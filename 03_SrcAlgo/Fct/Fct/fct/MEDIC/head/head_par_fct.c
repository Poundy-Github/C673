/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_par_fct.c

DESCRIPTION:               functions of the HEAD parameters 

AUTHOR:                    $Author: Boxey, Shishir (uic05032) (uic05032) $

CREATION DATE:             $Date: 2020/08/10 16:49:53CEST $

VERSION:                   $Revision: 1.25 $

LEGACY VERSION:            1.59
  
**************************************************************************** */
/**
@defgroup head_par_fct HEAD_PAR_FCT
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

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static eGDBError_t HEADParamSetGeneric(HEADParameterEmpty_t *pParam, HEADParameterEmpty_t *pRoot, 
                                       eHEADParamOutType_t eOutputType, HEADParameterMode_t bfMode, 
                                       HEADParameterHypothesisSub_t bfHypothesis, eHEADParamMainValueType_t eMainValueType, 
                                       HEADParameterState_t bfParamState, eHEADParamOperator_t eOperator, HEADParameterOrGroup_t uiOrGroup);
static eGDBError_t HEADGetTableParam(const HEADParameterTable_t *pParamTable, const struct HEADInputData_t *pInputData, 
                                     const HEADHypothesis_t *pHyp, uint8 uiModuleNr, float32 *pOutValue, 
                                     const HEADAdditionalTableInputValues_t* pAddTableInputs);
static boolean HEADIsCustomParameter( eHEADHypOutType_t eHypOutType );
static eGDBError_t HEADGetValueFromHyp( boolean bCheckOnlyPHyp, const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, 
                                       eHEADHypOutType_t eHypOutType, uint8 uiModuleNr, float32 *fVal);

/*************************************************************************************************************************
  Functionname:         HEADParamSetGeneric                                                                          *//*!

  @brief                creates a scalar parameter header

  @description          creates a scalar parameter header --> and sets the pointer from the last
                        element to the current element 
                        So the list that looked like this before:
                        root->Par1->Par2->Par3->NULL
                        looks now like this (with the new Parameter "ParNew"):
                        root->Par1->Par2->Par3->ParNew->NULL
                        Long parameter list is caused by the interface to 
                        auto-generated code

                        @startuml
                        Start
                            If(check Parameter empty structure is Null or not) then (Yes)
                            : update null pointer error;
                            Else
                            : initialize head parameter;
                            If(Is parameter and root parameter empty structure equal?) then (No)
                            While (null check for next parameter) then (No)
                            :next parameter assigned to next Parameter empty structure;
                            Endwhile(false)
                            : parameter empty structure value assigned 
                              to next Parameter empty structure;
                            endif
                            if(check operator type) then (Yes)
                            else if(is it less than operator ) then (Yes)
                            : update the value. That value must be less than parameter;
                            Else if(Is it greater than operator?) then (Yes)
                            :update the value. That value must be greater than parameter;
                            Else if (Is it output value specific operator?) 
                            : updated value Greater or less than the parameter.
                            It is depends on the output parameter;
                            Endif
                            Endif
                           :return the updated value;
                        stop
                        @enduml

  @return               eGDBError_t    :GDB error type is returned

  @param[in,out]        pParam         : pointer to head parameter empty structure 
  @param[in,out]        pRoot          : pointer to head parameter empty structure 
  @param[in]            eOutputType    : hypothesis output variable type of the parameter
  @param[in]            bfMode         : These variable is used to address fields in bit-fields
  @param[in]            bfHypothesis   : Head bit field for head parameter hypothesis
  @param[in]            eMainValueType : These MainValueType defines value or factor
  @param[in]            bfParamState   : These ParamState defines mode transitions
  @param[in]            eOperator      : head parameter operator for mathematic operation
  @param[in]            uiOrGroup      : Its define the indivitual module orgroups
  
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
*************************************************************************************************************************/
static eGDBError_t HEADParamSetGeneric(HEADParameterEmpty_t *pParam, 
                                       HEADParameterEmpty_t *pRoot, 
                                       eHEADParamOutType_t eOutputType, 
                                       HEADParameterMode_t bfMode,
                                       HEADParameterHypothesisSub_t bfHypothesis, 
                                       eHEADParamMainValueType_t eMainValueType, 
                                       HEADParameterState_t bfParamState, 
                                       eHEADParamOperator_t eOperator, 
                                       HEADParameterOrGroup_t uiOrGroup)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pParam == NULL) || (pRoot == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    HEADParameterEmpty_t *pNext;
    /*set header*/    
    pParam->ParameterType.sParameterType.ParameterHypSubType = (uint16)bfHypothesis;
    pParam->ParameterType.sParameterType.ParameterMode       = (uint8)bfMode;
    pParam->ParameterType.sParameterType.ParamOutType        = (uint8)eOutputType;
    pParam->ParameterType.sParameterType.ParamMainValueType  = (uint8)eMainValueType;
    pParam->ParameterType.sParameterType.ParamState          = (uint8)bfParamState;
    pParam->ParameterType.sParameterType.ParameterOrGroup    = (uint8) (MIN(uiOrGroup,(HEAD_MAX_OR_GROUPS-1uL)));
    /*set nextElementPointer to the nextElementPointer of the root element*/
    pParam->ParameterType.pNextParam          = NULL;

    /*append parameter to list in case of not the first paramter*/
    if(pRoot != pParam)
    {    
      pNext = pRoot;
      while(pNext->ParameterType.pNextParam != NULL)
      {
        pNext = pNext->ParameterType.pNextParam;
      }
      pNext->ParameterType.pNextParam = pParam;
    }
    
    switch(eOperator)
    {
      case HEADParamOperator_LESSTHAN:
        pParam->ParameterType.sParameterType.ParamOperator = (uint8) HEADParamOperator_LESSTHAN;
        break;

      case HEADParamOperator_GREATERTHAN:
        pParam->ParameterType.sParameterType.ParamOperator = (uint8) HEADParamOperator_GREATERTHAN;
        break;

      case HEADParamOperator_DEFAULT:
      default:
        switch(eOutputType)
        {          
          case HEADParamOutType_AllConditionsForOrGroupMet:
          case HEADParamOutType_StateActiveTime:
          case HEADParamOutType_OtherModuleStateTime:
          case HEADParamOutType_HypProb:
          case HEADParamOutType_ObjProb:
          case HEADParamOutType_EgoVelocity:
          case HEADParamOutType_EgoAccel:
          case HEADParamOutType_ClosingVel:
          case HEADParamOutType_ANecLatAbs:
          case HEADParamOutType_HypLifetime:
          #if HEAD_CFG_CORRIDOROCCUPANCY
          case HEADParamOutType_CorridorOccupancy:
          #endif
		  case HEADParamOutType_ObjMoveDir:
            pParam->ParameterType.sParameterType.ParamOperator = (uint8) HEADParamOperator_GREATERTHAN;
            break;          
          
          case HEADParamOutType_TTC:
          case HEADParamOutType_TTC2:
          case HEADParamOutType_TTC3:
          case HEADParamOutType_TTC4:
          case HEADParamOutType_TTB_PRE:
          case HEADParamOutType_TTB_ACUTE:
          case HEADParamOutType_TTS_PRE:
          case HEADParamOutType_TTS_ACUTE:
          case HEADParamOutType_ANecLong:          /*aneclong is < 0!*/  
          case HEADParamOutType_ObjectDist:
          case HEADParamOutType_ObjectDistLat:
          case HEADParamOutType_SafeObjDistSfty:
          case HEADParamOutType_SafeObjDistPerf:
          case HEADParamOutType_VRelX:            /*vRelX is < 0!*/
          case HEADParamOutType_TTMLongPre: 
          case HEADParamOutType_TTMLongAcute:
          case HEADParamOutType_EgoLatCurvature:
            pParam->ParameterType.sParameterType.ParamOperator = (uint8) HEADParamOperator_LESSTHAN;
            break;
          
          case HEADParamOutType_Max:
          default: /*these should be defined - but lets set to lessthan*/           
            pParam->ParameterType.sParameterType.ParamOperator = (uint8) HEADParamOperator_LESSTHAN;
            break;
         
        }
        break;

    }
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:          HEADParamSetScalarWithBitPack                                                                */ /*!

  @brief                creates a scalar parameter

  @description          creates a scalar parameter and adds a bit pack for some special functions, the bitpack defines the (f16_t) 
                        default value of the hypothesis vlaue if the hypothesis isn't found (for hypothesis dependent parameters 
                        like HEADParamOutType_TTC) the bitpack defines some information about other module state for 
                        HEADParamOutType_OtherModuleStateTime (HEADOtherModuleStateTime2BitPack(ModuleNr, ModulState, bInState))
                        Long parameter list is caused by the interface to auto-generated code.
                        @startuml
                        Start
                            If(check for either scalar parameter or empty parameter availability) then (No)
                            : Null pointer error is updated;
                            Else(Yes)
                            : set header, extra bit pack, object Class and dynamic Property;
                            endif
                            Note right:Set Scalar parameter as configured by HEAD AutoCoder \n and link the parameter to corresponding condition.
                            :Return updated error type;
                        Stop
                        @enduml
          
  @return               eGDBError_t    :GDB error type is returned

  @param[in,out]        pParam         : Pointer to head parameter empty structure 
  @param[in,out]        pRoot          : Pointer to head parameter empty structure 
  @param[in]            eOutputType    : Hypothesis output variable type of the parameter
  @param[in]            bfMode         : These variable is used to address fields in bit-fields
  @param[in]            bfHypothesis   : Head bit field for head parameter hypothesis
  @param[in]            eMainValueType : These MainValueType defines value or factor
  @param[in]            bfParamState   : These ParamState defines mode transitions
  @param[in]            fValue         : Store the float between min and max range
  @param[in]            eOperator      : Tead parameter operator for mathematic operation
  @param[in]            uiOrGroup      : Its define the indivitual module orgroups
  @param[in]            bfObjectClass  : Object class of hypothesis dependent parameter
  @param[in]            bfDnyamicProp  : Head eba dynamic properties
  @param[in]            bitPack        : Head  output type dependent parameter information

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
eGDBError_t HEADParamSetScalarWithBitPack(
  HEADParameterScalar_t *pParam, HEADParameterEmpty_t *pRoot, 
  eHEADParamOutType_t eOutputType, HEADParameterMode_t bfMode,
  HEADParameterHypothesisSub_t bfHypothesis, 
  eHEADParamMainValueType_t eMainValueType, HEADParameterState_t bfParamState, 
  float32 fValue, eHEADParamOperator_t eOperator, 
  HEADParameterOrGroup_t uiOrGroup, HEADEBAObjectClass_t bfObjectClass, 
  HEADEBADynProp_t bfDnyamicProp, HEADBitPack_t bitPack)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pParam == NULL) || (pRoot == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    /*set header*/
    retValue = HEADParamSetGeneric((HEADParameterEmpty_t*)((void*)pParam), pRoot, eOutputType, bfMode, /*PRQA S 0314 #date: 2020-06-02, reviewer: Nalina M, reason: Generic Implementation */
                                   bfHypothesis, eMainValueType, bfParamState, eOperator, uiOrGroup);
    pParam->ParameterType.sParameterType.ParamMainType = (uint8) HEADParamMainType_Scalar;
    /*set raw parameter value*/

    fValue = MINMAX_FLOAT( (float32) -HEADPARFCT_FLOAT_MAX, (float32) HEADPARFCT_FLOAT_MAX, fValue);
    pParam->f16RawValue = HEADConvf32Tof16(fValue);  
    /*set extra bit pack*/
    pParam->uiSpecialParInfo = bitPack;
    pParam->ParameterType.sParameterType.ParamObjectClass = bfObjectClass;
    pParam->ParameterType.sParameterType.ParamDynProp = bfDnyamicProp;
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADParamSetTableWithBitPack                                                                */ /*!

  @brief                creates a table parameter

  @description          creates a table parameter and adds a bit pack for some special functions
                        Long parameter list is caused by the interface to 
                        auto-generated code
                        @startuml
                            Start
                            If(check for scalar, empty or table parameter availability) then (No)
                            : Null pointer error is updated;
                            Else(Yes)
                            : set header, object Class dynamic Property and raw parameter value;
                            endif
                            Note right:Set table parameter as configured by HEAD AutoCoder \n and link the parameter to corresponding condition.
                            :Return updated error type;
                        Stop
                        @enduml

  @return               eGDBError_t    :GDB error type is returned

  @param[in,out]        pParam         : Pointer to head parameter empty structure 
  @param[in,out]        pRoot          : Pointer to head parameter empty structure 
  @param[in]            eOutputType    : Hypothesis output variable type of the parameter
  @param[in]            eTableType     : Parameter table type
  @param[in]            bfMode         : These variable is used to address fields in bit-fields
  @param[in]            bfHypothesis   : Head bit field for head parameter hypothesis
  @param[in]            eMainValueType : These MainValueType defines value or factor
  @param[in]            bfParamState   : These ParamState defines mode transitions
  @param[in]            uiNrOfRows     : Defines the number of table rows
  @param[in]            pTable         : Pointer to the table containing 2*uiNrOfTableRows values
  @param[in]            eOperator      : Tead parameter operator for mathematic operation
  @param[in]            uiOrGroup      : Its define the indivitual module orgroups
  @param[in]            fDefaultValue  : Default value if table input cannot be found
  @param[in]            eFloatType     : Parameter for scalar float values
  @param[in]            bfObjectClass  : Object class of hypothesis dependent parameter
  @param[in]            bfDnyamicProp  : Head eba dynamic properties
  @param[in]            bitPack        : Head  output type dependent parameter information

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  pParam, pTable and pRoot must be in memory, pTable must be defined with the correct parameter settings
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADParamSetTableWithBitPack(
  HEADParameterTable_t *pParam, HEADParameterEmpty_t *pRoot, eHEADParamOutType_t eOutputType, 
  HEADParamTableType_t eTableType, HEADParameterMode_t bfMode, 
  HEADParameterHypothesisSub_t bfHypothesis, eHEADParamMainValueType_t eMainValueType, 
  HEADParameterState_t bfParamState, uint8 uiNrOfRows, const void *pTable, eHEADParamOperator_t eOperator,
  HEADParameterOrGroup_t uiOrGroup, float32 fDefaultValue, eHEADParameterTableFloatType_t eFloatType,
  HEADEBAObjectClass_t bfObjectClass, HEADEBADynProp_t bfDnyamicProp, HEADBitPack_t bitPack)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pParam == NULL) || (pRoot == NULL) || (pTable == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    /*set header*/
    retValue = HEADParamSetGeneric((HEADParameterEmpty_t*)((void *)pParam), pRoot, eOutputType,/*PRQA S 0314 #date: 2020-06-02, reviewer: Nalina M, reason: Generic Implementation */
                      bfMode, bfHypothesis, eMainValueType, bfParamState, eOperator, uiOrGroup);
    pParam->ParameterType.sParameterType.ParamMainType = (uint8) HEADParamMainType_Table;
    pParam->ParameterType.sParameterType.ParamObjectClass = bfObjectClass;
    pParam->ParameterType.sParameterType.ParamDynProp = bfDnyamicProp;
    /*set raw parameter value*/    
    pParam->eTableFloatType = eFloatType;
    pParam->pTable = pTable; /*const warning ROM pointer to RAM pointer*/
    pParam->TableType = eTableType;
    pParam->uiNrOfTableRows = uiNrOfRows;
    pParam->uiSpecialParInfo = 0u;/*PRQA S 2982 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
    fDefaultValue = MINMAX_FLOAT( (float32) -HEADPARFCT_FLOAT_MAX, (float32) HEADPARFCT_FLOAT_MAX, fDefaultValue);
    pParam->f16DefaultValue = HEADConvf32Tof16(fDefaultValue);
    pParam->uiSpecialParInfo = bitPack;
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADCalculatePolygonValuef32                                                                 */ /*!

  @brief                Calculates the value of a polygon at a specific position

  @description          The polygon is specified by the sampling points (X[i];Y[i])
                        The X-position is given by fXPosition
                        The function returns the Y-Value at the given X-Position

                        @startuml
                        Start
                            If(check for input value is less than or equal 
                            to the first table value) then (Yes)
                            : Return the smallest sampling point y-value;
                            Elseif(check for input value is greater than or equal 
                            to the last row table value) then (Yes)
                            : Return the biggest sampling point y-value;
                            Else (No)
                            While(check for input value is less than the row table value) is (Yes)
                            :increment next row position;
                            Endwhile(No)
                            :Fetech the calculated value;
                            If(Is the calculated value non zero?) then (Yes)
                            :find the difference range from input value;
                            Else (No)
                            :update defult value;
                            Endif
                            : Update the interpolated value depends on input value;
                            Endif
                            :return the updated value;
                        stop
                        @enduml

  @return               float32 : The y-value at the specified x-position

  @param[in]            uiNrOfTableRows  : Get the table rows
  @param[in]            pTable           : Store the table values
  @param[in]            fInputValue      : Store the interpolation input value

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  pTable, must be in memory
                        The x-positions sampling points must be strictly increasing
                        The arrays must have the same length
                        The array length must be iNumberOfValues
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
float32 HEADCalculatePolygonValuef32(uint8 uiNrOfTableRows, const float32 pTable[], float32 fInputValue)
{
  /*get table value*/
  sint32 iRight; /* The index of the nearest sampling point to the right */
  float32 fResult;
  float32 fWeightRight;
  
  fResult = 0.0f;/*PRQA S 2982 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
  iRight  = 0;

  /* If the x-position is left of the smallest sampling point,return the smallest sampling point y-value */
  if (fInputValue <= pTable[0])
  {
    fResult = pTable[1];
  }
  /* If the x-position is right of the biggest sampling point,return the biggest sampling point y-value */
  else if (fInputValue >= pTable[2u*(uiNrOfTableRows-1u)])
  {
    fResult = pTable[(2u*uiNrOfTableRows)-1u];
  }
  /* In all other cases return the interpolated value between the matching sampling points */
  else
  {
    float32 fdx;
    while (pTable[iRight] < fInputValue)/*PRQA S 3350 #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because of Generic implementation*/
    {
      iRight = iRight + 2;
    }
    fdx = pTable[iRight] - pTable[iRight - 2];
    
    if (F32_IS_NZERO(fdx))
    {
      fWeightRight = (fInputValue - pTable[iRight - 2]) / (fdx);
    }
    else
    {
      fWeightRight = 0.0f;
    }
    
    fResult =   ((pTable[iRight - 1]) *  (1.0f-fWeightRight))
              + ((pTable[iRight + 1]) * fWeightRight);
  }
  return fResult;
}

