#ifndef _GA_GLOBAL_H_INCLUDED
#error include setup error: forbidden inclusion of GA local-scope header file; only component *_main.h + *_wrapper.h, and ga_global.h (or ga_global_emlib.h on emlib dependancy) are allowed
#endif

#ifndef GA_LCF_INTERFACES_EXT_H_INCLUDED
#define GA_LCF_INTERFACES_EXT_H_INCLUDED

/*! @ingroup lcf_interfaces
@{
@file
External header of the LCF_INTERFACES component.    */


#if (GA_CFG_LCF_INTERFACES == 1)

#ifdef __cplusplus
extern "C" {
#endif

/* --- virtual addresses --------------------------------------------------- */
#define LCF_INTERFACES_VA_CONTROL_DATA       ()   /*!< virtual address of controlData (uL) */

/* ---- constants ---------------------------------------------------------- */
#define LCF_AVAIL_LKA               (0)
#define LCF_AVAIL_LDW_LEFT          (1)
#define LCF_AVAIL_LDW_RIGHT         (2)
#define LCF_AVAIL_LDP_LEFT          (3)
#define LCF_AVAIL_LDP_RIGHT         (4)
#define LCF_AVAIL_RDP_LEFT          (5)
#define LCF_AVAIL_RDP_RIGHT         (6)
#define LCF_AVAIL_LDPOC_LEFT        (7)
#define LCF_AVAIL_LDPOC_RIGHT       (8)
#define LCF_AVAIL_TJA               (9)
#define LCF_AVAIL_ALCA_LEFT         (10)
#define LCF_AVAIL_ALCA_RIGHT        (11)

/* ---- type InterfaceVersion ---------------------------------------------- */
#define LCF_INTERFACES_CONTROL_DATA_INTVER  (1)  /*!< version of LCF_INTERFACES_ControlData */
#define LCF_TUN_PAR_LDP_INTFVER             (7)  /*!< version of LCF_INTERFACES_CPAR_LCF_TunParamsLDP */
#define LCF_TUN_PAR_LKA_INTFVER             (7)  /*!< version of LCF_INTERFACES_CPAR_LCF_TunParamsLKA */
#define LCF_TUN_PAR_KMC_INTFVER             (9)  /*!< version of LCF_INTERFACES_CPAR_LCF_TunParamsKMC */
#define LCF_TUN_PAR_DMC_INTFVER             (7)  /*!< version of LCF_INTERFACES_CPAR_LCF_TunParamsDMC */
#define LCF_INPUT_INTFVER                   (18)  /*!< version of LCF_INTERFACES_LCF_GenericInputs */
#define LCF_SEN_OUTPUT_INTFVER              (17)  /*!< version of LCF_INTERFACES_LCF_SenGenericOutputs */
#define LCF_VEH_OUTPUT_INTFVER              (10)  /*!< version of LCF_INTERFACES_LCF_VehGenericOutputs */
#define LCF_SEN2VEH_INTFVER                 (15)  /*!< version of LCF_INTERFACES_LCF_SenToVeh */
#define LCF_VEH2SEN_INTFVER                 (11)  /*!< version of LCF_INTERFACES_LCF_VehToSen */
#define LCF_SOC2IUC_INTFVER                 (4)  /*!< version of LCF_INTERFACES_LCF_LaDmcSocToIuc */
#define LCF_IUC2SOC_INTFVER                 (6)  /*!< version of LCF_INTERFACES_LCF_LaDmcIucToSoc */
#define LCF_CAN2LADMCIUC_INTFVER            (2)  /*!< version of LCF_INTERFACES_LCF_CanToLaDmcIuc */
#define LCF_LADMCIUC2CAN_INTFVER            (3)  /*!< version of LCF_INTERFACES_LCF_LaDmcIucToCan */
#define LCF_LEARNDATA_INTFVER               (2)  /*!< version of LCF_INTERFACES_NVM_LcfLearningData */

/* ---- type definitions --------------------------------------------------- */
#define lcf_interfaces_LCF_SYSTEM_AVAILABLE                                            (0u)
#define lcf_interfaces_LCF_SYSTEM_NOT_AVAILABLE                                        (1u)
#define lcf_interfaces_LCF_SYSTEM_ERROR                                                (2u)
#define lcf_interfaces_LCF_SYSTEM_INVALID                                              (3u)

/*! @brief System state of any relevant system for the mode controller */
typedef uint8 LCF_INTERFACES_LCF_e_ModeCtrlSystemState_t;

#define lcf_interfaces_LCF_ACTIVITY_STANDBY                                            (0u)
#define lcf_interfaces_LCF_ACTIVITY_CONTROLLING                                        (1u)
#define lcf_interfaces_LCF_ACTIVITY_SHUTDOWN                                           (2u)
#define lcf_interfaces_LCF_ACTIVITY_INVALID                                            (3u)

/*! @brief State that describes function activity for any relevant system for the mode controller */
typedef uint8 LCF_INTERFACES_LCF_e_ModeCtrlActiveState_t;

#define lcf_interfaces_LCF_INPUT_STATE_DEFECT                                          (0u)
#define lcf_interfaces_LCF_INPUT_STATE_NOT_DEFECT                                      (1u)
#define lcf_interfaces_LCF_INPUT_STATE_INVALID                                         (3u)

/*! @brief State that describes defectuous functioning of a relevant input system */
typedef uint8 LCF_INTERFACES_LCF_e_InputDefectState_t;

#define lcf_interfaces_LCF_MAIN_SWITCH_OFF                                             (0u)
#define lcf_interfaces_LCF_MAIN_SWITCH_ON                                              (1u)
#define lcf_interfaces_LCF_MAIN_SWITCH_INVALID                                         (3u)

/*! @brief State of the activation switch of a lateral control function */
typedef uint8 LCF_INTERFACES_LCF_e_MainSwitchState_t;

#define lcf_interfaces_LCF_SENSITIVITY_LATE                                            (0u)
#define lcf_interfaces_LCF_SENSITIVITY_EARLY                                           (1u)
#define lcf_interfaces_LCF_SENSITIVITY_STANDARD                                        (2u)
#define lcf_interfaces_LCF_SENSITIVITY_INVALID                                         (3u)

/*! @brief Sensitivity level of a lateral control function */
typedef uint8 LCF_INTERFACES_LCF_e_SensitivityState_t;

#define lcf_interfaces_LCF_FCT_MODE_DEFAULT                                            (0u)
#define lcf_interfaces_LCF_FCT_MODE_SETTING_1                                          (1u)
#define lcf_interfaces_LCF_FCT_MODE_SETTING_2                                          (2u)
#define lcf_interfaces_LCF_FCT_MODE_SETTING_3                                          (3u)
#define lcf_interfaces_LCF_FCT_MODE_UNKNOWN                                            (4u)
#define lcf_interfaces_LCF_FCT_MODE_INVALID                                            (5u)

/*! @brief Function mode of a lateral control function */
typedef uint8 LCF_INTERFACES_LCF_e_FctMode_t;

#define lcf_interfaces_LCF_IO_STATE_VALID                                              (0u)
#define lcf_interfaces_LCF_IO_STATE_INVALID                                            (1u)
#define lcf_interfaces_LCF_IO_STATE_NOTAVAIL                                           (2u)
#define lcf_interfaces_LCF_IO_STATE_SUBSTITUTE                                         (3u)
#define lcf_interfaces_LCF_IO_STATE_INIT                                               (4u)

/*! @brief Input states */
typedef uint8 LCF_INTERFACES_LCF_e_IoStateType_t;

#define lcf_interfaces_LCF_IO_POS_HWA                                                  (0u)
#define lcf_interfaces_LCF_IO_POS_HWAR                                                 (1u)
#define lcf_interfaces_LCF_IO_POS_DFSA                                                 (2u)
#define lcf_interfaces_LCF_IO_POS_DFSAR                                                (3u)
#define lcf_interfaces_LCF_IO_POS_STQ                                                  (4u)
#define lcf_interfaces_LCF_IO_POS_DSWT                                                 (5u)
#define lcf_interfaces_LCF_IO_POS_MTQ                                                  (6u)
#define lcf_interfaces_LCF_IO_POS_ESCS                                                 (7u)
#define lcf_interfaces_LCF_IO_POS_ESCA                                                 (8u)
#define lcf_interfaces_LCF_IO_POS_ABSS                                                 (9u)
#define lcf_interfaces_LCF_IO_POS_ABSA                                                 (10u)
#define lcf_interfaces_LCF_IO_POS_TCSS                                                 (11u)
#define lcf_interfaces_LCF_IO_POS_TCSA                                                 (12u)
#define lcf_interfaces_LCF_IO_POS_ACCS                                                 (13u)
#define lcf_interfaces_LCF_IO_POS_ACCA                                                 (14u)
#define lcf_interfaces_LCF_IO_POS_VSMS                                                 (15u)
#define lcf_interfaces_LCF_IO_POS_VSMA                                                 (16u)
#define lcf_interfaces_LCF_IO_POS_EBAS                                                 (17u)
#define lcf_interfaces_LCF_IO_POS_EBAA                                                 (18u)
#define lcf_interfaces_LCF_IO_POS_TBD                                                  (19u)
#define lcf_interfaces_LCF_IO_POS_DO                                                   (20u)
#define lcf_interfaces_LCF_IO_POS_TS                                                   (21u)
#define lcf_interfaces_LCF_IO_POS_TSL                                                  (22u)
#define lcf_interfaces_LCF_IO_POS_VRS                                                  (23u)
#define lcf_interfaces_LCF_IO_POS_DNB                                                  (24u)
#define lcf_interfaces_LCF_IO_POS_OSD                                                  (25u)
#define lcf_interfaces_LCF_IO_POS_USD                                                  (26u)
#define lcf_interfaces_LCF_IO_POS_BA                                                   (27u)
#define lcf_interfaces_LCF_IO_POS_TRL                                                  (28u)
#define lcf_interfaces_LCF_IO_POS_ETU                                                  (29u)
#define lcf_interfaces_LCF_IO_POS_ETA                                                  (30u)
#define lcf_interfaces_LCF_IO_POS_ETF                                                  (31u)
#define lcf_interfaces_LCF_IO_POS_EFS                                                  (32u)
#define lcf_interfaces_LCF_IO_POS_ED                                                   (33u)
#define lcf_interfaces_LCF_IO_POS_LKASW                                                (34u)
#define lcf_interfaces_LCF_IO_POS_LKAM                                                 (35u)
#define lcf_interfaces_LCF_IO_POS_TJASW                                                (36u)
#define lcf_interfaces_LCF_IO_POS_TJAM                                                 (37u)
#define lcf_interfaces_LCF_IO_POS_VAS                                                  (38u)
#define lcf_interfaces_LCF_IO_POS_SML                                                  (39u)
#define lcf_interfaces_LCF_IO_POS_LDWSW                                                (40u)
#define lcf_interfaces_LCF_IO_POS_LDPSW                                                (41u)
#define lcf_interfaces_LCF_IO_POS_RDPSW                                                (42u)
#define lcf_interfaces_LCF_IO_POS_LDPOSW                                               (43u)
#define lcf_interfaces_LCF_IO_POS_LDWS                                                 (44u)
#define lcf_interfaces_LCF_IO_POS_LDPS                                                 (45u)
#define lcf_interfaces_LCF_IO_POS_RDPS                                                 (46u)
#define lcf_interfaces_LCF_IO_POS_DHO                                                  (47u)
#define lcf_interfaces_LCF_IO_POS_VVEL                                                 (48u)
#define lcf_interfaces_LCF_IO_POS_SCCA                                                 (49u)
#define lcf_interfaces_LCF_IO_POS_USMR                                                 (50u)
#define lcf_interfaces_LCF_IO_POS_HDAON                                                (51u)
#define lcf_interfaces_LCF_IO_POS_SCCON                                                (52u)
#define lcf_interfaces_LCF_IO_POS_USMSS                                                (53u)
#define lcf_interfaces_LCF_IO_POS_NRT                                                  (54u)
#define lcf_interfaces_LCF_IO_POS_NSFOW                                                (55u)
#define lcf_interfaces_LCF_IO_POS_NSSL                                                 (56u)
#define lcf_interfaces_LCF_IO_POS_NST                                                  (57u)
#define lcf_interfaces_LCF_IO_POS_NPPT                                                 (58u)
#define lcf_interfaces_LCF_IO_POS_NTGD                                                 (59u)
#define lcf_interfaces_LCF_IO_POS_NTDDO                                                (60u)
#define lcf_interfaces_LCF_IO_POS_NPO                                                  (61u)
#define lcf_interfaces_LCF_IO_POS_NPCC                                                 (62u)
#define lcf_interfaces_LCF_IO_POS_NPOSCC                                               (63u)
#define lcf_interfaces_LCF_IO_POS_HEFF                                                 (64u)
#define lcf_interfaces_LCF_IO_POS_SCCM                                                 (65u)
#define lcf_interfaces_LCF_IO_POS_NSU                                                  (66u)
#define lcf_interfaces_LCF_IO_POS_AHO                                                  (67u)
#define lcf_interfaces_LCF_IO_POS_APP                                                  (68u)
#define lcf_interfaces_LCF_IO_POS_VAR                                                  (69u)
#define lcf_interfaces_LCF_IO_POS_OBSRL                                                (70u)
#define lcf_interfaces_LCF_IO_POS_OFOVRL                                               (71u)
#define lcf_interfaces_LCF_IO_POS_QFRL                                                 (72u)
#define lcf_interfaces_LCF_IO_POS_MSFRL                                                (73u)
#define lcf_interfaces_LCF_IO_POS_OBSRR                                                (74u)
#define lcf_interfaces_LCF_IO_POS_OFOVRR                                               (75u)
#define lcf_interfaces_LCF_IO_POS_QFRR                                                 (76u)
#define lcf_interfaces_LCF_IO_POS_MSFRR                                                (77u)
#define lcf_interfaces_LCF_IO_POS_ALCASW                                               (78u)
#define lcf_interfaces_LCF_IO_POS_ALCAS                                                (79u)
#define lcf_interfaces_LCF_IO_POS_ALCAM                                                (80u)
#define lcf_interfaces_LCF_IO_POS_LCAAL                                                (81u)
#define lcf_interfaces_LCF_IO_POS_BSDAL                                                (82u)
#define lcf_interfaces_LCF_IO_POS_LCAWL                                                (83u)
#define lcf_interfaces_LCF_IO_POS_BSDWL                                                (84u)
#define lcf_interfaces_LCF_IO_POS_LCAAR                                                (85u)
#define lcf_interfaces_LCF_IO_POS_BSDAR                                                (86u)
#define lcf_interfaces_LCF_IO_POS_LCAWR                                                (87u)
#define lcf_interfaces_LCF_IO_POS_BSDWR                                                (88u)
#define lcf_interfaces_LCF_IO_POS_HWLS                                                 (89u)
#define lcf_interfaces_LCF_IO_POS_HWRS                                                 (90u)
#define lcf_interfaces_LCF_IO_POS_HWCS                                                 (91u)
#define lcf_interfaces_LCF_IO_POS_HWLM                                                 (92u)
#define lcf_interfaces_LCF_IO_POS_HWRM                                                 (93u)
#define lcf_interfaces_LCF_IO_POS_HWCM                                                 (94u)
#define lcf_interfaces_LCF_IO_POS_VWLS                                                 (95u)
#define lcf_interfaces_LCF_IO_POS_VWRS                                                 (96u)
#define lcf_interfaces_LCF_IO_POS_VWCS                                                 (97u)
#define lcf_interfaces_LCF_IO_POS_VWLM                                                 (98u)
#define lcf_interfaces_LCF_IO_POS_VWRM                                                 (99u)
#define lcf_interfaces_LCF_IO_POS_VWCM                                                 (100u)
#define lcf_interfaces_LCF_IO_POS_LDPOCS                                               (101u)
#define lcf_interfaces_LCF_IO_POS_AOLCS                                                (102u)
#define lcf_interfaces_LCF_IO_POS_TJALCA                                               (103u)
#define lcf_interfaces_LCF_IO_POS_TJAHOWE                                              (104u)
#define lcf_interfaces_LCF_IO_POS_SCM                                                  (105u)
#define lcf_interfaces_LCF_IO_POS_EPSAF                                                (106u)
#define lcf_interfaces_LCF_IO_POS_EPSDI                                                (107u)
#define lcf_interfaces_LCF_IO_POS_EPSRT                                                (108u)
#define lcf_interfaces_LCF_IO_POS_EPSMT                                                (109u)
#define lcf_interfaces_LCF_IO_POS_EPSMAS                                               (110u)
#define lcf_interfaces_LCF_IO_POS_EPSRSA                                               (111u)
#define lcf_interfaces_LCF_IO_POS_STOD                                                 (112u)
#define lcf_interfaces_LCF_IO_POS_MRAX                                                 (113u)
#define lcf_interfaces_LCF_IO_POS_MRVX                                                 (114u)
#define lcf_interfaces_LCF_IO_POS_MRAY                                                 (115u)
#define lcf_interfaces_LCF_IO_POS_MRVY                                                 (116u)
#define lcf_interfaces_LCF_IO_POS_PPX                                                  (117u)
#define lcf_interfaces_LCF_IO_POS_PPY                                                  (118u)
#define lcf_interfaces_LCF_IO_POS_PPXSD                                                (119u)
#define lcf_interfaces_LCF_IO_POS_PPYSD                                                (120u)
#define lcf_interfaces_LCF_IO_POS_OBJQ                                                 (121u)
#define lcf_interfaces_LCF_IO_POS_OBJRCT                                               (122u)
#define lcf_interfaces_LCF_IO_POS_OBJRMS                                               (123u)
#define lcf_interfaces_LCF_IO_POS_DIMW                                                 (124u)
#define lcf_interfaces_LCF_IO_POS_SSRC                                                 (125u)
#define lcf_interfaces_LCF_IO_POS_TMST                                                 (126u)
#define lcf_interfaces_LCF_IO_POS_OBJREQ                                               (127u)
#define lcf_interfaces_LCF_IO_POS_LPX                                                  (128u)
#define lcf_interfaces_LCF_IO_POS_LPY                                                  (129u)
#define lcf_interfaces_LCF_IO_POS_LRVX                                                 (130u)
#define lcf_interfaces_LCF_IO_POS_LRVY                                                 (131u)
#define lcf_interfaces_LCF_IO_POS_LRAX                                                 (132u)
#define lcf_interfaces_LCF_IO_POS_LRAY                                                 (133u)
#define lcf_interfaces_LCF_IO_POS_LQU                                                  (134u)
#define lcf_interfaces_LCF_IO_POS_LMS                                                  (135u)
#define lcf_interfaces_LCF_IO_POS_LOBJRCT                                              (136u)
#define lcf_interfaces_LCF_IO_POS_LOBJTS                                               (137u)
#define lcf_interfaces_LCF_IO_POS_RPX                                                  (138u)
#define lcf_interfaces_LCF_IO_POS_RPY                                                  (139u)
#define lcf_interfaces_LCF_IO_POS_RRVX                                                 (140u)
#define lcf_interfaces_LCF_IO_POS_RRVY                                                 (141u)
#define lcf_interfaces_LCF_IO_POS_RRAX                                                 (142u)
#define lcf_interfaces_LCF_IO_POS_RRAY                                                 (143u)
#define lcf_interfaces_LCF_IO_POS_RQU                                                  (144u)
#define lcf_interfaces_LCF_IO_POS_RMS                                                  (145u)
#define lcf_interfaces_LCF_IO_POS_ROBJRCT                                              (146u)
#define lcf_interfaces_LCF_IO_POS_ROBJTS                                               (147u)
#define lcf_interfaces_LCF_IO_POS_DOCOBJL                                              (148u)
#define lcf_interfaces_LCF_IO_POS_DOCOBJR                                              (149u)
#define lcf_interfaces_LCF_IO_POS_DOCOBJQ                                              (150u)
#define lcf_interfaces_LCF_IO_MAX                                                      (151u)

/*! @brief Positions in the inputs state array State__nu. Must be updated every time LCF_GenericInputs is modified. See sheet Auxiliary_LCF_e_IoStatePos_t. */
typedef uint8 LCF_INTERFACES_LCF_e_IoStatePos_t;

#define lcf_interfaces_LCF_MODE_CTRL_ACTIVE_FUNCTION_NONE                              (0u)
#define lcf_interfaces_LCF_MODE_CTRL_ACTIVE_FUNCTION_ESA                               (1u)
#define lcf_interfaces_LCF_MODE_CTRL_ACTIVE_FUNCTION_LCA                               (2u)
#define lcf_interfaces_LCF_MODE_CTRL_ACTIVE_FUNCTION_TJA                               (3u)

/*! @brief Active lateral control function */
typedef uint8 LCF_INTERFACES_LCF_e_ActiveLatFunction_t;

#define lcf_interfaces_LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_DONOT_APPLY_TGT_VALUE       (0u)
#define lcf_interfaces_LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV                   (1u)
#define lcf_interfaces_LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_SIDE_SLIP         (2u)
#define lcf_interfaces_LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_FREEZE_CRV                  (3u)
#define lcf_interfaces_LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_FFCTRL            (4u)
#define lcf_interfaces_LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_TGT_CHANGE        (5u)
#define lcf_interfaces_LCF_LAT_CTRL_COORD_TRAJ_GUI_CTRL_QU_APPLY_CRV_BRIDGING          (6u)

/*! @brief Trajectory qualifier */
typedef uint8 LCF_INTERFACES_LCF_e_TrajGuiQualifier_t;

#define lcf_interfaces_LCF_SYSSTATE_NOTPRESENT                                         (0u)
#define lcf_interfaces_LCF_SYSSTATE_DISABLED                                           (1u)
#define lcf_interfaces_LCF_SYSSTATE_PASSIVE                                            (2u)
#define lcf_interfaces_LCF_SYSSTATE_REQUEST                                            (3u)
#define lcf_interfaces_LCF_SYSSTATE_CONTROLLING                                        (4u)
#define lcf_interfaces_LCF_SYSSTATE_RAMPOUT                                            (5u)
#define lcf_interfaces_LCF_SYSSTATE_ERROR                                              (6u)

/*! @brief Function system state */
typedef uint8 LCF_INTERFACES_LCF_e_FctSystemState_t;

#define lcf_interfaces_LCF_WARN_NONE                                                   (0u)
#define lcf_interfaces_LCF_WARN_HAPTIC                                                 (1u)
#define lcf_interfaces_LCF_WARN_ACOUSTIC                                               (2u)

/*! @brief Lkas_Ldws warning state */
typedef uint8 LCF_INTERFACES_LCF_e_Lkas_LdwsWarning_t;

#define lcf_interfaces_LCF_DISP_LANE_NOT_DETECTED                                      (0u)
#define lcf_interfaces_LCF_DISP_LANE_PYHSICAL                                          (1u)
#define lcf_interfaces_LCF_DISP_LANE_BRIDGED                                           (2u)
#define lcf_interfaces_LCF_DISP_LANE_VIRTUAL                                           (3u)

/*! @brief Display of detected lane  */
typedef uint8 LCF_INTERFACES_LCF_e_DispLaneDetected_t;

#define lcf_interfaces_LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PASSIVE                         (0u)
#define lcf_interfaces_LCF_TJA_SYS_COORD_LAT_CTRL_MODE_LANE_CENTERING                  (1u)
#define lcf_interfaces_LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_NO_LANE_BOUNDS          (2u)
#define lcf_interfaces_LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_CLOSE_TO_RIGHT_BOUND    (3u)
#define lcf_interfaces_LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_CLOSE_TO_LEFT_BOUND     (4u)
#define lcf_interfaces_LCF_TJA_SYS_COORD_LAT_CTRL_MODE_PURSUIT_WITH_LANE_BOUNDARIES    (5u)
#define lcf_interfaces_LCF_TJA_SYS_COORD_LAT_CTRL_MODE_DEGRADATION                     (6u)

/*! @brief Lateral control mode states */
typedef uint8 LCF_INTERFACES_LCF_e_LatCtrlMode_t;

#define lcf_interfaces_LCF_LCA_INACTIVE                                                (0u)
#define lcf_interfaces_LCF_LCA_ACTIVE                                                  (1u)
#define lcf_interfaces_LCF_LCA_INVALID                                                 (2u)

/*! @brief LCA active state */
typedef uint8 LCF_INTERFACES_LCF_e_LCAActiveState_t;

#define lcf_interfaces_LCF_BSD_INACTIVE                                                (0u)
#define lcf_interfaces_LCF_BSD_ACTIVE                                                  (1u)
#define lcf_interfaces_LCF_BSD_INVALID                                                 (2u)

/*! @brief BSD active state */
typedef uint8 LCF_INTERFACES_LCF_e_BSDActiveState_t;

#define lcf_interfaces_LCF_LCA_WARNING_OFF                                             (0u)
#define lcf_interfaces_LCF_LCA_WARNING_1                                               (1u)
#define lcf_interfaces_LCF_LCA_WARNING_2                                               (2u)
#define lcf_interfaces_LCF_LCA_WARNING_INVALID                                         (3u)

/*! @brief LCA warning state */
typedef uint8 LCF_INTERFACES_LCF_e_LCAWarningState_t;

#define lcf_interfaces_LCF_BSD_WARNING_OFF                                             (0u)
#define lcf_interfaces_LCF_BSD_WARNING_1                                               (1u)
#define lcf_interfaces_LCF_BSD_WARNING_2                                               (2u)
#define lcf_interfaces_LCF_BSD_WARNING_INVALID                                         (3u)

/*! @brief BSD warning state */
typedef uint8 LCF_INTERFACES_LCF_e_BSDWarningState_t;

#define lcf_interfaces_FROOP_NO_HAZARDOUS_OBJ                                          (0u)
#define lcf_interfaces_FROOP_RADAR_ONLY_LANE_MAPPED                                    (1u)
#define lcf_interfaces_FROOP_FUSED_OBJ_LANE_MAPPED                                     (2u)
#define lcf_interfaces_FROOP_RADAR_ONLY_CORR_MAPPED                                    (3u)
#define lcf_interfaces_FROOP_FUSED_OBJ_CORR_MAPPED                                     (4u)
#define lcf_interfaces_FROOP_DANG_OC_OBJ_INVALID                                       (7u)

/*! @brief Dangerous oncoming object detected by radar */
typedef uint8 LCF_INTERFACES_LCF_e_DangOcObj_t;

#define lcf_interfaces_LCF_WRN_DVC_STANDBY                                             (0u)
#define lcf_interfaces_LCF_WRN_DVC_ACTIVE                                              (1u)
#define lcf_interfaces_LCF_WRN_DVC_NOT_AVAILABLE                                       (2u)
#define lcf_interfaces_LCF_WRN_DVC_ERROR                                               (3u)
#define lcf_interfaces_LCF_WRN_DVC_UNKNOWN                                             (4u)
#define lcf_interfaces_LCF_WRN_DVC_INVALID                                             (7u)

/*! @brief Visual or haptic warning device state of vehicle */
typedef uint8 LCF_INTERFACES_LCF_e_WrnDeviceState_t;

#define lcf_interfaces_LCF_WRN_MODE_NOT_ACTIVE                                         (0u)
#define lcf_interfaces_LCF_WRN_MODE_ACTIVE_MODE_1                                      (1u)
#define lcf_interfaces_LCF_WRN_MODE_ACTIVE_MODE_2                                      (2u)
#define lcf_interfaces_LCF_WRN_MODE_ACTIVE_MODE_3                                      (3u)
#define lcf_interfaces_LCF_WRN_MODE_ACTIVE_MODE_4                                      (4u)
#define lcf_interfaces_LCF_WRN_MODE_ACTIVE_MODE_5                                      (5u)
#define lcf_interfaces_LCF_WRN_MODE_UNKNOWN                                            (6u)
#define lcf_interfaces_LCF_WRN_MODE_INVALID                                            (7u)

/*! @brief Visual or haptic warning device mode */
typedef uint8 LCF_INTERFACES_LCF_e_WrnDeviceMode_t;

#define lcf_interfaces_LCF_LANE_BOUND_NOT_AVAILABLE                                    (0u)
#define lcf_interfaces_LCF_LANE_BOUND_AVAILABLE                                        (1u)
#define lcf_interfaces_LCF_LAT_CONTROL_TRIGGER                                         (2u)
#define lcf_interfaces_LCF_LAT_CONTROL_RUNNING                                         (3u)
#define lcf_interfaces_LCF_LAT_CONTROL_SUCCESSFUL                                      (4u)
#define lcf_interfaces_LCF_LAT_CONTROL_CANCEL_DRV_ACTION                               (5u)
#define lcf_interfaces_LCF_LAT_CONTROL_CANCEL_LAT_DEVIATION                            (6u)
#define lcf_interfaces_LCF_LAT_CONTROL_CANCEL_LANE_MARKING_AVAIL                       (7u)
#define lcf_interfaces_LCF_LAT_CONTROL_CANCEL_OTHER                                    (8u)
#define lcf_interfaces_LCF_LAT_CONTROL_ABORT                                           (9u)
#define lcf_interfaces_LCF_LAT_CONTROL_INVALID                                         (15u)

/*! @brief Function side state for left or right */
typedef uint8 LCF_INTERFACES_LCF_e_FctSideState_t;

#define lcf_interfaces_LCF_FALSE                                                       (0u)
#define lcf_interfaces_LCF_TRUE                                                        (1u)
#define lcf_interfaces_LCF_INVALID                                                     (3u)

/*! @brief Enum for boolean signals (with invalid value) */
typedef uint8 LCF_INTERFACES_LCF_e_BoolState_t;

#define lcf_interfaces_LCF_ACC_TRACE_INVALID                                           (0u)
#define lcf_interfaces_LCF_ACC_TRACE_VALID                                             (1u)
#define lcf_interfaces_LCF_ACC_TRACE_NOT_AVAILABLE                                     (2u)
#define lcf_interfaces_LCF_ACC_TRACE_ERROR                                             (15u)

/*! @brief The qualifier of ACC trace trajectory.  */
typedef uint8 LCF_e_AccTraceTrajState_t;

#define lcf_interfaces_LCF_TURN_SIG_OFF                                                (0u)
#define lcf_interfaces_LCF_TURN_SIG_LEFT                                               (1u)
#define lcf_interfaces_LCF_TURN_SIG_RIGHT                                              (2u)
#define lcf_interfaces_LCF_TURN_SIG_HAZARD                                             (3u)
#define lcf_interfaces_LCF_TURN_SIG_INVALID                                            (4u)

/*! @brief indicates if the turn signal is activated */
typedef uint8 LCF_e_TurnSignalState_t;

#define lcf_interfaces_LCF_TURN_LEVER_OFF                                              (0u)
#define lcf_interfaces_LCF_TURN_LEVER_TIPPED                                           (1u)
#define lcf_interfaces_LCF_TURN_LEVER_ENGAGED                                          (2u)
#define lcf_interfaces_LCF_TURN_LEVER_INVALID                                          (3u)

/*! @brief indicates turn signal lever state */
typedef uint8 LCF_e_TurnLeverState_t;

#define lcf_interfaces_LCF_MODE_SEL_OFF                                                (0u)
#define lcf_interfaces_LCF_MODE_SEL_LDW                                                (1u)
#define lcf_interfaces_LCF_MODE_SEL_LDP_STD                                            (2u)
#define lcf_interfaces_LCF_MODE_SEL_LDP_ACT                                            (3u)

/*! @brief LKAS_LDW mode selection */
typedef uint8 LCF_e_ModeSelection_t;

#define lcf_interfaces_LCF_HANDS_OFF_DETECTED                                          (0u)
#define lcf_interfaces_LCF_HANDS_ON_DETECTED                                           (1u)
#define lcf_interfaces_LCF_HANDS_STAT_INVALID                                          (3u)

/*! @brief Driver HandsOff state */
typedef uint8 LCF_e_HandsOffState_t;

#define lcf_interfaces_LCF_SCC_INACTIVE                                                (0u)
#define lcf_interfaces_LCF_SCC_ACTIVE                                                  (1u)

/*! @brief Indicates that Smart Cruise Control is in the active state */
typedef uint8 LCF_e_SCCActiveState_t;

#define lcf_interfaces_LCF_USM_RESET_DEFAULT                                           (0u)
#define lcf_interfaces_LCF_USM_RESET_OFF                                               (1u)

/*! @brief The reset signal from Cluster/USM */
typedef uint8 LCF_e_USMResetState_t;

#define lcf_interfaces_LCF_HDA_DEFAULT                                                 (0u)
#define lcf_interfaces_LCF_HDA_OFF                                                     (1u)
#define lcf_interfaces_LCF_HDA_ON                                                      (2u)
#define lcf_interfaces_LCF_HDA_INVALID                                                 (3u)

/*! @brief This signal is used to set HAD function */
typedef uint8 LCF_e_HDAOnState_t;

#define lcf_interfaces_LCF_SCC_MODE                                                    (1u)
#define lcf_interfaces_LCF_CC_MODE                                                     (2u)

/*! @brief This signal reflects that the SCC mode is selected  */
typedef uint8 LCF_e_SCCOnState_t;

#define lcf_interfaces_LCF_ROAD_UNKNOWN                                                (0u)
#define lcf_interfaces_LCF_ROAD_FREEWAY                                                (1u)
#define lcf_interfaces_LCF_ROAD_CITY_FREEWAY                                           (2u)

/*! @brief Indicated the road type */
typedef uint8 LCF_e_NAVIRoadType_t;

#define lcf_interfaces_LCF_ROAD_FORM_UNKNOWN                                           (0u)
#define lcf_interfaces_LCF_ROAD_FORM_NONDISJ                                           (1u)
#define lcf_interfaces_LCF_ROAD_FORM_DISJ                                              (2u)
#define lcf_interfaces_LCF_ROAD_FORM_JC                                                (3u)
#define lcf_interfaces_LCF_ROAD_FORM_PLURAL_JC                                         (4u)
#define lcf_interfaces_LCF_ROAD_FORM_IC                                                (5u)
#define lcf_interfaces_LCF_ROAD_FORM_RESERVED1                                         (6u)
#define lcf_interfaces_LCF_ROAD_FORM_SERVICE_AREA                                      (7u)
#define lcf_interfaces_LCF_ROAD_FORM_RESERVED2                                         (8u)
#define lcf_interfaces_LCF_ROAD_FORM_ROUNDABOUT                                        (9u)
#define lcf_interfaces_LCF_ROAD_FORM_P_TURN                                            (10u)
#define lcf_interfaces_LCF_ROAD_FORM_U_TURN                                            (11u)
#define lcf_interfaces_LCF_ROAD_FORM_PEDESTRIAN                                        (12u)
#define lcf_interfaces_LCF_ROAD_FORM_FRONTAGE_RD                                       (13u)
#define lcf_interfaces_LCF_ROAD_FORM_INTERSECT_INT                                     (14u)
#define lcf_interfaces_LCF_ROAD_FORM_INVALID                                           (15u)

/*! @brief Indicated the form of way */
typedef uint8 LCF_e_NAVIRoadForm_t;

#define lcf_interfaces_LCF_NAVI_BOOTING                                                (0u)
#define lcf_interfaces_LCF_NAVI_NORMAL_OP                                              (1u)
#define lcf_interfaces_LCF_NAVI_NO_SD_CARD                                             (2u)
#define lcf_interfaces_LCF_NAVI_INVALID                                                (3u)

/*! @brief Status of NAVI */
typedef uint8 LCF_e_NAVIStatus_t;

#define lcf_interfaces_LCF_NAVI_PROL_INVALID                                           (0u)
#define lcf_interfaces_LCF_NAVI_PROL_LONGITUDE                                         (1u)
#define lcf_interfaces_LCF_NAVI_PROL_LATITUDE                                          (2u)
#define lcf_interfaces_LCF_NAVI_PROL_ALTITUDE                                          (3u)
#define lcf_interfaces_LCF_NAVI_PROL_CTRL_PT_LONGITUDE                                 (4u)
#define lcf_interfaces_LCF_NAVI_PROL_CTRL_PT_LATITUDE                                  (5u)
#define lcf_interfaces_LCF_NAVI_PROL_CTRL_PT_ALTITUDE                                  (6u)
#define lcf_interfaces_LCF_NAVI_PROL_LINK_IDENT                                        (7u)
#define lcf_interfaces_LCF_NAVI_PROL_TRAFFIC_SIGN                                      (8u)
#define lcf_interfaces_LCF_NAVI_PROL_RESERVED1                                         (9u)
#define lcf_interfaces_LCF_NAVI_PROL_RESERVED2                                         (10u)
#define lcf_interfaces_LCF_NAVI_PROL_RESERVED3                                         (11u)
#define lcf_interfaces_LCF_NAVI_PROL_RESERVED4                                         (12u)
#define lcf_interfaces_LCF_NAVI_PROL_RESERVED5                                         (13u)
#define lcf_interfaces_LCF_NAVI_PROL_RESERVED6                                         (14u)
#define lcf_interfaces_LCF_NAVI_PROL_RESERVED7                                         (15u)
#define lcf_interfaces_LCF_NAVI_PROL_ALERT_INFO_SPOT                                   (16u)

/*! @brief This signal is used to detect if an event from NAVI is transmited */
typedef uint8 LCF_e_NAVIProlProfType_t;

#define lcf_interfaces_LCF_NAVI_TOLLGATE_NOT_DET                                       (0u)
#define lcf_interfaces_LCF_NAVI_TOLLGATE_DET                                           (1u)

/*! @brief This signal is used to receive the info. about the presence of a toolgate in the next 2 km. */
typedef uint8 LCF_e_NAVITollgateDet_t;

#define lcf_interfaces_LCF_HDA_NO_EXT_FAIL                                             (0u)
#define lcf_interfaces_LCF_HDA_EXT_FAIL                                                (1u)

/*! @brief HDA function stop flag received from NORM if some external failures (HDA relevant) are detected by DEM */
typedef uint8 LCF_e_HDAExtFail_t;

#define lcf_interfaces_LCF_SCC_OFF                                                     (0u)
#define lcf_interfaces_LCF_SCC_ON                                                      (1u)

/*! @brief This signal specifies the status of a Main switch of SCC system */
typedef uint8 LCF_e_SCCMainMode_t;

#define lcf_interfaces_LCF_NAVI_SPD_UNIT_NONE                                          (0u)
#define lcf_interfaces_LCF_NAVI_SPD_UNIT_KPH                                           (1u)
#define lcf_interfaces_LCF_NAVI_SPD_UNIT_MPH                                           (2u)
#define lcf_interfaces_LCF_NAVI_SPD_UNIT_INVALID                                       (3u)

/*! @brief Unit of the Speed Limit  from NAVI */
typedef uint8 LCF_e_NAVISpeedUnit_t;

#define lcf_interfaces_LCF_NO_STEER_CONTROL                                            (0u)
#define lcf_interfaces_LCF_STEER_CONTROL                                               (1u)
#define lcf_interfaces_LCF_STEER_ACTUATOR_MODE                                         (2u)
#define lcf_interfaces_LCF_ANGLE_CONTROL_MODE                                          (3u)
#define lcf_interfaces_LCF_STEER_MODE_INVALID                                          (7u)

typedef uint8 LCF_e_EPSStSterCtlMod_t;

#define lcf_interfaces_LCF_EPS_ACT_FACT_OUTPUT                                         (0u)
#define lcf_interfaces_LCF_EPS_ACT_FACT_INPUT                                          (1u)
#define lcf_interfaces_LCF_EPS_ACT_FACT_INVALID                                        (3u)

typedef uint8 LCF_e_EPSStatusECUActFact_t;

#define lcf_interfaces_LCF_EPS_DRV_NO_INTERVENTION                                     (0u)
#define lcf_interfaces_LCF_EPS_DRV_INTERVENTION                                        (1u)
#define lcf_interfaces_LCF_EPS_DRV_INVALID                                             (3u)

typedef uint8 LCF_e_EPSStatusDriverInter_t;

#define lcf_interfaces_TJA_TARGET_OBJ_NOT_DETECTED                                     (0u)
#define lcf_interfaces_TJA_TARGET_OBJ_DETECTED                                         (1u)

/*! @brief Indicates whether TJA target object is detected */
typedef uint8 LCF_INTERFACES_SelectedTargetObjDetected__nu;

#define lcf_interfaces_TJA_EM_GEN_OBJECT_CLASS_POINT                                   (0u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_CLASS_CAR                                     (1u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_CLASS_TRUCK                                   (2u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_CLASS_PEDESTRIAN                              (3u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_CLASS_MOTORCYCLE                              (4u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_CLASS_BICYCLE                                 (5u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_CLASS_WIDE                                    (6u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_CLASS_UNCLASSIFIED                            (7u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_CLASS_TL                                      (8u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES                          (9u)

/*! @brief This signal indicates the class of the object.
Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles */
typedef uint8 LCF_INTERFACES_ObjRecognClassType__nu;

#define lcf_interfaces_TJA_EM_GEN_OBJECT_MT_STATE_DELETED                              (0u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_MT_STATE_NEW                                  (1u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_MT_STATE_MEASURED                             (2u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_MT_STATE_PREDICTED                            (3u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_MT_STATE_INACTIVE                             (4u)
#define lcf_interfaces_TJA_EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES                       (5u)

/*! @brief State of Object Recognization */
typedef uint8 LCF_INTERFACES_ObjRecognMeasState__nu;

#define lcf_interfaces_FROOP_OC_OBJ_QUAL_UNKNOWN                                       (0u)
#define lcf_interfaces_FROOP_OC_OBJ_QUAL_STARTUP                                       (1u)
#define lcf_interfaces_FROOP_OC_OBJ_QUAL_NORMAL_OP                                     (2u)
#define lcf_interfaces_FROOP_OC_OBJ_QUAL_ERR_DRV_SOLVABLE                              (3u)
#define lcf_interfaces_FROOP_OC_OBJ_QUAL_ERR_GARAGE                                    (4u)
#define lcf_interfaces_FROOP_OC_OBJ_QUAL_INVALID                                       (7u)

/*! @brief Qualifier for Oncoming Obj evaluation */
typedef uint8 LCF_e_QuDangOcObjDtct_t;

#define lcf_interfaces_LCF_SYS_OFF                                                     (0u)
#define lcf_interfaces_LCF_LOW_VEH_SPEED                                               (1u)
#define lcf_interfaces_LCF_SYS_UNAVAILABLE                                             (2u)
#define lcf_interfaces_LCF_EPS_CTRL_FULL_LANE_RECOGNIZED                               (3u)
#define lcf_interfaces_LCF_FULL_LANE_RECOGNIZED                                        (4u)
#define lcf_interfaces_LCF_LEFT_LINE_RECOGNIZED                                        (5u)
#define lcf_interfaces_LCF_RIGHT_LINE_RECOGNIZED                                       (6u)
#define lcf_interfaces_LCF_EPS_CTRL_LEFT_LINE_RECOGNIZED                               (7u)
#define lcf_interfaces_LCF_EPS_CTRL_RIGHT_LINE_RECOGNIZED                              (8u)
#define lcf_interfaces_LCF_SYS_NOT_CALIBRATED                                          (14u)
#define lcf_interfaces_LCF_SYS_FAILURE                                                 (15u)

/*! @brief LKAS System State to be sent on the bus */
typedef uint8 LCF_e_LKASLDWSysState_t;

#define lcf_interfaces_LCF_NO_LANE_DEPARTURE                                           (0u)
#define lcf_interfaces_LCF_DEPARTING_LEFT_LANE                                         (1u)
#define lcf_interfaces_LCF_DEPARTING_LEFT_LANE_FAST                                    (2u)
#define lcf_interfaces_LCF_DEPARTING_RIGHT_LANE                                        (3u)
#define lcf_interfaces_LCF_DEPARTING_RIGHT_LANE_FAST                                   (4u)
#define lcf_interfaces_LCF_DEPARTING_LANE_INVALID                                      (7u)

/*! @brief Position of the vehicle wrt to the lanes */
typedef uint8 LCF_e_LaKMCLaneStatus_t;

#define lcf_interfaces_LCF_OPT_USM_INVALID                                             (0u)
#define lcf_interfaces_LCF_OPT_USM_LDW                                                 (1u)
#define lcf_interfaces_LCF_OPT_USM_LKAS_STD                                            (2u)
#define lcf_interfaces_LCF_OPT_USM_LKAS_ACT                                            (3u)
#define lcf_interfaces_LCF_OPT_USM_LDW_ONLY                                            (4u)

/*! @brief (HMC)LDW/LKA System Option and USM setting information */
typedef uint8 LCF_e_Lkas_LDWSOpt_USM_t;

#define lcf_interfaces_LCF_WARN_NOINFO                                                 (0u)
#define lcf_interfaces_LCF_WARN_HANDSOFF                                               (4u)
#define lcf_interfaces_LCF_WARN_SYS_AUTO_OFF                                           (9u)

/*! @brief (HMC)A signal that provides additional information on the operation of the LKAS system for the HMI to display to the driver. This includes additional fault information, reasons for unavailablity of the system and additional warnings like the hands-off warning. Some if the information may be displayed for short periods, whlst others like the hands-off warning may be displayed for longer periods. */
typedef uint8 LCF_e_Lkas_SysWarning_t;

#define lcf_interfaces_LCF_LG_INACTIVE                                                 (0u)
#define lcf_interfaces_LCF_LG_ACTIVE                                                   (1u)

/*! @brief The signal that USM checks in order to display the LG status */
typedef uint8 LCF_e_HdaLgActStatus_t;

#define lcf_interfaces_LCF_MANUAL_SPD_LIMIT                                            (0u)
#define lcf_interfaces_LCF_AUTOMATIC_SPD_LIMIT                                         (1u)

/*! @brief The flag to activate the automatic speed limit change inside SCC */
typedef uint8 LCF_e_SCCAutoSetSpdEnable_t;

#define lcf_interfaces_LCF_AUTO_SET_SPD_UPD_DEFAULT                                    (0u)
#define lcf_interfaces_LCF_AUTO_SET_SPD_UPD_ON                                         (1u)

/*! @brief Indicates whether the set speed is automatically changed (beep sound generated) */
typedef uint8 LCF_e_CLUAutoSetSpdUpdate_t;

#define lcf_interfaces_LCF_HDA_NOT_APPLIED                                             (0u)
#define lcf_interfaces_LCF_HDA_FCT_OFF                                                 (1u)
#define lcf_interfaces_LCF_HDA_FCT_ON                                                  (2u)
#define lcf_interfaces_LCF_HDA_FAIL                                                    (3u)

/*! @brief The status of the HDA Manager */
typedef uint8 LCF_e_CLUHDAStatus_t;

#define lcf_interfaces_LCF_HDA_MODE_OFF                                                (0u)
#define lcf_interfaces_LCF_HDA_MODE_READY                                              (1u)
#define lcf_interfaces_LCF_HDA_MODE_ACT                                                (2u)
#define lcf_interfaces_LCF_HDA_MODE_RESERVED                                           (3u)

/*! @brief The Control Mode of HDA */
typedef uint8 LCF_e_CLUHDAMode_t;

#define lcf_interfaces_LCF_HDA_NO_LANE                                                 (0u)
#define lcf_interfaces_LCF_HDA_LEFT_LANE                                               (1u)
#define lcf_interfaces_LCF_HDA_RIGHT_LANE                                              (2u)
#define lcf_interfaces_LCF_HDA_FULL_LANE                                               (3u)

/*! @brief HDA Lane Detection Information */
typedef uint8 LCF_e_CLULaneDetect_t;

#define lcf_interfaces_LCF_HDA_DISP_NONE                                               (0u)
#define lcf_interfaces_LCF_HDA_DISP_SYS_START                                          (1u)
#define lcf_interfaces_LCF_HDA_DISP_SYS_AUTO_DISENG_HWY_OFF                            (2u)
#define lcf_interfaces_LCF_HDA_DISP_RESERVED1                                          (3u)
#define lcf_interfaces_LCF_HDA_DISP_SYS_FAIL_POPUP                                     (4u)
#define lcf_interfaces_LCF_HDA_DISP_HANDS_OFF_POPUP                                    (5u)
#define lcf_interfaces_LCF_HDA_DISP_HANDS_OFF_POPUP_W_SOUND                            (6u)
#define lcf_interfaces_LCF_HDA_YS_AUTO_OFF                                             (7u)

/*! @brief This is HDA information display needed for the cluster pop-up display */
typedef uint8 LCF_e_CLUHDAInfoDisplay_t;

#define lcf_interfaces_LCF_HDA_SYMB_OFF                                                (0u)
#define lcf_interfaces_LCF_HDA_SYMB_GRAY                                               (1u)
#define lcf_interfaces_LCF_HDA_SYMB_GREEN                                              (2u)
#define lcf_interfaces_LCF_HDA_SYMB_GREEN_BLINK                                        (3u)

/*! @brief This signal contains the HDA/LFA steering wheel symbol states to be displayed for the driver. */
typedef uint8 LCF_e_CLUHdaLfaSymbolState_t;

#define lcf_interfaces_LCF_TJA_LATCTRLMD_PASSIVE                                       (0u)
#define lcf_interfaces_LCF_TJA_LATCTRLMD_LNCENTRING                                    (1u)
#define lcf_interfaces_LCF_TJA_LATCTRLMD_OBJFOLLWNG                                    (2u)
#define lcf_interfaces_LCF_TJA_LATCTRLMD_COMBINED                                      (3u)
#define lcf_interfaces_LCF_TJA_LATCTRLMD_RQLNCENTRING                                  (4u)
#define lcf_interfaces_LCF_TJA_LATCTRLMD_RQOBJFOLLWNG                                  (5u)
#define lcf_interfaces_LCF_TJA_LATCTRLMD_RQCOMBINED                                    (6u)
#define lcf_interfaces_LCF_TJA_LATCTRLMD_INVALID                                       (15u)

typedef uint8 LCF_e_LatCtrlMod_t;

#define lcf_interfaces_LCF_DRV_ATTENTION_WRNG_STATE_NO_WARNING                         (0u)
#define lcf_interfaces_LCF_DRV_ATTENTION_WRNG_STATE_ATTENTIVNESS_REQUEST               (1u)
#define lcf_interfaces_LCF_DRV_ATTENTION_WRNG_STATE_TAKE_OVER_REQUEST                  (2u)
#define lcf_interfaces_LCF_DRV_ATTENTION_WRNG_STATE_DEGRADATION_TRIGGERED              (3u)

/*! @brief Qualifier of the driver attention warning state machine, which will be shown on HMI to the driver */
typedef uint8 LCF_INTERFACES_DrvAttWarnQualifier__nu;

#define lcf_interfaces_LCF_LADMC_OFF                                                   (0u)
#define lcf_interfaces_LCF_LADMC_ON                                                    (1u)
#define lcf_interfaces_LCF_LADMC_DRV_SUPPORT_STEER                                     (2u)
#define lcf_interfaces_LCF_LADMC_DRV_COUNTER_STEER                                     (3u)
#define lcf_interfaces_LCF_LADMC_PERM_DISABLED                                         (4u)
#define lcf_interfaces_LCF_LADMC_TEMP_DISABLED                                         (5u)
#define lcf_interfaces_LCF_LADMC_REQUEST                                               (6u)

/*! @brief  Operation status of the LaDMC for consideration in the LaKMC */
typedef uint8 LCF_e_LaDMCStatus_t;

#define lcf_interfaces_LCF_DEACTIVATE_TOI                                              (0u)
#define lcf_interfaces_LCF_ACTIVATE_TOI                                                (1u)

/*! @brief This is a flag that is set to 1 when requesting the steering to activate the torque overlay interface (TOI).  This must be done before an attempt is made to request non-zero steering torque overlay. */
typedef uint8 LCF_e_LKASActToi_t;

#define lcf_interfaces_LCF_NO_FAULT                                                    (0u)
#define lcf_interfaces_LCF_FAULT_PRESENT                                               (1u)

/*! @brief This fault flag is set when a fault in the LKAS system has been detected by the LKAS ECU such that LKAS can no longer function. CAN failures, internal video ECU failures, hard-wired component (e.g. master switch) failures and other system logic failures are all reported by this flag. Failures reported by the MDPS are not looped back through this flag. */
typedef uint8 LCF_e_LKASToiFlt_t;

#define lcf_interfaces_LCF_DONOT_REALIZE_TGT_VALUE_QUALIFIER                           (4u)
#define lcf_interfaces_LCF_REALIZE_CRV_QUALIFIER                                       (8u)
#define lcf_interfaces_LCF_REALIZE_CRV_SIDE_SLIP_QUALIFIER                             (9u)

/*! @brief Qualifier sent to DMC which indicates whether to active DMC or not. (DMC on EBS variant) */
typedef uint8 LCF_INTERFACES_LaKMC_QuTgtVehCtrl__nu;

#define lcf_interfaces_LCF_OFF                                                         (0u)
#define lcf_interfaces_LCF_LKA                                                         (1u)
#define lcf_interfaces_LCF_LDP                                                         (2u)
#define lcf_interfaces_LCF_LDPOC                                                       (3u)
#define lcf_interfaces_LCF_RDP                                                         (4u)
#define lcf_interfaces_LCF_ALCA                                                        (5u)
#define lcf_interfaces_LCF_AOLC                                                        (6u)
#define lcf_interfaces_LCF_ESA                                                         (7u)
#define lcf_interfaces_LCF_TJA                                                         (8u)

typedef uint8 LCF_e_ControllingFunction_t;

#define lcf_interfaces_LCF_TRAJ_PLAN_LAT_CTRL_COORD_SERVICE_QU_COL_CHECK_CRIDR_LIMITS  (0u)
#define lcf_interfaces_LCF_TRAJ_PLAN_LAT_CTRL_COORD_SERVICE_QU_COL_CHECK_OBJ           (1u)
#define lcf_interfaces_LCF_TRAJ_PLAN_LAT_CTRL_COORD_SERVICE_QU_FTIRE_CHECK             (2u)

typedef uint8 LCF_INTERFACES_TrajServiceQualifier__nu;

#define lcf_interfaces_LCF_DMC_NOABORT_REQUEST                                         (0u)
#define lcf_interfaces_LCF_DMC_ABORT_REQUEST                                           (1u)

/*! @brief When LCF judges to abort condition, DMC  shall set EPS request[Nm or rad]  to 0 immediately. (requirement from TMC) */
typedef uint8 LCF_e_LcfCtrlAbort_t;

#define lcf_interfaces_LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_DONOT_REALIZE_TGT_VALUE_QUALIFIER   (4u)
#define lcf_interfaces_LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_REALIZE_CRV_QUALIFIER               (8u)
#define lcf_interfaces_LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_REALIZE_CRV_SIDE_SLIP_QUALIFIER     (9u)

/*! @brief Qualifier of output */
typedef uint8 LCF_INTERFACES_TgtVehCtrlQualifier__nu;

#define lcf_interfaces_opModeReset                                                     (0u)   /*!< Reset */
#define lcf_interfaces_opModePause                                                     (1u)   /*!< Pause */
#define lcf_interfaces_opModeNormal                                                    (2u)   /*!< Normal */

/*! @brief OpMode(LCF_INTERFACES) */
typedef uint8 LCF_INTERFACES_OpMode;

#define lcf_interfaces_opModeReset                                                     (0u)   /*!< Reset */
#define lcf_interfaces_opModePause                                                     (1u)   /*!< Pause */
#define lcf_interfaces_opModeNormal                                                    (2u)   /*!< Normal */

/*! @brief OpMode(LCF_INTERFACES) */
typedef uint8 LCF_INTERFACES_OpMode;


/*! @brief Corridor for trajectory planning */
typedef struct
{
    float32                                            CorridorPosX0__m;                         /*!< Corridor x-position at start, Unit: [m]  */
    float32                                            CorridorPosY0__m;                         /*!< Corridor y-position at start, Unit: [m]  */
    float32                                            CorridorHeading__rad;                     /*!< Corridor heading angle, Unit: [rad]  */
    float32                                            CorridorCrv__1pm;                         /*!< Corridor curvature, Unit: [1/m]  */
    float32                                            CorridorChngOfCrv__1pm2;                  /*!< Corridor curvature rate, Unit: [1/m^2]  */
    float32                                            CorridorLength__m;                        /*!< Valid length of corridor, Unit: [m]  */
} LCF_INTERFACES_LCF_TrajPlanCorridor_t;

/*! @brief LCF side object properties */
typedef struct
{
    float32                                            PosX__m;                                  /*!< longitudinal position of side object, Unit: [m]  */
    float32                                            PosY__m;                                  /*!< lateral position of side object, Unit: [m]  */
    float32                                            RelVelX__mps;                             /*!< longitudinal velocity of side object, Unit: [m/s]  */
    float32                                            RelVelY__mps;                             /*!< lateral velocity of side object, Unit: [m/s]  */
    float32                                            RelAclX__mps2;                            /*!< longitudinal acceleration of side object, Unit: [m/s^2]  */
    float32                                            RelAclY__mps2;                            /*!< lateral acceleration of side object, Unit: [m/s^2]  */
    uint8                                              Quality__nu;                              /*!< quality of side object, Unit: [%]  */
    uint8                                              MeasState__nu;                            /*!< measurement state of side object  */
    uint8                                              ObjRecognClassType__nu;                   /*!< This signal indicates the class of the object. Classification limitation especially for pedestrians and bicycles  */
    uint32                                             ObjTstamp__us;                            /*!< time stamp of side object, Unit: [us]  */
} LCF_INTERFACES_LCF_SideObject_t;

/*! @brief Corridor for trajectory planning */
typedef struct
{
    uint16                                             EventId__nu;                              /*!< Corridor x-position at start  */
    uint16                                             EventLifetime__nu;                        /*!< Corridor y-position at start  */
} LCF_INTERFACES_LCF_Event_t;

typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    uint8                                              VcsLcfVariantNumber__nu;                  /*!< This signal is provided by the VCS component. The signal represents the conding variant number that shall be used by the LCF  */
    float32                                            Y_DPLSMI_CrvICDlcOffset_met[6];
    float32                                            Y_DPLSMI_CrvOCDlcOffset_met[6];
    float32                                            Y_DPLSMI_LWTrigDlcScalFact_nu[6];
    float32                                            Y_DPLSMI_LWTrigTlcScalFact_nu[6];
    float32                                            Y_DPLSMI_VXMD1TrigDlc_met[8];
    float32                                            Y_DPLSMI_VXMD2TrigDlc_met[8];
    float32                                            Y_DPLSMI_VXMD3TrigDlc_met[8];
    float32                                            Y_DPLSMI_VXTrigTlc_sec[8];
    float32                                            P_DPLSMI_TlcDistanceMin_met;
    float32                                            Y_DPLSMW_CrvICDlcOffset_met[6];
    float32                                            Y_DPLSMW_CrvOCDlcOffset_met[6];
    float32                                            Y_DPLSMW_LWTrigDlcScalFact_nu[6];
    float32                                            Y_DPLSMW_LWTrigTlcScalFact_nu[6];
    float32                                            Y_DPLSMW_VXMD1TrigDlc_met[8];
    float32                                            Y_DPLSMW_VXMD2TrigDlc_met[8];
    float32                                            Y_DPLSMW_VXTrigTlc_sec[8];
    float32                                            P_DPLSMW_TlcDistanceMin_met;
    float32                                            Y_DPRSMI_CrvICDlcOffset_met[6];
    float32                                            Y_DPRSMI_CrvOCDlcOffset_met[6];
    float32                                            Y_DPRSMI_LWTrigDlcScalFact_nu[6];
    float32                                            Y_DPRSMI_LWTrigTlcScalFact_nu[6];
    float32                                            Y_DPRSMI_VXMD1TrigDlc_met[8];
    float32                                            Y_DPRSMI_VXMD2TrigDlc_met[8];
    float32                                            Y_DPRSMI_VXTrigDrcDlc_met[8];
    float32                                            Y_DPRSMI_VXTrigDrc_met[8];
    float32                                            Y_DPRSMI_VXTrigTlc_sec[8];
    float32                                            Y_DPRSMI_VXTrigTrcTlc_sec[8];
    float32                                            Y_DPRSMI_VXTrigTrc_sec[8];
    float32                                            Y_DPRSMI_VXMD1TrigTrcTlc_sec[8];
    float32                                            Y_DPRSMI_VXMD1TrigTrc_sec[8];
    float32                                            Y_DPRSMI_VXMD2TrigTrcTlc_sec[8];
    float32                                            Y_DPRSMI_VXMD2TrigTrc_sec[8];
    float32                                            Y_DPRSMW_CrvICDlcOffset_met[6];
    float32                                            Y_DPRSMW_CrvOCDlcOffset_met[6];
    float32                                            Y_DPRSMW_LWTrigDlcScalFact_nu[6];
    float32                                            Y_DPRSMW_LWTrigTlcScalFact_nu[6];
    float32                                            Y_DPRSMW_VXMD1TrigDlc_met[8];
    float32                                            Y_DPRSMW_VXMD2TrigDlc_met[8];
    float32                                            Y_DPRSMW_VXTrigDrcDlc_met[8];
    float32                                            Y_DPRSMW_VXTrigDrc_met[8];
    float32                                            Y_DPRSMW_VXTrigTlc_sec[8];
    float32                                            Y_DPRSMW_VXTrigTrcTlc_sec[8];
    float32                                            Y_DPRSMW_VXTrigTrc_sec[8];
    float32                                            Y_DPRSMW_VXMD1TrigTrcTlc_sec[8];
    float32                                            Y_DPRSMW_VXMD1TrigTrc_sec[8];
    float32                                            Y_DPRSMW_VXMD2TrigTrcTlc_sec[8];
    float32                                            Y_DPRSMW_VXMD2TrigTrc_sec[8];
    float32                                            Y_DPODOO_TrigTlcValVx_sec[8];
    float32                                            Y_DPODOO_TrigTtcValVx_sec[8];
    float32                                            Y_DPODOO_TrigTlcTtcOffsetVx_sec[8];
    float32                                            Y_DPODOO_TrigTlcScalFactLw_nu[6];
    float32                                            Y_DPODOO_TrigDlcObjValVx_met[8];
    float32                                            Y_DPODOO_TrigDlcObjScalFactLw_nu[6];
    float32                                            Y_DPODOO_TrigDlcEgoValVxMd2_met[8];
    float32                                            Y_DPODOO_TrigDlcEgoValVxMd1_met[8];
    float32                                            Y_DPODOO_TrigDlcEgoScalFactLw_nu[6];
    float32                                            Y_DPODOO_TrigDlcEgoValCrvIC_met[6];
    float32                                            Y_DPODOO_TrigDlcEgoValCrvOC_met[6];
} LCF_INTERFACES_CPAR_LCF_TunParamsLDP;           /* @versionstr: LCF_TUN_PAR_LDP_INTFVER */

typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    uint16                                             P_LTAMGR_VCS_Info_btm;                    /*!< This parameter is provided by the LTA Manager  */
    float32                                            Y_LTAMGR_ManualTrqDumpGain_nu[15];        /*!< This parameter is provided by the LTA Manager  */
    float32                                            X_LTAMGR_ManualTrqActualVal_Nm[16];       /*!< This parameter is provided by the LTA Manager  */
    float32                                            Y_LTAMGR_CrvDumpGain_nu[4];               /*!< This parameter is provided by the LTA Manager  */
    float32                                            X_LTAMGR_CntrLnClthCurvR_met[5];          /*!< This parameter is provided by the LTA Manager  */
    float32                                            Y_LTAMGR_TgtStrAngGuard_deg[22];          /*!< This parameter is provided by the LTA Manager  */
    float32                                            Y_LTAMGR_TgtStrAngRateGuard_dps[22];      /*!< This parameter is provided by the LTA Manager  */
    float32                                            Y_LTAMGR_TgGainDcrStartTrq_nm[22];        /*!< This parameter is provided by the LTA Manager  */
    float32                                            Y_LTAMGR_TgGainDcrEndTrq_nm[22];          /*!< This parameter is provided by the LTA Manager  */
} LCF_INTERFACES_CPAR_LCF_TunParamsLKA;           /* @versionstr: LCF_TUN_PAR_LKA_INTFVER */

typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    uint8                                              P_TPLFBT_TgtCrvSwitch_nu;
    uint8                                              P_TPLCEN_DrvTqrReplanEnable_nu;
    float32                                            P_TPLCEN_ErrDistY_met;
    float32                                            P_TPLCEN_ErrHeadAglPrev_rad;
    float32                                            P_TPLCEN_ManualTrqImpuls_Nm;
    float32                                            P_TPLCEN_ManualTrqTime_sec;
    uint8                                              P_TPLCEN_ParamInternal_nu;
    uint8                                              P_TPLCEN_PlanTgtValueSwitch_nu;
    uint8                                              P_TPLCEN_RelTrigCustFctRplCur_nu;
    uint8                                              P_TPLCEN_TrajPlanEnable_nu;
    float32                                            P_TPLCEN_CyCTimeTrajCalc_sec;
    uint8                                              P_TPLCEN_CycEnable_nu;
    uint8                                              P_TPLTJC_ColldetActive_nu;
    float32                                            P_TPLTJC_MaxArcLength_met;
    uint8                                              P_TPLTJC_NumCircles_nu;
    uint8                                              P_TPLTJC_ParamCostFctInternal_nu;
    float32                                            P_TPLTJC_TMax_nu;
    uint8                                              P_TPLTJC_TimeTrajEndEnable__nu;
    float32                                            P_TPLTJC_WeightDistBased_nu;
    float32                                            Y_TPLTJC_WghtTgtDistYCharact_nu[2];
    float32                                            X_TPLTJC_WghtTgtDistYCustFct_nu[2];
    float32                                            P_TPLTJC_WeightTgtDistY_nu;
    float32                                            Y_TPLTJC_WghtTgtTimeCharact_nu[2];
    float32                                            X_TPLTJC_WghtTgtTimeCustFct_nu[2];
    float32                                            P_TPLTJC_WeightTgtTime_nu;
    float32                                            P_TPLCEN_VMinTimeBasedTraj_kph;
    uint8                                              P_TPLLCO_PreviewDistXEnable_nu;
    float32                                            X_TPLLCO_VehVelX_mps[13];
    float32                                            Y_TPLLCO_PreviewDistX_met[13];
    uint8                                              P_TCTLGC_CrvDifftoZeroSW_nu;
    float32                                            P_TCTLGC_CrvErrCorrTime_sec;
    float32                                            P_TCTLGC_CrvErrorD_nu;
    float32                                            P_TCTLGC_CrvErrorI_nu;
    float32                                            P_TCTLGC_CrvErrorILimit_nu;
    float32                                            P_TCTLGC_CrvErrorP_nu;
    float32                                            P_TCTLGC_DistYGain_nu;
    uint8                                              P_TCTLGC_DTTCFunction_nu;
    float32                                            P_TCTLGC_FactorDistYFromErrY_nu;
    float32                                            P_TCTLGC_FactorHeadFromDistY_nu;
    uint8                                              P_TCTLGC_FlxOverallGainEnable_nu;
    float32                                            P_TCTLGC_HeadingGain_nu;
    float32                                            P_TCTLGC_LateralCrvBeta_nu;
    float32                                            P_TCTLGC_LateralErrorAlpha_nu;
    float32                                            P_TCTLGC_LateralErrorILimit_met;
    float32                                            P_TCTLGC_LateralOffset_met;
    uint8                                              P_TCTLGC_LCFControllerEnable_nu;
    float32                                            P_TCTLGC_MaximumCorrDist_nu;
    float32                                            P_TCTLGC_MaximumCrv_1pm;
    float32                                            P_TCTLGC_MinimumCorrDist_nu;
    float32                                            P_TCTLGC_MinimumCrv_1pm;
    float32                                            P_TCTLGC_OverallGain_nu;
    float32                                            P_TCTLGC_PT1FilterCorrDist_nu;
    float32                                            P_TCTLGC_SpeedThreshold_mps;
    float32                                            X_TCTLGC_Curve_1pm[9];
    float32                                            X_TCTLGC_DTTC_met[5];
    float32                                            X_TCTLGC_DTTCTBVelX_mps[14];
    float32                                            X_TCTLGC_FactorCrvDistY_nu[7];
    float32                                            X_TCTLGC_FactorCrvHead_nu[7];
    float32                                            X_TCTLGC_OverallGainVelX_mps[16];
    float32                                            X_TCTLGC_Vel_mps[16];
    float32                                            Y_TCTLGC_DistYGain_nu[15];
    float32                                            Y_TCTLGC_DTTCGain_nu[4];
    float32                                            Y_TCTLGC_DTTCTBTime_sec[13];
    float32                                            Y_TCTLGC_FactorCrvCurveDistY_nu[8];
    float32                                            Y_TCTLGC_FactorCrvCurveHead_nu[8];
    float32                                            Y_TCTLGC_FactorCrvDistY_nu[6];
    float32                                            Y_TCTLGC_FactorCrvDistYLKA_nu[6];
    float32                                            Y_TCTLGC_FactorCrvHead_nu[6];
    float32                                            Y_TCTLGC_FactorCrvHeadLKA_nu[6];
    float32                                            Y_TCTLGC_FlxOverallGain_nu[15];
    float32                                            Y_TCTLGC_HeadingGain_nu[15];
    uint8                                              P_TCTCDC_PT1CurDistYEnable_nu;
    float32                                            P_TCTCDC_PT1CurDistYTime_sec;
    uint8                                              P_TCTCDC_PT1CurHeadingEnable_nu;
    float32                                            P_TCTCDC_PT1CurHeadingTime_sec;
    uint8                                              P_TCTCDC_PT1DevHeadingEnable_nu;
    float32                                            P_TCTCDC_PT1DevHeadingTime_sec;
    uint8                                              P_TCTDTE_ClearToZeroCrvDistrb_nu;
    uint8                                              P_TCTDTE_ClrZeroHeadAglDistrb_nu;
    float32                                            P_TCTDTE_DebounceTimerHold_sec;
    float32                                            P_TCTDTE_DeZoneHeadAglDistrb_rad;
    float32                                            P_TCTDTE_DmpngCrvBuildup_nu;
    float32                                            P_TCTDTE_DmpngCrvReduction_nu;
    float32                                            P_TCTDTE_DmpngCtrlledSys_nu;
    float32                                            P_TCTDTE_DmpngGrdLimitBuildup_nu;
    float32                                            P_TCTDTE_DmpngGrdLimRed_nu;
    float32                                            P_TCTDTE_DmpngHeadingAngle_nu;
    uint8                                              P_TCTDTE_EstiBankAngleEnable_nu;
    float32                                            P_TCTDTE_GrdGHold_nu;
    float32                                            P_TCTDTE_MinimumSpeed_mps;
    float32                                            P_TCTDTE_StartValTimerHold_sec;
    uint8                                              P_TCTDTE_SwitchCtrlErrHeading_nu;
    float32                                            P_TCTDTE_TConstCrvBuildup_sec;
    float32                                            P_TCTDTE_TConstCrvRed_sec;
    float32                                            P_TCTDTE_TConstCrvSlBdup_sec;
    float32                                            P_TCTDTE_TConstCtrlledSys_sec;
    float32                                            P_TCTDTE_TConstGrdLimBdup_sec;
    float32                                            P_TCTDTE_TConstGrdLimRed_sec;
    float32                                            P_TCTDTE_TConstGrdLimSlBdup_sec;
    float32                                            P_TCTDTE_TConstHeadAgl_sec;
    float32                                            P_TCTDTE_ThActualManualTrq_Nm;
    float32                                            P_TCTDTE_ThCtrlErrLatOffset_met;
    float32                                            P_TCTDTE_ThStrAglFRAxlEffGrd_rps;
    float32                                            P_TCTDTE_TStrAglFRAxlEff_sec;
    float32                                            X_TCTDTE_DetaVehVelToScalCrv_mps[10];
    float32                                            X_TCTDTE_FactorLatSlpVehVelX_nu[9];
    float32                                            X_TCTDTE_InputVehVelSat_met[8];
    float32                                            X_TCTDTE_InputVehVelScaling_mps[7];
    float32                                            Y_TCTDTE_DetaVehVelToScalCrvStartVal_nu[9];
    float32                                            Y_TCTDTE_FactorLatSlpVehVelY_nu[8];
    float32                                            Y_TCTDTE_InputVehVelToScalCrv_nu[6];
    float32                                            Y_TCTDTE_LatSlpFromCrvYAxis_rad[5];
    float32                                            Y_TCTDTE_ManuTrqActValScalCrv_nu[11];
    float32                                            Y_TCTDTE_VelXToMaxCrv_1pm[7];
    float32                                            Y_TCTDTE_VelXToMaxHeadAgl_rad[7];
    float32                                            Y_TCTDTE_VelXToMaxLatSlp_rad[7];
    uint8                                              P_TCTDTE_BankAngleCrvActive_nu;
    float32                                            P_TCTLGC_DistYGainLDP_nu;
    float32                                            P_TCTLGC_HeadingGainLDP_nu;
    float32                                            Y_TCTLGC_DistYD_nu[15];
    float32                                            P_DRMHOD_EstHandTqFilterC[8];             /*!< Depends on vehicle line, vehicle code  */
    float32                                            P_DRMHOD_HandsOffTqLim_Nm;                /*!< Depends on vehicle line, vehicle code  */
    float32                                            P_DRMHOD_HandsOnTorLimAbs_Nm;             /*!< Depends on vehicle line, vehicle code  */
    float32                                            P_DRMHOD_HandsOnTqLim_Nm;                 /*!< Depends on vehicle line, vehicle code  */
    float32                                            C_DRVMN_DebHorAfterHandsOff_sec[10];
    float32                                            C_DRVMN_DebounceTorAfterHor_sec[10];
    float32                                            P_DRMDAE_TrigDegrAftTorTime_sec[10];
    uint8                                              P_DRMDAE_IncWarningTime_bool;             /*!< Depends on vehicle line, vehicle code  */
    float32                                            P_DRMDAE_TrigDegrAftTorTime_sec[10];
    uint8                                              P_DRMDAE_IncWarningTime_bool;             /*!< Depends on vehicle line, vehicle code  */
} LCF_INTERFACES_CPAR_LCF_TunParamsKMC;           /* @versionstr: LCF_TUN_PAR_KMC_INTFVER */

typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    uint16                                             RTE_Dit_dirac_loop_count;
    uint16                                             RTE_Dit_signal_gen_frequency;
    uint16                                             RTE_Dit_torque_pulse_amplitude;
    uint16                                             RTE_Dmc_configuration_mode;
    uint16                                             RTE_Dmc_generic_00;
    uint16                                             RTE_Dmc_generic_01;
    uint16                                             RTE_Dmc_generic_02;
    uint16                                             RTE_Dmc_generic_03;
    uint16                                             RTE_Dmc_generic_04;
    uint16                                             RTE_Dmc_generic_05;
    uint16                                             RTE_Dmc_generic_06;
    uint16                                             RTE_Dmc_generic_07;
    uint16                                             RTE_Dmc_generic_08;
    uint16                                             RTE_Dmc_generic_09;
    sint16                                             RTE_Dmc_generic_10;
    sint16                                             RTE_Dmc_generic_11;
    sint16                                             RTE_Dmc_generic_12;
    sint16                                             RTE_Dmc_generic_13;
    sint16                                             RTE_Dmc_generic_14;
    sint16                                             RTE_Dmc_generic_15;
    sint16                                             RTE_Dmc_generic_16;
    sint16                                             RTE_Dmc_generic_17;
    sint16                                             RTE_Dmc_generic_18;
    sint16                                             RTE_Dmc_generic_19;
    uint16                                             RTE_Dyc_boost_signal_reduction;
    uint16                                             RTE_Dyc_compensation_mode;
    uint16                                             RTE_Dyc_kappa_a2_boost_factor;
    uint16                                             RTE_Dyc_kappa_a2_factor;
    uint16                                             RTE_Dyc_kappa_a2_y_scheduling[12];
    uint16                                             RTE_Dyc_kappa_a3_factor;
    uint16                                             RTE_Dyc_kappa_a3_y_scheduling[11];
    uint16                                             RTE_Dyc_kappa_angle_corr_factor;
    uint16                                             RTE_Dyc_kappa_angle_gen_cor_fct_neg;
    uint16                                             RTE_Dyc_kappa_angle_gen_corr_factor;
    uint16                                             RTE_Dyc_kappa_angle_lpf_corr_factor;
    uint16                                             RTE_Dyc_kappa_angle_t_y_sch_gen_neg[12];
    uint16                                             RTE_Dyc_kappa_angle_t_y_schedul_gen[12];
    uint16                                             RTE_Dyc_kappa_dot_boost_thrs;
    uint16                                             RTE_Dyc_kappa_dot_filter_coeff;
    uint16                                             RTE_Dyc_state_filter_time_constant;
    uint16                                             RTE_Dyc_time_constant_y_scheduling[12];
    uint16                                             RTE_Eps_d;
    uint16                                             RTE_Eps_one_by_j_motor;
    uint16                                             RTE_Eps_torque_comp_factor;
    uint16                                             RTE_Hec_controller_mode;
    uint16                                             RTE_Lat_2nd_rate_ctrl_filter_coeff;
    uint16                                             RTE_Lat_2nd_rate_ctrl_max_p_part;
    uint16                                             RTE_Lat_2nd_rate_ctrl_max_pt1_part;
    uint16                                             RTE_Lat_2nd_rate_limit_ctrl_kp;
    uint16                                             RTE_Lat_2nd_rate_limit_ctrl_pt1_kp;
    uint16                                             RTE_Lat_ay_control_kp;
    uint16                                             RTE_Lat_ay_control_pt1_kp;
    uint16                                             RTE_Lat_ay_controller_coeff;
    uint16                                             RTE_Lat_ay_max_support_y_scheduling[12];
    uint16                                             RTE_Lat_ay_max_y_scheduling[12];
    uint16                                             RTE_Lat_ay_requested_filter_coeff;
    uint16                                             RTE_Lat_damp_level_grad_off;
    uint16                                             RTE_Lat_damp_level_grad_on;
    uint16                                             RTE_Lat_delta_f_dot_filter_coeff;
    sint16                                             RTE_Lat_delta_f_offset;
    uint16                                             RTE_Lat_delta_off_flt_initial_loops;
    uint16                                             RTE_Lat_delta_off_flt_initial_omega;
    uint16                                             RTE_Lat_delta_offset_filter_coeff;
    uint16                                             RTE_Lat_delta_offset_filter_omega;
    uint16                                             RTE_Lat_derating_factor_filt_coeff;
    sint16                                             RTE_Lat_direct_feedthr_hf_part_trq;
    uint16                                             RTE_Lat_direct_feedthr_kappa_ctrl;
    uint16                                             RTE_Lat_direct_feedthrough_kappa;
    sint16                                             RTE_Lat_direct_feedthrough_trq;
    uint16                                             RTE_Lat_direct_feedthrough_trq_ldp;
    uint16                                             RTE_Lat_dmc_status_override_cycles;
    sint16                                             RTE_Lat_eps_trq_can_scaling_factor;
    uint16                                             RTE_Lat_feedthr_increment_per_loop;
    sint16                                             RTE_Lat_ffwd_rate_control_min_error;
    sint16                                             RTE_Lat_ffwd_rate_control_pt1_kp;
    sint16                                             RTE_Lat_ffwd_rate_limit_control_kp;
    sint16                                             RTE_Lat_ffwd_rate_pt1_filter_coeff;
    sint16                                             RTE_Lat_ffwd_rate_pt1_max_coeff;
    uint16                                             RTE_Lat_kappa_ctrl_discharge_grad;
    uint16                                             RTE_Lat_kappa_ctrl_discharge_mn_err;
    uint16                                             RTE_Lat_kappa_ctrl_discharge_slope;
    uint16                                             RTE_Lat_kappa_ctrl_lat_error_slope;
    uint16                                             RTE_Lat_kappa_ctrl_max_lateral_err;
    uint16                                             RTE_Lat_kappa_discharge_gradient;
    uint16                                             RTE_Lat_kappa_discharge_min_error;
    uint16                                             RTE_Lat_kappa_discharge_slope;
    uint16                                             RTE_Lat_kappa_filter_coeff;
    uint16                                             RTE_Lat_kappa_lateral_error_slope;
    uint16                                             RTE_Lat_kappa_linz_error_slope;
    uint16                                             RTE_Lat_kappa_linz_filt_max_error;
    uint16                                             RTE_Lat_kappa_linz_filter_max_omega;
    uint16                                             RTE_Lat_kappa_linz_filter_min_omega;
    uint16                                             RTE_Lat_kappa_linz_max_omega_memshp;
    uint16                                             RTE_Lat_kappa_linz_weighting_factor;
    uint16                                             RTE_Lat_kappa_max_lateral_error;
    uint16                                             RTE_Lat_kppa_min_omega_y_scheduling[12];
    uint16                                             RTE_Lat_ldp_startup_time;
    uint16                                             RTE_Lat_linz_error_slope;
    uint16                                             RTE_Lat_linz_filter_max_error;
    uint16                                             RTE_Lat_linz_filter_max_omega;
    uint16                                             RTE_Lat_linz_filter_min_omega;
    sint16                                             RTE_Lat_max_ay;
    uint16                                             RTE_Lat_max_ay_extrapolation_gain;
    uint16                                             RTE_Lat_max_ay_hand_off;
    uint16                                             RTE_Lat_max_ay_hand_off_kneepoint;
    uint16                                             RTE_Lat_max_kappa_ctrl_grad_y_sched[12];
    uint16                                             RTE_Lat_max_kappa_ctrl_gradient;
    uint16                                             RTE_Lat_max_kappa_gradient;
    sint16                                             RTE_Lat_max_output_torque;
    uint16                                             RTE_Lat_max_torque_corr_factor;
    uint16                                             RTE_Lat_max_torque_select;
    sint16                                             RTE_Lat_max_torque_x_scheduling[12];
    sint16                                             RTE_Lat_max_torque_y_scheduling[12];
    sint16                                             RTE_Lat_min_damping_level_x[4];
    sint16                                             RTE_Lat_min_damping_level_y[4];
    sint16                                             RTE_Lat_min_offset_state;
    uint16                                             RTE_Lat_oc_fast_ki;
    uint16                                             RTE_Lat_oc_kappa_cmd_filter_coeff;
    uint16                                             RTE_Lat_oc_kappa_max_driver_torque;
    uint16                                             RTE_Lat_oc_kappa_max_heading_error;
    uint16                                             RTE_Lat_oc_kappa_min_head_err_qual;
    uint16                                             RTE_Lat_oc_kappa_min_latency;
    sint16                                             RTE_Lat_oc_ki;
    uint16                                             RTE_Lat_oc_max_delta_f_dot;
    uint16                                             RTE_Lat_oc_max_delta_offset;
    uint16                                             RTE_Lat_oc_max_delta_offset_kappa;
    uint16                                             RTE_Lat_oc_max_driver_torque;
    uint16                                             RTE_Lat_oc_max_kappa;
    uint16                                             RTE_Lat_oc_max_kappa_dys;
    uint16                                             RTE_Lat_oc_max_lateral_accel;
    uint16                                             RTE_Lat_oc_max_lateral_error;
    uint16                                             RTE_Lat_oc_max_velocity;
    sint16                                             RTE_Lat_oc_min_kappa_quality;
    uint16                                             RTE_Lat_oc_min_velocity;
    uint16                                             RTE_Lat_oc_min_velocity_dys;
    uint16                                             RTE_Lat_oc_minimum_latency;
    uint16                                             RTE_Lat_oc_minimum_latency_shrt;
    sint16                                             RTE_Lat_offset_inc_per_loop_slow;
    sint16                                             RTE_Lat_offset_inc_per_loop_turn_on;
    sint16                                             RTE_Lat_offset_increment_per_loop;
    sint16                                             RTE_Lat_offset_max;
    sint16                                             RTE_Lat_offset_max_clm_trq;
    sint16                                             RTE_Lat_offset_max_steer_angle;
    sint16                                             RTE_Lat_out_direct_feedthrough_trq;
    uint16                                             RTE_Lat_out_torque_gradient;
    uint16                                             RTE_Lat_rate_control_d_filter_coeff;
    uint16                                             RTE_Lat_rate_control_max_p_part;
    uint16                                             RTE_Lat_rate_control_max_pt1_part;
    uint16                                             RTE_Lat_rate_ctrl_pt1_filter_coeff;
    uint16                                             RTE_Lat_rate_limit_control_kd;
    uint16                                             RTE_Lat_rate_limit_control_kp;
    sint16                                             RTE_Lat_rate_limit_control_pt1_kp;
    uint16                                             RTE_Lat_rate_pt1_filter_max_coeff;
    uint16                                             RTE_Lat_rate_ys_kp_pt1_y_scheduling[12];
    sint16                                             RTE_Lat_rate_ys_kp_y_scheduling[12];
    uint16                                             RTE_Lat_saturation_class_thr;
    uint16                                             RTE_Lat_select_input_source;
    uint16                                             RTE_Lat_support_arw_factor_1;
    uint16                                             RTE_Lat_support_arw_factor_2;
    uint16                                             RTE_Lat_support_arw_factor_3;
    uint16                                             RTE_Lat_support_discharge_omega;
    uint16                                             RTE_Lat_support_feedback_factor_1;
    uint16                                             RTE_Lat_support_feedback_factor_2;
    uint16                                             RTE_Lat_support_feedback_factor_hf;
    uint16                                             RTE_Lat_support_min_driver_torque;
    uint16                                             RTE_Lat_support_omega_1;
    uint16                                             RTE_Lat_support_omega_2;
    uint16                                             RTE_Lat_support_omega_hf;
    sint16                                             RTE_Lat_support_tor_x_scheduling[4];
    sint16                                             RTE_Lat_support_tor_y_scheduling[4];
    uint16                                             RTE_Lat_support_torque_threshold;
    uint16                                             RTE_Lat_switch_falling_rate;
    uint16                                             RTE_Lat_switch_falling_rate_2;
    uint16                                             RTE_Lat_switch_off_time;
    uint16                                             RTE_Lat_switch_rising_rate;
    uint16                                             RTE_Lat_switch_rising_rate_2;
    uint16                                             RTE_Lat_switch_rising_rate_initial;
    sint16                                             RTE_Lat_torque_grad_x_scheduling[12];
    sint16                                             RTE_Lat_torque_grad_y_scheduling[12];
    uint16                                             RTE_Lat_torque_gradient;
    uint16                                             RTE_Lat_torque_ramp_down_gradient;
    uint16                                             RTE_Lat_trq_grad_incr_factor_ldp;
    uint16                                             RTE_Lat_trq_grad_pos_req_factor_ldp;
    uint16                                             RTE_Lat_trq_saturation_end;
    uint16                                             RTE_Lat_trq_saturation_min;
    uint16                                             RTE_Lat_trq_saturation_start;
    uint16                                             RTE_Lat_trq_supporting_filt_coeff;
    uint16                                             RTE_Lat_yaw_rate_dot_filter_coeff;
    uint16                                             RTE_Lco_error_filter_falling_coeff;
    uint16                                             RTE_Lco_error_filter_rising_coeff;
    uint16                                             RTE_Lco_filter_falling_coeff;
    uint16                                             RTE_Lco_filter_rising_coeff;
    uint16                                             RTE_Lco_min_control_error;
    uint16                                             RTE_Lco_min_control_error_slope;
    uint16                                             RTE_Lco_min_curvature_command;
    uint16                                             RTE_Lco_min_curvature_slope;
    uint16                                             RTE_Lco_min_err_preload_enh_factor;
    uint16                                             RTE_Lco_min_lateral_error;
    uint16                                             RTE_Lco_min_lateral_error_slope;
    uint16                                             RTE_Lco_min_load_comp_factor;
    uint16                                             RTE_Lco_preload_enhancement_factor;
    uint16                                             RTE_Ldc_comp_kd_factor;
    uint16                                             RTE_Ldc_comp_kp_factor;
    uint16                                             RTE_Ldc_controller_mode;
    uint16                                             RTE_Ldc_ki;
    uint16                                             RTE_Ldc_ki_fb;
    uint16                                             RTE_Ldc_kp_factor;
    uint16                                             RTE_Lka_max_align_torque;
    sint16                                             RTE_Obs_damping_kd_transf_factor;
    sint16                                             RTE_Obs_delta_dot_filter_time_const;
    uint16                                             RTE_Obs_dos_d;
    uint16                                             RTE_Obs_dos_ff_gain;
    uint16                                             RTE_Obs_dos_ff_vel_y_scheduling[13];
    uint16                                             RTE_Obs_dos_l;
    uint16                                             RTE_Obs_dos_one_by_j_motor;
    uint16                                             RTE_Obs_eps_d;
    uint16                                             RTE_Obs_eps_one_by_j_motor;
    sint16                                             RTE_Obs_ffwd_filter_omega;
    uint16                                             RTE_Obs_ffwd_filter_tau;
    uint16                                             RTE_Obs_filter_omega;
    sint16                                             RTE_Obs_filter_tau;
    sint16                                             RTE_Obs_force_torque_transf_factor;
    uint16                                             RTE_Obs_l;
    uint16                                             RTE_Obs_l_y_scheduling[13];
    uint16                                             RTE_Obs_observer_mode;
    uint16                                             RTE_Obs_one_j_y_scheduling[13];
    uint16                                             RTE_Odm_odometry_mode;
    sint16                                             RTE_Sac_accepted_control_error;
    uint16                                             RTE_Sac_accuracy_feedback_transf;
    uint16                                             RTE_Sac_angle_fading_mode;
    sint16                                             RTE_Sac_backlash_torque;
    uint16                                             RTE_Sac_cmd_boost_request_factor;
    sint16                                             RTE_Sac_cmd_enhancement_gain;
    uint16                                             RTE_Sac_cmd_feedforward_gain;
    uint16                                             RTE_Sac_cmd_offset_gain;
    uint16                                             RTE_Sac_comp_fact_gain_y_scheduling[10];
    uint16                                             RTE_Sac_comp_factor_y_scheduling[13];
    sint16                                             RTE_Sac_compensation_factor;
    sint16                                             RTE_Sac_compensation_filter_select;
    uint16                                             RTE_Sac_controller_mode_1;
    uint16                                             RTE_Sac_controller_mode_2;
    uint16                                             RTE_Sac_ctrl_error_red_filter_coeff;
    uint16                                             RTE_Sac_ctrl_error_red_hf_scale;
    uint16                                             RTE_Sac_damp_act_fading_gain;
    uint16                                             RTE_Sac_damp_act_min_control_error;
    uint16                                             RTE_Sac_damp_ffwd_filter_coeff_1;
    uint16                                             RTE_Sac_damp_ffwd_filter_coeff_2;
    uint16                                             RTE_Sac_damp_level_y_scheduling[13];
    uint16                                             RTE_Sac_damping_kd_transf_factor;
    sint16                                             RTE_Sac_damping_lpf_coeff;
    uint16                                             RTE_Sac_damping_reduction_gate_time;
    uint16                                             RTE_Sac_dc_gain_curvature_slope;
    uint16                                             RTE_Sac_dc_gain_factor_high_curv;
    uint16                                             RTE_Sac_dc_gain_min_curvature;
    sint16                                             RTE_Sac_delta_f_cmd_filter_omega;
    uint16                                             RTE_Sac_delta_f_cmd_gradient;
    sint16                                             RTE_Sac_delta_f_dot2_filter_coeff;
    uint16                                             RTE_Sac_delta_gradient_y_scheduling[12];
    uint16                                             RTE_Sac_delta_psi_dot_factor;
    sint16                                             RTE_Sac_delta_psi_dot_maf_length;
    sint16                                             RTE_Sac_delta_psi_pt1_filter_coeff;
    uint16                                             RTE_Sac_differential_2_part;
    uint16                                             RTE_Sac_differential_part;
    uint16                                             RTE_Sac_eps_damping_level;
    uint16                                             RTE_Sac_eps_damping_level_low;
    uint16                                             RTE_Sac_error_filter_omega;
    uint16                                             RTE_Sac_error_filter_omega_2;
    sint16                                             RTE_Sac_fad_flt_fallng_lw_dyn_coeff;
    sint16                                             RTE_Sac_fad_flt_rising_lw_dyn_coeff;
    uint16                                             RTE_Sac_feedforward_filter_coeff;
    uint16                                             RTE_Sac_feedfwd_factor_y_scheduling[13];
    uint16                                             RTE_Sac_feedthr_increment_per_loop;
    sint16                                             RTE_Sac_ffwd_diff_filter_omega;
    uint16                                             RTE_Sac_ffwd_scale_pos_angle_cmd;
    uint16                                             RTE_Sac_ffwd_scaling_end;
    uint16                                             RTE_Sac_ffwd_scaling_start;
    sint16                                             RTE_Sac_filter_omega;
    sint16                                             RTE_Sac_filter_tau;
    uint16                                             RTE_Sac_frc_comp_b1_factor;
    uint16                                             RTE_Sac_frc_comp_omega;
    uint16                                             RTE_Sac_frc_static_friction_torque;
    uint16                                             RTE_Sac_frc_torque_corr_factor;
    uint16                                             RTE_Sac_friction_comp_activ_source;
    uint16                                             RTE_Sac_friction_comp_error_gain;
    uint16                                             RTE_Sac_friction_comp_linear_slope;
    uint16                                             RTE_Sac_friction_comp_torque;
    sint16                                             RTE_Sac_friction_comp_torque_cw;
    uint16                                             RTE_Sac_friction_control_error_gain;
    uint16                                             RTE_Sac_kd;
    uint16                                             RTE_Sac_kd_fading_factor;
    sint16                                             RTE_Sac_kd_max_fading_factor;
    sint16                                             RTE_Sac_kd_obs;
    uint16                                             RTE_Sac_kd_x_scheduling[12];
    uint16                                             RTE_Sac_kd_y_scheduling[12];
    uint16                                             RTE_Sac_ki;
    uint16                                             RTE_Sac_ki_fb;
    uint16                                             RTE_Sac_ki_fb_y_scheduling[11];
    uint16                                             RTE_Sac_ki_y_scheduling[13];
    uint16                                             RTE_Sac_kmc_loop_gain;
    uint16                                             RTE_Sac_kp;
    uint16                                             RTE_Sac_kp_dc_gain_factor;
    uint16                                             RTE_Sac_kp_derating_slope;
    sint16                                             RTE_Sac_kp_fading_flt_falling_coeff;
    sint16                                             RTE_Sac_kp_fading_flt_rising_coeff;
    uint16                                             RTE_Sac_kp_ldp;
    uint16                                             RTE_Sac_kp_scale_pos_angle_command;
    uint16                                             RTE_Sac_kp_scale_pos_control_error;
    uint16                                             RTE_Sac_kp_scaling_end;
    uint16                                             RTE_Sac_kp_scaling_start;
    uint16                                             RTE_Sac_kp_x_scheduling[12];
    uint16                                             RTE_Sac_kp_y_scheduling[12];
    uint16                                             RTE_Sac_kx;
    uint16                                             RTE_Sac_kx_y_scheduling[13];
    uint16                                             RTE_Sac_limiter_control_ki;
    uint16                                             RTE_Sac_lin_fad_enable_multi_ramp;
    uint16                                             RTE_Sac_lin_fading_activation_thrs;
    uint16                                             RTE_Sac_lin_fading_coefficient;
    uint16                                             RTE_Sac_lin_fading_gate_time;
    uint16                                             RTE_Sac_lin_fading_max_offset;
    uint16                                             RTE_Sac_lin_fading_min_offset;
    sint16                                             RTE_Sac_load_compensation_factor;
    uint16                                             RTE_Sac_max_angle_velocity;
    uint16                                             RTE_Sac_max_integ_torque_corr_fact;
    uint16                                             RTE_Sac_max_integ_trq_y_scheduling[11];
    uint16                                             RTE_Sac_min_command_gradient;
    uint16                                             RTE_Sac_min_control_error;
    sint16                                             RTE_Sac_min_kp;
    uint16                                             RTE_Sac_min_proportional_part;
    uint16                                             RTE_Sac_min_proportional_part_scale;
    sint16                                             RTE_Sac_mx_angle_speed_y_scheduling[11];
    sint16                                             RTE_Sac_notch_cf;
    sint16                                             RTE_Sac_notch_d;
    uint16                                             RTE_Sac_notch_high_pass_omega_1;
    sint16                                             RTE_Sac_notch_high_pass_omega_2;
    uint16                                             RTE_Sac_notch_l1;
    uint16                                             RTE_Sac_notch_l2;
    uint16                                             RTE_Sac_notch_l3;
    uint16                                             RTE_Sac_notch_one_by_j_motor;
    uint16                                             RTE_Sac_obs_scaling_end;
    uint16                                             RTE_Sac_obs_scaling_start;
    uint16                                             RTE_Sac_omega_arw;
    sint16                                             RTE_Sac_one_by_ts;
    uint16                                             RTE_Sac_osc_damp_ctrl_error_slope;
    uint16                                             RTE_Sac_osc_damp_diff_part_slope;
    sint16                                             RTE_Sac_osc_damp_flt_falling_coeff;
    sint16                                             RTE_Sac_osc_damp_flt_rising_coeff;
    uint16                                             RTE_Sac_osc_damp_min_control_error;
    sint16                                             RTE_Sac_p_part_filter_coeff;
    sint16                                             RTE_Sac_parity_omega;
    uint16                                             RTE_Sac_parity_time_constant;
    uint16                                             RTE_Sac_parity_time_constant_ldp;
    uint16                                             RTE_Sac_pid_kd;
    sint16                                             RTE_Sac_pid_kp;
    uint16                                             RTE_Sac_pid_kp_y_scheduling[13];
    uint16                                             RTE_Sac_prop_part_limit_scale;
    uint16                                             RTE_Sac_pt1_filter_coeff;
    uint16                                             RTE_Sac_pt1_filter_coeff_2;
    uint16                                             RTE_Sac_pt1_filter_coeff_3;
    uint16                                             RTE_Sac_pt1_filter_coeff_4;
    uint16                                             RTE_Sac_pt1_filter_coeff_5;
    uint16                                             RTE_Sac_pt1_filter_coeff_6;
    uint16                                             RTE_Sac_pt1_filter_coeff_7;
    uint16                                             RTE_Sac_pt1_max_filter_coeff_2;
    uint16                                             RTE_Sac_reduced_kmc_loop_gain;
    uint16                                             RTE_Sac_stiffness_filter_coeff;
    sint16                                             RTE_Sac_torque_scaling_factor;
    uint16                                             RTE_Sac_ts;
    uint16                                             RTE_Sat_dynamic_enhancement_factor;
    uint16                                             RTE_Sat_max_delta_f_cmd;
    uint16                                             RTE_Sat_thrs_control_kp;
    uint16                                             RTE_Tdf_comp_factor_filter_coeff;
    uint16                                             RTE_Tdf_control_err_derating_slope;
    uint16                                             RTE_Tdf_derating_end;
    uint16                                             RTE_Tdf_derating_mode;
    uint16                                             RTE_Tdf_derating_slope_y_scheduling[11];
    uint16                                             RTE_Tdf_derating_start;
    uint16                                             RTE_Tdf_derating_thrs_y_scheduling[11];
    sint16                                             RTE_Tdf_lat_accel_sign_slope;
    uint16                                             RTE_Tdf_load_comp_end;
    uint16                                             RTE_Tdf_load_comp_start;
    uint16                                             RTE_Tdf_load_comp_y_scheduling[11];
    uint16                                             RTE_Tdf_min_compensation_factor;
    sint16                                             RTE_Tdf_min_steer_torque_class;
    uint16                                             RTE_Tdf_min_steer_trq_cls_y_schedul[11];
    uint16                                             RTE_Tdf_steer_torque_comp_slope;
    uint16                                             RTE_Tdf_steer_torque_comp_thrs_ldp;
    uint16                                             RTE_Tdf_steer_torque_sign_slope;
    uint16                                             RTE_Tdf_steer_trq_cmp_ldp_y_schedul[11];
    uint16                                             RTE_Tdf_steer_trq_cmp_slp_y_schedul[12];
    uint16                                             RTE_Tdf_steer_trq_comp_reduced_thrs;
    sint16                                             RTE_Tdf_toque_derating_slope;
    uint16                                             RTE_Tdf_torque_der_filt_coeff_hf;
    uint16                                             RTE_Tdf_torque_derating_filt_coeff;
    uint16                                             RTE_Tdf_torque_derating_threshold;
    uint16                                             RTE_Tdf_torque_request_sign_slope;
    uint16                                             RTE_Tdf_torque_supporting_slope;
    uint16                                             RTE_Tdf_torque_supporting_threshold;
    uint16                                             RTE_Tdf_trq_der_thrs_dp_hi_sens;
    uint16                                             RTE_Tdf_trq_derating_max_init_trq;
    uint16                                             RTE_Tdf_trq_derating_min_init_trq;
    uint16                                             RTE_Tdf_trq_derating_slope_hf_path;
    uint16                                             RTE_Tdf_trq_derating_slope_hi_sens;
    uint16                                             RTE_Tdf_trq_derating_threshold_dp;
    uint16                                             RTE_Tdf_trq_derating_thrs_hi_sens;
    uint16                                             RTE_Tdf_trq_filter_coeff;
    uint16                                             RTE_Tdf_trq_scaling_end;
    uint16                                             RTE_Tdf_trq_scaling_start;
    uint16                                             RTE_Tdf_vel_derating_filt_coeff;
    uint16                                             RTE_Tdf_velocity_derating_slope;
    uint16                                             RTE_Tdf_velocity_derating_threshold;
    uint16                                             RTE_Tge_state_filter_time_constant;
    uint16                                             RTE_Trj_generation_mode;
    uint16                                             RTE_Trj_max_accel;
    sint16                                             RTE_Trj_max_heading_angle;
    sint16                                             RTE_Trj_step_command;
    uint16                                             RTE_Veh_column_stiffness;
    uint8                                              RTE_Veh_steer_angle_rate_source;
    uint8                                              RTE_Veh_steer_angle_source;
    sint16                                             RTE_Veh_steer_gear_ratio_x_tab[6];
    sint16                                             RTE_Veh_steer_gear_ratio_y_tab[6];
    uint16                                             RTE_Lat_lka_startup_time;
    uint16                                             RTE_Sac_delta_f_cmd_initial_grad;
} LCF_INTERFACES_CPAR_LCF_TunParamsDMC;           /* @versionstr: LCF_TUN_PAR_DMC_INTFVER */

