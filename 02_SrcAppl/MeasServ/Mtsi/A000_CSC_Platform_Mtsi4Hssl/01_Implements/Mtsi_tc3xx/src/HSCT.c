/**********************************************************************************************************************
  COMPANY:     Continental Teves AG & Co. OHG
  PROJECT:     ADC420HA22
  CPU:         AURIX TC38XP
  MODULNAME:   HSCT
  VERSION:     $Revision: 1.0 $
 *********************************************************************************************************************/

/**
 *  \file      HSCT.c
 *  \brief     High Speed Communication Tunnel driver source file.
 *  \date      15.07.2020
 *  \copyright Continental AG
 *
 *  This file describes High Speed Communication Tunnel interface for the Microcontroller
 *  high speed data communication including the physical layer and the control (link) layer.
 *
 */

/* ================================================================================================================= */
/*                                            QAC Warnings Suppressions                                              */
/*                                           (Global Files Suppressions)                                             */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                                Include Files                                                      */
/* ================================================================================================================= */
#include "HSCT.h"
#include "HSSL.h"
#include "HSSL_HSCT_Cfg.h"
#include "RegAccess.h"
#include "ScuWdt.h"
#include <Os.h>
static uint32  HSCT0_ISR_num=0;
/** @defgroup Productive Productive code
* @{
*/
/** @defgroup HSCT_Module HSCT_Module
* @{
*/
/* ================================================================================================================= */
/*                                               Defines & Macros                                                    */
/* ================================================================================================================= */
#define HSCT_CLC_ADDR                     (0xF0090000UL) ///< Clock acontrol register address
#define HSCT_CLC_DISS_MASK                (0x00000001UL) ///< Mask for disabling the local memory unit
#define HSCT_CLC_DISS_OFFSET              (2UL)          ///< Offset of the LMU_instance_nameDisable Status Bit
#define HSCT_CLC_ENABLE                   (0x0UL)        ///<  Mask for enabling the local memory unit
#define HSCT_KRST0_ADDR                   (0xF009FFF4UL) ///< Address for the HSCT Kernel Reset Register 0
#define HSCT_KRST0_RESET                  (0x1UL)        ///< Mask for reseting the Kernel Reset Register 0
#define HSCT_KRST1_ADDR                   (0xF009FFF0UL) ///< Address for the HSCT Kernel Reset Register 1
#define HSCT_KRST1_RESET                  (0x1UL)        ///< Mask for reseting the Kernel Reset Register 1
#define HSCT_INIT_ADDR                    (0xF0090010UL) ///<  HSCT Initialization Register address
#define HSCT_INIT_SYS_CLC_EN              (0x00000002UL) ///< Mask for enabling the system clock
#define HSCT_INIT_IFM_MASTER              (0UL)          ///< Select interface mode master
#define HSCT_INIT_IFM_OFFSET              (3UL)          ///< Offset for the Select interface mode in the initialization register
#define HSCT_INIT_SRCF_OFFSET             (4UL)          ///< Select reference clock frequency divider offset
#define HSCT_INIT_SSCF_OFFSET             (6UL)          ///< Select SysClk frequency divider offset
#define HSCT_INIT_TXHD_OFFSET             (16UL)         ///< Transmit high speed divider offset
#define HSCT_INIT_RXHD_OFFSET             (19UL)         ///< Receive high speed divider
#define HSCT_CONFIGPHY_ADDR               (0xF0090030UL) ///< Configuration Physical Layer Register address
#define HSCT_CONFIGPHY_EN_VAL             (0x001F0001u)  ///< Mask for enabling the configuration physical layer
#define HSCT_DISABLE_ADDR                 (0xF0090020UL) ///< Mask for disabling the configuration physical layer
#define HSCT_DISABLE_EN_BOTH_LINKS        (0x00000000u)  ///<  Disable both communication links
#define HSCT_CTSCTRL_ADDR                 (0xF009001CUL) ///< Clear to send control register address
#define HSCT_CTSCTRL_DIS_CTS_FRAME        (0x00000000u)  ///< Transmit Clear To Send frame generation. For value 0 the generation of dedicated clear to send frames is disabled
#define HSCT_IRQEN_ADDR                   (0xF0090044UL) ///< Interrupt enable register address
#define HSCT_IRQEN_IFCFS_EN               (0x0000010u)   ///< Mask HSCT interface control command send enable. Value is used for enabling the interrupt
#define HSCT_IRQEN_USM_EN                 (0x0000100u)   ///< Mask for enabling the Unsolicited message received register
#define HSCT_IRQEN_PAR_EN                 (0x0000200u)   ///< Mask for enabling the ping answer received register
#define HSCT_IFCTRL_ADDR                  (0xF0090014UL) ///< HSCT Interface control register address

