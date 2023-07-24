//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_regmanager.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:58CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_regmanager
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_regmanager.c
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
//! CREATION DATE:   Wed, 14, Nov 2012  2:13 W. Europe Standard Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_regmanager.h"
/*## dependency ic_cfg_registers */
#include "ic_cfg_registers.h"
/*## dependency ic_common */
#include "ic_common.h"
/*## dependency ic_driver */
#include "ic_driver.h"
/*## dependency ic_errmanager */
#include "ic_errmanager.h"
/*## dependency ic_oswrapper */
#include "ic_oswrapper.h"
/*## dependency ic_profiling */
#include "ic_profiling.h"
/*## dependency ic_registers_bitmasks */
#include "ic_registers_bitmasks.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_regmanager */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Structure for storing a tuple of register address and a bitmask
/*## type ICRM_S_AddrBitmaskPair */
typedef struct ICRM_S_AddrBitmaskPair {
    //  Description:   Register address
    //  Range:         0-65535
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_Addr;		/*## attribute ui16_Addr */
    //  Description:   Bitmask
    //  Range:         0-65535
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_Bitmask;		/*## attribute ui16_Bitmask */
} ICRM_S_AddrBitmaskPair;

//  Stores I2C write transfer finish timestamps
/*## type ICRM_S_I2CFinishTimes */
typedef struct ICRM_S_I2CFinishTimes {
    //  Description:   Finish time of IC Part1 initiated register transfer (I2C) for right imager
    //  Range:         0-2^32
    //  Resolution:    1
    //  Unit:          us
    uint32 ui32_Part1Right;		/*## attribute ui32_Part1Right */
    //  Description:   Finish time of IC Part1 initiated register transfer (I2C) for left imager
    //  Range:         0-2^32
    //  Resolution:    1
    //  Unit:          us
    uint32 ui32_Part1Left;		/*## attribute ui32_Part1Left */
    //  Description:   Finish time of IC Part2 initiated register transfer (I2C) for right imager
    //  Range:         0-2^32
    //  Resolution:    1
    //  Unit:          us
    uint32 ui32_Part2Right;		/*## attribute ui32_Part2Right */
    //  Description:   Finish time of IC Part2 initiated register transfer (I2C) for left imager
    //  Range:         0-2^32
    //  Resolution:    1
    //  Unit:          us
    uint32 ui32_Part2Left;		/*## attribute ui32_Part2Left */
} ICRM_S_I2CFinishTimes;

//  Definition of imager register I2C transfer groups
/*#[ type ICRM_E_TransferID */
typedef enum {
    ICRM_e_TRANSFID_INIT_ASYNC,      /* Asynchronous imager initialization sequence           */
    ICRM_e_TRANSFID_EXTERNAL,        /* External register read/write request (e.g. XCP)       */
    ICRM_e_TRANSFID_PART1_R,         /* Register write access from IC PART1 (right imager)    */
    ICRM_e_TRANSFID_PART2_R,         /* Register write access from IC PART2 (right imager)    */
    ICRM_e_TRANSFID_RX_REGCHECK_R,   /* Register read access for cyclic register checks right */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICRM_e_TRANSFID_PART1_L,         /* Register write access from IC PART1 (right imager)    */
    ICRM_e_TRANSFID_PART2_L,         /* Register write access from IC PART2 (right imager)    */
    ICRM_e_TRANSFID_RX_REGCHECK_L,   /* Register read access for cyclic register checks left  */
    ICRM_e_TRANSFID_RX_ASYNC_L,      /* Asynchronous register read left imager                */
#endif
    ICRM_e_TRANSFID_OTHER            /* Any other register transfer  */
}  ICRM_E_TransferID;
/*#]*/

//  Contains register input/output buffers and data to manage them. Each imager has
//  a instance of this data structure, which is primarily used for register checks.
/*## type ICRM_S_ImagerContext */
typedef struct ICRM_S_ImagerContext {
    //  Description:   The Imager which belongs to this context structure
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_Imager e_Imager;		/*## attribute e_Imager */
    //  Description:   Array of register buffers for all registers, which are read from embedded data.
    //                 Each array element is a buffer for one specific frame-type.
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    IC_S_RegBuff aRb_RegsIn[IC_cui16_NumFrameTypes];		/*## attribute aRb_RegsIn */
    //  Description:   Current register input buffer, which contains the input register values for
    //                 the current frame(-type), extracted from embedded data.
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    IC_S_RegBuff * pRb_CurRegInBuffer;		/*## attribute pRb_CurRegInBuffer */
    //  Description:   Current register output buffer, which contains the output register values for
    //                 the current frame.
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    IC_S_RegBuff * pRb_CurRegOutBuffer;		/*## attribute pRb_CurRegOutBuffer */
    //  Description:   Pointer to array of register output/history buffers. It points to first entry
    //                 of a ringbuffer, which holds the current and past register values of the last
    //                 'ui16_RegOutBuffLen' frames for a specific imager. The number of register buffers
    //                 in the target array must be set in 'ui16_RegOutBuffLen'.
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    IC_S_RegBuff * paRb_RegOutBuffs;		/*## attribute paRb_RegOutBuffs */
    //  Description:   Stores registers which are not part of embedded data, but are read via I2C.
    //                 They are used for register checks/verification.
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    IC_S_RegDataPair as_VerifyRegsI2CRxBuff[IC_ARRLEN(ICCFG_cas_VerifyRegsI2C)];		/*## attribute as_VerifyRegsI2CRxBuff */
    //  Description:   This field of ui32 is actually a bitmap, that indicates which registers
    //                 have been set/changed until last flush. Each register has a bit assigned,
    //                 which _BIT_index maps to the register's numeric enum value.
    //  Range:         0-2^32
    //  Resolution:    none
    //  Unit:          none
    uint32 aui32_RegChangedBitmap[(IMGREG_cui16_NumImagerRegs / IC_NUMBITS_32) + 1];		/*## attribute aui32_RegChangedBitmap */
    //  Description:   Current ringbuffer array index in 'paRb_RegOutBuffs'.
    //  Range:         0 - 'ui16_RegOutBuffLen'
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_RegOutBufferIndex;		/*## attribute ui16_RegOutBufferIndex */
    //  Description:   Number of registers buffers at 'paRb_RegOutBuffs', which stores history
    //                 register values
    //  Range:         0 - ui16_RegOutBuffLen
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_RegOutBuffLen;		/*## attribute ui16_RegOutBuffLen */
    //  Description:   Marks if register checking read transfer is done for this imager
    //  Range:         (boolean)
    //  Resolution:    none
    //  Unit:          none
    boolean b_RegCheckRxDone;		/*## attribute b_RegCheckRxDone */
} ICRM_S_ImagerContext;

//  Name of this module, required for calls to ICERR_HANDLE().
//  
//  Character string is only used for debugging & recording analysis, so suppress QAC warnings:
//  PRQA S 5013,3625 3
/*## attribute pch_ModuleName */
static const char * const pch_ModuleName = "REGMGR";

//  Number of output register buffers to keep for left imager (history storage)
/*## attribute ICRM_cui16_REG_BUFFER_DEPTH_L */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
#define ICRM_cui16_REG_BUFFER_DEPTH_L 8
#endif

//  Number of output register buffers to keep for right imager (history storage)
/*## attribute ICRM_cui16_REG_BUFFER_DEPTH_R */
#define ICRM_cui16_REG_BUFFER_DEPTH_R 2

//  Frame number of last received register data from left imager (is always behind ui16_FrameNum)
/*## attribute ICRM_ui16_FramenumLeft */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
static uint16 ICRM_ui16_FramenumLeft = 0;
#endif

//  Ring-buffer storing current/history register output values for right imager. It does
//  _not_ contain registers extracted from embedded data! This is used to do register
//  checking of registers, which are delayed by the imager (e.g. frame-sync'd registers).
//  It also buffers register output values of the current cycle though.
/*## attribute ICRM_aRb_RegOutBufferR */
static IC_S_RegBuff ICRM_aRb_RegOutBufferR[ICRM_cui16_REG_BUFFER_DEPTH_R];

//  Ring-buffer storing current/history register output values for left imager. It does
//  _not_ contain registers extracted from embedded data! This is used to do register
//  checking of registers, which are delayed for several frames by the long chain:
//  
//  IC -> I2C -> Imager -> Embedded Data -> FPGA -> DSP -> IPC -> IC
//  
//  It also buffers register output values of the current cycle though.
/*## attribute ICRM_aRb_RegOutBufferL */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
static IC_S_RegBuff ICRM_aRb_RegOutBufferL[ICRM_cui16_REG_BUFFER_DEPTH_L];
#endif

//  Pointer to structure for storing measurement data
/*## attribute ICRM_ps_MeasData */
static ICRM_S_MeasData * ICRM_ps_MeasData = NULL;

//  The TX mode (sync/buffer), which defines the behavior of ICRM_v_SetRegister*().
/*## attribute ICRM_e_TxMode */
static ICRM_E_TxMode ICRM_e_TxMode = ICRM_e_TXMODE_BUFFER_TILL_FLUSHED;

//  Total number of register transfer RX/TX errors, which occurred since module initialization
/*## attribute ICRM_ui32_NumRegTransErrors */
static uint32 ICRM_ui32_NumRegTransErrors = 0;

//  Flag indicating that the very first I2C read transfer for register checking has
//  (not) been scheduled (yet)
/*## attribute ICRM_b_I2CRegCheckFirstRxDone */
static boolean ICRM_b_I2CRegCheckFirstRxDone = 0;

//  Imager, which is currently selected for executing I2C register checks
/*## attribute ICRM_e_I2CRegCheckImager */
static IC_E_Imager ICRM_e_I2CRegCheckImager = IC_e_IMAGER_RIGHT;

//  Timestamps showing when I2C transfers were finished
/*## attribute ICRM_s_I2CFinishTimes */
static ICRM_S_I2CFinishTimes ICRM_s_I2CFinishTimes;

//  Storage for imager communication statistics (runtime, I2C ISR exec count, ...)
/*## attribute ICRM_s_CommStats */
static IC_S_CommStats ICRM_s_CommStats;

//  Storage for imager communication statistics of previous frame
/*## attribute ICRM_s_CommStatsPrev */
static IC_S_CommStats ICRM_s_CommStatsPrev;

//  Statistical data, used when profiling: Cyclic buffer, which stores total ISR runtimes
//  for the last N cycles.
//  
//  PRQA S 3229,3132,3229 3
/*## attribute ICRM_aui32_ISRRuntimes */
#if (IC_PROFILING_ENABLED == 1)
static uint32 ICRM_aui32_ISRRuntimes[32];
#endif

//  Statistical data, used when profiling: Cyclic buffer, which counts interrupt service routine (ISR)
//  executions for the last N cycles.
//  
//  PRQA S 3229,3132 3
/*## attribute ICRM_aui32_ISRCounts */
#if (IC_PROFILING_ENABLED == 1)
static uint32 ICRM_aui32_ISRCounts[32];
#endif

//  Current index in statistical ICRM_aui32_ISR*[] arrays. Used only when profiling is enabled.
//  
//  PRQA S 3229,3132,3229 3
/*## attribute ICRM_ui32_StatIndex */
#if (IC_PROFILING_ENABLED == 1)
static uint32 ICRM_ui32_StatIndex = 0;
#endif

//  This set of registers will be written every frame in IC Part2, regardless whether
//  they have been modified or not.
//  
//  ATTENTION: Keep registers with adjacent addresses in-order to allow writing them
//  as a block to the imager (which is faster)!
//  
//  It's intended to define array size by number of initializers:
//  PRQA S 3674 2
/*## attribute ICRM_cae_RegistersToWritePart2 */
static const IMGREG_E_SENSOR_REG ICRM_cae_RegistersToWritePart2[] = {
    IMGREG_e_REG_AE_CTRL_REG,
    IMGREG_e_REG_OPERATION_MODE_CTRL,
    IMGREG_e_REG_COARSE_INTEGRATION_TIME,
    IMGREG_e_REG_GLOBAL_GAIN,
    IMGREG_e_REG_AE_ROI_X_START_OFFSET,
    IMGREG_e_REG_AE_ROI_Y_START_OFFSET,
    IMGREG_e_REG_AE_ROI_X_SIZE,
    IMGREG_e_REG_AE_ROI_Y_SIZE
};

//  This set of registers will only be written to the sensor if they have been modified
//  (i.e. SetRegister() has been called).
//  
//  ATTENTION: Keep registers with adjacent addresses in-order to allow writing them
//  as a block to the imager (which is faster)!
//  
//  It's intended to define array size by number of initializers:
//  PRQA S 3674 2
/*## attribute ICRM_cae_RegistersToWriteWhenChanged */
static const IMGREG_E_SENSOR_REG ICRM_cae_RegistersToWriteWhenChanged[] = {
    IMGREG_e_REG_Y_ADDR_START,
    IMGREG_e_REG_X_ADDR_START,
    IMGREG_e_REG_Y_ADDR_END,
    IMGREG_e_REG_X_ADDR_END,
    IMGREG_e_REG_AE_HIST_BEGIN_PERC,
    IMGREG_e_REG_AE_HIST_END_PERC,
    IMGREG_e_REG_TEST_PATTERN_MODE,
    IMGREG_e_REG_TEST_DATA_BLUE,
    IMGREG_e_REG_TEST_DATA_GREENB,
    IMGREG_e_REG_TEST_DATA_GREENR,
    IMGREG_e_REG_TEST_DATA_RED,
    IMGREG_e_REG_AE_LUMA_TARGET_REG,
    IMGREG_e_REG_AE_HIST_TARGET_REG,
    IMGREG_e_REG_AE_DAMP_OFFSET_REG,
    IMGREG_e_REG_AE_DAMP_GAIN_REG,
    IMGREG_e_REG_AE_DAMP_MAX_REG,
    IMGREG_e_REG_AE_MAX_EV_STEP_REG,
    IMGREG_e_REG_FRAME_LENGTH_LINES,
    IMGREG_e_REG_RESET_REGISTER,
    IMGREG_e_REG_DIGITAL_TEST,
    IMGREG_e_REG_DATAPATH_SELECT,
    IMGREG_e_REG_DIGITAL_CTRL,
    IMGREG_e_REG_STAT_FRAME_ID
};

//  Number of register which are written in IC Part 2
/*## attribute ICRM_cui16_RegistersToWritePart2Count */
static const uint16 ICRM_cui16_RegistersToWritePart2Count = IC_ARRLEN(ICRM_cae_RegistersToWritePart2);

//  Number of register write buffer entries, which limits the maximum number of
//  registers which can be written in a register transfer.
/*## attribute ICRM_cui16_RegdataBufferSize */
#define ICRM_cui16_RegdataBufferSize IC_ARRLEN(ICRM_cae_RegistersToWriteWhenChanged)

//  Buffer which stores temporary register data for register write transfers.
/*## attribute ICRM_as_RegTxBuffer */
static IC_S_RegDataPair ICRM_as_RegTxBuffer[ICRM_cui16_RegdataBufferSize];

//  Buffer which stores temporary register data read from left imager
/*## attribute ICRM_as_RegRxBufferLeft */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
static IC_S_RegDataPair ICRM_as_RegRxBufferLeft[IC_ARRLEN(ICCFG_cae_LeftImagerAsyncRead)] = { 0 };
#endif

