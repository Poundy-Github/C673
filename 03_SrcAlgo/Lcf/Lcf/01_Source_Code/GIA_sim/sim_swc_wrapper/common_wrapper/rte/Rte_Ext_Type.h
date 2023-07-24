/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_Ext_Type.h
CESSAR-CT Version: 4.0.3.4
RTE Version: 4.0.3.1.2.0p06
Generated on:	Fri Feb 28 17:44:41 CET 2014
**************************************************************************/

#ifndef RTE_Ext_TYPE_H
#define RTE_Ext_TYPE_H

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */


#ifndef RTE_C
#include "Rte_Type.h"
#endif
/**********************************************/
/* Mode management types                      */
/**********************************************/






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
	#ifndef   ALGO_QUAL_CALIBRATION_ERROR_TO_HIGHT
	  #define ALGO_QUAL_CALIBRATION_ERROR_TO_HIGHT	(16)
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

/* typedef BaseSchedulingMode_t */
	#ifndef   BASE_SM_IDLE
	  #define BASE_SM_IDLE	(0)
	#endif
	#ifndef   BASE_SM_RESET
	  #define BASE_SM_RESET	(1)
	#endif
	#ifndef   BASE_SM_MAX_RUNTIME
	  #define BASE_SM_MAX_RUNTIME	(2)
	#endif
	#ifndef   BASE_SM_DEMO
	  #define BASE_SM_DEMO	(3)
	#endif
	#ifndef   BASE_SM_RUN
	  #define BASE_SM_RUN	(4)
	#endif
	#ifndef   BASE_SM_STANDALONE
	  #define BASE_SM_STANDALONE	(5)
	#endif
	#ifndef   BASE_SM_PARALLEL
	  #define BASE_SM_PARALLEL	(6)
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
	  #define COMP_ERROR_UNKNOWN	(1)
	#endif

/* typedef eShedulerModeRequest_t */
	#ifndef   COMP_MODE_REQ_NONE
	  #define COMP_MODE_REQ_NONE	(0)
	#endif
	#ifndef   COMP_MODE_REQ_RESET
	  #define COMP_MODE_REQ_RESET	(1)
	#endif
	#ifndef   COMP_MODE_REQ_RUN
	  #define COMP_MODE_REQ_RUN	(2)
	#endif
	#ifndef   COMP_MODE_REQ_STANDALONE
	  #define COMP_MODE_REQ_STANDALONE	(3)
	#endif
	#ifndef   COMP_MODE_REQ_PARALLEL
	  #define COMP_MODE_REQ_PARALLEL	(4)
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

/* typedef eMonoCalibrationVerificationStatus_t */
	#ifndef   MC_NO_VERIFICATION_DONE_YET
	  #define MC_NO_VERIFICATION_DONE_YET	(0)
	#endif
	#ifndef   MC_ABS_DEVIATION_GREATER_1_00_DEG
	  #define MC_ABS_DEVIATION_GREATER_1_00_DEG	(1)
	#endif
	#ifndef   MC_ABS_DEVIATION_LESSEQUAL_1_00_DEG
	  #define MC_ABS_DEVIATION_LESSEQUAL_1_00_DEG	(2)
	#endif
	#ifndef   MC_ABS_DEVIATION_LESSEQUAL_0_50_DEG
	  #define MC_ABS_DEVIATION_LESSEQUAL_0_50_DEG	(3)
	#endif
	#ifndef   MC_ABS_DEVIATION_LESSEQUAL_0_25_DEG
	  #define MC_ABS_DEVIATION_LESSEQUAL_0_25_DEG	(4)
	#endif
	#ifndef   MC_ABS_DEVIATION_LESSEQUAL_0_10_DEG
	  #define MC_ABS_DEVIATION_LESSEQUAL_0_10_DEG	(5)
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

/* typedef GB_t_eStereoBlockageType */
	#ifndef   GB_RIGHT_CAM
	  #define GB_RIGHT_CAM	(2)
	#endif
	#ifndef   GB_LEFT_CAM
	  #define GB_LEFT_CAM	(4)
	#endif

/* typedef GB_t_eWeatherCondition */
	#ifndef   GB_RAIN_SNOW
	  #define GB_RAIN_SNOW	(2)
	#endif
	#ifndef   GB_FOG
	  #define GB_FOG	(4)
	#endif
	#ifndef   GB_GLARING_SUN
	  #define GB_GLARING_SUN	(8)
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

/* typedef EcmRteError_t */
	#ifndef   ECM_RTE_TYPE_NOT_STARTED
	  #define ECM_RTE_TYPE_NOT_STARTED	(0)
	#endif
	#ifndef   ECM_RTE_TYPE_RUNNING
	  #define ECM_RTE_TYPE_RUNNING	(1)
	#endif
	#ifndef   ECM_RTE_TYPE_SUCCESS
	  #define ECM_RTE_TYPE_SUCCESS	(2)
	#endif
	#ifndef   ECM_RTE_TYPE_ERROR
	  #define ECM_RTE_TYPE_ERROR	(4)
	#endif
	#ifndef   ECM_RTE_TYPE_WARN_INTENSITY_INHOMOGEN
	  #define ECM_RTE_TYPE_WARN_INTENSITY_INHOMOGEN	(16)
	#endif
	#ifndef   ECM_RTE_TYPE_WARN_INTENSITY_BELOW_RANGE
	  #define ECM_RTE_TYPE_WARN_INTENSITY_BELOW_RANGE	(32)
	#endif
	#ifndef   ECM_RTE_TYPE_WARN_INTENSITY_ABOVE_RANGE
	  #define ECM_RTE_TYPE_WARN_INTENSITY_ABOVE_RANGE	(64)
	#endif
	#ifndef   ECM_RTE_TYPE_WARN_CONTRAST_BELOW_RANGE
	  #define ECM_RTE_TYPE_WARN_CONTRAST_BELOW_RANGE	(128)
	#endif
	#ifndef   ECM_RTE_TYPE_WARN_CONTRAST_ABOVE_RANGE
	  #define ECM_RTE_TYPE_WARN_CONTRAST_ABOVE_RANGE	(256)
	#endif
	#ifndef   ECM_RTE_TYPE_WARN_OTHER
	  #define ECM_RTE_TYPE_WARN_OTHER	(512)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_SYSTEM_NOT_ECMBRATED
	  #define ECM_RTE_TYPE_ERR_SYSTEM_NOT_ECMBRATED	(2048)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_VIN_INVALID
	  #define ECM_RTE_TYPE_ERR_VIN_INVALID	(4096)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_UNKNOWN_ECM_RTE_MODE
	  #define ECM_RTE_TYPE_ERR_UNKNOWN_ECM_RTE_MODE	(8192)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_UNKNOWN_PATTERN_TYPE
	  #define ECM_RTE_TYPE_ERR_UNKNOWN_PATTERN_TYPE	(16384)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INIT_DATA_FAILED
	  #define ECM_RTE_TYPE_ERR_INIT_DATA_FAILED	(32768)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_PARAMETER_FALSE
	  #define ECM_RTE_TYPE_ERR_PARAMETER_FALSE	(65536)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INTENSITY_INHOMOGEN
	  #define ECM_RTE_TYPE_ERR_INTENSITY_INHOMOGEN	(131072)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INTENSITY_BELOW_RANGE
	  #define ECM_RTE_TYPE_ERR_INTENSITY_BELOW_RANGE	(262144)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_INTENSITY_ABOVE_RANGE
	  #define ECM_RTE_TYPE_ERR_INTENSITY_ABOVE_RANGE	(524288)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_CONTRAST_BELOW_RANGE
	  #define ECM_RTE_TYPE_ERR_CONTRAST_BELOW_RANGE	(1048576)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_CONTRAST_ABOVE_RANGE
	  #define ECM_RTE_TYPE_ERR_CONTRAST_ABOVE_RANGE	(2097152)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_NO_MARKERS
	  #define ECM_RTE_TYPE_ERR_NO_MARKERS	(4194304)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_NOT_ENOUGH_MARKERS
	  #define ECM_RTE_TYPE_ERR_NOT_ENOUGH_MARKERS	(8388608)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_TOO_MANY_MARKERS
	  #define ECM_RTE_TYPE_ERR_TOO_MANY_MARKERS	(16777216)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_UNCORRESPONDING_MARKERS
	  #define ECM_RTE_TYPE_ERR_UNCORRESPONDING_MARKERS	(33554432)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_PATTERN_ECU_MOVING
	  #define ECM_RTE_TYPE_ERR_PATTERN_ECU_MOVING	(67108864)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_PATTERN_POSITION_INVALID
	  #define ECM_RTE_TYPE_ERR_PATTERN_POSITION_INVALID	(134217728)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_NUMERIECM_RTE_PROBLEM
	  #define ECM_RTE_TYPE_ERR_NUMERIECM_RTE_PROBLEM	(268435456)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_RESULT_OUT_OF_RANGE
	  #define ECM_RTE_TYPE_ERR_RESULT_OUT_OF_RANGE	(536870912)
	#endif
	#ifndef   ECM_RTE_TYPE_ERR_OTHER
	  #define ECM_RTE_TYPE_ERR_OTHER	(1073741824)
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

/* typedef EcmRteOpMode_t */
	#ifndef   ECM_RTE_OPMODE_IDLE
	  #define ECM_RTE_OPMODE_IDLE	(0)
	#endif
	#ifndef   ECM_RTE_OPMODE_RESET
	  #define ECM_RTE_OPMODE_RESET	(1)
	#endif
	#ifndef   ECM_RTE_OPMODE_DEV
	  #define ECM_RTE_OPMODE_DEV	(2)
	#endif
	#ifndef   ECM_RTE_OPMODE_EOL
	  #define ECM_RTE_OPMODE_EOL	(3)
	#endif
	#ifndef   ECM_RTE_OPMODE_MAX_RUNTIME
	  #define ECM_RTE_OPMODE_MAX_RUNTIME	(4)
	#endif
	#ifndef   ECM_RTE_OPMODE_DEMO
	  #define ECM_RTE_OPMODE_DEMO	(5)
	#endif
	#ifndef   ECM_RTE_OPMODE_TRANSMIT
	  #define ECM_RTE_OPMODE_TRANSMIT	(6)
	#endif

/* typedef eForesightState_t */
	#ifndef   CS_FORESIGHT_init
	  #define CS_FORESIGHT_init	(1)
	#endif
	#ifndef   CS_FORESIGHT_unknown
	  #define CS_FORESIGHT_unknown	(2)
	#endif
	#ifndef   CS_FORESIGHT_true
	  #define CS_FORESIGHT_true	(4)
	#endif
	#ifndef   CS_FORESIGHT_false
	  #define CS_FORESIGHT_false	(8)
	#endif
	#ifndef   CS_FORESIGHT_notAvailable
	  #define CS_FORESIGHT_notAvailable	(2147483647)
	#endif
	#ifndef   CS_FORESIGHT_unfilled
	  #define CS_FORESIGHT_unfilled	(4294967295)
	#endif

/* typedef eForesightIndicatorType_t */
	#ifndef   CS_FORESIGHT_Indicator_init
	  #define CS_FORESIGHT_Indicator_init	(1)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_CSSign
	  #define CS_FORESIGHT_Indicator_CSSign	(2)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_SpeedLimitCascade
	  #define CS_FORESIGHT_Indicator_SpeedLimitCascade	(4)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_XingMarkers
	  #define CS_FORESIGHT_Indicator_XingMarkers	(8)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_singleMarker
	  #define CS_FORESIGHT_Indicator_singleMarker	(16)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_doubleMarker
	  #define CS_FORESIGHT_Indicator_doubleMarker	(32)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_multMarkers
	  #define CS_FORESIGHT_Indicator_multMarkers	(64)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_egoSpeedProfile
	  #define CS_FORESIGHT_Indicator_egoSpeedProfile	(128)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_precedingVehicles
	  #define CS_FORESIGHT_Indicator_precedingVehicles	(256)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_unexpOppTraffic
	  #define CS_FORESIGHT_Indicator_unexpOppTraffic	(512)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_undefType
	  #define CS_FORESIGHT_Indicator_undefType	(1073741823)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_notAvailable
	  #define CS_FORESIGHT_Indicator_notAvailable	(2147483647)
	#endif
	#ifndef   CS_FORESIGHT_Indicator_unfilled
	  #define CS_FORESIGHT_Indicator_unfilled	(4294967295)
	#endif

/* typedef eConstructionSiteState_t */
	#ifndef   CS_State_init
	  #define CS_State_init	(0)
	#endif
	#ifndef   CS_State_unknown
	  #define CS_State_unknown	(1)
	#endif
	#ifndef   CS_State_true
	  #define CS_State_true	(2)
	#endif
	#ifndef   CS_State_false
	  #define CS_State_false	(4)
	#endif
	#ifndef   CS_State_notAvailable
	  #define CS_State_notAvailable	(252)
	#endif
	#ifndef   CS_State_error
	  #define CS_State_error	(2147483647)
	#endif
	#ifndef   CS_State_unfilled
	  #define CS_State_unfilled	(4294967295)
	#endif

/* typedef eDegradationReason_t */
	#ifndef   EM_VD_DR_UNKNOWN
	  #define EM_VD_DR_UNKNOWN	(0)
	#endif
	#ifndef   EM_VD_DR_NONE
	  #define EM_VD_DR_NONE	(1)
	#endif
	#ifndef   EM_VD_DR_RAIN
	  #define EM_VD_DR_RAIN	(2)
	#endif
	#ifndef   EM_VD_DR_FOG
	  #define EM_VD_DR_FOG	(3)
	#endif
	#ifndef   EM_VD_DR_DIRECT_SUN
	  #define EM_VD_DR_DIRECT_SUN	(4)
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

/* typedef EM_t_CamObjStatusFlashLight */
	#ifndef   EM_CAM_OBJ_FLASH_LIGHT_UNKNOWN
	  #define EM_CAM_OBJ_FLASH_LIGHT_UNKNOWN	(0)
	#endif
	#ifndef   EM_CAM_OBJ_FLASH_LIGHT_NO_FLASHING
	  #define EM_CAM_OBJ_FLASH_LIGHT_NO_FLASHING	(1)
	#endif
	#ifndef   EM_CAM_OBJ_FLASH_LIGHT_FLASHING_LEFT
	  #define EM_CAM_OBJ_FLASH_LIGHT_FLASHING_LEFT	(2)
	#endif
	#ifndef   EM_CAM_OBJ_FLASH_LIGHT_FLASHING_RIGHT
	  #define EM_CAM_OBJ_FLASH_LIGHT_FLASHING_RIGHT	(3)
	#endif
	#ifndef   EM_CAM_OBJ_FLASH_LIGHT_HAZARD_FLASHING
	  #define EM_CAM_OBJ_FLASH_LIGHT_HAZARD_FLASHING	(4)
	#endif
	#ifndef   EM_CAM_OBJ_FLASH_LIGHT_SNA
	  #define EM_CAM_OBJ_FLASH_LIGHT_SNA	(255)
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
	#ifndef   EM_CAM_OBJ_ASSOC_LANE_OUTSIDE
	  #define EM_CAM_OBJ_ASSOC_LANE_OUTSIDE	(4)
	#endif
	#ifndef   EM_CAM_OBJ_ASSOC_LANE_SNA
	  #define EM_CAM_OBJ_ASSOC_LANE_SNA	(255)
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
	#ifndef   EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES
	  #define EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES	(8)
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
	#ifndef   EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES
	  #define EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES	(4)
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
	  #define EM_GEN_OBJECT_MS_SRL	(16)
	#endif
	#ifndef   EM_GEN_OBJECT_MS_MCAM
	  #define EM_GEN_OBJECT_MS_MCAM	(256)
	#endif
	#ifndef   EM_GEN_OBJECT_MS_SCAM
	  #define EM_GEN_OBJECT_MS_SCAM	(512)
	#endif

/* typedef EM_t_GenObjEbaProhibit */
	#ifndef   EM_EBA_PROHIBIT_NO
	  #define EM_EBA_PROHIBIT_NO	(0)
	#endif
	#ifndef   EM_EBA_PROHIBIT_ACUTEBRAKE
	  #define EM_EBA_PROHIBIT_ACUTEBRAKE	(1)
	#endif
	#ifndef   EM_EBA_PROHIBIT_PREBRAKE
	  #define EM_EBA_PROHIBIT_PREBRAKE	(2)
	#endif
	#ifndef   EM_EBA_PROHIBIT_PREFILL
	  #define EM_EBA_PROHIBIT_PREFILL	(3)
	#endif
	#ifndef   EM_EBA_PROHIBIT_WARN
	  #define EM_EBA_PROHIBIT_WARN	(4)
	#endif
	#ifndef   EM_EBA_PROHIBIT_MAX_DIFF_TYPES
	  #define EM_EBA_PROHIBIT_MAX_DIFF_TYPES	(5)
	#endif

/* typedef EMB0_t_EventDataQualifier */
	#ifndef   EMB0_CEDQ_EVENT_DATA_AVAILABLE
	  #define EMB0_CEDQ_EVENT_DATA_AVAILABLE	(0)
	#endif
	#ifndef   EMB0_CEDQ_EVENT_DATA_AVAILABLE_REDUCED
	  #define EMB0_CEDQ_EVENT_DATA_AVAILABLE_REDUCED	(1)
	#endif
	#ifndef   EMB0_CEDQ_EVENT_DATA_NOT_AVAILABLE
	  #define EMB0_CEDQ_EVENT_DATA_NOT_AVAILABLE	(2)
	#endif
	#ifndef   EMB0_CEDQ_SNA
	  #define EMB0_CEDQ_SNA	(255)
	#endif

/* typedef EMB0_t_ExtendedQualifier */
	#ifndef   EMB0_CEQ_NORMAL_OPERATION_MODE
	  #define EMB0_CEQ_NORMAL_OPERATION_MODE	(0)
	#endif
	#ifndef   EMB0_CEQ_POWER_UP_OR_DOWN
	  #define EMB0_CEQ_POWER_UP_OR_DOWN	(1)
	#endif
	#ifndef   EMB0_CEQ_SENSOR_NOT_CALIBRATED
	  #define EMB0_CEQ_SENSOR_NOT_CALIBRATED	(2)
	#endif
	#ifndef   EMB0_CEQ_SENSOR_BLOCKED
	  #define EMB0_CEQ_SENSOR_BLOCKED	(3)
	#endif
	#ifndef   EMB0_CEQ_SENSOR_MISALIGNED
	  #define EMB0_CEQ_SENSOR_MISALIGNED	(4)
	#endif
	#ifndef   EMB0_CEQ_BAD_SENSOR_ENVIRONMENTAL_CONDITION
	  #define EMB0_CEQ_BAD_SENSOR_ENVIRONMENTAL_CONDITION	(5)
	#endif
	#ifndef   EMB0_CEQ_REDUCED_FIELD_OF_VIEW
	  #define EMB0_CEQ_REDUCED_FIELD_OF_VIEW	(6)
	#endif
	#ifndef   EMB0_CEQ_INPUT_NOT_AVAILABLE
	  #define EMB0_CEQ_INPUT_NOT_AVAILABLE	(7)
	#endif
	#ifndef   EMB0_CEQ_INTERNAL_REASON
	  #define EMB0_CEQ_INTERNAL_REASON	(8)
	#endif
	#ifndef   EMB0_CEQ_EXTERNAL_DISTORTION
	  #define EMB0_CEQ_EXTERNAL_DISTORTION	(9)
	#endif
	#ifndef   EMB0_CEQ_BEGINNING_BLOCKAGE
	  #define EMB0_CEQ_BEGINNING_BLOCKAGE	(10)
	#endif
	#ifndef   EMB0_CEQ_SNA
	  #define EMB0_CEQ_SNA	(255)
	#endif

/* typedef EMB0_t_MeasurementStatus */
	#ifndef   EMB0_CMS_MEAS_NEW
	  #define EMB0_CMS_MEAS_NEW	(0)
	#endif
	#ifndef   EMB0_CMS_MEAS_NEW_PART_OCCL
	  #define EMB0_CMS_MEAS_NEW_PART_OCCL	(1)
	#endif
	#ifndef   EMB0_CMS_MEAS
	  #define EMB0_CMS_MEAS	(2)
	#endif
	#ifndef   EMB0_CMS_MEAS_PART_OCCL
	  #define EMB0_CMS_MEAS_PART_OCCL	(3)
	#endif
	#ifndef   EMB0_CMS_PRED
	  #define EMB0_CMS_PRED	(4)
	#endif
	#ifndef   EMB0_CMS_PRED_PART_OCCL
	  #define EMB0_CMS_PRED_PART_OCCL	(5)
	#endif
	#ifndef   EMB0_CMS_SNA
	  #define EMB0_CMS_SNA	(255)
	#endif

/* typedef EMB0_t_ObjectMovementStatus */
	#ifndef   EMB0_OMS_STATIONARY_PARKING
	  #define EMB0_OMS_STATIONARY_PARKING	(0)
	#endif
	#ifndef   EMB0_OMS_STOPPED_WAS_ONCOMING
	  #define EMB0_OMS_STOPPED_WAS_ONCOMING	(1)
	#endif
	#ifndef   EMB0_OMS_STOPPED_WAS_ONGOING
	  #define EMB0_OMS_STOPPED_WAS_ONGOING	(2)
	#endif
	#ifndef   EMB0_OMS_STOPPED_WAS_UNKNOWN
	  #define EMB0_OMS_STOPPED_WAS_UNKNOWN	(3)
	#endif
	#ifndef   EMB0_OMS_MOVING_ONCOMMING
	  #define EMB0_OMS_MOVING_ONCOMMING	(4)
	#endif
	#ifndef   EMB0_OMS_MOVING_ONGOING
	  #define EMB0_OMS_MOVING_ONGOING	(5)
	#endif
	#ifndef   EMB0_OMS_MOVING_DIR_UNKNOWN
	  #define EMB0_OMS_MOVING_DIR_UNKNOWN	(6)
	#endif
	#ifndef   EMB0_OMS_SNA
	  #define EMB0_OMS_SNA	(255)
	#endif

/* typedef EMB0_t_ObjectType */
	#ifndef   EMB0_OT_PEDESTRIAN
	  #define EMB0_OT_PEDESTRIAN	(0)
	#endif
	#ifndef   EMB0_OT_CYCLIST
	  #define EMB0_OT_CYCLIST	(1)
	#endif
	#ifndef   EMB0_OT_MOTORBIKE
	  #define EMB0_OT_MOTORBIKE	(2)
	#endif
	#ifndef   EMB0_OT_CAR
	  #define EMB0_OT_CAR	(3)
	#endif
	#ifndef   EMB0_OT_TRUCK
	  #define EMB0_OT_TRUCK	(4)
	#endif
	#ifndef   EMB0_OT_OTHER_VEHICLE
	  #define EMB0_OT_OTHER_VEHICLE	(5)
	#endif
	#ifndef   EMB0_OT_ROAD_BOUNDARY
	  #define EMB0_OT_ROAD_BOUNDARY	(6)
	#endif
	#ifndef   EMB0_OT_BRIDGE
	  #define EMB0_OT_BRIDGE	(7)
	#endif
	#ifndef   EMB0_OT_UNKNOWN
	  #define EMB0_OT_UNKNOWN	(8)
	#endif
	#ifndef   EMB0_OT_SNA
	  #define EMB0_OT_SNA	(255)
	#endif

/* typedef EMB0_t_ObjectModeLateral */
	#ifndef   EMB0_OML_UNKNOWN
	  #define EMB0_OML_UNKNOWN	(0)
	#endif
	#ifndef   EMB0_OML_CUTTING_IN_FROM_LEFT
	  #define EMB0_OML_CUTTING_IN_FROM_LEFT	(1)
	#endif
	#ifndef   EMB0_OML_CUTTING_IN_FROM_RIGHT
	  #define EMB0_OML_CUTTING_IN_FROM_RIGHT	(2)
	#endif
	#ifndef   EMB0_OML_CUTTING_OUT_TO_LEFT
	  #define EMB0_OML_CUTTING_OUT_TO_LEFT	(3)
	#endif
	#ifndef   EMB0_OML_CUTTING_OUT_TO_RIGHT
	  #define EMB0_OML_CUTTING_OUT_TO_RIGHT	(4)
	#endif
	#ifndef   EMB0_OML_NONE
	  #define EMB0_OML_NONE	(5)
	#endif
	#ifndef   EMB0_OML_SNA
	  #define EMB0_OML_SNA	(255)
	#endif

/* typedef EMB0_t_DrivingTubeMapping */
	#ifndef   EMB0_DTM_INIT_UNKNOWN
	  #define EMB0_DTM_INIT_UNKNOWN	(0)
	#endif
	#ifndef   EMB0_DTM_EGO_LANE
	  #define EMB0_DTM_EGO_LANE	(1)
	#endif
	#ifndef   EMB0_DTM_NEXT_LEFT
	  #define EMB0_DTM_NEXT_LEFT	(2)
	#endif
	#ifndef   EMB0_DTM_FAR_LEFT
	  #define EMB0_DTM_FAR_LEFT	(3)
	#endif
	#ifndef   EMB0_DTM_NEXT_RIGHT
	  #define EMB0_DTM_NEXT_RIGHT	(4)
	#endif
	#ifndef   EMB0_DTM_FAR_RIGHT
	  #define EMB0_DTM_FAR_RIGHT	(5)
	#endif
	#ifndef   EMB0_DTM_SNA
	  #define EMB0_DTM_SNA	(255)
	#endif

/* typedef EMB0_t_ObjectReferencePoint */
	#ifndef   EMB0_ORP_CORNER_FRONT_LEFT
	  #define EMB0_ORP_CORNER_FRONT_LEFT	(0)
	#endif
	#ifndef   EMB0_ORP_MIDDLE_FRONT
	  #define EMB0_ORP_MIDDLE_FRONT	(1)
	#endif
	#ifndef   EMB0_ORP_CORNER_FRONT_RIGHT
	  #define EMB0_ORP_CORNER_FRONT_RIGHT	(2)
	#endif
	#ifndef   EMB0_ORP_MIDDLE_SIDE_RIGHT
	  #define EMB0_ORP_MIDDLE_SIDE_RIGHT	(3)
	#endif
	#ifndef   EMB0_ORP_CORNER_REAR_RIGHT
	  #define EMB0_ORP_CORNER_REAR_RIGHT	(4)
	#endif
	#ifndef   EMB0_ORP_MIDDLE_REAR
	  #define EMB0_ORP_MIDDLE_REAR	(5)
	#endif
	#ifndef   EMB0_ORP_CORNER_REAR_LEFT
	  #define EMB0_ORP_CORNER_REAR_LEFT	(6)
	#endif
	#ifndef   EMB0_ORP_MIDDLE_SIDE_LEFT
	  #define EMB0_ORP_MIDDLE_SIDE_LEFT	(7)
	#endif
	#ifndef   EMB0_ORP_SNA
	  #define EMB0_ORP_SNA	(255)
	#endif