/*
 *  Master Mode - Trigger for Interface Control Value to be send to Slave interface
 *
 *  Master IF Mode: The value is taken as control frame value send as payload to the Slave IF.
 *  Slave IF Mode: The value is a new configuration of the Slave IF (not recommended flow!!!).
 */
#define HSCT_IFCTRL_IFCVS_MASK            (0x000000FFUL) ///< Interface control mask
/*
 *  Master Mode - Slave IF control frame trigger
 *
 *  Changing the interface configuration, software must guarantee not having transfers active on the interface.
 *  This register bit always reads back zero.
 *  0B The IFCVS field configured value has no effect (default).
 *  1B Writing a one to the register bit sends the control frame configured
 *     in register field IFCVS, if the interface is configured as Master. In
 *     Slave Mode the trigger has an effect and takes the IFCTRL.IFCVS
 *     value. In Slave mode this is not the recommended control flow. A
 *     frame based configuration shall be used instead. A control frame
 *     has higher priority then a register control. At a simultaneous
 *     occurrence of both configuration source the register configuration
 *     in Slave mode is lost.
 */
#define HSCT_IFCTRL_SIFCV_OFFSET          (8u)           ///< Interface control offset
#define HSCT_IFCTRL_MRXSPEED_OFFSET       (16UL)         ///< Master mode Rx speed offset
#define HSCT_IFCTRL_MTXSPEED_OFFSET       (18UL)         ///<  Master mode Tx speed offset
#define HSCT_IFCTRL_MXXSPEED_MASK         (3UL)          ///< Mask for enabling the future use speed
#define HSCT_IFCTRL_MXXSPEED_LOWSPEED     (0UL)          ///< Mask for enabling the low speed
#define HSCT_IFCTRL_MXXSPEED_HIGHSPEED    (2UL)          ///< Mask for enabling the high speed

/*
 *  Interrupt register address
 *
 *  Interrupt status register. Read only and updated by HW. The bits remain active until cleared. The clear pulse is
 *  coming from the IRQCLR register. Only an interrupt source not being already active in the interrupt status register
 *  generates an interrupt pulse to the SoC interrupt controller.
 */
#define HSCT_IRQ_ADDR                     (0xF0090040UL) ///< Interrupt register address
/*
 *  Interrupt clear register address
 *
 *  This register is the Interrupt clear register. By writing a logic 1 to the register the interrupt in the IRQ register is
 *  cleared by a clear pulse. This means the interrupt clear methodology is write one to clear. Reading from this
 *  register presents the logic value 0 to software.
 */
#define HSCT_IRQCLR_ADDR                  (0xF0090048UL) ///< Interrupt clear register address
#define HSCT_IRQ_PAR_OFFSET               (9UL)          ///< Ping answer received register offset
#define HSCT_IRQ_USM_OFFSET               (8UL)          ///< Unsolicited message received register offset
#define HSCT_IRQ_IFCFS_OFFSET             (4UL)          ///< HSCT interface control frame send register offset
#define HSCT_IRQCLR_CLEARALL              (0xFFFFFFFFUL) ///< Mask for clearing all interrupt registers

/*
 *  Unsolicited Status Message Send
 *
 *  A write to the register activates the interface to send out an unsolicited status message to the other interface side.
 *  The Logical Channel Type reflected in the header is Hex 1 and the Payload is 32-bit always. An unsolicited frame
 *  has a higher priority then a Frame based on a data channel. In between frames the USMS gets higher priority then
 *  the data transfer requested by the HSSL. This function is not available in multi Slave scenario.
 */
#define HSCT_USMS_ADDR                    (0xF0090054UL) ///< Unsolicited Status Message Send address

/*
 *  Unsolicited Status Message Received
 *
 *  The Unsolicited Status message register is available to capture unsolicited messages received with the logical
 *  channel command encoding in the header of the frame (Logical Channel Type Hex 1). This function is not
 *  available in multi Slave scenario.
 */
#define HSCT_USMR_ADDR                    (0xF0090050UL) ///< Unsolicited Status Message Received address
#define HSCT_PORT21_ADDR                  (0xF003B500UL) ///< HSCT port configuration address for port 21 
#define HSCT_PORT21_LPCR1_ADDR            (0xF003B5A4UL) ///< Port n LVDS Pad control register 1 address
#define HSCT_PORT21_LPCR2_ADDR            (0xF003B5A8UL) ///< Port n LVDS Pad control register 2 address
#define HSCT_PORT21_PDR0_ADDR             (0xF003B540UL) ///< Port P21 Pad Driver Mode 0 Register address
#define HSCT_PORT21_PDR0_MASK             (0x00CCCC00UL) ///< Port P21 Pad Driver Mode 0 Register mask
#define HSCT_PORT21_PDR0_MASK_PD          (0x00333300UL) ///< Port P21 Pad Driver Mode 0 mask
#define HSCT_PORT20_PDR0_ADDR             (0xF003B440UL) ///< Port P20 Pad Driver Mode 0 Register address
#define HSCT_PORT20_PDR0_VALUE            (0x3UL)        ///< Port P20 Pad Driver Mode 0 Register value
#define HSCT_PORT21_LPCR1_VALUE           (0x7UL)        ///< Port 21 LVDS Pad Control Register 1 value
#define HSCT_PORT21_LPCR2_VALUE           (0x300UL)      ///< Port 21 LVDS Pad Control Register 2 value
/* ================================================================================================================= */
/*                                                Private Types                                                      */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                               Private Variables                                                   */
/* ================================================================================================================= */
static HSCT_InternalData_struct HSCT_stInternalData; ///< Hsct internal data structure