//  Timestamp of last asynchronous register read (left imager)
/*## attribute ICRM_ui64_RegRxAsyncTimeLeft */
static uint64 ICRM_ui64_RegRxAsyncTimeLeft = 0u;

//  Stores the addresses of all left imager registers, which are requested via IPC from the DSP.
/*## attribute ICRM_aui16_LeftImagerRegisterRequestAddrs */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
static uint16 ICRM_aui16_LeftImagerRegisterRequestAddrs[IC_ARRLEN(ICCFG_cae_LeftImagerRegisterRequest)];
#endif

//  This array contains bitmasks for verifying arbitrary registers, even of registers which
//  are not contained in enum IMGREG_E_SENSOR_REG. Only bits set to '1' are verified for the
//  corresponding register address. This array can be used when verifying init-sequences which
//  are not time-critical.
//  
//  PRQA S 3674,3120 COMPARE_BITMASKS
/*## attribute ICRM_cas_CompareBitmasks */
static const ICRM_S_AddrBitmaskPair ICRM_cas_CompareBitmasks[] = {
    { 0x301A, 0xFFFD }, // RESET Register: Mask bits which are always read as '0'
    { 0x3088, 0x0000 }, // SEQ_CTRL_PORT
    { 0x3086, 0x0000 }, // SEQ_DATA_PORT
    { 0x3046, 0x0180 }  // FLASH: unmask R/O status and reserved bits
    // PRQA L:COMPARE_BITMASKS
};

//  Array of imager context data, one entry for each imager
/*## attribute ICRM_as_ImgCtx */
static ICRM_S_ImagerContext ICRM_as_ImgCtx[ICCFG_NUM_IMAGERS];

//  Context data for right imager (e.g. register buffers)
/*## attribute ICRM_ps_ImgCtxR */
static ICRM_S_ImagerContext * const ICRM_ps_ImgCtxR = &ICRM_as_ImgCtx[IC_e_IMAGER_RIGHT];

//  Context data for left imager (e.g. register buffers)
/*## attribute ICRM_ps_ImgCtxL */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
static ICRM_S_ImagerContext * const ICRM_ps_ImgCtxL = &ICRM_as_ImgCtx[IC_e_IMAGER_LEFT];
#endif

//  Container which stores external register read/write request data and state
/*## attribute ICRM_s_RegTransExternReq */
static ICRM_S_RegTransExtern ICRM_s_RegTransExternReq;

//*****************************************************************************
//  Functionname:  ICRM_e_FlushSensorRegistersSingle
//  
//  Description:
//    Flushs 'touched' registers to a specific imager. Only registers which are contained in
//    the list 'ICRM_cae_RegistersToWriteWhenChanged' are actually written to the imager. The
//    transfer mode (async or sync) can be selected via 'b_WaitDone'.
//  
//    If 'e_Imager' is set to 'IC_e_IMAGER_ALL', then both imager register buffers are flushed.
//    The order is:
//      1) All RIGHT imager registers
//      2) All LEFT  imager registers
//  
//    In case a asynchronous flush is requested, the underlaying driver calls the callback
//    function 'ICRM_v_RegTransferDone' when the transfer finished. Each imager has a separate
//    transfer-id, so the callback is executed twice if both imagers have been selected.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be initialized
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  Description:   Flushs the buffered value of a single register to the selected imager(s)
//  Range:         Specific imager or ALL
//  Resolution:    none
//  Unit:          none
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
/*## operation ICRM_e_FlushSensorRegistersSingle(const IC_E_Imager,const boolean) */
static IC_E_ERROR ICRM_e_FlushSensorRegistersSingle(const IC_E_Imager e_Imager, const boolean b_WaitDone);

//*****************************************************************************
//  Functionname:  ICRM_v_FlushSingleReg
//  
//  Description:
//    Flushs/writes the buffered register value of a specific register to the imagers.
//    The function does nothing if the register has not been 'touched' by calling
//    ICRM_v_SetRegister*().
//  
//    The transfer is synchronous, so this function will not return before the transfer
//    is completed.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//  Parameter:     const IMGREG_E_SENSOR_REG e_Reg   <In>
//  Description:   The register which will be flushed
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_FlushSingleReg(const IMGREG_E_SENSOR_REG) */
static void ICRM_v_FlushSingleReg(const IMGREG_E_SENSOR_REG e_Reg);

//*****************************************************************************
//  Functionname:  ICRM_pRb_GetRegHistoryBuffer
//  
//  Description:
//    Returns a pointer to a register output shadow buffer, which contains the imager register
//    values at frame 'N-ui16_NumFramesBack'. The values reflect the real imager HW registers,
//    which are expected to be in the imager registers in that frame.
//  
//    Note that double buffering of 'frame syncd' imager registers is not taken into account
//    here, the embedded data in frame N does not necessary reflect the output shadow buffer
//    of frame N-1 (for some registers it's N-2). Setting 'ui16_NumFramesBack' to zero returns
//    the current working buffer.
//  
//  Preconditions:
//    - This Module must be initialized
//    - At least 'ui16_NumFramesBack' frames must have passed since module init,
//      whereas ICRM_v_RotateOutputShadBuffers() has been called in each frame.
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  Description:   Specific imager, whose history buffer is retrieved
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_NumFramesBack   <In>
//  Description:   Number of frames back in history. '0' is the current (working) output buffer,
//                 '1' is from previous frame, ...
//  Range:         0 to ICRM_cui16_REG_BUFFER_DEPTH_*-1
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_S_RegBuff * 
//**************************************************************************** */
/*## operation ICRM_pRb_GetRegHistoryBuffer(const IC_E_Imager,const uint16) */
static IC_S_RegBuff * ICRM_pRb_GetRegHistoryBuffer(const IC_E_Imager e_Imager, const uint16 ui16_NumFramesBack);

//*****************************************************************************
//  Functionname:  ICRM_v_IncorporateInitSequence
//  
//  Description:
//    Copies all registers, which are contained in the passed init sequence, into the register 
//    output shadow buffers clears the 'changed' flag for that register.
//  
//  Preconditions:
//    - This Module must be initialized
//    - I2C driver must be ready
//  
//  Parameter:     const IC_S_RegDataPair * ps_InitSequence   <In>
//  Description:   Init sequence which is copied to register buffers
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint16 ui16_NumElements   <In>
//  Description:   Number of entries in 'ps_InitSequence'
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_IncorporateInitSequence(const IC_S_RegDataPair *,uint16) */
static void ICRM_v_IncorporateInitSequence(const IC_S_RegDataPair * ps_InitSequence, uint16 ui16_NumElements);

//*****************************************************************************
//  Functionname:  ICRM_v_RegTransferDone
//  
//  Description:
//    This callback is called when an asynchronous register transfer has been completed.
//    It has the following tasks:
//  
//    1) Update I2C timing data, which is used to detect problems in I2C timing
//       (e.g. register write completed too late, so imager does not use values in
//       next frame).
//    2) Mark a asynchronous read transfer as completed, which is used when cyclic
//       register checks are executed.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  Parameter:     const IC_E_RXTXERR e_RetCode   <In>
//  Description:   Result code of the register transfer
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint8 ui8_TransferId   <In>
//  Description:   The transfer identifier of the transfer, which has been finished
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_RegTransferDone(const IC_E_RXTXERR,const uint8) */
static void ICRM_v_RegTransferDone(const IC_E_RXTXERR e_RetCode, const uint8 ui8_TransferId);

//*****************************************************************************
//  Functionname:  ICRM_e_CheckLeftRegReqContainsAll
//  
//  Description:
//    Checks if all registers in a given array are contained in the left imager register
//    request list (see ICCFG_cae_LeftImagerRegisterRequest).
//  
//  Preconditions:
//    none
//  
//  Returns:
//    IC_e_ERR_OK:                All registers are contained in the request list
//    IC_e_ERR_SOURCECODE_ERROR:  _NOT_ all registers are contained in the request list
//  
//  
//  Parameter:     IC_S_CompareRegPair const  * const ps_CompRegPairs   <In>
//  Description:   List of registers to be checked
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint32 ui32_CompRegCount   <In>
//  Description:   Number of entries in 'ps_CompRegPairs'
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_CheckLeftRegReqContainsAll(IC_S_CompareRegPair const  * const,const uint32) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
static IC_E_ERROR ICRM_e_CheckLeftRegReqContainsAll(IC_S_CompareRegPair const  * const ps_CompRegPairs, const uint32 ui32_CompRegCount);
#endif

//*****************************************************************************
//  Functionname:  ICRM_e_CompareRegisters
//  
//  Description:
//    Verifies/compares two list of registers, returning first register and a bitmask of
//    all bits that differs.
//  
//  Preconditions:
//    none
//  
//  Parameter:     const IC_S_RegBuff * const pRb_Regs1   <In>
//  Description:   Pointer to Register buffer 1, which is compared to Register buffer 2
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const IC_S_RegBuff * const pRb_Regs2   <In>
//  Description:   Pointer to Register buffer 2, which is compared to Register buffer 1
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const IC_S_CompareRegPair * ps_RegsToCheck   <In>
//  Description:   List of register / bitmasks which are actually compared
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint16 ui16_NumRegs   <In>
//  Description:   Number of entries in 'ps_RegsToCheck'
//  Range:         0-0xFFFF
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     IMGREG_E_SENSOR_REG * const pe_FailedReg   <Out>
//  Description:   Sets the pointer target to the first failed / not matching register. If all checked
//                 registers are ok, the target will be set to dummy IMGREG_e_REG__NUM_ENTRIES_.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint16 * const pui16_FailedBits   <Out>
//  Description:   Sets the pointer target to the failed/not matching bits of the first failed register.
//                 If all checked registers are ok, the target will be set to 0x0000.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICRM_e_CompareRegisters(const IC_S_RegBuff * const,const IC_S_RegBuff * const,const IC_S_CompareRegPair *,uint16,IMGREG_E_SENSOR_REG * const,uint16 * const) */
static IC_E_ERROR ICRM_e_CompareRegisters(const IC_S_RegBuff * const pRb_Regs1, const IC_S_RegBuff * const pRb_Regs2, const IC_S_CompareRegPair * ps_RegsToCheck, uint16 ui16_NumRegs, IMGREG_E_SENSOR_REG * const pe_FailedReg, uint16 * const pui16_FailedBits);

//*****************************************************************************
//  Functionname:  ICRM_ui16_GetCompareRegBitmask
//  
//  Description:
//    Returns a bitmask that marks all bits of a specific register, which shall be used when
//    verifying/comparing registers.
//  
//    The 'ui16_RegValueHint' will be used to do treatement of special registers like the
//    RESET-Register: If RESET-Bit is set, the bitmask will be 0x0000, because the whole
//    imager is reset and all the other bitvalues are lost.
//  
//    NOTE: Cyclic register check uses it's own masks, which are defined in the configuration
//          lists in file 'ic_cfg_registers.c'.
//  
//  Preconditions:
//    None
//  
//  Parameter:     const uint16 ui16_RegAddr   <In>
//  Description:   Register address whose check-bitmasks will be returned
//  Range:         0x3000 - 0x31FF
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_NewRegValueHint   <In>
//  Description:   Optional: The register value, which is written before comparation.
//                 See function description for details.
//  Range:         0 - 0xFFFF
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation ICRM_ui16_GetCompareRegBitmask(const uint16,const uint16) */
static uint16 ICRM_ui16_GetCompareRegBitmask(const uint16 ui16_RegAddr, const uint16 ui16_NewRegValueHint);

//*****************************************************************************
//  Functionname:  ICRM_v_BitmapSetBit
//  
//  Description:
//    Sets a specific bit of the given bitmap.
//  
//  Preconditions:
//    None
//  
//  Parameter:     uint32 * const pui32_Bitmap   <InOut>
//  Description:   Pointer to bitmap, which is used for this operation
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint32 ui32_Bitnum   <In>
//  Description:   Bit number/index whose value will be returned
//  Range:         0 to (numBits(bitmap)-1)
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_BitmapSetBit(uint32 * const,uint32) */
static void ICRM_v_BitmapSetBit(uint32 * const pui32_Bitmap, uint32 ui32_Bitnum);

//*****************************************************************************
//  Functionname:  ICRM_v_BitmapClearBit
//  
//  Description:
//    Clears a specific bit of the given bitmap.
//  
//  Preconditions:
//    None
//  
//  Parameter:     uint32 * const pui32_Bitmap   <InOut>
//  Description:   Pointer to bitmap, which is used for this operation
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint32 ui32_Bitnum   <In>
//  Description:   Bit number/index whose value will be returned
//  Range:         0 to (numBits(bitmap)-1)
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICRM_v_BitmapClearBit(uint32 * const,uint32) */
static void ICRM_v_BitmapClearBit(uint32 * const pui32_Bitmap, uint32 ui32_Bitnum);

//*****************************************************************************
//  Functionname:  ICRM_b_BitmapGetBit
//  
//  Description:
//    Returns the value of a bit in a bitfield.
//  
//  Preconditions:
//    none
//  
//  Returns:
//    b_TRUE:  Bit is SET
//    b_FALSE: Bit is CLEARED
//  
//  Parameter:     const uint32 * const pui32_Bitmap   <In>
//  Description:   Pointer to bitmap, which is used for this operation
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint32 ui32_Bitnum   <In>
//  Description:   Bit number/index whose value will be returned
//  Range:         0 to (numBits(bitmap)-1)
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         boolean
//**************************************************************************** */
/*## operation ICRM_b_BitmapGetBit(const uint32 * const,uint32) */
static boolean ICRM_b_BitmapGetBit(const uint32 * const pui32_Bitmap, uint32 ui32_Bitnum);

