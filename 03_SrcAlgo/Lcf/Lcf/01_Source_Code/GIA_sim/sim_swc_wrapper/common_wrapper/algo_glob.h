/*! \file **********************************************************************

  COMPANY:                Continental Temic, PC DAS, A.D.C. GmbH

  PROJECT:                All

  CPU:                    All

  COMPONENT:              RTE

  MODULNAME:              algo_glob.h

  DESCRIPTION:            


  CREATION DATE:          11.09.2007

  VERSION:                $Revision: 1.1 $

                  
  ---*/ /*---
  CHANGES:                $Log: algo_glob.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:22:58CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/common_wrapper/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:34:35CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/common_wrapper/project.pj
  CHANGES:                Revision 1.5 2014/03/05 12:38:27CET spruckj 
  CHANGES:                Add c++ guard for cml_ext.h
  CHANGES:                - Added comments -  spruckj [Mar 5, 2014 12:38:27 PM CET]
  CHANGES:                Change Package : 196584:4 http://mks-psad:7002/im/viewissue?selection=196584
  CHANGES:                Revision 1.4 2014/02/28 10:46:26CET Wolter, Frank (wolterf) 
  CHANGES:                - added include of CML
  CHANGES:                - changed VDY I/O state macros
  CHANGES:                --- Added comments ---  wolterf [Feb 28, 2014 10:46:27 AM CET]
  CHANGES:                Change Package : 221279:1 http://mks-psad:7002/im/viewissue?selection=221279
  CHANGES:                Revision 1.3 2013/12/03 10:03:26CET Spruck, Jochen (spruckj) 
  CHANGES:                remove #define VDY_IO_STATE_INIT  becaue it is now in the rte
  CHANGES:                --- Added comments ---  spruckj [Dec 3, 2013 10:03:26 AM CET]
  CHANGES:                Change Package : 196584:4 http://mks-psad:7002/im/viewissue?selection=196584
  CHANGES:                Revision 1.2 2013/07/18 16:19:12CEST Spruck, Jochen (spruckj) 
  CHANGES:                Check MKS issue with file share
  CHANGES:                --- Added comments ---  spruckj [Jul 18, 2013 4:19:12 PM CEST]
  CHANGES:                Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                Revision 1.1 2013/05/16 14:00:15CEST Spruck, Jochen (spruckj) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/ACI_AlgoCommonInterfaces/01_Source_Code/algo_common/project.pj


**************************************************************************** */
#ifndef ALGO_GLOB_HE_INCLUDED
#define ALGO_GLOB_HE_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "algo_cfg.h"
#include "algo_type.h"
#include "algo_service_types.h"
#include "glob_comp_id.h"

#ifdef __cplusplus
extern "C"
{
#endif
  #include "cml_ext.h"
#ifdef __cplusplus
}
#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/

/* Definition of utility message macro for MS-VS */
#define COMPILEMSG(x) message(__FILE__"("STRING_QUOTE(__LINE__)"): TODO: " x)

/*! Internally used macro, never use outside of this file. */
#define STRING_INTERNAL_QUOTE(x)  #x

/*! Macro to convert a token/define to string. Useful for names etc. Note how
the internally used macro is needed by this function. Otherwise define
replacement wouldn't take place */
#define STRING_QUOTE(x) STRING_INTERNAL_QUOTE(x)

#ifdef HINWEIS
#pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): add the folowing struct to the xls file")
#endif

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! Dummy interface version number. This define is used to set the version number
of interfaces not used in the code */
#define DUMMY_INTERFACE_VERSION   0xFFFFFFFFu

/*****************************************************************************

  VDY io state macros

  In order to access any vdy signal/parameter io state,
  use this bit masks and the set/get macros

*****************************************************************************/

/*! Set get macros for the vdy states */
#ifdef __PDO__
#define VDY_IO_STATE_BITMASK                   ((VDYIoState_t) (0x3U))
#define VDY_SET_IO_STATE(pos_, state_, val_)
#define VDY_GET_IO_STATE(pos_,val_)             0
#else
#if (VDY_VEH_DYN_INTFVER <= 5)
#define VDY_IO_STATE_BITMASK                   ((VDYIoState_t) (0x3U))
#define VDY_SET_IO_STATE(pos_, state_, val_)   ( (val_)[(pos_)/32UL] = (~((VDYIoState_t) (VDY_IO_STATE_BITMASK<<((pos_)%32UL))) & ((val_)[(pos_)/32UL])) | ((VDY_IO_STATE_BITMASK & (state_))<<((pos_)%32UL)))
#define VDY_GET_IO_STATE(pos_,val_)            ( ((val_)[(pos_)/32UL] >> ((pos_) % 32UL)) & VDY_IO_STATE_BITMASK)
#else
#define VDY_SET_IO_STATE(pos_, state_, val_)   ((val_)[(pos_)] = (state_))
#define VDY_GET_IO_STATE(pos_,val_)            ((val_)[(pos_)])

#define VDY_IO_STATE_BITMASK                       ((VDYIoState_t) (0x3U))
#define VDY_SET_NVM_IO_STATE(pos_, state_, val_)   ( (val_)[(pos_)/32UL] = (~((VDYIoState_t) (VDY_IO_STATE_BITMASK<<((pos_)%32UL))) & ((val_)[(pos_)/32UL])) | ((VDY_IO_STATE_BITMASK & (state_))<<((pos_)%32UL)))
#define VDY_GET_NVM_IO_STATE(pos_,val_)            ( ((val_)[(pos_)/32UL] >> ((pos_) % 32UL)) & VDY_IO_STATE_BITMASK)
#endif
#endif


#endif

