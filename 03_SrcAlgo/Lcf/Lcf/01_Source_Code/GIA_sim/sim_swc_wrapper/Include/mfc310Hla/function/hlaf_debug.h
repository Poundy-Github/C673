/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI DSP C674x

  COMPONENT:              HLA

  MODULNAME:              hlaf_debug.h

  DESCRIPTION:            Definition for debugging and evaluation

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-02-28

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_debug.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:02CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:38:45CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:33CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.6 2014/03/25 18:42:30CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_debug.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_debug.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/project.pj.
  CHANGES:                Revision 1.5 2014/03/05 11:05:28CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed build errors from previous check-in
  CHANGES:                --- Added comments ---  uidv7867 [Mar 5, 2014 11:05:28 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.4 2014/03/04 16:52:18CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed QAC warnings
  CHANGES:                Coding style
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:18 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.3 2014/01/10 18:33:36CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:36 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.2 2014/01/08 17:10:27CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Refactored HLA_Exec() function
  CHANGES:                Replaced uint64 time stamps by uint32 ones
  CHANGES:                Smaller bug fixes
  CHANGES:                Revision 1.1 2013/03/04 11:48:33CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:
  CHANGES:
**************************************************************************** */

#ifndef HLAF_DEBUG_INCLUDED
#define HLAF_DEBUG_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLAF_DEBUG_INTERFACE_VERSION_NUMBER_MAIN    1
#define HLAF_DEBUG_INTERFACE_VERSION_NUMBER_SUB     0
#define HLAF_DEBUG_INTERFACE_VERSION_NUMBER_BUGFIX  0
#define HLAF_DEBUG_INTERFACE_VERSION_NUMBER (  (HLA_INTERFACE_VERSION_NUMBER_ENDIAN      << 24) \
                                             | (HLAF_DEBUG_INTERFACE_VERSION_NUMBER_MAIN << 16) \
                                             | (HLAF_DEBUG_INTERFACE_VERSION_NUMBER_SUB  << 8)  \
                                             | (HLAF_DEBUG_INTERFACE_VERSION_NUMBER_BUGFIX)     \
                                             )

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/* output structure for Measfreeze */
typedef struct 
{
  uint32        dTimeInit_us;
  uint32        dTimeExec_us;
  uint32        dTimeDecision_us;
  uint32        dTimeLight_us;
  uint32        dTimeStandard_us;
  uint32        dTimePlus_us;
  uint32        dTimeMatrix_us;
  uint32        dTimeSpot_us;
  uint32        dTime08_us;
  uint32        dTime09_us;
  uint32        dTime10_us;
  uint32        dTime11_us;
  uint32        dTime12_us;
  uint32        dTime13_us;
  uint32        dTime14_us;
  uint32        dTime15_us;
} HLAF_TimeMeasurement_t;

/* output structure for debug data */
typedef struct
{
  uint32                  ui32_InterfaceVersionNumber;/*!< HLAF output interface version number */
  uint32                  ui32_HLA_SWVersionNumber;   /*!< HLA Software version number */
  uint32                  ui32_HLAF_SWVersionNumber;  /*!< HLAF Software version number */
  AlgoCycleCounter_t      uiFrameCnt;                 /*!< Frame counter */
  AlgoCycleCounter_t      uiHLAF_Cnt;                 /*!< HLAF counter  */
  AlgoDataTimeStamp_t     uiTimeStamp_HLA_us;         /*!< [us] HLA Timestamp, hla input data */
  AlgoDataTimeStamp_t     uiTimeStamp_Image_us;       /*!< [us] Image Timestamp */
  HLAF_TimeMeasurement_t  timeMeas;
} HLAF_DebugOutputs_t;


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/

#endif /* #ifndef HLAF_DEBUG_INCLUDED */

