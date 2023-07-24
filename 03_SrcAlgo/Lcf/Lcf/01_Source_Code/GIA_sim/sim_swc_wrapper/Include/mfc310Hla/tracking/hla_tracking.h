/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                CSF200

  CPU:                    Pentium

  COMPONENT:              HLA

  MODULNAME:              HLATracking.h

  DESCRIPTION:            definition of tracking functions.

  @brief                  definition of tracking functions.

  @author                 Stefan Heinrich

  CREATION DATE:          07.11.2006

  VERSION:                $Revision: 1.1 $

  CHANGES:                
  ---*/ /*---
  CHANGE:                 $Log: hla_tracking.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:09CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:50CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:10CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.7 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_tracking.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_tracking.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.6 2014/02/06 16:01:31CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:31 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.5 2014/01/24 15:23:29CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 3:23:29 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.4 2014/01/10 18:34:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:34:03 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.3 2013/12/18 15:18:06CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 introduction of new HighwayOncomingTruckLight detection
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:06 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.2 2013/12/13 16:44:58CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:58 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.1 2013/08/05 17:01:58CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 Revision 1.72.1.62 2013/08/02 15:25:57CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 2, 2013 3:25:58 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGE:                 Revision 1.72.1.61 2013/04/12 12:45:25CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:26 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.72.1.60 2013/03/11 14:32:53CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:32:54 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_TRACKING_INCLUDED
#define HLA_TRACKING_INCLUDED

/* includes */
#include "hla_trackslam.h"
#include "hla_trackpair.h"
#include "hla_hotpixels.h"

#define HLA_TRACKING_REMOVE_BORN_DEAD_TRACKS        0
#define HLA_TRACKING_REMOVE_NORMAL_DEAD_TRACKS      1


/*! Type definition for egomotion data */
typedef struct
{
  /* pre-computed data */
  HLATracking3DDataPreComputed_t      dataPreComputed;

  /* pre-calculated rotations matrix and vectors */
  HLATracking3DDataRotations_t        dataRotations;

  /* track list memory and association table */
  HLATracking3DDataTracks_t           dataTracks;

  /* cross-correlations in Cali algo */
  HLATracking3DDataCrossCorr_t        dataCrossCorr;

  /* data for target vehicles */
  HLATracking3DDataPairs_t   dataPairs;

} HLATracking3DData_t;

/*!type definition for tracking 3D Input */
typedef struct 
{
  const HLA_t_MotionState*  pMotionData;
  const HLACameraData_t*    pCamData;
  HLASegOut_t*              pSegOut;
  HLAHotPixelsData_t*       pDataHotPixels;
  RTE_HLAR_BrightnessState  eBrightnessState;
}HLATracking3DInput_t;

/* init function */
void HLATracking3DInit(       HLATracking3DOutput_t*          pOutput,
                              HLATracking3DData_t*            pData,
                        const HLA_t_FocalLength*              ps_FocalLength,
                        const HLA_t_LensCenter*               ps_LensCenter,
                        const HLA_t_SensorSocket*             ps_SensorSocket,
                        const HLA_t_Tracking3DParameters*     pParam,
                        const CPAR_HLAR_Parameter_t*          pCPar_Hlar
                       );

/* run function */
void HLATracking3D(       HLATracking3DOutput_t*      pOutput,
                          HLADebugOutputs_t*          phlaDebugOutputs,
                          HLATracking3DData_t*        pData,
                    const HLATracking3DInput_t*       pInput,
                    const HLA_t_Tracking3DParameters* pParam,
                    const CPAR_HLAR_Parameter_t*      pCpar_Hlar,
                    const RTE_HLA_TrafficStyle        eTrafficStyle,
                    const AS_t_GetTimestampuS32       pfGetTimestampuS32
                   );


/* avoid cyclic binding ---------------------------------------------------*/
#endif



