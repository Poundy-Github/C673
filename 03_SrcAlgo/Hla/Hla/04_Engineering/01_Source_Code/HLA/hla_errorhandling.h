/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx
 
  COMPONENT:              HLA
 
  FILENAME:               hla_errorhandling.h
 
  DESCRIPTION:            Error handling stuff like error stack, error handler,
                          error types, etc.
 
  CREATION DATE:          2016-08-09
 
  CPU:                    Independent
 
  VERSION:                $Revision: 1.17 $
*************************************************************************** */
/* avoid cyclic binding ---------------------------------------------------*/
#ifndef H_HLA_ERROR_HANDLING_H
#define H_HLA_ERROR_HANDLING_H

/****************************************************************************
* INCLUDES
*****************************************************************************/
 
/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/
 /* Right shift by 5 is equal to integer division by 32 which determines how 
 *  many bit fields - each with 32 bits - are required
 */
/* PRQA S 4523 ++ # 2019-05-28 M.Mutschler: Enum value used with shift operator is ok by design. */
#define HLA_ERROR_HANDLING_ARRAY_SIZE(LAST_ENUM_ENTRY) (((LAST_ENUM_ENTRY) >> 5) + 1) ///< size of error handling array

/* Hash values representing corresponding enum definitions */
#define HLA_ERROR_HASH_ERRORS       (0xa6f3d019u) ///< hash value for errors, which is calculated from the e_ErrorHandling_Errors enum
#define HLA_ERROR_HASH_WARNINGS     (0x0df2efd2u) ///< hash value for warnings, which is calculated from the e_ErrorHandling_Warnings enum
#define HLA_ERROR_HASH_INFORMATION  (0xef03e5c9u) ///< hash value for informations, which is calculated from the e_ErrorHandling_Information enum

