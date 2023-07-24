/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_type.h

  DESCRIPTION:            Declarations for the head light assist (HLAR + HLAF).

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2009-11-23

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_type.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:34CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:46CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:09CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.207 2014/03/27 14:50:15CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for R2.2 RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 27, 2014 2:50:15 PM CET]
  CHANGES:                Change Package : 207432:48 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.206 2014/03/22 10:28:23CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added project specific defines
  CHANGES:                Replaced defines for CORE by predefined ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 22, 2014 10:28:23 AM CET]
  CHANGES:                Change Package : 207432:40 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.205 2014/03/12 18:07:17CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:17 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.204 2014/03/11 10:33:53CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced SRLCAM_4T0 by CFG_SRLCAM==1
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2014 10:33:53 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.203 2014/03/04 18:00:43CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed ppars and vehpar from RTE and internal interface
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 6:00:43 PM CET]
  CHANGES:                Change Package : 207432:38 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.202 2014/03/04 14:03:04CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for latest R2.1 RTE
  CHANGES:                Undid I390 RTE specific things
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 2:03:05 PM CET]
  CHANGES:                Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.201 2014/03/04 12:58:53CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for I390 RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 12:58:54 PM CET]
  CHANGES:                Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.200 2014/03/03 16:51:34CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for R2.1 interface
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:35 PM CET]
  CHANGES:                Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.199 2014/02/07 13:40:10CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Get version info in wrapper now from lib
  CHANGES:                --- Added comments ---  uidv7867 [Feb 7, 2014 1:40:10 PM CET]
  CHANGES:                Change Package : 207432:30 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.198 2014/02/06 16:01:28CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                Centralized Null pointer checks
  CHANGES:                Refactored dframe calculation
  CHANGES:                --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:29 PM CET]
  CHANGES:                Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                Revision 1.197 2014/01/22 14:01:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed some critical QAC warnings
  CHANGES:                --- Added comments ---  uidv7867 [Jan 22, 2014 2:01:58 PM CET]
  CHANGES:                Change Package : 193435:6 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.196 2014/01/16 11:28:39CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed NVM calibration reset mode
  CHANGES:                Added headlightstate as mandatory request port
  CHANGES:                --- Added comments ---  uidv7867 [Jan 16, 2014 11:28:40 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.195 2014/01/10 18:34:05CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:34:06 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.194 2014/01/08 17:10:20CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactored HLA_Exec() function
  CHANGES:                Replaced uint64 time stamps by uint32 ones
  CHANGES:                Smaller bug fixes
  CHANGES:                --- Added comments ---  uidv7867 [Jan 8, 2014 5:10:20 PM CET]
  CHANGES:                Change Package : 207432:27 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.193 2013/12/18 15:18:08CET Schillinger, Patrick (uidv8776) 
  CHANGES:                introduction of new HighwayOncomingTruckLight detection
  CHANGES:                --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:08 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.192 2013/12/17 17:32:43CET Glebov, Roman (uidg4759) 
  CHANGES:                QAC Changes + Documentation of Chain of Light + fix of devision by 0 + small efficiency tweaks
  CHANGES:                --- Added comments ---  uidg4759 [Dec 17, 2013 5:32:43 PM CET]
  CHANGES:                Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.191 2013/12/13 16:44:56CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Service functions are now passed in one struct
  CHANGES:                SDLfile definitions moved to separate file
  CHANGES:                --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:56 PM CET]
  CHANGES:                Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.190 2013/12/11 08:59:40CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Error checks:
  CHANGES:                - Frame count comparison between image and IC
  CHANGES:                - Lens center, focal length, etc. (merge from I320 branch)
  CHANGES:                Enabled internal measfreezes again
  CHANGES:                Reviewed by AlexF
  CHANGES:                --- Added comments ---  uidv7867 [Dec 11, 2013 8:59:40 AM CET]
  CHANGES:                Change Package : 207432:2 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.189 2013/12/05 17:47:53CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Update to RTE I330
  CHANGES:                --- Added comments ---  uidv7867 [Dec 5, 2013 5:47:54 PM CET]
  CHANGES:                Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.188 2013/12/05 15:46:15CET Brunn, Marcus (brunnm) 
  CHANGES:                merged from I320
  CHANGES:                --- Added comments ---  brunnm [Dec 5, 2013 3:46:16 PM CET]
  CHANGES:                Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGES:                Revision 1.187 2013/11/21 17:53:30CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge from NEW_SEG branch
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:31 PM CET]
  CHANGES:                Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.186.1.5 2013/11/21 13:37:29CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved Icon normalize
  CHANGES:                Bug fixes in segmentation
  CHANGES:                Removed no longer compiler switches
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:29 PM CET]
  CHANGES:                Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.186.1.4 2013/10/30 13:06:39CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed no longer needed error warnings
  CHANGES:                --- Added comments ---  uidv7867 [Oct 30, 2013 1:06:39 PM CET]
  CHANGES:                Change Package : 201787:4 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.186.1.3 2013/10/29 18:21:23CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Time meas fixes
  CHANGES:                New roi calculation (alignment to eve)
  CHANGES:                Call EVE in segmentation now
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:23 PM CET]
  CHANGES:                Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.186.1.2 2013/10/24 12:30:40CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Added NULL pointer check of image data pointer
  CHANGES:                --- Added comments ---  uidv7867 [Oct 24, 2013 12:30:40 PM CEST]
  CHANGES:                Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.186.1.1 2013/10/18 13:28:00CEST Brunn, Marcus (brunnm) 
  CHANGES:                intial version of new segmentation
  CHANGES:                --- Added comments ---  brunnm [Oct 18, 2013 1:28:00 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.186 2013/10/07 11:42:39CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed temporary test modes (now defined in RTE)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 7, 2013 11:42:39 AM CEST]
  CHANGES:                Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.185 2013/09/26 11:21:26CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced specific HLA opmodes by TestMode CPar
  CHANGES:                --- Added comments ---  uidv7867 [Sep 26, 2013 11:21:27 AM CEST]
  CHANGES:                Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.184 2013/09/18 17:41:45CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Undo changes from development path
  CHANGES:                --- Added comments ---  uidv7867 [Sep 18, 2013 5:41:45 PM CEST]
  CHANGES:                Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.182 2013/08/30 14:15:06CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fix: ROIX1 calc wrong for ECU
  CHANGES:                --- Added comments ---  uidv7867 [Aug 30, 2013 2:15:06 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.181 2013/08/30 13:29:52CEST Manz, Alexander (uidv8777) 
  CHANGES:                Update: added an error to be raised when there is a high deviation in the imager response curve between ECU and DLL.
  CHANGES:                Change was needed due to getting rid of SIM_Overlay in visualization
  CHANGES:                --- Added comments ---  uidv8777 [Aug 30, 2013 1:29:52 PM CEST]
  CHANGES:                Change Package : 189284:1 http://mks-psad:7002/im/viewissue?selection=189284
  CHANGES:                Revision 1.180 2013/08/27 17:13:31CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed icon extraction
  CHANGES:                --- Added comments ---  uidv7867 [Aug 27, 2013 5:13:32 PM CEST]
  CHANGES:                Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
  CHANGES:                Revision 1.179 2013/08/09 17:53:33CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Eve bug fixes:
  CHANGES:                - # of seglines of function roi
  CHANGES:                - eve return code
  CHANGES:                --- Added comments ---  uidv7867 [Aug 9, 2013 5:53:33 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173**************************************************************************** */

#ifndef HLA_TYPE_INCLUDED
#define HLA_TYPE_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "Rte_ext_Type.h"
#include "glob_type.h"
#include "hla_defs.h"
#include "algo_service_types.h"


/*****************************************/
/* moved from MFC3xx glob_type.h to HLA  */
/*lint -e960                            */
/*****************************************/  



/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

#define HLA_MAX_RGBL_ELEM                      (16) /*!< max. number of RGBL elements in table. */
#define HLA_ui8_MAX_RGBL_ELEM         (uint8) HLA_MAX_RGBL_ELEM

#define HLA_FINGERPRINT_PIXELS                 (8)  /*!< number of pixels taken from raw image to identify that one */
 
/*****************************************************************************
  MACROS 
*****************************************************************************/
#ifdef ARRAY_BOUNDARY_CHECK
#include <boost/array.hpp>
#define ARRAY(dataType, numElements, variableName) boost::array<dataType, numElements> variableName
#define ARRAY2D(dataType, numElements1, numElements2, variableName) boost::array<boost::array<dataType, numElements2>, numElements1> variableName
#else
#define ARRAY(dataType, numElements, variableName) dataType variableName[numElements]
#define ARRAY2D(dataType, numElements1, numElements2, variableName) dataType variableName[numElements1][numElements2]
#endif

#ifndef __PDO__
#if((defined(__GOLDDUST__)) && (__GOLDDUST__ == 1))
#define HLA_BIG_ENDIAN
#define HLA_INTERFACE_VERSION_NUMBER_ENDIAN  0
#else /* WIN32, PC_SIM, _TMS320C6X */
#define HLA_LITTLE_ENDIAN
#define HLA_INTERFACE_VERSION_NUMBER_ENDIAN  1
#endif
#endif



/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/* -------------------- */
/* error output section */
/* -------------------- */

/*******************************************************************************/
/* Type definition of optional 32-bit error data (specifies error subcategory) */
/*******************************************************************************/
#define  HLA_ERRORID_OPTDATA_VEHICLE_LIGHT_MODULE_STATE_FAULT               7
#define  HLA_ERRORID_OPTDATA_VEHICLE_SCN_HEADLIGHTMODE_MISMATCH             8

#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_RESPCURVE_GREYVALUE              1
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_RESPCURVE_KNEELUX                2
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_RESPCURVE_SATLUX                 3
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_IC_HIGH_DEVIATION                   4
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_BITSPERPIXEL                        30
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_CYCLETIME                           31
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_CROPPEDROIBAYERPATTERN              32
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_FOCAL_LENGTH                        33
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_IMAGE_SIZE                          34
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_CROPPEDROISIZE                      35
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_CROPPEDROIX1                        36
#define  HLA_ERRORID_OPTDATA_IMAGE_DATA_LENSCENTER                          37

#define  HLA_ERRORID_OPTDATA_CALIBRATION_ROI_ALIGNMENT                      1
#define  HLA_ERRORID_OPTDATA_CALIBRATION_ROI_LIMITED                        2
#define  HLA_ERRORID_OPTDATA_CALIBRATION_CAM_ROT_OUT_OF_RANGE               3
#define  HLA_ERRORID_OPTDATA_CALIBRATION_ONLINE_CALI_OUT_OF_RANGE           4
#define  HLA_ERRORID_OPTDATA_CALIBRATION_ROI_LIMITED_X                      5
#define  HLA_ERRORID_OPTDATA_CALIBRATION_ROI_LIMITED_Y                      6
#define  HLA_ERRORID_OPTDATA_CALIBRATION_DIFF_TO_LANE_CALI                  7

#define  HLA_ERRORID_OPTDATA_INPUT_TIMESTAMP_HLA                            1
#define  HLA_ERRORID_OPTDATA_INPUT_TIMESTAMP_VDY                            2
#define  HLA_ERRORID_OPTDATA_INPUT_TIMESTAMP_IMAGE                          3
#define  HLA_ERRORID_OPTDATA_INPUT_MISMATCH_IMAGE_IC                        10
#define  HLA_ERRORID_OPTDATA_INPUT_DFRAME                                   11
#define  HLA_ERRORID_OPTDATA_INPUT_SPEED                                    30
#define  HLA_ERRORID_OPTDATA_INPUT_SPEED_DISPLAY                            31
#define  HLA_ERRORID_OPTDATA_INPUT_ACCELERATION                             32
#define  HLA_ERRORID_OPTDATA_INPUT_YAWRATERAW                               33
#define  HLA_ERRORID_OPTDATA_INPUT_YAWRATE                                  34
#define  HLA_ERRORID_OPTDATA_INPUT_AVAILABILITY_FAULT                       40
#define  HLA_ERRORID_OPTDATA_INPUT_NULL_POINTER                             50
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_HLAPAR                         60
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_HLARPAR                        61
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_HLAFPAR                        62
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_BSW_CTRL_DATA                  63
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_INPUT_IMG_ODD                  64
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_NVM_LEARN_VALUE                65
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_BLOCKAGE                       70
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_HLA_SIG                        71
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_HEADLIGHT_STATE                72
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_IMG_CHAR_ODD                   73
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_IMG_STAT_RES_ODD               74
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_MONO_CAL_LANE_IMG              75
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_VDY_DATA                       76
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_VDY_OFFSETS                    77
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_VEH_SIG                        78
#define  HLA_ERRORID_OPTDATA_INPUT_SIGSTATUS_OPMODE                         79

#define  HLA_ERRORID_OPTDATA_FATAL_HOTPIXELS_EXCEEDED                       1

/*!
 * definition of external error check status type
 * check failed means that the check was performed and an error detected
 */
typedef uint8 HLA_t_eErrorStatus;
#define HLA_ERRORSTATUS_CHECK_NOT_DONE            0  /*!< status of error unknown, i.e. error was not (completely) checked */
#define HLA_ERRORSTATUS_CHECK_DONE_AND_PASSED     1  /*!< error did not occur */
#define HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED     2  /*!< error did occur */
#define HLA_ERRORSTATUS_SIM_CHECK_DONE_AND_FAILED 3  /*!< error occured in simulation */
#define HLA_ERRORSTATUS_CHECK_INVALID             255


/*!
 * definition of external error ids (basic categories; algo can define additional ones)
 * parameter: erroneous input parameter (static  "configuration" data)
 * blockage : function not available due to blockage
 * vehicle data : erroneous vehicle data input (speed, yaw rate, ...)
 * image data : erroneous image data (wrong size, timestamp delta too large/small, non-incrementing frame counter ...)
 * calibration: calibration data error (special case of input error since often encountered)
 * input: erroneous dynamic input data (other sources)
 * software: internal software error (index, pointer, function parameter etc.)
 * fatal: serious, non-recoverable error
 * NOTE: Assumption is that first error has value 0
 */
#define HLA_ERRORID_UNUSED_PARAMETER                  0  /*!< = 0, error group: parameter --> error occurred during init */
#define HLA_ERRORID_BLOCKAGE                          1  /*!< = 1, error group: blockage (generates a DTC) */
#define HLA_ERRORID_VEHICLE_DATA                      2  /*!< = 2, error group: error in vehicle input data (generates a DTC) */
#define HLA_ERRORID_IMAGE_DATA                        3  /*!< = 3, error group: error in image input data */
#define HLA_ERRORID_CALIBRATION                       4  /*!< = 4, error group: error in calibration input */
#define HLA_ERRORID_INPUT                             5  /*!< = 5, error group: (other) input error */
#define HLA_ERRORID_SOFTWARE                          6  /*!< = 6, error group: software */
#define HLA_ERRORID_FATAL                             7  /*!< = 7, error group: fatal, e.g. HW-error (generates a DTC) */
#define HLA_ERRORID_SEGMENTATION                      8  /*!< = 8, error group: error codes from segmentation (eve, for instance) */
#define HLA_ERRORID_ANALYSIS                          9  /*!< = 9, error group: error codes from analysis (eve, for instance) */
#define HLA_ERRORID_NUM_LIST_ENTRIES                  10  /*!< = 10, pseudo entry for number of errors */

/*!
 * definition of algo state type
 */
typedef uint8 HLA_t_eSystemState;
#define HLA_SYSTEMSTATE_NOT_INITIALIZED       0  /*!< algo has not been initialized yet, state before init() function */
#define HLA_SYSTEMSTATE_RUNNING               1  /*!< algo has been initialized and is running fine */
#define HLA_SYSTEMSTATE_TEMP_NOT_AVAILABLE    2  /*!< algo has been initialized but is temporarily not available */
#define HLA_SYSTEMSTATE_FAILURE               3  /*!< algo is in failure mode, needs to be reinitialized by frame SW */
#define HLA_SYSTEMSTATE_INVALID               255

/*!
 * definition of external error list entry type
 */
typedef struct
{
  HLA_t_eErrorStatus      status;       /*!< status of error */
  uint32                  optData;      /*!< optional data */
} HLA_t_Error;

/*!
 * definition of external error list
 */
typedef struct
{
  ARRAY(HLA_t_Error, HLA_ERRORID_NUM_LIST_ENTRIES, error);  /*!< error entries, indexed by HLA_t_ErrorId defined above */
} HLA_t_OutputErrors;

/*!
 * definition of system info type
 * this structure is passed to algo init() and run() functions as output argument, algo updates it at each call.
 * e.g. init(..., HLASystemInfo_t *sysInfo, ...);
 */
typedef struct
{
  HLA_t_OutputErrors      errors;
  HLA_t_eSystemState      state;
} HLA_t_SystemInfo;

/*! @description: Curve light rotation angle
    @resolution: 1.0      @accuracy: undef    @unit: [rad]
    @min: -20.0           @max: 20.0          @refreshtime: 60 ms */
typedef float32 HLA_t_fLightAngle;

/*! @description: Light output
    @resolution: 1        @accuracy: undef    @unit: [W]
    @min: 0               @max: 38.0          @refreshtime: 60 ms */
typedef float32 HLA_t_f32LightOutput;

/*! @description: Light distance
    @resolution: 1.0      @accuracy: undef    @unit: [m]
    @min: 0.0             @max: 600.0         @refreshtime: 60 ms */
typedef float32 HLA_t_fLightDistance;

/*! @description: Environmental brightness 
    @resolution: 1        @accuracy: undef    @unit: [-]
    @min: 0               @max: 14            @refreshtime: 60 ms */
typedef uint8 HLA_t_ui8ChangeoverLevel;

/*! Type definition for day time states */
typedef uint8 HLA_t_eActiveChar;
#define HLA_ACTIVE_CHAR_UNKNOWN (0u)
#define HLA_ACTIVE_CHAR_DAY     (1u)      /*!< Illumination time of day is day */
#define HLA_ACTIVE_CHAR_NIGHT   (2u)      /*!< Illumination time of day is night */
#define HLA_ACTIVE_CHAR_INVALID (255u)

/* Type definition for wiper washer state */
typedef uint8 HLA_t_eWiperWasherState;
#define HLA_WWSTATE_UNKNOWN (0u)      
#define HLA_WWSTATE_OFF     (1u)      /*!< Wiper/washer switch not pressed */
#define HLA_WWSTATE_TIPWIPE (2u)      /*!< Tip wiping pressed */
#define HLA_WWSTATE_WASH    (3u)      /*!< Washing pressed */
#define HLA_WWSTATE_INVALID (255u)

/* Type definition for wiper stages */
typedef uint8 HLA_t_eWiperStage;
#define HLA_WIPER_UNKNOWN    (0u)
#define HLA_WIPER_OFF        (1u)
#define HLA_WIPER_INTERVAL1  (2u)
#define HLA_WIPER_INTERVAL2  (3u)
#define HLA_WIPER_INTERVAL3  (4u)
#define HLA_WIPER_INTERVAL4  (5u)
#define HLA_WIPER_STAGE1     (6u)
#define HLA_WIPER_STAGE2     (7u)
#define HLA_WIPER_INVALID    (255u)

/*! Type definition for vehicle movement state. */
typedef uint8 HLA_t_eMovementState;
#define HLA_MOVE_STATE_UNKNOWN      (0u)
#define HLA_MOVE_STATE_FWD          (1u)
#define HLA_MOVE_STATE_REV          (2u)
#define HLA_MOVE_STATE_STAND_STILL  (3u)
#define HLA_MOVE_STATE_INVALID      (255u)

/*! Type definition for bayer pattern. */
typedef uint8 HLA_t_eBayerPatternType;
#define HLA_BAYERPATTERN_RGGB    (0u)  /*!< Bayer Pattern: RGRG:GBGB */
#define HLA_BAYERPATTERN_GRBG    (1u)  /*!< Bayer Pattern: GRGR:BGBG */
#define HLA_BAYERPATTERN_GBRG    (2u)  /*!< Bayer Pattern: GBGB:RGRG */
#define HLA_BAYERPATTERN_BGGR    (3u)  /*!< Bayer Pattern: BGBG:GRGR */
#define HLA_BAYERPATTERN_UNKNOWN (254u)
#define HLA_BAYERPATTERN_INVALID (255u)


/*! Type definition for sensor socket data */
typedef struct
{
  float32           f32_Z;         /*! Height over ground */
  float32           f32_Y;         /*! Offset lateral */
  float32           f32_X;         /*! Offset longitudinal */
} HLA_t_SensorSocket;


/*! Type definition for sensor angles */
typedef struct
{
  float32                               f32_Pitch;      /*!< Pitch angle */
  float32                               f32_Roll;       /*!< Roll angle */
  float32                               f32_Yaw;        /*!< Yaw angle */
  float32                               f32_Quality;    /*!< calibration quality: <2.55°: OK, =2.55°: NOK */
  eMonoCalibrationVerificationStatus_t  e_caliState;    /*!< degree of absolute deviation of calibration */
} HLA_t_SensorAngles;


/*! Type definition for vehicle level */
typedef struct 
{
  float32 f32_FrontLeft;  /* [m] */
  float32 f32_FrontRight; /* [m] */
  float32 f32_RearLeft;   /* [m] */
  float32 f32_RearRight;  /* [m] */
} HLA_t_VehLevel;



/*! Type definition for HLA availability signal */
typedef struct
{
  RTE_HLA_Type             e_Type;                                 /*!< Access to signal HLA availability. */
  RTE_HLA_State            e_State;                                /*!< Access to HLA State */
  RTE_HLA_US_Sens          e_USSens;                               /*!< Access to US sensitivity mode */
} HLA_t_Availability;

/*! Type definition for HLA Matrix glare free area status */
typedef struct  
{
  HLA_t_fLightAngle           f32_PartHBCutoffAng_Lt;                         /*< Access to left rotation angle vertical cutoff  */
  HLA_t_fLightAngle           f32_PartHBCutoffAng_Rt;                         /*< Access to right rotation angle vertical cutoff */
  HLA_t_fLightAngle           f32_HorCutOffAng;                               /*< Access to signal HLA horizontal cutoff angle   */
  HLA_t_fLightDistance        f32_LightDistance;                              /*< Access to signal HLA lighting distance         */
  RTE_HLA_CutOffLineState     e_HorCutOffAngState;                            /*< Access to state of horizontal cutoff angle     */
  RTE_HLA_CutOffLineState     e_LightDistanceState;                           /*< Access to state of light distance              */
  RTE_HLA_LightStyle          e_LightStyle_Lt;                                /*< Access to signal HLA light style left          */
  RTE_HLA_LightStyle          e_LightStyle_Rt;                                /*< Access to signal HLA light style right         */
} HLA_t_MatrixGFAState;

/*! Type definition for HLA input signal */
typedef struct
{
  RTE_HLA_LightModuleState    e_LightModuleState;                             /*< Access to signal HLA state HLM_LT              */
  ARRAY(HLA_t_MatrixGFAState, RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS, GFA); /*< Access to glare free areas                     */
  uint32                      nGFA;                                           /*< Access to number of used GFAs                  */
  RTE_HLAF_HighBeamState      e_HighBeamState;                                /*< Access to signal HLA high beam state           */
  HLA_t_fLightAngle           f32_CurveLightRotAngle_Lt;                      /*< Access to left curve light rotation angle      */
  HLA_t_fLightAngle           f32_CurveLightRotAngle_Rt;                      /*< Access to right curve light rotation angle     */
  RTE_HLA_GlareReductionState e_GlareReductionState;                          /*< Access to signal glare reduction state         */
  HLA_t_f32LightOutput        f32_LightOutput;                                /*< Access to signal HLA headlamp light output     */
} HLA_t_HeadlightState;


/*! Type definition for current imager characteristic */
typedef struct
{
  /* blacklevel (0 lux) */
  uint16 ui16_Blacklevel_R_Greyvalue; /* [12bit greyvalue] red pixel   */
  uint16 ui16_Blacklevel_G_Greyvalue; /* [12bit greyvalue] green pixel */
  uint16 ui16_Blacklevel_B_Greyvalue; /* [12bit greyvalue] blue pixel  */
  /* 1. kneepoint */
  uint16  ui16_Kneepoint1_Greyvalue; /* [12bit greyvalue]   */
  float32 f32_Kneepoint1_R_Lux;      /* [lux] red pixel     */
  float32 f32_Kneepoint1_G_Lux;      /* [lux] green pixel   */
  float32 f32_Kneepoint1_B_Lux;      /* [lux] blue pixel    */
  /* 2. kneepoint */
  uint16  ui16_Kneepoint2_Greyvalue; /* [12bit greyvalue]   */
  float32 f32_Kneepoint2_R_Lux;      /* [lux] red pixel     */
  float32 f32_Kneepoint2_G_Lux;      /* [lux] green pixel   */
  float32 f32_Kneepoint2_B_Lux;      /* [lux] blue pixel    */
  /* saturation */
  uint16  ui16_Saturation_Greyvalue; /* [12bit greyvalue]   */
  float32 f32_Saturation_R_Lux;      /* [lux] red pixel     */
  float32 f32_Saturation_G_Lux;      /* [lux] green pixel   */
  float32 f32_Saturation_B_Lux;      /* [lux] blue pixel    */
} HLA_t_ImagerResponseCurve;

/*! Type definition for current imager characteristic */
typedef struct
{
  uint32  ui32_R1;    /* requested R1 = T1/T2 [4x, 8x or 16x] */
  uint32  ui32_R2;    /* requested R2 = T2/T3 [4x, 8x or 16x] */
  float32 f32_T1_us;  /* [us] current integration time T1     */
  float32 f32_T2_us;  /* [us] current integration time T2     */
  float32 f32_T3_us;  /* [us] current integration time T3     */
  float32 f32_Gain;   /* [1]  total gain, depending on temperature */

  /* imager response curve (lux to 12bit greyvalues) */
  HLA_t_ImagerResponseCurve s_ResponseCurve; 
}HLA_t_ImagerCharacteristic;

/*! Type definition for imager state */
typedef struct
{
  HLA_t_eActiveChar         e_ActiveChar;                          /*!< Access to active characteristic of illumination control */
  float32                   f32_Brightness_Lux;                    /*!< current mean brightness in Lux of IC Roi */
  uint32                    ui32_ExposureTime_us;                  /*!< Access to current exposure time in us (= T1+T2+T3) */
  uint32                    ui32_FrameNumber;                      /*!< Access to the current frame number */
  float32                   f32_Noise;                             /*!> current imager noise, standard deviation of black pixels */ 

  HLA_t_ImagerCharacteristic s_ImagerCharacteristic;               /*!> imager characteristic  */
} HLA_t_ImagerState;


/*! Type definition for the motion state.*/
typedef struct 
{
  float32               f32_SpeedDisplay;                         /*!< [m/s] displayed speed (HMI)  */
                                                                  /*!<       driving forwards  (e_MoveState == HLA_MOVE_STATE_FWD) -> speed > 0 */
                                                                  /*!<       driving backwards (e_MoveState == HLA_MOVE_STATE_REV) -> speed < 0 */
  float32               f32_Speed;                                /*!< [m/s] longitudinal velocity. */
                                                                  /*!<       driving forwards  (e_MoveState == HLA_MOVE_STATE_FWD) -> speed > 0 */
                                                                  /*!<       driving backwards (e_MoveState == HLA_MOVE_STATE_REV) -> speed < 0 */
  float32               f32_Acceleration;                         /*!< [m/s²] longitudinal acceleration */
  float32               f32_YawRateRaw;                           /*!< [rad/s] raw yaw rate (from CAN/ FR), offset compensated */
  float32               f32_YawRate;                              /*!< [rad/s] estimated vehicle yaw rate (from vdy)  */
  float32               f32_YawRateVariance;                      /*!< Estimated vehicle yaw rate variance (from vdy) */
  float32               f32_YawRateQuality;                       /*!< Estimated vehicle yaw rate quality (from vdy)  */
  float32               f32_SteeringWheelAngle;                   /*!< [rad] current steering wheel angle. */
  float32               f32_SteeringAngle;                        /*!< [rad] current steering angle = steering wheel/ steering ratio */
                                                                  /*!<       angle of the front wheels                               */   
  HLA_t_eMovementState  e_MoveState;                              /*!< vehicle motion state e.g. DYN_VHEMOT_STAND_STILL, DYN_VHEMOT_ROLL_FWD,... */
  float32               f32_MoveStateConfidence;                  /*!< confidence of vehicle motion state   */
} HLA_t_MotionState;


/* Type definition for vehicle data */
typedef struct 
{
  boolean                   b_FogLampFront;                        /*!< fog lamps front active*/
  boolean                   b_FogLampRear;                         /*!< fog lamps rear active*/
  boolean                   b_RainSensor;                          /*!< rain sensor state */
  uint8                     ui8_WiperState;                        /*!< current wiper state, reported from wiper */
  HLA_t_eWiperWasherState   e_WiperWasherFrontState;               /*!< tip-wipe / washer state */
  HLA_t_eWiperStage         e_WiperStage;                          /*!< wiper switch position */
  HLA_t_VehLevel            s_VehicleLevel;                        /*!< current vehicle level */
} HLA_t_VehicleState;


/* Type definition for image size */
typedef struct
{
  uint32    ui32_x; /* [pix] image width  */
  uint32    ui32_y; /* [pix] image height */
} HLA_t_ImageSize;

typedef struct
{
  uint32    ui32_x; /* [pix] x position of first cropped Roi pixel (X1) */
  uint32    ui32_y; /* [pix] y position of first cropped Roi pixel (X1) */
} HLA_t_CroppedRoiX;

typedef struct
{
  float32   f32_x;  /* [pix] x-position of the lens center */
  float32   f32_y;  /* [pix] y-position of the lens center */
} HLA_t_LensCenter;


typedef struct
{
  float32   f32_x;  /* [pix] focal length in x-direction */
  float32   f32_y;  /* [pix] focal length in y-direction */
} HLA_t_FocalLength;


/* Type definition for RGB-Lux elements */
typedef struct
{
  float32                     f32_lux;                                  /*!< Access to the lux value. */
  float32                     f32_avgR;                                 /*!< Access to the average red value. */
  float32                     f32_avgG;                                 /*!< Access to the average green value. */
  float32                     f32_avgB;                                 /*!< Access to the average blue value. */
} HLA_t_RGBLuxElement;


/* Type definition for RGB-Lux table */
typedef struct
{
  uint32  ui32_R1;    /* requested R1 = T1/T2 [4x, 8x or 16x] */
  uint32  ui32_R2;    /* requested R2 = T2/T3 [4x, 8x or 16x] */
  float32 f32_T1_us;  /* [us] current integration time T1     */
  float32 f32_T2_us;  /* [us] current integration time T2     */
  float32 f32_T3_us;  /* [us] current integration time T3     */
  float32 f32_Gain;   /* [1]  total gain, depending on temperature */
  float32 f32_RatioRedGreen;  /* [1]  Red/ Green ratio      */
  float32 f32_RatioBlueGreen; /* [1]  Blue/ Green ratio     */
  float32 f32_RatioGreenRef;  /* [1]  Green reference ratio */

  uint32                    ui32_tableLength;                     /*!< number of valid RGB-Lux elements in the table. */
  ARRAY(HLA_t_RGBLuxElement, HLA_ui8_MAX_RGBL_ELEM, as_table);    /*!< the table with the RGB-Lux elements. */
} HLA_t_CalibratedRGBLuxTable;

/* Type definition for camera distortion parameter */
typedef struct
{
  float32 f32_K1;
  float32 f32_K2;
  float32 f32_K3;
  float32 f32_K4;
  float32 f32_K5; 
} HLA_t_CameraDistortion;

/* Type definition for camera parameter */
typedef struct
{
  HLA_t_eBayerPatternType     e_bayerPattern;       /*!< Bayer Pattern type */ 
  float32                     f32_cycleTime;        /*!< [s] cycle time of HLA Algo */ 
  HLA_t_FocalLength           s_FocalLength;        /*!< focal length */ 
  HLA_t_ImageSize             s_ImageSize;          /*!< total image size */
  HLA_t_ImageSize             s_CroppedRoiSize;     /*!< cropped roi size */
  HLA_t_CroppedRoiX           s_CroppedRoiX1;       /*!< first pixel position X1=(x1,y1) of cropped ROI in the image */    
  HLA_t_LensCenter            s_LensCenter;         /*!< lens center in absolute Imager coordinates, not in cropped ROI coordinates */
  HLA_t_CalibratedRGBLuxTable s_RGBLuxTable;        /*!< calibrated RGB-Lux table from EOL in Ingolstadt */
  HLA_t_CameraDistortion      s_Distortion;         /*!< camera distortion parameter */    
  ImageHeader_t               s_ImageHeader;        /*!< BitsPerPixel, BytesPerRow, ... */
} HLA_t_CameraParameter;
 




/*! Type definition for HLA blockage output */
typedef struct
{
  boolean            b_ClearanceMeasurement; /* TRUE: clearance measurement done; FALSE: clearance measurement not done */
  boolean            b_Condensation;
  boolean            b_Blockage;
  boolean            b_ManualOverride;
  AlgoSignalState_t  e_SigStatus;
} HLA_t_Blockage;


/*! Type definition for one defect pixel.  */
typedef struct
{
  uint16                        ui16_xPos;                      /*!< Access to x-position of the defect pixel. */
  uint16                        ui16_yPos;                      /*!< Access to y-position of the defect pixel. */
  RTE_HLAR_DefectPixelType      e_DefectType;                   /*!< Access to defect type of the pixel. */
  uint16                        ui16_Count;                     /*!< Access to counter for defect pixel existence check */
} HLA_t_ICDefectPixel;


/*! Type definition for the defect pixels list  */
typedef struct
{
  uint8                      ui8_DefectsListLength;                    /*!< Access to the length of the defects list. */
  AlgoSignalState_t          e_DefectsListLengthSigStat;               /*!< Access to signal quality of DefectsListLength. */
  ARRAY(HLA_t_ICDefectPixel, RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH, as_DefectList); /*!< Access to defect pixel length. */
} HLA_t_DefectPixelList;


typedef struct
{
  float32   f32_Pitch;     /* [rad] pitch angle of online calibration  */
  float32   f32_Yaw;       /* [rad] yaw   angle of online calibration  */
  float32   f32_Roll;      /* [rad] roll  angle of online calibration  */
  float32   f32_OdoCali_m; /* [m]   calibration odometer               */
} HLA_t_CaliOnline;


typedef struct 
{
  AlgoCycleCounter_t      FrameNumber;
  uint16                  x; /* absolute x-start position of fingerprint */
  uint16                  y; /* absolute y-start position of fingerprint */
  ARRAY(t_PixelData, HLA_FINGERPRINT_PIXELS, pix);
} HLA_t_Fingerprint; 


/*! object type definition */
typedef struct
{
  uint16 ui16_distMin_cm; /* [cm] min distance */
  uint16 ui16_distMax_cm; /* [cm] max distance */
} HLA_t_ObjectDistance;

/*! object type definition */
typedef struct
{
  uint32 isPotentialVehicleOncoming1st  : 1;  /*!< flag for potential oncoming traffic after 1st analysis level */
  uint32 isPotentialVehicleAhead1st     : 1;  /*!< flag for potential leading traffic after 1st analysis level  */
  uint32 isPotentialVehicleOncoming2nd  : 1;  /*!< flag for potential oncoming traffic after 2nd analysis level */
  uint32 isPotentialVehicleAhead2nd     : 1;  /*!< flag for potential leading traffic after 2nd analysis level  */
  uint32 isVehicleOncoming              : 1;  /*!< flag for reliably detected oncoming traffic */
  uint32 isVehicleAhead                 : 1;  /*!< flag for reliably detected leading traffic  */
  uint32 isTooBright                    : 1;  /*!< flag for objects, which lay over defined intensity thresholds */
  uint32 isRed                          : 1;  /*!< flag for red objects */

  uint32 isPulsedLight                  : 1;  /*!< flag for pulsed lights, like LED tail lamps */
  uint32 isRed2                         : 1;  /*!< flag #2 for red objects */
  uint32 isMovingWhite                  : 1;  /*!< flag for contra motion with white color */
  uint32 isMovingNonWhite               : 1;  /*!< flag for contra motion with non-white color */
  uint32 isOncomingPair                 : 1;  /*!< flag for oncoming pair detection */
  uint32 isPotentialVehicleHighProbable : 1;  /*!< flag for potential candidate with high probability to become a detected vehicle soon */
  uint32 Bit_14                         : 1;  /*!< Bit_14 */
  uint32 Bit_15                         : 1;  /*!< Bit_15 */

  uint32 isStreetLamp                   : 1;  /*!< flag for detected street lamps */
  uint32 isAboveROI                     : 1;  /*!< flag for object that are above hla main ROI */
  uint32 isInfinite                     : 1;  /*!< flag for very far objects */
  uint32 is3DCorrect                    : 1;  /*!< flag for object with a correct static 3D estimation */
  uint32 isChainOfLight                 : 1;  /*!< flag for object that are in a chain of light */
  uint32 isBrightObject                 : 1;  /*!< flag for bright objects which could blind the driver (headlamp dimming candidates) */
  uint32 isPotentialTruckLight          : 1;  /*!< Bit_22 */
  uint32 Bit_23                         : 1;  /*!< Bit_23 */

  uint32 isTrackedInPair                : 1;  /*!< flag for tracks tracked within a pair */
  uint32 willBeRemoved                  : 1;  /*!< flag for tracks to be removed next cycle */
  uint32 isOneToOneAssociation          : 1;  /*!< set to 1 when track can only be associated to ONE light, and associated light can only be associated to this track, and light is isolated : it's a robust association */
  uint32 trackerClassStatic             : 1;  /*!< set to 1 when track is a static object (otherwise it may be unknown or dynamic) */
  uint32 trackerClassDynamic            : 1;  /*!< set to 1 when track is a dynamic object (otherwise it may be unknown or static) */
  uint32 Bit_29                         : 1;  /*!< Bit_29 */
  uint32 Bit_30                         : 1;  /*!< Bit_30 */
  uint32 Bit_31                         : 1;  /*!< Bit_31 */
} HLA_t_ObjectStatus;


/*! object region definition */
typedef struct
{
  uint16 ui16_x1;
  uint16 ui16_y1;
  uint16 ui16_x2;
  uint16 ui16_y2;
} HLA_t_ObjectRegion;

typedef struct  
{
  uint8 ledDetectionCalled            : 1;           /* icon led detection has been applied */
  uint8 streetLampDetectionCalled     : 1;           /* icon street lamp classifier has been applied */
  uint8 redLightDetectionCalled       : 1;           /* icon red light classifier has been applied */
  uint8 skippedBadPosition            : 1;           /* classification skipped because the predicted position didn't match the track position */
  uint8 Bit_04                        : 1;           /* Bit 04 */
  uint8 Bit_05                        : 1;           /* Bit 05 */
  uint8 Bit_06                        : 1;           /* Bit 06 */
  uint8 Bit_07                        : 1;           /* Bit 07 */
} HLA_t_ObjectIconStatus;

typedef struct  
{
  HLA_t_ObjectIconStatus status; /* various status bits */
  uint8 classCnt;                /* total number of applied icon classifications */
  sint16 classResultSum;         /* summed up classification response result from IconResultInfo. Increased for vehicle, decreased for no vehicle. */
} HLA_t_ObjectIconState;

/*! object type definition */
typedef struct
{
  /* object id = array index in the track list */
  uint8                       ui8_Id;

  /* object id of the pair light = array index in the track list: 255 = no pair */
  uint8                       ui8_IdPairLight;

  /* number of lost updates (reset if track is updated)       */
  uint8                       ui8_lost_time;
    
  /* just for byte alignment */  
  uint8                       ui8_LightID; 

  /* age of the object */
  uint16                      ui16_trace_time;

  /* blinding time of the preceding/ oncoming vehicle = cycles until object is detected as vehicle */
  uint16                      ui16_blind_time;  

  /* object x,y-position in the image (absolute image coordinates) */
  sint16                      si16_xcenter; 
  sint16                      si16_ycenter;
  
  /* track motion inside the image (without any ego motion compensation) */
  sint16                      si16_delta_x;
  sint16                      si16_delta_y;
  /* low pass filtered track motion inside the image (without any ego motion compensation) */
  sint16                      si16_delta_x_lp;
  sint16                      si16_delta_y_lp;

  /* object Status */
  HLA_t_ObjectStatus          s_Status;

  /* [lux] object intensity */
  uint16                      ui16_Intensity_lux;
  uint16                      ui16_Dummy;

  /* [ms] time to border */
  uint16                      ui16_ttb_ms;
  uint16                      ui16_ttb18_ms;

  /* first detection of track in the image (absolute coordinates) */
  sint16                      si16_xcenter_FD; 
  sint16                      si16_ycenter_FD;

  /* light distance = distance where the oncoming/ preceding vehicle will not be blinded) */
  HLA_t_ObjectDistance        s_LightDist;

  /* object distance in the world in x direction (AUTOSAR) */
  HLA_t_ObjectDistance        s_ObjectPos_xw;
  /* horizontal object angle in the world     */
  /* ang = atanf(yw/ (0.5*(xw_max + xw_min))) */
  float32                     f32_ObjectHorAng_rad;
  /* object position in the world in y,z direction (AUTOSAR) */
  /* yw,zw calc. at xw = 0.5*(xw_max + xw_min)               */
  sint16                      si16_ObjectPos_yw_cm; /* [cm] */
  sint16                      si16_ObjectPos_zw_cm; /* [cm] */

  /* icon information */
  HLA_t_ObjectIconState       s_IconState;

  uint8                       ui8_ExistenceProb; /* [%] existence probability of vehicle */
  uint8                       ui8_Dummy1[7];
} HLA_t_Object;


/*! region levels for the HlaRoi = FunctionRoi + AboveRoi */
typedef struct
{
  /* lux level which defines the regions */
  float32      f32_Level[RTE_HLA_SEG_MAX_NUM_LEVELS];
} HLA_t_ObjectRegionLevel;
 

/*! absolute imager position of the HlaRoi = FunctionRoi + AboveRoi */
typedef struct
{
  uint16 ui16_RoiX1;
  uint16 ui16_RoiX2;
  uint16 ui16_RoiY1;
  uint16 ui16_RoiY2;
  uint16 ui16_RoiYu; /* y-border between AboveRoi (city detection) and functionRoi (vehicle detection) */
} HLA_t_ObjectRoi;

/*! Focus of expansion in absolute imager coordinates */
typedef struct
{
  uint16 ui16_X;
  uint16 ui16_Y;
} HLA_t_ObjectFOE;


/*! Object list */
typedef struct
{
  uint32                   ui32_Version;              /*!< object list version number         */
  uint32                   ui32_HLA_SWVersionNumber;  /*!< HLA Software version number        */
  AlgoCycleCounter_t       uiFrameCnt;                /*!< Frame counter                      */
  AlgoCycleCounter_t       uiHLAR_Cnt;                /*!< HLAR cycle counter                 */
  AlgoDataTimeStamp_t      uiTimeStamp_HLA_us;        /*!< [us] HLA Timestamp, hla input data */

  /* position of the ROI = HLA Roi + Above Roi (absolute imager coordinates) */
  HLA_t_ObjectRoi           s_ObjectRoi;
  /* focus of expansion in absolute imager coordinates */
  HLA_t_ObjectFOE           s_ObjectFOE;
  

  uint32                    ui32_NumVehicles;                    /*!< number of detected vehicles, first in the list  */
  uint32                    ui32_NumObjects;                     /*!< number of all objects                           */
  ARRAY(HLA_t_Object, RTE_HLAR_OBJECT_LIST_LENGTH, as_Object);   /*!< object list                                     */
} HLA_t_ObjectList;



typedef struct
{
  RTE_HLAR_HighwayLatPosState          e_LateralPosition;
  RTE_HLAR_HighwayEgoMotionState       e_EgoMotion;
  RTE_HLAR_eHighwayOcclusionState      e_OcclusionDetection;
  RTE_HLAR_eHighwaySpeedDetectionState e_SpeedDetection;

  float32                              f32_ConfLatPos;
  float32                              f32_ConfEgoMotion;
  float32                              f32_ConfOcclDtction;

  RTE_HLAF_MotorwayState               e_HighwayOutInternal;

} HLA_t_Highway;


/* environment data */
typedef struct
{
  RTE_HLAR_BrightnessState    e_Brightness;
  RTE_HLAR_CityState          e_City;
  RTE_HLA_TrafficStyle        e_TrafficStyle;
  RTE_HLAR_TrafficStyleState  e_TrafficStyleState;
  RTE_HLAR_Tunnel             e_Tunnel;
  HLA_t_Highway               s_Highway;
  RTE_HLAR_WeatherState       e_Weather;
  RTE_HLAR_RedReflectorArea   e_RedReflectorArea;
} HLA_t_EnvironmentData;

/* traffic style */
typedef struct
{
  RTE_HLA_TrafficStyle               e_TrafficStyleLastLearned;
  RTE_HLAR_TrafficStyleLearningState e_TrafficStyleLearningState;
} HLA_t_TrafficStyle;


/*!< Diagnosis message for HLA debugging purposes */
/* diagnosis debug message state: */
typedef enum
{
  HLA_DDM_STATE__INIT = 0u, /* do not use */
  HLA_DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON,
  HLA_DDM_STATE__HLAF_TURN_OFF_REASON,
  HLA_DDM_STATE__HLAF_KEEP_OFF_REASON,
  HLA_DDM_STATE__HLA_VERSION,
  HLA_DDM_STATE__HB_ON, /* high beam on */
  HLA_DDM_STATE__6,
  HLA_DDM_STATE__7
}HLA_t_eDiagnosisDebugMsgState;

/* Diagnosis Debug Message */
typedef union
{
  AlgoDataTimeStamp_t  ui64_DiagnosisDebugMsg;

#ifdef HLA_LITTLE_ENDIAN
  struct {
    uint32 Low;
    uint32 High;
  } Long;
#else
  /* HLA_BIG_ENDIAN */
  struct {
    uint32 High;
    uint32 Low;
  } Long;
#endif

  /**************************/
  /* HLA_DDM_STATE__HB_ON       */
  /* state = 5              */
  /**************************/
#ifdef HLA_LITTLE_ENDIAN
  struct {
    /* 1. icon */
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Icon1_Oncom_TooBright                  : 1;
    uint32 Icon1_Oncom_ContraMotionWhite          : 1;     
    uint32 Icon1_Oncom_OncomingPair               : 1;           
    uint32 Icon1_Oncom_CenterBright               : 1;           
    uint32 Icon1_Oncom_ExtremeBright              : 1;          
    uint32 Icon1_Oncom_LateralBright              : 1;          
    uint32 Icon1_Oncom_Other                      : 1;

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Icon1_Ahead_RedLight                   : 1;               
    uint32 Icon1_Ahead_RedLight2                  : 1;              
    uint32 Icon1_Ahead_PulsedLight                : 1;            
    uint32 Icon1_Ahead_ContraMotionNonWhite       : 1;  
    uint32 Icon1_Ahead_Other                      : 1;        

    /* icon result info */
    uint32 Icon1_result                           : 2; /* icon classification result */
    uint32 Icon1_result_Unused                    : 1;

    /* icon status */
    uint32 Icon1_Status_ledDetectionCalled        : 1; /* icon led detection has been applied */
    uint32 Icon1_Status_streetLampDetectionCalled : 1; /* icon street lamp classifier has been applied */
    uint32 Icon1_Status_redLightDetectionCalled   : 1; /* icon red light classifier has been applied */

    uint32 Icon1_classResult_Vehicle              : 1; /* 0: no vehicle, 1: vehicle */
    uint32 Icon1_classResult_Sum                  : 7; /* summed up classification result */

    /* 2. icon */
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Icon2_Oncom_TooBright                  : 1;
    uint32 Icon2_Oncom_ContraMotionWhite          : 1;     
    uint32 Icon2_Oncom_OncomingPair               : 1;           
    uint32 Icon2_Oncom_CenterBright               : 1;           
    uint32 Icon2_Oncom_ExtremeBright              : 1;          
    uint32 Icon2_Oncom_LateralBright              : 1;

    /* 32 Bit alignment */

    uint32 Icon2_Oncom_Other                      : 1;

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Icon2_Ahead_RedLight                   : 1;               
    uint32 Icon2_Ahead_RedLight2                  : 1;              
    uint32 Icon2_Ahead_PulsedLight                : 1;            
    uint32 Icon2_Ahead_ContraMotionNonWhite       : 1;  
    uint32 Icon2_Ahead_Other                      : 1;        

    /* icon result info */
    uint32 Icon2_result                           : 2; /* icon classification result */
    uint32 Icon2_result_Unused                    : 1;


    /* icon status */
    uint32 Icon2_Status_ledDetectionCalled        : 1; /* icon led detection has been applied */
    uint32 Icon2_Status_streetLampDetectionCalled : 1; /* icon street lamp classifier has been applied */
    uint32 Icon2_Status_redLightDetectionCalled   : 1; /* icon red light classifier has been applied */

    uint32 Icon2_classResult_Vehicle              : 1; /* 0: no vehicle, 1: vehicle */
    uint32 Icon2_classResult_Sum                  : 7; /* summed up classification result */


    uint32 Dummy1                                 : 2; /* due to 4 bit alignment */

    uint32 RedReflectorArea                       : 1; /*!< 0: no red reflector area, 1: red reflector area */

    uint32 SamplingAborted                        : 1; /*!< 0: no sampling aborted, 1: sampling aborted */

    uint32 FrameDrop                              : 1;  /*!< 0: no frame drop, 1: one or more HLA frames droped */  

    uint32 eState                                  : 3;  /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4: HLA Version, 5-7: Brunn */

    uint32 NextState                              : 3;  /* next state     */
    uint32 Dummy0                                 : 1; 
  } HBon;
#else
/* HLA_BIG_ENDIAN */
  struct {
    uint32 Dummy0                                 : 1; 
    uint32 NextState                              : 3;  /* next state     */
    uint32 eState                                 : 3;  /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4: HLA Version, 5-7: Brunn */
    uint32 FrameDrop                              : 1;  /*!< 0: no frame drop, 1: one or more HLA frames droped */  
    uint32 SamplingAborted                        : 1; /*!< 0: no sampling aborted, 1: sampling aborted */
    uint32 RedReflectorArea                       : 1; /*!< 0: no red reflector area, 1: red reflector area */
    uint32 Dummy1                                 : 2; /* due to 4 bit alignment */

    /* 2. icon */
    uint32 Icon2_classResult_Sum                  : 7; /* summed up classification result */
    uint32 Icon2_classResult_Vehicle              : 1; /* 0: no vehicle, 1: vehicle */

    /* icon status */
    uint32 Icon2_Status_redLightDetectionCalled   : 1; /* icon red light classifier has been applied */
    uint32 Icon2_Status_streetLampDetectionCalled : 1; /* icon street lamp classifier has been applied */
    uint32 Icon2_Status_ledDetectionCalled        : 1; /* icon led detection has been applied */

    /* icon result info */
    uint32 Icon2_result_Unused                    : 1;
    uint32 Icon2_result                           : 2; /* icon classification result */

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Icon2_Ahead_Other                      : 1;        
    uint32 Icon2_Ahead_ContraMotionNonWhite       : 1;  
    uint32 Icon2_Ahead_PulsedLight                : 1;            
    uint32 Icon2_Ahead_RedLight2                  : 1;              
    uint32 Icon2_Ahead_RedLight                   : 1;               

    uint32 Icon2_Oncom_Other                      : 1;
    
    /* 32 Bit alignment */
    
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Icon2_Oncom_LateralBright              : 1;
    uint32 Icon2_Oncom_ExtremeBright              : 1;       
    uint32 Icon2_Oncom_CenterBright               : 1;        
    uint32 Icon2_Oncom_OncomingPair               : 1;           
    uint32 Icon2_Oncom_ContraMotionWhite          : 1;     
    uint32 Icon2_Oncom_TooBright                  : 1;


    /* 1. icon */
    /* icon status */
    uint32 Icon1_classResult_Sum                  : 7; /* summed up classification result */
    uint32 Icon1_classResult_Vehicle              : 1; /* 0: no vehicle, 1: vehicle */
    uint32 Icon1_Status_redLightDetectionCalled   : 1; /* icon red light classifier has been applied */
    uint32 Icon1_Status_streetLampDetectionCalled : 1; /* icon street lamp classifier has been applied */
    uint32 Icon1_Status_ledDetectionCalled        : 1; /* icon led detection has been applied */

    /* icon result info */
    uint32 Icon1_result_Unused                    : 1;
    uint32 Icon1_result                           : 2; /* icon classification result */

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Icon1_Ahead_Other                      : 1;  
    uint32 Icon1_Ahead_ContraMotionNonWhite       : 1;  
    uint32 Icon1_Ahead_PulsedLight                : 1;           
    uint32 Icon1_Ahead_RedLight2                  : 1;  
    uint32 Icon1_Ahead_RedLight                   : 1;               
    
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Icon1_Oncom_Other                      : 1;
    uint32 Icon1_Oncom_LateralBright              : 1;     
    uint32 Icon1_Oncom_ExtremeBright              : 1;      
    uint32 Icon1_Oncom_CenterBright               : 1;      
    uint32 Icon1_Oncom_OncomingPair               : 1;         
    uint32 Icon1_Oncom_ContraMotionWhite          : 1;     
    uint32 Icon1_Oncom_TooBright                  : 1;

    
  } HBon;
#endif


  /*******************************************/
  /* HLA_DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON */
  /* state = 1                               */
  /*******************************************/
#ifdef HLA_LITTLE_ENDIAN
  struct {
    /* initial turn off reason */
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Oncom_TooBright                : 1;
    uint32 Oncom_ContraMotionWhite        : 1;     
    uint32 Oncom_OncomingPair             : 1;           
    uint32 Oncom_CenterBright             : 1;           
    uint32 Oncom_ExtremeBright            : 1;          
    uint32 Oncom_LateralBright            : 1;          
    uint32 Oncom_Unused                   : 8;
    /* 2nd level turn offs */
    uint32 Oncom_SuddenlyAppearingVehicle : 1;
    uint32 Oncom_ClassResultReached       : 1;      

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Ahead_RedLight                 : 1;               
    uint32 Ahead_RedLight2                : 1;              
    uint32 Ahead_PulsedLight              : 1;            
    uint32 Ahead_ContraMotionNonWhite     : 1;  
    uint32 Ahead_Unused                   : 6;                  
    /* 2nd level turn offs */
    uint32 Ahead_Overtaker                : 1;
    uint32 Ahead_DriveDistReached         : 1;
    uint32 Ahead_DriveDistDynamicReached  : 1;
    uint32 Ahead_DriveDistPairReached     : 1;
    uint32 Ahead_SuddenlyAppearingVehicle : 1;
    uint32 Ahead_ClassResultReached       : 1;

    /* 32 Bit alignment */

    uint32 Dummy2                         : 16;

    uint32 FrameCnt                       : 4; /* lower 4 Bits of (FrameCnt/2) */

    uint32 Dummy1                         : 2; /* due to 4 bit alignment */

    uint32 RedReflectorArea               : 1; /*!< 0: no red reflector area, 1: red reflector area */

    uint32 SamplingAborted                : 1; /*!< 0: no sampling aborted, 1: sampling aborted */

    uint32 FrameDrop                      : 1;  /*!< 0: no frame drop, 1: one or more HLA frames droped */  

    uint32 eState                          : 3;  /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 NextState                      : 3;  /* next state     */
    uint32 Dummy0                         : 1; 
  } HLARInitialTurnOffReason;
#else
/* HLA_BIG_ENDIAN */
  struct {
    uint32 Dummy0                         : 1; 
    uint32 NextState                      : 3;  /* next state     */
    uint32 eState                         : 3;  /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 FrameDrop                      : 1;  /*!< 0: no frame drop, 1: one or more HLA frames droped */  
    uint32 SamplingAborted                : 1; /*!< 0: no sampling aborted, 1: sampling aborted */
    uint32 RedReflectorArea               : 1; /*!< 0: no red reflector area, 1: red reflector area */
    uint32 Dummy1                         : 2; /* due to 4 bit alignment */
    uint32 FrameCnt                       : 4; /* lower 4 Bits of (FrameCnt/2) */
    uint32 Dummy2                         : 16;

    /* 32 Bit alignment */

    /* initial turn off reason */
    /* oncoming traffic        */
    /* 1st level turn offs     */
    uint32 Oncom_TooBright                : 1;
    uint32 Oncom_ContraMotionWhite        : 1;     
    uint32 Oncom_OncomingPair             : 1;           
    uint32 Oncom_CenterBright             : 1;           
    uint32 Oncom_ExtremeBright            : 1;          
    uint32 Oncom_LateralBright            : 1;          
    uint32 Oncom_Unused                   : 8;
    /* 2nd level turn offs */
    uint32 Oncom_SuddenlyAppearingVehicle : 1;
    uint32 Oncom_ClassResultReached       : 1;      

    /* preceding traffic   */
    /* 1st level turn offs */
    uint32 Ahead_RedLight                 : 1;               
    uint32 Ahead_RedLight2                : 1;              
    uint32 Ahead_PulsedLight              : 1;            
    uint32 Ahead_ContraMotionNonWhite     : 1;  
    uint32 Ahead_Unused                   : 6;                  
    /* 2nd level turn offs */
    uint32 Ahead_Overtaker                : 1;
    uint32 Ahead_DriveDistReached         : 1;
    uint32 Ahead_DriveDistDynamicReached  : 1;
    uint32 Ahead_DriveDistPairReached     : 1;
    uint32 Ahead_SuddenlyAppearingVehicle : 1;
    uint32 Ahead_ClassResultReached       : 1;
  } HLARInitialTurnOffReason;
#endif


/*******************************************/
/* HLA_DDM_STATE__HLAF_TURN_OFF_REASON         */
/* state = 2                               */
/*******************************************/
#ifdef HLA_LITTLE_ENDIAN
  struct {
    /* global turn off reason */
    uint32 Global_NotReleased             : 1; 
    uint32 Global_NotReleasedRedPerf      : 1;   
    uint32 Global_NotReleasedBlockage     : 1; 
    uint32 Global_RedPerformance          : 1; 
    uint32 Global_Blockage                : 1; 
    uint32 Global_Brightness              : 1; 
    uint32 Global_Maxima                  : 1; 
    uint32 Global_Lights                  : 1; 
    uint32 Global_City                    : 1; 
    uint32 Global_Tunnel                  : 1; 
    uint32 Global_MinSpeed                : 1; 
    uint32 Global_NotActive               : 1; 
    uint32 Global_NotAvl                  : 1; 
    uint32 Global_NotCalibrated           : 1; 
    uint32 Global_Error                   : 1; 
    uint32 Global_Unused                  : 3;

    /* HLA Light turn off reason */
    uint32 Light_OncDetected              : 1;
    uint32 Light_PrecDetected             : 1;
    uint32 Light_Unused                   : 1;

    /* HLA Standard turn off reason */
    uint32 Std_OncDetected                : 1;
    uint32 Std_PrecDetected               : 1;
    uint32 Std_Unused                     : 1;

    /* HLA plus full HB turn off reason */
    uint32 Plus_OncDetected               : 1;  /*!< oncoming  traffic which deactivates full HB */
    uint32 Plus_PrecDetected              : 1;  /*!< preceding traffic which deactivates full HB */
    uint32 Plus_Unused                    : 1;

    /* HLA Plus partial HB turn off reason */
    uint32 PlusLeft_OncomingOnly          : 1;  /*!< only oncoming vehicles detected (no preceding vehicles) -> turn of left HB */
    uint32 PlusRight_OncomingOnly         : 1;  /*!< only oncoming vehicles detected (no preceding vehicles) -> turn of left HB */

    uint32 PlusLeft_AngOutermost2Large    : 1;  /*!< the (predicted) outer most angle is too large (e.g. > 15°)             */   
    uint32 PlusRight_AngOutermost2Large   : 1;  /*!< the (predicted) outer most angle is too large (e.g. > 15°)             */   

    uint32 PlusLeft_OncomingDeactRegion   : 1;  /*!< oncoming traffic in right deactivation region -> left partial HB off   */
  
    /* 32 Bit alignment */    

    uint32 PlusRight_OncomingDeactRegion  : 1;  /*!< oncoming traffic in right deactivation region -> left partial HB off   */

    uint32 PlusLeft_OncLeftPrec           : 1;  /*!< turn off left partial HB because oncoming vehicle is detected on left side of the preceding car */
    uint32 PlusRight_OncLeftPrec          : 1;  /*!< turn off left partial HB because oncoming vehicle is detected on left side of the preceding car */

    uint32 PlusLeft_TTD                   : 1;  /*!< deactivate partial HB in advance when TTD is small */
    uint32 PlusRight_TTD                  : 1;  /*!< deactivate partial HB in advance when TTD is small */

    uint32 PlusLeft_RightOff              : 1;  /*!< right hand traffic: deactivate left HB when right HB will be deactivated */
    uint32 PlusRight_RightOff             : 1;  /*!< right hand traffic: deactivate left HB when right HB will be deactivated */

    uint32 PlusLeft_dAng2Large            : 1;  /*!< left Partial HB wants to move more than 3° -> turn off left partial HB */
    uint32 PlusRight_dAng2Large           : 1;  /*!< left Partial HB wants to move more than 3° -> turn off left partial HB */

    uint32 PlusLeft_Oncoming              : 1;  /*!< oncoming  traffic which deactivates full/ partial HB */
    uint32 PlusRight_Oncoming             : 1;  /*!< oncoming  traffic which deactivates full/ partial HB */    

    uint32 PlusLeft_Preceding             : 1;  /*!< preceding traffic which deactivates full/ partial HB */
    uint32 PlusRight_Preceding            : 1;  /*!< preceding traffic which deactivates full/ partial HB */    

    uint32 PlusLeft_MinSpeed              : 1;  /*!< min activation speed */
    uint32 PlusRight_MinSpeed             : 1;  /*!< min activation speed */

    uint32 PlusLeft_MayBeCity             : 1;  /*!< HB on, vehicle detected may be city detected -> partial HB off because city will be detected in the next frames */
    uint32 PlusRight_MayBeCity            : 1;  /*!< HB on, vehicle detected may be city detected -> partial HB off because city will be detected in the next frames */

    uint32 PlusLeft_Motorway              : 1;  /*!< motorway: oncoming or preceding vehicle detected -> turn off left partial HB */
    uint32 PlusRight_Motorway             : 1;  /*!< motorway: oncoming or preceding vehicle detected -> turn off left partial HB */

    uint32 PlusLeft_Unused                : 3;
    uint32 PlusRight_Unused               : 3;

    uint32 eState                          : 3;  /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 NextState                      : 3;  /* next state     */
    uint32 Dummy0                         : 1; 
  } HLAFTurnOffReason;
#else
/* HLA_BIG_ENDIAN */
  struct {
    uint32 Dummy0                         : 1; 
    uint32 NextState                      : 3;  /* next state     */
    uint32 eState                         : 3;  /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 PlusRight_Unused               : 3;
    uint32 PlusLeft_Unused                : 3;

    uint32 PlusRight_Motorway             : 1;  /*!< motorway: oncoming or preceding vehicle detected -> turn off left partial HB */
    uint32 PlusLeft_Motorway              : 1;  /*!< motorway: oncoming or preceding vehicle detected -> turn off left partial HB */

    uint32 PlusRight_MayBeCity            : 1;  /*!< HB on, vehicle detected may be city detected -> partial HB off because city will be detected in the next frames */
    uint32 PlusLeft_MayBeCity             : 1;  /*!< HB on, vehicle detected may be city detected -> partial HB off because city will be detected in the next frames */

    uint32 PlusRight_MinSpeed             : 1;  /*!< min activation speed */
    uint32 PlusLeft_MinSpeed              : 1;  /*!< min activation speed */

    uint32 PlusRight_Preceding            : 1;  /*!< preceding traffic which deactivates full/ partial HB */    
    uint32 PlusLeft_Preceding             : 1;  /*!< preceding traffic which deactivates full/ partial HB */

    uint32 PlusRight_Oncoming             : 1;  /*!< oncoming  traffic which deactivates full/ partial HB */    
    uint32 PlusLeft_Oncoming              : 1;  /*!< oncoming  traffic which deactivates full/ partial HB */

    uint32 PlusRight_dAng2Large           : 1;  /*!< left Partial HB wants to move more than 3° -> turn off left partial HB */
    uint32 PlusLeft_dAng2Large            : 1;  /*!< left Partial HB wants to move more than 3° -> turn off left partial HB */

    uint32 PlusRight_RightOff             : 1;  /*!< right hand traffic: deactivate left HB when right HB will be deactivated */
    uint32 PlusLeft_RightOff              : 1;  /*!< right hand traffic: deactivate left HB when right HB will be deactivated */

    uint32 PlusRight_TTD                  : 1;  /*!< deactivate partial HB in advance when TTD is small */
    uint32 PlusLeft_TTD                   : 1;  /*!< deactivate partial HB in advance when TTD is small */

    uint32 PlusRight_OncLeftPrec          : 1;  /*!< turn off left partial HB because oncoming vehicle is detected on left side of the preceding car */
    uint32 PlusLeft_OncLeftPrec           : 1;  /*!< turn off left partial HB because oncoming vehicle is detected on left side of the preceding car */

    uint32 PlusRight_OncomingDeactRegion  : 1;  /*!< oncoming traffic in right deactivation region -> left partial HB off   */

    /* 32 Bit alignment */    

    /* HLA Plus partial HB turn off reason */
    uint32 PlusLeft_OncomingDeactRegion   : 1;  /*!< oncoming traffic in right deactivation region -> left partial HB off   */    
    uint32 PlusRight_AngOutermost2Large   : 1;  /*!< the (predicted) outer most angle is too large (e.g. > 15°)             */   
    uint32 PlusLeft_AngOutermost2Large    : 1;  /*!< the (predicted) outer most angle is too large (e.g. > 15°)             */   
    uint32 PlusRight_OncomingOnly         : 1;  /*!< only oncoming vehicles detected (no preceding vehicles) -> turn of left HB */
    uint32 PlusLeft_OncomingOnly          : 1;  /*!< only oncoming vehicles detected (no preceding vehicles) -> turn of left HB */


    uint32 Plus_Unused                    : 1;
    uint32 Plus_PrecDetected              : 1;  /*!< preceding traffic which deactivates full HB */
    uint32 Plus_OncDetected               : 1;  /*!< oncoming  traffic which deactivates full HB */

    /* HLA plus full HB turn off reason */
    uint32 Std_Unused                     : 1;
    uint32 Std_PrecDetected               : 1;
    uint32 Std_OncDetected                : 1;
  
    /* HLA Light turn off reason */
    uint32 Light_Unused                   : 1;
    uint32 Light_PrecDetected             : 1;
    uint32 Light_OncDetected              : 1;

    /* global turn off reason */
    uint32 Global_Unused                  : 3;
    uint32 Global_Error                   : 1; 
    uint32 Global_NotCalibrated           : 1; 
    uint32 Global_NotAvl                  : 1; 
    uint32 Global_NotActive               : 1; 
    uint32 Global_MinSpeed                : 1; 
    uint32 Global_Tunnel                  : 1; 
    uint32 Global_City                    : 1; 
    uint32 Global_Lights                  : 1; 
    uint32 Global_Maxima                  : 1; 
    uint32 Global_Brightness              : 1; 
    uint32 Global_Blockage                : 1; 
    uint32 Global_RedPerformance          : 1; 
    uint32 Global_NotReleasedBlockage     : 1; 
    uint32 Global_NotReleasedRedPerf      : 1;   
    uint32 Global_NotReleased             : 1; 
  } HLAFTurnOffReason;
#endif


/*******************************************/
/* HLA_DDM_STATE__HLAF_KEEP_OFF_REASON         */
/* state = 3                               */
/*******************************************/
#ifdef HLA_LITTLE_ENDIAN
  struct {
    /* HLA Standard keep off reason*/
    uint32 Std_SpdAcc                       : 1;  /*!< velocity will fall below activation speed in less than 2.5 seconds */
    uint32 Std_SmallRadius                  : 1;  /*!< small radius */
    uint32 Std_MinTimeHBOff                 : 1;  /*!< keep HB off for a minimal time */
    uint32 Std_TurnOnDelay                  : 1;  /*!< turn on delay */
    uint32 Std_PrecedingVehLost             : 1;  /*!< preceding vehicle lost in curve -> keep HB off until we reached the position and we are at the end of the curve */
    uint32 Std_MaybeCity                    : 1;  /*!< may be city detected keep full HB off because city will be detected in same frames */
    uint32 Std_PotVeh                       : 1;  /*!< potential vehcile   */
    uint32 Std_Unused                       : 3;

    /* HLA Plus full HB keep off reason */
    uint32 Plus_HB_Off                      : 1;  /*!< HB off from old decision */
    uint32 Plus_minTimeOff                  : 1;  /*!< minimum time low beam on before switching to full HB   */
    uint32 Plus_minTimePartOn               : 1;  /*!< minimum time partial HB on before switching to full HB */   
    uint32 Plus_Unused                      : 2;

    /* HLA Plus partial HB keep off reason */
    uint32 PlusLeft_TimeToDeact             : 1;  /*!< Object is moving from ACT/HOLD to DEACT soon */
    uint32 PlusRight_TimeToDeact            : 1;  /*!< Object is moving from ACT/HOLD to DEACT soon */

    uint32 PlusLeft_TimeToBorder            : 1;  /*!< Object in DEACT is lost */   
    uint32 PlusRight_TimeToBorder           : 1;  /*!< Object in DEACT is lost */      

    uint32 PlusLeft_NoOncomingMinTime       : 1;  /*!< after last oncoming vehicle passed keep partial HB off for a minimal time */
    uint32 PlusRight_NoOncomingMinTime      : 1;  /*!< after last oncoming vehicle passed keep partial HB off for a minimal time */    

    uint32 PlusLeft_NoOncoming              : 1;  /*!< keep off HB until no oncoming traffic is detected anymore */
    uint32 PlusRight_NoOncoming             : 1;  /*!< keep off HB until no oncoming traffic is detected anymore */

    uint32 PlusLeft_OutermostLost           : 1;  /*!< outermost vehicle lost -> keep HB off */
    uint32 PlusRight_OutermostLost          : 1;  /*!< outermost vehicle lost -> keep HB off */

    uint32 PlusLeft_SyncSinglePrecCar       : 1;  /*!< synchronously partial HB on when only 1 or 2 preceding lights detected  */
    uint32 PlusRight_SyncSinglePrecCar      : 1;  /*!<  synchronously partial HB on when only 1 or 2 preceding lights detected */

    uint32 PlusLeft_NoVeh                   : 1;  /*!< no vehicles detected at all -> full HB will be switched on soon    */
    uint32 PlusRight_NoVeh                  : 1;  /*!< no vehicles detected at all -> full HB will be switched on soon    */

    uint32 PlusLeft_SpdAcc                  : 1;  /*!< velocity will fall below activation speed in less than 2 to 3 seconds */
    uint32 PlusRight_SpdAcc                 : 1;  /*!< velocity will fall below activation speed in less than 2 to 3 seconds */

    uint32 PlusLeft_MaybeCity               : 1;  /*!< "maybe" city detected */

    /* 32 Bit alignment */

    uint32 PlusRight_MaybeCity              : 1;  /*!< "maybe" city detected */

    uint32 PlusLeft_minTimeOff              : 1;  /*!< keep partial HB off for a minimum time */
    uint32 PlusRight_minTimeOff             : 1;  /*!< keep partial HB off for a minimum time */

    uint32 PlusLeft_Gap2Large               : 1;  /*!< gap between left and right partial HB is too large */
    uint32 PlusRight_Gap2Large              : 1;  /*!< gap between left and right partial HB is too large */

    uint32 PlusLeft_TimeToDeactOther        : 1;  /*!< keep partial HB off if opposite partial HB will switch off in a certain time */
    uint32 PlusRight_TimeToDeactOther       : 1;  /*!< keep partial HB off if opposite partial HB will switch off in a certain time */

    uint32 PlusLeft_OncCoveredByPrec        : 1;  /*!< oncoming detected on the right side and is now covered by a preceding car -> wait until oncoming car is detected on the left side */
    uint32 PlusRight_OncCoveredByPrec       : 1;  /*!< oncoming detected on the right side and is now covered by a preceding car -> wait until oncoming car is detected on the left side */

    uint32 PlusLeft_OncWillLeaveFOV         : 1;  /*!< oncoming will leave the FOV in the next seconds, do not switch on partial HBs */
    uint32 PlusRight_OncWillLeaveFOV        : 1;  /*!< oncoming will leave the FOV in the next seconds, do not switch on partial HBs */

    uint32 PlusLeft_PotentialOncomingDeact  : 1;  /*!< Potential oncoming vehicle detected (deactivation/ hold region) */
    uint32 PlusRight_PotentialOncomingDeact : 1;  /*!< Potential oncoming vehicle detected (deactivation/ hold region) */

    uint32 PlusLeft_PotentialOncoming       : 1;  /*!< Potential oncoming vehicle detected (deactivation/ activation/ hold region) */
    uint32 PlusRight_PotentialOncoming      : 1;  /*!< Potential oncoming vehicle detected (deactivation/ activation/ hold region) */

    uint32 PlusLeft_Wait4OtherPHB           : 1;  /*!< keep left partial HB off until right part.HB will be switched on */   
    uint32 PlusRight_Wait4OtherPHB          : 1;  /*!< keep left partial HB off until right part.HB will be switched on */   

    uint32 PlusLeft_Sync                    : 1;  /*!< synchronize the partial high beams (left <-> right) */
    uint32 PlusRight_Sync                   : 1;  /*!< synchronize the partial high beams (left <-> right) */

    uint32 PlusLeft_PrecMinTimeInActRegion  : 1;  /*!< preceding car stays for minimal time in activation region */
    uint32 PlusRight_PrecMinTimeInActRegion : 1;  /*!< preceding car stays for minimal time in activation region */

    uint32 PlusLeft_OncMinTimeInActRegion   : 1;  /*!< oncoming car stays for minimal time in activation region */
    uint32 PlusRight_OncMinTimeInActRegion  : 1;  /*!< oncoming car stays for minimal time in activation region */

    uint32 PlusLeft_Unused                  : 1;
    uint32 PlusRight_Unused                 : 1;

    uint32 eState                           : 3;  /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 NextState                        : 3;  /* next state     */
    uint32 Dummy0                           : 1; 
  } HLAFKeepOffReason;
#else
/* HLA_BIG_ENDIAN */
  struct {
    uint32 Dummy0                           : 1; 
    uint32 NextState                        : 3;  /* next state     */
    uint32 eState                           : 3;  /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

    uint32 PlusRight_Unused                 : 1;
    uint32 PlusLeft_Unused                  : 1;

    uint32 PlusRight_OncMinTimeInActRegion  : 1;  /*!< oncoming car stays for minimal time in activation region */
    uint32 PlusLeft_OncMinTimeInActRegion   : 1;  /*!< oncoming car stays for minimal time in activation region */

    uint32 PlusRight_PrecMinTimeInActRegion : 1;  /*!< preceding car stays for minimal time in activation region */
    uint32 PlusLeft_PrecMinTimeInActRegion  : 1;  /*!< preceding car stays for minimal time in activation region */

    uint32 PlusRight_Sync                   : 1;  /*!< synchronize the partial high beams (left <-> right) */
    uint32 PlusLeft_Sync                    : 1;  /*!< synchronize the partial high beams (left <-> right) */

    uint32 PlusRight_Wait4OtherPHB          : 1;  /*!< keep left partial HB off until right part.HB will be switched on */   
    uint32 PlusLeft_Wait4OtherPHB           : 1;  /*!< keep left partial HB off until right part.HB will be switched on */   

    uint32 PlusRight_PotentialOncoming      : 1;  /*!< Potential oncoming vehicle detected (deactivation/ activation/ hold region) */
    uint32 PlusLeft_PotentialOncoming       : 1;  /*!< Potential oncoming vehicle detected (deactivation/ activation/ hold region) */

    uint32 PlusRight_PotentialOncomingDeact : 1;  /*!< Potential oncoming vehicle detected (deactivation/ hold region) */
    uint32 PlusLeft_PotentialOncomingDeact  : 1;  /*!< Potential oncoming vehicle detected (deactivation/ hold region) */

    uint32 PlusRight_OncWillLeaveFOV        : 1;  /*!< oncoming will leave the FOV in the next seconds, do not switch on partial HBs */
    uint32 PlusLeft_OncWillLeaveFOV         : 1;  /*!< oncoming will leave the FOV in the next seconds, do not switch on partial HBs */

    uint32 PlusRight_OncCoveredByPrec       : 1;  /*!< oncoming detected on the right side and is now covered by a preceding car -> wait until oncoming car is detected on the left side */
    uint32 PlusLeft_OncCoveredByPrec        : 1;  /*!< oncoming detected on the right side and is now covered by a preceding car -> wait until oncoming car is detected on the left side */

    uint32 PlusRight_TimeToDeactOther       : 1;  /*!< keep partial HB off if opposite partial HB will switch off in a certain time */
    uint32 PlusLeft_TimeToDeactOther        : 1;  /*!< keep partial HB off if opposite partial HB will switch off in a certain time */

    uint32 PlusRight_Gap2Large              : 1;  /*!< gap between left and right partial HB is too large */
    uint32 PlusLeft_Gap2Large               : 1;  /*!< gap between left and right partial HB is too large */

    uint32 PlusRight_minTimeOff             : 1;  /*!< keep partial HB off for a minimum time */
    uint32 PlusLeft_minTimeOff              : 1;  /*!< keep partial HB off for a minimum time */

    uint32 PlusRight_MaybeCity              : 1;  /*!< "maybe" city detected */


    /* 32 Bit alignment */

    /* HLA Plus partial HB keep off reason */
    uint32 PlusLeft_MaybeCity               : 1;  /*!< "maybe" city detected */

    uint32 PlusRight_SpdAcc                 : 1;  /*!< velocity will fall below activation speed in less than 2 to 3 seconds */
    uint32 PlusLeft_SpdAcc                  : 1;  /*!< velocity will fall below activation speed in less than 2 to 3 seconds */

    uint32 PlusRight_NoVeh                  : 1;  /*!< no vehicles detected at all -> full HB will be switched on soon    */
    uint32 PlusLeft_NoVeh                   : 1;  /*!< no vehicles detected at all -> full HB will be switched on soon    */

    uint32 PlusRight_SyncSinglePrecCar      : 1;  /*!<  synchronously partial HB on when only 1 or 2 preceding lights detected */
    uint32 PlusLeft_SyncSinglePrecCar       : 1;  /*!< synchronously partial HB on when only 1 or 2 preceding lights detected  */

    uint32 PlusRight_OutermostLost          : 1;  /*!< outermost vehicle lost -> keep HB off */
    uint32 PlusLeft_OutermostLost           : 1;  /*!< outermost vehicle lost -> keep HB off */

    uint32 PlusRight_NoOncoming             : 1;  /*!< keep off HB until no oncoming traffic is detected anymore */
    uint32 PlusLeft_NoOncoming              : 1;  /*!< keep off HB until no oncoming traffic is detected anymore */

    uint32 PlusRight_NoOncomingMinTime      : 1;  /*!< after last oncoming vehicle passed keep partial HB off for a minimal time */    
    uint32 PlusLeft_NoOncomingMinTime       : 1;  /*!< after last oncoming vehicle passed keep partial HB off for a minimal time */

    uint32 PlusRight_TimeToBorder           : 1;  /*!< Object in DEACT is lost */      
    uint32 PlusLeft_TimeToBorder            : 1;  /*!< Object in DEACT is lost */   

    uint32 PlusRight_TimeToDeact            : 1;  /*!< Object is moving from ACT/HOLD to DEACT soon */
    uint32 PlusLeft_TimeToDeact             : 1;  /*!< Object is moving from ACT/HOLD to DEACT soon */

    /* HLA Plus full HB keep off reason */
    uint32 Plus_Unused                      : 2;
    uint32 Plus_minTimePartOn               : 1;  /*!< minimum time partial HB on before switching to full HB */   
    uint32 Plus_minTimeOff                  : 1;  /*!< minimum time low beam on before switching to full HB   */
    uint32 Plus_HB_Off                      : 1;  /*!< HB off from old decision */

    /* HLA Standard keep off reason*/
    uint32 Std_Unused                       : 3;
    uint32 Std_PotVeh                       : 1;  /*!< potential vehcile   */
    uint32 Std_MaybeCity                    : 1;  /*!< may be city detected keep full HB off because city will be detected in same frames */
    uint32 Std_PrecedingVehLost             : 1;  /*!< preceding vehicle lost in curve -> keep HB off until we reached the position and we are at the end of the curve */
    uint32 Std_TurnOnDelay                  : 1;  /*!< turn on delay */
    uint32 Std_MinTimeHBOff                 : 1;  /*!< keep HB off for a minimal time */
    uint32 Std_SmallRadius                  : 1;  /*!< small radius */
    uint32 Std_SpdAcc                       : 1;  /*!< velocity will fall below activation speed in less than 2.5 seconds */
  } HLAFKeepOffReason;
#endif


/**************************/
/* HLA_DDM_STATE__HLA_VERSION */
/* state = 4              */
/**************************/
#ifdef HLA_LITTLE_ENDIAN
struct {
  uint32 HLAVersion       : 24; /*!< HLA version number: 3 Bytes BCD coded: 1 Byte Mainversion, 1Byte Subversion, 1Byte Bugfixlevel */ 

  uint32 Dummy3           : 8;
  /* 32 Bit */

  uint32 Dummy2           : 16;

  uint32 FrameCnt         : 4; /* lower 4 Bits of (FrameCnt/2) */

  uint32 Dummy1           : 2; /* due to 4 bit alignment */

  uint32 RedReflectorArea : 1; /*!< 0: no red reflector area, 1: red reflector area */

  uint32 SamplingAborted  : 1; /*!< 0: no sampling aborted, 1: sampling aborted */

  uint32 FrameDrop        : 1;  /*!< 0: no frame drop, 1: one or more HLA frames droped */  

  uint32 eState            : 3;  /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

  uint32 NextState        : 3;  /* next state     */
  uint32 Dummy0           : 1; 
} HLAVersion;
#else 
/* HLA_BIG_ENDIAN */
struct {
  uint32 Dummy0           : 1; 
  uint32 NextState        : 3;  /* next state     */
  uint32 eState           : 3;  /*!< 0: HB on, 1: initial HLAR turn off reason, 2: HLAF turn off reason, 3: HLAF keep off reason, 4-7: Brunn */

  uint32 FrameDrop        : 1;  /*!< 0: no frame drop, 1: one or more HLA frames droped */  
  uint32 SamplingAborted  : 1; /*!< 0: no sampling aborted, 1: sampling aborted */
  uint32 RedReflectorArea : 1; /*!< 0: no red reflector area, 1: red reflector area */
  uint32 Dummy1           : 2; /* due to 4 bit alignment */
  uint32 FrameCnt         : 4; /* lower 4 Bits of (FrameCnt/2) */
  uint32 Dummy2           : 16;

  /* 32 Bit alignment */

  uint32 Dummy3           : 8;
  uint32 HLAVersion       : 24; /*!< HLA version number: 3 Bytes BCD coded: 1 Byte Mainversion, 1Byte Subversion, 1Byte Bugfixlevel */ 
} HLAVersion;
#endif 

} HLA_t_DiagnosisDebugMsg;


/*****************************************************************************
  FUNCTION 
*****************************************************************************/

#endif /* #ifndef HLA_TYPE_INCLUDED */