/* typedef EMB0_t_Flags */
	#ifndef   EMB0_PVF_POSITION_X_INVALID
	  #define EMB0_PVF_POSITION_X_INVALID	(1)
	#endif
	#ifndef   EMB0_PVF_POSITION_Y_INVALID
	  #define EMB0_PVF_POSITION_Y_INVALID	(2)
	#endif
	#ifndef   EMB0_PVF_POSITION_Z_INVALID
	  #define EMB0_PVF_POSITION_Z_INVALID	(4)
	#endif
	#ifndef   EMB0_DVF_LENGTH_INVALID
	  #define EMB0_DVF_LENGTH_INVALID	(8)
	#endif
	#ifndef   EMB0_DVF_WIDTH_INVALID
	  #define EMB0_DVF_WIDTH_INVALID	(16)
	#endif
	#ifndef   EMB0_DVF_HEIGHT_INVALID
	  #define EMB0_DVF_HEIGHT_INVALID	(32)
	#endif
	#ifndef   EMB0_MIVF_SPEED_ABSOLUTE_X_INVALID
	  #define EMB0_MIVF_SPEED_ABSOLUTE_X_INVALID	(64)
	#endif
	#ifndef   EMB0_MIVF_SPEED_ABSOLUTE_Y_INVALID
	  #define EMB0_MIVF_SPEED_ABSOLUTE_Y_INVALID	(128)
	#endif
	#ifndef   EMB0_MIVF_ACCEL_ABSOLUTE_X_INVALID
	  #define EMB0_MIVF_ACCEL_ABSOLUTE_X_INVALID	(256)
	#endif
	#ifndef   EMB0_MIVF_ACCEL_ABSOLUTE_Y_INVALID
	  #define EMB0_MIVF_ACCEL_ABSOLUTE_Y_INVALID	(512)
	#endif
	#ifndef   EMB0_MIVF_ACCEL_YAW_ANGLE_INVALID
	  #define EMB0_MIVF_ACCEL_YAW_ANGLE_INVALID	(1024)
	#endif
	#ifndef   EMB0_MIVF_ACCEL_YAW_SPEED_INVALID
	  #define EMB0_MIVF_ACCEL_YAW_SPEED_INVALID	(2048)
	#endif
	#ifndef   EMB0_PSDVF_STD_DEV_POSITION_X_INVALID
	  #define EMB0_PSDVF_STD_DEV_POSITION_X_INVALID	(4096)
	#endif
	#ifndef   EMB0_PSDVF_STD_DEV_POSITION_Y_INVALID
	  #define EMB0_PSDVF_STD_DEV_POSITION_Y_INVALID	(8192)
	#endif
	#ifndef   EMB0_PSDVF_STD_DEV_POSITION_Z_INVALID
	  #define EMB0_PSDVF_STD_DEV_POSITION_Z_INVALID	(16384)
	#endif
	#ifndef   EMB0_PSDVF_STD_DEV_LENGTH_INVALID
	  #define EMB0_PSDVF_STD_DEV_LENGTH_INVALID	(32768)
	#endif
	#ifndef   EMB0_PSDVF_STD_DEV_WIDTH_INVALID
	  #define EMB0_PSDVF_STD_DEV_WIDTH_INVALID	(65536)
	#endif
	#ifndef   EMB0_PSDVF_STD_DEV_HEIGHT_INVALID
	  #define EMB0_PSDVF_STD_DEV_HEIGHT_INVALID	(131072)
	#endif
	#ifndef   EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_X_INVALID
	  #define EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_X_INVALID	(262144)
	#endif
	#ifndef   EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_Y_INVALID
	  #define EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_Y_INVALID	(524288)
	#endif
	#ifndef   EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_X_INVALID
	  #define EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_X_INVALID	(1048576)
	#endif
	#ifndef   EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_Y_INVALID
	  #define EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_Y_INVALID	(2097152)
	#endif
	#ifndef   EMB0_MSDVF_STD_DEV_ACCEL_YAW_ANGLE_INVALID
	  #define EMB0_MSDVF_STD_DEV_ACCEL_YAW_ANGLE_INVALID	(4194304)
	#endif
	#ifndef   EMB0_MSDVF_STD_DEV_ACCEL_YAW_SPEED_INVALID
	  #define EMB0_MSDVF_STD_DEV_ACCEL_YAW_SPEED_INVALID	(8388608)
	#endif
	#ifndef   EMB0_FLAGS_SNA
	  #define EMB0_FLAGS_SNA	(2147483648)
	#endif

/* typedef EMB0_t_ObjFlashLightStat */
	#ifndef   EMB0_OFS_STATUS_UNKNOWN
	  #define EMB0_OFS_STATUS_UNKNOWN	(0)
	#endif
	#ifndef   EMB0_OFS_NO_FLASHING
	  #define EMB0_OFS_NO_FLASHING	(1)
	#endif
	#ifndef   EMB0_OFS_FLASHING_LEFT
	  #define EMB0_OFS_FLASHING_LEFT	(2)
	#endif
	#ifndef   EMB0_OFS_FLASHING_RIGHT
	  #define EMB0_OFS_FLASHING_RIGHT	(3)
	#endif
	#ifndef   EMB0_OFS_HAZARD_FLASHING
	  #define EMB0_OFS_HAZARD_FLASHING	(4)
	#endif
	#ifndef   EMB0_OFS_SNA
	  #define EMB0_OFS_SNA	(255)
	#endif

/* typedef EMB0_t_ObjBrakeLightStat */
	#ifndef   EMB0_BLS_STATUS_UNKNOWN
	  #define EMB0_BLS_STATUS_UNKNOWN	(0)
	#endif
	#ifndef   EMB0_BLS_NO_BRAKING
	  #define EMB0_BLS_NO_BRAKING	(1)
	#endif
	#ifndef   EMB0_BLS_REGULAR_BRAKING
	  #define EMB0_BLS_REGULAR_BRAKING	(2)
	#endif
	#ifndef   EMB0_BLS_HEAVY_BREAKING
	  #define EMB0_BLS_HEAVY_BREAKING	(3)
	#endif
	#ifndef   EMB0_BLS_SNA
	  #define EMB0_BLS_SNA	(255)
	#endif

/* typedef EMB0_t_SensorSource */
	#ifndef   EMB0_OBJECT_LIST_SOURCE_NONE
	  #define EMB0_OBJECT_LIST_SOURCE_NONE	(0)
	#endif
	#ifndef   EMB0_OBJECT_LIST_SOURCE_LRR
	  #define EMB0_OBJECT_LIST_SOURCE_LRR	(1)
	#endif
	#ifndef   EMB0_OBJECT_LIST_SOURCE_MRR
	  #define EMB0_OBJECT_LIST_SOURCE_MRR	(2)
	#endif
	#ifndef   EMB0_OBJECT_LIST_SOURCE_SRR_FL
	  #define EMB0_OBJECT_LIST_SOURCE_SRR_FL	(3)
	#endif
	#ifndef   EMB0_OBJECT_LIST_SOURCE_SRR_FR
	  #define EMB0_OBJECT_LIST_SOURCE_SRR_FR	(4)
	#endif
	#ifndef   EMB0_OBJECT_LIST_SOURCE_SRR_RL
	  #define EMB0_OBJECT_LIST_SOURCE_SRR_RL	(5)
	#endif
	#ifndef   EMB0_OBJECT_LIST_SOURCE_SRR_RR
	  #define EMB0_OBJECT_LIST_SOURCE_SRR_RR	(6)
	#endif
	#ifndef   EMB0_OBJECT_LIST_SOURCE_SRL
	  #define EMB0_OBJECT_LIST_SOURCE_SRL	(7)
	#endif
	#ifndef   EMB0_OBJECT_LIST_SOURCE_MCAM
	  #define EMB0_OBJECT_LIST_SOURCE_MCAM	(8)
	#endif
	#ifndef   EMB0_OBJECT_LIST_SOURCE_SCAM
	  #define EMB0_OBJECT_LIST_SOURCE_SCAM	(9)
	#endif

/* typedef EMB0_t_Service */
	#ifndef   EMB0_QS_INIT
	  #define EMB0_QS_INIT	(0)
	#endif
	#ifndef   EMB0_QS_OK
	  #define EMB0_QS_OK	(1)
	#endif
	#ifndef   EMB0_QS_NOT_OK
	  #define EMB0_QS_NOT_OK	(2)
	#endif
	#ifndef   EMB0_QS_SNA
	  #define EMB0_QS_SNA	(255)
	#endif

/* typedef EM_t_CustomerProjectDef */
	#ifndef   EM_PRJ_MFC400
	  #define EM_PRJ_MFC400	(0)
	#endif
	#ifndef   EM_PRJ_SMFC4B0
	  #define EM_PRJ_SMFC4B0	(1)
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

/* typedef ePreDynWarning_t */
	#ifndef   ePreDynamicWarning_No
	  #define ePreDynamicWarning_No	(0)
	#endif
	#ifndef   ePreDynamicWarning_Moving
	  #define ePreDynamicWarning_Moving	(1)
	#endif
	#ifndef   ePreDynamicWarning_Standing
	  #define ePreDynamicWarning_Standing	(2)
	#endif
	#ifndef   ePreDynamicWarning_Halted
	  #define ePreDynamicWarning_Halted	(3)
	#endif

/* typedef eAcuteDynWarning_t */
	#ifndef   eAcuteDynamicWarning_No
	  #define eAcuteDynamicWarning_No	(0)
	#endif
	#ifndef   eAcuteDynamicWarning_Moving
	  #define eAcuteDynamicWarning_Moving	(1)
	#endif
	#ifndef   eAcuteDynamicWarning_Standing
	  #define eAcuteDynamicWarning_Standing	(2)
	#endif
	#ifndef   eAcuteDynamicWarning_Halted
	  #define eAcuteDynamicWarning_Halted	(3)
	#endif

/* typedef ePedWarning_t */
	#ifndef   ePedWarning_No
	  #define ePedWarning_No	(0)
	#endif
	#ifndef   ePedWarning_Moving
	  #define ePedWarning_Moving	(1)
	#endif
	#ifndef   ePedWarning_Standing
	  #define ePedWarning_Standing	(2)
	#endif
	#ifndef   ePedWarning_Halted
	  #define ePedWarning_Halted	(3)
	#endif

/* typedef eDistWarningDisplay_t */
	#ifndef   eDistWarningDisplay_No
	  #define eDistWarningDisplay_No	(0)
	#endif
	#ifndef   eDistWarningDisplay_Far
	  #define eDistWarningDisplay_Far	(1)
	#endif
	#ifndef   eDistWarningDisplay_Mid
	  #define eDistWarningDisplay_Mid	(2)
	#endif
	#ifndef   eDistWarningDisplay_Near
	  #define eDistWarningDisplay_Near	(3)
	#endif

/* typedef ePreCrashLevel_t */
	#ifndef   eCollision_No
	  #define eCollision_No	(0)
	#endif
	#ifndef   eCollision_RunUp
	  #define eCollision_RunUp	(1)
	#endif
	#ifndef   eCollision_Prob
	  #define eCollision_Prob	(2)
	#endif
	#ifndef   eCollision_Unavoidable
	  #define eCollision_Unavoidable	(3)
	#endif

/* typedef eFunctionQualifier_t */
	#ifndef   eAvailableOff
	  #define eAvailableOff	(0)
	#endif
	#ifndef   eAvailableOn
	  #define eAvailableOn	(1)
	#endif
	#ifndef   eUnavailableError
	  #define eUnavailableError	(2)
	#endif
	#ifndef   eUnavailableCoded
	  #define eUnavailableCoded	(3)
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
	#ifndef   eDriverFeedbackState_Negativ
	  #define eDriverFeedbackState_Negativ	(0)
	#endif
	#ifndef   eDriverFeedbackState_NoNegative
	  #define eDriverFeedbackState_NoNegative	(1)
	#endif
	#ifndef   eDriverFeedbackState_NoPositive
	  #define eDriverFeedbackState_NoPositive	(2)
	#endif
	#ifndef   eDriverFeedbackState_WeakPositive
	  #define eDriverFeedbackState_WeakPositive	(3)
	#endif
	#ifndef   eDriverFeedbackState_Positive
	  #define eDriverFeedbackState_Positive	(4)
	#endif
	#ifndef   eDriverFeedbackState_StrongPositive
	  #define eDriverFeedbackState_StrongPositive	(5)
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

/* typedef CodingParam_t */
	#ifndef   HEAD_CODING_STAT_OBJ
	  #define HEAD_CODING_STAT_OBJ	(1)
	#endif
	#ifndef   HEAD_CODING_LOW_SPEED
	  #define HEAD_CODING_LOW_SPEED	(2)
	#endif
	#ifndef   HEAD_CODING_COUNTRY
	  #define HEAD_CODING_COUNTRY	(4)
	#endif
	#ifndef   HEAD_CODING_IGN_SCHK
	  #define HEAD_CODING_IGN_SCHK	(8)
	#endif
	#ifndef   HEAD_CODING_NO_FAILUREHANDLING
	  #define HEAD_CODING_NO_FAILUREHANDLING	(16)
	#endif
	#ifndef   HEAD_CODING_DEBUGMESSAGES
	  #define HEAD_CODING_DEBUGMESSAGES	(32)
	#endif
	#ifndef   HEAD_CODING_DISTANCELIMIT
	  #define HEAD_CODING_DISTANCELIMIT	(64)
	#endif
	#ifndef   HEAD_CODING_IGNORE_ACT_SWITCH
	  #define HEAD_CODING_IGNORE_ACT_SWITCH	(128)
	#endif
	#ifndef   HEAD_CODING_VEHICLES_WARN
	  #define HEAD_CODING_VEHICLES_WARN	(256)
	#endif
	#ifndef   HEAD_CODING_VEHICLES_BRAKE
	  #define HEAD_CODING_VEHICLES_BRAKE	(512)
	#endif
	#ifndef   HEAD_CODING_PED_WARN
	  #define HEAD_CODING_PED_WARN	(1024)
	#endif
	#ifndef   HEAD_CODING_PED_BRAKE
	  #define HEAD_CODING_PED_BRAKE	(2048)
	#endif
	#ifndef   HEAD_CODING_OBJSTAT_WARN
	  #define HEAD_CODING_OBJSTAT_WARN	(4096)
	#endif
	#ifndef   HEAD_CODING_OBJSTAT_BRAKE
	  #define HEAD_CODING_OBJSTAT_BRAKE	(8192)
	#endif
	#ifndef   HEAD_CODING_OBJMOVE_WARN
	  #define HEAD_CODING_OBJMOVE_WARN	(16384)
	#endif
	#ifndef   HEAD_CODING_OBJMOVE_BRAKE
	  #define HEAD_CODING_OBJMOVE_BRAKE	(32768)
	#endif
	#ifndef   HEAD_CODING_PED_PRECRASH
	  #define HEAD_CODING_PED_PRECRASH	(65536)
	#endif
	#ifndef   HEAD_CODING_OBJMOVE_PRECRASH
	  #define HEAD_CODING_OBJMOVE_PRECRASH	(131072)
	#endif
	#ifndef   HEAD_CODING_OBJSTAT_PRECRASH
	  #define HEAD_CODING_OBJSTAT_PRECRASH	(262144)
	#endif
	#ifndef   HEAD_CODING_VCL_PRECRASH
	  #define HEAD_CODING_VCL_PRECRASH	(524288)
	#endif
	#ifndef   HEAD_CODING_MAX
	  #define HEAD_CODING_MAX	(2147483648)
	#endif

/* typedef FCTSubChainQualifier_t */
	#ifndef   eSystemOn
	  #define eSystemOn	(0)
	#endif
	#ifndef   eSystemOff
	  #define eSystemOff	(1)
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

/* typedef E_FCTIF_ALDWWrnMdRq_t */
	#ifndef   e_FCTIF_ALDW_MODE_1
	  #define e_FCTIF_ALDW_MODE_1	(0)
	#endif
	#ifndef   e_FCTIF_ALDW_MODE_2
	  #define e_FCTIF_ALDW_MODE_2	(1)
	#endif

/* typedef E_FCTIF_ALDWWarnSuppStat_t */
	#ifndef   e_FCTIF_ALDW_OFF_SPD
	  #define e_FCTIF_ALDW_OFF_SPD	(0)
	#endif
	#ifndef   e_FCTIF_ALDW_WARN_RDY
	  #define e_FCTIF_ALDW_WARN_RDY	(1)
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

/* typedef E_FCTIF_ALDWWarnVel_t */
	#ifndef   e_FCTIF_ALDW_VEL_OFF
	  #define e_FCTIF_ALDW_VEL_OFF	(0)
	#endif
	#ifndef   e_FCTIF_ALDW_VEL_ACTV
	  #define e_FCTIF_ALDW_VEL_ACTV	(1)
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

/* typedef eEBAObjectClass_t */
	#ifndef   EBAObjectClass_Unknown
	  #define EBAObjectClass_Unknown	(0)
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

/* typedef EBACodingParam_t */
	#ifndef   EBA_CODING_LOW_SPEED
	  #define EBA_CODING_LOW_SPEED	(1)
	#endif
	#ifndef   EBA_CODING_COUNTRY_A
	  #define EBA_CODING_COUNTRY_A	(2)
	#endif
	#ifndef   EBA_CODING_COUNTRY_B
	  #define EBA_CODING_COUNTRY_B	(4)
	#endif
	#ifndef   EBA_CODING_IGN_SCHK
	  #define EBA_CODING_IGN_SCHK	(8)
	#endif
	#ifndef   EBA_CODING_NO_FAILUREHANDLING
	  #define EBA_CODING_NO_FAILUREHANDLING	(16)
	#endif
	#ifndef   EBA_CODING_DEBUGMESSAGES
	  #define EBA_CODING_DEBUGMESSAGES	(32)
	#endif
	#ifndef   EBA_CODING_DISTANCELIMIT
	  #define EBA_CODING_DISTANCELIMIT	(64)
	#endif
	#ifndef   EBA_CODING_IGNORE_ACT_SWITCH
	  #define EBA_CODING_IGNORE_ACT_SWITCH	(128)
	#endif
	#ifndef   EBA_CODING_OBJSTAT_WARN
	  #define EBA_CODING_OBJSTAT_WARN	(256)
	#endif
	#ifndef   EBA_CODING_OBJSTAT_BRAKE
	  #define EBA_CODING_OBJSTAT_BRAKE	(512)
	#endif
	#ifndef   EBA_CODING_OBJSTAT_PRECRASH
	  #define EBA_CODING_OBJSTAT_PRECRASH	(1024)
	#endif
	#ifndef   EBA_CODING_OBJSTAT_PREFILL
	  #define EBA_CODING_OBJSTAT_PREFILL	(2048)
	#endif
	#ifndef   EBA_CODING_OBJSTAT_HBA
	  #define EBA_CODING_OBJSTAT_HBA	(4096)
	#endif
	#ifndef   EBA_CODING_OBJMOVE_WARN
	  #define EBA_CODING_OBJMOVE_WARN	(8192)
	#endif
	#ifndef   EBA_CODING_OBJMOVE_BRAKE
	  #define EBA_CODING_OBJMOVE_BRAKE	(16384)
	#endif
	#ifndef   EBA_CODING_OBJMOVE_PRECRASH
	  #define EBA_CODING_OBJMOVE_PRECRASH	(32768)
	#endif
	#ifndef   EBA_CODING_OBJMOVE_PREFILL
	  #define EBA_CODING_OBJMOVE_PREFILL	(65536)
	#endif
	#ifndef   EBA_CODING_OBJMOVE_HBA
	  #define EBA_CODING_OBJMOVE_HBA	(131072)
	#endif
	#ifndef   EBA_CODING_PED_WARN
	  #define EBA_CODING_PED_WARN	(262144)
	#endif
	#ifndef   EBA_CODING_PED_BRAKE
	  #define EBA_CODING_PED_BRAKE	(524288)
	#endif
	#ifndef   EBA_CODING_PED_PRECRASH
	  #define EBA_CODING_PED_PRECRASH	(1048576)
	#endif
	#ifndef   EBA_CODING_PED_PREFILL
	  #define EBA_CODING_PED_PREFILL	(2097152)
	#endif
	#ifndef   EBA_CODING_PED_HBA
	  #define EBA_CODING_PED_HBA	(4194304)
	#endif
	#ifndef   EBA_CODING_VEHICLES_WARN
	  #define EBA_CODING_VEHICLES_WARN	(8388608)
	#endif
	#ifndef   EBA_CODING_VEHICLES_BRAKE
	  #define EBA_CODING_VEHICLES_BRAKE	(16777216)
	#endif
	#ifndef   EBA_CODING_CROSSING_WARN
	  #define EBA_CODING_CROSSING_WARN	(33554432)
	#endif
	#ifndef   EBA_CODING_CROSSING_BRAKE
	  #define EBA_CODING_CROSSING_BRAKE	(67108864)
	#endif
	#ifndef   EBA_CODING_LATENT_WARN
	  #define EBA_CODING_LATENT_WARN	(134217728)
	#endif
	#ifndef   EBA_CODING_VCL_PRECRASH
	  #define EBA_CODING_VCL_PRECRASH	(268435456)
	#endif
	#ifndef   EBA_CODING_MAX
	  #define EBA_CODING_MAX	(2147483648)
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
	#ifndef   eFunctionSwitch_PedWarn
	  #define eFunctionSwitch_PedWarn	(1)
	#endif
	#ifndef   eFunctionSwitch_PedBrakePreCond
	  #define eFunctionSwitch_PedBrakePreCond	(2)
	#endif
	#ifndef   eFunctionSwitch_PedBrakeL1
	  #define eFunctionSwitch_PedBrakeL1	(4)
	#endif
	#ifndef   eFunctionSwitch_PedBrakeL2
	  #define eFunctionSwitch_PedBrakeL2	(8)
	#endif
	#ifndef   eFunctionSwitch_PedBrakeL3
	  #define eFunctionSwitch_PedBrakeL3	(16)
	#endif
	#ifndef   eFunctionSwitch_VehWarn
	  #define eFunctionSwitch_VehWarn	(32)
	#endif
	#ifndef   eFunctionSwitch_VehBrakePreCond
	  #define eFunctionSwitch_VehBrakePreCond	(64)
	#endif
	#ifndef   eFunctionSwitch_VehBrakeL1
	  #define eFunctionSwitch_VehBrakeL1	(128)
	#endif
	#ifndef   eFunctionSwitch_VehBrakeL2
	  #define eFunctionSwitch_VehBrakeL2	(256)
	#endif
	#ifndef   eFunctionSwitch_VehBrakeL3
	  #define eFunctionSwitch_VehBrakeL3	(512)
	#endif
	#ifndef   eFunctionSwitch_VehLatentWarn
	  #define eFunctionSwitch_VehLatentWarn	(1024)
	#endif
	#ifndef   eFunctionSwitch_UnknownWarn
	  #define eFunctionSwitch_UnknownWarn	(2048)
	#endif
	#ifndef   eFunctionSwitch_UnknownBrakePreCond
	  #define eFunctionSwitch_UnknownBrakePreCond	(4096)
	#endif
	#ifndef   eFunctionSwitch_UnknownBrakeL1
	  #define eFunctionSwitch_UnknownBrakeL1	(8192)
	#endif
	#ifndef   eFunctionSwitch_UnknownBrakeL2
	  #define eFunctionSwitch_UnknownBrakeL2	(16384)
	#endif
	#ifndef   eFunctionSwitch_UnknownBrakeL3
	  #define eFunctionSwitch_UnknownBrakeL3	(32768)
	#endif
	#ifndef   eFunctionSwitch_UnknownLatentWarn
	  #define eFunctionSwitch_UnknownLatentWarn	(65536)
	#endif
	#ifndef   eFunctionSwitch_MAX
	  #define eFunctionSwitch_MAX	(2147483648)
	#endif

/* typedef eObjectSwitch_t */
	#ifndef   eObjectSwitch_Pedestrians
	  #define eObjectSwitch_Pedestrians	(1)
	#endif
	#ifndef   eObjectSwitch_Vehicles
	  #define eObjectSwitch_Vehicles	(2)
	#endif
	#ifndef   eObjectSwitch_Unknown
	  #define eObjectSwitch_Unknown	(4)
	#endif
	#ifndef   eObjectSwitch_MAX
	  #define eObjectSwitch_MAX	(2147483648)
	#endif

/* typedef LKA_VELOCITY_UNIT_t */
	#ifndef   e_FCTIF_ALDW_VELOCITY_UNIT_KMH
	  #define e_FCTIF_ALDW_VELOCITY_UNIT_KMH	(0)
	#endif
	#ifndef   e_FCTIF_ALDW_VELOCITY_UNIT_MPH
	  #define e_FCTIF_ALDW_VELOCITY_UNIT_MPH	(1)
	#endif

/* typedef E_FCTIF_ALDWWarnShiftBound_t */
	#ifndef   e_FCTIF_ALDW_WARNING_SHIFT_BOUND_OFF
	  #define e_FCTIF_ALDW_WARNING_SHIFT_BOUND_OFF	(0)
	#endif
	#ifndef   e_FCTIF_ALDW_WARNING_SHIFT_BOUND_LEFT
	  #define e_FCTIF_ALDW_WARNING_SHIFT_BOUND_LEFT	(1)
	#endif
	#ifndef   e_FCTIF_ALDW_WARNING_SHIFT_BOUND_RIGHT
	  #define e_FCTIF_ALDW_WARNING_SHIFT_BOUND_RIGHT	(2)
	#endif
	#ifndef   e_FCTIF_ALDW_WARNING_SHIFT_BOUND_BOTH
	  #define e_FCTIF_ALDW_WARNING_SHIFT_BOUND_BOTH	(3)
	#endif

/* typedef E_FCTIF_ALDWRoadEdgeWarn_t */
	#ifndef   e_FCTIF_ALDW_ROAD_EDGE_WARNING_OFF
	  #define e_FCTIF_ALDW_ROAD_EDGE_WARNING_OFF	(0)
	#endif
	#ifndef   e_FCTIF_ALDW_ROAD_EDGE_WARNING_ON
	  #define e_FCTIF_ALDW_ROAD_EDGE_WARNING_ON	(1)
	#endif
	#ifndef   e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_GRASS
	  #define e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_GRASS	(2)
	#endif
	#ifndef   e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_SNOW
	  #define e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_SNOW	(3)
	#endif
	#ifndef   e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_CURBS
	  #define e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_CURBS	(4)
	#endif
	#ifndef   e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_RAISED
	  #define e_FCTIF_ALDW_ROAD_EDGE_WARNING_ONLY_RAISED	(5)
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
	#ifndef   FCT_MOD_SERVICEALIGNMENT
	  #define FCT_MOD_SERVICEALIGNMENT	(4)
	#endif
	#ifndef   FCT_MOD_END_OF_LINE
	  #define FCT_MOD_END_OF_LINE	(5)
	#endif
	#ifndef   FCT_MOD_MON_INPUT_ACC
	  #define FCT_MOD_MON_INPUT_ACC	(6)
	#endif
	#ifndef   FCT_MOD_REDUCED_FUNC
	  #define FCT_MOD_REDUCED_FUNC	(7)
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

/* typedef FexOpMode_t */
	#ifndef   FEX_OPMODE_IDLE
	  #define FEX_OPMODE_IDLE	(0)
	#endif
	#ifndef   FEX_OPMODE_RESET
	  #define FEX_OPMODE_RESET	(1)
	#endif
	#ifndef   FEX_OPMODE_RUN_INIT_FPGA
	  #define FEX_OPMODE_RUN_INIT_FPGA	(2)
	#endif
	#ifndef   FEX_OPMODE_RUN_STARTUP_TEST_FPGA
	  #define FEX_OPMODE_RUN_STARTUP_TEST_FPGA	(3)
	#endif
	#ifndef   FEX_OPMODE_RUN_CYCLIC_TEST_FPGA
	  #define FEX_OPMODE_RUN_CYCLIC_TEST_FPGA	(4)
	#endif
	#ifndef   FEX_OPMODE_RUN_SAC_DATA
	  #define FEX_OPMODE_RUN_SAC_DATA	(5)
	#endif
	#ifndef   FEX_OPMODE_RUN_PED_DATA
	  #define FEX_OPMODE_RUN_PED_DATA	(6)
	#endif
	#ifndef   FEX_OPMODE_MAX_RUNTIME
	  #define FEX_OPMODE_MAX_RUNTIME	(7)
	#endif
	#ifndef   FEX_OPMODE_DEMO
	  #define FEX_OPMODE_DEMO	(8)
	#endif

/* typedef eServiceQualifier_t */
	#ifndef   FSD_SERVICE_INIT
	  #define FSD_SERVICE_INIT	(0)
	#endif
	#ifndef   FSD_SERVICE_AVAILABLE
	  #define FSD_SERVICE_AVAILABLE	(1)
	#endif
	#ifndef   FSD_SERVICE_REDUCED
	  #define FSD_SERVICE_REDUCED	(2)
	#endif
	#ifndef   FSD_SERVICE_NOT_AVAILABLE
	  #define FSD_SERVICE_NOT_AVAILABLE	(3)
	#endif

/* typedef eStatus_t */
	#ifndef   FSD_MEAS
	  #define FSD_MEAS	(0)
	#endif
	#ifndef   FSD_MEAS_UP_VISIBILITY
	  #define FSD_MEAS_UP_VISIBILITY	(1)
	#endif
	#ifndef   FSD_HYPOTHESIS
	  #define FSD_HYPOTHESIS	(2)
	#endif
	#ifndef   FSD_MEAS_NOT_AVAILABLE
	  #define FSD_MEAS_NOT_AVAILABLE	(3)
	#endif

/* typedef eDynamicState_t */
	#ifndef   FSD_STATIC
	  #define FSD_STATIC	(0)
	#endif
	#ifndef   FSD_MOVING
	  #define FSD_MOVING	(1)
	#endif

/* typedef eValidFlags_t */
	#ifndef   FSD_VALIDFLAG_MINDIST
	  #define FSD_VALIDFLAG_MINDIST	(1)
	#endif
	#ifndef   FSD_VALIDFLAG_HEIGHTTOP
	  #define FSD_VALIDFLAG_HEIGHTTOP	(2)
	#endif
	#ifndef   FSD_VALIDFLAG_MINDIST_STD
	  #define FSD_VALIDFLAG_MINDIST_STD	(4)
	#endif
	#ifndef   FSD_VALIDFLAG_EXPROB
	  #define FSD_VALIDFLAG_EXPROB	(8)
	#endif
	#ifndef   FSD_VALIDFLAG_DYNSTATE
	  #define FSD_VALIDFLAG_DYNSTATE	(22)
	#endif

