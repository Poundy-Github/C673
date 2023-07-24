/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_adapter_fct_dll.cpp

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        23.03.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_adapter_dll.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:12CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:14:44CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/project.pj
  CHANGES:              Revision 1.1 2013/02/07 13:55:54CET ungvaryg 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/project.pj
  CHANGES:              Revision 1.1 2010/03/26 09:56:47CET oraicu 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj
  
**************************************************************************** */

#include "stdafx.h"
#include "resource.h"
#include "sim_adapter_main.h"

// global variables
HANDLE g_hModule = NULL;

// The Measurement Objects
BEGIN_ADAPTER_OBJECT_TABLE()
  ADAPTER_OBJECT_ENTRY(CSimAdapterMain)
END_ADAPTER_OBJECT_TABLE()

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
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