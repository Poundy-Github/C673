//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_initdata.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:54CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_initdata
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_initdata.c
//  LOGIN:           uidt3974  
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Array size defined implicitly by the number of initializers:
//    PRQA S 3674,3684 EOF
//  
//  We have of course tons of 'magic numbers':
//    PRQA S 3120 EOF
//  
//  Initializer arrays are used in other modules:
//    PRQA S 3211 EOF
//  
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Fri, 20, Jul 2012  9:16 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_initdata.h"
/*## dependency ic_cfg */
#include "ic_cfg.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_initdata */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## attribute ICINIT_caui16_SensorInitData */
const IC_S_RegDataPair ICINIT_caui16_SensorInitData[] = {
    { 0x301A, 0x0001 }, // Total Reset, RESET_REGISTER totally resets RAM
    { IC_cui16_SPECIALADDR_DELAY, 75 }, // insert delay of a minimum of 66ms (recommended 75!) after each reset!
    { 0x301A, 0x10D8 }, // RESET_REGISTER
    { IC_cui16_SPECIALADDR_DELAY, 75 }, // insert delay of a minimum of 66ms (recommended 75!) after each reset!
    { 0x3088, 0x8000 }, //open Sequencer Port for writing
    { 0x3086, 0x0025 }, //The Sequencer Load part of this init is for operation WITHOUT BOOSTER-HOLD at Pixel read out
    { 0x3086, 0x5050 }, //HiDy Seq Load
    { 0x3086, 0x2D26 }, //HiDy Seq Load
    { 0x3086, 0x0828 }, //HiDy Seq Load
    { 0x3086, 0x0D17 }, //HiDy Seq Load
    { 0x3086, 0x0926 }, //HiDy Seq Load
    { 0x3086, 0x0028 }, //HiDy Seq Load
    { 0x3086, 0x0526 }, //HiDy Seq Load
    { 0x3086, 0xA728 }, //HiDy Seq Load
    { 0x3086, 0x0725 }, //HiDy Seq Load
    { 0x3086, 0x8080 }, //HiDy Seq Load
    { 0x3086, 0x2925 }, //HiDy Seq Load
    { 0x3086, 0x0040 }, //HiDy Seq Load
    { 0x3086, 0x2700 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x2700 }, //HiDy Seq Load
    { 0x3086, 0x1F17 }, //HiDy Seq Load
    { 0x3086, 0x3626 }, //HiDy Seq Load
    { 0x3086, 0xA617 }, //HiDy Seq Load
    { 0x3086, 0x0326 }, //HiDy Seq Load
    { 0x3086, 0xA417 }, //HiDy Seq Load
    { 0x3086, 0x1F28 }, //HiDy Seq Load
    { 0x3086, 0x0526 }, //HiDy Seq Load
    { 0x3086, 0x2028 }, //HiDy Seq Load
    { 0x3086, 0x0425 }, //HiDy Seq Load
    { 0x3086, 0x2020 }, //HiDy Seq Load
    { 0x3086, 0x2700 }, //HiDy Seq Load
    { 0x3086, 0x171D }, //HiDy Seq Load
    { 0x3086, 0x2500 }, //HiDy Seq Load
    { 0x3086, 0x2017 }, //HiDy Seq Load
    { 0x3086, 0x1219 }, //HiDy Seq Load
    { 0x3086, 0x1703 }, //HiDy Seq Load
    { 0x3086, 0x2700 }, //HiDy Seq Load
    { 0x3086, 0x1728 }, //HiDy Seq Load
    { 0x3086, 0x2805 }, //HiDy Seq Load
    { 0x3086, 0x171A }, //HiDy Seq Load
    { 0x3086, 0x2660 }, //HiDy Seq Load
    { 0x3086, 0x175A }, //HiDy Seq Load
    { 0x3086, 0x2317 }, //HiDy Seq Load
    { 0x3086, 0x1122 }, //HiDy Seq Load
    { 0x3086, 0x1741 }, //HiDy Seq Load
    { 0x3086, 0x2500 }, //HiDy Seq Load
    { 0x3086, 0x9027 }, //HiDy Seq Load
    { 0x3086, 0x0026 }, //HiDy Seq Load
    { 0x3086, 0x1828 }, //HiDy Seq Load
    { 0x3086, 0x002E }, //HiDy Seq Load
    { 0x3086, 0x2A28 }, //HiDy Seq Load
    { 0x3086, 0x081C }, //HiDy Seq Load
    { 0x3086, 0x1470 }, //HiDy Seq Load
    { 0x3086, 0x7003 }, //HiDy Seq Load
    { 0x3086, 0x1470 }, //HiDy Seq Load
    { 0x3086, 0x7004 }, //HiDy Seq Load
    { 0x3086, 0x1470 }, //HiDy Seq Load
    { 0x3086, 0x7005 }, //HiDy Seq Load
    { 0x3086, 0x1470 }, //HiDy Seq Load
    { 0x3086, 0x7009 }, //HiDy Seq Load
    { 0x3086, 0x170C }, //HiDy Seq Load
    { 0x3086, 0x0014 }, //HiDy Seq Load
    { 0x3086, 0x0020 }, //HiDy Seq Load
    { 0x3086, 0x0014 }, //HiDy Seq Load
    { 0x3086, 0x0050 }, //HiDy Seq Load
    { 0x3086, 0x0314 }, //HiDy Seq Load
    { 0x3086, 0x0020 }, //HiDy Seq Load
    { 0x3086, 0x0314 }, //HiDy Seq Load
    { 0x3086, 0x0050 }, //HiDy Seq Load
    { 0x3086, 0x0414 }, //HiDy Seq Load
    { 0x3086, 0x0020 }, //HiDy Seq Load
    { 0x3086, 0x0414 }, //HiDy Seq Load
    { 0x3086, 0x0050 }, //HiDy Seq Load
    { 0x3086, 0x0514 }, //HiDy Seq Load
    { 0x3086, 0x0020 }, //HiDy Seq Load
    { 0x3086, 0x2405 }, //HiDy Seq Load
    { 0x3086, 0x1400 }, //HiDy Seq Load
    { 0x3086, 0x5001 }, //HiDy Seq Load
    { 0x3086, 0x2550 }, //HiDy Seq Load
    { 0x3086, 0x502D }, //HiDy Seq Load
    { 0x3086, 0x2608 }, //HiDy Seq Load
    { 0x3086, 0x280D }, //HiDy Seq Load
    { 0x3086, 0x1709 }, //HiDy Seq Load
    { 0x3086, 0x2600 }, //HiDy Seq Load
    { 0x3086, 0x2805 }, //HiDy Seq Load
    { 0x3086, 0x26A7 }, //HiDy Seq Load
    { 0x3086, 0x2807 }, //HiDy Seq Load
    { 0x3086, 0x2580 }, //HiDy Seq Load
    { 0x3086, 0x8029 }, //HiDy Seq Load
    { 0x3086, 0x2500 }, //HiDy Seq Load
    { 0x3086, 0x4027 }, //HiDy Seq Load
    { 0x3086, 0x0016 }, //HiDy Seq Load
    { 0x3086, 0x1627 }, //HiDy Seq Load
    { 0x3086, 0x0020 }, //HiDy Seq Load
    { 0x3086, 0x1736 }, //HiDy Seq Load
    { 0x3086, 0x26A6 }, //HiDy Seq Load
    { 0x3086, 0x1703 }, //HiDy Seq Load
    { 0x3086, 0x26A4 }, //HiDy Seq Load
    { 0x3086, 0x171F }, //HiDy Seq Load
    { 0x3086, 0x2805 }, //HiDy Seq Load
    { 0x3086, 0x2620 }, //HiDy Seq Load
    { 0x3086, 0x2804 }, //HiDy Seq Load
    { 0x3086, 0x2520 }, //HiDy Seq Load
    { 0x3086, 0x2027 }, //HiDy Seq Load
    { 0x3086, 0x0017 }, //HiDy Seq Load
    { 0x3086, 0x1D25 }, //HiDy Seq Load
    { 0x3086, 0x0020 }, //HiDy Seq Load
    { 0x3086, 0x1712 }, //HiDy Seq Load
    { 0x3086, 0x1A17 }, //HiDy Seq Load
    { 0x3086, 0x0327 }, //HiDy Seq Load
    { 0x3086, 0x0017 }, //HiDy Seq Load
    { 0x3086, 0x2828 }, //HiDy Seq Load
    { 0x3086, 0x0517 }, //HiDy Seq Load
    { 0x3086, 0x1A26 }, //HiDy Seq Load
    { 0x3086, 0x6017 }, //HiDy Seq Load
    { 0x3086, 0xAE25 }, //HiDy Seq Load
    { 0x3086, 0x0090 }, //HiDy Seq Load
    { 0x3086, 0x2700 }, //HiDy Seq Load
    { 0x3086, 0x2618 }, //HiDy Seq Load
    { 0x3086, 0x2800 }, //HiDy Seq Load
    { 0x3086, 0x2E2A }, //HiDy Seq Load
    { 0x3086, 0x2808 }, //HiDy Seq Load
    { 0x3086, 0x1D05 }, //HiDy Seq Load
    { 0x3086, 0x1470 }, //HiDy Seq Load
    { 0x3086, 0x7009 }, //HiDy Seq Load
    { 0x3086, 0x1720 }, //HiDy Seq Load
    { 0x3086, 0x1400 }, //HiDy Seq Load
    { 0x3086, 0x2024 }, //HiDy Seq Load
    { 0x3086, 0x1400 }, //HiDy Seq Load
    { 0x3086, 0x5002 }, //HiDy Seq Load
    { 0x3086, 0x2550 }, //HiDy Seq Load
    { 0x3086, 0x502D }, //HiDy Seq Load
    { 0x3086, 0x2608 }, //HiDy Seq Load
    { 0x3086, 0x280D }, //HiDy Seq Load
    { 0x3086, 0x1709 }, //HiDy Seq Load
    { 0x3086, 0x2600 }, //HiDy Seq Load
    { 0x3086, 0x2805 }, //HiDy Seq Load
    { 0x3086, 0x26A7 }, //HiDy Seq Load
    { 0x3086, 0x2807 }, //HiDy Seq Load
    { 0x3086, 0x2580 }, //HiDy Seq Load
    { 0x3086, 0x8029 }, //HiDy Seq Load
    { 0x3086, 0x2500 }, //HiDy Seq Load
    { 0x3086, 0x4027 }, //HiDy Seq Load
    { 0x3086, 0x0016 }, //HiDy Seq Load
    { 0x3086, 0x1627 }, //HiDy Seq Load
    { 0x3086, 0x0017 }, //HiDy Seq Load
    { 0x3086, 0x3626 }, //HiDy Seq Load
    { 0x3086, 0xA617 }, //HiDy Seq Load
    { 0x3086, 0x0326 }, //HiDy Seq Load
    { 0x3086, 0xA417 }, //HiDy Seq Load
    { 0x3086, 0x1F28 }, //HiDy Seq Load
    { 0x3086, 0x0526 }, //HiDy Seq Load
    { 0x3086, 0x2028 }, //HiDy Seq Load
    { 0x3086, 0x0425 }, //HiDy Seq Load
    { 0x3086, 0x2020 }, //HiDy Seq Load
    { 0x3086, 0x2700 }, //HiDy Seq Load
    { 0x3086, 0x171D }, //HiDy Seq Load
    { 0x3086, 0x2500 }, //HiDy Seq Load
    { 0x3086, 0x2021 }, //HiDy Seq Load
    { 0x3086, 0x1712 }, //HiDy Seq Load
    { 0x3086, 0x1B17 }, //HiDy Seq Load
    { 0x3086, 0x0327 }, //HiDy Seq Load
    { 0x3086, 0x0017 }, //HiDy Seq Load
    { 0x3086, 0x2828 }, //HiDy Seq Load
    { 0x3086, 0x0517 }, //HiDy Seq Load
    { 0x3086, 0x1A26 }, //HiDy Seq Load
    { 0x3086, 0x6017 }, //HiDy Seq Load
    { 0x3086, 0xAE25 }, //HiDy Seq Load
    { 0x3086, 0x0090 }, //HiDy Seq Load
    { 0x3086, 0x2700 }, //HiDy Seq Load
    { 0x3086, 0x2618 }, //HiDy Seq Load
    { 0x3086, 0x2800 }, //HiDy Seq Load
    { 0x3086, 0x2E2A }, //HiDy Seq Load
    { 0x3086, 0x2808 }, //HiDy Seq Load
    { 0x3086, 0x1E17 }, //HiDy Seq Load
    { 0x3086, 0x0A05 }, //HiDy Seq Load
    { 0x3086, 0x1470 }, //HiDy Seq Load
    { 0x3086, 0x7009 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1616 }, //HiDy Seq Load
    { 0x3086, 0x1400 }, //HiDy Seq Load
    { 0x3086, 0x2024 }, //HiDy Seq Load
    { 0x3086, 0x1400 }, //HiDy Seq Load
    { 0x3086, 0x502B }, //HiDy Seq Load
    { 0x3086, 0x302C }, //HiDy Seq Load
    { 0x3086, 0x2C2C }, //HiDy Seq Load
    { 0x3086, 0x2C00 }, //HiDy Seq Load
    { 0x3086, 0x0225 }, // start part of sequnencer that  enables use of linear mode
    { 0x3086, 0x5050 }, // Linear Seq Load
    { 0x3086, 0x2D26 }, // Linear Seq Load
    { 0x3086, 0x0828 }, // Linear Seq Load
    { 0x3086, 0x0D17 }, // Linear Seq Load
    { 0x3086, 0x0926 }, // Linear Seq Load
    { 0x3086, 0x0028 }, // Linear Seq Load
    { 0x3086, 0x0526 }, // Linear Seq Load
    { 0x3086, 0xA728 }, // Linear Seq Load
    { 0x3086, 0x0725 }, // Linear Seq Load
    { 0x3086, 0x8080 }, // Linear Seq Load
    { 0x3086, 0x2917 }, // Linear Seq Load
    { 0x3086, 0x0525 }, // Linear Seq Load
    { 0x3086, 0x0040 }, // Linear Seq Load
    { 0x3086, 0x2700 }, // Linear Seq Load
    { 0x3086, 0x1616 }, // Linear Seq Load
    { 0x3086, 0x2700 }, // Linear Seq Load
    { 0x3086, 0x1736 }, // Linear Seq Load
    { 0x3086, 0x26A6 }, // Linear Seq Load
    { 0x3086, 0x1703 }, // Linear Seq Load
    { 0x3086, 0x26A4 }, // Linear Seq Load
    { 0x3086, 0x171F }, // Linear Seq Load
    { 0x3086, 0x2805 }, // Linear Seq Load
    { 0x3086, 0x2620 }, // Linear Seq Load
    { 0x3086, 0x2804 }, // Linear Seq Load
    { 0x3086, 0x2520 }, // Linear Seq Load
    { 0x3086, 0x2027 }, // Linear Seq Load
    { 0x3086, 0x0017 }, // Linear Seq Load
    { 0x3086, 0x1E25 }, // Linear Seq Load
    { 0x3086, 0x0020 }, // Linear Seq Load
    { 0x3086, 0x2117 }, // Linear Seq Load
    { 0x3086, 0x121B }, // Linear Seq Load
    { 0x3086, 0x1703 }, // Linear Seq Load
    { 0x3086, 0x2700 }, // Linear Seq Load
    { 0x3086, 0x1728 }, // Linear Seq Load
    { 0x3086, 0x2805 }, // Linear Seq Load
    { 0x3086, 0x171A }, // Linear Seq Load
    { 0x3086, 0x2660 }, // Linear Seq Load
    { 0x3086, 0x17AE }, // Linear Seq Load
    { 0x3086, 0x2500 }, // Linear Seq Load
    { 0x3086, 0x9027 }, // Linear Seq Load
    { 0x3086, 0x0026 }, // Linear Seq Load
    { 0x3086, 0x1828 }, // Linear Seq Load
    { 0x3086, 0x002E }, // Linear Seq Load
    { 0x3086, 0x2A28 }, // Linear Seq Load
    { 0x3086, 0x081E }, // Linear Seq Load
    { 0x3086, 0x0831 }, // Linear Seq Load
    { 0x3086, 0x1440 }, // Linear Seq Load
    { 0x3086, 0x4014 }, // Linear Seq Load
    { 0x3086, 0x2020 }, // Linear Seq Load
    { 0x3086, 0x1410 }, // Linear Seq Load
    { 0x3086, 0x1034 }, // Linear Seq Load
    { 0x3086, 0x1400 }, // Linear Seq Load
    { 0x3086, 0x1014 }, // Linear Seq Load
    { 0x3086, 0x0020 }, // Linear Seq Load
    { 0x3086, 0x1400 }, // Linear Seq Load
    { 0x3086, 0x4013 }, // Linear Seq Load
    { 0x3086, 0x1802 }, // Linear Seq Load
    { 0x3086, 0x1470 }, // Linear Seq Load
    { 0x3086, 0x7004 }, // Linear Seq Load
    { 0x3086, 0x1470 }, // Linear Seq Load
    { 0x3086, 0x7003 }, // Linear Seq Load
    { 0x3086, 0x1470 }, // Linear Seq Load
    { 0x3086, 0x7017 }, // Linear Seq Load
    { 0x3086, 0x2002 }, // Linear Seq Load
    { 0x3086, 0x1400 }, // Linear Seq Load
    { 0x3086, 0x2002 }, // Linear Seq Load
    { 0x3086, 0x1400 }, // Linear Seq Load
    { 0x3086, 0x5004 }, // Linear Seq Load
    { 0x3086, 0x1400 }, // Linear Seq Load
    { 0x3086, 0x2004 }, // Linear Seq Load
    { 0x3086, 0x1400 }, // Linear Seq Load
    { 0x3086, 0x5022 }, // Linear Seq Load
    { 0x3086, 0x0314 }, // Linear Seq Load
    { 0x3086, 0x0020 }, // Linear Seq Load
    { 0x3086, 0x0314 }, // Linear Seq Load
    { 0x3086, 0x0050 }, // Linear Seq Load
    { 0x3086, 0x2C2C }, // Linear Seq Load
    { 0x3086, 0x2C2C }, // Linear Seq Load
    { 0x309E, 0x018A }, //set start address for linear seq
    { 0x30E4, 0x6372 }, // ADC_BITS_6_7 derived from OPTIMIZED SETTINGS
    { 0x30E2, 0x7253 }, // ADC_BITS_4_5 derived from OPTIMIZED SETTINGS
    { 0x30E0, 0x5470 }, // ADC_BITS_2_3 derived from OPTIMIZED SETTINGS
    { 0x30E6, 0xC4CC }, // ADC_CONFIG1 derived from OPTIMIZED SETTINGS
    { 0x30E8, 0x8050 }, // ADC_CONFIG2 derived from OPTIMIZED SETTINGS
    { 0x3EDE, 0xC005 }, // Tuning to avoid single oversat pixel, when CG = high
    { 0x302C, 0x0002 }, // VT_SYS_CLK_DIV settings for 7.5MHz ext Inputclock, 45MHz Pix-clock
    { 0x302A, 0x0006 }, // VT_PIX_CLK_DIV settings for 7.5MHz ext Inputclock, 45MHz Pix-clock, Must be 6, when HiSpi is used !
    { 0x302E, 0x0001 }, // PRE_PLL_CLK_DIV settings for 7.5MHz ext Inputclock, 45MHz Pix-clock
    { 0x3030, 0x0048 }, // PLL_MULTIPLIER settings for 7.5MHz ext Inputclock, 45MHz Pix-clock
    { 0x3040, 0x0000 }, // Mirror and Flip NOT needed with B1-Sample Modules and later samples
    { 0x3082, 0x0028 }, // OPERATION_MODE_CTRL, set ratios 0x0028 = R12=R23=16, set to 0x0024 for R12=8 R23=16, Bit0=1 = linear mode(possible to load Seq Load for Lin and HiDy, Mass Production: Both Sequencer fixed in Imager's ROM
    { 0x30B0, 0x1300 }, // DIGITAL_TEST --> use PLL, disable ags, anal gain=1x, gain=Bit[5:4]
    { 0x3100, 0x0000 }, // OPERATION_MODE_CTRL to make sure, DCG is set to low
    { 0x30D4, 0xE007 }, // COLUMN_CORRECTION Double number of rows to be sampled for more accurate sampling of CC
    { 0x30D6, 0x8000 }, //colcorr threshold
    { 0x30D8, 0x0800 }, //colcorr clip
    { 0x3028, 0x0010 }, // Row Speed / Edge --> play with this value, when communication issues appear!
#ifdef ICCFG_SENSOR_ARX550
    { 0x3044, 0x1000 }, // enable "Show dark rows"  , ARX550 does not have RNC (row noise correction)
#else
    { 0x3044, 0x1400 }, // enable "Show dark rows"  , enable RNC
#endif
    { 0x301E, 0x00A8 }, // set Data Pedestal to 168dec
    { 0x30BA, 0x0001 }, // DIGITAL_CTRL derived from OPTIMIZED SETTINGS !!!changed: retrigger ColCorr when enbale/disable DCG
    { 0x3EDA, 0x0F03 }, // DAC_LD_14_15 derived from OPTIMIZED SETTINGS
    { 0x3EE6, 0x4303 }, //Aptina: This will help with column noise at low light by minimizing variation to the ADC block.
    { 0x3ED8, 0x01EF }, // DAC_LD_12_13 derived from OPTIMIZED SETTINGS !!!up to here: IMPORTANT TO KEEP THE ORDER TO ENSURE BEST PICTURE QUALITY!!!
    { 0x3012, 0x01FF }, // COARSE_INTEGRATION_TIME          !!!from here: only SETTINGS in DIGITAL BLOCK. DIGITAL BLOCKS may be changed to any value at any time!
    { 0x30BA, 0x0000 }, // DIGITAL_CTRL Now disable column correction retriggering at DCG-Switch after a delay of 550 ms
    { 0x3032, 0x0000 }, // DIGITAL_BINNING//

    // NOTE: This is only the initial CROI position and size! The CROI is modified later in "ic_roi.c"
    //       and set by "ic_controller.c" each cycle. It's shifted in dependence of PPAR and SCN pitch
    //       and we have different frame-sizes for even- and odd-numbered frames. Those sizes are set in "ic_cfg.h"
#ifdef ICCFG_SENSOR_ARX550
    { 0x3002, 0x0004 }, // Y_ADDR_START = 4
    { 0x3004, 0x0004 }, // X_ADDR_START = 4
    { 0x3006, 0x0279 }, // Y_ADDR_END = 633
    { 0x3008, 0x034B }, // X_ADDR_END = 843
#else
    { 0x3002, 0x00D0 }, // Y_ADDR_START
    { 0x3004, 0x0038 }, // X_ADDR_START
    { 0x3006, 0x034F }, // Y_ADDR_END
    { 0x3008, 0x04CF }, // X_ADDR_END
#endif

    { 0x300A, 0x0336 }, // FRAME_LENGTH_LINES=822 lines, 30.14ms frame time nur Startwert, da Jitter!!!!  Sicherstellen: Framelength Lines_odd + Framelength Lines_even = 1644!!!
    { 0x30B0, 0x1382 }, // DIGITAL_TEST use PLL(Bit12),set monochrome(Bit7), AGS dis(Bit6 und 2), Column gain=1x(Bit5:4), no_sh_jump_limit enabled (Bit1)
    { 0x3064, 0x1982 }, // EMBEDDED_DATA_CTRL emb data and stats enabled
    { 0x301A, 0x10DC }, // !!!!CHECK!!!! RESET_REGISTER
    { 0x318A, 0x0FA0 }, // HDR Control1
    { 0x318C, 0x0040 }, // HDR Control2
    { 0x318E, 0x0110 }, // HDR Control3
    { 0x3190, 0x6BA0 }, // HDR Control4, DLO-HiDy enable, noise filter en, linear filter enabled
    { 0x3192, 0x0400 }, // HDR Control5
    { 0x3194, 0x0BB8 }, // HDR Control6 T1 barrier def=0xBB8=3000dez
    { 0x3196, 0x0DAC }, // HDR Control7 T2 Barrier def=0xDAC=3500dez
    { 0x3198, 0x0FA0 }, // HDR Control8 T3 Barrier def=0xFA0=4000dez
    { 0x319E, 0x5040 }, // HDR Control9 Bit 11:0 = S2_dlo_threshold
    { 0x31A0, 0x0040 }, // HDR Control10
    { 0x31A2, 0x0BB8 }, // HDR Control11 upper level for noise correction. If T1 or T2 is greater than R0x31A2, noise corr is not performed.
    { 0x30F0, 0x0080 }, // number of ignored frames at start
    { 0x3046, 0x0100 }, //Flash enable When T1 or T2 or T3 is integrating, then flash pin is set
    { 0x3056, 0x0020 }, //green1 gain_Digital gain,  8Bit, read as xxx.yyyyy example 0x0020 = 0b0010000 = 1x
    { 0x3058, 0x0020 }, //blue gain_Digital gain,  8Bit, read as xxx.yyyyy example 0x0020 = 0b0010000 = 1x
    { 0x305A, 0x0020 }, //red gain_Digital gain,  8Bit, read as xxx.yyyyy example 0x0020 = 0b0010000 = 1x
    { 0x305C, 0x0020 }, //green2 gain_Digital gain,  8Bit, read as xxx.yyyyy example 0x0020 = 0b0010000 = 1x
    { 0x305E, 0x0020 }, //global gain_Digital gain,  8Bit, read as xxx.yyyyy, set to 0x0020 = 1x when R1=T1/T2=16, set to 0x0008 = 0.25x when R1=T1/T2=4n (Image Control)
    { 0x3180, 0xC000 }, //delta_dk_ctrl
    { 0x3182, 0x7FFF }, //delta_dk_clip  Read out delta dark in R0x3184, -6, -8
    { 0x3070, 0x0000 }, //For Testpattern: set to 0x0003. Output is different with Rev3 (M024)
    { 0x307A, 0x0000 }, //set to 0x0001 to disable all corrections during testmode
    { 0x307E, 0x012C }, //minimum T3 in clocks
    { 0x30B4, 0x0011 }, //enable internal Temp-sensor(Bit0) and retrigger with each frame(Bit1) --> Read out in R0x30B2
    { 0x3140, 0x00EA }, //IC ROI is referenced to output window. Start -X = 234
    { 0x3142, 0x0118 }, //IC ROI is referenced to output window. Start -Y = 280
    { 0x3144, 0x02C2 }, //IC ROI, Width in X: 706 Spalten
    { 0x3146, 0x0110 }, //IC ROI, Height in Y: 272 Zeilen
    { 0x314c, 0x0080 }, // hist div
    { 0x3148, 0x3333 }, //ae_hist_begin_perc
    { 0x314a, 0xD1EA }, //ae_hist_end_perc
// Slew-rates are set in ic_controller.c!    { 0x306E, 0xFC10 }, //RIGHT IMAGER
// Slew-rates are set in ic_controller.c!    { 0x306E, 0x9010 }, //LEFT IMAGER
    { 0x301A, 0x10DE }  // Reset and Stream
// NOTE: Remaining part of init-sequence is handled by ic_controller.c
};