/* typedef eClusterType_t */
	#ifndef   GEN_CLUSTER_TYPE_UNDEFINED
	  #define GEN_CLUSTER_TYPE_UNDEFINED	(0)
	#endif
	#ifndef   GEN_CLUSTER_TYPE_GEOMETRIC
	  #define GEN_CLUSTER_TYPE_GEOMETRIC	(1)
	#endif
	#ifndef   GEN_CLUSTER_TYPE_FLOW
	  #define GEN_CLUSTER_TYPE_FLOW	(2)
	#endif

/* typedef RTE_HLAR_TrafficStyleLearningState */
	#ifndef   RTE_HLAR_TRAFFIC_LEARN_UNKNOWN
	  #define RTE_HLAR_TRAFFIC_LEARN_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_LEARN_0
	  #define RTE_HLAR_TRAFFIC_LEARN_0	(1)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_LEARN_RHD_1
	  #define RTE_HLAR_TRAFFIC_LEARN_RHD_1	(2)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_LEARN_RHD_2
	  #define RTE_HLAR_TRAFFIC_LEARN_RHD_2	(3)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_LEARN_RHD_3
	  #define RTE_HLAR_TRAFFIC_LEARN_RHD_3	(4)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_LEARN_LHD_1
	  #define RTE_HLAR_TRAFFIC_LEARN_LHD_1	(5)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_LEARN_LHD_2
	  #define RTE_HLAR_TRAFFIC_LEARN_LHD_2	(6)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_LEARN_LHD_3
	  #define RTE_HLAR_TRAFFIC_LEARN_LHD_3	(7)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_LEARN_INVALID
	  #define RTE_HLAR_TRAFFIC_LEARN_INVALID	(255)
	#endif

/* typedef RTE_HLAR_DefectPixelType */
	#ifndef   RTE_HLAR_DEFECT_PIXEL_UNKNOWN
	  #define RTE_HLAR_DEFECT_PIXEL_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_DEFECT_PIXEL_PIX_OK
	  #define RTE_HLAR_DEFECT_PIXEL_PIX_OK	(1)
	#endif
	#ifndef   RTE_HLAR_DEFECT_PIXEL_RED_HOT_PIX
	  #define RTE_HLAR_DEFECT_PIXEL_RED_HOT_PIX	(2)
	#endif
	#ifndef   RTE_HLAR_DEFECT_PIXEL_DYN_HOT_PIX
	  #define RTE_HLAR_DEFECT_PIXEL_DYN_HOT_PIX	(3)
	#endif
	#ifndef   RTE_HLAR_DEFECT_PIXEL_DRK_PIX
	  #define RTE_HLAR_DEFECT_PIXEL_DRK_PIX	(4)
	#endif
	#ifndef   RTE_HLAR_DEFECT_PIXEL_INVALID
	  #define RTE_HLAR_DEFECT_PIXEL_INVALID	(255)
	#endif

/* typedef RTE_HLA_Type */
	#ifndef   RTE_HLA_TYPE_UNKNOWN
	  #define RTE_HLA_TYPE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_TYPE_NAVL
	  #define RTE_HLA_TYPE_NAVL	(1)
	#endif
	#ifndef   RTE_HLA_TYPE_LIGHT
	  #define RTE_HLA_TYPE_LIGHT	(2)
	#endif
	#ifndef   RTE_HLA_TYPE_STANDARD
	  #define RTE_HLA_TYPE_STANDARD	(3)
	#endif
	#ifndef   RTE_HLA_TYPE_PLUS
	  #define RTE_HLA_TYPE_PLUS	(4)
	#endif
	#ifndef   RTE_HLA_TYPE_MATRIX
	  #define RTE_HLA_TYPE_MATRIX	(5)
	#endif
	#ifndef   RTE_HLA_TYPE_INVALID
	  #define RTE_HLA_TYPE_INVALID	(255)
	#endif

/* typedef RTE_HLA_State */
	#ifndef   RTE_HLA_STATE_UNKNOWN
	  #define RTE_HLA_STATE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_STATE_NAVL
	  #define RTE_HLA_STATE_NAVL	(1)
	#endif
	#ifndef   RTE_HLA_STATE_IDLE
	  #define RTE_HLA_STATE_IDLE	(2)
	#endif
	#ifndef   RTE_HLA_STATE_ACTV
	  #define RTE_HLA_STATE_ACTV	(3)
	#endif
	#ifndef   RTE_HLA_STATE_FAULT
	  #define RTE_HLA_STATE_FAULT	(4)
	#endif
	#ifndef   RTE_HLA_STATE_INVALID
	  #define RTE_HLA_STATE_INVALID	(255)
	#endif

/* typedef RTE_HLA_TrafficStyle */
	#ifndef   RTE_HLA_TRAFFIC_STYLE_UNKNOWN
	  #define RTE_HLA_TRAFFIC_STYLE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_TRAFFIC_STYLE_RHD
	  #define RTE_HLA_TRAFFIC_STYLE_RHD	(1)
	#endif
	#ifndef   RTE_HLA_TRAFFIC_STYLE_LHD
	  #define RTE_HLA_TRAFFIC_STYLE_LHD	(2)
	#endif
	#ifndef   RTE_HLA_TRAFFIC_STYLE_INVALID
	  #define RTE_HLA_TRAFFIC_STYLE_INVALID	(255)
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

/* typedef RTE_HLAF_SpeedState */
	#ifndef   RTE_HLAF_SPEEDSTATE_UNKNOWN
	  #define RTE_HLAF_SPEEDSTATE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_SPEEDSTATE_LOW
	  #define RTE_HLAF_SPEEDSTATE_LOW	(1)
	#endif
	#ifndef   RTE_HLAF_SPEEDSTATE_HIGH
	  #define RTE_HLAF_SPEEDSTATE_HIGH	(2)
	#endif
	#ifndef   RTE_HLAF_SPEEDSTATE_INVALID
	  #define RTE_HLAF_SPEEDSTATE_INVALID	(255)
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
	#ifndef   RTE_HLAF_TURNOFFREASON_LOW_SPEED
	  #define RTE_HLAF_TURNOFFREASON_LOW_SPEED	(4)
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
	#ifndef   RTE_HLAF_TURNOFFREASON_INVALID
	  #define RTE_HLAF_TURNOFFREASON_INVALID	(4294967295)
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

/* typedef RTE_HLAF_LightOutput */
	#ifndef   RTE_HLAF_LIGHTOUTPUT_UNKNOWN
	  #define RTE_HLAF_LIGHTOUTPUT_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_LIGHTOUTPUT_STD
	  #define RTE_HLAF_LIGHTOUTPUT_STD	(1)
	#endif
	#ifndef   RTE_HLAF_LIGHTOUTPUT_MIN
	  #define RTE_HLAF_LIGHTOUTPUT_MIN	(2)
	#endif
	#ifndef   RTE_HLAF_LIGHTOUTPUT_MAX
	  #define RTE_HLAF_LIGHTOUTPUT_MAX	(3)
	#endif
	#ifndef   RTE_HLAF_LIGHTOUTPUT_INVALID
	  #define RTE_HLAF_LIGHTOUTPUT_INVALID	(255)
	#endif

/* typedef RTE_HLAF_EcoLight_eAvailabilityState */
	#ifndef   RTE_HLAF_ECOLIGHT_AVST_UNKNOWN
	  #define RTE_HLAF_ECOLIGHT_AVST_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_AVST_AVAILABLE
	  #define RTE_HLAF_ECOLIGHT_AVST_AVAILABLE	(1)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_AVST_LIMITED
	  #define RTE_HLAF_ECOLIGHT_AVST_LIMITED	(2)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_AVST_ERROR
	  #define RTE_HLAF_ECOLIGHT_AVST_ERROR	(3)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_AVST_INVALID
	  #define RTE_HLAF_ECOLIGHT_AVST_INVALID	(255)
	#endif

/* typedef RTE_HLAF_EcoLight_eDetectionState */
	#ifndef   RTE_HLAF_ECOLIGHT_DETST_UNKNOWN
	  #define RTE_HLAF_ECOLIGHT_DETST_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_DETST_NEW_DTCD
	  #define RTE_HLAF_ECOLIGHT_DETST_NEW_DTCD	(1)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_DETST_DTCD
	  #define RTE_HLAF_ECOLIGHT_DETST_DTCD	(2)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_DETST_ESTIM
	  #define RTE_HLAF_ECOLIGHT_DETST_ESTIM	(3)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_DETST_NAVL
	  #define RTE_HLAF_ECOLIGHT_DETST_NAVL	(4)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_DETST_ERROR
	  #define RTE_HLAF_ECOLIGHT_DETST_ERROR	(5)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_DETST_INVALID
	  #define RTE_HLAF_ECOLIGHT_DETST_INVALID	(255)
	#endif

/* typedef RTE_HLAF_EcoLight_eVehicleType */
	#ifndef   RTE_HLAF_ECOLIGHT_VEHTYPE_UNKNOWN
	  #define RTE_HLAF_ECOLIGHT_VEHTYPE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_VEHTYPE_SINGLETRACK
	  #define RTE_HLAF_ECOLIGHT_VEHTYPE_SINGLETRACK	(1)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_VEHTYPE_TWOTRACK
	  #define RTE_HLAF_ECOLIGHT_VEHTYPE_TWOTRACK	(2)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_VEHTYPE_INVALID
	  #define RTE_HLAF_ECOLIGHT_VEHTYPE_INVALID	(255)
	#endif

/* typedef RTE_HLAF_EcoLight_eVehicleLight */
	#ifndef   RTE_HLAF_ECOLIGHT_VEHLIGHT_UNKNOWN
	  #define RTE_HLAF_ECOLIGHT_VEHLIGHT_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_VEHLIGHT_ON
	  #define RTE_HLAF_ECOLIGHT_VEHLIGHT_ON	(1)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_VEHLIGHT_OFF
	  #define RTE_HLAF_ECOLIGHT_VEHLIGHT_OFF	(2)
	#endif
	#ifndef   RTE_HLAF_ECOLIGHT_VEHLIGHT_INVALID
	  #define RTE_HLAF_ECOLIGHT_VEHLIGHT_INVALID	(255)
	#endif

/* typedef RTE_HLA_US_Sens */
	#ifndef   RTE_HLA_US_SENS_UNKNOWN
	  #define RTE_HLA_US_SENS_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_US_SENS_OFF
	  #define RTE_HLA_US_SENS_OFF	(1)
	#endif
	#ifndef   RTE_HLA_US_SENS_ON
	  #define RTE_HLA_US_SENS_ON	(2)
	#endif
	#ifndef   RTE_HLA_US_SENS_INVALID
	  #define RTE_HLA_US_SENS_INVALID	(255)
	#endif

/* typedef RTE_HLA_BlockageManualOverwrite */
	#ifndef   RTE_HLA_BLOCKMANOW_UNKNOWN
	  #define RTE_HLA_BLOCKMANOW_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_BLOCKMANOW_INACTIVE
	  #define RTE_HLA_BLOCKMANOW_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_BLOCKMANOW_ACTIVE
	  #define RTE_HLA_BLOCKMANOW_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_BLOCKMANOW_INVALID
	  #define RTE_HLA_BLOCKMANOW_INVALID	(255)
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

/* typedef RTE_HLA_LightModuleState */
	#ifndef   RTE_HLA_LTM_UNKNOWN
	  #define RTE_HLA_LTM_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_LTM_NAVL
	  #define RTE_HLA_LTM_NAVL	(1)
	#endif
	#ifndef   RTE_HLA_LTM_IDLE
	  #define RTE_HLA_LTM_IDLE	(2)
	#endif
	#ifndef   RTE_HLA_LTM_FAULT
	  #define RTE_HLA_LTM_FAULT	(3)
	#endif
	#ifndef   RTE_HLA_LTM_DEACT
	  #define RTE_HLA_LTM_DEACT	(4)
	#endif
	#ifndef   RTE_HLA_LTM_INVALID
	  #define RTE_HLA_LTM_INVALID	(255)
	#endif

/* typedef RTE_HLA_GlareReductionState */
	#ifndef   RTE_HLA_GR_UNKNOWN
	  #define RTE_HLA_GR_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_GR_INACTIVE
	  #define RTE_HLA_GR_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_GR_ACTIVE
	  #define RTE_HLA_GR_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_GR_INVALID
	  #define RTE_HLA_GR_INVALID	(255)
	#endif

/* typedef RTE_HLA_CutOffLineState */
	#ifndef   RTE_HLA_CUTOFFLINE_UNKNOWN
	  #define RTE_HLA_CUTOFFLINE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_CUTOFFLINE_INACTIVE
	  #define RTE_HLA_CUTOFFLINE_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_CUTOFFLINE_ACTIVE
	  #define RTE_HLA_CUTOFFLINE_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_CUTOFFLINE_INVALID
	  #define RTE_HLA_CUTOFFLINE_INVALID	(255)
	#endif

/* typedef RTE_HLA_LightStyle */
	#ifndef   RTE_HLA_LIGHTSTYLE_UNKNOWN
	  #define RTE_HLA_LIGHTSTYLE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_LIGHTSTYLE_SYMM
	  #define RTE_HLA_LIGHTSTYLE_SYMM	(1)
	#endif
	#ifndef   RTE_HLA_LIGHTSTYLE_COUNTRY
	  #define RTE_HLA_LIGHTSTYLE_COUNTRY	(2)
	#endif
	#ifndef   RTE_HLA_LIGHTSTYLE_MOTORWAY
	  #define RTE_HLA_LIGHTSTYLE_MOTORWAY	(3)
	#endif
	#ifndef   RTE_HLA_LIGHTSTYLE_PART_HB
	  #define RTE_HLA_LIGHTSTYLE_PART_HB	(4)
	#endif
	#ifndef   RTE_HLA_LIGHTSTYLE_FULL_HB
	  #define RTE_HLA_LIGHTSTYLE_FULL_HB	(5)
	#endif
	#ifndef   RTE_HLA_LIGHTSTYLE_SPOT
	  #define RTE_HLA_LIGHTSTYLE_SPOT	(6)
	#endif
	#ifndef   RTE_HLA_LIGHTSTYLE_INVALID
	  #define RTE_HLA_LIGHTSTYLE_INVALID	(255)
	#endif

/* typedef RTE_HLAR_ObjectStatus */
	#ifndef   RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_ONC_1ST
	  #define RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_ONC_1ST	(1)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_PREC_1ST
	  #define RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_PREC_1ST	(2)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_ONC_2ND
	  #define RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_ONC_2ND	(4)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_PREC_2ND
	  #define RTE_HLAR_OBJ_STA_IS_POTENTIAL_VEH_PREC_2ND	(8)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_VEH_ONC
	  #define RTE_HLAR_OBJ_STA_IS_VEH_ONC	(16)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_VEH_PREC
	  #define RTE_HLAR_OBJ_STA_IS_VEH_PREC	(32)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_TOO_BRIGHT
	  #define RTE_HLAR_OBJ_STA_IS_TOO_BRIGHT	(64)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_RED
	  #define RTE_HLAR_OBJ_STA_IS_RED	(128)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_PULSED_LIGHT
	  #define RTE_HLAR_OBJ_STA_IS_PULSED_LIGHT	(256)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_RED2
	  #define RTE_HLAR_OBJ_STA_IS_RED2	(512)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_MOVING_WHITE
	  #define RTE_HLAR_OBJ_STA_IS_MOVING_WHITE	(1024)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_MOVING_NON_WHITE
	  #define RTE_HLAR_OBJ_STA_IS_MOVING_NON_WHITE	(2048)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_ONC_PAIR
	  #define RTE_HLAR_OBJ_STA_IS_ONC_PAIR	(4096)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_POT_VEH_HIGH_PROB
	  #define RTE_HLAR_OBJ_STA_IS_POT_VEH_HIGH_PROB	(8192)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_BIT14
	  #define RTE_HLAR_OBJ_STA_BIT14	(16384)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_BIT15
	  #define RTE_HLAR_OBJ_STA_BIT15	(32768)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_STREET_LAMP
	  #define RTE_HLAR_OBJ_STA_IS_STREET_LAMP	(65536)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_ABOVE_ROI
	  #define RTE_HLAR_OBJ_STA_IS_ABOVE_ROI	(131072)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_INFINITE
	  #define RTE_HLAR_OBJ_STA_IS_INFINITE	(262144)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_3D_CORRECT
	  #define RTE_HLAR_OBJ_STA_IS_3D_CORRECT	(524288)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_CHAIN_OF_LIGHT
	  #define RTE_HLAR_OBJ_STA_IS_CHAIN_OF_LIGHT	(1048576)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_BRIGHT_OBJECT
	  #define RTE_HLAR_OBJ_STA_IS_BRIGHT_OBJECT	(2097152)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_BIT22
	  #define RTE_HLAR_OBJ_STA_BIT22	(4194304)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_BIT23
	  #define RTE_HLAR_OBJ_STA_BIT23	(8388608)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_TRACKED_IN_PAIR
	  #define RTE_HLAR_OBJ_STA_IS_TRACKED_IN_PAIR	(16777216)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_WILL_BE_REMOVED
	  #define RTE_HLAR_OBJ_STA_WILL_BE_REMOVED	(33554432)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_IS_ONE2ONE_ASS
	  #define RTE_HLAR_OBJ_STA_IS_ONE2ONE_ASS	(67108864)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_TRACKER_CLASS_STATIC
	  #define RTE_HLAR_OBJ_STA_TRACKER_CLASS_STATIC	(134217728)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_TRACKER_CLASS_DYNAMIC
	  #define RTE_HLAR_OBJ_STA_TRACKER_CLASS_DYNAMIC	(268435456)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_BIT29
	  #define RTE_HLAR_OBJ_STA_BIT29	(536870912)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_BIT30
	  #define RTE_HLAR_OBJ_STA_BIT30	(1073741824)
	#endif
	#ifndef   RTE_HLAR_OBJ_STA_BIT31
	  #define RTE_HLAR_OBJ_STA_BIT31	(2147483648)
	#endif

/* typedef RTE_HLAR_ObjectIconStatus */
	#ifndef   RTE_HLAR_OBJ_ICON_STA_LED_DET_CALLED
	  #define RTE_HLAR_OBJ_ICON_STA_LED_DET_CALLED	(1)
	#endif
	#ifndef   RTE_HLAR_OBJ_ICON_STA_STREETLAMP_DET_CALLED
	  #define RTE_HLAR_OBJ_ICON_STA_STREETLAMP_DET_CALLED	(2)
	#endif
	#ifndef   RTE_HLAR_OBJ_ICON_STA_REDLIGHT_DET_CALLED
	  #define RTE_HLAR_OBJ_ICON_STA_REDLIGHT_DET_CALLED	(4)
	#endif
	#ifndef   RTE_HLAR_OBJ_ICON_STA_SKIPPED_BAD_POS
	  #define RTE_HLAR_OBJ_ICON_STA_SKIPPED_BAD_POS	(8)
	#endif
	#ifndef   RTE_HLAR_OBJ_ICON_STA_BIT4
	  #define RTE_HLAR_OBJ_ICON_STA_BIT4	(16)
	#endif
	#ifndef   RTE_HLAR_OBJ_ICON_STA_BIT5
	  #define RTE_HLAR_OBJ_ICON_STA_BIT5	(32)
	#endif
	#ifndef   RTE_HLAR_OBJ_ICON_STA_BIT6
	  #define RTE_HLAR_OBJ_ICON_STA_BIT6	(64)
	#endif
	#ifndef   RTE_HLAR_OBJ_ICON_STA_BIT7
	  #define RTE_HLAR_OBJ_ICON_STA_BIT7	(128)
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
	#ifndef   RTE_HLA_TESTMODE_SEG_AUTOTHRES_OFF
	  #define RTE_HLA_TESTMODE_SEG_AUTOTHRES_OFF	(4)
	#endif
	#ifndef   RTE_HLA_TESTMODE_SEG_ALWAYS_ON
	  #define RTE_HLA_TESTMODE_SEG_ALWAYS_ON	(5)
	#endif
	#ifndef   RTE_HLA_TESTMODE_NO_CLEARMEAS
	  #define RTE_HLA_TESTMODE_NO_CLEARMEAS	(6)
	#endif
	#ifndef   RTE_HLA_TESTMODE_TEST_IMAGE
	  #define RTE_HLA_TESTMODE_TEST_IMAGE	(7)
	#endif
	#ifndef   RTE_HLA_TESTMODE_LAB
	  #define RTE_HLA_TESTMODE_LAB	(8)
	#endif
	#ifndef   RTE_HLA_TESTMODE_1
	  #define RTE_HLA_TESTMODE_1	(9)
	#endif
	#ifndef   RTE_HLA_TESTMODE_2
	  #define RTE_HLA_TESTMODE_2	(10)
	#endif
	#ifndef   RTE_HLA_TESTMODE_3
	  #define RTE_HLA_TESTMODE_3	(11)
	#endif
	#ifndef   RTE_HLA_TESTMODE_4
	  #define RTE_HLA_TESTMODE_4	(12)
	#endif
	#ifndef   RTE_HLA_TESTMODE_INVALID
	  #define RTE_HLA_TESTMODE_INVALID	(255)
	#endif

/* typedef RTE_HLA_CityDetection */
	#ifndef   RTE_HLA_CITYDET_UNKNOWN
	  #define RTE_HLA_CITYDET_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_CITYDET_INACTIVE
	  #define RTE_HLA_CITYDET_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_CITYDET_ACTIVE
	  #define RTE_HLA_CITYDET_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_CITYDET_INVALID
	  #define RTE_HLA_CITYDET_INVALID	(255)
	#endif

/* typedef RTE_HLA_TunnelDetection */
	#ifndef   RTE_HLA_TUNNELDET_UNKNOWN
	  #define RTE_HLA_TUNNELDET_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_TUNNELDET_INACTIVE
	  #define RTE_HLA_TUNNELDET_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_TUNNELDET_ACTIVE
	  #define RTE_HLA_TUNNELDET_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_TUNNELDET_INVALID
	  #define RTE_HLA_TUNNELDET_INVALID	(255)
	#endif

/* typedef RTE_HLA_BadPixelDetection */
	#ifndef   RTE_HLA_BADPIXELDET_UNKNOWN
	  #define RTE_HLA_BADPIXELDET_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_BADPIXELDET_INACTIVE
	  #define RTE_HLA_BADPIXELDET_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_BADPIXELDET_ACTIVE
	  #define RTE_HLA_BADPIXELDET_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_BADPIXELDET_INVALID
	  #define RTE_HLA_BADPIXELDET_INVALID	(255)
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

/* typedef RTE_HLA_BlockageDetection */
	#ifndef   RTE_HLA_BLOCKDET_UNKNOWN
	  #define RTE_HLA_BLOCKDET_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_BLOCKDET_INACTIVE
	  #define RTE_HLA_BLOCKDET_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_BLOCKDET_ACTIVE
	  #define RTE_HLA_BLOCKDET_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_BLOCKDET_INVALID
	  #define RTE_HLA_BLOCKDET_INVALID	(255)
	#endif

/* typedef RTE_HLA_HeadlightType */
	#ifndef   RTE_HLA_LTYPE_UNKNOWN
	  #define RTE_HLA_LTYPE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_LTYPE_HALOGENE
	  #define RTE_HLA_LTYPE_HALOGENE	(1)
	#endif
	#ifndef   RTE_HLA_LTYPE_XENON
	  #define RTE_HLA_LTYPE_XENON	(2)
	#endif
	#ifndef   RTE_HLA_LTYPE_LED
	  #define RTE_HLA_LTYPE_LED	(3)
	#endif
	#ifndef   RTE_HLA_LTYPE_PIXEL
	  #define RTE_HLA_LTYPE_PIXEL	(4)
	#endif
	#ifndef   RTE_HLA_LTYPE_LASER
	  #define RTE_HLA_LTYPE_LASER	(5)
	#endif
	#ifndef   RTE_HLA_LTYPE_INVALID
	  #define RTE_HLA_LTYPE_INVALID	(255)
	#endif

/* typedef RTE_HLA_HeadLightMechanics */
	#ifndef   RTE_HLA_LMECH_UNKNOWN
	  #define RTE_HLA_LMECH_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_LMECH_ROLLER
	  #define RTE_HLA_LMECH_ROLLER	(1)
	#endif
	#ifndef   RTE_HLA_LMECH_APERTURE
	  #define RTE_HLA_LMECH_APERTURE	(2)
	#endif
	#ifndef   RTE_HLA_LMECH_NONE
	  #define RTE_HLA_LMECH_NONE	(3)
	#endif
	#ifndef   RTE_HLA_LMECH_INVALID
	  #define RTE_HLA_LMECH_INVALID	(255)
	#endif

/* typedef RTE_HLA_SpotLight */
	#ifndef   RTE_HLA_SPOTLIGHT_UNKNOWN
	  #define RTE_HLA_SPOTLIGHT_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_SPOTLIGHT_AVL
	  #define RTE_HLA_SPOTLIGHT_AVL	(1)
	#endif
	#ifndef   RTE_HLA_SPOTLIGHT_NAVL
	  #define RTE_HLA_SPOTLIGHT_NAVL	(2)
	#endif
	#ifndef   RTE_HLA_SPOTLIGHT_INVALID
	  #define RTE_HLA_SPOTLIGHT_INVALID	(255)
	#endif

/* typedef RTE_HLA_WindshieldType */
	#ifndef   RTE_HLA_WTYPE_UNKNOWN
	  #define RTE_HLA_WTYPE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_WTYPE_CLEAR1
	  #define RTE_HLA_WTYPE_CLEAR1	(1)
	#endif
	#ifndef   RTE_HLA_WTYPE_CLEAR2
	  #define RTE_HLA_WTYPE_CLEAR2	(2)
	#endif
	#ifndef   RTE_HLA_WTYPE_GREEN
	  #define RTE_HLA_WTYPE_GREEN	(3)
	#endif
	#ifndef   RTE_HLA_WTYPE_BLUE
	  #define RTE_HLA_WTYPE_BLUE	(4)
	#endif
	#ifndef   RTE_HLA_WTYPE_BULLETPROOF
	  #define RTE_HLA_WTYPE_BULLETPROOF	(5)
	#endif
	#ifndef   RTE_HLA_WTYPE_INVALID
	  #define RTE_HLA_WTYPE_INVALID	(255)
	#endif

/* typedef RTE_HLA_MultipleReflectors */
	#ifndef   RTE_HLA_MREFL_UNKNOWN
	  #define RTE_HLA_MREFL_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_MREFL_INACTIVE
	  #define RTE_HLA_MREFL_INACTIVE	(1)
	#endif
	#ifndef   RTE_HLA_MREFL_ACTIVE
	  #define RTE_HLA_MREFL_ACTIVE	(2)
	#endif
	#ifndef   RTE_HLA_MREFL_INVALID
	  #define RTE_HLA_MREFL_INVALID	(255)
	#endif

/* typedef RTE_HLA_CountryCode */
	#ifndef   RTE_HLA_COUNTRY_CODE_UNKNOWN
	  #define RTE_HLA_COUNTRY_CODE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLA_COUNTRY_CODE_NORMAL
	  #define RTE_HLA_COUNTRY_CODE_NORMAL	(1)
	#endif
	#ifndef   RTE_HLA_COUNTRY_CODE_JP
	  #define RTE_HLA_COUNTRY_CODE_JP	(2)
	#endif
	#ifndef   RTE_HLA_COUNTRY_CODE_INVALID
	  #define RTE_HLA_COUNTRY_CODE_INVALID	(255)
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

/* typedef RTE_HLAR_TrafficStyleState */
	#ifndef   RTE_HLAR_TRAFFIC_STATE_UNKNOWN
	  #define RTE_HLAR_TRAFFIC_STATE_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_STATE_SCN
	  #define RTE_HLAR_TRAFFIC_STATE_SCN	(1)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_STATE_LEARN
	  #define RTE_HLAR_TRAFFIC_STATE_LEARN	(2)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_STATE_LAST_LEARNED
	  #define RTE_HLAR_TRAFFIC_STATE_LAST_LEARNED	(3)
	#endif
	#ifndef   RTE_HLAR_TRAFFIC_STATE_INVALID
	  #define RTE_HLAR_TRAFFIC_STATE_INVALID	(255)
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

/* typedef RTE_HLAR_RedReflectorArea */
	#ifndef   RTE_HLAR_RED_REFLECTOR_AREA_UNKNOWN
	  #define RTE_HLAR_RED_REFLECTOR_AREA_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_RED_REFLECTOR_AREA_NOT_DTCD
	  #define RTE_HLAR_RED_REFLECTOR_AREA_NOT_DTCD	(1)
	#endif
	#ifndef   RTE_HLAR_RED_REFLECTOR_AREA_DTCD
	  #define RTE_HLAR_RED_REFLECTOR_AREA_DTCD	(2)
	#endif
	#ifndef   RTE_HLAR_RED_REFLECTOR_AREA_INVALID
	  #define RTE_HLAR_RED_REFLECTOR_AREA_INVALID	(255)
	#endif

