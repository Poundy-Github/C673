/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SwcDemSc.c
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *     SW-C Type:  SwcDemSc
 *  Generated at:  Wed May 25 10:07:59 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  C-Code implementation template for SW-C <SwcDemSc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  ------------------------------------------------------------------------------------------------------------------- */

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Bernd Jesse                   Js            Vector Informatik GmbH
 *  Patricia Speidel              Pst           Vector Informatik GmbH
 *  Stefan Huebner                Hrs           Vector Informatik GmbH
 *  Thomas Necker                 Tne           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2008-10-13  Js      ESCAN00031326 Initial Version
 *  02.00.00  2008-11-14  Js      ESCAN00031330 Change interface names because of SHORT-NAME limitation
 *                                ESCAN00031331 SC6 removed
 *  02.01.00  2008-12-17  Js      ESCAN00032141 Rename port prototype IndicatorStatus
 *                                ESCAN00032142 Invalid handling for SC 3 and SC 4 after power on
 *  03.00.00  2009-01-14  Js      ESCAN00032337 SC5 removed
 *                                ESCAN00032391 Bus Signal Receiver Port type modified
 *                                              from Signal type to Signal Group type
 *  03.00.01  2009-01-20  Js      ESCAN00032471 SWC data mapping not possible
 *  04.00.00  2009-07-08  Pst     ESCAN00035220 Implement SC5 (Transportation Mode)
 *                                ESCAN00036228 DemSc is extended to set the operation cycle for ignition.
 *                                ESCAN00036159 Compiler warning "expression without effect"
 *                                  -           MISRA improvements
 *            2009-07-21  Hrs       -           Replace unions by simple datatypes and bit access (via macro)
 *  05.00.00  2009-11-18  Pst       -           Updated interfaces according system description of Daimler
 *                                  -           Changed ExternalTesterPresentStatus interface to bus signal
 *  05.00.01  2010-02-22  Pst       -           Updated signal group type SwcDemSc_IgnStat_GrpType according system 
 *                                              description of Daimler
 *  05.00.02  2010-03-02  Pst       -           Updated usage of compiler abstraction
 *  05.00.04  2010-03-18  Pst     ESCAN00041442 Avoid 'redefinition' warning caused by SWCDEMSC_STAT_SC_INACTIVE and 
 *                                              SWCDEMSC_STAT_SC_ACTIVE redefinition
 *                                  -           Harmonize format of justification for MISRA violations to support CDK
 *                                  -           Rework of macros to avoid compiler warnings
 *                                  -           Updated comments according system description of Daimler
 *  05.01.00  2010-08-13  Tne     ESCAN00044350 Timeout values for Ignition Cycle and SC1 are made configurable by user
 *  05.02.00  2010-10-21  Tne     ESCAN00045808 Use extended record data type compatibility for S/R communication
 *                        Tne     ESCAN00045825 Local Voltage Storage Condition thresholds are made configurable by user
 *  05.03.00  2010-11-17  Tne     ESCAN00046841 Use last know Odometer when Bus Failed was missing
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Port Prototypes:
 ================
  SwcDemSc_SysExtTester
    DidA Externer Tester erkannt

  SwcDemSc_SysIgnition
    Zuendungsstatus

  SwcDemSc_SysOdometer
    Kilometerstand (fuer alle, FFFFFEh: Signal ungueltig)

  SwcDemSc_SysTransportationMode
    Bordnetz Status Transportmodus

  SwcDemSc_SysVehicleEngineStartup
    Motoransprechverhalten Engine Control

  SwcDemSc_SysVoltage
    Bordnetz 14V Status Verbraucherbatterie


 Data Element Prototypes:
 ========================
  DidA_ExtTest_Pres of Port Interface SwcDemSc_SysExtTester
    DidA Externer Tester erkannt

  Odo of Port Interface SwcDemSc_SysOdometer
    Kilometerstand (fuer alle, FFFFFEh: Signal ungueltig)

  PN14_TransMd_Stat of Port Interface SwcDemSc_SysTransportationMode
    Bordnetz Status Transportmodus anzeigen

  Eng_Rs_EngCtrl of Port Interface SwcDemSc_SysVehicleEngineStartup
    Motoransprechverhalten Engine Control

  PN14_SupBat_Stat of Port Interface SwcDemSc_SysVoltage
    Bordnetz 14V Status Verbraucherbatterie

 *********************************************************************************************************************/

#include "Rte_SwcDemSc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "SwcDemSc.h"
#include "SwcDemScCfg.h"

#include "NvM_User.h"
#include "Dem.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Vendor specific version information is BCD coded */
#if ((DIAG_ASRSWCDEMSC_DAIMLER_VERSION         != 0x0503u)|| \
     (DIAG_ASRSWCDEMSC_DAIMLER_RELEASE_VERSION != 0x00u  )  )
# error "Vendor specific version numbers of SwcDemSc.c and SwcDemSc.h are inconsistent"
#endif

/* we're only interested in the correct data format version */
#if (SWCDEMSC_CFG_DATAFORMAT_VERSION != (0x02u) )
#  error "Data Format version numbers of SwcDemSc.c and SwcDemScCfg.h are inconsistent!"
#endif

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* SwcDemSc version */
CONST(uint8, RTE_CONST) SwcDemSc_MainVersion    = SWCDEMSC_SW_MAJOR_VERSION;   /* PRQA S 0850 *//* MD_MSR_19.8 */
CONST(uint8, RTE_CONST) SwcDemSc_SubVersion     = SWCDEMSC_SW_MINOR_VERSION;   /* PRQA S 0850 *//* MD_MSR_19.8 */
CONST(uint8, RTE_CONST) SwcDemSc_ReleaseVersion = SWCDEMSC_SW_PATCH_VERSION;   /* PRQA S 0850 *//* MD_MSR_19.8 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_19.1 */


/*** Local macro definitions ***/
/** Bit access macros */
/* read a single bit */
#define SWCDEMSC_READ_BIT(varType, var, bitNo)          ((((varType)((var) & (varType)(1u << (uint8)(bitNo)))) == 0) ? 0 : 1)      /* PRQA S 3453 *//* MD_MSR_19.7 */
/* internal bit access (no assignment) */
#define SWCDEMSC_SET_BIT(varType, var, bitNo)           ((varType)((var) | (1u << (uint8)(bitNo))))                                /* PRQA S 3453 *//* MD_MSR_19.7 */
#define SWCDEMSC_UNSET_BIT(varType, var, bitNo)         ((varType)((var) & (varType)(~(varType)(1u << (uint8)(bitNo)))))           /* PRQA S 3453 *//* MD_MSR_19.7 */
/* write a single bit */
#define SWCDEMSC_WRITE_BIT(varType, var, bitNo, value)  (var) = (varType)(((value)==0) ? SWCDEMSC_UNSET_BIT(varType, (var), (uint8)(bitNo)) : SWCDEMSC_SET_BIT(varType, (var), (uint8)(bitNo)))   /* PRQA S 3410, 3453 *//* MD_SWCDEMSC_19.10, MD_SWCDEMSC_19.7 */


/*** Failure Level evaluation ***/

enum SwcDemSc_locFlEnumTag
{
     SwcDemSc_SC1_CurCtrlDTCSetting       =  0  /* Bit  0 */
    ,SwcDemSc_SC2_CurIgStatus             =  1  /* Bit  1 */
    ,SwcDemSc_SC3_CurLocVoltStatus        =  2  /* Bit  2 */
    ,SwcDemSc_SC4_CurSysVoltStatus        =  3  /* Bit  3 */
    ,SwcDemSc_SC5_CurTransModeStatus      =  4  /* Bit  4 */
/*  ,reserved_5                           =  5     Bit  5 */
/*  ,reserved_6                           =  6     Bit  6 */
    ,SwcDemSc_SC8_CurPhysBusStatus        =  7  /* Bit  7 */
    ,SwcDemSc_SC9_CurIoDevConfStatus      =  8  /* Bit  8 */
    ,SwcDemSc_SC10_DebounceTimer          =  9  /* Bit  9 */
    ,SwcDemSc_SC11_CurVehEngStartupStatus = 10  /* Bit 10 */
/*  ,reserved_11                          = 11     Bit 11 */
/*  ,reserved_12                          = 12     Bit 12 */
/*  ,reserved_13                          = 13     Bit 13 */
/*  ,reserved_14                          = 14     Bit 14 */
/*  ,reserved_15                          = 15     Bit 15 */
};

typedef uint16 SwcDemSc_locFlType;

/*** Storage Condition evaluation ***/

enum SwcDemSc_locScSigIndEnumTag
{
/*   reserved_1                  = 0     Bit  0 */
     SwcDemSc_Voltage            = 1  /* Bit  1 */
    ,SwcDemSc_TransportationMode = 2  /* Bit  2 */
/*  ,reserved_3                  = 3     Bit  3 */
/*  ,reserved_4                  = 4     Bit  4 */
/*  ,reserved_5                  = 5     Bit  5 */
/*  ,reserved_6                  = 6     Bit  6 */
/*  ,reserved_7                  = 7     Bit  7 */
};


/*** Local self defined makros ***/

/*** Configuration dependent makros ***/

#define SWCDEMSC_VAL_SYS_VOLT_MIN    ((c08_V_0_25k4_0k1) 90)
#define SWCDEMSC_VAL_SYS_VOLT_MAX    ((c08_V_0_25k4_0k1)160)

/* check local voltage threshold configuration
  (check c08_V_0_25k4_0k1_LowerLimit, c08_V_0_25k4_0k1_UpperLimit, Rte_InvalidValue_c08_V_0_25k4_0k1) */
#if (  !( SWCDEMSC_VAL_LOC_VOLT_MIN >=   0 ) \
    || !( SWCDEMSC_VAL_LOC_VOLT_MIN <  255 ) )
# error "SC3 - configured local voltage minimum threshold not allowed!"
#endif
#if (  !( SWCDEMSC_VAL_LOC_VOLT_MAX >=   0 ) \
    || !( SWCDEMSC_VAL_LOC_VOLT_MAX <  255 ) )
