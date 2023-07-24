/***********************************************************************

// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.69 $

/// This file contains the SPM version
///
/// @file       spm_ver.h
///
/// @page       SPM_SensorPerformanceMonitoring

---*/ /*---
CHANGES:                   $Log: spm_ver.h  $
CHANGES:                   Revision 1.69 2021/03/04 14:11:16CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.50_INT-2
CHANGES:                   Revision 1.68 2021/02/25 10:42:22CET Pallo, Istvan (palloi) 
CHANGES:                   Update to new SPM version
CHANGES:                   Revision 1.67 2021/02/16 11:09:18CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.49_INT-1
CHANGES:                   Revision 1.66 2021/01/18 14:00:32CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.48_INT-1
CHANGES:                   Revision 1.65 2020/11/10 09:17:57CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.47_INT-1
CHANGES:                   Revision 1.64 2020/10/23 15:45:32CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.46_INT-1
CHANGES:                   Revision 1.63 2020/10/23 11:10:51CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.45_INT-1
CHANGES:                   Revision 1.62 2020/10/06 10:15:14CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.44_INT-1
CHANGES:                   Revision 1.61 2020/09/08 12:08:09CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.43_INT-1
CHANGES:                   Revision 1.60 2020/09/04 15:20:25CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.42_INT-2 for an experimental CP
CHANGES:                   Revision 1.57 2020/08/07 13:55:49CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.42_INT-1
CHANGES:                   Revision 1.56 2020/07/22 11:49:49CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Delete glob_def header
CHANGES:                   Revision 1.55 2020/06/30 16:28:37CEST Pallo, Istvan (palloi) 
CHANGES:                   Revert SRR SPM split changes on trunk
CHANGES:                   Revision 1.54 2020/06/25 08:05:23CEST Pallo, Istvan (palloi) 
CHANGES:                   Update version to new template
CHANGES:                   Revision 1.53 2020/06/10 13:20:06CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.40_INT-1
CHANGES:                   Revision 1.52 2020/05/08 15:22:48CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.33_INT-4
CHANGES:                   Revision 1.51 2020/05/05 08:50:02CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.39_INT-1
CHANGES:                   Revision 1.50 2020/03/17 09:27:54CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version
CHANGES:                   Revision 1.49 2020/02/21 14:32:04CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.37_INT-1
CHANGES:                   Revision 1.48 2020/02/13 12:54:45CET Pallo, Istvan (palloi) 
CHANGES:                   Update version for release AL_SPM_01.00.36_INT-1
CHANGES:                   Revision 1.47 2020/02/05 07:51:53CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.35_INT-1
CHANGES:                   Revision 1.46 2020/01/17 15:27:00CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.34_INT-1
CHANGES:                   Revision 1.44 2020/01/09 10:39:34CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.33_INT-3
CHANGES:                   Revision 1.43 2020/01/08 12:37:30CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.33_INT-2
CHANGES:                   Revision 1.42 2019/12/05 08:47:09CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.33_INT-1
CHANGES:                   Revision 1.41 2019/11/26 09:54:58CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.32_INT-1
CHANGES:                   Revision 1.40 2019/10/22 07:20:41CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.31_INT-1
CHANGES:                   Revision 1.39 2019/09/18 09:21:14CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.30_INT-1
CHANGES:                   Revision 1.38 2019/08/02 08:46:02CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.29_INT-1
CHANGES:                   Revision 1.37 2019/06/25 13:25:05CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.28_INT-1
CHANGES:                   Revision 1.36 2019/06/12 10:54:05CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.27_INT-2
CHANGES:                   Revision 1.35 2019/05/29 14:09:10CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.27_INT-1
CHANGES:                   Revision 1.34 2019/05/27 09:15:49CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.21_INT-2
CHANGES:                   Revision 1.33 2019/04/23 08:57:54CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.26_INT-1
CHANGES:                   Revision 1.32 2019/04/03 08:36:23CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.25_INT-1
CHANGES:                   Revision 1.31 2019/03/25 10:23:49CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update SPM version to AL_SPM_01.00.24_INT-1
CHANGES:                   Revision 1.30 2019/03/08 08:24:26CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version number to AL_SPM_01.00.23_INT-1
CHANGES:                   Revision 1.29 2019/02/26 10:40:26CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version number to AL_SPM_01.00.22_INT-1
CHANGES:                   Revision 1.28 2019/02/12 09:11:36CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version number to AL_SPM_01.00.21_INT-1
CHANGES:                   Revision 1.27 2019/02/05 10:06:41CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version number to AL_SPM_01.00.16_INT-2
CHANGES:                   Revision 1.26 2019/01/29 10:46:15CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version number to AL_SPM_01.00.20_INT-1
CHANGES:                   Revision 1.25 2018/12/10 15:23:42CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version number to AL_SPM_01.00.19_INT-2
CHANGES:                   Revision 1.24 2018/12/04 09:59:08CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version number to AL_SPM_01.00.19_INT-1
CHANGES:                   Revision 1.23 2018/11/20 09:34:27CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.18_INT-1
CHANGES:                   Revision 1.22 2018/10/23 12:00:10CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Replace SPM_CONTENT_VER_NO based on the new CP
CHANGES:                   Revision 1.21 2018/10/05 11:28:07CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.16_INT-1
CHANGES:                   Revision 1.20 2018/09/25 13:32:09CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version based on new dev path
CHANGES:                   Revision 1.19 2018/09/24 15:11:05CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for SRR
CHANGES:                   Revision 1.18 2018/09/19 09:14:22CEST Pallo, Istvan (palloi) 
CHANGES:                   Update version number to AL_SPM_01.00.12_INT-2
CHANGES:                   Revision 1.17 2018/08/31 08:28:09CEST Pallo, Istvan (palloi) 
CHANGES:                   Update version for release AL_SPM_01.00.11_INT-3
CHANGES:                   Revision 1.16 2018/08/28 09:04:08CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update version for release AL_SPM_01.00.14_INT-1
CHANGES:                   Revision 1.15 2018/08/14 13:28:41CEST Pallo, Istvan (palloi) 
CHANGES:                   Update SPM version for release AL_SPM_01.00.13_INT-2
CHANGES:                   Revision 1.14 2018/08/14 11:30:26CEST Pallo, Istvan (palloi) 
CHANGES:                   Update version for AL_SPM_01.00.11_INT-2
CHANGES:                   Revision 1.13 2018/08/07 09:49:47CEST Pallo, Istvan (palloi) 
CHANGES:                   Update SPM version to AL_SPM_01.00.13_INT-1
CHANGES:                   Revision 1.12 2018/07/03 07:01:28CEST Pallo, Istvan (palloi) 
CHANGES:                   Increment SPM version for release AL_SPM_01.00.12_INT-1
CHANGES:                   Revision 1.11 2018/06/18 09:50:13CEST Pallo, Istvan (palloi) 
CHANGES:                   Update version for release AL_SPM_01.00.11_INT-1
CHANGES:                   Revision 1.10 2018/05/22 08:02:50CEST Pallo, Istvan (palloi) 
CHANGES:                   Update version for release AL_SPM_01.00.10_INT-1
CHANGES:                   Revision 1.9 2018/05/08 08:55:25CEST Pallo, Istvan (palloi) 
CHANGES:                   Version incremented: AL_SPM_01.00.09_INT-2
CHANGES:                   Revision 1.8 2018/04/24 11:28:19CEST Pallo, Istvan (palloi) 
CHANGES:                   Version incremented: AL_SPM_01.00.09_INT-1
CHANGES:                   Revision 1.7 2018/03/28 09:35:05CEST Pallo, Istvan (palloi) 
CHANGES:                   New SPM version: AL_SPM_01.00.08_INT-1
CHANGES:                   Revision 1.6 2018/03/13 15:03:00CET Pallo, Istvan (palloi) 
CHANGES:                   New SPM version: AL_SPM_01.00.07_INT-1
CHANGES:                   Revision 1.5 2018/03/09 13:26:40CET Pallo, Istvan (palloi) 
CHANGES:                   Rename spm version defines and add defines from ver custom.
CHANGES:                   Remove sw version typedef.
CHANGES:                   Revision 1.4 2018/01/16 08:58:14CET Pallo, Istvan (palloi) 
CHANGES:                   Update file log
CHANGES:                   Revision 1.3 2017/07/04 09:22:28CEST Pallo, Istvan (palloi) 
CHANGES:                   SPM version for CW26 release
CHANGES:                   Revision 1.2 2017/06/21 09:25:12CEST Pallo, Istvan (palloi) 
CHANGES:                   Change file header.
CHANGES:                   Revision 1.1 2017/03/17 13:16:59CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/frame/project.pj

*****************************************************************************/


