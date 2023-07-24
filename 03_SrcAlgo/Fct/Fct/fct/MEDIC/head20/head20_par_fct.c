/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_par_fct.c

DESCRIPTION:               functions of the HEAD parameters 

AUTHOR:                    $Author: P S, SADHANASHREE (uidk2760) (uidk2760) $

CREATION DATE:             $Date: 2020/11/05 11:34:49CET $

VERSION:                   $Revision: 1.66 $

LEGACY VERSION:            1.59.1.3 (HEAD 2.0)
  
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if (MEDIC_CFG_HEAD20)
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#include "head20/head20_int.h"
 /* PRQA S 3760 EOF */ /* date: 2019-09-24, reviewer: Sekar, Balaji, reason:If the function righ to && is not called also no side effects */
 /*PRQA S 2986 EOF*/ /*date: 2020-08-25, reviewer: Nalina M, reason: Supressing because arguments are different and operation is redundant*/
 /*PRQA S 2982 EOF*/ /*date: 2020-08-25, reviewer: Nalina M, reason: Supressing because the value will be used in future*/
/*PRQA S 7013 EOF*/ /*QAC message suppressed for number of executable lines per file.*/
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
static eGDBError_t HEADParamSetGeneric(HEADParameterEmpty_t *pParam, 
                                       HEADParameterEmpty_t *pRoot, 
                                       eHEADParamOutType_t eOutputType, 
                                       HEADParameterMode_t bfMode,
                                       HEADParameterHypothesisSub_t bfHypothesis, 
                                       HEADParameterSensorSourceSub_t bfSensorSource, 
                                       eHEADParamMainValueType_t eMainValueType, 
                                       eHEADParamOperator_t eOperator);
static eGDBError_t HEADGetTableInputVal(HEADParamTableType_t uiTableType, const struct HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp,
                                        const uint8 uiHypNo, uint8 uiModuleNr, float32 *outvalue, const HEADAdditionalTableInputValues_t* pAddTableInputs, uint16 Breakcascade);
static eGDBError_t HEADGetTableParam(const HEADParameterTable_t *pParamTable, const struct HEADInputData_t *pInputData, 
                                     const HEADHypothesis_t *pHyp, const uint8 uiHypNo, uint8 uiModuleNr, float32 *pOutValue, 
                                     const HEADAdditionalTableInputValues_t* pAddTableInputs);
static eGDBError_t HEADGet3dTableParam(const HEADParameterTable3D_t *pParamTable, const struct HEADInputData_t *pInputData, 
                                       const HEADHypothesis_t *pHyp, const uint8 uiHypNo, uint8 uiModuleNr, float32 *pOutValue, 
                                       const HEADAdditionalTableInputValues_t* pAddTableInputs, boolean *pbFound);
static boolean HEADIsCustomParameter( eHEADHypOutType_t eHypOutType );
static eGDBError_t HEADGetValueFromHyp( boolean bCheckOnlyPHyp, const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, 
                                        const uint8 uiHypNo, eHEADHypOutType_t eHypOutType, uint8 uiModuleNr, float32 *fVal, const uint16 uiCascadeNo);
/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
/****************************************************************************************************************************
  Functionname:        HEADParamSetGeneric                                                                              */ /*!

  @brief               creates a scalar parameter header

  @description         creates a scalar parameter header --> and sets the pointer from the last
                       element to the current element 
                       So the list that looked like this before:
                       root->Par1->Par2->Par3->NULL
                       looks now like this (with the new Parameter "ParNew"):
                       root->Par1->Par2->Par3->ParNew->NULL
                       Long parameter list is caused by the interface to 
                       auto-generated code
                   
                        @startuml
                        Start
                            If(Null check for check Parameter empty structure) then (Yes)
                            : update null pointer error;
                            Else
                            : initialize head parameter;
                            If(Is parameter and root parameter empty structure equal?) then (No)
                            While (null check for next parameter) then (No)
                            :next parameter assigned to next Parameter empty structure;
                            Endwhile(0)
                            : parameter empty structure value assigned
                            to next Parameter empty structure;
                            endif
                            if(Is operator type valid?) then (Yes)
                            else if(is it less than operator ) then (Yes)
                            : Update the value. That value must be less than parameter;
                            Else if(Is it greater than operator?) then (Yes)
                            : Update the value. That value must be greater than parameter;
                            Else if (Is it output value specific operator?)
                            : Updated value is Greater or less than the parameter.
                            It is depends on the output parameter;
                            Endif
                            Endif
                            :return the updated value;
                        stop
                        @enduml

  @return               static eGDBError_t: GDB error type is returned

  @param[in,out]        pParam         : Parameter definition for scalar values
  @param[in,out]        pRoot          : Pointer to head parameter empty structure 
  @param[in]            eOutputType    : Hypothesis output variable type of the parameter
  @param[in]            bfMode         : These variable is used to address fields in bit-fields 
  @param[in]            bfHypothesis   : Head bit field for head parameter hypothesis
  @param[in]            eMainValueType : These MainValueType defines value or factor
  @param[in]            bfSensorSource : It define the object quqlity 
  @param[in]            eOperator      : Head parameter operator for mathematic operation

  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 

  @pre                  None
  @post                 None

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}

  @author               Robert Thiel | robert.thiel@contiautomotive.com
        
****************************************************************************************************************************/
static eGDBError_t HEADParamSetGeneric(HEADParameterEmpty_t *pParam, 
                                       HEADParameterEmpty_t *pRoot, 
                                       eHEADParamOutType_t eOutputType, 
                                       HEADParameterMode_t bfMode,
                                       HEADParameterHypothesisSub_t bfHypothesis, 
                                       HEADParameterSensorSourceSub_t bfSensorSource,
                                       eHEADParamMainValueType_t eMainValueType, 
                                       eHEADParamOperator_t eOperator)
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
    pParam->ParameterType.sParameterType.ParameterHypSubType = (uint32)bfHypothesis;
    pParam->ParameterType.sParameterType.ParamSensorSource   = (uint8)bfSensorSource;
    pParam->ParameterType.sParameterType.ParameterMode       = (uint8)bfMode;
    pParam->ParameterType.sParameterType.ParamOutType        = (uint8)eOutputType;
    pParam->ParameterType.sParameterType.ParamMainValueType  = (uint8)eMainValueType;
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
          #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
          case HEADParamOutType_ItemConfidence:
          case HEADParamOutType_Inlap:
          case HEADParamOutType_ImpactVelEgo:
          case HEADParamOutType_ImpactVelRel:
          case HEADParamOutType_SafetyFunctionEnableFlag:
          case HEADParamOutType_SafetyFunctionKeepFlag:
          #endif
            pParam->ParameterType.sParameterType.ParamOperator = (uint8) HEADParamOperator_GREATERTHAN;
            break;          
          
          case HEADParamOutType_TTC:
          case HEADParamOutType_TTC2:
          case HEADParamOutType_TTC3:
          case HEADParamOutType_TTC4:
          #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
          case HEADParamOutType_TTB_PRE:
          case HEADParamOutType_TTB_ACUTE:
          #else
          case HEADParamOutType_TTB:
          #endif
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
          case HEADParamOutType_ObjectSpeed:
          #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
          case HEADParamOutType_TargetVelocity:
          case HEADParamOutType_TargetAngle:
          case HEADParamOutType_ShortestDistance:
          #endif
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
  Functionname:         HEADDGSMParamSetScalarWithBitPack                                                            */ /*!

  @brief                Creates a scalar parameter 

  @description          creates a scalar parameter and adds a bit pack for some special functions
                        the bitpack defines the (f16_t) default value of the hypothesis value if 
                        the hypothesis isn't found (for hypothesis dependent parameters like 
                        HEADParamOutType_TTC) the bitpack defines some information about 
                        other module state for HEADParamOutType_OtherModuleStateTime 
                        (HEADOtherModuleStateTime2BitPack(ModuleNr, ModulState, bInState))
                        Long parameter list is caused by the interface to 
                        auto-generated code
                        @startuml
                        Start
                            If(check for either scalar parameter or \nempty parameter availability) then (No)
                            : Null pointer error is updated;
                            Else(Yes)
                            #orange: set header, extra bit pack, object Class and dynamic Property
                            <b> HEADParamSetGeneric <b> >
                            endif
                            Note right
                            Set Scalar parameter as configured by HEAD AutoCoder 
                            and link the parameter to corresponding condition
                            endnote
                            :Return updated error type;
                        Stop
                        @enduml

  @return               eGDBError_t :GDB error type is returned

  @param[in,out]        pParam         : Pointer to head parameter empty structure 
  @param[in,out]        pRoot          : Pointer to head parameter empty structure 
  @param[in]            eOutputType    : Hypothesis output variable type of the parameter
  @param[in]            bfMode         : These variable is used to address fields in bit-fields
  @param[in]            bfHypothesis   : Head bit field for head parameter hypothesis
  @param[in]            eMainValueType : These main valueType defines value or factor
  @param[in]            fValue         : Store the float between min and max range
  @param[in]            eOperator      : Head parameter operator for mathematic operation(< and > operator)
  @param[in]            bfObjectClass  : Object class of hypothesis dependent parameter(Vehicle, Pedestrian, Cyclist and obstacle)
  @param[in]            bfDnyamicProp  : Define object status(moving , stationary)
  @param[in]            bfSensorSource : It define the object quqlity.
  @param[in]            bitPack        : Head  output type dependent parameter information
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 
  
  @pre                  None
  @post                 None

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADDGSMParamSetScalarWithBitPack(HEADParameterScalar_t *pParam, HEADParameterEmpty_t *pRoot, 
                                              eHEADParamOutType_t eOutputType, HEADParameterMode_t bfMode,
                                              HEADParameterHypothesisSub_t bfHypothesis, 
                                              eHEADParamMainValueType_t eMainValueType, 
                                              float32 fValue, eHEADParamOperator_t eOperator, 
                                              HEADEBAObjectClass_t bfObjectClass, 
                                              HEADEBADynProp_t bfDnyamicProp, HEADEBAObjMovDir_t bfObjMovDir,
                                              HEADParameterSensorSourceSub_t bfSensorSource, HEADBitPack_t bitPack)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pParam == NULL) || (pRoot == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    /*set header*/
    /*PRQA S 0314 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
    retValue = HEADParamSetGeneric((HEADParameterEmpty_t*)((void*)pParam), pRoot, eOutputType, bfMode,
                                        bfHypothesis, bfSensorSource, eMainValueType, eOperator);
    pParam->ParameterType.sParameterType.ParamMainType = (uint8) HEADParamMainType_Scalar;
    /*set raw parameter value*/

    fValue = MINMAX_FLOAT( (float32) -HEADPARFCT_FLOAT_MAX, (float32) HEADPARFCT_FLOAT_MAX, fValue);
    pParam->f16RawValue = HEADConvf32Tof16(fValue);  
    /*set extra bit pack*/
    pParam->uiSpecialParInfo = bitPack;
    pParam->ParameterType.sParameterType.ParamObjectClass = bfObjectClass;
    pParam->ParameterType.sParameterType.ParamDynProp = bfDnyamicProp;
    pParam->ParameterType.sParameterType.ParamObjMovDir = bfObjMovDir;
  }
  return retValue;
}/*PRQA S 7007 */ /* date: 2020-10-21, reviewer: Siri Prakash, reason: Intended behaviour*/