/* ================================================================================================================= */
/*                                               Public Variables                                                    */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                         Private Functions Prototypes                                              */
/* ================================================================================================================= */
/// @brief      A function which sends a defined command to the slave.
///
/// @pre        HSCT should be in a valid state
///
/// @post       none
///
/// @return     void
///
/// @param[in]  Command  The command sent to the slave.
///
/// @globals
///   @ref HSCT_IfCtrlCmdType \n
///
/// @InOutCorrelation 
///   Send a command defined by user to the slave
///
/// @startuml
/// title Activity diagram for HSCT_SendIfc
///  start
///   :Read the content of IFCTRL register;
///   :Insert the interface control value to be send to slave;
///   :Update the IFCTRL register with IFCVS value;
///   :Trigger the sending of the interface control frame;
///  stop
/// @enduml
/// @traceability N/A
static void HSCT_SendIfc( const HSCT_IfCtrlCmdType Command );
/// @brief      A function which sends an answer request to the slave.
///
/// @pre        HSCT should be in a valid state
///
/// @post       none
///
/// @return     void
///
/// @InOutCorrelation 
///   Send a ping request to the slave.
///
/// @startuml
/// title Activity diagram for HSCT_SendPing
///  start
///   :Send a ping command to the slave;
///   :Mark that a new ping request was sent;
///  stop
/// @enduml
/// @traceability N/A
static void HSCT_SendPing(void);
/// @brief      A function which initializes the communication lanes in low speed mode.
///
/// @pre        HSCT should be in a valid state.
///
/// @post       none
///
/// @return     void
///
/// @InOutCorrelation 
///   Sets the communication lanes with the slave in low speed mode.
///
/// @startuml
/// title Activity diagram for HSCT_InitLowSpeed
///  start
///   :Send control command to enable the Slave TX;
///   :Check if interface control frame was sent;
///   if (Command was sent) then (yes)
///      :Clear interface control frames sent interrupt flag;
///      :Set Slave Tx to low speed;
///      :Wait until the command is sent;
///      if (Command was sent) then (yes)
///         :Clear interface control frames sent interrupt flag;
///         :Set TX_LINK to low speed on Master side;
///         :Swtich HSCT state to Low Speed mode;
///         else (no)
///              :Command was not sent, the state will not change;
///              endif
///     else (no)
///          :Command was not sent, the state will not change;
///          endif
///  stop
/// @enduml
/// @traceability N/A
static void HSCT_InitLowSpeed(void);
/// @brief      A function which initializes the communication lanes in high speed mode
///
/// @pre        HSCT should be in a valid state
///
/// @post       none
///
/// @return     void
///
/// @InOutCorrelation 
///   Sets the communication lanes with the slave in high speed mode.
///
/// @startuml
/// title Activity diagram for HSCT_InitHighSpeed
///  start
///   :Set RX_LINK to high speed on Master side;
///   :Set Slave Tx to high speed;
///   :Wait until the command is sent;
///   if (Command was sent) then (yes)
///      :Clear interface control frames sent interrupt flag;
///      :Set Slave RX to high speed;
///      :Wait until the command is sent;
///      if (Command was sent) then (yes)
///         :Clear interface control frames sent interrupt flag;
///         :set TX_LINK to high speed on Master side;
///         :Swtich HSCT state to High Speed mode;
///         else (no)
///              :Command was not sent, the state will not change;
///              endif
///     else (no)
///          :Command was not sent, the state will not change;
///          endif
///  stop
/// @enduml
/// @traceability N/A
static void HSCT_InitHighSpeed(void);
/// @brief      A function which resets the HSCT driver.
///
/// @pre        HSCT should be in a valid state
///
/// @post       none
///
/// @return     void
///
/// @InOutCorrelation
///   Reset the HSCT module.
///
/// @startuml
/// title Activity diagram for HSCT_InitHighSpeed
///  start
///   :Disable all interrupts;
///   :Request kernel reset;
///   :Enable all interrupts;
///   :Change the HSCT state to HSCT_UNINITIALIZED;
///   :Initialize the HSCT module;
///  stop
/// @enduml
/// @traceability N/A
static void HSCT_Reset(void );
/// @brief      A function which configures the LVDS for the HSCT driver.
///
/// @pre        HSCT should be in a valid state
///
/// @post       none
///
/// @return     void
///
/// @InOutCorrelation
///   Configures the LVDS interface of the HSCT module.
///
/// @startuml
/// title Activity diagram for HSCT_ConfigureLVDS
/// start
///  :Request kernel reset;
///  :Configure LVDS ports;
///  :Change the configure LVDS flag to 1;
/// stop
/// @enduml
/// @traceability N/A
static void HSCT_ConfigureLVDS(void);

