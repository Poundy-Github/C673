/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            interface_rsp_specbeamcmplxlist

  DESCRIPTION:          ARS400 B1 spec beam complex list (all versions)

  AUTHOR:               Thomas Berndt

  CREATION DATE:        16.09.2013

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: interface_rsp_specbeamcmplxlist.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:24CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/include/project.pj
  CHANGES:              Revision 1.1.1.4 2016/08/23 10:58:56CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + ARS510 V100
  CHANGES:              Revision 1.1.1.3 2014/08/13 14:08:16CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Simulation adapter changes - AL_ARS400EN_01.14.00
  CHANGES:              --- Added comments ---  berndtt1 [Aug 13, 2014 4:28:35 PM CEST]
  CHANGES:              Change Package : 221167:24 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.1.1.2 2014/07/01 15:22:58CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V3_PR Near Array Size 960 -> 640
  CHANGES:              --- Added comments ---  berndtt1 [Jul 2, 2014 8:56:41 AM CEST]
  CHANGES:              Change Package : 244114:2 http://mks-psad:7002/im/viewissue?selection=244114
  CHANGES:              Revision 1.1.1.1 2014/03/21 14:33:40CET Stolle, Ulf Eike (uidv1902) 
  CHANGES:              added SpecBeamCmplxList PR V1 und V2
  CHANGES:              --- Added comments ---  uidv1902 [Mar 21, 2014 2:33:40 PM CET]
  CHANGES:              Change Package : 226903:3 http://mks-psad:7002/im/viewissue?selection=226903
  CHANGES:              Revision 1.1 2013/09/18 16:45:05CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/include/project.pj

**************************************************************************** */
#ifndef INTERFACE_RSP_SPECBEAMCMPLXLST
#define INTERFACE_RSP_SPECBEAMCMPLXLST

#include "interface_base.h"

//
// Spec-Beam-Complex-list used from rte_type.h version 1.5.1.3 (inclusive),
// and up to 1.5.1.4 (with branch 1.5.1.3.1.1)
//
namespace RSP_SPECBEAMCMPLXLIST_V0               /* Size ARS Far: 16252 and Size ARS Near: 34832 */
{
  static const unsigned int NumFarSpecBeamCmplxList = 448;
#if SRR_SWITCH == SWITCH_ON
  static const unsigned int NumNearSpecBeamCmplxList = 360;
#else
  static const unsigned int NumNearSpecBeamCmplxList = 1024;
#endif
  typedef unsigned long AlgoDataTimeStamp_t      /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t      /* Algo cycle counter @min:0 @max:65535 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t        /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                 /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                              /* Common header for all structured data types */

  typedef struct                                 /* [Satisfies_rte sws 1191] */
  {
    signed char s_Real;
    signed char s_Imag;
  } t_Complex8;                                  /* signed 8 bit integer complex */

  typedef t_Complex8 a_SpecBeamCmplx_array_t_1[16]; /* Complex beam spectrum */ /* [Satisfies_rte sws 1189] */

  typedef struct                                 /* [Satisfies_rte sws 1191] */
  {
    unsigned short u_PowerScaleFactor;
    a_SpecBeamCmplx_array_t_1 a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplx;

  typedef RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t_0[NumFarSpecBeamCmplxList]; /* [Satisfies_rte sws 1189] */
  typedef RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t[NumNearSpecBeamCmplxList];  /* [Satisfies_rte sws 1189] */

  typedef struct                                 /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    a_SpecBeamCmplx_array_t_0 a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListFS;

  typedef struct                                 /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    a_SpecBeamCmplx_array_t a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListNS;

};  // End of namespace RSP_SPECBEAMCMPLXLIST_V0

namespace RSP_SPECBEAMCMPLXLIST_V1                                                       /* Size ARS Near: 67600 */
{
  static const unsigned int NumNearSpecBeamCmplxList = 1024;

  typedef RSP_SPECBEAMCMPLXLIST_V0::t_Complex8 a_SpecBeamCmplxMonopulse_array_t[16];     /* Complex beam spectrum */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    unsigned short u_PowerScaleFactor;
    RSP_SPECBEAMCMPLXLIST_V0::a_SpecBeamCmplx_array_t_1 a_SpecBeamCmplx;
    a_SpecBeamCmplxMonopulse_array_t a_SpecBeamCmplxMonopulse;
  } RSP_t_SpecBeamCmplx;

  typedef RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t[NumNearSpecBeamCmplxList];         /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP_SPECBEAMCMPLXLIST_V0::SignalHeader_t sSigHeader;
    a_SpecBeamCmplx_array_t a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListNS;

};  // End of namespace RSP_SPECBEAMCMPLXLIST_V1

