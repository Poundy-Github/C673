//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_regmanager.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:58CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_regmanager
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_regmanager.h
//  LOGIN:           uidt3974  
//  
//  The IC Register Manager is a central component for handling imager register data. In summary,
//  it has the following tasks:
//  
//  - Managing of input register values in a buffer, which are extracted from image embedded data
//  - Buffering of output register values, and flushing them to the imager(s) on request
//  - Storage of N 'history' output register values
//  - Asynchronous register transfers (TX and RX)
//  - Synchronous register transfers (e.g. sensor initialization), including data verification
//  - Cyclic Register checking/verification. This includes checking of registers, which are not
//    part of embedded data and must therefore be read asynchronously via I2C
//  - Checking of I2C write timing against timing constraints, which must not be violated to
//    ensure deterministic imager behavior
//  - Handling embedded register data of the left imager, which is received via IPC, because
//    the imager datapath is not directly connected the processor which executes this part of
//    software.
//  
//  ==========================================================================================
//  =                          LEFT IMAGER EMBEDDED REGISTER DATA                            =
//  ==========================================================================================
//  On stereo cameras, the databus of the left imager is not connected to the MCU, on which the
//  IC is running. Therefore it does not have direct access to the imager embedded register data.
//  To be able to execute register checks for the left imager, the embedded registers must be
//  requested from the Slave DSP CPU, which gets left imager embedded data from the FPGA. This
//  is done by using the IPC.
//  
//  As the IPC bandwith is highly limited, only relevant registers are transferred. The IC sends
//  a 'Register Request' with a list of registers to the DSP, which in turn sends a response
//  with the contents of all selected left imager registers.
//  
//  There is a multiframe delay until register data of frame N is actually received by the IC.
//  At time of writing, this is in the region of ~4 frames.
//  
//  ==========================================================================================
//  =                                  CYCLIC REGISTER CHECKS                                =
//  ==========================================================================================
//  The ICRM does cyclic checking of register values by comparing the embedded register data
//  with the last written/known values. Those checks are handled in 'ICRM_e_CheckRegisters'
//  for the right imager. As the left imager embedded data travels a long way until they are
//  available at the IC inputs (see 'LEFT IMAGER EMBEDDED REGISTER DATA' above), they are
//  handled separately in 'ICRM_v_CheckRegistersLeft'.
//  
//  To allow correct verification of double buffered registers and for taking the long IPC
//  delay for left imager embedded data into account, the ICRM has history buffers for all
//  known registers, which store the values of the last N frames. The buffer depth is different
//  for left and right imager, due to different delays.
//  
//  As not all registers are part of the imager embedded data, some of them are cyclically read
//  via I2C. Those checks are handled seperately in ICRM_v_HandleI2CRegChecks().
//  
//  ==========================================================================================
//  =                             IMAGER REGISTER WRITE TIMING                               =
//  ==========================================================================================
//  The timing of I2C register transfers is critical in this application. Most of the registers
//  must be written before the rising edge of the frame-valid signal, some of them are allowed
//  to be written before embedded register data starts (until end of line #15 when counting
//  starts with #0). As the exposure control can not calculate the new register values until the
//  embedded statistics (end of frame) are available, those registers can only be written after
//  falling edge and must finish before rising edge (frame blanking). IC-ROI is allowed to be
//  written until line #15.
//  
//  All of the following numbers are based on MFC310 frame timing:
//  
//  The minimum frame blanking at time of writing is ~2.383ms, so all exposure relevant register
//  transfers must fit into this short gap. Transferring the current set of registers from IC
//  Part2 takes about 900 us per imager, so on stereo cameras we have total transfer time of
//  1.8ms and only ~500us spare time.
//  
//  Imager sync offset has also to be taken into account, which means that the left imager can
//  have an intended timing offset of up to +-25 lines (916us). Therefore the left imager must
//  be written first, so it's finished before its rising edge appears.
//  
//  All non exposure relevant registers are written while frame-valid is asserted, which is
//  not time critical due to the long time of frame valid beeing high.
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//  via GOTO on error. Code using this type of error handling is much easier to read,
//  as no nested if() statements are required and checking of error-code/flag on each
//  block can be omitted. Suppress QAC warnings related to this functionality:
//    PRQA S 2001,2015,7003 EOF
//  
//  We intentionally have several data structures on file scope, even when they are used
//  only in one function:
//    PRQA S 3218 EOF
//  
//  A subsequent declaration of 'xxxx' means that it is being used both as a structure/union member
//  and also as a label, tag or ordinary identifier.
//    PRQA S 0781,0783 EOF
//  
//  Possible dereference of NULL pointer
//    PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Wed, 14, Nov 2012  11:28 W. Europe Standard Time AM 
//**************************************************************************** */

#ifndef ic_regmanager_H
#define ic_regmanager_H

