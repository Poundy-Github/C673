/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : HMIOC
  MODULE        : HMODFL
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     HMODFL.h
//! @brief     (HMODFL) Module Header.

#ifndef HMODFL_H_
#define HMODFL_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"
#include "HMODFL_type.h"
#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
  F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
*	HMODFL module sensor initialization function. Function initializes HMODFL sensor output data pointer.
*
*	@param
*		[in] HMODFL_SenOutArg Pointer to HMODFL sensor output data.
*
*	@return
*		void
*
*	@testmethod
*		Code Review
*
*	@traceability
*		Design Decision
*/
extern void HMODFL_SenInitOutPtr(HMODFL_SenOutType *HMODFL_SenOutArg);

/*!
*	HMODFL module sensor reset function.
*
*	@pre
*		- The HMODFL sensor initialization function(s) must be called once.
*		- The HMODFL sensor debug/output data pointer(s) should not be NULL.
*
*	@post
*
*	@param
*		void
*
*	@return
*		void
*
*	@globals
*		[Output Signal] [S_HMODFL_AvailableFunction_btf](@ref HMODFL_SenOutType::S_HMODFL_AvailableFunction_btf) \n
*		[Output Signal] [S_HMODFL_LKAInforStatus_nu](@ref HMODFL_SenOutType::S_HMODFL_LKAInforStatus_nu) \n
*		[Output Signal] [S_HMODFL_LKAStatusChange_nu](@ref HMODFL_SenOutType::S_HMODFL_LKAStatusChange_nu) \n\n
*		For signal details, see sub-section [Globals](@ref HMODFL_SenProcess_Globals) of the function @ref HMODFL_SenProcess.
*
*	@InOutCorrelation
*		Resets all static global variables.
*
*	@callsequence
*
*	@testmethod
*		Code Review
*
*	@traceability
*		Design Decision
*/
extern void HMODFL_SenReset(void);