typedef struct
{
    LCF_INTERFACES_SelectedTargetObjDetected__nu       SelectedTargetObjDetected__nu;            /*!< Indicates whether TJA target object is detected,Accuracy: 1.0, Unit: [Enum],List:TJA_TARGET_OBJ_NOT_DETECTED=0,TJA_TARGET_OBJ_DETECTED=1  */
    float32                                            MovementRelAclX__mps2;                    /*!< Relative longitudinal acceleration: Difference in longitudinal acceleration of the host and the object. This value shall be positive when the object acceleration is higher than the host acceleration.  */
    float32                                            MovementRelVelX__mps;                     /*!< Relative longitudinal velocity: Difference in longitudinal velocity of the host and the object. This value shall be positive when the object velocity is higher than the host velocity (opening velocity)., Unit: [m/s]  */
    float32                                            MovementRelAclY__mps2;                    /*!< Relative lateral acceleration: Acceleration in lateral direction of the object, relative to the host vehicle. This value shall be positive when the object accelerates towards the right.  */
    float32                                            MovementRelVelY__mps;                     /*!< Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left., Unit: [m/s]  */
    float32                                            PositionPosX__m;                          /*!< Longitudinal (parallel to ego-vehicle x-axis) distance to object kinematic point. , Unit: [m]  */
    float32                                            PositionPosY__m;                          /*!< Lateral (parallel to ego-vehicle y-axis) distance to object kinematic point. Positive to the left., Unit: [m]  */
    float32                                            PositionPosXStdDev__m;                    /*!< Standard deviation of PositionPosX__m. Negative if invalid., Unit: [m]  */
    float32                                            PositionPosYStdDev__m;                    /*!< Standard deviation of PositionPosY__m. Negative if invalid., Unit: [m]  */
    uint8                                              ObjQuality__nu;                           /*!< Function preselection ACC object quality (0-100):
<=70% shall not be selected as OOI
> 70% may be selected as neighbor lane OOI
> 85 % may be selected as in lane OOI  */
    LCF_INTERFACES_ObjRecognClassType__nu              ObjRecognClassType__nu;                   /*!< This signal indicates the class of the object.
Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles,Accuracy: 1.0, Unit: [Enum],List:TJA_EM_GEN_OBJECT_CLASS_POINT=0,TJA_EM_GEN_OBJECT_CLASS_CAR=1,TJA_EM_GEN_OBJECT_CLASS_TRUCK=2,TJA_EM_GEN_OBJECT_CLASS_PEDESTRIAN=3,TJA_EM_GEN_OBJECT_CLASS_MOTORCYCLE=4,TJA_EM_GEN_OBJECT_CLASS_BICYCLE=5,TJA_EM_GEN_OBJECT_CLASS_WIDE=6,TJA_EM_GEN_OBJECT_CLASS_UNCLASSIFIED=7,TJA_EM_GEN_OBJECT_CLASS_TL=8,TJA_EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES=9  */
    LCF_INTERFACES_ObjRecognMeasState__nu              ObjRecognMeasState__nu;                   /*!< State of Object Recognization,Accuracy: 1.0, Unit: [Enum],List:TJA_EM_GEN_OBJECT_MT_STATE_DELETED=0,TJA_EM_GEN_OBJECT_MT_STATE_NEW=1,TJA_EM_GEN_OBJECT_MT_STATE_MEASURED=2,TJA_EM_GEN_OBJECT_MT_STATE_PREDICTED=3,TJA_EM_GEN_OBJECT_MT_STATE_INACTIVE=4,TJA_EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES=5  */
    float32                                            DimensionsWidth__m;                       /*!< Object width (lateral dimension) based on measurement supported by the assumed object width as a function of the object class, Unit: [m]  */
    uint16                                             SensorSource__nu;                         /*!< Bitfield for a combination of given enum values to point out what sensor participated at measurement of the object. The object assocaition shall consider different acquisition times and  expected update cycles (properly avoid toggling)
  */
    uint32                                             Tstamp__us;                               /*!< Time stamp of object detection, Unit: [us]  */
    uint8                                              ObjRecognExtendedQualifier__nu;
} LCF_INTERFACES_TJATargetObject;
typedef struct
{
    LCF_INTERFACES_LCF_SideObject_t                    SideObjectLeft;                           /*!< Object information on left side  */
    LCF_INTERFACES_LCF_SideObject_t                    SideObjectRight;                          /*!< Object information on right side  */
} LCF_INTERFACES_TJASideObject;
typedef struct
{
    LCF_e_QuDangOcObjDtct_t                            QuDangOcObjDtct_nu;                       /*!< Qualifier for Oncoming Obj evaluation,Accuracy: 1.0, Unit: [Enum],List:FROOP_OC_OBJ_QUAL_UNKNOWN=0,FROOP_OC_OBJ_QUAL_STARTUP=1,FROOP_OC_OBJ_QUAL_NORMAL_OP=2,FROOP_OC_OBJ_QUAL_ERR_DRV_SOLVABLE=3,FROOP_OC_OBJ_QUAL_ERR_GARAGE=4,FROOP_OC_OBJ_QUAL_INVALID=7  */
} LCF_INTERFACES_FroopToLCF;
/*! @brief LCF_GenericInputs->
TMCESA_In */
typedef struct
{
    float32                                            TSEGapLongDistEgoToTarget__m;             /*!< The longitudinal distance between ego vehicle and critical object, Unit: [m]  */
    float32                                            TSEGapLongDistEgoToTargetPRE__m;          /*!< The predictive longitudinal distance between ego vehicle and 
critical object based on TTC., Unit: [m]  */
    float32                                            TSETargetLongVel__mps;                    /*!< The longitudinal velocity of the critical object, Unit: [m/s]  */
    float32                                            TSETargetLongAccel__mps2;                 /*!< The longitudinal acceleration  of the critical object, Unit: [m/s^2]  */
    float32                                            TSEKappaEvasiveCorrRight__1pm;            /*!< Curvature of the evasive corridor right, Unit: [1/m]  */
    float32                                            TSEGapLatDistEgoToCorrLeft__m;            /*!< lateral distance between ego vehicle and limiting object to the left, Unit: [m]  */
    float32                                            TSEGapLatDistEgoToCorrRight__m;           /*!< lateral distance between ego vehicle and limiting object to the right, Unit: [m]  */
    float32                                            TSEGapLatDistObjToCorrLeft__m;            /*!< laterale distance between critical objekt and limiting object besides left[MIN(current  
width, pedictive width on TTC)], Unit: [m]  */
    float32                                            TSEGapLatDistObjToCorrRight__m;           /*!< laterale distance between critical objekt and limiting object besides right [MIN(current 
 width, pedictive width on TTC)], Unit: [m]  */
    uint8                                              TSEAEBAcuteDynWarnFCTChan__nu;
    uint8                                              TSEAEBAcuteDynWarnSigState__nu;
    uint8                                              TSEStatusFunctionEPF__nu;
    float32                                            TSEAEBAnecLongAccel__mpss;                /*!< Longitudinal acceleration required to stop the object collision, Unit: [m/s^2]  */
} LCF_INTERFACES_TMCESA_In;
typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    float32                                            SteerHandWheelAngle__rad;                 /*!< Steering Wheel Angle (SAS_Angle), Unit: [rad]  */
    float32                                            SteerHandWheelAngleRate__rps;             /*!< Steering Wheel Angle Gradient (SAS_Speed), Unit: [rad/s]  */
    float32                                            DeltaFSteerAngle__deg;                    /*!< Steer angle at the front wheels of the vehicle. The steer angle information shall be derived from the EPS motor angle and not from the signal of a steering wheel sensor mounted close to the steering wheel, i.e. the provided angle signal shall not be affected by the elasticity of the steering column. The steer angle information shall be offset calibrated. The maximum offset error during vehicle life time under all operating conditions shall be below 0.3 degree related to the steering wheel angle., Unit: [deg]  */
    float32                                            DeltaFSteerAngleRate__degps;              /*!< Steer angle rate at the front wheels of the vehicle., Unit: [deg/s]  */
    float32                                            SteerTrq__nm;                             /*!< Steering torque from EPS
CR_Mdps_StrTq, Unit: [Nm]  */
    float32                                            DrvSteerWheelTrq__nm;                     /*!< Steering Wheel Torque
CR_Mdps_StrColTq, Unit: [Nm]  */
    float32                                            EPS_Motor_Torque__nm;                     /*!< Finally arbitrated motor torque command, that is controlled by the motor torque control unit of the EPS
CR_Mdps_OutTq, Unit: [Nm]  */
    float32                                            ACC_TraceTrajCurve__1pm;                  /*!< The estimated curvature information of ACC trace trajectory, which is calculated from the relevant front objects., Unit: [1/m]  */
    float32                                            ACC_TraceTrajWeight__nu;                  /*!< The weight of estimated curvature information of ACC trace trajectory.  */
    float32                                            ACC_TraceTrajMaxDist__m;                  /*!< The maximal longitudinal distance of front objects used for calculating the ACC trace trajectory., Unit: [m]  */
    LCF_e_AccTraceTrajState_t                          ACC_TraceTrajQualifier__nu;               /*!< The qualifier of ACC trace trajectory. ,Accuracy: 1.0, Unit: [Enum],List:LCF_ACC_TRACE_INVALID=0,LCF_ACC_TRACE_VALID=1,LCF_ACC_TRACE_NOT_AVAILABLE=2,LCF_ACC_TRACE_ERROR=15  */
    boolean                                            DynamometerTestBenchDetected__nu;         /*!< indicates if vehicle is on a (roller) test bench,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            DoorOpen__nu;                             /*!< indicates if vehicle door is open,Accuracy: 1.0, Range:[0..1]  */
    LCF_e_TurnSignalState_t                            TurnSignalState__nu;                      /*!< indicates if the turn signal is activated,Accuracy: 1.0, Unit: [Enum],List:LCF_TURN_SIG_OFF=0,LCF_TURN_SIG_LEFT=1,LCF_TURN_SIG_RIGHT=2,LCF_TURN_SIG_HAZARD=3,LCF_TURN_SIG_INVALID=4  */
    LCF_e_TurnLeverState_t                             TurnSignalLever__nu;                      /*!< indicates turn signal lever state,Accuracy: 1.0, Unit: [Enum],List:LCF_TURN_LEVER_OFF=0,LCF_TURN_LEVER_TIPPED=1,LCF_TURN_LEVER_ENGAGED=2,LCF_TURN_LEVER_INVALID=3  */
    boolean                                            VehicleReadyState__nu;                    /*!< general indicator for vehicle being ready,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            DriverNotBuckledUp__nu;                   /*!< indicates if the driver is buckled up,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            OversteeringDetected__nu;                 /*!< indicates if vehicle is oversteering,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            UndersteeringDetected__nu;                /*!< indicates if vehicle is understeering,Accuracy: 1.0, Range:[0..1]  */
    float32                                            BankAngle__rad;                           /*!< Road banking angle, Unit: [rad]  */
    float32                                            TieRodLoad__n;                            /*!< Current load at the tie rod of the steering system as estimated by the EPS, Unit: [N]  */
    boolean                                            EPS_Toi_Unavail__nu;                      /*!< Operation status of the EPS for consideration in the lateral controller (CF_Mdps_ToiUnavail),Accuracy: 1.0, Range:[0..1]  */
    boolean                                            EPS_Toi_Active__nu;                       /*!< Torque overlay interface activation status of the EPS for consideration in the lateral controller (CF_Mdps_ToiActive),Accuracy: 1.0, Range:[0..1]  */
    boolean                                            EPS_Toi_Flt__nu;                          /*!< Torque overlay interface faulty flag of the EPS for consideration in the lateral controller (CF_Mdps_ToiFlt),Accuracy: 1.0, Range:[0..1]  */
    boolean                                            EPS_Fail_Stat__nu;                        /*!< Torque overlay interface fail status of the EPS for consideration in the lateral controller (CF_Mdps_FailStat),Accuracy: 1.0, Range:[0..1]  */
    boolean                                            EPS_Def__nu;                              /*!< Information regarding the MDPS “defective” Indication (CF_Mdps_Def),Accuracy: 1.0, Range:[0..1]  */
    LCF_e_ModeSelection_t                              LKAMode__nu;                              /*!< LKAS_LDW mode selection,Accuracy: 1.0, Unit: [Enum],List:LCF_MODE_SEL_OFF=0,LCF_MODE_SEL_LDW=1,LCF_MODE_SEL_LDP_STD=2,LCF_MODE_SEL_LDP_ACT=3  */
    uint8                                              TJAMode__nu;                              /*!< TJA mode selection  */
    LCF_e_HandsOffState_t                              DriverHandsOff__nu;                       /*!< Driver HandsOff state,Accuracy: 1.0, Unit: [Enum],List:LCF_HANDS_OFF_DETECTED=0,LCF_HANDS_ON_DETECTED=1,LCF_HANDS_STAT_INVALID=3  */
    LCF_e_SCCActiveState_t                             SCCActive__nu;                            /*!< Indicates that Smart Cruise Control is in the active state,Accuracy: 1.0, Unit: [Enum],List:LCF_SCC_INACTIVE=0,LCF_SCC_ACTIVE=1  */
    LCF_e_USMResetState_t                              USMReset__nu;                             /*!< The reset signal from Cluster/USM,Accuracy: 1.0, Unit: [Enum],List:LCF_USM_RESET_DEFAULT=0,LCF_USM_RESET_OFF=1  */
    LCF_e_HDAOnState_t                                 HDAOn__nu;                                /*!< This signal is used to set HAD function,Accuracy: 1.0, Unit: [Enum],List:LCF_HDA_DEFAULT=0,LCF_HDA_OFF=1,LCF_HDA_ON=2,LCF_HDA_INVALID=3  */
    LCF_e_SCCOnState_t                                 SCCOn__nu;                                /*!< This signal reflects that the SCC mode is selected ,Accuracy: 1.0, Unit: [Enum],List:LCF_SCC_MODE=1,LCF_CC_MODE=2  */
    uint8                                              USMSetSpd__kph;                           /*!< The speed that the driver sets for the SCC, Unit: [km/h]  */
    LCF_e_NAVIRoadType_t                               NAVIRoadType__nu;                         /*!< Indicated the road type,Accuracy: 1.0, Unit: [Enum],List:LCF_ROAD_UNKNOWN=0,LCF_ROAD_FREEWAY=1,LCF_ROAD_CITY_FREEWAY=2  */
    LCF_e_NAVIRoadForm_t                               NAVISegFormOfWay__nu;                     /*!< Indicated the form of way,Accuracy: 1.0, Unit: [Enum],List:LCF_ROAD_FORM_UNKNOWN=0,LCF_ROAD_FORM_NONDISJ=1,LCF_ROAD_FORM_DISJ=2,LCF_ROAD_FORM_JC=3,LCF_ROAD_FORM_PLURAL_JC=4,LCF_ROAD_FORM_IC=5,LCF_ROAD_FORM_RESERVED1=6,LCF_ROAD_FORM_SERVICE_AREA=7,LCF_ROAD_FORM_RESERVED2=8,LCF_ROAD_FORM_ROUNDABOUT=9,LCF_ROAD_FORM_P_TURN=10,LCF_ROAD_FORM_U_TURN=11,LCF_ROAD_FORM_PEDESTRIAN=12,LCF_ROAD_FORM_FRONTAGE_RD=13,LCF_ROAD_FORM_INTERSECT_INT=14,LCF_ROAD_FORM_INVALID=15  */
    uint8                                              NAVISegSpeedLim__kph;                     /*!< The curent speed limit of the highway, Unit: [km/h]  */
    LCF_e_NAVIStatus_t                                 NAVIStatus__nu;                           /*!< Status of NAVI,Accuracy: 1.0, Unit: [Enum],List:LCF_NAVI_BOOTING=0,LCF_NAVI_NORMAL_OP=1,LCF_NAVI_NO_SD_CARD=2,LCF_NAVI_INVALID=3  */
    LCF_e_NAVIProlProfType_t                           NAVIProlProfType__nu;                     /*!< This signal is used to detect if an event from NAVI is transmited,Accuracy: 1.0, Unit: [Enum],List:LCF_NAVI_PROL_INVALID=0,LCF_NAVI_PROL_LONGITUDE=1,LCF_NAVI_PROL_LATITUDE=2,LCF_NAVI_PROL_ALTITUDE=3,LCF_NAVI_PROL_CTRL_PT_LONGITUDE=4,LCF_NAVI_PROL_CTRL_PT_LATITUDE=5,LCF_NAVI_PROL_CTRL_PT_ALTITUDE=6,LCF_NAVI_PROL_LINK_IDENT=7,LCF_NAVI_PROL_TRAFFIC_SIGN=8,LCF_NAVI_PROL_RESERVED1=9,LCF_NAVI_PROL_RESERVED2=10,LCF_NAVI_PROL_RESERVED3=11,LCF_NAVI_PROL_RESERVED4=12,LCF_NAVI_PROL_RESERVED5=13,LCF_NAVI_PROL_RESERVED6=14,LCF_NAVI_PROL_RESERVED7=15,LCF_NAVI_PROL_ALERT_INFO_SPOT=16  */
    LCF_e_NAVITollgateDet_t                            NAVITollgateDet__nu;                      /*!< This signal is used to receive the info. about the presence of a toolgate in the next 2 km.,Accuracy: 1.0, Unit: [Enum],List:LCF_NAVI_TOLLGATE_NOT_DET=0,LCF_NAVI_TOLLGATE_DET=1  */
    uint16                                             NAVITgDetDistOffset__m;                   /*!< This signal is the distance to the detected toolgate in the moment of event. , Unit: [m]  */
    uint16                                             NAVIPosOffset__m;                         /*!< This signal is the distance passed in the last cycle., Unit: [m]  */
    uint8                                              NAVIProlCyclicCount__nu;                  /*!< Cyclic Counter of the tollgate event  */
    uint8                                              NAVIPosCyclicCount__nu;                   /*!< Cyclic Counter of the position  */
    LCF_e_HDAExtFail_t                                 HDAExtFailFlag__nu;                       /*!< HDA function stop flag received from NORM if some external failures (HDA relevant) are detected by DEM,Accuracy: 1.0, Unit: [Enum],List:LCF_HDA_NO_EXT_FAIL=0,LCF_HDA_EXT_FAIL=1  */
    LCF_e_SCCMainMode_t                                SCCMainMode__nu;                          /*!< This signal specifies the status of a Main switch of SCC system,Accuracy: 1.0, Unit: [Enum],List:LCF_SCC_OFF=0,LCF_SCC_ON=1  */
    LCF_e_NAVISpeedUnit_t                              NAVISpeedUnit__nu;                        /*!< Unit of the Speed Limit  from NAVI,Accuracy: 1.0, Unit: [Enum],List:LCF_NAVI_SPD_UNIT_NONE=0,LCF_NAVI_SPD_UNIT_KPH=1,LCF_NAVI_SPD_UNIT_MPH=2,LCF_NAVI_SPD_UNIT_INVALID=3  */
    uint8                                              AlwaysHandsOn__nu;                        /*!< Used to deactivate DRVMN for debugging  */
    float32                                            AccelPedalPos__nu;                        /*!< Acceleration pedal positon (percentage)  */
    uint8                                              LcfVariantInfo__nu;                       /*!< Variant information, needed in TMC project  */
    boolean                                            DanRearObjBS_RearLeft__nu;                /*!< ALCA Trigger Flag Dangerous Object Left Blind Spot,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            DanRearObjFOV_RearLeft__nu;               /*!< ALCA Trigger Flag Dangerous Object Left Fast Overtaking Vehicle,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            OIQualifierFlag_RearLeft__nu;             /*!< Object Interface Flag Left Sensor,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            MSFlag_RearLeft__nu;                      /*!< Maneuver space Flag Left,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            DanRearObjBS_RearRight__nu;               /*!< ALCA Trigger Flag Dangerous Object Right Blind Spot,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            DanRearObjFOV_RearRight__nu;              /*!< ALCA Trigger Flag Dangerous Object Right Fast Overtaking Vehicle,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            OIQualifierFlag_RearRight__nu;            /*!< Object Interface Flag Right Sensor,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            MSFlag_RearRight__nu;                     /*!< Maneuver space Flag Right,Accuracy: 1.0, Range:[0..1]  */
    LCF_e_EPSStSterCtlMod_t                            EPSSteerCtrlMode__nu;
    LCF_e_EPSStatusECUActFact_t                        EPSECUActFact__nu;
    LCF_e_EPSStatusDriverInter_t                       EPSDriverIntervention__nu;
    float32                                            EPSReqTrq__nm;
    float32                                            EPSMotTrq__nm;
    float32                                            EPSMotAngSpd__degps;
    float32                                            EPSReqStAng__deg;
    LCF_INTERFACES_TJATargetObject                     TJATargetObject;
    LCF_INTERFACES_TJASideObject                       TJASideObject;
    LCF_INTERFACES_FroopToLCF                          FroopToLCF;
    LCF_INTERFACES_TMCESA_In                           TMCESA_In;                                /*!< LCF_GenericInputs->
TMCESA_In  */
    uint8                                              SteerWheelAngSensorStatus__nu;            /*!< SAIC Project Request :
Steering wheel angle sensor status. NO_ERROR state is requested to be checked in the wrappers.
The signal after the logic shall be a boolean with the following meaning :
TRUE: Sensor Error
FALSE: Sensor without any errors  */
    boolean                                            CommunicationLostEps__nu;                 /*!< SAIC Project Request :
Communication status with the EPS. 
When the communication is lost the signal should be TRUE(error), otherwise is should be FALSE(no error)
,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            CommunicationLostSCS__nu;                 /*!< SAIC Project Request :
Communication status with the SCS. 
When the communication is lost the signal should be TRUE(error), otherwise is should be FALSE(no error)
,Accuracy: 1.0, Range:[0..1]  */
    boolean                                            CommunicationLostTCM__nu;                 /*!< SAIC Project Request :
Communication status with the TCM. 
When the communication is lost the signal should be TRUE(error), otherwise is should be FALSE(no error)
,Accuracy: 1.0, Range:[0..1]  */
    float32                                            MainCylPressure_pa;                       /*!< SAIC Project Request :
The main cylinder pressure
  */
    uint8                                              CustSpecLCFErrInput__nu;                  /*!< SAIC Project Request :
Consider specific error scenarios for which an error input signal is required, which would be updated by the FCU. Signal Values:
0x0: NO ERROR
0x1: Performance Degradation
0x2: Temporarily Unavailable
0x3: Service Required
  */
    uint8                                              TerrainMode__nu;                          /*!< SAIC Project Request :
Switch on LCF functionalities based on their Terrain Mode input. Signal Values:
0x0 AUTO MODE
0x1 SPORT MODE
0x2 SNOW MODE
0x3 OFFROAD MODE
0x4 4L MODE
0x5 2H MODE
0x6 RESERVED
0x7 CUSTOMIZATION MODE

  */
} LCF_INTERFACES_LCF_GenericInputs;           /* @versionstr: LCF_INPUT_INTFVER */

