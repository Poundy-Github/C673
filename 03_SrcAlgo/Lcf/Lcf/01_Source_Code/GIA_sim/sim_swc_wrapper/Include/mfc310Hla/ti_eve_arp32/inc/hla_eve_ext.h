/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_ext.h

  DESCRIPTION:            Interface of HLA EVE functions between DSP and EVE

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-06-28

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_ext.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:46CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:35CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:02CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.13 2014/03/12 18:07:35CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:35 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.12 2014/03/03 16:51:42CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for R2.1 interface
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:43 PM CET]
  CHANGES:                Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.11 2014/02/06 16:02:44CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:45 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.10 2014/01/10 18:33:15CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:15 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.9 2013/12/10 14:49:27CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Cosmetic changes
  CHANGES:                --- Added comments ---  uidv7867 [Dec 10, 2013 2:49:27 PM CET]
  CHANGES:                Change Package : 207432:7 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.8 2013/12/09 10:47:25CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added newly needed rte header file
  CHANGES:                --- Added comments ---  uidv7867 [Dec 9, 2013 10:47:26 AM CET]
  CHANGES:                Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.7 2013/12/05 17:48:05CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Update to RTE I330
  CHANGES:                --- Added comments ---  uidv7867 [Dec 5, 2013 5:48:05 PM CET]
  CHANGES:                Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.6 2013/10/29 18:22:00CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:22:00 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.5 2013/10/24 11:16:47CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Adapted HIL to latest changes
  CHANGES:                Fixed segline buffer visu
  CHANGES:                --- Added comments ---  uidv7867 [Oct 24, 2013 11:16:47 AM CEST]
  CHANGES:                Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.4 2013/10/16 14:59:21CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated eve code for support for lrf
  CHANGES:                --- Added comments ---  uidv7867 [Oct 16, 2013 2:59:21 PM CEST]
  CHANGES:                Change Package : 198642:2 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.3 2013/08/21 18:21:30CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved sorting on EVE quite a lot
  CHANGES:                --- Added comments ---  uidv7867 [Aug 21, 2013 6:21:30 PM CEST]
  CHANGES:                Change Package : 192116:3 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.2 2013/08/05 20:41:26CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:26 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.1 2013/07/26 17:12:45CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/inc/project.pj
  CHANGES:
**************************************************************************** */

#ifndef HLA_EVE_EXT_H
#define HLA_EVE_EXT_H

#include "algo_service_types.h"
#include "Rte_Ext_Type.h"
#include "hla_defs.h"

/*---------------------------------------------------*/
/*  MACROS                                           */
/*---------------------------------------------------*/
/* Return values */
/* limited to 8 bits as we also want to transport segmentation/lrf error returns */
#define HLA_EVE_RETURN_OK                       0x00
#define HLA_EVE_RETURN_ERR_NULL_POINTER         0x01
#define HLA_EVE_RETURN_ERR_VERSION_MISMATCH     0x02
#define HLA_EVE_RETURN_ERR_ILLEGAL_FUNC_ID      0x03
#define HLA_EVE_RETURN_ERR_TIME_MEAS            0x04
#define HLA_EVE_RETURN_ERR_SEGMENTATION         0x05
#define HLA_EVE_RETURN_ERR_LRF                  0x06

/* EVE interface version number */
#define HLA_EVE_INTERFACE_VERSION_NUMBER_MAIN    2
#define HLA_EVE_INTERFACE_VERSION_NUMBER_SUB     0
#define HLA_EVE_INTERFACE_VERSION_NUMBER_BUGFIX  0

#define HLA_EVE_INTERFACE_VERSION_NUMBER ((HLA_EVE_INTERFACE_VERSION_NUMBER_MAIN<<16) | (HLA_EVE_INTERFACE_VERSION_NUMBER_SUB<<8) | (HLA_EVE_INTERFACE_VERSION_NUMBER_BUGFIX))

/* EVE local function IDs */
#define HLA_EVE_FUNC_ID_SEGMENTATION 0x00
#define HLA_EVE_FUNC_ID_LRF          0x01

