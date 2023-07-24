/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_bswalgo_param

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        23.03.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_bswalgo_param.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:11CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.36 2017/02/08 15:53:15CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V33 (ARS510)
  CHANGES:              Revision 1.35 2016/09/14 13:45:48CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              +V32 (Hyundayi)
  CHANGES:              Revision 1.34 2016/07/21 14:30:12CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V26 for ARS510 (=V26 without ALN)
  CHANGES:              Revision 1.33 2016/06/29 12:17:48CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              + V31 (same as V26_2
  CHANGES:              Revision 1.32 2016/06/01 14:32:11CEST Cretu, Teodora (CretuT) 
  CHANGES:              Add Convert_V27_1_to_Gen and InitV27 for V27 (size 160)
  CHANGES:              Revision 1.30 2016/02/03 14:39:20CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V27 (equal to V26)
  CHANGES:              Revision 1.29 2016/01/22 07:39:53CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V23 for ARS4B0 (ARS400_PR) (AL_ARS4B0_02.14.90_INT-9)
  CHANGES:              Revision 1.28 2015/11/03 12:42:33CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V26 for ARS4B0 (ARS400_PR)
  CHANGES:              --- Added comments ---  berndtt1 [Nov 3, 2015 12:47:28 PM CET]
  CHANGES:              Change Package : 393111:1 http://mks-psad:7002/im/viewissue?selection=393111
  CHANGES:              Revision 1.27 2015/09/28 10:46:31CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V25 (treated as V26)
  CHANGES:              --- Added comments ---  berndtt1 [Sep 28, 2015 10:49:37 AM CEST]
  CHANGES:              Change Package : 221167:57 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.26 2015/08/21 12:49:08CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V26
  CHANGES:              --- Added comments ---  berndtt1 [Aug 21, 2015 1:00:46 PM CEST]
  CHANGES:              Change Package : 369795:1 http://mks-psad:7002/im/viewissue?selection=369795
  CHANGES:              Revision 1.25 2015/04/20 07:51:16CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V21 (except for ARS4A0)
  CHANGES:              --- Added comments ---  berndtt1 [Apr 20, 2015 8:13:03 AM CEST]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.24 2015/03/09 13:54:40CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Version 20 for ARS400_PR (mapped from V19_2)
  CHANGES:              --- Added comments ---  berndtt1 [Mar 9, 2015 2:00:33 PM CET]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.23 2015/02/10 08:14:36CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Default values for Fct.Blockage.b_BlockageUseTemperature and Fct.Blockage.b_BlockageUseWiper changed from 1 to 0
  CHANGES:              --- Added comments ---  berndtt1 [Feb 10, 2015 8:21:04 AM CET]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.22 2015/02/04 12:36:05CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Comment
  CHANGES:              --- Added comments ---  berndtt1 [Feb 4, 2015 12:39:47 PM CET]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.21 2015/02/04 11:37:46CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              * V19 -> V19_1
  CHANGES:              + V19_2 and V20
  CHANGES:              Fct and Fct.Blockage modifcations, V20 with addtional Fct.Acc modification
  CHANGES:              --- Added comments ---  berndtt1 [Feb 4, 2015 12:04:49 PM CET]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.20 2015/01/27 14:52:04CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V19 (Fct and Fct.Blockage modifications)
  CHANGES:              --- Added comments ---  berndtt1 [Jan 27, 2015 2:59:21 PM CET]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.19 2014/12/15 17:07:24CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V18 (identical to V16)
  CHANGES:              --- Added comments ---  berndtt1 [Dec 15, 2014 5:10:12 PM CET]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.18 2014/10/29 15:09:23CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Version V16
  CHANGES:              --- Added comments ---  berndtt1 [Oct 29, 2014 3:47:14 PM CET]
  CHANGES:              Change Package : 221167:34 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.17 2014/08/22 18:02:26CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Special case with version number 13 used for version 10
  CHANGES:              --- Added comments ---  berndtt1 [Aug 22, 2014 6:03:42 PM CEST]
  CHANGES:              Change Package : 221167:28 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.16 2014/08/14 11:43:19CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Special case with version number 12 used for version 10 (ARS400_EN)
  CHANGES:              --- Added comments ---  berndtt1 [Aug 14, 2014 11:50:05 AM CEST]
  CHANGES:              Change Package : 205284:2 http://mks-psad:7002/im/viewissue?selection=205284
  CHANGES:              Revision 1.15 2014/08/07 11:27:47CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Special case with version number 14 used for version 13
  CHANGES:              --- Added comments ---  berndtt1 [Aug 7, 2014 12:14:28 PM CEST]
  CHANGES:              Change Package : 221167:22 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.14 2014/08/05 14:17:26CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Special case with version number 13 transmitted and requested for version 10
  CHANGES:              --- Added comments ---  berndtt1 [Aug 5, 2014 2:20:11 PM CEST]
  CHANGES:              Change Package : 221167:22 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.13 2014/07/25 16:26:59CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Special case with version number 13 transmitted and requested for version 10
  CHANGES:              --- Added comments ---  berndtt1 [Jul 25, 2014 4:29:48 PM CEST]
  CHANGES:              Change Package : 221167:22 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.12 2014/07/25 08:17:58CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Version 0x0D (13)
  CHANGES:              --- Added comments ---  berndtt1 [Jul 25, 2014 8:20:19 AM CEST]
  CHANGES:              Change Package : 221167:22 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.11 2014/06/13 10:25:16CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Introduced new adaption concept
  CHANGES:              and Version 10
  CHANGES:              --- Added comments ---  berndtt1 [Jun 13, 2014 10:34:35 AM CEST]
  CHANGES:              Change Package : 221167:17 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.10 2013/12/12 11:15:46CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + namespace BSW_s_AlgoParameters_ARS4xx_V6_V3
  CHANGES:              --- Added comments ---  berndtt1 [Jan 10, 2014 11:30:48 AM CET]
  CHANGES:              Change Package : 208935:2 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:              Revision 1.9 2013/06/26 10:03:06CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              ARS4xx BSW_s_AlgoParameters conversion class implementation
  CHANGES:              NOTE: Not compatible with previous versions only support for ARS400 BSW_s_AlgoParameters versions implemented!
  CHANGES:              (As support for older layouts no longer needed for ARS400 measurements)
  CHANGES:              --- Added comments ---  ungvaryg [Jun 26, 2013 10:03:06 AM CEST]
  CHANGES:              Change Package : 179559:3 http://mks-psad:7002/im/viewissue?selection=179559
  CHANGES:              Revision 1.8 2012/04/26 13:49:14CEST Mogos, Sorin (mogoss) 
  CHANGES:              * update: added conversion from current version to old versions of BSWAlgoParameter_t
  CHANGES:              --- Added comments ---  mogoss [Apr 26, 2012 1:49:14 PM CEST]
  CHANGES:              Change Package : 104778:1 http://mks-psad:7002/im/viewissue?selection=104778
  CHANGES:              Revision 1.7 2012/04/17 09:00:36CEST Mogos, Sorin (mogoss) 
  CHANGES:              * update: added conversion for new version of BSW_s_AlgoParameters_t
  CHANGES:              --- Added comments ---  mogoss [Apr 17, 2012 9:00:36 AM CEST]
  CHANGES:              Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
  CHANGES:              Revision 1.6 2011/09/01 13:29:15CEST Raicu, Ovidiu (RaicuO) 
  CHANGES:              Updated for new version of rte.h .
  CHANGES:              --- Added comments ---  RaicuO [Sep 1, 2011 1:29:16 PM CEST]
  CHANGES:              Change Package : 76905:1 http://mks-psad:7002/im/viewissue?selection=76905
  CHANGES:              Revision 1.5 2011/05/03 12:36:41CEST Ovidiu Raicu (RaicuO) 
  CHANGES:              Updated to new rte version.
  CHANGES:              --- Added comments ---  RaicuO [May 3, 2011 12:36:41 PM CEST]
  CHANGES:              Change Package : 62743:1 http://mks-psad:7002/im/viewissue?selection=62743
  CHANGES:              Revision 1.4 2011/04/14 11:36:58CEST Ovidiu Raicu (RaicuO) 
  CHANGES:              Updated with new conversion for BSW_s_AlgoParameters.
  CHANGES:              --- Added comments ---  RaicuO [Apr 14, 2011 11:36:58 AM CEST]
  CHANGES:              Change Package : 58958:1 http://mks-psad:7002/im/viewissue?selection=58958
  CHANGES:              Revision 1.3 2011/04/11 12:05:42CEST Ovidiu Raicu (RaicuO) 
  CHANGES:              Updated BSW_s_AlgoParameters conversion to new version.
  CHANGES:              --- Added comments ---  RaicuO [Apr 11, 2011 12:05:42 PM CEST]
  CHANGES:              Change Package : 58958:1 http://mks-psad:7002/im/viewissue?selection=58958
  CHANGES:              Revision 1.2 2010/11/26 09:22:05CET Ovidiu Raicu (RaicuO) 
  CHANGES:              Updated conversion to the new BSW_s_AlgoParameters structure.
  CHANGES:              --- Added comments ---  RaicuO [Nov 26, 2010 9:22:05 AM CET]
  CHANGES:              Change Package : 51581:1 http://mks-psad:7002/im/viewissue?selection=51581
  CHANGES:              Revision 1.1 2010/11/25 08:45:46CET Ovidiu Raicu (RaicuO) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_bswalgo_param.h"
#include "sim_versioninfo_impl.h"
#include "sim_adapter_cfg.h"

// New method for ARS5xx (Does nothing)
#define VAR(vartype, memclass) vartype

typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;

static inline float DEG2RAD(float fDegrees)
{
  return fDegrees * (3.1415927f / 180.f);
}

// ARS4xx BSW_s_AlgoParameters version 6 V1
namespace BSW_s_AlgoParameters_ARS4xx_V6_V1
{
  typedef struct EBAPrePrkAccelTabNv_t
  {
    float32 Velo;           /* Velocity @min:0.0 @max:100.0 */
    float32 Accel;          /* Minimum (neg.) allowed acceleration level 1 @min:-15.0 @max:0.0 */
  } EBAPreBrkAccelTabNv_t;  /* Minimum (neg.) allowed acceleration level 1 */

  typedef EBAPreBrkAccelTabNv_t AccelL2_array_t[4]; /* Minimum (neg.) allowed acceleration level 2 */

  typedef struct Aln_algo_parameters_t
  {
    float32 f_ElevMonMaxDiff; /* maximum allowed difference between last Eol/service alignment value and monitoring value and monitoring values in elevation (if exceeded DEM event is sent) */
    float32 f_AzimMonMaxDiff; /* maximum allowed difference between last Eol/service alignment value and monitoring value and monitoring values in azimuth (if exceeded DEM event is sent) */
    boolean b_ElevMonEnable;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
    boolean b_AzimMonEnable;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  } Aln_algo_parameters_t;    /* Alignment settings */


  typedef EBAPreBrkAccelTabNv_t AccelL1_array_t[4]; /* Minimum (neg.) allowed acceleration level 1 */

  typedef uint8 EBAPreBrkAccelParNvState_t  /* Validity status of acceleration parameter table @min: 0 @max:3 @values: enum { EBA_NV_TAB_PRE_BRK_LEV2_VALID=2,EBA_NV_TAB_PRE_BRK_INVALID=0,EBA_NV_TAB_PRE_BRK_LEV1_VALID=1,EBA_NV_TAB_PRE_BRK_ALL_VALID=3,} */;

  typedef struct EBAPreBrkAccelParNv_t
  {
    EBAPreBrkAccelParNvState_t Valid; /* Validity status of acceleration parameter table */
    AccelL1_array_t AccelL1;          /* Minimum (neg.) allowed acceleration level 1 */
    AccelL2_array_t AccelL2;          /* Minimum (neg.) allowed acceleration level 2 */
  } EBAPreBrkAccelParNv_t;            /* PreBrake permitted acceleration over velocity */

  typedef uint8 Em_cem_algo_sensor_state_t  /* State of COD usage @min: 0 @max:4 @values: enum { CEM_PAR_SENSOR_STATE_NORMAL=1,CEM_PAR_SENSOR_STATE_OFF=0,CEM_PAR_SENSOR_STATE_ENHANCE=3,CEM_PAR_SENSOR_STATE_REDUCE=2,CEM_PAR_SENSOR_STATE_ERROR=4,} */;
  typedef uint8 Em_cem_algo_mode_t         /* Coding parameter for mode selection @min: 0 @max:15 @values: enum { CEM_PAR_ME_SEL_NO=0,CEM_PAR_ME_SEL_2=2,CEM_PAR_ME_SEL_3=3,CEM_PAR_ME_SEL_1=1,CEM_PAR_ME_SEL_INVALID=15,CEM_PAR_ME_SEL_4=4,CEM_PAR_ME_SEL_5=5,} */;

  typedef struct Em_cem_algo_parameters_t
  {
    Em_cem_algo_sensor_state_t eCEMParCodState;   /* State of COD usage */
    Em_cem_algo_sensor_state_t eCEMParCldState;   /* State of CLD usage */
    Em_cem_algo_mode_t eCEMParModeSelection;      /* Coding parameter for mode selection */
  } Em_cem_algo_parameters_t;   /* Camera fusion parameters */

  typedef struct Em_algo_parameters_t
  {
    Em_cem_algo_parameters_t Cem; /* Camera fusion parameters */
  } Em_algo_parameters_t;   /* Environment Model Parameters */

  typedef uint8 CameraFusionPreselBits_t   /* Camera fusion preselection parameters @min: 0 @max:255 @values: enum { ACC_PAR_FUSION_SEL_DEFAULT=0,ACC_PAR_FUSION_SEL_NO_BIKES=1,ACC_PAR_FUSION_SEL_MAX=255,ACC_PAR_FUSION_SEL_BIT6=32,ACC_PAR_FUSION_SEL_BIT7=64,ACC_PAR_FUSION_SEL_BIT4=8,ACC_PAR_FUSION_SEL_BIT5=16,ACC_PAR_FUSION_SEL_BIT2=2,ACC_PAR_FUSION_SEL_BIT3=4,ACC_PAR_FUSION_SEL_BIT8=128,} */;

  typedef struct Fct_acc_algo_parameters_t
  {
    CameraFusionPreselBits_t CameraFusionPreselBits;              /* Camera fusion preselection parameters */
  } Fct_acc_algo_parameters_t;  /* ACC Function Parameters */

  typedef struct Fct_blockage_algo_parameters_t
  {
    float32 f32_ShutoffRange;         /* @min:0 @max:200.0 */
    float32 f32_ShutoffTime_Timeout;  /* @min:1 @max:500.0 */
    float32 f32_ShutoffWay_Timeout;   /* @min:1 @max:10000 */
    uint8 ui_ShutoffNoOfObjLosses;    /* @min:0 @max:10 */
    boolean b_BlockageActive;         /* @min:0 @max:1 */
  } Fct_blockage_algo_parameters_t; /* Blockage Function Parameters */

  typedef uint32 EBACodingBitEnum_t         /* EBA Coding Bits @min: 1 @max:4294967295 @values: enum { EBA_NV_COD_PRE_BRK_STAT=256,EBA_NV_COD_WARNING=1,EBA_NV_COD_IGN_SCHK=64,EBA_NV_COD_COUNTRY=8,EBA_NV_COD_STAT_OBJ=2,EBA_NV_COD_PRE_BRK=16,EBA_NV_COD_LOW_SPEED=4,EBA_NV_COD_BRK_COND=32,EBA_NV_COD_MAX=4294967295,EBA_NV_COD_PRE_BRK2=128,} */;

  typedef struct Fct_eba_algo_parameters_t
  {
    boolean CodingValid;                      /* EBA Coding Bits validity flag */
    EBACodingBitEnum_t CodingBits;            /* EBA Coding Bits */
    EBAPreBrkAccelParNv_t PreBrkParAccelTab;  /* PreBrake permitted acceleration over velocity */
  } Fct_eba_algo_parameters_t;  /* EBA Function Parameters */

  typedef struct Fct_algo_parameters_t
  {
    Fct_eba_algo_parameters_t Eba;            /* EBA Function Parameters */
    Fct_acc_algo_parameters_t Acc;            /* ACC Function Parameters */
    Fct_blockage_algo_parameters_t Blockage;  /* Blockage Function Parameters */
  } Fct_algo_parameters_t;    /* Function Parameters */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;       /* Number of used Version */
    Fct_algo_parameters_t Fct;    /* Function Parameters */
    Em_algo_parameters_t Em;      /* Environment Model Parameters */
    Aln_algo_parameters_t Aln;    /* Alignment settings */
  } BSW_s_AlgoParameters_t;   /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
};

//
// Unidentified subversion 2 of version 6 algo interface (?!)
//
namespace BSW_s_AlgoParameters_ARS4xx_V6_V2
{
  typedef struct Aln_algo_parameters_t
  {
    float f_ElevMonMaxDiff;
    float f_AzimMonMaxDiff;
    boolean b_ElevMonEnable;
    boolean b_AzimMonEnable;
    boolean b_EolChannelCalibEnable;
    boolean b_OnlineChannelCalibEnable;
    boolean b_OnlineAngleDevCalibEnable;
  } Aln_algo_parameters_t;    /* Alignment settings */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;      /* Number of used Version */
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_algo_parameters_t Fct;   /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Em_algo_parameters_t Em;     /* Environment Model Parameters */
    Aln_algo_parameters_t Aln;                                      /* Alignment settings */
  } BSW_s_AlgoParameters_t;   /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
};

//
// Unidentified subversion 3 of version 6 algo interface (?!)
//
namespace BSW_s_AlgoParameters_ARS4xx_V6_V3
{
  typedef struct Aln_algo_parameters_t
  {
    float f_MisalignCorrectionRange;
    float f_ElevMonMaxDiff;
    float f_AzimMonMaxDiff;
    boolean b_ElevMonEnable;
    boolean b_AzimMonEnable;
    boolean b_EolChannelCalibEnable;
    boolean b_OnlineChannelCalibEnable;
    boolean b_OnlineAngleDevCalibEnable;
  } Aln_algo_parameters_t;                                           /* Alignment settings */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_algo_parameters_t Fct;    /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Em_algo_parameters_t Em;      /* Environment Model Parameters */
    Aln_algo_parameters_t Aln;                                       /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
};

//
// Version 10 algo interface
//
namespace BSW_s_AlgoParameters_ARS4xx_V10
{
  typedef unsigned char FnSwitchBits_t                               /* General function switch bits @min: 1 @max:254 @values: enum { FN_AP_BIT_RESERVED=254,FN_AP_BIT_ABA_TEST_MODE=1,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char u_Dummy_array_t[3];                          /* dummy for 4-byte alignment */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    FnSwitchBits_t FnSwitchBits;
  } Fct_general_algo_par_t;                                          /* General function parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_eba_algo_parameters_t Eba;
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_acc_algo_parameters_t Acc;
    Fct_general_algo_par_t General;
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_blockage_algo_parameters_t Blockage;
  } Fct_algo_parameters_t;                                           /* Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_ElevMonMax;
    float f_AzimMonMax;
    float f_ElevEolMax;
    float f_AzimEolMax;
    float f_ElevMonMaxDiff;
    float f_AzimMonMaxDiff;
    boolean b_ElevMonEnable;
    boolean b_AzimMonEnable;
    boolean b_EolChannelCalibEnable;
    boolean b_OnlineChannelCalibEnable;
    boolean b_OnlineAngleDevCalibEnable;
    u_Dummy_array_t u_Dummy;
  } Aln_algo_parameters_t;                                           /* Alignment settings */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    Fct_algo_parameters_t Fct;                                       /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Em_algo_parameters_t Em;      /* Environment Model Parameters */
    Aln_algo_parameters_t Aln;                                       /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
};

// Version 13 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V13                            /* Length = 140 */
{
  typedef struct Em_lat_algo_parameters_t
  {
    boolean b_UseExternalYawRateLat;                                 /* Enable usage of external yaw rate latency. If disabled internal EM define (ODDELAY_f_yawRateObjLatency) is used. If enabled the value ds is used. */
    boolean b_UseExternalAxLat;                                      /* Enable usage of external latency longitudinal latency. If disabled internal EM define (ODDELAY_f_accelXObjLatency) is used. If enabled the value ds is used. */
    unsigned char u_YawRateObjLat;                                   /* If used the value replaces ODDELAY_f_yawRateObjLatency. 1LSB = 1ms @resolution:1.0 */
    unsigned char u_AccelXObjLat;                                    /* If used the value replaces ODDELAY_f_accelXObjLatency. 1LSB = 1ms @resolution:1.0 */
  } Em_lat_algo_parameters_t;

  typedef struct Em_algo_parameters_t
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Em_cem_algo_parameters_t Cem; /* Camera fusion parameters */
    Em_lat_algo_parameters_t Lat;                                    /* Ego dynamic latency parameters */
  } Em_algo_parameters_t;                                            /* Environment Model Parameters */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_algo_parameters_t Fct;                                       /* Function Parameters */
    Em_algo_parameters_t Em;      /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;                                       /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
};