static void HSCT_InitHighSpeed_Act(void);

/* ================================================================================================================= */
/*                                         Private Functions Definitions                                             */
/* ================================================================================================================= */
static void HSCT_SendIfc( const HSCT_IfCtrlCmdType Command )
{
  uint32 u32RegValue = 0u;

  /* Read the content of IFCTRL register */
  u32RegValue = RegAccess_Read32(HSCT_IFCTRL_ADDR);

  /* Insert the interface control value to be send to slave */
  u32RegValue &= ~HSCT_IFCTRL_IFCVS_MASK;
  u32RegValue |= (uint32)Command;

  /* Update the IFCTRL register with IFCVS value */
  RegAccess_Write32(HSCT_IFCTRL_ADDR, u32RegValue);

  /* Triggers the sending of the interface control frame */
  RegAccess_SetBits32(HSCT_IFCTRL_ADDR, 1UL << HSCT_IFCTRL_SIFCV_OFFSET);
}

static void HSCT_SendPing(void)
{
  HSCT_SendIfc(HSCT_IFC_SEND_PING);
  /* Mark that a new ping request was sent */
  HSCT_stInternalData.ui16PingCnt++;
}

static void HSCT_InitLowSpeed(void)
{
  uint16 ui16Timeout;
  /*Send control command to enable the Slave TX*/
  HSCT_SendIfc(HSCT_IFC_ENABLE_SLAVE_TX);
  ui16Timeout = HSCT_SEND_IFC_TIMEOUT;
  /* Check if interface control frame was sent */
  while ((1u != ((RegAccess_Read32(HSCT_IRQ_ADDR) >> HSCT_IRQ_IFCFS_OFFSET) & 1u)) && (ui16Timeout > 0u))
  {
    --ui16Timeout;
  }
 
  /* Command was sent */
  if (ui16Timeout > 0u)
  {
    /* Clear interface control frames sent interrupt flag */
    RegAccess_SetBits32(HSCT_IRQCLR_ADDR, (1UL << HSCT_IRQ_IFCFS_OFFSET));
    /*Set Slave Tx to low speed*/
    HSCT_SendIfc(HSCT_IFC_LS_SLAVE_TO_MASTER);
    ui16Timeout = HSCT_SEND_IFC_TIMEOUT;
    /*Wait until the command is sent*/
    while ((1u != ((RegAccess_Read32(HSCT_IRQ_ADDR) >> HSCT_IRQ_IFCFS_OFFSET) & 1u)) && (ui16Timeout > 0u))
    {
      --ui16Timeout;
    }

    /* Command was sent */
    if (ui16Timeout > 0u)
    {
      /* Clear interface control frames sent interrupt flag */
      RegAccess_SetBits32(HSCT_IRQCLR_ADDR, (1UL << HSCT_IRQ_IFCFS_OFFSET));

      /* set RX_LINK to low speed on Master side */
      RegAccess_ClrBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_MASK << HSCT_IFCTRL_MRXSPEED_OFFSET);
      RegAccess_SetBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_LOWSPEED << HSCT_IFCTRL_MRXSPEED_OFFSET);

      /*Set Slave Tx to low speed*/
      HSCT_SendIfc(HSCT_IFC_LS_MASTER_TO_SLAVE);
      ui16Timeout = HSCT_SEND_IFC_TIMEOUT;
      /*Wait until the command is sent*/
      while ((1u != ((RegAccess_Read32(HSCT_IRQ_ADDR) >> HSCT_IRQ_IFCFS_OFFSET) & 1u)) && (ui16Timeout > 0u))
      {
        --ui16Timeout;
      }

      /* Clear interface control frames sent interrupt flag */
      RegAccess_SetBits32(HSCT_IRQCLR_ADDR, (1UL << HSCT_IRQ_IFCFS_OFFSET));

      /* set TX_LINK to low speed on Master side */
      RegAccess_ClrBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_MASK << HSCT_IFCTRL_MTXSPEED_OFFSET);
      RegAccess_SetBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_LOWSPEED << HSCT_IFCTRL_MTXSPEED_OFFSET);

      /* Swtich to High Speed mode */
      HSCT_stInternalData.eHsctState = HSCT_HIGHSPEED;// HSCT_LOWSPEED;// 
    }
    else /* Command was not sent */
    {
      /* do not change the state */
    }
  }
  else /* Command was not sent */
  {
    /* do not change the state */
  }
}
static void HSCT_Delay(void)
{
  volatile uint32 ui32Timeout = 10000;
  while (ui32Timeout > 0u)
  {
    --ui32Timeout;
  }
}
static uint8 HSCT_IFCVS_CheckSendIRQ(void)
{
  return((RegAccess_Read32(HSCT_IRQ_ADDR) >> HSCT_IRQ_IFCFS_OFFSET) & 1u);
}
static void HSCT_IFCVS_ClrIRQ(void)
{
  RegAccess_SetBits32(HSCT_IRQCLR_ADDR, (1UL << HSCT_IRQ_IFCFS_OFFSET));
}
static uint8 debug_IFCVS[10];
static void HSCT_InitHighSpeed_Act(void)
{
  /* Enable reception at the Slave */
  HSCT_SendIfc(HSCT_IFC_ENABLE_SLAVE_TX);//IFCVS 49
  HSCT_Delay();
  if(1u == HSCT_IFCVS_CheckSendIRQ()) {debug_IFCVS[0]++;}
  HSCT_IFCVS_ClrIRQ();
  if(1u == HSCT_IFCVS_CheckSendIRQ()) {debug_IFCVS[5]++;}

  /*Send Ping*/
  HSCT_SendIfc(HSCT_IFC_SEND_PING);//IFCVS 0
  HSCT_Delay();
  if(1u == HSCT_IFCVS_CheckSendIRQ()) {debug_IFCVS[1]++;}
  HSCT_IFCVS_ClrIRQ();
  if(1u == HSCT_IFCVS_CheckSendIRQ()) {debug_IFCVS[6]++;}

  //Set RX link - bits IFCTRL.MRXSPEED to high speed
  RegAccess_ClrBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_MASK << HSCT_IFCTRL_MRXSPEED_OFFSET);
  RegAccess_SetBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_HIGHSPEED << HSCT_IFCTRL_MRXSPEED_OFFSET);

  /*Set Slave Tx to high speed mode*/
  HSCT_SendIfc(HSCT_IFC_HS_SLAVE_TO_MASTER);//IFCVS 128
  HSCT_Delay();
  if(1u == HSCT_IFCVS_CheckSendIRQ()) {debug_IFCVS[2]++;}
  HSCT_IFCVS_ClrIRQ();
  if(1u == HSCT_IFCVS_CheckSendIRQ()) {debug_IFCVS[7]++;}

  /*Set Slave Rx to high speed mode*/
  HSCT_SendIfc(HSCT_IFC_HS_MASTER_TO_SLAVE);//IFCVS 16
  HSCT_Delay();
  if(1u == HSCT_IFCVS_CheckSendIRQ()) {debug_IFCVS[3]++;}
  HSCT_IFCVS_ClrIRQ();
  if(1u == HSCT_IFCVS_CheckSendIRQ()) {debug_IFCVS[8]++;}

  //Set TX link - bits IFCTRL.MTXSPEED to high speed
  RegAccess_ClrBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_MASK << HSCT_IFCTRL_MTXSPEED_OFFSET);
  RegAccess_SetBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_HIGHSPEED << HSCT_IFCTRL_MTXSPEED_OFFSET);

  /*Send Ping*/
  HSCT_SendIfc(HSCT_IFC_SEND_PING);//IFCVS 0
  HSCT_Delay();
  if(1u == HSCT_IFCVS_CheckSendIRQ()) {debug_IFCVS[4]++;}
  HSCT_IFCVS_ClrIRQ();
  if(1u == HSCT_IFCVS_CheckSendIRQ()) {debug_IFCVS[9]++;}

  HSCT_stInternalData.eHsctState = HSCT_HIGHSPEED;
}
/* COU_COV_DISABLE: <Reason: At the moment the HighSpeed is not working..> */
// static void HSCT_InitHighSpeed(void)
// {
//   uint16 ui16Timeout;
//   /* set RX_LINK to high speed on Master side */
//   RegAccess_ClrBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_MASK << HSCT_IFCTRL_MRXSPEED_OFFSET);
//   RegAccess_SetBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_HIGHSPEED << HSCT_IFCTRL_MRXSPEED_OFFSET);
//   /*Set Slave Tx to high speed*/
//   HSCT_SendIfc(HSCT_IFC_HS_SLAVE_TO_MASTER);
//   ui16Timeout = HSCT_SEND_IFC_TIMEOUT;
//   /*Wait until the command is sent*/
//   while ((1u != ((RegAccess_Read32(HSCT_IRQ_ADDR) >> HSCT_IRQ_IFCFS_OFFSET) & 1u)) && (ui16Timeout > 0u))
//   {
//     --ui16Timeout;
//   }