/*## operation ICRM_e_Init(ICRM_S_MeasData * const) */
#pragma push
#pragma optimize_for_size on
IC_E_ERROR ICRM_e_Init(ICRM_S_MeasData * const ps_MeasDataIn) {
    /*#[ operation ICRM_e_Init(ICRM_S_MeasData * const) */
    IC_E_ERROR     e_Ret                 = IC_e_ERR_OK;
    uint16         ui16_NumRegs          = 0;
    uint32         ui32_Index            = 0;
    uint32         ui32_ImgIndex         = 0;
    uint16         ui16_RegAddr          = 0;
    IC_E_Imager    e_Imager              = IC_ce_MASTER_IMAGER;
    ICRM_S_ImagerContext *ps_Ctx         = NULL;
    
    // Some static checks
    #if((ICCFG_ENABLE_LEFT_IMAGER == 1) && (IC_REGISTER_CHECK_LEFT_ENABLED == 1))
    
    // First entry must be the frame-counter, as ICRM_e_ProcessRegisterResponse() relies on that
    if (ICCFG_cae_LeftImagerRegisterRequest[0] != IMGREG_e_REG_FRAME_COUNT)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_SOURCECODE_ERROR, 0);
      goto ERROR_EXIT;
    }
    
    // Check if all all registers, which are about to be checked in cyclic register checks,
    // are requested from the left imager
    if (ICRM_e_CheckLeftRegReqContainsAll(ICCFG_cas_VerifyRegs, IC_ARRLEN(ICCFG_cas_VerifyRegs)) != IC_e_ERR_OK)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_SOURCECODE_ERROR, 0);
      goto ERROR_EXIT;
    }                                                                                      
    if (ICRM_e_CheckLeftRegReqContainsAll(ICCFG_cas_VerifyRegsDelayed, IC_ARRLEN(ICCFG_cas_VerifyRegsDelayed)) != IC_e_ERR_OK)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_SOURCECODE_ERROR, 0);
      goto ERROR_EXIT;
    }
    #endif
    
    // Copy input
    ICRM_ps_MeasData = ps_MeasDataIn;
    
    // Initialize variables
    ICRM_ui32_NumRegTransErrors   = 0;
    ICRM_b_I2CRegCheckFirstRxDone = 0;
    ICRM_e_I2CRegCheckImager      = IC_e_IMAGER_RIGHT;
    ICRM_ui64_RegRxAsyncTimeLeft  = 0;
    
    // The following variables are intentionally _NOT_ re-initialized (only in variable definition).
    // This prevents register checks failing after re-init:
    //ICRM_ui16_LastLeftRegCheckFrame = 0;
    //ICRM_ui16_FramenumLeft          = 0;
    
    // Initialize imager context storage.
    // NOTE: CurRegInBuffer points to output buffer as long as we have not received first embedded data!
    IC_v_ZEROMEM(ICRM_as_ImgCtx);
    ICRM_as_ImgCtx[IC_e_IMAGER_RIGHT].paRb_RegOutBuffs     = ICRM_aRb_RegOutBufferR;
    ICRM_as_ImgCtx[IC_e_IMAGER_RIGHT].pRb_CurRegOutBuffer  = &(ICRM_aRb_RegOutBufferR[0]);
    ICRM_as_ImgCtx[IC_e_IMAGER_RIGHT].ui16_RegOutBuffLen   = ICRM_cui16_REG_BUFFER_DEPTH_R;
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICRM_as_ImgCtx[IC_e_IMAGER_LEFT].paRb_RegOutBuffs      = ICRM_aRb_RegOutBufferL;
    ICRM_as_ImgCtx[IC_e_IMAGER_LEFT].pRb_CurRegOutBuffer   = &ICRM_aRb_RegOutBufferL[0];
    ICRM_as_ImgCtx[IC_e_IMAGER_LEFT].ui16_RegOutBuffLen    = ICRM_cui16_REG_BUFFER_DEPTH_L;
    #endif
    
    // For all imagers ...
    for (ui32_ImgIndex = 0; ui32_ImgIndex < ICCFG_NUM_IMAGERS; ui32_ImgIndex++)
    {
      ps_Ctx = &ICRM_as_ImgCtx[ui32_ImgIndex];
      e_Imager = (IC_E_Imager)ui32_ImgIndex; // PRQA S 1482
    
      // Initialize variables
      ps_Ctx->e_Imager = e_Imager;
      ps_Ctx->pRb_CurRegInBuffer = &(ps_Ctx->aRb_RegsIn[IC_ce_MASTER_FRAMETYPE]);
    
      // Pass input register buffers to imager driver
      IMGDRV_v_SetRegisterInput (ps_Ctx->pRb_CurRegInBuffer,  e_Imager);
      IMGDRV_v_SetRegisterOutput(ps_Ctx->pRb_CurRegOutBuffer, e_Imager);
    
      // Initialize asynchronous register read buffers
      for (ui32_Index=0; ui32_Index<IC_ARRLEN(ps_Ctx->as_VerifyRegsI2CRxBuff); ui32_Index++)
      {
        ps_Ctx->as_VerifyRegsI2CRxBuff[ui32_Index].ui16_Addr = IMGREG_ui16_GetRegAddr(ICCFG_cas_VerifyRegsI2C[ui32_Index].e_Reg);
        ps_Ctx->as_VerifyRegsI2CRxBuff[ui32_Index].ui16_Data = 0x0000;
      }
    }
    
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    // Check if list of left register requests fits into the request buffer.
    // NOTE: This is a static code check and QAC will see that (when code is OK)
    //       the expression is always false. So disable QAC messages:
    // PRQA S 3356,3359,3201 4
    ui16_NumRegs = IC_ARRLEN(ICCFG_cae_LeftImagerRegisterRequest);
    if (IC_ARRLEN(ICRM_aui16_LeftImagerRegisterRequestAddrs) < ui16_NumRegs)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_REGISTER_LEFT_REQUEST_TOO_BIG, ui16_NumRegs);
      goto ERROR_EXIT;
    }
    
    // Fill request register addresses
    for (ui32_Index = 0; ui32_Index < ui16_NumRegs; ui32_Index++)
    {
      ui16_RegAddr = IMGREG_ui16_GetRegAddr(ICCFG_cae_LeftImagerRegisterRequest[ui32_Index]);
      ICRM_aui16_LeftImagerRegisterRequestAddrs[ui32_Index] = ui16_RegAddr;
    }
    
    // Setup left imager async register read data
    for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ICRM_as_RegRxBufferLeft); ui32_Index++)
    {
      ICRM_as_RegRxBufferLeft[ui32_Index].ui16_Addr = IMGREG_ui16_GetRegAddr(ICCFG_cae_LeftImagerAsyncRead[ui32_Index]);
      ICRM_as_RegRxBufferLeft[ui32_Index].ui16_Data = 0x0000;
    }
    #endif
    
    // Setup other stuff
    ICRM_ps_MeasData->s_I2CTimingRight.si16_SlackPart2Min = TYPEMAX_SI16;
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICRM_ps_MeasData->s_I2CTimingLeft.si16_SlackPart2Min  = TYPEMAX_SI16;
    #endif
    IC_v_ZEROMEM(ICRM_s_RegTransExternReq);
    
    ERROR_EXIT:
    return e_Ret;
    
    // QAC HIS matric: Num non-cyclic paths ...
    // PRQA S 7002 3
    /*#]*/
}
#pragma pop

/*## operation ICRM_v_SetRegister(const IMGREG_E_SENSOR_REG,const uint16) */
void ICRM_v_SetRegister(const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_Value) {
    /*#[ operation ICRM_v_SetRegister(const IMGREG_E_SENSOR_REG,const uint16) */
    ICRM_v_SetRegisterSingle(e_Reg, ui16_Value, IC_e_IMAGER_ALL);
    /*#]*/
}

/*## operation ICRM_v_SetRegisterSingle(const IMGREG_E_SENSOR_REG,const uint16,const IC_E_Imager) */
void ICRM_v_SetRegisterSingle(const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_Value, const IC_E_Imager e_Imager) {
    /*#[ operation ICRM_v_SetRegisterSingle(const IMGREG_E_SENSOR_REG,const uint16,const IC_E_Imager) */
    // Check if reg in range
    if (e_Reg >= IMGREG_e_REG__LAST_ENTRY_)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_REGISTER, 0);
      goto ERROR_EXIT;
    }
    
    // Update register data in shadow-array
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    if ((IC_e_IMAGER_ALL == e_Imager) || (IC_e_IMAGER_LEFT == e_Imager))
    {
      ICRM_ps_ImgCtxL->pRb_CurRegOutBuffer->aRegs[e_Reg] = ui16_Value;
      ICRM_v_BitmapSetBit(ICRM_ps_ImgCtxL->aui32_RegChangedBitmap, (uint32)e_Reg);
    }
    #endif
    if ((IC_e_IMAGER_ALL == e_Imager) || (IC_e_IMAGER_RIGHT == e_Imager))
    {
      ICRM_ps_ImgCtxR->pRb_CurRegOutBuffer->aRegs[e_Reg] = ui16_Value;
      ICRM_v_BitmapSetBit(ICRM_ps_ImgCtxR->aui32_RegChangedBitmap, (uint32)e_Reg);
    }
    
    // Directly write trough if requested
    if (ICRM_e_TXMODE_WRITEINSTANT_SYNC == ICRM_e_TxMode)
    {
      ICRM_v_FlushSingleReg(e_Reg);
    }
    
    ERROR_EXIT:
    return;
    /*#]*/
}

/*## operation ICRM_e_SensorRegRXSingle(const IC_E_Imager,const uint16,uint16 * const) */
IC_E_ERROR ICRM_e_SensorRegRXSingle(const IC_E_Imager e_SensorId, const uint16 ui16_RegAddr, uint16 * const pui16_RegValue) {
    /*#[ operation ICRM_e_SensorRegRXSingle(const IC_E_Imager,const uint16,uint16 * const) */
    IC_E_ERROR e_Ret;
    IC_S_RegDataPair s_AddrDat;
    
    // Check for sensor id
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    if ((e_SensorId != IC_e_IMAGER_RIGHT) && (e_SensorId != IC_e_IMAGER_LEFT))
    #else
    if ((e_SensorId != IC_e_IMAGER_RIGHT))
    #endif
    {
      e_Ret = IC_e_ERR_ILLEGAL_SENSORNUM;
      goto ERROR_EXIT;
    }
    
    // Setup and execute single transfer
    s_AddrDat.ui16_Addr = ui16_RegAddr;
    e_Ret = ICOSW_e_RegTransfer(e_SensorId, &s_AddrDat, 1, IC_e_TRANSFMODE_RX, NULL, (uint8)ICRM_e_TRANSFID_OTHER);
    *pui16_RegValue = s_AddrDat.ui16_Data;
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_e_SensorRegTXSingle(const IC_E_Imager,const uint16,const uint16,const uint16) */
IC_E_ERROR ICRM_e_SensorRegTXSingle(const IC_E_Imager e_SensorId, const uint16 ui16_RegAddr, const uint16 ui16_RegValue, const uint16 ui16_VerifyBitmask) {
    /*#[ operation ICRM_e_SensorRegTXSingle(const IC_E_Imager,const uint16,const uint16,const uint16) */
    IC_E_ERROR e_Ret;
    IC_S_RegDataPair s_AddrDat;
    uint16 ui16_RegValueRX = ~ui16_RegValue; // To assure that RX is really executed
    uint16 ui16_FailedBits;
    uint32 ui32_OptData;
    
    // Setup and execute single transfer
    s_AddrDat.ui16_Addr = ui16_RegAddr;
    s_AddrDat.ui16_Data = ui16_RegValue;
    e_Ret = ICOSW_e_RegTransfer(e_SensorId, &s_AddrDat, 1, IC_e_TRANSFMODE_TX, NULL, (uint8)ICRM_e_TRANSFID_OTHER);
    
    // If result is OK and check is requested, do it now
    if ((IC_e_ERR_OK == e_Ret) && (0x0000 != ui16_VerifyBitmask) && (ui16_RegAddr != IC_cui16_SPECIALADDR_DELAY))
    {
      if ((IC_e_IMAGER_ALL == e_SensorId) || (IC_e_IMAGER_RIGHT == e_SensorId))
      {
        e_Ret = ICRM_e_SensorRegRXSingle(IC_e_IMAGER_RIGHT, ui16_RegAddr, &ui16_RegValueRX);
        ui16_FailedBits = (ui16_RegValue ^ ui16_RegValueRX) & ui16_VerifyBitmask;
        ui32_OptData = (((uint32)ui16_RegAddr) << IC_NUMBITS_16) | ((uint32)ui16_FailedBits);
        if ((IC_e_ERR_OK == e_Ret) && (ui16_FailedBits != 0x0000))
        {
          e_Ret = ICERR_HANDLE(IC_e_ERR_REGTX_VERIFY_FAILED_R, ui32_OptData);
        }
      }
    
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
      if ((IC_e_IMAGER_ALL == e_SensorId) || (IC_e_IMAGER_LEFT == e_SensorId))
      {
        e_Ret = ICRM_e_SensorRegRXSingle(IC_e_IMAGER_LEFT, ui16_RegAddr, &ui16_RegValueRX);
        ui16_FailedBits = (ui16_RegValue ^ ui16_RegValueRX) & ui16_VerifyBitmask;
        ui32_OptData = (((uint32)ui16_RegAddr) << IC_NUMBITS_16) | ((uint32)ui16_FailedBits);
        if ((IC_e_ERR_OK == e_Ret) && (ui16_FailedBits != 0x0000))
        {
          e_Ret = ICERR_HANDLE(IC_e_ERR_REGTX_VERIFY_FAILED_L, ui32_OptData);
        }
      }
    #endif
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_e_ReadInitialRegisters() */
IC_E_ERROR ICRM_e_ReadInitialRegisters(void) {
    /*#[ operation ICRM_e_ReadInitialRegisters() */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    e_Ret = ICRM_e_ReadRegsViaI2C(ICCFG_cae_InitialRegsReadI2C, IC_ARRLEN(ICCFG_cae_InitialRegsReadI2C), IC_ce_MASTER_FRAMETYPE);
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_e_ReadRegsViaI2C(const IMGREG_E_SENSOR_REG * const,const uint16,const IC_E_FRAMETYPE) */
#pragma push
#pragma optimize_for_size on
IC_E_ERROR ICRM_e_ReadRegsViaI2C(const IMGREG_E_SENSOR_REG * const pe_Regs, const uint16 ui16_NumRegs, const IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation ICRM_e_ReadRegsViaI2C(const IMGREG_E_SENSOR_REG * const,const uint16,const IC_E_FRAMETYPE) */
    IC_E_ERROR     e_Ret                 = IC_e_ERR_OK;
    IC_E_ERROR     e_SubRet              = IC_e_ERR_OK;
    IMGREG_E_SENSOR_REG e_Reg            = IMGREG_e_REG__LAST_ENTRY_;
    uint16         ui16_RegVal           = 0;
    uint16         ui16_RegAddr          = 0;
    uint16         ui16_Index            = 0;
    
    // Read the given list of registers from the sensor via I2C
    for (ui16_Index = 0; ui16_Index < ui16_NumRegs; ui16_Index++)
    {
      // Access of array within bounds is ensured by using 'ui16_NumRegs', so suppress QAC warning:
      // PRQA S 0492 1
      e_Reg = pe_Regs[ui16_Index];
    
      // Check if register exists
      if (e_Reg >= IMGREG_e_REG__LAST_ENTRY_)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_ILLEGAL_REGISTER, e_Reg);
        goto ERROR_EXIT;
      }
      else
      {
        // Get register address
        ui16_RegAddr = IMGREG_ui16_GetRegAddr(e_Reg);
    
        // Right
        e_SubRet = ICRM_e_SensorRegRXSingle(IC_e_IMAGER_RIGHT, ui16_RegAddr, &ui16_RegVal);
        if (e_SubRet != IC_e_ERR_OK)
        {
          e_Ret = ICERR_HANDLE(e_SubRet, 0);
          goto ERROR_EXIT;
        }
        ICRM_ps_ImgCtxR->pRb_CurRegOutBuffer->aRegs[e_Reg]    = ui16_RegVal;
        ICRM_ps_ImgCtxR->aRb_RegsIn[e_FrameType].aRegs[e_Reg] = ui16_RegVal;
    
        // Left
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
        e_SubRet = ICRM_e_SensorRegRXSingle(IC_e_IMAGER_LEFT, ui16_RegAddr, &ui16_RegVal);
        if (e_SubRet != IC_e_ERR_OK)
        {
          e_Ret = ICERR_HANDLE(e_SubRet, 0);
          goto ERROR_EXIT;
        }
        ICRM_ps_ImgCtxL->pRb_CurRegOutBuffer->aRegs[e_Reg]    = ui16_RegVal;
        ICRM_ps_ImgCtxL->aRb_RegsIn[e_FrameType].aRegs[e_Reg] = ui16_RegVal;
    #endif
      }
    }
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}
#pragma pop

/*## operation ICRM_e_SendInitSequence(const IC_S_RegDataPair * const,const uint16) */
#pragma push
#pragma optimize_for_size on
IC_E_ERROR ICRM_e_SendInitSequence(const IC_S_RegDataPair * const ps_RegDataBuffer, const uint16 ui16_NumElements) {
    /*#[ operation ICRM_e_SendInitSequence(const IC_S_RegDataPair * const,const uint16) */
    IC_E_ERROR e_SubRet        = IC_e_ERR_OK;
    IC_E_ERROR e_Ret           = IC_e_ERR_OK;
    uint32 ui32_Index          = 0;
    uint32 ui32_Index2         = 0;
    uint16 ui16_RegAddr        = 0x0000;
    uint16 ui16_RegValTX       = 0x0000;
    uint16 ui16_RegValRX       = 0x0000;
    uint16 ui16_VerifyBitmask  = IC_BITSALLONE_U16;
    
    // Send init-sequence to imager
    for (ui32_Index = 0; (ui32_Index < ui16_NumElements); ui32_Index++)
    {
      ui16_RegAddr    = ps_RegDataBuffer[ui32_Index].ui16_Addr; // PRQA S 0492
      ui16_RegValTX   = ps_RegDataBuffer[ui32_Index].ui16_Data; // PRQA S 0492
    
      // Transfer register and verify.
      ui16_VerifyBitmask = ICRM_ui16_GetCompareRegBitmask(ui16_RegAddr, ui16_RegValTX);
      e_SubRet = ICRM_e_SensorRegTXSingle(IC_e_IMAGER_ALL, ui16_RegAddr, ui16_RegValTX, ui16_VerifyBitmask);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_REGTX, ui16_RegAddr);
        goto ERROR_EXIT;
      }
    }
    
    // Now read back registers and compare against init-sequence. As some registers are written more
    // than one time with different values, we have to traverse the full register-sequence for each
    // register and use the last written value for comparation. This is not very efficient but
    // should be feasible here. (Alternative: Traverse backwards and use bitfield to track already
    // "seen" registers)
    for (ui32_Index = 0; (ui32_Index < ui16_NumElements) && (IC_e_ERR_OK == e_SubRet); ui32_Index++)
    {
      ui16_RegAddr = ps_RegDataBuffer[ui32_Index].ui16_Addr; // PRQA S 0492
      ui16_VerifyBitmask = ICRM_ui16_GetCompareRegBitmask(ui16_RegAddr, ui16_RegValTX);
    
      // Verify register if it's not a delay value and we have a non-zero bitmask
      if ((ui16_RegAddr != IC_cui16_SPECIALADDR_DELAY) && (ui16_VerifyBitmask != 0x0000))
      {
        // Find last written value for this register
        for (ui32_Index2 = ui32_Index; (ui32_Index2 < ui16_NumElements); ui32_Index2++)
        {
          if (ui16_RegAddr == ps_RegDataBuffer[ui32_Index2].ui16_Addr) // PRQA S 0492
          {
            ui16_RegValTX = ps_RegDataBuffer[ui32_Index2].ui16_Data; // PRQA S 0492
          }
        }
    
        // Read back register from right imager
        e_SubRet = ICRM_e_SensorRegRXSingle(IC_e_IMAGER_RIGHT, ui16_RegAddr, &ui16_RegValRX);
        if (IC_e_ERR_OK != e_SubRet)
        {
          e_Ret = ICERR_HANDLE(IC_e_ERR_REGRX, ui16_RegAddr);
          goto ERROR_EXIT;
        }
    
        // Verify value
        if (((ui16_RegValTX ^ ui16_RegValRX) & ui16_VerifyBitmask) != 0x0000)
        {
          e_Ret = ICERR_HANDLE(IC_e_ERR_INITSEQ_VERIFY, ui16_RegAddr);
          goto ERROR_EXIT;
        }
    
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
        // Read back register from left imager
        e_SubRet = ICRM_e_SensorRegRXSingle(IC_e_IMAGER_LEFT, ui16_RegAddr, &ui16_RegValRX);
        if (IC_e_ERR_OK != e_SubRet)
        {
          e_Ret = ICERR_HANDLE(IC_e_ERR_REGRX, ui16_RegAddr);
          goto ERROR_EXIT;
        }
    
        // Verify value
        if (((ui16_RegValTX ^ ui16_RegValRX) & ui16_VerifyBitmask) != 0x0000)
        {
          e_Ret = ICERR_HANDLE(IC_e_ERR_INITSEQ_VERIFY, ui16_RegAddr);
          goto ERROR_EXIT;
        }
    #endif
      }
    }
    
    // Finally copy all written register values to our output buffer (used for register checks etc.)
    ICRM_v_IncorporateInitSequence(ps_RegDataBuffer, ui16_NumElements);
    
    ERROR_EXIT:
    return e_Ret;
    
    // QAC HIS matric: Num non-cyclic paths ...
    // PRQA S 7002 3
    /*#]*/
}
#pragma pop