namespace BSW_s_AlgoParameters_ARS4xx_V16                            /* Length = 140 !!! */
{
  typedef unsigned char CameraFusionPreselBits_t                     /* Camera fusion preselection parameters @min: 0 @max:255 @values: enum { ACC_PAR_FUSION_SEL_DEFAULT=0,ACC_PAR_FUSION_SEL_NO_BIKES=1,ACC_PAR_FUSION_SEL_MAX=255,ACC_PAR_FUSION_SEL_BIT6=32,ACC_PAR_FUSION_SEL_BIT7=64,ACC_PAR_FUSION_SEL_BIT4=8,ACC_PAR_FUSION_SEL_BIT5=16,ACC_PAR_FUSION_SEL_BIT2=2,ACC_PAR_FUSION_SEL_BIT3=4,ACC_PAR_FUSION_SEL_BIT8=128,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char NaviFusionPreselBits_t                       /* Navi fusion preselection parameters @min: 0 @max:255 @values: enum { ACC_NAV_FUSION_SEL_DEFAULT=0,ACC_NAV_FUSION_SEL_MAX=255,ACC_NAV_FUSION_SEL_TRAJ_FUSION=2,ACC_NAV_FUSION_SEL_BIT2=4,ACC_NAV_FUSION_SEL_BIT3=8,ACC_NAV_FUSION_SEL_COUNTRY_ROAD=1,ACC_NAV_FUSION_SEL_BIT5=32,ACC_NAV_FUSION_SEL_BIT6=64,ACC_NAV_FUSION_SEL_BIT7=128,ACC_NAV_FUSION_SEL_BIT4=16,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct Fct_acc_algo_parameters_t
  {
    CameraFusionPreselBits_t CameraFusionPreselBits;                 /* Camera fusion preselection parameters */
    NaviFusionPreselBits_t NaviFusionPreselBits;
  } Fct_acc_algo_parameters_t;                                       /* ACC Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_eba_algo_parameters_t Eba;
    Fct_acc_algo_parameters_t Acc;
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_general_algo_par_t General;
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_blockage_algo_parameters_t Blockage;
  } Fct_algo_parameters_t;                                           /* Function Parameters */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    Fct_algo_parameters_t Fct;                                       /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V13::Em_algo_parameters_t Em;        /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;      /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
};

// Version 19.1 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V19_1                          /* Length: PR=164, EN=160 */
{
  typedef float f32_ShutonRange_array_t[SYS_NUM_OF_SCANS];           /* @min:-500 */ /* [Satisfies_rte sws 1189] */
  typedef unsigned char ui8_UseFarNearScanForBlck_t                  /* 0 - Far or Near Scan (the Blockage Decision used the Max Probability value of the two Scans) 1 - only Near Scan 2 - only Far Scan 3 -  Far and Near Scan (the Blockage Decision used the Mean Probability value of the two Scans) @min: 0 @max:3 @values: enum { PD_USE_FUSED_FAR_NEAR=3,PD_USE_ONLY_FAR=2,PD_USE_MAX_FAR_NEAR=0,PD_USE_ONLY_NEAR=1,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f32_ShutoffRange;
    f32_ShutonRange_array_t f32_ShutonRange;
    float f32_ShutoffTime_Timeout;
    float f32_ShutoffWay_Timeout;
    unsigned char ui_ShutoffNoOfObjLosses;
    boolean b_BlockageActive;
    ui8_UseFarNearScanForBlck_t ui8_UseFarNearScanForBlck;
  } Fct_blockage_algo_parameters_t;                                  /* Blockage Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_eba_algo_parameters_t Eba;
    BSW_s_AlgoParameters_ARS4xx_V16::Fct_acc_algo_parameters_t Acc;
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_general_algo_par_t General;
    Fct_blockage_algo_parameters_t Blockage;
    signed char i8_BlockageHiTempThresh;
    signed char i8_BlockageLoTempThresh;
    unsigned char ui8_BlockageSpeedThreshold;
    unsigned char ui8_BlockageCamActivityFiltSize;
    unsigned char ui8_BlockageCamActivityFiltPos;
    unsigned char ui8_BlockageCamObjectFilterSize;
    unsigned char ui8_BlockageCamObjectFilterPos;
    unsigned char ui8_BlockageCamObjectThresh;
    signed char i8_BlockageCamTempThresh;
    unsigned char ui8_BlockageWiperCamThresh;
    unsigned char ui8_BlockageWiperThresh;
    boolean b_BlockageUseTemperature;
    boolean b_BlockageUseWiper;
    boolean b_BlockageUseWiperinCamera;
    boolean b_BlockageCamIntegrationActive;
  } Fct_algo_parameters_t;                                           /* Function Parameters */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    Fct_algo_parameters_t Fct;                                       /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V13::Em_algo_parameters_t Em;        /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;      /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V19_1

// Version 19.2 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V19_2                          /* Length: PR=176, EN=164 */
{
  typedef float f32_ShutoffRange_array_t[SYS_NUM_OF_SCANS];          /* @min:-500 */ /* [Satisfies_rte sws 1189] */
  typedef float f32_ShutonRange_array_t[SYS_NUM_OF_SCANS];           /* @min:-500 */ /* [Satisfies_rte sws 1189] */
  typedef boolean b_UseRoadbeam_array_t[SYS_NUM_OF_SCANS];                               /* Flag which defines if Roadbeam information is used in blockage. @min:0.1 */ /* [Satisfies_rte sws 1189] */
  typedef unsigned char ui8_RoadbeamSpeedMin_array_t[SYS_NUM_OF_SCANS];                  /* Speed Min threshold for use  Roadbeam information is used in blockage. 1LSB = 1km/h @min:-240 */	/* [Satisfies_rte sws 1189] */
  typedef unsigned char ui8_RoadVisibilityMin_array_t[SYS_NUM_OF_SCANS];                 /* Roadbeam – Visibility Threshold Trigger Road Detection [%] @min:-100 */	/* [Satisfies_rte sws 1189] */
  typedef unsigned char ui8_RoadQualityMin_array_t[SYS_NUM_OF_SCANS];                    /* Roadbeam – Visibility Quality Threshold Trigger Road Detection [%] @min:-100 */	/* [Satisfies_rte sws 1189] */
  typedef unsigned char ui8_UseFarNearScanForBlck_t                  /* 0 - Far or Near Scan (the Blockage Decision used the Max Probability value of the two Scans) 1 - only Near Scan 2 - only Far Scan 3 -  Far and Near Scan (the Blockage Decision used the Mean Probability value of the two Scans) @min: 0 @max:3 @values: enum { PD_USE_FUSED_FAR_NEAR=3,PD_USE_ONLY_FAR=2,PD_USE_MAX_FAR_NEAR=0,PD_USE_ONLY_NEAR=1,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    f32_ShutoffRange_array_t f32_ShutoffRange;                       /* NEW */
    f32_ShutonRange_array_t f32_ShutonRange;
    float f32_ShutoffTime_Timeout;
    float f32_ShutoffWay_Timeout;
    unsigned char ui_ShutoffNoOfObjLosses;
    boolean b_BlockageActive;
    b_UseRoadbeam_array_t b_UseRoadbeam;                             /* NEW */
    ui8_RoadbeamSpeedMin_array_t ui8_RoadbeamSpeedMin;               /* NEW */
    ui8_RoadVisibilityMin_array_t ui8_RoadVisibilityMin;             /* NEW */
    ui8_RoadQualityMin_array_t ui8_RoadQualityMin;                   /* NEW */
    ui8_UseFarNearScanForBlck_t ui8_UseFarNearScanForBlck;
    signed char i8_BlockageHiTempThresh;                             /* NEW */
    signed char i8_BlockageLoTempThresh;                             /* NEW */
    unsigned char ui8_BlockageSpeedThreshold;                        /* NEW */
    unsigned char ui8_BlockageCamActivityFiltSize;                   /* NEW */
    unsigned char ui8_BlockageCamActivityFiltPos;                    /* NEW */
    unsigned char ui8_BlockageCamObjectFilterSize;                   /* NEW */
    unsigned char ui8_BlockageCamObjectFilterPos;                    /* NEW */
    unsigned char ui8_BlockageCamObjectThresh;                       /* NEW */
    signed char i8_BlockageCamTempThresh;                            /* NEW */
    unsigned char ui8_BlockageWiperCamThresh;                        /* NEW */
    unsigned char ui8_BlockageWiperThresh;                           /* NEW */
    boolean b_BlockageUseTemperature;                                /* NEW */
    boolean b_BlockageUseWiper;                                      /* NEW */
    boolean b_BlockageUseWiperinCamera;                              /* NEW */
    boolean b_BlockageCamIntegrationActive;                          /* NEW */
  } Fct_blockage_algo_parameters_t;                                  /* Blockage Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_eba_algo_parameters_t Eba;
    BSW_s_AlgoParameters_ARS4xx_V16::Fct_acc_algo_parameters_t Acc;
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_general_algo_par_t General;
    Fct_blockage_algo_parameters_t Blockage;
  } Fct_algo_parameters_t;                                           /* Function Parameters */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    Fct_algo_parameters_t Fct;                                       /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V13::Em_algo_parameters_t Em;        /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;      /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V19_2

// Version 20 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V20                            /* Length = PR=168, EN=156 */
{
  typedef unsigned char e_MaxPickupDist_HiLo_Type_t                  /* Type definition for the maximal Pickup distance @min: 0 @max:1 @values: enum { ACC_HIGH=0,ACC_LOW=1,} */ /* [Satisfies_rte sws 1188] */;
  typedef float f32_ShutoffRange_array_t[SYS_NUM_OF_SCANS];          /* @min:-500 */ /* [Satisfies_rte sws 1189] */
  typedef float f32_ShutonRange_array_t[SYS_NUM_OF_SCANS];           /* @min:-500 */ /* [Satisfies_rte sws 1189] */
  typedef boolean b_UseRoadbeam_array_t[SYS_NUM_OF_SCANS];                               /* Flag which defines if Roadbeam information is used in blockage. @min:0.1 */ /* [Satisfies_rte sws 1189] */
  typedef unsigned char ui8_RoadbeamSpeedMin_array_t[SYS_NUM_OF_SCANS];                  /* Speed Min threshold for use  Roadbeam information is used in blockage. 1LSB = 1km/h @min:-240 */	/* [Satisfies_rte sws 1189] */
  typedef unsigned char ui8_RoadVisibilityMin_array_t[SYS_NUM_OF_SCANS];                 /* Roadbeam – Visibility Threshold Trigger Road Detection [%] @min:-100 */	/* [Satisfies_rte sws 1189] */
  typedef unsigned char ui8_RoadQualityMin_array_t[SYS_NUM_OF_SCANS];                    /* Roadbeam – Visibility Quality Threshold Trigger Road Detection [%] @min:-100 */	/* [Satisfies_rte sws 1189] */
  typedef unsigned char ui8_UseFarNearScanForBlck_t                  /* 0 - Far or Near Scan (the Blockage Decision used the Max Probability value of the two Scans) 1 - only Near Scan 2 - only Far Scan 3 -  Far and Near Scan (the Blockage Decision used the Mean Probability value of the two Scans) @min: 0 @max:3 @values: enum { PD_USE_FUSED_FAR_NEAR=3,PD_USE_ONLY_FAR=2,PD_USE_MAX_FAR_NEAR=0,PD_USE_ONLY_NEAR=1,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct Fct_acc_algo_parameters_t
  {
    BSW_s_AlgoParameters_ARS4xx_V16::CameraFusionPreselBits_t CameraFusionPreselBits;    /* Camera fusion preselection parameters */
    BSW_s_AlgoParameters_ARS4xx_V16::NaviFusionPreselBits_t NaviFusionPreselBits;
    e_MaxPickupDist_HiLo_Type_t e_MaxPickupDist_HiLo_Type;           /* NEW */
  } Fct_acc_algo_parameters_t;                                       /* ACC Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    f32_ShutoffRange_array_t f32_ShutoffRange;
    f32_ShutonRange_array_t f32_ShutonRange;
    float f32_ShutoffTime_Timeout;
    float f32_ShutoffWay_Timeout;
    unsigned char ui_ShutoffNoOfObjLosses;
    boolean b_BlockageActive;
    b_UseRoadbeam_array_t b_UseRoadbeam;                             /* NEW */
    ui8_RoadbeamSpeedMin_array_t ui8_RoadbeamSpeedMin;               /* NEW */
    ui8_RoadVisibilityMin_array_t ui8_RoadVisibilityMin;             /* NEW */
    ui8_RoadQualityMin_array_t ui8_RoadQualityMin;                   /* NEW */
    ui8_UseFarNearScanForBlck_t ui8_UseFarNearScanForBlck;
    signed char i8_BlockageHiTempThresh;                             /* NEW */
    signed char i8_BlockageLoTempThresh;                             /* NEW */
    unsigned char ui8_BlockageSpeedThreshold;                        /* NEW */
    unsigned char ui8_BlockageWiperThresh;                           /* NEW */
    boolean b_BlockageUseTemperature;                                /* NEW */
    boolean b_BlockageUseWiper;                                      /* NEW */
  } Fct_blockage_algo_parameters_t;                                  /* Blockage Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_eba_algo_parameters_t Eba;
    Fct_acc_algo_parameters_t Acc;
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_general_algo_par_t General;
    Fct_blockage_algo_parameters_t Blockage;
  } Fct_algo_parameters_t;                                           /* Function Parameters */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    Fct_algo_parameters_t Fct;                                       /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V13::Em_algo_parameters_t Em;        /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;      /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V20

// Version 21 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V21                            /* Length = PR=168, EN=156 */
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_eba_algo_parameters_t Eba;
    BSW_s_AlgoParameters_ARS4xx_V16::Fct_acc_algo_parameters_t Acc;
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_general_algo_par_t General;
    BSW_s_AlgoParameters_ARS4xx_V20::Fct_blockage_algo_parameters_t Blockage;
  } Fct_algo_parameters_t;                                           /* Function Parameters */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    Fct_algo_parameters_t Fct;                                       /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V13::Em_algo_parameters_t Em;        /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;      /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V21


// Version 23 algo interface for ARS4B0
namespace BSW_s_AlgoParameters_ARS4xx_V23                            /* Length = PR=180, (EN=168) */
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V19_2::f32_ShutoffRange_array_t f32_ShutoffRange;
    BSW_s_AlgoParameters_ARS4xx_V19_2::f32_ShutonRange_array_t f32_ShutonRange;
    float f32_ShutoffTime_Timeout;
    float f32_ShutoffWay_Timeout;
    unsigned char ui_ShutoffNoOfObjLosses;
    boolean b_BlockageActive;
    BSW_s_AlgoParameters_ARS4xx_V19_2::b_UseRoadbeam_array_t b_UseRoadbeam;
    BSW_s_AlgoParameters_ARS4xx_V19_2::ui8_RoadbeamSpeedMin_array_t ui8_RoadbeamSpeedMin;
    BSW_s_AlgoParameters_ARS4xx_V19_2::ui8_RoadVisibilityMin_array_t ui8_RoadVisibilityMin;
    BSW_s_AlgoParameters_ARS4xx_V19_2::ui8_RoadQualityMin_array_t ui8_RoadQualityMin;
    unsigned char ui8_UseFarNearScanForBlck;
    float f32_BlockageHiTempThreshFactor;                            /* NEW */
    signed char i8_BlockageHiTempThresh;
    signed char i8_BlockageLoTempThresh;
    unsigned char ui8_BlockageSpeedThreshold;
    unsigned char ui8_BlockageCamActivityFiltSize;
    unsigned char ui8_BlockageCamActivityFiltPos;
    unsigned char ui8_BlockageCamObjectFilterSize;
    unsigned char ui8_BlockageCamObjectFilterPos;
    unsigned char ui8_BlockageCamObjectThresh;
    signed char i8_BlockageCamTempThresh;
    unsigned char ui8_BlockageWiperCamThresh;
    unsigned char ui8_BlockageWiperThresh;
    boolean b_BlockageUseTemperature;
    boolean b_BlockageUseWiper;
    boolean b_BlockageUseWiperinCamera;
    boolean b_BlockageCamIntegrationActive;
  } Fct_blockage_algo_parameters_t;                                  /* Blockage Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_eba_algo_parameters_t Eba;
    BSW_s_AlgoParameters_ARS4xx_V16::Fct_acc_algo_parameters_t Acc;
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_general_algo_par_t General;
    Fct_blockage_algo_parameters_t Blockage;
  } Fct_algo_parameters_t;                                           /* Function Parameters */

  typedef struct
  {
    unsigned long uiVersionNumber;
    Fct_algo_parameters_t Fct;
    BSW_s_AlgoParameters_ARS4xx_V13::Em_algo_parameters_t Em;
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;
  } BSW_s_AlgoParameters_t;                                         /* Algo Parameters @vaddr:0x20900000 @vaddr_defs: BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V23

// Version 26 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V26                            /* Length = PR=172, EN=160 */
{
  typedef uint8 Em_Ped_ArtDummy_t                                    /* Switch to activate the Micro Doppler confirmation for crossing pedestrian detection. The switch will overwrite the custom dependent pre compiler switch CFG_EM_PED_TRAJ_ARTICULATED. If the project do not want to overwrite the project settings they should use EM_PED_ART_DUMMY_DEFAULT. Then the Algo will react as configured by the pre compiler switch. @min: 0 @max:2 @values: enum { EM_PED_ART_DUMMY_OFF=1,EM_PED_ART_DUMMY_ON=2,EM_PED_ART_DUMMY_DEFAULT=0,} */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V20::f32_ShutoffRange_array_t f32_ShutoffRange;
    BSW_s_AlgoParameters_ARS4xx_V20::f32_ShutonRange_array_t f32_ShutonRange;
    float f32_ShutoffTime_Timeout;
    float f32_ShutoffWay_Timeout;
    unsigned char ui_ShutoffNoOfObjLosses;
    boolean b_BlockageActive;
    BSW_s_AlgoParameters_ARS4xx_V20::b_UseRoadbeam_array_t b_UseRoadbeam;
    BSW_s_AlgoParameters_ARS4xx_V20::ui8_RoadbeamSpeedMin_array_t ui8_RoadbeamSpeedMin;
    BSW_s_AlgoParameters_ARS4xx_V20::ui8_RoadVisibilityMin_array_t ui8_RoadVisibilityMin;
    BSW_s_AlgoParameters_ARS4xx_V20::ui8_RoadQualityMin_array_t ui8_RoadQualityMin;
    BSW_s_AlgoParameters_ARS4xx_V20::ui8_UseFarNearScanForBlck_t ui8_UseFarNearScanForBlck;
    float f32_BlockageHiTempThreshFactor;                            /* a factor to define Temp threshold  for 2nd temperature flag new threshold is f32_BlockageHiTempThreshFactor *i8_BlockageHiTempThresh */
    signed char i8_BlockageHiTempThresh;
    signed char i8_BlockageLoTempThresh;
    unsigned char ui8_BlockageSpeedThreshold;
    unsigned char ui8_BlockageWiperThresh;
    boolean b_BlockageUseTemperature;
    boolean b_BlockageUseWiper;
  } Fct_blockage_algo_parameters_t;                                  /* Blockage Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_eba_algo_parameters_t Eba;
    BSW_s_AlgoParameters_ARS4xx_V16::Fct_acc_algo_parameters_t Acc;
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_general_algo_par_t General;
    Fct_blockage_algo_parameters_t Blockage;
  } Fct_algo_parameters_t;                                           /* Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    Em_Ped_ArtDummy_t ePedArtDummy;                                  /* Switch to activate the Micro Doppler confirmation for crossing pedestrian detection. The switch will overwrite the custom dependent pre compiler switch CFG_EM_PED_TRAJ_ARTICULATED. If the project do not want to overwrite the project settings they should use EM_PED_ART_DUMMY_DEFAULT. Then the Algo will react as configured by the pre compiler switch. */
  } Em_ped_algo_parameters_t;                                        /* Pedestrian detection parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Em_cem_algo_parameters_t Cem; /* Camera fusion parameters */
    BSW_s_AlgoParameters_ARS4xx_V13::Em_lat_algo_parameters_t Lat;   /* Ego dynamic latency parameters */
    Em_ped_algo_parameters_t Ped;                                    /* Pedestrian detection parameters */
  } Em_algo_parameters_t;                                            /* Environment Model Parameters */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    Fct_algo_parameters_t Fct;                                       /* Function Parameters */
    Em_algo_parameters_t Em;                                         /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;      /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V26