/* typedef RTE_HLAR_HighwayLatPosState */
	#ifndef   RTE_HLAR_HIGHWAY_LP_UNKNOWN
	  #define RTE_HLAR_HIGHWAY_LP_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_LP_NOT_DTCD
	  #define RTE_HLAR_HIGHWAY_LP_NOT_DTCD	(1)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_LP_DTCD
	  #define RTE_HLAR_HIGHWAY_LP_DTCD	(2)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_LP_INVALID
	  #define RTE_HLAR_HIGHWAY_LP_INVALID	(255)
	#endif

/* typedef RTE_HLAR_HighwayEgoMotionState */
	#ifndef   RTE_HLAR_HIGHWAY_EM_UNKNOWN
	  #define RTE_HLAR_HIGHWAY_EM_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_EM_NOT_DTCD
	  #define RTE_HLAR_HIGHWAY_EM_NOT_DTCD	(1)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_EM_DTCD
	  #define RTE_HLAR_HIGHWAY_EM_DTCD	(2)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_EM_LOW_SPEED
	  #define RTE_HLAR_HIGHWAY_EM_LOW_SPEED	(3)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_EM_INVALID
	  #define RTE_HLAR_HIGHWAY_EM_INVALID	(255)
	#endif

/* typedef RTE_HLAR_eHighwayOcclusionState */
	#ifndef   RTE_HLAR_HIGHWAY_OC_UNKNOWN
	  #define RTE_HLAR_HIGHWAY_OC_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_OC_NOT_DTCD
	  #define RTE_HLAR_HIGHWAY_OC_NOT_DTCD	(1)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_OC_DTCD
	  #define RTE_HLAR_HIGHWAY_OC_DTCD	(2)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_OC_INVALID
	  #define RTE_HLAR_HIGHWAY_OC_INVALID	(255)
	#endif

/* typedef RTE_HLAR_eHighwaySpeedDetectionState */
	#ifndef   RTE_HLAR_HIGHWAY_SP_UNKNOWN
	  #define RTE_HLAR_HIGHWAY_SP_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_SP_NOT_DTCD
	  #define RTE_HLAR_HIGHWAY_SP_NOT_DTCD	(1)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_SP_DTCD
	  #define RTE_HLAR_HIGHWAY_SP_DTCD	(2)
	#endif
	#ifndef   RTE_HLAR_HIGHWAY_SP_INVALID
	  #define RTE_HLAR_HIGHWAY_SP_INVALID	(255)
	#endif

/* typedef RTE_HLAF_NightViewObjectType */
	#ifndef   RTE_HLAF_NV_OBJ_UNKNOWN
	  #define RTE_HLAF_NV_OBJ_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_NV_OBJ_NO_OBJ
	  #define RTE_HLAF_NV_OBJ_NO_OBJ	(1)
	#endif
	#ifndef   RTE_HLAF_NV_OBJ_UNKNOWN_OBJ
	  #define RTE_HLAF_NV_OBJ_UNKNOWN_OBJ	(2)
	#endif
	#ifndef   RTE_HLAF_NV_OBJ_PEDESTRIAN
	  #define RTE_HLAF_NV_OBJ_PEDESTRIAN	(3)
	#endif
	#ifndef   RTE_HLAF_NV_OBJ_ANIMAL_SMALL
	  #define RTE_HLAF_NV_OBJ_ANIMAL_SMALL	(4)
	#endif
	#ifndef   RTE_HLAF_NV_OBJ_ANIMAL_BIG
	  #define RTE_HLAF_NV_OBJ_ANIMAL_BIG	(5)
	#endif
	#ifndef   RTE_HLAF_NV_OBJ_INVALID
	  #define RTE_HLAF_NV_OBJ_INVALID	(255)
	#endif

/* typedef RTE_HLAF_NightViewSpot */
	#ifndef   RTE_HLAF_NV_SPOT_UNKNOWN
	  #define RTE_HLAF_NV_SPOT_UNKNOWN	(0)
	#endif
	#ifndef   RTE_HLAF_NV_SPOT_OFF
	  #define RTE_HLAF_NV_SPOT_OFF	(1)
	#endif
	#ifndef   RTE_HLAF_NV_SPOT_BLINK
	  #define RTE_HLAF_NV_SPOT_BLINK	(2)
	#endif
	#ifndef   RTE_HLAF_NV_SPOT_CONT
	  #define RTE_HLAF_NV_SPOT_CONT	(3)
	#endif
	#ifndef   RTE_HLAF_NV_SPOT_ABORT
	  #define RTE_HLAF_NV_SPOT_ABORT	(4)
	#endif
	#ifndef   RTE_HLAF_NV_SPOT_INVALID
	  #define RTE_HLAF_NV_SPOT_INVALID	(255)
	#endif

/* typedef RTE_HLA_Seg_LightStatus */
	#ifndef   RTE_HLA_SEG_LIGHT_STA_POT_RED
	  #define RTE_HLA_SEG_LIGHT_STA_POT_RED	(1)
	#endif
	#ifndef   RTE_HLA_SEG_LIGHT_STA_POT_LED
	  #define RTE_HLA_SEG_LIGHT_STA_POT_LED	(2)
	#endif
	#ifndef   RTE_HLA_SEG_LIGHT_STA_SATURATED_T1
	  #define RTE_HLA_SEG_LIGHT_STA_SATURATED_T1	(4)
	#endif
	#ifndef   RTE_HLA_SEG_LIGHT_STA_SATURATED
	  #define RTE_HLA_SEG_LIGHT_STA_SATURATED	(8)
	#endif
	#ifndef   RTE_HLA_SEG_LIGHT_STA_HOT_PIXEL
	  #define RTE_HLA_SEG_LIGHT_STA_HOT_PIXEL	(16)
	#endif
	#ifndef   RTE_HLA_SEG_LIGHT_STA_POT_FAR_PAIR_LIGHT
	  #define RTE_HLA_SEG_LIGHT_STA_POT_FAR_PAIR_LIGHT	(32)
	#endif
	#ifndef   RTE_HLA_SEG_LIGHT_STA_ISOLATED
	  #define RTE_HLA_SEG_LIGHT_STA_ISOLATED	(64)
	#endif
	#ifndef   RTE_HLA_SEG_LIGHT_STA_DO_NOT_START_NEW_TRACK
	  #define RTE_HLA_SEG_LIGHT_STA_DO_NOT_START_NEW_TRACK	(128)
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

/* typedef eDimensionality_t */
	#ifndef   PC_X_
	  #define PC_X_	(0)
	#endif
	#ifndef   PC_XY_
	  #define PC_XY_	(1)
	#endif

/* typedef eReconstruct_Intensity_t */
	#ifndef   PC_BIAS_GAIN_OFF_
	  #define PC_BIAS_GAIN_OFF_	(0)
	#endif
	#ifndef   PC_BIAS_GAIN_
	  #define PC_BIAS_GAIN_	(1)
	#endif
	#ifndef   PC_BIAS_
	  #define PC_BIAS_	(2)
	#endif

/* typedef eReconstruct_Scale_t */
	#ifndef   PC_SCALE_OFF_
	  #define PC_SCALE_OFF_	(0)
	#endif
	#ifndef   PC_SCALE_FIXED_
	  #define PC_SCALE_FIXED_	(1)
	#endif
	#ifndef   PC_SCALE_RECONSTRUCT_
	  #define PC_SCALE_RECONSTRUCT_	(2)
	#endif

/* typedef eMaskingOut_t */
	#ifndef   PC_MASK_OFF_
	  #define PC_MASK_OFF_	(0)
	#endif
	#ifndef   PC_MASK_CREATE_
	  #define PC_MASK_CREATE_	(1)
	#endif

/* typedef PcOpMode_t */
	#ifndef   PC_OPMODE_IDLE
	  #define PC_OPMODE_IDLE	(0)
	#endif
	#ifndef   PC_OPMODE_RESET
	  #define PC_OPMODE_RESET	(1)
	#endif
	#ifndef   PC_OPMODE_RUN
	  #define PC_OPMODE_RUN	(2)
	#endif
	#ifndef   PC_OPMODE_MAX_RUNTIME
	  #define PC_OPMODE_MAX_RUNTIME	(3)
	#endif
	#ifndef   PC_OPMODE_DEMO
	  #define PC_OPMODE_DEMO	(4)
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

/* typedef PedOpMode_t */
	#ifndef   ePedOpMode_Idle
	  #define ePedOpMode_Idle	(0)
	#endif
	#ifndef   ePedOpMode_Reset
	  #define ePedOpMode_Reset	(1)
	#endif
	#ifndef   ePedOpMode_Run
	  #define ePedOpMode_Run	(2)
	#endif
	#ifndef   ePedOpMode_MaxRunTime
	  #define ePedOpMode_MaxRunTime	(3)
	#endif
	#ifndef   ePedOpMode_Demo1
	  #define ePedOpMode_Demo1	(4)
	#endif
	#ifndef   ePedOpMode_Demo2
	  #define ePedOpMode_Demo2	(5)
	#endif

/* typedef PedObjectClass_t */
	#ifndef   ePedObjectClass_Pedestrian
	  #define ePedObjectClass_Pedestrian	(1)
	#endif
	#ifndef   ePedObjectClass_BicycleSide
	  #define ePedObjectClass_BicycleSide	(2)
	#endif
	#ifndef   ePedObjectClass_BicycleFront
	  #define ePedObjectClass_BicycleFront	(3)
	#endif
	#ifndef   ePedObjectClassCount
	  #define ePedObjectClassCount	(4)
	#endif

/* typedef RtePvTrackingState_t */
	#ifndef   RTE_PV_TRACKING_STATE_INIT
	  #define RTE_PV_TRACKING_STATE_INIT	(0)
	#endif
	#ifndef   RTE_PV_TRACKING_STATE_RUN
	  #define RTE_PV_TRACKING_STATE_RUN	(1)
	#endif
	#ifndef   RTE_PV_TRACKING_STATE_ERROR
	  #define RTE_PV_TRACKING_STATE_ERROR	(2)
	#endif

/* typedef PvErrorCode_t */
	#ifndef   PV_ERROR_NO_ERROR
	  #define PV_ERROR_NO_ERROR	(0)
	#endif
	#ifndef   PV_ERROR_UNKNOWN
	  #define PV_ERROR_UNKNOWN	(1)
	#endif
	#ifndef   PV_ERROR_OPMODE_NOT_SUPPORTED
	  #define PV_ERROR_OPMODE_NOT_SUPPORTED	(2)
	#endif
	#ifndef   PV_ERROR_INPUT_PORT_LIST_NULL_PTR
	  #define PV_ERROR_INPUT_PORT_LIST_NULL_PTR	(3)
	#endif
	#ifndef   PV_ERROR_INPUT_PORT_NULL_PTR
	  #define PV_ERROR_INPUT_PORT_NULL_PTR	(4)
	#endif
	#ifndef   PV_ERROR_INPUT_SERVICE_LIST_NULL_PTR
	  #define PV_ERROR_INPUT_SERVICE_LIST_NULL_PTR	(5)
	#endif
	#ifndef   PV_ERROR_INPUT_SERVICE_NULL_PTR
	  #define PV_ERROR_INPUT_SERVICE_NULL_PTR	(6)
	#endif
	#ifndef   PV_ERROR_OUTPUT_PORT_LIST_NULL_PTR
	  #define PV_ERROR_OUTPUT_PORT_LIST_NULL_PTR	(7)
	#endif
	#ifndef   PV_ERROR_OUTPUT_PORT_NULL_PTR
	  #define PV_ERROR_OUTPUT_PORT_NULL_PTR	(8)
	#endif

/* typedef RtePvProcessingMode_t */
	#ifndef   RTE_PV_PROC_MODE_DEFAULT
	  #define RTE_PV_PROC_MODE_DEFAULT	(0)
	#endif
	#ifndef   RTE_PV_PROC_MODE_ALGO_NO_MEAS
	  #define RTE_PV_PROC_MODE_ALGO_NO_MEAS	(1)
	#endif
	#ifndef   RTE_PV_PROC_MODE_MEAS_INPUT_ONLY
	  #define RTE_PV_PROC_MODE_MEAS_INPUT_ONLY	(2)
	#endif
	#ifndef   RTE_PV_PROC_MODE_TEST_OUTPUT
	  #define RTE_PV_PROC_MODE_TEST_OUTPUT	(3)
	#endif

/* typedef PvOpMode_t */
	#ifndef   PV_OPMODE_IDLE
	  #define PV_OPMODE_IDLE	(0)
	#endif
	#ifndef   PV_OPMODE_RESET
	  #define PV_OPMODE_RESET	(1)
	#endif
	#ifndef   PV_OPMODE_RUN
	  #define PV_OPMODE_RUN	(2)
	#endif
	#ifndef   PV_OPMODE_MAX_RUNTIME
	  #define PV_OPMODE_MAX_RUNTIME	(3)
	#endif
	#ifndef   PV_OPMODE_DEMO
	  #define PV_OPMODE_DEMO	(4)
	#endif

/* typedef RtePvSignalState_t */
	#ifndef   RTE_PV_SIG_NOT_OK
	  #define RTE_PV_SIG_NOT_OK	(0)
	#endif
	#ifndef   RTE_PV_SIG_INIT
	  #define RTE_PV_SIG_INIT	(1)
	#endif
	#ifndef   RTE_PV_SIG_OK
	  #define RTE_PV_SIG_OK	(2)
	#endif

/* typedef RtePvSignalType_t */
	#ifndef   RTE_PV_SIGTYPE_INVALID
	  #define RTE_PV_SIGTYPE_INVALID	(0)
	#endif
	#ifndef   RTE_PV_SIGTYPE_ODO_POS_X
	  #define RTE_PV_SIGTYPE_ODO_POS_X	(1)
	#endif
	#ifndef   RTE_PV_SIGTYPE_ODO_POS_Y
	  #define RTE_PV_SIGTYPE_ODO_POS_Y	(2)
	#endif
	#ifndef   RTE_PV_SIGTYPE_ODO_YAW_ANGLE
	  #define RTE_PV_SIGTYPE_ODO_YAW_ANGLE	(3)
	#endif
	#ifndef   RTE_PV_SIGTYPE_ODO_POS_X_DELTA_ERR
	  #define RTE_PV_SIGTYPE_ODO_POS_X_DELTA_ERR	(4)
	#endif
	#ifndef   RTE_PV_SIGTYPE_ODO_POS_Y_DELTA_ERR
	  #define RTE_PV_SIGTYPE_ODO_POS_Y_DELTA_ERR	(5)
	#endif
	#ifndef   RTE_PV_SIGTYPE_ANGYAW_DELTA_ERR
	  #define RTE_PV_SIGTYPE_ANGYAW_DELTA_ERR	(6)
	#endif
	#ifndef   RTE_PV_SIGTYPE_VEH_CURVATURE
	  #define RTE_PV_SIGTYPE_VEH_CURVATURE	(7)
	#endif
	#ifndef   RTE_PV_SIGTYPE_VEH_ATTA_ANGLE
	  #define RTE_PV_SIGTYPE_VEH_ATTA_ANGLE	(8)
	#endif
	#ifndef   RTE_PV_SIGTYPE_VEH_SPEED
	  #define RTE_PV_SIGTYPE_VEH_SPEED	(9)
	#endif

/* typedef SacRteDistTestSigState_t */
	#ifndef   SAC_RTE_DSTMO_Default
	  #define SAC_RTE_DSTMO_Default	(0)
	#endif
	#ifndef   SAC_RTE_DSTMO_ValidDstTest
	  #define SAC_RTE_DSTMO_ValidDstTest	(1)
	#endif
	#ifndef   SAC_RTE_DSTMO_ValidCalibration
	  #define SAC_RTE_DSTMO_ValidCalibration	(2)
	#endif

/* typedef SacRteSource_t */
	#ifndef   SAC_RTE_SRC_Invalid
	  #define SAC_RTE_SRC_Invalid	(0)
	#endif
	#ifndef   SAC_RTE_SRC_NVM
	  #define SAC_RTE_SRC_NVM	(20)
	#endif
	#ifndef   SAC_RTE_SRC_EOL
	  #define SAC_RTE_SRC_EOL	(30)
	#endif
	#ifndef   SAC_RTE_SRC_AutoCalCoarse
	  #define SAC_RTE_SRC_AutoCalCoarse	(40)
	#endif
	#ifndef   SAC_RTE_SRC_AutoCalFine
	  #define SAC_RTE_SRC_AutoCalFine	(50)
	#endif
	#ifndef   SAC_RTE_SRC_EOLUpdate
	  #define SAC_RTE_SRC_EOLUpdate	(60)
	#endif
	#ifndef   SAC_RTE_SRC_SelfEval
	  #define SAC_RTE_SRC_SelfEval	(70)
	#endif
	#ifndef   SAC_RTE_SRC_TempModel
	  #define SAC_RTE_SRC_TempModel	(80)
	#endif
	#ifndef   SAC_RTE_SRC_DistanceTest
	  #define SAC_RTE_SRC_DistanceTest	(90)
	#endif

/* typedef SacRteDistTestMode_t */
	#ifndef   SAC_RTE_DSTM_EVALUATE
	  #define SAC_RTE_DSTM_EVALUATE	(0)
	#endif
	#ifndef   SAC_RTE_DSTM_CALIBRATE
	  #define SAC_RTE_DSTM_CALIBRATE	(1)
	#endif

/* typedef SacRteDistTestCoordinate_t */
	#ifndef   SAC_RTE_DSTM_CoordinateSystem_None
	  #define SAC_RTE_DSTM_CoordinateSystem_None	(0)
	#endif
	#ifndef   SAC_RTE_DSTM_CoordinateSystem_Vehicle
	  #define SAC_RTE_DSTM_CoordinateSystem_Vehicle	(2)
	#endif
	#ifndef   SAC_RTE_DSTM_CoordinateSystem_Camera_rectified_image
	  #define SAC_RTE_DSTM_CoordinateSystem_Camera_rectified_image	(50)
	#endif
	#ifndef   SAC_RTE_DSTM_CoordinateSystem_Camera_disparity_image
	  #define SAC_RTE_DSTM_CoordinateSystem_Camera_disparity_image	(70)
	#endif

/* typedef SacRteReturnState_t */
	#ifndef   SAC_RTE_Mode_Default
	  #define SAC_RTE_Mode_Default	(0)
	#endif
	#ifndef   SAC_RTE_Mode_Test_Running
	  #define SAC_RTE_Mode_Test_Running	(11)
	#endif
	#ifndef   SAC_RTE_Mode_Test_Finished
	  #define SAC_RTE_Mode_Test_Finished	(12)
	#endif
	#ifndef   SAC_RTE_Mode_Test_Failed
	  #define SAC_RTE_Mode_Test_Failed	(13)
	#endif
	#ifndef   SAC_RTE_Mode_MeasOnly_Running
	  #define SAC_RTE_Mode_MeasOnly_Running	(21)
	#endif
	#ifndef   SAC_RTE_Mode_MeasOnly_Finished
	  #define SAC_RTE_Mode_MeasOnly_Finished	(22)
	#endif
	#ifndef   SAC_RTE_Mode_MeasOnly_Failed
	  #define SAC_RTE_Mode_MeasOnly_Failed	(23)
	#endif
	#ifndef   SAC_RTE_Mode_InitLUT_Running
	  #define SAC_RTE_Mode_InitLUT_Running	(31)
	#endif
	#ifndef   SAC_RTE_Mode_InitLUT_Finished
	  #define SAC_RTE_Mode_InitLUT_Finished	(32)
	#endif
	#ifndef   SAC_RTE_Mode_InitLUT_Failed
	  #define SAC_RTE_Mode_InitLUT_Failed	(33)
	#endif
	#ifndef   SAC_RTE_Mode_AutoCalCoarse_Running
	  #define SAC_RTE_Mode_AutoCalCoarse_Running	(41)
	#endif
	#ifndef   SAC_RTE_Mode_AutoCalCoarse_Finished
	  #define SAC_RTE_Mode_AutoCalCoarse_Finished	(42)
	#endif
	#ifndef   SAC_RTE_Mode_AutoCalCoarse_Failed
	  #define SAC_RTE_Mode_AutoCalCoarse_Failed	(43)
	#endif
	#ifndef   SAC_RTE_Mode_AutoCalFine_Running
	  #define SAC_RTE_Mode_AutoCalFine_Running	(51)
	#endif
	#ifndef   SAC_RTE_Mode_AutoCalFine_Finished
	  #define SAC_RTE_Mode_AutoCalFine_Finished	(52)
	#endif
	#ifndef   SAC_RTE_Mode_AutoCalFine_Failed
	  #define SAC_RTE_Mode_AutoCalFine_Failed	(53)
	#endif
	#ifndef   SAC_RTE_Mode_EOLUpdate_Running
	  #define SAC_RTE_Mode_EOLUpdate_Running	(61)
	#endif
	#ifndef   SAC_RTE_Mode_EOLUpdate_Finished
	  #define SAC_RTE_Mode_EOLUpdate_Finished	(62)
	#endif
	#ifndef   SAC_RTE_Mode_EOLUpdate_Failed
	  #define SAC_RTE_Mode_EOLUpdate_Failed	(63)
	#endif
	#ifndef   SAC_RTE_Mode_SelfEval_Running
	  #define SAC_RTE_Mode_SelfEval_Running	(71)
	#endif
	#ifndef   SAC_RTE_Mode_SelfEval_Finished
	  #define SAC_RTE_Mode_SelfEval_Finished	(72)
	#endif
	#ifndef   SAC_RTE_Mode_SelfEval_Failed
	  #define SAC_RTE_Mode_SelfEval_Failed	(73)
	#endif
	#ifndef   SAC_RTE_Mode_DistTest_Running
	  #define SAC_RTE_Mode_DistTest_Running	(81)
	#endif
	#ifndef   SAC_RTE_Mode_DistTest_Finished
	  #define SAC_RTE_Mode_DistTest_Finished	(82)
	#endif
	#ifndef   SAC_RTE_Mode_DistTest_Failed
	  #define SAC_RTE_Mode_DistTest_Failed	(83)
	#endif

/* typedef SacRteCalibQuality_t */
	#ifndef   SAC_RTE_CalibQuality_undefined
	  #define SAC_RTE_CalibQuality_undefined	(0)
	#endif
	#ifndef   SAC_RTE_CalibQuality_good
	  #define SAC_RTE_CalibQuality_good	(1)
	#endif
	#ifndef   SAC_RTE_CalibQuality_sufficient
	  #define SAC_RTE_CalibQuality_sufficient	(3)
	#endif
	#ifndef   SAC_RTE_CalibQuality_insufficient
	  #define SAC_RTE_CalibQuality_insufficient	(6)
	#endif

/* typedef SacRteResult_t */
	#ifndef   SAC_RTE_RESULT_DEFAULT
	  #define SAC_RTE_RESULT_DEFAULT	(0)
	#endif
	#ifndef   SAC_RTE_RESULT_USABLE
	  #define SAC_RTE_RESULT_USABLE	(1)
	#endif
	#ifndef   SAC_RTE_RESULT_NOT_USABLE
	  #define SAC_RTE_RESULT_NOT_USABLE	(2)
	#endif

/* typedef SacRteCorrespondenceMode_t */
	#ifndef   SAC_RTE_CM_DEFAULT
	  #define SAC_RTE_CM_DEFAULT	(0)
	#endif
	#ifndef   SAC_RTE_CM_TEMPORAL
	  #define SAC_RTE_CM_TEMPORAL	(1)
	#endif
	#ifndef   SAC_RTE_CM_SPACIAL
	  #define SAC_RTE_CM_SPACIAL	(2)
	#endif

/* typedef SacRteBswSchedulingMode_t */
	#ifndef   SAC_RTE_BSW_MODE_IN_DEFAULT
	  #define SAC_RTE_BSW_MODE_IN_DEFAULT	(0)
	#endif
	#ifndef   SAC_RTE_BSW_MODE_IN_STANDALONE
	  #define SAC_RTE_BSW_MODE_IN_STANDALONE	(1)
	#endif
	#ifndef   SAC_RTE_BSW_MODE_IN_RUNPARALLEL
	  #define SAC_RTE_BSW_MODE_IN_RUNPARALLEL	(2)
	#endif

/* typedef SacRteGbBlockageStatus_t */
	#ifndef   SAC_RTE_GB_UNKNOWN_STATUS
	  #define SAC_RTE_GB_UNKNOWN_STATUS	(0)
	#endif
	#ifndef   SAC_RTE_GB_NO_BLOCKAGE
	  #define SAC_RTE_GB_NO_BLOCKAGE	(1)
	#endif
	#ifndef   SAC_RTE_GB_TOLERATED_BLOCKAGE
	  #define SAC_RTE_GB_TOLERATED_BLOCKAGE	(2)
	#endif
	#ifndef   SAC_RTE_GB_CONDENSATION
	  #define SAC_RTE_GB_CONDENSATION	(3)
	#endif
	#ifndef   SAC_RTE_GB_PART_BLOCKAGE
	  #define SAC_RTE_GB_PART_BLOCKAGE	(4)
	#endif
	#ifndef   SAC_RTE_GB_LOW_VISIBILITY
	  #define SAC_RTE_GB_LOW_VISIBILITY	(5)
	#endif
	#ifndef   SAC_RTE_GB_BLOCKAGE
	  #define SAC_RTE_GB_BLOCKAGE	(6)
	#endif

/* typedef SacRteInputCheckerMode_t */
	#ifndef   SAC_RTE_INPUT_CHECKER_MODE_ON
	  #define SAC_RTE_INPUT_CHECKER_MODE_ON	(0)
	#endif
	#ifndef   SAC_RTE_INPUT_CHECKER_MODE_OFF
	  #define SAC_RTE_INPUT_CHECKER_MODE_OFF	(1)
	#endif

/* typedef SacRteOutputCheckerMode_t */
	#ifndef   SAC_RTE_OUTPUT_CHECKER_MODE_ON
	  #define SAC_RTE_OUTPUT_CHECKER_MODE_ON	(0)
	#endif
	#ifndef   SAC_RTE_OUTPUT_CHECKER_MODE_OFF
	  #define SAC_RTE_OUTPUT_CHECKER_MODE_OFF	(1)
	#endif

/* typedef SacRteOpMode_t */
	#ifndef   SAC_RTE_OPMODE_IDLE
	  #define SAC_RTE_OPMODE_IDLE	(0)
	#endif
	#ifndef   SAC_RTE_OPMODE_RESET
	  #define SAC_RTE_OPMODE_RESET	(1)
	#endif
	#ifndef   SAC_RTE_OPMODE_RUN
	  #define SAC_RTE_OPMODE_RUN	(2)
	#endif
	#ifndef   SAC_RTE_OPMODE_MAX_RUNTIME
	  #define SAC_RTE_OPMODE_MAX_RUNTIME	(3)
	#endif
	#ifndef   SAC_RTE_OPMODE_DEMO
	  #define SAC_RTE_OPMODE_DEMO	(4)
	#endif
	#ifndef   SAC_RTE_OPMODE_SYNC
	  #define SAC_RTE_OPMODE_SYNC	(5)
	#endif
	#ifndef   SAC_RTE_OPMODE_MEAS_ONLY
	  #define SAC_RTE_OPMODE_MEAS_ONLY	(6)
	#endif
	#ifndef   SAC_RTE_OPMODE_INIT_LUT
	  #define SAC_RTE_OPMODE_INIT_LUT	(7)
	#endif
	#ifndef   SAC_RTE_OPMODE_AUTOCAL_COARSE
	  #define SAC_RTE_OPMODE_AUTOCAL_COARSE	(8)
	#endif
	#ifndef   SAC_RTE_OPMODE_AUTOCAL_FINE
	  #define SAC_RTE_OPMODE_AUTOCAL_FINE	(9)
	#endif
	#ifndef   SAC_RTE_OPMODE_AUTO_CHOICE
	  #define SAC_RTE_OPMODE_AUTO_CHOICE	(10)
	#endif
	#ifndef   SAC_RTE_OPMODE_EOL_UPDATE
	  #define SAC_RTE_OPMODE_EOL_UPDATE	(11)
	#endif
	#ifndef   SAC_RTE_OPMODE_SELF_EVAL
	  #define SAC_RTE_OPMODE_SELF_EVAL	(12)
	#endif
	#ifndef   SAC_RTE_OPMODE_TEST
	  #define SAC_RTE_OPMODE_TEST	(13)
	#endif
	#ifndef   SAC_RTE_OPMODE_DISTANCE_TEST
	  #define SAC_RTE_OPMODE_DISTANCE_TEST	(14)
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
	  #define SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_RIGHT_SIDE	(121010)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_LEFT_SIDE
	  #define SR_RTE_SIGN_CLASS_DANGER_ROAD_NARROW_LEFT_SIDE	(121020)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_ROAD_WORK
	  #define SR_RTE_SIGN_CLASS_DANGER_ROAD_WORK	(123000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_TRAFFIC_JAM
	  #define SR_RTE_SIGN_CLASS_DANGER_TRAFFIC_JAM	(124000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_TWO_WAY_TRAFFIC
	  #define SR_RTE_SIGN_CLASS_DANGER_TWO_WAY_TRAFFIC	(125000)
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
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_BUNDLE_NO_PASSING_END
	  #define SR_RTE_SIGN_CLASS_MAIN_BUNDLE_NO_PASSING_END	(280100)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_BUNDLE_NO_PASSING_END_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_BUNDLE_NO_PASSING_END_ACTIVE	(280101)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_GENERAL_END
	  #define SR_RTE_SIGN_CLASS_MAIN_GENERAL_END	(282000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_GENERAL_END_ACTIVE
	  #define SR_RTE_SIGN_CLASS_MAIN_GENERAL_END_ACTIVE	(282001)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_DANGER_CROSS_ROAD_SMALL_ROAD
	  #define SR_RTE_SIGN_CLASS_DANGER_CROSS_ROAD_SMALL_ROAD	(301000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_BEGIN
	  #define SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_BEGIN	(310000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_END
	  #define SR_RTE_SIGN_CLASS_MAIN_CITY_LIMIT_END	(311000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_BEGIN
	  #define SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_BEGIN	(325000)
	#endif
	#ifndef   SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_END
	  #define SR_RTE_SIGN_CLASS_MAIN_PLAY_STREET_END	(326000)
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
	#ifndef   SR_RTE_SIGN_CLASS_CLUSTER_GARBAGE
	  #define SR_RTE_SIGN_CLASS_CLUSTER_GARBAGE	(999990)
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