//   /* Check if command was sent */
//   if (ui16Timeout > 0u)
//   {
//     /* Clear interface control frames sent interrupt flag */
//     RegAccess_SetBits32(HSCT_IRQCLR_ADDR, (1UL << HSCT_IRQ_IFCFS_OFFSET));
//     /*Set Slave RX to high speed*/
//     HSCT_SendIfc(HSCT_IFC_HS_MASTER_TO_SLAVE);
//     ui16Timeout = HSCT_SEND_IFC_TIMEOUT;
//     /*Wait until the command is sent*/
//     while ((1u != ((RegAccess_Read32(HSCT_IRQ_ADDR) >> HSCT_IRQ_IFCFS_OFFSET) & 1u)) && (ui16Timeout > 0u))
//     {
//       --ui16Timeout;
//     }

//     /* Check if command was sent */
//       if (ui16Timeout > 0u)
//     {
//       /* Clear interface control frames sent interrupt flag */
//       RegAccess_SetBits32(HSCT_IRQCLR_ADDR, (1UL << HSCT_IRQ_IFCFS_OFFSET));
//       /* set TX_LINK to high speed on Master side */
//       RegAccess_ClrBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_MASK << HSCT_IFCTRL_MTXSPEED_OFFSET);
//       RegAccess_SetBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_HIGHSPEED << HSCT_IFCTRL_MTXSPEED_OFFSET);