/*## dependency ic_registers */
#include "ic_registers.h"
/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_regmanager */
/*#[ ignore */
//  The IC Register Manager is a central component for handling imager register data. In summary,
//  it has the following tasks:
//  
//  - Managing of input register values in a buffer, which are extracted from image embedded data
//  - Buffering of output register values, and flushing them to the imager(s) on request
//  - Storage of N 'history' output register values
//  - Asynchronous register transfers (TX and RX)
//  - Synchronous register transfers (e.g. sensor initialization), including data verification
//  - Cyclic Register checking/verification. This includes checking of registers, which are not
//    part of embedded data and must therefore be read asynchronously via I2C
//  - Checking of I2C write timing against timing constraints, which must not be violated to
//    ensure deterministic imager behavior
//  - Handling embedded register data of the left imager, which is received via IPC, because
//    the imager datapath is not directly connected the processor which executes this part of
//    software.
//  
//  ==========================================================================================
//  =                          LEFT IMAGER EMBEDDED REGISTER DATA                            =
//  ==========================================================================================
//  On stereo cameras, the databus of the left imager is not connected to the MCU, on which the
//  IC is running. Therefore it does not have direct access to the imager embedded register data.
//  To be able to execute register checks for the left imager, the embedded registers must be
//  requested from the Slave DSP CPU, which gets left imager embedded data from the FPGA. This
//  is done by using the IPC.
//  
//  As the IPC bandwith is highly limited, only relevant registers are transferred. The IC sends
//  a 'Register Request' with a list of registers to the DSP, which in turn sends a response
//  with the contents of all selected left imager registers.
//  
//  There is a multiframe delay until register data of frame N is actually received by the IC.
//  At time of writing, this is in the region of ~4 frames.
//  
//  ==========================================================================================
//  =                                  CYCLIC REGISTER CHECKS                                =
//  ==========================================================================================
//  The ICRM does cyclic checking of register values by comparing the embedded register data
//  with the last written/known values. Those checks are handled in 'ICRM_e_CheckRegisters'
//  for the right imager. As the left imager embedded data travels a long way until they are
//  available at the IC inputs (see 'LEFT IMAGER EMBEDDED REGISTER DATA' above), they are
//  handled separately in 'ICRM_v_CheckRegistersLeft'.
//  
//  To allow correct verification of double buffered registers and for taking the long IPC
//  delay for left imager embedded data into account, the ICRM has history buffers for all
//  known registers, which store the values of the last N frames. The buffer depth is different
//  for left and right imager, due to different delays.
//  
//  As not all registers are part of the imager embedded data, some of them are cyclically read
//  via I2C. Those checks are handled seperately in ICRM_v_HandleI2CRegChecks().
//  
//  ==========================================================================================
//  =                             IMAGER REGISTER WRITE TIMING                               =
//  ==========================================================================================
//  The timing of I2C register transfers is critical in this application. Most of the registers
//  must be written before the rising edge of the frame-valid signal, some of them are allowed
//  to be written before embedded register data starts (until end of line #15 when counting
//  starts with #0). As the exposure control can not calculate the new register values until the
//  embedded statistics (end of frame) are available, those registers can only be written after
//  falling edge and must finish before rising edge (frame blanking). IC-ROI is allowed to be
//  written until line #15.
//  
//  All of the following numbers are based on MFC310 frame timing:
//  
//  The minimum frame blanking at time of writing is ~2.383ms, so all exposure relevant register
//  transfers must fit into this short gap. Transferring the current set of registers from IC
//  Part2 takes about 900 us per imager, so on stereo cameras we have total transfer time of
//  1.8ms and only ~500us spare time.
//  
//  Imager sync offset has also to be taken into account, which means that the left imager can
//  have an intended timing offset of up to +-25 lines (916us). Therefore the left imager must
//  be written first, so it's finished before its rising edge appears.
//  
//  All non exposure relevant registers are written while frame-valid is asserted, which is
//  not time critical due to the long time of frame valid beeing high.
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//  via GOTO on error. Code using this type of error handling is much easier to read,
//  as no nested if() statements are required and checking of error-code/flag on each
//  block can be omitted. Suppress QAC warnings related to this functionality:
//    PRQA S 2001,2015,7003 EOF
//  
//  We intentionally have several data structures on file scope, even when they are used
//  only in one function:
//    PRQA S 3218 EOF
//  
//  A subsequent declaration of 'xxxx' means that it is being used both as a structure/union member
//  and also as a label, tag or ordinary identifier.
//    PRQA S 0781,0783 EOF
//  
//  Possible dereference of NULL pointer
//    PRQA S 0506 EOF
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Current mode for setting register data:
//  
//  ICRM_e_TXMODE_BUFFER_TILL_FLUSHED:
//    All write-accesss to registers will be buffered, until they are flushed by calling
//    ICRM_e_FlushSensorRegisters() or ICRM_e_WriteRegistersPart2().
//  
//  ICRM_e_TXMODE_WRITEINSTANT_SYNC:
//    Every write-access to a register will immediately execute a synchronous I2C transfer
/*#[ type ICRM_E_TxMode */
typedef enum {
    ICRM_e_TXMODE_BUFFER_TILL_FLUSHED,
    ICRM_e_TXMODE_WRITEINSTANT_SYNC
}  ICRM_E_TxMode;
/*#]*/

//  Stores I2C write timing statistics
/*## type ICRM_S_I2CTiming */
typedef struct ICRM_S_I2CTiming {
    //  Description:   Finish time of IC Part1 initiated register transfer (I2C)
    //  Range:         0-2^32
    //  Resolution:    1
    //  Unit:          us
    uint32 ui32_FinishPart1;		/*## attribute ui32_FinishPart1 */
    //  Description:   Finish time of IC Part2 initiated register transfer (I2C)
    //  Range:         0-2^32
    //  Resolution:    1
    //  Unit:          us
    uint32 ui32_FinishPart2;		/*## attribute ui32_FinishPart2 */
    //  Description:   Slack for IC Part2 initiated register transfer (I2C). This is the time
    //                 difference between the frame-valid signal rising edge and and the I2C
    //                 transfer finish time. A too low slack indicates a too slow/late register
    //                 transfer, which may lead to undesired imager behavior.
    //  Range:         -32768-32767
    //  Resolution:    1
    //  Unit:          us
    sint16 si16_SlackPart2;		/*## attribute si16_SlackPart2 */
    //  Description:   Overall minimum Slack for IC Part2 initiated register transfer (I2C). This is
    //                 the time difference between the frame-valid signal rising edge and and the
    //                 I2C transfer finish time. A too low slack indicates a too slow/late register
    //                 transfer, which may lead to undesired imager behavior.
    //  Range:         -32768-32767
    //  Resolution:    1
    //  Unit:          us
    sint16 si16_SlackPart2Min;		/*## attribute si16_SlackPart2Min */
} ICRM_S_I2CTiming;