#ifndef SPM_VER_H_INCLUDED
#define SPM_VER_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_cfg.h"
//#include "glob_defs.h"
#include "frame_spm_ver_custom.h"
#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#include "fct_ver_custom.h"


#ifdef __cplusplus
extern "C" {
#endif



/* SPM main version number*/
#define SPM_GEN_VER_NO           0x01

/* SPM interface version number*/
#define SPM_IFC_VER_NO           0x00

/* SPM content version number*/
#define SPM_CONTENT_VER_NO       0x50

/* Bugfix lever or Intergarion leven number */
#define SPM_INT_VER_NO        0x02


#define SPM_SW_VERSION_NUMBER     (   ( ( (uint32)SPM_GEN_VER_NO       ) << 24) \
                                      | ( ( (uint32)SPM_IFC_VER_NO     ) << 16) \
                                      | ( ( (uint32)SPM_CONTENT_VER_NO ) <<  8) \
                                      | ( ( (uint32)SPM_INT_VER_NO     )   )  )

/* This part is for filling the array uiAlgoVersionNumber in SEN and VEH components */

#define STR_SW_SPM_VERSION_NUMBER_TEXT(x) #x
#define STR_SW_SPM_VERSION_INFO(m,s,f,i)  FCT_ALL_SW_PROJECT_NAME STR_SW_SPM_VERSION_NUMBER_TEXT(m) STR_SW_SPM_VERSION_NUMBER_TEXT(s) STR_SW_SPM_VERSION_NUMBER_TEXT(f) STR_SW_SPM_VERSION_NUMBER_TEXT(i) FCTALL_SW_ALGO_OFFICIAL FCTALL_SW_MODIFICATION_SUMMARY 
#define VERSION_SPM_INFO_AS_TEXT  STR_SW_SPM_VERSION_INFO(SPM_GEN_VER_NO, SPM_IFC_VER_NO, SPM_CONTENT_VER_NO, SPM_INT_VER_NO)

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! @brief to validate the CDL used for data interpretation the current
 version number is also stored as signal name in the CDL.
 Stringify of macro arguments required a two level macro */
#ifdef __PDO__
#define X_STR_FCT_SPM_VERSION_AS_TEXT(m,s,f,i) STR_FCT_SPM_VERSION_AS_TEXT(m,s,f,i)
#define STR_FCT_SPM_VERSION_AS_TEXT(m,s,f,i) ui_##m##_##s##_##f##_##i
#ifdef FCTALL_SPM_SW_INT_VER_NO
#define FCT_SPM_VERSION_AS_TEXT X_STR_FCT_SPM_VERSION_AS_TEXT(SPM_GEN_VER_NO, SPM_IFC_VER_NO, SPM_CONTENT_VER_NO, SPM_INT_VER_NO)
#else
#define FCT_SPM_VERSION_AS_TEXT X_STR_FCT_SPM_VERSION_AS_TEXT(xx,SPM_GEN_VER_NO, SPM_IFC_VER_NO,SPM_CONTENT_VER_NO)
#endif
#endif

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/

/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/
#ifdef __cplusplus
};
#endif

#endif//SPM_SRR_TECHNOLOGY

#endif /*SPM_VER_H_INCLUDED */
