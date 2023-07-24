//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_testmanager.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:26:04CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_testmanager
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_testmanager.c
//  LOGIN:           uidt3974  
//  
//  The Imager Control Test Manager implements all 'remaining' FuSi checks, which are not
//  covered by separate modules. This includes:
//    * Imager BIST (Build-in self test)
//    * Imager Startup Databus Test (Databus Imager<->MCU)
//    * Imager Cyclic Databus Test (partly via noise/bitcombination analysis)
//  
//  Tests are controlled by the calling module (ic_controller) and implmeneted according to
//  the specification 'MFC3xx_Imager_Tests_at_Start_up_sequence_and_cyclic.docx'. See there
//  for details about thease tests.
//  
//  ==========================================================================================
//  =                  CYCLIC DATABUS TEST (noise analysis + frame counter)                  =
//  ==========================================================================================
//  The databus of the imager has to be cyclically checked, which is executed by using a
//  combination of embedded register data, embedded statistics data and image noise. All three
//  cases are needed to cover all 12 bits of the databus, so the test is split into three parts:
//  
//  1) The upper 8 bits [11:4] are checked using embedded register data. All imager registers
//     are split into two bytes, which are transported using embedded register data. All
//     important registers are cyclically checked in the register manager, so any biterror will
//     be seen there. To be sure to cover all possible damages of the bus (short circuit GND,
//     VDD, open circuit, short to neightbor line, ...), one dedicated register is used to
//     transport a special testpattern which will be changed each cycle. This is done in function
//     ICTM_e_ChangeDatabusTestpattern().
//  
//  2) The bits [3:2] are checked by using the frame counter in the statistics data, which spans
//     over pixels [9:2]. Therefore the two lower bits of the counter are visible in bits [3:2]
//     and expected to change every frame. After 4 frames, all bitcombos must have been seen in
//     the data stream. This is implemented in ICTM_v_DatabusCheckNoiseMainFunc().
//  
//  3) The lower two bits [1:0] are checked by analyzing the imager's pixeldata stream and looking
//     for all possible values (0,1,2,3) somewhere in the middle of the image. As the image is
//     always a bit grainy/noisy, even a very dark image will produce every combination within
//     a line in case the imager is not faulty. See functions ICTM_v_DatabusCheckNoise*Func() for
//     details.
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
//  Possible dereference of NULL pointer
//    PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Mon, 12, Nov 2012  10:54 W. Europe Standard Time AM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_testmanager.h"
/*## dependency ic_cfg */
#include "ic_cfg.h"
/*## dependency ic_driver */
#include "ic_driver.h"
/*## dependency ic_errmanager */
#include "ic_errmanager.h"
/*## dependency ic_oswrapper */
#include "ic_oswrapper.h"
/*## dependency ic_regmanager */
#include "ic_regmanager.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_testmanager */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Assure that the BIST spans at least 3 frames (set to 4 when starting at middle of frame)
/*## attribute ICTM_cui16_BistDelayNumFrames */
#define ICTM_cui16_BistDelayNumFrames 4

/*## attribute ICTM_cui16_DelayAfterStreamingOnUs */
#define ICTM_cui16_DelayAfterStreamingOnUs 32000

//  Start-position (CROI) of master output frame on active pixel array, needed for calculation
//  of testpattern start
/*## attribute ICTM_s_CroiMasterFrame */
static IC_S_Croi ICTM_s_CroiMasterFrame;

//  ROI for databus test at startup
//  
//  PRQA S 3218 2
/*## attribute ICTM_s_DatabusTestRoi */
static const IC_S_Roi ICTM_s_DatabusTestRoi = {
        0,                             /* StartX */
        ICCFG_cui16_DATABUSTEST_LINEY, /* StartY */
        ICCFG_cui16_CROI_ODD_WIDTH,    /* Width  */
        1                              /* Height */
};

//  Current state of this module
/*## attribute ICTM_e_DBTestState */
static ICTM_E_DBTestState ICTM_e_DBTestState = ICTM_e_DBTESTSTATE_INIT;