/*## operation ICRM_e_SendInitSequenceAsync(const IC_S_RegDataPair * const,const uint16) */
IC_E_ERROR ICRM_e_SendInitSequenceAsync(const IC_S_RegDataPair * const ps_RegDataBuffer, const uint16 ui16_NumElements) {
    /*#[ operation ICRM_e_SendInitSequenceAsync(const IC_S_RegDataPair * const,const uint16) */
    IC_E_ERROR e_SubRet = IC_e_ERR_OK;
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // Transfer buffer to imagers.
    //
    // NOTE: TX transfers do not modify transfer buffers, so casting 'const' away is okay here:
    // PRQA S 0311 3
    e_SubRet = ICOSW_e_RegTransfer(
            IC_e_IMAGER_ALL,
            (IC_S_RegDataPair*)ps_RegDataBuffer,
            ui16_NumElements,
            IC_e_TRANSFMODE_TX,
            &ICRM_v_RegTransferDone,
            (uint8)ICRM_e_TRANSFID_INIT_ASYNC);
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_REGTX, e_SubRet);
      goto ERROR_EXIT;
    }
    
    // TODO: Queue async register read for later verification
    
    // Copy init-sequence to output-buffers to prevent register checks from failing
    ICRM_v_IncorporateInitSequence(ps_RegDataBuffer, ui16_NumElements);
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_e_GetBuffersWritePart2(const IC_E_Imager,IC_S_RegDataPair const * * const,uint16 * const) */
IC_E_ERROR ICRM_e_GetBuffersWritePart2(const IC_E_Imager e_Imager, IC_S_RegDataPair const * * const pps_AddrDataPairs, uint16 * const pui16_NumElements) {
    /*#[ operation ICRM_e_GetBuffersWritePart2(const IC_E_Imager,IC_S_RegDataPair const * * const,uint16 * const) */
    uint16 ui16_Index;
    IMGREG_E_SENSOR_REG e_Reg;
    IC_S_RegBuff *pRb_Registers;
    uint32 *pui32_RegChangedBitmap;
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // Check imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
      goto ERROR_EXIT;
    }
    
    // Get imager context data
    pRb_Registers          = ICRM_as_ImgCtx[e_Imager].pRb_CurRegOutBuffer;
    pui32_RegChangedBitmap = ICRM_as_ImgCtx[e_Imager].aui32_RegChangedBitmap;
    
    // Signal error if buffer too small
    if (ICRM_cui16_RegistersToWritePart2Count > IC_ARRLEN(ICRM_as_RegTxBuffer))
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_BUFFER_OVERRUN, ICRM_cui16_RegistersToWritePart2Count);
      goto ERROR_EXIT;
    }
    
    // Copy register addr+content into working-buffer and tell caller number of elements
    for (ui16_Index = 0; ui16_Index < ICRM_cui16_RegistersToWritePart2Count; ui16_Index++)
    {
      e_Reg = ICRM_cae_RegistersToWritePart2[ui16_Index];
      ICRM_as_RegTxBuffer[ui16_Index].ui16_Addr = IMGREG_ui16_GetRegAddr(e_Reg);
      ICRM_as_RegTxBuffer[ui16_Index].ui16_Data = pRb_Registers->aRegs[e_Reg];
      ICRM_v_BitmapClearBit(pui32_RegChangedBitmap, (uint32)e_Reg);
    }
    *pui16_NumElements = ICRM_cui16_RegistersToWritePart2Count;
    *pps_AddrDataPairs = ICRM_as_RegTxBuffer;
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_e_GetBuffersWriteWhenChanged(const IC_E_Imager,IC_S_RegDataPair const * * const,uint16 * const) */
IC_E_ERROR ICRM_e_GetBuffersWriteWhenChanged(const IC_E_Imager e_Imager, IC_S_RegDataPair const * * const pps_AddrDataPairs, uint16 * const pui16_NumElements) {
    /*#[ operation ICRM_e_GetBuffersWriteWhenChanged(const IC_E_Imager,IC_S_RegDataPair const * * const,uint16 * const) */
    uint16 ui16_SrcIndex;
    uint16 ui16_DstIndex;
    IMGREG_E_SENSOR_REG e_Reg;
    IC_S_RegBuff *pRb_Registers;
    uint32 *pui32_RegChangedBitmap;
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // Check imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
      goto ERROR_EXIT;
    }
    
    // Get imager context data
    pRb_Registers          = ICRM_as_ImgCtx[e_Imager].pRb_CurRegOutBuffer;
    pui32_RegChangedBitmap = ICRM_as_ImgCtx[e_Imager].aui32_RegChangedBitmap;
    
    // Signal error if buffer may be too small
    if (IC_ARRLEN(ICRM_cae_RegistersToWriteWhenChanged) > IC_ARRLEN(ICRM_as_RegTxBuffer))
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_BUFFER_OVERRUN, 0);
      goto ERROR_EXIT;
    }
    
    // Copy register addr+content into working-buffer if changed and tell caller number of elements
    ui16_DstIndex = 0;
    for (ui16_SrcIndex = 0; ui16_SrcIndex < IC_ARRLEN(ICRM_cae_RegistersToWriteWhenChanged); ui16_SrcIndex++)
    {
      e_Reg = ICRM_cae_RegistersToWriteWhenChanged[ui16_SrcIndex];
      if (b_TRUE == ICRM_b_BitmapGetBit(pui32_RegChangedBitmap, (uint32)e_Reg))
      {
        ICRM_as_RegTxBuffer[ui16_DstIndex].ui16_Addr = IMGREG_ui16_GetRegAddr(e_Reg);
        ICRM_as_RegTxBuffer[ui16_DstIndex].ui16_Data = pRb_Registers->aRegs[e_Reg];
        ICRM_v_BitmapClearBit(pui32_RegChangedBitmap, (uint32)e_Reg);
        ui16_DstIndex++;
      }
    }
    
    // Set output
    *pui16_NumElements = ui16_DstIndex;
    *pps_AddrDataPairs = ICRM_as_RegTxBuffer;
    
    // SPECIAL HANDLING FOR RESET-REGISTER: Reset bits to zero which are used to trigger
    // certain events on the imager and are always read back as '0', e.g.:
    //   - reset_register_restart
    //   - reset_register_reset
    //
    // PRQA S 0277 1
    pRb_Registers->aRegs[IMGREG_e_REG_RESET_REGISTER] &= (uint16)(~(  IMGREG_cui16_BITMASK_RESET_REGISTER_RESET
                                                                    | IMGREG_cui16_BITMASK_RESET_REGISTER_RESTART));
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_e_FlushSensorRegisters(const boolean) */
IC_E_ERROR ICRM_e_FlushSensorRegisters(const boolean b_WaitDone) {
    /*#[ operation ICRM_e_FlushSensorRegisters(const boolean) */
    return ICRM_e_FlushSensorRegistersSingle(IC_e_IMAGER_ALL, b_WaitDone);
    /*#]*/
}

/*## operation ICRM_e_FlushSensorRegistersSingle(const IC_E_Imager,const boolean) */
static IC_E_ERROR ICRM_e_FlushSensorRegistersSingle(const IC_E_Imager e_Imager, const boolean b_WaitDone) {
    /*#[ operation ICRM_e_FlushSensorRegistersSingle(const IC_E_Imager,const boolean) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    IC_E_ERROR e_SubRet = IC_e_ERR_OK;
    IC_S_RegDataPair const *ps_RegDataBuffer;
    ICRM_E_TransferID e_TransferId;
    uint16 ui16_NumElements = 0;
    IC_Fct_TransfCallback pfct_TransfCallback = NULL;
    
    // If both specified, then call this method twice with L/R as parameters
    if (IC_e_IMAGER_ALL == e_Imager)
    {
      // Flush registers for right imager
      e_Ret = ICRM_e_FlushSensorRegistersSingle(IC_e_IMAGER_RIGHT, b_WaitDone); // PRQA S 3670
      if (e_Ret != IC_e_ERR_OK)
      {
        goto ERROR_EXIT;
      }
    
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
      // ATTENTION: With the ImageSync feature (which has +-25 lines at moment of writing) the
      // left imager may not have completed the previous frame when registers are flushed from
      // ICA_e_ExecEmbRegComplete(). To avoid crossing the frame-boundary when writing registers
      // to the left imager, which would cause wrong frame-sizes etc. in the left imager, they
      // MUST be flushed AFTER the registers of the right imager!
      e_Ret = ICRM_e_FlushSensorRegistersSingle(IC_e_IMAGER_LEFT, b_WaitDone); // PRQA S 3670
      if (e_Ret != IC_e_ERR_OK)
      {
        goto ERROR_EXIT;
      }
    #endif
    }
    else
    {
    
      // Get changed registers from sensor-driver
      e_SubRet = ICRM_e_GetBuffersWriteWhenChanged(e_Imager, &ps_RegDataBuffer, &ui16_NumElements);
      if (ui16_NumElements > 0)
      {
        // Set callback on asynchronous transfers, else provide nullpointer
        if (b_FALSE == b_WaitDone)
        {
          pfct_TransfCallback = &ICRM_v_RegTransferDone;
        }
        else
        {
          pfct_TransfCallback = NULL;
        }
    
        // Determine transfer ID and start profiling
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
        if (IC_e_IMAGER_LEFT == e_Imager)
        {
          e_TransferId = ICRM_e_TRANSFID_PART1_L;
        }
        else
    #endif
        {
          e_TransferId = ICRM_e_TRANSFID_PART1_R;
          IC_PROFILE_START(IC_e_PROFSECT_I2C_DURATION_P1);
        }
    
        // Write registers to imager
        e_SubRet = ICOSW_e_RegTransfer(
                e_Imager,                            /* Target imager                */
                // Const castaway possible on TX:
                (IC_S_RegDataPair*)ps_RegDataBuffer, /* Register buffer              */
                ui16_NumElements,                    /* Number of registers          */
                IC_e_TRANSFMODE_TX,                  /* Transfer mode: TX            */
                pfct_TransfCallback,                 /* Transfer completion callback */
                (uint8)e_TransferId                  /* Transfer ID number           */
                );
        if (IC_e_ERR_OK != e_SubRet)
        {
          e_Ret = ICERR_HANDLE(e_SubRet, 0);
          goto ERROR_EXIT;
        }
      }
    }
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_v_FlushSingleReg(const IMGREG_E_SENSOR_REG) */
#pragma push
#pragma optimize_for_size on
static void ICRM_v_FlushSingleReg(const IMGREG_E_SENSOR_REG e_Reg) {
    /*#[ operation ICRM_v_FlushSingleReg(const IMGREG_E_SENSOR_REG) */
    IC_E_ERROR e_Ret        = IC_e_ERR_OK;
    uint16     ui16_RegAddr = 0x0000;
    uint16     ui16_Value   = 0x0000;
    uint16     ui16_ImgIdx  = 0;
    ICRM_S_ImagerContext *ps_Ctx;
    
    // For all imagers ...
    for (ui16_ImgIdx = 0; ui16_ImgIdx < ICCFG_NUM_IMAGERS; ui16_ImgIdx++)
    {
      ps_Ctx = &ICRM_as_ImgCtx[ui16_ImgIdx];
    
      // Write if register has been changed
      if (b_TRUE == ICRM_b_BitmapGetBit(ps_Ctx->aui32_RegChangedBitmap, (uint32)e_Reg))
      {
        ui16_RegAddr = IMGREG_ui16_GetRegAddr(e_Reg);
        ui16_Value = ps_Ctx->pRb_CurRegOutBuffer->aRegs[e_Reg];
        e_Ret = ICRM_e_SensorRegTXSingle(ps_Ctx->e_Imager, ui16_RegAddr, ui16_Value, 0x0000);
        if (IC_e_ERR_OK != e_Ret)
        {
          ICRM_ui32_NumRegTransErrors++;
          (void)ICERR_HANDLE(e_Ret, 0);
          (void)ICERR_HANDLE(IC_e_ERR_REGTX, ps_Ctx->e_Imager);
        }
        else
        {
          ICRM_v_BitmapClearBit(ps_Ctx->aui32_RegChangedBitmap, (uint32)e_Reg);
        }
      }
    }
    /*#]*/
}
#pragma pop

