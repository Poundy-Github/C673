//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_registers.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:57CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_registers
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_registers.h
//  LOGIN:           uidt3974  
//  
//  Main purpose of this module is to provide definitions and addresses of the Imager registers
//  to all IC modules, which work with registers. The datatype 'IMGREG_S_SENSOR_REG'
//  declares a list of registers, which provides symbolic names for each known imager register.
//  This enum values are also used to access register values, which are stored in the array
//  of register buffer type 'IC_S_RegBuff.aRegs'.
//  
//  Register addresses can be gathered by calling IMGREG_ui16_GetRegAddr(). It's also possible
//  to get the register enum value by passing the register address to IMGREG_si16_FindRegIndex().
//  
//  Last but not least this module holds the 'reset' values of all relevant registers, which
//  can be retrieved by calling IMGREG_e_GetResetValues().
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//    A subsequent declaration of 'xxxx' means that it is being used both as a structure/union
//    member and also as a label, tag or ordinary identifier.
//        PRQA S 0781,0783 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Wed, 1, Aug 2012  2:10 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_registers_H
#define ic_registers_H

/*## dependency ic_globdefs */
#include "ic_globdefs.h"
/*## auto_generated */
#include "glob_type.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_registers */
/*#[ ignore */
//  Main purpose of this module is to provide definitions and addresses of the Imager registers
//  to all IC modules, which work with registers. The datatype 'IMGREG_S_SENSOR_REG'
//  declares a list of registers, which provides symbolic names for each known imager register.
//  This enum values are also used to access register values, which are stored in the array
//  of register buffer type 'IC_S_RegBuff.aRegs'.
//  
//  Register addresses can be gathered by calling IMGREG_ui16_GetRegAddr(). It's also possible
//  to get the register enum value by passing the register address to IMGREG_si16_FindRegIndex().
//  
//  Last but not least this module holds the 'reset' values of all relevant registers, which
//  can be retrieved by calling IMGREG_e_GetResetValues().
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//    A subsequent declaration of 'xxxx' means that it is being used both as a structure/union
//    member and also as a label, tag or ordinary identifier.
//        PRQA S 0781,0783 EOF
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Type for register address
/*#[ type IC_t_RegAddr */
typedef uint16 IC_t_RegAddr;
/*#]*/

//  Type for register value
/*#[ type IC_t_RegVal */
typedef uint16 IC_t_RegVal;
/*#]*/

//  Definition of error codes for this module, which are returned in diverse function calls
/*#[ type IMGREG_E_ERROR */
typedef enum {
    IMGREG_e_ERR_OK,
    IMGREG_e_ERR_NULLPOINTER,
    IMGREG_e_ERR_REGISTERMAP,
    IMGREG_e_ERR_REGISTERCOUNT_NOTMATCHED,
    IMGREG_e_ERR_UNSUPPORTED_IMAGER
}  IMGREG_E_ERROR;
/*#]*/

