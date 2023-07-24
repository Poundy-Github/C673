/*! \file **********************************************************************

COMPANY:              Continental

PROJECT:              Simulation

COMPONENT:            sim_swc_hla_dll

MODULNAME:            sim_swc_hla_dll.cpp

DESCRIPTION:          SWC plugin for Head Light Assist

AUTHOR:               Mihai Anghel

CREATION DATE:        26.02.2009

VERSION:              $Revision: 1.1 $

---*/ /*---
CHANGES:              $Log: sim_swc_hla_dll.cpp  $
CHANGES:              Revision 1.1 2017/02/28 15:29:50CET Fischer, Stephan02 (uidg9447) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/SW/Components/HLA_HeadLightAssist/04_Engineering/03_Workspace/Component_Workspace/HLA_sim/sim_swc_hla/project.pj
CHANGES:              Revision 1.1 2014/03/18 16:35:29CET Mutschler, Matthias (uidv7867) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/sim_swc_hla/project.pj
CHANGES:              Revision 1.2 2010/08/05 20:47:50CEST Brunn, Marcus (brunnm) 
CHANGES:              update for hla adapter (measfreeze adapter)
CHANGES:              --- Added comments ---  brunnm [Aug 5, 2010 8:47:50 PM CEST]
CHANGES:              Change Package : 38437:1 http://mks-psad:7002/im/viewissue?selection=38437
CHANGES:              Revision 1.1 2010/05/25 14:17:14CEST rmueller 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/sim_swc_hla/src/project.pj

**************************************************************************** */

#include "stdafx.h"
#include "resource.h"
#include "sim_swc_hla.h"
#include "sim_swc_base.h"

// global variables
HANDLE g_hModule = NULL;

// The Measurement Objects
BEGIN_SIM_OBJECT_TABLE()
SIM_OBJECT_ENTRY(CSimSwcHLA)
END_SIM_OBJECT_TABLE()

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