/****************************************************************************
* TYPEDEFS
*****************************************************************************/
/// \brief enum for errors in HLA error stack
typedef enum
{
  HLA_ERROR_PRO_PORT_NULL_POINTER_LIST = 0,                                         ///< null pointer in provide ports
  HLA_ERROR_PRO_PORT_NULL_POINTER_COMP_STATE,                                       ///< null pointer in comp sate
  HLA_ERROR_PRO_PORT_NULL_POINTER_HEADLIGHT_CONTROL,                                ///< null pointer in headlight control

  HLA_ERROR_SERVICES_NULL_POINTER_LIST,                                             ///< null pointer in service functions
  HLA_ERROR_SERVICES_NULL_POINTER_ADD_RTA_EVENT,                                    ///< null pointer in add rta event function
  HLA_ERROR_SERVICES_NULL_POINTER_MEAS_START_CYCLE,                                 ///< null pointer in meas start cycle function
  HLA_ERROR_SERVICES_NULL_POINTER_MEAS_FREEZE,                                      ///< null pointer in meas freeze function
  HLA_ERROR_SERVICES_NULL_POINTER_DEM_SET_EVENT,                                    ///< null pointer in dem set event function
  HLA_ERROR_SERVICES_NULL_POINTER_DEM_EXT_DATA,                                     ///< null pointer in dem ext data function
  
  HLA_ERROR_REQ_PORTS_NULL_POINTER_LIST,                                            ///< null pointer in req ports list
  HLA_ERROR_REQ_PORTS_NULL_POINTER_BASE_CONTROL_DATA,                               ///< null pointer in base control data
  HLA_ERROR_REQ_PORTS_NULL_POINTER_CPAR_HLAF,                                       ///< null pointer in hlaf cpar
  HLA_ERROR_REQ_PORTS_NULL_POINTER_MONO_CALI,                                       ///< null pointer in mono calibration
  HLA_ERROR_REQ_PORTS_NULL_POINTER_HLA_BUS_INPUT_SIGNALS,                           ///< null pointer in hla bus input signals
  HLA_ERROR_REQ_PORTS_NULL_POINTER_VEH_SIG,                                         ///< null pointer in vehicle signals
  HLA_ERROR_REQ_PORTS_NULL_POINTER_VDY_DATA,                                        ///< null pointer in vdy data
  HLA_ERROR_REQ_PORTS_NULL_POINTER_BLOCKAGE,                                        ///< null pointer in blockage
  HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_ENVIRONMENT_DATA,                            ///< null pointer in lsd environment data
  HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTOBJECTLIST,                             ///< null pointer in lsd light object list
  HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTLIST,                                   ///< null pointer in lsd light list
  
  HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BASE_CONTROL_DATA,                             ///< req ports version number base control data error
  HLA_ERROR_REQ_PORTS_VERSION_NUMBER_CPAR_HLAF,                                     ///< req ports version number cpar hlaf error
  HLA_ERROR_REQ_PORTS_VERSION_NUMBER_MONO_CALI,                                     ///< req ports version number mono cali error
  HLA_ERROR_REQ_PORTS_VERSION_NUMBER_HLA_BUS_INPUT_SIGNALS,                         ///< req ports version number hla bus input signals error
  HLA_ERROR_REQ_PORTS_VERSION_NUMBER_VEH_SIG,                                       ///< req ports version number veh sig error
  HLA_ERROR_REQ_PORTS_VERSION_NUMBER_VDY_DATA,                                      ///< req ports version number vdy data error
  HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BLOCKAGE,                                      ///< req ports version number blockage error
  HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_ENVIRONMENT_DATA,                          ///< req ports version number lsd environment data error
  HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_LIGHTOBJECTLIST,                           ///< req ports version number lsd light object list error
  HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_LIGHTLIST,                                 ///< req ports version number lsd light list error
  
  HLA_ERROR_REQ_PORTS_SIG_STATE_BASE_CONTROL_DATA,                                  ///< error req ports sig state base control data
  HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_CPAR_HLAF,                                     ///< error req ports sig state init cpar hlaf
  HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_MONO_CALI,                                     ///< error req ports sig state init mono cali
  HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_HLA_BUS_INPUT_SIGNALS,                         ///< error req ports sig state init hla bus input signals
  HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_VEH_SIG,                                       ///< error req ports sig state init veh sig
  HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_VDY_DATA,                                      ///< error req ports sig state init vdy data
  HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_BLOCKAGE,                                      ///< error req ports sig state init blockage
  HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_ENVIRONMENT_DATA,                          ///< error req ports sig state init lsd environment data
  HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTOBJECTLIST,                           ///< error req ports sig state init lsd light object list
  HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTLIST,                                 ///< error req ports sig state init lsd light list
  HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_CPAR_HLAF,                                  ///< error req ports sig state invalid cpar hlaf
  HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_MONO_CALI,                                  ///< error req ports sig state invalid mono cali
  HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_HLA_BUS_INPUT_SIGNALS,                      ///< error req ports sig state invalid hla bus input signals
  HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_VEH_SIG,                                    ///< error req ports sig state invalid veh sig
  HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_VDY_DATA,                                   ///< error req ports sig state invalid vdy data
  HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_BLOCKAGE,                                   ///< error req ports sig state invalid blockage
  HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_ENVIRONMENT_DATA,                       ///< error req ports sig state invalid lsd environment data
  HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_LIGHTOBJECTLIST,                        ///< error req ports sig state invalid lsd light objectlist
  HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_LIGHTLIST,                              ///< error req ports sig state invalid lsd light list

  HLA_ERROR_REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA,                                  ///< error req ports timestamp base control data
  HLA_ERROR_REQ_PORTS_TIMESTAMP_MONO_CALI,                                          ///< error req ports timestamp mono cali
  HLA_ERROR_REQ_PORTS_TIMESTAMP_HLA_BUS_INPUT_SIGNALS,                              ///< error req ports timestamp hla bus input signals
  HLA_ERROR_REQ_PORTS_TIMESTAMP_VEH_SIG,                                            ///< error req ports timestamp veh sig
  HLA_ERROR_REQ_PORTS_TIMESTAMP_VDY_DATA,                                           ///< error req ports timestamp vdy data
  HLA_ERROR_REQ_PORTS_TIMESTAMP_BLOCKAGE,                                           ///< error req ports timestamp blockage
  HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_ENVIRONMENT_DATA,                               ///< error req ports timestamp lsd environment data
  HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST,                                ///< error req ports timestamp lsd light object list
  HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTLIST,                                      ///< error req ports timestamp lsd light list

  HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BASE_CONTROL_DATA,                               ///< error req ports meas counter base control data
  HLA_ERROR_REQ_PORTS_MEAS_COUNTER_CPAR_HLAF_PAR,                                   ///< not in use according to architecture but still needed for correct port index reporting (DEM Events) */
  HLA_ERROR_REQ_PORTS_MEAS_COUNTER_MONO_CALI,                                       ///< error req ports meas counter mono cali
  HLA_ERROR_REQ_PORTS_MEAS_COUNTER_HLA_BUS_INPUT_SIGNALS,                           ///< error req ports meas counter hla bus input signals
  HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VEH_SIG,                                         ///< error req ports meas counter veh sig
  HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VDY_DATA,                                        ///< error req ports meas counter vdy data
  HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BLOCKAGE,                                        ///< error req ports meas counter blockage
  HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_ENVIRONMENT_DATA,                            ///< error req ports meas counter lsd environment data
  HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTOBJECTLIST,                             ///< error req ports meas counter lsd light object list
  HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTLIST,                                   ///< error req ports meas counter lsd light list

  HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_YAW_RATE,                                       ///< error req ports bus sig state yaw rate
  HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_CURVE,                                          ///< error req ports bus sig state curve
  HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_SWA,                                            ///< error req ports bus sig state steering wheel angle
  HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_VELOCITY,                                       ///< error req ports bus sig state velocity
  HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_ACCELERATION,                                   ///< error req ports bus sig state acceleration
  HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_MOTION_STATE,                                   ///< error req ports bus sig state motion state
  HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_DISPLAY_SPEED,                                  ///< error req ports bus sig state display speed
  HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_WIPER_STATE,                                    ///< error req ports bus sig state wiper state

  HLA_ERROR_CRITICAL_INPUTS_MONO_CALI,                                              ///< error critical inputs calibration data
  HLA_ERROR_CRITICAL_INPUTS_VDY,                                                    ///< error critical inputs VDY data

  HLA_ERROR_CPAR_RANGE_CHECK_HLAF_ALGO_CONFIG_PARAMETERS,                           ///< error cpar range check hlaf algo config parameters
  HLA_ERROR_CPAR_RANGE_CHECK_HLAF_KEEP_ON_DELAY_PARAMETERS,                         ///< error cpar range check hlaf keep on delay parameters
  HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_ON_DELAY_PARAMETERS,                         ///< error cpar range check hlaf turn on delay parameters
  HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_OFF_DELAY_PARAMETERS,                        ///< error cpar range check hlaf turn off delay parameters
  HLA_ERROR_CPAR_RANGE_CHECK_HLAF_SPEED_PARAMETERS,                                 ///< error cpar range check hlaf speed parameters
  HLA_ERROR_CPAR_RANGE_CHECK_HLAF_MATRIX_PARAMETERS,                                ///< error cpar range check hlaf matrix parameters
  HLA_ERROR_CPAR_RANGE_CHECK_HLAF_DIMMING_PARAMETERS,                               ///< error cpar range check hlaf dimming parameters

  HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_KEEP_ON_PARAMETERS,                        ///< error cpar plausibility check hlaf keep on parameters
  HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_TURN_ON_PARAMETERS,                        ///< error cpar plausibility check hlaf turn on parameters
  HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_SPEED_PARAMETERS,                          ///< error cpar plausibility check hlaf speed parameters

  HLA_ERROR_OUTPUT_CHECK_SIG_STATE,  ///< error output check sig state
  /* PRQA S 0779 ++ # 2019-05-28 M.Mutschler: Following enum values are generated by a script. Therefore we accept similar names. */
  /* OUTPUT_CHECK_ERRORS_START */
  HLA_ERROR_OUTPUT_CHECK_HEADLIGHTCONTROL,                                          ///< Error bit is set if any of below defined error messages were set.

  HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_OBJID,                                 ///< Error bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryLeft_ObjId of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_OBJID,                                ///< Error bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryRight_ObjId of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLOWER_OBJID,                                ///< Error bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryLower_ObjId of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYUPPER_OBJID,                                ///< Error bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryUpper_ObjId of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_OBJID,                                ///< Error bit is set in case \ref RTE_HLAF_MatrixGFA_t::ClosestObj_ObjId of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_OBJID,                                  ///< Error bit is set in case \ref RTE_HLAF_MatrixGFA_t::MinLight_ObjId of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  /* OUTPUT_CHECK_ERRORS_END */
  /* PRQA S 0779 -- */

  HLA_ERROR_BLOCKAGE_NO_VALID_INPUT,                                                ///< error blockage no valid input

  /* PRQA S 647 1 # 2019-05-28 M.Mutschler: Enum is designed to take as many error as possible */
  HLA_ERROR_LAST_ENUM_ENTRY                                                         ///< error last enum entry
} e_ErrorHandling_Errors;

