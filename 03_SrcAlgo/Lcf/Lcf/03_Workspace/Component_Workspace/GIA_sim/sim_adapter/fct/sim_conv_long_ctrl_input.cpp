/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_long_ctrl_input.cpp

  DESCRIPTION:          Converter class for LongCtrlInput

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        27.10.2011

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_long_ctrl_input.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:20CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.17 2016/11/17 14:14:15CET Dagli, Goekhan (uidj7850) 
  CHANGES:              + Conversion from V15 (=V21 (Mitsubishi)) to V22 (=V6_2) (Mitsubishi)
  CHANGES:              + Missing Conversion: Dest.sSigHeader = Src.sSigHeader
  CHANGES:              Revision 1.16 2016/11/16 14:05:47CET Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              + V7 (Daimler)
  CHANGES:              Revision 1.15 2016/11/08 13:33:19CET Cretu, Teodora (CretuT) 
  CHANGES:              A new version is added (V34 Hyundai)
  CHANGES:              Revision 1.14 2016/09/09 12:18:52CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              Added Version 7 (Toyota), 11 (Toyota_2) and 25 (Hyundai for using Toyota data)
  CHANGES:              Revision 1.13 2016/08/25 15:07:12CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              Version 21 for Mitsubishi fixed
  CHANGES:              Revision 1.12 2016/08/25 13:10:19CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              Added Version 21 and Version 22 for Mitsubishi for using Daimler data
  CHANGES:              Revision 1.11 2016/05/20 15:23:50CEST Both, Jens (uidg3187) 
  CHANGES:              - Merge update for interface version 19 and 18 for Toyota and Daimler project.
  CHANGES:              Revision 1.10.1.2 2016/05/20 15:21:27CEST Both, Jens (uidg3187) 
  CHANGES:              - Update simulation adapter for Daimler project (interface version 18)
  CHANGES:              - Fix missing condition in function IsVersionCompatibleWithType().
  CHANGES:              Revision 1.10.1.1 2016/04/25 13:15:03CEST Both, Jens (uidg3187) 
  CHANGES:              Not tested for all affected projects yet
  CHANGES:              - Add adaption of interface version 19 due to an update in the Toyota project's custom input signal
  CHANGES:              Revision 1.10 2015/09/22 13:48:12CEST Dohri, Karim (TFCES9) 
  CHANGES:              Fix Custom conversion (version 12) for missing EngineEcuInput in old measurements
  CHANGES:              --- Added comments ---  TFCES9 [Sep 22, 2015 1:48:12 PM CEST]
  CHANGES:              Change Package : 371667:1 http://mks-psad:7002/im/viewissue?selection=371667
  CHANGES:              Revision 1.9 2015/09/03 14:13:41CEST Dohri, Karim (TFCES9) 
  CHANGES:              update the adapter To use Toyota with long control input version number 11 for Gely project.
  CHANGES:              --- Added comments ---  TFCES9 [Sep 3, 2015 2:13:41 PM CEST]
  CHANGES:              Change Package : 371667:1 http://mks-psad:7002/im/viewissue?selection=371667
  CHANGES:              Revision 1.8 2015/07/15 16:39:37CEST Dohri, Karim (TFCES9) 
  CHANGES:              Add new signals in LongCtrlInput in MTS SIM Adapter for Geely
  CHANGES:              --- Added comments ---  TFCES9 [Jul 15, 2015 4:39:37 PM CEST]
  CHANGES:              Change Package : 356445:1 http://mks-psad:7002/im/viewissue?selection=356445
  CHANGES:              Revision 1.7 2015/02/27 16:18:14CET Both, Jens (uidg3187) 
  CHANGES:              - Fix Custom conversion for missing EngineEcuInput in old measurements
  CHANGES:              --- Added comments ---  uidg3187 [Feb 27, 2015 4:18:15 PM CET]
  CHANGES:              Change Package : 300393:2 http://mks-psad:7002/im/viewissue?selection=300393
  CHANGES:              Revision 1.6 2014/10/27 11:02:39CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Try to create a working adapter for both Daimler and TMC configurations (no pre-processor switching, since the switch isn't visible
  CHANGES:              in the adapter anyway)
  CHANGES:              --- Added comments ---  ungvaryg [Oct 27, 2014 11:02:39 AM CET]
  CHANGES:              Change Package : 263272:4 http://mks-psad:7002/im/viewissue?selection=263272
  CHANGES:              Revision 1.5 2014/10/09 14:01:50CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Update for AL_ARS400EN_01.15.01
  CHANGES:              LongCtrlInputV10
  CHANGES:              DimInputCustomV6_2
  CHANGES:              update FCTVehCustomInput
  CHANGES:              --- Added comments ---  berndtt1 [Oct 10, 2014 7:43:22 AM CEST]
  CHANGES:              Change Package : 270187:1 http://mks-psad:7002/im/viewissue?selection=270187
  CHANGES:              Revision 1.4 2014/09/03 16:00:32CEST Sinnstein, Simon (uidw0203) 
  CHANGES:              update for ARS430DP15
  CHANGES:              --- Added comments ---  uidw0203 [Sep 3, 2014 4:00:32 PM CEST]
  CHANGES:              Change Package : 198893:2 http://mks-psad:7002/im/viewissue?selection=198893
  CHANGES:              Revision 1.3 2014/09/02 09:40:02CEST Sinnstein, Simon (uidw0203) 
  CHANGES:              Update DAI spesific Signals
  CHANGES:              --- Added comments ---  uidw0203 [Sep 2, 2014 9:40:02 AM CEST]
  CHANGES:              Change Package : 198893:1 http://mks-psad:7002/im/viewissue?selection=198893
  CHANGES:              Revision 1.2 2014/02/06 16:27:35CET Both, Jens (uidg3187) 
  CHANGES:              Add workaround for ars4t0 missing engine ecu signals
  CHANGES:              --- Added comments ---  uidg3187 [Feb 6, 2014 4:27:35 PM CET]
  CHANGES:              Change Package : 207937:2 http://mks-psad:7002/im/viewissue?selection=207937
  CHANGES:              Revision 1.1 2014/01/09 15:28:50CET Both, Jens (uidg3187) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.3 2013/05/21 18:04:22CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              --- Added comments ---  ungvaryg [May 21, 2013 6:04:22 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.2 2011/11/03 14:21:14CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add dummy AccLever conversion support (which consists of only 4 byte long version number for projects where no AccLever information present)
  CHANGES:              --- Added comments ---  ungvaryg [Nov 3, 2011 2:21:14 PM CET]
  CHANGES:              Change Package : 86065:1 http://mks-psad:7002/im/viewissue?selection=86065
  CHANGES:              Revision 1.1 2011/10/27 17:59:24CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_long_ctrl_input.h"
#include "sim_versioninfo_impl.h"

//
// LongCtrlInput structure declarations
//

namespace LongCtrlInputV5
{
  typedef unsigned long AlgoDataTimeStamp_t;  /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */
  typedef unsigned short AlgoCycleCounter_t;  /* Algo cycle counter @min:0 @max:65535 */
  typedef unsigned char AlgoSignalState_t;    /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */

  typedef enum AlgoSignalState_enum_t {
    AL_SIG_STATE_INIT=0,
    AL_SIG_STATE_OK=1,
    AL_SIG_STATE_INVALID=2,
  } AlgoSignalState_enum_t;

  typedef struct SignalHeader_t
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;  /* Common header for all structured data types */

  typedef uint8 DC_status_information_t;  /* 0 = DC available, 1 = DC reversible not available, 2 = DC irreversible not available (for rest of ignition cycle) @min: 0 @max:2 @values: enum { DC_STATUS_AVAILABLE=0,DC_STATUS_NOT_AVAIL=2,DC_STATUS_TMP_NOT_AVAIL=1,} */

  typedef enum DC_status_info_enum_t {
    DC_STATUS_AVAILABLE=0,
    DC_STATUS_TMP_NOT_AVAIL=1,
    DC_STATUS_NOT_AVAIL=2,
  } DC_status_info_enum_t;

  typedef uint8 ldm_ctrl_state_t; /* LDM control state: indicates if ABS/TCS/ESP intervention active or control defective @min: 1 @max:32 @values: enum { LDM_CTRL_TCS_ACTIVE=2,LDM_CTRL_ESP_DEFECTIVE=32,LDM_CTRL_ABS_ACTIVE=1,LDM_CTRL_TCS_DEFECTIVE=16,LDM_CTRL_ABS_DEFECTIVE=8,LDM_CTRL_ESP_ACTIVE=4,} */

  typedef enum ldm_ctrl_state_enum_t {
    LDM_CTRL_ABS_ACTIVE=1,
    LDM_CTRL_TCS_ACTIVE=2,
    LDM_CTRL_ESP_ACTIVE=4,
    LDM_CTRL_ABS_DEFECTIVE=8,
    LDM_CTRL_TCS_DEFECTIVE=16,
    LDM_CTRL_ESP_DEFECTIVE=32,
  } ldm_ctrl_state_enum_t;

  typedef uint8 door_state_t; /* States of doors (bit field) @min: 1 @max:32 @values: enum { DOOR_TRUNK_OPEN=32,DOOR_FRONT_RIGHT_OPEN=2,DOOR_ENG_HOOD_OPEN=16,DOOR_REAR_LEFT_OPEN=4,DOOR_FRONT_LEFT_OPEN=1,DOOR_REAR_RIGHT_OPEN=8,} */

  typedef enum door_state_enum_t {
    DOOR_FRONT_LEFT_OPEN=1,
    DOOR_FRONT_RIGHT_OPEN=2,
    DOOR_REAR_LEFT_OPEN=4,
    DOOR_REAR_RIGHT_OPEN=8,
    DOOR_ENG_HOOD_OPEN=16,
    DOOR_TRUNK_OPEN=32,
  } door_state_enum_t;

  typedef uint8 SpeedUnitEnum_t;  /* Speed unit of spedometer @min: 0 @max:1 @values: enum { SPD_UNIT_KMH=0,SPD_UNIT_MPH=1,} */

  typedef enum SpeedUnitEnum_enum_t {
    SPD_UNIT_KMH=0,
    SPD_UNIT_MPH=1,
  } SpeedUnitEnum_enum_t;

  typedef struct KinCtrlDynInput_t
  {
    signed short longi_initialization_accel;
    unsigned char perm_lim_setspeed;
    boolean var_lim_eng;
    boolean stand_still_detected;
    DC_status_information_t DC_status_information;
    boolean driver_override_accel_pedal;
    boolean driver_override_decel_pedal;
    boolean driver_braking;
    boolean DAS_accel_request_limited;
    boolean DAS_decel_request_limited;
    boolean longi_shutoff_acknowledged;
    ldm_ctrl_state_t ldm_ctrl_state;
    boolean acc_enable;
    boolean park_brk_eng;
    boolean brk_sw;
    door_state_t door_state;
  } KinCtrlDynInput_t;  /* Dynamic controller output used by the kinematic controller as input */

  typedef struct KinDisplayInput_t
  {
    SpeedUnitEnum_t speed_unit;
    unsigned char speedometer_speed;
  } KinDisplayInput_t;  /* Output from display to the kinematic controller */

  typedef struct LongCtrlInput_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    KinCtrlDynInput_t KinCtrlDynInput;
    KinDisplayInput_t DisplayOutput;
  } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

};  // End of namespace LongCtrlInputV5


namespace LongCtrlInputV6
{
#if 0   // Reuse other namespace types where identical
  typedef unsigned long AlgoDataTimeStamp_t;  /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */
  typedef unsigned short AlgoCycleCounter_t;  /* Algo cycle counter @min:0 @max:65535 */
  typedef unsigned char AlgoSignalState_t;    /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */

  typedef enum AlgoSignalState_enum_t {
    AL_SIG_STATE_INIT=0,
    AL_SIG_STATE_OK=1,
    AL_SIG_STATE_INVALID=2,
  } AlgoSignalState_enum_t;

  typedef struct SignalHeader_t
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;  /* Common header for all structured data types */

  typedef uint8 DC_status_information_t;   /* 0 = DC available, 1 = DC reversible not available, 2 = DC irreversible not available (for rest of ignition cycle) @min: 0 @max:2 @values: enum { DC_STATUS_AVAILABLE=0,DC_STATUS_NOT_AVAIL=2,DC_STATUS_TMP_NOT_AVAIL=1,} */

  typedef enum DC_status_info_enum_t {
    DC_STATUS_AVAILABLE=0,
    DC_STATUS_TMP_NOT_AVAIL=1,
    DC_STATUS_NOT_AVAIL=2,
  } DC_status_info_enum_t;

  typedef uint8 ldm_ctrl_state_t; /* LDM control state: indicates if ABS/TCS/ESP intervention active or control defective @min: 1 @max:32 @values: enum { LDM_CTRL_TCS_ACTIVE=2,LDM_CTRL_ESP_DEFECTIVE=32,LDM_CTRL_ABS_ACTIVE=1,LDM_CTRL_TCS_DEFECTIVE=16,LDM_CTRL_ABS_DEFECTIVE=8,LDM_CTRL_ESP_ACTIVE=4,} */

  typedef enum ldm_ctrl_state_enum_t {
    LDM_CTRL_ABS_ACTIVE=1,
    LDM_CTRL_TCS_ACTIVE=2,
    LDM_CTRL_ESP_ACTIVE=4,
    LDM_CTRL_ABS_DEFECTIVE=8,
    LDM_CTRL_TCS_DEFECTIVE=16,
    LDM_CTRL_ESP_DEFECTIVE=32,
  } ldm_ctrl_state_enum_t;

  typedef uint8 door_state_t; /* States of doors (bit field) @min: 1 @max:32 @values: enum { DOOR_TRUNK_OPEN=32,DOOR_FRONT_RIGHT_OPEN=2,DOOR_ENG_HOOD_OPEN=16,DOOR_REAR_LEFT_OPEN=4,DOOR_FRONT_LEFT_OPEN=1,DOOR_REAR_RIGHT_OPEN=8,} */

  typedef enum door_state_enum_t {
    DOOR_FRONT_LEFT_OPEN=1,
    DOOR_FRONT_RIGHT_OPEN=2,
    DOOR_REAR_LEFT_OPEN=4,
    DOOR_REAR_RIGHT_OPEN=8,
    DOOR_ENG_HOOD_OPEN=16,
    DOOR_TRUNK_OPEN=32,
  } door_state_enum_t;

  typedef uint8 SpeedUnitEnum_t;  /* Speed unit of spedometer @min: 0 @max:1 @values: enum { SPD_UNIT_KMH=0,SPD_UNIT_MPH=1,} */

  typedef enum SpeedUnitEnum_enum_t {
    SPD_UNIT_KMH=0,
    SPD_UNIT_MPH=1,
  } SpeedUnitEnum_enum_t;

  typedef struct KinCtrlDynInput_t
  {
    signed short longi_initialization_accel;
    unsigned char perm_lim_setspeed;
    boolean var_lim_eng;
    boolean stand_still_detected;
    DC_status_information_t DC_status_information;
    boolean driver_override_accel_pedal;
    boolean driver_override_decel_pedal;
    boolean driver_braking;
    boolean DAS_accel_request_limited;
    boolean DAS_decel_request_limited;
    boolean longi_shutoff_acknowledged;
    ldm_ctrl_state_t ldm_ctrl_state;
    boolean acc_enable;
    boolean park_brk_eng;
    boolean brk_sw;
    door_state_t door_state;
  } KinCtrlDynInput_t;  /* Dynamic controller output used by the kinematic controller as input */

  typedef struct KinDisplayInput_t
  {
    SpeedUnitEnum_t speed_unit;
    unsigned char speedometer_speed;
  } KinDisplayInput_t;  /* Output from display to the kinematic controller */

  typedef struct LongCtrlInputBase_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    KinCtrlDynInput_t KinCtrlDynInput;
    KinDisplayInput_t DisplayOutput;
  } LongCtrlInputBase_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */
#else
  // Since all struct identical to V5, just derive base version
  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;
  typedef LongCtrlInputV5::KinCtrlDynInput_t KinCtrlDynInput_t;
  typedef LongCtrlInputV5::KinDisplayInput_t KinDisplayInput_t;
  typedef LongCtrlInputV5::LongCtrlInput_t LongCtrlInputBase_t;
#endif

  namespace Toyota
  {
    typedef signed short acceleration_t; /* Integer acceleration type @min:-32.767 @max:32.767 @resolution:0.001 */

    typedef unsigned char SPDSTAT_t;  /* Control Status at cruise lever operation by driver. @min: 0 @max:10 @values: enum { SPDSTAT_UNDER_DECEL_RQ_ACC=10,SPDSTAT_UNDER_CC_RESUME_CTRL=2,SPDSTAT_UNDER_CC_ACCEL_CTRL=3,SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,SPDSTAT_ACC_IDLE=8,SPDSTAT_UNDER_STOP_HOLD_ACC=7,SPDSTAT_NO_STATUS=0,SPDSTAT_UNDER_ACCEL_RQ_ACC=9,SPDSTAT_CC_IDLE=1,SPDSTAT_UNDER_CC_CORST_CTRL=4,SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,} */

    typedef enum SPDSTAT_enum_t{
      SPDSTAT_NO_STATUS=0,
      SPDSTAT_CC_IDLE=1,
      SPDSTAT_UNDER_CC_RESUME_CTRL=2,
      SPDSTAT_UNDER_CC_ACCEL_CTRL=3,
      SPDSTAT_UNDER_CC_CORST_CTRL=4,
      SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,
      SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,
      SPDSTAT_UNDER_STOP_HOLD_ACC=7,
      SPDSTAT_ACC_IDLE=8,
      SPDSTAT_UNDER_ACCEL_RQ_ACC=9,
      SPDSTAT_UNDER_DECEL_RQ_ACC=10,
    } SPDSTAT_enum_t;

    typedef unsigned char ACCSTAT_t;  /* Output control status @min: 0 @max:3 @values: enum { ACCSTAT_ACTIVE_OR_OVERRIDE=1,ACCSTAT_PB_RQ=3,ACCSTAT_DISENGAGE_OR_OFF=0,} */

    typedef enum ACC_STAT_enum_t {
      ACCSTAT_DISENGAGE_OR_OFF=0,
      ACCSTAT_ACTIVE_OR_OVERRIDE=1,
      ACCSTAT_PB_RQ=3,
    } ACC_STAT_enum_t;

    typedef unsigned char SLTACC_t;   /* ACC type @min: 0 @max:3 @values: enum { SLTACC_ACC_TYPE_FSRA=1,SLTACC_ACC_TYPE_CC=3,SLTACC_ACC_TYPE_RESERVE=0,SLTACC_ACC_TYPE_ACC=2,} */

    typedef enum SLTACC_enum_t {
      SLTACC_ACC_TYPE_RESERVE=0,
      SLTACC_ACC_TYPE_FSRA=1,
      SLTACC_ACC_TYPE_ACC=2,
      SLTACC_ACC_TYPE_CC=3,
    } SLTACC_enum_t;

    typedef unsigned char LTME2_t;    /* Vehicle following time @min: 0 @max:3 @values: enum { LTME2_VEH_FOLLOW_TIME_MIDDLE=2,LTME2_VEH_FOLLOW_TIME_SHORT=3,LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,LTME2_VEH_FOLLOW_TIME_LONG=1,} */

    typedef enum LTME2_enum_t {
      LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,
      LTME2_VEH_FOLLOW_TIME_LONG=1,
      LTME2_VEH_FOLLOW_TIME_MIDDLE=2,
      LTME2_VEH_FOLLOW_TIME_SHORT=3,
    } LTME2_enum_t;

    typedef struct EngineEcuInput_t
    {
      boolean XLDR;
      boolean XACCACT;
      boolean STPBZ;
      acceleration_t ACCREQ;
      SPDSTAT_t SPDSTAT;
      ACCSTAT_t ACCSTAT;
      unsigned char LCCHK;
      unsigned char VM;
      boolean XCCOK2;
      SLTACC_t SLTACC;
      LTME2_t LTME2;
      acceleration_t INTG;
    } EngineEcuInput_t; /* Input from TMC engine ECU (manages state machine, driver inputs etc.) */

    typedef struct LongCtrlInputCustom_t
    {
      EngineEcuInput_t EngineEcuInput;
    } LongCtrlInputCustom_t;  /* Customer specific fields */

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  }; // End of namespace Toyota

  namespace Daimler {
    typedef uint8 SPCR_Md_t;  /* Stop coordinator state (Signal SPCR_Md) @min: 0 @max:8 @values: enum { STOP_COORD_ACTIVE_SLIP=7,STOP_COORD_ACTIVE_GO=6,STOP_COORD_HOLD=1,STOP_COORD_ACTIVE_HOLD=5,STOP_COORD_GO=2,STOP_COORD_PASSIVE=8,STOP_COORD_SLIP=3,STOP_COORD_IDLE=0,STOP_COORD_ACTIVE=4,}  */

    typedef enum SPCR_Md_enum_t {
      STOP_COORD_IDLE=0,
      STOP_COORD_HOLD=1,
      STOP_COORD_GO=2,
      STOP_COORD_SLIP=3,
      STOP_COORD_ACTIVE=4,
      STOP_COORD_ACTIVE_HOLD=5,
      STOP_COORD_ACTIVE_GO=6,
      STOP_COORD_ACTIVE_SLIP=7,
      STOP_COORD_PASSIVE=8,
    } SPCR_Md_enum_t;

    typedef uint8 SPCR_Excpt_Rq_V2_t;  /* Stop coordinator exception request @min: 0 @max:3 @values: enum { AS_ENABLE=0,AS_DISABLE_ENG_HOOD_OPEN=2,AS_DISABLE_DRV_ABSENT=1,AS_DISABLE_DRV_ENG_HOOD=3,} */

    typedef enum SPCR_Excpt_Rq_V2_enum_t {
      AS_ENABLE=0,
      AS_DISABLE_DRV_ABSENT=1,
      AS_DISABLE_ENG_HOOD_OPEN=2,
      AS_DISABLE_DRV_ENG_HOOD=3,
    } SPCR_Excpt_Rq_V2_enum_t;

    typedef uint8 SPCR_AS_Off_Rq_t;  /* Stop Coordinator Assistance system off request @min: 0 @max:3 @values: enum { STOP_COORD_SYS_OFF_IDLE=0,STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,STOP_COORD_SYS_OFF_AS_CONT_OFF=2,STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,}  */

    typedef enum SPCR_AS_Off_Rq_enum_t {
      STOP_COORD_SYS_OFF_IDLE=0,
      STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,
      STOP_COORD_SYS_OFF_AS_CONT_OFF=2,
      STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,
    } SPCR_AS_Off_Rq_enum_t;

    typedef uint8 SPCR_AS_Dsabl_t;  /* Stop Coordinator disable assistance system (temperatur) @min: 0 @max:2 @values: enum { STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,STOP_COORD_SYS_DIS_IDLE=0,STOP_COORD_SYS_DIS_AS_DISABLE=2,}  */

    typedef enum SPCR_AS_Dsabl_enum_t {
      STOP_COORD_SYS_DIS_IDLE=0,
      STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,
      STOP_COORD_SYS_DIS_AS_DISABLE=2,
    } SPCR_AS_Dsabl_enum_t;

    typedef struct LongCtrlInputCustomSPCR_t 
    {
      SPCR_Md_t SPCR_Md;
      SPCR_Excpt_Rq_V2_t SPCR_Excpt_Rq_V2;
      SPCR_AS_Off_Rq_t SPCR_AS_Off_Rq;
      SPCR_AS_Dsabl_t SPCR_AS_Dsabl;
      boolean SPCR_Veh_Immo;
    } LongCtrlInputCustomSPCR_t;     /* Stop Coordinator fields */

    typedef uint8 VehAccel_X_LDC_VehSp_Rs_t; /* Longitudinal controller vehicle stop response @min: 0 @max:3 @values: enum { LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,LONG_VEH_STOP_RQ_IDLE=0,LONG_VEH_STOP_RQ_COMPLETE=2,LONG_VEH_STOP_RQ_ACTIVE=1,}  */

    typedef enum VehAccel_X_LDC_VehSp_Rs_enum_t {
      LONG_VEH_STOP_RQ_IDLE=0,
      LONG_VEH_STOP_RQ_ACTIVE=1,
      LONG_VEH_STOP_RQ_COMPLETE=2,
      LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,
    } VehAccel_X_LDC_VehSp_Rs_enum_t;

    typedef struct LongCtrlRs_t 
    {
      VehAccel_X_LDC_VehSp_Rs_t VehAccel_X_LDC_VehSp_Rs;
    } LongCtrlRs_t;			/* Custom Longitudinal Control Response (dynamic) */
  
    typedef struct LongCtrlInputCustom_t
    {
      LongCtrlInputCustomSPCR_t SPCR;
      LongCtrlRs_t LongCtrlRs;
    } LongCtrlInputCustom_t;  /* Customer specific fields */

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  };  // End of namespace Daimler

};  // End of namespace LongCtrlInputV6


namespace LongCtrlInputV7
{
  typedef LongCtrlInputV5::LongCtrlInput_t LongCtrlInputBase_t;

  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;
  typedef LongCtrlInputV5::KinCtrlDynInput_t KinCtrlDynInput_t;
  typedef LongCtrlInputV5::KinDisplayInput_t KinDisplayInput_t;

  typedef signed short acceleration_t; /* Integer acceleration type @min:-32.767 @max:32.767 @resolution:0.001 */
  typedef unsigned char SPDSTAT_t;  /* Control Status at cruise lever operation by driver. @min: 0 @max:10 @values: enum { SPDSTAT_UNDER_DECEL_RQ_ACC=10,SPDSTAT_UNDER_CC_RESUME_CTRL=2,SPDSTAT_UNDER_CC_ACCEL_CTRL=3,SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,SPDSTAT_ACC_IDLE=8,SPDSTAT_UNDER_STOP_HOLD_ACC=7,SPDSTAT_NO_STATUS=0,SPDSTAT_UNDER_ACCEL_RQ_ACC=9,SPDSTAT_CC_IDLE=1,SPDSTAT_UNDER_CC_CORST_CTRL=4,SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,} */
  typedef unsigned char ACCSTAT_t;  /* Output control status @min: 0 @max:3 @values: enum { ACCSTAT_ACTIVE_OR_OVERRIDE=1,ACCSTAT_PB_RQ=3,ACCSTAT_DISENGAGE_OR_OFF=0,} */
  typedef unsigned char SLTACC_t;   /* ACC type @min: 0 @max:3 @values: enum { SLTACC_ACC_TYPE_FSRA=1,SLTACC_ACC_TYPE_CC=3,SLTACC_ACC_TYPE_RESERVE=0,SLTACC_ACC_TYPE_ACC=2,} */
  typedef unsigned char LTME2_t;    /* Vehicle following time @min: 0 @max:3 @values: enum { LTME2_VEH_FOLLOW_TIME_MIDDLE=2,LTME2_VEH_FOLLOW_TIME_SHORT=3,LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,LTME2_VEH_FOLLOW_TIME_LONG=1,} */

  typedef struct EngineEcuInput_t
  {      
    boolean XLDR;
    boolean XACCACT;
    boolean STPBZ;
    boolean LCCW2;
    acceleration_t ACCREQ;
    SPDSTAT_t SPDSTAT;
    ACCSTAT_t ACCSTAT;
    unsigned char LCCHK;
    unsigned char VM;
    boolean XCCOK2;
    SLTACC_t SLTACC;
    LTME2_t LTME2;
    acceleration_t INTG;
  } EngineEcuInput_t;
  
  typedef struct LongCtrlInputCustom_t
  {
    EngineEcuInput_t EngineEcuInput;
  } LongCtrlInputCustom_t;

  namespace Toyota
  {
    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  }; // End of namespace Toyota

  namespace Daimler
  {
    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputV6::Daimler::LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  }; // End of namespace Daimler

};  // End of namespace LongCtrlInputV7


namespace LongCtrlInputV9
{
#if 0   // Re-use other namespace types where the same
  typedef unsigned long AlgoDataTimeStamp_t;  /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */
  typedef unsigned short AlgoCycleCounter_t;  /* Algo cycle counter @min:0 @max:65535 */
  typedef unsigned char AlgoSignalState_t;    /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */

  typedef enum AlgoSignalState_enum_t {
    AL_SIG_STATE_INIT=0,
    AL_SIG_STATE_OK=1,
    AL_SIG_STATE_INVALID=2,
  } AlgoSignalState_enum_t;

  typedef struct SignalHeader_t
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;  /* Common header for all structured data types */

  typedef uint8 DC_status_information_t;   /* 0 = DC available, 1 = DC reversible not available, 2 = DC irreversible not available (for rest of ignition cycle) @min: 0 @max:2 @values: enum { DC_STATUS_AVAILABLE=0,DC_STATUS_NOT_AVAIL=2,DC_STATUS_TMP_NOT_AVAIL=1,} */