/* typedef trafficStyle_t */
	#ifndef   SR_RTE_RESULT_COUNTRY_TRAFFIC_STYLE_UNKNOWN
	  #define SR_RTE_RESULT_COUNTRY_TRAFFIC_STYLE_UNKNOWN	(0)
	#endif
	#ifndef   SR_RTE_RESULT_COUNTRY_LEFT_HAND_TRAFFIC
	  #define SR_RTE_RESULT_COUNTRY_LEFT_HAND_TRAFFIC	(1)
	#endif
	#ifndef   SR_RTE_RESULT_COUNTRY_RIGHT_HAND_TRAFFIC
	  #define SR_RTE_RESULT_COUNTRY_RIGHT_HAND_TRAFFIC	(2)
	#endif
	#ifndef   SR_RTE_OUTPUT_COUNTRY_TRAFFIC_STYLE_INT_MAX
	  #define SR_RTE_OUTPUT_COUNTRY_TRAFFIC_STYLE_INT_MAX	(2147483647)
	#endif

/* typedef speedUnit_t */
	#ifndef   SR_RTE_RESULT_COUNTRY_UNIT_UNKNOWN
	  #define SR_RTE_RESULT_COUNTRY_UNIT_UNKNOWN	(0)
	#endif
	#ifndef   SR_RTE_RESULT_COUNTRY_UNIT_KMH
	  #define SR_RTE_RESULT_COUNTRY_UNIT_KMH	(1)
	#endif
	#ifndef   SR_RTE_RESULT_COUNTRY_UNIT_MPH
	  #define SR_RTE_RESULT_COUNTRY_UNIT_MPH	(2)
	#endif
	#ifndef   SR_RTE_RESULT_COUNTRY_UNIT_MPH_OR_KMH
	  #define SR_RTE_RESULT_COUNTRY_UNIT_MPH_OR_KMH	(3)
	#endif
	#ifndef   SR_RTE_OUTPUT_COUNTRY_SPEED_LIMIT_UNIT_INT_MAX
	  #define SR_RTE_OUTPUT_COUNTRY_SPEED_LIMIT_UNIT_INT_MAX	(2147483647)
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

/* typedef SrCountryVariationVehicle_t */
	#ifndef   SR_RTE_COUNTRY_VARIATION_UNKNOWN
	  #define SR_RTE_COUNTRY_VARIATION_UNKNOWN	(0)
	#endif
	#ifndef   SR_RTE_COUNTRY_VARIATION_ECE
	  #define SR_RTE_COUNTRY_VARIATION_ECE	(1)
	#endif
	#ifndef   SR_RTE_COUNTRY_VARIATION_GULF
	  #define SR_RTE_COUNTRY_VARIATION_GULF	(2)
	#endif
	#ifndef   SR_RTE_COUNTRY_VARIATION_USA
	  #define SR_RTE_COUNTRY_VARIATION_USA	(3)
	#endif
	#ifndef   SR_RTE_COUNTRY_VARIATION_CANADA
	  #define SR_RTE_COUNTRY_VARIATION_CANADA	(4)
	#endif
	#ifndef   SR_RTE_COUNTRY_VARIATION_ROW
	  #define SR_RTE_COUNTRY_VARIATION_ROW	(5)
	#endif
	#ifndef   SR_RTE_COUNTRY_VARIATION_JPCN
	  #define SR_RTE_COUNTRY_VARIATION_JPCN	(6)
	#endif
	#ifndef   SR_RTE_COUNTRY_VARIATION_INT_MAX
	  #define SR_RTE_COUNTRY_VARIATION_INT_MAX	(2147483647)
	#endif

/* typedef SrTsmCountryVariation_t */
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_ECE
	  #define SR_RTE_TSM_COUNTRY_VARIATION_ECE	(1)
	#endif
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_USA
	  #define SR_RTE_TSM_COUNTRY_VARIATION_USA	(2)
	#endif
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_GERMANY
	  #define SR_RTE_TSM_COUNTRY_VARIATION_GERMANY	(3)
	#endif
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_ENGLAND
	  #define SR_RTE_TSM_COUNTRY_VARIATION_ENGLAND	(4)
	#endif
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_CANADA
	  #define SR_RTE_TSM_COUNTRY_VARIATION_CANADA	(5)
	#endif
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_GULF
	  #define SR_RTE_TSM_COUNTRY_VARIATION_GULF	(6)
	#endif
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_CHINA
	  #define SR_RTE_TSM_COUNTRY_VARIATION_CHINA	(7)
	#endif
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_COREA
	  #define SR_RTE_TSM_COUNTRY_VARIATION_COREA	(8)
	#endif
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_JAPAN
	  #define SR_RTE_TSM_COUNTRY_VARIATION_JAPAN	(9)
	#endif
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_AUSTRALIA
	  #define SR_RTE_TSM_COUNTRY_VARIATION_AUSTRALIA	(10)
	#endif
	#ifndef   SR_RTE_TSM_COUNTRY_VARIATION_INT_MAX
	  #define SR_RTE_TSM_COUNTRY_VARIATION_INT_MAX	(2147483647)
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
	#ifndef   SR_RTE_FEATURE_CONFIG_PLAYSTREET
	  #define SR_RTE_FEATURE_CONFIG_PLAYSTREET	(8)
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
	#ifndef   SR_RTE_FEATURE_CONFIG_INT_MAX
	  #define SR_RTE_FEATURE_CONFIG_INT_MAX	(2147483647)
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

/* typedef TsaControlFlow_t */
	#ifndef   TSA_RTE_CONTROL_FLOW_NORMAL
	  #define TSA_RTE_CONTROL_FLOW_NORMAL	(0)
	#endif
	#ifndef   TSA_RTE_CONTROL_FLOW_SKIP_KERNEL
	  #define TSA_RTE_CONTROL_FLOW_SKIP_KERNEL	(1)
	#endif
	#ifndef   TSA_RTE_CONTROL_FLOW_SKIP_KERNEL_FAKE_OUTPUT
	  #define TSA_RTE_CONTROL_FLOW_SKIP_KERNEL_FAKE_OUTPUT	(2)
	#endif
	#ifndef   TSA_RTE_CONTROL_FLOW_DEBUG
	  #define TSA_RTE_CONTROL_FLOW_DEBUG	(3)
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

/* typedef countryConfig_t */
	#ifndef   TSA_RTE_COUNTRY_CONFIG_SLA_HMI_DISABLE_SPDLMT_END
	  #define TSA_RTE_COUNTRY_CONFIG_SLA_HMI_DISABLE_SPDLMT_END	(0)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_OFF
	  #define TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_OFF	(0)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_WWA_CNTRY_DISABLED
	  #define TSA_RTE_COUNTRY_CONFIG_WWA_CNTRY_DISABLED	(0)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_SLA_DISABLE_IMPLICIT_RULES
	  #define TSA_RTE_COUNTRY_CONFIG_SLA_DISABLE_IMPLICIT_RULES	(0)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_ALWAYS
	  #define TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_ALWAYS	(0)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_NPA_CNTRY_DISABLED
	  #define TSA_RTE_COUNTRY_CONFIG_NPA_CNTRY_DISABLED	(0)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_ENTRY
	  #define TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_ENTRY	(1)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_MID
	  #define TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_MID	(2)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_HIGH
	  #define TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_HIGH	(3)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_NOT_RESOLVED
	  #define TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_NOT_RESOLVED	(4)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_NEVER
	  #define TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_NEVER	(8)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_IGNORE
	  #define TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_IGNORE	(12)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_SLA_HMI_ENABLE_SPDLMT_END
	  #define TSA_RTE_COUNTRY_CONFIG_SLA_HMI_ENABLE_SPDLMT_END	(16)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_SLA_ENABLE_IMPLICIT_RULES
	  #define TSA_RTE_COUNTRY_CONFIG_SLA_ENABLE_IMPLICIT_RULES	(32)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_NPA_CNTRY_ENABLED
	  #define TSA_RTE_COUNTRY_CONFIG_NPA_CNTRY_ENABLED	(64)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_WWA_CNTRY_ENABLED
	  #define TSA_RTE_COUNTRY_CONFIG_WWA_CNTRY_ENABLED	(128)
	#endif
	#ifndef   TSA_RTE_COUNTRY_CONFIG_INT_MAX
	  #define TSA_RTE_COUNTRY_CONFIG_INT_MAX	(2147483647)
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

/* typedef TsaRteNpaValidity_t */
	#ifndef   TSA_RTE_NPA_IDLE_VALIDITY
	  #define TSA_RTE_NPA_IDLE_VALIDITY	(0)
	#endif
	#ifndef   TSA_RTE_NPA_VALID_UNRESTRICTED
	  #define TSA_RTE_NPA_VALID_UNRESTRICTED	(1)
	#endif
	#ifndef   TSA_RTE_NPA_VALID_RESTRICTED
	  #define TSA_RTE_NPA_VALID_RESTRICTED	(2)
	#endif
	#ifndef   TSA_RTE_NPA_VALID_FOR_TRUCK
	  #define TSA_RTE_NPA_VALID_FOR_TRUCK	(3)
	#endif
	#ifndef   TSA_RTE_NPA_VALID_FOR_CAR_TRAILER
	  #define TSA_RTE_NPA_VALID_FOR_CAR_TRAILER	(4)
	#endif
	#ifndef   TSA_RTE_NPA_VALID_FOR_CAR
	  #define TSA_RTE_NPA_VALID_FOR_CAR	(5)
	#endif
	#ifndef   TSA_RTE_NPA_VALID_ARROW
	  #define TSA_RTE_NPA_VALID_ARROW	(6)
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

/* typedef TsaRteNpaIndicators_t */
	#ifndef   TSA_RTE_NPA_INDICATOR_SIGN
	  #define TSA_RTE_NPA_INDICATOR_SIGN	(1)
	#endif
	#ifndef   TSA_RTE_NPA_INDICATOR_SIGN_CANCEL
	  #define TSA_RTE_NPA_INDICATOR_SIGN_CANCEL	(2)
	#endif
	#ifndef   TSA_RTE_NPA_INDICATOR_LANE
	  #define TSA_RTE_NPA_INDICATOR_LANE	(4)
	#endif
	#ifndef   TSA_RTE_NPA_INDICATOR_SIGN_RESTR
	  #define TSA_RTE_NPA_INDICATOR_SIGN_RESTR	(16)
	#endif
	#ifndef   TSA_RTE_NPA_INDICATOR_SIGN_TRAILER
	  #define TSA_RTE_NPA_INDICATOR_SIGN_TRAILER	(32)
	#endif
	#ifndef   TSA_RTE_NPA_INDICATOR_GENERAL_CANCEL
	  #define TSA_RTE_NPA_INDICATOR_GENERAL_CANCEL	(64)
	#endif
	#ifndef   TSA_RTE_NPA_INDICATOR_NO_DISPLAY
	  #define TSA_RTE_NPA_INDICATOR_NO_DISPLAY	(128)
	#endif

/* typedef TsaRteCustomSignResultTrackState_t */
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_ACTIVE
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_ACTIVE	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_ENDED
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_ENDED	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_PASSED
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_PASSED	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_FINISHED
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_STATE_FINISHED	(3)
	#endif

/* typedef TsaRteCustomSignResultTrackCharacteristics_t */
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_NONE
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_NONE	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HAS_SUPPLSIGN
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HAS_SUPPLSIGN	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ON_VEHICLE
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ON_VEHICLE	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ON_INFO_SIGN
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ON_INFO_SIGN	(4)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_NEVER_PASSED
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_NEVER_PASSED	(8)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_CLASS_SHAKY
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_CLASS_SHAKY	(16)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_GEN_END_CHECK_FAILED
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_GEN_END_CHECK_FAILED	(32)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_RESERVED
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_RESERVED	(64)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_IS_PART_OF_GATE
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_IS_PART_OF_GATE	(128)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_IS_EMBEDDED
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_IS_EMBEDDED	(256)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_REDNESS_CHECK_FAILED
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_REDNESS_CHECK_FAILED	(512)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HAS_YELLOW_BACKGROUND
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HAS_YELLOW_BACKGROUND	(1024)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ACTVSBLUE_FAILED
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ACTVSBLUE_FAILED	(2048)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_DISABELED
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_DISABELED	(4096)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT	(8192)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT_SUPPL
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_INCONSISTENT_CONTEXT_SUPPL	(16384)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_MODIFIED_CLASS
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_MODIFIED_CLASS	(32768)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HIGHWAY_EXIT
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_HIGHWAY_EXIT	(65536)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_OTHER_LANE
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_OTHER_LANE	(131072)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_PARALLEL_ROAD
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_PARALLEL_ROAD	(262144)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_DIVERTING_ROAD
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FOR_DIVERTING_ROAD	(524288)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FAR_IRRELEVANT
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_FAR_IRRELEVANT	(1048576)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_EGO_RELEVANCE_UNCLEAR
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_EGO_RELEVANCE_UNCLEAR	(2097152)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_DURING_TURN
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_DURING_TURN	(4194304)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ACTIVE
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_CHARAC_ACTIVE	(8388608)
	#endif

/* typedef TsaRteCustomSignResultGeometry_t */
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_CIRCULAR
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_CIRCULAR	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_RECTANGULAR
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_RECTANGULAR	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_TRIANGULAR
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_TRIANGULAR	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_DIAMOND
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SIGN_DIAMOND	(3)
	#endif

/* typedef TsaRteCustomSignResultUnit_t */
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_UNKNOWN
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_KMH
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_KMH	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_MPH
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_UNIT_MPH	(2)
	#endif

/* typedef TsaRteCustomSignSupplResultPosition_t */
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SUPPL_BELOW
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SUPPL_BELOW	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SUPPL_ABOVE
	  #define TSA_RTE_CUSTOM_SIGN_RESULT_TRACK_SUPPL_ABOVE	(1)
	#endif

/* typedef TsaRteCustomSignFunctionalSignClassId_t */
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_NO_SIGN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_NO_SIGN	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_NO_PASSING
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_NO_PASSING	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_NO_PASSING_SIGN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_NO_PASSING_SIGN	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT	(3)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GENERAL_WITHDRAWAL
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GENERAL_WITHDRAWAL	(4)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_5
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_5	(5)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_10
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_10	(6)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_15
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_15	(7)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_20
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_20	(8)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_25
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_25	(9)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_30
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_30	(10)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_35
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_35	(11)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_40
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_40	(12)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_45
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_45	(13)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_50
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_50	(14)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_55
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_55	(15)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_60
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_60	(16)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_65
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_65	(17)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_70
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_70	(18)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_75
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_75	(19)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_80
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_80	(20)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_85
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_85	(21)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_90
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_90	(22)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_95
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_95	(23)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_100
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_100	(24)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_105
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_105	(25)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_110
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_110	(26)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_115
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_115	(27)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_120
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_120	(28)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_125
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_125	(29)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_130
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_130	(30)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_135
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_135	(31)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_140
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_140	(32)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_145
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_SPEED_LIMIT_145	(33)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_RAIN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_RAIN	(34)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_FOG
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_FOG	(35)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SNOW
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SNOW	(36)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SNOW_RAIN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SNOW_RAIN	(37)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TIME
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TIME	(38)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SCHOOL
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_SCHOOL	(39)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_WEIGHT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_WEIGHT	(40)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_DISTANCE_IN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_DISTANCE_IN	(41)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_DISTANCE_FOR
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_DISTANCE_FOR	(42)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_LEFT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_LEFT	(43)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_RIGHT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_RIGHT	(44)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_LEFT_BEND
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_LEFT_BEND	(45)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_RIGHT_BEND
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ARROW_RIGHT_BEND	(46)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRUCK
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRUCK	(47)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRACTORS_MAY_BE_PASSED
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRACTORS_MAY_BE_PASSED	(48)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_HAZARDOUS
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_HAZARDOUS	(49)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRAILER
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TRAILER	(50)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_NIGHT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_NIGHT	(51)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ZONE
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_ZONE	(52)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_STOP_4WAY
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_STOP_4WAY	(53)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_MOTORCYCLE
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_MOTORCYCLE	(54)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT_2_DIGITS
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT_2_DIGITS	(55)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT_3_DIGITS
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_WITHDRAWAL_SPEED_LIMIT_3_DIGITS	(56)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_LEFT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_LEFT	(75)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_RIGHT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_RIGHT	(76)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_STRAIGHT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PASSING_STRAIGHT	(77)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ROUNDABOUT_SIGN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ROUNDABOUT_SIGN	(78)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_NO_ENTRY
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_NO_ENTRY	(79)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_VEHICLES_PROHIBITED
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_VEHICLES_PROHIBITED	(80)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_MOTORWAY_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_MOTORWAY_START	(81)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_MOTORWAY_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_MOTORWAY_END	(82)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_EXPRESSWAY_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_EXPRESSWAY_START	(83)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_EXPRESSWAY_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_EXPRESSWAY_END	(84)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_TRAFFIC_CALMING_ZONE_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_TRAFFIC_CALMING_ZONE_START	(85)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_TRAFFIC_CALMING_ZONE_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_TRAFFIC_CALMING_ZONE_END	(86)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_STOP_SIGN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_STOP_SIGN	(87)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GIVE_WAY
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GIVE_WAY	(88)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PRIORITY_ROAD_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PRIORITY_ROAD_START	(89)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PRIORITY_ROAD_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_PRIORITY_ROAD_END	(90)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BEND_LEFT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BEND_LEFT	(91)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BEND_RIGHT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BEND_RIGHT	(92)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_DOUBLE_BEND_LEFT_FIR
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_DOUBLE_BEND_LEFT_FIR	(93)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_DOUBLE_BEND_RIGHT_FI
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_DOUBLE_BEND_RIGHT_FI	(94)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_BOTH_SID
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_BOTH_SID	(95)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_LEFT_SID
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_LEFT_SID	(96)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_RIGHT_SI
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_NARROW_RIGHT_SI	(97)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CROSS_ROAD
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CROSS_ROAD	(98)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CROSS_ROAD_SMALL_ROA
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CROSS_ROAD_SMALL_ROA	(99)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_FROM_LEFT_45_DE
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_FROM_LEFT_45_DE	(100)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_FROM_RIGHT_45_D
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_FROM_RIGHT_45_D	(101)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ONE_BUMP
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ONE_BUMP	(102)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TWO_BUMP
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TWO_BUMP	(103)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CONCAVE
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CONCAVE	(104)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAFFIC_JAM
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAFFIC_JAM	(105)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_WORKS
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ROAD_WORKS	(106)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_RIGHT_DOWNWARDS
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_RIGHT_DOWNWARDS	(107)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_RIGHT_UPWARDS
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_RIGHT_UPWARDS	(108)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAFFIC_LIGHT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAFFIC_LIGHT	(109)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ANIMAL_CROSSING
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_ANIMAL_CROSSING	(110)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CHILDREN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_CHILDREN	(111)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_SNOW
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_SNOW	(112)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_SPLIPPERY_ROAD
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_SPLIPPERY_ROAD	(113)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_GIVE_WAY_ROUNDABOUT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_GIVE_WAY_ROUNDABOUT	(114)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_WIND_FROM_SIDE
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_WIND_FROM_SIDE	(115)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_PEDESTRIAN_CROSSING
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_PEDESTRIAN_CROSSING	(116)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BYCICLE_CROSSING
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_BYCICLE_CROSSING	(117)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAIN_CROSS_WITHOUT_
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAIN_CROSS_WITHOUT_	(118)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAIN_CROSS_WITH_BAR
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TRAIN_CROSS_WITH_BAR	(119)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_GRAVEL
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_GRAVEL	(120)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TWO_WAY_TRAFFIC
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_DANGER_TWO_WAY_TRAFFIC	(121)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_START	(122)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_END	(123)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_START_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_CITY_LIMIT_START_END	(124)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_START
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_START	(125)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_END
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_ENVIRONMENTAL_ZONE_END	(126)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GENERIC_SUPPLEMENTAL
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_MAIN_GENERIC_SUPPLEMENTAL	(127)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TEXT
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_TEXT	(128)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_PICTURE
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_PICTURE	(129)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_STOP_IN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_STOP_IN	(130)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_MOTORCYCLE_ALLOWED
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_MOTORCYCLE_ALLOWED	(131)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_CAR
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_CAR	(132)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_RESTRICTED
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_SUPPL_RESTRICTED	(133)
	#endif
	#ifndef   TSA_RTE_CUSTOM_SIGN_CLASS_UNKNOWN
	  #define TSA_RTE_CUSTOM_SIGN_CLASS_UNKNOWN	(254)
	#endif

/* typedef TsaRteSlaSpdLmtType_t */
	#ifndef   TSA_RTE_SLA_SPDLIMTYPE_IDLE
	  #define TSA_RTE_SLA_SPDLIMTYPE_IDLE	(0)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMTYPE_NDEF1
	  #define TSA_RTE_SLA_SPDLIMTYPE_NDEF1	(1)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMTYPE_IMPLICIT_URBAN
	  #define TSA_RTE_SLA_SPDLIMTYPE_IMPLICIT_URBAN	(2)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMTYPE_IMPLICIT_OVERLAND
	  #define TSA_RTE_SLA_SPDLIMTYPE_IMPLICIT_OVERLAND	(3)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMTYPE_EXPLICIT_REGULAR
	  #define TSA_RTE_SLA_SPDLIMTYPE_EXPLICIT_REGULAR	(4)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMTYPE_EXPLICIT_ALTER
	  #define TSA_RTE_SLA_SPDLIMTYPE_EXPLICIT_ALTER	(5)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMTYPE_EXPLICIT_UNLIM
	  #define TSA_RTE_SLA_SPDLIMTYPE_EXPLICIT_UNLIM	(6)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMTYPE_SNA
	  #define TSA_RTE_SLA_SPDLIMTYPE_SNA	(7)
	#endif

/* typedef TsaRteSlaSpdLmtVal_t */
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_IDLE
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_IDLE	(0)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_UNLIM
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_UNLIM	(1)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_ICY
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_ICY	(2)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_FOG
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_FOG	(3)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_WET
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_WET	(4)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_TIME
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_TIME	(5)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_DARK
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_DARK	(6)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_EXT_LFT
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_EXT_LFT	(7)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_EXT_RGT
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_EXT_RGT	(8)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_TRAILER
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_TRAILER	(9)
	#endif
	#ifndef   TSA_RTE_SLA_SPDLIMVALSTAT_RESTRICTED
	  #define TSA_RTE_SLA_SPDLIMVALSTAT_RESTRICTED	(10)
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

/* typedef TsaRteSlaSpdUnit_t */
	#ifndef   TSA_RTE_SLA_UNIT_KMH
	  #define TSA_RTE_SLA_UNIT_KMH	(0)
	#endif
	#ifndef   TSA_RTE_SLA_UNIT_MPH
	  #define TSA_RTE_SLA_UNIT_MPH	(1)
	#endif
	#ifndef   TSA_RTE_SLA_UNIT_NDEF2
	  #define TSA_RTE_SLA_UNIT_NDEF2	(2)
	#endif
	#ifndef   TSA_RTE_SLA_UNIT_SNA
	  #define TSA_RTE_SLA_UNIT_SNA	(3)
	#endif

/* typedef TsaRteSlaSpdLmtEnd_t */
	#ifndef   TSA_RTE_SLA_NO_SPD_LMT_END
	  #define TSA_RTE_SLA_NO_SPD_LMT_END	(0)
	#endif
	#ifndef   TSA_RTE_SLA_2_DIGIT_END
	  #define TSA_RTE_SLA_2_DIGIT_END	(1)
	#endif
	#ifndef   TSA_RTE_SLA_3_DIGIT_END
	  #define TSA_RTE_SLA_3_DIGIT_END	(2)
	#endif
	#ifndef   TSA_RTE_SLA_GENERAL_END
	  #define TSA_RTE_SLA_GENERAL_END	(4)
	#endif
	#ifndef   TSA_RTE_SLA_SPD_LMT_END_NOT_MATCHING
	  #define TSA_RTE_SLA_SPD_LMT_END_NOT_MATCHING	(16)
	#endif

/* typedef TsaRteEstTrafficStyle_t */
	#ifndef   TSA_RTE_EST_TRAFFIC_SYLE_SNA
	  #define TSA_RTE_EST_TRAFFIC_SYLE_SNA	(0)
	#endif
	#ifndef   TSA_RTE_EST_TRAFFIC_STYLE_LH
	  #define TSA_RTE_EST_TRAFFIC_STYLE_LH	(1)
	#endif
	#ifndef   TSA_RTE_EST_TRAFFIC_STYLE_RH
	  #define TSA_RTE_EST_TRAFFIC_STYLE_RH	(2)
	#endif

/* typedef TsaRteEstSpdUnt_t */
	#ifndef   TSA_RTE_EST_SPD_UNT_SNA
	  #define TSA_RTE_EST_SPD_UNT_SNA	(0)
	#endif
	#ifndef   TSA_RTE_EST_SPD_UNT_KMH
	  #define TSA_RTE_EST_SPD_UNT_KMH	(1)
	#endif
	#ifndef   TSA_RTE_EST_SPD_UNT_MPH
	  #define TSA_RTE_EST_SPD_UNT_MPH	(2)
	#endif
	#ifndef   TSA_RTE_EST_SPD_UNT_BOTH
	  #define TSA_RTE_EST_SPD_UNT_BOTH	(3)
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

/* typedef TsaRteCustomOutputEstTrafficStyle_t */
	#ifndef   TSA_RTE_CUSTOM_EST_TRAFFIC_SYLE_SNA
	  #define TSA_RTE_CUSTOM_EST_TRAFFIC_SYLE_SNA	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_EST_TRAFFIC_STYLE_LH
	  #define TSA_RTE_CUSTOM_EST_TRAFFIC_STYLE_LH	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_EST_TRAFFIC_STYLE_RH
	  #define TSA_RTE_CUSTOM_EST_TRAFFIC_STYLE_RH	(2)
	#endif

/* typedef timeOfDay_t */
	#ifndef   TSA_RTE_TIME_OF_DAY_UNKNOWN
	  #define TSA_RTE_TIME_OF_DAY_UNKNOWN	(0)
	#endif
	#ifndef   TSA_RTE_TIME_OF_DAY_DAY
	  #define TSA_RTE_TIME_OF_DAY_DAY	(1)
	#endif
	#ifndef   TSA_RTE_TIME_OF_DAY_NIGHT
	  #define TSA_RTE_TIME_OF_DAY_NIGHT	(2)
	#endif