/// \brief enum for warnings in HLA error stack
typedef enum
{
  HLA_WARNING_REQ_PORTS_SIG_STATE_CPAR_HLAF = 0,                                    ///< hla warning req ports sig state cpar hlaf
  HLA_WARNING_REQ_PORTS_SIG_STATE_MONO_CALI,                                        ///< hla warning req ports sig state mono cali
  HLA_WARNING_REQ_PORTS_SIG_STATE_HLA_BUS_INPUT_SIGNALS,                            ///< hla warning req ports sig state hla bus input signals
  HLA_WARNING_REQ_PORTS_SIG_STATE_VEH_SIG,                                          ///< hla warning req ports sig state veh sig
  HLA_WARNING_REQ_PORTS_SIG_STATE_VDY_DATA,                                         ///< hla warning req ports sig state vdy data
  HLA_WARNING_REQ_PORTS_SIG_STATE_BLOCKAGE,                                         ///< hla warning req ports sig state blockage
  HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_ENVIRONMENT_DATA,                             ///< hla warning req ports sig state lsd environment data
  HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTOBJECTLIST,                              ///< hla warning req ports sig state lsd light objectlist
  HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTLIST,                                    ///< hla warning req ports sig state lsd light list

  HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_ALGO_CONFIG_PARAMETERS,                    ///< hla warning cpar diff to defaults hlaf algo config parameters
  HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_KEEP_ON_DELAY_PARAMETERS,                  ///< hla warning cpar diff to defaults hlaf keep on delay parameters
  HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_ON_DELAY_PARAMETERS,                  ///< hla warning cpar diff to defaults hlaf turn on delay parameters
  HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_OFF_DELAY_PARAMETERS,                 ///< hla warning cpar diff to defaults hlaf turn off delay parameters
  HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_SPEED_PARAMETERS,                          ///< hla warning cpar diff to defaults hlaf speed parameters
  HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_MATRIX_PARAMETERS,                         ///< hla warning cpar diff to defaults hlaf matrix parameters
  HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_DIMMING_PARAMETERS,                        ///< hla warning cpar diff to defaults hlaf dimming parameters

  HLA_WARNING_OUTPUT_CHECK_COMP_STATE_INTERFACE_VERSION,                            ///< hla warning output check comp state interface version
  HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SIG_STATE,                                    ///< hla warning output check comp state sig state
  HLA_WARNING_OUTPUT_CHECK_COMP_STATE_COMP_STATE,                                   ///< hla warning output check comp state comp state
  HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SCHEDULER_SUBMODE_REQUEST,                    ///< hla warning output check comp state scheduler submode request
  HLA_WARNING_OUTPUT_CHECK_COMP_STATE_ALGO_QUALIFIER,                               ///< hla warning output check comp state algo qualifier
  HLA_WARNING_OUTPUT_CHECK_NVM_HLAR_LEARNINGVALUES,                                 ///< hla warning output check nvm hlar learningvalues 
  /* PRQA S 0779 ++ # 2019-05-28 M.Mutschler: Following enum values are generated by a script. Therefore we accept similar names. */
  /* OUTPUT_CHECK_WARNINGS_START */

  HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_HLAFUNCTIONSTATUS,                      ///< Warning bit is set in case \ref RTE_HLAF_HeadlightControl_t::hlaFunctionStatus of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TRAFFICSTYLE,                    ///< Warning bit is set in case \ref RTE_HLAF_HeadlightControl_Common_t::TrafficStyle of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_CITYSTATE,                       ///< Warning bit is set in case \ref RTE_HLAF_HeadlightControl_Common_t::CityState of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE,                    ///< Warning bit is set in case \ref RTE_HLAF_HeadlightControl_Common_t::WeatherState of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TUNNELSTATE,                     ///< Warning bit is set in case \ref RTE_HLAF_HeadlightControl_Common_t::TunnelState of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_MOTORWAYSTATE,                   ///< Warning bit is set in case \ref RTE_HLAF_HeadlightControl_Common_t::MotorwayState of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_BRIGHTNESSSTATE,                 ///< Warning bit is set in case \ref RTE_HLAF_HeadlightControl_Common_t::BrightnessState of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SENSMODE,                        ///< Warning bit is set in case \ref RTE_HLAF_HeadlightControl_Common_t::SensMode of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SPEEDSTATE,                      ///< Warning bit is set in case \ref RTE_HLAF_HeadlightControl_Common_t::SpeedState of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SCENEINFO,                       ///< Warning bit is set in case \ref RTE_HLAF_HeadlightControl_Common_t::SceneInfo of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIX_NGFA,                                             ///< Warning bit is set in case \ref RTE_HLAF_Matrix_t::nGFA of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIX_GFASTATUS,                                        ///< Warning bit is set in case \ref RTE_HLAF_Matrix_t::GFAStatus of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIX_HIGHBEAMSTATE,                                    ///< Warning bit is set in case \ref RTE_HLAF_Matrix_t::HighBeamState of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_DIST,                                     ///< Warning bit is set in case \ref RTE_HLAF_Matrix_t::LowBeam_Dist of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_ANG,                                      ///< Warning bit is set in case \ref RTE_HLAF_Matrix_t::LowBeam_Ang of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS,                                   ///< Warning bit is set in case \ref RTE_HLAF_Matrix_t::LowBeam_Status of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIX_TURNOFFREASON,                                    ///< Warning bit is set in case \ref RTE_HLAF_Matrix_t::TurnOffReason of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_ANG,                                 ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryLeft_Ang of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DIST,                                ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryLeft_Dist of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_ANG_CAM,                             ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryLeft_Ang_Cam of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTSTATE,                           ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryLeft_DistState of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTRELIABILITY,                     ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryLeft_DistReliability of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_ANG,                                ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryRight_Ang of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_DIST,                               ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryRight_Dist of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_ANG_CAM,                            ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryRight_Ang_Cam of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLOWER_ANG_CAM,                            ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryLower_Ang_Cam of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYUPPER_ANG_CAM,                            ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::BndryUpper_Ang_Cam of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_DIST,                               ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::ClosestObj_Dist of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_ANG,                                ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::ClosestObj_Ang of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_DIST,                                 ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::MinLight_Dist of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_ANG,                                  ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::MinLight_Ang of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT,                                     ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::ttb18Left of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT_STATUS,                              ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::ttb18Left_Status of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18RIGHT,                                    ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::ttb18Right of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_EXISTENCEPROB,                                 ///< Warning bit is set in case \ref RTE_HLAF_MatrixGFA_t::ExistenceProb of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGSTATUS,                              ///< Warning bit is set in case \ref RTE_HLAF_LightDimming_t::DimmingStatus of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGAREA,                                ///< Warning bit is set in case \ref RTE_HLAF_LightDimming_t::DimmingArea of provide port \ref proHlaPrtList_t::pHlaf_HeadlightControl is out of defined range as defined in column <tt>Type Range</tt> in [hla_algo_interface_types.xls](http://ims-adas:7001/si/viewrevision?projectName=%23%2FADAS%2FSW%23Components%2FHLA_HeadLightAssist%2F03_Design%2F03_Code_Generation%2FGeneric%2FHLA&selection=hla_algo_interface_types.xls)
  /* OUTPUT_CHECK_WARNINGS_END */
  /* PRQA S 0779 -- */

  HLA_WARNING_ROI_LIMITED_TOP,                                                      ///< hla warning roi limited top
  HLA_WARNING_ROI_LIMITED_BOTTOM,                                                   ///< hla warning roi limited bottom
  HLA_WARNING_ROI_LIMITED_LEFT,                                                     ///< hla warning roi limited left
  HLA_WARNING_ROI_LIMITED_RIGHT,                                                    ///< hla warning roi limited right
  HLA_WARNING_OUT_OF_RANGE_ROI_HEIGHT,                                              ///< hla warning out of range roi height
  HLA_WARNING_OUT_OF_RANGE_ROI_WIDTH,                                               ///< hla warning out of range roi width
  HLA_WARNING_OUT_OF_RANGE_FOE_X,                                                   ///< hla warning out of range foe x
  HLA_WARNING_OUT_OF_RANGE_FOE_Y,                                                   ///< hla warning out of range foe y

  HLA_WARNING_TIME_DIFF_BETWEEN_TWO_CYCLES_TOO_BIG,                                 ///< hla warning in case time difference between two consecutive calls was above a certain threshold.

  /* PRQA S 647 1 # 2019-05-28 M.Mutschler: Enum is designed to take as many warnings as possible */
  HLA_WARNING_LAST_ENUM_ENTRY                                                       ///< hla warning last enum entry
} e_ErrorHandling_Warnings;

