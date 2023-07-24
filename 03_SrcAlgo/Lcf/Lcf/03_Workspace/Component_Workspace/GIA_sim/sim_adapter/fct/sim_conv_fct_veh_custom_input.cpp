/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_fct_veh_custom_input.cpp

  DESCRIPTION:          Converter class for FCTVehCustomInput

  AUTHOR:               Simon Sinnstein

  CREATION DATE:        02.09.2014

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_fct_veh_custom_input.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:17CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.6 2016/11/15 16:35:37CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V8 and V10 (and V9 = V10)
  CHANGES:              Revision 1.5 2016/09/14 13:46:43CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              +V7a (Hyundayi)
  CHANGES:              Revision 1.4 2016/08/31 12:53:19CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              ] V7 for ARS430BW18
  CHANGES:              Revision 1.3 2016/08/23 07:04:42CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V6 for ARS430MI18
  CHANGES:              Revision 1.2 2014/10/09 14:44:56CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Update for AL_ARS400EN_01.15.01
  CHANGES:              LongCtrlInputV10
  CHANGES:              DimInputCustomV6_2
  CHANGES:              update FCTVehCustomInput
  CHANGES:              - Added comments -  berndtt1 [Oct 10, 2014 7:43:22 AM CEST]
  CHANGES:              Change Package : 270187:1 http://mks-psad:7002/im/viewissue?selection=270187
  CHANGES:              Revision 1.1 2014/09/03 15:44:13CEST Sinnstein, Simon (uidw0203) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/fct/project.pj


**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_fct_veh_custom_input.h"
#include "sim_versioninfo_impl.h"

//
// FCTVehCustomInput structure declarations
//

// General used defines
typedef unsigned long AlgoDataTimeStamp_t;  /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */
typedef unsigned short AlgoCycleCounter_t;  /* Algo cycle counter @min:0 @max:65535 */
typedef unsigned char AlgoSignalState_t;    /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */

typedef struct SignalHeader_t
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;  /* Common header for all structured data types */


namespace FCTVehCustomInputV1
{
  typedef uint8 FCTTransmissionGear_t;     /* Indicates current used gear position @min: 0 @max:12 @values: enum { VEH_NINTH_GEAR=9,VEH_FOURTH_GEAR=4,VEH_SECOND_GEAR=2,VEH_THIRD_GEAR=3,VEH_POWER_FREE=12,VEH_EIGHTH_GEAR=8,VEH_FIFTH_GEAR=5,VEH_NEUTRAL_GEAR=0,VEH_SIXTH_GEAR=6,VEH_FIRST_GEAR=1,VEH_PARK_GEAR=11,VEH_REVERSE_GEAR=10,VEH_SEVENTH_GEAR=7,}  */

  typedef enum FCTTransmissionGear_enum_t
  {
    VEH_NEUTRAL_GEAR = 0,
    VEH_FIRST_GEAR = 1,
    VEH_SECOND_GEAR = 2,
    VEH_THIRD_GEAR = 3,
    VEH_FOURTH_GEAR = 4,
    VEH_FIFTH_GEAR = 5,
    VEH_SIXTH_GEAR = 6,
    VEH_SEVENTH_GEAR = 7,
    VEH_EIGHTH_GEAR = 8,
    VEH_NINTH_GEAR = 9,
    VEH_REVERSE_GEAR = 10,
    VEH_PARK_GEAR = 11,
    VEH_POWER_FREE = 12,
  } FCTTransmissionGear_enum_t;

  typedef uint8 EngRun_Stat_t;    /* Indicates if engine running, needed for activation ACC @min: 0 @max:6 @values: enum { ENGRUN_IDLE_STBL=3,ENGRUN_NDEF6=6,ENGRUN_START=1,ENGRUN_STOP=0,ENGRUN_LIMITED=5,ENGRUN_IDLE_UNSTBL=2,ENGRUN_UNLIMITED=4,}  */

  typedef enum EngRun_Stat_enum_t
  {
    ENGRUN_STOP = 0,
    ENGRUN_START = 1,
    ENGRUN_IDLE_UNSTBL = 2,
    ENGRUN_IDLE_STBL = 3,
    ENGRUN_UNLIMITED = 4,
    ENGRUN_LIMITED = 5,
    ENGRUN_NDEF6 = 6,
  } EngRun_Stat_enum_t;

  typedef uint8 PwrFreeD_Stat_TCM_t;    /* TCM 'Power-free in D' sate @min: 0 @max:3 @values: enum { IN_SAIL_ENABLE=1,IN_SAIL_DISABLE=0,IN_SAIL_ACTIVE=3,IN_SAIL_TRANSITION=2,}  */

  typedef enum PwrFreeD_Stat_TCM_enum_t
  {
    IN_SAIL_DISABLE=0,
    IN_SAIL_ENABLE=1,
    IN_SAIL_TRANSITION=2,
    IN_SAIL_ACTIVE=3,
  } PwrFreeD_Stat_TCM_enum_t;

  typedef uint8 VehAccel_X_AS_Actv_Rs_t;   /* Active assistance system response from ESP @min: 0 @max:30 @values: enum { AS_ACTV_TBCC_LO_ACCEL_ACTV=27,AS_ACTV_TBCC_HI_TRQ_ACTV=29,AS_ACTV_ADTR_ACTV=4,AS_ACTV_DRV_AWAY_ACTV=25,AS_ACTV_REM_PARK_ACTV=21,AS_ACTV_PARK_SC_ACTV=22,AS_ACTV_TBCC_LO_TRQ_ACTV=30,AS_ACTV_DSR_ACTV=7,AS_ACTV_LIM_ACTV=18,AS_ACTV_BAS_PLUS_ACTV=5,AS_ACTV_WTSL_ACTV=19,AS_ACTV_CMS_P_ES2_ACTV=15,AS_ACTV_TBCC_HI_ACCEL_ACTV=28,AS_ACTV_CC_ACTV=17,AS_ACTV_CMSQ_ES1_ACTV=11,AS_ACTV_CMSQ_ES2_ACTV=13,AS_ACTV_CTA_ACTV=24,AS_ACTV_PARK_LIM_ACTV=23,AS_ACTV_BPQ_ACTV=10,AS_ACTV_CMS_P_ES1_ACTV=14,AS_ACTV_CMS_ES2_ACTV=9,AS_ACTV_TRANS_MD_LIM_ACTV=20,AS_ACTV_CMS_ES1_ACTV=8,AS_ACTV_CMS_REAR_ACTV=12,AS_ACTV_BAS_PLUS_P_ACTV=6,AS_ACTV_NDEF4=16,AS_ACTV_PARK_PLUS_BRK_ACTV=26,AS_ACTV_IDLE=0,AS_ACTV_NDEF1=1,AS_ACTV_NDEF2=2,AS_ACTV_NDEF3=3,}  */

  typedef enum VehAccel_X_AS_Actv_Rs_enum_t
  {
    AS_ACTV_IDLE= 0,
    AS_ACTV_NDEF1 = 1,
    AS_ACTV_NDEF2 = 2,
    AS_ACTV_NDEF3 = 3,
    AS_ACTV_ADTR_ACTV = 4,
    AS_ACTV_BAS_PLUS_ACTV = 5,
    AS_ACTV_BAS_PLUS_P_ACTV = 6,
    AS_ACTV_DSR_ACTV = 7,
    AS_ACTV_CMS_ES1_ACTV = 8,
    AS_ACTV_CMS_ES2_ACTV = 9,
    AS_ACTV_BPQ_ACTV = 10,
    AS_ACTV_CMSQ_ES1_ACTV = 11,
    AS_ACTV_CMS_REAR_ACTV = 12,
    AS_ACTV_CMSQ_ES2_ACTV = 13,
    AS_ACTV_CMS_P_ES1_ACTV = 14,
    AS_ACTV_CMS_P_ES2_ACTV = 15,
    AS_ACTV_NDEF4 = 16,
    AS_ACTV_CC_ACTV = 17,
    AS_ACTV_LIM_ACTV = 18,
    AS_ACTV_WTSL_ACTV = 19,
    AS_ACTV_TRANS_MD_LIM_ACTV = 20,
    AS_ACTV_REM_PARK_ACTV = 21,
    AS_ACTV_PARK_SC_ACTV = 22,
    AS_ACTV_PARK_LIM_ACTV = 23,
    AS_ACTV_CTA_ACTV = 24,
    AS_ACTV_DRV_AWAY_ACTV = 25,
    AS_ACTV_PARK_PLUS_BRK_ACTV = 26,
    AS_ACTV_TBCC_LO_ACCEL_ACTV = 27,
    AS_ACTV_TBCC_HI_ACCEL_ACTV = 28,
    AS_ACTV_TBCC_HI_TRQ_ACTV = 29,
    AS_ACTV_TBCC_LO_TRQ_ACTV = 30,
  } VehAccel_X_AS_Actv_Rs_enum_t;

  typedef uint8 VehAccel_X_Dsabl_Rq_ESP_t;  /* Vehicle longitudinal acceleration disable request @min: 0 @max:2 @values: enum { ACCEL_X_ESP_TMP_DISABLE=1,ACCEL_X_ESP_IDLE=0,ACCEL_X_ESP_CONT_DISABLE=2,}  */

  typedef enum VehAccel_X_Dsabl_Rq_ESP_enum_t
  {
    ACCEL_X_ESP_IDLE=0,
    ACCEL_X_ESP_TMP_DISABLE=1,
    ACCEL_X_ESP_CONT_DISABLE=2,
  } VehAccel_X_Dsabl_Rq_ESP_enum_t;

  typedef uint8 ESP_Oprtn_Stat_AS_t;  /* ESP operation state for assistance systems @min: 0 @max:9 @values: enum { ESP_STAT_ESP_ASR_CTRL_ACTV=6,ESP_STAT_FAULT=5,ESP_STAT_INIT=1,ESP_STAT_AMG_OFF=7,ESP_STAT_OFF_AMG_SPORT=8,ESP_STAT_ABS_CTRL_ACTV=9,ESP_STAT_TBCC=4,ESP_STAT_EMT=3,ESP_STAT_NORM=0,ESP_STAT_DIAG=2,}  */

  typedef enum ESP_Oprtn_Stat_AS_enum_t
  {
    ESP_STAT_NORM=0,
    ESP_STAT_INIT=1,
    ESP_STAT_DIAG=2,
    ESP_STAT_EMT=3,
    ESP_STAT_TBCC=4,
    ESP_STAT_FAULT=5,
    ESP_STAT_ESP_ASR_CTRL_ACTV=6,
    ESP_STAT_AMG_OFF=7,
    ESP_STAT_OFF_AMG_SPORT=8,
    ESP_STAT_ABS_CTRL_ACTV=9,
  } ESP_Oprtn_Stat_AS_enum_t;

  typedef uint8 FCTVehDPCMdASRq_t;  /* Driving program control: assistance system mode request @min: 1 @max:5 @values: enum { ECO=5,COMFORT=1,SPORT=3,SPORT_PLUS=4,COMFORT_PLUS=2,}  */

  typedef enum FCTVehDPCMdASRq_enum_t
  {
    COMFORT = 1,
    COMFORT_PLUS = 2,
    SPORT = 3,
    SPORT_PLUS = 4,
    ECO = 5,
  } FCTVehDPCMdASRq_enum_t;

  typedef uint8 Bckl_Sw_D_Stat_t;      /* Buckle switch driver state @min: 0 @max:2 @values: enum { DRV_BUCKLE_OK=0,DRV_BUCKLE_FLT=2,DRV_BUCKLE_NOT=1,}  */