//  Definition of known imager registers. This type is used in all modules which work with
//  registers and is also used to access register values stored in a register buffer of
//  type 'IC_S_RegBuff'.
//  
//  PRQA S 0647 REGISTER_ENUM
/*#[ type IMGREG_E_SENSOR_REG */
typedef enum {
    // Define only required registers if code is compiled for ECU, as they consume
    // memory and CPU-Time for extraction
#if (IC_COMPILE_FOR_MTS == 0)
    /* 0x3000 */ IMGREG_e_REG_MODEL_ID,
    /* 0x3002 */ IMGREG_e_REG_Y_ADDR_START,
    /* 0x3004 */ IMGREG_e_REG_X_ADDR_START,
    /* 0x3006 */ IMGREG_e_REG_Y_ADDR_END,
    /* 0x3008 */ IMGREG_e_REG_X_ADDR_END,
    /* 0x300a */ IMGREG_e_REG_FRAME_LENGTH_LINES,
    /* 0x300c */ IMGREG_e_REG_LINE_LENGTH_PCK,
    /* 0x300e */ IMGREG_e_REG_REVISION_NUMBER,
    /* 0x3010 */ IMGREG_e_REG_LOCK_CONTROL,
    /* 0x3012 */ IMGREG_e_REG_COARSE_INTEGRATION_TIME,
    /* 0x301a */ IMGREG_e_REG_RESET_REGISTER,
    /* 0x301e */ IMGREG_e_REG_DATA_PEDESTAL,
    /* 0x3028 */ IMGREG_e_REG_ROW_SPEED,
    /* 0x302a */ IMGREG_e_REG_VT_PIX_CLK_DIV,
    /* 0x302c */ IMGREG_e_REG_VT_SYS_CLK_DIV,
    /* 0x302e */ IMGREG_e_REG_PRE_PLL_CLK_DIV,
    /* 0x3030 */ IMGREG_e_REG_PLL_MULTIPLIER,
    /* 0x3032 */ IMGREG_e_REG_DIGITAL_BINNING,
    /* 0x303a */ IMGREG_e_REG_FRAME_COUNT,
    /* 0x3040 */ IMGREG_e_REG_READ_MODE,
    /* 0x3044 */ IMGREG_e_REG_DARK_CONTROL,
    /* 0x3056 */ IMGREG_e_REG_GREEN1_GAIN,
    /* 0x3058 */ IMGREG_e_REG_BLUE_GAIN,
    /* 0x305a */ IMGREG_e_REG_RED_GAIN,
    /* 0x305c */ IMGREG_e_REG_GREEN2_GAIN,
    /* 0x305e */ IMGREG_e_REG_GLOBAL_GAIN,
    /* 0x3064 */ IMGREG_e_REG_EMBEDDED_DATA_CTRL,
    /* 0x306e */ IMGREG_e_REG_DATAPATH_SELECT,
    /* 0x3070 */ IMGREG_e_REG_TEST_PATTERN_MODE,
    /* 0x3072 */ IMGREG_e_REG_TEST_DATA_RED,
    /* 0x3074 */ IMGREG_e_REG_TEST_DATA_GREENR,
    /* 0x3076 */ IMGREG_e_REG_TEST_DATA_BLUE,
    /* 0x3078 */ IMGREG_e_REG_TEST_DATA_GREENB,
    /* 0x307a */ IMGREG_e_REG_TEST_RAW_MODE,
    /* 0x307c */ IMGREG_e_REG_EXPOSURE_T2,
    /* 0x307e */ IMGREG_e_REG_MINIMUM_T3,
    /* 0x3080 */ IMGREG_e_REG_EXPOSURE_T3,
    /* 0x3082 */ IMGREG_e_REG_OPERATION_MODE_CTRL,
    /* 0x3086 */ IMGREG_e_REG_SEQ_DATA_PORT,
    /* 0x3088 */ IMGREG_e_REG_SEQ_CTRL_PORT,
    /* 0x30ac */ IMGREG_e_REG_EXPOSURE_T1,
    /* 0x30b0 */ IMGREG_e_REG_DIGITAL_TEST,
    /* 0x30b2 */ IMGREG_e_REG_TEMPSENS_DATA,
    /* 0x30b4 */ IMGREG_e_REG_TEMPSENS_CTRL,
    /* 0x30ba */ IMGREG_e_REG_DIGITAL_CTRL,
    /* 0x30c6 */ IMGREG_e_REG_TEMPSENS_CALIB1,
    /* 0x30c8 */ IMGREG_e_REG_TEMPSENS_CALIB2,
    /* 0x30ca */ IMGREG_e_REG_TEMPSENS_CALIB3,
    /* 0x30cc */ IMGREG_e_REG_TEMPSENS_CALIB4,
    /* 0x30d4 */ IMGREG_e_REG_COLUMN_CORRECTION,
    /* 0x30d6 */ IMGREG_e_REG_COLUMN_CORRECTION_THRESHOLD,
    /* 0x30d8 */ IMGREG_e_REG_COLUMN_CORRECTION_CLIP,
    /* 0x30de */ IMGREG_e_REG_ADC_BITS_0_1,
    /* 0x30e0 */ IMGREG_e_REG_ADC_BITS_2_3,
    /* 0x30e2 */ IMGREG_e_REG_ADC_BITS_4_5,
    /* 0x30e4 */ IMGREG_e_REG_ADC_BITS_6_7,
    /* 0x30e6 */ IMGREG_e_REG_ADC_CONFIG1,
    /* 0x30e8 */ IMGREG_e_REG_ADC_CONFIG2,
    /* 0x30ea */ IMGREG_e_REG_GAIN_OFFSET_CTRL,
    /* 0x30f0 */ IMGREG_e_REG_START_UP_FRAME_NR,
    /* 0x30f4 */ IMGREG_e_REG_OFFSET_LIMIT_LOW,
    /* 0x30f6 */ IMGREG_e_REG_OFFSET_LIMIT_HIGH,
    /* 0x30f8 */ IMGREG_e_REG_REG_OFFSET_BTM_GL,
    /* 0x3100 */ IMGREG_e_REG_AE_CTRL_REG,
    /* 0x3102 */ IMGREG_e_REG_AE_LUMA_TARGET_REG,
    /* 0x3104 */ IMGREG_e_REG_AE_HIST_TARGET_REG,
    /* 0x310a */ IMGREG_e_REG_AE_MAX_EV_STEP_REG,
    /* 0x310c */ IMGREG_e_REG_AE_DAMP_OFFSET_REG,
    /* 0x310e */ IMGREG_e_REG_AE_DAMP_GAIN_REG,
    /* 0x3110 */ IMGREG_e_REG_AE_DAMP_MAX_REG,
    /* 0x3130 */ IMGREG_e_REG_OTPM_TCFG_WRITE_01,
    /* 0x3132 */ IMGREG_e_REG_OTPM_TCFG_WRITE_23,
    /* 0x3134 */ IMGREG_e_REG_OTPM_TCFG_READ_01,
    /* 0x3136 */ IMGREG_e_REG_OTPM_TCFG_READ_23,
    /* 0x3138 */ IMGREG_e_REG_OTPM_TCFG_READ_4B,
    /* 0x313a */ IMGREG_e_REG_OTPM_DATA_MANUAL_L,
    /* 0x313c */ IMGREG_e_REG_OTPM_DATA_MANUAL_H,
    /* 0x313e */ IMGREG_e_REG_OTPM_DATA_MANUAL_EXTRA,
    /* 0x3140 */ IMGREG_e_REG_AE_ROI_X_START_OFFSET,
    /* 0x3142 */ IMGREG_e_REG_AE_ROI_Y_START_OFFSET,
    /* 0x3144 */ IMGREG_e_REG_AE_ROI_X_SIZE,
    /* 0x3146 */ IMGREG_e_REG_AE_ROI_Y_SIZE,
    /* 0x3148 */ IMGREG_e_REG_AE_HIST_BEGIN_PERC,
    /* 0x314a */ IMGREG_e_REG_AE_HIST_END_PERC,
    /* 0x314c */ IMGREG_e_REG_AE_HIST_DIV,
    /* 0x3180 */ IMGREG_e_REG_DELTA_DK_CONTROL,
    /* 0x3182 */ IMGREG_e_REG_DELTA_DK_CLIP,
    /* 0x3184 */ IMGREG_e_REG_DELTA_DK_T1,
    /* 0x3186 */ IMGREG_e_REG_DELTA_DK_T2,
    /* 0x3188 */ IMGREG_e_REG_DELTA_DK_T3,
    /* 0x318a */ IMGREG_e_REG_HDR_MC_CTRL1,
    /* 0x318c */ IMGREG_e_REG_HDR_MC_CTRL2,
    /* 0x318e */ IMGREG_e_REG_HDR_MC_CTRL3,
    /* 0x3190 */ IMGREG_e_REG_HDR_MC_CTRL4,
    /* 0x3192 */ IMGREG_e_REG_HDR_MC_CTRL5,
    /* 0x3194 */ IMGREG_e_REG_HDR_MC_CTRL6,
    /* 0x3196 */ IMGREG_e_REG_HDR_MC_CTRL7,
    /* 0x3198 */ IMGREG_e_REG_HDR_MC_CTRL8,
    /* 0x319e */ IMGREG_e_REG_HDR_MC_CTRL9,
    /* 0x31a0 */ IMGREG_e_REG_HDR_MC_CTRL10,
    /* 0x31a2 */ IMGREG_e_REG_HDR_MC_CTRL11,
    /* 0x31d0 */ IMGREG_e_REG_HDR_COMP,
    /* 0x31d2 */ IMGREG_e_REG_STAT_FRAME_ID,
    /* 0x31da */ IMGREG_e_REG_PLL_DITHER_1,
    /* 0x31dc */ IMGREG_e_REG_PLL_DITHER_2,
    /* 0x31de */ IMGREG_e_REG_PLL_DITHER_3,
    /* 0x31e0 */ IMGREG_e_REG_PIX_DEF_ID,
    /* 0x31e2 */ IMGREG_e_REG_PIX_DEF_ID_BASE_RAM,
    /* 0x31e4 */ IMGREG_e_REG_PIX_DEF_ID_STREAM_RAM,
    /* 0x31e6 */ IMGREG_e_REG_PIX_DEF_RAM_RD_ADDR,
    /* 0x31f4 */ IMGREG_e_REG_FUSE_ID1,
    /* 0x31f6 */ IMGREG_e_REG_FUSE_ID2,
    /* 0x31f8 */ IMGREG_e_REG_FUSE_ID3,
    /* 0x31fa */ IMGREG_e_REG_FUSE_ID4,
    /* 0x3ecc */ IMGREG_e_REG_DAC_LD_0_1,
    /* 0x3ece */ IMGREG_e_REG_DAC_LD_2_3,
    /* 0x3ed0 */ IMGREG_e_REG_DAC_LD_4_5,
    /* 0x3ed6 */ IMGREG_e_REG_DAC_LD_10_11,
    /* 0x3ed8 */ IMGREG_e_REG_DAC_LD_12_13,
    /* 0x3eda */ IMGREG_e_REG_DAC_LD_14_15,
    /* 0x3edc */ IMGREG_e_REG_DAC_LD_16_17,
    /* 0x3ede */ IMGREG_e_REG_DAC_LD_18_19,
    /* 0x3ee0 */ IMGREG_e_REG_DAC_LD_20_21,
    /* 0x3ee2 */ IMGREG_e_REG_DAC_LD_22_23,
    /* 0x3ee4 */ IMGREG_e_REG_DAC_LD_24_25,
    /* 0x3ee6 */ IMGREG_e_REG_DAC_LD_26_27,
    /* 0x3ee8 */ IMGREG_e_REG_DAC_LD_28_29,
    /* 0x3eea */ IMGREG_e_REG_DAC_LD_30_31,
    /* 0x3fd0 */ IMGREG_e_REG_BIST_BUFFERS_CONTROL1,
    /* 0x3fd4 */ IMGREG_e_REG_BIST_BUFFERS_STATUS1,
#else
    // Define all registers if code is compiled for MTS/Win32 PC
    /* 0x3000 */ IMGREG_e_REG_MODEL_ID,
    /* 0x3002 */ IMGREG_e_REG_Y_ADDR_START,
    /* 0x3004 */ IMGREG_e_REG_X_ADDR_START,
    /* 0x3006 */ IMGREG_e_REG_Y_ADDR_END,
    /* 0x3008 */ IMGREG_e_REG_X_ADDR_END,
    /* 0x300a */ IMGREG_e_REG_FRAME_LENGTH_LINES,
    /* 0x300c */ IMGREG_e_REG_LINE_LENGTH_PCK,
    /* 0x300e */ IMGREG_e_REG_REVISION_NUMBER,
    /* 0x3010 */ IMGREG_e_REG_LOCK_CONTROL,
    /* 0x3012 */ IMGREG_e_REG_COARSE_INTEGRATION_TIME,
    /* 0x3014 */ IMGREG_e_REG_FINE_INTEGRATION_TIME,
    /* 0x3016 */ IMGREG_e_REG_COARSE_INTEGRATION_TIME_CB,
    /* 0x3018 */ IMGREG_e_REG_FINE_INTEGRATION_TIME_CB,
    /* 0x301a */ IMGREG_e_REG_RESET_REGISTER,
    /* 0x301e */ IMGREG_e_REG_DATA_PEDESTAL,
    /* 0x3026 */ IMGREG_e_REG_GPI_STATUS,
    /* 0x3028 */ IMGREG_e_REG_ROW_SPEED,
    /* 0x302a */ IMGREG_e_REG_VT_PIX_CLK_DIV,
    /* 0x302c */ IMGREG_e_REG_VT_SYS_CLK_DIV,
    /* 0x302e */ IMGREG_e_REG_PRE_PLL_CLK_DIV,
    /* 0x3030 */ IMGREG_e_REG_PLL_MULTIPLIER,
    /* 0x3032 */ IMGREG_e_REG_DIGITAL_BINNING,
    /* 0x303a */ IMGREG_e_REG_FRAME_COUNT,
    /* 0x303c */ IMGREG_e_REG_FRAME_STATUS,
    /* 0x3040 */ IMGREG_e_REG_READ_MODE,
    /* 0x3044 */ IMGREG_e_REG_DARK_CONTROL,
    /* 0x3046 */ IMGREG_e_REG_FLASH,
    /* 0x304a */ IMGREG_e_REG_OTPM_CONTROL,
    /* 0x304c */ IMGREG_e_REG_OTPM_RECORD,
    /* 0x304e */ IMGREG_e_REG_OTPM_STATUS,
    /* 0x3050 */ IMGREG_e_REG_OTPM_MANUAL_CONTROL,
    /* 0x3052 */ IMGREG_e_REG_OTPM_CFG,
    /* 0x3054 */ IMGREG_e_REG_OTPM_EXPR,
    /* 0x3056 */ IMGREG_e_REG_GREEN1_GAIN,
    /* 0x3058 */ IMGREG_e_REG_BLUE_GAIN,
    /* 0x305a */ IMGREG_e_REG_RED_GAIN,
    /* 0x305c */ IMGREG_e_REG_GREEN2_GAIN,
    /* 0x305e */ IMGREG_e_REG_GLOBAL_GAIN,
    /* 0x3064 */ IMGREG_e_REG_EMBEDDED_DATA_CTRL,
    /* 0x306c */ IMGREG_e_REG_SCALER_TEST,
    /* 0x306e */ IMGREG_e_REG_DATAPATH_SELECT,
    /* 0x3070 */ IMGREG_e_REG_TEST_PATTERN_MODE,
    /* 0x3072 */ IMGREG_e_REG_TEST_DATA_RED,
    /* 0x3074 */ IMGREG_e_REG_TEST_DATA_GREENR,
    /* 0x3076 */ IMGREG_e_REG_TEST_DATA_BLUE,
    /* 0x3078 */ IMGREG_e_REG_TEST_DATA_GREENB,
    /* 0x307a */ IMGREG_e_REG_TEST_RAW_MODE,
    /* 0x307c */ IMGREG_e_REG_EXPOSURE_T2,
    /* 0x307e */ IMGREG_e_REG_MINIMUM_T3,
    /* 0x3080 */ IMGREG_e_REG_EXPOSURE_T3,
    /* 0x3082 */ IMGREG_e_REG_OPERATION_MODE_CTRL,
    /* 0x3084 */ IMGREG_e_REG_OPERATION_MODE_CTRL_CB,
    /* 0x3086 */ IMGREG_e_REG_SEQ_DATA_PORT,
    /* 0x3088 */ IMGREG_e_REG_SEQ_CTRL_PORT,
    /* 0x308a */ IMGREG_e_REG_X_ADDR_START_CB,
    /* 0x308c */ IMGREG_e_REG_Y_ADDR_START_CB,
    /* 0x308e */ IMGREG_e_REG_X_ADDR_END_CB,
    /* 0x3090 */ IMGREG_e_REG_Y_ADDR_END_CB,
    /* 0x309e */ IMGREG_e_REG_ERS_PROG_START_ADDR,
    /* 0x30a0 */ IMGREG_e_REG_X_EVEN_INC,
    /* 0x30a2 */ IMGREG_e_REG_X_ODD_INC,
    /* 0x30a4 */ IMGREG_e_REG_Y_EVEN_INC,
    /* 0x30a6 */ IMGREG_e_REG_Y_ODD_INC,
    /* 0x30a8 */ IMGREG_e_REG_Y_ODD_INC_CB,
    /* 0x30aa */ IMGREG_e_REG_FRAME_LENGTH_LINES_CB,
    /* 0x30ac */ IMGREG_e_REG_EXPOSURE_T1,
    /* 0x30b0 */ IMGREG_e_REG_DIGITAL_TEST,
    /* 0x30b2 */ IMGREG_e_REG_TEMPSENS_DATA,
    /* 0x30b4 */ IMGREG_e_REG_TEMPSENS_CTRL,
    /* 0x30ba */ IMGREG_e_REG_DIGITAL_CTRL,
    /* 0x30bc */ IMGREG_e_REG_GREEN1_GAIN_CB,
    /* 0x30be */ IMGREG_e_REG_BLUE_GAIN_CB,
    /* 0x30c0 */ IMGREG_e_REG_RED_GAIN_CB,
    /* 0x30c2 */ IMGREG_e_REG_GREEN2_GAIN_CB,
    /* 0x30c4 */ IMGREG_e_REG_GLOBAL_GAIN_CB,
    /* 0x30c6 */ IMGREG_e_REG_TEMPSENS_CALIB1,
    /* 0x30c8 */ IMGREG_e_REG_TEMPSENS_CALIB2,
    /* 0x30ca */ IMGREG_e_REG_TEMPSENS_CALIB3,
    /* 0x30cc */ IMGREG_e_REG_TEMPSENS_CALIB4,
    /* 0x30d4 */ IMGREG_e_REG_COLUMN_CORRECTION,
    /* 0x30d6 */ IMGREG_e_REG_COLUMN_CORRECTION_THRESHOLD,
    /* 0x30d8 */ IMGREG_e_REG_COLUMN_CORRECTION_CLIP,
    /* 0x30de */ IMGREG_e_REG_ADC_BITS_0_1,
    /* 0x30e0 */ IMGREG_e_REG_ADC_BITS_2_3,
    /* 0x30e2 */ IMGREG_e_REG_ADC_BITS_4_5,
    /* 0x30e4 */ IMGREG_e_REG_ADC_BITS_6_7,
    /* 0x30e6 */ IMGREG_e_REG_ADC_CONFIG1,
    /* 0x30e8 */ IMGREG_e_REG_ADC_CONFIG2,
    /* 0x30ea */ IMGREG_e_REG_GAIN_OFFSET_CTRL,
    /* 0x30ec */ IMGREG_e_REG_REG_OFFSET_TOP_GL,
    /* 0x30ee */ IMGREG_e_REG_REG_OFFSET_TOP_GH,
    /* 0x30f0 */ IMGREG_e_REG_START_UP_FRAME_NR,
    /* 0x30f4 */ IMGREG_e_REG_OFFSET_LIMIT_LOW,
    /* 0x30f6 */ IMGREG_e_REG_OFFSET_LIMIT_HIGH,
    /* 0x30f8 */ IMGREG_e_REG_REG_OFFSET_BTM_GL,
    /* 0x30fa */ IMGREG_e_REG_REG_OFFSET_BTM_GH,
    /* 0x3100 */ IMGREG_e_REG_AE_CTRL_REG,
    /* 0x3102 */ IMGREG_e_REG_AE_LUMA_TARGET_REG,
    /* 0x3104 */ IMGREG_e_REG_AE_HIST_TARGET_REG,
    /* 0x3106 */ IMGREG_e_REG_AE_HYSTERESIS_REG,
    /* 0x3108 */ IMGREG_e_REG_AE_MIN_EV_STEP_REG,
    /* 0x310a */ IMGREG_e_REG_AE_MAX_EV_STEP_REG,
    /* 0x310c */ IMGREG_e_REG_AE_DAMP_OFFSET_REG,
    /* 0x310e */ IMGREG_e_REG_AE_DAMP_GAIN_REG,
    /* 0x3110 */ IMGREG_e_REG_AE_DAMP_MAX_REG,
    /* 0x3112 */ IMGREG_e_REG_AE_DCG_EXPOSURE_HIGH_REG,
    /* 0x3114 */ IMGREG_e_REG_AE_DCG_EXPOSURE_LOW_REG,
    /* 0x3116 */ IMGREG_e_REG_AE_DCG_GAIN_FACTOR_REG,
    /* 0x3118 */ IMGREG_e_REG_AE_DCG_GAIN_FACTOR_INV_REG,
    /* 0x311c */ IMGREG_e_REG_AE_MAX_EXPOSURE_REG,
    /* 0x311e */ IMGREG_e_REG_AE_MIN_EXPOSURE_REG,
    /* 0x3120 */ IMGREG_e_REG_AE_LOW_MEAN_TARGET_REG,
    /* 0x3122 */ IMGREG_e_REG_AE_HIST_LOW_THRESH_REG,
    /* 0x3124 */ IMGREG_e_REG_AE_DARK_CUR_THRESH_REG,
    /* 0x3126 */ IMGREG_e_REG_AE_ALPHA_V1_REG,
    /* 0x3128 */ IMGREG_e_REG_AE_ALPHA_COEF_REG,
    /* 0x312a */ IMGREG_e_REG_AE_CURRENT_GAINS,
    /* 0x3130 */ IMGREG_e_REG_OTPM_TCFG_WRITE_01,
    /* 0x3132 */ IMGREG_e_REG_OTPM_TCFG_WRITE_23,
    /* 0x3134 */ IMGREG_e_REG_OTPM_TCFG_READ_01,
    /* 0x3136 */ IMGREG_e_REG_OTPM_TCFG_READ_23,
    /* 0x3138 */ IMGREG_e_REG_OTPM_TCFG_READ_4B,
    /* 0x313a */ IMGREG_e_REG_OTPM_DATA_MANUAL_L,
    /* 0x313c */ IMGREG_e_REG_OTPM_DATA_MANUAL_H,
    /* 0x313e */ IMGREG_e_REG_OTPM_DATA_MANUAL_EXTRA,
    /* 0x3140 */ IMGREG_e_REG_AE_ROI_X_START_OFFSET,
    /* 0x3142 */ IMGREG_e_REG_AE_ROI_Y_START_OFFSET,
    /* 0x3144 */ IMGREG_e_REG_AE_ROI_X_SIZE,
    /* 0x3146 */ IMGREG_e_REG_AE_ROI_Y_SIZE,
    /* 0x3148 */ IMGREG_e_REG_AE_HIST_BEGIN_PERC,
    /* 0x314a */ IMGREG_e_REG_AE_HIST_END_PERC,
    /* 0x314c */ IMGREG_e_REG_AE_HIST_DIV,
    /* 0x314e */ IMGREG_e_REG_AE_NORM_WIDTH_MIN,
    /* 0x3150 */ IMGREG_e_REG_AE_MEAN_H,
    /* 0x3152 */ IMGREG_e_REG_AE_MEAN_L,
    /* 0x3154 */ IMGREG_e_REG_AE_HIST_BEGIN_H,
    /* 0x3156 */ IMGREG_e_REG_AE_HIST_BEGIN_L,
    /* 0x3158 */ IMGREG_e_REG_AE_HIST_END_H,
    /* 0x315a */ IMGREG_e_REG_AE_HIST_END_L,
    /* 0x315c */ IMGREG_e_REG_AE_HIST_END_MEAN_H,
    /* 0x315e */ IMGREG_e_REG_AE_HIST_END_MEAN_L,
    /* 0x3160 */ IMGREG_e_REG_AE_PERC_LOW_END,
    /* 0x3162 */ IMGREG_e_REG_AE_NORM_ABS_DEV,
    /* 0x3164 */ IMGREG_e_REG_AE_COARSE_INTEGRATION_TIME,
    /* 0x3166 */ IMGREG_e_REG_AE_AG_EXPOSURE_HI,
    /* 0x3168 */ IMGREG_e_REG_AE_AG_EXPOSURE_LO,
    /* 0x316a */ IMGREG_e_REG_AE_AG_GAIN1,
    /* 0x316c */ IMGREG_e_REG_AE_AG_GAIN2,
    /* 0x316e */ IMGREG_e_REG_AE_AG_GAIN3,
    /* 0x3170 */ IMGREG_e_REG_AE_INV_AG_GAIN1,
    /* 0x3172 */ IMGREG_e_REG_AE_INV_AG_GAIN2,
    /* 0x3174 */ IMGREG_e_REG_AE_INV_AG_GAIN3,
    /* 0x3180 */ IMGREG_e_REG_DELTA_DK_CONTROL,
    /* 0x3182 */ IMGREG_e_REG_DELTA_DK_CLIP,
    /* 0x3184 */ IMGREG_e_REG_DELTA_DK_T1,
    /* 0x3186 */ IMGREG_e_REG_DELTA_DK_T2,
    /* 0x3188 */ IMGREG_e_REG_DELTA_DK_T3,
    /* 0x318a */ IMGREG_e_REG_HDR_MC_CTRL1,
    /* 0x318c */ IMGREG_e_REG_HDR_MC_CTRL2,
    /* 0x318e */ IMGREG_e_REG_HDR_MC_CTRL3,
    /* 0x3190 */ IMGREG_e_REG_HDR_MC_CTRL4,
    /* 0x3192 */ IMGREG_e_REG_HDR_MC_CTRL5,
    /* 0x3194 */ IMGREG_e_REG_HDR_MC_CTRL6,
    /* 0x3196 */ IMGREG_e_REG_HDR_MC_CTRL7,
    /* 0x3198 */ IMGREG_e_REG_HDR_MC_CTRL8,
    /* 0x319a */ IMGREG_e_REG_HDR_COMP_KNEE1,
    /* 0x319c */ IMGREG_e_REG_HDR_COMP_KNEE2,
    /* 0x319e */ IMGREG_e_REG_HDR_MC_CTRL9,
    /* 0x31a0 */ IMGREG_e_REG_HDR_MC_CTRL10,
    /* 0x31a2 */ IMGREG_e_REG_HDR_MC_CTRL11,
    /* 0x31c0 */ IMGREG_e_REG_HISPI_TIMING,
    /* 0x31c6 */ IMGREG_e_REG_HISPI_CONTROL_STATUS,
    /* 0x31c8 */ IMGREG_e_REG_HISPI_CRC_0,
    /* 0x31ca */ IMGREG_e_REG_HISPI_CRC_1,
    /* 0x31cc */ IMGREG_e_REG_HISPI_CRC_2,
    /* 0x31ce */ IMGREG_e_REG_HISPI_CRC_3,
    /* 0x31d0 */ IMGREG_e_REG_HDR_COMP,
    /* 0x31d2 */ IMGREG_e_REG_STAT_FRAME_ID,
    /* 0x31d6 */ IMGREG_e_REG_I2C_WRT_CHECKSUM,
    /* 0x31da */ IMGREG_e_REG_PLL_DITHER_1,
    /* 0x31dc */ IMGREG_e_REG_PLL_DITHER_2,
    /* 0x31de */ IMGREG_e_REG_PLL_DITHER_3,
    /* 0x31e0 */ IMGREG_e_REG_PIX_DEF_ID,
    /* 0x31e2 */ IMGREG_e_REG_PIX_DEF_ID_BASE_RAM,
    /* 0x31e4 */ IMGREG_e_REG_PIX_DEF_ID_STREAM_RAM,
    /* 0x31e6 */ IMGREG_e_REG_PIX_DEF_RAM_RD_ADDR,
    /* 0x31e8 */ IMGREG_e_REG_HORIZONTAL_CURSOR_POSITION,
    /* 0x31ea */ IMGREG_e_REG_VERTICAL_CURSOR_POSITION,
    /* 0x31ec */ IMGREG_e_REG_HORIZONTAL_CURSOR_WIDTH,
    /* 0x31ee */ IMGREG_e_REG_VERTICAL_CURSOR_WIDTH,
    /* 0x31f4 */ IMGREG_e_REG_FUSE_ID1,
    /* 0x31f6 */ IMGREG_e_REG_FUSE_ID2,
    /* 0x31f8 */ IMGREG_e_REG_FUSE_ID3,
    /* 0x31fa */ IMGREG_e_REG_FUSE_ID4,
    /* 0x31fc */ IMGREG_e_REG_I2C_IDS,
    /* 0x31fe */ IMGREG_e_REG_CUSTOMER_REV,
    /* 0x3ecc */ IMGREG_e_REG_DAC_LD_0_1,
    /* 0x3ece */ IMGREG_e_REG_DAC_LD_2_3,
    /* 0x3ed0 */ IMGREG_e_REG_DAC_LD_4_5,
    /* 0x3ed2 */ IMGREG_e_REG_DAC_LD_6_7,
    /* 0x3ed4 */ IMGREG_e_REG_DAC_LD_8_9,
    /* 0x3ed6 */ IMGREG_e_REG_DAC_LD_10_11,
    /* 0x3ed8 */ IMGREG_e_REG_DAC_LD_12_13,
    /* 0x3eda */ IMGREG_e_REG_DAC_LD_14_15,
    /* 0x3edc */ IMGREG_e_REG_DAC_LD_16_17,
    /* 0x3ede */ IMGREG_e_REG_DAC_LD_18_19,
    /* 0x3ee0 */ IMGREG_e_REG_DAC_LD_20_21,
    /* 0x3ee2 */ IMGREG_e_REG_DAC_LD_22_23,
    /* 0x3ee4 */ IMGREG_e_REG_DAC_LD_24_25,
    /* 0x3ee6 */ IMGREG_e_REG_DAC_LD_26_27,
    /* 0x3ee8 */ IMGREG_e_REG_DAC_LD_28_29,
    /* 0x3eea */ IMGREG_e_REG_DAC_LD_30_31,
    /* 0x3fd0 */ IMGREG_e_REG_BIST_BUFFERS_CONTROL1,
    /* 0x3fd2 */ IMGREG_e_REG_BIST_BUFFERS_CONTROL2,
    /* 0x3fd4 */ IMGREG_e_REG_BIST_BUFFERS_STATUS1,
    /* 0x3fd6 */ IMGREG_e_REG_BIST_BUFFERS_STATUS2,
    /* 0x3fd8 */ IMGREG_e_REG_BIST_BUFFERS_DATA1,
    /* 0x3fda */ IMGREG_e_REG_BIST_BUFFERS_DATA2,
    /* 0x3fe0 */ IMGREG_e_REG_BIST_CONTROL,
    /* 0x3fe2 */ IMGREG_e_REG_BIST_STATUS,
    /* 0x3fe4 */ IMGREG_e_REG_BIST_ADDRESS,
    /* 0x3fe6 */ IMGREG_e_REG_BIST_DATA1,
    /* 0x3fe8 */ IMGREG_e_REG_BIST_DATA2,
    /* 0x3fea */ IMGREG_e_REG_BIST_DATA3,
    /* 0x3fec */ IMGREG_e_REG_BIST_DATA4,
#endif
    IMGREG_e_REG__LAST_ENTRY_
    // PRQA L:REGISTER_ENUM
}  IMGREG_E_SENSOR_REG;
/*#]*/

