/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 sim_swc_lcf_veh_dll.cpp

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   Initial revision
  
**************************************************************************** */

#include "stdafx.h"
#include "resource.h"
#include "sim_swc_lcf_veh.h"

// global variables
HANDLE g_hModule = NULL;

// The Measurement Objects
BEGIN_SIM_OBJECT_TABLE()
  SIM_OBJECT_ENTRY(CSimLcfVeh)
END_SIM_OBJECT_TABLE()

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID /*lpReserved*/)
{
  switch(ul_reason_for_call)
  {
  case DLL_PROCESS_ATTACH:
    g_hModule = hModule;
    break;
  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
  case DLL_PROCESS_DETACH:
  break;
  }
    return TRUE;
}
/* ------------------------------------------------------------------------ */
/* EoF */