//  Measurement data from the IC Register Manager
/*## type ICRM_S_MeasData */
typedef struct ICRM_S_MeasData {
    //  Description:   Register address of last register, which failed in register checks (left imager).
    //  Range:         0-0xFFFF
    //  Resolution:    1
    //  Unit:          none
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    uint16 ui16_CheckFailedRegisterAddrLeft;
    #endif		/*## attribute ui16_CheckFailedRegisterAddrLeft */
    //  Description:   Register address of last register, which failed in register checks (right imager).
    //  Range:         0-0xFFFF
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_CheckFailedRegisterAddrRight;		/*## attribute ui16_CheckFailedRegisterAddrRight */
    //  Description:   Counts number of left imager register check executions
    //  Range:         0-65535
    //  Resolution:    1
    //  Unit:          none
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    uint16 ui16_CheckLeftExecCount;
    #endif		/*## attribute ui16_CheckLeftExecCount */
    //  Description:   Counts number of left imager register receptions, which are sent from the DSP
    //                 via IPC to the IC. Increments each time a new register set from left imager
    //                 has been seen.
    //  Resolution:    1
    //  Unit:          none
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    uint16 ui16_LeftRegistersReceiveCount;
    #endif		/*## attribute ui16_LeftRegistersReceiveCount */
    //  Description:   The timing lag (number of frames) between the right and left imager register data.
    //                 The lag is always positive, as the left imager register data is comming via IPC from DSP.
    //  Range:         0-65535
    //  Resolution:    1
    //  Unit:          frames
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    uint16 ui16_LeftRegistersLag;
    #endif		/*## attribute ui16_LeftRegistersLag */
    //  Description:   I2C register transfer timing data for right imager
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    ICRM_S_I2CTiming s_I2CTimingRight;		/*## attribute s_I2CTimingRight */
    //  Description:   I2C register transfer timing data for left imager
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICRM_S_I2CTiming s_I2CTimingLeft;
    #endif		/*## attribute s_I2CTimingLeft */
} ICRM_S_MeasData;

//  State of an external (i.e. via XCP) requested register transfer
/*#[ type ICRM_E_RegTransExtState */
typedef enum
{
  ICRM_e_REGTRANSEXTSTATE_IDLE,
  ICRM_e_REGTRANSEXTSTATE_ARMED,
  ICRM_e_REGTRANSEXTSTATE_PROCESSING,
  ICRM_e_REGTRANSEXTSTATE_DONE,
  ICRM_e_REGTRANSEXTSTATE_ERROR
} ICRM_E_RegTransExtState;
/*#]*/

//  Container which stores external register read/write requests
/*## type ICRM_S_RegTransExtern */
typedef struct ICRM_S_RegTransExtern {
    IC_S_RegDataPair s_Register;		/*## attribute s_Register */
    IC_E_TRANSFMODE e_TransferType;		/*## attribute e_TransferType */
    IC_E_Imager e_Imager;		/*## attribute e_Imager */
    ICRM_E_RegTransExtState e_State;		/*## attribute e_State */
} ICRM_S_RegTransExtern;

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  ICRM_e_Init
//  
//  Description:
//    Initializes this module, which includes some static code checks. See activity diagram
//    for details.
//  
//  Preconditions:
//    - 'ic_driver' must be initialized
//  
//  Parameter:     ICRM_S_MeasData * const ps_MeasDataIn   <In>
//  Description:   Pointer to measurement data structure, which will cyclically be updated by this module.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_Init(ICRM_S_MeasData * const) */
IC_E_ERROR ICRM_e_Init(ICRM_S_MeasData * const ps_MeasDataIn);

//*****************************************************************************
//  Functionname:  ICRM_v_SetRegister
//  
//  Description:
//    Sets the value of a specific register, which will be written to all imagers.
//  
//    The actual behavior depends on the current TX_MODE (ICRM_e_TxMode), which can be set
//    by calling ICRM_v_SetTxMode():
//  
//    ICRM_e_TXMODE_BUFFER_TILL_FLUSHED:
//      The register value is written to the current output buffer and the register is marked
//      as 'changed'. No data is immediately written to the imager(s). The flush function
//      ICRM_e_FlushSensorRegisters*() must be called later in order to write the register
//      (and all other changed registers) to the imager.
//  
//    ICRM_e_TXMODE_WRITEINSTANT_SYNC:
//      The imagers are directly written through to the imagers. The transfer is synchronous,
//      so this function does not return before the transfer is finished.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  Parameter:     const IMGREG_E_SENSOR_REG e_Reg   <In>
//  Description:   Target register
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_Value   <In>
//  Description:   The new register value
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_SetRegister(const IMGREG_E_SENSOR_REG,const uint16) */
void ICRM_v_SetRegister(const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_Value);

