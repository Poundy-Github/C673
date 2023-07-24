//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_interface.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:54CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_interface
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_interface.c
//  LOGIN:           uidt3974  
//  
//  This is the top-level interface file of the Imager Control component. All calls from
//  the runtime environment (aka FrameSW) are going through this interface. It is not
//  allowed to directly call functions of IC submodules, which are not defined in this
//  interface file!
//  
//  In fact, this file is only a wrapper, which calls IC submodule functions.
//  
//  =======================================================================================
//  |                                   The Imager Control                                |
//  =======================================================================================
//  The Imager Control component handles most of the tasks related to the imager. This
//  includes, but is not limited to:
//    * Initializing Imagers
//       * Includes register verification
//    * Executing Startup tests
//       * Imager BIST
//       * Databus Test
//       * Analog Test
//    * Imager timing control
//       * Imager synchronization
//       * Jittering of even numbered images
//    * Imager column noise correction triggering, based on temperature changes
//    * Software exposure regulation
//       * Independent control loops for even/odd frames, each having its own set of
//         parameters
//    * Calculation of image characteristics
//       * Response curve calculation (Output to Algos)
//       * Brightness calculation
//       * Noise estimation
//       * Imager temperature
//    * Cyclic FuSi checks
//       * Checking embedded data consistency
//       * Register verification
//       * Cyclic databus test
//       * Framecounter check
//       * Checking I2C register transfer timing
//  
//  =======================================================================================
//  |                                        HIL-Mode                                     |
//  =======================================================================================
//  This module can be initialized in 'HIL-Mode'. This can be used when no real imagers are
//  actually connected to the ECU (open control loop) or when this module is simulated on
//  a PC (e.g. as MTS MO). It is _not_ intended to be used on a simple 'Monitor HIL', which
//  has a camera mounted in front of the screen.
//  
//  In HIL-Mode, the IC skips the following execution steps during init / cyclic execution:
//    * Imager Initialization
//    * Startup tests (BIST, Databus Test, Analog Test)
//    * Cyclic checking of register contents
//    * Cyclic checking of I2C transfer timing
//    * Cyclic checking of left/right imager synchronization
//    * Cyclic checking of IC-ROI position and dimensions
//  
//  When HIL-Mode is enabled, the IC calls external callback 'pfct_v_ResyncSystemTime' on
//  each odd frame and passes the timing offset between embedded frame timestamp and current
//  ECU time as an argument. This can be used to resychronize the ECU time to the time base
//  which is embedded in the recording, which is currently streamed to the ECU camera
//  connectors.
//  
//  To enable HIL-Mode, set 'b_HILMode' to 'b_TRUE' when calling 'IC_e_Init()'.
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Thu, 18, Oct 2012  5:52 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_interface.h"
/*## dependency ic_atest */
#include "ic_atest.h"
/*## dependency ic_controller */
#include "ic_controller.h"
/*## dependency ic_exposuremgr */
#include "ic_exposuremgr.h"
/*## dependency ic_regmanager */
#include "ic_regmanager.h"
/*## dependency ic_roi */
#include "ic_roi.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_interface */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## attribute ICIF_ui32_ExtCtlUnlocked */
static uint32 ICIF_ui32_ExtCtlUnlocked = 0u;

/*## operation IC_v_SetInput(const IC_S_Input * const) */
void IC_v_SetInput(const IC_S_Input * const ps_InputIn) {
    /*#[ operation IC_v_SetInput(const IC_S_Input * const) */
    ICCTL_v_SetInput(ps_InputIn);
    /*#]*/
}

/*## operation IC_v_NewFrameStarted(const uint16,const uint64) */
void IC_v_NewFrameStarted(const uint16 ui16_FrameNum, const uint64 ui64_FrameTimestampIn) {
    /*#[ operation IC_v_NewFrameStarted(const uint16,const uint64) */
    ICCTL_v_NewFrameStarted(ui16_FrameNum, ui64_FrameTimestampIn);
    /*#]*/
}

/*## operation IC_e_LineFunc(const IC_E_FRAMETYPE,const uint16,const uint16 * const) */
IC_E_ERROR IC_e_LineFunc(const IC_E_FRAMETYPE e_FrameType, const uint16 ui16_LineNum, const uint16 * const pui16_PixelData) {
    /*#[ operation IC_e_LineFunc(const IC_E_FRAMETYPE,const uint16,const uint16 * const) */
    return ICCTL_e_LineFunc(e_FrameType, ui16_LineNum, pui16_PixelData);
    /*#]*/
}