/*## operation ICRM_e_WriteRegistersPart1() */
IC_E_ERROR ICRM_e_WriteRegistersPart1(void) {
    /*#[ operation ICRM_e_WriteRegistersPart1() */
    // Just call register flush function
    return ICRM_e_FlushSensorRegisters(b_FALSE);
    /*#]*/
}

/*## operation ICRM_e_WriteRegistersPart2() */
IC_E_ERROR ICRM_e_WriteRegistersPart2(void) {
    /*#[ operation ICRM_e_WriteRegistersPart2() */
    IC_E_ERROR  e_Ret    = IC_e_ERR_OK;
    IC_E_ERROR  e_SubRet = IC_e_ERR_OK;
    IC_S_RegDataPair const *ps_RegTxBuffer = NULL;
    uint16      ui16_RegTxElements   = 0;
                                                                            
    // Write Part2-data LEFT.
    // !! IMPORTANT: The LEFT imager registers must be written as fast as possible (therefore before the RIGHT)!
    //               The reason for this is the imager resynchonisation. If the left imager is timed to start
    //               several lines before the right, its rising edge comes also earlier than that of the right one.
    //               As this method is run after the falling edge of the RIGHT imager and all registers have
    //               to be written before the next rising edge, the LEFT is more time critical.
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    e_SubRet = ICRM_e_GetBuffersWritePart2(IC_e_IMAGER_LEFT, &ps_RegTxBuffer, &ui16_RegTxElements);
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = IC_e_ERR_IMGDRV_GETBUFFERS;
      goto ERROR_EXIT;
    }
    IC_PROFILE_START(IC_e_PROFSECT_I2C_DURATION_P2);  /* Profile total I2C runtime */ // PRQA S 3138,3141,3109
    e_SubRet = ICOSW_e_RegTransfer(
            IC_e_IMAGER_LEFT,
            (IC_S_RegDataPair*)ps_RegTxBuffer, /* Const castaway OK on TX */
            ui16_RegTxElements,
            IC_e_TRANSFMODE_TX,
            &ICRM_v_RegTransferDone,
            (uint8)ICRM_e_TRANSFID_PART2_L);
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = ICERR_HANDLE(e_SubRet, 0);
      goto ERROR_EXIT;
    }
    #endif
    
    // Write Part2-data RIGHT
    // !! IMPORTANT: Writing the trailing AE_ROI_* registers to the imagers must be finished
    //               at least after the output of the dark-rows of the next image is finished.
    //               Otherwise the statistics data (histogram) may be completely screwed up!
    e_SubRet = ICRM_e_GetBuffersWritePart2(IC_e_IMAGER_RIGHT, &ps_RegTxBuffer, &ui16_RegTxElements);
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = IC_e_ERR_IMGDRV_GETBUFFERS;
      goto ERROR_EXIT;
    }
    e_SubRet = ICOSW_e_RegTransfer(
            IC_e_IMAGER_RIGHT,
            (IC_S_RegDataPair*)ps_RegTxBuffer, /* Const castaway OK on TX */
            ui16_RegTxElements,
            IC_e_TRANSFMODE_TX,
            &ICRM_v_RegTransferDone,
            (uint8)ICRM_e_TRANSFID_PART2_R);
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = ICERR_HANDLE(e_SubRet, 0);
      goto ERROR_EXIT;
    }
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_v_RotateOutputShadBuffers() */
void ICRM_v_RotateOutputShadBuffers(void) {
    /*#[ operation ICRM_v_RotateOutputShadBuffers() */
    // NOTE: The function works on pointers in structure members of 'ICRM_as_ImgCtx',
    //       which are setup'd in ICRM_e_Init(). See there to get an understanding
    //       where the pointers are pointing to.
    
    uint32 ui32_Idx = 0;
    uint16 ui16_OldRegOutBuffIdx = 0;
    ICRM_S_ImagerContext *ps_Ctx;
    
    // Array subscription to pointer type can not be omitted here:
    // PRQA S 0491 ROT_OUTPUT_BUFFS
    
    // For all imagers ...
    for (ui32_Idx = 0; ui32_Idx < ICCFG_NUM_IMAGERS; ui32_Idx++)
    {
      ps_Ctx = &ICRM_as_ImgCtx[ui32_Idx];
    
      // Move buffers to next index (with wrap-around)
      ui16_OldRegOutBuffIdx = ps_Ctx->ui16_RegOutBufferIndex;
      ps_Ctx->ui16_RegOutBufferIndex++;
      if (ps_Ctx->ui16_RegOutBufferIndex >= ps_Ctx->ui16_RegOutBuffLen)
      {
        ps_Ctx->ui16_RegOutBufferIndex = 0;
      }
      ps_Ctx->pRb_CurRegOutBuffer = &(ps_Ctx->paRb_RegOutBuffs[ps_Ctx->ui16_RegOutBufferIndex]);
    
      // Copy contents from last buffer to current and give to sensor driver
      (void)memcpy(
              ps_Ctx->paRb_RegOutBuffs[ps_Ctx->ui16_RegOutBufferIndex].aRegs,
              ps_Ctx->paRb_RegOutBuffs[ui16_OldRegOutBuffIdx].aRegs,
              (uint32)sizeof(ps_Ctx->paRb_RegOutBuffs[0].aRegs));
      IMGDRV_v_SetRegisterOutput(ps_Ctx->pRb_CurRegOutBuffer, ps_Ctx->e_Imager);
    }
    
    // PRQA L:ROT_OUTPUT_BUFFS
    /*#]*/
}

/*## operation ICRM_v_CheckRegisters(const IC_E_FRAMETYPE) */
void ICRM_v_CheckRegisters(const IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation ICRM_v_CheckRegisters(const IC_E_FRAMETYPE) */
    IC_E_ERROR          e_Ret                 = IC_e_ERR_OK;
    IC_E_ERROR          e_SubRet              = IC_e_ERR_OK;
    IMGREG_E_SENSOR_REG e_FailedReg           = IMGREG_e_REG__LAST_ENTRY_;
    uint16              ui16_FailedRegAddr    = 0;
    uint16              ui16_FailedBits       = 0;
    IC_S_RegBuff       *pRb_RegHistBuff       = NULL;
    uint32              ui32_OptData          = 0;
    
    // Check registers that are not frame-sync'd (e.g. valid in next frame).
    // Get current working buffer from "history":
    pRb_RegHistBuff = ICRM_pRb_GetRegHistoryBuffer(IC_e_IMAGER_RIGHT, 0);
    e_SubRet = ICRM_e_CompareRegisters(
            &(ICRM_ps_ImgCtxR->aRb_RegsIn[e_FrameType]),
            pRb_RegHistBuff,
            ICCFG_cas_VerifyRegs,
            IC_ARRLEN(ICCFG_cas_VerifyRegs),
            &e_FailedReg,
            &ui16_FailedBits);
    if (IC_e_ERR_OK != e_SubRet)
    {
      ui16_FailedRegAddr = IMGREG_ui16_GetRegAddr(e_FailedReg);
      ui32_OptData = (uint32)ui16_FailedRegAddr | ((uint32)ui16_FailedBits << IC_NUMBITS_16);
      ICRM_ps_MeasData->ui16_CheckFailedRegisterAddrRight = ui16_FailedRegAddr;
      ICERR_v_DemFailed(IC_e_DEM_REGCHECK_FAILED_R, ui32_OptData);
      e_Ret = ICERR_HANDLE(IC_e_ERR_CHECK_REGISTERS_R, ui32_OptData);
    }
    
    // Check registers that are frame-sync'd (e.g. valid two frames later).
    // Go two buffers back in the past:
    pRb_RegHistBuff = ICRM_pRb_GetRegHistoryBuffer(IC_e_IMAGER_RIGHT, 1);
    e_SubRet = ICRM_e_CompareRegisters(
            &(ICRM_ps_ImgCtxR->aRb_RegsIn[e_FrameType]),
            pRb_RegHistBuff,
            ICCFG_cas_VerifyRegsDelayed,
            IC_ARRLEN(ICCFG_cas_VerifyRegsDelayed),
            &e_FailedReg,
            &ui16_FailedBits);
    if (IC_e_ERR_OK != e_SubRet)
    {
      ui16_FailedRegAddr = IMGREG_ui16_GetRegAddr(e_FailedReg);
      ui32_OptData = (uint32)ui16_FailedRegAddr | ((uint32)ui16_FailedBits << IC_NUMBITS_16);
      ICRM_ps_MeasData->ui16_CheckFailedRegisterAddrRight = ui16_FailedRegAddr;
      ICERR_v_DemFailed(IC_e_DEM_REGCHECK_FAILED_R, ui32_OptData);
      e_Ret = ICERR_HANDLE(IC_e_ERR_CHECK_REGISTERS_R_FSYNCED, ui32_OptData);
    }
    
    // Signal passed of no error for right
    if (IC_e_ERR_OK == e_Ret)
    {
      ICERR_v_DemPassed(IC_e_DEM_REGCHECK_FAILED_R);
    }
    /*#]*/
}

/*## operation ICRM_v_CheckRegistersLeft(const uint16) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICRM_v_CheckRegistersLeft(const uint16 ui16_FrameNumRight) {
    /*#[ operation ICRM_v_CheckRegistersLeft(const uint16) */
    IC_E_ERROR          e_RetLeft             = IC_e_ERR_OK;
    IC_E_ERROR          e_SubRet              = IC_e_ERR_OK;
    IMGREG_E_SENSOR_REG e_FailedReg           = IMGREG_e_REG__LAST_ENTRY_;
    uint16              ui16_FailedRegAddr    = 0;
    uint16              ui16_FailedBits       = 0;
    uint16              ui16_LeftRegistersLag = 0;
    IC_S_RegBuff       *pRb_RegHistBuff       = NULL;
    IC_S_RegBuff       *pRb_RegBuffIn         = NULL;
    uint32              ui32_OptData          = 0;
    
    // Get register input buffer master frame type (DSP only receives odd/master frames)
    pRb_RegBuffIn = &(ICRM_ps_ImgCtxL->aRb_RegsIn[IC_ce_MASTER_FRAMETYPE]);
    
    // Determine time-lag of left register set
    ui16_LeftRegistersLag = ui16_FrameNumRight - ICRM_ui16_FramenumLeft;
    
    // Check registers that are not frame-sync'd (e.g. valid in next frame)
    pRb_RegHistBuff = ICRM_pRb_GetRegHistoryBuffer(IC_e_IMAGER_LEFT, ui16_LeftRegistersLag);
    if (0 != pRb_RegHistBuff)
    {
      e_SubRet = ICRM_e_CompareRegisters(
              pRb_RegBuffIn,
              pRb_RegHistBuff,
              ICCFG_cas_VerifyRegs,
              IC_ARRLEN(ICCFG_cas_VerifyRegs),
              &e_FailedReg,
              &ui16_FailedBits);
      if (IC_e_ERR_OK != e_SubRet)
      {
        ui16_FailedRegAddr = IMGREG_ui16_GetRegAddr(e_FailedReg);
        ui32_OptData = (uint32)ui16_FailedRegAddr | ((uint32)ui16_FailedBits << IC_NUMBITS_16);
        ICRM_ps_MeasData->ui16_CheckFailedRegisterAddrLeft = ui16_FailedRegAddr;
        ICERR_v_DemFailed(IC_e_DEM_REGCHECK_FAILED_L, ui32_OptData);
        e_RetLeft = ICERR_HANDLE(IC_e_ERR_CHECK_REGISTERS_L, ui32_OptData);
      }
    }
    else
    {
      e_RetLeft = ICERR_HANDLE(IC_e_ERR_CHECK_REGISTERS_L_LATENCY, ui16_LeftRegistersLag);
    }
    
    // Check registers that are frame-sync'd (e.g. valid two frames later).
    // Go two buffers in the past:
    pRb_RegHistBuff = ICRM_pRb_GetRegHistoryBuffer(IC_e_IMAGER_LEFT, ui16_LeftRegistersLag + 1);
    if (0 != pRb_RegHistBuff)
    {
      e_SubRet = ICRM_e_CompareRegisters(
              pRb_RegBuffIn,
              pRb_RegHistBuff,
              ICCFG_cas_VerifyRegsDelayed,
              IC_ARRLEN(ICCFG_cas_VerifyRegsDelayed),
              &e_FailedReg,
              &ui16_FailedBits);
      if (IC_e_ERR_OK != e_SubRet)
      {
        ui16_FailedRegAddr = IMGREG_ui16_GetRegAddr(e_FailedReg);
        ui32_OptData = (uint32)ui16_FailedRegAddr | ((uint32)ui16_FailedBits << IC_NUMBITS_16);
        ICRM_ps_MeasData->ui16_CheckFailedRegisterAddrLeft = ui16_FailedRegAddr;
        ICERR_v_DemFailed(IC_e_DEM_REGCHECK_FAILED_L, ui32_OptData);
        e_RetLeft = ICERR_HANDLE(IC_e_ERR_CHECK_REGISTERS_L_FSYNCED, ui32_OptData);
      }
      ICRM_ps_MeasData->ui16_CheckLeftExecCount++;
    }
    
    // If no error occured, report check passed
    if (IC_e_ERR_OK == e_RetLeft)
    {
        ICERR_v_DemPassed(IC_e_DEM_REGCHECK_FAILED_L);
    }
    
    // Update measurement data
    ICRM_ps_MeasData->ui16_LeftRegistersLag = ui16_LeftRegistersLag;
    /*#]*/
}
#endif