/// \brief enum for informations in HLA error stack
typedef enum
{
  HLA_INFORMATION_REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST = 0,                        ///< information req ports null pointer em object list
  HLA_INFORMATION_REQ_PORTS_NULL_POINTER_HLA_RADAR_OBJECT_LIST,                     ///< information req ports null pointer hla radar object list
  HLA_INFORMATION_REQ_PORTS_VERSION_NUMBER_EM_OBJECT_LIST,                          ///< information req ports version number em object list
  HLA_INFORMATION_REQ_PORTS_VERSION_NUMBER_HLA_RADAR_OBJECT_LIST,                   ///< information req ports version number hla radar object list
  HLA_INFORMATION_REQ_PORTS_SIG_STATE_EM_OBJECT_LIST,                               ///< information req ports sig state em object list
  HLA_INFORMATION_REQ_PORTS_SIG_STATE_HLA_RADAR_OBJECT_LIST,                        ///< information req ports sig state hla radar object list
  HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST,                               ///< information req ports timestamp em object list
  HLA_INFORMATION_REQ_PORTS_TIMESTAMP_HLA_RADAR_OBJECT_LIST,                        ///< information req ports timestamp hla radar object list
  HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_EM_OBJECT_LIST,                            ///< information req ports meas counter em object list
  HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_HLA_RADAR_OBJECT_LIST,                     ///< information req ports meas counter hla radar object list
                                                                                    
  HLA_INFORMATION_CALIBRATION_DIFF_TO_EMO_CALI,                                     ///< information calibration diff to emo cali
  HLA_INFORMATION_CALIBRATION_INPUT_QUALI,                                          ///< information calibration input quali
                                                                                    
  HLA_INFORMATION_EDMA_COPY_FAILED,                                                 ///< information edma copy failed
  HLA_INFORMATION_EDMA_WAIT_FAILED,                                                 ///< information edma wait failed
                                                                                    
  HLA_INFORMATION_SCRATCHBUF_L2_NOT_AVAILABLE,                                      ///< information scratchbuf l2 not available
  HLA_INFORMATION_SCRATCHBUF_LOCK_FAILED,                                           ///< information scratchbuf lock failed
  HLA_INFORMATION_SCRATCHBUF_UNLOCK_FAILED,                                         ///< information scratchbuf unlock failed
                                                                                    
  HLA_INFORMATION_LAST_ENUM_ENTRY                                                   ///< information last enum entry
} e_ErrorHandling_Information;

 /* Error stack containing all sorts of errors, warnings and information */
