/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_dpu_cfg.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_dpu_cfg.h  $
  CHANGES:                   Revision 1.1 2019/03/24 17:35:31CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:23CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/project.pj
  CHANGES:                   Revision 1.1 2019/01/31 18:56:03CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/project.pj
**************************************************************************** */
#ifndef lcf_dpu_cfg_h__
#define lcf_dpu_cfg_h__


/**
@defgroup lcf_custom_cfg lcf custom configuration
  @ingroup lcf
    Custom configuration of lcf
@{ */

#include "lcf_cfg.h"


/*****************************************************************************
  Config:   
*****************************************************************************/

/* issue 782615: Too many standard type variables are linked into data_near_asil section. 
So part of the LCF standard type variables should be linked in the far section.
This will only be done for the target ECU build, because far keyword is not recognized when building SIL dlls.
*/
// #ifdef PC_SIM  //MFC5J3
#define far 
// #endif

/* LCF data qualifiers */
#ifndef LCF_ParamQualifier  //MFC5J3
#define LCF_ParamQualifier	volatile far
#endif
#ifndef LCF_SignalQualifier  //MFC5J3
#define LCF_SignalQualifier	far
#endif

#endif // lcf_dpu_cfg_h__
/** @} end defgroup: this sould be the last line in your external header*/ 