/*************************************************************************************************************************
  Functionname:         HEADDGSMParamSetTableWithBitPack                                                            */ /*!

  @brief                creates a table parameter 

  @description          creates a table parameter and adds a bit pack for some special functions
                        Long parameter list is caused by the interface to 
                        auto-generated code

                        @startuml
                        Start
                        If(check for scalar, empty or table parameter availability) then (No)
                        : Null pointer error is updated;
                        Else(Yes)
                        #orange:set header, object Class dynamic Property and raw parameter value
                        <b> HEADParamSetGeneric <b> >
                        endif
                        Note right:Set table parameter as configured by HEAD AutoCoder \n and link the parameter to corresponding condition.
                        :Return updated error type;
                        Stop
                        @enduml
                        
  @return               eGDBError_t :GDB error type is returned
                    
  @param[in,out]        pParam         : Parameter definition for table values 
  @param[in,out]        pRoot          : Pointer to head parameter empty structure 
  @param[in]            eOutputType    : Hypothesis output variable type of the parameter
  @param[in]            eTableType     : Parameter table type
  @param[in]            bfMode         : These variable is used to address fields in bit-fields
  @param[in]            bfHypothesis   : Head bit field for head parameter hypothesis
  @param[in]            eMainValueType : These main valueType defines value or factor
  @param[in]            uiNrOfRows     : Define the number of row 
  @param[in]            pTable        : Pointer to table 
  @param[in]            eOperator      : Head parameter operator for mathematic operation(< and > operator)
  @param[in]            fDefaultValue  : Define the float value
  @param[in]            eFloatType     : Define the float type ie 16 or 32 bit
  @param[in]            bfObjectClass  : Object class of hypothesis dependent parameter(Vehicle, Pedestrian, Cyclist and obstacle)
  @param[in]            bfDnyamicProp  : Define object status(moving , stationary)
  @param[in]            bfSensorSource : It define the object quqlity.
  @param[in]            bitPack        : Head  output type dependent parameter information
  
  @glob_in              None
  @glob_out             None
  
  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  pParam, pTable and pRoot must be in memory, pTable must be defined with the correct parameter settings
  @post                 [None]

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADDGSMParamSetTableWithBitPack(HEADParameterTable_t *pParam, HEADParameterEmpty_t *pRoot, eHEADParamOutType_t eOutputType, 
                                             HEADParamTableType_t eTableType, HEADParameterMode_t bfMode, 
                                             HEADParameterHypothesisSub_t bfHypothesis,
                                             eHEADParamMainValueType_t eMainValueType, 
                                             uint8 uiNrOfRows, const void *pTable, eHEADParamOperator_t eOperator,
                                             float32 fDefaultValue, eHEADParameterTableFloatType_t eFloatType,
                                             HEADEBAObjectClass_t bfObjectClass, HEADEBADynProp_t bfDnyamicProp, HEADEBAObjMovDir_t bfObjMovDir, 
                                             HEADParameterSensorSourceSub_t bfSensorSource, HEADBitPack_t bitPack)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pParam == NULL) || (pRoot == NULL) || (pTable == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    /*set header*/
    /*PRQA S 0314 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
    retValue = HEADParamSetGeneric((HEADParameterEmpty_t*)((void *)pParam), pRoot, eOutputType, 
                                        bfMode, bfHypothesis, bfSensorSource, eMainValueType, eOperator);

    pParam->ParameterType.sParameterType.ParamMainType = (uint8) HEADParamMainType_Table;
    pParam->ParameterType.sParameterType.ParamObjectClass = bfObjectClass;
    pParam->ParameterType.sParameterType.ParamDynProp = bfDnyamicProp;
    pParam->ParameterType.sParameterType.ParamObjMovDir = bfObjMovDir;
    /*set raw parameter value*/    
    pParam->eTableFloatType = eFloatType;
    pParam->pTable = pTable; /*const warning ROM pointer to RAM pointer*/
    pParam->TableType = eTableType;
    pParam->uiNrOfTableRows = uiNrOfRows;
    pParam->uiSpecialParInfo = 0u;
    fDefaultValue = MINMAX_FLOAT( (float32) -HEADPARFCT_FLOAT_MAX, (float32) HEADPARFCT_FLOAT_MAX, fDefaultValue);
    pParam->f16DefaultValue = HEADConvf32Tof16(fDefaultValue);
    pParam->uiSpecialParInfo = bitPack;
  }
  return retValue;
}/*PRQA S 7007 */ /* date: 2020-10-21, reviewer: Siri Prakash, reason: Intended behaviour*/


