/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_out_hbafunction.c

DESCRIPTION:               Implementation of the head hba function output

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/03/03 05:34:09CET $

VERSION:                   $Revision: 1.4.2.13 $

LEGACY VERSION:            1.37

**************************************************************************** */

/**
@defgroup head_out_hbafunction HEAD_OUT_HBAFUNCTION 
@ingroup Medic_head
@{ **/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_HEAD20)
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#include "head/head_int.h"

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

/*! @brief HBA level : Default state */
#define FCT_HEAD_HBA_LEVEL_NONE (0u)

/*! @brief HBA modules state : No module active (default)*/
#define FCT_HEAD_HBA_NO_MODULE_ACTIVE (0u)
/*! @brief HBA modules state : at least one module is active*/
#define FCT_HEAD_HBA_MODULE_ACTIVE (1u)

/*****************************************************************************
  VARIABLES
*****************************************************************************/

SET_MEMSEC_VAR(fHBADecelerationArbitrated)
/*! @brief HBA level : HBA deceleration arbitrated to 0 */
/*PRQA S 3218 STATIC_QAC*//* date: 2019-1-21, reviewer: Sadhanashree Srinivasa, Reason: this function/structure/variable can be used later in multiple functions/files  */
static float32 fHBADecelerationArbitrated = 0;

SET_MEMSEC_VAR(uiHBALevelArbitrated)
/*! @brief HBA level : HBA level arbitrated to default(0) */
static uint8 uiHBALevelArbitrated = FCT_HEAD_HBA_LEVEL_NONE;

SET_MEMSEC_VAR(HypoNrArbitrated)
/*! @brief HBA level : Number of hypotheses arbitrated */
static HEADHypothesisNr_t HypoNrArbitrated = HEADNoHypothesis;

SET_MEMSEC_VAR(uiHBALevelLastCycle)
/*! @brief HBA level : HBA level at last cycle */
static uint8 uiHBALevelLastCycle = FCT_HEAD_HBA_LEVEL_NONE;

SET_MEMSEC_VAR(uiHBAOneModuleActive)
/*! @brief HBA level : HBA level at last cycle */
static uint8 uiHBAOneModuleActive = FCT_HEAD_HBA_NO_MODULE_ACTIVE;
/*PRQA L:STATIC_QAC*/

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/

static void HEADGetCurrentHBAResults( const struct HEADModule_t * pModule, 
                                      const HEADModuleOutputHBAFunctionPar_t * pHBAFunctionPar,
                                      const Hypothesis_t* pKinHyp,
                                      float32 * pfHBADecelerationCurrent,
                                      uint8 *puiHBALevelCurrent);


