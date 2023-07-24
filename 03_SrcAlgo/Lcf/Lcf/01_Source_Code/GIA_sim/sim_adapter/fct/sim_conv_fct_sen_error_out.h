/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_em

  MODULNAME:            sim_conv_fct_sen_error_out.h

  DESCRIPTION:          

  AUTHOR:               Manuel Olejua

  CREATION DATE:        

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_fct_sen_error_out.h  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:00CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:17CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.2 2014/09/09 10:06:56CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added 1:1 Conversion, changed TypeName to "FCTSenErrrorOut_t"
  CHANGES:              - Added comments -  berndtt1 [Sep 10, 2014 11:43:34 AM CEST]
  CHANGES:              Change Package : 221167:30 http://mks-psad:7002/im/viewissue?selection=221167

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once

#include "sim_converter_base.h"

extern IConverter * CreateFctSenErrorOutConvInstance(void);