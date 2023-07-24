/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_parameter_def.h

DESCRIPTION:               Header of the HEAD component - for parameter definition

AUTHOR:                    $Author: Veerashettappa, Nagaraja (uidp9076) $

CREATION DATE:             $Date: 2020/11/09 13:51:55CET $

VERSION:                   $Revision: 1.56 $

LEGACY VERSION:            1.43.1.4 (HEAD 2.0)

**************************************************************************** */

#ifndef HEAD20_PARAMETER_DEF_H_INCLUDED
#define HEAD20_PARAMETER_DEF_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#include "head/head_float16_util.h"
/* PRQA S 0791 EOF */ /* date: 20-11-2019,  Reviewer:uic42639,Reason: warning is due to more number of identical characters match in defining two macros. However this will have no impact on the software */
/* PRQA S 2053 EOF */ /* date: 20-11-2019,  Reviewer:uic42639, Reason:warning is due to commenting source code which is not the case (not true) hence masking the warning */
/* PRQA S 0779 EOF*//* date: 20-11-2019, Reviewer:uic42639, Reason: Length of the identifier C90 limitted to 32 Charaters but in C99 allowed to 52 characters  */
/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! @brief       Max. allowed value due to half precision floating point range
    @general     This value related to raw in head parameter, stat upper limit because of half precision floating point range.
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none]     @min 0   @max 65500   */
#define HEADParameterRawValue_Max (65500)  /* Max. allowed value due to half precision floating point range  */

/* parameter definition for tables */

/*! @brief       Definition of table type for Host speed
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_HostSpeed                  ((HEADParamTableType_t) eHEADParamTabType_HostSpeed)

/*! @brief       Definition of table type for Object Acceleration
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_ObjectAccel                ((HEADParamTableType_t)eHEADParamTabType_ObjectAccel)

/*! @brief       Definition of table type for Object Speed
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_ObjectSpeed                ((HEADParamTableType_t)eHEADParamTabType_ObjectSpeed)

/*! @brief       Definition of table type for Host Accel.
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none]   */
#define HEADParamTableType_HostAccel                  ((HEADParamTableType_t) eHEADParamTabType_HostAccel)

/*! @brief       Definition of table type for Host Distance
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_Distance                   ((HEADParamTableType_t) eHEADParamTabType_Distance)

/*! @brief       Definition of table type for Driver Attention
    @general     [none]
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none] */
#define HEADParamTableType_DriverAttention            ((HEADParamTableType_t) eHEADParamTabType_ProbAttention)

/*! @brief       Definition of table type for Driver Feedback
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_DriverFeedback             ((HEADParamTableType_t) eHEADParamTabType_ProbFeedback) 

/*! @brief       Definition of table type for Driver Activity
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_DriverActivity             ((HEADParamTableType_t) eHEADParamTabType_ProbActivity) 

/*! @brief       Definition of table type for Host Speed's last state transaction.
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_HostSpeedLastStateTrans    ((HEADParamTableType_t) eHEADParamTabType_HostSpeedLastStateTrans)

/*! @brief       Definition of table type for Closing velocity
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none]  */
#define HEADParamTableType_ClosingVelocity            ((HEADParamTableType_t) eHEADParamTabType_ClosingVelocity)

/*! @brief       Definition of table type for VRel X
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_VRelX                      ((HEADParamTableType_t) eHEADParamTabType_VRelX)

/*! @brief       Definition of table type for TTC
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_TTC                        ((HEADParamTableType_t) eHEADParamTabType_TTC)

/*! @brief       Definition of table type for ObjListConfig
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_ObjListConfig              ((HEADParamTableType_t) eHEADParamTabType_ObjListConfig)

/*! @brief       Definition of table type for Inlap
    @general     [none]
    @conseq      [none]

    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_Inlap                      ((HEADParamTableType_t) eHEADParamTabType_Inlap)

/*! @brief       Definition of table type for Impact Velocity Ego
    @general     [none]
    @conseq      [none]

    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_ImpactVelEgo               ((HEADParamTableType_t) eHEADParamTabType_ImpactVelEgo)

/*! @brief       Definition of table type for Impact Velocity Relative
    @general     [none]
    @conseq      [none]

    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_ImpactVelRel               ((HEADParamTableType_t) eHEADParamTabType_ImpactVelRel)

    /*! @brief       Definition of table type for hypothesis lifetime
        @general     [none]
        @conseq      [none]

        @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
        @typical     [none]   @unit [none] */
#define HEADParamTableType_HypLifetime               ((HEADParamTableType_t) eHEADParamTabType_HypLifetime)

   /*! @brief       Definition of table type for Customer Parameter 00 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_00_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_00_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 01 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_01_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_01_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 02 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_02_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_02_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 03 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_03_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_03_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 04 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_04_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_04_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 05 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_05_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_05_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 06 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_06_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_06_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 07 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_07_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_07_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 08 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_08_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_08_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 09 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_09_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_09_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 10 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_10_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_10_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 11 Hyp. dependent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_11_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_11_HypDependent)

/*! @brief       Definition of table type for Customer Parameter 00 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_00_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_00_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 01 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_01_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_01_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 02 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_02_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_02_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 03 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_03_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_03_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 04 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_04_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_04_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 05 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_05_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_05_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 06 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_06_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_06_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 07 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_07_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_07_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 08 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_08_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_08_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 09 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_09_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_09_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 10 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_10_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_10_HypIndependent)

/*! @brief       Definition of table type for Customer Parameter 11 Hyp. independent
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParamTableType_CustomPar_11_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_11_HypIndependent)


/*! @brief       Definition use as function to call and set parameter mode for all bit
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none]  */
#define HEADParameterModeBit(mode)  ((HEADParameterMode_t)1u<<(mode))

/*! @brief       Definition Of head parameter Mode early 
    @general     This macro use a Other Macro definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterMode_Early     (HEADParameterModeBit((HEADMainMode_t)HEADMainMode_Early))

/*! @brief       Definition Of head parameter Mode Middle
    @general     This macro use a Other Macro definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterMode_Middle    (HEADParameterModeBit((HEADMainMode_t)HEADMainMode_Middle))

/*! @brief       Definition Of head parameter Mode late
    @general     This macro use a Other Macro definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterMode_Late      (HEADParameterModeBit((HEADMainMode_t)HEADMainMode_Late))

/*! @brief       Definition Of head parameter Mode ACC
    @general     This macro use a Other Macro Definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterMode_ACC       (HEADParameterModeBit((HEADMainMode_t)HEADMainMode_ACC))

/*! @brief       Definition Of head parameter Mode for all
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro and done bit wise or operation over it.
    @typical     [none]   @unit [none] */
#define HEADParameterMode_All       (HEADParameterMode_Early|HEADParameterMode_Middle|HEADParameterMode_Late|HEADParameterMode_ACC)

/*! @brief       Definition use as function to call and set State mode for all bit
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterStateBit(state)      (1u<<((HEADParameterState_t)(state)))

/*! @brief       Definition Of head parameter state for keep passive bit
    @general     This macro use a Other Macro Definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterState_KeepPassiveBit (HEADParameterStateBit(HEADParameterState_KeepPassive))

/*! @brief       Definition Of head parameter state for enable bit
    @general     This macro use a Other Macro Definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterState_EnableBit      (HEADParameterStateBit(HEADParameterState_Enable))

/*! @brief       Definition Of head parameter state for keep active bit
    @general     This macro use a Other Macro Definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterState_KeepActiveBit  (HEADParameterStateBit(HEADParameterState_KeepActive))

/*! @brief       Definition Of head parameter state for leave active bit
    @general     This macro use a Other Macro Definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterState_LeaveActiveBit (HEADParameterStateBit(HEADParameterState_LeaveActive))

/*! @brief       Definition Of head parameter state for keep wait bit
    @general     This macro use a Other Macro Definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterState_KeepWaitBit    (HEADParameterStateBit(HEADParameterState_KeepWait))

/*! @brief       Definition Of head parameter state for leave wait bit
    @general     This macro use a Other Macro Definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none]  */
#define HEADParameterState_LeaveWaitBit   (HEADParameterStateBit(HEADParameterState_LeaveWait))