  typedef enum DC_status_info_enum_t {
    DC_STATUS_AVAILABLE=0,
    DC_STATUS_TMP_NOT_AVAIL=1,
    DC_STATUS_NOT_AVAIL=2,
  } DC_status_info_enum_t;

  typedef uint8 ldm_ctrl_state_t; /* LDM control state: indicates if ABS/TCS/ESP intervention active or control defective @min: 1 @max:32 @values: enum { LDM_CTRL_TCS_ACTIVE=2,LDM_CTRL_ESP_DEFECTIVE=32,LDM_CTRL_ABS_ACTIVE=1,LDM_CTRL_TCS_DEFECTIVE=16,LDM_CTRL_ABS_DEFECTIVE=8,LDM_CTRL_ESP_ACTIVE=4,} */

  typedef enum ldm_ctrl_state_enum_t {
    LDM_CTRL_ABS_ACTIVE=1,
    LDM_CTRL_TCS_ACTIVE=2,
    LDM_CTRL_ESP_ACTIVE=4,
    LDM_CTRL_ABS_DEFECTIVE=8,
    LDM_CTRL_TCS_DEFECTIVE=16,
    LDM_CTRL_ESP_DEFECTIVE=32,
  } ldm_ctrl_state_enum_t;

  typedef uint8 door_state_t; /* States of doors (bit field) @min: 1 @max:32 @values: enum { DOOR_TRUNK_OPEN=32,DOOR_FRONT_RIGHT_OPEN=2,DOOR_ENG_HOOD_OPEN=16,DOOR_REAR_LEFT_OPEN=4,DOOR_FRONT_LEFT_OPEN=1,DOOR_REAR_RIGHT_OPEN=8,} */

  typedef enum door_state_enum_t {
    DOOR_FRONT_LEFT_OPEN=1,
    DOOR_FRONT_RIGHT_OPEN=2,
    DOOR_REAR_LEFT_OPEN=4,
    DOOR_REAR_RIGHT_OPEN=8,
    DOOR_ENG_HOOD_OPEN=16,
    DOOR_TRUNK_OPEN=32,
  } door_state_enum_t;

  typedef uint8 SpeedUnitEnum_t;  /* Speed unit of spedometer @min: 0 @max:1 @values: enum { SPD_UNIT_KMH=0,SPD_UNIT_MPH=1,} */

  typedef enum SpeedUnitEnum_enum_t {
    SPD_UNIT_KMH=0,
    SPD_UNIT_MPH=1,
  } SpeedUnitEnum_enum_t;
#else
  typedef LongCtrlInputV5::DC_status_information_t DC_status_information_t;
  typedef LongCtrlInputV5::ldm_ctrl_state_t ldm_ctrl_state_t;
  typedef LongCtrlInputV5::door_state_t door_state_t;
  typedef LongCtrlInputV5::SpeedUnitEnum_t SpeedUnitEnum_t;
  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;
#endif

  typedef uint8 country_code_t;  /* Country coding information @min: 0 @max:3 @values: enum { COUNTRY_REST_WORLD=0,COUNTRY_CANADA=3,COUNTRY_USA=1,COUNTRY_JAPAN=2,} */;

  typedef enum country_code_enum_t {
    COUNTRY_REST_WORLD = 0,
    COUNTRY_USA = 1,
    COUNTRY_JAPAN = 2,
    COUNTRY_CANADA = 3,
  } country_code_enum_t;

  typedef struct LongCtrlInputBase_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    //KinCtrlDynInput_t KinCtrlDynInput;
    //KinDisplayInput_t DisplayOutput;
  } LongCtrlInputBase_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  namespace Toyota
  {
#if 0   // Reuse identical types
    typedef signed short acceleration_t; /* Integer acceleration type @min:-32.767 @max:32.767 @resolution:0.001 */

    typedef unsigned char SPDSTAT_t;  /* Control Status at cruise lever operation by driver. @min: 0 @max:10 @values: enum { SPDSTAT_UNDER_DECEL_RQ_ACC=10,SPDSTAT_UNDER_CC_RESUME_CTRL=2,SPDSTAT_UNDER_CC_ACCEL_CTRL=3,SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,SPDSTAT_ACC_IDLE=8,SPDSTAT_UNDER_STOP_HOLD_ACC=7,SPDSTAT_NO_STATUS=0,SPDSTAT_UNDER_ACCEL_RQ_ACC=9,SPDSTAT_CC_IDLE=1,SPDSTAT_UNDER_CC_CORST_CTRL=4,SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,} */

    typedef enum SPDSTAT_enum_t{
      SPDSTAT_NO_STATUS=0,
      SPDSTAT_CC_IDLE=1,
      SPDSTAT_UNDER_CC_RESUME_CTRL=2,
      SPDSTAT_UNDER_CC_ACCEL_CTRL=3,
      SPDSTAT_UNDER_CC_CORST_CTRL=4,
      SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,
      SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,
      SPDSTAT_UNDER_STOP_HOLD_ACC=7,
      SPDSTAT_ACC_IDLE=8,
      SPDSTAT_UNDER_ACCEL_RQ_ACC=9,
      SPDSTAT_UNDER_DECEL_RQ_ACC=10,
    } SPDSTAT_enum_t;

    typedef unsigned char ACCSTAT_t;  /* Output control status @min: 0 @max:3 @values: enum { ACCSTAT_ACTIVE_OR_OVERRIDE=1,ACCSTAT_PB_RQ=3,ACCSTAT_DISENGAGE_OR_OFF=0,} */

    typedef enum ACC_STAT_enum_t {
      ACCSTAT_DISENGAGE_OR_OFF=0,
      ACCSTAT_ACTIVE_OR_OVERRIDE=1,
      ACCSTAT_PB_RQ=3,
    } ACC_STAT_enum_t;

    typedef unsigned char SLTACC_t;   /* ACC type @min: 0 @max:3 @values: enum { SLTACC_ACC_TYPE_FSRA=1,SLTACC_ACC_TYPE_CC=3,SLTACC_ACC_TYPE_RESERVE=0,SLTACC_ACC_TYPE_ACC=2,} */

    typedef enum SLTACC_enum_t {
      SLTACC_ACC_TYPE_RESERVE=0,
      SLTACC_ACC_TYPE_FSRA=1,
      SLTACC_ACC_TYPE_ACC=2,
      SLTACC_ACC_TYPE_CC=3,
    } SLTACC_enum_t;

    typedef unsigned char LTME2_t;    /* Vehicle following time @min: 0 @max:3 @values: enum { LTME2_VEH_FOLLOW_TIME_MIDDLE=2,LTME2_VEH_FOLLOW_TIME_SHORT=3,LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,LTME2_VEH_FOLLOW_TIME_LONG=1,} */

    typedef enum LTME2_enum_t {
      LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,
      LTME2_VEH_FOLLOW_TIME_LONG=1,
      LTME2_VEH_FOLLOW_TIME_MIDDLE=2,
      LTME2_VEH_FOLLOW_TIME_SHORT=3,
    } LTME2_enum_t;

    typedef struct EngineEcuInput_t
    {
      boolean XLDR;
      boolean XACCACT;
      boolean STPBZ;
      acceleration_t ACCREQ;
      SPDSTAT_t SPDSTAT;
      ACCSTAT_t ACCSTAT;
      unsigned char LCCHK;
      unsigned char VM;
      boolean XCCOK2;
      SLTACC_t SLTACC;
      LTME2_t LTME2;
      acceleration_t INTG;
    } EngineEcuInput_t; /* Input from TMC engine ECU (manages state machine, driver inputs etc.) */

    typedef struct LongCtrlInputCustom_t
    {
      EngineEcuInput_t EngineEcuInput;
    } LongCtrlInputCustom_t;  /* Customer specific fields */
#else
    typedef LongCtrlInputV6::Toyota::LongCtrlInputCustom_t LongCtrlInputCustom_t;
#endif
    typedef struct KinCtrlDynInput_t
    {
      signed short longi_initialization_accel;
      unsigned char perm_lim_setspeed;
      boolean var_lim_eng;
      boolean stand_still_detected;
      DC_status_information_t DC_status_information;
      boolean driver_override_accel_pedal;
      boolean driver_override_decel_pedal;
      boolean driver_braking;
      boolean DAS_accel_request_limited;
      boolean DAS_decel_request_limited;
      boolean longi_shutoff_acknowledged;
      ldm_ctrl_state_t ldm_ctrl_state;
      boolean acc_enable;
      boolean park_brk_eng;
      boolean brk_sw;
      door_state_t door_state;
      country_code_t country_code;
    } KinCtrlDynInput_t;  /* Dynamic controller output used by the kinematic controller as input */

    typedef enum DisplayOutputSignalState_enum_t {
      SPEED_UNIT = 1,
      SPEEDOMETER_SPEED = 2,
    } DisplayOutputSignalState_enum_t;

    typedef struct KinDisplayInput_t
    {
      SpeedUnitEnum_t speed_unit;
      unsigned char speedometer_speed;
    } KinDisplayInput_t;  /* Output from display to the kinematic controller */

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */
  };  // End of namespace Toyota

  namespace Daimler
  {
#if 0   // Reuse identical types from previous namespace
    typedef uint8 SPCR_Md_t;  /* Stop coordinator state (Signal SPCR_Md) @min: 0 @max:8 @values: enum { STOP_COORD_ACTIVE_SLIP=7,STOP_COORD_ACTIVE_GO=6,STOP_COORD_HOLD=1,STOP_COORD_ACTIVE_HOLD=5,STOP_COORD_GO=2,STOP_COORD_PASSIVE=8,STOP_COORD_SLIP=3,STOP_COORD_IDLE=0,STOP_COORD_ACTIVE=4,}  */

    typedef enum SPCR_Md_enum_t {
      STOP_COORD_IDLE=0,
      STOP_COORD_HOLD=1,
      STOP_COORD_GO=2,
      STOP_COORD_SLIP=3,
      STOP_COORD_ACTIVE=4,
      STOP_COORD_ACTIVE_HOLD=5,
      STOP_COORD_ACTIVE_GO=6,
      STOP_COORD_ACTIVE_SLIP=7,
      STOP_COORD_PASSIVE=8,
    } SPCR_Md_enum_t;

    typedef uint8 SPCR_Excpt_Rq_V2_t;  /* Stop coordinator exception request @min: 0 @max:3 @values: enum { AS_ENABLE=0,AS_DISABLE_ENG_HOOD_OPEN=2,AS_DISABLE_DRV_ABSENT=1,AS_DISABLE_DRV_ENG_HOOD=3,} */

    typedef enum SPCR_Excpt_Rq_V2_enum_t {
      AS_ENABLE=0,
      AS_DISABLE_DRV_ABSENT=1,
      AS_DISABLE_ENG_HOOD_OPEN=2,
      AS_DISABLE_DRV_ENG_HOOD=3,
    } SPCR_Excpt_Rq_V2_enum_t;

    typedef uint8 SPCR_AS_Off_Rq_t;  /* Stop Coordinator Assistance system off request @min: 0 @max:3 @values: enum { STOP_COORD_SYS_OFF_IDLE=0,STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,STOP_COORD_SYS_OFF_AS_CONT_OFF=2,STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,}  */

    typedef enum SPCR_AS_Off_Rq_enum_t {
      STOP_COORD_SYS_OFF_IDLE=0,
      STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,
      STOP_COORD_SYS_OFF_AS_CONT_OFF=2,
      STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,
    } SPCR_AS_Off_Rq_enum_t;

    typedef uint8 SPCR_AS_Dsabl_t;  /* Stop Coordinator disable assistance system (temperatur) @min: 0 @max:2 @values: enum { STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,STOP_COORD_SYS_DIS_IDLE=0,STOP_COORD_SYS_DIS_AS_DISABLE=2,}  */

    typedef enum SPCR_AS_Dsabl_enum_t {
      STOP_COORD_SYS_DIS_IDLE=0,
      STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,
      STOP_COORD_SYS_DIS_AS_DISABLE=2,
    } SPCR_AS_Dsabl_enum_t;

    typedef struct LongCtrlInputCustomSPCR_t 
    {
      SPCR_Md_t SPCR_Md;
      SPCR_Excpt_Rq_V2_t SPCR_Excpt_Rq_V2;
      SPCR_AS_Off_Rq_t SPCR_AS_Off_Rq;
      SPCR_AS_Dsabl_t SPCR_AS_Dsabl;
      boolean SPCR_Veh_Immo;
    } LongCtrlInputCustomSPCR_t;     /* Stop Coordinator fields */

    typedef uint8 VehAccel_X_LDC_VehSp_Rs_t; /* Longitudinal controller vehicle stop response @min: 0 @max:3 @values: enum { LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,LONG_VEH_STOP_RQ_IDLE=0,LONG_VEH_STOP_RQ_COMPLETE=2,LONG_VEH_STOP_RQ_ACTIVE=1,}  */

    typedef enum VehAccel_X_LDC_VehSp_Rs_enum_t {
      LONG_VEH_STOP_RQ_IDLE=0,
      LONG_VEH_STOP_RQ_ACTIVE=1,
      LONG_VEH_STOP_RQ_COMPLETE=2,
      LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,
    } VehAccel_X_LDC_VehSp_Rs_enum_t;

    typedef struct LongCtrlRs_t 
    {
      VehAccel_X_LDC_VehSp_Rs_t VehAccel_X_LDC_VehSp_Rs;
    } LongCtrlRs_t;			/* Custom Longitudinal Control Response (dynamic) */
#else
    typedef LongCtrlInputV6::Daimler::LongCtrlInputCustomSPCR_t LongCtrlInputCustomSPCR_t;
    typedef LongCtrlInputV6::Daimler::LongCtrlRs_t LongCtrlRs_t;
#endif

    typedef uint8 CustomSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:32 @values: enum { SPCR_EXCPT_RQ_ST=2,SPCR_MD_ST=1,SPCR_AS_OFF_RQ_ST=4,SPCR_AS_DSABL_ST=8,SPCR_VEH_IMMO_ST=16,VEH_ACCEL_X_LDC_VEH_SP_RS=32,}  */
  
    typedef enum CustomSignalState_enum_t {
      SPCR_MD_ST = 1,
      SPCR_EXCPT_RQ_ST = 2,
      SPCR_AS_OFF_RQ_ST = 4,
      SPCR_AS_DSABL_ST = 8,
      SPCR_VEH_IMMO_ST = 16,
      VEH_ACCEL_X_LDC_VEH_SP_RS = 32,
    } CustomSignalState_enum_t;
  
    typedef struct LongCtrlInputCustom_t
    {
      LongCtrlInputCustomSPCR_t SPCR;
      LongCtrlRs_t LongCtrlRs;
      CustomSignalState_t CustomSignalState;
    } LongCtrlInputCustom_t;  /* Customer specific fields */

    typedef uint16 KinCtrlSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:4096 @values: enum { DOOR_STATE=4096,ACC_ENABLE=1024,DRIVER_OVERRIDE_ACCEL_PEDAL=16,VAR_LIM_ENGAGE=4,STAND_STILL_DETECTED=8,LONG_INIT_ACCEL=1,DRIVER_BRAKING=64,DRIVER_OVERRIDE_BRAKE_PEDAL=32,DAS_ACCEL_REQ_LIM=128,PARK_BRK_ENGAGE=2048,PERM_LIM_SETSPEED=2,DAS_DECEL_REQ_LIM=256,LONG_SHUTOFF_ACQ=512,} */;

    typedef enum KinCtrlSignalState_enum_t {
      LONG_INIT_ACCEL = 1,
      PERM_LIM_SETSPEED = 2,
      VAR_LIM_ENGAGE = 4,
      STAND_STILL_DETECTED = 8,
      DRIVER_OVERRIDE_ACCEL_PEDAL = 16,
      DRIVER_OVERRIDE_BRAKE_PEDAL = 32,
      DRIVER_BRAKING = 64,
      DAS_ACCEL_REQ_LIM = 128,
      DAS_DECEL_REQ_LIM = 256,
      LONG_SHUTOFF_ACQ = 512,
      ACC_ENABLE = 1024,
      PARK_BRK_ENGAGE = 2048,
      DOOR_STATE = 4096,
    } KinCtrlSignalState_enum_t;

    typedef struct KinCtrlDynInput_t
    {
      signed short longi_initialization_accel;
      unsigned char perm_lim_setspeed;
      boolean var_lim_eng;
      boolean stand_still_detected;
      DC_status_information_t DC_status_information;
      boolean driver_override_accel_pedal;
      boolean driver_override_decel_pedal;
      boolean driver_braking;
      boolean DAS_accel_request_limited;
      boolean DAS_decel_request_limited;
      boolean longi_shutoff_acknowledged;
      ldm_ctrl_state_t ldm_ctrl_state;
      boolean acc_enable;
      boolean park_brk_eng;
      boolean brk_sw;
      door_state_t door_state;
      country_code_t country_code;
      KinCtrlSignalState_t KinCtrlSignalState;
    } KinCtrlDynInput_t;  /* Dynamic controller output used by the kinematic controller as input */


    typedef uint8 DisplayOutputSignalState_t; /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:2 @values: enum { SPEEDOMETER_SPEED=2,SPEED_UNIT=1,} */

    typedef enum DisplayOutputSignalState_enum_t {
      SPEED_UNIT = 1,
      SPEEDOMETER_SPEED = 2,
    } DisplayOutputSignalState_enum_t;

    typedef struct KinDisplayInput_t
    {
      SpeedUnitEnum_t speed_unit;
      unsigned char speedometer_speed;
      DisplayOutputSignalState_t DisplayOutputSignalState;
    } KinDisplayInput_t;  /* Output from display to the kinematic controller */

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */
  };  // End of namespace Daimler

};  // End of namespace LongCtrlInputV9

namespace LongCtrlInputV10
{
#if 0   // Reuse identical declarations
  typedef unsigned long AlgoDataTimeStamp_t;  /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */
  typedef unsigned short AlgoCycleCounter_t;  /* Algo cycle counter @min:0 @max:65535 */
  typedef unsigned char AlgoSignalState_t;    /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */

  typedef enum AlgoSignalState_enum_t {
    AL_SIG_STATE_INIT=0,
    AL_SIG_STATE_OK=1,
    AL_SIG_STATE_INVALID=2,
  } AlgoSignalState_enum_t;

  typedef struct SignalHeader_t
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;  /* Common header for all structured data types */

  typedef uint8 DC_status_information_t;   /* 0 = DC available, 1 = DC reversible not available, 2 = DC irreversible not available (for rest of ignition cycle) @min: 0 @max:2 @values: enum { DC_STATUS_AVAILABLE=0,DC_STATUS_NOT_AVAIL=2,DC_STATUS_TMP_NOT_AVAIL=1,} */

  typedef enum DC_status_info_enum_t {
    DC_STATUS_AVAILABLE=0,
    DC_STATUS_TMP_NOT_AVAIL=1,
    DC_STATUS_NOT_AVAIL=2,
  } DC_status_info_enum_t;

  typedef uint8 ldm_ctrl_state_t; /* LDM control state: indicates if ABS/TCS/ESP intervention active or control defective @min: 1 @max:32 @values: enum { LDM_CTRL_TCS_ACTIVE=2,LDM_CTRL_ESP_DEFECTIVE=32,LDM_CTRL_ABS_ACTIVE=1,LDM_CTRL_TCS_DEFECTIVE=16,LDM_CTRL_ABS_DEFECTIVE=8,LDM_CTRL_ESP_ACTIVE=4,} */

  typedef enum ldm_ctrl_state_enum_t {
    LDM_CTRL_ABS_ACTIVE=1,
    LDM_CTRL_TCS_ACTIVE=2,
    LDM_CTRL_ESP_ACTIVE=4,
    LDM_CTRL_ABS_DEFECTIVE=8,
    LDM_CTRL_TCS_DEFECTIVE=16,
    LDM_CTRL_ESP_DEFECTIVE=32,
  } ldm_ctrl_state_enum_t;

  typedef uint8 door_state_t; /* States of doors (bit field) @min: 1 @max:32 @values: enum { DOOR_TRUNK_OPEN=32,DOOR_FRONT_RIGHT_OPEN=2,DOOR_ENG_HOOD_OPEN=16,DOOR_REAR_LEFT_OPEN=4,DOOR_FRONT_LEFT_OPEN=1,DOOR_REAR_RIGHT_OPEN=8,} */

  typedef enum door_state_enum_t {
    DOOR_FRONT_LEFT_OPEN=1,
    DOOR_FRONT_RIGHT_OPEN=2,
    DOOR_REAR_LEFT_OPEN=4,
    DOOR_REAR_RIGHT_OPEN=8,
    DOOR_ENG_HOOD_OPEN=16,
    DOOR_TRUNK_OPEN=32,
  } door_state_enum_t;

  typedef uint8 SpeedUnitEnum_t;  /* Speed unit of spedometer @min: 0 @max:1 @values: enum { SPD_UNIT_KMH=0,SPD_UNIT_MPH=1,} */

  typedef enum SpeedUnitEnum_enum_t {
    SPD_UNIT_KMH=0,
    SPD_UNIT_MPH=1,
  } SpeedUnitEnum_enum_t;

  typedef uint8 country_code_t;  /* Country coding information @min: 0 @max:3 @values: enum { COUNTRY_REST_WORLD=0,COUNTRY_CANADA=3,COUNTRY_USA=1,COUNTRY_JAPAN=2,} */;

  typedef enum country_code_enum_t {
    COUNTRY_REST_WORLD = 0,
    COUNTRY_USA = 1,
    COUNTRY_JAPAN = 2,
    COUNTRY_CANADA = 3,
  } country_code_enum_t;

  typedef uint8 KinCtrlSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:4096 @values: enum { DOOR_STATE=4096,ACC_ENABLE=1024,DRIVER_OVERRIDE_ACCEL_PEDAL=16,VAR_LIM_ENGAGE=4,STAND_STILL_DETECTED=8,LONG_INIT_ACCEL=1,DRIVER_BRAKING=64,DRIVER_OVERRIDE_BRAKE_PEDAL=32,DAS_ACCEL_REQ_LIM=128,PARK_BRK_ENGAGE=2048,PERM_LIM_SETSPEED=2,DAS_DECEL_REQ_LIM=256,LONG_SHUTOFF_ACQ=512,} */;

  typedef enum KinCtrlSignalState_enum_t {
    LONG_INIT_ACCEL = 1,
    PERM_LIM_SETSPEED = 2,
    VAR_LIM_ENGAGE = 4,
    STAND_STILL_DETECTED = 8,
    DRIVER_OVERRIDE_ACCEL_PEDAL = 16,
    DRIVER_OVERRIDE_BRAKE_PEDAL = 32,
    DRIVER_BRAKING = 64,
    DAS_ACCEL_REQ_LIM = 128,
    DAS_DECEL_REQ_LIM = 256,
    LONG_SHUTOFF_ACQ = 512,
    ACC_ENABLE = 1024,
    PARK_BRK_ENGAGE = 2048,
    DOOR_STATE = 4096,
  } KinCtrlSignalState_enum_t;

  typedef struct KinCtrlDynInput_t
  {
    signed short longi_initialization_accel;
    unsigned char perm_lim_setspeed;
    boolean var_lim_eng;
    boolean stand_still_detected;
    DC_status_information_t DC_status_information;
    boolean driver_override_accel_pedal;
    boolean driver_override_decel_pedal;
    boolean driver_braking;
    boolean DAS_accel_request_limited;
    boolean DAS_decel_request_limited;
    boolean longi_shutoff_acknowledged;
    ldm_ctrl_state_t ldm_ctrl_state;
    boolean acc_enable;
    boolean park_brk_eng;
    boolean brk_sw;
    door_state_t door_state;
    country_code_t country_code;
    KinCtrlSignalState_t KinCtrlSignalState;
  } KinCtrlDynInput_t;  /* Dynamic controller output used by the kinematic controller as input */


  typedef uint8 DisplayOutputSignalState_t; /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:2 @values: enum { SPEEDOMETER_SPEED=2,SPEED_UNIT=1,} */

  typedef enum DisplayOutputSignalState_enum_t {
    SPEED_UNIT = 1,
    SPEEDOMETER_SPEED = 2,
  } DisplayOutputSignalState_enum_t;
#else
  typedef LongCtrlInputV5::SpeedUnitEnum_t SpeedUnitEnum_t;
  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;
#endif