typedef struct
{
    LCF_INTERFACES_LCF_TrajPlanCorridor_t              LeftCorridor;                             /*!< Left corridor boundary  */
    LCF_INTERFACES_LCF_TrajPlanCorridor_t              RightCorridor;                            /*!< Right corridor boundary  */
    LCF_INTERFACES_LCF_TrajPlanCorridor_t              TargetCorridor;                           /*!< Target corridor  */
    LCF_INTERFACES_LCF_TrajPlanCorridor_t              LeftRoadEdge;                             /*!< Left road edge  */
    LCF_INTERFACES_LCF_TrajPlanCorridor_t              RightRoadEdge;                            /*!< Right road edge  */
} LCF_INTERFACES_AllCorridors;
typedef struct
{
    LCF_INTERFACES_AllCorridors                        AllCorridors;
    uint8                                              LaneValidQualVis__nu;                     /*!< Status of detected lanes S_ABPLBP_LaneValidQualVis_nu to be used in visualization  */
    float32                                            ABDTimeStamp_sec;                         /*!< TimeStamp from the ABD component, Unit: [s]  */
} LCF_INTERFACES_Visualization;
typedef struct
{
    uint16                                             DFFunctActiveState_btf;                   /*!< Current Controlling Driving Function (Bitfield)  */
    uint8                                              LnBndLeValid4Fct_btf;                     /*!< Detected left lane is valid for specific function (Bitfield)  */
    uint8                                              LnBndRiValid4Fct_btf;                     /*!< Detected right lane is valid for specific function (Bitfield)  */
    uint8                                              SteeringWheelVibrationReq__nu;            /*!< Steering wheel vibration request sending to DMC.  */
    LCF_INTERFACES_DrvAttWarnQualifier__nu             DrvAttWarnQualifier__nu;                  /*!< Qualifier of the driver attention warning state machine, which will be shown on HMI to the driver,Accuracy: 1.0, Unit: [Enum],List:LCF_DRV_ATTENTION_WRNG_STATE_NO_WARNING=0,LCF_DRV_ATTENTION_WRNG_STATE_ATTENTIVNESS_REQUEST=1,LCF_DRV_ATTENTION_WRNG_STATE_TAKE_OVER_REQUEST=2,LCF_DRV_ATTENTION_WRNG_STATE_DEGRADATION_TRIGGERED=3  */
} LCF_INTERFACES_HMI_Out;
typedef struct
{
    uint8                                              TMC_Indi__nu;                             /*!< TMC specific HMI output  */
    uint8                                              TMC_LaneDispLeft__nu;                     /*!< TMC specific HMI output  */
    uint8                                              TMC_LaneDispRight__nu;                    /*!< TMC specific HMI output  */
    uint8                                              TMC_StrgCtrlAct__nu;                      /*!< TMC specific HMI output  */
    uint8                                              TMC_DriverHandsOff__nu;                   /*!< TMC specific HMI output  */
    uint8                                              TMC_OperationSpdDisp__nu;                 /*!< TMC specific HMI output  */
    uint8                                              TMC_LdwBuzzer__nu;                        /*!< TMC specific HMI output  */
    uint8                                              TMC_FuncModeDisp__nu;                     /*!< TMC specific HMI output  */
} LCF_INTERFACES_TMC_SEN_Out;
typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    LCF_e_LKASLDWSysState_t                            Lkas_LDWSSysState__nu;                    /*!< LKAS System State to be sent on the bus,Accuracy: 1.0, Unit: [Enum],List:LCF_SYS_OFF=0,LCF_LOW_VEH_SPEED=1,LCF_SYS_UNAVAILABLE=2,LCF_EPS_CTRL_FULL_LANE_RECOGNIZED=3,LCF_FULL_LANE_RECOGNIZED=4,LCF_LEFT_LINE_RECOGNIZED=5,LCF_RIGHT_LINE_RECOGNIZED=6,LCF_EPS_CTRL_LEFT_LINE_RECOGNIZED=7,LCF_EPS_CTRL_RIGHT_LINE_RECOGNIZED=8,LCF_SYS_NOT_CALIBRATED=14,LCF_SYS_FAILURE=15  */
    uint8                                              LaneRecogState__nu;                       /*!< HMC specific signal: Lane recognition state
E_HMOHMC_FULL_LANE_RECOG_nu - 3
E_HMOHMC_RIGHT_LANE_RECOG_nu - 2
E_HMOHMC_LEFT_LANE_RECOG_nu - 1
E_HMOHMC_NO_RECOGNITION_nu - 0  */
    uint8                                              SymbolState__nu;                          /*!< HMC specific signal: describes the state of the LKAS
E_HMOHMC_SYS_OFF_nu - 0
E_HMOHMC_SYS_ON_nu - 1 (Low Vehicle speed or Sys Unavailable or a lane/lanes are detected)
E_HMOHMC_LKA_ACTIVE_nu - 2 (Function is ready to trigger)
E_HMOHMC_STEER_CTRL_nu - 3 (ActToi_nu = 1)
E_HMOHMC_SYS_FAIL_nu - 4
E_HMOHMC_SYS_NOT_CALIB_nu - 5
E_HMOHMC_SYS_OFF_REG_nu - 6  */
    uint8                                              HandsOffSnd__nu;                          /*!< HMC specific signal: activates a warning sound for hands off  */
    LCF_e_LaKMCLaneStatus_t                            LaKMC_lane_status__nu;                    /*!< Position of the vehicle wrt to the lanes,Accuracy: 1.0, Unit: [Enum],List:LCF_NO_LANE_DEPARTURE=0,LCF_DEPARTING_LEFT_LANE=1,LCF_DEPARTING_LEFT_LANE_FAST=2,LCF_DEPARTING_RIGHT_LANE=3,LCF_DEPARTING_RIGHT_LANE_FAST=4,LCF_DEPARTING_LANE_INVALID=7  */
    LCF_e_Lkas_LDWSOpt_USM_t                           Lkas_LDWSOpt_USM__nu;                     /*!< (HMC)LDW/LKA System Option and USM setting information,Accuracy: 1.0, Unit: [Enum],List:LCF_OPT_USM_INVALID=0,LCF_OPT_USM_LDW=1,LCF_OPT_USM_LKAS_STD=2,LCF_OPT_USM_LKAS_ACT=3,LCF_OPT_USM_LDW_ONLY=4  */
    LCF_e_Lkas_SysWarning_t                            Lkas_SysWarning__nu;                      /*!< (HMC)A signal that provides additional information on the operation of the LKAS system for the HMI to display to the driver. This includes additional fault information, reasons for unavailablity of the system and additional warnings like the hands-off warning. Some if the information may be displayed for short periods, whlst others like the hands-off warning may be displayed for longer periods.,Accuracy: 1.0, Unit: [Enum],List:LCF_WARN_NOINFO=0,LCF_WARN_HANDSOFF=4,LCF_WARN_SYS_AUTO_OFF=9  */
    LCF_e_HdaLgActStatus_t                             CLUHdaLgActive__nu;                       /*!< The signal that USM checks in order to display the LG status,Accuracy: 1.0, Unit: [Enum],List:LCF_LG_INACTIVE=0,LCF_LG_ACTIVE=1  */
    LCF_e_SCCAutoSetSpdEnable_t                        SCCAutoSetSpdEnable__nu;                  /*!< The flag to activate the automatic speed limit change inside SCC,Accuracy: 1.0, Unit: [Enum],List:LCF_MANUAL_SPD_LIMIT=0,LCF_AUTOMATIC_SPD_LIMIT=1  */
    uint8                                              SCCAutoSetSpd__kph;                       /*!< The speed limit that SCC has to follow when HDA is in Auto Set Speed Mode, Unit: [km/h]  */
    LCF_e_CLUAutoSetSpdUpdate_t                        CLUAutoSetSpdUpdate__nu;                  /*!< Indicates whether the set speed is automatically changed (beep sound generated),Accuracy: 1.0, Unit: [Enum],List:LCF_AUTO_SET_SPD_UPD_DEFAULT=0,LCF_AUTO_SET_SPD_UPD_ON=1  */
    LCF_e_CLUHDAStatus_t                               CLUHDAStatus__nu;                         /*!< The status of the HDA Manager,Accuracy: 1.0, Unit: [Enum],List:LCF_HDA_NOT_APPLIED=0,LCF_HDA_FCT_OFF=1,LCF_HDA_FCT_ON=2,LCF_HDA_FAIL=3  */
    LCF_e_CLUHDAMode_t                                 CLUHDAMode__nu;                           /*!< The Control Mode of HDA,Accuracy: 1.0, Unit: [Enum],List:LCF_HDA_MODE_OFF=0,LCF_HDA_MODE_READY=1,LCF_HDA_MODE_ACT=2,LCF_HDA_MODE_RESERVED=3  */
    LCF_e_CLULaneDetect_t                              CLULaneDetect__nu;                        /*!< HDA Lane Detection Information,Accuracy: 1.0, Unit: [Enum],List:LCF_HDA_NO_LANE=0,LCF_HDA_LEFT_LANE=1,LCF_HDA_RIGHT_LANE=2,LCF_HDA_FULL_LANE=3  */
    LCF_e_CLUHDAInfoDisplay_t                          CLUHDAInfoDisplay__nu;                    /*!< This is HDA information display needed for the cluster pop-up display,Accuracy: 1.0, Unit: [Enum],List:LCF_HDA_DISP_NONE=0,LCF_HDA_DISP_SYS_START=1,LCF_HDA_DISP_SYS_AUTO_DISENG_HWY_OFF=2,LCF_HDA_DISP_RESERVED1=3,LCF_HDA_DISP_SYS_FAIL_POPUP=4,LCF_HDA_DISP_HANDS_OFF_POPUP=5,LCF_HDA_DISP_HANDS_OFF_POPUP_W_SOUND=6,LCF_HDA_YS_AUTO_OFF=7  */
    LCF_e_CLUHdaLfaSymbolState_t                       CLUHdaLfaSymbolState__nu;                 /*!< This signal contains the HDA/LFA steering wheel symbol states to be displayed for the driver.,Accuracy: 1.0, Unit: [Enum],List:LCF_HDA_SYMB_OFF=0,LCF_HDA_SYMB_GRAY=1,LCF_HDA_SYMB_GREEN=2,LCF_HDA_SYMB_GREEN_BLINK=3  */
    LCF_e_LatCtrlMod_t                                 TJALatCtrlMode__nu;
    uint8                                              HapticWrnDeviceLeftReq__nu;
    uint8                                              HapticWrnDeviceRightReq__nu;
    uint8                                              HapticWrnDeviceCommonReq__nu;
    uint8                                              VisualWrnDeviceLeftReq__nu;
    uint8                                              VisualWrnDeviceRightReq__nu;
    uint8                                              VisualWrnDeviceCommonReq__nu;
    uint8                                              AcousticWrnReqLeft__nu;
    uint8                                              AcousticWrnReqRight__nu;
    uint8                                              LaneValidQualDMC__nu;                     /*!< S_ABPLBP_LaneValidQualDMC_nu from ABPR to LaDMC  */
    uint8                                              HandsOffSysWarning__nu;
    uint16                                             AvailableFunction__nu;                    /*!< HMI component shall provide the following signal  S_HMOxxx_AvailableFunction_btf  */
    uint8                                              ErrorStateTJA__nu;                        /*!< SAIC Project Request : Customer specific error state for TJA Function (bitfield signal)
0x3=service required; 
0x2=system temporary unavailable; 0x1=performance degradation; 
0x0=no error   */
    uint8                                              CustSpecSysStateTJA__nu;                  /*!< SAIC Project Request : Customer specific system state for TJA Function (bitfield signal)
0x3=Override;
0x2=Active; 
0x1=Stand by; 
0x0=Off  */
    uint8                                              ErrorStateLKA__nu;                        /*!< SAIC Project Request : Customer specific error state for LKA Function (bitfield signal)
0x3=service required; 
0x2=system temporary unavailable; 0x1=performance degradation; 
0x0=no error   */
    uint8                                              CustSpecSysStateLKA__nu;                  /*!< SAIC Project Request : Customer specific system state for LKA Function (bitfield signal)
0x3=Override;
0x2=Active; 
0x1=Stand by; 
0x0=Off  */
    uint8                                              ErrorStateLDP__nu;                        /*!< SAIC Project Request : Customer specific error state for LDP Function (bitfield signal)
0x3=service required; 
0x2=system temporary unavailable; 0x1=performance degradation; 
0x0=no error   */
    uint8                                              CustSpecSysStateLDP__nu;                  /*!< SAIC Project Request : Customer specific system state for LDP Function (bitfield signal)
0x3=Override;
0x2=Active; 
0x1=Stand by; 
0x0=Off  */
    uint8                                              ErrorStateLDW__nu;                        /*!< SAIC Project Request : Customer specific error state for LDW Function (bitfield signal)
0x3=service required; 
0x2=system temporary unavailable; 0x1=performance degradation; 
0x0=no error   */
    uint8                                              CustSpecSysStateLDW__nu;                  /*!< SAIC Project Request : Customer specific system state for LDW Function (bitfield signal)
0x3=Override;
0x2=Active; 
0x1=Stand by; 
0x0=Off  */
    uint8                                              ErrorStateRDP__nu;                        /*!< SAIC Project Request : Customer specific error state for RDP Function (bitfield signal)
0x3=service required; 
0x2=system temporary unavailable; 0x1=performance degradation; 
0x0=no error   */
    uint8                                              CustSpecSysStateRDP__nu;                  /*!< SAIC Project Request : Customer specific system state for RDP Function (bitfield signal)
0x3=Override;
0x2=Active; 
0x1=Stand by; 
0x0=Off  */
    uint8                                              ErrorStateLDPOC__nu;                      /*!< SAIC Project Request : Customer specific error state for LDPOC Function (bitfield signal)
0x3=service required; 
0x2=system temporary unavailable; 0x1=performance degradation; 
0x0=no error   */
    uint8                                              CustSpecSysStateLDPOC__nu;                /*!< SAIC Project Request : Customer specific system state for LDPOC Function (bitfield signal)
0x3=Override;
0x2=Active; 
0x1=Stand by; 
0x0=Off  */
    LCF_INTERFACES_Visualization                       Visualization;
    LCF_INTERFACES_HMI_Out                             HMI_Out;
    float32                                            LCF_Stiffness__nu;                        /*!< LKAS stiffness request to be sent on the bus. (DMC on EBS variant)  */
    float32                                            LCF_Accuracy__nu;                         /*!< LKAS accuracy request to be sent on the bus. (DMC on EBS variant)  */
    uint8                                              TJA_Status__nu;                           /*!< Status of TJA function  */
    LCF_INTERFACES_TMC_SEN_Out                         TMC_SEN_Out;
    uint8                                              CustSpecDrvrTkovReq__nu;                  /*!< SAIC Project Request :
For SAIC HMI, a “Special Driver Takeover Request” in some specific conditions for all the functions.For Eg: “If Yaw Rate is too high, Curvature is too big etc.”. Signal Values:
0x0: FALSE
0x1: TRUE  */
    uint8                                              CustSpecAudReq__nu;                       /*!< SAIC Project Request :
Audio Warning in some specific cases:
“hands off detected in 180s, and intervention frequently(two times above)”. Signal Values:
0x0=no request;
0x1=Level 1;
0x2=Level 2;
0x3=Level 3; 
  */
} LCF_INTERFACES_LCF_SenGenericOutputs;           /* @versionstr: LCF_SEN_OUTPUT_INTFVER */

