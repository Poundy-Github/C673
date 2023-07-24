/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_mts.c

DESCRIPTION:               Implementation of the head MTS output

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/08/27 11:51:20CEST $

VERSION:                   $Revision: 1.51 $

LEGACY VERSION:            1.32.1.1 (HEAD 2.0)

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if (MEDIC_CFG_HEAD20)
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#include "head20/head20_int.h"
/*PRQA S 2982 EOF */ /*date: 2020-08-25, reviewer: Nalina M, reason: Suppressing because the value will be used in future*/
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

static eGDBError_t HEADMTSGetNextParam(const HEADModule_t *pCurrModule,
                                       const HEADModuleState_t *const pCurrState,
                                       const HEADStateTransition_t *const pCurrTransition,
                                       const HEADConditionGrp_t *const pCurrCondGrp,
                                       HEADMTSStaticData_t *pMTSStaticData);

static eGDBError_t HEADMTSNextCondGroup(const HEADModule_t *pCurrModule, 
                                        const HEADModuleState_t *const pCurrState,
                                        const HEADStateTransition_t *const pCurrTransition,
                                        HEADMTSStaticData_t *pMTSStaticData);

static eGDBError_t HEADMTSNextTransition(const HEADModule_t *pCurrModule, 
                                         const HEADModuleState_t *const pCurrState,
                                         HEADMTSStaticData_t *pMTSStaticData);

static eGDBError_t HEADMTSNextState(const HEADModule_t *pCurrModule, 
                                    HEADMTSStaticData_t *pMTSStaticData);

static void HEADMTSResetModuleParam(HEADMTSStaticData_t *pMTSStaticData);

#if (HEAD_CFG_PRECONDITION)
static eGDBError_t HEADMTSNextPreCondition(const HEADInputData_t *pInputData, HEADMTSPreCondParameterData_t *pMTSPreCondParamData, HEADMTSStaticData_t *pMTSStaticData);

static void HEADMTSResetPreCondParam(HEADMTSStaticData_t *pMTSStaticData);
#endif /*End PreConditon*/

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:         HEADMTSInit                                                                                 */ /*!

  @brief                initializes the MTS structure

  @description          initializes the MTS structure
                        
                        @startuml
                        Start
                            If(Null check for MTS static data )then (True)
                            : Set the null pointer error;
                            else
                            :Initialize MTS Structure;
                            Note right: Note right: Initialize all the Members of the \nMTS Static Data Structure.
                            Endif
                            : Return the updated return type;
                        Stop
                        @enduml
  
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in,out]        pMTSStaticData : Pointer to MTS Static Date for internal mts sending process

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None    
  @post                 None

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability        
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1132-0007e0f8}
  
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
    pMTSStaticData->pParLastWrittenParameter                 = NULL;
    pMTSStaticData->uiParLastWrittenModNr                    = 255u;
    pMTSStaticData->uiParLastWrittenStateNr                  = 0u;
    pMTSStaticData->uiParLastWrittenTransNr                  = 0u;
    pMTSStaticData->uiParLastWrittenCondGrpNr                = 0u;
    pMTSStaticData->uiParLastWrittenParNr                    = 0u;
    pMTSStaticData->uiParLastWrittenTabPos                   = 0u;
    pMTSStaticData->uiModNamesLastWritteModNameNr            = 0u;
    pMTSStaticData->uiSPMRulesLastWrittenRuleNr              = 0u;
    pMTSStaticData->uiCfgPartPos                             = 0u;
    pMTSStaticData->uiTransLastWrittenModNr                  = 0u;
    pMTSStaticData->uiTransLastWrittenStateNr                = 0u;
    pMTSStaticData->uiTransLastWrittenTransNr                = 0u;
    pMTSStaticData->uiModNamesLastWritteModuleStateNameIndex = 0u;
    pMTSStaticData->uiModLastWritModStateStyleName           = 0u;
    #if (HEAD_CFG_PRECONDITION)
    pMTSStaticData->pParLastWrittenPreCondParameter          = NULL;
    pMTSStaticData->uiParLastWrittenPreCondNr                = 0u;
    pMTSStaticData->uiParLastWrittenPreCondParNr             = 0u;
    pMTSStaticData->uiParLastWrittenPreCondTabPos            = 0u;
    pMTSStaticData->uiLastWrittenPreCondNameNr               = 0u; 
    #endif /*PreCondition*/
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendParameters                                                                        */ /*!

  @brief                writes one head parameter to head MTS output

  @description          writes one head parameter to head MTS output
                        
                        @startuml
                        Start
                            If(Null check for input parameter) then (true)
                            :Set the null pointer error;
                            else
                            :Find the next Parameter;
                            Note right:Find the next parameter to be written in MTS.
                            While(is the parameter valid?) is (no)
                            Floating Note left
                            If the current parameter is not valid,
                            Loop through all the parameters till we find the valid parameter.
                            End note
                            Floating Note right
                            The loop will get terminated only if the valid parameter is found
                            or if we looped through all the modules.
                            End note
                            :GO to next parameter;
                            If(check for current module is >= last written module) then (True)
                            : Increase loop counter;
                            endif
                            Endwhile
                            If (is last wirrten parameter valid?) then (yes)
                            :Send common parameter to MTS;
                            Note left
                            Make the parameter as valid in MTS data structure;
                            Write Parameter Date to MTS data structure based
                            on the Parameter Type.
                            (it can be either scalar or table parameter)
                            End note
                            If(is parameter type scalar?) then (Yes)
                            : stores the scalar value;
                            Else
                            If(is parameter type table) then (Yes)
                            :Send table parameter to MTS;
                            While(Is head MTS table rows valid?) is (Yes)
                            If(Is any more table information need to be updated?) then (Yes)
                            : Table index is updated depends on the data type;
                            Endif
                            Endwhile(No)
                            Else if(is parameter type 3d table)
                            :Send 3d table parameter to MTS;
                            While(Is size of the 3d table rows and columns valid?) is (Yes)
                            : 3D Table index is updated;
                            Endwhile(No)
                            Endif
                            Endif
                            Else(no)
                            :No Valid parameter;
                            Note right:if no valid parameter found, return invalid
                            Endif
                            Endif
                            :Return the updated error type;
                        Stop
                        @enduml
        
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error.

  @param[in]            pInputData : Pointer to HEAD input data
  @param[in,out]        pStaticData : Pointer to MTS Static Date for internal mts sending process
  @param[in,out]        pMTSParamData : pointer to MTS parameter data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1129-0007e0f8}
  
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
        /*PRQA S 0314 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
        pMTSParamData->fScalarValue_DefaultX = HEADConvf16Tof32(((const HEADParameterScalar_t *)((const void *)(pStaticData->pParLastWrittenParameter)))->f16RawValue);
      }
      else
      {
        if (pMTSParamData->sParameterHeader.ParamMainType == (HEADParamMainType_t) HEADParamMainType_Table)
        {
          uint8 uiI;
          /*PRQA S 0314 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
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
        else if (pMTSParamData->sParameterHeader.ParamMainType == (HEADParamMainType_t) HEADParamMainType_3dTable)
        {
          uint8 uiI,uiSize,iRows,iCol;
          /*PRQA S 0314 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
          const HEADParameterTable3D_t *pTable3d = ((const HEADParameterTable3D_t *)((const void *)(pStaticData->pParLastWrittenParameter)));
          pMTSParamData->fScalarValue_DefaultX1 = HEADConvf16Tof32(pTable3d->f16DefaultValX1);
          pMTSParamData->fScalarValue_DefaultX2 = HEADConvf16Tof32(pTable3d->f16DefaultValX2);
          pMTSParamData->eTableType = pTable3d->TableType1;
          pMTSParamData->eTableType2 = pTable3d->TableType2;
          pMTSParamData->uiNrOfTableRows = pTable3d->uiNrOfTableRows;
          pMTSParamData->uiNrOfTableCols = pTable3d->uiNrOfTableCols;
          pMTSParamData->X2SignalTyp =  pTable3d->X2SignalType;
          iRows = MIN(HEAD_MTS_MAX_3D_TABLE_ROWS,pTable3d->uiNrOfTableRows);
          iCol  = MIN(HEAD_MTS_MAX_TABLE_COLUMNS,pTable3d->uiNrOfTableCols);
          uiSize = ((iRows +1u) * iCol);
          for(uiI = 0u; uiI < uiSize/2u; uiI++)
          {
            const uint8 uiTblIdx = 2u*uiI;
            const uint8 uiTblLastIdx = 2u*(uiI+pStaticData->uiParLastWrittenTabPos);
            pMTSParamData->fTable3d[uiTblIdx]    = HEADConvf16Tof32(((const f16_t*)pTable3d->pTable)[uiTblLastIdx]);
            pMTSParamData->fTable3d[uiTblIdx+1u] = HEADConvf16Tof32(((const f16_t*)pTable3d->pTable)[uiTblLastIdx+1u]);
          }
        }
            else 
            {
              /*Do Nothing*/
            }
      }
    }
    else
    {
      /* no valid parameter found -> return invalid */
      pMTSParamData->bParamValid = 0u;
    }
  }

  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSNextCondGroup                                                                        */ /*! 

  @brief                go to the next condition group in the condition group list

  @description          go to the next condition group in the condition group list
  
                        @startuml
                        Start
                            :Increment the condition group;
                            If(Is last written Condition Group is greater 
                            than number of condition group?) then (Yes)
                            #orange: reset condition group number
                            <b> HEADMTSNextTransition<b> >
                            Note right 
                            Next transistion depends on the state condition or group. 
                            Each state have one or more State transition. 
                            In each state condition orgroup to be checked.
                            endnote
                            Endif
                            : Reset the parameter;
                            Note right
                            It will reset the next parameter in ORgroup;
                            endnote
                        stop
                        @enduml

  @return               eGDBError_t     : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.              
 
  @param[in]            pCurrModule     : Pointer to cuurent module
  @param[in]            pCurrState      : Pointer to cuurent state of the module
  @param[in]            pCurrTransition : Pointer to current state transition
  @param[out]           pMTSStaticData  : Pointer to MTS Static Date for internal mts sending process

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1129-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADMTSNextCondGroup(const HEADModule_t *pCurrModule,
                                        const HEADModuleState_t *const pCurrState,
                                        const HEADStateTransition_t *const pCurrTransition,
                                        HEADMTSStaticData_t *pMTSStaticData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;

  pMTSStaticData->uiParLastWrittenCondGrpNr++;

  if(pMTSStaticData->uiParLastWrittenCondGrpNr >= pCurrTransition->uiNumConditionGroups)
  {
    /* reset condition grp number */
    pMTSStaticData->uiParLastWrittenCondGrpNr = 0u;

    /* jump to the next transition*/
    retValue = HEADMTSNextTransition(pCurrModule, pCurrState, pMTSStaticData);
  }

  /* reset parameter number */
  pMTSStaticData->uiParLastWrittenParNr = 0u;

  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADMTSNextTransition                                                                       */ /*! 

  @brief                go to the next transition in the transition list

  @description          go to the next transition in the transition list
                        
                        @startuml
                        Start
                            :Increment the last written transition;
                            If(Is last written transition value  is greater  
                            than number of transition?) then (Yes)
                            #orange: Reset transition number
                            <b> HEADMTSNextState<b> >
                            Note right 
                            No further transition in current state of current module, 
                            jump to the next state of the current module
                             endnote
                            Endif
                            : Reset the last written parameter;
                            Note right
                             It will reset the next parameter in ORgroup;
                            endnote
                        stop
                        @enduml
                        
  @return               eGDBError_t     : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.    
                        
  @param[in]            pCurrModule     : Pointer to cuurent module
  @param[in]            pCurrState      : Pointer to cuurent state of the module
  @param[out]           pMTSStaticData  : Pointer to MTS Static Date for internal mts sending process

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1129-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADMTSNextTransition(const HEADModule_t *pCurrModule,
                                         const HEADModuleState_t *const pCurrState,
                                         HEADMTSStaticData_t *pMTSStaticData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;

  pMTSStaticData->uiParLastWrittenTransNr++;

  if(pMTSStaticData->uiParLastWrittenTransNr >= pCurrState->uiNumTransitions)
  {
    /* reset transition number */
    pMTSStaticData->uiParLastWrittenTransNr = 0u;

    /* no further transition in current state of current module: jump to the next state */
    retValue = HEADMTSNextState(pCurrModule, pMTSStaticData);
  }

  /* reset parameter number */
  pMTSStaticData->uiParLastWrittenParNr = 0u;

  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADMTSNextState                                                                            */ /*! 

  @brief                go to the next state in the state list

  @description          go to the next state in the state list
  
                        @startuml
                        Start
                            :Increment the last written state;
                            If(Is last written state value  is greater  
                            than number of module state?) then (Yes)
                            :Reset last written state
                            And go to next module;
                            Endif
                            : Reset the parameter value;
                            Note right
                            : Each module have different state in each state have different
                             ORgroup , once all condition  complete in ORgroup 
                             next parameter value will be reset.
                            endnote
                        stop
                        @enduml

  @return               eGDBError_t    : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.
  
  @param[in]            pCurrModule    : Pointer to cuurent module
  @param[out]           pMTSStaticData : Pointer to MTS Static Date for internal mts sending process

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1129-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADMTSNextState(const HEADModule_t *pCurrModule,
                                    HEADMTSStaticData_t *pMTSStaticData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;

  pMTSStaticData->uiParLastWrittenStateNr++;

  if(pMTSStaticData->uiParLastWrittenStateNr >= pCurrModule->uiNumModuleStates)
  {
    /* reset state number */
    pMTSStaticData->uiParLastWrittenStateNr = 0;

    /* go to next module number */
    pMTSStaticData->uiParLastWrittenModNr++;
  }

  /* reset parameter number */
  pMTSStaticData->uiParLastWrittenParNr = 0u;

  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADMTSResetModuleParam                                                                     */ /*! 

  @brief                Reset MTS module parameters

  @description          Reset MTS module parameters
  
                        @startuml
                        Start
                        Note Right: The start of the first module reset the following things.
                        : Reset state number;
                        : Reset transition number;
                        : Reset condition group number;
                        : Reset parameter number;
                        stop
                        @enduml
 
  @return               eGDBError_t     : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[out]           pMTSStaticData  : Pointer to MTS Static Date for internal mts sending process

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1129-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static void HEADMTSResetModuleParam(HEADMTSStaticData_t *pMTSStaticData)
{
  /* reset state number */
  pMTSStaticData->uiParLastWrittenStateNr   = 0;

  /* reset transition number */
  pMTSStaticData->uiParLastWrittenTransNr   = 0u;

  /* reset condition group number */
  pMTSStaticData->uiParLastWrittenCondGrpNr = 0u;

  /* reset parameter number */
  pMTSStaticData->uiParLastWrittenParNr     = 0u;

  pMTSStaticData->uiParLastWrittenTabPos    = 0u;
  pMTSStaticData->pParLastWrittenParameter  = NULL;
} 