/* typedef blockageStatus_t */
	#ifndef   TSA_RTE_BLOCKAGE_UNKNOWN_STATUS
	  #define TSA_RTE_BLOCKAGE_UNKNOWN_STATUS	(0)
	#endif
	#ifndef   TSA_RTE_BLOCKAGE_NO_BLOCKAGE
	  #define TSA_RTE_BLOCKAGE_NO_BLOCKAGE	(1)
	#endif
	#ifndef   TSA_RTE_BLOCKAGE_CONDENSATION
	  #define TSA_RTE_BLOCKAGE_CONDENSATION	(2)
	#endif
	#ifndef   TSA_RTE_BLOCKAGE_PART_BLOCKAGE
	  #define TSA_RTE_BLOCKAGE_PART_BLOCKAGE	(3)
	#endif
	#ifndef   TSA_RTE_BLOCKAGE_BLOCKAGE
	  #define TSA_RTE_BLOCKAGE_BLOCKAGE	(4)
	#endif

/* typedef calibrationStatus_t */
	#ifndef   TSA_RTE_CUSTOM_CALIB_STATUS_UNK
	  #define TSA_RTE_CUSTOM_CALIB_STATUS_UNK	(0)
	#endif
	#ifndef   TSA_RTE_CUSTOM_CALIB_STATUS_OK
	  #define TSA_RTE_CUSTOM_CALIB_STATUS_OK	(1)
	#endif
	#ifndef   TSA_RTE_CUSTOM_CALIB_STATUS_NOK
	  #define TSA_RTE_CUSTOM_CALIB_STATUS_NOK	(2)
	#endif
	#ifndef   TSA_RTE_CUSTOM_CALIB_STATUS_SNA
	  #define TSA_RTE_CUSTOM_CALIB_STATUS_SNA	(3)
	#endif

/* typedef corrQual_t */
	#ifndef   VDY_VELO_CORR_QUAL_EEPROM
	  #define VDY_VELO_CORR_QUAL_EEPROM	(0)
	#endif
	#ifndef   VDY_VELO_CORR_QUAL_RANGE_NVERIFIED
	  #define VDY_VELO_CORR_QUAL_RANGE_NVERIFIED	(1)
	#endif
	#ifndef   VDY_VELO_CORR_QUAL_RANGE_VERIFIED
	  #define VDY_VELO_CORR_QUAL_RANGE_VERIFIED	(2)
	#endif
	#ifndef   VDY_VELO_CORR_QUAL_SNA
	  #define VDY_VELO_CORR_QUAL_SNA	(3)
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

/* typedef VdyNvmState_t */
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
	#ifndef   VDY_NVM_POS_DUMMY
	  #define VDY_NVM_POS_DUMMY	(125000)
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

/* typedef TrailerConnection_t */
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
	#ifndef   VDY_IO_STATE_INIT
	  #define VDY_IO_STATE_INIT	(15)
	#endif
	#ifndef   VDY_IO_STATE_MAX
	  #define VDY_IO_STATE_MAX	(255)
	#endif

/* typedef VehDynStatePos_t */
	#ifndef   VDY_SOUT_POS_CURVE
	  #define VDY_SOUT_POS_CURVE	(0)
	#endif
	#ifndef   VDY_SOUT_POS_YWR
	  #define VDY_SOUT_POS_YWR	(1)
	#endif
	#ifndef   VDY_SOUT_POS_DRCRV
	  #define VDY_SOUT_POS_DRCRV	(2)
	#endif
	#ifndef   VDY_SOUT_POS_VEL
	  #define VDY_SOUT_POS_VEL	(3)
	#endif
	#ifndef   VDY_SOUT_POS_ACCEL
	  #define VDY_SOUT_POS_ACCEL	(4)
	#endif
	#ifndef   VDY_SOUT_POS_MSTAT
	  #define VDY_SOUT_POS_MSTAT	(5)
	#endif
	#ifndef   VDY_SOUT_POS_VCORR
	  #define VDY_SOUT_POS_VCORR	(6)
	#endif
	#ifndef   VDY_SOUT_POS_SSA
	  #define VDY_SOUT_POS_SSA	(7)
	#endif
	#ifndef   VDY_SOUT_POS_LATACC
	  #define VDY_SOUT_POS_LATACC	(8)
	#endif
	#ifndef   VDY_SOUT_POS_MAX
	  #define VDY_SOUT_POS_MAX	(12)
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
	#ifndef   VEH_SIG_ADD_IGN_SWITCH
	  #define VEH_SIG_ADD_IGN_SWITCH	(19)
	#endif
	#ifndef   VEH_SIG_ADD_MAX
	  #define VEH_SIG_ADD_MAX	(20)
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
	#ifndef   VEH_PAR_SEN_MOUNT_YAW_ANGLE
	  #define VEH_PAR_SEN_MOUNT_YAW_ANGLE	(6)
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
	  #define VEH_SIG_POWERTRAIN_MAX	(3)
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

/* typedef VodcaOpMode_t */
	#ifndef   VODCA_OPMODE_IDLE
	  #define VODCA_OPMODE_IDLE	(0)
	#endif
	#ifndef   VODCA_OPMODE_RESET
	  #define VODCA_OPMODE_RESET	(1)
	#endif
	#ifndef   VODCA_OPMODE_RUN
	  #define VODCA_OPMODE_RUN	(2)
	#endif
	#ifndef   VODCA_OPMODE_RUN_PREPROC
	  #define VODCA_OPMODE_RUN_PREPROC	(3)
	#endif
	#ifndef   VODCA_OPMODE_RUN_CLASSIFY
	  #define VODCA_OPMODE_RUN_CLASSIFY	(4)
	#endif
	#ifndef   VODCA_OPMODE_MAX_RUNTIME
	  #define VODCA_OPMODE_MAX_RUNTIME	(5)
	#endif
	#ifndef   VODCA_OPMODE_DEMO
	  #define VODCA_OPMODE_DEMO	(6)
	#endif

/* typedef eHOGFeatureType_t */
	#ifndef   eHOGFeatureType_Default
	  #define eHOGFeatureType_Default	(0)
	#endif
	#ifndef   eHOGFeatureType_iHOG
	  #define eHOGFeatureType_iHOG	(1)
	#endif

/* typedef eChannelType_t */
	#ifndef   eChannelType_Gray
	  #define eChannelType_Gray	(0)
	#endif
	#ifndef   eChannelType_U
	  #define eChannelType_U	(1)
	#endif
	#ifndef   eChannelType_V
	  #define eChannelType_V	(2)
	#endif
	#ifndef   eChannelType_UmV
	  #define eChannelType_UmV	(3)
	#endif
	#ifndef   eChannelType_Spare1
	  #define eChannelType_Spare1	(4)
	#endif
	#ifndef   eChannelType_Spare2
	  #define eChannelType_Spare2	(5)
	#endif
	#ifndef   eChannelType_Spare3
	  #define eChannelType_Spare3	(6)
	#endif
	#ifndef   eChannelType_Spare4
	  #define eChannelType_Spare4	(7)
	#endif

/* typedef e_DcgState_t */
	#ifndef   IC_DCG_LOW
	  #define IC_DCG_LOW	(0)
	#endif
	#ifndef   IC_DCG_HIGH
	  #define IC_DCG_HIGH	(1)
	#endif

/* typedef e_FrameType_t */
	#ifndef   IC_FRAME_TYPE_EVEN
	  #define IC_FRAME_TYPE_EVEN	(0)
	#endif
	#ifndef   IC_FRAME_TYPE_ODD
	  #define IC_FRAME_TYPE_ODD	(1)
	#endif

/* typedef e_IntradayState_t */
	#ifndef   IC_INTRADAY_STATE_NIGHT
	  #define IC_INTRADAY_STATE_NIGHT	(0)
	#endif
	#ifndef   IC_INTRADAY_STATE_DAY
	  #define IC_INTRADAY_STATE_DAY	(1)
	#endif

/* typedef e_ImagerCFA_t */
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
	#ifndef   CB_MEAS_ID_ALGO_COMP_STATE
	  #define CB_MEAS_ID_ALGO_COMP_STATE	(537485312)
	#endif
	#ifndef   CB_MEAS_ID_BUS_DEBUG_DATA
	  #define CB_MEAS_ID_BUS_DEBUG_DATA	(537489664)
	#endif
	#ifndef   CB_MEAS_ID_COMMON_ALGO_DATA
	  #define CB_MEAS_ID_COMMON_ALGO_DATA	(537473280)
	#endif
	#ifndef   CB_MEAS_ID_CTRL_BSW_DATA
	  #define CB_MEAS_ID_CTRL_BSW_DATA	(537481216)
	#endif
	#ifndef   CB_MEAS_ID_ERROR_DATA
	  #define CB_MEAS_ID_ERROR_DATA	(537473024)
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
	#ifndef   CB_MEAS_ID_KERNEL_OUTPUT
	  #define CB_MEAS_ID_KERNEL_OUTPUT	(537464832)
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
	#ifndef   CIPP_MEAS_ID_EVEN_BAYER_LOG_P0
	  #define CIPP_MEAS_ID_EVEN_BAYER_LOG_P0	(810620672)
	#endif
	#ifndef   CIPP_MEAS_ID_EVEN_U_P1
	  #define CIPP_MEAS_ID_EVEN_U_P1	(810619648)
	#endif
	#ifndef   CIPP_MEAS_ID_EVEN_V_P1
	  #define CIPP_MEAS_ID_EVEN_V_P1	(810619904)
	#endif
	#ifndef   CIPP_MEAS_ID_EVEN_Y_P1
	  #define CIPP_MEAS_ID_EVEN_Y_P1	(810619392)
	#endif
	#ifndef   CIPP_MEAS_ID_IMG_STAT
	  #define CIPP_MEAS_ID_IMG_STAT	(810621184)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_BAYER_LOG_P0
	  #define CIPP_MEAS_ID_ODD_BAYER_LOG_P0	(810620416)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_SAT_P0
	  #define CIPP_MEAS_ID_ODD_SAT_P0	(810618112)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_SAT_P1
	  #define CIPP_MEAS_ID_ODD_SAT_P1	(810618368)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_SAT_P2
	  #define CIPP_MEAS_ID_ODD_SAT_P2	(810618624)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_SAT_P3
	  #define CIPP_MEAS_ID_ODD_SAT_P3	(810618880)
	#endif
	#ifndef   CIPP_MEAS_ID_ODD_SAT_P4
	  #define CIPP_MEAS_ID_ODD_SAT_P4	(810619136)
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
	#ifndef   EMO_MEAS_ID_SLAM_FEATURES
	  #define EMO_MEAS_ID_SLAM_FEATURES	(816975872)
	#endif
	#ifndef   EM_MEAS_ID_B0_OBJECT_LIST_LRR
	  #define EM_MEAS_ID_B0_OBJECT_LIST_LRR	(538533888)
	#endif
	#ifndef   EM_MEAS_ID_B0_OBJECT_LIST_SCAM
	  #define EM_MEAS_ID_B0_OBJECT_LIST_SCAM	(538509312)
	#endif
	#ifndef   EM_MEAS_ID_B0_OBJECT_LIST_SRR
	  #define EM_MEAS_ID_B0_OBJECT_LIST_SRR	(538521600)
	#endif
	#ifndef   EM_MEAS_ID_BASE_CTRL_DATA
	  #define EM_MEAS_ID_BASE_CTRL_DATA	(537919568)
	#endif
	#ifndef   EM_MEAS_ID_BUS_DEBUG_DATA
	  #define EM_MEAS_ID_BUS_DEBUG_DATA	(538066944)
	#endif
	#ifndef   EM_MEAS_ID_CAM_OBJECT_LIST
	  #define EM_MEAS_ID_CAM_OBJECT_LIST	(538652672)
	#endif
	#ifndef   EM_MEAS_ID_CONSTRUCTION_SITE
	  #define EM_MEAS_ID_CONSTRUCTION_SITE	(538013696)
	#endif
	#ifndef   EM_MEAS_ID_CUSTOM_OUTPUT
	  #define EM_MEAS_ID_CUSTOM_OUTPUT	(538959872)
	#endif
	#ifndef   EM_MEAS_ID_DEBUG_DATA
	  #define EM_MEAS_ID_DEBUG_DATA	(538063104)
	#endif
	#ifndef   EM_MEAS_ID_EGO_OBJ_SYNC
	  #define EM_MEAS_ID_EGO_OBJ_SYNC	(537997888)
	#endif
	#ifndef   EM_MEAS_ID_EGO_TGT_SYNC
	  #define EM_MEAS_ID_EGO_TGT_SYNC	(537998336)
	#endif
	#ifndef   EM_MEAS_ID_EM_FCT_CYCLE_MODE
	  #define EM_MEAS_ID_EM_FCT_CYCLE_MODE	(537997824)
	#endif
	#ifndef   EM_MEAS_ID_FTRC_SEED_KILL_LIST
	  #define EM_MEAS_ID_FTRC_SEED_KILL_LIST	(538116096)
	#endif
	#ifndef   EM_MEAS_ID_FUN_PRESEL_ACC_DATA
	  #define EM_MEAS_ID_FUN_PRESEL_ACC_DATA	(538185728)
	#endif
	#ifndef   EM_MEAS_ID_FUN_PRESEL_CG_DATA
	  #define EM_MEAS_ID_FUN_PRESEL_CG_DATA	(538189824)
	#endif
	#ifndef   EM_MEAS_ID_GEN_OBJECT_LIST
	  #define EM_MEAS_ID_GEN_OBJECT_LIST	(538640384)
	#endif
	#ifndef   EM_MEAS_ID_ME_INPUT
	  #define EM_MEAS_ID_ME_INPUT	(537935872)
	#endif
	#ifndef   EM_MEAS_ID_ME_OUTPUT
	  #define EM_MEAS_ID_ME_OUTPUT	(538001408)
	#endif
	#ifndef   EM_MEAS_ID_OBJECT_TRACE_LIST
	  #define EM_MEAS_ID_OBJECT_TRACE_LIST	(538005504)
	#endif
	#ifndef   EM_MEAS_ID_OD_PRIVATE_OBJECT_LIST
	  #define EM_MEAS_ID_OD_PRIVATE_OBJECT_LIST	(538443776)
	#endif
	#ifndef   EM_MEAS_ID_OD_RCS_FREQUENCY
	  #define EM_MEAS_ID_OD_RCS_FREQUENCY	(538456065)
	#endif
	#ifndef   EM_MEAS_ID_PC_INPUT_PATCH_LIST
	  #define EM_MEAS_ID_PC_INPUT_PATCH_LIST	(538050816)
	#endif
	#ifndef   EM_MEAS_ID_PED_DEBUG_DATA
	  #define EM_MEAS_ID_PED_DEBUG_DATA	(538013952)
	#endif
	#ifndef   EM_MEAS_ID_PED_OUTPUT
	  #define EM_MEAS_ID_PED_OUTPUT	(538010112)
	#endif
	#ifndef   EM_MEAS_ID_PERF_DEGR_EXT_INPUT
	  #define EM_MEAS_ID_PERF_DEGR_EXT_INPUT	(537919488)
	#endif
	#ifndef   EM_MEAS_ID_PERF_DEG_OUT_DATA
	  #define EM_MEAS_ID_PERF_DEG_OUT_DATA	(537993728)
	#endif
	#ifndef   EM_MEAS_ID_PUBLIC_OBJECT_LIST
	  #define EM_MEAS_ID_PUBLIC_OBJECT_LIST	(537985024)
	#endif
	#ifndef   EM_MEAS_ID_RHC_INPUT
	  #define EM_MEAS_ID_RHC_INPUT	(537997856)
	#endif
	#ifndef   EM_MEAS_ID_STATE
	  #define EM_MEAS_ID_STATE	(538062848)
	#endif
	#ifndef   EM_MEAS_ID_SYS_PERF_MON_STATES
	  #define EM_MEAS_ID_SYS_PERF_MON_STATES	(537919504)
	#endif
	#ifndef   EM_MEAS_ID_VCL_OUTPUT
	  #define EM_MEAS_ID_VCL_OUTPUT	(538009600)
	#endif
	#ifndef   EM_MEAS_ID_VEL_STAT_OBJ
	  #define EM_MEAS_ID_VEL_STAT_OBJ	(537998592)
	#endif
	#ifndef   EM_MEAS_ID_VIEWING_DISTANCE
	  #define EM_MEAS_ID_VIEWING_DISTANCE	(538050560)
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
	#ifndef   FCT_MEAS_ID_CD_CUSTOM_OUTPUT
	  #define FCT_MEAS_ID_CD_CUSTOM_OUTPUT	(539496448)
	#endif
	#ifndef   FCT_MEAS_ID_CGEB_CD_DATA
	  #define FCT_MEAS_ID_CGEB_CD_DATA	(539140096)
	#endif
	#ifndef   FCT_MEAS_ID_CGEB_DIM_DATA
	  #define FCT_MEAS_ID_CGEB_DIM_DATA	(539142144)
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
	#ifndef   FCT_MEAS_ID_CGEB_HEAD_OUTFUNC_DATA
	  #define FCT_MEAS_ID_CGEB_HEAD_OUTFUNC_DATA	(539144192)
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
	#ifndef   FCT_MEAS_ID_HEAD_INPUT_CUSTOM
	  #define FCT_MEAS_ID_HEAD_INPUT_CUSTOM	(539166464)
	#endif
	#ifndef   FCT_MEAS_ID_HEAD_INPUT_GENERIC
	  #define FCT_MEAS_ID_HEAD_INPUT_GENERIC	(539165952)
	#endif
	#ifndef   FCT_MEAS_ID_HEAD_OUTPUT_CUSTOM
	  #define FCT_MEAS_ID_HEAD_OUTPUT_CUSTOM	(539166976)
	#endif
	#ifndef   FCT_MEAS_ID_HEAD_OUTPUT_GENERIC
	  #define FCT_MEAS_ID_HEAD_OUTPUT_GENERIC	(539167232)
	#endif
	#ifndef   FCT_MEAS_ID_LKA_BUS_DEBUG
	  #define FCT_MEAS_ID_LKA_BUS_DEBUG	(539796224)
	#endif
	#ifndef   FCT_MEAS_ID_LKS_LCD_OUTPUT
	  #define FCT_MEAS_ID_LKS_LCD_OUTPUT	(539430656)
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
	#ifndef   FCT_MEAS_ID_SEN_ERROR_OUT_VADDR
	  #define FCT_MEAS_ID_SEN_ERROR_OUT_VADDR	(539063552)
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
	#ifndef   FEX_MEAS_ID_CTRL_BSW_DATA
	  #define FEX_MEAS_ID_CTRL_BSW_DATA	(811597824)
	#endif
	#ifndef   FEX_MEAS_ID_PP_CLASSIFIER_OUTPUT
	  #define FEX_MEAS_ID_PP_CLASSIFIER_OUTPUT	(811663360)
	#endif
	#ifndef   FLSP_MEAS_ID_CALL_INTR_DIST
	  #define FLSP_MEAS_ID_CALL_INTR_DIST	(2154955648)
	#endif
	#ifndef   FLSP_MEAS_ID_DYN_RESPONSE_CURVE
	  #define FLSP_MEAS_ID_DYN_RESPONSE_CURVE	(2154955360)
	#endif
	#ifndef   FLSP_MEAS_ID_IMAGER_CHAR_LEFT
	  #define FLSP_MEAS_ID_IMAGER_CHAR_LEFT	(2154955584)
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
	#ifndef   FLSP_MEAS_ID_STEREO_CAL_ROI
	  #define FLSP_MEAS_ID_STEREO_CAL_ROI	(2154954752)
	#endif
	#ifndef   FLSP_MEAS_ID_STEREO_TRANS_ROT
	  #define FLSP_MEAS_ID_STEREO_TRANS_ROT	(2154954912)
	#endif
	#ifndef   FLSP_MEAS_ID_STEREP_CAL_INTR_LEFT
	  #define FLSP_MEAS_ID_STEREP_CAL_INTR_LEFT	(2155022080)
	#endif
	#ifndef   FLSP_MEAS_ID_STEREP_CAL_INTR_RIGHT
	  #define FLSP_MEAS_ID_STEREP_CAL_INTR_RIGHT	(2154954816)
	#endif
	#ifndef   FLSP_MEAS_ID_TEMP_COMP
	  #define FLSP_MEAS_ID_TEMP_COMP	(2155021632)
	#endif
	#ifndef   FSD_MEAS_ID_ALGO_STATE
	  #define FSD_MEAS_ID_ALGO_STATE	(812722176)
	#endif
	#ifndef   FSD_MEAS_ID_BASE_CTRL_DATA
	  #define FSD_MEAS_ID_BASE_CTRL_DATA	(812742656)
	#endif
	#ifndef   FSD_MEAS_ID_FAN_MODEL_DATA
	  #define FSD_MEAS_ID_FAN_MODEL_DATA	(812732416)
	#endif
	#ifndef   FTRC_MEAS_ID_DEBUGDATA
	  #define FTRC_MEAS_ID_DEBUGDATA	(816988160)
	#endif
	#ifndef   FTRC_MEAS_ID_TARGET_LIST
	  #define FTRC_MEAS_ID_TARGET_LIST	(816979968)
	#endif
	#ifndef   GEN_MEAS_ID_BASE_CTRL_DATA
	  #define GEN_MEAS_ID_BASE_CTRL_DATA	(806359040)
	#endif
	#ifndef   GEN_MEAS_ID_BUS_DEBUG_DATA
	  #define GEN_MEAS_ID_BUS_DEBUG_DATA	(806440960)
	#endif
	#ifndef   GEN_MEAS_ID_CTRL_BSW_DATA
	  #define GEN_MEAS_ID_CTRL_BSW_DATA	(806354944)
	#endif
	#ifndef   GEN_MEAS_ID_DEBUGDATA
	  #define GEN_MEAS_ID_DEBUGDATA	(806355456)
	#endif
	#ifndef   GEN_MEAS_ID_FTRC_DEPTH_FEATURE_LIST
	  #define GEN_MEAS_ID_FTRC_DEPTH_FEATURE_LIST	(806436864)
	#endif
	#ifndef   GEN_MEAS_ID_STATE
	  #define GEN_MEAS_ID_STATE	(806355200)
	#endif
	#ifndef   GEN_MEAS_ID_TARGET_LIST
	  #define GEN_MEAS_ID_TARGET_LIST	(806420480)
	#endif
	#ifndef   HMI_MEAS_ID_INPUT_DATA
	  #define HMI_MEAS_ID_INPUT_DATA	(2197815296)
	#endif
	#ifndef   IC_MEAS_ID_IMAGE_CHARACTERISTICS_EVEN_RIGHT
	  #define IC_MEAS_ID_IMAGE_CHARACTERISTICS_EVEN_RIGHT	(805372416)
	#endif
	#ifndef   IC_MEAS_ID_IMAGE_CHARACTERISTICS_ODD_RIGHT
	  #define IC_MEAS_ID_IMAGE_CHARACTERISTICS_ODD_RIGHT	(805371904)
	#endif
	#ifndef   IC_MEAS_ID_IMAGE_STATISTIC_EVEN_RIGHT
	  #define IC_MEAS_ID_IMAGE_STATISTIC_EVEN_RIGHT	(805372672)
	#endif
	#ifndef   IC_MEAS_ID_IMAGE_STATISTIC_ODD_RIGHT
	  #define IC_MEAS_ID_IMAGE_STATISTIC_ODD_RIGHT	(805372160)
	#endif
	#ifndef   LD_MEAS_ID_CPAR_DATA
	  #define LD_MEAS_ID_CPAR_DATA	(820281344)
	#endif
	#ifndef   LD_MEAS_ID_CTRL_BSW_DATA
	  #define LD_MEAS_ID_CTRL_BSW_DATA	(819986432)
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
	#ifndef   MEAS_ID_MO_TRACES_GLOB_DATA
	  #define MEAS_ID_MO_TRACES_GLOB_DATA	(537993840)
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
	#ifndef   NVM_SR_RTE_MEAS_ID
	  #define NVM_SR_RTE_MEAS_ID	(819462144)
	#endif
	#ifndef   PC_MEAS_ID_BUS_DEBUG_DATA
	  #define PC_MEAS_ID_BUS_DEBUG_DATA	(808452288)
	#endif
	#ifndef   PC_MEAS_ID_CTRL_BSW_DATA
	  #define PC_MEAS_ID_CTRL_BSW_DATA	(808452096)
	#endif
	#ifndef   PC_MEAS_ID_INPUTDATA
	  #define PC_MEAS_ID_INPUTDATA	(808517632)
	#endif
	#ifndef   PC_MEAS_ID_OUTPUTDATA
	  #define PC_MEAS_ID_OUTPUTDATA	(808452308)
	#endif
	#ifndef   PC_MEAS_ID_STATE
	  #define PC_MEAS_ID_STATE	(808452116)
	#endif
	#ifndef   PC_MEAS_ID_SYNC_REF
	  #define PC_MEAS_ID_SYNC_REF	(808452188)
	#endif
	#ifndef   PED_MEAS_ID_CLUSTERED_PEDESTRIANS
	  #define PED_MEAS_ID_CLUSTERED_PEDESTRIANS	(807469056)
	#endif
	#ifndef   PED_MEAS_ID_CLUSTERING_DEBUG
	  #define PED_MEAS_ID_CLUSTERING_DEBUG	(807600128)
	#endif
	#ifndef   PED_MEAS_ID_CTRL_BSW_DATA
	  #define PED_MEAS_ID_CTRL_BSW_DATA	(807403520)
	#endif
	#ifndef   PED_MEAS_ID_ERRORS
	  #define PED_MEAS_ID_ERRORS	(807731200)
	#endif
	#ifndef   PED_MEAS_ID_HYPGEN_DEBUG
	  #define PED_MEAS_ID_HYPGEN_DEBUG	(807510016)
	#endif
	#ifndef   PED_MEAS_ID_IMGTRACKED_PEDESTRIANS
	  #define PED_MEAS_ID_IMGTRACKED_PEDESTRIANS	(807489536)
	#endif
	#ifndef   PED_MEAS_ID_MAIN_DEBUG
	  #define PED_MEAS_ID_MAIN_DEBUG	(807665664)
	#endif
	#ifndef   PED_MEAS_ID_PATCH_CONFIG
	  #define PED_MEAS_ID_PATCH_CONFIG	(807796736)
	#endif
	#ifndef   PED_MEAS_ID_PED_ETHERNET_DEBUG_DATA
	  #define PED_MEAS_ID_PED_ETHERNET_DEBUG_DATA	(808157184)
	#endif
	#ifndef   PED_MEAS_ID_PED_PARAMETERS
	  #define PED_MEAS_ID_PED_PARAMETERS	(808058880)
	#endif
	#ifndef   PED_MEAS_ID_REQ_PORT_HEADERS
	  #define PED_MEAS_ID_REQ_PORT_HEADERS	(808124416)
	#endif
	#ifndef   PV_MEAS_ID_BUS_DEBUG_DATA
	  #define PV_MEAS_ID_BUS_DEBUG_DATA	(813762000)
	#endif
	#ifndef   PV_MEAS_ID_COMP_STATE
	  #define PV_MEAS_ID_COMP_STATE	(813761760)
	#endif
	#ifndef   PV_MEAS_ID_CTRL_BSW_DATA
	  #define PV_MEAS_ID_CTRL_BSW_DATA	(813694976)
	#endif
	#ifndef   PV_MEAS_ID_NVM_DATA
	  #define PV_MEAS_ID_NVM_DATA	(813695008)
	#endif
	#ifndef   PV_MEAS_ID_OUTPUT_DATA
	  #define PV_MEAS_ID_OUTPUT_DATA	(813760512)
	#endif
	#ifndef   PV_MEAS_ID_SYNC_HEADER
	  #define PV_MEAS_ID_SYNC_HEADER	(813761840)
	#endif
	#ifndef   PV_MEAS_ID_VEHICLE_DATA
	  #define PV_MEAS_ID_VEHICLE_DATA	(813695056)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_ALGO_COMP_STATE
	  #define RTE_HLA_MEAS_VADDR_ALGO_COMP_STATE	(824246272)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_BSW_CTRL_DATA
	  #define RTE_HLA_MEAS_VADDR_BSW_CTRL_DATA	(824180736)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_BUS_DEBUG_DATA
	  #define RTE_HLA_MEAS_VADDR_BUS_DEBUG_DATA	(824260608)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_ENV_DATA
	  #define RTE_HLA_MEAS_VADDR_ENV_DATA	(824254464)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_HEADLIGHT_CTRL
	  #define RTE_HLA_MEAS_VADDR_HEADLIGHT_CTRL	(824258560)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_HEADLIGHT_STATE
	  #define RTE_HLA_MEAS_VADDR_HEADLIGHT_STATE	(824186880)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_HLAF_PAR
	  #define RTE_HLA_MEAS_VADDR_HLAF_PAR	(824184832)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_HLAR_PAR
	  #define RTE_HLA_MEAS_VADDR_HLAR_PAR	(824182784)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_HLA_PAR
	  #define RTE_HLA_MEAS_VADDR_HLA_PAR	(824180816)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_HLA_SIG
	  #define RTE_HLA_MEAS_VADDR_HLA_SIG	(824187648)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_NIGHT_VIEW_IN
	  #define RTE_HLA_MEAS_VADDR_NIGHT_VIEW_IN	(824193024)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_NIGHT_VIEW_OUT
	  #define RTE_HLA_MEAS_VADDR_NIGHT_VIEW_OUT	(824259584)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_NVM_LEARN_VALUES_IN
	  #define RTE_HLA_MEAS_VADDR_NVM_LEARN_VALUES_IN	(824188928)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_NVM_LEARN_VALUES_OUT
	  #define RTE_HLA_MEAS_VADDR_NVM_LEARN_VALUES_OUT	(824256512)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_OBJECT_LIST
	  #define RTE_HLA_MEAS_VADDR_OBJECT_LIST	(824246528)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_SEG_LIGHT_LIST
	  #define RTE_HLA_MEAS_VADDR_SEG_LIGHT_LIST	(824262656)
	#endif
	#ifndef   RTE_HLA_MEAS_VADDR_SYNC_REF
	  #define RTE_HLA_MEAS_VADDR_SYNC_REF	(824193536)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_BSW_CONTROL_INPUT
	  #define SAC_RTE_MEAS_ID_IN_BSW_CONTROL_INPUT	(814743552)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_CPAR
	  #define SAC_RTE_MEAS_ID_IN_CPAR	(814751744)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_DIST_TEST
	  #define SAC_RTE_MEAS_ID_IN_DIST_TEST	(814749952)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_ECS
	  #define SAC_RTE_MEAS_ID_IN_ECS	(814749440)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_IMAGE_CHARACTERISTICS
	  #define SAC_RTE_MEAS_ID_IN_IMAGE_CHARACTERISTICS	(814745344)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_MONO_CALIBRATION_EOL_LEFT
	  #define SAC_RTE_MEAS_ID_IN_MONO_CALIBRATION_EOL_LEFT	(814747648)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_MONO_CALIBRATION_EOL_RIGHT
	  #define SAC_RTE_MEAS_ID_IN_MONO_CALIBRATION_EOL_RIGHT	(814744320)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_MONO_CALIBRATION_LANE
	  #define SAC_RTE_MEAS_ID_IN_MONO_CALIBRATION_LANE	(814748928)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_NVM
	  #define SAC_RTE_MEAS_ID_IN_NVM	(814747904)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_STEREO_ROI
	  #define SAC_RTE_MEAS_ID_IN_STEREO_ROI	(814745856)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_VEH_DYN
	  #define SAC_RTE_MEAS_ID_IN_VEH_DYN	(814744832)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_VEH_PAR
	  #define SAC_RTE_MEAS_ID_IN_VEH_PAR	(814745088)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_IN_WSM
	  #define SAC_RTE_MEAS_ID_IN_WSM	(814745600)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_ALGO_COMP_STATE
	  #define SAC_RTE_MEAS_ID_OUT_ALGO_COMP_STATE	(814843648)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_DEBUG
	  #define SAC_RTE_MEAS_ID_OUT_DEBUG	(814819584)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_DIAG_STATUS_CALIB_STEREO
	  #define SAC_RTE_MEAS_ID_OUT_DIAG_STATUS_CALIB_STEREO	(814843904)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_DIST_TEST
	  #define SAC_RTE_MEAS_ID_OUT_DIST_TEST	(814843392)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_ECS
	  #define SAC_RTE_MEAS_ID_OUT_ECS	(814843136)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_FEX_CONTROL
	  #define SAC_RTE_MEAS_ID_OUT_FEX_CONTROL	(814809344)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_MONO_CALIBRATION
	  #define SAC_RTE_MEAS_ID_OUT_MONO_CALIBRATION	(814841856)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_MONO_CALIBRATION_RECTIFICATION
	  #define SAC_RTE_MEAS_ID_OUT_MONO_CALIBRATION_RECTIFICATION	(814842624)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_NVM
	  #define SAC_RTE_MEAS_ID_OUT_NVM	(814814208)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_OUTPUT
	  #define SAC_RTE_MEAS_ID_OUT_OUTPUT	(814819072)
	#endif
	#ifndef   SAC_RTE_MEAS_ID_OUT_STEREO_CALIBRATION
	  #define SAC_RTE_MEAS_ID_OUT_STEREO_CALIBRATION	(814817280)
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
	#ifndef   SCB_MEAS_ID_ERROR_DATA
	  #define SCB_MEAS_ID_ERROR_DATA	(872951808)
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
	#ifndef   SCB_MEAS_ID_KERNEL_OUTPUT
	  #define SCB_MEAS_ID_KERNEL_OUTPUT	(872943616)
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
	#ifndef   SIB_MEAS_ID_ALGO_STATE
	  #define SIB_MEAS_ID_ALGO_STATE	(815888384)
	#endif
	#ifndef   SIB_MEAS_ID_BASE_CTRL_DATA
	  #define SIB_MEAS_ID_BASE_CTRL_DATA	(815908864)
	#endif
	#ifndef   SIB_MEAS_ID_FLOXEL_DEBUG_DATA
	  #define SIB_MEAS_ID_FLOXEL_DEBUG_DATA	(815857664)
	#endif
	#ifndef   SIB_MEAS_ID_ROAD_MODEL_DATA
	  #define SIB_MEAS_ID_ROAD_MODEL_DATA	(815898624)
	#endif
	#ifndef   SR_MEAS_ID_MEAS_OUTPUT_A
	  #define SR_MEAS_ID_MEAS_OUTPUT_A	(118489088)
	#endif
	#ifndef   SR_MEAS_ID_MEAS_OUTPUT_B
	  #define SR_MEAS_ID_MEAS_OUTPUT_B	(118509568)
	#endif
	#ifndef   SR_RTE_MEAS_BUSDEBUGDATA_A
	  #define SR_RTE_MEAS_BUSDEBUGDATA_A	(818942208)
	#endif
	#ifndef   SR_RTE_MEAS_BUSDEBUGDATA_B
	  #define SR_RTE_MEAS_BUSDEBUGDATA_B	(819224832)
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
	  #define SR_RTE_MEAS_ID_CODING_PARAMS	(819466240)
	#endif
	#ifndef   SR_RTE_MEAS_ID_OUTPUT
	  #define SR_RTE_MEAS_ID_OUTPUT	(819204096)
	#endif
	#ifndef   SR_RTE_MEAS_SYNCREF_A
	  #define SR_RTE_MEAS_SYNCREF_A	(818942464)
	#endif
	#ifndef   SR_RTE_MEAS_SYNCREF_B
	  #define SR_RTE_MEAS_SYNCREF_B	(819225088)
	#endif
	#ifndef   SR_RTE_MEAS_WRP_STATE_A
	  #define SR_RTE_MEAS_WRP_STATE_A	(818942976)
	#endif
	#ifndef   SR_RTE_MEAS_WRP_STATE_B
	  #define SR_RTE_MEAS_WRP_STATE_B	(819225344)
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
	  #define TSA_RTE_MEAS_ID_ALGO_COMP_STATE	(537150464)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_BASE_CTRL_DATA
	  #define TSA_RTE_MEAS_ID_BASE_CTRL_DATA	(537178368)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_BUS_DEBUG_DATA
	  #define TSA_RTE_MEAS_ID_BUS_DEBUG_DATA	(537178112)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_CODING_PARAMS
	  #define TSA_RTE_MEAS_ID_CODING_PARAMS	(537150976)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_CTRL_BSW_DATA
	  #define TSA_RTE_MEAS_ID_CTRL_BSW_DATA	(537149440)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_CUSTOM_INPUT
	  #define TSA_RTE_MEAS_ID_CUSTOM_INPUT	(537149952)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_INPUT_GPS
	  #define TSA_RTE_MEAS_ID_INPUT_GPS	(537149696)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_NVM_STATE
	  #define TSA_RTE_MEAS_ID_NVM_STATE	(537150720)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_OUTPUT_CUSTOM
	  #define TSA_RTE_MEAS_ID_OUTPUT_CUSTOM	(537169920)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_OUTPUT_RESULTS
	  #define TSA_RTE_MEAS_ID_OUTPUT_RESULTS	(537153536)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_OUTPUT_SIGN
	  #define TSA_RTE_MEAS_ID_OUTPUT_SIGN	(537157632)
	#endif
	#ifndef   TSA_RTE_MEAS_ID_SYNC_REF
	  #define TSA_RTE_MEAS_ID_SYNC_REF	(537151232)
	#endif
	#ifndef   VCL_MEAS_ID_BASE_CTRL_DATA
	  #define VCL_MEAS_ID_BASE_CTRL_DATA	(809500704)
	#endif
	#ifndef   VCL_MEAS_ID_BUS_DEBUG_DATA
	  #define VCL_MEAS_ID_BUS_DEBUG_DATA	(809696512)
	#endif
	#ifndef   VCL_MEAS_ID_COMP_STATE
	  #define VCL_MEAS_ID_COMP_STATE	(809696768)
	#endif
	#ifndef   VCL_MEAS_ID_DEBUG_DATA
	  #define VCL_MEAS_ID_DEBUG_DATA	(809697280)
	#endif
	#ifndef   VCL_MEAS_ID_MEAS_LIST
	  #define VCL_MEAS_ID_MEAS_LIST	(809566208)
	#endif
	#ifndef   VCL_MEAS_ID_REQUEST_PORT_DATA
	  #define VCL_MEAS_ID_REQUEST_PORT_DATA	(809500928)
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
	#ifndef   VODCA_MEAS_ID_CLASS_RESULTS
	  #define VODCA_MEAS_ID_CLASS_RESULTS	(825360384)
	#endif
	#ifndef   VODCA_MEAS_ID_CTRL_BSW_DATA
	  #define VODCA_MEAS_ID_CTRL_BSW_DATA	(825229312)
	#endif
	#ifndef   VODCA_MEAS_ID_DEBUG
	  #define VODCA_MEAS_ID_DEBUG	(825425920)
	#endif
	#ifndef   VODCA_MEAS_ID_ERRORS
	  #define VODCA_MEAS_ID_ERRORS	(825294848)
	#endif
	#ifndef   VODCA_MEAS_ID_REQ_PORT_HEADERS
	  #define VODCA_MEAS_ID_REQ_PORT_HEADERS	(825233408)
	#endif