/************************************************************************************************************************
  Functionname:         HEADGetCurrentHBAResults                                                                    */ /*!
 
  @brief                Get Current HBA Results
  
  @description          Get HBA levels depends on the driver deceleration. If driver is not attentive to apply the enough break 
                        during active state. In that time remaining level of deceleration will be applied through HBA. 
   
                        @startuml
                        Start
                            while(check Deceleration  level of HBA is more than current row) is (True)
                            if(check hba current deceleration less than necessary deceleration) then (Yes)
                            :set hba level;
                            endif
                            Endwhile(false)
                            If(check level found flag is true or false) then (False)
                            :update default level;
                            Endif
                            If(Check if Level needs to be adjusted due to or group)
                            while (check HBA level is more than current row) is (True)
                            if(check active hypothesis for or group is > zero) then (Yes)
                            :set hba level;
                            endif
                            Endwhile(false)
                            endif
                            if(HBA keep level First or group is greater than zero) then (Yes)
                            while (check current or group is less than number of or groups and check keep adaptation needed or not) is (Yes)
                            if(check active hypothesis for or group is > zero) then (yes)
                            : Update Keep adaption needed as TRUE;
                            Endif
                            Endwhile(false)
                            If(check keep adaption needed status) then (True)
                            If(check hba current level is less than hba last level cycle) then (Yes)
                            : set hba level;
                            Endif
                            Endif
                            Endif
                            If(check HBA  level To Requested deceleration)
                            while (check HBA level To Requested deceleration is more than current row) is (True)
                            if(check current HBA level  is less than requested deceleration) then (Yes)
                            :set hba level;
                            Else
                            : Necessary longitude deceleration  will not be overwritten;
                            endif
                            Endwhile(false)
                            endif
                            If(check deceleration with Offset is less than zero) then (Yes)
                            : update Correct deceleration with Offset;
                            Endif
                        Stop
                        @enduml
 
  @return               void
  
  @param[in]            pModule            Pointer HEAD Module 
  @param[in]            pHBAFunctionPar    HBA function parameter
  @param[in]            pKinHyp            Kinametic Hypotheses
  
  @param[out]           pfHBADecelerationCurrent  current deceleration for HBA
  @param[out]           puiHBALevelCurrent        current HBA levels
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 
  
  @pre                  should be run with bInit=True argument the first time
  @post                 None
  
  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision

  @author               Armin Vogl | armin.vogl@continental-corporation.com
**************************************************************************************************************************/
static void HEADGetCurrentHBAResults( const struct HEADModule_t * pModule, 
                                      const HEADModuleOutputHBAFunctionPar_t * pHBAFunctionPar,
                                      const Hypothesis_t* pKinHyp,
                                      float32 * pfHBADecelerationCurrent,
                                      uint8 *puiHBALevelCurrent) 
{
  uint8 currentRow=0;
  boolean levelFound = FALSE;

   _PARAM_UNUSED(pKinHyp);

  /* Set HBA-Level according to Deceleration*/
  for (currentRow=0; (currentRow < pHBAFunctionPar->HEADHBAaNecToLevelRelation_Rows) && (levelFound == FALSE); ++currentRow)
  {
    const uint8 uiCurrentRowTimesTwo = currentRow*2;
    if ((*pfHBADecelerationCurrent) <= pHBAFunctionPar->HEADHBAaNecToLevelRelation[uiCurrentRowTimesTwo])
    {
      (*puiHBALevelCurrent) = (uint8)ROUND_TO_UINT(pHBAFunctionPar->HEADHBAaNecToLevelRelation[uiCurrentRowTimesTwo+1]);
      levelFound = TRUE;
    }
  }
  if (levelFound == FALSE)
  {
    (*puiHBALevelCurrent) = pHBAFunctionPar->HBADefaultLevel;
  }

  /* Check if Level needs to be adjusted due to or group */
  if (pHBAFunctionPar->HEADHBAEvalOrGroupToLevel != 0)
  {
    for (currentRow=0; currentRow < pHBAFunctionPar->HEADHBAOrGroupToLevelTable_Rows; ++currentRow)
    {
      const uint8 orGroup = pHBAFunctionPar->HEADHBAOrGroupToLevelTable[(currentRow*2)];
      if (HEADGetActiveHypothesisForORGroup(pModule,orGroup) > 0 )
      {
        const uint8 newLevel = pHBAFunctionPar->HEADHBAOrGroupToLevelTable[(currentRow*2)+1];
        (*puiHBALevelCurrent) = CML_Max((*puiHBALevelCurrent), newLevel);
      }
    }
  }



  /* Eval Keep condition and correct Level if needed */
  if (pHBAFunctionPar->HEADHBAKeepLevelFirstOrGroup >=0 )
  {
    boolean KeepAdaptionNeeded =  FALSE;
    uint8 CurrentOrGroup;
    for (CurrentOrGroup = (uint8)pHBAFunctionPar->HEADHBAKeepLevelFirstOrGroup; 
      (CurrentOrGroup < pModule->uiNumOrGroups) && (KeepAdaptionNeeded == FALSE); ++CurrentOrGroup)
    {
      if (HEADGetActiveHypothesisForORGroup(pModule,CurrentOrGroup) > 0 )
      {
        KeepAdaptionNeeded = TRUE;
      }
    }
    if (KeepAdaptionNeeded != FALSE)
    {
      if ((*puiHBALevelCurrent) < uiHBALevelLastCycle)
      {
        (*puiHBALevelCurrent) = uiHBALevelLastCycle;
      }
    }
  }

    /* Set the HBADeceleration based on the brake level for HBA_TA */
  if (pHBAFunctionPar->HEADHBAUseLevelToReqDecel != 0)
  {
    levelFound=FALSE;
    for (currentRow=0; (currentRow < pHBAFunctionPar->HEADHBALevelToReqDecelTable_Rows) && (levelFound == FALSE); ++currentRow)
    {
      const uint8 uiCurrentRowTimesTwo = currentRow*2;
      if ((*puiHBALevelCurrent) <= pHBAFunctionPar->HEADHBALevelToReqDecelTable[uiCurrentRowTimesTwo])
      {
        (*pfHBADecelerationCurrent) = pHBAFunctionPar->HEADHBALevelToReqDecelTable[uiCurrentRowTimesTwo+1];
        levelFound = TRUE;
      }
    }
    /* If HEADHBAUseLevelToReqDecel is set and the level is not covered in the table HEADHBALevelToReqDecelTable the aNecLong will not be overwritten.
       Moreover, assertion is to be done*/
    MEDIC_ASSERT(levelFound); /*PRQA S 3112*//* date: 2019-1-21, reviewer: Sadhanashree Srinivasa, Reason: The statement only comes when logic fails ,it is an assertive failure statement  */
  }

  #if defined (HEAD_HBA_VDS_USE_CUST_ANECLONG) && (HEAD_HBA_VDS_USE_CUST_ANECLONG == MEDIC_ON)
  (*pfHBADecelerationCurrent) = pKinHyp->Custom.fLongNecAccelCustom;
  #else
  /* Correct Anec with Offset */
  if (((*pfHBADecelerationCurrent)< 0) && (((*pfHBADecelerationCurrent) + pHBAFunctionPar->HEADHBAAccelerationOffset) <= 0) )
  {
    (*pfHBADecelerationCurrent) = (*pfHBADecelerationCurrent) + pHBAFunctionPar->HEADHBAAccelerationOffset;
  }
  #endif
}

