//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_registers.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:57CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_registers
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_registers.c
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
//! CREATION DATE:   Wed, 29, Aug 2012  2:21 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_registers.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_registers */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Definitions of known imager models
/*#[ type IC_E_ImagerModel */
typedef enum {
    IC_e_IMAGERMODEL_A1000_REV4,
    IC_e_IMAGERMODEL_A1000_REV5,
    IC_e_IMAGERMODEL_A1000_REV6,
    IC_e_IMAGERMODEL_ARX550_REV1,
    IC_e_IMAGERMODEL__NUM_ENTRIES__
}  IC_E_ImagerModel;
/*#]*/

//  Type for a IMGREG_E_SENSOR_REG -> register address map entry
/*## type IMGREG_S_RegDef */
typedef struct IMGREG_S_RegDef {
    //  Description:   Imager register address
    //  Range:         0-0xFFFF
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_RegAddr;		/*## attribute ui16_RegAddr */
    //  Description:   Register symbolic name, which mapps to 'ui16_RegAddr'
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IMGREG_E_SENSOR_REG e_Reg;		/*## attribute e_Reg */
} IMGREG_S_RegDef;

//  Type for an imager model map entry. It's used to build a map (Model-Id, Revision) -> IC_E_ImagerModel.
/*## type IMGREG_S_ImagerModelMap */
typedef struct IMGREG_S_ImagerModelMap {
    //  Description:   Imager model ID (register value)
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_ModelId;		/*## attribute ui16_ModelId */
    //  Description:   Imager revision number
    //  Range:         0 - 0xFF
    //  Resolution:    1
    //  Unit:          none
    uint8 ui8_Revision;		/*## attribute ui8_Revision */
    //  Description:   Mask, which is applied to the revision number when looking up a specific imager
    //                 in the map.
    //  Range:         0 - 0xFF
    //  Resolution:    1
    //  Unit:          none
    uint8 ui8_RevisionCompareMask;		/*## attribute ui8_RevisionCompareMask */
    IC_E_ImagerModel e_Model;		/*## attribute e_Model */
} IMGREG_S_ImagerModelMap;

//  Stores imager register address and a data word
/*## type IMGREG_S_RegDataPair */
typedef struct IMGREG_S_RegDataPair {
    //  Description:   Imager register address
    //  Range:         0-0xFFFF
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_Addr;		/*## attribute ui16_Addr */
    //  Description:   Imager register value
    //  Range:         0-0xFFFF
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_Data;		/*## attribute ui16_Data */
} IMGREG_S_RegDataPair;

//  Type for defining a power-up reset register value entry
/*## type IMGREG_S_RegDefaultEntry */
typedef struct IMGREG_S_RegDefaultEntry {
    //  Imager register address of current entry
    IC_t_RegAddr RgAddr_RegAddress;		/*## attribute RgAddr_RegAddress */
    //  Definition of reset-values for each type of imager. Order is defined by enum 'IC_E_ImagerModel'.
    IC_t_RegVal aRv_ResetValues[IC_e_IMAGERMODEL__NUM_ENTRIES__];		/*## attribute aRv_ResetValues */
} IMGREG_S_RegDefaultEntry;

//  This array maps enum-values (indexes) to register-addresses. It's indexed by enum-values
//  'IMGREG_E_SENSOR_REG' and contains the corresponding register addresses.
//  
//  This LUT is initialized in IMGREG_e_Init().
/*## attribute IMGREG_aui16_ImagerIndexToAddrMap */
static uint16 IMGREG_aui16_ImagerIndexToAddrMap[IMGREG_cui16_NumImagerRegs];