/*************************************************************************************************************************
  Functionname:         HEADDGSMParamSet3dTableWithBitPack                                                           */ /*!

  @brief                creates a 3D table parameter 

  @description          creates a 3D table parameter and adds a bit pack for some special functions
                        Long parameter list is caused by the interface to 
                        auto-generated code
                   
                        @startuml
                        Start
                            If(Null check for 3D table parameter) then (Yes)
                            : Null pointer error is updated;
                            Else(Yes)
                            #orange:set header, object Class dynamic Property, 3D table information and raw parameter value
                            <b> HEADParamSetGeneric <b> >
                            endif
                            Note right:Set 3D table parameter as configured by HEAD AutoCoder \n and link the parameter to corresponding condition.
                            :Return updated error type;
                        Stop
                        @enduml


  @return               eGDBError_t :GDB error type is returned

  @param[in,out]        pParam        : parameter definition for 3D table values
  @param[in,out]        pRoot          : Pointer to head parameter empty structure 
  @param[in]            eOutputType    : Hypothesis output variable type of the parameter
  @param[in]            eTableType1    : Define the first table parameter information 
  @param[in]            eTableType2    : Define the second table parameter information 
  @param[in]            bfMode         : These variable is used to address fields in bit-fields
  @param[in]            bfHypothesis   : Head bit field for head parameter hypothesis
  @param[in]            eMainValueType : These main valueType defines value or factor
  @param[in]            uiNrOfRows     : Define the number of row 
  @param[in]            uiNrOfCols     : Define the number of columns 
  @param[in]            pTable        : Pointer to table 
  @param[in]            eOperator      : Head parameter operator for mathematic operation(< and > operator)
  @param[in]            fDefaultX1Val  : Define the default X1 value in the table
  @param[in]            fDefaultX2Val  : Define the default X2 value in the table
  @param[in]            bfObjectClass  : Object class of hypothesis dependent parameter(Vehicle, Pedestrian, Cyclist and obstacle)
  @param[in]            bfDnyamicProp  : Define object status(moving , stationary)
  @param[in]            bfSensorSource : It define the object quqlity.
  @param[in]            bitPack        : Head  output type dependent parameter information
  
  @glob_in              None
  @glob_out             None
  
  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   
  
  @pre                  pParam, pTable and pRoot must be in memory, pTable must be defined with the correct parameter settings
  @post                 [None]

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com          
*************************************************************************************************************************/
eGDBError_t HEADDGSMParamSet3dTableWithBitPack(HEADParameterTable3D_t *pParam, HEADParameterEmpty_t *pRoot,
                                               eHEADParamOutType_t eOutputType, HEADParamTableType_t eTableType1,
                                               HEADParamTableType_t eTableType2, HEADParameterMode_t bfMode, 
                                               HEADParameterHypothesisSub_t bfHypothesis, eHEADParamMainValueType_t eMainValueType,
                                               uint8 uiNrOfRows, uint8 uiNrOfCols, const void *pTable, eHEADParamOperator_t eOperator,
                                               float32 fDefaultX1Val, float32 fDefaultX2Val, eHEADParam3DTableX2Type_t X2SignalType, 
                                               boolean X2DefaultResult, eHEADParameterTableFloatType_t eFloatType, 
                                               HEADEBAObjectClass_t bfObjectClass, HEADEBADynProp_t bfDnyamicProp, HEADEBAObjMovDir_t bfObjMovDir, 
                                               HEADParameterSensorSourceSub_t bfSensorSource, HEADBitPack_t bitPack)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pParam == NULL) || (pRoot == NULL) || (pTable == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    /*set header*/
    /*PRQA S 0314 2*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
    retValue = HEADParamSetGeneric((HEADParameterEmpty_t*)((void *)pParam), pRoot, eOutputType, 
                                        bfMode, bfHypothesis, bfSensorSource, eMainValueType, eOperator);

    pParam->ParameterType.sParameterType.ParamMainType = (uint8) HEADParamMainType_3dTable;
    pParam->ParameterType.sParameterType.ParamObjectClass = bfObjectClass;
    pParam->ParameterType.sParameterType.ParamDynProp = bfDnyamicProp;
    pParam->ParameterType.sParameterType.ParamObjMovDir = bfObjMovDir;
    /*set raw parameter value*/    
    pParam->eTableFloatType = eFloatType;
    pParam->pTable = pTable; /*const warning ROM pointer to RAM pointer*/
    pParam->TableType1 = eTableType1;
    pParam->TableType2 = eTableType2;
    pParam->uiNrOfTableRows = uiNrOfRows;
    pParam->uiNrOfTableCols = uiNrOfCols;
    pParam->uiSpecialParInfo = 0u;
    fDefaultX1Val = MINMAX_FLOAT( (float32) -HEADPARFCT_FLOAT_MAX, (float32) HEADPARFCT_FLOAT_MAX, fDefaultX1Val);
    pParam->f16DefaultValX1= HEADConvf32Tof16(fDefaultX1Val);
    fDefaultX2Val = MINMAX_FLOAT( (float32) -HEADPARFCT_FLOAT_MAX, (float32) HEADPARFCT_FLOAT_MAX, fDefaultX2Val);
    pParam->f16DefaultValX2= HEADConvf32Tof16(fDefaultX2Val);
    pParam->uiSpecialParInfo = bitPack;
    pParam->X2SignalType = X2SignalType;
    pParam->X2DefaultResult = X2DefaultResult;
  }
  return retValue;
}/*PRQA S 7007 */ /* date: 2020-10-21, reviewer: Siri Prakash, reason: Intended behaviour*/


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

  @InOutCorrelation     see description
  
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
  
  fResult = 0.0f;
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
    /*PRQA S 3350 1*/ /* date: 2019-05-23, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
    while (pTable[iRight] < fInputValue)
    {
      MEDIC_ASSERT(pTable[iRight+2]-pTable[iRight]>0.0f);/*PRQA S 3112,3119 */ /* date: 2019-09-19, reviewer: Srinivasa, Sadhanashree, Reason: This code is placed for assertive failure and hence cannot be removed *//*Detect Tables not fitting to norm of strictly increasing x values*/
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

  @return               float32          : interpolated value

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

  @InOutCorrelation     see description
  
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
  
  fResult = 0.0f;
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
    /*PRQA S 3350 1*/ /* date: 2019-05-23, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
    while (fTableValue < fInputValue)
    {
      MEDIC_ASSERT((HEADConvf16Tof32(pTable[iRight+2])-fTableValue)>0.0f);/*PRQA S 3119 */ /* date: 2019-09-19, reviewer: Srinivasa, Sadhanashree, Reason: This code is placed for assertive failure and hence cannot be removed *//*Detect Tables not fitting to norm of strictly increasing x values*/
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
  Functionname:         HEADCalculatePolygon3DValuef32                                                               */ /*!

  @brief                returns a value out of a 32bitfloat table using fInputValue

  @description          returns an interpolated value out of the 3D table as shown below
                        We get N1 as argument(uiNrOfTableRows), uiTableCol2Index as the starting position of y values.
                        We get 2D table pTable using these parameters and interpolation is done on the 2D table normally
                        fInputValue will be the required input value to the 2D table
                       
                        @startuml
                        Start
                        If(check for input value is less than or equal
                        to the first table value) then (Yes)
                        : Return the smallest sampling point y-value;
                        Elseif(check for input value is greater than or equal
                        to the last row table value) then (Yes)
                        : Return the biggest sampling point y-value;
                        Else (No)
                        While(check for input value and first index is less than the row table value and number of table rows) is (Yes)
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
  @param[in]            uiTableCol2Index : Define the table column index
  @param[in]            pTable           : Store the table values
  @param[in]            fInputValue      : Store the interpolation input value
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION  

  @pre                  pTable, must be in memory
  @post                 [None]

  @InOutCorrelation     
                        table[(N2)*(N1+1)] = {dummy,x1[1],x1[2],.........x1[N1], \n
                                               x2[1],y1[1],y1[2],.........y1[N1], \n
                                               x2[2],y2[1],y2[2],.........y2[N1], \n
                                               x2[N2],yN2[1],yN2[2],.........yN2[N1]} \n

                        N2 =  no of columns(parameter from autocoder)\n
                        N1 = no of rows(parameter from autocoder)\n
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision 
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
float32 HEADCalculatePolygon3DValuef32(uint8 uiNrOfTableRows, uint8 uiTableCol2Index, const float32 pTable[], float32 fInputValue)
{
  /*get table value*/
  uint32 iRight; /* The index of the nearest sampling point to the right */
  float32 fResult;
  float32 fWeightRight;
  
  fResult = 0.0f;
  iRight = 1u; /* first sampling point */

  /* If the x-position is left of the smallest sampling point,return the smallest sampling point y-value */
  if (fInputValue <= pTable[iRight]) /* index 1 is the smallest sampling point */
  {
    fResult = pTable[uiTableCol2Index];
  }
  /* If the x-position is right of the biggest sampling point,return the biggest sampling point y-value */
  else if (fInputValue >= pTable[uiNrOfTableRows])
  {
    fResult = pTable[(uiTableCol2Index + uiNrOfTableRows) - 1u];
  }
  /* In all other cases return the interpolated value between the matching sampling points */
  else
  {
    float32 fdx;
    /*PRQA S 3350 1*/ /* date: 2019-05-23, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
    while ((pTable[iRight] < fInputValue)&&(iRight < uiNrOfTableRows))
    {
      MEDIC_ASSERT(pTable[iRight+1]-pTable[iRight]>0.0f);/*PRQA S 3119 */ /* date: 2019-09-19, reviewer: Srinivasa, Sadhanashree, Reason: This code is placed for assertive failure and hence cannot be removed *//*Detect Tables not fitting to norm of strictly increasing x values*/
      iRight = iRight + 1u;
    }

    fdx = pTable[iRight] - pTable[iRight - 1u];
    
    if (F32_IS_NZERO(fdx))
    {
     fWeightRight = (fInputValue - pTable[iRight - 1u]) / (fdx);
    }
    else
    {
      fWeightRight = 0.0f;
    }

    fResult =   ((pTable[(uiTableCol2Index + iRight) - 2u]) *  (1.0f-fWeightRight))
                + ((pTable[(uiTableCol2Index + iRight) - 1u]) * fWeightRight);
  }
  return fResult;
}


/*************************************************************************************************************************
  Functionname:         HEADCalculatePolygon3DValuef16                                                              */ /*!

  @brief                returns a value out of a 16bitfloat table using fInputValue

  @description          returns an interpolated value out of the 3D table as shown below
                        We get N1 as argument(uiNrOfTableRows), uiTableCol2Index as the starting position of y values.
                        We get 2D table pTable using these parameters and interpolation is done on the 2D table normally
                        fInputValue will be the required input value to the 2D table
                   
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
                            While(check for input value and first index is less than the row table value and number of table rows) is (Yes)
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

 @param[in]             uiNrOfTableRows  : Get the number of table rows
  @param[in]            uiTableCol2Index : Define the table column index
  @param[in]            pTable           : Store the table values
  @param[in]            fInputValue      : Store the interpolation input value
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION  

  @pre                  pTable, must be in memory
  @post                 None

  @InOutCorrelation     table[(N2)*(N1+1)] = {dummy,x1[1],x1[2],.........x1[N1],\n
                        x2[1],y1[1],y1[2],.........y1[N1], \n
                        x2[2],y2[1],y2[2],.........y2[N1], \n
                        x2[N2],yN2[1],yN2[2],.........yN2[N1]}\n

                        N2 =  no of columns(parameter from autocoder)\n
                        N1 = no of rows(parameter from autocoder)\n
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision 
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
float32 HEADCalculatePolygon3DValuef16(uint8 uiNrOfTableRows, uint8 uiTableCol2Index, const f16_t pTable[], float32 fInputValue)
{
  /*get table value*/
  uint32 iRight; /* The index of the nearest sampling point to the right */
  float32 fResult;
  float32 fWeightRight;
  
  fResult = 0.0f;
  iRight = 1u; /* first sampling point */

  /* If the x-position is left of the smallest sampling point,return the smallest sampling point y-value */
  if (fInputValue <= HEADConvf16Tof32(pTable[iRight])) /* index 1 is the smallest sampling point */
  {
    fResult = HEADConvf16Tof32(pTable[uiTableCol2Index]);
  }
  /* If the x-position is right of the biggest sampling point,return the biggest sampling point y-value */
  else if (fInputValue >= HEADConvf16Tof32(pTable[uiNrOfTableRows]))
  {
    fResult = HEADConvf16Tof32(pTable[(uiTableCol2Index + uiNrOfTableRows) - 1u]);
  }
  /* In all other cases return the interpolated value between the matching sampling points */
  else
  {
    float32 fdx;
    float32 fTableValue = HEADConvf16Tof32(pTable[iRight]);
    /*PRQA S 3350 1*/ /* date: 2019-05-23, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
    while ((fTableValue < fInputValue)&&(iRight < uiNrOfTableRows))
    {
      MEDIC_ASSERT(HEADConvf16Tof32(pTable[iRight+1])-HEADConvf16Tof32(pTable[iRight])>0.0f);/*PRQA S 3119 */ /* date: 2019-09-19, reviewer: Srinivasa, Sadhanashree, Reason: This code is placed for assertive failure and hence cannot be removed *//*Detect Tables not fitting to norm of strictly increasing x values*/
      iRight = iRight + 1u;
      fTableValue = HEADConvf16Tof32(pTable[iRight]);
    }

    fdx = HEADConvf16Tof32(pTable[iRight]);
    fdx -= HEADConvf16Tof32(pTable[iRight - 1u]);
    
    if (F32_IS_NZERO(fdx))    
    {
     fWeightRight = (fInputValue - HEADConvf16Tof32(pTable[iRight - 1u])) / (fdx);
    }
    else
    {
      fWeightRight = 0.0f;
    }

    fResult =   ((HEADConvf16Tof32(pTable[(uiTableCol2Index + iRight) - 2u])) *  (1.0f-fWeightRight));
    fResult += ((HEADConvf16Tof32(pTable[(uiTableCol2Index + iRight) - 1u])) * fWeightRight);
  }
  return fResult;
}


