/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_mts_custom.c

DESCRIPTION:               Implementation of the head mts output

AUTHOR:                    $Author: uia92763 $

CREATION DATE:             $Date: 2020/06/24 08:29:45CEST $

VERSION:                   $Revision: 1.4.5.1 $  

LEGACY VERSION:            1.4.1.4          

**************************************************************************** */

/**
@defgroup head_mts_custom HEAD_MTS_CUSTOM 
@ingroup Medic_head
@{ **/

/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_HEAD20)
#include "head/head_int.h"
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  CONSTS
*****************************************************************************/
#if !defined(FCT_MEAS_ID_CGEB_HEAD_CUSTOM_HYP_PAR)
/*! @brief       FCT_MEAS_ID_CGEB_HEAD_CUSTOM_HYP_PAR

    @general     FCT_MEAS_ID_CGEB_HEAD_CUSTOM_HYP_PAR

    @conseq      @incp  
                 @decp  

    @attention   TODO: workaround as long as not defined in rte

    @typical     0x20282500uL

    @unit        SI-unit
    
       */
#define FCT_MEAS_ID_CGEB_HEAD_CUSTOM_HYP_PAR 0x20282500uL
#endif

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! @brief Additional block for customer specific hypothesis parameters */
static HEADMTSCustHypData_t HEADMTSCustHypData;

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:         HEADMTSSetDrvFeedBack                                                                        */ /*!

  @brief                update the filtered drv feedback value in HEADMTSCustHypData structure 
  
  @description          update the filtered drv feedback value in HEADMTSCustHypData structure  
                        @startuml
                        start
                        partition HEADMTSSetDrvFeedBack {
                            :Filter the Driver feedback value;
                        }
                        stop
                        @enduml
        
  @return               void

  @param[in]            fValue  : Paramter signal value
 
  @glob_in              None 
  @glob_out             @ref HEADMTSCustHypData 

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None 
  @post                 None 

  @InOutCorrelation     Not defined 
  
  @testmethod           Test of output data (dynamic module test)  

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
void HEADMTSSetDrvFeedBack(float32 fValue)
{
  HEADMTSCustHypData.DrvFeedBack.Values[0] = fValue;
}

/*************************************************************************************************************************
  Functionname:         HEADCustomMTSFreezeData                                                                         */ /*!

  @brief                writes out data to MTS 
  
  @description          writes out data to MTS  
                        @startuml
                        Start
                            :Resource Allocation;
                            Note right: Virtualaddress,length,funcid,FunctionchannelID
                            If(Null check for input data and module list) then (True)
                            : null pointer error is updated;
                            Else
                            :Get module list;
                            While(check for less than number of modules) is (True)
                            :get the current module;
                            If (Null check for input module) then (True)
                            If(check for less than the mts maximum modules ) then (Yes)
                            : Fetch the module information;
                            While(check for less than the twice the number \nof max orgroup for each modules) is (True)
                            If(check for less than the twice the number \nof max orgroup for each modules) then (True)
                            :The total time is updated; 
                            Else
                            :Reset the counts;
                            Endif
                            Endwhile(No)
                            Endif
                            Endif
                            Endwhile(No)
                            while(check for less than the mts maximum modules) is (Yes)
                            : Initialize module internal data;
                            Endwhile(No)
                            If(Null check for FCT CD hypotheses) then (True)
                            while(check for less than the no of hypotheses) is (Yes)
                            : Get the hypothesis with index;
                            Endwhile(No)
                            Endif
                            If(Is stand still deactivation enabled?) then (Yes)
                            : Hypothesis independent Signal enabled;
                            Else
                            : Hypothesis independent Signal disabled;
                            endif
                            :Freeze data;
                            Endif
                            : Return the updated error type;
                        stop
                        @enduml

        
  @return               eGDBError_t                : GDB error type is returned

  @param[in,out]        pHEADMTSExtData            : Pointer to HEAD MTS information
  @param[in,out]        pHEADMTSCodedInhibition    : Pointer to HEAD MTS coded inhibition
  @param[in,out]        pHEADMTSConditionsOKTimer  : Pointer to conditions ok timer
  @param[in]            pHEADMTSModuleCommonOut    : Pointer to MTS module information
  @param[in]            pHEADMTSData               : Pointer to head output data 
  @param[in]            pInputData                 : Pointer to head input data  
 
  @glob_in              None 
  @glob_out             @ref HEADMTSCustHypData

  @c_switch_part        @ref HEAD_USE_CUSTOM_SYSTEMFUNCTION
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None 
  @post                 None 

  @InOutCorrelation     Not defined 
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADCustomMTSFreezeData(HEADMTSSpecificData_t *pHEADMTSExtData, 
                                    HEADMTSCodedInhibition_t *pHEADMTSCodedInhibition, 
                                    HEADMTSConditionsOKTimer_t *pHEADMTSConditionsOKTimer,
                                    HEADMTSModuleCommonOut_t *pHEADMTSModuleCommonOut,
                                    HEADMTSData_t *pHEADMTSData, 
                                    const struct HEADInputData_t *pInputData)
{
  static const MEASInfo_t HEADMTSDataInfo = /*PRQA S 3205*//* Date: 2020-04-17, Reviewer: Sivaprakash Palanisamy, Reason: suppress warning for identifier 'HEADMTSDataInfo*/
  {
    FCT_MEAS_ID_CGEB_HEAD_DATA, 
    sizeof(HEADMTSData_t), 
    MEDIC_MEAS_FUNC_ID, 
    MEDIC_MEAS_FUNC_CHAN_ID
  };
  static const MEASInfo_t HEADMTSModCommonOutDataInfo = /*PRQA S 3205*//* Date: 2020-04-17, Reviewer: Sivaprakash Palanisamy, Reason: suppress warning for identifier 'HEADMTSDataInfo*/
  {
    FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT,
    sizeof(HEADMTSModuleCommonOut_t), 
    MEDIC_MEAS_FUNC_ID, 
    MEDIC_MEAS_FUNC_CHAN_ID
  };
  static const MEASInfo_t HEADMTSCondTimerDataInfo = /*PRQA S 3205*//* Date: 2020-04-17, Reviewer: Sivaprakash Palanisamy, Reason: suppress warning for identifier 'HEADMTSDataInfo*/
  {
    FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA, 
    sizeof(HEADMTSConditionsOKTimer_t), 
    MEDIC_MEAS_FUNC_ID, 
    MEDIC_MEAS_FUNC_CHAN_ID
  };
  static const MEASInfo_t HEADMTSExtDataInfo = /*PRQA S 3205*//* Date: 2020-04-17, Reviewer: Sivaprakash Palanisamy, Reason: suppress warning for identifier 'HEADMTSDataInfo*/
  { 
    FCT_MEAS_ID_CGEB_HEAD_GSM_DATA,
    sizeof(HEADMTSSpecificData_t), 
    MEDIC_MEAS_FUNC_ID, 
    MEDIC_MEAS_FUNC_CHAN_ID
  };
  static const MEASInfo_t HEADMTSOutFuncDataInfo = /*PRQA S 3205*//* Date: 2020-04-17, Reviewer: Sivaprakash Palanisamy, Reason: suppress warning for identifier 'HEADMTSDataInfo*/
  {
    FCT_MEAS_ID_CGEB_HEAD_OUTFUNC_DATA, 
    sizeof(HEADModuleOutputStruct_t), 
    MEDIC_MEAS_FUNC_ID, 
    MEDIC_MEAS_FUNC_CHAN_ID
  };
  static const MEASInfo_t HEADCodingInfoInfo = /*PRQA S 3205*//* Date: 2020-04-17, Reviewer: Sivaprakash Palanisamy, Reason: suppress warning for identifier 'HEADMTSDataInfo*/
  {
    FCT_MEAS_ID_CGEB_HEAD_CUSTOM_DATA, 
    sizeof(HEADCustomCodingInfo_t), 
    MEDIC_MEAS_FUNC_ID, 
    MEDIC_MEAS_FUNC_CHAN_ID
  };
  static const MEASInfo_t HEADMTSCustParInfo = /*PRQA S 3205*//* Date: 2020-04-17, Reviewer: Sivaprakash Palanisamy, Reason: suppress warning for identifier 'HEADMTSDataInfo*/
  {
    FCT_MEAS_ID_CGEB_HEAD_CUSTOM_HYP_PAR,
    sizeof(HEADMTSCustHypData_t), 
    MEDIC_MEAS_FUNC_ID, 
    MEDIC_MEAS_FUNC_CHAN_ID
  };
  #if (HEAD_USE_CUSTOM_SYSTEMFUNCTION == MEDIC_ON)
  static const MEASInfo_t HEADMTSCustomSystemfunctionInfo = 
  {
    FCT_MEAS_ID_BMW_CUSTOM_SYS_FCT,//123456u, //replace by RTE define
    sizeof(HEADCustomSystemfunction_t),
    MEDIC_MEAS_FUNC_ID, 
    MEDIC_MEAS_FUNC_CHAN_ID
  };
  #endif

  uint8 uiI;
  uint8 uiGSMModNr = 0u;

  eGDBError_t retValue = GDB_ERROR_NONE;

  if ( (pInputData == NULL) || (pInputData->pModuleList == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    const HEADModuleList_t *const pModuleList = pInputData->pModuleList;

    for (uiI = 0u; uiI < pModuleList->uiNrOfModules; uiI++)
    {
      HEADModule_t *pCurrModule = HEADGetModule(pModuleList, (uint32)uiI);

    if (   (pCurrModule != NULL)
        && (pCurrModule->pInternal != NULL) 
        && (pCurrModule->pInternal->InternalHeader.eModuleInternalType == HEADModuleInternalType_GSM)
       )
    {
      if (uiGSMModNr < HEAD_MTS_MAX_MODULES)
      {
        uint8 uiTimerIdx;
        HEADModuleInternalGSM_t *thisModule = ((HEADModuleInternalGSM_t *)(void*)(pCurrModule->pInternal));
        pHEADMTSExtData->ModuleInternalData[uiGSMModNr].uiModuleNr = uiI;
        pHEADMTSExtData->ModuleInternalData[uiGSMModNr].objClassSelection = thisModule->ObjClassSelection;
        pHEADMTSExtData->ModuleInternalData[uiGSMModNr].DynamicProperty = thisModule->DynamicProperty;
        pHEADMTSExtData->ModuleInternalData[uiGSMModNr].bInitialized = thisModule->bInitialized;
        pHEADMTSExtData->ModuleInternalData[uiGSMModNr].sAddInputs.fHostSpeedLastStateTransition = thisModule->sAdditionalTableInputs.fHostSpeedLastStateTransition;
        pHEADMTSExtData->ModuleInternalData[uiGSMModNr].sAddInputs.bHostSpeedLastStateTransitionOK = thisModule->sAdditionalTableInputs.bHostSpeedLastStateTransitionOK;
        for(uiTimerIdx = 0; uiTimerIdx < (HEAD_MAX_OR_GROUPS*2u); uiTimerIdx++)
        {
          if( uiTimerIdx < (pCurrModule->uiNumOrGroups * 2u) )
          {
            float32 fCondTimer = MIN_FLOAT(thisModule->pfConditionsOKTimer[uiTimerIdx], (float32) HEADPARFCT_FLOAT_MAX);
            /*PRQA S 0491 1*//*array with known length*/
            pHEADMTSConditionsOKTimer->fConditionsOKTimer[uiGSMModNr][uiTimerIdx] = HEADConvf32Tof16(fCondTimer);
          }
          else
          {
            pHEADMTSConditionsOKTimer->fConditionsOKTimer[uiGSMModNr][uiTimerIdx] = 0;
          }
        }
      }
      uiGSMModNr++;
    }
  }
  for ( ; uiGSMModNr < HEAD_MTS_MAX_MODULES; uiGSMModNr++)
  {
    pHEADMTSExtData->ModuleInternalData[uiGSMModNr].uiModuleNr = (uint8) 255u;
    pHEADMTSExtData->ModuleInternalData[uiGSMModNr].objClassSelection = 0u;
    pHEADMTSExtData->ModuleInternalData[uiGSMModNr].bInitialized = FALSE;
    pHEADMTSExtData->ModuleInternalData[uiGSMModNr].sAddInputs.fHostSpeedLastStateTransition = 0;
    pHEADMTSExtData->ModuleInternalData[uiGSMModNr].sAddInputs.bHostSpeedLastStateTransitionOK = FALSE;
  }
  /* collect custom parameters */
  if( MEDIC_p_GetHypothesisIntf() != NULL )
  {
    float32 CustDrvFeedBack;
    HEADBitField_t bfInhibition;
    
    //HEADMTSCustHypData.PreBrkActTime2.uiCustParIdx = (uint8)HEAD_CUST_PAR_BRK_ACT2 - (uint8)HEADHypOutType_CustomPar_00;
    HEADMTSCustHypData.ObjLifeTimeHiQual.uiCustParIdx = (uint8)HEAD__OBJ_LT_HQ - (uint8)HEADHypOutType_CustomPar_00;
    HEADMTSCustHypData.DrvFeedBack.uiCustParIdx = (uint8)HEAD_CUST_PAR_DRV_FDBCK - (uint8)HEADHypOutType_CustomPar_00;

    CustDrvFeedBack = HEADMTSCustHypData.DrvFeedBack.Values[0];
  

    for( uiI = 0u; uiI < MEDIC_p_GetHypothesisIntf()->Header.uiNumOfHypotheses; uiI++ )
    {
      /*get the hypothesis with index uiCurrentHyp from the hypotheses list */
      const HEADHypothesis_t * pHyp = HEADGetHypothesis(pInputData->rgHypothesisList, uiI);
      (void)HEADInhibitionCheck( pHyp, &bfInhibition);
      pHEADMTSCodedInhibition->CodedInhibitionMask[uiI] = bfInhibition;
      HEADMTSCustHypData.ObjLifeTimeHiQual.Values[ uiI ] = MEDIC_p_GetHypothesisIntf()->Hypothesis[ uiI ].Custom.fObjLifeTimeHiQual;
      HEADMTSCustHypData.DrvFeedBack.Values[ uiI ] = CustDrvFeedBack;
    }
  }
  /* Hyp independent Singnals */
  HEADMTSCustHypData.StillStandExtDeact.uiCustParIdx = (uint8)HEAD_CUST_PAR_STILLSTAND_EXT_DEACT - (uint8) HEADParamOutType_CustomPar_00_HypIndependent;
  if (bHEADDeactivationStandStill == TRUE)
  {
    HEADMTSCustHypData.StillStandExtDeact.Value = 1;
  }
  else
  {
    HEADMTSCustHypData.StillStandExtDeact.Value = 0;
  }
  /* freeze data */
  //(void) MEDIC_FREEZE_DATA(&HEADMTSDataInfo, pHEADMTSData, NULL);
  //(void) MEDIC_FREEZE_DATA(&HEADMTSModCommonOutDataInfo, pHEADMTSModuleCommonOut, NULL);
  //(void) MEDIC_FREEZE_DATA(&HEADMTSCondTimerDataInfo, pHEADMTSConditionsOKTimer, NULL);
  //(void) MEDIC_FREEZE_DATA(&HEADMTSExtDataInfo, pHEADMTSExtData, NULL);
  //(void) MEDIC_FREEZE_DATA(&HEADMTSOutFuncDataInfo, &HEADModuleOutputData, NULL);
  //(void) MEDIC_FREEZE_DATA(&HEADCodingInfoInfo, &HEADCodingInfo, NULL);

  //(void) MEDIC_FREEZE_DATA(&HEADMTSCustParInfo, &HEADMTSCustHypData, NULL);
  //#if (HEAD_USE_CUSTOM_SYSTEMFUNCTION == MEDIC_ON)
  //(void) MEDIC_FREEZE_DATA(&HEADMTSCustomSystemfunctionInfo, &HEADCustomSystemFct, NULL);
  //#endif

  MeasFreeze_Medic_GlobVar(FCT_MEAS_ID_CGEB_HEAD_DATA           , pHEADMTSData             , sizeof(HEADMTSData_t)             );
  MeasFreeze_Medic_GlobVar(FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT     , pHEADMTSModuleCommonOut  , sizeof(HEADMTSModuleCommonOut_t)  );
  MeasFreeze_Medic_GlobVar(FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA, pHEADMTSConditionsOKTimer, sizeof(HEADMTSConditionsOKTimer_t));
  MeasFreeze_Medic_GlobVar(FCT_MEAS_ID_CGEB_HEAD_GSM_DATA       , pHEADMTSExtData          , sizeof(HEADMTSSpecificData_t)     );
  MeasFreeze_Medic_GlobVar(FCT_MEAS_ID_CGEB_HEAD_OUTFUNC_DATA   , &HEADModuleOutputData    , sizeof(HEADModuleOutputStruct_t)  );
  MeasFreeze_Medic_GlobVar(FCT_MEAS_ID_CGEB_HEAD_CUSTOM_DATA    , &HEADCodingInfo          , sizeof(HEADCustomCodingInfo_t)    );
  MeasFreeze_Medic_GlobVar(FCT_MEAS_ID_CGEB_HEAD_CUSTOM_HYP_PAR , &HEADMTSCustHypData      , sizeof(HEADMTSCustHypData_t)      );
  #if (HEAD_USE_CUSTOM_SYSTEMFUNCTION == MEDIC_ON)
  MeasFreeze_Medic_GlobVar(FCT_MEAS_ID_BMW_CUSTOM_SYS_FCT       , &HEADCustomSystemFct     , sizeof(HEADCustomSystemfunction_t));
  #endif
  }

  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSCustomInit                                                                           */ /*!

  @brief                Initializes the HEAD MTS custom hypothesis data
  
  @description          Initializes the HEAD MTS custom hypothesis data
                        @startuml
                        start
                            partition HeadMTSCustomInit{
                            : HEADMTSCustHypData Update;
                            Note right: Repeat until Number of hypothesis
                            }
                        stop
                        @enduml

  @return               void

  @param[in,out]        void 
  
  @glob_in              None 
  @glob_out             @ref HEADMTSCustHypData 

  @c_switch_part       
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None 
  @post                 None 

  @InOutCorrelation     Not defined 
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
void HEADMTSCustomInit(void)
{
  uint8 uiHypoIndex;

  //HEADMTSCustHypData.PreBrkActTime2.uiCustParIdx = (uint8) HEAD_CUST_PAR_BRK_ACT2 - (uint8)HEADHypOutType_CustomPar_00;
  HEADMTSCustHypData.PreBrkActTime2.uiDummy1 = 0u;
  HEADMTSCustHypData.PreBrkActTime2.uiDummy2 = 0u;
  HEADMTSCustHypData.PreBrkActTime2.uiDummy3 = 0u;

  HEADMTSCustHypData.ObjLifeTimeHiQual.uiCustParIdx = (uint8)HEAD__OBJ_LT_HQ - (uint8)HEADHypOutType_CustomPar_00;
  HEADMTSCustHypData.ObjLifeTimeHiQual.uiDummy1 = 0u;
  HEADMTSCustHypData.ObjLifeTimeHiQual.uiDummy2 = 0u;
  HEADMTSCustHypData.ObjLifeTimeHiQual.uiDummy3 = 0u;

  HEADMTSCustHypData.DrvFeedBack.uiCustParIdx = (uint8)HEAD_CUST_PAR_DRV_FDBCK - (uint8)HEADHypOutType_CustomPar_00;
  HEADMTSCustHypData.DrvFeedBack.uiDummy1 = 0u;
  HEADMTSCustHypData.DrvFeedBack.uiDummy2 = 0u;
  HEADMTSCustHypData.DrvFeedBack.uiDummy3 = 0u;

  for(uiHypoIndex = 0u; uiHypoIndex < HEAD_MAX_NUMBER_OF_CD_HYPS; uiHypoIndex++)
  {
    HEADMTSCustHypData.PreBrkActTime2.Values[ uiHypoIndex ] = 0;
    HEADMTSCustHypData.ObjLifeTimeHiQual.Values[ uiHypoIndex ] = 0;
    HEADMTSCustHypData.DrvFeedBack.Values[ uiHypoIndex ] = 0;
  }

   /* Hyp independent Singnals */
  HEADMTSCustHypData.StillStandExtDeact.uiCustParIdx = (uint8)HEAD_CUST_PAR_STILLSTAND_EXT_DEACT - (uint8) HEADParamOutType_CustomPar_00_HypIndependent;
  HEADMTSCustHypData.StillStandExtDeact.Value = 0;
}

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif  /* !(MEDIC_CFG_HEAD20) */

/**@}*/ 
