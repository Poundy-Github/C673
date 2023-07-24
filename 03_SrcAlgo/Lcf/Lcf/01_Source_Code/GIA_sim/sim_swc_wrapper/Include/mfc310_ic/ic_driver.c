//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_driver.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:49CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_driver
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_driver.c
//  LOGIN:           uidt3974  
//  
//  Disable QAC Messages:
//  
//    Possible dereference of NULL pointer.
//     PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Wed, 1, Aug 2012  3:17 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_driver.h"
/*## dependency ic_errmanager */
#include "ic_errmanager.h"
/*## dependency ic_registers_bitmasks */
#include "ic_registers_bitmasks.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_driver */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## type IC_S_SensorDrvObj */
typedef struct IC_S_SensorDrvObj {
    const IC_S_RegBuff * apRb_RegsIn[ICCFG_NUM_IMAGERS];		/*## attribute apRb_RegsIn */
    IC_S_RegBuff * apRb_RegsOut[ICCFG_NUM_IMAGERS];		/*## attribute apRb_RegsOut */
    const IC_S_RegBuff * pRb_RegsInMaster;		/*## attribute pRb_RegsInMaster */
    const IC_S_RegBuff * pRb_RegsOutMaster;		/*## attribute pRb_RegsOutMaster */
    boolean b_DriverInitialized;		/*## attribute b_DriverInitialized */
    float32 f32_CorrectionFactor;		/*## attribute f32_CorrectionFactor */
    float32 f32_DigitalGain;		/*## attribute f32_DigitalGain */
    IC_Fct_v_SetRegister pfct_v_SetRegister;		/*## attribute pfct_v_SetRegister */
} IC_S_SensorDrvObj;

//  PRQA S 3625,3232,5013 2
/*## attribute pch_ModuleName */
static char const * const pch_ModuleName = "DRV";

/*## attribute IMGDRV_cf32_CORR_FACT_MAX */
static const float32 IMGDRV_cf32_CORR_FACT_MAX = 7.96875f;

/*## attribute IMGDRV_cf32_CORR_FACT_MIN */
static const float32 IMGDRV_cf32_CORR_FACT_MIN = 0.03125f;

/*## attribute IMGDRV_cf32_GLOB_GAIN_PHYS2RAW */
static const float32 IMGDRV_cf32_GLOB_GAIN_PHYS2RAW = 32.0f;

//  Static file scope is intended, even when only used it in one function:
//  PRQA S 3218 2
/*## attribute IMGDRV_cui16_GLOB_GAIN_MAX */
static const uint16 IMGDRV_cui16_GLOB_GAIN_MAX = 0xFF;

//  Static file scope is intended, even when only used it in one function:
//  PRQA S 3218 2
/*## attribute IMGDRV_cui16_GLOB_GAIN_MIN */
static const uint16 IMGDRV_cui16_GLOB_GAIN_MIN = 0x01;

//  Driver object for Imager Driver
/*## attribute IMGDRV_s_DrvObj */
static IC_S_SensorDrvObj IMGDRV_s_DrvObj;

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetRegister
//  
//  
//  
//  Parameter:     const IMGREG_E_SENSOR_REG e_Reg   <In>
//  
//  
//  Parameter:     const uint16 ui16_Value   <In>
//  
//    
//  
//  return         IC_INLINE_VOID
//**************************************************************************** */
/*## operation IMGDRV_v_SetRegister(const IMGREG_E_SENSOR_REG,const uint16) */
static IC_INLINE_VOID IMGDRV_v_SetRegister(const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_Value);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetRegisterSingle
//  
//  
//  
//  Parameter:     const IMGREG_E_SENSOR_REG e_Reg   <In>
//  
//  
//  Parameter:     const uint16 ui16_Value   <In>
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         IC_INLINE_VOID
//**************************************************************************** */
/*## operation IMGDRV_v_SetRegisterSingle(const IMGREG_E_SENSOR_REG,const uint16,const IC_E_Imager) */
static IC_INLINE_VOID IMGDRV_v_SetRegisterSingle(const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_Value, const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetRegisterBits
//  
//  Sets bits of an register to one specified by a bit-mask.
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     const IMGREG_E_SENSOR_REG e_Reg   <In>
//  
//  
//  Parameter:     const uint16 ui16_BitMask   <In>
//  
//    
//  
//  return         IC_INLINE_VOID
//**************************************************************************** */
/*## operation IMGDRV_v_SetRegisterBits(const IC_E_Imager,const IMGREG_E_SENSOR_REG,const uint16) */
static IC_INLINE_VOID IMGDRV_v_SetRegisterBits(const IC_E_Imager e_Imager, const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_BitMask);

//*****************************************************************************
//  Functionname:  IMGDRV_v_ClearRegisterBits
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     const IMGREG_E_SENSOR_REG e_Reg   <In>
//  
//  
//  Parameter:     const uint16 ui16_BitMask   <In>
//  
//    
//  
//  return         IC_INLINE_VOID
//**************************************************************************** */
/*## operation IMGDRV_v_ClearRegisterBits(const IC_E_Imager,const IMGREG_E_SENSOR_REG,const uint16) */
static IC_INLINE_VOID IMGDRV_v_ClearRegisterBits(const IC_E_Imager e_Imager, const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_BitMask);

//*****************************************************************************
//  Functionname:  IMGDRV_v_ClearAndSetRegisterBits
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     const IMGREG_E_SENSOR_REG e_Reg   <In>
//  
//  
//  Parameter:     const uint16 ui16_BitMaskClear   <In>
//  
//  
//  Parameter:     const uint16 ui16_BitMaskSet   <In>
//  
//    
//  
//  return         IC_INLINE_VOID
//**************************************************************************** */
/*## operation IMGDRV_v_ClearAndSetRegisterBits(const IC_E_Imager,const IMGREG_E_SENSOR_REG,const uint16,const uint16) */
static IC_INLINE_VOID IMGDRV_v_ClearAndSetRegisterBits(const IC_E_Imager e_Imager, const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_BitMaskClear, const uint16 ui16_BitMaskSet);

//*****************************************************************************
//  Functionname:  IMGDRV_f32_GlobGainFromRaw
//  
//  
//  
//  Parameter:     const uint16 ui16_RegGain   <In>
//  
//    
//  
//  return         float32
//**************************************************************************** */
/*## operation IMGDRV_f32_GlobGainFromRaw(const uint16) */
static float32 IMGDRV_f32_GlobGainFromRaw(const uint16 ui16_RegGain);

//*****************************************************************************
//  Functionname:  IMGDRV_ui16_DetermineGlobGain
//  
//  
//  
//  Parameter:     const float32 f32_GlobalGain   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IMGDRV_ui16_DetermineGlobGain(const float32) */
static uint16 IMGDRV_ui16_DetermineGlobGain(const float32 f32_GlobalGain);

//*****************************************************************************
//  Functionname:  IMGDRV_v_UpdateGlobalGains
//  
//  
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_UpdateGlobalGains() */
static void IMGDRV_v_UpdateGlobalGains(void);

//*****************************************************************************
//  Functionname:  IMGDRV_ui16_IntTimeRatioToRaw
//  
//  
//  
//  Parameter:     const IC_E_INTEGR_RATIO e_Ratio   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IMGDRV_ui16_IntTimeRatioToRaw(const IC_E_INTEGR_RATIO) */
static uint16 IMGDRV_ui16_IntTimeRatioToRaw(const IC_E_INTEGR_RATIO e_Ratio);

//*****************************************************************************
//  Functionname:  IMGDRV_e_IntTimeRatioFromRaw
//  
//  
//  
//  Parameter:     const uint16 ui16_RawValue   <In>
//  
//    
//  
//  return         IC_E_INTEGR_RATIO
//**************************************************************************** */
/*## operation IMGDRV_e_IntTimeRatioFromRaw(const uint16) */
static IC_E_INTEGR_RATIO IMGDRV_e_IntTimeRatioFromRaw(const uint16 ui16_RawValue);

/*## operation IMGDRV_e_Init(const IC_Fct_v_SetRegister) */
IC_E_ERROR IMGDRV_e_Init(const IC_Fct_v_SetRegister pfct_v_SetReg) {
    /*#[ operation IMGDRV_e_Init(const IC_Fct_v_SetRegister) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    IMGREG_E_ERROR e_IMGREG_Ret = IMGREG_e_ERR_OK;
    
    IC_v_ZEROMEM(IMGDRV_s_DrvObj);
    IMGDRV_s_DrvObj.f32_CorrectionFactor         = 1.0f; // PRQA S 3121
    IMGDRV_s_DrvObj.f32_DigitalGain              = 1.0f; // PRQA S 3121
    
    // Initialize register table
    e_IMGREG_Ret = IMGREG_e_Init();
    if (e_IMGREG_Ret != IMGREG_e_ERR_OK)
    {
      e_Ret = IC_e_ERR_REGISTERTABLE;
    }
    else
    {
      // Copy function pointers
      IMGDRV_s_DrvObj.pfct_v_SetRegister = pfct_v_SetReg;
    
      // Init done
      IMGDRV_s_DrvObj.b_DriverInitialized = b_TRUE;
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation IMGDRV_v_SetRegister(const IMGREG_E_SENSOR_REG,const uint16) */
static IC_INLINE_VOID IMGDRV_v_SetRegister(const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_Value) {
    /*#[ operation IMGDRV_v_SetRegister(const IMGREG_E_SENSOR_REG,const uint16) */
    IMGDRV_v_SetRegisterSingle(e_Reg, ui16_Value, IC_e_IMAGER_ALL);
    /*#]*/
}

/*## operation IMGDRV_v_SetRegisterSingle(const IMGREG_E_SENSOR_REG,const uint16,const IC_E_Imager) */
static IC_INLINE_VOID IMGDRV_v_SetRegisterSingle(const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_Value, const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_v_SetRegisterSingle(const IMGREG_E_SENSOR_REG,const uint16,const IC_E_Imager) */
    IMGDRV_s_DrvObj.pfct_v_SetRegister(e_Reg, ui16_Value, e_Imager);
    /*#]*/
}

/*## operation IMGDRV_v_SetRegisterBits(const IC_E_Imager,const IMGREG_E_SENSOR_REG,const uint16) */
static IC_INLINE_VOID IMGDRV_v_SetRegisterBits(const IC_E_Imager e_Imager, const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_BitMask) {
    /*#[ operation IMGDRV_v_SetRegisterBits(const IC_E_Imager,const IMGREG_E_SENSOR_REG,const uint16) */
    if ((IC_e_IMAGER_ALL == e_Imager) || (IC_e_IMAGER_RIGHT == e_Imager))
    {
      IMGDRV_v_SetRegisterSingle(e_Reg, IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_RIGHT]->aRegs[e_Reg] | ui16_BitMask, IC_e_IMAGER_RIGHT);
    }
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    if ((IC_e_IMAGER_ALL == e_Imager) || (IC_e_IMAGER_LEFT == e_Imager))
    {
      IMGDRV_v_SetRegisterSingle(e_Reg, IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_LEFT]->aRegs[e_Reg] | ui16_BitMask, IC_e_IMAGER_LEFT);
    }
    #endif
    /*#]*/
}