  typedef struct LongCtrlInputBase_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    //KinCtrlDynInput_t KinCtrlDynInput;
    //KinDisplayInput_t DisplayOutput;
  } LongCtrlInputBase_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  namespace Toyota
  {
#if 0
    typedef signed short acceleration_t; /* Integer acceleration type @min:-32.767 @max:32.767 @resolution:0.001 */

    typedef unsigned char SPDSTAT_t;  /* Control Status at cruise lever operation by driver. @min: 0 @max:10 @values: enum { SPDSTAT_UNDER_DECEL_RQ_ACC=10,SPDSTAT_UNDER_CC_RESUME_CTRL=2,SPDSTAT_UNDER_CC_ACCEL_CTRL=3,SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,SPDSTAT_ACC_IDLE=8,SPDSTAT_UNDER_STOP_HOLD_ACC=7,SPDSTAT_NO_STATUS=0,SPDSTAT_UNDER_ACCEL_RQ_ACC=9,SPDSTAT_CC_IDLE=1,SPDSTAT_UNDER_CC_CORST_CTRL=4,SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,} */

    typedef enum SPDSTAT_enum_t{
      SPDSTAT_NO_STATUS=0,
      SPDSTAT_CC_IDLE=1,
      SPDSTAT_UNDER_CC_RESUME_CTRL=2,
      SPDSTAT_UNDER_CC_ACCEL_CTRL=3,
      SPDSTAT_UNDER_CC_CORST_CTRL=4,
      SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,
      SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,
      SPDSTAT_UNDER_STOP_HOLD_ACC=7,
      SPDSTAT_ACC_IDLE=8,
      SPDSTAT_UNDER_ACCEL_RQ_ACC=9,
      SPDSTAT_UNDER_DECEL_RQ_ACC=10,
  } SPDSTAT_enum_t;

    typedef unsigned char ACCSTAT_t;  /* Output control status @min: 0 @max:3 @values: enum { ACCSTAT_ACTIVE_OR_OVERRIDE=1,ACCSTAT_PB_RQ=3,ACCSTAT_DISENGAGE_OR_OFF=0,} */

    typedef enum ACC_STAT_enum_t {
      ACCSTAT_DISENGAGE_OR_OFF=0,
      ACCSTAT_ACTIVE_OR_OVERRIDE=1,
      ACCSTAT_PB_RQ=3,
    } ACC_STAT_enum_t;

    typedef unsigned char SLTACC_t;   /* ACC type @min: 0 @max:3 @values: enum { SLTACC_ACC_TYPE_FSRA=1,SLTACC_ACC_TYPE_CC=3,SLTACC_ACC_TYPE_RESERVE=0,SLTACC_ACC_TYPE_ACC=2,} */

    typedef enum SLTACC_enum_t {
      SLTACC_ACC_TYPE_RESERVE=0,
      SLTACC_ACC_TYPE_FSRA=1,
      SLTACC_ACC_TYPE_ACC=2,
      SLTACC_ACC_TYPE_CC=3,
    } SLTACC_enum_t;

    typedef unsigned char LTME2_t;    /* Vehicle following time @min: 0 @max:3 @values: enum { LTME2_VEH_FOLLOW_TIME_MIDDLE=2,LTME2_VEH_FOLLOW_TIME_SHORT=3,LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,LTME2_VEH_FOLLOW_TIME_LONG=1,} */

    typedef enum LTME2_enum_t {
      LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,
      LTME2_VEH_FOLLOW_TIME_LONG=1,
      LTME2_VEH_FOLLOW_TIME_MIDDLE=2,
      LTME2_VEH_FOLLOW_TIME_SHORT=3,
    } LTME2_enum_t;

    typedef struct EngineEcuInput_t
    {
      boolean XLDR;
      boolean XACCACT;
      boolean STPBZ;
      acceleration_t ACCREQ;
      SPDSTAT_t SPDSTAT;
      ACCSTAT_t ACCSTAT;
      unsigned char LCCHK;
      unsigned char VM;
      boolean XCCOK2;
      SLTACC_t SLTACC;
      LTME2_t LTME2;
      acceleration_t INTG;
    } EngineEcuInput_t; /* Input from TMC engine ECU (manages state machine, driver inputs etc.) */

    typedef struct LongCtrlInputCustom_t
    {
      EngineEcuInput_t EngineEcuInput;
    } LongCtrlInputCustom_t;  /* Customer specific fields */
#else
    typedef LongCtrlInputV9::Toyota::LongCtrlInputCustom_t LongCtrlInputCustom_t;
#endif
    typedef struct KinDisplayInput_t
    {
      SpeedUnitEnum_t speed_unit;
      unsigned __int16 speedometer_speed;
    } KinDisplayInput_t;  /* Output from display to the kinematic controller */

    typedef LongCtrlInputV9::Toyota::KinCtrlDynInput_t KinCtrlDynInput_t;

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  };  // End of namespace Toyota

  namespace Daimler
  {
#if 0   // Reuse identical declarations
    typedef uint8 SPCR_Md_t;  /* Stop coordinator state (Signal SPCR_Md) @min: 0 @max:8 @values: enum { STOP_COORD_ACTIVE_SLIP=7,STOP_COORD_ACTIVE_GO=6,STOP_COORD_HOLD=1,STOP_COORD_ACTIVE_HOLD=5,STOP_COORD_GO=2,STOP_COORD_PASSIVE=8,STOP_COORD_SLIP=3,STOP_COORD_IDLE=0,STOP_COORD_ACTIVE=4,}  */

    typedef enum SPCR_Md_enum_t {
      STOP_COORD_IDLE=0,
      STOP_COORD_HOLD=1,
      STOP_COORD_GO=2,
      STOP_COORD_SLIP=3,
      STOP_COORD_ACTIVE=4,
      STOP_COORD_ACTIVE_HOLD=5,
      STOP_COORD_ACTIVE_GO=6,
      STOP_COORD_ACTIVE_SLIP=7,
      STOP_COORD_PASSIVE=8,
    } SPCR_Md_enum_t;

    typedef uint8 SPCR_Excpt_Rq_V2_t;  /* Stop coordinator exception request @min: 0 @max:3 @values: enum { AS_ENABLE=0,AS_DISABLE_ENG_HOOD_OPEN=2,AS_DISABLE_DRV_ABSENT=1,AS_DISABLE_DRV_ENG_HOOD=3,} */

    typedef enum SPCR_Excpt_Rq_V2_enum_t {
      AS_ENABLE=0,
      AS_DISABLE_DRV_ABSENT=1,
      AS_DISABLE_ENG_HOOD_OPEN=2,
      AS_DISABLE_DRV_ENG_HOOD=3,
    } SPCR_Excpt_Rq_V2_enum_t;

    typedef uint8 SPCR_AS_Off_Rq_t;  /* Stop Coordinator Assistance system off request @min: 0 @max:3 @values: enum { STOP_COORD_SYS_OFF_IDLE=0,STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,STOP_COORD_SYS_OFF_AS_CONT_OFF=2,STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,}  */

    typedef enum SPCR_AS_Off_Rq_enum_t {
      STOP_COORD_SYS_OFF_IDLE=0,
      STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,
      STOP_COORD_SYS_OFF_AS_CONT_OFF=2,
      STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,
    } SPCR_AS_Off_Rq_enum_t;

    typedef uint8 SPCR_AS_Dsabl_t;  /* Stop Coordinator disable assistance system (temperatur) @min: 0 @max:2 @values: enum { STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,STOP_COORD_SYS_DIS_IDLE=0,STOP_COORD_SYS_DIS_AS_DISABLE=2,}  */

    typedef enum SPCR_AS_Dsabl_enum_t {
      STOP_COORD_SYS_DIS_IDLE=0,
      STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,
      STOP_COORD_SYS_DIS_AS_DISABLE=2,
    } SPCR_AS_Dsabl_enum_t;

    typedef struct LongCtrlInputCustomSPCR_t 
    {
      SPCR_Md_t SPCR_Md;
      SPCR_Excpt_Rq_V2_t SPCR_Excpt_Rq_V2;
      SPCR_AS_Off_Rq_t SPCR_AS_Off_Rq;
      SPCR_AS_Dsabl_t SPCR_AS_Dsabl;
      boolean SPCR_Veh_Immo;
    } LongCtrlInputCustomSPCR_t;     /* Stop Coordinator fields */

    typedef uint8 VehAccel_X_LDC_VehSp_Rs_t; /* Longitudinal controller vehicle stop response @min: 0 @max:3 @values: enum { LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,LONG_VEH_STOP_RQ_IDLE=0,LONG_VEH_STOP_RQ_COMPLETE=2,LONG_VEH_STOP_RQ_ACTIVE=1,}  */

    typedef enum VehAccel_X_LDC_VehSp_Rs_enum_t {
      LONG_VEH_STOP_RQ_IDLE=0,
      LONG_VEH_STOP_RQ_ACTIVE=1,
      LONG_VEH_STOP_RQ_COMPLETE=2,
      LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,
    } VehAccel_X_LDC_VehSp_Rs_enum_t;

    typedef struct LongCtrlRs_t 
    {
      VehAccel_X_LDC_VehSp_Rs_t VehAccel_X_LDC_VehSp_Rs;
    } LongCtrlRs_t;			/* Custom Longitudinal Control Response (dynamic) */

    typedef uint8 CustomSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:32 @values: enum { SPCR_EXCPT_RQ_ST=2,SPCR_MD_ST=1,SPCR_AS_OFF_RQ_ST=4,SPCR_AS_DSABL_ST=8,SPCR_VEH_IMMO_ST=16,VEH_ACCEL_X_LDC_VEH_SP_RS=32,}  */
  
    typedef enum CustomSignalState_enum_t {
      SPCR_MD_ST = 1,
      SPCR_EXCPT_RQ_ST = 2,
      SPCR_AS_OFF_RQ_ST = 4,
      SPCR_AS_DSABL_ST = 8,
      SPCR_VEH_IMMO_ST = 16,
      VEH_ACCEL_X_LDC_VEH_SP_RS = 32,
    } CustomSignalState_enum_t;
  
    typedef struct LongCtrlInputCustom_t
    {
      LongCtrlInputCustomSPCR_t SPCR;
      LongCtrlRs_t LongCtrlRs;
      CustomSignalState_t CustomSignalState;
    } LongCtrlInputCustom_t;  /* Customer specific fields */
#else
    typedef LongCtrlInputV9::Daimler::LongCtrlInputCustom_t LongCtrlInputCustom_t;
#endif
    typedef LongCtrlInputV9::Daimler::KinCtrlDynInput_t KinCtrlDynInput_t;
    typedef LongCtrlInputV9::SpeedUnitEnum_t SpeedUnitEnum_t;
    typedef LongCtrlInputV9::Daimler::DisplayOutputSignalState_t DisplayOutputSignalState_t;
    typedef LongCtrlInputV9::Daimler::KinCtrlDynInput_t KinCtrlDynInput_t;
    typedef struct KinDisplayInput_t
    {
      SpeedUnitEnum_t speed_unit;
      unsigned __int16 speedometer_speed;
      DisplayOutputSignalState_t DisplayOutputSignalState;
    } KinDisplayInput_t;  /* Output from display to the kinematic controller */

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  };  // End of namespace Daimler

};  // End of namespace LongCtrlInputV10

namespace LongCtrlInputV11
{
#if 0   // Reuse identical declarations
  typedef unsigned long AlgoDataTimeStamp_t;  /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */
  typedef unsigned short AlgoCycleCounter_t;  /* Algo cycle counter @min:0 @max:65535 */
  typedef unsigned char AlgoSignalState_t;    /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */

  typedef enum AlgoSignalState_enum_t {
    AL_SIG_STATE_INIT=0,
    AL_SIG_STATE_OK=1,
    AL_SIG_STATE_INVALID=2,
  } AlgoSignalState_enum_t;

  typedef struct SignalHeader_t
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;  /* Common header for all structured data types */

  typedef uint8 DC_status_information_t;   /* 0 = DC available, 1 = DC reversible not available, 2 = DC irreversible not available (for rest of ignition cycle) @min: 0 @max:2 @values: enum { DC_STATUS_AVAILABLE=0,DC_STATUS_NOT_AVAIL=2,DC_STATUS_TMP_NOT_AVAIL=1,} */

  typedef enum DC_status_info_enum_t {
    DC_STATUS_AVAILABLE=0,
    DC_STATUS_TMP_NOT_AVAIL=1,
    DC_STATUS_NOT_AVAIL=2,
  } DC_status_info_enum_t;

  typedef uint8 ldm_ctrl_state_t; /* LDM control state: indicates if ABS/TCS/ESP intervention active or control defective @min: 1 @max:32 @values: enum { LDM_CTRL_TCS_ACTIVE=2,LDM_CTRL_ESP_DEFECTIVE=32,LDM_CTRL_ABS_ACTIVE=1,LDM_CTRL_TCS_DEFECTIVE=16,LDM_CTRL_ABS_DEFECTIVE=8,LDM_CTRL_ESP_ACTIVE=4,} */

  typedef enum ldm_ctrl_state_enum_t {
    LDM_CTRL_ABS_ACTIVE=1,
    LDM_CTRL_TCS_ACTIVE=2,
    LDM_CTRL_ESP_ACTIVE=4,
    LDM_CTRL_ABS_DEFECTIVE=8,
    LDM_CTRL_TCS_DEFECTIVE=16,
    LDM_CTRL_ESP_DEFECTIVE=32,
  } ldm_ctrl_state_enum_t;

  typedef uint8 door_state_t; /* States of doors (bit field) @min: 1 @max:32 @values: enum { DOOR_TRUNK_OPEN=32,DOOR_FRONT_RIGHT_OPEN=2,DOOR_ENG_HOOD_OPEN=16,DOOR_REAR_LEFT_OPEN=4,DOOR_FRONT_LEFT_OPEN=1,DOOR_REAR_RIGHT_OPEN=8,} */

  typedef enum door_state_enum_t {
    DOOR_FRONT_LEFT_OPEN=1,
    DOOR_FRONT_RIGHT_OPEN=2,
    DOOR_REAR_LEFT_OPEN=4,
    DOOR_REAR_RIGHT_OPEN=8,
    DOOR_ENG_HOOD_OPEN=16,
    DOOR_TRUNK_OPEN=32,
  } door_state_enum_t;

  typedef uint8 SpeedUnitEnum_t;  /* Speed unit of spedometer @min: 0 @max:1 @values: enum { SPD_UNIT_KMH=0,SPD_UNIT_MPH=1,} */

  typedef enum SpeedUnitEnum_enum_t {
    SPD_UNIT_KMH=0,
    SPD_UNIT_MPH=1,
  } SpeedUnitEnum_enum_t;

  typedef uint8 country_code_t;  /* Country coding information @min: 0 @max:3 @values: enum { COUNTRY_REST_WORLD=0,COUNTRY_CANADA=3,COUNTRY_USA=1,COUNTRY_JAPAN=2,} */;

  typedef enum country_code_enum_t {
    COUNTRY_REST_WORLD = 0,
    COUNTRY_USA = 1,
    COUNTRY_JAPAN = 2,
    COUNTRY_CANADA = 3,
  } country_code_enum_t;

  typedef uint8 KinCtrlSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:4096 @values: enum { DOOR_STATE=4096,ACC_ENABLE=1024,DRIVER_OVERRIDE_ACCEL_PEDAL=16,VAR_LIM_ENGAGE=4,STAND_STILL_DETECTED=8,LONG_INIT_ACCEL=1,DRIVER_BRAKING=64,DRIVER_OVERRIDE_BRAKE_PEDAL=32,DAS_ACCEL_REQ_LIM=128,PARK_BRK_ENGAGE=2048,PERM_LIM_SETSPEED=2,DAS_DECEL_REQ_LIM=256,LONG_SHUTOFF_ACQ=512,} */;

  typedef enum KinCtrlSignalState_enum_t {
    LONG_INIT_ACCEL = 1,
    PERM_LIM_SETSPEED = 2,
    VAR_LIM_ENGAGE = 4,
    STAND_STILL_DETECTED = 8,
    DRIVER_OVERRIDE_ACCEL_PEDAL = 16,
    DRIVER_OVERRIDE_BRAKE_PEDAL = 32,
    DRIVER_BRAKING = 64,
    DAS_ACCEL_REQ_LIM = 128,
    DAS_DECEL_REQ_LIM = 256,
    LONG_SHUTOFF_ACQ = 512,
    ACC_ENABLE = 1024,
    PARK_BRK_ENGAGE = 2048,
    DOOR_STATE = 4096,
  } KinCtrlSignalState_enum_t;

  typedef struct KinCtrlDynInput_t
  {
    signed short longi_initialization_accel;
    unsigned char perm_lim_setspeed;
    boolean var_lim_eng;
    boolean stand_still_detected;
    DC_status_information_t DC_status_information;
    boolean driver_override_accel_pedal;
    boolean driver_override_decel_pedal;
    boolean driver_braking;
    boolean DAS_accel_request_limited;
    boolean DAS_decel_request_limited;
    boolean longi_shutoff_acknowledged;
    ldm_ctrl_state_t ldm_ctrl_state;
    boolean acc_enable;
    boolean park_brk_eng;
    boolean brk_sw;
    door_state_t door_state;
    country_code_t country_code;
    KinCtrlSignalState_t KinCtrlSignalState;
  } KinCtrlDynInput_t;  /* Dynamic controller output used by the kinematic controller as input */


  typedef uint8 DisplayOutputSignalState_t; /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:2 @values: enum { SPEEDOMETER_SPEED=2,SPEED_UNIT=1,} */

  typedef enum DisplayOutputSignalState_enum_t {
    SPEED_UNIT = 1,
    SPEEDOMETER_SPEED = 2,
  } DisplayOutputSignalState_enum_t;
#else
  typedef LongCtrlInputV5::SpeedUnitEnum_t SpeedUnitEnum_t;
  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;
#endif

  typedef struct LongCtrlInputBase_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    //KinCtrlDynInput_t KinCtrlDynInput;
    //KinDisplayInput_t DisplayOutput;
  } LongCtrlInputBase_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  namespace Toyota
  {
    typedef signed short acceleration_t; /* Integer acceleration type @min:-32.767 @max:32.767 @resolution:0.001 */

    typedef unsigned char SPDSTAT_t;  /* Control Status at cruise lever operation by driver. @min: 0 @max:10 @values: enum { SPDSTAT_UNDER_DECEL_RQ_ACC=10,SPDSTAT_UNDER_CC_RESUME_CTRL=2,SPDSTAT_UNDER_CC_ACCEL_CTRL=3,SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,SPDSTAT_ACC_IDLE=8,SPDSTAT_UNDER_STOP_HOLD_ACC=7,SPDSTAT_NO_STATUS=0,SPDSTAT_UNDER_ACCEL_RQ_ACC=9,SPDSTAT_CC_IDLE=1,SPDSTAT_UNDER_CC_CORST_CTRL=4,SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,} */
    typedef unsigned char Ext_AccState_t;
    typedef unsigned char Ext_AccMode_t;
    typedef unsigned char Ext_HeadwaySetting_t;
    typedef unsigned char Ext_AccInhibitionRq_In_t;

    typedef enum SPDSTAT_enum_t{
      SPDSTAT_NO_STATUS=0,
      SPDSTAT_CC_IDLE=1,
      SPDSTAT_UNDER_CC_RESUME_CTRL=2,
      SPDSTAT_UNDER_CC_ACCEL_CTRL=3,
      SPDSTAT_UNDER_CC_CORST_CTRL=4,
      SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,
      SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,
      SPDSTAT_UNDER_STOP_HOLD_ACC=7,
      SPDSTAT_ACC_IDLE=8,
      SPDSTAT_UNDER_ACCEL_RQ_ACC=9,
      SPDSTAT_UNDER_DECEL_RQ_ACC=10,
  } SPDSTAT_enum_t;

    typedef unsigned char ACCSTAT_t;  /* Output control status @min: 0 @max:3 @values: enum { ACCSTAT_ACTIVE_OR_OVERRIDE=1,ACCSTAT_PB_RQ=3,ACCSTAT_DISENGAGE_OR_OFF=0,} */

    typedef enum ACC_STAT_enum_t {
      ACCSTAT_DISENGAGE_OR_OFF=0,
      ACCSTAT_ACTIVE_OR_OVERRIDE=1,
      ACCSTAT_PB_RQ=3,
    } ACC_STAT_enum_t;

    typedef unsigned char SLTACC_t;   /* ACC type @min: 0 @max:3 @values: enum { SLTACC_ACC_TYPE_FSRA=1,SLTACC_ACC_TYPE_CC=3,SLTACC_ACC_TYPE_RESERVE=0,SLTACC_ACC_TYPE_ACC=2,} */

    typedef enum SLTACC_enum_t {
      SLTACC_ACC_TYPE_RESERVE=0,
      SLTACC_ACC_TYPE_FSRA=1,
      SLTACC_ACC_TYPE_ACC=2,
      SLTACC_ACC_TYPE_CC=3,
    } SLTACC_enum_t;

    typedef unsigned char LTME2_t;    /* Vehicle following time @min: 0 @max:3 @values: enum { LTME2_VEH_FOLLOW_TIME_MIDDLE=2,LTME2_VEH_FOLLOW_TIME_SHORT=3,LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,LTME2_VEH_FOLLOW_TIME_LONG=1,} */

    typedef enum LTME2_enum_t {
      LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,
      LTME2_VEH_FOLLOW_TIME_LONG=1,
      LTME2_VEH_FOLLOW_TIME_MIDDLE=2,
      LTME2_VEH_FOLLOW_TIME_SHORT=3,
    } LTME2_enum_t;

    typedef struct EngineEcuInput_t
    {
      boolean XLDR;
      boolean XACCACT;
      boolean STPBZ;
      acceleration_t ACCREQ;
      SPDSTAT_t SPDSTAT;
      ACCSTAT_t ACCSTAT;
      unsigned char LCCHK;
      unsigned char VM;
      boolean XCCOK2;
      SLTACC_t SLTACC;
      LTME2_t LTME2;
      acceleration_t INTG;
      Ext_AccState_t Ext_AccState;
      Ext_AccMode_t Ext_AccMode;
      Ext_HeadwaySetting_t Ext_HeadwaySetting;
      unsigned char Ext_SetSpeed;
      Ext_AccInhibitionRq_In_t Ext_AccInhibitionRq_In;
    } EngineEcuInput_t; /* Input from TMC engine ECU (manages state machine, driver inputs etc.) */

    typedef struct LongCtrlInputCustom_t
    {
      EngineEcuInput_t EngineEcuInput;
    } LongCtrlInputCustom_t;  /* Customer specific fields */

    typedef struct KinDisplayInput_t
    {
      SpeedUnitEnum_t speed_unit;
      unsigned __int16 speedometer_speed;
    } KinDisplayInput_t;  /* Output from display to the kinematic controller */

    typedef LongCtrlInputV10::Toyota::KinCtrlDynInput_t KinCtrlDynInput_t;

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  };  // End of namespace Toyota
  
  namespace Toyota_2
  {
    typedef LongCtrlInputV11::Toyota::acceleration_t acceleration_t;
    typedef LongCtrlInputV11::Toyota::SPDSTAT_t SPDSTAT_t;
    typedef LongCtrlInputV11::Toyota::ACCSTAT_t ACCSTAT_t;
    typedef LongCtrlInputV11::Toyota::SLTACC_t SLTACC_t;
    typedef LongCtrlInputV11::Toyota::LTME2_t LTME2_t;
    typedef LongCtrlInputV10::Toyota::KinCtrlDynInput_t KinCtrlDynInput_t;
    typedef LongCtrlInputV11::Toyota::KinDisplayInput_t KinDisplayInput_t;

    typedef struct EngineEcuInput_t
    {      
      boolean XLDR;
      boolean XACCACT;
      boolean STPBZ;
      boolean LCCW2;
      acceleration_t ACCREQ;
      SPDSTAT_t SPDSTAT;
      ACCSTAT_t ACCSTAT;
      unsigned char LCCHK;
      unsigned short VM;
      boolean XCCOK2;
      SLTACC_t SLTACC;
      LTME2_t LTME2;
      acceleration_t INTG;
    } EngineEcuInput_t;

    typedef struct LongCtrlInputCustom_t
    {
      EngineEcuInput_t EngineEcuInput;
    } LongCtrlInputCustom_t;

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  };  // End of namespace Toyota_2

  namespace Daimler
  {
#if 0   // Reuse identical declarations
    typedef uint8 SPCR_Md_t;  /* Stop coordinator state (Signal SPCR_Md) @min: 0 @max:8 @values: enum { STOP_COORD_ACTIVE_SLIP=7,STOP_COORD_ACTIVE_GO=6,STOP_COORD_HOLD=1,STOP_COORD_ACTIVE_HOLD=5,STOP_COORD_GO=2,STOP_COORD_PASSIVE=8,STOP_COORD_SLIP=3,STOP_COORD_IDLE=0,STOP_COORD_ACTIVE=4,}  */

    typedef enum SPCR_Md_enum_t {
      STOP_COORD_IDLE=0,
      STOP_COORD_HOLD=1,
      STOP_COORD_GO=2,
      STOP_COORD_SLIP=3,
      STOP_COORD_ACTIVE=4,
      STOP_COORD_ACTIVE_HOLD=5,
      STOP_COORD_ACTIVE_GO=6,
      STOP_COORD_ACTIVE_SLIP=7,
      STOP_COORD_PASSIVE=8,
    } SPCR_Md_enum_t;

    typedef uint8 SPCR_Excpt_Rq_V2_t;  /* Stop coordinator exception request @min: 0 @max:3 @values: enum { AS_ENABLE=0,AS_DISABLE_ENG_HOOD_OPEN=2,AS_DISABLE_DRV_ABSENT=1,AS_DISABLE_DRV_ENG_HOOD=3,} */

    typedef enum SPCR_Excpt_Rq_V2_enum_t {
      AS_ENABLE=0,
      AS_DISABLE_DRV_ABSENT=1,
      AS_DISABLE_ENG_HOOD_OPEN=2,
      AS_DISABLE_DRV_ENG_HOOD=3,
    } SPCR_Excpt_Rq_V2_enum_t;

    typedef uint8 SPCR_AS_Off_Rq_t;  /* Stop Coordinator Assistance system off request @min: 0 @max:3 @values: enum { STOP_COORD_SYS_OFF_IDLE=0,STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,STOP_COORD_SYS_OFF_AS_CONT_OFF=2,STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,}  */

    typedef enum SPCR_AS_Off_Rq_enum_t {
      STOP_COORD_SYS_OFF_IDLE=0,
      STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,
      STOP_COORD_SYS_OFF_AS_CONT_OFF=2,
      STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,
    } SPCR_AS_Off_Rq_enum_t;

    typedef uint8 SPCR_AS_Dsabl_t;  /* Stop Coordinator disable assistance system (temperatur) @min: 0 @max:2 @values: enum { STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,STOP_COORD_SYS_DIS_IDLE=0,STOP_COORD_SYS_DIS_AS_DISABLE=2,}  */

    typedef enum SPCR_AS_Dsabl_enum_t {
      STOP_COORD_SYS_DIS_IDLE=0,
      STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,
      STOP_COORD_SYS_DIS_AS_DISABLE=2,
    } SPCR_AS_Dsabl_enum_t;

    typedef struct LongCtrlInputCustomSPCR_t 
    {
      SPCR_Md_t SPCR_Md;
      SPCR_Excpt_Rq_V2_t SPCR_Excpt_Rq_V2;
      SPCR_AS_Off_Rq_t SPCR_AS_Off_Rq;
      SPCR_AS_Dsabl_t SPCR_AS_Dsabl;
      boolean SPCR_Veh_Immo;
    } LongCtrlInputCustomSPCR_t;     /* Stop Coordinator fields */

    typedef uint8 VehAccel_X_LDC_VehSp_Rs_t; /* Longitudinal controller vehicle stop response @min: 0 @max:3 @values: enum { LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,LONG_VEH_STOP_RQ_IDLE=0,LONG_VEH_STOP_RQ_COMPLETE=2,LONG_VEH_STOP_RQ_ACTIVE=1,}  */

    typedef enum VehAccel_X_LDC_VehSp_Rs_enum_t {
      LONG_VEH_STOP_RQ_IDLE=0,
      LONG_VEH_STOP_RQ_ACTIVE=1,
      LONG_VEH_STOP_RQ_COMPLETE=2,
      LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,
    } VehAccel_X_LDC_VehSp_Rs_enum_t;

    typedef struct LongCtrlRs_t 
    {
      VehAccel_X_LDC_VehSp_Rs_t VehAccel_X_LDC_VehSp_Rs;
    } LongCtrlRs_t;			/* Custom Longitudinal Control Response (dynamic) */

    typedef uint8 CustomSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:32 @values: enum { SPCR_EXCPT_RQ_ST=2,SPCR_MD_ST=1,SPCR_AS_OFF_RQ_ST=4,SPCR_AS_DSABL_ST=8,SPCR_VEH_IMMO_ST=16,VEH_ACCEL_X_LDC_VEH_SP_RS=32,}  */
  
    typedef enum CustomSignalState_enum_t {
      SPCR_MD_ST = 1,
      SPCR_EXCPT_RQ_ST = 2,
      SPCR_AS_OFF_RQ_ST = 4,
      SPCR_AS_DSABL_ST = 8,
      SPCR_VEH_IMMO_ST = 16,
      VEH_ACCEL_X_LDC_VEH_SP_RS = 32,
    } CustomSignalState_enum_t;
  
    typedef struct LongCtrlInputCustom_t
    {
      LongCtrlInputCustomSPCR_t SPCR;
      LongCtrlRs_t LongCtrlRs;
      CustomSignalState_t CustomSignalState;
    } LongCtrlInputCustom_t;  /* Customer specific fields */
#else
    typedef LongCtrlInputV10::Daimler::LongCtrlInputCustom_t LongCtrlInputCustom_t;
#endif 
    typedef LongCtrlInputV10::Daimler::KinCtrlDynInput_t KinCtrlDynInput_t;
    typedef LongCtrlInputV10::SpeedUnitEnum_t SpeedUnitEnum_t;
    typedef LongCtrlInputV10::Daimler::DisplayOutputSignalState_t DisplayOutputSignalState_t;
    typedef LongCtrlInputV10::Daimler::KinCtrlDynInput_t KinCtrlDynInput_t;
    typedef struct KinDisplayInput_t
    {
      SpeedUnitEnum_t speed_unit;
      unsigned __int16 speedometer_speed;
      DisplayOutputSignalState_t DisplayOutputSignalState;
    } KinDisplayInput_t;  /* Output from display to the kinematic controller */

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  };  // End of namespace Daimler

};  // End of namespace LongCtrlInputV11

namespace LongCtrlInputV12
{
#if 0   // Reuse identical declarations
  typedef unsigned long AlgoDataTimeStamp_t;  /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */
  typedef unsigned short AlgoCycleCounter_t;  /* Algo cycle counter @min:0 @max:65535 */
  typedef unsigned char AlgoSignalState_t;    /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */

  typedef enum AlgoSignalState_enum_t {
    AL_SIG_STATE_INIT=0,
    AL_SIG_STATE_OK=1,
    AL_SIG_STATE_INVALID=2,
  } AlgoSignalState_enum_t;

  typedef struct SignalHeader_t
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;  /* Common header for all structured data types */

  typedef uint8 DC_status_information_t;   /* 0 = DC available, 1 = DC reversible not available, 2 = DC irreversible not available (for rest of ignition cycle) @min: 0 @max:2 @values: enum { DC_STATUS_AVAILABLE=0,DC_STATUS_NOT_AVAIL=2,DC_STATUS_TMP_NOT_AVAIL=1,} */

  typedef enum DC_status_info_enum_t {
    DC_STATUS_AVAILABLE=0,
    DC_STATUS_TMP_NOT_AVAIL=1,
    DC_STATUS_NOT_AVAIL=2,
  } DC_status_info_enum_t;

  typedef uint8 ldm_ctrl_state_t; /* LDM control state: indicates if ABS/TCS/ESP intervention active or control defective @min: 1 @max:32 @values: enum { LDM_CTRL_TCS_ACTIVE=2,LDM_CTRL_ESP_DEFECTIVE=32,LDM_CTRL_ABS_ACTIVE=1,LDM_CTRL_TCS_DEFECTIVE=16,LDM_CTRL_ABS_DEFECTIVE=8,LDM_CTRL_ESP_ACTIVE=4,} */

  typedef enum ldm_ctrl_state_enum_t {
    LDM_CTRL_ABS_ACTIVE=1,
    LDM_CTRL_TCS_ACTIVE=2,
    LDM_CTRL_ESP_ACTIVE=4,
    LDM_CTRL_ABS_DEFECTIVE=8,
    LDM_CTRL_TCS_DEFECTIVE=16,
    LDM_CTRL_ESP_DEFECTIVE=32,
  } ldm_ctrl_state_enum_t;

  typedef uint8 door_state_t; /* States of doors (bit field) @min: 1 @max:32 @values: enum { DOOR_TRUNK_OPEN=32,DOOR_FRONT_RIGHT_OPEN=2,DOOR_ENG_HOOD_OPEN=16,DOOR_REAR_LEFT_OPEN=4,DOOR_FRONT_LEFT_OPEN=1,DOOR_REAR_RIGHT_OPEN=8,} */