// Version 26 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V26_2                          /* Length = PR=180, EN=168 */
{
  typedef uint8 Em_Ped_ArtDummy_t                                    /* Switch to activate the Micro Doppler confirmation for crossing pedestrian detection. The switch will overwrite the custom dependent pre compiler switch CFG_EM_PED_TRAJ_ARTICULATED. If the project do not want to overwrite the project settings they should use EM_PED_ART_DUMMY_DEFAULT. Then the Algo will react as configured by the pre compiler switch. @min: 0 @max:2 @values: enum { EM_PED_ART_DUMMY_OFF=1,EM_PED_ART_DUMMY_ON=2,EM_PED_ART_DUMMY_DEFAULT=0,} */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V20::f32_ShutoffRange_array_t f32_ShutoffRange;
    BSW_s_AlgoParameters_ARS4xx_V20::f32_ShutonRange_array_t f32_ShutonRange;
    float f32_ShutoffTime_Timeout;
    float f32_ShutoffWay_Timeout;
    unsigned char ui_ShutoffNoOfObjLosses;
    boolean b_BlockageActive;
    BSW_s_AlgoParameters_ARS4xx_V20::b_UseRoadbeam_array_t b_UseRoadbeam;
    BSW_s_AlgoParameters_ARS4xx_V20::ui8_RoadbeamSpeedMin_array_t ui8_RoadbeamSpeedMin;
    BSW_s_AlgoParameters_ARS4xx_V20::ui8_RoadVisibilityMin_array_t ui8_RoadVisibilityMin;
    BSW_s_AlgoParameters_ARS4xx_V20::ui8_RoadQualityMin_array_t ui8_RoadQualityMin;
    BSW_s_AlgoParameters_ARS4xx_V20::ui8_UseFarNearScanForBlck_t ui8_UseFarNearScanForBlck;
    float f32_BlockageHiTempThreshFactor;                            /* a factor to define Temp threshold  for 2nd temperature flag new threshold is f32_BlockageHiTempThreshFactor *i8_BlockageHiTempThresh */
    signed char i8_BlockageHiTempThresh;
    signed char i8_BlockageLoTempThresh;
    unsigned char ui8_BlockageSpeedThreshold;
    unsigned char ui8_BlockageCamActivityFiltSize;                   /* New */
    unsigned char ui8_BlockageCamActivityFiltPos;                    /* New */
    unsigned char ui8_BlockageCamObjectFilterSize;                   /* New */
    unsigned char ui8_BlockageCamObjectFilterPos;                    /* New */
    unsigned char ui8_BlockageCamObjectThresh;                       /* New */
    signed char i8_BlockageCamTempThresh;                            /* New */
    unsigned char ui8_BlockageWiperCamThresh;                        /* New */
    unsigned char ui8_BlockageWiperThresh;
    boolean b_BlockageUseTemperature;
    boolean b_BlockageUseWiper;
  } Fct_blockage_algo_parameters_t;                                  /* Blockage Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_eba_algo_parameters_t Eba;
    BSW_s_AlgoParameters_ARS4xx_V16::Fct_acc_algo_parameters_t Acc;
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_general_algo_par_t General;
    Fct_blockage_algo_parameters_t Blockage;
  } Fct_algo_parameters_t;                                           /* Function Parameters */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    Fct_algo_parameters_t Fct;                                       /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V26::Em_algo_parameters_t Em;        /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;      /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V26_2

// Version 26 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V26_3                          /* Length = ARS510=128 */
{
#define RTE_TYPE_EBAPreBrkAccelTabNv_t
  typedef struct
  {
    VAR(float, TYPEDEF) Velo;
    VAR(float, TYPEDEF) Accel;
  } EBAPreBrkAccelTabNv_t;
  typedef VAR(EBAPreBrkAccelTabNv_t, TYPEDEF) AccelL1_array_t[4];
  typedef VAR(EBAPreBrkAccelTabNv_t, TYPEDEF) AccelL2_array_t[4];
  typedef VAR(float, TYPEDEF) f32_ShutoffRange_array_t[1];
  typedef VAR(float, TYPEDEF) f32_ShutonRange_array_t[1];
  typedef VAR(boolean, TYPEDEF) b_UseRoadbeam_array_t[1];
  typedef VAR(unsigned char, TYPEDEF) ui8_RoadbeamSpeedMin_array_t[1];
  typedef VAR(unsigned char, TYPEDEF) ui8_RoadVisibilityMin_array_t[1];
  typedef VAR(unsigned char, TYPEDEF) ui8_RoadQualityMin_array_t[1];
  typedef VAR(unsigned long, TYPEDEF) EBACodingBitEnum_t;
  typedef VAR(unsigned char, TYPEDEF) EBAPreBrkAccelParNvState_t;
  typedef struct
  {
    VAR(EBAPreBrkAccelParNvState_t, TYPEDEF) Valid;
    VAR(AccelL1_array_t, TYPEDEF) AccelL1;
    VAR(AccelL2_array_t, TYPEDEF) AccelL2;
  } EBAPreBrkAccelParNv_t;
  typedef struct
  {
    VAR(boolean, TYPEDEF) CodingValid;
    VAR(EBACodingBitEnum_t, TYPEDEF) CodingBits;
    VAR(EBAPreBrkAccelParNv_t, TYPEDEF) PreBrkParAccelTab;
  } Fct_eba_algo_parameters_t;
  typedef VAR(unsigned char, TYPEDEF) CameraFusionPreselBits_t;
  typedef VAR(unsigned char, TYPEDEF) NaviFusionPreselBits_t;
  typedef struct
  {
    VAR(CameraFusionPreselBits_t, TYPEDEF) CameraFusionPreselBits;
    VAR(NaviFusionPreselBits_t, TYPEDEF) NaviFusionPreselBits;
  } Fct_acc_algo_parameters_t;
  typedef VAR(unsigned char, TYPEDEF) FnSwitchBits_t;
  typedef struct
  {
    VAR(FnSwitchBits_t, TYPEDEF) FnSwitchBits;
  } Fct_general_algo_par_t;
  typedef VAR(unsigned char, TYPEDEF) ui8_UseFarNearScanForBlck_t;
  typedef struct
  {
    VAR(f32_ShutoffRange_array_t, TYPEDEF) f32_ShutoffRange;
    VAR(f32_ShutonRange_array_t, TYPEDEF) f32_ShutonRange;
    VAR(float, TYPEDEF) f32_ShutoffTime_Timeout;
    VAR(float, TYPEDEF) f32_ShutoffWay_Timeout;
    VAR(unsigned char, TYPEDEF) ui_ShutoffNoOfObjLosses;
    VAR(boolean, TYPEDEF) b_BlockageActive;
    VAR(b_UseRoadbeam_array_t, TYPEDEF) b_UseRoadbeam;
    VAR(ui8_RoadbeamSpeedMin_array_t, TYPEDEF) ui8_RoadbeamSpeedMin;
    VAR(ui8_RoadVisibilityMin_array_t, TYPEDEF) ui8_RoadVisibilityMin;
    VAR(ui8_RoadQualityMin_array_t, TYPEDEF) ui8_RoadQualityMin;
    VAR(ui8_UseFarNearScanForBlck_t, TYPEDEF) ui8_UseFarNearScanForBlck;
    VAR(float, TYPEDEF) f32_BlockageHiTempThreshFactor;
    VAR(signed char, TYPEDEF) i8_BlockageHiTempThresh;
    VAR(signed char, TYPEDEF) i8_BlockageLoTempThresh;
    VAR(unsigned char, TYPEDEF) ui8_BlockageSpeedThreshold;
    VAR(unsigned char, TYPEDEF) ui8_BlockageWiperThresh;
    VAR(boolean, TYPEDEF) b_BlockageUseTemperature;
    VAR(boolean, TYPEDEF) b_BlockageUseWiper;
  } Fct_blockage_algo_parameters_t;
  typedef struct
  {
    VAR(Fct_eba_algo_parameters_t, TYPEDEF) Eba;
    VAR(Fct_acc_algo_parameters_t, TYPEDEF) Acc;
    VAR(Fct_general_algo_par_t, TYPEDEF) General;
    VAR(Fct_blockage_algo_parameters_t, TYPEDEF) Blockage;
  } Fct_algo_parameters_t;
  typedef VAR(unsigned char, TYPEDEF) Em_cem_algo_sensor_state_t;
  typedef VAR(unsigned char, TYPEDEF) Em_cem_algo_mode_t;
  typedef struct
  {
    VAR(Em_cem_algo_sensor_state_t, TYPEDEF) eCEMParCodState;
    VAR(Em_cem_algo_sensor_state_t, TYPEDEF) eCEMParCldState;
    VAR(Em_cem_algo_mode_t, TYPEDEF) eCEMParModeSelection;
  } Em_cem_algo_parameters_t;
  typedef struct
  {
    VAR(boolean, TYPEDEF) b_UseExternalYawRateLat;
    VAR(boolean, TYPEDEF) b_UseExternalAxLat;
    VAR(unsigned char, TYPEDEF) u_YawRateObjLat;
    VAR(unsigned char, TYPEDEF) u_AccelXObjLat;
  } Em_lat_algo_parameters_t;
  typedef VAR(unsigned char, TYPEDEF) Em_Ped_ArtDummy_t;
  typedef struct
  {
    VAR(Em_Ped_ArtDummy_t, TYPEDEF) ePedArtDummy;
  } Em_ped_algo_parameters_t;
  typedef struct
  {
    VAR(Em_cem_algo_parameters_t, TYPEDEF) Cem;
    VAR(Em_lat_algo_parameters_t, TYPEDEF) Lat;
    VAR(Em_ped_algo_parameters_t, TYPEDEF) Ped;
  } Em_algo_parameters_t;
  typedef struct
  {
    VAR(unsigned long, TYPEDEF) uiVersionNumber;
    VAR(Fct_algo_parameters_t, TYPEDEF) Fct;
    VAR(Em_algo_parameters_t, TYPEDEF) Em;
  } BSW_s_AlgoParameters_t;

}; // end of BSW_s_AlgoParameters_ARS4xx_V26_3

// Version 27 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V27                            /* Length = PR=124, EN=160 */
{
  typedef float                     	f32_ShutoffRange_array_t[1];/* @min:-500 */	/* [Satisfies_rte sws 1189] */
  typedef float                     	f32_ShutoffRange_array_t[1];/* @min:-500 */	/* [Satisfies_rte sws 1189] */
  typedef boolean                   	b_UseRoadbeam_array_t[1];/* Flag which defines if Roadbeam information is used in blockage. @min:0.1 */	/* [Satisfies_rte sws 1189] */
  typedef unsigned char             	ui8_RoadbeamSpeedMin_array_t[1];/* Speed Min threshold for use  Roadbeam information is used in blockage. 1LSB = 1km/h @min:-240 */	/* [Satisfies_rte sws 1189] */
  typedef unsigned char             	ui8_RoadVisibilityMin_array_t[1];/* Roadbeam – Visibility Threshold Trigger Road Detection [%] @min:-100 */	/* [Satisfies_rte sws 1189] */
  typedef unsigned char             	ui8_RoadQualityMin_array_t[1];/* Roadbeam – Visibility Quality Threshold Trigger Road Detection [%] @min:-100 */	/* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    f32_ShutoffRange_array_t f32_ShutoffRange;
    f32_ShutoffRange_array_t f32_ShutonRange;
    float f32_ShutoffTime_Timeout;
    float f32_ShutoffWay_Timeout;
    unsigned char ui_ShutoffNoOfObjLosses;
    boolean b_BlockageActive;
    b_UseRoadbeam_array_t b_UseRoadbeam;
    ui8_RoadbeamSpeedMin_array_t ui8_RoadbeamSpeedMin;
    ui8_RoadVisibilityMin_array_t ui8_RoadVisibilityMin;
    ui8_RoadQualityMin_array_t ui8_RoadQualityMin;
    BSW_s_AlgoParameters_ARS4xx_V20::ui8_UseFarNearScanForBlck_t ui8_UseFarNearScanForBlck;
    float f32_BlockageHiTempThreshFactor;                            /* a factor to define Temp threshold  for 2nd temperature flag new threshold is f32_BlockageHiTempThreshFactor *i8_BlockageHiTempThresh */
    signed char i8_BlockageHiTempThresh;
    signed char i8_BlockageLoTempThresh;
    unsigned char ui8_BlockageSpeedThreshold;
    unsigned char ui8_BlockageWiperThresh;
    boolean b_BlockageUseTemperature;
    boolean b_BlockageUseWiper;
  } Fct_blockage_algo_parameters_t;                                  /* Blockage Function Parameters */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_eba_algo_parameters_t Eba;
    BSW_s_AlgoParameters_ARS4xx_V16::Fct_acc_algo_parameters_t Acc;
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_general_algo_par_t General;
    Fct_blockage_algo_parameters_t Blockage;
  } Fct_algo_parameters_t;                                           /* Function Parameters */

  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    Fct_algo_parameters_t Fct;                                       /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V26::Em_algo_parameters_t Em;                                         /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;      /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V27