/*## operation IMGDRV_v_ClearRegisterBits(const IC_E_Imager,const IMGREG_E_SENSOR_REG,const uint16) */
static IC_INLINE_VOID IMGDRV_v_ClearRegisterBits(const IC_E_Imager e_Imager, const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_BitMask) {
    /*#[ operation IMGDRV_v_ClearRegisterBits(const IC_E_Imager,const IMGREG_E_SENSOR_REG,const uint16) */
    uint16 ui16_RegVal;
    if ((IC_e_IMAGER_ALL == e_Imager) || (IC_e_IMAGER_RIGHT == e_Imager))
    {
      ui16_RegVal = (IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_RIGHT]->aRegs[e_Reg]) & (uint16)(~ui16_BitMask);
      IMGDRV_v_SetRegisterSingle(e_Reg, ui16_RegVal, IC_e_IMAGER_RIGHT);
    }
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    if ((IC_e_IMAGER_ALL == e_Imager) || (IC_e_IMAGER_LEFT == e_Imager))
    {
      ui16_RegVal = IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_LEFT]->aRegs[e_Reg] & (uint16)(~ui16_BitMask);
      IMGDRV_v_SetRegisterSingle(e_Reg, ui16_RegVal, IC_e_IMAGER_LEFT);
    }
    #endif
    /*#]*/
}

/*## operation IMGDRV_v_ClearAndSetRegisterBits(const IC_E_Imager,const IMGREG_E_SENSOR_REG,const uint16,const uint16) */
static IC_INLINE_VOID IMGDRV_v_ClearAndSetRegisterBits(const IC_E_Imager e_Imager, const IMGREG_E_SENSOR_REG e_Reg, const uint16 ui16_BitMaskClear, const uint16 ui16_BitMaskSet) {
    /*#[ operation IMGDRV_v_ClearAndSetRegisterBits(const IC_E_Imager,const IMGREG_E_SENSOR_REG,const uint16,const uint16) */
    uint16 ui16_RegVal;
    if ((IC_e_IMAGER_ALL == e_Imager) || (IC_e_IMAGER_RIGHT == e_Imager))
    {
      ui16_RegVal = (IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_RIGHT]->aRegs[e_Reg] & (uint16)(~ui16_BitMaskClear)) | ui16_BitMaskSet;
      IMGDRV_v_SetRegisterSingle(e_Reg, ui16_RegVal, IC_e_IMAGER_RIGHT);
    }
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    if ((IC_e_IMAGER_ALL == e_Imager) || (IC_e_IMAGER_LEFT == e_Imager))
    {
      ui16_RegVal = (IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_LEFT]->aRegs[e_Reg] & (uint16)(~ui16_BitMaskClear)) | ui16_BitMaskSet;
      IMGDRV_v_SetRegisterSingle(e_Reg, ui16_RegVal, IC_e_IMAGER_LEFT);
    }
    #endif
    /*#]*/
}

/*## operation IMGDRV_v_SetRegisterInput(const IC_S_RegBuff * const,const IC_E_Imager) */
void IMGDRV_v_SetRegisterInput(const IC_S_RegBuff * const pRb_Regs, const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_v_SetRegisterInput(const IC_S_RegBuff * const,const IC_E_Imager) */
    // Check for valid imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      IMGDRV_s_DrvObj.apRb_RegsIn[e_Imager] = pRb_Regs;
      if (IC_ce_MASTER_IMAGER == e_Imager)
      {
        IMGDRV_s_DrvObj.pRb_RegsInMaster = pRb_Regs;
      }
    }
    /*#]*/
}

/*## operation IMGDRV_v_SetRegisterOutput(IC_S_RegBuff * const,const IC_E_Imager) */
void IMGDRV_v_SetRegisterOutput(IC_S_RegBuff * const pRb_Regs, const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_v_SetRegisterOutput(IC_S_RegBuff * const,const IC_E_Imager) */
    // Check for valid imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      IMGDRV_s_DrvObj.apRb_RegsOut[e_Imager] = pRb_Regs;
      if (IC_ce_MASTER_IMAGER == e_Imager)
      {
        IMGDRV_s_DrvObj.pRb_RegsOutMaster = pRb_Regs;
      }
    }
    /*#]*/
}