namespace RSP_SPECBEAMCMPLXLIST_V1_PR
{
  static const unsigned int NumFarSpecBeamCmplxList = 448;
  static const unsigned int NumNearSpecBeamCmplxList = 960;

  //typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  //{
  //  unsigned short u_PowerScaleFactor;
  //  RSP_SPECBEAMCMPLXLIST_V0::a_SpecBeamCmplx_array_t_1 a_SpecBeamCmplx;
  //} RSP_t_SpecBeamCmplx;
  typedef RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplx RSP_t_SpecBeamCmplx;

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP_SPECBEAMCMPLXLIST_V0::SignalHeader_t sSigHeader;
  } RSP_t_SpecBeamCmplxHeader;

  typedef RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t_0[NumFarSpecBeamCmplxList];        /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    RSP_t_SpecBeamCmplxHeader Header;
    a_SpecBeamCmplx_array_t_0 a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListFS;                                                           /* @vaddr:0x06670000 @vaddr_defs: RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_FS @cycleid:RSP1_ENV @vname:RSP_CplxSpecFS */

  typedef RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t[NumNearSpecBeamCmplxList];         /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    RSP_t_SpecBeamCmplxHeader Header;
    a_SpecBeamCmplx_array_t a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListNS;                                                           /* @vaddr:0x06680000 @vaddr_defs: RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_NS @cycleid:RSP1_ENV @vname:RSP_CplxSpecNS */
};  // End of namespace RSP_SPECBEAMCMPLXLIST_V1_PR

namespace RSP_SPECBEAMCMPLXLIST_V2_PR
{
  static const unsigned int NumFarSpecBeamCmplxList = 448;
  static const unsigned int NumNearSpecBeamCmplxList = 960;

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    float f_PowerScaleFactor;
    RSP_SPECBEAMCMPLXLIST_V0::a_SpecBeamCmplx_array_t_1 a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplx;

  typedef RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t_0[NumFarSpecBeamCmplxList];        /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxHeader Header;
    a_SpecBeamCmplx_array_t_0 a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListFS;                                                           /* @vaddr:0x06670000 @vaddr_defs: RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_FS @cycleid:RSP1_ENV @vname:RSP_CplxSpecFS */

  typedef RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t[NumNearSpecBeamCmplxList];         /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxHeader Header;
    a_SpecBeamCmplx_array_t a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListNS;                                                           /* @vaddr:0x06680000 @vaddr_defs: RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_NS @cycleid:RSP1_ENV @vname:RSP_CplxSpecNS */
};  // End of namespace RSP_SPECBEAMCMPLXLIST_V2_PR


// SW_ARS400_PR_RTE_ALGOECUEXTRACT_1.57
namespace RSP_SPECBEAMCMPLXLIST_V3_PR
{
  static const unsigned int NumFarSpecBeamCmplxList = 448;
  static const unsigned int NumNearSpecBeamCmplxList = 640;

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    float f_PowerScaleFactor;
    RSP_SPECBEAMCMPLXLIST_V0::a_SpecBeamCmplx_array_t_1 a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplx;

  typedef RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t_0[NumFarSpecBeamCmplxList];        /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxHeader Header;
    a_SpecBeamCmplx_array_t_0 a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListFS;                                                           /* @vaddr:0x06670000 @vaddr_defs: RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_FS @cycleid:RSP1_ENV @vname:RSP_CplxSpecFS */

  typedef RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t[NumNearSpecBeamCmplxList];         /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxHeader Header;
    a_SpecBeamCmplx_array_t a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListNS;                                                           /* @vaddr:0x06680000 @vaddr_defs: RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_NS @cycleid:RSP1_ENV @vname:RSP_CplxSpecNS */
};  // End of namespace RSP_SPECBEAMCMPLXLIST_V3_PR


// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06%5fAlgorithm/04%5fEngineering/00%5fCodeGen/algo/rsp/core/project.pj&selection=rsp%5falgo%5finterface%5ftypes.xls&revision=1.128
namespace RSP_SPECBEAMCMPLXLIST_V2_1_EN                                                  /* Size ARS Near, Far: 20496, ----- */
{
  static const unsigned int NumNearSpecBeamCmplxList = 1024;

  typedef RSP_SPECBEAMCMPLXLIST_V0::t_Complex8 a_Channels_array_t[8];                    /* Complex channel values */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    float f_PowerScaleFactor;
    a_Channels_array_t a_Channels;
  } RSP_t_SpecBeamCmplx;

  typedef RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t[NumNearSpecBeamCmplxList];         /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxHeader Header;
    a_SpecBeamCmplx_array_t a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListNS;                                                           /* @vaddr:0x06680000 @vaddr_defs: RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_NS @cycleid:RSP1_ENV @vname:RSP_CplxSpecNS */
};  // End of namespace RSP_SPECBEAMCMPLXLIST_V2_1_EN


// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06%5fAlgorithm/04%5fEngineering/00%5fCodeGen/algo/rsp/core/project.pj&selection=rsp%5falgo%5finterface%5ftypes.xls&revision=1.140
namespace RSP_SPECBEAMCMPLXLIST_V2_2_EN                                                  /* Size ARS Near, Far: 15376, ----- */
{
  static const unsigned int NumNearSpecBeamCmplxList = 768;

  typedef RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t[NumNearSpecBeamCmplxList];         /* [Satisfies_rte sws 1189] */

  typedef struct                                                                         /* [Satisfies_rte sws 1191] */
  {
    RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxHeader Header;
    a_SpecBeamCmplx_array_t a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListNS;                                                           /* @vaddr:0x06680000 @vaddr_defs: RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_NS @cycleid:RSP1_ENV @vname:RSP_CplxSpecNS */
};  // End of namespace RSP_SPECBEAMCMPLXLIST_V2_2_EN

// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06%5fAlgorithm/04%5fEngineering/00%5fCodeGen/algo/rsp/core/project.pj&selection=rsp%5falgo%5finterface%5ftypes.xls&revision=1.140
namespace RSP_SPECBEAMCMPLXLIST_ARS5xx_V1                                                /* Size ARS Near, Far: , ----- */
{
  static const unsigned int NumNearSpecBeamCmplxList = 768;

  typedef RSP_SPECBEAMCMPLXLIST_V0::t_Complex8 a_Channels_array_t[16];                   /* Complex channel values */ /* [Satisfies_rte sws 1189] */

  typedef struct
  {
    float f_PowerScaleFactor;
    a_Channels_array_t a_Channels;
  } RSP_t_SpecBeamCmplx;

  typedef RSP_t_SpecBeamCmplx a_SpecBeamCmplx_array_t[NumNearSpecBeamCmplxList];

  typedef struct
  {
    RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxHeader Header;
    a_SpecBeamCmplx_array_t a_SpecBeamCmplx;
  } RSP_t_SpecBeamCmplxListNS;                                                           /* @vaddr:0x06680000 @vaddr_defs: RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_NS @cycleid:RSP1_ENV @vname:RSP_CplxSpecNS */
};  // End of namespace RSP_SPECBEAMCMPLXLIST_ARS5xx_V1


// Generic RSP_t_SpecBeamCmplxListNS                                                     Length = 
// Holds all possible structure members from all possible namespaces
namespace RSP_SPECBEAMCMPLXLIST_GEN
{

  typedef struct
  {
    unsigned long u_VersionNumber;
    RSP_SPECBEAMCMPLXLIST_V0::SignalHeader_t sSigHeader;

    RSP_SPECBEAMCMPLXLIST_V0::a_SpecBeamCmplx_array_t a_SpecBeamCmplx_v0;
    RSP_SPECBEAMCMPLXLIST_V1::a_SpecBeamCmplx_array_t a_SpecBeamCmplx_v1;
    RSP_SPECBEAMCMPLXLIST_V1_PR::a_SpecBeamCmplx_array_t a_SpecBeamCmplx_v2;
    RSP_SPECBEAMCMPLXLIST_V2_PR::a_SpecBeamCmplx_array_t a_SpecBeamCmplx_v3;
    RSP_SPECBEAMCMPLXLIST_V3_PR::a_SpecBeamCmplx_array_t a_SpecBeamCmplx_v4;
    RSP_SPECBEAMCMPLXLIST_V2_1_EN::a_SpecBeamCmplx_array_t a_SpecBeamCmplx_v5;           /* Used for RSP_SPECBEAMCMPLXLIST_V2_1_EN and RSP_SPECBEAMCMPLXLIST_V2_2_EN */

  } RSP_t_SpecBeamCmplxListNS;

  typedef struct
  {
    unsigned long u_VersionNumber;
    RSP_SPECBEAMCMPLXLIST_V0::SignalHeader_t sSigHeader;

    RSP_SPECBEAMCMPLXLIST_V0::a_SpecBeamCmplx_array_t_0 a_SpecBeamCmplx_v0;
    //RSP_SPECBEAMCMPLXLIST_V1::a_SpecBeamCmplx_array_t_0 a_SpecBeamCmplx_v1;
    RSP_SPECBEAMCMPLXLIST_V1_PR::a_SpecBeamCmplx_array_t_0 a_SpecBeamCmplx_v2;
    RSP_SPECBEAMCMPLXLIST_V2_PR::a_SpecBeamCmplx_array_t_0 a_SpecBeamCmplx_v3;

  } RSP_t_SpecBeamCmplxListFS;

};  // End of namespace RSP_SPECBEAMCMPLXLIST_GEN

#endif
