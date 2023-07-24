/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_cfg.h

DESCRIPTION:               configuration file for MEDIC 

AUTHOR:                    $Author: Veerashettappa, Nagaraja (uidp9076) $

CREATION DATE:             $Date: 2020/12/04 09:27:41CET $

VERSION:                   $Revision: 1.5.15.5 $
**************************************************************************** */
/**
@ingroup frame_medic
@{ **/ 
#ifndef MEDIC_CFG_H_INCLUDED
#define MEDIC_CFG_H_INCLUDED

#include "fct_config.h"
#define MEDIC_ARCHITECTURE_VERSION 0x01  // 0x00-0x09: before FSF.500    0x10+: after FSF.500

#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
#include "algo_glob.h"
#else

#define CFG_MEDIC_OUT_HBA           1
#define CFG_MEDIC_OUT_PREFILL       1
#define CFG_MEDIC_OUT_BRAKE         1 
#define CFG_MEDIC_OUT_WARNING       1
#define CFG_MEDIC_OUT_PRECRASH      1
#define CFG_MEDIC_OUT_DRIVEOFF      1
#define CFG_MEDIC_OUT_ESA           1
#define CFG_MEDIC_OUT_HYP_REACTIONS 1
#define CFG_MEDIC_OUT_QUALIFIERS    1
#define CFG_MEDIC_OUT_FCTDATA       1
#define CFG_MEDIC_OUT_TOYOTA        1
#define CFG_MEDIC_OUT_DIM           1

#include "ga_medic_main.h"
#endif 

#define MEDIC_CFG_DEPENDENT_SWITCH(bool_condition, switch_value) ((bool_condition) && (switch_value))

/* Use C library functions */
#define MEDIC_USE_C_LIB_FUNC                        (SWITCH_ON)

#if (MEDIC_USE_C_LIB_FUNC)
#ifndef __PDO__
#include <string.h>
#endif /* ifndef __PDO__ */
#define MEDIC_MEMSET memset
#define MEDIC_MEMCPY memcpy
#else
#define MEDIC_MEMSET(DEST, VALUE, SIZE) CML_memset_s(DEST, SIZE, VALUE, SIZE)
#define MEDIC_MEMCPY(DEST, SRC  , SIZE) CML_memcpy_s(DEST, SIZE, SRC  , SIZE)
#endif
/*****************************************************************************/
/* MEDIC Configurable Constants                                              */
/*****************************************************************************/

/*!  @brief MEDIC Cycle Time */
#define MEDIC_CYCLE_TIME (0.020f)

/*****************************************************************************/
/* MEDIC Configuration Switches                                              */ 
/*****************************************************************************/

/*!  @brief DIM switch for MEDIC */
#define MEDIC_CFG_DRIVER_INTENTION_MONITORING          MEDIC_CFG_DEPENDENT_SWITCH(FCT_CFG_DRIVER_INTENTION_MONITORING, SWITCH_ON)

/*!  @brief HEAD switch for MEDIC */
#define MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION         MEDIC_CFG_DEPENDENT_SWITCH(FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION, SWITCH_ON)

/*!  @brief EBA switch for MEDIC */
#define MEDIC_CFG_EMERGENCY_BRAKE_ASSIST               MEDIC_CFG_DEPENDENT_SWITCH(FCT_CFG_MEDIC_COMPONENT, SWITCH_ON)

/*!  @brief HEAD Version switch (SWITCH_ON => HEAD 2.0   SWITCH_OFF => HEAD 1.0) */
#define MEDIC_CFG_HEAD20                               (SWITCH_OFF)

/*!  @brief DIM  Version switch (SWITCH_ON => DIM 2.0    SWITCH_OFF => DIM 1.0)  */
#define MEDIC_CFG_DIM20                                (SWITCH_OFF)

/*! @brief Configuration switch for Target Planner  */
#define MEDIC_CFG_TARGET_PLANNER                       (SWITCH_OFF)


/*! @brief Activates the check of the signal headers time stamp of all require ports in the function @ref MEDIC_b_SetupPorts */
#define MEDIC_CFG_USE_ALGO_SIGHEADER_TIMESTAMP_CHECK   (SWITCH_OFF)

/*! @brief Include all interfaces in request/provide port structures, even if the current configuration does not use them. */
#define MEDIC_CFG_INCLUDE_UNUSED_INTF                  (SWITCH_OFF)

/*! @brief Configuration switch to enable usage of the Coding Parameters Port as input to MEDIC */
#define MEDIC_CFG_CPAR_PARAMS                          (SWITCH_ON)

