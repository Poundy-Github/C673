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
  CHANGES:                Revision 1.1 2020/05/08 04:23:34CEST Wang, Jianan02 (uia93585) (uia93585) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/RTE_RunTimeEnvironment/04_Engineering/00_Projects/MFC431VA21/common/RTE_VH/algo/project.pj
  CHANGES:                Revision 1.1 2019/04/29 10:32:42CEST Wang, Jianan02 (uia93585) (uia93585) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/RTE_RunTimeEnvironment/04_Engineering/00_Projects/MFC431VA10/common/RTE_VH/algo/project.pj
  CHANGES:                Revision 1.3 2016/11/30 14:08:32CET Baur, Magnus (uidr0839) 
  CHANGES:                SW_COMMON_161111_MFC431_RTE
  CHANGES:                updated algo_glob.h to rev. 1.8
  CHANGES:                sw_interface_types.xls    1.112
  CHANGES:                DB_TRANS_TYPE_VERSION     88
  CHANGES:                based on AUTOSAR_AlgoTypes.ecuextract 1.3.1.22
  CHANGES:                Dem_IntErrIdSlv.h         1.3
  CHANGES:                Revision 1.2 2016/11/30 13:31:10CET Baur, Magnus (uidr0839) 
  CHANGES:                update for R5.0 Release from old repository
  CHANGES:                SW_COMMON_161111_MFC431_RTE
  CHANGES:                updated algo_glob.h to rev. 1.8
  CHANGES:                sw_interface_types.xls    1.112
  CHANGES:                DB_TRANS_TYPE_VERSION     88
  CHANGES:                based on AUTOSAR_AlgoTypes.ecuextract 1.3.1.22
  CHANGES:                Dem_IntErrIdSlv.h         1.3
  CHANGES:                Revision 1.1 2016/11/25 12:22:12CET Baur, Magnus (uidr0839) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/RTE_RunTimeEnvironment/04_Engineering/00_Projects/MFC431/common/RTE_VH/algo/project.pj
  CHANGES:                Revision 1.7 2014/10/02 10:23:58CEST Miettinen, Markku (uidw0354) 
  CHANGES:                Error checked memory section include added
  CHANGES:                - Added comments -  uidw0354 [Oct 2, 2014 10:23:59 AM CEST]
  CHANGES:                Change Package : 266477:1 http://mks-psad:7002/im/viewissue?selection=266477
  CHANGES:                Revision 1.6 2014/06/16 17:08:38CEST Roher-EXT, Christian (uidg9448) 
  CHANGES:                QAC check minor format changes for better readability and suppressions
  CHANGES:                --- Added comments ---  uidg9448 [Jun 16, 2014 5:08:39 PM CEST]
  CHANGES:                Change Package : 238988:1 http://mks-psad:7002/im/viewissue?selection=238988
  CHANGES:                Revision 1.6 2014/14/06 10:15:27CET Christian, Rother 
  CHANGES:                QAC check minor format changes for better readability
  CHANGES:                Change Package : 238988:1 http://mks-psad:7002/im/viewissue?selection=238988
  CHANGES:                Revision 1.5 2014/03/05 12:38:27CET Spruck, Jochen (spruckj) 
  CHANGES:                Add c++ guard for cml_ext.h
  CHANGES:                --- Added comments ---  spruckj [Mar 5, 2014 12:38:27 PM CET]
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
#include "glob_defs.h"
#include "glob_memsec.h"

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
/* PRQA S 3429,3453 1 */ /* C.Rother 04.06.2014 Function like macro not replaceable by fkt */
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
#define VDY_IO_STATE_BITMASK                       ((VDYIoState_t) (0x3U))
#define VDY_SET_IO_STATE(pos_, state_, val_)
#define VDY_GET_IO_STATE(pos_,val_)                 0
#else
#if (VDY_VEH_DYN_INTFVER_LCF <= 5)
#define VDY_IO_STATE_BITMASK                       ((VDYIoState_t) (0x3U))
/* PRQA S 3429,3435,3453,3456 10 */ /* C.Rother 03.06.2014 Function like macro. WARNING: Parameter pos_ occurs more then once so */
/*                                                        do not use variables with side effect ( e.g ++ )!                     */
#define VDY_SET_IO_STATE(pos_, state_, val_)       (                                                                                   \
                                                    (val_)[(pos_)/32UL] = (                                                            \
                                                                              ~((VDYIoState_t) (VDY_IO_STATE_BITMASK << ((pos_)%32UL)))\
                                                                             & ((val_)[(pos_)/32UL])                                   \
                                                                          )                                                            \
                                                                        | (                                                            \
                                                                             (VDY_IO_STATE_BITMASK & (state_))<<((pos_)%32UL)          \
                                                                          )                                                            \
                                                   )
/* PRQA S 3429,3435,3453,3456 2 */ /* C.Rother 03.06.2014  Function like macro. WARNING: Parameter pos_ occurs more then once so do */
/*                                                         not use variables with side effect (e.g ++ )!                            */
#define VDY_GET_IO_STATE(pos_,val_)                ( ((val_)[(pos_)/32UL] >> ((pos_) % 32UL)) & VDY_IO_STATE_BITMASK)
#else
#define VDY_SET_IO_STATE(pos_, state_, val_)       ((val_)[(pos_)] = (state_))
#define VDY_GET_IO_STATE(pos_,val_)                ((val_)[(pos_)])

#define VDY_IO_STATE_BITMASK                       ((VDYIoState_t) (0x3U))
#define VDY_SET_NVM_IO_STATE(pos_, state_, val_)   (                                                                                   \
                                                      (val_)[(pos_)/32UL] = (                                                          \
                                                                                ~((VDYIoState_t) (VDY_IO_STATE_BITMASK<<((pos_)%32UL)))\
                                                                               & ((val_)[(pos_)/32UL])                                 \
                                                                            )                                                          \
                                                                          | (                                                          \
                                                                               (VDY_IO_STATE_BITMASK & (state_))<<((pos_)%32UL)        \
                                                                            )                                                          \
                                                   )
#define VDY_GET_NVM_IO_STATE(pos_,val_)            ( ((val_)[(pos_)/32UL] >> ((pos_) % 32UL)) & VDY_IO_STATE_BITMASK)
#endif
#endif


#endif

