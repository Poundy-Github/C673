/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_autocode_cfg.h

DESCRIPTION:               header file of autocode parameters (for the generic state machine) in the HEAD module

AUTHOR:                    $Author:$

CREATION DATE:             $Date:$

VERSION:                   $Revision:$

HPX:                       MFC5J3_C673_v8.7.2_SOP1.hpx

**************************************************************************** */

/**
@ingroup Medic_head
@{ **/

/* DO NOT MANUALLY EDIT THIS FILE - use cgeb_head_generate_code.py instead! */

#ifndef _HEAD_AUTOCODE_CFG_H_INCLUDED
#define _HEAD_AUTOCODE_CFG_H_INCLUDED

/*CHECKSUMCODE*/
#define HEAD_AUTOCODE_SPM_VelocityNotOK (0u)
#define HEAD_AUTOCODE_SPM_VelocityNotOK_Error (1u)
#define HEAD_AUTOCODE_SPM_MinVelocity (2u)
#define HEAD_AUTOCODE_SPM_AccelNotOK (3u)
#define HEAD_AUTOCODE_SPM_AccelNotOK_Error (4u)
#define HEAD_AUTOCODE_SPM_YawRateNotOK (5u)
#define HEAD_AUTOCODE_SPM_YawRateNotOK_Error (6u)
#define HEAD_AUTOCODE_SPM_DrivingDirectionNotValid (7u)
#define HEAD_AUTOCODE_SPM_DrivingDirectionNotValid_Error (8u)
#define HEAD_AUTOCODE_SPM_DrivingDirectionWrong (9u)
#define HEAD_AUTOCODE_SPM_DriverFeedbackProbNotOK_Brk (10u)
#define HEAD_AUTOCODE_SPM_DriverFeedbackProbNotOK_Error_Brk (11u)
#define HEAD_AUTOCODE_SPM_DriverFeedbackProbNotOK_Warn (12u)
#define HEAD_AUTOCODE_SPM_DriverAttentionNotOK (13u)
#define HEAD_AUTOCODE_SPM_DriverAttentionNotOK_Error (14u)
#define HEAD_AUTOCODE_SPM_DriverActivityNotOK (15u)
#define HEAD_AUTOCODE_SPM_DriverActivityNotOK_Error (16u)
#define HEAD_AUTOCODE_SPM_DIMInputDegradation (17u)
#define HEAD_AUTOCODE_SPM_DIMInputLimited (18u)
#define HEAD_AUTOCODE_SPM_CDHypothesisNotOK (19u)
#define HEAD_AUTOCODE_SPM_CDHypothesisNotOK_Error (20u)
#define HEAD_AUTOCODE_MOD_LatPreWarn (0u)
#define HEAD_AUTOCODE_MOD_LatAcuteWarn (1u)
#define HEAD_AUTOCODE_MOD_DynPreWarn (2u)
#define HEAD_AUTOCODE_MOD_DynAcuteWarn (3u)
#define HEAD_AUTOCODE_MOD_HaptDynWarn (4u)
#define HEAD_AUTOCODE_MOD_Prefill (5u)
#define HEAD_AUTOCODE_MOD_Veh_AutoBrk1 (6u)
#define HEAD_AUTOCODE_MOD_Veh_AutoBrk2 (7u)
#define HEAD_AUTOCODE_MOD_Veh_AutoBrk3 (8u)
#define HEAD_AUTOCODE_MOD_HBA_TA (9u)
#define HEAD_AUTOCODE_MOD_HBA_VDS (10u)
#define HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn (11u)
#define HEAD_AUTOCODE_MOD_CrossVru_HaptDynWarn (12u)
#define HEAD_AUTOCODE_MOD_CrossVru_HBA (13u)
#define HEAD_AUTOCODE_MOD_CrossVru_Prefill (14u)
#define HEAD_AUTOCODE_MOD_CrossVru_PreBrk (15u)
#define HEAD_AUTOCODE_MOD_CrossVru_PreBrk2 (16u)
#define HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn (17u)
#define HEAD_AUTOCODE_MOD_LongVru_HaptDynWarn (18u)
#define HEAD_AUTOCODE_MOD_LongVru_HBA (19u)
#define HEAD_AUTOCODE_MOD_LongVru_Prefill (20u)
#define HEAD_AUTOCODE_MOD_LongVru_Brk1 (21u)
#define HEAD_AUTOCODE_MOD_LongVru_Brk2 (22u)
#define HEAD_AUTOCODE_MOD_EgoVehStandstill (23u)
#define HEAD_AUTOCODE_MOD_HoldBrakeInStandstill (24u)
#define HEAD_AUTOCODE_MOD_OncomingLatentWarn (25u)
#define HEAD_AUTOCODE_MOD_OncomingDriveOffPrevention (26u)
#define HEAD_AUTOCODE_MOD_OncomingWarn (27u)
#define HEAD_AUTOCODE_MOD_OncomingBrake (28u)
#define HEAD_AUTOCODE_MOD_DynAcuteWarn_TRUCK (29u)