/*! @brief       Definition Of head parameter state for state init bit
    @general     This macro use a Other Macro Definition by calling HEADParameterModeBit for bit wise left shift operation
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical     [none]   @unit [none] */
#define HEADParameterState_InitBit        (HEADParameterStateBit(HEADParameterState_Init))

/*! @brief       Definition Of head parameter state for all bit
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterState_t, as enum variable is assigned to macro, and bitwise or operation done over it to get macro for all combine in one.
    @typical     [none]   @unit [none] */
#define HEADParameterState_AllBits        (HEADParameterState_KeepPassiveBit|HEADParameterState_EnableBit|HEADParameterState_KeepActiveBit|HEADParameterState_LeaveActiveBit|HEADParameterState_KeepWaitBit|HEADParameterState_LeaveWaitBit|HEADParameterState_InitBit)

/*! @brief       HEAD CPAR EBA Object list configured
    @general     [none]
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none] */
#define HEAD_CPAR_EBA_OBJ_COFIG           (MEDIC_p_GetCPARFCTParameters()->EBA.eObjListConfig)

/*! @brief       Definition Of head MTS maximum table row
    @general     mts output for parameters
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none]     @min 0   @max 65535   */
#define HEAD_MTS_MAX_TABLE_ROWS (4u)

//Columns for 3d table
#define HEAD_MTS_MAX_3D_TABLE_ROWS (21u)
#define HEAD_MTS_MAX_TABLE_COLUMNS (4u)

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! @brief       Definition for Head parameter hypothesis bit
    @general     This Macro will do simple bitwise shift operation over hypothesis variable and typecast with enum variable
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterHypothesisSub_t, as enum variable is assigned to macro.
    @typical     [none]   @unit [none] */
#define HEADParameterHypothesisBit(hypothesis)  ((HEADParameterHypothesisSub_t)1u<<((uint32)(hypothesis)-1u))

/*! @brief       Definition Of head parameter hypothesis of all bits
    @general     This Macro will do simple bitwise shift operation over hypothesis variable and typecast with enum variable
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterHypothesisSub_t, as enum variable is assigned to macro.
    @typical     [none]   @unit [none] */
#define HEADParameterHypothesisAllBits(hypothesis_max) (HEADParameterHypothesisBit(hypothesis_max)-1u)

/*! @brief       Definition Of head parameter of hypothesis for independent elements.
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterHypothesisSub_t, as enum variable is assigned to macro.
    @typical     [none]   @unit [none]  */
#define HEADParameterHypothesisIndependent ((HEADParameterHypothesisSub_t)0)

/*! @brief       Definition Of head parameter of sensor source for independent elements.
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterSensorSourceSub_t, as enum variable is assigned to macro.
    @typical     [none]   @unit [none]  */
#define HEADParameterSensorSourceIndependent ((HEADParameterSensorSourceSub_t)0)

/*! @brief       Definition Of head parameter of sensor source for independent elements.
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is HEADParameterSensorSourceSub_t, as enum variable is assigned to macro.
    @typical     [none]   @unit [none]  */
#define HEADParameterSensorBit(SensorSource) ((HEADParameterSensorSourceSub_t)(1u<<((uint8)(SensorSource)-1u)))

/*! @brief       Definition Of Head other module state time to bit pack
    @general     creates a 1|6|5 bit structure of the information (in state [1], not in state [0]) (module state [off, passive, active, wait]) (modulenr+1)
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none] */
#define HEADOtherModuleStateTime2BitPack(ModuleNr, ModulState, bInState) \
  ((uint16)(( (((bInState) & 1u) << 12u) | ((ModulState) << 5u) | ((ModuleNr)))))

/*! @brief       Definition Of head bit pack to other module state time module near
    @general     [none]
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none]     @min 0 @max 255  */
#define HEADBitPackToOtherModuleStateTime_ModuleNr(bitpack)    ((uint8)((bitpack)&0x1fu))


/*! @brief       Definition Of head bit pack to other module state time module state.
    @general     [none]
    @conseq      [none]
                 
    @attention   Type of Macro is eHEADSMState_t, as enum variable is assigned to macro.
    @typical     [none]   @unit [none]      */
#define HEADBitPackToOtherModuleStateTime_ModuleState(bitpack) ((eHEADSMState_t)(((bitpack)>>5u)&0x7fu))


/*! @brief       Definition Of head bit pack to other module state time must be in state
    @general     [none]
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none]     @min 0   @max 1   */
#define HEADBitPackToOtherModuleStateTime_MustBeInState(bitpack) (((((bitpack)>>12)&0x1u) != 0u) ? b_TRUE : b_FALSE)


/*! @brief       Definition Of head other or group true to bit pack
    @general     [none]
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none]     @min 0   @max 65535   */
#define HEADOtherOrGroupTrue2BitPack(OrGroupNr, bTrueFalse) \
  ((uint16)(( (((bTrueFalse) & 1u) << 3u) | ((OrGroupNr)))))

/*! @brief       Definition Of head bit pack to other or group or group near
    @general     [none]
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none]     @min 0   @max 255   */
#define HEADBitPackToOtherOrGroup_OrGroupNr(bitpack)       ((uint8)((bitpack)&0x3u))

/*! @brief       Definition Of head bit pack to other or group must be true or false
    @general     [none]
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none]     @min 0   @max 1   */
#define HEADBitPackToOtherOrGroup_MustBeTrueFalse(bitpack) ((boolean)(((bitpack)>>3)&0x1u))

    /*! @brief       Definition Of head bit pack for sensor source and sensor source check type
        @general     [none]
        @conseq      [none]

        @attention   [none]
        @typical     [none]   @unit [none]     @min 0   @max 65535   */
#define HEADBitPackSensorSource(SensorCheckType, SensorSource)  ((uint16) (((SensorCheckType) << 14u) | SensorSource))

/*! @brief       Definition Of head bit pack to Sensor Source Check Type
    @general     [none]
    @conseq      [none]

    @attention   [none]
    @typical     [none]   @unit [none]     @min 0   @max 3   */
#define HEADGetBitsSensorCheckType(CheckType)                   ((uint16) (((CheckType) >> 14u) & 0x0003u))

/*! @brief       Definition Of head bit pack for precondition group no and precondition check type
    @general     [none]
    @conseq      [none]

    @attention   [none]
    @typical     [none]   @unit [none]     @min 0   @max 65535   */
#define HEADBitPackPreCondition(PreCondCheckType, PreCondGroupNo)  ( (uint16) ((PreCondCheckType << 15u) | PreCondGroupNo) )

/*! @brief       Definition Of head object class bit.
    @general     [none]
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none]     @min 0   @max 255   */
#define HEADObjectClassBit(object)  ((HEADEBAObjectClass_t)1u<<((uint8)(object) -1u))

/*! @brief       Definition Of head dynamic properties bit
    @general     [none]
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   @unit [none]     @min 0   @max 255   */
#define HEADDynPropBit(dynProp)          ((HEADEBADynProp_t)1u<<((uint8)(dynProp)-1u))

/*! @brief          Definition Of head object movement direction bit
    @typical        [none]   @unit [none]     @min 0   @max 255   */
#define HEADObjMovDirBit(objMovDir)         ((HEADEBAObjMovDir_t)1u<<((uint8)(objMovDir)))

/*! @brief       Definition for Head parameter Condition Groups bit
    @general     This Macro will do simple bitwise shift operation over CondGrpNr variable and typecast with enum variable
    @conseq      [none]
                 
    @attention   Type of Macro is HEADCondGrpBitField_t, as enum variable is assigned to macro.
    @typical     [none]   @unit [none] */
#define HEADParameterCondGroupBit(CondGrpNr)  ((HEADCondGrpBitField_t)1u<<((uint8)(CondGrpNr)))


/*! @brief       Get the hypothesis logic(AND/OR) for the current condition group number
    @general     [none]
    @conseq      [none]
                 
    @attention   [none]
    @typical     [none]   */
#define HEADParamHypLogic_MustBeAnd(bitpack, CondGrpNr)     (((((bitpack) >> (CondGrpNr)) & 0x1u) != 0u) ? b_TRUE : b_FALSE)


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* 
  parameters are typically defined in concatenated lists (each HEAD module gets a parameter 
  list that defines all the parameters that are used in this module) this list is defined 
  HEADParameterList_t