/*************************************************************************************************************************
  Functionname:         HEADGetTableInputVal                                                                         */ /*!

  @brief                Returns the input value for a table parameter

  @description          Returns the input value for a table parameter
  
                        @startuml
                        Start
                            : Get Parameter table type;
                            Note right
                            Host Speed, Host Acceleration, Driver activity,
                            Driver feedback and Driver attention, these head module parameter types are checked
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
                            check relative velocity,Distance parameter types and TTC are checked)
                            : update return type as low quality signal;
                            elseIf(check DEPENDENT Parameter table type) then (Yes)
                            #orange: update hypothesis internal variable error type
                            <b> HEADGetValueFromHyp <b> >
                            Else if(check INDEPENDENT Parameter table type ) then (Yes)
                            #orange: update independent parameter error type
                            <b> HEADGSMGetIndValue <b> >
                            else
                            :update unknown error type;
                            Endif
                            :return the updated error;
                        stop
                        @enduml 

  @return               eGDBError_t      :GDB error type is returned

  @param[in]            uiTableType      : It define parameter value
  @param[in]            pInputData       : Pointer to input data
  @param[in]            pHyp             : Pointer to the hypothesis
  @param[in]            uiModuleNr       : Its count the module number 
  @param[in,out]        pOutValue        : Pointer to output value
  @param[in]            pAddTableInputs  : Pointer to additional table input values
    
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 

  @pre                  pInputData  must be in memory
  @post                 None

  
  @InOutCorrelation     see description

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1188-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/

static eGDBError_t HEADGetTableInputVal(HEADParamTableType_t uiTableType, const struct HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp,
                                        const uint8 uiHypNo, uint8 uiModuleNr, float32 *outvalue, const HEADAdditionalTableInputValues_t* pAddTableInputs, uint16 Breakcascade)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  sint32 siInputValue  = 0;

  switch(uiTableType)
  {      
    case HEADParamTableType_HostSpeed:
      locError = HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, outvalue);
      if( (pInputData->pInputValueList->LongVelocity.eSignalQuality != HEADInputSignalState_OK)
        &&(pInputData->pInputValueList->LongVelocity.eSignalQuality != HEADInputSignalState_BadQuality)
        &&(pInputData->pInputValueList->LongVelocity.eSignalQuality != HEADInputSignalState_Suspicious)
        &&(locError == GDB_ERROR_NONE) )
      {
        locError = GDB_ERROR_LOW_QUALITY;
      }
      break;
    case HEADParamTableType_HostAccel:
      locError = HEADGetInputValue_float32(pInputData->pInputValueList->LongAcceleration, HEAD_DEFAULT_LongAccel, outvalue);
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
      *outvalue = (float32) siInputValue;
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
      *outvalue = (float32) siInputValue;
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
      *outvalue = (float32) siInputValue;
      if( (pInputData->pInputValueList->DriverAttention.eSignalQuality != HEADInputSignalState_OK)
        &&(pInputData->pInputValueList->DriverAttention.eSignalQuality != HEADInputSignalState_BadQuality)
        &&(pInputData->pInputValueList->DriverAttention.eSignalQuality != HEADInputSignalState_Suspicious)
        &&(locError == GDB_ERROR_NONE) )
      {
        locError = GDB_ERROR_LOW_QUALITY;
      }
      break;
    case HEADParamTableType_Distance:
     locError = HEADGetValueFromHyp(b_TRUE, pInputData, pHyp, uiHypNo, HEADHypOutType_ObjectDist, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_HostSpeedLastStateTrans:
      *outvalue = pAddTableInputs->fHostSpeedLastStateTransition;
      if(pAddTableInputs->bHostSpeedLastStateTransitionOK == b_FALSE)
      {
        locError = GDB_ERROR_LOW_QUALITY;
      }
      break;
    case HEADParamTableType_ClosingVelocity:
     locError = HEADGetValueFromHyp(b_TRUE, pInputData, pHyp, uiHypNo, HEADHypOutType_ClosingVel, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_VRelX:
     locError = HEADGetValueFromHyp(b_TRUE, pInputData, pHyp, uiHypNo, HEADHypOutType_VRelX, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_TTC:
     locError = HEADGetValueFromHyp(b_TRUE, pInputData, pHyp, uiHypNo, HEADHypOutType_TTC, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_ObjListConfig:
      *outvalue = (float32)HEADSystemConfig.uiHEADRadCamFusOrRadOnly;
      break;
    case HEADParamTableType_ObjectSpeed:
     locError = HEADGetValueFromHyp(b_TRUE, pInputData, pHyp, uiHypNo, HEADHypOutType_ObjectSpeed, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_ObjectAccel:
     locError = HEADGetValueFromHyp(b_TRUE, pInputData, pHyp, uiHypNo, HEADHypOutType_ObjectAccel, uiModuleNr, outvalue, Breakcascade);
     break;
    case HEADParamTableType_Inlap:
     locError = HEADGetValueFromHyp(b_TRUE, pInputData, pHyp, uiHypNo, HEADHypOutType_Inlap, uiModuleNr, outvalue, Breakcascade);
     break;
    case HEADParamTableType_ImpactVelEgo:
      locError = HEADGetValueFromHyp(b_TRUE, pInputData, pHyp, uiHypNo, HEADHypOutType_ImpactVelEgo, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_ImpactVelRel:
      locError = HEADGetValueFromHyp(b_TRUE, pInputData, pHyp, uiHypNo, HEADHypOutType_ImpactVelRel, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_HypLifetime:
      locError = HEADGetValueFromHyp(b_TRUE, pInputData, pHyp, uiHypNo, HEADHypOutType_HypLifetime, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_00_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_00, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_01_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_01, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_02_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_02, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_03_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_03, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_04_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_04, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_05_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_05, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_06_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_06, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_07_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_07, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_08_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_08, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_09_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_09, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_10_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_10, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_11_HypDependent:
     locError = HEADGetValueFromHyp(b_FALSE, pInputData, pHyp, uiHypNo, HEADHypOutType_CustomPar_11, uiModuleNr, outvalue, Breakcascade);
      break;
    case HEADParamTableType_CustomPar_00_HypIndependent:
     locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_00_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_01_HypIndependent:
     locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_01_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_02_HypIndependent:
     locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_02_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_03_HypIndependent:
     locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_03_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_04_HypIndependent:
     locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_04_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_05_HypIndependent:
     locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_05_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_06_HypIndependent:
     locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_06_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_07_HypIndependent:
     locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_07_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_08_HypIndependent:
      locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_08_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_09_HypIndependent:
      locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_09_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_10_HypIndependent:
      locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_10_HypIndependent, uiModuleNr, outvalue);
      break;
    case HEADParamTableType_CustomPar_11_HypIndependent:
      locError = HEADGSMGetIndValue(pInputData, HEADParamOutType_CustomPar_11_HypIndependent, uiModuleNr, outvalue);
      break;
    default:
      locError = GDB_ERROR_UNKNOWN_TYPE;
      break;
  }

  return locError;
} /*PRQA S 7004*/ /*QAC message suppressed for cyclomatic complexitiy */


/*************************************************************************************************************************
  Functionname:         HEADGetTableParam                                                                           */ /*!

  @brief                returns a value out of a table parameter using the correct input

  @description          returns a value out of a table parameter using the correct input
  
                        @startuml
                        start
                            If(NULL pointer check) then (yes)
                            : update return type as null pointer error;
                            Else
                            #orange: get input value for the table
                            <b> HEADGetTableInputVal <b> >
                            If(check for local error is no error  ) then (Yes)
                            :update Input Value is true;
                            Else if (check for local error is low quality signal) then (Yes)
                            :update Input Value is true;
                            Else
                            :update Input Value is false;
                            endif
                            if (check for Input Value valid  is true) then (Yes)
                            if (check type of the Table values is FloatType_16) then (Yes)
                            #orange:  Corresponding Calculate Polygon Value are updated
                            <b> HEADCalculatePolygonValuef16 <b> 
                            Else
                            #orange: Corresponding Calculated 32 type Polygon Value are updated
                            <b> HEADCalculatePolygonValuef32 <b> >
                            endif
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

  
  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADGetTableParam(const HEADParameterTable_t *pParamTable, const struct HEADInputData_t *pInputData, 
                                     const HEADHypothesis_t *pHyp, const uint8 uiHypNo, uint8 uiModuleNr, float32 *pOutValue, 
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
    boolean bInputValueValid = b_FALSE;

    /*get input value for the table*/
    locError = HEADGetTableInputVal(pParamTable->TableType, pInputData, pHyp, uiHypNo, uiModuleNr, &fInputValue, pAddTableInputs, (uint16)pParamTable->uiSpecialParInfo);

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
}


