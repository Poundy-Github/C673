/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_parameter_def.h

DESCRIPTION:               Header of the HEAD component - for parameter definition

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/17 13:52:55CEST $

VERSION:                   $Revision: 1.15 $

LEGACY VERSION:            1.44

**************************************************************************** */
/**
@ingroup head
@{ **/
#ifndef HEAD_PARAMETER_DEF_H_INCLUDED
#define HEAD_PARAMETER_DEF_H_INCLUDED
/*** START OF SINGLE INCLUDE SECTION ****************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/*! @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*! @endcond */

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! @brief          Max. allowed value due to half precision floating point range
    @description    This value related to raw in head parameter, stat upper limit because of half precision floating point range.
    @typical        [none]   @unit [none]     @min 0   @max 65500   */
#define HEADParameterRawValue_Max (65500)  /* Max. allowed value due to half precision floating point range  */

/* parameter definition for tables */

/*! @brief          Definition of table type for Host speed
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_HostSpeed                  ((HEADParamTableType_t) eHEADParamTabType_HostSpeed)

/*! @brief          Definition of table type for Host Accel.
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none]   */
#define HEADParamTableType_HostAccel                  ((HEADParamTableType_t) eHEADParamTabType_HostAccel)

/*! @brief          Definition of table type for Host Distance
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_Distance                   ((HEADParamTableType_t) eHEADParamTabType_Distance)

/*! @brief       	Definition of table type for lateral distance
    @attention   	Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical     	[none]   @unit [none] */
#define HEADParamTableType_DistanceLat                ((HEADParamTableType_t) eHEADParamTabType_DistanceLat)

/*! @brief          Definition of table type for Driver Attention
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_DriverAttention            ((HEADParamTableType_t) eHEADParamTabType_ProbAttention)

/*! @brief          Definition of table type for Driver Feedback
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_DriverFeedback             ((HEADParamTableType_t) eHEADParamTabType_ProbFeedback) 

/*! @brief          Definition of table type for Driver Activity
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_DriverActivity             ((HEADParamTableType_t) eHEADParamTabType_ProbActivity) 

/*! @brief          Definition of table type for Host Speed's last state transaction.
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_HostSpeedLastStateTrans    ((HEADParamTableType_t) eHEADParamTabType_HostSpeedLastStateTrans)

/*! @brief          Definition of table type for Closing velocity
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none]  */
#define HEADParamTableType_ClosingVelocity            ((HEADParamTableType_t) eHEADParamTabType_ClosingVelocity)

/*! @brief          Definition of table type for VRel X
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_VRelX                      ((HEADParamTableType_t) eHEADParamTabType_VRelX)
   
/*! @brief          Definition of table type for Customer Parameter 00 Hyp. dependent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_00_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_00_HypDependent)

/*! @brief          Definition of table type for Customer Parameter 01 Hyp. dependent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_01_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_01_HypDependent)

/*! @brief          Definition of table type for Customer Parameter 02 Hyp. dependent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_CustomPar_02_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_02_HypDependent)

/*! @brief          Definition of table type for Customer Parameter 03 Hyp. dependent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_03_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_03_HypDependent)

/*! @brief          Definition of table type for Customer Parameter 04 Hyp. dependent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_04_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_04_HypDependent)

/*! @brief          Definition of table type for Customer Parameter 05 Hyp. dependent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_CustomPar_05_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_05_HypDependent)

/*! @brief          Definition of table type for Customer Parameter 06 Hyp. dependent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_CustomPar_06_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_06_HypDependent)

/*! @brief          Definition of table type for Customer Parameter 07 Hyp. dependent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_CustomPar_07_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_07_HypDependent)

#define HEADParamTableType_CustomPar_08_HypDependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_08_HypDependent)

/*! @brief          Definition of table type for Customer Parameter 00 Hyp. independent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_CustomPar_00_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_00_HypIndependent)

/*! @brief          Definition of table type for Customer Parameter 01 Hyp. independent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_CustomPar_01_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_01_HypIndependent)

/*! @brief          Definition of table type for Customer Parameter 02 Hyp. independent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_CustomPar_02_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_02_HypIndependent)

/*! @brief          Definition of table type for Customer Parameter 03 Hyp. independent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_CustomPar_03_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_03_HypIndependent)

/*! @brief          Definition of table type for Customer Parameter 04 Hyp. independent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_CustomPar_04_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_04_HypIndependent)

/*! @brief           Definition of table type for Customer Parameter 05 Hyp. independent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_05_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_05_HypIndependent)

/*! @brief          Definition of table type for Customer Parameter 06 Hyp. independent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none]  */
#define HEADParamTableType_CustomPar_06_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_06_HypIndependent)

/*! @brief          Definition of table type for Customer Parameter 07 Hyp. independent
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParamTableType_CustomPar_07_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_07_HypIndependent)
#define HEADParamTableType_CustomPar_08_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_08_HypIndependent)
#define HEADParamTableType_CustomPar_09_HypIndependent     ((HEADParamTableType_t) eHEADParamTabType_CustomPar_09_HypIndependent)

/*! @brief          Definition use as function to call and set parameter mode for all bit
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none]  */
#define HEADParameterModeBit(mode)  (1u<<((HEADParameterMode_t)(mode)))

