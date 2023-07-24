/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_sen_cfg.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_sen_cfg.h  $
  CHANGES:                   Revision 1.1 2019/03/24 17:36:10CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:25CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.1 2019/01/31 18:56:04CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/FRAME_SEN/project.pj
  CHANGES:                   Revision 1.10 2018/03/27 12:38:34CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in wrappers for Sprint08
  CHANGES:                   Revision 1.9 2018/03/02 08:35:48CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   issue 782615: LCF standard type variables to be moved to the FAR memory section
  CHANGES:                   Revision 1.8 2018/01/15 15:22:14CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial quick merge with latest wrappers from R7.1
  CHANGES:                   Revision 1.7 2017/12/05 09:36:20CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   switched to any boundary interface
  CHANGES:                   Revision 1.6 2017/11/24 18:32:04CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   first full integration of mainstream code
  CHANGES:                   Revision 1.5 2017/11/20 19:03:39CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   LCF MFC431 R7.1
  CHANGES:                   Revision 1.4 2017/11/01 12:08:17CET Grosu, George (uidl9584) 
  CHANGES:                   Compilable version of maual code
  CHANGES:                   Revision 1.10.2.1 2017/08/30 10:39:30CEST Grosu, George (uidl9584) 
  CHANGES:                   Bugfix
  CHANGES:                   Revision 1.10 2017/08/09 15:45:32CEST Grosu, George (uidl9584) 
  CHANGES:                   Merge with MFC431HI28
  CHANGES:                   Revision 1.9 2017/08/03 15:01:21CEST Grosu, George (uidl9584) 
  CHANGES:                   IPC for Simulation
  CHANGES:                   Revision 1.8 2017/08/02 15:42:59CEST Grosu, George (uidl9584) 
  CHANGES:                   INT-13
  CHANGES:                   Revision 1.7 2017/07/25 14:53:54CEST Grosu, George (uidl9584) 
  CHANGES:                   Generic
  CHANGES:                   Revision 1.6 2017/07/24 08:56:43CEST Grosu, George (uidl9584) 
  CHANGES:                   New CP
  CHANGES:                   Revision 1.5 2017/07/14 09:38:37CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for TJA RTE
  CHANGES:                   Revision 1.4 2017/07/13 17:59:23CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for TJA RTE
  CHANGES:                   Revision 1.3 2017/07/05 14:10:27CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for INT-6
  CHANGES:                   Revision 1.2 2017/06/30 16:07:10CEST Grosu, George (uidl9584) 
  CHANGES:                   Update components
  CHANGES:                   Revision 1.1 2016/11/25 12:47:21CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Common includes cleanup.
  CHANGES:                   Revision 1.0 2016/07/01 06:44:48CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/algo/00_Custom/frame_sen/project.pj

**************************************************************************** */
#ifndef lcf_sen_cfg_h__
#define lcf_sen_cfg_h__


/**
@defgroup lcf_custom_cfg lcf custom configuration
  @ingroup lcf
    Custom configuration of lcf
@{ */

#include "lcf_dpu_cfg.h"


/*****************************************************************************
  Config:   
*****************************************************************************/

#define LCF_SEN_WRP_RUNTIME_PROFILING         (SWITCH_ON)    /*!< enable runtime profiling for LCF_SEN wrapper */

#endif // lcf_sen_cfg_h__
/** @} end defgroup: this sould be the last line in your external header*/ 