/*## operation IMGDRV_f32_GlobGainFromRaw(const uint16) */
static float32 IMGDRV_f32_GlobGainFromRaw(const uint16 ui16_RegGain) {
    /*#[ operation IMGDRV_f32_GlobGainFromRaw(const uint16) */
    return (float32)ui16_RegGain / IMGDRV_cf32_GLOB_GAIN_PHYS2RAW;
    /*#]*/
}

/*## operation IMGDRV_ui16_DetermineGlobGain(const float32) */
static uint16 IMGDRV_ui16_DetermineGlobGain(const float32 f32_GlobalGain) {
    /*#[ operation IMGDRV_ui16_DetermineGlobGain(const float32) */
    uint16 ui16_RegGain = 0;
    
    // reg_gain   = 0bxxx.yyyyy
    //
    // => so we get (0b100000 = 32):
    // reg_gain   = 32 * f32_GlobalGain + 0.5
    //                                   ^^^^^ 0.5 respects rounding-errors
    ui16_RegGain = (uint16)((IMGDRV_cf32_GLOB_GAIN_PHYS2RAW * f32_GlobalGain) + 0.5f); // PRQA S 4119,3121
    
    // Saturate if out of range (error checking done at caller)
    if (ui16_RegGain > IMGDRV_cui16_GLOB_GAIN_MAX)
    {
      ui16_RegGain = IMGDRV_cui16_GLOB_GAIN_MAX;
    }
    if (ui16_RegGain <= IMGDRV_cui16_GLOB_GAIN_MIN)
    {
      ui16_RegGain = IMGDRV_cui16_GLOB_GAIN_MIN;
    }
    return ui16_RegGain;
    /*#]*/
}

/*## operation IMGDRV_v_UpdateGlobalGains() */
static void IMGDRV_v_UpdateGlobalGains(void) {
    /*#[ operation IMGDRV_v_UpdateGlobalGains() */
    uint16 ui16_RegGlobGainLeft;
    uint16 ui16_RegGlobGainRight;
    
    // The CorrectionFactor is the ratio gain(right)/gain(left),
    // so a value >1.0 means the right imager has a higher gain and the
    // _left's_ digital gain must be _increased_ by this factor.
    float32 f32_GlobGainRight = IMGDRV_s_DrvObj.f32_DigitalGain;
    float32 f32_GlobGainLeft  = f32_GlobGainRight * IMGDRV_s_DrvObj.f32_CorrectionFactor;
    
    // Limit gains to valid range of sensor
    if (f32_GlobGainLeft > IMGDRV_cf32_CORR_FACT_MAX)
    {
      f32_GlobGainLeft = IMGDRV_cf32_CORR_FACT_MAX;
    }
    else if (f32_GlobGainLeft < IMGDRV_cf32_CORR_FACT_MIN)
    {
      f32_GlobGainLeft = IMGDRV_cf32_CORR_FACT_MIN;
    }
    else
    {
      // Value is within limits, do nothing
    }
    
    // Limit gains to valid range of sensor
    if (f32_GlobGainRight > IMGDRV_cf32_CORR_FACT_MAX)
    {
      f32_GlobGainRight = IMGDRV_cf32_CORR_FACT_MAX;
    }
    else if (f32_GlobGainRight < IMGDRV_cf32_CORR_FACT_MIN)
    {
      f32_GlobGainRight = IMGDRV_cf32_CORR_FACT_MIN;
    }
    else
    {
      // Value is within limits, do nothing
    }
    
    // Calculate register values
    ui16_RegGlobGainLeft  = IMGDRV_ui16_DetermineGlobGain(f32_GlobGainLeft);
    ui16_RegGlobGainRight = IMGDRV_ui16_DetermineGlobGain(f32_GlobGainRight);
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_GLOBAL_GAIN, ui16_RegGlobGainLeft,  IC_e_IMAGER_LEFT);
    #endif
    IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_GLOBAL_GAIN, ui16_RegGlobGainRight, IC_e_IMAGER_RIGHT);
    
    // Setting global gain register equals setting all four color-specific gain
    // registers to the same value. To prevent register-checks from failing we have to
    // update our output-buffers for each color gain register:
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_LEFT]->aRegs[IMGREG_e_REG_GREEN1_GAIN]  = ui16_RegGlobGainLeft;
    IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_LEFT]->aRegs[IMGREG_e_REG_BLUE_GAIN]    = ui16_RegGlobGainLeft;
    IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_LEFT]->aRegs[IMGREG_e_REG_RED_GAIN]     = ui16_RegGlobGainLeft;
    IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_LEFT]->aRegs[IMGREG_e_REG_GREEN2_GAIN]  = ui16_RegGlobGainLeft;
    #endif
    IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_RIGHT]->aRegs[IMGREG_e_REG_GREEN1_GAIN] = ui16_RegGlobGainRight;
    IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_RIGHT]->aRegs[IMGREG_e_REG_BLUE_GAIN]   = ui16_RegGlobGainRight;
    IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_RIGHT]->aRegs[IMGREG_e_REG_RED_GAIN]    = ui16_RegGlobGainRight;
    IMGDRV_s_DrvObj.apRb_RegsOut[IC_e_IMAGER_RIGHT]->aRegs[IMGREG_e_REG_GREEN2_GAIN] = ui16_RegGlobGainRight;
    /*#]*/
}

/*## operation IMGDRV_e_SetCorrectionFactor(const float32) */
IC_E_ERROR IMGDRV_e_SetCorrectionFactor(const float32 f32_CorrectionFactor) {
    /*#[ operation IMGDRV_e_SetCorrectionFactor(const float32) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // Setup pointer for interpretation of float32 correction factor as int, as
    // it can be used to test against NaN or illegal values resulting from corrupted
    // /incomplete PPAR.
    //
    // PRQA S 0310 1
    uint32 const * const pui32_CorrFactReinterprAsInt = (uint32 const *)(&f32_CorrectionFactor);
    
    // Check correction factor
    if (   (IC_BITMASK_U32 == *pui32_CorrFactReinterprAsInt) /* Check for NaN */
         ||(IMGDRV_cf32_CORR_FACT_MAX < f32_CorrectionFactor)
         ||(IMGDRV_cf32_CORR_FACT_MIN > f32_CorrectionFactor))
    {
      e_Ret = IC_e_ERR_INVALID_CORRECTION_FACTOR;
    }
    else
    {
      // Copy correction-factor (ratio right to left) and update gains
      IMGDRV_s_DrvObj.f32_CorrectionFactor = f32_CorrectionFactor;
      IMGDRV_v_UpdateGlobalGains();
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation IMGDRV_e_SetCROI(const IC_E_Imager,const IC_S_Croi * const) */
IC_E_ERROR IMGDRV_e_SetCROI(const IC_E_Imager e_Imager, const IC_S_Croi * const ps_Croi) {
    /*#[ operation IMGDRV_e_SetCROI(const IC_E_Imager,const IC_S_Croi * const) */
    IC_E_ERROR e_Ret          = IC_e_ERR_OK;
    const uint16 ui16_XStart  = ps_Croi->ui16_StartX;
    const uint16 ui16_YStart  = ps_Croi->ui16_StartY;
    const uint16 ui16_XWidth  = ps_Croi->ui16_Width;
    const uint16 ui16_YHeight = ps_Croi->ui16_Height;
    uint16 ui16_XAddrEnd      = 0;
    uint16 ui16_YAddrEnd      = 0;
    
    // Calc *_ADDR_END
    ui16_XAddrEnd = (ui16_XStart + ui16_XWidth ) - 1;
    ui16_YAddrEnd = (ui16_YStart + ui16_YHeight) - 1;
    
    // Check X start
    if (ui16_XStart < ICCFG_cui16_CROI_STARTX_MIN)
    {
      e_Ret = IC_e_ERR_XSTART;
    }
    // Check Y start
    else if (ui16_YStart < ICCFG_cui16_CROI_STARTY_MIN)
    {
      e_Ret = IC_e_ERR_YSTART;
    }
    // Check width
    else if (ui16_XAddrEnd > ICCFG_cui16_CROI_ENDX_MAX)
    {
      e_Ret = IC_e_ERR_CROI_WIDTH;
    }
    // Check height
    else if (ui16_YAddrEnd > ICCFG_cui16_CROI_ENDY_MAX)
    {
      e_Ret = IC_e_ERR_CROI_HEIGHT;
    }
    else
    {
      // Set register values
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_X_ADDR_START, ui16_XStart, e_Imager);
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_Y_ADDR_START, ui16_YStart, e_Imager);
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_X_ADDR_END, ui16_XAddrEnd, e_Imager);
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_Y_ADDR_END, ui16_YAddrEnd, e_Imager);
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation IMGDRV_v_SetDCG(const IC_E_DCG_STATE) */
void IMGDRV_v_SetDCG(const IC_E_DCG_STATE e_DCGstate) {
    /*#[ operation IMGDRV_v_SetDCG(const IC_E_DCG_STATE) */
    if(IC_e_DCG_HIGH == e_DCGstate)
    {
      IMGDRV_v_SetRegisterBits(IC_e_IMAGER_ALL, IMGREG_e_REG_AE_CTRL_REG, IMGREG_cui16_BITMASK_AE_CTRL_REG_DCG_MANUAL_SET);
    }
    else
    {
      IMGDRV_v_ClearRegisterBits(IC_e_IMAGER_ALL, IMGREG_e_REG_AE_CTRL_REG, IMGREG_cui16_BITMASK_AE_CTRL_REG_DCG_MANUAL_SET);
    }
    /*#]*/
}