/*!
*	HMODFL module sensor process function.
*
*	@pre
*		- The HMODFL sensor initialization function(s) must be called once.
*		- The HMODFL sensor debug/output data pointer(s) should not be NULL.
*
*	@post
*
*	@param
*		void
*
*	@return
*		void
*
*	@globals
*		@anchor HMODFL_SenProcess_Globals
*		[S_HMODFL_AvailableFunction_btf](@ref HMODFL_SenOutType::S_HMODFL_AvailableFunction_btf) \n
*		\@kind: Output Signal \n
*		\@type: @ref u8_NoUnit_0_255_0_1_t \n
*		\@size: 1x1x1 \n
*		\@unit: - \n
*		\@min: 0 \n
*		\@max: 255 \n
*		\@description: \n
*		Bit0: TJA(LKA); \n\n
*		[S_HMODFL_LKAInforStatus_nu](@ref HMODFL_SenOutType::S_HMODFL_LKAInforStatus_nu) \n
*		\@kind: Output Signal \n
*		\@type: @ref u8_NoUnit_0_10_0_1_t \n
*		\@size: 1x1x1 \n
*		\@unit: - \n
*		\@min: 0 \n
*		\@max: 10 \n
*		\@description: \n
*		LKA status: \n
*		0 -> Not present / Disable \n
*		1 -> Passive \n
*		2 -> Request / Controlling / Rampout \n
*		4 -> Fault \n\n
*		[S_HMODFL_LKAStatusChange_nu](@ref HMODFL_SenOutType::S_HMODFL_LKAStatusChange_nu) \n
*		\@kind: Output Signal \n
*		\@type: @ref u8_NoUnit_0_1_0_1_t \n
*		\@size: 1x1x1 \n
*		\@unit: - \n
*		\@min: 0 \n
*		\@max: 1 \n
*		\@description: \n
*		Indicate if the LKA status changes from 0 to 1 or from 1 to 2. \n\n
*		@ref S_DPLSMI_SysStateLDP_nu \n
*		\@kind: Input Signal \n
*		\@type: @ref E_LCF_SysStateType_t \n
*		\@size: 1x1x1 \n
*		\@unit: - \n
*		\@min: 0 \n
*		\@max: 6 \n
*		\@description: \n
*		System State of the LDP function. \n\n
*		@ref S_TJASTM_SysStateTJA_nu \n
*		\@kind: Input Signal \n
*		\@type: @ref E_LCF_SysStateType_t \n
*		\@size: 1x1x1 \n
*		\@unit: - \n
*		\@min: 0 \n
*		\@max: 6 \n
*		\@description: \n
*		TJASTM_OUTPUT \n\n
*		@ref P_HMODFL_UsePassiveAvlbFct_bool \n
*		\@kind: Parameter \n
*		\@type: @ref u8_NoUnit_0_1_0_1_t \n
*		\@size: 1x1x1 \n
*		\@unit: - \n
*		\@min: 0 \n
*		\@max: 1 \n
*		\@description: \n
*		Enable to use also state passive in  \n
*		S_HMODFL_AvailableFunction_btf \n\n
*		@ref P_HMODFL_WarningCycle_nu \n
*		\@kind: Parameter \n
*		\@type: @ref u8_NoUnit_0_100_0_1_t \n
*		\@size: 1x1x1 \n
*		\@unit: - \n
*		\@min: 0 \n
*		\@max: 100 \n
*		\@description: \n
*		LKA change status warning cycle. \n\n
*
*	@InOutCorrelation
*		[\@link: HMODFL Module Software Detailed Design]()
*
*	@callsequence
*
*	@testmethod
*		-# [Testcase_Initialization](@ref HMODFL_Testcase_Initialization) Initialization of the HMODFL
*		-# [TestcaseAF_1](@ref HMODFL_TestcaseAF_1)
*		-# [TestcaseAF_2](@ref HMODFL_TestcaseAF_2)
*		-# [TestcaseAF_3](@ref HMODFL_TestcaseAF_3)
*		-# [TestcaseAF_4](@ref HMODFL_TestcaseAF_4)
*		-# [TestcaseAF_5](@ref HMODFL_TestcaseAF_5)
*		-# [TestcaseAF_6](@ref HMODFL_TestcaseAF_6)
*		-# [TestcaseAF_7](@ref HMODFL_TestcaseAF_7)
*		-# [TestcaseAF_8](@ref HMODFL_TestcaseAF_8)
*		-# [TestcaseAF_9](@ref HMODFL_TestcaseAF_9)
*		-# [TestcaseAF_10](@ref HMODFL_TestcaseAF_10)
*		-# [TestcaseAF_11](@ref HMODFL_TestcaseAF_11)
*		-# [TestcaseAF_12](@ref HMODFL_TestcaseAF_12)
*		-# [TestcaseAF_13](@ref HMODFL_TestcaseAF_13)
*		-# [TestcaseAF_14](@ref HMODFL_TestcaseAF_14)
*		-# [TestcaseAF_15](@ref HMODFL_TestcaseAF_15)
*		-# [TestcaseAF_16](@ref HMODFL_TestcaseAF_16)
*		-# [TestcaseAF_17](@ref HMODFL_TestcaseAF_17)
*		-# [TestcaseAF_18](@ref HMODFL_TestcaseAF_18)
*		-# [TestcaseAF_19](@ref HMODFL_TestcaseAF_19)
*		-# [TestcaseAF_20](@ref HMODFL_TestcaseAF_20)
*		-# [TestcaseAF_21](@ref HMODFL_TestcaseAF_21)
*		-# [TestcaseAF_22](@ref HMODFL_TestcaseAF_22)
*		-# [TestcaseAF_23](@ref HMODFL_TestcaseAF_23)
*		-# [TestcaseAF_24](@ref HMODFL_TestcaseAF_24)
*		-# [TestcaseAF_25](@ref HMODFL_TestcaseAF_25)
*		-# [TestcaseAF_26](@ref HMODFL_TestcaseAF_26)
*		-# [TestcaseAF_27](@ref HMODFL_TestcaseAF_27)
*		-# [TestcaseAF_28](@ref HMODFL_TestcaseAF_28)
*		-# [TestcaseAF_29](@ref HMODFL_TestcaseAF_29)
*		-# [TestcaseAF_30](@ref HMODFL_TestcaseAF_30)
*		-# [TestcaseAF_31](@ref HMODFL_TestcaseAF_31)
*		-# [TestcaseAF_32](@ref HMODFL_TestcaseAF_32)
*		-# [TestcaseAF_33](@ref HMODFL_TestcaseAF_33)
*		-# [TestcaseAF_34](@ref HMODFL_TestcaseAF_34)
*		-# [TestcaseAF_35](@ref HMODFL_TestcaseAF_35)
*		-# [TestcaseAF_36](@ref HMODFL_TestcaseAF_36)
*		-# [TestcaseAF_37](@ref HMODFL_TestcaseAF_37)
*		-# [TestcaseAF_38](@ref HMODFL_TestcaseAF_38)
*		-# [TestcaseAF_39](@ref HMODFL_TestcaseAF_39)
*		-# [TestcaseAF_40](@ref HMODFL_TestcaseAF_40)
*		-# [TestcaseAF_41](@ref HMODFL_TestcaseAF_41)
*		-# [TestcaseAF_42](@ref HMODFL_TestcaseAF_42)
*		-# [TestcaseAF_43](@ref HMODFL_TestcaseAF_43)
*		-# [TestcaseAF_44](@ref HMODFL_TestcaseAF_44)
*		-# [TestcaseAF_45](@ref HMODFL_TestcaseAF_45)
*		-# [TestcaseAF_46](@ref HMODFL_TestcaseAF_46)
*		-# [TestcaseAF_47](@ref HMODFL_TestcaseAF_47)
*		-# [TestcaseAF_48](@ref HMODFL_TestcaseAF_48)
*		-# [TestcaseAF_49](@ref HMODFL_TestcaseAF_49)
*		-# [TestcaseAF_50](@ref HMODFL_TestcaseAF_50)
*		-# [TestcaseAF_51](@ref HMODFL_TestcaseAF_51)
*		-# [TestcaseAF_52](@ref HMODFL_TestcaseAF_52)
*		-# [TestcaseAF_53](@ref HMODFL_TestcaseAF_53)
*		-# [TestcaseAF_54](@ref HMODFL_TestcaseAF_54)
*		-# [TestcaseAF_55](@ref HMODFL_TestcaseAF_55)
*		-# [TestcaseAF_56](@ref HMODFL_TestcaseAF_56)
*		-# [TestcaseAF_57](@ref HMODFL_TestcaseAF_57)
*		-# [TestcaseAF_58](@ref HMODFL_TestcaseAF_58)
*		-# [TestcaseAF_59](@ref HMODFL_TestcaseAF_59)
*		-# [TestcaseAF_60](@ref HMODFL_TestcaseAF_60)
*		-# [TestcaseAF_61](@ref HMODFL_TestcaseAF_61)
*		-# [TestcaseAF_62](@ref HMODFL_TestcaseAF_62)
*		-# [TestcaseAF_63](@ref HMODFL_TestcaseAF_63)
*		-# [TestcaseAF_64](@ref HMODFL_TestcaseAF_64)
*		-# [TestcaseAF_65](@ref HMODFL_TestcaseAF_65)
*		-# [TestcaseAF_66](@ref HMODFL_TestcaseAF_66)
*		-# [TestcaseAF_67](@ref HMODFL_TestcaseAF_67)
*		-# [TestcaseAF_68](@ref HMODFL_TestcaseAF_68)
*		-# [TestcaseAF_69](@ref HMODFL_TestcaseAF_69)
*		-# [TestcaseAF_70](@ref HMODFL_TestcaseAF_70)
*		-# [TestcaseAF_71](@ref HMODFL_TestcaseAF_71)
*		-# [TestcaseAF_72](@ref HMODFL_TestcaseAF_72)
*		-# [TestcaseAF_73](@ref HMODFL_TestcaseAF_73)
*		-# [TestcaseAF_74](@ref HMODFL_TestcaseAF_74)
*		-# [TestcaseAF_75](@ref HMODFL_TestcaseAF_75)
*		-# [TestcaseAF_76](@ref HMODFL_TestcaseAF_76)
*		-# [TestcaseAF_77](@ref HMODFL_TestcaseAF_77)
*		-# [TestcaseAF_78](@ref HMODFL_TestcaseAF_78)
*		-# [TestcaseAF_79](@ref HMODFL_TestcaseAF_79)
*		-# [TestcaseAF_80](@ref HMODFL_TestcaseAF_80)
*		-# [TestcaseAF_81](@ref HMODFL_TestcaseAF_81)
*		-# [TestcaseAF_82](@ref HMODFL_TestcaseAF_82)
*		-# [TestcaseAF_83](@ref HMODFL_TestcaseAF_83)
*		-# [TestcaseAF_84](@ref HMODFL_TestcaseAF_84)
*		-# [TestcaseAF_85](@ref HMODFL_TestcaseAF_85)
*		-# [TestcaseAF_86](@ref HMODFL_TestcaseAF_86)
*		-# [TestcaseAF_87](@ref HMODFL_TestcaseAF_87)
*		-# [TestcaseAF_88](@ref HMODFL_TestcaseAF_88)
*		-# [TestcaseAF_89](@ref HMODFL_TestcaseAF_89)
*		-# [TestcaseAF_90](@ref HMODFL_TestcaseAF_90)
*		-# [TestcaseAF_91](@ref HMODFL_TestcaseAF_91)
*		-# [TestcaseAF_92](@ref HMODFL_TestcaseAF_92)
*		-# [TestcaseAF_93](@ref HMODFL_TestcaseAF_93)
*		-# [TestcaseAF_94](@ref HMODFL_TestcaseAF_94)
*		-# [TestcaseAF_95](@ref HMODFL_TestcaseAF_95)
*		-# [TestcaseAF_96](@ref HMODFL_TestcaseAF_96)
*		-# [TestcaseAF_97](@ref HMODFL_TestcaseAF_97)
*		-# [TestcaseAF_98](@ref HMODFL_TestcaseAF_98)
*		-# [Testcase15](@ref HMODFL_Testcase15)
*		-# [Testcase16](@ref HMODFL_Testcase16)
*		-# [Testcase17](@ref HMODFL_Testcase17)
*		-# [Testcase18](@ref HMODFL_Testcase18)
*		-# [Testcase19](@ref HMODFL_Testcase19)
*		-# [Testcase20](@ref HMODFL_Testcase20)
*		-# [Testcase21](@ref HMODFL_Testcase21)
*		-# [Testcase22](@ref HMODFL_Testcase22)
*		-# [Testcase23](@ref HMODFL_Testcase23)
*		-# [Testcase24](@ref HMODFL_Testcase24)
*		-# [Testcase25](@ref HMODFL_Testcase25)
*		-# [Testcase26](@ref HMODFL_Testcase26)
*		-# [Testcase27](@ref HMODFL_Testcase27)
*		-# [Testcase28](@ref HMODFL_Testcase28)
*		-# [Testcase29](@ref HMODFL_Testcase29)
*		-# [Testcase30](@ref HMODFL_Testcase30)
*		-# [Testcase31](@ref HMODFL_Testcase31)
*		-# [Testcase32](@ref HMODFL_Testcase32)
*		-# [Testcase33](@ref HMODFL_Testcase33)
*		-# [Testcase34](@ref HMODFL_Testcase34)
*		-# [Testcase35](@ref HMODFL_Testcase35)
*		-# [Testcase36](@ref HMODFL_Testcase36)
*		-# [Testcase37](@ref HMODFL_Testcase37)
*		-# [Testcase38](@ref HMODFL_Testcase38)
*		-# [Testcase39](@ref HMODFL_Testcase39)
*		-# [Testcase40](@ref HMODFL_Testcase40)
*		-# [Testcase41](@ref HMODFL_Testcase41)
*		-# [Testcase42](@ref HMODFL_Testcase42)
*		-# [Testcase43](@ref HMODFL_Testcase43)
*		-# [Testcase44](@ref HMODFL_Testcase44)
*		-# [Testcase45](@ref HMODFL_Testcase45)
*		-# [Testcase46](@ref HMODFL_Testcase46)
*		-# [Testcase47](@ref HMODFL_Testcase47)
*		-# [Testcase48](@ref HMODFL_Testcase48)
*		-# [Testcase49](@ref HMODFL_Testcase49)
*		-# [Testcase50](@ref HMODFL_Testcase50)
*		-# [Testcase51](@ref HMODFL_Testcase51)
*		-# [Testcase52](@ref HMODFL_Testcase52)
*		-# [Testcase53](@ref HMODFL_Testcase53)
*		-# [Testcase54](@ref HMODFL_Testcase54)
*		-# [Testcase55](@ref HMODFL_Testcase55)
*		-# [Testcase56](@ref HMODFL_Testcase56)
*		-# [Testcase57](@ref HMODFL_Testcase57)
*		-# [Testcase58](@ref HMODFL_Testcase58)
*		-# [Testcase59](@ref HMODFL_Testcase59)
*		-# [Testcase60](@ref HMODFL_Testcase60)
*		-# [Testcase61](@ref HMODFL_Testcase61)
*		-# [Testcase62](@ref HMODFL_Testcase62)
*		-# [Testcase63](@ref HMODFL_Testcase63)
*		-# [Testcase64](@ref HMODFL_Testcase64)
*		-# [Testcase65](@ref HMODFL_Testcase65)
*		-# [Testcase66](@ref HMODFL_Testcase66)
*		-# [Testcase67](@ref HMODFL_Testcase67)
*		-# [Testcase68](@ref HMODFL_Testcase68)
*		-# [Testcase69](@ref HMODFL_Testcase69)
*		-# [Testcase70](@ref HMODFL_Testcase70)
*		-# [Testcase71](@ref HMODFL_Testcase71)
*
*	@traceability
*		[\@link: HMODFL Module Requirements]()
*/
extern void HMODFL_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // HMODFL_H_