// Version 31 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V31                            /* Length = PR=180, EN=168 */
{
  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    BSW_s_AlgoParameters_ARS4xx_V26_2::Fct_algo_parameters_t Fct;    /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V26::Em_algo_parameters_t Em;        /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;      /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V31

// Version 32 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V32                            /* Length = PR=180, EN=168 */
{
  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    BSW_s_AlgoParameters_ARS4xx_V26::Fct_algo_parameters_t Fct;      /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V26::Em_algo_parameters_t Em;        /* Environment Model Parameters */
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln;      /* Alignment settings */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V32

// Version 33 algo interface
namespace BSW_s_AlgoParameters_ARS4xx_V33                            /* ARS510: Length = 128, SRR520: Length = ??? */
{
  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    BSW_s_AlgoParameters_ARS4xx_V26::Fct_algo_parameters_t Fct;      /* Function Parameters */
    BSW_s_AlgoParameters_ARS4xx_V26::Em_algo_parameters_t Em;        /* Environment Model Parameters */
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
}; // end of BSW_s_AlgoParameters_ARS4xx_V33

// Generic ARS4xx & SRR3xx BSW_s_AlgoParameters_t                    Length =
// Holds all possible structure members from all possible namespaces
namespace BSW_s_AlgoParameters_ARS4xx_GenAll
{
  typedef struct BSW_s_AlgoParameters_t
  {
    uint32 uiVersionNumber;                                          /* Number of used Version */
    BSW_s_AlgoParameters_ARS4xx_V6_V1::Fct_algo_parameters_t Fct_V6_V1;
    BSW_s_AlgoParameters_ARS4xx_V10::Fct_algo_parameters_t Fct_V10;
    BSW_s_AlgoParameters_ARS4xx_V16::Fct_algo_parameters_t Fct_V16;
    BSW_s_AlgoParameters_ARS4xx_V19_1::Fct_algo_parameters_t Fct_V19_1;
    BSW_s_AlgoParameters_ARS4xx_V19_2::Fct_algo_parameters_t Fct_V19_2;
    BSW_s_AlgoParameters_ARS4xx_V20::Fct_algo_parameters_t Fct_V20;
    BSW_s_AlgoParameters_ARS4xx_V21::Fct_algo_parameters_t Fct_V21;
    BSW_s_AlgoParameters_ARS4xx_V23::Fct_algo_parameters_t Fct_V23;
    BSW_s_AlgoParameters_ARS4xx_V26::Fct_algo_parameters_t Fct_V26;
    BSW_s_AlgoParameters_ARS4xx_V26_2::Fct_algo_parameters_t Fct_V26_2;
    //BSW_s_AlgoParameters_ARS4xx_V26_3::Fct_algo_parameters_t Fct_V26_3;
    BSW_s_AlgoParameters_ARS4xx_V27::Fct_algo_parameters_t Fct_V27;

    BSW_s_AlgoParameters_ARS4xx_V6_V1::Em_algo_parameters_t Em_V6_V1;
    BSW_s_AlgoParameters_ARS4xx_V13::Em_algo_parameters_t Em_V13;
    BSW_s_AlgoParameters_ARS4xx_V26::Em_algo_parameters_t Em_V26;
    //BSW_s_AlgoParameters_ARS4xx_V26_3::Em_algo_parameters_t Em_V26_3;

    BSW_s_AlgoParameters_ARS4xx_V6_V1::Aln_algo_parameters_t Aln_V6_V1;
    BSW_s_AlgoParameters_ARS4xx_V6_V2::Aln_algo_parameters_t Aln_V6_V2;
    BSW_s_AlgoParameters_ARS4xx_V6_V3::Aln_algo_parameters_t Aln_V6_V3;
    BSW_s_AlgoParameters_ARS4xx_V10::Aln_algo_parameters_t Aln_V10;
  } BSW_s_AlgoParameters_t;                                          /* Algo Parameters @vaddr:BSW_ALGOPARAMETERS_VADDR @cycleid:EM_ENV @vname:BSW_s_AlgoParameters */
};


class CConvBSWAlgoParameters : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  /*
  static const char* DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t m_BufGen;
  BSW_s_AlgoParameters_ARS4xx_V6_V1::BSW_s_AlgoParameters_t m_BufV6_1;
  BSW_s_AlgoParameters_ARS4xx_V6_V2::BSW_s_AlgoParameters_t m_BufV6_2;
  BSW_s_AlgoParameters_ARS4xx_V6_V3::BSW_s_AlgoParameters_t m_BufV6_3;
  BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t m_BufV10;
  BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t m_BufV13;
  BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t m_BufV16;
  BSW_s_AlgoParameters_ARS4xx_V19_1::BSW_s_AlgoParameters_t m_BufV19_1;
  BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t m_BufV19_2;
  BSW_s_AlgoParameters_ARS4xx_V20::BSW_s_AlgoParameters_t m_BufV20;
  BSW_s_AlgoParameters_ARS4xx_V21::BSW_s_AlgoParameters_t m_BufV21;
  BSW_s_AlgoParameters_ARS4xx_V23::BSW_s_AlgoParameters_t m_BufV23;
  BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t m_BufV26;
  BSW_s_AlgoParameters_ARS4xx_V26_2::BSW_s_AlgoParameters_t m_BufV26_2;
  BSW_s_AlgoParameters_ARS4xx_V26_3::BSW_s_AlgoParameters_t m_BufV26_3;
  BSW_s_AlgoParameters_ARS4xx_V27::BSW_s_AlgoParameters_t m_BufV27;
  BSW_s_AlgoParameters_ARS4xx_V31::BSW_s_AlgoParameters_t m_BufV31;
  BSW_s_AlgoParameters_ARS4xx_V32::BSW_s_AlgoParameters_t m_BufV32;
  BSW_s_AlgoParameters_ARS4xx_V33::BSW_s_AlgoParameters_t m_BufV33;

  static void InitGen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Params);
  static void InitV6_1(BSW_s_AlgoParameters_ARS4xx_V6_V1::BSW_s_AlgoParameters_t & Params);
  static void InitV6_2(BSW_s_AlgoParameters_ARS4xx_V6_V2::BSW_s_AlgoParameters_t & Params);
  static void InitV6_3(BSW_s_AlgoParameters_ARS4xx_V6_V3::BSW_s_AlgoParameters_t & Params);
  static void InitV10(BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t & Params);
  static void InitV13(BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t & Params);
  static void InitV16(BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t & Params);
  static void InitV19_1(BSW_s_AlgoParameters_ARS4xx_V19_1::BSW_s_AlgoParameters_t & Params);
  static void InitV19_2(BSW_s_AlgoParameters_ARS4xx_V19_2::Fct_algo_parameters_t & Params);
  static void InitV19_2(BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t & Params);
  static void InitV20(BSW_s_AlgoParameters_ARS4xx_V20::Fct_algo_parameters_t & Params);
  static void InitV20(BSW_s_AlgoParameters_ARS4xx_V20::BSW_s_AlgoParameters_t & Params);
  static void InitV21(BSW_s_AlgoParameters_ARS4xx_V21::Fct_algo_parameters_t & Params);
  static void InitV21(BSW_s_AlgoParameters_ARS4xx_V21::BSW_s_AlgoParameters_t & Params);
  static void InitV23(BSW_s_AlgoParameters_ARS4xx_V23::Fct_algo_parameters_t & Params);            // Init Part Fct of BSW_s_AlgoParameters_ARS4xx_V23
  static void InitV23(BSW_s_AlgoParameters_ARS4xx_V23::BSW_s_AlgoParameters_t & Params);
  static void InitV26(BSW_s_AlgoParameters_ARS4xx_V26::Fct_algo_parameters_t & Params);
  static void InitV26(BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t & Params);
  static void InitV26_2(BSW_s_AlgoParameters_ARS4xx_V26_2::Fct_algo_parameters_t & Params);
  static void InitV26_2(BSW_s_AlgoParameters_ARS4xx_V26_2::BSW_s_AlgoParameters_t & Params);
  static void InitV26_3(BSW_s_AlgoParameters_ARS4xx_V26_3::Fct_algo_parameters_t & Params);
  static void InitV26_3(BSW_s_AlgoParameters_ARS4xx_V26_3::BSW_s_AlgoParameters_t & Params);
  static void InitV27(BSW_s_AlgoParameters_ARS4xx_V27::Fct_algo_parameters_t & Params);
  static void InitV27(BSW_s_AlgoParameters_ARS4xx_V27::BSW_s_AlgoParameters_t & Params);
  static void InitV31(BSW_s_AlgoParameters_ARS4xx_V31::BSW_s_AlgoParameters_t & Params);
  static void InitV32(BSW_s_AlgoParameters_ARS4xx_V32::BSW_s_AlgoParameters_t & Params);
  static void InitV33(BSW_s_AlgoParameters_ARS4xx_V33::BSW_s_AlgoParameters_t & Params);

  static void Convert_V6_V1_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V6_V1::BSW_s_AlgoParameters_t & Src);
  static void Convert_V6_V2_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V6_V2::BSW_s_AlgoParameters_t & Src);
  static void Convert_V6_V3_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V6_V3::BSW_s_AlgoParameters_t & Src);
  static void Convert_V10_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t & Src);
  static void Convert_V13_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t & Src);
  static void Convert_V16_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t & Src);
  static void Convert_V19_1_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V19_1::BSW_s_AlgoParameters_t & Src);
  static void Convert_V19_2_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t & Src);
  static void Convert_V20_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V20::BSW_s_AlgoParameters_t & Src);
  static void Convert_V21_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V21::BSW_s_AlgoParameters_t & Src);
  static void Convert_V23_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V23::BSW_s_AlgoParameters_t & Src);
  static void Convert_V26_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t & Src);
  static void Convert_V26_2_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V26_2::BSW_s_AlgoParameters_t & Src);
  static void Convert_V26_3_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V26_3::BSW_s_AlgoParameters_t & Src);
  static void Convert_V27_1_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V27::BSW_s_AlgoParameters_t & Src);
  static void Convert_V31_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V31::BSW_s_AlgoParameters_t & Src);
  static void Convert_V32_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V32::BSW_s_AlgoParameters_t & Src);
  static void Convert_V33_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V33::BSW_s_AlgoParameters_t & Src);

  static void Convert_Gen_to_V6_V1(BSW_s_AlgoParameters_ARS4xx_V6_V1::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V6_V2(BSW_s_AlgoParameters_ARS4xx_V6_V2::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V6_V3(BSW_s_AlgoParameters_ARS4xx_V6_V3::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V10(BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V13(BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V16(BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V19_1(BSW_s_AlgoParameters_ARS4xx_V19_1::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V19_2(BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V20(BSW_s_AlgoParameters_ARS4xx_V20::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V21(BSW_s_AlgoParameters_ARS4xx_V21::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V23(BSW_s_AlgoParameters_ARS4xx_V23::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V26(BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V26_2(BSW_s_AlgoParameters_ARS4xx_V26_2::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V26_3(BSW_s_AlgoParameters_ARS4xx_V26_3::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V27(BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V27_1(BSW_s_AlgoParameters_ARS4xx_V27::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V31(BSW_s_AlgoParameters_ARS4xx_V31::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V32(BSW_s_AlgoParameters_ARS4xx_V32::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
  static void Convert_Gen_to_V33(BSW_s_AlgoParameters_ARS4xx_V33::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src);
public:

  static const char* GetConverterTypeName()
  {
    return "BSWAlgoParameters";
  }

  CConvBSWAlgoParameters(void);
  virtual ~CConvBSWAlgoParameters(void);

  const char* GetTypeName()
  {
    return GetConverterTypeName();
  }

  void Destroy()
  {
    delete this;
  }

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo,
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void** pDefaultData, unsigned long& ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo);
private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION6;
  static CVersionInfoImpl VERSION10;
  static CVersionInfoImpl VERSION12;
  static CVersionInfoImpl VERSION13;
  static CVersionInfoImpl VERSION14;
  static CVersionInfoImpl VERSION16;
  static CVersionInfoImpl VERSION18;
  static CVersionInfoImpl VERSION19;
  static CVersionInfoImpl VERSION20;
  static CVersionInfoImpl VERSION21;
  static CVersionInfoImpl VERSION23;
  static CVersionInfoImpl VERSION25;
  static CVersionInfoImpl VERSION26;
  static CVersionInfoImpl VERSION27;
  static CVersionInfoImpl VERSION31;
  static CVersionInfoImpl VERSION32;
  static CVersionInfoImpl VERSION33;

  enum BSWAlgoParameters
  {
    BSW_ALGO_PARAM_RTE_V6_1,
    BSW_ALGO_PARAM_RTE_V6_2,
    BSW_ALGO_PARAM_RTE_V6_3,
    BSW_ALGO_PARAM_RTE_V10,
    BSW_ALGO_PARAM_RTE_V12,
    BSW_ALGO_PARAM_RTE_V13,
    BSW_ALGO_PARAM_RTE_V14,
    BSW_ALGO_PARAM_RTE_V16,
    BSW_ALGO_PARAM_RTE_V18,
    BSW_ALGO_PARAM_RTE_V19_1,
    BSW_ALGO_PARAM_RTE_V19_2,
    BSW_ALGO_PARAM_RTE_V20_1,
    BSW_ALGO_PARAM_RTE_V20_2,
    BSW_ALGO_PARAM_RTE_V21,
    BSW_ALGO_PARAM_RTE_V23,
    BSW_ALGO_PARAM_RTE_V25,
    BSW_ALGO_PARAM_RTE_V26,
    BSW_ALGO_PARAM_RTE_V26_2,
    BSW_ALGO_PARAM_RTE_V27,
    BSW_ALGO_PARAM_RTE_V26_3,
    BSW_ALGO_PARAM_RTE_V27_1,
    BSW_ALGO_PARAM_RTE_V31,
    BSW_ALGO_PARAM_RTE_V32,
    BSW_ALGO_PARAM_RTE_V33,
    BSW_ALGO_PARAM_VERSION_COUNT
  };

  static const CVersionInfoImpl * const A_VERSIONS[BSW_ALGO_PARAM_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[BSW_ALGO_PARAM_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo * pPortVersion) const;

};

CVersionInfoImpl CConvBSWAlgoParameters::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION6(0, 0, 6);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION10(0, 0, 10);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION12(0, 0, 12);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION13(0, 0, 13);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION14(0, 0, 14);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION16(0, 0, 16);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION18(0, 0, 18);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION19(0, 0, 19);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION20(0, 0, 20);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION21(0, 0, 21);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION23(0, 0, 23);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION25(0, 0, 25);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION26(0, 0, 26);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION27(0, 0, 27);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION31(0, 0, 31);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION32(0, 0, 32);
CVersionInfoImpl CConvBSWAlgoParameters::VERSION33(0, 0, 33);

const CVersionInfoImpl * const CConvBSWAlgoParameters::A_VERSIONS[BSW_ALGO_PARAM_VERSION_COUNT] =
{
  &VERSION6,
  &VERSION6,
  &VERSION6,
  &VERSION10,
  &VERSION12,
  &VERSION13,
  &VERSION14,
  &VERSION16,
  &VERSION18,
  &VERSION19,
  &VERSION19,
  &VERSION20,
  &VERSION20,
  &VERSION21,
  &VERSION23,
  &VERSION25,
  &VERSION26,
  &VERSION26,
  &VERSION27,
  &VERSION26,
  &VERSION27,
  &VERSION31,
  &VERSION32,
  &VERSION33
};

const unsigned long CConvBSWAlgoParameters::SUPPORTED_SIZE[CConvBSWAlgoParameters::BSW_ALGO_PARAM_VERSION_COUNT] =
{
  sizeof(BSW_s_AlgoParameters_ARS4xx_V6_V1::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V6_V2::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V6_V3::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V19_1::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V20::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V21::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V23::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V26_2::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V26_3::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V27::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V31::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V32::BSW_s_AlgoParameters_t),
  sizeof(BSW_s_AlgoParameters_ARS4xx_V33::BSW_s_AlgoParameters_t)
};

CConvBSWAlgoParameters::CConvBSWAlgoParameters(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV6_1(), m_BufV6_2(), m_BufV6_3(), m_BufV10(), m_BufV13(), m_BufV16(), m_BufV19_1(), m_BufV19_2(), m_BufV20(), m_BufV21(), m_BufV23(), m_BufV26(), m_BufV26_2(), m_BufV26_3(), m_BufV27(), m_BufV31(), m_BufV32()
{
}

CConvBSWAlgoParameters::~CConvBSWAlgoParameters(void)
{
}

bool CConvBSWAlgoParameters::IsPortSupported(unsigned long ulPortSize, const IVersionInfo * pPortVersion) const
{
  for (int nI=0; nI<BSW_ALGO_PARAM_VERSION_COUNT; nI++)
  {
    if ((pPortVersion == NULL) ||
      (pPortVersion->Equals(&BASE_VERSION)) ||
      (pPortVersion->Equals(A_VERSIONS[nI])))
    {
      if (ulPortSize == SUPPORTED_SIZE[nI])
      {
        return true;
      }
      else if ((nI == 4) || (nI == 5))
      {
        // Special case where Version number is 13 and length is 136
        if (ulPortSize == SUPPORTED_SIZE[nI-1])
        {
          return true;
        }
      }
    }
  }
  return false;
};

void CConvBSWAlgoParameters::InitGen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
}

void CConvBSWAlgoParameters::InitV6_1(BSW_s_AlgoParameters_ARS4xx_V6_V1::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 6u;
  // EBA
  Params.Fct.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Fct.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Fct.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Fct.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  // Blockage
  Params.Fct.Blockage.f32_ShutoffRange        = 95;   /* @min:0 @max:200.0 */
  Params.Fct.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Fct.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Fct.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Fct.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  // EM
  Params.Em.Cem.eCEMParCodState       = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState       = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection  = 0;  // CEM_PAR_ME_SEL_NO
  // ALN
  Params.Aln.f_ElevMonMaxDiff   = DEG2RAD(4); /* maximum allowed difference between last Eol/service alignment value and monitoring value and monitoring values in elevation (if exceeded DEM event is sent) */
  Params.Aln.f_AzimMonMaxDiff   = DEG2RAD(6); /* maximum allowed difference between last Eol/service alignment value and monitoring value and monitoring values in azimuth (if exceeded DEM event is sent) */
  Params.Aln.b_ElevMonEnable    = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable    = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
}

void CConvBSWAlgoParameters::InitV6_2(BSW_s_AlgoParameters_ARS4xx_V6_V2::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 6u;
  // EBA
  Params.Fct.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Fct.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Fct.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Fct.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  // Blockage
  Params.Fct.Blockage.f32_ShutoffRange        = 95;   /* @min:0 @max:200.0 */
  Params.Fct.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Fct.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Fct.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Fct.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  // EM
  Params.Em.Cem.eCEMParCodState       = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState       = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection  = 0;  // CEM_PAR_ME_SEL_NO
  // ALN
  Params.Aln.f_ElevMonMaxDiff             = DEG2RAD(4); /* maximum allowed difference between last Eol/service alignment value and monitoring value and monitoring values in elevation (if exceeded DEM event is sent) */
  Params.Aln.f_AzimMonMaxDiff             = DEG2RAD(6); /* maximum allowed difference between last Eol/service alignment value and monitoring value and monitoring values in azimuth (if exceeded DEM event is sent) */
  Params.Aln.b_ElevMonEnable              = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable              = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable      = 1;
  Params.Aln.b_OnlineChannelCalibEnable   = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable  = 1;
}

void CConvBSWAlgoParameters::InitV6_3(BSW_s_AlgoParameters_ARS4xx_V6_V3::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 6u;
  // EBA
  Params.Fct.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Fct.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Fct.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Fct.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  // Blockage
  Params.Fct.Blockage.f32_ShutoffRange        = 95;   /* @min:0 @max:200.0 */
  Params.Fct.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Fct.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Fct.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Fct.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  // EM
  Params.Em.Cem.eCEMParCodState       = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState       = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection  = 0;  // CEM_PAR_ME_SEL_NO
  // ALN
  Params.Aln.f_MisalignCorrectionRange    = DEG2RAD(6); /* from aln_algoparameters.par V1.2 */
  Params.Aln.f_ElevMonMaxDiff             = DEG2RAD(4); /* maximum allowed difference between last Eol/service alignment value and monitoring value and monitoring values in elevation (if exceeded DEM event is sent) */
  Params.Aln.f_AzimMonMaxDiff             = DEG2RAD(6); /* maximum allowed difference between last Eol/service alignment value and monitoring value and monitoring values in azimuth (if exceeded DEM event is sent) */
  Params.Aln.b_ElevMonEnable              = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable              = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable      = 1;
  Params.Aln.b_OnlineChannelCalibEnable   = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable  = 1;
}

void CConvBSWAlgoParameters::InitV10(BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 10u;
  // EBA
  Params.Fct.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Fct.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Fct.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Fct.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  // General
  Params.Fct.General.FnSwitchBits             = 0;
  // Blockage
  Params.Fct.Blockage.f32_ShutoffRange        = 95;   /* @min:0 @max:200.0 */
  Params.Fct.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Fct.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Fct.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Fct.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  // EM
  Params.Em.Cem.eCEMParCodState       = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState       = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection  = 0;  // CEM_PAR_ME_SEL_NO
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV13(BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 13u;
  // EBA
  Params.Fct.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Fct.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Fct.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Fct.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  // General
  Params.Fct.General.FnSwitchBits             = 0;
  // Blockage
  Params.Fct.Blockage.f32_ShutoffRange        = 95;   /* @min:0 @max:200.0 */
  Params.Fct.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Fct.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Fct.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Fct.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV16(BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 16u;
  // EBA
  Params.Fct.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Fct.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Fct.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Fct.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  Params.Fct.Acc.NaviFusionPreselBits         = 0;
  // General
  Params.Fct.General.FnSwitchBits             = 0;
  // Blockage
  Params.Fct.Blockage.f32_ShutoffRange        = 95;   /* @min:0 @max:200.0 */
  Params.Fct.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Fct.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Fct.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Fct.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV19_1(BSW_s_AlgoParameters_ARS4xx_V19_1::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 19u;
  // EBA
  Params.Fct.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Fct.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Fct.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Fct.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Fct.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  Params.Fct.Acc.NaviFusionPreselBits         = 0;
  // General
  Params.Fct.General.FnSwitchBits             = 0;
  // Blockage
  Params.Fct.Blockage.f32_ShutoffRange        = 95;   /* @min:0 @max:200.0 */
  Params.Fct.Blockage.f32_ShutonRange[0]      = 175;
  if (SYS_NUM_OF_SCANS>1)
  {
    Params.Fct.Blockage.f32_ShutonRange[1]    = 350;
  }
  Params.Fct.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Fct.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Fct.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Fct.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  Params.Fct.Blockage.ui8_UseFarNearScanForBlck = 0;
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV19_2(BSW_s_AlgoParameters_ARS4xx_V19_2::Fct_algo_parameters_t & Params)
{
  // EBA
  Params.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  Params.Acc.NaviFusionPreselBits         = 0;
  // General
  Params.General.FnSwitchBits             = 0;
  // Blockage
  Params.Blockage.f32_ShutoffRange[0]     = 120;  /* @min:0 @max:200.0 */
  Params.Blockage.f32_ShutonRange[0]      = 175;  /* @min:0 @max:200.0 */
  Params.Blockage.b_UseRoadbeam[0]        = 0;
  Params.Blockage.ui8_RoadbeamSpeedMin[0] = 10;
  Params.Blockage.ui8_RoadVisibilityMin[0] = 80;
  Params.Blockage.ui8_RoadQualityMin[0]   = 40;
  if (SYS_NUM_OF_SCANS>1)
  {
    Params.Blockage.f32_ShutoffRange[1]   = 240;  /* @min:0 @max:200.0 */
    Params.Blockage.f32_ShutonRange[1]    = 350;  /* @min:0 @max:500.0 */
    Params.Blockage.b_UseRoadbeam[1]      = 1;
    Params.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
    Params.Blockage.ui8_RoadVisibilityMin[1] = 80;
    Params.Blockage.ui8_RoadQualityMin[1] = 40;
  }
  Params.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  Params.Blockage.i8_BlockageHiTempThresh = 5;
  Params.Blockage.i8_BlockageLoTempThresh = -10;
  Params.Blockage.ui8_BlockageSpeedThreshold = 15;
  Params.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Params.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Params.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Params.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Params.Blockage.ui8_BlockageCamObjectThresh = 1;
  Params.Blockage.i8_BlockageCamTempThresh = 5;
  Params.Blockage.ui8_BlockageWiperCamThresh = 43;
  Params.Blockage.ui8_BlockageWiperThresh = 43;
  Params.Blockage.b_BlockageUseTemperature = 0;
  Params.Blockage.b_BlockageUseWiper = 0;
  Params.Blockage.b_BlockageUseWiperinCamera = 1;
  Params.Blockage.b_BlockageCamIntegrationActive = 1;
}

void CConvBSWAlgoParameters::InitV19_2(BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 19u;
  // FCT
  InitV19_2(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV20(BSW_s_AlgoParameters_ARS4xx_V20::Fct_algo_parameters_t & Params)
{
  // EBA
  Params.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  Params.Acc.NaviFusionPreselBits         = 0;
  Params.Acc.e_MaxPickupDist_HiLo_Type    = 0;
  // General
  Params.General.FnSwitchBits             = 0;
  // Blockage
  Params.Blockage.f32_ShutoffRange[0]     = 120;  /* @min:0 @max:200.0 */
  Params.Blockage.f32_ShutonRange[0]      = 175;  /* @min:0 @max:200.0 */
  Params.Blockage.b_UseRoadbeam[0]        = 0;
  Params.Blockage.ui8_RoadbeamSpeedMin[0] = 10;
  Params.Blockage.ui8_RoadVisibilityMin[0] = 80;
  Params.Blockage.ui8_RoadQualityMin[0]   = 40;
  if (SYS_NUM_OF_SCANS>1)
  {
    Params.Blockage.f32_ShutoffRange[1]   = 240;  /* @min:0 @max:200.0 */
    Params.Blockage.f32_ShutonRange[1]    = 350;  /* @min:0 @max:200.0 */
    Params.Blockage.b_UseRoadbeam[1]      = 1;
    Params.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
    Params.Blockage.ui8_RoadVisibilityMin[1] = 80;
    Params.Blockage.ui8_RoadQualityMin[1] = 40;
  }
  Params.Blockage.ui8_UseFarNearScanForBlck = 0;
  Params.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  Params.Blockage.i8_BlockageHiTempThresh = 5;
  Params.Blockage.i8_BlockageLoTempThresh = -10;
  Params.Blockage.ui8_BlockageSpeedThreshold = 15;
  Params.Blockage.ui8_BlockageWiperThresh = 43;
  Params.Blockage.b_BlockageUseTemperature = 0;
  Params.Blockage.b_BlockageUseWiper = 0;
}

void CConvBSWAlgoParameters::InitV20(BSW_s_AlgoParameters_ARS4xx_V20::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 20u;
  // FCT
  InitV20(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV21(BSW_s_AlgoParameters_ARS4xx_V21::Fct_algo_parameters_t & Params)
{
  BSW_s_AlgoParameters_ARS4xx_V20::Fct_algo_parameters_t *Param2 = reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V20::Fct_algo_parameters_t*>(&Params);
  InitV20(*Param2);
}

void CConvBSWAlgoParameters::InitV21(BSW_s_AlgoParameters_ARS4xx_V21::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 21u;
  // FCT
  InitV21(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV23(BSW_s_AlgoParameters_ARS4xx_V23::Fct_algo_parameters_t &Params)
{
  // EBA
  Params.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  Params.Acc.NaviFusionPreselBits         = 0;
  // General
  Params.General.FnSwitchBits             = 0;
  // Blockage
  Params.Blockage.f32_ShutoffRange[0]     = 120;  /* @min:0 @max:200.0 */
  Params.Blockage.f32_ShutonRange[0]      = 175;  /* @min:0 @max:200.0 */
  Params.Blockage.b_UseRoadbeam[0]        = 0;
  Params.Blockage.ui8_RoadbeamSpeedMin[0] = 10;
  Params.Blockage.ui8_RoadVisibilityMin[0] = 80;
  Params.Blockage.ui8_RoadQualityMin[0]   = 40;
  if (SYS_NUM_OF_SCANS>1)
  {
    Params.Blockage.f32_ShutoffRange[1]   = 240;  /* @min:0 @max:200.0 */
    Params.Blockage.f32_ShutonRange[1]    = 350;  /* @min:0 @max:200.0 */
    Params.Blockage.b_UseRoadbeam[1]      = 1;
    Params.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
    Params.Blockage.ui8_RoadVisibilityMin[1] = 80;
    Params.Blockage.ui8_RoadQualityMin[1] = 40;
  }
  Params.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  Params.Blockage.ui8_UseFarNearScanForBlck = 0;
  Params.Blockage.f32_BlockageHiTempThreshFactor = 2.0f;
  Params.Blockage.i8_BlockageHiTempThresh = 5;
  Params.Blockage.i8_BlockageLoTempThresh = -10;
  Params.Blockage.ui8_BlockageSpeedThreshold = 15;
  Params.Blockage.ui8_BlockageCamActivityFiltSize= 15;
  Params.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Params.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Params.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Params.Blockage.ui8_BlockageCamObjectThresh = 1;
  Params.Blockage.i8_BlockageCamTempThresh = 5;
  Params.Blockage.ui8_BlockageWiperCamThresh = 43;
  Params.Blockage.ui8_BlockageWiperThresh = 43;
  Params.Blockage.b_BlockageUseTemperature = 1;
  Params.Blockage.b_BlockageUseWiper = 0;
  Params.Blockage.b_BlockageUseWiperinCamera = 1;
  Params.Blockage.b_BlockageCamIntegrationActive = 1;
}

void CConvBSWAlgoParameters::InitV23(BSW_s_AlgoParameters_ARS4xx_V23::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 23u;
  // FCT
  InitV23(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV26(BSW_s_AlgoParameters_ARS4xx_V26::Fct_algo_parameters_t & Params)
{
  // EBA
  Params.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  Params.Acc.NaviFusionPreselBits         = 0;
  // General
  Params.General.FnSwitchBits             = 0;
  // Blockage
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Params.Blockage.f32_ShutoffRange[0] = 120.f * (nI + 1);  /* @min:0 @max:200.0 */
    Params.Blockage.f32_ShutonRange[nI] = 175.f * (nI + 1);
    Params.Blockage.b_UseRoadbeam[nI] = nI;
    Params.Blockage.ui8_RoadbeamSpeedMin[nI] = 10;
    Params.Blockage.ui8_RoadVisibilityMin[nI] = 80;
    Params.Blockage.ui8_RoadQualityMin[nI] = 40;
  }
  Params.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  Params.Blockage.f32_BlockageHiTempThreshFactor = 2.f;
  Params.Blockage.i8_BlockageHiTempThresh = 5;
  Params.Blockage.i8_BlockageLoTempThresh = -10;
  Params.Blockage.ui8_BlockageSpeedThreshold = 15;
  Params.Blockage.ui8_BlockageWiperThresh = 43;
  Params.Blockage.b_BlockageUseTemperature = 0;
  Params.Blockage.b_BlockageUseWiper      = 0;
}

void CConvBSWAlgoParameters::InitV26(BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 26u;
  // FCT
  InitV26(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  Params.Em.Ped.ePedArtDummy            = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV26_2(BSW_s_AlgoParameters_ARS4xx_V26_2::Fct_algo_parameters_t & Params)
{
  // EBA
  Params.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  Params.Acc.NaviFusionPreselBits         = 0;
  // General
  Params.General.FnSwitchBits             = 0;
  // Blockage
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Params.Blockage.f32_ShutoffRange[0] = 120.f * (nI + 1);  /* @min:0 @max:200.0 */
    Params.Blockage.f32_ShutonRange[nI] = 175.f * (nI + 1);
    Params.Blockage.b_UseRoadbeam[nI] = nI;
    Params.Blockage.ui8_RoadbeamSpeedMin[nI] = 10;
    Params.Blockage.ui8_RoadVisibilityMin[nI] = 80;
    Params.Blockage.ui8_RoadQualityMin[nI] = 40;
  }
  Params.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  Params.Blockage.f32_BlockageHiTempThreshFactor = 2.f;
  Params.Blockage.i8_BlockageHiTempThresh = 5;
  Params.Blockage.i8_BlockageLoTempThresh = -10;
  Params.Blockage.ui8_BlockageSpeedThreshold = 15;
  Params.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Params.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Params.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Params.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Params.Blockage.ui8_BlockageCamObjectThresh = 1;
  Params.Blockage.i8_BlockageCamTempThresh = 5;
  Params.Blockage.ui8_BlockageWiperCamThresh = 43;
  Params.Blockage.ui8_BlockageWiperThresh = 43;
  Params.Blockage.b_BlockageUseTemperature = 0;
  Params.Blockage.b_BlockageUseWiper      = 0;
}

void CConvBSWAlgoParameters::InitV26_2(BSW_s_AlgoParameters_ARS4xx_V26_2::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 26u;
  // FCT
  InitV26_2(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  Params.Em.Ped.ePedArtDummy            = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV26_3(BSW_s_AlgoParameters_ARS4xx_V26_3::Fct_algo_parameters_t & Params)
{
  // EBA
  Params.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  Params.Acc.NaviFusionPreselBits         = 0;
  // General
  Params.General.FnSwitchBits             = 0;
  // Blockage
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Params.Blockage.f32_ShutoffRange[0] = 120.f * (nI + 1);  /* @min:0 @max:200.0 */
    Params.Blockage.f32_ShutonRange[nI] = 175.f * (nI + 1);
    Params.Blockage.b_UseRoadbeam[nI] = nI;
    Params.Blockage.ui8_RoadbeamSpeedMin[nI] = 10;
    Params.Blockage.ui8_RoadVisibilityMin[nI] = 80;
    Params.Blockage.ui8_RoadQualityMin[nI] = 40;
  }
  Params.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  Params.Blockage.f32_BlockageHiTempThreshFactor = 2.f;
  Params.Blockage.i8_BlockageHiTempThresh = 5;
  Params.Blockage.i8_BlockageLoTempThresh = -10;
  Params.Blockage.ui8_BlockageSpeedThreshold = 15;
  Params.Blockage.ui8_BlockageWiperThresh = 43;
  Params.Blockage.b_BlockageUseTemperature = 0;
  Params.Blockage.b_BlockageUseWiper      = 0;
}

void CConvBSWAlgoParameters::InitV26_3(BSW_s_AlgoParameters_ARS4xx_V26_3::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 26u;
  // FCT
  InitV26_3(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  Params.Em.Ped.ePedArtDummy            = 0;
}

void CConvBSWAlgoParameters::InitV27(BSW_s_AlgoParameters_ARS4xx_V27::Fct_algo_parameters_t & Params)
{
  // EBA
  Params.Eba.CodingValid                  = 0;    /* EBA Coding Bits validity flag */
  Params.Eba.CodingBits                   = 0x27; /* EBA Coding Bits */
  Params.Eba.PreBrkParAccelTab.Valid      = 0;    /* Validity status of acceleration parameter table */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL1[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 1 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[0].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[1].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[2].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Velo  = 0;    /* Minimum (neg.) allowed acceleration level 2 */
  Params.Eba.PreBrkParAccelTab.AccelL2[3].Accel = -15;  /* Minimum (neg.) allowed acceleration level 2 */
  // ACC
  Params.Acc.CameraFusionPreselBits       = 0;  // ACC_PAR_FUSION_SEL_DEFAULT
  Params.Acc.NaviFusionPreselBits         = 0;
  // General
  Params.General.FnSwitchBits             = 0;
  // Blockage
  Params.Blockage.f32_ShutoffRange[0] = 120.f;  /* @min:0 @max:200.0 */
  Params.Blockage.f32_ShutonRange[0] = 175.f;
  Params.Blockage.b_UseRoadbeam[0] = 0;
  Params.Blockage.ui8_RoadbeamSpeedMin[0] = 10;
  Params.Blockage.ui8_RoadVisibilityMin[0] = 80;
  Params.Blockage.ui8_RoadQualityMin[0] = 40;

  Params.Blockage.f32_ShutoffTime_Timeout = 60;   /* @min:1 @max:500.0 */
  Params.Blockage.f32_ShutoffWay_Timeout  = 2000; /* @min:1 @max:10000 */
  Params.Blockage.ui_ShutoffNoOfObjLosses = 6;    /* @min:0 @max:10 */
  Params.Blockage.b_BlockageActive        = 1;    /* @min:0 @max:1 */
  Params.Blockage.f32_BlockageHiTempThreshFactor = 2.f;
  Params.Blockage.i8_BlockageHiTempThresh = 5;
  Params.Blockage.i8_BlockageLoTempThresh = -10;
  Params.Blockage.ui8_BlockageSpeedThreshold = 15;
  Params.Blockage.ui8_BlockageWiperThresh = 43;
  Params.Blockage.b_BlockageUseTemperature = 0;
  Params.Blockage.b_BlockageUseWiper      = 0;
}

void CConvBSWAlgoParameters::InitV27(BSW_s_AlgoParameters_ARS4xx_V27::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 27u;
  // FCT
  InitV27(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  Params.Em.Ped.ePedArtDummy            = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV31(BSW_s_AlgoParameters_ARS4xx_V31::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 31u;
  // FCT
  InitV26_2(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  Params.Em.Ped.ePedArtDummy            = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV32(BSW_s_AlgoParameters_ARS4xx_V32::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 32u;
  // FCT
  InitV26(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  Params.Em.Ped.ePedArtDummy            = 0;
  // ALN
  Params.Aln.f_ElevMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevEolMax                = DEG2RAD(3); /* from aln_algoparameters.par */
  Params.Aln.f_AzimEolMax                = DEG2RAD(5); /* from aln_algoparameters.par */
  Params.Aln.f_ElevMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.f_AzimMonMaxDiff            = DEG2RAD(15); /* from aln_algoparameters.par */
  Params.Aln.b_ElevMonEnable             = 1;  /* Enable monitoring elevation. If disabled, no cyclic elevation requests are sent to MEL */
  Params.Aln.b_AzimMonEnable             = 1;  /* Enable monitoring azimuth. If disabled, monitoring runs and saves detected misalignments to the monitoring nvm values, but not to the current used nvm value (detected misalignment is not applied). */
  Params.Aln.b_EolChannelCalibEnable     = 1;
  Params.Aln.b_OnlineChannelCalibEnable  = 1;
  Params.Aln.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::InitV33(BSW_s_AlgoParameters_ARS4xx_V33::BSW_s_AlgoParameters_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.uiVersionNumber = 33u;
  // FCT
  InitV26(Params.Fct);
  // EM
  Params.Em.Cem.eCEMParCodState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParCldState         = 1;  // CEM_PAR_SENSOR_STATE_NORMAL
  Params.Em.Cem.eCEMParModeSelection    = 0;  // CEM_PAR_ME_SEL_NO
  Params.Em.Lat.b_UseExternalYawRateLat = 0;
  Params.Em.Lat.b_UseExternalAxLat      = 0;
  Params.Em.Lat.u_YawRateObjLat         = 0;
  Params.Em.Lat.u_AccelXObjLat          = 0;
  Params.Em.Ped.ePedArtDummy            = 0;
}

void CConvBSWAlgoParameters::Convert_V6_V1_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V6_V1::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1 = Src.Fct;

  Dest.Fct_V10.Acc = Src.Fct.Acc;
  Dest.Fct_V10.Blockage = Src.Fct.Blockage;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General.FnSwitchBits = 0;

  Dest.Fct_V16.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V16.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V16.Blockage = Src.Fct.Blockage;
  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.General.FnSwitchBits = 0;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V19_1.General.FnSwitchBits = 0;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_1.Blockage.f32_ShutonRange[0] = 0.0F;
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_1.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_1.b_BlockageUseWiper = 0;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_2.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V19_2.General.FnSwitchBits = 0;
  Dest.Fct_V19_2.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_2.Blockage.f32_ShutonRange[0] = 175;  /* @min:0 @max:200.0 */
  Dest.Fct_V19_2.Blockage.b_UseRoadbeam[0] = 0;
  Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[0] = 10;
  Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[0] = 80;
  Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[0] = 40;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[1] = 350;
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[1] = 1;
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[1] = 80;
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[1] = 40;
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  InitV20(Dest.Fct_V20);
  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V21.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V21.General.FnSwitchBits = 0;
  Dest.Fct_V21.Blockage = Dest.Fct_V20.Blockage;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Em_V6_V1 = Src.Em;
  Dest.Em_V13.Cem = Src.Em.Cem;
  Dest.Em_V13.Lat.b_UseExternalYawRateLat = 0;
  Dest.Em_V13.Lat.b_UseExternalAxLat = 0;
  Dest.Em_V13.Lat.u_YawRateObjLat = 0;
  Dest.Em_V13.Lat.u_AccelXObjLat = 0;
  Dest.Em_V26.Cem = Src.Em.Cem;
  Dest.Em_V26.Lat = Dest.Em_V13.Lat;
  Dest.Em_V26.Ped.ePedArtDummy = /*EM_PED_ART_DUMMY_DEFAULT=*/0;

  Dest.Aln_V6_V1 = Src.Aln;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = 1;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = 1;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = 1;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = 1;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = 1;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = 1;
  Dest.Aln_V10.f_ElevMonMax = DEG2RAD(5);
  Dest.Aln_V10.f_AzimMonMax = DEG2RAD(5);
  Dest.Aln_V10.f_ElevEolMax = DEG2RAD(3);
  Dest.Aln_V10.f_AzimEolMax = DEG2RAD(5);
  Dest.Aln_V10.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V10.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V10.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V10.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V10.b_EolChannelCalibEnable = 1;
  Dest.Aln_V10.b_OnlineChannelCalibEnable = 1;
  Dest.Aln_V10.b_OnlineAngleDevCalibEnable = 1;
}

void CConvBSWAlgoParameters::Convert_V6_V2_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V6_V2::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1 = Src.Fct;

  Dest.Fct_V10.Acc = Src.Fct.Acc;
  Dest.Fct_V10.Blockage = Src.Fct.Blockage;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General.FnSwitchBits = 0;

  Dest.Fct_V16.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V16.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V16.Blockage = Src.Fct.Blockage;
  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.General.FnSwitchBits = 0;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V19_1.General.FnSwitchBits = 0;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_1.Blockage.f32_ShutonRange[0] = 0.0F;
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_1.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_1.b_BlockageUseWiper = 0;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_2.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V19_2.General.FnSwitchBits = 0;
  Dest.Fct_V19_2.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_2.Blockage.f32_ShutonRange[0] = 175.f;  /* @min:0 @max:200.0 */
  Dest.Fct_V19_2.Blockage.b_UseRoadbeam[0] = 0;
  Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[0] = 10;
  Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[0] = 80;
  Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[0] = 40;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[1] = 350;
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[1] = 1;
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[1] = 80;
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[1] = 40;
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  InitV20(Dest.Fct_V20);
  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V21.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V21.General.FnSwitchBits = 0;
  Dest.Fct_V21.Blockage = Dest.Fct_V20.Blockage;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Em_V6_V1 = Src.Em;
  Dest.Em_V13.Cem = Src.Em.Cem;
  Dest.Em_V13.Lat.b_UseExternalYawRateLat = 0;
  Dest.Em_V13.Lat.b_UseExternalAxLat = 0;
  Dest.Em_V13.Lat.u_YawRateObjLat = 0;
  Dest.Em_V13.Lat.u_AccelXObjLat = 0;
  Dest.Em_V26.Cem = Src.Em.Cem;
  Dest.Em_V26.Lat = Dest.Em_V13.Lat;
  Dest.Em_V26.Ped.ePedArtDummy = /*EM_PED_ART_DUMMY_DEFAULT=*/0;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2 = Src.Aln;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10.f_ElevMonMax = DEG2RAD(5);
  Dest.Aln_V10.f_AzimMonMax = DEG2RAD(5);
  Dest.Aln_V10.f_ElevEolMax = DEG2RAD(3);
  Dest.Aln_V10.f_AzimEolMax = DEG2RAD(5);
  Dest.Aln_V10.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V10.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V10.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V10.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V10.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V10.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V10.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
}

void CConvBSWAlgoParameters::Convert_V6_V3_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V6_V3::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1 = Src.Fct;

  Dest.Fct_V10.Acc = Src.Fct.Acc;
  Dest.Fct_V10.Blockage = Src.Fct.Blockage;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General.FnSwitchBits = 0;

  Dest.Fct_V16.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V16.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V16.Blockage = Src.Fct.Blockage;
  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.General.FnSwitchBits = 0;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V19_1.General.FnSwitchBits = 0;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_1.Blockage.f32_ShutonRange[0] = 175.F;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[1] = 350.F;
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_1.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_1.b_BlockageUseWiper = 0;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_2.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V19_2.General.FnSwitchBits = 0;
  Dest.Fct_V19_2.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_2.Blockage.f32_ShutonRange[0] = 175;  /* @min:0 @max:200.0 */
  Dest.Fct_V19_2.Blockage.b_UseRoadbeam[0] = 0;
  Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[0] = 10;
  Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[0] = 80;
  Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[0] = 40;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[1] = 350;
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[1] = 1;
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[1] = 80;
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[1] = 40;
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  InitV20(Dest.Fct_V20);
  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V21.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V21.General.FnSwitchBits = 0;
  Dest.Fct_V21.Blockage = Dest.Fct_V20.Blockage;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Em_V6_V1 = Src.Em;
  Dest.Em_V13.Cem = Src.Em.Cem;
  Dest.Em_V13.Lat.b_UseExternalYawRateLat = 0;
  Dest.Em_V13.Lat.b_UseExternalAxLat = 0;
  Dest.Em_V13.Lat.u_YawRateObjLat = 0;
  Dest.Em_V13.Lat.u_AccelXObjLat = 0;
  Dest.Em_V26.Cem = Src.Em.Cem;
  Dest.Em_V26.Lat = Dest.Em_V13.Lat;
  Dest.Em_V26.Ped.ePedArtDummy = /*EM_PED_ART_DUMMY_DEFAULT=*/0;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3 = Src.Aln;
  Dest.Aln_V10.f_ElevMonMax = DEG2RAD(5);
  Dest.Aln_V10.f_AzimMonMax = DEG2RAD(5);
  Dest.Aln_V10.f_ElevEolMax = DEG2RAD(3);
  Dest.Aln_V10.f_AzimEolMax = DEG2RAD(5);
  Dest.Aln_V10.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V10.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V10.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V10.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V10.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V10.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V10.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
}

void CConvBSWAlgoParameters::Convert_V10_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc = Src.Fct.Acc;
  Dest.Fct_V6_V1.Blockage = Src.Fct.Blockage;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10 = Src.Fct;

  Dest.Fct_V16.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V16.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V16.Blockage = Src.Fct.Blockage;
  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.General = Src.Fct.General;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_1.Blockage.f32_ShutonRange[0] = 175.F;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[1] = 350.F;
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_1.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_1.b_BlockageUseWiper = 0;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_2.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V19_2.General = Src.Fct.General;
  Dest.Fct_V19_2.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_2.Blockage.f32_ShutonRange[0] = 175.f;  /* @min:0 @max:200.0 */
  Dest.Fct_V19_2.Blockage.b_UseRoadbeam[0] = 0;
  Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[0] = 10;
  Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[0] = 80;
  Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[0] = 40;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[1] = 350;
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[1] = 1;
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[1] = 80;
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[1] = 40;
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  InitV20(Dest.Fct_V20);
  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.General = Src.Fct.General;
  Dest.Fct_V20.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V21.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V21.General = Src.Fct.General;
  Dest.Fct_V21.Blockage = Dest.Fct_V20.Blockage;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V26.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V26_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Em_V6_V1 = Src.Em;
  Dest.Em_V13.Cem = Src.Em.Cem;
  Dest.Em_V13.Lat.b_UseExternalYawRateLat = 0;
  Dest.Em_V13.Lat.b_UseExternalAxLat = 0;
  Dest.Em_V13.Lat.u_YawRateObjLat = 0;
  Dest.Em_V13.Lat.u_AccelXObjLat = 0;
  Dest.Em_V26.Cem = Src.Em.Cem;
  Dest.Em_V26.Lat = Dest.Em_V13.Lat;
  Dest.Em_V26.Ped.ePedArtDummy = /*EM_PED_ART_DUMMY_DEFAULT=*/0;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V13_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc = Src.Fct.Acc;
  Dest.Fct_V6_V1.Blockage = Src.Fct.Blockage;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10 = Src.Fct;

  Dest.Fct_V16.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V16.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V16.Blockage = Src.Fct.Blockage;
  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.General = Src.Fct.General;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_1.Blockage.f32_ShutonRange[0] = 175.F;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[1] = 350.F;
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_1.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_1.b_BlockageUseWiper = 0;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_2.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V19_2.General = Src.Fct.General;
  Dest.Fct_V19_2.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_2.Blockage.f32_ShutonRange[0] = 175.f;  /* @min:0 @max:200.0 */
  Dest.Fct_V19_2.Blockage.b_UseRoadbeam[0] = 0;
  Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[0] = 10;
  Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[0] = 80;
  Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[0] = 40;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[1] = 350;
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[1] = 1;
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[1] = 80;
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[1] = 40;
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  InitV20(Dest.Fct_V20);
  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.General = Src.Fct.General;
  Dest.Fct_V20.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V21.Acc.NaviFusionPreselBits = 0;
  Dest.Fct_V21.General = Src.Fct.General;
  Dest.Fct_V21.Blockage = Dest.Fct_V20.Blockage;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V26.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V26_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13 = Src.Em;
  Dest.Em_V26.Cem = Src.Em.Cem;
  Dest.Em_V26.Lat = Src.Em.Lat;
  Dest.Em_V26.Ped.ePedArtDummy = /*EM_PED_ART_DUMMY_DEFAULT=*/0;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V16_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage = Src.Fct.Blockage;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage = Src.Fct.Blockage;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16 = Src.Fct;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc = Src.Fct.Acc;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_1.Blockage.f32_ShutonRange[0] = 175.F;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[1] = 350.F;
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_1.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_1.b_BlockageUseWiper = 0;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc = Src.Fct.Acc;
  Dest.Fct_V19_2.General = Src.Fct.General;
  Dest.Fct_V19_2.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V19_2.Blockage.f32_ShutonRange[0] = 175;  /* @min:0 @max:200.0 */
  Dest.Fct_V19_2.Blockage.b_UseRoadbeam[0] = 0;
  Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[0] = 10;
  Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[0] = 80;
  Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[0] = 40;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[1] = 350;
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[1] = 1;
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[1] = 80;
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[1] = 40;
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = 0;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = 5;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = -10;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = 43;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = 0;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  InitV20(Dest.Fct_V20);
  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.General = Src.Fct.General;
  Dest.Fct_V20.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  if (SYS_NUM_OF_SCANS>1)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[1] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V21.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V21.General = Src.Fct.General;
  Dest.Fct_V21.Blockage = Dest.Fct_V20.Blockage;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc = Src.Fct.Acc;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V26.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V26.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc = Src.Fct.Acc;
  Dest.Fct_V26_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V27.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13 = Src.Em;
  Dest.Em_V26.Cem = Src.Em.Cem;
  Dest.Em_V26.Lat = Src.Em.Lat;
  Dest.Em_V26.Ped.ePedArtDummy = /*EM_PED_ART_DUMMY_DEFAULT=*/0;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V19_1_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V19_1::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc = Src.Fct.Acc;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1 = Src.Fct;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_2.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = Src.Fct.ui8_BlockageCamActivityFiltSize;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = Src.Fct.ui8_BlockageCamActivityFiltPos;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = Src.Fct.ui8_BlockageCamObjectFilterSize;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = Src.Fct.ui8_BlockageCamObjectFilterPos;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = Src.Fct.ui8_BlockageCamObjectThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = Src.Fct.i8_BlockageCamTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = Src.Fct.ui8_BlockageWiperCamThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = Src.Fct.b_BlockageUseWiperinCamera;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = Src.Fct.b_BlockageCamIntegrationActive;

  InitV20(Dest.Fct_V20);
  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.Acc.e_MaxPickupDist_HiLo_Type = 0;
  Dest.Fct_V20.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V20.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V20.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V20.Blockage.i8_BlockageHiTempThresh = Src.Fct.i8_BlockageHiTempThresh;
  Dest.Fct_V20.Blockage.i8_BlockageLoTempThresh = Src.Fct.i8_BlockageLoTempThresh;
  Dest.Fct_V20.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.ui8_BlockageSpeedThreshold;
  Dest.Fct_V20.Blockage.ui8_BlockageWiperThresh = Src.Fct.ui8_BlockageWiperThresh;
  Dest.Fct_V20.Blockage.b_BlockageUseTemperature = Src.Fct.b_BlockageUseTemperature;
  Dest.Fct_V20.Blockage.b_BlockageUseWiper = Src.Fct.b_BlockageUseWiper;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V21.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V21.General = Src.Fct.General;
  Dest.Fct_V21.Blockage = Dest.Fct_V20.Blockage;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc = Src.Fct.Acc;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V23.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V26.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V26.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V26.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26.Blockage.i8_BlockageHiTempThresh = Src.Fct.i8_BlockageHiTempThresh;
  Dest.Fct_V26.Blockage.i8_BlockageLoTempThresh = Src.Fct.i8_BlockageLoTempThresh;
  Dest.Fct_V26.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26.Blockage.ui8_BlockageWiperThresh = Src.Fct.ui8_BlockageWiperThresh;
  Dest.Fct_V26.Blockage.b_BlockageUseTemperature = Src.Fct.b_BlockageUseTemperature;
  Dest.Fct_V26.Blockage.b_BlockageUseWiper = Src.Fct.b_BlockageUseWiper;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V27.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange;
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.b_BlockageUseWiper;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc = Src.Fct.Acc;
  Dest.Fct_V26_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange;
    Dest.Fct_V26_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.i8_BlockageHiTempThresh;
  Dest.Fct_V26_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.i8_BlockageLoTempThresh;
  Dest.Fct_V26_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.ui8_BlockageWiperThresh;
  Dest.Fct_V26_2.Blockage.b_BlockageUseTemperature = Src.Fct.b_BlockageUseTemperature;
  Dest.Fct_V26_2.Blockage.b_BlockageUseWiper = Src.Fct.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13 = Src.Em;
  Dest.Em_V26.Cem = Src.Em.Cem;
  Dest.Em_V26.Lat = Src.Em.Lat;
  Dest.Em_V26.Ped.ePedArtDummy = /*EM_PED_ART_DUMMY_DEFAULT=*/0;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V19_2_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc = Src.Fct.Acc;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = Src.Fct.Blockage.ui8_BlockageCamActivityFiltSize;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = Src.Fct.Blockage.ui8_BlockageCamActivityFiltPos;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = Src.Fct.Blockage.ui8_BlockageCamObjectFilterSize;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = Src.Fct.Blockage.ui8_BlockageCamObjectFilterPos;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = Src.Fct.Blockage.ui8_BlockageCamObjectThresh;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = Src.Fct.Blockage.i8_BlockageCamTempThresh;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = Src.Fct.Blockage.ui8_BlockageWiperCamThresh;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = Src.Fct.Blockage.b_BlockageUseWiperinCamera;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = Src.Fct.Blockage.b_BlockageCamIntegrationActive;

  Dest.Fct_V19_2 = Src.Fct;

  InitV20(Dest.Fct_V20);
  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V20.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V20.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V20.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V20.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V20.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V20.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V20.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V20.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V20.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V20.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V21.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V21.General = Src.Fct.General;
  Dest.Fct_V21.Blockage = Dest.Fct_V20.Blockage;

  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc = Src.Fct.Acc;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V23.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V23.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V23.Blockage.f32_BlockageHiTempThreshFactor = 2.0f;
  Dest.Fct_V23.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V23.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageCamActivityFiltSize = Src.Fct.Blockage.ui8_BlockageCamActivityFiltSize;
  Dest.Fct_V23.Blockage.ui8_BlockageCamActivityFiltPos = Src.Fct.Blockage.ui8_BlockageCamActivityFiltPos;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectFilterSize = Src.Fct.Blockage.ui8_BlockageCamObjectFilterSize;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectFilterPos = Src.Fct.Blockage.ui8_BlockageCamObjectFilterPos;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectThresh = Src.Fct.Blockage.ui8_BlockageCamObjectThresh;
  Dest.Fct_V23.Blockage.i8_BlockageCamTempThresh = Src.Fct.Blockage.i8_BlockageCamTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperCamThresh = Src.Fct.Blockage.ui8_BlockageWiperCamThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V23.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V23.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V23.Blockage.b_BlockageUseWiperinCamera = Src.Fct.Blockage.b_BlockageUseWiperinCamera;
  Dest.Fct_V23.Blockage.b_BlockageCamIntegrationActive = Src.Fct.Blockage.b_BlockageCamIntegrationActive;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V26.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V26.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V27.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V27.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc = Src.Fct.Acc;
  Dest.Fct_V26_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13 = Src.Em;
  Dest.Em_V26.Cem = Src.Em.Cem;
  Dest.Em_V26.Lat = Src.Em.Lat;
  Dest.Em_V26.Ped.ePedArtDummy = /*EM_PED_ART_DUMMY_DEFAULT=*/0;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V20_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V20::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V16.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_2.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V20 = Src.Fct;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V21.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V21.General = Src.Fct.General;
  Dest.Fct_V21.Blockage = Src.Fct.Blockage;

  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V23.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V23.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V23.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V23.Blockage.f32_BlockageHiTempThreshFactor = 2.0f;
  Dest.Fct_V23.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V23.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V23.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V23.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V23.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V23.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V23.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V23.Blockage.b_BlockageCamIntegrationActive = 1;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V26.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V26.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V26_2.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V26_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V27.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V27.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13 = Src.Em;
  Dest.Em_V26.Cem = Src.Em.Cem;
  Dest.Em_V26.Lat = Src.Em.Lat;
  Dest.Em_V26.Ped.ePedArtDummy = /*EM_PED_ART_DUMMY_DEFAULT=*/0;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V21_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V21::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc = Src.Fct.Acc;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc = Src.Fct.Acc;
  Dest.Fct_V19_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.Acc.e_MaxPickupDist_HiLo_Type = 0;
  Dest.Fct_V20.General = Src.Fct.General;
  Dest.Fct_V20.Blockage = Src.Fct.Blockage;

  Dest.Fct_V21 = Src.Fct;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc = Src.Fct.Acc;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V23.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V23.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V23.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V23.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V23.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V23.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc = Src.Fct.Acc;
  Dest.Fct_V26.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc = Src.Fct.Acc;
  Dest.Fct_V26_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc = Src.Fct.Acc;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V27.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13 = Src.Em;
  Dest.Em_V26.Cem = Src.Em.Cem;
  Dest.Em_V26.Lat = Src.Em.Lat;
  Dest.Em_V26.Ped.ePedArtDummy = /*EM_PED_ART_DUMMY_DEFAULT=*/0;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V23_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V23::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc = Src.Fct.Acc;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc = Src.Fct.Acc;
  Dest.Fct_V19_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.Acc.e_MaxPickupDist_HiLo_Type = 0;
  Dest.Fct_V20.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V20.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V20.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V20.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V20.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V20.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V20.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V20.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V20.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V20.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V20.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc = Src.Fct.Acc;
  Dest.Fct_V21.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V21.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V21.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V21.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V21.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V21.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V21.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V21.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V21.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V21.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V21.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V21.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V21.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V21.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V21.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V21.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V23 = Src.Fct;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc = Src.Fct.Acc;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V27.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13 = Src.Em;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V26_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc = Src.Fct.Acc;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc = Src.Fct.Acc;
  Dest.Fct_V19_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.Acc.e_MaxPickupDist_HiLo_Type = 0;
  Dest.Fct_V20.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V20.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V20.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V20.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V20.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V20.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V20.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V20.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V20.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V20.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V20.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc = Src.Fct.Acc;
  Dest.Fct_V21.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V21.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V21.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V21.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V21.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V21.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V21.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V21.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V21.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V21.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V21.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V21.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V21.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V21.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V21.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V21.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc = Src.Fct.Acc;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V23.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V23.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V23.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V23.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V23.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V23.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V23.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V26 = Src.Fct;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc = Src.Fct.Acc;
  Dest.Fct_V26_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26_2.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V26_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc = Src.Fct.Acc;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V27.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13.Cem = Src.Em.Cem;
  Dest.Em_V13.Lat = Src.Em.Lat;
  Dest.Em_V26 = Src.Em;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V26_2_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V26_2::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc = Src.Fct.Acc;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc = Src.Fct.Acc;
  Dest.Fct_V19_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.Acc.e_MaxPickupDist_HiLo_Type = 0;
  Dest.Fct_V20.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V20.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V20.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V20.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V20.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V20.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V20.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V20.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V20.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V20.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V20.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc = Src.Fct.Acc;
  Dest.Fct_V21.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V21.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V21.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V21.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V21.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V21.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V21.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V21.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V21.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V21.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V21.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V21.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V21.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V21.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V21.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V21.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc = Src.Fct.Acc;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V23.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V23.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V23.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V23.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V23.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageCamActivityFiltSize = Src.Fct.Blockage.ui8_BlockageCamActivityFiltSize;
  Dest.Fct_V23.Blockage.ui8_BlockageCamActivityFiltPos = Src.Fct.Blockage.ui8_BlockageCamActivityFiltPos;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectFilterSize = Src.Fct.Blockage.ui8_BlockageCamObjectFilterSize;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectFilterPos = Src.Fct.Blockage.ui8_BlockageCamObjectFilterPos;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectThresh = Src.Fct.Blockage.ui8_BlockageCamObjectThresh;
  Dest.Fct_V23.Blockage.i8_BlockageCamTempThresh = Src.Fct.Blockage.i8_BlockageCamTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageCamActivityFiltSize = Src.Fct.Blockage.ui8_BlockageCamActivityFiltSize;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V23.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V23.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc = Src.Fct.Acc;
  Dest.Fct_V26.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V26.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V26_2 = Src.Fct;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc = Src.Fct.Acc;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V27.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13.Cem = Src.Em.Cem;
  Dest.Em_V13.Lat = Src.Em.Lat;
  Dest.Em_V26 = Src.Em;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V26_3_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V26_3::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba.CodingBits = Src.Fct.Eba.CodingBits;
  Dest.Fct_V6_V1.Eba.CodingValid = Src.Fct.Eba.CodingValid;
  Dest.Fct_V6_V1.Eba.PreBrkParAccelTab.Valid = Src.Fct.Eba.PreBrkParAccelTab.Valid;
  memcpy (&(Dest.Fct_V6_V1.Eba.PreBrkParAccelTab.AccelL1), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL1), sizeof(Dest.Fct_V6_V1.Eba.PreBrkParAccelTab.AccelL1));
  memcpy (&(Dest.Fct_V6_V1.Eba.PreBrkParAccelTab.AccelL2), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL2), sizeof(Dest.Fct_V6_V1.Eba.PreBrkParAccelTab.AccelL2));

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba.CodingBits = Src.Fct.Eba.CodingBits;
  Dest.Fct_V10.Eba.CodingValid = Src.Fct.Eba.CodingValid;
  Dest.Fct_V10.Eba.PreBrkParAccelTab.Valid = Src.Fct.Eba.PreBrkParAccelTab.Valid;
  memcpy (&(Dest.Fct_V10.Eba.PreBrkParAccelTab.AccelL1), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL1), sizeof(Dest.Fct_V10.Eba.PreBrkParAccelTab.AccelL1));
  memcpy (&(Dest.Fct_V10.Eba.PreBrkParAccelTab.AccelL2), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL2), sizeof(Dest.Fct_V10.Eba.PreBrkParAccelTab.AccelL2));
  Dest.Fct_V10.General.FnSwitchBits = Src.Fct.General.FnSwitchBits;

  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V16.Eba.CodingBits = Src.Fct.Eba.CodingBits;
  Dest.Fct_V16.Eba.CodingValid = Src.Fct.Eba.CodingValid;
  Dest.Fct_V16.Eba.PreBrkParAccelTab.Valid = Src.Fct.Eba.PreBrkParAccelTab.Valid;
  memcpy (&(Dest.Fct_V16.Eba.PreBrkParAccelTab.AccelL1), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL1), sizeof(Dest.Fct_V16.Eba.PreBrkParAccelTab.AccelL1));
  memcpy (&(Dest.Fct_V16.Eba.PreBrkParAccelTab.AccelL2), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL2), sizeof(Dest.Fct_V16.Eba.PreBrkParAccelTab.AccelL2));
  Dest.Fct_V16.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V16.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V16.General.FnSwitchBits = Src.Fct.General.FnSwitchBits ;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba.CodingBits = Src.Fct.Eba.CodingBits;
  Dest.Fct_V19_1.Eba.CodingValid = Src.Fct.Eba.CodingValid;
  Dest.Fct_V19_1.Eba.PreBrkParAccelTab.Valid = Src.Fct.Eba.PreBrkParAccelTab.Valid;
  memcpy (&(Dest.Fct_V19_1.Eba.PreBrkParAccelTab.AccelL1), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL1), sizeof(Dest.Fct_V19_1.Eba.PreBrkParAccelTab.AccelL1));
  memcpy (&(Dest.Fct_V19_1.Eba.PreBrkParAccelTab.AccelL2), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL2), sizeof(Dest.Fct_V19_1.Eba.PreBrkParAccelTab.AccelL2));
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General.FnSwitchBits = Src.Fct.General.FnSwitchBits;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba.CodingBits = Src.Fct.Eba.CodingBits;
  Dest.Fct_V19_2.Eba.CodingValid = Src.Fct.Eba.CodingValid;
  Dest.Fct_V19_2.Eba.PreBrkParAccelTab.Valid = Src.Fct.Eba.PreBrkParAccelTab.Valid;
  memcpy (&(Dest.Fct_V19_2.Eba.PreBrkParAccelTab.AccelL1), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL1), sizeof(Dest.Fct_V19_2.Eba.PreBrkParAccelTab.AccelL1));
  memcpy (&(Dest.Fct_V19_2.Eba.PreBrkParAccelTab.AccelL2), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL2), sizeof(Dest.Fct_V19_2.Eba.PreBrkParAccelTab.AccelL2));
  Dest.Fct_V19_2.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_2.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_2.General.FnSwitchBits = Src.Fct.General.FnSwitchBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V20.Eba.CodingBits = Src.Fct.Eba.CodingBits;
  Dest.Fct_V20.Eba.CodingValid = Src.Fct.Eba.CodingValid;
  Dest.Fct_V20.Eba.PreBrkParAccelTab.Valid = Src.Fct.Eba.PreBrkParAccelTab.Valid;
  memcpy (&(Dest.Fct_V20.Eba.PreBrkParAccelTab.AccelL1), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL1), sizeof(Dest.Fct_V20.Eba.PreBrkParAccelTab.AccelL1));
  memcpy (&(Dest.Fct_V20.Eba.PreBrkParAccelTab.AccelL2), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL2), sizeof(Dest.Fct_V20.Eba.PreBrkParAccelTab.AccelL2));
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.Acc.e_MaxPickupDist_HiLo_Type = 0;
  Dest.Fct_V20.General.FnSwitchBits = Src.Fct.General.FnSwitchBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V20.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V20.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V20.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V20.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V20.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V20.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V20.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V20.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V20.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V20.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V21.Eba.CodingBits = Src.Fct.Eba.CodingBits;
  Dest.Fct_V21.Eba.CodingValid = Src.Fct.Eba.CodingValid;
  Dest.Fct_V21.Eba.PreBrkParAccelTab.Valid = Src.Fct.Eba.PreBrkParAccelTab.Valid;
  memcpy (&(Dest.Fct_V21.Eba.PreBrkParAccelTab.AccelL1), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL1), sizeof(Dest.Fct_V21.Eba.PreBrkParAccelTab.AccelL1));
  memcpy (&(Dest.Fct_V21.Eba.PreBrkParAccelTab.AccelL2), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL2), sizeof(Dest.Fct_V21.Eba.PreBrkParAccelTab.AccelL2));
  Dest.Fct_V21.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V21.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V21.General.FnSwitchBits = Src.Fct.General.FnSwitchBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V21.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V21.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V21.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V21.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V21.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V21.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V21.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V21.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V21.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V21.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V21.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V21.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V21.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V21.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V21.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba.CodingBits = Src.Fct.Eba.CodingBits;
  Dest.Fct_V23.Eba.CodingValid = Src.Fct.Eba.CodingValid;
  Dest.Fct_V23.Eba.PreBrkParAccelTab.Valid = Src.Fct.Eba.PreBrkParAccelTab.Valid;
  memcpy (&(Dest.Fct_V23.Eba.PreBrkParAccelTab.AccelL1), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL1), sizeof(Dest.Fct_V23.Eba.PreBrkParAccelTab.AccelL1));
  memcpy (&(Dest.Fct_V23.Eba.PreBrkParAccelTab.AccelL2), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL2), sizeof(Dest.Fct_V23.Eba.PreBrkParAccelTab.AccelL2));
  Dest.Fct_V23.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V23.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V23.General.FnSwitchBits = Src.Fct.General.FnSwitchBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V23.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V23.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V23.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V23.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V23.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V23.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V23.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba.CodingBits = Src.Fct.Eba.CodingBits;
  Dest.Fct_V26.Eba.CodingValid = Src.Fct.Eba.CodingValid;
  Dest.Fct_V26.Eba.PreBrkParAccelTab.Valid = Src.Fct.Eba.PreBrkParAccelTab.Valid;
  memcpy (&(Dest.Fct_V26.Eba.PreBrkParAccelTab.AccelL1), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL1), sizeof(Dest.Fct_V26.Eba.PreBrkParAccelTab.AccelL1));
  memcpy (&(Dest.Fct_V26.Eba.PreBrkParAccelTab.AccelL2), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL2), sizeof(Dest.Fct_V26.Eba.PreBrkParAccelTab.AccelL2));
  Dest.Fct_V26.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V26.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V26.General.FnSwitchBits = Src.Fct.General.FnSwitchBits;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V26.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  memcpy(&(Dest.Fct_V26_2), &(Src.Fct), sizeof(Dest.Fct_V26_2));

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba.CodingBits = Src.Fct.Eba.CodingBits;
  Dest.Fct_V27.Eba.CodingValid = Src.Fct.Eba.CodingValid;
  Dest.Fct_V27.Eba.PreBrkParAccelTab.Valid = Src.Fct.Eba.PreBrkParAccelTab.Valid;
  memcpy (&(Dest.Fct_V27.Eba.PreBrkParAccelTab.AccelL1), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL1), sizeof(Dest.Fct_V27.Eba.PreBrkParAccelTab.AccelL1));
  memcpy (&(Dest.Fct_V27.Eba.PreBrkParAccelTab.AccelL2), &(Src.Fct.Eba.PreBrkParAccelTab.AccelL2), sizeof(Dest.Fct_V27.Eba.PreBrkParAccelTab.AccelL2));
  Dest.Fct_V27.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V27.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V27.General.FnSwitchBits = Src.Fct.General.FnSwitchBits;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V27.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem.eCEMParCldState = Src.Em.Cem.eCEMParCldState;
  Dest.Em_V6_V1.Cem.eCEMParCodState = Src.Em.Cem.eCEMParCodState;
  Dest.Em_V6_V1.Cem.eCEMParModeSelection = Src.Em.Cem.eCEMParModeSelection;
  Dest.Em_V13.Cem.eCEMParCldState = Src.Em.Cem.eCEMParCldState;
  Dest.Em_V13.Cem.eCEMParCodState = Src.Em.Cem.eCEMParCodState;
  Dest.Em_V13.Cem.eCEMParModeSelection = Src.Em.Cem.eCEMParModeSelection;
  Dest.Em_V13.Lat.b_UseExternalAxLat = Src.Em.Lat.b_UseExternalAxLat;
  Dest.Em_V13.Lat.b_UseExternalYawRateLat = Src.Em.Lat.b_UseExternalYawRateLat;
  Dest.Em_V13.Lat.u_AccelXObjLat = Src.Em.Lat.u_AccelXObjLat;
  Dest.Em_V13.Lat.u_YawRateObjLat = Src.Em.Lat.u_YawRateObjLat;
  memcpy(&(Dest.Em_V26),&(Src.Em), sizeof(Dest.Em_V26));

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V1.b_ElevMonEnable = 1 ;
  Dest.Aln_V6_V1.b_AzimMonEnable = 1;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V2.b_ElevMonEnable = 1;
  Dest.Aln_V6_V2.b_AzimMonEnable = 1;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = 1;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = 1;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = 1;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V3.b_ElevMonEnable = 1;
  Dest.Aln_V6_V3.b_AzimMonEnable = 1;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = 1;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = 1;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = 1;
  Dest.Aln_V10.f_ElevMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V10.f_AzimMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V10.b_ElevMonEnable = 1;
  Dest.Aln_V10.b_AzimMonEnable = 1;
  Dest.Aln_V10.b_EolChannelCalibEnable = 1;
  Dest.Aln_V10.b_OnlineChannelCalibEnable = 1;
  Dest.Aln_V10.b_OnlineAngleDevCalibEnable = 1;
  Dest.Aln_V10.f_ElevMonMax = DEG2RAD(5);
  Dest.Aln_V10.f_AzimMonMax = DEG2RAD(5);
  Dest.Aln_V10.f_ElevEolMax = DEG2RAD(3);
  Dest.Aln_V10.f_AzimEolMax = DEG2RAD(5);

  //Dest.Fct_V26_3 = Src.Fct;
  //Dest.Em_V26_3 = Src.Em;
}