/*## operation IC_e_Init(const IC_S_PlatformFuncs * const,const IC_S_StaticInput * const,const boolean,const boolean) */
IC_E_ERROR IC_e_Init(const IC_S_PlatformFuncs * const ps_PlatformFuncsIn, const IC_S_StaticInput * const ps_StaticInputIn, const boolean b_UseHilMode, const boolean b_DisableAnalogTest) {
    /*#[ operation IC_e_Init(const IC_S_PlatformFuncs * const,const IC_S_StaticInput * const,const boolean,const boolean) */
    return ICCTL_e_Init(ps_PlatformFuncsIn, ps_StaticInputIn, b_UseHilMode, b_DisableAnalogTest);
    /*#]*/
}

/*## operation IC_e_DeInit() */
IC_E_ERROR IC_e_DeInit(void) {
    /*#[ operation IC_e_DeInit() */
    return ICCTL_e_DeInit();
    /*#]*/
}

/*## operation IC_e_Start() */
IC_E_ERROR IC_e_Start(void) {
    /*#[ operation IC_e_Start() */
    return ICCTL_e_Start();
    /*#]*/
}

/*## operation IC_v_GetImagerCroi(IC_S_Croi * const,const IC_E_Imager,const IC_E_FRAMETYPE) */
void IC_v_GetImagerCroi(IC_S_Croi * const ps_Croi, const IC_E_Imager e_ImagerTypeLR, const IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation IC_v_GetImagerCroi(IC_S_Croi * const,const IC_E_Imager,const IC_E_FRAMETYPE) */
    ICROI_v_GetImagerCroi(ps_Croi, e_ImagerTypeLR, e_FrameType);
    /*#]*/
}

/*## operation IC_e_GetTemperature(const IC_E_Imager,float32 * const,uint64 * const) */
IC_E_ERROR IC_e_GetTemperature(const IC_E_Imager e_Imager, float32 * const pf32_Temp, uint64 * const pui64_TimeStamp) {
    /*#[ operation IC_e_GetTemperature(const IC_E_Imager,float32 * const,uint64 * const) */
    return ICCTL_e_GetTemperature(e_Imager, pf32_Temp, pui64_TimeStamp);
    /*#]*/
}

/*## operation IC_v_GetSensorIDs(IC_S_SensorIDs * const,const IC_E_Imager) */
void IC_v_GetSensorIDs(IC_S_SensorIDs * const ps_SensorIDs, const IC_E_Imager e_Imager) {
    /*#[ operation IC_v_GetSensorIDs(IC_S_SensorIDs * const,const IC_E_Imager) */
    ICCTL_v_GetSensorIDs(ps_SensorIDs, e_Imager);
    /*#]*/
}

/*## operation IC_b_IsStableStateReached() */
boolean IC_b_IsStableStateReached(void) {
    /*#[ operation IC_b_IsStableStateReached() */
    return ICCTL_b_IsStableStateReached();
    /*#]*/
}

/*## operation IC_e_SetTemporaryFixedExposureT1(const uint16,const uint32) */
IC_E_ERROR IC_e_SetTemporaryFixedExposureT1(const uint16 ui16_T1_us, const uint32 ui32_NumFramesPersistence) {
    /*#[ operation IC_e_SetTemporaryFixedExposureT1(const uint16,const uint32) */
    return ICEXPMG_e_SetTemporaryFixedExposureT1(ui16_T1_us, ui32_NumFramesPersistence);
    /*#]*/
}

/*## operation IC_v_ResetTemporaryFixedExposureT1() */
void IC_v_ResetTemporaryFixedExposureT1(void) {
    /*#[ operation IC_v_ResetTemporaryFixedExposureT1() */
    ICEXPMG_v_ResetTemporaryFixedExposureT1();
    /*#]*/
}

/*## operation IC_v_SetTestpatternLeft(const boolean) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void IC_v_SetTestpatternLeft(const boolean b_Enabled) {
    /*#[ operation IC_v_SetTestpatternLeft(const boolean) */
    ICCTL_v_SetTestpatternLeft(b_Enabled);
    /*#]*/
}
#endif

/*## operation IC_e_SetAnalogTestParams(const IC_S_ATestExternParams * const) */
#if (IC_ANALOG_TEST_ENABLED == 1)
IC_E_ERROR IC_e_SetAnalogTestParams(const IC_S_ATestExternParams * const ps_Params) {
    /*#[ operation IC_e_SetAnalogTestParams(const IC_S_ATestExternParams * const) */
    return ICCTL_e_SetAnalogTestParams(ps_Params);
    /*#]*/
}
#endif

