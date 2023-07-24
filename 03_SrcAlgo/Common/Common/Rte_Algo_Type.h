/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_Algo_Type.h
CESSAR-CT Version: 4.0.3.2015B_M1
RTE Version: 4.0.3.2.7.0
Generated on:	Fri Jul 17 13:57:14 CST 2020
**************************************************************************/

#ifndef RTE_Algo_TYPE_H
#define RTE_Algo_TYPE_H

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */


#include "Rte_Type.h"
/**********************************************/
/* Mode management types                      */
/**********************************************/






/* Enum types */
/* typedef acc_obj_lane_t */
    #ifndef Obj_lane_left1
        #define Obj_lane_left1 -1
    #endif
    #ifndef Obj_lane_same
        #define Obj_lane_same 0
    #endif
    #ifndef Obj_lane_right1
        #define Obj_lane_right1 1
    #endif

/* typedef obj_class_t */
    #ifndef Obj_class_none
        #define Obj_class_none 0U
    #endif
    #ifndef Obj_class_passenger_car
        #define Obj_class_passenger_car 1U
    #endif
    #ifndef Obj_class_truck
        #define Obj_class_truck 2U
    #endif
    #ifndef Obj_class_cycle
        #define Obj_class_cycle 3U
    #endif
    #ifndef Obj_class_pedestrian
        #define Obj_class_pedestrian 4U
    #endif

/* typedef INHIBITION_REASON_t */
    #ifndef Acc_inhibition_none
        #define Acc_inhibition_none 0U
    #endif
    #ifndef Acc_inhibition_blockage
        #define Acc_inhibition_blockage 1U
    #endif
    #ifndef Acc_inhibition_alignment_init
        #define Acc_inhibition_alignment_init 2U
    #endif
    #ifndef Acc_inhibition_alignment
        #define Acc_inhibition_alignment 4U
    #endif
    #ifndef Acc_inhibition_partial_blockage
        #define Acc_inhibition_partial_blockage 8U
    #endif
    #ifndef Acc_inhibition_selftest
        #define Acc_inhibition_selftest 16U
    #endif
    #ifndef Acc_inhibition_degradation
        #define Acc_inhibition_degradation 32U
    #endif

/* typedef acc_situation_class_t */
    #ifndef Acc_sit_class_undefined
        #define Acc_sit_class_undefined 0U
    #endif
    #ifndef Acc_sit_class_freemode
        #define Acc_sit_class_freemode 1U
    #endif
    #ifndef Acc_sit_class_follow
        #define Acc_sit_class_follow 2U
    #endif
    #ifndef Acc_sit_class_crawl
        #define Acc_sit_class_crawl 3U
    #endif
    #ifndef Acc_sit_class_stop
        #define Acc_sit_class_stop 4U
    #endif
    #ifndef Acc_sit_class_go
        #define Acc_sit_class_go 5U
    #endif
    #ifndef Acc_sit_class_overtake
        #define Acc_sit_class_overtake 6U
    #endif

/* typedef e_AlnOpMode_t */
    #ifndef ALN_OpMode_Reset
        #define ALN_OpMode_Reset 0U
    #endif
    #ifndef ALN_OpMode_Pause
        #define ALN_OpMode_Pause 1U
    #endif
    #ifndef ALN_OpMode_Normal
        #define ALN_OpMode_Normal 2U
    #endif
    #ifndef ALN_OpMode_EolAlignment
        #define ALN_OpMode_EolAlignment 3U
    #endif
    #ifndef ALN_OpMode_Automatic
        #define ALN_OpMode_Automatic 4U
    #endif
    #ifndef ALN_OpMode_Service
        #define ALN_OpMode_Service 5U
    #endif

/* typedef u_CycleState_t */
    #ifndef Aln_CycleState_Near
        #define Aln_CycleState_Near 0U
    #endif
    #ifndef Aln_CycleState_Clusters
        #define Aln_CycleState_Clusters 2U
    #endif

/* typedef e_AlnState_t */
    #ifndef AlnStateNormal
        #define AlnStateNormal 0U
    #endif
    #ifndef AlnStateFinished
        #define AlnStateFinished 1U
    #endif
    #ifndef AlnStateFailed
        #define AlnStateFailed 2U
    #endif

/* typedef e_AlignState_t */
    #ifndef ALNMonInit
        #define ALNMonInit 0U
    #endif
    #ifndef ALNMonNormal
        #define ALNMonNormal 1U
    #endif
    #ifndef ALNMonPermanentlyNotAligned
        #define ALNMonPermanentlyNotAligned 3U
    #endif
    #ifndef ALNMonPartialBlockage
        #define ALNMonPartialBlockage 4U
    #endif

/* typedef e_Direction_t */
    #ifndef ALNDirUnknown
        #define ALNDirUnknown 0U
    #endif
    #ifndef ALNDirForward
        #define ALNDirForward 1U
    #endif
    #ifndef ALNDirBackward
        #define ALNDirBackward 2U
    #endif
    #ifndef ALNDirStandstill
        #define ALNDirStandstill 3U
    #endif

/* typedef e_GainReduction_t */
    #ifndef ALN_GainRed_Auto
        #define ALN_GainRed_Auto 0U
    #endif
    #ifndef ALN_GainRed_0dB
        #define ALN_GainRed_0dB 1U
    #endif
    #ifndef ALN_GainRed_6dB
        #define ALN_GainRed_6dB 2U
    #endif
    #ifndef ALN_GainRed_12dB
        #define ALN_GainRed_12dB 3U
    #endif
    #ifndef ALN_GainRed_18dB
        #define ALN_GainRed_18dB 4U
    #endif

/* typedef e_PowerReduction_t */
    #ifndef ALN_PowerRed_Auto
        #define ALN_PowerRed_Auto 0U
    #endif
    #ifndef ALN_PowerRed_Off
        #define ALN_PowerRed_Off 1U
    #endif
    #ifndef ALN_PowerRed_On
        #define ALN_PowerRed_On 2U
    #endif

/* typedef AccelSwitch_t */
    #ifndef ACC_LEVER_NO_ACCEL
        #define ACC_LEVER_NO_ACCEL 0U
    #endif
    #ifndef ACC_LEVER_ACCEL_LOW
        #define ACC_LEVER_ACCEL_LOW 1U
    #endif
    #ifndef ACC_LEVER_ACCEL_HIGH
        #define ACC_LEVER_ACCEL_HIGH 2U
    #endif

/* typedef DecelSwitch_t */
    #ifndef ACC_LEVER_NO_DECEL
        #define ACC_LEVER_NO_DECEL 0U
    #endif
    #ifndef ACC_LEVER_DECEL_LOW
        #define ACC_LEVER_DECEL_LOW 1U
    #endif
    #ifndef ACC_LEVER_DECEL_HIGH
        #define ACC_LEVER_DECEL_HIGH 2U
    #endif

/* typedef CompState_t */
    #ifndef COMP_STATE_NOT_INITIALIZED
        #define COMP_STATE_NOT_INITIALIZED 0U
    #endif
    #ifndef COMP_STATE_RUNNING
        #define COMP_STATE_RUNNING 1U
    #endif
    #ifndef COMP_STATE_TEMPORARY_ERROR
        #define COMP_STATE_TEMPORARY_ERROR 2U
    #endif
    #ifndef COMP_STATE_PERMANENT_ERROR
        #define COMP_STATE_PERMANENT_ERROR 3U
    #endif
    #ifndef COMP_STATE_SUCCESS
        #define COMP_STATE_SUCCESS 4U
    #endif
    #ifndef COMP_STATE_REDUCED_AVAILABILITY
        #define COMP_STATE_REDUCED_AVAILABILITY 5U
    #endif
    #ifndef COMP_STATE_NOT_RUNNING
        #define COMP_STATE_NOT_RUNNING 6U
    #endif
    #ifndef COMP_STATE_INPUT_INTERFACE_INCONSISTANT
        #define COMP_STATE_INPUT_INTERFACE_INCONSISTANT 7U
    #endif

/* typedef CompErrorCode_t */
    #ifndef COMP_ERROR_NO_ERROR
        #define COMP_ERROR_NO_ERROR 0U
    #endif
    #ifndef COMP_ERROR_UNKNOWN
        #define COMP_ERROR_UNKNOWN 4294967295U
    #endif

/* typedef eRelObjLossReason_t */
    #ifndef OBJ_LOSS_NO_INFO
        #define OBJ_LOSS_NO_INFO 0U
    #endif
    #ifndef OBJ_LOSS_DISAPPEARED
        #define OBJ_LOSS_DISAPPEARED 1U
    #endif
    #ifndef OBJ_LOSS_LANE_CHG_LEFT
        #define OBJ_LOSS_LANE_CHG_LEFT 2U
    #endif
    #ifndef OBJ_LOSS_LANE_CHG_RIGHT
        #define OBJ_LOSS_LANE_CHG_RIGHT 3U
    #endif
    #ifndef OBJ_LOSS_CURVE_LEFT
        #define OBJ_LOSS_CURVE_LEFT 4U
    #endif
    #ifndef OBJ_LOSS_CURVE_RIGHT
        #define OBJ_LOSS_CURVE_RIGHT 5U
    #endif
    #ifndef OBJ_LOSS_CURVE_LEFT_AHEAD
        #define OBJ_LOSS_CURVE_LEFT_AHEAD 6U
    #endif
    #ifndef OBJ_LOSS_CURVE_RIGHT_AHEAD
        #define OBJ_LOSS_CURVE_RIGHT_AHEAD 7U
    #endif
    #ifndef OBJ_LOSS_STEER_LEFT
        #define OBJ_LOSS_STEER_LEFT 8U
    #endif
    #ifndef OBJ_LOSS_STEER_RIGHT
        #define OBJ_LOSS_STEER_RIGHT 9U
    #endif
    #ifndef OBJ_LOSS_RANGE_REDUCTION
        #define OBJ_LOSS_RANGE_REDUCTION 10U
    #endif
    #ifndef OBJ_LOSS_DISAPP_LOWDIST
        #define OBJ_LOSS_DISAPP_LOWDIST 11U
    #endif

/* typedef eAssociatedLane_t */
    #ifndef ASSOC_LANE_UNKNOWN
        #define ASSOC_LANE_UNKNOWN 0U
    #endif
    #ifndef ASSOC_LANE_FAR_LEFT
        #define ASSOC_LANE_FAR_LEFT 1U
    #endif
    #ifndef ASSOC_LANE_LEFT
        #define ASSOC_LANE_LEFT 2U
    #endif
    #ifndef ASSOC_LANE_EGO
        #define ASSOC_LANE_EGO 3U
    #endif
    #ifndef ASSOC_LANE_RIGHT
        #define ASSOC_LANE_RIGHT 4U
    #endif
    #ifndef ASSOC_LANE_FAR_RIGHT
        #define ASSOC_LANE_FAR_RIGHT 5U
    #endif

/* typedef eObjOOI_t */
    #ifndef OBJ_NOT_OOI
        #define OBJ_NOT_OOI -1
    #endif
    #ifndef OBJ_NEXT_OOI
        #define OBJ_NEXT_OOI 0
    #endif
    #ifndef OBJ_HIDDEN_NEXT_OOI
        #define OBJ_HIDDEN_NEXT_OOI 1
    #endif
    #ifndef OBJ_NEXT_LONG_LEFT_OOI
        #define OBJ_NEXT_LONG_LEFT_OOI 2
    #endif
    #ifndef OBJ_NEXT_LONG_RIGHT_OOI
        #define OBJ_NEXT_LONG_RIGHT_OOI 3
    #endif
    #ifndef OBJ_NEXT_LAT_LEFT_OOI
        #define OBJ_NEXT_LAT_LEFT_OOI 4
    #endif
    #ifndef OBJ_NEXT_LAT_RIGHT_OOI
        #define OBJ_NEXT_LAT_RIGHT_OOI 5
    #endif

/* typedef eDynamicMeasStatus_t */
    #ifndef NOT_MEASURED_STOPPED_OBJ
        #define NOT_MEASURED_STOPPED_OBJ 0U
    #endif
    #ifndef NOT_MEASURED_STANDING_OBJ
        #define NOT_MEASURED_STANDING_OBJ 1U
    #endif
    #ifndef NOT_MEASURED_ONCOMING_OBJ
        #define NOT_MEASURED_ONCOMING_OBJ 2U
    #endif
    #ifndef NOT_MEASURED_MOVING_OBJ
        #define NOT_MEASURED_MOVING_OBJ 3U
    #endif
    #ifndef MEASURED_STOPPED_OBJ
        #define MEASURED_STOPPED_OBJ 4U
    #endif
    #ifndef MEASURED_STANDING_OBJ
        #define MEASURED_STANDING_OBJ 5U
    #endif
    #ifndef MEASURED_ONCOMING_OBJ
        #define MEASURED_ONCOMING_OBJ 6U
    #endif
    #ifndef MEASURED_MOVING_OBJ
        #define MEASURED_MOVING_OBJ 7U
    #endif
    #ifndef NEW_STOPPED_OBJ
        #define NEW_STOPPED_OBJ 8U
    #endif
    #ifndef NEW_STANDING_OBJ
        #define NEW_STANDING_OBJ 9U
    #endif
    #ifndef NEW_ONCOMING_OBJ
        #define NEW_ONCOMING_OBJ 10U
    #endif
    #ifndef NEW_MOVING_OBJ
        #define NEW_MOVING_OBJ 11U
    #endif
    #ifndef IMPLAUSIBLE_OBJ
        #define IMPLAUSIBLE_OBJ 12U
    #endif
    #ifndef NO_OBJ
        #define NO_OBJ 14U
    #endif

/* typedef eObjMeasStatus_t */
    #ifndef OBJ_NONE
        #define OBJ_NONE 0U
    #endif
    #ifndef OBJ_NEW
        #define OBJ_NEW 1U
    #endif
    #ifndef OBJ_NOT_MEASURED
        #define OBJ_NOT_MEASURED 2U
    #endif
    #ifndef OBJ_CONFIRMED_MEASURED
        #define OBJ_CONFIRMED_MEASURED 3U
    #endif

/* typedef EBACodingBitEnum_t */
    #ifndef EBA_NV_COD_WARNING
        #define EBA_NV_COD_WARNING 1U
    #endif
    #ifndef EBA_NV_COD_STAT_OBJ
        #define EBA_NV_COD_STAT_OBJ 2U
    #endif
    #ifndef EBA_NV_COD_LOW_SPEED
        #define EBA_NV_COD_LOW_SPEED 4U
    #endif
    #ifndef EBA_NV_COD_COUNTRY
        #define EBA_NV_COD_COUNTRY 8U
    #endif
    #ifndef EBA_NV_COD_PRE_BRK
        #define EBA_NV_COD_PRE_BRK 16U
    #endif
    #ifndef EBA_NV_COD_BRK_COND
        #define EBA_NV_COD_BRK_COND 32U
    #endif
    #ifndef EBA_NV_COD_IGN_SCHK
        #define EBA_NV_COD_IGN_SCHK 64U
    #endif
    #ifndef EBA_NV_COD_PRE_BRK2
        #define EBA_NV_COD_PRE_BRK2 128U
    #endif
    #ifndef EBA_NV_COD_PRE_BRK_STAT
        #define EBA_NV_COD_PRE_BRK_STAT 256U
    #endif
    #ifndef EBA_NV_COD_EM_BRAKING
        #define EBA_NV_COD_EM_BRAKING 512U
    #endif
    #ifndef EBA_NV_COD_MAX
        #define EBA_NV_COD_MAX 4294967295U
    #endif

/* typedef EBAPreBrkAccelParNvState_t */
    #ifndef EBA_NV_TAB_PRE_BRK_INVALID
        #define EBA_NV_TAB_PRE_BRK_INVALID 0U
    #endif
    #ifndef EBA_NV_TAB_PRE_BRK_LEV1_VALID
        #define EBA_NV_TAB_PRE_BRK_LEV1_VALID 1U
    #endif
    #ifndef EBA_NV_TAB_PRE_BRK_LEV2_VALID
        #define EBA_NV_TAB_PRE_BRK_LEV2_VALID 2U
    #endif
    #ifndef EBA_NV_TAB_PRE_BRK_ALL_VALID
        #define EBA_NV_TAB_PRE_BRK_ALL_VALID 3U
    #endif

/* typedef CameraFusionPreselBits_t */
    #ifndef ACC_PAR_FUSION_SEL_DEFAULT
        #define ACC_PAR_FUSION_SEL_DEFAULT 0U
    #endif
    #ifndef ACC_PAR_FUSION_SEL_NO_BIKES
        #define ACC_PAR_FUSION_SEL_NO_BIKES 1U
    #endif
    #ifndef ACC_PAR_FUSION_SEL_BIT2
        #define ACC_PAR_FUSION_SEL_BIT2 2U
    #endif
    #ifndef ACC_PAR_FUSION_SEL_BIT3
        #define ACC_PAR_FUSION_SEL_BIT3 4U
    #endif
    #ifndef ACC_PAR_FUSION_SEL_BIT4
        #define ACC_PAR_FUSION_SEL_BIT4 8U
    #endif
    #ifndef ACC_PAR_FUSION_SEL_BIT5
        #define ACC_PAR_FUSION_SEL_BIT5 16U
    #endif
    #ifndef ACC_PAR_FUSION_SEL_BIT6
        #define ACC_PAR_FUSION_SEL_BIT6 32U
    #endif
    #ifndef ACC_PAR_FUSION_SEL_BIT7
        #define ACC_PAR_FUSION_SEL_BIT7 64U
    #endif
    #ifndef ACC_PAR_FUSION_SEL_BIT8
        #define ACC_PAR_FUSION_SEL_BIT8 128U
    #endif
    #ifndef ACC_PAR_FUSION_SEL_MAX
        #define ACC_PAR_FUSION_SEL_MAX 255U
    #endif

/* typedef NaviFusionPreselBits_t */
    #ifndef ACC_NAV_FUSION_SEL_DEFAULT
        #define ACC_NAV_FUSION_SEL_DEFAULT 0U
    #endif
    #ifndef ACC_NAV_FUSION_SEL_COUNTRY_ROAD
        #define ACC_NAV_FUSION_SEL_COUNTRY_ROAD 1U
    #endif
    #ifndef ACC_NAV_FUSION_SEL_TRAJ_FUSION
        #define ACC_NAV_FUSION_SEL_TRAJ_FUSION 2U
    #endif
    #ifndef ACC_NAV_FUSION_SEL_BIT2
        #define ACC_NAV_FUSION_SEL_BIT2 4U
    #endif
    #ifndef ACC_NAV_FUSION_SEL_BIT3
        #define ACC_NAV_FUSION_SEL_BIT3 8U
    #endif
    #ifndef ACC_NAV_FUSION_SEL_BIT4
        #define ACC_NAV_FUSION_SEL_BIT4 16U
    #endif
    #ifndef ACC_NAV_FUSION_SEL_BIT5
        #define ACC_NAV_FUSION_SEL_BIT5 32U
    #endif
    #ifndef ACC_NAV_FUSION_SEL_BIT6
        #define ACC_NAV_FUSION_SEL_BIT6 64U
    #endif
    #ifndef ACC_NAV_FUSION_SEL_BIT7
        #define ACC_NAV_FUSION_SEL_BIT7 128U
    #endif
    #ifndef ACC_NAV_FUSION_SEL_MAX
        #define ACC_NAV_FUSION_SEL_MAX 255U
    #endif

/* typedef FnSwitchBits_t */
    #ifndef FN_AP_BIT_ABA_TEST_MODE
        #define FN_AP_BIT_ABA_TEST_MODE 1U
    #endif
    #ifndef FN_AP_BIT_RESERVED
        #define FN_AP_BIT_RESERVED 254U
    #endif

/* typedef ui8_UseFarNearScanForBlck_t */
    #ifndef PD_USE_MAX_FAR_NEAR
        #define PD_USE_MAX_FAR_NEAR 0U
    #endif
    #ifndef PD_USE_ONLY_NEAR
        #define PD_USE_ONLY_NEAR 1U
    #endif
    #ifndef PD_USE_ONLY_FAR
        #define PD_USE_ONLY_FAR 2U
    #endif
    #ifndef PD_USE_FUSED_FAR_NEAR
        #define PD_USE_FUSED_FAR_NEAR 3U
    #endif

/* typedef Em_cem_algo_sensor_state_t */
    #ifndef CEM_PAR_SENSOR_STATE_OFF
        #define CEM_PAR_SENSOR_STATE_OFF 0U
    #endif
    #ifndef CEM_PAR_SENSOR_STATE_NORMAL
        #define CEM_PAR_SENSOR_STATE_NORMAL 1U
    #endif
    #ifndef CEM_PAR_SENSOR_STATE_REDUCE
        #define CEM_PAR_SENSOR_STATE_REDUCE 2U
    #endif
    #ifndef CEM_PAR_SENSOR_STATE_ENHANCE
        #define CEM_PAR_SENSOR_STATE_ENHANCE 3U
    #endif
    #ifndef CEM_PAR_SENSOR_STATE_ERROR
        #define CEM_PAR_SENSOR_STATE_ERROR 4U
    #endif

/* typedef Em_cem_algo_mode_t */
    #ifndef CEM_PAR_ME_SEL_NO
        #define CEM_PAR_ME_SEL_NO 0U
    #endif
    #ifndef CEM_PAR_ME_SEL_1
        #define CEM_PAR_ME_SEL_1 1U
    #endif
    #ifndef CEM_PAR_ME_SEL_2
        #define CEM_PAR_ME_SEL_2 2U
    #endif
    #ifndef CEM_PAR_ME_SEL_3
        #define CEM_PAR_ME_SEL_3 3U
    #endif
    #ifndef CEM_PAR_ME_SEL_4
        #define CEM_PAR_ME_SEL_4 4U
    #endif
    #ifndef CEM_PAR_ME_SEL_5
        #define CEM_PAR_ME_SEL_5 5U
    #endif
    #ifndef CEM_PAR_ME_SEL_INVALID
        #define CEM_PAR_ME_SEL_INVALID 15U
    #endif

/* typedef Em_Ped_ArtDummy_t */
    #ifndef EM_PED_ART_DUMMY_DEFAULT
        #define EM_PED_ART_DUMMY_DEFAULT 0U
    #endif
    #ifndef EM_PED_ART_DUMMY_OFF
        #define EM_PED_ART_DUMMY_OFF 1U
    #endif
    #ifndef EM_PED_ART_DUMMY_ON
        #define EM_PED_ART_DUMMY_ON 2U
    #endif

/* typedef EMOpMode_t */
    #ifndef EM_MOD_STARTUP
        #define EM_MOD_STARTUP 0U
    #endif
    #ifndef EM_MOD_RUNNING
        #define EM_MOD_RUNNING 1U
    #endif
    #ifndef EM_MOD_PAUSE
        #define EM_MOD_PAUSE 2U
    #endif
    #ifndef EM_MOD_INVALID_INPUT_SIGNALS
        #define EM_MOD_INVALID_INPUT_SIGNALS 3U
    #endif
    #ifndef EM_MOD_INIT
        #define EM_MOD_INIT 4U
    #endif
    #ifndef EM_MOD_SERVICEALIGNMENT
        #define EM_MOD_SERVICEALIGNMENT 5U
    #endif
    #ifndef EM_MOD_END_OF_LINE
        #define EM_MOD_END_OF_LINE 6U
    #endif
    #ifndef EM_MOD_SELFTEST
        #define EM_MOD_SELFTEST 7U
    #endif
    #ifndef EM_MOD_INTERFERENCE
        #define EM_MOD_INTERFERENCE 8U
    #endif
    #ifndef EM_MOD_BLOCKAGE_TEST
        #define EM_MOD_BLOCKAGE_TEST 9U
    #endif
    #ifndef EM_MOD_FUNCTION_TEST
        #define EM_MOD_FUNCTION_TEST 10U
    #endif

/* typedef BaseOpMode_t */
    #ifndef BASE_OM_IDLE
        #define BASE_OM_IDLE 0U
    #endif
    #ifndef BASE_OM_RESET
        #define BASE_OM_RESET 1U
    #endif
    #ifndef BASE_OM_MAX_RUNTIME
        #define BASE_OM_MAX_RUNTIME 2U
    #endif
    #ifndef BASE_OM_DEMO
        #define BASE_OM_DEMO 3U
    #endif
    #ifndef BASE_OM_RUN
        #define BASE_OM_RUN 4U
    #endif
    #ifndef BASE_OM_RUN_ODD
        #define BASE_OM_RUN_ODD 5U
    #endif
    #ifndef BASE_OM_RUN_EVEN
        #define BASE_OM_RUN_EVEN 6U
    #endif
    #ifndef BASE_OM_SYNC
        #define BASE_OM_SYNC 7U
    #endif
    #ifndef BASE_OM_MEAS_ONLY
        #define BASE_OM_MEAS_ONLY 8U
    #endif
    #ifndef BASE_OM_INIT_LUT
        #define BASE_OM_INIT_LUT 9U
    #endif
    #ifndef BASE_OM_AUTOCAL_COARSE
        #define BASE_OM_AUTOCAL_COARSE 10U
    #endif
    #ifndef BASE_OM_AUTOCAL_FINE
        #define BASE_OM_AUTOCAL_FINE 11U
    #endif
    #ifndef BASE_OM_AUTO_CHOICE
        #define BASE_OM_AUTO_CHOICE 12U
    #endif
    #ifndef BASE_OM_EOL_UPDATE
        #define BASE_OM_EOL_UPDATE 13U
    #endif
    #ifndef BASE_OM_SELF_EVAL
        #define BASE_OM_SELF_EVAL 14U
    #endif
    #ifndef BASE_OM_TEST
        #define BASE_OM_TEST 15U
    #endif
    #ifndef BASE_OM_DISTANCE_TEST
        #define BASE_OM_DISTANCE_TEST 16U
    #endif
    #ifndef BASE_OM_ECM_RTE_TRANSMIT
        #define BASE_OM_ECM_RTE_TRANSMIT 17U
    #endif
    #ifndef BASE_OM_ECM_RTE_DEV
        #define BASE_OM_ECM_RTE_DEV 18U
    #endif
    #ifndef BASE_OM_ECM_RTE_EOL
        #define BASE_OM_ECM_RTE_EOL 19U
    #endif
    #ifndef BASE_OM_FEX_RUN_INIT_FPGA
        #define BASE_OM_FEX_RUN_INIT_FPGA 20U
    #endif
    #ifndef BASE_OM_FEX_RUN_STARTUP_TEST_FPGA
        #define BASE_OM_FEX_RUN_STARTUP_TEST_FPGA 21U
    #endif
    #ifndef BASE_OM_FEX_RUN_CYCLIC_TEST_FPGA
        #define BASE_OM_FEX_RUN_CYCLIC_TEST_FPGA 22U
    #endif
    #ifndef BASE_OM_FEX_RUN_SAC_DATA
        #define BASE_OM_FEX_RUN_SAC_DATA 23U
    #endif
    #ifndef BASE_OM_FEX_RUN_PED_DATA
        #define BASE_OM_FEX_RUN_PED_DATA 24U
    #endif
    #ifndef BASE_OM_PED_RUN_HYPGEN
        #define BASE_OM_PED_RUN_HYPGEN 25U
    #endif
    #ifndef BASE_OM_PED_RUN_IMAGE_TRACKING
        #define BASE_OM_PED_RUN_IMAGE_TRACKING 26U
    #endif
    #ifndef BASE_OM_PED_RUN_CLUSTERING
        #define BASE_OM_PED_RUN_CLUSTERING 27U
    #endif
    #ifndef BASE_OM_MEMO_SYNCVDY
        #define BASE_OM_MEMO_SYNCVDY 28U
    #endif
    #ifndef BASE_OM_VCL_ROIGEN
        #define BASE_OM_VCL_ROIGEN 29U
    #endif
    #ifndef BASE_OM_EM_PREDICT
        #define BASE_OM_EM_PREDICT 30U
    #endif
    #ifndef BASE_OM_EM_UPDATE_GEN
        #define BASE_OM_EM_UPDATE_GEN 31U
    #endif
    #ifndef BASE_OM_EM_UPDATE_PED
        #define BASE_OM_EM_UPDATE_PED 32U
    #endif
    #ifndef BASE_OM_EM_UPDATE_VCL
        #define BASE_OM_EM_UPDATE_VCL 33U
    #endif
    #ifndef BASE_OM_EM_UPDATE_SPC
        #define BASE_OM_EM_UPDATE_SPC 34U
    #endif
    #ifndef BASE_OM_EM_MAINTENANCE
        #define BASE_OM_EM_MAINTENANCE 35U
    #endif
    #ifndef BASE_OM_SIB_GEOMETRY
        #define BASE_OM_SIB_GEOMETRY 36U
    #endif
    #ifndef BASE_OM_SIB_DYNAMIC
        #define BASE_OM_SIB_DYNAMIC 37U
    #endif
    #ifndef BASE_OM_VODCA_PREPROCESS
        #define BASE_OM_VODCA_PREPROCESS 38U
    #endif
    #ifndef BASE_OM_VODCA_CLASSIFY
        #define BASE_OM_VODCA_CLASSIFY 39U
    #endif
    #ifndef BASE_OM_NVM_CALIB_RESET
        #define BASE_OM_NVM_CALIB_RESET 40U
    #endif
    #ifndef BASE_OM_NVM_RESET
        #define BASE_OM_NVM_RESET 41U
    #endif
    #ifndef BASE_OM_VCL_TRACK
        #define BASE_OM_VCL_TRACK 42U
    #endif
    #ifndef BASE_OM_VCL_POSTPROC
        #define BASE_OM_VCL_POSTPROC 43U
    #endif
    #ifndef BASE_OM_HLA_SEG
        #define BASE_OM_HLA_SEG 44U
    #endif
    #ifndef BASE_OM_EM_PROCESS_GSS
        #define BASE_OM_EM_PROCESS_GSS 45U
    #endif
    #ifndef BASE_OM_EM_PROCESS_OD
        #define BASE_OM_EM_PROCESS_OD 46U
    #endif
    #ifndef BASE_OM_EM_PROCESS_ROAD
        #define BASE_OM_EM_PROCESS_ROAD 47U
    #endif
    #ifndef BASE_OM_RUM_INITIAL_ROI_GEN
        #define BASE_OM_RUM_INITIAL_ROI_GEN 48U
    #endif
    #ifndef BASE_OM_RUM_TRACKING
        #define BASE_OM_RUM_TRACKING 49U
    #endif
    #ifndef BASE_OM_RUM_POST_PROC
        #define BASE_OM_RUM_POST_PROC 50U
    #endif
    #ifndef BASE_OM_EM_PROCESS_FLOW
        #define BASE_OM_EM_PROCESS_FLOW 51U
    #endif
    #ifndef BASE_OM_EM_PROCESS_LMD
        #define BASE_OM_EM_PROCESS_LMD 52U
    #endif
    #ifndef BASE_OM_ACAL_TRANSMIT
        #define BASE_OM_ACAL_TRANSMIT 53U
    #endif
    #ifndef BASE_OM_ACAL_CALIB
        #define BASE_OM_ACAL_CALIB 54U
    #endif
    #ifndef BASE_OM_LD_TEXTURE_CLASSIFY
        #define BASE_OM_LD_TEXTURE_CLASSIFY 55U
    #endif
    #ifndef BASE_OM_MEMO_RUN_EGOMOTION
        #define BASE_OM_MEMO_RUN_EGOMOTION 56U
    #endif
    #ifndef BASE_OM_MEMO_RUN_DEPTH
        #define BASE_OM_MEMO_RUN_DEPTH 57U
    #endif
    #ifndef BASE_OM_VODCA_PROCESS
        #define BASE_OM_VODCA_PROCESS 58U
    #endif
    #ifndef BASE_OM_VODCA_PROCESS_FINAL
        #define BASE_OM_VODCA_PROCESS_FINAL 59U
    #endif
    #ifndef BASE_OM_GEOS_PROCESS_FLOW
        #define BASE_OM_GEOS_PROCESS_FLOW 60U
    #endif
    #ifndef BASE_OM_GEOS_SEGMENTATION
        #define BASE_OM_GEOS_SEGMENTATION 61U
    #endif
    #ifndef BASE_OM_GEOS_PROCESS_EXTENDED_FLOW
        #define BASE_OM_GEOS_PROCESS_EXTENDED_FLOW 62U
    #endif
    #ifndef BASE_OM_DAP01
        #define BASE_OM_DAP01 1001U
    #endif
    #ifndef BASE_OM_DAP02
        #define BASE_OM_DAP02 1002U
    #endif
    #ifndef BASE_OM_DAP03
        #define BASE_OM_DAP03 1003U
    #endif
    #ifndef BASE_OM_DAP04
        #define BASE_OM_DAP04 1004U
    #endif
    #ifndef BASE_OM_GP01
        #define BASE_OM_GP01 1010U
    #endif
    #ifndef BASE_OM_GP02
        #define BASE_OM_GP02 1011U
    #endif
    #ifndef BASE_OM_GP03
        #define BASE_OM_GP03 1012U
    #endif
    #ifndef BASE_OM_GP04
        #define BASE_OM_GP04 1013U
    #endif
    #ifndef BASE_OM_GP05
        #define BASE_OM_GP05 1014U
    #endif
    #ifndef BASE_OM_GP06
        #define BASE_OM_GP06 1015U
    #endif
    #ifndef BASE_OM_OD01
        #define BASE_OM_OD01 1021U
    #endif
    #ifndef BASE_OM_OD02
        #define BASE_OM_OD02 1022U
    #endif
    #ifndef BASE_OM_OD03
        #define BASE_OM_OD03 1023U
    #endif
    #ifndef BASE_OM_OD04
        #define BASE_OM_OD04 1024U
    #endif
    #ifndef BASE_OM_OD05
        #define BASE_OM_OD05 1025U
    #endif
    #ifndef BASE_OM_OD06
        #define BASE_OM_OD06 1026U
    #endif
    #ifndef BASE_OM_OD07
        #define BASE_OM_OD07 1027U
    #endif
    #ifndef BASE_OM_PD01
        #define BASE_OM_PD01 1036U
    #endif
    #ifndef BASE_OM_PD02
        #define BASE_OM_PD02 1037U
    #endif
    #ifndef BASE_OM_PCC01
        #define BASE_OM_PCC01 1044U
    #endif
    #ifndef BASE_OM_PCC02
        #define BASE_OM_PCC02 1045U
    #endif
    #ifndef BASE_OM_RMHT01
        #define BASE_OM_RMHT01 1046U
    #endif
    #ifndef BASE_OM_RMHT02
        #define BASE_OM_RMHT02 1047U
    #endif
    #ifndef BASE_OM_RMHT03
        #define BASE_OM_RMHT03 1048U
    #endif
    #ifndef BASE_OM_RMHT04
        #define BASE_OM_RMHT04 1049U
    #endif
    #ifndef BASE_OM_RMHT05
        #define BASE_OM_RMHT05 1050U
    #endif
    #ifndef BASE_OM_RDT01
        #define BASE_OM_RDT01 1051U
    #endif
    #ifndef BASE_OM_RDT02
        #define BASE_OM_RDT02 1052U
    #endif
    #ifndef BASE_OM_RDT03
        #define BASE_OM_RDT03 1053U
    #endif
    #ifndef BASE_OM_RDT04
        #define BASE_OM_RDT04 1054U
    #endif
    #ifndef BASE_OM_RDT05
        #define BASE_OM_RDT05 1055U
    #endif
    #ifndef BASE_OM_RDT06
        #define BASE_OM_RDT06 1056U
    #endif
    #ifndef BASE_OM_RADI
        #define BASE_OM_RADI 1057U
    #endif
    #ifndef BASE_OM_RSP01
        #define BASE_OM_RSP01 1058U
    #endif
    #ifndef BASE_OM_SRP1_01
        #define BASE_OM_SRP1_01 1059U
    #endif
    #ifndef BASE_OM_SRP2_01
        #define BASE_OM_SRP2_01 1060U
    #endif
    #ifndef BASE_OM_SRP2_02
        #define BASE_OM_SRP2_02 1061U
    #endif
    #ifndef BASE_OM_SRP2_03
        #define BASE_OM_SRP2_03 1062U
    #endif
    #ifndef BASE_OM_SRP2_04
        #define BASE_OM_SRP2_04 1063U
    #endif
    #ifndef BASE_OM_RMP1_01
        #define BASE_OM_RMP1_01 1064U
    #endif
    #ifndef BASE_OM_RMP2_01
        #define BASE_OM_RMP2_01 1065U
    #endif
    #ifndef BASE_OM_RMP2_02
        #define BASE_OM_RMP2_02 1066U
    #endif
    #ifndef BASE_OM_SEP1_01
        #define BASE_OM_SEP1_01 1067U
    #endif
    #ifndef BASE_OM_SEP2_01
        #define BASE_OM_SEP2_01 1068U
    #endif
    #ifndef BASE_OM_SEP2_02
        #define BASE_OM_SEP2_02 1069U
    #endif
    #ifndef BASE_OM_SEP2_03
        #define BASE_OM_SEP2_03 1070U
    #endif
    #ifndef BASE_OM_OOC01
        #define BASE_OM_OOC01 1071U
    #endif
    #ifndef BASE_OM_RIC01
        #define BASE_OM_RIC01 1072U
    #endif
    #ifndef BASE_OM_RIC02
        #define BASE_OM_RIC02 1073U
    #endif
    #ifndef BASE_OM_CC01
        #define BASE_OM_CC01 1074U
    #endif
    #ifndef BASE_OM_ACDC01
        #define BASE_OM_ACDC01 1075U
    #endif
    #ifndef BASE_OM_LOCTR01
        #define BASE_OM_LOCTR01 1076U
    #endif
    #ifndef BASE_OM_MEDIC01
        #define BASE_OM_MEDIC01 1077U
    #endif
    #ifndef BASE_OM_LOPLN01
        #define BASE_OM_LOPLN01 1078U
    #endif
    #ifndef BASE_OM_RFCOM_Init
        #define BASE_OM_RFCOM_Init 1079U
    #endif
    #ifndef BASE_OM_RFCOM_ConfigFrame
        #define BASE_OM_RFCOM_ConfigFrame 1080U
    #endif
    #ifndef BASE_OM_RFCOM_TriggerFrame
        #define BASE_OM_RFCOM_TriggerFrame 1081U
    #endif
    #ifndef BASE_OM_RHC_PreSp1FRS
        #define BASE_OM_RHC_PreSp1FRS 1082U
    #endif
    #ifndef BASE_OM_RHC_PostSp1FRS
        #define BASE_OM_RHC_PostSp1FRS 1083U
    #endif
    #ifndef BASE_OM_RHC_PreSp1NRS
        #define BASE_OM_RHC_PreSp1NRS 1084U
    #endif
    #ifndef BASE_OM_RHC_PostSp1NRS
        #define BASE_OM_RHC_PostSp1NRS 1085U
    #endif
    #ifndef BASE_OM_RHC_PreLoopbackTest
        #define BASE_OM_RHC_PreLoopbackTest 1086U
    #endif
    #ifndef BASE_OM_RHC_PostLoopbackTest
        #define BASE_OM_RHC_PostLoopbackTest 1087U
    #endif
    #ifndef BASE_OM_RPM1_01
        #define BASE_OM_RPM1_01 1088U
    #endif
    #ifndef BASE_OM_RPM2_01
        #define BASE_OM_RPM2_01 1089U
    #endif
    #ifndef BASE_OM_RSP_INIT_CALC_AB_FRS
        #define BASE_OM_RSP_INIT_CALC_AB_FRS 1090U
    #endif
    #ifndef BASE_OM_RSP_INIT_CALC_AB_NRS
        #define BASE_OM_RSP_INIT_CALC_AB_NRS 1091U
    #endif
    #ifndef BASE_OM_RSP02
        #define BASE_OM_RSP02 1092U
    #endif
    #ifndef BASE_OM_ALN
        #define BASE_OM_ALN 1093U
    #endif
    #ifndef BASE_OM_ALN_EOL
        #define BASE_OM_ALN_EOL 1094U
    #endif
    #ifndef BASE_OM_ALN_SERVICE
        #define BASE_OM_ALN_SERVICE 1095U
    #endif
    #ifndef BASE_OM_ALN_AUTOMATIC
        #define BASE_OM_ALN_AUTOMATIC 1096U
    #endif
    #ifndef BASE_OM_MOS01
        #define BASE_OM_MOS01 1097U
    #endif
    #ifndef BASE_OM_RPP01
        #define BASE_OM_RPP01 1098U
    #endif
    #ifndef BASE_OM_PCA_NORMAL
        #define BASE_OM_PCA_NORMAL 2000U
    #endif
    #ifndef BASE_OM_PCA_NUC
        #define BASE_OM_PCA_NUC 2001U
    #endif
    #ifndef BASE_OM_LIQOR_PIXEL_LABEL
        #define BASE_OM_LIQOR_PIXEL_LABEL 2016U
    #endif
    #ifndef BASE_OM_LIQOR_OBJ_LABEL
        #define BASE_OM_LIQOR_OBJ_LABEL 2017U
    #endif
    #ifndef BASE_OM_VDY
        #define BASE_OM_VDY 2018U
    #endif
    #ifndef BASE_OM_RC1_01
        #define BASE_OM_RC1_01 2019U
    #endif
    #ifndef BASE_OM_RC1_02
        #define BASE_OM_RC1_02 2020U
    #endif
    #ifndef BASE_OM_RC2_01
        #define BASE_OM_RC2_01 2021U
    #endif
    #ifndef BASE_OM_RCG
        #define BASE_OM_RCG 4096U
    #endif
    #ifndef BASE_OM_INVALID
        #define BASE_OM_INVALID 65535U
    #endif

/* typedef BaseSchedulingMode_t */
    #ifndef BASE_SM_IDLE
        #define BASE_SM_IDLE 0U
    #endif
    #ifndef BASE_SM_RESET
        #define BASE_SM_RESET 1U
    #endif
    #ifndef BASE_SM_DEMO
        #define BASE_SM_DEMO 2U
    #endif
    #ifndef BASE_SM_RUN
        #define BASE_SM_RUN 3U
    #endif
    #ifndef BASE_SM_EOL
        #define BASE_SM_EOL 4U
    #endif
    #ifndef BASE_SM_CALIB
        #define BASE_SM_CALIB 5U
    #endif
    #ifndef BASE_SM_DEGRADED
        #define BASE_SM_DEGRADED 6U
    #endif
    #ifndef BASE_SM_SERVICE_ALIGNMENT
        #define BASE_SM_SERVICE_ALIGNMENT 7U
    #endif
    #ifndef BASE_SM_AIA
        #define BASE_SM_AIA 8U
    #endif

/* typedef BaseSchedulingSubMode_t */
    #ifndef BASE_SSM_NONE
        #define BASE_SSM_NONE 0U
    #endif
    #ifndef BASE_SSM_BLOCKAGE
        #define BASE_SSM_BLOCKAGE 1U
    #endif
    #ifndef BASE_SSM_DEGRADED
        #define BASE_SSM_DEGRADED 2U
    #endif
    #ifndef BASE_SSM_STANDALONE
        #define BASE_SSM_STANDALONE 4U
    #endif
    #ifndef BASE_SSM_PARALLEL
        #define BASE_SSM_PARALLEL 8U
    #endif
    #ifndef BASE_SSM_NOT_CALIBRATED
        #define BASE_SSM_NOT_CALIBRATED 16U
    #endif

/* typedef EBACodingParamGen_t */
    #ifndef EBA_CODING_GEN_LOW_SPEED
        #define EBA_CODING_GEN_LOW_SPEED 1U
    #endif
    #ifndef EBA_CODING_GEN_COUNTRY_A
        #define EBA_CODING_GEN_COUNTRY_A 2U
    #endif
    #ifndef EBA_CODING_GEN_COUNTRY_B
        #define EBA_CODING_GEN_COUNTRY_B 4U
    #endif
    #ifndef EBA_CODING_GEN_IGNR_SFTY_CHCKS
        #define EBA_CODING_GEN_IGNR_SFTY_CHCKS 8U
    #endif
    #ifndef EBA_CODING_GEN_DEBUGMESSAGES
        #define EBA_CODING_GEN_DEBUGMESSAGES 16U
    #endif
    #ifndef EBA_CODING_GEN_DISTANCELIMIT
        #define EBA_CODING_GEN_DISTANCELIMIT 32U
    #endif
    #ifndef EBA_CODING_GEN_DRIVER_SET_CODING
        #define EBA_CODING_GEN_DRIVER_SET_CODING 64U
    #endif
    #ifndef EBA_CODING_GEN_IGNORE_ACT_SWITCH
        #define EBA_CODING_GEN_IGNORE_ACT_SWITCH 128U
    #endif
    #ifndef EBA_CODING_GEN_MAX_VALUE
        #define EBA_CODING_GEN_MAX_VALUE 4294967295U
    #endif

/* typedef CPAREBACodingFctMods_t */
    #ifndef EBA_CODING_BIT_PRECRASH
        #define EBA_CODING_BIT_PRECRASH 1U
    #endif
    #ifndef EBA_CODING_BIT_PREFILL1
        #define EBA_CODING_BIT_PREFILL1 2U
    #endif
    #ifndef EBA_CODING_BIT_PREFILL2
        #define EBA_CODING_BIT_PREFILL2 4U
    #endif
    #ifndef EBA_CODING_BIT_HBA1
        #define EBA_CODING_BIT_HBA1 8U
    #endif
    #ifndef EBA_CODING_BIT_HBA2
        #define EBA_CODING_BIT_HBA2 16U
    #endif
    #ifndef EBA_CODING_BIT_AUTOBRK1
        #define EBA_CODING_BIT_AUTOBRK1 32U
    #endif
    #ifndef EBA_CODING_BIT_AUTOBRK2
        #define EBA_CODING_BIT_AUTOBRK2 64U
    #endif
    #ifndef EBA_CODING_BIT_AUTOBRK3
        #define EBA_CODING_BIT_AUTOBRK3 128U
    #endif
    #ifndef EBA_CODING_BIT_DYN_WARN1
        #define EBA_CODING_BIT_DYN_WARN1 256U
    #endif
    #ifndef EBA_CODING_BIT_DYN_WARN2
        #define EBA_CODING_BIT_DYN_WARN2 512U
    #endif
    #ifndef EBA_CODING_BIT_DYN_WARN3
        #define EBA_CODING_BIT_DYN_WARN3 1024U
    #endif
    #ifndef EBA_CODING_BIT_DIST_WARN1
        #define EBA_CODING_BIT_DIST_WARN1 2048U
    #endif
    #ifndef EBA_CODING_BIT_DIST_WARN2
        #define EBA_CODING_BIT_DIST_WARN2 4096U
    #endif
    #ifndef EBA_CODING_BIT_SPARE1
        #define EBA_CODING_BIT_SPARE1 8192U
    #endif
    #ifndef EBA_CODING_BIT_SPARE2
        #define EBA_CODING_BIT_SPARE2 16384U
    #endif
    #ifndef EBA_CODING_BIT_SPARE3
        #define EBA_CODING_BIT_SPARE3 32768U
    #endif

/* typedef EBACodingParamCustom_t */
    #ifndef EBA_CODING_BIT_CUSTOM1
        #define EBA_CODING_BIT_CUSTOM1 1U
    #endif
    #ifndef EBA_CODING_BIT_CUSTOM2
        #define EBA_CODING_BIT_CUSTOM2 2U
    #endif
    #ifndef EBA_CODING_BIT_CUSTOM3
        #define EBA_CODING_BIT_CUSTOM3 4U
    #endif
    #ifndef EBA_CODING_BIT_CUSTOM4
        #define EBA_CODING_BIT_CUSTOM4 8U
    #endif
    #ifndef EBA_CODING_BIT_CUSTOM5
        #define EBA_CODING_BIT_CUSTOM5 16U
    #endif
    #ifndef EBA_CODING_BIT_CUSTOM6
        #define EBA_CODING_BIT_CUSTOM6 32U
    #endif
    #ifndef EBA_CODING_BIT_CUSTOM7
        #define EBA_CODING_BIT_CUSTOM7 64U
    #endif
    #ifndef EBA_CODING_BIT_CUSTOM8
        #define EBA_CODING_BIT_CUSTOM8 128U
    #endif

/* typedef t_CamLaneMarkerEnum */
    #ifndef CL_CAM_LANE_MK_ADJ_LEFT
        #define CL_CAM_LANE_MK_ADJ_LEFT 0U
    #endif
    #ifndef CL_CAM_LANE_MK_LEFT
        #define CL_CAM_LANE_MK_LEFT 1U
    #endif
    #ifndef CL_CAM_LANE_MK_RIGHT
        #define CL_CAM_LANE_MK_RIGHT 2U
    #endif
    #ifndef CL_CAM_LANE_MK_ADJ_RIGHT
        #define CL_CAM_LANE_MK_ADJ_RIGHT 3U
    #endif

/* typedef t_MarkerColor */
    #ifndef CL_MARKER_COLOR_UNKNOWN
        #define CL_MARKER_COLOR_UNKNOWN 0U
    #endif
    #ifndef CL_MARKER_COLOR_WHITE
        #define CL_MARKER_COLOR_WHITE 1U
    #endif
    #ifndef CL_MARKER_COLOR_YELLOW
        #define CL_MARKER_COLOR_YELLOW 2U
    #endif
    #ifndef CL_MARKER_COLOR_BLUE
        #define CL_MARKER_COLOR_BLUE 3U
    #endif
    #ifndef CL_MARKER_COLOR_GREEN
        #define CL_MARKER_COLOR_GREEN 4U
    #endif
    #ifndef CL_MARKER_COLOR_RED
        #define CL_MARKER_COLOR_RED 5U
    #endif
    #ifndef CL_MARKER_COLOR_SNA
        #define CL_MARKER_COLOR_SNA 6U
    #endif
    #ifndef CL_MARKER_COLOR_UNDEFINED1
        #define CL_MARKER_COLOR_UNDEFINED1 7U
    #endif
    #ifndef CL_MARKER_COLOR_UNDEFINED2
        #define CL_MARKER_COLOR_UNDEFINED2 8U
    #endif
    #ifndef CL_MARKER_COLOR_UNDEFINED3
        #define CL_MARKER_COLOR_UNDEFINED3 9U
    #endif

/* typedef t_MarkerType */
    #ifndef CL_MARKER_TYPE_CONTINUOUS
        #define CL_MARKER_TYPE_CONTINUOUS 0U
    #endif
    #ifndef CL_MARKER_TYPE_DASHED
        #define CL_MARKER_TYPE_DASHED 1U
    #endif
    #ifndef CL_MARKER_TYPE_RESERVED1
        #define CL_MARKER_TYPE_RESERVED1 2U
    #endif
    #ifndef CL_MARKER_TYPE_RESERVED2
        #define CL_MARKER_TYPE_RESERVED2 3U
    #endif
    #ifndef CL_MARKER_TYPE_NOLINEDETECTED
        #define CL_MARKER_TYPE_NOLINEDETECTED 4U
    #endif
    #ifndef CL_MARKER_TYPE_UNCLASSIFIED
        #define CL_MARKER_TYPE_UNCLASSIFIED 5U
    #endif
    #ifndef CL_MARKER_TYPE_DOTTED
        #define CL_MARKER_TYPE_DOTTED 6U
    #endif
    #ifndef CL_MARKER_TYPE_DECORATION
        #define CL_MARKER_TYPE_DECORATION 7U
    #endif
    #ifndef CL_MARKER_TYPE_SEPARATING
        #define CL_MARKER_TYPE_SEPARATING 8U
    #endif
    #ifndef CL_MARKER_TYPE_NARROWDASHED
        #define CL_MARKER_TYPE_NARROWDASHED 9U
    #endif
    #ifndef CL_MARKER_TYPE_LOWCURB
        #define CL_MARKER_TYPE_LOWCURB 10U
    #endif
    #ifndef CL_MARKER_TYPE_HIGHCURB
        #define CL_MARKER_TYPE_HIGHCURB 11U
    #endif
    #ifndef CL_MARKER_TYPE_CRASHBARRIER
        #define CL_MARKER_TYPE_CRASHBARRIER 12U
    #endif
    #ifndef CL_MARKER_TYPE_WALL
        #define CL_MARKER_TYPE_WALL 13U
    #endif
    #ifndef CL_MARKER_TYPE_ROADSHOULDER
        #define CL_MARKER_TYPE_ROADSHOULDER 14U
    #endif
    #ifndef CL_MARKER_TYPE_SNA
        #define CL_MARKER_TYPE_SNA 15U
    #endif
    #ifndef CL_MARKER_TYPE_GRASS
        #define CL_MARKER_TYPE_GRASS 16U
    #endif
    #ifndef CL_MARKER_TYPE_MISCELLANEOUS
        #define CL_MARKER_TYPE_MISCELLANEOUS 17U
    #endif

/* typedef HDCSysStat_t */
    #ifndef HDC_STAT_OFF
        #define HDC_STAT_OFF 0U
    #endif
    #ifndef HDC_STAT_ENABLE
        #define HDC_STAT_ENABLE 1U
    #endif
    #ifndef HDC_STAT_ACTIVE
        #define HDC_STAT_ACTIVE 2U
    #endif
    #ifndef HDC_STAT_FAILED
        #define HDC_STAT_FAILED 3U
    #endif

/* typedef ACCFailureMode_t */
    #ifndef NoError
        #define NoError 0U
    #endif
    #ifndef TempError
        #define TempError 1U
    #endif
    #ifndef PermError
        #define PermError 2U
    #endif

/* typedef GearPosition_t */
    #ifndef GEAR_POSITION_NONE
        #define GEAR_POSITION_NONE 0U
    #endif
    #ifndef GEAR_POSITION_PARK
        #define GEAR_POSITION_PARK 1U
    #endif
    #ifndef GEAR_POSITION_NEUTRAL
        #define GEAR_POSITION_NEUTRAL 2U
    #endif
    #ifndef GEAR_POSITION_REVERSE
        #define GEAR_POSITION_REVERSE 3U
    #endif
    #ifndef GEAR_POSITION_DRIVE
        #define GEAR_POSITION_DRIVE 4U
    #endif
    #ifndef GEAR_POSITION_SPORT
        #define GEAR_POSITION_SPORT 5U
    #endif
    #ifndef GEAR_POSITION_MANUAL
        #define GEAR_POSITION_MANUAL 6U
    #endif

/* typedef EngineStatus_t */
    #ifndef ENGINE_STOPEED
        #define ENGINE_STOPEED 0U
    #endif
    #ifndef ENGINE_STALLED
        #define ENGINE_STALLED 1U
    #endif
    #ifndef ENGINE_RUNNING
        #define ENGINE_RUNNING 2U
    #endif
    #ifndef ENGINE_CRANKING
        #define ENGINE_CRANKING 3U
    #endif
    #ifndef ENGINE_ERROR
        #define ENGINE_ERROR 4U
    #endif

/* typedef EM_t_CustomerProjectDef */
    #ifndef EM_PRJ_ARS400
        #define EM_PRJ_ARS400 0U
    #endif
    #ifndef EM_PRJ_ARS4B0
        #define EM_PRJ_ARS4B0 1U
    #endif
    #ifndef EM_PRJ_ARS4D0
        #define EM_PRJ_ARS4D0 2U
    #endif
    #ifndef EM_PRJ_ARS4D1
        #define EM_PRJ_ARS4D1 3U
    #endif
    #ifndef EM_PRJ_ARS4D2
        #define EM_PRJ_ARS4D2 4U
    #endif
    #ifndef EM_PRJ_ARS4L0
        #define EM_PRJ_ARS4L0 5U
    #endif
    #ifndef EM_PRJ_ARS4L1
        #define EM_PRJ_ARS4L1 6U
    #endif
    #ifndef EM_PRJ_ARS4T0
        #define EM_PRJ_ARS4T0 7U
    #endif
    #ifndef EM_PRJ_ARS4V0
        #define EM_PRJ_ARS4V0 8U
    #endif
    #ifndef EM_PRJ_ARS4G0
        #define EM_PRJ_ARS4G0 9U
    #endif
    #ifndef EM_PRJ_ARS4A0
        #define EM_PRJ_ARS4A0 10U
    #endif
    #ifndef EM_PRJ_ARS4E0
        #define EM_PRJ_ARS4E0 11U
    #endif
    #ifndef EM_PRJ_ARS4N0
        #define EM_PRJ_ARS4N0 12U
    #endif
    #ifndef EM_PRJ_ARS4AD
        #define EM_PRJ_ARS4AD 13U
    #endif
    #ifndef EM_PRJ_ARS4R0
        #define EM_PRJ_ARS4R0 14U
    #endif
    #ifndef EM_PRJ_ARS4N1
        #define EM_PRJ_ARS4N1 15U
    #endif
    #ifndef EM_PRJ_ARS4M0
        #define EM_PRJ_ARS4M0 16U
    #endif
    #ifndef EM_PRJ_ARS4J0
        #define EM_PRJ_ARS4J0 17U
    #endif
    #ifndef EM_PRJ_ARS410EUNCAP
        #define EM_PRJ_ARS410EUNCAP 18U
    #endif
    #ifndef EM_PRJ_ARS510
        #define EM_PRJ_ARS510 19U
    #endif
    #ifndef EM_PRJ_ARS410HI17
        #define EM_PRJ_ARS410HI17 20U
    #endif
    #ifndef EM_PRJ_ARS441DP10
        #define EM_PRJ_ARS441DP10 21U
    #endif
    #ifndef EM_PRJ_ARS510GM18
        #define EM_PRJ_ARS510GM18 22U
    #endif
    #ifndef EM_PRJ_ARS510GM29
        #define EM_PRJ_ARS510GM29 23U
    #endif
    #ifndef EM_PRJ_ARSVWBERTRAM
        #define EM_PRJ_ARSVWBERTRAM 24U
    #endif
    #ifndef EM_PRJ_ARS410TL17
        #define EM_PRJ_ARS410TL17 25U
    #endif
    #ifndef EM_PRJ_ARS510EUNCAP
        #define EM_PRJ_ARS510EUNCAP 26U
    #endif
    #ifndef EM_PRJ_ARS510TA19
        #define EM_PRJ_ARS510TA19 27U
    #endif
    #ifndef EM_PRJ_ARS410HI28
        #define EM_PRJ_ARS410HI28 28U
    #endif
    #ifndef EM_PRJ_ARS510VW19
        #define EM_PRJ_ARS510VW19 29U
    #endif
    #ifndef EM_PRJ_ARS410LO19
        #define EM_PRJ_ARS410LO19 30U
    #endif
    #ifndef EM_PRJ_ARS410SC19
        #define EM_PRJ_ARS410SC19 31U
    #endif
    #ifndef EM_PRJ_ARS510BW11
        #define EM_PRJ_ARS510BW11 32U
    #endif
    #ifndef EM_PRJ_ARS410GY69
        #define EM_PRJ_ARS410GY69 33U
    #endif
    #ifndef EM_PRJ_ARS510RT10
        #define EM_PRJ_ARS510RT10 34U
    #endif
    #ifndef EM_PRJ_ARS410SW29
        #define EM_PRJ_ARS410SW29 35U
    #endif
    #ifndef EM_PRJ_ARS410VA10
        #define EM_PRJ_ARS410VA10 36U
    #endif
    #ifndef EM_PRJ_ARS410BD10
        #define EM_PRJ_ARS410BD10 37U
    #endif
    #ifndef EM_PRJ_ARS410CN11
        #define EM_PRJ_ARS410CN11 38U
    #endif
    #ifndef EM_PRJ_ARS410VA21
        #define EM_PRJ_ARS410VA21 39U
    #endif

/* typedef EM_t_StatusFusion */
    #ifndef EM_FUSION_NONE
        #define EM_FUSION_NONE 0U
    #endif
    #ifndef EM_FUSION_SCAM_FRONT
        #define EM_FUSION_SCAM_FRONT 1U
    #endif
    #ifndef EM_FUSION_MCAM_FRONT
        #define EM_FUSION_MCAM_FRONT 2U
    #endif
    #ifndef EM_FUSION_CAM_FEND
        #define EM_FUSION_CAM_FEND 4U
    #endif
    #ifndef EM_FUSION_TOP_VIEW
        #define EM_FUSION_TOP_VIEW 8U
    #endif
    #ifndef EM_FUSION_CAM_REAR
        #define EM_FUSION_CAM_REAR 16U
    #endif
    #ifndef EM_FUSION_RADAR_FRONT
        #define EM_FUSION_RADAR_FRONT 32U
    #endif
    #ifndef EM_FUSION_RADAR_SCAM
        #define EM_FUSION_RADAR_SCAM 33U
    #endif
    #ifndef EM_FUSION_RADAR_FSIDE
        #define EM_FUSION_RADAR_FSIDE 64U
    #endif
    #ifndef EM_FUSION_RAD_SIDE_SCAM
        #define EM_FUSION_RAD_SIDE_SCAM 65U
    #endif
    #ifndef EM_FUSION_RADAR_BOTH
        #define EM_FUSION_RADAR_BOTH 96U
    #endif
    #ifndef EM_FUSION_RAD_BOTH_SCAM
        #define EM_FUSION_RAD_BOTH_SCAM 97U
    #endif
    #ifndef EM_FUSION_RADAR_RSIDE
        #define EM_FUSION_RADAR_RSIDE 128U
    #endif
    #ifndef EM_FUSION_RADAR_REAR
        #define EM_FUSION_RADAR_REAR 256U
    #endif
    #ifndef EM_FUSION_USOUND_FRONT
        #define EM_FUSION_USOUND_FRONT 512U
    #endif
    #ifndef EM_FUSION_USOUND_FSIDE
        #define EM_FUSION_USOUND_FSIDE 1024U
    #endif
    #ifndef EM_FUSION_USOUND_RSIDE
        #define EM_FUSION_USOUND_RSIDE 2048U
    #endif
    #ifndef EM_FUSION_USOUND_REAR
        #define EM_FUSION_USOUND_REAR 4096U
    #endif
    #ifndef EM_FUSION_ROAD_ONBOARD
        #define EM_FUSION_ROAD_ONBOARD 8192U
    #endif
    #ifndef EM_FUSION_ROAD_OFFBOARD
        #define EM_FUSION_ROAD_OFFBOARD 16384U
    #endif
    #ifndef EM_FUSION_SNA
        #define EM_FUSION_SNA 65535U
    #endif

/* typedef EM_t_FusionStateGlobal */
    #ifndef EM_FUSION_STATE_OFF
        #define EM_FUSION_STATE_OFF 0U
    #endif
    #ifndef EM_FUSION_STATE_CAM_FULL
        #define EM_FUSION_STATE_CAM_FULL 1U
    #endif
    #ifndef EM_FUSION_STATE_CAM_REDUCED
        #define EM_FUSION_STATE_CAM_REDUCED 2U
    #endif
    #ifndef EM_FUSION_STATE_CAM_TMP_NOT_AVAIL
        #define EM_FUSION_STATE_CAM_TMP_NOT_AVAIL 3U
    #endif
    #ifndef EM_FUSION_STATE_CAM_TIMEOUT
        #define EM_FUSION_STATE_CAM_TIMEOUT 4U
    #endif

/* typedef EMB0_t_SensorSource */
    #ifndef EMB0_OBJECT_LIST_SOURCE_NONE
        #define EMB0_OBJECT_LIST_SOURCE_NONE 0U
    #endif
    #ifndef EMB0_OBJECT_LIST_SOURCE_LRR
        #define EMB0_OBJECT_LIST_SOURCE_LRR 1U
    #endif
    #ifndef EMB0_OBJECT_LIST_SOURCE_MRR
        #define EMB0_OBJECT_LIST_SOURCE_MRR 2U
    #endif
    #ifndef EMB0_OBJECT_LIST_SOURCE_SRR_FL
        #define EMB0_OBJECT_LIST_SOURCE_SRR_FL 3U
    #endif
    #ifndef EMB0_OBJECT_LIST_SOURCE_SRR_FR
        #define EMB0_OBJECT_LIST_SOURCE_SRR_FR 4U
    #endif
    #ifndef EMB0_OBJECT_LIST_SOURCE_SRR_RL
        #define EMB0_OBJECT_LIST_SOURCE_SRR_RL 5U
    #endif
    #ifndef EMB0_OBJECT_LIST_SOURCE_SRR_RR
        #define EMB0_OBJECT_LIST_SOURCE_SRR_RR 6U
    #endif
    #ifndef EMB0_OBJECT_LIST_SOURCE_SRL
        #define EMB0_OBJECT_LIST_SOURCE_SRL 7U
    #endif
    #ifndef EMB0_OBJECT_LIST_SOURCE_MCAM
        #define EMB0_OBJECT_LIST_SOURCE_MCAM 8U
    #endif
    #ifndef EMB0_OBJECT_LIST_SOURCE_SCAM
        #define EMB0_OBJECT_LIST_SOURCE_SCAM 9U
    #endif

/* typedef EMB0_t_Service */
    #ifndef EMB0_QS_INIT
        #define EMB0_QS_INIT 0U
    #endif
    #ifndef EMB0_QS_OK
        #define EMB0_QS_OK 1U
    #endif
    #ifndef EMB0_QS_NOT_OK
        #define EMB0_QS_NOT_OK 2U
    #endif
    #ifndef EMB0_QS_SNA
        #define EMB0_QS_SNA 255U
    #endif

/* typedef EMBase_t_CamSensorState */
    #ifndef EMBASE_CAM_SEN_STATE_UNKNOWN
        #define EMBASE_CAM_SEN_STATE_UNKNOWN 0U
    #endif
    #ifndef EMBASE_CAM_SEN_STATE_NOT_OK
        #define EMBASE_CAM_SEN_STATE_NOT_OK 1U
    #endif
    #ifndef EMBASE_CAM_SEN_STATE_OK
        #define EMBASE_CAM_SEN_STATE_OK 2U
    #endif
    #ifndef EMBASE_CAM_SEN_STATE_REDUCED
        #define EMBASE_CAM_SEN_STATE_REDUCED 3U
    #endif
    #ifndef EMBASE_CAM_SEN_STATE_BLOCKED
        #define EMBASE_CAM_SEN_STATE_BLOCKED 4U
    #endif
    #ifndef INVALID
        #define INVALID 7U
    #endif

/* typedef eRefpointLocation_t */
    #ifndef EM_CAM_OBJ_REF_POINT_INVALID
        #define EM_CAM_OBJ_REF_POINT_INVALID 0U
    #endif
    #ifndef EM_CAM_OBJ_REF_POINT_BACK
        #define EM_CAM_OBJ_REF_POINT_BACK 1U
    #endif
    #ifndef EM_CAM_OBJ_REF_POINT_FRONT
        #define EM_CAM_OBJ_REF_POINT_FRONT 2U
    #endif
    #ifndef EM_CAM_OBJ_REF_POINT_LEFT
        #define EM_CAM_OBJ_REF_POINT_LEFT 3U
    #endif
    #ifndef EM_CAM_OBJ_REF_POINT_RIGHT
        #define EM_CAM_OBJ_REF_POINT_RIGHT 4U
    #endif

/* typedef EM_t_Cust_MatchType */
    #ifndef EM_COD_MATCH_UNKNOWN
        #define EM_COD_MATCH_UNKNOWN 0U
    #endif
    #ifndef EM_COD_MATCH_OCCLUDED
        #define EM_COD_MATCH_OCCLUDED 1U
    #endif
    #ifndef EM_COD_MATCH_NO_VEHICLE
        #define EM_COD_MATCH_NO_VEHICLE 2U
    #endif
    #ifndef EM_COD_MATCH_VEHICLE
        #define EM_COD_MATCH_VEHICLE 3U
    #endif
    #ifndef EM_COD_MATCH_SINGLE_MATCH
        #define EM_COD_MATCH_SINGLE_MATCH 4U
    #endif
    #ifndef EM_COD_MATCH_MULTIPLE_MATCH_OK
        #define EM_COD_MATCH_MULTIPLE_MATCH_OK 5U
    #endif
    #ifndef EM_COD_MATCH_MULTIPLE_MATCH
        #define EM_COD_MATCH_MULTIPLE_MATCH 6U
    #endif
    #ifndef EM_COD_MATCH_NO_MATCH
        #define EM_COD_MATCH_NO_MATCH 7U
    #endif
    #ifndef EM_COD_MATCH_NEW_OBJECT
        #define EM_COD_MATCH_NEW_OBJECT 8U
    #endif
    #ifndef EM_COD_MATCH_ID_CHANGE_1
        #define EM_COD_MATCH_ID_CHANGE_1 9U
    #endif
    #ifndef EM_COD_MATCH_ID_CHANGE_2
        #define EM_COD_MATCH_ID_CHANGE_2 10U
    #endif
    #ifndef EM_COD_MATCH_INFO_1
        #define EM_COD_MATCH_INFO_1 11U
    #endif
    #ifndef EM_COD_MATCH_INFO_2
        #define EM_COD_MATCH_INFO_2 12U
    #endif
    #ifndef EM_COD_MATCH_INFO_3
        #define EM_COD_MATCH_INFO_3 13U
    #endif
    #ifndef EM_COD_MATCH_ERROR_1
        #define EM_COD_MATCH_ERROR_1 21U
    #endif
    #ifndef EM_COD_MATCH_ERROR_2
        #define EM_COD_MATCH_ERROR_2 22U
    #endif
    #ifndef EM_COD_MATCH_ERROR_3
        #define EM_COD_MATCH_ERROR_3 23U
    #endif

/* typedef EM_t_Cust_FusionStatus */
    #ifndef EM_COD_FUS_DATA_INIT
        #define EM_COD_FUS_DATA_INIT 0U
    #endif
    #ifndef EM_COD_FUS_DATA_INACTIVE
        #define EM_COD_FUS_DATA_INACTIVE 1U
    #endif
    #ifndef EM_COD_FUS_INPUT_STATUS_INIT
        #define EM_COD_FUS_INPUT_STATUS_INIT 10U
    #endif
    #ifndef EM_COD_FUS_INPUT_STATUS_OK
        #define EM_COD_FUS_INPUT_STATUS_OK 11U
    #endif
    #ifndef EM_COD_FUS_INPUT_STATUS_NOT_OK
        #define EM_COD_FUS_INPUT_STATUS_NOT_OK 12U
    #endif
    #ifndef EM_COD_FUS_INPUT_STATUS_TIMEOUT
        #define EM_COD_FUS_INPUT_STATUS_TIMEOUT 13U
    #endif
    #ifndef EM_COD_FUS_INPUT_STATUS_OUT_OF_RANGE
        #define EM_COD_FUS_INPUT_STATUS_OUT_OF_RANGE 15U
    #endif
    #ifndef EM_COD_FUS_INPUT_1_STATUS_OUT_OF_RANGE
        #define EM_COD_FUS_INPUT_1_STATUS_OUT_OF_RANGE 16U
    #endif
    #ifndef EM_COD_FUS_INPUT_2_STATUS_OUT_OF_RANGE
        #define EM_COD_FUS_INPUT_2_STATUS_OUT_OF_RANGE 17U
    #endif
    #ifndef EM_COD_FUS_INPUT_3_STATUS_OUT_OF_RANGE
        #define EM_COD_FUS_INPUT_3_STATUS_OUT_OF_RANGE 18U
    #endif
    #ifndef EM_COD_FUS_ALGO_DATA_MISSING
        #define EM_COD_FUS_ALGO_DATA_MISSING 20U
    #endif
    #ifndef EM_COD_FUS_ALGO_1_DATA_MISSING
        #define EM_COD_FUS_ALGO_1_DATA_MISSING 21U
    #endif
    #ifndef EM_COD_FUS_ALGO_2_DATA_MISSING
        #define EM_COD_FUS_ALGO_2_DATA_MISSING 22U
    #endif
    #ifndef EM_COD_FUS_ALGO_3_DATA_MISSING
        #define EM_COD_FUS_ALGO_3_DATA_MISSING 23U
    #endif
    #ifndef EM_COD_FUS_ALGO_CONTENT_ERROR
        #define EM_COD_FUS_ALGO_CONTENT_ERROR 25U
    #endif
    #ifndef EM_COD_FUS_ALGO_1_CONTENT_ERROR
        #define EM_COD_FUS_ALGO_1_CONTENT_ERROR 26U
    #endif
    #ifndef EM_COD_FUS_ALGO_2_CONTENT_ERROR
        #define EM_COD_FUS_ALGO_2_CONTENT_ERROR 27U
    #endif
    #ifndef EM_COD_FUS_ALGO_3_CONTENT_ERROR
        #define EM_COD_FUS_ALGO_3_CONTENT_ERROR 28U
    #endif
    #ifndef EM_COD_FUS_ALGO_CYCLETIEM_COD_INSUFFICIENT
        #define EM_COD_FUS_ALGO_CYCLETIEM_COD_INSUFFICIENT 30U
    #endif
    #ifndef EM_COD_FUS_ALGO_INTERNAL_ERROR
        #define EM_COD_FUS_ALGO_INTERNAL_ERROR 31U
    #endif
    #ifndef EM_COD_FUS_ALGO_1_INTERNAL_ERROR
        #define EM_COD_FUS_ALGO_1_INTERNAL_ERROR 32U
    #endif
    #ifndef EM_COD_FUS_ALGO_2_INTERNAL_ERROR
        #define EM_COD_FUS_ALGO_2_INTERNAL_ERROR 33U
    #endif
    #ifndef EM_COD_FUS_ALGO_3_INTERNAL_ERROR
        #define EM_COD_FUS_ALGO_3_INTERNAL_ERROR 34U
    #endif
    #ifndef EM_COD_FUS_SENSOR_INIT
        #define EM_COD_FUS_SENSOR_INIT 40U
    #endif
    #ifndef EM_COD_FUS_SENSOR_MISALIGNED
        #define EM_COD_FUS_SENSOR_MISALIGNED 41U
    #endif
    #ifndef EM_COD_FUS_SENSOR_BLOCKED
        #define EM_COD_FUS_SENSOR_BLOCKED 42U
    #endif
    #ifndef EM_COD_FUS_SENSOR_ERROR
        #define EM_COD_FUS_SENSOR_ERROR 43U
    #endif

/* typedef EM_t_Cust_CamAvailStatus */
    #ifndef EM_COD_FUS_CAMERA_AVAILABLE_NO
        #define EM_COD_FUS_CAMERA_AVAILABLE_NO 0U
    #endif
    #ifndef EM_COD_FUS_CAMERA_AVAILABLE_YES
        #define EM_COD_FUS_CAMERA_AVAILABLE_YES 1U
    #endif
    #ifndef EM_COD_FUS_CAMERA_AVAILABLE_TEMP_NO
        #define EM_COD_FUS_CAMERA_AVAILABLE_TEMP_NO 2U
    #endif

/* typedef EM_t_CamTurnLightsState */
    #ifndef CAM_TURN_LIGHT_OFF
        #define CAM_TURN_LIGHT_OFF 0U
    #endif
    #ifndef CAM_TURN_LIGHT_LEFT
        #define CAM_TURN_LIGHT_LEFT 1U
    #endif
    #ifndef CAM_TURN_LIGHT_RIGHT
        #define CAM_TURN_LIGHT_RIGHT 2U
    #endif
    #ifndef CAM_TURN_LIGHT_HAZARD
        #define CAM_TURN_LIGHT_HAZARD 3U
    #endif
    #ifndef CAM_TURN_LIGHT_UNKNOWN
        #define CAM_TURN_LIGHT_UNKNOWN 15U
    #endif

/* typedef EM_t_CamBrakeLight */
    #ifndef CAM_BRAKE_LIGHT_OFF
        #define CAM_BRAKE_LIGHT_OFF 0U
    #endif
    #ifndef CAM_BRAKE_LIGHT_ON
        #define CAM_BRAKE_LIGHT_ON 1U
    #endif
    #ifndef CAM_BRAKE_LIGHT_UNKNOWN
        #define CAM_BRAKE_LIGHT_UNKNOWN 15U
    #endif

/* typedef EM_t_CamObjManeuver */
    #ifndef CAM_OM_NONE
        #define CAM_OM_NONE 0U
    #endif
    #ifndef CAM_OM_CUT_IN
        #define CAM_OM_CUT_IN 1U
    #endif
    #ifndef CAM_OM_CUT_OUT
        #define CAM_OM_CUT_OUT 2U
    #endif

/* typedef EM_t_PositionInBeam */
    #ifndef EM_CLU_FOV_NORMAL
        #define EM_CLU_FOV_NORMAL 0U
    #endif
    #ifndef EM_CLU_AZIMUTH_BOUNDARY
        #define EM_CLU_AZIMUTH_BOUNDARY 1U
    #endif
    #ifndef EM_CLU_ELEVATION_OVERHEAD
        #define EM_CLU_ELEVATION_OVERHEAD 2U
    #endif

/* typedef EM_t_AmbigState */
    #ifndef EM_CLU_INVALID
        #define EM_CLU_INVALID 0U
    #endif
    #ifndef EM_CLU_AMBIGUOUS
        #define EM_CLU_AMBIGUOUS 1U
    #endif
    #ifndef EM_CLU_STAGGERED_RAMP
        #define EM_CLU_STAGGERED_RAMP 2U
    #endif
    #ifndef EM_CLU_UNAMBIG
        #define EM_CLU_UNAMBIG 3U
    #endif
    #ifndef EM_CLU_STATCAND
        #define EM_CLU_STATCAND 4U
    #endif

/* typedef EM_t_DynamicProperty */
    #ifndef EM_CLU_DYNPROP_MOVING
        #define EM_CLU_DYNPROP_MOVING 0U
    #endif
    #ifndef EM_CLU_DYNPROP_STATIONARY
        #define EM_CLU_DYNPROP_STATIONARY 1U
    #endif
    #ifndef EM_CLU_DYNPROP_ONCOMING
        #define EM_CLU_DYNPROP_ONCOMING 2U
    #endif
    #ifndef EM_CLU_DYNPROP_STAT_CAND
        #define EM_CLU_DYNPROP_STAT_CAND 3U
    #endif
    #ifndef EM_CLU_DYNPROP_UNKNOWN
        #define EM_CLU_DYNPROP_UNKNOWN 4U
    #endif
    #ifndef EM_CLU_DYNPROP_CROSSING_STAT
        #define EM_CLU_DYNPROP_CROSSING_STAT 5U
    #endif
    #ifndef EM_CLU_DYNPROP_CROSSING_MOV
        #define EM_CLU_DYNPROP_CROSSING_MOV 6U
    #endif
    #ifndef EM_CLU_DYNPROP_STOPPED
        #define EM_CLU_DYNPROP_STOPPED 7U
    #endif

/* typedef EM_t_InvalidReason */
    #ifndef EM_CLU_NOTINVALID
        #define EM_CLU_NOTINVALID 0U
    #endif
    #ifndef EM_CLU_LOWRCS
        #define EM_CLU_LOWRCS 1U
    #endif
    #ifndef EM_CLU_NEARFIELD
        #define EM_CLU_NEARFIELD 2U
    #endif
    #ifndef EM_CLU_FAR_NOTCONFIRMEDIN_NEAR
        #define EM_CLU_FAR_NOTCONFIRMEDIN_NEAR 3U
    #endif
    #ifndef EM_CLU_NOTINVALID_ENHANCEDRCS
        #define EM_CLU_NOTINVALID_ENHANCEDRCS 4U
    #endif
    #ifndef EM_CLU_JPDAMATRIX_FULL
        #define EM_CLU_JPDAMATRIX_FULL 5U
    #endif
    #ifndef EM_CLU_MIRROR
        #define EM_CLU_MIRROR 6U
    #endif
    #ifndef EM_CLU_AZIMUTH_OVERFLOW
        #define EM_CLU_AZIMUTH_OVERFLOW 7U
    #endif
    #ifndef EM_CLU_ELEVATED_CLU_FIXED
        #define EM_CLU_ELEVATED_CLU_FIXED 8U
    #endif
    #ifndef EM_CLU_CHILD
        #define EM_CLU_CHILD 9U
    #endif
    #ifndef EM_CLU_50DEG
        #define EM_CLU_50DEG 10U
    #endif
    #ifndef EM_CLU_ADDCLU
        #define EM_CLU_ADDCLU 11U
    #endif
    #ifndef EM_CLU_ARTFKT
        #define EM_CLU_ARTFKT 12U
    #endif
    #ifndef EM_CLU_PED
        #define EM_CLU_PED 13U
    #endif
    #ifndef EM_CLU_HARM
        #define EM_CLU_HARM 14U
    #endif
    #ifndef EM_CLU_RANGELIMIT
        #define EM_CLU_RANGELIMIT 15U
    #endif
    #ifndef EM_CLU_MULTITARGET
        #define EM_CLU_MULTITARGET 16U
    #endif
    #ifndef EM_CLU_SUSANG
        #define EM_CLU_SUSANG 17U
    #endif

/* typedef EM_t_ClusterListValid */
    #ifndef EM_CLULST_INVALID
        #define EM_CLULST_INVALID 0U
    #endif
    #ifndef EM_CLULST_VALID
        #define EM_CLULST_VALID 1U
    #endif

/* typedef uEMDet_AzAngValid_t */
    #ifndef EM_DET_VALID_NONE
        #define EM_DET_VALID_NONE 0U
    #endif
    #ifndef EM_DET_VALID_HYP_0
        #define EM_DET_VALID_HYP_0 1U
    #endif
    #ifndef EM_DET_VALID_HYP_1
        #define EM_DET_VALID_HYP_1 2U
    #endif

/* typedef uEMDet_Qualifier_t */
    #ifndef EM_DET_QUAL_OK
        #define EM_DET_QUAL_OK 0U
    #endif
    #ifndef EM_DET_QUAL_BELOW_RCS
        #define EM_DET_QUAL_BELOW_RCS 1U
    #endif
    #ifndef EM_DET_QUAL_BELOW_RCS_ENH
        #define EM_DET_QUAL_BELOW_RCS_ENH 2U
    #endif
    #ifndef EM_DET_QUAL_ARTIFACT
        #define EM_DET_QUAL_ARTIFACT 4U
    #endif
    #ifndef EM_DET_QUAL_AZ_RESOLUTION
        #define EM_DET_QUAL_AZ_RESOLUTION 8U
    #endif
    #ifndef EM_DET_QUAL_MULTIPATH_ARTIFACT
        #define EM_DET_QUAL_MULTIPATH_ARTIFACT 16U
    #endif

/* typedef eObstacleClass_t */
    #ifndef OBST_CLASS_UNKNOWN
        #define OBST_CLASS_UNKNOWN 0U
    #endif
    #ifndef OBST_CLASS_BRIDGE
        #define OBST_CLASS_BRIDGE 1U
    #endif
    #ifndef OBST_CLASS_VEHICLE
        #define OBST_CLASS_VEHICLE 2U
    #endif
    #ifndef OBST_CLASS_TRAFFIC_SIGN
        #define OBST_CLASS_TRAFFIC_SIGN 3U
    #endif
    #ifndef OBST_CLASS_TUNNEL
        #define OBST_CLASS_TUNNEL 4U
    #endif
    #ifndef OBST_CLASS_GUARDRAIL
        #define OBST_CLASS_GUARDRAIL 5U
    #endif
    #ifndef OBST_CLASS_BUTTJOINT
        #define OBST_CLASS_BUTTJOINT 6U
    #endif

/* typedef e_SuspiciousStopped_t */
    #ifndef ODOBJ_STOPPED_SUSPICIOUS_NONE
        #define ODOBJ_STOPPED_SUSPICIOUS_NONE 0U
    #endif
    #ifndef ODOBJ_STOPPED_SUSPICIOUS_LONG
        #define ODOBJ_STOPPED_SUSPICIOUS_LONG 1U
    #endif
    #ifndef ODOBJ_STOPPED_SUSPICIOUS_LAT
        #define ODOBJ_STOPPED_SUSPICIOUS_LAT 2U
    #endif

/* typedef EM_t_ARS_DynamicProperty */
    #ifndef ARS_OBJECT_PROPERTY_MOVING
        #define ARS_OBJECT_PROPERTY_MOVING 0U
    #endif
    #ifndef ARS_OBJECT_PROPERTY_STATIONARY
        #define ARS_OBJECT_PROPERTY_STATIONARY 1U
    #endif
    #ifndef ARS_OBJECT_PROPERTY_ONCOMING
        #define ARS_OBJECT_PROPERTY_ONCOMING 2U
    #endif

/* typedef EM_t_ARS_AbsMovingState */
    #ifndef ARS_OBJECT_MOVSTATE_STATIONARY
        #define ARS_OBJECT_MOVSTATE_STATIONARY 0U
    #endif
    #ifndef ARS_OBJECT_MOVSTATE_STOPPED
        #define ARS_OBJECT_MOVSTATE_STOPPED 1U
    #endif
    #ifndef ARS_OBJECT_MOVSTATE_MOVING
        #define ARS_OBJECT_MOVSTATE_MOVING 2U
    #endif

/* typedef EM_t_ARS_DynamicSubProperty */
    #ifndef ARS_OBJECT_SUBPROP_NORMAL
        #define ARS_OBJECT_SUBPROP_NORMAL 0U
    #endif
    #ifndef ARS_OBJECT_SUBPROP_CROSSING
        #define ARS_OBJECT_SUBPROP_CROSSING 1U
    #endif

/* typedef EM_t_ARS_Classification */
    #ifndef ARS_OBJCLASS_POINT
        #define ARS_OBJCLASS_POINT 0U
    #endif
    #ifndef ARS_OBJCLASS_CAR
        #define ARS_OBJCLASS_CAR 1U
    #endif
    #ifndef ARS_OBJCLASS_TRUCK
        #define ARS_OBJCLASS_TRUCK 2U
    #endif
    #ifndef ARS_OBJCLASS_PEDESTRIAN
        #define ARS_OBJCLASS_PEDESTRIAN 3U
    #endif
    #ifndef ARS_OBJCLASS_MOTORCYCLE
        #define ARS_OBJCLASS_MOTORCYCLE 4U
    #endif
    #ifndef ARS_OBJCLASS_BICYCLE
        #define ARS_OBJCLASS_BICYCLE 5U
    #endif
    #ifndef ARS_OBJCLASS_WIDE
        #define ARS_OBJCLASS_WIDE 6U
    #endif
    #ifndef ARS_OBJCLASS_UNCLASSIFIED
        #define ARS_OBJCLASS_UNCLASSIFIED 7U
    #endif

/* typedef EM_t_ARS_MeasuredSources */
    #ifndef ARS_MEAS_SEN_NONE
        #define ARS_MEAS_SEN_NONE 0U
    #endif
    #ifndef ARS_MEAS_SEN_FARSCAN
        #define ARS_MEAS_SEN_FARSCAN 1U
    #endif
    #ifndef ARS_MEAS_SEN_NEARSCAN
        #define ARS_MEAS_SEN_NEARSCAN 2U
    #endif
    #ifndef ARS_MEAS_SEN_GRID
        #define ARS_MEAS_SEN_GRID 4U
    #endif
    #ifndef ARS_MEAS_SEN_CAM
        #define ARS_MEAS_SEN_CAM 8U
    #endif
    #ifndef ARS_MEAS_SEN_1
        #define ARS_MEAS_SEN_1 16U
    #endif
    #ifndef ARS_MEAS_SEN_2
        #define ARS_MEAS_SEN_2 32U
    #endif
    #ifndef ARS_MEAS_SEN_3
        #define ARS_MEAS_SEN_3 64U
    #endif
    #ifndef ARS_MEAS_SEN_4
        #define ARS_MEAS_SEN_4 128U
    #endif

/* typedef EM_t_ObjRelationsClass */
    #ifndef ARS_LONGVEHICLE_TYPE_NORMAL
        #define ARS_LONGVEHICLE_TYPE_NORMAL 0U
    #endif
    #ifndef ARS_LONGVEHICLE_TYPE_REAL
        #define ARS_LONGVEHICLE_TYPE_REAL 1U
    #endif
    #ifndef ARS_LONGVEHICLE_TYPE_MIRROR
        #define ARS_LONGVEHICLE_TYPE_MIRROR 2U
    #endif
    #ifndef ARS_LONGVEHICLE_TYPE_SHADOW
        #define ARS_LONGVEHICLE_TYPE_SHADOW 3U
    #endif
    #ifndef ARS_LONGVEHICLE_TYPE_MIDDLE
        #define ARS_LONGVEHICLE_TYPE_MIDDLE 4U
    #endif

/* typedef EM_t_FOVOverlapFar */
    #ifndef ARS_INSIDE_FOV
        #define ARS_INSIDE_FOV 0U
    #endif
    #ifndef ARS_OUTSIDE_FOV
        #define ARS_OUTSIDE_FOV 1U
    #endif
    #ifndef ARS_BOUNDARY_FOV
        #define ARS_BOUNDARY_FOV 2U
    #endif

/* typedef EM_t_CamObjStatusBrakeLight */
    #ifndef EM_CAM_OBJ_BRAKE_LIGHT_UNKNOWN
        #define EM_CAM_OBJ_BRAKE_LIGHT_UNKNOWN 0U
    #endif
    #ifndef EM_CAM_OBJ_BRAKE_LIGHT_NO_BRAKING
        #define EM_CAM_OBJ_BRAKE_LIGHT_NO_BRAKING 1U
    #endif
    #ifndef EM_CAM_OBJ_BRAKE_LIGHT_REGULAR_BRAKING
        #define EM_CAM_OBJ_BRAKE_LIGHT_REGULAR_BRAKING 2U
    #endif
    #ifndef EM_CAM_OBJ_BRAKE_LIGHT_HEAVY_BREAKING
        #define EM_CAM_OBJ_BRAKE_LIGHT_HEAVY_BREAKING 3U
    #endif
    #ifndef EM_CAM_OBJ_BRAKE_LIGHT_SNA
        #define EM_CAM_OBJ_BRAKE_LIGHT_SNA 255U
    #endif

/* typedef EM_t_CamObjStatusTurnIndicator */
    #ifndef EM_CAM_OBJ_TURN_INDICATOR_UNKNOWN
        #define EM_CAM_OBJ_TURN_INDICATOR_UNKNOWN 0U
    #endif
    #ifndef EM_CAM_OBJ_TURN_INDICATOR_NO_FLASHING
        #define EM_CAM_OBJ_TURN_INDICATOR_NO_FLASHING 1U
    #endif
    #ifndef EM_CAM_OBJ_TURN_INDICATOR_FLASHING_LEFT
        #define EM_CAM_OBJ_TURN_INDICATOR_FLASHING_LEFT 2U
    #endif
    #ifndef EM_CAM_OBJ_TURN_INDICATOR_FLASHING_RIGHT
        #define EM_CAM_OBJ_TURN_INDICATOR_FLASHING_RIGHT 3U
    #endif
    #ifndef EM_CAM_OBJ_TURN_INDICATOR_HAZARD_FLASHING
        #define EM_CAM_OBJ_TURN_INDICATOR_HAZARD_FLASHING 4U
    #endif
    #ifndef EM_CAM_OBJ_TURN_INDICATOR_SNA
        #define EM_CAM_OBJ_TURN_INDICATOR_SNA 255U
    #endif

/* typedef EM_t_CamObjAssociatedLane */
    #ifndef EM_CAM_OBJ_ASSOC_LANE_UNKNOWN
        #define EM_CAM_OBJ_ASSOC_LANE_UNKNOWN 0U
    #endif
    #ifndef EM_CAM_OBJ_ASSOC_LANE_EGO
        #define EM_CAM_OBJ_ASSOC_LANE_EGO 1U
    #endif
    #ifndef EM_CAM_OBJ_ASSOC_LANE_LEFT
        #define EM_CAM_OBJ_ASSOC_LANE_LEFT 2U
    #endif
    #ifndef EM_CAM_OBJ_ASSOC_LANE_RIGHT
        #define EM_CAM_OBJ_ASSOC_LANE_RIGHT 3U
    #endif
    #ifndef EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_LEFT
        #define EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_LEFT 4U
    #endif
    #ifndef EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_RIGHT
        #define EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_RIGHT 5U
    #endif
    #ifndef EM_CAM_OBJ_ASSOC_LANE_SNA
        #define EM_CAM_OBJ_ASSOC_LANE_SNA 255U
    #endif

/* typedef EM_t_CamObjLaneChange */
    #ifndef EM_CAM_OBJ_LANE_CHANGE_NONE
        #define EM_CAM_OBJ_LANE_CHANGE_NONE 0U
    #endif
    #ifndef EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_RIGHT
        #define EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_RIGHT 1U
    #endif
    #ifndef EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_LEFT
        #define EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_LEFT 2U
    #endif
    #ifndef EM_CAM_OBJ_LANE_CHANGE_CUT_IN_RIGHT
        #define EM_CAM_OBJ_LANE_CHANGE_CUT_IN_RIGHT 3U
    #endif
    #ifndef EM_CAM_OBJ_LANE_CHANGE_CUT_IN_LEFT
        #define EM_CAM_OBJ_LANE_CHANGE_CUT_IN_LEFT 4U
    #endif

/* typedef u_RoadSide_t */
    #ifndef UNRELEVANT
        #define UNRELEVANT 0U
    #endif
    #ifndef LEFT_BORDER
        #define LEFT_BORDER 1U
    #endif
    #ifndef RIGHT_BORDER
        #define RIGHT_BORDER 2U
    #endif
    #ifndef ROAD_BORDER_LEFT
        #define ROAD_BORDER_LEFT 3U
    #endif
    #ifndef ROAD_BORDER_RIGHT
        #define ROAD_BORDER_RIGHT 4U
    #endif
    #ifndef ROAD_BORDER_COUPLED
        #define ROAD_BORDER_COUPLED 5U
    #endif

/* typedef EM_t_FusionSensorIndices */
    #ifndef EM_FUSION_SEN_IDX_CAM
        #define EM_FUSION_SEN_IDX_CAM 0U
    #endif

/* typedef EM_t_GenFusionCamFctFlags */
    #ifndef EM_GEN_FUSION_CAM_NO_FCT
        #define EM_GEN_FUSION_CAM_NO_FCT 0U
    #endif
    #ifndef EM_GEN_FUSION_CAM_CIPV
        #define EM_GEN_FUSION_CAM_CIPV 1U
    #endif
    #ifndef EM_GEN_FUSION_CAM_FCW
        #define EM_GEN_FUSION_CAM_FCW 2U
    #endif
    #ifndef EM_GEN_FUSION_CAM_FCB
        #define EM_GEN_FUSION_CAM_FCB 4U
    #endif

/* typedef EM_t_FusionSensorState */
    #ifndef EM_GEN_FUSION_SENS_STATE_FUSION_NA
        #define EM_GEN_FUSION_SENS_STATE_FUSION_NA 0U
    #endif
    #ifndef EM_GEN_FUSION_SENS_STATE_FUSION_OFF
        #define EM_GEN_FUSION_SENS_STATE_FUSION_OFF 1U
    #endif
    #ifndef EM_GEN_FUSION_SENS_STATE_SEN_TIMEOUT
        #define EM_GEN_FUSION_SENS_STATE_SEN_TIMEOUT 2U
    #endif
    #ifndef EM_GEN_FUSION_SENS_STATE_SEN_TMP_NA
        #define EM_GEN_FUSION_SENS_STATE_SEN_TMP_NA 4U
    #endif
    #ifndef EM_GEN_FUSION_SENS_STATE_REDUCED
        #define EM_GEN_FUSION_SENS_STATE_REDUCED 5U
    #endif
    #ifndef EM_GEN_FUSION_SENS_STATE_OK
        #define EM_GEN_FUSION_SENS_STATE_OK 6U
    #endif

/* typedef EM_t_GenObjShapePointState */
    #ifndef EM_GEN_OBJECT_SHAPE_POINT_STATE_INVALID
        #define EM_GEN_OBJECT_SHAPE_POINT_STATE_INVALID 0U
    #endif
    #ifndef EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED
        #define EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED 1U
    #endif
    #ifndef EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_ASSUMED
        #define EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_ASSUMED 2U
    #endif
    #ifndef EM_GEN_OBJECT_SHAPE_POINT_STATE_VISIBILITY_EDGE
        #define EM_GEN_OBJECT_SHAPE_POINT_STATE_VISIBILITY_EDGE 3U
    #endif
    #ifndef EM_GEN_OBJECT_SHAPE_POINT_STATE_MAX_DIFF_TYPES
        #define EM_GEN_OBJECT_SHAPE_POINT_STATE_MAX_DIFF_TYPES 4U
    #endif

/* typedef EM_t_GenObjDynamicProperty */
    #ifndef EM_GEN_OBJECT_DYN_PROPERTY_MOVING
        #define EM_GEN_OBJECT_DYN_PROPERTY_MOVING 0U
    #endif
    #ifndef EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY
        #define EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY 1U
    #endif
    #ifndef EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING
        #define EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING 2U
    #endif
    #ifndef EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT
        #define EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT 3U
    #endif
    #ifndef EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT
        #define EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT 4U
    #endif
    #ifndef EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN
        #define EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN 5U
    #endif
    #ifndef EM_GEN_OBJECT_DYN_PROPERTY_STOPPED
        #define EM_GEN_OBJECT_DYN_PROPERTY_STOPPED 6U
    #endif
    #ifndef EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES
        #define EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES 7U
    #endif

/* typedef EM_t_GenObjClassification */
    #ifndef EM_GEN_OBJECT_CLASS_POINT
        #define EM_GEN_OBJECT_CLASS_POINT 0U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_CAR
        #define EM_GEN_OBJECT_CLASS_CAR 1U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_TRUCK
        #define EM_GEN_OBJECT_CLASS_TRUCK 2U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_PEDESTRIAN
        #define EM_GEN_OBJECT_CLASS_PEDESTRIAN 3U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_MOTORCYCLE
        #define EM_GEN_OBJECT_CLASS_MOTORCYCLE 4U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_BICYCLE
        #define EM_GEN_OBJECT_CLASS_BICYCLE 5U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_WIDE
        #define EM_GEN_OBJECT_CLASS_WIDE 6U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_UNCLASSIFIED
        #define EM_GEN_OBJECT_CLASS_UNCLASSIFIED 7U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_OTHER_VEHICLE
        #define EM_GEN_OBJECT_CLASS_OTHER_VEHICLE 8U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_TL
        #define EM_GEN_OBJECT_CLASS_TL 9U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_MULTIPLE
        #define EM_GEN_OBJECT_CLASS_MULTIPLE 10U
    #endif
    #ifndef EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES
        #define EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES 11U
    #endif

/* typedef EM_t_GenObjOcclusionState */
    #ifndef EM_GEN_OBJECT_OCCL_NONE
        #define EM_GEN_OBJECT_OCCL_NONE 0U
    #endif
    #ifndef EM_GEN_OBJECT_OCCL_UNKNOWN
        #define EM_GEN_OBJECT_OCCL_UNKNOWN 1U
    #endif
    #ifndef EM_GEN_OBJECT_OCCL_PARTLY
        #define EM_GEN_OBJECT_OCCL_PARTLY 2U
    #endif
    #ifndef EM_GEN_OBJECT_OCCL_FULL
        #define EM_GEN_OBJECT_OCCL_FULL 3U
    #endif
    #ifndef EM_GEN_OBJECT_OCCL_MAX_DIFF_TYPES
        #define EM_GEN_OBJECT_OCCL_MAX_DIFF_TYPES 4U
    #endif

/* typedef EM_t_GenObjMaintenanceState */
    #ifndef EM_GEN_OBJECT_MT_STATE_DELETED
        #define EM_GEN_OBJECT_MT_STATE_DELETED 0U
    #endif
    #ifndef EM_GEN_OBJECT_MT_STATE_NEW
        #define EM_GEN_OBJECT_MT_STATE_NEW 1U
    #endif
    #ifndef EM_GEN_OBJECT_MT_STATE_MEASURED
        #define EM_GEN_OBJECT_MT_STATE_MEASURED 2U
    #endif
    #ifndef EM_GEN_OBJECT_MT_STATE_PREDICTED
        #define EM_GEN_OBJECT_MT_STATE_PREDICTED 3U
    #endif
    #ifndef EM_GEN_OBJECT_MT_STATE_INACTIVE
        #define EM_GEN_OBJECT_MT_STATE_INACTIVE 4U
    #endif
    #ifndef EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES
        #define EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES 5U
    #endif

/* typedef EM_t_GenObjSplitMergeState */
    #ifndef EM_GEN_OBJECT_SM_STATE_NONE
        #define EM_GEN_OBJECT_SM_STATE_NONE 0U
    #endif
    #ifndef EM_GEN_OBJECT_SM_STATE_MERGE
        #define EM_GEN_OBJECT_SM_STATE_MERGE 1U
    #endif
    #ifndef EM_GEN_OBJECT_SM_STATE_SPLIT
        #define EM_GEN_OBJECT_SM_STATE_SPLIT 2U
    #endif
    #ifndef EM_GEN_OBJECT_SM_STATE_MAX_DIFF_TYPES
        #define EM_GEN_OBJECT_SM_STATE_MAX_DIFF_TYPES 3U
    #endif

/* typedef EM_t_GenObjSensorSource */
    #ifndef EM_GEN_OBJECT_MS_NONE
        #define EM_GEN_OBJECT_MS_NONE 0U
    #endif
    #ifndef EM_GEN_OBJECT_MS_LRR
        #define EM_GEN_OBJECT_MS_LRR 1U
    #endif
    #ifndef EM_GEN_OBJECT_MS_MRR
        #define EM_GEN_OBJECT_MS_MRR 2U
    #endif
    #ifndef EM_GEN_OBJECT_MS_SRR
        #define EM_GEN_OBJECT_MS_SRR 4U
    #endif
    #ifndef EM_GEN_OBJECT_MS_SRL
        #define EM_GEN_OBJECT_MS_SRL 8U
    #endif
    #ifndef EM_GEN_OBJECT_MS_CAM
        #define EM_GEN_OBJECT_MS_CAM 16U
    #endif
    #ifndef EM_GEN_OBJECT_MS_USN
        #define EM_GEN_OBJECT_MS_USN 32U
    #endif
    #ifndef EM_GEN_OBJECT_MS_HFL
        #define EM_GEN_OBJECT_MS_HFL 64U
    #endif
    #ifndef EM_GEN_OBJECT_MS_IR
        #define EM_GEN_OBJECT_MS_IR 128U
    #endif

/* typedef EM_t_GenEbaHypCat */
    #ifndef FPS_EBA_HYP_CAT_NONE
        #define FPS_EBA_HYP_CAT_NONE 0U
    #endif
    #ifndef FPS_EBA_HYP_CAT_PED
        #define FPS_EBA_HYP_CAT_PED 1U
    #endif
    #ifndef FPS_EBA_HYP_CAT_VCL
        #define FPS_EBA_HYP_CAT_VCL 2U
    #endif
    #ifndef FPS_EBA_HYP_CAT_XING
        #define FPS_EBA_HYP_CAT_XING 4U
    #endif
    #ifndef FPS_EBA_HYP_CAT_ONC
        #define FPS_EBA_HYP_CAT_ONC 8U
    #endif
    #ifndef FPS_EBA_HYP_CAT_STAT
        #define FPS_EBA_HYP_CAT_STAT 16U
    #endif
    #ifndef FPS_EBA_HYP_CAT_CYCL
        #define FPS_EBA_HYP_CAT_CYCL 32U
    #endif
    #ifndef FPS_EBA_HYP_CAT_COMOV
        #define FPS_EBA_HYP_CAT_COMOV 64U
    #endif
    #ifndef FPS_EBA_HYP_CAT_ALL
        #define FPS_EBA_HYP_CAT_ALL 255U
    #endif

/* typedef EM_t_GenEbaInhibit */
    #ifndef FPS_EBA_INH_NONE
        #define FPS_EBA_INH_NONE 0U
    #endif
    #ifndef FPS_EBA_INH_LAT_WARN
        #define FPS_EBA_INH_LAT_WARN 1U
    #endif
    #ifndef FPS_EBA_INH_PRE_WARN
        #define FPS_EBA_INH_PRE_WARN 2U
    #endif
    #ifndef FPS_EBA_INH_ACU_WARN
        #define FPS_EBA_INH_ACU_WARN 4U
    #endif
    #ifndef FPS_EBA_INH_PRE_FILL
        #define FPS_EBA_INH_PRE_FILL 8U
    #endif
    #ifndef FPS_EBA_INH_HBA_THRD
        #define FPS_EBA_INH_HBA_THRD 16U
    #endif
    #ifndef FPS_EBA_INH_HBA_TBRK
        #define FPS_EBA_INH_HBA_TBRK 32U
    #endif
    #ifndef FPS_EBA_INH_PRECRASH
        #define FPS_EBA_INH_PRECRASH 64U
    #endif
    #ifndef FPS_EBA_INH_BRAKE_L1
        #define FPS_EBA_INH_BRAKE_L1 128U
    #endif
    #ifndef FPS_EBA_INH_BRAKE_L2
        #define FPS_EBA_INH_BRAKE_L2 256U
    #endif
    #ifndef FPS_EBA_INH_BRAKE_L3
        #define FPS_EBA_INH_BRAKE_L3 512U
    #endif
    #ifndef FPS_EBA_INH_ALL
        #define FPS_EBA_INH_ALL 65535U
    #endif

/* typedef EM_t_GenEbaObjClass */
    #ifndef FPS_EBA_CLASS_NONE
        #define FPS_EBA_CLASS_NONE 0U
    #endif
    #ifndef FPS_EBA_CLASS_UNKNOWN
        #define FPS_EBA_CLASS_UNKNOWN 1U
    #endif
    #ifndef FPS_EBA_CLASS_CAR
        #define FPS_EBA_CLASS_CAR 2U
    #endif
    #ifndef FPS_EBA_CLASS_TRUCK
        #define FPS_EBA_CLASS_TRUCK 3U
    #endif
    #ifndef FPS_EBA_CLASS_PEDESTRIAN
        #define FPS_EBA_CLASS_PEDESTRIAN 4U
    #endif
    #ifndef FPS_EBA_CLASS_CYCLIST
        #define FPS_EBA_CLASS_CYCLIST 5U
    #endif
    #ifndef FPS_EBA_CLASS_MOTORBIKE
        #define FPS_EBA_CLASS_MOTORBIKE 6U
    #endif
    #ifndef FPS_EBA_CLASS_VEHICLE
        #define FPS_EBA_CLASS_VEHICLE 7U
    #endif
    #ifndef FPS_EBA_CLASS_MAX_VALUE
        #define FPS_EBA_CLASS_MAX_VALUE 255U
    #endif

/* typedef EM_t_GenEbaQualifier */
    #ifndef FPS_EBA_QULF_ALL_PASSIVE
        #define FPS_EBA_QULF_ALL_PASSIVE 0U
    #endif
    #ifndef FPS_EBA_QULF_PRE_SELECT
        #define FPS_EBA_QULF_PRE_SELECT 1U
    #endif
    #ifndef FPS_EBA_QULF_WARN
        #define FPS_EBA_QULF_WARN 2U
    #endif
    #ifndef FPS_EBA_QULF_PRE_COND
        #define FPS_EBA_QULF_PRE_COND 4U
    #endif
    #ifndef FPS_EBA_QULF_PRECRASH
        #define FPS_EBA_QULF_PRECRASH 8U
    #endif
    #ifndef FPS_EBA_QULF_DRIVER_INITIATED
        #define FPS_EBA_QULF_DRIVER_INITIATED 16U
    #endif
    #ifndef FPS_EBA_QULF_LIMITED_INTERVENTION
        #define FPS_EBA_QULF_LIMITED_INTERVENTION 32U
    #endif
    #ifndef FPS_EBA_QULF_INTERVENTION
        #define FPS_EBA_QULF_INTERVENTION 64U
    #endif
    #ifndef FPS_EBA_QULF_MAX_VALUE
        #define FPS_EBA_QULF_MAX_VALUE 255U
    #endif

/* typedef EM_t_GenEbaObjMovState */
    #ifndef FPS_EBA_MOVSTATE_UNKNOWN
        #define FPS_EBA_MOVSTATE_UNKNOWN 0U
    #endif
    #ifndef FPS_EBA_MOVSTATE_STATIC
        #define FPS_EBA_MOVSTATE_STATIC 1U
    #endif
    #ifndef FPS_EBA_MOVSTATE_STOPPED
        #define FPS_EBA_MOVSTATE_STOPPED 2U
    #endif
    #ifndef FPS_EBA_MOVSTATE_COMOVING
        #define FPS_EBA_MOVSTATE_COMOVING 3U
    #endif
    #ifndef FPS_EBA_MOVSTATE_ONCOMING
        #define FPS_EBA_MOVSTATE_ONCOMING 4U
    #endif
    #ifndef FPS_EBA_MOVSTATE_CROSSING
        #define FPS_EBA_MOVSTATE_CROSSING 5U
    #endif
    #ifndef FPS_EBA_MOVSTATE_CROSSING_SOFT
        #define FPS_EBA_MOVSTATE_CROSSING_SOFT 6U
    #endif
    #ifndef FPS_EBA_MOVSTATE_MAX_VALUE
        #define FPS_EBA_MOVSTATE_MAX_VALUE 255U
    #endif

/* typedef eCycleMode_t */
    #ifndef EM_FCT_CYCLE_INIT
        #define EM_FCT_CYCLE_INIT 0U
    #endif
    #ifndef EM_FCT_CYCLE_DEFAULT
        #define EM_FCT_CYCLE_DEFAULT 1U
    #endif
    #ifndef EM_FCT_CYCLE_PREDICTION_MISSING_TARGETLIST
        #define EM_FCT_CYCLE_PREDICTION_MISSING_TARGETLIST 2U
    #endif
    #ifndef EM_FCT_CYCLE_REVERSE
        #define EM_FCT_CYCLE_REVERSE 3U
    #endif
    #ifndef EM_FCT_CYCLE_EM_VIOLATION
        #define EM_FCT_CYCLE_EM_VIOLATION 4U
    #endif

/* typedef eLongControlStatus_t */
    #ifndef FSRFunctionInit
        #define FSRFunctionInit 0U
    #endif
    #ifndef FSRFunctionDisabled
        #define FSRFunctionDisabled 1U
    #endif
    #ifndef FSRFunctionEnabledHold
        #define FSRFunctionEnabledHold 2U
    #endif
    #ifndef FSRFunctionEnabled
        #define FSRFunctionEnabled 3U
    #endif

/* typedef CodingValue_t */
    #ifndef FCT_CODING_WARNING
        #define FCT_CODING_WARNING 1U
    #endif
    #ifndef FCT_CODING_STAT_OBJ
        #define FCT_CODING_STAT_OBJ 2U
    #endif
    #ifndef FCT_CODING_LOW_SPEED
        #define FCT_CODING_LOW_SPEED 4U
    #endif
    #ifndef FCT_CODING_COUNTRY
        #define FCT_CODING_COUNTRY 8U
    #endif
    #ifndef FCT_CODING_PRE_BRK
        #define FCT_CODING_PRE_BRK 16U
    #endif
    #ifndef FCT_CODING_BRK_COND
        #define FCT_CODING_BRK_COND 32U
    #endif
    #ifndef FCT_CODING_IGN_SCHK
        #define FCT_CODING_IGN_SCHK 64U
    #endif
    #ifndef FCT_CODING_PRE_BRK2
        #define FCT_CODING_PRE_BRK2 128U
    #endif
    #ifndef FCT_CODING_MAX
        #define FCT_CODING_MAX 2147483648U
    #endif

/* typedef ucPredictState_t */
    #ifndef PRED_ACC_TRAJ_EGO_ONLY
        #define PRED_ACC_TRAJ_EGO_ONLY 0U
    #endif
    #ifndef PRED_ACC_TRAJ_ROAD_ESTI
        #define PRED_ACC_TRAJ_ROAD_ESTI 1U
    #endif
    #ifndef PRED_ACC_TRAJ_OBJ_TRACES
        #define PRED_ACC_TRAJ_OBJ_TRACES 2U
    #endif

/* typedef eDriverOverride_t */
    #ifndef eOverrideFdbk_Invalid
        #define eOverrideFdbk_Invalid 0U
    #endif
    #ifndef eOverrideFdbk_Active
        #define eOverrideFdbk_Active 1U
    #endif
    #ifndef eOverrideFdbk_Inactive
        #define eOverrideFdbk_Inactive 2U
    #endif
    #ifndef eOverrideFdbk_NotUsed
        #define eOverrideFdbk_NotUsed 3U
    #endif

/* typedef eDriverSetting_t */
    #ifndef eDriverSetting_Early
        #define eDriverSetting_Early 0U
    #endif
    #ifndef eDriverSetting_Middle
        #define eDriverSetting_Middle 1U
    #endif
    #ifndef eDriverSetting_Late
        #define eDriverSetting_Late 2U
    #endif
    #ifndef eDriverSetting_Invalid
        #define eDriverSetting_Invalid 3U
    #endif

/* typedef DIMInputSignalState_t */
    #ifndef DIMInputSignalState_OK
        #define DIMInputSignalState_OK 0U
    #endif
    #ifndef DIMInputSignalState_Default
        #define DIMInputSignalState_Default 1U
    #endif
    #ifndef DIMInputSignalState_Missing
        #define DIMInputSignalState_Missing 2U
    #endif
    #ifndef DIMInputSignalState_BadQuality
        #define DIMInputSignalState_BadQuality 3U
    #endif
    #ifndef DIMInputSignalState_Suspicious
        #define DIMInputSignalState_Suspicious 4U
    #endif
    #ifndef DIMInputSignalState_Max
        #define DIMInputSignalState_Max 5U
    #endif

/* typedef eTurnIndicator_t */
    #ifndef eTurnIndicator_Off
        #define eTurnIndicator_Off 0U
    #endif
    #ifndef eTurnIndicator_Left
        #define eTurnIndicator_Left 1U
    #endif
    #ifndef eTurnIndicator_Right
        #define eTurnIndicator_Right 2U
    #endif
    #ifndef eTurnIndicator_Both
        #define eTurnIndicator_Both 3U
    #endif
    #ifndef eTurnIndicator_Invalid
        #define eTurnIndicator_Invalid 4U
    #endif

/* typedef ePowerTrainEngaged_t */
    #ifndef ePowerTrain_Engaged
        #define ePowerTrain_Engaged 0U
    #endif
    #ifndef ePowerTrain_Disengaged
        #define ePowerTrain_Disengaged 1U
    #endif
    #ifndef ePowerTrain_Invalid
        #define ePowerTrain_Invalid 2U
    #endif

/* typedef DIMOutMonState_t */
    #ifndef eDimMonState_NotPossible
        #define eDimMonState_NotPossible 0U
    #endif
    #ifndef eDimMonState_Limited
        #define eDimMonState_Limited 1U
    #endif
    #ifndef eDimMonState_Unlimited
        #define eDimMonState_Unlimited 2U
    #endif

/* typedef eDriverAttentionState_t */
    #ifndef eDriverAttentionState_Unknown
        #define eDriverAttentionState_Unknown 0U
    #endif
    #ifndef eDriverAttentionState_Low
        #define eDriverAttentionState_Low 1U
    #endif
    #ifndef eDriverAttentionState_High
        #define eDriverAttentionState_High 2U
    #endif
    #ifndef eDriverAttentionState_Higher
        #define eDriverAttentionState_Higher 3U
    #endif
    #ifndef eDriverAttentionState_VeryHigh
        #define eDriverAttentionState_VeryHigh 4U
    #endif
    #ifndef eDriverAttentionState_Unattended
        #define eDriverAttentionState_Unattended 5U
    #endif

/* typedef eDriverFeedbackState_t */
    #ifndef eDriverFeedbackState_Negative
        #define eDriverFeedbackState_Negative 0U
    #endif
    #ifndef eDriverFeedbackState_WeakNegative
        #define eDriverFeedbackState_WeakNegative 1U
    #endif
    #ifndef eDriverFeedbackState_NoNegative
        #define eDriverFeedbackState_NoNegative 2U
    #endif
    #ifndef eDriverFeedbackState_NoPositive
        #define eDriverFeedbackState_NoPositive 3U
    #endif
    #ifndef eDriverFeedbackState_WeakPositive
        #define eDriverFeedbackState_WeakPositive 4U
    #endif
    #ifndef eDriverFeedbackState_Positive
        #define eDriverFeedbackState_Positive 5U
    #endif
    #ifndef eDriverFeedbackState_StrongPositive
        #define eDriverFeedbackState_StrongPositive 6U
    #endif

/* typedef eDriverActivityState_t */
    #ifndef eDriverActivity_Inactive
        #define eDriverActivity_Inactive 0U
    #endif
    #ifndef eDriverActivity_MissingConf
        #define eDriverActivity_MissingConf 1U
    #endif
    #ifndef eDriverActivity_VeryActive
        #define eDriverActivity_VeryActive 2U
    #endif
    #ifndef eDriverActivity_EmergencySteer
        #define eDriverActivity_EmergencySteer 3U
    #endif

/* typedef FCTSubChainQualifier_t */
    #ifndef eSystemOn
        #define eSystemOn 0U
    #endif
    #ifndef eSystemOff
        #define eSystemOff 1U
    #endif
    #ifndef eSystemInvalid
        #define eSystemInvalid 2U
    #endif

/* typedef BCM_Status_t */
    #ifndef eBcmStateOn
        #define eBcmStateOn 0U
    #endif
    #ifndef eBcmStateOff
        #define eBcmStateOff 1U
    #endif
    #ifndef eBcmStateInvalid
        #define eBcmStateInvalid 2U
    #endif

/* typedef SCS_AEB_HBA_Resp_t */
    #ifndef NO_REQUEST
        #define NO_REQUEST 0U
    #endif
    #ifndef REQUEST_HONORED
        #define REQUEST_HONORED 1U
    #endif
    #ifndef LOST_ARBITRATION
        #define LOST_ARBITRATION 2U
    #endif
    #ifndef CONTROL_NOT_ALLOWED
        #define CONTROL_NOT_ALLOWED 3U
    #endif
    #ifndef PRECOND_NOT_SATISFIED
        #define PRECOND_NOT_SATISFIED 4U
    #endif

/* typedef EBA_Active_Condition_Custom_t */
    #ifndef LOST_COMMUNICATION_GW
        #define LOST_COMMUNICATION_GW 1U
    #endif
    #ifndef LOST_COMMUNICATION_SCS
        #define LOST_COMMUNICATION_SCS 2U
    #endif
    #ifndef VSE_ACTIVE
        #define VSE_ACTIVE 4U
    #endif
    #ifndef ABS_FAILURE
        #define ABS_FAILURE 8U
    #endif
    #ifndef ABS_AVAILABLE
        #define ABS_AVAILABLE 16U
    #endif
    #ifndef VSE_FAILURE
        #define VSE_FAILURE 32U
    #endif

/* typedef eMainSwitch_t */
    #ifndef eMainSwitch_Active
        #define eMainSwitch_Active 0U
    #endif
    #ifndef eMainSwitch_Inactive
        #define eMainSwitch_Inactive 1U
    #endif
    #ifndef eMainSwitch_NotUsed
        #define eMainSwitch_NotUsed 2U
    #endif
    #ifndef eMainSwitch_Invalid
        #define eMainSwitch_Invalid 3U
    #endif

/* typedef eFunctionSwitch_t */
    #ifndef eEBASwitch_LongVehDW
        #define eEBASwitch_LongVehDW 1U
    #endif
    #ifndef eEBASwitch_LongVehFCW1
        #define eEBASwitch_LongVehFCW1 2U
    #endif
    #ifndef eEBASwitch_LongVehFCW2
        #define eEBASwitch_LongVehFCW2 4U
    #endif
    #ifndef eEBASwitch_LongVehFCW3
        #define eEBASwitch_LongVehFCW3 8U
    #endif
    #ifndef eEBASwitch_LongVehBRK
        #define eEBASwitch_LongVehBRK 16U
    #endif
    #ifndef eEBASwitch_LongVruDW
        #define eEBASwitch_LongVruDW 32U
    #endif
    #ifndef eEBASwitch_LongVruFCW1
        #define eEBASwitch_LongVruFCW1 64U
    #endif
    #ifndef eEBASwitch_LongVruFCW2
        #define eEBASwitch_LongVruFCW2 128U
    #endif
    #ifndef eEBASwitch_LongVruFCW3
        #define eEBASwitch_LongVruFCW3 256U
    #endif
    #ifndef eEBASwitch_LongVruBRK
        #define eEBASwitch_LongVruBRK 512U
    #endif
    #ifndef eEBASwitch_CrossVehDW
        #define eEBASwitch_CrossVehDW 1024U
    #endif
    #ifndef eEBASwitch_CrossVehFCW1
        #define eEBASwitch_CrossVehFCW1 2048U
    #endif
    #ifndef eEBASwitch_CrossVehFCW2
        #define eEBASwitch_CrossVehFCW2 4096U
    #endif
    #ifndef eEBASwitch_CrossVehFCW3
        #define eEBASwitch_CrossVehFCW3 8192U
    #endif
    #ifndef eEBASwitch_CrossVehBRK
        #define eEBASwitch_CrossVehBRK 16384U
    #endif
    #ifndef eEBASwitch_CrossVruDW
        #define eEBASwitch_CrossVruDW 32768U
    #endif
    #ifndef eEBASwitch_CrossVruFCW1
        #define eEBASwitch_CrossVruFCW1 65536U
    #endif
    #ifndef eEBASwitch_CrossVruFCW2
        #define eEBASwitch_CrossVruFCW2 131072U
    #endif
    #ifndef eEBASwitch_CrossVruFCW3
        #define eEBASwitch_CrossVruFCW3 262144U
    #endif
    #ifndef eEBASwitch_CrossVruBRK
        #define eEBASwitch_CrossVruBRK 524288U
    #endif
    #ifndef eEBASwitch_OncVehDW
        #define eEBASwitch_OncVehDW 1048576U
    #endif
    #ifndef eEBASwitch_OncVehFCW1
        #define eEBASwitch_OncVehFCW1 2097152U
    #endif
    #ifndef eEBASwitch_OncVehFCW2
        #define eEBASwitch_OncVehFCW2 4194304U
    #endif
    #ifndef eEBASwitch_OncVehFCW3
        #define eEBASwitch_OncVehFCW3 8388608U
    #endif
    #ifndef eEBASwitch_OncVehBRK
        #define eEBASwitch_OncVehBRK 16777216U
    #endif
    #ifndef eEBASwitch_OncVruDW
        #define eEBASwitch_OncVruDW 33554432U
    #endif
    #ifndef eEBASwitch_OncVruFCW1
        #define eEBASwitch_OncVruFCW1 67108864U
    #endif
    #ifndef eEBASwitch_OncVruFCW2
        #define eEBASwitch_OncVruFCW2 134217728U
    #endif
    #ifndef eEBASwitch_OncVruFCW3
        #define eEBASwitch_OncVruFCW3 268435456U
    #endif
    #ifndef eEBASwitch_OncVruBRK
        #define eEBASwitch_OncVruBRK 536870912U
    #endif
    #ifndef eEBASwitch_MaxValue
        #define eEBASwitch_MaxValue 2147483648U
    #endif

/* typedef eEBAFctChan_t */
    #ifndef eEBAFctChan_Unknown
        #define eEBAFctChan_Unknown 0U
    #endif
    #ifndef eEBAFctChan_Vehicle
        #define eEBAFctChan_Vehicle 1U
    #endif
    #ifndef eEBAFctChan_Pedestrian
        #define eEBAFctChan_Pedestrian 2U
    #endif
    #ifndef eEBAFctChan_Unclassified
        #define eEBAFctChan_Unclassified 4U
    #endif
    #ifndef eEBAFctChan_Crossing
        #define eEBAFctChan_Crossing 8U
    #endif
    #ifndef eEBAFctChan_Cyclist
        #define eEBAFctChan_Cyclist 16U
    #endif
    #ifndef eEBAFctChan_DrvIntoOncoming
        #define eEBAFctChan_DrvIntoOncoming 32U
    #endif
    #ifndef eEBAFctChan_HeadOn
        #define eEBAFctChan_HeadOn 64U
    #endif

/* typedef eGeneratorControl_t */
    #ifndef eEBAGenerator_No
        #define eEBAGenerator_No 0U
    #endif
    #ifndef eEBAGenerator_KeepVoltage
        #define eEBAGenerator_KeepVoltage 1U
    #endif
    #ifndef eEBAGenerator_BoostVoltage
        #define eEBAGenerator_BoostVoltage 2U
    #endif

/* typedef eEBASignalState_t */
    #ifndef eEBAOn_Inactive
        #define eEBAOn_Inactive 0U
    #endif
    #ifndef eEBAOn_Moving
        #define eEBAOn_Moving 1U
    #endif
    #ifndef eEBAOn_Standing
        #define eEBAOn_Standing 2U
    #endif
    #ifndef eEBAOn_Halted
        #define eEBAOn_Halted 3U
    #endif
    #ifndef eEBAOn_CrossFrLeft
        #define eEBAOn_CrossFrLeft 4U
    #endif
    #ifndef eEBAOn_CrossFrRight
        #define eEBAOn_CrossFrRight 5U
    #endif
    #ifndef eEBAOn_Oncoming
        #define eEBAOn_Oncoming 6U
    #endif

/* typedef eWarnSens_t */
    #ifndef eEBAHaptSensNone
        #define eEBAHaptSensNone 0U
    #endif
    #ifndef eEBAHaptSensLow
        #define eEBAHaptSensLow 1U
    #endif
    #ifndef eEBAHaptSensMid
        #define eEBAHaptSensMid 2U
    #endif
    #ifndef eEBAHaptSensHigh
        #define eEBAHaptSensHigh 3U
    #endif

/* typedef eEBARelObjQualifier_t */
    #ifndef eEBAObjRelNo
        #define eEBAObjRelNo 0U
    #endif
    #ifndef eEBAObjRelHyp
        #define eEBAObjRelHyp 1U
    #endif
    #ifndef eEBAObjRelFctMod
        #define eEBAObjRelFctMod 2U
    #endif

/* typedef eFunctionQualifier_t */
    #ifndef eStatus_FCW_Coded
        #define eStatus_FCW_Coded 1U
    #endif
    #ifndef eStatus_FCW_Switched
        #define eStatus_FCW_Switched 2U
    #endif
    #ifndef eStatus_FCW_NoError
        #define eStatus_FCW_NoError 4U
    #endif
    #ifndef eStatus_FCW_NoDegraded
        #define eStatus_FCW_NoDegraded 8U
    #endif
    #ifndef eStatus_AutoBrk_Coded
        #define eStatus_AutoBrk_Coded 16U
    #endif
    #ifndef eStatus_AutoBrk_Switched
        #define eStatus_AutoBrk_Switched 32U
    #endif
    #ifndef eStatus_AutoBrk_NoError
        #define eStatus_AutoBrk_NoError 64U
    #endif
    #ifndef eStatus_AutoBrk_NoDegraded
        #define eStatus_AutoBrk_NoDegraded 128U
    #endif
    #ifndef eStatus_DistWarn_Coded
        #define eStatus_DistWarn_Coded 256U
    #endif
    #ifndef eStatus_DistWarn_Switched
        #define eStatus_DistWarn_Switched 512U
    #endif
    #ifndef eStatus_DistWarn_NoError
        #define eStatus_DistWarn_NoError 1024U
    #endif
    #ifndef eStatus_DistWarn_NoDegraded
        #define eStatus_DistWarn_NoDegraded 2048U
    #endif
    #ifndef eStatus_BrakeAssist_Coded
        #define eStatus_BrakeAssist_Coded 4096U
    #endif
    #ifndef eStatus_BrakeAssist_Switched
        #define eStatus_BrakeAssist_Switched 8192U
    #endif
    #ifndef eStatus_BrakeAssist_NoError
        #define eStatus_BrakeAssist_NoError 16384U
    #endif
    #ifndef eStatus_BrakeAssist_NoDegraded
        #define eStatus_BrakeAssist_NoDegraded 32768U
    #endif
    #ifndef eStatus_BrakePreCond_Coded
        #define eStatus_BrakePreCond_Coded 65536U
    #endif
    #ifndef eStatus_BrakePreCond_Switched
        #define eStatus_BrakePreCond_Switched 131072U
    #endif
    #ifndef eStatus_BrakePreCond_NoError
        #define eStatus_BrakePreCond_NoError 262144U
    #endif
    #ifndef eStatus_BrakePreCond_NoDegraded
        #define eStatus_BrakePreCond_NoDegraded 524288U
    #endif
    #ifndef eStatus_OccSafety_Coded
        #define eStatus_OccSafety_Coded 1048576U
    #endif
    #ifndef eStatus_OccSafety_Switched
        #define eStatus_OccSafety_Switched 2097152U
    #endif
    #ifndef eStatus_OccSafety_NoError
        #define eStatus_OccSafety_NoError 4194304U
    #endif
    #ifndef eStatus_OccSafety_NoDegraded
        #define eStatus_OccSafety_NoDegraded 8388608U
    #endif
    #ifndef eStatus_Spare1_Coded
        #define eStatus_Spare1_Coded 16777216U
    #endif
    #ifndef eStatus_Spare1_Switched
        #define eStatus_Spare1_Switched 33554432U
    #endif
    #ifndef eStatus_Spare1_NoError
        #define eStatus_Spare1_NoError 67108864U
    #endif
    #ifndef eStatus_Spare1_NoDegraded
        #define eStatus_Spare1_NoDegraded 134217728U
    #endif
    #ifndef eStatus_Spare2_Coded
        #define eStatus_Spare2_Coded 268435456U
    #endif
    #ifndef eStatus_Spare2_Switched
        #define eStatus_Spare2_Switched 536870912U
    #endif
    #ifndef eStatus_Spare2_NoError
        #define eStatus_Spare2_NoError 1073741824U
    #endif
    #ifndef eStatus_Spare2_NoDegraded
        #define eStatus_Spare2_NoDegraded 2147483648U
    #endif

/* typedef eThreatLvl_t */
    #ifndef eThrtLvl_No
        #define eThrtLvl_No 0U
    #endif
    #ifndef eThrtLvl_Low
        #define eThrtLvl_Low 1U
    #endif
    #ifndef eThrtLvl_Mid
        #define eThrtLvl_Mid 2U
    #endif
    #ifndef eThrtLvl_High
        #define eThrtLvl_High 3U
    #endif

/* typedef FCTObjUsageState_t */
    #ifndef OBJ_USAGE_IDLE
        #define OBJ_USAGE_IDLE 0U
    #endif
    #ifndef OBJ_USAGE_CONTROL
        #define OBJ_USAGE_CONTROL 1U
    #endif
    #ifndef OBJ_USAGE_DISPLAY
        #define OBJ_USAGE_DISPLAY 2U
    #endif
    #ifndef OBJ_USAGE_ALERT
        #define OBJ_USAGE_ALERT 4U
    #endif

/* typedef FCT_OP_MODE_t */
    #ifndef FCT_MOD_STARTUP
        #define FCT_MOD_STARTUP 0U
    #endif
    #ifndef FCT_MOD_INIT
        #define FCT_MOD_INIT 1U
    #endif
    #ifndef FCT_MOD_RUNNING
        #define FCT_MOD_RUNNING 2U
    #endif
    #ifndef FCT_MOD_SHUTDOWN
        #define FCT_MOD_SHUTDOWN 3U
    #endif
    #ifndef FCT_MOD_PAUSE
        #define FCT_MOD_PAUSE 4U
    #endif

/* typedef eGDBPDStates_t */
    #ifndef GDB_PD_OFF
        #define GDB_PD_OFF 0U
    #endif
    #ifndef GDB_PD_ON
        #define GDB_PD_ON 1U
    #endif
    #ifndef GDB_PD_STARTUP
        #define GDB_PD_STARTUP 2U
    #endif
    #ifndef GDB_PD_ROADBEAM_TEST
        #define GDB_PD_ROADBEAM_TEST 3U
    #endif

/* typedef eTraceBracketBitMasks_t */
    #ifndef TRBRM_ExtRelevObj
        #define TRBRM_ExtRelevObj 1U
    #endif
    #ifndef TRBRM_ExtObjApprox
        #define TRBRM_ExtObjApprox 2U
    #endif
    #ifndef TRBRM_ResCurveOutBorder
        #define TRBRM_ResCurveOutBorder 4U
    #endif
    #ifndef TRBRM_ResTgtOutsideBracket
        #define TRBRM_ResTgtOutsideBracket 8U
    #endif
    #ifndef TRBRM_ResByRoadBorder
        #define TRBRM_ResByRoadBorder 16U
    #endif
    #ifndef TRBRM_ResNeighborRelObj
        #define TRBRM_ResNeighborRelObj 32U
    #endif
    #ifndef TRBRM_ExtRoadBorder
        #define TRBRM_ExtRoadBorder 64U
    #endif
    #ifndef TRBRM_ExtCurveInnerBorder
        #define TRBRM_ExtCurveInnerBorder 128U
    #endif
    #ifndef TRBRM_ExtRoadBorderCurveInner
        #define TRBRM_ExtRoadBorderCurveInner 256U
    #endif
    #ifndef TRBRM_ExtFollowObjInCurve
        #define TRBRM_ExtFollowObjInCurve 512U
    #endif
    #ifndef TRBRM_ExtRoadWorksBorder
        #define TRBRM_ExtRoadWorksBorder 1024U
    #endif

/* typedef eEBAObjQuality_t */
    #ifndef CDObjEbaQual_Min
        #define CDObjEbaQual_Min 0U
    #endif
    #ifndef CDObjEbaQual_NotAlignd
        #define CDObjEbaQual_NotAlignd 84U
    #endif
    #ifndef CDObjEbaQual_NoCamConf
        #define CDObjEbaQual_NoCamConf 96U
    #endif
    #ifndef CDObjEbaQual_NoCamAvail
        #define CDObjEbaQual_NoCamAvail 97U
    #endif
    #ifndef CDObjEbaQual_CamConf
        #define CDObjEbaQual_CamConf 98U
    #endif
    #ifndef CDObjEbaQual_Max
        #define CDObjEbaQual_Max 100U
    #endif

/* typedef FCTStateSig_t */
    #ifndef eFCT_STATE_SIG_INACTIVE
        #define eFCT_STATE_SIG_INACTIVE 0U
    #endif
    #ifndef eFCT_STATE_SIG_ACTIVE
        #define eFCT_STATE_SIG_ACTIVE 1U
    #endif
    #ifndef eFCT_STATE_SIG_INVALID
        #define eFCT_STATE_SIG_INVALID 2U
    #endif

/* typedef SpeedUnitEnum_t */
    #ifndef SPD_UNIT_KMH
        #define SPD_UNIT_KMH 0U
    #endif
    #ifndef SPD_UNIT_MPH
        #define SPD_UNIT_MPH 1U
    #endif

/* typedef t_NavStreetType */
    #ifndef NAV_STT_UNKNOWN
        #define NAV_STT_UNKNOWN 0U
    #endif
    #ifndef NAV_STT_RAILTRACK
        #define NAV_STT_RAILTRACK 1U
    #endif
    #ifndef NAV_STT_TRAFFICCALMZONE_BIDIRECTION
        #define NAV_STT_TRAFFICCALMZONE_BIDIRECTION 2U
    #endif
    #ifndef NAV_STT_TRAFFICCALMZONE_ONEWAY
        #define NAV_STT_TRAFFICCALMZONE_ONEWAY 3U
    #endif
    #ifndef NAV_STT_RESIDENTIAL_BIDIRECTION
        #define NAV_STT_RESIDENTIAL_BIDIRECTION 4U
    #endif
    #ifndef NAV_STT_RESIDENTIAL_ONEWAY
        #define NAV_STT_RESIDENTIAL_ONEWAY 5U
    #endif
    #ifndef NAV_STT_URBAN_BIDIRECTION
        #define NAV_STT_URBAN_BIDIRECTION 6U
    #endif
    #ifndef NAV_STT_URBAN_ONEWAY
        #define NAV_STT_URBAN_ONEWAY 7U
    #endif
    #ifndef NAV_STT_URBAN_DIVIDER
        #define NAV_STT_URBAN_DIVIDER 8U
    #endif
    #ifndef NAV_STT_URBAN_INTERSTATE_HIGHWAY
        #define NAV_STT_URBAN_INTERSTATE_HIGHWAY 9U
    #endif
    #ifndef NAV_STT_URBAN_INTERSTATE_HIGHWAY_DIVIDER
        #define NAV_STT_URBAN_INTERSTATE_HIGHWAY_DIVIDER 10U
    #endif
    #ifndef NAV_STT_COUNTRY_ROAD
        #define NAV_STT_COUNTRY_ROAD 11U
    #endif
    #ifndef NAV_STT_COUNTRY_ROAD_DIVIDER
        #define NAV_STT_COUNTRY_ROAD_DIVIDER 12U
    #endif
    #ifndef NAV_STT_FEDERAL_HIGHWAY
        #define NAV_STT_FEDERAL_HIGHWAY 13U
    #endif
    #ifndef NAV_STT_FEDERAL_HIGHWAY_DIVIDER
        #define NAV_STT_FEDERAL_HIGHWAY_DIVIDER 14U
    #endif
    #ifndef NAV_STT_FEDERAL_HIGHWAY_RAMP
        #define NAV_STT_FEDERAL_HIGHWAY_RAMP 15U
    #endif
    #ifndef NAV_STT_FEDERAL_HIGHWAY_EXIT
        #define NAV_STT_FEDERAL_HIGHWAY_EXIT 16U
    #endif
    #ifndef NAV_STT_FEDERAL_HIGHWAY_RAMP_EXIT
        #define NAV_STT_FEDERAL_HIGHWAY_RAMP_EXIT 17U
    #endif
    #ifndef NAV_STT_INTERSTATE_HIGHWAY
        #define NAV_STT_INTERSTATE_HIGHWAY 18U
    #endif
    #ifndef NAV_STT_INTERSTATE_HIGHWAY_RAMP
        #define NAV_STT_INTERSTATE_HIGHWAY_RAMP 19U
    #endif
    #ifndef NAV_STT_INTERSTATE_HIGHWAY_EXIT
        #define NAV_STT_INTERSTATE_HIGHWAY_EXIT 20U
    #endif
    #ifndef NAV_STT_INTERSTATE_HIGHWAY_RAMP_EXIT
        #define NAV_STT_INTERSTATE_HIGHWAY_RAMP_EXIT 21U
    #endif
    #ifndef NAV_STT_FERRY
        #define NAV_STT_FERRY 22U
    #endif
    #ifndef NAV_STT_RACETRACK
        #define NAV_STT_RACETRACK 23U
    #endif
    #ifndef NAV_STT_SIGNAL_UNFILLED
        #define NAV_STT_SIGNAL_UNFILLED 255U
    #endif

/* typedef t_EBACodingParamFctModsIdx */
    #ifndef eEBACodingIdx_LongVehMov
        #define eEBACodingIdx_LongVehMov 0U
    #endif
    #ifndef eEBACodingIdx_LongVehStat
        #define eEBACodingIdx_LongVehStat 1U
    #endif
    #ifndef eEBACodingIdx_LongPedMov
        #define eEBACodingIdx_LongPedMov 2U
    #endif
    #ifndef eEBACodingIdx_LongPedStat
        #define eEBACodingIdx_LongPedStat 3U
    #endif
    #ifndef eEBACodingIdx_LongCyclMov
        #define eEBACodingIdx_LongCyclMov 4U
    #endif
    #ifndef eEBACodingIdx_LongCyclStat
        #define eEBACodingIdx_LongCyclStat 5U
    #endif
    #ifndef eEBACodingIdx_LongObsMov
        #define eEBACodingIdx_LongObsMov 6U
    #endif
    #ifndef eEBACodingIdx_LongObsStat
        #define eEBACodingIdx_LongObsStat 7U
    #endif
    #ifndef eEBACodingIdx_CrossVehMov
        #define eEBACodingIdx_CrossVehMov 8U
    #endif
    #ifndef eEBACodingIdx_CrossVehStat
        #define eEBACodingIdx_CrossVehStat 9U
    #endif
    #ifndef eEBACodingIdx_CrossPedMov
        #define eEBACodingIdx_CrossPedMov 10U
    #endif
    #ifndef eEBACodingIdx_CrossPedStat
        #define eEBACodingIdx_CrossPedStat 11U
    #endif
    #ifndef eEBACodingIdx_CrossCyclMov
        #define eEBACodingIdx_CrossCyclMov 12U
    #endif
    #ifndef eEBACodingIdx_CrossCyclStat
        #define eEBACodingIdx_CrossCyclStat 13U
    #endif
    #ifndef eEBACodingIdx_CrossObsMov
        #define eEBACodingIdx_CrossObsMov 14U
    #endif
    #ifndef eEBACodingIdx_CrossObsStat
        #define eEBACodingIdx_CrossObsStat 15U
    #endif
    #ifndef eEBACodingIdx_OncVehMov
        #define eEBACodingIdx_OncVehMov 16U
    #endif
    #ifndef eEBACodingIdx_OncVehStat
        #define eEBACodingIdx_OncVehStat 17U
    #endif
    #ifndef eEBACodingIdx_OncPedMov
        #define eEBACodingIdx_OncPedMov 18U
    #endif
    #ifndef eEBACodingIdx_OncPedStat
        #define eEBACodingIdx_OncPedStat 19U
    #endif
    #ifndef eEBACodingIdx_OncCyclMov
        #define eEBACodingIdx_OncCyclMov 20U
    #endif
    #ifndef eEBACodingIdx_OncCyclStat
        #define eEBACodingIdx_OncCyclStat 21U
    #endif
    #ifndef eEBACodingIdx_OncObsMov
        #define eEBACodingIdx_OncObsMov 22U
    #endif
    #ifndef eEBACodingIdx_OncObsStat
        #define eEBACodingIdx_OncObsStat 23U
    #endif

/* typedef DriveMode_t_e */
    #ifndef NORMAL
        #define NORMAL 0U
    #endif
    #ifndef COMFORT
        #define COMFORT 1U
    #endif
    #ifndef COMFORT_PLUS
        #define COMFORT_PLUS 2U
    #endif
    #ifndef SPORT
        #define SPORT 3U
    #endif
    #ifndef SPORT_PLUS
        #define SPORT_PLUS 4U
    #endif
    #ifndef ECO
        #define ECO 5U
    #endif
    #ifndef ECO_PLUS
        #define ECO_PLUS 6U
    #endif

/* typedef eCDHypothesisType_t */
    #ifndef CDHypothesisType_No
        #define CDHypothesisType_No 0U
    #endif
    #ifndef CDHypothesisType_RunUp
        #define CDHypothesisType_RunUp 1U
    #endif
    #ifndef CDHypothesisType_RunUpBraking
        #define CDHypothesisType_RunUpBraking 2U
    #endif
    #ifndef CDHypothesisType_RunUpStationary
        #define CDHypothesisType_RunUpStationary 3U
    #endif
    #ifndef CDHypothesisType_Static
        #define CDHypothesisType_Static 4U
    #endif
    #ifndef CDHypothesisType_ACC
        #define CDHypothesisType_ACC 5U
    #endif
    #ifndef CDHypothesisType_Pass
        #define CDHypothesisType_Pass 6U
    #endif
    #ifndef CDHypothesisType_CutIn
        #define CDHypothesisType_CutIn 7U
    #endif
    #ifndef CDHypothesisType_Collision
        #define CDHypothesisType_Collision 8U
    #endif
    #ifndef CDHypothesisType_CollisionUnavoidable
        #define CDHypothesisType_CollisionUnavoidable 9U
    #endif
    #ifndef CDHypothesisType_PedCollision
        #define CDHypothesisType_PedCollision 10U
    #endif
    #ifndef CDHypothesisType_PedPass
        #define CDHypothesisType_PedPass 11U
    #endif
    #ifndef CDHypothesisType_Crossing
        #define CDHypothesisType_Crossing 12U
    #endif
    #ifndef CDHypothesisType_CyclColl
        #define CDHypothesisType_CyclColl 13U
    #endif
    #ifndef CDHypothesisType_RunupCoMoving
        #define CDHypothesisType_RunupCoMoving 14U
    #endif
    #ifndef CDHypothesisType_DriveIntoOncoming
        #define CDHypothesisType_DriveIntoOncoming 15U
    #endif
    #ifndef CDHypothesisType_HeadOn
        #define CDHypothesisType_HeadOn 16U
    #endif
    #ifndef CDHypothesisType_TurnIntoVRU
        #define CDHypothesisType_TurnIntoVRU 17U
    #endif
    #ifndef CDHypothesisType_DriveIntoSloMo
        #define CDHypothesisType_DriveIntoSloMo 18U
    #endif
    #ifndef CDHypothesisType_Reserved1
        #define CDHypothesisType_Reserved1 19U
    #endif
    #ifndef CDHypothesisType_Reserved2
        #define CDHypothesisType_Reserved2 20U
    #endif
    #ifndef CDHypothesisType_Reserved3
        #define CDHypothesisType_Reserved3 21U
    #endif

/* typedef eEBAObjectClass_t */
    #ifndef EBAObjectClass_NotAvail
        #define EBAObjectClass_NotAvail 0U
    #endif
    #ifndef EBAObjectClass_Pedestrian
        #define EBAObjectClass_Pedestrian 1U
    #endif
    #ifndef EBAObjectClass_Vehicle
        #define EBAObjectClass_Vehicle 2U
    #endif
    #ifndef EBAObjectClass_Obstacle
        #define EBAObjectClass_Obstacle 3U
    #endif
    #ifndef EBAObjectClass_Cyclist
        #define EBAObjectClass_Cyclist 4U
    #endif

/* typedef eEBADynProp_t */
    #ifndef EBADynProp_NotAvail
        #define EBADynProp_NotAvail 0U
    #endif
    #ifndef EBADynProp_Mov
        #define EBADynProp_Mov 1U
    #endif
    #ifndef EBADynProp_Stat
        #define EBADynProp_Stat 2U
    #endif

/* typedef eEBAObjMovDir_t */
    #ifndef EBAObjMovDir_DoT
        #define EBAObjMovDir_DoT 0U
    #endif
    #ifndef EBAObjMovDir_Cross
        #define EBAObjMovDir_Cross 1U
    #endif
    #ifndef EBAObjMovDir_Onco
        #define EBAObjMovDir_Onco 2U
    #endif

/* typedef lodmc_service_id_t */
    #ifndef Lodmc_no_service
        #define Lodmc_no_service 0U
    #endif
    #ifndef Lodmc_occ_demand
        #define Lodmc_occ_demand 1U
    #endif
    #ifndef Lodmc_hdc_demand
        #define Lodmc_hdc_demand 2U
    #endif
    #ifndef Lodmc_acc_demand
        #define Lodmc_acc_demand 3U
    #endif
    #ifndef Lodmc_dbf_demand
        #define Lodmc_dbf_demand 4U
    #endif
    #ifndef Lodmc_cms1_demand
        #define Lodmc_cms1_demand 5U
    #endif
    #ifndef Lodmc_cms2_demand
        #define Lodmc_cms2_demand 6U
    #endif
    #ifndef Lodmc_epa1_demand
        #define Lodmc_epa1_demand 7U
    #endif
    #ifndef Lodmc_epa2_demand
        #define Lodmc_epa2_demand 8U
    #endif
    #ifndef Lodmc_valim_demand
        #define Lodmc_valim_demand 9U
    #endif
    #ifndef Lodmc_last_element
        #define Lodmc_last_element 10U
    #endif

/* typedef lodmc_act_type_t */
    #ifndef Lodmc_act_none
        #define Lodmc_act_none 0U
    #endif
    #ifndef Lodmc_act_any
        #define Lodmc_act_any 1U
    #endif
    #ifndef Lodmc_act_brk
        #define Lodmc_act_brk 2U
    #endif
    #ifndef Lodmc_act_engine
        #define Lodmc_act_engine 3U
    #endif

/* typedef lodmc_op_state_t */
    #ifndef Lodmc_state_off
        #define Lodmc_state_off 0U
    #endif
    #ifndef Lodmc_state_hold
        #define Lodmc_state_hold 1U
    #endif
    #ifndef Lodmc_state_release
        #define Lodmc_state_release 2U
    #endif
    #ifndef Lodmc_state_ctrl
        #define Lodmc_state_ctrl 3U
    #endif

/* typedef Tcu_Gear_State_t */
    #ifndef NO_SHIFT_IN_PROGRESS
        #define NO_SHIFT_IN_PROGRESS 0U
    #endif
    #ifndef UPSHIFT_IN_PROGRESS
        #define UPSHIFT_IN_PROGRESS 1U
    #endif
    #ifndef DOWNSHIFT_IN_PROGRESS
        #define DOWNSHIFT_IN_PROGRESS 2U
    #endif

/* typedef lodmc_req_response_t */
    #ifndef CONTROL_NOT_ALLOWED_FOR_ERROR
        #define CONTROL_NOT_ALLOWED_FOR_ERROR 3U
    #endif
    #ifndef PRECONDITION_NOT_SATISFIED
        #define PRECONDITION_NOT_SATISFIED 4U
    #endif

/* typedef ALGO_OP_MODE_t */
    #ifndef ALGO_MODE_STARTUP
        #define ALGO_MODE_STARTUP 0U
    #endif
    #ifndef ALGO_MODE_INIT
        #define ALGO_MODE_INIT 1U
    #endif
    #ifndef ALGO_MODE_RUNNING
        #define ALGO_MODE_RUNNING 2U
    #endif
    #ifndef ALGO_MODE_SHUTDOWN
        #define ALGO_MODE_SHUTDOWN 3U
    #endif
    #ifndef ALGO_MODE_PAUSE
        #define ALGO_MODE_PAUSE 4U
    #endif

/* typedef Degradation_Status_t */
    #ifndef NO_ERROR
        #define NO_ERROR 0U
    #endif
    #ifndef DEGRADED
        #define DEGRADED 1U
    #endif
    #ifndef TEMPORARY_ERROR
        #define TEMPORARY_ERROR 2U
    #endif
    #ifndef PERMANENT_ERROR
        #define PERMANENT_ERROR 3U
    #endif

/* typedef DC_status_information_t */
    #ifndef DC_STATUS_AVAILABLE
        #define DC_STATUS_AVAILABLE 0U
    #endif
    #ifndef DC_STATUS_TMP_NOT_AVAIL
        #define DC_STATUS_TMP_NOT_AVAIL 1U
    #endif
    #ifndef DC_STATUS_NOT_AVAIL
        #define DC_STATUS_NOT_AVAIL 2U
    #endif

/* typedef ldm_ctrl_state_t */
    #ifndef LDM_CTRL_ABS_ACTIVE
        #define LDM_CTRL_ABS_ACTIVE 1U
    #endif
    #ifndef LDM_CTRL_TCS_ACTIVE
        #define LDM_CTRL_TCS_ACTIVE 2U
    #endif
    #ifndef LDM_CTRL_ESP_ACTIVE
        #define LDM_CTRL_ESP_ACTIVE 4U
    #endif
    #ifndef LDM_CTRL_ABS_DEFECTIVE
        #define LDM_CTRL_ABS_DEFECTIVE 8U
    #endif
    #ifndef LDM_CTRL_TCS_DEFECTIVE
        #define LDM_CTRL_TCS_DEFECTIVE 16U
    #endif
    #ifndef LDM_CTRL_ESP_DEFECTIVE
        #define LDM_CTRL_ESP_DEFECTIVE 32U
    #endif

/* typedef door_state_t */
    #ifndef DOOR_ALL_CLOSED
        #define DOOR_ALL_CLOSED 0U
    #endif
    #ifndef DOOR_FRONT_LEFT_OPEN
        #define DOOR_FRONT_LEFT_OPEN 1U
    #endif
    #ifndef DOOR_FRONT_RIGHT_OPEN
        #define DOOR_FRONT_RIGHT_OPEN 2U
    #endif
    #ifndef DOOR_REAR_LEFT_OPEN
        #define DOOR_REAR_LEFT_OPEN 4U
    #endif
    #ifndef DOOR_REAR_RIGHT_OPEN
        #define DOOR_REAR_RIGHT_OPEN 8U
    #endif
    #ifndef DOOR_ENG_HOOD_OPEN
        #define DOOR_ENG_HOOD_OPEN 16U
    #endif
    #ifndef DOOR_TRUNK_OPEN
        #define DOOR_TRUNK_OPEN 32U
    #endif

/* typedef seatbelt_state_t */
    #ifndef SEATBELT_DRIVER_OPEN
        #define SEATBELT_DRIVER_OPEN 0U
    #endif
    #ifndef SEATBELT_DRIVER_CLOSED
        #define SEATBELT_DRIVER_CLOSED 1U
    #endif

/* typedef country_code_t */
    #ifndef COUNTRY_REST_WORLD
        #define COUNTRY_REST_WORLD 0U
    #endif
    #ifndef COUNTRY_USA
        #define COUNTRY_USA 1U
    #endif
    #ifndef COUNTRY_JAPAN
        #define COUNTRY_JAPAN 2U
    #endif
    #ifndef COUNTRY_CANADA
        #define COUNTRY_CANADA 3U
    #endif

/* typedef KinCtrlSignalState_t */
    #ifndef LONG_INIT_ACCEL
        #define LONG_INIT_ACCEL 1U
    #endif
    #ifndef PERM_LIM_SETSPEED
        #define PERM_LIM_SETSPEED 2U
    #endif
    #ifndef VAR_LIM_ENGAGE
        #define VAR_LIM_ENGAGE 4U
    #endif
    #ifndef STAND_STILL_DETECTED
        #define STAND_STILL_DETECTED 8U
    #endif
    #ifndef DRIVER_ACCEL_PEDAL_OVERRIDE
        #define DRIVER_ACCEL_PEDAL_OVERRIDE 16U
    #endif
    #ifndef DRIVER_BRAKE_PEDAL_OVERRIDE
        #define DRIVER_BRAKE_PEDAL_OVERRIDE 32U
    #endif
    #ifndef BRAKING_BY_DRIVER
        #define BRAKING_BY_DRIVER 64U
    #endif
    #ifndef DAS_ACCEL_REQ_LIM
        #define DAS_ACCEL_REQ_LIM 128U
    #endif
    #ifndef DAS_DECEL_REQ_LIM
        #define DAS_DECEL_REQ_LIM 256U
    #endif
    #ifndef LONG_SHUTOFF_ACQ
        #define LONG_SHUTOFF_ACQ 512U
    #endif
    #ifndef ACC_ENABLE
        #define ACC_ENABLE 1024U
    #endif
    #ifndef PARK_BRK_ENGAGE
        #define PARK_BRK_ENGAGE 2048U
    #endif
    #ifndef DOOR_STATE
        #define DOOR_STATE 4096U
    #endif

/* typedef DisplayOutputSignalState_t */
    #ifndef SPEED_UNIT
        #define SPEED_UNIT 1U
    #endif
    #ifndef SPEEDOMETER_SPEED
        #define SPEEDOMETER_SPEED 2U
    #endif

/* typedef t_e_SLA_Setting */
    #ifndef SLA_CFG_OFF
        #define SLA_CFG_OFF 0U
    #endif
    #ifndef SLA_CFG_MANUAL
        #define SLA_CFG_MANUAL 1U
    #endif
    #ifndef SLA_CFG_AUTOMATIC
        #define SLA_CFG_AUTOMATIC 2U
    #endif

/* typedef DAS_status_t */
    #ifndef DAS_STATUS_OFF
        #define DAS_STATUS_OFF 0U
    #endif
    #ifndef DAS_STATUS_ENGAGED
        #define DAS_STATUS_ENGAGED 1U
    #endif
    #ifndef DAS_STATUS_ACTIVE
        #define DAS_STATUS_ACTIVE 2U
    #endif
    #ifndef DAS_STATUS_OVERRIDE
        #define DAS_STATUS_OVERRIDE 3U
    #endif
    #ifndef DAS_STATUS_DISENGAGE
        #define DAS_STATUS_DISENGAGE 4U
    #endif
    #ifndef DAS_STATUS_AUTORESUME
        #define DAS_STATUS_AUTORESUME 5U
    #endif

/* typedef DAS_failure_information_t */
    #ifndef DAS_FAILURE_NONE
        #define DAS_FAILURE_NONE 0U
    #endif
    #ifndef DAS_FAILURE_TMP_NOT_AVAIL
        #define DAS_FAILURE_TMP_NOT_AVAIL 1U
    #endif
    #ifndef DAS_FAILURE_PERF_DEGR
        #define DAS_FAILURE_PERF_DEGR 2U
    #endif
    #ifndef DAS_FAILURE_SRV_REQUESTED
        #define DAS_FAILURE_SRV_REQUESTED 3U
    #endif

/* typedef cc_reported_error_t */
    #ifndef Cc_no_error
        #define Cc_no_error 0U
    #endif
    #ifndef Cc_performance_degradation
        #define Cc_performance_degradation 1U
    #endif
    #ifndef Cc_temp_unavailable
        #define Cc_temp_unavailable 2U
    #endif
    #ifndef Cc_error_service
        #define Cc_error_service 3U
    #endif

/* typedef display_op_status_t */
    #ifndef Display_op_none
        #define Display_op_none 0U
    #endif
    #ifndef Display_op_cc_none
        #define Display_op_cc_none 1U
    #endif
    #ifndef Display_op_cc_valid
        #define Display_op_cc_valid 2U
    #endif
    #ifndef Display_op_cc_active
        #define Display_op_cc_active 3U
    #endif
    #ifndef Display_op_cc_invalid
        #define Display_op_cc_invalid 4U
    #endif
    #ifndef Display_op_cc_disengage
        #define Display_op_cc_disengage 5U
    #endif
    #ifndef Display_op_cc_override
        #define Display_op_cc_override 6U
    #endif
    #ifndef Display_op_cc_recom_speed
        #define Display_op_cc_recom_speed 7U
    #endif
    #ifndef Display_op_lim_none
        #define Display_op_lim_none 8U
    #endif
    #ifndef Display_op_lim_valid
        #define Display_op_lim_valid 9U
    #endif
    #ifndef Display_op_lim_active
        #define Display_op_lim_active 10U
    #endif
    #ifndef Display_op_lim_invalid
        #define Display_op_lim_invalid 11U
    #endif
    #ifndef Display_op_lim_disengage
        #define Display_op_lim_disengage 12U
    #endif
    #ifndef Display_op_plim
        #define Display_op_plim 13U
    #endif

/* typedef ldm_drive_mode_t */
    #ifndef LDM_MODE_NORMAL
        #define LDM_MODE_NORMAL 0U
    #endif
    #ifndef LDM_MODE_DYNAMIC
        #define LDM_MODE_DYNAMIC 1U
    #endif
    #ifndef LDM_MODE_ECO
        #define LDM_MODE_ECO 2U
    #endif

/* typedef FCA_status_t */
    #ifndef FCA_STATUS_OFF
        #define FCA_STATUS_OFF 0U
    #endif
    #ifndef FCA_STATUS_ON_INACTIVE
        #define FCA_STATUS_ON_INACTIVE 1U
    #endif
    #ifndef FCA_STATUS_ON_ACTIVE
        #define FCA_STATUS_ON_ACTIVE 2U
    #endif

/* typedef DM_alert_level_t */
    #ifndef NOT_AVAILABLE
        #define NOT_AVAILABLE 0U
    #endif
    #ifndef CRITICAL
        #define CRITICAL 7U
    #endif

/* typedef DM_status_t */
    #ifndef DM_STATUS_OFF
        #define DM_STATUS_OFF 0U
    #endif
    #ifndef DM_STATUS_ON_INACTIVE
        #define DM_STATUS_ON_INACTIVE 1U
    #endif
    #ifndef DM_STATUS_ON_ACTIVE
        #define DM_STATUS_ON_ACTIVE 2U
    #endif

/* typedef SLA_MsgDisp_t */
    #ifndef SLA_IDLE
        #define SLA_IDLE 0U
    #endif
    #ifndef SLA_MANUAL
        #define SLA_MANUAL 1U
    #endif
    #ifndef SLA_MANUAL_OFFSET
        #define SLA_MANUAL_OFFSET 2U
    #endif
    #ifndef SLA_AUTO
        #define SLA_AUTO 3U
    #endif
    #ifndef SLA_AUTO_OFFSET
        #define SLA_AUTO_OFFSET 4U
    #endif

/* typedef SLA_TkOvr_State_t */
    #ifndef SLA_TK_OVR_OFF
        #define SLA_TK_OVR_OFF 0U
    #endif
    #ifndef SLA_TK_OVR_ON
        #define SLA_TK_OVR_ON 1U
    #endif
    #ifndef SLA_TK_OVR_ER
        #define SLA_TK_OVR_ER 2U
    #endif

/* typedef ACCStatus_Radar_t */
    #ifndef ACC_STAT_OFF
        #define ACC_STAT_OFF 0U
    #endif
    #ifndef ACC_STAT_PASSIVE
        #define ACC_STAT_PASSIVE 1U
    #endif
    #ifndef ACC_STAT_STANDBY
        #define ACC_STAT_STANDBY 2U
    #endif
    #ifndef ACC_STAT_ACTIVECONTROL
        #define ACC_STAT_ACTIVECONTROL 3U
    #endif
    #ifndef ACC_STAT_BRAKEONLYMODE
        #define ACC_STAT_BRAKEONLYMODE 4U
    #endif
    #ifndef ACC_STAT_OVERRIDE
        #define ACC_STAT_OVERRIDE 5U
    #endif
    #ifndef ACC_STAT_STANDSTILL
        #define ACC_STAT_STANDSTILL 6U
    #endif
    #ifndef ACC_STAT_FAILUREMODE
        #define ACC_STAT_FAILUREMODE 7U
    #endif
    #ifndef ACC_STAT_STANDSTILLACTIVE
        #define ACC_STAT_STANDSTILLACTIVE 8U
    #endif

/* typedef CruiseControlMode_t */
    #ifndef NoCruiseControl
        #define NoCruiseControl 0U
    #endif
    #ifndef CruiseControl
        #define CruiseControl 1U
    #endif
    #ifndef AdaptiveCruiseControl
        #define AdaptiveCruiseControl 2U
    #endif

/* typedef ACCTextMessage_t */
    #ifndef NoDisplay
        #define NoDisplay 0U
    #endif
    #ifndef DoorOpen
        #define DoorOpen 1U
    #endif
    #ifndef SeatbeltUnbuckled
        #define SeatbeltUnbuckled 2U
    #endif
    #ifndef NoForwardGear
        #define NoForwardGear 3U
    #endif
    #ifndef EPBActivate
        #define EPBActivate 4U
    #endif
    #ifndef ESPOFF
        #define ESPOFF 5U
    #endif
    #ifndef SpeedOver150kph
        #define SpeedOver150kph 6U
    #endif
    #ifndef RSMBlindness
        #define RSMBlindness 7U
    #endif
    #ifndef Unable2ActiveACC
        #define Unable2ActiveACC 8U
    #endif
    #ifndef DriveOffRequest
        #define DriveOffRequest 9U
    #endif
    #ifndef CCisSwitchOn
        #define CCisSwitchOn 10U
    #endif
    #ifndef ACCisSwitchOn
        #define ACCisSwitchOn 11U
    #endif
    #ifndef ACCisSwitchOff
        #define ACCisSwitchOff 12U
    #endif
    #ifndef StandWaitOver3Min
        #define StandWaitOver3Min 13U
    #endif
    #ifndef RadarError
        #define RadarError 14U
    #endif
    #ifndef Unable2ActiveCC
        #define Unable2ActiveCC 15U
    #endif
    #ifndef EngineNotRunning
        #define EngineNotRunning 16U
    #endif
    #ifndef ACCUnintendedExit
        #define ACCUnintendedExit 17U
    #endif
    #ifndef BrakePedalApplied
        #define BrakePedalApplied 18U
    #endif
    #ifndef EnterStandwait
        #define EnterStandwait 19U
    #endif
    #ifndef EnterBOM
        #define EnterBOM 20U
    #endif
    #ifndef OutOfSteeringAngleLimitation
        #define OutOfSteeringAngleLimitation 21U
    #endif

/* typedef shutdownMode_t */
    #ifndef SoftOff
        #define SoftOff 0U
    #endif
    #ifndef FastOff
        #define FastOff 1U
    #endif
    #ifndef ImmediateOff
        #define ImmediateOff 2U
    #endif
    #ifndef NoReq
        #define NoReq 3U
    #endif

/* typedef ACCExitMsgReq_t */
    #ifndef ACCEXIT_NODISPLAY
        #define ACCEXIT_NODISPLAY 0U
    #endif
    #ifndef ACCEXIT_DISPLAY
        #define ACCEXIT_DISPLAY 1U
    #endif
    #ifndef ACCEXIT_CANCELSWITCH
        #define ACCEXIT_CANCELSWITCH 2U
    #endif
    #ifndef ACCEXIT_MAINSWITCH
        #define ACCEXIT_MAINSWITCH 3U
    #endif
    #ifndef ACCEXIT_MODESWITCH
        #define ACCEXIT_MODESWITCH 4U
    #endif
    #ifndef ACCEXIT_BRAKEPEDAL
        #define ACCEXIT_BRAKEPEDAL 5U
    #endif
    #ifndef ACCEXIT_TJASWITCH
        #define ACCEXIT_TJASWITCH 6U
    #endif

/* typedef DisplayDistanceLevel_t */
    #ifndef DISTANCE_NO_DISPLAY
        #define DISTANCE_NO_DISPLAY 0U
    #endif
    #ifndef DISTANCE_LEVEL_1
        #define DISTANCE_LEVEL_1 1U
    #endif
    #ifndef DISTANCE_LEVEL_2
        #define DISTANCE_LEVEL_2 2U
    #endif
    #ifndef DISTANCE_LEVEL_3
        #define DISTANCE_LEVEL_3 3U
    #endif
    #ifndef DISTANCE_LEVEL_4
        #define DISTANCE_LEVEL_4 4U
    #endif
    #ifndef DISTANCE_LEVEL_5
        #define DISTANCE_LEVEL_5 5U
    #endif
    #ifndef DISTANCE_LEVEL_6
        #define DISTANCE_LEVEL_6 6U
    #endif
    #ifndef DISTANCE_LEVEL_7
        #define DISTANCE_LEVEL_7 7U
    #endif

/* typedef ACCTextMessageBD10_t */
    #ifndef ACCTextMessageBD10_eNo_display
        #define ACCTextMessageBD10_eNo_display 0U
    #endif
    #ifndef ACCTextMessageBD10_eACC_ativation_failure
        #define ACCTextMessageBD10_eACC_ativation_failure 1U
    #endif
    #ifndef ACCTextMessageBD10_eACC_canceled
        #define ACCTextMessageBD10_eACC_canceled 2U
    #endif
    #ifndef ACCTextMessageBD10_eACC_activated
        #define ACCTextMessageBD10_eACC_activated 3U
    #endif
    #ifndef ACCTextMessageBD10_eoverride
        #define ACCTextMessageBD10_eoverride 4U
    #endif
    #ifndef ACCTextMessageBD10_etake_over
        #define ACCTextMessageBD10_etake_over 5U
    #endif
    #ifndef ACCTextMessageBD10_eReserved
        #define ACCTextMessageBD10_eReserved 6U
    #endif
    #ifndef ACCTextMessageBD10_eACC_on
        #define ACCTextMessageBD10_eACC_on 7U
    #endif
    #ifndef ACCTextMessageBD10_eACC_off
        #define ACCTextMessageBD10_eACC_off 8U
    #endif
    #ifndef ACCTextMessageBD10_efailure
        #define ACCTextMessageBD10_efailure 9U
    #endif
    #ifndef ACCTextMessageBD10_edriver_belt_off
        #define ACCTextMessageBD10_edriver_belt_off 10U
    #endif
    #ifndef ACCTextMessageBD10_eDoor_open
        #define ACCTextMessageBD10_eDoor_open 11U
    #endif
    #ifndef ACCTextMessageBD10_eNot_in_Dgear
        #define ACCTextMessageBD10_eNot_in_Dgear 12U
    #endif
    #ifndef ACCTextMessageBD10_eEPB_not_release
        #define ACCTextMessageBD10_eEPB_not_release 13U
    #endif
    #ifndef ACCTextMessageBD10_eESP_off
        #define ACCTextMessageBD10_eESP_off 14U
    #endif

/* typedef eTraceUpdateState_t */
    #ifndef TRACE_STATE_INIT
        #define TRACE_STATE_INIT 0U
    #endif
    #ifndef TRACE_STATE_NEW
        #define TRACE_STATE_NEW 1U
    #endif
    #ifndef TRACE_STATE_OBJ_DELETED
        #define TRACE_STATE_OBJ_DELETED 2U
    #endif
    #ifndef TRACE_STATE_ONLY_EGO_COMP
        #define TRACE_STATE_ONLY_EGO_COMP 3U
    #endif
    #ifndef TRACE_STATE_EGO_COMP_ADD_POINT
        #define TRACE_STATE_EGO_COMP_ADD_POINT 4U
    #endif

/* typedef eTraceType_t */
    #ifndef TRACE_TYPE_UNKNOWN
        #define TRACE_TYPE_UNKNOWN 0U
    #endif
    #ifndef TRACE_TYPE_ONCOMING
        #define TRACE_TYPE_ONCOMING 1U
    #endif
    #ifndef TRACE_TYPE_MOVING
        #define TRACE_TYPE_MOVING 2U
    #endif
    #ifndef TRACE_TYPE_MOVING_TO_STATIONARY
        #define TRACE_TYPE_MOVING_TO_STATIONARY 3U
    #endif
    #ifndef TRACE_TYPE_EGO
        #define TRACE_TYPE_EGO 4U
    #endif

/* typedef Quality_t */
    #ifndef OT_Q_REACH_EGO_VEH
        #define OT_Q_REACH_EGO_VEH 1U
    #endif
    #ifndef OT_Q_VALID_FOR_LANE_MATRIX
        #define OT_Q_VALID_FOR_LANE_MATRIX 2U
    #endif
    #ifndef OT_Q_VALID_MAX
        #define OT_Q_VALID_MAX 10000000U
    #endif

/* typedef eActualRangeMaxQual_t */
    #ifndef PD_DMP_QUAL_DEFAULT
        #define PD_DMP_QUAL_DEFAULT 0U
    #endif
    #ifndef PD_DMP_QUAL_NO_QUAL
        #define PD_DMP_QUAL_NO_QUAL 1U
    #endif
    #ifndef PD_DMP_QUAL_WEAK_STATIONARY_ONLY
        #define PD_DMP_QUAL_WEAK_STATIONARY_ONLY 2U
    #endif
    #ifndef PD_DMP_QUAL_STATIONARY_ONLY
        #define PD_DMP_QUAL_STATIONARY_ONLY 3U
    #endif
    #ifndef PD_DMP_QUAL_UNRESTRICTED
        #define PD_DMP_QUAL_UNRESTRICTED 4U
    #endif
    #ifndef PD_DMP_QUAL_SNA
        #define PD_DMP_QUAL_SNA 255U
    #endif

/* typedef ODObj_t_RefPointPos */
    #ifndef ODOBJ_REFPOINT_BACK
        #define ODOBJ_REFPOINT_BACK 0U
    #endif
    #ifndef ODOBJ_REFPOINT_LEFT
        #define ODOBJ_REFPOINT_LEFT 1U
    #endif
    #ifndef ODOBJ_REFPOINT_FRONT
        #define ODOBJ_REFPOINT_FRONT 2U
    #endif
    #ifndef ODOBJ_REFPOINT_RIGHT
        #define ODOBJ_REFPOINT_RIGHT 3U
    #endif
    #ifndef ODOBJ_REFPOINT_NONE
        #define ODOBJ_REFPOINT_NONE 4U
    #endif

/* typedef ODObj_t_DynamicProperty */
    #ifndef ODOBJ_DYNPROP_MOVING
        #define ODOBJ_DYNPROP_MOVING 0U
    #endif
    #ifndef ODOBJ_DYNPROP_STATIONARY
        #define ODOBJ_DYNPROP_STATIONARY 1U
    #endif
    #ifndef ODOBJ_DYNPROP_ONCOMING
        #define ODOBJ_DYNPROP_ONCOMING 2U
    #endif
    #ifndef ODOBJ_DYNPROP_UNKNOWN
        #define ODOBJ_DYNPROP_UNKNOWN 3U
    #endif

/* typedef ODObj_t_DynamicSubProp */
    #ifndef ODOBJ_DYNSUBPROP_NORMAL
        #define ODOBJ_DYNSUBPROP_NORMAL 0U
    #endif
    #ifndef ODOBJ_DYNSUBPROP_CROSSING
        #define ODOBJ_DYNSUBPROP_CROSSING 1U
    #endif

/* typedef ODObj_t_AbsMovingState */
    #ifndef ODOBJ_MOVSTATE_STATIONARY
        #define ODOBJ_MOVSTATE_STATIONARY 0U
    #endif
    #ifndef ODOBJ_MOVSTATE_STOPPED
        #define ODOBJ_MOVSTATE_STOPPED 1U
    #endif
    #ifndef ODOBJ_MOVSTATE_MOVING
        #define ODOBJ_MOVSTATE_MOVING 2U
    #endif
    #ifndef ODOBJ_MOVSTATE_UNKNOWN
        #define ODOBJ_MOVSTATE_UNKNOWN 3U
    #endif

/* typedef ODObj_t_OcclusionState */
    #ifndef ODOBJ_OCCLUSION_NONE
        #define ODOBJ_OCCLUSION_NONE 0U
    #endif
    #ifndef ODOBJ_OCCLUSION_BY_STAT
        #define ODOBJ_OCCLUSION_BY_STAT 1U
    #endif
    #ifndef ODOBJ_OCCLUSION_BY_MOVING
        #define ODOBJ_OCCLUSION_BY_MOVING 2U
    #endif

/* typedef ODObj_t_MaintenanceState */
    #ifndef ODOBJ_MT_STATE_DELETED
        #define ODOBJ_MT_STATE_DELETED 0U
    #endif
    #ifndef ODOBJ_MT_STATE_NEW
        #define ODOBJ_MT_STATE_NEW 1U
    #endif
    #ifndef ODOBJ_MT_STATE_MEASURED
        #define ODOBJ_MT_STATE_MEASURED 2U
    #endif
    #ifndef ODOBJ_MT_STATE_PREDICTED
        #define ODOBJ_MT_STATE_PREDICTED 3U
    #endif
    #ifndef ODOBJ_MT_STATE_EMPTY
        #define ODOBJ_MT_STATE_EMPTY 4U
    #endif

/* typedef ODObj_t_MergeSplitState */
    #ifndef ODOBJ_MS_STATE_NONE
        #define ODOBJ_MS_STATE_NONE 0U
    #endif
    #ifndef ODOBJ_MS_STATE_MERGE
        #define ODOBJ_MS_STATE_MERGE 1U
    #endif
    #ifndef ODOBJ_MS_STATE_SPLIT
        #define ODOBJ_MS_STATE_SPLIT 2U
    #endif

/* typedef ODObj_t_ObjRelationsClass */
    #ifndef ODOBJ_TYPE_NORMAL
        #define ODOBJ_TYPE_NORMAL 0U
    #endif
    #ifndef ODOBJ_TYPE_REAL
        #define ODOBJ_TYPE_REAL 1U
    #endif
    #ifndef ODOBJ_TYPE_MIRROR
        #define ODOBJ_TYPE_MIRROR 2U
    #endif
    #ifndef ODOBJ_TYPE_MULTIPLE
        #define ODOBJ_TYPE_MULTIPLE 3U
    #endif
    #ifndef ODOBJ_TYPE_MIDDLE
        #define ODOBJ_TYPE_MIDDLE 4U
    #endif
    #ifndef ODOBJ_TYPE_GHOST
        #define ODOBJ_TYPE_GHOST 5U
    #endif

/* typedef ODObj_t_MeasuredSources */
    #ifndef ODOBJ_MEAS_SRC_NONE
        #define ODOBJ_MEAS_SRC_NONE 0U
    #endif
    #ifndef ODOBJ_MEAS_SRC_FARSCAN
        #define ODOBJ_MEAS_SRC_FARSCAN 1U
    #endif
    #ifndef ODOBJ_MEAS_SRC_NEARSCAN
        #define ODOBJ_MEAS_SRC_NEARSCAN 2U
    #endif
    #ifndef ODOBJ_MEAS_SRC_GRID
        #define ODOBJ_MEAS_SRC_GRID 4U
    #endif
    #ifndef ODOBJ_MEAS_SRC_CAM
        #define ODOBJ_MEAS_SRC_CAM 8U
    #endif
    #ifndef ODOBJ_MEAS_SRC_PED
        #define ODOBJ_MEAS_SRC_PED 16U
    #endif
    #ifndef ODOBJ_MEAS_SRC_3
        #define ODOBJ_MEAS_SRC_3 32U
    #endif
    #ifndef ODOBJ_MEAS_SRC_2
        #define ODOBJ_MEAS_SRC_2 64U
    #endif
    #ifndef ODOBJ_MEAS_SRC_1
        #define ODOBJ_MEAS_SRC_1 128U
    #endif

/* typedef ucAccSelBits_t */
    #ifndef FPS_ACC_BIT_POE
        #define FPS_ACC_BIT_POE 1U
    #endif
    #ifndef FPS_ACC_BIT_RCS
        #define FPS_ACC_BIT_RCS 2U
    #endif
    #ifndef FPS_ACC_BIT_TGT
        #define FPS_ACC_BIT_TGT 4U
    #endif
    #ifndef FPS_ACC_BIT_LATV
        #define FPS_ACC_BIT_LATV 8U
    #endif
    #ifndef FPS_ACC_BIT_LV
        #define FPS_ACC_BIT_LV 16U
    #endif
    #ifndef FPS_ACC_BIT_NR
        #define FPS_ACC_BIT_NR 32U
    #endif
    #ifndef FPS_ACC_BIT_PED
        #define FPS_ACC_BIT_PED 64U
    #endif
    #ifndef FPS_ACC_BIT_POBS
        #define FPS_ACC_BIT_POBS 128U
    #endif

/* typedef RCG_OpMode */
    #ifndef rcg_opModeReset
        #define rcg_opModeReset 0U
    #endif
    #ifndef rcg_opModePause
        #define rcg_opModePause 1U
    #endif
    #ifndef rcg_opModeNormal
        #define rcg_opModeNormal 2U
    #endif

/* typedef u_OpMode_t */
    #ifndef RHC_OpMode_Reset
        #define RHC_OpMode_Reset 0U
    #endif
    #ifndef RHC_OpMode_Pause
        #define RHC_OpMode_Pause 1U
    #endif
    #ifndef RHC_OpMode_Normal
        #define RHC_OpMode_Normal 2U
    #endif
    #ifndef RHC_OpMode_Alignment
        #define RHC_OpMode_Alignment 3U
    #endif
    #ifndef RHC_OpMode_NoEmission
        #define RHC_OpMode_NoEmission 4U
    #endif

/* typedef u_GainRxChipNear_t */
    #ifndef RHC_RxGainRed_0dB
        #define RHC_RxGainRed_0dB 0U
    #endif
    #ifndef RHC_RxGainRed_6dB
        #define RHC_RxGainRed_6dB 1U
    #endif
    #ifndef RHC_RxGainRed_12dB
        #define RHC_RxGainRed_12dB 2U
    #endif
    #ifndef RHC_RxGainRed_18dB
        #define RHC_RxGainRed_18dB 3U
    #endif
    #ifndef RHC_RxGainRed_24dB
        #define RHC_RxGainRed_24dB 4U
    #endif

/* typedef RSP_t_OpMode */
    #ifndef RSP_OpMode_Reset
        #define RSP_OpMode_Reset 0U
    #endif
    #ifndef RSP_OpMode_Pause
        #define RSP_OpMode_Pause 1U
    #endif
    #ifndef RSP_OpMode_Normal
        #define RSP_OpMode_Normal 2U
    #endif

/* typedef eLaneWidthClass_t */
    #ifndef LANE_WIDTH_CLASS_UNKNOWN
        #define LANE_WIDTH_CLASS_UNKNOWN -1
    #endif
    #ifndef LANE_WIDTH_CLASS_NORMAL
        #define LANE_WIDTH_CLASS_NORMAL 0
    #endif
    #ifndef LANE_WIDTH_CLASS_NARROW
        #define LANE_WIDTH_CLASS_NARROW 1
    #endif
    #ifndef LANE_WIDTH_CLASS_MORE_NARROW
        #define LANE_WIDTH_CLASS_MORE_NARROW 2
    #endif

/* typedef eLaneWidthSource_t */
    #ifndef Source0
        #define Source0 0U
    #endif
    #ifndef Source1
        #define Source1 1U
    #endif

/* typedef e_CoupledRoadCoherence_t */
    #ifndef COUPLEDROAD_COH_DEFAULT
        #define COUPLEDROAD_COH_DEFAULT 0U
    #endif
    #ifndef COUPLEDROAD_COH_INCOHERENT
        #define COUPLEDROAD_COH_INCOHERENT 1U
    #endif

/* typedef e_BorderType_t */
    #ifndef ROAD_BORDERTYPE_UNKNOWN
        #define ROAD_BORDERTYPE_UNKNOWN 0U
    #endif
    #ifndef ROAD_BORDERTYPE_GUARDRAIL
        #define ROAD_BORDERTYPE_GUARDRAIL 1U
    #endif
    #ifndef ROAD_BORDERTYPE_OTHER
        #define ROAD_BORDERTYPE_OTHER 2U
    #endif

/* typedef eTrafficOrientation_t */
    #ifndef TRAFFICORIENTATION_UNKNOWN
        #define TRAFFICORIENTATION_UNKNOWN 0U
    #endif
    #ifndef GDB_TRAFFICORIENTATION_RIGHT_HAND
        #define GDB_TRAFFICORIENTATION_RIGHT_HAND 1U
    #endif
    #ifndef GDB_TRAFFICORIENTATION_LEFT_HAND
        #define GDB_TRAFFICORIENTATION_LEFT_HAND 2U
    #endif

/* typedef eRoadTypeClass_t */
    #ifndef ROAD_TYPE_UNKNOWN
        #define ROAD_TYPE_UNKNOWN 0U
    #endif
    #ifndef ROAD_TYPE_CITY
        #define ROAD_TYPE_CITY 1U
    #endif
    #ifndef ROAD_TYPE_COUNTRY
        #define ROAD_TYPE_COUNTRY 2U
    #endif
    #ifndef ROAD_TYPE_HIGHWAY
        #define ROAD_TYPE_HIGHWAY 3U
    #endif

/* typedef eRoadWorksClass_t */
    #ifndef ROAD_TYPE_LEVEL2_NOINFO
        #define ROAD_TYPE_LEVEL2_NOINFO 0U
    #endif
    #ifndef ROAD_TYPE_LEVEL2_ROADWORKS
        #define ROAD_TYPE_LEVEL2_ROADWORKS 2U
    #endif

/* typedef eCustomRoadType_t */
    #ifndef CUST_ROAD_TYPE_UNKNOWN
        #define CUST_ROAD_TYPE_UNKNOWN 0U
    #endif
    #ifndef CUST_ROAD_TYPE_CITY
        #define CUST_ROAD_TYPE_CITY 1U
    #endif
    #ifndef CUST_ROAD_TYPE_SECONDARY_ROAD
        #define CUST_ROAD_TYPE_SECONDARY_ROAD 2U
    #endif
    #ifndef CUST_ROAD_TYPE_HIGHWAY
        #define CUST_ROAD_TYPE_HIGHWAY 3U
    #endif
    #ifndef CUST_ROAD_TYPE_CONSTRUCTION_ENTRY
        #define CUST_ROAD_TYPE_CONSTRUCTION_ENTRY 4U
    #endif
    #ifndef CUST_ROAD_TYPE_CONSTRUCTION_EXIT
        #define CUST_ROAD_TYPE_CONSTRUCTION_EXIT 5U
    #endif

/* typedef t_e_SLA_SpeedLimitNextType */
    #ifndef SLA_TYPE_IDLE
        #define SLA_TYPE_IDLE 0U
    #endif
    #ifndef SLA_TYPE_AFTER_LIMIT
        #define SLA_TYPE_AFTER_LIMIT 1U
    #endif
    #ifndef SLA_TYPE_BEFOR_LIMIT
        #define SLA_TYPE_BEFOR_LIMIT 2U
    #endif

/* typedef AlgoErrorState_t */
    #ifndef AL_ERR_STATE_UNKNOWN
        #define AL_ERR_STATE_UNKNOWN 0U
    #endif
    #ifndef AL_ERR_STATE_ACTIVE
        #define AL_ERR_STATE_ACTIVE 1U
    #endif
    #ifndef AL_ERR_STATE_INACTIVE
        #define AL_ERR_STATE_INACTIVE 2U
    #endif

/* typedef AlgoSignalState_t */
    #ifndef AL_SIG_STATE_INIT
        #define AL_SIG_STATE_INIT 0U
    #endif
    #ifndef AL_SIG_STATE_OK
        #define AL_SIG_STATE_OK 1U
    #endif
    #ifndef AL_SIG_STATE_INVALID
        #define AL_SIG_STATE_INVALID 2U
    #endif

/* typedef SigState_t */
    #ifndef SIGNAL_INVALID
        #define SIGNAL_INVALID 0U
    #endif
    #ifndef SIGNAL_VALID
        #define SIGNAL_VALID 1U
    #endif

/* typedef GenAlgoQualifiers_t */
    #ifndef ALGO_QUAL_OK
        #define ALGO_QUAL_OK 0U
    #endif
    #ifndef ALGO_QUAL_CRITICAL_INPUT_ERROR
        #define ALGO_QUAL_CRITICAL_INPUT_ERROR 1U
    #endif
    #ifndef ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR
        #define ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR 2U
    #endif
    #ifndef ALGO_QUAL_BLOCKAGE
        #define ALGO_QUAL_BLOCKAGE 4U
    #endif
    #ifndef ALGO_QUAL_PARTIAL_BLOCKAGE
        #define ALGO_QUAL_PARTIAL_BLOCKAGE 8U
    #endif
    #ifndef ALGO_QUAL_CALIBRATION_ERROR_TOO_HIGH
        #define ALGO_QUAL_CALIBRATION_ERROR_TOO_HIGH 16U
    #endif
    #ifndef ALGO_QUAL_GENERAL_FUNCTION_ERROR
        #define ALGO_QUAL_GENERAL_FUNCTION_ERROR 32U
    #endif
    #ifndef ALGO_QUAL_NO_VISIBILITY
        #define ALGO_QUAL_NO_VISIBILITY 64U
    #endif
    #ifndef ALGO_QUAL_LIMITED_VISIBILITY
        #define ALGO_QUAL_LIMITED_VISIBILITY 128U
    #endif
    #ifndef ALGO_QUAL_CALIBRATION_RUNNING
        #define ALGO_QUAL_CALIBRATION_RUNNING 256U
    #endif
    #ifndef ALGO_QUAL_MAX
        #define ALGO_QUAL_MAX 4294967295U
    #endif

/* typedef BaseReturnCode_t */
    #ifndef BASE_RETURN_OK
        #define BASE_RETURN_OK 0U
    #endif
    #ifndef BASE_RETURN_ERROR
        #define BASE_RETURN_ERROR 4294967295U
    #endif

/* typedef FusiErrorExtDirection_t */
    #ifndef FUSI_ERROR_DIR_SNA
        #define FUSI_ERROR_DIR_SNA 0U
    #endif
    #ifndef FUSI_ERROR_DIR_INPUT
        #define FUSI_ERROR_DIR_INPUT 1U
    #endif
    #ifndef FUSI_ERROR_DIR_OUTPUT
        #define FUSI_ERROR_DIR_OUTPUT 2U
    #endif

/* typedef FusiErrorExtType_t */
    #ifndef FUSI_ERROR_TYPE_SNA
        #define FUSI_ERROR_TYPE_SNA 0U
    #endif
    #ifndef FUSI_ERROR_TYPE_NULLPOINTER
        #define FUSI_ERROR_TYPE_NULLPOINTER 1U
    #endif
    #ifndef FUSI_ERROR_TYPE_VERSIONNUMBER
        #define FUSI_ERROR_TYPE_VERSIONNUMBER 2U
    #endif
    #ifndef FUSI_ERROR_TYPE_SIGNALSTATE
        #define FUSI_ERROR_TYPE_SIGNALSTATE 3U
    #endif
    #ifndef FUSI_ERROR_TYPE_COUNTER
        #define FUSI_ERROR_TYPE_COUNTER 4U
    #endif
    #ifndef FUSI_ERROR_TYPE_FINGERPRINT
        #define FUSI_ERROR_TYPE_FINGERPRINT 5U
    #endif
    #ifndef FUSI_ERROR_TYPE_VERIFICATION
        #define FUSI_ERROR_TYPE_VERIFICATION 6U
    #endif

/* typedef TCI_State_t */
    #ifndef TCI_State_INIT
        #define TCI_State_INIT 0U
    #endif
    #ifndef TCI_State_NO_INIT
        #define TCI_State_NO_INIT 1U
    #endif
    #ifndef TCI_State_Acoustical_Visual_Start
        #define TCI_State_Acoustical_Visual_Start 2U
    #endif
    #ifndef TCI_State_Acoustical_Start
        #define TCI_State_Acoustical_Start 3U
    #endif
    #ifndef TCI_State_Visual_End
        #define TCI_State_Visual_End 4U
    #endif
    #ifndef TCI_State_Default
        #define TCI_State_Default 5U
    #endif

/* typedef TCI_HMIDriveOffState_t */
    #ifndef TCI_HMIDriveOffState_Default
        #define TCI_HMIDriveOffState_Default 0U
    #endif
    #ifndef TCI_HMIDriveOffState_Visual_Start
        #define TCI_HMIDriveOffState_Visual_Start 1U
    #endif
    #ifndef TCI_HMIDriveOffState_Visual_End
        #define TCI_HMIDriveOffState_Visual_End 2U
    #endif

/* typedef SelectedTargetObjDetected__nu_t */
    #ifndef TJA_TARGET_OBJ_NOT_DETECTED
        #define TJA_TARGET_OBJ_NOT_DETECTED 0U
    #endif
    #ifndef TJA_TARGET_OBJ_DETECTED
        #define TJA_TARGET_OBJ_DETECTED 1U
    #endif

/* typedef ObjRecognClassType__nu_t */
    #ifndef TJA_EM_GEN_OBJECT_CLASS_POINT
        #define TJA_EM_GEN_OBJECT_CLASS_POINT 0U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_CLASS_CAR
        #define TJA_EM_GEN_OBJECT_CLASS_CAR 1U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_CLASS_TRUCK
        #define TJA_EM_GEN_OBJECT_CLASS_TRUCK 2U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_CLASS_PEDESTRIAN
        #define TJA_EM_GEN_OBJECT_CLASS_PEDESTRIAN 3U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_CLASS_MOTORCYCLE
        #define TJA_EM_GEN_OBJECT_CLASS_MOTORCYCLE 4U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_CLASS_BICYCLE
        #define TJA_EM_GEN_OBJECT_CLASS_BICYCLE 5U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_CLASS_WIDE
        #define TJA_EM_GEN_OBJECT_CLASS_WIDE 6U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_CLASS_UNCLASSIFIED
        #define TJA_EM_GEN_OBJECT_CLASS_UNCLASSIFIED 7U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_CLASS_TL
        #define TJA_EM_GEN_OBJECT_CLASS_TL 8U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES
        #define TJA_EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES 9U
    #endif

/* typedef ObjRecognMeasState__nu_t */
    #ifndef TJA_EM_GEN_OBJECT_MT_STATE_DELETED
        #define TJA_EM_GEN_OBJECT_MT_STATE_DELETED 0U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MT_STATE_NEW
        #define TJA_EM_GEN_OBJECT_MT_STATE_NEW 1U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MT_STATE_MEASURED
        #define TJA_EM_GEN_OBJECT_MT_STATE_MEASURED 2U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MT_STATE_PREDICTED
        #define TJA_EM_GEN_OBJECT_MT_STATE_PREDICTED 3U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MT_STATE_INACTIVE
        #define TJA_EM_GEN_OBJECT_MT_STATE_INACTIVE 4U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES
        #define TJA_EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES 5U
    #endif

/* typedef SensorSource__nu_t */
    #ifndef TJA_EM_GEN_OBJECT_MS_NONE
        #define TJA_EM_GEN_OBJECT_MS_NONE 0U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MS_LRR
        #define TJA_EM_GEN_OBJECT_MS_LRR 1U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MS_MRR
        #define TJA_EM_GEN_OBJECT_MS_MRR 2U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MS_SRR
        #define TJA_EM_GEN_OBJECT_MS_SRR 4U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MS_SRL
        #define TJA_EM_GEN_OBJECT_MS_SRL 8U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MS_CAM
        #define TJA_EM_GEN_OBJECT_MS_CAM 16U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MS_USN
        #define TJA_EM_GEN_OBJECT_MS_USN 32U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MS_HFL
        #define TJA_EM_GEN_OBJECT_MS_HFL 64U
    #endif
    #ifndef TJA_EM_GEN_OBJECT_MS_IR
        #define TJA_EM_GEN_OBJECT_MS_IR 128U
    #endif

/* typedef SlaSignType_t_e */
    #ifndef SLA_OUTPUT_SIGN_NO
        #define SLA_OUTPUT_SIGN_NO 0U
    #endif
    #ifndef SLA_OUTPUT_SIGN_SL
        #define SLA_OUTPUT_SIGN_SL 1U
    #endif
    #ifndef SLA_OUTPUT_SIGN_SLE
        #define SLA_OUTPUT_SIGN_SLE 2U
    #endif
    #ifndef SLA_OUTPUT_SIGN_CITYLIMIT_START
        #define SLA_OUTPUT_SIGN_CITYLIMIT_START 3U
    #endif
    #ifndef SLA_OUTPUT_SIGN_CITYLIMIT_END
        #define SLA_OUTPUT_SIGN_CITYLIMIT_END 4U
    #endif
    #ifndef SLA_OUTPUT_SIGN_PLAYSTREET_START
        #define SLA_OUTPUT_SIGN_PLAYSTREET_START 5U
    #endif
    #ifndef SLA_OUTPUT_SIGN_PLAYSTREET_END
        #define SLA_OUTPUT_SIGN_PLAYSTREET_END 6U
    #endif
    #ifndef SLA_OUTPUT_SIGN_HIGHWAY_START
        #define SLA_OUTPUT_SIGN_HIGHWAY_START 7U
    #endif
    #ifndef SLA_OUTPUT_SIGN_HIGHWAY_END
        #define SLA_OUTPUT_SIGN_HIGHWAY_END 8U
    #endif
    #ifndef SLA_OUTPUT_SIGN_MOTORWAY_START
        #define SLA_OUTPUT_SIGN_MOTORWAY_START 9U
    #endif
    #ifndef SLA_OUTPUT_SIGN_MOTORWAY_END
        #define SLA_OUTPUT_SIGN_MOTORWAY_END 10U
    #endif

/* typedef SlaSignVal_t_e */
    #ifndef SLA_SIGN_VALIDITY_IDLE
        #define SLA_SIGN_VALIDITY_IDLE 0U
    #endif
    #ifndef SLA_SIGN_VALIDITY_UNLIM
        #define SLA_SIGN_VALIDITY_UNLIM 1U
    #endif
    #ifndef SLA_SIGN_VALIDITY_ICY
        #define SLA_SIGN_VALIDITY_ICY 2U
    #endif
    #ifndef SLA_SIGN_VALIDITY_FOG
        #define SLA_SIGN_VALIDITY_FOG 3U
    #endif
    #ifndef SLA_SIGN_VALIDITY_WET
        #define SLA_SIGN_VALIDITY_WET 4U
    #endif
    #ifndef SLA_SIGN_VALIDITY_TIME
        #define SLA_SIGN_VALIDITY_TIME 5U
    #endif
    #ifndef SLA_SIGN_VALIDITY_DARK
        #define SLA_SIGN_VALIDITY_DARK 6U
    #endif
    #ifndef SLA_SIGN_VALIDITY_EXT_LFT
        #define SLA_SIGN_VALIDITY_EXT_LFT 7U
    #endif
    #ifndef SLA_SIGN_VALIDITY_EXT_RGT
        #define SLA_SIGN_VALIDITY_EXT_RGT 8U
    #endif
    #ifndef SLA_SIGN_VALIDITY_TRAILER
        #define SLA_SIGN_VALIDITY_TRAILER 9U
    #endif
    #ifndef SLA_SIGN_VALIDITY_RESTRICTED
        #define SLA_SIGN_VALIDITY_RESTRICTED 10U
    #endif
    #ifndef SLA_RTE_SIGN_VALIDITY_RAIN
        #define SLA_RTE_SIGN_VALIDITY_RAIN 11U
    #endif
    #ifndef SLA_SIGN_VALIDITY_TRUCK
        #define SLA_SIGN_VALIDITY_TRUCK 12U
    #endif
    #ifndef SLA_SIGN_VALIDITY_CAR
        #define SLA_SIGN_VALIDITY_CAR 13U
    #endif

/* typedef SlaSpeedUnit_t_e */
    #ifndef SLA_SPD_UNIT_UNKNOWN
        #define SLA_SPD_UNIT_UNKNOWN 0U
    #endif
    #ifndef SLA_SPD_UNIT_KMH
        #define SLA_SPD_UNIT_KMH 1U
    #endif
    #ifndef SLA_SPD_UNIT_MPH
        #define SLA_SPD_UNIT_MPH 2U
    #endif
    #ifndef SLA_SPD_UNIT_SNA
        #define SLA_SPD_UNIT_SNA 3U
    #endif

/* typedef SlaSignWarning_t_e */
    #ifndef SLA_WARN_OFF
        #define SLA_WARN_OFF 0U
    #endif
    #ifndef SLA_WARN_ON
        #define SLA_WARN_ON 1U
    #endif
    #ifndef SLA_WARN_SNA
        #define SLA_WARN_SNA 2U
    #endif

/* typedef TrafficStyle_t */
    #ifndef TRAFFIC_STYLE_UNKOWN
        #define TRAFFIC_STYLE_UNKOWN 0U
    #endif
    #ifndef TRAFFIC_STYLE_RH
        #define TRAFFIC_STYLE_RH 1U
    #endif
    #ifndef TRAFFIC_STYLE_LH
        #define TRAFFIC_STYLE_LH 2U
    #endif
    #ifndef TRAFFIC_STYLE_INVALID
        #define TRAFFIC_STYLE_INVALID 3U
    #endif

/* typedef VDYCaliState_t */
    #ifndef VDY_CAL_INIT
        #define VDY_CAL_INIT 0U
    #endif
    #ifndef VDY_CAL_YWR_OFFS_STST
        #define VDY_CAL_YWR_OFFS_STST 1U
    #endif
    #ifndef VDY_CAL_YWR_OFFS_DYN
        #define VDY_CAL_YWR_OFFS_DYN 2U
    #endif
    #ifndef VDY_CAL_WHS_OFFS
        #define VDY_CAL_WHS_OFFS 4U
    #endif
    #ifndef VDY_CAL_SWA_OFFS
        #define VDY_CAL_SWA_OFFS 16U
    #endif
    #ifndef VDY_CAL_LTA_OFFS
        #define VDY_CAL_LTA_OFFS 32U
    #endif
    #ifndef VDY_CAL_SWA_GRAD
        #define VDY_CAL_SWA_GRAD 64U
    #endif
    #ifndef VDY_CAL_WHS_LOAD
        #define VDY_CAL_WHS_LOAD 128U
    #endif

/* typedef VDYCtrlState_t */
    #ifndef VDY_CTRL_STATE_STARTUP
        #define VDY_CTRL_STATE_STARTUP 0U
    #endif
    #ifndef VDY_CTRL_STATE_INIT
        #define VDY_CTRL_STATE_INIT 1U
    #endif
    #ifndef VDY_CTRL_STATE_RUNNING
        #define VDY_CTRL_STATE_RUNNING 2U
    #endif

/* typedef VDYIoStateTypes_t */
    #ifndef VDY_IO_STATE_VALID
        #define VDY_IO_STATE_VALID 0U
    #endif
    #ifndef VDY_IO_STATE_INVALID
        #define VDY_IO_STATE_INVALID 1U
    #endif
    #ifndef VDY_IO_STATE_NOTAVAIL
        #define VDY_IO_STATE_NOTAVAIL 2U
    #endif
    #ifndef VDY_IO_STATE_DECREASED
        #define VDY_IO_STATE_DECREASED 3U
    #endif
    #ifndef VDY_IO_STATE_SUBSTITUE
        #define VDY_IO_STATE_SUBSTITUE 4U
    #endif
    #ifndef VDY_IO_STATE_INPLAUSIBLE
        #define VDY_IO_STATE_INPLAUSIBLE 5U
    #endif
    #ifndef VDY_IO_STATE_INIT
        #define VDY_IO_STATE_INIT 15U
    #endif
    #ifndef VDY_IO_STATE_MAX
        #define VDY_IO_STATE_MAX 255U
    #endif

// /* typedef VehDynStatePos_t */
//     #ifndef VDY_SOUT_POS_CURVE
//         #define VDY_SOUT_POS_CURVE 0U
//     #endif
//     #ifndef VDY_SOUT_POS_YWR
//         #define VDY_SOUT_POS_YWR 1U
//     #endif
//     #ifndef VDY_SOUT_POS_DRCRV
//         #define VDY_SOUT_POS_DRCRV 2U
//     #endif
//     #ifndef VDY_SOUT_POS_VEL
//         #define VDY_SOUT_POS_VEL 3U
//     #endif
//     #ifndef VDY_SOUT_POS_ACCEL
//         #define VDY_SOUT_POS_ACCEL 4U
//     #endif
//     #ifndef VDY_SOUT_POS_MSTAT
//         #define VDY_SOUT_POS_MSTAT 5U
//     #endif
//     #ifndef VDY_SOUT_POS_VCORR
//         #define VDY_SOUT_POS_VCORR 6U
//     #endif
//     #ifndef VDY_SOUT_POS_SSA
//         #define VDY_SOUT_POS_SSA 7U
//     #endif
//     #ifndef VDY_SOUT_POS_LATACC
//         #define VDY_SOUT_POS_LATACC 8U
//     #endif
//     #ifndef VDY_SOUT_POS_RAW_YWR
//         #define VDY_SOUT_POS_RAW_YWR 9U
//     #endif
//     #ifndef VDY_SOUT_POS_RAW_VEL
//         #define VDY_SOUT_POS_RAW_VEL 10U
//     #endif
//     #ifndef VDY_SOUT_POS_MAX
//         #define VDY_SOUT_POS_MAX 12U
//     #endif

/* typedef VehSigMainStatePos_t */
    #ifndef VDY_SIN_POS_YWR
        #define VDY_SIN_POS_YWR 0U
    #endif
    #ifndef VDY_SIN_POS_YWR_TEMP
        #define VDY_SIN_POS_YWR_TEMP 1U
    #endif
    #ifndef VDY_SIN_POS_SWA
        #define VDY_SIN_POS_SWA 2U
    #endif
    #ifndef VDY_SIN_POS_LATA
        #define VDY_SIN_POS_LATA 3U
    #endif
    #ifndef VDY_SIN_POS_WVEL_FL
        #define VDY_SIN_POS_WVEL_FL 4U
    #endif
    #ifndef VDY_SIN_POS_WVEL_FR
        #define VDY_SIN_POS_WVEL_FR 5U
    #endif
    #ifndef VDY_SIN_POS_WVEL_RL
        #define VDY_SIN_POS_WVEL_RL 6U
    #endif
    #ifndef VDY_SIN_POS_WVEL_RR
        #define VDY_SIN_POS_WVEL_RR 7U
    #endif
    #ifndef VDY_SIN_POS_YWRINT
        #define VDY_SIN_POS_YWRINT 8U
    #endif
    #ifndef VDY_SIN_POS_YWRINT_TEMP
        #define VDY_SIN_POS_YWRINT_TEMP 9U
    #endif
    #ifndef VDY_SIN_POS_LONGA
        #define VDY_SIN_POS_LONGA 10U
    #endif
    #ifndef VDY_SIN_POS_RSTA
        #define VDY_SIN_POS_RSTA 11U
    #endif
    #ifndef VDY_SIN_POS_VEHVEL_EXT
        #define VDY_SIN_POS_VEHVEL_EXT 12U
    #endif
    #ifndef VDY_SIN_POS_VEHACL_EXT
        #define VDY_SIN_POS_VEHACL_EXT 13U
    #endif
    #ifndef VDY_SIN_POS_WDIR_FL
        #define VDY_SIN_POS_WDIR_FL 14U
    #endif
    #ifndef VDY_SIN_POS_WDIR_FR
        #define VDY_SIN_POS_WDIR_FR 15U
    #endif
    #ifndef VDY_SIN_POS_WDIR_RL
        #define VDY_SIN_POS_WDIR_RL 16U
    #endif
    #ifndef VDY_SIN_POS_WDIR_RR
        #define VDY_SIN_POS_WDIR_RR 17U
    #endif
    #ifndef VDY_SIN_POS_WTCKS_FL
        #define VDY_SIN_POS_WTCKS_FL 18U
    #endif
    #ifndef VDY_SIN_POS_WTCKS_FR
        #define VDY_SIN_POS_WTCKS_FR 19U
    #endif
    #ifndef VDY_SIN_POS_WTCKS_RL
        #define VDY_SIN_POS_WTCKS_RL 20U
    #endif
    #ifndef VDY_SIN_POS_WTCKS_RR
        #define VDY_SIN_POS_WTCKS_RR 21U
    #endif
    #ifndef VDY_SIN_POS_GEAR
        #define VDY_SIN_POS_GEAR 22U
    #endif
    #ifndef VDY_SIN_POS_BRAKE
        #define VDY_SIN_POS_BRAKE 23U
    #endif
    #ifndef VDY_SIN_POS_PBRK
        #define VDY_SIN_POS_PBRK 24U
    #endif
    #ifndef VDY_SIN_POS_VDIR
        #define VDY_SIN_POS_VDIR 25U
    #endif
    #ifndef VDY_SIN_POS_VMOT
        #define VDY_SIN_POS_VMOT 26U
    #endif
    #ifndef VDY_SIN_POS_DUMMY
        #define VDY_SIN_POS_DUMMY 27U
    #endif
    #ifndef VDY_SIN_POS_CRV
        #define VDY_SIN_POS_CRV 28U
    #endif
    #ifndef VDY_SIN_POS_SSA
        #define VDY_SIN_POS_SSA 29U
    #endif
    #ifndef VDY_SIN_POS_MAX
        #define VDY_SIN_POS_MAX 32U
    #endif

/* typedef VehSigAddStatePos_t */
    #ifndef VEH_SIG_ADD_ENV_TEMP
        #define VEH_SIG_ADD_ENV_TEMP 0U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_STATE
        #define VEH_SIG_ADD_WIPER_STATE 1U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_STAGE
        #define VEH_SIG_ADD_WIPER_STAGE 2U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_OUT_PARK_POS
        #define VEH_SIG_ADD_WIPER_OUT_PARK_POS 3U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_WASHER_FRONT
        #define VEH_SIG_ADD_WIPER_WASHER_FRONT 4U
    #endif
    #ifndef VEH_SIG_ADD_RAIN_SENSOR
        #define VEH_SIG_ADD_RAIN_SENSOR 5U
    #endif
    #ifndef VEH_SIG_ADD_TURN_SIGNAL
        #define VEH_SIG_ADD_TURN_SIGNAL 6U
    #endif
    #ifndef VEH_SIG_ADD_FOG_LAMP_FRONT
        #define VEH_SIG_ADD_FOG_LAMP_FRONT 7U
    #endif
    #ifndef VEH_SIG_ADD_FOG_LAMP_REAR
        #define VEH_SIG_ADD_FOG_LAMP_REAR 8U
    #endif
    #ifndef VEH_SIG_ADD_ROAD_WHL_ANG_FR
        #define VEH_SIG_ADD_ROAD_WHL_ANG_FR 9U
    #endif
    #ifndef VEH_SIG_ADD_ROAD_WHL_ANG_RE
        #define VEH_SIG_ADD_ROAD_WHL_ANG_RE 10U
    #endif
    #ifndef VEH_SIG_ADD_ODOMETER
        #define VEH_SIG_ADD_ODOMETER 11U
    #endif
    #ifndef VEH_SIG_ADD_GAS_PEDAL_POS
        #define VEH_SIG_ADD_GAS_PEDAL_POS 12U
    #endif
    #ifndef VEH_SIG_ADD_KICK_DOWN
        #define VEH_SIG_ADD_KICK_DOWN 13U
    #endif
    #ifndef VEH_SIG_ADD_BRAKE_PEDAL_PRESSED
        #define VEH_SIG_ADD_BRAKE_PEDAL_PRESSED 14U
    #endif
    #ifndef VEH_SIG_ADD_DRIVER_TIRED
        #define VEH_SIG_ADD_DRIVER_TIRED 15U
    #endif
    #ifndef VEH_SIG_ADD_SPEED_UNIT
        #define VEH_SIG_ADD_SPEED_UNIT 16U
    #endif
    #ifndef VEH_SIG_ADD_SPEEDO_SPEED
        #define VEH_SIG_ADD_SPEEDO_SPEED 17U
    #endif
    #ifndef VEH_SIG_ADD_TRAILER_CON
        #define VEH_SIG_ADD_TRAILER_CON 18U
    #endif
    #ifndef VEH_SIG_ADD_TRAILER_CON_BEF_SHUTDOWN
        #define VEH_SIG_ADD_TRAILER_CON_BEF_SHUTDOWN 19U
    #endif
    #ifndef VEH_SIG_ADD_TRAILER_LENGTH_INPUT
        #define VEH_SIG_ADD_TRAILER_LENGTH_INPUT 20U
    #endif
    #ifndef VEH_SIG_ADD_PARK_AID_DET_L
        #define VEH_SIG_ADD_PARK_AID_DET_L 21U
    #endif
    #ifndef VEH_SIG_ADD_PARK_AID_DET_CL
        #define VEH_SIG_ADD_PARK_AID_DET_CL 22U
    #endif
    #ifndef VEH_SIG_ADD_PARK_AID_DET_CR
        #define VEH_SIG_ADD_PARK_AID_DET_CR 23U
    #endif
    #ifndef VEH_SIG_ADD_PARK_AID_DET_R
        #define VEH_SIG_ADD_PARK_AID_DET_R 24U
    #endif
    #ifndef VEH_SIG_ADD_IGN_SWITCH
        #define VEH_SIG_ADD_IGN_SWITCH 25U
    #endif
    #ifndef VEH_SIG_ADD_HEIGHT_LEVEL
        #define VEH_SIG_ADD_HEIGHT_LEVEL 26U
    #endif
    #ifndef VEH_SIG_ADD_WHEEL_HEIGHT_LEVEL
        #define VEH_SIG_ADD_WHEEL_HEIGHT_LEVEL 27U
    #endif
    #ifndef VEH_SIG_ADD_EXT_CAM_BLOCKAGE_DETECTION
        #define VEH_SIG_ADD_EXT_CAM_BLOCKAGE_DETECTION 28U
    #endif
    #ifndef VEH_SIG_ADD_MAX
        #define VEH_SIG_ADD_MAX 32U
    #endif

/* typedef VehParMainStatePos_t */
    #ifndef VDY_PAR_POS_SSG
        #define VDY_PAR_POS_SSG 0U
    #endif
    #ifndef VDY_PAR_POS_SWARAT
        #define VDY_PAR_POS_SWARAT 1U
    #endif
    #ifndef VDY_PAR_POS_WBASE
        #define VDY_PAR_POS_WBASE 2U
    #endif
    #ifndef VDY_PAR_POS_TWDFR
        #define VDY_PAR_POS_TWDFR 3U
    #endif
    #ifndef VDY_PAR_POS_TWDRE
        #define VDY_PAR_POS_TWDRE 4U
    #endif
    #ifndef VDY_PAR_POS_VEHWGT
        #define VDY_PAR_POS_VEHWGT 5U
    #endif
    #ifndef VDY_PAR_POS_COGH
        #define VDY_PAR_POS_COGH 6U
    #endif
    #ifndef VDY_PAR_POS_AXLD
        #define VDY_PAR_POS_AXLD 7U
    #endif
    #ifndef VDY_PAR_POS_WHLDFR
        #define VDY_PAR_POS_WHLDFR 8U
    #endif
    #ifndef VDY_PAR_POS_WHLDRE
        #define VDY_PAR_POS_WHLDRE 9U
    #endif
    #ifndef VDY_PAR_POS_WHLCIR
        #define VDY_PAR_POS_WHLCIR 10U
    #endif
    #ifndef VDY_PAR_POS_DRVAXL
        #define VDY_PAR_POS_DRVAXL 11U
    #endif
    #ifndef VDY_PAR_POS_WTCKSREV
        #define VDY_PAR_POS_WTCKSREV 12U
    #endif
    #ifndef VDY_PAR_POS_CSFR
        #define VDY_PAR_POS_CSFR 13U
    #endif
    #ifndef VDY_PAR_POS_CSRE
        #define VDY_PAR_POS_CSRE 14U
    #endif
    #ifndef VDY_PAR_POS_MAX
        #define VDY_PAR_POS_MAX 16U
    #endif

/* typedef VehParAddStatePos_t */
    #ifndef VEH_PAR_ADD_VEHICLE_WIDTH
        #define VEH_PAR_ADD_VEHICLE_WIDTH 0U
    #endif
    #ifndef VEH_PAR_ADD_VEHICLE_LENGTH
        #define VEH_PAR_ADD_VEHICLE_LENGTH 1U
    #endif
    #ifndef VEH_PAR_ADD_CURB_WEIGHT
        #define VEH_PAR_ADD_CURB_WEIGHT 2U
    #endif
    #ifndef VEH_PAR_ADD_OVERHANG_FRONT
        #define VEH_PAR_ADD_OVERHANG_FRONT 3U
    #endif
    #ifndef VEH_PAR_ADD_FRONT_AXLE_ROAD
        #define VEH_PAR_ADD_FRONT_AXLE_ROAD 4U
    #endif
    #ifndef VEH_PAR_ADD_WHEEL_WIDTH
        #define VEH_PAR_ADD_WHEEL_WIDTH 5U
    #endif
    #ifndef VEH_PAR_ADD_STEERING_VARIANT
        #define VEH_PAR_ADD_STEERING_VARIANT 6U
    #endif
    #ifndef VEH_PAR_ADD_PASSABLE_HEIGHT
        #define VEH_PAR_ADD_PASSABLE_HEIGHT 7U
    #endif
    #ifndef VEH_PAR_ADD_DIST_CAMERA_HOOD_X
        #define VEH_PAR_ADD_DIST_CAMERA_HOOD_X 8U
    #endif
    #ifndef VEH_PAR_ADD_DIST_CAMERA_HOOD_Y
        #define VEH_PAR_ADD_DIST_CAMERA_HOOD_Y 9U
    #endif
    #ifndef VEH_PAR_ADD_MAX
        #define VEH_PAR_ADD_MAX 12U
    #endif

/* typedef VehParSenMountStatePos_t */
    #ifndef VEH_PAR_SEN_MOUNT_LAT_POS
        #define VEH_PAR_SEN_MOUNT_LAT_POS 0U
    #endif
    #ifndef VEH_PAR_SEN_MOUNT_LONG_POS
        #define VEH_PAR_SEN_MOUNT_LONG_POS 1U
    #endif
    #ifndef VEH_PAR_SEN_MOUNT_VERT_POS
        #define VEH_PAR_SEN_MOUNT_VERT_POS 2U
    #endif
    #ifndef VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG
        #define VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG 3U
    #endif
    #ifndef VEH_PAR_SEN_MOUNT_PITCH_ANGLE
        #define VEH_PAR_SEN_MOUNT_PITCH_ANGLE 4U
    #endif
    #ifndef VEH_PAR_SEN_MOUNT_ORIENTATION
        #define VEH_PAR_SEN_MOUNT_ORIENTATION 5U
    #endif
    #ifndef VEH_PAR_SEN_MOUNT_ROLL_ANGLE
        #define VEH_PAR_SEN_MOUNT_ROLL_ANGLE 6U
    #endif
    #ifndef VEH_PAR_SEN_MOUNT_YAW_ANGLE
        #define VEH_PAR_SEN_MOUNT_YAW_ANGLE 7U
    #endif
    #ifndef VEH_PAR_SEN_MOUNT_MAX
        #define VEH_PAR_SEN_MOUNT_MAX 8U
    #endif

/* typedef VehParSensorStatePos_t */
    #ifndef VEH_PAR_SENSOR_COVER_DAMPING
        #define VEH_PAR_SENSOR_COVER_DAMPING 0U
    #endif
    #ifndef VEH_PAR_SENSOR_COVERAGE_ANGLE
        #define VEH_PAR_SENSOR_COVERAGE_ANGLE 1U
    #endif
    #ifndef VEH_PAR_SENSOR_LOBE_ANGLE
        #define VEH_PAR_SENSOR_LOBE_ANGLE 2U
    #endif
    #ifndef VEH_PAR_SENSOR_CYCLE_TIME
        #define VEH_PAR_SENSOR_CYCLE_TIME 3U
    #endif
    #ifndef VEH_PAR_SENSOR_NO_OF_SCANS
        #define VEH_PAR_SENSOR_NO_OF_SCANS 4U
    #endif
    #ifndef VEH_PAR_SENSOR_MAX
        #define VEH_PAR_SENSOR_MAX 8U
    #endif

/* typedef VehSigBrakeStatePos_t */
    #ifndef VEH_SIG_BRAKE_ABS
        #define VEH_SIG_BRAKE_ABS 0U
    #endif
    #ifndef VEH_SIG_BRAKE_TSC
        #define VEH_SIG_BRAKE_TSC 1U
    #endif
    #ifndef VEH_SIG_BRAKE_MAX
        #define VEH_SIG_BRAKE_MAX 2U
    #endif

/* typedef VehSigPowertrainStatePos_t */
    #ifndef VEH_SIG_POWERTRAIN_ACTUALGEAR
        #define VEH_SIG_POWERTRAIN_ACTUALGEAR 0U
    #endif
    #ifndef VEH_SIG_POWERTRAIN_TARGETGEAR
        #define VEH_SIG_POWERTRAIN_TARGETGEAR 1U
    #endif
    #ifndef VEH_SIG_POWERTRAIN_ENGINE_RUNNING
        #define VEH_SIG_POWERTRAIN_ENGINE_RUNNING 2U
    #endif
    #ifndef VEH_SIG_POWERTRAIN_MAX
        #define VEH_SIG_POWERTRAIN_MAX 4U
    #endif

/* typedef VDYNvmState_t */
    #ifndef VDY_NVM_POS_SWA
        #define VDY_NVM_POS_SWA 0U
    #endif
    #ifndef VDY_NVM_POS_SSG
        #define VDY_NVM_POS_SSG 2U
    #endif
    #ifndef VDY_NVM_POS_YWR
        #define VDY_NVM_POS_YWR 4U
    #endif
    #ifndef VDY_NVM_POS_LATACC
        #define VDY_NVM_POS_LATACC 6U
    #endif
    #ifndef VDY_NVM_POS_VELCORR
        #define VDY_NVM_POS_VELCORR 8U
    #endif
    #ifndef VDY_NVM_POS_WLD
        #define VDY_NVM_POS_WLD 10U
    #endif
    #ifndef VDY_NVM_POS_MAX
        #define VDY_NVM_POS_MAX 125000U
    #endif

/* typedef LongDirState_t */
    #ifndef VDY_LONG_DIR_VOID
        #define VDY_LONG_DIR_VOID 0U
    #endif
    #ifndef VDY_LONG_DIR_FWD
        #define VDY_LONG_DIR_FWD 1U
    #endif
    #ifndef VDY_LONG_DIR_RWD
        #define VDY_LONG_DIR_RWD 2U
    #endif

/* typedef VDYDrvAxle_t */
    #ifndef VDY_DRV_AXLE_UNKNOWN
        #define VDY_DRV_AXLE_UNKNOWN 0U
    #endif
    #ifndef VDY_DRV_AXLE_FRONT
        #define VDY_DRV_AXLE_FRONT 1U
    #endif
    #ifndef VDY_DRV_AXLE_REAR
        #define VDY_DRV_AXLE_REAR 2U
    #endif
    #ifndef VDY_DRV_AXLE_ALL
        #define VDY_DRV_AXLE_ALL 3U
    #endif

/* typedef VDYTrailerConnection_t */
    #ifndef VEH_SIG_ADD_TRLR_NO_DETECT
        #define VEH_SIG_ADD_TRLR_NO_DETECT 0U
    #endif
    #ifndef VEH_SIG_ADD_TRLR_OK
        #define VEH_SIG_ADD_TRLR_OK 1U
    #endif
    #ifndef VEH_SIG_ADD_TRLR_NDEF2
        #define VEH_SIG_ADD_TRLR_NDEF2 2U
    #endif
    #ifndef VEH_SIG_ADD_TRLR_SNA
        #define VEH_SIG_ADD_TRLR_SNA 3U
    #endif

/* typedef VDYErrState_t */
    #ifndef VDY_ERR_STATE_UNKNOWN
        #define VDY_ERR_STATE_UNKNOWN 0U
    #endif
    #ifndef VDY_ERR_STATE_ACTIVE
        #define VDY_ERR_STATE_ACTIVE 1U
    #endif
    #ifndef VDY_ERR_STATE_INACTIVE
        #define VDY_ERR_STATE_INACTIVE 2U
    #endif

/* typedef corrQual_t */
    #ifndef VDY_VELO_CORR_QUAL_EEPROM
        #define VDY_VELO_CORR_QUAL_EEPROM 0U
    #endif
    #ifndef VDY_VELO_CORR_QUAL_RANGE_NVERIFIED
        #define VDY_VELO_CORR_QUAL_RANGE_NVERIFIED 1U
    #endif
    #ifndef VDY_VELO_CORR_QUAL_RANGE_VERIFIED
        #define VDY_VELO_CORR_QUAL_RANGE_VERIFIED 2U
    #endif
    #ifndef VDY_VELO_CORR_QUAL_SNA
        #define VDY_VELO_CORR_QUAL_SNA 3U
    #endif

/* typedef MotState_t */
    #ifndef VDY_LONG_MOT_STATE_MOVE
        #define VDY_LONG_MOT_STATE_MOVE 0U
    #endif
    #ifndef VDY_LONG_MOT_STATE_MOVE_FWD
        #define VDY_LONG_MOT_STATE_MOVE_FWD 1U
    #endif
    #ifndef VDY_LONG_MOT_STATE_MOVE_RWD
        #define VDY_LONG_MOT_STATE_MOVE_RWD 2U
    #endif
    #ifndef VDY_LONG_MOT_STATE_STDST
        #define VDY_LONG_MOT_STATE_STDST 3U
    #endif

/* typedef SteeringVariant_t */
    #ifndef VEH_PAR_ADD_STEERING_VAR_UNKNOWN
        #define VEH_PAR_ADD_STEERING_VAR_UNKNOWN 0U
    #endif
    #ifndef VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE
        #define VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE 1U
    #endif
    #ifndef VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE
        #define VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE 2U
    #endif

/* typedef Orientation_t */
    #ifndef SENSOR_OR_NORMAL
        #define SENSOR_OR_NORMAL 0U
    #endif
    #ifndef SENSOR_OR_ROTATED
        #define SENSOR_OR_ROTATED 1U
    #endif

/* typedef ActGearPos_t */
    #ifndef ACT_GEAR_POS_NEUTRAL
        #define ACT_GEAR_POS_NEUTRAL 0U
    #endif
    #ifndef ACT_GEAR_POS_PARKING
        #define ACT_GEAR_POS_PARKING 1U
    #endif
    #ifndef ACT_GEAR_POS_FORWARD
        #define ACT_GEAR_POS_FORWARD 2U
    #endif
    #ifndef ACT_GEAR_POS_REVERSE
        #define ACT_GEAR_POS_REVERSE 3U
    #endif

/* typedef ParkBrakeState_t */
    #ifndef STAT_INACTIVE
        #define STAT_INACTIVE 0U
    #endif
    #ifndef STAT_ACTIVE
        #define STAT_ACTIVE 1U
    #endif

/* typedef VehLongMotStateExt_t */
    #ifndef VDY_VEH_MOT_STATE_ROLLING
        #define VDY_VEH_MOT_STATE_ROLLING 0U
    #endif
    #ifndef VDY_VEH_MOT_STATE_FAST_STST
        #define VDY_VEH_MOT_STATE_FAST_STST 1U
    #endif
    #ifndef VDY_VEH_MOT_STATE_SECURE_STST
        #define VDY_VEH_MOT_STATE_SECURE_STST 2U
    #endif

/* typedef WiperState_t */
    #ifndef VEH_SIG_ADD_WIPER_STATE_INACTIVE
        #define VEH_SIG_ADD_WIPER_STATE_INACTIVE 0U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_STATE_ACTIVE
        #define VEH_SIG_ADD_WIPER_STATE_ACTIVE 1U
    #endif

/* typedef WiperStage_t */
    #ifndef VEH_SIG_ADD_WIPER_OFF
        #define VEH_SIG_ADD_WIPER_OFF 0U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_INTERVAL1
        #define VEH_SIG_ADD_WIPER_INTERVAL1 1U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_INTERVAL2
        #define VEH_SIG_ADD_WIPER_INTERVAL2 2U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_INTERVAL3
        #define VEH_SIG_ADD_WIPER_INTERVAL3 3U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_INTERVAL4
        #define VEH_SIG_ADD_WIPER_INTERVAL4 4U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_STAGE1
        #define VEH_SIG_ADD_WIPER_STAGE1 5U
    #endif
    #ifndef VEH_SIG_ADD_WIPER_STAGE2
        #define VEH_SIG_ADD_WIPER_STAGE2 6U
    #endif

/* typedef WiperWasherFrontState_t */
    #ifndef VEH_SIG_ADD_WWS_IDLE
        #define VEH_SIG_ADD_WWS_IDLE 0U
    #endif
    #ifndef VEH_SIG_ADD_WWS_TIPWIPE
        #define VEH_SIG_ADD_WWS_TIPWIPE 1U
    #endif
    #ifndef VEH_SIG_ADD_WWS_WASH
        #define VEH_SIG_ADD_WWS_WASH 2U
    #endif

/* typedef TurnSignal_t */
    #ifndef VEH_SIG_ADD_TURN_SIG_UNKNOWN
        #define VEH_SIG_ADD_TURN_SIG_UNKNOWN 0U
    #endif
    #ifndef VEH_SIG_ADD_TURN_SIG_LEFT
        #define VEH_SIG_ADD_TURN_SIG_LEFT 1U
    #endif
    #ifndef VEH_SIG_ADD_TURN_SIG_RIGHT
        #define VEH_SIG_ADD_TURN_SIG_RIGHT 2U
    #endif
    #ifndef VEH_SIG_ADD_TURN_SIG_NEUTRAL
        #define VEH_SIG_ADD_TURN_SIG_NEUTRAL 3U
    #endif
    #ifndef VEH_SIG_ADD_TURN_SIG_BOTH
        #define VEH_SIG_ADD_TURN_SIG_BOTH 4U
    #endif

/* typedef SpeedUnit_t */
    #ifndef VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN
        #define VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN 0U
    #endif
    #ifndef VEH_SIG_ADD_SPEEDO_UNIT_KMH
        #define VEH_SIG_ADD_SPEEDO_UNIT_KMH 1U
    #endif
    #ifndef VEH_SIG_ADD_SPEEDO_UNIT_MPH
        #define VEH_SIG_ADD_SPEEDO_UNIT_MPH 2U
    #endif

/* typedef IgnitionSwitch_t */
    #ifndef VEH_SIG_ADD_IGN_LOCK
        #define VEH_SIG_ADD_IGN_LOCK 0U
    #endif
    #ifndef VEH_SIG_ADD_IGN_OFF
        #define VEH_SIG_ADD_IGN_OFF 1U
    #endif
    #ifndef VEH_SIG_ADD_IGN_ACC
        #define VEH_SIG_ADD_IGN_ACC 2U
    #endif
    #ifndef VEH_SIG_ADD_IGN_ON
        #define VEH_SIG_ADD_IGN_ON 4U
    #endif
    #ifndef VEH_SIG_ADD_IGN_START
        #define VEH_SIG_ADD_IGN_START 5U
    #endif

/* typedef eSuspensionSystem_t */
    #ifndef VEH_SIG_ADD_NO_ACTIVE_SUSPENSION
        #define VEH_SIG_ADD_NO_ACTIVE_SUSPENSION 0U
    #endif
    #ifndef VEH_SIG_ADD_ACTIVE_SUSPENSION
        #define VEH_SIG_ADD_ACTIVE_SUSPENSION 1U
    #endif

/* typedef eHeightLevel_t */
    #ifndef VEH_SIG_ADD_NO_HEIGHT_LVL
        #define VEH_SIG_ADD_NO_HEIGHT_LVL 0U
    #endif
    #ifndef VEH_SIG_ADD_HEIGHT_LVL_NORMAL
        #define VEH_SIG_ADD_HEIGHT_LVL_NORMAL 1U
    #endif
    #ifndef VEH_SIG_ADD_HEIGHT_LVL_LOW
        #define VEH_SIG_ADD_HEIGHT_LVL_LOW 2U
    #endif
    #ifndef VEH_SIG_ADD_HEIGHT_LVL_HIGH
        #define VEH_SIG_ADD_HEIGHT_LVL_HIGH 4U
    #endif

/* typedef ExternalCamBlockageDetection_t */
    #ifndef EXT_CAM_BLOCKAGE_UNKOWN
        #define EXT_CAM_BLOCKAGE_UNKOWN 0U
    #endif
    #ifndef EXT_CAM_BLOCKAGE_DETECTED
        #define EXT_CAM_BLOCKAGE_DETECTED 1U
    #endif
    #ifndef EXT_CAM_BLOCKAGE_NOT_DETECTED
        #define EXT_CAM_BLOCKAGE_NOT_DETECTED 2U
    #endif

/* typedef TransmissionGear_t */
    #ifndef DYN_GEAR_NEUTRAL_GEAR
        #define DYN_GEAR_NEUTRAL_GEAR 0U
    #endif
    #ifndef DYN_GEAR_FIRST_GEAR
        #define DYN_GEAR_FIRST_GEAR 1U
    #endif
    #ifndef DYN_GEAR_SECOND_GEAR
        #define DYN_GEAR_SECOND_GEAR 2U
    #endif
    #ifndef DYN_GEAR_THIRD_GEAR
        #define DYN_GEAR_THIRD_GEAR 3U
    #endif
    #ifndef DYN_GEAR_FOURTH_GEAR
        #define DYN_GEAR_FOURTH_GEAR 4U
    #endif
    #ifndef DYN_GEAR_FIFTH_GEAR
        #define DYN_GEAR_FIFTH_GEAR 5U
    #endif
    #ifndef DYN_GEAR_SIXTH_GEAR
        #define DYN_GEAR_SIXTH_GEAR 6U
    #endif
    #ifndef DYN_GEAR_SEVENTH_GEAR
        #define DYN_GEAR_SEVENTH_GEAR 7U
    #endif
    #ifndef DYN_GEAR_EIGHTH_GEAR
        #define DYN_GEAR_EIGHTH_GEAR 8U
    #endif
    #ifndef DYN_GEAR_NINTH_GEAR
        #define DYN_GEAR_NINTH_GEAR 9U
    #endif
    #ifndef DYN_GEAR_REVERSE_GEAR
        #define DYN_GEAR_REVERSE_GEAR 10U
    #endif
    #ifndef DYN_GEAR_PARK_GEAR
        #define DYN_GEAR_PARK_GEAR 11U
    #endif
    #ifndef DYN_GEAR_POWER_FREE
        #define DYN_GEAR_POWER_FREE 12U
    #endif
    #ifndef DYN_GEAR_POWER_INVALID
        #define DYN_GEAR_POWER_INVALID 255U
    #endif

/* typedef Percentage_s_t */
    #ifndef Percentage_min
        #define Percentage_min 0U
    #endif
    #ifndef Percentage_max
        #define Percentage_max 100U
    #endif

/* typedef True_False_s_t */
    #ifndef RTE_False
        #define RTE_False 0U
    #endif
    #ifndef RTE_True
        #define RTE_True 1U
    #endif

/* typedef SYSDampState_t */
    #ifndef GDB_NO_DAMP
        #define GDB_NO_DAMP 0U
    #endif
    #ifndef GDB_INC_DAMP
        #define GDB_INC_DAMP 1U
    #endif
    #ifndef GDB_FULL_DAMP
        #define GDB_FULL_DAMP 2U
    #endif
    #ifndef GDB_RDC_DAMP
        #define GDB_RDC_DAMP 3U
    #endif
    #ifndef GDB_UNKNOWN_DAMP
        #define GDB_UNKNOWN_DAMP 4U
    #endif

/* typedef SYS_t_Scans */
    #ifndef SYS_SCAN_NEAR
        #define SYS_SCAN_NEAR 0U
    #endif
    #ifndef SYS_SCAN_FAR
        #define SYS_SCAN_FAR 1U
    #endif

/* typedef SYS_t_HWSample */
    #ifndef SYS_B1_2
        #define SYS_B1_2 257U
    #endif
    #ifndef SYS_C0
        #define SYS_C0 258U
    #endif
    #ifndef SYS_C1
        #define SYS_C1 261U
    #endif
    #ifndef SYS_C1_1
        #define SYS_C1_1 272U
    #endif

/* typedef MTS_VirtAddrs */
    #ifndef ALN_MEAS_ID_ANGDEV_FAR
        #define ALN_MEAS_ID_ANGDEV_FAR 542334976U
    #endif
    #ifndef ALN_MEAS_ID_ANGDEV_NEAR
        #define ALN_MEAS_ID_ANGDEV_NEAR 542330880U
    #endif
    #ifndef ALN_MEAS_ID_AZIMUTH_CORRECTION
        #define ALN_MEAS_ID_AZIMUTH_CORRECTION 542199808U
    #endif
    #ifndef ALN_MEAS_ID_BSW_IN_CLUSTERS
        #define ALN_MEAS_ID_BSW_IN_CLUSTERS 542121984U
    #endif
    #ifndef ALN_MEAS_ID_BSW_IN_FAR
        #define ALN_MEAS_ID_BSW_IN_FAR 542113792U
    #endif
    #ifndef ALN_MEAS_ID_BSW_IN_NEAR
        #define ALN_MEAS_ID_BSW_IN_NEAR 542117888U
    #endif
    #ifndef ALN_MEAS_ID_BSW_OUT_CLUSTERS
        #define ALN_MEAS_ID_BSW_OUT_CLUSTERS 542187520U
    #endif
    #ifndef ALN_MEAS_ID_BSW_OUT_FAR
        #define ALN_MEAS_ID_BSW_OUT_FAR 542179328U
    #endif
    #ifndef ALN_MEAS_ID_BSW_OUT_NEAR
        #define ALN_MEAS_ID_BSW_OUT_NEAR 542183424U
    #endif
    #ifndef ALN_MEAS_ID_INTERNAL
        #define ALN_MEAS_ID_INTERNAL 542310400U
    #endif
    #ifndef ALN_MEAS_ID_INTERNAL_EOL
        #define ALN_MEAS_ID_INTERNAL_EOL 542314496U
    #endif
    #ifndef ALN_MEAS_ID_INTERNAL_MON
        #define ALN_MEAS_ID_INTERNAL_MON 542318592U
    #endif
    #ifndef ALN_MEAS_ID_MONITORING
        #define ALN_MEAS_ID_MONITORING 542208000U
    #endif
    #ifndef ALN_MEAS_ID_MONOPULSE_CORRECTION
        #define ALN_MEAS_ID_MONOPULSE_CORRECTION 542212096U
    #endif
    #ifndef ALN_MEAS_ID_MONOP_PHASE_PPAR
        #define ALN_MEAS_ID_MONOP_PHASE_PPAR 542339072U
    #endif
    #ifndef ALN_MEAS_ID_NVM_IN
        #define ALN_MEAS_ID_NVM_IN 542126080U
    #endif
    #ifndef ALN_MEAS_ID_NVM_OUT
        #define ALN_MEAS_ID_NVM_OUT 542191616U
    #endif
    #ifndef ALN_MEAS_ID_PARAMETERS
        #define ALN_MEAS_ID_PARAMETERS 542130176U
    #endif
    #ifndef ALN_MEAS_ID_REQ_HW_CONFIG
        #define ALN_MEAS_ID_REQ_HW_CONFIG 542195712U
    #endif
    #ifndef ALN_MEAS_ID_SIMINIT
        #define ALN_MEAS_ID_SIMINIT 542244864U
    #endif
    #ifndef ALN_MEAS_ID_SIMINIT_EOL
        #define ALN_MEAS_ID_SIMINIT_EOL 542248960U
    #endif
    #ifndef ALN_MEAS_ID_SIMINIT_MON
        #define ALN_MEAS_ID_SIMINIT_MON 542253056U
    #endif
    #ifndef ALN_MEAS_ID_SYNC_REF
        #define ALN_MEAS_ID_SYNC_REF 542326784U
    #endif
    #ifndef BSW_ALGOPARAMETERS_VADDR
        #define BSW_ALGOPARAMETERS_VADDR 546308096U
    #endif
    #ifndef CP_MEAS_ID_TRACE_ADD_DATA
        #define CP_MEAS_ID_TRACE_ADD_DATA 539364352U
    #endif
    #ifndef CP_MEAS_ID_TRACE_TRAJECTORY
        #define CP_MEAS_ID_TRACE_TRAJECTORY 539369472U
    #endif
    #ifndef EM_MEAS_ID_ARS_OBJECT_LIST
        #define EM_MEAS_ID_ARS_OBJECT_LIST 538656768U
    #endif
    #ifndef EM_MEAS_ID_BASE_OBJECT_LIST_CAM
        #define EM_MEAS_ID_BASE_OBJECT_LIST_CAM 538509312U
    #endif
    #ifndef EM_MEAS_ID_CLD_OUTPUT
        #define EM_MEAS_ID_CLD_OUTPUT 538181632U
    #endif
    #ifndef EM_MEAS_ID_CLUSTER_LIST_FAR
        #define EM_MEAS_ID_CLUSTER_LIST_FAR 538009600U
    #endif
    #ifndef EM_MEAS_ID_CLUSTER_LIST_NEAR
        #define EM_MEAS_ID_CLUSTER_LIST_NEAR 538040464U
    #endif
    #ifndef EM_MEAS_ID_COD_OUTPUT
        #define EM_MEAS_ID_COD_OUTPUT 538182656U
    #endif
    #ifndef EM_MEAS_ID_CTRLDATA
        #define EM_MEAS_ID_CTRLDATA 537920000U
    #endif
    #ifndef EM_MEAS_ID_CUSTOM_OBJECT_LIST
        #define EM_MEAS_ID_CUSTOM_OBJECT_LIST 538574848U
    #endif
    #ifndef EM_MEAS_ID_CUSTOM_OUTPUT
        #define EM_MEAS_ID_CUSTOM_OUTPUT 538632192U
    #endif
    #ifndef EM_MEAS_ID_DETECTIONS_FAR
        #define EM_MEAS_ID_DETECTIONS_FAR 538337792U
    #endif
    #ifndef EM_MEAS_ID_DETECTIONS_NEAR
        #define EM_MEAS_ID_DETECTIONS_NEAR 538312704U
    #endif
    #ifndef EM_MEAS_ID_EGO_OBJ_SYNC
        #define EM_MEAS_ID_EGO_OBJ_SYNC 537997888U
    #endif
    #ifndef EM_MEAS_ID_EGO_TGT_SYNC
        #define EM_MEAS_ID_EGO_TGT_SYNC 537998336U
    #endif
    #ifndef EM_MEAS_ID_ELEV
        #define EM_MEAS_ID_ELEV 538334464U
    #endif
    #ifndef EM_MEAS_ID_EM_FCT_CYCLE_MODE
        #define EM_MEAS_ID_EM_FCT_CYCLE_MODE 537997824U
    #endif
    #ifndef EM_MEAS_ID_ERRORTRAP
        #define EM_MEAS_ID_ERRORTRAP 538116096U
    #endif
    #ifndef EM_MEAS_ID_FUN_PRESEL_ACC_DATA
        #define EM_MEAS_ID_FUN_PRESEL_ACC_DATA 538185728U
    #endif
    #ifndef EM_MEAS_ID_FUN_PRESEL_ACC_GLOB_DATA
        #define EM_MEAS_ID_FUN_PRESEL_ACC_GLOB_DATA 538187776U
    #endif
    #ifndef EM_MEAS_ID_FUN_PRESEL_CG_DATA
        #define EM_MEAS_ID_FUN_PRESEL_CG_DATA 538189824U
    #endif
    #ifndef EM_MEAS_ID_FUN_PRESEL_CG_OBJCLASS
        #define EM_MEAS_ID_FUN_PRESEL_CG_OBJCLASS 538193152U
    #endif
    #ifndef EM_MEAS_ID_FUN_PRESEL_CG_OBJMOV
        #define EM_MEAS_ID_FUN_PRESEL_CG_OBJMOV 538191360U
    #endif
    #ifndef EM_MEAS_ID_FUN_PRESEL_CG_OBJ_DATA
        #define EM_MEAS_ID_FUN_PRESEL_CG_OBJ_DATA 538194432U
    #endif
    #ifndef EM_MEAS_ID_FUN_PRESEL_CG_OBS_DATA
        #define EM_MEAS_ID_FUN_PRESEL_CG_OBS_DATA 538194176U
    #endif
    #ifndef EM_MEAS_ID_FUSION_OBJECT_LIST
        #define EM_MEAS_ID_FUSION_OBJECT_LIST 538660864U
    #endif
    #ifndef EM_MEAS_ID_GEN_OBJECT_LIST
        #define EM_MEAS_ID_GEN_OBJECT_LIST 538640384U
    #endif
    #ifndef EM_MEAS_ID_INPUT_SIGHEADERS
        #define EM_MEAS_ID_INPUT_SIGHEADERS 538120192U
    #endif
    #ifndef EM_MEAS_ID_ME_INPUT
        #define EM_MEAS_ID_ME_INPUT 537935872U
    #endif
    #ifndef EM_MEAS_ID_ME_OUTPUT
        #define EM_MEAS_ID_ME_OUTPUT 538001408U
    #endif
    #ifndef EM_MEAS_ID_NVM_IN
        #define EM_MEAS_ID_NVM_IN 537936128U
    #endif
    #ifndef EM_MEAS_ID_OBJECT_TRACE_LIST
        #define EM_MEAS_ID_OBJECT_TRACE_LIST 538005504U
    #endif
    #ifndef EM_MEAS_ID_OD_RCS_FREQUENCY
        #define EM_MEAS_ID_OD_RCS_FREQUENCY 538460161U
    #endif
    #ifndef EM_MEAS_ID_PCC_DATA
        #define EM_MEAS_ID_PCC_DATA 537853952U
    #endif
    #ifndef EM_MEAS_ID_PERF_DEGR_EXT_INPUT
        #define EM_MEAS_ID_PERF_DEGR_EXT_INPUT 537919488U
    #endif
    #ifndef EM_MEAS_ID_PERF_DEG_OUT_DATA
        #define EM_MEAS_ID_PERF_DEG_OUT_DATA 538075121U
    #endif
    #ifndef EM_MEAS_ID_PUBLIC_OBJECT_LIST
        #define EM_MEAS_ID_PUBLIC_OBJECT_LIST 538378240U
    #endif
    #ifndef EM_MEAS_ID_RCS_DECAY_FAR
        #define EM_MEAS_ID_RCS_DECAY_FAR 537920512U
    #endif
    #ifndef EM_MEAS_ID_RCS_DECAY_NEAR
        #define EM_MEAS_ID_RCS_DECAY_NEAR 537920256U
    #endif
    #ifndef EM_MEAS_ID_RHC_INPUT
        #define EM_MEAS_ID_RHC_INPUT 537997856U
    #endif
    #ifndef EM_MEAS_ID_ROAD_CUSTOM_OUTPUT
        #define EM_MEAS_ID_ROAD_CUSTOM_OUTPUT 538638336U
    #endif
    #ifndef EM_MEAS_ID_RSP_EM_OUTPUT
        #define EM_MEAS_ID_RSP_EM_OUTPUT 537993216U
    #endif
    #ifndef EM_MEAS_ID_RTB_Recognition
        #define EM_MEAS_ID_RTB_Recognition 537998848U
    #endif
    #ifndef EM_MEAS_ID_SYS_PERF_MON_STATES
        #define EM_MEAS_ID_SYS_PERF_MON_STATES 537919744U
    #endif
    #ifndef EM_MEAS_ID_VEL_STAT_OBJ
        #define EM_MEAS_ID_VEL_STAT_OBJ 537998592U
    #endif
    #ifndef FCT_MEAS_ID_ACC_DISPLAY_OBJ
        #define FCT_MEAS_ID_ACC_DISPLAY_OBJ 539071232U
    #endif
    #ifndef FCT_MEAS_ID_ACC_LEVER_INPUT
        #define FCT_MEAS_ID_ACC_LEVER_INPUT 539070464U
    #endif
    #ifndef FCT_MEAS_ID_ACC_OUTPUT_DATA
        #define FCT_MEAS_ID_ACC_OUTPUT_DATA 539071024U
    #endif
    #ifndef FCT_MEAS_ID_CAMSLAINPUTDATA
        #define FCT_MEAS_ID_CAMSLAINPUTDATA 540001856U
    #endif
    #ifndef FCT_MEAS_ID_CAM_LANE_INPUT_VADDR
        #define FCT_MEAS_ID_CAM_LANE_INPUT_VADDR 539521024U
    #endif
    #ifndef FCT_MEAS_ID_CD_CUSTOM_OUTPUT
        #define FCT_MEAS_ID_CD_CUSTOM_OUTPUT 539496448U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_CD_CUSTOM_DATA
        #define FCT_MEAS_ID_CGEB_CD_CUSTOM_DATA 539505152U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_CD_DATA
        #define FCT_MEAS_ID_CGEB_CD_DATA 539140096U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_CD_INT_OBJ_DATA
        #define FCT_MEAS_ID_CGEB_CD_INT_OBJ_DATA 539797888U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_CD_WRAP_DATA
        #define FCT_MEAS_ID_CGEB_CD_WRAP_DATA 539295744U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_DIM_DATA
        #define FCT_MEAS_ID_CGEB_DIM_DATA 539142144U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT
        #define FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT 539502080U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA
        #define FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA 539504128U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_HEAD_CUSTOM_DATA
        #define FCT_MEAS_ID_CGEB_HEAD_CUSTOM_DATA 539501568U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_HEAD_CUSTOM_HYP_PAR
        #define FCT_MEAS_ID_CGEB_HEAD_CUSTOM_HYP_PAR 539501824U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_HEAD_CUSTOM_PCS_PED_DETECT
        #define FCT_MEAS_ID_CGEB_HEAD_CUSTOM_PCS_PED_DETECT 539146496U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_HEAD_DATA
        #define FCT_MEAS_ID_CGEB_HEAD_DATA 539143168U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_HEAD_GSM_DATA
        #define FCT_MEAS_ID_CGEB_HEAD_GSM_DATA 539500544U
    #endif
    #ifndef FCT_MEAS_ID_CGEB_HEAD_OUTFUNC_DATA
        #define FCT_MEAS_ID_CGEB_HEAD_OUTFUNC_DATA 539145472U
    #endif
    #ifndef FCT_MEAS_ID_CPAR_FCT_PARAMETERS
        #define FCT_MEAS_ID_CPAR_FCT_PARAMETERS 539796480U
    #endif
    #ifndef FCT_MEAS_ID_CP_DEVICE
        #define FCT_MEAS_ID_CP_DEVICE 539230464U
    #endif
    #ifndef FCT_MEAS_ID_CUSTOM_INPUT
        #define FCT_MEAS_ID_CUSTOM_INPUT 539688960U
    #endif
    #ifndef FCT_MEAS_ID_CUSTOM_OUTPUT
        #define FCT_MEAS_ID_CUSTOM_OUTPUT 539492352U
    #endif
    #ifndef FCT_MEAS_ID_DIM_INPUT_CUSTOM
        #define FCT_MEAS_ID_DIM_INPUT_CUSTOM 539165440U
    #endif
    #ifndef FCT_MEAS_ID_DIM_INPUT_GENERIC
        #define FCT_MEAS_ID_DIM_INPUT_GENERIC 539164928U
    #endif
    #ifndef FCT_MEAS_ID_DIM_OUTPUT_CUSTOM
        #define FCT_MEAS_ID_DIM_OUTPUT_CUSTOM 539167744U
    #endif
    #ifndef FCT_MEAS_ID_EBA_DEGRADATION_DATA
        #define FCT_MEAS_ID_EBA_DEGRADATION_DATA 539442944U
    #endif
    #ifndef FCT_MEAS_ID_EBA_RUNTIME_DEBUG
        #define FCT_MEAS_ID_EBA_RUNTIME_DEBUG 539441664U
    #endif
    #ifndef FCT_MEAS_ID_EBA_TRAJECTORIES
        #define FCT_MEAS_ID_EBA_TRAJECTORIES 539442688U
    #endif
    #ifndef FCT_MEAS_ID_FCT_SEN_ACC_OOI
        #define FCT_MEAS_ID_FCT_SEN_ACC_OOI 539072256U
    #endif
    #ifndef FCT_MEAS_ID_FCT_VEH_2_SEN
        #define FCT_MEAS_ID_FCT_VEH_2_SEN 539071744U
    #endif
    #ifndef FCT_MEAS_ID_FCT_VEH_CUSTOM_INPUT
        #define FCT_MEAS_ID_FCT_VEH_CUSTOM_INPUT 539072000U
    #endif
    #ifndef FCT_MEAS_ID_FCT_VEH_OUT_ARBIT
        #define FCT_MEAS_ID_FCT_VEH_OUT_ARBIT 539071872U
    #endif
    #ifndef FCT_MEAS_ID_FIP_DEVICE
        #define FCT_MEAS_ID_FIP_DEVICE 539427680U
    #endif
    #ifndef FCT_MEAS_ID_HEAD_INPUT_CUSTOM
        #define FCT_MEAS_ID_HEAD_INPUT_CUSTOM 539166464U
    #endif
    #ifndef FCT_MEAS_ID_HEAD_INPUT_GENERIC
        #define FCT_MEAS_ID_HEAD_INPUT_GENERIC 539165952U
    #endif
    #ifndef FCT_MEAS_ID_HEAD_OUTPUT_CUSTOM
        #define FCT_MEAS_ID_HEAD_OUTPUT_CUSTOM 539166976U
    #endif
    #ifndef FCT_MEAS_ID_HEAD_OUTPUT_GENERIC
        #define FCT_MEAS_ID_HEAD_OUTPUT_GENERIC 539167248U
    #endif
    #ifndef FCT_MEAS_ID_LA_DEVICE
        #define FCT_MEAS_ID_LA_DEVICE 539374848U
    #endif
    #ifndef FCT_MEAS_ID_LOHP_TCCP
        #define FCT_MEAS_ID_LOHP_TCCP 540002071U
    #endif
    #ifndef FCT_MEAS_ID_LOHP_TCSP
        #define FCT_MEAS_ID_LOHP_TCSP 540002103U
    #endif
    #ifndef FCT_MEAS_ID_LONG_CTRL_INPUT
        #define FCT_MEAS_ID_LONG_CTRL_INPUT 539070688U
    #endif
    #ifndef FCT_MEAS_ID_LONG_CTRL_OUTPUT
        #define FCT_MEAS_ID_LONG_CTRL_OUTPUT 539071488U
    #endif
    #ifndef FCT_MEAS_ID_LOPC_TFCP
        #define FCT_MEAS_ID_LOPC_TFCP 540002135U
    #endif
    #ifndef FCT_MEAS_ID_LOPC_TFSP
        #define FCT_MEAS_ID_LOPC_TFSP 540002839U
    #endif
    #ifndef FCT_MEAS_ID_NAVI_DEBUG
        #define FCT_MEAS_ID_NAVI_DEBUG 539427648U
    #endif
    #ifndef FCT_MEAS_ID_NAVI_INPUT_VADDR
        #define FCT_MEAS_ID_NAVI_INPUT_VADDR 539516928U
    #endif
    #ifndef FCT_MEAS_ID_OBJECTLOSS
        #define FCT_MEAS_ID_OBJECTLOSS 539231232U
    #endif
    #ifndef FCT_MEAS_ID_OUT_DEVICE
        #define FCT_MEAS_ID_OUT_DEVICE 539361920U
    #endif
    #ifndef FCT_MEAS_ID_PRIVATE_OBJECT_LIST
        #define FCT_MEAS_ID_PRIVATE_OBJECT_LIST 539623424U
    #endif
    #ifndef FCT_MEAS_ID_PUBLIC_OBJECT_LIST
        #define FCT_MEAS_ID_PUBLIC_OBJECT_LIST 539033600U
    #endif
    #ifndef FCT_MEAS_ID_RUNTIME_DEBUG
        #define FCT_MEAS_ID_RUNTIME_DEBUG 539440640U
    #endif
    #ifndef FCT_MEAS_ID_SENSOR_CTRL
        #define FCT_MEAS_ID_SENSOR_CTRL 539164672U
    #endif
    #ifndef FCT_MEAS_ID_SEN_CTRL_DATA
        #define FCT_MEAS_ID_SEN_CTRL_DATA 539427584U
    #endif
    #ifndef FCT_MEAS_ID_SEN_EBA_FRAME_DATA
        #define FCT_MEAS_ID_SEN_EBA_FRAME_DATA 539441408U
    #endif
    #ifndef FCT_MEAS_ID_SEN_EBA_INPUT_SIGHEADERS
        #define FCT_MEAS_ID_SEN_EBA_INPUT_SIGHEADERS 539442176U
    #endif
    #ifndef FCT_MEAS_ID_SEN_ERROR_OUT_VADDR
        #define FCT_MEAS_ID_SEN_ERROR_OUT_VADDR 539068160U
    #endif
    #ifndef FCT_MEAS_ID_SEN_FRAME_DATA
        #define FCT_MEAS_ID_SEN_FRAME_DATA 539426816U
    #endif
    #ifndef FCT_MEAS_ID_SEN_HYPO_OUT
        #define FCT_MEAS_ID_SEN_HYPO_OUT 539791616U
    #endif
    #ifndef FCT_MEAS_ID_SEN_INPUT_SIGHEADERS
        #define FCT_MEAS_ID_SEN_INPUT_SIGHEADERS 539427840U
    #endif
    #ifndef FCT_MEAS_ID_SIT_DEVICE
        #define FCT_MEAS_ID_SIT_DEVICE 539512832U
    #endif
    #ifndef FCT_MEAS_ID_SI_BLOCKED_PATH_STATUS
        #define FCT_MEAS_ID_SI_BLOCKED_PATH_STATUS 539766784U
    #endif
    #ifndef FCT_MEAS_ID_SI_TRAF_DENSITY
        #define FCT_MEAS_ID_SI_TRAF_DENSITY 539513344U
    #endif
    #ifndef FCT_MEAS_ID_SLADATA
        #define FCT_MEAS_ID_SLADATA 540001893U
    #endif
    #ifndef FCT_MEAS_ID_SPM_BLKPAR
        #define FCT_MEAS_ID_SPM_BLKPAR 539231744U
    #endif
    #ifndef FCT_MEAS_ID_SPM_DATA
        #define FCT_MEAS_ID_SPM_DATA 539230720U
    #endif
    #ifndef FCT_MEAS_ID_TJA_TARGET_OBJ
        #define FCT_MEAS_ID_TJA_TARGET_OBJ 540001926U
    #endif
    #ifndef FCT_MEAS_ID_TRAJECTORIES
        #define FCT_MEAS_ID_TRAJECTORIES 539230208U
    #endif
    #ifndef FCT_MEAS_ID_TSA_SLATE_INPUT
        #define FCT_MEAS_ID_TSA_SLATE_INPUT 540002903U
    #endif
    #ifndef FCT_MEAS_ID_VEH_CTRL_DATA
        #define FCT_MEAS_ID_VEH_CTRL_DATA 539427616U
    #endif
    #ifndef FCT_MEAS_ID_VEH_ERROR_OUT_VADDR
        #define FCT_MEAS_ID_VEH_ERROR_OUT_VADDR 539068416U
    #endif
    #ifndef FCT_MEAS_ID_VEH_FRAME_DATA
        #define FCT_MEAS_ID_VEH_FRAME_DATA 539426944U
    #endif
    #ifndef FCT_MEAS_ID_VEH_INPUT_SIGHEADERS
        #define FCT_MEAS_ID_VEH_INPUT_SIGHEADERS 539428864U
    #endif
    #ifndef FIP_LANE_MATRIX_MEAS_FREEZE_VADDR
        #define FIP_LANE_MATRIX_MEAS_FREEZE_VADDR 539427824U
    #endif
    #ifndef FIP_MOVOBJ_DYNTRACES_MEAS_FREEZE_VADDR
        #define FIP_MOVOBJ_DYNTRACES_MEAS_FREEZE_VADDR 540000000U
    #endif
    #ifndef LODMC_MEAS_ID_DEBUG_DATA
        #define LODMC_MEAS_ID_DEBUG_DATA 539075584U
    #endif
    #ifndef LODMC_MEAS_ID_INPUT
        #define LODMC_MEAS_ID_INPUT 539074560U
    #endif
    #ifndef LODMC_MEAS_ID_OUTPUT
        #define LODMC_MEAS_ID_OUTPUT 539075072U
    #endif
    #ifndef MEAS_ID_MO_TRACES_GLOB_DATA
        #define MEAS_ID_MO_TRACES_GLOB_DATA 537993840U
    #endif
    #ifndef MEAS_ID_ROAD_PUBLIC_GLOB_DATA
        #define MEAS_ID_ROAD_PUBLIC_GLOB_DATA 537993472U
    #endif
    #ifndef RADAR_MEAS_ID_MONITORING_SEN_CYCLE
        #define RADAR_MEAS_ID_MONITORING_SEN_CYCLE 545272064U
    #endif
    #ifndef RADAR_MEAS_ID_MONITORING_VEH_CYCLE
        #define RADAR_MEAS_ID_MONITORING_VEH_CYCLE 545271808U
    #endif
    #ifndef RADAR_MEAS_ID_REQ_HW_CONFIG_RHC_CYCLE
        #define RADAR_MEAS_ID_REQ_HW_CONFIG_RHC_CYCLE 545275904U
    #endif
    #ifndef RADAR_MEAS_ID_RSP2_OUT_RHC_RHC_CYCLE
        #define RADAR_MEAS_ID_RSP2_OUT_RHC_RHC_CYCLE 545280000U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_DYN_DATA_PROC_CYCLE
        #define RADAR_MEAS_ID_VEH_DYN_DATA_PROC_CYCLE 545264384U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_DYN_RAW_DATA_CYCLE
        #define RADAR_MEAS_ID_VEH_DYN_RAW_DATA_CYCLE 545263616U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_DYN_RHC_CYCLE
        #define RADAR_MEAS_ID_VEH_DYN_RHC_CYCLE 545264128U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_DYN_SEN_CYCLE
        #define RADAR_MEAS_ID_VEH_DYN_SEN_CYCLE 545263872U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_PAR_DATA_PROC_CYCLE
        #define RADAR_MEAS_ID_VEH_PAR_DATA_PROC_CYCLE 545260288U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_PAR_RAW_DATA_CYCLE
        #define RADAR_MEAS_ID_VEH_PAR_RAW_DATA_CYCLE 545259520U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_PAR_RHC_CYCLE
        #define RADAR_MEAS_ID_VEH_PAR_RHC_CYCLE 545260032U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_PAR_SEN_CYCLE
        #define RADAR_MEAS_ID_VEH_PAR_SEN_CYCLE 545259776U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_SIG_DATA_PROC_CYCLE
        #define RADAR_MEAS_ID_VEH_SIG_DATA_PROC_CYCLE 545268480U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_SIG_RAW_DATA_CYCLE
        #define RADAR_MEAS_ID_VEH_SIG_RAW_DATA_CYCLE 545267712U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_SIG_RHC_CYCLE
        #define RADAR_MEAS_ID_VEH_SIG_RHC_CYCLE 545268224U
    #endif
    #ifndef RADAR_MEAS_ID_VEH_SIG_SEN_CYCLE
        #define RADAR_MEAS_ID_VEH_SIG_SEN_CYCLE 545267968U
    #endif
    #ifndef RHC_MEAS_ID_ACTL_INPUT
        #define RHC_MEAS_ID_ACTL_INPUT 543186944U
    #endif
    #ifndef RHC_MEAS_ID_ADJ_HW_CONFIG_FAR
        #define RHC_MEAS_ID_ADJ_HW_CONFIG_FAR 543195136U
    #endif
    #ifndef RHC_MEAS_ID_ADJ_HW_CONFIG_NEAR
        #define RHC_MEAS_ID_ADJ_HW_CONFIG_NEAR 543199232U
    #endif
    #ifndef RHC_MEAS_ID_BSW_IN
        #define RHC_MEAS_ID_BSW_IN 543203328U
    #endif
    #ifndef RHC_MEAS_ID_BSW_OUT
        #define RHC_MEAS_ID_BSW_OUT 543207424U
    #endif
    #ifndef RHC_MEAS_ID_DEM_OUTPUT
        #define RHC_MEAS_ID_DEM_OUTPUT 543178752U
    #endif
    #ifndef RHC_MEAS_ID_DIAG_DATA_ADDR
        #define RHC_MEAS_ID_DIAG_DATA_ADDR 543170560U
    #endif
    #ifndef RHC_MEAS_ID_INFORAMP_FREQU_DATA_ADDR
        #define RHC_MEAS_ID_INFORAMP_FREQU_DATA_ADDR 543174656U
    #endif
    #ifndef RHC_MEAS_ID_INPUT_FCT
        #define RHC_MEAS_ID_INPUT_FCT 543211520U
    #endif
    #ifndef RHC_MEAS_ID_INTERN_ADDR
        #define RHC_MEAS_ID_INTERN_ADDR 543166464U
    #endif
    #ifndef RHC_MEAS_ID_MAZ_INPUT
        #define RHC_MEAS_ID_MAZ_INPUT 543182848U
    #endif
    #ifndef RHC_MEAS_ID_NVM
        #define RHC_MEAS_ID_NVM 543223808U
    #endif
    #ifndef RHC_MEAS_ID_RF_COM_OUT
        #define RHC_MEAS_ID_RF_COM_OUT 543219712U
    #endif
    #ifndef RHC_MEAS_ID_SYNC_REF
        #define RHC_MEAS_ID_SYNC_REF 543215616U
    #endif
    #ifndef RHC_MEAS_ID_VCO_TABLE_ADDR
        #define RHC_MEAS_ID_VCO_TABLE_ADDR 543162368U
    #endif
    #ifndef RSP1_MEAS_ID_IN_ACTL_FAR
        #define RSP1_MEAS_ID_IN_ACTL_FAR 100859904U
    #endif
    #ifndef RSP1_MEAS_ID_IN_ACTL_NEAR
        #define RSP1_MEAS_ID_IN_ACTL_NEAR 100860160U
    #endif
    #ifndef RSP1_SPT_TEST_DATA_VADDR
        #define RSP1_SPT_TEST_DATA_VADDR 112652800U
    #endif
    #ifndef RSP1_SPT_TEST_OUT_VADDR
        #define RSP1_SPT_TEST_OUT_VADDR 112652544U
    #endif
    #ifndef RSP1_VADDR_FDCMON_OUT_NS
        #define RSP1_VADDR_FDCMON_OUT_NS 112619776U
    #endif
    #ifndef RSP1_VADDR_FDCMON_RESULT_NS
        #define RSP1_VADDR_FDCMON_RESULT_NS 112654336U
    #endif
    #ifndef RSP1_VADDR_INTERF_HIST
        #define RSP1_VADDR_INTERF_HIST 101187840U
    #endif
    #ifndef RSP1_VADDR_NOISE_FS
        #define RSP1_VADDR_NOISE_FS 101126144U
    #endif
    #ifndef RSP1_VADDR_NOISE_NS
        #define RSP1_VADDR_NOISE_NS 101122048U
    #endif
    #ifndef RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_FS
        #define RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_FS 107413504U
    #endif
    #ifndef RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_NS
        #define RSP1_VADDR_SPEC_BEAM_CMPLX_LIST_NS 107479040U
    #endif
    #ifndef RSP1_VADDR_SYNC_REF_FS
        #define RSP1_VADDR_SYNC_REF_FS 107282432U
    #endif
    #ifndef RSP1_VADDR_SYNC_REF_NS
        #define RSP1_VADDR_SYNC_REF_NS 107216896U
    #endif
    #ifndef RSP2_MEAS_ID_IN_ACTL_FAR
        #define RSP2_MEAS_ID_IN_ACTL_FAR 100860416U
    #endif
    #ifndef RSP2_MEAS_ID_IN_ACTL_NEAR
        #define RSP2_MEAS_ID_IN_ACTL_NEAR 100860672U
    #endif
    #ifndef RSP2_MEAS_ID_OUT_RHC
        #define RSP2_MEAS_ID_OUT_RHC 101187584U
    #endif
    #ifndef RSP2_VADDR_CLU_LST_FAR
        #define RSP2_VADDR_CLU_LST_FAR 100925440U
    #endif
    #ifndef RSP2_VADDR_CLU_LST_NEAR
        #define RSP2_VADDR_CLU_LST_NEAR 100990976U
    #endif
    #ifndef RSP2_VADDR_RSP_TO_EM_FS
        #define RSP2_VADDR_RSP_TO_EM_FS 107347968U
    #endif
    #ifndef RSP2_VADDR_RSP_TO_EM_NS
        #define RSP2_VADDR_RSP_TO_EM_NS 107380736U
    #endif
    #ifndef RSP2_VADDR_SYNC_REF_FS
        #define RSP2_VADDR_SYNC_REF_FS 112569002U
    #endif
    #ifndef RSP2_VADDR_SYNC_REF_NS
        #define RSP2_VADDR_SYNC_REF_NS 112547157U
    #endif
    #ifndef RSP2_VADDR_TIME_MEAS_FS
        #define RSP2_VADDR_TIME_MEAS_FS 112619648U
    #endif
    #ifndef RSP2_VADDR_TIME_MEAS_NS
        #define RSP2_VADDR_TIME_MEAS_NS 112619520U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_00
        #define RSP_VADDR_PEAK_LIST_NS_00 101842944U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_01
        #define RSP_VADDR_PEAK_LIST_NS_01 101908480U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_02
        #define RSP_VADDR_PEAK_LIST_NS_02 101974016U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_03
        #define RSP_VADDR_PEAK_LIST_NS_03 102039552U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_04
        #define RSP_VADDR_PEAK_LIST_NS_04 102105088U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_05
        #define RSP_VADDR_PEAK_LIST_NS_05 102170624U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_06
        #define RSP_VADDR_PEAK_LIST_NS_06 102236160U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_07
        #define RSP_VADDR_PEAK_LIST_NS_07 102301696U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_08
        #define RSP_VADDR_PEAK_LIST_NS_08 102367232U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_09
        #define RSP_VADDR_PEAK_LIST_NS_09 102432768U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_10
        #define RSP_VADDR_PEAK_LIST_NS_10 102498304U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_11
        #define RSP_VADDR_PEAK_LIST_NS_11 102563840U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_12
        #define RSP_VADDR_PEAK_LIST_NS_12 102629376U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_13
        #define RSP_VADDR_PEAK_LIST_NS_13 102694912U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_14
        #define RSP_VADDR_PEAK_LIST_NS_14 102760448U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_15
        #define RSP_VADDR_PEAK_LIST_NS_15 102825984U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_16
        #define RSP_VADDR_PEAK_LIST_NS_16 102891520U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_17
        #define RSP_VADDR_PEAK_LIST_NS_17 102957056U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_18
        #define RSP_VADDR_PEAK_LIST_NS_18 103022592U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_19
        #define RSP_VADDR_PEAK_LIST_NS_19 103088128U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_20
        #define RSP_VADDR_PEAK_LIST_NS_20 103153664U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_21
        #define RSP_VADDR_PEAK_LIST_NS_21 103219200U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_22
        #define RSP_VADDR_PEAK_LIST_NS_22 103284736U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_23
        #define RSP_VADDR_PEAK_LIST_NS_23 103350272U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_24
        #define RSP_VADDR_PEAK_LIST_NS_24 103415808U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_25
        #define RSP_VADDR_PEAK_LIST_NS_25 103481344U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_26
        #define RSP_VADDR_PEAK_LIST_NS_26 103546880U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_27
        #define RSP_VADDR_PEAK_LIST_NS_27 103612416U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_28
        #define RSP_VADDR_PEAK_LIST_NS_28 103677952U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_29
        #define RSP_VADDR_PEAK_LIST_NS_29 103743488U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_30
        #define RSP_VADDR_PEAK_LIST_NS_30 103809024U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_31
        #define RSP_VADDR_PEAK_LIST_NS_31 103874560U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_32
        #define RSP_VADDR_PEAK_LIST_NS_32 103940096U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_33
        #define RSP_VADDR_PEAK_LIST_NS_33 104005632U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_34
        #define RSP_VADDR_PEAK_LIST_NS_34 104071168U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_35
        #define RSP_VADDR_PEAK_LIST_NS_35 104136704U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_36
        #define RSP_VADDR_PEAK_LIST_NS_36 104202240U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_37
        #define RSP_VADDR_PEAK_LIST_NS_37 104267776U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_38
        #define RSP_VADDR_PEAK_LIST_NS_38 104333312U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_39
        #define RSP_VADDR_PEAK_LIST_NS_39 104398848U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_40
        #define RSP_VADDR_PEAK_LIST_NS_40 104464384U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_41
        #define RSP_VADDR_PEAK_LIST_NS_41 104529920U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_42
        #define RSP_VADDR_PEAK_LIST_NS_42 104595456U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_43
        #define RSP_VADDR_PEAK_LIST_NS_43 104660992U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_44
        #define RSP_VADDR_PEAK_LIST_NS_44 104726528U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_45
        #define RSP_VADDR_PEAK_LIST_NS_45 104792064U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_46
        #define RSP_VADDR_PEAK_LIST_NS_46 104857600U
    #endif
    #ifndef RSP_VADDR_PEAK_LIST_NS_47
        #define RSP_VADDR_PEAK_LIST_NS_47 104923136U
    #endif
    #ifndef RSP_VADDR_PRE_CLU_LST_FS
        #define RSP_VADDR_PRE_CLU_LST_FS 100663296U
    #endif
    #ifndef RSP_VADDR_PRE_CLU_LST_NS
        #define RSP_VADDR_PRE_CLU_LST_NS 100728832U
    #endif
    #ifndef RSP_VADDR_RANGE_GATE_INFO_LIST_FS
        #define RSP_VADDR_RANGE_GATE_INFO_LIST_FS 101777408U
    #endif
    #ifndef RSP_VADDR_RANGE_GATE_INFO_LIST_NS
        #define RSP_VADDR_RANGE_GATE_INFO_LIST_NS 101711872U
    #endif
    #ifndef RSP_VADDR_ROAD_BEAM_NEAR
        #define RSP_VADDR_ROAD_BEAM_NEAR 107085824U
    #endif
    #ifndef RSP_VADDR_RSP1_CFG
        #define RSP_VADDR_RSP1_CFG 107610112U
    #endif
    #ifndef RSP_VADDR_RSP2_BLOCKAGE_OUT
        #define RSP_VADDR_RSP2_BLOCKAGE_OUT 112590848U
    #endif
    #ifndef RSP_VADDR_RSP2_NOISE_OUT
        #define RSP_VADDR_RSP2_NOISE_OUT 112525312U
    #endif
    #ifndef RSP_VADDR_SIMULATION_INPUT_FAR
        #define RSP_VADDR_SIMULATION_INPUT_FAR 107020288U
    #endif
    #ifndef RSP_VADDR_SIMULATION_INPUT_NEAR
        #define RSP_VADDR_SIMULATION_INPUT_NEAR 106954752U
    #endif
    #ifndef SI_CUSTOM_OUTPUT_DEBUG_DATA_VADDR
        #define SI_CUSTOM_OUTPUT_DEBUG_DATA_VADDR 539362432U
    #endif
    #ifndef SI_CUTINOBJ_DATA_MEAS_VADDR
        #define SI_CUTINOBJ_DATA_MEAS_VADDR 539362560U
    #endif
    #ifndef SI_MEAS_ADDR_CALIB_SEEK_WIDTH
        #define SI_MEAS_ADDR_CALIB_SEEK_WIDTH 539363072U
    #endif
    #ifndef SI_MEAS_ADDR_DEBUG_OBJ_SCORES
        #define SI_MEAS_ADDR_DEBUG_OBJ_SCORES 539366400U
    #endif
    #ifndef SI_MEAS_ADDR_LANE_CHANGE
        #define SI_MEAS_ADDR_LANE_CHANGE 539363328U
    #endif
    #ifndef SI_MEAS_ADDR_OBJECT_SCORES
        #define SI_MEAS_ADDR_OBJECT_SCORES 539365376U
    #endif
    #ifndef SI_MEAS_ADDR_OBJ_SCORE_EGO_DYN
        #define SI_MEAS_ADDR_OBJ_SCORE_EGO_DYN 539367424U
    #endif
    #ifndef SI_MEAS_ADDR_SCORE_CAM_LANE
        #define SI_MEAS_ADDR_SCORE_CAM_LANE 539368960U
    #endif
    #ifndef SI_MEAS_ADDR_SCORE_ROAD_ESTI
        #define SI_MEAS_ADDR_SCORE_ROAD_ESTI 539367680U
    #endif
    #ifndef SI_MEAS_ADDR_SCORE_TRACES
        #define SI_MEAS_ADDR_SCORE_TRACES 539367936U
    #endif
    #ifndef SI_MEAS_ADDR_SCORING_TRACE_LANES
        #define SI_MEAS_ADDR_SCORING_TRACE_LANES 539369216U
    #endif
    #ifndef SI_MEAS_ID_SI_COURSE_DATA
        #define SI_MEAS_ID_SI_COURSE_DATA 539364096U
    #endif
    #ifndef SI_MEAS_ID_SI_TRAJECTORY
        #define SI_MEAS_ID_SI_TRAJECTORY 539363584U
    #endif
    #ifndef SI_OOI_LIST_MEAS_VADDR
        #define SI_OOI_LIST_MEAS_VADDR 539361536U
    #endif
    #ifndef SI_RANGE_FACTOR_MEAS_VADDR
        #define SI_RANGE_FACTOR_MEAS_VADDR 539362304U
    #endif
    #ifndef SI_RELOBJ_MEAS_VADDR
        #define SI_RELOBJ_MEAS_VADDR 539361280U
    #endif
    #ifndef SLATE_MEAS_ID_FRAME_DATA
        #define SLATE_MEAS_ID_FRAME_DATA 540003051U
    #endif
    #ifndef SLATE_MEAS_ID_SLATE_DEVICE
        #define SLATE_MEAS_ID_SLATE_DEVICE 539361920U
    #endif
    #ifndef TCI_MEAS_ID_INPUT
        #define TCI_MEAS_ID_INPUT 540001812U
    #endif
    #ifndef TCI_MEAS_ID_OUTPUT
        #define TCI_MEAS_ID_OUTPUT 540001792U
    #endif
    #ifndef VDY_MEAS_ID_ALN_EST_YAW_RATE
        #define VDY_MEAS_ID_ALN_EST_YAW_RATE 540018944U
    #endif
    #ifndef VDY_MEAS_ID_ALN_YAW_RATE
        #define VDY_MEAS_ID_ALN_YAW_RATE 540345600U
    #endif
    #ifndef VDY_MEAS_ID_CTRLDATA
        #define VDY_MEAS_ID_CTRLDATA 540016640U
    #endif
    #ifndef VDY_MEAS_ID_ERRORS
        #define VDY_MEAS_ID_ERRORS 540345088U
    #endif
    #ifndef VDY_MEAS_ID_EST_CURVES
        #define VDY_MEAS_ID_EST_CURVES 540346112U
    #endif
    #ifndef VDY_MEAS_ID_NVM_READ
        #define VDY_MEAS_ID_NVM_READ 540017664U
    #endif
    #ifndef VDY_MEAS_ID_NVM_WRITE
        #define VDY_MEAS_ID_NVM_WRITE 540345344U
    #endif
    #ifndef VDY_MEAS_ID_OFFSETS
        #define VDY_MEAS_ID_OFFSETS 540344832U
    #endif
    #ifndef VDY_MEAS_ID_SYNC_REF
        #define VDY_MEAS_ID_SYNC_REF 540346192U
    #endif
    #ifndef VDY_MEAS_ID_VEH_DYN
        #define VDY_MEAS_ID_VEH_DYN 540344320U
    #endif
    #ifndef VDY_MEAS_ID_VEH_PAR
        #define VDY_MEAS_ID_VEH_PAR 540017408U
    #endif
    #ifndef VDY_MEAS_ID_VEH_SIG
        #define VDY_MEAS_ID_VEH_SIG 540016720U
    #endif
    #ifndef VDY_MEAS_ID_VEL_STAT_OBJ
        #define VDY_MEAS_ID_VEL_STAT_OBJ 540018688U
    #endif
    #ifndef VDY_MEAS_ID_YWRT_TEMP_TABPE
        #define VDY_MEAS_ID_YWRT_TEMP_TABPE 540017920U
    #endif

/* typedef SymbolicConstants */
    #ifndef ALGO_FUSI_DEBOUNCE_CYCLES
        #define ALGO_FUSI_DEBOUNCE_CYCLES 3
    #endif
    #ifndef ALGO_FUSI_DEBOUNCE_TIME
        #define ALGO_FUSI_DEBOUNCE_TIME 185000
    #endif
    #ifndef ALGO_VERSION_INFO_LENGTH
        #define ALGO_VERSION_INFO_LENGTH 50
    #endif
    #ifndef ALN_ANGLE_DEV_FAR_NOF_ANGLES
        #define ALN_ANGLE_DEV_FAR_NOF_ANGLES 441
    #endif
    #ifndef ALN_ANGLE_DEV_FAR_NOF_NVM
        #define ALN_ANGLE_DEV_FAR_NOF_NVM 44
    #endif
    #ifndef ALN_ANGLE_DEV_NEAR_NOF_ANGLES
        #define ALN_ANGLE_DEV_NEAR_NOF_ANGLES 721
    #endif
    #ifndef ALN_ANGLE_DEV_NEAR_NOF_NVM
        #define ALN_ANGLE_DEV_NEAR_NOF_NVM 90
    #endif
    #ifndef ALN_MONOPULSE_DEV_NOF_ANGLES
        #define ALN_MONOPULSE_DEV_NOF_ANGLES 181
    #endif
    #ifndef ALN_MONOPULSE_DEV_NOF_NVM
        #define ALN_MONOPULSE_DEV_NOF_NVM 181
    #endif
    #ifndef ALN_PARTIAL_BLOCK_NOF_ZONES
        #define ALN_PARTIAL_BLOCK_NOF_ZONES 3
    #endif
    #ifndef CFG_ACC_LEVER_INPUT
        #define CFG_ACC_LEVER_INPUT 1
    #endif
    #ifndef CFG_ARS400_EN
        #define CFG_ARS400_EN 1
    #endif
    #ifndef CFG_FCT_CD_CMS
        #define CFG_FCT_CD_CMS 0
    #endif
    #ifndef CFG_FCT_VEH_EBA_INTF
        #define CFG_FCT_VEH_EBA_INTF 1
    #endif
    #ifndef CFG_LONG_CONTROLLER
        #define CFG_LONG_CONTROLLER 1
    #endif
    #ifndef CFG_LONG_CTRL_SIG_MON
        #define CFG_LONG_CTRL_SIG_MON 1
    #endif
    #ifndef CFG_USE_FUSION
        #define CFG_USE_FUSION 1
    #endif
    #ifndef EM_GEN_OBJECT_SM_ID_NONE
        #define EM_GEN_OBJECT_SM_ID_NONE 255
    #endif
    #ifndef EM_GEN_OBJECT_SM_ID_UNKNOWN
        #define EM_GEN_OBJECT_SM_ID_UNKNOWN 254
    #endif
    #ifndef EM_GEN_OBJ_N_SHAPE_POINTS
        #define EM_GEN_OBJ_N_SHAPE_POINTS 4
    #endif
    #ifndef EM_NR_PUBLIC_OBJECTS
        #define EM_NR_PUBLIC_OBJECTS 100
    #endif
    #ifndef EM_NUM_DETECTIONS_NEAR
        #define EM_NUM_DETECTIONS_NEAR 600
    #endif
    #ifndef EM_NUM_OFCLUSTERS_FAR
        #define EM_NUM_OFCLUSTERS_FAR 1
    #endif
    #ifndef EM_NUM_OFCLUSTERS_NEAR
        #define EM_NUM_OFCLUSTERS_NEAR 666
    #endif
    #ifndef EM_NUM_OF_ME_OBJECTS
        #define EM_NUM_OF_ME_OBJECTS 10
    #endif
    #ifndef EM_N_CAM_OBJECTS
        #define EM_N_CAM_OBJECTS 12
    #endif
    #ifndef EM_N_FUSION_SENSORS
        #define EM_N_FUSION_SENSORS 1
    #endif
    #ifndef EM_N_OBJECTS
        #define EM_N_OBJECTS 25
    #endif
    #ifndef FCT_CAM_LANE_NUM_LANES
        #define FCT_CAM_LANE_NUM_LANES 4
    #endif
    #ifndef FCT_CFG_ACT_GEN_4
        #define FCT_CFG_ACT_GEN_4 1
    #endif
    #ifndef FCT_CFG_ASSESSED_OBJ_OUT_INTF
        #define FCT_CFG_ASSESSED_OBJ_OUT_INTF 1
    #endif
    #ifndef FCT_CFG_CAM_FUSION
        #define FCT_CFG_CAM_FUSION 1
    #endif
    #ifndef FCT_CFG_HP_TFC_PORT_CNT
        #define FCT_CFG_HP_TFC_PORT_CNT 6
    #endif
    #ifndef FCT_CFG_LONG_CTRL_SLA_SUPPORT
        #define FCT_CFG_LONG_CTRL_SLA_SUPPORT 1
    #endif
    #ifndef FCT_CFG_SEN2VEH_ACC_OOI_PORT
        #define FCT_CFG_SEN2VEH_ACC_OOI_PORT 1
    #endif
    #ifndef FCT_CFG_TP_ACC_CRV_SIZE
        #define FCT_CFG_TP_ACC_CRV_SIZE 8
    #endif
    #ifndef FCT_CFG_VEH_CUSTOM_INPUT
        #define FCT_CFG_VEH_CUSTOM_INPUT 0
    #endif
    #ifndef FCT_NAV_NUM_EXIT_SEG
        #define FCT_NAV_NUM_EXIT_SEG 5
    #endif
    #ifndef FCT_NAV_NUM_SEG
        #define FCT_NAV_NUM_SEG 8
    #endif
    #ifndef FCT_NOF_CAMERA_BOUNDARY
        #define FCT_NOF_CAMERA_BOUNDARY 10
    #endif
    #ifndef FCT_NOF_CUST_OUT_OBJECTS
        #define FCT_NOF_CUST_OUT_OBJECTS 40
    #endif
    #ifndef FCT_NUM_OF_HMI_OBJECTS
        #define FCT_NUM_OF_HMI_OBJECTS 6
    #endif
    #ifndef FPGA_MAX_NUM_OF_DYNAMIC_PEAKS
        #define FPGA_MAX_NUM_OF_DYNAMIC_PEAKS 500
    #endif
    #ifndef GA_P_BACKUP_SENSORS_AVAILABLE
        #define GA_P_BACKUP_SENSORS_AVAILABLE 0
    #endif
    #ifndef MAX_NUM_OF_HYPS
        #define MAX_NUM_OF_HYPS 12
    #endif
    #ifndef MAX_NUM_TRACES
        #define MAX_NUM_TRACES 10
    #endif
    #ifndef MAX_TRACE_POINTS
        #define MAX_TRACE_POINTS 25
    #endif
    #ifndef ODOBJ_STOPPED_CONF_MAX
        #define ODOBJ_STOPPED_CONF_MAX 100
    #endif
    #ifndef ODOBJ_STOPPED_CONF_NONE
        #define ODOBJ_STOPPED_CONF_NONE 0
    #endif
    #ifndef OD_OBJECTLIST_INTVER
        #define OD_OBJECTLIST_INTVER 5
    #endif
    #ifndef PUBLIC_OBJECTLIST_HEADER_BYTEALIGNMENT
        #define PUBLIC_OBJECTLIST_HEADER_BYTEALIGNMENT 3
    #endif
    #ifndef RCG_MAX_NUM_OBJECTS
        #define RCG_MAX_NUM_OBJECTS 40
    #endif
    #ifndef REF_SPEED_NO_BINS
        #define REF_SPEED_NO_BINS 81
    #endif
    #ifndef RHC_CHIRP_TABLE_LEN
        #define RHC_CHIRP_TABLE_LEN 1536
    #endif
    #ifndef RHC_DAC_TABLE_LEN
        #define RHC_DAC_TABLE_LEN 1536
    #endif
    #ifndef RHC_NUM_CHANNELS
        #define RHC_NUM_CHANNELS 12
    #endif
    #ifndef RHC_NUM_DIFF_DAC_TABLES
        #define RHC_NUM_DIFF_DAC_TABLES 4
    #endif
    #ifndef RHC_NUM_IF_CHANNELS
        #define RHC_NUM_IF_CHANNELS 6
    #endif
    #ifndef RHC_N_CHIRP_TABLES
        #define RHC_N_CHIRP_TABLES 4
    #endif
    #ifndef RHC_N_RX_CHIPS
        #define RHC_N_RX_CHIPS 4
    #endif
    #ifndef RHC_N_SPI_ENTRIES
        #define RHC_N_SPI_ENTRIES 20
    #endif
    #ifndef RHC_N_TX_CHIPS
        #define RHC_N_TX_CHIPS 2
    #endif
    #ifndef RHC_VCO_RAM_SIZE
        #define RHC_VCO_RAM_SIZE 3072
    #endif
    #ifndef RSP_CL_NUM_OF_PDH0
        #define RSP_CL_NUM_OF_PDH0 7
    #endif
    #ifndef RSP_INVALID_AZANGLE
        #define RSP_INVALID_AZANGLE -999
    #endif
    #ifndef RSP_MAINHYP_AZANGLE
        #define RSP_MAINHYP_AZANGLE 0
    #endif
    #ifndef RSP_NOF_PRE_CLUSTERS_FAR
        #define RSP_NOF_PRE_CLUSTERS_FAR 448
    #endif
    #ifndef RSP_NOF_PRE_CLUSTERS_NEAR
        #define RSP_NOF_PRE_CLUSTERS_NEAR 768
    #endif
    #ifndef RSP_NUM_OFCLUSTERS_FAR
        #define RSP_NUM_OFCLUSTERS_FAR 448
    #endif
    #ifndef RSP_NUM_OFCLUSTERS_NEAR
        #define RSP_NUM_OFCLUSTERS_NEAR 768
    #endif
    #ifndef RSP_NUM_OF_AZANGLES
        #define RSP_NUM_OF_AZANGLES 2
    #endif
    #ifndef RSP_NUM_OF_CL_RG
        #define RSP_NUM_OF_CL_RG 4
    #endif
    #ifndef RSP_NUM_OF_DOPPLER_NACOM
        #define RSP_NUM_OF_DOPPLER_NACOM 5
    #endif
    #ifndef RSP_NUM_OF_DOPPLER_ROADBEAM
        #define RSP_NUM_OF_DOPPLER_ROADBEAM 21
    #endif
    #ifndef RSP_NUM_OF_PEAKS_PER_FREEZE
        #define RSP_NUM_OF_PEAKS_PER_FREEZE 64
    #endif
    #ifndef RSP_NUM_OF_RGS_NACOM
        #define RSP_NUM_OF_RGS_NACOM 10
    #endif
    #ifndef RSP_NUM_OF_RGS_ROADBEAM_NS
        #define RSP_NUM_OF_RGS_ROADBEAM_NS 21
    #endif
    #ifndef RTE_BITFIELD_TYPE
        #define RTE_BITFIELD_TYPE 1
    #endif
    #ifndef RTE_PUBLIC_OBJECT_LIST_TYPE
        #define RTE_PUBLIC_OBJECT_LIST_TYPE 1
    #endif
    #ifndef SPT_CP16_CPL_DATA
        #define SPT_CP16_CPL_DATA 8192
    #endif
    #ifndef SPT_MAX_SAMPLES
        #define SPT_MAX_SAMPLES 512
    #endif
    #ifndef SPT_MAX_SAMPLES_FS
        #define SPT_MAX_SAMPLES_FS 256
    #endif
    #ifndef SPT_MAX_SAMPLES_NS
        #define SPT_MAX_SAMPLES_NS 512
    #endif
    #ifndef SPT_NUM_OF_HIST_ENTRY
        #define SPT_NUM_OF_HIST_ENTRY 64
    #endif
    #ifndef SPT_N_BEAMS
        #define SPT_N_BEAMS 16
    #endif
    #ifndef SPT_N_CHIRPS_FS
        #define SPT_N_CHIRPS_FS 512
    #endif
    #ifndef SPT_N_CHIRPS_MAX
        #define SPT_N_CHIRPS_MAX 512
    #endif
    #ifndef SPT_N_CHIRPS_NS
        #define SPT_N_CHIRPS_NS 256
    #endif
    #ifndef SPT_N_CP6_BUF_FS
        #define SPT_N_CP6_BUF_FS 114644
    #endif
    #ifndef SPT_N_CP6_BUF_NS
        #define SPT_N_CP6_BUF_NS 122880
    #endif
    #ifndef SPT_N_HIST_LEN
        #define SPT_N_HIST_LEN 48
    #endif
    #ifndef SPT_N_RX_CHANNELS
        #define SPT_N_RX_CHANNELS 6
    #endif
    #ifndef SPT_N_SLICES
        #define SPT_N_SLICES 8
    #endif
    #ifndef SPT_SDMA_DATA_LEN_FS
        #define SPT_SDMA_DATA_LEN_FS 1904
    #endif
    #ifndef SPT_SDMA_DATA_LEN_NS
        #define SPT_SDMA_DATA_LEN_NS 3696
    #endif
    #ifndef SYS_CFG_EAGLE
        #define SYS_CFG_EAGLE 1
    #endif
    #ifndef SYS_NUM_OF_BEAMS
        #define SYS_NUM_OF_BEAMS 16
    #endif
    #ifndef SYS_NUM_OF_CHANNELS
        #define SYS_NUM_OF_CHANNELS 6
    #endif
    #ifndef SYS_NUM_OF_CL_RG
        #define SYS_NUM_OF_CL_RG 4
    #endif
    #ifndef SYS_NUM_OF_RG_FAR
        #define SYS_NUM_OF_RG_FAR 112
    #endif
    #ifndef SYS_NUM_OF_RG_NEAR
        #define SYS_NUM_OF_RG_NEAR 256
    #endif
    #ifndef SYS_NUM_OF_RX_CHIPS
        #define SYS_NUM_OF_RX_CHIPS 1
    #endif
    #ifndef SYS_NUM_OF_SCANS
        #define SYS_NUM_OF_SCANS 1
    #endif
    #ifndef SYS_NUM_OF_TX_CHIPS
        #define SYS_NUM_OF_TX_CHIPS 1
    #endif
    #ifndef SYS_NUM_TEMPER_RR
        #define SYS_NUM_TEMPER_RR 2
    #endif
    #ifndef TCI_CFG_ENABLE
        #define TCI_CFG_ENABLE 1
    #endif
    #ifndef TRACE_INVALID_ID
        #define TRACE_INVALID_ID 255
    #endif
    #ifndef TRACE_NO_OF_POINTS
        #define TRACE_NO_OF_POINTS 25
    #endif
    #ifndef TRACE_NO_OF_TRACES
        #define TRACE_NO_OF_TRACES 10
    #endif
    #ifndef TRACE_SCALE_CONST
        #define TRACE_SCALE_CONST 1000
    #endif
    #ifndef TSA_SLATE_INPUT_ENABLE
        #define TSA_SLATE_INPUT_ENABLE 1
    #endif
    #ifndef VDY_SWA_RAT_NO_ANGL
        #define VDY_SWA_RAT_NO_ANGL 2
    #endif
    #ifndef VDY_SWA_RAT_NO_VELO
        #define VDY_SWA_RAT_NO_VELO 2
    #endif

/* typedef InterfaceVersion */
    #ifndef ACC_DISPLAY_OBJECT_INTFVER
        #define ACC_DISPLAY_OBJECT_INTFVER 1U
    #endif
    #ifndef ALN_AzimuthCorrectionVersion
        #define ALN_AzimuthCorrectionVersion 4U
    #endif
    #ifndef ALN_BswInVersion
        #define ALN_BswInVersion 11U
    #endif
    #ifndef ALN_BswOutVersion
        #define ALN_BswOutVersion 8U
    #endif
    #ifndef ALN_MONITORING_VERSION
        #define ALN_MONITORING_VERSION 8U
    #endif
    #ifndef ALN_MonopulseCorrectionVersion
        #define ALN_MonopulseCorrectionVersion 1U
    #endif
    #ifndef ALN_NvmVersion
        #define ALN_NvmVersion 9U
    #endif
    #ifndef ALN_PARAMETERS_INTFVER
        #define ALN_PARAMETERS_INTFVER 1U
    #endif
    #ifndef ALN_ReqHwConfigVersion
        #define ALN_ReqHwConfigVersion 2U
    #endif
    #ifndef BASE_CTRL_DATA_INTFVER
        #define BASE_CTRL_DATA_INTFVER 2U
    #endif
    #ifndef BSW_ALGOPARAMETERS_INTFVER
        #define BSW_ALGOPARAMETERS_INTFVER 42U
    #endif
    #ifndef BSW_VDY_CTRL_DATA_INTFVER
        #define BSW_VDY_CTRL_DATA_INTFVER 2U
    #endif
    #ifndef BSW_VEH_PAR_INTFVER
        #define BSW_VEH_PAR_INTFVER 9U
    #endif
    #ifndef BSW_VEH_SIG_INTFVER
        #define BSW_VEH_SIG_INTFVER 19U
    #endif
    #ifndef COMP_STATE_INTFVER
        #define COMP_STATE_INTFVER 3U
    #endif
    #ifndef CPAR_FCT_PARAMETERS_INTFVER
        #define CPAR_FCT_PARAMETERS_INTFVER 14U
    #endif
    #ifndef CamSLAInputData_INTFVER
        #define CamSLAInputData_INTFVER 1U
    #endif
    #ifndef EMBASE_OBJECT_LIST_CAM_INTFVER
        #define EMBASE_OBJECT_LIST_CAM_INTFVER 6U
    #endif
    #ifndef EM_ARS_OBJECT_LIST_INTFVER
        #define EM_ARS_OBJECT_LIST_INTFVER 6U
    #endif
    #ifndef EM_BSW_CTRL_DATA_INTFVER
        #define EM_BSW_CTRL_DATA_INTFVER 4U
    #endif
    #ifndef EM_CLUSTERLIST_FAR_INTFVER
        #define EM_CLUSTERLIST_FAR_INTFVER 6U
    #endif
    #ifndef EM_CLUSTERLIST_NEAR_INTFVER
        #define EM_CLUSTERLIST_NEAR_INTFVER 6U
    #endif
    #ifndef EM_CUSTOM_OBJECT_LIST_INTFVER
        #define EM_CUSTOM_OBJECT_LIST_INTFVER 4U
    #endif
    #ifndef EM_CUSTOM_ROAD_OUTPUT_INTFVER
        #define EM_CUSTOM_ROAD_OUTPUT_INTFVER 10U
    #endif
    #ifndef EM_DETECTIONLIST_NEAR_INTFVER
        #define EM_DETECTIONLIST_NEAR_INTFVER 2U
    #endif
    #ifndef EM_FCT_CYCLE_INTFVER
        #define EM_FCT_CYCLE_INTFVER 1U
    #endif
    #ifndef EM_FUSION_OBJECT_INTFVER
        #define EM_FUSION_OBJECT_INTFVER 3U
    #endif
    #ifndef EM_FUSION_OBJECT_LIST_INTFVER
        #define EM_FUSION_OBJECT_LIST_INTFVER 196608U
    #endif
    #ifndef EM_FUSION_OUTPUT_INTFVER
        #define EM_FUSION_OUTPUT_INTFVER 1U
    #endif
    #ifndef EM_GEN_OBJECT_INTFVER
        #define EM_GEN_OBJECT_INTFVER 18U
    #endif
    #ifndef EM_GEN_OBJECT_LIST_INTFVER
        #define EM_GEN_OBJECT_LIST_INTFVER 393216U
    #endif
    #ifndef EM_ME_INPUT_INTFVER
        #define EM_ME_INPUT_INTFVER 5U
    #endif
    #ifndef EM_ME_OUTPUT_INTFVER
        #define EM_ME_OUTPUT_INTFVER 2U
    #endif
    #ifndef EM_MOVING_OBJ_TRACES_INTFVER
        #define EM_MOVING_OBJ_TRACES_INTFVER 3U
    #endif
    #ifndef EM_NVM_INTFVER
        #define EM_NVM_INTFVER 3U
    #endif
    #ifndef EM_OBJECT_LIST_INTFVER
        #define EM_OBJECT_LIST_INTFVER 11U
    #endif
    #ifndef EM_OBJ_TRACES_INTFVER
        #define EM_OBJ_TRACES_INTFVER 258U
    #endif
    #ifndef EM_PERF_DEGR_EXT_INPUT_VERSION
        #define EM_PERF_DEGR_EXT_INPUT_VERSION 0U
    #endif
    #ifndef EM_PERF_DEGR_INTFVER
        #define EM_PERF_DEGR_INTFVER 12U
    #endif
    #ifndef EM_ROAD_INTFVER
        #define EM_ROAD_INTFVER 3U
    #endif
    #ifndef EM_RTBRecognition_INTFVER
        #define EM_RTBRecognition_INTFVER 3U
    #endif
    #ifndef EM_VEL_STAT_OBJ_INTFVER
        #define EM_VEL_STAT_OBJ_INTFVER 1U
    #endif
    #ifndef FCT_ACC_LEVER_INTFVER
        #define FCT_ACC_LEVER_INTFVER 6U
    #endif
    #ifndef FCT_ACC_OUTPUT_DATA_INTFVER
        #define FCT_ACC_OUTPUT_DATA_INTFVER 4U
    #endif
    #ifndef FCT_ASSESSED_OBJ_INTFVER
        #define FCT_ASSESSED_OBJ_INTFVER 16U
    #endif
    #ifndef FCT_CAM_LANE_INPUT_INTFVER
        #define FCT_CAM_LANE_INPUT_INTFVER 7U
    #endif
    #ifndef FCT_CD_OUTPUT_CUSTOM_INTFVER
        #define FCT_CD_OUTPUT_CUSTOM_INTFVER 22U
    #endif
    #ifndef FCT_CTRL_DATA_INTFVER
        #define FCT_CTRL_DATA_INTFVER 1U
    #endif
    #ifndef FCT_CUSTOM_INPUT_INTFVER
        #define FCT_CUSTOM_INPUT_INTFVER 24U
    #endif
    #ifndef FCT_CUSTOM_OUTPUT_INTFVER
        #define FCT_CUSTOM_OUTPUT_INTFVER 54U
    #endif
    #ifndef FCT_CUST_INPUT_INTFVER
        #define FCT_CUST_INPUT_INTFVER 7U
    #endif
    #ifndef FCT_DIM_INPUT_CUSTOM_INTFVER
        #define FCT_DIM_INPUT_CUSTOM_INTFVER 12U
    #endif
    #ifndef FCT_DIM_INPUT_GENERIC_INTFVER
        #define FCT_DIM_INPUT_GENERIC_INTFVER 6U
    #endif
    #ifndef FCT_DIM_OUTPUT_CUSTOM_INTFVER
        #define FCT_DIM_OUTPUT_CUSTOM_INTFVER 7U
    #endif
    #ifndef FCT_HEAD_INPUT_CUSTOM_INTFVER
        #define FCT_HEAD_INPUT_CUSTOM_INTFVER 23U
    #endif
    #ifndef FCT_HEAD_INPUT_GENERIC_INTFVER
        #define FCT_HEAD_INPUT_GENERIC_INTFVER 7U
    #endif
    #ifndef FCT_HEAD_OUTPUT_CUSTOM_INTFVER
        #define FCT_HEAD_OUTPUT_CUSTOM_INTFVER 53U
    #endif
    #ifndef FCT_HEAD_OUTPUT_GENERIC_INTFVER
        #define FCT_HEAD_OUTPUT_GENERIC_INTFVER 2U
    #endif
    #ifndef FCT_HYPOTHESIS_INTFVER
        #define FCT_HYPOTHESIS_INTFVER 30U
    #endif
    #ifndef FCT_LONG_CTRL_INPUT_INTFVER
        #define FCT_LONG_CTRL_INPUT_INTFVER 54U
    #endif
    #ifndef FCT_LONG_CTRL_OUTPUT_INTFVER
        #define FCT_LONG_CTRL_OUTPUT_INTFVER 40U
    #endif
    #ifndef FCT_SEN_ACC_OOI_INTFVER
        #define FCT_SEN_ACC_OOI_INTFVER 9U
    #endif
    #ifndef FCT_SEN_ERROR_OUT_INTFVER
        #define FCT_SEN_ERROR_OUT_INTFVER 18U
    #endif
    #ifndef FCT_TJA_TARGET_OBJ_INTFVER
        #define FCT_TJA_TARGET_OBJ_INTFVER 2U
    #endif
    #ifndef FCT_VEH_2_SEN_INFO_VERSION
        #define FCT_VEH_2_SEN_INFO_VERSION 6U
    #endif
    #ifndef FCT_VEH_ERROR_OUT_INTFVER
        #define FCT_VEH_ERROR_OUT_INTFVER 2U
    #endif
    #ifndef FCT_VEH_SIG_CUSTOM_INTFVER
        #define FCT_VEH_SIG_CUSTOM_INTFVER 4U
    #endif
    #ifndef LODM_INPUT_VERSION
        #define LODM_INPUT_VERSION 4U
    #endif
    #ifndef LODM_OUTPUT_INTFVER
        #define LODM_OUTPUT_INTFVER 3U
    #endif
    #ifndef LOHP_TCCP_INTFVER
        #define LOHP_TCCP_INTFVER 3U
    #endif
    #ifndef LOHP_TCSP_INTFVER
        #define LOHP_TCSP_INTFVER 2U
    #endif
    #ifndef LOPC_TFCP_INTFVER
        #define LOPC_TFCP_INTFVER 3U
    #endif
    #ifndef LOPC_TFSP_INTFVER
        #define LOPC_TFSP_INTFVER 2U
    #endif
    #ifndef RCG_CONTROL_DATA_INTVER
        #define RCG_CONTROL_DATA_INTVER 1U
    #endif
    #ifndef RCG_EXTERN_OBJECT_LIST_INTVER
        #define RCG_EXTERN_OBJECT_LIST_INTVER 1U
    #endif
    #ifndef RHC_ADJ_HW_CONFIG_VERSION
        #define RHC_ADJ_HW_CONFIG_VERSION 5U
    #endif
    #ifndef RHC_BswInVersion
        #define RHC_BswInVersion 6U
    #endif
    #ifndef RHC_BswOutVersion
        #define RHC_BswOutVersion 3U
    #endif
    #ifndef RHC_EventConfigVersion
        #define RHC_EventConfigVersion 2U
    #endif
    #ifndef RHC_RfComOut
        #define RHC_RfComOut 3U
    #endif
    #ifndef RHC_t_Nvm
        #define RHC_t_Nvm 1U
    #endif
    #ifndef RSP_INPUT_ACTL_INTFVER
        #define RSP_INPUT_ACTL_INTFVER 5U
    #endif
    #ifndef RSP_OUTP_CLLST_NEAR_INTFVER
        #define RSP_OUTP_CLLST_NEAR_INTFVER 7U
    #endif
    #ifndef RSP_OUTP_FDCMON_NS_INTFVER
        #define RSP_OUTP_FDCMON_NS_INTFVER 2U
    #endif
    #ifndef RSP_OUTP_NOISE_INTFVER
        #define RSP_OUTP_NOISE_INTFVER 3U
    #endif
    #ifndef RSP_OUTP_PRE_CLLST_NEAR_INTFVER
        #define RSP_OUTP_PRE_CLLST_NEAR_INTFVER 6U
    #endif
    #ifndef RSP_OUTP_RB_NS_INTFVER
        #define RSP_OUTP_RB_NS_INTFVER 3U
    #endif
    #ifndef RSP_OUTP_RHC_INTFVER
        #define RSP_OUTP_RHC_INTFVER 3U
    #endif
    #ifndef RSP_OUTP_RSPTOEM_NS_INTFVER
        #define RSP_OUTP_RSPTOEM_NS_INTFVER 3U
    #endif
    #ifndef RSP_OUTP_SPEC_BEAM_CMPLX_INTFVER
        #define RSP_OUTP_SPEC_BEAM_CMPLX_INTFVER 2U
    #endif
    #ifndef RSP_SPT_TEST_OUT_INTFVER
        #define RSP_SPT_TEST_OUT_INTFVER 0U
    #endif
    #ifndef SLAData_INTFVER
        #define SLAData_INTFVER 1U
    #endif
    #ifndef SYS_PERF_MON_OUT_INTFVER
        #define SYS_PERF_MON_OUT_INTFVER 3U
    #endif
    #ifndef TCIInput_INTFVER
        #define TCIInput_INTFVER 3U
    #endif
    #ifndef TCIOutput_INTFVER
        #define TCIOutput_INTFVER 4U
    #endif
    #ifndef TSA_SLATE_Input_INTFVER
        #define TSA_SLATE_Input_INTFVER 2U
    #endif
    #ifndef VDY_ERRORS_INTFVER
        #define VDY_ERRORS_INTFVER 3U
    #endif
    #ifndef VDY_EST_CURVES_INTFVER
        #define VDY_EST_CURVES_INTFVER 1U
    #endif
    #ifndef VDY_NVM_IO_DATA_INTFVER
        #define VDY_NVM_IO_DATA_INTFVER 1U
    #endif
    #ifndef VDY_OFFSETS_INTFVER
        #define VDY_OFFSETS_INTFVER 2U
    #endif
    #ifndef VDY_VEH_DYN_INTFVER
        #define VDY_VEH_DYN_INTFVER 19U
    #endif


//add camera macro



/* Enum types */
/* typedef AlgoErrorState_t */
	#ifndef   AL_ERR_STATE_UNKNOWN
	  #define AL_ERR_STATE_UNKNOWN	(0)
	#endif
	#ifndef   AL_ERR_STATE_ACTIVE
	  #define AL_ERR_STATE_ACTIVE	(1)
	#endif
	#ifndef   AL_ERR_STATE_INACTIVE
	  #define AL_ERR_STATE_INACTIVE	(2)
	#endif

/* typedef AlgoSignalState_t */
	#ifndef   AL_SIG_STATE_INIT
	  #define AL_SIG_STATE_INIT	(0)
	#endif
	#ifndef   AL_SIG_STATE_OK
	  #define AL_SIG_STATE_OK	(1)
	#endif
	#ifndef   AL_SIG_STATE_INVALID
	  #define AL_SIG_STATE_INVALID	(2)
	#endif

/* typedef SigState_t */
	#ifndef   SIGNAL_INVALID
	  #define SIGNAL_INVALID	(0)
	#endif
	#ifndef   SIGNAL_VALID
	  #define SIGNAL_VALID	(1)
	#endif

/* typedef GenAlgoQualifiers_t */
	#ifndef   ALGO_QUAL_OK
	  #define ALGO_QUAL_OK	(0)
	#endif
	#ifndef   ALGO_QUAL_CRITICAL_INPUT_ERROR
	  #define ALGO_QUAL_CRITICAL_INPUT_ERROR	(1)
	#endif
	#ifndef   ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR
	  #define ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR	(2)
	#endif
	#ifndef   ALGO_QUAL_BLOCKAGE
	  #define ALGO_QUAL_BLOCKAGE	(4)
	#endif
	#ifndef   ALGO_QUAL_PARTIAL_BLOCKAGE
	  #define ALGO_QUAL_PARTIAL_BLOCKAGE	(8)
	#endif
	#ifndef   ALGO_QUAL_CALIBRATION_ERROR_TOO_HIGH
	  #define ALGO_QUAL_CALIBRATION_ERROR_TOO_HIGH	(16)
	#endif
	#ifndef   ALGO_QUAL_GENERAL_FUNCTION_ERROR
	  #define ALGO_QUAL_GENERAL_FUNCTION_ERROR	(32)
	#endif
	#ifndef   ALGO_QUAL_NO_VISIBILITY
	  #define ALGO_QUAL_NO_VISIBILITY	(64)
	#endif
	#ifndef   ALGO_QUAL_LIMITED_VISIBILITY
	  #define ALGO_QUAL_LIMITED_VISIBILITY	(128)
	#endif
	#ifndef   ALGO_QUAL_CALIBRATION_RUNNING
	  #define ALGO_QUAL_CALIBRATION_RUNNING	(256)
	#endif
	#ifndef   ALGO_QUAL_MAX
	  #define ALGO_QUAL_MAX	(4294967295)
	#endif

/* typedef BaseReturnCode_t */
	#ifndef   BASE_RETURN_OK
	  #define BASE_RETURN_OK	(0)
	#endif
	#ifndef   BASE_RETURN_ERROR
	  #define BASE_RETURN_ERROR	(4294967295)
	#endif

/* typedef FusiErrorExtDirection_t */
	#ifndef   FUSI_ERROR_DIR_SNA
	  #define FUSI_ERROR_DIR_SNA	(0)
	#endif
	#ifndef   FUSI_ERROR_DIR_INPUT
	  #define FUSI_ERROR_DIR_INPUT	(1)
	#endif
	#ifndef   FUSI_ERROR_DIR_OUTPUT
	  #define FUSI_ERROR_DIR_OUTPUT	(2)
	#endif

/* typedef FusiErrorExtType_t */
	#ifndef   FUSI_ERROR_TYPE_SNA
	  #define FUSI_ERROR_TYPE_SNA	(0)
	#endif
	#ifndef   FUSI_ERROR_TYPE_NULLPOINTER
	  #define FUSI_ERROR_TYPE_NULLPOINTER	(1)
	#endif
	#ifndef   FUSI_ERROR_TYPE_VERSIONNUMBER
	  #define FUSI_ERROR_TYPE_VERSIONNUMBER	(2)
	#endif
	#ifndef   FUSI_ERROR_TYPE_SIGNALSTATE
	  #define FUSI_ERROR_TYPE_SIGNALSTATE	(3)
	#endif
	#ifndef   FUSI_ERROR_TYPE_COUNTER
	  #define FUSI_ERROR_TYPE_COUNTER	(4)
	#endif
	#ifndef   FUSI_ERROR_TYPE_FINGERPRINT
	  #define FUSI_ERROR_TYPE_FINGERPRINT	(5)
	#endif
	#ifndef   FUSI_ERROR_TYPE_VERIFICATION
	  #define FUSI_ERROR_TYPE_VERIFICATION	(6)
	#endif

/* typedef Percentage_s_t */
	#ifndef   Percentage_min
	  #define Percentage_min	(0)
	#endif
	#ifndef   Percentage_max
	  #define Percentage_max	(100)
	#endif

/* typedef True_False_s_t */
	#ifndef   RTE_False
	  #define RTE_False	(0)
	#endif
	#ifndef   RTE_True
	  #define RTE_True	(1)
	#endif

/* typedef BaseOpMode_t */
	#ifndef   BASE_OM_IDLE
	  #define BASE_OM_IDLE	(0)
	#endif
	#ifndef   BASE_OM_RESET
	  #define BASE_OM_RESET	(1)
	#endif
	#ifndef   BASE_OM_MAX_RUNTIME
	  #define BASE_OM_MAX_RUNTIME	(2)
	#endif
	#ifndef   BASE_OM_DEMO
	  #define BASE_OM_DEMO	(3)
	#endif
	#ifndef   BASE_OM_RUN
	  #define BASE_OM_RUN	(4)
	#endif
	#ifndef   BASE_OM_RUN_ODD
	  #define BASE_OM_RUN_ODD	(5)
	#endif
	#ifndef   BASE_OM_RUN_EVEN
	  #define BASE_OM_RUN_EVEN	(6)
	#endif
	#ifndef   BASE_OM_SYNC
	  #define BASE_OM_SYNC	(7)
	#endif
	#ifndef   BASE_OM_MEAS_ONLY
	  #define BASE_OM_MEAS_ONLY	(8)
	#endif
	#ifndef   BASE_OM_INIT_LUT
	  #define BASE_OM_INIT_LUT	(9)
	#endif
	#ifndef   BASE_OM_AUTOCAL_COARSE
	  #define BASE_OM_AUTOCAL_COARSE	(10)
	#endif
	#ifndef   BASE_OM_AUTOCAL_FINE
	  #define BASE_OM_AUTOCAL_FINE	(11)
	#endif
	#ifndef   BASE_OM_AUTO_CHOICE
	  #define BASE_OM_AUTO_CHOICE	(12)
	#endif
	#ifndef   BASE_OM_EOL_UPDATE
	  #define BASE_OM_EOL_UPDATE	(13)
	#endif
	#ifndef   BASE_OM_SELF_EVAL
	  #define BASE_OM_SELF_EVAL	(14)
	#endif
	#ifndef   BASE_OM_TEST
	  #define BASE_OM_TEST	(15)
	#endif
	#ifndef   BASE_OM_DISTANCE_TEST
	  #define BASE_OM_DISTANCE_TEST	(16)
	#endif
	#ifndef   BASE_OM_ECM_RTE_TRANSMIT
	  #define BASE_OM_ECM_RTE_TRANSMIT	(17)
	#endif
	#ifndef   BASE_OM_ECM_RTE_DEV
	  #define BASE_OM_ECM_RTE_DEV	(18)
	#endif
	#ifndef   BASE_OM_ECM_RTE_EOL
	  #define BASE_OM_ECM_RTE_EOL	(19)
	#endif
	#ifndef   BASE_OM_FEX_RUN_INIT_FPGA
	  #define BASE_OM_FEX_RUN_INIT_FPGA	(20)
	#endif
	#ifndef   BASE_OM_FEX_RUN_STARTUP_TEST_FPGA
	  #define BASE_OM_FEX_RUN_STARTUP_TEST_FPGA	(21)
	#endif
	#ifndef   BASE_OM_FEX_RUN_CYCLIC_TEST_FPGA
	  #define BASE_OM_FEX_RUN_CYCLIC_TEST_FPGA	(22)
	#endif
	#ifndef   BASE_OM_FEX_RUN_SAC_DATA
	  #define BASE_OM_FEX_RUN_SAC_DATA	(23)
	#endif
	#ifndef   BASE_OM_FEX_RUN_PED_DATA
	  #define BASE_OM_FEX_RUN_PED_DATA	(24)
	#endif
	#ifndef   BASE_OM_PED_RUN_HYPGEN
	  #define BASE_OM_PED_RUN_HYPGEN	(25)
	#endif
	#ifndef   BASE_OM_PED_RUN_IMAGE_TRACKING
	  #define BASE_OM_PED_RUN_IMAGE_TRACKING	(26)
	#endif
	#ifndef   BASE_OM_PED_RUN_CLUSTERING
	  #define BASE_OM_PED_RUN_CLUSTERING	(27)
	#endif
	#ifndef   BASE_OM_MEMO_SYNCVDY
	  #define BASE_OM_MEMO_SYNCVDY	(28)
	#endif
	#ifndef   BASE_OM_VCL_ROIGEN
	  #define BASE_OM_VCL_ROIGEN	(29)
	#endif
	#ifndef   BASE_OM_EM_PREDICT
	  #define BASE_OM_EM_PREDICT	(30)
	#endif
	#ifndef   BASE_OM_EM_UPDATE_GEN
	  #define BASE_OM_EM_UPDATE_GEN	(31)
	#endif
	#ifndef   BASE_OM_EM_UPDATE_PED
	  #define BASE_OM_EM_UPDATE_PED	(32)
	#endif
	#ifndef   BASE_OM_EM_UPDATE_VCL
	  #define BASE_OM_EM_UPDATE_VCL	(33)
	#endif
	#ifndef   BASE_OM_EM_UPDATE_SPC
	  #define BASE_OM_EM_UPDATE_SPC	(34)
	#endif
	#ifndef   BASE_OM_EM_MAINTENANCE
	  #define BASE_OM_EM_MAINTENANCE	(35)
	#endif
	#ifndef   BASE_OM_SIB_GEOMETRY
	  #define BASE_OM_SIB_GEOMETRY	(36)
	#endif
	#ifndef   BASE_OM_SIB_DYNAMIC
	  #define BASE_OM_SIB_DYNAMIC	(37)
	#endif
	#ifndef   BASE_OM_VODCA_PREPROCESS
	  #define BASE_OM_VODCA_PREPROCESS	(38)
	#endif
	#ifndef   BASE_OM_VODCA_CLASSIFY
	  #define BASE_OM_VODCA_CLASSIFY	(39)
	#endif
	#ifndef   BASE_OM_NVM_CALIB_RESET
	  #define BASE_OM_NVM_CALIB_RESET	(40)
	#endif
	#ifndef   BASE_OM_NVM_RESET
	  #define BASE_OM_NVM_RESET	(41)
	#endif
	#ifndef   BASE_OM_VCL_TRACK
	  #define BASE_OM_VCL_TRACK	(42)
	#endif
	#ifndef   BASE_OM_VCL_POSTPROC
	  #define BASE_OM_VCL_POSTPROC	(43)
	#endif
	#ifndef   BASE_OM_HLA_SEG
	  #define BASE_OM_HLA_SEG	(44)
	#endif
	#ifndef   BASE_OM_EM_PROCESS_GSS
	  #define BASE_OM_EM_PROCESS_GSS	(45)
	#endif
	#ifndef   BASE_OM_EM_PROCESS_OD
	  #define BASE_OM_EM_PROCESS_OD	(46)
	#endif
	#ifndef   BASE_OM_EM_PROCESS_ROAD
	  #define BASE_OM_EM_PROCESS_ROAD	(47)
	#endif
	#ifndef   BASE_OM_RUM_INITIAL_ROI_GEN
	  #define BASE_OM_RUM_INITIAL_ROI_GEN	(48)
	#endif
	#ifndef   BASE_OM_RUM_TRACKING
	  #define BASE_OM_RUM_TRACKING	(49)
	#endif
	#ifndef   BASE_OM_RUM_POST_PROC
	  #define BASE_OM_RUM_POST_PROC	(50)
	#endif
	#ifndef   BASE_OM_EM_PROCESS_FLOW
	  #define BASE_OM_EM_PROCESS_FLOW	(51)
	#endif
	#ifndef   BASE_OM_EM_PROCESS_LMD
	  #define BASE_OM_EM_PROCESS_LMD	(52)
	#endif
	#ifndef   BASE_OM_ACAL_TRANSMIT
	  #define BASE_OM_ACAL_TRANSMIT	(53)
	#endif
	#ifndef   BASE_OM_ACAL_CALIB
	  #define BASE_OM_ACAL_CALIB	(54)
	#endif
	#ifndef   BASE_OM_LD_TEXTURE_CLASSIFY
	  #define BASE_OM_LD_TEXTURE_CLASSIFY	(55)
	#endif
	#ifndef   BASE_OM_MEMO_RUN_EGOMOTION
	  #define BASE_OM_MEMO_RUN_EGOMOTION	(56)
	#endif
	#ifndef   BASE_OM_MEMO_RUN_DEPTH
	  #define BASE_OM_MEMO_RUN_DEPTH	(57)
	#endif
	#ifndef   BASE_OM_VODCA_PROCESS
	  #define BASE_OM_VODCA_PROCESS	(58)
	#endif
	#ifndef   BASE_OM_VODCA_PROCESS_FINAL
	  #define BASE_OM_VODCA_PROCESS_FINAL	(59)
	#endif
	#ifndef   BASE_OM_GEOS_PROCESS_FLOW
	  #define BASE_OM_GEOS_PROCESS_FLOW	(60)
	#endif
	#ifndef   BASE_OM_GEOS_SEGMENTATION
	  #define BASE_OM_GEOS_SEGMENTATION	(61)
	#endif
	#ifndef   BASE_OM_DAP01
	  #define BASE_OM_DAP01	(1001)
	#endif
	#ifndef   BASE_OM_DAP02
	  #define BASE_OM_DAP02	(1002)
	#endif
	#ifndef   BASE_OM_DAP03
	  #define BASE_OM_DAP03	(1003)
	#endif
	#ifndef   BASE_OM_DAP04
	  #define BASE_OM_DAP04	(1004)
	#endif
	#ifndef   BASE_OM_GP01
	  #define BASE_OM_GP01	(1010)
	#endif
	#ifndef   BASE_OM_GP02
	  #define BASE_OM_GP02	(1011)
	#endif
	#ifndef   BASE_OM_GP03
	  #define BASE_OM_GP03	(1012)
	#endif
	#ifndef   BASE_OM_GP04
	  #define BASE_OM_GP04	(1013)
	#endif
	#ifndef   BASE_OM_GP05
	  #define BASE_OM_GP05	(1014)
	#endif
	#ifndef   BASE_OM_GP06
	  #define BASE_OM_GP06	(1015)
	#endif
	#ifndef   BASE_OM_OD01
	  #define BASE_OM_OD01	(1021)
	#endif
	#ifndef   BASE_OM_OD02
	  #define BASE_OM_OD02	(1022)
	#endif
	#ifndef   BASE_OM_OD03
	  #define BASE_OM_OD03	(1023)
	#endif
	#ifndef   BASE_OM_OD04
	  #define BASE_OM_OD04	(1024)
	#endif
	#ifndef   BASE_OM_OD05
	  #define BASE_OM_OD05	(1025)
	#endif
	#ifndef   BASE_OM_OD06
	  #define BASE_OM_OD06	(1026)
	#endif
	#ifndef   BASE_OM_OD07
	  #define BASE_OM_OD07	(1027)
	#endif
	#ifndef   BASE_OM_PD01
	  #define BASE_OM_PD01	(1036)
	#endif
	#ifndef   BASE_OM_PD02
	  #define BASE_OM_PD02	(1037)
	#endif
	#ifndef   BASE_OM_PCC01
	  #define BASE_OM_PCC01	(1044)
	#endif
	#ifndef   BASE_OM_PCC02
	  #define BASE_OM_PCC02	(1045)
	#endif
	#ifndef   BASE_OM_PCA_NORMAL
	  #define BASE_OM_PCA_NORMAL	(2000)
	#endif
	#ifndef   BASE_OM_PCA_NUC
	  #define BASE_OM_PCA_NUC	(2001)
	#endif
	#ifndef   BASE_OM_INVALID
	  #define BASE_OM_INVALID	(65535)
	#endif

/* typedef BaseSchedulingMode_t */
	#ifndef   BASE_SM_IDLE
	  #define BASE_SM_IDLE	(0)
	#endif
	#ifndef   BASE_SM_RESET
	  #define BASE_SM_RESET	(1)
	#endif
	#ifndef   BASE_SM_DEMO
	  #define BASE_SM_DEMO	(2)
	#endif
	#ifndef   BASE_SM_RUN
	  #define BASE_SM_RUN	(3)
	#endif
	#ifndef   BASE_SM_EOL
	  #define BASE_SM_EOL	(4)
	#endif
	#ifndef   BASE_SM_CALIB
	  #define BASE_SM_CALIB	(5)
	#endif
	#ifndef   BASE_SM_DEGRADED
	  #define BASE_SM_DEGRADED	(6)
	#endif

/* typedef BaseSchedulingSubMode_t */
	#ifndef   BASE_SSM_NONE
	  #define BASE_SSM_NONE	(0)
	#endif
	#ifndef   BASE_SSM_BLOCKAGE
	  #define BASE_SSM_BLOCKAGE	(1)
	#endif
	#ifndef   BASE_SSM_DEGRADED
	  #define BASE_SSM_DEGRADED	(2)
	#endif
	#ifndef   BASE_SSM_STANDALONE
	  #define BASE_SSM_STANDALONE	(4)
	#endif
	#ifndef   BASE_SSM_PARALLEL
	  #define BASE_SSM_PARALLEL	(8)
	#endif
	#ifndef   BASE_SSM_NOT_CALIBRATED
	  #define BASE_SSM_NOT_CALIBRATED	(16)
	#endif

/* typedef CompState_t */
	#ifndef   COMP_STATE_NOT_INITIALIZED
	  #define COMP_STATE_NOT_INITIALIZED	(0)
	#endif
	#ifndef   COMP_STATE_RUNNING
	  #define COMP_STATE_RUNNING	(1)
	#endif
	#ifndef   COMP_STATE_TEMPORARY_ERROR
	  #define COMP_STATE_TEMPORARY_ERROR	(2)
	#endif
	#ifndef   COMP_STATE_PERMANENT_ERROR
	  #define COMP_STATE_PERMANENT_ERROR	(3)
	#endif
	#ifndef   COMP_STATE_SUCCESS
	  #define COMP_STATE_SUCCESS	(4)
	#endif
	#ifndef   COMP_STATE_REDUCED_AVAILABILITY
	  #define COMP_STATE_REDUCED_AVAILABILITY	(5)
	#endif
	#ifndef   COMP_STATE_NOT_RUNNING
	  #define COMP_STATE_NOT_RUNNING	(6)
	#endif

/* typedef CompErrorCode_t */
	#ifndef   COMP_ERROR_NO_ERROR
	  #define COMP_ERROR_NO_ERROR	(0)
	#endif
	#ifndef   COMP_ERROR_UNKNOWN
	  #define COMP_ERROR_UNKNOWN	(4294967295)
	#endif

/* typedef ImageDataFormat_t */
	#ifndef   ICF_NONE
	  #define ICF_NONE	(0)
	#endif
	#ifndef   ICF_GRAY
	  #define ICF_GRAY	(1)
	#endif
	#ifndef   ICF_BAYER_RGGB
	  #define ICF_BAYER_RGGB	(2)
	#endif
	#ifndef   ICF_BAYER_GRBG
	  #define ICF_BAYER_GRBG	(3)
	#endif
	#ifndef   ICF_BAYER_BGGR
	  #define ICF_BAYER_BGGR	(4)
	#endif
	#ifndef   ICF_BAYER_GBRG
	  #define ICF_BAYER_GBRG	(5)
	#endif
	#ifndef   ICF_YCRCB_420
	  #define ICF_YCRCB_420	(6)
	#endif
	#ifndef   ICF_U
	  #define ICF_U	(7)
	#endif
	#ifndef   ICF_V
	  #define ICF_V	(8)
	#endif
	#ifndef   ICF_SATURATION
	  #define ICF_SATURATION	(9)
	#endif
	#ifndef   ICF_2DVECTORFIELD
	  #define ICF_2DVECTORFIELD	(10)
	#endif
	#ifndef   ICF_UV
	  #define ICF_UV	(11)
	#endif

/* typedef FlowImageCorrespondenceType_t */
	#ifndef   FI_CORRESPONDENCE_TYPE_DEFAULT
	  #define FI_CORRESPONDENCE_TYPE_DEFAULT	(0)
	#endif
	#ifndef   FI_CORRESPONDENCE_TYPE_TEMPORAL
	  #define FI_CORRESPONDENCE_TYPE_TEMPORAL	(1)
	#endif
	#ifndef   FI_CORRESPONDENCE_TYPE_SPATIAL
	  #define FI_CORRESPONDENCE_TYPE_SPATIAL	(2)
	#endif
	#ifndef   FI_CORRESPONDENCE_TYPE_TEMPORAL_INVERSE
	  #define FI_CORRESPONDENCE_TYPE_TEMPORAL_INVERSE	(3)
	#endif

/* typedef eMonoCalibrationSide_t */
	#ifndef   MC_CAMERA_DEFAULT
	  #define MC_CAMERA_DEFAULT	(0)
	#endif
	#ifndef   MC_CAMERA_RIGHT
	  #define MC_CAMERA_RIGHT	(1)
	#endif
	#ifndef   MC_CAMERA_LEFT
	  #define MC_CAMERA_LEFT	(2)
	#endif

/* typedef eMonoCalibrationCameraType_t */
	#ifndef   MC_CAMERA_TYPE_DEFAULT
	  #define MC_CAMERA_TYPE_DEFAULT	(0)
	#endif
	#ifndef   MC_CAMERA_TYPE_IMAGER
	  #define MC_CAMERA_TYPE_IMAGER	(1)
	#endif
	#ifndef   MC_CAMERA_TYPE_CROI
	  #define MC_CAMERA_TYPE_CROI	(2)
	#endif
	#ifndef   MC_CAMERA_TYPE_RROI
	  #define MC_CAMERA_TYPE_RROI	(3)
	#endif
	#ifndef   MC_CAMERA_TYPE_RECTIFIED
	  #define MC_CAMERA_TYPE_RECTIFIED	(4)
	#endif

/* typedef eMonoCalibrationSource_t */
	#ifndef   MC_SOURCE_UNKNOWN
	  #define MC_SOURCE_UNKNOWN	(0)
	#endif
	#ifndef   MC_SOURCE_CODING
	  #define MC_SOURCE_CODING	(1)
	#endif
	#ifndef   MC_SOURCE_EOL_TARGET
	  #define MC_SOURCE_EOL_TARGET	(2)
	#endif
	#ifndef   MC_SOURCE_MANUAL
	  #define MC_SOURCE_MANUAL	(3)
	#endif
	#ifndef   MC_SOURCE_EOL_AUTO
	  #define MC_SOURCE_EOL_AUTO	(4)
	#endif
	#ifndef   MC_SOURCE_AUTO_CALI
	  #define MC_SOURCE_AUTO_CALI	(5)
	#endif

/* typedef GB_t_eFctId */
	#ifndef   GB_UNKNOWN_FCT_ID
	  #define GB_UNKNOWN_FCT_ID	(0)
	#endif
	#ifndef   GB_HLA_FCT_ID
	  #define GB_HLA_FCT_ID	(1)
	#endif
	#ifndef   GB_TSA_FCT_ID
	  #define GB_TSA_FCT_ID	(2)
	#endif
	#ifndef   GB_LDW_FCT_ID
	  #define GB_LDW_FCT_ID	(3)
	#endif
	#ifndef   GB_SOD_R_FCT_ID
	  #define GB_SOD_R_FCT_ID	(4)
	#endif
	#ifndef   GB_SOD_L_FCT_ID
	  #define GB_SOD_L_FCT_ID	(5)
	#endif
	#ifndef   GB_SOD_FCT_ID
	  #define GB_SOD_FCT_ID	(6)
	#endif

/* typedef GB_t_eBlockageStatus */
	#ifndef   GB_UNKNOWN_STATUS
	  #define GB_UNKNOWN_STATUS	(0)
	#endif
	#ifndef   GB_NO_BLOCKAGE
	  #define GB_NO_BLOCKAGE	(1)
	#endif
	#ifndef   GB_CONDENSATION
	  #define GB_CONDENSATION	(3)
	#endif
	#ifndef   GB_TOP_PART_BLOCKAGE
	  #define GB_TOP_PART_BLOCKAGE	(4)
	#endif
	#ifndef   GB_BOTTOM_PART_BLOCKAGE
	  #define GB_BOTTOM_PART_BLOCKAGE	(5)
	#endif
	#ifndef   GB_BLOCKAGE
	  #define GB_BLOCKAGE	(6)
	#endif
	#ifndef   GB_LEFT_PART_BLOCKAGE
	  #define GB_LEFT_PART_BLOCKAGE	(7)
	#endif
	#ifndef   GB_RIGHT_PART_BLOCKAGE
	  #define GB_RIGHT_PART_BLOCKAGE	(8)
	#endif

/* typedef GB_t_e_DegradationReason */
	#ifndef   GB_REAS_CONDENSATION
	  #define GB_REAS_CONDENSATION	(0)
	#endif
	#ifndef   GB_REAS_RAIN
	  #define GB_REAS_RAIN	(1)
	#endif
	#ifndef   GB_REAS_SNOW
	  #define GB_REAS_SNOW	(2)
	#endif
	#ifndef   GB_REAS_FOG
	  #define GB_REAS_FOG	(3)
	#endif
	#ifndef   GB_REAS_GLARING
	  #define GB_REAS_GLARING	(4)
	#endif
	#ifndef   GB_REAS_PARTIAL_BLOCKAGE
	  #define GB_REAS_PARTIAL_BLOCKAGE	(5)
	#endif
	#ifndef   GB_REAS_BLOCKAGE
	  #define GB_REAS_BLOCKAGE	(6)
	#endif

/* typedef GB_t_eStereoBlockageType */
	#ifndef   GB_RIGHT_CAM
	  #define GB_RIGHT_CAM	(2)
	#endif
	#ifndef   GB_LEFT_CAM
	  #define GB_LEFT_CAM	(4)
	#endif

/* typedef GB_t_eWeatherCondition */
	#ifndef   GB_HEAVY_RAIN_SNOW
	  #define GB_HEAVY_RAIN_SNOW	(2)
	#endif
	#ifndef   GB_HEAVY_FOG
	  #define GB_HEAVY_FOG	(4)
	#endif
	#ifndef   GB_HEAVY_GLARING_SUN
	  #define GB_HEAVY_GLARING_SUN	(8)
	#endif
	#ifndef   GB_GLARING
	  #define GB_GLARING	(16)
	#endif
	#ifndef   GB_RAIN
	  #define GB_RAIN	(32)
	#endif
	#ifndef   GB_FOG
	  #define GB_FOG	(64)
	#endif

/* typedef GB_t_eVisibilityRange */
	#ifndef   GB_UNKNOWN_VISIBILITY_RANGE
	  #define GB_UNKNOWN_VISIBILITY_RANGE	(0)
	#endif
	#ifndef   GB_CLEAR_VISIBILITY_RANGE
	  #define GB_CLEAR_VISIBILITY_RANGE	(1)
	#endif
	#ifndef   GB_HIGH_VISIBILITY_RANGE
	  #define GB_HIGH_VISIBILITY_RANGE	(2)
	#endif
	#ifndef   GB_MEDIUM_VISIBILITY_RANGE
	  #define GB_MEDIUM_VISIBILITY_RANGE	(3)
	#endif
	#ifndef   GB_LOW_VISIBILITY_RANGE
	  #define GB_LOW_VISIBILITY_RANGE	(4)
	#endif

/* typedef GB_t_BrightnessStates */
	#ifndef   GB_BRT_UNKNOWN
	  #define GB_BRT_UNKNOWN	(0)
	#endif
	#ifndef   GB_BRT_DAY
	  #define GB_BRT_DAY	(1)
	#endif
	#ifndef   GB_BRT_TWLGT
	  #define GB_BRT_TWLGT	(2)
	#endif
	#ifndef   GB_BRT_NIGHT
	  #define GB_BRT_NIGHT	(3)
	#endif

/* typedef GB_t_eOpticsStates */
	#ifndef   GB_CRACKED_WINDSHIELD
	  #define GB_CRACKED_WINDSHIELD	(2)
	#endif
	#ifndef   GB_CRACKED_LENS
	  #define GB_CRACKED_LENS	(4)
	#endif

/* typedef GB_t_eHeatingActivationRequest */
	#ifndef   GB_HEATING_ON_UNKNOWN
	  #define GB_HEATING_ON_UNKNOWN	(1)
	#endif
	#ifndef   GB_HEATING_ON_CONDENSATION
	  #define GB_HEATING_ON_CONDENSATION	(2)
	#endif
	#ifndef   GB_HEATING_ON_BLOCKAGE
	  #define GB_HEATING_ON_BLOCKAGE	(4)
	#endif
	#ifndef   GB_HEATING_ON_RAIN
	  #define GB_HEATING_ON_RAIN	(8)
	#endif
	#ifndef   GB_HEATING_ON_FOG
	  #define GB_HEATING_ON_FOG	(16)
	#endif

/* typedef CippErrorCode_t */
	#ifndef   CIPP_ERROR_NO_ERROR
	  #define CIPP_ERROR_NO_ERROR	(0)
	#endif
	#ifndef   CIPP_ERROR_UNKNOWN
	  #define CIPP_ERROR_UNKNOWN	(1)
	#endif
	#ifndef   CIPP_ERROR_OPMODE_NOT_SUPPORTED
	  #define CIPP_ERROR_OPMODE_NOT_SUPPORTED	(2)
	#endif
	#ifndef   CIPP_ERROR_INPUT_PORT_LIST_NULL_PTR
	  #define CIPP_ERROR_INPUT_PORT_LIST_NULL_PTR	(3)
	#endif
	#ifndef   CIPP_ERROR_INPUT_PORT_NULL_PTR
	  #define CIPP_ERROR_INPUT_PORT_NULL_PTR	(4)
	#endif
	#ifndef   CIPP_ERROR_INPUT_DATA_NULL_PTR
	  #define CIPP_ERROR_INPUT_DATA_NULL_PTR	(5)
	#endif
	#ifndef   CIPP_ERROR_INPUT_SERVICE_NULL_PTR
	  #define CIPP_ERROR_INPUT_SERVICE_NULL_PTR	(6)
	#endif
	#ifndef   CIPP_ERROR_OUTPUT_PORT_LIST_NULL_PTR
	  #define CIPP_ERROR_OUTPUT_PORT_LIST_NULL_PTR	(7)
	#endif
	#ifndef   CIPP_ERROR_OUTPUT_PORT_NULL_PTR
	  #define CIPP_ERROR_OUTPUT_PORT_NULL_PTR	(8)
	#endif
	#ifndef   CIPP_ERROR_OUTPUT_BUFFER_NULL_PTR
	  #define CIPP_ERROR_OUTPUT_BUFFER_NULL_PTR	(9)
	#endif
	#ifndef   CIPP_ERROR_INPUT_CFA_ALIGNMENT_NOT_SUPPORTED
	  #define CIPP_ERROR_INPUT_CFA_ALIGNMENT_NOT_SUPPORTED	(10)
	#endif
	#ifndef   CIPP_ERROR_INPUT_ODD_FRAMEFORMAT_NOT_SUPPORTED
	  #define CIPP_ERROR_INPUT_ODD_FRAMEFORMAT_NOT_SUPPORTED	(11)
	#endif
	#ifndef   CIPP_ERROR_INPUT_EVEN_FRAMEFORMAT_NOT_SUPPORTED
	  #define CIPP_ERROR_INPUT_EVEN_FRAMEFORMAT_NOT_SUPPORTED	(12)
	#endif
	#ifndef   CIPP_ERROR_RROI_FRAMEFORMAT_NOT_SUPPORTED
	  #define CIPP_ERROR_RROI_FRAMEFORMAT_NOT_SUPPORTED	(13)
	#endif
	#ifndef   CIPP_ERROR_EVE_ODD
	  #define CIPP_ERROR_EVE_ODD	(14)
	#endif
	#ifndef   CIPP_ERROR_EVE_EVEN
	  #define CIPP_ERROR_EVE_EVEN	(15)
	#endif
	#ifndef   CIPP_ERROR_INPUT_SIG_STATE_INVALID
	  #define CIPP_ERROR_INPUT_SIG_STATE_INVALID	(16)
	#endif
	#ifndef   CIPP_ERROR_ALGO_NOT_INITIALIZED
	  #define CIPP_ERROR_ALGO_NOT_INITIALIZED	(17)
	#endif
	#ifndef   CIPP_ERROR_INPUT_TIMESTAMP
	  #define CIPP_ERROR_INPUT_TIMESTAMP	(18)
	#endif
	#ifndef   CIPP_ERROR_IMAGE_FINGERPRINT
	  #define CIPP_ERROR_IMAGE_FINGERPRINT	(19)
	#endif

/* typedef EcmRteError_t */
	#ifndef   ECM_RTE_TYPE_NO_ERROR
	  #define ECM_RTE_TYPE_NO_ERROR	(0)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_WRONG_FOCAL
	  #define ECM_RTE_TYPE_ERR_INPUT_WRONG_FOCAL	(1)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_WRONG_MAINPOINT
	  #define ECM_RTE_TYPE_ERR_INPUT_WRONG_MAINPOINT	(2)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_IMAGE_SIZE
	  #define ECM_RTE_TYPE_ERR_INPUT_IMAGE_SIZE	(4)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_WRONG_DISTORTION
	  #define ECM_RTE_TYPE_ERR_INPUT_WRONG_DISTORTION	(8)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_WRONG_PATPOS
	  #define ECM_RTE_TYPE_ERR_INPUT_WRONG_PATPOS	(16)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_WRONG_SENSORPOS
	  #define ECM_RTE_TYPE_ERR_INPUT_WRONG_SENSORPOS	(32)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_WRONG_SENANGLESNOM
	  #define ECM_RTE_TYPE_ERR_INPUT_WRONG_SENANGLESNOM	(64)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_WRONG_SENANGLESTOL
	  #define ECM_RTE_TYPE_ERR_INPUT_WRONG_SENANGLESTOL	(128)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_WRONG_DISTANCE_BETWEEN_TARGET
	  #define ECM_RTE_TYPE_ERR_INPUT_WRONG_DISTANCE_BETWEEN_TARGET	(256)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_WRONG_IMAGEPATPOS
	  #define ECM_RTE_TYPE_ERR_INPUT_WRONG_IMAGEPATPOS	(512)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_IMAGEPTR
	  #define ECM_RTE_TYPE_ERR_INPUT_IMAGEPTR	(1024)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_EXTRACTION_CONSTRAST
	  #define ECM_RTE_TYPE_ERR_EXTRACTION_CONSTRAST	(2048)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_EXTRACTION_NO_TARGET
	  #define ECM_RTE_TYPE_ERR_EXTRACTION_NO_TARGET	(4096)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_EXTRACTION_TOO_MANY_TARGETS
	  #define ECM_RTE_TYPE_ERR_EXTRACTION_TOO_MANY_TARGETS	(8192)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_EXTRACTION_WHITE_CONSTRAST
	  #define ECM_RTE_TYPE_ERR_EXTRACTION_WHITE_CONSTRAST	(16384)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_EXTRACTION_TARGET_MOVING
	  #define ECM_RTE_TYPE_ERR_EXTRACTION_TARGET_MOVING	(32768)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_CALIBRATION_WRONG_TARGET_POSITION
	  #define ECM_RTE_TYPE_ERR_CALIBRATION_WRONG_TARGET_POSITION	(65536)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_CALIBRATION_WRONG_OUTPUT_ANGLES
	  #define ECM_RTE_TYPE_ERR_CALIBRATION_WRONG_OUTPUT_ANGLES	(131072)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_SOFTWARE
	  #define ECM_RTE_TYPE_ERR_SOFTWARE	(262144)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_CALIBRATION_WRONG_OUTPUT_ROLL
	  #define ECM_RTE_TYPE_ERR_CALIBRATION_WRONG_OUTPUT_ROLL	(524288)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_CALIBRATION_WRONG_OUTPUT_PITCH
	  #define ECM_RTE_TYPE_ERR_CALIBRATION_WRONG_OUTPUT_PITCH	(1048576)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_CALIBRATION_WRONG_OUTPUT_YAW
	  #define ECM_RTE_TYPE_ERR_CALIBRATION_WRONG_OUTPUT_YAW	(2097152)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INPUT_IDENTICAL_PATTERNS
	  #define ECM_RTE_TYPE_ERR_INPUT_IDENTICAL_PATTERNS	(4194304)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_TARGET_DIFFERENT_HORIZONTAL_DISTANCE
	  #define ECM_RTE_TYPE_ERR_TARGET_DIFFERENT_HORIZONTAL_DISTANCE	(8388608)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_TARGET_DIFFERENT_VERTICAL_DISTANCE
	  #define ECM_RTE_TYPE_ERR_TARGET_DIFFERENT_VERTICAL_DISTANCE	(16777216)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_CENTER_TARGET_ORTHOGONAL_DISTANCE_EXCEEDED
	  #define ECM_RTE_TYPE_ERR_CENTER_TARGET_ORTHOGONAL_DISTANCE_EXCEEDED	(33554432)
	#endif

/* typedef EcmRtePatPos_t */
	#ifndef   ECM_RTE_PAT_POS_LEFT
	  #define ECM_RTE_PAT_POS_LEFT	(0)
	#endif
	#ifndef   ECM_RTE_PAT_POS_MID
	  #define ECM_RTE_PAT_POS_MID	(1)
	#endif
	#ifndef   ECM_RTE_PAT_POS_RIGHT
	  #define ECM_RTE_PAT_POS_RIGHT	(2)
	#endif

/* typedef EcmRteProcRoiState_t */
	#ifndef   ECM_RTE_PROC_INIT_STATE
	  #define ECM_RTE_PROC_INIT_STATE	(0)
	#endif
	#ifndef   ECM_RTE_PROC_SEARCH_CIRCLE_STATE
	  #define ECM_RTE_PROC_SEARCH_CIRCLE_STATE	(1)
	#endif
	#ifndef   ECM_RTE_PROC_FINE_POSITIONING_STATE
	  #define ECM_RTE_PROC_FINE_POSITIONING_STATE	(2)
	#endif
	#ifndef   ECM_RTE_PROC_SAVE_CIRCLE_POS_STATE
	  #define ECM_RTE_PROC_SAVE_CIRCLE_POS_STATE	(3)
	#endif
	#ifndef   ECM_RTE_PROC_ECMC_CORRESPOND_CIRCLE_STATE
	  #define ECM_RTE_PROC_ECMC_CORRESPOND_CIRCLE_STATE	(4)
	#endif
	#ifndef   ECM_RTE_PROC_CHANGE_PATTERN_STATE
	  #define ECM_RTE_PROC_CHANGE_PATTERN_STATE	(5)
	#endif
	#ifndef   ECM_RTE_PROC_FIND_CORRESPOND_CIRCLE_STATE
	  #define ECM_RTE_PROC_FIND_CORRESPOND_CIRCLE_STATE	(6)
	#endif
	#ifndef   ECM_RTE_PROC_PATTERN_NOT_VERIFIED
	  #define ECM_RTE_PROC_PATTERN_NOT_VERIFIED	(7)
	#endif
	#ifndef   ECM_RTE_PROC_PATTERN_LOCATED
	  #define ECM_RTE_PROC_PATTERN_LOCATED	(8)
	#endif
	#ifndef   ECM_RTE_PROC_ERROR
	  #define ECM_RTE_PROC_ERROR	(9)
	#endif

/* typedef EcmRteCurMarker_t */
	#ifndef   ECM_RTE_MID_MARKER
	  #define ECM_RTE_MID_MARKER	(0)
	#endif
	#ifndef   ECM_RTE_LEFT_MARKER
	  #define ECM_RTE_LEFT_MARKER	(1)
	#endif
	#ifndef   ECM_RTE_RIGHT_MARKER
	  #define ECM_RTE_RIGHT_MARKER	(2)
	#endif

/* typedef PatPosRecognitionComplete_t */
	#ifndef   ECM_RTE_TYPE_RECOGNITION_NOT_COMPLETE
	  #define ECM_RTE_TYPE_RECOGNITION_NOT_COMPLETE	(0)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_COMPLETE_TARGET_1
	  #define ECM_RTE_TYPE_RECOGNITION_COMPLETE_TARGET_1	(1)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_COMPLETE_TARGET_2
	  #define ECM_RTE_TYPE_RECOGNITION_COMPLETE_TARGET_2	(2)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_COMPLETE_TARGET_3
	  #define ECM_RTE_TYPE_RECOGNITION_COMPLETE_TARGET_3	(3)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_COMPLETE_ALL_TARGETS
	  #define ECM_RTE_TYPE_RECOGNITION_COMPLETE_ALL_TARGETS	(4)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_COMPLETE_NEAR_TARGET_HYUNDAI_SERVICE
	  #define ECM_RTE_TYPE_RECOGNITION_COMPLETE_NEAR_TARGET_HYUNDAI_SERVICE	(5)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_COMPLETE_FAR_TARGET_HYUNDAI_SERVICE
	  #define ECM_RTE_TYPE_RECOGNITION_COMPLETE_FAR_TARGET_HYUNDAI_SERVICE	(6)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_COMPLETE_ALL_TARGETS_HYUNDAI_STD2
	  #define ECM_RTE_TYPE_RECOGNITION_COMPLETE_ALL_TARGETS_HYUNDAI_STD2	(7)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_COMPLETE_HYUNDAI_STD1
	  #define ECM_RTE_TYPE_RECOGNITION_COMPLETE_HYUNDAI_STD1	(8)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_COMPLETE_BYD
	  #define ECM_RTE_TYPE_RECOGNITION_COMPLETE_BYD	(9)
	#endif

/* typedef PatPosRecognitionReqFromDiag_t */
	#ifndef   ECM_RTE_TYPE_RECOGNITION_NO_REQUEST
	  #define ECM_RTE_TYPE_RECOGNITION_NO_REQUEST	(0)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_REQUEST_TARGET_1
	  #define ECM_RTE_TYPE_RECOGNITION_REQUEST_TARGET_1	(1)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_REQUEST_TARGET_2
	  #define ECM_RTE_TYPE_RECOGNITION_REQUEST_TARGET_2	(2)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_REQUEST_TARGET_3
	  #define ECM_RTE_TYPE_RECOGNITION_REQUEST_TARGET_3	(3)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_REQUEST_ALL_TARGETS
	  #define ECM_RTE_TYPE_RECOGNITION_REQUEST_ALL_TARGETS	(4)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_REQUEST_NEAR_TARGET_HYUNDAI_SERVICE
	  #define ECM_RTE_TYPE_RECOGNITION_REQUEST_NEAR_TARGET_HYUNDAI_SERVICE	(5)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_REQUEST_FAR_TARGET_HYUNDAI_SERVICE
	  #define ECM_RTE_TYPE_RECOGNITION_REQUEST_FAR_TARGET_HYUNDAI_SERVICE	(6)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_REQUEST_ALL_TARGETS_HYUNDAI_STD2
	  #define ECM_RTE_TYPE_RECOGNITION_REQUEST_ALL_TARGETS_HYUNDAI_STD2	(7)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_REQUEST_HYUNDAI_STD1
	  #define ECM_RTE_TYPE_RECOGNITION_REQUEST_HYUNDAI_STD1	(8)
	#endif
	#ifndef   ECM_RTE_TYPE_RECOGNITION_REQUEST_BYD
	  #define ECM_RTE_TYPE_RECOGNITION_REQUEST_BYD	(9)
	#endif

/* typedef EmoAvailability_t */
	#ifndef   EMO_AVAILABILITY_NOT_OK
	  #define EMO_AVAILABILITY_NOT_OK	(0)
	#endif
	#ifndef   EMO_AVAILABILITY_LIMITED
	  #define EMO_AVAILABILITY_LIMITED	(1)
	#endif
	#ifndef   EMO_AVAILABILITY_OK
	  #define EMO_AVAILABILITY_OK	(2)
	#endif
	#ifndef   EMO_AVAILABILITY_ERROR
	  #define EMO_AVAILABILITY_ERROR	(3)
	#endif

/* typedef eEmoInputSource_t */
	#ifndef   EMO_SOURCE_IMAGE_ONLY
	  #define EMO_SOURCE_IMAGE_ONLY	(0)
	#endif
	#ifndef   EMO_SOURCE_VDY_ONLY
	  #define EMO_SOURCE_VDY_ONLY	(1)
	#endif
	#ifndef   EMO_SOURCE_IMAGE_AND_VDY
	  #define EMO_SOURCE_IMAGE_AND_VDY	(2)
	#endif

/* typedef eEmoMotState_t */
	#ifndef   EMO_MOT_STATE_MOVE
	  #define EMO_MOT_STATE_MOVE	(0)
	#endif
	#ifndef   EMO_MOT_STATE_MOVE_FWD
	  #define EMO_MOT_STATE_MOVE_FWD	(1)
	#endif
	#ifndef   EMO_MOT_STATE_MOVE_RWD
	  #define EMO_MOT_STATE_MOVE_RWD	(2)
	#endif
	#ifndef   EMO_MOT_STATE_STDST
	  #define EMO_MOT_STATE_STDST	(3)
	#endif

/* typedef uiStatus_t */
	#ifndef   EMO_MAC_STATUS_NOT_CALIBRATED
	  #define EMO_MAC_STATUS_NOT_CALIBRATED	(0)
	#endif
	#ifndef   EMO_MAC_STATUS_CALIBRATED
	  #define EMO_MAC_STATUS_CALIBRATED	(1)
	#endif
	#ifndef   EMO_MAC_STATUS_CAM_BLOCKED
	  #define EMO_MAC_STATUS_CAM_BLOCKED	(2)
	#endif
	#ifndef   EMO_MAC_STATUS_DIST_EXCEEDED
	  #define EMO_MAC_STATUS_DIST_EXCEEDED	(3)
	#endif
	#ifndef   EMO_MAC_STATUS_ERROR_DEADJUSTMENT
	  #define EMO_MAC_STATUS_ERROR_DEADJUSTMENT	(4)
	#endif
	#ifndef   EMO_MAC_STATUS_ERROR_OTHER
	  #define EMO_MAC_STATUS_ERROR_OTHER	(5)
	#endif

/* typedef FtrcFeatureState_t */
	#ifndef   FTRC_FEAT_STATE_UNDEFINED
	  #define FTRC_FEAT_STATE_UNDEFINED	(0)
	#endif
	#ifndef   FTRC_FEAT_STATE_LOST
	  #define FTRC_FEAT_STATE_LOST	(1)
	#endif
	#ifndef   FTRC_FEAT_STATE_TRACKED
	  #define FTRC_FEAT_STATE_TRACKED	(2)
	#endif
	#ifndef   FTRC_FEAT_STATE_FOUND
	  #define FTRC_FEAT_STATE_FOUND	(3)
	#endif

/* typedef eCamObstacleDetected_t */
	#ifndef   EM_CLEARANCE_DET_FREE
	  #define EM_CLEARANCE_DET_FREE	(0)
	#endif
	#ifndef   EM_CLEARANCE_DET_NOT_FREE
	  #define EM_CLEARANCE_DET_NOT_FREE	(1)
	#endif
	#ifndef   EM_CLEARANCE_DET_INACTIVE
	  #define EM_CLEARANCE_DET_INACTIVE	(2)
	#endif

/* typedef EM_t_GSS_FlowSegmentOrientation */
	#ifndef   EM_GSS_SEG_UNKNOWN_ORIENTATION
	  #define EM_GSS_SEG_UNKNOWN_ORIENTATION	(0)
	#endif
	#ifndef   EM_GSS_SEG_BACKPLANE
	  #define EM_GSS_SEG_BACKPLANE	(1)
	#endif
	#ifndef   EM_GSS_SEG_SIDEPLANE
	  #define EM_GSS_SEG_SIDEPLANE	(2)
	#endif
	#ifndef   EM_GSS_SEG_IS_GROUNDPLANE
	  #define EM_GSS_SEG_IS_GROUNDPLANE	(3)
	#endif

/* typedef EM_t_GSS_DynamicFlag */
	#ifndef   EM_GSS_DYNFLAG_UNKNOWN
	  #define EM_GSS_DYNFLAG_UNKNOWN	(0)
	#endif
	#ifndef   EM_GSS_DYNFLAG_STATIC
	  #define EM_GSS_DYNFLAG_STATIC	(1)
	#endif
	#ifndef   EM_GSS_DYNFLAG_GROUND
	  #define EM_GSS_DYNFLAG_GROUND	(2)
	#endif
	#ifndef   EM_GSS_DYNFLAG_MOVING
	  #define EM_GSS_DYNFLAG_MOVING	(3)
	#endif
	#ifndef   EM_GSS_DYNFLAG_CROSSING
	  #define EM_GSS_DYNFLAG_CROSSING	(4)
	#endif
	#ifndef   EM_GSS_DYNFLAG_PASSING
	  #define EM_GSS_DYNFLAG_PASSING	(5)
	#endif
	#ifndef   EM_GSS_DYNFLAG_PRECEDING
	  #define EM_GSS_DYNFLAG_PRECEDING	(6)
	#endif
	#ifndef   EM_GSS_DYNFLAG_ONCOMING
	  #define EM_GSS_DYNFLAG_ONCOMING	(7)
	#endif
	#ifndef   EM_GSS_DYNFLAG_INFINITE
	  #define EM_GSS_DYNFLAG_INFINITE	(8)
	#endif
	#ifndef   EM_GSS_DYNFLAG_AMBIGUOS
	  #define EM_GSS_DYNFLAG_AMBIGUOS	(9)
	#endif

/* typedef EM_t_GSS_DynamicLabel */
	#ifndef   EM_GSS_DYN_UNKNOWN
	  #define EM_GSS_DYN_UNKNOWN	(0)
	#endif
	#ifndef   EM_GSS_DYN_GROUND
	  #define EM_GSS_DYN_GROUND	(1)
	#endif
	#ifndef   EM_GSS_DYN_STATIC
	  #define EM_GSS_DYN_STATIC	(2)
	#endif
	#ifndef   EM_GSS_DYN_MOVING
	  #define EM_GSS_DYN_MOVING	(3)
	#endif

/* typedef EM_t_GenObjShapePointState */
	#ifndef   EM_GEN_OBJECT_SHAPE_POINT_STATE_INVALID
	  #define EM_GEN_OBJECT_SHAPE_POINT_STATE_INVALID	(0)
	#endif
	#ifndef   EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED
	  #define EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED	(1)
	#endif
	#ifndef   EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_ASSUMED
	  #define EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_ASSUMED	(2)
	#endif
	#ifndef   EM_GEN_OBJECT_SHAPE_POINT_STATE_VISIBILITY_EDGE
	  #define EM_GEN_OBJECT_SHAPE_POINT_STATE_VISIBILITY_EDGE	(3)
	#endif
	#ifndef   EM_GEN_OBJECT_SHAPE_POINT_STATE_MAX_DIFF_TYPES
	  #define EM_GEN_OBJECT_SHAPE_POINT_STATE_MAX_DIFF_TYPES	(4)
	#endif

/* typedef EM_t_GenObjDynamicProperty */
	#ifndef   EM_GEN_OBJECT_DYN_PROPERTY_MOVING
	  #define EM_GEN_OBJECT_DYN_PROPERTY_MOVING	(0)
	#endif
	#ifndef   EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY
	  #define EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY	(1)
	#endif
	#ifndef   EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING
	  #define EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING	(2)
	#endif
	#ifndef   EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT
	  #define EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT	(3)
	#endif
	#ifndef   EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT
	  #define EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT	(4)
	#endif
	#ifndef   EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN
	  #define EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN	(5)
	#endif
	#ifndef   EM_GEN_OBJECT_DYN_PROPERTY_STOPPED
	  #define EM_GEN_OBJECT_DYN_PROPERTY_STOPPED	(6)
	#endif
	#ifndef   EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES
	  #define EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES	(7)
	#endif

/* typedef EM_t_GenObjClassification */
	#ifndef   EM_GEN_OBJECT_CLASS_POINT
	  #define EM_GEN_OBJECT_CLASS_POINT	(0)
	#endif
	#ifndef   EM_GEN_OBJECT_CLASS_CAR
	  #define EM_GEN_OBJECT_CLASS_CAR	(1)
	#endif
	#ifndef   EM_GEN_OBJECT_CLASS_TRUCK
	  #define EM_GEN_OBJECT_CLASS_TRUCK	(2)
	#endif
	#ifndef   EM_GEN_OBJECT_CLASS_PEDESTRIAN
	  #define EM_GEN_OBJECT_CLASS_PEDESTRIAN	(3)
	#endif
	#ifndef   EM_GEN_OBJECT_CLASS_MOTORCYCLE
	  #define EM_GEN_OBJECT_CLASS_MOTORCYCLE	(4)
	#endif
	#ifndef   EM_GEN_OBJECT_CLASS_BICYCLE
	  #define EM_GEN_OBJECT_CLASS_BICYCLE	(5)
	#endif
	#ifndef   EM_GEN_OBJECT_CLASS_WIDE
	  #define EM_GEN_OBJECT_CLASS_WIDE	(6)
	#endif
	#ifndef   EM_GEN_OBJECT_CLASS_UNCLASSIFIED
	  #define EM_GEN_OBJECT_CLASS_UNCLASSIFIED	(7)
	#endif
	#ifndef   EM_GEN_OBJECT_CLASS_OTHER_VEHICLE
	  #define EM_GEN_OBJECT_CLASS_OTHER_VEHICLE	(8)
	#endif
	#ifndef   EM_GEN_OBJECT_CLASS_TL
	  #define EM_GEN_OBJECT_CLASS_TL	(9)
	#endif
	#ifndef   EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES_LCF
	  #define EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES_LCF	(10)
	#endif

/* typedef EM_t_GenObjOcclusionState */
	#ifndef   EM_GEN_OBJECT_OCCL_NONE
	  #define EM_GEN_OBJECT_OCCL_NONE	(0)
	#endif
	#ifndef   EM_GEN_OBJECT_OCCL_UNKNOWN
	  #define EM_GEN_OBJECT_OCCL_UNKNOWN	(1)
	#endif
	#ifndef   EM_GEN_OBJECT_OCCL_PARTLY
	  #define EM_GEN_OBJECT_OCCL_PARTLY	(2)
	#endif
	#ifndef   EM_GEN_OBJECT_OCCL_FULL
	  #define EM_GEN_OBJECT_OCCL_FULL	(3)
	#endif
	#ifndef   EM_GEN_OBJECT_OCCL_MAX_DIFF_TYPES
	  #define EM_GEN_OBJECT_OCCL_MAX_DIFF_TYPES	(4)
	#endif

/* typedef EM_t_GenObjMaintenanceState */
	#ifndef   EM_GEN_OBJECT_MT_STATE_DELETED
	  #define EM_GEN_OBJECT_MT_STATE_DELETED	(0)
	#endif
	#ifndef   EM_GEN_OBJECT_MT_STATE_NEW
	  #define EM_GEN_OBJECT_MT_STATE_NEW	(1)
	#endif
	#ifndef   EM_GEN_OBJECT_MT_STATE_MEASURED
	  #define EM_GEN_OBJECT_MT_STATE_MEASURED	(2)
	#endif
	#ifndef   EM_GEN_OBJECT_MT_STATE_PREDICTED
	  #define EM_GEN_OBJECT_MT_STATE_PREDICTED	(3)
	#endif
	#ifndef   EM_GEN_OBJECT_MT_STATE_INACTIVE
	  #define EM_GEN_OBJECT_MT_STATE_INACTIVE	(4)
	#endif
	#ifndef   EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES
	  #define EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES	(5)
	#endif

/* typedef EM_t_GenObjSplitMergeState */
	#ifndef   EM_GEN_OBJECT_SM_STATE_NONE
	  #define EM_GEN_OBJECT_SM_STATE_NONE	(0)
	#endif
	#ifndef   EM_GEN_OBJECT_SM_STATE_MERGE
	  #define EM_GEN_OBJECT_SM_STATE_MERGE	(1)
	#endif
	#ifndef   EM_GEN_OBJECT_SM_STATE_SPLIT
	  #define EM_GEN_OBJECT_SM_STATE_SPLIT	(2)
	#endif
	#ifndef   EM_GEN_OBJECT_SM_STATE_MAX_DIFF_TYPES
	  #define EM_GEN_OBJECT_SM_STATE_MAX_DIFF_TYPES	(3)
	#endif

/* typedef EM_t_GenObjSensorSource */
	#ifndef   EM_GEN_OBJECT_MS_NONE
	  #define EM_GEN_OBJECT_MS_NONE	(0)
	#endif
	#ifndef   EM_GEN_OBJECT_MS_LRR
	  #define EM_GEN_OBJECT_MS_LRR	(1)
	#endif
	#ifndef   EM_GEN_OBJECT_MS_MRR
	  #define EM_GEN_OBJECT_MS_MRR	(2)
	#endif
	#ifndef   EM_GEN_OBJECT_MS_SRR
	  #define EM_GEN_OBJECT_MS_SRR	(4)
	#endif
	#ifndef   EM_GEN_OBJECT_MS_SRL
	  #define EM_GEN_OBJECT_MS_SRL	(8)
	#endif
	#ifndef   EM_GEN_OBJECT_MS_CAM
	  #define EM_GEN_OBJECT_MS_CAM	(16)
	#endif
	#ifndef   EM_GEN_OBJECT_MS_USN
	  #define EM_GEN_OBJECT_MS_USN	(32)
	#endif
	#ifndef   EM_GEN_OBJECT_MS_HFL
	  #define EM_GEN_OBJECT_MS_HFL	(64)
	#endif
	#ifndef   EM_GEN_OBJECT_MS_IR
	  #define EM_GEN_OBJECT_MS_IR	(128)
	#endif

/* typedef EM_t_GenEbaHypCat */
	#ifndef   FPS_EBA_HYP_CAT_NONE
	  #define FPS_EBA_HYP_CAT_NONE	(0)
	#endif
	#ifndef   FPS_EBA_HYP_CAT_PED
	  #define FPS_EBA_HYP_CAT_PED	(1)
	#endif
	#ifndef   FPS_EBA_HYP_CAT_VCL
	  #define FPS_EBA_HYP_CAT_VCL	(2)
	#endif
	#ifndef   FPS_EBA_HYP_CAT_XING
	  #define FPS_EBA_HYP_CAT_XING	(4)
	#endif
	#ifndef   FPS_EBA_HYP_CAT_ONC
	  #define FPS_EBA_HYP_CAT_ONC	(8)
	#endif
	#ifndef   FPS_EBA_HYP_CAT_STAT
	  #define FPS_EBA_HYP_CAT_STAT	(16)
	#endif
	#ifndef   FPS_EBA_HYP_CAT_CYCL
	  #define FPS_EBA_HYP_CAT_CYCL	(32)
	#endif
	#ifndef   FPS_EBA_HYP_CAT_COMOV
	  #define FPS_EBA_HYP_CAT_COMOV	(64)
	#endif
	#ifndef   FPS_EBA_HYP_CAT_ALL
	  #define FPS_EBA_HYP_CAT_ALL	(255)
	#endif

/* typedef EM_t_GenEbaInhibit */
	#ifndef   FPS_EBA_INH_NONE
	  #define FPS_EBA_INH_NONE	(0)
	#endif
	#ifndef   FPS_EBA_INH_LAT_WARN
	  #define FPS_EBA_INH_LAT_WARN	(1)
	#endif
	#ifndef   FPS_EBA_INH_PRE_WARN
	  #define FPS_EBA_INH_PRE_WARN	(2)
	#endif
	#ifndef   FPS_EBA_INH_ACU_WARN
	  #define FPS_EBA_INH_ACU_WARN	(4)
	#endif
	#ifndef   FPS_EBA_INH_PRE_FILL
	  #define FPS_EBA_INH_PRE_FILL	(8)
	#endif
	#ifndef   FPS_EBA_INH_HBA_THRD
	  #define FPS_EBA_INH_HBA_THRD	(16)
	#endif
	#ifndef   FPS_EBA_INH_HBA_TBRK
	  #define FPS_EBA_INH_HBA_TBRK	(32)
	#endif
	#ifndef   FPS_EBA_INH_PRECRASH
	  #define FPS_EBA_INH_PRECRASH	(64)
	#endif
	#ifndef   FPS_EBA_INH_BRAKE_L1
	  #define FPS_EBA_INH_BRAKE_L1	(128)
	#endif
	#ifndef   FPS_EBA_INH_BRAKE_L2
	  #define FPS_EBA_INH_BRAKE_L2	(256)
	#endif
	#ifndef   FPS_EBA_INH_BRAKE_L3
	  #define FPS_EBA_INH_BRAKE_L3	(512)
	#endif
	#ifndef   FPS_EBA_INH_ALL
	  #define FPS_EBA_INH_ALL	(65535)
	#endif

/* typedef EM_t_GenEbaObjClass */
	#ifndef   FPS_EBA_CLASS_NONE
	  #define FPS_EBA_CLASS_NONE	(0)
	#endif
	#ifndef   FPS_EBA_CLASS_UNKNOWN
	  #define FPS_EBA_CLASS_UNKNOWN	(1)
	#endif
	#ifndef   FPS_EBA_CLASS_CAR
	  #define FPS_EBA_CLASS_CAR	(2)
	#endif
	#ifndef   FPS_EBA_CLASS_TRUCK
	  #define FPS_EBA_CLASS_TRUCK	(3)
	#endif
	#ifndef   FPS_EBA_CLASS_PEDESTRIAN
	  #define FPS_EBA_CLASS_PEDESTRIAN	(4)
	#endif
	#ifndef   FPS_EBA_CLASS_CYCLIST
	  #define FPS_EBA_CLASS_CYCLIST	(5)
	#endif
	#ifndef   FPS_EBA_CLASS_MOTORBIKE
	  #define FPS_EBA_CLASS_MOTORBIKE	(6)
	#endif
	#ifndef   FPS_EBA_CLASS_VEHICLE
	  #define FPS_EBA_CLASS_VEHICLE	(7)
	#endif
	#ifndef   FPS_EBA_CLASS_MAX_VALUE
	  #define FPS_EBA_CLASS_MAX_VALUE	(255)
	#endif

/* typedef eRefpointLocation_t */
	#ifndef   EM_CAM_OBJ_REF_POINT_INVALID
	  #define EM_CAM_OBJ_REF_POINT_INVALID	(0)
	#endif
	#ifndef   EM_CAM_OBJ_REF_POINT_BACK
	  #define EM_CAM_OBJ_REF_POINT_BACK	(1)
	#endif
	#ifndef   EM_CAM_OBJ_REF_POINT_FRONT
	  #define EM_CAM_OBJ_REF_POINT_FRONT	(2)
	#endif
	#ifndef   EM_CAM_OBJ_REF_POINT_LEFT
	  #define EM_CAM_OBJ_REF_POINT_LEFT	(3)
	#endif
	#ifndef   EM_CAM_OBJ_REF_POINT_RIGHT
	  #define EM_CAM_OBJ_REF_POINT_RIGHT	(4)
	#endif

/* typedef EM_t_CamObjActiveFlag */
	#ifndef   EM_CAM_OBJ_AF_NONE
	  #define EM_CAM_OBJ_AF_NONE	(0)
	#endif
	#ifndef   EM_CAM_OBJ_AF_PEDESTRIAN
	  #define EM_CAM_OBJ_AF_PEDESTRIAN	(1)
	#endif
	#ifndef   EM_CAM_OBJ_AF_BICYCLE
	  #define EM_CAM_OBJ_AF_BICYCLE	(2)
	#endif
	#ifndef   EM_CAM_OBJ_AF_MOTORBIKE
	  #define EM_CAM_OBJ_AF_MOTORBIKE	(4)
	#endif
	#ifndef   EM_CAM_OBJ_AF_CAR
	  #define EM_CAM_OBJ_AF_CAR	(8)
	#endif
	#ifndef   EM_CAM_OBJ_AF_TRUCK
	  #define EM_CAM_OBJ_AF_TRUCK	(16)
	#endif
	#ifndef   EM_CAM_OBJ_AF_OTHER_VEHICLE
	  #define EM_CAM_OBJ_AF_OTHER_VEHICLE	(32)
	#endif
	#ifndef   EM_CAM_OBJ_AF_ROAD_BOUNDARY
	  #define EM_CAM_OBJ_AF_ROAD_BOUNDARY	(64)
	#endif
	#ifndef   EM_CAM_OBJ_AF_MASK
	  #define EM_CAM_OBJ_AF_MASK	(127)
	#endif

/* typedef EM_t_CamObjStatusBrakeLight */
	#ifndef   EM_CAM_OBJ_BRAKE_LIGHT_UNKNOWN
	  #define EM_CAM_OBJ_BRAKE_LIGHT_UNKNOWN	(0)
	#endif
	#ifndef   EM_CAM_OBJ_BRAKE_LIGHT_NO_BRAKING
	  #define EM_CAM_OBJ_BRAKE_LIGHT_NO_BRAKING	(1)
	#endif
	#ifndef   EM_CAM_OBJ_BRAKE_LIGHT_REGULAR_BRAKING
	  #define EM_CAM_OBJ_BRAKE_LIGHT_REGULAR_BRAKING	(2)
	#endif
	#ifndef   EM_CAM_OBJ_BRAKE_LIGHT_HEAVY_BREAKING
	  #define EM_CAM_OBJ_BRAKE_LIGHT_HEAVY_BREAKING	(3)
	#endif
	#ifndef   EM_CAM_OBJ_BRAKE_LIGHT_SNA
	  #define EM_CAM_OBJ_BRAKE_LIGHT_SNA	(255)
	#endif

/* typedef EM_t_CamObjStatusTurnIndicator */
	#ifndef   EM_CAM_OBJ_TURN_INDICATOR_UNKNOWN
	  #define EM_CAM_OBJ_TURN_INDICATOR_UNKNOWN	(0)
	#endif
	#ifndef   EM_CAM_OBJ_TURN_INDICATOR_NO_FLASHING
	  #define EM_CAM_OBJ_TURN_INDICATOR_NO_FLASHING	(1)
	#endif
	#ifndef   EM_CAM_OBJ_TURN_INDICATOR_FLASHING_LEFT
	  #define EM_CAM_OBJ_TURN_INDICATOR_FLASHING_LEFT	(2)
	#endif
	#ifndef   EM_CAM_OBJ_TURN_INDICATOR_FLASHING_RIGHT
	  #define EM_CAM_OBJ_TURN_INDICATOR_FLASHING_RIGHT	(3)
	#endif
	#ifndef   EM_CAM_OBJ_TURN_INDICATOR_HAZARD_FLASHING
	  #define EM_CAM_OBJ_TURN_INDICATOR_HAZARD_FLASHING	(4)
	#endif
	#ifndef   EM_CAM_OBJ_TURN_INDICATOR_SNA
	  #define EM_CAM_OBJ_TURN_INDICATOR_SNA	(255)
	#endif

/* typedef EM_t_CamObjAssociatedLane */
	#ifndef   EM_CAM_OBJ_ASSOC_LANE_UNKNOWN
	  #define EM_CAM_OBJ_ASSOC_LANE_UNKNOWN	(0)
	#endif
	#ifndef   EM_CAM_OBJ_ASSOC_LANE_EGO
	  #define EM_CAM_OBJ_ASSOC_LANE_EGO	(1)
	#endif
	#ifndef   EM_CAM_OBJ_ASSOC_LANE_LEFT
	  #define EM_CAM_OBJ_ASSOC_LANE_LEFT	(2)
	#endif
	#ifndef   EM_CAM_OBJ_ASSOC_LANE_RIGHT
	  #define EM_CAM_OBJ_ASSOC_LANE_RIGHT	(3)
	#endif
	#ifndef   EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_LEFT
	  #define EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_LEFT	(4)
	#endif
	#ifndef   EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_RIGHT
	  #define EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_RIGHT	(5)
	#endif
	#ifndef   EM_CAM_OBJ_ASSOC_LANE_SNA
	  #define EM_CAM_OBJ_ASSOC_LANE_SNA	(255)
	#endif

/* typedef EM_t_CamObjLaneChange */
	#ifndef   EM_CAM_OBJ_LANE_CHANGE_NONE
	  #define EM_CAM_OBJ_LANE_CHANGE_NONE	(0)
	#endif
	#ifndef   EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_RIGHT
	  #define EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_RIGHT	(1)
	#endif
	#ifndef   EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_LEFT
	  #define EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_LEFT	(2)
	#endif
	#ifndef   EM_CAM_OBJ_LANE_CHANGE_CUT_IN_RIGHT
	  #define EM_CAM_OBJ_LANE_CHANGE_CUT_IN_RIGHT	(3)
	#endif
	#ifndef   EM_CAM_OBJ_LANE_CHANGE_CUT_IN_LEFT
	  #define EM_CAM_OBJ_LANE_CHANGE_CUT_IN_LEFT	(4)
	#endif

/* typedef EM_t_GenLmkClassification */
	#ifndef   EM_GEN_LMK_CLASS_UNCLASSIFIED
	  #define EM_GEN_LMK_CLASS_UNCLASSIFIED	(0)
	#endif
	#ifndef   EM_GEN_LMK_CLASS_TL
	  #define EM_GEN_LMK_CLASS_TL	(1)
	#endif
	#ifndef   EM_GEN_LMK_CLASS_MAX_DIFF_TYPES
	  #define EM_GEN_LMK_CLASS_MAX_DIFF_TYPES	(2)
	#endif

/* typedef EM_t_GenLmkOcclusionState */
	#ifndef   EM_GEN_LMK_OCCL_NONE
	  #define EM_GEN_LMK_OCCL_NONE	(0)
	#endif
	#ifndef   EM_GEN_LMK_OCCL_UNKNOWN
	  #define EM_GEN_LMK_OCCL_UNKNOWN	(1)
	#endif
	#ifndef   EM_GEN_LMK_OCCL_PARTLY
	  #define EM_GEN_LMK_OCCL_PARTLY	(2)
	#endif
	#ifndef   EM_GEN_LMK_OCCL_FULL
	  #define EM_GEN_LMK_OCCL_FULL	(3)
	#endif
	#ifndef   EM_GEN_LMK_OCCL_MAX_DIFF_TYPES
	  #define EM_GEN_LMK_OCCL_MAX_DIFF_TYPES	(4)
	#endif

/* typedef EM_t_GenLmkTlColor */
	#ifndef   EM_GEN_LMK_TLC_UNKNOWN
	  #define EM_GEN_LMK_TLC_UNKNOWN	(0)
	#endif
	#ifndef   EM_GEN_LMK_TLC_RED
	  #define EM_GEN_LMK_TLC_RED	(1)
	#endif
	#ifndef   EM_GEN_LMK_TLC_YELLOW
	  #define EM_GEN_LMK_TLC_YELLOW	(2)
	#endif
	#ifndef   EM_GEN_LMK_TLC_RED_YELLOW
	  #define EM_GEN_LMK_TLC_RED_YELLOW	(3)
	#endif
	#ifndef   EM_GEN_LMK_TLC_GREEN
	  #define EM_GEN_LMK_TLC_GREEN	(4)
	#endif
	#ifndef   EM_GEN_LMK_TLC_SNA
	  #define EM_GEN_LMK_TLC_SNA	(255)
	#endif

/* typedef EM_t_GenLmkTlMode */
	#ifndef   EM_GEN_LMK_TLM_UNKNOWN
	  #define EM_GEN_LMK_TLM_UNKNOWN	(0)
	#endif
	#ifndef   EM_GEN_LMK_TLM_CONTINUOUS
	  #define EM_GEN_LMK_TLM_CONTINUOUS	(1)
	#endif
	#ifndef   EM_GEN_LMK_TLM_BLINKING
	  #define EM_GEN_LMK_TLM_BLINKING	(2)
	#endif
	#ifndef   EM_GEN_LMK_TLM_SNA
	  #define EM_GEN_LMK_TLM_SNA	(255)
	#endif

/* typedef EM_t_GenLmkTlSubClass */
	#ifndef   EM_GEN_LMK_TL_SC_UNKNOWN
	  #define EM_GEN_LMK_TL_SC_UNKNOWN	(0)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_CIRCULAR
	  #define EM_GEN_LMK_TL_SC_CIRCULAR	(1)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_CROSS
	  #define EM_GEN_LMK_TL_SC_CROSS	(2)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR
	  #define EM_GEN_LMK_TL_SC_DIR	(4)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_PED
	  #define EM_GEN_LMK_TL_SC_PED	(8)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_TRIANGLE
	  #define EM_GEN_LMK_TL_SC_TRIANGLE	(16)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_PED_TRIANGLE
	  #define EM_GEN_LMK_TL_SC_PED_TRIANGLE	(24)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIAG
	  #define EM_GEN_LMK_TL_SC_DIAG	(32)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_CROSS_DIAG
	  #define EM_GEN_LMK_TL_SC_CROSS_DIAG	(34)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_UP
	  #define EM_GEN_LMK_TL_SC_UP	(64)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_UP
	  #define EM_GEN_LMK_TL_SC_DIR_UP	(68)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DOWN
	  #define EM_GEN_LMK_TL_SC_DOWN	(128)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_DOWN
	  #define EM_GEN_LMK_TL_SC_DIR_DOWN	(132)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_LEFT
	  #define EM_GEN_LMK_TL_SC_LEFT	(256)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_LEFT
	  #define EM_GEN_LMK_TL_SC_DIR_LEFT	(260)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_UP_LEFT
	  #define EM_GEN_LMK_TL_SC_DIR_UP_LEFT	(324)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_DIAG_UP_LEFT
	  #define EM_GEN_LMK_TL_SC_DIR_DIAG_UP_LEFT	(356)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_DOWN_LEFT
	  #define EM_GEN_LMK_TL_SC_DIR_DOWN_LEFT	(388)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_DIAG_DOWN_LEFT
	  #define EM_GEN_LMK_TL_SC_DIR_DIAG_DOWN_LEFT	(420)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_RIGHT
	  #define EM_GEN_LMK_TL_SC_RIGHT	(512)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_RIGHT
	  #define EM_GEN_LMK_TL_SC_DIR_RIGHT	(516)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_UP_RIGHT
	  #define EM_GEN_LMK_TL_SC_DIR_UP_RIGHT	(580)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_DIAG_UP_RIGHT
	  #define EM_GEN_LMK_TL_SC_DIR_DIAG_UP_RIGHT	(612)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_DOWN_RIGHT
	  #define EM_GEN_LMK_TL_SC_DIR_DOWN_RIGHT	(644)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_DIAG_DOWN_RIGHT
	  #define EM_GEN_LMK_TL_SC_DIR_DIAG_DOWN_RIGHT	(676)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_LEFT_RIGHT
	  #define EM_GEN_LMK_TL_SC_DIR_LEFT_RIGHT	(772)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_UP_LEFT_RIGHT
	  #define EM_GEN_LMK_TL_SC_DIR_UP_LEFT_RIGHT	(836)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_DIR_DOWN_LEFT_RIGHT
	  #define EM_GEN_LMK_TL_SC_DIR_DOWN_LEFT_RIGHT	(900)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_BIKE
	  #define EM_GEN_LMK_TL_SC_BIKE	(1024)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_HAND
	  #define EM_GEN_LMK_TL_SC_HAND	(2048)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_BUS
	  #define EM_GEN_LMK_TL_SC_BUS	(4096)
	#endif
	#ifndef   EM_GEN_LMK_TL_SC_SNA
	  #define EM_GEN_LMK_TL_SC_SNA	(65535)
	#endif

/* typedef EM_t_GenLmkTlSubClassMode */
	#ifndef   EM_GEN_LMK_TL_SCM_DEFAULT
	  #define EM_GEN_LMK_TL_SCM_DEFAULT	(0)
	#endif
	#ifndef   EM_GEN_LMK_TL_SCM_INV
	  #define EM_GEN_LMK_TL_SCM_INV	(16384)
	#endif
	#ifndef   EM_GEN_LMK_TL_SCM_UNION
	  #define EM_GEN_LMK_TL_SCM_UNION	(32768)
	#endif
	#ifndef   EM_GEN_LMK_TL_SCM_INV_UNION
	  #define EM_GEN_LMK_TL_SCM_INV_UNION	(49152)
	#endif

/* typedef EM_t_GenLmkMaintenanceState */
	#ifndef   EM_GEN_LMK_MT_STATE_DELETED
	  #define EM_GEN_LMK_MT_STATE_DELETED	(0)
	#endif
	#ifndef   EM_GEN_LMK_MT_STATE_NEW
	  #define EM_GEN_LMK_MT_STATE_NEW	(1)
	#endif
	#ifndef   EM_GEN_LMK_MT_STATE_MEASURED
	  #define EM_GEN_LMK_MT_STATE_MEASURED	(2)
	#endif
	#ifndef   EM_GEN_LMK_MT_STATE_PREDICTED
	  #define EM_GEN_LMK_MT_STATE_PREDICTED	(3)
	#endif
	#ifndef   EM_GEN_LMK_MT_STATE_MAX_DIFF_TYPES
	  #define EM_GEN_LMK_MT_STATE_MAX_DIFF_TYPES	(4)
	#endif

/* typedef EM_t_GenLmkVisibilityState */
	#ifndef   EM_GEN_LMK_VIS_STATE_INTERNAL
	  #define EM_GEN_LMK_VIS_STATE_INTERNAL	(0)
	#endif
	#ifndef   EM_GEN_LMK_VIS_STATE_ALL
	  #define EM_GEN_LMK_VIS_STATE_ALL	(255)
	#endif

/* typedef EM_t_GenLmkSplitMergeState */
	#ifndef   EM_GEN_LMK_SM_STATE_NONE
	  #define EM_GEN_LMK_SM_STATE_NONE	(0)
	#endif
	#ifndef   EM_GEN_LMK_SM_STATE_MERGE
	  #define EM_GEN_LMK_SM_STATE_MERGE	(1)
	#endif
	#ifndef   EM_GEN_LMK_SM_STATE_SPLIT
	  #define EM_GEN_LMK_SM_STATE_SPLIT	(2)
	#endif
	#ifndef   EM_GEN_LMK_SM_STATE_MAX_DIFF_TYPES
	  #define EM_GEN_LMK_SM_STATE_MAX_DIFF_TYPES	(3)
	#endif

/* typedef EM_t_GenLmkSensorSource */
	#ifndef   EM_GEN_LMK_MS_NONE
	  #define EM_GEN_LMK_MS_NONE	(0)
	#endif
	#ifndef   EM_GEN_LMK_MS_LRR
	  #define EM_GEN_LMK_MS_LRR	(1)
	#endif
	#ifndef   EM_GEN_LMK_MS_MRR
	  #define EM_GEN_LMK_MS_MRR	(2)
	#endif
	#ifndef   EM_GEN_LMK_MS_SRR
	  #define EM_GEN_LMK_MS_SRR	(4)
	#endif
	#ifndef   EM_GEN_LMK_MS_SRL
	  #define EM_GEN_LMK_MS_SRL	(16)
	#endif
	#ifndef   EM_GEN_LMK_MS_MCAM
	  #define EM_GEN_LMK_MS_MCAM	(256)
	#endif
	#ifndef   EM_GEN_LMK_MS_SCAM
	  #define EM_GEN_LMK_MS_SCAM	(512)
	#endif

/* typedef EMT0_t_CamSensorState */
	#ifndef   EMT0_MCAM_SEN_STATE_UNKNOWN
	  #define EMT0_MCAM_SEN_STATE_UNKNOWN	(0)
	#endif
	#ifndef   EMT0_MCAM_SEN_STATE_OK
	  #define EMT0_MCAM_SEN_STATE_OK	(1)
	#endif
	#ifndef   EMT0_MCAM_SEN_STATE_NOT_OK
	  #define EMT0_MCAM_SEN_STATE_NOT_OK	(2)
	#endif
	#ifndef   EMT0_MCAM_SEN_STATE_BLOCKED
	  #define EMT0_MCAM_SEN_STATE_BLOCKED	(3)
	#endif

/* typedef EMT0_t_CamDetectionMode */
	#ifndef   EMT0_MCAM_DETECT_STATE_UNKNOWN
	  #define EMT0_MCAM_DETECT_STATE_UNKNOWN	(0)
	#endif
	#ifndef   EMT0_MCAM_DETECT_STATE_NORMAL
	  #define EMT0_MCAM_DETECT_STATE_NORMAL	(1)
	#endif
	#ifndef   EMT0_MCAM_DETECT_STATE_REDUCED
	  #define EMT0_MCAM_DETECT_STATE_REDUCED	(2)
	#endif

/* typedef EMT0_t_MCamObjDynProp */
	#ifndef   EMT0_MCAM_OBJ_DYN_PROP_MOVING
	  #define EMT0_MCAM_OBJ_DYN_PROP_MOVING	(0)
	#endif
	#ifndef   EMT0_MCAM_OBJ_DYN_PROP_STATIONARY
	  #define EMT0_MCAM_OBJ_DYN_PROP_STATIONARY	(1)
	#endif
	#ifndef   EMT0_MCAM_OBJ_DYN_PROP_ONCOMING
	  #define EMT0_MCAM_OBJ_DYN_PROP_ONCOMING	(2)
	#endif
	#ifndef   EMT0_MCAM_OBJ_DYN_PROP_CROSSING_LEFT
	  #define EMT0_MCAM_OBJ_DYN_PROP_CROSSING_LEFT	(3)
	#endif
	#ifndef   EMT0_MCAM_OBJ_DYN_PROP_CROSSING_RIGHT
	  #define EMT0_MCAM_OBJ_DYN_PROP_CROSSING_RIGHT	(4)
	#endif
	#ifndef   EMT0_MCAM_OBJ_DYN_PROP_UNKNOWN
	  #define EMT0_MCAM_OBJ_DYN_PROP_UNKNOWN	(5)
	#endif
	#ifndef   EMT0_MCAM_OBJ_DYN_PROP_STOPPED
	  #define EMT0_MCAM_OBJ_DYN_PROP_STOPPED	(6)
	#endif

/* typedef EMT0_t_MCamObjClass */
	#ifndef   EMT0_MCAM_OBJ_CLASS_POINT
	  #define EMT0_MCAM_OBJ_CLASS_POINT	(0)
	#endif
	#ifndef   EMT0_MCAM_OBJ_CLASS_CAR
	  #define EMT0_MCAM_OBJ_CLASS_CAR	(1)
	#endif
	#ifndef   EMT0_MCAM_OBJ_CLASS_TRUCK
	  #define EMT0_MCAM_OBJ_CLASS_TRUCK	(2)
	#endif
	#ifndef   EMT0_MCAM_OBJ_CLASS_PEDESTRIAN
	  #define EMT0_MCAM_OBJ_CLASS_PEDESTRIAN	(3)
	#endif
	#ifndef   EMT0_MCAM_OBJ_CLASS_MOTORCYCLE
	  #define EMT0_MCAM_OBJ_CLASS_MOTORCYCLE	(4)
	#endif
	#ifndef   EMT0_MCAM_OBJ_CLASS_BICYCLE
	  #define EMT0_MCAM_OBJ_CLASS_BICYCLE	(5)
	#endif
	#ifndef   EMT0_MCAM_OBJ_CLASS_WIDE
	  #define EMT0_MCAM_OBJ_CLASS_WIDE	(6)
	#endif
	#ifndef   EMT0_MCAM_OBJ_CLASS_UNCLASSIFIED
	  #define EMT0_MCAM_OBJ_CLASS_UNCLASSIFIED	(7)
	#endif

/* typedef EMT0_t_ObjFlashLightStat */
	#ifndef   EMT0_MCAM_SFL_UNKNOWN
	  #define EMT0_MCAM_SFL_UNKNOWN	(0)
	#endif
	#ifndef   EMT0_MCAM_SFL_NO_FLASHING
	  #define EMT0_MCAM_SFL_NO_FLASHING	(1)
	#endif
	#ifndef   EMT0_MCAM_SFL_FLASHING_LEFT
	  #define EMT0_MCAM_SFL_FLASHING_LEFT	(2)
	#endif
	#ifndef   EMT0_MCAM_SFL_FLASHING_RIGHT
	  #define EMT0_MCAM_SFL_FLASHING_RIGHT	(3)
	#endif
	#ifndef   EMT0_MCAM_SFL_HAZARD_FLASHING
	  #define EMT0_MCAM_SFL_HAZARD_FLASHING	(4)
	#endif
	#ifndef   EMT0_MCAM_SFL_SNA
	  #define EMT0_MCAM_SFL_SNA	(255)
	#endif

/* typedef ui_Accuracy_t */
	#ifndef   EMT0_MCAM_OBJ_ACCURACY_NA
	  #define EMT0_MCAM_OBJ_ACCURACY_NA	(0)
	#endif
	#ifndef   EMT0_MCAM_OBJ_ACCURACY_LOW
	  #define EMT0_MCAM_OBJ_ACCURACY_LOW	(1)
	#endif
	#ifndef   EMT0_MCAM_OBJ_ACCURACY_MID
	  #define EMT0_MCAM_OBJ_ACCURACY_MID	(2)
	#endif
	#ifndef   EMT0_MCAM_OBJ_ACCURACY_HIGH
	  #define EMT0_MCAM_OBJ_ACCURACY_HIGH	(3)
	#endif

/* typedef EMT0_t_CamObjAssociatedLane */
	#ifndef   EMT0_MCAM_OBJ_ASSOC_LANE_UNKNOWN
	  #define EMT0_MCAM_OBJ_ASSOC_LANE_UNKNOWN	(0)
	#endif
	#ifndef   EMT0_MCAM_OBJ_ASSOC_LANE_EGO
	  #define EMT0_MCAM_OBJ_ASSOC_LANE_EGO	(1)
	#endif
	#ifndef   EMT0_MCAM_OBJ_ASSOC_LANE_LEFT
	  #define EMT0_MCAM_OBJ_ASSOC_LANE_LEFT	(2)
	#endif
	#ifndef   EMT0_MCAM_OBJ_ASSOC_LANE_RIGHT
	  #define EMT0_MCAM_OBJ_ASSOC_LANE_RIGHT	(3)
	#endif
	#ifndef   EMT0_MCAM_OBJ_ASSOC_LANE_OUTSIDE
	  #define EMT0_MCAM_OBJ_ASSOC_LANE_OUTSIDE	(4)
	#endif
	#ifndef   EMT0_MCAM_OBJ_ASSOC_LANE_BEYOND_LEFT
	  #define EMT0_MCAM_OBJ_ASSOC_LANE_BEYOND_LEFT	(5)
	#endif
	#ifndef   EMT0_MCAM_OBJ_ASSOC_LANE_BEYOND_RIGHT
	  #define EMT0_MCAM_OBJ_ASSOC_LANE_BEYOND_RIGHT	(6)
	#endif
	#ifndef   EMT0_MCAM_OBJ_ASSOC_LANE_SNA
	  #define EMT0_MCAM_OBJ_ASSOC_LANE_SNA	(255)
	#endif

/* typedef EM_t_CustomerProjectDef */
	#ifndef   EM_PRJ_MFC400
	  #define EM_PRJ_MFC400	(0)
	#endif
	#ifndef   EM_PRJ_SMFC4B0
	  #define EM_PRJ_SMFC4B0	(1)
	#endif

/* typedef Result_t */
	#ifndef   eFamoOutputReset
	  #define eFamoOutputReset	(0)
	#endif
	#ifndef   eFamoSuccessful
	  #define eFamoSuccessful	(2863311530)
	#endif

/* typedef FCT_OP_MODE_t */
	#ifndef   FCT_MOD_STARTUP
	  #define FCT_MOD_STARTUP	(0)
	#endif
	#ifndef   FCT_MOD_INIT
	  #define FCT_MOD_INIT	(1)
	#endif
	#ifndef   FCT_MOD_RUNNING
	  #define FCT_MOD_RUNNING	(2)
	#endif
	#ifndef   FCT_MOD_SHUTDOWN
	  #define FCT_MOD_SHUTDOWN	(3)
	#endif
	#ifndef   FCT_MOD_PAUSE
	  #define FCT_MOD_PAUSE	(4)
	#endif

/* typedef FCTStateSig_t */
	#ifndef   eFCT_STATE_SIG_INACTIVE
	  #define eFCT_STATE_SIG_INACTIVE	(0)
	#endif
	#ifndef   eFCT_STATE_SIG_ACTIVE
	  #define eFCT_STATE_SIG_ACTIVE	(1)
	#endif
	#ifndef   eFCT_STATE_SIG_INVALID
	  #define eFCT_STATE_SIG_INVALID	(2)
	#endif

/* typedef t_EBACodingParamFctModsIdx */
	#ifndef   eEBACodingIdx_LongVehMov
	  #define eEBACodingIdx_LongVehMov	(0)
	#endif
	#ifndef   eEBACodingIdx_LongVehStat
	  #define eEBACodingIdx_LongVehStat	(1)
	#endif
	#ifndef   eEBACodingIdx_LongPedMov
	  #define eEBACodingIdx_LongPedMov	(2)
	#endif
	#ifndef   eEBACodingIdx_LongPedStat
	  #define eEBACodingIdx_LongPedStat	(3)
	#endif
	#ifndef   eEBACodingIdx_LongCyclMov
	  #define eEBACodingIdx_LongCyclMov	(4)
	#endif
	#ifndef   eEBACodingIdx_LongCyclStat
	  #define eEBACodingIdx_LongCyclStat	(5)
	#endif
	#ifndef   eEBACodingIdx_LongObsMov
	  #define eEBACodingIdx_LongObsMov	(6)
	#endif
	#ifndef   eEBACodingIdx_LongObsStat
	  #define eEBACodingIdx_LongObsStat	(7)
	#endif
	#ifndef   eEBACodingIdx_CrossVehMov
	  #define eEBACodingIdx_CrossVehMov	(8)
	#endif
	#ifndef   eEBACodingIdx_CrossVehStat
	  #define eEBACodingIdx_CrossVehStat	(9)
	#endif
	#ifndef   eEBACodingIdx_CrossPedMov
	  #define eEBACodingIdx_CrossPedMov	(10)
	#endif
	#ifndef   eEBACodingIdx_CrossPedStat
	  #define eEBACodingIdx_CrossPedStat	(11)
	#endif
	#ifndef   eEBACodingIdx_CrossCyclMov
	  #define eEBACodingIdx_CrossCyclMov	(12)
	#endif
	#ifndef   eEBACodingIdx_CrossCyclStat
	  #define eEBACodingIdx_CrossCyclStat	(13)
	#endif
	#ifndef   eEBACodingIdx_CrossObsMov
	  #define eEBACodingIdx_CrossObsMov	(14)
	#endif
	#ifndef   eEBACodingIdx_CrossObsStat
	  #define eEBACodingIdx_CrossObsStat	(15)
	#endif
	#ifndef   eEBACodingIdx_OncVehMov
	  #define eEBACodingIdx_OncVehMov	(16)
	#endif
	#ifndef   eEBACodingIdx_OncVehStat
	  #define eEBACodingIdx_OncVehStat	(17)
	#endif
	#ifndef   eEBACodingIdx_OncPedMov
	  #define eEBACodingIdx_OncPedMov	(18)
	#endif
	#ifndef   eEBACodingIdx_OncPedStat
	  #define eEBACodingIdx_OncPedStat	(19)
	#endif
	#ifndef   eEBACodingIdx_OncCyclMov
	  #define eEBACodingIdx_OncCyclMov	(20)
	#endif
	#ifndef   eEBACodingIdx_OncCyclStat
	  #define eEBACodingIdx_OncCyclStat	(21)
	#endif
	#ifndef   eEBACodingIdx_OncObsMov
	  #define eEBACodingIdx_OncObsMov	(22)
	#endif
	#ifndef   eEBACodingIdx_OncObsStat
	  #define eEBACodingIdx_OncObsStat	(23)
	#endif

/* typedef eRelObjLossReason_t */
	#ifndef   OBJ_LOSS_NO_INFO
	  #define OBJ_LOSS_NO_INFO	(0)
	#endif
	#ifndef   OBJ_LOSS_DISAPPEARED
	  #define OBJ_LOSS_DISAPPEARED	(1)
	#endif
	#ifndef   OBJ_LOSS_LANE_CHG_LEFT
	  #define OBJ_LOSS_LANE_CHG_LEFT	(2)
	#endif
	#ifndef   OBJ_LOSS_LANE_CHG_RIGHT
	  #define OBJ_LOSS_LANE_CHG_RIGHT	(3)
	#endif
	#ifndef   OBJ_LOSS_CURVE_LEFT
	  #define OBJ_LOSS_CURVE_LEFT	(4)
	#endif
	#ifndef   OBJ_LOSS_CURVE_RIGHT
	  #define OBJ_LOSS_CURVE_RIGHT	(5)
	#endif
	#ifndef   OBJ_LOSS_CURVE_LEFT_AHEAD
	  #define OBJ_LOSS_CURVE_LEFT_AHEAD	(6)
	#endif
	#ifndef   OBJ_LOSS_CURVE_RIGHT_AHEAD
	  #define OBJ_LOSS_CURVE_RIGHT_AHEAD	(7)
	#endif
	#ifndef   OBJ_LOSS_STEER_LEFT
	  #define OBJ_LOSS_STEER_LEFT	(8)
	#endif
	#ifndef   OBJ_LOSS_STEER_RIGHT
	  #define OBJ_LOSS_STEER_RIGHT	(9)
	#endif
	#ifndef   OBJ_LOSS_RANGE_REDUCTION
	  #define OBJ_LOSS_RANGE_REDUCTION	(10)
	#endif
	#ifndef   OBJ_LOSS_DISAPP_LOWDIST
	  #define OBJ_LOSS_DISAPP_LOWDIST	(11)
	#endif

/* typedef eAssociatedLane_t */
	#ifndef   ASSOC_LANE_UNKNOWN
	  #define ASSOC_LANE_UNKNOWN	(0)
	#endif
	#ifndef   ASSOC_LANE_FAR_LEFT
	  #define ASSOC_LANE_FAR_LEFT	(1)
	#endif
	#ifndef   ASSOC_LANE_LEFT
	  #define ASSOC_LANE_LEFT	(2)
	#endif
	#ifndef   ASSOC_LANE_EGO
	  #define ASSOC_LANE_EGO	(3)
	#endif
	#ifndef   ASSOC_LANE_RIGHT
	  #define ASSOC_LANE_RIGHT	(4)
	#endif
	#ifndef   ASSOC_LANE_FAR_RIGHT
	  #define ASSOC_LANE_FAR_RIGHT	(5)
	#endif

/* typedef eObjOOI_t */
	#ifndef   OBJ_NOT_OOI
	  #define OBJ_NOT_OOI	(-1)
	#endif
	#ifndef   OBJ_NEXT_OOI
	  #define OBJ_NEXT_OOI	(0)
	#endif
	#ifndef   OBJ_HIDDEN_NEXT_OOI
	  #define OBJ_HIDDEN_NEXT_OOI	(1)
	#endif
	#ifndef   OBJ_NEXT_LONG_LEFT_OOI
	  #define OBJ_NEXT_LONG_LEFT_OOI	(2)
	#endif
	#ifndef   OBJ_NEXT_LONG_RIGHT_OOI
	  #define OBJ_NEXT_LONG_RIGHT_OOI	(3)
	#endif
	#ifndef   OBJ_NEXT_LAT_LEFT_OOI
	  #define OBJ_NEXT_LAT_LEFT_OOI	(4)
	#endif
	#ifndef   OBJ_NEXT_LAT_RIGHT_OOI
	  #define OBJ_NEXT_LAT_RIGHT_OOI	(5)
	#endif

/* typedef eDynamicMeasStatus_t */
	#ifndef   NOT_MEASURED_STOPPED_OBJ
	  #define NOT_MEASURED_STOPPED_OBJ	(0)
	#endif
	#ifndef   NOT_MEASURED_STANDING_OBJ
	  #define NOT_MEASURED_STANDING_OBJ	(1)
	#endif
	#ifndef   NOT_MEASURED_ONCOMING_OBJ
	  #define NOT_MEASURED_ONCOMING_OBJ	(2)
	#endif
	#ifndef   NOT_MEASURED_MOVING_OBJ
	  #define NOT_MEASURED_MOVING_OBJ	(3)
	#endif
	#ifndef   MEASURED_STOPPED_OBJ
	  #define MEASURED_STOPPED_OBJ	(4)
	#endif
	#ifndef   MEASURED_STANDING_OBJ
	  #define MEASURED_STANDING_OBJ	(5)
	#endif
	#ifndef   MEASURED_ONCOMING_OBJ
	  #define MEASURED_ONCOMING_OBJ	(6)
	#endif
	#ifndef   MEASURED_MOVING_OBJ
	  #define MEASURED_MOVING_OBJ	(7)
	#endif
	#ifndef   NEW_STOPPED_OBJ
	  #define NEW_STOPPED_OBJ	(8)
	#endif
	#ifndef   NEW_STANDING_OBJ
	  #define NEW_STANDING_OBJ	(9)
	#endif
	#ifndef   NEW_ONCOMING_OBJ
	  #define NEW_ONCOMING_OBJ	(10)
	#endif
	#ifndef   NEW_MOVING_OBJ
	  #define NEW_MOVING_OBJ	(11)
	#endif
	#ifndef   IMPLAUSIBLE_OBJ
	  #define IMPLAUSIBLE_OBJ	(12)
	#endif
	#ifndef   NO_OBJ
	  #define NO_OBJ	(14)
	#endif

/* typedef eObjMeasStatus_t */
	#ifndef   OBJ_NONE
	  #define OBJ_NONE	(0)
	#endif
	#ifndef   OBJ_NEW
	  #define OBJ_NEW	(1)
	#endif
	#ifndef   OBJ_NOT_MEASURED
	  #define OBJ_NOT_MEASURED	(2)
	#endif
	#ifndef   OBJ_CONFIRMED_MEASURED
	  #define OBJ_CONFIRMED_MEASURED	(3)
	#endif

/* typedef eCDHypothesisType_t */
	#ifndef   CDHypothesisType_No
	  #define CDHypothesisType_No	(0)
	#endif
	#ifndef   CDHypothesisType_RunUp
	  #define CDHypothesisType_RunUp	(1)
	#endif
	#ifndef   CDHypothesisType_RunUpBraking
	  #define CDHypothesisType_RunUpBraking	(2)
	#endif
	#ifndef   CDHypothesisType_RunUpStationary
	  #define CDHypothesisType_RunUpStationary	(3)
	#endif
	#ifndef   CDHypothesisType_Static
	  #define CDHypothesisType_Static	(4)
	#endif
	#ifndef   CDHypothesisType_ACC
	  #define CDHypothesisType_ACC	(5)
	#endif
	#ifndef   CDHypothesisType_Pass
	  #define CDHypothesisType_Pass	(6)
	#endif
	#ifndef   CDHypothesisType_CutIn
	  #define CDHypothesisType_CutIn	(7)
	#endif
	#ifndef   CDHypothesisType_Collision
	  #define CDHypothesisType_Collision	(8)
	#endif
	#ifndef   CDHypothesisType_CollisionUnavoidable
	  #define CDHypothesisType_CollisionUnavoidable	(9)
	#endif
	#ifndef   CDHypothesisType_PedCollision
	  #define CDHypothesisType_PedCollision	(10)
	#endif
	#ifndef   CDHypothesisType_PedPass
	  #define CDHypothesisType_PedPass	(11)
	#endif
	#ifndef   CDHypothesisType_Crossing
	  #define CDHypothesisType_Crossing	(12)
	#endif
	#ifndef   CDHypothesisType_CyclColl
	  #define CDHypothesisType_CyclColl	(13)
	#endif

/* typedef eEBAObjectClass_t */
	#ifndef   EBAObjectClass_NotAvail
	  #define EBAObjectClass_NotAvail	(0)
	#endif
	#ifndef   EBAObjectClass_Pedestrian
	  #define EBAObjectClass_Pedestrian	(1)
	#endif
	#ifndef   EBAObjectClass_Vehicle
	  #define EBAObjectClass_Vehicle	(2)
	#endif
	#ifndef   EBAObjectClass_Obstacle
	  #define EBAObjectClass_Obstacle	(3)
	#endif
	#ifndef   EBAObjectClass_Cyclist
	  #define EBAObjectClass_Cyclist	(4)
	#endif

/* typedef eEBADynProp_t */
	#ifndef   EBADynProp_NotAvail
	  #define EBADynProp_NotAvail	(0)
	#endif
	#ifndef   EBADynProp_Mov
	  #define EBADynProp_Mov	(1)
	#endif
	#ifndef   EBADynProp_Stat
	  #define EBADynProp_Stat	(2)
	#endif

/* typedef eEBAObjMovDir_t */
	#ifndef   EBAObjMovDir_DoT
	  #define EBAObjMovDir_DoT	(0)
	#endif
	#ifndef   EBAObjMovDir_Cross
	  #define EBAObjMovDir_Cross	(1)
	#endif
	#ifndef   EBAObjMovDir_Onco
	  #define EBAObjMovDir_Onco	(2)
	#endif

/* typedef eDriverSetting_t */
	#ifndef   eDriverSetting_Early
	  #define eDriverSetting_Early	(0)
	#endif
	#ifndef   eDriverSetting_Middle
	  #define eDriverSetting_Middle	(1)
	#endif
	#ifndef   eDriverSetting_Late
	  #define eDriverSetting_Late	(2)
	#endif
	#ifndef   eDriverSetting_Invalid
	  #define eDriverSetting_Invalid	(3)
	#endif

/* typedef DIMInputSignalState_t */
	#ifndef   DIMInputSignalState_OK
	  #define DIMInputSignalState_OK	(0)
	#endif
	#ifndef   DIMInputSignalState_Default
	  #define DIMInputSignalState_Default	(1)
	#endif
	#ifndef   DIMInputSignalState_Missing
	  #define DIMInputSignalState_Missing	(2)
	#endif
	#ifndef   DIMInputSignalState_BadQuality
	  #define DIMInputSignalState_BadQuality	(3)
	#endif
	#ifndef   DIMInputSignalState_Suspicious
	  #define DIMInputSignalState_Suspicious	(4)
	#endif
	#ifndef   DIMInputSignalState_Max
	  #define DIMInputSignalState_Max	(5)
	#endif

/* typedef eTurnIndicator_t */
	#ifndef   eTurnIndicator_Off
	  #define eTurnIndicator_Off	(0)
	#endif
	#ifndef   eTurnIndicator_Left
	  #define eTurnIndicator_Left	(1)
	#endif
	#ifndef   eTurnIndicator_Right
	  #define eTurnIndicator_Right	(2)
	#endif
	#ifndef   eTurnIndicator_Both
	  #define eTurnIndicator_Both	(3)
	#endif
	#ifndef   eTurnIndicator_Invalid
	  #define eTurnIndicator_Invalid	(4)
	#endif

/* typedef ePowerTrainEngaged_t */
	#ifndef   ePowerTrain_Engaged
	  #define ePowerTrain_Engaged	(0)
	#endif
	#ifndef   ePowerTrain_Disengaged
	  #define ePowerTrain_Disengaged	(1)
	#endif
	#ifndef   ePowerTrain_Invalid
	  #define ePowerTrain_Invalid	(2)
	#endif

/* typedef eMainSwitch_t */
	#ifndef   eMainSwitch_Active
	  #define eMainSwitch_Active	(0)
	#endif
	#ifndef   eMainSwitch_Inactive
	  #define eMainSwitch_Inactive	(1)
	#endif
	#ifndef   eMainSwitch_NotUsed
	  #define eMainSwitch_NotUsed	(2)
	#endif
	#ifndef   eMainSwitch_Invalid
	  #define eMainSwitch_Invalid	(3)
	#endif

/* typedef eFunctionSwitch_t */
	#ifndef   eEBASwitch_LongVehDW
	  #define eEBASwitch_LongVehDW	(1)
	#endif
	#ifndef   eEBASwitch_LongVehFCW1
	  #define eEBASwitch_LongVehFCW1	(2)
	#endif
	#ifndef   eEBASwitch_LongVehFCW2
	  #define eEBASwitch_LongVehFCW2	(4)
	#endif
	#ifndef   eEBASwitch_LongVehFCW3
	  #define eEBASwitch_LongVehFCW3	(8)
	#endif
	#ifndef   eEBASwitch_LongVehBRK
	  #define eEBASwitch_LongVehBRK	(16)
	#endif
	#ifndef   eEBASwitch_LongVruDW
	  #define eEBASwitch_LongVruDW	(32)
	#endif
	#ifndef   eEBASwitch_LongVruFCW1
	  #define eEBASwitch_LongVruFCW1	(64)
	#endif
	#ifndef   eEBASwitch_LongVruFCW2
	  #define eEBASwitch_LongVruFCW2	(128)
	#endif
	#ifndef   eEBASwitch_LongVruFCW3
	  #define eEBASwitch_LongVruFCW3	(256)
	#endif
	#ifndef   eEBASwitch_LongVruBRK
	  #define eEBASwitch_LongVruBRK	(512)
	#endif
	#ifndef   eEBASwitch_CrossVehDW
	  #define eEBASwitch_CrossVehDW	(1024)
	#endif
	#ifndef   eEBASwitch_CrossVehFCW1
	  #define eEBASwitch_CrossVehFCW1	(2048)
	#endif
	#ifndef   eEBASwitch_CrossVehFCW2
	  #define eEBASwitch_CrossVehFCW2	(4096)
	#endif
	#ifndef   eEBASwitch_CrossVehFCW3
	  #define eEBASwitch_CrossVehFCW3	(8192)
	#endif
	#ifndef   eEBASwitch_CrossVehBRK
	  #define eEBASwitch_CrossVehBRK	(16384)
	#endif
	#ifndef   eEBASwitch_CrossVruDW
	  #define eEBASwitch_CrossVruDW	(32768)
	#endif
	#ifndef   eEBASwitch_CrossVruFCW1
	  #define eEBASwitch_CrossVruFCW1	(65536)
	#endif
	#ifndef   eEBASwitch_CrossVruFCW2
	  #define eEBASwitch_CrossVruFCW2	(131072)
	#endif
	#ifndef   eEBASwitch_CrossVruFCW3
	  #define eEBASwitch_CrossVruFCW3	(262144)
	#endif
	#ifndef   eEBASwitch_CrossVruBRK
	  #define eEBASwitch_CrossVruBRK	(524288)
	#endif
	#ifndef   eEBASwitch_OncVehDW
	  #define eEBASwitch_OncVehDW	(1048576)
	#endif
	#ifndef   eEBASwitch_OncVehFCW1
	  #define eEBASwitch_OncVehFCW1	(2097152)
	#endif
	#ifndef   eEBASwitch_OncVehFCW2
	  #define eEBASwitch_OncVehFCW2	(4194304)
	#endif
	#ifndef   eEBASwitch_OncVehFCW3
	  #define eEBASwitch_OncVehFCW3	(8388608)
	#endif
	#ifndef   eEBASwitch_OncVehBRK
	  #define eEBASwitch_OncVehBRK	(16777216)
	#endif
	#ifndef   eEBASwitch_OncVruDW
	  #define eEBASwitch_OncVruDW	(33554432)
	#endif
	#ifndef   eEBASwitch_OncVruFCW1
	  #define eEBASwitch_OncVruFCW1	(67108864)
	#endif
	#ifndef   eEBASwitch_OncVruFCW2
	  #define eEBASwitch_OncVruFCW2	(134217728)
	#endif
	#ifndef   eEBASwitch_OncVruFCW3
	  #define eEBASwitch_OncVruFCW3	(268435456)
	#endif
	#ifndef   eEBASwitch_OncVruBRK
	  #define eEBASwitch_OncVruBRK	(536870912)
	#endif
	#ifndef   eEBASwitch_MaxValue
	  #define eEBASwitch_MaxValue	(2147483648)
	#endif

/* typedef FCTSubChainQualifier_t */
	#ifndef   eSystemOn
	  #define eSystemOn	(0)
	#endif
	#ifndef   eSystemOff
	  #define eSystemOff	(1)
	#endif

/* typedef eEBAFctChan_t */
	#ifndef   eEBAFctChan_Unknown
	  #define eEBAFctChan_Unknown	(0)
	#endif
	#ifndef   eEBAFctChan_Vehicle
	  #define eEBAFctChan_Vehicle	(1)
	#endif
	#ifndef   eEBAFctChan_Pedestrian
	  #define eEBAFctChan_Pedestrian	(2)
	#endif
	#ifndef   eEBAFctChan_Unclassified
	  #define eEBAFctChan_Unclassified	(4)
	#endif
	#ifndef   eEBAFctChan_Crossing
	  #define eEBAFctChan_Crossing	(8)
	#endif
	#ifndef   eEBAFctChan_Cyclist
	  #define eEBAFctChan_Cyclist	(16)
	#endif

/* typedef eGeneratorControl_t */
	#ifndef   eEBAGenerator_No
	  #define eEBAGenerator_No	(0)
	#endif
	#ifndef   eEBAGenerator_KeepVoltage
	  #define eEBAGenerator_KeepVoltage	(1)
	#endif
	#ifndef   eEBAGenerator_BoostVoltage
	  #define eEBAGenerator_BoostVoltage	(2)
	#endif

/* typedef eEBASignalState_t */
	#ifndef   eEBAOn_Inactive
	  #define eEBAOn_Inactive	(0)
	#endif
	#ifndef   eEBAOn_Moving
	  #define eEBAOn_Moving	(1)
	#endif
	#ifndef   eEBAOn_Standing
	  #define eEBAOn_Standing	(2)
	#endif
	#ifndef   eEBAOn_Halted
	  #define eEBAOn_Halted	(3)
	#endif
	#ifndef   eEBAOn_CrossFrLeft
	  #define eEBAOn_CrossFrLeft	(4)
	#endif
	#ifndef   eEBAOn_CrossFrRight
	  #define eEBAOn_CrossFrRight	(5)
	#endif

/* typedef eEBARelObjQualifier_t */
	#ifndef   eEBAObjRelNo
	  #define eEBAObjRelNo	(0)
	#endif
	#ifndef   eEBAObjRelHyp
	  #define eEBAObjRelHyp	(1)
	#endif
	#ifndef   eEBAObjRelFctMod
	  #define eEBAObjRelFctMod	(2)
	#endif

/* typedef eFunctionQualifier_t */
	#ifndef   eStatus_FCW_Coded
	  #define eStatus_FCW_Coded	(1)
	#endif
	#ifndef   eStatus_FCW_Switched
	  #define eStatus_FCW_Switched	(2)
	#endif
	#ifndef   eStatus_FCW_NoError
	  #define eStatus_FCW_NoError	(4)
	#endif
	#ifndef   eStatus_FCW_NoDegraded
	  #define eStatus_FCW_NoDegraded	(8)
	#endif
	#ifndef   eStatus_AutoBrk_Coded
	  #define eStatus_AutoBrk_Coded	(16)
	#endif
	#ifndef   eStatus_AutoBrk_Switched
	  #define eStatus_AutoBrk_Switched	(32)
	#endif
	#ifndef   eStatus_AutoBrk_NoError
	  #define eStatus_AutoBrk_NoError	(64)
	#endif
	#ifndef   eStatus_AutoBrk_NoDegraded
	  #define eStatus_AutoBrk_NoDegraded	(128)
	#endif
	#ifndef   eStatus_DistWarn_Coded
	  #define eStatus_DistWarn_Coded	(256)
	#endif
	#ifndef   eStatus_DistWarn_Switched
	  #define eStatus_DistWarn_Switched	(512)
	#endif
	#ifndef   eStatus_DistWarn_NoError
	  #define eStatus_DistWarn_NoError	(1024)
	#endif
	#ifndef   eStatus_DistWarn_NoDegraded
	  #define eStatus_DistWarn_NoDegraded	(2048)
	#endif
	#ifndef   eStatus_BrakeAssist_Coded
	  #define eStatus_BrakeAssist_Coded	(4096)
	#endif
	#ifndef   eStatus_BrakeAssist_Switched
	  #define eStatus_BrakeAssist_Switched	(8192)
	#endif
	#ifndef   eStatus_BrakeAssist_NoError
	  #define eStatus_BrakeAssist_NoError	(16384)
	#endif
	#ifndef   eStatus_BrakeAssist_NoDegraded
	  #define eStatus_BrakeAssist_NoDegraded	(32768)
	#endif
	#ifndef   eStatus_BrakePreCond_Coded
	  #define eStatus_BrakePreCond_Coded	(65536)
	#endif
	#ifndef   eStatus_BrakePreCond_Switched
	  #define eStatus_BrakePreCond_Switched	(131072)
	#endif
	#ifndef   eStatus_BrakePreCond_NoError
	  #define eStatus_BrakePreCond_NoError	(262144)
	#endif
	#ifndef   eStatus_BrakePreCond_NoDegraded
	  #define eStatus_BrakePreCond_NoDegraded	(524288)
	#endif
	#ifndef   eStatus_OccSafety_Coded
	  #define eStatus_OccSafety_Coded	(1048576)
	#endif
	#ifndef   eStatus_OccSafety_Switched
	  #define eStatus_OccSafety_Switched	(2097152)
	#endif
	#ifndef   eStatus_OccSafety_NoError
	  #define eStatus_OccSafety_NoError	(4194304)
	#endif
	#ifndef   eStatus_OccSafety_NoDegraded
	  #define eStatus_OccSafety_NoDegraded	(8388608)
	#endif
	#ifndef   eStatus_Spare1_Coded
	  #define eStatus_Spare1_Coded	(16777216)
	#endif
	#ifndef   eStatus_Spare1_Switched
	  #define eStatus_Spare1_Switched	(33554432)
	#endif
	#ifndef   eStatus_Spare1_NoError
	  #define eStatus_Spare1_NoError	(67108864)
	#endif
	#ifndef   eStatus_Spare1_NoDegraded
	  #define eStatus_Spare1_NoDegraded	(134217728)
	#endif
	#ifndef   eStatus_Spare2_Coded
	  #define eStatus_Spare2_Coded	(268435456)
	#endif
	#ifndef   eStatus_Spare2_Switched
	  #define eStatus_Spare2_Switched	(536870912)
	#endif
	#ifndef   eStatus_Spare2_NoError
	  #define eStatus_Spare2_NoError	(1073741824)
	#endif
	#ifndef   eStatus_Spare2_NoDegraded
	  #define eStatus_Spare2_NoDegraded	(2147483648)
	#endif

/* typedef DIMOutMonState_t */
	#ifndef   eDimMonState_NotPossible
	  #define eDimMonState_NotPossible	(0)
	#endif
	#ifndef   eDimMonState_Limited
	  #define eDimMonState_Limited	(1)
	#endif
	#ifndef   eDimMonState_Unlimited
	  #define eDimMonState_Unlimited	(2)
	#endif

/* typedef eDriverAttentionState_t */
	#ifndef   eDriverAttentionState_Unknown
	  #define eDriverAttentionState_Unknown	(0)
	#endif
	#ifndef   eDriverAttentionState_Low
	  #define eDriverAttentionState_Low	(1)
	#endif
	#ifndef   eDriverAttentionState_High
	  #define eDriverAttentionState_High	(2)
	#endif
	#ifndef   eDriverAttentionState_Higher
	  #define eDriverAttentionState_Higher	(3)
	#endif
	#ifndef   eDriverAttentionState_VeryHigh
	  #define eDriverAttentionState_VeryHigh	(4)
	#endif
	#ifndef   eDriverAttentionState_Unattended
	  #define eDriverAttentionState_Unattended	(5)
	#endif

/* typedef eDriverFeedbackState_t */
	#ifndef   eDriverFeedbackState_Negative
	  #define eDriverFeedbackState_Negative	(0)
	#endif
	#ifndef   eDriverFeedbackState_WeakNegative
	  #define eDriverFeedbackState_WeakNegative	(1)
	#endif
	#ifndef   eDriverFeedbackState_NoNegative
	  #define eDriverFeedbackState_NoNegative	(2)
	#endif
	#ifndef   eDriverFeedbackState_NoPositive
	  #define eDriverFeedbackState_NoPositive	(3)
	#endif
	#ifndef   eDriverFeedbackState_WeakPositive
	  #define eDriverFeedbackState_WeakPositive	(4)
	#endif
	#ifndef   eDriverFeedbackState_Positive
	  #define eDriverFeedbackState_Positive	(5)
	#endif
	#ifndef   eDriverFeedbackState_StrongPositive
	  #define eDriverFeedbackState_StrongPositive	(6)
	#endif

/* typedef eDriverActivityState_t */
	#ifndef   eDriverActivity_Inactive
	  #define eDriverActivity_Inactive	(0)
	#endif
	#ifndef   eDriverActivity_MissingConf
	  #define eDriverActivity_MissingConf	(1)
	#endif
	#ifndef   eDriverActivity_VeryActive
	  #define eDriverActivity_VeryActive	(2)
	#endif
	#ifndef   eDriverActivity_EmergencySteer
	  #define eDriverActivity_EmergencySteer	(3)
	#endif

/* typedef E_FCTIF_ALDWStatus_t */
	#ifndef   e_FCTIF_ALDW_STATUS_OFF
	  #define e_FCTIF_ALDW_STATUS_OFF	(0)
	#endif
	#ifndef   e_FCTIF_ALDW_STATUS_ON_INACTIVE
	  #define e_FCTIF_ALDW_STATUS_ON_INACTIVE	(1)
	#endif
	#ifndef   e_FCTIF_ALDW_STATUS_ON_ACTIVE
	  #define e_FCTIF_ALDW_STATUS_ON_ACTIVE	(2)
	#endif

/* typedef E_FCTIF_ALDWWrnRq_t */
	#ifndef   e_FCTIF_ALDW_WARN_IDLE
	  #define e_FCTIF_ALDW_WARN_IDLE	(0)
	#endif
	#ifndef   e_FCTIF_ALDW_WARN_LT
	  #define e_FCTIF_ALDW_WARN_LT	(1)
	#endif
	#ifndef   e_FCTIF_ALDW_WARN_RT
	  #define e_FCTIF_ALDW_WARN_RT	(2)
	#endif

/* typedef E_FCTIF_ALDWWarnSuppStat_t */
	#ifndef   e_FCTIF_ALDW_WARN_RDY
	  #define e_FCTIF_ALDW_WARN_RDY	(0)
	#endif
	#ifndef   e_FCTIF_ALDW_OFF_SPD
	  #define e_FCTIF_ALDW_OFF_SPD	(1)
	#endif
	#ifndef   e_FCTIF_ALDW_DRV_ACTV
	  #define e_FCTIF_ALDW_DRV_ACTV	(2)
	#endif
	#ifndef   e_FCTIF_ALDW_DRV_ACTV_DELAY
	  #define e_FCTIF_ALDW_DRV_ACTV_DELAY	(3)
	#endif
	#ifndef   e_FCTIF_ALDW_DRV_DISTRACTION
	  #define e_FCTIF_ALDW_DRV_DISTRACTION	(4)
	#endif
	#ifndef   e_FCTIF_ALDW_TURN
	  #define e_FCTIF_ALDW_TURN	(5)
	#endif
	#ifndef   e_FCTIF_ALDW_TURN_DELAY
	  #define e_FCTIF_ALDW_TURN_DELAY	(6)
	#endif
	#ifndef   e_FCTIF_ALDW_WARN
	  #define e_FCTIF_ALDW_WARN	(7)
	#endif
	#ifndef   e_FCTIF_ALDW_WARN_DELAY
	  #define e_FCTIF_ALDW_WARN_DELAY	(8)
	#endif
	#ifndef   e_FCTIF_ALDW_SYS_ACTIV
	  #define e_FCTIF_ALDW_SYS_ACTIV	(9)
	#endif

/* typedef eLKSOperationStatus_t */
	#ifndef   eOperationStatus_MIN
	  #define eOperationStatus_MIN	(0)
	#endif
	#ifndef   eOperationStatus_NotInSpeedRange
	  #define eOperationStatus_NotInSpeedRange	(1)
	#endif
	#ifndef   eOperationStatus_NotInLatAccRange
	  #define eOperationStatus_NotInLatAccRange	(2)
	#endif
	#ifndef   eOperationStatus_NotInLongAccRange
	  #define eOperationStatus_NotInLongAccRange	(4)
	#endif
	#ifndef   eOperationStatus_NotInSteerAngRange
	  #define eOperationStatus_NotInSteerAngRange	(8)
	#endif
	#ifndef   eOperationStatus_NotInSteerAngVelRange
	  #define eOperationStatus_NotInSteerAngVelRange	(16)
	#endif
	#ifndef   eOperationStatus_InvalidLaneWidth
	  #define eOperationStatus_InvalidLaneWidth	(32)
	#endif
	#ifndef   eOperationStatus_LaneChange
	  #define eOperationStatus_LaneChange	(64)
	#endif
	#ifndef   eOperationStatus_InvalidGearPos
	  #define eOperationStatus_InvalidGearPos	(128)
	#endif
	#ifndef   eOperationStatus_ChasCtrlOff
	  #define eOperationStatus_ChasCtrlOff	(256)
	#endif
	#ifndef   eOperationStatus_ChasCtrlActive
	  #define eOperationStatus_ChasCtrlActive	(512)
	#endif
	#ifndef   eOperationStatus_DrvHandsOff
	  #define eOperationStatus_DrvHandsOff	(1024)
	#endif
	#ifndef   eOperationStatus_DrvHandsOffL2
	  #define eOperationStatus_DrvHandsOffL2	(2048)
	#endif
	#ifndef   eOperationStatus_DrvSteering
	  #define eOperationStatus_DrvSteering	(4096)
	#endif
	#ifndef   eOperationStatus_BrakePedalAct
	  #define eOperationStatus_BrakePedalAct	(8192)
	#endif
	#ifndef   eOperationStatus_AccelPedalAct
	  #define eOperationStatus_AccelPedalAct	(16384)
	#endif
	#ifndef   eOperationStatus_MAX
	  #define eOperationStatus_MAX	(32768)
	#endif

/* typedef eLKSSuppressionStatus_t */
	#ifndef   eSuppressionStatus_MIN
	  #define eSuppressionStatus_MIN	(0)
	#endif
	#ifndef   eSuppressionStatus_TurnSignal
	  #define eSuppressionStatus_TurnSignal	(1)
	#endif
	#ifndef   eSuppressionStatus_InvalidLane
	  #define eSuppressionStatus_InvalidLane	(2)
	#endif
	#ifndef   eSuppressionStatus_InLaneReset
	  #define eSuppressionStatus_InLaneReset	(4)
	#endif
	#ifndef   eSuppressionStatus_WaitingTime
	  #define eSuppressionStatus_WaitingTime	(8)
	#endif
	#ifndef   eSuppressionStatus_InProhibitedArea
	  #define eSuppressionStatus_InProhibitedArea	(16)
	#endif
	#ifndef   eSuppressionStatus_MAX
	  #define eSuppressionStatus_MAX	(32768)
	#endif

/* typedef eLKSCompleteStatus_t */
	#ifndef   eCompleteStatus_MIN
	  #define eCompleteStatus_MIN	(0)
	#endif
	#ifndef   eCompleteStatus_MaxLastingTime
	  #define eCompleteStatus_MaxLastingTime	(1)
	#endif
	#ifndef   eCompleteStatus_MaxDeviation
	  #define eCompleteStatus_MaxDeviation	(2)
	#endif
	#ifndef   eCompleteStatus_TurnSignal
	  #define eCompleteStatus_TurnSignal	(4)
	#endif
	#ifndef   eCompleteStatus_InvalidLane
	  #define eCompleteStatus_InvalidLane	(8)
	#endif
	#ifndef   eCompleteStatus_InFinishPosition
	  #define eCompleteStatus_InFinishPosition	(16)
	#endif
	#ifndef   eCompleteStatus_MAX
	  #define eCompleteStatus_MAX	(32768)
	#endif

/* typedef eLKSStatus_t */
	#ifndef   LKS_STATUS_OFF
	  #define LKS_STATUS_OFF	(0)
	#endif
	#ifndef   LKS_STATUS_INACTIVE
	  #define LKS_STATUS_INACTIVE	(1)
	#endif
	#ifndef   LKS_STATUS_READY
	  #define LKS_STATUS_READY	(2)
	#endif
	#ifndef   LKS_STATUS_ACTION_LEFT
	  #define LKS_STATUS_ACTION_LEFT	(3)
	#endif
	#ifndef   LKS_STATUS_ACTION_RIGHT
	  #define LKS_STATUS_ACTION_RIGHT	(4)
	#endif

/* typedef eLkaAldwMode_t */
	#ifndef   Lka_aldw_mode_off
	  #define Lka_aldw_mode_off	(0)
	#endif
	#ifndef   Lka_aldw_mode_ldw
	  #define Lka_aldw_mode_ldw	(1)
	#endif
	#ifndef   Lka_aldw_mode_aldw_light
	  #define Lka_aldw_mode_aldw_light	(2)
	#endif
	#ifndef   Lka_aldw_mode_aldw
	  #define Lka_aldw_mode_aldw	(3)
	#endif

/* typedef eLDWSwitch_t */
	#ifndef   LKS_LDW_MAIN_SWITCH_OFF
	  #define LKS_LDW_MAIN_SWITCH_OFF	(0)
	#endif
	#ifndef   LKS_LDW_MAIN_SWITCH_ON
	  #define LKS_LDW_MAIN_SWITCH_ON	(1)
	#endif

/* typedef eLDPSwitch_t */
	#ifndef   LKS_LDP_MAIN_SWITCH_OFF
	  #define LKS_LDP_MAIN_SWITCH_OFF	(0)
	#endif
	#ifndef   LKS_LDP_MAIN_SWITCH_ON
	  #define LKS_LDP_MAIN_SWITCH_ON	(1)
	#endif

/* typedef eLKASwitch_t */
	#ifndef   LKS_LKA_MAIN_SWITCH_OFF
	  #define LKS_LKA_MAIN_SWITCH_OFF	(0)
	#endif
	#ifndef   LKS_LKA_MAIN_SWITCH_ON
	  #define LKS_LKA_MAIN_SWITCH_ON	(1)
	#endif

/* typedef eLKSSensitivity_t */
	#ifndef   LKS_SENSITIVITY_LATE
	  #define LKS_SENSITIVITY_LATE	(0)
	#endif
	#ifndef   LKS_SENSITIVITY_EARLY
	  #define LKS_SENSITIVITY_EARLY	(1)
	#endif

/* typedef eLKSTurnSignal_t */
	#ifndef   LKS_TURN_SIGNAL_OFF
	  #define LKS_TURN_SIGNAL_OFF	(0)
	#endif
	#ifndef   LKS_TURN_SIGNAL_LEFT
	  #define LKS_TURN_SIGNAL_LEFT	(1)
	#endif
	#ifndef   LKS_TURN_SIGNAL_RIGHT
	  #define LKS_TURN_SIGNAL_RIGHT	(2)
	#endif

/* typedef t_MarkerType */
	#ifndef   CL_MARKER_TYPE_CONTINUOUS
	  #define CL_MARKER_TYPE_CONTINUOUS	(0)
	#endif
	#ifndef   CL_MARKER_TYPE_DASHED
	  #define CL_MARKER_TYPE_DASHED	(1)
	#endif
	#ifndef   CL_MARKER_TYPE_RESERVED1
	  #define CL_MARKER_TYPE_RESERVED1	(2)
	#endif
	#ifndef   CL_MARKER_TYPE_RESERVED2
	  #define CL_MARKER_TYPE_RESERVED2	(3)
	#endif
	#ifndef   CL_MARKER_TYPE_NOLINEDETECTED
	  #define CL_MARKER_TYPE_NOLINEDETECTED	(4)
	#endif
	#ifndef   CL_MARKER_TYPE_UNCLASSIFIED
	  #define CL_MARKER_TYPE_UNCLASSIFIED	(5)
	#endif
	#ifndef   CL_MARKER_TYPE_DOTTED
	  #define CL_MARKER_TYPE_DOTTED	(6)
	#endif
	#ifndef   CL_MARKER_TYPE_DECORATION
	  #define CL_MARKER_TYPE_DECORATION	(7)
	#endif
	#ifndef   CL_MARKER_TYPE_SEPARATING
	  #define CL_MARKER_TYPE_SEPARATING	(8)
	#endif
	#ifndef   CL_MARKER_TYPE_NARROWDASHED
	  #define CL_MARKER_TYPE_NARROWDASHED	(9)
	#endif
	#ifndef   CL_MARKER_TYPE_LOWCURB
	  #define CL_MARKER_TYPE_LOWCURB	(10)
	#endif
	#ifndef   CL_MARKER_TYPE_HIGHCURB
	  #define CL_MARKER_TYPE_HIGHCURB	(11)
	#endif
	#ifndef   CL_MARKER_TYPE_CRASHBARRIER
	  #define CL_MARKER_TYPE_CRASHBARRIER	(12)
	#endif
	#ifndef   CL_MARKER_TYPE_WALL
	  #define CL_MARKER_TYPE_WALL	(13)
	#endif
	#ifndef   CL_MARKER_TYPE_ROADSHOULDER
	  #define CL_MARKER_TYPE_ROADSHOULDER	(14)
	#endif
	#ifndef   CL_MARKER_TYPE_SNA
	  #define CL_MARKER_TYPE_SNA	(15)
	#endif
	#ifndef   CL_MARKER_TYPE_GRASS
	  #define CL_MARKER_TYPE_GRASS	(16)
	#endif
	#ifndef   CL_MARKER_TYPE_MISCELLANEOUS
	  #define CL_MARKER_TYPE_MISCELLANEOUS	(17)
	#endif

/* typedef t_CamLaneMarkerEnum */
	#ifndef   CL_CAM_LANE_MK_ADJ_LEFT
	  #define CL_CAM_LANE_MK_ADJ_LEFT	(0)
	#endif
	#ifndef   CL_CAM_LANE_MK_LEFT
	  #define CL_CAM_LANE_MK_LEFT	(1)
	#endif
	#ifndef   CL_CAM_LANE_MK_RIGHT
	  #define CL_CAM_LANE_MK_RIGHT	(2)
	#endif
	#ifndef   CL_CAM_LANE_MK_ADJ_RIGHT
	  #define CL_CAM_LANE_MK_ADJ_RIGHT	(3)
	#endif

/* typedef EBACodingParamGen_t */
	#ifndef   EBA_CODING_GEN_LOW_SPEED
	  #define EBA_CODING_GEN_LOW_SPEED	(1)
	#endif
	#ifndef   EBA_CODING_GEN_COUNTRY_A
	  #define EBA_CODING_GEN_COUNTRY_A	(2)
	#endif
	#ifndef   EBA_CODING_GEN_COUNTRY_B
	  #define EBA_CODING_GEN_COUNTRY_B	(4)
	#endif
	#ifndef   EBA_CODING_GEN_IGNR_SFTY_CHCKS
	  #define EBA_CODING_GEN_IGNR_SFTY_CHCKS	(8)
	#endif
	#ifndef   EBA_CODING_GEN_DEBUGMESSAGES
	  #define EBA_CODING_GEN_DEBUGMESSAGES	(16)
	#endif
	#ifndef   EBA_CODING_GEN_DISTANCELIMIT
	  #define EBA_CODING_GEN_DISTANCELIMIT	(32)
	#endif
	#ifndef   EBA_CODING_GEN_DRIVER_SET_CODING
	  #define EBA_CODING_GEN_DRIVER_SET_CODING	(64)
	#endif
	#ifndef   EBA_CODING_GEN_IGNORE_ACT_SWITCH
	  #define EBA_CODING_GEN_IGNORE_ACT_SWITCH	(128)
	#endif
	#ifndef   EBA_CODING_GEN_MAX_VALUE
	  #define EBA_CODING_GEN_MAX_VALUE	(4294967295)
	#endif

/* typedef CPAREBACodingFctMods_t */
	#ifndef   EBA_CODING_BIT_PRECRASH
	  #define EBA_CODING_BIT_PRECRASH	(1)
	#endif
	#ifndef   EBA_CODING_BIT_PREFILL1
	  #define EBA_CODING_BIT_PREFILL1	(2)
	#endif
	#ifndef   EBA_CODING_BIT_PREFILL2
	  #define EBA_CODING_BIT_PREFILL2	(4)
	#endif
	#ifndef   EBA_CODING_BIT_HBA1
	  #define EBA_CODING_BIT_HBA1	(8)
	#endif
	#ifndef   EBA_CODING_BIT_HBA2
	  #define EBA_CODING_BIT_HBA2	(16)
	#endif
	#ifndef   EBA_CODING_BIT_AUTOBRK1
	  #define EBA_CODING_BIT_AUTOBRK1	(32)
	#endif
	#ifndef   EBA_CODING_BIT_AUTOBRK2
	  #define EBA_CODING_BIT_AUTOBRK2	(64)
	#endif
	#ifndef   EBA_CODING_BIT_AUTOBRK3
	  #define EBA_CODING_BIT_AUTOBRK3	(128)
	#endif
	#ifndef   EBA_CODING_BIT_DYN_WARN1
	  #define EBA_CODING_BIT_DYN_WARN1	(256)
	#endif
	#ifndef   EBA_CODING_BIT_DYN_WARN2
	  #define EBA_CODING_BIT_DYN_WARN2	(512)
	#endif
	#ifndef   EBA_CODING_BIT_DYN_WARN3
	  #define EBA_CODING_BIT_DYN_WARN3	(1024)
	#endif
	#ifndef   EBA_CODING_BIT_DIST_WARN1
	  #define EBA_CODING_BIT_DIST_WARN1	(2048)
	#endif
	#ifndef   EBA_CODING_BIT_DIST_WARN2
	  #define EBA_CODING_BIT_DIST_WARN2	(4096)
	#endif
	#ifndef   EBA_CODING_BIT_SPARE1
	  #define EBA_CODING_BIT_SPARE1	(8192)
	#endif
	#ifndef   EBA_CODING_BIT_SPARE2
	  #define EBA_CODING_BIT_SPARE2	(16384)
	#endif
	#ifndef   EBA_CODING_BIT_SPARE3
	  #define EBA_CODING_BIT_SPARE3	(32768)
	#endif

/* typedef EBACodingParamCustom_t */
	#ifndef   EBA_CODING_BIT_CUSTOM1
	  #define EBA_CODING_BIT_CUSTOM1	(1)
	#endif
	#ifndef   EBA_CODING_BIT_CUSTOM2
	  #define EBA_CODING_BIT_CUSTOM2	(2)
	#endif
	#ifndef   EBA_CODING_BIT_CUSTOM3
	  #define EBA_CODING_BIT_CUSTOM3	(4)
	#endif
	#ifndef   EBA_CODING_BIT_CUSTOM4
	  #define EBA_CODING_BIT_CUSTOM4	(8)
	#endif
	#ifndef   EBA_CODING_BIT_CUSTOM5
	  #define EBA_CODING_BIT_CUSTOM5	(16)
	#endif
	#ifndef   EBA_CODING_BIT_CUSTOM6
	  #define EBA_CODING_BIT_CUSTOM6	(32)
	#endif
	#ifndef   EBA_CODING_BIT_CUSTOM7
	  #define EBA_CODING_BIT_CUSTOM7	(64)
	#endif
	#ifndef   EBA_CODING_BIT_CUSTOM8
	  #define EBA_CODING_BIT_CUSTOM8	(128)
	#endif

/* typedef LKSCodingParamGen_t */
	#ifndef   LKS_CODING_GEN_COUNTRY_A
	  #define LKS_CODING_GEN_COUNTRY_A	(1)
	#endif
	#ifndef   LKS_CODING_GEN_COUNTRY_B
	  #define LKS_CODING_GEN_COUNTRY_B	(2)
	#endif
	#ifndef   LKS_CODING_GEN_COUNTRY_C
	  #define LKS_CODING_GEN_COUNTRY_C	(4)
	#endif
	#ifndef   LKS_CODING_GEN_IGNORE_SFTY_CHCKS
	  #define LKS_CODING_GEN_IGNORE_SFTY_CHCKS	(8)
	#endif
	#ifndef   LKS_CODING_GEN_IGNORE_ACT_SWITCH
	  #define LKS_CODING_GEN_IGNORE_ACT_SWITCH	(16)
	#endif
	#ifndef   LKS_CODING_GEN_MAX_VALUE
	  #define LKS_CODING_GEN_MAX_VALUE	(4294967295)
	#endif

/* typedef RTE_HLA_TestMode */
	#ifndef   RTE_HLA_TESTMODE_UNKNOWN
	  #define RTE_HLA_TESTMODE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_TESTMODE_INACTIVE
	  #define RTE_HLA_TESTMODE_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_TESTMODE_SAE
	  #define RTE_HLA_TESTMODE_SAE	(2)
	#endif
	#ifndef   RTE_HLA_TESTMODE_ECE
	  #define RTE_HLA_TESTMODE_ECE	(3)
	#endif
	#ifndef   RTE_HLA_TESTMODE_SEG_ALWAYS_ON
	  #define RTE_HLA_TESTMODE_SEG_ALWAYS_ON	(4)
	#endif
	#ifndef   RTE_HLA_TESTMODE_NO_CLEARMEAS
	  #define RTE_HLA_TESTMODE_NO_CLEARMEAS	(5)
	#endif
	#ifndef   RTE_HLA_TESTMODE_LAB
	  #define RTE_HLA_TESTMODE_LAB	(6)
	#endif
	#ifndef   RTE_HLA_TESTMODE_FOV
	  #define RTE_HLA_TESTMODE_FOV	(7)
	#endif
	#ifndef   RTE_HLA_TESTMODE_LAB_ENHANCED
	  #define RTE_HLA_TESTMODE_LAB_ENHANCED	(8)
	#endif
	#ifndef   RTE_HLA_TESTMODE_1
	  #define RTE_HLA_TESTMODE_1	(9)
	#endif
	#ifndef   RTE_HLA_TESTMODE_2
	  #define RTE_HLA_TESTMODE_2	(10)
	#endif

/* typedef RTE_HLA_FogDetection */
	#ifndef   RTE_HLA_FOGDET_UNKNOWN
	  #define RTE_HLA_FOGDET_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_FOGDET_INACTIVE
	  #define RTE_HLA_FOGDET_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_FOGDET_ACTIVE
	  #define RTE_HLA_FOGDET_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_FOGDET_INVALID
	  #define RTE_HLA_FOGDET_INVALID	(255)
	#endif

/* typedef RTE_HLA_BadWeatherDetection */
	#ifndef   RTE_HLA_BADWEATHER_DET_UNKNOWN
	  #define RTE_HLA_BADWEATHER_DET_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_BADWEATHER_DET_INACTIVE
	  #define RTE_HLA_BADWEATHER_DET_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_BADWEATHER_DET_ACTIVE
	  #define RTE_HLA_BADWEATHER_DET_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_BADWEATHER_DET_INVALID
	  #define RTE_HLA_BADWEATHER_DET_INVALID	(255)
	#endif

/* typedef RTE_HLA_CparSensityMode */
	#ifndef   RTE_HLA_CPAR_SENSITIVITY_MODE_UNKNOWN
	  #define RTE_HLA_CPAR_SENSITIVITY_MODE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_CPAR_SENSITIVITY_MODE_DEFAULT
	  #define RTE_HLA_CPAR_SENSITIVITY_MODE_DEFAULT	(1)
	#endif
	#ifndef   RTE_HLA_CPAR_SENSITIVITY_MODE_US
	  #define RTE_HLA_CPAR_SENSITIVITY_MODE_US	(2)
	#endif

/* typedef DimmingDetection_t */
	#ifndef   RTE_HLA_DIMMDET_UNKNOWN
	  #define RTE_HLA_DIMMDET_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_DIMMDET_INACTIVE
	  #define RTE_HLA_DIMMDET_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_DIMMDET_ACTIVE
	  #define RTE_HLA_DIMMDET_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_DIMMDET_INVALID
	  #define RTE_HLA_DIMMDET_INVALID	(255)
	#endif

/* typedef HLA_BusInputSignals_HlaRequest */
	#ifndef   HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_UNKNOWN
	  #define HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_UNKNOWN	(0)
	#endif
	#ifndef   HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_OFF
	  #define HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_OFF	(1)
	#endif
	#ifndef   HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_ON
	  #define HLA_BUS_INPUT_SIGNALS_HLA_REQUEST_ON	(2)
	#endif

/* typedef HLA_BusInputSignals_HBIndicatorLamp */
	#ifndef   HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_UNKNOWN
	  #define HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_UNKNOWN	(0)
	#endif
	#ifndef   HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_OFF
	  #define HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_OFF	(1)
	#endif
	#ifndef   HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_GREEN
	  #define HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_GREEN	(2)
	#endif
	#ifndef   HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_BLUE
	  #define HLA_BUS_INPUT_SIGNALS_HB_INDICATOR_LAMP_BLUE	(3)
	#endif

/* typedef RTE_HLAF_FunctionStatus */
	#ifndef   RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF
	  #define RTE_HLAF_FUNCTION_STATUS_TEMPORARY_OFF	(0)
	#endif
	#ifndef   RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF
	  #define RTE_HLAF_FUNCTION_STATUS_PERMANENT_OFF	(1)
	#endif
	#ifndef   RTE_HLAF_FUNCTION_STATUS_RUNNING
	  #define RTE_HLAF_FUNCTION_STATUS_RUNNING	(2)
	#endif
	#ifndef   RTE_HLAF_FUNCTION_STATUS_INVALID
	  #define RTE_HLAF_FUNCTION_STATUS_INVALID	(3)
	#endif

/* typedef RTE_HLA_TrafficStyle */
	#ifndef   RTE_HLA_TRAFFIC_STYLE_UNKNOWN
	  #define RTE_HLA_TRAFFIC_STYLE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_TRAFFIC_STYLE_RHT
	  #define RTE_HLA_TRAFFIC_STYLE_RHT	(1)
	#endif
	#ifndef   RTE_HLA_TRAFFIC_STYLE_LHT
	  #define RTE_HLA_TRAFFIC_STYLE_LHT	(2)
	#endif
	#ifndef   RTE_HLA_TRAFFIC_STYLE_INVALID
	  #define RTE_HLA_TRAFFIC_STYLE_INVALID	(255)
	#endif

/* typedef RTE_HLAR_CityState */
	#ifndef   RTE_HLAR_CITY_UNKNOWN
	  #define RTE_HLAR_CITY_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_CITY_NOT_DTCD
	  #define RTE_HLAR_CITY_NOT_DTCD	(1)
	#endif
	#ifndef   RTE_HLAR_CITY_DTCD
	  #define RTE_HLAR_CITY_DTCD	(2)
	#endif
	#ifndef   RTE_HLAR_CITY_MAYBE
	  #define RTE_HLAR_CITY_MAYBE	(3)
	#endif
	#ifndef   RTE_HLAR_CITY_INVALID
	  #define RTE_HLAR_CITY_INVALID	(255)
	#endif

/* typedef RTE_HLAR_WeatherState */
	#ifndef   RTE_HLAR_WEATHER_UNKNOWN
	  #define RTE_HLAR_WEATHER_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_WEATHER_GOOD
	  #define RTE_HLAR_WEATHER_GOOD	(1)
	#endif
	#ifndef   RTE_HLAR_WEATHER_BAD
	  #define RTE_HLAR_WEATHER_BAD	(2)
	#endif
	#ifndef   RTE_HLAR_WEATHER_LIGHT_FOG
	  #define RTE_HLAR_WEATHER_LIGHT_FOG	(3)
	#endif
	#ifndef   RTE_HLAR_WEATHER_MEDIUM_FOG
	  #define RTE_HLAR_WEATHER_MEDIUM_FOG	(4)
	#endif
	#ifndef   RTE_HLAR_WEATHER_HEAVY_FOG
	  #define RTE_HLAR_WEATHER_HEAVY_FOG	(5)
	#endif
	#ifndef   RTE_HLAR_WEATHER_INVALID
	  #define RTE_HLAR_WEATHER_INVALID	(255)
	#endif

/* typedef RTE_HLAR_Tunnel */
	#ifndef   RTE_HLAR_TUNNEL_UNKNOWN
	  #define RTE_HLAR_TUNNEL_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_TUNNEL_NOT_DTCD
	  #define RTE_HLAR_TUNNEL_NOT_DTCD	(1)
	#endif
	#ifndef   RTE_HLAR_TUNNEL_UPFRONT
	  #define RTE_HLAR_TUNNEL_UPFRONT	(2)
	#endif
	#ifndef   RTE_HLAR_TUNNEL_INSIDE
	  #define RTE_HLAR_TUNNEL_INSIDE	(3)
	#endif
	#ifndef   RTE_HLAR_TUNNEL_INVALID
	  #define RTE_HLAR_TUNNEL_INVALID	(255)
	#endif

/* typedef RTE_HLAF_MotorwayState */
	#ifndef   RTE_HLAF_MTWY_UNKNOWN
	  #define RTE_HLAF_MTWY_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_MTWY_COUNTRY
	  #define RTE_HLAF_MTWY_COUNTRY	(1)
	#endif
	#ifndef   RTE_HLAF_MTWY_MOTORWAY
	  #define RTE_HLAF_MTWY_MOTORWAY	(2)
	#endif
	#ifndef   RTE_HLAF_MTWY_INVALID
	  #define RTE_HLAF_MTWY_INVALID	(255)
	#endif

/* typedef RTE_HLAR_BrightnessState */
	#ifndef   RTE_HLAR_BRT_UNKNOWN
	  #define RTE_HLAR_BRT_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_BRT_DAY
	  #define RTE_HLAR_BRT_DAY	(1)
	#endif
	#ifndef   RTE_HLAR_BRT_TWLGT_1
	  #define RTE_HLAR_BRT_TWLGT_1	(2)
	#endif
	#ifndef   RTE_HLAR_BRT_TWLGT_2
	  #define RTE_HLAR_BRT_TWLGT_2	(3)
	#endif
	#ifndef   RTE_HLAR_BRT_TWLGT_3
	  #define RTE_HLAR_BRT_TWLGT_3	(4)
	#endif
	#ifndef   RTE_HLAR_BRT_NIGHT
	  #define RTE_HLAR_BRT_NIGHT	(5)
	#endif
	#ifndef   RTE_HLAR_BRT_INVALID
	  #define RTE_HLAR_BRT_INVALID	(255)
	#endif

/* typedef RTE_HLA_SensMode */
	#ifndef   RTE_HLA_SENSMODE_UNKNOWN
	  #define RTE_HLA_SENSMODE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_SENSMODE_NORMAL
	  #define RTE_HLA_SENSMODE_NORMAL	(1)
	#endif
	#ifndef   RTE_HLA_SENSMODE_US
	  #define RTE_HLA_SENSMODE_US	(2)
	#endif
	#ifndef   RTE_HLA_SENSMODE_INVALID
	  #define RTE_HLA_SENSMODE_INVALID	(255)
	#endif

/* typedef RTE_HLAF_SpeedState */
	#ifndef   RTE_HLAF_SPEEDSTATE_UNKNOWN
	  #define RTE_HLAF_SPEEDSTATE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_SPEEDSTATE_TOO_LOW
	  #define RTE_HLAF_SPEEDSTATE_TOO_LOW	(1)
	#endif
	#ifndef   RTE_HLAF_SPEEDSTATE_IN_RANGE
	  #define RTE_HLAF_SPEEDSTATE_IN_RANGE	(2)
	#endif
	#ifndef   RTE_HLAF_SPEEDSTATE_TOO_HIGH
	  #define RTE_HLAF_SPEEDSTATE_TOO_HIGH	(3)
	#endif
	#ifndef   RTE_HLAF_SPEEDSTATE_INVALID
	  #define RTE_HLAF_SPEEDSTATE_INVALID	(255)
	#endif

/* typedef RTE_HLA_SceneInfo */
	#ifndef   RTE_HLA_SCENEINFO_UNKNOWN
	  #define RTE_HLA_SCENEINFO_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_SCENEINFO_ONCOMING_PASSING
	  #define RTE_HLA_SCENEINFO_ONCOMING_PASSING	(1)
	#endif
	#ifndef   RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING
	  #define RTE_HLA_SCENEINFO_PRECEDING_OVERTAKING	(2)
	#endif
	#ifndef   RTE_HLA_SCENEINFO_INVALID
	  #define RTE_HLA_SCENEINFO_INVALID	(255)
	#endif

/* typedef RTE_HLAF_SignalStatus */
	#ifndef   RTE_HLAF_SIGSTAT_UNKNOWN
	  #define RTE_HLAF_SIGSTAT_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_SIGSTAT_INIT
	  #define RTE_HLAF_SIGSTAT_INIT	(1)
	#endif
	#ifndef   RTE_HLAF_SIGSTAT_DATA_VALID
	  #define RTE_HLAF_SIGSTAT_DATA_VALID	(2)
	#endif
	#ifndef   RTE_HLAF_SIGSTAT_DATA_INVALID
	  #define RTE_HLAF_SIGSTAT_DATA_INVALID	(3)
	#endif
	#ifndef   RTE_HLAF_SIGSTAT_INVALID
	  #define RTE_HLAF_SIGSTAT_INVALID	(255)
	#endif

/* typedef RTE_HLAF_HighBeamState */
	#ifndef   RTE_HLAF_HB_STATE_UNKNOWN
	  #define RTE_HLAF_HB_STATE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_HB_STATE_OFF
	  #define RTE_HLAF_HB_STATE_OFF	(1)
	#endif
	#ifndef   RTE_HLAF_HB_STATE_FULL_ON
	  #define RTE_HLAF_HB_STATE_FULL_ON	(2)
	#endif
	#ifndef   RTE_HLAF_HB_STATE_PARTIAL
	  #define RTE_HLAF_HB_STATE_PARTIAL	(3)
	#endif
	#ifndef   RTE_HLAF_HB_STATE_SPOT
	  #define RTE_HLAF_HB_STATE_SPOT	(4)
	#endif
	#ifndef   RTE_HLAF_HB_STATE_INVALID
	  #define RTE_HLAF_HB_STATE_INVALID	(255)
	#endif

/* typedef RTE_HLAF_ObjStatus */
	#ifndef   RTE_HLAF_OBJSTA_UNKNOWN
	  #define RTE_HLAF_OBJSTA_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_OBJSTA_NO_OBJ
	  #define RTE_HLAF_OBJSTA_NO_OBJ	(1)
	#endif
	#ifndef   RTE_HLAF_OBJSTA_UNKNOWN_OBJ
	  #define RTE_HLAF_OBJSTA_UNKNOWN_OBJ	(2)
	#endif
	#ifndef   RTE_HLAF_OBJSTA_PREC_OBJ
	  #define RTE_HLAF_OBJSTA_PREC_OBJ	(3)
	#endif
	#ifndef   RTE_HLAF_OBJSTA_ONC_OBJ
	  #define RTE_HLAF_OBJSTA_ONC_OBJ	(4)
	#endif
	#ifndef   RTE_HLAF_OBJSTA_INVALID
	  #define RTE_HLAF_OBJSTA_INVALID	(255)
	#endif

/* typedef RTE_HLAF_MatrixTurnOffReason */
	#ifndef   RTE_HLAF_TURNOFFREASON_UNKNOWN
	  #define RTE_HLAF_TURNOFFREASON_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_ONC
	  #define RTE_HLAF_TURNOFFREASON_ONC	(1)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_PREC
	  #define RTE_HLAF_TURNOFFREASON_PREC	(2)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_SPEED
	  #define RTE_HLAF_TURNOFFREASON_SPEED	(4)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_BRIGHTNESS
	  #define RTE_HLAF_TURNOFFREASON_BRIGHTNESS	(8)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_CITY
	  #define RTE_HLAF_TURNOFFREASON_CITY	(16)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_FOG
	  #define RTE_HLAF_TURNOFFREASON_FOG	(32)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_BLOCKAGE
	  #define RTE_HLAF_TURNOFFREASON_BLOCKAGE	(64)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_DELAY
	  #define RTE_HLAF_TURNOFFREASON_DELAY	(128)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_ERROR
	  #define RTE_HLAF_TURNOFFREASON_ERROR	(256)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_TUNNEL
	  #define RTE_HLAF_TURNOFFREASON_TUNNEL	(512)
	#endif
	#ifndef   RTE_HLAF_TURNOFFREASON_WEATHER
	  #define RTE_HLAF_TURNOFFREASON_WEATHER	(1024)
	#endif

/* typedef RTE_HLAF_DistState */
	#ifndef   RTE_HLAF_DISTSTATE_UNKNOWN
	  #define RTE_HLAF_DISTSTATE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_DISTSTATE_SINGLELIGHT
	  #define RTE_HLAF_DISTSTATE_SINGLELIGHT	(1)
	#endif
	#ifndef   RTE_HLAF_DISTSTATE_PAIRLIGHT
	  #define RTE_HLAF_DISTSTATE_PAIRLIGHT	(2)
	#endif
	#ifndef   RTE_HLAF_DISTSTATE_PAIRLIGHT_WIDE
	  #define RTE_HLAF_DISTSTATE_PAIRLIGHT_WIDE	(3)
	#endif
	#ifndef   RTE_HLAF_DISTSTATE_INVALID
	  #define RTE_HLAF_DISTSTATE_INVALID	(255)
	#endif

/* typedef RTE_HLA_DistReliability */
	#ifndef   RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN
	  #define RTE_HLA_DISTANCE_RELIABILITY_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_DISTANCE_RELIABILITY_LOW
	  #define RTE_HLA_DISTANCE_RELIABILITY_LOW	(1)
	#endif
	#ifndef   RTE_HLA_DISTANCE_RELIABILITY_MID
	  #define RTE_HLA_DISTANCE_RELIABILITY_MID	(2)
	#endif
	#ifndef   RTE_HLA_DISTANCE_RELIABILITY_HIGH
	  #define RTE_HLA_DISTANCE_RELIABILITY_HIGH	(3)
	#endif
	#ifndef   RTE_HLA_DISTANCE_RELIABILITY_INVALID
	  #define RTE_HLA_DISTANCE_RELIABILITY_INVALID	(255)
	#endif

/* typedef RTE_HLAF_TTBStatus */
	#ifndef   RTE_HLAF_TTBSTA_UNKNOWN
	  #define RTE_HLAF_TTBSTA_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_TTBSTA_NO_OBJ
	  #define RTE_HLAF_TTBSTA_NO_OBJ	(1)
	#endif
	#ifndef   RTE_HLAF_TTBSTA_DIR_UNKNOWN
	  #define RTE_HLAF_TTBSTA_DIR_UNKNOWN	(2)
	#endif
	#ifndef   RTE_HLAF_TTBSTA_DIR_LEFT
	  #define RTE_HLAF_TTBSTA_DIR_LEFT	(3)
	#endif
	#ifndef   RTE_HLAF_TTBSTA_DIR_RIGHT
	  #define RTE_HLAF_TTBSTA_DIR_RIGHT	(4)
	#endif
	#ifndef   RTE_HLAF_TTBSTA_INVALID
	  #define RTE_HLAF_TTBSTA_INVALID	(255)
	#endif

/* typedef RTE_HLAF_DimmingStatus */
	#ifndef   RTE_HLAF_DIMM_STATE_UNKNOWN
	  #define RTE_HLAF_DIMM_STATE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_DIMM_STATE_AVL
	  #define RTE_HLAF_DIMM_STATE_AVL	(1)
	#endif
	#ifndef   RTE_HLAF_DIMM_STATE_LIMITED
	  #define RTE_HLAF_DIMM_STATE_LIMITED	(2)
	#endif
	#ifndef   RTE_HLAF_DIMM_STATE_NAVL
	  #define RTE_HLAF_DIMM_STATE_NAVL	(3)
	#endif
	#ifndef   RTE_HLAF_DIMM_STATE_ERROR
	  #define RTE_HLAF_DIMM_STATE_ERROR	(4)
	#endif
	#ifndef   RTE_HLAF_DIMM_STATE_INVALID
	  #define RTE_HLAF_DIMM_STATE_INVALID	(255)
	#endif

/* typedef RTE_HLAF_DimmingLevel */
	#ifndef   RTE_HLAF_DIMM_LEVEL_UNKNOWN
	  #define RTE_HLAF_DIMM_LEVEL_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_DIMM_LEVEL_NO_REDUCT
	  #define RTE_HLAF_DIMM_LEVEL_NO_REDUCT	(1)
	#endif
	#ifndef   RTE_HLAF_DIMM_LEVEL_REDUCT_1
	  #define RTE_HLAF_DIMM_LEVEL_REDUCT_1	(2)
	#endif
	#ifndef   RTE_HLAF_DIMM_LEVEL_REDUCT_2
	  #define RTE_HLAF_DIMM_LEVEL_REDUCT_2	(3)
	#endif
	#ifndef   RTE_HLAF_DIMM_LEVEL_INVALID
	  #define RTE_HLAF_DIMM_LEVEL_INVALID	(255)
	#endif

/* typedef HLA_RadarObjDynamicProperty */
	#ifndef   HLA_RADAR_OBJECT_DYN_PROPERTY_MOVING
	  #define HLA_RADAR_OBJECT_DYN_PROPERTY_MOVING	(0)
	#endif
	#ifndef   HLA_RADAR_OBJECT_DYN_PROPERTY_STATIONARY
	  #define HLA_RADAR_OBJECT_DYN_PROPERTY_STATIONARY	(1)
	#endif
	#ifndef   HLA_RADAR_OBJECT_DYN_PROPERTY_ONCOMING
	  #define HLA_RADAR_OBJECT_DYN_PROPERTY_ONCOMING	(2)
	#endif
	#ifndef   HLA_RADAR_OBJECT_DYN_PROPERTY_CROSSING_LEFT
	  #define HLA_RADAR_OBJECT_DYN_PROPERTY_CROSSING_LEFT	(3)
	#endif
	#ifndef   HLA_RADAR_OBJECT_DYN_PROPERTY_CROSSING_RIGHT
	  #define HLA_RADAR_OBJECT_DYN_PROPERTY_CROSSING_RIGHT	(4)
	#endif
	#ifndef   HLA_RADAR_OBJECT_DYN_PROPERTY_UNKNOWN
	  #define HLA_RADAR_OBJECT_DYN_PROPERTY_UNKNOWN	(5)
	#endif
	#ifndef   HLA_RADAR_OBJECT_DYN_PROPERTY_STOPPED
	  #define HLA_RADAR_OBJECT_DYN_PROPERTY_STOPPED	(6)
	#endif
	#ifndef   HLA_RADAR_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES
	  #define HLA_RADAR_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES	(7)
	#endif

/* typedef HLA_RadarObjClassification */
	#ifndef   HLA_RADAR_OBJECT_CLASS_POINT
	  #define HLA_RADAR_OBJECT_CLASS_POINT	(0)
	#endif
	#ifndef   HLA_RADAR_OBJECT_CLASS_CAR
	  #define HLA_RADAR_OBJECT_CLASS_CAR	(1)
	#endif
	#ifndef   HLA_RADAR_OBJECT_CLASS_TRUCK
	  #define HLA_RADAR_OBJECT_CLASS_TRUCK	(2)
	#endif
	#ifndef   HLA_RADAR_OBJECT_CLASS_PEDESTRIAN
	  #define HLA_RADAR_OBJECT_CLASS_PEDESTRIAN	(3)
	#endif
	#ifndef   HLA_RADAR_OBJECT_CLASS_MOTORCYCLE
	  #define HLA_RADAR_OBJECT_CLASS_MOTORCYCLE	(4)
	#endif
	#ifndef   HLA_RADAR_OBJECT_CLASS_BICYCLE
	  #define HLA_RADAR_OBJECT_CLASS_BICYCLE	(5)
	#endif
	#ifndef   HLA_RADAR_OBJECT_CLASS_WIDE
	  #define HLA_RADAR_OBJECT_CLASS_WIDE	(6)
	#endif
	#ifndef   HLA_RADAR_OBJECT_CLASS_UNCLASSIFIED
	  #define HLA_RADAR_OBJECT_CLASS_UNCLASSIFIED	(7)
	#endif
	#ifndef   HLA_RADAR_OBJECT_CLASS_OTHER_VEHICLE
	  #define HLA_RADAR_OBJECT_CLASS_OTHER_VEHICLE	(8)
	#endif
	#ifndef   HLA_RADAR_OBJECT_CLASS_MAX_DIFF_TYPES
	  #define HLA_RADAR_OBJECT_CLASS_MAX_DIFF_TYPES	(9)
	#endif

/* typedef LCF_e_ModeCtrlSystemState_t */
	#ifndef   LCF_SYSTEM_AVAILABLE
	  #define LCF_SYSTEM_AVAILABLE	(0)
	#endif
	#ifndef   LCF_SYSTEM_NOT_AVAILABLE
	  #define LCF_SYSTEM_NOT_AVAILABLE	(1)
	#endif
	#ifndef   LCF_SYSTEM_ERROR
	  #define LCF_SYSTEM_ERROR	(2)
	#endif
	#ifndef   LCF_SYSTEM_INVALID
	  #define LCF_SYSTEM_INVALID	(3)
	#endif

/* typedef LCF_e_ModeCtrlActiveState_t */
	#ifndef   LCF_ACTIVITY_STANDBY
	  #define LCF_ACTIVITY_STANDBY	(0)
	#endif
	#ifndef   LCF_ACTIVITY_CONTROLLING
	  #define LCF_ACTIVITY_CONTROLLING	(1)
	#endif
	#ifndef   LCF_ACTIVITY_SHUTDOWN
	  #define LCF_ACTIVITY_SHUTDOWN	(2)
	#endif
	#ifndef   LCF_ACTIVITY_INVALID
	  #define LCF_ACTIVITY_INVALID	(3)
	#endif

/* typedef LCF_e_InputDefectState_t */
	#ifndef   LCF_INPUT_STATE_DEFECT
	  #define LCF_INPUT_STATE_DEFECT	(0)
	#endif
	#ifndef   LCF_INPUT_STATE_NOT_DEFECT
	  #define LCF_INPUT_STATE_NOT_DEFECT	(1)
	#endif
	#ifndef   LCF_INPUT_STATE_INVALID
	  #define LCF_INPUT_STATE_INVALID	(3)
	#endif

/* typedef LCF_e_MainSwitchState_t */
	#ifndef   LCF_MAIN_SWITCH_OFF
	  #define LCF_MAIN_SWITCH_OFF	(0)
	#endif
	#ifndef   LCF_MAIN_SWITCH_ON
	  #define LCF_MAIN_SWITCH_ON	(1)
	#endif
	#ifndef   LCF_MAIN_SWITCH_INVALID
	  #define LCF_MAIN_SWITCH_INVALID	(3)
	#endif

/* typedef LCF_e_SensitivityState_t */
	#ifndef   LCF_SENSITIVITY_LATE
	  #define LCF_SENSITIVITY_LATE	(0)
	#endif
	#ifndef   LCF_SENSITIVITY_EARLY
	  #define LCF_SENSITIVITY_EARLY	(1)
	#endif
	#ifndef   LCF_SENSITIVITY_STANDARD
	  #define LCF_SENSITIVITY_STANDARD	(2)
	#endif
	#ifndef   LCF_SENSITIVITY_INVALID
	  #define LCF_SENSITIVITY_INVALID	(3)
	#endif

/* typedef LCF_e_FctMode_t */
	#ifndef   LCF_FCT_MODE_DEFAULT
	  #define LCF_FCT_MODE_DEFAULT	(0)
	#endif
	#ifndef   LCF_FCT_MODE_SETTING_1
	  #define LCF_FCT_MODE_SETTING_1	(1)
	#endif
	#ifndef   LCF_FCT_MODE_SETTING_2
	  #define LCF_FCT_MODE_SETTING_2	(2)
	#endif
	#ifndef   LCF_FCT_MODE_SETTING_3
	  #define LCF_FCT_MODE_SETTING_3	(3)
	#endif
	#ifndef   LCF_FCT_MODE_UNKNOWN
	  #define LCF_FCT_MODE_UNKNOWN	(4)
	#endif
	#ifndef   LCF_FCT_MODE_INVALID
	  #define LCF_FCT_MODE_INVALID	(5)
	#endif

/* typedef LCF_e_IoStateType_t */
	#ifndef   LCF_IO_STATE_VALID
	  #define LCF_IO_STATE_VALID	(0)
	#endif
	#ifndef   LCF_IO_STATE_INVALID
	  #define LCF_IO_STATE_INVALID	(1)
	#endif
	#ifndef   LCF_IO_STATE_NOTAVAIL
	  #define LCF_IO_STATE_NOTAVAIL	(2)
	#endif
	#ifndef   LCF_IO_STATE_SUBSTITUTE
	  #define LCF_IO_STATE_SUBSTITUTE	(3)
	#endif
	#ifndef   LCF_IO_STATE_INIT
	  #define LCF_IO_STATE_INIT	(4)
	#endif

/* typedef LCF_e_IoStatePos_t */
	#ifndef   LCF_IO_POS_HWA
	  #define LCF_IO_POS_HWA	(0)
	#endif
	#ifndef   LCF_IO_POS_HWAR
	  #define LCF_IO_POS_HWAR	(1)
	#endif
	#ifndef   LCF_IO_POS_DFSA
	  #define LCF_IO_POS_DFSA	(2)
	#endif
	#ifndef   LCF_IO_POS_DFSAR
	  #define LCF_IO_POS_DFSAR	(3)
	#endif
	#ifndef   LCF_IO_POS_STQ
	  #define LCF_IO_POS_STQ	(4)
	#endif
	#ifndef   LCF_IO_POS_DSWT
	  #define LCF_IO_POS_DSWT	(5)
	#endif
	#ifndef   LCF_IO_POS_MTQ
	  #define LCF_IO_POS_MTQ	(6)
	#endif
	#ifndef   LCF_IO_POS_ESCS
	  #define LCF_IO_POS_ESCS	(7)
	#endif
	#ifndef   LCF_IO_POS_ESCA
	  #define LCF_IO_POS_ESCA	(8)
	#endif
	#ifndef   LCF_IO_POS_ABSS
	  #define LCF_IO_POS_ABSS	(9)
	#endif
	#ifndef   LCF_IO_POS_ABSA
	  #define LCF_IO_POS_ABSA	(10)
	#endif
	#ifndef   LCF_IO_POS_TCSS
	  #define LCF_IO_POS_TCSS	(11)
	#endif
	#ifndef   LCF_IO_POS_TCSA
	  #define LCF_IO_POS_TCSA	(12)
	#endif
	#ifndef   LCF_IO_POS_ACCS
	  #define LCF_IO_POS_ACCS	(13)
	#endif
	#ifndef   LCF_IO_POS_ACCA
	  #define LCF_IO_POS_ACCA	(14)
	#endif
	#ifndef   LCF_IO_POS_VSMS
	  #define LCF_IO_POS_VSMS	(15)
	#endif
	#ifndef   LCF_IO_POS_VSMA
	  #define LCF_IO_POS_VSMA	(16)
	#endif
	#ifndef   LCF_IO_POS_EBAS
	  #define LCF_IO_POS_EBAS	(17)
	#endif
	#ifndef   LCF_IO_POS_EBAA
	  #define LCF_IO_POS_EBAA	(18)
	#endif
	#ifndef   LCF_IO_POS_TBD
	  #define LCF_IO_POS_TBD	(19)
	#endif
	#ifndef   LCF_IO_POS_DO
	  #define LCF_IO_POS_DO	(20)
	#endif
	#ifndef   LCF_IO_POS_TS
	  #define LCF_IO_POS_TS	(21)
	#endif
	#ifndef   LCF_IO_POS_TSL
	  #define LCF_IO_POS_TSL	(22)
	#endif
	#ifndef   LCF_IO_POS_VRS
	  #define LCF_IO_POS_VRS	(23)
	#endif
	#ifndef   LCF_IO_POS_DNB
	  #define LCF_IO_POS_DNB	(24)
	#endif
	#ifndef   LCF_IO_POS_OSD
	  #define LCF_IO_POS_OSD	(25)
	#endif
	#ifndef   LCF_IO_POS_USD
	  #define LCF_IO_POS_USD	(26)
	#endif
	#ifndef   LCF_IO_POS_BA
	  #define LCF_IO_POS_BA	(27)
	#endif
	#ifndef   LCF_IO_POS_TRL
	  #define LCF_IO_POS_TRL	(28)
	#endif
	#ifndef   LCF_IO_POS_ETU
	  #define LCF_IO_POS_ETU	(29)
	#endif
	#ifndef   LCF_IO_POS_ETA
	  #define LCF_IO_POS_ETA	(30)
	#endif
	#ifndef   LCF_IO_POS_ETF
	  #define LCF_IO_POS_ETF	(31)
	#endif
	#ifndef   LCF_IO_POS_EFS
	  #define LCF_IO_POS_EFS	(32)
	#endif
	#ifndef   LCF_IO_POS_ED
	  #define LCF_IO_POS_ED	(33)
	#endif
	#ifndef   LCF_IO_POS_LKASW
	  #define LCF_IO_POS_LKASW	(34)
	#endif
	#ifndef   LCF_IO_POS_LKAM
	  #define LCF_IO_POS_LKAM	(35)
	#endif
	#ifndef   LCF_IO_POS_TJASW
	  #define LCF_IO_POS_TJASW	(36)
	#endif
	#ifndef   LCF_IO_POS_TJAM
	  #define LCF_IO_POS_TJAM	(37)
	#endif
	#ifndef   LCF_IO_POS_VAS
	  #define LCF_IO_POS_VAS	(38)
	#endif
	#ifndef   LCF_IO_POS_SML
	  #define LCF_IO_POS_SML	(39)
	#endif
	#ifndef   LCF_IO_POS_LDWSW
	  #define LCF_IO_POS_LDWSW	(40)
	#endif
	#ifndef   LCF_IO_POS_LDPSW
	  #define LCF_IO_POS_LDPSW	(41)
	#endif
	#ifndef   LCF_IO_POS_RDPSW
	  #define LCF_IO_POS_RDPSW	(42)
	#endif
	#ifndef   LCF_IO_POS_LDPOSW
	  #define LCF_IO_POS_LDPOSW	(43)
	#endif
	#ifndef   LCF_IO_POS_LDWS
	  #define LCF_IO_POS_LDWS	(44)
	#endif
	#ifndef   LCF_IO_POS_LDPS
	  #define LCF_IO_POS_LDPS	(45)
	#endif
	#ifndef   LCF_IO_POS_RDPS
	  #define LCF_IO_POS_RDPS	(46)
	#endif
	#ifndef   LCF_IO_POS_DHO
	  #define LCF_IO_POS_DHO	(47)
	#endif
	#ifndef   LCF_IO_POS_VVEL
	  #define LCF_IO_POS_VVEL	(48)
	#endif
	#ifndef   LCF_IO_POS_SCCA
	  #define LCF_IO_POS_SCCA	(49)
	#endif
	#ifndef   LCF_IO_POS_USMR
	  #define LCF_IO_POS_USMR	(50)
	#endif
	#ifndef   LCF_IO_POS_HDAON
	  #define LCF_IO_POS_HDAON	(51)
	#endif
	#ifndef   LCF_IO_POS_SCCON
	  #define LCF_IO_POS_SCCON	(52)
	#endif
	#ifndef   LCF_IO_POS_USMSS
	  #define LCF_IO_POS_USMSS	(53)
	#endif
	#ifndef   LCF_IO_POS_NRT
	  #define LCF_IO_POS_NRT	(54)
	#endif
	#ifndef   LCF_IO_POS_NSFOW
	  #define LCF_IO_POS_NSFOW	(55)
	#endif
	#ifndef   LCF_IO_POS_NSSL
	  #define LCF_IO_POS_NSSL	(56)
	#endif
	#ifndef   LCF_IO_POS_NST
	  #define LCF_IO_POS_NST	(57)
	#endif
	#ifndef   LCF_IO_POS_NPPT
	  #define LCF_IO_POS_NPPT	(58)
	#endif
	#ifndef   LCF_IO_POS_NTGD
	  #define LCF_IO_POS_NTGD	(59)
	#endif
	#ifndef   LCF_IO_POS_NTDDO
	  #define LCF_IO_POS_NTDDO	(60)
	#endif
	#ifndef   LCF_IO_POS_NPO
	  #define LCF_IO_POS_NPO	(61)
	#endif
	#ifndef   LCF_IO_POS_NPCC
	  #define LCF_IO_POS_NPCC	(62)
	#endif
	#ifndef   LCF_IO_POS_NPOSCC
	  #define LCF_IO_POS_NPOSCC	(63)
	#endif
	#ifndef   LCF_IO_POS_HEFF
	  #define LCF_IO_POS_HEFF	(64)
	#endif
	#ifndef   LCF_IO_POS_SCCM
	  #define LCF_IO_POS_SCCM	(65)
	#endif
	#ifndef   LCF_IO_POS_NSU
	  #define LCF_IO_POS_NSU	(66)
	#endif
	#ifndef   LCF_IO_POS_AHO
	  #define LCF_IO_POS_AHO	(67)
	#endif
	#ifndef   LCF_IO_POS_APP
	  #define LCF_IO_POS_APP	(68)
	#endif
	#ifndef   LCF_IO_POS_VAR
	  #define LCF_IO_POS_VAR	(69)
	#endif
	#ifndef   LCF_IO_POS_OBSRL
	  #define LCF_IO_POS_OBSRL	(70)
	#endif
	#ifndef   LCF_IO_POS_OFOVRL
	  #define LCF_IO_POS_OFOVRL	(71)
	#endif
	#ifndef   LCF_IO_POS_QFRL
	  #define LCF_IO_POS_QFRL	(72)
	#endif
	#ifndef   LCF_IO_POS_MSFRL
	  #define LCF_IO_POS_MSFRL	(73)
	#endif
	#ifndef   LCF_IO_POS_OBSRR
	  #define LCF_IO_POS_OBSRR	(74)
	#endif
	#ifndef   LCF_IO_POS_OFOVRR
	  #define LCF_IO_POS_OFOVRR	(75)
	#endif
	#ifndef   LCF_IO_POS_QFRR
	  #define LCF_IO_POS_QFRR	(76)
	#endif
	#ifndef   LCF_IO_POS_MSFRR
	  #define LCF_IO_POS_MSFRR	(77)
	#endif
	#ifndef   LCF_IO_POS_ALCASW
	  #define LCF_IO_POS_ALCASW	(78)
	#endif
	#ifndef   LCF_IO_POS_ALCAS
	  #define LCF_IO_POS_ALCAS	(79)
	#endif
	#ifndef   LCF_IO_POS_ALCAM
	  #define LCF_IO_POS_ALCAM	(80)
	#endif
	#ifndef   LCF_IO_POS_LCAAL
	  #define LCF_IO_POS_LCAAL	(81)
	#endif
	#ifndef   LCF_IO_POS_BSDAL
	  #define LCF_IO_POS_BSDAL	(82)
	#endif
	#ifndef   LCF_IO_POS_LCAWL
	  #define LCF_IO_POS_LCAWL	(83)
	#endif
	#ifndef   LCF_IO_POS_BSDWL
	  #define LCF_IO_POS_BSDWL	(84)
	#endif
	#ifndef   LCF_IO_POS_LCAAR
	  #define LCF_IO_POS_LCAAR	(85)
	#endif
	#ifndef   LCF_IO_POS_BSDAR
	  #define LCF_IO_POS_BSDAR	(86)
	#endif
	#ifndef   LCF_IO_POS_LCAWR
	  #define LCF_IO_POS_LCAWR	(87)
	#endif
	#ifndef   LCF_IO_POS_BSDWR
	  #define LCF_IO_POS_BSDWR	(88)
	#endif
	#ifndef   LCF_IO_POS_HWLS
	  #define LCF_IO_POS_HWLS	(89)
	#endif
	#ifndef   LCF_IO_POS_HWRS
	  #define LCF_IO_POS_HWRS	(90)
	#endif
	#ifndef   LCF_IO_POS_HWCS
	  #define LCF_IO_POS_HWCS	(91)
	#endif
	#ifndef   LCF_IO_POS_HWLM
	  #define LCF_IO_POS_HWLM	(92)
	#endif
	#ifndef   LCF_IO_POS_HWRM
	  #define LCF_IO_POS_HWRM	(93)
	#endif
	#ifndef   LCF_IO_POS_HWCM
	  #define LCF_IO_POS_HWCM	(94)
	#endif
	#ifndef   LCF_IO_POS_VWLS
	  #define LCF_IO_POS_VWLS	(95)
	#endif
	#ifndef   LCF_IO_POS_VWRS
	  #define LCF_IO_POS_VWRS	(96)
	#endif
	#ifndef   LCF_IO_POS_VWCS
	  #define LCF_IO_POS_VWCS	(97)
	#endif
	#ifndef   LCF_IO_POS_VWLM
	  #define LCF_IO_POS_VWLM	(98)
	#endif
	#ifndef   LCF_IO_POS_VWRM
	  #define LCF_IO_POS_VWRM	(99)
	#endif
	#ifndef   LCF_IO_POS_VWCM
	  #define LCF_IO_POS_VWCM	(100)
	#endif
	#ifndef   LCF_IO_POS_LDPOCS
	  #define LCF_IO_POS_LDPOCS	(101)
	#endif
	#ifndef   LCF_IO_POS_AOLCS
	  #define LCF_IO_POS_AOLCS	(102)
	#endif
	#ifndef   LCF_IO_POS_TJALCA
	  #define LCF_IO_POS_TJALCA	(103)
	#endif
	#ifndef   LCF_IO_POS_TJAHOWE
	  #define LCF_IO_POS_TJAHOWE	(104)
	#endif
	#ifndef   LCF_IO_POS_SCM
	  #define LCF_IO_POS_SCM	(105)
	#endif
	#ifndef   LCF_IO_POS_EPSAF
	  #define LCF_IO_POS_EPSAF	(106)
	#endif
	#ifndef   LCF_IO_POS_EPSDI
	  #define LCF_IO_POS_EPSDI	(107)
	#endif
	#ifndef   LCF_IO_POS_EPSRT
	  #define LCF_IO_POS_EPSRT	(108)
	#endif
	#ifndef   LCF_IO_POS_EPSMT
	  #define LCF_IO_POS_EPSMT	(109)
	#endif
	#ifndef   LCF_IO_POS_EPSMAS
	  #define LCF_IO_POS_EPSMAS	(110)
	#endif
	#ifndef   LCF_IO_POS_EPSRSA
	  #define LCF_IO_POS_EPSRSA	(111)
	#endif
	#ifndef   LCF_IO_POS_STOD
	  #define LCF_IO_POS_STOD	(112)
	#endif
	#ifndef   LCF_IO_POS_MRAX
	  #define LCF_IO_POS_MRAX	(113)
	#endif
	#ifndef   LCF_IO_POS_MRVX
	  #define LCF_IO_POS_MRVX	(114)
	#endif
	#ifndef   LCF_IO_POS_MRAY
	  #define LCF_IO_POS_MRAY	(115)
	#endif
	#ifndef   LCF_IO_POS_MRVY
	  #define LCF_IO_POS_MRVY	(116)
	#endif
	#ifndef   LCF_IO_POS_PPX
	  #define LCF_IO_POS_PPX	(117)
	#endif
	#ifndef   LCF_IO_POS_PPY
	  #define LCF_IO_POS_PPY	(118)
	#endif
	#ifndef   LCF_IO_POS_PPXSD
	  #define LCF_IO_POS_PPXSD	(119)
	#endif
	#ifndef   LCF_IO_POS_PPYSD
	  #define LCF_IO_POS_PPYSD	(120)
	#endif
	#ifndef   LCF_IO_POS_OBJQ
	  #define LCF_IO_POS_OBJQ	(121)
	#endif
	#ifndef   LCF_IO_POS_OBJRCT
	  #define LCF_IO_POS_OBJRCT	(122)
	#endif
	#ifndef   LCF_IO_POS_OBJRMS
	  #define LCF_IO_POS_OBJRMS	(123)
	#endif
	#ifndef   LCF_IO_POS_DIMW
	  #define LCF_IO_POS_DIMW	(124)
	#endif
	#ifndef   LCF_IO_POS_SSRC
	  #define LCF_IO_POS_SSRC	(125)
	#endif
	#ifndef   LCF_IO_POS_TMST
	  #define LCF_IO_POS_TMST	(126)
	#endif
	#ifndef   LCF_IO_POS_OBJREQ
	  #define LCF_IO_POS_OBJREQ	(127)
	#endif
	#ifndef   LCF_IO_POS_LPX
	  #define LCF_IO_POS_LPX	(128)
	#endif
	#ifndef   LCF_IO_POS_LPY
	  #define LCF_IO_POS_LPY	(129)
	#endif
	#ifndef   LCF_IO_POS_LRVX
	  #define LCF_IO_POS_LRVX	(130)
	#endif
	#ifndef   LCF_IO_POS_LRVY
	  #define LCF_IO_POS_LRVY	(131)
	#endif
	#ifndef   LCF_IO_POS_LRAX
	  #define LCF_IO_POS_LRAX	(132)
	#endif
	#ifndef   LCF_IO_POS_LRAY
	  #define LCF_IO_POS_LRAY	(133)
	#endif
	#ifndef   LCF_IO_POS_LQU
	  #define LCF_IO_POS_LQU	(134)
	#endif
	#ifndef   LCF_IO_POS_LMS
	  #define LCF_IO_POS_LMS	(135)
	#endif
	#ifndef   LCF_IO_POS_LOBJRCT
	  #define LCF_IO_POS_LOBJRCT	(136)
	#endif
	#ifndef   LCF_IO_POS_LOBJTS
	  #define LCF_IO_POS_LOBJTS	(137)
	#endif
	#ifndef   LCF_IO_POS_RPX
	  #define LCF_IO_POS_RPX	(138)
	#endif
	#ifndef   LCF_IO_POS_RPY
	  #define LCF_IO_POS_RPY	(139)
	#endif
	#ifndef   LCF_IO_POS_RRVX
	  #define LCF_IO_POS_RRVX	(140)
	#endif
	#ifndef   LCF_IO_POS_RRVY
	  #define LCF_IO_POS_RRVY	(141)
	#endif
	#ifndef   LCF_IO_POS_RRAX
	  #define LCF_IO_POS_RRAX	(142)
	#endif
	#ifndef   LCF_IO_POS_RRAY
	  #define LCF_IO_POS_RRAY	(143)
	#endif
	#ifndef   LCF_IO_POS_RQU
	  #define LCF_IO_POS_RQU	(144)
	#endif
	#ifndef   LCF_IO_POS_RMS
	  #define LCF_IO_POS_RMS	(145)
	#endif
	#ifndef   LCF_IO_POS_ROBJRCT
	  #define LCF_IO_POS_ROBJRCT	(146)
	#endif
	#ifndef   LCF_IO_POS_ROBJTS
	  #define LCF_IO_POS_ROBJTS	(147)
	#endif
	#ifndef   LCF_IO_POS_DOCOBJL
	  #define LCF_IO_POS_DOCOBJL	(148)
	#endif
	#ifndef   LCF_IO_POS_DOCOBJR
	  #define LCF_IO_POS_DOCOBJR	(149)
	#endif
	#ifndef   LCF_IO_POS_DOCOBJQ
	  #define LCF_IO_POS_DOCOBJQ	(150)
	#endif
	#ifndef   LCF_IO_POS_APASTA
	  #define LCF_IO_POS_APASTA	(151)
	#endif
	#ifndef   LCF_IO_MAX
	  #define LCF_IO_MAX	(152)
	#endif

/* typedef LCF_e_ActiveLatFunction_t */
	#ifndef   LCF_MODE_CTRL_ACTIVE_FUNCTION_NONE
	  #define LCF_MODE_CTRL_ACTIVE_FUNCTION_NONE	(0)
	#endif
	#ifndef   LCF_MODE_CTRL_ACTIVE_FUNCTION_ESA
	  #define LCF_MODE_CTRL_ACTIVE_FUNCTION_ESA	(1)
	#endif
	#ifndef   LCF_MODE_CTRL_ACTIVE_FUNCTION_LCA
	  #define LCF_MODE_CTRL_ACTIVE_FUNCTION_LCA	(2)
	#endif
	#ifndef   LCF_MODE_CTRL_ACTIVE_FUNCTION_TJA
	  #define LCF_MODE_CTRL_ACTIVE_FUNCTION_TJA	(3)
	#endif

/* typedef LCF_e_RearDrvAssStat_t */
	#ifndef   LCF_STATIONARY
	  #define LCF_STATIONARY	(0)
	#endif
	#ifndef   LCF_NOT_STATIONARY
	  #define LCF_NOT_STATIONARY	(1)
	#endif

/* typedef LCF_e_TrajGuiQualifier_t */
	#ifndef   LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_DONOT_APPLY_TGT_VALUE
	  #define LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_DONOT_APPLY_TGT_VALUE	(0)
	#endif
	#ifndef   LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV
	  #define LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV	(1)
	#endif
	#ifndef   LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_SIDE_SLIP
	  #define LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_SIDE_SLIP	(2)
	#endif
	#ifndef   LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_FREEZE_CRV
	  #define LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_FREEZE_CRV	(3)
	#endif
	#ifndef   LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_FFCTRL
	  #define LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_FFCTRL	(4)
	#endif
	#ifndef   LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_TGT_CHANGE
	  #define LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_TGT_CHANGE	(5)
	#endif
	#ifndef   LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_BRIDGING
	  #define LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_BRIDGING	(6)
	#endif

/* typedef LCF_e_FctSystemState_t */
	#ifndef   LCF_SYSSTATE_NOTPRESENT
	  #define LCF_SYSSTATE_NOTPRESENT	(0)
	#endif
	#ifndef   LCF_SYSSTATE_DISABLED
	  #define LCF_SYSSTATE_DISABLED	(1)
	#endif
	#ifndef   LCF_SYSSTATE_PASSIVE
	  #define LCF_SYSSTATE_PASSIVE	(2)
	#endif
	#ifndef   LCF_SYSSTATE_REQUEST
	  #define LCF_SYSSTATE_REQUEST	(3)
	#endif
	#ifndef   LCF_SYSSTATE_CONTROLLING
	  #define LCF_SYSSTATE_CONTROLLING	(4)
	#endif
	#ifndef   LCF_SYSSTATE_RAMPOUT
	  #define LCF_SYSSTATE_RAMPOUT	(5)
	#endif
	#ifndef   LCF_SYSSTATE_ERROR
	  #define LCF_SYSSTATE_ERROR	(6)
	#endif

/* typedef LCF_e_Lkas_LdwsWarning_t */
	#ifndef   LCF_WARN_NONE
	  #define LCF_WARN_NONE	(0)
	#endif
	#ifndef   LCF_WARN_HAPTIC
	  #define LCF_WARN_HAPTIC	(1)
	#endif
	#ifndef   LCF_WARN_ACOUSTIC
	  #define LCF_WARN_ACOUSTIC	(2)
	#endif

/* typedef LCF_e_DispLaneDetected_t */
	#ifndef   LCF_DISP_LANE_NOT_DETECTED
	  #define LCF_DISP_LANE_NOT_DETECTED	(0)
	#endif
	#ifndef   LCF_DISP_LANE_PYHSICAL
	  #define LCF_DISP_LANE_PYHSICAL	(1)
	#endif
	#ifndef   LCF_DISP_LANE_BRIDGED
	  #define LCF_DISP_LANE_BRIDGED	(2)
	#endif
	#ifndef   LCF_DISP_LANE_VIRTUAL
	  #define LCF_DISP_LANE_VIRTUAL	(3)
	#endif

/* typedef LCF_e_LatCtrlMode_t */
	#ifndef   LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PASSIVE
	  #define LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PASSIVE	(0)
	#endif
	#ifndef   LCF_TJA_SYS_COORD_LAT_CTRL_MODE_LANE_CENTERING
	  #define LCF_TJA_SYS_COORD_LAT_CTRL_MODE_LANE_CENTERING	(1)
	#endif
	#ifndef   LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_NO_LANE_BOUNDS
	  #define LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_NO_LANE_BOUNDS	(2)
	#endif
	#ifndef   LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_CLOSE_TO_RIGHT_BOUND
	  #define LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_CLOSE_TO_RIGHT_BOUND	(3)
	#endif
	#ifndef   LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_CLOSE_TO_LEFT_BOUND
	  #define LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_CLOSE_TO_LEFT_BOUND	(4)
	#endif
	#ifndef   LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_WITH_LANE_BOUNDARIES
	  #define LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_WITH_LANE_BOUNDARIES	(5)
	#endif
	#ifndef   LCF_TJA_SYS_COORD_LAT_CTRL_MODE_DEGRADATION
	  #define LCF_TJA_SYS_COORD_LAT_CTRL_MODE_DEGRADATION	(6)
	#endif

/* typedef LCF_e_LCAActiveState_t */
	#ifndef   LCF_LCA_INACTIVE
	  #define LCF_LCA_INACTIVE	(0)
	#endif
	#ifndef   LCF_LCA_ACTIVE
	  #define LCF_LCA_ACTIVE	(1)
	#endif
	#ifndef   LCF_LCA_INVALID
	  #define LCF_LCA_INVALID	(2)
	#endif

/* typedef LCF_e_BSDActiveState_t */
	#ifndef   LCF_BSD_INACTIVE
	  #define LCF_BSD_INACTIVE	(0)
	#endif
	#ifndef   LCF_BSD_ACTIVE
	  #define LCF_BSD_ACTIVE	(1)
	#endif
	#ifndef   LCF_BSD_INVALID
	  #define LCF_BSD_INVALID	(2)
	#endif

/* typedef LCF_e_LCAWarningState_t */
	#ifndef   LCF_LCA_WARNING_OFF
	  #define LCF_LCA_WARNING_OFF	(0)
	#endif
	#ifndef   LCF_LCA_WARNING_1
	  #define LCF_LCA_WARNING_1	(1)
	#endif
	#ifndef   LCF_LCA_WARNING_2
	  #define LCF_LCA_WARNING_2	(2)
	#endif
	#ifndef   LCF_LCA_WARNING_INVALID
	  #define LCF_LCA_WARNING_INVALID	(3)
	#endif

/* typedef LCF_e_BSDWarningState_t */
	#ifndef   LCF_BSD_WARNING_OFF
	  #define LCF_BSD_WARNING_OFF	(0)
	#endif
	#ifndef   LCF_BSD_WARNING_1
	  #define LCF_BSD_WARNING_1	(1)
	#endif
	#ifndef   LCF_BSD_WARNING_2
	  #define LCF_BSD_WARNING_2	(2)
	#endif
	#ifndef   LCF_BSD_WARNING_INVALID
	  #define LCF_BSD_WARNING_INVALID	(3)
	#endif

/* typedef LCF_e_DangOcObj_t */
	#ifndef   FROOP_NO_HAZARDOUS_OBJ
	  #define FROOP_NO_HAZARDOUS_OBJ	(0)
	#endif
	#ifndef   FROOP_RADAR_ONLY_LANE_MAPPED
	  #define FROOP_RADAR_ONLY_LANE_MAPPED	(1)
	#endif
	#ifndef   FROOP_FUSED_OBJ_LANE_MAPPED
	  #define FROOP_FUSED_OBJ_LANE_MAPPED	(2)
	#endif
	#ifndef   FROOP_RADAR_ONLY_CORR_MAPPED
	  #define FROOP_RADAR_ONLY_CORR_MAPPED	(3)
	#endif
	#ifndef   FROOP_FUSED_OBJ_CORR_MAPPED
	  #define FROOP_FUSED_OBJ_CORR_MAPPED	(4)
	#endif
	#ifndef   FROOP_DANG_OC_OBJ_INVALID
	  #define FROOP_DANG_OC_OBJ_INVALID	(7)
	#endif

/* typedef LCF_e_WrnDeviceState_t */
	#ifndef   LCF_WRN_DVC_STANDBY
	  #define LCF_WRN_DVC_STANDBY	(0)
	#endif
	#ifndef   LCF_WRN_DVC_ACTIVE
	  #define LCF_WRN_DVC_ACTIVE	(1)
	#endif
	#ifndef   LCF_WRN_DVC_NOT_AVAILABLE
	  #define LCF_WRN_DVC_NOT_AVAILABLE	(2)
	#endif
	#ifndef   LCF_WRN_DVC_ERROR
	  #define LCF_WRN_DVC_ERROR	(3)
	#endif
	#ifndef   LCF_WRN_DVC_UNKNOWN
	  #define LCF_WRN_DVC_UNKNOWN	(4)
	#endif
	#ifndef   LCF_WRN_DVC_INVALID
	  #define LCF_WRN_DVC_INVALID	(7)
	#endif

/* typedef LCF_e_WrnDeviceMode_t */
	#ifndef   LCF_WRN_MODE_NOT_ACTIVE
	  #define LCF_WRN_MODE_NOT_ACTIVE	(0)
	#endif
	#ifndef   LCF_WRN_MODE_ACTIVE_MODE_1
	  #define LCF_WRN_MODE_ACTIVE_MODE_1	(1)
	#endif
	#ifndef   LCF_WRN_MODE_ACTIVE_MODE_2
	  #define LCF_WRN_MODE_ACTIVE_MODE_2	(2)
	#endif
	#ifndef   LCF_WRN_MODE_ACTIVE_MODE_3
	  #define LCF_WRN_MODE_ACTIVE_MODE_3	(3)
	#endif
	#ifndef   LCF_WRN_MODE_ACTIVE_MODE_4
	  #define LCF_WRN_MODE_ACTIVE_MODE_4	(4)
	#endif
	#ifndef   LCF_WRN_MODE_ACTIVE_MODE_5
	  #define LCF_WRN_MODE_ACTIVE_MODE_5	(5)
	#endif
	#ifndef   LCF_WRN_MODE_UNKNOWN
	  #define LCF_WRN_MODE_UNKNOWN	(6)
	#endif
	#ifndef   LCF_WRN_MODE_INVALID
	  #define LCF_WRN_MODE_INVALID	(7)
	#endif

/* typedef LCF_e_FctSideState_t */
	#ifndef   LCF_LANE_BOUND_NOT_AVAILABLE
	  #define LCF_LANE_BOUND_NOT_AVAILABLE	(0)
	#endif
	#ifndef   LCF_LANE_BOUND_AVAILABLE
	  #define LCF_LANE_BOUND_AVAILABLE	(1)
	#endif
	#ifndef   LCF_LAT_CONTROL_TRIGGER
	  #define LCF_LAT_CONTROL_TRIGGER	(2)
	#endif
	#ifndef   LCF_LAT_CONTROL_RUNNING
	  #define LCF_LAT_CONTROL_RUNNING	(3)
	#endif
	#ifndef   LCF_LAT_CONTROL_SUCCESSFUL
	  #define LCF_LAT_CONTROL_SUCCESSFUL	(4)
	#endif
	#ifndef   LCF_LAT_CONTROL_CANCEL_DRV_ACTION
	  #define LCF_LAT_CONTROL_CANCEL_DRV_ACTION	(5)
	#endif
	#ifndef   LCF_LAT_CONTROL_CANCEL_LAT_DEVIATION
	  #define LCF_LAT_CONTROL_CANCEL_LAT_DEVIATION	(6)
	#endif
	#ifndef   LCF_LAT_CONTROL_CANCEL_LANE_MARKING_AVAIL
	  #define LCF_LAT_CONTROL_CANCEL_LANE_MARKING_AVAIL	(7)
	#endif
	#ifndef   LCF_LAT_CONTROL_CANCEL_OTHER
	  #define LCF_LAT_CONTROL_CANCEL_OTHER	(8)
	#endif
	#ifndef   LCF_LAT_CONTROL_ABORT
	  #define LCF_LAT_CONTROL_ABORT	(9)
	#endif
	#ifndef   LCF_LAT_CONTROL_INVALID
	  #define LCF_LAT_CONTROL_INVALID	(15)
	#endif

/* typedef LCF_e_BoolState_t */
	#ifndef   LCF_FALSE
	  #define LCF_FALSE	(0)
	#endif
	#ifndef   LCF_TRUE
	  #define LCF_TRUE	(1)
	#endif
	#ifndef   LCF_INVALID
	  #define LCF_INVALID	(3)
	#endif

/* typedef LCF_e_AccTraceTrajState_t */
	#ifndef   LCF_ACC_TRACE_INVALID
	  #define LCF_ACC_TRACE_INVALID	(0)
	#endif
	#ifndef   LCF_ACC_TRACE_VALID
	  #define LCF_ACC_TRACE_VALID	(1)
	#endif
	#ifndef   LCF_ACC_TRACE_NOT_AVAILABLE
	  #define LCF_ACC_TRACE_NOT_AVAILABLE	(2)
	#endif
	#ifndef   LCF_ACC_TRACE_ERROR
	  #define LCF_ACC_TRACE_ERROR	(15)
	#endif

/* typedef LCF_e_TurnSignalState_t */
	#ifndef   LCF_TURN_SIG_OFF
	  #define LCF_TURN_SIG_OFF	(0)
	#endif
	#ifndef   LCF_TURN_SIG_LEFT
	  #define LCF_TURN_SIG_LEFT	(1)
	#endif
	#ifndef   LCF_TURN_SIG_RIGHT
	  #define LCF_TURN_SIG_RIGHT	(2)
	#endif
	#ifndef   LCF_TURN_SIG_HAZARD
	  #define LCF_TURN_SIG_HAZARD	(3)
	#endif
	#ifndef   LCF_TURN_SIG_INVALID
	  #define LCF_TURN_SIG_INVALID	(4)
	#endif

/* typedef LCF_e_TurnLeverState_t */
	#ifndef   LCF_TURN_LEVER_OFF
	  #define LCF_TURN_LEVER_OFF	(0)
	#endif
	#ifndef   LCF_TURN_LEVER_TIPPED
	  #define LCF_TURN_LEVER_TIPPED	(1)
	#endif
	#ifndef   LCF_TURN_LEVER_ENGAGED
	  #define LCF_TURN_LEVER_ENGAGED	(2)
	#endif
	#ifndef   LCF_TURN_LEVER_INVALID
	  #define LCF_TURN_LEVER_INVALID	(3)
	#endif

/* typedef LCF_e_ModeSelection_t */
	#ifndef   LCF_MODE_SEL_OFF
	  #define LCF_MODE_SEL_OFF	(0)
	#endif
	#ifndef   LCF_MODE_SEL_LDW
	  #define LCF_MODE_SEL_LDW	(1)
	#endif
	#ifndef   LCF_MODE_SEL_LDP_STD
	  #define LCF_MODE_SEL_LDP_STD	(2)
	#endif
	#ifndef   LCF_MODE_SEL_LDP_ACT
	  #define LCF_MODE_SEL_LDP_ACT	(3)
	#endif

/* typedef LCF_e_HandsOffState_t */
	#ifndef   LCF_HANDS_OFF_DETECTED
	  #define LCF_HANDS_OFF_DETECTED	(0)
	#endif
	#ifndef   LCF_HANDS_ON_DETECTED
	  #define LCF_HANDS_ON_DETECTED	(1)
	#endif
	#ifndef   LCF_HANDS_STAT_INVALID
	  #define LCF_HANDS_STAT_INVALID	(3)
	#endif

/* typedef LCF_e_SCCActiveState_t */
	#ifndef   LCF_SCC_INACTIVE
	  #define LCF_SCC_INACTIVE	(0)
	#endif
	#ifndef   LCF_SCC_ACTIVE
	  #define LCF_SCC_ACTIVE	(1)
	#endif

/* typedef LCF_e_USMResetState_t */
	#ifndef   LCF_USM_RESET_DEFAULT
	  #define LCF_USM_RESET_DEFAULT	(0)
	#endif
	#ifndef   LCF_USM_RESET_OFF
	  #define LCF_USM_RESET_OFF	(1)
	#endif

/* typedef LCF_e_HDAOnState_t */
	#ifndef   LCF_HDA_DEFAULT
	  #define LCF_HDA_DEFAULT	(0)
	#endif
	#ifndef   LCF_HDA_OFF
	  #define LCF_HDA_OFF	(1)
	#endif
	#ifndef   LCF_HDA_ON
	  #define LCF_HDA_ON	(2)
	#endif
	#ifndef   LCF_HDA_INVALID
	  #define LCF_HDA_INVALID	(3)
	#endif

/* typedef LCF_e_SCCOnState_t */
	#ifndef   LCF_SCC_MODE
	  #define LCF_SCC_MODE	(1)
	#endif
	#ifndef   LCF_CC_MODE
	  #define LCF_CC_MODE	(2)
	#endif

/* typedef LCF_e_NAVIRoadType_t */
	#ifndef   LCF_ROAD_UNKNOWN
	  #define LCF_ROAD_UNKNOWN	(0)
	#endif
	#ifndef   LCF_ROAD_FREEWAY
	  #define LCF_ROAD_FREEWAY	(1)
	#endif
	#ifndef   LCF_ROAD_CITY_FREEWAY
	  #define LCF_ROAD_CITY_FREEWAY	(2)
	#endif

/* typedef LCF_e_NAVIRoadForm_t */
	#ifndef   LCF_ROAD_FORM_UNKNOWN
	  #define LCF_ROAD_FORM_UNKNOWN	(0)
	#endif
	#ifndef   LCF_ROAD_FORM_NONDISJ
	  #define LCF_ROAD_FORM_NONDISJ	(1)
	#endif
	#ifndef   LCF_ROAD_FORM_DISJ
	  #define LCF_ROAD_FORM_DISJ	(2)
	#endif
	#ifndef   LCF_ROAD_FORM_JC
	  #define LCF_ROAD_FORM_JC	(3)
	#endif
	#ifndef   LCF_ROAD_FORM_PLURAL_JC
	  #define LCF_ROAD_FORM_PLURAL_JC	(4)
	#endif
	#ifndef   LCF_ROAD_FORM_IC
	  #define LCF_ROAD_FORM_IC	(5)
	#endif
	#ifndef   LCF_ROAD_FORM_RESERVED1
	  #define LCF_ROAD_FORM_RESERVED1	(6)
	#endif
	#ifndef   LCF_ROAD_FORM_SERVICE_AREA
	  #define LCF_ROAD_FORM_SERVICE_AREA	(7)
	#endif
	#ifndef   LCF_ROAD_FORM_RESERVED2
	  #define LCF_ROAD_FORM_RESERVED2	(8)
	#endif
	#ifndef   LCF_ROAD_FORM_ROUNDABOUT
	  #define LCF_ROAD_FORM_ROUNDABOUT	(9)
	#endif
	#ifndef   LCF_ROAD_FORM_P_TURN
	  #define LCF_ROAD_FORM_P_TURN	(10)
	#endif
	#ifndef   LCF_ROAD_FORM_U_TURN
	  #define LCF_ROAD_FORM_U_TURN	(11)
	#endif
	#ifndef   LCF_ROAD_FORM_PEDESTRIAN
	  #define LCF_ROAD_FORM_PEDESTRIAN	(12)
	#endif
	#ifndef   LCF_ROAD_FORM_FRONTAGE_RD
	  #define LCF_ROAD_FORM_FRONTAGE_RD	(13)
	#endif
	#ifndef   LCF_ROAD_FORM_INTERSECT_INT
	  #define LCF_ROAD_FORM_INTERSECT_INT	(14)
	#endif
	#ifndef   LCF_ROAD_FORM_INVALID
	  #define LCF_ROAD_FORM_INVALID	(15)
	#endif

/* typedef LCF_e_NAVIStatus_t */
	#ifndef   LCF_NAVI_BOOTING
	  #define LCF_NAVI_BOOTING	(0)
	#endif
	#ifndef   LCF_NAVI_NORMAL_OP
	  #define LCF_NAVI_NORMAL_OP	(1)
	#endif
	#ifndef   LCF_NAVI_NO_SD_CARD
	  #define LCF_NAVI_NO_SD_CARD	(2)
	#endif
	#ifndef   LCF_NAVI_INVALID
	  #define LCF_NAVI_INVALID	(3)
	#endif

/* typedef LCF_e_NAVIProlProfType_t */
	#ifndef   LCF_NAVI_PROL_INVALID
	  #define LCF_NAVI_PROL_INVALID	(0)
	#endif
	#ifndef   LCF_NAVI_PROL_LONGITUDE
	  #define LCF_NAVI_PROL_LONGITUDE	(1)
	#endif
	#ifndef   LCF_NAVI_PROL_LATITUDE
	  #define LCF_NAVI_PROL_LATITUDE	(2)
	#endif
	#ifndef   LCF_NAVI_PROL_ALTITUDE
	  #define LCF_NAVI_PROL_ALTITUDE	(3)
	#endif
	#ifndef   LCF_NAVI_PROL_CTRL_PT_LONGITUDE
	  #define LCF_NAVI_PROL_CTRL_PT_LONGITUDE	(4)
	#endif
	#ifndef   LCF_NAVI_PROL_CTRL_PT_LATITUDE
	  #define LCF_NAVI_PROL_CTRL_PT_LATITUDE	(5)
	#endif
	#ifndef   LCF_NAVI_PROL_CTRL_PT_ALTITUDE
	  #define LCF_NAVI_PROL_CTRL_PT_ALTITUDE	(6)
	#endif
	#ifndef   LCF_NAVI_PROL_LINK_IDENT
	  #define LCF_NAVI_PROL_LINK_IDENT	(7)
	#endif
	#ifndef   LCF_NAVI_PROL_TRAFFIC_SIGN
	  #define LCF_NAVI_PROL_TRAFFIC_SIGN	(8)
	#endif
	#ifndef   LCF_NAVI_PROL_RESERVED1
	  #define LCF_NAVI_PROL_RESERVED1	(9)
	#endif
	#ifndef   LCF_NAVI_PROL_RESERVED2
	  #define LCF_NAVI_PROL_RESERVED2	(10)
	#endif
	#ifndef   LCF_NAVI_PROL_RESERVED3
	  #define LCF_NAVI_PROL_RESERVED3	(11)
	#endif
	#ifndef   LCF_NAVI_PROL_RESERVED4
	  #define LCF_NAVI_PROL_RESERVED4	(12)
	#endif
	#ifndef   LCF_NAVI_PROL_RESERVED5
	  #define LCF_NAVI_PROL_RESERVED5	(13)
	#endif
	#ifndef   LCF_NAVI_PROL_RESERVED6
	  #define LCF_NAVI_PROL_RESERVED6	(14)
	#endif
	#ifndef   LCF_NAVI_PROL_RESERVED7
	  #define LCF_NAVI_PROL_RESERVED7	(15)
	#endif
	#ifndef   LCF_NAVI_PROL_ALERT_INFO_SPOT
	  #define LCF_NAVI_PROL_ALERT_INFO_SPOT	(16)
	#endif

/* typedef LCF_e_NAVITollgateDet_t */
	#ifndef   LCF_NAVI_TOLLGATE_NOT_DET
	  #define LCF_NAVI_TOLLGATE_NOT_DET	(0)
	#endif
	#ifndef   LCF_NAVI_TOLLGATE_DET
	  #define LCF_NAVI_TOLLGATE_DET	(1)
	#endif

/* typedef LCF_e_HDAExtFail_t */
	#ifndef   LCF_HDA_NO_EXT_FAIL
	  #define LCF_HDA_NO_EXT_FAIL	(0)
	#endif
	#ifndef   LCF_HDA_EXT_FAIL
	  #define LCF_HDA_EXT_FAIL	(1)
	#endif

/* typedef LCF_e_SCCMainMode_t */
	#ifndef   LCF_SCC_OFF
	  #define LCF_SCC_OFF	(0)
	#endif
	#ifndef   LCF_SCC_ON
	  #define LCF_SCC_ON	(1)
	#endif

/* typedef LCF_e_NAVISpeedUnit_t */
	#ifndef   LCF_NAVI_SPD_UNIT_NONE
	  #define LCF_NAVI_SPD_UNIT_NONE	(0)
	#endif
	#ifndef   LCF_NAVI_SPD_UNIT_KPH
	  #define LCF_NAVI_SPD_UNIT_KPH	(1)
	#endif
	#ifndef   LCF_NAVI_SPD_UNIT_MPH
	  #define LCF_NAVI_SPD_UNIT_MPH	(2)
	#endif
	#ifndef   LCF_NAVI_SPD_UNIT_INVALID
	  #define LCF_NAVI_SPD_UNIT_INVALID	(3)
	#endif

/* typedef LCF_e_EPSStSterCtlMod_t */
	#ifndef   LCF_NO_STEER_CONTROL
	  #define LCF_NO_STEER_CONTROL	(0)
	#endif
	#ifndef   LCF_STEER_CONTROL
	  #define LCF_STEER_CONTROL	(1)
	#endif
	#ifndef   LCF_STEER_ACTUATOR_MODE
	  #define LCF_STEER_ACTUATOR_MODE	(2)
	#endif
	#ifndef   LCF_ANGLE_CONTROL_MODE
	  #define LCF_ANGLE_CONTROL_MODE	(3)
	#endif
	#ifndef   LCF_STEER_MODE_INVALID
	  #define LCF_STEER_MODE_INVALID	(7)
	#endif

/* typedef LCF_e_EPSStatusECUActFact_t */
	#ifndef   LCF_EPS_ACT_FACT_OUTPUT
	  #define LCF_EPS_ACT_FACT_OUTPUT	(0)
	#endif
	#ifndef   LCF_EPS_ACT_FACT_INPUT
	  #define LCF_EPS_ACT_FACT_INPUT	(1)
	#endif
	#ifndef   LCF_EPS_ACT_FACT_INVALID
	  #define LCF_EPS_ACT_FACT_INVALID	(3)
	#endif

/* typedef LCF_e_EPSStatusDriverInter_t */
	#ifndef   LCF_EPS_DRV_NO_INTERVENTION
	  #define LCF_EPS_DRV_NO_INTERVENTION	(0)
	#endif
	#ifndef   LCF_EPS_DRV_INTERVENTION
	  #define LCF_EPS_DRV_INTERVENTION	(1)
	#endif
	#ifndef   LCF_EPS_DRV_INVALID
	  #define LCF_EPS_DRV_INVALID	(3)
	#endif

/* typedef LCF_e_LObjStat_t */
	#ifndef   LCF_LOBJSTS_NO_OBJECT
	  #define LCF_LOBJSTS_NO_OBJECT	(0)
	#endif
	#ifndef   LCF_LOBJSTS_NEW
	  #define LCF_LOBJSTS_NEW	(1)
	#endif
	#ifndef   LCF_LOBJSTS_MATURE
	  #define LCF_LOBJSTS_MATURE	(2)
	#endif
	#ifndef   LCF_LOBJSTS_COASTED
	  #define LCF_LOBJSTS_COASTED	(3)
	#endif

/* typedef LCF_e_RObjStat_t */
	#ifndef   LCF_ROBJSTS_NO_OBJECT
	  #define LCF_ROBJSTS_NO_OBJECT	(0)
	#endif
	#ifndef   LCF_ROBJSTS_NEW
	  #define LCF_ROBJSTS_NEW	(1)
	#endif
	#ifndef   LCF_ROBJSTS_MATURE
	  #define LCF_ROBJSTS_MATURE	(2)
	#endif
	#ifndef   LCF_ROBJSTS_COASTED
	  #define LCF_ROBJSTS_COASTED	(3)
	#endif

/* typedef LCF_e_LObjZone_t */
	#ifndef   LCF_LOBJZONE_NO_OBJECT
	  #define LCF_LOBJZONE_NO_OBJECT	(0)
	#endif
	#ifndef   LCF_LOBJZONE_BSW_ZONE
	  #define LCF_LOBJZONE_BSW_ZONE	(1)
	#endif
	#ifndef   LCF_LOBJZONE_CVW_ZONE
	  #define LCF_LOBJZONE_CVW_ZONE	(2)
	#endif
	#ifndef   LCF_LOBJZONE_SHARED_ZONE
	  #define LCF_LOBJZONE_SHARED_ZONE	(3)
	#endif

/* typedef LCF_e_RObjZone_t */
	#ifndef   LCF_ROBJZONE_NO_OBJECT
	  #define LCF_ROBJZONE_NO_OBJECT	(0)
	#endif
	#ifndef   LCF_ROBJZONE_BSW_ZONE
	  #define LCF_ROBJZONE_BSW_ZONE	(1)
	#endif
	#ifndef   LCF_ROBJZONE_CVW_ZONE
	  #define LCF_ROBJZONE_CVW_ZONE	(2)
	#endif
	#ifndef   LCF_ROBJZONE_SHARED_ZONE
	  #define LCF_ROBJZONE_SHARED_ZONE	(3)
	#endif

/* typedef LCF_e_RearDrvAssState_t */
	#ifndef   LCF_LCA_RESERVED1
	  #define LCF_LCA_RESERVED1	(1)
	#endif
	#ifndef   LCF_LCA_RESERVED2
	  #define LCF_LCA_RESERVED2	(2)
	#endif
	#ifndef   LCF_LCA_SENSORBLOCKAGE
	  #define LCF_LCA_SENSORBLOCKAGE	(3)
	#endif
	#ifndef   LCF_LCA_DISABLED
	  #define LCF_LCA_DISABLED	(4)
	#endif
	#ifndef   LCF_LCA_ENABLED
	  #define LCF_LCA_ENABLED	(5)
	#endif
	#ifndef   LCF_LCA_SYSTEMERROR
	  #define LCF_LCA_SYSTEMERROR	(6)
	#endif

/* typedef SelectedTargetObjDetected__nu_t */
	#ifndef   TJA_TARGET_OBJ_NOT_DETECTED
	  #define TJA_TARGET_OBJ_NOT_DETECTED	(0)
	#endif
	#ifndef   TJA_TARGET_OBJ_DETECTED
	  #define TJA_TARGET_OBJ_DETECTED	(1)
	#endif

/* typedef ObjRecognClassType__nu_t */
	#ifndef   TJA_EM_GEN_OBJECT_CLASS_POINT
	  #define TJA_EM_GEN_OBJECT_CLASS_POINT	(0)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_CLASS_CAR
	  #define TJA_EM_GEN_OBJECT_CLASS_CAR	(1)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_CLASS_TRUCK
	  #define TJA_EM_GEN_OBJECT_CLASS_TRUCK	(2)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_CLASS_PEDESTRIAN
	  #define TJA_EM_GEN_OBJECT_CLASS_PEDESTRIAN	(3)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_CLASS_MOTORCYCLE
	  #define TJA_EM_GEN_OBJECT_CLASS_MOTORCYCLE	(4)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_CLASS_BICYCLE
	  #define TJA_EM_GEN_OBJECT_CLASS_BICYCLE	(5)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_CLASS_WIDE
	  #define TJA_EM_GEN_OBJECT_CLASS_WIDE	(6)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_CLASS_UNCLASSIFIED
	  #define TJA_EM_GEN_OBJECT_CLASS_UNCLASSIFIED	(7)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_CLASS_TL
	  #define TJA_EM_GEN_OBJECT_CLASS_TL	(8)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES
	  #define TJA_EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES	(9)
	#endif

/* typedef ObjRecognMeasState__nu_t */
	#ifndef   TJA_EM_GEN_OBJECT_MT_STATE_DELETED
	  #define TJA_EM_GEN_OBJECT_MT_STATE_DELETED	(0)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_MT_STATE_NEW
	  #define TJA_EM_GEN_OBJECT_MT_STATE_NEW	(1)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_MT_STATE_MEASURED
	  #define TJA_EM_GEN_OBJECT_MT_STATE_MEASURED	(2)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_MT_STATE_PREDICTED
	  #define TJA_EM_GEN_OBJECT_MT_STATE_PREDICTED	(3)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_MT_STATE_INACTIVE
	  #define TJA_EM_GEN_OBJECT_MT_STATE_INACTIVE	(4)
	#endif
	#ifndef   TJA_EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES
	  #define TJA_EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES	(5)
	#endif

/* typedef LCF_e_QuDangOcObjDtct_t */
	#ifndef   FROOP_OC_OBJ_QUAL_UNKNOWN
	  #define FROOP_OC_OBJ_QUAL_UNKNOWN	(0)
	#endif
	#ifndef   FROOP_OC_OBJ_QUAL_STARTUP
	  #define FROOP_OC_OBJ_QUAL_STARTUP	(1)
	#endif
	#ifndef   FROOP_OC_OBJ_QUAL_NORMAL_OP
	  #define FROOP_OC_OBJ_QUAL_NORMAL_OP	(2)
	#endif
	#ifndef   FROOP_OC_OBJ_QUAL_ERR_DRV_SOLVABLE
	  #define FROOP_OC_OBJ_QUAL_ERR_DRV_SOLVABLE	(3)
	#endif
	#ifndef   FROOP_OC_OBJ_QUAL_ERR_GARAGE
	  #define FROOP_OC_OBJ_QUAL_ERR_GARAGE	(4)
	#endif
	#ifndef   FROOP_OC_OBJ_QUAL_INVALID
	  #define FROOP_OC_OBJ_QUAL_INVALID	(7)
	#endif

/* typedef LCF_e_LKASLDWSysState_t */
	#ifndef   LCF_SYS_OFF
	  #define LCF_SYS_OFF	(0)
	#endif
	#ifndef   LCF_LOW_VEH_SPEED
	  #define LCF_LOW_VEH_SPEED	(1)
	#endif
	#ifndef   LCF_SYS_UNAVAILABLE
	  #define LCF_SYS_UNAVAILABLE	(2)
	#endif
	#ifndef   LCF_EPS_CTRL_FULL_LANE_RECOGNIZED
	  #define LCF_EPS_CTRL_FULL_LANE_RECOGNIZED	(3)
	#endif
	#ifndef   LCF_FULL_LANE_RECOGNIZED
	  #define LCF_FULL_LANE_RECOGNIZED	(4)
	#endif
	#ifndef   LCF_LEFT_LINE_RECOGNIZED
	  #define LCF_LEFT_LINE_RECOGNIZED	(5)
	#endif
	#ifndef   LCF_RIGHT_LINE_RECOGNIZED
	  #define LCF_RIGHT_LINE_RECOGNIZED	(6)
	#endif
	#ifndef   LCF_EPS_CTRL_LEFT_LINE_RECOGNIZED
	  #define LCF_EPS_CTRL_LEFT_LINE_RECOGNIZED	(7)
	#endif
	#ifndef   LCF_EPS_CTRL_RIGHT_LINE_RECOGNIZED
	  #define LCF_EPS_CTRL_RIGHT_LINE_RECOGNIZED	(8)
	#endif
	#ifndef   LCF_SYS_NOT_CALIBRATED
	  #define LCF_SYS_NOT_CALIBRATED	(14)
	#endif
	#ifndef   LCF_SYS_FAILURE
	  #define LCF_SYS_FAILURE	(15)
	#endif

/* typedef LCF_e_LaKMCLaneStatus_t */
	#ifndef   LCF_NO_LANE_DEPARTURE
	  #define LCF_NO_LANE_DEPARTURE	(0)
	#endif
	#ifndef   LCF_DEPARTING_LEFT_LANE
	  #define LCF_DEPARTING_LEFT_LANE	(1)
	#endif
	#ifndef   LCF_DEPARTING_LEFT_LANE_FAST
	  #define LCF_DEPARTING_LEFT_LANE_FAST	(2)
	#endif
	#ifndef   LCF_DEPARTING_RIGHT_LANE
	  #define LCF_DEPARTING_RIGHT_LANE	(3)
	#endif
	#ifndef   LCF_DEPARTING_RIGHT_LANE_FAST
	  #define LCF_DEPARTING_RIGHT_LANE_FAST	(4)
	#endif
	#ifndef   LCF_DEPARTING_LANE_INVALID
	  #define LCF_DEPARTING_LANE_INVALID	(7)
	#endif

/* typedef LCF_e_Lkas_LDWSOpt_USM_t */
	#ifndef   LCF_OPT_USM_INVALID
	  #define LCF_OPT_USM_INVALID	(0)
	#endif
	#ifndef   LCF_OPT_USM_LDW
	  #define LCF_OPT_USM_LDW	(1)
	#endif
	#ifndef   LCF_OPT_USM_LKAS_STD
	  #define LCF_OPT_USM_LKAS_STD	(2)
	#endif
	#ifndef   LCF_OPT_USM_LKAS_ACT
	  #define LCF_OPT_USM_LKAS_ACT	(3)
	#endif
	#ifndef   LCF_OPT_USM_LDW_ONLY
	  #define LCF_OPT_USM_LDW_ONLY	(4)
	#endif

/* typedef LCF_e_Lkas_SysWarning_t */
	#ifndef   LCF_WARN_NOINFO
	  #define LCF_WARN_NOINFO	(0)
	#endif
	#ifndef   LCF_WARN_HANDSOFF
	  #define LCF_WARN_HANDSOFF	(4)
	#endif
	#ifndef   LCF_WARN_SYS_AUTO_OFF
	  #define LCF_WARN_SYS_AUTO_OFF	(9)
	#endif

/* typedef LCF_e_HdaLgActStatus_t */
	#ifndef   LCF_LG_INACTIVE
	  #define LCF_LG_INACTIVE	(0)
	#endif
	#ifndef   LCF_LG_ACTIVE
	  #define LCF_LG_ACTIVE	(1)
	#endif

/* typedef LCF_e_SCCAutoSetSpdEnable_t */
	#ifndef   LCF_MANUAL_SPD_LIMIT
	  #define LCF_MANUAL_SPD_LIMIT	(0)
	#endif
	#ifndef   LCF_AUTOMATIC_SPD_LIMIT
	  #define LCF_AUTOMATIC_SPD_LIMIT	(1)
	#endif

/* typedef LCF_e_CLUAutoSetSpdUpdate_t */
	#ifndef   LCF_AUTO_SET_SPD_UPD_DEFAULT
	  #define LCF_AUTO_SET_SPD_UPD_DEFAULT	(0)
	#endif
	#ifndef   LCF_AUTO_SET_SPD_UPD_ON
	  #define LCF_AUTO_SET_SPD_UPD_ON	(1)
	#endif

/* typedef LCF_e_CLUHDAStatus_t */
	#ifndef   LCF_HDA_NOT_APPLIED
	  #define LCF_HDA_NOT_APPLIED	(0)
	#endif
	#ifndef   LCF_HDA_FCT_OFF
	  #define LCF_HDA_FCT_OFF	(1)
	#endif
	#ifndef   LCF_HDA_FCT_ON
	  #define LCF_HDA_FCT_ON	(2)
	#endif
	#ifndef   LCF_HDA_FAIL
	  #define LCF_HDA_FAIL	(3)
	#endif

/* typedef LCF_e_CLUHDAMode_t */
	#ifndef   LCF_HDA_MODE_OFF
	  #define LCF_HDA_MODE_OFF	(0)
	#endif
	#ifndef   LCF_HDA_MODE_READY
	  #define LCF_HDA_MODE_READY	(1)
	#endif
	#ifndef   LCF_HDA_MODE_ACT
	  #define LCF_HDA_MODE_ACT	(2)
	#endif
	#ifndef   LCF_HDA_MODE_RESERVED
	  #define LCF_HDA_MODE_RESERVED	(3)
	#endif

/* typedef LCF_e_CLULaneDetect_t */
	#ifndef   LCF_HDA_NO_LANE
	  #define LCF_HDA_NO_LANE	(0)
	#endif
	#ifndef   LCF_HDA_LEFT_LANE
	  #define LCF_HDA_LEFT_LANE	(1)
	#endif
	#ifndef   LCF_HDA_RIGHT_LANE
	  #define LCF_HDA_RIGHT_LANE	(2)
	#endif
	#ifndef   LCF_HDA_FULL_LANE
	  #define LCF_HDA_FULL_LANE	(3)
	#endif

/* typedef LCF_e_CLUHDAInfoDisplay_t */
	#ifndef   LCF_HDA_DISP_NONE
	  #define LCF_HDA_DISP_NONE	(0)
	#endif
	#ifndef   LCF_HDA_DISP_SYS_START
	  #define LCF_HDA_DISP_SYS_START	(1)
	#endif
	#ifndef   LCF_HDA_DISP_SYS_AUTO_DISENG_HWY_OFF
	  #define LCF_HDA_DISP_SYS_AUTO_DISENG_HWY_OFF	(2)
	#endif
	#ifndef   LCF_HDA_DISP_RESERVED1
	  #define LCF_HDA_DISP_RESERVED1	(3)
	#endif
	#ifndef   LCF_HDA_DISP_SYS_FAIL_POPUP
	  #define LCF_HDA_DISP_SYS_FAIL_POPUP	(4)
	#endif
	#ifndef   LCF_HDA_DISP_HANDS_OFF_POPUP
	  #define LCF_HDA_DISP_HANDS_OFF_POPUP	(5)
	#endif
	#ifndef   LCF_HDA_DISP_HANDS_OFF_POPUP_W_SOUND
	  #define LCF_HDA_DISP_HANDS_OFF_POPUP_W_SOUND	(6)
	#endif
	#ifndef   LCF_HDA_YS_AUTO_OFF
	  #define LCF_HDA_YS_AUTO_OFF	(7)
	#endif

/* typedef LCF_e_CLUHdaLfaSymbolState_t */
	#ifndef   LCF_HDA_SYMB_OFF
	  #define LCF_HDA_SYMB_OFF	(0)
	#endif
	#ifndef   LCF_HDA_SYMB_GRAY
	  #define LCF_HDA_SYMB_GRAY	(1)
	#endif
	#ifndef   LCF_HDA_SYMB_GREEN
	  #define LCF_HDA_SYMB_GREEN	(2)
	#endif
	#ifndef   LCF_HDA_SYMB_GREEN_BLINK
	  #define LCF_HDA_SYMB_GREEN_BLINK	(3)
	#endif

/* typedef LCF_e_LatCtrlMod_t */
	#ifndef   LCF_TJA_LATCTRLMD_PASSIVE
	  #define LCF_TJA_LATCTRLMD_PASSIVE	(0)
	#endif
	#ifndef   LCF_TJA_LATCTRLMD_LNCENTRING
	  #define LCF_TJA_LATCTRLMD_LNCENTRING	(1)
	#endif
	#ifndef   LCF_TJA_LATCTRLMD_OBJFOLLWNG
	  #define LCF_TJA_LATCTRLMD_OBJFOLLWNG	(2)
	#endif
	#ifndef   LCF_TJA_LATCTRLMD_COMBINED
	  #define LCF_TJA_LATCTRLMD_COMBINED	(3)
	#endif
	#ifndef   LCF_TJA_LATCTRLMD_RQLNCENTRING
	  #define LCF_TJA_LATCTRLMD_RQLNCENTRING	(4)
	#endif
	#ifndef   LCF_TJA_LATCTRLMD_RQOBJFOLLWNG
	  #define LCF_TJA_LATCTRLMD_RQOBJFOLLWNG	(5)
	#endif
	#ifndef   LCF_TJA_LATCTRLMD_RQCOMBINED
	  #define LCF_TJA_LATCTRLMD_RQCOMBINED	(6)
	#endif
	#ifndef   LCF_TJA_LATCTRLMD_INVALID
	  #define LCF_TJA_LATCTRLMD_INVALID	(15)
	#endif

/* typedef DrvAttWarnQualifier__nu_t */
	#ifndef   LCF_DRV_ATTENTION_WRNG_STATE_NO_WARNING
	  #define LCF_DRV_ATTENTION_WRNG_STATE_NO_WARNING	(0)
	#endif
	#ifndef   LCF_DRV_ATTENTION_WRNG_STATE_ATTENTIVNESS_REQUEST
	  #define LCF_DRV_ATTENTION_WRNG_STATE_ATTENTIVNESS_REQUEST	(1)
	#endif
	#ifndef   LCF_DRV_ATTENTION_WRNG_STATE_TAKE_OVER_REQUEST
	  #define LCF_DRV_ATTENTION_WRNG_STATE_TAKE_OVER_REQUEST	(2)
	#endif
	#ifndef   LCF_DRV_ATTENTION_WRNG_STATE_DEGRADATION_TRIGGERED
	  #define LCF_DRV_ATTENTION_WRNG_STATE_DEGRADATION_TRIGGERED	(3)
	#endif

/* typedef LCF_e_CustSpecLCAState_t */
	#ifndef   LCF_LCA_CUST_OFF
	  #define LCF_LCA_CUST_OFF	(0)
	#endif
	#ifndef   LCF_LCA_CUST_STANDBY
	  #define LCF_LCA_CUST_STANDBY	(1)
	#endif
	#ifndef   LCF_LCA_CUST_ACTIVE
	  #define LCF_LCA_CUST_ACTIVE	(2)
	#endif
	#ifndef   LCF_LCA_CUST_OVERRIDE
	  #define LCF_LCA_CUST_OVERRIDE	(3)
	#endif

/* typedef LCF_e_CustSpecLCAErrorState_t */
	#ifndef   LCF_LCA_ERROR_NO_ERROR
	  #define LCF_LCA_ERROR_NO_ERROR	(0)
	#endif
	#ifndef   LCF_LCA_ERROR_PERF_DEGRAD
	  #define LCF_LCA_ERROR_PERF_DEGRAD	(1)
	#endif
	#ifndef   LCF_LCA_ERROR_SYS_TEMP_UNAVAIL
	  #define LCF_LCA_ERROR_SYS_TEMP_UNAVAIL	(2)
	#endif
	#ifndef   LCF_LCA_ERROR_SERVICE_REQ
	  #define LCF_LCA_ERROR_SERVICE_REQ	(3)
	#endif

/* typedef HMOSGW_TJALatCntlMdSW_nu_t */
	#ifndef   LCF_TJASTM_LATCTRLMDSW_NC
	  #define LCF_TJASTM_LATCTRLMDSW_NC	(0)
	#endif
	#ifndef   LCF_TJASTM_LATCTRLMDSW_LC
	  #define LCF_TJASTM_LATCTRLMDSW_LC	(1)
	#endif
	#ifndef   LCF_TJASTM_LATCTRLMDSW_OF
	  #define LCF_TJASTM_LATCTRLMDSW_OF	(2)
	#endif

/* typedef LCF_e_LaDMCStatus_t */
	#ifndef   LCF_LADMC_OFF
	  #define LCF_LADMC_OFF	(0)
	#endif
	#ifndef   LCF_LADMC_ON
	  #define LCF_LADMC_ON	(1)
	#endif
	#ifndef   LCF_LADMC_DRV_SUPPORT_STEER
	  #define LCF_LADMC_DRV_SUPPORT_STEER	(2)
	#endif
	#ifndef   LCF_LADMC_DRV_COUNTER_STEER
	  #define LCF_LADMC_DRV_COUNTER_STEER	(3)
	#endif
	#ifndef   LCF_LADMC_PERM_DISABLED
	  #define LCF_LADMC_PERM_DISABLED	(4)
	#endif
	#ifndef   LCF_LADMC_TEMP_DISABLED
	  #define LCF_LADMC_TEMP_DISABLED	(5)
	#endif
	#ifndef   LCF_LADMC_REQUEST
	  #define LCF_LADMC_REQUEST	(6)
	#endif

/* typedef LCF_e_LKASActToi_t */
	#ifndef   LCF_DEACTIVATE_TOI
	  #define LCF_DEACTIVATE_TOI	(0)
	#endif
	#ifndef   LCF_ACTIVATE_TOI
	  #define LCF_ACTIVATE_TOI	(1)
	#endif

/* typedef LCF_e_LKASToiFlt_t */
	#ifndef   LCF_NO_FAULT
	  #define LCF_NO_FAULT	(0)
	#endif
	#ifndef   LCF_FAULT_PRESENT
	  #define LCF_FAULT_PRESENT	(1)
	#endif

/* typedef LaKMC_QuTgtVehCtrl__nu_t */
	#ifndef   LCF_DONOT_REALIZE_TGT_VALUE_QUALIFIER
	  #define LCF_DONOT_REALIZE_TGT_VALUE_QUALIFIER	(4)
	#endif
	#ifndef   LCF_REALIZE_CRV_QUALIFIER
	  #define LCF_REALIZE_CRV_QUALIFIER	(8)
	#endif
	#ifndef   LCF_REALIZE_CRV_SIDE_SLIP_QUALIFIER
	  #define LCF_REALIZE_CRV_SIDE_SLIP_QUALIFIER	(9)
	#endif

/* typedef LCF_e_ControllingFunction_t */
	#ifndef   LCF_OFF
	  #define LCF_OFF	(0)
	#endif
	#ifndef   LCF_LKA
	  #define LCF_LKA	(1)
	#endif
	#ifndef   LCF_LDP
	  #define LCF_LDP	(2)
	#endif
	#ifndef   LCF_LDPOC
	  #define LCF_LDPOC	(3)
	#endif
	#ifndef   LCF_RDP
	  #define LCF_RDP	(4)
	#endif
	#ifndef   LCF_ALCA
	  #define LCF_ALCA	(5)
	#endif
	#ifndef   LCF_AOLC
	  #define LCF_AOLC	(6)
	#endif
	#ifndef   LCF_ESA
	  #define LCF_ESA	(7)
	#endif
	#ifndef   LCF_TJA
	  #define LCF_TJA	(8)
	#endif

/* typedef TrajServiceQualifier__nu_t */
	#ifndef   LCF_TRAJ_PLAN_LAT_CTRL_COORD_SERVICE_QU_COL_CHECK_CRIDR_LIMITS
	  #define LCF_TRAJ_PLAN_LAT_CTRL_COORD_SERVICE_QU_COL_CHECK_CRIDR_LIMITS	(0)
	#endif
	#ifndef   LCF_TRAJ_PLAN_LAT_CTRL_COORD_SERVICE_QU_COL_CHECK_OBJ
	  #define LCF_TRAJ_PLAN_LAT_CTRL_COORD_SERVICE_QU_COL_CHECK_OBJ	(1)
	#endif
	#ifndef   LCF_TRAJ_PLAN_LAT_CTRL_COORD_SERVICE_QU_FTIRE_CHECK
	  #define LCF_TRAJ_PLAN_LAT_CTRL_COORD_SERVICE_QU_FTIRE_CHECK	(2)
	#endif

/* typedef LCF_e_LcfCtrlAbort_t */
	#ifndef   LCF_DMC_NOABORT_REQUEST
	  #define LCF_DMC_NOABORT_REQUEST	(0)
	#endif
	#ifndef   LCF_DMC_ABORT_REQUEST
	  #define LCF_DMC_ABORT_REQUEST	(1)
	#endif

/* typedef TgtVehCtrlQualifier__nu_t */
	#ifndef   LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_DONOT_REALIZE_TGT_VALUE_QUALIFIER
	  #define LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_DONOT_REALIZE_TGT_VALUE_QUALIFIER	(4)
	#endif
	#ifndef   LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_REALIZE_CRV_QUALIFIER
	  #define LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_REALIZE_CRV_QUALIFIER	(8)
	#endif
	#ifndef   LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_REALIZE_CRV_SIDE_SLIP_QUALIFIER
	  #define LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_REALIZE_CRV_SIDE_SLIP_QUALIFIER	(9)
	#endif

/* typedef eOriginCoordinateSystem_t */
	#ifndef   ABD_CS_FRONT_AXLE
	  #define ABD_CS_FRONT_AXLE	(0)
	#endif
	#ifndef   ABD_CS_REAR_AXLE
	  #define ABD_CS_REAR_AXLE	(1)
	#endif
	#ifndef   ABD_CS_BUGFIX
	  #define ABD_CS_BUGFIX	(2147483647)
	#endif

/* typedef eParallelModelActive_t */
	#ifndef   ABD_PM_NOT_PARALLEL
	  #define ABD_PM_NOT_PARALLEL	(0)
	#endif
	#ifndef   ABD_PM_PARALLEL
	  #define ABD_PM_PARALLEL	(1)
	#endif
	#ifndef   ABD_PM_BUGFIX
	  #define ABD_PM_BUGFIX	(2147483647)
	#endif

/* typedef eLaneChange_t */
	#ifndef   ABD_LC_UNKNOWN
	  #define ABD_LC_UNKNOWN	(0)
	#endif
	#ifndef   ABD_LC_LEFT
	  #define ABD_LC_LEFT	(1)
	#endif
	#ifndef   ABD_LC_RIGHT
	  #define ABD_LC_RIGHT	(2)
	#endif
	#ifndef   ABD_LC_UNCHANGED
	  #define ABD_LC_UNCHANGED	(3)
	#endif
	#ifndef   ABD_LC_INVALID
	  #define ABD_LC_INVALID	(255)
	#endif

/* typedef eColor_t */
	#ifndef   ABD_MC_UNCLASSIFIED
	  #define ABD_MC_UNCLASSIFIED	(0)
	#endif
	#ifndef   ABD_MC_WHITE
	  #define ABD_MC_WHITE	(1)
	#endif
	#ifndef   ABD_MC_YELLOW
	  #define ABD_MC_YELLOW	(2)
	#endif
	#ifndef   ABD_MC_RED
	  #define ABD_MC_RED	(3)
	#endif
	#ifndef   ABD_MC_BLUE
	  #define ABD_MC_BLUE	(4)
	#endif
	#ifndef   ABD_MC_GREEN
	  #define ABD_MC_GREEN	(5)
	#endif
	#ifndef   ABD_MC_BUGFIX
	  #define ABD_MC_BUGFIX	(2147483647)
	#endif

/* typedef eType_t */
	#ifndef   ABD_MT_NO_LINE
	  #define ABD_MT_NO_LINE	(0)
	#endif
	#ifndef   ABD_MT_PAINTED_CONTINUOUS
	  #define ABD_MT_PAINTED_CONTINUOUS	(1)
	#endif
	#ifndef   ABD_MT_PAINTED_DASHED
	  #define ABD_MT_PAINTED_DASHED	(2)
	#endif
	#ifndef   ABD_MT_PAINTED_DECORATIVE
	  #define ABD_MT_PAINTED_DECORATIVE	(3)
	#endif
	#ifndef   ABD_MT_DOTTED_CONTINUOUS
	  #define ABD_MT_DOTTED_CONTINUOUS	(4)
	#endif
	#ifndef   ABD_MT_DOTTED_DASHED
	  #define ABD_MT_DOTTED_DASHED	(5)
	#endif
	#ifndef   ABD_MT_ELEVATED_CONTINUOUS
	  #define ABD_MT_ELEVATED_CONTINUOUS	(6)
	#endif
	#ifndef   ABD_MT_ELEVATED_DISCRETE
	  #define ABD_MT_ELEVATED_DISCRETE	(7)
	#endif
	#ifndef   ABD_MT_CURBSTONE
	  #define ABD_MT_CURBSTONE	(8)
	#endif
	#ifndef   ABD_MT_ROADEDGE
	  #define ABD_MT_ROADEDGE	(9)
	#endif
	#ifndef   ABD_MT_UNKNOWN
	  #define ABD_MT_UNKNOWN	(100)
	#endif
	#ifndef   ABD_MT_BUGFIX
	  #define ABD_MT_BUGFIX	(2147483647)
	#endif

/* typedef eLaneEventType_t */
	#ifndef   ABD_LE_IDLE
	  #define ABD_LE_IDLE	(0)
	#endif
	#ifndef   ABD_LE_FORK_EXIT
	  #define ABD_LE_FORK_EXIT	(1)
	#endif
	#ifndef   ABD_LE_FORK_ENTRY
	  #define ABD_LE_FORK_ENTRY	(2)
	#endif
	#ifndef   ABD_LE_FORK_UNKNOWN_OPEN
	  #define ABD_LE_FORK_UNKNOWN_OPEN	(3)
	#endif
	#ifndef   ABD_LE_FORK_UNKNOWN_CLOSE
	  #define ABD_LE_FORK_UNKNOWN_CLOSE	(4)
	#endif
	#ifndef   ABD_LE_CONSTRUCTION_START
	  #define ABD_LE_CONSTRUCTION_START	(5)
	#endif
	#ifndef   ABD_LE_CONSTRUCTION_STOP
	  #define ABD_LE_CONSTRUCTION_STOP	(6)
	#endif
	#ifndef   ABD_LE_PEDX_START
	  #define ABD_LE_PEDX_START	(7)
	#endif
	#ifndef   ABD_LE_PEDX_STOP
	  #define ABD_LE_PEDX_STOP	(8)
	#endif
	#ifndef   ABD_LE_BUGFIX
	  #define ABD_LE_BUGFIX	(2147483647)
	#endif

/* typedef eCoordinateSystem_t */
	#ifndef   LD_CS_FRONT_AXLE
	  #define LD_CS_FRONT_AXLE	(0)
	#endif
	#ifndef   LD_CS_REAR_AXLE
	  #define LD_CS_REAR_AXLE	(1)
	#endif
	#ifndef   LD_CS_BUGFIX
	  #define LD_CS_BUGFIX	(2147483647)
	#endif

/* typedef eParallelModel_t */
	#ifndef   LD_PM_NOT_PARALLEL
	  #define LD_PM_NOT_PARALLEL	(0)
	#endif
	#ifndef   LD_PM_PARALLEL
	  #define LD_PM_PARALLEL	(1)
	#endif
	#ifndef   LD_PM_BUGFIX
	  #define LD_PM_BUGFIX	(2147483647)
	#endif

/* typedef eSteeringSide_t */
	#ifndef   LD_SS_BOTH
	  #define LD_SS_BOTH	(0)
	#endif
	#ifndef   LD_SS_RIGHT
	  #define LD_SS_RIGHT	(1)
	#endif
	#ifndef   LD_SS_LEFT
	  #define LD_SS_LEFT	(2)
	#endif
	#ifndef   LD_SS_NONE
	  #define LD_SS_NONE	(3)
	#endif
	#ifndef   LD_SS_BUGFIX
	  #define LD_SS_BUGFIX	(2147483647)
	#endif

/* typedef aiMarkerTypes_t */
	#ifndef   LD_MT_CONTINUOUS
	  #define LD_MT_CONTINUOUS	(0)
	#endif
	#ifndef   LD_MT_DASHED
	  #define LD_MT_DASHED	(1)
	#endif
	#ifndef   LD_MT_RESERVED1
	  #define LD_MT_RESERVED1	(2)
	#endif
	#ifndef   LD_MT_RESERVED2
	  #define LD_MT_RESERVED2	(3)
	#endif
	#ifndef   LD_MT_NOLINEDETECTED
	  #define LD_MT_NOLINEDETECTED	(4)
	#endif
	#ifndef   LD_MT_UNCLASSIFIED
	  #define LD_MT_UNCLASSIFIED	(5)
	#endif
	#ifndef   LD_MT_DOTTED
	  #define LD_MT_DOTTED	(6)
	#endif
	#ifndef   LD_MT_DECORATION
	  #define LD_MT_DECORATION	(7)
	#endif
	#ifndef   LD_MT_SEPARATING
	  #define LD_MT_SEPARATING	(8)
	#endif
	#ifndef   LD_MT_NARROWDASHED
	  #define LD_MT_NARROWDASHED	(9)
	#endif
	#ifndef   LD_MT_LOWCURB
	  #define LD_MT_LOWCURB	(10)
	#endif
	#ifndef   LD_MT_HIGHCURB
	  #define LD_MT_HIGHCURB	(11)
	#endif
	#ifndef   LD_MT_CRASHBARRIER
	  #define LD_MT_CRASHBARRIER	(12)
	#endif
	#ifndef   LD_MT_WALL
	  #define LD_MT_WALL	(13)
	#endif
	#ifndef   LD_MT_ROADSHOULDER
	  #define LD_MT_ROADSHOULDER	(14)
	#endif
	#ifndef   LD_MT_BUGFIX
	  #define LD_MT_BUGFIX	(2147483647)
	#endif

/* typedef aiMarkerColors_t */
	#ifndef   LD_MC_WHITE
	  #define LD_MC_WHITE	(0)
	#endif
	#ifndef   LD_MC_YELLOW
	  #define LD_MC_YELLOW	(1)
	#endif
	#ifndef   LD_MC_RED
	  #define LD_MC_RED	(2)
	#endif
	#ifndef   LD_MC_BLUE
	  #define LD_MC_BLUE	(3)
	#endif
	#ifndef   LD_MC_GREEN
	  #define LD_MC_GREEN	(4)
	#endif
	#ifndef   LD_MC_UNKNOWN
	  #define LD_MC_UNKNOWN	(5)
	#endif
	#ifndef   LD_MC_BUGFIX
	  #define LD_MC_BUGFIX	(2147483647)
	#endif

/* typedef eEventType_t */
	#ifndef   LD_LE_IDLE
	  #define LD_LE_IDLE	(0)
	#endif
	#ifndef   LD_LE_FORK_EXIT
	  #define LD_LE_FORK_EXIT	(1)
	#endif
	#ifndef   LD_LE_FORK_ENTRY
	  #define LD_LE_FORK_ENTRY	(2)
	#endif
	#ifndef   LD_LE_FORK_UNKNOWN_OPEN
	  #define LD_LE_FORK_UNKNOWN_OPEN	(3)
	#endif
	#ifndef   LD_LE_FORK_UNKNOWN_CLOSE
	  #define LD_LE_FORK_UNKNOWN_CLOSE	(4)
	#endif
	#ifndef   LD_LE_CONSTRUCTION_START
	  #define LD_LE_CONSTRUCTION_START	(5)
	#endif
	#ifndef   LD_LE_CONSTRUCTION_CLOSE
	  #define LD_LE_CONSTRUCTION_CLOSE	(6)
	#endif
	#ifndef   LD_LE_BUGFIX
	  #define LD_LE_BUGFIX	(2147483647)
	#endif

/* typedef LSD_e_TrafficStyle */
	#ifndef   LSD_TRAFFIC_STYLE_UNKNOWN
	  #define LSD_TRAFFIC_STYLE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_TRAFFIC_STYLE_RIGHT_HAND_TRAFFIC
	  #define LSD_TRAFFIC_STYLE_RIGHT_HAND_TRAFFIC	(1)
	#endif
	#ifndef   LSD_TRAFFIC_STYLE_LEFT_HAND_TRAFFIC
	  #define LSD_TRAFFIC_STYLE_LEFT_HAND_TRAFFIC	(2)
	#endif

/* typedef LSD_e_Cpar_HeadlightType */
	#ifndef   LSD_CPAR_HEADLIGHT_TYPE_UNKNOWN
	  #define LSD_CPAR_HEADLIGHT_TYPE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_CPAR_HEADLIGHT_TYPE_HALOGEN
	  #define LSD_CPAR_HEADLIGHT_TYPE_HALOGEN	(1)
	#endif
	#ifndef   LSD_CPAR_HEADLIGHT_TYPE_XENON
	  #define LSD_CPAR_HEADLIGHT_TYPE_XENON	(2)
	#endif
	#ifndef   LSD_CPAR_HEADLIGHT_TYPE_LED
	  #define LSD_CPAR_HEADLIGHT_TYPE_LED	(3)
	#endif
	#ifndef   LSD_CPAR_HEADLIGHT_TYPE_PIXEL
	  #define LSD_CPAR_HEADLIGHT_TYPE_PIXEL	(4)
	#endif
	#ifndef   LSD_CPAR_HEADLIGHT_TYPE_LASER
	  #define LSD_CPAR_HEADLIGHT_TYPE_LASER	(5)
	#endif

/* typedef LSD_e_Cpar_ConfigTestMode */
	#ifndef   LSD_CPAR_CONFIG_TEST_MODE_UNKNOWN
	  #define LSD_CPAR_CONFIG_TEST_MODE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_CPAR_CONFIG_TEST_MODE_INACTIVE
	  #define LSD_CPAR_CONFIG_TEST_MODE_INACTIVE	(1)
	#endif
	#ifndef   LSD_CPAR_CONFIG_TEST_MODE_SAE
	  #define LSD_CPAR_CONFIG_TEST_MODE_SAE	(2)
	#endif
	#ifndef   LSD_CPAR_CONFIG_TEST_MODE_SEG_ALWAYS_ON
	  #define LSD_CPAR_CONFIG_TEST_MODE_SEG_ALWAYS_ON	(3)
	#endif
	#ifndef   LSD_CPAR_CONFIG_TEST_MODE_FOV
	  #define LSD_CPAR_CONFIG_TEST_MODE_FOV	(4)
	#endif
	#ifndef   LSD_CPAR_CONFIG_TEST_MODE_LAB
	  #define LSD_CPAR_CONFIG_TEST_MODE_LAB	(5)
	#endif
	#ifndef   LSD_CPAR_CONFIG_TEST_MODE_1
	  #define LSD_CPAR_CONFIG_TEST_MODE_1	(6)
	#endif
	#ifndef   LSD_CPAR_CONFIG_TEST_MODE_2
	  #define LSD_CPAR_CONFIG_TEST_MODE_2	(7)
	#endif

/* typedef LSD_e_Cpar_ConfigCityDetection */
	#ifndef   LSD_CPAR_CONFIG_CITY_DETECTION_UNKNOWN
	  #define LSD_CPAR_CONFIG_CITY_DETECTION_UNKNOWN	(0)
	#endif
	#ifndef   LSD_CPAR_CONFIG_CITY_DETECTION_INACTIVE
	  #define LSD_CPAR_CONFIG_CITY_DETECTION_INACTIVE	(1)
	#endif
	#ifndef   LSD_CPAR_CONFIG_CITY_DETECTION_ACTIVE
	  #define LSD_CPAR_CONFIG_CITY_DETECTION_ACTIVE	(2)
	#endif

/* typedef LSD_e_Cpar_ConfigTunnelDetection */
	#ifndef   LSD_CPAR_CONFIG_TUNNEL_DETECTION_UNKNOWN
	  #define LSD_CPAR_CONFIG_TUNNEL_DETECTION_UNKNOWN	(0)
	#endif
	#ifndef   LSD_CPAR_CONFIG_TUNNEL_DETECTION_INACTIVE
	  #define LSD_CPAR_CONFIG_TUNNEL_DETECTION_INACTIVE	(1)
	#endif
	#ifndef   LSD_CPAR_CONFIG_TUNNEL_DETECTION_ACTIVE
	  #define LSD_CPAR_CONFIG_TUNNEL_DETECTION_ACTIVE	(2)
	#endif

/* typedef LSD_e_Cpar_CountryCode */
	#ifndef   LSD_CPAR_COUNTRY_CODE_UNKNOWN
	  #define LSD_CPAR_COUNTRY_CODE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_CPAR_COUNTRY_CODE_DEFAULT
	  #define LSD_CPAR_COUNTRY_CODE_DEFAULT	(1)
	#endif
	#ifndef   LSD_CPAR_COUNTRY_CODE_JAPAN
	  #define LSD_CPAR_COUNTRY_CODE_JAPAN	(2)
	#endif
	#ifndef   LSD_CPAR_COUNTRY_CODE_KOREA
	  #define LSD_CPAR_COUNTRY_CODE_KOREA	(3)
	#endif
	#ifndef   LSD_CPAR_COUNTRY_CODE_CHINA
	  #define LSD_CPAR_COUNTRY_CODE_CHINA	(4)
	#endif
	#ifndef   LSD_CPAR_COUNTRY_CODE_AUSTRALIA
	  #define LSD_CPAR_COUNTRY_CODE_AUSTRALIA	(5)
	#endif
	#ifndef   LSD_CPAR_COUNTRY_CODE_US
	  #define LSD_CPAR_COUNTRY_CODE_US	(6)
	#endif

/* typedef LSD_e_Nvm_TrafficStyleLearningState */
	#ifndef   LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_UNKNOWN
	  #define LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_RIGHT_HAND_TRAFFIC_LEVEL_1
	  #define LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_RIGHT_HAND_TRAFFIC_LEVEL_1	(1)
	#endif
	#ifndef   LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_RIGHT_HAND_TRAFFIC_LEVEL_2
	  #define LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_RIGHT_HAND_TRAFFIC_LEVEL_2	(2)
	#endif
	#ifndef   LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_RIGHT_HAND_TRAFFIC_LEVEL_3
	  #define LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_RIGHT_HAND_TRAFFIC_LEVEL_3	(3)
	#endif
	#ifndef   LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_LEFT_HAND_TRAFFIC_LEVEL_1
	  #define LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_LEFT_HAND_TRAFFIC_LEVEL_1	(4)
	#endif
	#ifndef   LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_LEFT_HAND_TRAFFIC_LEVEL_2
	  #define LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_LEFT_HAND_TRAFFIC_LEVEL_2	(5)
	#endif
	#ifndef   LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_LEFT_HAND_TRAFFIC_LEVEL_3
	  #define LSD_NVM_TRAFFIC_STYLE_LEARNING_STATE_LEFT_HAND_TRAFFIC_LEVEL_3	(6)
	#endif

/* typedef LSD_e_LightList_SegmentationMode */
	#ifndef   LSD_LIGHT_LIST_SEGMENTATION_MODE_UNKNOWN
	  #define LSD_LIGHT_LIST_SEGMENTATION_MODE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_LIGHT_LIST_SEGMENTATION_MODE_DAY_NORMAL
	  #define LSD_LIGHT_LIST_SEGMENTATION_MODE_DAY_NORMAL	(1)
	#endif
	#ifndef   LSD_LIGHT_LIST_SEGMENTATION_MODE_DAY_POOR_COLOR
	  #define LSD_LIGHT_LIST_SEGMENTATION_MODE_DAY_POOR_COLOR	(2)
	#endif
	#ifndef   LSD_LIGHT_LIST_SEGMENTATION_MODE_DAY_SAT_NOISE
	  #define LSD_LIGHT_LIST_SEGMENTATION_MODE_DAY_SAT_NOISE	(3)
	#endif
	#ifndef   LSD_LIGHT_LIST_SEGMENTATION_MODE_DAY_SUN_REFLECTION
	  #define LSD_LIGHT_LIST_SEGMENTATION_MODE_DAY_SUN_REFLECTION	(4)
	#endif
	#ifndef   LSD_LIGHT_LIST_SEGMENTATION_MODE_DAY_SUN_REFLECTION_SAT_NOISE
	  #define LSD_LIGHT_LIST_SEGMENTATION_MODE_DAY_SUN_REFLECTION_SAT_NOISE	(5)
	#endif
	#ifndef   LSD_LIGHT_LIST_SEGMENTATION_MODE_TWILIGHT1
	  #define LSD_LIGHT_LIST_SEGMENTATION_MODE_TWILIGHT1	(6)
	#endif
	#ifndef   LSD_LIGHT_LIST_SEGMENTATION_MODE_TWILIGHT2
	  #define LSD_LIGHT_LIST_SEGMENTATION_MODE_TWILIGHT2	(7)
	#endif
	#ifndef   LSD_LIGHT_LIST_SEGMENTATION_MODE_TWILIGHT3
	  #define LSD_LIGHT_LIST_SEGMENTATION_MODE_TWILIGHT3	(8)
	#endif
	#ifndef   LSD_LIGHT_LIST_SEGMENTATION_MODE_NIGHT
	  #define LSD_LIGHT_LIST_SEGMENTATION_MODE_NIGHT	(9)
	#endif

/* typedef LSD_e_Light_Color */
	#ifndef   LSD_LIGHT_COLOR_UNKNOWN
	  #define LSD_LIGHT_COLOR_UNKNOWN	(0)
	#endif
	#ifndef   LSD_LIGHT_COLOR_WHITE
	  #define LSD_LIGHT_COLOR_WHITE	(1)
	#endif
	#ifndef   LSD_LIGHT_COLOR_RED
	  #define LSD_LIGHT_COLOR_RED	(2)
	#endif
	#ifndef   LSD_LIGHT_COLOR_ORANGE
	  #define LSD_LIGHT_COLOR_ORANGE	(3)
	#endif
	#ifndef   LSD_LIGHT_COLOR_YELLOW
	  #define LSD_LIGHT_COLOR_YELLOW	(4)
	#endif
	#ifndef   LSD_LIGHT_COLOR_GREEN
	  #define LSD_LIGHT_COLOR_GREEN	(5)
	#endif

/* typedef LSD_e_Light_StatusBits */
	#ifndef   LSD_LIGHT_STATUS_BIT_NONE
	  #define LSD_LIGHT_STATUS_BIT_NONE	(0)
	#endif
	#ifndef   LSD_LIGHT_STATUS_BIT_LED
	  #define LSD_LIGHT_STATUS_BIT_LED	(1)
	#endif
	#ifndef   LSD_LIGHT_STATUS_BIT_DEFECT_PIXEL
	  #define LSD_LIGHT_STATUS_BIT_DEFECT_PIXEL	(2)
	#endif
	#ifndef   LSD_LIGHT_STATUS_BIT_SATURATED
	  #define LSD_LIGHT_STATUS_BIT_SATURATED	(4)
	#endif
	#ifndef   LSD_LIGHT_STATUS_BIT_POTENTIAL_PAIR_FAR_AWAY
	  #define LSD_LIGHT_STATUS_BIT_POTENTIAL_PAIR_FAR_AWAY	(8)
	#endif
	#ifndef   LSD_LIGHT_STATUS_BIT_FOUND_BY_SEG_INTENSITY
	  #define LSD_LIGHT_STATUS_BIT_FOUND_BY_SEG_INTENSITY	(16)
	#endif
	#ifndef   LSD_LIGHT_STATUS_BIT_FOUND_BY_SEG_COLOR
	  #define LSD_LIGHT_STATUS_BIT_FOUND_BY_SEG_COLOR	(32)
	#endif
	#ifndef   LSD_LIGHT_STATUS_BIT_FOUND_IN_ODD_IMAGE
	  #define LSD_LIGHT_STATUS_BIT_FOUND_IN_ODD_IMAGE	(64)
	#endif
	#ifndef   LSD_LIGHT_STATUS_BIT_FOUND_IN_EVEN_IMAGE
	  #define LSD_LIGHT_STATUS_BIT_FOUND_IN_EVEN_IMAGE	(128)
	#endif

/* typedef LSD_e_LightObject_AttributesStatusBits */
	#ifndef   LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_NONE
	  #define LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_NONE	(0)
	#endif
	#ifndef   LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED
	  #define LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_WILL_BE_REMOVED	(1)
	#endif
	#ifndef   LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_TRUCK_LIGHT
	  #define LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_TRUCK_LIGHT	(2)
	#endif
	#ifndef   LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE
	  #define LSD_LIGHT_OBJECT_ATTRIBUTES_STATUS_BIT_BRIGHT_NON_VEHICLE	(4)
	#endif

/* typedef LSD_e_EnvironmentData_BrightnessState */
	#ifndef   LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_UNKNOWN
	  #define LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY
	  #define LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_DAY	(1)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_1
	  #define LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_1	(2)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_2
	  #define LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_2	(3)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3
	  #define LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_TWILIGHT_3	(4)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT
	  #define LSD_ENVIRONMENT_DATA_BRIGHTNESS_STATE_NIGHT	(5)
	#endif

/* typedef LSD_e_EnvironmentData_CityState */
	#ifndef   LSD_ENVIRONMENT_DATA_CITY_STATE_UNKNOWN
	  #define LSD_ENVIRONMENT_DATA_CITY_STATE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_CITY_STATE_NONE
	  #define LSD_ENVIRONMENT_DATA_CITY_STATE_NONE	(1)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE
	  #define LSD_ENVIRONMENT_DATA_CITY_STATE_MAYBE	(2)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED
	  #define LSD_ENVIRONMENT_DATA_CITY_STATE_DETECTED	(3)
	#endif

/* typedef LSD_e_EnvironmentData_TunnelState */
	#ifndef   LSD_ENVIRONMENT_DATA_TUNNEL_STATE_UNKNOWN
	  #define LSD_ENVIRONMENT_DATA_TUNNEL_STATE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_TUNNEL_STATE_NONE
	  #define LSD_ENVIRONMENT_DATA_TUNNEL_STATE_NONE	(1)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_TUNNEL_STATE_UPFRONT
	  #define LSD_ENVIRONMENT_DATA_TUNNEL_STATE_UPFRONT	(2)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_TUNNEL_STATE_INSIDE
	  #define LSD_ENVIRONMENT_DATA_TUNNEL_STATE_INSIDE	(3)
	#endif

/* typedef LSD_e_EnvironmentData_HighwayState */
	#ifndef   LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_UNKNOWN
	  #define LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE
	  #define LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_NONE	(1)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED
	  #define LSD_ENVIRONMENT_DATA_HIGHWAY_STATE_DETECTED	(2)
	#endif

/* typedef LSD_e_EnvironmentData_HighReflectorDensityState */
	#ifndef   LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_UNKNOWN
	  #define LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_UNKNOWN	(0)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE
	  #define LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_NONE	(1)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_DETECTED
	  #define LSD_ENVIRONMENT_DATA_HIGH_REFLECTOR_DENSITY_STATE_DETECTED	(2)
	#endif

/* typedef MapRteFuncState_t */
	#ifndef   MAP_RTE_FUNC_STATE_SNA
	  #define MAP_RTE_FUNC_STATE_SNA	(0)
	#endif
	#ifndef   MAP_RTE_FUNC_STATE_ON
	  #define MAP_RTE_FUNC_STATE_ON	(1)
	#endif
	#ifndef   MAP_RTE_FUNC_STATE_OFF
	  #define MAP_RTE_FUNC_STATE_OFF	(2)
	#endif

/* typedef MAPProvider_t */
	#ifndef   MAP_RTE_PROVIDER_UNKNOWN
	  #define MAP_RTE_PROVIDER_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_PROVIDER_TELEATLAS
	  #define MAP_RTE_PROVIDER_TELEATLAS	(1)
	#endif
	#ifndef   MAP_RTE_PROVIDER_NAVTEQ
	  #define MAP_RTE_PROVIDER_NAVTEQ	(2)
	#endif
	#ifndef   MAP_RTE_PROVIDER_ZENRIN
	  #define MAP_RTE_PROVIDER_ZENRIN	(3)
	#endif
	#ifndef   MAP_RTE_PROVIDER_SNA
	  #define MAP_RTE_PROVIDER_SNA	(4)
	#endif

/* typedef MapRteOutputTrafficStyle_T */
	#ifndef   MAP_RTE_TRAFFIC_STYLE_UNKNOWN
	  #define MAP_RTE_TRAFFIC_STYLE_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_TRAFFIC_STYLE_RIGHTHAND
	  #define MAP_RTE_TRAFFIC_STYLE_RIGHTHAND	(1)
	#endif
	#ifndef   MAP_RTE_TRAFFIC_STYLE_LEFTHAND
	  #define MAP_RTE_TRAFFIC_STYLE_LEFTHAND	(2)
	#endif
	#ifndef   MAP_RTE_TRAFFIC_STYLE_SNA
	  #define MAP_RTE_TRAFFIC_STYLE_SNA	(3)
	#endif

/* typedef MapRteOutputLocationType_t */
	#ifndef   MAP_RTE_LCT_UNKNOWN
	  #define MAP_RTE_LCT_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_LCT_TUNNEL
	  #define MAP_RTE_LCT_TUNNEL	(1)
	#endif
	#ifndef   MAP_RTE_LCT_INTERSECTION
	  #define MAP_RTE_LCT_INTERSECTION	(2)
	#endif
	#ifndef   MAP_RTE_LCT_ROUNDABOUT
	  #define MAP_RTE_LCT_ROUNDABOUT	(3)
	#endif
	#ifndef   MAP_RTE_LCT_TOLLSTATION
	  #define MAP_RTE_LCT_TOLLSTATION	(4)
	#endif
	#ifndef   MAP_RTE_LCT_LEFT_EXIT_RAMP
	  #define MAP_RTE_LCT_LEFT_EXIT_RAMP	(5)
	#endif
	#ifndef   MAP_RTE_LCT_RIGHT_EXIT_RAMP
	  #define MAP_RTE_LCT_RIGHT_EXIT_RAMP	(6)
	#endif
	#ifndef   MAP_RTE_LCT_LEFT_ENTERING_RAMP
	  #define MAP_RTE_LCT_LEFT_ENTERING_RAMP	(7)
	#endif
	#ifndef   MAP_RTE_LCT_RIGHT_ENTERING_RAMP
	  #define MAP_RTE_LCT_RIGHT_ENTERING_RAMP	(8)
	#endif

/* typedef MapRteOutputBuildUpArea_t */
	#ifndef   MAP_RTE_BUILD_UP_AREA_UNKNOWN
	  #define MAP_RTE_BUILD_UP_AREA_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_BUILD_UP_AREA_OUTSIDE
	  #define MAP_RTE_BUILD_UP_AREA_OUTSIDE	(1)
	#endif
	#ifndef   MAP_RTE_BUILD_UP_AREA_INSIDE
	  #define MAP_RTE_BUILD_UP_AREA_INSIDE	(2)
	#endif
	#ifndef   MAP_RTE_BUILD_UP_AREA_SNA
	  #define MAP_RTE_BUILD_UP_AREA_SNA	(3)
	#endif

/* typedef MapRteOutputVarSignPosition_t */
	#ifndef   MAP_RTE_VAR_SIGN_POS_UNKNOWN
	  #define MAP_RTE_VAR_SIGN_POS_UNKNOWN	(1)
	#endif
	#ifndef   MAP_RTE_VAR_SIGN_POS_LEFT
	  #define MAP_RTE_VAR_SIGN_POS_LEFT	(2)
	#endif
	#ifndef   MAP_RTE_VAR_SIGN_POS_RIGHT
	  #define MAP_RTE_VAR_SIGN_POS_RIGHT	(4)
	#endif
	#ifndef   MAP_RTE_VAR_SIGN_POS_ABOVE
	  #define MAP_RTE_VAR_SIGN_POS_ABOVE	(8)
	#endif
	#ifndef   MAP_RTE_VAR_SIGN_POS_EMLANE
	  #define MAP_RTE_VAR_SIGN_POS_EMLANE	(16)
	#endif
	#ifndef   MAP_RTE_VAR_SIGN_POS_1ST_LANE
	  #define MAP_RTE_VAR_SIGN_POS_1ST_LANE	(32)
	#endif
	#ifndef   MAP_RTE_VAR_SIGN_POS_2ND_LANE
	  #define MAP_RTE_VAR_SIGN_POS_2ND_LANE	(64)
	#endif
	#ifndef   MAP_RTE_VAR_SIGN_POS_3RD_LANE
	  #define MAP_RTE_VAR_SIGN_POS_3RD_LANE	(128)
	#endif
	#ifndef   MAP_RTE_VAR_SIGN_POS_4TH_LANE
	  #define MAP_RTE_VAR_SIGN_POS_4TH_LANE	(256)
	#endif
	#ifndef   MAP_RTE_VAR_SIGN_POS_5TH_LANE
	  #define MAP_RTE_VAR_SIGN_POS_5TH_LANE	(512)
	#endif

/* typedef MapRteInputAv2Type_t */
	#ifndef   MAP_RTE_AV2MSG_INVALID
	  #define MAP_RTE_AV2MSG_INVALID	(0)
	#endif
	#ifndef   MAP_RTE_AV2MSG_POSITION
	  #define MAP_RTE_AV2MSG_POSITION	(1)
	#endif
	#ifndef   MAP_RTE_AV2MSG_SEGMENT
	  #define MAP_RTE_AV2MSG_SEGMENT	(2)
	#endif
	#ifndef   MAP_RTE_AV2MSG_STUB
	  #define MAP_RTE_AV2MSG_STUB	(3)
	#endif
	#ifndef   MAP_RTE_AV2MSG_PROFILE_SHORT
	  #define MAP_RTE_AV2MSG_PROFILE_SHORT	(4)
	#endif
	#ifndef   MAP_RTE_AV2MSG_PROFILE_LONG
	  #define MAP_RTE_AV2MSG_PROFILE_LONG	(5)
	#endif
	#ifndef   MAP_RTE_AV2MSG_METADATA
	  #define MAP_RTE_AV2MSG_METADATA	(6)
	#endif
	#ifndef   MAP_RTE_AV2MSG_RESERVED
	  #define MAP_RTE_AV2MSG_RESERVED	(7)
	#endif

/* typedef MapRteSpeedUnit_t */
	#ifndef   MAP_RTE_SPD_UNIT_UNKNOWN
	  #define MAP_RTE_SPD_UNIT_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_SPD_UNIT_KMH
	  #define MAP_RTE_SPD_UNIT_KMH	(1)
	#endif
	#ifndef   MAP_RTE_SPD_UNIT_MPH
	  #define MAP_RTE_SPD_UNIT_MPH	(2)
	#endif
	#ifndef   MAP_RTE_SPD_UNIT_SNA
	  #define MAP_RTE_SPD_UNIT_SNA	(3)
	#endif

/* typedef MapRteSpeedLimitSignType_t */
	#ifndef   MAP_RTE_SPD_LMT_STYPE_UNKNOWN
	  #define MAP_RTE_SPD_LMT_STYPE_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_STYPE_NDEF0
	  #define MAP_RTE_SPD_LMT_STYPE_NDEF0	(1)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_STYPE_LIM
	  #define MAP_RTE_SPD_LMT_STYPE_LIM	(2)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_STYPE_UNLIM
	  #define MAP_RTE_SPD_LMT_STYPE_UNLIM	(3)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_STYPE_TMP
	  #define MAP_RTE_SPD_LMT_STYPE_TMP	(4)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_STYPE_IMPL
	  #define MAP_RTE_SPD_LMT_STYPE_IMPL	(5)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_STYPE_CHNG
	  #define MAP_RTE_SPD_LMT_STYPE_CHNG	(6)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_STYPE_NDEF6
	  #define MAP_RTE_SPD_LMT_STYPE_NDEF6	(7)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_STYPE_SNA
	  #define MAP_RTE_SPD_LMT_STYPE_SNA	(15)
	#endif

/* typedef MapRteSpeedLimitValidity_t */
	#ifndef   MAP_RTE_SPD_LMT_VLD_UNKNOWN
	  #define MAP_RTE_SPD_LMT_VLD_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_UNLIM
	  #define MAP_RTE_SPD_LMT_VLD_UNLIM	(1)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_WET
	  #define MAP_RTE_SPD_LMT_VLD_WET	(2)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_ICY
	  #define MAP_RTE_SPD_LMT_VLD_ICY	(3)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_FOG
	  #define MAP_RTE_SPD_LMT_VLD_FOG	(4)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_TMP_UN
	  #define MAP_RTE_SPD_LMT_VLD_TMP_UN	(5)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_TMP_NA
	  #define MAP_RTE_SPD_LMT_VLD_TMP_NA	(6)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_TMP_A
	  #define MAP_RTE_SPD_LMT_VLD_TMP_A	(7)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_WEIGHT
	  #define MAP_RTE_SPD_LMT_VLD_WEIGHT	(8)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_VEHICLE
	  #define MAP_RTE_SPD_LMT_VLD_VEHICLE	(9)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_DARK
	  #define MAP_RTE_SPD_LMT_VLD_DARK	(10)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_DAY
	  #define MAP_RTE_SPD_LMT_VLD_DAY	(11)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_SCHOOL
	  #define MAP_RTE_SPD_LMT_VLD_SCHOOL	(12)
	#endif
	#ifndef   MAP_RTE_SPD_LMT_VLD_SNA
	  #define MAP_RTE_SPD_LMT_VLD_SNA	(15)
	#endif

/* typedef MapRteSpeedLimitSide_t */
	#ifndef   MAP_RTE_SPD_LIMIT_SIDE_UNKNOWN
	  #define MAP_RTE_SPD_LIMIT_SIDE_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_SPD_LIMIT_SIDE_LEFT
	  #define MAP_RTE_SPD_LIMIT_SIDE_LEFT	(1)
	#endif
	#ifndef   MAP_RTE_SPD_LIMIT_SIDE_RIGHT
	  #define MAP_RTE_SPD_LIMIT_SIDE_RIGHT	(2)
	#endif
	#ifndef   MAP_RTE_SPD_LIMIT_SIDE_SNA
	  #define MAP_RTE_SPD_LIMIT_SIDE_SNA	(3)
	#endif

/* typedef MapRteContextChangeType_t */
	#ifndef   MAP_RTE_CONTEXT_CHANGE_UNKNOWN
	  #define MAP_RTE_CONTEXT_CHANGE_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_CONTEXT_CHANGE_NO_CHANGE_AHEAD
	  #define MAP_RTE_CONTEXT_CHANGE_NO_CHANGE_AHEAD	(1)
	#endif
	#ifndef   MAP_RTE_CONTEXT_CHANGE_OUTSIDE_TO_INSIDE
	  #define MAP_RTE_CONTEXT_CHANGE_OUTSIDE_TO_INSIDE	(2)
	#endif
	#ifndef   MAP_RTE_CONTEXT_CHANGE_INSIDE_TO_OUTSIDE
	  #define MAP_RTE_CONTEXT_CHANGE_INSIDE_TO_OUTSIDE	(3)
	#endif

/* typedef MapRteFunctionalRoadClass_t */
	#ifndef   MAP_RTE_FRC_UNKNOWN
	  #define MAP_RTE_FRC_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_FRC1
	  #define MAP_RTE_FRC1	(1)
	#endif
	#ifndef   MAP_RTE_FRC2
	  #define MAP_RTE_FRC2	(2)
	#endif
	#ifndef   MAP_RTE_FRC3
	  #define MAP_RTE_FRC3	(3)
	#endif
	#ifndef   MAP_RTE_FRC4
	  #define MAP_RTE_FRC4	(4)
	#endif
	#ifndef   MAP_RTE_FRC5
	  #define MAP_RTE_FRC5	(5)
	#endif
	#ifndef   MAP_RTE_FRC6
	  #define MAP_RTE_FRC6	(6)
	#endif
	#ifndef   MAP_RTE_FRC_SNA
	  #define MAP_RTE_FRC_SNA	(7)
	#endif

/* typedef MapRteFormOfWay_t */
	#ifndef   MAP_RTE_FORM_OF_WAY_UNKNOWN
	  #define MAP_RTE_FORM_OF_WAY_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_CONTROLLED_ACCESS
	  #define MAP_RTE_FORM_OF_WAY_CONTROLLED_ACCESS	(1)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_MULTIPLY_DIGITIZED
	  #define MAP_RTE_FORM_OF_WAY_MULTIPLY_DIGITIZED	(2)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_SINGLE_CARRIAGEWAY
	  #define MAP_RTE_FORM_OF_WAY_SINGLE_CARRIAGEWAY	(3)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_ROUNDABOUT
	  #define MAP_RTE_FORM_OF_WAY_ROUNDABOUT	(4)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_STF
	  #define MAP_RTE_FORM_OF_WAY_STF	(5)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_RESERVED_6
	  #define MAP_RTE_FORM_OF_WAY_RESERVED_6	(6)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_RESERVED_7
	  #define MAP_RTE_FORM_OF_WAY_RESERVED_7	(7)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_PARALLEL_ROAD
	  #define MAP_RTE_FORM_OF_WAY_PARALLEL_ROAD	(8)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_RAMP_CONTROLLED_ACCESS
	  #define MAP_RTE_FORM_OF_WAY_RAMP_CONTROLLED_ACCESS	(9)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_RAMP_NO_CONTROLLED_ACCESS
	  #define MAP_RTE_FORM_OF_WAY_RAMP_NO_CONTROLLED_ACCESS	(10)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_FRONTAGE_ROAD
	  #define MAP_RTE_FORM_OF_WAY_FRONTAGE_ROAD	(11)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_ACCESS_PARKING
	  #define MAP_RTE_FORM_OF_WAY_ACCESS_PARKING	(12)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_ACCESS
	  #define MAP_RTE_FORM_OF_WAY_ACCESS	(13)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_PEDESTRIANS
	  #define MAP_RTE_FORM_OF_WAY_PEDESTRIANS	(14)
	#endif
	#ifndef   MAP_RTE_FORM_OF_WAY_SNA
	  #define MAP_RTE_FORM_OF_WAY_SNA	(15)
	#endif

/* typedef MapRteRouteNumberType_t */
	#ifndef   MAP_RTE_ROUTE_NUMBER_UNKNOWN
	  #define MAP_RTE_ROUTE_NUMBER_UNKNOWN	(1)
	#endif
	#ifndef   MAP_RTE_ROUTE_NUMBER_1
	  #define MAP_RTE_ROUTE_NUMBER_1	(2)
	#endif
	#ifndef   MAP_RTE_ROUTE_NUMBER_2
	  #define MAP_RTE_ROUTE_NUMBER_2	(4)
	#endif
	#ifndef   MAP_RTE_ROUTE_NUMBER_3
	  #define MAP_RTE_ROUTE_NUMBER_3	(8)
	#endif
	#ifndef   MAP_RTE_ROUTE_NUMBER_4
	  #define MAP_RTE_ROUTE_NUMBER_4	(16)
	#endif
	#ifndef   MAP_RTE_ROUTE_NUMBER_5
	  #define MAP_RTE_ROUTE_NUMBER_5	(32)
	#endif
	#ifndef   MAP_RTE_ROUTE_NUMBER_6
	  #define MAP_RTE_ROUTE_NUMBER_6	(64)
	#endif
	#ifndef   MAP_RTE_ROUTE_NUMBER_RESERVED
	  #define MAP_RTE_ROUTE_NUMBER_RESERVED	(128)
	#endif

/* typedef MapRteNumLanesDrivingDir_t */
	#ifndef   MAP_RTE_NUM_LANES_DRIVING_0
	  #define MAP_RTE_NUM_LANES_DRIVING_0	(0)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_DRIVING_1
	  #define MAP_RTE_NUM_LANES_DRIVING_1	(1)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_DRIVING_2
	  #define MAP_RTE_NUM_LANES_DRIVING_2	(2)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_DRIVING_3
	  #define MAP_RTE_NUM_LANES_DRIVING_3	(3)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_DRIVING_4
	  #define MAP_RTE_NUM_LANES_DRIVING_4	(4)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_DRIVING_5
	  #define MAP_RTE_NUM_LANES_DRIVING_5	(5)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_DRIVING_6_PLUS
	  #define MAP_RTE_NUM_LANES_DRIVING_6_PLUS	(6)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_DRIVING_UNKNOWN
	  #define MAP_RTE_NUM_LANES_DRIVING_UNKNOWN	(7)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_DRIVING_SNA
	  #define MAP_RTE_NUM_LANES_DRIVING_SNA	(15)
	#endif

/* typedef MapRteNumLanesOppositeDir_t */
	#ifndef   MAP_RTE_NUM_LANES_OPPOSITE_0
	  #define MAP_RTE_NUM_LANES_OPPOSITE_0	(0)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_OPPOSITE_1
	  #define MAP_RTE_NUM_LANES_OPPOSITE_1	(1)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_OPPOSITE_2_PLUS
	  #define MAP_RTE_NUM_LANES_OPPOSITE_2_PLUS	(2)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_OPPOSITE_UNKNOWN
	  #define MAP_RTE_NUM_LANES_OPPOSITE_UNKNOWN	(3)
	#endif
	#ifndef   MAP_RTE_NUM_LANES_OPPOSITE_SNA
	  #define MAP_RTE_NUM_LANES_OPPOSITE_SNA	(7)
	#endif

/* typedef MapRteOutputRoadChange_t */
	#ifndef   MAP_RTE_ROAD_CHANGE_UNKNOWN
	  #define MAP_RTE_ROAD_CHANGE_UNKNOWN	(0)
	#endif
	#ifndef   MAP_RTE_ROAD_CHANGE_LEFT_TURN
	  #define MAP_RTE_ROAD_CHANGE_LEFT_TURN	(1)
	#endif
	#ifndef   MAP_RTE_ROAD_CHANGE_RIGHT_TURN
	  #define MAP_RTE_ROAD_CHANGE_RIGHT_TURN	(2)
	#endif
	#ifndef   MAP_RTE_ROAD_CHANGE_LEFT_LEAVE
	  #define MAP_RTE_ROAD_CHANGE_LEFT_LEAVE	(3)
	#endif
	#ifndef   MAP_RTE_ROAD_CHANGE_RIGHT_LEAVE
	  #define MAP_RTE_ROAD_CHANGE_RIGHT_LEAVE	(4)
	#endif
	#ifndef   MAP_RTE_ROAD_CHANGE_ROUNDABOUT
	  #define MAP_RTE_ROAD_CHANGE_ROUNDABOUT	(5)
	#endif
	#ifndef   MAP_RTE_ROAD_CHANGE_UTURN
	  #define MAP_RTE_ROAD_CHANGE_UTURN	(6)
	#endif
	#ifndef   MAP_RTE_ROAD_CHANGE_SNA
	  #define MAP_RTE_ROAD_CHANGE_SNA	(7)
	#endif

/* typedef ePyramidLevel_t */
	#ifndef   IMAGE_PO
	  #define IMAGE_PO	(0)
	#endif
	#ifndef   IMAGE_P1
	  #define IMAGE_P1	(1)
	#endif
	#ifndef   IMAGE_P2
	  #define IMAGE_P2	(2)
	#endif
	#ifndef   IMAGE_P3
	  #define IMAGE_P3	(3)
	#endif
	#ifndef   IMAGE_P4
	  #define IMAGE_P4	(4)
	#endif

/* typedef eValidity_t */
	#ifndef   PC_NO_MATCH_FOUND
	  #define PC_NO_MATCH_FOUND	(0)
	#endif
	#ifndef   PC_VALID_MATCH
	  #define PC_VALID_MATCH	(1)
	#endif
	#ifndef   PC_EXCEEDED
	  #define PC_EXCEEDED	(2)
	#endif
	#ifndef   PC_MEAN_DISPARITY
	  #define PC_MEAN_DISPARITY	(3)
	#endif
	#ifndef   PC_INVALID_INPUT
	  #define PC_INVALID_INPUT	(4)
	#endif

/* typedef RumClass_t */
	#ifndef   RUM_CLASS_PED
	  #define RUM_CLASS_PED	(0)
	#endif
	#ifndef   RUM_CLASS_BIC
	  #define RUM_CLASS_BIC	(1)
	#endif
	#ifndef   RUM_CLASS_MB
	  #define RUM_CLASS_MB	(2)
	#endif
	#ifndef   RUM_CLASS_CAR
	  #define RUM_CLASS_CAR	(3)
	#endif
	#ifndef   RUM_CLASS_TRUCK
	  #define RUM_CLASS_TRUCK	(4)
	#endif
	#ifndef   RUM_CLASS_WHEEL
	  #define RUM_CLASS_WHEEL	(5)
	#endif
	#ifndef   RUM_CLASS_COUNT
	  #define RUM_CLASS_COUNT	(6)
	#endif

/* typedef RumPose_t */
	#ifndef   RUM_POSE_FRONT
	  #define RUM_POSE_FRONT	(0)
	#endif
	#ifndef   RUM_POSE_BACK
	  #define RUM_POSE_BACK	(1)
	#endif
	#ifndef   RUM_POSE_LEFT
	  #define RUM_POSE_LEFT	(2)
	#endif
	#ifndef   RUM_POSE_RIGHT
	  #define RUM_POSE_RIGHT	(3)
	#endif
	#ifndef   RUM_POSE_COUNT
	  #define RUM_POSE_COUNT	(4)
	#endif

/* typedef RumPedObjectClass_t */
	#ifndef   eRumPedObjectClass_Pedestrian
	  #define eRumPedObjectClass_Pedestrian	(1)
	#endif
	#ifndef   eRumPedObjectClass_BicycleSide
	  #define eRumPedObjectClass_BicycleSide	(2)
	#endif
	#ifndef   eRumPedObjectClass_BicycleFront
	  #define eRumPedObjectClass_BicycleFront	(3)
	#endif
	#ifndef   eRumPedObjectClassCount
	  #define eRumPedObjectClassCount	(4)
	#endif

/* typedef RumTemplateTrackingState_t */
	#ifndef   RUM_TEMPL_NO_REQUEST
	  #define RUM_TEMPL_NO_REQUEST	(0)
	#endif
	#ifndef   RUM_TEMPL_REQUEST_NO_UPD
	  #define RUM_TEMPL_REQUEST_NO_UPD	(1)
	#endif
	#ifndef   RUM_TEMPL_REQUEST_UPD
	  #define RUM_TEMPL_REQUEST_UPD	(3)
	#endif

/* typedef eRumVclObjPose_t */
	#ifndef   RUM_VCL_POSE_UNKNOWN
	  #define RUM_VCL_POSE_UNKNOWN	(0)
	#endif
	#ifndef   RUM_VCL_POSE_REAR
	  #define RUM_VCL_POSE_REAR	(1)
	#endif
	#ifndef   RUM_VCL_POSE_FRONT
	  #define RUM_VCL_POSE_FRONT	(2)
	#endif
	#ifndef   RUM_VCL_POSE_LEFT
	  #define RUM_VCL_POSE_LEFT	(3)
	#endif
	#ifndef   RUM_VCL_POSE_RIGHT
	  #define RUM_VCL_POSE_RIGHT	(4)
	#endif

/* typedef eRumVclMeasType_t */
	#ifndef   RUM_VCL_EDGE_CLASSIFIER
	  #define RUM_VCL_EDGE_CLASSIFIER	(0)
	#endif
	#ifndef   RUM_VCL_EDGE_TEMPLATE
	  #define RUM_VCL_EDGE_TEMPLATE	(1)
	#endif
	#ifndef   RUM_VCL_LIGHT_CLUSTER
	  #define RUM_VCL_LIGHT_CLUSTER	(2)
	#endif
	#ifndef   RUM_VCL_DIFF_HOM
	  #define RUM_VCL_DIFF_HOM	(3)
	#endif
	#ifndef   RUM_VCL_DIFF_TEMPL
	  #define RUM_VCL_DIFF_TEMPL	(4)
	#endif
	#ifndef   RUM_VCL_DIFF_NIGHT
	  #define RUM_VCL_DIFF_NIGHT	(5)
	#endif
	#ifndef   RUM_VCL_LIGHT_TEMPLATE
	  #define RUM_VCL_LIGHT_TEMPLATE	(6)
	#endif
	#ifndef   RUM_VCL_MAX_MEAS_TYPES
	  #define RUM_VCL_MAX_MEAS_TYPES	(7)
	#endif

/* typedef eRumVclLightCond_t */
	#ifndef   RUM_VCL_LC_DAY
	  #define RUM_VCL_LC_DAY	(0)
	#endif
	#ifndef   RUM_VCL_LC_NIGHT
	  #define RUM_VCL_LC_NIGHT	(1)
	#endif
	#ifndef   RUM_VCL_LC_TWILIGHT
	  #define RUM_VCL_LC_TWILIGHT	(2)
	#endif
	#ifndef   RUM_VCL_LC_UNKNOWN
	  #define RUM_VCL_LC_UNKNOWN	(3)
	#endif

/* typedef uTrackingFlags_t */
	#ifndef   RUM_IMG_TEMPL_NO_REQUEST
	  #define RUM_IMG_TEMPL_NO_REQUEST	(0)
	#endif
	#ifndef   RUM_IMG_TEMPL_REQUEST_NO_UPD
	  #define RUM_IMG_TEMPL_REQUEST_NO_UPD	(1)
	#endif
	#ifndef   RUM_IMG_TEMPL_REQUEST_UPD
	  #define RUM_IMG_TEMPL_REQUEST_UPD	(3)
	#endif

/* typedef uMotionFlags_t */
	#ifndef   RUM_WALK_BOOST_BUFFER
	  #define RUM_WALK_BOOST_BUFFER	(1)
	#endif
	#ifndef   RUM_WALK_BUFFER_NEW
	  #define RUM_WALK_BUFFER_NEW	(2)
	#endif
	#ifndef   RUM_WALK_BOOST_EXECUTE
	  #define RUM_WALK_BOOST_EXECUTE	(4)
	#endif
	#ifndef   RUM_BBQ_BUFFER
	  #define RUM_BBQ_BUFFER	(8)
	#endif
	#ifndef   RUM_BBQ_BUFFER_NEW
	  #define RUM_BBQ_BUFFER_NEW	(16)
	#endif
	#ifndef   RUM_BBQ_EXECUTE_TURN_LEFT
	  #define RUM_BBQ_EXECUTE_TURN_LEFT	(32)
	#endif
	#ifndef   RUM_BBQ_EXECUTE_TURN_RIGHT
	  #define RUM_BBQ_EXECUTE_TURN_RIGHT	(64)
	#endif
	#ifndef   RUM_BBQ_EXECUTE_BRAKE
	  #define RUM_BBQ_EXECUTE_BRAKE	(128)
	#endif

/* typedef uSearchFlags_t */
	#ifndef   RUM_CLASS_PED_BIT
	  #define RUM_CLASS_PED_BIT	(1)
	#endif
	#ifndef   RUM_CLASS_BIC_BIT
	  #define RUM_CLASS_BIC_BIT	(2)
	#endif
	#ifndef   RUM_CLASS_MB_BIT
	  #define RUM_CLASS_MB_BIT	(4)
	#endif
	#ifndef   RUM_CLASS_CAR_BIT
	  #define RUM_CLASS_CAR_BIT	(8)
	#endif
	#ifndef   RUM_CLASS_TRUCK_BIT
	  #define RUM_CLASS_TRUCK_BIT	(16)
	#endif
	#ifndef   RUM_CLASS_WHEEL_BIT
	  #define RUM_CLASS_WHEEL_BIT	(32)
	#endif

/* typedef bSearchPerformed_t */
	#ifndef   RUM_EM_OBJ_NOT_SCANNED
	  #define RUM_EM_OBJ_NOT_SCANNED	(0)
	#endif
	#ifndef   RUM_EM_OBJ_UNKNOWN_IF_SCANNED
	  #define RUM_EM_OBJ_UNKNOWN_IF_SCANNED	(1)
	#endif
	#ifndef   RUM_EM_OBJ_SCANNED
	  #define RUM_EM_OBJ_SCANNED	(2)
	#endif

/* typedef SrDefaultCountryCode_t */
	#ifndef   SR_RTE_DEFAULT_COUNTRY_UNKNOWN
	  #define SR_RTE_DEFAULT_COUNTRY_UNKNOWN	(0)
	#endif
	#ifndef   SR_RTE_DEFAULT_COUNTRY_ECE
	  #define SR_RTE_DEFAULT_COUNTRY_ECE	(1)
	#endif
	#ifndef   SR_RTE_DEFAULT_COUNTRY_GULF
	  #define SR_RTE_DEFAULT_COUNTRY_GULF	(2)
	#endif
	#ifndef   SR_RTE_DEFAULT_COUNTRY_USA
	  #define SR_RTE_DEFAULT_COUNTRY_USA	(3)
	#endif
	#ifndef   SR_RTE_DEFAULT_COUNTRY_CANADA
	  #define SR_RTE_DEFAULT_COUNTRY_CANADA	(4)
	#endif
	#ifndef   SR_RTE_DEFAULT_COUNTRY_ROW
	  #define SR_RTE_DEFAULT_COUNTRY_ROW	(5)
	#endif
	#ifndef   SR_RTE_DEFAULT_COUNTRY_JPCN
	  #define SR_RTE_DEFAULT_COUNTRY_JPCN	(6)
	#endif
	#ifndef   SR_RTE_DEFAULT_COUNTRY_OCEANIA
	  #define SR_RTE_DEFAULT_COUNTRY_OCEANIA	(7)
	#endif
	#ifndef   SR_RTE_DEFAULT_COUNTRY_INT_MAX
	  #define SR_RTE_DEFAULT_COUNTRY_INT_MAX	(2147483647)
	#endif

/* typedef SrFeatureMaster_t */
	#ifndef   SR_RTE_FEATURE_CONFIG_NONE
	  #define SR_RTE_FEATURE_CONFIG_NONE	(0)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_CITYLIMIT
	  #define SR_RTE_FEATURE_CONFIG_CITYLIMIT	(1)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_NOCIRCLE
	  #define SR_RTE_FEATURE_CONFIG_NOCIRCLE	(2)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_SKIPFRAME
	  #define SR_RTE_FEATURE_CONFIG_SKIPFRAME	(4)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_COLCLS
	  #define SR_RTE_FEATURE_CONFIG_COLCLS	(8)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_DISABLED
	  #define SR_RTE_FEATURE_CONFIG_DISABLED	(16)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_TRUCKSTICKER
	  #define SR_RTE_FEATURE_CONFIG_TRUCKSTICKER	(32)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_RECTANGULAR
	  #define SR_RTE_FEATURE_CONFIG_RECTANGULAR	(64)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_TRIANGULAR
	  #define SR_RTE_FEATURE_CONFIG_TRIANGULAR	(128)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_CIRCLE
	  #define SR_RTE_FEATURE_CONFIG_CIRCLE	(256)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_DIAMOND
	  #define SR_RTE_FEATURE_CONFIG_DIAMOND	(512)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_INV_TRIANGULAR
	  #define SR_RTE_FEATURE_CONFIG_INV_TRIANGULAR	(1024)
	#endif
	#ifndef   SR_RTE_FEATURE_CONFIG_INT_MAX
	  #define SR_RTE_FEATURE_CONFIG_INT_MAX	(2147483647)
	#endif

/* typedef SR_RTE_OutSignGeometry_t */
	#ifndef   SR_RTE_RESULT_TRACK_SIGN_CIRCULAR
	  #define SR_RTE_RESULT_TRACK_SIGN_CIRCULAR	(0)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_SIGN_RECTANGULAR
	  #define SR_RTE_RESULT_TRACK_SIGN_RECTANGULAR	(1)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_SIGN_TRIANGULAR
	  #define SR_RTE_RESULT_TRACK_SIGN_TRIANGULAR	(2)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_SIGN_DIAMOND
	  #define SR_RTE_RESULT_TRACK_SIGN_DIAMOND	(3)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_SIGN_INT_MAX
	  #define SR_RTE_RESULT_TRACK_SIGN_INT_MAX	(2147483647)
	#endif

/* typedef SR_RTE_OutSupplSignPosition_t */
	#ifndef   SR_RTE_RESULT_TRACK_SUPPL_BELOW
	  #define SR_RTE_RESULT_TRACK_SUPPL_BELOW	(0)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_SUPPL_ABOVE
	  #define SR_RTE_RESULT_TRACK_SUPPL_ABOVE	(1)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_SUPPL_INT_MAX
	  #define SR_RTE_RESULT_TRACK_SUPPL_INT_MAX	(2147483647)
	#endif

/* typedef SR_RTE_ApplicationControlFlow_t */
	#ifndef   SR_RTE_APPL_CONTROL_FLOW_NORMAL
	  #define SR_RTE_APPL_CONTROL_FLOW_NORMAL	(0)
	#endif
	#ifndef   SR_RTE_APPL_CONTROL_FLOW_SKIP_KERNEL
	  #define SR_RTE_APPL_CONTROL_FLOW_SKIP_KERNEL	(1)
	#endif
	#ifndef   SR_RTE_APPL_CONTROL_FLOW_SKIP_KERNEL_FAKE_OUTPUT
	  #define SR_RTE_APPL_CONTROL_FLOW_SKIP_KERNEL_FAKE_OUTPUT	(2)
	#endif
	#ifndef   SR_RTE_APPL_CONTROL_FLOW_DEBUG
	  #define SR_RTE_APPL_CONTROL_FLOW_DEBUG	(3)
	#endif
	#ifndef   SR_RTE_APPL_CONTROL_FLOW_INT_MAX
	  #define SR_RTE_APPL_CONTROL_FLOW_INT_MAX	(2147483647)
	#endif

/* typedef SR_RTE_OutputResultTrackStatus_t */
	#ifndef   SR_RTE_RESULT_TRACK_STATUS_ACTIVE
	  #define SR_RTE_RESULT_TRACK_STATUS_ACTIVE	(0)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_STATUS_ENDED
	  #define SR_RTE_RESULT_TRACK_STATUS_ENDED	(1)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_STATUS_PASSED
	  #define SR_RTE_RESULT_TRACK_STATUS_PASSED	(2)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_STATUS_FINISHED
	  #define SR_RTE_RESULT_TRACK_STATUS_FINISHED	(3)
	#endif
	#ifndef   SR_RTE_OUTPUT_RESULT_TRACK_STATUS_INT_MAX
	  #define SR_RTE_OUTPUT_RESULT_TRACK_STATUS_INT_MAX	(2147483647)
	#endif

/* typedef SR_RTE_OutputTrackCharacteristic_t */
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_NONE
	  #define SR_RTE_RESULT_TRACK_CHARAC_NONE	(0)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_HAS_SUPPLSIGN
	  #define SR_RTE_RESULT_TRACK_CHARAC_HAS_SUPPLSIGN	(1)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_ON_VEHICLE
	  #define SR_RTE_RESULT_TRACK_CHARAC_ON_VEHICLE	(2)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_ON_INFO_SIGN
	  #define SR_RTE_RESULT_TRACK_CHARAC_ON_INFO_SIGN	(4)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_NEVER_PASSED
	  #define SR_RTE_RESULT_TRACK_CHARAC_NEVER_PASSED	(8)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_CLASS_SHAKY
	  #define SR_RTE_RESULT_TRACK_CHARAC_CLASS_SHAKY	(16)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_GEN_END_CHECK_FAILED
	  #define SR_RTE_RESULT_TRACK_CHARAC_GEN_END_CHECK_FAILED	(32)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_RESERVED
	  #define SR_RTE_RESULT_TRACK_CHARAC_RESERVED	(64)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_IS_PART_OF_GATE
	  #define SR_RTE_RESULT_TRACK_CHARAC_IS_PART_OF_GATE	(128)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_IS_EMBEDDED
	  #define SR_RTE_RESULT_TRACK_CHARAC_IS_EMBEDDED	(256)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_REDNESS_CHECK_FAILED
	  #define SR_RTE_RESULT_TRACK_CHARAC_REDNESS_CHECK_FAILED	(512)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_HAS_YELLOW_BACKGROUND
	  #define SR_RTE_RESULT_TRACK_CHARAC_HAS_YELLOW_BACKGROUND	(1024)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_ACTVSBLUE_FAILED
	  #define SR_RTE_RESULT_TRACK_CHARAC_ACTVSBLUE_FAILED	(2048)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_DISABELED
	  #define SR_RTE_RESULT_TRACK_CHARAC_DISABELED	(4096)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT
	  #define SR_RTE_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT	(8192)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT_SUPPL
	  #define SR_RTE_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT_SUPPL	(16384)
	#endif
	#ifndef   SR_RTE_RESULT_TRACK_CHARAC_MODIFIED_CLASS
	  #define SR_RTE_RESULT_TRACK_CHARAC_MODIFIED_CLASS	(32768)
	#endif
	#ifndef   SR_RTE_OUTPUT_TRACK_CHAR_INT_MAX
	  #define SR_RTE_OUTPUT_TRACK_CHAR_INT_MAX	(2147483647)
	#endif

/* typedef SR_RTE_CalibrationStatus_t */
	#ifndef   SR_RTE_CALIBRATION_STATUS_UNKNOWN
	  #define SR_RTE_CALIBRATION_STATUS_UNKNOWN	(0)
	#endif
	#ifndef   SR_RTE_CALIBRATION_STATUS_OK
	  #define SR_RTE_CALIBRATION_STATUS_OK	(1)
	#endif
	#ifndef   SR_RTE_CALIBRATION_STATUS_NOT_OK
	  #define SR_RTE_CALIBRATION_STATUS_NOT_OK	(2)
	#endif
	#ifndef   SR_RTE_CALIBRATION_STATUS_INT_MAX
	  #define SR_RTE_CALIBRATION_STATUS_INT_MAX	(2147483647)
	#endif

/* typedef SR_RTE_Brightness_t */
	#ifndef   SR_RTE_BRIGHTNESS_UNKNOWN
	  #define SR_RTE_BRIGHTNESS_UNKNOWN	(0)
	#endif
	#ifndef   SR_RTE_BRIGHTNESS_DARK
	  #define SR_RTE_BRIGHTNESS_DARK	(1)
	#endif
	#ifndef   SR_RTE_BRIGHTNESS_BRIGHT
	  #define SR_RTE_BRIGHTNESS_BRIGHT	(2)
	#endif
	#ifndef   SR_RTE_BRIGHTNESS_INT_MAX
	  #define SR_RTE_BRIGHTNESS_INT_MAX	(2147483647)
	#endif

/* typedef classId_t */
	#ifndef   SR_RTE_SIGN_CLASS_UNKNOWN
	  #define SR_RTE_SIGN_CLASS_UNKNOWN	(0)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_RESTRICTED
	  #define SR_RTE_SIGN_CLASS_SUPPL_RESTRICTED	(100000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_ARROW_LEFT
	  #define SR_RTE_SIGN_CLASS_SUPPL_ARROW_LEFT	(100010)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_CURVED_ARROW_LEFT
	  #define SR_RTE_SIGN_CLASS_SUPPL_CURVED_ARROW_LEFT	(100011)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_ARROW_RIGHT
	  #define SR_RTE_SIGN_CLASS_SUPPL_ARROW_RIGHT	(100020)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_CURVED_ARROW_RIGHT
	  #define SR_RTE_SIGN_CLASS_SUPPL_CURVED_ARROW_RIGHT	(100021)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_VALID_FOR_DISTANCE
	  #define SR_RTE_SIGN_CLASS_SUPPL_VALID_FOR_DISTANCE	(100100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_VALID_IN_DISTANCE
	  #define SR_RTE_SIGN_CLASS_SUPPL_VALID_IN_DISTANCE	(100400)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_ONLY_INFORMATION_PICT
	  #define SR_RTE_SIGN_CLASS_SUPPL_ONLY_INFORMATION_PICT	(100600)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_ONLY_INFORMATION_TEXT_ONE_ROW
	  #define SR_RTE_SIGN_CLASS_SUPPL_ONLY_INFORMATION_TEXT_ONE_ROW	(100601)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_ZONE
	  #define SR_RTE_SIGN_CLASS_SUPPL_ZONE	(100604)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_GARBAGE
	  #define SR_RTE_SIGN_CLASS_SUPPL_GARBAGE	(100990)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_EXCLAMATION_MARK
	  #define SR_RTE_SIGN_CLASS_DANGER_EXCLAMATION_MARK	(101000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_CROSS_ROAD
	  #define SR_RTE_SIGN_CLASS_DANGER_CROSS_ROAD	(102000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_BICYCLE_PERMITTED
	  #define SR_RTE_SIGN_CLASS_SUPPL_BICYCLE_PERMITTED	(102210)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_MOTORCYCLE_PERMITTED
	  #define SR_RTE_SIGN_CLASS_SUPPL_MOTORCYCLE_PERMITTED	(102212)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_BEND_LEFT
	  #define SR_RTE_SIGN_CLASS_DANGER_BEND_LEFT	(103010)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_BEND_RIGHT
	  #define SR_RTE_SIGN_CLASS_DANGER_BEND_RIGHT	(103020)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_TIME_RESTRICTION
	  #define SR_RTE_SIGN_CLASS_SUPPL_TIME_RESTRICTION	(104030)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_NIGHT
	  #define SR_RTE_SIGN_CLASS_SUPPL_NIGHT	(104040)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_WORKDAYS
	  #define SR_RTE_SIGN_CLASS_SUPPL_WORKDAYS	(104230)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_WORKDAYS_AND_TIME
	  #define SR_RTE_SIGN_CLASS_SUPPL_WORKDAYS_AND_TIME	(104231)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_MON2FRI_AND_TIME
	  #define SR_RTE_SIGN_CLASS_SUPPL_MON2FRI_AND_TIME	(104233)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_MOTORCYCLE
	  #define SR_RTE_SIGN_CLASS_SUPPL_MOTORCYCLE	(104610)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_PASSENGER_CAR
	  #define SR_RTE_SIGN_CLASS_SUPPL_PASSENGER_CAR	(104810)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_PASSENGER_CAR_TRAILER
	  #define SR_RTE_SIGN_CLASS_SUPPL_PASSENGER_CAR_TRAILER	(104811)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_TRUCK_BUS
	  #define SR_RTE_SIGN_CLASS_SUPPL_TRUCK_BUS	(104812)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_TRACTORS_MAY_BE_PASSED
	  #define SR_RTE_SIGN_CLASS_SUPPL_TRACTORS_MAY_BE_PASSED	(104911)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_TRUCK_BUS_CAR_TRAILER
	  #define SR_RTE_SIGN_CLASS_SUPPL_TRUCK_BUS_CAR_TRAILER	(104913)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_DOUBLE_BEND_LEFT
	  #define SR_RTE_SIGN_CLASS_DANGER_DOUBLE_BEND_LEFT	(105010)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_DOUBLE_BEND_RIGHT
	  #define SR_RTE_SIGN_CLASS_DANGER_DOUBLE_BEND_RIGHT	(105020)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_WEIGHT
	  #define SR_RTE_SIGN_CLASS_SUPPL_WEIGHT	(105235)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_WET
	  #define SR_RTE_SIGN_CLASS_SUPPL_WET	(105236)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_FOGGY
	  #define SR_RTE_SIGN_CLASS_SUPPL_FOGGY	(105237)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_ICY
	  #define SR_RTE_SIGN_CLASS_SUPPL_ICY	(105238)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_SCHOOL
	  #define SR_RTE_SIGN_CLASS_SUPPL_SCHOOL	(105239)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_X_WAY
	  #define SR_RTE_SIGN_CLASS_SUPPL_X_WAY	(105240)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_SNOW_RAIN
	  #define SR_RTE_SIGN_CLASS_SUPPL_SNOW_RAIN	(105241)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_RAIN
	  #define SR_RTE_SIGN_CLASS_SUPPL_RAIN	(105242)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL__ALL_WAY
	  #define SR_RTE_SIGN_CLASS_SUPPL__ALL_WAY	(105243)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_HILL_DOWNWARDS
	  #define SR_RTE_SIGN_CLASS_DANGER_HILL_DOWNWARDS	(108000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_GARBAGE
	  #define SR_RTE_SIGN_CLASS_DANGER_GARBAGE	(109990)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_HILL_UPWARDS
	  #define SR_RTE_SIGN_CLASS_DANGER_HILL_UPWARDS	(110000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_BUMPS
	  #define SR_RTE_SIGN_CLASS_DANGER_BUMPS	(112000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_UNEVEN_ROAD
	  #define SR_RTE_SIGN_CLASS_DANGER_UNEVEN_ROAD	(112100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_SNOW
	  #define SR_RTE_SIGN_CLASS_DANGER_SNOW	(113000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_SLIPPERY_ROAD
	  #define SR_RTE_SIGN_CLASS_DANGER_SLIPPERY_ROAD	(114000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_FALLING_ROCKS
	  #define SR_RTE_SIGN_CLASS_DANGER_FALLING_ROCKS	(115000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_GRAVEL
	  #define SR_RTE_SIGN_CLASS_DANGER_GRAVEL	(116000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_WIND
	  #define SR_RTE_SIGN_CLASS_DANGER_WIND	(117000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_BOTH_SIDES
	  #define SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_BOTH_SIDES	(120000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_RIGHT_SIDE
	  #define SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_RIGHT_SIDE	(121000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_LEFT_SIDE
	  #define SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_LEFT_SIDE	(121020)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_ROAD_WORK
	  #define SR_RTE_SIGN_CLASS_DANGER_ROAD_WORK	(123000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_STRUCTURAL_CLEARANCE
	  #define SR_RTE_SIGN_CLASS_DANGER_STRUCTURAL_CLEARANCE	(123100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_TRAFFIC_JAM
	  #define SR_RTE_SIGN_CLASS_DANGER_TRAFFIC_JAM	(124000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_TWO_WAY_TRAFFIC
	  #define SR_RTE_SIGN_CLASS_DANGER_TWO_WAY_TRAFFIC	(125000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_MOVING_BRIDGE
	  #define SR_RTE_SIGN_CLASS_DANGER_MOVING_BRIDGE	(128000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_DANGER_WATERFRONT
	  #define SR_RTE_SIGN_CLASS_DANGER_DANGER_WATERFRONT	(129000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_TRAFFIC_LIGHTS
	  #define SR_RTE_SIGN_CLASS_DANGER_TRAFFIC_LIGHTS	(131000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_PEDESTRIAN
	  #define SR_RTE_SIGN_CLASS_DANGER_PEDESTRIAN	(133000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_PEDESTRIAN_ZEBRA_CROSSING
	  #define SR_RTE_SIGN_CLASS_DANGER_PEDESTRIAN_ZEBRA_CROSSING	(134000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_DANGER_CHILDREN
	  #define SR_RTE_SIGN_CLASS_DANGER_DANGER_CHILDREN	(136000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_CYCLIST_CROSSING
	  #define SR_RTE_SIGN_CLASS_DANGER_CYCLIST_CROSSING	(138000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_CATTLE_CROSSING
	  #define SR_RTE_SIGN_CLASS_DANGER_CATTLE_CROSSING	(140000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS__DANGER_ACCOMPPANIED_HORSES
	  #define SR_RTE_SIGN_CLASS__DANGER_ACCOMPPANIED_HORSES	(140100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_AMPHIBIAN_MIGRATION
	  #define SR_RTE_SIGN_CLASS_DANGER_AMPHIBIAN_MIGRATION	(140200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_ANIMAL_CROSSING
	  #define SR_RTE_SIGN_CLASS_DANGER_ANIMAL_CROSSING	(142000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_AIR_TRAFFIC
	  #define SR_RTE_SIGN_CLASS_DANGER_AIR_TRAFFIC	(144000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_BUS
	  #define SR_RTE_SIGN_CLASS_DANGER_BUS	(145000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_TRAIN_CROSS
	  #define SR_RTE_SIGN_CLASS_DANGER_TRAIN_CROSS	(151000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_GIVE_WAY
	  #define SR_RTE_SIGN_CLASS_DANGER_GIVE_WAY	(205000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_STOP
	  #define SR_RTE_SIGN_CLASS_MAIN_STOP	(206000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_TURN_LEFT
	  #define SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_TURN_LEFT	(209100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_TURN_RIGHT
	  #define SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_TURN_RIGHT	(209200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_STRAIGHT
	  #define SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_STRAIGHT	(209300)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_GARBAGE_DIR_ARROW
	  #define SR_RTE_SIGN_CLASS_MAIN_GARBAGE_DIR_ARROW	(209990)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_SIDE_LEFT
	  #define SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_SIDE_LEFT	(211100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_SIDE_RIGHT
	  #define SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_SIDE_RIGHT	(211200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_LEFT
	  #define SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_LEFT	(214100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_RIGHT
	  #define SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_RIGHT	(214200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_ROUNDABOUT
	  #define SR_RTE_SIGN_CLASS_MAIN_ROUNDABOUT	(215000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_PASS_LEFT
	  #define SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_PASS_LEFT	(222100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_PASS_RIGHT
	  #define SR_RTE_SIGN_CLASS_MAIN_DIR_ARROW_PASS_RIGHT	(222200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_PASS_LEFT_OR_RIGHT
	  #define SR_RTE_SIGN_CLASS_MAIN_PASS_LEFT_OR_RIGHT	(222210)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_LEFT_OR_RIGHT
	  #define SR_RTE_SIGN_CLASS_MAIN_LEFT_OR_RIGHT	(222220)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DRIVE_ON_SHOULDER
	  #define SR_RTE_SIGN_CLASS_MAIN_DRIVE_ON_SHOULDER	(223100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_NO_LONGER_DRIVE_ON_SHOULDER
	  #define SR_RTE_SIGN_CLASS_MAIN_NO_LONGER_DRIVE_ON_SHOULDER	(223200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CLEAR_SHOULDER
	  #define SR_RTE_SIGN_CLASS_MAIN_CLEAR_SHOULDER	(223300)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DO_NOT_DRIVE_IN_LANE
	  #define SR_RTE_SIGN_CLASS_MAIN_DO_NOT_DRIVE_IN_LANE	(223400)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_DRIVE_IN_LANE
	  #define SR_RTE_SIGN_CLASS_MAIN_DRIVE_IN_LANE	(223500)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CLEAR_LEFT_LANE
	  #define SR_RTE_SIGN_CLASS_MAIN_CLEAR_LEFT_LANE	(223600)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CLEAR_RIGHT_LANE
	  #define SR_RTE_SIGN_CLASS_MAIN_CLEAR_RIGHT_LANE	(223700)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_ADVANCE_DIRECTION_SIGN
	  #define SR_RTE_SIGN_CLASS_MAIN_ADVANCE_DIRECTION_SIGN	(223800)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_PROHIB_ALL
	  #define SR_RTE_SIGN_CLASS_MAIN_PROHIB_ALL	(250000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_GARBAGE_PROHIB
	  #define SR_RTE_SIGN_CLASS_MAIN_GARBAGE_PROHIB	(250990)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_PROHIB_CAR
	  #define SR_RTE_SIGN_CLASS_MAIN_PROHIB_CAR	(251000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_PROHIB_MOTORBIKE_CAR
	  #define SR_RTE_SIGN_CLASS_MAIN_PROHIB_MOTORBIKE_CAR	(260000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_NO_ENTRY
	  #define SR_RTE_SIGN_CLASS_MAIN_NO_ENTRY	(267000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE
	  #define SR_RTE_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE	(270100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_GREEN
	  #define SR_RTE_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_GREEN	(270110)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_END
	  #define SR_RTE_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_END	(270200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_NO_TURNING
	  #define SR_RTE_SIGN_CLASS_MAIN_NO_TURNING	(272000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_NO_LEFT_TURN
	  #define SR_RTE_SIGN_CLASS_MAIN_NO_LEFT_TURN	(272100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_NO_RIGHT_TURN
	  #define SR_RTE_SIGN_CLASS_MAIN_NO_RIGHT_TURN	(272200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS__MAIN_NO_LEFT_TURN_HERE
	  #define SR_RTE_SIGN_CLASS__MAIN_NO_LEFT_TURN_HERE	(272300)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS__MAIN_NO_RIGHT_TURN_HERE
	  #define SR_RTE_SIGN_CLASS__MAIN_NO_RIGHT_TURN_HERE	(272400)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_005
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_005	(274505)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_005_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_005_ACTIVE	(274506)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_010
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_010	(274510)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_010_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_010_ACTIVE	(274511)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_015
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_015	(274515)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_015_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_015_ACTIVE	(274516)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_020
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_020	(274520)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_020_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_020_ACTIVE	(274521)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_025
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_025	(274525)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_025_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_025_ACTIVE	(274526)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_030
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_030	(274530)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_030_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_030_ACTIVE	(274531)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_035
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_035	(274535)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_035_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_035_ACTIVE	(274536)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_040
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_040	(274540)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_040_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_040_ACTIVE	(274541)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_045
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_045	(274545)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_045_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_045_ACTIVE	(274546)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_050
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_050	(274550)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_050_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_050_ACTIVE	(274551)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_055
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_055	(274555)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_055_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_055_ACTIVE	(274556)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_060
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_060	(274560)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_060_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_060_ACTIVE	(274561)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_065
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_065	(274565)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_065_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_065_ACTIVE	(274566)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_070
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_070	(274570)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_070_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_070_ACTIVE	(274571)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_075
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_075	(274575)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_075_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_075_ACTIVE	(274576)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_080
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_080	(274580)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_080_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_080_ACTIVE	(274581)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_085
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_085	(274585)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_085_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_085_ACTIVE	(274586)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_090
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_090	(274590)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_090_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_090_ACTIVE	(274591)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_095
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_095	(274595)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_095_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_095_ACTIVE	(274596)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_100
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_100	(274600)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_100_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_100_ACTIVE	(274601)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_105
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_105	(274605)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_105_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_105_ACTIVE	(274606)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_110
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_110	(274610)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_110_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_110_ACTIVE	(274611)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_115
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_115	(274615)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_115_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_115_ACTIVE	(274616)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_120
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_120	(274620)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_120_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_120_ACTIVE	(274621)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_125
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_125	(274625)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_125_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_125_ACTIVE	(274626)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_130
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_130	(274630)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_130_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_130_ACTIVE	(274631)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_140
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_140	(274640)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_SL_140_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_SL_140_ACTIVE	(274641)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_GARBAGE
	  #define SR_RTE_SIGN_CLASS_MAIN_GARBAGE	(274990)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_GARBAGE_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_GARBAGE_ACTIVE	(274991)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_MINIMUM_SPEED_LIMIT
	  #define SR_RTE_SIGN_CLASS_MAIN_MINIMUM_SPEED_LIMIT	(275000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CAR_NO_PASSING
	  #define SR_RTE_SIGN_CLASS_MAIN_CAR_NO_PASSING	(276000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CAR_NO_PASSING_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_CAR_NO_PASSING_ACTIVE	(276001)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_TRUCK_NO_PASSING
	  #define SR_RTE_SIGN_CLASS_MAIN_TRUCK_NO_PASSING	(277000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_TRUCK_NO_PASSING_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_TRUCK_NO_PASSING_ACTIVE	(277001)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_BUNDLE_TWO_DIGIT_END
	  #define SR_RTE_SIGN_CLASS_MAIN_BUNDLE_TWO_DIGIT_END	(278200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_BUNDLE_TWO_DIGIT_END_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_BUNDLE_TWO_DIGIT_END_ACTIVE	(278201)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_BUNDLE_THREE_DIGIT_END
	  #define SR_RTE_SIGN_CLASS_MAIN_BUNDLE_THREE_DIGIT_END	(278300)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_BUNDLE_THREE_DIGIT_END_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_BUNDLE_THREE_DIGIT_END_ACTIVE	(278301)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_GARBAGE_END
	  #define SR_RTE_SIGN_CLASS_MAIN_GARBAGE_END	(278990)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_GARBAGE_END_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_GARBAGE_END_ACTIVE	(278991)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_MINIMUM_SPEED_LIMIT_END
	  #define SR_RTE_SIGN_CLASS_MAIN_MINIMUM_SPEED_LIMIT_END	(279000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CAR_NO_PASSING_END
	  #define SR_RTE_SIGN_CLASS_MAIN_CAR_NO_PASSING_END	(280000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CAR_NO_PASSING_END_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_CAR_NO_PASSING_END_ACTIVE	(280001)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_BUNDLE_NO_PASSING_END
	  #define SR_RTE_SIGN_CLASS_MAIN_BUNDLE_NO_PASSING_END	(280100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_BUNDLE_NO_PASSING_END_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_BUNDLE_NO_PASSING_END_ACTIVE	(280101)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_TRUCK_NO_PASSING_END
	  #define SR_RTE_SIGN_CLASS_MAIN_TRUCK_NO_PASSING_END	(281000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_TRUCK_NO_PASSING_END_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_TRUCK_NO_PASSING_END_ACTIVE	(281001)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_GENERAL_END
	  #define SR_RTE_SIGN_CLASS_MAIN_GENERAL_END	(282000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_GENERAL_END_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_GENERAL_END_ACTIVE	(282001)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_NO_PARKING_AT_ANY_TIME
	  #define SR_RTE_SIGN_CLASS_MAIN_NO_PARKING_AT_ANY_TIME	(283000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_START_OF_NO_PARKING_AT_ANY_TIME
	  #define SR_RTE_SIGN_CLASS_MAIN_START_OF_NO_PARKING_AT_ANY_TIME	(283100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_END_OF_NO_PARKING_AT_ANY_TIME
	  #define SR_RTE_SIGN_CLASS_MAIN_END_OF_NO_PARKING_AT_ANY_TIME	(283200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_NO_PARKING_AT_ANY_TIME_CONTINUED
	  #define SR_RTE_SIGN_CLASS_MAIN_NO_PARKING_AT_ANY_TIME_CONTINUED	(283300)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_RESTRICTED_PARKING
	  #define SR_RTE_SIGN_CLASS_MAIN_RESTRICTED_PARKING	(286000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_START_OF_RESTRICTED_PARKING
	  #define SR_RTE_SIGN_CLASS_MAIN_START_OF_RESTRICTED_PARKING	(286100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_END_OF_RESTRICTED_PARKING
	  #define SR_RTE_SIGN_CLASS_MAIN_END_OF_RESTRICTED_PARKING	(286200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_RESTRICTED_PARKING_CONTINUED
	  #define SR_RTE_SIGN_CLASS_MAIN_RESTRICTED_PARKING_CONTINUED	(286300)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_HOUSE_BEGIN
	  #define SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_HOUSE_BEGIN	(290000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_HOUSE_END
	  #define SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_HOUSE_END	(290100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_CROSS_ROAD_SMALL_ROAD
	  #define SR_RTE_SIGN_CLASS_DANGER_CROSS_ROAD_SMALL_ROAD	(301000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS__DANGER_INTERSECTION_RIGHT_OF_WAY_ON_LEFT
	  #define SR_RTE_SIGN_CLASS__DANGER_INTERSECTION_RIGHT_OF_WAY_ON_LEFT	(301100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_INTERSECTION_RIGHT_OF_WAY_ON_RIGHT
	  #define SR_RTE_SIGN_CLASS_DANGER_INTERSECTION_RIGHT_OF_WAY_ON_RIGHT	(301200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_INTERSECTION_WITHOUT_RIGHT_OF_WAY
	  #define SR_RTE_SIGN_CLASS_DANGER_INTERSECTION_WITHOUT_RIGHT_OF_WAY	(301300)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_T_JUNCTION
	  #define SR_RTE_SIGN_CLASS_DANGER_T_JUNCTION	(301400)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_T_JUNCTION_LEFT
	  #define SR_RTE_SIGN_CLASS_DANGER_T_JUNCTION_LEFT	(301500)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_T_JUNCTION_RIGHT
	  #define SR_RTE_SIGN_CLASS_DANGER_T_JUNCTION_RIGHT	(301600)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_INTERSECTION_OFFSET_LEFT
	  #define SR_RTE_SIGN_CLASS_DANGER_INTERSECTION_OFFSET_LEFT	(301700)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_INTERSECTION_OFFSET_RIGHT
	  #define SR_RTE_SIGN_CLASS_DANGER_INTERSECTION_OFFSET_RIGHT	(301800)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_PREFERENCE_ROAD
	  #define SR_RTE_SIGN_CLASS_DANGER_PREFERENCE_ROAD	(306000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CARPOOL_LANE
	  #define SR_RTE_SIGN_CLASS_MAIN_CARPOOL_LANE	(306100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS__DANGER_PREFERENCE_ROAD_END
	  #define SR_RTE_SIGN_CLASS__DANGER_PREFERENCE_ROAD_END	(307000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_BEGIN
	  #define SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_BEGIN	(310000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_END
	  #define SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_END	(311000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_PARKING
	  #define SR_RTE_SIGN_CLASS_MAIN_PARKING	(314000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_BEGIN
	  #define SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_BEGIN	(325000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_EMBEDDED_SL
	  #define SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_EMBEDDED_SL	(325100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_END
	  #define SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_END	(326000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_TUNNEL
	  #define SR_RTE_SIGN_CLASS_MAIN_TUNNEL	(327000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_EMERGENCY_STOP_BAY
	  #define SR_RTE_SIGN_CLASS_MAIN_EMERGENCY_STOP_BAY	(328000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_HIGHWAY_BEGIN
	  #define SR_RTE_SIGN_CLASS_MAIN_HIGHWAY_BEGIN	(330000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_MOTORWAY_BEGIN
	  #define SR_RTE_SIGN_CLASS_MAIN_MOTORWAY_BEGIN	(331000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_HIGHWAY_END
	  #define SR_RTE_SIGN_CLASS_MAIN_HIGHWAY_END	(334000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_MOTORWAY_END
	  #define SR_RTE_SIGN_CLASS_MAIN_MOTORWAY_END	(336000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_ONE_WAY_STREET
	  #define SR_RTE_SIGN_CLASS_MAIN_ONE_WAY_STREET	(353000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_ADVISORY_SPEED_LIMIT
	  #define SR_RTE_SIGN_CLASS_MAIN_ADVISORY_SPEED_LIMIT	(380000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_ADVISORY_SPEED_LIMIT_END
	  #define SR_RTE_SIGN_CLASS_MAIN_ADVISORY_SPEED_LIMIT_END	(381000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_LEFT_HAND
	  #define SR_RTE_SIGN_CLASS_LEFT_HAND	(616100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_RIGHT_HAND_FLASHING_ARROW
	  #define SR_RTE_SIGN_CLASS_RIGHT_HAND_FLASHING_ARROW	(616200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_NO_TURNS
	  #define SR_RTE_SIGN_CLASS_MAIN_NO_TURNS	(879102)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_ON_RED
	  #define SR_RTE_SIGN_CLASS_SUPPL_ON_RED	(879103)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_SPEED_LIMIT_AHEAD
	  #define SR_RTE_SIGN_CLASS_DANGER_SPEED_LIMIT_AHEAD	(879200)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_CLUSTER_GARBAGE
	  #define SR_RTE_SIGN_CLASS_CLUSTER_GARBAGE	(999990)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_END
	  #define SR_RTE_SIGN_CLASS_SUPPL_END	(1012310)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_EXIT
	  #define SR_RTE_SIGN_CLASS_SUPPL_EXIT	(1012320)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_SUPPL_RAMP
	  #define SR_RTE_SIGN_CLASS_SUPPL_RAMP	(1012330)
	#endif
	#ifndef   SR_RTE_OUTPUT_FUNCTIONAL_SIGN_CLASS_INT_MAX
	  #define SR_RTE_OUTPUT_FUNCTIONAL_SIGN_CLASS_INT_MAX	(2147483647)
	#endif

/* typedef srStatus_t */
	#ifndef   SR_RTE_PROCESS_STATUS_NOT_RUNNING
	  #define SR_RTE_PROCESS_STATUS_NOT_RUNNING	(0)
	#endif
	#ifndef   SR_RTE_PROCESS_STATUS_ERROR
	  #define SR_RTE_PROCESS_STATUS_ERROR	(1)
	#endif
	#ifndef   SR_RTE_PROCESS_STATUS_INIT
	  #define SR_RTE_PROCESS_STATUS_INIT	(2)
	#endif
	#ifndef   SR_RTE_PROCESS_STATUS_NO_COMPETENCE
	  #define SR_RTE_PROCESS_STATUS_NO_COMPETENCE	(3)
	#endif
	#ifndef   SR_RTE_PROCESS_STATUS_BLOCKAGE
	  #define SR_RTE_PROCESS_STATUS_BLOCKAGE	(4)
	#endif
	#ifndef   SR_RTE_PROCESS_STATUS_RUNNING
	  #define SR_RTE_PROCESS_STATUS_RUNNING	(5)
	#endif
	#ifndef   SR_RTE_PROCESS_STATUS_RUNNING_OVERLOADED
	  #define SR_RTE_PROCESS_STATUS_RUNNING_OVERLOADED	(6)
	#endif
	#ifndef   SR_RTE_PROCESS_STATUS_TEMP_ERROR
	  #define SR_RTE_PROCESS_STATUS_TEMP_ERROR	(7)
	#endif
	#ifndef   SR_RTE_PROCESS_STATUS_MUST_RESET
	  #define SR_RTE_PROCESS_STATUS_MUST_RESET	(8)
	#endif
	#ifndef   SR_RTE_OUTPUT_PROCESS_STATUS_INT_MAX
	  #define SR_RTE_OUTPUT_PROCESS_STATUS_INT_MAX	(2147483647)
	#endif

/* typedef SR_RTE_OutputTrackAlgo_t */
	#ifndef   SR_RTE_TRACK_ALGO_NONE
	  #define SR_RTE_TRACK_ALGO_NONE	(0)
	#endif
	#ifndef   SR_RTE_TRACK_ALGO_TRIANGULATE
	  #define SR_RTE_TRACK_ALGO_TRIANGULATE	(1)
	#endif
	#ifndef   SR_RTE_TRACK_ALGO_MODEL_BASED
	  #define SR_RTE_TRACK_ALGO_MODEL_BASED	(2)
	#endif
	#ifndef   SR_RTE_TRACK_ALGO_INT_MAX
	  #define SR_RTE_TRACK_ALGO_INT_MAX	(2147483647)
	#endif

/* typedef TLR_e_TimeOfDay */
	#ifndef   TLR_NIGHT
	  #define TLR_NIGHT	(0)
	#endif
	#ifndef   TLR_DAY
	  #define TLR_DAY	(1)
	#endif

/* typedef TLR_e_MeasStatus */
	#ifndef   TLR_NOT_MEASURED
	  #define TLR_NOT_MEASURED	(0)
	#endif
	#ifndef   TLR_ODD_MEAS
	  #define TLR_ODD_MEAS	(1)
	#endif
	#ifndef   TLR_EVEN_MEAS
	  #define TLR_EVEN_MEAS	(2)
	#endif

/* typedef TLR_e_RejectionReason */
	#ifndef   TLR_NOT_REJECTED
	  #define TLR_NOT_REJECTED	(0)
	#endif
	#ifndef   TLR_COLOR_REJECTION
	  #define TLR_COLOR_REJECTION	(1)
	#endif
	#ifndef   TLR_REFINED_COLOR_REJECTION
	  #define TLR_REFINED_COLOR_REJECTION	(2)
	#endif
	#ifndef   TLR_SIZE_REJECTION
	  #define TLR_SIZE_REJECTION	(3)
	#endif
	#ifndef   TLR_SIZE_RATIO_REJECTION
	  #define TLR_SIZE_RATIO_REJECTION	(4)
	#endif
	#ifndef   TLR_WORLD_SIZE_REJECTION
	  #define TLR_WORLD_SIZE_REJECTION	(5)
	#endif
	#ifndef   TLR_ROI_REJECTION
	  #define TLR_ROI_REJECTION	(6)
	#endif
	#ifndef   TLR_WORLD_ROI_REJECTION
	  #define TLR_WORLD_ROI_REJECTION	(7)
	#endif
	#ifndef   TLR_CLASSIF_REJECTION
	  #define TLR_CLASSIF_REJECTION	(8)
	#endif
	#ifndef   TLR_NO_MEAS_REJECTION
	  #define TLR_NO_MEAS_REJECTION	(9)
	#endif
	#ifndef   TLR_MERGED_REJECTION
	  #define TLR_MERGED_REJECTION	(10)
	#endif
	#ifndef   TLR_MAX_REJECTION
	  #define TLR_MAX_REJECTION	(16777215)
	#endif

/* typedef TLR_e_Color */
	#ifndef   TLR_UNKNOWN_COLOR
	  #define TLR_UNKNOWN_COLOR	(0)
	#endif
	#ifndef   TLR_RED
	  #define TLR_RED	(1)
	#endif
	#ifndef   TLR_YELLOW
	  #define TLR_YELLOW	(2)
	#endif
	#ifndef   TLR_RED_YELLOW
	  #define TLR_RED_YELLOW	(3)
	#endif
	#ifndef   TLR_GREEN
	  #define TLR_GREEN	(4)
	#endif

/* typedef TLR_e_LightMode */
	#ifndef   TLR_UNKNOWN_LIGHT_MODE
	  #define TLR_UNKNOWN_LIGHT_MODE	(0)
	#endif
	#ifndef   TLR_CONTINUOUS
	  #define TLR_CONTINUOUS	(1)
	#endif
	#ifndef   TLR_BLINKING
	  #define TLR_BLINKING	(2)
	#endif

/* typedef TLR_e_Class */
	#ifndef   TLR_SH_UNKNOWN_CLASS
	  #define TLR_SH_UNKNOWN_CLASS	(0)
	#endif
	#ifndef   TLR_SH_CIRCULAR
	  #define TLR_SH_CIRCULAR	(1)
	#endif
	#ifndef   TLR_SH_CROSS
	  #define TLR_SH_CROSS	(2)
	#endif
	#ifndef   TLR_SH_DIR
	  #define TLR_SH_DIR	(4)
	#endif
	#ifndef   TLR_SH_PED
	  #define TLR_SH_PED	(8)
	#endif
	#ifndef   TLR_SH_TRIANGLE
	  #define TLR_SH_TRIANGLE	(16)
	#endif
	#ifndef   TLR_SH_PED_TRIANGLE
	  #define TLR_SH_PED_TRIANGLE	(24)
	#endif
	#ifndef   TLR_SH_DIAG
	  #define TLR_SH_DIAG	(32)
	#endif
	#ifndef   TLR_SH_CROSS_DIAG
	  #define TLR_SH_CROSS_DIAG	(34)
	#endif
	#ifndef   TLR_SH_UP
	  #define TLR_SH_UP	(64)
	#endif
	#ifndef   TLR_SH_DIR_UP
	  #define TLR_SH_DIR_UP	(68)
	#endif
	#ifndef   TLR_SH_DOWN
	  #define TLR_SH_DOWN	(128)
	#endif
	#ifndef   TLR_SH_DIR_DOWN
	  #define TLR_SH_DIR_DOWN	(132)
	#endif
	#ifndef   TLR_SH_LEFT
	  #define TLR_SH_LEFT	(256)
	#endif
	#ifndef   TLR_SH_DIR_LEFT
	  #define TLR_SH_DIR_LEFT	(260)
	#endif
	#ifndef   TLR_SH_DIR_UP_LEFT
	  #define TLR_SH_DIR_UP_LEFT	(324)
	#endif
	#ifndef   TLR_SH_DIR_DIAG_UP_LEFT
	  #define TLR_SH_DIR_DIAG_UP_LEFT	(356)
	#endif
	#ifndef   TLR_SH_DIR_DOWN_LEFT
	  #define TLR_SH_DIR_DOWN_LEFT	(388)
	#endif
	#ifndef   TLR_SH_DIR_DIAG_DOWN_LEFT
	  #define TLR_SH_DIR_DIAG_DOWN_LEFT	(420)
	#endif
	#ifndef   TLR_SH_RIGHT
	  #define TLR_SH_RIGHT	(512)
	#endif
	#ifndef   TLR_SH_DIR_RIGHT
	  #define TLR_SH_DIR_RIGHT	(516)
	#endif
	#ifndef   TLR_SH_DIR_UP_RIGHT
	  #define TLR_SH_DIR_UP_RIGHT	(580)
	#endif
	#ifndef   TLR_SH_DIR_DIAG_UP_RIGHT
	  #define TLR_SH_DIR_DIAG_UP_RIGHT	(612)
	#endif
	#ifndef   TLR_SH_DIR_DOWN_RIGHT
	  #define TLR_SH_DIR_DOWN_RIGHT	(644)
	#endif
	#ifndef   TLR_SH_DIR_DIAG_DOWN_RIGHT
	  #define TLR_SH_DIR_DIAG_DOWN_RIGHT	(676)
	#endif
	#ifndef   TLR_SH_DIR_LEFT_RIGHT
	  #define TLR_SH_DIR_LEFT_RIGHT	(772)
	#endif
	#ifndef   TLR_SH_DIR_UP_LEFT_RIGHT
	  #define TLR_SH_DIR_UP_LEFT_RIGHT	(836)
	#endif
	#ifndef   TLR_SH_DIR_DOWN_LEFT_RIGHT
	  #define TLR_SH_DIR_DOWN_LEFT_RIGHT	(900)
	#endif
	#ifndef   TLR_SH_BIKE
	  #define TLR_SH_BIKE	(1024)
	#endif
	#ifndef   TLR_SH_HAND
	  #define TLR_SH_HAND	(2048)
	#endif
	#ifndef   TLR_SH_BUS
	  #define TLR_SH_BUS	(4096)
	#endif
	#ifndef   TLR_SH_MAX
	  #define TLR_SH_MAX	(65535)
	#endif

/* typedef TLR_e_ClassMode */
	#ifndef   TLR_SHM_DEFAULT
	  #define TLR_SHM_DEFAULT	(0)
	#endif
	#ifndef   TLR_SHM_INV
	  #define TLR_SHM_INV	(16384)
	#endif
	#ifndef   TLR_SHM_UNION
	  #define TLR_SHM_UNION	(32768)
	#endif
	#ifndef   TLR_SHM_INV_UNION
	  #define TLR_SHM_INV_UNION	(49152)
	#endif

/* typedef TLR_e_BrightnessMode */
	#ifndef   TLR_MODE_OFF
	  #define TLR_MODE_OFF	(0)
	#endif
	#ifndef   TLR_MODE_DAY
	  #define TLR_MODE_DAY	(1)
	#endif
	#ifndef   TLR_MODE_NIGHT
	  #define TLR_MODE_NIGHT	(2)
	#endif
	#ifndef   TLR_MODE_DAY_NIGHT
	  #define TLR_MODE_DAY_NIGHT	(3)
	#endif

/* typedef TLR_e_CountryVariation */
	#ifndef   TLR_COUNTRY_VARIATION_ECE
	  #define TLR_COUNTRY_VARIATION_ECE	(1)
	#endif
	#ifndef   TLR_COUNTRY_VARIATION_USA
	  #define TLR_COUNTRY_VARIATION_USA	(2)
	#endif
	#ifndef   TLR_COUNTRY_VARIATION_GERMANY
	  #define TLR_COUNTRY_VARIATION_GERMANY	(3)
	#endif
	#ifndef   TLR_COUNTRY_VARIATION_ENGLAND
	  #define TLR_COUNTRY_VARIATION_ENGLAND	(4)
	#endif
	#ifndef   TLR_COUNTRY_VARIATION_CANADA
	  #define TLR_COUNTRY_VARIATION_CANADA	(5)
	#endif
	#ifndef   TLR_COUNTRY_VARIATION_GULF
	  #define TLR_COUNTRY_VARIATION_GULF	(6)
	#endif
	#ifndef   TLR_COUNTRY_VARIATION_CHINA
	  #define TLR_COUNTRY_VARIATION_CHINA	(7)
	#endif
	#ifndef   TLR_COUNTRY_VARIATION_COREA
	  #define TLR_COUNTRY_VARIATION_COREA	(8)
	#endif
	#ifndef   TLR_COUNTRY_VARIATION_JAPAN
	  #define TLR_COUNTRY_VARIATION_JAPAN	(9)
	#endif
	#ifndef   TLR_COUNTRY_VARIATION_AUSTRALIA
	  #define TLR_COUNTRY_VARIATION_AUSTRALIA	(10)
	#endif

/* typedef TLR_e_FeatureMaster */
	#ifndef   TLR_FEATURE_CONFIG_NONE
	  #define TLR_FEATURE_CONFIG_NONE	(0)
	#endif
	#ifndef   TLR_FEATURE_CONFIG_SEGMENTATION
	  #define TLR_FEATURE_CONFIG_SEGMENTATION	(1)
	#endif
	#ifndef   TLR_FEATURE_CONFIG_CLASSIFICATION
	  #define TLR_FEATURE_CONFIG_CLASSIFICATION	(2)
	#endif
	#ifndef   TLR_FEATURE_CONFIG_TRACKING
	  #define TLR_FEATURE_CONFIG_TRACKING	(4)
	#endif

/* typedef TsaCountryVariationVehicle_t */
	#ifndef   TSA_RTE_COUNTRY_VARIATION_UNKNOWN
	  #define TSA_RTE_COUNTRY_VARIATION_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_ECE
	  #define TSA_RTE_COUNTRY_VARIATION_ECE	(1)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_GULF
	  #define TSA_RTE_COUNTRY_VARIATION_GULF	(2)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_USA
	  #define TSA_RTE_COUNTRY_VARIATION_USA	(3)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_CANADA
	  #define TSA_RTE_COUNTRY_VARIATION_CANADA	(4)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_ROW
	  #define TSA_RTE_COUNTRY_VARIATION_ROW	(5)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_JPCN
	  #define TSA_RTE_COUNTRY_VARIATION_JPCN	(6)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_ISRAEL
	  #define TSA_RTE_COUNTRY_VARIATION_ISRAEL	(7)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_CYPRUS
	  #define TSA_RTE_COUNTRY_VARIATION_CYPRUS	(8)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_CROATIA
	  #define TSA_RTE_COUNTRY_VARIATION_CROATIA	(9)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_TURKEY
	  #define TSA_RTE_COUNTRY_VARIATION_TURKEY	(10)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_BELARUS
	  #define TSA_RTE_COUNTRY_VARIATION_BELARUS	(11)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_CHINA
	  #define TSA_RTE_COUNTRY_VARIATION_CHINA	(12)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_SAFRICA
	  #define TSA_RTE_COUNTRY_VARIATION_SAFRICA	(13)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_AUSTRALIA
	  #define TSA_RTE_COUNTRY_VARIATION_AUSTRALIA	(14)
	#endif
	#ifndef   TSA_RTE_COUNTRY_VARIATION_SKOREA
	  #define TSA_RTE_COUNTRY_VARIATION_SKOREA	(15)
	#endif

/* typedef TsaNavigationInputIdentifier_t */
	#ifndef   TSA_RTE_NAV_IDENTIFIER_NO
	  #define TSA_RTE_NAV_IDENTIFIER_NO	(0)
	#endif
	#ifndef   TSA_RTE_NAV_IDENTIFIER_ONLY_CCO
	  #define TSA_RTE_NAV_IDENTIFIER_ONLY_CCO	(1)
	#endif
	#ifndef   TSA_RTE_NAV_IDENTIFIER_MAP
	  #define TSA_RTE_NAV_IDENTIFIER_MAP	(2)
	#endif
	#ifndef   TSA_RTE_NAV_IDENTIFIER_HI17
	  #define TSA_RTE_NAV_IDENTIFIER_HI17	(3)
	#endif
	#ifndef   TSA_RTE_NAV_IDENTIFIER_TA19
	  #define TSA_RTE_NAV_IDENTIFIER_TA19	(4)
	#endif

/* typedef MapProvider_t */
	#ifndef   INPUT_GPS_MAP_PROVIDER_NAVTEQ
	  #define INPUT_GPS_MAP_PROVIDER_NAVTEQ	(0)
	#endif
	#ifndef   INPUT_GPS_MAP_PROVIDER_TELEATLAS
	  #define INPUT_GPS_MAP_PROVIDER_TELEATLAS	(1)
	#endif
	#ifndef   INPUT_GPS_MAP_PROVIDER_ZENRIN
	  #define INPUT_GPS_MAP_PROVIDER_ZENRIN	(2)
	#endif
	#ifndef   INPUT_GPS_MAP_PROVIDER_ADF
	  #define INPUT_GPS_MAP_PROVIDER_ADF	(3)
	#endif
	#ifndef   INPUT_GPS_MAP_PROVIDER_NAVINFO
	  #define INPUT_GPS_MAP_PROVIDER_NAVINFO	(4)
	#endif
	#ifndef   INPUT_GPS_MAP_PROVIDER_RESERVED
	  #define INPUT_GPS_MAP_PROVIDER_RESERVED	(5)
	#endif
	#ifndef   INPUT_GPS_MAP_PROVIDER_NOT_AVAILABLE
	  #define INPUT_GPS_MAP_PROVIDER_NOT_AVAILABLE	(6)
	#endif
	#ifndef   INPUT_GPS_MAP_PROVIDER_INVALID
	  #define INPUT_GPS_MAP_PROVIDER_INVALID	(7)
	#endif

/* typedef TsaRteCurrentMotorway_t */
	#ifndef   TSA_RTE_MOTORWAY_UNKNOWN
	  #define TSA_RTE_MOTORWAY_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_MOTORWAY_TRUE
	  #define TSA_RTE_MOTORWAY_TRUE	(1)
	#endif
	#ifndef   TSA_RTE_MOTORWAY_FALSE
	  #define TSA_RTE_MOTORWAY_FALSE	(2)
	#endif
	#ifndef   TSA_RTE_MOTORWAY_SNA
	  #define TSA_RTE_MOTORWAY_SNA	(3)
	#endif

/* typedef TsaRteCurrentUrbanArea_t */
	#ifndef   TSA_RTE_URBAN_AREA_UNKNOWN
	  #define TSA_RTE_URBAN_AREA_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_URBAN_AREA_TRUE
	  #define TSA_RTE_URBAN_AREA_TRUE	(1)
	#endif
	#ifndef   TSA_RTE_URBAN_AREA_FALSE
	  #define TSA_RTE_URBAN_AREA_FALSE	(2)
	#endif
	#ifndef   TSA_RTE_URBAN_AREA_SNA
	  #define TSA_RTE_URBAN_AREA_SNA	(3)
	#endif

/* typedef TsaRteUrbanAreaChange_t */
	#ifndef   TSA_RTE_URBAN_AREA_CHANGE_UNKNOWN
	  #define TSA_RTE_URBAN_AREA_CHANGE_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_URBAN_AREA_CHANGE_NO_CHANGE_AHEAD
	  #define TSA_RTE_URBAN_AREA_CHANGE_NO_CHANGE_AHEAD	(1)
	#endif
	#ifndef   TSA_RTE_URBAN_AREA_CHANGE_OUTSIDE_TO_INSIDE
	  #define TSA_RTE_URBAN_AREA_CHANGE_OUTSIDE_TO_INSIDE	(2)
	#endif
	#ifndef   TSA_RTE_URBAN_AREA_CHANGE_INSIDE_TO_OUTSIDE
	  #define TSA_RTE_URBAN_AREA_CHANGE_INSIDE_TO_OUTSIDE	(3)
	#endif

/* typedef signType_t */
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_NO
	  #define TSA_RTE_SLA_OUTPUT_SIGN_NO	(0)
	#endif
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_SL
	  #define TSA_RTE_SLA_OUTPUT_SIGN_SL	(1)
	#endif
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_SLE
	  #define TSA_RTE_SLA_OUTPUT_SIGN_SLE	(2)
	#endif
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_CITYLIMIT_START
	  #define TSA_RTE_SLA_OUTPUT_SIGN_CITYLIMIT_START	(3)
	#endif
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_CITYLIMIT_END
	  #define TSA_RTE_SLA_OUTPUT_SIGN_CITYLIMIT_END	(4)
	#endif
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_PLAYSTREET_START
	  #define TSA_RTE_SLA_OUTPUT_SIGN_PLAYSTREET_START	(5)
	#endif
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_PLAYSTREET_END
	  #define TSA_RTE_SLA_OUTPUT_SIGN_PLAYSTREET_END	(6)
	#endif
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_HIGHWAY_START
	  #define TSA_RTE_SLA_OUTPUT_SIGN_HIGHWAY_START	(7)
	#endif
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_HIGHWAY_END
	  #define TSA_RTE_SLA_OUTPUT_SIGN_HIGHWAY_END	(8)
	#endif
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_MOTORWAY_START
	  #define TSA_RTE_SLA_OUTPUT_SIGN_MOTORWAY_START	(9)
	#endif
	#ifndef   TSA_RTE_SLA_OUTPUT_SIGN_MOTORWAY_END
	  #define TSA_RTE_SLA_OUTPUT_SIGN_MOTORWAY_END	(10)
	#endif

/* typedef TsaRteSlaSupSgnVal_t */
	#ifndef   TSA_RTE_SLA_SUPPLVALSTAT_UNKNOWN
	  #define TSA_RTE_SLA_SUPPLVALSTAT_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_SLA_SUPPLVALSTAT_INVALID
	  #define TSA_RTE_SLA_SUPPLVALSTAT_INVALID	(1)
	#endif
	#ifndef   TSA_RTE_SLA_SUPPLVALSTAT_VALID
	  #define TSA_RTE_SLA_SUPPLVALSTAT_VALID	(2)
	#endif
	#ifndef   TSA_RTE_SLA_SUPPLVALSTAT_EXTRAPOL
	  #define TSA_RTE_SLA_SUPPLVALSTAT_EXTRAPOL	(3)
	#endif

/* typedef TsaRteNpaStatus_t */
	#ifndef   TSA_RTE_NPA_PASSING_STATE_IDLE
	  #define TSA_RTE_NPA_PASSING_STATE_IDLE	(0)
	#endif
	#ifndef   TSA_RTE_NPA_PASSING_STATE_ALLOWED
	  #define TSA_RTE_NPA_PASSING_STATE_ALLOWED	(1)
	#endif
	#ifndef   TSA_RTE_NPA_PASSING_STATE_CANCEL
	  #define TSA_RTE_NPA_PASSING_STATE_CANCEL	(2)
	#endif
	#ifndef   TSA_RTE_NPA_PASSING_STATE_FORBIDDEN
	  #define TSA_RTE_NPA_PASSING_STATE_FORBIDDEN	(3)
	#endif

/* typedef TsaRteNpaSupplSignValState_t */
	#ifndef   TSA_RTE_NPA_SUPPLVALSTAT_UNKNOWN
	  #define TSA_RTE_NPA_SUPPLVALSTAT_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NPA_SUPPLVALSTAT_INVALID
	  #define TSA_RTE_NPA_SUPPLVALSTAT_INVALID	(1)
	#endif
	#ifndef   TSA_RTE_NPA_SUPPLVALSTAT_VALID
	  #define TSA_RTE_NPA_SUPPLVALSTAT_VALID	(2)
	#endif
	#ifndef   TSA_RTE_NPA_SUPPLVALSTAT_EXTRAPOL
	  #define TSA_RTE_NPA_SUPPLVALSTAT_EXTRAPOL	(3)
	#endif

/* typedef TsaRteRwfStatus_t */
	#ifndef   TSA_RTE_RWF_STATUS_UNKNOWN
	  #define TSA_RTE_RWF_STATUS_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_RWF_STATUS_NO
	  #define TSA_RTE_RWF_STATUS_NO	(1)
	#endif
	#ifndef   TSA_RTE_RWF_STATUS_YES
	  #define TSA_RTE_RWF_STATUS_YES	(2)
	#endif

/* typedef TsaRteRwfIndicators_t */
	#ifndef   TSA_RTE_RWF_INDICATOR_SPD_LMT_CAM_VS_MAP
	  #define TSA_RTE_RWF_INDICATOR_SPD_LMT_CAM_VS_MAP	(1)
	#endif
	#ifndef   TSA_RTE_RWF_INDICATOR_SPD_LMT_FUNNEL
	  #define TSA_RTE_RWF_INDICATOR_SPD_LMT_FUNNEL	(2)
	#endif
	#ifndef   TSA_RTE_RWF_INDICATOR_SIGN_REPET_RATE
	  #define TSA_RTE_RWF_INDICATOR_SIGN_REPET_RATE	(4)
	#endif
	#ifndef   TSA_RTE_RWF_INDICATOR_SIGN_BACK_COLOR
	  #define TSA_RTE_RWF_INDICATOR_SIGN_BACK_COLOR	(8)
	#endif
	#ifndef   TSA_RTE_RWF_INDICATOR_LANE_MARK_COLOR
	  #define TSA_RTE_RWF_INDICATOR_LANE_MARK_COLOR	(16)
	#endif
	#ifndef   TSA_RTE_RWF_INDICATOR_SIGN_INVALIDATED
	  #define TSA_RTE_RWF_INDICATOR_SIGN_INVALIDATED	(32)
	#endif
	#ifndef   TSA_RTE_RWF_INDICATOR_LANE_WIDTH
	  #define TSA_RTE_RWF_INDICATOR_LANE_WIDTH	(64)
	#endif
	#ifndef   TSA_RTE_RWF_INDICATOR_RW_SIGN
	  #define TSA_RTE_RWF_INDICATOR_RW_SIGN	(128)
	#endif

/* typedef TSARteWwaStatus_t */
	#ifndef   TSA_RTE_WWA_WRONG_WAY_IDLE
	  #define TSA_RTE_WWA_WRONG_WAY_IDLE	(0)
	#endif
	#ifndef   TSA_RTE_WWA_NOT_DRIVING_WRONG_WAY
	  #define TSA_RTE_WWA_NOT_DRIVING_WRONG_WAY	(1)
	#endif
	#ifndef   TSA_RTE_WWA_DRIVING_WRONG_WAY
	  #define TSA_RTE_WWA_DRIVING_WRONG_WAY	(2)
	#endif

/* typedef eventType_t */
	#ifndef   TSA_RTE_GWW_IDLE
	  #define TSA_RTE_GWW_IDLE	(0)
	#endif
	#ifndef   TSA_RTE_GWW_STOP_SIGN
	  #define TSA_RTE_GWW_STOP_SIGN	(1)
	#endif
	#ifndef   TSA_RTE_GWW_GW_SIGN
	  #define TSA_RTE_GWW_GW_SIGN	(2)
	#endif
	#ifndef   TSA_RTE_GWW_TRAFFIC_LIGHT
	  #define TSA_RTE_GWW_TRAFFIC_LIGHT	(3)
	#endif
	#ifndef   TSA_RTE_GWW_RES1
	  #define TSA_RTE_GWW_RES1	(4)
	#endif
	#ifndef   TSA_RTE_GWW_RES2
	  #define TSA_RTE_GWW_RES2	(5)
	#endif
	#ifndef   TSA_RTE_GWW_RES3
	  #define TSA_RTE_GWW_RES3	(6)
	#endif

/* typedef TsaRteCustomSignClass_t */
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_INDICATION
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_INDICATION	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SPEED_LIMIT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SPEED_LIMIT	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SPEED_LIMIT_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SPEED_LIMIT_END	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_ALL_WITHDRAWAL
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_ALL_WITHDRAWAL	(7)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_HIGHWAY_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_HIGHWAY_START	(16)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_HIGHWAY_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_HIGHWAY_END	(17)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MOTORWAY_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MOTORWAY_START	(18)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MOTORWAY_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MOTORWAY_END	(19)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_AREA_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_AREA_START	(20)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_AREA_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_AREA_END	(21)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_HOME_ZONE_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_HOME_ZONE_START	(22)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_HOME_ZONE_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_HOME_ZONE_END	(23)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_ISRAEL_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_ISRAEL_START	(24)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_ISRAEL_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_BUILTUP_ISRAEL_END	(25)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_RH
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_RH	(65)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_LH
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_LH	(66)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_END	(67)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_JAPAN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_JAPAN	(70)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_JAPAN_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_JAPAN_END	(71)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_US
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_US	(72)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_US_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_US_END	(73)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_CANADA
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_CANADA	(74)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_CANADA_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_PASS_CANADA_END	(75)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_ENTRY
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_ENTRY	(129)
	#endif

/* typedef TsaRteCustomGrayLevel_t */
	#ifndef   TSA_RTE_CUSTOM_GRAY_LVL_NO_GRAYING
	  #define TSA_RTE_CUSTOM_GRAY_LVL_NO_GRAYING	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_GRAY_LVL_1
	  #define TSA_RTE_CUSTOM_GRAY_LVL_1	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_GRAY_LVL_2
	  #define TSA_RTE_CUSTOM_GRAY_LVL_2	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_GRAY_LVL_3
	  #define TSA_RTE_CUSTOM_GRAY_LVL_3	(3)
	#endif

/* typedef TsaRteCustomHighlightStatus_t */
	#ifndef   TSA_RTE_CUSTOM_HIGHLIGHT_OFF
	  #define TSA_RTE_CUSTOM_HIGHLIGHT_OFF	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_HIGHLIGHT_REVERSING
	  #define TSA_RTE_CUSTOM_HIGHLIGHT_REVERSING	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_HIGHLIGHT_BLINKING
	  #define TSA_RTE_CUSTOM_HIGHLIGHT_BLINKING	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_HIGHLIGHT_RESERVED
	  #define TSA_RTE_CUSTOM_HIGHLIGHT_RESERVED	(3)
	#endif

/* typedef TsaRteCustomSupplSignClass_t */
	#ifndef   TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_NO_INDICATION
	  #define TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_NO_INDICATION	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_APPLIED_TIME
	  #define TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_APPLIED_TIME	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_EXIT_RAMP_RIGHT
	  #define TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_EXIT_RAMP_RIGHT	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_EXIT_RAMP_LEFT
	  #define TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_EXIT_RAMP_LEFT	(3)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_WHEN_WET
	  #define TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_WHEN_WET	(4)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_WHEN_RAIN
	  #define TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_WHEN_RAIN	(5)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_WHEN_ICE
	  #define TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_WHEN_ICE	(6)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_UNK
	  #define TSA_RTE_CUSTOM_SUPPL_SIGN_CLASS_UNK	(15)
	#endif

/* typedef TsaRteCustomBzrReq_t */
	#ifndef   TSA_RTE_CUSTOM_BUZZER_REQUEST_OFF
	  #define TSA_RTE_CUSTOM_BUZZER_REQUEST_OFF	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_BUZZER_REQUEST_ON
	  #define TSA_RTE_CUSTOM_BUZZER_REQUEST_ON	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_BUZZER_REQUEST_RESERVED_1
	  #define TSA_RTE_CUSTOM_BUZZER_REQUEST_RESERVED_1	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_BUZZER_REQUEST_RESERVED_2
	  #define TSA_RTE_CUSTOM_BUZZER_REQUEST_RESERVED_2	(3)
	#endif

/* typedef TsaRteCustomSpeedUnit_t */
	#ifndef   TSA_RTE_CUSTOM_SPEED_UNIT_UNK
	  #define TSA_RTE_CUSTOM_SPEED_UNIT_UNK	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SPEED_UNIT_KHM
	  #define TSA_RTE_CUSTOM_SPEED_UNIT_KHM	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SPEED_UNIT_MPH
	  #define TSA_RTE_CUSTOM_SPEED_UNIT_MPH	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SPEED_UNIT_RESERVED
	  #define TSA_RTE_CUSTOM_SPEED_UNIT_RESERVED	(3)
	#endif

/* typedef TsaRteCustomNoticeMethod_t */
	#ifndef   TSA_RTE_CUSTOM_NOTICE_METHOD_UNK
	  #define TSA_RTE_CUSTOM_NOTICE_METHOD_UNK	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_NOTICE_METHOD_OFF
	  #define TSA_RTE_CUSTOM_NOTICE_METHOD_OFF	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_NOTICE_METHOD_ONLY_VISIBLE
	  #define TSA_RTE_CUSTOM_NOTICE_METHOD_ONLY_VISIBLE	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_NOTICE_METHOD_VISIBLE_AND_AUDIBLE
	  #define TSA_RTE_CUSTOM_NOTICE_METHOD_VISIBLE_AND_AUDIBLE	(3)
	#endif

/* typedef TsaRteCustomOvSpdStartVal_t */
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_MINUS_5
	  #define TSA_RTE_CUSTOM_OVSPVAL_MINUS_5	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_MINUS_4
	  #define TSA_RTE_CUSTOM_OVSPVAL_MINUS_4	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_MINUS_3
	  #define TSA_RTE_CUSTOM_OVSPVAL_MINUS_3	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_MINUS_2
	  #define TSA_RTE_CUSTOM_OVSPVAL_MINUS_2	(3)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_MINUS_1
	  #define TSA_RTE_CUSTOM_OVSPVAL_MINUS_1	(4)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_0
	  #define TSA_RTE_CUSTOM_OVSPVAL_0	(5)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_1
	  #define TSA_RTE_CUSTOM_OVSPVAL_1	(6)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_2
	  #define TSA_RTE_CUSTOM_OVSPVAL_2	(7)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_3
	  #define TSA_RTE_CUSTOM_OVSPVAL_3	(8)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_4
	  #define TSA_RTE_CUSTOM_OVSPVAL_4	(9)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_5
	  #define TSA_RTE_CUSTOM_OVSPVAL_5	(10)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_6
	  #define TSA_RTE_CUSTOM_OVSPVAL_6	(11)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_7
	  #define TSA_RTE_CUSTOM_OVSPVAL_7	(12)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_8
	  #define TSA_RTE_CUSTOM_OVSPVAL_8	(13)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_9
	  #define TSA_RTE_CUSTOM_OVSPVAL_9	(14)
	#endif
	#ifndef   TSA_RTE_CUSTOM_OVSPVAL_10
	  #define TSA_RTE_CUSTOM_OVSPVAL_10	(15)
	#endif

/* typedef TsaRteConditionFlag_t */
	#ifndef   TSA_RTE_CONDITION_FLAG_DEACTIVATED
	  #define TSA_RTE_CONDITION_FLAG_DEACTIVATED	(0)
	#endif
	#ifndef   TSA_RTE_CONDITION_FLAG_RESERVED
	  #define TSA_RTE_CONDITION_FLAG_RESERVED	(1)
	#endif
	#ifndef   TSA_RTE_CONDITION_FLAG_NOT_APPLICABLE
	  #define TSA_RTE_CONDITION_FLAG_NOT_APPLICABLE	(2)
	#endif
	#ifndef   TSA_RTE_CONDITION_FLAG_APPLICABLE
	  #define TSA_RTE_CONDITION_FLAG_APPLICABLE	(3)
	#endif

/* typedef TsaRteExitRampFlag_t */
	#ifndef   TSA_RTE_EXIT_RAMP_DEACTIVATED
	  #define TSA_RTE_EXIT_RAMP_DEACTIVATED	(0)
	#endif
	#ifndef   TSA_RTE_EXIT_RAMP_IDLE
	  #define TSA_RTE_EXIT_RAMP_IDLE	(1)
	#endif
	#ifndef   TSA_RTE_EXIT_RAMP_RIGHT
	  #define TSA_RTE_EXIT_RAMP_RIGHT	(2)
	#endif
	#ifndef   TSA_RTE_EXIT_RAMP_LEFT
	  #define TSA_RTE_EXIT_RAMP_LEFT	(3)
	#endif

/* typedef signalState_t */
	#ifndef   TSA_RTE_DRIVING_DISTANCE_INVALID
	  #define TSA_RTE_DRIVING_DISTANCE_INVALID	(0)
	#endif
	#ifndef   TSA_RTE_DRIVING_DISTANCE_VALID
	  #define TSA_RTE_DRIVING_DISTANCE_VALID	(1)
	#endif

/* typedef TsaRteSignClassId_t */
	#ifndef   TSA_RTE_SGN_CLS_UNKNOWN
	  #define TSA_RTE_SGN_CLS_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_RESTRICTED
	  #define TSA_RTE_SGN_CLS_SUPPL_RESTRICTED	(100000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_ARROW_LEFT
	  #define TSA_RTE_SGN_CLS_SUPPL_ARROW_LEFT	(100010)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_CURVED_ARROW_LEFT
	  #define TSA_RTE_SGN_CLS_SUPPL_CURVED_ARROW_LEFT	(100011)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_ARROW_RIGHT
	  #define TSA_RTE_SGN_CLS_SUPPL_ARROW_RIGHT	(100020)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_CURVED_ARROW_RIGHT
	  #define TSA_RTE_SGN_CLS_SUPPL_CURVED_ARROW_RIGHT	(100021)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_VALID_FOR_DISTANCE
	  #define TSA_RTE_SGN_CLS_SUPPL_VALID_FOR_DISTANCE	(100100)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_VALID_IN_DISTANCE
	  #define TSA_RTE_SGN_CLS_SUPPL_VALID_IN_DISTANCE	(100400)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_ONLY_INFORMATION_PICT
	  #define TSA_RTE_SGN_CLS_SUPPL_ONLY_INFORMATION_PICT	(100600)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_ONLY_INFORMATION_TEXT_ONE_ROW
	  #define TSA_RTE_SGN_CLS_SUPPL_ONLY_INFORMATION_TEXT_ONE_ROW	(100601)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_ZONE
	  #define TSA_RTE_SGN_CLS_SUPPL_ZONE	(100604)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_GARBAGE
	  #define TSA_RTE_SGN_CLS_SUPPL_GARBAGE	(100990)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_EXCLAMATION_MARK
	  #define TSA_RTE_SGN_CLS_DANGER_EXCLAMATION_MARK	(101000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_CROSS_ROAD
	  #define TSA_RTE_SGN_CLS_DANGER_CROSS_ROAD	(102000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_BEND_LEFT
	  #define TSA_RTE_SGN_CLS_DANGER_BEND_LEFT	(103010)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_BEND_RIGHT
	  #define TSA_RTE_SGN_CLS_DANGER_BEND_RIGHT	(103020)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_TIME_RESTRICTION
	  #define TSA_RTE_SGN_CLS_SUPPL_TIME_RESTRICTION	(104030)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_NIGHT
	  #define TSA_RTE_SGN_CLS_SUPPL_NIGHT	(104040)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_WORKDAYS
	  #define TSA_RTE_SGN_CLS_SUPPL_WORKDAYS	(104230)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_WORKDAYS_AND_TIME
	  #define TSA_RTE_SGN_CLS_SUPPL_WORKDAYS_AND_TIME	(104231)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_MON2FRI_AND_TIME
	  #define TSA_RTE_SGN_CLS_SUPPL_MON2FRI_AND_TIME	(104233)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_MOTORCYCLE
	  #define TSA_RTE_SGN_CLS_SUPPL_MOTORCYCLE	(104610)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_PASSENGER_CAR
	  #define TSA_RTE_SGN_CLS_SUPPL_PASSENGER_CAR	(104810)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_PASSENGER_CAR_TRAILER
	  #define TSA_RTE_SGN_CLS_SUPPL_PASSENGER_CAR_TRAILER	(104811)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_TRUCK_BUS
	  #define TSA_RTE_SGN_CLS_SUPPL_TRUCK_BUS	(104812)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_TRACTORS_MAY_BE_PASSED
	  #define TSA_RTE_SGN_CLS_SUPPL_TRACTORS_MAY_BE_PASSED	(104911)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_TRUCK_BUS_CAR_TRAILER
	  #define TSA_RTE_SGN_CLS_SUPPL_TRUCK_BUS_CAR_TRAILER	(104913)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_DOUBLE_BEND_LEFT
	  #define TSA_RTE_SGN_CLS_DANGER_DOUBLE_BEND_LEFT	(105010)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_DOUBLE_BEND_RIGHT
	  #define TSA_RTE_SGN_CLS_DANGER_DOUBLE_BEND_RIGHT	(105020)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_WEIGHT
	  #define TSA_RTE_SGN_CLS_SUPPL_WEIGHT	(105235)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_WET
	  #define TSA_RTE_SGN_CLS_SUPPL_WET	(105236)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_FOGGY
	  #define TSA_RTE_SGN_CLS_SUPPL_FOGGY	(105237)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_ICY
	  #define TSA_RTE_SGN_CLS_SUPPL_ICY	(105238)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_SCHOOL
	  #define TSA_RTE_SGN_CLS_SUPPL_SCHOOL	(105239)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_X_WAY
	  #define TSA_RTE_SGN_CLS_SUPPL_X_WAY	(105240)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_SNOW_RAIN
	  #define TSA_RTE_SGN_CLS_SUPPL_SNOW_RAIN	(105241)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_SUPPL_RAIN
	  #define TSA_RTE_SGN_CLS_SUPPL_RAIN	(105242)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_STEEP_HILL_DOWNWARDS
	  #define TSA_RTE_SGN_CLS_DANGER_STEEP_HILL_DOWNWARDS	(108000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_STEEP_HILL_UPWARDS
	  #define TSA_RTE_SGN_CLS_DANGER_STEEP_HILL_UPWARDS	(110000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_BUMPS
	  #define TSA_RTE_SGN_CLS_DANGER_BUMPS	(112000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_SNOW
	  #define TSA_RTE_SGN_CLS_DANGER_SNOW	(113000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_SLIPPERY_ROAD
	  #define TSA_RTE_SGN_CLS_DANGER_SLIPPERY_ROAD	(114000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_GRAVEL
	  #define TSA_RTE_SGN_CLS_DANGER_GRAVEL	(116000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_WIND
	  #define TSA_RTE_SGN_CLS_DANGER_WIND	(117000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_ROAD_NARROW_BOTH_SIDES
	  #define TSA_RTE_SGN_CLS_DANGER_ROAD_NARROW_BOTH_SIDES	(120000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_ROAD_NARROW_RIGHT_SIDE
	  #define TSA_RTE_SGN_CLS_DANGER_ROAD_NARROW_RIGHT_SIDE	(121010)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_ROAD_NARROW_LEFT_SIDE
	  #define TSA_RTE_SGN_CLS_DANGER_ROAD_NARROW_LEFT_SIDE	(121020)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_ROAD_WORK
	  #define TSA_RTE_SGN_CLS_DANGER_ROAD_WORK	(123000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_TRAFFIC_JAM
	  #define TSA_RTE_SGN_CLS_DANGER_TRAFFIC_JAM	(124000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_TWO_WAY_TRAFFIC
	  #define TSA_RTE_SGN_CLS_DANGER_TWO_WAY_TRAFFIC	(125000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_TRAFFIC_LIGHTS
	  #define TSA_RTE_SGN_CLS_DANGER_TRAFFIC_LIGHTS	(131000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_PEDESTRIAN
	  #define TSA_RTE_SGN_CLS_DANGER_PEDESTRIAN	(133000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_PEDESTRIAN_ZEBRA_CROSSING
	  #define TSA_RTE_SGN_CLS_DANGER_PEDESTRIAN_ZEBRA_CROSSING	(134000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_DANGER_CHILDREN
	  #define TSA_RTE_SGN_CLS_DANGER_DANGER_CHILDREN	(136000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_CYCLIST_CROSSING
	  #define TSA_RTE_SGN_CLS_DANGER_CYCLIST_CROSSING	(138000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_ANIMAL_CROSSING
	  #define TSA_RTE_SGN_CLS_DANGER_ANIMAL_CROSSING	(142000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_TRAIN_CROSS
	  #define TSA_RTE_SGN_CLS_DANGER_TRAIN_CROSS	(151000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_GIVE_WAY
	  #define TSA_RTE_SGN_CLS_DANGER_GIVE_WAY	(205000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_STOP
	  #define TSA_RTE_SGN_CLS_MAIN_STOP	(206000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_TURN_LEFT
	  #define TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_TURN_LEFT	(209100)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_TURN_RIGHT
	  #define TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_TURN_RIGHT	(209200)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_STRAIGHT
	  #define TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_STRAIGHT	(209300)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_GARBAGE_DIR_ARROW
	  #define TSA_RTE_SGN_CLS_MAIN_GARBAGE_DIR_ARROW	(209990)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_SIDE_LEFT
	  #define TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_SIDE_LEFT	(211100)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_SIDE_RIGHT
	  #define TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_SIDE_RIGHT	(211200)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_LEFT
	  #define TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_LEFT	(214100)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_RIGHT
	  #define TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_STRAIGHT_AND_TURN_RIGHT	(214200)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_ROUNDABOUT
	  #define TSA_RTE_SGN_CLS_MAIN_ROUNDABOUT	(215000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_PASS_LEFT
	  #define TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_PASS_LEFT	(222100)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_PASS_RIGHT
	  #define TSA_RTE_SGN_CLS_MAIN_DIR_ARROW_PASS_RIGHT	(222200)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_PROHIB_ALL
	  #define TSA_RTE_SGN_CLS_MAIN_PROHIB_ALL	(250000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_GARBAGE_PROHIB
	  #define TSA_RTE_SGN_CLS_MAIN_GARBAGE_PROHIB	(250990)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_PROHIB_CAR
	  #define TSA_RTE_SGN_CLS_MAIN_PROHIB_CAR	(251000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_PROHIB_MOTORBIKE_CAR
	  #define TSA_RTE_SGN_CLS_MAIN_PROHIB_MOTORBIKE_CAR	(260000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_NO_ENTRY
	  #define TSA_RTE_SGN_CLS_MAIN_NO_ENTRY	(267000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_ENVIRONMENTAL_ZONE
	  #define TSA_RTE_SGN_CLS_MAIN_ENVIRONMENTAL_ZONE	(270100)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_ENVIRONMENTAL_ZONE_GREEN
	  #define TSA_RTE_SGN_CLS_MAIN_ENVIRONMENTAL_ZONE_GREEN	(270110)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_ENVIRONMENTAL_ZONE_END
	  #define TSA_RTE_SGN_CLS_MAIN_ENVIRONMENTAL_ZONE_END	(270200)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_005
	  #define TSA_RTE_SGN_CLS_MAIN_SL_005	(274505)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_005_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_005_ACTIVE	(274506)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_010
	  #define TSA_RTE_SGN_CLS_MAIN_SL_010	(274510)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_010_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_010_ACTIVE	(274511)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_015
	  #define TSA_RTE_SGN_CLS_MAIN_SL_015	(274515)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_015_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_015_ACTIVE	(274516)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_020
	  #define TSA_RTE_SGN_CLS_MAIN_SL_020	(274520)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_020_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_020_ACTIVE	(274521)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_025
	  #define TSA_RTE_SGN_CLS_MAIN_SL_025	(274525)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_025_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_025_ACTIVE	(274526)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_030
	  #define TSA_RTE_SGN_CLS_MAIN_SL_030	(274530)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_030_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_030_ACTIVE	(274531)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_035
	  #define TSA_RTE_SGN_CLS_MAIN_SL_035	(274535)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_035_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_035_ACTIVE	(274536)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_040
	  #define TSA_RTE_SGN_CLS_MAIN_SL_040	(274540)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_040_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_040_ACTIVE	(274541)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_045
	  #define TSA_RTE_SGN_CLS_MAIN_SL_045	(274545)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_045_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_045_ACTIVE	(274546)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_050
	  #define TSA_RTE_SGN_CLS_MAIN_SL_050	(274550)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_050_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_050_ACTIVE	(274551)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_055
	  #define TSA_RTE_SGN_CLS_MAIN_SL_055	(274555)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_055_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_055_ACTIVE	(274556)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_060
	  #define TSA_RTE_SGN_CLS_MAIN_SL_060	(274560)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_060_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_060_ACTIVE	(274561)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_065
	  #define TSA_RTE_SGN_CLS_MAIN_SL_065	(274565)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_065_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_065_ACTIVE	(274566)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_070
	  #define TSA_RTE_SGN_CLS_MAIN_SL_070	(274570)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_070_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_070_ACTIVE	(274571)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_075
	  #define TSA_RTE_SGN_CLS_MAIN_SL_075	(274575)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_075_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_075_ACTIVE	(274576)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_080
	  #define TSA_RTE_SGN_CLS_MAIN_SL_080	(274580)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_080_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_080_ACTIVE	(274581)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_085
	  #define TSA_RTE_SGN_CLS_MAIN_SL_085	(274585)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_085_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_085_ACTIVE	(274586)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_090
	  #define TSA_RTE_SGN_CLS_MAIN_SL_090	(274590)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_090_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_090_ACTIVE	(274591)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_095
	  #define TSA_RTE_SGN_CLS_MAIN_SL_095	(274595)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_095_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_095_ACTIVE	(274596)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_100
	  #define TSA_RTE_SGN_CLS_MAIN_SL_100	(274600)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_100_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_100_ACTIVE	(274601)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_110
	  #define TSA_RTE_SGN_CLS_MAIN_SL_110	(274610)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_110_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_110_ACTIVE	(274611)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_120
	  #define TSA_RTE_SGN_CLS_MAIN_SL_120	(274620)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_120_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_120_ACTIVE	(274621)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_130
	  #define TSA_RTE_SGN_CLS_MAIN_SL_130	(274630)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_130_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_130_ACTIVE	(274631)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_140
	  #define TSA_RTE_SGN_CLS_MAIN_SL_140	(274640)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_140_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_140_ACTIVE	(274641)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_150
	  #define TSA_RTE_SGN_CLS_MAIN_SL_150	(274650)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_150_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_150_ACTIVE	(274651)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_160
	  #define TSA_RTE_SGN_CLS_MAIN_SL_160	(274660)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_160_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_160_ACTIVE	(274661)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_170
	  #define TSA_RTE_SGN_CLS_MAIN_SL_170	(274670)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_170_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_170_ACTIVE	(274671)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_180
	  #define TSA_RTE_SGN_CLS_MAIN_SL_180	(274680)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_180_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_180_ACTIVE	(274681)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_190
	  #define TSA_RTE_SGN_CLS_MAIN_SL_190	(274690)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_190_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_SL_190_ACTIVE	(274691)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_GARBAGE
	  #define TSA_RTE_SGN_CLS_MAIN_GARBAGE	(274990)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_GARBAGE_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_GARBAGE_ACTIVE	(274991)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING
	  #define TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING	(276000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING_ACTIVE	(276001)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING
	  #define TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING	(277000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING_ACTIVE	(277001)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_BUNDLE_TWO_DIGIT_END
	  #define TSA_RTE_SGN_CLS_MAIN_BUNDLE_TWO_DIGIT_END	(278200)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_BUNDLE_TWO_DIGIT_END_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_BUNDLE_TWO_DIGIT_END_ACTIVE	(278201)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_BUNDLE_THREE_DIGIT_END
	  #define TSA_RTE_SGN_CLS_MAIN_BUNDLE_THREE_DIGIT_END	(278300)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_BUNDLE_THREE_DIGIT_END_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_BUNDLE_THREE_DIGIT_END_ACTIVE	(278301)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_005_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_005_END	(278505)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_010_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_010_END	(278510)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_015_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_015_END	(278515)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_020_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_020_END	(278520)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_025_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_025_END	(278525)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_030_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_030_END	(278530)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_035_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_035_END	(278535)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_040_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_040_END	(278540)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_045_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_045_END	(278545)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_050_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_050_END	(278550)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_055_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_055_END	(278555)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_060_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_060_END	(278560)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_065_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_065_END	(278565)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_070_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_070_END	(278570)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_075_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_075_END	(278575)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_080_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_080_END	(278580)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_085_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_085_END	(278585)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_090_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_090_END	(278590)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_095_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_095_END	(278595)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_100_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_100_END	(278600)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_110_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_110_END	(278610)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_120_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_120_END	(278620)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_130_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_130_END	(278630)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_140_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_140_END	(278640)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_150_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_150_END	(278650)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_160_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_160_END	(278660)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_170_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_170_END	(278670)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_180_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_180_END	(278680)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_SL_190_END
	  #define TSA_RTE_SGN_CLS_MAIN_SL_190_END	(278690)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_GARBAGE_END
	  #define TSA_RTE_SGN_CLS_MAIN_GARBAGE_END	(278990)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_GARBAGE_END_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_GARBAGE_END_ACTIVE	(278991)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING_END
	  #define TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING_END	(280000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING_END_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_CAR_NO_PASSING_END_ACTIVE	(280001)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_BUNDLE_NO_PASSING_END
	  #define TSA_RTE_SGN_CLS_MAIN_BUNDLE_NO_PASSING_END	(280100)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_BUNDLE_NO_PASSING_END_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_BUNDLE_NO_PASSING_END_ACTIVE	(280101)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING_END
	  #define TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING_END	(281000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING_END_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_TRUCK_NO_PASSING_END_ACTIVE	(281001)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_GENERAL_END
	  #define TSA_RTE_SGN_CLS_MAIN_GENERAL_END	(282000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_GENERAL_END_ACTIVE
	  #define TSA_RTE_SGN_CLS_MAIN_GENERAL_END_ACTIVE	(282001)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_HOUSE_BEGIN
	  #define TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_HOUSE_BEGIN	(290000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_HOUSE_END
	  #define TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_HOUSE_END	(290100)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_DANGER_CROSS_ROAD_SMALL_ROAD
	  #define TSA_RTE_SGN_CLS_DANGER_CROSS_ROAD_SMALL_ROAD	(301000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_BEGIN
	  #define TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_BEGIN	(310000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_END
	  #define TSA_RTE_SGN_CLS_MAIN_CITY_LIMIT_END	(311000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_PLAY_STREET_BEGIN
	  #define TSA_RTE_SGN_CLS_MAIN_PLAY_STREET_BEGIN	(325000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_PLAY_STREET_END
	  #define TSA_RTE_SGN_CLS_MAIN_PLAY_STREET_END	(326000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_HIGHWAY_BEGIN
	  #define TSA_RTE_SGN_CLS_MAIN_HIGHWAY_BEGIN	(330000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_MOTORWAY
	  #define TSA_RTE_SGN_CLS_MAIN_MOTORWAY	(330100)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_MOTORWAY_BEGIN
	  #define TSA_RTE_SGN_CLS_MAIN_MOTORWAY_BEGIN	(331000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_HIGHWAY_END
	  #define TSA_RTE_SGN_CLS_MAIN_HIGHWAY_END	(334000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_MAIN_MOTORWAY_END
	  #define TSA_RTE_SGN_CLS_MAIN_MOTORWAY_END	(336000)
	#endif
	#ifndef   TSA_RTE_SGN_CLS_CLUSTER_GARBAGE
	  #define TSA_RTE_SGN_CLS_CLUSTER_GARBAGE	(999990)
	#endif

/* typedef TsaRteSignDecisionBase_t */
	#ifndef   TSA_RTE_SGN_DEC_BASE_UKN
	  #define TSA_RTE_SGN_DEC_BASE_UKN	(0)
	#endif
	#ifndef   TSA_RTE_SGN_DEC_BASE_MAP_RULE
	  #define TSA_RTE_SGN_DEC_BASE_MAP_RULE	(1)
	#endif
	#ifndef   TSA_RTE_SGN_DEC_BASE_MAP_IMPL
	  #define TSA_RTE_SGN_DEC_BASE_MAP_IMPL	(2)
	#endif
	#ifndef   TSA_RTE_SGN_DEC_BASE_MAP_EXPL
	  #define TSA_RTE_SGN_DEC_BASE_MAP_EXPL	(3)
	#endif
	#ifndef   TSA_RTE_SGN_DEC_BASE_CAM
	  #define TSA_RTE_SGN_DEC_BASE_CAM	(4)
	#endif
	#ifndef   TSA_RTE_SGN_DEC_BASE_MAP_CAM
	  #define TSA_RTE_SGN_DEC_BASE_MAP_CAM	(5)
	#endif

/* typedef TsaRteSpeedUnit_t */
	#ifndef   TSA_RTE_SPD_UNT_UNKNOWN
	  #define TSA_RTE_SPD_UNT_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_SPD_UNT_KMH
	  #define TSA_RTE_SPD_UNT_KMH	(1)
	#endif
	#ifndef   TSA_RTE_SPD_UNT_MPH
	  #define TSA_RTE_SPD_UNT_MPH	(2)
	#endif
	#ifndef   TSA_RTE_SPD_UNT_BOTH
	  #define TSA_RTE_SPD_UNT_BOTH	(3)
	#endif
	#ifndef   TSA_RTE_SPD_UNT_SNA
	  #define TSA_RTE_SPD_UNT_SNA	(4)
	#endif

/* typedef TsaRteTrafficStyle_t */
	#ifndef   TSA_RTE_TRF_STL_UNKNOWN
	  #define TSA_RTE_TRF_STL_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_TRF_STL_RIGHTHAND
	  #define TSA_RTE_TRF_STL_RIGHTHAND	(1)
	#endif
	#ifndef   TSA_RTE_TRF_STL_LEFTHAND
	  #define TSA_RTE_TRF_STL_LEFTHAND	(2)
	#endif
	#ifndef   TSA_RTE_TRF_STL_SNA
	  #define TSA_RTE_TRF_STL_SNA	(3)
	#endif

/* typedef TsaRteWarning_t */
	#ifndef   TSA_RTE_WARN_OFF
	  #define TSA_RTE_WARN_OFF	(0)
	#endif
	#ifndef   TSA_RTE_WARN_ON
	  #define TSA_RTE_WARN_ON	(1)
	#endif
	#ifndef   TSA_RTE_WARN_SNA
	  #define TSA_RTE_WARN_SNA	(2)
	#endif

/* typedef TsaRteActivationStatus_t */
	#ifndef   TSA_RTE_ACTIVATION_STATUS_SNA
	  #define TSA_RTE_ACTIVATION_STATUS_SNA	(0)
	#endif
	#ifndef   TSA_RTE_ACTIVATION_STATUS_ON
	  #define TSA_RTE_ACTIVATION_STATUS_ON	(1)
	#endif
	#ifndef   TSA_RTE_ACTIVATION_STATUS_OFF
	  #define TSA_RTE_ACTIVATION_STATUS_OFF	(2)
	#endif

/* typedef TsaRteStreet_t */
	#ifndef   TSA_RTE_STREET_TYPE_SNA
	  #define TSA_RTE_STREET_TYPE_SNA	(0)
	#endif
	#ifndef   TSA_RTE_STREET_TYPE_CITY
	  #define TSA_RTE_STREET_TYPE_CITY	(1)
	#endif
	#ifndef   TSA_RTE_STREET_TYPE_OVERLAND
	  #define TSA_RTE_STREET_TYPE_OVERLAND	(2)
	#endif
	#ifndef   TSA_RTE_STREET_TYPE_MOTORWAY
	  #define TSA_RTE_STREET_TYPE_MOTORWAY	(3)
	#endif
	#ifndef   TSA_RTE_STREET_TYPE_RES
	  #define TSA_RTE_STREET_TYPE_RES	(4)
	#endif

/* typedef TsaRteSignVal_t */
	#ifndef   TSA_RTE_SIGN_VALIDITY_IDLE
	  #define TSA_RTE_SIGN_VALIDITY_IDLE	(0)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_UNLIM
	  #define TSA_RTE_SIGN_VALIDITY_UNLIM	(1)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_ICY
	  #define TSA_RTE_SIGN_VALIDITY_ICY	(2)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_FOG
	  #define TSA_RTE_SIGN_VALIDITY_FOG	(3)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_WET
	  #define TSA_RTE_SIGN_VALIDITY_WET	(4)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_TIME
	  #define TSA_RTE_SIGN_VALIDITY_TIME	(5)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_DARK
	  #define TSA_RTE_SIGN_VALIDITY_DARK	(6)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_EXT_LFT
	  #define TSA_RTE_SIGN_VALIDITY_EXT_LFT	(7)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_EXT_RGT
	  #define TSA_RTE_SIGN_VALIDITY_EXT_RGT	(8)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_TRAILER
	  #define TSA_RTE_SIGN_VALIDITY_TRAILER	(9)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_RESTRICTED
	  #define TSA_RTE_SIGN_VALIDITY_RESTRICTED	(10)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_RAIN
	  #define TSA_RTE_SIGN_VALIDITY_RAIN	(11)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_TRUCK
	  #define TSA_RTE_SIGN_VALIDITY_TRUCK	(12)
	#endif
	#ifndef   TSA_RTE_SIGN_VALIDITY_CAR
	  #define TSA_RTE_SIGN_VALIDITY_CAR	(13)
	#endif

/* typedef e_subStructureFilled_t */
	#ifndef   TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_NONE
	  #define TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_NONE	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_HI17
	  #define TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_HI17	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_TA19_EU
	  #define TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_TA19_EU	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_TA19_JP
	  #define TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_TA19_JP	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_SW19_CN
	  #define TSA_RTE_NAVI_SUBSTRUCTURE_FILLED_SW19_CN	(3)
	#endif

/* typedef e_naviFrwInfo_t */
	#ifndef   TSA_RTE_NAVI_HI17_FRW_NONE
	  #define TSA_RTE_NAVI_HI17_FRW_NONE	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_FRW_ENTRANCE
	  #define TSA_RTE_NAVI_HI17_FRW_ENTRANCE	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_FRW_EXIT
	  #define TSA_RTE_NAVI_HI17_FRW_EXIT	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_FRW_BRANCH
	  #define TSA_RTE_NAVI_HI17_FRW_BRANCH	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_FRW_RESTAREA
	  #define TSA_RTE_NAVI_HI17_FRW_RESTAREA	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_FRW_RES5
	  #define TSA_RTE_NAVI_HI17_FRW_RES5	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_FRW_RES6
	  #define TSA_RTE_NAVI_HI17_FRW_RES6	(6)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_FRW_INVALID
	  #define TSA_RTE_NAVI_HI17_FRW_INVALID	(7)
	#endif

/* typedef e_naviLinkClass_t */
	#ifndef   TSA_RTE_NAVI_HI17_LINK_UNKNOWN
	  #define TSA_RTE_NAVI_HI17_LINK_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_LINK_FREEWAY
	  #define TSA_RTE_NAVI_HI17_LINK_FREEWAY	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_LINK_IC
	  #define TSA_RTE_NAVI_HI17_LINK_IC	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_LINK_JC
	  #define TSA_RTE_NAVI_HI17_LINK_JC	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_LINK_RESTAREA
	  #define TSA_RTE_NAVI_HI17_LINK_RESTAREA	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_LINK_COUNTRY
	  #define TSA_RTE_NAVI_HI17_LINK_COUNTRY	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_LINK_ROUNDABOUT
	  #define TSA_RTE_NAVI_HI17_LINK_ROUNDABOUT	(6)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_LINK_INVALID
	  #define TSA_RTE_NAVI_HI17_LINK_INVALID	(7)
	#endif

/* typedef e_naviTollStation_t */
	#ifndef   TSA_RTE_NAVI_HI17_TOLL_NONE
	  #define TSA_RTE_NAVI_HI17_TOLL_NONE	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_TOLL_NORMAL
	  #define TSA_RTE_NAVI_HI17_TOLL_NORMAL	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_TOLL_ELECTRONIC
	  #define TSA_RTE_NAVI_HI17_TOLL_ELECTRONIC	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_TOLL_INVALID
	  #define TSA_RTE_NAVI_HI17_TOLL_INVALID	(3)
	#endif

/* typedef e_naviTimeSpdStatus_t */
	#ifndef   TSA_RTE_NAVI_HI17_TIME_SPD_NONE
	  #define TSA_RTE_NAVI_HI17_TIME_SPD_NONE	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_TIME_SPD_VALID
	  #define TSA_RTE_NAVI_HI17_TIME_SPD_VALID	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_TIME_SPD_UNLIMITED
	  #define TSA_RTE_NAVI_HI17_TIME_SPD_UNLIMITED	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_TIME_SPD_INVALID
	  #define TSA_RTE_NAVI_HI17_TIME_SPD_INVALID	(3)
	#endif

/* typedef e_naviTunnel_t */
	#ifndef   TSA_RTE_NAVI_HI17_TUNNEL_NONE
	  #define TSA_RTE_NAVI_HI17_TUNNEL_NONE	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_TUNNEL_ACTIVE
	  #define TSA_RTE_NAVI_HI17_TUNNEL_ACTIVE	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_TUNNEL_RES
	  #define TSA_RTE_NAVI_HI17_TUNNEL_RES	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_HI17_TUNNEL_INVALID
	  #define TSA_RTE_NAVI_HI17_TUNNEL_INVALID	(3)
	#endif

/* typedef TA19NSPDTYP_t */
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_UNKNOWN
	  #define TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_IMPLICIT
	  #define TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_IMPLICIT	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_ON_SIGN
	  #define TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_ON_SIGN	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_PROVISIONAL
	  #define TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_PROVISIONAL	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_VARIABLE
	  #define TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_EXPLICIT_VARIABLE	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_RESERVED
	  #define TSA_RTE_NAVI_TA19_EU_SPD_LMT_TYP_RESERVED	(5)
	#endif

/* typedef TA19NSPLSGN_t */
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPL_SIGN_UNKNOWN
	  #define TSA_RTE_NAVI_TA19_EU_SPL_SIGN_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPL_SIGN_NONE
	  #define TSA_RTE_NAVI_TA19_EU_SPL_SIGN_NONE	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPL_SIGN_TIME_PROVISION
	  #define TSA_RTE_NAVI_TA19_EU_SPL_SIGN_TIME_PROVISION	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPL_SIGN_WHEN_RAIN
	  #define TSA_RTE_NAVI_TA19_EU_SPL_SIGN_WHEN_RAIN	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPL_SIGN_WHEN_ICY
	  #define TSA_RTE_NAVI_TA19_EU_SPL_SIGN_WHEN_ICY	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_SPL_SIGN_RESERVED
	  #define TSA_RTE_NAVI_TA19_EU_SPL_SIGN_RESERVED	(5)
	#endif

/* typedef TA19FCRDCLS_t */
	#ifndef   TSA_RTE_NAVI_TA19_EU_UNKNOWN
	  #define TSA_RTE_NAVI_TA19_EU_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_FC1
	  #define TSA_RTE_NAVI_TA19_EU_FC1	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_FC2
	  #define TSA_RTE_NAVI_TA19_EU_FC2	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_FC3
	  #define TSA_RTE_NAVI_TA19_EU_FC3	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_FC4
	  #define TSA_RTE_NAVI_TA19_EU_FC4	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_FC5
	  #define TSA_RTE_NAVI_TA19_EU_FC5	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_reserved
	  #define TSA_RTE_NAVI_TA19_EU_reserved	(6)
	#endif

/* typedef TA19_RDCLS_t */
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_OFFROAD
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_OFFROAD	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_NONE
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_NONE	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FREEWAY_1
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FREEWAY_1	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FREEWAY_2
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FREEWAY_2	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_HIGHWAY
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_HIGHWAY	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_THROUGHWAY
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_THROUGHWAY	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_LOCAL
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_LOCAL	(6)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FRONTAGE
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FRONTAGE	(7)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_VERY_LOW_SPEED
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_VERY_LOW_SPEED	(8)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_PRIVATE
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_PRIVATE	(9)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_WALKWAY
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_WALKWAY	(10)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_NON_TSA_RTE_NAVI_TA19_EUGABLE
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_NON_TSA_RTE_NAVI_TA19_EUGABLE	(11)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FERRY
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_FERRY	(12)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_CAR_TRAIN
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_CAR_TRAIN	(13)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_PUBLIC_VEHICLE_ONLY
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_PUBLIC_VEHICLE_ONLY	(14)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_CARPOOL_LANE
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_CLASS_CARPOOL_LANE	(15)
	#endif

/* typedef TA19_LINKCLS_t */
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_UNKNOWN
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_NONE
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_NONE	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_MAIN_LINE_WITHOUT_MEDIAN_STRIP
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_MAIN_LINE_WITHOUT_MEDIAN_STRIP	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_MAIN_LINE_WITH_MEDIAN_STRIP
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_MAIN_LINE_WITH_MEDIAN_STRIP	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_CONNECT_ROAD_BETWEEN_MAIN_ROADS
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_CONNECT_ROAD_BETWEEN_MAIN_ROADS	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_INTERSECTION
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_INTERSECTION	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RAMP_LEFT_SIDE
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RAMP_LEFT_SIDE	(6)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RAMP_RIGHT_SIDE
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RAMP_RIGHT_SIDE	(7)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_PARALLEL_ROAD_OF_MAIN_LINE
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_PARALLEL_ROAD_OF_MAIN_LINE	(8)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_PARALLEL_ROAD_TO_THE_SA_ETC
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_PARALLEL_ROAD_TO_THE_SA_ETC	(9)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_ROTARY
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_ROTARY	(10)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED1
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED1	(11)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED2
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED2	(12)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED3
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED3	(13)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED4
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED4	(14)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED5
	  #define TSA_RTE_NAVI_TA19_EU_LINK_CLASS_RESERVED5	(15)
	#endif

/* typedef TA19_RDSTR_t */
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_UNKNOWN
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_NONE
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_NONE	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_TUNNEL
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_TUNNEL	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_BRIDGE
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_BRIDGE	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED1
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED1	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED2
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED2	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED3
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED3	(6)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED4
	  #define TSA_RTE_NAVI_TA19_EU_ROAD_STRUCTURE_RESERVED4	(7)
	#endif

/* typedef TA19_BUILTUP_t */
	#ifndef   TSA_RTE_NAVI_TA19_EU_BUILTUP_UNKNOWN
	  #define TSA_RTE_NAVI_TA19_EU_BUILTUP_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_BUILTUP_OUTSIDE
	  #define TSA_RTE_NAVI_TA19_EU_BUILTUP_OUTSIDE	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_BUILTUP_INSIDE
	  #define TSA_RTE_NAVI_TA19_EU_BUILTUP_INSIDE	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_BUILTUP_RESERVED
	  #define TSA_RTE_NAVI_TA19_EU_BUILTUP_RESERVED	(3)
	#endif

/* typedef TA19_NENTLNK_t */
	#ifndef   TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_UNKNOWN
	  #define TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_NONE
	  #define TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_NONE	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_LEFT
	  #define TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_LEFT	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RIGHT
	  #define TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RIGHT	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_STRAIGHT
	  #define TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_STRAIGHT	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED1
	  #define TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED1	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED2
	  #define TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED2	(6)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED3
	  #define TSA_RTE_NAVI_TA19_EU_NO_ENTRY_LINK_RESERVED3	(7)
	#endif

/* typedef TA19_MTCHCONF_t */
	#ifndef   TSA_RTE_NAVI_TA19_EU_MATCH_CONF_UNKNOWN
	  #define TSA_RTE_NAVI_TA19_EU_MATCH_CONF_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_MATCH_CONF_OFFROAD
	  #define TSA_RTE_NAVI_TA19_EU_MATCH_CONF_OFFROAD	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_MATCH_CONF_NOT_IDENTIFIED
	  #define TSA_RTE_NAVI_TA19_EU_MATCH_CONF_NOT_IDENTIFIED	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_MATCH_CONF_IDENTIFIED
	  #define TSA_RTE_NAVI_TA19_EU_MATCH_CONF_IDENTIFIED	(3)
	#endif

/* typedef TA19_ROUTSTS_t */
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROUTSTS_UNKNOWN
	  #define TSA_RTE_NAVI_TA19_EU_ROUTSTS_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROUTSTS_NO_ROUTING
	  #define TSA_RTE_NAVI_TA19_EU_ROUTSTS_NO_ROUTING	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_EU_ROUTSTS_ROUTING
	  #define TSA_RTE_NAVI_TA19_EU_ROUTSTS_ROUTING	(2)
	#endif

/* typedef TA19_RDC_t */
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_MOTORWAY_1
	  #define TSA_RTE_NAVI_TA19_JP_RDC_MOTORWAY_1	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_MOTORWAY_2
	  #define TSA_RTE_NAVI_TA19_JP_RDC_MOTORWAY_2	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_HIGHWAY
	  #define TSA_RTE_NAVI_TA19_JP_RDC_HIGHWAY	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_THOROUGHFARE
	  #define TSA_RTE_NAVI_TA19_JP_RDC_THOROUGHFARE	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_LOCAL_ROAD
	  #define TSA_RTE_NAVI_TA19_JP_RDC_LOCAL_ROAD	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_ROAD_1
	  #define TSA_RTE_NAVI_TA19_JP_RDC_ROAD_1	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_ROAD_2
	  #define TSA_RTE_NAVI_TA19_JP_RDC_ROAD_2	(6)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_PRIVATE_ROAD
	  #define TSA_RTE_NAVI_TA19_JP_RDC_PRIVATE_ROAD	(7)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_1
	  #define TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_1	(8)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_2
	  #define TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_2	(9)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_FERRY_ROUTE
	  #define TSA_RTE_NAVI_TA19_JP_RDC_FERRY_ROUTE	(10)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_PARKING_ROAD
	  #define TSA_RTE_NAVI_TA19_JP_RDC_PARKING_ROAD	(11)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_3
	  #define TSA_RTE_NAVI_TA19_JP_RDC_SIDE_ROAD_3	(12)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_RESERVED_1
	  #define TSA_RTE_NAVI_TA19_JP_RDC_RESERVED_1	(13)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_RESERVED_2
	  #define TSA_RTE_NAVI_TA19_JP_RDC_RESERVED_2	(14)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_RDC_INVALID
	  #define TSA_RTE_NAVI_TA19_JP_RDC_INVALID	(15)
	#endif

/* typedef TA19_LYT_t */
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_TRAFFIC_CIRCLE
	  #define TSA_RTE_NAVI_TA19_JP_LYT_TRAFFIC_CIRCLE	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_1
	  #define TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_1	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_2
	  #define TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_2	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_JUNCTION
	  #define TSA_RTE_NAVI_TA19_JP_LYT_JUNCTION	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_INTERSECTION
	  #define TSA_RTE_NAVI_TA19_JP_LYT_INTERSECTION	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_RAMP
	  #define TSA_RTE_NAVI_TA19_JP_LYT_RAMP	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_SIDE
	  #define TSA_RTE_NAVI_TA19_JP_LYT_TRUNK_SIDE	(6)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_SAPA
	  #define TSA_RTE_NAVI_TA19_JP_LYT_SAPA	(7)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_SHORTCUT_1
	  #define TSA_RTE_NAVI_TA19_JP_LYT_SHORTCUT_1	(8)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_SHORTCUT_2
	  #define TSA_RTE_NAVI_TA19_JP_LYT_SHORTCUT_2	(9)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_ROTARY
	  #define TSA_RTE_NAVI_TA19_JP_LYT_ROTARY	(10)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_CIRCLE
	  #define TSA_RTE_NAVI_TA19_JP_LYT_CIRCLE	(11)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_NO_DEFINITION_AREA
	  #define TSA_RTE_NAVI_TA19_JP_LYT_NO_DEFINITION_AREA	(12)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_RESERVED_1
	  #define TSA_RTE_NAVI_TA19_JP_LYT_RESERVED_1	(13)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_RESERVED_2
	  #define TSA_RTE_NAVI_TA19_JP_LYT_RESERVED_2	(14)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_LYT_INVALID
	  #define TSA_RTE_NAVI_TA19_JP_LYT_INVALID	(15)
	#endif

/* typedef TA19_BRANCH_t */
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_NONE
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_NONE	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_LEFT
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_LEFT	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RIGHT
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RIGHT	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RIGHT_AND_LEFT
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RIGHT_AND_LEFT	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_1
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_1	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_2
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_2	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_3
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_3	(6)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_4
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_4	(7)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_5
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_5	(8)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_6
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_6	(9)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_7
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_7	(10)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_8
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_8	(11)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_9
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_9	(12)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_10
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_10	(13)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_11
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_11	(14)
	#endif
	#ifndef   TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_12
	  #define TSA_RTE_NAVI_TA19_JP_BRANCH_RESERVED_12	(15)
	#endif

/* typedef eNav_CurrRoadType_t */
	#ifndef   TSA_RTE_NAVI_SW18_UNKNOWN
	  #define TSA_RTE_NAVI_SW18_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_SW18_HIGHWAY
	  #define TSA_RTE_NAVI_SW18_HIGHWAY	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_SW18_ROAD_CLASS_1
	  #define TSA_RTE_NAVI_SW18_ROAD_CLASS_1	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_SW18_ROAD_CLASS_2
	  #define TSA_RTE_NAVI_SW18_ROAD_CLASS_2	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_SW18_ROAD_CLASS_3
	  #define TSA_RTE_NAVI_SW18_ROAD_CLASS_3	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_SW18_ROAD_CLASS_4
	  #define TSA_RTE_NAVI_SW18_ROAD_CLASS_4	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_SW18_ROAD_CLASS_5
	  #define TSA_RTE_NAVI_SW18_ROAD_CLASS_5	(6)
	#endif

/* typedef e_NavSpeedLimitStatus_t */
	#ifndef   SL_UNKNOWN
	  #define SL_UNKNOWN	(0)
	#endif
	#ifndef   SL_EXISTS
	  #define SL_EXISTS	(1)
	#endif
	#ifndef   SL_RESERVED
	  #define SL_RESERVED	(2)
	#endif
	#ifndef   SL_PLURAL
	  #define SL_PLURAL	(3)
	#endif

/* typedef TsaRteNaviProvider_t */
	#ifndef   TSA_RTE_NAVI_PROVIDER_NOT_AVAILABLE
	  #define TSA_RTE_NAVI_PROVIDER_NOT_AVAILABLE	(0)
	#endif
	#ifndef   TSA_RTE_NAVI_PROVIDER_NAVTEQ
	  #define TSA_RTE_NAVI_PROVIDER_NAVTEQ	(1)
	#endif
	#ifndef   TSA_RTE_NAVI_PROVIDER_TOMTOM
	  #define TSA_RTE_NAVI_PROVIDER_TOMTOM	(2)
	#endif
	#ifndef   TSA_RTE_NAVI_PROVIDER_TELEATLAS
	  #define TSA_RTE_NAVI_PROVIDER_TELEATLAS	(3)
	#endif
	#ifndef   TSA_RTE_NAVI_PROVIDER_ZENRIN
	  #define TSA_RTE_NAVI_PROVIDER_ZENRIN	(4)
	#endif
	#ifndef   TSA_RTE_NAVI_PROVIDER_ADF
	  #define TSA_RTE_NAVI_PROVIDER_ADF	(5)
	#endif
	#ifndef   TSA_RTE_NAVI_PROVIDER_NAVINFO
	  #define TSA_RTE_NAVI_PROVIDER_NAVINFO	(6)
	#endif
	#ifndef   TSA_RTE_NAVI_PROVIDER_INVALID
	  #define TSA_RTE_NAVI_PROVIDER_INVALID	(7)
	#endif

/* typedef udw_suppress_warn_t */
	#ifndef   Udw_other_system_warn_inactive
	  #define Udw_other_system_warn_inactive	(0)
	#endif
	#ifndef   Udw_other_system_warn_active
	  #define Udw_other_system_warn_active	(1)
	#endif
	#ifndef   Udw_RestAdvisoryOff
	  #define Udw_RestAdvisoryOff	(2)
	#endif

/* typedef udw_interrupt_warn_t */
	#ifndef   Udw_NoInterruptWarning
	  #define Udw_NoInterruptWarning	(0)
	#endif
	#ifndef   Udw_InterruptWarning
	  #define Udw_InterruptWarning	(1)
	#endif

/* typedef UDW_ENABLE_t */
	#ifndef   UDW_SWITCH_OFF
	  #define UDW_SWITCH_OFF	(0)
	#endif
	#ifndef   UDW_SWITCH_ON
	  #define UDW_SWITCH_ON	(1)
	#endif

/* typedef UDW_SIZE_ANALYSIS_WINDOW_t */
	#ifndef   UDW_WIN_SIZE_MIN
	  #define UDW_WIN_SIZE_MIN	(15)
	#endif
	#ifndef   UDW_WIN_SIZE_DFT
	  #define UDW_WIN_SIZE_DFT	(20)
	#endif
	#ifndef   UDW_WIN_SIZE_MAX
	  #define UDW_WIN_SIZE_MAX	(25)
	#endif

/* typedef LastActivationState_t */
	#ifndef   UDW_STATE_NOT_ACTIVATED
	  #define UDW_STATE_NOT_ACTIVATED	(0)
	#endif
	#ifndef   UDW_STATE_ACTIVATED
	  #define UDW_STATE_ACTIVATED	(1)
	#endif

/* typedef LastSensitivity_t */
	#ifndef   UDW_SENS_LEVEL_1
	  #define UDW_SENS_LEVEL_1	(0)
	#endif
	#ifndef   UDW_SENS_LEVEL_2
	  #define UDW_SENS_LEVEL_2	(1)
	#endif
	#ifndef   UDW_SENS_LEVEL_3
	  #define UDW_SENS_LEVEL_3	(2)
	#endif
	#ifndef   UDW_SENS_LEVEL_4
	  #define UDW_SENS_LEVEL_4	(3)
	#endif

/* typedef udw_alert_sensitivity_t */
	#ifndef   Udw_sens_level_1
	  #define Udw_sens_level_1	(0)
	#endif
	#ifndef   Udw_sens_level_2
	  #define Udw_sens_level_2	(1)
	#endif
	#ifndef   Udw_sens_level_3
	  #define Udw_sens_level_3	(2)
	#endif
	#ifndef   Udw_sens_level_4
	  #define Udw_sens_level_4	(3)
	#endif

/* typedef eUdwActivationSwitch_t */
	#ifndef   Udw_Not_Activated
	  #define Udw_Not_Activated	(0)
	#endif
	#ifndef   Udw_Activated
	  #define Udw_Activated	(1)
	#endif

/* typedef udw_Warning_t */
	#ifndef   Udw_No_Warning
	  #define Udw_No_Warning	(0)
	#endif
	#ifndef   Udw_Warning_1
	  #define Udw_Warning_1	(1)
	#endif
	#ifndef   Udw_Warning_2
	  #define Udw_Warning_2	(2)
	#endif
	#ifndef   Udw_Warning_undefined
	  #define Udw_Warning_undefined	(3)
	#endif

/* typedef udw_attention_level_t */
	#ifndef   Udw_attention_level_Off
	  #define Udw_attention_level_Off	(0)
	#endif
	#ifndef   Udw_attention_level_1
	  #define Udw_attention_level_1	(1)
	#endif
	#ifndef   Udw_attention_level_2
	  #define Udw_attention_level_2	(2)
	#endif
	#ifndef   Udw_attention_level_3
	  #define Udw_attention_level_3	(3)
	#endif
	#ifndef   Udw_attention_level_4
	  #define Udw_attention_level_4	(4)
	#endif
	#ifndef   Udw_attention_level_5
	  #define Udw_attention_level_5	(5)
	#endif
	#ifndef   Udw_attention_level_6
	  #define Udw_attention_level_6	(6)
	#endif
	#ifndef   Udw_attention_level_undefined
	  #define Udw_attention_level_undefined	(7)
	#endif

/* typedef udw_status_t */
	#ifndef   Udw_status_off_signals_out_of_range
	  #define Udw_status_off_signals_out_of_range	(0)
	#endif
	#ifndef   Udw_status_on_able_to_warn
	  #define Udw_status_on_able_to_warn	(1)
	#endif
	#ifndef   Udw_status_on_warning_suppressed
	  #define Udw_status_on_warning_suppressed	(2)
	#endif
	#ifndef   Udw_status_on_warning_active
	  #define Udw_status_on_warning_active	(3)
	#endif
	#ifndef   Udw_status_on_temporary_not_available
	  #define Udw_status_on_temporary_not_available	(4)
	#endif
	#ifndef   Udw_status_off_permanently_not_available
	  #define Udw_status_off_permanently_not_available	(5)
	#endif

/* typedef VDYCaliState_t */
	#ifndef   VDY_CAL_INIT
	  #define VDY_CAL_INIT	(0)
	#endif
	#ifndef   VDY_CAL_YWR_OFFS_STST
	  #define VDY_CAL_YWR_OFFS_STST	(1)
	#endif
	#ifndef   VDY_CAL_YWR_OFFS_DYN
	  #define VDY_CAL_YWR_OFFS_DYN	(2)
	#endif
	#ifndef   VDY_CAL_WHS_OFFS
	  #define VDY_CAL_WHS_OFFS	(4)
	#endif
	#ifndef   VDY_CAL_SWA_OFFS
	  #define VDY_CAL_SWA_OFFS	(16)
	#endif
	#ifndef   VDY_CAL_LTA_OFFS
	  #define VDY_CAL_LTA_OFFS	(32)
	#endif
	#ifndef   VDY_CAL_SWA_GRAD
	  #define VDY_CAL_SWA_GRAD	(64)
	#endif
	#ifndef   VDY_CAL_WHS_LOAD
	  #define VDY_CAL_WHS_LOAD	(128)
	#endif

/* typedef VDYCtrlState_t */
	#ifndef   VDY_CTRL_STATE_STARTUP
	  #define VDY_CTRL_STATE_STARTUP	(0)
	#endif
	#ifndef   VDY_CTRL_STATE_INIT
	  #define VDY_CTRL_STATE_INIT	(1)
	#endif
	#ifndef   VDY_CTRL_STATE_RUNNING
	  #define VDY_CTRL_STATE_RUNNING	(2)
	#endif

/* typedef VDYIoStateTypes_t */
	#ifndef   VDY_IO_STATE_VALID
	  #define VDY_IO_STATE_VALID	(0)
	#endif
	#ifndef   VDY_IO_STATE_INVALID
	  #define VDY_IO_STATE_INVALID	(1)
	#endif
	#ifndef   VDY_IO_STATE_NOTAVAIL
	  #define VDY_IO_STATE_NOTAVAIL	(2)
	#endif
	#ifndef   VDY_IO_STATE_DECREASED
	  #define VDY_IO_STATE_DECREASED	(3)
	#endif
	#ifndef   VDY_IO_STATE_SUBSTITUE
	  #define VDY_IO_STATE_SUBSTITUE	(4)
	#endif
	#ifndef   VDY_IO_STATE_INPLAUSIBLE
	  #define VDY_IO_STATE_INPLAUSIBLE	(5)
	#endif
	#ifndef   VDY_IO_STATE_INIT
	  #define VDY_IO_STATE_INIT	(15)
	#endif
	#ifndef   VDY_IO_STATE_MAX
	  #define VDY_IO_STATE_MAX	(255)
	#endif

/* typedef VehDynStatePos_t */
	#ifndef   VDY_SOUT_POS_VELOCITY
	  #define VDY_SOUT_POS_VELOCITY	(0)
	#endif
	#ifndef   VDY_SOUT_POS_ACCEL
	  #define VDY_SOUT_POS_ACCEL	(1)
	#endif
	#ifndef   VDY_SOUT_POS_YAWRATE
	  #define VDY_SOUT_POS_YAWRATE	(2)
	#endif
	#ifndef   VDY_SOUT_POS_CURVE
	  #define VDY_SOUT_POS_CURVE	(3)
	#endif
	#ifndef   VDY_SOUT_POS_DRVINTCURVE
	  #define VDY_SOUT_POS_DRVINTCURVE	(4)
	#endif
	#ifndef   VDY_SOUT_POS_LATERALACCEL
	  #define VDY_SOUT_POS_LATERALACCEL	(5)
	#endif
	#ifndef   VDY_SOUT_POS_SLIPANGLE
	  #define VDY_SOUT_POS_SLIPANGLE	(6)
	#endif
	#ifndef   VDY_SOUT_POS_MOTIONSTATE
	  #define VDY_SOUT_POS_MOTIONSTATE	(7)
	#endif
	#ifndef   VDY_SOUT_POS_SELFSTEERING
	  #define VDY_SOUT_POS_SELFSTEERING	(8)
	#endif
	#ifndef   VDY_SOUT_POS_MAX
	  #define VDY_SOUT_POS_MAX	(9)
	#endif

	/* typedef VehDynStatePos_t */
    // #ifndef VDY_SOUT_POS_CURVE
    //     #define VDY_SOUT_POS_CURVE 0U
    // #endif
    #ifndef VDY_SOUT_POS_YWR
        //#define VDY_SOUT_POS_YWR 1U
        #define VDY_SOUT_POS_YWR VDY_SOUT_POS_YAWRATE
    #endif
    #ifndef VDY_SOUT_POS_DRCRV
        //#define VDY_SOUT_POS_DRCRV 2U
        #define VDY_SOUT_POS_DRCRV VDY_SOUT_POS_DRVINTCURVE
    #endif
    #ifndef VDY_SOUT_POS_VEL
        //#define VDY_SOUT_POS_VEL 3U
        #define VDY_SOUT_POS_VEL VDY_SOUT_POS_VELOCITY
    #endif
    // #ifndef VDY_SOUT_POS_ACCEL
    //     #define VDY_SOUT_POS_ACCEL 4U
    // #endif
    #ifndef VDY_SOUT_POS_MSTAT
        //#define VDY_SOUT_POS_MSTAT 5U
        #define VDY_SOUT_POS_MSTAT VDY_SOUT_POS_MOTIONSTATE
    #endif
    #ifndef VDY_SOUT_POS_VCORR
        #define VDY_SOUT_POS_VCORR 6U
    #endif
    #ifndef VDY_SOUT_POS_SSA
        #define VDY_SOUT_POS_SSA 7U
    #endif
    #ifndef VDY_SOUT_POS_LATACC
        //#define VDY_SOUT_POS_LATACC 8U
        #define VDY_SOUT_POS_LATACC VDY_SOUT_POS_LATERALACCEL
    #endif
    #ifndef VDY_SOUT_POS_RAW_YWR
        #define VDY_SOUT_POS_RAW_YWR 9U
    #endif
    #ifndef VDY_SOUT_POS_RAW_VEL
        #define VDY_SOUT_POS_RAW_VEL 10U
    #endif
    #ifndef VDY_SOUT_POS_MAX
        #define VDY_SOUT_POS_MAX 12U
    #endif

/* typedef VehSigMainStatePos_t */
	#ifndef   VDY_SIN_POS_YWR
	  #define VDY_SIN_POS_YWR	(0)
	#endif
	#ifndef   VDY_SIN_POS_YWR_TEMP
	  #define VDY_SIN_POS_YWR_TEMP	(1)
	#endif
	#ifndef   VDY_SIN_POS_SWA
	  #define VDY_SIN_POS_SWA	(2)
	#endif
	#ifndef   VDY_SIN_POS_LATA
	  #define VDY_SIN_POS_LATA	(3)
	#endif
	#ifndef   VDY_SIN_POS_WVEL_FL
	  #define VDY_SIN_POS_WVEL_FL	(4)
	#endif
	#ifndef   VDY_SIN_POS_WVEL_FR
	  #define VDY_SIN_POS_WVEL_FR	(5)
	#endif
	#ifndef   VDY_SIN_POS_WVEL_RL
	  #define VDY_SIN_POS_WVEL_RL	(6)
	#endif
	#ifndef   VDY_SIN_POS_WVEL_RR
	  #define VDY_SIN_POS_WVEL_RR	(7)
	#endif
	#ifndef   VDY_SIN_POS_YWRINT
	  #define VDY_SIN_POS_YWRINT	(8)
	#endif
	#ifndef   VDY_SIN_POS_YWRINT_TEMP
	  #define VDY_SIN_POS_YWRINT_TEMP	(9)
	#endif
	#ifndef   VDY_SIN_POS_LONGA
	  #define VDY_SIN_POS_LONGA	(10)
	#endif
	#ifndef   VDY_SIN_POS_RSTA
	  #define VDY_SIN_POS_RSTA	(11)
	#endif
	#ifndef   VDY_SIN_POS_VEHVEL_EXT
	  #define VDY_SIN_POS_VEHVEL_EXT	(12)
	#endif
	#ifndef   VDY_SIN_POS_VEHACL_EXT
	  #define VDY_SIN_POS_VEHACL_EXT	(13)
	#endif
	#ifndef   VDY_SIN_POS_WDIR_FL
	  #define VDY_SIN_POS_WDIR_FL	(14)
	#endif
	#ifndef   VDY_SIN_POS_WDIR_FR
	  #define VDY_SIN_POS_WDIR_FR	(15)
	#endif
	#ifndef   VDY_SIN_POS_WDIR_RL
	  #define VDY_SIN_POS_WDIR_RL	(16)
	#endif
	#ifndef   VDY_SIN_POS_WDIR_RR
	  #define VDY_SIN_POS_WDIR_RR	(17)
	#endif
	#ifndef   VDY_SIN_POS_WTCKS_FL
	  #define VDY_SIN_POS_WTCKS_FL	(18)
	#endif
	#ifndef   VDY_SIN_POS_WTCKS_FR
	  #define VDY_SIN_POS_WTCKS_FR	(19)
	#endif
	#ifndef   VDY_SIN_POS_WTCKS_RL
	  #define VDY_SIN_POS_WTCKS_RL	(20)
	#endif
	#ifndef   VDY_SIN_POS_WTCKS_RR
	  #define VDY_SIN_POS_WTCKS_RR	(21)
	#endif
	#ifndef   VDY_SIN_POS_GEAR
	  #define VDY_SIN_POS_GEAR	(22)
	#endif
	#ifndef   VDY_SIN_POS_BRAKE
	  #define VDY_SIN_POS_BRAKE	(23)
	#endif
	#ifndef   VDY_SIN_POS_PBRK
	  #define VDY_SIN_POS_PBRK	(24)
	#endif
	#ifndef   VDY_SIN_POS_VDIR
	  #define VDY_SIN_POS_VDIR	(25)
	#endif
	#ifndef   VDY_SIN_POS_VMOT
	  #define VDY_SIN_POS_VMOT	(26)
	#endif
	#ifndef   VDY_SIN_POS_DUMMY
	  #define VDY_SIN_POS_DUMMY	(27)
	#endif
	#ifndef   VDY_SIN_POS_CRV
	  #define VDY_SIN_POS_CRV	(28)
	#endif
	#ifndef   VDY_SIN_POS_SSA
	  #define VDY_SIN_POS_SSA	(29)
	#endif
	#ifndef   VDY_SIN_POS_MAX
	  #define VDY_SIN_POS_MAX	(32)
	#endif

/* typedef VehSigAddStatePos_t */
	#ifndef   VEH_SIG_ADD_ENV_TEMP
	  #define VEH_SIG_ADD_ENV_TEMP	(0)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_STATE
	  #define VEH_SIG_ADD_WIPER_STATE	(1)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_STAGE
	  #define VEH_SIG_ADD_WIPER_STAGE	(2)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_OUT_PARK_POS
	  #define VEH_SIG_ADD_WIPER_OUT_PARK_POS	(3)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_WASHER_FRONT
	  #define VEH_SIG_ADD_WIPER_WASHER_FRONT	(4)
	#endif
	#ifndef   VEH_SIG_ADD_RAIN_SENSOR
	  #define VEH_SIG_ADD_RAIN_SENSOR	(5)
	#endif
	#ifndef   VEH_SIG_ADD_TURN_SIGNAL
	  #define VEH_SIG_ADD_TURN_SIGNAL	(6)
	#endif
	#ifndef   VEH_SIG_ADD_FOG_LAMP_FRONT
	  #define VEH_SIG_ADD_FOG_LAMP_FRONT	(7)
	#endif
	#ifndef   VEH_SIG_ADD_FOG_LAMP_REAR
	  #define VEH_SIG_ADD_FOG_LAMP_REAR	(8)
	#endif
	#ifndef   VEH_SIG_ADD_ROAD_WHL_ANG_FR
	  #define VEH_SIG_ADD_ROAD_WHL_ANG_FR	(9)
	#endif
	#ifndef   VEH_SIG_ADD_ROAD_WHL_ANG_RE
	  #define VEH_SIG_ADD_ROAD_WHL_ANG_RE	(10)
	#endif
	#ifndef   VEH_SIG_ADD_ODOMETER
	  #define VEH_SIG_ADD_ODOMETER	(11)
	#endif
	#ifndef   VEH_SIG_ADD_GAS_PEDAL_POS
	  #define VEH_SIG_ADD_GAS_PEDAL_POS	(12)
	#endif
	#ifndef   VEH_SIG_ADD_KICK_DOWN
	  #define VEH_SIG_ADD_KICK_DOWN	(13)
	#endif
	#ifndef   VEH_SIG_ADD_BRAKE_PEDAL_PRESSED
	  #define VEH_SIG_ADD_BRAKE_PEDAL_PRESSED	(14)
	#endif
	#ifndef   VEH_SIG_ADD_DRIVER_TIRED
	  #define VEH_SIG_ADD_DRIVER_TIRED	(15)
	#endif
	#ifndef   VEH_SIG_ADD_SPEED_UNIT
	  #define VEH_SIG_ADD_SPEED_UNIT	(16)
	#endif
	#ifndef   VEH_SIG_ADD_SPEEDO_SPEED
	  #define VEH_SIG_ADD_SPEEDO_SPEED	(17)
	#endif
	#ifndef   VEH_SIG_ADD_TRAILER_CON
	  #define VEH_SIG_ADD_TRAILER_CON	(18)
	#endif
	#ifndef   VEH_SIG_ADD_TRAILER_CON_BEF_SHUTDOWN
	  #define VEH_SIG_ADD_TRAILER_CON_BEF_SHUTDOWN	(19)
	#endif
	#ifndef   VEH_SIG_ADD_TRAILER_LENGTH_INPUT
	  #define VEH_SIG_ADD_TRAILER_LENGTH_INPUT	(20)
	#endif
	#ifndef   VEH_SIG_ADD_PARK_AID_DET_L
	  #define VEH_SIG_ADD_PARK_AID_DET_L	(21)
	#endif
	#ifndef   VEH_SIG_ADD_PARK_AID_DET_CL
	  #define VEH_SIG_ADD_PARK_AID_DET_CL	(22)
	#endif
	#ifndef   VEH_SIG_ADD_PARK_AID_DET_CR
	  #define VEH_SIG_ADD_PARK_AID_DET_CR	(23)
	#endif
	#ifndef   VEH_SIG_ADD_PARK_AID_DET_R
	  #define VEH_SIG_ADD_PARK_AID_DET_R	(24)
	#endif
	#ifndef   VEH_SIG_ADD_IGN_SWITCH
	  #define VEH_SIG_ADD_IGN_SWITCH	(25)
	#endif
	#ifndef   VEH_SIG_ADD_HEIGHT_LEVEL
	  #define VEH_SIG_ADD_HEIGHT_LEVEL	(26)
	#endif
	#ifndef   VEH_SIG_ADD_WHEEL_HEIGHT_LEVEL
	  #define VEH_SIG_ADD_WHEEL_HEIGHT_LEVEL	(27)
	#endif
	#ifndef   VEH_SIG_ADD_MAX_LCF
	  #define VEH_SIG_ADD_MAX_LCF	(28)
	#endif

/* typedef VehParMainStatePos_t */
	#ifndef   VDY_PAR_POS_SSG
	  #define VDY_PAR_POS_SSG	(0)
	#endif
	#ifndef   VDY_PAR_POS_SWARAT
	  #define VDY_PAR_POS_SWARAT	(1)
	#endif
	#ifndef   VDY_PAR_POS_WBASE
	  #define VDY_PAR_POS_WBASE	(2)
	#endif
	#ifndef   VDY_PAR_POS_TWDFR
	  #define VDY_PAR_POS_TWDFR	(3)
	#endif
	#ifndef   VDY_PAR_POS_TWDRE
	  #define VDY_PAR_POS_TWDRE	(4)
	#endif
	#ifndef   VDY_PAR_POS_VEHWGT
	  #define VDY_PAR_POS_VEHWGT	(5)
	#endif
	#ifndef   VDY_PAR_POS_COGH
	  #define VDY_PAR_POS_COGH	(6)
	#endif
	#ifndef   VDY_PAR_POS_AXLD
	  #define VDY_PAR_POS_AXLD	(7)
	#endif
	#ifndef   VDY_PAR_POS_WHLDFR
	  #define VDY_PAR_POS_WHLDFR	(8)
	#endif
	#ifndef   VDY_PAR_POS_WHLDRE
	  #define VDY_PAR_POS_WHLDRE	(9)
	#endif
	#ifndef   VDY_PAR_POS_WHLCIR
	  #define VDY_PAR_POS_WHLCIR	(10)
	#endif
	#ifndef   VDY_PAR_POS_DRVAXL
	  #define VDY_PAR_POS_DRVAXL	(11)
	#endif
	#ifndef   VDY_PAR_POS_WTCKSREV
	  #define VDY_PAR_POS_WTCKSREV	(12)
	#endif
	#ifndef   VDY_PAR_POS_CSFR
	  #define VDY_PAR_POS_CSFR	(13)
	#endif
	#ifndef   VDY_PAR_POS_CSRE
	  #define VDY_PAR_POS_CSRE	(14)
	#endif
	#ifndef   VDY_PAR_POS_MAX
	  #define VDY_PAR_POS_MAX	(16)
	#endif

/* typedef VehParAddStatePos_t */
	#ifndef   VEH_PAR_ADD_VEHICLE_WIDTH
	  #define VEH_PAR_ADD_VEHICLE_WIDTH	(0)
	#endif
	#ifndef   VEH_PAR_ADD_VEHICLE_LENGTH
	  #define VEH_PAR_ADD_VEHICLE_LENGTH	(1)
	#endif
	#ifndef   VEH_PAR_ADD_CURB_WEIGHT
	  #define VEH_PAR_ADD_CURB_WEIGHT	(2)
	#endif
	#ifndef   VEH_PAR_ADD_OVERHANG_FRONT
	  #define VEH_PAR_ADD_OVERHANG_FRONT	(3)
	#endif
	#ifndef   VEH_PAR_ADD_FRONT_AXLE_ROAD
	  #define VEH_PAR_ADD_FRONT_AXLE_ROAD	(4)
	#endif
	#ifndef   VEH_PAR_ADD_WHEEL_WIDTH
	  #define VEH_PAR_ADD_WHEEL_WIDTH	(5)
	#endif
	#ifndef   VEH_PAR_ADD_STEERING_VARIANT
	  #define VEH_PAR_ADD_STEERING_VARIANT	(6)
	#endif
	#ifndef   VEH_PAR_ADD_PASSABLE_HEIGHT
	  #define VEH_PAR_ADD_PASSABLE_HEIGHT	(7)
	#endif
	#ifndef   VEH_PAR_ADD_DIST_CAMERA_HOOD_X
	  #define VEH_PAR_ADD_DIST_CAMERA_HOOD_X	(8)
	#endif
	#ifndef   VEH_PAR_ADD_DIST_CAMERA_HOOD_Y
	  #define VEH_PAR_ADD_DIST_CAMERA_HOOD_Y	(9)
	#endif
	#ifndef   VEH_PAR_ADD_MAX
	  #define VEH_PAR_ADD_MAX	(12)
	#endif

/* typedef VehParSenMountStatePos_t */
	#ifndef   VEH_PAR_SEN_MOUNT_LAT_POS
	  #define VEH_PAR_SEN_MOUNT_LAT_POS	(0)
	#endif
	#ifndef   VEH_PAR_SEN_MOUNT_LONG_POS
	  #define VEH_PAR_SEN_MOUNT_LONG_POS	(1)
	#endif
	#ifndef   VEH_PAR_SEN_MOUNT_VERT_POS
	  #define VEH_PAR_SEN_MOUNT_VERT_POS	(2)
	#endif
	#ifndef   VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG
	  #define VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG	(3)
	#endif
	#ifndef   VEH_PAR_SEN_MOUNT_PITCH_ANGLE
	  #define VEH_PAR_SEN_MOUNT_PITCH_ANGLE	(4)
	#endif
	#ifndef   VEH_PAR_SEN_MOUNT_ORIENTATION
	  #define VEH_PAR_SEN_MOUNT_ORIENTATION	(5)
	#endif
	#ifndef   VEH_PAR_SEN_MOUNT_ROLL_ANGLE
	  #define VEH_PAR_SEN_MOUNT_ROLL_ANGLE	(6)
	#endif
	#ifndef   VEH_PAR_SEN_MOUNT_YAW_ANGLE
	  #define VEH_PAR_SEN_MOUNT_YAW_ANGLE	(7)
	#endif
	#ifndef   VEH_PAR_SEN_MOUNT_MAX
	  #define VEH_PAR_SEN_MOUNT_MAX	(8)
	#endif

/* typedef VehParSensorStatePos_t */
	#ifndef   VEH_PAR_SENSOR_COVER_DAMPING
	  #define VEH_PAR_SENSOR_COVER_DAMPING	(0)
	#endif
	#ifndef   VEH_PAR_SENSOR_COVERAGE_ANGLE
	  #define VEH_PAR_SENSOR_COVERAGE_ANGLE	(1)
	#endif
	#ifndef   VEH_PAR_SENSOR_LOBE_ANGLE
	  #define VEH_PAR_SENSOR_LOBE_ANGLE	(2)
	#endif
	#ifndef   VEH_PAR_SENSOR_CYCLE_TIME
	  #define VEH_PAR_SENSOR_CYCLE_TIME	(3)
	#endif
	#ifndef   VEH_PAR_SENSOR_NO_OF_SCANS
	  #define VEH_PAR_SENSOR_NO_OF_SCANS	(4)
	#endif
	#ifndef   VEH_PAR_SENSOR_MAX
	  #define VEH_PAR_SENSOR_MAX	(8)
	#endif

/* typedef VehSigBrakeStatePos_t */
	#ifndef   VEH_SIG_BRAKE_ABS
	  #define VEH_SIG_BRAKE_ABS	(0)
	#endif
	#ifndef   VEH_SIG_BRAKE_TSC
	  #define VEH_SIG_BRAKE_TSC	(1)
	#endif
	#ifndef   VEH_SIG_BRAKE_MAX
	  #define VEH_SIG_BRAKE_MAX	(2)
	#endif

/* typedef VehSigPowertrainStatePos_t */
	#ifndef   VEH_SIG_POWERTRAIN_ACTUALGEAR
	  #define VEH_SIG_POWERTRAIN_ACTUALGEAR	(0)
	#endif
	#ifndef   VEH_SIG_POWERTRAIN_TARGETGEAR
	  #define VEH_SIG_POWERTRAIN_TARGETGEAR	(1)
	#endif
	#ifndef   VEH_SIG_POWERTRAIN_ENGINE_RUNNING
	  #define VEH_SIG_POWERTRAIN_ENGINE_RUNNING	(2)
	#endif
	#ifndef   VEH_SIG_POWERTRAIN_MAX
	  #define VEH_SIG_POWERTRAIN_MAX	(4)
	#endif

/* typedef VDYNvmState_t */
	#ifndef   VDY_NVM_POS_SWA
	  #define VDY_NVM_POS_SWA	(0)
	#endif
	#ifndef   VDY_NVM_POS_SSG
	  #define VDY_NVM_POS_SSG	(2)
	#endif
	#ifndef   VDY_NVM_POS_YWR
	  #define VDY_NVM_POS_YWR	(4)
	#endif
	#ifndef   VDY_NVM_POS_LATACC
	  #define VDY_NVM_POS_LATACC	(6)
	#endif
	#ifndef   VDY_NVM_POS_VELCORR
	  #define VDY_NVM_POS_VELCORR	(8)
	#endif
	#ifndef   VDY_NVM_POS_WLD
	  #define VDY_NVM_POS_WLD	(10)
	#endif
	#ifndef   VDY_NVM_POS_MAX
	  #define VDY_NVM_POS_MAX	(125000)
	#endif

/* typedef LongDirState_t */
	#ifndef   VDY_LONG_DIR_VOID
	  #define VDY_LONG_DIR_VOID	(0)
	#endif
	#ifndef   VDY_LONG_DIR_FWD
	  #define VDY_LONG_DIR_FWD	(1)
	#endif
	#ifndef   VDY_LONG_DIR_RWD
	  #define VDY_LONG_DIR_RWD	(2)
	#endif

/* typedef VDYDrvAxle_t */
	#ifndef   VDY_DRV_AXLE_UNKNOWN
	  #define VDY_DRV_AXLE_UNKNOWN	(0)
	#endif
	#ifndef   VDY_DRV_AXLE_ALL_LCF
	  #define VDY_DRV_AXLE_ALL_LCF	(1)
	#endif
	#ifndef   VDY_DRV_AXLE_FRONT
	  #define VDY_DRV_AXLE_FRONT	(1)
	#endif
	#ifndef   VDY_DRV_AXLE_REAR
	  #define VDY_DRV_AXLE_REAR	(2)
	#endif

/* typedef VDYTrailerConnection_t */
	#ifndef   VEH_SIG_ADD_TRLR_NO_DETECT
	  #define VEH_SIG_ADD_TRLR_NO_DETECT	(0)
	#endif
	#ifndef   VEH_SIG_ADD_TRLR_OK
	  #define VEH_SIG_ADD_TRLR_OK	(1)
	#endif
	#ifndef   VEH_SIG_ADD_TRLR_NDEF2
	  #define VEH_SIG_ADD_TRLR_NDEF2	(2)
	#endif
	#ifndef   VEH_SIG_ADD_TRLR_SNA
	  #define VEH_SIG_ADD_TRLR_SNA	(3)
	#endif

/* typedef VelocityCorrectionQuality_t */
	#ifndef   VDY_NO_VELO_CORR
	  #define VDY_NO_VELO_CORR	(0)
	#endif
	#ifndef   VDY_VELO_CORR_QUAL_EEPROM_LCF
	  #define VDY_VELO_CORR_QUAL_EEPROM_LCF	(1)
	#endif
	#ifndef   VDY_VELO_CORR_QUAL_RANGE_NVERIFIED_LCF
	  #define VDY_VELO_CORR_QUAL_RANGE_NVERIFIED_LCF	(2)
	#endif
	#ifndef   VDY_VELO_CORR_QUAL_RANGE_VERIFIED_LCF
	  #define VDY_VELO_CORR_QUAL_RANGE_VERIFIED_LCF	(3)
	#endif
	#ifndef   VDY_VELO_CORR_QUAL_SNA_LCF
	  #define VDY_VELO_CORR_QUAL_SNA_LCF	(4)
	#endif

/* typedef MotState_t */
	#ifndef   VDY_LONG_MOT_STATE_MOVE
	  #define VDY_LONG_MOT_STATE_MOVE	(0)
	#endif
	#ifndef   VDY_LONG_MOT_STATE_MOVE_FWD
	  #define VDY_LONG_MOT_STATE_MOVE_FWD	(1)
	#endif
	#ifndef   VDY_LONG_MOT_STATE_MOVE_RWD
	  #define VDY_LONG_MOT_STATE_MOVE_RWD	(2)
	#endif
	#ifndef   VDY_LONG_MOT_STATE_STDST
	  #define VDY_LONG_MOT_STATE_STDST	(3)
	#endif

/* typedef ActGearPos_t */
	#ifndef   ACT_GEAR_POS_NEUTRAL
	  #define ACT_GEAR_POS_NEUTRAL	(0)
	#endif
	#ifndef   ACT_GEAR_POS_PARKING
	  #define ACT_GEAR_POS_PARKING	(1)
	#endif
	#ifndef   ACT_GEAR_POS_FORWARD
	  #define ACT_GEAR_POS_FORWARD	(2)
	#endif
	#ifndef   ACT_GEAR_POS_REVERSE
	  #define ACT_GEAR_POS_REVERSE	(3)
	#endif

/* typedef ParkBrakeState_t */
	#ifndef   STAT_INACTIVE
	  #define STAT_INACTIVE	(0)
	#endif
	#ifndef   STAT_ACTIVE
	  #define STAT_ACTIVE	(1)
	#endif

/* typedef VehLongMotStateExt_t */
	#ifndef   VDY_VEH_MOT_STATE_ROLLING
	  #define VDY_VEH_MOT_STATE_ROLLING	(0)
	#endif
	#ifndef   VDY_VEH_MOT_STATE_FAST_STST
	  #define VDY_VEH_MOT_STATE_FAST_STST	(1)
	#endif
	#ifndef   VDY_VEH_MOT_STATE_SECURE_STST
	  #define VDY_VEH_MOT_STATE_SECURE_STST	(2)
	#endif

/* typedef WiperState_t */
	#ifndef   VEH_SIG_ADD_WIPER_STATE_INACTIVE
	  #define VEH_SIG_ADD_WIPER_STATE_INACTIVE	(0)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_STATE_ACTIVE
	  #define VEH_SIG_ADD_WIPER_STATE_ACTIVE	(1)
	#endif

/* typedef WiperStage_t */
	#ifndef   VEH_SIG_ADD_WIPER_OFF
	  #define VEH_SIG_ADD_WIPER_OFF	(0)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_INTERVAL1
	  #define VEH_SIG_ADD_WIPER_INTERVAL1	(1)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_INTERVAL2
	  #define VEH_SIG_ADD_WIPER_INTERVAL2	(2)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_INTERVAL3
	  #define VEH_SIG_ADD_WIPER_INTERVAL3	(3)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_INTERVAL4
	  #define VEH_SIG_ADD_WIPER_INTERVAL4	(4)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_STAGE1
	  #define VEH_SIG_ADD_WIPER_STAGE1	(5)
	#endif
	#ifndef   VEH_SIG_ADD_WIPER_STAGE2
	  #define VEH_SIG_ADD_WIPER_STAGE2	(6)
	#endif

/* typedef WiperWasherFrontState_t */
	#ifndef   VEH_SIG_ADD_WWS_IDLE
	  #define VEH_SIG_ADD_WWS_IDLE	(0)
	#endif
	#ifndef   VEH_SIG_ADD_WWS_TIPWIPE
	  #define VEH_SIG_ADD_WWS_TIPWIPE	(1)
	#endif
	#ifndef   VEH_SIG_ADD_WWS_WASH
	  #define VEH_SIG_ADD_WWS_WASH	(2)
	#endif

/* typedef TurnSignal_t */
	#ifndef   VEH_SIG_ADD_TURN_SIG_UNKNOWN
	  #define VEH_SIG_ADD_TURN_SIG_UNKNOWN	(0)
	#endif
	#ifndef   VEH_SIG_ADD_TURN_SIG_LEFT
	  #define VEH_SIG_ADD_TURN_SIG_LEFT	(1)
	#endif
	#ifndef   VEH_SIG_ADD_TURN_SIG_RIGHT
	  #define VEH_SIG_ADD_TURN_SIG_RIGHT	(2)
	#endif
	#ifndef   VEH_SIG_ADD_TURN_SIG_NEUTRAL
	  #define VEH_SIG_ADD_TURN_SIG_NEUTRAL	(3)
	#endif
	#ifndef   VEH_SIG_ADD_TURN_SIG_BOTH
	  #define VEH_SIG_ADD_TURN_SIG_BOTH	(4)
	#endif

/* typedef SpeedUnit_t */
	#ifndef   VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN
	  #define VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN	(0)
	#endif
	#ifndef   VEH_SIG_ADD_SPEEDO_UNIT_KMH
	  #define VEH_SIG_ADD_SPEEDO_UNIT_KMH	(1)
	#endif
	#ifndef   VEH_SIG_ADD_SPEEDO_UNIT_MPH
	  #define VEH_SIG_ADD_SPEEDO_UNIT_MPH	(2)
	#endif

/* typedef IgnitionSwitch_t */
	#ifndef   VEH_SIG_ADD_IGN_LOCK
	  #define VEH_SIG_ADD_IGN_LOCK	(0)
	#endif
	#ifndef   VEH_SIG_ADD_IGN_OFF
	  #define VEH_SIG_ADD_IGN_OFF	(1)
	#endif
	#ifndef   VEH_SIG_ADD_IGN_ACC
	  #define VEH_SIG_ADD_IGN_ACC	(2)
	#endif
	#ifndef   VEH_SIG_ADD_IGN_ON
	  #define VEH_SIG_ADD_IGN_ON	(4)
	#endif
	#ifndef   VEH_SIG_ADD_IGN_START
	  #define VEH_SIG_ADD_IGN_START	(5)
	#endif

/* typedef eSuspensionSystem_t */
	#ifndef   VEH_SIG_ADD_NO_ACTIVE_SUSPENSION
	  #define VEH_SIG_ADD_NO_ACTIVE_SUSPENSION	(0)
	#endif
	#ifndef   VEH_SIG_ADD_ACTIVE_SUSPENSION
	  #define VEH_SIG_ADD_ACTIVE_SUSPENSION	(1)
	#endif

/* typedef eHeightLevel_t */
	#ifndef   VEH_SIG_ADD_NO_HEIGHT_LVL
	  #define VEH_SIG_ADD_NO_HEIGHT_LVL	(0)
	#endif
	#ifndef   VEH_SIG_ADD_HEIGHT_LVL_NORMAL
	  #define VEH_SIG_ADD_HEIGHT_LVL_NORMAL	(1)
	#endif
	#ifndef   VEH_SIG_ADD_HEIGHT_LVL_LOW
	  #define VEH_SIG_ADD_HEIGHT_LVL_LOW	(2)
	#endif
	#ifndef   VEH_SIG_ADD_HEIGHT_LVL_HIGH
	  #define VEH_SIG_ADD_HEIGHT_LVL_HIGH	(4)
	#endif

/* typedef TransmissionGear_t */
	#ifndef   DYN_GEAR_NEUTRAL_GEAR
	  #define DYN_GEAR_NEUTRAL_GEAR	(0)
	#endif
	#ifndef   DYN_GEAR_FIRST_GEAR
	  #define DYN_GEAR_FIRST_GEAR	(1)
	#endif
	#ifndef   DYN_GEAR_SECOND_GEAR
	  #define DYN_GEAR_SECOND_GEAR	(2)
	#endif
	#ifndef   DYN_GEAR_THIRD_GEAR
	  #define DYN_GEAR_THIRD_GEAR	(3)
	#endif
	#ifndef   DYN_GEAR_FOURTH_GEAR
	  #define DYN_GEAR_FOURTH_GEAR	(4)
	#endif
	#ifndef   DYN_GEAR_FIFTH_GEAR
	  #define DYN_GEAR_FIFTH_GEAR	(5)
	#endif
	#ifndef   DYN_GEAR_SIXTH_GEAR
	  #define DYN_GEAR_SIXTH_GEAR	(6)
	#endif
	#ifndef   DYN_GEAR_SEVENTH_GEAR
	  #define DYN_GEAR_SEVENTH_GEAR	(7)
	#endif
	#ifndef   DYN_GEAR_EIGHTH_GEAR
	  #define DYN_GEAR_EIGHTH_GEAR	(8)
	#endif
	#ifndef   DYN_GEAR_NINTH_GEAR
	  #define DYN_GEAR_NINTH_GEAR	(9)
	#endif
	#ifndef   DYN_GEAR_REVERSE_GEAR
	  #define DYN_GEAR_REVERSE_GEAR	(10)
	#endif
	#ifndef   DYN_GEAR_PARK_GEAR
	  #define DYN_GEAR_PARK_GEAR	(11)
	#endif
	#ifndef   DYN_GEAR_POWER_FREE
	  #define DYN_GEAR_POWER_FREE	(12)
	#endif
	#ifndef   DYN_GEAR_POWER_INVALID
	  #define DYN_GEAR_POWER_INVALID	(255)
	#endif

/* typedef SteeringVariant_t */
	#ifndef   VEH_PAR_ADD_STEERING_VAR_UNKNOWN
	  #define VEH_PAR_ADD_STEERING_VAR_UNKNOWN	(0)
	#endif
	#ifndef   VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE
	  #define VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE	(1)
	#endif
	#ifndef   VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE
	  #define VEH_PAR_ADD_STEERING_VAR_RIGHT_SIDE	(2)
	#endif

/* typedef Orientation_t */
	#ifndef   SENSOR_OR_NORMAL
	  #define SENSOR_OR_NORMAL	(0)
	#endif
	#ifndef   SENSOR_OR_ROTATED
	  #define SENSOR_OR_ROTATED	(1)
	#endif

/* typedef VDYErrState_t */
	#ifndef   VDY_ERR_STATE_UNKNOWN
	  #define VDY_ERR_STATE_UNKNOWN	(0)
	#endif
	#ifndef   VDY_ERR_STATE_ACTIVE
	  #define VDY_ERR_STATE_ACTIVE	(1)
	#endif
	#ifndef   VDY_ERR_STATE_INACTIVE
	  #define VDY_ERR_STATE_INACTIVE	(2)
	#endif

/* typedef VodcaDominantDirection_t */
	#ifndef   VODCA_DOMINANT_DIRECTION_VERT
	  #define VODCA_DOMINANT_DIRECTION_VERT	(0)
	#endif
	#ifndef   VODCA_DOMINANT_DIRECTION_HORZ
	  #define VODCA_DOMINANT_DIRECTION_HORZ	(1)
	#endif
	#ifndef   VODCA_DOMINANT_DIRECTION_NONE
	  #define VODCA_DOMINANT_DIRECTION_NONE	(2)
	#endif

/* typedef FrameType_t */
	#ifndef   IC_FRAME_TYPE_EVEN
	  #define IC_FRAME_TYPE_EVEN	(0)
	#endif
	#ifndef   IC_FRAME_TYPE_ODD
	  #define IC_FRAME_TYPE_ODD	(1)
	#endif

/* typedef ResponseCurve_t */
	#ifndef   IC_RESPONSE_CURVE_TYPE_4X_16X
	  #define IC_RESPONSE_CURVE_TYPE_4X_16X	(1)
	#endif
	#ifndef   IC_RESPONSE_CURVE_TYPE_16X_16X
	  #define IC_RESPONSE_CURVE_TYPE_16X_16X	(2)
	#endif

/* typedef CFAPos_t */
	#ifndef   IC_CFA_POS_0
	  #define IC_CFA_POS_0	(0)
	#endif
	#ifndef   IC_CFA_POS_1
	  #define IC_CFA_POS_1	(1)
	#endif
	#ifndef   IC_CFA_POS_2
	  #define IC_CFA_POS_2	(2)
	#endif
	#ifndef   IC_CFA_POS_3
	  #define IC_CFA_POS_3	(3)
	#endif
	#ifndef   IC_CFA_POS_MAX
	  #define IC_CFA_POS_MAX	(4)
	#endif

/* typedef DcgState_t */
	#ifndef   IC_DCG_LOW
	  #define IC_DCG_LOW	(0)
	#endif
	#ifndef   IC_DCG_HIGH
	  #define IC_DCG_HIGH	(1)
	#endif

/* typedef ImagerCFA_t */
	#ifndef   IC_IMAGER_CFA_UNKNOWN
	  #define IC_IMAGER_CFA_UNKNOWN	(0)
	#endif
	#ifndef   IC_IMAGER_CFA_CCCC
	  #define IC_IMAGER_CFA_CCCC	(1)
	#endif
	#ifndef   IC_IMAGER_CFA_RGGB
	  #define IC_IMAGER_CFA_RGGB	(2)
	#endif
	#ifndef   IC_IMAGER_CFA_BGGR
	  #define IC_IMAGER_CFA_BGGR	(3)
	#endif
	#ifndef   IC_IMAGER_CFA_GRBG
	  #define IC_IMAGER_CFA_GRBG	(4)
	#endif
	#ifndef   IC_IMAGER_CFA_GBRG
	  #define IC_IMAGER_CFA_GBRG	(5)
	#endif
	#ifndef   IC_IMAGER_CFA_RCGB
	  #define IC_IMAGER_CFA_RCGB	(6)
	#endif
	#ifndef   IC_IMAGER_CFA_GBRC
	  #define IC_IMAGER_CFA_GBRC	(7)
	#endif
	#ifndef   IC_IMAGER_CFA_CRBG
	  #define IC_IMAGER_CFA_CRBG	(8)
	#endif
	#ifndef   IC_IMAGER_CFA_BGCR
	  #define IC_IMAGER_CFA_BGCR	(9)
	#endif
	#ifndef   IC_IMAGER_CFA_RCCB
	  #define IC_IMAGER_CFA_RCCB	(10)
	#endif
	#ifndef   IC_IMAGER_CFA_RCCC
	  #define IC_IMAGER_CFA_RCCC	(14)
	#endif

/* typedef e_IntradayState_t */
	#ifndef   IC_INTRADAY_STATE_NIGHT
	  #define IC_INTRADAY_STATE_NIGHT	(0)
	#endif
	#ifndef   IC_INTRADAY_STATE_DAY
	  #define IC_INTRADAY_STATE_DAY	(1)
	#endif

/* typedef IOB_t_ColorChannel */
	#ifndef   IOB_COLOR_CHANNEL_ALL
	  #define IOB_COLOR_CHANNEL_ALL	(0)
	#endif
	#ifndef   IOB_COLOR_CHANNEL_G1
	  #define IOB_COLOR_CHANNEL_G1	(1)
	#endif
	#ifndef   IOB_COLOR_CHANNEL_G2
	  #define IOB_COLOR_CHANNEL_G2	(2)
	#endif
	#ifndef   IOB_COLOR_CHANNEL_R
	  #define IOB_COLOR_CHANNEL_R	(3)
	#endif
	#ifndef   IOB_COLOR_CHANNEL_B
	  #define IOB_COLOR_CHANNEL_B	(4)
	#endif

/* typedef IOB_t_SocState */
	#ifndef   IOB_MODE_ERROR
	  #define IOB_MODE_ERROR	(0)
	#endif
	#ifndef   IOB_MODE_READY
	  #define IOB_MODE_READY	(1)
	#endif
	#ifndef   IOB_MODE_ACQUIRING
	  #define IOB_MODE_ACQUIRING	(2)
	#endif
	#ifndef   IOB_MODE_IMAGE_AVAILABLE
	  #define IOB_MODE_IMAGE_AVAILABLE	(3)
	#endif
	#ifndef   IOB_MODE_DOWNLOADING
	  #define IOB_MODE_DOWNLOADING	(4)
	#endif

/* typedef t_HMI_On_Off_Switch_t */
	#ifndef   HMI_ONOFF_SWITCH_ON
	  #define HMI_ONOFF_SWITCH_ON	(0)
	#endif
	#ifndef   HMI_ONOFF_SWITCH_OFF
	  #define HMI_ONOFF_SWITCH_OFF	(1)
	#endif
	#ifndef   HMI_ONOFF_SWITCH_INVLAID
	  #define HMI_ONOFF_SWITCH_INVLAID	(2)
	#endif

/* typedef t_HMI_Warning_Levels_t */
	#ifndef   HMI_WARN_LEVEL_EARLY
	  #define HMI_WARN_LEVEL_EARLY	(0)
	#endif
	#ifndef   HMI_WARN_LEVEL_MID
	  #define HMI_WARN_LEVEL_MID	(1)
	#endif
	#ifndef   HMI_WARN_LEVEL_LATE
	  #define HMI_WARN_LEVEL_LATE	(2)
	#endif
	#ifndef   HMI_WARN_LEVEL_INVALID
	  #define HMI_WARN_LEVEL_INVALID	(3)
	#endif

/* typedef MTS_VirtAddrs */
	#ifndef   ABD_MEAS_ID_OUTPUT_DATA
	  #define ABD_MEAS_ID_OUTPUT_DATA	(820445184)
	#endif
	#ifndef   ACAL_RTE_MEAS_ID_OUT_NVM
	  #define ACAL_RTE_MEAS_ID_OUT_NVM	(831537152)
	#endif
	#ifndef   CB_IPC_MEAS_ID_PROVIDED_OUTPUTS
	  #define CB_IPC_MEAS_ID_PROVIDED_OUTPUTS	(537485568)
	#endif
	#ifndef   CB_MEAS_ID_ALGO_COMP_STATE
	  #define CB_MEAS_ID_ALGO_COMP_STATE	(537485312)
	#endif
	#ifndef   CB_MEAS_ID_BUS_DEBUG_DATA
	  #define CB_MEAS_ID_BUS_DEBUG_DATA	(537489664)
	#endif
	#ifndef   CB_MEAS_ID_COMMON_ALGO_DATA
	  #define CB_MEAS_ID_COMMON_ALGO_DATA	(537473280)
	#endif
	#ifndef   CB_MEAS_ID_CPAR
	  #define CB_MEAS_ID_CPAR	(537482240)
	#endif
	#ifndef   CB_MEAS_ID_CTRL_BSW_DATA
	  #define CB_MEAS_ID_CTRL_BSW_DATA	(537481216)
	#endif
	#ifndef   CB_MEAS_ID_HEATING_REQUEST
	  #define CB_MEAS_ID_HEATING_REQUEST	(537489408)
	#endif
	#ifndef   CB_MEAS_ID_INTEGRATION_DATA
	  #define CB_MEAS_ID_INTEGRATION_DATA	(537468928)
	#endif
	#ifndef   CB_MEAS_ID_KERNEL_INPUT
	  #define CB_MEAS_ID_KERNEL_INPUT	(537460736)
	#endif
	#ifndef   CB_MEAS_ID_PROVIDED_OUTPUTS
	  #define CB_MEAS_ID_PROVIDED_OUTPUTS	(537493504)
	#endif
	#ifndef   CB_MEAS_ID_SIGNALS_HEADERS
	  #define CB_MEAS_ID_SIGNALS_HEADERS	(537481472)
	#endif
	#ifndef   CB_MEAS_ID_SPECIFIC_ALGO_DATA
	  #define CB_MEAS_ID_SPECIFIC_ALGO_DATA	(537477120)
	#endif
	#ifndef   CB_MEAS_ID_WRP_ERROR_DATA
	  #define CB_MEAS_ID_WRP_ERROR_DATA	(537481984)
	#endif
	#ifndef   CIPP_MEAS_ID_CTRL_BSW_DATA
	  #define CIPP_MEAS_ID_CTRL_BSW_DATA	(810549248)
	#endif
	#ifndef   CIPP_MEAS_ID_CTRL_BSW_DATA_PVT
	  #define CIPP_MEAS_ID_CTRL_BSW_DATA_PVT	(810553344)
	#endif
	#ifndef   CIPP_MEAS_ID_DEBUG_STATE
	  #define CIPP_MEAS_ID_DEBUG_STATE	(810688512)
	#endif
	#ifndef   CIPP_MEAS_ID_EVEN_GRADIENT_P1
	  #define CIPP_MEAS_ID_EVEN_GRADIENT_P1	(810620672)
	#endif
	#ifndef   CIPP_MEAS_ID_EVEN_GRADIENT_P2
	  #define CIPP_MEAS_ID_EVEN_GRADIENT_P2	(810692864)
	#endif
	#ifndef   CIPP_MEAS_ID_EVEN_SAT_P1
	  #define CIPP_MEAS_ID_EVEN_SAT_P1	(810693120)
	#endif
	#ifndef   CIPP_MEAS_ID_EVEN_U_P1
	  #define CIPP_MEAS_ID_EVEN_U_P1	(810619648)
	#endif
	#ifndef   CIPP_MEAS_ID_EVEN_V_P1
	  #define CIPP_MEAS_ID_EVEN_V_P1	(810619904)
	#endif
	#ifndef   CIPP_MEAS_ID_EVEN_Y_P0
	  #define CIPP_MEAS_ID_EVEN_Y_P0	(810622976)
	#endif
	#ifndef   CIPP_MEAS_ID_EVEN_Y_P1
	  #define CIPP_MEAS_ID_EVEN_Y_P1	(810619392)
	#endif
	#ifndef   CIPP_MEAS_ID_IMG_STAT
	  #define CIPP_MEAS_ID_IMG_STAT	(810621184)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_U_P1
	  #define CIPP_MEAS_ID_ODD_U_P1	(810616064)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_U_P2
	  #define CIPP_MEAS_ID_ODD_U_P2	(810616320)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_U_P3
	  #define CIPP_MEAS_ID_ODD_U_P3	(810616576)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_U_P4
	  #define CIPP_MEAS_ID_ODD_U_P4	(810616832)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_V_P1
	  #define CIPP_MEAS_ID_ODD_V_P1	(810617088)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_V_P2
	  #define CIPP_MEAS_ID_ODD_V_P2	(810617344)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_V_P3
	  #define CIPP_MEAS_ID_ODD_V_P3	(810617600)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_V_P4
	  #define CIPP_MEAS_ID_ODD_V_P4	(810617856)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_Y_P0
	  #define CIPP_MEAS_ID_ODD_Y_P0	(810614784)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_Y_P1
	  #define CIPP_MEAS_ID_ODD_Y_P1	(810615040)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_Y_P2
	  #define CIPP_MEAS_ID_ODD_Y_P2	(810615296)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_Y_P3
	  #define CIPP_MEAS_ID_ODD_Y_P3	(810615552)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_Y_P4
	  #define CIPP_MEAS_ID_ODD_Y_P4	(810615808)
	#endif
	#ifndef   CIPP_MEAS_ID_REQPORTS
	  #define CIPP_MEAS_ID_REQPORTS	(810684416)
	#endif
	#ifndef   CIPP_MEAS_ID_STATE
	  #define CIPP_MEAS_ID_STATE	(810620160)
	#endif
	#ifndef   CIPP_MEAS_ID_SYNCREF
	  #define CIPP_MEAS_ID_SYNCREF	(810680320)
	#endif
	#ifndef   CIPP_MEAS_ID_WBR
	  #define CIPP_MEAS_ID_WBR	(810620928)
	#endif
	#ifndef   ECM_MEASID_SYNCVDY_VDYOFFSETS
	  #define ECM_MEASID_SYNCVDY_VDYOFFSETS	(821174272)
	#endif
	#ifndef   ECM_MEASID_SYNCVDY_VEHDYN
	  #define ECM_MEASID_SYNCVDY_VEHDYN	(821178368)
	#endif
	#ifndef   ECM_MEASID_SYNCVDY_VEHPAR
	  #define ECM_MEASID_SYNCVDY_VEHPAR	(821182464)
	#endif
	#ifndef   ECM_MEASID_SYNCVDY_VEHSIG
	  #define ECM_MEASID_SYNCVDY_VEHSIG	(821186560)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_COMP_STATE
	  #define ECM_RTE_MEAS_ID_COMP_STATE	(821105408)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_CTRL_BSW_DATA
	  #define ECM_RTE_MEAS_ID_CTRL_BSW_DATA	(821035008)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_DIAG_INPUT
	  #define ECM_RTE_MEAS_ID_DIAG_INPUT	(821035184)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_ENV_FOV_DATA
	  #define ECM_RTE_MEAS_ID_ENV_FOV_DATA	(821100544)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_IN_CPAR
	  #define ECM_RTE_MEAS_ID_IN_CPAR	(821035776)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_IN_NVM
	  #define ECM_RTE_MEAS_ID_IN_NVM	(821035520)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_OUTPUT
	  #define ECM_RTE_MEAS_ID_OUTPUT	(821105152)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_OUT_ALGO_HIS
	  #define ECM_RTE_MEAS_ID_OUT_ALGO_HIS	(821108736)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_OUT_MONOCALIBRATION_CROI
	  #define ECM_RTE_MEAS_ID_OUT_MONOCALIBRATION_CROI	(821111040)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_OUT_MONOCALIBRATION_EOL_LEFT
	  #define ECM_RTE_MEAS_ID_OUT_MONOCALIBRATION_EOL_LEFT	(821113600)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_OUT_MONOCALIBRATION_EOL_RIGHT
	  #define ECM_RTE_MEAS_ID_OUT_MONOCALIBRATION_EOL_RIGHT	(821110272)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_OUT_MONOCALIBRATION_IMAGER
	  #define ECM_RTE_MEAS_ID_OUT_MONOCALIBRATION_IMAGER	(821110528)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_OUT_MONOCALIBRATION_RROI
	  #define ECM_RTE_MEAS_ID_OUT_MONOCALIBRATION_RROI	(821113088)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_OUT_NVM
	  #define ECM_RTE_MEAS_ID_OUT_NVM	(821110016)
	#endif
	#ifndef   ECM_RTE_MEAS_ID_ROI_DATA
	  #define ECM_RTE_MEAS_ID_ROI_DATA	(821105488)
	#endif
	#ifndef   EMO_MEAS_ID_CPAR
	  #define EMO_MEAS_ID_CPAR	(816841216)
	#endif
	#ifndef   EMO_MEAS_ID_EMO_INPUT
	  #define EMO_MEAS_ID_EMO_INPUT	(816963584)
	#endif
	#ifndef   EMO_MEAS_ID_EMO_TO_NVM
	  #define EMO_MEAS_ID_EMO_TO_NVM	(816934912)
	#endif
	#ifndef   EMO_MEAS_ID_ERROR_CODE
	  #define EMO_MEAS_ID_ERROR_CODE	(816959488)
	#endif
	#ifndef   EMO_MEAS_ID_EXPORT
	  #define EMO_MEAS_ID_EXPORT	(816955392)
	#endif
	#ifndef   EMO_MEAS_ID_FTRC_MEASFREEZE
	  #define EMO_MEAS_ID_FTRC_MEASFREEZE	(817057792)
	#endif
	#ifndef   EMO_MEAS_ID_FTRC_REQUEST_GRID
	  #define EMO_MEAS_ID_FTRC_REQUEST_GRID	(817061888)
	#endif
	#ifndef   EMO_MEAS_ID_FTRC_SEEDKILL_LIST
	  #define EMO_MEAS_ID_FTRC_SEEDKILL_LIST	(816930816)
	#endif
	#ifndef   EMO_MEAS_ID_MONO_CALIBRATION_CROI
	  #define EMO_MEAS_ID_MONO_CALIBRATION_CROI	(816914432)
	#endif
	#ifndef   EMO_MEAS_ID_MONO_CALIBRATION_IMAGER
	  #define EMO_MEAS_ID_MONO_CALIBRATION_IMAGER	(816910336)
	#endif
	#ifndef   EMO_MEAS_ID_MONO_CALIBRATION_RROI
	  #define EMO_MEAS_ID_MONO_CALIBRATION_RROI	(816918528)
	#endif
	#ifndef   EMO_MEAS_ID_SLAM_CAM2CAM
	  #define EMO_MEAS_ID_SLAM_CAM2CAM	(817049600)
	#endif
	#ifndef   EMO_MEAS_ID_SLAM_FEATURES
	  #define EMO_MEAS_ID_SLAM_FEATURES	(816975872)
	#endif
	#ifndef   EMO_MEAS_ID_SLAM_GROUNDPLANE
	  #define EMO_MEAS_ID_SLAM_GROUNDPLANE	(817053696)
	#endif
	#ifndef   EM_MEAS_ID_BASE_CTRL_DATA
	  #define EM_MEAS_ID_BASE_CTRL_DATA	(537919568)
	#endif
	#ifndef   EM_MEAS_ID_CAM_OBJECT_LIST
	  #define EM_MEAS_ID_CAM_OBJECT_LIST	(538652672)
	#endif
	#ifndef   EM_MEAS_ID_CLEARANCE_DETECTION
	  #define EM_MEAS_ID_CLEARANCE_DETECTION	(538050560)
	#endif
	#ifndef   EM_MEAS_ID_CUSTOM_OUTPUT_LCF
	  #define EM_MEAS_ID_CUSTOM_OUTPUT_LCF	(538959872)
	#endif
	#ifndef   EM_MEAS_ID_DEBUG_DATA
	  #define EM_MEAS_ID_DEBUG_DATA	(538116096)
	#endif
	#ifndef   EM_MEAS_ID_EAB_FEATURE_LIST
	  #define EM_MEAS_ID_EAB_FEATURE_LIST	(538067968)
	#endif
	#ifndef   EM_MEAS_ID_GEN_LANDMARK_LIST
	  #define EM_MEAS_ID_GEN_LANDMARK_LIST	(538705920)
	#endif
	#ifndef   EM_MEAS_ID_GEN_OBJECT_LIST
	  #define EM_MEAS_ID_GEN_OBJECT_LIST	(538640384)
	#endif
	#ifndef   EM_MEAS_ID_GSS_DYNAMIC_MAP
	  #define EM_MEAS_ID_GSS_DYNAMIC_MAP	(538247168)
	#endif
	#ifndef   EM_MEAS_ID_GSS_SEGMENTATION
	  #define EM_MEAS_ID_GSS_SEGMENTATION	(538296320)
	#endif
	#ifndef   EM_MEAS_ID_PC_REQUEST_PATCHES
	  #define EM_MEAS_ID_PC_REQUEST_PATCHES	(538312704)
	#endif
	#ifndef   EM_MEAS_ID_PED_OUTPUT
	  #define EM_MEAS_ID_PED_OUTPUT	(538010880)
	#endif
	#ifndef   EM_MEAS_ID_RUM_IMG_PROC_RQS
	  #define EM_MEAS_ID_RUM_IMG_PROC_RQS	(538378240)
	#endif
	#ifndef   EM_MEAS_ID_STATE
	  #define EM_MEAS_ID_STATE	(538066688)
	#endif
	#ifndef   EM_MEAS_ID_SYNC_REF
	  #define EM_MEAS_ID_SYNC_REF	(538181632)
	#endif
	#ifndef   EM_MEAS_ID_T0_OBJECT_LIST_MCAM
	  #define EM_MEAS_ID_T0_OBJECT_LIST_MCAM	(538509312)
	#endif
	#ifndef   EM_MEAS_ID_VCL_OUTPUT
	  #define EM_MEAS_ID_VCL_OUTPUT	(538009600)
	#endif
	#ifndef   FAMO_MEAS_ID_ALGO_STATE
	  #define FAMO_MEAS_ID_ALGO_STATE	(830603264)
	#endif
	#ifndef   FAMO_MEAS_ID_BASE_CTRL_DATA
	  #define FAMO_MEAS_ID_BASE_CTRL_DATA	(830537728)
	#endif
	#ifndef   FAMO_MEAS_ID_OUTPUT
	  #define FAMO_MEAS_ID_OUTPUT	(830668800)
	#endif
	#ifndef   FCT_MEAS_ID_ALDW_INPUT_GEN
	  #define FCT_MEAS_ID_ALDW_INPUT_GEN	(539427328)
	#endif
	#ifndef   FCT_MEAS_ID_ALDW_OUTPUT_GEN
	  #define FCT_MEAS_ID_ALDW_OUTPUT_GEN	(539427072)
	#endif
	#ifndef   FCT_MEAS_ID_ALDW_PAR
	  #define FCT_MEAS_ID_ALDW_PAR	(539794688)
	#endif
	#ifndef   FCT_MEAS_ID_CAM_LANE_INPUT_VADDR
	  #define FCT_MEAS_ID_CAM_LANE_INPUT_VADDR	(539521024)
	#endif
	#ifndef   FCT_MEAS_ID_CD_CUSTOM_OUTPUT
	  #define FCT_MEAS_ID_CD_CUSTOM_OUTPUT	(539496448)
	#endif
	#ifndef   FCT_MEAS_ID_CGEB_CD_DATA
	  #define FCT_MEAS_ID_CGEB_CD_DATA	(539140096)
	#endif
	#ifndef   FCT_MEAS_ID_CGEB_DIM_DATA
	  #define FCT_MEAS_ID_CGEB_DIM_DATA	(539142144)
	#endif
	#ifndef   FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT
	  #define FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT	(539502080)
	#endif
	#ifndef   FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA
	  #define FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA	(539504128)
	#endif
	#ifndef   FCT_MEAS_ID_CGEB_HEAD_CUSTOM_DATA
	  #define FCT_MEAS_ID_CGEB_HEAD_CUSTOM_DATA	(539501568)
	#endif
	#ifndef   FCT_MEAS_ID_CGEB_HEAD_DATA
	  #define FCT_MEAS_ID_CGEB_HEAD_DATA	(539143168)
	#endif
	#ifndef   FCT_MEAS_ID_CGEB_HEAD_GSM_DATA
	  #define FCT_MEAS_ID_CGEB_HEAD_GSM_DATA	(539500544)
	#endif
	#ifndef   FCT_MEAS_ID_CGEB_HEAD_OUTFUNC_DATA_LCF
	  #define FCT_MEAS_ID_CGEB_HEAD_OUTFUNC_DATA_LCF	(539144192)
	#endif
	#ifndef   FCT_MEAS_ID_CPAR_FCT_LKS_PARAMETERS
	  #define FCT_MEAS_ID_CPAR_FCT_LKS_PARAMETERS	(539440384)
	#endif
	#ifndef   FCT_MEAS_ID_CPAR_FCT_PARAMETERS
	  #define FCT_MEAS_ID_CPAR_FCT_PARAMETERS	(539796480)
	#endif
	#ifndef   FCT_MEAS_ID_DIM_INPUT_CUSTOM
	  #define FCT_MEAS_ID_DIM_INPUT_CUSTOM	(539165440)
	#endif
	#ifndef   FCT_MEAS_ID_DIM_INPUT_GENERIC
	  #define FCT_MEAS_ID_DIM_INPUT_GENERIC	(539164928)
	#endif
	#ifndef   FCT_MEAS_ID_DIM_OUTPUT_CUSTOM
	  #define FCT_MEAS_ID_DIM_OUTPUT_CUSTOM	(539167744)
	#endif
	#ifndef   FCT_MEAS_ID_EBA_BUS_DEBUG
	  #define FCT_MEAS_ID_EBA_BUS_DEBUG	(539795968)
	#endif
	#ifndef   FCT_MEAS_ID_FCT_SEN_ACC_OOI
	  #define FCT_MEAS_ID_FCT_SEN_ACC_OOI	(539072256)
	#endif
	#ifndef   FCT_MEAS_ID_HEAD_INPUT_CUSTOM
	  #define FCT_MEAS_ID_HEAD_INPUT_CUSTOM	(539166464)
	#endif
	#ifndef   FCT_MEAS_ID_HEAD_INPUT_GENERIC
	  #define FCT_MEAS_ID_HEAD_INPUT_GENERIC	(539165952)
	#endif
	#ifndef   FCT_MEAS_ID_HEAD_OUTPUT_CUSTOM
	  #define FCT_MEAS_ID_HEAD_OUTPUT_CUSTOM	(539166976)
	#endif
	#ifndef   FCT_MEAS_ID_HEAD_OUTPUT_GENERIC_LCF
	  #define FCT_MEAS_ID_HEAD_OUTPUT_GENERIC_LCF	(539167232)
	#endif
	#ifndef   FCT_MEAS_ID_LCD_DEBUG
	  #define FCT_MEAS_ID_LCD_DEBUG	(539438336)
	#endif
	#ifndef   FCT_MEAS_ID_LCK_DEBUG
	  #define FCT_MEAS_ID_LCK_DEBUG	(539436288)
	#endif
	#ifndef   FCT_MEAS_ID_LKA_BUS_DEBUG
	  #define FCT_MEAS_ID_LKA_BUS_DEBUG	(539796224)
	#endif
	#ifndef   FCT_MEAS_ID_LKS_DEBUG
	  #define FCT_MEAS_ID_LKS_DEBUG	(539432192)
	#endif
	#ifndef   FCT_MEAS_ID_LKS_LCD_OUTPUT
	  #define FCT_MEAS_ID_LKS_LCD_OUTPUT	(539430656)
	#endif
	#ifndef   FCT_MEAS_ID_LKS_LCK_INPUT
	  #define FCT_MEAS_ID_LKS_LCK_INPUT	(539431424)
	#endif
	#ifndef   FCT_MEAS_ID_LKS_LCK_OUTPUT
	  #define FCT_MEAS_ID_LKS_LCK_OUTPUT	(539429888)
	#endif
	#ifndef   FCT_MEAS_ID_PUBLIC_OBJECT_LIST
	  #define FCT_MEAS_ID_PUBLIC_OBJECT_LIST	(539033600)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_BUS_DEBUG
	  #define FCT_MEAS_ID_SEN_BUS_DEBUG	(539795712)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_CAM_OBJECT_LIST
	  #define FCT_MEAS_ID_SEN_CAM_OBJECT_LIST	(539783168)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_COMP_STATE
	  #define FCT_MEAS_ID_SEN_COMP_STATE	(539795200)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_CTRL_DATA
	  #define FCT_MEAS_ID_SEN_CTRL_DATA	(539427584)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_EGO_DYN_OBJ_SYNC
	  #define FCT_MEAS_ID_SEN_EGO_DYN_OBJ_SYNC	(539787264)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_EGO_DYN_RAW
	  #define FCT_MEAS_ID_SEN_EGO_DYN_RAW	(539787520)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_ERROR_OUT_VADDR_LCF
	  #define FCT_MEAS_ID_SEN_ERROR_OUT_VADDR_LCF	(539063552)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_FRAME_DATA
	  #define FCT_MEAS_ID_SEN_FRAME_DATA	(539426816)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_GEN_OBJECT_LIST
	  #define FCT_MEAS_ID_SEN_GEN_OBJECT_LIST	(539770880)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_HYPO_OUT
	  #define FCT_MEAS_ID_SEN_HYPO_OUT	(539791616)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_INPUT_SIGHEADERS
	  #define FCT_MEAS_ID_SEN_INPUT_SIGHEADERS	(539427840)
	#endif
	#ifndef   FCT_MEAS_ID_SEN_VEH_PARAM
	  #define FCT_MEAS_ID_SEN_VEH_PARAM	(539787776)
	#endif
	#ifndef   FCT_MEAS_ID_TRAJECTORIES
	  #define FCT_MEAS_ID_TRAJECTORIES	(539230208)
	#endif
	#ifndef   FCT_MEAS_ID_VEH_COMP_STATE
	  #define FCT_MEAS_ID_VEH_COMP_STATE	(539795456)
	#endif
	#ifndef   FCT_MEAS_ID_VEH_CTRL_DATA
	  #define FCT_MEAS_ID_VEH_CTRL_DATA	(539427616)
	#endif
	#ifndef   FCT_MEAS_ID_VEH_EGO_DYN
	  #define FCT_MEAS_ID_VEH_EGO_DYN	(539791360)
	#endif
	#ifndef   FCT_MEAS_ID_VEH_FRAME_DATA
	  #define FCT_MEAS_ID_VEH_FRAME_DATA	(539426944)
	#endif
	#ifndef   FCT_MEAS_ID_VEH_HYPOTHESIS
	  #define FCT_MEAS_ID_VEH_HYPOTHESIS	(539788288)
	#endif
	#ifndef   FCT_MEAS_ID_VEH_INPUT_SIGHEADERS
	  #define FCT_MEAS_ID_VEH_INPUT_SIGHEADERS	(539428864)
	#endif
	#ifndef   FLSP_MEAS_ID_CALL_INTR_DIST
	  #define FLSP_MEAS_ID_CALL_INTR_DIST	(2154955648)
	#endif
	#ifndef   FLSP_MEAS_ID_DYN_RESPONSE_CURVE
	  #define FLSP_MEAS_ID_DYN_RESPONSE_CURVE	(2154955360)
	#endif
	#ifndef   FLSP_MEAS_ID_IMAGER_ANALOG_TEST
	  #define FLSP_MEAS_ID_IMAGER_ANALOG_TEST	(2155022592)
	#endif
	#ifndef   FLSP_MEAS_ID_IMAGER_CHAR_RIGHT
	  #define FLSP_MEAS_ID_IMAGER_CHAR_RIGHT	(2154955520)
	#endif
	#ifndef   FLSP_MEAS_ID_PROD_DATA
	  #define FLSP_MEAS_ID_PROD_DATA	(2154955904)
	#endif
	#ifndef   FLSP_MEAS_ID_PROD_INTR_LEFT
	  #define FLSP_MEAS_ID_PROD_INTR_LEFT	(2155022160)
	#endif
	#ifndef   FLSP_MEAS_ID_PROD_INTR_RIGHT
	  #define FLSP_MEAS_ID_PROD_INTR_RIGHT	(2154955808)
	#endif
	#ifndef   FLSP_MEAS_ID_RESPONSE_CURVE
	  #define FLSP_MEAS_ID_RESPONSE_CURVE	(2154955040)
	#endif
	#ifndef   FLSP_MEAS_ID_STEREP_CAL_INTR_RIGHT
	  #define FLSP_MEAS_ID_STEREP_CAL_INTR_RIGHT	(2154954816)
	#endif
	#ifndef   FTRC_MEAS_ID_TARGET_LIST
	  #define FTRC_MEAS_ID_TARGET_LIST	(816979968)
	#endif
	#ifndef   HLA_MEAS_VADDR_PRO_PORT_ALGO_COMP_STATE
	  #define HLA_MEAS_VADDR_PRO_PORT_ALGO_COMP_STATE	(824180736)
	#endif
	#ifndef   HLA_MEAS_VADDR_PRO_PORT_HEADLIGHT_CTRL
	  #define HLA_MEAS_VADDR_PRO_PORT_HEADLIGHT_CTRL	(824181248)
	#endif
	#ifndef   HLA_MEAS_VADDR_REQ_PORT_BUS_INPUT_SIGNALS
	  #define HLA_MEAS_VADDR_REQ_PORT_BUS_INPUT_SIGNALS	(824184064)
	#endif
	#ifndef   HLA_MEAS_VADDR_REQ_PORT_CPAR
	  #define HLA_MEAS_VADDR_REQ_PORT_CPAR	(824183296)
	#endif
	#ifndef   HLA_MEAS_VADDR_REQ_PORT_RADAR_OBJECT_LIST
	  #define HLA_MEAS_VADDR_REQ_PORT_RADAR_OBJECT_LIST	(824185600)
	#endif
	#ifndef   HLA_MEAS_VADDR_SYNC_REF
	  #define HLA_MEAS_VADDR_SYNC_REF	(824184832)
	#endif
	#ifndef   HMI_MEAS_ID_INPUT_DATA
	  #define HMI_MEAS_ID_INPUT_DATA	(2197815296)
	#endif
	#ifndef   IC_MEAS_ID_IMAGE_CHARACTERISTICS_EVEN_RIGHT
	  #define IC_MEAS_ID_IMAGE_CHARACTERISTICS_EVEN_RIGHT	(537592320)
	#endif
	#ifndef   IC_MEAS_ID_IMAGE_CHARACTERISTICS_ODD_RIGHT
	  #define IC_MEAS_ID_IMAGE_CHARACTERISTICS_ODD_RIGHT	(537591808)
	#endif
	#ifndef   IC_MEAS_ID_IMAGE_STATISTIC_EVEN_RIGHT
	  #define IC_MEAS_ID_IMAGE_STATISTIC_EVEN_RIGHT	(537592576)
	#endif
	#ifndef   IC_MEAS_ID_IMAGE_STATISTIC_ODD_RIGHT
	  #define IC_MEAS_ID_IMAGE_STATISTIC_ODD_RIGHT	(537592064)
	#endif
	#ifndef   LCF_MEAS_ID_CAN2LADMCIUC
	  #define LCF_MEAS_ID_CAN2LADMCIUC	(2148270144)
	#endif
	#ifndef   LCF_MEAS_ID_DEBUG_SEN
	  #define LCF_MEAS_ID_DEBUG_SEN	(840990720)
	#endif
	#ifndef   LCF_MEAS_ID_DEBUG_VEH
	  #define LCF_MEAS_ID_DEBUG_VEH	(840040448)
	#endif
	#ifndef   LCF_MEAS_ID_INPUT
	  #define LCF_MEAS_ID_INPUT	(840959488)
	#endif
	#ifndef   LCF_MEAS_ID_IUC2SOC
	  #define LCF_MEAS_ID_IUC2SOC	(2148270080)
	#endif
	#ifndef   LCF_MEAS_ID_LADMCDEBUG
	  #define LCF_MEAS_ID_LADMCDEBUG	(2148270272)
	#endif
	#ifndef   LCF_MEAS_ID_LADMCIUC2CAN
	  #define LCF_MEAS_ID_LADMCIUC2CAN	(2148270208)
	#endif
	#ifndef   LCF_MEAS_ID_LEARNDATA
	  #define LCF_MEAS_ID_LEARNDATA	(839913472)
	#endif
	#ifndef   LCF_MEAS_ID_SEN2VEH
	  #define LCF_MEAS_ID_SEN2VEH	(840958464)
	#endif
	#ifndef   LCF_MEAS_ID_SEN_OUTPUT
	  #define LCF_MEAS_ID_SEN_OUTPUT	(840957952)
	#endif
	#ifndef   LCF_MEAS_ID_SOC2IUC
	  #define LCF_MEAS_ID_SOC2IUC	(839911424)
	#endif
	#ifndef   LCF_MEAS_ID_TUN_DMC
	  #define LCF_MEAS_ID_TUN_DMC	(840433664)
	#endif
	#ifndef   LCF_MEAS_ID_TUN_KMC
	  #define LCF_MEAS_ID_TUN_KMC	(840171520)
	#endif
	#ifndef   LCF_MEAS_ID_TUN_LDP
	  #define LCF_MEAS_ID_TUN_LDP	(840962048)
	#endif
	#ifndef   LCF_MEAS_ID_TUN_LKA
	  #define LCF_MEAS_ID_TUN_LKA	(840966144)
	#endif
	#ifndef   LCF_MEAS_ID_VEH2SEN
	  #define LCF_MEAS_ID_VEH2SEN	(839909888)
	#endif
	#ifndef   LCF_MEAS_ID_VEH_OUTPUT
	  #define LCF_MEAS_ID_VEH_OUTPUT	(839909376)
	#endif
	#ifndef   LCF_SEN_MEAS_ID_ALGO_COMP_STATE
	  #define LCF_SEN_MEAS_ID_ALGO_COMP_STATE	(840982528)
	#endif
	#ifndef   LCF_SEN_MEAS_ID_CTRL_BSW_DATA
	  #define LCF_SEN_MEAS_ID_CTRL_BSW_DATA	(840974336)
	#endif
	#ifndef   LCF_SEN_MEAS_ID_SYNC_REF
	  #define LCF_SEN_MEAS_ID_SYNC_REF	(840982784)
	#endif
	#ifndef   LCF_VEH_MEAS_ID_ALGO_COMP_STATE
	  #define LCF_VEH_MEAS_ID_ALGO_COMP_STATE	(839910400)
	#endif
	#ifndef   LCF_VEH_MEAS_ID_CTRL_BSW_DATA
	  #define LCF_VEH_MEAS_ID_CTRL_BSW_DATA	(839946240)
	#endif
	#ifndef   LCF_VEH_MEAS_ID_SYNC_REF
	  #define LCF_VEH_MEAS_ID_SYNC_REF	(839974912)
	#endif
	#ifndef   LD_MEAS_ID_ANCHOR_AREA_CONFIG
	  #define LD_MEAS_ID_ANCHOR_AREA_CONFIG	(820379648)
	#endif
	#ifndef   LD_MEAS_ID_COMP_STATE
	  #define LD_MEAS_ID_COMP_STATE	(820285440)
	#endif
	#ifndef   LD_MEAS_ID_CPAR_DATA
	  #define LD_MEAS_ID_CPAR_DATA	(820281344)
	#endif
	#ifndef   LD_MEAS_ID_CTRL_BSW_DATA
	  #define LD_MEAS_ID_CTRL_BSW_DATA	(819986432)
	#endif
	#ifndef   LD_MEAS_ID_DYNAMIC_POSE
	  #define LD_MEAS_ID_DYNAMIC_POSE	(820289536)
	#endif
	#ifndef   LD_MEAS_ID_MONO_CALIB_CROI
	  #define LD_MEAS_ID_MONO_CALIB_CROI	(820269056)
	#endif
	#ifndef   LD_MEAS_ID_MONO_CALIB_IMAGER
	  #define LD_MEAS_ID_MONO_CALIB_IMAGER	(820277248)
	#endif
	#ifndef   LD_MEAS_ID_MONO_CALIB_RROI
	  #define LD_MEAS_ID_MONO_CALIB_RROI	(820273152)
	#endif
	#ifndef   LD_MEAS_ID_ONLINE_CALI_DATA
	  #define LD_MEAS_ID_ONLINE_CALI_DATA	(820117504)
	#endif
	#ifndef   LD_MEAS_ID_OUTPUT_DATA
	  #define LD_MEAS_ID_OUTPUT_DATA	(820051968)
	#endif
	#ifndef   LD_MEAS_ID_RTE_INPUT_HEADER
	  #define LD_MEAS_ID_RTE_INPUT_HEADER	(820183040)
	#endif
	#ifndef   LD_MEAS_ID_SIM_RTA_BUFFER
	  #define LD_MEAS_ID_SIM_RTA_BUFFER	(820510720)
	#endif
	#ifndef   LD_MEAS_ID_SIM_RTA_BUFFER_EVE
	  #define LD_MEAS_ID_SIM_RTA_BUFFER_EVE	(820576256)
	#endif
	#ifndef   LEFT_IPC_MEAS_ID_PROVIDED_OUTPUTS
	  #define LEFT_IPC_MEAS_ID_PROVIDED_OUTPUTS	(872964608)
	#endif
	#ifndef   LSD_MEAS_VADDR_PRO_PORT_ALGO_COMP_STATE
	  #define LSD_MEAS_VADDR_PRO_PORT_ALGO_COMP_STATE	(842006528)
	#endif
	#ifndef   LSD_MEAS_VADDR_PRO_PORT_ENVIRONMENT_DATA
	  #define LSD_MEAS_VADDR_PRO_PORT_ENVIRONMENT_DATA	(842007040)
	#endif
	#ifndef   LSD_MEAS_VADDR_PRO_PORT_LIGHT_LIST
	  #define LSD_MEAS_VADDR_PRO_PORT_LIGHT_LIST	(842007552)
	#endif
	#ifndef   LSD_MEAS_VADDR_PRO_PORT_LIGHT_OBJECT_LIST
	  #define LSD_MEAS_VADDR_PRO_PORT_LIGHT_OBJECT_LIST	(842011648)
	#endif
	#ifndef   LSD_MEAS_VADDR_PRO_PORT_NVM
	  #define LSD_MEAS_VADDR_PRO_PORT_NVM	(842015744)
	#endif
	#ifndef   LSD_MEAS_VADDR_REQ_PORT_CPAR
	  #define LSD_MEAS_VADDR_REQ_PORT_CPAR	(842017280)
	#endif
	#ifndef   LSD_MEAS_VADDR_SYNC_REF
	  #define LSD_MEAS_VADDR_SYNC_REF	(842018816)
	#endif
	#ifndef   MAP_MEAS_ID_ALGO_STATE_DATA
	  #define MAP_MEAS_ID_ALGO_STATE_DATA	(838861312)
	#endif
	#ifndef   MAP_MEAS_ID_CTRL_DATA
	  #define MAP_MEAS_ID_CTRL_DATA	(838860800)
	#endif
	#ifndef   MAP_MEAS_ID_NVM_STATE_DATA
	  #define MAP_MEAS_ID_NVM_STATE_DATA	(838864896)
	#endif
	#ifndef   MAP_MEAS_ID_RTE_INPUT_DATA
	  #define MAP_MEAS_ID_RTE_INPUT_DATA	(838862848)
	#endif
	#ifndef   MAP_MEAS_ID_RTE_OUTPUT_DATA
	  #define MAP_MEAS_ID_RTE_OUTPUT_DATA	(838861568)
	#endif
	#ifndef   MAP_MEAS_ID_SYNC_REF_DATA
	  #define MAP_MEAS_ID_SYNC_REF_DATA	(838861056)
	#endif
	#ifndef   MEAS_ID_HIL_TIMESYNC
	  #define MEAS_ID_HIL_TIMESYNC	(2197839872)
	#endif
	#ifndef   MEAS_ID_NVM_CONFIG_ECUSW
	  #define MEAS_ID_NVM_CONFIG_ECUSW	(2197827584)
	#endif
	#ifndef   MEAS_ID_STAT_ECU_DATA_SOC
	  #define MEAS_ID_STAT_ECU_DATA_SOC	(2197835776)
	#endif
	#ifndef   MEAS_ID_SYSDATA_MCU
	  #define MEAS_ID_SYSDATA_MCU	(2197819392)
	#endif
	#ifndef   MEAS_ID_SYSDATA_SOC
	  #define MEAS_ID_SYSDATA_SOC	(2197823488)
	#endif
	#ifndef   MEAS_ID_TIMESTAMP_MCU
	  #define MEAS_ID_TIMESTAMP_MCU	(2197831680)
	#endif
	#ifndef   MEMO_MEAS_ID_CTRL_BSW_DATA
	  #define MEMO_MEAS_ID_CTRL_BSW_DATA	(816840704)
	#endif
	#ifndef   MEMO_MEAS_ID_OUTPUT
	  #define MEMO_MEAS_ID_OUTPUT	(817045504)
	#endif
	#ifndef   MEMO_MEAS_ID_STATE
	  #define MEMO_MEAS_ID_STATE	(816922624)
	#endif
	#ifndef   MEMO_MEAS_ID_SYNCVDY_VDYOFFSETS
	  #define MEMO_MEAS_ID_SYNCVDY_VDYOFFSETS	(816951296)
	#endif
	#ifndef   MEMO_MEAS_ID_SYNCVDY_VEHDYN
	  #define MEMO_MEAS_ID_SYNCVDY_VEHDYN	(816943104)
	#endif
	#ifndef   MEMO_MEAS_ID_SYNCVDY_VEHPAR
	  #define MEMO_MEAS_ID_SYNCVDY_VEHPAR	(816947200)
	#endif
	#ifndef   MEMO_MEAS_ID_SYNCVDY_VEHSIG
	  #define MEMO_MEAS_ID_SYNCVDY_VEHSIG	(816939008)
	#endif
	#ifndef   MEMO_MEAS_ID_SYNC_REF
	  #define MEMO_MEAS_ID_SYNC_REF	(816967680)
	#endif
	#ifndef   PC_MEAS_ID_BUS_DEBUG_DATA
	  #define PC_MEAS_ID_BUS_DEBUG_DATA	(808452490)
	#endif
	#ifndef   PC_MEAS_ID_CTRL_BSW_DATA
	  #define PC_MEAS_ID_CTRL_BSW_DATA	(808452096)
	#endif
	#ifndef   PC_MEAS_ID_REQUEST_PATCHES
	  #define PC_MEAS_ID_REQUEST_PATCHES	(808452618)
	#endif
	#ifndef   PC_MEAS_ID_RESULT_PATCHES
	  #define PC_MEAS_ID_RESULT_PATCHES	(808484864)
	#endif
	#ifndef   PC_MEAS_ID_STATE
	  #define PC_MEAS_ID_STATE	(808452160)
	#endif
	#ifndef   PC_MEAS_ID_SYNC_REF
	  #define PC_MEAS_ID_SYNC_REF	(808452292)
	#endif
	#ifndef   PFC_MEAS_ID_BASE_CTRLDATA
	  #define PFC_MEAS_ID_BASE_CTRLDATA	(826277920)
	#endif
	#ifndef   PFC_MEAS_ID_COMPSTATE
	  #define PFC_MEAS_ID_COMPSTATE	(826343424)
	#endif
	#ifndef   PFC_MEAS_ID_DEBUGDATA
	  #define PFC_MEAS_ID_DEBUGDATA	(826605568)
	#endif
	#ifndef   PFC_MEAS_ID_FLOWMAP
	  #define PFC_MEAS_ID_FLOWMAP	(826343680)
	#endif
	#ifndef   PFC_MEAS_ID_REQPORTS
	  #define PFC_MEAS_ID_REQPORTS	(826278144)
	#endif
	#ifndef   PFC_MEAS_ID_SIGNATUREIMAGE
	  #define PFC_MEAS_ID_SIGNATUREIMAGE	(826671104)
	#endif
	#ifndef   PFC_MEAS_ID_SYNCREF
	  #define PFC_MEAS_ID_SYNCREF	(826966016)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_ALGO_COMP_STATE
	  #define RTE_UDW_MEAS_VADDR_ALGO_COMP_STATE	(844136448)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_BSW_CTRL_DATA
	  #define RTE_UDW_MEAS_VADDR_BSW_CTRL_DATA	(844103680)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_CPAR
	  #define RTE_UDW_MEAS_VADDR_CPAR	(844104448)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_DEBUG_CUSTOM
	  #define RTE_UDW_MEAS_VADDR_DEBUG_CUSTOM	(844137216)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_DEBUG_GENERIC
	  #define RTE_UDW_MEAS_VADDR_DEBUG_GENERIC	(844136960)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_INPUT_CUSTOM
	  #define RTE_UDW_MEAS_VADDR_INPUT_CUSTOM	(844104192)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_INPUT_GENERIC
	  #define RTE_UDW_MEAS_VADDR_INPUT_GENERIC	(844103936)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_NVM_I
	  #define RTE_UDW_MEAS_VADDR_NVM_I	(844104704)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_NVM_O
	  #define RTE_UDW_MEAS_VADDR_NVM_O	(844137472)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_OUTPUT_GENERIC
	  #define RTE_UDW_MEAS_VADDR_OUTPUT_GENERIC	(844136704)
	#endif
	#ifndef   RTE_UDW_MEAS_VADDR_SYNC_REF
	  #define RTE_UDW_MEAS_VADDR_SYNC_REF	(844104960)
	#endif
	#ifndef   RUM_MEAS_ID_ALGO_COMP_STATE
	  #define RUM_MEAS_ID_ALGO_COMP_STATE	(843093760)
	#endif
	#ifndef   RUM_MEAS_ID_ANCHOR_AREA_CONFIG_SCAN
	  #define RUM_MEAS_ID_ANCHOR_AREA_CONFIG_SCAN	(843063296)
	#endif
	#ifndef   RUM_MEAS_ID_ANCHOR_AREA_CONFIG_TRACK
	  #define RUM_MEAS_ID_ANCHOR_AREA_CONFIG_TRACK	(843448320)
	#endif
	#ifndef   RUM_MEAS_ID_BOOSTER_DEBUG
	  #define RUM_MEAS_ID_BOOSTER_DEBUG	(843382784)
	#endif
	#ifndef   RUM_MEAS_ID_CLUSTERED_PEDESTRIANS
	  #define RUM_MEAS_ID_CLUSTERED_PEDESTRIANS	(843071744)
	#endif
	#ifndef   RUM_MEAS_ID_CLUSTERING_DEBUG
	  #define RUM_MEAS_ID_CLUSTERING_DEBUG	(843087872)
	#endif
	#ifndef   RUM_MEAS_ID_CLUSTERS
	  #define RUM_MEAS_ID_CLUSTERS	(843317248)
	#endif
	#ifndef   RUM_MEAS_ID_CTRL_BSW_DATA
	  #define RUM_MEAS_ID_CTRL_BSW_DATA	(843055104)
	#endif
	#ifndef   RUM_MEAS_ID_ERRORS
	  #define RUM_MEAS_ID_ERRORS	(843087904)
	#endif
	#ifndef   RUM_MEAS_ID_HYPGEN_DEBUG
	  #define RUM_MEAS_ID_HYPGEN_DEBUG	(843075840)
	#endif
	#ifndef   RUM_MEAS_ID_IMG_PROC_RESPONSES
	  #define RUM_MEAS_ID_IMG_PROC_RESPONSES	(843513856)
	#endif
	#ifndef   RUM_MEAS_ID_MAIN_DEBUG
	  #define RUM_MEAS_ID_MAIN_DEBUG	(843071488)
	#endif
	#ifndef   RUM_MEAS_ID_PARAMETERS
	  #define RUM_MEAS_ID_PARAMETERS	(843089664)
	#endif
	#ifndef   RUM_MEAS_ID_PED_CLUSTERING_DEBUG
	  #define RUM_MEAS_ID_PED_CLUSTERING_DEBUG	(843186176)
	#endif
	#ifndef   RUM_MEAS_ID_PED_IMGTRACKED_PEDESTRIANS
	  #define RUM_MEAS_ID_PED_IMGTRACKED_PEDESTRIANS	(843072512)
	#endif
	#ifndef   RUM_MEAS_ID_REQ_PORT_HEADERS
	  #define RUM_MEAS_ID_REQ_PORT_HEADERS	(843093248)
	#endif
	#ifndef   RUM_MEAS_ID_TEMPLATE_TRACK_DEBUG
	  #define RUM_MEAS_ID_TEMPLATE_TRACK_DEBUG	(843120640)
	#endif
	#ifndef   RUM_MEAS_ID_TEMPLATE_TRACK_REQUESTS
	  #define RUM_MEAS_ID_TEMPLATE_TRACK_REQUESTS	(843251712)
	#endif
	#ifndef   RUM_MEAS_ID_TEMPLATE_TRACK_RESPONSES
	  #define RUM_MEAS_ID_TEMPLATE_TRACK_RESPONSES	(843094016)
	#endif
	#ifndef   RUM_MEAS_ID_VCL_MEAS_LIST
	  #define RUM_MEAS_ID_VCL_MEAS_LIST	(843056128)
	#endif
	#ifndef   SCB_IPC_MEAS_ID_PROVIDED_OUTPUTS
	  #define SCB_IPC_MEAS_ID_PROVIDED_OUTPUTS	(872964352)
	#endif
	#ifndef   SCB_MEAS_ID_ALGO_COMP_STATE
	  #define SCB_MEAS_ID_ALGO_COMP_STATE	(872964096)
	#endif
	#ifndef   SCB_MEAS_ID_BUS_DEBUG_DATA
	  #define SCB_MEAS_ID_BUS_DEBUG_DATA	(872968448)
	#endif
	#ifndef   SCB_MEAS_ID_COMMON_ALGO_DATA
	  #define SCB_MEAS_ID_COMMON_ALGO_DATA	(872952064)
	#endif
	#ifndef   SCB_MEAS_ID_CTRL_BSW_DATA
	  #define SCB_MEAS_ID_CTRL_BSW_DATA	(872960000)
	#endif
	#ifndef   SCB_MEAS_ID_HEATING_REQUEST
	  #define SCB_MEAS_ID_HEATING_REQUEST	(872968192)
	#endif
	#ifndef   SCB_MEAS_ID_INTEGRATION_DATA
	  #define SCB_MEAS_ID_INTEGRATION_DATA	(872947712)
	#endif
	#ifndef   SCB_MEAS_ID_KERNEL_INPUT
	  #define SCB_MEAS_ID_KERNEL_INPUT	(872939520)
	#endif
	#ifndef   SCB_MEAS_ID_MONO_PROVIDED_OUTPUTS
	  #define SCB_MEAS_ID_MONO_PROVIDED_OUTPUTS	(872972288)
	#endif
	#ifndef   SCB_MEAS_ID_PROVIDED_OUTPUTS
	  #define SCB_MEAS_ID_PROVIDED_OUTPUTS	(872992768)
	#endif
	#ifndef   SCB_MEAS_ID_SIGNALS_HEADERS
	  #define SCB_MEAS_ID_SIGNALS_HEADERS	(872960256)
	#endif
	#ifndef   SCB_MEAS_ID_SPECIFIC_ALGO_DATA
	  #define SCB_MEAS_ID_SPECIFIC_ALGO_DATA	(872955904)
	#endif
	#ifndef   SCB_MEAS_ID_WRP_ERROR_DATA
	  #define SCB_MEAS_ID_WRP_ERROR_DATA	(872960768)
	#endif
	#ifndef   SEMO_MEAS_ID_CTRL_BSW_DATA
	  #define SEMO_MEAS_ID_CTRL_BSW_DATA	(816840960)
	#endif
	#ifndef   SEMO_MEAS_ID_OUTPUT
	  #define SEMO_MEAS_ID_OUTPUT	(816906240)
	#endif
	#ifndef   SEMO_MEAS_ID_STATE
	  #define SEMO_MEAS_ID_STATE	(816926720)
	#endif
	#ifndef   SEMO_MEAS_ID_SYNC_REF
	  #define SEMO_MEAS_ID_SYNC_REF	(816971776)
	#endif
	#ifndef   SI_CUTINOBJ_DATA_MEAS_VADDR
	  #define SI_CUTINOBJ_DATA_MEAS_VADDR	(539362560)
	#endif
	#ifndef   SI_OOI_LIST_MEAS_VADDR
	  #define SI_OOI_LIST_MEAS_VADDR	(539361536)
	#endif
	#ifndef   SI_RANGE_FACTOR_MEAS_VADDR
	  #define SI_RANGE_FACTOR_MEAS_VADDR	(539362304)
	#endif
	#ifndef   SR_MEAS_ID_MEAS_OUTPUT_A
	  #define SR_MEAS_ID_MEAS_OUTPUT_A	(118489088)
	#endif
	#ifndef   SR_MEAS_ID_MEAS_OUTPUT_B
	  #define SR_MEAS_ID_MEAS_OUTPUT_B	(118509568)
	#endif
	#ifndef   SR_RTE_MEAS_ID_ALGO_COMP_A
	  #define SR_RTE_MEAS_ID_ALGO_COMP_A	(818941952)
	#endif
	#ifndef   SR_RTE_MEAS_ID_ALGO_COMP_B
	  #define SR_RTE_MEAS_ID_ALGO_COMP_B	(819224576)
	#endif
	#ifndef   SR_RTE_MEAS_ID_BASE_CTRL_DATA_A
	  #define SR_RTE_MEAS_ID_BASE_CTRL_DATA_A	(818937856)
	#endif
	#ifndef   SR_RTE_MEAS_ID_BASE_CTRL_DATA_B
	  #define SR_RTE_MEAS_ID_BASE_CTRL_DATA_B	(819200000)
	#endif
	#ifndef   SR_RTE_MEAS_ID_CODING_PARAMS
	  #define SR_RTE_MEAS_ID_CODING_PARAMS	(819462144)
	#endif
	#ifndef   SR_RTE_MEAS_ID_OUTPUT
	  #define SR_RTE_MEAS_ID_OUTPUT	(819204096)
	#endif
	#ifndef   SR_RTE_MEAS_SYNCREF_A
	  #define SR_RTE_MEAS_SYNCREF_A	(818942208)
	#endif
	#ifndef   SR_RTE_MEAS_SYNCREF_B
	  #define SR_RTE_MEAS_SYNCREF_B	(819224832)
	#endif
	#ifndef   SR_RTE_MEAS_WRP_STATE_A
	  #define SR_RTE_MEAS_WRP_STATE_A	(818942720)
	#endif
	#ifndef   SR_RTE_MEAS_WRP_STATE_B
	  #define SR_RTE_MEAS_WRP_STATE_B	(819225088)
	#endif
	#ifndef   TLR_MEAS_ID_ALGO_COMP_STATE
	  #define TLR_MEAS_ID_ALGO_COMP_STATE	(828854272)
	#endif
	#ifndef   TLR_MEAS_ID_ALGO_DATA
	  #define TLR_MEAS_ID_ALGO_DATA	(828440576)
	#endif
	#ifndef   TLR_MEAS_ID_BUS_DEBUG_DATA
	  #define TLR_MEAS_ID_BUS_DEBUG_DATA	(828858368)
	#endif
	#ifndef   TLR_MEAS_ID_CLASSIF_RESULTS_LIST
	  #define TLR_MEAS_ID_CLASSIF_RESULTS_LIST	(828571648)
	#endif
	#ifndef   TLR_MEAS_ID_CTRL_BSW_DATA
	  #define TLR_MEAS_ID_CTRL_BSW_DATA	(828833792)
	#endif
	#ifndef   TLR_MEAS_ID_ERROR_DATA
	  #define TLR_MEAS_ID_ERROR_DATA	(828841984)
	#endif
	#ifndef   TLR_MEAS_ID_INTEGRATION_DATA
	  #define TLR_MEAS_ID_INTEGRATION_DATA	(828702720)
	#endif
	#ifndef   TLR_MEAS_ID_KERNEL_INPUT
	  #define TLR_MEAS_ID_KERNEL_INPUT	(828379136)
	#endif
	#ifndef   TLR_MEAS_ID_PROVIDED_OUTPUTS
	  #define TLR_MEAS_ID_PROVIDED_OUTPUTS	(828862464)
	#endif
	#ifndef   TLR_MEAS_ID_SEG_RESULTS_LIST
	  #define TLR_MEAS_ID_SEG_RESULTS_LIST	(828506112)
	#endif
	#ifndef   TLR_MEAS_ID_SIGNALS_HEADERS
	  #define TLR_MEAS_ID_SIGNALS_HEADERS	(828837888)
	#endif
	#ifndef   TLR_MEAS_ID_TLR_CPAR
	  #define TLR_MEAS_ID_TLR_CPAR	(828375040)
	#endif
	#ifndef   TLR_MEAS_ID_TRACKING_RESULTS_LIST
	  #define TLR_MEAS_ID_TRACKING_RESULTS_LIST	(828637184)
	#endif
	#ifndef   TSA_MEAS_ID_INT_OUTPUT_DEBUG
	  #define TSA_MEAS_ID_INT_OUTPUT_DEBUG	(537133056)
	#endif
	#ifndef   TSA_MEAS_ID_INT_STATE
	  #define TSA_MEAS_ID_INT_STATE	(537141248)
	#endif
	#ifndef   TSA_MEAS_ID_START
	  #define TSA_MEAS_ID_START	(537133056)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_ALGO_COMP_STATE
	  #define TSA_RTE_MEAS_ID_ALGO_COMP_STATE	(829472768)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_BUS_DEBUG_DATA
	  #define TSA_RTE_MEAS_ID_BUS_DEBUG_DATA	(829497344)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_CODING_PARAMS
	  #define TSA_RTE_MEAS_ID_CODING_PARAMS	(829473280)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_CTRL_BSW_DATA
	  #define TSA_RTE_MEAS_ID_CTRL_BSW_DATA	(829423616)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_CUSTOM_INPUT
	  #define TSA_RTE_MEAS_ID_CUSTOM_INPUT	(829424128)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_ERROR_TABLE
	  #define TSA_RTE_MEAS_ID_ERROR_TABLE	(829497600)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_INPUT_GPS
	  #define TSA_RTE_MEAS_ID_INPUT_GPS	(829423872)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_INPUT_NAVIGATION
	  #define TSA_RTE_MEAS_ID_INPUT_NAVIGATION	(829427712)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_NVM_STATE
	  #define TSA_RTE_MEAS_ID_NVM_STATE	(829473024)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_OUTPUT_CUSTOM
	  #define TSA_RTE_MEAS_ID_OUTPUT_CUSTOM	(829489152)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_OUTPUT_RESULTS
	  #define TSA_RTE_MEAS_ID_OUTPUT_RESULTS	(829476864)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_OUTPUT_SIGN
	  #define TSA_RTE_MEAS_ID_OUTPUT_SIGN	(829480960)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_SYNC_REF
	  #define TSA_RTE_MEAS_ID_SYNC_REF	(829473536)
	#endif
	#ifndef   VDY_MEAS_ID_ALN_EST_YAW_RATE
	  #define VDY_MEAS_ID_ALN_EST_YAW_RATE	(540018944)
	#endif
	#ifndef   VDY_MEAS_ID_ALN_YAW_RATE
	  #define VDY_MEAS_ID_ALN_YAW_RATE	(540345600)
	#endif
	#ifndef   VDY_MEAS_ID_CTRLDATA
	  #define VDY_MEAS_ID_CTRLDATA	(540016640)
	#endif
	#ifndef   VDY_MEAS_ID_ERRORS
	  #define VDY_MEAS_ID_ERRORS	(540345088)
	#endif
	#ifndef   VDY_MEAS_ID_EST_CURVES
	  #define VDY_MEAS_ID_EST_CURVES	(540346112)
	#endif
	#ifndef   VDY_MEAS_ID_LONGLONG_TIMESTAMP
	  #define VDY_MEAS_ID_LONGLONG_TIMESTAMP	(540345680)
	#endif
	#ifndef   VDY_MEAS_ID_NVM_READ
	  #define VDY_MEAS_ID_NVM_READ	(540017664)
	#endif
	#ifndef   VDY_MEAS_ID_NVM_WRITE
	  #define VDY_MEAS_ID_NVM_WRITE	(540345344)
	#endif
	#ifndef   VDY_MEAS_ID_OFFSETS
	  #define VDY_MEAS_ID_OFFSETS	(540344832)
	#endif
	#ifndef   VDY_MEAS_ID_SYNC_REF
	  #define VDY_MEAS_ID_SYNC_REF	(540346192)
	#endif
	#ifndef   VDY_MEAS_ID_VEH_DYN
	  #define VDY_MEAS_ID_VEH_DYN	(540344320)
	#endif
	#ifndef   VDY_MEAS_ID_VEH_PAR
	  #define VDY_MEAS_ID_VEH_PAR	(540017408)
	#endif
	#ifndef   VDY_MEAS_ID_VEH_SIG
	  #define VDY_MEAS_ID_VEH_SIG	(540016720)
	#endif
	#ifndef   VDY_MEAS_ID_VEL_STAT_OBJ
	  #define VDY_MEAS_ID_VEL_STAT_OBJ	(540018688)
	#endif
	#ifndef   VDY_MEAS_ID_YWRT_TEMP_TABPE
	  #define VDY_MEAS_ID_YWRT_TEMP_TABPE	(540017920)
	#endif
	#ifndef   VODCA_MEAS_ID_ALGO_COMP_STATE
	  #define VODCA_MEAS_ID_ALGO_COMP_STATE	(825491456)
	#endif
	#ifndef   VODCA_MEAS_ID_CTRL_BSW_DATA
	  #define VODCA_MEAS_ID_CTRL_BSW_DATA	(825229312)
	#endif
	#ifndef   VODCA_MEAS_ID_DEBUG
	  #define VODCA_MEAS_ID_DEBUG	(825425920)
	#endif
	#ifndef   VODCA_MEAS_ID_DETECTION_RESULTS
	  #define VODCA_MEAS_ID_DETECTION_RESULTS	(825556992)
	#endif
	#ifndef   VODCA_MEAS_ID_DETECTOR_PARAMS
	  #define VODCA_MEAS_ID_DETECTOR_PARAMS	(825753600)
	#endif
	#ifndef   VODCA_MEAS_ID_ERRORS
	  #define VODCA_MEAS_ID_ERRORS	(825294848)
	#endif
	#ifndef   VODCA_MEAS_ID_REQ_PORT_HEADERS
	  #define VODCA_MEAS_ID_REQ_PORT_HEADERS	(825233408)
	#endif

/* typedef SymbolicConstants */
	#ifndef   ABD_MAX_NUM_BOUNDARY
	  #define ABD_MAX_NUM_BOUNDARY	(10)
	#endif
	#ifndef   ABD_MAX_NUM_EGOLANE_MARKER
	  #define ABD_MAX_NUM_EGOLANE_MARKER	(3)
	#endif
	#ifndef   ABD_NUM_BOUNDARY_POINTS
	  #define ABD_NUM_BOUNDARY_POINTS	(100)
	#endif
	#ifndef   ACAL_RTE_LAST_ERROR_SIZE
	  #define ACAL_RTE_LAST_ERROR_SIZE	(10)
	#endif
	#ifndef   ALGO_FUSI_DEBOUNCE_CYCLES
	  #define ALGO_FUSI_DEBOUNCE_CYCLES	(3)
	#endif
	#ifndef   ALGO_FUSI_DEBOUNCE_TIME
	  #define ALGO_FUSI_DEBOUNCE_TIME	(185000)
	#endif
	#ifndef   ALGO_VERSION_INFO_LENGTH
	  #define ALGO_VERSION_INFO_LENGTH	(50)
	#endif
	#ifndef   CB_ui8_MAX_MPC_FUNCTION
	  #define CB_ui8_MAX_MPC_FUNCTION	(6)
	#endif
	#ifndef   CB_ui8_NB_AOI
	  #define CB_ui8_NB_AOI	(25)
	#endif
	#ifndef   CB_ui8_NB_RAD_SEG
	  #define CB_ui8_NB_RAD_SEG	(8)
	#endif
	#ifndef   CB_ui8_NB_RAD_TILES
	  #define CB_ui8_NB_RAD_TILES	(5)
	#endif
	#ifndef   CDR_DATA_ARRAY_SIZE
	  #define CDR_DATA_ARRAY_SIZE	(256)
	#endif
	#ifndef   CDR_MAX_NUM_OF_RECORDING_AREAS
	  #define CDR_MAX_NUM_OF_RECORDING_AREAS	(7)
	#endif
	#ifndef   CDR_MAX_NUM_OF_TRIGGER_GROUPS
	  #define CDR_MAX_NUM_OF_TRIGGER_GROUPS	(7)
	#endif
	#ifndef   CDR_MAX_NUM_OF_TRIGGER_PER_TRIGGER_GROUP
	  #define CDR_MAX_NUM_OF_TRIGGER_PER_TRIGGER_GROUP	(6)
	#endif
	#ifndef   CDR_MAX_TOTAL_NUM_OF_TRIGGER
	  #define CDR_MAX_TOTAL_NUM_OF_TRIGGER	(42)
	#endif
	#ifndef   CDR_PAYLOAD_SIZE
	  #define CDR_PAYLOAD_SIZE	(15)
	#endif
	#ifndef   CDR_TIMESTAMP_LEN
	  #define CDR_TIMESTAMP_LEN	(8)
	#endif
	#ifndef   CDR_TRIGGER_NUMBER
	  #define CDR_TRIGGER_NUMBER	(15)
	#endif
	#ifndef   CFG_FCT_CD_CMS
	  #define CFG_FCT_CD_CMS	(0)
	#endif
	#ifndef   CFG_FCT_VEH_EBA_INTF
	  #define CFG_FCT_VEH_EBA_INTF	(1)
	#endif
	#ifndef   CIPP_NUMB_OF_HIST_COLS
	  #define CIPP_NUMB_OF_HIST_COLS	(256)
	#endif
	#ifndef   DB_TRANS_TYPE_VERSION
	  #define DB_TRANS_TYPE_VERSION	(121)
	#endif
	#ifndef   ECM_RTE_MAX_PATTERN_DIMENSION
	  #define ECM_RTE_MAX_PATTERN_DIMENSION	(32)
	#endif
	#ifndef   ECM_RTE_MAX_POINT_LIST_ELEMENTS
	  #define ECM_RTE_MAX_POINT_LIST_ELEMENTS	(40)
	#endif
	#ifndef   EMO_SENSOR_MISALIGNMENT_PITCH
	  #define EMO_SENSOR_MISALIGNMENT_PITCH	(2)
	#endif
	#ifndef   EMO_SENSOR_MISALIGNMENT_ROLL
	  #define EMO_SENSOR_MISALIGNMENT_ROLL	(1)
	#endif
	#ifndef   EMO_SENSOR_MISALIGNMENT_YAW
	  #define EMO_SENSOR_MISALIGNMENT_YAW	(4)
	#endif
	#ifndef   EMT0_N_MCAM_OBJECTS
	  #define EMT0_N_MCAM_OBJECTS	(12)
	#endif
	#ifndef   EM_EAB_NUM_FEATURES
	  #define EM_EAB_NUM_FEATURES	(200)
	#endif
	#ifndef   EM_GEN_OBJECT_SM_ID_NONE
	  #define EM_GEN_OBJECT_SM_ID_NONE	(255)
	#endif
	#ifndef   EM_GEN_OBJECT_SM_ID_UNKNOWN
	  #define EM_GEN_OBJECT_SM_ID_UNKNOWN	(254)
	#endif
	#ifndef   EM_GEN_OBJ_N_SHAPE_POINTS
	  #define EM_GEN_OBJ_N_SHAPE_POINTS	(4)
	#endif
	#ifndef   EM_GSS_DYN_MAP_HEIGHT
	  #define EM_GSS_DYN_MAP_HEIGHT	(80)
	#endif
	#ifndef   EM_GSS_DYN_MAP_MAX_LABEL
	  #define EM_GSS_DYN_MAP_MAX_LABEL	(3)
	#endif
	#ifndef   EM_GSS_DYN_MAP_SIZE
	  #define EM_GSS_DYN_MAP_SIZE	(10240)
	#endif
	#ifndef   EM_GSS_DYN_MAP_WIDTH
	  #define EM_GSS_DYN_MAP_WIDTH	(128)
	#endif
	#ifndef   EM_GSS_NUM_SEGMENTS
	  #define EM_GSS_NUM_SEGMENTS	(64)
	#endif
	#ifndef   EM_GSS_SEG_MAP_HEIGHT
	  #define EM_GSS_SEG_MAP_HEIGHT	(80)
	#endif
	#ifndef   EM_GSS_SEG_MAP_SIZE
	  #define EM_GSS_SEG_MAP_SIZE	(10240)
	#endif
	#ifndef   EM_GSS_SEG_MAP_WIDTH
	  #define EM_GSS_SEG_MAP_WIDTH	(128)
	#endif
	#ifndef   EM_N_LANDMARKS
	  #define EM_N_LANDMARKS	(10)
	#endif
	#ifndef   EM_N_OBJECTS_LCF
	  #define EM_N_OBJECTS_LCF	(20)
	#endif
	#ifndef   EM_VCL_DISTMEAS_LIST_SIZE
	  #define EM_VCL_DISTMEAS_LIST_SIZE	(40)
	#endif
	#ifndef   FAMO_MAX_MONITORED_COMPONENTS
	  #define FAMO_MAX_MONITORED_COMPONENTS	(20)
	#endif
	#ifndef   FCT_CAM_LANE_NUM_LANES
	  #define FCT_CAM_LANE_NUM_LANES	(4)
	#endif
	#ifndef   FCT_CFG_ASSESSED_OBJ_OUT_INTF
	  #define FCT_CFG_ASSESSED_OBJ_OUT_INTF	(1)
	#endif
	#ifndef   FCT_CFG_LONG_CTRL_SLA_SUPPORT_LCF
	  #define FCT_CFG_LONG_CTRL_SLA_SUPPORT_LCF	(0)
	#endif
	#ifndef   FCT_CFG_SEN2VEH_ACC_OOI_PORT
	  #define FCT_CFG_SEN2VEH_ACC_OOI_PORT	(1)
	#endif
	#ifndef   FCT_CFG_VEH_CUSTOM_INPUT
	  #define FCT_CFG_VEH_CUSTOM_INPUT	(0)
	#endif
	#ifndef   FCT_LCD_NO_SUPPORT_POINTS
	  #define FCT_LCD_NO_SUPPORT_POINTS	(8)
	#endif
	#ifndef   FCT_LCK_NO_SUPPORT_POINTS
	  #define FCT_LCK_NO_SUPPORT_POINTS	(8)
	#endif
	#ifndef   FLSP_DATE_OF_PROD_LENGTH
	  #define FLSP_DATE_OF_PROD_LENGTH	(3)
	#endif
	#ifndef   FLSP_NUM_TEMPERATURES2COMPENSATE
	  #define FLSP_NUM_TEMPERATURES2COMPENSATE	(16)
	#endif
	#ifndef   FLSP_RESPONSE_CURVE_LENGTH
	  #define FLSP_RESPONSE_CURVE_LENGTH	(12)
	#endif
	#ifndef   FLSP_SERIAL_NUMBER_LENGTH
	  #define FLSP_SERIAL_NUMBER_LENGTH	(26)
	#endif
	#ifndef   FLSP_TRACE_NUM_LENGTH
	  #define FLSP_TRACE_NUM_LENGTH	(14)
	#endif
	#ifndef   FTRC_EMO_MAX_SEED_ROIS
	  #define FTRC_EMO_MAX_SEED_ROIS	(10)
	#endif
	#ifndef   FTRC_EMO_SEED_BASE_ID
	  #define FTRC_EMO_SEED_BASE_ID	(0)
	#endif
	#ifndef   FTRC_FEATURE_REQUEST_GRID_HEIGHT
	  #define FTRC_FEATURE_REQUEST_GRID_HEIGHT	(10)
	#endif
	#ifndef   FTRC_FEATURE_REQUEST_GRID_SIZE
	  #define FTRC_FEATURE_REQUEST_GRID_SIZE	(160)
	#endif
	#ifndef   FTRC_FEATURE_REQUEST_GRID_WIDTH
	  #define FTRC_FEATURE_REQUEST_GRID_WIDTH	(16)
	#endif
	#ifndef   FTRC_FEAT_LIST_INCOUNT_BITMASK_MEASFLOW
	  #define FTRC_FEAT_LIST_INCOUNT_BITMASK_MEASFLOW	(128)
	#endif
	#ifndef   FTRC_FEAT_LIST_INCOUNT_BITMASK_REFINEMENT_FAIL
	  #define FTRC_FEAT_LIST_INCOUNT_BITMASK_REFINEMENT_FAIL	(32)
	#endif
	#ifndef   FTRC_FEAT_LIST_INCOUNT_BITMASK_REFINEMENT_SUCCESS
	  #define FTRC_FEAT_LIST_INCOUNT_BITMASK_REFINEMENT_SUCCESS	(64)
	#endif
	#ifndef   FTRC_MAX_FEATURES
	  #define FTRC_MAX_FEATURES	(1000)
	#endif
	#ifndef   FTRC_MAX_SEED_ROIS
	  #define FTRC_MAX_SEED_ROIS	(40)
	#endif
	#ifndef   FTRC_OD_MAX_SEED_ROIS
	  #define FTRC_OD_MAX_SEED_ROIS	(40)
	#endif
	#ifndef   FTRC_OD_SEED_BASE_ID
	  #define FTRC_OD_SEED_BASE_ID	(10)
	#endif
	#ifndef   FTRC_PRESENCE_ARRAY_HEIGHT
	  #define FTRC_PRESENCE_ARRAY_HEIGHT	(10)
	#endif
	#ifndef   FTRC_PRESENCE_ARRAY_NBINDEX
	  #define FTRC_PRESENCE_ARRAY_NBINDEX	(15)
	#endif
	#ifndef   FTRC_PRESENCE_ARRAY_SIZE
	  #define FTRC_PRESENCE_ARRAY_SIZE	(2400)
	#endif
	#ifndef   FTRC_PRESENCE_ARRAY_WIDTH
	  #define FTRC_PRESENCE_ARRAY_WIDTH	(16)
	#endif
	#ifndef   HLA_NUM_RADAR_OBJECTS
	  #define HLA_NUM_RADAR_OBJECTS	(2)
	#endif
	#ifndef   IC_RESPONSE_CURVE_LENGTH
	  #define IC_RESPONSE_CURVE_LENGTH	(5)
	#endif
	#ifndef   IOB_IMAGE_DATA_NUM_PIXELS_MAX
	  #define IOB_IMAGE_DATA_NUM_PIXELS_MAX	(630)
	#endif
	#ifndef   LCF_AVAIL_ALCA_LEFT
	  #define LCF_AVAIL_ALCA_LEFT	(10)
	#endif
	#ifndef   LCF_AVAIL_ALCA_RIGHT
	  #define LCF_AVAIL_ALCA_RIGHT	(11)
	#endif
	#ifndef   LCF_AVAIL_LDPOC_LEFT
	  #define LCF_AVAIL_LDPOC_LEFT	(7)
	#endif
	#ifndef   LCF_AVAIL_LDPOC_RIGHT
	  #define LCF_AVAIL_LDPOC_RIGHT	(8)
	#endif
	#ifndef   LCF_AVAIL_LDP_LEFT
	  #define LCF_AVAIL_LDP_LEFT	(3)
	#endif
	#ifndef   LCF_AVAIL_LDP_RIGHT
	  #define LCF_AVAIL_LDP_RIGHT	(4)
	#endif
	#ifndef   LCF_AVAIL_LDW_LEFT
	  #define LCF_AVAIL_LDW_LEFT	(1)
	#endif
	#ifndef   LCF_AVAIL_LDW_RIGHT
	  #define LCF_AVAIL_LDW_RIGHT	(2)
	#endif
	#ifndef   LCF_AVAIL_LKA
	  #define LCF_AVAIL_LKA	(0)
	#endif
	#ifndef   LCF_AVAIL_RDP_LEFT
	  #define LCF_AVAIL_RDP_LEFT	(5)
	#endif
	#ifndef   LCF_AVAIL_RDP_RIGHT
	  #define LCF_AVAIL_RDP_RIGHT	(6)
	#endif
	#ifndef   LCF_AVAIL_TJA
	  #define LCF_AVAIL_TJA	(9)
	#endif
	#ifndef   LD_CONSTANT_TWO
	  #define LD_CONSTANT_TWO	(2)
	#endif
	#ifndef   LD_EL_MAX_CONNECTIONS
	  #define LD_EL_MAX_CONNECTIONS	(8)
	#endif
	#ifndef   LD_EL_MAX_NUM_GROUPS_PER_MARKER
	  #define LD_EL_MAX_NUM_GROUPS_PER_MARKER	(32)
	#endif
	#ifndef   LD_EL_MAX_NUM_TANGENTS_PER_MARKER
	  #define LD_EL_MAX_NUM_TANGENTS_PER_MARKER	(16)
	#endif
	#ifndef   LD_EL_MAX_RAW_FEATURES_PER_GROUP
	  #define LD_EL_MAX_RAW_FEATURES_PER_GROUP	(24)
	#endif
	#ifndef   LD_INTERFACE_CPAR_LEN_CONFIG_DATA
	  #define LD_INTERFACE_CPAR_LEN_CONFIG_DATA	(8)
	#endif
	#ifndef   LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE
	  #define LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE	(3)
	#endif
	#ifndef   LD_MAX_FEATURE_POSITIONS
	  #define LD_MAX_FEATURE_POSITIONS	(16)
	#endif
	#ifndef   LD_MAX_NUM_BOUNDARY
	  #define LD_MAX_NUM_BOUNDARY	(10)
	#endif
	#ifndef   LD_MAX_NUM_EDGEGROUPS
	  #define LD_MAX_NUM_EDGEGROUPS	(288)
	#endif
	#ifndef   LD_MAX_NUM_GRADIENT_FEATURES
	  #define LD_MAX_NUM_GRADIENT_FEATURES	(49152)
	#endif
	#ifndef   LD_MAX_NUM_MARKER_FEATURES
	  #define LD_MAX_NUM_MARKER_FEATURES	(72)
	#endif
	#ifndef   LD_MAX_NUM_SATURATION_ROAD_EDGE_FEATURES
	  #define LD_MAX_NUM_SATURATION_ROAD_EDGE_FEATURES	(80)
	#endif
	#ifndef   LD_MAX_TEXTURE_MAP_SIZE
	  #define LD_MAX_TEXTURE_MAP_SIZE	(5120)
	#endif
	#ifndef   LD_NUM_MODEL_RESIDUUM_SAMPLE_POINTS
	  #define LD_NUM_MODEL_RESIDUUM_SAMPLE_POINTS	(10)
	#endif
	#ifndef   LSD_LIGHT_LIST_LENGTH
	  #define LSD_LIGHT_LIST_LENGTH	(80)
	#endif
	#ifndef   LSD_LIGHT_OBJECT_LIST_LENGTH
	  #define LSD_LIGHT_OBJECT_LIST_LENGTH	(35)
	#endif
	#ifndef   LSD_NVM_DEFECT_PIXEL_LIST_LENGTH
	  #define LSD_NVM_DEFECT_PIXEL_LIST_LENGTH	(90)
	#endif
	#ifndef   MAP_RTE_DEBUG_ABSTRACT_MAX_LEN
	  #define MAP_RTE_DEBUG_ABSTRACT_MAX_LEN	(8192)
	#endif
	#ifndef   MAP_RTE_ERROR_NUM_OPT_DATA_BYTES
	  #define MAP_RTE_ERROR_NUM_OPT_DATA_BYTES	(10)
	#endif
	#ifndef   MAP_RTE_INPUT_AV2_MSG_STACK_LEN
	  #define MAP_RTE_INPUT_AV2_MSG_STACK_LEN	(10)
	#endif
	#ifndef   MAP_RTE_MAX_NUM_ERRORS
	  #define MAP_RTE_MAX_NUM_ERRORS	(32)
	#endif
	#ifndef   MAP_RTE_MAX_NUM_FUTURE_SPEED_LIMITS
	  #define MAP_RTE_MAX_NUM_FUTURE_SPEED_LIMITS	(8)
	#endif
	#ifndef   MAP_RTE_MAX_NUM_PARALLEL_SPEED_LIMITS
	  #define MAP_RTE_MAX_NUM_PARALLEL_SPEED_LIMITS	(3)
	#endif
	#ifndef   MAP_RTE_NUM_ERROR_LIST_ENTRIES
	  #define MAP_RTE_NUM_ERROR_LIST_ENTRIES	(9)
	#endif
	#ifndef   MAP_RTE_NVM_PATH_ARRAY_SIZE
	  #define MAP_RTE_NVM_PATH_ARRAY_SIZE	(10)
	#endif
	#ifndef   MAP_RTE_NVM_SEGMENT_ARRAY_SIZE
	  #define MAP_RTE_NVM_SEGMENT_ARRAY_SIZE	(10)
	#endif
	#ifndef   MAP_RTE_OUTPUT_PATH_ARRAY_SIZE
	  #define MAP_RTE_OUTPUT_PATH_ARRAY_SIZE	(10)
	#endif
	#ifndef   MAP_RTE_OUTPUT_SEGMENT_ARRAY_SIZE
	  #define MAP_RTE_OUTPUT_SEGMENT_ARRAY_SIZE	(20)
	#endif
	#ifndef   MAP_RTE_PERS_STATE_FP_MAX_LEN
	  #define MAP_RTE_PERS_STATE_FP_MAX_LEN	(128)
	#endif
	#ifndef   MAP_RTE_PERS_STATE_FV_MAX_LEN
	  #define MAP_RTE_PERS_STATE_FV_MAX_LEN	(96)
	#endif
	#ifndef   MAP_RTE_PROFILE_NPSL_SHIFT
	  #define MAP_RTE_PROFILE_NPSL_SHIFT	(8)
	#endif
	#ifndef   MAP_RTE_PROFILE_VALUE_NUM
	  #define MAP_RTE_PROFILE_VALUE_NUM	(2)
	#endif
	#ifndef   MAP_RTE_STATE_MAX_LEN
	  #define MAP_RTE_STATE_MAX_LEN	(8192)
	#endif
	#ifndef   MAP_RTE_VERSION_INFO_MAX_LENGTH
	  #define MAP_RTE_VERSION_INFO_MAX_LENGTH	(51)
	#endif
	#ifndef   MAX_NUMBER_FORESIGHTINDICATORS
	  #define MAX_NUMBER_FORESIGHTINDICATORS	(10)
	#endif
	#ifndef   MAX_NUM_OF_HYPS
	  #define MAX_NUM_OF_HYPS	(12)
	#endif
	#ifndef   MFC_ECU_STATE_TEMPERATURE_ARRAY_SIZE
	  #define MFC_ECU_STATE_TEMPERATURE_ARRAY_SIZE	(10)
	#endif
	#ifndef   MFC_FFD_IMAGE_LENGTH
	  #define MFC_FFD_IMAGE_LENGTH	(2560)
	#endif
	#ifndef   MFC_FFD_IMAGE_LENGTH_SMALL
	  #define MFC_FFD_IMAGE_LENGTH_SMALL	(2028)
	#endif
	#ifndef   MFC_IMAGE_PYRAMID_SCALE_FACTOR
	  #define MFC_IMAGE_PYRAMID_SCALE_FACTOR	(2)
	#endif
	#ifndef   MFC_MAX_FLOW_SIZE
	  #define MFC_MAX_FLOW_SIZE	(752640)
	#endif
	#ifndef   MFC_MAX_IMAGE_HEIGHT
	  #define MFC_MAX_IMAGE_HEIGHT	(640)
	#endif
	#ifndef   MFC_MAX_IMAGE_SIZE
	  #define MFC_MAX_IMAGE_SIZE	(778240)
	#endif
	#ifndef   MFC_MAX_IMAGE_WIDTH
	  #define MFC_MAX_IMAGE_WIDTH	(1216)
	#endif
	#ifndef   MFC_MONO_CALIBRATION_DIST_COEFFICIENT_COUNT
	  #define MFC_MONO_CALIBRATION_DIST_COEFFICIENT_COUNT	(10)
	#endif
	#ifndef   MFC_MONO_CALIBRATION_RECT_COEFFICIENT_COUNT
	  #define MFC_MONO_CALIBRATION_RECT_COEFFICIENT_COUNT	(2)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L0
	  #define MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L0	(2304)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L1
	  #define MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L1	(1152)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L2
	  #define MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L2	(640)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L3
	  #define MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L3	(384)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L4
	  #define MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L4	(256)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L0
	  #define MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L0	(1152)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L1
	  #define MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L1	(576)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L2
	  #define MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L2	(320)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L3
	  #define MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L3	(192)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L4
	  #define MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L4	(128)
	#endif
	#ifndef   MFC_REDUCED_ROI_8BIT_PITCH_L0
	  #define MFC_REDUCED_ROI_8BIT_PITCH_L0	(1152)
	#endif
	#ifndef   MFC_REDUCED_ROI_8BIT_PITCH_L1
	  #define MFC_REDUCED_ROI_8BIT_PITCH_L1	(640)
	#endif
	#ifndef   MFC_REDUCED_ROI_8BIT_PITCH_L2
	  #define MFC_REDUCED_ROI_8BIT_PITCH_L2	(384)
	#endif
	#ifndef   MFC_REDUCED_ROI_8BIT_PITCH_L3
	  #define MFC_REDUCED_ROI_8BIT_PITCH_L3	(256)
	#endif
	#ifndef   MFC_REDUCED_ROI_8BIT_PITCH_L4
	  #define MFC_REDUCED_ROI_8BIT_PITCH_L4	(128)
	#endif
	#ifndef   MFC_REDUCED_ROI_EVEN_HEIGHT_L0
	  #define MFC_REDUCED_ROI_EVEN_HEIGHT_L0	(482)
	#endif
	#ifndef   MFC_REDUCED_ROI_EVEN_HEIGHT_L1
	  #define MFC_REDUCED_ROI_EVEN_HEIGHT_L1	(241)
	#endif
	#ifndef   MFC_REDUCED_ROI_EVEN_HEIGHT_L2
	  #define MFC_REDUCED_ROI_EVEN_HEIGHT_L2	(120)
	#endif
	#ifndef   MFC_REDUCED_ROI_HEIGHT_L0
	  #define MFC_REDUCED_ROI_HEIGHT_L0	(640)
	#endif
	#ifndef   MFC_REDUCED_ROI_HEIGHT_L1
	  #define MFC_REDUCED_ROI_HEIGHT_L1	(320)
	#endif
	#ifndef   MFC_REDUCED_ROI_HEIGHT_L2
	  #define MFC_REDUCED_ROI_HEIGHT_L2	(160)
	#endif
	#ifndef   MFC_REDUCED_ROI_HEIGHT_L3
	  #define MFC_REDUCED_ROI_HEIGHT_L3	(80)
	#endif
	#ifndef   MFC_REDUCED_ROI_HEIGHT_L4
	  #define MFC_REDUCED_ROI_HEIGHT_L4	(40)
	#endif
	#ifndef   MFC_REDUCED_ROI_WIDTH_L0
	  #define MFC_REDUCED_ROI_WIDTH_L0	(1152)
	#endif
	#ifndef   MFC_REDUCED_ROI_WIDTH_L1
	  #define MFC_REDUCED_ROI_WIDTH_L1	(576)
	#endif
	#ifndef   MFC_REDUCED_ROI_WIDTH_L2
	  #define MFC_REDUCED_ROI_WIDTH_L2	(288)
	#endif
	#ifndef   MFC_REDUCED_ROI_WIDTH_L3
	  #define MFC_REDUCED_ROI_WIDTH_L3	(144)
	#endif
	#ifndef   MFC_REDUCED_ROI_WIDTH_L4
	  #define MFC_REDUCED_ROI_WIDTH_L4	(72)
	#endif
	#ifndef   NUMBER_OF_OBJECTS
	  #define NUMBER_OF_OBJECTS	(40)
	#endif
	#ifndef   NUMBER_OF_REFERENCE_POINTS
	  #define NUMBER_OF_REFERENCE_POINTS	(3)
	#endif
	#ifndef   PC_ID_VALUE_DEFAULT
	  #define PC_ID_VALUE_DEFAULT	(100)
	#endif
	#ifndef   PC_ID_VALUE_MAX
	  #define PC_ID_VALUE_MAX	(1023)
	#endif
	#ifndef   PC_ID_VALUE_MIN
	  #define PC_ID_VALUE_MIN	(0)
	#endif
	#ifndef   PC_INIT_SHIFT_DEFAULT
	  #define PC_INIT_SHIFT_DEFAULT	(-1)
	#endif
	#ifndef   PC_INIT_SHIFT_MAX
	  #define PC_INIT_SHIFT_MAX	(1024)
	#endif
	#ifndef   PC_INIT_SHIFT_MIN
	  #define PC_INIT_SHIFT_MIN	(-1024)
	#endif
	#ifndef   PC_MAX_NMB_PATCHES
	  #define PC_MAX_NMB_PATCHES	(1024)
	#endif
	#ifndef   PC_SCALE_DEFAULT
	  #define PC_SCALE_DEFAULT	(1)
	#endif
	#ifndef   PC_SCALE_MAX
	  #define PC_SCALE_MAX	(2)
	#endif
	#ifndef   PC_SCALE_MIN
	  #define PC_SCALE_MIN	(0)
	#endif
	#ifndef   PC_SEARCH_RANGE_DEFAULT
	  #define PC_SEARCH_RANGE_DEFAULT	(4)
	#endif
	#ifndef   PC_SEARCH_RANGE_MAX
	  #define PC_SEARCH_RANGE_MAX	(15)
	#endif
	#ifndef   PC_SEARCH_RANGE_MIN
	  #define PC_SEARCH_RANGE_MIN	(0)
	#endif
	#ifndef   PFC_FLOWMAP_BYTE_PITCH
	  #define PFC_FLOWMAP_BYTE_PITCH	(1152)
	#endif
	#ifndef   PFC_FLOWMAP_HEIGHT
	  #define PFC_FLOWMAP_HEIGHT	(96)
	#endif
	#ifndef   PFC_FLOWMAP_PIXEL_PITCH
	  #define PFC_FLOWMAP_PIXEL_PITCH	(288)
	#endif
	#ifndef   PFC_FLOWMAP_WIDTH
	  #define PFC_FLOWMAP_WIDTH	(288)
	#endif
	#ifndef   PFC_SIGNATURE_IMG_BYTE_PITCH
	  #define PFC_SIGNATURE_IMG_BYTE_PITCH	(2304)
	#endif
	#ifndef   PFC_SIGNATURE_IMG_HEIGHT
	  #define PFC_SIGNATURE_IMG_HEIGHT	(128)
	#endif
	#ifndef   PFC_SIGNATURE_IMG_PIXEL_PITCH
	  #define PFC_SIGNATURE_IMG_PIXEL_PITCH	(576)
	#endif
	#ifndef   PFC_SIGNATURE_IMG_WIDTH
	  #define PFC_SIGNATURE_IMG_WIDTH	(576)
	#endif
	#ifndef   PFC_ZERO_SIGNAL_SIGNATURE
	  #define PFC_ZERO_SIGNAL_SIGNATURE	(797161)
	#endif
	#ifndef   RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS
	  #define RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS	(5)
	#endif
	#ifndef   RTE_HLA_NUM_DIMM_AREAS
	  #define RTE_HLA_NUM_DIMM_AREAS	(5)
	#endif
	#ifndef   RTE_HLA_NUM_DIMM_AREAS_BORDERS
	  #define RTE_HLA_NUM_DIMM_AREAS_BORDERS	(4)
	#endif
	#ifndef   RUM_IMG_PROC_LIST_SIZE
	  #define RUM_IMG_PROC_LIST_SIZE	(30)
	#endif
	#ifndef   RUM_MAX_CLUSTERS
	  #define RUM_MAX_CLUSTERS	(80)
	#endif
	#ifndef   RUM_PED_MAX_CLUSTERED_PEDS
	  #define RUM_PED_MAX_CLUSTERED_PEDS	(15)
	#endif
	#ifndef   RUM_PED_MAX_IMGTRACKED_PEDS
	  #define RUM_PED_MAX_IMGTRACKED_PEDS	(15)
	#endif
	#ifndef   RUM_PED_NUM_REF_OBJECTS
	  #define RUM_PED_NUM_REF_OBJECTS	(10)
	#endif
	#ifndef   RUM_TEMPLATE_TRACK_LIST_SIZE
	  #define RUM_TEMPLATE_TRACK_LIST_SIZE	(12)
	#endif
	#ifndef   RUM_VCL_ASSOC_LIST_SIZE
	  #define RUM_VCL_ASSOC_LIST_SIZE	(80)
	#endif
	#ifndef   RUM_VCL_CAM_OBJ_LIST_SIZE
	  #define RUM_VCL_CAM_OBJ_LIST_SIZE	(6)
	#endif
	#ifndef   RUM_VCL_NUM_DIFF_MEAS
	  #define RUM_VCL_NUM_DIFF_MEAS	(20)
	#endif
	#ifndef   RUM_VCL_NUM_EDGE_MEAS
	  #define RUM_VCL_NUM_EDGE_MEAS	(20)
	#endif
	#ifndef   SR_RTE_CCE_PROBABILITIES_MAX
	  #define SR_RTE_CCE_PROBABILITIES_MAX	(12)
	#endif
	#ifndef   SR_RTE_COMMUNICATION_BUFFER_LENGTH
	  #define SR_RTE_COMMUNICATION_BUFFER_LENGTH	(1590500)
	#endif
	#ifndef   SR_RTE_CUSTOM_FEATURE_LENGTH
	  #define SR_RTE_CUSTOM_FEATURE_LENGTH	(8)
	#endif
	#ifndef   SR_RTE_DEBUG_ABSTRACT_MAX_LEN
	  #define SR_RTE_DEBUG_ABSTRACT_MAX_LEN	(40960)
	#endif
	#ifndef   SR_RTE_ECU_SERIAL_STR_LEN
	  #define SR_RTE_ECU_SERIAL_STR_LEN	(64)
	#endif
	#ifndef   SR_RTE_HEALTH_ERRORS_LENGTH
	  #define SR_RTE_HEALTH_ERRORS_LENGTH	(4)
	#endif
	#ifndef   SR_RTE_IMAGER_RC_MAX_LUT_SIZE
	  #define SR_RTE_IMAGER_RC_MAX_LUT_SIZE	(32)
	#endif
	#ifndef   SR_RTE_IMAGER_SERIAL_STR_LEN
	  #define SR_RTE_IMAGER_SERIAL_STR_LEN	(64)
	#endif
	#ifndef   SR_RTE_MAX_NUM_ERRORS
	  #define SR_RTE_MAX_NUM_ERRORS	(32)
	#endif
	#ifndef   SR_RTE_RESULT_CLASSES_NUM
	  #define SR_RTE_RESULT_CLASSES_NUM	(5)
	#endif
	#ifndef   SR_RTE_RESULT_INFO_LENGTH
	  #define SR_RTE_RESULT_INFO_LENGTH	(3)
	#endif
	#ifndef   SR_RTE_RESULT_TRACKS_MAX
	  #define SR_RTE_RESULT_TRACKS_MAX	(16)
	#endif
	#ifndef   SR_RTE_SCRATCH_BUFFER_MAX_LEN
	  #define SR_RTE_SCRATCH_BUFFER_MAX_LEN	(40960)
	#endif
	#ifndef   SR_RTE_STATE_MAX_LEN
	  #define SR_RTE_STATE_MAX_LEN	(18874368)
	#endif
	#ifndef   SW_ATV1_1XGAIN_COLUMNPOSITIONS
	  #define SW_ATV1_1XGAIN_COLUMNPOSITIONS	(5)
	#endif
	#ifndef   SW_ATV1_1XGAIN_DEVIATIONVALUES
	  #define SW_ATV1_1XGAIN_DEVIATIONVALUES	(5)
	#endif
	#ifndef   SW_ATV1_2XGAIN_COLUMNPOSITIONS
	  #define SW_ATV1_2XGAIN_COLUMNPOSITIONS	(5)
	#endif
	#ifndef   SW_ATV1_2XGAIN_DEVIATIONVALUES
	  #define SW_ATV1_2XGAIN_DEVIATIONVALUES	(5)
	#endif
	#ifndef   SW_ATV3_1XGAIN_COLUMNPOSITIONS
	  #define SW_ATV3_1XGAIN_COLUMNPOSITIONS	(5)
	#endif
	#ifndef   SW_ATV3_1XGAIN_DEVIATIONVALUES
	  #define SW_ATV3_1XGAIN_DEVIATIONVALUES	(5)
	#endif
	#ifndef   SW_FW_ACTL_DYNAMOMETER_TEST
	  #define SW_FW_ACTL_DYNAMOMETER_TEST	(25)
	#endif
	#ifndef   SW_FW_ACTL_FUNCTION_CLUSTER_OFF
	  #define SW_FW_ACTL_FUNCTION_CLUSTER_OFF	(23)
	#endif
	#ifndef   SW_FW_ACTL_MODE_CALIB
	  #define SW_FW_ACTL_MODE_CALIB	(1)
	#endif
	#ifndef   SW_FW_ACTL_MODE_CALIB_RESET
	  #define SW_FW_ACTL_MODE_CALIB_RESET	(10)
	#endif
	#ifndef   SW_FW_ACTL_MODE_DEMO
	  #define SW_FW_ACTL_MODE_DEMO	(6)
	#endif
	#ifndef   SW_FW_ACTL_MODE_DIAG
	  #define SW_FW_ACTL_MODE_DIAG	(14)
	#endif
	#ifndef   SW_FW_ACTL_MODE_DIST_TEST
	  #define SW_FW_ACTL_MODE_DIST_TEST	(5)
	#endif
	#ifndef   SW_FW_ACTL_MODE_ECM
	  #define SW_FW_ACTL_MODE_ECM	(2)
	#endif
	#ifndef   SW_FW_ACTL_MODE_ECS
	  #define SW_FW_ACTL_MODE_ECS	(3)
	#endif
	#ifndef   SW_FW_ACTL_MODE_ECU_STARTUP
	  #define SW_FW_ACTL_MODE_ECU_STARTUP	(11)
	#endif
	#ifndef   SW_FW_ACTL_MODE_EC_BOTH
	  #define SW_FW_ACTL_MODE_EC_BOTH	(4)
	#endif
	#ifndef   SW_FW_ACTL_MODE_IDLE
	  #define SW_FW_ACTL_MODE_IDLE	(17)
	#endif
	#ifndef   SW_FW_ACTL_MODE_IOB
	  #define SW_FW_ACTL_MODE_IOB	(18)
	#endif
	#ifndef   SW_FW_ACTL_MODE_MAX_RUNTIME
	  #define SW_FW_ACTL_MODE_MAX_RUNTIME	(9)
	#endif
	#ifndef   SW_FW_ACTL_MODE_NORMAL
	  #define SW_FW_ACTL_MODE_NORMAL	(0)
	#endif
	#ifndef   SW_FW_ACTL_MODE_NVM_RESET
	  #define SW_FW_ACTL_MODE_NVM_RESET	(7)
	#endif
	#ifndef   SW_FW_ACTL_MODE_PRESHUTDOWN
	  #define SW_FW_ACTL_MODE_PRESHUTDOWN	(13)
	#endif
	#ifndef   SW_FW_ACTL_MODE_RESET
	  #define SW_FW_ACTL_MODE_RESET	(8)
	#endif
	#ifndef   SW_FW_ACTL_MODE_SAFE_SILENT
	  #define SW_FW_ACTL_MODE_SAFE_SILENT	(15)
	#endif
	#ifndef   SW_FW_ACTL_MODE_STARTUP_SOC
	  #define SW_FW_ACTL_MODE_STARTUP_SOC	(12)
	#endif
	#ifndef   SW_FW_ACTL_MODE_STEREO_PARALEL
	  #define SW_FW_ACTL_MODE_STEREO_PARALEL	(19)
	#endif
	#ifndef   SW_FW_ACTL_MODE_STEREO_STANDALONE
	  #define SW_FW_ACTL_MODE_STEREO_STANDALONE	(16)
	#endif
	#ifndef   SW_FW_ACTL_PRESHUTDOWN_EXECUTE
	  #define SW_FW_ACTL_PRESHUTDOWN_EXECUTE	(20)
	#endif
	#ifndef   SW_FW_ACTL_PRESHUTDOWN_WAIT_RESET
	  #define SW_FW_ACTL_PRESHUTDOWN_WAIT_RESET	(21)
	#endif
	#ifndef   SW_FW_ACTL_SENSOR_MISALIGNED
	  #define SW_FW_ACTL_SENSOR_MISALIGNED	(26)
	#endif
	#ifndef   SW_FW_ACTL_SOC_FATAL_ERROR
	  #define SW_FW_ACTL_SOC_FATAL_ERROR	(24)
	#endif
	#ifndef   SW_FW_ACTL_TEMPERATURE_DEGRADATION
	  #define SW_FW_ACTL_TEMPERATURE_DEGRADATION	(22)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_M1
	  #define SW_FW_ALGOCONFIG_M1	(0)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_M2
	  #define SW_FW_ALGOCONFIG_M2	(1)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_M3
	  #define SW_FW_ALGOCONFIG_M3	(2)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_M4
	  #define SW_FW_ALGOCONFIG_M4	(3)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_M5
	  #define SW_FW_ALGOCONFIG_M5	(4)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S1
	  #define SW_FW_ALGOCONFIG_S1	(0)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S10
	  #define SW_FW_ALGOCONFIG_S10	(9)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S11
	  #define SW_FW_ALGOCONFIG_S11	(10)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S12
	  #define SW_FW_ALGOCONFIG_S12	(11)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S2
	  #define SW_FW_ALGOCONFIG_S2	(1)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S3
	  #define SW_FW_ALGOCONFIG_S3	(2)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S4
	  #define SW_FW_ALGOCONFIG_S4	(3)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S5
	  #define SW_FW_ALGOCONFIG_S5	(4)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S6
	  #define SW_FW_ALGOCONFIG_S6	(5)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S7
	  #define SW_FW_ALGOCONFIG_S7	(6)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S8
	  #define SW_FW_ALGOCONFIG_S8	(7)
	#endif
	#ifndef   SW_FW_ALGOCONFIG_S9
	  #define SW_FW_ALGOCONFIG_S9	(8)
	#endif
	#ifndef   SW_FW_CRASHDUMP_SIZE
	  #define SW_FW_CRASHDUMP_SIZE	(1055)
	#endif
	#ifndef   SW_FW_DEM_BUFFER_SIZE
	  #define SW_FW_DEM_BUFFER_SIZE	(512)
	#endif
	#ifndef   SW_FW_LAB_MODE_DEMO_ON
	  #define SW_FW_LAB_MODE_DEMO_ON	(926365495)
	#endif
	#ifndef   SW_FW_LAB_MODE_DEMO_ON_MTS_OFF
	  #define SW_FW_LAB_MODE_DEMO_ON_MTS_OFF	(1940207450)
	#endif
	#ifndef   SW_FW_LAB_MODE_HIL_ON
	  #define SW_FW_LAB_MODE_HIL_ON	(2913316261)
	#endif
	#ifndef   SW_FW_LAB_MODE_MON_OFF
	  #define SW_FW_LAB_MODE_MON_OFF	(1515870810)
	#endif
	#ifndef   SW_FW_LAB_MODE_MTS_OFF
	  #define SW_FW_LAB_MODE_MTS_OFF	(1381651034)
	#endif
	#ifndef   SW_FW_LAB_MODE_MTS_ON
	  #define SW_FW_LAB_MODE_MTS_ON	(799218420)
	#endif
	#ifndef   SW_FW_LAB_MODE_OFF
	  #define SW_FW_LAB_MODE_OFF	(0)
	#endif
	#ifndef   SW_FW_MAX_NUM_RESERVED
	  #define SW_FW_MAX_NUM_RESERVED	(7)
	#endif
	#ifndef   SW_FW_MCU_MEASFREEZES_DATA_SIZE
	  #define SW_FW_MCU_MEASFREEZES_DATA_SIZE	(7936)
	#endif
	#ifndef   SW_FW_PRODUCT_ID_STRING_SZ
	  #define SW_FW_PRODUCT_ID_STRING_SZ	(16)
	#endif
	#ifndef   SW_FW_VERSION_NUBER
	  #define SW_FW_VERSION_NUBER	(2)
	#endif
	#ifndef   SW_FW_XCP_DATA_SIZE
	  #define SW_FW_XCP_DATA_SIZE	(64)
	#endif
	#ifndef   SW_HIL_TIME_SIZE
	  #define SW_HIL_TIME_SIZE	(8)
	#endif
	#ifndef   SW_HMI_VERSION_NUBER
	  #define SW_HMI_VERSION_NUBER	(1)
	#endif
	#ifndef   SW_MON_CTRL_CLEAR
	  #define SW_MON_CTRL_CLEAR	(0)
	#endif
	#ifndef   SW_MON_CTRL_DIS_DPU_FATAL_ERR
	  #define SW_MON_CTRL_DIS_DPU_FATAL_ERR	(2147483649)
	#endif
	#ifndef   SW_MTFCONTI_AO_IS_HOR
	  #define SW_MTFCONTI_AO_IS_HOR	(10)
	#endif
	#ifndef   SW_MTFCONTI_AO_IS_VER
	  #define SW_MTFCONTI_AO_IS_VER	(10)
	#endif
	#ifndef   SW_VERSION
	  #define SW_VERSION	(12)
	#endif
	#ifndef   TLR_MAXIMUM_CLASS
	  #define TLR_MAXIMUM_CLASS	(60)
	#endif
	#ifndef   TLR_MAXIMUM_OUTPUT_TRACKS
	  #define TLR_MAXIMUM_OUTPUT_TRACKS	(20)
	#endif
	#ifndef   TRACE_NO_OF_TRACES
	  #define TRACE_NO_OF_TRACES	(10)
	#endif
	#ifndef   TSA_RTE_CPAR_EXP_TAB_SIZE
	  #define TSA_RTE_CPAR_EXP_TAB_SIZE	(5)
	#endif
	#ifndef   TSA_RTE_CPAR_WWA_CC_LENGTH
	  #define TSA_RTE_CPAR_WWA_CC_LENGTH	(24)
	#endif
	#ifndef   TSA_RTE_CUSTOM_INPUT_RESERVED_BYTES_NUM
	  #define TSA_RTE_CUSTOM_INPUT_RESERVED_BYTES_NUM	(8)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_INFO_LENGTH
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_INFO_LENGTH	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_NUM_MAIN_CLASSES
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_NUM_MAIN_CLASSES	(5)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_NUM_SUPPL_CLASSES
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_NUM_SUPPL_CLASSES	(5)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACKS_MAX
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACKS_MAX	(16)
	#endif
	#ifndef   TSA_RTE_ISO3166_REGION_SHORT_NAME_LENGTH
	  #define TSA_RTE_ISO3166_REGION_SHORT_NAME_LENGTH	(8)
	#endif
	#ifndef   TSA_RTE_NVM_GWW_RESERVED_BYTES_NUM
	  #define TSA_RTE_NVM_GWW_RESERVED_BYTES_NUM	(16)
	#endif
	#ifndef   TSA_RTE_NVM_RESERVED_BYTES_NUM
	  #define TSA_RTE_NVM_RESERVED_BYTES_NUM	(50)
	#endif
	#ifndef   TSA_RTE_NVM_SLA_NUM_RESULTS
	  #define TSA_RTE_NVM_SLA_NUM_RESULTS	(2)
	#endif
	#ifndef   TSA_RTE_NVM_WWA_RESERVED_BYTES_NUM
	  #define TSA_RTE_NVM_WWA_RESERVED_BYTES_NUM	(16)
	#endif
	#ifndef   TSA_RTE_ROADCHARACTERISTICS_LEN
	  #define TSA_RTE_ROADCHARACTERISTICS_LEN	(10)
	#endif
	#ifndef   TSA_RTE_ROADFORSIGHT_CURVEFORESIGHT_LEN
	  #define TSA_RTE_ROADFORSIGHT_CURVEFORESIGHT_LEN	(15)
	#endif
	#ifndef   TSA_RTE_ROADFORSIGHT_ROADTOPOLOGY_LEN
	  #define TSA_RTE_ROADFORSIGHT_ROADTOPOLOGY_LEN	(10)
	#endif
	#ifndef   TSA_RTE_SLA_HEALTH_LEN
	  #define TSA_RTE_SLA_HEALTH_LEN	(16)
	#endif
	#ifndef   TSA_RTE_SLA_NUM_RESULTS
	  #define TSA_RTE_SLA_NUM_RESULTS	(3)
	#endif
	#ifndef   TSA_RTE_SPEEDFORESIGHTDATA_LEN
	  #define TSA_RTE_SPEEDFORESIGHTDATA_LEN	(10)
	#endif
	#ifndef   TSA_RTE_TA19_NAVI_EU_NUM_OF_LINKS
	  #define TSA_RTE_TA19_NAVI_EU_NUM_OF_LINKS	(5)
	#endif
	#ifndef   TSA_RTE_TA19_NAVI_EU_SPDLMT_NUM
	  #define TSA_RTE_TA19_NAVI_EU_SPDLMT_NUM	(6)
	#endif
	#ifndef   VDY_SWA_RAT_NO_ANGL
	  #define VDY_SWA_RAT_NO_ANGL	(2)
	#endif
	#ifndef   VDY_SWA_RAT_NO_VELO
	  #define VDY_SWA_RAT_NO_VELO	(2)
	#endif
	#ifndef   VODCA_MAX_CLASSIFIER_ID
	  #define VODCA_MAX_CLASSIFIER_ID	(63)
	#endif
	#ifndef   VODCA_MAX_DETECTION_IDX
	  #define VODCA_MAX_DETECTION_IDX	(511)
	#endif
	#ifndef   VODCA_MAX_LENGTH_DETECTOR_NAME
	  #define VODCA_MAX_LENGTH_DETECTOR_NAME	(24)
	#endif
	#ifndef   VODCA_MAX_LENGTH_SUB_TYPE_NAME
	  #define VODCA_MAX_LENGTH_SUB_TYPE_NAME	(8)
	#endif
	#ifndef   VODCA_MAX_NUMBER_OF_ANCHOR_AREAS
	  #define VODCA_MAX_NUMBER_OF_ANCHOR_AREAS	(256)
	#endif
	#ifndef   VODCA_MAX_NUMBER_OF_CLASSIFIERS
	  #define VODCA_MAX_NUMBER_OF_CLASSIFIERS	(64)
	#endif
	#ifndef   VODCA_MAX_NUMBER_OF_DETECTIONS
	  #define VODCA_MAX_NUMBER_OF_DETECTIONS	(512)
	#endif
	#ifndef   VODCA_MAX_NUMBER_OF_SUB_TYPES
	  #define VODCA_MAX_NUMBER_OF_SUB_TYPES	(8)
	#endif
	#ifndef   VODCA_MAX_NUM_EXPERTS
	  #define VODCA_MAX_NUM_EXPERTS	(4)
	#endif
	#ifndef   VODCA_MAX_NUM_INTERPORLATION_POINTS
	  #define VODCA_MAX_NUM_INTERPORLATION_POINTS	(10)
	#endif

/* typedef InterfaceVersion */
	#ifndef   ABD_OUTPUT_DATA_INTFVER
	  #define ABD_OUTPUT_DATA_INTFVER	(2)
	#endif
	#ifndef   ACAL_NVM_INTFVER
	  #define ACAL_NVM_INTFVER	(2)
	#endif
	#ifndef   BASE_CTRL_DATA_INTFVER
	  #define BASE_CTRL_DATA_INTFVER	(2)
	#endif
	#ifndef   BSW_VDY_CTRL_DATA_INTFVER
	  #define BSW_VDY_CTRL_DATA_INTFVER	(2)
	#endif
	#ifndef   BSW_VEH_PAR_INTFVER_LCF
	  #define BSW_VEH_PAR_INTFVER_LCF	(8)
	#endif
	#ifndef   BSW_VEH_SIG_INTFVER_LCF
	  #define BSW_VEH_SIG_INTFVER_LCF	(10)
	#endif
	#ifndef   CB_CPAR_INTFVER
	  #define CB_CPAR_INTFVER	(4)
	#endif
	#ifndef   CB_HEATING_REQUEST_INTFVER
	  #define CB_HEATING_REQUEST_INTFVER	(3)
	#endif
	#ifndef   CB_IPC_PROVIDED_OUTPUTS_INTFVER
	  #define CB_IPC_PROVIDED_OUTPUTS_INTFVER	(4)
	#endif
	#ifndef   CB_PROVIDED_OUTPUTS_INTFVER
	  #define CB_PROVIDED_OUTPUTS_INTFVER	(9)
	#endif
	#ifndef   CIPP_IMG_STAT_INTFVER
	  #define CIPP_IMG_STAT_INTFVER	(1)
	#endif
	#ifndef   CIPP_WBR_INTFVER
	  #define CIPP_WBR_INTFVER	(1)
	#endif
	#ifndef   COMP_STATE_INTFVER
	  #define COMP_STATE_INTFVER	(3)
	#endif
	#ifndef   CPAR_ALDW_Parameters_INTFVER
	  #define CPAR_ALDW_Parameters_INTFVER	(8)
	#endif
	#ifndef   CPAR_ECM_RTE_INTFVER
	  #define CPAR_ECM_RTE_INTFVER	(3)
	#endif
	#ifndef   CPAR_EMO_INTFVER
	  #define CPAR_EMO_INTFVER	(8)
	#endif
	#ifndef   CPAR_FCT_LKS_PARAMETERS_INTFVER
	  #define CPAR_FCT_LKS_PARAMETERS_INTFVER	(4)
	#endif
	#ifndef   CPAR_FCT_PARAMETERS_INTFVER
	  #define CPAR_FCT_PARAMETERS_INTFVER	(14)
	#endif
	#ifndef   CPAR_HLAF_PARAMETER_INTFVER
	  #define CPAR_HLAF_PARAMETER_INTFVER	(10)
	#endif
	#ifndef   CPAR_LD_INTFVER
	  #define CPAR_LD_INTFVER	(2)
	#endif
	#ifndef   CPAR_TLR_PARAMETERS_INTFVER
	  #define CPAR_TLR_PARAMETERS_INTFVER	(2)
	#endif
	#ifndef   CPAR_UDW_PARAMETERS_INTFVER
	  #define CPAR_UDW_PARAMETERS_INTFVER	(9)
	#endif
	#ifndef   DISPARITY_IMAGE_INTFVER
	  #define DISPARITY_IMAGE_INTFVER	(2)
	#endif
	#ifndef   ECM_RTE_ALGO_HIS_INTFVER
	  #define ECM_RTE_ALGO_HIS_INTFVER	(2)
	#endif
	#ifndef   ECM_RTE_DIAG_INPUT_INTFVER
	  #define ECM_RTE_DIAG_INPUT_INTFVER	(5)
	#endif
	#ifndef   ECM_RTE_ENV_FOV_DATA_INTFVER
	  #define ECM_RTE_ENV_FOV_DATA_INTFVER	(1)
	#endif
	#ifndef   ECM_RTE_OUTPUT_INTFVER
	  #define ECM_RTE_OUTPUT_INTFVER	(5)
	#endif
	#ifndef   ECU_STATE_INTFVER
	  #define ECU_STATE_INTFVER	(1)
	#endif
	#ifndef   EMO_EXPORT_INTFVER
	  #define EMO_EXPORT_INTFVER	(3)
	#endif
	#ifndef   EMO_OUTPUT_INTFVER
	  #define EMO_OUTPUT_INTFVER	(4)
	#endif
	#ifndef   EMT0_OBJECT_LIST_MCAM_INTFVER
	  #define EMT0_OBJECT_LIST_MCAM_INTFVER	(1)
	#endif
	#ifndef   EM_CAM_OBJECT_INTFVER
	  #define EM_CAM_OBJECT_INTFVER	(11)
	#endif
	#ifndef   EM_CAM_OBJECT_LIST_INTFVER
	  #define EM_CAM_OBJECT_LIST_INTFVER	(131083)
	#endif
	#ifndef   EM_CLEARANCE_DETECTION_INTFVER
	  #define EM_CLEARANCE_DETECTION_INTFVER	(1)
	#endif
	#ifndef   EM_CUSTOM_OBJECT_LIST_INTFVER_LCF
	  #define EM_CUSTOM_OBJECT_LIST_INTFVER_LCF	(2)
	#endif
	#ifndef   EM_EAB_FEATURE_LIST_INTFVER
	  #define EM_EAB_FEATURE_LIST_INTFVER	(1)
	#endif
	#ifndef   EM_GEN_LANDMARK_INTFVER
	  #define EM_GEN_LANDMARK_INTFVER	(3)
	#endif
	#ifndef   EM_GEN_LANDMARK_LIST_INTFVER
	  #define EM_GEN_LANDMARK_LIST_INTFVER	(65536)
	#endif
	#ifndef   EM_GEN_OBJECT_INTFVER_LCF
	  #define EM_GEN_OBJECT_INTFVER_LCF	(15)
	#endif
	#ifndef   EM_GEN_OBJECT_LIST_INTFVER_LCF
	  #define EM_GEN_OBJECT_LIST_INTFVER_LCF	(262159)
	#endif
	#ifndef   EM_GSS_DYNAMIC_MAP_INTFVER
	  #define EM_GSS_DYNAMIC_MAP_INTFVER	(4)
	#endif
	#ifndef   EM_GSS_SEGMENTATION_INTFVER
	  #define EM_GSS_SEGMENTATION_INTFVER	(4)
	#endif
	#ifndef   EM_PED_OUTPUT_INTFVER
	  #define EM_PED_OUTPUT_INTFVER	(2)
	#endif
	#ifndef   EM_VCL_OUTPUT_INTFVER
	  #define EM_VCL_OUTPUT_INTFVER	(2)
	#endif
	#ifndef   FAMO_OUTPUT_DATA_INTFVER
	  #define FAMO_OUTPUT_DATA_INTFVER	(1)
	#endif
	#ifndef   FCT_ASSESSED_OBJ_INTFVER_LCF
	  #define FCT_ASSESSED_OBJ_INTFVER_LCF	(15)
	#endif
	#ifndef   FCT_CAM_LANE_INPUT_INTFVER_LCF
	  #define FCT_CAM_LANE_INPUT_INTFVER_LCF	(5)
	#endif
	#ifndef   FCT_CD_OUTPUT_CUSTOM_INTFVER_LCF
	  #define FCT_CD_OUTPUT_CUSTOM_INTFVER_LCF	(20)
	#endif
	#ifndef   FCT_CTRL_DATA_INTFVER
	  #define FCT_CTRL_DATA_INTFVER	(1)
	#endif
	#ifndef   FCT_DIM_INPUT_CUSTOM_INTFVER_LCF
	  #define FCT_DIM_INPUT_CUSTOM_INTFVER_LCF	(11)
	#endif
	#ifndef   FCT_DIM_INPUT_GENERIC_INTFVER_LCF
	  #define FCT_DIM_INPUT_GENERIC_INTFVER_LCF	(5)
	#endif
	#ifndef   FCT_DIM_OUTPUT_CUSTOM_INTFVER_LCF
	  #define FCT_DIM_OUTPUT_CUSTOM_INTFVER_LCF	(6)
	#endif
	#ifndef   FCT_HEAD_INPUT_CUSTOM_INTFVER_LCF
	  #define FCT_HEAD_INPUT_CUSTOM_INTFVER_LCF	(10)
	#endif
	#ifndef   FCT_HEAD_INPUT_GENERIC_INTFVER
	  #define FCT_HEAD_INPUT_GENERIC_INTFVER	(7)
	#endif
	#ifndef   FCT_HEAD_OUTPUT_CUSTOM_INTFVER_LCF
	  #define FCT_HEAD_OUTPUT_CUSTOM_INTFVER_LCF	(41)
	#endif
	#ifndef   FCT_HEAD_OUTPUT_GENERIC_INTFVER
	  #define FCT_HEAD_OUTPUT_GENERIC_INTFVER	(2)
	#endif
	#ifndef   FCT_HYPOTHESIS_INTFVER_LCF
	  #define FCT_HYPOTHESIS_INTFVER_LCF	(24)
	#endif
	#ifndef   FCT_LKA_INPUT_GENERIC_INTFVER
	  #define FCT_LKA_INPUT_GENERIC_INTFVER	(11)
	#endif
	#ifndef   FCT_LKA_OUTPUT_GENERIC_INTFVER
	  #define FCT_LKA_OUTPUT_GENERIC_INTFVER	(16)
	#endif
	#ifndef   FCT_LKS_Output_LCD_INTFVER
	  #define FCT_LKS_Output_LCD_INTFVER	(3)
	#endif
	#ifndef   FCT_LKS_Output_LCK_INTFVER
	  #define FCT_LKS_Output_LCK_INTFVER	(3)
	#endif
	#ifndef   FCT_SEN_ACC_OOI_INTFVER_LCF
	  #define FCT_SEN_ACC_OOI_INTFVER_LCF	(4)
	#endif
	#ifndef   FCT_SEN_ERROR_OUT_INTFVER_LCF
	  #define FCT_SEN_ERROR_OUT_INTFVER_LCF	(15)
	#endif
	#ifndef   FFDIMAGE8SMALL_INTFVER
	  #define FFDIMAGE8SMALL_INTFVER	(1)
	#endif
	#ifndef   FFDIMAGE8_INTFVER
	  #define FFDIMAGE8_INTFVER	(1)
	#endif
	#ifndef   FLOW_IMAGE_INTFVER
	  #define FLOW_IMAGE_INTFVER	(3)
	#endif
	#ifndef   FLSP_CALL_INTR_DIST_INTFVER
	  #define FLSP_CALL_INTR_DIST_INTFVER	(2)
	#endif
	#ifndef   FLSP_IMAGER_ANALOG_TEST_INTFVER
	  #define FLSP_IMAGER_ANALOG_TEST_INTFVER	(2)
	#endif
	#ifndef   FLSP_IMAGER_CHAR_RIGHT_INTFVER
	  #define FLSP_IMAGER_CHAR_RIGHT_INTFVER	(3)
	#endif
	#ifndef   FLSP_PROD_DATA_INTFVER
	  #define FLSP_PROD_DATA_INTFVER	(2)
	#endif
	#ifndef   FLSP_PROD_INTR_INTFVER
	  #define FLSP_PROD_INTR_INTFVER	(3)
	#endif
	#ifndef   FLSP_RESPONSE_CURVES_INTFVER
	  #define FLSP_RESPONSE_CURVES_INTFVER	(2)
	#endif
	#ifndef   FLSP_STEREO_CAL_INTR_INTFVER
	  #define FLSP_STEREO_CAL_INTR_INTFVER	(2)
	#endif
	#ifndef   FTRC_FEATURE_LIST_INTFVER
	  #define FTRC_FEATURE_LIST_INTFVER	(6)
	#endif
	#ifndef   FTRC_REQUEST_GRID_INTFVER
	  #define FTRC_REQUEST_GRID_INTFVER	(2)
	#endif
	#ifndef   FTRC_SEED_KILL_LIST_INTFVER
	  #define FTRC_SEED_KILL_LIST_INTFVER	(4)
	#endif
	#ifndef   HLA_BUS_INPUT_SIGNALS_INTFVER
	  #define HLA_BUS_INPUT_SIGNALS_INTFVER	(1)
	#endif
	#ifndef   HLA_RADAR_OBJECT_LIST_INTFVER
	  #define HLA_RADAR_OBJECT_LIST_INTFVER	(1)
	#endif
	#ifndef   HMI_INPUT_DATA
	  #define HMI_INPUT_DATA	(3)
	#endif
	#ifndef   IC_IMAGE_CHARACTERISTICS_INTFVER
	  #define IC_IMAGE_CHARACTERISTICS_INTFVER	(2)
	#endif
	#ifndef   IC_IMAGE_STATISTIC_INTFVER
	  #define IC_IMAGE_STATISTIC_INTFVER	(2)
	#endif
	#ifndef   IMAGE16_INTFVER
	  #define IMAGE16_INTFVER	(3)
	#endif
	#ifndef   IMAGE8_INTFVER
	  #define IMAGE8_INTFVER	(3)
	#endif
	#ifndef   LCF_CAN2LADMCIUC_INTFVER
	  #define LCF_CAN2LADMCIUC_INTFVER	(2)
	#endif
	#ifndef   LCF_INPUT_INTFVER
	  #define LCF_INPUT_INTFVER	(21)
	#endif
	#ifndef   LCF_IUC2SOC_INTFVER
	  #define LCF_IUC2SOC_INTFVER	(6)
	#endif
	#ifndef   LCF_LADMCIUC2CAN_INTFVER
	  #define LCF_LADMCIUC2CAN_INTFVER	(3)
	#endif
	#ifndef   LCF_LEARNDATA_INTFVER
	  #define LCF_LEARNDATA_INTFVER	(2)
	#endif
	#ifndef   LCF_SEN2VEH_INTFVER
	  #define LCF_SEN2VEH_INTFVER	(15)
	#endif
	#ifndef   LCF_SEN_OUTPUT_INTFVER
	  #define LCF_SEN_OUTPUT_INTFVER	(19)
	#endif
	#ifndef   LCF_SOC2IUC_INTFVER
	  #define LCF_SOC2IUC_INTFVER	(4)
	#endif
	#ifndef   LCF_TUN_PAR_DMC_INTFVER
	  #define LCF_TUN_PAR_DMC_INTFVER	(7)
	#endif
	#ifndef   LCF_TUN_PAR_KMC_INTFVER
	  #define LCF_TUN_PAR_KMC_INTFVER	(9)
	#endif
	#ifndef   LCF_TUN_PAR_LDP_INTFVER
	  #define LCF_TUN_PAR_LDP_INTFVER	(7)
	#endif
	#ifndef   LCF_TUN_PAR_LKA_INTFVER
	  #define LCF_TUN_PAR_LKA_INTFVER	(7)
	#endif
	#ifndef   LCF_VEH2SEN_INTFVER
	  #define LCF_VEH2SEN_INTFVER	(11)
	#endif
	#ifndef   LCF_VEH_OUTPUT_INTFVER
	  #define LCF_VEH_OUTPUT_INTFVER	(10)
	#endif
	#ifndef   LD_ONLINE_CALI_DATA_INTFVER
	  #define LD_ONLINE_CALI_DATA_INTFVER	(1)
	#endif
	#ifndef   LD_OUTPUT_DATA_INTFVER
	  #define LD_OUTPUT_DATA_INTFVER	(3)
	#endif
	#ifndef   LSD_CPAR_INTFVER
	  #define LSD_CPAR_INTFVER	(257)
	#endif
	#ifndef   LSD_ENVIRONMENT_DATA_INTFVER
	  #define LSD_ENVIRONMENT_DATA_INTFVER	(256)
	#endif
	#ifndef   LSD_LIGHT_LIST_INTFVER
	  #define LSD_LIGHT_LIST_INTFVER	(257)
	#endif
	#ifndef   LSD_LIGHT_OBJECT_LIST_INTFVER
	  #define LSD_LIGHT_OBJECT_LIST_INTFVER	(257)
	#endif
	#ifndef   LSD_NVM_INTFVER
	  #define LSD_NVM_INTFVER	(256)
	#endif
	#ifndef   MAP_NVM_INTFVER
	  #define MAP_NVM_INTFVER	(1)
	#endif
	#ifndef   MAP_RTE_INPUT_INTFVER
	  #define MAP_RTE_INPUT_INTFVER	(2)
	#endif
	#ifndef   MAP_RTE_OUTPUT_INTFVER
	  #define MAP_RTE_OUTPUT_INTFVER	(2)
	#endif
	#ifndef   MONO_CALIBRATION_EOL_INTFVER
	  #define MONO_CALIBRATION_EOL_INTFVER	(3)
	#endif
	#ifndef   MONO_CALIBRATION_INTFVER
	  #define MONO_CALIBRATION_INTFVER	(9)
	#endif
	#ifndef   MONO_CALIBRATION_RECTIFICATION_INTFVER
	  #define MONO_CALIBRATION_RECTIFICATION_INTFVER	(3)
	#endif
	#ifndef   NVM_ECM_RTE_INTFVER
	  #define NVM_ECM_RTE_INTFVER	(3)
	#endif
	#ifndef   NVM_EMO_INTFVER
	  #define NVM_EMO_INTFVER	(9)
	#endif
	#ifndef   NVM_UDW_STATE_INTFVER
	  #define NVM_UDW_STATE_INTFVER	(10)
	#endif
	#ifndef   PC_REQUEST_PATCHES_INTFVER
	  #define PC_REQUEST_PATCHES_INTFVER	(1)
	#endif
	#ifndef   PC_RESULT_PATCHES_INTFVER
	  #define PC_RESULT_PATCHES_INTFVER	(1)
	#endif
	#ifndef   PFC_SIGNATUREIMAGE_INTFVER
	  #define PFC_SIGNATUREIMAGE_INTFVER	(2)
	#endif
	#ifndef   RTE_HLAF_HEADLIGHTCONTROL_INTFVER
	  #define RTE_HLAF_HEADLIGHTCONTROL_INTFVER	(12)
	#endif
	#ifndef   RTE_INPUT_GPS_INTFVER
	  #define RTE_INPUT_GPS_INTFVER	(65793)
	#endif
	#ifndef   RUM_CLUSTERS_INTFVER
	  #define RUM_CLUSTERS_INTFVER	(6)
	#endif
	#ifndef   RUM_IMG_PROC_RQ_INTFVER
	  #define RUM_IMG_PROC_RQ_INTFVER	(2)
	#endif
	#ifndef   RUM_IMG_PROC_RSP_INTFVER
	  #define RUM_IMG_PROC_RSP_INTFVER	(2)
	#endif
	#ifndef   RUM_PED_CLUSTERED_PEDS_INTFVER
	  #define RUM_PED_CLUSTERED_PEDS_INTFVER	(1)
	#endif
	#ifndef   RUM_PED_IMGTRACKED_PEDS_INTFVER
	  #define RUM_PED_IMGTRACKED_PEDS_INTFVER	(2)
	#endif
	#ifndef   RUM_TEMPLATE_TRACK_REQUESTS_INTFVER
	  #define RUM_TEMPLATE_TRACK_REQUESTS_INTFVER	(2)
	#endif
	#ifndef   RUM_TEMPLATE_TRACK_RESPONSES_INTFVER
	  #define RUM_TEMPLATE_TRACK_RESPONSES_INTFVER	(3)
	#endif
	#ifndef   RUM_VCL_MEAS_LIST_INTFVER
	  #define RUM_VCL_MEAS_LIST_INTFVER	(5)
	#endif
	#ifndef   SR_RTE_CODING_PARAMS_INTFVER
	  #define SR_RTE_CODING_PARAMS_INTFVER	(262145)
	#endif
	#ifndef   SR_RTE_COMMUNICATION_BUFFER_INTFVER
	  #define SR_RTE_COMMUNICATION_BUFFER_INTFVER	(1)
	#endif
	#ifndef   SR_RTE_OUTPUT_INTFVER
	  #define SR_RTE_OUTPUT_INTFVER	(5)
	#endif
	#ifndef   SW_MCU_SYSTEM_DATA_INTFVER
	  #define SW_MCU_SYSTEM_DATA_INTFVER	(3)
	#endif
	#ifndef   SW_MCU_TIME_STAMP_INTFVER
	  #define SW_MCU_TIME_STAMP_INTFVER	(1)
	#endif
	#ifndef   SW_NVM_CFG_ECU_INTFVER
	  #define SW_NVM_CFG_ECU_INTFVER	(1)
	#endif
	#ifndef   SW_SOC_DEMSLAVEEVENTS_INTVER
	  #define SW_SOC_DEMSLAVEEVENTS_INTVER	(1)
	#endif
	#ifndef   SW_SOC_FHCOMMAND_INTVER
	  #define SW_SOC_FHCOMMAND_INTVER	(1)
	#endif
	#ifndef   SW_SOC_FHREPLY_INTVER
	  #define SW_SOC_FHREPLY_INTVER	(1)
	#endif
	#ifndef   SW_SOC_HIL_TIMESYNC_INTFVER
	  #define SW_SOC_HIL_TIMESYNC_INTFVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBATESTPARAM_INTVER
	  #define SW_SOC_MCUIOBATESTPARAM_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBATESTRESULTS_INTVER
	  #define SW_SOC_MCUIOBATESTRESULTS_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBEMBEDDEDDATA_INTVER
	  #define SW_SOC_MCUIOBEMBEDDEDDATA_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBICSETTINGS_INTVER
	  #define SW_SOC_MCUIOBICSETTINGS_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBIMAGEDATA_INTVER
	  #define SW_SOC_MCUIOBIMAGEDATA_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBLFTCONFIG_INTVER
	  #define SW_SOC_MCUIOBLFTCONFIG_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBLFTRESULT_INTVER
	  #define SW_SOC_MCUIOBLFTRESULT_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBPRODTESTCFG_INTVER
	  #define SW_SOC_MCUIOBPRODTESTCFG_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBPRODTESTRESULT_INTVER
	  #define SW_SOC_MCUIOBPRODTESTRESULT_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBREQUEST_INTVER
	  #define SW_SOC_MCUIOBREQUEST_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBRESPONSE_INTVER
	  #define SW_SOC_MCUIOBRESPONSE_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBROI_INTVER
	  #define SW_SOC_MCUIOBROI_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBSHRPOUTDATA_INTVER
	  #define SW_SOC_MCUIOBSHRPOUTDATA_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUIOBSHRPRESULT_INTVER
	  #define SW_SOC_MCUIOBSHRPRESULT_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCUMEASFREEZE_INTVER
	  #define SW_SOC_MCUMEASFREEZE_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCU_CDRCOMMAND_INTVER
	  #define SW_SOC_MCU_CDRCOMMAND_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCU_CDRCONFIG_INTVER
	  #define SW_SOC_MCU_CDRCONFIG_INTVER	(5)
	#endif
	#ifndef   SW_SOC_MCU_CDRENCRYPTION_INTVER
	  #define SW_SOC_MCU_CDRENCRYPTION_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCU_CDRREPLY_INTVER
	  #define SW_SOC_MCU_CDRREPLY_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCU_CDRTRIGGERID_INTVER
	  #define SW_SOC_MCU_CDRTRIGGERID_INTVER	(1)
	#endif
	#ifndef   SW_SOC_MCU_CDRTRIGGER_INTVER
	  #define SW_SOC_MCU_CDRTRIGGER_INTVER	(3)
	#endif
	#ifndef   SW_SOC_SOCCRUSHDUMP_INTVER
	  #define SW_SOC_SOCCRUSHDUMP_INTVER	(1)
	#endif
	#ifndef   SW_SOC_SYSTEMCONFINFO_INTVER
	  #define SW_SOC_SYSTEMCONFINFO_INTVER	(1)
	#endif
	#ifndef   SW_SOC_SYSTEM_DATA_INTFVER
	  #define SW_SOC_SYSTEM_DATA_INTFVER	(2)
	#endif
	#ifndef   SW_SOC_XCPRXCONT_INTVER
	  #define SW_SOC_XCPRXCONT_INTVER	(1)
	#endif
	#ifndef   SW_SOC_XCPTXCONT_INTVER
	  #define SW_SOC_XCPTXCONT_INTVER	(1)
	#endif
	#ifndef   SW_SoC_STAT_ECU_DATA_INTFVER
	  #define SW_SoC_STAT_ECU_DATA_INTFVER	(1)
	#endif
	#ifndef   TLR_OUTPUT_INTFVER
	  #define TLR_OUTPUT_INTFVER	(6)
	#endif
	#ifndef   TSA_RTE_CODING_PARAMS_INTFVER
	  #define TSA_RTE_CODING_PARAMS_INTFVER	(132097)
	#endif
	#ifndef   TSA_RTE_CUSTOM_INPUT_INTFVER
	  #define TSA_RTE_CUSTOM_INPUT_INTFVER	(327682)
	#endif
	#ifndef   TSA_RTE_INPUT_NAVIGATION_INTFVER
	  #define TSA_RTE_INPUT_NAVIGATION_INTFVER	(66049)
	#endif
	#ifndef   TSA_RTE_NVM_STATE_INTFVER
	  #define TSA_RTE_NVM_STATE_INTFVER	(131076)
	#endif
	#ifndef   TSA_RTE_OUTPUT_CUSTOM_INTFVER
	  #define TSA_RTE_OUTPUT_CUSTOM_INTFVER	(196608)
	#endif
	#ifndef   TSA_RTE_OUTPUT_RESULTS_INTFVER
	  #define TSA_RTE_OUTPUT_RESULTS_INTFVER	(67584)
	#endif
	#ifndef   UDW_INPUT_CUSTOM_INTFVER
	  #define UDW_INPUT_CUSTOM_INTFVER	(4)
	#endif
	#ifndef   UDW_INPUT_GENERIC_INTFVER
	  #define UDW_INPUT_GENERIC_INTFVER	(10)
	#endif
	#ifndef   UDW_OUTPUT_GENERIC_INTFVER
	  #define UDW_OUTPUT_GENERIC_INTFVER	(6)
	#endif
	#ifndef   VDY_ERRORS_INTFVER_LCF
	  #define VDY_ERRORS_INTFVER_LCF	(6)
	#endif
	#ifndef   VDY_EST_CURVES_INTFVER
	  #define VDY_EST_CURVES_INTFVER	(1)
	#endif
	#ifndef   VDY_NVM_IO_DATA_INTFVER
	  #define VDY_NVM_IO_DATA_INTFVER	(1)
	#endif
	#ifndef   VDY_OFFSETS_INTFVER
	  #define VDY_OFFSETS_INTFVER	(2)
	#endif
	#ifndef   VDY_VEH_DYN_INTFVER_LCF
	  #define VDY_VEH_DYN_INTFVER_LCF	(33)
	#endif
	#ifndef   VODCA_ANCHOR_AREA_CONFIG_INTFVER
	  #define VODCA_ANCHOR_AREA_CONFIG_INTFVER	(3)
	#endif
	#ifndef   VODCA_DETECTION_RESULTS_INTFVER
	  #define VODCA_DETECTION_RESULTS_INTFVER	(4)
	#endif
	#ifndef   VODCA_DETECTOR_PARAMS_INTFVER
	  #define VODCA_DETECTOR_PARAMS_INTFVER	(5)
	#endif

#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif /* RTE_Algo_TYPE_H */