/*************************************************************************************************************************
  Functionname:         HEADMTSGetNextParam                                                                         */ /*! 

  @brief                get the next parameter in the current condition group

  @description          get the next parameter in the current condition group
                        updates 'pParLastWrittenParameter' and jumps to next condition group
                        if no parameter available in current condition group
                 
                        @startuml
                        Start
                            If(Is last written parameter Null?) then (Yes)
                            : Get the parameter list;
                            : Reset parameter number;
                            If (check for any valid parameter in the current condition group of the transition) then (No)
                            #orange: Get the next condition group 
                            list of the current module 
                            <b> HEADMTSNextCondGroup<b> >
                            Endif
                            Else
                            If(check for current parameter is a table type) then (Yes)
                            : Get the parameter information and position of the table;
                            If(check for number of table less than the last written table position) then (Yes)
                            : Reset the parameter value and jump to next parameter;
                            If(Null check for last written parameter) then (True)
                            : Update the last written parameter;
                            Else
                            #orange: jump to next condition group because No 
                            new parameter in current condition group
                            <b> HEADMTSNextCondGroup<b> >
                            Endif
                            Endif
                            Else
                            : Reset the table position value;
                            : Get the scalar parameter from the list;
                            If(Null check for last written parameter) then (True)
                            : Update the last written parameter;
                            Else
                            #orange: jump to next condition group because No 
                            new parameter in current condition group
                            <b> HEADMTSNextCondGroup<b> >
                            Endif
                            Endif
                            Endif
                            :Return the error type;
                        stop
                        @enduml

  @return               eGDBError_t     : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.
  
  @param[in]            pCurrModule     : Pointer to cuurent module
  @param[in]            pCurrState      : Pointer to cuurent state of the module  
  @param[in]            pCurrTransition : Pointer to current state transition
  @param[in]            pCurrCondGrp    : Current condition group list for particular state 
  @param[out]           pMTSStaticData  : Pointer to MTS Static Date for internal mts sending process

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1129-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADMTSGetNextParam(const HEADModule_t *pCurrModule,
                                       const HEADModuleState_t *const pCurrState,
                                       const HEADStateTransition_t *const pCurrTransition,
                                       const HEADConditionGrp_t *const pCurrCondGrp,
                                       HEADMTSStaticData_t *pMTSStaticData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;

  if(pMTSStaticData->pParLastWrittenParameter == NULL)  /* first parameter of the condition group */
  {
    /* This list is the sorted list according to the operator and outType */
    const HEADParameterEmpty_t *const pParamList = pCurrCondGrp->pParameterList;

    /* reset parameter number */
    pMTSStaticData->uiParLastWrittenParNr = 0u;
    pMTSStaticData->uiParLastWrittenTabPos = 0u;

    /* Get the parameter from parameter list */
    pMTSStaticData->pParLastWrittenParameter = pParamList;

    /*no more valid parameter in the current condition group of the transition: pParLastWrittenParameter == NULL*/
    if(pMTSStaticData->pParLastWrittenParameter == NULL)
    {
      /* jump to the next condition group*/
      retValue = HEADMTSNextCondGroup(pCurrModule, pCurrState, pCurrTransition, pMTSStaticData);
    }
  }
  else /* Iterate through current condition group */
  {
    /*parameter is already defined*/        
    /*case 3 - check if current parameter is in a table*/
    if ((HEADParamMainType_t)(pMTSStaticData->pParLastWrittenParameter->ParameterType.sParameterType.ParamMainType) == (HEADParamMainType_t) HEADParamMainType_Table)
    {
      /*case 4 - check if table is already finished*/
      /*PRQA S 0314 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
      const HEADParameterTable_t *pTable = (const HEADParameterTable_t*)((const void *)(pMTSStaticData->pParLastWrittenParameter));
      /*increase position in table*/
      pMTSStaticData->uiParLastWrittenTabPos += HEAD_MTS_MAX_TABLE_ROWS;
      if(pTable->uiNrOfTableRows <= pMTSStaticData->uiParLastWrittenTabPos)
      {
        pMTSStaticData->uiParLastWrittenTabPos = 0u;

        /*table already transfered - jump to next parameter*/
        pMTSStaticData->pParLastWrittenParameter = (const HEADParameterEmpty_t *)(pMTSStaticData->pParLastWrittenParameter->ParameterType.pNextRelevantParam);
                  
        if(pMTSStaticData->pParLastWrittenParameter != NULL)
        {
          pMTSStaticData->uiParLastWrittenParNr++;
        }
        else /* no new parameter in current condition group- jump to next condition group */
        {
          retValue = HEADMTSNextCondGroup(pCurrModule, pCurrState, pCurrTransition, pMTSStaticData);
        }
      }
      else
      {
        /*nothing to do - next table rows already selected*/
      }
    }
    else
    {
      pMTSStaticData->uiParLastWrittenTabPos = 0u;

      /*scalar - directly jump to the next parameter*/
      pMTSStaticData->pParLastWrittenParameter = (const HEADParameterEmpty_t *)(pMTSStaticData->pParLastWrittenParameter->ParameterType.pNextRelevantParam);
      if(pMTSStaticData->pParLastWrittenParameter != NULL)
      {
        pMTSStaticData->uiParLastWrittenParNr++;
      }
      else /* no new parameter in current condition group- jump to next condition group */
      {
        retValue = HEADMTSNextCondGroup(pCurrModule, pCurrState, pCurrTransition, pMTSStaticData);
      }
    }
  }

  return retValue;
}