#define HEAD_AUTO_CFG_NO_MODULES    30u
#define HEAD_AUTO_CFG_NO_SPM_RULES  21u
/*defines the max number of otherModuleInState values (min = 1)*/
#define HEAD_AUTO_CFG_NO_OMIS       8u

/*PRQA S 3412 1*//*QAC cant handle this macro*/
#define HEAD_CALL_NO_ERROR(error, callfct) if( (error) == GDB_ERROR_NONE ) { (error) = (callfct); }

/*! @brief HEAD Module Output Function
    @general HEAD Module Output Toogle Function
    @conseq [None]
    @attention [None]
    */

typedef struct {
  HEADModuleOutputToggleFunction_t LatPreWarn;
  HEADModuleOutputToggleFunction_t LatAcuteWarn;
  HEADModuleOutputToggleFunction_t DynPreWarn;
  HEADModuleOutputWarnFunction_t DynAcuteWarn;
  HEADModuleOutputToggleFunction_t HaptDynWarn;
  HEADModuleOutputToggleFunction_t Prefill;
  HEADModuleOutputBrakeFunction_t Veh_AutoBrk1;
  HEADModuleOutputBrakeFunction_t Veh_AutoBrk2;
  HEADModuleOutputBrakeFunction_t Veh_AutoBrk3;
  HEADModuleOutputHBAFunction_t HBA_TA;
  HEADModuleOutputHBAFunction_t HBA_VDS;
  HEADModuleOutputWarnFunction_t CrossVru_DynAcuteWarn;
  HEADModuleOutputToggleFunction_t CrossVru_HaptDynWarn;
  HEADModuleOutputHBAFunction_t CrossVru_HBA;
  HEADModuleOutputToggleFunction_t CrossVru_Prefill;
  HEADModuleOutputBrakeFunction_t CrossVru_PreBrk;
  HEADModuleOutputBrakeFunction_t CrossVru_PreBrk2;
  HEADModuleOutputWarnFunction_t LongVru_DynAcuteWarn;
  HEADModuleOutputToggleFunction_t LongVru_HaptDynWarn;
  HEADModuleOutputHBAFunction_t LongVru_HBA;
  HEADModuleOutputToggleFunction_t LongVru_Prefill;
  HEADModuleOutputBrakeFunction_t LongVru_Brk1;
  HEADModuleOutputBrakeFunction_t LongVru_Brk2;
  HEADModuleOutputToggleFunction_t EgoVehStandstill;
  HEADModuleOutputToggleFunction_t HoldBrakeInStandstill;
  HEADModuleOutputToggleFunction_t OncomingLatentWarn;
  HEADModuleOutputToggleFunction_t OncomingDriveOffPrevention;
  HEADModuleOutputToggleFunction_t OncomingWarn;
  HEADModuleOutputToggleFunction_t OncomingBrake;
  HEADModuleOutputWarnFunction_t DynAcuteWarn_TRUCK;
} HEADModuleOutputStruct_t;
extern HEADModuleOutputStruct_t HEADModuleOutputData;

extern eGDBError_t HEADAutoCodeCreate(HEADModuleList_t *pModuleList, struct HEADInputData_t *pHEADInputData, void *pAddInputValueList);
extern eGDBError_t HEADAutoCodeUpdateParams(void);
extern eGDBError_t HEADSendCfgToMTS(HEADMTSStaticData_t *pStaticData, HEADMTSCfgData_t *pCfgData);

/*/CHECKSUMCODE*/


#endif /* ifndef _HEAD_AUTOCODE_CFG_H_INCLUDED */

/**@}*/

/*AUTOCHECKSUM_SHA256*/
/*d9855e2d289c7edf6d3761f3ec14be5d59bda9b1aad0a32d5828f7949c8f922b*/
/*/AUTOCHECKSUM_SHA256*/