/*PRQA S 1505 1*//*HEADCalculatePolygonValuef16 belongs to common function catalog*/
/*************************************************************************************************************************
  Functionname:         HEADCalculatePolygonValuef16                                                                 */ /*!

  @brief                Calculates the value of a polygon at a specific position

  @description          The polygon is specified by the sampling points (X[i];Y[i])
                        The X-position is given by fXPosition
                        The function returns the Y-Value at the given X-Position

                        @startuml
                        Start
                            If(check for input value is less than or equal
                            to the first table value) then (Yes)
                            : Return the smallest sampling point y-value;
                            Note left
                            This function interpret y-value corresponding to x-value.
                            Internaly Convert 16-bit float to 32-bit float and 
                            perform the calculation and retun 32-bit float value.
                            End note
                            Elseif(check for input value is greater than or equal
                            to the last row table value) then (Yes)
                            : Return the biggest sampling point y-value;
                            Else (No)
                            While(check for input value is less than the row table value) is (Yes)
                            :increment next row position;
                            Endwhile(No)
                            :Fetech the calculated value;
                            If(Is the calculated value non zero?) then (Yes)
                            :find the difference range from input value;
                            Else (No)
                            :update defult value;
                            Endif
                            : Update the interpolated value depends on input value;
                            Endif
                            :return the updated value;
                        stop
                        @enduml

  @return               float32 : interpolated value

  @param[in]            uiNrOfTableRows  : Get the number of table rows
  @param[in]            pTable           : Store the table values
  @param[in]            fInputValue      : Store the interpolation input value

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  pTable, must be in memory
                        The x-positions sampling points must be strictly increasing
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
float32 HEADCalculatePolygonValuef16(uint8 uiNrOfTableRows, const f16_t pTable[], float32 fInputValue)
{
  /*get table value*/
  sint32 iRight; /* The index of the nearest sampling point to the right */
  float32 fResult;
  float32 fWeightRight;
  
  fResult = 0.0f;/*PRQA S 2982 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
  iRight = 0;

  /* If the x-position is left of the smallest sampling point,return the smallest sampling point y-value */
  if (fInputValue <= HEADConvf16Tof32(pTable[0]))
  {
    fResult = HEADConvf16Tof32(pTable[1]);
  }
  /* If the x-position is right of the biggest sampling point,return the biggest sampling point y-value */
  else if (fInputValue >= HEADConvf16Tof32(pTable[2u*(uiNrOfTableRows-1u)]))
  {
    fResult = HEADConvf16Tof32(pTable[(2u*uiNrOfTableRows)-1u]);
  }
  /* In all other cases return the interpolated value between the matching sampling points */
  else
  {
    float32 fdx;
    float32 fTableValue = HEADConvf16Tof32(pTable[iRight]);
    while (fTableValue < fInputValue)/*PRQA S 3350 #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because of Generic implementation*/
    {
      iRight = iRight + 2;
      fTableValue = HEADConvf16Tof32(pTable[iRight]);
    }
    fdx = HEADConvf16Tof32(pTable[iRight]);
    fdx -= HEADConvf16Tof32(pTable[iRight - 2]);
    
    if (F32_IS_NZERO(fdx))    
    {
      fWeightRight = (fInputValue - HEADConvf16Tof32(pTable[iRight - 2])) / (fdx);
    }
    else
    {
      fWeightRight = 0.0f;
    }

    fResult =   ((HEADConvf16Tof32(pTable[iRight - 1])) *  (1.0f-fWeightRight));
    fResult += ((HEADConvf16Tof32(pTable[iRight + 1])) * fWeightRight);
  }
  return fResult;
}