void CConvBSWAlgoParameters::Convert_V27_1_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V27::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc = Src.Fct.Acc;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];

  Dest.Fct_V19_1.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V19_1.Blockage.f32_ShutonRange[1] = 250;

  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc = Src.Fct.Acc;
  Dest.Fct_V19_2.General = Src.Fct.General;

  Dest.Fct_V19_2.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V19_2.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V19_2.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];

  Dest.Fct_V19_2.Blockage.f32_ShutoffRange[1] = 180;
  Dest.Fct_V19_2.Blockage.f32_ShutonRange[1] = 250;
  Dest.Fct_V19_2.Blockage.b_UseRoadbeam[1] = 0;
  Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
  Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[1] = 80;
  Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[1] = 40;

  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.Acc.e_MaxPickupDist_HiLo_Type = 0;
  Dest.Fct_V20.General = Src.Fct.General;

  Dest.Fct_V20.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V20.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V20.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V20.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V20.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V20.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];

  Dest.Fct_V20.Blockage.f32_ShutoffRange[1] = 180;
  Dest.Fct_V20.Blockage.f32_ShutonRange[1] = 250;
  Dest.Fct_V20.Blockage.b_UseRoadbeam[1] = 0;
  Dest.Fct_V20.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
  Dest.Fct_V20.Blockage.ui8_RoadVisibilityMin[1] = 80;
  Dest.Fct_V20.Blockage.ui8_RoadQualityMin[1] = 40;

  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V20.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V20.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V20.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V20.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V20.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V20.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V20.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc = Src.Fct.Acc;
  Dest.Fct_V21.General = Src.Fct.General;

  Dest.Fct_V21.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V21.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V21.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V21.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V21.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V21.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];

  Dest.Fct_V21.Blockage.f32_ShutoffRange[1] = 180;
  Dest.Fct_V21.Blockage.f32_ShutonRange[1] = 250;
  Dest.Fct_V21.Blockage.b_UseRoadbeam[1] = 0;
  Dest.Fct_V21.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
  Dest.Fct_V21.Blockage.ui8_RoadVisibilityMin[1] = 80;
  Dest.Fct_V21.Blockage.ui8_RoadQualityMin[1] = 40;

  Dest.Fct_V21.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V21.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V21.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V21.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V21.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V21.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V21.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V21.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V21.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V21.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V21.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc = Src.Fct.Acc;
  Dest.Fct_V23.General = Src.Fct.General;

  Dest.Fct_V23.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V23.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V23.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V23.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];

  Dest.Fct_V23.Blockage.f32_ShutoffRange[1] = 180;
  Dest.Fct_V23.Blockage.f32_ShutonRange[1] = 250;
  Dest.Fct_V23.Blockage.b_UseRoadbeam[1] = 0;
  Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
  Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[1] = 80;
  Dest.Fct_V23.Blockage.ui8_RoadQualityMin[1] = 40;

  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V23.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V23.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V23.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V23.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V23.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V26.Acc = Src.Fct.Acc;
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.General = Src.Fct.General;

  Dest.Fct_V26.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V26.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V26.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V26.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V26.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V26.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];

  Dest.Fct_V26.Blockage.f32_ShutoffRange[1] = 180;
  Dest.Fct_V26.Blockage.f32_ShutonRange[1] = 250;
  Dest.Fct_V26.Blockage.b_UseRoadbeam[1] = 0;
  Dest.Fct_V26.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
  Dest.Fct_V26.Blockage.ui8_RoadVisibilityMin[1] = 80;
  Dest.Fct_V26.Blockage.ui8_RoadQualityMin[1] = 40;

  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V26.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V26_2.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V26_2.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V26_2.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V26_2.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V26_2.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V26_2.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];

  Dest.Fct_V26_2.Blockage.f32_ShutoffRange[1] = 180;
  Dest.Fct_V26_2.Blockage.f32_ShutonRange[1] = 250;
  Dest.Fct_V26_2.Blockage.b_UseRoadbeam[1] = 0;
  Dest.Fct_V26_2.Blockage.ui8_RoadbeamSpeedMin[1] = 10;
  Dest.Fct_V26_2.Blockage.ui8_RoadVisibilityMin[1] = 80;
  Dest.Fct_V26_2.Blockage.ui8_RoadQualityMin[1] = 40;

  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26_2.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V26_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13.Cem = Src.Em.Cem;
  Dest.Em_V13.Lat = Src.Em.Lat;
  Dest.Em_V26 = Src.Em;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;

  Dest.Fct_V27 = Src.Fct;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc = Src.Fct.Acc;
  Dest.Fct_V27.General = Src.Fct.General;
}

