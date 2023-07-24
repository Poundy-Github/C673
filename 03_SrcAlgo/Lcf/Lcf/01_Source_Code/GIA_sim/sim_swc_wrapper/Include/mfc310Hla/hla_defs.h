/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_defs.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2010-09-30

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_defs.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:32CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:43CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:07CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGES:                Revision 1.53 2014/03/22 10:28:28CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added project specific defines
  CHANGES:                Replaced defines for CORE by predefined ones
  CHANGES:                --- Added comments ---  uidv7867 [Mar 22, 2014 10:28:29 AM CET]
  CHANGES:                Change Package : 207432:40 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.52 2014/03/19 16:31:07CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGES:                Fixed hlar input adapter for old recordings (headlamp type)
  CHANGES:                Clean-up of no longer needed files in simulation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:07 PM CET]
  CHANGES:                Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGES:                Revision 1.51 2014/03/12 18:07:37CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:38 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.50 2014/03/11 15:43:45CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Took cfg_project.h into use
  CHANGES:                --- Added comments ---  uidv7867 [Mar 11, 2014 3:43:45 PM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.49 2014/03/04 16:51:59CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed QAC warnings
  CHANGES:                Coding style
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:00 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.48 2014/03/03 16:51:41CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for R2.1 interface
  CHANGES:                --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:42 PM CET]
  CHANGES:                Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.47 2014/02/28 15:04:53CET Brunn, Marcus (brunnm) 
  CHANGES:                - improved light filtering
  CHANGES:                - preparation of light list for new rte interface i390
  CHANGES:                --- Added comments ---  brunnm [Feb 28, 2014 3:04:53 PM CET]
  CHANGES:                Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGES:                Revision 1.46 2014/02/05 15:26:52CET Brunn, Marcus (brunnm) 
  CHANGES:                removed LED segmentation
  CHANGES:                --- Added comments ---  brunnm [Feb 5, 2014 3:26:52 PM CET]
  CHANGES:                Change Package : 217024:1 http://mks-psad:7002/im/viewissue?selection=217024
  CHANGES:                Revision 1.45 2014/01/24 09:33:35CET Glebov, Roman (uidg4759) 
  CHANGES:                new HLA_F32_IS.* macros for comparing with 0, which use HLA_F32_DELTA which is much
  CHANGES:                smaller then the C_F32_DELTA from global_defs.h.
  CHANGES:                --- Added comments ---  uidg4759 [Jan 24, 2014 9:33:36 AM CET]
  CHANGES:                Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.44 2014/01/10 18:33:52CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:52 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.43 2014/01/07 09:32:24CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Moved PC specific pragmas behind PC_SIM flag
  CHANGES:                --- Added comments ---  uidv7867 [Jan 7, 2014 9:32:24 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.42 2013/12/17 17:32:40CET Glebov, Roman (uidg4759) 
  CHANGES:                QAC Changes + Documentation of Chain of Light + fix of devision by 0 + small efficiency tweaks
  CHANGES:                --- Added comments ---  uidg4759 [Dec 17, 2013 5:32:40 PM CET]
  CHANGES:                Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGES:                Revision 1.41 2013/12/13 16:45:12CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Service functions are now passed in one struct
  CHANGES:                SDLfile definitions moved to separate file
  CHANGES:                --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:12 PM CET]
  CHANGES:                Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.40 2013/12/11 08:59:41CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Error checks:
  CHANGES:                - Frame count comparison between image and IC
  CHANGES:                - Lens center, focal length, etc. (merge from I320 branch)
  CHANGES:                Enabled internal measfreezes again
  CHANGES:                Reviewed by AlexF
  CHANGES:                --- Added comments ---  uidv7867 [Dec 11, 2013 8:59:41 AM CET]
  CHANGES:                Change Package : 207432:2 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.39 2013/12/05 17:48:00CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Update to RTE I330
  CHANGES:                --- Added comments ---  uidv7867 [Dec 5, 2013 5:48:01 PM CET]
  CHANGES:                Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.38 2013/11/21 17:53:56CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge from NEW_SEG branch
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:56 PM CET]
  CHANGES:                Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.37 2013/10/16 14:59:19CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated eve code for support for lrf
  CHANGES:                --- Added comments ---  uidv7867 [Oct 16, 2013 2:59:20 PM CEST]
  CHANGES:                Change Package : 198642:2 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.36.1.7 2013/11/21 13:37:38CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved Icon normalize
  CHANGES:                Bug fixes in segmentation
  CHANGES:                Removed no longer compiler switches
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:38 PM CET]
  CHANGES:                Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.36.1.6 2013/11/12 13:44:46CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed SegOut from function arguments
  CHANGES:                --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:46 PM CET]
  CHANGES:                Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.36.1.5 2013/11/05 12:04:52CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added a few more RTA events
  CHANGES:                --- Added comments ---  uidv7867 [Nov 5, 2013 12:04:52 PM CET]
  CHANGES:                Change Package : 201787:8 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.36.1.4 2013/10/29 18:21:27CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Time meas fixes
  CHANGES:                New roi calculation (alignment to eve)
  CHANGES:                Call EVE in segmentation now
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:27 PM CET]
  CHANGES:                Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.36.1.3 2013/10/22 12:21:45CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge 1.37 to branch
  CHANGES:                --- Added comments ---  uidv7867 [Oct 22, 2013 12:21:45 PM CEST]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.36.1.2 2013/10/21 16:00:27CEST Brunn, Marcus (brunnm) 
  CHANGES:                introduced preprocessing function: HLASegPreProcImage()
  CHANGES:                --- Added comments ---  brunnm [Oct 21, 2013 4:00:27 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.36.1.1 2013/10/18 13:27:53CEST Brunn, Marcus (brunnm) 
  CHANGES:                intial version of new segmentation
  CHANGES:                --- Added comments ---  brunnm [Oct 18, 2013 1:27:54 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Disabled almost all internal measfreezes temporary due 15K budget
  CHANGES:                --- Added comments ---  uidv7867 [Aug 29, 2013 12:39:39 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.34 2013/08/05 20:41:28CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:28 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.33 2013/02/20 16:17:51CET Brunn, Marcus (brunnm) 
  CHANGES:                removed "glob_comp_id.h"
  CHANGES:                --- Added comments ---  brunnm [Feb 20, 2013 4:17:52 PM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.32 2013/02/19 07:45:29CET Brunn, Marcus (brunnm) 
  CHANGES:                fixed measfreezes from DSP (little endian)
  CHANGES:                - added endianness to Interface version number
  CHANGES:                --- Added comments ---  brunnm [Feb 19, 2013 7:45:30 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.31 2013/02/07 14:59:10CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Took glob_comp_id.h in use
  CHANGES:                --- Added comments ---  uidv7867 [Feb 7, 2013 2:59:10 PM CET]
  CHANGES:                Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.30 2013/01/30 10:51:32CET Brunn, Marcus (brunnm) 
  CHANGES:                renamed Highway variables:
  CHANGES:                - RdwayType -> LatPos
  CHANGES:                - HwayDction -> EgoMotion
  CHANGES:                --- Added comments ---  brunnm [Jan 30, 2013 10:51:33 AM CET]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.29 2013/01/21 13:35:38CET Brunn, Marcus (brunnm) 
  CHANGES:                added missing define HLA_USE_CORE1
**************************************************************************** */

/* ~CodeReview ~ID:9e10a83b4223a03c8e687b93aeb89f94 ~Reviewer:CW01\uidv0772 ~Date:19.07.2012 
   ~Priority:3 ~Comment:(general) signedness does not match, use postfix u for unsigned defines */
/* ~CodeReview ~ID:fb824ce874ab395b00181a2fc3e0a2f6 ~Reviewer:CW01\uidt9253 ~Date:7/13/2012 
   ~Priority:3 ~Comment:Only module global definitions should be placed in this file. I.e. Analysis definitions can be moved to analysis */

#ifndef HLA_DEFS_INCLUDED
#define HLA_DEFS_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "glob_comp_id.h"
#include "cml_ext.h"
#include "hla_project_defs.h"



/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/**********************************/
/* MEASFREEZE:                    */
/**********************************/
/* Virtual addresses for internal measfreezes */
#define HLA_MEAS_VADDR_HLAR_IN                         0x31220000
#define HLA_MEAS_VADDR_HLAF_IN                         0x31222000
#define HLA_MEAS_VADDR_HLAR_OUT                        0x31225000
#define HLA_MEAS_VADDR_HLAF_OUT                        0x31227000

#define HLA_MEAS_VADDR_SYSTEM_INFO                     0x31230000
#define HLA_MEAS_VADDR_IMAGER_PARAMETERS               0x31231000
#define HLA_MEAS_VADDR_CAM_DATA                        0x31232000
#define HLA_MEAS_VADDR_ODOMETER                        0x31233000
#define HLA_MEAS_VADDR_HLA_DEBUG_OUT                   0x31234000

#define HLA_MEAS_VADDR_SEG_IN                          0x31240000
#define HLA_MEAS_VADDR_SEG_DATA                        0x31240100
#define HLA_MEAS_VADDR_SEG_OUT                         0x31240300
#define HLA_MEAS_VADDR_SEG_LINE_BUFFER                 0x31241000
#define HLA_MEAS_VADDR_SEG_REGION_BUFFER               0x31244000
#define HLA_MEAS_VADDR_SEG_LIGHT_BUFFER                0x31247000

#define HLA_MEAS_VADDR_TRACK_OUT                       0x31250000
#define HLA_MEAS_VADDR_TRACK_PRE_COMPUTED              0x31251000
#define HLA_MEAS_VADDR_DEBUG_ICON_LIST                 0x31252000
#define HLA_MEAS_VADDR_HIGHWAY_OUT                     0x31255000
#define HLA_MEAS_VADDR_CITY_DATA                       0x31256000
#define HLA_MEAS_VADDR_TUNNEL_OUT                      0x31257000

#define HLA_MEAS_VADDR_HLAF_DATA                       0x31260000
#define HLA_MEAS_VADDR_HLAF_DEBUG_OUT                  0x31261000
#define HLA_MEAS_VADDR_HLAF_PARAMETER                  0x31262000
#define HLA_MEAS_VADDR_HLAF_MATRIX_PARAMETER           0x31263000
#define HLA_MEAS_VADDR_HLAF_MATRIX_INPUT               0x31264000
#define HLA_MEAS_VADDR_HLAF_MATRIX_DATA                0x31265000
#define HLA_MEAS_VADDR_HLAF_PLUS_PARAMETER             0x31266000
#define HLA_MEAS_VADDR_HLAF_PLUS_INPUT                 0x31267000
#define HLA_MEAS_VADDR_HLAF_PLUS_DATA                  0x31268000
#define HLA_MEAS_VADDR_HLAF_STANDARD_DATA              0x3126A000
#define HLA_MEAS_VADDR_HLAF_LIGHT                      0x3126B000

/**********************************/
/* RTA events                     */
/**********************************/
/* To interpret those RTA events      please keep
 * 05_Testing\06_Test_Tools\mts\mts_measurement\cfg\algo\hla\RTA_ID_HLA.xml
 * up-to-date.
 */
#define HLA_RTA_RUNTIME_EXEC          0u
#define HLA_RTA_RUNTIME_HLAR          1u
#define HLA_RTA_RUNTIME_SEGMENTATION  2u
#define HLA_RTA_RUNTIME_TRACKING      3u
#define HLA_RTA_RUNTIME_ANALYSIS      4u
#define HLA_RTA_RUNTIME_HIGHWAY       5u
#define HLA_RTA_RUNTIME_CITY          6u
#define HLA_RTA_RUNTIME_TRAFFIC_STYLE 7u
#define HLA_RTA_RUNTIME_TUNNEL        8u
#define HLA_RTA_RUNTIME_HLAF          9u

/**********************************/
/* Segmentation                   */
/**********************************/
#define HLA_SEG_LEVEL_LIGHT               (RTE_HLA_SEG_MAX_NUM_LEVELS - 2u) /* 6..0 */

#define HLA_SEG_NGB_OFFSET_R_X 3
#define HLA_SEG_NGB_OFFSET_R_Y 4
#define HLA_SEG_NGB_OFFSET_GR_X 4 /* green pixel on red row  */
#define HLA_SEG_NGB_OFFSET_GR_Y 4 /* green pixel on red row  */
#define HLA_SEG_NGB_OFFSET_GB_X 3 /* green pixel on blue row */
#define HLA_SEG_NGB_OFFSET_GB_Y 3 /* green pixel on blue row */
#define HLA_SEG_NGB_OFFSET_B_X 4
#define HLA_SEG_NGB_OFFSET_B_Y 3

/* conversion from new 64_NGB to former 13_NGB */
#define NGB_0  19 
#define NGB_1  26
#define NGB_2  27
#define NGB_3  28
#define NGB_4  33
#define NGB_5  34
#define NGB_6  35
#define NGB_7  36
#define NGB_8  37
#define NGB_9  42
#define NGB_10 43
#define NGB_11 44
#define NGB_12 51


/**********************************/
/* Hla Turn Off Reason (TOR)      */
/* for oncoming and ahead traffic */
/**********************************/
#define HLA_TOR__MAX_CNT  32 /* maximal counter for the turn off reason storage */

/**********************************/
/* oncoming traffic               */
/**********************************/
#define HLA_TOR__ONCOM_BIT_MASK                   0x0000FFFFu
#define HLA_TOR__AHEAD_BIT_MASK                   0xFFFF0000u


#define HLA_TOR__ONCOM__TOO_BRIGHT                0x00000001 /* bit  0 */
#define HLA_TOR__ONCOM__CONTRA_MOTION_WHITE       0x00000002 /* bit  1 */
#define HLA_TOR__ONCOM__ONCOMING_PAIR             0x00000004 /* bit  2 */
#define HLA_TOR__ONCOM__CENTER_BRIGHT             0x00000008 /* bit  3 */
#define HLA_TOR__ONCOM__EXTREME_BRIGHT            0x00000010 /* bit  4 */
#define HLA_TOR__ONCOM__LATERAL_BRIGHT            0x00000020 /* bit  5 */
#define HLA_TOR__ONCOM__BIT_06                    0x00000040 /* bit  6 */
#define HLA_TOR__ONCOM__BIT_07                    0x00000080 /* bit  7 */          
#define HLA_TOR__ONCOM__BIT_08                    0x00000100 /* bit  8 */          
#define HLA_TOR__ONCOM__BIT_09                    0x00000200 /* bit  9 */         
#define HLA_TOR__ONCOM__BIT_10                    0x00000400 /* bit 10 */         
#define HLA_TOR__ONCOM__BIT_11                    0x00000800 /* bit 11 */         
#define HLA_TOR__ONCOM__BIT_12                    0x00001000 /* bit 12 */
#define HLA_TOR__ONCOM__HIGHWAYONCOMINGCAR        0x00002000 /* bit 13 */
#define HLA_TOR__ONCOM__SUDDENLYAPPEARINGVEHICLE  0x00004000 /* bit 14 */         
#define HLA_TOR__ONCOM__CLASSRESULTREACHED        0x00008000 /* bit 15 */         

#define HLA_TOR__AHEAD__RED_LIGHT                 0x00010000 /* bit 16 */         
#define HLA_TOR__AHEAD__RED_LIGHT2                0x00020000 /* bit 17 */         
#define HLA_TOR__AHEAD__PULSED_LIGHT              0x00040000 /* bit 18 */         
#define HLA_TOR__AHEAD__CONTRA_MOTION_NONWHITE    0x00080000 /* bit 19 */         
#define HLA_TOR__AHEAD__BIT_20                    0x00100000 /* bit 20 */         
#define HLA_TOR__AHEAD__BIT_21                    0x00200000 /* bit 21 */         
#define HLA_TOR__AHEAD__BIT_22                    0x00400000 /* bit 22 */         
#define HLA_TOR__AHEAD__BIT_23                    0x00800000 /* bit 23 */         
#define HLA_TOR__AHEAD__BIT_24                    0x01000000 /* bit 24 */         
#define HLA_TOR__AHEAD__BIT_25                    0x02000000 /* bit 25 */         
#define HLA_TOR__AHEAD__OVERTAKER                 0x04000000 /* bit 26 */         
#define HLA_TOR__AHEAD__DRIVEDISTREACHED          0x08000000 /* bit 27 */         
#define HLA_TOR__AHEAD__DRIVEDISTDYNAMICREACHED   0x10000000 /* bit 28 */         
#define HLA_TOR__AHEAD__DRIVEDISTPAIRREACHED      0x20000000 /* bit 29 */         
#define HLA_TOR__AHEAD__SUDDENLYAPPEARINGVEHICLE  0x40000000 /* bit 30 */         
#define HLA_TOR__AHEAD__CLASSRESULTREACHED        0x80000000u/* bit 31 */         


/*! @ maximal uint32 value to check for overflow */
#define UI32_T_MAX  (4294967295u)
/*! @ minimal sint32 value to check for overflow */
#define SI32_T_MIN  (-2147483648)
/*! @ maximal sint32 value to check for overflow */
#define SI32_T_MAX  (2147483647)
/*! @ maximal uint16 value to check for overflow */
#define UI16_T_MAX  (65535u)  
/*! @ minimal sint16 value to check for overflow */
#define SI16_T_MIN  (-32768)
/*! @ maximal sint16 value to check for overflow */
#define SI16_T_MAX  (32767)
/*! @ maximal 12 bit value to check for overflow */
#define UI12_T_MAX   (4095u)
/*! @ maximal uint8 value to check for overflow */
#define UI8_T_MAX   (255u)
/*! @ minimal sint8 value to check for overflow */
#define SI8_T_MIN  (-128)
/*! @ maximal sint8 value to check for overflow */
#define SI8_T_MAX  (127)

/* chi2 values */
#define HLA_CHI2_VALUE_N1    8.9999f
#define HLA_CHI2_VALUE_N2    11.8291f
#define HLA_CHI2_VALUE_N3    14.1564f
#define HLA_CHI2_VALUE_N4    16.2513f
#define HLA_CHI2_VALUE_N6    20.0620f

/* max floating point value */
#define HLA_FLT_MAX         3.402823466e+38F
#define HLA_FLT_MAX_LOG     88.722835f

/*****************************************************************************
  MACROS 
*****************************************************************************/
#define MAX_DFRAME 10
#define MAX_FRAMENUMBER 255

#ifndef INLINE
#define INLINE __inline
#endif  

#define HLA_ENABLE_INTERNAL_MEASFREEZES

#if defined(PC_SIM) || defined(EVAL_BOARD)
/* only DLL for visualization/ evaluation purpose */
#define HLA_GLOBAL_STATIC
#define ICON_MEASFREEZE
#else
#define HLA_GLOBAL_STATIC static
#endif

#ifdef _TMS320C6X
#define HLA_SEGMENTATION_ON_EVE
#define HLA_LRF_ON_EVE
#endif

#ifdef PC_SIM
/* solves QAC critical messages about side effects of this function in conditional expressions 
   See M2CM Rule 12.4, 3415. C:\tools\QAC\m2cm\messages\3415.html */

#pragma warning(push)

/* disabling unknown pragma warning of VC++ Compiler */
#pragma  warning( disable : 4068 )
#pragma PRQA_NO_SIDE_EFFECTS fabsf
#pragma PRQA_NO_SIDE_EFFECTS sqrtf

#pragma warning(pop)

#ifndef restrict
#define restrict
#endif

#endif

#define HLA_DSP_CACHE_LINE_SIZE 128

#define HLA_COMPILE_TIME_ASSERT( x ) \
  switch ( x ) \
  { \
  case b_TRUE: \
    break; \
  case ( x ): \
    break; \
  }

#define HLA_SIZE_MATCHES_DSP_CACHE_SIZE(type) HLA_COMPILE_TIME_ASSERT((sizeof(type) % HLA_DSP_CACHE_LINE_SIZE) != 0)

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/

#endif /* #ifndef HLA_DEFS_INCLUDED */