typedef struct
{
    uint8                                              TMC_DdrData1__nu;                         /*!< TMC specific DDR output
0- 3bit DDR trigger
DDR_NO_REQUEST = 0
DDR_TRIGGERED_BY_UNINTEND_CTRL = 1
DDR_TRIGGERED_BY_QUICK_STR = 2
3-8: not defined 
4-7bit reserve  */
    uint8                                              TMC_DdrData2__nu;                         /*!< TMC specific DDR output
0bit Driver cancel for LKA
NO_REQUEST = 0
DRIVER_CANCEL_REQUESTED = 1
1bit Driver cancel for LDA
NO_REQUEST = 0
DRIVER_CANCEL_REQUESTED = 1
2-7bit reserve  */
    uint8                                              TMC_DdrData3__nu;                         /*!< TMC specific DDR output
0-7bit reserve  */
} LCF_INTERFACES_TMC_VEH_Out;
/*! @brief LCF_VehGenericOutputs->
TMCESA_Out */
typedef struct
{
    uint8                                              TSEAESSysState__nu;                       /*!< Status Function LCF (Bitfield)  */
} LCF_INTERFACES_TMCESA_Out;
typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    LCF_e_LaDMCStatus_t                                LaDMC_Status__nu;                         /*!<  Operation status of the LaDMC for consideration in the LaKMC,Accuracy: 1.0, Unit: [Enum],List:LCF_LADMC_OFF=0,LCF_LADMC_ON=1,LCF_LADMC_DRV_SUPPORT_STEER=2,LCF_LADMC_DRV_COUNTER_STEER=3,LCF_LADMC_PERM_DISABLED=4,LCF_LADMC_TEMP_DISABLED=5,LCF_LADMC_REQUEST=6  */
    uint8                                              LaDMC_Eps_Damping_Level_Request__per;     /*!< Requested activation level of the active damping function in the EPS, Unit: [%]  */
    float32                                            Lkas_StrToqReq__nm;                       /*!< EPS Motor torque request calculated by the LaDMC to be considered in the torque arbitration of the EPS, Unit: [Nm]  */
    LCF_e_LKASActToi_t                                 Lkas_ActToi__nu;                          /*!< This is a flag that is set to 1 when requesting the steering to activate the torque overlay interface (TOI).  This must be done before an attempt is made to request non-zero steering torque overlay.,Accuracy: 1.0, Unit: [Enum],List:LCF_DEACTIVATE_TOI=0,LCF_ACTIVATE_TOI=1  */
    LCF_e_LKASToiFlt_t                                 Lkas_ToiFlt__nu;                          /*!< This fault flag is set when a fault in the LKAS system has been detected by the LKAS ECU such that LKAS can no longer function. CAN failures, internal video ECU failures, hard-wired component (e.g. master switch) failures and other system logic failures are all reported by this flag. Failures reported by the MDPS are not looped back through this flag.,Accuracy: 1.0, Unit: [Enum],List:LCF_NO_FAULT=0,LCF_FAULT_PRESENT=1  */
    float32                                            Lkas_SteeringAngleRate__rps;              /*!< LKAS steering angle rate request, Unit: [rad/s]  */
    float32                                            LaKMC_CrvCmd_Sum__1pm;                    /*!< LaKMC Curvature command including feedforward and tracking control parts., Unit: [1/m]  */
    float32                                            LaKMC_CrvCmd_FF__1pm;                     /*!< LaKMC Curvature command including only feedforward part., Unit: [1/m]  */
    float32                                            LaKMC_CrvCmd_Ctrl__1pm;                   /*!< LaKMC Curvature command including only tracking control part., Unit: [1/m]  */
    LCF_INTERFACES_LaKMC_QuTgtVehCtrl__nu              LaKMC_QuTgtVehCtrl__nu;                   /*!< Qualifier sent to DMC which indicates whether to active DMC or not. (DMC on EBS variant),Accuracy: 1.0, Unit: [Enum],List:LCF_DONOT_REALIZE_TGT_VALUE_QUALIFIER=4,LCF_REALIZE_CRV_QUALIFIER=8,LCF_REALIZE_CRV_SIDE_SLIP_QUALIFIER=9  */
    float32                                            LaDMC_StrAngReq__deg;                     /*!< Steering angle request (to be used in TMC project), Unit: [deg]  */
    float32                                            LaDMC_StrAngEst__deg;                     /*!< Estimated actual steering angle used in LaDMC, Unit: [deg]  */
    uint8                                              LaDMC_ActFunc__nu;                        /*!< This is a bit mapped flag to indicate which function is activating LaDMC.
Application projects can define the meaning of bits.
(e.g. Bit0=TJA, Bit1=LDP)  */
    float32                                            LaDMC_DeratingFactorReq__nu;              /*!< Torque Derating Factor request for motor torque reduction in the EPS upon driver interaction., Unit: [%]  */
    float32                                            LaDMC_StiffnessReq__nu;                   /*!< Steering stiffness request factor scaling the motor output torque of the steer angle controller in the EPS., Unit: [%]  */
    float32                                            LaDMC_AccuracyReq__nu;                    /*!< Steering accuracy request factor for the steer angle control in the EPS., Unit: [%]  */
    uint8                                              LaDMC_SteerAngReqQF__nu;
    uint8                                              LaDMC_YawRateReqQF__nu;
    LCF_INTERFACES_TMC_VEH_Out                         TMC_VEH_Out;
    LCF_INTERFACES_TMCESA_Out                          TMCESA_Out;                               /*!< LCF_VehGenericOutputs->
TMCESA_Out  */
} LCF_INTERFACES_LCF_VehGenericOutputs;           /* @versionstr: LCF_VEH_OUTPUT_INTFVER */