/*! @brief          Definition Of head parameter Mode early 
    @description    Definition Of head parameter Mode early, This macro use a Other Macro definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterMode_Early     (HEADParameterModeBit(HEADMainMode_Early))

/*! @brief          Definition Of head parameter Mode Middle
    @description    Definition Of head parameter Mode Middle, This macro use a Other Macro definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterMode_Middle    (HEADParameterModeBit(HEADMainMode_Middle))

/*! @brief          Definition Of head parameter Mode late
    @description    Definition Of head parameter Mode late, This macro use a Other Macro definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterMode_Late      (HEADParameterModeBit(HEADMainMode_Late))

/*! @brief          Definition Of head parameter Mode ACC
    @description    Definition Of head parameter Mode ACC, This macro use a Other Macro Definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterMode_ACC       (HEADParameterModeBit(HEADMainMode_ACC))

/*! @brief          Definition Of head parameter Mode for all
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro and done bit wise or operation over it.
    @typical        [none]   @unit [none] */
#define HEADParameterMode_All       (HEADParameterMode_Early|HEADParameterMode_Middle|HEADParameterMode_Late|HEADParameterMode_ACC)

/*! @brief          Definition use as function to call and set State mode for all bit
    @attention      Type of Macro is HEADParamTableType_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterStateBit(state)      (1u<<((HEADParameterState_t)(state)))

/*! @brief          Definition Of head parameter state for keep passive bit
    @description    Definition Of head parameter state for keep passive bit, This macro use a Other Macro Definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterState_KeepPassiveBit (HEADParameterStateBit(HEADParameterState_KeepPassive))

/*! @brief          Definition Of head parameter state for enable bit
    @description    Definition Of head parameter state for enable bit, This macro use a Other Macro Definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterState_EnableBit      (HEADParameterStateBit(HEADParameterState_Enable))

/*! @brief          Definition Of head parameter state for keep active bit
    @description    Definition Of head parameter state for keep active bit, This macro use a Other Macro Definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterState_KeepActiveBit  (HEADParameterStateBit(HEADParameterState_KeepActive))

/*! @brief          Definition Of head parameter state for leave active bit
    @description    Definition Of head parameter state for leave active bit, This macro use a Other Macro Definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterState_LeaveActiveBit (HEADParameterStateBit(HEADParameterState_LeaveActive))

/*! @brief          Definition Of head parameter state for keep wait bit
    @description    Definition Of head parameter state for keep wait bit, This macro use a Other Macro Definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterState_KeepWaitBit    (HEADParameterStateBit(HEADParameterState_KeepWait))

/*! @brief          Definition Of head parameter state for leave wait bit
    @description    Definition Of head parameter state for leave wait bit, This macro use a Other Macro Definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none]  */
#define HEADParameterState_LeaveWaitBit   (HEADParameterStateBit(HEADParameterState_LeaveWait))

/*! @brief          Definition Of head parameter state for state init bit
    @description    Definition Of head parameter state for state init bit, This macro use a Other Macro Definition by calling 
                    HEADParameterModeBit for bit wise left shift operation
    @attention      Type of Macro is HEADParameterState_t, as enum variable is assigned to macro
    @typical        [none]   @unit [none] */
#define HEADParameterState_InitBit        (HEADParameterStateBit(HEADParameterState_Init))

/*! @brief          Definition Of head parameter state for all bit
    @attention      Type of Macro is HEADParameterState_t, as enum variable is assigned to macro, and bitwise or operation done over it to get macro for all combine in one.
    @typical        [none]   @unit [none] */
#define HEADParameterState_AllBits        (HEADParameterState_KeepPassiveBit|HEADParameterState_EnableBit|HEADParameterState_KeepActiveBit|HEADParameterState_LeaveActiveBit|HEADParameterState_KeepWaitBit|HEADParameterState_LeaveWaitBit|HEADParameterState_InitBit)

/*! @brief          Definition Of head MTS maximum table row
    @description    mts output for parameters
    @typical        [none]   @unit [none]     @min 0   @max 65535   */
#define HEAD_MTS_MAX_TABLE_ROWS (4u)

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! @brief          Definition for Head parameter hypothesis bit
    @description    This Macro will do simple bitwise shift operation over hypothesis variable and typecast with enum variable
    @attention      Type of Macro is HEADParameterHypothesisSub_t, as enum variable is assigned to macro.
    @typical        [none]   @unit [none] */
#define HEADParameterHypothesisBit(hypothesis)  ((HEADParameterHypothesisSub_t)(1u<<((uint32)(hypothesis)-1u)))

/*! @brief          Definition Of head parameter hypothesis of all bits
    @description    This Macro will do simple bitwise shift operation over hypothesis variable and typecast with enum variable
    @attention      Type of Macro is HEADParameterHypothesisSub_t, as enum variable is assigned to macro.
    @typical        [none]   @unit [none] */
#define HEADParameterHypothesisAllBits(hypothesis_max) (HEADParameterHypothesisSub_t)((1u<<(hypothesis_max)-1)-1)