//  This array defines the register-addresses for all known registers. The order of addresses must be
//  strictly increasing! This is checked when the module is initialized.
/*## attribute IMGREG_cs_ImagerRegMap */
static const IMGREG_S_RegDef IMGREG_cs_ImagerRegMap[IMGREG_cui16_NumImagerRegs] = {
    // Define only required registers if code is compiled for ECU, as they consume
    // memory and CPU-Time for extraction
    //
    // Magic numbers are required here of course:
    //   PRQA S 3120 REGDEFS
#if (IC_COMPILE_FOR_MTS == 0)
    { 0x3000, IMGREG_e_REG_MODEL_ID },
    { 0x3002, IMGREG_e_REG_Y_ADDR_START },
    { 0x3004, IMGREG_e_REG_X_ADDR_START },
    { 0x3006, IMGREG_e_REG_Y_ADDR_END },
    { 0x3008, IMGREG_e_REG_X_ADDR_END },
    { 0x300a, IMGREG_e_REG_FRAME_LENGTH_LINES },
    { 0x300c, IMGREG_e_REG_LINE_LENGTH_PCK },
    { 0x300e, IMGREG_e_REG_REVISION_NUMBER },
    { 0x3010, IMGREG_e_REG_LOCK_CONTROL },
    { 0x3012, IMGREG_e_REG_COARSE_INTEGRATION_TIME },
    { 0x301a, IMGREG_e_REG_RESET_REGISTER },
    { 0x301e, IMGREG_e_REG_DATA_PEDESTAL },
    { 0x3028, IMGREG_e_REG_ROW_SPEED },
    { 0x302a, IMGREG_e_REG_VT_PIX_CLK_DIV },
    { 0x302c, IMGREG_e_REG_VT_SYS_CLK_DIV },
    { 0x302e, IMGREG_e_REG_PRE_PLL_CLK_DIV },
    { 0x3030, IMGREG_e_REG_PLL_MULTIPLIER },
    { 0x3032, IMGREG_e_REG_DIGITAL_BINNING },
    { 0x303a, IMGREG_e_REG_FRAME_COUNT },
    { 0x3040, IMGREG_e_REG_READ_MODE },
    { 0x3044, IMGREG_e_REG_DARK_CONTROL },
    { 0x3056, IMGREG_e_REG_GREEN1_GAIN },
    { 0x3058, IMGREG_e_REG_BLUE_GAIN },
    { 0x305a, IMGREG_e_REG_RED_GAIN },
    { 0x305c, IMGREG_e_REG_GREEN2_GAIN },
    { 0x305e, IMGREG_e_REG_GLOBAL_GAIN },
    { 0x3064, IMGREG_e_REG_EMBEDDED_DATA_CTRL },
    { 0x306e, IMGREG_e_REG_DATAPATH_SELECT },
    { 0x3070, IMGREG_e_REG_TEST_PATTERN_MODE },
    { 0x3072, IMGREG_e_REG_TEST_DATA_RED },
    { 0x3074, IMGREG_e_REG_TEST_DATA_GREENR },
    { 0x3076, IMGREG_e_REG_TEST_DATA_BLUE },
    { 0x3078, IMGREG_e_REG_TEST_DATA_GREENB },
    { 0x307a, IMGREG_e_REG_TEST_RAW_MODE },
    { 0x307c, IMGREG_e_REG_EXPOSURE_T2 },
    { 0x307e, IMGREG_e_REG_MINIMUM_T3 },
    { 0x3080, IMGREG_e_REG_EXPOSURE_T3 },
    { 0x3082, IMGREG_e_REG_OPERATION_MODE_CTRL },
    { 0x3086, IMGREG_e_REG_SEQ_DATA_PORT },
    { 0x3088, IMGREG_e_REG_SEQ_CTRL_PORT },
    { 0x30ac, IMGREG_e_REG_EXPOSURE_T1 },
    { 0x30b0, IMGREG_e_REG_DIGITAL_TEST },
    { 0x30b2, IMGREG_e_REG_TEMPSENS_DATA },
    { 0x30b4, IMGREG_e_REG_TEMPSENS_CTRL },
    { 0x30ba, IMGREG_e_REG_DIGITAL_CTRL },
    { 0x30c6, IMGREG_e_REG_TEMPSENS_CALIB1 },
    { 0x30c8, IMGREG_e_REG_TEMPSENS_CALIB2 },
    { 0x30ca, IMGREG_e_REG_TEMPSENS_CALIB3 },
    { 0x30cc, IMGREG_e_REG_TEMPSENS_CALIB4 },
    { 0x30d4, IMGREG_e_REG_COLUMN_CORRECTION },
    { 0x30d6, IMGREG_e_REG_COLUMN_CORRECTION_THRESHOLD },
    { 0x30d8, IMGREG_e_REG_COLUMN_CORRECTION_CLIP },
    { 0x30de, IMGREG_e_REG_ADC_BITS_0_1 },
    { 0x30e0, IMGREG_e_REG_ADC_BITS_2_3 },
    { 0x30e2, IMGREG_e_REG_ADC_BITS_4_5 },
    { 0x30e4, IMGREG_e_REG_ADC_BITS_6_7 },
    { 0x30e6, IMGREG_e_REG_ADC_CONFIG1 },
    { 0x30e8, IMGREG_e_REG_ADC_CONFIG2 },
    { 0x30ea, IMGREG_e_REG_GAIN_OFFSET_CTRL },
    { 0x30f0, IMGREG_e_REG_START_UP_FRAME_NR },
    { 0x30f4, IMGREG_e_REG_OFFSET_LIMIT_LOW },
    { 0x30f6, IMGREG_e_REG_OFFSET_LIMIT_HIGH },
    { 0x30f8, IMGREG_e_REG_REG_OFFSET_BTM_GL },
    { 0x3100, IMGREG_e_REG_AE_CTRL_REG },
    { 0x3102, IMGREG_e_REG_AE_LUMA_TARGET_REG },
    { 0x3104, IMGREG_e_REG_AE_HIST_TARGET_REG },
    { 0x310a, IMGREG_e_REG_AE_MAX_EV_STEP_REG },
    { 0x310c, IMGREG_e_REG_AE_DAMP_OFFSET_REG },
    { 0x310e, IMGREG_e_REG_AE_DAMP_GAIN_REG },
    { 0x3110, IMGREG_e_REG_AE_DAMP_MAX_REG },
    { 0x3130, IMGREG_e_REG_OTPM_TCFG_WRITE_01 },
    { 0x3132, IMGREG_e_REG_OTPM_TCFG_WRITE_23 },
    { 0x3134, IMGREG_e_REG_OTPM_TCFG_READ_01 },
    { 0x3136, IMGREG_e_REG_OTPM_TCFG_READ_23 },
    { 0x3138, IMGREG_e_REG_OTPM_TCFG_READ_4B },
    { 0x313a, IMGREG_e_REG_OTPM_DATA_MANUAL_L },
    { 0x313c, IMGREG_e_REG_OTPM_DATA_MANUAL_H },
    { 0x313e, IMGREG_e_REG_OTPM_DATA_MANUAL_EXTRA },
    { 0x3140, IMGREG_e_REG_AE_ROI_X_START_OFFSET },
    { 0x3142, IMGREG_e_REG_AE_ROI_Y_START_OFFSET },
    { 0x3144, IMGREG_e_REG_AE_ROI_X_SIZE },
    { 0x3146, IMGREG_e_REG_AE_ROI_Y_SIZE },
    { 0x3148, IMGREG_e_REG_AE_HIST_BEGIN_PERC },
    { 0x314a, IMGREG_e_REG_AE_HIST_END_PERC },
    { 0x314c, IMGREG_e_REG_AE_HIST_DIV },
    { 0x3180, IMGREG_e_REG_DELTA_DK_CONTROL },
    { 0x3182, IMGREG_e_REG_DELTA_DK_CLIP },
    { 0x3184, IMGREG_e_REG_DELTA_DK_T1 },
    { 0x3186, IMGREG_e_REG_DELTA_DK_T2 },
    { 0x3188, IMGREG_e_REG_DELTA_DK_T3 },
    { 0x318a, IMGREG_e_REG_HDR_MC_CTRL1 },
    { 0x318c, IMGREG_e_REG_HDR_MC_CTRL2 },
    { 0x318e, IMGREG_e_REG_HDR_MC_CTRL3 },
    { 0x3190, IMGREG_e_REG_HDR_MC_CTRL4 },
    { 0x3192, IMGREG_e_REG_HDR_MC_CTRL5 },
    { 0x3194, IMGREG_e_REG_HDR_MC_CTRL6 },
    { 0x3196, IMGREG_e_REG_HDR_MC_CTRL7 },
    { 0x3198, IMGREG_e_REG_HDR_MC_CTRL8 },
    { 0x319e, IMGREG_e_REG_HDR_MC_CTRL9 },
    { 0x31a0, IMGREG_e_REG_HDR_MC_CTRL10 },
    { 0x31a2, IMGREG_e_REG_HDR_MC_CTRL11 },
    { 0x31d0, IMGREG_e_REG_HDR_COMP },
    { 0x31d2, IMGREG_e_REG_STAT_FRAME_ID },
    { 0x31da, IMGREG_e_REG_PLL_DITHER_1 },
    { 0x31dc, IMGREG_e_REG_PLL_DITHER_2 },
    { 0x31de, IMGREG_e_REG_PLL_DITHER_3 },
    { 0x31e0, IMGREG_e_REG_PIX_DEF_ID },
    { 0x31e2, IMGREG_e_REG_PIX_DEF_ID_BASE_RAM },
    { 0x31e4, IMGREG_e_REG_PIX_DEF_ID_STREAM_RAM },
    { 0x31e6, IMGREG_e_REG_PIX_DEF_RAM_RD_ADDR },
    { 0x31f4, IMGREG_e_REG_FUSE_ID1 },
    { 0x31f6, IMGREG_e_REG_FUSE_ID2 },
    { 0x31f8, IMGREG_e_REG_FUSE_ID3 },
    { 0x31fa, IMGREG_e_REG_FUSE_ID4 },
    { 0x3ecc, IMGREG_e_REG_DAC_LD_0_1 },
    { 0x3ece, IMGREG_e_REG_DAC_LD_2_3 },
    { 0x3ed0, IMGREG_e_REG_DAC_LD_4_5 },
    { 0x3ed6, IMGREG_e_REG_DAC_LD_10_11 },
    { 0x3ed8, IMGREG_e_REG_DAC_LD_12_13 },
    { 0x3eda, IMGREG_e_REG_DAC_LD_14_15 },
    { 0x3edc, IMGREG_e_REG_DAC_LD_16_17 },
    { 0x3ede, IMGREG_e_REG_DAC_LD_18_19 },
    { 0x3ee0, IMGREG_e_REG_DAC_LD_20_21 },
    { 0x3ee2, IMGREG_e_REG_DAC_LD_22_23 },
    { 0x3ee4, IMGREG_e_REG_DAC_LD_24_25 },
    { 0x3ee6, IMGREG_e_REG_DAC_LD_26_27 },
    { 0x3ee8, IMGREG_e_REG_DAC_LD_28_29 },
    { 0x3eea, IMGREG_e_REG_DAC_LD_30_31 },
    { 0x3fd0, IMGREG_e_REG_BIST_BUFFERS_CONTROL1 },
    { 0x3fd4, IMGREG_e_REG_BIST_BUFFERS_STATUS1 }
#else
    // Define all registers if code is compiled for MTS/Win32 PC
    { 0x3000, IMGREG_e_REG_MODEL_ID },
    { 0x3002, IMGREG_e_REG_Y_ADDR_START },
    { 0x3004, IMGREG_e_REG_X_ADDR_START },
    { 0x3006, IMGREG_e_REG_Y_ADDR_END },
    { 0x3008, IMGREG_e_REG_X_ADDR_END },
    { 0x300a, IMGREG_e_REG_FRAME_LENGTH_LINES },
    { 0x300c, IMGREG_e_REG_LINE_LENGTH_PCK },
    { 0x300e, IMGREG_e_REG_REVISION_NUMBER },
    { 0x3010, IMGREG_e_REG_LOCK_CONTROL },
    { 0x3012, IMGREG_e_REG_COARSE_INTEGRATION_TIME },
    { 0x3014, IMGREG_e_REG_FINE_INTEGRATION_TIME },
    { 0x3016, IMGREG_e_REG_COARSE_INTEGRATION_TIME_CB },
    { 0x3018, IMGREG_e_REG_FINE_INTEGRATION_TIME_CB },
    { 0x301a, IMGREG_e_REG_RESET_REGISTER },
    { 0x301e, IMGREG_e_REG_DATA_PEDESTAL },
    { 0x3026, IMGREG_e_REG_GPI_STATUS },
    { 0x3028, IMGREG_e_REG_ROW_SPEED },
    { 0x302a, IMGREG_e_REG_VT_PIX_CLK_DIV },
    { 0x302c, IMGREG_e_REG_VT_SYS_CLK_DIV },
    { 0x302e, IMGREG_e_REG_PRE_PLL_CLK_DIV },
    { 0x3030, IMGREG_e_REG_PLL_MULTIPLIER },
    { 0x3032, IMGREG_e_REG_DIGITAL_BINNING },
    { 0x303a, IMGREG_e_REG_FRAME_COUNT },
    { 0x303c, IMGREG_e_REG_FRAME_STATUS },
    { 0x3040, IMGREG_e_REG_READ_MODE },
    { 0x3044, IMGREG_e_REG_DARK_CONTROL },
    { 0x3046, IMGREG_e_REG_FLASH },
    { 0x304a, IMGREG_e_REG_OTPM_CONTROL },
    { 0x304c, IMGREG_e_REG_OTPM_RECORD },
    { 0x304e, IMGREG_e_REG_OTPM_STATUS },
    { 0x3050, IMGREG_e_REG_OTPM_MANUAL_CONTROL },
    { 0x3052, IMGREG_e_REG_OTPM_CFG },
    { 0x3054, IMGREG_e_REG_OTPM_EXPR },
    { 0x3056, IMGREG_e_REG_GREEN1_GAIN },
    { 0x3058, IMGREG_e_REG_BLUE_GAIN },
    { 0x305a, IMGREG_e_REG_RED_GAIN },
    { 0x305c, IMGREG_e_REG_GREEN2_GAIN },
    { 0x305e, IMGREG_e_REG_GLOBAL_GAIN },
    { 0x3064, IMGREG_e_REG_EMBEDDED_DATA_CTRL },
    { 0x306c, IMGREG_e_REG_SCALER_TEST },
    { 0x306e, IMGREG_e_REG_DATAPATH_SELECT },
    { 0x3070, IMGREG_e_REG_TEST_PATTERN_MODE },
    { 0x3072, IMGREG_e_REG_TEST_DATA_RED },
    { 0x3074, IMGREG_e_REG_TEST_DATA_GREENR },
    { 0x3076, IMGREG_e_REG_TEST_DATA_BLUE },
    { 0x3078, IMGREG_e_REG_TEST_DATA_GREENB },
    { 0x307a, IMGREG_e_REG_TEST_RAW_MODE },
    { 0x307c, IMGREG_e_REG_EXPOSURE_T2 },
    { 0x307e, IMGREG_e_REG_MINIMUM_T3 },
    { 0x3080, IMGREG_e_REG_EXPOSURE_T3 },
    { 0x3082, IMGREG_e_REG_OPERATION_MODE_CTRL },
    { 0x3084, IMGREG_e_REG_OPERATION_MODE_CTRL_CB },
    { 0x3086, IMGREG_e_REG_SEQ_DATA_PORT },
    { 0x3088, IMGREG_e_REG_SEQ_CTRL_PORT },
    { 0x308a, IMGREG_e_REG_X_ADDR_START_CB },
    { 0x308c, IMGREG_e_REG_Y_ADDR_START_CB },
    { 0x308e, IMGREG_e_REG_X_ADDR_END_CB },
    { 0x3090, IMGREG_e_REG_Y_ADDR_END_CB },
    { 0x309e, IMGREG_e_REG_ERS_PROG_START_ADDR },
    { 0x30a0, IMGREG_e_REG_X_EVEN_INC },
    { 0x30a2, IMGREG_e_REG_X_ODD_INC },
    { 0x30a4, IMGREG_e_REG_Y_EVEN_INC },
    { 0x30a6, IMGREG_e_REG_Y_ODD_INC },
    { 0x30a8, IMGREG_e_REG_Y_ODD_INC_CB },
    { 0x30aa, IMGREG_e_REG_FRAME_LENGTH_LINES_CB },
    { 0x30ac, IMGREG_e_REG_EXPOSURE_T1 },
    { 0x30b0, IMGREG_e_REG_DIGITAL_TEST },
    { 0x30b2, IMGREG_e_REG_TEMPSENS_DATA },
    { 0x30b4, IMGREG_e_REG_TEMPSENS_CTRL },
    { 0x30ba, IMGREG_e_REG_DIGITAL_CTRL },
    { 0x30bc, IMGREG_e_REG_GREEN1_GAIN_CB },
    { 0x30be, IMGREG_e_REG_BLUE_GAIN_CB },
    { 0x30c0, IMGREG_e_REG_RED_GAIN_CB },
    { 0x30c2, IMGREG_e_REG_GREEN2_GAIN_CB },
    { 0x30c4, IMGREG_e_REG_GLOBAL_GAIN_CB },
    { 0x30c6, IMGREG_e_REG_TEMPSENS_CALIB1 },
    { 0x30c8, IMGREG_e_REG_TEMPSENS_CALIB2 },
    { 0x30ca, IMGREG_e_REG_TEMPSENS_CALIB3 },
    { 0x30cc, IMGREG_e_REG_TEMPSENS_CALIB4 },
    { 0x30d4, IMGREG_e_REG_COLUMN_CORRECTION },
    { 0x30d6, IMGREG_e_REG_COLUMN_CORRECTION_THRESHOLD },
    { 0x30d8, IMGREG_e_REG_COLUMN_CORRECTION_CLIP },
    { 0x30de, IMGREG_e_REG_ADC_BITS_0_1 },
    { 0x30e0, IMGREG_e_REG_ADC_BITS_2_3 },
    { 0x30e2, IMGREG_e_REG_ADC_BITS_4_5 },
    { 0x30e4, IMGREG_e_REG_ADC_BITS_6_7 },
    { 0x30e6, IMGREG_e_REG_ADC_CONFIG1 },
    { 0x30e8, IMGREG_e_REG_ADC_CONFIG2 },
    { 0x30ea, IMGREG_e_REG_GAIN_OFFSET_CTRL },
    { 0x30ec, IMGREG_e_REG_REG_OFFSET_TOP_GL },
    { 0x30ee, IMGREG_e_REG_REG_OFFSET_TOP_GH },
    { 0x30f0, IMGREG_e_REG_START_UP_FRAME_NR },
    { 0x30f4, IMGREG_e_REG_OFFSET_LIMIT_LOW },
    { 0x30f6, IMGREG_e_REG_OFFSET_LIMIT_HIGH },
    { 0x30f8, IMGREG_e_REG_REG_OFFSET_BTM_GL },
    { 0x30fa, IMGREG_e_REG_REG_OFFSET_BTM_GH },
    { 0x3100, IMGREG_e_REG_AE_CTRL_REG },
    { 0x3102, IMGREG_e_REG_AE_LUMA_TARGET_REG },
    { 0x3104, IMGREG_e_REG_AE_HIST_TARGET_REG },
    { 0x3106, IMGREG_e_REG_AE_HYSTERESIS_REG },
    { 0x3108, IMGREG_e_REG_AE_MIN_EV_STEP_REG },
    { 0x310a, IMGREG_e_REG_AE_MAX_EV_STEP_REG },
    { 0x310c, IMGREG_e_REG_AE_DAMP_OFFSET_REG },
    { 0x310e, IMGREG_e_REG_AE_DAMP_GAIN_REG },
    { 0x3110, IMGREG_e_REG_AE_DAMP_MAX_REG },
    { 0x3112, IMGREG_e_REG_AE_DCG_EXPOSURE_HIGH_REG },
    { 0x3114, IMGREG_e_REG_AE_DCG_EXPOSURE_LOW_REG },
    { 0x3116, IMGREG_e_REG_AE_DCG_GAIN_FACTOR_REG },
    { 0x3118, IMGREG_e_REG_AE_DCG_GAIN_FACTOR_INV_REG },
    { 0x311c, IMGREG_e_REG_AE_MAX_EXPOSURE_REG },
    { 0x311e, IMGREG_e_REG_AE_MIN_EXPOSURE_REG },
    { 0x3120, IMGREG_e_REG_AE_LOW_MEAN_TARGET_REG },
    { 0x3122, IMGREG_e_REG_AE_HIST_LOW_THRESH_REG },
    { 0x3124, IMGREG_e_REG_AE_DARK_CUR_THRESH_REG },
    { 0x3126, IMGREG_e_REG_AE_ALPHA_V1_REG },
    { 0x3128, IMGREG_e_REG_AE_ALPHA_COEF_REG },
    { 0x312a, IMGREG_e_REG_AE_CURRENT_GAINS },
    { 0x3130, IMGREG_e_REG_OTPM_TCFG_WRITE_01 },
    { 0x3132, IMGREG_e_REG_OTPM_TCFG_WRITE_23 },
    { 0x3134, IMGREG_e_REG_OTPM_TCFG_READ_01 },
    { 0x3136, IMGREG_e_REG_OTPM_TCFG_READ_23 },
    { 0x3138, IMGREG_e_REG_OTPM_TCFG_READ_4B },
    { 0x313a, IMGREG_e_REG_OTPM_DATA_MANUAL_L },
    { 0x313c, IMGREG_e_REG_OTPM_DATA_MANUAL_H },
    { 0x313e, IMGREG_e_REG_OTPM_DATA_MANUAL_EXTRA },
    { 0x3140, IMGREG_e_REG_AE_ROI_X_START_OFFSET },
    { 0x3142, IMGREG_e_REG_AE_ROI_Y_START_OFFSET },
    { 0x3144, IMGREG_e_REG_AE_ROI_X_SIZE },
    { 0x3146, IMGREG_e_REG_AE_ROI_Y_SIZE },
    { 0x3148, IMGREG_e_REG_AE_HIST_BEGIN_PERC },
    { 0x314a, IMGREG_e_REG_AE_HIST_END_PERC },
    { 0x314c, IMGREG_e_REG_AE_HIST_DIV },
    { 0x314e, IMGREG_e_REG_AE_NORM_WIDTH_MIN },
    { 0x3150, IMGREG_e_REG_AE_MEAN_H },
    { 0x3152, IMGREG_e_REG_AE_MEAN_L },
    { 0x3154, IMGREG_e_REG_AE_HIST_BEGIN_H },
    { 0x3156, IMGREG_e_REG_AE_HIST_BEGIN_L },
    { 0x3158, IMGREG_e_REG_AE_HIST_END_H },
    { 0x315a, IMGREG_e_REG_AE_HIST_END_L },
    { 0x315c, IMGREG_e_REG_AE_HIST_END_MEAN_H },
    { 0x315e, IMGREG_e_REG_AE_HIST_END_MEAN_L },
    { 0x3160, IMGREG_e_REG_AE_PERC_LOW_END },
    { 0x3162, IMGREG_e_REG_AE_NORM_ABS_DEV },
    { 0x3164, IMGREG_e_REG_AE_COARSE_INTEGRATION_TIME },
    { 0x3166, IMGREG_e_REG_AE_AG_EXPOSURE_HI },
    { 0x3168, IMGREG_e_REG_AE_AG_EXPOSURE_LO },
    { 0x316a, IMGREG_e_REG_AE_AG_GAIN1 },
    { 0x316c, IMGREG_e_REG_AE_AG_GAIN2 },
    { 0x316e, IMGREG_e_REG_AE_AG_GAIN3 },
    { 0x3170, IMGREG_e_REG_AE_INV_AG_GAIN1 },
    { 0x3172, IMGREG_e_REG_AE_INV_AG_GAIN2 },
    { 0x3174, IMGREG_e_REG_AE_INV_AG_GAIN3 },
    { 0x3180, IMGREG_e_REG_DELTA_DK_CONTROL },
    { 0x3182, IMGREG_e_REG_DELTA_DK_CLIP },
    { 0x3184, IMGREG_e_REG_DELTA_DK_T1 },
    { 0x3186, IMGREG_e_REG_DELTA_DK_T2 },
    { 0x3188, IMGREG_e_REG_DELTA_DK_T3 },
    { 0x318a, IMGREG_e_REG_HDR_MC_CTRL1 },
    { 0x318c, IMGREG_e_REG_HDR_MC_CTRL2 },
    { 0x318e, IMGREG_e_REG_HDR_MC_CTRL3 },
    { 0x3190, IMGREG_e_REG_HDR_MC_CTRL4 },
    { 0x3192, IMGREG_e_REG_HDR_MC_CTRL5 },
    { 0x3194, IMGREG_e_REG_HDR_MC_CTRL6 },
    { 0x3196, IMGREG_e_REG_HDR_MC_CTRL7 },
    { 0x3198, IMGREG_e_REG_HDR_MC_CTRL8 },
    { 0x319a, IMGREG_e_REG_HDR_COMP_KNEE1 },
    { 0x319c, IMGREG_e_REG_HDR_COMP_KNEE2 },
    { 0x319e, IMGREG_e_REG_HDR_MC_CTRL9 },
    { 0x31a0, IMGREG_e_REG_HDR_MC_CTRL10 },
    { 0x31a2, IMGREG_e_REG_HDR_MC_CTRL11 },
    { 0x31c0, IMGREG_e_REG_HISPI_TIMING },
    { 0x31c6, IMGREG_e_REG_HISPI_CONTROL_STATUS },
    { 0x31c8, IMGREG_e_REG_HISPI_CRC_0 },
    { 0x31ca, IMGREG_e_REG_HISPI_CRC_1 },
    { 0x31cc, IMGREG_e_REG_HISPI_CRC_2 },
    { 0x31ce, IMGREG_e_REG_HISPI_CRC_3 },
    { 0x31d0, IMGREG_e_REG_HDR_COMP },
    { 0x31d2, IMGREG_e_REG_STAT_FRAME_ID },
    { 0x31d6, IMGREG_e_REG_I2C_WRT_CHECKSUM },
    { 0x31da, IMGREG_e_REG_PLL_DITHER_1 },
    { 0x31dc, IMGREG_e_REG_PLL_DITHER_2 },
    { 0x31de, IMGREG_e_REG_PLL_DITHER_3 },
    { 0x31e0, IMGREG_e_REG_PIX_DEF_ID },
    { 0x31e2, IMGREG_e_REG_PIX_DEF_ID_BASE_RAM },
    { 0x31e4, IMGREG_e_REG_PIX_DEF_ID_STREAM_RAM },
    { 0x31e6, IMGREG_e_REG_PIX_DEF_RAM_RD_ADDR },
    { 0x31e8, IMGREG_e_REG_HORIZONTAL_CURSOR_POSITION },
    { 0x31ea, IMGREG_e_REG_VERTICAL_CURSOR_POSITION },
    { 0x31ec, IMGREG_e_REG_HORIZONTAL_CURSOR_WIDTH },
    { 0x31ee, IMGREG_e_REG_VERTICAL_CURSOR_WIDTH },
    { 0x31f4, IMGREG_e_REG_FUSE_ID1 },
    { 0x31f6, IMGREG_e_REG_FUSE_ID2 },
    { 0x31f8, IMGREG_e_REG_FUSE_ID3 },
    { 0x31fa, IMGREG_e_REG_FUSE_ID4 },
    { 0x31fc, IMGREG_e_REG_I2C_IDS },
    { 0x31fe, IMGREG_e_REG_CUSTOMER_REV },
    { 0x3ecc, IMGREG_e_REG_DAC_LD_0_1 },
    { 0x3ece, IMGREG_e_REG_DAC_LD_2_3 },
    { 0x3ed0, IMGREG_e_REG_DAC_LD_4_5 },
    { 0x3ed2, IMGREG_e_REG_DAC_LD_6_7 },
    { 0x3ed4, IMGREG_e_REG_DAC_LD_8_9 },
    { 0x3ed6, IMGREG_e_REG_DAC_LD_10_11 },
    { 0x3ed8, IMGREG_e_REG_DAC_LD_12_13 },
    { 0x3eda, IMGREG_e_REG_DAC_LD_14_15 },
    { 0x3edc, IMGREG_e_REG_DAC_LD_16_17 },
    { 0x3ede, IMGREG_e_REG_DAC_LD_18_19 },
    { 0x3ee0, IMGREG_e_REG_DAC_LD_20_21 },
    { 0x3ee2, IMGREG_e_REG_DAC_LD_22_23 },
    { 0x3ee4, IMGREG_e_REG_DAC_LD_24_25 },
    { 0x3ee6, IMGREG_e_REG_DAC_LD_26_27 },
    { 0x3ee8, IMGREG_e_REG_DAC_LD_28_29 },
    { 0x3eea, IMGREG_e_REG_DAC_LD_30_31 },
    { 0x3fd0, IMGREG_e_REG_BIST_BUFFERS_CONTROL1 },
    { 0x3fd2, IMGREG_e_REG_BIST_BUFFERS_CONTROL2 },
    { 0x3fd4, IMGREG_e_REG_BIST_BUFFERS_STATUS1 },
    { 0x3fd6, IMGREG_e_REG_BIST_BUFFERS_STATUS2 },
    { 0x3fd8, IMGREG_e_REG_BIST_BUFFERS_DATA1 },
    { 0x3fda, IMGREG_e_REG_BIST_BUFFERS_DATA2 },
    { 0x3fe0, IMGREG_e_REG_BIST_CONTROL },
    { 0x3fe2, IMGREG_e_REG_BIST_STATUS },
    { 0x3fe4, IMGREG_e_REG_BIST_ADDRESS },
    { 0x3fe6, IMGREG_e_REG_BIST_DATA1 },
    { 0x3fe8, IMGREG_e_REG_BIST_DATA2 },
    { 0x3fea, IMGREG_e_REG_BIST_DATA3 },
    { 0x3fec, IMGREG_e_REG_BIST_DATA4 }
#endif
    // PRQA L:REGDEFS
};