/*************************************************************************************************************************
  Functionname:         HEADMTSNextParameter                                                                        */ /*! 

  @brief                go to the next parameter in the parameter list

  @description          go to the next parameter in the parameter list. Parameters are already sorted in accordance to the 
                        the operator and outType in a condition group list of a particular transition of a state of a module. 
                        The parameter is selected from the current state of the module
                 
                        @startuml
                        Start
                            If(Null check for all input parameter) then (True)
                            :Set null pointer error;
                            Else
                            If(check for last written parameter >= the number of modules) then 
                            #orange: Reset transition number and all 
                            module parameter,transition and condition group
                            <b> HEADMTSResetModuleParam<b> >
                            : Get the current module information;
                            If(Null check for current module) the (True)
                            : Get the next state data of the current module
                            If(Null check for current module state) the (True)
                            : Get the current transition data of the current state;
                            If(Null check for current module state transition) the (True)
                            : Get the current condition group data of the current transition;
                            If(Null check for current module current condition group) the (True)
                            :get the next parameter in the condition group
                            <b> HEADMTSGetNextParam <b> >
                            Else 
                            #orange: Get the next condition group list
                            <b> HEADMTSNextCondGroup <b> >
                            Endif
                            Else
                            #orange: Reset condition group number and get the next transition of the state 
                            <b> HEADMTSNextTransition <b> >
                            Endif
                            Else
                            #orange: Get the next state of the current module
                            <b> HEADMTSNextState <b> >
                            Endif
                            Else 
                            #orange:  Get the next module number and module
                            <b> HEADMTSNextState <b> >
                            Endif
                            : Head MTS parameter data is updated;
                            Endif
                            :Return the error type;
                        stop
                        @enduml

  @return               eGDBError_t     :  GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.
  
  @param[in]            pInputData      : Pointer to HEAD input data
  @param[in]            pMTSParamData   : Pointer to head MTS parameter data
  @param[in]            pMTSStaticData  : Pointer to head MTS static data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1129-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com      
*************************************************************************************************************************/
static eGDBError_t HEADMTSNextParameter(const HEADInputData_t *pInputData, HEADMTSParameterData_t *pMTSParamData, HEADMTSStaticData_t *pMTSStaticData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData == NULL) || (pMTSParamData == NULL) || (pMTSStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    const HEADModule_t * pCurrModule; 

    if (pMTSStaticData->uiParLastWrittenModNr >= pInputData->pModuleList->uiNrOfModules)
    {
      /*set back to first parameter*/
      pMTSStaticData->uiParLastWrittenModNr     = 0u;
      HEADMTSResetModuleParam(pMTSStaticData);
    }
    
    pCurrModule = HEADGetModule(pInputData->pModuleList, pMTSStaticData->uiParLastWrittenModNr);

    /* now the moduleNr should be in range*/
    /*case 1 - module is a GSM module - others do not use the parameter cue...*/
    if (   (pCurrModule != NULL) 
        && (pCurrModule->pInternal != NULL) 
        && (pCurrModule->pInternal->InternalHeader.eModuleInternalType == HEADModuleInternalType_GSM))
    {

      /* Get the next state data of the current module */
      const HEADModuleState_t *const pCurrState = HEADGetModuleState(pCurrModule,pMTSStaticData->uiParLastWrittenStateNr);
     
      if(pCurrState != NULL)
      {
        /* Get the current transition data of the current state */
        const HEADStateTransition_t *const pCurrTransition = HEADGetStateTransition(pCurrState, pMTSStaticData->uiParLastWrittenTransNr);

        if(pCurrTransition != NULL)
        {           
          /* Get the current condition group data of the current transition */
          const HEADConditionGrp_t *const pCurrCondGrp = HEADGetConditionGrp(pCurrTransition, pMTSStaticData->uiParLastWrittenCondGrpNr);

          if(pCurrCondGrp != NULL)
          {
            /* find the next parameter in the condition group */
            retValue = HEADMTSGetNextParam(pCurrModule, pCurrState, pCurrTransition, pCurrCondGrp, pMTSStaticData);
          }
          else/* pCurrCondGrp != NULL */
          {
            /* jump to the next condition group*/
            retValue = HEADMTSNextCondGroup(pCurrModule, pCurrState, pCurrTransition, pMTSStaticData);

            pMTSStaticData->uiParLastWrittenTabPos = 0u;
            pMTSStaticData->pParLastWrittenParameter = NULL;
          }
        }
        else/* pCurrTransition != NULL */
        {
          /* reset condition grp number */
          pMTSStaticData->uiParLastWrittenCondGrpNr = 0u;

          /* jump to the next transition */
          retValue = HEADMTSNextTransition(pCurrModule, pCurrState, pMTSStaticData);

          pMTSStaticData->uiParLastWrittenTabPos = 0u;
          pMTSStaticData->pParLastWrittenParameter = NULL;
        }
      }
      else /* pCurrState != NULL */
      {
        /*not valid state of the current module: jump to the next state*/
        retValue = HEADMTSNextState(pCurrModule, pMTSStaticData);

        pMTSStaticData->uiParLastWrittenTransNr   = 0u;
        pMTSStaticData->uiParLastWrittenCondGrpNr = 0u;

        pMTSStaticData->uiParLastWrittenTabPos = 0u;
        pMTSStaticData->pParLastWrittenParameter = NULL;
      }
    }
    else
    {
      /*no GSM module: jump to the next module*/
      pMTSStaticData->uiParLastWrittenModNr++;
      HEADMTSResetModuleParam(pMTSStaticData);
    }

    pMTSParamData->uiParNr     = pMTSStaticData->uiParLastWrittenParNr;
    pMTSParamData->uiTablePos  = pMTSStaticData->uiParLastWrittenTabPos;
    pMTSParamData->uiCondGrpNr = pMTSStaticData->uiParLastWrittenCondGrpNr; 
    pMTSParamData->uiTransNr   = pMTSStaticData->uiParLastWrittenTransNr;
    pMTSParamData->uiStateNr   = pMTSStaticData->uiParLastWrittenStateNr;
    pMTSParamData->uiModuleNr  = pMTSStaticData->uiParLastWrittenModNr;
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
  @param[in,out]        pMTSStaticData : Pointer to MTS Static Date for internal mts sending process
  @param[in,out]        pMTSModuleData : Pointer to MTS Module Data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}
  
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
      /*PRQA S 2991,2995 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
      if(pModule->strModuleName != NULL)
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
        /*PRQA S 2880 2*/ /* date: 2019-05-23, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
        MEDIC_ASSERT(FALSE);/*PRQA S 3119 */ /* date: 2019-09-19, reviewer: Srinivasa, Sadhanashree, Reason: This code is placed for assertive failure and hence cannot be removed */
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
  Functionname:         HEADMTSSendStateName                                                                        */ /*!

  @brief                writes State Name to MTS(one state per cycle)

  @description          writes State Name to MTS(one state per cycle)
                        @startuml
                        Start
                            If (is the State Number valid?) then (no)
                            :Reset State Name Count;
                                Note right: Reset the State Name count.
                            Else(yes)
                            Endif
                            :Increment State Name Count;
                                Note left: Increment the State Name count \nfor MTS send process.
                            :Fetch the State Name;
                                Note left:Fetch the State Name corresponding to \nState name count.
                            :Send State Name to MTS;
                             Note right
                                Writes State Name to MTS
                                ->State name is a string with Zero termination.
                            End note
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in,out]        pMTSStaticData : Pointer to MTS Static Data for internal mts sending process
  @param[in,out]        pMTSStateData  : Pointer to MTS State Data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}
  
  @author               Minuthi H U | minuthi.hu@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendStateName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSStateName_t *pMTSStateData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pMTSStateData == NULL) || (pMTSStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {   
    /*just in case it's out of bounds*/
    if(pMTSStaticData->uiModNamesLastWritteStateNameNr >= HEAD_AUTO_CFG_MAX_STATES_NAMES)
    {
      pMTSStaticData->uiModNamesLastWritteStateNameNr = 0u;
    }
    pMTSStateData->uiStateNr = pMTSStaticData->uiModNamesLastWritteStateNameNr;
    pMTSStaticData->uiModNamesLastWritteStateNameNr++;
    
    if(strModuleStateName[pMTSStateData->uiStateNr] != NULL)
    {
      uint8 uiFirst, uiLast = 0;
      
      for(uiFirst = 0u ; (uiFirst< (HEAD_STATENAME_LENGTH-1u)) && (uiLast == uiFirst); uiFirst++)
      {
        if(strModuleStateName[pMTSStateData->uiStateNr][uiFirst] != '\0')
        {
          pMTSStateData->strStateName[uiFirst] = (uint8)strModuleStateName[pMTSStateData->uiStateNr][uiFirst];
          uiLast = uiFirst+1u;
        }
      }
             
      pMTSStateData->strStateName[uiLast] = 0u;
    }
    else
    {
      pMTSStateData->strStateName[0] = 0u;
    }
  }
  return retValue;
} 