/*! @brief          Definition Of head parameter of hypothesis for independent elements.
    @attention      Type of Macro is HEADParameterHypothesisSub_t, as enum variable is assigned to macro.
    @typical        [none]   @unit [none]  */
#define HEADParameterHypothesisIndependent ((HEADParameterHypothesisSub_t)0)

/*! @brief          Definition Of Head other module state time to bit pack
    @description    creates a 1|2|5 bit structure of the information (in state [1], not in state [0]) (module state [off, passive, active, wait]) (modulenr+1)
    @typical        [none]   @unit [none] */
#define HEADOtherModuleStateTime2BitPack(ModuleNr, ModulState, bInState) \
  ((uint16)(( (((bInState) & 1u) << 7u) | ((ModulState) << 5u) | ((ModuleNr)))))

/*! @brief          Definition Of head bit pack to other module state time module near
    @typical        [none]   @unit [none]     @min 0 @max 255  */
#define HEADBitPackToOtherModuleStateTime_ModuleNr(bitpack)    ((uint8)((bitpack)&0x1fu))

/*! @brief          Definition Of head bit pack to other module state time module state.
    @attention      Type of Macro is eHEADSMState_t, as enum variable is assigned to macro.
    @typical        [none]   @unit [none]     @min -1.7E+308   @max +1.7E+308   */
#define HEADBitPackToOtherModuleStateTime_ModuleState(bitpack) ((eHEADSMState_t)(((bitpack)>>5u)&0x3u))

/*! @brief          Definition Of head bit pack to other module state time must be in state
    @typical        [none]   @unit [none]     @min 0   @max 1   */
#define HEADBitPackToOtherModuleStateTime_MustBeInState(bitpack) (((((bitpack)>>7)&0x1u)!= 0u) ? b_TRUE : b_FALSE)

/*! @brief          Definition Of head other or group true to bit pack
    @typical        [none]   @unit [none]     @min 0   @max 65535   */
#define HEADOtherOrGroupTrue2BitPack(OrGroupNr, bTrueFalse) \
  ((uint16)(( (((bTrueFalse) & 1u) << 3u) | ((OrGroupNr)))))

/*! @brief          Definition Of head bit pack to other or group or group near
    @typical        [none]   @unit [none]     @min 0   @max 255   */
#define HEADBitPackToOtherOrGroup_OrGroupNr(bitpack)       ((uint8)((bitpack)&0x3u))

/*! @brief          Definition Of head bit pack to other or group must be true or false
    @typical        [none]   @unit [none]     @min 0	@max 1   */
#define HEADBitPackToOtherOrGroup_MustBeTrueFalse(bitpack) (((((bitpack)>>3)&0x1u) != 0u) ? b_TRUE : b_FALSE)

/*! @brief          Definition Of head object class bit.
    @typical        [none]   @unit [none]     @min 0   @max 255   */
#define HEADObjectClassBit(object)  ((HEADEBAObjectClass_t)(1u<<((uint8)(object) -1u)))

/*! @brief          Definition Of head dynamic properties bit
    @typical        [none]   @unit [none]     @min 0   @max 255   */
#define HEADDynPropBit(dynProp)     ((HEADEBADynProp_t)    (1u<<((uint8)(dynProp)-1u)))

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
/*! @brief          Head bit field available for main type parameter.

    @description    main type of the parameter (scalar/table)
    */
typedef enum 
{  
  HEADParamMainType_Scalar = 0u,                                   /*!< parameter type is a scalar*/
  HEADParamMainType_Table  = 1u                                    /*!< parameter type is a value*/
} eHEADParamMainType_t;

/*! @brief          The Bit Field type of the enum @ref eHEADParamMainType_t
    */
typedef HEADBitField_t HEADParamMainType_t;                        /*!< @values: eHEADParamMainType_t */

/*! eHEADParamMainValueType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Head bit field available for main value type.

    @description    main value types (value/factor)
    */
typedef enum
{
  HEADParamMainValueType_Value  = 0u,                              /*!< defines that the output is the real value of this parameter*/
  HEADParamMainValueType_Factor = 1u,                              /*!< defines that the output is a factor for this parameter. if a value is not defined, factors are not used!*/
  HEADParamMainValueType_Bool   = 2u                               /*!< defines that the output is a bool (>0: true, <0: false).*/
} eHEADParamMainValueType_t;

/*! @brief          The Bit Field type of the enum @ref eHEADParamMainValueType_t
    */
typedef HEADBitField_t HEADParamMainValueType_t;                   /*!< @values: eHEADParamMainValueType_t */


/*! eHEADHypOutType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Head Hypothesis output type

    @description    hypothesis output variable type
    */
