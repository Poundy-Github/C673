/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_veh_cfg.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_veh_cfg.h  $
  CHANGES:                   Revision 1.1 2019/03/24 17:36:40CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:28CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.1 2019/01/31 18:56:07CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/FRAME_VEH/project.pj
  CHANGES:                   Revision 1.8 2018/03/27 12:49:45CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in wrappers for Sprint08
  CHANGES:                   Revision 1.7 2018/02/02 08:43:07CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   MFC431 R8.0 - bugfix2 - round2
  CHANGES:                   Revision 1.6 2018/01/15 15:22:16CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial quick merge with latest wrappers from R7.1
  CHANGES:                   Revision 1.5 2017/12/22 10:02:18CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   R8.0 update
  CHANGES:                   Revision 1.4 2017/11/01 12:08:09CET Grosu, George (uidl9584) 
  CHANGES:                   Compilable version of maual code
  CHANGES:                   Revision 1.2.1.6.2.1 2017/08/30 10:39:41CEST Grosu, George (uidl9584) 
  CHANGES:                   Bugfix
  CHANGES:                   Revision 1.2.1.6 2017/08/09 15:45:33CEST Grosu, George (uidl9584) 
  CHANGES:                   Merge with MFC431HI28
  CHANGES:                   Revision 1.2.1.5 2017/08/02 15:42:56CEST Grosu, George (uidl9584) 
  CHANGES:                   INT-13
  CHANGES:                   Revision 1.2.1.4 2017/07/24 08:56:40CEST Grosu, George (uidl9584) 
  CHANGES:                   New CP
  CHANGES:                   Revision 1.2.1.3 2017/07/14 09:38:49CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for TJA RTE
  CHANGES:                   Revision 1.2.1.2 2017/07/13 17:59:33CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for TJA RTE
  CHANGES:                   Revision 1.2.1.1 2017/06/30 16:07:23CEST Grosu, George (uidl9584) 
  CHANGES:                   Update components
  CHANGES:                   Revision 1.2 2017/05/08 13:07:46CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Move LCF_VEH (LaDMC) in 10ms task.
  CHANGES:                   Revision 1.1 2016/11/25 12:49:25CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Common includes cleanup.
  CHANGES:                   Revision 1.0 2016/07/01 06:45:27CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/algo/00_Custom/frame_veh/project.pj
 
**************************************************************************** */
#ifndef lcf_veh_cfg_h__
#define lcf_veh_cfg_h__


/**
@defgroup lcf_custom_cfg lcf custom configuration
  @ingroup lcf
    Custom configuration of lcf
@{ */

#include "lcf_dpu_cfg.h"


/*****************************************************************************
  Config:   
*****************************************************************************/
#define LCF_VEH_WRP_RUNTIME_PROFILING         (SWITCH_ON)    /*!< enable runtime profiling for LCF_VEH wrapper */

#endif // lcf_veh_cfg_h__
/** @} end defgroup: this sould be the last line in your external header*/ 