/*## operation IMGDRV_e_GetDCGState() */
IC_E_DCG_STATE IMGDRV_e_GetDCGState(void) {
    /*#[ operation IMGDRV_e_GetDCGState() */
    IC_E_DCG_STATE e_Ret;
    if ((IMGDRV_s_DrvObj.pRb_RegsInMaster->aRegs[IMGREG_e_REG_AE_CTRL_REG] & IMGREG_cui16_BITMASK_AE_CTRL_REG_DCG_MANUAL_SET) != 0)
    {
      e_Ret = IC_e_DCG_HIGH;
    }
    else
    {
      e_Ret = IC_e_DCG_LOW;
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation IMGDRV_v_SetDigitalGain(const float32) */
void IMGDRV_v_SetDigitalGain(const float32 f32_DigitalGain) {
    /*#[ operation IMGDRV_v_SetDigitalGain(const float32) */
    IMGDRV_s_DrvObj.f32_DigitalGain = f32_DigitalGain;
    IMGDRV_v_UpdateGlobalGains();
    /*#]*/
}

/*## operation IMGDRV_f32_GetDigitalGainRight() */
float32 IMGDRV_f32_GetDigitalGainRight(void) {
    /*#[ operation IMGDRV_f32_GetDigitalGainRight() */
    return IMGDRV_f32_GlobGainFromRaw(IMGDRV_s_DrvObj.pRb_RegsInMaster->aRegs[IMGREG_e_REG_GLOBAL_GAIN]);
    /*#]*/
}

/*## operation IMGDRV_v_SetAnalogGain(const IC_E_ANALOG_GAIN) */
void IMGDRV_v_SetAnalogGain(const IC_E_ANALOG_GAIN e_AnalogGain) {
    /*#[ operation IMGDRV_v_SetAnalogGain(const IC_E_ANALOG_GAIN) */
    IMGDRV_v_ClearAndSetRegisterBits(
            IC_e_IMAGER_ALL,
            IMGREG_e_REG_DIGITAL_TEST,
            IMGREG_cui16_BITMASK_DIGITAL_TEST_COL_GAIN,
            ((uint16)e_AnalogGain << IMGREG_cui16_BITSHIFT_DIGITAL_TEST_COL_GAIN) & IMGREG_cui16_BITMASK_DIGITAL_TEST_COL_GAIN
        );
    /*#]*/
}

/*## operation IMGDRV_v_SetColCorrRetriggDCG(const boolean) */
void IMGDRV_v_SetColCorrRetriggDCG(const boolean b_TrigOnDCG) {
    /*#[ operation IMGDRV_v_SetColCorrRetriggDCG(const boolean) */
    IMGDRV_v_ClearAndSetRegisterBits(
            IC_e_IMAGER_ALL,
            IMGREG_e_REG_DIGITAL_CTRL,
            IMGREG_cui16_BITMASK_DIGITAL_CTRL_ENABLE_DCG_COLCORR_RETRIGG,
            (b_TrigOnDCG << IMGREG_cui16_BITSHIFT_DIGITAL_CTRL_ENABLE_DCG_COLCORR_RETRIGG) & IMGREG_cui16_BITMASK_DIGITAL_CTRL_ENABLE_DCG_COLCORR_RETRIGG
        );
    /*#]*/
}

/*## operation IMGDRV_v_SetColCorrCorrectAlways(const boolean) */
void IMGDRV_v_SetColCorrCorrectAlways(const boolean b_CorrectAlways) {
    /*#[ operation IMGDRV_v_SetColCorrCorrectAlways(const boolean) */
    IMGDRV_v_ClearAndSetRegisterBits(
            IC_e_IMAGER_ALL,
            IMGREG_e_REG_DIGITAL_CTRL,
            IMGREG_cui16_BITMASK_DIGITAL_CTRL_COL_CORR_CORRECT_ALWAYS,
            (b_CorrectAlways << IMGREG_cui16_BITSHIFT_DIGITAL_CTRL_COL_CORR_CORRECT_ALWAYS) & IMGREG_cui16_BITMASK_DIGITAL_CTRL_COL_CORR_CORRECT_ALWAYS
        );
    /*#]*/
}

/*## operation IMGDRV_v_SetFrameId(const uint16,const IC_E_Imager) */
void IMGDRV_v_SetFrameId(const uint16 ui16_FrameId, const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_v_SetFrameId(const uint16,const IC_E_Imager) */
    IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_STAT_FRAME_ID, ui16_FrameId, e_Imager);
    /*#]*/
}

/*## operation IMGDRV_e_SetICROI(const IC_S_Roi * const) */
IC_E_ERROR IMGDRV_e_SetICROI(const IC_S_Roi * const ps_Roi) {
    /*#[ operation IMGDRV_e_SetICROI(const IC_S_Roi * const) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // NOTE: Checking whether IC-ROI fits inside the CROI is removed here because
    // AE_ROI registers are not frame-sync'd whereas Y_ADDR_START etc are.
    // So this check would cause false-errors in double-frame mode, because
    // both register-sets belong to different frames. Check must be done in
    // top-level modules where the corresponding CROI is known.
    
    // Check pointer
    if (NULL == ps_Roi)
    {
      e_Ret = IC_e_ERR_NULLPOINTER;
    }
    else
    {
      // Set the registers
      IMGDRV_v_SetRegister(IMGREG_e_REG_AE_ROI_X_START_OFFSET, ps_Roi->ui16_StartX);
      IMGDRV_v_SetRegister(IMGREG_e_REG_AE_ROI_Y_START_OFFSET, ps_Roi->ui16_StartY);
      IMGDRV_v_SetRegister(IMGREG_e_REG_AE_ROI_X_SIZE, ps_Roi->ui16_Width);
      IMGDRV_v_SetRegister(IMGREG_e_REG_AE_ROI_Y_SIZE, ps_Roi->ui16_Height);
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation IMGDRV_v_GetIcRoi(IC_S_Roi * const) */
void IMGDRV_v_GetIcRoi(IC_S_Roi * const ps_Roi) {
    /*#[ operation IMGDRV_v_GetIcRoi(IC_S_Roi * const) */
    if (NULL != ps_Roi)
    {
      ps_Roi->ui16_StartX = IMGDRV_s_DrvObj.pRb_RegsInMaster->aRegs[IMGREG_e_REG_AE_ROI_X_START_OFFSET];
      ps_Roi->ui16_StartY = IMGDRV_s_DrvObj.pRb_RegsInMaster->aRegs[IMGREG_e_REG_AE_ROI_Y_START_OFFSET];
      ps_Roi->ui16_Width  = IMGDRV_s_DrvObj.pRb_RegsInMaster->aRegs[IMGREG_e_REG_AE_ROI_X_SIZE];
      ps_Roi->ui16_Height = IMGDRV_s_DrvObj.pRb_RegsInMaster->aRegs[IMGREG_e_REG_AE_ROI_Y_SIZE];
    }
    /*#]*/
}

/*## operation IMGDRV_e_SetExposureTime(const uint16) */
IC_E_ERROR IMGDRV_e_SetExposureTime(const uint16 ui16_ExposureTimeUs) {
    /*#[ operation IMGDRV_e_SetExposureTime(const uint16) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    uint16 ui16_ExposureCoarse_LineNum = (uint16) 0;
    
    // Precondition checks
    if (b_FALSE == IMGDRV_s_DrvObj.b_DriverInitialized)
    {
    	e_Ret = IC_e_ERR_NOTINIT;
    }
    else
    {
      // Find number of lines
      ui16_ExposureCoarse_LineNum = IMGDRV_ui16_UsToLines(ui16_ExposureTimeUs);
    
      // Postcondition: Exposure should not be bigger than frame time;
      if (IMGDRV_s_DrvObj.pRb_RegsOutMaster->aRegs[IMGREG_e_REG_FRAME_LENGTH_LINES] <= ui16_ExposureCoarse_LineNum)
      {
        e_Ret = IC_e_ERR_EXPOSURE_LINENUM;
      }
    
      // Postcondition: Exposure time (in lines) must not be zero
      if (ui16_ExposureCoarse_LineNum <= 0)
      {
        e_Ret = IC_e_ERR_EXPOSURE_LINENUM;
      }
    
      // Assign new value for coarse integration time register if there was no error
      if (IC_e_ERR_OK == e_Ret)
      {
        IMGDRV_v_SetRegister(IMGREG_e_REG_COARSE_INTEGRATION_TIME, ui16_ExposureCoarse_LineNum);
      }
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation IMGDRV_ui16_GetExposureTime() */
uint16 IMGDRV_ui16_GetExposureTime(void) {
    /*#[ operation IMGDRV_ui16_GetExposureTime() */
    const uint16 ui16_ExpTimeLines = IMGDRV_s_DrvObj.pRb_RegsInMaster->aRegs[IMGREG_e_REG_COARSE_INTEGRATION_TIME];
    const uint32 ui32_ExpTimeNs    = (uint32)ui16_ExpTimeLines * ICCFG_cui32_LineTimeNs;
    const uint16 ui16_ExpTimeUs    = (uint16)IC_ui32_CONV_ns_us(ui32_ExpTimeNs);
    return ui16_ExpTimeUs;
    /*#]*/
}

/*## operation IMGDRV_v_SetIntegrationTimeRatios(const IC_E_INTEGR_RATIO,const IC_E_INTEGR_RATIO) */
void IMGDRV_v_SetIntegrationTimeRatios(const IC_E_INTEGR_RATIO e_R1, const IC_E_INTEGR_RATIO e_R2) {
    /*#[ operation IMGDRV_v_SetIntegrationTimeRatios(const IC_E_INTEGR_RATIO,const IC_E_INTEGR_RATIO) */
    // Mask out relevant part of op-mode-ctrl register
    uint16 ui16_OpmodeCtrl;
    
    // Read current value of operation mode control register
    ui16_OpmodeCtrl = IMGDRV_s_DrvObj.pRb_RegsOutMaster->aRegs[IMGREG_e_REG_OPERATION_MODE_CTRL];
    
    // Clear bits which contains both ratios:
    //   PRQA S 0277 1
    ui16_OpmodeCtrl &= (uint16)(~(  IMGREG_cui16_BITMASK_OPERATION_MODE_CTRL_RATIO_T1_T2
                                  | IMGREG_cui16_BITMASK_OPERATION_MODE_CTRL_RATIO_T2_T3));
    
    // Set ratios and write back new register value
    ui16_OpmodeCtrl |= IMGDRV_ui16_IntTimeRatioToRaw(e_R1) << IMGREG_cui16_BITSHIFT_OPERATION_MODE_CTRL_RATIO_T1_T2;
    ui16_OpmodeCtrl |= IMGDRV_ui16_IntTimeRatioToRaw(e_R2) << IMGREG_cui16_BITSHIFT_OPERATION_MODE_CTRL_RATIO_T2_T3;
    IMGDRV_v_SetRegister(IMGREG_e_REG_OPERATION_MODE_CTRL, ui16_OpmodeCtrl);
    /*#]*/
}

/*## operation IMGDRV_v_GetIntegrationTimeRatios(IC_E_INTEGR_RATIO * const,IC_E_INTEGR_RATIO * const) */
void IMGDRV_v_GetIntegrationTimeRatios(IC_E_INTEGR_RATIO * const pe_R1, IC_E_INTEGR_RATIO * const pe_R2) {
    /*#[ operation IMGDRV_v_GetIntegrationTimeRatios(IC_E_INTEGR_RATIO * const,IC_E_INTEGR_RATIO * const) */
    
    // Get register value
    const uint16 ui16_OpmodeCtrl = IMGDRV_s_DrvObj.pRb_RegsInMaster->aRegs[IMGREG_e_REG_OPERATION_MODE_CTRL];
    
    // Extract RAW-values for R1 and R2
    const uint16 ui16_ValFromRegR1 = ((ui16_OpmodeCtrl & IMGREG_cui16_BITMASK_OPERATION_MODE_CTRL_RATIO_T1_T2)
                                                      >> IMGREG_cui16_BITSHIFT_OPERATION_MODE_CTRL_RATIO_T1_T2);
    const uint16 ui16_ValFromRegR2 = ((ui16_OpmodeCtrl & IMGREG_cui16_BITMASK_OPERATION_MODE_CTRL_RATIO_T2_T3)
                                                      >> IMGREG_cui16_BITSHIFT_OPERATION_MODE_CTRL_RATIO_T2_T3);
    
    // Convert to enum and set return values
    *pe_R1 = IMGDRV_e_IntTimeRatioFromRaw(ui16_ValFromRegR1);
    *pe_R2 = IMGDRV_e_IntTimeRatioFromRaw(ui16_ValFromRegR2);
    /*#]*/
}

/*## operation IMGDRV_v_SetTestpattern(const IC_E_Imager,const IMGDRV_E_SensorTestmode) */
void IMGDRV_v_SetTestpattern(const IC_E_Imager e_Imager, const IMGDRV_E_SensorTestmode e_TestMode) {
    /*#[ operation IMGDRV_v_SetTestpattern(const IC_E_Imager,const IMGDRV_E_SensorTestmode) */
    
    // This is some kind of a LUT, so magic numbers are symbolized by the enum names:
    // PRQA S 3120 TESTPATTERN_LUT
    switch (e_TestMode)
    {
    case IMGDRV_e_TESTPATTERN_NONE:
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_TEST_PATTERN_MODE, 0x0000u, e_Imager);
      break;
    case IMGDRV_e_TESTPATTERN_FADETOGRAY:
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_TEST_PATTERN_MODE, 0x0003u, e_Imager);
      break;
    case IMGDRV_e_TESTPATTERN_WALKING_ONES:
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_TEST_PATTERN_MODE, 0x0100u, e_Imager);
      break;
    case IMGDRV_e_TESTPATTERN_SOLID_PATTERN:
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_TEST_PATTERN_MODE, 0x0001u, e_Imager);
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_TEST_DATA_BLUE,    0x0000u, e_Imager);
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_TEST_DATA_GREENB,  0xffffu, e_Imager);
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_TEST_DATA_GREENR,  0xffffu, e_Imager);
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_TEST_DATA_RED,     0x0000u, e_Imager);
      break;
    default:
      break;
    }
    // PRQA L:TESTPATTERN_LUT
    /*#]*/
}