typedef enum 
{
  HEADHypOutType_TTC                      = 0u,           /*!< defines the TTC  CAUTION!!! TTC must be the first hyp dependent value!!!*/
  HEADHypOutType_TTB_PRE                  = 1u,           /*!< defines the TTB pre*/
  HEADHypOutType_TTB_ACUTE                = 2u,           /*!< defines the TTB acute*/
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
  HEADHypOutType_SensorSource             = 18u,          /*! */
  /* The application-specific parameters should always be between the general parameters and Max. */
  HEADHypOutType_CustomPar_00             = 19u,          /*!< defines application specific DEPENDENT parameter 0 */
  HEADHypOutType_CustomPar_01             = 20u,          /*!< defines application specific DEPENDENT parameter 1 */
  HEADHypOutType_CustomPar_02             = 21u,          /*!< defines application specific DEPENDENT parameter 2 */
  HEADHypOutType_CustomPar_03             = 22u,          /*!< defines application specific DEPENDENT parameter 3 */
  HEADHypOutType_CustomPar_04             = 23u,          /*!< defines application specific DEPENDENT parameter 4 */
  HEADHypOutType_CustomPar_05             = 24u,          /*!< defines application specific DEPENDENT parameter 5 */
  HEADHypOutType_CustomPar_06             = 25u,          /*!< defines application specific DEPENDENT parameter 6 */
  HEADHypOutType_CustomPar_07             = 26u,          /*!< defines application specific DEPENDENT parameter 7 */
  HEADHypOutType_ObjectDistLat            = 27u,          /*!< defines the lateral object distance (m)*/
  #if HEAD_CFG_TURN_ASSIST
  HEADHypOutType_CorridorStopDistance     = 28u,          /*! */
  HEADHypOutType_Max                      = 29u           /*!< defines the maximum number of enums (must correlate to the number of bits in @ref HEADParameterType_t) <= 64*/
  #elif HEAD_CFG_CORRIDOROCCUPANCY        
  HEADHypOutType_CorridorOccupancy        = 28u,
  HEADHypOutType_ObjMovDir                = 29u,
  HEADHypOutType_CustomPar_08             = 30u,
  HEADHypOutType_Max                      = 31u           /*!< defines the maximum number of enums (must correlate to the number of bits in @ref HEADParameterType_t) <= 64*/
  #else 
  HEADHypOutType_Max                      = 28u           /*!< defines the maximum number of enums (must correlate to the number of bits in @ref HEADParameterType_t) <= 64*/
  #endif
} eHEADHypOutType_t;      

/*! eHEADParamOutType_t */
/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Head Hypothesis output type of the parameter

    @description    hypothesis output variable type of the parameter
    */