/*************************************************************************************************************************
  Functionname:         HEADGet3dTableParam                                                                         */ /*!

  @brief                returns a value out of a 3d table parameter using the correct input

  @description          returns a value out of a 3d table parameter using the correct input
  
                        @startuml
                        Start
                            If(Null check for input parameter) then (True)
                            : Set the null pointer error;
                            Else
                            #orange: Get the error type
                            <b> HEADGetTableInputVal <b> >
                            If(Is it no error type?) then (Yes)
                            : Enable the local flag;
                            Elseif(Is signal quality bad?) then (Yes)
                            : Enable the local flag;
                            Else
                            : Disable the flag;
                            Endif
                            If(check for local flag is enabled) then (Yes)
                            #orange: Get the error type
                            <b> HEADGetTableInputVal <b> >
                            If(Is it no error type?) then (Yes)
                            : Enable the local flag;
                            Elseif(Is signal quality bad?) then (Yes)
                            : Enable the local flag;
                            Else
                            : Disable the flag;
                            Endif
                            If(check for local flag is enabled) then (Yes)
                            Note right 
                            Interpolate the output value
                            If no error in getting input values (X1 and X2)
                            Endnote
                            If(Is table float type values 16?) then (Yes)
                            If(Check for signal type is discrete) then (Yes)
                            While(Is number of table columns valid and local flag?) is (Yes)
                            : Get table value;
                            If(check for table input value is less than the delta threshold value) then (Yes)
                            : Enable the local flag;
                            Note right 
                            Once find the input table value then enable the flag
                            Endnote
                            Endif
                            Endwhile(No)
                            If(Is local value enabled?) then (Yes)
                            #orange:Interpolated output value is updated
                            <b> HEADCalculatePolygon3DValuef16 <b> >
                            Else
                            : Default value is updated its configure from autocoder;
                            Endif
                            Else
                            While(Is number of table columns valid and local flag?) is(Yes)
                            : Get table value ;
                            If(check for table input value is less than the delta threshold value) then (Yes)
                            : Enable the local flag;
                            Note right
                             Once find the input table value then enable the flag
                            End Note
                            Endif
                            Endwhile(No)
                            If(Is local value enabled?) then (Yes)
                            #orange:Interpolated output value is updated
                            <b> HEADCalculatePolygon3DValuef32 <b> >
                            Else
                            : Default value is updated its configure from auto coder;
                            endif
                            endif
                            endif
                            endif
                            endif
                            endif
                        stop
                        @enduml

  @return               eGDBError_t      :GDB error type is returned
  
  @param[in]            pParamTable      : Pointer to parameter definition for table values
  @param[in]            pInputData       : Pointer to input data
  @param[in]            pHyp             : Pointer to the hypothesis
  @param[in]            uiModuleNr       : Its count the module number 
  @param[in,out]        pOutValue        : Pointer to output value
  @param[in]            pAddTableInputs  : Pointer to additional table input values
  @param[in,out]        pbFound          : Define the status of the flag 
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 

  @pre                  pParamTable, pInputData and pOutValue must be in memory
  @post                 None

  
  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADGet3dTableParam(const HEADParameterTable3D_t *pParamTable, const struct HEADInputData_t *pInputData, 
                                       const HEADHypothesis_t *pHyp, const uint8 uiHypNo, uint8 uiModuleNr, float32 *pOutValue, 
                                       const HEADAdditionalTableInputValues_t* pAddTableInputs, boolean *pbFound)
{
  eGDBError_t locError = GDB_ERROR_NONE;
  if ((pParamTable == NULL) || (pOutValue == NULL) || (pParamTable->pTable == NULL) || (pInputData == NULL))
  {
    locError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
     float32 fInputValue1      = 0.0f;
     float32 fInputValue2      = 0.0f;
     boolean bInputValueValid = b_FALSE;

     /*get input X1 value for the table*/
     locError = HEADGetTableInputVal(pParamTable->TableType1, pInputData, pHyp, uiHypNo, uiModuleNr, &fInputValue1, pAddTableInputs, (uint16)pParamTable->uiSpecialParInfo);
     if(locError == GDB_ERROR_NONE)
     {
       bInputValueValid = b_TRUE;
     }
     else if(locError == GDB_ERROR_LOW_QUALITY)
     {
       fInputValue1 = HEADConvf16Tof32(pParamTable->f16DefaultValX1);
       bInputValueValid = b_TRUE;
     }
     else 
     {
       bInputValueValid = b_FALSE;
     }

     /* check if no error getting input X1 value */
     if(bInputValueValid == b_TRUE)
     {
        /*get input X2 value for the table*/
       locError = HEADGetTableInputVal(pParamTable->TableType2, pInputData, pHyp, uiHypNo, uiModuleNr, &fInputValue2, pAddTableInputs, (uint16)pParamTable->uiSpecialParInfo);
        if(locError == GDB_ERROR_NONE)
        {
          bInputValueValid = b_TRUE;
        }
        else if(locError == GDB_ERROR_LOW_QUALITY)
        {
          fInputValue2 = HEADConvf16Tof32(pParamTable->f16DefaultValX2);
          bInputValueValid = b_TRUE;
        }
        else 
        {
          bInputValueValid = b_FALSE;
        }

        /* no error in getting input values (X1 and X2) */
        /* interpolate the output value */
        if(bInputValueValid == b_TRUE)
        {
          uint8 uiIndex = 0u;
          uint8 uiCurrX2Index = 0u;
          *pbFound = b_FALSE;

          if(pParamTable->eTableFloatType == HEADParameterTableFloatType_f16)
          {
              if (pParamTable->X2SignalType == HEADParam3DTableX2Type_Discrete)
              { 
                    const f16_t *pTable = (const f16_t *)(pParamTable->pTable);

                    /* search the 2D table using the input value X2 */
                    for(uiIndex = 1u; (uiIndex < pParamTable->uiNrOfTableCols)&&(*pbFound == b_FALSE); uiIndex++)
                    {
                        uiCurrX2Index = uiIndex * (pParamTable->uiNrOfTableRows+1u);
                        /* 2D table found */ 
                        if(fABS(HEADConvf16Tof32(pTable[uiCurrX2Index]) - fInputValue2) <= CML_f_Delta) /* approximate matching for float values */
                        {
                           *pbFound = b_TRUE;
                        }
                    }

                    if(*pbFound == b_TRUE)  
                    {
                        *pOutValue = HEADCalculatePolygon3DValuef16(pParamTable->uiNrOfTableRows, (uiCurrX2Index+1u), (const f16_t *)(pParamTable->pTable), fInputValue1); 
                    }
                    else
                    {
                        /* Take default value of X2 defined in autocode. */ 
                        /* In this case we have to make this condition (to either TRUE/FALSE) according to autocode config */
                        *pOutValue = (float32)pParamTable->f16DefaultValX2;
                    }
              }
              else if (pParamTable->X2SignalType == HEADParam3DTableX2Type_Analog)
              {
                 /* This method interpolate the unknown value 'y' correspond to input signals x1 and x2 */
                 const f16_t *pTable = (const f16_t *)(pParamTable->pTable);    /* pointer to the table containing (uiNrOfTableRows+1)*(uiNrOfTableCols) values */
                 boolean bTableX1Input;
                 float32 fNearestSamplePoint[4];                        /* Nearest sampling points of y*/
                 float32 fIntermediateResult[2];

                 uint8 uiX1RelativeIndex[2] = {0,0};                    /* Hold 3DTableIndex correspond to nearest sampling points of X1*/
                 uint8 uiX2RelativeIndex[2] = {0,0};                    /* Hold 3DTableIndex correspond to nearest sampling points of X2*/
                 float32 fX1_WeightRight    = 0.0f;                           /* X1 Weightage from nearest right sample point */
                 float32 fX2_WeightRight    = 0.0f;                           /* X2 Weightage from nearest right sample point */

                 uint8 uiStepX2Index        = pParamTable->uiNrOfTableRows;
                 uiStepX2Index++;                                       /* columnstepsize = uiNrOfTableRows + 1 */

                 /* Find the two nearest known sample pointes correspond to Input values X1 and also find the weightage to the respective date points */
                 /* Only the weightage to right point is found, the remaing weightage in the ratio is for left point */
                 bTableX1Input              = b_TRUE;
                 HEADGet3dTableNearKnownValsAndWtg(pParamTable, fInputValue1, uiX1RelativeIndex, &fX1_WeightRight, bTableX1Input);

                 /* Find the two nearest known sample pointes correspond to Input values X2 and also find the weightage to the respective date points */
                 bTableX1Input              = b_FALSE;
                 HEADGet3dTableNearKnownValsAndWtg(pParamTable, fInputValue2, uiX2RelativeIndex, &fX2_WeightRight, bTableX1Input);

                 /* Based on data points of X1 and X2, Get all the four sampling points of y */
                 uiX2RelativeIndex[0]   = (uiStepX2Index * uiX2RelativeIndex[0]);
                 fNearestSamplePoint[0] = HEADConvf16Tof32(pTable[(uiX2RelativeIndex[0] + uiX1RelativeIndex[0])]);
                 fNearestSamplePoint[1] = HEADConvf16Tof32(pTable[(uiX2RelativeIndex[0] + uiX1RelativeIndex[1])]); 

                 uiX2RelativeIndex[1]   = (uiStepX2Index * uiX2RelativeIndex[1]);
                 fNearestSamplePoint[2] = HEADConvf16Tof32(pTable[(uiX2RelativeIndex[1] + uiX1RelativeIndex[0])]);
                 fNearestSamplePoint[3] = HEADConvf16Tof32(pTable[(uiX2RelativeIndex[1] + uiX1RelativeIndex[1])]);

                 /* Interpolate the sampling points with respective weightage*/
                 fIntermediateResult[0] = HEADInterpolation(fNearestSamplePoint[0], fNearestSamplePoint[1], fX1_WeightRight);
                 fIntermediateResult[1] = HEADInterpolation(fNearestSamplePoint[2], fNearestSamplePoint[3], fX1_WeightRight);

                 *pOutValue             = HEADInterpolation(fIntermediateResult[0], fIntermediateResult[1], fX2_WeightRight);
                 *pbFound               = b_TRUE;
              }
              else
              {
                  /* TBD. this case */
              }
          }
          else
          {
            const float32 *pTable = (const float32 *)(pParamTable->pTable);

            /* search the 2D table using the input value X2 */
            for(uiIndex = 1u; (uiIndex < pParamTable->uiNrOfTableCols)&&(*pbFound == b_FALSE); uiIndex++)
            {
              uiCurrX2Index = uiIndex * (pParamTable->uiNrOfTableRows+1u);

              /* 2D table found */ 
              if(fABS(pTable[uiCurrX2Index] - fInputValue2) <= CML_f_Delta ) /* approximate matching for float values */
              {
                *pbFound = b_TRUE;
              }
            }

            if(*pbFound == b_TRUE)  
            {
              *pOutValue = HEADCalculatePolygon3DValuef32(pParamTable->uiNrOfTableRows, (uiCurrX2Index+1u), (const float32 *)(pParamTable->pTable), fInputValue1);
            }
            else
            {
                 /* Take default value of X2 defined in autocode. */ 
                 /* In this case we have to make this condition (to either TRUE/FALSE) according to autocode config */
                 *pOutValue = (float32)pParamTable->f16DefaultValX2;
            }
          }
        }
     }
  }
  return locError;
} /*PRQA S 7002 */ /*date: 2020-10-21, Reviewer: Siri Prakash, Reason:suppressing cyclomatic complexity for better code maintainability*/  