  typedef enum Bckl_Sw_D_Stat_enum_t
  {
    DRV_BUCKLE_OK = 0,
    DRV_BUCKLE_NOT = 1,
    DRV_BUCKLE_FLT = 2,
  } Bckl_Sw_D_Stat_enum_t;

  typedef struct FCTVehPowerTrain_t
  {
    FCTTransmissionGear_t ActualGear;
    FCTTransmissionGear_t TargetGear;
    EngRun_Stat_t EngRun_Stat;
    boolean PowerTrainReady;
    boolean KickDnSw_Psd;
    boolean SSA_EngSp;
    unsigned char AccelPdlPosn_Raw;
    PwrFreeD_Stat_TCM_t PwrFreeD_Stat_TCM;
  } FCTVehPowerTrain_t;  /* Powertrain information */

  typedef struct ExtDASystem_t
  {
    boolean BrkIntrvntn_Actv_CWA;
    boolean DSR_Actv;
    boolean BrkIntrvntn_Actv_LDP;
    VehAccel_X_AS_Actv_Rs_t VehAccel_X_AS_Actv_Rs;
  } ExtDASystem_t;  /* External driver assistance system information */

  typedef struct FCTVehESP_t
  {
    VehAccel_X_Dsabl_Rq_ESP_t VehAccel_X_Dsabl_Rq_ESP;
    ESP_Oprtn_Stat_AS_t ESP_Oprtn_Stat_AS;
    boolean BrkIntrvntn_Actv_ESP;
    FCTVehDPCMdASRq_t DPC_Md_AS_Rq;
  } FCTVehESP_t;  /* ESP information */

  typedef struct FCTVehPassSafetySys_t
  {
    Bckl_Sw_D_Stat_t Bckl_Sw_D_Stat;
    boolean Impact_X;
  } FCTVehPassSafetySys_t;  /* Passive Safety Systems Information */

  typedef struct FCTVehCustomInput_t  /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCTVehPowerTrain_t FCTVehPowerTrain;
    FCTVehESP_t FCTVehESP;
    FCTVehPassSafetySys_t FCTVehPassSafetySys;
    ExtDASystem_t ExtDASystem;
  } FCTVehCustomInput_t;    /* Vehicle input signals for FCT 20 Cycle @vaddr:0x20219600 @vaddr_defs: FCT_MEAS_ID_FCT_VEH_CUSTOM_INPUT @cycleid:FCT_VEH_IN @vname:FCTVehCustomInput */

};  // End of namespace FCTVehCustomInputV1


namespace FCTVehCustomInputV2
{
  typedef uint8 FCTTransmissionGear_t;     /* Indicates current used gear position @min: 0 @max:12 @values: enum { VEH_NINTH_GEAR=9,VEH_FOURTH_GEAR=4,VEH_SECOND_GEAR=2,VEH_THIRD_GEAR=3,VEH_POWER_FREE=12,VEH_EIGHTH_GEAR=8,VEH_FIFTH_GEAR=5,VEH_NEUTRAL_GEAR=0,VEH_SIXTH_GEAR=6,VEH_FIRST_GEAR=1,VEH_PARK_GEAR=11,VEH_REVERSE_GEAR=10,VEH_SEVENTH_GEAR=7,}  */

  typedef enum FCTTransmissionGear_enum_t
  {
    VEH_NEUTRAL_GEAR = 0,
    VEH_FIRST_GEAR = 1,
    VEH_SECOND_GEAR = 2,
    VEH_THIRD_GEAR = 3,
    VEH_FOURTH_GEAR = 4,
    VEH_FIFTH_GEAR = 5,
    VEH_SIXTH_GEAR = 6,
    VEH_SEVENTH_GEAR = 7,
    VEH_EIGHTH_GEAR = 8,
    VEH_NINTH_GEAR = 9,
    VEH_REVERSE_GEAR = 10,
    VEH_PARK_GEAR = 11,
    VEH_POWER_FREE = 12,
  } FCTTransmissionGear_enum_t;

  typedef uint8 EngRun_Stat_t;    /* Indicates if engine running, needed for activation ACC @min: 0 @max:6 @values: enum { ENGRUN_IDLE_STBL=3,ENGRUN_NDEF6=6,ENGRUN_START=1,ENGRUN_STOP=0,ENGRUN_LIMITED=5,ENGRUN_IDLE_UNSTBL=2,ENGRUN_UNLIMITED=4,}  */

  typedef enum EngRun_Stat_enum_t
  {
    ENGRUN_STOP = 0,
    ENGRUN_START = 1,
    ENGRUN_IDLE_UNSTBL = 2,
    ENGRUN_IDLE_STBL = 3,
    ENGRUN_UNLIMITED = 4,
    ENGRUN_LIMITED = 5,
    ENGRUN_NDEF6 = 6,
  } EngRun_Stat_enum_t;

  typedef uint8 PwrFreeD_Stat_TCM_t;    /* TCM 'Power-free in D' sate @min: 0 @max:3 @values: enum { IN_SAIL_ENABLE=1,IN_SAIL_DISABLE=0,IN_SAIL_ACTIVE=3,IN_SAIL_TRANSITION=2,}  */

  typedef enum PwrFreeD_Stat_TCM_enum_t
  {
    IN_SAIL_DISABLE=0,
    IN_SAIL_ENABLE=1,
    IN_SAIL_TRANSITION=2,
    IN_SAIL_ACTIVE=3,
  } PwrFreeD_Stat_TCM_enum_t;

  typedef uint8 FCTVehPTSignalState_t;    /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:64 @values: enum { KICK_DN_SW_PSD_ST=8,SSA_ENG_SP_ST=16,POWER_TRAIN_READY_ST=4,ACTUAL_GEAR_ST=1,TARGET_GEAR_ST=2,PWR_FREE_D_STAT_TCM_ST=64,ACCEL_PDL_POSN_RAW_ST=32,}  */

  typedef enum FCTVehPTSignalState_enum_t
  {
    ACTUAL_GEAR_ST = 1,
    TARGET_GEAR_ST = 2,
    POWER_TRAIN_READY_ST = 4,
    KICK_DN_SW_PSD_ST = 8,
    SSA_ENG_SP_ST = 16,
    ACCEL_PDL_POSN_RAW_ST = 32,
    PWR_FREE_D_STAT_TCM_ST = 64,
  } FCTVehPTSignalState_enum_t;

  typedef uint8 VehAccel_X_AS_Actv_Rs_t;   /* Active assistance system response from ESP @min: 0 @max:30 @values: enum { AS_ACTV_TBCC_LO_ACCEL_ACTV=27,AS_ACTV_TBCC_HI_TRQ_ACTV=29,AS_ACTV_ADTR_ACTV=4,AS_ACTV_DRV_AWAY_ACTV=25,AS_ACTV_REM_PARK_ACTV=21,AS_ACTV_PARK_SC_ACTV=22,AS_ACTV_TBCC_LO_TRQ_ACTV=30,AS_ACTV_DSR_ACTV=7,AS_ACTV_LIM_ACTV=18,AS_ACTV_BAS_PLUS_ACTV=5,AS_ACTV_WTSL_ACTV=19,AS_ACTV_CMS_P_ES2_ACTV=15,AS_ACTV_TBCC_HI_ACCEL_ACTV=28,AS_ACTV_CC_ACTV=17,AS_ACTV_CMSQ_ES1_ACTV=11,AS_ACTV_CMSQ_ES2_ACTV=13,AS_ACTV_CTA_ACTV=24,AS_ACTV_PARK_LIM_ACTV=23,AS_ACTV_BPQ_ACTV=10,AS_ACTV_CMS_P_ES1_ACTV=14,AS_ACTV_CMS_ES2_ACTV=9,AS_ACTV_TRANS_MD_LIM_ACTV=20,AS_ACTV_CMS_ES1_ACTV=8,AS_ACTV_CMS_REAR_ACTV=12,AS_ACTV_BAS_PLUS_P_ACTV=6,AS_ACTV_NDEF4=16,AS_ACTV_PARK_PLUS_BRK_ACTV=26,AS_ACTV_IDLE=0,AS_ACTV_NDEF1=1,AS_ACTV_NDEF2=2,AS_ACTV_NDEF3=3,}  */

  typedef enum VehAccel_X_AS_Actv_Rs_enum_t
  {
    AS_ACTV_IDLE= 0,
    AS_ACTV_NDEF1 = 1,
    AS_ACTV_NDEF2 = 2,
    AS_ACTV_NDEF3 = 3,
    AS_ACTV_ADTR_ACTV = 4,
    AS_ACTV_BAS_PLUS_ACTV = 5,
    AS_ACTV_BAS_PLUS_P_ACTV = 6,
    AS_ACTV_DSR_ACTV = 7,
    AS_ACTV_CMS_ES1_ACTV = 8,
    AS_ACTV_CMS_ES2_ACTV = 9,
    AS_ACTV_BPQ_ACTV = 10,
    AS_ACTV_CMSQ_ES1_ACTV = 11,
    AS_ACTV_CMS_REAR_ACTV = 12,
    AS_ACTV_CMSQ_ES2_ACTV = 13,
    AS_ACTV_CMS_P_ES1_ACTV = 14,
    AS_ACTV_CMS_P_ES2_ACTV = 15,
    AS_ACTV_NDEF4 = 16,
    AS_ACTV_CC_ACTV = 17,
    AS_ACTV_LIM_ACTV = 18,
    AS_ACTV_WTSL_ACTV = 19,
    AS_ACTV_TRANS_MD_LIM_ACTV = 20,
    AS_ACTV_REM_PARK_ACTV = 21,
    AS_ACTV_PARK_SC_ACTV = 22,
    AS_ACTV_PARK_LIM_ACTV = 23,
    AS_ACTV_CTA_ACTV = 24,
    AS_ACTV_DRV_AWAY_ACTV = 25,
    AS_ACTV_PARK_PLUS_BRK_ACTV = 26,
    AS_ACTV_TBCC_LO_ACCEL_ACTV = 27,
    AS_ACTV_TBCC_HI_ACCEL_ACTV = 28,
    AS_ACTV_TBCC_HI_TRQ_ACTV = 29,
    AS_ACTV_TBCC_LO_TRQ_ACTV = 30,
  } VehAccel_X_AS_Actv_Rs_enum_t;

  typedef uint8 ExtDASystemSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:8 @values: enum { DSR_ACTV_ST=2,BRK_INTRVNTN_ACTV_LDP=4,VEH_ACCEL_X_AS_ACTV_RS_ST=8,BRK_INTRVNTN_ACTV_CWA=1,}  */

  typedef enum ExtDASystemSignalState_enum_t
  {
    BRK_INTRVNTN_ACTV_CWA = 1,
    DSR_ACTV_ST = 2,
    BRK_INTRVNTN_ACTV_LDP = 4,
    VEH_ACCEL_X_AS_ACTV_RS_ST = 8,
  } ExtDASystemSignalState_enum_t;

  typedef uint8 VehAccel_X_Dsabl_Rq_ESP_t;  /* Vehicle longitudinal acceleration disable request @min: 0 @max:2 @values: enum { ACCEL_X_ESP_TMP_DISABLE=1,ACCEL_X_ESP_IDLE=0,ACCEL_X_ESP_CONT_DISABLE=2,}  */

  typedef enum VehAccel_X_Dsabl_Rq_ESP_enum_t
  {
    ACCEL_X_ESP_IDLE=0,
    ACCEL_X_ESP_TMP_DISABLE=1,
    ACCEL_X_ESP_CONT_DISABLE=2,
  } VehAccel_X_Dsabl_Rq_ESP_enum_t;