//  This table maps imager model and revision ID to the corresponding enum-value 'IC_e_ImagerModel'.
//  The Mask is applied to the revision number and can be used e.g. to ignore the lower nibble.
//  
//  PRQA S 3218 2
/*## attribute IMGREG_cas_ModelMap */
static const IMGREG_S_ImagerModelMap IMGREG_cas_ModelMap[IC_e_IMAGERMODEL__NUM_ENTRIES__] = {
    // Magic numbers are required here of course:
    // PRQA S 3120 MODEL_MAP
    //
    // ModelId, Revision, Mask,  Default value Column Mapping
    { 0x2400,   0x40,     0xf0,  IC_e_IMAGERMODEL_A1000_REV4 },
    { 0x2400,   0x50,     0xf0,  IC_e_IMAGERMODEL_A1000_REV5 },
    { 0x2400,   0x60,     0xf0,  IC_e_IMAGERMODEL_A1000_REV6 },
    { 0x2300,   0x10,     0xf0,  IC_e_IMAGERMODEL_ARX550_REV1 }
    // PRQA L:MODEL_MAP
};

//  Contains power-up reset values for several (but not all) imager registers, which can be used for
//  register checks. As the values differ between different imager models and revisions, there are
//  separate columns for each imager type defined in IC_E_ImagerModel.
//  
//  PRQA S 3218,3674 2
/*## attribute IMGREG_cas_RegResetValues */
static const IMGREG_S_RegDefaultEntry IMGREG_cas_RegResetValues[] = {
    // Magic numbers are required here of course:
    // PRQA S 3120 RESET_VALUES
    { 0x3000, { 0x2400, 0x2400, 0x2400, 0x2300 } },
    { 0x306e, { 0x9210, 0x9210, 0x9210, 0xfe10 } },
    { 0x3082, { 0x0029, 0x0029, 0x0029, 0x0028 } },
    { 0x3144, { 0x0504, 0x0504, 0x0504, 0x0350 } },
    { 0x3146, { 0x03c4, 0x03c4, 0x03c4, 0x027e } },
    { 0x3edc, { 0x0080, 0x0070, 0x0070, 0x0080 } },
    { 0x3ee0, { 0x047d, 0x067d, 0x067d, 0x047d } }
    // PRQA L:RESET_VALUES
};