  typedef enum door_state_enum_t {
    DOOR_FRONT_LEFT_OPEN=1,
    DOOR_FRONT_RIGHT_OPEN=2,
    DOOR_REAR_LEFT_OPEN=4,
    DOOR_REAR_RIGHT_OPEN=8,
    DOOR_ENG_HOOD_OPEN=16,
    DOOR_TRUNK_OPEN=32,
  } door_state_enum_t;

  typedef uint8 SpeedUnitEnum_t;  /* Speed unit of spedometer @min: 0 @max:1 @values: enum { SPD_UNIT_KMH=0,SPD_UNIT_MPH=1,} */

  typedef enum SpeedUnitEnum_enum_t {
    SPD_UNIT_KMH=0,
    SPD_UNIT_MPH=1,
  } SpeedUnitEnum_enum_t;

  typedef uint8 country_code_t;  /* Country coding information @min: 0 @max:3 @values: enum { COUNTRY_REST_WORLD=0,COUNTRY_CANADA=3,COUNTRY_USA=1,COUNTRY_JAPAN=2,} */;

  typedef enum country_code_enum_t {
    COUNTRY_REST_WORLD = 0,
    COUNTRY_USA = 1,
    COUNTRY_JAPAN = 2,
    COUNTRY_CANADA = 3,
  } country_code_enum_t;

  typedef uint8 KinCtrlSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:4096 @values: enum { DOOR_STATE=4096,ACC_ENABLE=1024,DRIVER_OVERRIDE_ACCEL_PEDAL=16,VAR_LIM_ENGAGE=4,STAND_STILL_DETECTED=8,LONG_INIT_ACCEL=1,DRIVER_BRAKING=64,DRIVER_OVERRIDE_BRAKE_PEDAL=32,DAS_ACCEL_REQ_LIM=128,PARK_BRK_ENGAGE=2048,PERM_LIM_SETSPEED=2,DAS_DECEL_REQ_LIM=256,LONG_SHUTOFF_ACQ=512,} */;

  typedef enum KinCtrlSignalState_enum_t {
    LONG_INIT_ACCEL = 1,
    PERM_LIM_SETSPEED = 2,
    VAR_LIM_ENGAGE = 4,
    STAND_STILL_DETECTED = 8,
    DRIVER_OVERRIDE_ACCEL_PEDAL = 16,
    DRIVER_OVERRIDE_BRAKE_PEDAL = 32,
    DRIVER_BRAKING = 64,
    DAS_ACCEL_REQ_LIM = 128,
    DAS_DECEL_REQ_LIM = 256,
    LONG_SHUTOFF_ACQ = 512,
    ACC_ENABLE = 1024,
    PARK_BRK_ENGAGE = 2048,
    DOOR_STATE = 4096,
  } KinCtrlSignalState_enum_t;

  typedef struct KinCtrlDynInput_t
  {
    signed short longi_initialization_accel;
    unsigned char perm_lim_setspeed;
    boolean var_lim_eng;
    boolean stand_still_detected;
    DC_status_information_t DC_status_information;
    boolean driver_override_accel_pedal;
    boolean driver_override_decel_pedal;
    boolean driver_braking;
    boolean DAS_accel_request_limited;
    boolean DAS_decel_request_limited;
    boolean longi_shutoff_acknowledged;
    ldm_ctrl_state_t ldm_ctrl_state;
    boolean acc_enable;
    boolean park_brk_eng;
    boolean brk_sw;
    door_state_t door_state;
    country_code_t country_code;
    KinCtrlSignalState_t KinCtrlSignalState;
  } KinCtrlDynInput_t;  /* Dynamic controller output used by the kinematic controller as input */


  typedef uint8 DisplayOutputSignalState_t; /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:2 @values: enum { SPEEDOMETER_SPEED=2,SPEED_UNIT=1,} */

  typedef enum DisplayOutputSignalState_enum_t {
    SPEED_UNIT = 1,
    SPEEDOMETER_SPEED = 2,
  } DisplayOutputSignalState_enum_t;
#else
  typedef LongCtrlInputV5::SpeedUnitEnum_t SpeedUnitEnum_t;
  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;
#endif

  typedef struct LongCtrlInputBase_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    //KinCtrlDynInput_t KinCtrlDynInput;
    //KinDisplayInput_t DisplayOutput;
  } LongCtrlInputBase_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  namespace Toyota
  {
    typedef signed short acceleration_t; /* Integer acceleration type @min:-32.767 @max:32.767 @resolution:0.001 */

    typedef unsigned char SPDSTAT_t;  /* Control Status at cruise lever operation by driver. @min: 0 @max:10 @values: enum { SPDSTAT_UNDER_DECEL_RQ_ACC=10,SPDSTAT_UNDER_CC_RESUME_CTRL=2,SPDSTAT_UNDER_CC_ACCEL_CTRL=3,SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,SPDSTAT_ACC_IDLE=8,SPDSTAT_UNDER_STOP_HOLD_ACC=7,SPDSTAT_NO_STATUS=0,SPDSTAT_UNDER_ACCEL_RQ_ACC=9,SPDSTAT_CC_IDLE=1,SPDSTAT_UNDER_CC_CORST_CTRL=4,SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,} */
    typedef unsigned char Ext_AccState_t;
    typedef unsigned char Ext_AccMode_t;
    typedef unsigned char Ext_HeadwaySetting_t;
    typedef unsigned char Ext_AccInhibitionRq_In_t;

    typedef enum SPDSTAT_enum_t{
      SPDSTAT_NO_STATUS=0,
      SPDSTAT_CC_IDLE=1,
      SPDSTAT_UNDER_CC_RESUME_CTRL=2,
      SPDSTAT_UNDER_CC_ACCEL_CTRL=3,
      SPDSTAT_UNDER_CC_CORST_CTRL=4,
      SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,
      SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,
      SPDSTAT_UNDER_STOP_HOLD_ACC=7,
      SPDSTAT_ACC_IDLE=8,
      SPDSTAT_UNDER_ACCEL_RQ_ACC=9,
      SPDSTAT_UNDER_DECEL_RQ_ACC=10,
  } SPDSTAT_enum_t;

    typedef unsigned char ACCSTAT_t;  /* Output control status @min: 0 @max:3 @values: enum { ACCSTAT_ACTIVE_OR_OVERRIDE=1,ACCSTAT_PB_RQ=3,ACCSTAT_DISENGAGE_OR_OFF=0,} */

    typedef enum ACC_STAT_enum_t {
      ACCSTAT_DISENGAGE_OR_OFF=0,
      ACCSTAT_ACTIVE_OR_OVERRIDE=1,
      ACCSTAT_PB_RQ=3,
    } ACC_STAT_enum_t;

    typedef unsigned char SLTACC_t;   /* ACC type @min: 0 @max:3 @values: enum { SLTACC_ACC_TYPE_FSRA=1,SLTACC_ACC_TYPE_CC=3,SLTACC_ACC_TYPE_RESERVE=0,SLTACC_ACC_TYPE_ACC=2,} */

    typedef enum SLTACC_enum_t {
      SLTACC_ACC_TYPE_RESERVE=0,
      SLTACC_ACC_TYPE_FSRA=1,
      SLTACC_ACC_TYPE_ACC=2,
      SLTACC_ACC_TYPE_CC=3,
    } SLTACC_enum_t;

    typedef unsigned char LTME2_t;    /* Vehicle following time @min: 0 @max:3 @values: enum { LTME2_VEH_FOLLOW_TIME_MIDDLE=2,LTME2_VEH_FOLLOW_TIME_SHORT=3,LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,LTME2_VEH_FOLLOW_TIME_LONG=1,} */

    typedef enum LTME2_enum_t {
      LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,
      LTME2_VEH_FOLLOW_TIME_LONG=1,
      LTME2_VEH_FOLLOW_TIME_MIDDLE=2,
      LTME2_VEH_FOLLOW_TIME_SHORT=3,
    } LTME2_enum_t;

    typedef struct EngineEcuInput_t
    {
      /*boolean XLDR;
      boolean XACCACT;
      boolean STPBZ;
      acceleration_t ACCREQ;
      SPDSTAT_t SPDSTAT;
      ACCSTAT_t ACCSTAT;
      unsigned char LCCHK;
      unsigned char VM;
      boolean XCCOK2;
      SLTACC_t SLTACC;
      LTME2_t LTME2;
      acceleration_t INTG;*/
      Ext_AccState_t Ext_AccState;
      Ext_AccMode_t Ext_AccMode;
      Ext_HeadwaySetting_t Ext_HeadwaySetting;
      unsigned char Ext_SetSpeed;
      Ext_AccInhibitionRq_In_t Ext_AccInhibitionRq_In;
      acceleration_t Ext_RequestedAccelAfterGradLim;
    } EngineEcuInput_t; /* Input from TMC engine ECU (manages state machine, driver inputs etc.) */

    typedef struct LongCtrlInputCustom_t
    {
      EngineEcuInput_t EngineEcuInput;
    } LongCtrlInputCustom_t;  /* Customer specific fields */

    typedef struct KinDisplayInput_t
    {
      SpeedUnitEnum_t speed_unit;
      unsigned __int16 speedometer_speed;
    } KinDisplayInput_t;  /* Output from display to the kinematic controller */

    typedef LongCtrlInputV11::Toyota::KinCtrlDynInput_t KinCtrlDynInput_t;

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  };  // End of namespace Toyota

  namespace Daimler
  {
#if 0   // Reuse identical declarations
    typedef uint8 SPCR_Md_t;  /* Stop coordinator state (Signal SPCR_Md) @min: 0 @max:8 @values: enum { STOP_COORD_ACTIVE_SLIP=7,STOP_COORD_ACTIVE_GO=6,STOP_COORD_HOLD=1,STOP_COORD_ACTIVE_HOLD=5,STOP_COORD_GO=2,STOP_COORD_PASSIVE=8,STOP_COORD_SLIP=3,STOP_COORD_IDLE=0,STOP_COORD_ACTIVE=4,}  */

    typedef enum SPCR_Md_enum_t {
      STOP_COORD_IDLE=0,
      STOP_COORD_HOLD=1,
      STOP_COORD_GO=2,
      STOP_COORD_SLIP=3,
      STOP_COORD_ACTIVE=4,
      STOP_COORD_ACTIVE_HOLD=5,
      STOP_COORD_ACTIVE_GO=6,
      STOP_COORD_ACTIVE_SLIP=7,
      STOP_COORD_PASSIVE=8,
    } SPCR_Md_enum_t;

    typedef uint8 SPCR_Excpt_Rq_V2_t;  /* Stop coordinator exception request @min: 0 @max:3 @values: enum { AS_ENABLE=0,AS_DISABLE_ENG_HOOD_OPEN=2,AS_DISABLE_DRV_ABSENT=1,AS_DISABLE_DRV_ENG_HOOD=3,} */

    typedef enum SPCR_Excpt_Rq_V2_enum_t {
      AS_ENABLE=0,
      AS_DISABLE_DRV_ABSENT=1,
      AS_DISABLE_ENG_HOOD_OPEN=2,
      AS_DISABLE_DRV_ENG_HOOD=3,
    } SPCR_Excpt_Rq_V2_enum_t;

    typedef uint8 SPCR_AS_Off_Rq_t;  /* Stop Coordinator Assistance system off request @min: 0 @max:3 @values: enum { STOP_COORD_SYS_OFF_IDLE=0,STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,STOP_COORD_SYS_OFF_AS_CONT_OFF=2,STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,}  */

    typedef enum SPCR_AS_Off_Rq_enum_t {
      STOP_COORD_SYS_OFF_IDLE=0,
      STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,
      STOP_COORD_SYS_OFF_AS_CONT_OFF=2,
      STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,
    } SPCR_AS_Off_Rq_enum_t;

    typedef uint8 SPCR_AS_Dsabl_t;  /* Stop Coordinator disable assistance system (temperatur) @min: 0 @max:2 @values: enum { STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,STOP_COORD_SYS_DIS_IDLE=0,STOP_COORD_SYS_DIS_AS_DISABLE=2,}  */

    typedef enum SPCR_AS_Dsabl_enum_t {
      STOP_COORD_SYS_DIS_IDLE=0,
      STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,
      STOP_COORD_SYS_DIS_AS_DISABLE=2,
    } SPCR_AS_Dsabl_enum_t;

    typedef struct LongCtrlInputCustomSPCR_t 
    {
      SPCR_Md_t SPCR_Md;
      SPCR_Excpt_Rq_V2_t SPCR_Excpt_Rq_V2;
      SPCR_AS_Off_Rq_t SPCR_AS_Off_Rq;
      SPCR_AS_Dsabl_t SPCR_AS_Dsabl;
      boolean SPCR_Veh_Immo;
    } LongCtrlInputCustomSPCR_t;     /* Stop Coordinator fields */

    typedef uint8 VehAccel_X_LDC_VehSp_Rs_t; /* Longitudinal controller vehicle stop response @min: 0 @max:3 @values: enum { LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,LONG_VEH_STOP_RQ_IDLE=0,LONG_VEH_STOP_RQ_COMPLETE=2,LONG_VEH_STOP_RQ_ACTIVE=1,}  */

    typedef enum VehAccel_X_LDC_VehSp_Rs_enum_t {
      LONG_VEH_STOP_RQ_IDLE=0,
      LONG_VEH_STOP_RQ_ACTIVE=1,
      LONG_VEH_STOP_RQ_COMPLETE=2,
      LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,
    } VehAccel_X_LDC_VehSp_Rs_enum_t;

    typedef struct LongCtrlRs_t 
    {
      VehAccel_X_LDC_VehSp_Rs_t VehAccel_X_LDC_VehSp_Rs;
    } LongCtrlRs_t;			/* Custom Longitudinal Control Response (dynamic) */

    typedef uint8 CustomSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:32 @values: enum { SPCR_EXCPT_RQ_ST=2,SPCR_MD_ST=1,SPCR_AS_OFF_RQ_ST=4,SPCR_AS_DSABL_ST=8,SPCR_VEH_IMMO_ST=16,VEH_ACCEL_X_LDC_VEH_SP_RS=32,}  */
  
    typedef enum CustomSignalState_enum_t {
      SPCR_MD_ST = 1,
      SPCR_EXCPT_RQ_ST = 2,
      SPCR_AS_OFF_RQ_ST = 4,
      SPCR_AS_DSABL_ST = 8,
      SPCR_VEH_IMMO_ST = 16,
      VEH_ACCEL_X_LDC_VEH_SP_RS = 32,
    } CustomSignalState_enum_t;
  
    typedef struct LongCtrlInputCustom_t
    {
      LongCtrlInputCustomSPCR_t SPCR;
      LongCtrlRs_t LongCtrlRs;
      CustomSignalState_t CustomSignalState;
    } LongCtrlInputCustom_t;  /* Customer specific fields */
#else
    typedef LongCtrlInputV10::Daimler::LongCtrlInputCustom_t LongCtrlInputCustom_t;
#endif 
    typedef LongCtrlInputV11::Daimler::KinCtrlDynInput_t KinCtrlDynInput_t;
    typedef LongCtrlInputV11::SpeedUnitEnum_t SpeedUnitEnum_t;
    typedef LongCtrlInputV11::Daimler::DisplayOutputSignalState_t DisplayOutputSignalState_t;
    typedef LongCtrlInputV11::Daimler::KinCtrlDynInput_t KinCtrlDynInput_t;
    typedef struct KinDisplayInput_t
    {
      SpeedUnitEnum_t speed_unit;
      unsigned __int16 speedometer_speed;
      DisplayOutputSignalState_t DisplayOutputSignalState;
    } KinDisplayInput_t;  /* Output from display to the kinematic controller */

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  };  // End of namespace Daimler

};  // End of namespace LongCtrlInputV12

namespace LongCtrlInputV19
{
#if 0   // Reuse identical declarations
  typedef unsigned long AlgoDataTimeStamp_t;  /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */
  typedef unsigned short AlgoCycleCounter_t;  /* Algo cycle counter @min:0 @max:65535 */
  typedef unsigned char AlgoSignalState_t;    /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */

  typedef enum AlgoSignalState_enum_t {
    AL_SIG_STATE_INIT=0,
    AL_SIG_STATE_OK=1,
    AL_SIG_STATE_INVALID=2,
  } AlgoSignalState_enum_t;

  typedef struct SignalHeader_t
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;  /* Common header for all structured data types */

  typedef uint8 DC_status_information_t;   /* 0 = DC available, 1 = DC reversible not available, 2 = DC irreversible not available (for rest of ignition cycle) @min: 0 @max:2 @values: enum { DC_STATUS_AVAILABLE=0,DC_STATUS_NOT_AVAIL=2,DC_STATUS_TMP_NOT_AVAIL=1,} */

  typedef enum DC_status_info_enum_t {
    DC_STATUS_AVAILABLE=0,
    DC_STATUS_TMP_NOT_AVAIL=1,
    DC_STATUS_NOT_AVAIL=2,
  } DC_status_info_enum_t;

  typedef uint8 ldm_ctrl_state_t; /* LDM control state: indicates if ABS/TCS/ESP intervention active or control defective @min: 1 @max:32 @values: enum { LDM_CTRL_TCS_ACTIVE=2,LDM_CTRL_ESP_DEFECTIVE=32,LDM_CTRL_ABS_ACTIVE=1,LDM_CTRL_TCS_DEFECTIVE=16,LDM_CTRL_ABS_DEFECTIVE=8,LDM_CTRL_ESP_ACTIVE=4,} */

  typedef enum ldm_ctrl_state_enum_t {
    LDM_CTRL_ABS_ACTIVE=1,
    LDM_CTRL_TCS_ACTIVE=2,
    LDM_CTRL_ESP_ACTIVE=4,
    LDM_CTRL_ABS_DEFECTIVE=8,
    LDM_CTRL_TCS_DEFECTIVE=16,
    LDM_CTRL_ESP_DEFECTIVE=32,
  } ldm_ctrl_state_enum_t;

  typedef uint8 door_state_t; /* States of doors (bit field) @min: 1 @max:32 @values: enum { DOOR_TRUNK_OPEN=32,DOOR_FRONT_RIGHT_OPEN=2,DOOR_ENG_HOOD_OPEN=16,DOOR_REAR_LEFT_OPEN=4,DOOR_FRONT_LEFT_OPEN=1,DOOR_REAR_RIGHT_OPEN=8,} */

  typedef enum door_state_enum_t {
    DOOR_FRONT_LEFT_OPEN=1,
    DOOR_FRONT_RIGHT_OPEN=2,
    DOOR_REAR_LEFT_OPEN=4,
    DOOR_REAR_RIGHT_OPEN=8,
    DOOR_ENG_HOOD_OPEN=16,
    DOOR_TRUNK_OPEN=32,
  } door_state_enum_t;

  typedef uint8 SpeedUnitEnum_t;  /* Speed unit of spedometer @min: 0 @max:1 @values: enum { SPD_UNIT_KMH=0,SPD_UNIT_MPH=1,} */

  typedef enum SpeedUnitEnum_enum_t {
    SPD_UNIT_KMH=0,
    SPD_UNIT_MPH=1,
  } SpeedUnitEnum_enum_t;

  typedef uint8 country_code_t;  /* Country coding information @min: 0 @max:3 @values: enum { COUNTRY_REST_WORLD=0,COUNTRY_CANADA=3,COUNTRY_USA=1,COUNTRY_JAPAN=2,} */;

  typedef enum country_code_enum_t {
    COUNTRY_REST_WORLD = 0,
    COUNTRY_USA = 1,
    COUNTRY_JAPAN = 2,
    COUNTRY_CANADA = 3,
  } country_code_enum_t;

  typedef uint8 KinCtrlSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:4096 @values: enum { DOOR_STATE=4096,ACC_ENABLE=1024,DRIVER_OVERRIDE_ACCEL_PEDAL=16,VAR_LIM_ENGAGE=4,STAND_STILL_DETECTED=8,LONG_INIT_ACCEL=1,DRIVER_BRAKING=64,DRIVER_OVERRIDE_BRAKE_PEDAL=32,DAS_ACCEL_REQ_LIM=128,PARK_BRK_ENGAGE=2048,PERM_LIM_SETSPEED=2,DAS_DECEL_REQ_LIM=256,LONG_SHUTOFF_ACQ=512,} */;

  typedef enum KinCtrlSignalState_enum_t {
    LONG_INIT_ACCEL = 1,
    PERM_LIM_SETSPEED = 2,
    VAR_LIM_ENGAGE = 4,
    STAND_STILL_DETECTED = 8,
    DRIVER_OVERRIDE_ACCEL_PEDAL = 16,
    DRIVER_OVERRIDE_BRAKE_PEDAL = 32,
    DRIVER_BRAKING = 64,
    DAS_ACCEL_REQ_LIM = 128,
    DAS_DECEL_REQ_LIM = 256,
    LONG_SHUTOFF_ACQ = 512,
    ACC_ENABLE = 1024,
    PARK_BRK_ENGAGE = 2048,
    DOOR_STATE = 4096,
  } KinCtrlSignalState_enum_t;

  typedef struct KinCtrlDynInput_t
  {
    signed short longi_initialization_accel;
    unsigned char perm_lim_setspeed;
    boolean var_lim_eng;
    boolean stand_still_detected;
    DC_status_information_t DC_status_information;
    boolean driver_override_accel_pedal;
    boolean driver_override_decel_pedal;
    boolean driver_braking;
    boolean DAS_accel_request_limited;
    boolean DAS_decel_request_limited;
    boolean longi_shutoff_acknowledged;
    ldm_ctrl_state_t ldm_ctrl_state;
    boolean acc_enable;
    boolean park_brk_eng;
    boolean brk_sw;
    door_state_t door_state;
    country_code_t country_code;
    KinCtrlSignalState_t KinCtrlSignalState;
  } KinCtrlDynInput_t;  /* Dynamic controller output used by the kinematic controller as input */


  typedef uint8 DisplayOutputSignalState_t; /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:2 @values: enum { SPEEDOMETER_SPEED=2,SPEED_UNIT=1,} */

  typedef enum DisplayOutputSignalState_enum_t {
    SPEED_UNIT = 1,
    SPEEDOMETER_SPEED = 2,
  } DisplayOutputSignalState_enum_t;
#else
  typedef LongCtrlInputV5::SpeedUnitEnum_t SpeedUnitEnum_t;
  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;
#endif