# error "SC3 - configured local voltage maximum threshold not allowed!"
#endif
#if ( SWCDEMSC_VAL_LOC_VOLT_MIN > SWCDEMSC_VAL_LOC_VOLT_MAX )
# error "SC3 - configured local voltage minimum threshold greater than configured maximum threshold!"
#endif

#define SWCDEMSC_VAL_SC_DEB_TIM_INIT 0

/* make sure the debounce timers can be at least decremented once before expiration */
#if !( SWCDEMSC_VAL_SC_DEB_TIM_MAX > SWCDEMSC_VAL_SC_DEB_TIM_INIT )
# error "SC10 debounce timer must be larger than 0!"
#endif
#if !( SWCDEMSC_VAL_IG_DEB_TIM_MAX > SWCDEMSC_VAL_SC_DEB_TIM_INIT )
# error "Ignition cycle debounce timer must be larger than 0!"
#endif

/*** Failure Level evaluation ***/

#define SWCDEMSC_STAT_LOC_FL_INACTIVE               (0u)
#define SWCDEMSC_STAT_LOC_FL_ACTIVE                 (1u)

#define ReadLocalFailureLevel()                     (flCondition)
#define WriteLocalFailureLevel(a)                   (flCondition = (a))                                                                              /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Write_Local_SC1_CurCtrlDTCSetting(a)        SWCDEMSC_WRITE_BIT(SwcDemSc_locFlType, flCondition, SwcDemSc_SC1_CurCtrlDTCSetting, (a))         /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Write_Local_SC2_CurIgStatus(a)              SWCDEMSC_WRITE_BIT(SwcDemSc_locFlType, flCondition, SwcDemSc_SC2_CurIgStatus, (a))               /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Write_Local_SC3_CurLocVoltStatus(a)         SWCDEMSC_WRITE_BIT(SwcDemSc_locFlType, flCondition, SwcDemSc_SC3_CurLocVoltStatus, (a))          /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Write_Local_SC4_CurSysVoltStatus(a)         SWCDEMSC_WRITE_BIT(SwcDemSc_locFlType, flCondition, SwcDemSc_SC4_CurSysVoltStatus, (a))          /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Write_Local_SC5_CurTransModeStatus(a)       SWCDEMSC_WRITE_BIT(SwcDemSc_locFlType, flCondition, SwcDemSc_SC5_CurTransModeStatus, (a))        /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Write_Local_SC8_CurPhysBusStatus(a)         SWCDEMSC_WRITE_BIT(SwcDemSc_locFlType, flCondition, SwcDemSc_SC8_CurPhysBusStatus, (a))          /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Write_Local_SC9_CurIoDevConfStatus(a)       SWCDEMSC_WRITE_BIT(SwcDemSc_locFlType, flCondition, SwcDemSc_SC9_CurIoDevConfStatus, (a))        /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Read_Local_SC10_DebounceTimer()             SWCDEMSC_READ_BIT( SwcDemSc_locFlType, flCondition, SwcDemSc_SC10_DebounceTimer)
#define Write_Local_SC10_DebounceTimer(a)           SWCDEMSC_WRITE_BIT(SwcDemSc_locFlType, flCondition, SwcDemSc_SC10_DebounceTimer, (a))            /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Write_Local_SC11_CurVehEngStartupStatus(a)  SWCDEMSC_WRITE_BIT(SwcDemSc_locFlType, flCondition, SwcDemSc_SC11_CurVehEngStartupStatus, (a))   /* PRQA S 3453 *//* MD_MSR_19.7 */

/*** Storage Condition evaluation ***/

/* Check wether SWCDEMSC_STAT_SC_INACTIVE and/or SWCDEMSC_STAT_SC_ACTIVE are already defined differently in Rte_Type (up to R7 or V2.12 of RTE generator) */
#if defined (SWCDEMSC_STAT_SC_INACTIVE)
# if RTE_CONST_SWCDEMSC_STAT_SC_INACTIVE != 0u
#   error "Constant value <SWCDEMSC_STAT_SC_INACTIVE> conflicts with another constant. Please update your RTE generator (at least version 2.13)."
# endif
#else
# define SWCDEMSC_STAT_SC_INACTIVE                   ((SwcDemSc_ScStatusType)0u)
#endif

#if defined (SWCDEMSC_STAT_SC_ACTIVE)
# if RTE_CONST_SWCDEMSC_STAT_SC_ACTIVE != 1u
#   error "Constant value <SWCDEMSC_STAT_SC_ACTIVE> conflicts with another constant. Please update your RTE generator (at least version 2.13)."
# endif
#else
# define SWCDEMSC_STAT_SC_ACTIVE                     ((SwcDemSc_ScStatusType)1u)
#endif

#define SWCDEMSC_STAT_LOC_SIG_IND_CLEARED           (0u)
#define SWCDEMSC_STAT_LOC_SIG_IND_SET               (1u)

#define ReadLocalScSigInd()                         (scLocSigInd)
#define WriteLocalScSigInd(a)                       (scLocSigInd = (a))                                                                           /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Read_Local_ScSigInd_Voltage()               SWCDEMSC_READ_BIT( SwcDemSc_glbScSigIndType, scLocSigInd, SwcDemSc_Voltage)
#define Write_Local_ScSigInd_Voltage(a)             SWCDEMSC_WRITE_BIT(SwcDemSc_glbScSigIndType, scLocSigInd, SwcDemSc_Voltage, (a))              /* PRQA S 3453 *//* MD_MSR_19.7 */
#define Read_Local_ScSigInd_TransportationMode()    SWCDEMSC_READ_BIT( SwcDemSc_glbScSigIndType, scLocSigInd, SwcDemSc_TransportationMode)
#define Write_Local_ScSigInd_TransportationMode(a)  SWCDEMSC_WRITE_BIT(SwcDemSc_glbScSigIndType, scLocSigInd, SwcDemSc_TransportationMode, (a))   /* PRQA S 3453 *//* MD_MSR_19.7 */