/*## operation IMGDRV_v_SetDatabusTestpattern(const uint16) */
void IMGDRV_v_SetDatabusTestpattern(const uint16 ui16_Pattern) {
    /*#[ operation IMGDRV_v_SetDatabusTestpattern(const uint16) */
    IMGDRV_v_SetRegister(IMGREG_e_REG_AE_DAMP_MAX_REG, ui16_Pattern);
    /*#]*/
}

/*## operation IMGDRV_ui16_GetDatabusTestpattern(const IC_E_Imager) */
uint16 IMGDRV_ui16_GetDatabusTestpattern(const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_ui16_GetDatabusTestpattern(const IC_E_Imager) */
    uint16 ui16_Ret = 0;
    
    // Check for valid imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      ui16_Ret = IMGDRV_s_DrvObj.apRb_RegsIn[e_Imager]->aRegs[IMGREG_e_REG_AE_DAMP_MAX_REG];
    }
    return ui16_Ret;
    /*#]*/
}

/*## operation IMGDRV_v_SetStreamingMode(const IMGDRV_E_StreamingMode) */
void IMGDRV_v_SetStreamingMode(const IMGDRV_E_StreamingMode e_Mode) {
    /*#[ operation IMGDRV_v_SetStreamingMode(const IMGDRV_E_StreamingMode) */
    uint16 ui16_RegVal = IMGDRV_s_DrvObj.pRb_RegsOutMaster->aRegs[IMGREG_e_REG_RESET_REGISTER];
    switch (e_Mode)
    {
    case IMGDRV_e_STREAMING_MODE_OFF:
      ui16_RegVal &= (uint16)~IMGREG_cui16_BITMASK_RESET_REGISTER_STREAM; // PRQA S 0277
      break;
    case IMGDRV_e_STREAMING_MODE_ON:
      ui16_RegVal |= IMGREG_cui16_BITMASK_RESET_REGISTER_STREAM | IMGREG_cui16_BITMASK_RESET_REGISTER_RESTART;
      break;
    case IMGDRV_e_STREAMING_MODE_EXTTRIGGER:
      // Disable continous streaming
      ui16_RegVal &= (uint16)~IMGREG_cui16_BITMASK_RESET_REGISTER_STREAM; // PRQA S 0277
    
      // Enable GPI Input-Buffers to allow usage of external trigger/exposure-pin.
      // Force PLL to be always enabled. This ensures that the PLL is already locked
      // when the external TRIGGER-Pin enables streaming. Otherwise left/right imager
      // are not in sync as the PLLs may take different times until they are locked.
      ui16_RegVal |=  IMGREG_cui16_BITMASK_RESET_REGISTER_RESTART
                  |   IMGREG_cui16_BITMASK_RESET_REGISTER_GPI_EN
                  |   IMGREG_cui16_BITMASK_RESET_REGISTER_FORCED_PLL_ON;
      break;
    default:
      // Defaults to streaming OFF
      ui16_RegVal &= (uint16)~IMGREG_cui16_BITMASK_RESET_REGISTER_STREAM; // PRQA S 0277
      break;
    }
    IMGDRV_v_SetRegister(IMGREG_e_REG_RESET_REGISTER, ui16_RegVal);
    /*#]*/
}