//  Result for databus test
/*## attribute ICTM_e_DBTestResult */
static ICTM_E_DBUS_RESULT ICTM_e_DBTestResult = ICTM_e_DBUS_RESULT_NOT_FINISHED;

//  State and calculation values from cyclic databus test
/*## attribute ICTM_s_CycDBus */
static ICTM_S_CyclicDBusTest ICTM_s_CycDBus;

//  Our measurement data
/*## attribute ICTM_ps_MeasData */
static ICTM_S_MeasData * ICTM_ps_MeasData = 0;

//  Name of this module, required for calls to ICERR_HANDLE().
//  
//  Character string is only used for debugging & recording analysis, so suppress QAC warnings:
//  PRQA S 5013,3625 3
/*## attribute pch_ModuleName */
static const char * const pch_ModuleName = "TESTMGR";

/*## operation ICTM_e_ExecBIST() */
IC_E_ERROR ICTM_e_ExecBIST(void) {
    /*#[ operation ICTM_e_ExecBIST() */
    ICRM_E_TxMode e_TxMode;
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    boolean b_Passed = b_FALSE;
    uint32 ui32_NumTransErrors = 0;
    
    // List of registers for reading status flags
    // PRQA S 3674 1
    static const IMGREG_E_SENSOR_REG cae_BistStatusRegs[] = { IMGREG_e_REG_BIST_BUFFERS_STATUS1 };
    
    // Save current tx-mode and set to instant-flush for this function. Errors will be checked
    // after this function.
    e_TxMode = ICRM_e_GetTXMode();
    ICRM_v_SetTXMode(ICRM_e_TXMODE_WRITEINSTANT_SYNC);
    
    // Implementation according to "MFC3xx_ImagerTests_at_Statup_sequence_and_cyclic.docx"
    // from SFE.
    //
    // PRQA S 3120 4
    IMGDRV_v_SetStreamingMode(IMGDRV_e_STREAMING_MODE_OFF);           // Disable streaming
    ICRM_v_SetRegister(IMGREG_e_REG_OPERATION_MODE_CTRL,   0x0028);   // Enable HiDy Mode
    ICRM_v_SetRegister(IMGREG_e_REG_BIST_BUFFERS_CONTROL1, 0x0000);   // Reset the BIST
    ICRM_v_SetRegister(IMGREG_e_REG_BIST_BUFFERS_CONTROL1, 0x0701);   // Enable BIST
    IMGDRV_v_SetStreamingMode(IMGDRV_e_STREAMING_MODE_ON);            // Enable streaming
    
    // Pause  for a  minimum of 3 frame cycles and then stop BIST by disabling streaming
    ICOSW_v_DelayUs(ICCFG_cui32_FramePeriodUs * (uint32)ICTM_cui16_BistDelayNumFrames); // PRQA S 4119
    IMGDRV_v_SetStreamingMode(IMGDRV_e_STREAMING_MODE_OFF);
    
    // Read status
    e_Ret = ICRM_e_ReadRegsViaI2C(cae_BistStatusRegs, IC_ARRLEN(cae_BistStatusRegs), IC_ce_MASTER_FRAMETYPE);
    if (IC_e_ERR_OK != e_Ret)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_REGRX, 0);
      goto ERROR_EXIT;
    }
    
    // Check status
    b_Passed = IMGDRV_b_GetBistStatusPassed(IC_e_IMAGER_RIGHT);
    if (b_FALSE == b_Passed)
    {
      ICERR_v_DemFailed(IC_e_DEM_IMAGER_BIST_R, 0);
      e_Ret = ICERR_HANDLE(IC_e_ERR_BIST_FAILED_RIGHT, 0);
      goto ERROR_EXIT;
    }
    else
    {
      ICERR_v_DemPassed(IC_e_DEM_IMAGER_BIST_R);
    }
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    b_Passed = IMGDRV_b_GetBistStatusPassed(IC_e_IMAGER_LEFT);
    if (b_FALSE == b_Passed)
    {
      ICERR_v_DemFailed(IC_e_DEM_IMAGER_BIST_L, 0);
      e_Ret = ICERR_HANDLE(IC_e_ERR_BIST_FAILED_LEFT, 0);
      goto ERROR_EXIT;
    }
    else
    {
      ICERR_v_DemPassed(IC_e_DEM_IMAGER_BIST_L);
    }
    #endif
    
    // Go back to normal mode
    ICRM_v_SetRegister(IMGREG_e_REG_BIST_BUFFERS_CONTROL1, 0x0000);   // Reset the BIST
    IMGDRV_v_SetStreamingMode(IMGDRV_e_STREAMING_MODE_ON);            // Enable streaming
    
    // There must not be any transfer errors occured
    ui32_NumTransErrors = ICRM_ui32_GetNumTransferErrors();
    if (ui32_NumTransErrors != 0)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_REGTRANS_ERRORS_NOT_ZERO, ui32_NumTransErrors);
      goto ERROR_EXIT;
    }
    
    ERROR_EXIT:
    ICRM_v_SetTXMode(e_TxMode); // Restore previous TX mode
    return e_Ret;
    /*#]*/
}