  typedef struct LongCtrlInputBase_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    //KinCtrlDynInput_t KinCtrlDynInput;
    //KinDisplayInput_t DisplayOutput;
  } LongCtrlInputBase_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  namespace Toyota
  {
    typedef signed short acceleration_t; /* Integer acceleration type @min:-32.767 @max:32.767 @resolution:0.001 */

    typedef unsigned char SPDSTAT_t;  /* Control Status at cruise lever operation by driver. @min: 0 @max:10 @values: enum { SPDSTAT_UNDER_DECEL_RQ_ACC=10,SPDSTAT_UNDER_CC_RESUME_CTRL=2,SPDSTAT_UNDER_CC_ACCEL_CTRL=3,SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,SPDSTAT_ACC_IDLE=8,SPDSTAT_UNDER_STOP_HOLD_ACC=7,SPDSTAT_NO_STATUS=0,SPDSTAT_UNDER_ACCEL_RQ_ACC=9,SPDSTAT_CC_IDLE=1,SPDSTAT_UNDER_CC_CORST_CTRL=4,SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,} */

    typedef enum SPDSTAT_enum_t{
      SPDSTAT_NO_STATUS=0,
      SPDSTAT_CC_IDLE=1,
      SPDSTAT_UNDER_CC_RESUME_CTRL=2,
      SPDSTAT_UNDER_CC_ACCEL_CTRL=3,
      SPDSTAT_UNDER_CC_CORST_CTRL=4,
      SPDSTAT_UNDER_CC_TAP_DOWN_CTRL=5,
      SPDSTAT_UNDER_CC_TAP_UP_CTRL=6,
      SPDSTAT_UNDER_STOP_HOLD_ACC=7,
      SPDSTAT_ACC_IDLE=8,
      SPDSTAT_UNDER_ACCEL_RQ_ACC=9,
      SPDSTAT_UNDER_DECEL_RQ_ACC=10,
    } SPDSTAT_enum_t;

    typedef unsigned char ACCSTAT_t;  /* Output control status @min: 0 @max:3 @values: enum { ACCSTAT_ACTIVE_OR_OVERRIDE=1,ACCSTAT_PB_RQ=3,ACCSTAT_DISENGAGE_OR_OFF=0,} */

    typedef enum ACC_STAT_enum_t {
      ACCSTAT_DISENGAGE_OR_OFF=0,
      ACCSTAT_ACTIVE_OR_OVERRIDE=1,
      ACCSTAT_PB_RQ=3,
    } ACC_STAT_enum_t;

    typedef unsigned char SLTACC_t;   /* ACC type @min: 0 @max:3 @values: enum { SLTACC_ACC_TYPE_FSRA=1,SLTACC_ACC_TYPE_CC=3,SLTACC_ACC_TYPE_RESERVE=0,SLTACC_ACC_TYPE_ACC=2,} */

    typedef enum SLTACC_enum_t {
      SLTACC_ACC_TYPE_RESERVE=0,
      SLTACC_ACC_TYPE_FSRA=1,
      SLTACC_ACC_TYPE_ACC=2,
      SLTACC_ACC_TYPE_CC=3,
    } SLTACC_enum_t;

    typedef unsigned char LTME2_t;    /* Vehicle following time @min: 0 @max:3 @values: enum { LTME2_VEH_FOLLOW_TIME_MIDDLE=2,LTME2_VEH_FOLLOW_TIME_SHORT=3,LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,LTME2_VEH_FOLLOW_TIME_LONG=1,} */

    typedef enum LTME2_enum_t {
      LTME2_VEH_FOLLOW_TIME_UNDEFINED=0,
      LTME2_VEH_FOLLOW_TIME_LONG=1,
      LTME2_VEH_FOLLOW_TIME_MIDDLE=2,
      LTME2_VEH_FOLLOW_TIME_SHORT=3,
    } LTME2_enum_t;

    typedef struct EngineEcuInput_t
    {
      boolean XLDR;
      boolean XACCACT;
      boolean STPBZ;
      acceleration_t ACCREQ;
      SPDSTAT_t SPDSTAT;
      ACCSTAT_t ACCSTAT;
      unsigned char LCCHK;
      unsigned short VM;
      boolean XCCOK2;
      SLTACC_t SLTACC;
      LTME2_t LTME2;
      acceleration_t INTG;
    } EngineEcuInput_t; /* Input from TMC engine ECU (manages state machine, driver inputs etc.) */

    typedef struct LongCtrlInputCustom_t
    {
      EngineEcuInput_t EngineEcuInput;
    } LongCtrlInputCustom_t;  /* Customer specific fields */

    typedef struct KinDisplayInput_t
    {
      SpeedUnitEnum_t speed_unit;
      unsigned __int16 speedometer_speed;
    } KinDisplayInput_t;  /* Output from display to the kinematic controller */

    typedef LongCtrlInputV11::Toyota::KinCtrlDynInput_t KinCtrlDynInput_t;

    typedef struct LongCtrlInput_t
    {
      uint32 uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  }; // End of namespace Toyota

  namespace Daimler
  {
#if 0   // Reuse identical declarations
    typedef uint8 SPCR_Md_t;  /* Stop coordinator state (Signal SPCR_Md) @min: 0 @max:8 @values: enum { STOP_COORD_ACTIVE_SLIP=7,STOP_COORD_ACTIVE_GO=6,STOP_COORD_HOLD=1,STOP_COORD_ACTIVE_HOLD=5,STOP_COORD_GO=2,STOP_COORD_PASSIVE=8,STOP_COORD_SLIP=3,STOP_COORD_IDLE=0,STOP_COORD_ACTIVE=4,}  */

    typedef enum SPCR_Md_enum_t {
      STOP_COORD_IDLE=0,
      STOP_COORD_HOLD=1,
      STOP_COORD_GO=2,
      STOP_COORD_SLIP=3,
      STOP_COORD_ACTIVE=4,
      STOP_COORD_ACTIVE_HOLD=5,
      STOP_COORD_ACTIVE_GO=6,
      STOP_COORD_ACTIVE_SLIP=7,
      STOP_COORD_PASSIVE=8,
    } SPCR_Md_enum_t;

    typedef uint8 SPCR_Excpt_Rq_V2_t;  /* Stop coordinator exception request @min: 0 @max:3 @values: enum { AS_ENABLE=0,AS_DISABLE_ENG_HOOD_OPEN=2,AS_DISABLE_DRV_ABSENT=1,AS_DISABLE_DRV_ENG_HOOD=3,} */

    typedef enum SPCR_Excpt_Rq_V2_enum_t {
      AS_ENABLE=0,
      AS_DISABLE_DRV_ABSENT=1,
      AS_DISABLE_ENG_HOOD_OPEN=2,
      AS_DISABLE_DRV_ENG_HOOD=3,
    } SPCR_Excpt_Rq_V2_enum_t;

    typedef uint8 SPCR_AS_Off_Rq_t;  /* Stop Coordinator Assistance system off request @min: 0 @max:3 @values: enum { STOP_COORD_SYS_OFF_IDLE=0,STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,STOP_COORD_SYS_OFF_AS_CONT_OFF=2,STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,}  */

    typedef enum SPCR_AS_Off_Rq_enum_t {
      STOP_COORD_SYS_OFF_IDLE=0,
      STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,
      STOP_COORD_SYS_OFF_AS_CONT_OFF=2,
      STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,
    } SPCR_AS_Off_Rq_enum_t;

    typedef uint8 SPCR_AS_Dsabl_t;  /* Stop Coordinator disable assistance system (temperatur) @min: 0 @max:2 @values: enum { STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,STOP_COORD_SYS_DIS_IDLE=0,STOP_COORD_SYS_DIS_AS_DISABLE=2,}  */

    typedef enum SPCR_AS_Dsabl_enum_t {
      STOP_COORD_SYS_DIS_IDLE=0,
      STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,
      STOP_COORD_SYS_DIS_AS_DISABLE=2,
    } SPCR_AS_Dsabl_enum_t;

    typedef struct LongCtrlInputCustomSPCR_t 
    {
      SPCR_Md_t SPCR_Md;
      SPCR_Excpt_Rq_V2_t SPCR_Excpt_Rq_V2;
      SPCR_AS_Off_Rq_t SPCR_AS_Off_Rq;
      SPCR_AS_Dsabl_t SPCR_AS_Dsabl;
      boolean SPCR_Veh_Immo;
    } LongCtrlInputCustomSPCR_t;     /* Stop Coordinator fields */

    typedef uint8 VehAccel_X_LDC_VehSp_Rs_t; /* Longitudinal controller vehicle stop response @min: 0 @max:3 @values: enum { LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,LONG_VEH_STOP_RQ_IDLE=0,LONG_VEH_STOP_RQ_COMPLETE=2,LONG_VEH_STOP_RQ_ACTIVE=1,}  */

    typedef enum VehAccel_X_LDC_VehSp_Rs_enum_t {
      LONG_VEH_STOP_RQ_IDLE=0,
      LONG_VEH_STOP_RQ_ACTIVE=1,
      LONG_VEH_STOP_RQ_COMPLETE=2,
      LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,
    } VehAccel_X_LDC_VehSp_Rs_enum_t;

    typedef struct LongCtrlRs_t 
    {
      VehAccel_X_LDC_VehSp_Rs_t VehAccel_X_LDC_VehSp_Rs;
    } LongCtrlRs_t;			/* Custom Longitudinal Control Response (dynamic) */

    typedef uint8 CustomSignalState_t;  /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:32 @values: enum { SPCR_EXCPT_RQ_ST=2,SPCR_MD_ST=1,SPCR_AS_OFF_RQ_ST=4,SPCR_AS_DSABL_ST=8,SPCR_VEH_IMMO_ST=16,VEH_ACCEL_X_LDC_VEH_SP_RS=32,}  */
  
    typedef enum CustomSignalState_enum_t {
      SPCR_MD_ST = 1,
      SPCR_EXCPT_RQ_ST = 2,
      SPCR_AS_OFF_RQ_ST = 4,
      SPCR_AS_DSABL_ST = 8,
      SPCR_VEH_IMMO_ST = 16,
      VEH_ACCEL_X_LDC_VEH_SP_RS = 32,
    } CustomSignalState_enum_t;
  
    typedef struct LongCtrlInputCustom_t
    {
      LongCtrlInputCustomSPCR_t SPCR;
      LongCtrlRs_t LongCtrlRs;
      CustomSignalState_t CustomSignalState;
    } LongCtrlInputCustom_t;  /* Customer specific fields */
#else
    typedef LongCtrlInputV10::Daimler::LongCtrlInputCustom_t LongCtrlInputCustom_t;
#endif 
    typedef LongCtrlInputV11::Daimler::KinCtrlDynInput_t KinCtrlDynInput_t;
    typedef LongCtrlInputV11::SpeedUnitEnum_t SpeedUnitEnum_t;
    typedef LongCtrlInputV11::Daimler::DisplayOutputSignalState_t DisplayOutputSignalState_t;
    typedef LongCtrlInputV11::Daimler::KinCtrlDynInput_t KinCtrlDynInput_t;

    typedef unsigned short t_u_DistanceLong;
    typedef unsigned char t_e_SLA_SpeedLimitNextType;
    typedef unsigned char t_e_SLA_Setting;
    typedef unsigned char t_NavStreetType;

    typedef struct KinDisplayInput_t
    {
      SpeedUnitEnum_t speed_unit;
      unsigned __int16 speedometer_speed;
      DisplayOutputSignalState_t DisplayOutputSignalState;
    } KinDisplayInput_t;  /* Output from display to the kinematic controller */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    signed char s_TSA_SpeedOffset;
 	    SpeedUnitEnum_t e_TSA_SpeedUnit;
    } TSA_Input_t;			/* Input from Traffic Sign Assist Camera function */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    unsigned char u_SLA_SpeedLimitNow;
 	    unsigned char u_SLA_SpeedLimitNext;
 	    t_u_DistanceLong u_SLA_SpeedLimitNextDistance;
 	    SpeedUnitEnum_t e_SLA_SpeedLimitUnit;
 	    t_e_SLA_SpeedLimitNextType e_SLA_SpeedLimitNextType;
 	    t_e_SLA_Setting e_SLA_Setting;
     } SLA_Input_t;			/* Input from Speed Limit Assist  function (Camera and Navi data) */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    t_NavStreetType e_NavStreetType;
    } Navi_Output_t;			/* Navi data input */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    unsigned long uiVersionNumber;
 	    SignalHeader_t sSigHeader;
 	    KinCtrlDynInput_t KinCtrlDynInput;
 	    KinDisplayInput_t DisplayOutput;
 	    TSA_Input_t TSA_Input;
 	    SLA_Input_t SLA_Input;
 	    Navi_Output_t Navi_Input;
 	    LongCtrlInputCustom_t Custom;
     } LongCtrlInput_t;			/* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  };  // End of namespace Daimler
};  // End of namespace LongCtrlInputV19

namespace LongCtrlInputV21
{
  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;

  typedef struct LongCtrlInputBase_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    //KinCtrlDynInput_t KinCtrlDynInput;
    //KinDisplayInput_t DisplayOutput;
  } LongCtrlInputBase_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */


  namespace Mitsubishi
  {
    typedef unsigned char SPCR_Md_t                 /* Stop coordinator state (Signal SPCR_Md) @min: 0 @max:8 @values: enum { STOP_COORD_ACTIVE_SLIP=7,STOP_COORD_ACTIVE_GO=6,STOP_COORD_HOLD=1,STOP_COORD_ACTIVE_HOLD=5,STOP_COORD_GO=2,STOP_COORD_PASSIVE=8,STOP_COORD_SLIP=3,STOP_COORD_IDLE=0,STOP_COORD_ACTIVE=4,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char SPCR_AS_Dsabl_t           /* Stop Coordinator disable assistance system (temperatur) @min: 0 @max:2 @values: enum { STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,STOP_COORD_SYS_DIS_IDLE=0,STOP_COORD_SYS_DIS_AS_DISABLE=2,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char SPCR_AS_Off_Rq_t          /* Stop Coordinator Assistance system off request @min: 0 @max:3 @values: enum { STOP_COORD_SYS_OFF_IDLE=0,STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,STOP_COORD_SYS_OFF_AS_CONT_OFF=2,STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char SPCR_Excpt_Rq_V2_t        /* Stop coordinator exception request @min: 0 @max:3 @values: enum { AS_ENABLE=0,AS_DISABLE_ENG_HOOD_OPEN=2,AS_DISABLE_DRV_ABSENT=1,AS_DISABLE_DRV_ENG_HOOD=3,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char VehAccel_X_LDC_VehSp_Rs_t /* Longitudinal controller vehicle stop response @min: 0 @max:3 @values: enum { LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,LONG_VEH_STOP_RQ_IDLE=0,LONG_VEH_STOP_RQ_COMPLETE=2,LONG_VEH_STOP_RQ_ACTIVE=1,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char CustomSignalState_t       /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:32 @values: enum { SPCR_EXCPT_RQ_ST=2,SPCR_MD_ST=1,SPCR_AS_OFF_RQ_ST=4,SPCR_AS_DSABL_ST=8,SPCR_VEH_IMMO_ST=16,VEH_ACCEL_X_LDC_VEH_SP_RS=32,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char eASG_status_t             /* ASG Status @min: 0 @max:3 @values: enum { IDLE_STOP=1,IDL_STP_PROHI_AUTO_START=3,AUTO_START=2,NORMAL=0,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char eAuto_Hold_Status_t       /* Brake auto hold state @min: 0 @max:4 @values: enum { AUTO_HOLD_STANDBY=1,AUTO_HOLD_ACTIVE=3,AUTO_HOLD_OFF=0,AUTO_HOLD_ACTIVE_ERROR=4,AUTO_HOLD_ERROR=2,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char ACCS_state_eng_t          /* Engine ECU State Machine @min: 0 @max:1 @values: enum { ACCS_STANDBY_ENG=0,ACCS_ACTIVE_ENG=1,} */	/* [Satisfies_rte sws 1188] */;

    typedef struct
    {
      SPCR_Md_t SPCR_Md;
      SPCR_Excpt_Rq_V2_t SPCR_Excpt_Rq_V2;
      SPCR_AS_Off_Rq_t SPCR_AS_Off_Rq;
      SPCR_AS_Dsabl_t SPCR_AS_Dsabl;
      boolean SPCR_Veh_Immo;
    } LongCtrlInputCustomSPCR_t;

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      VehAccel_X_LDC_VehSp_Rs_t VehAccel_X_LDC_VehSp_Rs;
    } LongCtrlRs_t;			/* Custom Longitudinal Control Response (dynamic) */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      boolean bEPB_Fail;
      eASG_status_t eASG_status;
      boolean bACCS_Limit_Grade;
      eAuto_Hold_Status_t eAuto_Hold_Status;
      boolean bAirbag_Deploy;
      boolean bAccsShftPos;
      boolean ACCS_TempFail;
      boolean ACCS_SeriousFail;
      boolean bACCS_TempDisp;
      boolean bACCS_BlockageDisp;
      ACCS_state_eng_t ACCS_state_eng;
    } LongCtrlInputCustomMMCIn_t;			/* Customer Specific Input for MMC */

    typedef struct
    {
      LongCtrlInputCustomSPCR_t SPCR;
      LongCtrlRs_t LongCtrlRs;
      CustomSignalState_t CustomSignalState;
      LongCtrlInputCustomMMCIn_t MMCIn;
    } LongCtrlInputCustom_t;

    typedef struct
    {
      unsigned long uiVersionNumber;
      SignalHeader_t sSigHeader;
      LongCtrlInputV19::Toyota::KinCtrlDynInput_t KinCtrlDynInput;
      LongCtrlInputV19::Toyota::KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;
  };  // End of namespace Mitsubishi
};  // End of namespace LongCtrlInputV21

namespace LongCtrlInputV22
{
  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;

  typedef struct LongCtrlInputBase_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
    //KinCtrlDynInput_t KinCtrlDynInput;
    //KinDisplayInput_t DisplayOutput;
  } LongCtrlInputBase_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */


  namespace Mitsubishi
  {
    typedef unsigned char SPCR_Md_t                 /* Stop coordinator state (Signal SPCR_Md) @min: 0 @max:8 @values: enum { STOP_COORD_ACTIVE_SLIP=7,STOP_COORD_ACTIVE_GO=6,STOP_COORD_HOLD=1,STOP_COORD_ACTIVE_HOLD=5,STOP_COORD_GO=2,STOP_COORD_PASSIVE=8,STOP_COORD_SLIP=3,STOP_COORD_IDLE=0,STOP_COORD_ACTIVE=4,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char SPCR_AS_Dsabl_t           /* Stop Coordinator disable assistance system (temperatur) @min: 0 @max:2 @values: enum { STOP_COORD_SYS_DIS_AS_NOT_ENABLE=1,STOP_COORD_SYS_DIS_IDLE=0,STOP_COORD_SYS_DIS_AS_DISABLE=2,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char SPCR_AS_Off_Rq_t          /* Stop Coordinator Assistance system off request @min: 0 @max:3 @values: enum { STOP_COORD_SYS_OFF_IDLE=0,STOP_COORD_SYS_OFF_AS_TEMP_OFF=1,STOP_COORD_SYS_OFF_AS_CONT_OFF=2,STOP_COORD_SYS_OFF_NOT_AVALIBLE=3,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char SPCR_Excpt_Rq_V2_t        /* Stop coordinator exception request @min: 0 @max:3 @values: enum { AS_ENABLE=0,AS_DISABLE_ENG_HOOD_OPEN=2,AS_DISABLE_DRV_ABSENT=1,AS_DISABLE_DRV_ENG_HOOD=3,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char VehAccel_X_LDC_VehSp_Rs_t /* Longitudinal controller vehicle stop response @min: 0 @max:3 @values: enum { LONG_VEH_STOP_RQ_TAKE_OVER_SPCR=3,LONG_VEH_STOP_RQ_IDLE=0,LONG_VEH_STOP_RQ_COMPLETE=2,LONG_VEH_STOP_RQ_ACTIVE=1,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char CustomSignalState_t       /* Bit-Map Input signal state min RAM solution. Set true if signal valid, false if signal not valid. @min: 1 @max:32 @values: enum { SPCR_EXCPT_RQ_ST=2,SPCR_MD_ST=1,SPCR_AS_OFF_RQ_ST=4,SPCR_AS_DSABL_ST=8,SPCR_VEH_IMMO_ST=16,VEH_ACCEL_X_LDC_VEH_SP_RS=32,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char eASG_status_t             /* ASG Status @min: 0 @max:3 @values: enum { IDLE_STOP=1,IDL_STP_PROHI_AUTO_START=3,AUTO_START=2,NORMAL=0,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char eAuto_Hold_Status_t       /* Brake auto hold state @min: 0 @max:4 @values: enum { AUTO_HOLD_STANDBY=1,AUTO_HOLD_ACTIVE=3,AUTO_HOLD_OFF=0,AUTO_HOLD_ACTIVE_ERROR=4,AUTO_HOLD_ERROR=2,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char ACCS_state_eng_t          /* Engine ECU State Machine @min: 0 @max:1 @values: enum { ACCS_STANDBY_ENG=0,ACCS_ACTIVE_ENG=1,} */	/* [Satisfies_rte sws 1188] */;

    typedef struct
    {
      SPCR_Md_t SPCR_Md;
      SPCR_Excpt_Rq_V2_t SPCR_Excpt_Rq_V2;
      SPCR_AS_Off_Rq_t SPCR_AS_Off_Rq;
      SPCR_AS_Dsabl_t SPCR_AS_Dsabl;
      boolean SPCR_Veh_Immo;
    } LongCtrlInputCustomSPCR_t;

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      VehAccel_X_LDC_VehSp_Rs_t VehAccel_X_LDC_VehSp_Rs;
    } LongCtrlRs_t;			/* Custom Longitudinal Control Response (dynamic) */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      boolean bEPB_Fail;
      eASG_status_t eASG_status;
      boolean bACCS_ASG_type;
      boolean bACCS_Limit_Grade;
      eAuto_Hold_Status_t eAuto_Hold_Status;
      boolean bAirbag_Deploy;
      boolean bAccsShftPos;
      boolean ACCS_TempFail;
      boolean ACCS_SeriousFail;
      boolean bACCS_TempDisp;
      boolean bACCS_BlockageDisp;
      ACCS_state_eng_t ACCS_state_eng;
      boolean bSPM_selftest_active;
      boolean bFCMB_start;
    } LongCtrlInputCustomMMCIn_t;			/* Customer Specific Input for MMC */

    typedef struct
    {
      LongCtrlInputCustomSPCR_t SPCR;
      LongCtrlRs_t LongCtrlRs;
      CustomSignalState_t CustomSignalState;
      LongCtrlInputCustomMMCIn_t MMCIn;
    } LongCtrlInputCustom_t;

    typedef struct
    {
      unsigned long uiVersionNumber;
      SignalHeader_t sSigHeader;
      LongCtrlInputV19::Toyota::KinCtrlDynInput_t KinCtrlDynInput;
      LongCtrlInputV19::Toyota::KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
    } LongCtrlInput_t;
  };  // End of namespace Mitsubishi
};  // End of namespace LongCtrlInputV22

namespace LongCtrlInputV25
{
  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;

  typedef struct LongCtrlInputBase_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
  } LongCtrlInputBase_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  namespace Hyundai
  {
    typedef LongCtrlInputV9::Toyota::KinCtrlDynInput_t KinCtrlDynInput_t;
    typedef LongCtrlInputV19::Toyota::KinDisplayInput_t KinDisplayInput_t;

    typedef uint8                       FCTVehDPCMdASRq_t;
    typedef uint8                       percentage_t;
    typedef signed short                NSCC_SegInfoList_Dist_array_t[20];    /* Array of the distances regarding the segments within 2km horizon @min:-2000 @max:2000 @resolution:0.1 */	/* [Satisfies_rte sws 1189] */
    typedef uint8                       nscc_roadclass_t;
    typedef uint8                       nscc_linkclass_t;
    typedef signed short                OSC_SpotCamInfoList_Dist_array_t[20]; /* Array of the distances regarding the POIs within 2km horizon @min:-2000 @max:2000 @resolution:0.1 */	/* [Satisfies_rte sws 1189] */
    typedef uint8                       OSC_SpotCamInfoList_Type_t;           /* Array of the POI types within 2km horizon @min: 0 @max:3 @values: enum { POI_TYPE_FIXED=3,POI_TYPE_FIXED_MOVING=2,POI_TYPE_NONE=0,POI_TYPE_MOVING=1,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char             	OSC_SpotCamInfoList_array_t[20];      /* Array of the speed limit of the POIs within 2km horizon @min:0 @max:31 */	/* [Satisfies_rte sws 1189] */

    typedef nscc_roadclass_t          	NSCC_SegInfoList_RC_array_t[20];      /* Array of the road class regarding the segments within 2km horizon */	/* [Satisfies_rte sws 1189] */
    typedef nscc_linkclass_t          	NSCC_SegInfoList_LC_array_t[20];      /* Array of the link class regarding the segments within 2km horizon */	/* [Satisfies_rte sws 1189] */
    typedef OSC_SpotCamInfoList_Type_t 	OSC_SpotCamInfoList_Type_array_t[20]; /* Array of the POI types within 2km horizon */	/* [Satisfies_rte sws 1189] */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    NSCC_SegInfoList_Dist_array_t NSCC_SegInfoList_Dist;
 	    NSCC_SegInfoList_RC_array_t NSCC_SegInfoList_RC;
 	    NSCC_SegInfoList_LC_array_t NSCC_SegInfoList_LC;
 	    boolean NSCC_DataReady;
 	    nscc_roadclass_t NSCC_CurRoadClass;
 	    nscc_linkclass_t NSCC_CurLinkClass;
 	    unsigned char NSCC_SegInfoValidSize;
     } NSCC_Segments_t;			/* NaviSCC Segments Input */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    OSC_SpotCamInfoList_Dist_array_t OSC_SpotCamInfoList_Dist;
 	    OSC_SpotCamInfoList_Type_array_t OSC_SpotCamInfoList_Type;
 	    OSC_SpotCamInfoList_array_t OSC_SpotCamInfoList;
 	    unsigned char OSC_SpotCamInfoValidSize;
     } NSCC_ProLong_t;			/* NaviSCC ProLong Input */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    NSCC_Segments_t NSCC_Seg;
 	    NSCC_ProLong_t NSCC_ProLong;
     } NSCC_Input_t;			/* HMC specific NaviSCC inputs */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    boolean HDA_AutoSetSpdEnable;
 	    unsigned char HDA_SetSpd;
     } HDA_Input_t;			/* HMC specific Higway Drive Assist inputs */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    boolean diseng_EBA;
 	    FCTVehDPCMdASRq_t driving_mode_init;
 	    percentage_t headway_init;
 	    boolean SLD_State;
 	    NSCC_Input_t NaviSCC;
 	    HDA_Input_t HDAIn;
     } LongCtrlInputCustomHMCIn_t;			/* Customer Specific Input for HMC */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    LongCtrlInputCustomHMCIn_t HMCIn;
     } LongCtrlInputCustom_t;			/* Customer specific fields */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
	    unsigned long uiVersionNumber;
 	    SignalHeader_t sSigHeader;
 	    KinCtrlDynInput_t KinCtrlDynInput;
 	    KinDisplayInput_t DisplayOutput;
 	    LongCtrlInputCustom_t Custom;
     } LongCtrlInput_t;			/* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  }; // End of namespace Toyota

};  // End of namespace LongCtrlInputV25

namespace LongCtrlInputV34
{
  typedef LongCtrlInputV5::SignalHeader_t SignalHeader_t;

  typedef struct LongCtrlInputBase_t
  {
    uint32 uiVersionNumber;
    SignalHeader_t sSigHeader;
  } LongCtrlInputBase_t;  /* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  namespace Hyundai
  {
    typedef LongCtrlInputV9::Toyota::KinCtrlDynInput_t KinCtrlDynInput_t;
    typedef LongCtrlInputV19::Toyota::KinDisplayInput_t KinDisplayInput_t;

    typedef uint8                       FCTVehDPCMdASRq_t;
    typedef uint8                       percentage_t;
    typedef signed short                NSCC_SegInfoList_Dist_array_t[20];    /* Array of the distances regarding the segments within 2km horizon @min:-2000 @max:2000 @resolution:0.1 */	/* [Satisfies_rte sws 1189] */
    typedef uint8                       nscc_roadclass_t;
    typedef uint8                       nscc_linkclass_t;
    typedef signed short                OSC_SpotCamInfoList_Dist_array_t[20]; /* Array of the distances regarding the POIs within 2km horizon @min:-2000 @max:2000 @resolution:0.1 */	/* [Satisfies_rte sws 1189] */
    typedef uint8                       OSC_SpotCamInfoList_Type_t;           /* Array of the POI types within 2km horizon @min: 0 @max:3 @values: enum { POI_TYPE_FIXED=3,POI_TYPE_FIXED_MOVING=2,POI_TYPE_NONE=0,POI_TYPE_MOVING=1,} */	/* [Satisfies_rte sws 1188] */;
    typedef unsigned char               OSC_SpotCamInfoList_array_t[20];      /* Array of the speed limit of the POIs within 2km horizon @min:0 @max:31 */	/* [Satisfies_rte sws 1189] */

    typedef nscc_roadclass_t            NSCC_SegInfoList_RC_array_t[20];      /* Array of the road class regarding the segments within 2km horizon */	/* [Satisfies_rte sws 1189] */
    typedef nscc_linkclass_t            NSCC_SegInfoList_LC_array_t[20];      /* Array of the link class regarding the segments within 2km horizon */	/* [Satisfies_rte sws 1189] */
    typedef OSC_SpotCamInfoList_Type_t  OSC_SpotCamInfoList_Type_array_t[20]; /* Array of the POI types within 2km horizon */	/* [Satisfies_rte sws 1189] */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      NSCC_SegInfoList_Dist_array_t NSCC_SegInfoList_Dist;
      NSCC_SegInfoList_RC_array_t NSCC_SegInfoList_RC;
      NSCC_SegInfoList_LC_array_t NSCC_SegInfoList_LC;
      boolean NSCC_DataReady;
      nscc_roadclass_t NSCC_CurRoadClass;
      nscc_linkclass_t NSCC_CurLinkClass;
      unsigned char NSCC_SegInfoValidSize;
     } NSCC_Segments_t;			/* NaviSCC Segments Input */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      OSC_SpotCamInfoList_Dist_array_t OSC_SpotCamInfoList_Dist;
      OSC_SpotCamInfoList_Type_array_t OSC_SpotCamInfoList_Type;
      OSC_SpotCamInfoList_array_t OSC_SpotCamInfoList;
      unsigned char OSC_SpotCamInfoValidSize;
     } NSCC_ProLong_t;			/* NaviSCC ProLong Input */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      unsigned char OSC_SectCam_Spd;
      float OSC_SectCam_AvgSpd;
      boolean OSC_SectCam_Valid;
      boolean SOSC_DataReady;
    } NSCC_ProShort_t;			/* NaviSCC ProShort Input */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      NSCC_Segments_t NSCC_Seg;
      NSCC_ProLong_t NSCC_ProLong;
      NSCC_ProShort_t NSCC_ProShort;
      float DrivingDistFor1Cycle;
      boolean NSCC_Buffer_Reset;
      float DrivingDistForPosMsgUpdate;
      boolean NSCC_Inhibit;
      boolean NSCC_RouteInvalid;
      boolean NSCC_PosMsgUpdate;
      boolean OSC_USM_Status;
     } NSCC_Input_t;			/* HMC specific NaviSCC inputs */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      boolean HDA_AutoSetSpdEnable;
      unsigned char HDA_SetSpd;
     } HDA_Input_t;			/* HMC specific Higway Drive Assist inputs */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      boolean diseng_EBA;
      FCTVehDPCMdASRq_t driving_mode_init;
      percentage_t headway_init;
      boolean SLD_State;
      NSCC_Input_t NaviSCC;
      HDA_Input_t HDAIn;
     } LongCtrlInputCustomHMCIn_t;			/* Customer Specific Input for HMC */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      LongCtrlInputCustomHMCIn_t HMCIn;
     } LongCtrlInputCustom_t;			/* Customer specific fields */

    typedef struct 			/* [Satisfies_rte sws 1191] */
    {
      unsigned long uiVersionNumber;
      SignalHeader_t sSigHeader;
      KinCtrlDynInput_t KinCtrlDynInput;
      KinDisplayInput_t DisplayOutput;
      LongCtrlInputCustom_t Custom;
     } LongCtrlInput_t;			/* Longitudinal Control Response usually from brake ECU @vaddr:0x20219100 @vaddr_defs: FCT_MEAS_ID_LONG_CTRL_INPUT @cycleid:FCT_VEH_IN @vname:LongCtrlInput */

  }; // End of namespace Hyundai

};  // End of namespace LongCtrlInputV34

//
// Main ACC conversion class
//