//  Total number of known imager registers, defined in IMGREG_E_SENSOR_REG.
/*#[ type IMGREG_cui16_NumImagerRegs */
#define IMGREG_cui16_NumImagerRegs ((uint16)IMGREG_e_REG__LAST_ENTRY_)
/*#]*/

//  Type for a register value buffer
/*## type IC_S_RegBuff */
typedef struct IC_S_RegBuff {
    //  Register buffer array, which is indexed by values of IMGREG_E_SENSOR_REG
    IC_t_RegVal aRegs[IMGREG_cui16_NumImagerRegs];		/*## attribute aRegs */
} IC_S_RegBuff;

//  Address of reset register
/*## attribute IMGREG_cui16_REGADDR_RESET */
#define IMGREG_cui16_REGADDR_RESET 0x301A

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  IMGREG_e_Init
//  
//  Description:
//    Initializes this module. Lookup tables are generated and some static code checks are done
//    to ensure, that register definition and address map tables are complete.
//  
//  Preconditions:
//    Module must be initialized.
//  
//  Returns:
//    - IMGREG_e_ERR_OK:
//          No error detected
//  
//    - IMGREG_e_ERR_REGISTERCOUNT_NOTMATCHED:
//          Number of elements in enum 'IMGREG_E_SENSOR_REG' differs from register address definition
//          table 'IMGREG_cs_ImagerRegMap'
//  
//    - IMGREG_e_ERR_REGISTERMAP:
//          Register address definition 'IMGREG_cs_ImagerRegMap' contains errors
//  
//    
//  
//  return         IMGREG_E_ERROR
//**************************************************************************** */
/*## operation IMGREG_e_Init() */
IMGREG_E_ERROR IMGREG_e_Init(void);