/*## operation ICTM_v_DatabusCheckLineFunc(const uint16,const uint16 *) */
void ICTM_v_DatabusCheckLineFunc(const uint16 ui16_LineNum, const uint16 * pui16_PixelData) {
    /*#[ operation ICTM_v_DatabusCheckLineFunc(const uint16,const uint16 *) */
    // We use pointers to access pixeldata here, so disable QAC messages:
    //   PRQA S 0488,0492 LINEFUNC
    //
    // All magic numbers used here are described directly in the code to improve readability
    //   PRQA S 3120 LINEFUNC
    boolean b_Failed = b_FALSE;
    uint16 ui16_Pattern = 0;
    uint16 ui16_FirstPatternValue = 0x0000;
    uint16 ui16_FirstPixel = 0;
    const uint16 cui16_TestpatternPixelPeriod = 28;
    
    if ((ICTM_e_DBTESTSTATE_RUNNING == ICTM_e_DBTestState)
         && (ui16_LineNum == ICCFG_cui16_DATABUSTEST_LINEY))
    {
      // Testpattern starts at column zero of active pixel array and repeats every 28 pixels, so we have to
      // find our testpattern start depending on CROI start X. Formula is:
      //
      //      TESTPATTERN_START = Ceil(X_ADDR_START / 28)*28 - X_ADDR_START
      //
      ui16_FirstPixel = ((((ICTM_s_CroiMasterFrame.ui16_StartX + cui16_TestpatternPixelPeriod) - 1) / cui16_TestpatternPixelPeriod) /* CEIL(X_ADDR_START / 28) */
                          * cui16_TestpatternPixelPeriod
                        )
                        - ICTM_s_CroiMasterFrame.ui16_StartX;
      pui16_PixelData += ui16_FirstPixel;
    
      // Check first pixel value
    #ifdef ICCFG_SENSOR_MT9M025
      // In MT9M025 there's a bug in "Walking 1's" testpattern.
      // Instead of 0x0000, Imager outputs 0x0002, so do special check at beginning
      ui16_FirstPatternValue = 0x0002;
    #else
      // Non-buggy imagers (ARX550) start with 0x0000
      ui16_FirstPatternValue = 0x0000;
    #endif
      if ((pui16_PixelData[0] != ui16_FirstPatternValue) || (pui16_PixelData[1] != ui16_FirstPatternValue))
      {
        b_Failed = b_TRUE;
      }
      pui16_PixelData += 2;
    
      // Check next values (1,2,4,8,16,...,2048). NOTE: Each value is stable for TWO pixels
      ui16_Pattern = 1;
      while (ui16_Pattern <= 2048)
      {
        if ((pui16_PixelData[0] != ui16_Pattern) || (pui16_PixelData[1] != ui16_Pattern))
        {
          b_Failed = b_TRUE;
        }
        ui16_Pattern <<= 1;
        pui16_PixelData += 2;
      }
    
      // Check last value (4095 <<-- NOTE: it's NOT 4096)
      if ((pui16_PixelData[0] != 4095) ||( pui16_PixelData[1] != 4095))
      {
        b_Failed = b_TRUE;
      }
    
      // Provide final result
      if (b_TRUE == b_Failed)
      {
        ICTM_e_DBTestResult = ICTM_e_DBUS_RESULT_FINISHED_FAILED;
      }
      else
      {
        ICTM_e_DBTestResult = ICTM_e_DBUS_RESULT_FINISHED_OK;
      }
    
      // Move to next state
      ICTM_e_DBTestState++; /* Linear state machine */ // PRQA S 1481,1319
    }
    
    // PRQA L:LINEFUNC
    /*#]*/
}