/*************************************************************************************************************************
Functionname:         HEADMTSSendModuleStateNameIndex                                                                        */ /*!

@brief                writes ModuleStateName Index to MTS(All StateName index of one module per cycle)

@description          writes ModuleStateName Index to MTS(All StateName index of one module per cycle)
                      @startuml
                      Start
                          If (is the ModuleStateName Index valid?) then (no)
                          :Reset ModuleStateName Index Count;
                          Note right: Reset the ModuleStateName Index count.
                          Else(yes)
                          Endif
                          :Fetch the ModuleStateName Index;
                          Note left:Fetch the ModuleStateName Index corresponding to \nModule count.
                          :Send ModuleStateName Index to MTS;
                          Note right
                          Writes ModuleStateName Index to MTS
                          ->ModuleStateName Index is a uint8 value .
                          End note
                          :Increment ModuleStateName Index Count;
                          Note left: Increment the ModuleStateName Index count \nfor MTS send process.
                      Stop
                      @enduml

@return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

@param[in,out]        pMTSStaticData : Pointer to MTS Static Data for internal mts sending process
@param[in,out]        pMTSModuleStateIndexData  : Pointer to MTS ModuleStateIndex Data

@glob_in              None
@glob_out             None

@c_switch_part        None
@c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

@pre                  None
@post                 None

@InOutCorrelation     See description

@testmethod           Test of output data (dynamic module test)

@traceability.........
                      @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}

@author               Minuthi H U | minuthi.hu@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendModuleStateNameIndex(HEADMTSStaticData_t *pMTSStaticData, HEADMTSModuleStateNameIndex_t *pMTSModuleStateIndexData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pMTSModuleStateIndexData == NULL) || (pMTSStaticData == NULL))
  {
      retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    uint8 uiFirst;
    uint8 uicurrModule = 0u;
    /*just in case it's out of bounds*/
    if (pMTSStaticData->uiModNamesLastWritteModuleStateNameIndex >= HEAD_AUTO_CFG_NO_MODULES)
    {
      pMTSStaticData->uiModNamesLastWritteModuleStateNameIndex = 0u;
    }
    uicurrModule = pMTSStaticData->uiModNamesLastWritteModuleStateNameIndex;
    pMTSModuleStateIndexData->uiModuleNr = uicurrModule;
    
    for (uiFirst = 0u; uiFirst < HEAD_AUTO_CFG_MAX_STATES; uiFirst++)
    {
      pMTSModuleStateIndexData->ModuleStateNameIndex[uiFirst] = ui_strModuleStateName[uicurrModule][uiFirst];
    }
    pMTSStaticData->uiModNamesLastWritteModuleStateNameIndex++;
  }
  return retValue;
}


/*************************************************************************************************************************
Functionname:         HEADMTSSendStateStyleName                                                                        */ /*!

@brief                writes StateStyle to MTS(StateStyle of one module per cycle)

@description          writes StateStyle to MTS(StateStyle of one module per cycle)

                      @startuml
                      Start
                          If (is the ModuleStateStyleName valid?) then (no)
                          :Reset ModuleStateStyleName Count;
                          Note right: Reset the ModuleStateStyleName count.
                          Else(yes)
                          Endif
                          :Fetch the ModuleStateStyleName;
                          Note left:Fetch the ModuleStateStyleName corresponding to \nModule count.
                          :Send ModuleStateStyleName to MTS;
                          Note right
                          Writes ModuleStateStyleName to MTS
                          ->ModuleStateStyleName is a uint8 value .
                          End note
                          :Increment ModuleStateStyleName Count;
                          Note left: Increment the ModuleStateStyleName count \nfor MTS send process.
                      Stop
                      @enduml


@return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

@param[in,out]        pMTSStaticData : Pointer to MTS Static Data for internal mts sending process
@param[in,out]        pMTSModuleStateStyleName  : Pointer to MTS ModuleStateStyleName Data

@glob_in              None
@glob_out             None

@c_switch_part        None
@c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

@pre                  None
@post                 None

@InOutCorrelation     See description

@testmethod           Test of output data (dynamic module test)

@traceability.........
                      @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}

@author               Minuthi H U | minuthi.hu@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendStateStyleName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSModuleStateStyleName_t *pMTSModuleStateStyleName)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pMTSModuleStateStyleName == NULL) || (pMTSStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    uint8 uiFirst;
    uint8 uicurrModule = 0u;
    /*just in case it's out of bounds*/
    if (pMTSStaticData->uiModLastWritModStateStyleName >= HEAD_AUTO_CFG_NO_MODULES)
    {
      pMTSStaticData->uiModLastWritModStateStyleName = 0u;
    }
    uicurrModule = pMTSStaticData->uiModLastWritModStateStyleName;
    pMTSModuleStateStyleName->uiModuleNr = uicurrModule;
    for (uiFirst = 0u; uiFirst < HEAD_AUTO_CFG_MAX_STATES; uiFirst++)
    {
      pMTSModuleStateStyleName->ModuleStateStyleName[uiFirst] = strStateStyleName[uicurrModule][uiFirst];
    }
    pMTSStaticData->uiModLastWritModStateStyleName++;
  }
  return retValue;
}



/*************************************************************************************************************************
  Functionname:         HEADMTSSendDGSMStateName                                                                        */ /*!

  @brief                writes State Name to MTS(one state per cycle)

  @description          writes State Name to MTS(one state per cycle)
                        @startuml
                        Start
                            If (is the State Number valid?) then (no)
                            :Reset State Name Count;
                                Note right: Reset the State Name count.
                            Else(yes)
                            Endif
                            :Increment State Name Count;
                                Note left: Increment the State Name count \nfor MTS send process.
                            :Fetch the State Name;
                                Note left:Fetch the State Name corresponding to \nState name count.
                            :Send State Name to MTS;
                             Note right
                                Writes State Name to MTS
                                ->State name is a string with Zero termination.
                            End note
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in,out]        pMTSStaticData : Pointer to MTS Static Data for internal mts sending process
  @param[in,out]        pMTSStateData  : Pointer to MTS State Data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}
  
  @author               Minuthi H U | minuthi.hu@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendDGSMStateName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSDGSMStateName_t *pMTSStateData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pMTSStateData == NULL) || (pMTSStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {  
    uint8 iNameIndex;

    /*just in case it's out of bounds*/
    if(pMTSStaticData->uiModNamesLastWritteDGSMStateNameNr >= (uint8)HEAD_STATES_MAX)
    {
      pMTSStaticData->uiModNamesLastWritteDGSMStateNameNr = 0u;
    }
    pMTSStateData->uiStateNr = pMTSStaticData->uiModNamesLastWritteDGSMStateNameNr;
    pMTSStaticData->uiModNamesLastWritteDGSMStateNameNr++;
    
    iNameIndex = ui_strModuleStateIndex[pMTSStateData->uiStateNr];

    if(strModuleStateName[iNameIndex] != NULL)
    {
      uint8 uiFirst, uiLast = 0;
      
      for(uiFirst = 0u ; (uiFirst< (HEAD_DGSMSTATENAME_LENGTH-1u)) && (uiLast == uiFirst); uiFirst++)
      {
        if(strModuleStateName[iNameIndex][uiFirst] != '\0')
        {
          pMTSStateData->strDGSMStateName[uiFirst] = (uint8)strModuleStateName[iNameIndex][uiFirst];
          uiLast = uiFirst+1u;
        }
      }
             
      pMTSStateData->strDGSMStateName[uiLast] = 0u;
    }
    else
    {
      pMTSStateData->strDGSMStateName[0] = 0u;
    }
  }
  return retValue;
} 

/*************************************************************************************************************************
  Functionname:         HEADMTSSendQosName                                                                        */ /*!

  @brief                writes Qos Name to MTS(one Qos per cycle)

  @description          writes Qos Name to MTS(one Qos per cycle)
                        @startuml
                        Start
                            If (is the Qos Number valid?) then (no)
                            :Reset Qos Name Count;
                                Note right: Reset the Qos Name count.
                            Else(yes)
                            Endif
                            :Increment Qos Name Count;
                                Note left: Increment the Qos Name count \nfor MTS send process.
                            :Fetch the Qos Name;
                                Note left:Fetch the Qos Name corresponding to \nQos name count.
                            :Send Qos Name to MTS;
                             Note right
                                Writes Qos Name to MTS
                                ->Qos name is a string with Zero termination.
                            End note
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in,out]        pMTSStaticData : Pointer to MTS Static Data for internal mts sending process
  @param[in,out]        pMTSQosData : Pointer to MTS Qos Data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}
  
  @author               Minuthi H U | minuthi.hu@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendQosName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSQosName_t *pMTSQosData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pMTSQosData == NULL) || (pMTSStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    
    /*just in case it's out of bounds*/
    if(pMTSStaticData->uiModNamesLastWritteQosNameNr >= (uint8)HEADModuleQoS_Max)
    {
      pMTSStaticData->uiModNamesLastWritteQosNameNr = 0u;
    }
    pMTSQosData->uiQosNr = pMTSStaticData->uiModNamesLastWritteQosNameNr;
    pMTSStaticData->uiModNamesLastWritteQosNameNr++;
      
    if(strQoSName[pMTSQosData->uiQosNr] != NULL)
    {
      uint8 uiFirst, uiLast = 0;
      for(uiFirst = 0u ; (uiFirst< (HEAD_QOSNAME_LENGTH-1u)) && (uiLast == uiFirst); uiFirst++)
      {
        if(strQoSName[pMTSQosData->uiQosNr][uiFirst] != '\0')
        {
          pMTSQosData->strQosName[uiFirst] = (uint8)strQoSName[pMTSQosData->uiQosNr] [uiFirst];
          uiLast = uiFirst+1u;
        }
      }
      pMTSQosData->strQosName[uiLast] = 0u;
    }
    else
    {
        pMTSQosData->strQosName[0] = 0u;
    }
  }
  return retValue;
} 