/*! @brief Configuration switch to enable usage of VehSig as input to MEDIC */
#define MEDIC_CFG_VEH_SIG_INPUT                        (SWITCH_ON)

/*! @brief Configuration switch to enabe the AlgoCompstate interface */
#define MEDIC_CFG_USE_ALGOCOMPSTATE                    (SWITCH_OFF)

/*! @brief Configuration switch to enabe error output */
#define MEDIC_CFG_ERROR_OUTPUT_VEH                     (SWITCH_ON)

/*! @brief Configuration switch enables EM-Generic_Object list and disables ObjectList_t */
#define MEDIC_CFG_USE_EM_GENERIC_OBJECT_LIST           (SWITCH_ON)

/*! @brief Configuration switch to enable the generic Signal Header in Interfaces */
#define MEDIC_CFG_USE_SIG_HEADER                       (SWITCH_ON)

/*! @brief Configuration switch for enabling profiling on ECU */
#define MEDIC_CFG_RTA_PROFILING                        (SWITCH_OFF)

/*! @brief Configuration switch to use third parameter in Exec methods to call the Function. Third parameter is a struct to service functions provided by the Frame. */
#define MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS           (SWITCH_OFF)

/*! @brief Configuration switch to activate Measurement Output Code */
#define MEDIC_CFG_MEASUREMENT                          (SWITCH_ON)

/*! @brief Configuration switch to enable sensory type CAMERA */
#define MEDIC_CFG_SENSOR_TYPE_CAMERA                   (SWITCH_OFF)

/*! @brief Activates the checking of input measurement counters */
#define MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING      (SWITCH_OFF)

/*! @brief Switch that enables the Base Control Data struct and disables the OPMode-port */
#define MEDIC_CFG_USE_BASECTRLDATA                     (SWITCH_OFF)

/*! @brief Configuration switch to enable EgoDynRaw */
#define MEDIC_CFG_SHORT_RANGE_FUNCTIONS                (SWITCH_OFF)

/*! @brief Configuration switch enabling mapping of certain parameters from ROM area to RAM in order to allow target calibration (RAM tunable). 0 => ROM,  1 => RAM  memory mapping */
#define MEDIC_CFG_ENABLE_RAM_PARAM                     (SWITCH_ON)

/*! @brief Switch that enables the DEM reporting towards Service Interface (currently NOT available in radar projects) */
#define MEDIC_CFG_USE_DEM                              (SWITCH_OFF)

/*! @brief MEDIC switch to enable the braking decision by second sensor confirmation */
#define MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION          (SWITCH_OFF)

/*! @brief Configuration switch to enable ignoring distance safety check */
#define MEDIC_CFG_EBA_HEAD_IGNR_SFTY_CHECK             (SWITCH_OFF)

/*! @brief Switch to enable setting of Measfreeze Cylce Start Service (currently NOT available in radar projects) */
#define MEDIC_CFG_USE_FREEZE_CYCLE_START               (SWITCH_OFF)

/*! Switches to make local copy of pointer interfaces and use callback measfreeze function. Use this functionality if output pointers are non constant (ringbuffer IPC) */
#define MEDIC_CFG_FREEZE_USE_CALLBACK                  MEDIC_CFG_DEPENDENT_SWITCH(MEDIC_CFG_MEASUREMENT, SWITCH_OFF)

/*! @brief Configuration switch for enabling the check of SigHeaders */
#define MEDIC_CFG_ACTIVATE_SIGHEADER_CHECK             (SWITCH_OFF)

/*! Configuration switch enabling the passing of algo parameters to the MEDIC component. This should be enabled, if the SW environment provides this information */
#define MEDIC_CFG_BSW_ALGO_PARAMS                      (SWITCH_ON)

/*! FCT veh custom input interface */
#define MEDIC_CFG_USE_MEDIC_INTERNAL_MEMORY            (SWITCH_OFF)
#define MEDIC_CFG_CUSTOMINPUT                          (SWITCH_ON)

/*! FCT veh custom output interface */
#define MEDIC_CFG_CUSTOMOUTPUT                         (SWITCH_ON)