void CConvBSWAlgoParameters::Convert_V31_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V31::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc = Src.Fct.Acc;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc = Src.Fct.Acc;
  Dest.Fct_V19_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.Acc.e_MaxPickupDist_HiLo_Type = 0;
  Dest.Fct_V20.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V20.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V20.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V20.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V20.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V20.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V20.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V20.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V20.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V20.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V20.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc = Src.Fct.Acc;
  Dest.Fct_V21.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V21.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V21.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V21.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V21.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V21.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V21.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V21.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V21.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V21.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V21.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V21.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V21.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V21.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V21.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V21.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc = Src.Fct.Acc;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V23.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V23.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V23.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V23.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V23.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageCamActivityFiltSize = Src.Fct.Blockage.ui8_BlockageCamActivityFiltSize;
  Dest.Fct_V23.Blockage.ui8_BlockageCamActivityFiltPos = Src.Fct.Blockage.ui8_BlockageCamActivityFiltPos;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectFilterSize = Src.Fct.Blockage.ui8_BlockageCamObjectFilterSize;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectFilterPos = Src.Fct.Blockage.ui8_BlockageCamObjectFilterPos;
  Dest.Fct_V23.Blockage.ui8_BlockageCamObjectThresh = Src.Fct.Blockage.ui8_BlockageCamObjectThresh;
  Dest.Fct_V23.Blockage.i8_BlockageCamTempThresh = Src.Fct.Blockage.i8_BlockageCamTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageCamActivityFiltSize = Src.Fct.Blockage.ui8_BlockageCamActivityFiltSize;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V23.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V23.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV26(Dest.Fct_V26);
  Dest.Fct_V26.Eba = Src.Fct.Eba;
  Dest.Fct_V26.Acc = Src.Fct.Acc;
  Dest.Fct_V26.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V26.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V26_2 = Src.Fct;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc = Src.Fct.Acc;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V27.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13.Cem = Src.Em.Cem;
  Dest.Em_V13.Lat = Src.Em.Lat;
  Dest.Em_V26 = Src.Em;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V32_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V32::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc = Src.Fct.Acc;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc = Src.Fct.Acc;
  Dest.Fct_V19_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.Acc.e_MaxPickupDist_HiLo_Type = 0;
  Dest.Fct_V20.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V20.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V20.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V20.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V20.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V20.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V20.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V20.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V20.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V20.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V20.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc = Src.Fct.Acc;
  Dest.Fct_V21.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V21.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V21.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V21.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V21.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V21.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V21.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V21.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V21.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V21.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V21.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V21.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V21.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V21.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V21.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V21.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc = Src.Fct.Acc;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V23.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V23.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V23.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V23.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V23.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V23.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V23.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V26 = Src.Fct;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc = Src.Fct.Acc;
  Dest.Fct_V26_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26_2.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V26_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc = Src.Fct.Acc;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V27.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13.Cem = Src.Em.Cem;
  Dest.Em_V13.Lat = Src.Em.Lat;
  Dest.Em_V26 = Src.Em;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V1.b_ElevMonEnable = Src.Aln.b_ElevMonEnable ;
  Dest.Aln_V6_V1.b_AzimMonEnable = Src.Aln.b_AzimMonEnable ;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V2.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V2.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = Src.Aln.f_ElevMonMaxDiff;
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = Src.Aln.f_AzimMonMaxDiff;
  Dest.Aln_V6_V3.b_ElevMonEnable = Src.Aln.b_ElevMonEnable;
  Dest.Aln_V6_V3.b_AzimMonEnable = Src.Aln.b_AzimMonEnable;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = Src.Aln.b_EolChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = Src.Aln.b_OnlineChannelCalibEnable;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = Src.Aln.b_OnlineAngleDevCalibEnable;
  Dest.Aln_V10 = Src.Aln;
}