/*## operation ICRM_v_HandleConstRegChecks() */
void ICRM_v_HandleConstRegChecks(void) {
    /*#[ operation ICRM_v_HandleConstRegChecks() */
    uint32 ui32_ImgIdx = 0;
    uint32 ui32_Idx = 0;
    ICRM_S_ImagerContext *ps_Ctx;
    IMGREG_E_SENSOR_REG e_Reg;
    uint16 ui16_FailedBits;
    uint16 ui16_Mask;
    uint16 ui16_RegValActual;
    uint16 ui16_RegValDesired;
    uint16 ui16_RegAddr;
    uint32 ui32_OptData;
    
    // Mapping of error-codes to imager number
    static const IC_E_ERROR cae_CheckFailedErr[ICCFG_NUM_IMAGERS] =
    {
        IC_e_ERR_CHECK_REGISTERS_R_CONST
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
       ,IC_e_ERR_CHECK_REGISTERS_L_CONST
    #endif
    };
    
    // For all imagers ...
    for (ui32_ImgIdx = 0; ui32_ImgIdx < ICCFG_NUM_IMAGERS; ui32_ImgIdx++)
    {
      ps_Ctx = &ICRM_as_ImgCtx[ui32_ImgIdx];
    
      // Check constant register bits
      //
      // Currently there is only one register to verify, so disable QAC warning about
      // for-loop only on-time executed:
      //
      // PRQA S 2465 1
      for (ui32_Idx = 0; ui32_Idx < IC_ARRLEN(ICCFG_cas_VerifyRegsConst); ui32_Idx++)
      {
        e_Reg              = ICCFG_cas_VerifyRegsConst[ui32_Idx].e_Reg;
        ui16_Mask          = ICCFG_cas_VerifyRegsConst[ui32_Idx].ui16_Mask;
        ui16_RegValDesired = ICCFG_cas_VerifyRegsConst[ui32_Idx].ui16_Value;
        ui16_RegValActual  = ps_Ctx->pRb_CurRegInBuffer->aRegs[e_Reg];
    
        // Find failed bits
        ui16_FailedBits = ((ui16_RegValActual ^ ui16_RegValDesired) & ui16_Mask);
    
        // Some bits differ from desired value?
        if (ui16_FailedBits != 0x0000)
        {
          ui16_RegAddr = IMGREG_ui16_GetRegAddr(e_Reg);
          ui32_OptData = (((uint32)ui16_RegValActual) << IC_NUMBITS_16) | (uint32)ui16_RegAddr;
          (void)ICERR_HANDLE(cae_CheckFailedErr[ui32_ImgIdx], ui32_OptData);
        }
      }
    }
    /*#]*/
}

/*## operation ICRM_v_HandleI2CRegChecks() */
void ICRM_v_HandleI2CRegChecks(void) {
    /*#[ operation ICRM_v_HandleI2CRegChecks() */
    IC_E_ERROR   e_Ret         = IC_e_ERR_OK;
    const uint32 cui32_NumRegs = IC_ARRLEN(ICCFG_cas_VerifyRegsI2C);
    IC_S_RegBuff *pRb_TxBuff   = NULL;
    IC_S_RegDataPair *ps_RxDat = NULL;
    IMGREG_E_SENSOR_REG e_Reg  = IMGREG_e_REG__LAST_ENTRY_;
    boolean b_ReadNext         = b_TRUE;
    uint32  ui32_Index         = 0;
    uint16  ui16_Mask          = 0;
    uint16  ui16_DataRx        = 0;
    uint16  ui16_DataTx        = 0;
    uint16  ui16_FailedBits    = 0;
    uint16  ui16_RegAddr       = 0;
    uint32  ui32_OptData       = 0;
    
    // This struct is used to store different pointers and constants for left/right imager,
    // saving a lot of if() and #if() statements which would make code worse readable.
    typedef struct
    {
        IC_E_Imager         e_NextImager;
        IC_E_ERROR          e_CheckFailedErr;
        IC_E_ERROR          e_ReadFailedErr;
        ICRM_E_TransferID   e_TransferId;
        IC_S_RegDataPair   *pas_RxBuffer;
        IC_S_RegBuff      **ppRb_RegOutputBuffer;
    } ICRM_S_AsyncRegCheckData;
    static const ICRM_S_AsyncRegCheckData cas_CheckData[ICCFG_NUM_IMAGERS] =
    {
        {
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
            IC_e_IMAGER_LEFT,               /* Next imager to be checked                     */
    #else
            IC_e_IMAGER_RIGHT,              /* Next imager to be checked                     */
    #endif
            IC_e_ERR_CHECK_REGISTERS_I2C_R, /* Check failed error id                         */
            IC_e_ERR_ASYNC_REGCHECK_READ_R, /* RX transfer start error                       */
            ICRM_e_TRANSFID_RX_REGCHECK_R,  /* Register transfer ID                          */
            ICRM_as_ImgCtx[IC_e_IMAGER_RIGHT].as_VerifyRegsI2CRxBuff, /* Pointer to non-embedded register data         */
            &ICRM_as_ImgCtx[IC_e_IMAGER_RIGHT].pRb_CurRegOutBuffer    /* Ptr2Ptr holding register output shadow buffer */
        },
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
        {
            IC_e_IMAGER_RIGHT,              /* Next imager to be checked                     */
            IC_e_ERR_CHECK_REGISTERS_I2C_L, /* Check failed error id                         */
            IC_e_ERR_ASYNC_REGCHECK_READ_L, /* RX transfer start error                       */
            ICRM_e_TRANSFID_RX_REGCHECK_L,  /* Register transfer ID                          */
            ICRM_as_ImgCtx[IC_e_IMAGER_LEFT].as_VerifyRegsI2CRxBuff,  /* Pointer to non-embedded register data         */
            &ICRM_as_ImgCtx[IC_e_IMAGER_LEFT].pRb_CurRegOutBuffer     /* Ptr2Ptr holding register output shadow buffer */
        }
    #endif
    };
    ICRM_S_AsyncRegCheckData const *ps_CurCheckDat;
    
    // Sanity check
    if (ICRM_e_I2CRegCheckImager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, ICRM_e_I2CRegCheckImager);
      goto ERROR_EXIT;
    }
    
    // Get register check data for current imager
    ps_CurCheckDat = &cas_CheckData[ICRM_e_I2CRegCheckImager];
    
    // Check registers which have been scheduled for read in last cycle
    if (b_TRUE == ICRM_b_I2CRegCheckFirstRxDone)
    {
      // Check if read transfer done
      if (b_FALSE == ICRM_as_ImgCtx[ICRM_e_I2CRegCheckImager].b_RegCheckRxDone)
      {
        (void)ICERR_HANDLE(IC_e_ERR_REGCHECK_I2C_NOT_FINISHED, 0);
        b_ReadNext = b_FALSE;
      }
      else
      {
        // Check all registers which have been read
        for (ui32_Index = 0; ui32_Index < cui32_NumRegs; ui32_Index++)
        {
          ps_RxDat           = &ps_CurCheckDat->pas_RxBuffer[ui32_Index]; // PRQA S 0491
          e_Reg              = ICCFG_cas_VerifyRegsI2C[ui32_Index].e_Reg;
          pRb_TxBuff         = *(ps_CurCheckDat->ppRb_RegOutputBuffer);
          ui16_Mask          = ICCFG_cas_VerifyRegsI2C[ui32_Index].ui16_Bitmask;
          ui16_DataRx        = ps_RxDat->ui16_Data;
          ui16_DataTx        = pRb_TxBuff->aRegs[e_Reg];
          ui16_FailedBits    = (ui16_DataRx ^ ui16_DataTx) & ui16_Mask;
          ui16_RegAddr       = ps_RxDat->ui16_Addr;
          if (ui16_FailedBits != 0)
          {
            ui32_OptData = ((uint32)ui16_FailedBits << IC_NUMBITS_16) | (uint32)ui16_RegAddr;
            (void)ICERR_HANDLE(ps_CurCheckDat->e_CheckFailedErr, ui32_OptData);
          }
    
          // Clear old read data to ensure it's really read again
          ps_RxDat->ui16_Data = 0;
        }
    
        // Switch to next imager
        ICRM_e_I2CRegCheckImager = ps_CurCheckDat->e_NextImager;
        ps_CurCheckDat = &cas_CheckData[ICRM_e_I2CRegCheckImager]; // PRQA S 3692
      }
    }
    
    // Schedule read of imager registers
    if (b_TRUE == b_ReadNext)
    {
      // Clear read transfer done flag and start transfer
      ICRM_as_ImgCtx[ICRM_e_I2CRegCheckImager].b_RegCheckRxDone = b_FALSE; // PRQA S 3689
      e_Ret = ICOSW_e_RegTransfer(
              ICRM_e_I2CRegCheckImager,
              ps_CurCheckDat->pas_RxBuffer,
              cui32_NumRegs,
              IC_e_TRANSFMODE_RX,
              &ICRM_v_RegTransferDone,
              (uint8)ps_CurCheckDat->e_TransferId);
      if (IC_e_ERR_OK != e_Ret)
      {
        (void)ICERR_HANDLE(ps_CurCheckDat->e_ReadFailedErr, e_Ret);
      }
    }
    
    ICRM_b_I2CRegCheckFirstRxDone = b_TRUE;
    
    ERROR_EXIT:
    return;
    /*#]*/
}

/*## operation ICRM_v_HandleRegTransExtReq() */
void ICRM_v_HandleRegTransExtReq(void) {
    /*#[ operation ICRM_v_HandleRegTransExtReq() */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    IMGREG_E_SENSOR_REG e_Register = IMGREG_e_REG__LAST_ENTRY_;
    
    // New transfer scheduled?
    if (ICRM_e_REGTRANSEXTSTATE_ARMED == ICRM_s_RegTransExternReq.e_State)
    {
      // Mark as being processed
      ICRM_s_RegTransExternReq.e_State = ICRM_e_REGTRANSEXTSTATE_PROCESSING;
    
      // Schedule register transfer to low layer
      e_Ret = ICOSW_e_RegTransfer(
              ICRM_s_RegTransExternReq.e_Imager,
              &ICRM_s_RegTransExternReq.s_Register,
              1,
              ICRM_s_RegTransExternReq.e_TransferType,
              &ICRM_v_RegTransferDone,
              (uint8)ICRM_e_TRANSFID_EXTERNAL);
      if (IC_e_ERR_OK == e_Ret)
      {
        if (IC_e_TRANSFMODE_TX == ICRM_s_RegTransExternReq.e_TransferType)
        {
          // If its a write, take over value to shadow buffers if entry exists for two reasons:
          //   1) Register checks will fail
          //   2) Some registers are bit-manipulated which requires to reflect the current value in the
          //      shadow buffers, otherwise this write may be lost.
          //
          // NOTE: Calling ICRM_v_SetRegisterSingle() will mark the register as modified, so it will be TX'd
          ///      to the imager a second time when it's in the list 'ICRM_cae_RegistersToWriteWhenChanged'.
          //       We don't care about this as it should not cause problems.
          e_Register = IMGREG_e_FindRegByAddr(ICRM_s_RegTransExternReq.s_Register.ui16_Addr);
          if (IMGREG_e_REG__LAST_ENTRY_ != e_Register)
          {
            ICRM_v_SetRegisterSingle(e_Register, ICRM_s_RegTransExternReq.s_Register.ui16_Data, ICRM_s_RegTransExternReq.e_Imager);
          }
        }
      }
      else
      {
        ICRM_s_RegTransExternReq.e_State = ICRM_e_REGTRANSEXTSTATE_ERROR;
      }
    }
    /*#]*/
}

/*## operation ICRM_e_RegTransExternalSchedule(const IC_E_Imager,const IC_E_TRANSFMODE,const uint16,const uint16) */
IC_E_ERROR ICRM_e_RegTransExternalSchedule(const IC_E_Imager e_Imager, const IC_E_TRANSFMODE e_TransMode, const uint16 ui16_RegAddr, const uint16 ui16_RegDataIfWrite) {
    /*#[ operation ICRM_e_RegTransExternalSchedule(const IC_E_Imager,const IC_E_TRANSFMODE,const uint16,const uint16) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    if ((IC_e_IMAGER_ALL == e_Imager) && (IC_e_TRANSFMODE_RX == e_TransMode))
    {
      // Error: Read from 'all imagers' not possible
      e_Ret = IC_e_ERR_ILLEGAL_ARGUMENT;
    }
    else if ((ICRM_e_REGTRANSEXTSTATE_ARMED == ICRM_s_RegTransExternReq.e_State)
      ||(ICRM_e_REGTRANSEXTSTATE_PROCESSING == ICRM_s_RegTransExternReq.e_State))
    {
      // Error: Transfer is ongoing
      e_Ret = IC_e_ERR_WRONG_STATE;
    }
    else
    {
      ICRM_s_RegTransExternReq.s_Register.ui16_Addr = ui16_RegAddr;
      ICRM_s_RegTransExternReq.s_Register.ui16_Data = ui16_RegDataIfWrite;
      ICRM_s_RegTransExternReq.e_Imager             = e_Imager;
      ICRM_s_RegTransExternReq.e_TransferType       = e_TransMode;
      ICRM_s_RegTransExternReq.e_State              = ICRM_e_REGTRANSEXTSTATE_ARMED; /* Schedules transfer */
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_v_RegTransExternalGetResult(IC_S_RegTransExtResult * const) */
void ICRM_v_RegTransExternalGetResult(IC_S_RegTransExtResult * const ps_Result) {
    /*#[ operation ICRM_v_RegTransExternalGetResult(IC_S_RegTransExtResult * const) */
    // Copy transfer data to result
    ps_Result->ui16_RegAddress = ICRM_s_RegTransExternReq.s_Register.ui16_Addr;
    ps_Result->ui16_RegValue   = ICRM_s_RegTransExternReq.s_Register.ui16_Data;
    ps_Result->e_Imager        = ICRM_s_RegTransExternReq.e_Imager;
    
    // Assign status
    switch (ICRM_s_RegTransExternReq.e_State)
    {
    case ICRM_e_REGTRANSEXTSTATE_DONE:
      ps_Result->b_Done  = b_TRUE;
      ps_Result->b_Error = b_FALSE;
      break;
    case ICRM_e_REGTRANSEXTSTATE_ERROR:
      ps_Result->b_Done  = b_TRUE;
      ps_Result->b_Error = b_TRUE;
      break;
    default:
      ps_Result->b_Done  = b_FALSE;
      ps_Result->b_Error = b_FALSE;
      break;
    }
    /*#]*/
}

/*## operation ICRM_v_RegTransRxLeftSchedule() */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICRM_v_RegTransRxLeftSchedule(void) {
    /*#[ operation ICRM_v_RegTransRxLeftSchedule() */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // Schedule register data read transfer
    e_Ret = ICOSW_e_RegTransfer(
            IC_e_IMAGER_LEFT,
            (IC_S_RegDataPair*)&ICRM_as_RegRxBufferLeft,
            IC_ARRLEN(ICRM_as_RegRxBufferLeft),
            IC_e_TRANSFMODE_RX,
            ICRM_v_RegTransferDone,
            (uint8)ICRM_e_TRANSFID_RX_ASYNC_L
        );
    if (IC_e_ERR_OK != e_Ret)
    {
      (void)ICERR_HANDLE(e_Ret, 0);
    }
    /*#]*/
}
#endif

/*## operation ICRM_v_RegTransRxLeftDone() */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICRM_v_RegTransRxLeftDone(void) {
    /*#[ operation ICRM_v_RegTransRxLeftDone() */
    uint32 ui32_Index = 0;
    IMGREG_E_SENSOR_REG e_Reg;
    
    // Copy data
    for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ICRM_as_RegRxBufferLeft); ui32_Index++)
    {
      e_Reg = ICCFG_cae_LeftImagerAsyncRead[ui32_Index];
      ICRM_ps_ImgCtxL->aRb_RegsIn[IC_ce_MASTER_FRAMETYPE].aRegs[e_Reg] = ICRM_as_RegRxBufferLeft[ui32_Index].ui16_Data;
    }
    ICRM_ui64_RegRxAsyncTimeLeft = ICOSW_ui64_GetTimeUs();
    /*#]*/
}
#endif