#define MEDIC_CFG_ABORT_REASON                         (SWITCH_OFF)
#define MEDIC_CFG_USE_CALCULATED_CYCLETIME             (SWITCH_OFF)
#define MEDIC_CFG_MTS_DATA_IN_INTER_MEAS               (SWITCH_OFF)
#define MEDIC_CFG_DIAGNOSTIC_OUTPUT                    (SWITCH_OFF)
#define MEDIC_CFG_AUTOSAR_WRAPPER                      (SWITCH_OFF)
#define MEDIC_CFG_USE_VDY                              (SWITCH_OFF)

/*! @brief Activate writing DEM output */
#define MEDIC_CFG_ENABLE_DEM_OUTPUT                    (SWITCH_OFF)

/*! @brief driver adaption feature switch*/
#define MEDIC_CFG_ENABLE_DRVR_ADAPTION                 (SWITCH_OFF)
/*! @brief CAM AEB RTE SWITCH */
#define MEDIC_CFG_CAM_AEB                              (SWITCH_OFF)
/*****************************************************************************/
/* MEDIC Port Configuration                                                  */
/*****************************************************************************/

/*! @brief Macro to determine the current number of require ports. Has to be aligned with the structure @ref reqMEDICPrtList_t */
#define MEDIC_NOF_REQ_PORTS	  (   ( (uint8)(0                                            ) )                             \
                                + ( (uint8)(1                                            ) )   /*pVehCtrlData*/          \
                                + ( (uint8)(1                                            ) )   /*pEgoDynRaw*/            \
                                + ( (uint8)(    (MEDIC_CFG_DRIVER_INTENTION_MONITORING)                                  \
                                             || (MEDIC_CFG_INCLUDE_UNUSED_INTF)          ) )   /*pDIMInputGeneric*/      \
                                + ( (uint8)(    (MEDIC_CFG_DRIVER_INTENTION_MONITORING )                                 \
                                             || (MEDIC_CFG_INCLUDE_UNUSED_INTF)          ) )   /*pDIMInputCustom*/       \
                                + ( (uint8)(    (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)                                 \
                                             || (MEDIC_CFG_INCLUDE_UNUSED_INTF)          ) )   /*pFCTCDHypotheses*/      \
                                + ( (uint8)(    (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)                                 \
                                             || (MEDIC_CFG_INCLUDE_UNUSED_INTF)          ) )   /*pHEADInputGeneric*/     \
                                + ( (uint8)(    (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)                                 \
                                             || (MEDIC_CFG_INCLUDE_UNUSED_INTF)          ) )   /*pHEADInputCustom*/      \
                                + ( (uint8)(    (MEDIC_CFG_CPAR_PARAMS)                                                  \
                                             || (MEDIC_CFG_INCLUDE_UNUSED_INTF)          ) )   /*pCPAR_FCT_Parameters*/  \
                                + ( (uint8)(    (MEDIC_CFG_VEH_SIG_INPUT)                                                \
                                             || (MEDIC_CFG_INCLUDE_UNUSED_INTF)          ) )   /*pVehSig*/               \
                                + ( (uint8)(    (MEDIC_CFG_BSW_ALGO_PARAMS)                                              \
                                             || (MEDIC_CFG_INCLUDE_UNUSED_INTF)          ) )   /*pBswAlgoParameters*/    \
                                + ( (uint8)(    (MEDIC_CFG_CUSTOMINPUT)                                                  \
                                             || (MEDIC_CFG_INCLUDE_UNUSED_INTF)          ) ) ) /*pFctVehCustInput*/


/*! @brief Macro to determine the current number of provide ports. Has to be aligned with the structure @ref provMEDICPrtList_t*/
#define MEDIC_NOF_PRO_PORTS  (   ( (uint8)(0                                             ) )                             \
                               + ( (uint8)(MEDIC_CFG_USE_ALGOCOMPSTATE                   ) )   /*pVehCompState*/         \
                               + ( (uint8)(   (MEDIC_CFG_DRIVER_INTENTION_MONITORING)          /*pDIMOutputCustom*/      \
                                           || (MEDIC_CFG_INCLUDE_UNUSED_INTF)            ) )                             \
                               + ( (uint8)(   (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)                                   \
                                           || (MEDIC_CFG_INCLUDE_UNUSED_INTF)            ) )   /*pHEADOutputGeneric*/    \
                               + ( (uint8)(   (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)                                   \
                                           || (MEDIC_CFG_INCLUDE_UNUSED_INTF)            ) )   /*pHEADOutputCustom*/     \
                               + ( (uint8)(MEDIC_CFG_ERROR_OUTPUT_VEH                    ) ) ) /*pErrorOut*/


#endif /* MEDIC_CFG_H_INCLUDED */
/**@}*/

