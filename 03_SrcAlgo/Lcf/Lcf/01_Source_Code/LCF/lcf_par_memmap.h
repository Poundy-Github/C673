/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_par_memmap.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.2 $


  ---*/ /*---
  CHANGES:                   $Log: lcf_par_memmap.h  $
  CHANGES:                   Revision 1.2 2020/07/31 12:27:09CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   new updates
  CHANGES:                   Revision 1.1 2019/06/26 19:10:46CEST Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/project.pj

**************************************************************************** */

#if defined(LCF_PAR_MEMMAP_USED) && LCF_PAR_MEMMAP_USED == LCF_SWITCH_ON

#ifdef LCF_ParamQualifier
#undef LCF_ParamQualifier
#endif

#ifdef LCFPRM_ONLINE_START
#undef LCFPRM_ONLINE_START
#include "parameter_online_start.h"
#define LCF_ParamQualifier PARAMETER_ONLINE
#endif // LCFPRM_ONLINE_START

#ifdef LCFPRM_ONLINE_STOP
#undef LCFPRM_ONLINE_STOP
#include "parameter_online_stop.h"
#endif // LCFPRM_ONLINE_STOP

#ifdef LCFPRM_OFFLINE_START
#undef LCFPRM_OFFLINE_START
#include "parameter_offline_start.h"
#define LCF_ParamQualifier PARAMETER_OFFLINE
#endif // LCFPRM_OFFLINE_START

#ifdef LCFPRM_OFFLINE_STOP
#undef LCFPRM_OFFLINE_STOP
#include "parameter_offline_stop.h"
#endif // LCFPRM_OFFLINE_STOP

#endif // LCF_PAR_MEMMAP_USED