/*************************************************************************************************************************
  Functionname:         HEADMTSSendSpmName                                                                        */ /*!
  @brief                writes Spm Name to MTS(one Spm per cycle)

  @description          writes Spm Name to MTS(one Spm per cycle)
                        @startuml
                        Start
                            If (is the Spm Number valid?) then (no)
                            :Reset Spm Name Count;
                                Note right: Reset the Spm Name count.
                            Else(yes)
                            Endif
                            :Increment Spm Name Count;
                                Note left: Increment the Spm Name count \nfor MTS send process.
                            :Fetch the Spm Name;
                                Note left:Fetch the Spm Name corresponding to \nSpm name count.
                            :Send Spm Name to MTS;
                             Note right
                                Writes Spm Name to MTS
                                ->Spm name is a string with Zero termination.
                            End note
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in,out]        pMTSStaticData : Pointer to MTS Static Data for internal mts sending process
  @param[in,out]        pMTSSpmData : Pointer to MTS Spm Data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}

  @author               Minuthi H U | minuthi.hu@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendSpmName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSSpmName_t *pMTSSpmData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pMTSSpmData == NULL) || (pMTSStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    /*just in case it's out of bounds*/
    if(pMTSStaticData->uiModNamesLastWritteSpmNameNr >= HEAD_AUTO_MAX_SPMS)
    {
      pMTSStaticData->uiModNamesLastWritteSpmNameNr = 0u;
    }
    pMTSSpmData->uiSpmNr = pMTSStaticData->uiModNamesLastWritteSpmNameNr;
    pMTSStaticData->uiModNamesLastWritteSpmNameNr++;
      
    if(strSPMNames[pMTSSpmData->uiSpmNr] != NULL)
    {
      uint8 uiFirst, uiLast = 0;
      for(uiFirst = 0u ; (uiFirst< (HEAD_SPMNAME_LENGTH-1u)) && (uiLast == uiFirst); uiFirst++)
      {
        if(strSPMNames[pMTSSpmData->uiSpmNr][uiFirst] != '\0')
        {
          pMTSSpmData->strSpmName[uiFirst] = (uint8)strSPMNames[pMTSSpmData->uiSpmNr] [uiFirst];
          uiLast = uiFirst+1u;
        }
      }
      pMTSSpmData->strSpmName[uiLast] = 0u;
    }
    else
    {
        pMTSSpmData->strSpmName[0] = 0u;
    }
  }
  return retValue;
} 

/*************************************************************************************************************************
  Functionname:         HEADMTSSendErrorName                                                                        */ /*!

  @brief                writes Error Name to MTS(one state per cycle)

  @description          writes Error Name to MTS(one module per cycle)
                        @startuml
                        Start
                            If (is the Error Number valid?) then (no)
                            :Reset Error Count;
                                Note right: Reset the Error Name count.
                            Else(yes)
                            Endif
                            :Increment Error Name Count;
                                Note left: Increment the Error Name count \nfor MTS send process.
                            :Fetch the Error Name;
                                Note left:Fetch the Error Name correspond to \nError name count.
                            :Send Error Name to MTS;
                             Note right
                                Writes Error Name to MTS
                                ->Error name is a string with Zero termination.
                            End note
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in,out]        pMTSStaticData : Pointer to MTS Static Data for internal mts sending process
  @param[in,out]        pMTSErrorData  : Pointer to MTS Error Data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}
  
  @author               Minuthi H U | minuthi.hu@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendErrorName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSErrorName_t *pMTSErrorData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pMTSErrorData == NULL) || (pMTSStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
        
    /*just in case it's out of bounds*/
    if(pMTSStaticData->uiModNamesLastWritteErrorNameNr >= (uint8)HEADModuleRepError_Max)
    {
      pMTSStaticData->uiModNamesLastWritteErrorNameNr = 0u;
    }
    pMTSErrorData->uiErrorNr = pMTSStaticData->uiModNamesLastWritteErrorNameNr;
    pMTSStaticData->uiModNamesLastWritteErrorNameNr++;
    
    if(strRepErrorName[pMTSErrorData->uiErrorNr] != NULL)
    {
      uint8 uiFirst, uiLast = 0;
      for(uiFirst = 0u ; (uiFirst< (HEAD_REPERRNAME_LENGTH-1u)) && (uiLast == uiFirst); uiFirst++)
      {
        if(strRepErrorName[pMTSErrorData->uiErrorNr][uiFirst] != '\0')
        {
          pMTSErrorData->strErrorName[uiFirst] = (uint8)strRepErrorName[pMTSErrorData->uiErrorNr][uiFirst];
          uiLast = uiFirst+1u;
        }
      }
      pMTSErrorData->strErrorName[uiLast] = 0u;
    }
    else
    {
        pMTSErrorData->strErrorName[0] = 0u;
    }
  }
 
  return retValue;
} 

#if (HEAD_CFG_PRECONDITION)
/*************************************************************************************************************************
  Functionname:         HEADMTSSendPreConditionName                                                                  */ /*!

  @brief                writes Precondition Name to MTS(one name per cycle)

  @description          writes Precondition Name to MTS(one name per cycle)
                        @startuml
                        Start
                            If (is the Precondition Number valid?) then (no)
                            :Reset Precondition Count;
                                Note right: Reset the Precondition Name count.
                            Else(yes)
                            Endif
                            :Increment Precondition Name Count;
                                Note left: Increment the Precondition Name count \nfor MTS send process.
                            :Fetch the Error Name;
                                Note left:Fetch the Precondition Name correspond to \nPrecondition name count.
                            :Send Precondition Name to MTS;
                             Note right
                                Writes Precondition Name to MTS
                                ->Precondition name is a string with Zero termination.
                            End note
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in,out]        pMTSStaticData      : Pointer to MTS Static Data for internal mts sending process
  @param[in,out]        pMTSPreConditionName: Pointer to MTS Precondition Name Data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1134-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendPreConditionName(HEADMTSStaticData_t *pMTSStaticData, HEADMTSPreCondName_t *pMTSPreConditionName)
{
  eGDBError_t    retValue = GDB_ERROR_NONE;
  HEADPreCond_t *pPrecond;

  if ((pMTSPreConditionName == NULL) || (pMTSStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    /*just in case it's out of bounds*/
    if(pMTSStaticData->uiLastWrittenPreCondNameNr >= (uint8)HEAD_AUTO_CFG_NO_PRECONDS)
    {
      pMTSStaticData->uiLastWrittenPreCondNameNr = 0u;
    }
    pMTSPreConditionName->uiPreCondNr = pMTSStaticData->uiLastWrittenPreCondNameNr;
    pMTSStaticData->uiLastWrittenPreCondNameNr++;

    pPrecond = &MEDIC_p_ModHEADInputData()->pPreCondList->rgPreCondList[pMTSPreConditionName->uiPreCondNr];

    if(pPrecond != NULL)
    {
      uint8 uiFirst, uiLast = 0u;
      for(uiFirst = 0u; (uiFirst < (HEAD_PRECONDNAME_LENGTH - 1u)) && (uiLast == uiFirst); uiFirst++)
      { 
        if (pPrecond->strPreCondName[uiFirst] != 0u)
        {
          pMTSPreConditionName->strPreCondName[uiFirst] = pPrecond->strPreCondName[uiFirst];
          uiLast = uiFirst + 1u;
        }
        pMTSPreConditionName->strPreCondName[uiLast] = 0u;
      }
    }
    else
    {
      pMTSPreConditionName->strPreCondName[0u] = 0u;
    }
  }
 
  return retValue;
} 