/*## operation IMGDRV_v_SetAllowReadFuseId(const boolean) */
void IMGDRV_v_SetAllowReadFuseId(const boolean b_AllowRead) {
    /*#[ operation IMGDRV_v_SetAllowReadFuseId(const boolean) */
    if (b_TRUE == b_AllowRead)
    {
      IMGDRV_v_SetRegisterBits  (IC_e_IMAGER_ALL, IMGREG_e_REG_RESET_REGISTER, IMGREG_cui16_BITMASK_RESET_REGISTER_REG_RD_EN);
    }
    else
    {
      IMGDRV_v_ClearRegisterBits(IC_e_IMAGER_ALL, IMGREG_e_REG_RESET_REGISTER, IMGREG_cui16_BITMASK_RESET_REGISTER_REG_RD_EN);
    }
    /*#]*/
}

/*## operation IMGDRV_e_GetTemperature(const IC_E_Imager,float32 * const) */
IC_E_ERROR IMGDRV_e_GetTemperature(const IC_E_Imager e_Imager, float32 * const pf32_Temp) {
    /*#[ operation IMGDRV_e_GetTemperature(const IC_E_Imager,float32 * const) */
    IC_E_ERROR e_Ret    = IC_e_ERR_OK;
    IC_S_RegBuff const *ps_Regs = NULL;
    uint16  ui16_RawCalib_A     = 0;
    uint16  ui16_RawCalib_B     = 0;
    uint16  ui16_RawCurTemp     = 0;
    uint16  ui16_TempCtrl       = 0;
    float32 f32_T0              = 0.0f; // PRQA S 3121
    float32 f32_TempSlope       = 0.0f; // PRQA S 3121
    float32 f32_Temp            = 0.0f; // PRQA S 3121
    
    #if (IC_TEMPCALIB_USE_FOURPOINT == 1)
    const float32             cf32_TEMP_A  =  55.0f;
    const float32             cf32_TEMP_B  = 105.0f;
    const IMGREG_E_SENSOR_REG e_RegCalib_A = IMGREG_e_REG_TEMPSENS_CALIB2; // 55deg value
    const IMGREG_E_SENSOR_REG e_RegCalib_B = IMGREG_e_REG_TEMPSENS_CALIB4; // 70deg value
    #else
    const float32             cf32_TEMP_A  = 55.0f;
    const float32             cf32_TEMP_B  = 70.0f;
    const IMGREG_E_SENSOR_REG e_RegCalib_A = IMGREG_e_REG_TEMPSENS_CALIB2; // 55deg value
    const IMGREG_E_SENSOR_REG e_RegCalib_B = IMGREG_e_REG_TEMPSENS_CALIB1; // 70deg value
    #endif
    
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      // Get register values for selected imager
      ps_Regs          = IMGDRV_s_DrvObj.apRb_RegsIn[e_Imager];
      ui16_RawCalib_A  = ps_Regs->aRegs[e_RegCalib_A];
      ui16_RawCalib_B  = ps_Regs->aRegs[e_RegCalib_B];
      ui16_RawCurTemp  = ps_Regs->aRegs[IMGREG_e_REG_TEMPSENS_DATA];
      ui16_TempCtrl    = ps_Regs->aRegs[IMGREG_e_REG_TEMPSENS_CTRL];
    
      // Check if temperature sensor is enabled
      if ( ((ui16_TempCtrl & IMGREG_cui16_BITMASK_TEMPSENS_CTRL_TEMP_START_CONVERSION) == 0)
        || ((ui16_TempCtrl & IMGREG_cui16_BITMASK_TEMPSENS_CTRL_TEMPSENS_POWER_ON) == 0))
      {
        e_Ret = IC_e_ERR_TEMPSENS_NOT_ENABLED;
      }
    
      // Go further if OK
      if (IC_e_ERR_OK == e_Ret)
      {
        // Calculate slope
        f32_TempSlope = (cf32_TEMP_B - cf32_TEMP_A) / (float32)(ui16_RawCalib_B - ui16_RawCalib_A);
    
        // Calculate T0 (Temp in Deg-C for raw-value 0x0000)
        f32_T0 = cf32_TEMP_A - (f32_TempSlope * (float32)ui16_RawCalib_A);
    
        // Calculate real temperature
        f32_Temp   = f32_T0 + (f32_TempSlope * (float32)ui16_RawCurTemp);
        *pf32_Temp = f32_Temp;
      }
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation IMGDRV_v_SetTimestampEmbedded(const IC_E_Imager,const uint64) */
void IMGDRV_v_SetTimestampEmbedded(const IC_E_Imager e_Imager, const uint64 ui64_TimeStamp) {
    /*#[ operation IMGDRV_v_SetTimestampEmbedded(const IC_E_Imager,const uint64) */
    const uint16 cui16_BITS_01 = (uint16)((ui64_TimeStamp >> IC_BITSHIFT_0BYTE) & IC_BITMASK_U16); // LSBs
    const uint16 cui16_BITS_23 = (uint16)((ui64_TimeStamp >> IC_BITSHIFT_2BYTE) & IC_BITMASK_U16);
    const uint16 cui16_BITS_45 = (uint16)((ui64_TimeStamp >> IC_BITSHIFT_4BYTE) & IC_BITMASK_U16);
    const uint16 cui16_BITS_67 = (uint16)((ui64_TimeStamp >> IC_BITSHIFT_6BYTE) & IC_BITMASK_U16); // MSBs
    
    IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_AE_LUMA_TARGET_REG, cui16_BITS_01, e_Imager);
    IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_AE_HIST_TARGET_REG, cui16_BITS_23, e_Imager);
    IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_AE_DAMP_OFFSET_REG, cui16_BITS_45, e_Imager);
    IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_AE_DAMP_GAIN_REG,   cui16_BITS_67, e_Imager);
    /*#]*/
}