//*****************************************************************************
//  Functionname:  IMGREG_ui16_GetRegAddr
//  
//  Description:
//    Returns the register address of a specific register.
//  
//  Preconditions:
//    Module must be initialized.
//  
//  Returns:
//    - 0x0000:  Enum value is invalid
//    - else:    Requested register address
//  
//  Parameter:     const IMGREG_E_SENSOR_REG e_Register   <In>
//  Description:   Register, whose address is requested
//  Range:         (enum)
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IMGREG_ui16_GetRegAddr(const IMGREG_E_SENSOR_REG) */
uint16 IMGREG_ui16_GetRegAddr(const IMGREG_E_SENSOR_REG e_Register);

//*****************************************************************************
//  Functionname:  IMGREG_e_FindRegByAddr
//  
//  Description:
//    Looks up the enum-value/index corresponding to a specific register address. No lookup table or
//    binary space partition is used, so calling this function is a bit slow.
//  
//    Function returns IMGREG_e_REG__LAST_ENTRY_ if register was not found.
//  
//  Preconditions:
//    Module must be initialized.
//  
//  Returns:
//    - IMGREG_e_REG__LAST_ENTRY_:  Register address not known
//    - else:                       Requested register enum value
//  
//  Parameter:     const uint16 ui16_RegAddr   <In>
//  Description:   Address of the register, which is requested
//  Range:         0-0xFFFF
//  Resolution:    1
//  Unit:          none
//    
//  
//  return         IMGREG_E_SENSOR_REG
//**************************************************************************** */
/*## operation IMGREG_e_FindRegByAddr(const uint16) */
IMGREG_E_SENSOR_REG IMGREG_e_FindRegByAddr(const uint16 ui16_RegAddr);