//  Contains power-up reset values for several (but not all) imager registers, which can be used for
//  register checks. This array stores values that are common to all imager models and revisions.
//  
//  PRQA S 3218,3674 2
/*## attribute IMGREG_cas_RegResetValuesAllRevs */
static const IMGREG_S_RegDataPair IMGREG_cas_RegResetValuesAllRevs[] = {
    // Magic numbers are required here of course:
    // PRQA S 3120 RESET_VALUES_ALLREVS
    { 0x300c, 0x0672 },
    { 0x3010, 0xbeef },
    { 0x3012, 0x0010 },
    { 0x3070, 0x0000 },
    { 0x30c8, 0x4567 },
    { 0x30cc, 0xcdef },
    { 0x30de, 0x5454 },
    { 0x30ea, 0x0c00 },
    { 0x30f4, 0x0000 },
    { 0x30f6, 0x03ff },
    { 0x30f8, 0x0000 },
    { 0x3100, 0x0000 },
    { 0x3102, 0x0666 },
    { 0x3104, 0xc000 },
    { 0x310a, 0x0002 },
    { 0x310c, 0x0010 },
    { 0x310e, 0x0010 },
    { 0x3110, 0x00e0 },
    { 0x3130, 0x0f1f },
    { 0x3132, 0x0f1f },
    { 0x3134, 0x1818 },
    { 0x3136, 0x3131 },
    { 0x3138, 0x4431 },
    { 0x313a, 0x0000 },
    { 0x313c, 0x0000 },
    { 0x313e, 0x0000 },
    { 0x3140, 0x0000 },
    { 0x3142, 0x0000 },
    { 0x31d0, 0x0001 },
    { 0x31da, 0x0000 },
    { 0x31dc, 0x0000 },
    { 0x31de, 0x0000 },
    { 0x31e0, 0x0000 },
    { 0x31e2, 0x0000 },
    { 0x31e4, 0x0000 },
    { 0x31e6, 0x0000 },
    { 0x3ecc, 0x0010 },
    { 0x3ece, 0x1010 },
    { 0x3ed0, 0x1000 },
    { 0x3ed6, 0x00bd },
    { 0x3ee2, 0xa46b },
    { 0x3ee4, 0xd208 },
    { 0x3eea, 0x0000 },
    { 0x3fd0, 0x0f00 },
    // PRQA L:RESET_VALUES_ALLREVS
};