/*## operation IC_e_StartAnalogTest() */
#if (IC_ANALOG_TEST_ENABLED == 1)
IC_E_ERROR IC_e_StartAnalogTest(void) {
    /*#[ operation IC_e_StartAnalogTest() */
    return ICCTL_e_StartAnalogTest();
    /*#]*/
}
#endif

/*## operation IC_ps_GetATestResults() */
#if (IC_ANALOG_TEST_ENABLED == 1)
IC_S_ATestResults * IC_ps_GetATestResults(void) {
    /*#[ operation IC_ps_GetATestResults() */
    return ICAT_ps_GetExtResults();
    
    /*#]*/
}
#endif

/*## operation IC_e_RegTransAsyncWrite(const IC_E_Imager,const uint16,const uint16) */
IC_E_ERROR IC_e_RegTransAsyncWrite(const IC_E_Imager e_Imager, const uint16 ui16_RegisterAddress, const uint16 ui16_RegisterData) {
    /*#[ operation IC_e_RegTransAsyncWrite(const IC_E_Imager,const uint16,const uint16) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    if (ICIF_cui32_KEY_UNLOCK_CONTROL == ICIF_ui32_ExtCtlUnlocked)
    {
      e_Ret = ICRM_e_RegTransExternalSchedule(e_Imager, IC_e_TRANSFMODE_TX, ui16_RegisterAddress, ui16_RegisterData);
    }
    else
    {
      e_Ret = IC_e_ERR_LOCKED;
    }
    return e_Ret;
    /*#]*/
}

/*## operation IC_e_RegTransAsyncRead(const IC_E_Imager,const uint16) */
IC_E_ERROR IC_e_RegTransAsyncRead(const IC_E_Imager e_Imager, const uint16 ui16_RegisterAddress) {
    /*#[ operation IC_e_RegTransAsyncRead(const IC_E_Imager,const uint16) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    if (ICIF_cui32_KEY_UNLOCK_CONTROL == ICIF_ui32_ExtCtlUnlocked)
    {
      e_Ret = ICRM_e_RegTransExternalSchedule(e_Imager, IC_e_TRANSFMODE_RX, ui16_RegisterAddress, 0x0000);
    }
    else
    {
      e_Ret = IC_e_ERR_LOCKED;
    }
    return e_Ret;
    /*#]*/
}

/*## operation IC_v_RegTransGetResult(IC_S_RegTransExtResult *) */
void IC_v_RegTransGetResult(IC_S_RegTransExtResult * ps_Result) {
    /*#[ operation IC_v_RegTransGetResult(IC_S_RegTransExtResult *) */
    ICRM_v_RegTransExternalGetResult(ps_Result);
    /*#]*/
}

/*## operation IC_e_ExternalControl(const ICIF_E_EXTCMD,const uint8 [ICIF_cui32_EXTCTL_ARGSIZE]) */
IC_E_ERROR IC_e_ExternalControl(const ICIF_E_EXTCMD e_Command, const uint8 aui8_ControlSequence[ICIF_cui32_EXTCTL_ARGSIZE]) {
    /*#[ operation IC_e_ExternalControl(const ICIF_E_EXTCMD,const uint8 [ICIF_cui32_EXTCTL_ARGSIZE]) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    uint32 ui32_KeyIn = 0;
    
    // Unlock requested?
    if (ICIF_e_EXTCMD_UNLOCK == e_Command)
    {
      ui32_KeyIn = (aui8_ControlSequence[0] << IC_BITSHIFT_3BYTE)
                 | (aui8_ControlSequence[1] << IC_BITSHIFT_2BYTE)
                 | (aui8_ControlSequence[2] << IC_BITSHIFT_1BYTE)
                 | (aui8_ControlSequence[3] << IC_BITSHIFT_0BYTE);
      ICIF_ui32_ExtCtlUnlocked = ui32_KeyIn;
    }
    
    // Check if we are unlocked
    if (ICIF_cui32_KEY_UNLOCK_CONTROL == ICIF_ui32_ExtCtlUnlocked)
    {
      e_Ret = ICCTL_e_ExternalControl(e_Command, aui8_ControlSequence);
    }
    else
    {
      e_Ret = IC_e_ERR_LOCKED;
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation IC_ui32_GetVersion() */
uint32 IC_ui32_GetVersion(void) {
    /*#[ operation IC_ui32_GetVersion() */
    return IC_TOPLEVEL_VERSION;
    /*#]*/
}


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_interface.c
*********************************************************************/