/*************************************************************************************************************************
  Functionname:         HEADOutHBAFunction                                                                            */ /*!

  @brief                HBA module output function
  
  @description          HBA module output function
                        @startuml
                        start
                            If(Null pointer check)then (yes)
                            :Module output, output params \n to HBA function structure are updated;
                            if (Check for bInit to TRUE)then(yes)
                            :Do initialization for HBA output function;
                            Else(no)
                            If( Null pointer check for input data) then(Yes)
                            If(Is the first module of the HBA output function is non zero?) then (Yes)
                            If(In HBA modules state, is any one module active?) then(Yes)
                            : Update the Fct Channel; 
                            Else
                            : Update the unknown Fct Channel; 
                            Endif
                            :Initialize the  output type;
                            Endif
                            If (Is state machine active state?) then (Yes)
                            :Get the most critical and current module hypothesis;
                            If(Is any hypothesis exist for current module?) then (Yes)
                            #orange:Get current deceleration and HBA level
                            <b> HEADGetCurrentHBAResults <b> >
                            Endif
                            If(Is current HBA level greater\n than the arbitrated level?) then (Yes)
                            : updated arbitrate current result with existing Values;
                            Elseif(Is current HBA level equal \nto the arbitrated level?) then (Yes)
                            If(Is HBA arbitrated deceleration greater\n than the current deceleration level) then (Yes)
                            : updated arbitrate current \nresult with existing Values;
                            endif
                            Else
                            : No change in Arbitrated data needed;
                            Endif
                            Else
                            : Initialization for this output type;
                            Endif
                            else
                            : Null pointer error is updated;
                            Endif
                            Endif
                            Endif
                            : Return type is updated;
                        stop
                        @enduml


  @return               eGDBError_t: Error Code is returned

  @param[in]            pInputData: Pointer to Main HEAD input data 
  @param[in]            pModule   : Pointer to HEAD module
  @param[in]            bInit     : initialization flag
 
  @glob_in              None 
  @glob_out             None 

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined 
  
  @testmethod           Test of output data (dynamic module test)   

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADOutHBAFunction(const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, boolean bInit)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  
  if ((pModule != NULL) && (pModule->pOutput != NULL) && (pModule->pOutputParams != NULL))
  {
    void *pVoidHBAFunction    = (void *)pModule->pOutput;
    const void *pVoidHBAFunctionPar = pModule->pOutputParams;

    HEADModuleOutputHBAFunction_t *pHBAFunction       = (HEADModuleOutputHBAFunction_t *)pVoidHBAFunction;
    const HEADModuleOutputHBAFunctionPar_t *pHBAFunctionPar = (const HEADModuleOutputHBAFunctionPar_t*)pVoidHBAFunctionPar;
    
    if(bInit == TRUE)
    {
      /*do initialization for this output type*/
      uiHBALevelArbitrated                                = FCT_HEAD_HBA_LEVEL_NONE;
      fHBADecelerationArbitrated                          = 0;
      HypoNrArbitrated                                    = HEADNoHypothesis;
      uiHBALevelLastCycle                                 = FCT_HEAD_HBA_LEVEL_NONE;
      MEDIC_p_GetEBAFctChan()->FctChanArbitrated          = eEBAFctChan_Unknown;
      MEDIC_p_GetEBAFctChan()->FctChanArbitratedLastCycle = eEBAFctChan_Unknown;
      uiHBAOneModuleActive                                = FCT_HEAD_HBA_NO_MODULE_ACTIVE;
      pHBAFunction->puiHBALevel                           = &uiHBALevelArbitrated;
      pHBAFunction->pfHBADeceleration                     = &fHBADecelerationArbitrated;
      pHBAFunction->pHypoNr                               = &HypoNrArbitrated;
      pHBAFunction->pFctChannel                           = &MEDIC_p_GetEBAFctChan()->FctChanArbitrated;
    }
    else
    {
      if (pInputData != NULL)
      {
        /*Reset of Arbitrated Values necessary, function only add info, no reset within function! */
        if (pHBAFunctionPar->FirstHBAModule != 0)
        {
          if (FCT_HEAD_HBA_MODULE_ACTIVE == uiHBAOneModuleActive)
          {
            /*if active in last cycle store FctChan for current cycle*/
             MEDIC_p_GetEBAFctChan()->FctChanArbitratedLastCycle = MEDIC_p_GetEBAFctChan()->FctChanArbitrated;
          }
          else
          {
             MEDIC_p_GetEBAFctChan()->FctChanArbitratedLastCycle = eEBAFctChan_Unknown;
          }
          uiHBAOneModuleActive                       = FCT_HEAD_HBA_NO_MODULE_ACTIVE;
          uiHBALevelLastCycle                        = uiHBALevelArbitrated;
          uiHBALevelArbitrated                       = FCT_HEAD_HBA_LEVEL_NONE;
          fHBADecelerationArbitrated                 = 0;
          HypoNrArbitrated                           = HEADNoHypothesis;
          MEDIC_p_GetEBAFctChan()->FctChanArbitrated = eEBAFctChan_Unknown;
        }

        if(pModule->eSMState == HEADSMState_ACTIVE)
        {
          float32 fHBADecelerationCurrent = 0;
          uint8 uiHBALevelCurrent = FCT_HEAD_HBA_LEVEL_NONE;
          const Hypothesis_t* pKinHyp = NULL;
          uint16 uiModBitF = 0;
          HEADHypothesisNr_t kinHypNr = HEADNoHypothesis;
          uiHBAOneModuleActive = FCT_HEAD_HBA_MODULE_ACTIVE;
          uiModBitF = HEADGetActiveHypothesisForModule(pModule);
          kinHypNr  = HEADGetMostCritHypOfBitfieldForModule(pInputData, uiModBitF, &pKinHyp, TRUE);
          if (kinHypNr != HEADNoHypothesis)
          {
            fHBADecelerationCurrent = pKinHyp->fLongNecAccel;
            HEADGetCurrentHBAResults(pModule, pHBAFunctionPar, pKinHyp, &fHBADecelerationCurrent, &uiHBALevelCurrent);
          }
          /* If no error occurred arbitrate currentResult with existing Values */
          
          if (uiHBALevelCurrent > uiHBALevelArbitrated)
          {
            uiHBALevelArbitrated                       = uiHBALevelCurrent;
            HypoNrArbitrated                           = kinHypNr;
            fHBADecelerationArbitrated                 = fHBADecelerationCurrent;
            MEDIC_p_GetEBAFctChan()->FctChanArbitrated = ( MEDIC_p_GetEBAFctChan()->FctChanArbitratedLastCycle | HEADGetFctChannel(pKinHyp));
          }
          else if (uiHBALevelCurrent == uiHBALevelArbitrated)
          {
            if (fHBADecelerationArbitrated > fHBADecelerationCurrent)
            {
              HypoNrArbitrated                           = kinHypNr;
              fHBADecelerationArbitrated                 = fHBADecelerationCurrent;
              MEDIC_p_GetEBAFctChan()->FctChanArbitrated = ( MEDIC_p_GetEBAFctChan()->FctChanArbitratedLastCycle | HEADGetFctChannel(pKinHyp));
            }
          }
          else /*(uiHBALevelCurrent < uiHBALevelArbitrated) */
          {
            /* No change in Arbitrated data needed */
          }
        }
      }
      else
      {
        uiHBALevelArbitrated                       = FCT_HEAD_HBA_LEVEL_NONE;
        fHBADecelerationArbitrated                 = 0;
        HypoNrArbitrated                           = HEADNoHypothesis;
        MEDIC_p_GetEBAFctChan()->FctChanArbitrated = eEBAFctChan_Unknown;
        retValue = GDB_ERROR_POINTER_NULL;
      }
    } /*init false*/
  }
  else
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }

  return retValue;
}

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif  /* !(MEDIC_CFG_HEAD20) */

/**@}*/