/*## attribute ICINIT_caui16_SensorExitATestInitData */
const IC_S_RegDataPair ICINIT_caui16_SensorExitATestInitData[] = {
    { 0x3044, 0x1400 }, // Enable ARNC (Analog Row Noise correction)
    { 0x30B0, 0x1382 }, // Ensure Imager is set to 1x gain, AGS disabled
    { 0x30EA, 0x0C00 }, // Use calculated Offset
    { 0x3180, 0xC000 }, // Enable delta dark correction (Black level correction)
    { 0x3EE0, 0x047D }, //
    { 0x3EE2, 0xA46B }, //
    { 0x3EE4, 0xD208 }, //
    { 0x3EE6, 0x4303 }  //
};

/*## attribute ICINIT_caui16_SensorEnterATestInitData */
const IC_S_RegDataPair ICINIT_caui16_SensorEnterATestInitData[] = {
    { 0x3044, 0x1000 }, // Disable ARNC (Analog Row Noise correction)
    { 0x30B0, 0x1382 }, // Ensure AGS is disabled (Auto-Gain-Select; disabled also in Conti-Mode)
    { 0x30EA, 0x8C00 }, // Use Register Offset, not calculated Offset
    { 0x3180, 0x0000 }, // Disable delta dark correction (Black level correction)
    { 0x3EE0, 0x047C }, // Disable anti-eclipse for reset sampling
    { 0x3EE2, 0xA47F }, // Set voltage step levels for Analog Test
    { 0x3EE4, 0xC208 }, // Disable row noise correction
    { 0x3EE6, 0x4313 }  // Needs periodic Check during normal operation mode! This generally enables Analog Test. Must not happen unintendent during operation!!!
};

/*## attribute ICINIT_caui16_SensorInitDataEntries */
const uint16 ICINIT_caui16_SensorInitDataEntries = (uint16)(sizeof(ICINIT_caui16_SensorInitData) / sizeof(ICINIT_caui16_SensorInitData[0]));

/*## attribute ICINIT_caui16_SensorEnterATestInitDataEntries */
const uint16 ICINIT_caui16_SensorEnterATestInitDataEntries = (uint16)(sizeof(ICINIT_caui16_SensorEnterATestInitData) / sizeof(ICINIT_caui16_SensorEnterATestInitData[0]));

/*## attribute ICINIT_caui16_SensorExitATestInitDataEntries */
const uint16 ICINIT_caui16_SensorExitATestInitDataEntries = (uint16)(sizeof(ICINIT_caui16_SensorExitATestInitData) / sizeof(ICINIT_caui16_SensorExitATestInitData[0]));


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_initdata.c
*********************************************************************/