/*************************************************************************************************************************
  Functionname:         HEADGetParam                                                                                */ /*!

  @brief                returns a value out of a parameter

  @description          returns a value out of a parameter if the conditions (mode, hypothesis) are met.
   
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
                            elseif(Is the parameter main type table ?) then (Yes)
                            #orange:Parameter table value updated to
                            the return  variable
                            <b> HEADGetTableParam <b> >
                            Elseif (Is the parameter main type 3D table ?) then (Yes)
                            #orange:Parameter table value updated to
                            the return  variable
                            <b> HEADGet3dTableParam <b> >
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
  @param[in]            pbFound
  @param[in]            pAddTableInputs  : Pointer to additional table input values

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  pParam, pInputData and pOutValue must be in memory
  @post                 None

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com

*************************************************************************************************************************/
eGDBError_t HEADGetParam(const HEADParameterEmpty_t *pParam, const struct HEADInputData_t *pInputData, 
                         const HEADHypothesis_t *pHyp, const uint8 uiHypNo, uint8 uiModuleNr, float32 *pOutValue, 
                         const HEADAdditionalTableInputValues_t* pAddTableInputs, boolean *pbFound)
{
  eGDBError_t retValue = GDB_ERROR_NONE;
  if ((pParam == NULL) || (pOutValue == NULL))
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  { 
    /*check if parameter is used in this mode*/
    if(
        /*either parametermode independend*/
       (pParam->ParameterType.sParameterType.ParameterMode == 0u) 
       ||
        /*paramtermode (early-middle-late-ACC) is used in this mode*/
       ((((uint32)pParam->ParameterType.sParameterType.ParameterMode) & (uint32)HEADParameterModeBit(pInputData->eHEADMainMode)) > 0u)
      )
    {
        switch(pParam->ParameterType.sParameterType.ParamMainType)
        {
        /*PRQA S 0314 16*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: Caste to void intended as use of generic interface*/
        case (HEADParamMainType_t)HEADParamMainType_Scalar:
            *pOutValue = HEADConvf16Tof32(((const HEADParameterScalar_t *)((const void *)pParam))->f16RawValue);
            *pbFound = b_TRUE;
            break;
          case (HEADParamMainType_t)HEADParamMainType_Table:
            retValue = HEADGetTableParam((const HEADParameterTable_t *)((const void *)pParam), pInputData, pHyp, uiHypNo, uiModuleNr, pOutValue, pAddTableInputs);
            *pbFound = b_TRUE;
            break;
          case (HEADParamMainType_t)HEADParamMainType_3dTable:
            retValue = HEADGet3dTableParam((const HEADParameterTable3D_t *)((const void *)pParam), pInputData, pHyp, uiHypNo, uiModuleNr, pOutValue, pAddTableInputs, pbFound);
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
                            If(Null check for hypothesis Out type) then (True)
                            : Set the null pointer error;
                            Else
                            If(Is the parameter out type valid?) then (Yes)
                            :Find Hypothesis out type \nfor Parameter out type;
                            Note right:Returns the hypothesis out type correspond \nto parameter out type
                            Else
                            : Set unknown type parameter;
                            Endif
                            Endif
                            : Return the updated error type;
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

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
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
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
      case HEADParamOutType_TTB_PRE:
        *peHypOutType = HEADHypOutType_TTB_PRE;
        break;
      case HEADParamOutType_TTB_ACUTE:
        *peHypOutType = HEADHypOutType_TTB_ACUTE;
        break;
#else
      case HEADParamOutType_TTB:
        *peHypOutType = HEADHypOutType_TTB;
        break;
#endif 
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
      case HEADParamOutType_ObjectSpeed: 
        *peHypOutType = HEADHypOutType_ObjectSpeed;
        break;
      case HEADParamOutType_ObjectAccel: 
        *peHypOutType = HEADHypOutType_ObjectAccel;
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
      case HEADParamOutType_CustomPar_09_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_09;
        break;
      case HEADParamOutType_CustomPar_10_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_10;
        break;
      case HEADParamOutType_CustomPar_11_HypDependent:
        *peHypOutType = HEADHypOutType_CustomPar_11;
        break;
      case HEADParamOutType_TargetVelocity:
        *peHypOutType = HEADHypOutType_TargetVelocity;
        break;
      case HEADParamOutType_TargetAngle:
        *peHypOutType = HEADHypOutType_TargetAngle;
        break;
      case HEADParamOutType_ShortestDistance:
        *peHypOutType = HEADHypOutType_ShortestDistance;
        break;
      #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
      case HEADParamOutType_ItemConfidence:
        *peHypOutType = HEADHypOutType_ItemConfidence;
        break;
      case HEADParamOutType_Inlap:
        *peHypOutType = HEADHypOutType_Inlap;
        break;
      case HEADParamOutType_ImpactVelEgo:
        *peHypOutType = HEADHypOutType_ImpactVelEgo;
        break;
      case HEADParamOutType_ImpactVelRel:
        *peHypOutType = HEADHypOutType_ImpactVelRel;
        break;
      #endif
      #if HEAD_CFG_TURN_ASSIST
      case HEADParamOutType_CorridorStopDistance:
        *peHypOutType = HEADHypOutType_CorridorStopDistance;
        break;
      #endif /* HEAD_CFG_TURN_ASSIST */
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
      case HEADParamOutType_CustomPar_10_HypIndependent:
      case HEADParamOutType_CustomPar_11_HypIndependent:
      #if HEAD_CFG_TURN_ASSIST
      case HEADParamOutType_SteeringAngle :
      case HEADParamOutType_TurnIndicatorInSteeringDirection:
      case HEADParamOutType_GasPedal :
      #endif /* HEAD_CFG_TURN_ASSIST */
      case HEADParamOutType_Max:
      default:
        retValue = GDB_ERROR_UNKNOWN_TYPE;
        break;
    }
  }
  return retValue;
} /*PRQA S 7004 */ /*QAC message suppressed for cyclomatic complexitiy */


/*************************************************************************************************************************
  Functionname:         HEADIsCustomParameter                                                                            */ /*!

  @brief                Checks if the parameter is a custom DEPENDENT parameter 

  @description          Checks if the parameter is a custom DEPENDENT parameter 
                        Returns TRUE if the parameter is a custom parameter
  
                        @startuml
                        Start
                            :initialize a return type;
                            If(check for relevant output hypothesis type availability) then (yes)
                            If(check for hypothesis dependent value or not) then (Yes)
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

  @return               static boolean : Returns TRUE if the parameter is a custom parameter

  @param[in]            eHypOutType : Its hypothesis output variable type
  
  @glob_in              None
  @glob_out             None 

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION 

  @pre                  None
  @post                 None

  @InOutCorrelation     see description
  
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
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
    case HEADHypOutType_TTB_PRE:
    case HEADHypOutType_TTB_ACUTE:
#else
    case HEADHypOutType_TTB:
#endif 
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
    case HEADHypOutType_ObjectSpeed:
    case HEADHypOutType_ObjectAccel:
    #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
    case HEADHypOutType_TargetVelocity:
    case HEADHypOutType_TargetAngle:
    case HEADHypOutType_ShortestDistance:
    case HEADHypOutType_ItemConfidence:
    case HEADHypOutType_Inlap:
    case HEADHypOutType_ImpactVelEgo:
    case HEADHypOutType_ImpactVelRel:
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
    case HEADHypOutType_CustomPar_09:
    case HEADHypOutType_CustomPar_10:
    case HEADHypOutType_CustomPar_11:
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
  Functionname:    HEADIsHypDependentParameter                                                                      */ /*!

  @brief           Checks if the parameter is a hyp dependent or independent parameter

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

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADIsHypDependentParameter( eHEADParamOutType_t eOutType, boolean* bRetValue )
{
  eGDBError_t locError = GDB_ERROR_NONE;
  *bRetValue = b_FALSE;
  switch(eOutType)
  {
    case HEADParamOutType_TTC                    :
    #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
    case HEADParamOutType_TTB_PRE                :
    case HEADParamOutType_TTB_ACUTE              :
    #else
   case HEADParamOutType_TTB                    :
    #endif
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
    case HEADParamOutType_TargetVelocity         :
    case HEADParamOutType_TargetAngle            :
    case HEADParamOutType_ShortestDistance       :
    case HEADParamOutType_CustomPar_00_HypDependent :
    case HEADParamOutType_CustomPar_01_HypDependent :
    case HEADParamOutType_CustomPar_02_HypDependent :
    case HEADParamOutType_CustomPar_03_HypDependent :
    case HEADParamOutType_CustomPar_04_HypDependent :
    case HEADParamOutType_CustomPar_05_HypDependent :
    case HEADParamOutType_CustomPar_06_HypDependent :
    case HEADParamOutType_CustomPar_07_HypDependent :
    case HEADParamOutType_CustomPar_08_HypDependent:
    case HEADParamOutType_CustomPar_09_HypDependent:
    case HEADParamOutType_CustomPar_10_HypDependent:
    case HEADParamOutType_CustomPar_11_HypDependent:
    case HEADParamOutType_ObjectSpeed:
    #if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
    case HEADParamOutType_ItemConfidence:
    case HEADParamOutType_Inlap:
    case HEADParamOutType_ImpactVelEgo:
    case HEADParamOutType_ImpactVelRel:
    case HEADParamOutType_SafetyFunctionEnableFlag:
    case HEADParamOutType_SafetyFunctionKeepFlag:
    #endif 
    #if HEAD_CFG_TURN_ASSIST
    case HEADParamOutType_CorridorStopDistance:
    #endif /* HEAD_CFG_TURN_ASSIST */
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
    case HEADParamOutType_CustomPar_10_HypIndependent   :
    case HEADParamOutType_CustomPar_11_HypIndependent   :
    #if HEAD_CFG_TURN_ASSIST
    case HEADParamOutType_SteeringAngle                   :
    case HEADParamOutType_TurnIndicatorInSteeringDirection:
    case HEADParamOutType_GasPedal                        :
    #endif /* HEAD_CFG_TURN_ASSIST */
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
  Functionname:    HEADGetHypValue                                                                                  */ /*!

  @brief           returns the value of a parameter out type out of a hypothesis 

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

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADGetHypValue(const HEADInputData_t *pInputData,
                           const HEADHypothesis_t *pHyp,
                           const uint8 uiHypNo,
                           eHEADHypOutType_t eHypOutType,
                           uint8 uiModuleNr,
                           boolean * bFound,
                           float32 *retValue,
                           const uint16 uiCascadeNo)/* PRQA S 3199 *//*Reviewer: Nalina M, Reason: will be required for feature use*/
{
  eGDBError_t retError = GDB_ERROR_NONE;

  if ( (pHyp != NULL) && (pInputData != NULL) && (pHyp->pHypothesis != NULL) && (retValue != NULL ) && (bFound != NULL ) )
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
      *bFound = b_TRUE;
      switch(eHypOutType)
      {
        case HEADHypOutType_TTC: 
          *retValue = MEDIC_f_GetHypTTC(pHyp);
          break;
        #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
        case HEADHypOutType_TTB_PRE:
          *retValue = MEDIC_f_GetHypTTBPre(pHyp);
          break;
        case HEADHypOutType_TTB_ACUTE:
          *retValue = MEDIC_f_GetHypTTBAcute(pHyp);
          break;
        #else
        case HEADHypOutType_TTB:
           *retValue = MEDIC_f_GetHypTTB(uiHypNo, uiCascadeNo);
          break;
        #endif
        case HEADHypOutType_TTS_PRE:
          *retValue = MEDIC_f_GetHypTTSPre(pHyp);
          break;
        case HEADHypOutType_TTS_ACUTE:
          *retValue = MEDIC_f_GetHypTTSAcute(pHyp);
          break;
        case HEADHypOutType_ClosingVel:
          *retValue = MEDIC_f_GetHypClosingVelocity(pHyp);
          break;
        case HEADHypOutType_ANecLong:
          *retValue = MEDIC_f_GetHypLongNecAccel(uiHypNo);
          break;
        case HEADHypOutType_HypProb:
          *retValue = (float32) MEDIC_u_GetHypProbability(pHyp);
          break;
        case HEADHypOutType_ObjectDist:
          *retValue = MEDIC_f_GetHypDistX(pHyp);
          break;
        case HEADHypOutType_ObjectDistLat:
          *retValue = MEDIC_f_GetHypDistY(pHyp);
          break;
        case HEADHypOutType_ObjProb:
          *retValue = (float32) MEDIC_u_GetHypObjProbability(pHyp);
          break;
        case HEADHypOutType_TTC2:
          *retValue = MEDIC_f_GetHypTTC2(pHyp);
          break;
        case HEADHypOutType_TTC3:
          *retValue = MEDIC_f_GetHypTTC3(pHyp);
          break;
        case HEADHypOutType_TTC4:
          *retValue = MEDIC_f_GetHypTTC4(pHyp);
          break;
        case HEADHypOutType_HypLifetime:
          *retValue = MEDIC_f_GetHypLifetime(pHyp);
          break;
        #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
        case HEADHypOutType_ANecLatAbs:
          *retValue = fABS(MEDIC_f_GetHypLatNecAccel(pHyp));
          break;
        case HEADHypOutType_VRelX:
          *retValue = MEDIC_f_GetHypVrelX(pHyp);
          break;
        case HEADHypOutType_ObjectSpeed:
          *retValue = (MEDIC_f_GetHypVrelX(pHyp)) + (pInputData->pInputValueList->LongVelocity.uValue.fValue);
          break;
        case HEADHypOutType_ObjectAccel:
          *retValue = (MEDIC_f_GetHypArelX(pHyp)) + (pInputData->pInputValueList->LongAcceleration.uValue.fValue) ;
          break;
        #else
        case HEADHypOutType_TargetVelocity:
          *retValue = MEDIC_f_GetHypVabs(pHyp);
          break;
        case HEADHypOutType_TargetAngle:
          *retValue = MEDIC_f_GetHypAngle(pHyp);
          break;
        case HEADHypOutType_ShortestDistance:
          *retValue = MEDIC_f_GetHypDist(pHyp);
          break;
        case HEADHypOutType_VRelX:
          *retValue = MEDIC_f_GetHypVabsX(pHyp) - (pInputData->pInputValueList->LongVelocity.uValue.fValue);
          break;
        case HEADHypOutType_ObjectSpeed:
          *retValue = MEDIC_f_GetHypVabsX(pHyp);
          break;
        case HEADHypOutType_ObjectAccel:
          *retValue = (MEDIC_f_GetHypAabsX(pHyp));
          break;
        case HEADHypOutType_ItemConfidence:
          *retValue = (float32)(MEDIC_f_GetHypItemConfidence(pHyp));
          break;
        case HEADHypOutType_Inlap:
          *retValue = MEDIC_f_GetHypInlap(pHyp);
          break;
        case HEADHypOutType_ImpactVelEgo:
          *retValue = MEDIC_f_GetHypImpactVelEgo(uiHypNo, uiCascadeNo);
          break;
        case HEADHypOutType_ImpactVelRel:
          *retValue = MEDIC_f_GetHypImpactVelRel(uiHypNo, uiCascadeNo);
          break;
        #endif
        #if defined(HEAD_USE_TTM_LONG) && (HEAD_USE_TTM_LONG == MEDIC_ON) 
        /* Use TTM LONG - this config switch is doubled from CD! */
        case HEADHypOutType_TTMLongPre:
          *retValue = MEDIC_f_GetHypTTMLongPre(pHyp);
          break;
        case HEADHypOutType_TTMLongAcute:
          *retValue = MEDIC_f_GetHypTTMLongAcute(pHyp);
          break;
        #endif
        #if HEAD_CFG_TURN_ASSIST
        case HEADHypOutType_CorridorStopDistance:
        #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
          *retValue = MEDIC_f_GetHypCorridorStopDist(pHyp);
        #else
          *retValue = MEDIC_f_GetHypCorridorStopDist(uiHypNo, uiCascadeNo);
        #endif
          break;
        #endif
        /*driver hyp or other*/
        case HEADHypOutType_SensorSource:
        case HEADHypOutType_CustomPar_00:
        case HEADHypOutType_CustomPar_01:
        case HEADHypOutType_CustomPar_02:
        case HEADHypOutType_CustomPar_03:
        case HEADHypOutType_CustomPar_04:
        case HEADHypOutType_CustomPar_05:
        case HEADHypOutType_CustomPar_06:
        case HEADHypOutType_CustomPar_07:
        case HEADHypOutType_CustomPar_08:
        case HEADHypOutType_CustomPar_09:
        case HEADHypOutType_CustomPar_10:
        case HEADHypOutType_CustomPar_11:
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
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  _PARAM_UNUSED(uiCascadeNo);/* PRQA S 3119 *//*date: 2020-07-06, Reviewer: Praveen Annareddy, Reason: will be required for feature use*/
  #endif 
  return retError;
} /*PRQA S 7004 , 7002 */ /*date: 2020-10-21, Reviewer: Siri Prakash, Reason:QAC message suppressed for cyclomatic complexitiy*/  


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
                            endwhile (0)
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
  
  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}

  @todo                 Rework this function
                        if(locError != GDB_ERROR_NONE) : Do Error Case handling
                        if(bFound == FALSE) : Change this to consistent behavior

  @author               Robert Thiel | robert.thiel@contiautomotive.com
*************************************************************************************************************************/

static eGDBError_t HEADGetValueFromHyp(boolean bCheckOnlyPHyp, const HEADInputData_t *pInputData,
                                       const HEADHypothesis_t *pHyp, const uint8 uiHypNo, eHEADHypOutType_t eHypOutType,
                                       uint8 uiModuleNr, float32 *fVal, const uint16 uiCascadeNo)
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
    eGDBError_t locError = HEADGetHypValue(pInputData, pHyp, uiHypNo, eHypOutType, uiModuleNr, &bFound, &fOutVal, uiCascadeNo);
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
          locError = HEADGetHypValue( pInputData, pCurrHyp, uiI, eHypOutType, uiModuleNr, &bFound, &fOutVal, uiCascadeNo);
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
                            : Get parameter output type;
                            If(check for parameter output type is state active time) then (Yes)
                            If( Is global state machine state less than the combination of minimum 
                            and number of states in the current module && greater 
                            than the minimum number of states in the current module) then (Yes)
                            : Get the module state and update how 
                            long time module is in the current state;
                            Else
                            : overflow error is updated;
                            Endif
                            Elseif (check for ego velocity signal quality type is default
                            value, bad quality and suspicious signal state ) then (No)
                            : Update Error based on signal Quality.;
                            Note right
                            Ego lateral curvature, Ego acceleration, Safe object distance safety,
                            Driver feedback probability, Driver sctivity probability and
                            Driver attention probability all parameter output type signal is checked
                            endnote
                            Elseif(Is hypothesis independent parameter?) then (yes)
                            :Call Custom Independent \nparameter callback function;
                            else
                            :update unknown error type;
                            Endif
                            If(Is the local flag enabled?)then (Yes)
                            If(Null check for filtering independent custom parameters) then (True)
                            : perform application specific filtering of value;
                            Endif
                            Endif
                        Stop
                        @enduml

  @return               eGDBError_t    :GDB error type is returned

  @param[in]            pInputData     : Pointer to input data
  @param[in]            eOutType       : Hypothesis output type of the parameter
  @param[in]            uiModuleNr     : Its count the module number 
  @param[in,out]        pfParamValue   : Pointer to parammeter value

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     see description
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1141-0007e0f8}
  
  @author               Andreas Jakob | andreas.jakob-ext@conti-engineering.com