//       /* Switch to the High Speed mode */
//       HSCT_stInternalData.eHsctState = HSCT_HIGHSPEED;
//     }
//     else /* Command was not sent */
//     {
//       /* Do not change the state */
//     }
//   }
//   else /* Command was not sent */
//   {
//     /* Do not change the state */
//   }
// }
static void HSCT_InitHighSpeed(void)
{
  volatile uint16 ui16Timeout;
  /*Send control command to enable the Slave TX*/
  HSCT_SendIfc(HSCT_IFC_ENABLE_SLAVE_TX);
  ui16Timeout = HSCT_SEND_IFC_TIMEOUT;
  /* Check if interface control frame was sent */
  while ((1u != ((RegAccess_Read32(HSCT_IRQ_ADDR) >> HSCT_IRQ_IFCFS_OFFSET) & 1u)) && (ui16Timeout > 0u))
  {
    --ui16Timeout;
  }
  
  
  /* Check if command was sent */
  if (ui16Timeout > 0u)
  {
    /* Clear interface control frames sent interrupt flag */
    RegAccess_SetBits32(HSCT_IRQCLR_ADDR, (1UL << HSCT_IRQ_IFCFS_OFFSET));
    /*Set Slave Tx to high speed*/
    HSCT_SendIfc(HSCT_IFC_HS_SLAVE_TO_MASTER);
    ui16Timeout = HSCT_SEND_IFC_TIMEOUT;
    /*Wait until the command is sent*/
    while ((1u != ((RegAccess_Read32(HSCT_IRQ_ADDR) >> HSCT_IRQ_IFCFS_OFFSET) & 1u)) && (ui16Timeout > 0u))
    {
      --ui16Timeout;
    }
    
    
    /* Command was sent */
    if (ui16Timeout > 0u)
    {
      /* Clear interface control frames sent interrupt flag */
      RegAccess_SetBits32(HSCT_IRQCLR_ADDR, (1UL << HSCT_IRQ_IFCFS_OFFSET));
      /* set RX_LINK to high speed on Master side */
      RegAccess_ClrBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_MASK << HSCT_IFCTRL_MRXSPEED_OFFSET);
      RegAccess_SetBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_HIGHSPEED << HSCT_IFCTRL_MRXSPEED_OFFSET);
      /*Set Slave Tx to high speed*/
      HSCT_SendIfc(HSCT_IFC_HS_MASTER_TO_SLAVE);
      ui16Timeout = HSCT_SEND_IFC_TIMEOUT;
      /*Wait until the command is sent*/
      while ((1u != ((RegAccess_Read32(HSCT_IRQ_ADDR) >> HSCT_IRQ_IFCFS_OFFSET) & 1u)) && (ui16Timeout > 0u))
      {
        --ui16Timeout;
      }
      
      /* Clear interface control frames sent interrupt flag */
      RegAccess_SetBits32(HSCT_IRQCLR_ADDR, (1UL << HSCT_IRQ_IFCFS_OFFSET));

      /* set TX_LINK to high speed on Master side */
      RegAccess_ClrBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_MASK << HSCT_IFCTRL_MTXSPEED_OFFSET);
      RegAccess_SetBits32(HSCT_IFCTRL_ADDR, HSCT_IFCTRL_MXXSPEED_HIGHSPEED << HSCT_IFCTRL_MTXSPEED_OFFSET);

      /* Switch to the High Speed mode */
      HSCT_stInternalData.eHsctState = HSCT_HIGHSPEED;
    }
    else /* Command was not sent */
    {
      /* Do not change the state */
    }
  }
  else /* Command was not sent */
  {
    /* Do not change the state */
  }
}
/* COU_COV_ENABLE */

