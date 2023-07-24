/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_veh_par.h

  DESCRIPTION:          Converter class for VehPar

  AUTHOR:               Frank Wolter/Jochen Spruck/Gergely Ungvary

  CREATION DATE:        27.10.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_veh_par.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:44CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/vdy/project.pj
  CHANGES:              Revision 1.15.1.1 2013/08/07 10:39:08CEST ungvaryg 
  CHANGES:              Simplified VehDyn/VehPar adapter version, where only factory function is exposed via header file (complete implementation
  CHANGES:              hidden in cpp file, making modification of single file necessary when support for new interface version becomes necessary)
  CHANGES:              Note: incompatible change to old versions as respective classes (CConvVehDyn, CConvVehPar) no longer declared by header
  CHANGES:              file. This is the price to pay for information hiding (if the class is exposed via header, then the header always needs to be modified
  CHANGES:              for new conversions)
  CHANGES:              - Added comments -  ungvaryg [Aug 7, 2013 10:39:08 AM CEST]
  CHANGES:              Change Package : 190143:3 http://mks-psad:7002/im/viewissue?selection=190143

**************************************************************************** */
#pragma once
#include "sim_converter_base.h"

extern IConverter * CreateVehParConvClass(void);