typedef struct  
{
  uint32             hashErrors;                                                                        ///< Hash value (\ref HLA_ERROR_HASH_ERRORS) of current definition of error messages.
  uint32             hashWarnings;                                                                      ///< Hash value (\ref HLA_ERROR_HASH_WARNINGS) of current definition of warning messages.
  uint32             hashInformation;                                                                   ///< Hash value (\ref HLA_ERROR_HASH_INFORMATION) of current definition of information messages.
  uint8              numErrors;                                                                         ///< Number of found error messages. \min 0  \max \c HLA_ERROR_LAST_ENUM_ENTRY
  uint8              numWarnings;                                                                       ///< Number of found error messages. \min 0  \max \c HLA_WARNING_LAST_ENUM_ENTRY
  uint8              numInformation;                                                                    ///< Number of found error messages. \min 0  \max \c HLA_INFORMATION_LAST_ENUM_ENTRY
  VDYIoStateTypes_t  busSigStateFlag;                                                                   ///< Signal state of failed VDY bus input signal check used for additional data during DEM event mapping.
  uint16             busSigStateOffset;                                                                 ///< Offset of failed VDY bus input signal to beginning of the VDY request port used for additional data during DEM event mapping. \phys_unit Bytes
  uint32             serviceFunctRetValue;                                                              ///< Return value of failing service functions used for additional data during DEM event mapping.
  uint32             measfreezeAmount;                                                                  ///< Total amount of measfreezed data during one HLA cycle. \phys_unit Bytes
  uint32             errors[HLA_ERROR_HANDLING_ARRAY_SIZE(HLA_ERROR_LAST_ENUM_ENTRY)];                  ///< Bit-field array containing all error messages found during one HLA cycle.
  uint32             warnings[HLA_ERROR_HANDLING_ARRAY_SIZE(HLA_WARNING_LAST_ENUM_ENTRY)];              ///< Bit-field array containing all warning messages found during one HLA cycle.
  uint32             information[HLA_ERROR_HANDLING_ARRAY_SIZE(HLA_INFORMATION_LAST_ENUM_ENTRY)];       ///< Bit-field array containing all information messages found during one HLA cycle.
  uint32             dummy;                                                                             ///< Not used. It's just to make sure that there is no array with only one single element at the end of this struct. Some compilers can treat that as array of flexible lenght. QAC warning #1039 can be avoided by that.
} t_ErrorHandling_ErrorStack;