//*****************************************************************************
//  Functionname:  IMGREG_e_GetResetValues
//  
//  Description:
//    Fills the passed register buffer 'pRb_TargetBuff' with the default power-up reset values of
//    the imager. As the values differ between imager revisions, the model-id and revision number
//    must be passed to this function call.
//  
//    NOTE: Not all registers have a reset value defined. For this registers, the corresponding
//          entry in the output register buffer will be left untouched, so make sure they are
//          properly initialized.
//  
//  Preconditions:
//    Module must be initialized.
//  
//  Returns:
//    - IMGREG_e_ERR_OK:                  No error occurred.
//    - IMGREG_e_ERR_UNSUPPORTED_IMAGER:  The imager type is not known.
//  
//  Parameter:     IC_S_RegBuff * const pRb_TargetRegBuff   <Out>
//  Description:   Target output register buffer, which will be filled with all known reset values
//                 of the requested imager.
//  Range:         0-0xFFFF
//  Resolution:    1
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_ModelId   <In>
//  Description:   Model ID of the imager, whose reset values are requested
//  Range:         0-0xFFFF
//  Resolution:    1
//  Unit:          none
//  
//  Parameter:     const uint8 ui8_RevisionNum   <In>
//  Description:   Revision number of the imager, whose reset values are requested
//  Range:         0-0xFF
//  Resolution:    1
//  Unit:          none
//    
//  
//  return         IMGREG_E_ERROR
//**************************************************************************** */
/*## operation IMGREG_e_GetResetValues(IC_S_RegBuff * const,const uint16,const uint8) */
IMGREG_E_ERROR IMGREG_e_GetResetValues(IC_S_RegBuff * const pRb_TargetRegBuff, const uint16 ui16_ModelId, const uint8 ui8_RevisionNum);

/***    User explicit entries    ***/



/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_registers.h
*********************************************************************/