static void HSCT_Reset( void )
{
  /* Request kernel reset */
  SuspendAllInterrupts();

  ScuWdt_EndinitClear();
  RegAccess_Write32(HSCT_KRST0_ADDR, HSCT_KRST0_RESET);
  RegAccess_Write32(HSCT_KRST1_ADDR, HSCT_KRST1_RESET);
  ScuWdt_EndinitSet();

  ResumeAllInterrupts();

  HSCT_stInternalData.eHsctState = HSCT_UNINITIALIZED;

  /* Init the HSCT module */
  HSCT_Init(&HSCT_Cfg);
}

static void HSCT_ConfigureLVDS(void)
{
  /* Request kernel reset */
  SuspendAllInterrupts();
  ScuWdt_EndinitClear();
  /*Configure LVDS ports*/
  RegAccess_SetBits32(HSCT_PORT21_PDR0_ADDR, HSCT_PORT21_PDR0_MASK);
  RegAccess_ClrBits32(HSCT_PORT21_PDR0_ADDR, HSCT_PORT21_PDR0_MASK_PD);
  RegAccess_ClrBits32(HSCT_PORT20_PDR0_ADDR, HSCT_PORT20_PDR0_VALUE);
  RegAccess_Write32(HSCT_PORT21_LPCR1_ADDR, HSCT_PORT21_LPCR1_VALUE);
  RegAccess_Write32(HSCT_PORT21_LPCR2_ADDR, HSCT_PORT21_LPCR2_VALUE);
  ScuWdt_EndinitSet();
  ResumeAllInterrupts();
  /*Change the configure LVDS flag to 1*/
  HSCT_stInternalData.ui8ConfigLVDSflag = 1u;
}
/* ================================================================================================================= */
/*                                            Public Functions Definitions                                           */
/* ================================================================================================================= */
void HSCT_Init(HSCT_ConfigType const * const ConfigPtr)
{
  uint32 ui32RegValue = 0u;
  uint16 ui16Timeout = HSCT_SEND_IFC_TIMEOUT;

  /* Initialize internal data structure */
  HSCT_stInternalData.eHsctState = HSCT_UNINITIALIZED;
  HSCT_stInternalData.ui16PingCnt = 0u;

  SuspendAllInterrupts();
  /* Enable HSCT module */
  ScuWdt_EndinitClear();
  RegAccess_Write32(HSCT_CLC_ADDR, HSCT_CLC_ENABLE);
  ScuWdt_EndinitSet();
  ResumeAllInterrupts();

  /* Wait for the module to be enabled */
  while ((0u != ((RegAccess_Read32(HSCT_IRQ_ADDR) >> HSCT_IRQ_IFCFS_OFFSET) & 1u)) && (ui16Timeout > 0u))
  {
    --ui16Timeout;
  }

  /* Request kernel reset */
  SuspendAllInterrupts();
  ScuWdt_EndinitClear();
  RegAccess_Write32(HSCT_KRST0_ADDR, HSCT_KRST0_RESET);
  RegAccess_Write32(HSCT_KRST1_ADDR, HSCT_KRST1_RESET);
  ScuWdt_EndinitSet();
  ResumeAllInterrupts();

  /* HSCT module initialized in time */
  if (ui16Timeout > 0u)
  {
    /* Setup master interface */
    ui32RegValue &= ~(HSCT_INIT_IFM_MASTER << HSCT_INIT_IFM_OFFSET);

     /* Check if configuration is valid */
    if ( NULL_PTR != ConfigPtr )
    {
    /* Select reference clock frequency divider */
    ui32RegValue |= ((uint32)ConfigPtr->RefClckFreqDiv << HSCT_INIT_SRCF_OFFSET);
    /* Select sysclk frequency divider */
    ui32RegValue |= ((uint32)ConfigPtr->SysClckFreqDiv << HSCT_INIT_SSCF_OFFSET);
    /* Select transmit high speed divider */
    ui32RegValue |= ((uint32)ConfigPtr->HighSpeedDiv   << HSCT_INIT_TXHD_OFFSET);
    /* Select receive high speed divider */
    ui32RegValue |= ((uint32)ConfigPtr->HighSpeedDiv   << HSCT_INIT_RXHD_OFFSET);
    }

    /* Apply configuration onto INIT register */
    RegAccess_Write32(HSCT_INIT_ADDR, ui32RegValue);

    /* Enable HSCT sysclk */
    RegAccess_SetBits32(HSCT_INIT_ADDR, HSCT_INIT_SYS_CLC_EN);

    /* Enable HSCT PHY */
    RegAccess_Write32(HSCT_CONFIGPHY_ADDR, HSCT_CONFIGPHY_EN_VAL);

    /* Enable both HSCT liks */
    RegAccess_Write32(HSCT_DISABLE_ADDR, HSCT_DISABLE_EN_BOTH_LINKS);

    /* Disable CTS handling */
    RegAccess_Write32(HSCT_CTSCTRL_ADDR, HSCT_CTSCTRL_DIS_CTS_FRAME);

    /* Enable IFCFS, PAR, USM receive interrupts */
    RegAccess_Write32(HSCT_IRQEN_ADDR, (HSCT_IRQEN_PAR_EN));

    /* Clear all interrupt register status */
    RegAccess_Write32(HSCT_IRQCLR_ADDR, HSCT_IRQCLR_CLEARALL);

    if(0u == HSCT_stInternalData.ui8ConfigLVDSflag)
    {
      HSCT_ConfigureLVDS();

      /* Initialize low speed mode */
      HSCT_InitHighSpeed_Act();// HSCT_InitLowSpeed();//
    
    }

    /* Change the HSCT state to INITIALIZED */
    HSCT_stInternalData.eHsctState = HSCT_INITIALIZED;
  }
  else /* HSCT module did not initialize */
  {
    /* keep Uninitialized state */
  }
}