typedef enum 
{
  HEADParamOutType_AllConditionsForOrGroupMet    = 0u,        /*!< defines a time where all other conditions needs to be met to activate the function - must be the first!*/  
  HEADParamOutType_OrGroupInhibition             = 1u,        /*!< defines Inhibition of hyps for an orGroup*/
  HEADParamOutType_StateActiveTime               = 2u,        /*!< defines a time where the state must be active to go to the next state - must be the last in this enum*/
  HEADParamOutType_OtherModuleStateTime          = 3u,        /*!< defines that the parameter value defines a time another module must/must not be in a specific state to make the transition*/
  HEADParamOutType_Bool                          = 4u,        /*!< defines a bool value*/
  HEADParamOutType_EgoVelocity                   = 5u,        /*!< defines ego velocity (m/s) - hyp independend*/
  HEADParamOutType_EgoAccel                      = 6u,        /*!< defines ego acceleration (m/s*s) - hyp independend*/
  HEADParamOutType_SafeObjDistSfty               = 7u,        /*!< defines safe object distance for safety functions (m) - hyp independend*/
  HEADParamOutType_SafeObjDistPerf               = 8u,        /*!< defines safe object distance for performance functions (m) - hyp independend*/
  HEADParamOutType_DriverFeedbackProb            = 9u,        /*!< defines DIM Feedback Probability*/
  HEADParamOutType_DriverActivityProb            = 10u,       /*!< defines DIM Activity Probability*/
  HEADParamOutType_DriverAttentionProb           = 11u,       /*!< defines DIM Attention Probability*/
  HEADParamOutType_TTC                           = 12u,       /*!< defines the TTC*/
  HEADParamOutType_TTB_PRE                       = 13u,       /*!< defines the TTB pre*/
  HEADParamOutType_TTB_ACUTE                     = 14u,       /*!< defines the TTB acute*/
  HEADParamOutType_TTS_PRE                       = 15u,       /*!< defines the TTS pre*/
  HEADParamOutType_TTS_ACUTE                     = 16u,       /*!< defines the TTS acute*/
  HEADParamOutType_ClosingVel                    = 17u,       /*!< defines the closing velocity (m/s)*/
  HEADParamOutType_ANecLong                      = 18u,       /*!< defines the necessary longitudinal deceleration (m/s^2)*/
  HEADParamOutType_HypProb                       = 19u,       /*!< defines hypothesis probability (%)*/
  HEADParamOutType_ObjectDist                    = 20u,       /*!< defines the object distance (m)*/
  HEADParamOutType_ObjProb                       = 21u,       /*!< defines hypothesis object probability (%)*/
  HEADParamOutType_TTC2                          = 22u,       /*!< defines TTC2 */
  HEADParamOutType_TTC3                          = 23u,       /*!< defines TTC3 */
  HEADParamOutType_TTC4                          = 24u,       /*!< defines TTC4 */
  HEADParamOutType_HypLifetime                   = 25u,       /*!< defines hypothesis lifetime */
  HEADParamOutType_ANecLatAbs                    = 26u,       /*!< defines the necessary absolute lateral deceleration (m/s^2)*/
  HEADParamOutType_VRelX                         = 27u,       /*!< defines the relative velocity (m/s)*/
  HEADParamOutType_TTMLongPre                    = 28u,       /*!< defines Time to comfort mitigation by longitudinal acceleration to avoid a collision in 2D scenario */
  HEADParamOutType_TTMLongAcute                  = 29u,       /*!< defines Time to comfort mitigation by longitudinal acceleration to avoid a collision in 2D scenario */
  HEADParamOutType_OtherOrGroupIsTrue            = 30u,       /*!< defines an other orGroup to be true*/
  /*PRQA S 0779 16*//*identifier is part of enum - QAC warning is ignored */
  HEADParamOutType_CustomPar_00_HypIndependent   = 31u,       /*!< defines application specific INDEPENDENT parameter 0 */
  HEADParamOutType_CustomPar_01_HypIndependent   = 32u,       /*!< defines application specific INDEPENDENT parameter 1 */
  HEADParamOutType_CustomPar_02_HypIndependent   = 33u,       /*!< defines application specific INDEPENDENT parameter 2 */
  HEADParamOutType_CustomPar_03_HypIndependent   = 34u,       /*!< defines application specific INDEPENDENT parameter 3 */
  HEADParamOutType_CustomPar_04_HypIndependent   = 35u,       /*!< defines application specific INDEPENDENT parameter 4 */
  HEADParamOutType_CustomPar_05_HypIndependent   = 36u,       /*!< defines application specific INDEPENDENT parameter 5 */
  HEADParamOutType_CustomPar_06_HypIndependent   = 37u,       /*!< defines application specific INDEPENDENT parameter 6 */
  HEADParamOutType_CustomPar_07_HypIndependent   = 38u,       /*!< defines application specific INDEPENDENT parameter 7 */
  HEADParamOutType_CustomPar_00_HypDependent     = 39u,       /*!< defines application specific DEPENDENT parameter 0 */
  HEADParamOutType_CustomPar_01_HypDependent     = 40u,       /*!< defines application specific DEPENDENT parameter 1 */
  HEADParamOutType_CustomPar_02_HypDependent     = 41u,       /*!< defines application specific DEPENDENT parameter 2 */
  HEADParamOutType_CustomPar_03_HypDependent     = 42u,       /*!< defines application specific DEPENDENT parameter 3 */
  HEADParamOutType_CustomPar_04_HypDependent     = 43u,       /*!< defines application specific DEPENDENT parameter 4 */
  HEADParamOutType_CustomPar_05_HypDependent     = 44u,       /*!< defines application specific DEPENDENT parameter 5 */
  HEADParamOutType_CustomPar_06_HypDependent     = 45u,       /*!< defines application specific DEPENDENT parameter 6 */
  HEADParamOutType_CustomPar_07_HypDependent     = 46u,       /*!< defines application specific DEPENDENT parameter 7 */
  HEADParamOutType_EgoLatCurvature               = 47u,       /*!< defines curvature of ego trajectory */
  HEADParamOutType_SensorSource                  = 48u,       /*!< defines the sensor source of the object (e.g. Camera, Radar, Fusion,..) */
  HEADParamOutType_ObjectDistLat                 = 49u,       /*!< defines the object distance (m)*/  
  #if HEAD_CFG_TURN_ASSIST
  HEADParamOutType_SteeringAngle                 = 50u,       /*! */
  HEADParamOutType_GasPedal                      = 51u,       /*! */
  HEADParamOutType_CorridorStopDistance          = 52u,       /*! */
  HEADParamOutType_TurnIndicatorInSteeringDirection = 53u,    /*! */
  HEADParamOutType_Max                           = 54u        /*!< defines the maximum number of enums (must correlate to the number of bits in HEADParameterType_t) <= 64*/
  #elif HEAD_CFG_CORRIDOROCCUPANCY  
  HEADParamOutType_CorridorOccupancy             = 50u,
  HEADParamOutType_ObjMoveDir                    = 51u,
  HEADParamOutType_CustomPar_08_HypIndependent   = 52u,
  HEADParamOutType_CustomPar_09_HypIndependent   = 53u,
  HEADParamOutType_CustomPar_08_HypDependent     = 54u,       /*!< defines application specific DEPENDENT parameter 8 */
  HEADParamOutType_Max                           = 55u        /*!< defines the maximum number of enums (must correlate to the number of bits in HEADParameterType_t) <= 64*/
  #else 
  HEADParamOutType_Max                           = 50u        /*!< defines the maximum number of enums (must correlate to the number of bits in HEADParameterType_t) <= 64*/
  #endif
  /*this enum can be extended up to 64 entries - always append new OutTypes before customs for backward compatibility*/
} eHEADParamOutType_t;

/*! @brief          The Bit Field type of the enum @ref eHEADParamOutType_t
    */
typedef HEADBitField_t HEADParamOutType_t;                 /*!< using 8bit type for the real enum (32bit type) ref eHEADParameterType_t to save memory @values @ref eHEADParamOutType_t */