/* typedef SymbolicConstants */
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
	#ifndef   CFG_FCT_CD_CMS
	  #define CFG_FCT_CD_CMS	(0)
	#endif
	#ifndef   CFG_FCT_VEH_EBA_INTF
	  #define CFG_FCT_VEH_EBA_INTF	(1)
	#endif
	#ifndef   CIPP_NUMB_OF_HIST_COLS
	  #define CIPP_NUMB_OF_HIST_COLS	(256)
	#endif
	#ifndef   ECM_RTE_MAX_CIRCLE_LIST_ELEMENTS
	  #define ECM_RTE_MAX_CIRCLE_LIST_ELEMENTS	(10)
	#endif
	#ifndef   ECM_RTE_MAX_PATTERN_DIMENSION
	  #define ECM_RTE_MAX_PATTERN_DIMENSION	(32)
	#endif
	#ifndef   ECM_RTE_MAX_PATTERN_DIMENSION_SQUARED
	  #define ECM_RTE_MAX_PATTERN_DIMENSION_SQUARED	(1024)
	#endif
	#ifndef   EMB0_N_FREE_FORM_OBJECTS
	  #define EMB0_N_FREE_FORM_OBJECTS	(10)
	#endif
	#ifndef   EMB0_N_FREE_FORM_POINTS
	  #define EMB0_N_FREE_FORM_POINTS	(13)
	#endif
	#ifndef   EMB0_N_SCAM_OBJECTS
	  #define EMB0_N_SCAM_OBJECTS	(40)
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
	#ifndef   EM_N_OBJECTS
	  #define EM_N_OBJECTS	(40)
	#endif
	#ifndef   FCT_CFG_VEH_CUSTOM_INPUT
	  #define FCT_CFG_VEH_CUSTOM_INPUT	(0)
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
	#ifndef   FSD_MAX_NMB_SEGMENTS
	  #define FSD_MAX_NMB_SEGMENTS	(80)
	#endif
	#ifndef   FTRC_EMO_MAX_SEED_ROIS
	  #define FTRC_EMO_MAX_SEED_ROIS	(10)
	#endif
	#ifndef   FTRC_EMO_SEED_BASE_ID
	  #define FTRC_EMO_SEED_BASE_ID	(0)
	#endif
	#ifndef   FTRC_MAX_FEATURES
	  #define FTRC_MAX_FEATURES	(500)
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
	#ifndef   GENERIC_BUS_DEBUG_DATA_LENGTH
	  #define GENERIC_BUS_DEBUG_DATA_LENGTH	(20)
	#endif
	#ifndef   GEN_INVALID_ASSOCIATED_COLUMN
	  #define GEN_INVALID_ASSOCIATED_COLUMN	(65535)
	#endif
	#ifndef   GEN_INVALID_OBJECT_ID
	  #define GEN_INVALID_OBJECT_ID	(255)
	#endif
	#ifndef   GEN_NUMBER_OF_DEPTH_ROWS
	  #define GEN_NUMBER_OF_DEPTH_ROWS	(5)
	#endif
	#ifndef   GEN_NUMBER_OF_SHAPE_FLOW_COLS
	  #define GEN_NUMBER_OF_SHAPE_FLOW_COLS	(850)
	#endif
	#ifndef   GEN_NUMBER_OF_TARGETS
	  #define GEN_NUMBER_OF_TARGETS	(80)
	#endif
	#ifndef   IC_RESPONSE_CURVE_LENGTH
	  #define IC_RESPONSE_CURVE_LENGTH	(5)
	#endif
	#ifndef   LD_INTERFACE_CPAR_LEN_CONFIG_DATA
	  #define LD_INTERFACE_CPAR_LEN_CONFIG_DATA	(8)
	#endif
	#ifndef   LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE
	  #define LD_INTERFACE_MAX_NUM_MARKERS_PER_SIDE	(3)
	#endif
	#ifndef   LD_NUM_MODEL_RESIDUUM_SAMPLE_POINTS
	  #define LD_NUM_MODEL_RESIDUUM_SAMPLE_POINTS	(10)
	#endif
	#ifndef   MAX_NUMBER_FORESIGHTINDICATORS
	  #define MAX_NUMBER_FORESIGHTINDICATORS	(10)
	#endif
	#ifndef   MAX_NUM_OF_HYPS
	  #define MAX_NUM_OF_HYPS	(12)
	#endif
	#ifndef   MAX_NUM_VODCA_CLASSIFIERS_PER_PATCH
	  #define MAX_NUM_VODCA_CLASSIFIERS_PER_PATCH	(4)
	#endif
	#ifndef   MFC_ECU_STATE_TEMPERATURE_ARRAY_SIZE
	  #define MFC_ECU_STATE_TEMPERATURE_ARRAY_SIZE	(10)
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
	  #define MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L0	(2048)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L1
	  #define MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L1	(1024)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L2
	  #define MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L2	(512)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L3
	  #define MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L3	(256)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L4
	  #define MFC_REDUCED_ROI_16BIT_BYTE_PITCH_L4	(128)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L0
	  #define MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L0	(1024)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L1
	  #define MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L1	(512)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L2
	  #define MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L2	(256)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L3
	  #define MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L3	(128)
	#endif
	#ifndef   MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L4
	  #define MFC_REDUCED_ROI_16BIT_PIXEL_PITCH_L4	(64)
	#endif
	#ifndef   MFC_REDUCED_ROI_8BIT_PITCH_L0
	  #define MFC_REDUCED_ROI_8BIT_PITCH_L0	(1024)
	#endif
	#ifndef   MFC_REDUCED_ROI_8BIT_PITCH_L1
	  #define MFC_REDUCED_ROI_8BIT_PITCH_L1	(512)
	#endif
	#ifndef   MFC_REDUCED_ROI_8BIT_PITCH_L2
	  #define MFC_REDUCED_ROI_8BIT_PITCH_L2	(256)
	#endif
	#ifndef   MFC_REDUCED_ROI_8BIT_PITCH_L3
	  #define MFC_REDUCED_ROI_8BIT_PITCH_L3	(128)
	#endif
	#ifndef   MFC_REDUCED_ROI_8BIT_PITCH_L4
	  #define MFC_REDUCED_ROI_8BIT_PITCH_L4	(64)
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
	#ifndef   MFC_VERSION_INFO_LENGTH
	  #define MFC_VERSION_INFO_LENGTH	(51)
	#endif
	#ifndef   NUMBER_OF_DIFF_MEAS
	  #define NUMBER_OF_DIFF_MEAS	(25)
	#endif
	#ifndef   NUMBER_OF_EDGE_MEAS
	  #define NUMBER_OF_EDGE_MEAS	(25)
	#endif
	#ifndef   NUMBER_OF_LIGHTS_PER_CLUSTER
	  #define NUMBER_OF_LIGHTS_PER_CLUSTER	(10)
	#endif
	#ifndef   NUMBER_OF_LIGHT_CLUSTERS
	  #define NUMBER_OF_LIGHT_CLUSTERS	(25)
	#endif
	#ifndef   NUMBER_OF_OBJECTS
	  #define NUMBER_OF_OBJECTS	(40)
	#endif
	#ifndef   NUMBER_OF_PED_CLASSIFIERS
	  #define NUMBER_OF_PED_CLASSIFIERS	(8)
	#endif
	#ifndef   NUMBER_OF_PED_REF_OBJECTS
	  #define NUMBER_OF_PED_REF_OBJECTS	(10)
	#endif
	#ifndef   NUMBER_OF_REFERENCE_POINTS
	  #define NUMBER_OF_REFERENCE_POINTS	(3)
	#endif
	#ifndef   NUMBER_OF_VCL_TRACKS
	  #define NUMBER_OF_VCL_TRACKS	(10)
	#endif
	#ifndef   NUMBER_OF_VODCA_CLASSIFIERS
	  #define NUMBER_OF_VODCA_CLASSIFIERS	(8)
	#endif
	#ifndef   NUMBER_OF_VODCA_PATCHES
	  #define NUMBER_OF_VODCA_PATCHES	(128)
	#endif
	#ifndef   NUMBER_OF_VODCA_REF_OBJECTS
	  #define NUMBER_OF_VODCA_REF_OBJECTS	(10)
	#endif
	#ifndef   NVM_TSA_RTE_STATE_FP_MAX_LEN
	  #define NVM_TSA_RTE_STATE_FP_MAX_LEN	(128)
	#endif
	#ifndef   NVM_TSA_RTE_STATE_FV_MAX_LEN
	  #define NVM_TSA_RTE_STATE_FV_MAX_LEN	(96)
	#endif
	#ifndef   PC_BIAS_DEFAULT
	  #define PC_BIAS_DEFAULT	(0)
	#endif
	#ifndef   PC_BIAS_MAX
	  #define PC_BIAS_MAX	(4000)
	#endif
	#ifndef   PC_BIAS_MIN
	  #define PC_BIAS_MIN	(-4000)
	#endif
	#ifndef   PC_GAIN_DEFAULT
	  #define PC_GAIN_DEFAULT	(1)
	#endif
	#ifndef   PC_GAIN_MAX
	  #define PC_GAIN_MAX	(100)
	#endif
	#ifndef   PC_GAIN_MIN
	  #define PC_GAIN_MIN	(0.01)
	#endif
	#ifndef   PC_ID_VALUE_DEFAULT
	  #define PC_ID_VALUE_DEFAULT	(255)
	#endif
	#ifndef   PC_ID_VALUE_MAX
	  #define PC_ID_VALUE_MAX	(254)
	#endif
	#ifndef   PC_ID_VALUE_MIN
	  #define PC_ID_VALUE_MIN	(0)
	#endif
	#ifndef   PC_INIT_SHIFT_DEFAULT
	  #define PC_INIT_SHIFT_DEFAULT	(-1)
	#endif
	#ifndef   PC_INIT_SHIFT_MAX
	  #define PC_INIT_SHIFT_MAX	(63)
	#endif
	#ifndef   PC_INIT_SHIFT_MIN
	  #define PC_INIT_SHIFT_MIN	(-1)
	#endif
	#ifndef   PC_MAX_NMB_PATCHES
	  #define PC_MAX_NMB_PATCHES	(100)
	#endif
	#ifndef   PC_SCALE_DEFAULT
	  #define PC_SCALE_DEFAULT	(0)
	#endif
	#ifndef   PC_SCALE_MAX
	  #define PC_SCALE_MAX	(0.5)
	#endif
	#ifndef   PC_SCALE_MIN
	  #define PC_SCALE_MIN	(-0.5)
	#endif
	#ifndef   PC_SEARCH_RANGE_DEFAULT
	  #define PC_SEARCH_RANGE_DEFAULT	(4)
	#endif
	#ifndef   PC_SEARCH_RANGE_DISP_DEFAULT
	  #define PC_SEARCH_RANGE_DISP_DEFAULT	(-1)
	#endif
	#ifndef   PC_SEARCH_RANGE_DISP_MAX
	  #define PC_SEARCH_RANGE_DISP_MAX	(63)
	#endif
	#ifndef   PC_SEARCH_RANGE_DISP_MIN
	  #define PC_SEARCH_RANGE_DISP_MIN	(-1)
	#endif
	#ifndef   PC_SEARCH_RANGE_MAX
	  #define PC_SEARCH_RANGE_MAX	(10)
	#endif
	#ifndef   PC_SEARCH_RANGE_MIN
	  #define PC_SEARCH_RANGE_MIN	(1)
	#endif
	#ifndef   PED_MAX_CLUSTERED_PEDS
	  #define PED_MAX_CLUSTERED_PEDS	(15)
	#endif
	#ifndef   PED_MAX_IMGTRACKED_PEDS
	  #define PED_MAX_IMGTRACKED_PEDS	(15)
	#endif
	#ifndef   RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS
	  #define RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS	(5)
	#endif
	#ifndef   RTE_HLAF_MATRIX_MAX_NUM_LIGHT_AREAS
	  #define RTE_HLAF_MATRIX_MAX_NUM_LIGHT_AREAS	(5)
	#endif
	#ifndef   RTE_HLAF_NIGHTVIEW_OBJECT_LIST_LENGTH
	  #define RTE_HLAF_NIGHTVIEW_OBJECT_LIST_LENGTH	(2)
	#endif
	#ifndef   RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH
	  #define RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH	(90)
	#endif
	#ifndef   RTE_HLAR_OBJECT_LIST_LENGTH
	  #define RTE_HLAR_OBJECT_LIST_LENGTH	(35)
	#endif
	#ifndef   RTE_HLA_NUM_DIMM_AREAS
	  #define RTE_HLA_NUM_DIMM_AREAS	(5)
	#endif
	#ifndef   RTE_HLA_NUM_DIMM_AREAS_BORDERS
	  #define RTE_HLA_NUM_DIMM_AREAS_BORDERS	(4)
	#endif
	#ifndef   RTE_HLA_SEG_LIGHT_LIST_LENGTH
	  #define RTE_HLA_SEG_LIGHT_LIST_LENGTH	(60)
	#endif
	#ifndef   RTE_HLA_SEG_MAX_NUM_LEVELS
	  #define RTE_HLA_SEG_MAX_NUM_LEVELS	(8)
	#endif
	#ifndef   RTE_HLA_SEG_REGION_LIST_LENGTH
	  #define RTE_HLA_SEG_REGION_LIST_LENGTH	(100)
	#endif
	#ifndef   RTE_PV_MAX_NUM_REL_PROFILE_POINTS_PER_TRACK
	  #define RTE_PV_MAX_NUM_REL_PROFILE_POINTS_PER_TRACK	(72)
	#endif
	#ifndef   RTE_PV_MAX_NUM_VEH_SIGNALS_PER_ALGO_CYCLE
	  #define RTE_PV_MAX_NUM_VEH_SIGNALS_PER_ALGO_CYCLE	(80)
	#endif
	#ifndef   SAC_RTE_HIL_SIM_BUFFER_SIZE
	  #define SAC_RTE_HIL_SIM_BUFFER_SIZE	(2097152)
	#endif
	#ifndef   SAC_RTE_KMETERS_LAST_ERROR_SIZE
	  #define SAC_RTE_KMETERS_LAST_ERROR_SIZE	(10)
	#endif
	#ifndef   SAC_RTE_LAST_ERROR_SIZE
	  #define SAC_RTE_LAST_ERROR_SIZE	(10)
	#endif
	#ifndef   SAC_RTE_LUT_ENTRY_COUNT
	  #define SAC_RTE_LUT_ENTRY_COUNT	(1122)
	#endif
	#ifndef   SAC_RTE_NUMBER_OF_RDU_OBJECTS
	  #define SAC_RTE_NUMBER_OF_RDU_OBJECTS	(40)
	#endif
	#ifndef   SAC_RTE_NUMBER_USED_FRAMES_HISTOGRAM_SIZE
	  #define SAC_RTE_NUMBER_USED_FRAMES_HISTOGRAM_SIZE	(6)
	#endif
	#ifndef   SAC_RTE_RECTIFICATION_ERROR_HISTOGRAM_SIZE
	  #define SAC_RTE_RECTIFICATION_ERROR_HISTOGRAM_SIZE	(12)
	#endif
	#ifndef   SAC_RTE_TEMPMOD_ANGLE_NO_NODES
	  #define SAC_RTE_TEMPMOD_ANGLE_NO_NODES	(16)
	#endif
	#ifndef   SAC_RTE_WSM_COEFFICIENT_COUNT
	  #define SAC_RTE_WSM_COEFFICIENT_COUNT	(5)
	#endif
	#ifndef   SIB_FLOW_HISTOGRAM_SIZE
	  #define SIB_FLOW_HISTOGRAM_SIZE	(4)
	#endif
	#ifndef   SIB_FLOXEL_FAT_MAX_CATCH_DIST_M
	  #define SIB_FLOXEL_FAT_MAX_CATCH_DIST_M	(1)
	#endif
	#ifndef   SIB_FLOXEL_FAT_MAX_DISP_JUMP_PX
	  #define SIB_FLOXEL_FAT_MAX_DISP_JUMP_PX	(2)
	#endif
	#ifndef   SIB_FLOXEL_LUT_DIST_FROM_DISP_MAX_DIST_M
	  #define SIB_FLOXEL_LUT_DIST_FROM_DISP_MAX_DIST_M	(200)
	#endif
	#ifndef   SIB_FLOXEL_LUT_DIST_FROM_DISP_SIZE
	  #define SIB_FLOXEL_LUT_DIST_FROM_DISP_SIZE	(1024)
	#endif
	#ifndef   SIB_FLOXEL_MAX_VAR_DISP_PX2
	  #define SIB_FLOXEL_MAX_VAR_DISP_PX2	(4)
	#endif
	#ifndef   SIB_FLOXEL_MAX_VAR_FLOW_PX2
	  #define SIB_FLOXEL_MAX_VAR_FLOW_PX2	(4)
	#endif
	#ifndef   SIB_FLOXEL_MIN_NMB_VALID_PX
	  #define SIB_FLOXEL_MIN_NMB_VALID_PX	(1)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_CATCH_DISTANCE_M
	  #define SIB_FLOXEL_PBOOST_CATCH_DISTANCE_M	(0.3)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_CATCH_DISTANCE_PX
	  #define SIB_FLOXEL_PBOOST_CATCH_DISTANCE_PX	(1)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_ENABLE
	  #define SIB_FLOXEL_PBOOST_ENABLE	(1)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_FLEX_ENV_ENABLE
	  #define SIB_FLOXEL_PBOOST_FLEX_ENV_ENABLE	(1)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_FLEX_ENV_MIN_LONG_RANGE_1_M
	  #define SIB_FLOXEL_PBOOST_FLEX_ENV_MIN_LONG_RANGE_1_M	(3)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_FLEX_ENV_MIN_LONG_RANGE_2_M
	  #define SIB_FLOXEL_PBOOST_FLEX_ENV_MIN_LONG_RANGE_2_M	(6)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_FLEX_ENV_V_EGO1_M_PER_S
	  #define SIB_FLOXEL_PBOOST_FLEX_ENV_V_EGO1_M_PER_S	(10)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_FLEX_ENV_V_EGO2_M_PER_S
	  #define SIB_FLOXEL_PBOOST_FLEX_ENV_V_EGO2_M_PER_S	(20)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_FLEX_ENV_V_LAT_M_PER_S
	  #define SIB_FLOXEL_PBOOST_FLEX_ENV_V_LAT_M_PER_S	(1)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_MAX_LAT_RANGE_M
	  #define SIB_FLOXEL_PBOOST_MAX_LAT_RANGE_M	(4)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_MAX_LONG_RANGE_M
	  #define SIB_FLOXEL_PBOOST_MAX_LONG_RANGE_M	(28)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_MAX_NMB_SEEDS
	  #define SIB_FLOXEL_PBOOST_MAX_NMB_SEEDS	(200)
	#endif
	#ifndef   SIB_FLOXEL_PBOOST_MAX_NMB_STARTPX_STRIDE
	  #define SIB_FLOXEL_PBOOST_MAX_NMB_STARTPX_STRIDE	(2)
	#endif
	#ifndef   SIB_FLOXEL_SIZE_BYTES
	  #define SIB_FLOXEL_SIZE_BYTES	(44)
	#endif
	#ifndef   SIB_FLOXEL_SIZE_HORIZONTAL_PX
	  #define SIB_FLOXEL_SIZE_HORIZONTAL_PX	(6)
	#endif
	#ifndef   SIB_FLOXEL_SIZE_VERTICAL_PX
	  #define SIB_FLOXEL_SIZE_VERTICAL_PX	(6)
	#endif
	#ifndef   SIB_FLOXEL_TABLE_HEIGHT
	  #define SIB_FLOXEL_TABLE_HEIGHT	(73)
	#endif
	#ifndef   SIB_FLOXEL_TABLE_SIZE
	  #define SIB_FLOXEL_TABLE_SIZE	(12410)
	#endif
	#ifndef   SIB_FLOXEL_TABLE_WIDTH
	  #define SIB_FLOXEL_TABLE_WIDTH	(170)
	#endif
	#ifndef   SIB_MEAS_RANGE_LAT_MAX_M
	  #define SIB_MEAS_RANGE_LAT_MAX_M	(20)
	#endif
	#ifndef   SIB_MEAS_RANGE_LAT_MIN_M
	  #define SIB_MEAS_RANGE_LAT_MIN_M	(-20)
	#endif
	#ifndef   SIB_MEAS_RANGE_LONG_MAX_M
	  #define SIB_MEAS_RANGE_LONG_MAX_M	(50)
	#endif
	#ifndef   SIB_MEAS_RANGE_LONG_MIN_M
	  #define SIB_MEAS_RANGE_LONG_MIN_M	(2)
	#endif
	#ifndef   SIB_MEAS_RANGE_VERT_MAX_M
	  #define SIB_MEAS_RANGE_VERT_MAX_M	(3)
	#endif
	#ifndef   SIB_MEAS_RANGE_VERT_MIN_M
	  #define SIB_MEAS_RANGE_VERT_MIN_M	(-2)
	#endif
	#ifndef   SIB_SCRATCH_BUFFER_SIZE
	  #define SIB_SCRATCH_BUFFER_SIZE	(8192)
	#endif
	#ifndef   SIZE_OF_HIDDEN_NEURON_RESULTS
	  #define SIZE_OF_HIDDEN_NEURON_RESULTS	(4)
	#endif
	#ifndef   SIZE_OF_RESULT_ARRAY
	  #define SIZE_OF_RESULT_ARRAY	(512)
	#endif
	#ifndef   SR_RTE_COMMUNICATION_BUFFER_LENGTH
	  #define SR_RTE_COMMUNICATION_BUFFER_LENGTH	(1468007)
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
	#ifndef   SR_RTE_PERS_STATE_FP_MAX_LEN
	  #define SR_RTE_PERS_STATE_FP_MAX_LEN	(80)
	#endif
	#ifndef   SR_RTE_PERS_STATE_FV_MAX_LEN
	  #define SR_RTE_PERS_STATE_FV_MAX_LEN	(28)
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
	#ifndef   SW_FW_ACTL_MODE_SAFE_COMMUNICATION
	  #define SW_FW_ACTL_MODE_SAFE_COMMUNICATION	(16)
	#endif
	#ifndef   SW_FW_ACTL_MODE_SAFE_SILENT
	  #define SW_FW_ACTL_MODE_SAFE_SILENT	(15)
	#endif
	#ifndef   SW_FW_ACTL_MODE_STARTUP_SOC
	  #define SW_FW_ACTL_MODE_STARTUP_SOC	(12)
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
	  #define SW_FW_CRASHDUMP_SIZE	(100)
	#endif
	#ifndef   SW_FW_DEM_BUFFER_SIZE
	  #define SW_FW_DEM_BUFFER_SIZE	(1024)
	#endif
	#ifndef   SW_FW_LAB_MODE_DEMO_ON
	  #define SW_FW_LAB_MODE_DEMO_ON	(926365495)
	#endif
	#ifndef   SW_FW_LAB_MODE_HIL_ON
	  #define SW_FW_LAB_MODE_HIL_ON	(2913316261)
	#endif
	#ifndef   SW_FW_LAB_MODE_MTS_OFF
	  #define SW_FW_LAB_MODE_MTS_OFF	(1381651034)
	#endif
	#ifndef   SW_FW_LAB_MODE_OFF
	  #define SW_FW_LAB_MODE_OFF	(0)
	#endif
	#ifndef   SW_FW_MAX_NUM_RESERVED
	  #define SW_FW_MAX_NUM_RESERVED	(7)
	#endif
	#ifndef   SW_FW_VERSION_NUBER
	  #define SW_FW_VERSION_NUBER	(2)
	#endif
	#ifndef   SW_FW_XCP_DATA_SIZE
	  #define SW_FW_XCP_DATA_SIZE	(1024)
	#endif
	#ifndef   SW_HMI_VERSION_NUBER
	  #define SW_HMI_VERSION_NUBER	(1)
	#endif
	#ifndef   TRACE_NO_OF_TRACES
	  #define TRACE_NO_OF_TRACES	(10)
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
	  #define TSA_RTE_SLA_NUM_RESULTS	(2)
	#endif
	#ifndef   TSA_RTE_SPEEDFORESIGHTDATA_LEN
	  #define TSA_RTE_SPEEDFORESIGHTDATA_LEN	(10)
	#endif
	#ifndef   VCL_ASSOC_LIST_SIZE
	  #define VCL_ASSOC_LIST_SIZE	(80)
	#endif
	#ifndef   VDY_SWA_RAT_NO_ANGL
	  #define VDY_SWA_RAT_NO_ANGL	(2)
	#endif
	#ifndef   VDY_SWA_RAT_NO_VELO
	  #define VDY_SWA_RAT_NO_VELO	(2)
	#endif
	#ifndef   VODCA_CLASSIFIER_NAME_LEN
	  #define VODCA_CLASSIFIER_NAME_LEN	(64)
	#endif
	#ifndef   VODCA_LRF_MAX_FEATURES
	  #define VODCA_LRF_MAX_FEATURES	(6272)
	#endif
	#ifndef   VODCA_LRF_MAX_HIDDEN_NEURONS
	  #define VODCA_LRF_MAX_HIDDEN_NEURONS	(4)
	#endif
	#ifndef   VODCA_LRF_WEIGHT_LIST_SIZE
	  #define VODCA_LRF_WEIGHT_LIST_SIZE	(25088)
	#endif
	#ifndef   VODCA_MAX_CLASSIFIER_VECTOR_LEN
	  #define VODCA_MAX_CLASSIFIER_VECTOR_LEN	(50000)
	#endif
	#ifndef   VODCA_MAX_NR_OF_HOGFEATURES
	  #define VODCA_MAX_NR_OF_HOGFEATURES	(4096)
	#endif
	#ifndef   VODCA_MAX_NR_OF_RECEPTIVE_FIELDS
	  #define VODCA_MAX_NR_OF_RECEPTIVE_FIELDS	(48)
	#endif
	#ifndef   VODCA_RECEPTIVE_FIELD_LIST_SIZE
	  #define VODCA_RECEPTIVE_FIELD_LIST_SIZE	(1200)
	#endif
	#ifndef   VODCA_RECEPTIVE_FIELD_SIZE
	  #define VODCA_RECEPTIVE_FIELD_SIZE	(5)
	#endif