example:

  HEADParameterScalar_t

   ------------------------------------
  | MainType (scalar, table)           | \
   ------------------------------------   |
  | MainValueType (value, factor, ...) |  |
   ------------------------------------   |
  | Operator (<, >)                    |  |
   ------------------------------------   |
  | OutType (TTC, HypProb, ... )       |  |
   ------------------------------------   |
  | State (Enable,Keep,Wait)           |  |
   ------------------------------------   |- param header
  | Mode (early, middle, late, acc)    |  |
   ------------------------------------   |
  | HypMainType (kin, drv)             |  |
   ------------------------------------   |
  | HypSubType (Run-Up, ...)           |  |
   ------------------------------------   |
  | OrGroup (G0..G3)                   |  |
   ------------------------------------   |
  | pointer to next parameter          | /
   ====================================
  | SpecialParInfo                     |
   ------------------------------------
  | RawValue                           |  - Value
   ------------------------------------  


  HEADParameterTable_t

   -----------------------------------
  | MainType (scalar, table)          | \
   -----------------------------------   |
  | MainValueType (value, factor, ...)|  |
   -----------------------------------   |
  | Operator (<, >)                   |  |
   -----------------------------------   |
  | OutType (TTC, HypProb, ... )      |  |
   -----------------------------------   |
  | State (Enable,Keep,Wait)          |  |
   -----------------------------------   |- param header
  | Mode (early, middle, late, acc)   |  |
   -----------------------------------   |
  | HypMainType (kin, drv)            |  |
   -----------------------------------   |
  | HypSubType (Run-Up, ...)          |  |
   -----------------------------------   |
  | OrGroup (G0..G3)                  |  |
   -----------------------------------   |
  | pointer to next parameter         | /
   ===================================
  | SpecialParInfo                    |
   ---------------------------------- 
  | TableType (table input value)     |   
   -----------------------------------
  | uiNrOfTableRows                   |   
   -----------------------------------
  | Default input value               |   
   -----------------------------------
  | Float format (16 / 32 Bit         |   
   -----------------------------------
  | pTable (pointer to the values)    |   
   -----------------------------------
   
*/
/************************************************************************/

/*! eHEADParamMainType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head bit field available for main type parameter.

    @general main type of the parameter (scalar/table)

    @conseq [none]

    @attention [none]

    */
typedef enum 
{  
  HEADParamMainType_Scalar   = 0u,                                    /*!< parameter type is a scalar*/
  HEADParamMainType_Table    = 1u,                                    /*!< parameter type is a table*/
  HEADParamMainType_3dTable  = 2u                                     /*!< parameter type is a 3d table*/
} eHEADParamMainType_t;
typedef HEADBitField_t HEADParamMainType_t;                           /*!< @values: eHEADParamMainType_t */

/*! eHEADParamMainValueType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head bit field available for main value type.

    @general main value types (value/factor)

    @conseq [none]

    @attention [none]

    */
typedef enum
{
  HEADParamMainValueType_Value  = 0u,                              /*!< defines that the output is the real value of this parameter*/
  HEADParamMainValueType_Factor = 1u,                              /*!< defines that the output is a factor for this parameter. if a value is not defined, factors are not used!*/
  HEADParamMainValueType_Bool   = 2u                               /*!< defines that the output is a bool (>0: true, <0: false).*/
} eHEADParamMainValueType_t;
typedef HEADBitField_t HEADParamMainValueType_t;                   /*!< @values: eHEADParamMainValueType_t */


/*! eHEADHypOutType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head Hypothesis output type

    @general hypothesis output variable type

    @conseq [none]

    @attention [none]

    */
typedef enum {
  HEADHypOutType_TTC                      = 0u,           /*!< defines the TTC  CAUTION!!! TTC must be the first hyp dependent value!!!*/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  HEADHypOutType_TTB_PRE                  = 1u,           /*!< defines the TTB pre*/
  HEADHypOutType_TTB_ACUTE                = 2u,           /*!< defines the TTB acute*/
#else
  HEADHypOutType_TTB                      = 1u,           /*!< defines the TTB*/
  HEADHypOutType_Dummy                    = 2u,           /*!< defines the Dummy*/
#endif 
  HEADHypOutType_TTS_PRE                  = 3u,           /*!< defines the TTS pre*/
  HEADHypOutType_TTS_ACUTE                = 4u,           /*!< defines the TTS acute*/
  HEADHypOutType_ClosingVel               = 5u,           /*!< defines the closing velocity (m/s)*/
  HEADHypOutType_ANecLong                 = 6u,           /*!< defines the necessary longitudinal deceleration (m/s^2)*/
  HEADHypOutType_HypProb                  = 7u,           /*!< defines hypothesis probability (%)*/
  HEADHypOutType_ObjectDist               = 8u,           /*!< defines the object distance (m)*/
  HEADHypOutType_ObjProb                  = 9u,           /*!< defines hypothesis object probability (%)*/
  HEADHypOutType_TTC2                     = 10u,          /*!< defines TTC2 */
  HEADHypOutType_TTC3                     = 11u,          /*!< defines TTC3 */
  HEADHypOutType_TTC4                     = 12u,          /*!< defines TTC4 */
  HEADHypOutType_HypLifetime              = 13u,          /*!< defines hypothesis lifetime */
  HEADHypOutType_ANecLatAbs               = 14u,          /*!< defines the necessary absolut lateral deceleration (m/s^2)*/
  HEADHypOutType_VRelX                    = 15u,          /*!< defines the relative velocity (m/s)*/
  HEADHypOutType_TTMLongPre               = 16u,          /*!< Time to comfort mitigation by longitudinal acceleration to avoid a collision in 2D scenario */
  HEADHypOutType_TTMLongAcute             = 17u,          /*!< Time to emergency mitigation by longitudinal acceleration to avoid a collision in 2D scenario */
  HEADHypOutType_SensorSource             = 18u,
  HEADHypOutType_ObjectDistLat            = 19u,           /*!< defines the object lateral distance (m)*/
  HEADHypOutType_ObjectSpeed              = 20u,           /*!< defines the object velocity (m/s)*/
  HEADHypOutType_ObjectAccel              = 21u,           /*!< defines the object deceleration (m/s^2) */
 /* The application-specific parameters should always be between the general parameters and Max. */
  HEADHypOutType_CustomPar_00             = 22u,          /*!< defines application specific DEPENDENT parameter 0 */
  HEADHypOutType_CustomPar_01             = 23u,          /*!< defines application specific DEPENDENT parameter 1 */
  HEADHypOutType_CustomPar_02             = 24u,          /*!< defines application specific DEPENDENT parameter 2 */
  HEADHypOutType_CustomPar_03             = 25u,          /*!< defines application specific DEPENDENT parameter 3 */
  HEADHypOutType_CustomPar_04             = 26u,          /*!< defines application specific DEPENDENT parameter 4 */
  HEADHypOutType_CustomPar_05             = 27u,          /*!< defines application specific DEPENDENT parameter 5 */
  HEADHypOutType_CustomPar_06             = 28u,          /*!< defines application specific DEPENDENT parameter 6 */
  HEADHypOutType_CustomPar_07             = 29u,          /*!< defines application specific DEPENDENT parameter 7 */
  HEADHypOutType_CustomPar_08             = 30u,          /*!< defines application specific DEPENDENT parameter 8 */
  HEADHypOutType_CustomPar_09             = 31u,          /*!< defines application specific DEPENDENT parameter 9 */
  HEADHypOutType_CustomPar_10             = 32u,          /*!< defines application specific DEPENDENT parameter 10 */
  HEADHypOutType_CustomPar_11             = 33u,          /*!< defines application specific DEPENDENT parameter 11 */
  HEADHypOutType_TargetVelocity           = 34u,          /*!< defines Target velocity in target's driving direction  */
  HEADHypOutType_ShortestDistance         = 35u,          /*!< defines Shortest distance to target */
  HEADHypOutType_TargetAngle              = 36u,          /*!< defines Angle to target */
  HEADHypOutType_CorridorStopDistance     = 37u,          /*! */
  HEADHypOutType_ItemConfidence           = 38u,          /*!< defines Item Confidence */
  HEADHypOutType_Inlap                    = 39u,          /*!< defines Inlap at collision */
  HEADHypOutType_ImpactVelEgo             = 40u,          /*!< defines Impact Velocity Ego at collision */
  HEADHypOutType_ImpactVelRel             = 41u,          /*!< defines Impact Velocity Relative at collision */
  HEADHypOutType_Max                      = 42u           /*!< defines the maximum number of enums (must correlate to the number of bits in @ref HEADParameterType_t) <= 64*/
} eHEADHypOutType_t;      

/*! eHEADParamOutType_t */
/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head Hypothesis output type of the parameter

    @general hypothesis output variable type of the parameter

    @conseq [none]

    @attention [none]

    */
typedef enum 
{
  HEADParamOutType_None                          = 0u,
  HEADParamOutType_AllConditionsForOrGroupMet       = 1u,        /*!< defines a time where all other conditions needs to be met to activate the function - must be the first!*/  
  HEADParamOutType_OrGroupInhibition                = 2u,        /*!< defines Inhibition of hyps for an orGroup*/
  HEADParamOutType_StateActiveTime                  = 3u,        /*!< defines a time where the state must be active to go to the next state - must be the last in this enum*/
  HEADParamOutType_OtherModuleStateTime             = 4u,        /*!< defines that the parameter value defines a time another module must/must not be in a specific state to make the transition*/
  HEADParamOutType_Bool                             = 5u,        /*!< defines a bool value*/
  HEADParamOutType_EgoVelocity                      = 6u,        /*!< defines ego velocity (m/s) - hyp independend*/
  HEADParamOutType_EgoAccel                         = 7u,        /*!< defines ego acceleration (m/s*s) - hyp independend*/
  HEADParamOutType_SafeObjDistSfty                  = 8u,        /*!< defines safe object distance for safety functions (m) - hyp independend*/
  HEADParamOutType_SafeObjDistPerf                  = 9u,        /*!< defines safe object distance for performance functions (m) - hyp independend*/
  HEADParamOutType_DriverFeedbackProb               = 10u,        /*!< defines DIM Feedback Probability*/
  HEADParamOutType_DriverActivityProb               = 11u,       /*!< defines DIM Activity Probability*/
  HEADParamOutType_DriverAttentionProb              = 12u,       /*!< defines DIM Attention Probability*/
  HEADParamOutType_TTC                              = 13u,       /*!< defines the TTC*/
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  HEADParamOutType_TTB_PRE                          = 14u,       /*!< defines the TTB pre*/
  HEADParamOutType_TTB_ACUTE                        = 15u,       /*!< defines the TTB acute*/
  #else
  HEADParamOutType_TTB                              = 14u,       /*!< defines the TTB pre*/
  HEADParamOutType_Dummy                            = 15u,
  #endif 
  HEADParamOutType_TTS_PRE                          = 16u,       /*!< defines the TTS pre*/
  HEADParamOutType_TTS_ACUTE                        = 17u,       /*!< defines the TTS acute*/
  HEADParamOutType_ClosingVel                       = 18u,       /*!< defines the closing velocity (m/s)*/
  HEADParamOutType_ANecLong                         = 19u,       /*!< defines the necessary longitudinal deceleration (m/s^2)*/
  HEADParamOutType_HypProb                          = 20u,       /*!< defines hypothesis probability (%)*/
  HEADParamOutType_ObjectDist                       = 21u,       /*!< defines the object distance (m)*/
  HEADParamOutType_ObjProb                          = 22u,       /*!< defines hypothesis object probability (%)*/
  HEADParamOutType_TTC2                             = 23u,       /*!< defines TTC2 */
  HEADParamOutType_TTC3                             = 24u,       /*!< defines TTC3 */
  HEADParamOutType_TTC4                             = 25u,       /*!< defines TTC4 */
  HEADParamOutType_HypLifetime                      = 26u,       /*!< defines hypothesis lifetime */
  HEADParamOutType_ANecLatAbs                       = 27u,       /*!< defines the necessary absolut lateral deceleration (m/s^2)*/
  HEADParamOutType_VRelX                            = 28u,       /*!< defines the relative velocity (m/s)*/
  HEADParamOutType_TTMLongPre                       = 29u,       /*!< defines Time to comfort mitigation by longitudinal acceleration to avoid a collision in 2D scenario */
  HEADParamOutType_TTMLongAcute                     = 30u,       /*!< defines Time to comfort mitigation by longitudinal acceleration to avoid a collision in 2D scenario */
  HEADParamOutType_OtherOrGroupIsTrue               = 31u,       /*!< defines an other orGroup to be true*/
  HEADParamOutType_ObjectSpeed                      = 32u,       /*!< defines the object velocity (m/s) */
  HEADParamOutType_ObjectAccel                      = 33u,       /*!< defines the object deceleration (m/s^2) */

  /*PRQA S 0779 16*//*identifier is part of enum - QAC warning is ignored */
  HEADParamOutType_CustomPar_00_HypIndependent      = 34u,       /*!< defines application specific INDEPENDENT parameter 0 */
  HEADParamOutType_CustomPar_01_HypIndependent      = 35u,       /*!< defines application specific INDEPENDENT parameter 1 */
  HEADParamOutType_CustomPar_02_HypIndependent      = 36u,       /*!< defines application specific INDEPENDENT parameter 2 */
  HEADParamOutType_CustomPar_03_HypIndependent      = 37u,       /*!< defines application specific INDEPENDENT parameter 3 */
  HEADParamOutType_CustomPar_04_HypIndependent      = 38u,       /*!< defines application specific INDEPENDENT parameter 4 */
  HEADParamOutType_CustomPar_05_HypIndependent      = 39u,       /*!< defines application specific INDEPENDENT parameter 5 */
  HEADParamOutType_CustomPar_06_HypIndependent      = 40u,       /*!< defines application specific INDEPENDENT parameter 6 */
  HEADParamOutType_CustomPar_07_HypIndependent      = 41u,       /*!< defines application specific INDEPENDENT parameter 7 */
  HEADParamOutType_CustomPar_08_HypIndependent      = 42u,       /*!< defines application specific INDEPENDENT parameter 8 */
  HEADParamOutType_CustomPar_09_HypIndependent      = 43u,       /*!< defines application specific INDEPENDENT parameter 9 */
  HEADParamOutType_CustomPar_10_HypIndependent      = 44u,       /*!< defines application specific INDEPENDENT parameter 10 */
  HEADParamOutType_CustomPar_11_HypIndependent      = 45u,       /*!< defines application specific INDEPENDENT parameter 11 */
  HEADParamOutType_CustomPar_00_HypDependent        = 46u,       /*!< defines application specific DEPENDENT parameter 0 */
  HEADParamOutType_CustomPar_01_HypDependent        = 47u,       /*!< defines application specific DEPENDENT parameter 1 */
  HEADParamOutType_CustomPar_02_HypDependent        = 48u,       /*!< defines application specific DEPENDENT parameter 2 */
  HEADParamOutType_CustomPar_03_HypDependent        = 49u,       /*!< defines application specific DEPENDENT parameter 3 */
  HEADParamOutType_CustomPar_04_HypDependent        = 50u,       /*!< defines application specific DEPENDENT parameter 4 */
  HEADParamOutType_CustomPar_05_HypDependent        = 51u,       /*!< defines application specific DEPENDENT parameter 5 */
  HEADParamOutType_CustomPar_06_HypDependent        = 52u,       /*!< defines application specific DEPENDENT parameter 6 */
  HEADParamOutType_CustomPar_07_HypDependent        = 53u,       /*!< defines application specific DEPENDENT parameter 7 */
  HEADParamOutType_CustomPar_08_HypDependent        = 54u,       /*!< defines application specific DEPENDENT parameter 8 */
  HEADParamOutType_CustomPar_09_HypDependent        = 55u,       /*!< defines application specific DEPENDENT parameter 9 */
  HEADParamOutType_CustomPar_10_HypDependent        = 56u,       /*!< defines application specific DEPENDENT parameter 10 */
  HEADParamOutType_CustomPar_11_HypDependent        = 57u,       /*!< defines application specific DEPENDENT parameter 11 */
  HEADParamOutType_EgoLatCurvature                  = 58u,       /*!< defines curvature of ego trajectory */
  HEADParamOutType_SensorSource                     = 59u,       /*!< defines the sensor source of the object (e.g. Camera, Radar, Fusion,..) */
  HEADParamOutType_OtherCondGroups                  = 60u,       /*!< defines the other Condition Groups relation with the current condition group */
  HEADParamOutType_ObjectDistLat                    = 61u,       /*!< defines the object lateral distance (m)*/
  HEADParamOutType_ObjListConfig                    = 62u,       /*!< defines the sensors coded (e.g. Radar only or Radar Camera Fusion,..) */
  HEADParamOutType_TargetVelocity                   = 63u,       /*!<defines Target velocity in target's driving direction */
  HEADParamOutType_ShortestDistance                 = 64u,       /*!<defines Shortest distance to target */
  HEADParamOutType_TargetAngle                      = 65u,       /*!<defines Angle to target */
  HEADParamOutType_SteeringAngle                    = 66u,       /*! <defines SWA */
  HEADParamOutType_GasPedal                         = 67u,       /*! <defines accelerator pedal postition */
  HEADParamOutType_CorridorStopDistance             = 68u,       /*! <defines Corridor Stop Distance */
  HEADParamOutType_TurnIndicatorInSteeringDirection = 69u,       /*! <defines turn indicator */
  HEADParamOutType_Precondition                     = 70u,       /*! <defines Precondition feature */
  HEADParamOutType_EBAStateControl                  = 71u,       /*!< defines Degradation */
  HEADParamOutType_ItemConfidence                   = 72u,       /*!< defines Item confidence */
  HEADParamOutType_Inlap                            = 73u,       /*!< defines Inlap at Collision */
  HEADParamOutType_ImpactVelEgo                     = 74u,       /*!< defines Impact Velocity Ego at Collision */
  HEADParamOutType_ImpactVelRel                     = 75u,       /*!< defines Impact Velocity Relative at Collision */
  HEADParamOutType_SafetyFunctionEnableFlag         = 76u,        /*!< define the safety function flag for Enable condition*/
  HEADParamOutType_SafetyFunctionKeepFlag           = 77u,        /*!<define te safety function flag for Keep condition*/
  HEADParamOutType_Max                              = 78u        /*!< defines the maximum number of enums (must correlate to the number of bits in HEADParameterType_t) <= 127 */
 /*this enum can be extended up to 128 entries - always append new OutTypes before customs for backward compatibility*/
} eHEADParamOutType_t;
typedef HEADBitField_t HEADParamOutType_t;                 /*!< using 8bit type for the real enum (32bit type) ref eHEADParameterType_t to save memory values: eHEADParamOutType_t */


/*! @brief       for evaluation first hypo based parameter is TTC
    @general     Head parameter output type of first value  
    */
#define HEADParamOutType_FirstValue HEADParamOutType_AllConditionsForOrGroupMet


/*! eHEADParamTabType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head parameter table type

    @general [none]

    @conseq [none]

    @attention [none]

    */
typedef enum
{
  eHEADParamTabType_HostSpeed                     =  0u,      /*!< x value of the table is absolute host x speed (m/s)*/
  eHEADParamTabType_HostAccel                     =  1u,      /*!< x value of the table is absolute host x accel (m/s^2)*/
  eHEADParamTabType_Distance                      =  2u,      /*!< x value of the table is the longitudinal distance to the object (m)*/
  eHEADParamTabType_ProbAttention                 =  3u,      /*!< x value of the table is driver activity probability (%)*/
  eHEADParamTabType_ConfAttention                 =  4u,
  eHEADParamTabType_ProbFeedback                  =  5u,      /*!< x value of the table is driver feedback probability (%)*/
  eHEADParamTabType_ConfFeedback                  =  6u,
  eHEADParamTabType_ProbActivity                  =  7u,      /*!< x value of the table is driver activity probability (%)*/
  eHEADParamTabType_ConfActivity                  =  8u,
  eHEADParamTabType_HostSpeedLastStateTrans       =  9u,      /*!< x value of the table is absolute host x speed (m/s) at the time where the module was transitioning from passive to active */
  eHEADParamTabType_ClosingVelocity               = 10u,      /*!< x value of the table is the closing velocity (m/s) */
  eHEADParamTabType_VRelX                         = 11u,      /*!< x value of the table is relative velocity (m/s) */
  eHEADParamTabType_TTC                           = 12u,      /*!< x value of the table is TTC (s) */
  eHEADParamTabType_ObjListConfig                 = 13u,      /*!< x value of the table is Sensors coded (e.g. Radar only or Radar Camera Fusion,..) */
  eHEADParamTabType_ObjectSpeed                   = 14u,      /*!< x value of the table is object velocity (m/s) */
  eHEADParamTabType_ObjectAccel                   = 15u,      /*!< x value of the table is object acceleration (m/s^2) */
  eHEADParamTabType_Inlap                         = 16u,      /*!< x value of the table is Inlap (m) */
  eHEADParamTabType_ImpactVelEgo                  = 17u,      /*!< x value of the table is Impact Velocity Ego at Collision (m/s) */
  eHEADParamTabType_ImpactVelRel                  = 18u,      /*!< x value of the table is Impact Velocity Relative at Collision (m/s) */
  eHEADParamTabType_HypLifetime                   = 19u,      /*!< x value of the table is hypothesis lifetime () */
  eHEADParamTabType_CustomPar_00_HypIndependent   = 20u,      /*!< defines application specific INDEPENDENT parameter 0 */
  eHEADParamTabType_CustomPar_01_HypIndependent   = 21u,      /*!< defines application specific INDEPENDENT parameter 1 */
  eHEADParamTabType_CustomPar_02_HypIndependent   = 22u,      /*!< defines application specific INDEPENDENT parameter 2 */
  eHEADParamTabType_CustomPar_03_HypIndependent   = 23u,      /*!< defines application specific INDEPENDENT parameter 3 */
  eHEADParamTabType_CustomPar_04_HypIndependent   = 24u,      /*!< defines application specific INDEPENDENT parameter 4 */
  eHEADParamTabType_CustomPar_05_HypIndependent   = 25u,      /*!< defines application specific INDEPENDENT parameter 5 */
  eHEADParamTabType_CustomPar_06_HypIndependent   = 26u,      /*!< defines application specific INDEPENDENT parameter 6 */
  eHEADParamTabType_CustomPar_07_HypIndependent   = 27u,      /*!< defines application specific INDEPENDENT parameter 7 */
  eHEADParamTabType_CustomPar_08_HypIndependent   = 28u,      /*!< defines application specific INDEPENDENT parameter 8 */
  eHEADParamTabType_CustomPar_09_HypIndependent   = 29u,      /*!< defines application specific INDEPENDENT parameter 9 */
  eHEADParamTabType_CustomPar_10_HypIndependent   = 30u,      /*!< defines application specific INDEPENDENT parameter 10 */
  eHEADParamTabType_CustomPar_11_HypIndependent   = 31u,      /*!< defines application specific INDEPENDENT parameter 11 */
  /*PRQA S 0779 8*//*identifier is part of enum - QAC warning is ignored */
  eHEADParamTabType_CustomPar_00_HypDependent     = 32u,      /*!< defines application specific DEPENDENT parameter 0 */
  eHEADParamTabType_CustomPar_01_HypDependent     = 33u,      /*!< defines application specific DEPENDENT parameter 1 */
  eHEADParamTabType_CustomPar_02_HypDependent     = 34u,      /*!< defines application specific DEPENDENT parameter 2 */
  eHEADParamTabType_CustomPar_03_HypDependent     = 35u,      /*!< defines application specific DEPENDENT parameter 3 */
  eHEADParamTabType_CustomPar_04_HypDependent     = 36u,      /*!< defines application specific DEPENDENT parameter 4 */
  eHEADParamTabType_CustomPar_05_HypDependent     = 37u,      /*!< defines application specific DEPENDENT parameter 5 */
  eHEADParamTabType_CustomPar_06_HypDependent     = 38u,      /*!< defines application specific DEPENDENT parameter 6 */
  eHEADParamTabType_CustomPar_07_HypDependent     = 39u,      /*!< defines application specific DEPENDENT parameter 7 */
  eHEADParamTabType_CustomPar_08_HypDependent     = 40u,      /*!< defines application specific DEPENDENT parameter 8 */
  eHEADParamTabType_CustomPar_09_HypDependent     = 41u,      /*!< defines application specific DEPENDENT parameter 9 */
  eHEADParamTabType_CustomPar_10_HypDependent     = 42u,      /*!< defines application specific DEPENDENT parameter 10 */
  eHEADParamTabType_CustomPar_11_HypDependent     = 43u       /*!< defines application specific DEPENDENT parameter 11 */
} eHEADParamTabType_t;  
typedef uint8 HEADParamTableType_t;                       /*!< using 8bit type for the real enum (32bit type) @ref eHEADParamTabType_t to save memory @values: eHEADParamTabType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief this structure defines all input variable that are used for table inputs (x) which cannot be provided from current input data

    @general Head additional table input values availalbe with host speed last state

    @conseq [none]

    @attention TODO Rework Concept => These Variables should be handled in non-generic part
    */
typedef struct  
{
  float32 fHostSpeedLastStateTransition;                       /*!< Defines the ego velocity at the beginning of the last state transition */  
  boolean bHostSpeedLastStateTransitionOK;                     /*!< Defines the ego velocity at the beginning of the last state transition signal state */  
} HEADAdditionalTableInputValues_t;

/* ****************************************************************
    TYPEDEF ENUM eHEADMainMode_t
    **************************************************************** */
/*! @brief These values are used to address Bits in bit-fields. Make sure values are within bounds 

    @general definition of internal head modes

    @conseq [none]

    @attention [none]

    */
typedef enum 
{
  HEADMainMode_Early  = 0u,                                         /*!< defines the HEAD internal mode EARLY*/
  HEADMainMode_Middle = 1u,                                         /*!< defines the HEAD internal mode MIDDLE*/
  HEADMainMode_Late   = 2u,                                         /*!< defines the HEAD internal mode LATE*/
  HEADMainMode_ACC    = 3u,                                         /*!< defines the HEAD internal mode ACC*/
  HEADMainMode_Max    = 4u                                          /*!< counts the values in this enum*/
} eHEADMainMode_t;

/* ****************************************************************
    TYPEDEF ENUM HEADMainMode_t
    **************************************************************** */
/*! @brief These values are used to address Bits in bit-fields. Make sure values are within bounds 

    @general definition of internal head modes

    @conseq [none]

    @attention [none]

    */
typedef uint8 HEADMainMode_t;                                       /*!< @values: eHEADMainMode_t */

/* ****************************************************************
    TYPEDEF ENUM HEADParameterMode_t
    **************************************************************** */
/*! @brief These values are used to address fields in bit-fields. Make sure values are within bounds 

    @general definition of internal head fields

    @conseq [none]

    @attention [none]

    */
typedef HEADBitField_t HEADParameterMode_t;

/* ****************************************************************
    TYPEDEF ENUM HEADParameterHypothesisSub_t
    **************************************************************** */
/*! @brief Head bit field for head parameter hypothesis sub.

    @general [none]

    @conseq [none]

    @attention [none]

    */
typedef HEADBitField_t HEADParameterHypothesisSub_t;

/* ****************************************************************
    TYPEDEF ENUM HEADParameterSensorSourceSub_t
    **************************************************************** */
/*! @brief Head bit field for head parameter sensor source sub.

    @general [none]

    @conseq [none]

    @attention [none]

    */
typedef HEADBitField_t HEADParameterSensorSourceSub_t;

/*! eHEADParameterState_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief These values are used to address Bits in bit-fields. Make sure values are within bounds 

    @general definition of head parameters for mode transitions

    @conseq [none]

    @attention [none]

    */
typedef enum 
{
  HEADParameterState_KeepPassive  = 0u,                             /*!< defines the HEAD transition state KeepPassive*/  
  HEADParameterState_Enable       = 1u,                             /*!< defines the HEAD transition state ENABLE*/
  HEADParameterState_KeepActive   = 2u,                             /*!< defines the HEAD transition state KeepACTIVE*/
  HEADParameterState_LeaveActive  = 3u,                             /*!< defines the HEAD transition state LeaveACTIVE*/
  HEADParameterState_KeepWait     = 4u,                             /*!< defines the HEAD transition state KeepWAIT*/
  HEADParameterState_LeaveWait    = 5u,                             /*!< defines the HEAD transition state LeaveWAIT*/
  HEADParameterState_Init         = 6u,                             /*!< defines the HEAD transition state INIT*/
  HEADParameterState_Max          = 7u                              /*!< counts the values in this enum*/
} eHEADParameterState_t;
typedef HEADBitField_t HEADParameterState_t;                        /*!< @values: eHEADParameterState_t */

/*! eHEADParamOperator_t */
/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief head parameter operator for mathematic operation

    @general < operator type (</>)

    @conseq [none]

    @attention [none]

    */
typedef enum 
{
  HEADParamOperator_LESSTHAN    = 0u,                           /*!< "<" value must be less than parameter*/
  HEADParamOperator_GREATERTHAN = 1u,                           /*!< ">" value must be greater than parameter*/
  HEADParamOperator_DEFAULT     = 2u                            /*!< defines to use the output value specific operator (e.g. TTC -> "<", aneclat -> ">")*/
} eHEADParamOperator_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head bit field for parameter operation

    @general < operator type (</>)

    @conseq [none]

    @attention [none]

    */
typedef HEADBitField_t HEADParamOperator_t;                     /*!< @values: eHEADParamOperator_t */

/*! eHEADSensorSourceCheckType_t */
/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
    /*! @brief head sensor source check type

        @general defines the evaluation of sensor detection

        @conseq [none]

        @attention [none]

        */
typedef enum
{
    HEADSensorCheckType_Exact = 0u,                           /*!< Sensor source should be exactly matched*/
    HEADSensorCheckType_AtLeast = 1u,                         /*!< Sensor source should match with atleast all selected configured source*/
    HEADSensorCheckType_OR = 2u                               /*!< Sensor source should match with any one of the selected source*/
} eHEADSensorSourceCheckType_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
    /*! @brief head sensor source check type

        @general defines the evaluation of sensor detection

        @conseq [none]

        @attention [none]

        */
typedef HEADBitField_t HEADSensorSourceCheckType_t;                     /*!< @values: eHEADSensorSourceCheckType_t */

/*! eHEADPreConditionCheckType_t */
/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
    /*! @brief head precondition check type

        @general defines the evaluation of precondition

        @conseq [none]

        @attention [none]

        */
typedef enum
{
    HEADPreCondCheckType_Normal = 0u,                           /*!< Normal*/
    HEADPreCondCheckType_NewHypothesisEntryCheck = 1u          /*!< on new hypothesis keep active entry condition*/
} eHEADPreConditionCheckType_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
    /*! @brief head precondition check type

        @general defines the evaluation of precondition

        @conseq [none]

        @attention [none]

        */
typedef HEADBitField_t HEADPreConditionCheckType_t;                     /*!< @values: eHEADPreConditionCheckType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head bit field for head parameter individual or group

    @general < operator type (</>)

    @conseq [none]

    @attention [none]

    */
typedef HEADBitField_t HEADParameterOrGroup_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head bit field for head transition condition groups

    @general Currently maximum 8 condition groups are available for a transition

    @conseq [none]

    @attention [none]

    */
typedef uint8 HEADCondGrpBitField_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head bit field for head eba object class

    @general < operator type (</>)

    @conseq [none]

    @attention [none]

    */
typedef HEADBitField_t HEADEBAObjectClass_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head bit field for head eba dynamic properties

    @general < operator type (</>)

    @conseq [none]

    @attention [none]

    */
typedef HEADBitField_t HEADEBADynProp_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Head bit field for head eba object movement direction
    */
typedef HEADBitField_t HEADEBAObjMovDir_t;


/* ****************************************************************
    TYPEDEF 
    **************************************************************** */
/*! @brief Head bit field for head parameter other condition group timer identification

    @general [none]

    @conseq [none]

    @attention [none]

    */
 #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
typedef uint32 HEADParamCondGrpTimerBitField_t;
#else
typedef uint8 HEADParamCondGrpTimerBitField_t;
#endif




/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief Head parameter other condition group timer identification structure

    @general [none]

    @conseq [none]

    @attention [none]

    */
typedef struct /*PRQA S 0635 5*/ /*QAC message suppressed*/
{
  HEADParamCondGrpTimerBitField_t   TransNr       :4;   /*!< transition no. to which timer is assigned */
  HEADParamCondGrpTimerBitField_t   CondGrpNr     :4;   /*!< condition group no. to which timer is assigned */
} HEADParamCondGrpTimerId_t;


/* ****************************************************************
    TYPEDEF STRUCT HEADParamCondGrpTimer_t
    **************************************************************** */
/*! @brief Head parameter timer for counting other condition groups TRUE/FALSE time

    @general [none]

    @conseq [none]

    @attention [none]

    */
typedef struct  
{
  float32                         fTimerVal;             /*!< timer value */  
  HEADParamCondGrpTimerId_t       sTimerId;              /*!< timer identification when allocated during runtime */  
} HEADParamCondGrpTimer_t;


/* ****************************************************************
    TYPEDEF STRUCT HEADParamCondGrpTimerList_t
    **************************************************************** */
/*! @brief Head parameter timers list for a particular module

    @general [none]

    @conseq [none]

    @attention [none]

    */
typedef struct  
{
  HEADParamCondGrpTimer_t         *pCondGrpTimer;             /*!< pointer to timers list used to evaluate conditions of OutType(HEADParamOutType_OtherCondGroups)*/  
  uint8                            uiNumTotalCGTimers;        /*!< Total number of timers allocated to evaluate conditions of OutType(HEADParamOutType_OtherCondGroups) */  
  uint8                            uiNumUsedCGTimers;         /*!< Number of timers used for the current module evaluation */
} HEADParamCondGrpTimerList_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief Head parameter empty struct for head parameter empty

    @general [none]

    @conseq [none]

    @attention [none]

    */
typedef struct  
{
  /*generic parameter information*/
  HEADParamMainType_t            ParamMainType        : 2;          /*!< 2 (Offset 0+0) bits for main type (none, scalar, table, 3dtable) @values: eHEADParamMainValueType_t @unit:none|scalar|table*/
  HEADParamMainValueType_t       ParamMainValueType   : 1;          /*!< 1 (Offset 0+2) bit  for (value, factor) - defines the type of the parameter @unit:val|fac|bool*/
  HEADParamOperator_t            ParamOperator        : 1;          /*!< 1 (Offset 0+3) bit for the operator (</>) @unit:less|greater*/
  /*head specific parameter information*/
  HEADParamOutType_t             ParamOutType         : 7;          /*!< 7 (Offset 0+4) bits for OutType (128 different types like TTC, ModuleConditionEgoVel...) */
  HEADParameterState_t           Padding1             : 6;          /*!< 6 (Offset 0+11) bits */ 
  HEADParameterMode_t            ParameterMode        : 4;          /*!< 4 (Offset 0+17) bits - one BIT for every driver preference setting (early, middle, late, acc) @unit:Early|Middle|Late|ACC*/
  HEADParameterOrGroup_t         ParameterOrGroup     : 3;          /*!< 3 (Offset 0+21) bits - or group - OR(AND(all Group 0 parameters), AND(all Group 1 parameters),...),@unit:0-8*/
  HEADEBAObjectClass_t           ParamObjectClass     : 4;          /*!< 4 (Offset 0+24) bits for object class (Veh, Ped, Cycl, Obst) */
  HEADEBADynProp_t               ParamDynProp         : 2;          /*!< 2 (Offset 0+28) bits for object dynamic property (Moving/Stat) */
  HEADBitField_t                 Padding2             : 2;          /*!< 2 (Offset 0+30) bits */
  HEADParameterHypothesisSub_t   ParameterHypSubType  : 32;         /*!< 32(Offset 1+0)  bits - one BIT for every Hypothesis (HEADParameterHypothesisBit(xxx)|...|...) @unit:hyptype*/
  HEADParameterSensorSourceSub_t ParamSensorSource    : 8;          /*!< 8 (Offset 2+0)  bits -  8 bits for each sensor type */
  HEADEBAObjMovDir_t             ParamObjMovDir       : 3;          /*!< 3 (Offset 2+8)  bits for object movement direction @unit DoT|Crossing|Oncoming|None */
  HEADBitField_t                 Padding3             : 21;         /*!< 21(Offset 2+11) bits */
} HEADParameterType_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief Head parameter empty struct for parameter arr.
    @general [none]

    @conseq [none]

    @attention [none]

    */
typedef struct HEADParameterEmptyStruct HEADParameterEmpty_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief Head parameter header for implementing head parameter.

    @general [none]

    @conseq [none]

    @attention [none]

    */
typedef struct 
{
  HEADParameterType_t       sParameterType;                   /*!<next list element*/
  HEADParameterEmpty_t *    pNextParam;                       /*!< pointer to next parameter*/
  HEADParameterEmpty_t *    pNextRelevantParam;               /*!< pointer to the next relevant parameter*/
} HEADParameterHeader_t;

/*-- different parameter definitions -> each parameter definition MUST have HEADParameterHeader_t at the beginning*/

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief different parameter definitions -> each parameter definition MUST have HEADParameterHeader_t at the beginning

    @general could contain special (@ref eHEADParamOutType_t dependent) information
    
    @conseq [none]

    @attention [none]

    */
typedef uint16 HEADBitPack_t; /*!< could contain special (@ref eHEADParamOutType_t dependent) information*/


/*parameter definition for an empty parameter*/

/* ****************************************************************
    STRUCT HEADParameterEmptyStruct
    **************************************************************** */
/*! @brief HEAD Parameter Empty Structure

    @general HEAD Parameter Empty Structure
    
    @conseq [none]

    @attention [none]

    */
struct HEADParameterEmptyStruct 
{
  HEADParameterHeader_t   ParameterType;                        /*!< defines the type of the parameter - must be at the beginning (ParameterType.ParamMainType must be HEADParamMainType_Empty)*/
  HEADBitPack_t           uiSpecialParInfo;                     /*!< could ontain special (eHEADParamOutType_t dependent) information*/
};


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief Head parameter scaler

    @general parameter definition for scalar values
    
    @conseq [none]

    @attention [none]

    */
typedef struct  
{
  HEADParameterHeader_t     ParameterType;                       /*!< defines the type of the parameter - must be at the beginning (ParameterType.ParamMainType must be HEADParamMainType_Scalar)*/
  HEADBitPack_t             uiSpecialParInfo;                    /*!< could contain special (eHEADParamOutType_t dependent) information*/
  /*scalar specific information*/
  f16_t                     f16RawValue;                         /*!< the raw value -> must be divided by ParameterType.ParamScaleType scaling*/
} HEADParameterScalar_t;


/*! eHEADParameterTableFloatType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head parameter table float type values

    @general parameter definition for scalar values
    
    @conseq [none]

    @attention [none]

    */
typedef enum
{
  HEADParameterTableFloatType_f16 = 0u,
  HEADParameterTableFloatType_f32 = 1u
} eHEADParameterTableFloatType_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Head parameter table float type values

    @general parameter definition for scalar values
    
    @conseq [none]

    @attention [none]

    */
typedef enum
{
  HEADParam3DTableX2Type_Analog = 0u,
  HEADParam3DTableX2Type_Discrete = 1u
} eHEADParam3DTableX2Type_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief parameter definition for table values

    @general [none]
    
    @conseq [none]

    @attention [none]

    */
typedef struct  
{
  HEADParameterHeader_t          ParameterType;                      /*!< defines the type of the parameter - must be at the beginning (ParameterType.ParamMainType must be HEADParamMainType_Table)*/
  HEADBitPack_t                  uiSpecialParInfo;                   /*!< could contain special (eHEADParamOutType_t dependent) information*/                                
  /*table specific information*/
  HEADParamTableType_t           TableType;                          /*!< defines specific table type (input vector type) */
  uint8                          uiNrOfTableRows;                    /*!< defines the number of table rows*/  
  f16_t                          f16DefaultValue;                    /*!< default value (for the input) if table input cannot be found*/
  eHEADParameterTableFloatType_t eTableFloatType;                    /*!< defines the type of the pTable values*/  
  const void                     *pTable;                            /*!< pointer to the table containing 2*uiNrOfTableRows values (x0,y0,x1,y1,...xn,yn)*/
} HEADParameterTable_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief parameter definition for 3D table values

    @general [none]
    
    @conseq [none]

    @attention [none]

    */
typedef struct  
{
  HEADParameterHeader_t          ParameterType;                      /*!< defines the type of the parameter - must be at the beginning (ParameterType.ParamMainType must be HEADParamMainType_Table)*/
  HEADBitPack_t                  uiSpecialParInfo;                   /*!< could contain special (eHEADParamOutType_t dependent) information*/                                
  /*table specific information*/
  HEADParamTableType_t           TableType1;                         /*!< defines specific table type (input vector type X1) */
  HEADParamTableType_t           TableType2;                         /*!< defines specific table type (input vector type X2) */
  uint8                          uiNrOfTableRows;                    /*!< defines the number of table rows*/
  uint8                          uiNrOfTableCols;                    /*!< defines the number of table cols*/
  f16_t                          f16DefaultValX1;                    /*!< default value (for the input X1) if table input cannot be found*/
  f16_t                          f16DefaultValX2;                    /*!< default value (for the input X2) if table input cannot be found*/
  eHEADParam3DTableX2Type_t      X2SignalType;                       /* indicates whether second (X2) signal selected for 3-D table is analog or discrete */
  boolean                        X2DefaultResult;                    /* This is default result (enabled/disabled) of condition incase X2 is discrete and value is not found in table configured. */
  eHEADParameterTableFloatType_t eTableFloatType;                    /*!< defines the type of the pTable values*/  
  const void                     *pTable;                            /*!< pointer to the table containing (uiNrOfTableRows+1)*(uiNrOfTableCols) values (x0,y0,x1,y1,...xn,yn)*/
} HEADParameterTable3D_t;

typedef uint8 HEADParamTableType3D_t; 

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief head MTS parameter data

    @general [none]
    
    @conseq [none]

    @attention [none]

    */
typedef struct  /*PRQA S 0635 40*/ /*QAC message suppressed*/
{
  /*HEADER Information*/
  HEADBitField_t        bParamValid           :1;              /*!< defines if to following information is valid or not @unit:bool*/
  HEADBitField_t        uiModuleNr            :7;              /*!< defines to which module the parameter belongs @name:ModuleNr*/
  HEADBitField_t        uiParNr               :16;             /*!< defines the nr of the parameter in this module @name:ParameterNr*/
  HEADBitField_t        uiTablePos            :8;              /*!< since tables are transfered as parts (n rows per cycle, this value defines the last row) @name:TableRowOffset*/
 #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
  HEADBitField_t        uiStateNr             :6;              /*!< defines to which state of a module the parameter belongs @name:StateNr*/
  HEADBitField_t        uiTransNr             :5;              /*!< defines to which transition of a particular state the parameter belongs @name:TransNr*/
  HEADBitField_t        uiCondGrpNr           :5;              /*!< defines to which condition group of a particular transition the parameter belongs @name:CondGrpNr*/
  HEADParameterType_t   sParameterHeader;                      /*!< stores the parameter header information @name:ParameterHeader*/
  HEADBitField_t        uiSpecialParInfo;                      /*!< @name:BitPack*/
 #else
  HEADBitPack_t         uiStateNr             :6;              /*!< defines to which state of a module the parameter belongs @name:StateNr*/
  HEADBitPack_t         uiTransNr             :5;              /*!< defines to which transition of a particular state the parameter belongs @name:TransNr*/
  HEADBitPack_t         uiCondGrpNr           :5;              /*!< defines to which condition group of a particular transition the parameter belongs @name:CondGrpNr*/
  HEADParameterType_t   sParameterHeader;                      /*!< stores the parameter header information @name:ParameterHeader*/
  HEADBitPack_t         uiSpecialParInfo;                      /*!< @name:BitPack*/
 #endif
  /*table parameter information*/
  uint8                 uiNrOfTableRows;                       /*!< table rows in case of a parameter table*/
  HEADParamTableType_t  eTableType;                            /*!< table type in case of a parameter table*/  
  /*scalar or table parameter information*/
  float32               fScalarValue_DefaultX;                 /*!< stores the scalar value in case of a scalar parameter or the defaultX value in case of a table*/
  /*table itself*/
  float32               fTable[2u*HEAD_MTS_MAX_TABLE_ROWS];    /*!< part of the values in case of a parameter table*/

  /*3d table*/
  float32               fScalarValue_DefaultX1;                 /*!< stores the scalar value in case of a scalar parameter or the defaultX1 value in case of a 3d-table*/
  float32               fScalarValue_DefaultX2;                 /*!< stores the scalar value in case of a scalar parameter or the defaultX2 value in case of a 3d-table*/
  float32               fTable3d[(HEAD_MTS_MAX_3D_TABLE_ROWS + 1u)*HEAD_MTS_MAX_TABLE_COLUMNS];
  uint8                 uiNrOfTableCols;
  HEADParamTableType3D_t  eTableType2;
  eHEADParam3DTableX2Type_t X2SignalTyp;                        /* Obtain whether it is Discrete or Continuous*/
} HEADMTSParameterData_t;


#if (HEAD_CFG_PRECONDITION)
/* ****************************************************************
TYPEDEF STRUCT
**************************************************************** */
/*! @brief head MTS pre condition parameter data

@general [none]

@conseq [none]

@attention [none]

*/
typedef struct
{
  /*HEADER Information*/
  HEADBitField_t            bParamValid : 1;                       /*!< defines if to following information is valid or not @unit:bool*/
  HEADBitField_t            uiParNr : 16;                          /*!< defines the nr of the parameter in this precondition @name:ParameterNr*/
  HEADBitField_t            uiTablePos : 8;                        /*!< since tables are transfered as parts (n rows per cycle, this value defines the last row) @name:TableRowOffset*/
  HEADBitField_t            uiPreCondNr : 6;                       /*!< defines to which precondition group the parameter belongs @name:PreCondNr*/
  HEADBitField_t            Padding1 : 1;                          /*!<  @name:Padding1*/
  HEADParameterType_t       sParameterHeader;                      /*!< stores the parameter header information @name:ParameterHeader*/
  HEADBitField_t            uiSpecialParInfo;                      /*!< @name:BitPack*/
  uint8                     uiNrOfTableRows;                       /*!< table rows in case of a parameter table*/
  HEADParamTableType_t      eTableType;                            /*!< table type in case of a parameter table*/
                                                                   /*scalar or table parameter information*/
  float32                   fScalarValue_DefaultX;                 /*!< stores the scalar value in case of a scalar parameter or the defaultX value in case of a table*/
/*table itself*/
  float32                   fTable[2u * HEAD_MTS_MAX_TABLE_ROWS];  /*!< part of the values in case of a parameter table*/

/*3d table*/
  float32                   fScalarValue_DefaultX1;                /*!< stores the scalar value in case of a scalar parameter or the defaultX1 value in case of a 3d-table*/
  float32                   fScalarValue_DefaultX2;                /*!< stores the scalar value in case of a scalar parameter or the defaultX2 value in case of a 3d-table*/
  float32                   fTable3d[(HEAD_MTS_MAX_3D_TABLE_ROWS + 1u)*HEAD_MTS_MAX_TABLE_COLUMNS];
  uint8                     uiNrOfTableCols;
  HEADParamTableType3D_t    eTableType2;
  eHEADParam3DTableX2Type_t X2SignalTyp;                        /* Obtain whether it is Discrete or Continuous*/
} HEADMTSPreCondParameterData_t;
#endif /*

*/
/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* HEAD20_PAR_DEF_H_INCLUDED */