/*## operation IMGDRV_ui64_GetTimestampEmbedded(const IC_E_Imager) */
uint64 IMGDRV_ui64_GetTimestampEmbedded(const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_ui64_GetTimestampEmbedded(const IC_E_Imager) */
    IC_S_RegBuff const * ps_Regs;
    uint64 ui64_TimestampUs = 0;
    
    // Check for valid imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      ps_Regs = IMGDRV_s_DrvObj.apRb_RegsIn[e_Imager];
    
      ui64_TimestampUs = (((uint64)ps_Regs->aRegs[IMGREG_e_REG_AE_LUMA_TARGET_REG]) << IC_BITSHIFT_0BYTE)
                       | (((uint64)ps_Regs->aRegs[IMGREG_e_REG_AE_HIST_TARGET_REG]) << IC_BITSHIFT_2BYTE)
                       | (((uint64)ps_Regs->aRegs[IMGREG_e_REG_AE_DAMP_OFFSET_REG]) << IC_BITSHIFT_4BYTE)
                       | (((uint64)ps_Regs->aRegs[IMGREG_e_REG_AE_DAMP_GAIN_REG])   << IC_BITSHIFT_6BYTE);
    }
    return ui64_TimestampUs;
    /*#]*/
}

/*## operation IMGDRV_v_SetFrameHeightTotal(const IC_E_Imager,const uint16) */
void IMGDRV_v_SetFrameHeightTotal(const IC_E_Imager e_Imager, const uint16 ui16_LinesTotal) {
    /*#[ operation IMGDRV_v_SetFrameHeightTotal(const IC_E_Imager,const uint16) */
    // Check for valid imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      IMGDRV_v_SetRegisterSingle(IMGREG_e_REG_FRAME_LENGTH_LINES, ui16_LinesTotal, e_Imager);
    }
    /*#]*/
}

/*## operation IMGDRV_ui16_GetImageHeightTotalR() */
uint16 IMGDRV_ui16_GetImageHeightTotalR(void) {
    /*#[ operation IMGDRV_ui16_GetImageHeightTotalR() */
    return IMGDRV_s_DrvObj.pRb_RegsInMaster->aRegs[IMGREG_e_REG_FRAME_LENGTH_LINES];
    /*#]*/
}

/*## operation IMGDRV_ui64_GetFuseId(const IC_E_Imager) */
uint64 IMGDRV_ui64_GetFuseId(const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_ui64_GetFuseId(const IC_E_Imager) */
    uint64 ui64_FuseId = 0;
    IC_S_RegBuff const * ps_Regs = NULL;
    
    // Check for valid imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      ps_Regs = IMGDRV_s_DrvObj.apRb_RegsIn[e_Imager];
      ui64_FuseId = ((uint64)ps_Regs->aRegs[IMGREG_e_REG_FUSE_ID1] << IC_BITSHIFT_0BYTE)
                  | ((uint64)ps_Regs->aRegs[IMGREG_e_REG_FUSE_ID2] << IC_BITSHIFT_2BYTE)
                  | ((uint64)ps_Regs->aRegs[IMGREG_e_REG_FUSE_ID3] << IC_BITSHIFT_4BYTE)
                  | ((uint64)ps_Regs->aRegs[IMGREG_e_REG_FUSE_ID4] << IC_BITSHIFT_6BYTE);
    }
    
    return ui64_FuseId;
    /*#]*/
}

/*## operation IMGDRV_ui16_GetModelId(const IC_E_Imager) */
uint16 IMGDRV_ui16_GetModelId(const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_ui16_GetModelId(const IC_E_Imager) */
    uint16 ui16_ModelId = 0;
    
    // Check for valid imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      ui16_ModelId = IMGDRV_s_DrvObj.apRb_RegsIn[e_Imager]->aRegs[IMGREG_e_REG_MODEL_ID];
    }
    return ui16_ModelId;
    /*#]*/
}

/*## operation IMGDRV_ui8_GetRevisionNumber(const IC_E_Imager) */
uint8 IMGDRV_ui8_GetRevisionNumber(const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_ui8_GetRevisionNumber(const IC_E_Imager) */
    uint8 ui8_RevNum = 0;
    
    // Check for valid imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      // The revision-number is an 8-bit register! So extract it from the MSB:
      ui8_RevNum = (uint8)(IMGDRV_s_DrvObj.apRb_RegsIn[e_Imager]->aRegs[IMGREG_e_REG_REVISION_NUMBER] >> IC_BITSHIFT_1BYTE);
    }
    return ui8_RevNum;
    /*#]*/
}

/*## operation IMGDRV_v_SetEmbeddedDataVersion(const uint8) */
void IMGDRV_v_SetEmbeddedDataVersion(const uint8 ui8_Version) {
    /*#[ operation IMGDRV_v_SetEmbeddedDataVersion(const uint8) */
    IMGDRV_v_SetRegister(IMGREG_e_REG_AE_MAX_EV_STEP_REG, (uint16)ui8_Version);
    /*#]*/
}

/*## operation IMGDRV_b_GetBistStatusPassed(const IC_E_Imager) */
boolean IMGDRV_b_GetBistStatusPassed(const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_b_GetBistStatusPassed(const IC_E_Imager) */
    uint16 ui16_Status = 0;
    boolean b_Ret = b_FALSE;
    
    // Check for valid imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      // Get register status for selected imager
      ui16_Status = IMGDRV_s_DrvObj.apRb_RegsIn[e_Imager]->aRegs[IMGREG_e_REG_BIST_BUFFERS_STATUS1];
    
      // Check status flag
      if ((ui16_Status & IMGREG_cui16_BITMASK_BIST_BUFFERS_STATUS1_TEST_FAILED) != 0)
      {
        b_Ret = b_FALSE;    // FAILED!
      }
      else
      {
        b_Ret = b_TRUE;     // passed.
      }
    }
    return b_Ret;
    /*#]*/
}