/*## operation IMGREG_e_Init() */
#pragma push
#pragma optimize_for_size on
IMGREG_E_ERROR IMGREG_e_Init(void) {
    /*#[ operation IMGREG_e_Init() */
    const uint16 cui16_EmptyMapEntry = 0x0000;
    IMGREG_E_ERROR      e_Ret = IMGREG_e_ERR_OK;
    IMGREG_E_SENSOR_REG e_Reg = IMGREG_e_REG__LAST_ENTRY_;
    uint16 ui16_LoopCnt       = 0;
    uint16 ui16_Addr          = 0x0000;
    uint16 ui16_AddrPrevious  = 0x0000;
    
    // First check if element-count of enum matches the element-count of the address-map
    // NOTE: This is a static code check, which will always evaluate to false if code is OK.
    //       QAC sees this, so disable warnings:
    // PRQA S 3325,3201 3
    if (IMGREG_cui16_NumImagerRegs != IC_ARRLEN(IMGREG_cs_ImagerRegMap))
    {
      e_Ret = IMGREG_e_ERR_REGISTERCOUNT_NOTMATCHED;
    }
    
    if (IMGREG_e_ERR_OK == e_Ret) // PRQA S 3355,3358
    {
      // Clean mapping
      for (ui16_LoopCnt=0; ui16_LoopCnt<IMGREG_cui16_NumImagerRegs; ui16_LoopCnt++)
      {
        IMGREG_aui16_ImagerIndexToAddrMap[ui16_LoopCnt] = cui16_EmptyMapEntry;
      }
    
      // Create LUT for mapping IMGREG_E_SENSOR_REG -> Address
      for (ui16_LoopCnt=0; ui16_LoopCnt<IMGREG_cui16_NumImagerRegs; ui16_LoopCnt++)
      {
        e_Reg     = IMGREG_cs_ImagerRegMap[ui16_LoopCnt].e_Reg;
        ui16_Addr = IMGREG_cs_ImagerRegMap[ui16_LoopCnt].ui16_RegAddr;
        IMGREG_aui16_ImagerIndexToAddrMap[(uint16)e_Reg] = ui16_Addr;
        if (ui16_Addr <= ui16_AddrPrevious)
        {
          // Address order is not strictly increasing! This is required by some functions!
          e_Ret = IMGREG_e_ERR_REGISTERMAP;
        }
        ui16_AddrPrevious = ui16_Addr;
      }
    }
    
    if (IMGREG_e_ERR_OK ==  e_Ret)
    {
      // Check if our mapping is complete
      for (ui16_LoopCnt=0; ui16_LoopCnt<IMGREG_cui16_NumImagerRegs; ui16_LoopCnt++)
      {
        if (cui16_EmptyMapEntry == IMGREG_aui16_ImagerIndexToAddrMap[ui16_LoopCnt])
        {
          e_Ret = IMGREG_e_ERR_REGISTERMAP;
        }
      }
    }
    
    return e_Ret;
    /*#]*/
}
#pragma pop