/*************************************************************************************************************************
  Functionname:         HEADMTSSendPreConditionData                                                                 */ /*!
  @brief                writes PreCondition Data to MTS(All precondition per cycle)
  @description          writes PreCondition to MTS(All precondition per cycle)
                        @startuml
                        Start
                            if(Null check for input parameter of the function) then (True)
                            : Set the null pointer error;
                            else
                            :Fetch total Number of PreConditions;
                            Note right:Fetch the total Number of PreConditions from \nPreCondition List.
                            while (is the PreCondition Number Valid?) is (yes)
                            if(check for less than the maximum number of precondition) then (Yes)
                            :Fetch the precondition;
                            Note left:Fetch the precondition correspond to \nPreCondition Number.
                            if(Is PreCondiiton is null?) then (No)
                            : Update the PreCondition information to MTS Precondition data;
                            Note right
                            PreCondition information are PreCondition status and Hypothesis used
                            endnote
                            else
                            : Update the null pointer error;
                            endif
                            else
                            : Update the array overflow error;
                            Endif
                            Endwhile(No)
                            endif
                            : Return the updated error type;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise an error code is returned.

  @param[in]            pInputData : Pointer to HEAD input data
  @param[in,out]        pMTSPreConditionData  : Pointer to MTS PreCondition Data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref HEAD_CFG_PRECONDITION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1134-0007e0f8}

  @author               Minuthi H U | minuthi.hu@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendPreConditionData(const HEADInputData_t *pInputData, HEADMTSPreConditionData *pMTSPreConditionData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  HEADPreCond_t *pPrecond;
  uint8 uiPreCond;
  if ((pMTSPreConditionData == NULL) || (pInputData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    for (uiPreCond = 0u; uiPreCond < pInputData->pPreCondList->uiNrOfPreConds; uiPreCond++)
    {
      if (uiPreCond < HEAD_AUTO_CFG_NO_PRECONDS)
      {
        pPrecond = HEADGetPreCondition(pInputData->pPreCondList, uiPreCond);
        if (pPrecond != NULL)
        {
          pMTSPreConditionData->HEADMTSPreCond[uiPreCond].PreCondStatus    = pPrecond->PreCondStatus;
          pMTSPreConditionData->HEADMTSPreCond[uiPreCond].uiHypInCondGroup = pPrecond->uiHypInCondGroup;
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
Functionname:         HEADMTSSendPreCondParam                                                                        */ /*!

@brief                writes one head precondition parameter to head MTS output

@description          writes one head precondition parameter to head MTS output

                      @startuml
                      Start
                          If(Null check for input parameter) then (true)
                          :Set the null pointer error;
                          else
                          :Find the next precondition Parameter;
                          Note right:Find the next precondition parameter to be written in MTS.
                          While(is the precondition parameter valid?) is (no)
                          Note left
                          If the current precondition parameter is not valid,
                          Loop through all the precondition parameters till we find the valid parameter.
                          End note
                          Note right
                          The loop will get terminated only if the valid parameter is found
                          or if we looped through all the preconditions.
                          End note
                          :Go to next precondition parameter;
                          If(check for current precondition is >= last written precondition) then (True)
                          : Increase loop counter;
                          endif
                          Endwhile
                          If (is last wirrten parameter valid?) then (yes)
                          :Send common parameter to MTS;
                          Note left
                          Make the parameter as valid in MTS data structure;
                          Write Parameter Date to MTS data structure based
                          on the Parameter Type.
                          (it can be either scalar or table parameter)
                          End note
                          If(is parameter type scalar?) then (Yes)
                          : stores the scalar value;
                          Else
                          If(is parameter type table) then (Yes)
                          :Send table parameter to MTS;
                          While(Is head MTS table rows valid?) is (Yes)
                          If(Is any more table information need to be updated?) then (Yes)
                          : Table index is updated depends on the data type;
                          Endif
                          Endwhile(No)
                          Else if(is parameter type 3d table)
                          :Send 3d table parameter to MTS;
                          While(Is size of the 3d table rows and columns valid?) is (Yes)
                          : 3D Table index is updated;
                          Endwhile(No)
                          Endif
                          Endif
                          Else(no)
                          :No Valid parameter;
                          Note right:if no valid parameter found, return invalid
                          Endif
                          Endif
                          :Return the updated error type;
                      Stop
                      @enduml

@return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error.

@param[in]            pInputData : Pointer to HEAD input data
@param[in,out]        pStaticData : Pointer to MTS Static Date for internal mts sending process
@param[in,out]        pMTSPreCondParamData : pointer to MTS precondition parameter data

@glob_in              None
@glob_out             None

@c_switch_part        None
@c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION,HEAD_CFG_PRECONDITION

@pre                  None
@post                 None

@InOutCorrelation     See description

@testmethod           Test of output data (dynamic module test)

@traceability.........
                      @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1134-0007e0f8}

@author               Minuthi H U | minuthi.h.u@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendPreCondParam(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pStaticData, HEADMTSPreCondParameterData_t *pMTSPreCondParamData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData == NULL) || (pStaticData == NULL) || (pMTSPreCondParamData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }

  else
  {
    uint8  uiCurrentPreCond;
    uint8  uiLoopCounter = 0u;
    /*find next parameter in the list*/
    retValue = HEADMTSNextPreCondition(pInputData, pMTSPreCondParamData, pStaticData);
    uiCurrentPreCond = pStaticData->uiParLastWrittenPreCondNr;

    /*while (current parameter not valid) go to the next*/
    while ((pStaticData->pParLastWrittenPreCondParameter == NULL) && (uiLoopCounter < 2u))
    {
      retValue = HEADMTSNextPreCondition(pInputData, pMTSPreCondParamData, pStaticData);
      if (uiCurrentPreCond >= pStaticData->uiParLastWrittenPreCondNr)
      {
        /*if current modulenr >= modulenr at the start -> increase one loop*/
        uiLoopCounter++;
      }
    }

    if (pStaticData->pParLastWrittenPreCondParameter != NULL)
    {
      pMTSPreCondParamData->bParamValid = 1u;
      pMTSPreCondParamData->sParameterHeader = pStaticData->pParLastWrittenPreCondParameter->ParameterType.sParameterType;
      pMTSPreCondParamData->uiSpecialParInfo = pStaticData->pParLastWrittenPreCondParameter->uiSpecialParInfo;
      pMTSPreCondParamData->uiPreCondNr = pStaticData->uiParLastWrittenPreCondNr;
      pMTSPreCondParamData->uiParNr = pStaticData->uiParLastWrittenPreCondParNr;
      if (pMTSPreCondParamData->sParameterHeader.ParamMainType == (HEADParamMainType_t)HEADParamMainType_Scalar)
      {
        /*PRQA S 0314 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
        pMTSPreCondParamData->fScalarValue_DefaultX = HEADConvf16Tof32(((const HEADParameterScalar_t *)((const void *)(pStaticData->pParLastWrittenPreCondParameter)))->f16RawValue);
      }
      else
      {
        if (pMTSPreCondParamData->sParameterHeader.ParamMainType == (HEADParamMainType_t)HEADParamMainType_Table)
        {
          uint8 uiI;
          /*PRQA S 0314 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
          const HEADParameterTable_t *pTable = ((const HEADParameterTable_t *)((const void *)(pStaticData->pParLastWrittenPreCondParameter)));
          pMTSPreCondParamData->fScalarValue_DefaultX = HEADConvf16Tof32(pTable->f16DefaultValue);
          pMTSPreCondParamData->eTableType = pTable->TableType;
          pMTSPreCondParamData->uiNrOfTableRows = pTable->uiNrOfTableRows;
          for (uiI = 0u; uiI < HEAD_MTS_MAX_TABLE_ROWS; uiI++)
          {
            if ((uiI + pStaticData->uiParLastWrittenPreCondTabPos) < pTable->uiNrOfTableRows)
            {
              const uint8 uiTblIdx = 2u * uiI;
              const uint8 uiTblLastIdx = 2u * (uiI + pStaticData->uiParLastWrittenPreCondTabPos);
              if (pTable->eTableFloatType == HEADParameterTableFloatType_f16)
              {
                /* PRQA S 0491 2*//* MISRA rule 17.4: reviewer name: Thomas Diepolder, date: 17.03.2011 reason: Bounds are explicitly checked against the table parameters */
                pMTSPreCondParamData->fTable[uiTblIdx] = HEADConvf16Tof32(((const f16_t*)pTable->pTable)[uiTblLastIdx]);
                pMTSPreCondParamData->fTable[uiTblIdx + 1u] = HEADConvf16Tof32(((const f16_t*)pTable->pTable)[uiTblLastIdx + 1u]);
              }
              else
              {
                /* PRQA S 0491 2*//* MISRA rule 17.4: reviewer name: Thomas Diepolder, date: 17.03.2011 reason: Bounds are explicitly checked against the table parameters */
                pMTSPreCondParamData->fTable[uiTblIdx] = ((const float32*)pTable->pTable)[uiTblLastIdx];
                pMTSPreCondParamData->fTable[uiTblIdx + 1u] = ((const float32*)pTable->pTable)[uiTblLastIdx + 1u];
              }
            }
          }
        }
        else if (pMTSPreCondParamData->sParameterHeader.ParamMainType == (HEADParamMainType_t)HEADParamMainType_3dTable)
        {
          uint8 uiI, uiSize, iRows, iCol;
          /*PRQA S 0314 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
          const HEADParameterTable3D_t *pTable3d = ((const HEADParameterTable3D_t *)((const void *)(pStaticData->pParLastWrittenPreCondParameter)));
          pMTSPreCondParamData->fScalarValue_DefaultX1 = HEADConvf16Tof32(pTable3d->f16DefaultValX1);
          pMTSPreCondParamData->fScalarValue_DefaultX2 = HEADConvf16Tof32(pTable3d->f16DefaultValX2);
          pMTSPreCondParamData->eTableType = pTable3d->TableType1;
          pMTSPreCondParamData->eTableType2 = pTable3d->TableType2;
          pMTSPreCondParamData->uiNrOfTableRows = pTable3d->uiNrOfTableRows;
          pMTSPreCondParamData->uiNrOfTableCols = pTable3d->uiNrOfTableCols;
          pMTSPreCondParamData->X2SignalTyp = pTable3d->X2SignalType;
          iRows = MIN(HEAD_MTS_MAX_3D_TABLE_ROWS, pTable3d->uiNrOfTableRows);
          iCol = MIN(HEAD_MTS_MAX_TABLE_COLUMNS, pTable3d->uiNrOfTableCols);
          uiSize = ((iRows + 1u) * iCol);
          for (uiI = 0u; uiI < uiSize / 2u; uiI++)
          {
            const uint8 uiTblIdx = 2u * uiI;
            const uint8 uiTblLastIdx = 2u * (uiI + pStaticData->uiParLastWrittenPreCondTabPos);
            pMTSPreCondParamData->fTable3d[uiTblIdx] = HEADConvf16Tof32(((const f16_t*)pTable3d->pTable)[uiTblLastIdx]);
            pMTSPreCondParamData->fTable3d[uiTblIdx + 1u] = HEADConvf16Tof32(((const f16_t*)pTable3d->pTable)[uiTblLastIdx + 1u]);
          }
        }
        else
        {
          /*Do Nothing*/
        }
      }
    }
    else
    {
      /* no valid parameter found -> return invalid */
      pMTSPreCondParamData->bParamValid = 0u;
    }
  }
  return retValue;
}