class CConvLongCtrlInput : public CSimConverterBase
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

  LongCtrlInputV5::LongCtrlInput_t m_LongCtrlInputV5;
  union {
    LongCtrlInputV6::LongCtrlInputBase_t      Base;
    LongCtrlInputV6::Daimler::LongCtrlInput_t Daimler;
    LongCtrlInputV6::Toyota::LongCtrlInput_t  Toyota;
  } m_LongCtrlInputV6;
  union {
    LongCtrlInputV7::LongCtrlInputBase_t      Base;
    LongCtrlInputV7::Daimler::LongCtrlInput_t Daimler;
    LongCtrlInputV7::Toyota::LongCtrlInput_t  Toyota;
  } m_LongCtrlInputV7;
  union {
    LongCtrlInputV9::LongCtrlInputBase_t      Base;
    LongCtrlInputV9::Daimler::LongCtrlInput_t Daimler;
    LongCtrlInputV9::Toyota::LongCtrlInput_t  Toyota;
  } m_LongCtrlInputV9;
  union {
    LongCtrlInputV10::LongCtrlInputBase_t       Base;
    LongCtrlInputV10::Daimler::LongCtrlInput_t  Daimler;
    LongCtrlInputV10::Toyota::LongCtrlInput_t   Toyota;
  } m_LongCtrlInputV10;
  union {
    LongCtrlInputV11::LongCtrlInputBase_t       Base;
    LongCtrlInputV11::Daimler::LongCtrlInput_t  Daimler;
    LongCtrlInputV11::Toyota::LongCtrlInput_t   Toyota;
    LongCtrlInputV11::Toyota_2::LongCtrlInput_t Toyota_2;
  } m_LongCtrlInputV11;
  union {
    LongCtrlInputV12::LongCtrlInputBase_t       Base;
    LongCtrlInputV12::Daimler::LongCtrlInput_t  Daimler;
    LongCtrlInputV12::Toyota::LongCtrlInput_t   Toyota;
  } m_LongCtrlInputV12;
  union {
    LongCtrlInputV19::LongCtrlInputBase_t       Base;
    LongCtrlInputV19::Daimler::LongCtrlInput_t  Daimler;
    LongCtrlInputV19::Toyota::LongCtrlInput_t   Toyota;
  } m_LongCtrlInputV19;
  union {
    LongCtrlInputV21::LongCtrlInputBase_t         Base;
    LongCtrlInputV21::Mitsubishi::LongCtrlInput_t Mitsubishi;
  } m_LongCtrlInputV21;
  union {
    LongCtrlInputV22::LongCtrlInputBase_t         Base;
    LongCtrlInputV22::Mitsubishi::LongCtrlInput_t Mitsubishi;
  } m_LongCtrlInputV22;
  //LongCtrlInputV9::LongCtrlInput_t m_LongCtrlInputV9;
  //LongCtrlInputV10::LongCtrlInput_t m_LongCtrlInputV10;
  union {
    LongCtrlInputV25::LongCtrlInputBase_t       Base;
    LongCtrlInputV25::Hyundai::LongCtrlInput_t  Hyundai;
  } m_LongCtrlInputV25;
  union {
    LongCtrlInputV34::LongCtrlInputBase_t       Base;
    LongCtrlInputV34::Hyundai::LongCtrlInput_t  Hyundai;
  } m_LongCtrlInputV34;

  void InitV5(LongCtrlInputV5::LongCtrlInput_t & Dest);
  void InitV6(LongCtrlInputV6::LongCtrlInputBase_t & Dest);
  void InitV6(LongCtrlInputV6::Daimler::LongCtrlInput_t & Dest);
  void InitV6(LongCtrlInputV6::Toyota::LongCtrlInput_t & Dest);
  void InitV7(LongCtrlInputV7::LongCtrlInputBase_t & Dest);
  void InitV7(LongCtrlInputV7::Daimler::LongCtrlInput_t & Dest);
  void InitV7(LongCtrlInputV7::Toyota::LongCtrlInput_t & Dest);
  void InitV9(LongCtrlInputV9::LongCtrlInputBase_t & Dest);
  void InitV9(LongCtrlInputV9::Daimler::LongCtrlInput_t & Dest);
  void InitV9(LongCtrlInputV9::Toyota::LongCtrlInput_t & Dest);
  void InitV10(LongCtrlInputV10::LongCtrlInputBase_t & Dest);
  void InitV10(LongCtrlInputV10::Daimler::LongCtrlInput_t & Dest);
  void InitV10(LongCtrlInputV10::Toyota::LongCtrlInput_t & Dest);
  void InitV11(LongCtrlInputV11::LongCtrlInputBase_t & Dest);
  void InitV11(LongCtrlInputV11::Daimler::LongCtrlInput_t & Dest);
  void InitV11(LongCtrlInputV11::Toyota::LongCtrlInput_t & Dest);
  void InitV11(LongCtrlInputV11::Toyota_2::LongCtrlInput_t & Dest);
  void InitV12(LongCtrlInputV12::LongCtrlInputBase_t & Dest);
  void InitV12(LongCtrlInputV12::Daimler::LongCtrlInput_t & Dest);
  void InitV12(LongCtrlInputV12::Toyota::LongCtrlInput_t & Dest);
  void InitV19(LongCtrlInputV19::LongCtrlInputBase_t & Dest);
  void InitV19(LongCtrlInputV19::Daimler::LongCtrlInput_t & Dest);
  void InitV19(LongCtrlInputV19::Toyota::LongCtrlInput_t & Dest);
  void InitV21(LongCtrlInputV21::LongCtrlInputBase_t & Dest);
  void InitV21(LongCtrlInputV21::Mitsubishi::LongCtrlInput_t & Dest);
  void InitV22(LongCtrlInputV22::LongCtrlInputBase_t & Dest);
  void InitV22(LongCtrlInputV22::Mitsubishi::LongCtrlInput_t & Dest);
  void InitV25(LongCtrlInputV25::LongCtrlInputBase_t & Dest);
  void InitV25(LongCtrlInputV25::Hyundai::LongCtrlInput_t & Dest);
  void InitV34(LongCtrlInputV34::LongCtrlInputBase_t & Dest);
  void InitV34(LongCtrlInputV34::Hyundai::LongCtrlInput_t & Dest);
  void Init(LongCtrlInputV6::Toyota::LongCtrlInputCustom_t & Dest);

  
public:

  static const char* GetConverterTypeName()
  {
    return "LongCtrlInput";
  }

  CConvLongCtrlInput(void);
  virtual ~CConvLongCtrlInput(void);

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
  static CVersionInfoImpl LONG_CTRL_INPUT_V5_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V6_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V7_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V9_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V10_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V11_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V12_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V18_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V19_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V21_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V22_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V25_VERSION;
  static CVersionInfoImpl LONG_CTRL_INPUT_V34_VERSION;

  enum eLongCtrlInputVersions
  {
    LONG_CTRL_DUMMY_INPUT,
    LONG_CTRL_INPUT_V5,
    LONG_CTRL_INPUT_V6_DAIMLER,
    LONG_CTRL_INPUT_V6_TOYOTA,
    LONG_CTRL_INPUT_V7_DAIMLER,
    LONG_CTRL_INPUT_V7_TOYOTA,
    LONG_CTRL_INPUT_V9_DAMILER,
    LONG_CTRL_INPUT_V9_TOYOTA,
    LONG_CTRL_INPUT_V10_DAIMLER,
    LONG_CTRL_INPUT_V10_TOYOTA,
    LONG_CTRL_INPUT_V11_DAIMLER,
    LONG_CTRL_INPUT_V11_TOYOTA,
    LONG_CTRL_INPUT_V11_TOYOTA_2,
    LONG_CTRL_INPUT_V12_DAIMLER,
    LONG_CTRL_INPUT_V12_TOYOTA,
    LONG_CTRL_INPUT_V19_DAIMLER,
    LONG_CTRL_INPUT_V19_TOYOTA,
    LONG_CTRL_INPUT_V21_MITSUBISHI,
    LONG_CTRL_INPUT_V22_MITSUBISHI,
    LONG_CTRL_INPUT_V25_HYUNDAI,
    LONG_CTRL_INPUT_V34_HYUNDAI,
    LONG_CTRL_INPUT_VERSION_COUNT
  };
  static unsigned long SUPPORTED_SIZE[LONG_CTRL_INPUT_VERSION_COUNT];
  static const CVersionInfoImpl * const LONG_CTRL_INPUT_VERSIONS[LONG_CTRL_INPUT_VERSION_COUNT];
};

CVersionInfoImpl CConvLongCtrlInput::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V5_VERSION(0, 0, 5);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V6_VERSION(0, 0, 6);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V7_VERSION(0, 0, 7);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V9_VERSION(0, 0, 9);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V10_VERSION(0, 0, 10);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V11_VERSION(0, 0, 11);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V12_VERSION(0, 0, 12);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V18_VERSION(0, 0, 18);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V19_VERSION(0, 0, 19);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V21_VERSION(0, 0, 21);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V22_VERSION(0, 0, 22);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V25_VERSION(0, 0, 25);
CVersionInfoImpl CConvLongCtrlInput::LONG_CTRL_INPUT_V34_VERSION(0, 0, 34);
static uint32 DummyVersion = 0xFFFFFFFFu;

unsigned long CConvLongCtrlInput::SUPPORTED_SIZE[CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT]=
{
  sizeof(DummyVersion),     //!< Special dummy for 4 byte version number only (i.e.: no ACC interface of FCT component)
  sizeof(LongCtrlInputV5::LongCtrlInput_t),
  sizeof(LongCtrlInputV6::Daimler::LongCtrlInput_t),
  sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t),
  sizeof(LongCtrlInputV7::Daimler::LongCtrlInput_t),
  sizeof(LongCtrlInputV7::Toyota::LongCtrlInput_t),
  sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t),
  sizeof(LongCtrlInputV9::Toyota::LongCtrlInput_t),
  sizeof(LongCtrlInputV10::Daimler::LongCtrlInput_t),
  sizeof(LongCtrlInputV10::Toyota::LongCtrlInput_t),
  sizeof(LongCtrlInputV11::Daimler::LongCtrlInput_t),
  sizeof(LongCtrlInputV11::Toyota::LongCtrlInput_t),
  sizeof(LongCtrlInputV11::Toyota_2::LongCtrlInput_t),
  sizeof(LongCtrlInputV12::Daimler::LongCtrlInput_t),
  sizeof(LongCtrlInputV12::Toyota::LongCtrlInput_t),
  sizeof(LongCtrlInputV19::Daimler::LongCtrlInput_t),
  sizeof(LongCtrlInputV19::Toyota::LongCtrlInput_t),
  sizeof(LongCtrlInputV21::Mitsubishi::LongCtrlInput_t),
  sizeof(LongCtrlInputV22::Mitsubishi::LongCtrlInput_t),
  sizeof(LongCtrlInputV25::Hyundai::LongCtrlInput_t),
  sizeof(LongCtrlInputV34::Hyundai::LongCtrlInput_t)
};

const CVersionInfoImpl * const CConvLongCtrlInput::LONG_CTRL_INPUT_VERSIONS[CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT] =
{
  &BASE_VERSION,
  &LONG_CTRL_INPUT_V5_VERSION,
  &LONG_CTRL_INPUT_V6_VERSION,
  &LONG_CTRL_INPUT_V6_VERSION,
  &LONG_CTRL_INPUT_V7_VERSION,
  &LONG_CTRL_INPUT_V7_VERSION,
  &LONG_CTRL_INPUT_V9_VERSION,
  &LONG_CTRL_INPUT_V9_VERSION,
  &LONG_CTRL_INPUT_V10_VERSION,
  &LONG_CTRL_INPUT_V10_VERSION,
  &LONG_CTRL_INPUT_V11_VERSION,
  &LONG_CTRL_INPUT_V11_VERSION,
  &LONG_CTRL_INPUT_V12_VERSION,
  &LONG_CTRL_INPUT_V12_VERSION,
  &LONG_CTRL_INPUT_V18_VERSION,
  &LONG_CTRL_INPUT_V19_VERSION,
  &LONG_CTRL_INPUT_V21_VERSION,
  &LONG_CTRL_INPUT_V22_VERSION,
  &LONG_CTRL_INPUT_V25_VERSION,
  &LONG_CTRL_INPUT_V34_VERSION
};

CConvLongCtrlInput::CConvLongCtrlInput(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_LongCtrlInputV5(), m_LongCtrlInputV6(), m_LongCtrlInputV7(), m_LongCtrlInputV9(), m_LongCtrlInputV10(), m_LongCtrlInputV11(), m_LongCtrlInputV12(), m_LongCtrlInputV19(), m_LongCtrlInputV21(), m_LongCtrlInputV22(), m_LongCtrlInputV25(), m_LongCtrlInputV34()
{
  InitV5(m_LongCtrlInputV5);
  InitV6(m_LongCtrlInputV6.Base);
  InitV7(m_LongCtrlInputV7.Base);
  InitV9(m_LongCtrlInputV9.Base);
  InitV10(m_LongCtrlInputV10.Base);
  InitV11(m_LongCtrlInputV11.Base);
  InitV12(m_LongCtrlInputV12.Base);
  InitV19(m_LongCtrlInputV19.Base);
  InitV21(m_LongCtrlInputV21.Base);
  InitV22(m_LongCtrlInputV22.Base);
  InitV25(m_LongCtrlInputV25.Base);
  InitV34(m_LongCtrlInputV34.Base);
}

CConvLongCtrlInput::~CConvLongCtrlInput(void)
{
}

void CConvLongCtrlInput::InitV5(LongCtrlInputV5::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 5;
}

void CConvLongCtrlInput::InitV6(LongCtrlInputV6::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 6;
  Dest.sSigHeader.eSigStatus  = LongCtrlInputV5::AL_SIG_STATE_INIT;
}

void CConvLongCtrlInput::InitV6(LongCtrlInputV6::Daimler::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 6;
}

void CConvLongCtrlInput::InitV6(LongCtrlInputV6::Toyota::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 6;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Init(Dest.Custom);
}

void CConvLongCtrlInput::InitV7(LongCtrlInputV7::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 7;
  Dest.sSigHeader.eSigStatus  = LongCtrlInputV5::AL_SIG_STATE_INIT;
}

void CConvLongCtrlInput::InitV7(LongCtrlInputV7::Daimler::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 7;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Dest.Custom.SPCR.SPCR_Md          = 0;
  Dest.Custom.SPCR.SPCR_Excpt_Rq_V2 = 0;
  Dest.Custom.SPCR.SPCR_AS_Off_Rq   = 0;
  Dest.Custom.SPCR.SPCR_AS_Dsabl    = 0;
  Dest.Custom.SPCR.SPCR_Veh_Immo    = 0;
  Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs = 0;
}

void CConvLongCtrlInput::InitV7(LongCtrlInputV7::Toyota::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 7;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Dest.Custom.EngineEcuInput.ACCSTAT    = 1;    /* ACCSTAT_ACTIVE_OR_OVERRIDE */
  Dest.Custom.EngineEcuInput.LTME2      = 2;    /* LTME2_VEH_FOLLOW_TIME_MIDDLE */
  Dest.Custom.EngineEcuInput.VM         = 100;  /* Setspeed 100 km/h*/
  Dest.Custom.EngineEcuInput.ACCREQ     = 4;
  Dest.Custom.EngineEcuInput.INTG       = 1;
  Dest.Custom.EngineEcuInput.LCCHK      = 0;
  Dest.Custom.EngineEcuInput.LCCW2      = 0;
  Dest.Custom.EngineEcuInput.SLTACC     = 2;
  Dest.Custom.EngineEcuInput.SPDSTAT    = 8;
  Dest.Custom.EngineEcuInput.STPBZ      = 0;
  Dest.Custom.EngineEcuInput.XACCACT    = 1;
  Dest.Custom.EngineEcuInput.XCCOK2     = 1;
  Dest.Custom.EngineEcuInput.XLDR       = 1;
}

void CConvLongCtrlInput::InitV9(LongCtrlInputV9::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 9;
}

void CConvLongCtrlInput::InitV9(LongCtrlInputV9::Daimler::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 9;
}

void CConvLongCtrlInput::InitV9(LongCtrlInputV9::Toyota::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 9;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Init(Dest.Custom);
#if 0
  Dest.Custom.EngineEcuInput.ACCSTAT    = 1;    /* ACCSTAT_ACTIVE_OR_OVERRIDE */
  Dest.Custom.EngineEcuInput.LTME2      = 2;    /* LTME2_VEH_FOLLOW_TIME_MIDDLE */
  Dest.Custom.EngineEcuInput.VM         = 100;  /* Setspeed 100 km/h*/
  Dest.Custom.EngineEcuInput.ACCREQ     = 4;
  Dest.Custom.EngineEcuInput.INTG       = 1;
  Dest.Custom.EngineEcuInput.LCCHK      = 0;
  Dest.Custom.EngineEcuInput.SLTACC     = 2;
  Dest.Custom.EngineEcuInput.SPDSTAT    = 8;
  Dest.Custom.EngineEcuInput.STPBZ      = 0;
  Dest.Custom.EngineEcuInput.XACCACT    = 1;
  Dest.Custom.EngineEcuInput.XCCOK2     = 1;
  Dest.Custom.EngineEcuInput.XLDR       = 1;
#endif
}

void CConvLongCtrlInput::InitV10(LongCtrlInputV10::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 10;
}

void CConvLongCtrlInput::InitV10(LongCtrlInputV10::Daimler::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 10;
}

void CConvLongCtrlInput::InitV10(LongCtrlInputV10::Toyota::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 10;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Init(Dest.Custom);
#if 0
  Dest.Custom.EngineEcuInput.ACCSTAT    = 1;    /* ACCSTAT_ACTIVE_OR_OVERRIDE */
  Dest.Custom.EngineEcuInput.LTME2      = 2;    /* LTME2_VEH_FOLLOW_TIME_MIDDLE */
  Dest.Custom.EngineEcuInput.VM         = 100;  /* Setspeed 100 km/h*/
  Dest.Custom.EngineEcuInput.ACCREQ     = 4;
  Dest.Custom.EngineEcuInput.INTG       = 1;
  Dest.Custom.EngineEcuInput.LCCHK      = 0;
  Dest.Custom.EngineEcuInput.SLTACC     = 2;
  Dest.Custom.EngineEcuInput.SPDSTAT    = 8;
  Dest.Custom.EngineEcuInput.STPBZ      = 0;
  Dest.Custom.EngineEcuInput.XACCACT    = 1;
  Dest.Custom.EngineEcuInput.XCCOK2     = 1;
  Dest.Custom.EngineEcuInput.XLDR       = 1;
#endif
}

void CConvLongCtrlInput::InitV11(LongCtrlInputV11::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 11;
}

void CConvLongCtrlInput::InitV11(LongCtrlInputV11::Daimler::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 11;
}

void CConvLongCtrlInput::InitV11(LongCtrlInputV11::Toyota::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  
  Dest.uiVersionNumber  = 11;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
  Dest.Custom.EngineEcuInput.Ext_AccMode = 0;
  Dest.Custom.EngineEcuInput.Ext_AccState = 0;
  Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 0;
  Dest.Custom.EngineEcuInput.Ext_SetSpeed = 0;
  Dest.Custom.EngineEcuInput.ACCSTAT    = 1;    /* ACCSTAT_ACTIVE_OR_OVERRIDE */
  Dest.Custom.EngineEcuInput.LTME2      = 2;    /* LTME2_VEH_FOLLOW_TIME_MIDDLE */
  Dest.Custom.EngineEcuInput.VM         = 100;  /* Setspeed 100 km/h*/
  Dest.Custom.EngineEcuInput.ACCREQ     = 4;
  Dest.Custom.EngineEcuInput.INTG       = 1;
  Dest.Custom.EngineEcuInput.LCCHK      = 0;
  Dest.Custom.EngineEcuInput.SLTACC     = 2;
  Dest.Custom.EngineEcuInput.SPDSTAT    = 8;
  Dest.Custom.EngineEcuInput.STPBZ      = 0;
  Dest.Custom.EngineEcuInput.XACCACT    = 1;
  Dest.Custom.EngineEcuInput.XCCOK2     = 1;
  Dest.Custom.EngineEcuInput.XLDR       = 1;
}

void CConvLongCtrlInput::InitV11(LongCtrlInputV11::Toyota_2::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  
  Dest.uiVersionNumber  = 11;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Dest.Custom.EngineEcuInput.ACCSTAT    = 1;    /* ACCSTAT_ACTIVE_OR_OVERRIDE */
  Dest.Custom.EngineEcuInput.LTME2      = 2;    /* LTME2_VEH_FOLLOW_TIME_MIDDLE */
  Dest.Custom.EngineEcuInput.VM         = 100;  /* Setspeed 100 km/h*/
  Dest.Custom.EngineEcuInput.ACCREQ     = 4;
  Dest.Custom.EngineEcuInput.INTG       = 1;
  Dest.Custom.EngineEcuInput.LCCHK      = 0;
  Dest.Custom.EngineEcuInput.LCCW2      = 0;
  Dest.Custom.EngineEcuInput.SLTACC     = 2;
  Dest.Custom.EngineEcuInput.SPDSTAT    = 8;
  Dest.Custom.EngineEcuInput.STPBZ      = 0;
  Dest.Custom.EngineEcuInput.XACCACT    = 1;
  Dest.Custom.EngineEcuInput.XCCOK2     = 1;
  Dest.Custom.EngineEcuInput.XLDR       = 1;
}

void CConvLongCtrlInput::InitV12(LongCtrlInputV12::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 12;
}

void CConvLongCtrlInput::InitV12(LongCtrlInputV12::Daimler::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 12;
}

void CConvLongCtrlInput::InitV12(LongCtrlInputV12::Toyota::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  
  Dest.uiVersionNumber  = 12;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
  Dest.Custom.EngineEcuInput.Ext_AccMode = 0;
  Dest.Custom.EngineEcuInput.Ext_AccState = 0;
  Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 0;
  Dest.Custom.EngineEcuInput.Ext_SetSpeed = 0;
 // Dest.Custom.EngineEcuInput.ACCSTAT    = 1;    /* ACCSTAT_ACTIVE_OR_OVERRIDE */
 // Dest.Custom.EngineEcuInput.LTME2      = 2;    /* LTME2_VEH_FOLLOW_TIME_MIDDLE */
 // Dest.Custom.EngineEcuInput.VM         = 100;  /* Setspeed 100 km/h*/
  /*Dest.Custom.EngineEcuInput.ACCREQ     = 4;
  Dest.Custom.EngineEcuInput.INTG       = 1;
  Dest.Custom.EngineEcuInput.LCCHK      = 0;
  Dest.Custom.EngineEcuInput.SLTACC     = 2;
  Dest.Custom.EngineEcuInput.SPDSTAT    = 8;
  Dest.Custom.EngineEcuInput.STPBZ      = 0;
  Dest.Custom.EngineEcuInput.XACCACT    = 1;
  Dest.Custom.EngineEcuInput.XCCOK2     = 1;
  Dest.Custom.EngineEcuInput.XLDR       = 1; */
}

void CConvLongCtrlInput::InitV19(LongCtrlInputV19::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 19;
}

void CConvLongCtrlInput::InitV19(LongCtrlInputV19::Daimler::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));

  Dest.Navi_Input.e_NavStreetType = 0;
  
  Dest.SLA_Input.e_SLA_Setting = 0;
  Dest.SLA_Input.e_SLA_SpeedLimitNextType = 0;
  Dest.SLA_Input.e_SLA_SpeedLimitUnit = 0; /* KMH */
  Dest.SLA_Input.u_SLA_SpeedLimitNext = 0;
  Dest.SLA_Input.u_SLA_SpeedLimitNextDistance = 0;
  Dest.SLA_Input.u_SLA_SpeedLimitNow = 0;

  Dest.TSA_Input.e_TSA_SpeedUnit = 0; /* KMH */
  Dest.TSA_Input.s_TSA_SpeedOffset = 0;

  Dest.uiVersionNumber  = 19;
}

void CConvLongCtrlInput::InitV19(LongCtrlInputV19::Toyota::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  
  Dest.uiVersionNumber  = 19;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Dest.Custom.EngineEcuInput.ACCSTAT    = 1;    /* ACCSTAT_ACTIVE_OR_OVERRIDE */
  Dest.Custom.EngineEcuInput.LTME2      = 2;    /* LTME2_VEH_FOLLOW_TIME_MIDDLE */
  Dest.Custom.EngineEcuInput.VM         = 100;  /* Setspeed 100 km/h*/
  Dest.Custom.EngineEcuInput.ACCREQ     = 4;
  Dest.Custom.EngineEcuInput.INTG       = 1;
  Dest.Custom.EngineEcuInput.LCCHK      = 0;
  Dest.Custom.EngineEcuInput.SLTACC     = 2;
  Dest.Custom.EngineEcuInput.SPDSTAT    = 8;
  Dest.Custom.EngineEcuInput.STPBZ      = 0;
  Dest.Custom.EngineEcuInput.XACCACT    = 1;
  Dest.Custom.EngineEcuInput.XCCOK2     = 1;
  Dest.Custom.EngineEcuInput.XLDR       = 1; 
}

void CConvLongCtrlInput::InitV21(LongCtrlInputV21::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 21;
}

void CConvLongCtrlInput::InitV21(LongCtrlInputV21::Mitsubishi::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  
  Dest.uiVersionNumber  = 21;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Dest.Custom.MMCIn.bAccsShftPos        = 1;
  Dest.Custom.MMCIn.ACCS_state_eng      = 1;
}

void CConvLongCtrlInput::InitV22(LongCtrlInputV22::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 22;
}

void CConvLongCtrlInput::InitV22(LongCtrlInputV22::Mitsubishi::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  
  Dest.uiVersionNumber  = 22;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/
  Dest.Custom.MMCIn.bAccsShftPos        = 1;
  Dest.Custom.MMCIn.ACCS_state_eng      = 1;
}

void CConvLongCtrlInput::InitV25(LongCtrlInputV25::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 25;
}

void CConvLongCtrlInput::InitV34(LongCtrlInputV34::LongCtrlInputBase_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  Dest.uiVersionNumber  = 34;
}

void CConvLongCtrlInput::InitV25(LongCtrlInputV25::Hyundai::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  
  Dest.uiVersionNumber  = 25;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/

  Dest.Custom.HMCIn.driving_mode_init = 1;
}

void CConvLongCtrlInput::InitV34(LongCtrlInputV34::Hyundai::LongCtrlInput_t & Dest)
{
  memset(&Dest, 0, sizeof(Dest));
  
  Dest.uiVersionNumber  = 34;
  Dest.DisplayOutput.speedometer_speed  = 1;    /* factor 0.01 */
  Dest.DisplayOutput.speed_unit         = 0;    /* speed_unit_kmh*/

  Dest.Custom.HMCIn.driving_mode_init = 1;

}

void CConvLongCtrlInput::Init(LongCtrlInputV6::Toyota::LongCtrlInputCustom_t & Dest)
{
  Dest.EngineEcuInput.ACCSTAT    = 1;    /* ACCSTAT_ACTIVE_OR_OVERRIDE */
  Dest.EngineEcuInput.LTME2      = 2;    /* LTME2_VEH_FOLLOW_TIME_MIDDLE */
  Dest.EngineEcuInput.VM         = 100;  /* Setspeed 100 km/h*/
  Dest.EngineEcuInput.ACCREQ     = 4;
  Dest.EngineEcuInput.INTG       = 1;
  Dest.EngineEcuInput.LCCHK      = 0;
  Dest.EngineEcuInput.SLTACC     = 2;
  Dest.EngineEcuInput.SPDSTAT    = 8;
  Dest.EngineEcuInput.STPBZ      = 0;
  Dest.EngineEcuInput.XACCACT    = 1;
  Dest.EngineEcuInput.XCCOK2     = 1;
  Dest.EngineEcuInput.XLDR       = 1;
}