/*## operation ICTM_v_DatabusCheckNoiseLineFunc(const uint16,const uint16 *) */
void ICTM_v_DatabusCheckNoiseLineFunc(const uint16 ui16_LineNum, const uint16 * pui16_PixelData) {
    /*#[ operation ICTM_v_DatabusCheckNoiseLineFunc(const uint16,const uint16 *) */
    static const uint16 cui16_PIXELS_PER_LOOP = 4;
    const uint16 cui16_AllCombosSeenValue_Bits01 = 0x000F; /* Lower two lanes: 2^0b11 = 15 */
    uint16 ui16_BitCombosSeen = 0;
    uint32 ui32_Index = 0;
    register uint16 ui16_Pix1 = 0;
    register uint16 ui16_Pix2 = 0;
    register uint16 ui16_Pix3 = 0;
    register uint16 ui16_Pix4 = 0;
    
    // Only process our selected ROI
    if (ICCFG_cui16_DATABUSTEST_CYCLIC_LINEY == ui16_LineNum)
    {
      // Go through all pixels until all lower 2 bit-combinations had occurred
      for (ui32_Index = 0;
          (ui32_Index < ICCFG_cui16_DATABUSTEST_CYCLIC_COLUMNS) && (ui16_BitCombosSeen != cui16_AllCombosSeenValue_Bits01);
           ui32_Index += cui16_PIXELS_PER_LOOP)
      {
        // Load 4 pixels
        // PRQA S 0489 8
        ui16_Pix1 = *pui16_PixelData;
        pui16_PixelData++;
        ui16_Pix2 = *pui16_PixelData;
        pui16_PixelData++;
        ui16_Pix3 = *pui16_PixelData;
        pui16_PixelData++;
        ui16_Pix4 = *pui16_PixelData;
        pui16_PixelData++;
    
        // Mask lower-2 bits, shift and OR
        // PRQA S 3120 4
        ui16_BitCombosSeen |= 1u << (ui16_Pix1 & 0x3u);
        ui16_BitCombosSeen |= 1u << (ui16_Pix2 & 0x3u);
        ui16_BitCombosSeen |= 1u << (ui16_Pix3 & 0x3u);
        ui16_BitCombosSeen |= 1u << (ui16_Pix4 & 0x3u);
      }
    
      // Accumulate total number of pixels currently used
      ICTM_s_CycDBus.ui32_NumPixelsUsed += ui32_Index;
    
      // Store value from current cycle for main function
      ICTM_s_CycDBus.ui16_CombosSeen_Bits01 = ui16_BitCombosSeen;
    }
    /*#]*/
}

/*## operation ICTM_e_ChangeDatabusTestpattern() */
IC_E_ERROR ICTM_e_ChangeDatabusTestpattern(void) {
    /*#[ operation ICTM_e_ChangeDatabusTestpattern() */
    // Execute cyclic databus check. IMPORTANT NOTE: The actual check is automatically done
    // during the register verification checks in ICRM_e_CheckRegisters(). The following
    // function only changes the pattern written to the register used for this test.
    // PRQA S 3674,3120 3
    static const uint16 ICTIM_caui16_Patterns[] =
    {
        0xAAAA, 0x5555, 0xCCCC, 0x3333, 0xF0F0,
        0x0F0F, 0xFF00, 0x00FF, 0xFFFF, 0x0000
    };
    static uint8 ICTIM_ui8_TestPatternIndex = 0;
    uint16 ui16_Pattern = 0;
    
    ui16_Pattern = ICTIM_caui16_Patterns[ICTIM_ui8_TestPatternIndex];
    IMGDRV_v_SetDatabusTestpattern(ui16_Pattern);
    ICTIM_ui8_TestPatternIndex++;
    if (ICTIM_ui8_TestPatternIndex >= IC_ARRLEN(ICTIM_caui16_Patterns))
    {
      ICTIM_ui8_TestPatternIndex = 0;
    }
    
    return IC_e_ERR_OK;
    /*#]*/
}