/*! @brief          for evaluation first hypo based parameter is TTC
    @description    Head parameter output type of first value  
    */
#define HEADParamOutType_FirstValue HEADParamOutType_AllConditionsForOrGroupMet


/*! eHEADParamTabType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Head parameter table type
    */
typedef enum
{
  eHEADParamTabType_HostSpeed                     =  0u,      /*!< x value of the table is absolute host x speed (m/s)*/
  eHEADParamTabType_HostAccel                     =  1u,      /*!< x value of the table is absolute host x accel (m/s^2)*/
  eHEADParamTabType_Distance                      =  2u,      /*!< x value of the table is the longitudinal distance to the object (m)*/
  eHEADParamTabType_ProbAttention                 =  3u,      /*!< x value of the table is driver activity probability (%)*/
  eHEADParamTabType_ConfAttention                 =  4u,      /*! */
  eHEADParamTabType_ProbFeedback                  =  5u,      /*!< x value of the table is driver feedback probability (%)*/
  eHEADParamTabType_ConfFeedback                  =  6u,      /*! */
  eHEADParamTabType_ProbActivity                  =  7u,      /*!< x value of the table is driver activity probability (%)*/
  eHEADParamTabType_ConfActivity                  =  8u,      /*! */
  eHEADParamTabType_HostSpeedLastStateTrans       =  9u,      /*!< x value of the table is absolute host x speed (m/s) at the time where the module was transitioning from passive to active */
  eHEADParamTabType_ClosingVelocity               = 10u,      /*!< x value of the table is the closing velocity (m/s) */
  eHEADParamTabType_VRelX                         = 11u,      /*!< x value of the table is relative velocity (m/s) */
  eHEADParamTabType_CustomPar_00_HypIndependent   = 12u,      /*!< defines application specific INDEPENDENT parameter 0 */
  eHEADParamTabType_CustomPar_01_HypIndependent   = 13u,      /*!< defines application specific INDEPENDENT parameter 1 */
  eHEADParamTabType_CustomPar_02_HypIndependent   = 14u,      /*!< defines application specific INDEPENDENT parameter 2 */
  eHEADParamTabType_CustomPar_03_HypIndependent   = 15u,      /*!< defines application specific INDEPENDENT parameter 3 */
  eHEADParamTabType_CustomPar_04_HypIndependent   = 16u,      /*!< defines application specific INDEPENDENT parameter 4 */
  eHEADParamTabType_CustomPar_05_HypIndependent   = 17u,      /*!< defines application specific INDEPENDENT parameter 5 */
  eHEADParamTabType_CustomPar_06_HypIndependent   = 18u,      /*!< defines application specific INDEPENDENT parameter 6 */
  eHEADParamTabType_CustomPar_07_HypIndependent   = 19u,      /*!< defines application specific INDEPENDENT parameter 7 */
  eHEADParamTabType_CustomPar_08_HypIndependent   = 20u,      /*!< defines application specific INDEPENDENT parameter 8 */
  eHEADParamTabType_CustomPar_09_HypIndependent   = 21u,      /*!< defines application specific INDEPENDENT parameter 8 */
  /*PRQA S 0779 8*//*identifier is part of enum - QAC warning is ignored */
  eHEADParamTabType_CustomPar_00_HypDependent     = 22u,      /*!< defines application specific DEPENDENT parameter 0 */
  eHEADParamTabType_CustomPar_01_HypDependent     = 23u,      /*!< defines application specific DEPENDENT parameter 1 */
  eHEADParamTabType_CustomPar_02_HypDependent     = 24u,      /*!< defines application specific DEPENDENT parameter 2 */
  eHEADParamTabType_CustomPar_03_HypDependent     = 25u,      /*!< defines application specific DEPENDENT parameter 3 */
  eHEADParamTabType_CustomPar_04_HypDependent     = 26u,      /*!< defines application specific DEPENDENT parameter 4 */
  eHEADParamTabType_CustomPar_05_HypDependent     = 27u,      /*!< defines application specific DEPENDENT parameter 5 */
  eHEADParamTabType_CustomPar_06_HypDependent     = 28u,      /*!< defines application specific DEPENDENT parameter 6 */
  eHEADParamTabType_CustomPar_07_HypDependent     = 29u,      /*!< defines application specific DEPENDENT parameter 7 */
  eHEADParamTabType_CustomPar_08_HypDependent     = 30u,      /*!< defines application specific DEPENDENT parameter 8 */
  eHEADParamTabType_DistanceLat                   = 31u      /*!< x value of the table is the longitudinal distance to the object (m)*/  
} eHEADParamTabType_t;  

/*! @brief          The numeric type of the enum @ref eHEADParamTabType_t
    */
typedef uint8 HEADParamTableType_t;                       /*!< using 8bit type for the real enum (32bit type) @ref eHEADParamTabType_t to save memory @values @ref eHEADParamTabType_t */

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          this structure defines all input variable that are used for table inputs (x) which cannot be provided from current input data

    @description    Head additional table input values availalbe with host speed last state

    @attention      TODO Rework Concept => These Variables should be handled in non-generic part
    */