static void SwcDemSc_HandleSysVoltMontoring(c08_V_0_25k4_0k1 CurSysVoltage);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * DC_BOOL: Boolean
 * Dem_DTCStatusMaskType: Integer in interval [0...255]
 * Dem_DTCType: Integer in interval [0...4294967295]
 * SwcDemSc_DebTimType: Integer in interval [0...65535]
 * SwcDemSc_ScStatusType: Boolean
 * SwcDemSc_glbScSigIndType: Integer in interval [0...255]
 * UInt32: Integer in interval [0...4294967295] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dem_DTCKindType: Enumeration of integer in interval [1...2] with enumerators
 *   DEM_DTC_KIND_ALL_DTCS (1u)
 *   DEM_DTC_KIND_EMISSION_REL_DTCS (2u)
 * Dem_IndicatorStatusType: Enumeration of integer in interval [0...3] with enumerators
 *   DEM_INDICATOR_OFF (0u)
 *   DEM_INDICATOR_CONTINUOUS (1u)
 *   DEM_INDICATOR_BLINKING (2u)
 *   DEM_INDICATOR_BLINK_CONT (3u)
 * Dem_OperationCycleStateType: Enumeration of integer in interval [1...2] with enumerators
 *   DEM_CYCLE_STATE_START (1u)
 *   DEM_CYCLE_STATE_END (2u)
 * SwcDemSc_FlReportType: Enumeration of integer in interval [0...255] with enumerators
 *   SWCDEMSC_STAT_FL_REPORT_CYCLIC (0u)
 *   SWCDEMSC_STAT_FL_REPORT_EVENT (1u)
 *   SWCDEMSC_STAT_FL_REPORT_INVALID (255u)
 * SwcDemSc_StdReturnType: Enumeration of integer in interval [0...255] with enumerators
 *   SWCDEMSC_E_OK (0u)
 *   SWCDEMSC_E_NOT_OK (1u)
 *   SWCDEMSC_E_INVALID (255u)
 * c02_TransMd_Stat: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_TRANSMD_STAT_OFF (0u)
 *   I_C02_TRANSMD_STAT_TEMP_OFF (1u)
 *   I_C02_TRANSMD_STAT_ACTV (2u)
 *   I_C02_TRANSMD_STAT_SNA (3u)
 * c03_EngRun_Stat: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ENGRUN_STAT_STOP (0u)
 *   I_C03_ENGRUN_STAT_START (1u)
 *   I_C03_ENGRUN_STAT_IDLE_UNSTBL (2u)
 *   I_C03_ENGRUN_STAT_IDLE_STBL (3u)
 *   I_C03_ENGRUN_STAT_UNLIMITED (4u)
 *   I_C03_ENGRUN_STAT_LIMITED (5u)
 *   I_C03_ENGRUN_STAT_NDEF6 (6u)
 *   I_C03_ENGRUN_STAT_SNA (7u)
 * c03_ISw_Stat: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ISW_STAT_IGN_LOCK (0u)
 *   I_C03_ISW_STAT_IGN_OFF (1u)
 *   I_C03_ISW_STAT_IGN_ACC (2u)
 *   I_C03_ISW_STAT_IGN_ON (4u)
 *   I_C03_ISW_STAT_IGN_START (5u)
 *   I_C03_ISW_STAT_SNA (7u)
 * c08_V_0_25k4_0k1: Enumeration of integer in interval [0...255] with enumerators
 *   I_C08_V_0_25K4_0K1_SNA (255u)
 * c24_km_0_999999k9_0k1: Enumeration of integer in interval [0...16777215] with enumerators
 *   I_C24_KM_0_999999K9_0K1_SNA (16777215u)
 *
 * Record Types:
 * =============
 * SwcDemSc_EngRsEngCtrl_GrpType: Record with elements
 *   EngRun_Stat of type c03_EngRun_Stat
 * SwcDemSc_IgnStat_GrpType: Record with elements
 *   ISw_Stat of type c03_ISw_Stat
 * SwcDemSc_PN14SupBatStat_GrpType: Record with elements
 *   PN14_SupBat_Volt of type c08_V_0_25k4_0k1
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SWCDEMSC_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CallbackControlDTCStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ControlDTCStatusChanged> of PortPrototype <CBControlDTCStatus>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_CallbackControlDTCStatus_SC1_CurDemCtrlDTCSetting(SwcDemSc_ScStatusType data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SwcDemSc_CallbackControlDTCStatus(Boolean status)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackControlDTCStatus_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_CallbackControlDTCStatus(Boolean status)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_CallbackControlDTCStatus (returns application error)
 *********************************************************************************************************************/

  Rte_IrvWrite_CallbackControlDTCStatus_SC1_CurDemCtrlDTCSetting((SwcDemSc_ScStatusType)!status);  /*
                                                                      inverse status to internal evaluation:
                                                                      FALSE = storing prohibited
                                                                      TRUE  = storing permitted
                                                                      */

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CallbackDTCStatusChange
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DTCStatusChanged> of PortPrototype <CBStatusDTC_SC8>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_CallbackDTCStatusChange_SC8_CurDemIndicatorStatus(SwcDemSc_ScStatusType data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_IndStatus_DEM_IND_SC8_RELEVANT_GetIndicatorStatus(Dem_IndicatorStatusType *IndicatorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IndicatorStatus_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SwcDemSc_CallbackDTCStatusChange(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackDTCStatusChange_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_CallbackDTCStatusChange(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_CallbackDTCStatusChange (returns application error)
 *********************************************************************************************************************/

  Dem_IndicatorStatusType IndicatorStatus = DEM_INDICATOR_OFF;

  SWCDEMSC_IGNORE_UNUSED_ARG(DTC);            /* PRQA S 3112 *//* MD_SWCDEMSC_14.2 */
  SWCDEMSC_IGNORE_UNUSED_ARG(DTCKind);        /* PRQA S 3112 *//* MD_SWCDEMSC_14.2 */
  SWCDEMSC_IGNORE_UNUSED_ARG(DTCStatusOld);   /* PRQA S 3112 *//* MD_SWCDEMSC_14.2 */
  SWCDEMSC_IGNORE_UNUSED_ARG(DTCStatusNew);   /* PRQA S 3112 *//* MD_SWCDEMSC_14.2 */


  if(Rte_Call_IndStatus_DEM_IND_SC8_RELEVANT_GetIndicatorStatus(0, &IndicatorStatus) == RTE_E_OK)
  {
    /* Indicator valid, use value */
    if(IndicatorStatus == DEM_INDICATOR_OFF)
    {
      Rte_IrvWrite_CallbackDTCStatusChange_SC8_CurDemIndicatorStatus(SWCDEMSC_STAT_SC_INACTIVE);
    }
    else
    {
      Rte_IrvWrite_CallbackDTCStatusChange_SC8_CurDemIndicatorStatus(SWCDEMSC_STAT_SC_ACTIVE);
    }
  }
  else
  {
    /* Indicator invalid, switch back to default */
    Rte_IrvWrite_CallbackDTCStatusChange_SC8_CurDemIndicatorStatus(SWCDEMSC_STAT_SC_INACTIVE);
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CheckStorageConditions
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SwcDemSc_LocIoDevice_Io_Stat(SwcDemSc_StdReturnType *data)
 *   Std_ReturnType Rte_Read_SwcDemSc_LocVoltage_SupBat_Volt(c08_V_0_25k4_0k1 *data)
 *   Std_ReturnType Rte_Read_SwcDemSc_SysTransportationMode_PN14_TransMd_Stat(c02_TransMd_Stat *data)
 *   Std_ReturnType Rte_Read_SwcDemSc_SysVehicleEngineStartup_Eng_Rs_EngCtrl(SwcDemSc_EngRsEngCtrl_GrpType *data)
 *   Std_ReturnType Rte_Read_SwcDemSc_SysVoltage_PN14_SupBat_Stat(SwcDemSc_PN14SupBatStat_GrpType *data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   SwcDemSc_ScStatusType Rte_IrvRead_CheckStorageConditions_SC1_CurDemCtrlDTCSetting(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_CheckStorageConditions_SC8_CurDemIndicatorStatus(void)
 *   c03_ISw_Stat Rte_IrvRead_CheckStorageConditions_glbCurSig_Ignition(void)
 *   SwcDemSc_glbScSigIndType Rte_IrvRead_CheckStorageConditions_glbScSigInd(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_CheckStorageConditions_SC11_CurVehEngStartupStatus(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_CheckStorageConditions_SC1_CurCtrlDTCSetting(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_CheckStorageConditions_SC2_CurIgStatus(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_CheckStorageConditions_SC3_CurLocVoltStatus(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_CheckStorageConditions_SC4_CurSysVoltStatus(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_CheckStorageConditions_SC5_CurTransModeStatus(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_CheckStorageConditions_SC8_CurPhysBusStatus(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_CheckStorageConditions_SC9_CurIoDevConfStatus(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_CheckStorageConditions_glbScSigInd(SwcDemSc_glbScSigIndType data)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_CheckStorageConditions(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_CheckStorageConditions
 *********************************************************************************************************************/

  SwcDemSc_glbScSigIndType scLocSigInd;  /*
                                           Local signal indication buffer, read from global buffer at the beginning,
                                           write to the global buffer at the end.
                                         */

  WriteLocalScSigInd(Rte_IrvRead_CheckStorageConditions_glbScSigInd()); /* Get current indication status */

  {
    /*** Evaluate SC1_CurCtrlDTCSetting ***/

    Rte_IrvWrite_CheckStorageConditions_SC1_CurCtrlDTCSetting(Rte_IrvRead_CheckStorageConditions_SC1_CurDemCtrlDTCSetting());
  }

  {
    c03_ISw_Stat           curIgStatus = Rte_IrvRead_CheckStorageConditions_glbCurSig_Ignition();

    /*** Evaluate SC2_CurIgStatus ***/

    if(curIgStatus != I_C03_ISW_STAT_IGN_ON)
    {
      /* curIgStatus != RUN */
      Rte_IrvWrite_CheckStorageConditions_SC2_CurIgStatus(SWCDEMSC_STAT_SC_ACTIVE);
    }
    else
    {
      /* curIgStatus = RUN */
      Rte_IrvWrite_CheckStorageConditions_SC2_CurIgStatus(SWCDEMSC_STAT_SC_INACTIVE);
    }
  }

  {
    c08_V_0_25k4_0k1                  locVoltValue = Rte_InitValue_SwcDemSc_LocVoltage_SupBat_Volt;       /* PRQA S 3197 *//* MD_SWCDEMSC_3197 */
    c08_V_0_25k4_0k1                  sysVoltValue = SWCDEMSC_GRPINIT_PN14SupBatStat.PN14_SupBat_Volt;    /* PRQA S 3197 *//* MD_SWCDEMSC_3197 */
    SwcDemSc_PN14SupBatStat_GrpType   sysVoltValueGrp;

    (void)Rte_Read_SwcDemSc_LocVoltage_SupBat_Volt(&locVoltValue);     /* PRQA S 3417, 3426 *//* MD_SWCDEMSC_12.10, MD_SWCDEMSC_14.2 */

    if(Rte_Read_SwcDemSc_SysVoltage_PN14_SupBat_Stat(&sysVoltValueGrp) != RTE_E_OK)
    {
      /*
        Timeout(RTE_E_MAX_AGE_EXCEEDED) or any other read issue possible.
        Set signal back to the init value to detect bus communication failed.
        There is no need to configure the COM to copy any default value in case of an timeout,
        but the timeout function must be configured:
                                                    Rte_COMCbk_<SIGNAL>()     to reset timeout flag
                                                    Rte_COMCbkTOut_<SIGNAL>() to   set timeout flag
      */
      sysVoltValue = SWCDEMSC_GRPINIT_PN14SupBatStat.PN14_SupBat_Volt;
    }
    else
    {
      sysVoltValue = sysVoltValueGrp.PN14_SupBat_Volt;
    }

    /*** Evaluate SC3_CurLocVoltStatus ***/

    if(locVoltValue != Rte_InitValue_SwcDemSc_LocVoltage_SupBat_Volt)
    {
      Write_Local_ScSigInd_Voltage(SWCDEMSC_STAT_LOC_SIG_IND_SET);  /* Voltage (Local) valid received */                             /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */

      /* locVoltValue available */
      if((((c08_V_0_25k4_0k1)SWCDEMSC_VAL_LOC_VOLT_MIN) <= locVoltValue) && (locVoltValue <= ((c08_V_0_25k4_0k1)SWCDEMSC_VAL_LOC_VOLT_MAX)))
      {
        /* locVoltValue valid */
        Rte_IrvWrite_CheckStorageConditions_SC3_CurLocVoltStatus(SWCDEMSC_STAT_SC_INACTIVE);
      }
      else
      {
        /* locVoltValue invalid / out of range */
        Rte_IrvWrite_CheckStorageConditions_SC3_CurLocVoltStatus(SWCDEMSC_STAT_SC_ACTIVE);
      }
    }
    else if(sysVoltValue != SWCDEMSC_GRPINIT_PN14SupBatStat.PN14_SupBat_Volt)
    {
      /* sysVoltValue available */
      if((SWCDEMSC_VAL_SYS_VOLT_MIN <= sysVoltValue) && (sysVoltValue <= SWCDEMSC_VAL_SYS_VOLT_MAX))
      {
        /* sysVoltValue valid */
        Rte_IrvWrite_CheckStorageConditions_SC3_CurLocVoltStatus(SWCDEMSC_STAT_SC_INACTIVE);
      }
      else
      {
        /* sysVoltValue invalid / out of range */
        Rte_IrvWrite_CheckStorageConditions_SC3_CurLocVoltStatus(SWCDEMSC_STAT_SC_ACTIVE);
      }
    }
    else
    {
      /* Neither locVoltValue nor sysVoltValue available */
      if(Read_Local_ScSigInd_Voltage() == SWCDEMSC_STAT_LOC_SIG_IND_CLEARED)
      {
        /* Set default */
        Rte_IrvWrite_CheckStorageConditions_SC3_CurLocVoltStatus(SWCDEMSC_STAT_SC_ACTIVE);
      }
      /*
      else: Signal at least once valid - bus communication failed - keep old SC
      */
    }

    /*** Evaluate SC4_CurSysVoltStatus ***/

    if(sysVoltValue != SWCDEMSC_GRPINIT_PN14SupBatStat.PN14_SupBat_Volt)
    {
      Write_Local_ScSigInd_Voltage(SWCDEMSC_STAT_LOC_SIG_IND_SET);  /* Voltage (System) valid received */                            /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */

      /* sysVoltValue available */
      if((SWCDEMSC_VAL_SYS_VOLT_MIN <= sysVoltValue) && (sysVoltValue <= SWCDEMSC_VAL_SYS_VOLT_MAX))
      {
        /* sysVoltValue valid */
        Rte_IrvWrite_CheckStorageConditions_SC4_CurSysVoltStatus(SWCDEMSC_STAT_SC_INACTIVE);
      }
      else
      {
        /* sysVoltValue invalid / out of range */
        Rte_IrvWrite_CheckStorageConditions_SC4_CurSysVoltStatus(SWCDEMSC_STAT_SC_ACTIVE);
      }
    }
    else if(locVoltValue != Rte_InitValue_SwcDemSc_LocVoltage_SupBat_Volt)
    {
      /* locVoltValue available */
      if((((c08_V_0_25k4_0k1)SWCDEMSC_VAL_LOC_VOLT_MIN) <= locVoltValue) && (locVoltValue <= ((c08_V_0_25k4_0k1)SWCDEMSC_VAL_LOC_VOLT_MAX)))
      {
        /* locVoltValue valid */
        Rte_IrvWrite_CheckStorageConditions_SC4_CurSysVoltStatus(SWCDEMSC_STAT_SC_INACTIVE);
      }
      else
      {
        /* locVoltValue invalid / out of range */
        Rte_IrvWrite_CheckStorageConditions_SC4_CurSysVoltStatus(SWCDEMSC_STAT_SC_ACTIVE);
      }
    }
    else
    {
      /* Neither sysVoltValue nor locVoltValue available */
      if(Read_Local_ScSigInd_Voltage() == SWCDEMSC_STAT_LOC_SIG_IND_CLEARED)
      {
        /* Set default */
        Rte_IrvWrite_CheckStorageConditions_SC4_CurSysVoltStatus(SWCDEMSC_STAT_SC_ACTIVE);
      }
      /*
      else: Signal at least once valid - bus communication failed - keep old SC
      */
    }

    /* Monitor for the Over-/UnderVoltage-DTCs; */
    SwcDemSc_HandleSysVoltMontoring(sysVoltValue);
  }

  {
    c02_TransMd_Stat  sysTransModeStatus = Rte_InitValue_SwcDemSc_SysTransportationMode_PN14_TransMd_Stat;

    if(Rte_Read_SwcDemSc_SysTransportationMode_PN14_TransMd_Stat(&sysTransModeStatus) != RTE_E_OK)
    {
      /*
        Timeout(RTE_E_MAX_AGE_EXCEEDED) or any other read issue possible.
        Set signal back to the init value to detect bus communication failed.
        There is no need to configure the COM to copy any default value in case of an timeout,
        but the timeout function must be configured:
                                                    Rte_COMCbk_<SIGNAL>()     to reset timeout flag
                                                    Rte_COMCbkTOut_<SIGNAL>() to   set timeout flag
      */
      sysTransModeStatus = Rte_InitValue_SwcDemSc_SysTransportationMode_PN14_TransMd_Stat;
    }
    /*
    else: Signal is already read - keep its value
    */

    /*** Evaluate SC5_CurTransModeStatus ***/

    if(sysTransModeStatus != Rte_InitValue_SwcDemSc_SysTransportationMode_PN14_TransMd_Stat)
    {
      Write_Local_ScSigInd_TransportationMode(SWCDEMSC_STAT_LOC_SIG_IND_SET);  /* TransportationMode (System) valid received */      /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */

      /* sysTransModeStatus available */
      if(sysTransModeStatus != I_C02_TRANSMD_STAT_ACTV)
      {
        Rte_IrvWrite_CheckStorageConditions_SC5_CurTransModeStatus(SWCDEMSC_STAT_SC_INACTIVE);
      }
      else
      {
        /* sysTransModeStatus active */
        Rte_IrvWrite_CheckStorageConditions_SC5_CurTransModeStatus(SWCDEMSC_STAT_SC_ACTIVE);
      }

    }
    else
    {
      /* sysTransModeStatus not available */
      if(Read_Local_ScSigInd_TransportationMode() == SWCDEMSC_STAT_LOC_SIG_IND_CLEARED)
      {
        /* Set default */
        Rte_IrvWrite_CheckStorageConditions_SC5_CurTransModeStatus(SWCDEMSC_STAT_SC_INACTIVE);
      }
      /*
      else: Signal at least once valid - bus communication failed - keep old SC
      */
    }
  }

  {
    /*** Evaluate SC8_CurPhysBusStatus ***/

    Rte_IrvWrite_CheckStorageConditions_SC8_CurPhysBusStatus(Rte_IrvRead_CheckStorageConditions_SC8_CurDemIndicatorStatus());
  }

  {
    SwcDemSc_StdReturnType locIoDeviceStatus = Rte_InitValue_SwcDemSc_LocIoDevice_Io_Stat;     /* PRQA S 3197 *//* MD_SWCDEMSC_3197 */

    (void)Rte_Read_SwcDemSc_LocIoDevice_Io_Stat(&locIoDeviceStatus);                           /* PRQA S 3417, 3426 *//* MD_SWCDEMSC_12.10, MD_SWCDEMSC_14.2 */

    /*** Evaluate SC9_CurIoDevConfStatus ***/

    if(locIoDeviceStatus != SWCDEMSC_E_OK)
    {
      /* Error in configuration */
      Rte_IrvWrite_CheckStorageConditions_SC9_CurIoDevConfStatus(SWCDEMSC_STAT_SC_ACTIVE);
    }
    else
    {
      /* No error or not configured */
      Rte_IrvWrite_CheckStorageConditions_SC9_CurIoDevConfStatus(SWCDEMSC_STAT_SC_INACTIVE);
    }
  }

  {
    c03_EngRun_Stat                 sysVehEngStartupStatus = SWCDEMSC_GRPINIT_EngRsEngCtrl.EngRun_Stat;   /* PRQA S 3197 *//* MD_SWCDEMSC_3197 */
    SwcDemSc_EngRsEngCtrl_GrpType   sysVehEngStartupStatusGrp;

    if(Rte_Read_SwcDemSc_SysVehicleEngineStartup_Eng_Rs_EngCtrl(&sysVehEngStartupStatusGrp) != RTE_E_OK)
    {
      /*
        Timeout(RTE_E_MAX_AGE_EXCEEDED) or any other read issue possible.
        Set signal back to the init value to detect bus communication failed.
        There is no need to configure the COM to copy any default value in case of an timeout,
        but the timeout function must be configured:
                                                    Rte_COMCbk_<SIGNAL>()     to reset timeout flag
                                                    Rte_COMCbkTOut_<SIGNAL>() to   set timeout flag
      */
      sysVehEngStartupStatus = SWCDEMSC_GRPINIT_EngRsEngCtrl.EngRun_Stat;
    }
    else
    {
      sysVehEngStartupStatus = sysVehEngStartupStatusGrp.EngRun_Stat;
    }

    /*** Evaluate SC11_CurVehEngStartupStatus ***/

    if(sysVehEngStartupStatus != SWCDEMSC_GRPINIT_EngRsEngCtrl.EngRun_Stat)
    {
      if((sysVehEngStartupStatus == 1) || (sysVehEngStartupStatus == 6))
      {
        /* System unstable */
        Rte_IrvWrite_CheckStorageConditions_SC11_CurVehEngStartupStatus(SWCDEMSC_STAT_SC_ACTIVE);
      }
      else
      {
        /* 0, 3, 4, 5 or other values */
        Rte_IrvWrite_CheckStorageConditions_SC11_CurVehEngStartupStatus(SWCDEMSC_STAT_SC_INACTIVE);
      }
    }
    else
    {
      /* Message never received or timeout */
      Rte_IrvWrite_CheckStorageConditions_SC11_CurVehEngStartupStatus(SWCDEMSC_STAT_SC_INACTIVE);
    }
  }

  Rte_IrvWrite_CheckStorageConditions_glbScSigInd(ReadLocalScSigInd()); /* Set current indication status */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Chk_DEM_SL_ECU_LEVEL
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC11_CurVehEngStartupStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC1_CurCtrlDTCSetting(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC3_CurLocVoltStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC9_CurIoDevConfStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_flOldLev_DEM_SL_ECU_LEVEL(void)
 *   SwcDemSc_FlReportType Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_Chk_DEM_SL_ECU_LEVEL_flOldLev_DEM_SL_ECU_LEVEL(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL(SwcDemSc_FlReportType data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EnCond_DEM_SL_ECU_LEVEL_SetEnableCondition(Boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_Chk_DEM_SL_ECU_LEVEL(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_Chk_DEM_SL_ECU_LEVEL
 *********************************************************************************************************************/

  /*** Local declaration section ***/
  SwcDemSc_StdReturnType flEnableCondRet = SWCDEMSC_E_INVALID;
  SwcDemSc_locFlType     flCondition;
  SwcDemSc_ScStatusType  flOldLev        = Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_flOldLev_DEM_SL_ECU_LEVEL();


  /*** Local implementation section ***/


  /* Evaluate local Failure Level from global Storage Condition */
  WriteLocalFailureLevel(SWCDEMSC_STAT_LOC_FL_INACTIVE);                            /* PRQA S 3198 *//* MD_SWCDEMSC_3198 */
  Write_Local_SC1_CurCtrlDTCSetting      (Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC1_CurCtrlDTCSetting());                        /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC3_CurLocVoltStatus       (Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC3_CurLocVoltStatus());                         /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC9_CurIoDevConfStatus     (Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC9_CurIoDevConfStatus());                       /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC11_CurVehEngStartupStatus(Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC11_CurVehEngStartupStatus());                  /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */

  /* Write current overall status based on criteria all SC 0 or all SC != 0 */
  if(ReadLocalFailureLevel() != SWCDEMSC_STAT_LOC_FL_INACTIVE)
  {
    WriteLocalFailureLevel(SWCDEMSC_STAT_LOC_FL_ACTIVE);
  }

  /* Report Rte_Call_EnCond_DEM_SL_ECU_LEVEL_SetEnableCondition() */
  
  if(Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL() == SWCDEMSC_STAT_FL_REPORT_CYCLIC)
  {
    /* Report Failure Level cyclic */
    flEnableCondRet = Rte_Call_EnCond_DEM_SL_ECU_LEVEL_SetEnableCondition(1, !(SwcDemSc_ScStatusType)ReadLocalFailureLevel());
  }
  else
  {
    /* Report Failure Level on event */
    if((SwcDemSc_ScStatusType)ReadLocalFailureLevel() != flOldLev)
    {
      /* New event incoming */
      flEnableCondRet = Rte_Call_EnCond_DEM_SL_ECU_LEVEL_SetEnableCondition(1, !(SwcDemSc_ScStatusType)ReadLocalFailureLevel());
    }
  }

  /* Decide further notification processing for Rte_Call_EnCond_DEM_SL_ECU_LEVEL_SetEnableCondition() */
    
  if(flEnableCondRet == SWCDEMSC_E_NOT_OK)
  {
    /* Back to cyclic report, if there is any API failure */
    Rte_IrvWrite_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL(SWCDEMSC_STAT_FL_REPORT_CYCLIC);
  }
  else if(flEnableCondRet == SWCDEMSC_E_OK)
  {
    Rte_IrvWrite_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL(SWCDEMSC_STAT_FL_REPORT_EVENT);
  }
  else
  {
    /* Wait for new event */
  }

  /* Save to old level for the next cycle */
  Rte_IrvWrite_Chk_DEM_SL_ECU_LEVEL_flOldLev_DEM_SL_ECU_LEVEL((SwcDemSc_ScStatusType)ReadLocalFailureLevel());

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Chk_DEM_SL_NONE
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NONE_SC1_CurCtrlDTCSetting(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NONE_flOldLev_DEM_SL_NONE(void)
 *   SwcDemSc_FlReportType Rte_IrvRead_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_Chk_DEM_SL_NONE_flOldLev_DEM_SL_NONE(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE(SwcDemSc_FlReportType data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EnCond_DEM_SL_NONE_SetEnableCondition(Boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_Chk_DEM_SL_NONE(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_Chk_DEM_SL_NONE
 *********************************************************************************************************************/

   /*** Local declaration section ***/
  SwcDemSc_StdReturnType flEnableCondRet = SWCDEMSC_E_INVALID;
  SwcDemSc_locFlType     flCondition;
  SwcDemSc_ScStatusType  flOldLev        = Rte_IrvRead_Chk_DEM_SL_NONE_flOldLev_DEM_SL_NONE();
  
  /*** Local implementation section ***/


  /* Evaluate local Failure Level from global Storage Condition */
  WriteLocalFailureLevel(SWCDEMSC_STAT_LOC_FL_INACTIVE);                                        /* PRQA S 3198 *//* MD_SWCDEMSC_3198 */
  Write_Local_SC1_CurCtrlDTCSetting(Rte_IrvRead_Chk_DEM_SL_NONE_SC1_CurCtrlDTCSetting());       /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */

  /* Write current overall status based on criteria all SC 0 or all SC != 0 */
  if(ReadLocalFailureLevel() != SWCDEMSC_STAT_LOC_FL_INACTIVE)
  {
    WriteLocalFailureLevel(SWCDEMSC_STAT_LOC_FL_ACTIVE);
  }
  
  /* Report Rte_Call_EnCond_DEM_SL_NONE_SetEnableCondition() */
  
  if(Rte_IrvRead_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE() == SWCDEMSC_STAT_FL_REPORT_CYCLIC)
  {
    /* Report Failure Level cyclic */
    flEnableCondRet = Rte_Call_EnCond_DEM_SL_NONE_SetEnableCondition(0, !(SwcDemSc_ScStatusType)ReadLocalFailureLevel());
  }
  else
  {
    /* Report Failure Level on event */
    if((SwcDemSc_ScStatusType)ReadLocalFailureLevel() != flOldLev)
    {
      /* New event incoming */
      flEnableCondRet = Rte_Call_EnCond_DEM_SL_NONE_SetEnableCondition(0, !(SwcDemSc_ScStatusType)ReadLocalFailureLevel());
    }
  }

  /* Decide further notification processing for Rte_Call_EnCond_DEM_SL_NONE_SetEnableCondition() */
    
  if(flEnableCondRet == SWCDEMSC_E_NOT_OK)
  {
    /* Back to cyclic report, if there is any API failure */
    Rte_IrvWrite_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE(SWCDEMSC_STAT_FL_REPORT_CYCLIC);
  }
  else if(flEnableCondRet == SWCDEMSC_E_OK)
  {
    Rte_IrvWrite_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE(SWCDEMSC_STAT_FL_REPORT_EVENT);
  }
  else
  {
    /* Wait for new event */
  }

  /* Save to old level for the next cycle */
  Rte_IrvWrite_Chk_DEM_SL_NONE_flOldLev_DEM_SL_NONE((SwcDemSc_ScStatusType)ReadLocalFailureLevel());

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Chk_DEM_SL_NWCOM_NO_CL15
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   SwcDemSc_DebTimType Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC10_dTim_DEM_SL_NWCOM_NO_CL15(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC11_CurVehEngStartupStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC1_CurCtrlDTCSetting(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC4_CurSysVoltStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC5_CurTransModeStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC8_CurPhysBusStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_flOldLev_DEM_SL_NWCOM_NO_CL15(void)
 *   SwcDemSc_FlReportType Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_Chk_DEM_SL_NWCOM_NO_CL15_SC10_dTim_DEM_SL_NWCOM_NO_CL15(SwcDemSc_DebTimType data)
 *   void Rte_IrvWrite_Chk_DEM_SL_NWCOM_NO_CL15_flOldLev_DEM_SL_NWCOM_NO_CL15(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15(SwcDemSc_FlReportType data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EnCond_DEM_SL_NWCOM_NO_CL15_SetEnableCondition(Boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15
 *********************************************************************************************************************/

  /*** Local declaration section ***/
  SwcDemSc_StdReturnType flEnableCondRet = SWCDEMSC_E_INVALID;
  SwcDemSc_locFlType     flCondition;
  SwcDemSc_DebTimType    curTimer        = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT;
  SwcDemSc_ScStatusType  flOldLev        = Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_flOldLev_DEM_SL_NWCOM_NO_CL15();

  /*** Local implementation section ***/


  /* Evaluate local Failure Level from global Storage Condition */
  WriteLocalFailureLevel(SWCDEMSC_STAT_LOC_FL_INACTIVE);                           /* PRQA S 3198 *//* MD_SWCDEMSC_3198 */
  Write_Local_SC1_CurCtrlDTCSetting      (Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC1_CurCtrlDTCSetting());                    /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC4_CurSysVoltStatus       (Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC4_CurSysVoltStatus());                     /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC5_CurTransModeStatus     (Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC5_CurTransModeStatus());                   /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC8_CurPhysBusStatus       (Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC8_CurPhysBusStatus());                     /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC11_CurVehEngStartupStatus(Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC11_CurVehEngStartupStatus());              /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */

  if((ReadLocalFailureLevel() == SWCDEMSC_STAT_LOC_FL_INACTIVE) &&
     (flOldLev                == SWCDEMSC_STAT_SC_ACTIVE      )    )
  {
    curTimer = Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC10_dTim_DEM_SL_NWCOM_NO_CL15();

    /*
      All other current ressources released.
      Last ressource that prevents from status change is the timer SC.
      Start timer now, to force a final status change if there are no new SC's will be activated.
    */

    if(curTimer == (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT)
    {
      /* Timer Storage Condition locks always the Failure Level until the timer expires */
      Write_Local_SC10_DebounceTimer(SWCDEMSC_STAT_SC_ACTIVE);                                                                       /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
      /* Start timer, if not currently running */
      curTimer = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_MAX;
    }
    else if((curTimer - 1) != (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT)
    {
      /* Timer running */
      curTimer = curTimer - 1;
      /* Timer Storage Condition locks always the Failure Level until the timer expires */
      Write_Local_SC10_DebounceTimer(SWCDEMSC_STAT_SC_ACTIVE);                                                                       /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
    }
    else
    {
      /* Timer finished, current Failure Level must remain SWCDEMSC_STAT_SC_INACTIVE now */
      curTimer = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT;
    }
  }
  /*
  else: Possible debounce timer abort - keep init value
  */
  
  Rte_IrvWrite_Chk_DEM_SL_NWCOM_NO_CL15_SC10_dTim_DEM_SL_NWCOM_NO_CL15(curTimer);  

  /* Write current overall status based on criteria all SC 0 or all SC != 0 */
  if(ReadLocalFailureLevel() != SWCDEMSC_STAT_LOC_FL_INACTIVE)
  {
    WriteLocalFailureLevel(SWCDEMSC_STAT_LOC_FL_ACTIVE);
  }
  
  /* Report Rte_Call_EnCond_DEM_SL_NWCOM_NO_CL15_SetEnableCondition() */
  
  if(Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15() == SWCDEMSC_STAT_FL_REPORT_CYCLIC)
  {
    /* Report Failure Level cyclic */
    flEnableCondRet = Rte_Call_EnCond_DEM_SL_NWCOM_NO_CL15_SetEnableCondition(3, !(SwcDemSc_ScStatusType)ReadLocalFailureLevel());
  }
  else
  {
    /* Report Failure Level on event */
    if((SwcDemSc_ScStatusType)ReadLocalFailureLevel() != flOldLev)
    {
      /* New event incoming */
      flEnableCondRet = Rte_Call_EnCond_DEM_SL_NWCOM_NO_CL15_SetEnableCondition(3, !(SwcDemSc_ScStatusType)ReadLocalFailureLevel());
    }
  }

  /* Decide further notification processing for Rte_Call_EnCond_DEM_SL_NWCOM_NO_CL15_SetEnableCondition() */
    
  if(flEnableCondRet == SWCDEMSC_E_NOT_OK)
  {
    /* Back to cyclic report, if there is any API failure */
    Rte_IrvWrite_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15(SWCDEMSC_STAT_FL_REPORT_CYCLIC);
  }
  else if(flEnableCondRet == SWCDEMSC_E_OK)
  {
    Rte_IrvWrite_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15(SWCDEMSC_STAT_FL_REPORT_EVENT);
  }
  else
  {
    /* Wait for new event */
  }

  /* Save to old level for the next cycle */
  Rte_IrvWrite_Chk_DEM_SL_NWCOM_NO_CL15_flOldLev_DEM_SL_NWCOM_NO_CL15((SwcDemSc_ScStatusType)ReadLocalFailureLevel());

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Chk_DEM_SL_NWCOM_WITH_CL15
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   SwcDemSc_DebTimType Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC10_dTim_DEM_SL_NWCOM_WITH_CL15(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC11_CurVehEngStartupStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC1_CurCtrlDTCSetting(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC2_CurIgStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC4_CurSysVoltStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC5_CurTransModeStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC8_CurPhysBusStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_flOldLev_DEM_SL_NWCOM_WITH_CL15(void)
 *   SwcDemSc_FlReportType Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_Chk_DEM_SL_NWCOM_WITH_CL15_SC10_dTim_DEM_SL_NWCOM_WITH_CL15(SwcDemSc_DebTimType data)
 *   void Rte_IrvWrite_Chk_DEM_SL_NWCOM_WITH_CL15_flOldLev_DEM_SL_NWCOM_WITH_CL15(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15(SwcDemSc_FlReportType data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EnCond_DEM_SL_NWCOM_WITH_CL15_SetEnableCondition(Boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15
 *********************************************************************************************************************/

  /*** Local declaration section ***/
  SwcDemSc_StdReturnType flEnableCondRet = SWCDEMSC_E_INVALID;
  SwcDemSc_locFlType     flCondition;
  SwcDemSc_DebTimType    curTimer        = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT;
  SwcDemSc_ScStatusType  flOldLev        = Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_flOldLev_DEM_SL_NWCOM_WITH_CL15();

  /*** Local implementation section ***/


  /* Evaluate local Failure Level from global Storage Condition */
  WriteLocalFailureLevel(SWCDEMSC_STAT_LOC_FL_INACTIVE);                           /* PRQA S 3198 *//* MD_SWCDEMSC_3198 */
  Write_Local_SC1_CurCtrlDTCSetting      (Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC1_CurCtrlDTCSetting());                  /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC2_CurIgStatus            (Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC2_CurIgStatus());                        /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC4_CurSysVoltStatus       (Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC4_CurSysVoltStatus());                   /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC5_CurTransModeStatus     (Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC5_CurTransModeStatus());                 /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC8_CurPhysBusStatus       (Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC8_CurPhysBusStatus());                   /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC11_CurVehEngStartupStatus(Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC11_CurVehEngStartupStatus());            /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */

  if((ReadLocalFailureLevel() == SWCDEMSC_STAT_LOC_FL_INACTIVE) &&
     (flOldLev                == SWCDEMSC_STAT_SC_ACTIVE      )    )
  {
    curTimer = Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC10_dTim_DEM_SL_NWCOM_WITH_CL15();

    /*
      All other current ressources released.
      Last ressource that prevents from status change is the timer SC.
      Start timer now, to force a final status change if there are no new SC's will be activated.
    */

    if(curTimer == (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT)
    {
      /* Timer Storage Condition locks always the Failure Level until the timer expires */
      Write_Local_SC10_DebounceTimer(SWCDEMSC_STAT_SC_ACTIVE);                                                                       /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
      /* Start timer, if not currently running */
      curTimer = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_MAX;
    }
    else if((curTimer - 1) != (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT)
    {
      /* Timer running */
      curTimer = curTimer - 1;
      /* Timer Storage Condition locks always the Failure Level until the timer expires */
      Write_Local_SC10_DebounceTimer(SWCDEMSC_STAT_SC_ACTIVE);                                                                       /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
    }
    else
    {
      /* Timer finished, current Failure Level must remain SWCDEMSC_STAT_SC_INACTIVE now */
      curTimer = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT;
    }
  }
  /*
  else: Possible debounce timer abort - keep init value
  */
  
  Rte_IrvWrite_Chk_DEM_SL_NWCOM_WITH_CL15_SC10_dTim_DEM_SL_NWCOM_WITH_CL15(curTimer);  

  /* Write current overall status based on criteria all SC 0 or all SC != 0 */
  if(ReadLocalFailureLevel() != SWCDEMSC_STAT_LOC_FL_INACTIVE)
  {
    WriteLocalFailureLevel(SWCDEMSC_STAT_LOC_FL_ACTIVE);
  }
  
  /* Report Rte_Call_EnCond_DEM_SL_NWCOM_WITH_CL15_SetEnableCondition() */
  
  if(Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15() == SWCDEMSC_STAT_FL_REPORT_CYCLIC)
  {
    /* Report Failure Level cyclic */
    flEnableCondRet = Rte_Call_EnCond_DEM_SL_NWCOM_WITH_CL15_SetEnableCondition(2, !(SwcDemSc_ScStatusType)ReadLocalFailureLevel());
  }
  else
  {
    /* Report Failure Level on event */
    if((SwcDemSc_ScStatusType)ReadLocalFailureLevel() != flOldLev)
    {
      /* New event incoming */
      flEnableCondRet = Rte_Call_EnCond_DEM_SL_NWCOM_WITH_CL15_SetEnableCondition(2, !(SwcDemSc_ScStatusType)ReadLocalFailureLevel());
    }
  }

  /* Decide further notification processing for Rte_Call_EnCond_DEM_SL_NWCOM_WITH_CL15_SetEnableCondition() */
    
  if(flEnableCondRet == SWCDEMSC_E_NOT_OK)
  {
    /* Back to cyclic report, if there is any API failure */
    Rte_IrvWrite_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15(SWCDEMSC_STAT_FL_REPORT_CYCLIC);
  }
  else if(flEnableCondRet == SWCDEMSC_E_OK)
  {
    Rte_IrvWrite_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15(SWCDEMSC_STAT_FL_REPORT_EVENT);
  }
  else
  {
    /* Wait for new event */
  }

  /* Save to old level for the next cycle */
  Rte_IrvWrite_Chk_DEM_SL_NWCOM_WITH_CL15_flOldLev_DEM_SL_NWCOM_WITH_CL15((SwcDemSc_ScStatusType)ReadLocalFailureLevel());

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Chk_DEM_SL_POWER_DIST
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   SwcDemSc_DebTimType Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC10_dTim_DEM_SL_POWER_DIST(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC11_CurVehEngStartupStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC1_CurCtrlDTCSetting(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC2_CurIgStatus(void)
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_POWER_DIST_flOldLev_DEM_SL_POWER_DIST(void)
 *   SwcDemSc_FlReportType Rte_IrvRead_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_Chk_DEM_SL_POWER_DIST_SC10_dTim_DEM_SL_POWER_DIST(SwcDemSc_DebTimType data)
 *   void Rte_IrvWrite_Chk_DEM_SL_POWER_DIST_flOldLev_DEM_SL_POWER_DIST(SwcDemSc_ScStatusType data)
 *   void Rte_IrvWrite_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST(SwcDemSc_FlReportType data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EnCond_DEM_SL_POWER_DIST_SetEnableCondition(Boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_Chk_DEM_SL_POWER_DIST(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_Chk_DEM_SL_POWER_DIST
 *********************************************************************************************************************/

   /*** Local declaration section ***/
  SwcDemSc_StdReturnType flEnableCondRet = SWCDEMSC_E_INVALID;
  SwcDemSc_locFlType     flCondition;
  SwcDemSc_DebTimType    curTimer       = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT;
  SwcDemSc_ScStatusType  flOldLev        = Rte_IrvRead_Chk_DEM_SL_POWER_DIST_flOldLev_DEM_SL_POWER_DIST();


  /*** Local implementation section ***/


  /* Evaluate local Failure Level from global Storage Condition */
  WriteLocalFailureLevel(SWCDEMSC_STAT_LOC_FL_INACTIVE);                           /* PRQA S 3198 *//* MD_SWCDEMSC_3198 */
  Write_Local_SC1_CurCtrlDTCSetting      (Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC1_CurCtrlDTCSetting());                       /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC2_CurIgStatus            (Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC2_CurIgStatus());                             /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
  Write_Local_SC11_CurVehEngStartupStatus(Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC11_CurVehEngStartupStatus());                 /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */

  if((ReadLocalFailureLevel() == SWCDEMSC_STAT_LOC_FL_INACTIVE) &&
     (flOldLev                == SWCDEMSC_STAT_SC_ACTIVE      )    )
  {
    curTimer = Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC10_dTim_DEM_SL_POWER_DIST();

    /*
      All other current ressources released.
      Last ressource that prevents from status change is the timer SC.
      Start timer now, to force a final status change if there are no new SC's will be activated.
    */

    if(curTimer == (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT)
    {
      /* Timer Storage Condition locks always the Failure Level until the timer expires */
      Write_Local_SC10_DebounceTimer(SWCDEMSC_STAT_SC_ACTIVE);                                                                       /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
      /* Start timer, if not currently running */
      curTimer = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_MAX;
    }
    else if((curTimer -1 ) != (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT)
    {
      /* Timer running */
      curTimer = curTimer - 1;
      /* Timer Storage Condition locks always the Failure Level until the timer expires */
      Write_Local_SC10_DebounceTimer(SWCDEMSC_STAT_SC_ACTIVE);                                                                       /* PRQA S 0277 *//* MD_SWCDEMSC_3.1 */
    }
    else
    {
      /* Timer finished, current Failure Level must remain SWCDEMSC_STAT_SC_INACTIVE now */
      curTimer = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT;
    }
  }
  /*
  else: Possible debounce timer abort - keep init value
  */
  
  Rte_IrvWrite_Chk_DEM_SL_POWER_DIST_SC10_dTim_DEM_SL_POWER_DIST(curTimer);  

  /* Write current overall status based on criteria all SC 0 or all SC != 0 */
  if(ReadLocalFailureLevel() != SWCDEMSC_STAT_LOC_FL_INACTIVE)
  {
    WriteLocalFailureLevel(SWCDEMSC_STAT_LOC_FL_ACTIVE);
  }
    
  /* Report Rte_Call_EnCond_DEM_SL_POWER_DIST_SetEnableCondition() */
  
  if(Rte_IrvRead_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST() == SWCDEMSC_STAT_FL_REPORT_CYCLIC)
  {
    /* Report Failure Level cyclic */
    flEnableCondRet = Rte_Call_EnCond_DEM_SL_POWER_DIST_SetEnableCondition(4, !(SwcDemSc_ScStatusType)ReadLocalFailureLevel());
  }
  else
  {
    /* Report Failure Level on event */
    if((SwcDemSc_ScStatusType)ReadLocalFailureLevel() != flOldLev)
    {
      /* New event incoming */
      flEnableCondRet = Rte_Call_EnCond_DEM_SL_POWER_DIST_SetEnableCondition(4, !(SwcDemSc_ScStatusType)ReadLocalFailureLevel());
    }
  }

  /* Decide further notification processing for Rte_Call_EnCond_DEM_SL_POWER_DIST_SetEnableCondition() */
    
  if(flEnableCondRet == SWCDEMSC_E_NOT_OK)
  {
    /* Back to cyclic report, if there is any API failure */
    Rte_IrvWrite_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST(SWCDEMSC_STAT_FL_REPORT_CYCLIC);
  }
  else if(flEnableCondRet == SWCDEMSC_E_OK)
  {
    Rte_IrvWrite_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST(SWCDEMSC_STAT_FL_REPORT_EVENT);
  }
  else
  {
    /* Wait for new event */
  }

  /* Save to old level for the next cycle */
  Rte_IrvWrite_Chk_DEM_SL_POWER_DIST_flOldLev_DEM_SL_POWER_DIST((SwcDemSc_ScStatusType)ReadLocalFailureLevel());

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetCurrentOdometer
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetCurrentOdometer> of PortPrototype <EnvironmentalValues>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SwcDemSc_SysOdometer_Odo(c24_km_0_999999k9_0k1 *data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   c24_km_0_999999k9_0k1 Rte_IrvRead_GetCurrentOdometer_glbSysOdometer(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SwcDemSc_GetCurrentOdometer(UInt32 *odometer)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EnvironmentalValues_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_GetCurrentOdometer(P2VAR(UInt32, AUTOMATIC, RTE_SWCDEMSC_APPL_VAR) odometer)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_GetCurrentOdometer (returns application error)
 *********************************************************************************************************************/

  *odometer = Rte_IrvRead_HandleSysOdometer_glbSysOdometer();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetExternalTesterStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetExternalTesterStatus> of PortPrototype <EnvironmentalValues>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SwcDemSc_SysExtTester_DidA_ExtTest_Pres(DC_BOOL *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SwcDemSc_GetExternalTesterStatus(Boolean *testerPresent)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EnvironmentalValues_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_GetExternalTesterStatus(P2VAR(Boolean, AUTOMATIC, RTE_SWCDEMSC_APPL_VAR) testerPresent)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_GetExternalTesterStatus (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType ret = Rte_Read_SwcDemSc_SysExtTester_DidA_ExtTest_Pres(testerPresent);

  return ret; /* Timeout(RTE_E_MAX_AGE_EXCEEDED) or any other read issue possible */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetIgnitionSignal
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SwcDemSc_LocIgnition_Ign_Stat(c03_ISw_Stat *data)
 *   Std_ReturnType Rte_Read_SwcDemSc_SysIgnition_Ign_Stat(SwcDemSc_IgnStat_GrpType *data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_GetIgnitionSignal_glbCurSig_Ignition(c03_ISw_Stat data)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_GetIgnitionSignal(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_GetIgnitionSignal
 *********************************************************************************************************************/

  c03_ISw_Stat                locIgStatus = Rte_InitValue_SwcDemSc_LocIgnition_Ign_Stat;    /* PRQA S 3197 *//* MD_SWCDEMSC_3197 */
  c03_ISw_Stat                sysIgStatus = SWCDEMSC_GRPINIT_IgnStat.ISw_Stat;              /* PRQA S 3197 *//* MD_SWCDEMSC_3197 */
  SwcDemSc_IgnStat_GrpType    sysIgStatusGrp;

  (void)Rte_Read_SwcDemSc_LocIgnition_Ign_Stat(&locIgStatus);               /* PRQA S 3417, 3426 *//* MD_SWCDEMSC_12.10, MD_SWCDEMSC_14.2 */

  if(Rte_Read_SwcDemSc_SysIgnition_Ign_Stat(&sysIgStatusGrp) != RTE_E_OK)
  {
    /*
      Timeout(RTE_E_MAX_AGE_EXCEEDED) or any other read issue possible.
      Set signal back to the init value to detect bus communication failed.
      There is no need to configure the COM to copy any default value in case of an timeout,
      but the timeout function must be configured:
                                                  Rte_COMCbk_<SIGNAL>()     to reset timeout flag
                                                  Rte_COMCbkTOut_<SIGNAL>() to   set timeout flag
    */
    sysIgStatus = SWCDEMSC_GRPINIT_IgnStat.ISw_Stat;
  }
  else
  {
    sysIgStatus = sysIgStatusGrp.ISw_Stat;
  }

  /*** Evaluate Ignition Status ***/
  if(sysIgStatus != SWCDEMSC_GRPINIT_IgnStat.ISw_Stat)
  {
    Rte_IrvWrite_GetIgnitionSignal_glbCurSig_Ignition(sysIgStatus);   /* System Ignition is used */
  }
  else if(locIgStatus != Rte_InitValue_SwcDemSc_LocIgnition_Ign_Stat)
  {
    Rte_IrvWrite_GetIgnitionSignal_glbCurSig_Ignition(locIgStatus);   /* Local Ignition is used */
  }
  else
  {
    /* Neither sysIgStatus nor locIgStatus available -> keep last known value (either last valid or init value) */
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HandleSysOdometer
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SwcDemSc_SysOdometer_Odo(c24_km_0_999999k9_0k1 *data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   c24_km_0_999999k9_0k1 Rte_IrvRead_HandleSysOdometer_glbSysOdometer(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_HandleSysOdometer_glbSysOdometer(c24_km_0_999999k9_0k1 data)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_HandleSysOdometer(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_HandleSysOdometer
 *********************************************************************************************************************/

  Std_ReturnType        retCode;
  c24_km_0_999999k9_0k1 newOdo;
  c24_km_0_999999k9_0k1 oldOdo = Rte_IrvRead_HandleSysOdometer_glbSysOdometer();

  static DC_BOOL b_InitOdoDone = FALSE;

  if(b_InitOdoDone == FALSE)
  {
    /* Odometer on communication bus system:
     * Raw:        physical:       resolution:
     * 0..9999999  0..999999.9 km  0.1 km
     * => Store to NvM with the same resolution:
     * c24_km_0_999999k9_0k1 -> uint32; */
    NvM_v_ReadRamOdometer((uint8*)&oldOdo);

    Rte_IrvWrite_HandleSysOdometer_glbSysOdometer(oldOdo);

    b_InitOdoDone = TRUE;
  }

  retCode = Rte_Read_SwcDemSc_SysOdometer_Odo(&newOdo);

  if (RTE_E_OK == retCode)
  {
    if (((newOdo & 0xFFFFFEuL)  != 0xFFFFFEuL) || /* (newOdo != 0xFFFFFFuL) && (newOdo != 0xFFFFFEuL) */
        ((oldOdo & 0xFFFFFEuL)  == 0xFFFFFEuL))   /* (oldOdo == 0xFFFFFFuL) || (oldOdo == 0xFFFFFEuL) */
    {
      /* Condition 1: the sys odometer value is valid         -> store it */
      /* Condition 2: no valid value has been received before -> store even errors (0xFFFFFF and 0xFFFFFE may toggle) */
      /* -> store value */
      Rte_IrvWrite_HandleSysOdometer_glbSysOdometer(newOdo);

      if(newOdo != oldOdo)
      {
        /* Odometer on communication bus system:
         * Raw:        physical:       resolution:
         * 0..9999999  0..999999.9 km  0.1 km
         * => Store to NvM with the same resolution:
         * c24_km_0_999999k9_0k1 -> uint32; */
        NvM_v_WriteRamOdometer((uint8*)&newOdo);
      }
    }
    else
    {
      /* the sys odometer value is not valid but we have stored a previously received valid one -> take that */
    }
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetIgnitionCycle
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   SwcDemSc_DebTimType Rte_IrvRead_SetIgnitionCycle_dTim_DEM_OC_IGNITION(void)
 *   Dem_OperationCycleStateType Rte_IrvRead_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION(void)
 *   SwcDemSc_FlReportType Rte_IrvRead_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION(void)
 *   c03_ISw_Stat Rte_IrvRead_SetIgnitionCycle_glbCurSig_Ignition(void)
 *   c03_ISw_Stat Rte_IrvRead_SetIgnitionCycle_glbOldSig_Ignition(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_SetIgnitionCycle_dTim_DEM_OC_IGNITION(SwcDemSc_DebTimType data)
 *   void Rte_IrvWrite_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION(Dem_OperationCycleStateType data)
 *   void Rte_IrvWrite_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION(SwcDemSc_FlReportType data)
 *   void Rte_IrvWrite_SetIgnitionCycle_glbOldSig_Ignition(c03_ISw_Stat data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_OpCycle_DEM_IGNITION_SetOperationCycleState(Dem_OperationCycleStateType CycleState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OperationCycle_DEM_E_QUEUE_OVERFLOW, RTE_E_OperationCycle_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCDEMSC_APPL_CODE) SwcDemSc_SetIgnitionCycle(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcDemSc_SetIgnitionCycle
 *********************************************************************************************************************/

  SwcDemSc_StdReturnType      flOpCycleRet      = SWCDEMSC_E_INVALID;
  c03_ISw_Stat                curIgStatus       = Rte_IrvRead_SetIgnitionCycle_glbCurSig_Ignition();
  c03_ISw_Stat                oldIgStatus       = Rte_IrvRead_SetIgnitionCycle_glbOldSig_Ignition();
  SwcDemSc_DebTimType         curTimer          = Rte_IrvRead_SetIgnitionCycle_dTim_DEM_OC_IGNITION();
  Dem_OperationCycleStateType localIgCycleState = Rte_IrvRead_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION();


  /*** Evaluate Ignition Status ***/
  if (I_C03_ISW_STAT_IGN_START == curIgStatus)
  {
    /* Status IGN_START will be ignored -> take 'last known' value */
    curIgStatus = oldIgStatus;
  }

  /* Remaining ignition states: OFF: IGN_LOCK, IGN_OFF, IGN_ACC; ON: IGN_ON */
  if ((I_C03_ISW_STAT_IGN_ON != curIgStatus) && 
      (I_C03_ISW_STAT_IGN_ON == oldIgStatus)    )
  {
    /* Transition from ignition ON to ignition OFF -> stop ignition cycle, stop timer */
    localIgCycleState = DEM_CYCLE_STATE_END;
    curTimer = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT;
  }
  else if ((I_C03_ISW_STAT_IGN_ON == curIgStatus      ) && 
           (DEM_CYCLE_STATE_START != localIgCycleState)    )
  {
    /* Ignition is ON and timer has not been finished, yet -> check debounce timer status */
    if(curTimer == (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT)
    {
      /* Start timer, as currently not running */
      curTimer = (SwcDemSc_DebTimType)SWCDEMSC_VAL_IG_DEB_TIM_MAX;
    }
    else if((curTimer - 1) != (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT)
    {
      /* Timer running */
      curTimer = curTimer - 1;
    }
    else
    {
      /* Timer finished, ignition cycle can be started now */
      localIgCycleState = DEM_CYCLE_STATE_START;
      curTimer = (SwcDemSc_DebTimType)SWCDEMSC_VAL_SC_DEB_TIM_INIT;
    }
  }
  else 
  {
    /* ignition status is unchanged OFF or ignition status is ON and timer has been finished */
  }

  /* Save 'last known' ignition status for the next cycle */
  Rte_IrvWrite_SetIgnitionCycle_glbOldSig_Ignition(curIgStatus);

  /* Save timer for the next cycle */
  Rte_IrvWrite_SetIgnitionCycle_dTim_DEM_OC_IGNITION(curTimer);

  /* Report Rte_Call_OpCycle_DEM_IGNITION_SetOperationCycleState() */
  if(Rte_IrvRead_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION() == SWCDEMSC_STAT_FL_REPORT_CYCLIC)
  {
    /* Report ignition cycle state cyclic */
    flOpCycleRet = Rte_Call_OpCycle_DEM_IGNITION_SetOperationCycleState(DEM_IGNITION_CYCLE, localIgCycleState);
  }
  else
  {
    /* Report ignition cycle state on event */
    if(localIgCycleState != Rte_IrvRead_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION())
    {
      /* New event incoming */
      flOpCycleRet = Rte_Call_OpCycle_DEM_IGNITION_SetOperationCycleState(DEM_IGNITION_CYCLE, localIgCycleState);
    }
  }

  /* Decide further notification processing for Rte_Call_OpCycle_DEM_IGNITION_SetOperationCycleState() */
  if((flOpCycleRet == RTE_E_OperationCycle_DEM_E_QUEUE_OVERFLOW) || 
     (flOpCycleRet == RTE_E_OperationCycle_E_NOT_OK            )    )
  {
    /* Back to cyclic report, if there is any API failure */
    Rte_IrvWrite_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION(SWCDEMSC_STAT_FL_REPORT_CYCLIC);
  }
  else if (flOpCycleRet == SWCDEMSC_E_OK)
  {
    Rte_IrvWrite_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION(SWCDEMSC_STAT_FL_REPORT_EVENT);
  }
  else
  {
    /* Wait for new event */
  }

  /* Save to old ignition cycle state for the next cycle */
  Rte_IrvWrite_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION(localIgCycleState);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SWCDEMSC_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Local Static Function Name: SwcDemSc_HandleSysVoltMontoring
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   SwcDemSc_ScStatusType Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC4_CurSysVoltStatus(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   ---
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Dem_SetEventStatus()
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: E_NOT_OK, E_NOT_OK
 *
 *********************************************************************************************************************/
static void SwcDemSc_HandleSysVoltMontoring(c08_V_0_25k4_0k1 CurSysVoltage)
{
/*--- (SYMBOLIC) CONSTANTS ---*/

#define SWCDEMSC_VAL_SYS_VOLT_HYSTERESIS  ((c08_V_0_25k4_0k1)5)
#define SWCDEMSC_STATE_NORM   0uL
#define SWCDEMSC_STATE_UVOLT  1uL
#define SWCDEMSC_STATE_OVOLT  2uL

/** System Over-/UnderVoltage-DTC debounce timer in multiples of cycle
    time of the following runnable: SwcDemSc_CheckStorageConditions
    must be at least 1 */
#define SYSTEM_DEBOUNCE_CNT        (1500u)

/*--- VARIABLES ---*/
  /*** Local declaration section ***/

  static UInt32 locSupStat = SWCDEMSC_STATE_NORM;
  static UInt32 locDebouncer = (UInt32)SYSTEM_DEBOUNCE_CNT;


  /*** Local implementation section ***/
  /*** Evaluate CurSysVoltStatus ***/

  /* just debounce */
  if(locDebouncer > 0uL)
  {
    locDebouncer--;
  }

  /* Check if system voltage is valid received from bus. */
  if(CurSysVoltage != SWCDEMSC_GRPINIT_PN14SupBatStat.PN14_SupBat_Volt)
  {
    /* CurSysVoltage available */
    /*! Check if voltage is in regular range */
    if(SWCDEMSC_VAL_SYS_VOLT_MIN >= CurSysVoltage)
    {
      /* when not in this state, start debouncing */
      if(locSupStat != SWCDEMSC_STATE_UVOLT)
      {
        locDebouncer = (UInt32)SYSTEM_DEBOUNCE_CNT;
      }
      locSupStat = SWCDEMSC_STATE_UVOLT;
    }
    else if(SWCDEMSC_VAL_SYS_VOLT_MAX <= CurSysVoltage)
    {
      /* when not in this state, start debouncing */
      if(locSupStat != SWCDEMSC_STATE_OVOLT)
      {
        locDebouncer = (UInt32)SYSTEM_DEBOUNCE_CNT;
      }
      locSupStat = SWCDEMSC_STATE_OVOLT;
    }
    else
    {
      /* voltage between 9.5V and 15.5V set it to normal again, in all other cases leave it untouched */
      if( (CurSysVoltage > (SWCDEMSC_VAL_SYS_VOLT_MIN + SWCDEMSC_VAL_SYS_VOLT_HYSTERESIS))
        && (CurSysVoltage < (SWCDEMSC_VAL_SYS_VOLT_MAX - SWCDEMSC_VAL_SYS_VOLT_HYSTERESIS)) )
      {
        /* when not in this state, start debouncing */
        if(locSupStat != SWCDEMSC_STATE_NORM)
        {
          locDebouncer = (UInt32)SYSTEM_DEBOUNCE_CNT;
        }
        locSupStat = SWCDEMSC_STATE_NORM;
      }
    }
  }
  else
  {
    /* CurSysVoltage not available from bus. Presum System Voltage is in normal range. */
    locSupStat = SWCDEMSC_STATE_NORM;
  }

  if(locSupStat == SWCDEMSC_STATE_NORM)
  {
    if(locDebouncer == 0uL)
    {
      (void)Dem_SetEventStatus(MON_SYS_UNDERVOLTAGE, DEM_EVENT_STATUS_PASSED);
      (void)Dem_SetEventStatus(MON_SYS_OVERVOLTAGE, DEM_EVENT_STATUS_PASSED);
    }
  }
  else
  {
    if(locDebouncer == 0uL)
    {
      if(locSupStat == SWCDEMSC_STATE_UVOLT)
      {
        (void)Dem_SetEventStatus(MON_SYS_UNDERVOLTAGE, DEM_EVENT_STATUS_FAILED);
        (void)Dem_SetEventStatus(MON_SYS_OVERVOLTAGE, DEM_EVENT_STATUS_PASSED);
      }
      else
      {
        (void)Dem_SetEventStatus(MON_SYS_UNDERVOLTAGE, DEM_EVENT_STATUS_PASSED);
        (void)Dem_SetEventStatus(MON_SYS_OVERVOLTAGE, DEM_EVENT_STATUS_FAILED);
      }
    }
  }
/* -----------------------------*/
}




/* module specific MISRA deviations:
   MD_SWCDEMSC_3.1:
     Reason:     Avoid compiler warning/error.
                 The SWCDEMSC_UNSET_BIT() macro uses the ~ operator to construct a 1111 bit mask with a single bit set
                 to 0. For correct MISRA implementation (according PRQA) the code must be like
                    (varType)(~(1u << 0))
                 Unfortunately most compilers need an additional cast
                    (varType)(~(varType)(1u << 0))
                 to avoid warnings or error messages like "cast truncates constant value" (VisualC), "truncating 
                 assignment" (Cosmic), "Possible loss of data" (Metrowerks).
                 To get compilable code each use of the SWCDEMSC_UNSET_BIT() macro (and other macros using the 
                 ~ operator) will intentionally cause MISRA-C:2004 Rule 3.1 violation!
     Risk:       None.
     Prevention: None.
   MD_SWCDEMSC_12.10:
     Reason:     This deviation is caused by the RTE. 
     Risk:       n.a.
     Prevention: n.a.
   MD_SWCDEMSC_14.2:
     Reason:     This statement is used to avoid warnings caused by unused parameters.
     Risk:       None.
     Prevention: None.
   MD_SWCDEMSC_19.10:
     Reason:     Don't use () with 'varType' when using inside SwcDemSc_[UN]SET_BIT macro, else type-cast there will 
                 fail due ((varType)) as cast is invalid with some compilers.
     Risk:       The operator precedence may not give the desired results.
     Prevention: Code review and detailed test of the component in the component test.
   MD_SWCDEMSC_3197:
     Reason:     The modification is done with an external function.
     Risk:       None.
     Prevention: None.
   MD_SWCDEMSC_3198:
     Reason:     Just single bits are modified later - the resetting of the complete word is necessary.
     Risk:       None.
     Prevention: None.
    MD_SWCDEMSC_4700:
     Reason:     All storage conditions are evaluated in the same function.
     Risk:       Resulting code is difficult to understand.
     Prevention: Detailed test of the component in the component test.
*/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: SwcDemSc.c
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