/*************************************************************************************************************************
Functionname:         HEADMTSNextPreCondition                                                                        */ /*!
 @brief               go to the next precondition parameter in the precondition parameter list

 @description         go to the next precondition parameter in the precondition parameter list
                      Parameters are already sorted in accordance to the
                      the operator and outType in a precondition group list
                      The parameter is selected from the current precondition group
                      @startuml
                      Start
                          If(Null check for all input parameter) then (True);
                         :Set null pointer error;
                         Else
                         If(check for last written precond number >= the number of preconditions) then (True);
                         :Reset precondition number, param number
                         tablepos and pParLastWrittenPreCondParameter
                         HEADMTSResetPreCondParam;
                         Endif
                         :Get the current precondition information;
                         If(Null check for last written precondition param) then (True)
                         #orange:
                         First parameter in this PreCondition Group;
                         :get the parameter in this precondition group;
                         :Increment the precond param number;
                         If(Null check for precondition param) then (True)
                         #orange:
                         No more valid param in this precondition group;
                        :Increment PreCond num and reset param number and table pos;
                         Endif
                         Else
                         #orange: Iterate through current pre condition group;
                         If(ParamMainType is HEADParamMainType_Table) then (True);
                         :Increment the uiParLastWrittenPreCondTabPos by HEAD_MTS_MAX_TABLE_ROWS;
                         If(Check if all the table rows are transmitted) then (True);
                         :Set the uiParLastWrittenPreCondTabPos to zero;
                         :Get the next relevant param in this precondition;
                         If(Null check for last written precondition param) then (True);
                         :Increment uiParLastWrittenPreCondParNr;
                         Else
                         #orange:
                         No new parameter in current precondition group;
                         :Increment PreConditionnr and param number;
                         Endif
                         Else
                         #orange: Do nothing as next table row is already selected;
                         Endif
                         Else(ParamMainType is scalar);
                         :Set the uiParLastWrittenPreCondTabPos to zero;
                         :Get the next relevant param;
                         If(pParLastWrittenPreCondParameter is not NULL) then (True);
                         :Increment precond param number;
                         Else
                         :Increment PreConditionnum and param number;
                         Endif
                         Endif
                         Endif
                         Endif
                         :Update the MTS data for uiPreCondNr,uiParNr and uiTablePos;
                         :Return the error type;
                      stop
                      @enduml
 @return               eGDBError_t     :  GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

 @param[in]            pInputData      : Pointer to HEAD input data
 @param[in]            pMTSPreCondParamData   : Pointer to head MTS precondition parameter data
 @param[in]            pMTSStaticData  : Pointer to head MTS static data

 @glob_in              None
 @glob_out             None

 @c_switch_part        None
 @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION,HEAD_CFG_PRECONDITION

 @pre                  None
 @post                 None

 @InOutCorrelation     See description

 @testmethod           Test of output data (dynamic module test)

 @traceability         
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1134-0007e0f8}

 @author               Minuthi H U | minuthi.h.u@continental-corporation.com
*************************************************************************************************************************/
  static eGDBError_t HEADMTSNextPreCondition(const HEADInputData_t *pInputData, HEADMTSPreCondParameterData_t *pMTSPreCondParamData, HEADMTSStaticData_t *pMTSStaticData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if (pInputData == NULL || pMTSPreCondParamData == NULL || pMTSStaticData == NULL)
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    const HEADPreCond_t *pCurrPrecond;
    if (pMTSStaticData->uiParLastWrittenPreCondNr >= pInputData->pPreCondList->uiNrOfPreConds)
    {
      pMTSStaticData->uiParLastWrittenPreCondNr = 0;
      HEADMTSResetPreCondParam(pMTSStaticData);
    }
    pCurrPrecond = HEADGetPreCondition(pInputData->pPreCondList, pMTSStaticData->uiParLastWrittenPreCondNr);
    if (pMTSStaticData->pParLastWrittenPreCondParameter == NULL) /* First parameter in this PreCondition Group*/
    {
      const HEADParameterEmpty_t *const pParamList = pCurrPrecond->rgPreCond.pParameterList;
      pMTSStaticData->pParLastWrittenPreCondParameter = pParamList;
      pMTSStaticData->uiParLastWrittenPreCondParNr++;
      /*No more valid param in this precondition group */
      if (pMTSStaticData->pParLastWrittenPreCondParameter == NULL)
      {
        pMTSStaticData->uiParLastWrittenPreCondParNr = 0;
        pMTSStaticData->uiParLastWrittenPreCondTabPos = 0;
        pMTSStaticData->uiParLastWrittenPreCondNr += 1u;
      }
    }
    else /* Iterate through current pre condition group*/
    {
      /*parameter is already defined*/
      /*check if current parameter is in a table*/
      if ((HEADParamMainType_t)(pMTSStaticData->pParLastWrittenPreCondParameter->ParameterType.sParameterType.ParamMainType) == (HEADParamMainType_t)HEADParamMainType_Table)
      {
        /*check if table is already finished*/
        /*PRQA S 0314 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
        const HEADParameterTable_t *pTable = (const HEADParameterTable_t*)((const void *)(pMTSStaticData->pParLastWrittenPreCondParameter));
        /*increase position in table*/
        pMTSStaticData->uiParLastWrittenPreCondTabPos += HEAD_MTS_MAX_TABLE_ROWS;
        if (pTable->uiNrOfTableRows <= pMTSStaticData->uiParLastWrittenPreCondTabPos)
        {
          pMTSStaticData->uiParLastWrittenPreCondTabPos = 0u;

          /*table already transfered - jump to next parameter*/
          pMTSStaticData->pParLastWrittenPreCondParameter = (const HEADParameterEmpty_t *)(pMTSStaticData->pParLastWrittenPreCondParameter->ParameterType.pNextRelevantParam);

          if (pMTSStaticData->pParLastWrittenPreCondParameter != NULL)
          {
            pMTSStaticData->uiParLastWrittenPreCondParNr++;
          }
          else /* no new parameter in current pre condition group- jump to next pre condition group */
          {
            pMTSStaticData->uiParLastWrittenPreCondNr += 1u;
            pMTSStaticData->uiParLastWrittenPreCondParNr = 0;
          }
        }
        else
        {
          /*nothing to do - next table rows already selected*/
        }
      }
      else
      {
        pMTSStaticData->uiParLastWrittenPreCondTabPos = 0u;
        /*scalar - directly jump to the next parameter*/
        pMTSStaticData->pParLastWrittenPreCondParameter = (const HEADParameterEmpty_t *)(pMTSStaticData->pParLastWrittenPreCondParameter->ParameterType.pNextRelevantParam);
        if (pMTSStaticData->pParLastWrittenPreCondParameter != NULL)
        {
          pMTSStaticData->uiParLastWrittenPreCondParNr++;
        }
        else
        {
          pMTSStaticData->uiParLastWrittenPreCondNr += 1u;
          pMTSStaticData->uiParLastWrittenPreCondParNr = 0;
        }
      }
    }
    pMTSPreCondParamData->uiPreCondNr = pMTSStaticData->uiParLastWrittenPreCondNr;
    pMTSPreCondParamData->uiParNr = pMTSStaticData->uiParLastWrittenPreCondParNr;
    pMTSPreCondParamData->uiTablePos = pMTSStaticData->uiParLastWrittenTabPos;
  }
  return retValue;
}

  /*************************************************************************************************************************
  Functionname:         HEADMTSResetPreCondParam                                                                     */ /*!

  @brief                Reset MTS precondition parameters

  @description          Reset MTS precondition parameters

                        @startuml
                        Start
                            Note Right: The start of the first precondition reset the following things.
                            : Reset precondition number;
                            : Reset precondition;
                            : Reset parameter number;
                        stop
                        @enduml

  @return               eGDBError_t     : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[out]           pMTSStaticData  : Pointer to MTS Static Data for internal mts sending process

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION,HEAD_CFG_PRECONDITION

  @pre                  None
  @post                 None

  @InOutCorrelation     See description

  @testmethod           Test of output data (dynamic module test)

  @traceability.......
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1134-0007e0f8}

  @author               Minuthi H U | minuthi.h.u@continental-corporation.com
  *************************************************************************************************************************/

  static void HEADMTSResetPreCondParam(HEADMTSStaticData_t *pMTSStaticData)
  {
    /* reset parameter number */
    pMTSStaticData->uiParLastWrittenPreCondParNr = 0;

    /* reset table pos number */
    pMTSStaticData->uiParLastWrittenPreCondTabPos = 0u;

    /* reset condition group number */
    pMTSStaticData->pParLastWrittenPreCondParameter = NULL;
  }

