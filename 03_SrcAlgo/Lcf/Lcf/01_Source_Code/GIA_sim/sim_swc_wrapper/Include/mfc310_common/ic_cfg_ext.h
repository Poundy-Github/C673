/*
 * ic_cfg_ext.h
 *
 *  Created on: 08.10.2012
 *      Author: uidt3974
 */
#ifndef IC_CFG_EXT_H_
#define IC_CFG_EXT_H_

// Position and size of the imager output frame (CROI)
#if (CFG_MFC_MONO_ENTRY == 1)
    // Dimensions: ARX550
    #define ICCFG_cui16_CROI_EVEN_HEIGHT     482u
    #define ICCFG_cui16_CROI_EVEN_WIDTH      840u
    #define ICCFG_cui16_CROI_ODD_HEIGHT      630u
    #define ICCFG_cui16_CROI_ODD_WIDTH       840u

    // Nominal position of CROI (in case SCN and intrinsic pitches are zero)
    #define ICCFG_cui16_CROI_EVEN_BASE_X       4u
    #define ICCFG_cui16_CROI_EVEN_BASE_Y       4u
    #define ICCFG_cui16_CROI_ODD_BASE_X        4u
    #define ICCFG_cui16_CROI_ODD_BASE_Y        4u

    // No CROI-Shift here, as we read the full imager height, so futher shifting is not possible
    #define IC_CROISHIFT_ENABLED                0
#else
    // Dimensions: MT9M025
    #define ICCFG_cui16_CROI_EVEN_HEIGHT     482u
    #define ICCFG_cui16_CROI_EVEN_WIDTH     1176u
    #define ICCFG_cui16_CROI_ODD_HEIGHT      640u
    #define ICCFG_cui16_CROI_ODD_WIDTH      1176u

    // Nominal position of CROI (in case SCN and intrinsic pitches are zero)
    #define ICCFG_cui16_CROI_EVEN_BASE_X      56u
    #define ICCFG_cui16_CROI_EVEN_BASE_Y     232u
    #define ICCFG_cui16_CROI_ODD_BASE_X       56u
    #define ICCFG_cui16_CROI_ODD_BASE_Y      232u

    // Enable vertical CROI shifting based on intrinsic pitch and SCN coding
    #define IC_CROISHIFT_ENABLED                1
#endif

// Enable frame jittering
#define IC_JITTERING_ENABLED                1

// Position and size of the IC-ROIs
#define ICCFG_cui16_IC_ROI_WIDTH_EVEN    680
#define ICCFG_cui16_IC_ROI_WIDTH_ODD     680
#define ICCFG_cui16_IC_ROI_HEIGHT_EVEN   190
#define ICCFG_cui16_IC_ROI_HEIGHT_ODD    242

// Use static positioning for even frame IC-ROI?
#define IC_ICROI_EVEN_USESTATICPOSITION    0  // Do not use fixed IC-ROI position, use dynamic (online-calib)
#define ICCFG_cui16_IC_ROI_STATIC_X_EVEN   0
#define ICCFG_cui16_IC_ROI_STATIC_Y_EVEN   0

// Nominal total height/length of the frames including vertical blanking, but without
// taking jittering into account [lines]
#define ICCFG_cui16_FrameHeightTotalOdd  ((uint16)822)
#define ICCFG_cui16_FrameHeightTotalEven ((uint16)822)

#endif /* IC_CFG_EXT_H_ */