/*## operation IMGDRV_v_CollectImageData(IC_S_EmbeddedRegData * const,const IC_E_Imager) */
void IMGDRV_v_CollectImageData(IC_S_EmbeddedRegData * const ps_EmbDat, const IC_E_Imager e_Imager) {
    /*#[ operation IMGDRV_v_CollectImageData(IC_S_EmbeddedRegData * const,const IC_E_Imager) */
    uint16 ui16_Reg_T1 = 0;
    uint16 ui16_Reg_T2 = 0;
    uint16 ui16_Reg_T3 = 0;
    uint16 ui16_AnalogGainIndex = 0;
    IC_S_RegBuff const * ps_Regs = NULL;
    
    // Check for valid imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_SENSORNUM, e_Imager);
    }
    else
    {
      // Get registers for selected imager
      ps_Regs = IMGDRV_s_DrvObj.apRb_RegsIn[e_Imager];
    
      // Get register-value for calculation of total exposure time
      ui16_Reg_T1 = ps_Regs->aRegs[IMGREG_e_REG_EXPOSURE_T1];
      ui16_Reg_T2 = ps_Regs->aRegs[IMGREG_e_REG_EXPOSURE_T2];
      ui16_Reg_T3 = ps_Regs->aRegs[IMGREG_e_REG_EXPOSURE_T3];
    
      // Calculate some exposure-times
      ps_EmbDat->ui16_ExposureTimeT1_lines  = ui16_Reg_T1;
      ps_EmbDat->ui16_ExposureTimeT1_us     = (uint16)((float32)ui16_Reg_T1 * ICCFG_cf32_LineTimeUs);  // PRQA S 4119
      ps_EmbDat->ui16_ExposureTimeT2_us     = (uint16)((float32)ui16_Reg_T2 * ICCFG_cf32_LineTimeUs);  // PRQA S 4119
      ps_EmbDat->ui16_ExposureTimeT3_us     = (uint16)((float32)ui16_Reg_T3 * ICCFG_cf32_PixelTimeUs); // PRQA S 4119
      ps_EmbDat->ui16_ExposureTimeTotal_us  = ps_EmbDat->ui16_ExposureTimeT1_us +
                                              ps_EmbDat->ui16_ExposureTimeT2_us +
                                              ps_EmbDat->ui16_ExposureTimeT3_us;
    
      // Copy over other register values
      ps_EmbDat->ui16_FrameCounter          = ps_Regs->aRegs[IMGREG_e_REG_FRAME_COUNT];
      ps_EmbDat->ui64_FrameTimestamp_us     = IMGDRV_ui64_GetTimestampEmbedded(e_Imager);
    
      // DCG
      if ((ps_Regs->aRegs[IMGREG_e_REG_AE_CTRL_REG] & IMGREG_cui16_BITMASK_AE_CTRL_REG_DCG_MANUAL_SET) != 0)
      {
        ps_EmbDat->e_DcgState = IC_e_DCG_HIGH;
      }
      else
      {
        ps_EmbDat->e_DcgState = IC_e_DCG_LOW;
      }
    
      // Extract analog gain. This is a LUT-style switch statement, so magic numbers are intended here:
      // PRQA S 3120 LUT_ANALOG_GAIN
      ui16_AnalogGainIndex = (ps_Regs->aRegs[IMGREG_e_REG_DIGITAL_TEST] & IMGREG_cui16_BITMASK_DIGITAL_TEST_COL_GAIN)
                             >> IMGREG_cui16_BITSHIFT_DIGITAL_TEST_COL_GAIN;
      switch (ui16_AnalogGainIndex)
      {
      case 0u:
        ps_EmbDat->e_AnalogGain = IC_e_ANALOG_GAIN_1X;
        break;
      case 1u:
        ps_EmbDat->e_AnalogGain = IC_e_ANALOG_GAIN_2X;
        break;
      case 2u:
        ps_EmbDat->e_AnalogGain = IC_e_ANALOG_GAIN_4X;
        break;
      case 3u:
        ps_EmbDat->e_AnalogGain = IC_e_ANALOG_GAIN_8X;
        break;
      default:
        ps_EmbDat->e_AnalogGain = IC_e_ANALOG_GAIN_1X;
        break;
      }
      // PRQA L:LUT_ANALOG_GAIN
    }
    /*#]*/
}

/*## operation IMGDRV_ui32_LinesToUs(const uint16) */
uint32 IMGDRV_ui32_LinesToUs(const uint16 ui16_Lines) {
    /*#[ operation IMGDRV_ui32_LinesToUs(const uint16) */
    const uint32 cui32_Ns = (uint32)ui16_Lines * ICCFG_cui32_LineTimeNs;
    return IC_ui32_CONV_ns_us(cui32_Ns);
    /*#]*/
}

/*## operation IMGDRV_ui16_UsToLines(const uint32) */
uint16 IMGDRV_ui16_UsToLines(const uint32 ui32_TimeUs) {
    /*#[ operation IMGDRV_ui16_UsToLines(const uint32) */
    uint32 ui32_TimeNs = IC_ui32_CONV_us_ns(ui32_TimeUs);
    uint32 ui32_Lines  = 0;
    
    // Add a half line to achieve rounding to nearest integer
    ui32_TimeNs += (ICCFG_cui32_LineTimeNs / 2); // PRQA S 3120
    ui32_Lines = ui32_TimeNs / ICCFG_cui32_LineTimeNs;
    return (uint16)(ui32_Lines);
    /*#]*/
}

/*## operation IMGDRV_ui16_IntTimeRatioToRaw(const IC_E_INTEGR_RATIO) */
static uint16 IMGDRV_ui16_IntTimeRatioToRaw(const IC_E_INTEGR_RATIO e_Ratio) {
    /*#[ operation IMGDRV_ui16_IntTimeRatioToRaw(const IC_E_INTEGR_RATIO) */
    uint16 ui16_RawValue = 0;
    
    // This is a LUT, so disable QAC magic warnings message
    // PRQA S 3120 INTTIME_RATIO_LUT
    switch (e_Ratio)
    {
    case IC_e_INTEGR_RATIO_4:
      ui16_RawValue = 0;
      break;
    case IC_e_INTEGR_RATIO_8:
      ui16_RawValue = 1;
      break;
    case IC_e_INTEGR_RATIO_16:
      ui16_RawValue = 2;
      break;
    case IC_e_INTEGR_RATIO_32:
      ui16_RawValue = 3;
      break;
    default:
      ui16_RawValue = 0;
      break;
    }
    // PRQA L:INTTIME_RATIO_LUT
    
    return ui16_RawValue;
    /*#]*/
}

/*## operation IMGDRV_e_IntTimeRatioFromRaw(const uint16) */
static IC_E_INTEGR_RATIO IMGDRV_e_IntTimeRatioFromRaw(const uint16 ui16_RawValue) {
    /*#[ operation IMGDRV_e_IntTimeRatioFromRaw(const uint16) */
    IC_E_INTEGR_RATIO e_Ratio = IC_e_INTEGR_RATIO_16;
    static const IC_E_INTEGR_RATIO cae_ValMap[] = // PRQA S 3674
    {
          IC_e_INTEGR_RATIO_4,
          IC_e_INTEGR_RATIO_8,
          IC_e_INTEGR_RATIO_16,
          IC_e_INTEGR_RATIO_32
    };
    
    if (ui16_RawValue < IC_ARRLEN(cae_ValMap))
    {
      e_Ratio = cae_ValMap[ui16_RawValue];
    }
    return e_Ratio;
    /*#]*/
}


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_driver.c
*********************************************************************/
