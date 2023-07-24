/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_veh_dyn.h

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        23.03.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_veh_dyn.h  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:56CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/vdy/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:44CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/vdy/project.pj
  CHANGES:              Revision 1.13.1.1 2013/08/07 10:39:06CEST ungvaryg 
  CHANGES:              Simplified VehDyn/VehPar adapter version, where only factory function is exposed via header file (complete implementation
  CHANGES:              hidden in cpp file, making modification of single file necessary when support for new interface version becomes necessary)
  CHANGES:              Note: incompatible change to old versions as respective classes (CConvVehDyn, CConvVehPar) no longer declared by header
  CHANGES:              file. This is the price to pay for information hiding (if the class is exposed via header, then the header always needs to be modified
  CHANGES:              for new conversions)
  CHANGES:              - Added comments -  ungvaryg [Aug 7, 2013 10:39:06 AM CEST]
  CHANGES:              Change Package : 190143:3 http://mks-psad:7002/im/viewissue?selection=190143
  CHANGES:              Revision 1.13 2013/01/16 11:36:32CET Spruck, Jochen (spruckj) 
  CHANGES:              Update VehSig VehPar and VehDyn adapter modules regarding mfc400 changes
  CHANGES:              --- Added comments ---  spruckj [Jan 16, 2013 11:36:33 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.12 2012/11/21 14:45:46CET Manea, Gabriela (ManeaG) 
  CHANGES:              Add new vdy vehdyn version to vdy sim adapter
  CHANGES:              --- Added comments ---  ManeaG [Nov 21, 2012 2:45:56 PM CET]
  CHANGES:              Change Package : 166725:1 http://mks-psad:7002/im/viewissue?selection=166725
  CHANGES:              Revision 1.11 2011/12/08 17:04:32CET Spruck, Jochen (spruckj) 
  CHANGES:              Add new vdy vehdyn version to vdy sim adapter
  CHANGES:              --- Added comments ---  spruckj [Dec 8, 2011 5:04:33 PM CET]
  CHANGES:              Change Package : 90999:1 http://mks-psad:7002/im/viewissue?selection=90999
  CHANGES:              Revision 1.10 2011/06/30 10:19:33CEST Sachs Martin (sachsm) (sachsm) 
  CHANGES:              fix RSPInputVdata for measurements of April 2009, due to error in pdo
  CHANGES:              --- Added comments ---  sachsm [Jun 30, 2011 10:19:34 AM CEST]
  CHANGES:              Change Package : 71262:1 http://mks-psad:7002/im/viewissue?selection=71262
  CHANGES:              Revision 1.9 2011/01/24 14:26:50CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:              RSP VDATA input data bug fix
  CHANGES:              --- Added comments ---  spruckj [Jan 24, 2011 2:26:50 PM CET]
  CHANGES:              Change Package : 57482:1 http://mks-psad:7002/im/viewissue?selection=57482
  CHANGES:              Revision 1.8 2010/11/23 10:25:51CET Jochen Spruck (spruckj) 
  CHANGES:              Merge the rsp VDATA input adaption to the general veh dyn adapter
  CHANGES:              --- Added comments ---  spruckj [Nov 23, 2010 10:25:52 AM CET]
  CHANGES:              Change Package : 51886:1 http://mks-psad:7002/im/viewissue?selection=51886
  CHANGES:              Revision 1.7 2010/11/22 17:24:22CET Jochen Spruck (spruckj) 
  CHANGES:              Update vdy adpter,
  CHANGES:              use the general adater for the interface VehDyn interface,
  CHANGES:              and merge the adaption of the old vdy interface to this adapter
  CHANGES:              --- Added comments ---  spruckj [Nov 22, 2010 5:24:22 PM CET]
  CHANGES:              Change Package : 51886:1 http://mks-psad:7002/im/viewissue?selection=51886
  CHANGES:              Revision 1.6 2010/11/19 11:05:17CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Change TPWInput_VehDyn and VehDyn name order: add comment for future removal of bogus "TPWInput_VehDyn" string
  CHANGES:              --- Added comments ---  ungvaryg [Nov 19, 2010 11:05:17 AM CET]
  CHANGES:              Change Package : 54752:1 http://mks-psad:7002/im/viewissue?selection=54752
  CHANGES:              Revision 1.5 2010/11/18 19:15:41CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Rewrite adapters for forward/backward compatibility
  CHANGES:              Clean up several unclean/problematic code parts (better transparancy of what adapter is doing, which
  CHANGES:              buffers it's using)
  CHANGES:              Remove overcomplicated CDataBuffer use (not needed anyway, hard to debug etc.)
  CHANGES:              --- Added comments ---  ungvaryg [Nov 18, 2010 7:15:41 PM CET]
  CHANGES:              Change Package : 54725:1 http://mks-psad:7002/im/viewissue?selection=54725
  CHANGES:              Revision 1.1 2010/03/26 09:57:42CET oraicu 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once

#include "sim_converter_base.h"

extern IConverter * CreateVehDynConvClass(void);
