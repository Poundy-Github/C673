/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                CSF200

  CPU:                    M32R

  COMPONENT:              HLA

  MODULNAME:              hla_camera.c

  DESCRIPTION:            Camera functions  

  AUTHOR:                 Stefan Heinrich

  CREATION DATE:          11.09.2007

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_camera.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:51CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:27CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:23CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/camera/project.pj
  CHANGE:                 Revision 1.5 2014/03/25 18:35:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_camera.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_camera.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/camera/project.pj.
  CHANGE:                 Revision 1.4 2014/02/07 16:33:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed dframe calculation
  CHANGE:                 Updated time meas inside segmentation
  CHANGE:                 Updated HIL according to latest changes
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 4:33:04 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.3 2014/02/06 16:02:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 Revision 1.2 2013/11/21 17:53:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:57 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.1.1.1 2013/10/18 13:27:34CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:34 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.1 2013/08/05 17:01:54CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 Revision 1.16.1.21 2013/03/04 11:15:11CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:15:11 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_CAMERA_INCLUDED
#define HLA_CAMERA_INCLUDED

/* includes */
#include "hlar_ext.h"
#include "hla_base.h"
#include "hla_cam_rot.h"


/*! Updates the ROI. */
void HLARUpdateRoi( const HLAR_t_RequiredInputs *ps_In,
                    HLACameraData_t             *pCamData,
                    const HLACamRot             *pCamRot,
                    HLA_t_SystemInfo            *ps_SystemInfo
                  );

void HLAUpdateCamera( const HLAR_t_RequiredInputs*   pReqIn,
                      const HLATracking3DDataCali_t* pDataCali,
                      const boolean                  forceCameraUpdate,
                      const sint16                   dFrameCnt,
                            HLACameraData_t*         pCamData,
                            HLACamRot*               pCamRot
                    );

/*! initializes global variables of camera */
void HLAInitCamera(                      
                   HLACameraData_t               *pCamData,
                   HLACamRot                     *pCamRot
                   );


/* avoid cyclic binding ---------------------------------------------------*/
#endif