/*## operation ICTM_e_DatabusCheckMainFunc() */
ICTM_E_DBUS_RESULT ICTM_e_DatabusCheckMainFunc(void) {
    /*#[ operation ICTM_e_DatabusCheckMainFunc() */
    IC_E_ERROR e_SubRet = IC_e_ERR_OK;
    ICTM_E_DBUS_RESULT e_Ret = ICTM_e_DBUS_RESULT_NOT_FINISHED;
    
    switch (ICTM_e_DBTestState)
    {
    case ICTM_e_DBTESTSTATE_INIT:
    
      // Register Test-ROI
      e_SubRet = ICOSW_e_RegisterTestRoi(&ICTM_s_DatabusTestRoi);
      if (IC_e_ERR_OK != e_SubRet)
      {
        ICTM_e_DBTestResult = ICTM_e_DBUS_RESULT_ERROR;
        ICTM_e_DBTestState  = ICTM_e_DBTESTSTATE_DONE;
      }
      else
      {
        IMGDRV_v_SetTestpattern(IC_e_IMAGER_RIGHT, IMGDRV_e_TESTPATTERN_WALKING_ONES);
        ICTM_e_DBTestState++; /* Linear state machine */ // PRQA S 1481,1319
      }
      break;
    
    case ICTM_e_DBTESTSTATE_DELAY_1_FRAME:
      ICTM_e_DBTestState++; /* Linear state machine */ // PRQA S 1481,1319
      break;
    
    case ICTM_e_DBTESTSTATE_RUNNING:
      break;
    
    case ICTM_e_DBTESTSTATE_CLEANUP:
      (void)ICOSW_e_DeleteTestRoi();
      IMGDRV_v_SetTestpattern(IC_e_IMAGER_RIGHT, IMGDRV_e_TESTPATTERN_NONE);
      ICTM_e_DBTestState++; /* Linear state machine */ // PRQA S 1481,1319
      e_Ret = ICTM_e_DBTestResult;
      break;
    
    case ICTM_e_DBTESTSTATE_DONE:
      e_Ret = ICTM_e_DBTestResult;
      break;
    
    default:
      break;
    }
    
    // Update meas-data struct
    ICTM_ps_MeasData->e_DatabusTestState  = ICTM_e_DBTestState;
    ICTM_ps_MeasData->e_DatabusTestResult = ICTM_e_DBTestResult;
    ICTM_ps_MeasData->b_DatabusTestFailed = (ICTM_e_DBUS_RESULT_FINISHED_FAILED == ICTM_e_DBTestResult) ? b_TRUE : b_FALSE;
    return e_Ret;
    /*#]*/
}