long CConvLongCtrlInput::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo,
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const uint32 version = (ulPPortSize >= 4)?(*reinterpret_cast<const uint32*>(pPPortData)):0;  // See if conversion is needed
  CVersionInfoImpl VersionFromData(CONV_I32VERSION_TO_TUPPLE(version));

  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (((pProvidePortVersionInfo == NULL) && (VersionFromData.Equals(&requestPortVersionInfo))) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))))
  {
    // Ports match 1-1 no conversion needed
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  else
  {
    // Conversion needed: on first level see what destination we have to convert to
     if ((ulRPortSize == sizeof(LongCtrlInputV34::Hyundai::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V34_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV34::Hyundai::LongCtrlInput_t & Dest = m_LongCtrlInputV34.Hyundai;
      if ((ulPPortSize == sizeof(LongCtrlInputV25::Hyundai::LongCtrlInput_t)) &&
         (version == 25u))
       {
         const LongCtrlInputV25::Hyundai::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV25::Hyundai::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV19::Toyota::LongCtrlInput_t)) &&
         (version == 19u))
       {
         const LongCtrlInputV19::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV19::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV12::Toyota::LongCtrlInput_t)) &&
         (version == 12u))
       {
         const LongCtrlInputV12::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV12::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV11::Toyota_2::LongCtrlInput_t)) &&      //TBD: ist wirklich notwendig???
         (version == 11u))
       {
         const LongCtrlInputV11::Toyota_2::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV11::Toyota_2::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV11::Toyota::LongCtrlInput_t)) &&
         (version == 11u))
       {
         const LongCtrlInputV11::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV11::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV10::Toyota::LongCtrlInput_t)) &&
         (version == 10u))
       {
         const LongCtrlInputV10::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Toyota::LongCtrlInput_t)) &&
         (version == 9u))
       {
         const LongCtrlInputV9::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV7::Daimler::LongCtrlInput_t)) &&
         (version == 7u))
       {
         const LongCtrlInputV7::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV7::Daimler::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV7::Toyota::LongCtrlInput_t)) &&
         (version == 7u))
       {
         const LongCtrlInputV7::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV7::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t)) &&
         (version == 6u))
       {
         const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
         (version == 5u))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV25::Hyundai::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V25_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV25::Hyundai::LongCtrlInput_t & Dest = m_LongCtrlInputV25.Hyundai;
      if ((ulPPortSize == sizeof(LongCtrlInputV19::Toyota::LongCtrlInput_t)) &&
         (version == 19u))
       {
         const LongCtrlInputV19::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV19::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV12::Toyota::LongCtrlInput_t)) &&
         (version == 12u))
       {
         const LongCtrlInputV12::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV12::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV11::Toyota_2::LongCtrlInput_t)) &&      //TBD: ist wirklich notwendig???
         (version == 11u))
       {
         const LongCtrlInputV11::Toyota_2::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV11::Toyota_2::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV11::Toyota::LongCtrlInput_t)) &&
         (version == 11u))
       {
         const LongCtrlInputV11::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV11::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV10::Toyota::LongCtrlInput_t)) &&
         (version == 10u))
       {
         const LongCtrlInputV10::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Toyota::LongCtrlInput_t)) &&
         (version == 9u))
       {
         const LongCtrlInputV9::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV7::Daimler::LongCtrlInput_t)) &&
         (version == 7u))
       {
         const LongCtrlInputV7::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV7::Daimler::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV7::Toyota::LongCtrlInput_t)) &&
         (version == 7u))
       {
         const LongCtrlInputV7::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV7::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t)) &&
         (version == 6u))
       {
         const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
         (version == 5u))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.Custom.HMCIn.driving_mode_init               = 1;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV22::Mitsubishi::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V22_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV22::Mitsubishi::LongCtrlInput_t & Dest = m_LongCtrlInputV22.Mitsubishi;
      if ((ulPPortSize == sizeof(LongCtrlInputV21::Mitsubishi::LongCtrlInput_t)) &&
         (version == 21u) || (version == 15u))
      {
        const LongCtrlInputV21::Mitsubishi::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV21::Mitsubishi::LongCtrlInput_t*>(pPPortData);

        Dest.sSigHeader = Src.sSigHeader;

        Dest.Custom.CustomSignalState                  = Src.Custom.CustomSignalState;
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;

        Dest.Custom.MMCIn.ACCS_SeriousFail             = Src.Custom.MMCIn.ACCS_SeriousFail;
        Dest.Custom.MMCIn.ACCS_state_eng               = Src.Custom.MMCIn.ACCS_state_eng;
        Dest.Custom.MMCIn.ACCS_TempFail                = Src.Custom.MMCIn.ACCS_TempFail;
        Dest.Custom.MMCIn.bAccsShftPos                 = Src.Custom.MMCIn.bAccsShftPos;
        Dest.Custom.MMCIn.bACCS_BlockageDisp           = Src.Custom.MMCIn.bACCS_BlockageDisp;
        Dest.Custom.MMCIn.bACCS_Limit_Grade            = Src.Custom.MMCIn.bACCS_Limit_Grade;
        Dest.Custom.MMCIn.bACCS_TempDisp               = Src.Custom.MMCIn.bACCS_TempDisp;
        Dest.Custom.MMCIn.bAirbag_Deploy               = Src.Custom.MMCIn.bAirbag_Deploy;
        Dest.Custom.MMCIn.bEPB_Fail                    = Src.Custom.MMCIn.bEPB_Fail;
        Dest.Custom.MMCIn.eASG_status                  = Src.Custom.MMCIn.eASG_status;
        Dest.Custom.MMCIn.eAuto_Hold_Status            = Src.Custom.MMCIn.eAuto_Hold_Status;
        
        memcpy(&Dest.Custom.SPCR,     &Src.Custom.SPCR,     sizeof(Dest.Custom.SPCR));
        memcpy(&Dest.DisplayOutput,   &Src.DisplayOutput,   sizeof(Dest.DisplayOutput));
        memcpy(&Dest.KinCtrlDynInput, &Src.KinCtrlDynInput, sizeof(Dest.KinCtrlDynInput));

        Dest.uiVersionNumber  = 22;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV10::Daimler::LongCtrlInput_t)) &&
         (version == 10u))
      {
        const LongCtrlInputV10::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.sSigHeader = Src.sSigHeader;

        memcpy(&Dest.Custom.SPCR, &Src.Custom.SPCR, sizeof(Dest.Custom.SPCR));
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
        Dest.Custom.CustomSignalState                  = Src.Custom.CustomSignalState;
        Dest.Custom.MMCIn.ACCS_SeriousFail             = 0;
        Dest.Custom.MMCIn.ACCS_state_eng               = 1;
        Dest.Custom.MMCIn.ACCS_TempFail                = 0;
        Dest.Custom.MMCIn.bAccsShftPos                 = 1;
        Dest.Custom.MMCIn.bACCS_ASG_type               = 1;
        Dest.Custom.MMCIn.bACCS_BlockageDisp           = 0;
        Dest.Custom.MMCIn.bACCS_Limit_Grade            = 0;
        Dest.Custom.MMCIn.bACCS_TempDisp               = 0;
        Dest.Custom.MMCIn.bAirbag_Deploy               = 0;
        Dest.Custom.MMCIn.bEPB_Fail                    = 0;
        Dest.Custom.MMCIn.bFCMB_start                  = 0;
        Dest.Custom.MMCIn.bSPM_selftest_active         = 0;
        Dest.Custom.MMCIn.eASG_status                  = 0;
        Dest.Custom.MMCIn.eAuto_Hold_Status            = 0;

        Dest.DisplayOutput.speedometer_speed = Src.DisplayOutput.speedometer_speed;
        Dest.DisplayOutput.speed_unit        = Src.DisplayOutput.speed_unit;

        Dest.KinCtrlDynInput.longi_initialization_accel  = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.perm_lim_setspeed           = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.var_lim_eng                 = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.stand_still_detected        = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.DC_status_information       = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.driver_override_accel_pedal = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.driver_braking              = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.DAS_accel_request_limited   = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited   = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged  = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.ldm_ctrl_state              = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.acc_enable                  = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.park_brk_eng                = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.brk_sw                      = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.door_state                  = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.country_code                = Src.KinCtrlDynInput.country_code;

        Dest.uiVersionNumber  = 22;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV7::Daimler::LongCtrlInput_t)) &&
         (version == 7u))
       {
         const LongCtrlInputV7::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV7::Daimler::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         memcpy(&Dest.Custom.SPCR, &Src.Custom.SPCR, sizeof(Dest.Custom.SPCR));
         Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
         Dest.Custom.CustomSignalState                     = 0;
         Dest.Custom.MMCIn.ACCS_SeriousFail                = 0;
         Dest.Custom.MMCIn.ACCS_state_eng                  = 1;
         Dest.Custom.MMCIn.ACCS_TempFail                   = 0;
         Dest.Custom.MMCIn.bAccsShftPos                    = 1;
         Dest.Custom.MMCIn.bACCS_ASG_type                  = 1;
         Dest.Custom.MMCIn.bACCS_BlockageDisp              = 0;
         Dest.Custom.MMCIn.bACCS_Limit_Grade               = 0;
         Dest.Custom.MMCIn.bACCS_TempDisp                  = 0;
         Dest.Custom.MMCIn.bAirbag_Deploy                  = 0;
         Dest.Custom.MMCIn.bEPB_Fail                       = 0;
         Dest.Custom.MMCIn.bFCMB_start                     = 0;
         Dest.Custom.MMCIn.bSPM_selftest_active            = 0;
         Dest.Custom.MMCIn.eASG_status                     = 0;
         Dest.Custom.MMCIn.eAuto_Hold_Status               = 0;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
      }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV21::Mitsubishi::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V21_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV21::Mitsubishi::LongCtrlInput_t & Dest = m_LongCtrlInputV21.Mitsubishi;
      if ((ulPPortSize == sizeof(LongCtrlInputV22::Mitsubishi::LongCtrlInput_t)) &&
         (version == 22u))
      {
        const LongCtrlInputV22::Mitsubishi::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV22::Mitsubishi::LongCtrlInput_t*>(pPPortData);
        
        Dest.sSigHeader = Src.sSigHeader;

        Dest.Custom.CustomSignalState                  = Src.Custom.CustomSignalState;
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;

        Dest.Custom.MMCIn.ACCS_SeriousFail             = Src.Custom.MMCIn.ACCS_SeriousFail;
        Dest.Custom.MMCIn.ACCS_state_eng               = Src.Custom.MMCIn.ACCS_state_eng;
        Dest.Custom.MMCIn.ACCS_TempFail                = Src.Custom.MMCIn.ACCS_TempFail;
        Dest.Custom.MMCIn.bAccsShftPos                 = Src.Custom.MMCIn.bAccsShftPos;
        Dest.Custom.MMCIn.bACCS_BlockageDisp           = Src.Custom.MMCIn.bACCS_BlockageDisp;
        Dest.Custom.MMCIn.bACCS_Limit_Grade            = Src.Custom.MMCIn.bACCS_Limit_Grade;
        Dest.Custom.MMCIn.bACCS_TempDisp               = Src.Custom.MMCIn.bACCS_TempDisp;
        Dest.Custom.MMCIn.bAirbag_Deploy               = Src.Custom.MMCIn.bAirbag_Deploy;
        Dest.Custom.MMCIn.bEPB_Fail                    = Src.Custom.MMCIn.bEPB_Fail;
        Dest.Custom.MMCIn.eASG_status                  = Src.Custom.MMCIn.eASG_status;
        Dest.Custom.MMCIn.eAuto_Hold_Status            = Src.Custom.MMCIn.eAuto_Hold_Status;
        
        memcpy(&Dest.Custom.SPCR,     &Src.Custom.SPCR,     sizeof(Dest.Custom.SPCR));
        memcpy(&Dest.DisplayOutput,   &Src.DisplayOutput,   sizeof(Dest.DisplayOutput));
        memcpy(&Dest.KinCtrlDynInput, &Src.KinCtrlDynInput, sizeof(Dest.KinCtrlDynInput));

        Dest.uiVersionNumber  = 21;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV10::Daimler::LongCtrlInput_t)) &&
         (version == 10u))
      {
        const LongCtrlInputV10::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Daimler::LongCtrlInput_t*>(pPPortData);
        
        Dest.sSigHeader = Src.sSigHeader;

        memcpy(&Dest.Custom.SPCR, &Src.Custom.SPCR, sizeof(Dest.Custom.SPCR));
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
        Dest.Custom.CustomSignalState                  = Src.Custom.CustomSignalState;

        Dest.DisplayOutput.speedometer_speed = Src.DisplayOutput.speedometer_speed;
        Dest.DisplayOutput.speed_unit        = Src.DisplayOutput.speed_unit;

        Dest.KinCtrlDynInput.longi_initialization_accel  = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.perm_lim_setspeed           = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.var_lim_eng                 = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.stand_still_detected        = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.DC_status_information       = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.driver_override_accel_pedal = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.driver_braking              = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.DAS_accel_request_limited   = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited   = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged  = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.ldm_ctrl_state              = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.acc_enable                  = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.park_brk_eng                = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.brk_sw                      = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.door_state                  = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.country_code                = Src.KinCtrlDynInput.country_code;

        Dest.uiVersionNumber  = 21;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV19::Daimler::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V19_VERSION)) || (requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V18_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV19::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV19.Daimler;
      if ((ulPPortSize == sizeof(LongCtrlInputV12::Daimler::LongCtrlInput_t)) &&
         (version == 12u))
      {
        const LongCtrlInputV12::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV12::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.DisplayOutputSignalState       = Src.DisplayOutput.DisplayOutputSignalState;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput                              = Src.KinCtrlDynInput;
        Dest.Custom                                       = Src.Custom;
        Dest.sSigHeader                                   = Src.sSigHeader;
        Dest.Navi_Input.e_NavStreetType = 0;
  
        Dest.SLA_Input.e_SLA_Setting = 0;
        Dest.SLA_Input.e_SLA_SpeedLimitNextType = 0;
        Dest.SLA_Input.e_SLA_SpeedLimitUnit = 0; /* KMH */
        Dest.SLA_Input.u_SLA_SpeedLimitNext = 0;
        Dest.SLA_Input.u_SLA_SpeedLimitNextDistance = 0;
        Dest.SLA_Input.u_SLA_SpeedLimitNow = 0;

        Dest.TSA_Input.e_TSA_SpeedUnit = 0; /* KMH */
        Dest.TSA_Input.s_TSA_SpeedOffset = 0;

        if(requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V18_VERSION))
        {
          /* Update correct version number */
          Dest.uiVersionNumber  = 18;
        }
        else
        {
          Dest.uiVersionNumber  = 19;
        }

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;

      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV11::Daimler::LongCtrlInput_t)) &&
         (version == 11u))
      {
        const LongCtrlInputV11::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV11::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.DisplayOutputSignalState       = Src.DisplayOutput.DisplayOutputSignalState;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput                              = Src.KinCtrlDynInput;
        Dest.Custom                                       = Src.Custom;
        Dest.sSigHeader                                   = Src.sSigHeader;
        Dest.Navi_Input.e_NavStreetType = 0;
  
        Dest.SLA_Input.e_SLA_Setting = 0;
        Dest.SLA_Input.e_SLA_SpeedLimitNextType = 0;
        Dest.SLA_Input.e_SLA_SpeedLimitUnit = 0; /* KMH */
        Dest.SLA_Input.u_SLA_SpeedLimitNext = 0;
        Dest.SLA_Input.u_SLA_SpeedLimitNextDistance = 0;
        Dest.SLA_Input.u_SLA_SpeedLimitNow = 0;

        Dest.TSA_Input.e_TSA_SpeedUnit = 0; /* KMH */
        Dest.TSA_Input.s_TSA_SpeedOffset = 0;

        if(requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V18_VERSION))
        {
          /* Update correct version number */
          Dest.uiVersionNumber  = 18;
        }
        else
        {
          Dest.uiVersionNumber  = 19;
        }

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;

      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV10::Daimler::LongCtrlInput_t)) &&
         (version == 10u))
      {
        const LongCtrlInputV10::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.DisplayOutputSignalState       = Src.DisplayOutput.DisplayOutputSignalState;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput                              = Src.KinCtrlDynInput;
        Dest.Custom                                       = Src.Custom;
        Dest.sSigHeader                                   = Src.sSigHeader;
        Dest.Navi_Input.e_NavStreetType = 0;
  
        Dest.SLA_Input.e_SLA_Setting = 0;
        Dest.SLA_Input.e_SLA_SpeedLimitNextType = 0;
        Dest.SLA_Input.e_SLA_SpeedLimitUnit = 0; /* KMH */
        Dest.SLA_Input.u_SLA_SpeedLimitNext = 0;
        Dest.SLA_Input.u_SLA_SpeedLimitNextDistance = 0;
        Dest.SLA_Input.u_SLA_SpeedLimitNow = 0;

        Dest.TSA_Input.e_TSA_SpeedUnit = 0; /* KMH */
        Dest.TSA_Input.s_TSA_SpeedOffset = 0;

        if(requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V18_VERSION))
        {
          /* Update correct version number */
          Dest.uiVersionNumber  = 18;
        }
        else
        {
          Dest.uiVersionNumber  = 19;
        }

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;

      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.DisplayOutputSignalState       = Src.DisplayOutput.DisplayOutputSignalState;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.Custom.CustomSignalState                     = Src.Custom.CustomSignalState;
        Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
        Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
        Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
        Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
        Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
        Dest.Navi_Input.e_NavStreetType = 0;
  
        Dest.SLA_Input.e_SLA_Setting = 0;
        Dest.SLA_Input.e_SLA_SpeedLimitNextType = 0;
        Dest.SLA_Input.e_SLA_SpeedLimitUnit = 0; /* KMH */
        Dest.SLA_Input.u_SLA_SpeedLimitNext = 0;
        Dest.SLA_Input.u_SLA_SpeedLimitNextDistance = 0;
        Dest.SLA_Input.u_SLA_SpeedLimitNow = 0;

        Dest.TSA_Input.e_TSA_SpeedUnit = 0; /* KMH */
        Dest.TSA_Input.s_TSA_SpeedOffset = 0;

        if(requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V18_VERSION))
        {
          /* Update correct version number */
          Dest.uiVersionNumber  = 18;
        }
        else
        {
          Dest.uiVersionNumber  = 19;
        }

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.DisplayOutputSignalState       = Src.DisplayOutput.DisplayOutputSignalState;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.Custom.CustomSignalState                     = Src.Custom.CustomSignalState;
        Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
        Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
        Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
        Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
        Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
        Dest.Navi_Input.e_NavStreetType = 0;
  
        Dest.SLA_Input.e_SLA_Setting = 0;
        Dest.SLA_Input.e_SLA_SpeedLimitNextType = 0;
        Dest.SLA_Input.e_SLA_SpeedLimitUnit = 0; /* KMH */
        Dest.SLA_Input.u_SLA_SpeedLimitNext = 0;
        Dest.SLA_Input.u_SLA_SpeedLimitNextDistance = 0;
        Dest.SLA_Input.u_SLA_SpeedLimitNow = 0;

        Dest.TSA_Input.e_TSA_SpeedUnit = 0; /* KMH */
        Dest.TSA_Input.s_TSA_SpeedOffset = 0;

        if(requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V18_VERSION))
        {
          /* Update correct version number */
          Dest.uiVersionNumber  = 18;
        }
        else
        {
          Dest.uiVersionNumber  = 19;
        }

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV6::Daimler::LongCtrlInput_t)) &&
         ((version == 6u) || (version == 7u)))
      {
         const LongCtrlInputV6::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Daimler::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.DisplayOutputSignalState       = 0;
         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.KinCtrlDynInput.KinCtrlSignalState           = 0;
         Dest.Custom.CustomSignalState                     = 0;
         Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
         Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
         Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
         Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
         Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
         Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else if ((ulPPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
         (version == 5u))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.DisplayOutputSignalState       = 0;
         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.KinCtrlDynInput.KinCtrlSignalState           = 0;
         Dest.Custom.CustomSignalState                     = 0;
         Dest.Custom.SPCR.SPCR_AS_Dsabl                    = 0;
         Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = 0;
         Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = 0;
         Dest.Custom.SPCR.SPCR_Md                          = 0;
         Dest.Custom.SPCR.SPCR_Veh_Immo                    = 0;
         Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = 0;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV19::Toyota::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V19_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV19::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV19.Toyota;
      if ((ulPPortSize == sizeof(LongCtrlInputV11::Toyota::LongCtrlInput_t)) &&
         ((version == 11u)||(version == 12u))
         ||
         /* workaround for version 18, since no change for Toyota (prevent definition of version 18) */
         (version == 18u))
      {
        const LongCtrlInputV10::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Toyota::LongCtrlInput_t*>(pPPortData);
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;

        Dest.sSigHeader       = Src.sSigHeader;
        Dest.KinCtrlDynInput  = Src.KinCtrlDynInput;
        Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;
        Dest.Custom.EngineEcuInput.XLDR  = Src.Custom.EngineEcuInput.XLDR;

        /* Changed data type from uint8 to uint16 */
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM *100;

        Dest.uiVersionNumber  = 12u;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV10::Toyota::LongCtrlInput_t)) &&
         ((version == 10u)||(version == 11u)))
      {
        const LongCtrlInputV10::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Toyota::LongCtrlInput_t*>(pPPortData);
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;

        Dest.sSigHeader       = Src.sSigHeader;
        Dest.KinCtrlDynInput  = Src.KinCtrlDynInput;
        Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;
        Dest.Custom.EngineEcuInput.XLDR  = Src.Custom.EngineEcuInput.XLDR;
        /* Changed data type from uint8 to uint16 */
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM *100;

        Dest.uiVersionNumber  = 12u;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Toyota::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Toyota::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;

        
#if 0
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
        Dest.sSigHeader       = Src.sSigHeader;
        Dest.KinCtrlDynInput  = Src.KinCtrlDynInput;
        Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;
        Dest.Custom.EngineEcuInput.XLDR  = Src.Custom.EngineEcuInput.XLDR;
        /* Changed data type from uint8 to uint16 */
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM *100;

#endif
        Dest.uiVersionNumber  = 12u;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t)) &&
         ((version == 6u) || (version == 7u)))
      {
         const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;

         
#if 0
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
         Dest.sSigHeader      = Src.sSigHeader;
#endif
        Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;
        /* Changed data type from uint8 to uint16 */
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM *100;

         Dest.uiVersionNumber = 12u;
         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       // Special work-around for unfilled ARS4T0 signals
       else if (sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t) == ulPPortSize)
       {
        const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

        if ( (Src.uiVersionNumber != 6)
          || (Src.Custom.EngineEcuInput.XLDR != 0)
          || (Src.Custom.EngineEcuInput.XACCACT != 0)
          || (Src.Custom.EngineEcuInput.STPBZ != 0)
          || (Src.Custom.EngineEcuInput.ACCREQ != 0)
          || (Src.Custom.EngineEcuInput.SPDSTAT != 0)
          || (Src.Custom.EngineEcuInput.ACCSTAT != 0)
          || (Src.Custom.EngineEcuInput.LCCHK != 0)
          || (Src.Custom.EngineEcuInput.VM != 0)
          || (Src.Custom.EngineEcuInput.XCCOK2 != 0)
          || (Src.Custom.EngineEcuInput.SLTACC != 0)
          || (Src.Custom.EngineEcuInput.LTME2 != 0)
          || (Src.Custom.EngineEcuInput.INTG != 0)
          )
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        else
        {
          // Work-around for activation with CAN where no Engine ECU input provided
          LongCtrlInputV6::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV6.Toyota;
          Dest.uiVersionNumber  = 6;
          Dest = Src;
          Init(Dest.Custom);
          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
       }
       else if ((ulPPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
         (version == 5u))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;

#if 0
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
         Dest.sSigHeader      = Src.sSigHeader;
#endif

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV12::Daimler::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V12_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV12::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV12.Daimler;
      if ((ulPPortSize == sizeof(LongCtrlInputV11::Daimler::LongCtrlInput_t)) &&
         (version == 11u))
      {
        const LongCtrlInputV11::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV11::Daimler::LongCtrlInput_t*>(pPPortData);

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;

      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV10::Daimler::LongCtrlInput_t)) &&
         (version == 10u))
      {
        const LongCtrlInputV10::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Daimler::LongCtrlInput_t*>(pPPortData);

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;

      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.DisplayOutputSignalState       = Src.DisplayOutput.DisplayOutputSignalState;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.Custom.CustomSignalState                     = Src.Custom.CustomSignalState;
        Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
        Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
        Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
        Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
        Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.DisplayOutputSignalState       = Src.DisplayOutput.DisplayOutputSignalState;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.Custom.CustomSignalState                     = Src.Custom.CustomSignalState;
        Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
        Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
        Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
        Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
        Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV6::Daimler::LongCtrlInput_t)) &&
         ((version == 6u) || (version == 7u)))
      {
         const LongCtrlInputV6::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Daimler::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.DisplayOutputSignalState       = 0;
         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.KinCtrlDynInput.KinCtrlSignalState           = 0;
         Dest.Custom.CustomSignalState                     = 0;
         Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
         Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
         Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
         Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
         Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
         Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else if ((ulPPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
         (version == 5u))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.DisplayOutputSignalState       = 0;
         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.KinCtrlDynInput.KinCtrlSignalState           = 0;
         Dest.Custom.CustomSignalState                     = 0;
         Dest.Custom.SPCR.SPCR_AS_Dsabl                    = 0;
         Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = 0;
         Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = 0;
         Dest.Custom.SPCR.SPCR_Md                          = 0;
         Dest.Custom.SPCR.SPCR_Veh_Immo                    = 0;
         Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = 0;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV12::Toyota::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V12_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV12::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV12.Toyota;

      if ((ulPPortSize == sizeof(LongCtrlInputV11::Toyota::LongCtrlInput_t)) &&
         ((version == 11u)||(version == 12u)))
      {
        const LongCtrlInputV10::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Toyota::LongCtrlInput_t*>(pPPortData);
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;

        Dest.sSigHeader       = Src.sSigHeader;
        Dest.KinCtrlDynInput  = Src.KinCtrlDynInput;
        /*Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;
        Dest.Custom.EngineEcuInput.XLDR  = Src.Custom.EngineEcuInput.XLDR; */
       
        Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
        Dest.Custom.EngineEcuInput.Ext_SetSpeed = Src.Custom.EngineEcuInput.VM;

        Dest.Custom.EngineEcuInput.Ext_AccMode = Src.Custom.EngineEcuInput.SLTACC;
        if(Src.Custom.EngineEcuInput.ACCSTAT == 0u /*ACCSTAT_DISENGAGE_OR_OFF*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 1u /*ACCSTAT_ACTIVE_OR_OVERRIDE*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 2u /*EXT_ACC_STATE_ACTIVE*/ ;
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 3u /*ACCSTAT_PB_RQ*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState =  4u;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        
        if(Src.Custom.EngineEcuInput.LTME2 == 3u /*LTME2_VEH_FOLLOW_TIME_SHORT=3*/)
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 1;
        }
        else if(Src.Custom.EngineEcuInput.LTME2 == 2/*LTME2_VEH_FOLLOW_TIME_MIDDLE=2*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 3u;
        }
        else if (Src.Custom.EngineEcuInput.LTME2 == 1 /*LTME2_VEH_FOLLOW_TIME_LONG=1*/ )
        {
           Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5; //Default
        }
        Dest.uiVersionNumber  = 12u;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV10::Toyota::LongCtrlInput_t)) &&
         ((version == 10u)||(version == 11u)))
      {
        const LongCtrlInputV10::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Toyota::LongCtrlInput_t*>(pPPortData);
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;

        Dest.sSigHeader       = Src.sSigHeader;
        Dest.KinCtrlDynInput  = Src.KinCtrlDynInput;
        /*Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;
        Dest.Custom.EngineEcuInput.XLDR  = Src.Custom.EngineEcuInput.XLDR;*/
       
        Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
        Dest.Custom.EngineEcuInput.Ext_SetSpeed = Src.Custom.EngineEcuInput.VM;
        Dest.Custom.EngineEcuInput.Ext_RequestedAccelAfterGradLim = 1;// new inputsignal version 12

        Dest.Custom.EngineEcuInput.Ext_AccMode = Src.Custom.EngineEcuInput.SLTACC;
        if(Src.Custom.EngineEcuInput.ACCSTAT == 0u /*ACCSTAT_DISENGAGE_OR_OFF*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 1u /*ACCSTAT_ACTIVE_OR_OVERRIDE*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 2u /*EXT_ACC_STATE_ACTIVE*/ ;
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 3u /*ACCSTAT_PB_RQ*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState =  4u;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        
        if(Src.Custom.EngineEcuInput.LTME2 == 3u /*LTME2_VEH_FOLLOW_TIME_SHORT=3*/)
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 1;
        }
        else if(Src.Custom.EngineEcuInput.LTME2 == 2/*LTME2_VEH_FOLLOW_TIME_MIDDLE=2*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 3u;
        }
        else if (Src.Custom.EngineEcuInput.LTME2 == 1 /*LTME2_VEH_FOLLOW_TIME_LONG=1*/ )
        {
           Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5; //Default
        }
        Dest.uiVersionNumber  = 12u;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Toyota::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Toyota::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;

        
