/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              sim

  COMPONENT:            <TODO: Enter Component Name>

  MODULNAME:            <TODO: Enter Module File Name>

  DESCRIPTION:          <TODO: Enter description text>

  AUTHOR:               Robert Hecker

  CREATION DATE:        08.09.2008

  VERSION:              $<TODO remove this text to enable MKS makro>Revision:$

  ---*/ /*---
  CHANGES:              $<TODO remove this text to enable MKS makro>Log:$

**************************************************************************** */

#include "stdafx.h"
#include "hil_client.h"

#include "sim_object_base.h"

// global variables
HANDLE g_hModule = NULL;

// The Measurement Objects
BEGIN_SIM_OBJECT_TABLE()
	SIM_OBJECT_ENTRY( C_HilClient )
END_SIM_OBJECT_TABLE()

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID /*lpReserved*/)
{
	switch (ul_reason_for_call)
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