typedef struct  
{
  float32 fHostSpeedLastStateTransition;                       /*!< Defines the ego velocity at the beginning of the last state transition */  
  boolean bHostSpeedLastStateTransitionOK;                     /*!< Defines the ego velocity at the beginning of the last state transition signal state */  
} HEADAdditionalTableInputValues_t;

/* ****************************************************************
    TYPEDEF ENUM eHEADMainMode_t
    **************************************************************** */
/*! @brief          These values are used to address Bits in bit-fields. Make sure values are within bounds 

    @description    definition of internal head modes
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
    TYPEDEF 
    **************************************************************** */
/*! @brief 			The numeric type of the enum @ref eHEADMainMode_t

    @description 	These values are used to address Bits in bit-fields. Make sure values are within bounds 
    */
typedef uint8 HEADMainMode_t;                                       /*!< @values: eHEADMainMode_t */


/* ****************************************************************
    TYPEDEF ENUM HEADParameterMode_t
    **************************************************************** */
/*! @brief          These values are used to address fields in bit-fields. Make sure values are within bounds 

    @description    definition of internal head fields
    */
typedef HEADBitField_t HEADParameterMode_t;


/* ****************************************************************
    TYPEDEF ENUM HEADParameterHypothesisSub_t
    **************************************************************** */
/*! @brief          Head beat field for head parameter hypothesis sub.
    */
typedef HEADBitField_t HEADParameterHypothesisSub_t;


/*! eHEADParameterState_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          These values are used to address Bits in bit-fields. Make sure values are within bounds 

    @description    definition of head parameters for mode transitions
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

/*! @brief          Head beat field type of the enum @ref eHEADParameterState_t
    */
typedef HEADBitField_t HEADParameterState_t;                        /*!< @values: eHEADParameterState_t */


/*! eHEADParamOperator_t */
/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          head parameter operator for mathematic operation. \n
                    operator type (</>)
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
/*! @brief          Head bit field for parameter operation. \n
                    operator type (</>)
    */
typedef HEADBitField_t HEADParamOperator_t;                     /*!< @values: eHEADParamOperator_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Head bit field for head parameter individual or group
    */
typedef HEADBitField_t HEADParameterOrGroup_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Head bit field for head eba object class
    */
typedef HEADBitField_t HEADEBAObjectClass_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Head bit field for head eba dynamic properties
    */
typedef HEADBitField_t HEADEBADynProp_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          Structure definition for Head parameter Type

    */
typedef struct  
{
  /*generic parameter information*/
  HEADParamMainType_t          ParamMainType        : 1;          /*!< 1 (Offset 0+0) bits for main type (none, scalar, table) @values @ref eHEADParamMainValueType_t @unit none|scalar|table*/
  HEADParamMainValueType_t     ParamMainValueType   : 1;          /*!< 1 (Offset 0+1) bit  for (value, factor) - defines the type of the parameter @unit val|fac|bool*/
  HEADParamOperator_t          ParamOperator        : 1;          /*!< 1 (Offset 0+2) bit for the operator (</>) @unit less|greater*/
  /*head specific parameter information*/
  HEADParamOutType_t           ParamOutType         : 6;          /*!< 6 (Offset 0+3) bits for OutType (64 different types like TTC, ModuleConditionEgoVel...) @values @ref eHEADParamOutType_t*/
  HEADParameterState_t         ParamState           : 7;          /*!< 4 (Offset 0+9) bits for the state (keepPassive [passive], enable [pass-act], keepActive [active], leaveActive [act-wait], keepWait [wait], leaveWait [wait-pass]) 
                                                                     @values @ref eHEADParameterState_t, @unit:keepPassive|Enable|KeepActive|LeaveActive|KeepWait|LeaveWait|Init*/ 
  HEADParameterMode_t          ParameterMode        : 4;          /*!< 4 (Offset 0+16) bits - one BIT for every driver preference setting (early, middle, late, acc) @unit Early|Middle|Late|ACC*/
  HEADParameterOrGroup_t       ParameterOrGroup     : 3;          /*!< 3 (Offset 0+20) bits - or group - OR(AND(all Group 0 parameters), AND(all Group 1 parameters),...),@unit:0-8*/
  HEADEBAObjectClass_t         ParamObjectClass     : 4;          /*!< 4 (Offset 0+23) bits for Object Class @unit NotAvail|Pedestrian|Vehicle|Obstacle|Cyclist */
  HEADEBADynProp_t             ParamDynProp         : 2;          /*!< 2 (Offset 0+27) bits for Dynamic Property @unit NotAvail|Moving|Stationary */
  HEADBitField_t               Padding1             : 3;          /*!< 3 (Offset 0+29) bits */
  HEADParameterHypothesisSub_t ParameterHypSubType  : 16;         /*!< 10 (Offset 1+0)bits - one BIT for every Hypothesis (HEADParameterHypothesisBit(xxx)|...|...) @unit: hyptype*/
  HEADBitField_t               Padding2             : 16;         /*!< 16 (Offset 1+16) bits */
} HEADParameterType_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          Head parameter empty struct for head parameter empty.

    */