/*## operation ICRM_ui64_GetRegRxAsyncTimeLeft() */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
uint64 ICRM_ui64_GetRegRxAsyncTimeLeft(void) {
    /*#[ operation ICRM_ui64_GetRegRxAsyncTimeLeft() */
    return ICRM_ui64_RegRxAsyncTimeLeft;
    /*#]*/
}
#endif

/*## operation ICRM_v_UpdateCommStats(uint16 * const) */
void ICRM_v_UpdateCommStats(uint16 * const pui16_IsrRuntimeOut) {
    /*#[ operation ICRM_v_UpdateCommStats(uint16 * const) */
    // Get new data
    ICRM_s_CommStatsPrev = ICRM_s_CommStats;
    ICOSW_v_GetCommStats(&ICRM_s_CommStats);
    
    // Calc deltas
    #if (IC_PROFILING_ENABLED == 1)
    ICRM_aui32_ISRRuntimes[ICRM_ui32_StatIndex] = ICRM_s_CommStats.ui32_ISRRuntimeTotalUs - ICRM_s_CommStatsPrev.ui32_ISRRuntimeTotalUs;
    ICRM_aui32_ISRCounts[ICRM_ui32_StatIndex]   = ICRM_s_CommStats.ui32_ISRCountTotal     - ICRM_s_CommStatsPrev.ui32_ISRCountTotal;
    
    ICRM_ui32_StatIndex++;
    if (ICRM_ui32_StatIndex >= IC_ARRLEN(ICRM_aui32_ISRCounts))
    {
      ICRM_ui32_StatIndex = 0;
    }
    #endif
    
    if (NULL != pui16_IsrRuntimeOut)
    {
      *pui16_IsrRuntimeOut = (uint16)(ICRM_s_CommStats.ui32_ISRRuntimeTotalUs - ICRM_s_CommStatsPrev.ui32_ISRRuntimeTotalUs);
    }
    /*#]*/
}

/*## operation ICRM_v_CheckI2CTiming(const uint32,const sint32) */
void ICRM_v_CheckI2CTiming(const uint32 ui32_FrameStartUs, const sint32 si32_TimingOffsetLR) {
    /*#[ operation ICRM_v_CheckI2CTiming(const uint32,const sint32) */
    // Calculate slacks
    const sint32 si32_SlackP2_R = ((sint32)ui32_FrameStartUs - (sint32)ICRM_s_I2CFinishTimes.ui32_Part2Right);
    const sint32 si32_SlackP2_L = ((sint32)ui32_FrameStartUs - (sint32)ICRM_s_I2CFinishTimes.ui32_Part2Left ) + si32_TimingOffsetLR;
    const sint16 si16_SlackP2_R = IC_si16_SaturateSi32(si32_SlackP2_R);
    const sint16 si16_SlackP2_L = IC_si16_SaturateSi32(si32_SlackP2_L);
    const uint32 cui32_Optdata_R = (1 << 16);
    const uint32 cui32_Optdata_L = (2 << 16);
    uint32 ui32_OptData   = 0;
    
    // Handle right imager slack
    if (si16_SlackP2_R < ICCFG_si16_I2C_PART2_MIN_SLACK_US)
    {
      // Report error: Put slack into optional data for debug purpose, so disable QAC warning
      // PRQA S 0290 1
      ui32_OptData = cui32_Optdata_R | ((uint32)si16_SlackP2_R & IC_BITMASK_U16);
      ICERR_v_DemFailed(IC_e_DEM_IMAGER_COMM_TIMING, ui32_OptData);
      (void)ICERR_HANDLE(IC_e_ERR_I2C_TIMING_LATE_RIGHT, si16_SlackP2_R);
    }
    else
    {
      ICERR_v_DemPassed(IC_e_DEM_IMAGER_COMM_TIMING);
    }
    ICRM_ps_MeasData->s_I2CTimingRight.si16_SlackPart2 = si16_SlackP2_R;
    if (si16_SlackP2_R < ICRM_ps_MeasData->s_I2CTimingRight.si16_SlackPart2Min)
    {
      ICRM_ps_MeasData->s_I2CTimingRight.si16_SlackPart2Min = si16_SlackP2_R;
    }
    ICRM_ps_MeasData->s_I2CTimingRight.ui32_FinishPart1 = ICRM_s_I2CFinishTimes.ui32_Part1Right;
    ICRM_ps_MeasData->s_I2CTimingRight.ui32_FinishPart2 = ICRM_s_I2CFinishTimes.ui32_Part2Right;
    
    // Handle left imager slack
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    if (si16_SlackP2_L < ICCFG_si16_I2C_PART2_MIN_SLACK_US)
    {
      // Report error: Put slack into optional data for debug purpose, so disable QAC warning
      // PRQA S 0290 1
      ui32_OptData = cui32_Optdata_L | ((uint32)si16_SlackP2_L & IC_BITMASK_U16);
      ICERR_v_DemFailed(IC_e_DEM_IMAGER_COMM_TIMING, ui32_OptData);
      (void)ICERR_HANDLE(IC_e_ERR_I2C_TIMING_LATE_LEFT, si16_SlackP2_L);
    }
    else
    {
      ICERR_v_DemPassed(IC_e_DEM_IMAGER_COMM_TIMING);
    }
    ICRM_ps_MeasData->s_I2CTimingLeft.si16_SlackPart2  = si16_SlackP2_L;
    if (si16_SlackP2_L < ICRM_ps_MeasData->s_I2CTimingLeft.si16_SlackPart2Min)
    {
      ICRM_ps_MeasData->s_I2CTimingLeft.si16_SlackPart2Min = si16_SlackP2_L;
    }
    ICRM_ps_MeasData->s_I2CTimingLeft.ui32_FinishPart1  = ICRM_s_I2CFinishTimes.ui32_Part1Left;
    ICRM_ps_MeasData->s_I2CTimingLeft.ui32_FinishPart2  = ICRM_s_I2CFinishTimes.ui32_Part2Left;
    #endif
    /*#]*/
}

/*## operation ICRM_v_GetRegisterRequest(IC_S_RegTransfReq * const) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICRM_v_GetRegisterRequest(IC_S_RegTransfReq * const ps_Request) {
    /*#[ operation ICRM_v_GetRegisterRequest(IC_S_RegTransfReq * const) */
    ps_Request->pui16_Registers = ICRM_aui16_LeftImagerRegisterRequestAddrs;
    ps_Request->ui16_NumRegisters = IC_ARRLEN(ICRM_aui16_LeftImagerRegisterRequestAddrs);
    ps_Request->ui16_SeqCounter++;
    ps_Request->ui16_RegistersetChangedCnt = 1; // Request-set is constant, so this is never incremented
    ps_Request->b_RequestValid = b_TRUE;
    /*#]*/
}
#endif

/*## operation ICRM_e_ProcessRegisterResponse(const uint16,const IC_S_RegTransfResp * const) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
IC_E_ERROR ICRM_e_ProcessRegisterResponse(const uint16 ui16_FrameNum, const IC_S_RegTransfResp * const ps_Resp) {
    /*#[ operation ICRM_e_ProcessRegisterResponse(const uint16,const IC_S_RegTransfResp * const) */
    IC_E_ERROR          e_Ret                 = IC_e_ERR_OK;
    IC_E_FRAMETYPE      e_FrametypeLeft       = IC_ce_MASTER_FRAMETYPE;
    IMGREG_E_SENSOR_REG e_Register            = IMGREG_e_REG__LAST_ENTRY_;
    uint16              ui16_LeftRegistersLag = 0;
    uint16              ui16_Index            = 0;
    uint16              ui16_RegValue         = 0;
    IC_S_RegBuff       *pRb_RegBuffIn         = 0;
    
    // Check pointer
    if ((NULL == ps_Resp) || (NULL == ps_Resp->paui16_Registers))
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_NULLPOINTER, 0);
      goto ERROR_EXIT;
    }
    
    // Determine frame-type from frame-counter and copy values from IPC
    ICRM_ui16_FramenumLeft = ps_Resp->paui16_Registers[0]; // PRQA S 0491
    e_FrametypeLeft = ((ICRM_ui16_FramenumLeft & 1) == 0) ? IC_e_FRAMETYPE_EVEN : IC_e_FRAMETYPE_ODD;
    pRb_RegBuffIn = &(ICRM_ps_ImgCtxL->aRb_RegsIn[e_FrametypeLeft]);
    ui16_LeftRegistersLag = ui16_FrameNum - ICRM_ui16_FramenumLeft;
    
    // Copy registers from IPC and give to sensor-driver
    for (ui16_Index = 0; ui16_Index < IC_ARRLEN(ICCFG_cae_LeftImagerRegisterRequest); ui16_Index++)
    {
      ui16_RegValue = ps_Resp->paui16_Registers[ui16_Index]; // PRQA S 0491
      e_Register = ICCFG_cae_LeftImagerRegisterRequest[ui16_Index];
      pRb_RegBuffIn->aRegs[e_Register] = ui16_RegValue;
    }
    IMGDRV_v_SetRegisterInput(pRb_RegBuffIn, IC_e_IMAGER_LEFT);
    
    // We got a new response
    ICRM_ps_MeasData->ui16_LeftRegistersLag = ui16_LeftRegistersLag;
    ICRM_ps_MeasData->ui16_LeftRegistersReceiveCount++;
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}
#endif

/*## operation ICRM_ui32_GetNumTransferErrors() */
uint32 ICRM_ui32_GetNumTransferErrors(void) {
    /*#[ operation ICRM_ui32_GetNumTransferErrors() */
    return ICRM_ui32_NumRegTransErrors;
    /*#]*/
}

/*## operation ICRM_pRb_GetRegistersIn(const IC_E_Imager,const IC_E_FRAMETYPE) */
IC_S_RegBuff * ICRM_pRb_GetRegistersIn(const IC_E_Imager e_Imager, const IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation ICRM_pRb_GetRegistersIn(const IC_E_Imager,const IC_E_FRAMETYPE) */
    // Only imager RIGHT/LEFT possible for 'e_Imager'
    // PRQA S 3689 1
    return &(ICRM_as_ImgCtx[e_Imager].aRb_RegsIn[e_FrameType]);
    /*#]*/
}

/*## operation ICRM_pRb_GetRegHistoryBuffer(const IC_E_Imager,const uint16) */
static IC_S_RegBuff * ICRM_pRb_GetRegHistoryBuffer(const IC_E_Imager e_Imager, const uint16 ui16_NumFramesBack) {
    /*#[ operation ICRM_pRb_GetRegHistoryBuffer(const IC_E_Imager,const uint16) */
    uint16 ui16_Index = 0;
    IC_S_RegBuff *pRb_Ret = NULL;
    ICRM_S_ImagerContext *ps_Ctx;
    
    if (e_Imager <= IC_ce_LAST_SINGLE_IMAGER)
    {
      ps_Ctx = &ICRM_as_ImgCtx[e_Imager];
      if (ui16_NumFramesBack < ps_Ctx->ui16_RegOutBuffLen)
      {
        ui16_Index = ((ps_Ctx->ui16_RegOutBufferIndex + ps_Ctx->ui16_RegOutBuffLen) - ui16_NumFramesBack)
                   % ps_Ctx->ui16_RegOutBuffLen;
    
        pRb_Ret = &(ps_Ctx->paRb_RegOutBuffs[ui16_Index]); // PRQA S 0491
      }
    }
    return pRb_Ret;
    /*#]*/
}

/*## operation ICRM_v_SetTXMode(const ICRM_E_TxMode) */
void ICRM_v_SetTXMode(const ICRM_E_TxMode e_Mode) {
    /*#[ operation ICRM_v_SetTXMode(const ICRM_E_TxMode) */
    ICRM_e_TxMode = e_Mode;
    /*#]*/
}

/*## operation ICRM_e_GetTXMode() */
ICRM_E_TxMode ICRM_e_GetTXMode(void) {
    /*#[ operation ICRM_e_GetTXMode() */
    return ICRM_e_TxMode;
    /*#]*/
}

/*## operation ICRM_v_IncorporateInitSequence(const IC_S_RegDataPair *,uint16) */
#pragma push
#pragma optimize_for_size on
static void ICRM_v_IncorporateInitSequence(const IC_S_RegDataPair * ps_InitSequence, uint16 ui16_NumElements) {
    /*#[ operation ICRM_v_IncorporateInitSequence(const IC_S_RegDataPair *,uint16) */
    IMGREG_E_SENSOR_REG e_Reg;
    if (NULL != ps_InitSequence)
    {
      // Loop over all elements
      while (ui16_NumElements > 0)
      {
        e_Reg = IMGREG_e_FindRegByAddr(ps_InitSequence->ui16_Addr);
        if (e_Reg < IMGREG_e_REG__LAST_ENTRY_)
        {
          // Register found, so copy value into output buffer
          ICRM_ps_ImgCtxR->pRb_CurRegOutBuffer->aRegs[e_Reg] = ps_InitSequence->ui16_Data;
          ICRM_v_BitmapClearBit(ICRM_ps_ImgCtxR->aui32_RegChangedBitmap, (uint32)e_Reg);
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
          ICRM_ps_ImgCtxL->pRb_CurRegOutBuffer->aRegs[e_Reg] = ps_InitSequence->ui16_Data;
          ICRM_v_BitmapClearBit(ICRM_ps_ImgCtxL->aui32_RegChangedBitmap, (uint32)e_Reg);
    #endif
        }
    
        // Go to next entry. Pointer-arithmetic can not be omitted here:
        // PRQA S 0489 1
        ps_InitSequence++;
        ui16_NumElements--;
      }
    }
    /*#]*/
}
#pragma pop