void HSCT_MainFunction(void)
{
  /* COU_COV_DISABLE: <Reason: HSCT_State can't be on HSCT_LOWSPEED.> */
  switch(HSCT_stInternalData.eHsctState)
  /* COU_COV_ENABLE */
  {
    case HSCT_UNINITIALIZED:

      /* Init the HSCT module */
      HSCT_Init(&HSCT_Cfg);

      break;

    case HSCT_INITIALIZED:    

      /* Initialize low speed mode */
      HSCT_InitHighSpeed_Act();//HSCT_InitLowSpeed();//
      //debug HSCT_InitHighSpeed();

      break;
    /* COU_COV_DISABLE: <Reason: At the moment the HighSpeed is not working..> */
    case HSCT_LOWSPEED:

        /* Initialize high speed mode */
        HSCT_InitHighSpeed();

      break;
    /* COU_COV_ENABLE */
    case HSCT_HIGHSPEED:

    /* If more than HSCT_PING_TIMEOUT consecutive pings were transmited
     * but no response received then restart the HSCT and HSSL driver */
     if(HSCT_MAX_NO_OF_RESETS > HSCT_stInternalData.ui32ResetsPerformed)
     {
       if(HSCT_PING_TIMEOUT < HSCT_stInternalData.ui16PingCnt)
       {
         HSCT_stInternalData.ui16PingCnt = 0u;
         HSCT_stInternalData.ui32ResetsPerformed++;
         /* Reset HSSL and HSCT */
         HSCT_Reset();
         HSSL_Reset();
       }
       else
       {
         /* Send the ping in order to detect if the communication is still alive */
           HSCT_SendPing();
       }
     }
     else
     {
       /* Maximum number of resets were performed, abandon HSSL communication */
     }

      break;
    /* COU_COV_DISABLE: <Reason: Here isn't a default case.> */
    default:
      /* Do nothing */
      break;
    /* COU_COV_ENABLE */
  }
}

extern HSCT_StateType HSCT_GetState(void)
{
  return HSCT_stInternalData.eHsctState;
}

/// @brief Function for ISR HSCT_ISR.
/// @globals
/// @ref HSCT_stInternalData \n
/// @InOutCorrelation RegAccess_SetBits32() is called
//ISR(HSCT_ISR)
extern void OS_ISR_HSCT0_ISR(void)
{
  uint32 ui32RegValue = 0u;

  /* Read the whole Interrupt status register */
  ui32RegValue = RegAccess_Read32(HSCT_IRQ_ADDR);

  /* Check if ping answer was received */
  if(0u != ((ui32RegValue >> HSCT_IRQ_PAR_OFFSET) & 1u))
  {
    /* Clear ping answer received interrupt flag */
    RegAccess_SetBits32(HSCT_IRQCLR_ADDR, (1UL << HSCT_IRQ_PAR_OFFSET));

    HSCT_stInternalData.ui16PingCnt = 0u;
  }
  else
  {
    /* Another interrupt request */
    /* Do not reset the ping counter */	 
  }
  HSCT0_ISR_num++;
}

/** @} doxygen end group definition  */
/** @} doxygen end group definition  */

/* ================================================================================================================= */
/*                                                     End of File                                                   */
/* ================================================================================================================= */