/*## operation ICTM_v_DatabusCheckNoiseMainFunc(const uint16) */
void ICTM_v_DatabusCheckNoiseMainFunc(const uint16 ui16_FrameCntStat) {
    /*#[ operation ICTM_v_DatabusCheckNoiseMainFunc(const uint16) */
    const uint16 cui16_AllCombosSeenValue = 0xFFFF;
    ICTM_S_MeasDBusCyc * const ps_MeasCyc = &ICTM_ps_MeasData->s_DBusCyclic;
    uint16 ui16_ShiftValue = 0;
    
    // In the line-func we collected seen bit-combinations for databus[1:0]. Now use FrameCnt[1:0]
    // from statistical data, which corresponds to databus[3:2] and calculate a total bit-combos
    // seen on databus[3:0].
    //
    // NOTE for ui16_CombosSeen_Bits01:
    //    Bit on position 'n' set to '1' means that we have seen value DBUS[1:0]=n on the bus.
    // NOTE for ui16_CombosSeen_Bits0123:
    //    Bit on position 'n' set to '1' means that we have seen value DBUS[3:0]=n on the bus.
    //
    // Let bits 'abcd' be the seen bit-combos for databus[1:0]. Taking the FrameCnt into account,
    // we create a new bit-combos seen value for databus[3:0] which has the following format:
    //
    //   FrameCnt = 0: 0000 0000 0000 abcd
    //   FrameCnt = 1: 0000 0000 abcd 0000
    //   FrameCnt = 2: 0000 abcd 0000 0000
    //   FrameCnt = 3: abcd 0000 0000 0000
    //
    // So shift ui16_CombosSeen_Bits01 by (FrameCnt[1:0] * 4).
    // PRQA S 3120 1
    ui16_ShiftValue = ((ui16_FrameCntStat & 3) * 4);
    ICTM_s_CycDBus.ui16_CombosSeen_Bits0123 |= (uint16)(ICTM_s_CycDBus.ui16_CombosSeen_Bits01 << ui16_ShiftValue);
    ICTM_s_CycDBus.ui16_NumFramesUsed++;
    
    // Test if we have a problem
    if (ICTM_s_CycDBus.ui16_NumFramesUsed > ICCFG_cui32_DATABUSTEST_CYCLIC_MAXFRAMES)
    {
      (void)ICERR_HANDLE(IC_e_ERR_DATABUSTEST_CYCLIC, ICTM_s_CycDBus.ui16_CombosSeen_Bits0123);
      ICERR_v_DemFailed(IC_e_DEM_IMAGER_DATABUS_MCU_CYCLIC, (uint32)ICTM_s_CycDBus.ui16_CombosSeen_Bits0123);
    }
    else
    {
      ICERR_v_DemPassed(IC_e_DEM_IMAGER_DATABUS_MCU_CYCLIC);
    }
    
    // Store peak values for MTS
    if (ICTM_s_CycDBus.ui32_NumPixelsUsed > ps_MeasCyc->ui32_DataBusNumPixMax)
    {
      ps_MeasCyc->ui32_DataBusNumPixMax = ICTM_s_CycDBus.ui32_NumPixelsUsed;
    }
    if (ICTM_s_CycDBus.ui16_NumFramesUsed > ps_MeasCyc->ui16_DataBusNumFramesMax)
    {
      ps_MeasCyc->ui16_DataBusNumFramesMax = ICTM_s_CycDBus.ui16_NumFramesUsed;
    }
    ps_MeasCyc->ui16_DataBusBitCombosSeen = ICTM_s_CycDBus.ui16_CombosSeen_Bits0123;
    
    // Test if we are finished with all combos
    if (cui16_AllCombosSeenValue == ICTM_s_CycDBus.ui16_CombosSeen_Bits0123)
    {
      ps_MeasCyc->ui32_DataBusNumPixLast = ICTM_s_CycDBus.ui32_NumPixelsUsed;
      ps_MeasCyc->ui16_DataBusNumFrames  = ICTM_s_CycDBus.ui16_NumFramesUsed;
    
      // Reset values for next cycle
      ICTM_s_CycDBus.ui32_NumPixelsUsed = 0;
      ICTM_s_CycDBus.ui16_NumFramesUsed = 0;
      ICTM_s_CycDBus.ui16_CombosSeen_Bits01 = 0;
      ICTM_s_CycDBus.ui16_CombosSeen_Bits0123 = 0;
    }
    /*#]*/
}

/*## operation ICTM_v_Init(ICTM_S_MeasData * const,const IC_S_Croi * const) */
void ICTM_v_Init(ICTM_S_MeasData * const ps_MeasData, const IC_S_Croi * const ps_CroiMasterFrame) {
    /*#[ operation ICTM_v_Init(ICTM_S_MeasData * const,const IC_S_Croi * const) */
    // Initialize variables
    IC_v_ZEROMEM(ICTM_s_CycDBus);
    ICTM_e_DBTestState     = ICTM_e_DBTESTSTATE_INIT;
    ICTM_e_DBTestResult    = ICTM_e_DBUS_RESULT_NOT_FINISHED;
    ICTM_ps_MeasData       = ps_MeasData;
    ICTM_s_CroiMasterFrame = *ps_CroiMasterFrame;
    /*#]*/
}


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_testmanager.c
*********************************************************************/
