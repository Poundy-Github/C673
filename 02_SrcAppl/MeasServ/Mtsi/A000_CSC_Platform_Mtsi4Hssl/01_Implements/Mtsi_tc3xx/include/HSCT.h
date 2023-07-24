/**********************************************************************************************************************
  COMPANY:     Continental Teves AG & Co. OHG
  PROJECT:     ADC420HA22
  CPU:         AURIX TC38XP
  MODULNAME:   HSCT
  VERSION:     $Revision: 1.0 $
 *********************************************************************************************************************/

/**
 *  \file      HSCT.h
 *  \brief     TBD.
 *  \date      15.07.2020
 *  \copyright Continental AG
 *
 *  TBD.
 *
 */

#ifndef HSCT_H
#define HSCT_H

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
* @{
*/
/** @defgroup HSCT_Module HSCT_Module
* @{
*/
/* ================================================================================================================= */
/*                                               Defines & Macros                                                    */
/* ================================================================================================================= */
#define HSCT_PING_TIMEOUT      ((uint16)10)    ///< Defined number of maximum pings sent until ping timeout */
#define HSCT_SEND_IFC_TIMEOUT  ((uint16)10000) ///< Defined 1000 cycles of execution until timeout */
#define HSCT_MAX_NO_OF_RESETS  ((uint32)10)    ///< Maximum number of resets performed on the HSCT peripheral */
/* ================================================================================================================= */
/*                                                Public Types                                                       */
/* ================================================================================================================= */
/** @brief Enumeration used for status of the HSCT module. */
typedef enum
{
  HSCT_UNINITIALIZED = 0x00u, ///< HSCT peripheral state is uninitialized */
  HSCT_INITIALIZED   = 0x01u, ///< HSCT peripheral state is initialized */
  HSCT_LOWSPEED      = 0x02u, ///< HSCT peripheral state is in low speed */
  HSCT_HIGHSPEED     = 0x03u  ///< HSCT peripheral state is in high speed */
  
}HSCT_StateType;
/** @brief Enumeration used for reference clock frequency dividers of HSCT module. */
typedef enum
{
  HSCT_SRCF_10MHZ = 0x00u,///< Reference clock frequency divider by 1 */
  HSCT_SRCF_20MHZ = 0x01u,///< Reference clock frequency divider by 2 */
  HSCT_SRCF_40MHZ = 0x02u ///< Reference clock frequency divider by 4 */
}HSCT_RefClckFreqDivType;
/** @brief Enumeration used for system clock frequency dividers of the HSCT module. */
typedef enum
{
  HSCT_SSCF_DIV_1_1 = 0x00u,///< System clock frequency divider by 1 */
  HSCT_SSCF_DIV_1_2 = 0x01u,///< System clock frequency divider by 2 */
  HSCT_SSCF_DIV_1_4 = 0x02u ///< System clock frequency divider by 4 */
}HSCT_SysClckFreqDivType;
/** @brief Enumeration used for high speed dividers of the HSCT module. */
typedef enum
{
  HSCT_HD_1_1  = 0x00u,///< High speed divider by 1  *//* 320 Mbps*/
  HSCT_HD_1_2  = 0x01u,///< High speed divider by 2  *//* 160 Mbps*/
  HSCT_HD_1_4  = 0x02u,///< High speed divider by 4  *//*  80 Mbps*/
  HSCT_HD_1_8  = 0x03u,///< High speed divider by 8  *//*  40 Mbps*/
  HSCT_HD_1_16 = 0x04u ///< High speed divider by 16 *//*  20 Mbps*/
}HSCT_HighSpeedDivType;

/** @brief Interface command controls of the HSCT module. */
typedef enum {
  HSCT_IFC_LS_SLAVE_TO_MASTER  = 0x20, ///< Lowspeed for RX_Link on slave side */
  HSCT_IFC_LS_MASTER_TO_SLAVE  = 0x08, ///< lowspeed for TX_Link on slave side */
  HSCT_IFC_HS_SLAVE_TO_MASTER  = 0x80, ///< highspeed for RX_Link on slave side */
  HSCT_IFC_HS_MASTER_TO_SLAVE  = 0x10, ///< highspeed for TX_Link on slave side */
  HSCT_IFC_START_CLK_MUL_SLAVE = 0x02, ///< start PLL on slave side */
  HSCT_IFC_STOP_CLK_MUL_SLAVE  = 0x04, ///< stop PLL on slave side */
  HSCT_IFC_ENABLE_SLAVE_TX     = 0x31, ///< enable slave transmitter */
  HSCT_IFC_DISABLE_SLAVE_TX    = 0x32, ///< disable slave transmitter */
  HSCT_IFC_SEND_PING           = 0x00  ///< trigger ping */
}HSCT_IfCtrlCmdType;
/** @brief Enumeration used for controling the communication lanes of the HSCT module. */
typedef enum {
  HSCT_FSM_IDLE,          ///< FSM is idle, no speed change is active */
  HSCT_FSM_SLAVE_TX_EN,   ///< Enable Slave Transmitter state */
  HSCT_FSM_RX_LINK,       ///< Setup RX_LINK on Slave side state */
  HSCT_FSM_TX_LINK,       ///< Setup TX_LINK on Slave side state */
  HSCT_FSM_SLAVE_PLL_ON,  ///< Switch on PLL on slave side state */
  HSCT_FSM_SLAVE_PLL_OFF, ///< Switch off PLL on slave side state */
  HSCT_FSM_WAIT_FOR_LOCK  ///< Wait for PLL lock information from salve side state */
}HSCT_FsmType;
/** @brief Enumeration used for locking the PLL and clearing the software watchdog of the HSCT module. */
typedef enum {
  HSCT_PLL_LOCK_HS = 0x7AAAAAAAUL, ///< USM message for PLL lock handshake */
  HSCT_CLR_SW_WD   = 0x55555555UL  ///< USM message for clearing software watchdog (slave) */
}HSCT_UsmCmd;
/** @brief Enumeration used for configuring the HSCT module. */
typedef struct
{
  HSCT_RefClckFreqDivType   RefClckFreqDiv; ///< Refecrence for the clock frequency divider */
  HSCT_SysClckFreqDivType   SysClckFreqDiv; ///< System clock frequency divider */
  HSCT_HighSpeedDivType     HighSpeedDiv;   ///< High Speed divider */
}HSCT_ConfigType;
/** @brief Enumeration used for internal data of the HSCT module. */
typedef struct
{
  HSCT_StateType eHsctState;  ///< The state in which HSCT peripheral is in */
  uint16 ui16PingCnt;         ///< Counts the number of pings that the master sends to the slave */
  uint32 ui32ResetsPerformed; ///< Counts the number of resets performed on the HSCT peripheral */
  uint8 ui8ConfigLVDSflag; ///< Flag used to configure the LVDS once */
}HSCT_InternalData_struct;
/* ================================================================================================================= */
/*                                          Public Variables Declarations                                            */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                           Public Functions Declarations                                           */
/* ================================================================================================================= */
/// @brief      Init function for HSCT Module.
///
/// @pre        none
///
/// @post       HSCT State will be changed to HSCT_INITIALIZED
///
/// @param[in] ConfigPtr Config type of HSCT module
///
/// @globals
///   @ref HSCT_stInternalData \n
///
/// @InOutCorrelation 
///   HSCT Module is enabled
///   If the HSCT Module is enabled "HSCT_stInternalData.eHsctState" is set to HSCT_INITIALIZED
///
/// @callsequence
/// @startuml
/// title Sequence Diagram for HSCT_Init
///  activate CDD_MTSI
///  CDD_MTSI -> HSCT : HSCT_Init
///   activate HSCT
///    HSCT --> CDD_MTSI
///   deactivate HSCT
///  deactivate CDD_MTSI
/// @enduml
///
///@startuml
///title Activity diagram for HSCT_Init
/// start
///  :Initialize internal data structure;
///  :Enable HSCT module;
///  :Waiting for enabling the module;
///  :Request kernel reset;
///  if (HSCT Module is enabled) then (yes)
///     :Setup master interface;
///     if (Configuration is valid) then (yes)
///        :Select reference clock frequency divider;
///        :Select sysclk frequency divider;
///        :Select transmit high speed divider;
///        :Select receive high speed divider;
///     endif
///     :Apply configuration onto INIT register;
///     :Enable HSCT sysclk;
///     :Enable HSCT PHY;
///     :Enable both HSCT links;
///     :Disable CTS handling;
///     :Enable IFCFS, PAR, USM receive interrupts;
///     :Clear all interrupt register status;
///     if (HSCT Configure LVDS flag is 0) then (yes)
///        :Configure LVDS ports;
///        ::Initialize low speed mode;
///     endif
///     :Change the HSCT state to INITIALIZED;
///  else (no)
///     :HSCT module did not initialize;
///  endif
/// stop
///@enduml
/// @traceability
///    @satisfy{GUID_a9439b17-1eb3-4e4e-8123-5b55e072fe2f}
///    @satisfy{ADC420_L3_SW_21912}
extern void HSCT_Init(HSCT_ConfigType const * const ConfigPtr);
/// @brief      Main function for HSCT Module
///
/// @pre        HSCT should be in a valid state
///
/// @post       none
///
/// @globals
///   @ref HSCT_stInternalData \n
///
/// @InOutCorrelation 
///   According with the HSCT state different functions will be called.
///
/// @callsequence
/// @startuml
///  activate CDD_MTSI
///   CDD_MTSI -> HSCT : HSCT_MainFunction
///   activate HSCT
/// group (case HSCT_UNINITIALIZED)
///  HSCT -> HSCT : HSCT_Init
/// end
/// group (case HSCT_INITIALIZED)
///  HSCT -> HSCT : HSCT_InitLowSpeed
/// end
/// group (case HSCT_LOWSPEED)
///  HSCT -> HSCT : HSCT_InitHighSpeed
/// end
/// group (case HSCT_HIGHSPEED)
/// alt (HSCT_MAX_NO_OF_RESETS > HSCT_stInternalData.ui32ResetsPerformed)
///    alt (HSCT_PING_TIMEOUT < HSCT_stInternalData.ui16PingCnt)
///        HSCT -> HSCT : HSCT_Reset()
///         activate HSCT
///          HSCT -> HSCT : HSCT_Reset()
///          deactivate HSCT
///    else 
///         HSCT -> HSCT : HSCT_SendPing()
///    end
/// end
/// end
/// HSCT --> CDD_MTSI
///   deactivate HSCT
///  deactivate CDD_MTSI
/// @enduml
///
/// @startuml
/// title Activity diagram for HSCT_MainFunction
///  start
///   if (HSCT state is HSCT_UNINITIALIZED) then (yes)
///      :Initialize the HSCT module;
///   elseif (HSCT state is HSCT_INITIALIZED) then (yes)
///      :Initialize low speed mode;
///   elseif (HSCT state is HSCT_LOWSPEED) then (yes)
///      :Initialize low speed mode;
///   elseif (HSCT state is HSCT_HIGHSPEED) then (yes)
///      if (Maximum number of resets to the HSCT and HSCT driver were performed) then (yes)
///         :Abandon HSCT communication;
///         else (no)
///         if (More than HSCT_PING_TIMEOUT consecutive pings were transmited) then (yes)
///            :Reset HSCT and HSCT drivers;
///            else (no)
///                 :Send the ping in order to detect if the communication is still alive;
///         endif
///      endif
///   else (no)
///   endif
///   stop
/// @enduml
/// @traceability N/A
extern void HSCT_MainFunction(void);
/// @brief      A function which return the state of HSCT.
///
/// @pre        HSCT should be in a valid state
///
/// @post       none
///
/// @return     HSCT_StateType
///
/// @globals
///   @ref HSCT_stInternalData \n
///
/// @InOutCorrelation 
///   Return the state of HSCT Module
///
/// @callsequence
/// @startuml
/// title Sequence Diagram for HSCT_GetState
///  activate ENV
///   ENV -> HSCT : HSCT_GetState
///   activate HSCT
///    HSCT -> ENV
///   deactivate HSCT
///  deactivate ENV
/// @enduml
///
/// @startuml
/// title Activity diagram for HSCT_GetState
///  start
///   :Return HSCT State;
///  stop
/// @enduml
/// @traceability N/A
extern HSCT_StateType HSCT_GetState(void);

#ifdef __cplusplus
}
#endif

#endif

/** @} doxygen end group definition  */
/** @} doxygen end group definition  */

/* ================================================================================================================= */
/*                                                     End of File                                                   */
/* ================================================================================================================= */