  typedef uint8 ESP_Oprtn_Stat_AS_t;  /* ESP operation state for assistance systems @min: 0 @max:9 @values: enum { ESP_STAT_ESP_ASR_CTRL_ACTV=6,ESP_STAT_FAULT=5,ESP_STAT_INIT=1,ESP_STAT_AMG_OFF=7,ESP_STAT_OFF_AMG_SPORT=8,ESP_STAT_ABS_CTRL_ACTV=9,ESP_STAT_TBCC=4,ESP_STAT_EMT=3,ESP_STAT_NORM=0,ESP_STAT_DIAG=2,}  */

  typedef enum ESP_Oprtn_Stat_AS_enum_t
  {
    ESP_STAT_NORM=0,
    ESP_STAT_INIT=1,
    ESP_STAT_DIAG=2,
    ESP_STAT_EMT=3,
    ESP_STAT_TBCC=4,
    ESP_STAT_FAULT=5,
    ESP_STAT_ESP_ASR_CTRL_ACTV=6,
    ESP_STAT_AMG_OFF=7,
    ESP_STAT_OFF_AMG_SPORT=8,
    ESP_STAT_ABS_CTRL_ACTV=9,
  } ESP_Oprtn_Stat_AS_enum_t;

  typedef uint8 FCTVehDPCMdASRq_t;  /* Driving program control: assistance system mode request @min: 1 @max:5 @values: enum { ECO=5,COMFORT=1,SPORT=3,SPORT_PLUS=4,COMFORT_PLUS=2,}  */

  typedef enum FCTVehDPCMdASRq_enum_t
  {
    COMFORT = 1,
    COMFORT_PLUS = 2,
    SPORT = 3,
    SPORT_PLUS = 4,
    ECO = 5,
  } FCTVehDPCMdASRq_enum_t;

  typedef uint8 FCTVehESPSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:8 @values: enum { VEH_ACCEL_X_DISABL_ST=1,ESP_OPRTN_STAT_AS_ST=2,BRK_INTRVNTN_ACTV_ESP_ST=4,DPC_MD_AS_RQ_ST=8,}  */

  typedef enum FCTVehESPSignalState_enum_t
  {
    VEH_ACCEL_X_DISABL_ST = 1,
    ESP_OPRTN_STAT_AS_ST = 2,
    BRK_INTRVNTN_ACTV_ESP_ST = 4,
    DPC_MD_AS_RQ_ST = 8,
  } FCTVehESPSignalState_enum_t;

  typedef uint8 Bckl_Sw_D_Stat_t;      /* Buckle switch driver state @min: 0 @max:2 @values: enum { DRV_BUCKLE_OK=0,DRV_BUCKLE_FLT=2,DRV_BUCKLE_NOT=1,}  */

  typedef enum Bckl_Sw_D_Stat_enum_t
  {
    DRV_BUCKLE_OK = 0,
    DRV_BUCKLE_NOT = 1,
    DRV_BUCKLE_FLT = 2,
  } Bckl_Sw_D_Stat_enum_t;

  typedef uint8 FCTVehPSSignalState_t;   /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:2 @values: enum { IMPACT_X_ST=2,BCKL_SW_D_STAT=1,}  */

  typedef enum FCTVehPSSignalState_enum_t
  {
    BCKL_SW_D_STAT = 1,
    IMPACT_X_ST = 2,
  } FCTVehPSSignalState_enum_t;

  typedef struct FCTVehPowerTrain_t
  {
    FCTTransmissionGear_t ActualGear;
    FCTTransmissionGear_t TargetGear;
    EngRun_Stat_t EngRun_Stat;
    boolean PowerTrainReady;
    boolean KickDnSw_Psd;
    boolean SSA_EngSp;
    unsigned char AccelPdlPosn_Raw;
    PwrFreeD_Stat_TCM_t PwrFreeD_Stat_TCM;
    FCTVehPTSignalState_t FCTVehPTSignalState;
  } FCTVehPowerTrain_t;  /* Powertrain information */

  typedef struct ExtDASystem_t
  {
    boolean BrkIntrvntn_Actv_CWA;
    boolean DSR_Actv;
    boolean BrkIntrvntn_Actv_LDP;
    VehAccel_X_AS_Actv_Rs_t VehAccel_X_AS_Actv_Rs;
    ExtDASystemSignalState_t ExtDASystemSignalState;
  } ExtDASystem_t;  /* External driver assistance system information */

  typedef struct FCTVehESP_t
  {
    VehAccel_X_Dsabl_Rq_ESP_t VehAccel_X_Dsabl_Rq_ESP;
    ESP_Oprtn_Stat_AS_t ESP_Oprtn_Stat_AS;
    boolean BrkIntrvntn_Actv_ESP;
    FCTVehDPCMdASRq_t DPC_Md_AS_Rq;
    FCTVehESPSignalState_t FCTVehESPSignalState;
  } FCTVehESP_t;  /* ESP information */

  typedef struct FCTVehPassSafetySys_t
  {
    Bckl_Sw_D_Stat_t Bckl_Sw_D_Stat;
    boolean Impact_X;
    FCTVehPSSignalState_t FCTVehPSSignalState;
  } FCTVehPassSafetySys_t;  /* Passive Safety Systems Information */

  typedef struct FCTVehCustomInput_t  /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCTVehPowerTrain_t FCTVehPowerTrain;
    FCTVehESP_t FCTVehESP;
    FCTVehPassSafetySys_t FCTVehPassSafetySys;
    ExtDASystem_t ExtDASystem;
  } FCTVehCustomInput_t;    /* Vehicle input signals for FCT 20 Cycle @vaddr:0x20219600 @vaddr_defs: FCT_MEAS_ID_FCT_VEH_CUSTOM_INPUT @cycleid:FCT_VEH_IN @vname:FCTVehCustomInput */
};  // End of namespace FCTVehCustomInputV2


namespace FCTVehCustomInputV6
{
  typedef uint8 FCTTransmissionGear_t;     /* Indicates current used gear position @min: 0 @max:12 @values: enum { VEH_NINTH_GEAR=9,VEH_FOURTH_GEAR=4,VEH_SECOND_GEAR=2,VEH_THIRD_GEAR=3,VEH_POWER_FREE=12,VEH_EIGHTH_GEAR=8,VEH_FIFTH_GEAR=5,VEH_NEUTRAL_GEAR=0,VEH_SIXTH_GEAR=6,VEH_FIRST_GEAR=1,VEH_PARK_GEAR=11,VEH_REVERSE_GEAR=10,VEH_SEVENTH_GEAR=7,}  */
  typedef uint8 EngRun_Stat_t;    /* Indicates if engine running, needed for activation ACC @min: 0 @max:6 @values: enum { ENGRUN_IDLE_STBL=3,ENGRUN_NDEF6=6,ENGRUN_START=1,ENGRUN_STOP=0,ENGRUN_LIMITED=5,ENGRUN_IDLE_UNSTBL=2,ENGRUN_UNLIMITED=4,}  */
  typedef uint8 PwrFreeD_Stat_TCM_t;    /* TCM 'Power-free in D' sate @min: 0 @max:3 @values: enum { IN_SAIL_ENABLE=1,IN_SAIL_DISABLE=0,IN_SAIL_ACTIVE=3,IN_SAIL_TRANSITION=2,}  */
  typedef uint8 FCTVehPTSignalState_t;    /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:64 @values: enum { KICK_DN_SW_PSD_ST=8,SSA_ENG_SP_ST=16,POWER_TRAIN_READY_ST=4,ACTUAL_GEAR_ST=1,TARGET_GEAR_ST=2,PWR_FREE_D_STAT_TCM_ST=64,ACCEL_PDL_POSN_RAW_ST=32,}  */
  typedef uint8 VehAccel_X_Dsabl_Rq_ESP_t;  /* Vehicle longitudinal acceleration disable request @min: 0 @max:2 @values: enum { ACCEL_X_ESP_TMP_DISABLE=1,ACCEL_X_ESP_IDLE=0,ACCEL_X_ESP_CONT_DISABLE=2,}  */
  typedef uint8 ESP_Oprtn_Stat_AS_t;  /* ESP operation state for assistance systems @min: 0 @max:9 @values: enum { ESP_STAT_ESP_ASR_CTRL_ACTV=6,ESP_STAT_FAULT=5,ESP_STAT_INIT=1,ESP_STAT_AMG_OFF=7,ESP_STAT_OFF_AMG_SPORT=8,ESP_STAT_ABS_CTRL_ACTV=9,ESP_STAT_TBCC=4,ESP_STAT_EMT=3,ESP_STAT_NORM=0,ESP_STAT_DIAG=2,}  */
  typedef uint8 FCTVehDPCMdASRq_t;  /* Driving program control: assistance system mode request @min: 1 @max:5 @values: enum { ECO=5,COMFORT=1,SPORT=3,SPORT_PLUS=4,COMFORT_PLUS=2,}  */
  typedef uint8 FCTVehESPSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:8 @values: enum { VEH_ACCEL_X_DISABL_ST=1,ESP_OPRTN_STAT_AS_ST=2,BRK_INTRVNTN_ACTV_ESP_ST=4,DPC_MD_AS_RQ_ST=8,}  */

  typedef struct FCTVehPowerTrain_t
  {
    FCTTransmissionGear_t ActualGear;
    FCTTransmissionGear_t TargetGear;
    EngRun_Stat_t EngRun_Stat;
    unsigned short ENG_RPM;
    boolean PowerTrainReady;
    boolean KickDnSw_Psd;
    boolean SSA_EngSp;
    unsigned char AccelPdlPosn_Raw;
    PwrFreeD_Stat_TCM_t PwrFreeD_Stat_TCM;
    FCTVehPTSignalState_t FCTVehPTSignalState;
  } FCTVehPowerTrain_t;  /* Powertrain information */

  typedef struct FCTVehESP_t
  {
    VehAccel_X_Dsabl_Rq_ESP_t VehAccel_X_Dsabl_Rq_ESP;
    ESP_Oprtn_Stat_AS_t ESP_Oprtn_Stat_AS;
    boolean bESPMode;
    boolean BrkIntrvntn_Actv_ESP;
    FCTVehDPCMdASRq_t DPC_Md_AS_Rq;
    FCTVehESPSignalState_t FCTVehESPSignalState;
  } FCTVehESP_t;  /* ESP information */

  typedef struct FCTVehCustomInput_t  /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCTVehPowerTrain_t FCTVehPowerTrain;
    FCTVehESP_t FCTVehESP;
    FCTVehCustomInputV2::FCTVehPassSafetySys_t FCTVehPassSafetySys;
    FCTVehCustomInputV2::ExtDASystem_t ExtDASystem;
  } FCTVehCustomInput_t;    /* Vehicle input signals for FCT 20 Cycle @vaddr:0x20219600 @vaddr_defs: FCT_MEAS_ID_FCT_VEH_CUSTOM_INPUT @cycleid:FCT_VEH_IN @vname:FCTVehCustomInput */
};  // End of namespace FCTVehCustomInputV6

/* New introduced Veh Custom Input for ARS430BW18 */
/* DevPath: AL_FCT_ARS430BW18_02.68.00 - RTE- Common: 1.140 */
namespace FCTVehCustomInputV7
{
  const unsigned char FCT_VEH_SenBlockage0 = 0u;
  const unsigned char FCTVehCustomVehCondition1 = 1u;