/*## operation ICRM_e_SetRegisterResetValues(const IC_E_Imager,const uint16,const uint8) */
IC_E_ERROR ICRM_e_SetRegisterResetValues(const IC_E_Imager e_Imager, const uint16 ui16_ModelId, const uint8 ui8_RevisionNum) {
    /*#[ operation ICRM_e_SetRegisterResetValues(const IC_E_Imager,const uint16,const uint8) */
    IC_E_ERROR     e_Ret = IC_e_ERR_OK;
    IMGREG_E_ERROR e_ImgRet;
    
    // Only single imager allowed
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
      goto ERROR_EXIT;
    }
    
    // Get reset values for selected imager
    e_ImgRet = IMGREG_e_GetResetValues(ICRM_as_ImgCtx[e_Imager].pRb_CurRegOutBuffer, ui16_ModelId, ui8_RevisionNum);
    switch (e_ImgRet)
    {
    case IMGREG_e_ERR_OK:
      /* Good boy! */
      break;
    case IMGREG_e_ERR_UNSUPPORTED_IMAGER:
      e_Ret = ICERR_HANDLE(IC_e_ERR_UNSUPPORTED_IMAGER, ((uint32)ui8_RevisionNum << IC_NUMBITS_16) | (uint32)ui16_ModelId);
      break;
    default:
      e_Ret = ICERR_HANDLE(IC_e_ERR_GET_REGISTER_DEFAULTS, ((uint32)ui8_RevisionNum << IC_NUMBITS_16) | (uint32)ui16_ModelId);
      break;
    }
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_v_RegTransferDone(const IC_E_RXTXERR,const uint8) */
static void ICRM_v_RegTransferDone(const IC_E_RXTXERR e_RetCode, const uint8 ui8_TransferId) {
    /*#[ operation ICRM_v_RegTransferDone(const IC_E_RXTXERR,const uint8) */
    // **************************************
    // THIS IS CALLED FROM INTERRUPT CONTEXT!
    // **************************************
    
    // Handle error
    if (IC_e_RXTXERR_OK != e_RetCode)
    {
      ICRM_ui32_NumRegTransErrors++;
      (void)ICOSW_e_HandleRXTXErr(e_RetCode);
    }
    
    // Handle specific transfer ID
    switch ((ICRM_E_TransferID)ui8_TransferId) // PRQA S 1484
    {
    case ICRM_e_TRANSFID_PART1_R:
      ICRM_s_I2CFinishTimes.ui32_Part1Right = ICOSW_ui32_GetTimeUs();
      break;
    case ICRM_e_TRANSFID_PART2_R:
      ICRM_s_I2CFinishTimes.ui32_Part2Right = ICOSW_ui32_GetTimeUs();
      IC_PROFILE_STOP(IC_e_PROFSECT_I2C_DURATION_P2); // PRQA S 3138,3141,3109
      break;
    case ICRM_e_TRANSFID_RX_REGCHECK_R:
      ICRM_as_ImgCtx[IC_e_IMAGER_RIGHT].b_RegCheckRxDone = b_TRUE;
      break;
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    case ICRM_e_TRANSFID_PART1_L:
      ICRM_s_I2CFinishTimes.ui32_Part1Left = ICOSW_ui32_GetTimeUs();
      IC_PROFILE_STOP(IC_e_PROFSECT_I2C_DURATION_P1); // PRQA S 3138,3141,3109
      break;
    case ICRM_e_TRANSFID_PART2_L:
      ICRM_s_I2CFinishTimes.ui32_Part2Left = ICOSW_ui32_GetTimeUs();
      break;
    case ICRM_e_TRANSFID_RX_REGCHECK_L:
      ICRM_as_ImgCtx[IC_e_IMAGER_LEFT].b_RegCheckRxDone = b_TRUE;
      break;
    case ICRM_e_TRANSFID_RX_ASYNC_L:
      ICRM_v_RegTransRxLeftDone();
      break;
    #endif // (ICCFG_ENABLE_LEFT_IMAGER == 1)
    case ICRM_e_TRANSFID_OTHER:
      break;
    case ICRM_e_TRANSFID_INIT_ASYNC:
      break;
    case ICRM_e_TRANSFID_EXTERNAL:
      if (ICRM_e_REGTRANSEXTSTATE_PROCESSING == ICRM_s_RegTransExternReq.e_State)
      {
        if (IC_e_RXTXERR_OK == e_RetCode)
        {
          ICRM_s_RegTransExternReq.e_State = ICRM_e_REGTRANSEXTSTATE_DONE;
        }
        else
        {
          ICRM_s_RegTransExternReq.e_State = ICRM_e_REGTRANSEXTSTATE_ERROR;
        }
      }
      else
      {
        // Wrong state!!
        (void)ICERR_HANDLE(IC_e_ERR_FATAL_PROGRAM_ERROR, ICRM_s_RegTransExternReq.e_State);
      }
      break;
    default:
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_REGTRANSFER_ID, ui8_TransferId);
      break;
    }
    /*#]*/
}

/*## operation ICRM_e_CheckLeftRegReqContainsAll(IC_S_CompareRegPair const  * const,const uint32) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
static IC_E_ERROR ICRM_e_CheckLeftRegReqContainsAll(IC_S_CompareRegPair const  * const ps_CompRegPairs, const uint32 ui32_CompRegCount) {
    /*#[ operation ICRM_e_CheckLeftRegReqContainsAll(IC_S_CompareRegPair const  * const,const uint32) */
    IC_E_ERROR e_Ret    = IC_e_ERR_OK;
    uint32 ui32_IndexA  = 0;
    uint32 ui32_IndexB  = 0;
    uint32 ui32_LoopCnt = 0;
    uint16 ui16_RegAddr = 0;
    boolean b_Found     = b_FALSE;
    IMGREG_E_SENSOR_REG e_Reg = IMGREG_e_REG__LAST_ENTRY_;
    
    // Check if all registers which are to be verified are contained in left register
    // request array. IndexB runs circular even if entry has been found in previous
    // loop. This saves runtime if 'ICCFG_cas_VerifyRegs' and 'ICCFG_cae_LeftImagerRegisterRequest' have
    // same or at least similar register order.
    ui32_IndexB = 0;
    for (ui32_IndexA = 0; ui32_IndexA < ui32_CompRegCount; ui32_IndexA++)
    {
      b_Found = b_FALSE;
      e_Reg = ps_CompRegPairs[ui32_IndexA].e_Reg; // PRQA S 0492
    
      // Search for current register in LeftRegRequest list
      for (ui32_LoopCnt = 0; (ui32_LoopCnt < IC_ARRLEN(ICCFG_cae_LeftImagerRegisterRequest)) && (b_FALSE == b_Found); ui32_LoopCnt++)
      {
        if (e_Reg == ICCFG_cae_LeftImagerRegisterRequest[ui32_IndexB])
        {
          b_Found = b_TRUE;
        }
    
        // Increment index and handle wraparound
        ui32_IndexB++;
        if (ui32_IndexB >= IC_ARRLEN(ICCFG_cae_LeftImagerRegisterRequest))
        {
          ui32_IndexB = 0;
        }
      }
    
      // If we could not find current entry, throw an error here
      if (b_TRUE != b_Found)
      {
        ui16_RegAddr = IMGREG_ui16_GetRegAddr(e_Reg);
        e_Ret = ICERR_HANDLE(IC_e_ERR_SOURCECODE_ERROR, ui16_RegAddr);
      }
    }
    
    return e_Ret;
    /*#]*/
}
#endif

/*## operation ICRM_e_CompareRegisters(const IC_S_RegBuff * const,const IC_S_RegBuff * const,const IC_S_CompareRegPair *,uint16,IMGREG_E_SENSOR_REG * const,uint16 * const) */
static IC_E_ERROR ICRM_e_CompareRegisters(const IC_S_RegBuff * const pRb_Regs1, const IC_S_RegBuff * const pRb_Regs2, const IC_S_CompareRegPair * ps_RegsToCheck, uint16 ui16_NumRegs, IMGREG_E_SENSOR_REG * const pe_FailedReg, uint16 * const pui16_FailedBits) {
    /*#[ operation ICRM_e_CompareRegisters(const IC_S_RegBuff * const,const IC_S_RegBuff * const,const IC_S_CompareRegPair *,uint16,IMGREG_E_SENSOR_REG * const,uint16 * const) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    IMGREG_E_SENSOR_REG e_Reg;
    uint16 ui16_FailedBits = 0;
    
    // Set outputs to 'non failed'
    *pe_FailedReg = IMGREG_e_REG__LAST_ENTRY_;
    *pui16_FailedBits = 0;
    
    while (ui16_NumRegs > 0)
    {
      e_Reg = ps_RegsToCheck->e_Reg;
      ui16_FailedBits = (pRb_Regs1->aRegs[e_Reg] ^ pRb_Regs2->aRegs[e_Reg]) & ps_RegsToCheck->ui16_Bitmask;
      if (ui16_FailedBits != 0)
      {
        *pe_FailedReg = e_Reg;
        *pui16_FailedBits = ui16_FailedBits;
    
        // End loop and exit with error
        ui16_NumRegs = 0;
        e_Ret = IC_e_ERR_REGCOMPARE_FAILED;
    
        // ========================= DEBUG_TEST ========================
        //ICERR_HANDLE(IC_e_ERR_REGCOMPARE_FAILED, ((uint32)IMGREG_ui16_GetRegAddr(e_Reg) << 16) | (pRb_Regs1->aRegs[e_Reg]));
        // ========================= DEBUG_TEST ========================
      }
      else
      {
        // No error, move to next register
        ui16_NumRegs--;
      }
    
      // Go to next entry. Pointer-arithmetic can not be omitted here:
      // PRQA S 0489 1
      ps_RegsToCheck++;
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation ICRM_ui16_GetCompareRegBitmask(const uint16,const uint16) */
#pragma push
#pragma optimize_for_size on
static uint16 ICRM_ui16_GetCompareRegBitmask(const uint16 ui16_RegAddr, const uint16 ui16_NewRegValueHint) {
    /*#[ operation ICRM_ui16_GetCompareRegBitmask(const uint16,const uint16) */
    uint32 ui32_Index = 0;
    uint16 ui16_Bitmask = IC_BITSALLONE_U16; // Default: Check all bits
    for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ICRM_cas_CompareBitmasks); ui32_Index++)
    {
      if (ui16_RegAddr == ICRM_cas_CompareBitmasks[ui32_Index].ui16_Addr)
      {
        ui16_Bitmask = ICRM_cas_CompareBitmasks[ui32_Index].ui16_Bitmask;
        break;
      }
    }
    
    // The reset register needs special treatment: Don't compare anything if RESET-Bit is set!
    if ( (ui16_RegAddr == IMGREG_cui16_REGADDR_RESET)
     && ((ui16_NewRegValueHint & IMGREG_cui16_BITMASK_RESET_REGISTER_RESET) != 0))
    {
      ui16_Bitmask = 0x0000;
    }
    
    return ui16_Bitmask;
    /*#]*/
}
#pragma pop

/*## operation ICRM_v_BitmapSetBit(uint32 * const,uint32) */
static void ICRM_v_BitmapSetBit(uint32 * const pui32_Bitmap, uint32 ui32_Bitnum) {
    /*#[ operation ICRM_v_BitmapSetBit(uint32 * const,uint32) */
    // 3120: 'Magic Numbers' are commented in the code
    // 0492: Pointer usage as array can not be omitted here
    //
    // PRQA S 3120,0492 3
    const uint32 ui32_ElemIndex = ui32_Bitnum >> 5u; // div 32
    ui32_Bitnum -= ui32_ElemIndex << 5u; // mult 32
    pui32_Bitmap[ui32_ElemIndex] |= (1u << ui32_Bitnum);
    /*#]*/
}

/*## operation ICRM_v_BitmapClearBit(uint32 * const,uint32) */
static void ICRM_v_BitmapClearBit(uint32 * const pui32_Bitmap, uint32 ui32_Bitnum) {
    /*#[ operation ICRM_v_BitmapClearBit(uint32 * const,uint32) */
    // 3120: 'Magic Numbers' are commented in the code
    // 0492: Pointer usage as array can not be omitted here
    //
    // PRQA S 3120,0492 3
    const uint32 ui32_ElemIndex = ui32_Bitnum >> 5u; // div 32
    ui32_Bitnum -= ui32_ElemIndex << 5u; // mult 32
    pui32_Bitmap[ui32_ElemIndex] &= (uint32)(~(1u << ui32_Bitnum));
    /*#]*/
}

/*## operation ICRM_b_BitmapGetBit(const uint32 * const,uint32) */
static boolean ICRM_b_BitmapGetBit(const uint32 * const pui32_Bitmap, uint32 ui32_Bitnum) {
    /*#[ operation ICRM_b_BitmapGetBit(const uint32 * const,uint32) */
    // 3120: 'Magic Numbers' are commented in the code
    // 0492: Pointer usage as array can not be omitted here
    //
    // PRQA S 3120,0492 4
    boolean b_Ret = b_FALSE;
    const uint32 ui32_ElemIndex = ui32_Bitnum >> 5u; // div 32
    ui32_Bitnum -= ui32_ElemIndex << 5u; // mult 32
    if ((pui32_Bitmap[ui32_ElemIndex] & (1u << ui32_Bitnum)) != 0)
    {
      b_Ret = b_TRUE;
    }
    else
    {
      b_Ret = b_FALSE;
    }
    return b_Ret;
    /*#]*/
}

/*## operation ICRM_e_FindLastRegValue(const IMGREG_E_SENSOR_REG ,const IC_S_RegDataPair * const,const uint16,uint16 * const) */
#pragma push
#pragma optimize_for_size on
IC_E_ERROR ICRM_e_FindLastRegValue(const IMGREG_E_SENSOR_REG e_Register, const IC_S_RegDataPair * const ps_RegDataBuffer, const uint16 ui16_NumElements, uint16 * const pui16_InitValue) {
    /*#[ operation ICRM_e_FindLastRegValue(const IMGREG_E_SENSOR_REG ,const IC_S_RegDataPair * const,const uint16,uint16 * const) */
    IC_E_ERROR e_Ret = IC_e_ERR_NOTAVAILABLE;
    IMGREG_E_SENSOR_REG e_MyReg = IMGREG_e_REG__LAST_ENTRY_;
    sint16 si16_Index = 0;
    uint16 ui16_RegAddr = IMGREG_ui16_GetRegAddr(e_Register);
    boolean b_Found = b_FALSE;
    
    for (si16_Index = ((sint16)ui16_NumElements-1); (si16_Index >= 0) && (b_FALSE == b_Found); si16_Index--)
    {
      if (ui16_RegAddr == ps_RegDataBuffer[si16_Index].ui16_Addr)
      {
        *pui16_InitValue = ps_RegDataBuffer[si16_Index].ui16_Data;
        b_Found = b_TRUE;
        e_Ret = IC_e_ERR_OK;
      }
    }
    return e_Ret;
    /*#]*/
}
#pragma pop


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_regmanager.c
*********************************************************************/
// PRQA S 7013 2