#endif /*End PreConditon*/
/*************************************************************************************************************************
  Functionname:         HEADMTSSendModuleCommonData                                                                 */ /*!

  @brief                writes one head parameter to head MTS output

  @description          writes one head parameter to head MTS output
  
                        @startuml
                        Start
                            If(Null check for input parameter of the function) then (True)
                            : Set the null pointer error;
                            else
                            :Fetch total Number of \nModules;
                            Note right:Fetch the total Number of Modules from \nHEAD Module List.

                            while (is the Module Number Valid?) is (yes)
                            if(check for nless than the maximum number of modules) then (Yes)
                            :Fetch the Module;
                            Note left:Fetch the module correspond to \nModule Number.
                            If(Is module is null?) then (No)
                            : Update the module information to MTS common data;
                            Note right
                             Module information are updated like State, number of module states, 
                            Min module state, QoS and Reported Error
                            endnote
                            while (Is the Module state Valid?) is (yes)
                            : Get the last cycle state and transition;
                            If(Is last cycle transition Null?) then (No)
                            while (Is the condition groups Valid?) is (yes)
                            : Fetch  current module  orGroup hypothesis;
                            Endwhile(No)
                            Endif
                            Endwhile(No)
                            while (Is the Module state Valid?) is (yes)
                            : Get module state information;
                            If(check for module state timer value greater than zero) then (Yes)
                            : Fetch the state timer value i.e. how long the 
                            Module is in the current state
                            ;
                            Else
                            :  Fetch the timer value i.e. how long the 
                            Module is not in the current state;
                            Endif 
                            : Update the module timer information to MTS common data;
                            Endwhile(No)
                            else
                            : Update the null pointer error;
                            endif
                            else
                            : Update the null pointer error;

                            Endif
                            Endwhile(No)
                            endif
                            : Return the updated error type;
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

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1131-0007e0f8}
  
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
    uint8 uiK;

    pMTSModuleCommonData->uiNrOfModules = pInputData->pModuleList->uiNrOfModules;
    for(uiI = 0u; uiI < pMTSModuleCommonData->uiNrOfModules; uiI++)
    {
      if(uiI < HEAD_MTS_MAX_MODULES)
      {
        HEADModule_t *pModule = HEADGetModule(pInputData->pModuleList, (uint32)uiI);

        if (pModule != NULL)
        {
          HEADModuleState_t * pLastCycleState = HEADGetModuleState(pModule, (uint32)pModule->eDGSMLastCycleState - (uint32)pModule->eNumModuleStateMin);
          HEADStateTransition_t * pLastCycleTransition = HEADGetLastTransitionForState(pLastCycleState, pModule->eDGSMState);

          pMTSModuleCommonData->sModuleInfo[uiI].eState         = (HEADSMState_t) pModule->eDGSMState;
          pMTSModuleCommonData->sModuleInfo[uiI].uiNumModuleStates = pModule->uiNumModuleStates;
          pMTSModuleCommonData->sModuleInfo[uiI].uiMinModuleState = (HEADSMState_t)pModule->eNumModuleStateMin; 

          pMTSModuleCommonData->sModuleInfo[uiI].eQoS           = (HEADModuleQoS_t) pModule->eQoS;
          pMTSModuleCommonData->sModuleInfo[uiI].eReportedError = (HEADModuleRepError_t) pModule->eReportedError;

          if(pLastCycleTransition != NULL)
          {
            for (uiK = 0u; uiK < pLastCycleTransition->uiNumConditionGroups; uiK++)
            {
              pMTSModuleCommonData->sModuleInfo[uiI].uiHypInOrGroup |= pLastCycleTransition->puHypInCondGroup[uiK];
            }
          }

          for (uiJ = 0u; uiJ < pModule->uiNumModuleStates; uiJ++)
          {
            float32 fRelStateTimer;
            HEADModuleState_t * pState = HEADGetModuleState(pModule, uiJ);
            if (pState->fStateTimer > 0.0f )
            {
              fRelStateTimer = pState->fStateTimer;
            }
            else
            {
              fRelStateTimer = pState->fNotInStateTimer;
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
  @param[in,out]        pMTSStaticData : Pointer to MTS Static Date for internal mts sending process
  @param[in,out]        pMTSSPMModule : Pointer MTS SPM rule

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability        
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}
  
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
      /* QoS and Reported Error details are passed to MTS through a separate autocode file in headview plugin */
      pMTSSPMModule->uiNumQoSModules  = pCurrentRule->uiNumQoSModules;

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

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1130-0007e0f8}
  
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

  @param[in]            pInputData    : Pointer to HEAD input Data
  @param[in,out]        pMTSSPMTimers : Pointer to MTS SPMTimers

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability        
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}
  
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
  Functionname:         HEADMTSSendInputSignal                                                                      */ /*! 

  @brief                writes dynamic information of one input signal to MTS

  @description          writes dynamic information of one input signal to MTS
                        
                        @startuml
                        Start
                            If(check for less than the max input signal) then (Yes)
                            If(Null check for input signal and signal list) then (Yes)
                            : Input signal updated to the MTS list;
                            If(Is signal type is valid?) then (Yes) 
                            #orange: Get the input value and updated to the MTS signal list >
                            Note right: Input signal types are depends on the \nvalue i.e. signed float, unsigned int ,bool etc.
                            Else 
                            :Set error type as unknown;
                            Endif
                            Else
                            :Set error type as null pointer error;
                            Endif
                            Else 
                            : Set error type as over flow error;
                            Endif
                            : Return the error type;
                        Stop
                        @enduml
                        
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.
                        
  @param[in]            pInputSignal        : Stores signal quality, it's type, quality and Standard Deviation
  @param[in]            pMTSInputSignalList : Poinhter to MTS input signal list
  @param[in]            uiMTSInputSigNr     : MTS input signal number
  @param[in]            eHEADMTSInSigIdent  : Identify the HEAD output signals

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability       
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1130-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendInputSignal(const struct HEADInputValue_t *pInputSignal, 
                                   HEADMTSInputSignalList_t *pMTSInputSignalList, 
                                   uint8 uiMTSInputSigNr, HEADMTSInSigIdent_t eHEADMTSInSigIdent)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
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
        retValue = GDB_ERROR_UNKNOWN_TYPE;
        break;
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
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendInputSignals                                                                     */ /*! 
  
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
                        
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.
                        
  @param[in]            fpExtraValueFct     : Function pointer to a function that writes the extra input signals to the MTS
  @param[in]            pExtraValueList     : Void pointer to the extra input list
  @param[in]            pInputData          : Pointer to HEAD input data     
  @param[in]            pMTSInputSignalList : Poinhter to MTS input signal list
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability       
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1130-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com

*************************************************************************************************************************/
eGDBError_t HEADMTSSendInputSignals(const HEADInputData_t *pInputData, const void *pExtraValueList, HEADMTSSendExtraInputSignals_ft *fpExtraValueFct, HEADMTSInputSignalList_t *pMTSInputSignalList)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData != NULL) && (pInputData->pInputValueList != NULL) && (pMTSInputSignalList != NULL))
  {
    uint8 uiNr = 0u;
    /*send input value list*/
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->LongVelocity, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_Velocity);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->LongAcceleration, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_Acceleration);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->YawRate, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_YawRate);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->DrivingDirection, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_DrivinDirection);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->EgoLatCurvature, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_EgoLatCurvature);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->CDHypotheses, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_CDHypotheses);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->DIMHypotheses, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_DMHypotheses);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->SafeObjDistSfty, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_SafeObjDistSfty);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->SafeObjDistPerf, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_SafeObjDistPerf);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->StabCtrlState, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_StabCtrlState);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->BrakeChainState, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_BrakeChainState);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->WarnChainState, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_WarnChainState);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->DriverFeedback, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_DriverFeedback);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->DriverActivity, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_DriverActivity);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->DriverAttention, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_DriverAttention);
    uiNr++;
    #if HEAD_CFG_TURN_ASSIST
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->SteeringAngle, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_SteeringAngle);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->TurnIndicatorInSteeringDirection, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_TurnIndicatorInSteeringDirection);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->GasPedal, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_GasPedal);
    uiNr++;
    #endif /* HEAD_CFG_TURN_ASSIST */
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->ObjListSource, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_ObjListSource);
    uiNr++;
    retValue = HEADMTSSendInputSignal(&pInputData->pInputValueList->ObjListDegraded, pMTSInputSignalList, uiNr, eHEADMTSInSigIdent_ObjListDegraded);
    uiNr++;

    /*send extra values*/
    if ( (pExtraValueList != NULL) && (fpExtraValueFct != NULL))
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

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability        
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1135-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendHeaderData(HEADMTSHeaderData_t *sMTSHeaderData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if(sMTSHeaderData != NULL)
  {
    sMTSHeaderData->uiBaseVersion = HEAD_AUTOVERSION;
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

  @brief                writes static header information to mts struct
  
  @description          writes static header information to mts struct
  
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

  @param[in,out]        pStaticData : Pointer to MTS Static Date for internal mts sending process
  @param[in,out]        pMTSConfigData : Pointer to MTS Cfg Data
  @param[in]            pCfg[] : Pointer to HEAD Config
  @param[in]            uiCfgLen : Config Length

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability       
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1135-0007e0f8}
  
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

/*************************************************************************************************************************
  Functionname:         HEADMTSSendTransitions                                                                      */ /*!

  @brief                writes Transition Info to MTS(one Transition per cycle)

  @description          writes Transition Info to MTS(one Transition per cycle)
                        @startuml
                        Start
                        If(Null check for input signal and signal list) then (Yes)
                        :Set error type as GDB_ERROR_POINTER_NULL;
                        Else
                        :Fetch the current module and state;
                        :Increment the uiTransLastWrittenTransNr to fetch the next transition;
                        If(is transition number > Max transition number)(Yes)
                        :Reset the transition number and increment the state number;
                        Endif
                        If(is state number > Max state number)(Yes)
                        :Reset the state number and Increment the module number;
                        Endif
                        If(is module number > max module number)(Yes)
                        :Reset the module number;
                        Endif
                        :Fetch the current module,state and transition;
                        :Send transition data to MTS;
                        Endif
                        :Return the error type;
                        Stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned when pointers are okay, otherwise Null Pointer error is returned.

  @param[in]            pInputData : Pointer to HEAD input data
  @param[in,out]        pMTSStaticData : Pointer to MTS Static Date for internal mts sending process
  @param[in,out]        pMTSTransitionData : Pointer MTS Transition data

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability        
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1136-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADMTSSendTransitions(const HEADInputData_t *pInputData, HEADMTSStaticData_t *pStaticData, HEADMTSTransitionData_t *pMTSTransitionData)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pInputData == NULL) || (pMTSTransitionData == NULL) || (pStaticData == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    HEADModule_t*          pModule = HEADGetModule(pInputData->pModuleList, (uint32)pStaticData->uiTransLastWrittenModNr);
    HEADModuleState_t*     pState  = HEADGetModuleState(pModule,pStaticData->uiTransLastWrittenStateNr);
    HEADStateTransition_t* pTransition;

    // Find next Transition to transmit
    pStaticData->uiTransLastWrittenTransNr++; 
    if (pStaticData->uiTransLastWrittenTransNr >= pState->uiNumTransitions)
    {
      pStaticData->uiTransLastWrittenTransNr = 0u;
      pStaticData->uiTransLastWrittenStateNr++;
      if(pStaticData->uiTransLastWrittenStateNr >= pModule->uiNumModuleStates)
      {
        pStaticData->uiTransLastWrittenStateNr = 0;
        pStaticData->uiTransLastWrittenModNr++;
        if (pStaticData->uiTransLastWrittenModNr >= pInputData->pModuleList->uiNrOfModules)
        {
          pStaticData->uiTransLastWrittenModNr = 0u;
        }
      }
    }
    pModule     = HEADGetModule(pInputData->pModuleList, (uint32)pStaticData->uiTransLastWrittenModNr);
    pState      = HEADGetModuleState(pModule,pStaticData->uiTransLastWrittenStateNr);
    pTransition = &(pState->pStateTransitionList[pStaticData->uiTransLastWrittenTransNr]);

    pMTSTransitionData->uiModuleNr    = pStaticData->uiTransLastWrittenModNr;
    pMTSTransitionData->uiStateNr     = pStaticData->uiTransLastWrittenStateNr;
    pMTSTransitionData->uiTransNr     = pStaticData->uiTransLastWrittenTransNr;
    pMTSTransitionData->uiTargetState = (uint8)(pTransition->eDGSMNextState);
  }
  return retValue;
}


#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* MEDIC_CFG_HEAD20 */

/*PRQA S 7013 *//* Date: 2018-12-17, Reviewer: Pronnoy Chowdhury, Reason:  suppressed number of executable lines per file. */