/*************************************************************************************************************************
  Functionname:         HEADGetTableParam                                                                            */ /*!

  @brief                Returns a value out of a table parameter using the correct input

  @description          Returns a value out of a table parameter using the correct input
  
                        @startuml
                        Start
                            If(NULL pointer check) then (yes)
                            : update return type as null pointer error;
                            Else
                            : Get Parameter table type;
                            Note right
                            Host Speed, Host Acceleration, Driver activity,
                            Driver feedback and Driver attention, these head module parameter type are checked
                            End note
                            if(check signal quality type is default value, bad quality 
                            and suspicious signal state ) then (No)
                            Note right
                            Host Speed, Host Acceleration, Driver activity,
                            Driver feedback and Driver attention corresponding 
                            parameter signal state are checked
                            End note
                            : update return type as low quality signal;
                            elseIf(check Parameter table type is host
                             speed last state transition) then (Yes)
                            If (Is Host speed last state transition false?) then (Yes)
                            : update return type as low quality signal;
                            Endif
                            elseIf(check for parameter table type is Closing Velocity similarly 
                            check relative velocity And Distance parameter types are checked)
                            : update return type as low quality signal;
                            elseIf(check DEPENDENT Parameter table type) then (Yes)
                            : update hypothesis internal variable error type;
                            Else if(check INDEPENDENT Parameter table type ) then (Yes)
                            : update independent parameter error type;
                            else 
                            :update unknown error type; 
                            Endif
                            If(check local error is no error  ) then (Yes)
                            :update Input Value is true;
                            Else if (check local error is low quality signal) then (Yes)
                            :update Input Value is true;
                            Else
                            :update Input Value is false;
                            endif
                            if (check Input Value valid  is true) then (Yes)
                            if (check type of the Table values is FloatType_16) then (Yes)
                            : corresponding Calculate Polygon Value are updated;
                            Else
                            : Corresponding Calculated 32 type Polygon Value are updated;
                            Endif
                            Endif
                            Endif
                            :return the updated error;
                        stop
                        @enduml

  @return               eGDBError_t      :GDB error type is returned

  @param[in]            pParamTable      : Pointer to parameter definition for table values
  @param[in]            pInputData       : Pointer to input data
  @param[in]            pHyp             : Pointer to the hypothesis
  @param[in]            uiModuleNr       : Its count the module number 
  @param[in,out]        pOutValue        : Pointer to output value
  @param[in]            pAddTableInputs  : Pointer to additional table input values
    
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 

  @pre                  pParamTable, pInputData and pOutValue must be in memory
  @post                 None

  
  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision

  @author                Robert Thiel | robert.thiel@contiautomotive.com
*************************************************************************************************************************/
static eGDBError_t HEADGetTableParam(const HEADParameterTable_t *pParamTable, const struct HEADInputData_t *pInputData, 
                                     const HEADHypothesis_t *pHyp, uint8 uiModuleNr, float32 *pOutValue, 
                                     const HEADAdditionalTableInputValues_t* pAddTableInputs)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  if ((pParamTable == NULL) || (pOutValue == NULL) || (pParamTable->pTable == NULL) || (pInputData == NULL))
  {
    locError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    float32 fInputValue      = 0.0f;
    sint32 siInputValue      = 0;
    boolean bInputValueValid = b_FALSE;
    /*get input value for the table*/
    switch(pParamTable->TableType)
    {      
      case HEADParamTableType_HostSpeed:
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &fInputValue);
        if( (pInputData->pInputValueList->LongVelocity.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->LongVelocity.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->LongVelocity.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
        break;
      case HEADParamTableType_HostAccel:
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->LongAcceleration, HEAD_DEFAULT_LongAccel, &fInputValue);
        if( (pInputData->pInputValueList->LongAcceleration.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->LongAcceleration.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->LongAcceleration.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
        break;
      case HEADParamTableType_DriverActivity:
        locError = HEADGetInputValue_sint32(pInputData->pInputValueList->DriverActivity, HEAD_DEFAULT_DriverActivityProb, &siInputValue);
        fInputValue = (float32) siInputValue;
        if( (pInputData->pInputValueList->DriverActivity.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->DriverActivity.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->DriverActivity.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
        break;
      case HEADParamTableType_DriverFeedback:
        locError = HEADGetInputValue_sint32(pInputData->pInputValueList->DriverFeedback, HEAD_DEFAULT_DriverFeedbackProb, &siInputValue);
        fInputValue = (float32) siInputValue;
        if( (pInputData->pInputValueList->DriverFeedback.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->DriverFeedback.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->DriverFeedback.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
        break;
      case HEADParamTableType_DriverAttention:
        locError = HEADGetInputValue_sint32(pInputData->pInputValueList->DriverAttention, HEAD_DEFAULT_DriverAttentionProb, &siInputValue);
        fInputValue = (float32) siInputValue;
        if( (pInputData->pInputValueList->DriverAttention.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->DriverAttention.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->DriverAttention.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
        break;
      case HEADParamTableType_Distance:
        locError  = HEADGetValueFromHyp(b_TRUE, pInputData,  pHyp, HEADHypOutType_ObjectDist, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_DistanceLat:
        locError  = HEADGetValueFromHyp(b_TRUE, pInputData,  pHyp, HEADHypOutType_ObjectDistLat, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_HostSpeedLastStateTrans:
        fInputValue = pAddTableInputs->fHostSpeedLastStateTransition;
        if(pAddTableInputs->bHostSpeedLastStateTransitionOK == b_FALSE)
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
        break;
      case HEADParamTableType_ClosingVelocity:
        locError = HEADGetValueFromHyp(b_TRUE, pInputData,  pHyp, HEADHypOutType_ClosingVel, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_VRelX:
        locError = HEADGetValueFromHyp(b_TRUE, pInputData,  pHyp, HEADHypOutType_VRelX, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_00_HypDependent:
        locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, HEADHypOutType_CustomPar_00, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_01_HypDependent:
        locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, HEADHypOutType_CustomPar_01, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_02_HypDependent:
        locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, HEADHypOutType_CustomPar_02, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_03_HypDependent:
        locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, HEADHypOutType_CustomPar_03, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_04_HypDependent:
        locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, HEADHypOutType_CustomPar_04, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_05_HypDependent:
        locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, HEADHypOutType_CustomPar_05, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_06_HypDependent:
        locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, HEADHypOutType_CustomPar_06, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_07_HypDependent:
        locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, HEADHypOutType_CustomPar_07, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_08_HypDependent:
        locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, HEADHypOutType_CustomPar_08, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_00_HypIndependent:
        locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_00_HypIndependent, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_01_HypIndependent:
        locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_01_HypIndependent, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_02_HypIndependent:
        locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_02_HypIndependent, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_03_HypIndependent:
        locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_03_HypIndependent, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_04_HypIndependent:
        locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_04_HypIndependent, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_05_HypIndependent:
        locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_05_HypIndependent, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_06_HypIndependent:
        locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_06_HypIndependent, uiModuleNr, &fInputValue);
        break;
      case HEADParamTableType_CustomPar_07_HypIndependent:
        locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_07_HypIndependent, uiModuleNr, &fInputValue);
        break;
	  case HEADParamTableType_CustomPar_08_HypIndependent:
		  locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_08_HypIndependent, uiModuleNr, &fInputValue);
		  break;
	  case HEADParamTableType_CustomPar_09_HypIndependent:
		  locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_09_HypIndependent, uiModuleNr, &fInputValue);
		  break;
      default:
        locError = GDB_ERROR_UNKNOWN_TYPE;
        break;
    }

    if(locError == GDB_ERROR_NONE)
    {
      bInputValueValid = b_TRUE;
    }
    else if(locError == GDB_ERROR_LOW_QUALITY)
    {
      fInputValue = HEADConvf16Tof32(pParamTable->f16DefaultValue);
      bInputValueValid = b_TRUE;
    }
    else 
    {
      bInputValueValid = b_FALSE;
    }

    if(bInputValueValid == b_TRUE)
    {
      if(pParamTable->eTableFloatType == HEADParameterTableFloatType_f16)
      {
        *pOutValue = HEADCalculatePolygonValuef16(pParamTable->uiNrOfTableRows, (const f16_t *)(pParamTable->pTable), fInputValue);
      }
      else
      {
        *pOutValue = HEADCalculatePolygonValuef32(pParamTable->uiNrOfTableRows, (const float32 *)(pParamTable->pTable), fInputValue);
      }
    }
  }
  return locError;
}/* PRQA S 7004, 7002 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability */

/*************************************************************************************************************************
  Functionname:         HEADGetParam                                                                                */ /*!

  @brief                returns a value out of a parameter

  @description          returns a value out of a parameter if the conditions (mode, hypothesis) are met.
                        depends on the parameter main mode a scalar or table values are returned.

                        @startuml
                        Start
                            If(Is the parameter and out value equal to null?) then (Yes)
                            : Update return type as null pointer error;
                            Else
                            If(check for either parameter mode is early 
                            type or parameter mode & with parameter 
                            mode bit greater than zero) then (Yes)
                            :get parameter main type;
                            If(Is the parameter main type scalar?) then (Yes)
                            : Parameter scalar value updated to the output value;
                            elseif(Is the parameter main type is value ?) then (Yes)
                            : Parameter table value updated to 
                            the return  variable;
                            Else 
                            :enum unknown handling type updated 
                            to the return variable;
                            Endif
                            Else
                            : Filter function doesn't match 
                            any result is updated in the return value ;
                            Endif
                            Endif
                            : Return the updated return value;
                        stop
                        @enduml

  @return               eGDBError_t      :GDB error type is returned

  @param[in]            pParam           : Pointer to Parameter Empty Structure
  @param[in]            pInputData       : Pointer to input data
  @param[in]            pHyp             : Pointer to the hypothesis
  @param[in]            uiModuleNr       : Its count the module number 
  @param[in,out]        pOutValue        : Pointer to output value
  @param[in]            pAddTableInputs  : Pointer to additional table input values

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  pParam, pInputData and pOutValue must be in memory
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADGetParam(const HEADParameterEmpty_t *pParam, const struct HEADInputData_t *pInputData, 
                         const HEADHypothesis_t *pHyp, uint8 uiModuleNr, float32 *pOutValue, 
                         const HEADAdditionalTableInputValues_t* pAddTableInputs)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pParam == NULL) || (pOutValue == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    /*check if parameter is used in this mode*/
    if (
        /*either parametermode independend*/
       (pParam->ParameterType.sParameterType.ParameterMode == 0)
       ||
        /*paramtermode (early-middle-late-ACC) is used in this mode*/
       (((uint32)(pParam->ParameterType.sParameterType.ParameterMode) & (uint32)HEADParameterModeBit(pInputData->eHEADMainMode)) > 0u)/*PRQA S 4391, 4399 #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because there is no impact on software*/
       )
    {
      switch(pParam->ParameterType.sParameterType.ParamMainType)
      {
        case (HEADParamMainType_t)HEADParamMainType_Scalar:
          *pOutValue = HEADConvf16Tof32(((const HEADParameterScalar_t *)((const void *)pParam))->f16RawValue);/*PRQA S 0314 3 #date: 2020-06-02, reviewer: Nalina M, reason: Generic Implementation */
          break;
        case (HEADParamMainType_t)HEADParamMainType_Table:
          retValue = HEADGetTableParam((const HEADParameterTable_t *)((const void *)pParam), pInputData, pHyp, uiModuleNr, pOutValue, pAddTableInputs);
          break;         
        default: 
          retValue = GDB_ERROR_UNKNOWN_TYPE;
          *pOutValue = 0.0f;
          break;   
      }       
    }      
    else
    {
      /*parameter not for this mode*/
      retValue = GDB_ERROR_FILTER_DOESNT_MATCH;
      *pOutValue = 0.0f;
    }    
  }                          
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADParamOutTypeToHypOutType                                                                */ /*!

  @brief                returns the hypothesis out type from a param out type

  @description          returns the hypothesis out type from a param out type  

                        @startuml
                        Start
                            :Find Hypothesis out type \nfor Parameter out type;
                            Note right:Returns the hypothesis out type correspond \nto parameter out type
                        stop
                        @enduml
          
  @return               eGDBError_t    :GDB error type is returned

  @param[in]            eParamOutType  : Hypothesis output type of the parameter
  @param[in,out]        peHypOutType   : Pointer to hypothesis output variable type

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
eGDBError_t HEADParamOutTypeToHypOutType(eHEADParamOutType_t eParamOutType, eHEADHypOutType_t *peHypOutType)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if(peHypOutType == NULL)
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    switch(eParamOutType)
    {
      /* general parameters */
      case HEADParamOutType_TTC: 
        *peHypOutType = HEADHypOutType_TTC;
        break;
      case HEADParamOutType_TTB_PRE:
        *peHypOutType = HEADHypOutType_TTB_PRE;
        break;
      case HEADParamOutType_TTB_ACUTE:
        *peHypOutType = HEADHypOutType_TTB_ACUTE;
        break;
      case HEADParamOutType_TTS_PRE:
        *peHypOutType = HEADHypOutType_TTS_PRE;
        break;
      case HEADParamOutType_TTS_ACUTE:
        *peHypOutType = HEADHypOutType_TTS_ACUTE;
        break;
      case HEADParamOutType_ClosingVel:
        *peHypOutType = HEADHypOutType_ClosingVel;
        break;
      case HEADParamOutType_ANecLong:
        *peHypOutType = HEADHypOutType_ANecLong;
        break;
      case HEADParamOutType_HypProb:
        *peHypOutType = HEADHypOutType_HypProb;
        break;
      case HEADParamOutType_ObjectDist: 
        *peHypOutType = HEADHypOutType_ObjectDist;
        break;
      case HEADParamOutType_ObjectDistLat: 
        *peHypOutType = HEADHypOutType_ObjectDistLat;
		    break;
      case HEADParamOutType_ObjProb:
        *peHypOutType = HEADHypOutType_ObjProb;
        break;
      case HEADParamOutType_TTC2:
        *peHypOutType = HEADHypOutType_TTC2;
        break;
      case HEADParamOutType_TTC3:
        *peHypOutType = HEADHypOutType_TTC3;
        break;
      case HEADParamOutType_TTC4:
        *peHypOutType = HEADHypOutType_TTC4;
        break;
      case HEADParamOutType_HypLifetime:
        *peHypOutType = HEADHypOutType_HypLifetime;
        break;
      case HEADParamOutType_ANecLatAbs:
        *peHypOutType = HEADHypOutType_ANecLatAbs;
        break;
      case HEADParamOutType_VRelX:
        *peHypOutType = HEADHypOutType_VRelX;
        break;
      case HEADParamOutType_TTMLongPre:
        *peHypOutType = HEADHypOutType_TTMLongPre;
        break;
      case HEADParamOutType_TTMLongAcute:
        *peHypOutType = HEADHypOutType_TTMLongAcute;
        break;
      case HEADParamOutType_SensorSource:
        *peHypOutType = HEADHypOutType_SensorSource;
        break;
      /* application specific parameters */
      case HEADParamOutType_CustomPar_00_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_00;
        break;
      case HEADParamOutType_CustomPar_01_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_01;
        break;
      case HEADParamOutType_CustomPar_02_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_02;
        break;
      case HEADParamOutType_CustomPar_03_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_03;
        break;
      case HEADParamOutType_CustomPar_04_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_04;
        break;
      case HEADParamOutType_CustomPar_05_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_05;
        break;
      case HEADParamOutType_CustomPar_06_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_06;
        break;
      case HEADParamOutType_CustomPar_07_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_07;
        break;
        case HEADParamOutType_CustomPar_08_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_08;
        break;
      #if HEAD_CFG_TURN_ASSIST
      case HEADParamOutType_CorridorStopDistance:
        *peHypOutType = HEADHypOutType_CorridorStopDistance;
        break;
      #endif
      #if HEAD_CFG_CORRIDOROCCUPANCY
      case HEADParamOutType_CorridorOccupancy:
        *peHypOutType = HEADHypOutType_CorridorOccupancy;
        break;
      #endif
	  case HEADParamOutType_ObjMoveDir:
		  *peHypOutType = HEADHypOutType_ObjMovDir;
		  break;
      /*These cases must never be touched as they are not hypothesis based */
      case HEADParamOutType_AllConditionsForOrGroupMet:
      case HEADParamOutType_OtherOrGroupIsTrue:
      case HEADParamOutType_StateActiveTime:
      case HEADParamOutType_OtherModuleStateTime:
      case HEADParamOutType_EgoVelocity:
      case HEADParamOutType_EgoAccel:
      case HEADParamOutType_SafeObjDistSfty:
      case HEADParamOutType_SafeObjDistPerf:
      case HEADParamOutType_EgoLatCurvature:
      case HEADParamOutType_CustomPar_00_HypIndependent:
      case HEADParamOutType_CustomPar_01_HypIndependent:
      case HEADParamOutType_CustomPar_02_HypIndependent:
      case HEADParamOutType_CustomPar_03_HypIndependent:
      case HEADParamOutType_CustomPar_04_HypIndependent:
      case HEADParamOutType_CustomPar_05_HypIndependent:
      case HEADParamOutType_CustomPar_06_HypIndependent:
      case HEADParamOutType_CustomPar_07_HypIndependent:
	  case HEADParamOutType_CustomPar_08_HypIndependent:
	  case HEADParamOutType_CustomPar_09_HypIndependent:
      #if HEAD_CFG_TURN_ASSIST
      case HEADParamOutType_SteeringAngle :
      case HEADParamOutType_TurnIndicatorInSteeringDirection:
      case HEADParamOutType_GasPedal :
      #endif
      case HEADParamOutType_Max:
      default:
        retValue = GDB_ERROR_UNKNOWN_TYPE;
        break;
    }
  }
  return retValue;
} /* PRQA S 7004 *//* date: 2018-10-26, reviewer:Krupa H R, reason:suppressing cyclomatic complexity for better code maintainability */

/*************************************************************************************************************************
  Functionname:         HEADIsCustomParameter                                                                            */ /*!

  @brief                Checks if the parameter is a custom DEPENDENT parameter 

  @description          Checks if the parameter is a custom DEPENDENT parameter 
                        Returns TRUE if the parameter is a custom parameter
  
                        @startuml
                        Start
                            :initialize a return type;
                            If(check relevant output hypothesis type availability) then (yes)
                            If(check hypothesis dependent value or not) then (Yes)
                            : update return value as false;
                            Else if (check parameter is application specific 
                            DEPENDENT Parameter or not) then (yes)
                            : update return value as true;
                            Else
                            : update return value as false;
                            Endif
                            Endif
                            :return the updated return value;
                        stop
                        @enduml

  @return               boolean 

  @param[in]            eHypOutType : Its hypothesis output variable type
  
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
*************************************************************************************************************************/
static boolean HEADIsCustomParameter( eHEADHypOutType_t eHypOutType )
{
  boolean bRetVal = b_FALSE;

  switch(eHypOutType)
  {
    case HEADHypOutType_TTC:
    case HEADHypOutType_TTB_PRE:
    case HEADHypOutType_TTB_ACUTE:
    case HEADHypOutType_TTS_PRE:
    case HEADHypOutType_TTS_ACUTE:
    case HEADHypOutType_ClosingVel:
    case HEADHypOutType_ANecLong:
    case HEADHypOutType_HypProb:
    case HEADHypOutType_ObjectDist:
    case HEADHypOutType_ObjectDistLat:
    case HEADHypOutType_ObjProb:
    case HEADHypOutType_TTC2:
    case HEADHypOutType_TTC3:
    case HEADHypOutType_TTC4:
    case HEADHypOutType_HypLifetime:
    case HEADHypOutType_ANecLatAbs:
    case HEADHypOutType_VRelX:
    case HEADHypOutType_TTMLongPre:
    case HEADHypOutType_TTMLongAcute:
    case HEADHypOutType_SensorSource:
	case HEADHypOutType_ObjMovDir:
    #if HEAD_CFG_CORRIDOROCCUPANCY
    case HEADHypOutType_CorridorOccupancy:
    #endif
      bRetVal = b_FALSE;
      break;
    case HEADHypOutType_CustomPar_00:
    case HEADHypOutType_CustomPar_01:
    case HEADHypOutType_CustomPar_02:
    case HEADHypOutType_CustomPar_03:
    case HEADHypOutType_CustomPar_04:
    case HEADHypOutType_CustomPar_05:
	case HEADHypOutType_CustomPar_06:
	case HEADHypOutType_CustomPar_07:
  case HEADHypOutType_CustomPar_08:
      bRetVal = b_TRUE;
      break;
    default:
      bRetVal = b_FALSE;
      break;
  }
  /* done */
  return bRetVal;
}

/*************************************************************************************************************************
  Functionname:         HEADIsHypDependentParameter                                                                  */ /*!

  @brief                Checks if the parameter is a hyp dependent or independent parameter

  @description          Checks if the parameter is a hyp dependent or independent parameter
                        @startuml
                        Start
                            :Check the Parameter is Hypothesis Dependent \nor independent.;
                            Note right: Returns TRUE if the parameter is hypothesis dependent parameter \nelse return False.
                        stop
                        @enduml
          
  @return               eGDBError_t     :GDB error type is returned

  @param[in]            eOutType   : Hypothesis output type of the parameter
  @param[in,out]        bRetValue  : Returns TRUE if the parameter is a hyp dependent parameter

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
eGDBError_t HEADIsHypDependentParameter( eHEADParamOutType_t eOutType, boolean* bRetValue )
{
  eGDBError_t locError = GDB_ERROR_NONE;
  *bRetValue = b_FALSE;
  switch(eOutType)
  {
    case HEADParamOutType_TTC                    :
    case HEADParamOutType_TTB_PRE                :
    case HEADParamOutType_TTB_ACUTE              :
    case HEADParamOutType_TTS_PRE                :
    case HEADParamOutType_TTS_ACUTE              :
    case HEADParamOutType_ClosingVel             :
    case HEADParamOutType_ANecLong               :
    case HEADParamOutType_HypProb                :
    case HEADParamOutType_ObjectDist             :
    case HEADParamOutType_ObjectDistLat          :
    case HEADParamOutType_ObjProb                :
    case HEADParamOutType_TTC2                   :
    case HEADParamOutType_TTC3                   :
    case HEADParamOutType_TTC4                   :
    case HEADParamOutType_HypLifetime            :
    case HEADParamOutType_ANecLatAbs             :
    case HEADParamOutType_VRelX                  :
    case HEADParamOutType_TTMLongPre             :
    case HEADParamOutType_TTMLongAcute           :
    case HEADParamOutType_SensorSource           :
    case HEADParamOutType_CustomPar_00_HypDependent :
    case HEADParamOutType_CustomPar_01_HypDependent :
    case HEADParamOutType_CustomPar_02_HypDependent :
    case HEADParamOutType_CustomPar_03_HypDependent :
    case HEADParamOutType_CustomPar_04_HypDependent :
    case HEADParamOutType_CustomPar_05_HypDependent :
    case HEADParamOutType_CustomPar_06_HypDependent :
    case HEADParamOutType_CustomPar_07_HypDependent :
    case HEADParamOutType_CustomPar_08_HypDependent :
	case HEADParamOutType_ObjMoveDir:
    #if HEAD_CFG_TURN_ASSIST
    case HEADParamOutType_CorridorStopDistance:
    #endif
    #if HEAD_CFG_CORRIDOROCCUPANCY
    case HEADParamOutType_CorridorOccupancy:
    #endif
      *bRetValue = b_TRUE;
      break;
    case HEADParamOutType_AllConditionsForOrGroupMet :
    case HEADParamOutType_OtherOrGroupIsTrue         :
    case HEADParamOutType_OrGroupInhibition          :
    case HEADParamOutType_StateActiveTime            :
    case HEADParamOutType_OtherModuleStateTime       :
    case HEADParamOutType_Bool                       :
    case HEADParamOutType_EgoVelocity                :
    case HEADParamOutType_EgoAccel                   :
    case HEADParamOutType_SafeObjDistSfty            :
    case HEADParamOutType_SafeObjDistPerf            :
    case HEADParamOutType_DriverFeedbackProb         :
    case HEADParamOutType_DriverActivityProb         :
    case HEADParamOutType_DriverAttentionProb        :
    case HEADParamOutType_EgoLatCurvature            :
    case HEADParamOutType_CustomPar_00_HypIndependent   :
    case HEADParamOutType_CustomPar_01_HypIndependent   :
    case HEADParamOutType_CustomPar_02_HypIndependent   :
    case HEADParamOutType_CustomPar_03_HypIndependent   :
    case HEADParamOutType_CustomPar_04_HypIndependent   :
    case HEADParamOutType_CustomPar_05_HypIndependent   :
    case HEADParamOutType_CustomPar_06_HypIndependent   :
    case HEADParamOutType_CustomPar_07_HypIndependent   :
	case HEADParamOutType_CustomPar_08_HypIndependent   :
	case HEADParamOutType_CustomPar_09_HypIndependent   :
    #if HEAD_CFG_TURN_ASSIST
    case HEADParamOutType_SteeringAngle                   :
    case HEADParamOutType_TurnIndicatorInSteeringDirection:
    case HEADParamOutType_GasPedal                        :
    #endif
      *bRetValue = b_FALSE;
      break;
    default:
      *bRetValue = b_FALSE;
      locError = GDB_ERROR_UNKNOWN_TYPE;
      break;
  }
  return locError;
}

/*************************************************************************************************************************
  Functionname:         HEADGetHypValue                                                                             */ /*!

  @brief                returns the value of a hypothesis

  @description          returns the value of a parameter out type out of a hypothesis 
                        @startuml
                        Start
                            If(Null check for input parameter) then (True)
                            If(Is custom parameter return type is true?) then (Yes)
                            If(Null check for call back function) then (True)
                            : Fetch dependent custom parameters;
                            Else
                            : Local flag was disabled;
                            Endif
                            Else
                            If(Is it Hypothesis output type?) then (Yes)
                            :Update corresponding value to the return variable; 
                            Elseif(Is it application-specific parameters?) then (Yes)
                            : Local flag was disabled;
                            Else
                            : Local flag was disabled;
                            Endif
                            Endif
                            If(Is the local flag enabled?)then (Yes)
                            If(Null check for filtering custom parameters) then (True)
                            : perform application specific filtering of value;
                            Endif
                            Endif
                            Else
                            : Null pointer error was updated;
                            Endif
                            :Return the updated error type;
                        Stop 
                        @enduml

  @return               eGDBError_t     :GDB error type is returned

  @param[in]            pInputData   : Pointer to input data
  @param[in]            pHyp         : Pointer to the hypothesis
  @param[in]            eHypOutType  : Its defines a hypothesis output variable type
  @param[in]            uiModuleNr   : Its count the module number 
  @param[in,out]        bFound       : Find the the status of the flag
  @param[in,out]        retValue     : Update the hypothesis output value

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref HEAD_USE_TTM_LONG
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADGetHypValue(const HEADInputData_t *pInputData, 
                            const HEADHypothesis_t *pHyp, 
                            eHEADHypOutType_t eHypOutType, 
                            uint8 uiModuleNr, 
                            boolean * bFound,
                            float32 *retValue)
{
  eGDBError_t retError = GDB_ERROR_NONE;

  if ( (pHyp != NULL) && (pInputData != NULL) && (pHyp->pHypothesis != NULL) && (retValue != NULL ) && (bFound != NULL ))
  {
    *bFound = b_FALSE;
    *retValue = 0.0f;
    /* if custom parameter call the application specific callback */
    if( HEADIsCustomParameter( eHypOutType ) != b_FALSE )
    {
      if( pInputData->CustCallbacks.fpCustomGetHypValue != NULL )
      {
        retError = pInputData->CustCallbacks.fpCustomGetHypValue( pInputData, pHyp, eHypOutType, retValue );
        if( retError == GDB_ERROR_NONE )
        {
          *bFound = b_TRUE;
        }
      }
      else
      {
        /* This is not an error but allowed behavior */
        *bFound = b_FALSE;
      }
    }
    /* hyp dependent parameter (not custom)*/
    else
    {
      const Hypothesis_t *pKinHyp = pHyp->pHypothesis;
      *bFound = b_TRUE;
      switch(eHypOutType)
      {
        case HEADHypOutType_TTC: 
          *retValue = pKinHyp->fTTC;
          break;
        case HEADHypOutType_TTB_PRE:
          *retValue = pKinHyp->fTTBPre;
          break;
        case HEADHypOutType_TTB_ACUTE:
          *retValue = pKinHyp->fTTBAcute;
          break;
        case HEADHypOutType_TTS_PRE:
          *retValue = pKinHyp->fTTSPre;
          break;
        case HEADHypOutType_TTS_ACUTE:
          *retValue = pKinHyp->fTTSAcute;
          break;
        case HEADHypOutType_ClosingVel:
          *retValue = pKinHyp->fClosingVelocity;
          break;
        case HEADHypOutType_ANecLong:
          *retValue = pKinHyp->fLongNecAccel;
          break;
        case HEADHypOutType_HypProb:
          *retValue = (float32) pKinHyp->uiHypothesisProbability;
          break;
        case HEADHypOutType_ObjectDist:
          *retValue = pKinHyp->fDistX;
          break;
        case HEADHypOutType_ObjectDistLat:
          *retValue = pKinHyp->fDistY;
          break;
        case HEADHypOutType_ObjProb:
          *retValue = (float32) pKinHyp->uiObjectProbability;
          break;
        case HEADHypOutType_TTC2:
          *retValue = pKinHyp->fTTC2;
          break;
        case HEADHypOutType_TTC3:
          *retValue = pKinHyp->fTTC3;
          break;
        case HEADHypOutType_TTC4:
          *retValue = pKinHyp->fTTC4;
          break;
        case HEADHypOutType_HypLifetime:
          *retValue = pKinHyp->fHypothesisLifetime;
          break;
        case HEADHypOutType_ANecLatAbs:
          *retValue = fABS(pKinHyp->fLatNecAccel);
          break;
        case HEADHypOutType_VRelX:
          *retValue = pKinHyp->fVrelX;
          break;
        #if HEAD_CFG_CORRIDOROCCUPANCY
        case HEADHypOutType_CorridorOccupancy:
          *retValue = pKinHyp->fCorridorOccupancy;
          break;
        #endif
		case HEADHypOutType_ObjMovDir:
			*retValue = pKinHyp->eEBAObjMovDir;
			break;
        #if defined(HEAD_USE_TTM_LONG) && (HEAD_USE_TTM_LONG == MEDIC_ON) 
        /* Use TTM LONG - this config switch is doubled from CD! */
        case HEADHypOutType_TTMLongPre:
          *retValue = pKinHyp->fTTMLongPre;
          break;
        case HEADHypOutType_TTMLongAcute:
          *retValue = pKinHyp->fTTMLongAcute;
          break;
        #endif
        #if HEAD_CFG_TURN_ASSIST
        case HEADHypOutType_CorridorStopDistance:
          *retValue = pKinHyp->fCorridorStopDistance;
          break;
        #endif
        /*driver hyp or other*/
        case HEADHypOutType_SensorSource:
        case HEADHypOutType_CustomPar_00:
        case HEADHypOutType_CustomPar_01:
        case HEADHypOutType_CustomPar_02:
        case HEADHypOutType_CustomPar_03:
        case HEADHypOutType_CustomPar_04:
        case HEADHypOutType_Max: 
        default:
          *bFound = b_FALSE;
          break;
      }
    }
    // parameter type not found here
    if((*bFound) != b_FALSE)
    {
      // perform application specific filtering of value
      if( pInputData->CustCallbacks.fpCustomFilterHypValue != NULL )
      {
        retError = pInputData->CustCallbacks.fpCustomFilterHypValue( pInputData, pHyp, eHypOutType, uiModuleNr, retValue );
      }
      else
      {
        // This is not an error but allowed behavior
      }
    }
  }
  else
  {
    retError = GDB_ERROR_POINTER_NULL;
  }
  return retError;
}/* PRQA S 7004 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability*/


/*************************************************************************************************************************
  Functionname:         HEADGetValueFromHyp                                                                              */ /*!

  @brief                returns value of a hypothesis internal variable

  @description          update the value of a hypothesis and returns value of a hypothesis.
  
                        @startuml
                        Start
                            :initialize local variable;
                            If(Null check for input data and hypothesis) then (Yes) 
                            : update null pointer error;
                            Else
                            : get Hypothesis Value;
                            If (Is found value true?) then (Yes)
                            : update the hypothesis value;
                            Else 
                            If (check other hypotheses is false) then (Yes)
                            while (check all hypothesis, local error type is no error and check found value is false ) is (Yes)
                            : get current Hypothesis and Hypothesis Value;
                            If (Is found value true?) then (Yes)
                            : update the hypothesis value;
                            endif
                            endwhile (false)
                            if(check local error type is no error) then (Yes)
                            :update found value as false;
                            endif
                            endif
                            endif
                            If (Is found value true?) then (No)
                            : update filter function doesn't match ; 
                            Endif
                            Endif
                            :return updated value;
                        stop
                        @enduml

  @return               eGDBError_t    :GDB error type is returned

  @param[in]            bCheckOnlyPHyp : Depends on these boolean Hypothesis will be evaluated or checked    
  @param[in]            pInputData     : Pointer to input data
  @param[in]            pHyp           : Pointer to the hypothesis
  @param[in]            eHypOutType    : Its defines a hypothesis output variable type
  @param[in]            uiModuleNr     : Its count the module number 
  @param[in,out]        fVal           : Pointer to float value
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 

  @pre                  if bCheckOnlyPHyp == True, only the pHyp will be evaluated, 
                        otherwise all hyps will be checked
  @post                 None
  
  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision

  @todo                 Rework this function
                        if(locError != GDB_ERROR_NONE) : Do Error Case handling
                        if(bFound == FALSE) : Change this to consistent behavior

  @author               Robert Thiel | robert.thiel@contiautomotive.com
*************************************************************************************************************************/
static eGDBError_t HEADGetValueFromHyp( boolean bCheckOnlyPHyp, const HEADInputData_t *pInputData, 
                                const HEADHypothesis_t *pHyp, eHEADHypOutType_t eHypOutType, 
                                uint8 uiModuleNr, float32 *fVal)
{

  eGDBError_t retValue = GDB_ERROR_NONE;
  boolean bFound = b_FALSE;
  float32 fOutVal;
  
  if ((pHyp == NULL) || (pInputData == NULL))  /* Currently valid (non-zero) pInputData is expected, however it might 
                                                  be an use in future to support this */
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    eGDBError_t locError = HEADGetHypValue( pInputData, pHyp, eHypOutType, uiModuleNr, &bFound, &fOutVal);
    if(locError != GDB_ERROR_NONE)
    {

    }
    else if (bFound == b_TRUE)
    {
      *fVal = fOutVal;
    }
    else
    {
      /*now check other hypotheses*/
      if(bCheckOnlyPHyp == b_FALSE)
      {
        uint8 uiI;
        
        /*loop over all hypotheses to find a hypothesis that matches*/
        for(uiI = 0u; (uiI < pInputData->uiNumberOfHEADHypotheses) && (bFound != b_TRUE) && (locError == GDB_ERROR_NONE); uiI++)
        {
          const HEADHypothesis_t *pCurrHyp = HEADGetHypothesis(pInputData->rgHypothesisList, uiI);
          locError = HEADGetHypValue( pInputData, pCurrHyp, eHypOutType, uiModuleNr, &bFound, &fOutVal);
          if(bFound == b_TRUE)
          {
            *fVal = fOutVal;
          }
        }
        if (locError != GDB_ERROR_NONE)
        {
          /* left loop due to an error */
          bFound = b_FALSE;
        }
      }
    }

    if(bFound == b_FALSE)
    {
      retValue = GDB_ERROR_FILTER_DOESNT_MATCH;
    }
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADGSMGetIndValue                                                                          */ /*!

  @brief                returns the value for the independent parameter

  @description          returns the value for the independent parameter
                        and sets an error if eOutType isn't defined.
                        @startuml
                        Start
                        :Set LocalError as None;
                        #orange:Get Module information
                        <b>HEADGetModule</b> >
                        Note
                        Return a Module correspond to Module number 
                        from HEAD Module list.
                        Endnote
                        If (ParamOutType == StateActiveTime) then (yes)
                            If (Module_Current_SM_State < Max_SM_State) then (yes)
                            :Update Param Value with Module Current State 
                            Timer Count;
                            Else (no)
                            :Set ArrayOverFlow Error;
                            Endif
                        Elseif (ParamOutType == (EgoVelocity/ EgoAccel/ SafeObjDistSfty SafeObjDistPerf)) then (yes)
                            #orange:Get Input Value of Type Float32
                            <b>HEADGetInputValue_float32</b> >
                            Note
                            Get Value from Input Value List and Update 
                            It in the Param value.
                            Return Error none if the SignalType is Float 
                            Else return Unknown type error.
                            End note
                            If ((Input Signal Quality != (Ok && BadQuality && Suspicious)) AND
                            LocalError == None)
                            :Set LocalError as Low_Quality Signal Error;
                            Endif
                        Elseif (ParamOutType == EgoLatCurvature) then (yes)
                            #orange:Get Input Value of Type Float32
                            <b>HEADGetInputValue_float32</b> >
                            Note
                            Get Value from Input Value List and Update 
                            It in the Param value.
                            Return Error none if the SignalType is Float 
                            Else return Unknown type error.
                            End note
                            #orange:Get absoulute Value
                            <b>fABS</b> >
                            Note:Curvature value can be negative also. So take the absoulute value
                        Elseif (ParamOutType == (DriverFeedbackProb/ DriverActivityProb/ DriverAttentionProb)) then (yes)
                            #orange:Get Input Value of Type sint32
                            <b>HEADGetInputValue_sint32</b> >
                            Note
                            Get Value from Input Value List and Update 
                            It in the Param value.
                            Return Error none if the SignalType is Singed int 
                            Else return Unknown type error.
                            End note
                            :Typedef Signed int Param to float type; 
                            If ((Input Signal Quality != (Ok && BadQuality && Suspicious)) AND
                            LocalError == None)
                            :Set LocalError as Low_Quality Signal Error;
                            Endif
                        Elseif (ParamOutType == TURN_ASSIST_Related) then (yes)
                        partition IF_TURN_ASSIST_Enabled {
                            If (ParamOutType == SteeringAngle) then (yes)
                                #orange:Get Input Value of Type Float32
                                <b>HEADGetInputValue_float32</b> >
                            
                            elseif (ParamOutType == TurnIndicatorInSteeringDirection) then (yes)
                                #orange:Get Input Value of Type boolean
                                <b>HEADGetInputValue_boolean</b> >
                                :Typedef boolean Param to float type;
                            elseif (ParamOutType == GasPedal) then (yes)
                                #orange:Get Input Value of Type Float32
                                <b>HEADGetInputValue_float32</b> >
                            Endif
                        }
                        Elseif (ParamOutType == HypIndependent) then (yes)
                            #orange:Get Custom Indipendent Value >
                            Note: Call Custom Independent parameter callback function.
                        Else
                            :Set LocalError as Unknown type;
                            :Set Flag correspond to parameter found
                            As false;
                            :set param value as zero;
                        Endif
                        If (Is Parameter Found?) then (yes)
                        If (Is InputData Cutom Filter function Pointer valid?) then (yes)
                        :perform application specific filtering of value;
                        Endif
                        Endif
                        :Return LocalError;
                        Stop 
                        @enduml

  @return               eGDBError_t    : GDB_ERROR_NONE is returned if no error, else return Unknown type error if Signal type
                                         mismatch or Low Quality signal error if the input signal Quality is not ok.

  @param[in]            pInputData     : Pointer to HEAD Input data
  @param[in]            eOutType       : output type of the parameter
  @param[in]            uiModuleNr     : Module number 
  @param[in,out]        pfParamValue   : Pointer to parammeter value

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Andreas Jakob | andreas.jakob-ext@conti-engineering.com
*************************************************************************************************************************/
eGDBError_t HEADGSMGetIndValue( const struct HEADInputData_t *pInputData,
                                const eHEADParamOutType_t eOutType,
                                const uint8 uiModuleNr,
                                float32 *pfParamValue)
{
  HEADModule_t * pModule = NULL;
  sint32 sProb = 0;
  #if HEAD_CFG_TURN_ASSIST
  boolean bValue = FALSE;
  #endif
  eGDBError_t locError = GDB_ERROR_NONE;
  boolean bFound = b_TRUE;

  pModule = HEADGetModule(pInputData->pModuleList, uiModuleNr);

  switch( eOutType )
  {
    case HEADParamOutType_StateActiveTime:
      {
        if (pModule->eSMState < HEADSMState_Max)
        {
          /*PRQA S 3689 1*//*fStateTimer has size HEADSMState_Max*/
          *pfParamValue = pModule->fStateTimer[pModule->eSMState]; 
        }
        else
        {
          locError = GDB_ERROR_ARRAY_OVERFLOW;
        }
      }
      break;
    case HEADParamOutType_EgoVelocity:
      {
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, pfParamValue);
        if( (pInputData->pInputValueList->LongVelocity.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->LongVelocity.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->LongVelocity.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
      }
      break;
    case HEADParamOutType_EgoLatCurvature:
      {
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->EgoLatCurvature, HEAD_DEFAULT_EgoLatCur, pfParamValue);
        /* Curvature value can be negative also. So take the absoulute value */
        *pfParamValue = fABS(*pfParamValue);

        if( (pInputData->pInputValueList->EgoLatCurvature.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->EgoLatCurvature.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->EgoLatCurvature.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
      }
      break;
    case HEADParamOutType_EgoAccel:
      {
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->LongAcceleration, HEAD_DEFAULT_LongAccel, pfParamValue);
        if( (pInputData->pInputValueList->LongAcceleration.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->LongAcceleration.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->LongAcceleration.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
      }
      break;
    case HEADParamOutType_SafeObjDistSfty:
      {
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->SafeObjDistSfty, HEAD_DEFAULT_SafeObjDistance, pfParamValue);
        if( (pInputData->pInputValueList->SafeObjDistSfty.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->SafeObjDistSfty.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->SafeObjDistSfty.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
      }
      break;
    case HEADParamOutType_SafeObjDistPerf:
      {
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->SafeObjDistPerf, HEAD_DEFAULT_PerfObjDistance, pfParamValue);
        if( (pInputData->pInputValueList->SafeObjDistPerf.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->SafeObjDistPerf.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->SafeObjDistPerf.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
      }
      break;
    case HEADParamOutType_DriverFeedbackProb :
      {
        locError = HEADGetInputValue_sint32(pInputData->pInputValueList->DriverFeedback, HEAD_DEFAULT_DriverFeedbackProb, &sProb);
        *pfParamValue = (float32) sProb;
        if( (pInputData->pInputValueList->DriverFeedback.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->DriverFeedback.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->DriverFeedback.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
      }
      break;
    case HEADParamOutType_DriverActivityProb :
      {
        locError = HEADGetInputValue_sint32(pInputData->pInputValueList->DriverActivity, HEAD_DEFAULT_DriverActivityProb, &sProb);
        *pfParamValue = (float32) sProb;
        if( (pInputData->pInputValueList->DriverActivity.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->DriverActivity.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->DriverActivity.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
      }
      break;
    case HEADParamOutType_DriverAttentionProb:
      {
        locError = HEADGetInputValue_sint32(pInputData->pInputValueList->DriverAttention, HEAD_DEFAULT_DriverAttentionProb, &sProb);
        *pfParamValue = (float32) sProb;
        if( (pInputData->pInputValueList->DriverAttention.eSignalQuality != HEADInputSignalState_OK)
          &&(pInputData->pInputValueList->DriverAttention.eSignalQuality != HEADInputSignalState_BadQuality)
          &&(pInputData->pInputValueList->DriverAttention.eSignalQuality != HEADInputSignalState_Suspicious)
          &&(locError == GDB_ERROR_NONE) )
        {
          locError = GDB_ERROR_LOW_QUALITY;
        }
      }
      break;
    #if HEAD_CFG_TURN_ASSIST
    case HEADParamOutType_SteeringAngle:
      {
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->SteeringAngle, HEAD_DEFAULT_SteeringAngle, pfParamValue);
      }
      break;
    case HEADParamOutType_TurnIndicatorInSteeringDirection:
      {
        locError = HEADGetInputValue_boolean(pInputData->pInputValueList->TurnIndicatorInSteeringDirection, HEAD_DEFAULT_TurnIndicatorInSteeringDirection, &bValue);
        *pfParamValue = (float32) bValue;
      }
      break;
    case HEADParamOutType_GasPedal:
      {
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->GasPedal, HEAD_DEFAULT_GasPedal, pfParamValue);
      }
      break;
    #endif
    case HEADParamOutType_CustomPar_00_HypIndependent:
    case HEADParamOutType_CustomPar_01_HypIndependent:
    case HEADParamOutType_CustomPar_02_HypIndependent:
    case HEADParamOutType_CustomPar_03_HypIndependent:
    case HEADParamOutType_CustomPar_04_HypIndependent:
    case HEADParamOutType_CustomPar_05_HypIndependent:
    case HEADParamOutType_CustomPar_06_HypIndependent:
    case HEADParamOutType_CustomPar_07_HypIndependent:
	case HEADParamOutType_CustomPar_08_HypIndependent:
	case HEADParamOutType_CustomPar_09_HypIndependent:
      {
        pInputData->CustCallbacks.fpCustomGetIndValue(pInputData, eOutType, pfParamValue, uiModuleNr);
      }
      break;
    default:
      locError = GDB_ERROR_UNKNOWN_TYPE;
      bFound = b_FALSE;
      *pfParamValue = 0.0f;
      break;
  }

  if(bFound != b_FALSE)
  {
    /* perform application specific filtering of value */
    if( pInputData->CustCallbacks.fpCustomFilterIndValue != NULL )
    {
      pInputData->CustCallbacks.fpCustomFilterIndValue(pInputData, eOutType, uiModuleNr, pfParamValue );
    }
  }

  return locError;
}/* PRQA S 7004 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability*/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif  /* !(MEDIC_CFG_HEAD20) */

/**@}*//* PRQA S 7013 *//* date: 2018-10-26, reviewer:Krupa H R, reason:suppressing cyclomatic complexity for better code maintainability */
