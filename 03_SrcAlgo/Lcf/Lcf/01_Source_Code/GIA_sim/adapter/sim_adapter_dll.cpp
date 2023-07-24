/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_adapter_dll.cpp

  DESCRIPTION:          

  AUTHOR:               Julian Schutsch

  CREATION DATE:        31.10.2013

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  
**************************************************************************** */

#include "stdafx.h"
#include "simadapter.h"

std::wfstream dbg;

// global variables
HANDLE g_hModule = NULL;

// The Measurement Objects
BEGIN_ADAPTER_OBJECT_TABLE()
  ADAPTER_OBJECT_ENTRY(CSimAdapter)
END_ADAPTER_OBJECT_TABLE()

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
  switch(ul_reason_for_call)
  {
  case DLL_PROCESS_ATTACH:
    g_hModule = hModule;
    dbg.open("adapter.out", std::ios_base::out);
    break;
  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
    break;
  case DLL_PROCESS_DETACH:
    dbg.close();
    break;
  }
    return TRUE;
}
/* ------------------------------------------------------------------------ */
/* EoF */