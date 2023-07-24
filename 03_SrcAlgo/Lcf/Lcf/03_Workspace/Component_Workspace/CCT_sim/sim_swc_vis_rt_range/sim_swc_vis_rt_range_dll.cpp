/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

*/
#include "stdafx.h"
#include "resource.h"
#include "sim_swc_vis_rt_range.h"

// global variables
HANDLE g_hModule = NULL;

// The Measurement Objects
BEGIN_SIM_OBJECT_TABLE()
  SIM_OBJECT_ENTRY(CSimVisRtRange)
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