void CConvBSWAlgoParameters::Convert_V33_to_Gen(BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_V33::BSW_s_AlgoParameters_t & Src)
{
  Dest.Fct_V6_V1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V6_V1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V6_V1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V6_V1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V6_V1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V6_V1.Eba = Src.Fct.Eba;

  Dest.Fct_V10.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V10.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V10.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V10.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V10.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V10.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V10.Eba = Src.Fct.Eba;
  Dest.Fct_V10.General = Src.Fct.General;

  Dest.Fct_V16.Eba = Src.Fct.Eba;
  Dest.Fct_V16.Acc = Src.Fct.Acc;
  Dest.Fct_V16.General = Src.Fct.General;
  Dest.Fct_V16.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V16.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V16.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V16.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V16.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;

  Dest.Fct_V19_1.Eba = Src.Fct.Eba;
  Dest.Fct_V19_1.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V19_1.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V19_1.General = Src.Fct.General;
  Dest.Fct_V19_1.Blockage.f32_ShutoffRange = Src.Fct.Blockage.f32_ShutoffRange[0];
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_1.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
  }
  Dest.Fct_V19_1.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_1.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_1.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_1.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_1.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_1.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_1.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_1.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_1.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_1.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_1.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_1.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_1.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_1.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_1.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_1.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_1.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V19_2.Eba = Src.Fct.Eba;
  Dest.Fct_V19_2.Acc = Src.Fct.Acc;
  Dest.Fct_V19_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V19_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V19_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V19_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V19_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V19_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V19_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V19_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V19_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V19_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V19_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V19_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V19_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamActivityFiltPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterSize = 15;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectFilterPos = 3;
  Dest.Fct_V19_2.Blockage.ui8_BlockageCamObjectThresh = 1;
  Dest.Fct_V19_2.Blockage.i8_BlockageCamTempThresh = 5;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperCamThresh = 43;
  Dest.Fct_V19_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V19_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;
  Dest.Fct_V19_2.Blockage.b_BlockageUseWiperinCamera = 1;
  Dest.Fct_V19_2.Blockage.b_BlockageCamIntegrationActive = 1;

  Dest.Fct_V20.Eba = Src.Fct.Eba;
  Dest.Fct_V20.Acc.CameraFusionPreselBits = Src.Fct.Acc.CameraFusionPreselBits;
  Dest.Fct_V20.Acc.NaviFusionPreselBits = Src.Fct.Acc.NaviFusionPreselBits;
  Dest.Fct_V20.Acc.e_MaxPickupDist_HiLo_Type = 0;
  Dest.Fct_V20.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V20.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V20.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V20.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V20.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V20.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V20.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V20.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V20.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V20.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V20.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V20.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V20.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V20.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V20.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V20.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V20.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V21.Eba = Src.Fct.Eba;
  Dest.Fct_V21.Acc = Src.Fct.Acc;
  Dest.Fct_V21.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V21.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V21.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V21.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V21.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V21.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V21.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V21.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V21.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V21.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V21.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V21.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V21.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V21.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V21.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V21.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V21.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV23(Dest.Fct_V23);
  Dest.Fct_V23.Eba = Src.Fct.Eba;
  Dest.Fct_V23.Acc = Src.Fct.Acc;
  Dest.Fct_V23.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V23.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V23.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V23.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V23.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V23.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V23.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V23.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V23.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V23.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V23.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V23.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V23.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V23.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V23.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V23.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V23.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V23.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Fct_V26 = Src.Fct;

  InitV26_2(Dest.Fct_V26_2);
  Dest.Fct_V26_2.Eba = Src.Fct.Eba;
  Dest.Fct_V26_2.Acc = Src.Fct.Acc;
  Dest.Fct_V26_2.General = Src.Fct.General;
  for (int nI=0; nI<SYS_NUM_OF_SCANS; nI++)
  {
    Dest.Fct_V26_2.Blockage.f32_ShutoffRange[nI] = Src.Fct.Blockage.f32_ShutoffRange[nI];
    Dest.Fct_V26_2.Blockage.f32_ShutonRange[nI] = Src.Fct.Blockage.f32_ShutonRange[nI];
    Dest.Fct_V26_2.Blockage.b_UseRoadbeam[nI] = Src.Fct.Blockage.b_UseRoadbeam[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadbeamSpeedMin[nI] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadVisibilityMin[nI] = Src.Fct.Blockage.ui8_RoadVisibilityMin[nI];
    Dest.Fct_V26_2.Blockage.ui8_RoadQualityMin[nI] = Src.Fct.Blockage.ui8_RoadQualityMin[nI];
  }
  Dest.Fct_V26_2.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V26_2.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V26_2.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V26_2.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V26_2.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V26_2.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V26_2.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V26_2.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V26_2.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V26_2.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V26_2.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V26_2.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  InitV27(Dest.Fct_V27);
  Dest.Fct_V27.Eba = Src.Fct.Eba;
  Dest.Fct_V27.Acc = Src.Fct.Acc;
  Dest.Fct_V27.General = Src.Fct.General;
  Dest.Fct_V27.Blockage.f32_ShutoffRange[0] = Src.Fct.Blockage.f32_ShutoffRange[0];
  Dest.Fct_V27.Blockage.f32_ShutonRange[0] = Src.Fct.Blockage.f32_ShutonRange[0];
  Dest.Fct_V27.Blockage.b_UseRoadbeam[0] = Src.Fct.Blockage.b_UseRoadbeam[0];
  Dest.Fct_V27.Blockage.ui8_RoadbeamSpeedMin[0] = Src.Fct.Blockage.ui8_RoadbeamSpeedMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadVisibilityMin[0] = Src.Fct.Blockage.ui8_RoadVisibilityMin[0];
  Dest.Fct_V27.Blockage.ui8_RoadQualityMin[0] = Src.Fct.Blockage.ui8_RoadQualityMin[0];
  Dest.Fct_V27.Blockage.f32_ShutoffTime_Timeout = Src.Fct.Blockage.f32_ShutoffTime_Timeout;
  Dest.Fct_V27.Blockage.f32_ShutoffWay_Timeout = Src.Fct.Blockage.f32_ShutoffWay_Timeout;
  Dest.Fct_V27.Blockage.ui_ShutoffNoOfObjLosses = Src.Fct.Blockage.ui_ShutoffNoOfObjLosses;
  Dest.Fct_V27.Blockage.b_BlockageActive = Src.Fct.Blockage.b_BlockageActive;
  Dest.Fct_V27.Blockage.ui8_UseFarNearScanForBlck = Src.Fct.Blockage.ui8_UseFarNearScanForBlck;
  Dest.Fct_V27.Blockage.f32_BlockageHiTempThreshFactor = Src.Fct.Blockage.f32_BlockageHiTempThreshFactor;
  Dest.Fct_V27.Blockage.i8_BlockageHiTempThresh = Src.Fct.Blockage.i8_BlockageHiTempThresh;
  Dest.Fct_V27.Blockage.i8_BlockageLoTempThresh = Src.Fct.Blockage.i8_BlockageLoTempThresh;
  Dest.Fct_V27.Blockage.ui8_BlockageSpeedThreshold = Src.Fct.Blockage.ui8_BlockageSpeedThreshold;
  Dest.Fct_V27.Blockage.ui8_BlockageWiperThresh = Src.Fct.Blockage.ui8_BlockageWiperThresh;
  Dest.Fct_V27.Blockage.b_BlockageUseTemperature = Src.Fct.Blockage.b_BlockageUseTemperature;
  Dest.Fct_V27.Blockage.b_BlockageUseWiper = Src.Fct.Blockage.b_BlockageUseWiper;

  Dest.Em_V6_V1.Cem = Src.Em.Cem;
  Dest.Em_V13.Cem = Src.Em.Cem;
  Dest.Em_V13.Lat = Src.Em.Lat;
  Dest.Em_V26 = Src.Em;

  Dest.Aln_V6_V1.f_ElevMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V1.f_AzimMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V1.b_ElevMonEnable = 1 ;
  Dest.Aln_V6_V1.b_AzimMonEnable = 1;
  Dest.Aln_V6_V2.f_ElevMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V2.f_AzimMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V2.b_ElevMonEnable = 1;
  Dest.Aln_V6_V2.b_AzimMonEnable = 1;
  Dest.Aln_V6_V2.b_EolChannelCalibEnable = 1;
  Dest.Aln_V6_V2.b_OnlineChannelCalibEnable = 1;
  Dest.Aln_V6_V2.b_OnlineAngleDevCalibEnable = 1;
  Dest.Aln_V6_V3.f_MisalignCorrectionRange = DEG2RAD(6);
  Dest.Aln_V6_V3.f_ElevMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V3.f_AzimMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V6_V3.b_ElevMonEnable = 1;
  Dest.Aln_V6_V3.b_AzimMonEnable = 1;
  Dest.Aln_V6_V3.b_EolChannelCalibEnable = 1;
  Dest.Aln_V6_V3.b_OnlineChannelCalibEnable = 1;
  Dest.Aln_V6_V3.b_OnlineAngleDevCalibEnable = 1;
  Dest.Aln_V10.f_ElevMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V10.f_AzimMonMaxDiff = DEG2RAD(15);
  Dest.Aln_V10.b_ElevMonEnable = 1;
  Dest.Aln_V10.b_AzimMonEnable = 1;
  Dest.Aln_V10.b_EolChannelCalibEnable = 1;
  Dest.Aln_V10.b_OnlineChannelCalibEnable = 1;
  Dest.Aln_V10.b_OnlineAngleDevCalibEnable = 1;
  Dest.Aln_V10.f_ElevMonMax = DEG2RAD(5);
  Dest.Aln_V10.f_AzimMonMax = DEG2RAD(5);
  Dest.Aln_V10.f_ElevEolMax = DEG2RAD(3);
  Dest.Aln_V10.f_AzimEolMax = DEG2RAD(5);
}