/*## operation IMGREG_ui16_GetRegAddr(const IMGREG_E_SENSOR_REG) */
uint16 IMGREG_ui16_GetRegAddr(const IMGREG_E_SENSOR_REG e_Register) {
    /*#[ operation IMGREG_ui16_GetRegAddr(const IMGREG_E_SENSOR_REG) */
    uint16 ui16_RegAddr = 0;
    if (e_Register < IMGREG_e_REG__LAST_ENTRY_)
    {
      ui16_RegAddr = IMGREG_aui16_ImagerIndexToAddrMap[e_Register];
    }
    return ui16_RegAddr;
    /*#]*/
}

/*## operation IMGREG_e_FindRegByAddr(const uint16) */
#pragma push
#pragma optimize_for_size on
IMGREG_E_SENSOR_REG IMGREG_e_FindRegByAddr(const uint16 ui16_RegAddr) {
    /*#[ operation IMGREG_e_FindRegByAddr(const uint16) */
    uint16 ui16_Index = 0;
    IMGREG_E_SENSOR_REG e_Reg = IMGREG_e_REG__LAST_ENTRY_;
    
    // Loop through register-map and find register
    for (ui16_Index = 0; ui16_Index < IMGREG_cui16_NumImagerRegs; ui16_Index++)
    {
      if (IMGREG_cs_ImagerRegMap[ui16_Index].ui16_RegAddr == ui16_RegAddr)
      {
        e_Reg = IMGREG_cs_ImagerRegMap[ui16_Index].e_Reg;
        break;
      }
    }
    return e_Reg;
    /*#]*/
}
#pragma pop