#if 0
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
        Dest.sSigHeader       = Src.sSigHeader;
        Dest.KinCtrlDynInput  = Src.KinCtrlDynInput;
        /*Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;
        Dest.Custom.EngineEcuInput.XLDR  = Src.Custom.EngineEcuInput.XLDR;*/

        Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
        Dest.Custom.EngineEcuInput.Ext_SetSpeed = Src.Custom.EngineEcuInput.VM;
        Dest.Custom.EngineEcuInput.Ext_RequestedAccelAfterGradLim = 1;// new inputsignal version 12

        Dest.Custom.EngineEcuInput.Ext_AccMode = Src.Custom.EngineEcuInput.SLTACC;
        if(Src.Custom.EngineEcuInput.ACCSTAT == 0u /*ACCSTAT_DISENGAGE_OR_OFF*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 1u /*ACCSTAT_ACTIVE_OR_OVERRIDE*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 2u /*EXT_ACC_STATE_ACTIVE*/ ;
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 3u /*ACCSTAT_PB_RQ*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState =  4u;
        }
        else
        {
           Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        
        if(Src.Custom.EngineEcuInput.LTME2 == 3u /*LTME2_VEH_FOLLOW_TIME_SHORT=3*/)
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 1;
        }
        else if(Src.Custom.EngineEcuInput.LTME2 == 2/*LTME2_VEH_FOLLOW_TIME_MIDDLE=2*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 3u;
        }
        else if (Src.Custom.EngineEcuInput.LTME2 == 1 /*LTME2_VEH_FOLLOW_TIME_LONG=1*/ )
        {
           Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
#endif
        Dest.uiVersionNumber  = 12u;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t)) &&
         ((version == 6u) || (version == 7u)))
      {
         const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;

         
#if 0
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
         Dest.sSigHeader      = Src.sSigHeader;
#endif
        /*Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;*/
       
        Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
        Dest.Custom.EngineEcuInput.Ext_SetSpeed = Src.Custom.EngineEcuInput.VM;
        Dest.Custom.EngineEcuInput.Ext_RequestedAccelAfterGradLim = 1;// new inputsignal version 12

        Dest.Custom.EngineEcuInput.Ext_AccMode = Src.Custom.EngineEcuInput.SLTACC;
        if(Src.Custom.EngineEcuInput.ACCSTAT == 0u /*ACCSTAT_DISENGAGE_OR_OFF*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 1u /*ACCSTAT_ACTIVE_OR_OVERRIDE*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 2u /*EXT_ACC_STATE_ACTIVE*/ ;
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 3u /*ACCSTAT_PB_RQ*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState =  4u;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        
        if(Src.Custom.EngineEcuInput.LTME2 == 3u /*LTME2_VEH_FOLLOW_TIME_SHORT=3*/)
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 1;
        }
        else if(Src.Custom.EngineEcuInput.LTME2 == 2/*LTME2_VEH_FOLLOW_TIME_MIDDLE=2*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 3u;
        }
        else if (Src.Custom.EngineEcuInput.LTME2 == 1 /*LTME2_VEH_FOLLOW_TIME_LONG=1*/ )
        {
           Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
         Dest.uiVersionNumber = 12u;
         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       // Special work-around for unfilled ARS4T0 signals
       else if (sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t) == ulPPortSize)
       {
        const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

        if ( (Src.uiVersionNumber != 6)
          || (Src.Custom.EngineEcuInput.XLDR != 0)
          || (Src.Custom.EngineEcuInput.XACCACT != 0)
          || (Src.Custom.EngineEcuInput.STPBZ != 0)
          || (Src.Custom.EngineEcuInput.ACCREQ != 0)
          || (Src.Custom.EngineEcuInput.SPDSTAT != 0)
          || (Src.Custom.EngineEcuInput.ACCSTAT != 0)
          || (Src.Custom.EngineEcuInput.LCCHK != 0)
          || (Src.Custom.EngineEcuInput.VM != 0)
          || (Src.Custom.EngineEcuInput.XCCOK2 != 0)
          || (Src.Custom.EngineEcuInput.SLTACC != 0)
          || (Src.Custom.EngineEcuInput.LTME2 != 0)
          || (Src.Custom.EngineEcuInput.INTG != 0)
          )
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        else
        {
          // Work-around for activation with CAN where no Engine ECU input provided
          LongCtrlInputV6::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV6.Toyota;
          Dest.uiVersionNumber  = 6;
          Dest = Src;
          Init(Dest.Custom);
          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
       }
       else if ((ulPPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
         (version == 5u))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
        
         Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
         Dest.Custom.EngineEcuInput.Ext_AccMode = 0;
         Dest.Custom.EngineEcuInput.Ext_AccState = 0;
         Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 0;
         Dest.Custom.EngineEcuInput.Ext_RequestedAccelAfterGradLim = 1;// new inputsignal version 12
         
#if 0
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
         Dest.sSigHeader      = Src.sSigHeader;
#endif

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV11::Daimler::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V11_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV11::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV11.Daimler;
      if ((ulPPortSize == sizeof(LongCtrlInputV10::Daimler::LongCtrlInput_t)) &&
         (version == 10u))
      {
        const LongCtrlInputV10::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Daimler::LongCtrlInput_t*>(pPPortData);

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;

      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.DisplayOutputSignalState       = Src.DisplayOutput.DisplayOutputSignalState;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.Custom.CustomSignalState                     = Src.Custom.CustomSignalState;
        Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
        Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
        Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
        Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
        Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.DisplayOutputSignalState       = Src.DisplayOutput.DisplayOutputSignalState;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.Custom.CustomSignalState                     = Src.Custom.CustomSignalState;
        Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
        Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
        Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
        Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
        Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV6::Daimler::LongCtrlInput_t)) &&
         ((version == 6u) || (version == 7u)))
      {
         const LongCtrlInputV6::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Daimler::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.DisplayOutputSignalState       = 0;
         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.KinCtrlDynInput.KinCtrlSignalState           = 0;
         Dest.Custom.CustomSignalState                     = 0;
         Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
         Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
         Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
         Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
         Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
         Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else if ((ulPPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
         (version == 5u))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.DisplayOutputSignalState       = 0;
         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.KinCtrlDynInput.KinCtrlSignalState           = 0;
         Dest.Custom.CustomSignalState                     = 0;
         Dest.Custom.SPCR.SPCR_AS_Dsabl                    = 0;
         Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = 0;
         Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = 0;
         Dest.Custom.SPCR.SPCR_Md                          = 0;
         Dest.Custom.SPCR.SPCR_Veh_Immo                    = 0;
         Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = 0;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV11::Toyota::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V11_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV11::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV11.Toyota;

      if ((ulPPortSize == sizeof(LongCtrlInputV10::Toyota::LongCtrlInput_t)) &&
         ((version == 10u)||(version == 11u)))
      {
        const LongCtrlInputV10::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Toyota::LongCtrlInput_t*>(pPPortData);
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;

        Dest.sSigHeader       = Src.sSigHeader;
        Dest.KinCtrlDynInput  = Src.KinCtrlDynInput;
        Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;
        Dest.Custom.EngineEcuInput.XLDR  = Src.Custom.EngineEcuInput.XLDR;
       
        Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
        Dest.Custom.EngineEcuInput.Ext_SetSpeed = Src.Custom.EngineEcuInput.VM;

        Dest.Custom.EngineEcuInput.Ext_AccMode = Src.Custom.EngineEcuInput.SLTACC;
        if(Src.Custom.EngineEcuInput.ACCSTAT == 0u /*ACCSTAT_DISENGAGE_OR_OFF*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 1u /*ACCSTAT_ACTIVE_OR_OVERRIDE*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 2u /*EXT_ACC_STATE_ACTIVE*/ ;
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 3u /*ACCSTAT_PB_RQ*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState =  4u;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        
        if(Src.Custom.EngineEcuInput.LTME2 == 3u /*LTME2_VEH_FOLLOW_TIME_SHORT=3*/)
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 1;
        }
        else if(Src.Custom.EngineEcuInput.LTME2 == 2/*LTME2_VEH_FOLLOW_TIME_MIDDLE=2*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 3u;
        }
        else if (Src.Custom.EngineEcuInput.LTME2 == 1 /*LTME2_VEH_FOLLOW_TIME_LONG=1*/ )
        {
           Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5; //Default
        }
        Dest.uiVersionNumber  = 11u;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV9::Toyota::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Toyota::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;

        
#if 0
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
        Dest.sSigHeader       = Src.sSigHeader;
        Dest.KinCtrlDynInput  = Src.KinCtrlDynInput;
        Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;
        Dest.Custom.EngineEcuInput.XLDR  = Src.Custom.EngineEcuInput.XLDR;

        Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
        Dest.Custom.EngineEcuInput.Ext_SetSpeed = Src.Custom.EngineEcuInput.VM;

        Dest.Custom.EngineEcuInput.Ext_AccMode = Src.Custom.EngineEcuInput.SLTACC;
        if(Src.Custom.EngineEcuInput.ACCSTAT == 0u /*ACCSTAT_DISENGAGE_OR_OFF*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 1u /*ACCSTAT_ACTIVE_OR_OVERRIDE*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 2u /*EXT_ACC_STATE_ACTIVE*/ ;
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 3u /*ACCSTAT_PB_RQ*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState =  4u;
        }
        else
        {
           Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        
        if(Src.Custom.EngineEcuInput.LTME2 == 3u /*LTME2_VEH_FOLLOW_TIME_SHORT=3*/)
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 1;
        }
        else if(Src.Custom.EngineEcuInput.LTME2 == 2/*LTME2_VEH_FOLLOW_TIME_MIDDLE=2*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 3u;
        }
        else if (Src.Custom.EngineEcuInput.LTME2 == 1 /*LTME2_VEH_FOLLOW_TIME_LONG=1*/ )
        {
           Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
#endif
        Dest.uiVersionNumber  = 10u;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t)) &&
         ((version == 6u) || (version == 7u)))
      {
         const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;

         
#if 0
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
         Dest.sSigHeader      = Src.sSigHeader;
#endif
         Dest.Custom.EngineEcuInput.ACCREQ  = Src.Custom.EngineEcuInput.ACCREQ;
        Dest.Custom.EngineEcuInput.ACCSTAT  = Src.Custom.EngineEcuInput.ACCSTAT;
        Dest.Custom.EngineEcuInput.INTG  = Src.Custom.EngineEcuInput.INTG;
        Dest.Custom.EngineEcuInput.LCCHK  = Src.Custom.EngineEcuInput.LCCHK;
        Dest.Custom.EngineEcuInput.LTME2  = Src.Custom.EngineEcuInput.LTME2;
        Dest.Custom.EngineEcuInput.SLTACC  = Src.Custom.EngineEcuInput.SLTACC;
        Dest.Custom.EngineEcuInput.SPDSTAT  = Src.Custom.EngineEcuInput.SPDSTAT;
        Dest.Custom.EngineEcuInput.STPBZ  = Src.Custom.EngineEcuInput.STPBZ;
        Dest.Custom.EngineEcuInput.VM  = Src.Custom.EngineEcuInput.VM;
        Dest.Custom.EngineEcuInput.XACCACT  = Src.Custom.EngineEcuInput.XACCACT;
        Dest.Custom.EngineEcuInput.XCCOK2  = Src.Custom.EngineEcuInput.XCCOK2;
       
        Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
        Dest.Custom.EngineEcuInput.Ext_SetSpeed = Src.Custom.EngineEcuInput.VM;

        Dest.Custom.EngineEcuInput.Ext_AccMode = Src.Custom.EngineEcuInput.SLTACC;
        if(Src.Custom.EngineEcuInput.ACCSTAT == 0u /*ACCSTAT_DISENGAGE_OR_OFF*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 1u /*ACCSTAT_ACTIVE_OR_OVERRIDE*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 2u /*EXT_ACC_STATE_ACTIVE*/ ;
        }
        else if (Src.Custom.EngineEcuInput.ACCSTAT == 3u /*ACCSTAT_PB_RQ*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_AccState =  4u;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_AccState = 0U; //EXT_ACC_STATE_OFF
        }
        
        if(Src.Custom.EngineEcuInput.LTME2 == 3u /*LTME2_VEH_FOLLOW_TIME_SHORT=3*/)
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 1;
        }
        else if(Src.Custom.EngineEcuInput.LTME2 == 2/*LTME2_VEH_FOLLOW_TIME_MIDDLE=2*/ )
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 3u;
        }
        else if (Src.Custom.EngineEcuInput.LTME2 == 1 /*LTME2_VEH_FOLLOW_TIME_LONG=1*/ )
        {
           Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
        else
        {
          Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 5;
        }
         Dest.uiVersionNumber = 11u;
         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       // Special work-around for unfilled ARS4T0 signals
       else if (sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t) == ulPPortSize)
       {
        const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

        if ( (Src.uiVersionNumber != 6)
          || (Src.Custom.EngineEcuInput.XLDR != 0)
          || (Src.Custom.EngineEcuInput.XACCACT != 0)
          || (Src.Custom.EngineEcuInput.STPBZ != 0)
          || (Src.Custom.EngineEcuInput.ACCREQ != 0)
          || (Src.Custom.EngineEcuInput.SPDSTAT != 0)
          || (Src.Custom.EngineEcuInput.ACCSTAT != 0)
          || (Src.Custom.EngineEcuInput.LCCHK != 0)
          || (Src.Custom.EngineEcuInput.VM != 0)
          || (Src.Custom.EngineEcuInput.XCCOK2 != 0)
          || (Src.Custom.EngineEcuInput.SLTACC != 0)
          || (Src.Custom.EngineEcuInput.LTME2 != 0)
          || (Src.Custom.EngineEcuInput.INTG != 0)
          )
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        else
        {
          // Work-around for activation with CAN where no Engine ECU input provided
          LongCtrlInputV6::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV6.Toyota;
          Dest.uiVersionNumber  = 6;
          Dest = Src;
          Init(Dest.Custom);
          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
       }
       else if ((ulPPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
         (version == 5u))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
        
         Dest.Custom.EngineEcuInput.Ext_AccInhibitionRq_In = 0;
         Dest.Custom.EngineEcuInput.Ext_AccMode = 0;
         Dest.Custom.EngineEcuInput.Ext_AccState = 0;
         Dest.Custom.EngineEcuInput.Ext_HeadwaySetting = 0;

         
#if 0
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
         Dest.sSigHeader      = Src.sSigHeader;
#endif

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV10::Daimler::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V10_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV10::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV10.Daimler;

      if ((ulPPortSize == sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Daimler::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.DisplayOutputSignalState       = Src.DisplayOutput.DisplayOutputSignalState;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.Custom.CustomSignalState                     = Src.Custom.CustomSignalState;
        Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
        Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
        Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
        Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
        Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
        Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV6::Daimler::LongCtrlInput_t)) &&
         ((version == 6u) || (version == 7u)))
      {
         const LongCtrlInputV6::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Daimler::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.DisplayOutputSignalState       = 0;
         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.KinCtrlDynInput.KinCtrlSignalState           = 0;
         Dest.Custom.CustomSignalState                     = 0;
         Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
         Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
         Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
         Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
         Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
         Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else if ((ulPPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
         (version == 5u))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.DisplayOutputSignalState       = 0;
         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.KinCtrlDynInput.KinCtrlSignalState           = 0;
         Dest.Custom.CustomSignalState                     = 0;
         Dest.Custom.SPCR.SPCR_AS_Dsabl                    = 0;
         Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = 0;
         Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = 0;
         Dest.Custom.SPCR.SPCR_Md                          = 0;
         Dest.Custom.SPCR.SPCR_Veh_Immo                    = 0;
         Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = 0;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV10::Toyota::LongCtrlInput_t))
      && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V10_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV10::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV10.Toyota;

      if ((ulPPortSize == sizeof(LongCtrlInputV9::Toyota::LongCtrlInput_t)) &&
         (version == 9u))
      {
        const LongCtrlInputV9::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV9::Toyota::LongCtrlInput_t*>(pPPortData);

        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
#if 0
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.KinCtrlDynInput.country_code                 = Src.KinCtrlDynInput.country_code;
        Dest.KinCtrlDynInput.KinCtrlSignalState           = Src.KinCtrlDynInput.KinCtrlSignalState;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
        Dest.sSigHeader       = Src.sSigHeader;
        Dest.KinCtrlDynInput  = Src.KinCtrlDynInput;
        Dest.Custom           = Src.Custom;
#endif
        Dest.uiVersionNumber  = 10u;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t)) &&
         ((version == 6u) || (version == 7u)))
      {
         const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed * 100;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
#if 0
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
         Dest.sSigHeader      = Src.sSigHeader;
#endif
         Dest.Custom          = Src.Custom;
         Dest.uiVersionNumber = 10u;
         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       // Special work-around for unfilled ARS4T0 signals
       else if (sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t) == ulPPortSize)
       {
        const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

        if ( (Src.uiVersionNumber != 6)
          || (Src.Custom.EngineEcuInput.XLDR != 0)
          || (Src.Custom.EngineEcuInput.XACCACT != 0)
          || (Src.Custom.EngineEcuInput.STPBZ != 0)
          || (Src.Custom.EngineEcuInput.ACCREQ != 0)
          || (Src.Custom.EngineEcuInput.SPDSTAT != 0)
          || (Src.Custom.EngineEcuInput.ACCSTAT != 0)
          || (Src.Custom.EngineEcuInput.LCCHK != 0)
          || (Src.Custom.EngineEcuInput.VM != 0)
          || (Src.Custom.EngineEcuInput.XCCOK2 != 0)
          || (Src.Custom.EngineEcuInput.SLTACC != 0)
          || (Src.Custom.EngineEcuInput.LTME2 != 0)
          || (Src.Custom.EngineEcuInput.INTG != 0)
          )
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        else
        {
          // Work-around for activation with CAN where no Engine ECU input provided
          LongCtrlInputV6::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV6.Toyota;
          Dest.uiVersionNumber  = 6;
          Dest = Src;
          Init(Dest.Custom);
          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
       }
       else if ((ulPPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
         (version == 5u))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Init(Dest.Custom);
#if 0
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
#else
         Dest.sSigHeader      = Src.sSigHeader;
#endif

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t)) && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V9_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
       LongCtrlInputV9::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV9.Daimler;

       if (version < 9)   // ? Everything below version 9 assumed to be version 6?! Left like this, since no idea whats behind this
       {
         const LongCtrlInputV6::Daimler::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Daimler::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.DisplayOutputSignalState       = 0;
         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.KinCtrlDynInput.KinCtrlSignalState           = 0;
         Dest.Custom.CustomSignalState                     = 0;
         Dest.Custom.SPCR.SPCR_AS_Dsabl                    = Src.Custom.SPCR.SPCR_AS_Dsabl;
         Dest.Custom.SPCR.SPCR_AS_Off_Rq                   = Src.Custom.SPCR.SPCR_AS_Off_Rq;
         Dest.Custom.SPCR.SPCR_Excpt_Rq_V2                 = Src.Custom.SPCR.SPCR_Excpt_Rq_V2;
         Dest.Custom.SPCR.SPCR_Md                          = Src.Custom.SPCR.SPCR_Md;
         Dest.Custom.SPCR.SPCR_Veh_Immo                    = Src.Custom.SPCR.SPCR_Veh_Immo;
         Dest.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs    = Src.Custom.LongCtrlRs.VehAccel_X_LDC_VehSp_Rs;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
         Dest.uiVersionNumber                              = 10u;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         if (sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t) == ulPPortSize)
         {
           *pOutData = pPPortData;
           ulOutSize = ulPPortSize;
           lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
         }
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV9::Toyota::LongCtrlInput_t)) && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V9_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
       LongCtrlInputV9::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV9.Toyota;

       if ((version == 10) && (sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t) == ulPPortSize))
       {
         const LongCtrlInputV10::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV10::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed / 100;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.Custom                                       = Src.Custom;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
         Dest.uiVersionNumber                              = 9u;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else if (((version >= 6) && (version < 9)) && (sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t) == ulPPortSize))
       {
         const LongCtrlInputV6::Toyota::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV6::Toyota::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Dest.Custom                                       = Src.Custom;
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
         Dest.uiVersionNumber                              = 9u;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else if ((version == 5) && (sizeof(LongCtrlInputV5::LongCtrlInput_t) == ulPPortSize))
       {
         const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);

         Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
         Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
         Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
         Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
         Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
         Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
         Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
         Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
         Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
         Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
         Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
         Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
         Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
         Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
         Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
         Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
         Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
         Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
         Dest.KinCtrlDynInput.country_code                 = 0;
         Init(Dest.Custom);
         Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
         Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
         Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
         Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;
         Dest.uiVersionNumber                              = 6u;

         *pOutData = &Dest;
         ulOutSize = sizeof(Dest);
         lRet = SIM_ERR_OK;
       }
       else
       {
         lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
       }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV6::Daimler::LongCtrlInput_t)) && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V6_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV6::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV6.Daimler;
      switch (version)
      {
      case 0:
      case 1:
        if (sizeof(LongCtrlInputV5::LongCtrlInput_t) == ulPPortSize)
        {
          const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);
          Dest.uiVersionNumber  = 6;
#if(LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
          Dest.Custom.EngineEcuInput.ACCREQ   = 4;
          Dest.Custom.EngineEcuInput.ACCSTAT  = 1;
          Dest.Custom.EngineEcuInput.INTG     = 1;
          Dest.Custom.EngineEcuInput.LCCHK    = 0;
          Dest.Custom.EngineEcuInput.LTME2    = 2;
          Dest.Custom.EngineEcuInput.SLTACC   = 2;
          Dest.Custom.EngineEcuInput.SPDSTAT  = 8;
          Dest.Custom.EngineEcuInput.STPBZ    = 0;
          Dest.Custom.EngineEcuInput.VM       = 100;
          Dest.Custom.EngineEcuInput.XACCACT  = 1;
          Dest.Custom.EngineEcuInput.XCCOK2   = 1;
          Dest.Custom.EngineEcuInput.XLDR     = 1;
#endif
          Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
          Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
          Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
          Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
          Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
          Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
          Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
          Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
          Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
          Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
          Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
          Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
          Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
          Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
          Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
          Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
          Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
          Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
          Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
          Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
          Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
          Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      case 2:
        if (sizeof(LongCtrlInputV6::Daimler::LongCtrlInput_t) == ulPPortSize)
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      default:
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        break;
      }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t)) && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V6_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV6::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV6.Toyota;
      if ((version < 6) && (sizeof(LongCtrlInputV5::LongCtrlInput_t) == ulPPortSize))
      {
        const LongCtrlInputV5::LongCtrlInput_t & Src = *reinterpret_cast<LongCtrlInputV5::LongCtrlInput_t*>(pPPortData);
        Dest.uiVersionNumber  = 6;
        Init(Dest.Custom);
        Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
        Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
        Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
        Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
        Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
        Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
        Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
        Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
        Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
        Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
        Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
        Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
        Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
        Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
        Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
        Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
        Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
        Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
        Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
        Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
        Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
        Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V5_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      switch (version)
      {
      case 0:
      case 1:
        if (sizeof(LongCtrlInputV5::LongCtrlInput_t) == ulPPortSize)
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
        }
        break;
      case 2:
        if (sizeof(LongCtrlInputV6::LongCtrlInputBase_t) <= ulPPortSize)
        {
          const LongCtrlInputV6::LongCtrlInputBase_t & Src = *reinterpret_cast<LongCtrlInputV6::LongCtrlInputBase_t*>(pPPortData);
          LongCtrlInputV5::LongCtrlInput_t & Dest = m_LongCtrlInputV5;
          Dest.uiVersionNumber  = 5;

          Dest.DisplayOutput.speedometer_speed              = Src.DisplayOutput.speedometer_speed;
          Dest.DisplayOutput.speed_unit                     = Src.DisplayOutput.speed_unit;
          Dest.KinCtrlDynInput.acc_enable                   = Src.KinCtrlDynInput.acc_enable;
          Dest.KinCtrlDynInput.brk_sw                       = Src.KinCtrlDynInput.brk_sw;
          Dest.KinCtrlDynInput.DAS_accel_request_limited    = Src.KinCtrlDynInput.DAS_accel_request_limited;
          Dest.KinCtrlDynInput.DAS_decel_request_limited    = Src.KinCtrlDynInput.DAS_decel_request_limited;
          Dest.KinCtrlDynInput.DC_status_information        = Src.KinCtrlDynInput.DC_status_information;
          Dest.KinCtrlDynInput.door_state                   = Src.KinCtrlDynInput.door_state;
          Dest.KinCtrlDynInput.driver_braking               = Src.KinCtrlDynInput.driver_braking;
          Dest.KinCtrlDynInput.driver_override_accel_pedal  = Src.KinCtrlDynInput.driver_override_accel_pedal;
          Dest.KinCtrlDynInput.driver_override_decel_pedal  = Src.KinCtrlDynInput.driver_override_decel_pedal;
          Dest.KinCtrlDynInput.ldm_ctrl_state               = Src.KinCtrlDynInput.ldm_ctrl_state;
          Dest.KinCtrlDynInput.longi_initialization_accel   = Src.KinCtrlDynInput.longi_initialization_accel;
          Dest.KinCtrlDynInput.longi_shutoff_acknowledged   = Src.KinCtrlDynInput.longi_shutoff_acknowledged;
          Dest.KinCtrlDynInput.park_brk_eng                 = Src.KinCtrlDynInput.park_brk_eng;
          Dest.KinCtrlDynInput.perm_lim_setspeed            = Src.KinCtrlDynInput.perm_lim_setspeed;
          Dest.KinCtrlDynInput.stand_still_detected         = Src.KinCtrlDynInput.stand_still_detected;
          Dest.KinCtrlDynInput.var_lim_eng                  = Src.KinCtrlDynInput.var_lim_eng;
          Dest.sSigHeader.eSigStatus                        = Src.sSigHeader.eSigStatus;
          Dest.sSigHeader.uiCycleCounter                    = Src.sSigHeader.uiCycleCounter;
          Dest.sSigHeader.uiMeasurementCounter              = Src.sSigHeader.uiMeasurementCounter;
          Dest.sSigHeader.uiTimeStamp                       = Src.sSigHeader.uiTimeStamp;

          *pOutData = &Dest;
          ulOutSize = sizeof(Dest);
          lRet = SIM_ERR_OK;
        }
        break;
      default:
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
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
  return lRet;
}

/** returns: 
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvLongCtrlInput::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(LongCtrlInputV25::Hyundai::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V25_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV25::Hyundai::LongCtrlInput_t & Dest = m_LongCtrlInputV25.Hyundai;
      InitV25(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV22::Mitsubishi::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V22_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV22::Mitsubishi::LongCtrlInput_t & Dest = m_LongCtrlInputV22.Mitsubishi;
      InitV22(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV21::Mitsubishi::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V21_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV21::Mitsubishi::LongCtrlInput_t & Dest = m_LongCtrlInputV21.Mitsubishi;
      InitV21(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV12::Daimler::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V12_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV12::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV12.Daimler;
      InitV12(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV12::Toyota::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V12_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV12::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV12.Toyota;
      InitV12(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV11::Daimler::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V11_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV11::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV11.Daimler;
      InitV11(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV11::Toyota::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V11_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV11::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV11.Toyota;
      InitV11(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV10::Daimler::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V10_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV10::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV10.Daimler;
      InitV10(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV10::Toyota::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V10_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV10::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV10.Toyota;
      InitV10(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V9_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV9::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV9.Daimler;
      InitV9(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV9::Toyota::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V9_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV9::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV9.Toyota;
      InitV9(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV6::Daimler::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V6_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV6::Daimler::LongCtrlInput_t & Dest = m_LongCtrlInputV6.Daimler;
      InitV6(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V6_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      LongCtrlInputV6::Toyota::LongCtrlInput_t & Dest = m_LongCtrlInputV6.Toyota;
      InitV6(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) &&
      ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V5_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      InitV5(m_LongCtrlInputV5);
      *pDefaultData = &m_LongCtrlInputV5;
      ulDefaultSize = sizeof(m_LongCtrlInputV5);
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
bool CConvLongCtrlInput::IsVersionCompatibleWithType(
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
      if ((ulRPortSize == sizeof(LongCtrlInputV34::Hyundai::LongCtrlInput_t))
        && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V34_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if ((ulRPortSize == sizeof(LongCtrlInputV25::Hyundai::LongCtrlInput_t))
        && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V25_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if (((ulRPortSize == sizeof(LongCtrlInputV22::Mitsubishi::LongCtrlInput_t)) || (ulRPortSize == sizeof(LongCtrlInputV22::Mitsubishi::LongCtrlInput_t)))
        && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V22_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if (((ulRPortSize == sizeof(LongCtrlInputV21::Mitsubishi::LongCtrlInput_t)) || (ulRPortSize == sizeof(LongCtrlInputV21::Mitsubishi::LongCtrlInput_t)))
        && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V21_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if (((ulRPortSize == sizeof(LongCtrlInputV19::Daimler::LongCtrlInput_t)) || (ulRPortSize == sizeof(LongCtrlInputV19::Toyota::LongCtrlInput_t)))
        && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V19_VERSION)) || (requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V18_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if (((ulRPortSize == sizeof(LongCtrlInputV12::Daimler::LongCtrlInput_t)) || (ulRPortSize == sizeof(LongCtrlInputV12::Toyota::LongCtrlInput_t)))
        && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V12_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if (((ulRPortSize == sizeof(LongCtrlInputV11::Daimler::LongCtrlInput_t)) || (ulRPortSize == sizeof(LongCtrlInputV11::Toyota::LongCtrlInput_t)))
        && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V11_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if (((ulRPortSize == sizeof(LongCtrlInputV10::Daimler::LongCtrlInput_t)) || (ulRPortSize == sizeof(LongCtrlInputV10::Toyota::LongCtrlInput_t)))
        && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V10_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if (((ulRPortSize == sizeof(LongCtrlInputV9::Daimler::LongCtrlInput_t)) || (ulRPortSize == sizeof(LongCtrlInputV9::Toyota::LongCtrlInput_t)))
        && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V9_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if (((ulRPortSize == sizeof(LongCtrlInputV6::Daimler::LongCtrlInput_t)) || (ulRPortSize == sizeof(LongCtrlInputV6::Toyota::LongCtrlInput_t)))
        && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V6_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if ((ulRPortSize == sizeof(LongCtrlInputV5::LongCtrlInput_t)) && ((requestPortVersionInfo.Equals(&LONG_CTRL_INPUT_V5_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && (!bResult);i++)
        {
          if (ulPPortSize == SUPPORTED_SIZE[i])
          {
            bResult = true;
          }
        }
      }
      else if (ulRPortSize == sizeof(DummyVersion))
      {
        bResult = true;
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvLongCtrlInput::AreVersionsCompatible(
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
    bool bProvideOK = false, bRequestOK = false;
    for (unsigned int i =0; (i<CConvLongCtrlInput::LONG_CTRL_INPUT_VERSION_COUNT) && ((!bProvideOK) || (!bRequestOK));i++)
    {
      if ((ulPPortSize == SUPPORTED_SIZE[i]) && ((providePortVersionInfo.Equals(LONG_CTRL_INPUT_VERSIONS[i])) || (providePortVersionInfo.Equals(&BASE_VERSION))))
      {
        bProvideOK = true;
      }
      if ((ulRPortSize == SUPPORTED_SIZE[i]) && ((requestPortVersionInfo.Equals(LONG_CTRL_INPUT_VERSIONS[i])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        bRequestOK = true;
      }
    }
    bResult = bProvideOK && bRequestOK;
  }
  return bResult;
}

//
// CreateLongCtrlInputConvClass : single externally visible function of module
//

IConverter * CreateLongCtrlInputConvClass(void)
{
  return new CConvLongCtrlInput();
}