/* PRQA S 4523 -- */

/****************************************************************************
* GLOBAL FUNCTIONS DECLARATION
*****************************************************************************/
/** ************************************************************************************************
  \brief
    Internal error stack gets initialized. Global errorStack variable is set to zero. Hash values for
    error, warnings and informations are set.
  
  \pre
    None

  \post
    None

  \return
    Void

  \globals
    Input is errorStack variable, which gets set to zero

  \InOutCorrelation
    No input correlations
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_ErrorHandling_Init(void);
/** ************************************************************************************************
  \brief
    Error bit is set in error array of error stack. Calls HLA_ErrorHandling_SetBit() function which
    sets the bit in the error stack
  
  \pre
    None

  \post
    None

  \param [in]  errorBit  Bit that must be set in error array

  \return
    Void

  \globals
    Bit is set in global errorStack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_ErrorHandling_SetError(const e_ErrorHandling_Errors errorBit);
/** ************************************************************************************************
  \brief
    Checks whether errorBit is set in error array of error stack
  
  \pre
    None

  \post
    None

  \param [in]  errorBit  Bit that is checked

  \return
    Boolean if the bit was set (true) or not (false)

  \globals
    Global errorStack variable is checked if bit is set

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
boolean HLA_ErrorHandling_GetError(const e_ErrorHandling_Errors errorBit);
/** ************************************************************************************************
  \brief
    Since we increase number of errors each time a new one is set we can simply return number of
    errors, i.e. set bits in error array.
  
  \pre
    None

  \post
    None

  \return
    Number of error

  \globals
    Number of errors is returned from global errorStack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
uint8 HLA_ErrorHandling_GetNumErrors(void);
/** ************************************************************************************************
  \brief
    Warning bit is set in warning array of error stack. Calls HLA_ErrorHandling_SetBit() function which
    sets the bit in the error stack
  
  \pre
    None

  \post
    None

  \param [in]  warningBit  Bit that must be set in warning array

  \return
    Void

  \globals
    Warning bit is set in global errorStack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_ErrorHandling_SetWarning(const e_ErrorHandling_Warnings warningBit);
/** ************************************************************************************************
  \brief
    Checks whether warningBit is set in error array of error stack
  
  \pre
    None

  \post
    None

  \param [in]  warningBit  Bit that is checked

  \return
    Boolean if the warning bit was set (true) or not (false)

  \globals
    Global errorStack variable is checked if warning bit is set

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
boolean HLA_ErrorHandling_GetWarning(const e_ErrorHandling_Warnings warningBit);
/** ************************************************************************************************
  \brief
    Since we increase number of warnings each time a new one is set we can simply return number of
    warnings, i.e. set bits in warnings array.
  
  \pre
    None

  \post
    None

  \return
    Number of warnings

  \globals
    Number of warnings is returned from global errorStack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
uint8 HLA_ErrorHandling_GetNumWarnings(void);
/** ************************************************************************************************
  \brief
    Information bit is set in information array of error stack. HLA_ErrorHandling_SetBit() function
    is called to check if information bit was set.
  
  \pre
    None

  \post
    Information bit is set

  \param [in]  informationBit  Bit that must be set in information array

  \return
    Void

  \globals
    Bit is set in global errorStack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_ErrorHandling_SetInformation(const e_ErrorHandling_Information informationBit);
/** ************************************************************************************************
  \brief
    Checks whether informationBit is set in error array of error stack

  \pre
    None

  \post
    None

  \param [in]  informationBit  Bit that is checked

  \return
    Boolean if the information bit was set (true) or not (false)

  \globals
    Global errorStack variable is checked if information bit is set

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
#ifdef HLA_QAC_ACTIVE
  #pragma PRQA_NO_SIDE_EFFECTS HLA_ErrorHandling_GetInformation
#endif
boolean HLA_ErrorHandling_GetInformation(const e_ErrorHandling_Information informationBit);
/** ************************************************************************************************
  \brief
    Since we increase number of information each time a new one is set we can simply return number
    of information, i.e. set bits in information array.
  
  \pre
    None

  \post
    None

  \return
    Number of informations

  \globals
    Number of informations is returned from global errorStack variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
uint8 HLA_ErrorHandling_GetNumInformation(void);
/** ************************************************************************************************
  \brief
    Simply returns constant pointer to error stack needed for measfreeze.
  
  \pre
    None

  \post
    None

  \return
    constant pointer to error stack

  \globals
    Pointer to global error stack is returned.
    
  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
const t_ErrorHandling_ErrorStack* HLA_ErrorHandling_GetErrorStack(void);
/** ************************************************************************************************
  \brief
    Store measurement counter from which soft error state persists.\n
    If measCnt is zero soft error state is left.

  \pre
    None

  \post
    None

  \param [in]  measCnt  Measurement counter from which soft error state persists

  \return
    None

  \globals
    Updates softErrorMeasCnt

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_ErrorHandling_SetSoftErrorState(const AlgoCycleCounter_t measCnt);
/** ************************************************************************************************
  \brief
    Returns measurement counter when soft error state was entered. If errorStack.softErrorMeasCnt
    is zero it means that we are currently not in a soft error state.

  \pre
    None

  \post
    None

  \return
    Measurement counter when soft error state was entered else zero.

  \globals
    Returns softErrorMeasCnt

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
AlgoCycleCounter_t HLA_ErrorHandling_GetSoftErrorState(void);
/** ************************************************************************************************
  \brief
    Stores error code of algo service function

  \pre
    None

  \post
    None

  \param [in]  servicesReturnValue  Return code of algo service function

  \return
    None

  \globals
    service retrun value is stored in global error stack

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_ErrorHandling_SetServicesReturnValue(const uint32 servicesReturnValue);
/** ************************************************************************************************
  \brief
    Returns stored return code of algo service function.

  \pre
    None

  \post
    None

  \return
    Stored return code

  \globals
    Returns service return value from global error stack

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
uint32 HLA_ErrorHandling_GetServicesReturnValue(void);
/** ************************************************************************************************
  \brief
    Stores bus signal state flag of corresponding vdy signals 

  \pre
    None

  \post
    None

  \param [in]  stateFlag     State flag of affected bus signal
  \param [in]  structOffset  Offset of this signal compared to beginning of struct

  \return
    None

  \globals
    Sets bus signals in global error variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_ErrorHandling_SetBusSigState( const VDYIoStateTypes_t stateFlag, 
                                       const ptrdiff_t         structOffset
                                      );

/** ************************************************************************************************
  \brief
    Returns bus signal state flag of corresponding vdy signals

  \pre
    None

  \post
    None

  \return
    Stored bus signal state flag

  \globals
    Stores bus state flag in global error variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
uint8 HLA_ErrorHandling_GetBusSigStateFlag(void);
/** ************************************************************************************************
  \brief
    Returns bus signal state offset of corresponding vdy signals

  \pre
    None

  \post
    None

  \return
    Stored bus signal state offset

  \globals
    Stores bus signal state offset in global error variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
uint16 HLA_ErrorHandling_GetBusSigStateOffset(void);
/** ************************************************************************************************
  \brief
    Adds numBytes to internal counter of measfreezed bytes of this cycle.

  \pre
    None

  \post
    None

  \param [in]  numBytes  Number of bytes that shall be counted

  \return
    None

  \globals
    Stores meas freeze amount in global error variable

  \InOutCorrelation
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
void HLA_ErrorHandling_AddMeasfreezeAmount(const uint32 numBytes);

/* avoid cyclic binding ---------------------------------------------------*/
#endif /* #ifndef H_HLA_ERROR_HANDLING_H */