//*****************************************************************************
//  Functionname:  ICRM_v_SetRegisterSingle
//  
//  Description:
//    Sets the value of a specific register, which will be written to one or both imagers,
//    depending on function arguments.
//  
//    The actual behavior depends on the current TX_MODE (ICRM_e_TxMode), which can be set
//    by calling ICRM_v_SetTxMode():
//  
//    ICRM_e_TXMODE_BUFFER_TILL_FLUSHED:
//      The register value is written to the current output buffer and the register is marked
//      as 'changed'. No data is immediately written to the imager(s). The flush function
//      ICRM_e_FlushSensorRegisters*() must be called later in order to write the register
//      (and all other changed registers) to the imager.
//  
//    ICRM_e_TXMODE_WRITEINSTANT_SYNC:
//      The registers are directly written through to the imagers. The transfer is synchronous,
//      so this function does not return before the transfer is finished.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  Parameter:     const IMGREG_E_SENSOR_REG e_Reg   <In>
//  Description:   Target register
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_Value   <In>
//  Description:   New register value
//  Range:         0 - 0xFFFF
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  Description:   Target imager
//  Range:         Specific imager or 'ALL'
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_SetRegisterSingle(const IMGREG_E_SENSOR_REG,const uint16,const IC_E_Imager) */
void ICRM_v_SetRegisterSingle(const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_Value, const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  ICRM_e_SensorRegRXSingle
//  
//  Description:
//    Reads a single register via I2C from a specific imager.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//  Parameter:     const IC_E_Imager e_SensorId   <In>
//  Description:   The specific Imager from which the register value will be read.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_RegAddr   <In>
//  Description:   Address of to be read register
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint16 * const pui16_RegValue   <In>
//  Description:   Target will be updated with to the read register value
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_SensorRegRXSingle(const IC_E_Imager,const uint16,uint16 * const) */
IC_E_ERROR ICRM_e_SensorRegRXSingle(const IC_E_Imager e_SensorId, const uint16 ui16_RegAddr, uint16 * const pui16_RegValue);

//*****************************************************************************
//  Functionname:  ICRM_e_SensorRegTXSingle
//  
//  Description:
//    Writes a single register via I2C to a specific or to all imagers. If 'ui16_VerifyBitmask'
//    is not zero, then the register will be verified by reading back the value via I2C and
//    compareing it against the written value. The bitmask is applied before comparation is done.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//  Parameter:     const IC_E_Imager e_SensorId   <In>
//  Description:   The specific Imager to which the register value will be written.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_RegAddr   <In>
//  Description:   Address of to be written register
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_RegValue   <In>
//  Description:   Value, which will be written to the selected register.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_VerifyBitmask   <In>
//  Description:   Bitmask used for verification. Only bits set to '1' will be verified after read back.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_SensorRegTXSingle(const IC_E_Imager,const uint16,const uint16,const uint16) */
IC_E_ERROR ICRM_e_SensorRegTXSingle(const IC_E_Imager e_SensorId, const uint16 ui16_RegAddr, const uint16 ui16_RegValue, const uint16 ui16_VerifyBitmask);

//*****************************************************************************
//  Functionname:  ICRM_e_ReadInitialRegisters
//  
//  Description:
//    Reads all registers contained in the list 'ICCFG_cae_InitialRegsReadI2C' via I2C and copies
//    the values to both the register input buffer and the current register output buffer. The RX
//    transfer is synchronous and the function returns not before all registers have been read.
//    
//    The read values can be used as initial values for cyclic register checks for all registers,
//    whose reset values are not known (e.g. calibration registers).
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_ReadInitialRegisters() */
IC_E_ERROR ICRM_e_ReadInitialRegisters(void);

//*****************************************************************************
//  Functionname:  ICRM_e_ReadRegsViaI2C
//  
//  Description:
//    Reads a list of registers via I2C from all imagers and copies the values to both
//    the register input buffer and the current register output buffer. The RX transfer
//    is sychronous and the function returns not before all registers have been read.
//    
//    The read values can be used as initial values for cyclic register checks for all
//    registers, whose reset values are not known (e.g. calibration registers).
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//  Parameter:     const IMGREG_E_SENSOR_REG * const pe_Regs   <In>
//  Description:   List of registers which are to be read.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_NumRegs   <In>
//  Description:   Number of entries in 'pe_Regs'
//  Range:         0-0xffff
//  Resolution:    1
//  Unit:          none
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  Description:   Frame type of the target buffer, which will be updated with the read values.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_ReadRegsViaI2C(const IMGREG_E_SENSOR_REG * const,const uint16,const IC_E_FRAMETYPE) */
IC_E_ERROR ICRM_e_ReadRegsViaI2C(const IMGREG_E_SENSOR_REG * const pe_Regs, const uint16 ui16_NumRegs, const IC_E_FRAMETYPE e_FrameType);

//*****************************************************************************
//  Functionname:  ICRM_e_SendInitSequence
//  
//  Description:
//    Sends a sensor register intialization sequence to all imagers. The transfer mode is
//    synchronous, so the method returns not before all registers have been written.
//  
//    Setting 'IC_cui16_SPECIALADDR_DELAY' as a register address allows to insert delays.
//    The register value is then interpreted as a time delay (milliseconds).
//  
//    After writing all values to the imagers, they are copied to the current register
//    output buffer. This ensures that future register checks uses correct register values.
//  
//    This method includes a double check of all register values written during initalization:
//  
//    1) Each written register is immediately verified by reading back the value via I2C
//       and comparing the read value with the written one.
//    2) After all registers have been written, the contents are read back and checked again.
//       This is done by looping again through the init sequence and read each listed register
//       via I2C. The register value is then compared against the 'last' value of this
//       register contained in the init sequence.
//       There is a special handling of the 
//  
//    For each single register verification step, a bitmask is applied to the register value
//    in case there is an entry in 'ICRM_cas_CompareBitmasks' for the register. Registers
//    without a dedicated bitmask are checked with all bits. This allows to check registers
//    that have some bits which are always read as '0' or '1', or for other special registers
//    which never reflects the written value.
//  
//    Any verification error will abort the initalization of the sensor, and the function
//    returns with an error.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//  Parameter:     const IC_S_RegDataPair * const ps_RegDataBuffer   <In>
//  Description:   List of register address/data pairs, which will be written to the imager(s).
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_NumElements   <In>
//  Description:   Number of entries in 'ps_RegDataBuffer'
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_SendInitSequence(const IC_S_RegDataPair * const,const uint16) */
IC_E_ERROR ICRM_e_SendInitSequence(const IC_S_RegDataPair * const ps_RegDataBuffer, const uint16 ui16_NumElements);

//*****************************************************************************
//  Functionname:  ICRM_e_SendInitSequenceAsync
//  
//  Description:
//    Sends a sensor register intialization sequence to the imager(s). This method is
//    asynchronous and returns immediately after buffers have been passed to the register
//    transfer layer. After writing all values to the imagers, they are copied to the
//    current register output buffer. This ensures that future register checks uses
//    correct register values.
//  
//    As the transfer is asynchronous, no register verification is done here. Nevertheless,
//    the cyclic register check will catch any inconsistent register which may be written
//    incorrectly.
//  
//    NOTE: In contrast to ICRM_e_SendInitSequence(), it is _not_ allowed to insert delays
//          in the initalization sequence!
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//  Parameter:     const IC_S_RegDataPair * const ps_RegDataBuffer   <In>
//  Description:   List of register address/data pairs, which will be written to the imager(s).
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_NumElements   <In>
//  Description:   Number of entries in 'ps_RegDataBuffer'
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_SendInitSequenceAsync(const IC_S_RegDataPair * const,const uint16) */
IC_E_ERROR ICRM_e_SendInitSequenceAsync(const IC_S_RegDataPair * const ps_RegDataBuffer, const uint16 ui16_NumElements);

//*****************************************************************************
//  Functionname:  ICRM_e_GetBuffersWritePart2
//  
//  Description:
//    Fills a register TX buffer array with register addresses and values, which have to
//    be written to a specific imager during IC Part2 execution (during frame blanking).
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  Description:   The Imager whose buffered values are returned.
//  Range:         Only specific imager (not ALL)
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     IC_S_RegDataPair const * * const pps_AddrDataPairs   <Out>
//  Description:   Pointer will be set to the target register buffer, that holds the register data.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint16 * const pui16_NumElements   <Out>
//  Description:   Sets target to the number of registers contained in '*pps_AddrDataPairs'
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_GetBuffersWritePart2(const IC_E_Imager,IC_S_RegDataPair const * * const,uint16 * const) */
IC_E_ERROR ICRM_e_GetBuffersWritePart2(const IC_E_Imager e_Imager, IC_S_RegDataPair const * * const pps_AddrDataPairs, uint16 * const pui16_NumElements);

//*****************************************************************************
//  Functionname:  ICRM_e_GetBuffersWriteWhenChanged
//  
//  Description:
//    Fills a register TX buffer array with register addresses and values, which have
//    been 'touched' since last call to this function. Only registers contained in
//    'ICRM_cae_RegistersToWriteWhenChanged' are actually written to the imager.
//  
//    'Touched' means, that ICRM_v_SetRegister* has been called. Those registers are
//    also returned, even if the register value did not change.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  Description:   The Imager whose buffered values are returned.
//  Range:         Only specific imager (not ALL)
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     IC_S_RegDataPair const * * const pps_AddrDataPairs   <Out>
//  Description:   Pointer will be set to the target register buffer, that holds the register data.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint16 * const pui16_NumElements   <In>
//  Description:   Sets target to the number of registers contained in '*pps_AddrDataPairs'
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_GetBuffersWriteWhenChanged(const IC_E_Imager,IC_S_RegDataPair const * * const,uint16 * const) */
IC_E_ERROR ICRM_e_GetBuffersWriteWhenChanged(const IC_E_Imager e_Imager, IC_S_RegDataPair const * * const pps_AddrDataPairs, uint16 * const pui16_NumElements);

//*****************************************************************************
//  Functionname:  ICRM_e_FlushSensorRegisters
//  
//  Description:
//    Flushs 'touched' registers to all available imagers. Only registers which are contained in
//    the list 'ICRM_cae_RegistersToWriteWhenChanged' are actually written to the imagers. The
//    transfer mode (async or sync) can be selected via 'b_WaitDone'.
//  
//    See ICRM_e_FlushSensorRegistersSingle() for details.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be initialized
//  
//  Parameter:     const boolean b_WaitDone   <In>
//  Description:   Sets the register transfer mode.
//  Range:         'b_TRUE':  Use synchronous I2C transfer (block until done)
//                 'b_FALSE': Use asynchronous I2C transfer (function immediately returns)
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_FlushSensorRegisters(const boolean) */
IC_E_ERROR ICRM_e_FlushSensorRegisters(const boolean b_WaitDone);

//*****************************************************************************
//  Functionname:  ICRM_e_WriteRegistersPart1
//  
//  Description:
//    Initiates a transfer of all 'touched' registers to the sensor, which shall be flushed
//    during execution of IC Part 1 (during frame-valid = HIGH).
//  
//    The transfer is asynchronous, so this function returns after buffers are passed to
//    the I2C driver.
//  
//    See ICRM_e_FlushSensorRegisters() for details.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_WriteRegistersPart1() */
IC_E_ERROR ICRM_e_WriteRegistersPart1(void);

//*****************************************************************************
//  Functionname:  ICRM_e_WriteRegistersPart2
//  
//  Description:
//    Initiates a transfer of all registers to the sensor, which shall be written
//    during execution of IC Part 2 (during frame-blanking). It first schedules a transfer
//    of all left imager's registers, after this follow all right imager's registers.
//  
//    The transfer is asynchronous, so this function returns after buffers are passed to
//    the I2C driver.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_WriteRegistersPart2() */
IC_E_ERROR ICRM_e_WriteRegistersPart2(void);

//*****************************************************************************
//  Functionname:  ICRM_v_RotateOutputShadBuffers
//  
//  Description:
//    This function handles updating/rotation of the register output shadow/history buffers,
//    their indexes and current entry pointers. It must be called when a new frame starts,
//    after register checks have been executed and before any register is modified by calling
//    ICRM_v_SetRegister*() functions.
//  
//    The history buffers store the register output values of the last N frames. They are arranged
//    as a cyclic buffer, which has the most recent register values at dynamic index 'n' (and
//    not constant at index 0 or 'N-1').
//  
//    This function sets the current output buffer pointer to the next entry in the cyclic
//    buffer (which currently stores the 'oldest' register data), and replaces that data
//    with the last (most recent) register values.
//  
//    So after this function returns, the output buffer pointers points to the next buffer,
//    which holds the values which were last written to the imager.
//  
//  Preconditions:
//    - This Module must be initialized
//    - Cyclic register checks must be finished for current frame, in case they are executed
//      at all. Otherwise they will fail!
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_RotateOutputShadBuffers() */
void ICRM_v_RotateOutputShadBuffers(void);

//*****************************************************************************
//  Functionname:  ICRM_v_CheckRegisters
//  
//  Description:
//    Verifies register settings by checking the values contained in the embedded data against
//    those values, which are 'expected' to be in the imager registers. The register output
//    shadow/history buffers are used for comparation. Only selected registers are involved in 
//    the check, and each of them has a dedicated bitmask, which masks some bits which can
//    not be checked (i.e. they are R/O status bits which may change).
//  
//    The imager has both double-bufferend and unbuffered registers, which are visible in
//    embedded data with different frame delay. Unbuffered registes appear in the embedded
//    data of frame n+1, double-buffered registers are visible in frame n+2. Because of this
//    there are two lists of registers, which are checked with different time-delay against
//    the history buffers.
//  
//    NOTE: This function checks only register values of the right/master imager.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  Description:   The specific frame type (buffer), for which registers are checked
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_CheckRegisters(const IC_E_FRAMETYPE) */
void ICRM_v_CheckRegisters(const IC_E_FRAMETYPE e_FrameType);

//*****************************************************************************
//  Functionname:  ICRM_v_CheckRegistersLeft
//  
//  Description:
//    Verifies register settings by checking the values contained in the embedded data against
//    those values, which are 'expected' to be in the imager registers. The register output
//    shadow/history buffers are used for comparation. Only selected registers are involved in 
//    the check, and each of them has a dedicated bitmask, which masks some bits which can
//    not be checked (i.e. they are R/O status bits which may change).
//  
//    The imager has both double-bufferend and unbuffered registers, which are visible in
//    embedded data with different frame delay. Unbuffered registes appear in the embedded
//    data of frame n+1, double-buffered registers are visible in frame n+2. Because of this
//    there are two lists of registers, which are checked with different time-delay against
//    the history buffers.
//  
//    NOTE: This function checks only register values of the left imager.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  
//  Parameter:     const uint16 ui16_FrameNumRight   <In>
//  Description:   Current frame number (e.g. from right imager embedded or statistic data)
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_CheckRegistersLeft(const uint16) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICRM_v_CheckRegistersLeft(const uint16 ui16_FrameNumRight);
#endif

//*****************************************************************************
//  Functionname:  ICRM_v_HandleConstRegChecks
//  
//  Description:
//    Checks selected (critical) registers against constant values. This list of registers and
//    the value to which they are compared against are populated in the list 'ICRM_cas_VerifyRegsConst'.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_HandleConstRegChecks() */
void ICRM_v_HandleConstRegChecks(void);

//*****************************************************************************
//  Functionname:  ICRM_v_HandleI2CRegChecks
//  
//  Description:
//    This function does verification of register values, which are not contained in the embedded
//    data (not written into register input buffers ICRM_S_ImagerContext.aRb_RegsIn[]). The registers
//    are read via I2C and compared against the most recent (current) output buffer.
//  
//    One imager is checked in each cycle. On execution 'n' this method schedules a asynchronous
//    I2C read transfer of all registers, which are to be checked. On next cycle 'n+1' the received
//    values are compared against the expected values. In the same cycle 'n+1', the next read
//    transaction is queued. On stereo-cameras this is the 'other' imager.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_HandleI2CRegChecks() */
void ICRM_v_HandleI2CRegChecks(void);

//*****************************************************************************
//  Functionname:  ICRM_v_HandleRegTransExtReq
//  
//  Description:
//    This function handles external (i.e. via XCP) requested register read/writes. If a read
//    or write has been scheduled by calling ICRM_v_ScheduleExtRegTransfer(), this function
//    passes the transfer to the OS-Wrapper / I2C driver framework, which executes the request.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_HandleRegTransExtReq() */
void ICRM_v_HandleRegTransExtReq(void);

//*****************************************************************************
//  Functionname:  ICRM_e_RegTransExternalSchedule
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     const IC_E_TRANSFMODE e_TransMode   <In>
//  
//  
//  Parameter:     const uint16 ui16_RegAddr   <In>
//  
//  
//  Parameter:     const uint16 ui16_RegDataIfWrite   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_RegTransExternalSchedule(const IC_E_Imager,const IC_E_TRANSFMODE,const uint16,const uint16) */
IC_E_ERROR ICRM_e_RegTransExternalSchedule(const IC_E_Imager e_Imager, const IC_E_TRANSFMODE e_TransMode, const uint16 ui16_RegAddr, const uint16 ui16_RegDataIfWrite);

//*****************************************************************************
//  Functionname:  ICRM_v_RegTransExternalGetResult
//  
//  
//  
//  Parameter:     IC_S_RegTransExtResult * const ps_Result   <Out>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_RegTransExternalGetResult(IC_S_RegTransExtResult * const) */
void ICRM_v_RegTransExternalGetResult(IC_S_RegTransExtResult * const ps_Result);

//*****************************************************************************
//  Functionname:  ICRM_v_RegTransRxLeftSchedule
//  
//  Description:
//    Schedules I2C-based register read from left imager for a specific set of registers,
//    which is defined in the configuration file 'ic_cfg_registers.h'.
//  
//  Preconditions:
//    - This module must be initialized
//    - Imagers must be ready for I2C comm
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_RegTransRxLeftSchedule() */
void ICRM_v_RegTransRxLeftSchedule(void);

//*****************************************************************************
//  Functionname:  ICRM_v_RegTransRxLeftDone
//  
//  Description:
//    This function is called when an asynchronous left imager register read job finished.
//    It takes over the read data into the register input buffer and stores the timestamp,
//    which indicates the point in time when the read transfer was finished.
//  
//  Preconditions:
//    - Left imager asynchronous I2C transfer finished as a result of call
//      ICRM_v_RegTransferRxLeftSchedule()
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_RegTransRxLeftDone() */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICRM_v_RegTransRxLeftDone(void);
#endif

//*****************************************************************************
//  Functionname:  ICRM_ui64_GetRegRxAsyncTimeLeft
//  
//  Description:
//    Returns the timestamp for the point in time, when a left imager asynchronous read job,
//    which has been scheduled by calling ICRM_v_RegTransferRxLeftSchedule(), was finished.
//  
//  Preconditions:
//    - ICRM_v_RegTransferRxLeftSchedule() has been called
//  
//    
//  
//  return         uint64
//**************************************************************************** */
/*## operation ICRM_ui64_GetRegRxAsyncTimeLeft() */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
uint64 ICRM_ui64_GetRegRxAsyncTimeLeft(void);
#endif

//*****************************************************************************
//  Functionname:  ICRM_v_UpdateCommStats
//  
//  Description:
//    Reads imager communication statistics (I2C ISR runtime, I2C ISR count, ...) from the
//    underlying driver and updates profiling data, in case 'IC_PROFILING_ENABLED == 1'.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be initialized
//  
//  Parameter:     uint16 * const pui16_IsrRuntimeOut   <Out>
//  Description:   The target is set to the total ISR runtime, which has been sum up since
//                 last call of this function.
//  Range:         none
//  Resolution:    1
//  Unit:          us
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_UpdateCommStats(uint16 * const) */
void ICRM_v_UpdateCommStats(uint16 * const pui16_IsrRuntimeOut);

//*****************************************************************************
//  Functionname:  ICRM_v_CheckI2CTiming
//  
//  Description:
//    This function checks the timing/finish times of imager register write transactions, which
//    have been queued during the last frame. Due to some constraints in the imager, some registers
//    must be written before the rising edge of the frame valid signal. Violation of the timing
//    will result in unexpected imager behavior (e.g. wrong exposure settings, wrong histogram
//    values).
//  
//    For each imager, the timing-difference between finishing register writes and the rising edge
//    of the following frame is calculated ("Slack") and checked against thresholds which are
//    defined in 'ic_cfg.h'.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  Parameter:     const uint32 ui32_FrameStartUs   <In>
//  Description:   Timestamp of the framevalid high edge.
//  Range:         0 - 0xFFFFFFFF
//  Resolution:    none
//  Unit:          us
//  
//  Parameter:     const sint32 si32_TimingOffsetLR   <In>
//  Description:   Frame timing offset between left/right imager.
//  Range:         none
//  Resolution:    1
//  Unit:          us
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_CheckI2CTiming(const uint32,const sint32) */
void ICRM_v_CheckI2CTiming(const uint32 ui32_FrameStartUs, const sint32 si32_TimingOffsetLR);

//*****************************************************************************
//  Functionname:  ICRM_v_GetRegisterRequest
//  
//  Description:
//    The embedded data of the left imager is not directly accessable by the IC. The register
//    values can only be received via IPC from the slave processor. To limit bandwidth, only
//    selected registers are sent via IPC. Those registers are explicitly requested by the IC.
//  
//    This function fills the register transfer request buffer at 'ps_Request' with a list of
//    registers, which are requested from the slave processor that has access to left imager
//    embedded data.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  Parameter:     IC_S_RegTransfReq * const ps_Request   <In>
//  Description:   Output register request buffer, which will be filled
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_GetRegisterRequest(IC_S_RegTransfReq * const) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICRM_v_GetRegisterRequest(IC_S_RegTransfReq * const ps_Request);
#endif

//*****************************************************************************
//  Functionname:  ICRM_e_ProcessRegisterResponse
//  
//  Description:
//    Processes a list of register values, which have been received from the left imager
//    via IPC (see module description for additional details).
//  
//    The register values, which are part of the response, are copied to the register
//    input buffer that is associated with the left imager. The buffer is then passed to
//    the imager driver, which allows other modules to access the interpreted/converted
//    register data.
//  
//  Preconditions:
//    - This Module must be initialized
//    - 'ic_driver' must be initialized
//  
//  Parameter:     const uint16 ui16_FrameNum   <In>
//  Description:   Current frame number
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const IC_S_RegTransfResp * const ps_Resp   <In>
//  Description:   Pointer to left imager register data which has been received from slave processor.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_ProcessRegisterResponse(const uint16,const IC_S_RegTransfResp * const) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
IC_E_ERROR ICRM_e_ProcessRegisterResponse(const uint16 ui16_FrameNum, const IC_S_RegTransfResp * const ps_Resp);
#endif

//*****************************************************************************
//  Functionname:  ICRM_ui32_GetNumTransferErrors
//  
//  Description:
//    Returns the total number of register RX/TX transfer errors, which occurred
//    since module initializatin.
//  
//  Preconditions:
//    None
//  
//    
//  
//  return         uint32
//**************************************************************************** */
/*## operation ICRM_ui32_GetNumTransferErrors() */
uint32 ICRM_ui32_GetNumTransferErrors(void);

//*****************************************************************************
//  Functionname:  ICRM_pRb_GetRegistersIn
//  
//  Description:
//    Returns a pointer to the most recent register set, which has been received from
//    the imager.
//  
//  Preconditions:
//    - This Module must be initialized
//    - At least 'ui16_NumFramesBack' frames must have passed since module init,
//      whereas ICRM_v_RotateOutputShadBuffers() has been called in each frame.
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  Description:   The selected imager, whose embedded register buffer will be returned.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  Description:   The selected frametype, for which the register buffer will be returned.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_S_RegBuff * 
//**************************************************************************** */
/*## operation ICRM_pRb_GetRegistersIn(const IC_E_Imager,const IC_E_FRAMETYPE) */
IC_S_RegBuff * ICRM_pRb_GetRegistersIn(const IC_E_Imager e_Imager, const IC_E_FRAMETYPE e_FrameType);

//*****************************************************************************
//  Functionname:  ICRM_v_SetTXMode
//  
//  Sets the behavior how ICRM_v_SetRegister*() works
//  
//  Parameter:     const ICRM_E_TxMode e_Mode   <In>
//  Description:   Register write mode (see type description)
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_SetTXMode(const ICRM_E_TxMode) */
void ICRM_v_SetTXMode(const ICRM_E_TxMode e_Mode);

//*****************************************************************************
//  Functionname:  ICRM_e_GetTXMode
//  
//  Description:
//    Returns current TX mode, which is used when calling 'ICRM_v_SetRegister*'.
//  
//  Preconditions:
//    None
//  
//    
//  
//  return         ICRM_E_TxMode
//**************************************************************************** */
/*## operation ICRM_e_GetTXMode() */
ICRM_E_TxMode ICRM_e_GetTXMode(void);

//*****************************************************************************
//  Functionname:  ICRM_e_SetRegisterResetValues
//  
//  Description:
//    Sets the internal register output buffer of a specific register to the default imager
//    reset values, depending on the imager model and revision. This can be used to provide
//    starting values for cyclic register checks.
//  
//  Preconditions:
//    none
//  
//  Returns:
//    IC_e_ERR_OK:                    No error occurred
//    IC_e_ERR_UNSUPPORTED_IMAGER:    The imager model/revision is not known
//    IC_e_ERR_GET_REGISTER_DEFAULTS: An internal error occurred
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  Description:   Selects the imager buffer, which will be initialized with reset values.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_ModelId   <In>
//  Description:   The model id of the imager, whose reset values will be used.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint8 ui8_RevisionNum   <In>
//  Description:   The revision number of the imager, whose reset values will be used.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_SetRegisterResetValues(const IC_E_Imager,const uint16,const uint8) */
IC_E_ERROR ICRM_e_SetRegisterResetValues(const IC_E_Imager e_Imager, const uint16 ui16_ModelId, const uint8 ui8_RevisionNum);

//*****************************************************************************
//  Functionname:  ICRM_e_FindLastRegValue
//  
//  Description:
//    Searches for the last register value in a register initialization list.
//  
//  Returns:
//    IC_e_ERR_OK:            Register was found in the list out-value contains value
//    IC_e_ERR_NOT_AVAILABLE: Register could not be found in the list, out-value unchanged
//  
//  Preconditions:
//    none
//  
//  Parameter:     const IMGREG_E_SENSOR_REG e_Register   <In>
//  Description:   Register which is searched for in the list
//  Range:         (enum)
//  Resolution:    none
//  Unit:          none
//  
//  
//  Parameter:     const IC_S_RegDataPair * const ps_RegDataBuffer   <In>
//  Description:   Pointer to register initialization list
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_NumElements   <In>
//  Description:   Number of entries in the initialization list (ps_RegDataBuffer)
//  Range:         0-0xFFFF
//  Resolution:    1
//  Unit:          none
//  
//  Parameter:     uint16 * const pui16_InitValue   <Out>
//  Description:   Output register value, which is set to the found entry value
//  Range:         0-0xFFFF
//  Resolution:    1
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_FindLastRegValue(const IMGREG_E_SENSOR_REG ,const IC_S_RegDataPair * const,const uint16,uint16 * const) */
IC_E_ERROR ICRM_e_FindLastRegValue(const IMGREG_E_SENSOR_REG e_Register, const IC_S_RegDataPair * const ps_RegDataBuffer, const uint16 ui16_NumElements, uint16 * const pui16_InitValue);


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_regmanager.h
*********************************************************************/