typedef struct
{
    LCF_INTERFACES_LCF_TrajPlanCorridor_t              LeftCorridor;                             /*!< Left corridor boundary  */
    LCF_INTERFACES_LCF_TrajPlanCorridor_t              RightCorridor;                            /*!< Right corridor boundary  */
    LCF_INTERFACES_LCF_TrajPlanCorridor_t              TargetCorridor;                           /*!< Target corridor  */
} AllCoridors_t;
typedef struct
{
    LCF_INTERFACES_TrajServiceQualifier__nu            TrajServiceQualifier__nu;
    float32                                            WeightTgtDistY__nu;
    float32                                            WeightEndTime__nu;
    float32                                            DistYToleranceLeftTgtArea__m;
    float32                                            DistYToleranceRightTgtArea__m;
    float32                                            FTireAclMax__mps2;
    float32                                            FTireAclMin__mps2;
} LCF_INTERFACES_TrajOptimization;
typedef struct
{
    float32                                            DevDistY__m;
    float32                                            DevHeading__rad;
    boolean                                            TriggerReplan__nu;
    float32                                            PredictionTimeHeading__s;
    float32                                            PredictionTimeCrv__s;
    float32                                            PlanningHorizon__s;
} LCF_INTERFACES_TrajCalc;
typedef struct
{
    float32                                            Obstacle_VelX__mps;
    float32                                            Obstacle_AclX__mps2;
    float32                                            Obstacle_Width__m;
    float32                                            Obstacle_DistX__m;
    float32                                            Obstacle_DistY__m;
} LCF_INTERFACES_Obstacle;
typedef struct
{
    boolean                                            LtcyCompActivated__nu;
    float32                                            TimeStamp__s;
} LCF_INTERFACES_LtcyComp;
typedef struct
{
    float32                                            VehGuiCtrl_FTireVel__mps[7];
    float32                                            VehGuiCtrl_DeadTime__s[7];
} LCF_INTERFACES_DeadTimeCalc;
typedef struct
{
    float32                                            MaxCrvTrajGuiCtrl__1pm;
    float32                                            MaxCrvGrdBuildup__1pms;
    float32                                            MaxCrvGrdReduction__1pms;
    float32                                            GrdLimitTgtCrvTrajGuiCtrl__1pms;
} LCF_INTERFACES_CrvLimitation;
typedef struct
{
    float32                                            StrWhStifLimit__nu;                       /*!< Steering Wheel Stiffness Limiter. Situation-, function-,(evtl application-) specific reduction of steering wheel stiffness (lookup table)  */
    float32                                            StrWhStifGrad__1ps;                       /*!< Steering Wheel Stiffness Gradient. Sets gradient of how fast steering wheel stiffness shall change (only function specific -> no lookup table needed)  */
    float32                                            TrqRampGrad__1ps;                         /*!< Torque Ramp Gradient. Sets gradient of how fast EPS output torque shall change during rampin and rampout of the function (only function specific -> no lookup table needed)  */
    float32                                            MaxTrqScalLimit__nu;                      /*!< Maximum Torque Scaling Limiter (Torque saturation). Situation-, function-,(evtl application-) specific reduction of maximum EPS output torque (lookup table)  */
    float32                                            MaxTrqScalGrad__1ps;                      /*!< Maximum Torque Scaling Gradient. Sets gradient of how fast EPS max output torque limit shall change during controlling of the function (only function specific -> no lookup table needed)  */
    uint8                                              HighStatAccu__nu;                         /*!< High Stationary Accuracy required. Set to 1 if high stationary accuracy is need (LDP/RDP,..), set to 0 if high stationary accuracy is not the main priority (e.g. LKA in curves)  */
    uint16                                             RampingDownReq__nu;
    uint16                                             AngleFadingReq__nu;
    uint8                                              DeratingLevel__nu;                        /*!< Every function shall have its own driver override capability! CTRSC will decide which one shall send the request to VEH Task, depending on the priority  */
} LCF_INTERFACES_CtrlTransitions;
typedef struct
{
    LCF_INTERFACES_CrvLimitation                       CrvLimitation;
    LCF_INTERFACES_CtrlTransitions                     CtrlTransitions;
} LCF_INTERFACES_TrajCtrlDirect;
typedef struct
{
    boolean                                            CrvAmplificationActivated__nu;
} LCF_INTERFACES_CrvAmp;
typedef struct
{
    boolean                                            LimiterActivated__nu;
    boolean                                            LimiterType__nu;
    float32                                            LimiterTimeDuration__s;
} LCF_INTERFACES_TrajCtrlLimiter;
typedef struct
{
    AllCoridors_t                                      AllCorridors;
    LCF_INTERFACES_TrajOptimization                    TrajOptimization;
    LCF_INTERFACES_TrajCalc                            TrajCalc;
    LCF_INTERFACES_Obstacle                            Obstacle;
    LCF_INTERFACES_LtcyComp                            LtcyComp;
    LCF_INTERFACES_DeadTimeCalc                        DeadTimeCalc;
    LCF_INTERFACES_TrajCtrlDirect                      TrajCtrlDirect;
    LCF_INTERFACES_CrvAmp                              CrvAmp;
    LCF_INTERFACES_TrajCtrlLimiter                     TrajCtrlLimiter;
} LCF_INTERFACES_LCF_FCT;
typedef struct
{
    LCF_e_LcfCtrlAbort_t                               LcfCtrlAbort__nu;                         /*!< When LCF judges to abort condition, DMC  shall set EPS request[Nm or rad]  to 0 immediately. (requirement from TMC),Accuracy: 1.0, Unit: [Enum],List:LCF_DMC_NOABORT_REQUEST=0,LCF_DMC_ABORT_REQUEST=1  */
    uint8                                              LnBndValidLKA__nu;                        /*!< Lane boundaries validity from LKA function  */
    uint8                                              LnBndValidLDW__nu;                        /*!< Lane boundaries validity from LDW function  */
    uint8                                              LnBndValidLDP__nu;                        /*!< Lane boundaries validity from LDP function  */
    uint8                                              LnBndValidRDP__nu;                        /*!< Lane boundaries validity from RDP function  */
    uint8                                              LnBndValidLDPOC__nu;                      /*!< Lane boundaries validity from LDPOC function  */
    uint8                                              LnBndValidTJA__nu;                        /*!< Lane boundaries validity from TJA function  */
    uint8                                              LnBndValidALCA__nu;                       /*!< Lane boundaries validity from ALCA function  */
    uint16                                             LcfFctAvailability__nu;                   /*!< LCF functions availability bitfield (see bit positions defines in Static Variables sheet)  */
} LCF_INTERFACES_LCF_SysCoordinator;
typedef struct
{
    float32                                            ABP_CamCorridorCurvature__1pm;            /*!< Pure curvature command from the camera regarding the middle of the lane without modification by the trajectory planner, without preview, without latency compensation. , Unit: [1/m]  */
    float32                                            ABP_CamLateralError__m;                   /*!< Lateral error with respect to the middle of the lane as seen by the camera without modification by the trajectory planner, without preview, without latency compensation. , Unit: [m]  */
    float32                                            ABP_CamHeadingError__rad;                 /*!< Heading error with respect to the middle of the lane as seen by the camera without modification by the trajectory planner, without preview, without latency compensation., Unit: [rad]  */
} LCF_INTERFACES_ABP_CamRawData;
typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    LCF_e_ControllingFunction_t                        ControllingFunction_nu;
    uint8                                              ActFctEnabled_nu;                         /*!< Used in Hyundai project to activate DRVMN in case a function possibly controlling is active  */
    uint8                                              ActFctLevel_nu;                           /*!< Used in LCF project to activate DRVMN in case a function possibly controlling is active  */
    uint8                                              SpecialDrivingCorridor__nu;               /*!< To signalize special driving corridor situation where special control concept is needed, e.g. Fishbone zone  */
    float32                                            MaxJerkAllowed_mps3;
    uint8                                              OcObjActSide_nu;                          /*!< This signal is provided by LDPOCSA. Requested by TMC  */
    uint8                                              AngReqMaxLimitScale_per;                  /*!< This signal is provided by the LTA Manager in the TMC Project. , Unit: [%]  */
    uint8                                              AngReqRateMaxLimitScale_per;              /*!< This signal is provided by the LTA Manager in the TMC Project. , Unit: [%]  */
    uint8                                              StraightPathDtct_nu;                      /*!< Straight Path provided by ABPR to LATDMC  */
    float32                                            Reserved1_nu;                             /*!< For unexpected development needs, to avoid RTE updates.  */
    float32                                            Reserved2_nu;                             /*!< For unexpected development needs, to avoid RTE updates.  */
    LCF_INTERFACES_LCF_FCT                             LCF_FCT;
    LCF_INTERFACES_LCF_SysCoordinator                  LCF_SysCoordinator;
    LCF_INTERFACES_ABP_CamRawData                      ABP_CamRawData;
    LCF_INTERFACES_LCF_Event_t                         EvntDtctnSenEvents__nu[5];                /*!< LCF/TJA event communication channels between LCF/TJA LaDmcOnIuC and LCF_SEN and LCF_VEH and LCF_SEN component  */
} LCF_INTERFACES_LCF_SenToVeh;           /* @versionstr: LCF_SEN2VEH_INTFVER */

typedef struct
{
    boolean                                            TrigCustFctReplanCurValues__nu;
} LCF_INTERFACES_ReplanValues;
typedef struct
{
    float32                                            CurDistY__m;
    float32                                            CurHeading__rad;
    float32                                            LtcyComp_DevHeading__rad;
} LCF_INTERFACES_TrajError;
typedef struct
{
    float32                                            TrajDistY__m;
    float32                                            TrajHeading__rad;
    float32                                            TrajHeadingInclPreview__rad;
} LCF_INTERFACES_DesiredTraj;
typedef struct
{
    float32                                            TgtTrajCrv__1pm;
    float32                                            TgtTrajCrvGrd__1pms;
    float32                                            LtcyComp_RightCorridorCrv__1pm;
} LCF_INTERFACES_TrajPlanCurvatures;
typedef struct
{
    float32                                            CtrlErrDistY__m;                          /*!< Current distance error, Unit: [m]  */
    float32                                            CtrlErrHeadingAngle__rad;                 /*!< Current heading angle error, Unit: [rad]  */
} LCF_INTERFACES_Errors;
typedef struct
{
    float32                                            TgtCrv_NoDE__1pm;                         /*!< Target curvature (no DE), Unit: [1/m]  */
    float32                                            TgtCrv_DEWithNoLatSlp__1pm;               /*!< Target curvature (no DE, no slope), Unit: [1/m]  */
    float32                                            TgtCrv_DE__1pm;                           /*!< Target curvature (DE), Unit: [1/m]  */
    float32                                            TgtCrv_Limited__1pm;                      /*!< Limited target curvature, Unit: [1/m]  */
    float32                                            TgtCrv_Gradient__1pms;                    /*!< Limited target curvature gradient  */
} LCF_INTERFACES_Curvatures;
typedef struct
{
    LCF_INTERFACES_TgtVehCtrlQualifier__nu             TgtVehCtrlQualifier__nu;                  /*!< Qualifier of output,Accuracy: 1.0, Unit: [Enum],List:LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_DONOT_REALIZE_TGT_VALUE_QUALIFIER=4,LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_REALIZE_CRV_QUALIFIER=8,LCF_TRAJ_CTRL_TRAJ_GUI_CTRL_REALIZE_CRV_SIDE_SLIP_QUALIFIER=9  */
    boolean                                            TgtCrv_LimiterWarning__nu;                /*!< Curvature output limited,Accuracy: 1.0, Range:[0..1]  */
    uint8                                              TrjCtrQualifierService__nu;               /*!< Trajectory Controller Qualifier, which provides a feedback about the controller state and a potential error condition.  */
    uint16                                             QuStatusTrajPlan__nu;                     /*!< Trajectory Planner Calculation Qualifier, which provides a feedback, if the planner found a trajectory or not, if the limiter is active or not etc..   */
    uint8                                              LaDmcQualifierService__nu;                /*!< Lateral Dynamic Motion Controller Qualifier, which provides detailed information about the LaDMC operation mode.  */
} LCF_INTERFACES_Flags;
typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    float32                                            DrvAttention_perc;                        /*!< Estimated Driver Attention, Unit: [%], Range:[-100..100]  */
    sint8                                              DrvAttentionConf_perc;                    /*!< Estimated Driver Attention Confidence, Unit: [%], Range:[0..100]  */
    uint8                                              DrvMonSysWarning_nu;                      /*!< Driver monitoring warning, used by HMI for Hyundai  */
    uint8                                              HandsOffConfirmed_nu;                     /*!< Driver monitoring hands off confirmed  */
    uint8                                              AbuseWarning_nu;                          /*!< Driver monitoring abuse warning  */
    float32                                            EstHandTor_nm;                            /*!< Driver monitoring estimated hands torque  */
    uint8                                              SAC_Eps_Request_Flag__nu;
    float32                                            Reserved1_nu;                             /*!< For unexpected development needs, to avoid RTE updates.  */
    float32                                            Reserved2_nu;                             /*!< For unexpected development needs, to avoid RTE updates.  */
    LCF_INTERFACES_ReplanValues                        ReplanValues;
    LCF_INTERFACES_TrajError                           TrajError;
    LCF_INTERFACES_DesiredTraj                         DesiredTraj;
    LCF_INTERFACES_TrajPlanCurvatures                  TrajPlanCurvatures;
    LCF_INTERFACES_Errors                              Errors;
    LCF_INTERFACES_Curvatures                          Curvatures;
    LCF_INTERFACES_Flags                               Flags;
    LCF_INTERFACES_LCF_Event_t                         EvntDtctnVehEvents__nu[5];                /*!< LCF/TJA event communication channels between LCF/TJA LaDmcOnIuC and LCF_SEN and LCF_VEH and LCF_SEN component  */
    uint8                                              TSEMDC_ControllingFunction_nu;            /*!< Mde controller output calculated in TMCESA component to arbitrate between functions running on LCF_SEN ad LCF_VEH  */
} LCF_INTERFACES_LCF_VehToSen;           /* @versionstr: LCF_VEH2SEN_INTFVER */

typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    boolean                                            SAC_Activation_Request__nu;
    uint8                                              SAC_Activation_Request_Qf__nu;
    boolean                                            SAC_Force_Shut_Off_Request;
    sint16                                             SAC_Steer_Angle_Command__deg;
    sint16                                             SAC_Torque_Overlay_Request__nm;
    uint8                                              SAC_Stiffness_Request__per;
    uint8                                              SAC_Accuracy_Request__per;
    uint8                                              SAC_Steering_Wheel_Vibration__nu;
    uint8                                              SAC_Lane_Status__nu;
    uint8                                              SAC_Derating_Level_Request__per;
    uint8                                              SAC_Torque_Ramp_Factor__per;
} LCF_INTERFACES_LCF_LaDmcSocToIuc;           /* @versionstr: LCF_SOC2IUC_INTFVER */

typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    uint16                                             SAC_Dmc_Status__nu;
    sint16                                             SAC_Eps_Torque_Request__nm;
    uint8                                              SAC_Eps_Request_Flag__nu;
    LCF_INTERFACES_LCF_Event_t                         EvntDtctnIucEvents__nu[5];                /*!< LCF/TJA event communication channels between LCF/TJA LaDmcOnIuC and LCF_SEN and LCF_VEH and LCF_SEN component  */
} LCF_INTERFACES_LCF_LaDmcIucToSoc;           /* @versionstr: LCF_IUC2SOC_INTFVER */

typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    sint16                                             VEH_Delta_L__deg;
    uint8                                              VEH_Delta_L_Qf__nu;
    sint16                                             VEH_Delta_L_Dot__dps;
    uint8                                              VEH_Delta_L_Dot_Qf__nu;
    sint16                                             VEH_Steer_Torque__nm;
    uint8                                              VEH_Steer_Torque_Qf__nu;
    uint8                                              EPS_Fail_Stat__nu;
    uint8                                              EPS_Toi_Unavail__nu;
    uint8                                              EPS_Toi_Active__nu;
    uint8                                              EPS_Toi_Flt__nu;
    sint16                                             VEH_Yaw_Rate__dps;
    uint8                                              VEH_Yaw_Rate_Qf__nu;
    sint16                                             VEH_Vehicle_Velocity__kph;
    uint8                                              ESC_Active_State__nu;
    uint8                                              ESC_System_State__nu;
    uint8                                              ABS_Active_State__nu;
    uint8                                              ABS_System_State__nu;
    uint8                                              TCS_Active_State__nu;
    uint8                                              TCS_System_State__nu;
} LCF_INTERFACES_LCF_CanToLaDmcIuc;           /* @versionstr: LCF_CAN2LADMCIUC_INTFVER */

typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    sint16                                             SAC_Eps_Torque_Request__nm;
    uint8                                              SAC_Eps_Request_Flag__nu;
    uint8                                              SAC_Eps_Damping_Level_Request__per;
    uint8                                              SAC_Eps_Torque_RequestQF__nu;             /*!< SAIC Request, Unit: [%]  */
} LCF_INTERFACES_LCF_LaDmcIucToCan;           /* @versionstr: LCF_LADMCIUC2CAN_INTFVER */

typedef struct
{
    AlgoInterfaceVersionNumber_t                       uiVersionNumber;                          /*!< Version number of interface  */
    BASE_INTERFACES_SignalHeader_t                     sSigHeader;                               /*!< Signal header with common signal information  */
    uint8                                              AdpCorrFactorPos_nu[20];                  /*!< Containing the current kappa-2-angle correction factor table for left cornerings  */
    uint16                                             AdpCorrCounterPos_nu[20];                 /*!< Containing the number of the summed learning events of the kappa-2-angle correction factor table for left cornerings  */
    uint8                                              AdpCorrFactorNeg_nu[20];                  /*!< Containing the current kappa-2-angle correction factor table for right cornerings  */
    uint16                                             AdpCorrCounterNeg_nu[20];                 /*!< Containing the number of the summed learning events of the kappa-2-angle correction factor table for right cornerings  */
    sint16                                             AngleOff_nu;                              /*!< Containing the offset from the current ignition cycle  */
    uint16                                             AngleOffCalibCnt_nu;                      /*!< Reflecting the validity of the offset  */
} LCF_INTERFACES_NVM_LcfLearningData;           /* @versionstr: LCF_LEARNDATA_INTFVER */


#ifdef __cplusplus
}
#endif

#endif /* #if (GA_CFG_LCF_INTERFACES == 1) */

/*! @} end defgroup */

#endif /* #ifndef GA_LCF_INTERFACES_EXT_H_INCLUDED */