typedef struct HEADParameterEmptyStruct HEADParameterEmpty_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          Head parameter header for implementing head parameter.

    */
typedef struct
{
  HEADParameterType_t       sParameterType;                   /*!<next list element*/
  HEADParameterEmpty_t *                    pNextParam;                           /*!< pointer to next parameter*/
  HEADParameterEmpty_t *                    pNextRelevantParam;                   /*!< pointer to the next relevant parameter*/
} HEADParameterHeader_t;

/*-- different parameter definitions -> each parameter definition MUST have HEADParameterHeader_t at the beginning*/

/* ****************************************************************
    TYPEDEF 
    **************************************************************** */
/*! @brief different parameter definitions -> each parameter definition MUST have HEADParameterHeader_t at the beginning

    @general could contain special (@ref eHEADParamOutType_t dependent) information

    */
typedef uint16 HEADBitPack_t; /*!< could contain special (@ref eHEADParamOutType_t dependent) information*/

/*parameter definition for an empty parameter*/

/* ****************************************************************
    STRUCT HEADParameterEmptyStruct
    **************************************************************** */
/*! @brief 			HEAD Parameter Empty Structure

    */
struct HEADParameterEmptyStruct 
{
  HEADParameterHeader_t   ParameterType;                        /*!< defines the type of the parameter - must be at the beginning (ParameterType.ParamMainType must be HEADParamMainType_Empty)*/
  HEADBitPack_t           uiSpecialParInfo;                     /*!< could contain special (eHEADParamOutType_t dependent) information*/
};


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          Head parameter scaler

    @description    parameter definition for scalar values
    */
typedef struct  
{
  HEADParameterHeader_t ParameterType;                         /*!< defines the type of the parameter - must be at the beginning (ParameterType.ParamMainType must be HEADParamMainType_Scalar)*/
  HEADBitPack_t         uiSpecialParInfo;                      /*!< could contain special (eHEADParamOutType_t dependent) information*/
  /*scalar specific information*/
  f16_t                 f16RawValue;                           /*!< the raw value -> must be divided by ParameterType.ParamScaleType scaling*/
} HEADParameterScalar_t;


/*! eHEADParameterTableFloatType_t */

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          Head parameter table float type values

    @description    Enum to Define Table float type for Table parameters
    */
typedef enum
{
  HEADParameterTableFloatType_f16 = 0u,
  HEADParameterTableFloatType_f32 = 1u
} eHEADParameterTableFloatType_t;


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief          parameter definition for table values
    */
typedef struct  
{
  HEADParameterHeader_t          ParameterType;                      /*!< defines the type of the parameter - must be at the beginning (ParameterType.ParamMainType must be HEADParamMainType_Table)*/
  HEADBitPack_t                  uiSpecialParInfo;                   /*!< could contain special (eHEADParamOutType_t dependent) information*/                                
  /*table specific information*/
  HEADParamTableType_t           TableType;                          /*!< defines specific table type (input vector type) @values @ref eHEADParamTabType_t */
  uint8                          uiNrOfTableRows;                    /*!< defines the number of table rows*/  
  f16_t                          f16DefaultValue;                    /*!< default value (for the input) if table input cannot be found*/
  eHEADParameterTableFloatType_t eTableFloatType;                    /*!< defines the type of the pTable @values @ref eHEADParameterTableFloatType_t */  
  const void                     *pTable;                            /*!< pointer to the table containing 2*uiNrOfTableRows values (x0,y0,x1,y1,...xn,yn)*/
} HEADParameterTable_t;


/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          head MTS parameter data
    */
typedef struct  
{
  /*HEADER Information*/
  HEADBitField_t        bParamValid           :1;              /*!< defines if to following information is valid or not @unit:bool*/
  HEADBitField_t        uiModuleNr            :7;              /*!< defines to which module the parameter belongs @name:ModuleNr*/
  HEADBitField_t        uiParNr               :16;             /*!< defines the nr of the parameter in this module @name:ParameterNr*/
  HEADBitField_t        uiTablePos            :8;              /*!< since tables are transfered as parts (n rows per cycle, this value defines the last row) @name:TableRowOffset*/
  HEADParameterType_t   sParameterHeader;                      /*!< stores the parameter header information @name:ParameterHeader*/
  HEADBitPack_t         uiSpecialParInfo;                      /*!< stores special information @name:BitPack*/
  /*table parameter information*/
  uint8                 uiNrOfTableRows;                       /*!< table rows in case of a parameter table*/
  HEADParamTableType_t  eTableType;                            /*!< table type in case of a parameter table*/
  /*scalar or table parameter information*/
  float32               fScalarValue_DefaultX;                 /*!< stores the scalar value in case of a scalar parameter or the defaultX value in case of a table*/
  /*table itself*/
  float32               fTable[2u*HEAD_MTS_MAX_TABLE_ROWS];    /*!< part of the values in case of a parameter table*/

} HEADMTSParameterData_t;

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/

/*** END OF SINLGE INCLUDE SECTION ******************************************/

/*! @cond */
#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
/*! @endcond */

#endif /* HEAD_PAR_DEF_H_INCLUDED */
/**@}*/