*************************************************************************************************************************/
eGDBError_t HEADGSMGetIndValue( const struct HEADInputData_t *pInputData,
                                const eHEADParamOutType_t eOutType,
                                const uint8 uiModuleNr,
                                float32 *pfParamValue)
{
  HEADModule_t * pModule = NULL;
  HEADModuleState_t *pState = NULL;

  sint32 sProb = 0;

  #if HEAD_CFG_TURN_ASSIST
  boolean bValue = b_FALSE;
  #endif /* HEAD_CFG_TURN_ASSIST */

  eGDBError_t locError = GDB_ERROR_NONE;
  boolean bFound = b_TRUE;

  pModule = HEADGetModule(pInputData->pModuleList, uiModuleNr);

  switch( eOutType )
  {
    case HEADParamOutType_StateActiveTime:
      {
        if ((((HEADSMState_t)pModule->eDGSMState) < (pModule->uiNumModuleStates + (HEADSMState_t)pModule->eNumModuleStateMin))
           && (((HEADSMState_t)pModule->eDGSMState) >= ((HEADSMState_t)pModule->eNumModuleStateMin)))
        {
          pState       = HEADGetModuleState(pModule, ((uint32)pModule->eDGSMState - (uint32)pModule->eNumModuleStateMin));
          *pfParamValue = pState->fStateTimer; 
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
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->EgoLatCurvature, (float32)HEAD_DEFAULT_EgoLatCur, pfParamValue);
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
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->SteeringAngle, (float32)HEAD_DEFAULT_SteeringAngle, pfParamValue);
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
        locError = HEADGetInputValue_float32(pInputData->pInputValueList->GasPedal, (float32)HEAD_DEFAULT_GasPedal, pfParamValue);
      }
      break;
    #endif /* HEAD_CFG_TURN_ASSIST */
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
    case HEADParamOutType_CustomPar_10_HypIndependent:
    case HEADParamOutType_CustomPar_11_HypIndependent:
    {
      pInputData->CustCallbacks.fpCustomGetIndValue(pInputData, eOutType, pfParamValue);
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
} /*PRQA S 7004*/ /*QAC message suppressed for cyclomatic complexitiy */


/*****************************************************************************************************************************
  Functionname:         HEADInterpolation                                                                               */ /*!

  @brief                This function is used get the value of unknown point based on the weightage of the two known points.

  @description          This function is used get the value of unknown point based on the weightage of the two known points.
                        @startuml
                        Start
                            :Get Input sample points and do Linear interpolation;
                        Stop
                        @enduml

  @return               float32 : Linear interpolated result value

  @param[in]            fPoint1 : First sample point
  @param[in]            fPoint2 : Second sample point
  @param[in]            fPoint2Weight : Weightage average from first sample point
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  [None]
  @post                 [None]

  @InOutCorrelation     see description

  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision 

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*****************************************************************************************************************************/
static float32 HEADInterpolation(const float32 fPoint1, const float32 fPoint2, const float32 fPoint2Weight)
{
  float32 fResult;
  fResult = (fPoint1 * (1.0f - fPoint2Weight));
  fResult = (fResult + (fPoint2 * fPoint2Weight));
  return fResult;
}


/*****************************************************************************************************************************
  Functionname:         HEADGet3dTableNearKnownValsAndWtg                                                               */ /*!

  @brief                This function is used to find the two nearest known Date pointes correspond to Input values and
                        also finds the weightage to the respective date points.

  @description          This function is used to find the two nearest known Date pointes correspond to Input values and
                        also finds the weightage to the respective date points.
                        @startuml
                        Start
                        : Get 3D table;
                        If (((Is Input Value for X1)==(True))) then (yes)
                            :need to Iterate through rows to find the nearest sample points,
                             and also find the weightage of each points;
                        Else (no)
                            :need to Iterate through column to find the nearest sample points,
                             and also find the weightage of each points;
                        Endif
                        Note: If Input is smaller than smallest sampling point,\n return the smallest sampling point index
                        Stop
                        @enduml

  @return               void

  @param[in]            pParamTable : Pointer to parameter definition for table values
  @param[in]            fInputValue : Table Input Value
  @param[out]           uiRelativeIndex : Sample point Index
  @param[out]           pWeightRight : Weighted average from each sample points
  @param[in]            bIsInputValueForX1 : Boolean indicates X1 Input

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HEAD20 \n
                        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
                        
  @pre                  [None]
  @post                 [None]

  @InOutCorrelation     See description

  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision 

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*****************************************************************************************************************************/
static void HEADGet3dTableNearKnownValsAndWtg( const HEADParameterTable3D_t *pParamTable, 
                                               float32 fInputValue, 
                                               uint8 uiRelativeIndex[], 
                                               float32 *pWeightRight, 
                                               boolean bIsInputValueForX1 )
{
  uint8 uiIndxRight = 1;                /* The index of the nearest sampling point to the right */
  float32 fdx;                          /* Distance between the nearest sampling points */
  float32 fTableValue;                  /* Table Value */
  uint8 uiNextIndexStepSize = 0;        /* Number of Steps needed to goto the next Row or column Index */
  uint8 uiLastRowColIndex = 0 ;         /* Last Row or Column Index */

   const f16_t *pTable = (const f16_t *)(pParamTable->pTable);      /* pointer to the table containing (uiNrOfTableRows+1)*(uiNrOfTableCols) values */
 
  if (bIsInputValueForX1 == b_TRUE)
  {
     /* Input value is X1 so need to Iterate through rows to find the nearest sample points */
     uiNextIndexStepSize = 1;
     uiLastRowColIndex = pParamTable->uiNrOfTableRows;
  }
  else
  {
     /* Input value is X2 so need to Iterate through column to find the nearest sample points */
     uiNextIndexStepSize = pParamTable->uiNrOfTableRows;
     uiNextIndexStepSize++;                                 /* columnstepsize = uiNrOfTableRows + 1*/
     uiLastRowColIndex = pParamTable->uiNrOfTableCols;
     uiLastRowColIndex--;                                   /* Lastcolumn = uiNrOfTableCols - 1*/
  }

   /* If the x-position is left of the smallest sampling point, return the smallest sampling point index */
   /* In this case no need to find the weightage since both left and right points are the same points*/
  if (fInputValue <= HEADConvf16Tof32(pTable[(uiIndxRight * uiNextIndexStepSize)]))
  {
     uiRelativeIndex[0] = uiIndxRight;
     uiRelativeIndex[1] = uiIndxRight;
     *pWeightRight = 0.0f;
  }
  /* If the x-position is right of the biggest sampling point,return the biggest sampling point index */
  /* In this case no need to find the weightage since both left and right points are the same points*/
  else if (fInputValue >= HEADConvf16Tof32(pTable[(uiLastRowColIndex * uiNextIndexStepSize)]))
  {
     uiIndxRight = uiLastRowColIndex;
     uiRelativeIndex[0] = uiIndxRight;
     uiRelativeIndex[1] = uiIndxRight;
     *pWeightRight = 0.0f;
  }
  /* In all other cases return the nearest left and right sampling points index and also find the weightage of the each points */
  /* Only the weightage to right point is found, the remaing weightage in the ratio is for left point */
  else
  {
     fTableValue = HEADConvf16Tof32(pTable[(uiIndxRight * uiNextIndexStepSize)]);
     /*PRQA S 3350 1*/ /* date: 2019-05-23, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
     while (fTableValue < fInputValue)
     {
        uiIndxRight++;
        MEDIC_ASSERT(HEADConvf16Tof32(pTable[(uiIndxRight * uiNextIndexStepSize)])-fTableValue>0.0f);/*PRQA S 3119 */ /* date: 2019-09-19, reviewer: Srinivasa, Sadhanashree, Reason: This code is placed for assertive failure and hence cannot be removed *//*Detect Tables not fitting to norm of strictly increasing x values*/
        fTableValue = HEADConvf16Tof32(pTable[(uiIndxRight * uiNextIndexStepSize)]);
     }
     fdx = HEADConvf16Tof32(pTable[(uiIndxRight * uiNextIndexStepSize)]);
     fdx -= HEADConvf16Tof32(pTable[((uiIndxRight * uiNextIndexStepSize) - uiNextIndexStepSize)]);
    
     if (F32_IS_NZERO(fdx))    
     {
        *pWeightRight = (fInputValue - HEADConvf16Tof32(pTable[((uiIndxRight * uiNextIndexStepSize) - uiNextIndexStepSize)])) / (fdx);
     }
     else
     {
        *pWeightRight = 0.0f;
     }

     uiRelativeIndex[0] = uiIndxRight-1u;
     uiRelativeIndex[1] = uiIndxRight;
  }
}

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* MEDIC_CFG_HEAD20 */