/* typedef InterfaceVersion */
	#ifndef   BASE_CTRL_DATA_INTFVER
	  #define BASE_CTRL_DATA_INTFVER	(1)
	#endif
	#ifndef   BSW_VDY_CTRL_DATA_INTFVER
	  #define BSW_VDY_CTRL_DATA_INTFVER	(2)
	#endif
	#ifndef   BSW_VEH_PAR_INTFVER
	  #define BSW_VEH_PAR_INTFVER	(8)
	#endif
	#ifndef   BSW_VEH_SIG_INTFVER
	  #define BSW_VEH_SIG_INTFVER	(8)
	#endif
	#ifndef   CB_HEATING_REQUEST_INTFVER
	  #define CB_HEATING_REQUEST_INTFVER	(2)
	#endif
	#ifndef   CB_PROVIDED_OUTPUTS_INTFVER
	  #define CB_PROVIDED_OUTPUTS_INTFVER	(5)
	#endif
	#ifndef   CIPP_IMG_STAT_INTFVER
	  #define CIPP_IMG_STAT_INTFVER	(1)
	#endif
	#ifndef   CIPP_WBR_INTFVER
	  #define CIPP_WBR_INTFVER	(1)
	#endif
	#ifndef   COMP_STATE_INTFVER
	  #define COMP_STATE_INTFVER	(2)
	#endif
	#ifndef   CPAR_ECM_RTE_INTFVER
	  #define CPAR_ECM_RTE_INTFVER	(1)
	#endif
	#ifndef   CPAR_EMO_INTFVER
	  #define CPAR_EMO_INTFVER	(5)
	#endif
	#ifndef   CPAR_FCT_PARAMETERS_INTFVER
	  #define CPAR_FCT_PARAMETERS_INTFVER	(3)
	#endif
	#ifndef   CPAR_HLAF_PARAMETER_INTFVER
	  #define CPAR_HLAF_PARAMETER_INTFVER	(3)
	#endif
	#ifndef   CPAR_HLAR_PARAMETER_INTFVER
	  #define CPAR_HLAR_PARAMETER_INTFVER	(2)
	#endif
	#ifndef   CPAR_HLA_PARAMETER_INTFVER
	  #define CPAR_HLA_PARAMETER_INTFVER	(2)
	#endif
	#ifndef   CPAR_LD_INTFVER
	  #define CPAR_LD_INTFVER	(1)
	#endif
	#ifndef   CPAR_SAC_RTE_INTFVER
	  #define CPAR_SAC_RTE_INTFVER	(1)
	#endif
	#ifndef   DISPARITY_IMAGE_INTFVER
	  #define DISPARITY_IMAGE_INTFVER	(2)
	#endif
	#ifndef   ECM_RTE_ALGO_HIS_INTFVER
	  #define ECM_RTE_ALGO_HIS_INTFVER	(1)
	#endif
	#ifndef   ECM_RTE_BSW_CTRL_DATA_INTFVER
	  #define ECM_RTE_BSW_CTRL_DATA_INTFVER	(1)
	#endif
	#ifndef   ECM_RTE_DIAG_INPUT_INTFVER
	  #define ECM_RTE_DIAG_INPUT_INTFVER	(1)
	#endif
	#ifndef   ECM_RTE_ENV_FOV_DATA_INTFVER
	  #define ECM_RTE_ENV_FOV_DATA_INTFVER	(1)
	#endif
	#ifndef   ECM_RTE_OUTPUT_INTFVER
	  #define ECM_RTE_OUTPUT_INTFVER	(2)
	#endif
	#ifndef   ECU_STATE_INTFVER
	  #define ECU_STATE_INTFVER	(1)
	#endif
	#ifndef   EMB0_OBJECT_LIST_SCAM_INTFVER
	  #define EMB0_OBJECT_LIST_SCAM_INTFVER	(2)
	#endif
	#ifndef   EMB0_OBJECT_SUBLISTS_INTFVER
	  #define EMB0_OBJECT_SUBLISTS_INTFVER	(393216)
	#endif
	#ifndef   EMO_EXPORT_INTFVER
	  #define EMO_EXPORT_INTFVER	(1)
	#endif
	#ifndef   EMO_OUTPUT_INTFVER
	  #define EMO_OUTPUT_INTFVER	(3)
	#endif
	#ifndef   EM_CAM_OBJECT_INTFVER
	  #define EM_CAM_OBJECT_INTFVER	(2)
	#endif
	#ifndef   EM_CAM_OBJECT_LIST_INTFVER
	  #define EM_CAM_OBJECT_LIST_INTFVER	(65536)
	#endif
	#ifndef   EM_CONSTRUCTION_SITE_NTFVER
	  #define EM_CONSTRUCTION_SITE_NTFVER	(1)
	#endif
	#ifndef   EM_CUSTOM_OBJECT_LIST_INTFVER
	  #define EM_CUSTOM_OBJECT_LIST_INTFVER	(268435458)
	#endif
	#ifndef   EM_GEN_OBJECT_INTFVER
	  #define EM_GEN_OBJECT_INTFVER	(5)
	#endif
	#ifndef   EM_GEN_OBJECT_LIST_INTFVER
	  #define EM_GEN_OBJECT_LIST_INTFVER	(65536)
	#endif
	#ifndef   EM_PED_OUTPUT_INTFVER
	  #define EM_PED_OUTPUT_INTFVER	(2)
	#endif
	#ifndef   EM_VCL_OUTPUT_INTFVER
	  #define EM_VCL_OUTPUT_INTFVER	(1)
	#endif
	#ifndef   EM_VIEWING_DISTANCE_INTFVER
	  #define EM_VIEWING_DISTANCE_INTFVER	(1)
	#endif
	#ifndef   FCT_ASSESSED_OBJ_INTFVER
	  #define FCT_ASSESSED_OBJ_INTFVER	(8)
	#endif
	#ifndef   FCT_CD_OUTPUT_CUSTOM_INTFVER
	  #define FCT_CD_OUTPUT_CUSTOM_INTFVER	(10)
	#endif
	#ifndef   FCT_CTRL_DATA_INTFVER
	  #define FCT_CTRL_DATA_INTFVER	(1)
	#endif
	#ifndef   FCT_DIM_INPUT_CUSTOM_INTFVER
	  #define FCT_DIM_INPUT_CUSTOM_INTFVER	(6)
	#endif
	#ifndef   FCT_DIM_INPUT_GENERIC_INTFVER
	  #define FCT_DIM_INPUT_GENERIC_INTFVER	(4)
	#endif
	#ifndef   FCT_DIM_OUTPUT_CUSTOM_INTFVER
	  #define FCT_DIM_OUTPUT_CUSTOM_INTFVER	(4)
	#endif
	#ifndef   FCT_HEAD_INPUT_CUSTOM_INTFVER
	  #define FCT_HEAD_INPUT_CUSTOM_INTFVER	(7)
	#endif
	#ifndef   FCT_HEAD_INPUT_GENERIC_INTFVER
	  #define FCT_HEAD_INPUT_GENERIC_INTFVER	(3)
	#endif
	#ifndef   FCT_HEAD_OUTPUT_CUSTOM_INTFVER
	  #define FCT_HEAD_OUTPUT_CUSTOM_INTFVER	(19)
	#endif
	#ifndef   FCT_HEAD_OUTPUT_GENERIC_INTFVER
	  #define FCT_HEAD_OUTPUT_GENERIC_INTFVER	(2)
	#endif
	#ifndef   FCT_HYPOTHESIS_INTFVER
	  #define FCT_HYPOTHESIS_INTFVER	(11)
	#endif
	#ifndef   FCT_LKA_INPUT_GENERIC_INTFVER
	  #define FCT_LKA_INPUT_GENERIC_INTFVER	(3)
	#endif
	#ifndef   FCT_LKA_OUTPUT_GENERIC_INTFVER
	  #define FCT_LKA_OUTPUT_GENERIC_INTFVER	(6)
	#endif
	#ifndef   FCT_SEN_ERROR_OUT_INTFVER
	  #define FCT_SEN_ERROR_OUT_INTFVER	(7)
	#endif
	#ifndef   FEX_BSW_CTRL_DATA_INTFVER
	  #define FEX_BSW_CTRL_DATA_INTFVER	(1)
	#endif
	#ifndef   FLOW_IMAGE_INTFVER
	  #define FLOW_IMAGE_INTFVER	(2)
	#endif
	#ifndef   FLSP_CALL_INTR_DIST_INTFVER
	  #define FLSP_CALL_INTR_DIST_INTFVER	(1)
	#endif
	#ifndef   FLSP_IMAGER_CHAR_LEFT_INTFVER
	  #define FLSP_IMAGER_CHAR_LEFT_INTFVER	(2)
	#endif
	#ifndef   FLSP_IMAGER_CHAR_RIGHT_INTFVER
	  #define FLSP_IMAGER_CHAR_RIGHT_INTFVER	(2)
	#endif
	#ifndef   FLSP_PROD_DATA_INTFVER
	  #define FLSP_PROD_DATA_INTFVER	(1)
	#endif
	#ifndef   FLSP_PROD_INTR_INTFVER
	  #define FLSP_PROD_INTR_INTFVER	(2)
	#endif
	#ifndef   FLSP_RESPONSE_CURVES_INTFVER
	  #define FLSP_RESPONSE_CURVES_INTFVER	(1)
	#endif
	#ifndef   FLSP_STEREO_CAL_INTR_INTFVER
	  #define FLSP_STEREO_CAL_INTR_INTFVER	(1)
	#endif
	#ifndef   FLSP_STEREO_CAL_TRAN_ROT_INTFVER
	  #define FLSP_STEREO_CAL_TRAN_ROT_INTFVER	(1)
	#endif
	#ifndef   FLSP_TEMP_COMP_INTFVER
	  #define FLSP_TEMP_COMP_INTFVER	(1)
	#endif
	#ifndef   FSD_LIST_INTFVER
	  #define FSD_LIST_INTFVER	(3)
	#endif
	#ifndef   FTRC_FEATURE_LIST_INTFVER
	  #define FTRC_FEATURE_LIST_INTFVER	(3)
	#endif
	#ifndef   FTRC_SEED_KILL_LIST_INTFVER
	  #define FTRC_SEED_KILL_LIST_INTFVER	(1)
	#endif
	#ifndef   GEN_FTRC_DEPTH_FEATURE_LIST_INTFVER
	  #define GEN_FTRC_DEPTH_FEATURE_LIST_INTFVER	(1)
	#endif
	#ifndef   GEN_TARGET_LIST_INTFVER
	  #define GEN_TARGET_LIST_INTFVER	(5)
	#endif
	#ifndef   HMI_INPUT_DATA
	  #define HMI_INPUT_DATA	(2)
	#endif
	#ifndef   IC_IMAGE_CHARACTERISTICS_INTFVER
	  #define IC_IMAGE_CHARACTERISTICS_INTFVER	(1)
	#endif
	#ifndef   IC_IMAGE_STATISTIC_INTFVER
	  #define IC_IMAGE_STATISTIC_INTFVER	(1)
	#endif
	#ifndef   IMAGE16_INTFVER
	  #define IMAGE16_INTFVER	(3)
	#endif
	#ifndef   IMAGE8_INTFVER
	  #define IMAGE8_INTFVER	(3)
	#endif
	#ifndef   LD_ONLINE_CALI_DATA_INTFVER
	  #define LD_ONLINE_CALI_DATA_INTFVER	(1)
	#endif
	#ifndef   LD_OUTPUT_DATA_INTFVER
	  #define LD_OUTPUT_DATA_INTFVER	(2)
	#endif
	#ifndef   MONO_CALIBRATION_EOL_INTFVER
	  #define MONO_CALIBRATION_EOL_INTFVER	(2)
	#endif
	#ifndef   MONO_CALIBRATION_INTFVER
	  #define MONO_CALIBRATION_INTFVER	(6)
	#endif
	#ifndef   MONO_CALIBRATION_RECTIFICATION_INTFVER
	  #define MONO_CALIBRATION_RECTIFICATION_INTFVER	(2)
	#endif
	#ifndef   NVM_ECM_RTE_INTFVER
	  #define NVM_ECM_RTE_INTFVER	(2)
	#endif
	#ifndef   NVM_EMO_INTFVER
	  #define NVM_EMO_INTFVER	(2)
	#endif
	#ifndef   NVM_HLAR_LEARNING_VALUES_INTFVER
	  #define NVM_HLAR_LEARNING_VALUES_INTFVER	(1)
	#endif
	#ifndef   NVM_SAC_RTE_INTFVER
	  #define NVM_SAC_RTE_INTFVER	(2)
	#endif
	#ifndef   NVM_SR_RTE_INTFVER
	  #define NVM_SR_RTE_INTFVER	(1)
	#endif
	#ifndef   PCINPUTDATA_INTFVER
	  #define PCINPUTDATA_INTFVER	(1)
	#endif
	#ifndef   PCOUTPUTDATA_INTFVER
	  #define PCOUTPUTDATA_INTFVER	(1)
	#endif
	#ifndef   PC_BSW_CTRL_DATA_INTFVER
	  #define PC_BSW_CTRL_DATA_INTFVER	(1)
	#endif
	#ifndef   PED_CLUSTERED_PEDS_INTFVER
	  #define PED_CLUSTERED_PEDS_INTFVER	(1)
	#endif
	#ifndef   PED_IMGTRACKED_PEDS_INTFVER
	  #define PED_IMGTRACKED_PEDS_INTFVER	(1)
	#endif
	#ifndef   PV_BSW_CTRL_DATA_INTFVER
	  #define PV_BSW_CTRL_DATA_INTFVER	(1)
	#endif
	#ifndef   PV_NVM_DATA_INTFVER
	  #define PV_NVM_DATA_INTFVER	(2)
	#endif
	#ifndef   PV_OUTPUT_DATA_INTFVER
	  #define PV_OUTPUT_DATA_INTFVER	(2)
	#endif
	#ifndef   PV_VEHICLE_DATA_INTFVER
	  #define PV_VEHICLE_DATA_INTFVER	(3)
	#endif
	#ifndef   RTE_HLAF_HEADLIGHTCONTROL_INTFVER
	  #define RTE_HLAF_HEADLIGHTCONTROL_INTFVER	(5)
	#endif
	#ifndef   RTE_HLAF_NIGHTVIEW_DATA_INTFVER
	  #define RTE_HLAF_NIGHTVIEW_DATA_INTFVER	(1)
	#endif
	#ifndef   RTE_HLAR_ENVIRONMENT_DATA_INTFVER
	  #define RTE_HLAR_ENVIRONMENT_DATA_INTFVER	(1)
	#endif
	#ifndef   RTE_HLAR_OBJECTLIST_INTFVER
	  #define RTE_HLAR_OBJECTLIST_INTFVER	(4)
	#endif
	#ifndef   RTE_HLA_HEADLIGHT_STATE_INTFVER
	  #define RTE_HLA_HEADLIGHT_STATE_INTFVER	(1)
	#endif
	#ifndef   RTE_HLA_SEG_LIGHTLIST_INTFVER
	  #define RTE_HLA_SEG_LIGHTLIST_INTFVER	(1)
	#endif
	#ifndef   RTE_HLA_SIGNALS_INTFVER
	  #define RTE_HLA_SIGNALS_INTFVER	(1)
	#endif
	#ifndef   RTE_INPUT_GPS_INTFVER
	  #define RTE_INPUT_GPS_INTFVER	(65792)
	#endif
	#ifndef   SAC_RTE_BSW_CONTROL_INPUT_INTFVER
	  #define SAC_RTE_BSW_CONTROL_INPUT_INTFVER	(2)
	#endif
	#ifndef   SAC_RTE_COMPONENT_TIMEOUT_INTFVER
	  #define SAC_RTE_COMPONENT_TIMEOUT_INTFVER	(1)
	#endif
	#ifndef   SAC_RTE_CROPPED_ROI_INPUT_INTFVER
	  #define SAC_RTE_CROPPED_ROI_INPUT_INTFVER	(1)
	#endif
	#ifndef   SAC_RTE_DEBUG_OUTPUT_INTFVER
	  #define SAC_RTE_DEBUG_OUTPUT_INTFVER	(1)
	#endif
	#ifndef   SAC_RTE_DIAG_STATUS_CALIB_STEREO
	  #define SAC_RTE_DIAG_STATUS_CALIB_STEREO	(1)
	#endif
	#ifndef   SAC_RTE_DIST_TEST_INPUT_INTFVER
	  #define SAC_RTE_DIST_TEST_INPUT_INTFVER	(1)
	#endif
	#ifndef   SAC_RTE_DIST_TEST_OUTPUT_INTFVER
	  #define SAC_RTE_DIST_TEST_OUTPUT_INTFVER	(1)
	#endif
	#ifndef   SAC_RTE_ECS_INPUT_INTFVER
	  #define SAC_RTE_ECS_INPUT_INTFVER	(1)
	#endif
	#ifndef   SAC_RTE_ECS_OUTPUT_INTFVER
	  #define SAC_RTE_ECS_OUTPUT_INTFVER	(1)
	#endif
	#ifndef   SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER
	  #define SAC_RTE_FEX_CONTROL_OUTPUT_INTFVER	(1)
	#endif
	#ifndef   SAC_RTE_OUTPUT_INTFVER
	  #define SAC_RTE_OUTPUT_INTFVER	(1)
	#endif
	#ifndef   SAC_RTE_RDU_INPUT_INTFVER
	  #define SAC_RTE_RDU_INPUT_INTFVER	(1)
	#endif
	#ifndef   SAC_RTE_STEREO_CALIBRATION_OUTPUT_INTFVER
	  #define SAC_RTE_STEREO_CALIBRATION_OUTPUT_INTFVER	(2)
	#endif
	#ifndef   SAC_RTE_STEREO_ROI_INPUT_INTFVER
	  #define SAC_RTE_STEREO_ROI_INPUT_INTFVER	(1)
	#endif
	#ifndef   SIB_FLOXEL_DATA_INTFVER
	  #define SIB_FLOXEL_DATA_INTFVER	(3)
	#endif
	#ifndef   SIB_ROAD_MODEL_DATA_INTFVER
	  #define SIB_ROAD_MODEL_DATA_INTFVER	(2)
	#endif
	#ifndef   SR_RTE_CODING_PARAMS_INTFVER
	  #define SR_RTE_CODING_PARAMS_INTFVER	(196608)
	#endif
	#ifndef   SR_RTE_COMMUNICATION_BUFFER_INTFVER
	  #define SR_RTE_COMMUNICATION_BUFFER_INTFVER	(1)
	#endif
	#ifndef   SR_RTE_OUTPUT_INTFVER
	  #define SR_RTE_OUTPUT_INTFVER	(3)
	#endif
	#ifndef   SW_MCU_SYSTEM_DATA_INTFVER
	  #define SW_MCU_SYSTEM_DATA_INTFVER	(2)
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
	#ifndef   SW_SOC_SOCCRUSHDUMP_INTVER
	  #define SW_SOC_SOCCRUSHDUMP_INTVER	(1)
	#endif
	#ifndef   SW_SOC_SYSTEMCONFINFO_INTVER
	  #define SW_SOC_SYSTEMCONFINFO_INTVER	(1)
	#endif
	#ifndef   SW_SOC_SYSTEM_DATA_INTFVER
	  #define SW_SOC_SYSTEM_DATA_INTFVER	(1)
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
	#ifndef   SYS_PERF_MON_OUT_INTFVER
	  #define SYS_PERF_MON_OUT_INTFVER	(2)
	#endif
	#ifndef   TSA_RTE_CODING_PARAMS_INTFVER
	  #define TSA_RTE_CODING_PARAMS_INTFVER	(65536)
	#endif
	#ifndef   TSA_RTE_CUSTOM_INPUT_INTFVER
	  #define TSA_RTE_CUSTOM_INPUT_INTFVER	(131072)
	#endif
	#ifndef   TSA_RTE_NVM_STATE_INTFVER
	  #define TSA_RTE_NVM_STATE_INTFVER	(65792)
	#endif
	#ifndef   TSA_RTE_OUTPUT_CUSTOM_INTFVER
	  #define TSA_RTE_OUTPUT_CUSTOM_INTFVER	(66560)
	#endif
	#ifndef   TSA_RTE_OUTPUT_RESULTS_INTFVER
	  #define TSA_RTE_OUTPUT_RESULTS_INTFVER	(66048)
	#endif
	#ifndef   VCL_MEAS_LIST_INTFVER
	  #define VCL_MEAS_LIST_INTFVER	(1)
	#endif
	#ifndef   VDY_ERRORS_INTFVER
	  #define VDY_ERRORS_INTFVER	(3)
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
	#ifndef   VDY_VEH_DYN_INTFVER
	  #define VDY_VEH_DYN_INTFVER	(6)
	#endif
	#ifndef   VODCA_CLASSIFIER_DEF_INTFVER
	  #define VODCA_CLASSIFIER_DEF_INTFVER	(4)
	#endif
	#ifndef   VODCA_CLASSIFIER_RESULTS_INTFVER
	  #define VODCA_CLASSIFIER_RESULTS_INTFVER	(3)
	#endif
	#ifndef   VODCA_PATCH_CONFIG_INTFVER
	  #define VODCA_PATCH_CONFIG_INTFVER	(3)
	#endif


#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif /* RTE_Ext_TYPE_H */