void CConvBSWAlgoParameters::Convert_Gen_to_V6_V1(BSW_s_AlgoParameters_ARS4xx_V6_V1::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 6u;
  Dest.Fct = Src.Fct_V6_V1;
  Dest.Em = Src.Em_V6_V1;
  Dest.Aln = Src.Aln_V6_V1;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V6_V2(BSW_s_AlgoParameters_ARS4xx_V6_V2::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 6u;
  Dest.Fct = Src.Fct_V6_V1;
  Dest.Em = Src.Em_V6_V1;
  Dest.Aln = Src.Aln_V6_V2;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V6_V3(BSW_s_AlgoParameters_ARS4xx_V6_V3::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 6u;
  Dest.Fct = Src.Fct_V6_V1;
  Dest.Em = Src.Em_V6_V1;
  Dest.Aln = Src.Aln_V6_V3;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V10(BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 10u;
  Dest.Fct = Src.Fct_V10;
  Dest.Em = Src.Em_V6_V1;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V13(BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x0Du;
  Dest.Fct = Src.Fct_V10;
  Dest.Em = Src.Em_V13;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V16(BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x0Du;
  Dest.Fct = Src.Fct_V16;
  Dest.Em = Src.Em_V13;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V19_1(BSW_s_AlgoParameters_ARS4xx_V19_1::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x13u;
  Dest.Fct = Src.Fct_V19_1;
  Dest.Em = Src.Em_V13;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V19_2(BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x13u;
  Dest.Fct = Src.Fct_V19_2;
  Dest.Em = Src.Em_V13;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V20(BSW_s_AlgoParameters_ARS4xx_V20::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x14u;
  Dest.Fct = Src.Fct_V20;
  Dest.Em = Src.Em_V13;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V21(BSW_s_AlgoParameters_ARS4xx_V21::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x15u;
  Dest.Fct = Src.Fct_V21;
  Dest.Em = Src.Em_V13;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V23(BSW_s_AlgoParameters_ARS4xx_V23::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x17u;
  Dest.Fct = Src.Fct_V23;
  Dest.Em = Src.Em_V13;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V26(BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x1Au;
  Dest.Fct = Src.Fct_V26;
  Dest.Em = Src.Em_V26;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V26_2(BSW_s_AlgoParameters_ARS4xx_V26_2::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x1Au;
  Dest.Fct = Src.Fct_V26_2;
  Dest.Em = Src.Em_V26;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V26_3(BSW_s_AlgoParameters_ARS4xx_V26_3::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x1Au;
  memcpy(&(Dest.Fct), &(Src.Fct_V26), sizeof(Dest.Fct));
  memcpy(&(Dest.Em), &(Src.Em_V26), sizeof(Dest.Em));
  //Dest.Fct = Src.Fct_V26_3;
  //Dest.Em = Src.Em_V26_3;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V27(BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x1Bu;
  Dest.Fct = Src.Fct_V26;
  Dest.Em = Src.Em_V26;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V27_1(BSW_s_AlgoParameters_ARS4xx_V27::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x1Bu;
  Dest.Fct = Src.Fct_V27;
  Dest.Em = Src.Em_V26;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V31(BSW_s_AlgoParameters_ARS4xx_V31::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x1Fu;
  Dest.Fct = Src.Fct_V26_2;
  Dest.Em = Src.Em_V26;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V32(BSW_s_AlgoParameters_ARS4xx_V32::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x20u;
  Dest.Fct = Src.Fct_V26;
  Dest.Em = Src.Em_V26;
  Dest.Aln = Src.Aln_V10;
}

void CConvBSWAlgoParameters::Convert_Gen_to_V33(BSW_s_AlgoParameters_ARS4xx_V33::BSW_s_AlgoParameters_t & Dest, const BSW_s_AlgoParameters_ARS4xx_GenAll::BSW_s_AlgoParameters_t & Src)
{
  Dest.uiVersionNumber = 0x21u;
  Dest.Fct = Src.Fct_V26;
  Dest.Em = Src.Em_V26;
}

long CConvBSWAlgoParameters::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo,
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);

  // First decide which version we are converting to
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    // If ports equal, then always compatible
    if (ulRPortSize == ulPPortSize)
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    // First decide from which version we are converting and fill the generic buffer accordingly
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V33])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V33])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 33u))
    {
      // Source Port V33
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V33::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V33::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V33_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V32])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V32])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 32u))
    {
      // Source Port V32
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V32::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V32::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V32_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V31])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V31])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 31u))
    {
      // Source Port V31
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V31::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V31::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V31_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V26_3])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V26_3])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 26u))
    {
      // Source Port V26_3 (ARS510)
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V26_3::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V26_3::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V26_3_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V26_2])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V26_2])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 26u))
    {
      // Source Port V26_2 (ARS4B0)
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V26_2::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V26_2::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V26_2_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V26])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V26])) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V27])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 26u) || (uDataVer == 27u)))
    {
      // Source Port V26 and V27
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V26_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V25])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V25])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 25u))
    {
      // Source Port V25          (Using the struct of V26 which had one additional structure member but because of alignment that doesn't matter)
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V26::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V26_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V23])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V23])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 23u))
    {
      // Source Port V23
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V23::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V23::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V23_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V21])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V21])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 21u))
    {
      // Source Port V21
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V21::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V21::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V21_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V20_1])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V20_1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 20u))
    {
      // Source Port V20
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V20::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V20::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V20_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V20_2])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V20_2])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 20u))
    {
      // Source Port V19.2 with provided version number 20
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V19_2_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V19_2])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V19_2])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 19u))
    {
      // Source Port V19.2
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V19_2::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V19_2_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V19_1])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V19_1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && (uDataVer == 19u))
    {
      // Source Port V19.1
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V19_1::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V19_1::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V19_1_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V16])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V18])) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V16])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 16u) || (uDataVer == 18u)))
    {
      // Source Port V16
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V16::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V16_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V13])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V13])) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V14])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 13u) || (uDataVer == 14u) || (uDataVer == 0)))
    {
      // Source Port V13
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V13::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V13_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V10])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V10])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 13u) || (uDataVer == 10u) || (uDataVer == 0)))
    {
      // Source Port V10
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V10::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V10_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V6_3])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V6_3])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 6u) || (uDataVer == 0)))
    {
      // Source Port V6_V3
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V6_V3::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V6_V3::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V6_V3_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V6_2])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V6_2])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 6u) || (uDataVer == 0)))
    {
      // Source Port V6_V2
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V6_V2::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V6_V2::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V6_V2_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }
    else if ((ulPPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V6_1])
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V6_1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 6u) || (uDataVer == 0)))
    {
      // Source Port V6_V1
      CConvBSWAlgoParameters::InitGen(m_BufGen);
      const BSW_s_AlgoParameters_ARS4xx_V6_V1::BSW_s_AlgoParameters_t & Src = *reinterpret_cast<BSW_s_AlgoParameters_ARS4xx_V6_V1::BSW_s_AlgoParameters_t*>(pPPortData);
      Convert_V6_V1_to_Gen(m_BufGen, Src);
      bGenBufferFilled = true;
    }

    if (bGenBufferFilled == true)
    {
      // Second decide to which version we are converting
      // and take the generic buffer to fill the destination buffer
      if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V33]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V33])))
      {
        // Destination port of V33
        Convert_Gen_to_V33(m_BufV33, m_BufGen);
        *pOutData = &m_BufV33;
        ulOutSize = sizeof(m_BufV33);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V32]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V32])))
      {
        // Destination port of V32
        Convert_Gen_to_V32(m_BufV32, m_BufGen);
        *pOutData = &m_BufV32;
        ulOutSize = sizeof(m_BufV32);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V31]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V31])))
      {
        // Destination port of V31
        Convert_Gen_to_V31(m_BufV31, m_BufGen);
        *pOutData = &m_BufV31;
        ulOutSize = sizeof(m_BufV31);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V27_1]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V27_1])))
      {
        // Destination port of V27
        Convert_Gen_to_V27_1(m_BufV27, m_BufGen);
        *pOutData = &m_BufV27;
        ulOutSize = sizeof(m_BufV27);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V27]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V27])))
      {
        // Destination port of V27
        Convert_Gen_to_V27(m_BufV26, m_BufGen);
        *pOutData = &m_BufV26;
        ulOutSize = sizeof(m_BufV26);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V26_3]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V26_3])))
      {
        // Destination port of V26_3 (ARS510)
        Convert_Gen_to_V26_3(m_BufV26_3, m_BufGen);
        *pOutData = &m_BufV26_3;
        ulOutSize = sizeof(m_BufV26_3);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V26_2]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V26_2])))
      {
        // Destination port of V26_2 (ARS4B0)
        Convert_Gen_to_V26_2(m_BufV26_2, m_BufGen);
        *pOutData = &m_BufV26_2;
        ulOutSize = sizeof(m_BufV26_2);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V26]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V26])))
      {
        // Destination port of V26
        Convert_Gen_to_V26(m_BufV26, m_BufGen);
        *pOutData = &m_BufV26;
        ulOutSize = sizeof(m_BufV26);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V25]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V25])))
      {
        // Destination port of V25          (Using the struct of V26 which had one additional structure member but because of alignment that doesn't matter)
        Convert_Gen_to_V26(m_BufV26, m_BufGen);
        *pOutData = &m_BufV26;
        ulOutSize = sizeof(m_BufV26);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V23]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V23])))
      {
        // Destination port of V23
        Convert_Gen_to_V23(m_BufV23, m_BufGen);
        *pOutData = &m_BufV23;
        ulOutSize = sizeof(m_BufV23);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V21]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V21])))
      {
        // Destination port of V21
        Convert_Gen_to_V21(m_BufV21, m_BufGen);
        *pOutData = &m_BufV21;
        ulOutSize = sizeof(m_BufV21);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V20_1]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V20_1])))
      {
        // Destination port of V20
        Convert_Gen_to_V20(m_BufV20, m_BufGen);
        *pOutData = &m_BufV20;
        ulOutSize = sizeof(m_BufV20);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V20_2]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V20_2])))
      {
        // Destination port (with size) of V19.2 and request version number 20
        Convert_Gen_to_V19_2(m_BufV19_2, m_BufGen);
        *pOutData = &m_BufV19_2;
        ulOutSize = sizeof(m_BufV19_2);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V19_2]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V19_2])))
      {
        // Destination port of V19.2 with request version number 19
        Convert_Gen_to_V19_2(m_BufV19_2, m_BufGen);
        *pOutData = &m_BufV19_2;
        ulOutSize = sizeof(m_BufV19_2);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V19_1]) && (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V19_1])))
      {
        // Destination port of V19.1
        Convert_Gen_to_V19_1(m_BufV19_1, m_BufGen);
        *pOutData = &m_BufV19_1;
        ulOutSize = sizeof(m_BufV19_1);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V16]) && ((requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V18])) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V16]))))
      {
        // Destination port of V16
        Convert_Gen_to_V16(m_BufV16, m_BufGen);
        *pOutData = &m_BufV16;
        ulOutSize = sizeof(m_BufV16);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V13]) && ((requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V14])) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V13])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Destination port of V13 (and V14)
        Convert_Gen_to_V13(m_BufV13, m_BufGen);
        *pOutData = &m_BufV13;
        ulOutSize = sizeof(m_BufV13);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V10]) && ((requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V13])) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V12])) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V10])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Destination port of V10 (and V12, V13)
        Convert_Gen_to_V10(m_BufV10, m_BufGen);
        *pOutData = &m_BufV10;
        ulOutSize = sizeof(m_BufV10);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V6_3]) && ((requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V6_3])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Destination port of V6_V3
        Convert_Gen_to_V6_V3(m_BufV6_3, m_BufGen);
        *pOutData = &m_BufV6_3;
        ulOutSize = sizeof(m_BufV6_3);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V6_2]) && ((requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V6_2])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Destination port of V6_V2
        Convert_Gen_to_V6_V2(m_BufV6_2, m_BufGen);
        *pOutData = &m_BufV6_2;
        ulOutSize = sizeof(m_BufV6_2);
        lRet = SIM_ERR_OK;
      }
      else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V6_1]) && ((requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V6_1])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Destination port of V6_V1
        Convert_Gen_to_V6_V1(m_BufV6_1, m_BufGen);
        *pOutData = &m_BufV6_1;
        ulOutSize = sizeof(m_BufV6_1);
        lRet = SIM_ERR_OK;
      }
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvBSWAlgoParameters::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V32]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V32]))))
    {
      InitV32(m_BufV32);
      *pDefaultData = &m_BufV32;
      ulDefaultSize = sizeof(m_BufV32);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V31]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V31]))))
    {
      InitV31(m_BufV31);
      *pDefaultData = &m_BufV31;
      ulDefaultSize = sizeof(m_BufV31);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V27_1]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V27_1]))))
    {
      InitV27(m_BufV27);
      *pDefaultData = &m_BufV27;
      ulDefaultSize = sizeof(m_BufV27);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V26_3]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V26_3]))))
    {
      InitV26_3(m_BufV26_3);
      *pDefaultData = &m_BufV26_3;
      ulDefaultSize = sizeof(m_BufV26_3);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V26_2]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V26_2]))))
    {
      InitV26_2(m_BufV26_2);
      *pDefaultData = &m_BufV26_2;
      ulDefaultSize = sizeof(m_BufV26_2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V26]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V26]))))
    {
      InitV26(m_BufV26);
      *pDefaultData = &m_BufV26;
      ulDefaultSize = sizeof(m_BufV26);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V25]) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V25]))))
    {
      // Destination port of V25 Using the struct of V26 which had one additional structure member but because of alignment that doesn't matter
      InitV26(m_BufV26);
      *pDefaultData = &m_BufV26;
      ulDefaultSize = sizeof(m_BufV26);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V23]) && ((requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V23]) || requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitV23(m_BufV23);
      *pDefaultData = &m_BufV23;
      ulDefaultSize = sizeof(m_BufV23);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[BSW_ALGO_PARAM_RTE_V21]) && ((requestPortVersionInfo.Equals(A_VERSIONS[BSW_ALGO_PARAM_RTE_V21]) || requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitV21(m_BufV21);
      *pDefaultData = &m_BufV21;
      ulDefaultSize = sizeof(m_BufV21);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV20)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION20.Equals(&requestPortVersionInfo))))
    {
      InitV20(m_BufV20);
      *pDefaultData = &m_BufV20;
      ulDefaultSize = sizeof(m_BufV20);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV19_2)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION19.Equals(&requestPortVersionInfo))))
    {
      InitV19_2(m_BufV19_2);
      *pDefaultData = &m_BufV19_2;
      ulDefaultSize = sizeof(m_BufV19_2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV19_1)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION19.Equals(&requestPortVersionInfo))))
    {
      InitV19_1(m_BufV19_1);
      *pDefaultData = &m_BufV19_1;
      ulDefaultSize = sizeof(m_BufV19_1);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV16)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION16.Equals(&requestPortVersionInfo))))
    {
      InitV16(m_BufV16);
      *pDefaultData = &m_BufV16;
      ulDefaultSize = sizeof(m_BufV16);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV13)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION13.Equals(&requestPortVersionInfo))))
    {
      InitV13(m_BufV13);
      *pDefaultData = &m_BufV13;
      ulDefaultSize = sizeof(m_BufV13);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV10)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION10.Equals(&requestPortVersionInfo))))
    {
      InitV10(m_BufV10);
      *pDefaultData = &m_BufV10;
      ulDefaultSize = sizeof(m_BufV10);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV6_3)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION6.Equals(&requestPortVersionInfo))))
    {
      InitV6_3(m_BufV6_3);
      *pDefaultData = &m_BufV6_3;
      ulDefaultSize = sizeof(m_BufV6_3);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV6_2)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION6.Equals(&requestPortVersionInfo))))
    {
      InitV6_2(m_BufV6_2);
      *pDefaultData = &m_BufV6_2;
      ulDefaultSize = sizeof(m_BufV6_2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_BufV6_1)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION6.Equals(&requestPortVersionInfo))))
    {
      InitV6_1(m_BufV6_1);
      *pDefaultData = &m_BufV6_1;
      ulDefaultSize = sizeof(m_BufV6_1);
      lRet = SIM_ERR_OK;
    }
    else
    {
      // No conversion available
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvBSWAlgoParameters::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
  {
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else
  {
    if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
    {
      if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
      {
        bResult = true;
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvBSWAlgoParameters::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // If ports equal, then always compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
    {
      if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
      {
        bResult = true;
      }
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateBswAlgoParamConverter(void)
{
  return new CConvBSWAlgoParameters();
}