/*## operation IMGREG_e_GetResetValues(IC_S_RegBuff * const,const uint16,const uint8) */
#pragma push
#pragma optimize_for_size on
IMGREG_E_ERROR IMGREG_e_GetResetValues(IC_S_RegBuff * const pRb_TargetRegBuff, const uint16 ui16_ModelId, const uint8 ui8_RevisionNum) {
    /*#[ operation IMGREG_e_GetResetValues(IC_S_RegBuff * const,const uint16,const uint8) */
    IMGREG_E_ERROR e_Ret = IMGREG_e_ERR_OK;
    uint16 ui16_RegIdx = 0;
    uint16 ui16_EntryIdxCommon = 0;
    uint16 ui16_EntryIdxIndiv = 0;
    uint16 ui16_LoopCnt = 0;
    uint16 ui16_RegAddr = 0;
    uint16 ui16_ResetValue = 0;
    uint8  ui8_RevNumCompare = 0;
    boolean b_ValueFound = b_FALSE;
    IC_E_ImagerModel e_Model = IC_e_IMAGERMODEL__NUM_ENTRIES__;
    IMGREG_S_ImagerModelMap const *ps_ModMap;
    IMGREG_S_RegDefaultEntry const *ps_Entry;
    
    // Nullpointer check
    if (NULL == pRb_TargetRegBuff)
    {
      e_Ret = IMGREG_e_ERR_NULLPOINTER;
    }
    else
    {
      // Find the default register values column for our imager revision
      for (ui16_LoopCnt = 0; ui16_LoopCnt < IC_ARRLEN(IMGREG_cas_ModelMap); ui16_LoopCnt++)
      {
        ps_ModMap = &IMGREG_cas_ModelMap[ui16_LoopCnt];
    
        // Compare register revision (XOR and apply mask). Zero result means they match!
        ui8_RevNumCompare  = (ui8_RevisionNum ^ ps_ModMap->ui8_Revision);
        ui8_RevNumCompare &= ps_ModMap->ui8_RevisionCompareMask;
        if ((ps_ModMap->ui16_ModelId == ui16_ModelId) && (ui8_RevNumCompare == 0))
        {
          e_Model = ps_ModMap->e_Model;
        }
      }
    
      // Entry not found?
      if (e_Model >= IC_e_IMAGERMODEL__NUM_ENTRIES__)
      {
        e_Ret = IMGREG_e_ERR_UNSUPPORTED_IMAGER;
      }
      else
      {
        // Loop through all registers
        for (ui16_RegIdx = 0; ui16_RegIdx < IMGREG_cui16_NumImagerRegs; ui16_RegIdx++)
        {
          b_ValueFound = b_FALSE;
          ui16_ResetValue = 0x0000; /* Defaults to zero in case reset-value is not available */
          ui16_RegAddr = IMGREG_cs_ImagerRegMap[ui16_RegIdx].ui16_RegAddr;
    
          // Find reset value for current register address in common revision value list
          for (ui16_LoopCnt = 0;
              (ui16_LoopCnt < IC_ARRLEN(IMGREG_cas_RegResetValuesAllRevs)) && (b_ValueFound == b_FALSE);
               ui16_LoopCnt++)
          {
            // Found reset value?
            if (IMGREG_cas_RegResetValuesAllRevs[ui16_EntryIdxCommon].ui16_Addr == ui16_RegAddr)
            {
              b_ValueFound = b_TRUE;
              ui16_ResetValue = IMGREG_cas_RegResetValuesAllRevs[ui16_EntryIdxCommon].ui16_Data;
            }
    
            // Increment reset value entry-index and handle wrap-around.
            // NOTE: Resuming at last entry-index provides shorter execution-time if addresses
            //       in RegResetValues are strictly increasing
            ui16_EntryIdxCommon++;
            if (ui16_EntryIdxCommon > IC_ARRLEN(IMGREG_cas_RegResetValuesAllRevs))
            {
              ui16_EntryIdxCommon = 0;
            }
          }
    
          // Find reset value for current register address in individual revision default value list
          for (ui16_LoopCnt = 0;
              (ui16_LoopCnt < IC_ARRLEN(IMGREG_cas_RegResetValues)) && (b_ValueFound == b_FALSE);
               ui16_LoopCnt++)
          {
            ps_Entry = &IMGREG_cas_RegResetValues[ui16_EntryIdxIndiv];
    
            // Found reset value?
            if (ps_Entry->RgAddr_RegAddress == ui16_RegAddr)
            {
              b_ValueFound = b_TRUE;
              ui16_ResetValue = ps_Entry->aRv_ResetValues[e_Model];
            }
    
            // Increment reset value entry-index and handle wrap-around.
            // NOTE: Resuming at last entry-index provides shorter execution-time if addresses
            //       in RegResetValues are strictly increasing
            ui16_EntryIdxIndiv++;
            if (ui16_EntryIdxIndiv > IC_ARRLEN(IMGREG_cas_RegResetValues))
            {
              ui16_EntryIdxIndiv = 0;
            }
          }
    
          // Set output value
          pRb_TargetRegBuff->aRegs[ui16_RegIdx] = ui16_ResetValue;
        }
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

// PRQA S 7001 10
/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_registers.c
*********************************************************************/