#define HLA_EVE_SEG_PROCESSED_ROI_HEIGHT_ALIGNMENT   2u               /* alignment of image width in y direction: 2 due to binning */
#define HLA_EVE_SEG_PROCESSED_ROI_WIDTH_ALIGNMENT    16u              /* alignment of image width in x direction: same as HLA_EVE_SEG_PROCESSED_BLOCK_WIDTH: 16 due to binning * VCOP_SIMD_WIDTH */
#define HLA_EVE_SEG_PROCESSED_MAX_ROI_HEIGHT         512u             /* max image (ROI) height being supported is 512 pixels, i.e. IBUFL input buffer for raw data is 512 * 2Bytes * 16 Pixels = 16K */
#define HLA_EVE_SEG_PROCESSED_MAX_ROI_WIDTH          960u             /* max image (ROI) width being supported is pixels (modulo 16)*/
#define HLA_EVE_SEG_LED_META_THRESHOLD               0x8000           /* meta threshold for LEDs. We need that for in threshold tab while high/low thresholds are sent via parameters */

#define HLA_EVE_LRF_NUM_RFS_PARALLEL                8                 /* number of RFs that can be calculated in parallel */
#define HLA_EVE_LRF_TANH_LUT_INTERLEAVED_SIZE       640u              /* size of interleaved tanh look-up table, more details: compiler check hla_eve_lrf_main.c */
#define HLA_EVE_LRF_NUM_EVE_OUTPUTS                 16u               /* number of hidden neurons coming out of eve, more details: compiler check hla_eve_lrf_main.c */

/*---------------------------------------------------*/
/*  TYPEDEFS                                         */
/*---------------------------------------------------*/
/*
 * Parameter interfaces
 */
/* Parameter struct for calling segmentation */
typedef struct
{
  uint16 processingWidth;                            /* number of columns to be processed, needs to be modulo 16 since we transfer 16 rows at once by edma*/
  uint16 processingHeight;                           /* number of rows to be processed */
  uint16 rowOffset;                                  /* number of pixels to move forward in order to get to next row in memory, i.e. cRoi width */
  uint16 thresholdTab[RTE_HLA_SEG_MAX_NUM_LEVELS];  /* this array contains thresholds for each level */
  uint16 thresholdLedUpper;                          /* threshold for upper limit of LED band */
  uint16 thresholdLedLower;                          /* threshold for lower limit of LED band */
  uint16 xOffsetRoi;                                 /* number of pixels in x direction to transform roi coordinates (as we use them inside eve) to absolute imager coordinates */
  uint16 yOffsetRoi;                                 /* number of pixels in y direction to transform roi coordinates (as we use them inside eve) to absolute imager coordinates */
  uint16 maxSeglines;                                /* maximum number of seglines to be stored in this region */
} HLAEveSegParams_t;


/* Parameter struct for calling Lrf classifier */
typedef struct
{
  uint8   lrfType;     /* icon/lrf type: xenon/led, halogen, red light, city light */
  uint8   numRFs;      /* number of receptive fiels (RFs), different for different lrf types */
} HLAEveLrfParams_t;


/* Time measurements */
typedef struct
{
  uint16 dTimeEve_us;
  uint16 dTimeEveSeg_us;
  uint16 dTimeEveSegInit_us;
  uint16 dTimeEveSegMain_us;
  uint16 dTimeEveSegMainEdma_us;
  uint16 dTimeEveSegMainVcop_us;
  uint16 dTimeEveSegMainInterpretSaveVcopOut_us;
  uint16 dTimeEveSegMainInterpretStoreSeglines_us;
  uint16 dTimeEveSegExit_us;
  uint16 dTimeEveLrf_us;
  uint16 dTimeEveLrfInit_us;
  uint16 dTimeEveLrfMain_us;
  uint16 dTimeEveLrfMainEdma_us;
  uint16 dTimeEveLrfMainVcop_us;
  uint16 dTimeEveLrfExit_us;

  /* padding bytes to be aligned to HLA_DSP_CACHE_LINE_SIZE */
  uint8 dummy[98u];
} HLAEveTimeMeas_t;


/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DECLARATIONS                     */
/*---------------------------------------------------*/
/* Eve entry point which sorts out which local function to call, etc. */
sint32 HLA_Eve_Exec(const AS_t_EVEContainer *pEveContainer);

#endif /* #HLA_EVE_EXT_H */