  typedef unsigned char FCTVehCustomBaseBlockage_t;                  /* Radar blockage @min: 0 @max:4 @values: enum { FCT_VEH_SenBlockage4=4,FCT_VEH_SenBlockage0=0,FCT_VEH_SenBlockage1=1,FCT_VEH_SenBlockage2=2,FCT_VEH_SenBlockage3=3,} */ /* [Satisfies_rte sws 1188] */
  typedef unsigned char FCTVehCustomVehCondition_t;                  /* BMW prvovides ASIL Vehicle Condition @min: 0 @max:3 @values: enum { FCTVehCustomVehCondition2=2,FCTVehCustomVehCondition3=3,FCTVehCustomVehCondition0=0,FCTVehCustomVehCondition1=1,} */ /* [Satisfies_rte sws 1188] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    FCTVehCustomBaseBlockage_t eRadarBlockage;
    FCTVehCustomBaseBlockage_t eCameraBlockage;
    FCTVehCustomVehCondition_t eVehicleCondition;
  } FCTVehBMWSysFct_t;                                               /* External driver assistance system information */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCTVehBMWSysFct_t FCTVehBMWSysFct;
  } FCTVehCustomInput_t;                                             /* Vehicle input signals for FCT 20 Cycle @vaddr:0x20219600 @vaddr_defs: FCT_MEAS_ID_FCT_VEH_CUSTOM_INPUT @cycleid:FCT_VEH_IN @vname:FCTVehCustomInput */

};  // End of namespace FCTVehCustomInputV7

namespace FCTVehCustomInputV7a
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCTVehCustomInputV6::FCTVehPowerTrain_t FCTVehPowerTrain;
    FCTVehCustomInputV2::FCTVehESP_t FCTVehESP;
  } FCTVehCustomInput_t;                                             /* Vehicle input signals for FCT 20 Cycle @vaddr:0x20219600 @vaddr_defs: FCT_MEAS_ID_FCT_VEH_CUSTOM_INPUT @cycleid:FCT_VEH_IN @vname:FCTVehCustomInput */
};  // End of namespace FCTVehCustomInputV7a

namespace FCTVehCustomInputV8
{
  typedef unsigned char FCTVehCustomBaseBlockage_t;                  /* Radar blockage @min: 0 @max:4 @values: enum { FCT_VEH_SenBlockage4=4,FCT_VEH_SenBlockage0=0,FCT_VEH_SenBlockage1=1,FCT_VEH_SenBlockage2=2,FCT_VEH_SenBlockage3=3,} */ /* [Satisfies_rte sws 1188] */
  typedef unsigned char FCTVehCustomVehCondition_t;                  /* BMW prvovides ASIL Vehicle Condition @min: 0 @max:3 @values: enum { FCTVehCustomVehCondition2=2,FCTVehCustomVehCondition3=3,FCTVehCustomVehCondition0=0,FCTVehCustomVehCondition1=1,} */ /* [Satisfies_rte sws 1188] */

typedef struct                                                       /* [Satisfies_rte sws 1191] */
  {
    FCTVehCustomBaseBlockage_t eRadarBlockage;
    FCTVehCustomBaseBlockage_t eCameraBlockage;
    FCTVehCustomVehCondition_t eVehicleCondition;
    boolean bDynamometer;
    boolean calibrationState;
    float fWarningPedVminEgo;
    float fWarningPedVmaxEgo;
    float fWarningBicVminEgo;
    float fWarningBicVmaxEgo;
    float fBrakePedVminEgo;
    float fBrakePedVmaxEgo;
    float fBrakeBicVminEgo;
    float fBrakeBicVmaxEgo;
    float fMaxBraking;
    float fSteeringAngleFroAxleEffMax;
    float fTireAngle;
    boolean bReactivity;
    boolean bLineOfSight;
    boolean bLongClosedEyes;
  } FCTVehBMWSysFct_t;                                               /* External driver assistance system information */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCTVehBMWSysFct_t FCTVehBMWSysFct;
  } FCTVehCustomInput_t;                                             /* Vehicle input signals for FCT 20 Cycle @vaddr:0x20219600 @vaddr_defs: FCT_MEAS_ID_FCT_VEH_CUSTOM_INPUT @cycleid:FCT_VEH_IN @vname:FCTVehCustomInput */
};  // End of namespace FCTVehCustomInputV8

namespace FCTVehCustomInputV10
{
  typedef unsigned char eLineOfSight_t;                              /* @min: 1 @max:16 @values: enum { No_inattention_area_left_detected=16,No_inattention_area_halfright_detected=2,No_inattention_area_halfleft_detected=8,No_inattention_area_front_detected=4,No_inattention_area_right_detected=1,} */ /* [Satisfies_rte sws 1188] */
  typedef unsigned char eLongClosedEyes_t;                           /* @min: 0 @max:255 @values: enum { Very_long_lid_closure_detected=2,Unknown_lid_closure=255,Long_lid_closure_detected=1,No_long_lid_closure_detected=0,} */ /* [Satisfies_rte sws 1188] */

typedef struct                                                       /* [Satisfies_rte sws 1191] */
  {
    FCTVehCustomInputV8::FCTVehCustomBaseBlockage_t eRadarBlockage;
    FCTVehCustomInputV8::FCTVehCustomBaseBlockage_t eCameraBlockage;
    FCTVehCustomInputV8::FCTVehCustomVehCondition_t eVehicleCondition;
    boolean bDynamometer;
    boolean calibrationState;
    float fWarningPedVminEgo;
    float fWarningPedVmaxEgo;
    float fWarningBicVminEgo;
    float fWarningBicVmaxEgo;
    float fBrakePedVminEgo;
    float fBrakePedVmaxEgo;
    float fBrakeBicVminEgo;
    float fBrakeBicVmaxEgo;
    float fMaxBraking;
    float fSteeringAngleFroAxleEffMax;
    float fTireAngle;
    float fReactivity;
    eLineOfSight_t eLineOfSight;
    eLongClosedEyes_t eLongClosedEyes;
    unsigned char BrightnessEnvironment;
    unsigned char StatusLowBeamReason;
  } FCTVehBMWSysFct_t;                                               /* External driver assistance system information */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long uiVersionNumber;
    SignalHeader_t sSigHeader;
    FCTVehBMWSysFct_t FCTVehBMWSysFct;
  } FCTVehCustomInput_t;                                             /* Vehicle input signals for FCT 20 Cycle @vaddr:0x20219600 @vaddr_defs: FCT_MEAS_ID_FCT_VEH_CUSTOM_INPUT @cycleid:FCT_VEH_IN @vname:FCTVehCustomInput */
};  // End of namespace FCTVehCustomInputV10


//
// Main ACC conversion class
//

class CConvFCTVehCustomInput : public CSimConverterBase
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

  FCTVehCustomInputV1::FCTVehCustomInput_t m_FCTVehCustomInputV1;
  FCTVehCustomInputV2::FCTVehCustomInput_t m_FCTVehCustomInputV2;
  FCTVehCustomInputV6::FCTVehCustomInput_t m_FCTVehCustomInputV6;
  FCTVehCustomInputV7::FCTVehCustomInput_t m_FCTVehCustomInputV7;
  FCTVehCustomInputV7a::FCTVehCustomInput_t m_FCTVehCustomInputV7a;
  FCTVehCustomInputV8::FCTVehCustomInput_t m_FCTVehCustomInputV8;
  FCTVehCustomInputV10::FCTVehCustomInput_t m_FCTVehCustomInputV10;

  // Initialization
  template <typename T> static void InitVersion (T & Dest, uint32 VersionNumber)
  {
    ::memset(&Dest, 0, sizeof(Dest));
    Dest.uiVersionNumber = VersionNumber;
  }

public:

  static const char* GetConverterTypeName()
  {
    return "FCTVehCustomInput_t";
  }

  CConvFCTVehCustomInput(void);
  virtual ~CConvFCTVehCustomInput(void) {};

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

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < FCT_VEH_CUSTOM_INPUT_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(VERSION_NUMBERS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };

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
  static CVersionInfoImpl FCT_VEH_CUSTOM_INPUT_V3_VERSION;
  static CVersionInfoImpl FCT_VEH_CUSTOM_INPUT_V4_VERSION;
  static CVersionInfoImpl FCT_VEH_CUSTOM_INPUT_V5_VERSION;
  static CVersionInfoImpl FCT_VEH_CUSTOM_INPUT_V6_VERSION;
  static CVersionInfoImpl FCT_VEH_CUSTOM_INPUT_V7_VERSION;
  static CVersionInfoImpl FCT_VEH_CUSTOM_INPUT_V7a_VERSION;
  static CVersionInfoImpl FCT_VEH_CUSTOM_INPUT_V8_VERSION;
  static CVersionInfoImpl FCT_VEH_CUSTOM_INPUT_V9_VERSION;
  static CVersionInfoImpl FCT_VEH_CUSTOM_INPUT_V10_VERSION;

  enum eRoadVersions
  {
    FCT_VEH_CUSTOM_DUMMY_INPUT,
    FCT_VEH_CUSTOM_INPUT_V3,
    FCT_VEH_CUSTOM_INPUT_V4,
    FCT_VEH_CUSTOM_INPUT_V5,
    FCT_VEH_CUSTOM_INPUT_V6,
    FCT_VEH_CUSTOM_INPUT_V7,
    FCT_VEH_CUSTOM_INPUT_V7a,
    FCT_VEH_CUSTOM_INPUT_V8,
    FCT_VEH_CUSTOM_INPUT_V9,
    FCT_VEH_CUSTOM_INPUT_V10,
    FCT_VEH_CUSTOM_INPUT_VERSION_COUNT
  };
  static unsigned long SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_VERSION_COUNT];
  static const CVersionInfoImpl * const VERSION_NUMBERS[FCT_VEH_CUSTOM_INPUT_VERSION_COUNT];
};

CVersionInfoImpl  CConvFCTVehCustomInput::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_V3_VERSION(0, 0, 3);
CVersionInfoImpl  CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_V4_VERSION(0, 0, 4);
CVersionInfoImpl  CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_V5_VERSION(0, 0, 5);
CVersionInfoImpl  CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_V6_VERSION(0, 0, 6);
CVersionInfoImpl  CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_V7_VERSION(0, 0, 7);
CVersionInfoImpl  CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_V7a_VERSION(0, 0, 7);
CVersionInfoImpl  CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_V8_VERSION(0, 0, 8);
CVersionInfoImpl  CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_V9_VERSION(0, 0, 9);
CVersionInfoImpl  CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_V10_VERSION(0, 0, 10);

static uint32 DummyVersion = 0xFFFFFFFFu;

unsigned long CConvFCTVehCustomInput::SUPPORTED_SIZE[CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_VERSION_COUNT]=
{
  sizeof(DummyVersion),     //!< Special dummy for 4 byte version number only (i.e.: no ACC interface of FCT component)
  sizeof(FCTVehCustomInputV1::FCTVehCustomInput_t),
  sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t),
  sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t),
  sizeof(FCTVehCustomInputV6::FCTVehCustomInput_t),
  sizeof(FCTVehCustomInputV7::FCTVehCustomInput_t),
  sizeof(FCTVehCustomInputV7a::FCTVehCustomInput_t),
  sizeof(FCTVehCustomInputV8::FCTVehCustomInput_t),
  sizeof(FCTVehCustomInputV10::FCTVehCustomInput_t),
  sizeof(FCTVehCustomInputV10::FCTVehCustomInput_t)
};

const CVersionInfoImpl * const CConvFCTVehCustomInput::VERSION_NUMBERS[CConvFCTVehCustomInput::FCT_VEH_CUSTOM_INPUT_VERSION_COUNT] =
{
  &BASE_VERSION,
  &FCT_VEH_CUSTOM_INPUT_V3_VERSION,
  &FCT_VEH_CUSTOM_INPUT_V4_VERSION,
  &FCT_VEH_CUSTOM_INPUT_V5_VERSION,
  &FCT_VEH_CUSTOM_INPUT_V6_VERSION,
  &FCT_VEH_CUSTOM_INPUT_V7_VERSION,
  &FCT_VEH_CUSTOM_INPUT_V7a_VERSION,
  &FCT_VEH_CUSTOM_INPUT_V8_VERSION,
  &FCT_VEH_CUSTOM_INPUT_V9_VERSION,
  &FCT_VEH_CUSTOM_INPUT_V10_VERSION
};

