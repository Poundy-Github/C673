/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_mts.c

DESCRIPTION:               Implementation of the head MTS output

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/17 13:55:06CEST $

VERSION:                   $Revision: 1.17 $

LEGACY VERSION:            1.33

**************************************************************************** */
/**
@defgroup head_mts HEAD_MTS  
@ingroup Medic_head
@{ **/
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"

#if !(MEDIC_CFG_HEAD20)
#include "head/head_int.h"

/*PRQA S 0314 EOF #date: 2020-06-02, reviewer: Nalina M, reason: Case to void intended as use of generic interface */
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

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static eGDBError_t HEADMTSNextParameter(const HEADInputData_t *pInputData, HEADMTSParameterData_t *pMTSParamData, HEADMTSStaticData_t *pMTSStaticData);

/*************************************************************************************************************************
  Functionname:         HEADMTSInit                                                                                */ /*!

  @brief                initializes the MTS structure

  @description          initializes the MTS structure
                        @startuml
                        Start
                            :Initialize MTS Structure;
                            Note right: Note right: Initialize all the Members of the \nMTS Static Data Structure.
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in,out]        pMTSStaticData : Pointer to MTS Static Data for internal mts sending process

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
eGDBError_t HEADMTSInit(HEADMTSStaticData_t *pMTSStaticData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if(pMTSStaticData == NULL)
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    pMTSStaticData->pParLastWrittenParameter = NULL;
    pMTSStaticData->uiParLastWrittenModNr = 255u;
    pMTSStaticData->uiParLastWrittenParNr = 0u;
    pMTSStaticData->uiParLastWrittenTabPos = 0u; 
    pMTSStaticData->eParLastWrittenOperator = (HEADParamOperator_t) HEADParamOperator_LESSTHAN;
    pMTSStaticData->uiParLastWrittenOutType = (uint8)HEADParamOutType_FirstValue;

    pMTSStaticData->uiModNamesLastWritteModNameNr = 0u;

    pMTSStaticData->uiSPMRulesLastWrittenRuleNr = 0u;

    pMTSStaticData->uiCfgPartPos = 0u;
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADMTSNextParameter                                                                        */ /*!
  
  @brief                go to the next parameter in the cue

  @description          Go to the next scalar or table parameter in the            
                        Queue. The all module parameter information are 
                        Updated in the MTS.
                        
                        @startuml
                        Start
                            If(NULL pointer check) then (yes)
                            : update return type as null pointer error;
                            Else
                            If(check last written module is more than the no of modules)
                            :set module and last written parameter 
                             in the MTS static data structure;
                            endif
                            :get current module information;
                            If(NULL pointer check for current module ) then (Yes)
                            If(Is it  Last written parameter equal to null?) then (Yes)
                            :get internal data information;
                            If(Is it  Last written output value equal to maximum output value?) then (Yes)
                            : reinitialize the all module;
                            Endif
                            While(check Last written parameter equal to null and Last written output value less than maximum output value ?) is (Yes)
                            : module list will be updated;
                            Endwhile (false)
                            If(Is it  Last written parameter equal to null?) then (Yes)
                            :Next module will be executed;
                            Else
                            :set the table position and increase the parameter count;
                            Endif
                            Else
                            If(check current parameter is in a table) then (Yes)
                            If(check the number of table rows
                            More than the last written table position rows) then (Yes)
                            :update table written parameter;
                            If(Is it  Last written parameter equal to null?) then (No)
                            :set the table position and increase the parameter count;
                            Endif
                            Else
                            : Next table rows already selected;
                             endif
                            else
                            : Get scalar value of the next parameter ;
                            If(Is it  Last written parameter equal to null?) then (No)
                            :set the table position and increase the parameter count;
                            Endif
                            Endif
                            Endif
                            Else 
                            : jump to the next module;
                            Endif
                            : assign static data of the internal mts
                            To head MTS parameter data structure;
                            Endif
                            :return the updated return value;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in]            pInputData : Pointer to HEAD input data
  @param[in]            pMTSParamData : pointer to MTS parameter data
  @param[in]            pMTSStaticData : Pointer to MTS Static Data for internal mts sending process

  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision

  @author               Robert Thiel | robert.thiel@contiautomotive.com
**************************************************************************************************************************/
static eGDBError_t HEADMTSNextParameter(const HEADInputData_t *pInputData, HEADMTSParameterData_t *pMTSParamData, HEADMTSStaticData_t *pMTSStaticData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ( (pInputData == NULL) || (pMTSParamData == NULL) || (pMTSStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    HEADModule_t *pCurrModule;
    
    if (pMTSStaticData->uiParLastWrittenModNr >= pInputData->pModuleList->uiNrOfModules)
    {
      /*set back to first parameter*/
      pMTSStaticData->uiParLastWrittenModNr = 0u;
      pMTSStaticData->pParLastWrittenParameter = NULL;
    }
  
    pCurrModule = HEADGetModule(pInputData->pModuleList, (uint32) pMTSStaticData->uiParLastWrittenModNr);
    
    /* now the moduleNr should be in range*/
    /*case 1 - module is a GSM module - others do not use the parameter cue...*/
    if (   (pCurrModule != NULL) 
        && (pCurrModule->pInternal != NULL) 
        && (pCurrModule->pInternal->InternalHeader.eModuleInternalType == HEADModuleInternalType_GSM))
    {
      if(pMTSStaticData->pParLastWrittenParameter == NULL)
      {
        HEADModuleInternalGSM_t *pGSMInternal = (HEADModuleInternalGSM_t *)((void *)(pCurrModule->pInternal));
        if(pMTSStaticData->uiParLastWrittenOutType == (uint8)HEADParamOutType_Max)
        {
          /*already looped through whole module: reinit*/
          pMTSStaticData->eParLastWrittenOperator = (uint8)HEADParamOperator_LESSTHAN;
          pMTSStaticData->uiParLastWrittenOutType = (uint8)HEADParamOutType_FirstValue;
        }
        /*while loop through rootpointerlist in a module*/
        while(  (pMTSStaticData->uiParLastWrittenOutType < (uint8)HEADParamOutType_Max) 
             && (pMTSStaticData->pParLastWrittenParameter == NULL)
             )
        {
          if(pMTSStaticData->eParLastWrittenOperator == (uint8)HEADParamOperator_LESSTHAN)
          {
            pMTSStaticData->eParLastWrittenOperator = (uint8)HEADParamOperator_GREATERTHAN;
          }
          else
          {
            pMTSStaticData->eParLastWrittenOperator = (uint8)HEADParamOperator_LESSTHAN;
            pMTSStaticData->uiParLastWrittenOutType++;
          }
          if(pMTSStaticData->uiParLastWrittenOutType < (uint8)HEADParamOutType_Max)
          {
            pMTSStaticData->pParLastWrittenParameter = pGSMInternal->pRootPointerList[pMTSStaticData->eParLastWrittenOperator][pMTSStaticData->uiParLastWrittenOutType];
          }
        }
        
        
        /*not more valid parameter in the module: pParLastWrittenParameter == NULL*/
        if(pMTSStaticData->pParLastWrittenParameter == NULL)
        {
          /*jump to the next module*/
          pMTSStaticData->uiParLastWrittenModNr++;
          pMTSStaticData->pParLastWrittenParameter = NULL;
          pMTSStaticData->uiParLastWrittenParNr = 0u;
        }
        else
        {
          pMTSStaticData->uiParLastWrittenTabPos = 0u;
          pMTSStaticData->uiParLastWrittenParNr++;
        }
      }
      else
      {
        /*parameter is already defined*/        
        /*case 3 - check if current parameter is in a table*/
        if ((HEADParamMainType_t)(pMTSStaticData->pParLastWrittenParameter->ParameterType.sParameterType.ParamMainType) == (HEADParamMainType_t) HEADParamMainType_Table)
        {
          /*case 4 - check if table is already finished*/
          const HEADParameterTable_t *pTable = (const HEADParameterTable_t*)((const void *)(pMTSStaticData->pParLastWrittenParameter));
          /*increase position in table*/
          pMTSStaticData->uiParLastWrittenTabPos += HEAD_MTS_MAX_TABLE_ROWS;
          if(pTable->uiNrOfTableRows <= pMTSStaticData->uiParLastWrittenTabPos)
          {
            /*table already transfered - jump to next parameter*/
            pMTSStaticData->pParLastWrittenParameter = (const HEADParameterEmpty_t *)(pMTSStaticData->pParLastWrittenParameter->ParameterType.pNextRelevantParam);
            if(pMTSStaticData->pParLastWrittenParameter != NULL)
            {
              pMTSStaticData->uiParLastWrittenTabPos = 0u;
              pMTSStaticData->uiParLastWrittenParNr++;
            }
          }
          else
          {
            /*nothing to do - next table rows already selected*/
          }
        }
        else
        {
          /*scalar - directly jump to the next parameter*/
          pMTSStaticData->pParLastWrittenParameter = (const HEADParameterEmpty_t *)(pMTSStaticData->pParLastWrittenParameter->ParameterType.pNextRelevantParam);
          if(pMTSStaticData->pParLastWrittenParameter != NULL)
          {
            pMTSStaticData->uiParLastWrittenTabPos = 0u;
            pMTSStaticData->uiParLastWrittenParNr++;
          }
        }
      }
    }
    else
    {
      /*no GSM module: jump to the next module*/
      pMTSStaticData->uiParLastWrittenModNr++;
      pMTSStaticData->pParLastWrittenParameter = NULL;
    }
    pMTSParamData->uiParNr    = pMTSStaticData->uiParLastWrittenParNr;
    pMTSParamData->uiTablePos = pMTSStaticData->uiParLastWrittenTabPos;
    pMTSParamData->uiModuleNr = pMTSStaticData->uiParLastWrittenModNr;
  }
  
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendParameters                                                                        */ /*!

  @brief                writes one head parameter to head MTS output

  @description          writes one head parameter to head MTS output
                        @startuml
                        Start
                            :Find the next Parameter;
                                Note right:Find the next parameter to be written in MTS.
                            While(is the parameter is valid?) is (no)
                                Floating Note left
                                    If the current parameter is not valid,
                                    Loop through all the parameters till we find the valid parameter.
                                End note
                                Floating Note right
                                    The loop will get terminated only if the valid parameter is found 
                                    or if we looped through all the modules. 
                                End note
                            :GO to next parameter;
                            Endwhile

                            If (is it the valid parameter?) then (yes)
                            :Send parameter to MTS;
                                Note left
                                Make the parameter as valid in MTS data structure;
                                Write Parameter Data to MTS data structure based 
                                on the Parameter Type.
                                (it can be either scalar or table parameter)
                                End note
                            Else(no)
                            :No Valid parameter;
                                Note right:if no valid parameter found, return invalid 
                            Endif
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error.

  @param[in]            pInputData : Pointer to HEAD input data
  @param[in,out]        pStaticData : Pointer to MTS Static Data for internal mts sending process
  @param[in,out]        pMTSParamData : pointer to MTS parameter data

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
eGDBError_t HEADMTSSendParameters(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pStaticData, HEADMTSParameterData_t *pMTSParamData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData == NULL) || (pMTSParamData == NULL) || (pStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {    
    uint8  uiCurrentModule;
    uint8  uiLoopCounter = 0u;
    /*find next parameter in the list*/
    retValue = HEADMTSNextParameter(pInputData, pMTSParamData, pStaticData);
    uiCurrentModule = pStaticData->uiParLastWrittenModNr;

    /*while (current parameter not valid) go to the next*/
    while ((pStaticData->pParLastWrittenParameter == NULL) && (uiLoopCounter < 2u))
    {      
      retValue = HEADMTSNextParameter(pInputData, pMTSParamData, pStaticData);
      if(uiCurrentModule >= pStaticData->uiParLastWrittenModNr)
      {
        /*if current modulenr >= modulenr at the start -> increase one loop*/
        uiLoopCounter++;
      }
    }
    if(pStaticData->pParLastWrittenParameter != NULL)
    {
      /*valid parameter found*/
      pMTSParamData->bParamValid = 1u;
      pMTSParamData->sParameterHeader = pStaticData->pParLastWrittenParameter->ParameterType.sParameterType;
      pMTSParamData->uiSpecialParInfo = pStaticData->pParLastWrittenParameter->uiSpecialParInfo;
      if (pMTSParamData->sParameterHeader.ParamMainType == (HEADParamMainType_t) HEADParamMainType_Scalar)
      {
        pMTSParamData->fScalarValue_DefaultX = HEADConvf16Tof32(((const HEADParameterScalar_t *)((const void *)(pStaticData->pParLastWrittenParameter)))->f16RawValue);
      }
      else
      {
        if (pMTSParamData->sParameterHeader.ParamMainType == (HEADParamMainType_t) HEADParamMainType_Table)/*PRQA S 2995, 2991 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
        {
          uint8 uiI;
          const HEADParameterTable_t *pTable = ((const HEADParameterTable_t *)((const void *)(pStaticData->pParLastWrittenParameter)));
          pMTSParamData->fScalarValue_DefaultX = HEADConvf16Tof32(pTable->f16DefaultValue);
          pMTSParamData->eTableType = pTable->TableType;
          pMTSParamData->uiNrOfTableRows = pTable->uiNrOfTableRows;
          for(uiI = 0u; uiI < HEAD_MTS_MAX_TABLE_ROWS; uiI++)
          {
            if ((uiI+pStaticData->uiParLastWrittenTabPos) < pTable->uiNrOfTableRows)
            {
              const uint8 uiTblIdx = 2u*uiI;
              const uint8 uiTblLastIdx = 2u*(uiI+pStaticData->uiParLastWrittenTabPos);
              if(pTable->eTableFloatType == HEADParameterTableFloatType_f16)
              {
                /* PRQA S 0491 2*//* MISRA rule 17.4: reviewer name: Thomas Diepolder, date: 17.03.2011 reason: Bounds are explicitly checked against the table parameters */
                pMTSParamData->fTable[uiTblIdx]    = HEADConvf16Tof32(((const f16_t*)pTable->pTable)[uiTblLastIdx]);
                pMTSParamData->fTable[uiTblIdx+1u] = HEADConvf16Tof32(((const f16_t*)pTable->pTable)[uiTblLastIdx+1u]);
              }
              else
              {
                /* PRQA S 0491 2*//* MISRA rule 17.4: reviewer name: Thomas Diepolder, date: 17.03.2011 reason: Bounds are explicitly checked against the table parameters */
                pMTSParamData->fTable[uiTblIdx]    = ((const float32*)pTable->pTable)[uiTblLastIdx];
                pMTSParamData->fTable[uiTblIdx+1u] = ((const float32*)pTable->pTable)[uiTblLastIdx+1u];
              }
            }
          }
        }
        else
        {
          /*shouldn't happen*/
          pMTSParamData->bParamValid = 0u;
        }
      }
    }
    else
    {
      /*no valid parameter found -> return invalid*/
      pMTSParamData->bParamValid = 0u;
    }
  }

  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendModuleName                                                                        */ /*!

  @brief                writes Module Name and Module Type to MTS(one module per cycle)

  @description          writes Module Name and Module Type to MTS(one module per cycle)
                        @startuml
                        Start
                            :Increment Module Count;
                                Note left: Increment the Module Name count \nfor MTS send process.
                            If (is the Module Number valid?) then (no)
                            :Reset Module Count;
                                Note right: Reset the Module Name count.
                            Else(yes)
                            Endif
                            :Fetch the Module;
                                Note left:Fetch the module correspond to \nModule name count.
                            :Send Module Name to MTS;
                            Note right
                                Writes Module Type and Module Name to MTS
                                ->Module name is a string with Zero termination.
                            End note
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in]            pInputData : Pointer to HEAD input data
  @param[in,out]        pMTSStaticData : Pointer to MTS Static Data for internal mts sending process
  @param[in,out]        pMTSModuleData : Pointer to MTS Module Data

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
eGDBError_t HEADMTSSendModuleName(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pMTSStaticData, HEADMTSModuleName_t *pMTSModuleData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData == NULL) || (pMTSModuleData == NULL) || (pInputData->pModuleList == NULL) || (pMTSStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    HEADModule_t *pModule;
    pMTSStaticData->uiModNamesLastWritteModNameNr++;    
    /*just in case it's out of bounds*/
    if(pMTSStaticData->uiModNamesLastWritteModNameNr >= pInputData->pModuleList->uiNrOfModules)
    {
      pMTSStaticData->uiModNamesLastWritteModNameNr = 0u;
    }
    pMTSModuleData->uiModNr = pMTSStaticData->uiModNamesLastWritteModNameNr;
    pModule = HEADGetModule(pInputData->pModuleList, (uint32)pMTSStaticData->uiModNamesLastWritteModNameNr);
    
    if(pModule != NULL)
    {
      if(pModule->pInternal != NULL)
      { 
        pMTSModuleData->eInternalType = (HEADModuleInternalType_t)pModule->pInternal->InternalHeader.eModuleInternalType;
      }
      else
      {
        retValue = GDB_ERROR_POINTER_NULL;
      }         

      if(pModule->strModuleName != NULL)/*PRQA S 2995 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
      {
        uint8 uiI, uiLast = 0u;
        for(uiI = 0u; (uiI < (HEAD_MODULENAME_LENGTH-1u)) && (uiLast == uiI); uiI++)
        {
          if(pModule->strModuleName[uiI] != 0u)
          {
            pMTSModuleData->strModuleName[uiI] = pModule->strModuleName[uiI];
            uiLast = uiI + 1u;
          }
        }  
        pMTSModuleData->strModuleName[uiLast] = 0u;
      }
      else
      {
        pMTSModuleData->strModuleName[0] = 0u;
      }
    }
    else
    {
      retValue = GDB_ERROR_POINTER_NULL;
    }    
  }
  return retValue;
} 

/*************************************************************************************************************************
  Functionname:         HEADMTSSendModuleCommonData                                                                        */ /*!

  @brief                writes Modules Common Data to MTS

  @description          writes Modules Common Data to MTS
                        @startuml
                        Start
                        :Fetch total Number of \nModules;
                        Note right:Fetch the total Number of Modules from \nHEAD Module List.       
                            partition GoThroughAllTheModules {
                            while (is the Module Number Valid?) is (yes)
                            :Fetch the Module;
                                Note left:Fetch the module correspond to \nModule Number.
                            :Send Module Common Data \nto MTS;
                            Note right
                                Writes Current Module State, QoS, Reported Error, orGroup Hypothesis array and
                                relevant state time to MTS
                            End note
                            endwhile (no)
                            }
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, otherwise an error code is returned.

  @param[in]            pInputData : Pointer to HEAD input data
  @param[in,out]        pMTSModuleCommonData : Pointer MTS Module Common Output Data

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
eGDBError_t HEADMTSSendModuleCommonData(const HEADInputData_t *pInputData, HEADMTSModuleCommonOut_t *pMTSModuleCommonData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData == NULL) || (pMTSModuleCommonData == NULL) || (pInputData->pModuleList == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    uint8 uiI;
    uint8 uiJ;
    pMTSModuleCommonData->uiNrOfModules = pInputData->pModuleList->uiNrOfModules;
    for(uiI = 0u; uiI < pMTSModuleCommonData->uiNrOfModules; uiI++)
    {
      if(uiI < HEAD_MTS_MAX_MODULES)
      {
        HEADModule_t *pModule = HEADGetModule(pInputData->pModuleList, (uint32)uiI);

        if (pModule != NULL)
        {
          pMTSModuleCommonData->sModuleInfo[uiI].eState         = (HEADSMState_t) pModule->eSMState;
          pMTSModuleCommonData->sModuleInfo[uiI].eQoS           = (HEADModuleQoS_t) pModule->eQoS;
          pMTSModuleCommonData->sModuleInfo[uiI].eReportedError = (HEADModuleRepError_t) pModule->eReportedError;
          for (uiJ = 0u; uiJ < pModule->uiNumOrGroups; uiJ++)
          {
            pMTSModuleCommonData->sModuleInfo[uiI].uiHypInOrGroup[uiJ] = pModule->uiHypInOrGroup[uiJ];
          }
          for (uiJ = 0u; uiJ < (uint8)HEADSMState_Max; uiJ++)
          {
            float32 fRelStateTimer;
            
            if (pModule->fStateTimer[uiJ] > 0.0f )
            {
               fRelStateTimer = pModule->fStateTimer[uiJ];
            }
            else
            {
               fRelStateTimer = pModule->fNotInStateTimer[uiJ];
            }
            
            fRelStateTimer = MIN_FLOAT(fRelStateTimer, HEAD_MTS_MAX_STATE_TIME);
            pMTSModuleCommonData->sModuleInfo[uiI].f16RelStateTimer[uiJ] = HEADConvf32Tof16(fRelStateTimer);
          }
        }
        else
        {
          retValue = GDB_ERROR_POINTER_NULL;
        }
      }
      else
      {
        retValue = GDB_ERROR_ARRAY_OVERFLOW;
      }
    }
  }
  return retValue;
} 

/*************************************************************************************************************************
  Functionname:         HEADMTSSendSPMRule                                                                          */ /*!

  @brief                writes SPM Rule to MTS(one SPM Rule per cycle)

  @description          writes SPM Rule to MTS(one SPM Rule per cycle)
                        @startuml
                        Start
                            If (is the Rule Number valid?) then (no)
                            :Reset Rule Number Count;
                                Note right: Reset the SPM Rule Number count \nfor MTS Send Process.
                            Else(yes)
                            Endif
                            :Fetch the SPM Rule;
                                Note left:Fetch the SPM Rule correspond to \nRule Number count.
                            :Send SPM Rule to MTS;
                                Note right:Writes the Current SPM Rule to MTS.
                            :Increment SPM Rule Number \nCount;
                                Note right:Increment the SPM Rule Number Count \nfor MTS Send process
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in]            pInputData : Pointer to HEAD input data
  @param[in,out]        pMTSStaticData : Pointer to MTS Static Data for internal mts sending process
  @param[in,out]        pMTSSPMModule : Pointer MTS SPM rule

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
eGDBError_t HEADMTSSendSPMRule(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pMTSStaticData, HEADMTSSPMRule_t *pMTSSPMModule)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  HEADSPMCheck_t *pCurrentRule;
  if ((pInputData == NULL) || (pMTSSPMModule == NULL) || (pMTSStaticData == NULL) || (pInputData->pSPMRules == NULL) || (pInputData->pSPMRules->rgSPMRules == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    if(pMTSStaticData->uiSPMRulesLastWrittenRuleNr >= pInputData->pSPMRules->uiNrOfSPMRules)
    {
      pMTSStaticData->uiSPMRulesLastWrittenRuleNr = 0u;
    }
    
    pCurrentRule = HEADSPMGetRule(pInputData->pSPMRules->rgSPMRules, (uint32)pMTSStaticData->uiSPMRulesLastWrittenRuleNr);

    if (pCurrentRule != NULL)
    {
      pMTSSPMModule->bitModules       = pCurrentRule->bitModules;
      pMTSSPMModule->eQOS             = pCurrentRule->eQOS;
      pMTSSPMModule->eReportedError   = pCurrentRule->eReportedError;
      pMTSSPMModule->fValue           = HEADConvf16Tof32(pCurrentRule->f16Value);
      pMTSSPMModule->uiInSigIdent     = (uint8)pCurrentRule->eHEADMTSInSigIdent;
      pMTSSPMModule->uiNeededTime     = pCurrentRule->uiNeededTime;
      pMTSSPMModule->uiRuleNr         = pMTSStaticData->uiSPMRulesLastWrittenRuleNr;
      pMTSSPMModule->eFunction        = HEADSPMGetBitsFunction(pCurrentRule->bitCheckType);
      pMTSSPMModule->eOperator        = HEADSPMGetBitsOperator(pCurrentRule->bitCheckType);
      pMTSSPMModule->eSignalOrSigStat = HEADSPMGetBitsSignal(pCurrentRule->bitCheckType);
      pMTSSPMModule->eStdDevType      = HEADSPMGetBitsStdDeviation(pCurrentRule->bitCheckType);
      pMTSSPMModule->uiNrOfRules      = pInputData->pSPMRules->uiNrOfSPMRules;

      pMTSStaticData->uiSPMRulesLastWrittenRuleNr++;
    } 
    else
    {
      retValue = GDB_ERROR_POINTER_NULL;
    }
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendInputData                                                                        */ /*!

  @brief                writes input data to MTS

  @description          writes input data to MTS
                        @startuml
                        Start
                            :Send Input Data to MTS;
                            Note right:Writes HEAD Main Input Data to MTS
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in]            pInputData : Pointer to HEAD input Data
  @param[in,out]        pMTSInputData : Pointer to HEAD MTS Input Data

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
eGDBError_t HEADMTSSendInputData(const HEADInputData_t *pInputData, HEADMTSInputData_t *pMTSInputData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData == NULL) || (pMTSInputData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    pMTSInputData->eExternalOpMode          = (uint8)pInputData->eOpMode;
    pMTSInputData->eHEADMainMode            = pInputData->eHEADMainMode;
    pMTSInputData->fCycleTime               = pInputData->fCycleTime;
    pMTSInputData->uiNumberOfHEADHypotheses = pInputData->uiNumberOfHEADHypotheses;
    pMTSInputData->uiCurrentCycle           = pInputData->uiCurrentCycle;
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendSPMRuleTimes                                                                     */ /*!

  @brief                writes dynamic information from spm rules to MTS

  @description          writes dynamic information from spm rules to MTS
                        @startuml
                        Start
                        :Find Max Possible Number \nof SPM Rules;
                        Note right:Find the Maximum Number of SPM Rules that \ncan be Written to MTS.
                            partition GoThroughAllTheSPMRules {
                            while (is the Rule Number valid?) is (yes)
                            :Fetch the SPM Rule; 
                                Note left:Fetch the SPM Rule correspond to \nRule Number.
                            :Send Current Time to MTS;
                                Note right: Writes the Current SPM Rule Time Count to MTS
                            endwhile (no)
                            }
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in]            pInputData : Pointer to HEAD input Data
  @param[in,out]        pMTSSPMTimers : Pointer to MTS SPMTimers

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
eGDBError_t HEADMTSSendSPMRuleTimes(const HEADInputData_t *pInputData, HEADMTSSPMTimers_t *pMTSSPMTimers)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData == NULL) || (pMTSSPMTimers == NULL) || (pInputData->pSPMRules == NULL) || (pInputData->pSPMRules->rgSPMRules == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    const uint8 uiMaxRules = (uint8)MIN(pInputData->pSPMRules->uiNrOfSPMRules, HEADMTSSPMRulesMax);
    uint8 uiI;
    for(uiI = 0u; uiI < uiMaxRules; uiI++)
    {
      HEADSPMCheck_t *pSPMRule = HEADSPMGetRule(pInputData->pSPMRules->rgSPMRules, (uint32)uiI);
      pMTSSPMTimers->rguiTime[uiI] = pSPMRule->uiCurrentTimer;
    }
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendInputSignal                                                                        */ /*!

  @brief                writes dynamic information of one input signal to MTS

  @description          writes dynamic information of one input signal to MTS
                        @startuml
                        Start
                        If ((No_Error)) then (yes) 
                          If ((Is MTS Input signal number valid?)) then (yes)
                            If ((Is pointer to HEAD Input signal valid?)AND
                        (Is pointer to MTS Input signal list valid?)) then (yes)
                                  :Send Input Signal information to MTS;
                              Note:Send Signal Quality, Type, Standard Deviation, Identity and Value to MTS.
                              If ((Is signal type Signed Intiger?)) then (yes)  
                                #orange:Get signed integer Value from HEAD Input signal
                                <b>HEADGetInputValue_sint32</b> >
                                :Send value to MTS;
                              Else if ((Is Signal Type Unsigned Intiger?)) then (yes)
                                #orange:Get Unsigned integer Value from HEAD Input signal
                                <b>HEADGetInputValue_uint32</b> >
                                :Send value to MTS;
                              Else if (((Is Signal Type float?)) then (yes)
                                #orange:Get float Value from HEAD Input signal and send 
                        \nthe value to MTS.
                                <b>HEADGetInputValue_float32</b> >
                              Else if (((Is Signal Type Bool?)) then (yes)
                                #orange:Get Boolean Value from HEAD Input signal
                                <b>HEADGetInputValue_boolean</b> >
                                :Send value to MTS;
                              Else (no)
                                :Set Unknown Type error;
                              Endif
                            Else (no)
                              :Set Null pointer error;
                            Endif
                            Floating note: Signal value need to fetched based on the Signal Type.
                          Else (no)
                            :Set Array Overflow error;
                          Endif
                        Endif
                        Stop
                        @enduml

  @return               void

  @param[in]            pInputSignal : Pointer to HEAD Input data
  @param[in]            pMTSInputSignalList : pointer to MTS Input signal list.
  @param[in]            uiMTSInputSigNr : MTS Input signal number.
  @param[in]            eHEADMTSInSigIdent : MTS Input signal Identifier
  @param[in]            retErrorValue : Pointer to Error value

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
void HEADMTSSendInputSignal(const struct HEADInputValue_t *pInputSignal, 
                                   HEADMTSInputSignalList_t *pMTSInputSignalList, 
                                   uint8 uiMTSInputSigNr, HEADMTSInSigIdent_t eHEADMTSInSigIdent, eGDBError_t* retErrorValue)
{
  if (*retErrorValue == GDB_ERROR_NONE)
  {
    if (uiMTSInputSigNr < HEADMTSMaxInputSignals)
    {
      if ((pInputSignal != NULL) && (pMTSInputSignalList != NULL))
      {
        pMTSInputSignalList->rgInputSignal[uiMTSInputSigNr].eSigStat = pInputSignal->eSignalQuality;
        pMTSInputSignalList->rgInputSignal[uiMTSInputSigNr].eSigType = pInputSignal->eSignalType;
        pMTSInputSignalList->rgInputSignal[uiMTSInputSigNr].fStdDev = pInputSignal->fStdDev;
        pMTSInputSignalList->rgInputSignal[uiMTSInputSigNr].HEADMTSInSigIdent = (uint8)eHEADMTSInSigIdent;
        pMTSInputSignalList->rgInputSignal[uiMTSInputSigNr].isValid = b_TRUE;

        switch (pInputSignal->eSignalType)
        {
        case HEADInputSignalType_SignedInt:
          {
            sint32 iVal;
            (void)HEADGetInputValue_sint32(*pInputSignal, 0, &iVal);
            pMTSInputSignalList->rgInputSignal[uiMTSInputSigNr].fValue = (float32)iVal;
          }
          break;
        case HEADInputSignalType_UnsignedInt:
          {
            uint32 uiVal;
            (void)HEADGetInputValue_uint32(*pInputSignal, 0, &uiVal);
            pMTSInputSignalList->rgInputSignal[uiMTSInputSigNr].fValue = (float32)uiVal;
          }
          break;
        case HEADInputSignalType_Float:
          {
            (void)HEADGetInputValue_float32(*pInputSignal, 0.0f, &(pMTSInputSignalList->rgInputSignal[uiMTSInputSigNr].fValue));
          }
          break;
        case HEADInputSignalType_Bool:
          {
            boolean bVal;
            (void)HEADGetInputValue_boolean(*pInputSignal, b_FALSE, &bVal);
            pMTSInputSignalList->rgInputSignal[uiMTSInputSigNr].fValue = (float32)bVal;
          }
          break;
        default:
          *retErrorValue = GDB_ERROR_UNKNOWN_TYPE;
          break;
        }
      }
      else
      {
        *retErrorValue = GDB_ERROR_POINTER_NULL;
      }
    }
    else
    {
      *retErrorValue = GDB_ERROR_ARRAY_OVERFLOW;
    }
  }
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendInputSignals                                                                        */ /*!

  @brief                writes dynamic information from input signals to MTS

  @description          writes dynamic information from input signals to MTS
                        @startuml
                        Start
                        :Set LocalError as None;
                        If ((Is InputData Pointer Valid?) AND
                        (IS InputValueList Pointer valid?) AND
                        (Is MTSInputSignalList pointer valid?)) then (yes)
                            #orange:Send input value list to MTS
                            <b>HEADMTSSendInputSignal </b>  >
                            Note 
                            The Input Values List contains: Longitudinal Velocity, Longitudinal Acceleration,
                            YawRate, Driving Direction, Host vehicle trajectory curvature, CD hypotheses,
                            DIM hypotheses, Safe Object Distance for Safety functions, 
                            Safe Object Distance for Performance functions, 
                            Status of stability control system, Status of brake system, 
                            Status of warning chain systems, Driver Feedback, Driver Activity, 
                            Driver Attention, Steering Angle, Turn Indicator In Steering Direction,
                            Gas Pedal.
                            End note
                            If ((Is Extra Value available?) AND
                            (Is Extra Value function pointer valid?) AND
                            (No LocalError)) then (yes)
                                #orange: send extra Signals to MTS >
                            Endif 
                        Else
                        :Set LocalError as Null pointer Error;
                        Endif
                        :Return Local Error;
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error. 

  @param[in]            pInputData : Pointer to HEAD Input data
  @param[in]            pExtraValueList : pointer to the extra input list.
  @param[in]            fpExtraValueFct : Function pointer to a function that writes the extra input signals to the MTS.
  @param[in]            pMTSInputSignalList : Pointer to MTS Input signal List

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
eGDBError_t HEADMTSSendInputSignals(const HEADInputData_t *pInputData, const void *pExtraValueList, HEADMTSSendExtraInputSignals_ft *fpExtraValueFct, HEADMTSInputSignalList_t *pMTSInputSignalList)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData != NULL) && (pInputData->pInputValueList != NULL) && (pMTSInputSignalList != NULL))
  {
    uint8 uiNr = 0u;
    /*send input value list*/
    HEADMTSSendInputSignal(&pInputData->pInputValueList->LongVelocity, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_Velocity, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->LongAcceleration, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_Acceleration, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->YawRate, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_YawRate, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->DrivingDirection, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_DrivinDirection, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->EgoLatCurvature, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_EgoLatCurvature, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->CDHypotheses, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_CDHypotheses, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->DIMHypotheses, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_DMHypotheses, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->SafeObjDistSfty, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_SafeObjDistSfty, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->SafeObjDistPerf, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_SafeObjDistPerf, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->StabCtrlState, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_StabCtrlState, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->BrakeChainState, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_BrakeChainState, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->WarnChainState, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_WarnChainState, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->DriverFeedback, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_DriverFeedback, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->DriverActivity, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_DriverActivity, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->DriverAttention, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_DriverAttention, &retValue);
    uiNr++;
    #if HEAD_CFG_TURN_ASSIST
    HEADMTSSendInputSignal(&pInputData->pInputValueList->SteeringAngle, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_SteeringAngle, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->TurnIndicatorInSteeringDirection, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_TurnIndicatorInSteeringDirection, &retValue);
    uiNr++;
    HEADMTSSendInputSignal(&pInputData->pInputValueList->GasPedal, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_GasPedal, &retValue);
    uiNr++;
    #endif

    /*send extra values*/
    if ( (pExtraValueList != NULL) && (fpExtraValueFct != NULL) && (retValue == GDB_ERROR_NONE))
    {
      retValue = (*fpExtraValueFct)(pExtraValueList, pMTSInputSignalList, uiNr);
    }
  }
  else
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendHeaderData                                                                       */ /*!

  @brief                writes static header information to mts struct

  @description          writes static header information to mts struct
                        @startuml
                        Start
                            :Send Header information to MTS;
                            Note right: Send HEAD Auto Version Number and \nsize of HEAD MTS Output Data to MTS.
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in,out]        sMTSHeaderData : Pointer to MTS Header Data

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
eGDBError_t HEADMTSSendHeaderData(HEADMTSHeaderData_t *sMTSHeaderData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if(sMTSHeaderData != NULL)
  {
    sMTSHeaderData->uiBaseVersion = HEAD_AUTOVERSION;/*PRQA S 4464 4 #date: 2020-06-02, reviewer: Nalina M, reason: Supressing this as there is no side effect*/
    sMTSHeaderData->uiStructSize = sizeof(HEADMTSData_t);
  }
  else
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendConfigData                                                                        */ /*!

  @brief                writes Config Data to mts struct

  @description          writes Config Data to mts struct
                        @startuml
                        Start
                        If ((is config data array is not Empty) and (config length > 1Byte) ) then (yes)
                            If (config length >= Current config part Position) then (yes)
                                :Find length of Current Config Part \nand send it to MTS;
                            Else(no)
                                :Send length of Current config \nPart as zero to  MTS;
                                Note right: should never happen
                            Endif
                            :Send Config length, current Position \nand Data to MTS;
                                Note right:set new position in array for the next chunk;
                        Else(no)
                            :Reset Config Data;
                                Note right:Reset all the Data correspond to Config \nin the MTS Data structure.
                        Endif
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in,out]        pStaticData : Pointer to MTS Static Data for internal mts sending process
  @param[in,out]        pMTSConfigData : Pointer to MTS Cfg Data
  @param[in]            pCfg[] : Pointer to HEAD Config
  @param[in]            uiCfgLen : Config Length

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
eGDBError_t HEADMTSSendConfigData(HEADMTSStaticData_t *pStaticData, HEADMTSCfgData_t *pMTSConfigData, const uint8 pCfg[], uint32 uiCfgLen)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pMTSConfigData != NULL) && (pStaticData != NULL))
  {
    uint32 uiI;
    if ( (pCfg != NULL) && (uiCfgLen > 1u))
    {     
      /*send out data*/
      if ( uiCfgLen >= pStaticData->uiCfgPartPos)
      {
        pMTSConfigData->uiCfgPartLen = MIN(HEAD_CFG_PART_MAX_LENGTH, uiCfgLen - pStaticData->uiCfgPartPos);
      }
      else
      {
        pMTSConfigData->uiCfgPartLen = 0u; /*should never happen*/
      }

      pMTSConfigData->uiCfgLen = uiCfgLen;
      pMTSConfigData->uiCfgPartPos = pStaticData->uiCfgPartPos;
      
      for(uiI = 0u; uiI < pMTSConfigData->uiCfgPartLen; uiI++)
      {
        pMTSConfigData->uiCfgData[uiI] = pCfg[pMTSConfigData->uiCfgPartPos+uiI];
      }      
      /*set new pos in array for the next chunk*/
      pStaticData->uiCfgPartPos+= pMTSConfigData->uiCfgPartLen;
      pStaticData->uiCfgPartPos%= uiCfgLen;
    } 
    else
    {
      pMTSConfigData->uiCfgLen = 0u;
      pMTSConfigData->uiCfgPartLen = 0u;
      pMTSConfigData->uiCfgPartPos = 0u;
      for(uiI = 0u; uiI < HEAD_CFG_PART_MAX_LENGTH; uiI++)
      {
        pMTSConfigData->uiCfgData[uiI] = 0u;
      }      
    }
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