CConvFCTVehCustomInput::CConvFCTVehCustomInput(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_FCTVehCustomInputV1(), m_FCTVehCustomInputV2(), m_FCTVehCustomInputV6(), m_FCTVehCustomInputV7(), m_FCTVehCustomInputV7a()
{
  InitVersion(m_FCTVehCustomInputV1, 3u);
  InitVersion(m_FCTVehCustomInputV2, 4u);
  InitVersion(m_FCTVehCustomInputV6, 6u);
  InitVersion(m_FCTVehCustomInputV7, 7u);
  InitVersion(m_FCTVehCustomInputV7a, 7u);
  InitVersion(m_FCTVehCustomInputV8, 8u);
  InitVersion(m_FCTVehCustomInputV10, 10u);
}

long CConvFCTVehCustomInput::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  // See if conversion is needed
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))))
  {
    // Ports match 1-1 no conversion needed
    *pOutData = pPPortData;
    ulOutSize = ulPPortSize;
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  else if (ulPPortSize >= 4)
  {
    const uint32 version = *reinterpret_cast<const uint32*>(pPPortData);
    // Conversion needed: on first level see what destination we have to convert to
    if ((ulRPortSize == SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V10]) && ((requestPortVersionInfo.Equals(VERSION_NUMBERS[FCT_VEH_CUSTOM_INPUT_V10])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      FCTVehCustomInputV10::FCTVehCustomInput_t & Dest = m_FCTVehCustomInputV10;
      switch (version)
      {
      case 0:
        break;
      case 1:
      case 2:
      case 3:
        break;
      case 4:
      case 5:
        break;
      case 6:
      case 7:
        if (SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V7] == ulPPortSize)
        {
          const FCTVehCustomInputV7::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV7::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                             = 10;
          Dest.sSigHeader                                  = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus                     = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehBMWSysFct.eRadarBlockage              = Src.FCTVehBMWSysFct.eRadarBlockage;
          Dest.FCTVehBMWSysFct.eCameraBlockage             = Src.FCTVehBMWSysFct.eCameraBlockage;
          Dest.FCTVehBMWSysFct.eVehicleCondition           = Src.FCTVehBMWSysFct.eVehicleCondition;
          Dest.FCTVehBMWSysFct.bDynamometer                = FALSE;
          Dest.FCTVehBMWSysFct.calibrationState            = FALSE;
          Dest.FCTVehBMWSysFct.fWarningPedVminEgo          = 5.f;
          Dest.FCTVehBMWSysFct.fWarningPedVmaxEgo          = 85.f;
          Dest.FCTVehBMWSysFct.fWarningBicVminEgo          = 5.f;
          Dest.FCTVehBMWSysFct.fWarningBicVmaxEgo          = 85.f;
          Dest.FCTVehBMWSysFct.fBrakePedVminEgo            = 5.f;
          Dest.FCTVehBMWSysFct.fBrakePedVmaxEgo            = 65.f;
          Dest.FCTVehBMWSysFct.fBrakeBicVminEgo            = 5.f;
          Dest.FCTVehBMWSysFct.fBrakeBicVmaxEgo            = 65.f;
          Dest.FCTVehBMWSysFct.fMaxBraking                 = 0.f;
          Dest.FCTVehBMWSysFct.fSteeringAngleFroAxleEffMax = 0.f;
          Dest.FCTVehBMWSysFct.fTireAngle                  = 0.f;
          Dest.FCTVehBMWSysFct.fReactivity                 = 0.f;
          Dest.FCTVehBMWSysFct.eLineOfSight                = 0u;
          Dest.FCTVehBMWSysFct.eLongClosedEyes             = 0u;
          Dest.FCTVehBMWSysFct.BrightnessEnvironment       = 0u;
          Dest.FCTVehBMWSysFct.StatusLowBeamReason         = 0u;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 8:
        if (SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V8] == ulPPortSize)
        {
          const FCTVehCustomInputV8::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV8::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                             = 10;
          Dest.sSigHeader                                  = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus                     = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehBMWSysFct.eRadarBlockage              = Src.FCTVehBMWSysFct.eRadarBlockage;
          Dest.FCTVehBMWSysFct.eCameraBlockage             = Src.FCTVehBMWSysFct.eCameraBlockage;
          Dest.FCTVehBMWSysFct.eVehicleCondition           = Src.FCTVehBMWSysFct.eVehicleCondition;
          Dest.FCTVehBMWSysFct.bDynamometer                = Src.FCTVehBMWSysFct.bDynamometer;
          Dest.FCTVehBMWSysFct.calibrationState            = Src.FCTVehBMWSysFct.calibrationState;
          Dest.FCTVehBMWSysFct.fWarningPedVminEgo          = Src.FCTVehBMWSysFct.fWarningPedVminEgo;
          Dest.FCTVehBMWSysFct.fWarningPedVmaxEgo          = Src.FCTVehBMWSysFct.fWarningPedVmaxEgo;
          Dest.FCTVehBMWSysFct.fWarningBicVminEgo          = Src.FCTVehBMWSysFct.fWarningBicVminEgo;
          Dest.FCTVehBMWSysFct.fWarningBicVmaxEgo          = Src.FCTVehBMWSysFct.fWarningBicVmaxEgo;
          Dest.FCTVehBMWSysFct.fBrakePedVminEgo            = Src.FCTVehBMWSysFct.fBrakePedVminEgo;
          Dest.FCTVehBMWSysFct.fBrakePedVmaxEgo            = Src.FCTVehBMWSysFct.fBrakePedVmaxEgo;
          Dest.FCTVehBMWSysFct.fBrakeBicVminEgo            = Src.FCTVehBMWSysFct.fBrakeBicVminEgo;
          Dest.FCTVehBMWSysFct.fBrakeBicVmaxEgo            = Src.FCTVehBMWSysFct.fBrakeBicVmaxEgo;
          Dest.FCTVehBMWSysFct.fMaxBraking                 = Src.FCTVehBMWSysFct.fMaxBraking;
          Dest.FCTVehBMWSysFct.fSteeringAngleFroAxleEffMax = Src.FCTVehBMWSysFct.fSteeringAngleFroAxleEffMax;
          Dest.FCTVehBMWSysFct.fTireAngle                  = Src.FCTVehBMWSysFct.fTireAngle;
          Dest.FCTVehBMWSysFct.fReactivity                 = Src.FCTVehBMWSysFct.bReactivity;
          Dest.FCTVehBMWSysFct.eLineOfSight                = Src.FCTVehBMWSysFct.bLineOfSight;
          Dest.FCTVehBMWSysFct.eLongClosedEyes             = Src.FCTVehBMWSysFct.bLongClosedEyes;
          Dest.FCTVehBMWSysFct.BrightnessEnvironment       = 0u;
          Dest.FCTVehBMWSysFct.StatusLowBeamReason         = 0u;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 9:
      case 10:
        if (SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V10] == ulPPortSize)
        {
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      default:
        break;
      }
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V8]) && ((requestPortVersionInfo.Equals(VERSION_NUMBERS[FCT_VEH_CUSTOM_INPUT_V8])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      FCTVehCustomInputV8::FCTVehCustomInput_t & Dest = m_FCTVehCustomInputV8;
      switch (version)
      {
      case 0:                          /* E.g.: \\lifs010.cw01.contiwan.com\prj\ARS430BW18\2016-11-14_SW_40.05.110_Somke-test\G11_V712756_S18A_C1H_MM\20161114_1336_{71101327-402A-45B2-BC62-C0DFBC8CA77C}.rrec */
        if (SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V10] == ulPPortSize)
        {
          const FCTVehCustomInputV10::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV10::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                             = 8;
          Dest.sSigHeader                                  = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus                     = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehBMWSysFct.eRadarBlockage              = Src.FCTVehBMWSysFct.eRadarBlockage;
          Dest.FCTVehBMWSysFct.eCameraBlockage             = Src.FCTVehBMWSysFct.eCameraBlockage;
          Dest.FCTVehBMWSysFct.eVehicleCondition           = Src.FCTVehBMWSysFct.eVehicleCondition;
          Dest.FCTVehBMWSysFct.bDynamometer                = Src.FCTVehBMWSysFct.bDynamometer;
          Dest.FCTVehBMWSysFct.calibrationState            = Src.FCTVehBMWSysFct.calibrationState;
          Dest.FCTVehBMWSysFct.fWarningPedVminEgo          = Src.FCTVehBMWSysFct.fWarningPedVminEgo;
          Dest.FCTVehBMWSysFct.fWarningPedVmaxEgo          = Src.FCTVehBMWSysFct.fWarningPedVmaxEgo;
          Dest.FCTVehBMWSysFct.fWarningBicVminEgo          = Src.FCTVehBMWSysFct.fWarningBicVminEgo;
          Dest.FCTVehBMWSysFct.fWarningBicVmaxEgo          = Src.FCTVehBMWSysFct.fWarningBicVmaxEgo;
          Dest.FCTVehBMWSysFct.fBrakePedVminEgo            = Src.FCTVehBMWSysFct.fBrakePedVminEgo;
          Dest.FCTVehBMWSysFct.fBrakePedVmaxEgo            = Src.FCTVehBMWSysFct.fBrakePedVmaxEgo;
          Dest.FCTVehBMWSysFct.fBrakeBicVminEgo            = Src.FCTVehBMWSysFct.fBrakeBicVminEgo;
          Dest.FCTVehBMWSysFct.fBrakeBicVmaxEgo            = Src.FCTVehBMWSysFct.fBrakeBicVmaxEgo;
          Dest.FCTVehBMWSysFct.fMaxBraking                 = Src.FCTVehBMWSysFct.fMaxBraking;
          Dest.FCTVehBMWSysFct.fSteeringAngleFroAxleEffMax = Src.FCTVehBMWSysFct.fSteeringAngleFroAxleEffMax;
          Dest.FCTVehBMWSysFct.fTireAngle                  = Src.FCTVehBMWSysFct.fTireAngle;
          Dest.FCTVehBMWSysFct.bReactivity                 = (Src.FCTVehBMWSysFct.fReactivity > 0.f) ? TRUE : FALSE;
          Dest.FCTVehBMWSysFct.bLineOfSight                = (Src.FCTVehBMWSysFct.eLineOfSight) ? TRUE : FALSE;
          Dest.FCTVehBMWSysFct.bLongClosedEyes             = (Src.FCTVehBMWSysFct.eLongClosedEyes) ? TRUE : FALSE;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 1:
      case 2:
      case 3:
        break;
      case 4:
      case 5:
        break;
      case 6:
      case 7:
        if (SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V7] == ulPPortSize)
        {
          const FCTVehCustomInputV7::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV7::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                             = 7;
          Dest.sSigHeader                                  = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus                     = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehBMWSysFct.eRadarBlockage              = Src.FCTVehBMWSysFct.eRadarBlockage;
          Dest.FCTVehBMWSysFct.eCameraBlockage             = Src.FCTVehBMWSysFct.eCameraBlockage;
          Dest.FCTVehBMWSysFct.eVehicleCondition           = Src.FCTVehBMWSysFct.eVehicleCondition;
          Dest.FCTVehBMWSysFct.bDynamometer                = FALSE;
          Dest.FCTVehBMWSysFct.calibrationState            = FALSE;
          Dest.FCTVehBMWSysFct.fWarningPedVminEgo          = 5.f;
          Dest.FCTVehBMWSysFct.fWarningPedVmaxEgo          = 85.f;
          Dest.FCTVehBMWSysFct.fWarningBicVminEgo          = 5.f;
          Dest.FCTVehBMWSysFct.fWarningBicVmaxEgo          = 85.f;
          Dest.FCTVehBMWSysFct.fBrakePedVminEgo            = 5.f;
          Dest.FCTVehBMWSysFct.fBrakePedVmaxEgo            = 65.f;
          Dest.FCTVehBMWSysFct.fBrakeBicVminEgo            = 5.f;
          Dest.FCTVehBMWSysFct.fBrakeBicVmaxEgo            = 65.f;
          Dest.FCTVehBMWSysFct.fMaxBraking                 = 0.f;
          Dest.FCTVehBMWSysFct.fSteeringAngleFroAxleEffMax = 0.f;
          Dest.FCTVehBMWSysFct.fTireAngle                  = 0.f;
          Dest.FCTVehBMWSysFct.bReactivity                 = FALSE;
          Dest.FCTVehBMWSysFct.bLineOfSight                = FALSE;
          Dest.FCTVehBMWSysFct.bLongClosedEyes             = FALSE;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 8:
        if (SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V8] == ulPPortSize)
        {
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      case 9:
      case 10:
        if (SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V10] == ulPPortSize)
        {
          const FCTVehCustomInputV10::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV10::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                             = 8;
          Dest.sSigHeader                                  = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus                     = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehBMWSysFct.eRadarBlockage              = Src.FCTVehBMWSysFct.eRadarBlockage;
          Dest.FCTVehBMWSysFct.eCameraBlockage             = Src.FCTVehBMWSysFct.eCameraBlockage;
          Dest.FCTVehBMWSysFct.eVehicleCondition           = Src.FCTVehBMWSysFct.eVehicleCondition;
          Dest.FCTVehBMWSysFct.bDynamometer                = Src.FCTVehBMWSysFct.bDynamometer;
          Dest.FCTVehBMWSysFct.calibrationState            = Src.FCTVehBMWSysFct.calibrationState;
          Dest.FCTVehBMWSysFct.fWarningPedVminEgo          = Src.FCTVehBMWSysFct.fWarningPedVminEgo;
          Dest.FCTVehBMWSysFct.fWarningPedVmaxEgo          = Src.FCTVehBMWSysFct.fWarningPedVmaxEgo;
          Dest.FCTVehBMWSysFct.fWarningBicVminEgo          = Src.FCTVehBMWSysFct.fWarningBicVminEgo;
          Dest.FCTVehBMWSysFct.fWarningBicVmaxEgo          = Src.FCTVehBMWSysFct.fWarningBicVmaxEgo;
          Dest.FCTVehBMWSysFct.fBrakePedVminEgo            = Src.FCTVehBMWSysFct.fBrakePedVminEgo;
          Dest.FCTVehBMWSysFct.fBrakePedVmaxEgo            = Src.FCTVehBMWSysFct.fBrakePedVmaxEgo;
          Dest.FCTVehBMWSysFct.fBrakeBicVminEgo            = Src.FCTVehBMWSysFct.fBrakeBicVminEgo;
          Dest.FCTVehBMWSysFct.fBrakeBicVmaxEgo            = Src.FCTVehBMWSysFct.fBrakeBicVmaxEgo;
          Dest.FCTVehBMWSysFct.fMaxBraking                 = Src.FCTVehBMWSysFct.fMaxBraking;
          Dest.FCTVehBMWSysFct.fSteeringAngleFroAxleEffMax = Src.FCTVehBMWSysFct.fSteeringAngleFroAxleEffMax;
          Dest.FCTVehBMWSysFct.fTireAngle                  = Src.FCTVehBMWSysFct.fTireAngle;
          Dest.FCTVehBMWSysFct.bReactivity                 = (Src.FCTVehBMWSysFct.fReactivity > 0.f) ? TRUE : FALSE;
          Dest.FCTVehBMWSysFct.bLineOfSight                = (Src.FCTVehBMWSysFct.eLineOfSight) ? TRUE : FALSE;
          Dest.FCTVehBMWSysFct.bLongClosedEyes             = (Src.FCTVehBMWSysFct.eLongClosedEyes) ? TRUE : FALSE;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      default:
        break;
      }
    }
    else if ((ulRPortSize == sizeof(FCTVehCustomInputV7a::FCTVehCustomInput_t)) && ((requestPortVersionInfo.Equals(&FCT_VEH_CUSTOM_INPUT_V7a_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      FCTVehCustomInputV7a::FCTVehCustomInput_t & Dest = m_FCTVehCustomInputV7a;
      switch (version)
      {
      case 0:
      case 1:
      case 2:
      case 3:
        if (sizeof(FCTVehCustomInputV1::FCTVehCustomInput_t) == ulPPortSize)
        {
          const FCTVehCustomInputV1::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV1::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                         = 7;
          Dest.sSigHeader                              = Src.sSigHeader;
          Dest.sSigHeader.eSigStatus                   = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehPowerTrain.AccelPdlPosn_Raw       = Src.FCTVehPowerTrain.AccelPdlPosn_Raw;
          Dest.FCTVehPowerTrain.ActualGear             = Src.FCTVehPowerTrain.ActualGear;
          Dest.FCTVehPowerTrain.EngRun_Stat            = Src.FCTVehPowerTrain.EngRun_Stat;
          Dest.FCTVehPowerTrain.ENG_RPM                = 2000;
          Dest.FCTVehPowerTrain.FCTVehPTSignalState    = 0u;
          Dest.FCTVehPowerTrain.KickDnSw_Psd           = Src.FCTVehPowerTrain.KickDnSw_Psd;
          Dest.FCTVehPowerTrain.PowerTrainReady        = Src.FCTVehPowerTrain.PowerTrainReady;
          Dest.FCTVehPowerTrain.PwrFreeD_Stat_TCM      = Src.FCTVehPowerTrain.PwrFreeD_Stat_TCM;
          Dest.FCTVehPowerTrain.SSA_EngSp              = Src.FCTVehPowerTrain.SSA_EngSp;
          Dest.FCTVehPowerTrain.TargetGear             = Src.FCTVehPowerTrain.TargetGear;
          Dest.FCTVehESP.BrkIntrvntn_Actv_ESP          = Src.FCTVehESP.BrkIntrvntn_Actv_ESP;
          Dest.FCTVehESP.DPC_Md_AS_Rq                  = Src.FCTVehESP.DPC_Md_AS_Rq;
          Dest.FCTVehESP.ESP_Oprtn_Stat_AS             = Src.FCTVehESP.ESP_Oprtn_Stat_AS;
          Dest.FCTVehESP.FCTVehESPSignalState          = 0u;
          Dest.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP       = Src.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 4:
      case 5:
        if (sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t) == ulPPortSize)
        {
          const FCTVehCustomInputV2::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV2::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                      = 7;
          Dest.sSigHeader                           = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus              = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehPowerTrain.AccelPdlPosn_Raw    = Src.FCTVehPowerTrain.AccelPdlPosn_Raw;
          Dest.FCTVehPowerTrain.ActualGear          = Src.FCTVehPowerTrain.ActualGear;
          Dest.FCTVehPowerTrain.EngRun_Stat         = Src.FCTVehPowerTrain.EngRun_Stat;
          Dest.FCTVehPowerTrain.ENG_RPM             = 2000;
          Dest.FCTVehPowerTrain.FCTVehPTSignalState = Src.FCTVehPowerTrain.FCTVehPTSignalState;
          Dest.FCTVehPowerTrain.KickDnSw_Psd        = Src.FCTVehPowerTrain.KickDnSw_Psd;
          Dest.FCTVehPowerTrain.PowerTrainReady     = Src.FCTVehPowerTrain.PowerTrainReady;
          Dest.FCTVehPowerTrain.PwrFreeD_Stat_TCM   = Src.FCTVehPowerTrain.PwrFreeD_Stat_TCM;
          Dest.FCTVehPowerTrain.SSA_EngSp           = Src.FCTVehPowerTrain.SSA_EngSp;
          Dest.FCTVehPowerTrain.TargetGear          = Src.FCTVehPowerTrain.TargetGear;
          Dest.FCTVehESP.FCTVehESPSignalState       = 0u;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 6:
        if (sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t) == ulPPortSize)
        {
          const FCTVehCustomInputV2::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV2::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                         = 7;
          Dest.sSigHeader                           = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus              = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehPowerTrain.ENG_RPM             = 2000;
          Dest.FCTVehPowerTrain.FCTVehPTSignalState = 0u;
          Dest.FCTVehESP.BrkIntrvntn_Actv_ESP       = Src.FCTVehESP.BrkIntrvntn_Actv_ESP;
          Dest.FCTVehESP.DPC_Md_AS_Rq               = Src.FCTVehESP.DPC_Md_AS_Rq;
          Dest.FCTVehESP.ESP_Oprtn_Stat_AS          = Src.FCTVehESP.ESP_Oprtn_Stat_AS;
          Dest.FCTVehESP.FCTVehESPSignalState       = Src.FCTVehESP.FCTVehESPSignalState;
          Dest.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP    = Src.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 7:
      default:
        break;
      }
    }
    else if ((ulRPortSize == sizeof(FCTVehCustomInputV7::FCTVehCustomInput_t)) && ((requestPortVersionInfo.Equals(&FCT_VEH_CUSTOM_INPUT_V7_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      switch (version)
      {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        break;
      case 7:
        if (sizeof(FCTVehCustomInputV6::FCTVehCustomInput_t) == ulPPortSize)
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      case 8:
        if (SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V8] == ulPPortSize)
        {
          FCTVehCustomInputV7::FCTVehCustomInput_t & Dest = m_FCTVehCustomInputV7;
          const FCTVehCustomInputV8::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV8::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                             = 7;
          Dest.sSigHeader                                  = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus                     = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehBMWSysFct.eRadarBlockage              = Src.FCTVehBMWSysFct.eRadarBlockage;
          Dest.FCTVehBMWSysFct.eCameraBlockage             = Src.FCTVehBMWSysFct.eCameraBlockage;
          Dest.FCTVehBMWSysFct.eVehicleCondition           = Src.FCTVehBMWSysFct.eVehicleCondition;
          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 9:
      case 10:
        if (SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V10] == ulPPortSize)
        {
          FCTVehCustomInputV7::FCTVehCustomInput_t & Dest = m_FCTVehCustomInputV7;
          const FCTVehCustomInputV10::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV10::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                             = 7;
          Dest.sSigHeader                                  = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus                     = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehBMWSysFct.eRadarBlockage              = Src.FCTVehBMWSysFct.eRadarBlockage;
          Dest.FCTVehBMWSysFct.eCameraBlockage             = Src.FCTVehBMWSysFct.eCameraBlockage;
          Dest.FCTVehBMWSysFct.eVehicleCondition           = Src.FCTVehBMWSysFct.eVehicleCondition;
          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      default:
        break;
      }
    }
    else if ((ulRPortSize == sizeof(FCTVehCustomInputV6::FCTVehCustomInput_t)) && ((requestPortVersionInfo.Equals(&FCT_VEH_CUSTOM_INPUT_V6_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      FCTVehCustomInputV6::FCTVehCustomInput_t & Dest = m_FCTVehCustomInputV6;
      switch (version)
      {
      case 0:
      case 1:
      case 2:
      case 3:
        if (sizeof(FCTVehCustomInputV1::FCTVehCustomInput_t) == ulPPortSize)
        {
          const FCTVehCustomInputV1::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV1::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                         = 6;
          Dest.sSigHeader                              = Src.sSigHeader;
          Dest.sSigHeader.eSigStatus                   = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehPowerTrain.AccelPdlPosn_Raw       = Src.FCTVehPowerTrain.AccelPdlPosn_Raw;
          Dest.FCTVehPowerTrain.ActualGear             = Src.FCTVehPowerTrain.ActualGear;
          Dest.FCTVehPowerTrain.EngRun_Stat            = Src.FCTVehPowerTrain.EngRun_Stat;
          Dest.FCTVehPowerTrain.ENG_RPM                = 2000;
          Dest.FCTVehPowerTrain.FCTVehPTSignalState    = 0u;
          Dest.FCTVehPowerTrain.KickDnSw_Psd           = Src.FCTVehPowerTrain.KickDnSw_Psd;
          Dest.FCTVehPowerTrain.PowerTrainReady        = Src.FCTVehPowerTrain.PowerTrainReady;
          Dest.FCTVehPowerTrain.PwrFreeD_Stat_TCM      = Src.FCTVehPowerTrain.PwrFreeD_Stat_TCM;
          Dest.FCTVehPowerTrain.SSA_EngSp              = Src.FCTVehPowerTrain.SSA_EngSp;
          Dest.FCTVehPowerTrain.TargetGear             = Src.FCTVehPowerTrain.TargetGear;
          Dest.FCTVehESP.BrkIntrvntn_Actv_ESP          = Src.FCTVehESP.BrkIntrvntn_Actv_ESP;
          Dest.FCTVehESP.DPC_Md_AS_Rq                  = Src.FCTVehESP.DPC_Md_AS_Rq;
          Dest.FCTVehESP.bESPMode                      = 1;
          Dest.FCTVehESP.ESP_Oprtn_Stat_AS             = Src.FCTVehESP.ESP_Oprtn_Stat_AS;
          Dest.FCTVehESP.FCTVehESPSignalState          = 0u;
          Dest.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP       = Src.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP;
          Dest.ExtDASystem.BrkIntrvntn_Actv_CWA        = Src.ExtDASystem.BrkIntrvntn_Actv_CWA;
          Dest.ExtDASystem.BrkIntrvntn_Actv_LDP        = Src.ExtDASystem.BrkIntrvntn_Actv_LDP;
          Dest.ExtDASystem.DSR_Actv                    = Src.ExtDASystem.DSR_Actv;
          Dest.ExtDASystem.ExtDASystemSignalState      = 0u;
          Dest.ExtDASystem.VehAccel_X_AS_Actv_Rs       = Src.ExtDASystem.VehAccel_X_AS_Actv_Rs;
          Dest.FCTVehPassSafetySys.Bckl_Sw_D_Stat      = Src.FCTVehPassSafetySys.Bckl_Sw_D_Stat;
          Dest.FCTVehPassSafetySys.FCTVehPSSignalState = 0u;
          Dest.FCTVehPassSafetySys.Impact_X            = Src.FCTVehPassSafetySys.Impact_X;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 4:
      case 5:
        if (sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t) == ulPPortSize)
        {
          const FCTVehCustomInputV2::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV2::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                      = 6;
          Dest.sSigHeader                           = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus              = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehPowerTrain.AccelPdlPosn_Raw    = Src.FCTVehPowerTrain.AccelPdlPosn_Raw;
          Dest.FCTVehPowerTrain.ActualGear          = Src.FCTVehPowerTrain.ActualGear;
          Dest.FCTVehPowerTrain.EngRun_Stat         = Src.FCTVehPowerTrain.EngRun_Stat;
          Dest.FCTVehPowerTrain.ENG_RPM             = 2000;
          Dest.FCTVehPowerTrain.FCTVehPTSignalState = Src.FCTVehPowerTrain.FCTVehPTSignalState;
          Dest.FCTVehPowerTrain.KickDnSw_Psd        = Src.FCTVehPowerTrain.KickDnSw_Psd;
          Dest.FCTVehPowerTrain.PowerTrainReady     = Src.FCTVehPowerTrain.PowerTrainReady;
          Dest.FCTVehPowerTrain.PwrFreeD_Stat_TCM   = Src.FCTVehPowerTrain.PwrFreeD_Stat_TCM;
          Dest.FCTVehPowerTrain.SSA_EngSp           = Src.FCTVehPowerTrain.SSA_EngSp;
          Dest.FCTVehPowerTrain.TargetGear          = Src.FCTVehPowerTrain.TargetGear;
          Dest.FCTVehESP.BrkIntrvntn_Actv_ESP       = Src.FCTVehESP.BrkIntrvntn_Actv_ESP;
          Dest.FCTVehESP.DPC_Md_AS_Rq               = Src.FCTVehESP.DPC_Md_AS_Rq;
          Dest.FCTVehESP.bESPMode                   = 1;
          Dest.FCTVehESP.ESP_Oprtn_Stat_AS          = Src.FCTVehESP.ESP_Oprtn_Stat_AS;
          Dest.FCTVehESP.FCTVehESPSignalState       = Src.FCTVehESP.FCTVehESPSignalState;
          Dest.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP    = Src.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP;
          Dest.ExtDASystem                          = Src.ExtDASystem;
          Dest.FCTVehPassSafetySys                  = Src.FCTVehPassSafetySys;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 6:
        if (sizeof(FCTVehCustomInputV6::FCTVehCustomInput_t) == ulPPortSize)
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      default:
        break;
      }
    }
    else if ((ulRPortSize == sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t)) && ((requestPortVersionInfo.Equals(&FCT_VEH_CUSTOM_INPUT_V4_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      FCTVehCustomInputV2::FCTVehCustomInput_t & Dest = m_FCTVehCustomInputV2;
      switch (version)
      {
      case 0:
      case 1:
      case 2:
      case 3:
        if (sizeof(FCTVehCustomInputV1::FCTVehCustomInput_t) == ulPPortSize)
        {
          const FCTVehCustomInputV1::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV1::FCTVehCustomInput_t*>(pPPortData);
          FCTVehCustomInputV2::FCTVehCustomInput_t & Dest = m_FCTVehCustomInputV2;
          Dest.uiVersionNumber                         = 4;
          Dest.sSigHeader                              = Src.sSigHeader;
          Dest.sSigHeader.eSigStatus                   = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehPowerTrain.AccelPdlPosn_Raw       = Src.FCTVehPowerTrain.AccelPdlPosn_Raw;
          Dest.FCTVehPowerTrain.ActualGear             = Src.FCTVehPowerTrain.ActualGear;
          Dest.FCTVehPowerTrain.EngRun_Stat            = Src.FCTVehPowerTrain.EngRun_Stat;
          Dest.FCTVehPowerTrain.FCTVehPTSignalState    = 0u;
          Dest.FCTVehPowerTrain.KickDnSw_Psd           = Src.FCTVehPowerTrain.KickDnSw_Psd;
          Dest.FCTVehPowerTrain.PowerTrainReady        = Src.FCTVehPowerTrain.PowerTrainReady;
          Dest.FCTVehPowerTrain.PwrFreeD_Stat_TCM      = Src.FCTVehPowerTrain.PwrFreeD_Stat_TCM;
          Dest.FCTVehPowerTrain.SSA_EngSp              = Src.FCTVehPowerTrain.SSA_EngSp;
          Dest.FCTVehPowerTrain.TargetGear             = Src.FCTVehPowerTrain.TargetGear;
          Dest.FCTVehESP.BrkIntrvntn_Actv_ESP          = Src.FCTVehESP.BrkIntrvntn_Actv_ESP;
          Dest.FCTVehESP.DPC_Md_AS_Rq                  = Src.FCTVehESP.DPC_Md_AS_Rq;
          Dest.FCTVehESP.ESP_Oprtn_Stat_AS             = Src.FCTVehESP.ESP_Oprtn_Stat_AS;
          Dest.FCTVehESP.FCTVehESPSignalState          = 0u;
          Dest.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP       = Src.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP;
          Dest.ExtDASystem.BrkIntrvntn_Actv_CWA        = Src.ExtDASystem.BrkIntrvntn_Actv_CWA;
          Dest.ExtDASystem.BrkIntrvntn_Actv_LDP        = Src.ExtDASystem.BrkIntrvntn_Actv_LDP;
          Dest.ExtDASystem.DSR_Actv                    = Src.ExtDASystem.DSR_Actv;
          Dest.ExtDASystem.ExtDASystemSignalState      = 0u;
          Dest.ExtDASystem.VehAccel_X_AS_Actv_Rs       = Src.ExtDASystem.VehAccel_X_AS_Actv_Rs;
          Dest.FCTVehPassSafetySys.Bckl_Sw_D_Stat      = Src.FCTVehPassSafetySys.Bckl_Sw_D_Stat;
          Dest.FCTVehPassSafetySys.FCTVehPSSignalState = 0u;
          Dest.FCTVehPassSafetySys.Impact_X            = Src.FCTVehPassSafetySys.Impact_X;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 4:
      case 5:
        if (sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t) == ulPPortSize)
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      case 6:
        if (sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t) == ulPPortSize)
        {
          const FCTVehCustomInputV2::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV2::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                         = 4;
          Dest.sSigHeader                           = Src.sSigHeader;
          //Dest.sSigHeader.eSigStatus              = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehPowerTrain.AccelPdlPosn_Raw    = Src.FCTVehPowerTrain.AccelPdlPosn_Raw;
          Dest.FCTVehPowerTrain.ActualGear          = Src.FCTVehPowerTrain.ActualGear;
          Dest.FCTVehPowerTrain.EngRun_Stat         = Src.FCTVehPowerTrain.EngRun_Stat;
          Dest.FCTVehPowerTrain.FCTVehPTSignalState = Src.FCTVehPowerTrain.FCTVehPTSignalState;
          Dest.FCTVehPowerTrain.KickDnSw_Psd        = Src.FCTVehPowerTrain.KickDnSw_Psd;
          Dest.FCTVehPowerTrain.PowerTrainReady     = Src.FCTVehPowerTrain.PowerTrainReady;
          Dest.FCTVehPowerTrain.PwrFreeD_Stat_TCM   = Src.FCTVehPowerTrain.PwrFreeD_Stat_TCM;
          Dest.FCTVehPowerTrain.SSA_EngSp           = Src.FCTVehPowerTrain.SSA_EngSp;
          Dest.FCTVehPowerTrain.TargetGear          = Src.FCTVehPowerTrain.TargetGear;
          Dest.FCTVehESP.BrkIntrvntn_Actv_ESP       = Src.FCTVehESP.BrkIntrvntn_Actv_ESP;
          Dest.FCTVehESP.DPC_Md_AS_Rq               = Src.FCTVehESP.DPC_Md_AS_Rq;
          Dest.FCTVehESP.ESP_Oprtn_Stat_AS          = Src.FCTVehESP.ESP_Oprtn_Stat_AS;
          Dest.FCTVehESP.FCTVehESPSignalState       = Src.FCTVehESP.FCTVehESPSignalState;
          Dest.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP    = Src.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP;
          Dest.ExtDASystem                          = Src.ExtDASystem;
          Dest.FCTVehPassSafetySys                  = Src.FCTVehPassSafetySys;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      default:
        break;
      }
    }
    else if ((ulRPortSize == sizeof(FCTVehCustomInputV1::FCTVehCustomInput_t)) && ((requestPortVersionInfo.Equals(&FCT_VEH_CUSTOM_INPUT_V3_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      FCTVehCustomInputV1::FCTVehCustomInput_t & Dest = m_FCTVehCustomInputV1;
      switch (version)
      {
      case 0:
      case 1:
      case 2:
      case 3:
        if (sizeof(FCTVehCustomInputV1::FCTVehCustomInput_t) == ulPPortSize)
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      case 4:
      case 5:
        if (sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t) == ulPPortSize)
        {
          const FCTVehCustomInputV2::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV2::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                    = 3;
          Dest.sSigHeader                         = Src.sSigHeader;
          Dest.sSigHeader.eSigStatus              = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehPowerTrain.AccelPdlPosn_Raw  = Src.FCTVehPowerTrain.AccelPdlPosn_Raw;
          Dest.FCTVehPowerTrain.ActualGear        = Src.FCTVehPowerTrain.ActualGear;
          Dest.FCTVehPowerTrain.EngRun_Stat       = Src.FCTVehPowerTrain.EngRun_Stat;
          Dest.FCTVehPowerTrain.KickDnSw_Psd      = Src.FCTVehPowerTrain.KickDnSw_Psd;
          Dest.FCTVehPowerTrain.PowerTrainReady   = Src.FCTVehPowerTrain.PowerTrainReady;
          Dest.FCTVehPowerTrain.PwrFreeD_Stat_TCM = Src.FCTVehPowerTrain.PwrFreeD_Stat_TCM;
          Dest.FCTVehPowerTrain.SSA_EngSp         = Src.FCTVehPowerTrain.SSA_EngSp;
          Dest.FCTVehPowerTrain.TargetGear        = Src.FCTVehPowerTrain.TargetGear;
          Dest.FCTVehESP.BrkIntrvntn_Actv_ESP     = Src.FCTVehESP.BrkIntrvntn_Actv_ESP;
          Dest.FCTVehESP.DPC_Md_AS_Rq             = Src.FCTVehESP.DPC_Md_AS_Rq;
          Dest.FCTVehESP.ESP_Oprtn_Stat_AS        = Src.FCTVehESP.ESP_Oprtn_Stat_AS;
          Dest.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP  = Src.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP;
          Dest.ExtDASystem.BrkIntrvntn_Actv_CWA   = Src.ExtDASystem.BrkIntrvntn_Actv_CWA;
          Dest.ExtDASystem.BrkIntrvntn_Actv_LDP   = Src.ExtDASystem.BrkIntrvntn_Actv_LDP;
          Dest.ExtDASystem.DSR_Actv               = Src.ExtDASystem.DSR_Actv;
          Dest.ExtDASystem.VehAccel_X_AS_Actv_Rs  = Src.ExtDASystem.VehAccel_X_AS_Actv_Rs;
          Dest.FCTVehPassSafetySys.Bckl_Sw_D_Stat = Src.FCTVehPassSafetySys.Bckl_Sw_D_Stat;
          Dest.FCTVehPassSafetySys.Impact_X       = Src.FCTVehPassSafetySys.Impact_X;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 6:
        if (sizeof(FCTVehCustomInputV1::FCTVehCustomInput_t) == ulPPortSize)
        {
          const FCTVehCustomInputV1::FCTVehCustomInput_t & Src = *reinterpret_cast<FCTVehCustomInputV1::FCTVehCustomInput_t*>(pPPortData);
          Dest.uiVersionNumber                    = 3;
          Dest.sSigHeader                         = Src.sSigHeader;
          Dest.sSigHeader.eSigStatus              = /*Src.sSigHeader.eSigStatus*/ /*AL_SIG_STATE_OK=*/ 1;
          Dest.FCTVehPowerTrain.AccelPdlPosn_Raw  = Src.FCTVehPowerTrain.AccelPdlPosn_Raw;
          Dest.FCTVehPowerTrain.ActualGear        = Src.FCTVehPowerTrain.ActualGear;
          Dest.FCTVehPowerTrain.EngRun_Stat       = Src.FCTVehPowerTrain.EngRun_Stat;
          Dest.FCTVehPowerTrain.KickDnSw_Psd      = Src.FCTVehPowerTrain.KickDnSw_Psd;
          Dest.FCTVehPowerTrain.PowerTrainReady   = Src.FCTVehPowerTrain.PowerTrainReady;
          Dest.FCTVehPowerTrain.PwrFreeD_Stat_TCM = Src.FCTVehPowerTrain.PwrFreeD_Stat_TCM;
          Dest.FCTVehPowerTrain.SSA_EngSp         = Src.FCTVehPowerTrain.SSA_EngSp;
          Dest.FCTVehPowerTrain.TargetGear        = Src.FCTVehPowerTrain.TargetGear;
          Dest.FCTVehESP.BrkIntrvntn_Actv_ESP     = Src.FCTVehESP.BrkIntrvntn_Actv_ESP;
          Dest.FCTVehESP.DPC_Md_AS_Rq             = Src.FCTVehESP.DPC_Md_AS_Rq;
          Dest.FCTVehESP.ESP_Oprtn_Stat_AS        = Src.FCTVehESP.ESP_Oprtn_Stat_AS;
          Dest.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP  = Src.FCTVehESP.VehAccel_X_Dsabl_Rq_ESP;
          Dest.ExtDASystem.BrkIntrvntn_Actv_CWA   = Src.ExtDASystem.BrkIntrvntn_Actv_CWA;
          Dest.ExtDASystem.BrkIntrvntn_Actv_LDP   = Src.ExtDASystem.BrkIntrvntn_Actv_LDP;
          Dest.ExtDASystem.DSR_Actv               = Src.ExtDASystem.DSR_Actv;
          Dest.ExtDASystem.VehAccel_X_AS_Actv_Rs  = Src.ExtDASystem.VehAccel_X_AS_Actv_Rs;
          Dest.FCTVehPassSafetySys.Bckl_Sw_D_Stat = Src.FCTVehPassSafetySys.Bckl_Sw_D_Stat;
          Dest.FCTVehPassSafetySys.Impact_X       = Src.FCTVehPassSafetySys.Impact_X;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      default:
        break;
      }
    }
    else if (ulRPortSize == 4u)
    {
      // Special 4 byte input port : FCT does not really need ACC lever information only dummy version number
      *pOutData = &DummyVersion;
      ulOutSize = sizeof(DummyVersion);
      lRet = SIM_ERR_OK;
    }
    else
    {
      // Destination (request port) format not known
      lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
    }
  }
  else
  {
    // Provide port smaller than version number?!
    lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  }
  return lRet;
}

/** returns: 
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvFCTVehCustomInput::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V10]) &&
      ((requestPortVersionInfo.Equals(VERSION_NUMBERS[FCT_VEH_CUSTOM_INPUT_V10])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitVersion(m_FCTVehCustomInputV10, 10u);
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.eRadarBlockage     = FCTVehCustomInputV7::FCT_VEH_SenBlockage0;
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.eCameraBlockage    = FCTVehCustomInputV7::FCT_VEH_SenBlockage0;
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.eVehicleCondition  = FCTVehCustomInputV7::FCTVehCustomVehCondition1;
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.fWarningPedVminEgo = 5.f;
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.fWarningPedVmaxEgo = 85.f;
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.fWarningBicVminEgo = 5.f;
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.fWarningBicVmaxEgo = 85.f;
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.fBrakePedVminEgo   = 5.f;
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.fBrakePedVmaxEgo   = 65.f;
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.fBrakeBicVminEgo   = 5.f;
      m_FCTVehCustomInputV10.FCTVehBMWSysFct.fBrakeBicVmaxEgo   = 65.f;
      *pDefaultData = &m_FCTVehCustomInputV10;
      ulDefaultSize = sizeof(m_FCTVehCustomInputV10);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V8]) &&
      ((requestPortVersionInfo.Equals(VERSION_NUMBERS[FCT_VEH_CUSTOM_INPUT_V8])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitVersion(m_FCTVehCustomInputV8, 8u);
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.eRadarBlockage     = FCTVehCustomInputV7::FCT_VEH_SenBlockage0;
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.eCameraBlockage    = FCTVehCustomInputV7::FCT_VEH_SenBlockage0;
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.eVehicleCondition  = FCTVehCustomInputV7::FCTVehCustomVehCondition1;
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.fWarningPedVminEgo = 5.f;
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.fWarningPedVmaxEgo = 85.f;
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.fWarningBicVminEgo = 5.f;
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.fWarningBicVmaxEgo = 85.f;
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.fBrakePedVminEgo   = 5.f;
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.fBrakePedVmaxEgo   = 65.f;
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.fBrakeBicVminEgo   = 5.f;
      m_FCTVehCustomInputV8.FCTVehBMWSysFct.fBrakeBicVmaxEgo   = 65.f;
      *pDefaultData = &m_FCTVehCustomInputV8;
      ulDefaultSize = sizeof(m_FCTVehCustomInputV8);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[FCT_VEH_CUSTOM_INPUT_V7]) &&
      ((requestPortVersionInfo.Equals(VERSION_NUMBERS[FCT_VEH_CUSTOM_INPUT_V7])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitVersion(m_FCTVehCustomInputV7, 7u);
      m_FCTVehCustomInputV7.FCTVehBMWSysFct.eRadarBlockage    = FCTVehCustomInputV7::FCT_VEH_SenBlockage0;
      m_FCTVehCustomInputV7.FCTVehBMWSysFct.eCameraBlockage   = FCTVehCustomInputV7::FCT_VEH_SenBlockage0;
      m_FCTVehCustomInputV7.FCTVehBMWSysFct.eVehicleCondition = FCTVehCustomInputV7::FCTVehCustomVehCondition1;
      *pDefaultData = &m_FCTVehCustomInputV7;
      ulDefaultSize = sizeof(m_FCTVehCustomInputV7);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t)) &&
      ((requestPortVersionInfo.Equals(&FCT_VEH_CUSTOM_INPUT_V4_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitVersion(m_FCTVehCustomInputV6, 6u);
      m_FCTVehCustomInputV6.FCTVehPowerTrain.ENG_RPM = 2000u;
      m_FCTVehCustomInputV6.FCTVehESP.bESPMode = 1u;
      *pDefaultData = &m_FCTVehCustomInputV6;
      ulDefaultSize = sizeof(m_FCTVehCustomInputV6);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(FCTVehCustomInputV2::FCTVehCustomInput_t)) &&
      ((requestPortVersionInfo.Equals(&FCT_VEH_CUSTOM_INPUT_V4_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitVersion(m_FCTVehCustomInputV2, 4u);
      *pDefaultData = &m_FCTVehCustomInputV2;
      ulDefaultSize = sizeof(m_FCTVehCustomInputV2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(FCTVehCustomInputV1::FCTVehCustomInput_t)) &&
      ((requestPortVersionInfo.Equals(&FCT_VEH_CUSTOM_INPUT_V3_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitVersion(m_FCTVehCustomInputV1, 3u);
      *pDefaultData = &m_FCTVehCustomInputV1;
      ulDefaultSize = sizeof(m_FCTVehCustomInputV1);
      lRet = SIM_ERR_OK;
    }
    else if (ulRPortSize == sizeof(DummyVersion))
    {
      *pDefaultData = &DummyVersion;
      ulDefaultSize = sizeof(DummyVersion);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvFCTVehCustomInput::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;

  if (ePPortType == eRPortType)
  {
    // Check if ports are of equal size & type. In this case always declare them compatible
    if (ulRPortSize == ulPPortSize)
    {
      bResult = true;
    }
    else
    {
      // Conversion necessary
      if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
      {
        bResult = true;
      }
      if ((bResult == false) && (ulRPortSize == sizeof(DummyVersion)))
      {
        bResult = true;
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvFCTVehCustomInput::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // Ports with same type/size/version are always compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// CreateAccLeverConvClass : single externally visible function of module
//

IConverter * CreateFCTVehCustomInputConvClass(void)
{
  return new CConvFCTVehCustomInput();
}
