/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_codingSwitches.h

DESCRIPTION:               Implementation of the head codingSwitches

AUTHOR:                    $Author: uia92763 $

CREATION DATE:             $Date: 2020/09/14 06:36:28CEST $

VERSION:                   $Revision: 1.8.8.3 $

LEGACY VERSION:            1.15.2.1

**************************************************************************** */

/**
@defgroup head_codingSwitches HEAD_CODINGSWITCHES
@ingroup Medic_head
@{ **/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_HEAD20)
#include "head/head_int.h"
#if MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief ObjMovement_t

    @general object movement types for the coding (Moving, Stationary)

    @conseq [None]

    @attention [None]
    */
typedef enum 
{
  CPARObjMoving = 0,   /*!<Object movement type is moving*/
  CPARObjStat   = 1    /*!<Object movement type is stationary*/
} ObjMovement_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Cod_ObjType_t

    @general Object Types for the Codings (Vehicle, Pedestrian, Cyclist, Obstacle) 

    @conseq [None]

    @attention [None]
    */
typedef enum 
{
  CPARObjVeh  = 0,  /*!<Object Type is vehicle */
  CPARObjPed  = 1,  /*!<Object Type is  pedestrian */
  CPARObjCycl = 2,  /*!<Object Type is cyclist */
  CPARObjObst = 3   /*!<Object Type is bbstacle */
} Cod_ObjType_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief Sw_ObjType_t

    @general Object Types for the switches (Vehicle, VRU)

    @conseq [None]

    @attention [None]
    */
typedef enum
{
  SwitchObjVeh = 0,  /*!<defines the switch Object Type is vehcile*/
  SwitchObjVru = 1   /*!<defines the switch Object Type is Vulnerable road user */
} Sw_ObjType_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief DriverFeature_t

    @general Driver Feature Types for coding and switches (Longitudinal, Crossing, Oncoming)

    @conseq [None]

    @attention [None]
    */
typedef enum
{
  CPARObjLong  = 0,  /*!<Longitudinal driver feature type */
  CPARObjCross = 1,  /*!<Crossing driver feature type */
  CPARObjOnCom = 2   /*!<Oncoming driver feature type */
} DriverFeature_t;

/*****************************************************************************
  VARIABLES
*****************************************************************************/
HEADCustomCodingInfo_t HEADCodingInfo;

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static void HEADDegradateModule(const uint16 moduleNr);
static eGDBError_t HEADCustomReadCodingParams( void );
static DriverFeature_t HEADConvEBAMoVDir2DriverFeature(eEBAObjMovDir_t ObjectDirection);
static Cod_ObjType_t HEADConvEBAObjClass2CPARObjClass(eEBAObjectClass_t objClass);
static eGDBError_t HEADGetEBACodingIndex(HEADHypothesis_t const *pHyp, t_EBACodingParamFctModsIdx *FctModsIdx);

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
#pragma PRQA_NO_SIDE_EFFECTS HEADGetEBASwitch
#pragma PRQA_NO_SIDE_EFFECTS HEADGetEBACoding
#pragma PRQA_NO_SIDE_EFFECTS HEADGetEBASwitchHyp

/*************************************************************************************************************************
  Functionname:         HEADGetEBACoding                                                                         */ /*!

  @brief                Reads customer Coding Params 

  @description          Reads customer Codings
                        @startuml
                        start
                            :Initializes internal pointer to external EBA Coding Parameter INPUT interface for  FCT Coding Parameters;
                            :Initializes coding Parameters for EBA function by calculating the coding index;
                        Note left: returns coding status True or False
                        stop
                        @enduml

  @return               boolean           : (switch state True/False)

  @param[in]            CPAR_EBA_Function : the corresponding function (e.g. EBA_CODING_BIT_PRECRASH)
  @param[in]            eEBACodingIdx     : index of the coding (calculated through HEADGetEBACodingIndex)

  @glob_in              @ref MEDIC_p_GetCPARFCTParameters()
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability         

  @author               Ayman Almalih | ayman.almalih@continental-corporation.com
*************************************************************************************************************************/
boolean HEADGetEBACoding(CPAREBACodingFctMods_t CPAR_EBA_Function, t_EBACodingParamFctModsIdx eEBACodingIdx)
{
  const CPAR_EBA_Parameters_t *const CPAR_EBA_Parameters = &(MEDIC_p_GetCPARFCTParameters()->EBA);
  const CPAREBACodingFctMods_t CParamFmod = CPAR_EBA_Parameters->EBACodingParamFctMods[eEBACodingIdx];

  boolean retVal = ( (CParamFmod & CPAR_EBA_Function) > 0u) ? TRUE:FALSE;
  return retVal;
}

/*************************************************************************************************************************
  Functionname:         HEADGetEBASwitch                                                                         */ /*!

  @brief                gets the switch state 

  @description          gets the current state for the corresponding switch based on the FunctionBit

                        @startuml
                        start
                            : Gets the Switch state by Initializing the internal pointer to external HEAD generic  INPUT interface;
                            : Gets the current state for the corresponding switch based on the FunctionBit;
                        Note left: returns Switch state status to True or False
                        stop
                        @enduml

  @return               boolean     : (switch state True/False)

  @param[in]            FunctionBit : e.g. eEBASwitch_LongVehDW

  @glob_in              @ref MEDIC_p_GetHeadInGeneric()
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability         

  @author               Ayman Almalih | ayman.almalih@continental-corporation.com 
*************************************************************************************************************************/
boolean HEADGetEBASwitch(eFunctionSwitch_t FunctionBit)
{
  const eFunctionSwitch_t eFunctionSwitches = MEDIC_p_GetHeadInGeneric()->eFunctionSwitch;
  boolean retVal = ( (eFunctionSwitches & FunctionBit) > 0u) ? TRUE : FALSE;
  return retVal;
}

/*************************************************************************************************************************
  Functionname:         HEADGetEBASwitchHyp                                                                         */ /*!

  @brief                Reads Switches 

  @description          gets the current state for the corresponding switch based on the Function type and the extracted data of the Hypo.
                        @startuml
                        Start
                            :Reads the Switches;
                            :Gets the current state of the switch based on Function type along with Hypothesis data;
                        If(checks for Hypothesis availability) then (yes)
                         :Sets the object class;
                            note left
                            Objects are Classified into Vehicle, Obstacle, Pedestrian and Cyclist
                            End note
                            If(Checks for Main Switch is Valid and Active) then (yes)
                                :Calculates the Switch index value for Enabling EBA Switching Function based on FunctionBit value;
                                note left
                                 Returns True value
                                End note
                            Else (no)
                                :Disables all FCT and EBA switches;
                                note left
                                Returns False value
                                End note
                            Endif
                        Else (no)
                            note right
                            Returns False value
                            End note
                            endif 
                        Stop
                        @enduml

  @return               boolean Switch status (True/False)

  @param[in]            eFunctionSwitch : the corresponding function (e.g. Switch_BRK)
  @param[in]            pHyp : the current Hypo.

  @glob_in              @ref MEDIC_p_GetHeadInGeneric()
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability         

  @author               Ayman Almalih | ayman.almalih@continental-corporation.com
*************************************************************************************************************************/
boolean HEADGetEBASwitchHyp(Switch_Function_t eFunctionSwitch, HEADHypothesis_t const *pHyp)
{
  uint32 eEBASwitchIdx = 0;
  eFunctionSwitch_t FunctionBit = 0;
  boolean retVal = FALSE;
  const eMainSwitch_t eMainSwitch = MEDIC_p_GetHeadInGeneric()->eMainSwitch;

  if(pHyp == NULL)
  {
    retVal = FALSE;
  }
  else
  {
    const Hypothesis_t* plocalHyp = pHyp->pHypothesis;
    eEBAObjectClass_t objClass = plocalHyp->eEBAObjectClass;
    eEBAObjMovDir_t ObjectDirection = plocalHyp->eEBAObjMovDir;
    DriverFeature_t DriverFeature = HEADConvEBAMoVDir2DriverFeature(ObjectDirection);
    Sw_ObjType_t Sw_ObjectType;
    /* setting the Object type */
    if ((objClass == EBAObjectClass_Vehicle) || (objClass == EBAObjectClass_Obstacle))
    {
      Sw_ObjectType = SwitchObjVeh;
    }
    else if ((objClass == EBAObjectClass_Pedestrian) || (objClass == EBAObjectClass_Cyclist))
    {
      Sw_ObjectType = SwitchObjVru;
    }
    else
    {
      Sw_ObjectType = SwitchObjVeh;
    }

    if (eMainSwitch_Invalid != eMainSwitch)
    {
      /* evaluate MainSwitch */
      if (eMainSwitch_Inactive == eMainSwitch) 
      {
        /* Disable all */
        retVal = FALSE;
      }
      else
      {
        /* Calculation of the switch index:
        Driver Feature   DF:=3 (LONG=0, CROSS=1, ONC=2) [i]
        Object Type      OT:=2 (VEH=0, VRU=1) [j]
        Switch Function  SF:=5 (DW=0, FCW1=1, FCW2=2, FCW3=3, BRK=4) [k]
        Switch index     M[i][j][k] = [i*(OT*OM)+j*OM+k]*/
        /*                                k          +            SF *                          j        +              SF           *         OT               *             i        */
        eEBASwitchIdx = (uint32) eFunctionSwitch + (HEAD_Switch_Function_Nr * ((uint32)Sw_ObjectType)) + (HEAD_Switch_Function_Nr*HEAD_Switch_Object_Type_Nr*((uint32)DriverFeature));
        FunctionBit = (eFunctionSwitch_t)(1 << eEBASwitchIdx);
        retVal  = HEADGetEBASwitch(FunctionBit);
      }
    }
    else
    {
     retVal              = FALSE;
    }
  }
  return retVal;
}

/*************************************************************************************************************************
  Functionname:         HEADGetEBACodingIndex                                                                    */ /*!

  @brief                Returns the index of the current Coding

  @description          Calculates the index of the current coding based on the information out of the hypo. (DF: Driver Feature, OT: Object Type, OM: Object Movement)
                        If Hypothesis Parameter  is present then using dynamic property , movement  of the object is set.
                        Using Object movement,Driver Feature,Object Type coding index is calculated.

                        @startuml
                        Start
                            If(Is Hypothesis Parameter present?)then (No)
                            : Null function pointer error is updated;
                            Else (yes)
                            :setting the Object movement ;
                            If(check EBA Dynamic Properties type) then (Moving) 
                            :set object type as moving;
                            Else(stationary )
                            :set object type as stationary; 
                            Endif
                            :precalculated array index;
                            Endif
                            :return the error type; 
                        Stop
                        @enduml

  @return               eGDBError_t :GDB error type is returned

  @param[in]            pHyp       : the current Hypothesis.
  @param[in,out]        FctModsIdx : Index of the coding.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability     

  @author               Ayman Almalih | ayman.almalih@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADGetEBACodingIndex(HEADHypothesis_t const *pHyp, t_EBACodingParamFctModsIdx *FctModsIdx)
{
  eGDBError_t eError = GDB_ERROR_NONE;
  if(pHyp == NULL)
  {
    eError = GDB_ERROR_FUNC_POINTER_NULL;
  }
  else
  {
    const Hypothesis_t* plocalHyp   = pHyp->pHypothesis;
    eEBADynProp_t dynProp           = plocalHyp->eEBADynProp;
    eEBAObjectClass_t objClass      = plocalHyp->eEBAObjectClass;
    eEBAObjMovDir_t ObjectDirection = plocalHyp->eEBAObjMovDir;
    ObjMovement_t ObjectMov;
    Cod_ObjType_t Cod_ObjectType    = HEADConvEBAObjClass2CPARObjClass(objClass);
    DriverFeature_t DriverFeature   = HEADConvEBAMoVDir2DriverFeature(ObjectDirection);
    
    /* setting the Object movement */
    if (dynProp == EBADynProp_Mov)
    {
      ObjectMov = CPARObjMoving;
    }
    else if (dynProp == EBADynProp_Stat)
    {
      ObjectMov = CPARObjStat;
    }
    else
    {
      ObjectMov = CPARObjMoving; 
    }

    /* Calculation of the coding index:
    Driver Feature  DF:=3 (LONG=0, CROSS=1, ONC=2) [i]
    Object Type     OT:=4 (VEH=0,PED=1,CYCL=2,OBS=3) [j]
    Object          OM:=2 (MOV=0,STAT=1) [k]
    Coding index    M[i][j][k] = A[i*(OT*OM)+j*OM+k] */
    /*                                                           i          *           OT              *             OM             +                 j          *            OM             +          k        */
    *FctModsIdx = (t_EBACodingParamFctModsIdx) ( ( ( (uint32)DriverFeature) * HEAD_Coding_Object_Type_Nr*HEAD_Coding_Object_Mov_Nr ) + (( (uint32)Cod_ObjectType) *HEAD_Coding_Object_Mov_Nr) + (uint32)ObjectMov );
  }
  return eError;
}

/*************************************************************************************************************************
  Functionname:         HEADConvEBAObjClass2CPARObjClass                                                                 */ /*!

  @brief                Returns the current Object type

  @description          Returns the Object type "only Mapping" 
                        Eba object class is verified , If Eba object class is vehicle corresponding objetc type is assigned.

                        @startuml
                        Start
                            :setting the Coding Object type;
                            If(check object is vehile) then (yes)
                            :set object type as vechile;
                            Else if (check object is Pedestrian) then (yes)
                            :set object type as Pedestrian;
                            Else if (check object is cyclist) then (yes)
                            :set object type as cyclist;
                            Else if (check object is Obstacle) then (yes)
                            :set object type as cyclist;
                            Else (other than the this object type)
                            :set object type as vechile;
                            Endif       
                            :Return the object type;
                        Stop
                        @enduml
                    
  @return               Cod_ObjType_t  (CPARObjVeh, CPARObjPed, CPARObjCycl, CPARObjObst)

  @param[in]            objClass : Function Object Class for EBA

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability  

  @author               Ayman Almalih | ayman.almalih@continental-corporation.com
*************************************************************************************************************************/
static Cod_ObjType_t HEADConvEBAObjClass2CPARObjClass(eEBAObjectClass_t objClass)
{
  Cod_ObjType_t Cod_ObjectType;
  /* setting the Coding Object type */
  if (objClass == EBAObjectClass_Vehicle)
  {
    Cod_ObjectType = CPARObjVeh;
  }
  else if (objClass == EBAObjectClass_Pedestrian)
  {
    Cod_ObjectType = CPARObjPed;
  }
  else if (objClass == EBAObjectClass_Cyclist)
  {
    Cod_ObjectType = CPARObjCycl;
  }
  else if (objClass == EBAObjectClass_Obstacle)
  {
    Cod_ObjectType = CPARObjObst;
  }
  else
  {
    Cod_ObjectType = CPARObjVeh;
  }
  return Cod_ObjectType;
}

/*************************************************************************************************************************
  Functionname:         HEADConvEBAMoVDir2DriverFeature                                                                  */ /*!

  @brief                Returns the Driver feature

  @description          Driver feature is updated based on Eba  object moving direction.
                        If object is crossing, then corresponding driver feature Is updated.
                        If object is On coming , then corresponding driver feature Is updated. etc

                        @startuml
                        Start
                            :setting the Driver feature;
                            :moving direction of object;
                            note left
                            Longitudinal, Crossing and  Oncoming any one of this
                            parameter will be mapped
                            End note
                            :Return the DriverFeature;
                        Stop
                        @enduml

  @return               DriverFeature_t : Driver feature is returned

  @param[in]            ObjectDirection : object moving direction

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 

  @author               Ayman Almalih | ayman.almalih@continental-corporation.com
*************************************************************************************************************************/
static DriverFeature_t HEADConvEBAMoVDir2DriverFeature(eEBAObjMovDir_t ObjectDirection)
{
  DriverFeature_t DriverFeature;
  /* setting the Driver feature */
  if (ObjectDirection == EBAObjMovDir_DoT)
  {
    DriverFeature = CPARObjLong;
  }
  else if (ObjectDirection == EBAObjMovDir_Cross)
  {
    DriverFeature = CPARObjCross;
  }
  else if (ObjectDirection == EBAObjMovDir_Onco)
  {
    DriverFeature = CPARObjOnCom;
  }
  else
  {
    DriverFeature = CPARObjLong;
  }

  return DriverFeature;
}

/*************************************************************************************************************************
  Functionname:         HEADCodingInhibitionCheck                                                                         */ /*!

  @brief                Returns the InhibitionMask according to the Coding 

  @description          Checks object class and dynamic property and returns Inhibition-mask according to the Coding

                        @startuml
                        Start
                            If(checks for object Hypothesis availability) then (Yes)
                            :Stores the individual object hypothesis in to pointer;
                            If(checks for individual object Hypothesis availability) then (Yes)
                            :Stores Object and Dynamic Properties of Object and returns
                            Inbihibition Mask value according to Coding to disable that functionality;
                            Endif
                            Endif
                            If(checks for either status of EBA mainswitch, Object , Dynamic Properties availabilty or other than the no error ) then (Yes)
                            :Sets Inhibition mask bits to highest value, to
                            disable all functionalities;
                            else
                            if(check get EBA coding is equal to false)
                            : Inhibition mask bits or with Pre crash bits are updated;
                            note right
                            Warnings are related to Precrash,
                            Prefill1,Prefill2,HBA1,HBA2,Auto Brake1,
                            Auto Brake2,Auto Brake3, Dynamic Warning1,
                            Dynamic Warning2,Dynamic Warning3,Warning1,
                            Distance Warning2
                            End note
                            Else
                            : Sets Inhibition mask bits to highest value;
                            Endif
                            endif
                            :return updated error type;
                        Stop
                        @enduml

  @return               eGDBError_t : Error Code is returned

  @param[in]            pHyp : Pointer to current Hypothesis
  @param[in,out]        pInhibitionMask : Pointer to Inhibition Mask

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability         

  @author               Ayman Almalih | ayman.almalih@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADCodingInhibitionCheck(HEADHypothesis_t const *pHyp, HEADBitField_t *pInhibitionMask)
{
  eGDBError_t eError = GDB_ERROR_NONE;
  t_EBACodingParamFctModsIdx eEBACodingIdx = eEBACodingIdx_LongVehMov;
  eEBADynProp_t dynProp = EBADynProp_NotAvail;
  eEBAObjectClass_t objClass = EBAObjectClass_NotAvail;
  const eMainSwitch_t eMainSwitch = MEDIC_p_GetHeadInGeneric()->eMainSwitch;

  if(pHyp != NULL)
  {
    const Hypothesis_t* plocalHyp = pHyp->pHypothesis;
    if(plocalHyp != NULL)
    {
      dynProp  = plocalHyp->eEBADynProp;
      objClass = plocalHyp->eEBAObjectClass;
      eError = HEADGetEBACodingIndex(pHyp, &eEBACodingIdx);
    }
  }

  if((eMainSwitch == eMainSwitch_Inactive) || (dynProp == EBADynProp_NotAvail) 
    ||(objClass == EBAObjectClass_NotAvail) 
    ||(eError != GDB_ERROR_NONE)
    )
  {
    *pInhibitionMask = FPS_EBA_INH_ALL;
    eError = GDB_ERROR_UNKNOWN_TYPE;
  }
  else
  {
    (*pInhibitionMask) = ((HEADGetEBACoding(EBA_CODING_BIT_PRECRASH, eEBACodingIdx)   == FALSE))?                      /*!< Precrash */
          ((*pInhibitionMask)|FPS_EBA_INH_PRECRASH)                               : (*pInhibitionMask);
    (*pInhibitionMask) = ((HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx)   == FALSE))?                      /*!< Prefill1 */
          ((*pInhibitionMask)|FPS_EBA_INH_PRE_FILL)                               : (*pInhibitionMask);
 
    (*pInhibitionMask) = ((HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx)       == FALSE))?                      /*!< HBA1 */
          ((*pInhibitionMask)|FPS_EBA_INH_HBA_THRD)                                   : (*pInhibitionMask);
    (*pInhibitionMask) = ((HEADGetEBACoding(EBA_CODING_BIT_HBA2, eEBACodingIdx)       == FALSE))?                      /*!< HBA2 */
          ((*pInhibitionMask)|FPS_EBA_INH_HBA_TBRK)                                   : (*pInhibitionMask);
    (*pInhibitionMask) = ((HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx)   == FALSE) || (HEADGetEBASwitchHyp(Switch_BRK, pHyp)   == FALSE))?               /*!< Auto Brake1 */
          ((*pInhibitionMask)|FPS_EBA_INH_BRAKE_L1)                               : (*pInhibitionMask);  
    (*pInhibitionMask) = ((HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx)   == FALSE) || (HEADGetEBASwitchHyp(Switch_BRK, pHyp)   == FALSE))?               /*!< Auto Brake2 */
          ((*pInhibitionMask)|FPS_EBA_INH_BRAKE_L2)                               : (*pInhibitionMask);
    (*pInhibitionMask) = ((HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx)   == FALSE) || (HEADGetEBASwitchHyp(Switch_BRK, pHyp)   == FALSE))?               /*!< Auto Brake3 */
          ((*pInhibitionMask)|FPS_EBA_INH_BRAKE_L3)                               : (*pInhibitionMask);
    (*pInhibitionMask) = ((HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx)  == FALSE) || (HEADGetEBASwitchHyp(Switch_FCW1, pHyp)  == FALSE))?               /*!< Dynamic Warning1 */
          ((*pInhibitionMask)|FPS_EBA_INH_PRE_WARN)                              : (*pInhibitionMask);
    (*pInhibitionMask) = ((HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN2, eEBACodingIdx)  == FALSE) || (HEADGetEBASwitchHyp(Switch_FCW2, pHyp)  == FALSE))?               /*!< Dynamic Warning2 */
          ((*pInhibitionMask)|FPS_EBA_INH_ACU_WARN)                              : (*pInhibitionMask);
    (*pInhibitionMask) = ((HEADGetEBACoding(EBA_CODING_BIT_DIST_WARN1, eEBACodingIdx) == FALSE) || (HEADGetEBASwitchHyp(Switch_DW, pHyp)    == FALSE))?               /*!< Distance Warning1 */
          ((*pInhibitionMask)|FPS_EBA_INH_LAT_WARN)                             : (*pInhibitionMask);
  }
  return eError;
}

/**************************************************************************************************
  Functionname:         HEADCustomReadCodingParams                                              */ /*!
  
  @brief                Reads customer Coding Params
  
  @description          Custom specific coding parameters are updated.
                        Following are the few parametrs updated.
                        Low speed active bit, country specific bit,distance limit etc.

                        @startuml
                        Start
                            If (Is the EBA coding parameter and signal status valid?) then (yes)
                            :Set DEM coding parameters and signal status valid;
                            Note left 
                            EBA coding parameters are vehicle low speed, 
                            country variants and distance limit etc.
                            End note
                            Else (No)
                            If(check the EBA coding parameter) then (signal invalid)
                            :Set valid  DEM coding parameters;
                            Else (parameter invalid)
                            :Set valid DEM signal status;
                            Endif
                            Endif
                            :return the error type;
                        Stop
                        @enduml  

  @return                eGDBError_t  :GDB error type is returned

  @param[in,out]         void

  @c_switch_part         None
  @c_switch_full         @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
  
  @pre                   None
  @post                  None
  
  @InOutCorrelation      Not defined

  @testmethod            Test of output data (dynamic module test)

  @traceability 
 
  @author               Clemens Schnurr | Clemens.Schnurr@continental-corporation.com
*************************************************************************************************** */
static eGDBError_t HEADCustomReadCodingParams( void )
{
  eGDBError_t eError = GDB_ERROR_NONE;

  const CPAR_EBA_Parameters_t *const CPAR_EBA_Parameters = &(MEDIC_p_GetCPARFCTParameters()->EBA);
  const EBACodingParamGen_t CParamGen = CPAR_EBA_Parameters->EBACodingParamGen;
  
  if ((CPAR_EBA_Parameters->EBACodingParamValid != FALSE) && 
      (MEDIC_p_GetCPARFCTParameters()->sSigHeader.eSigStatus == AL_SIG_STATE_OK))
  {
    HEADCodingInfo.CodeGenLowSpeedBitActive               = ((CParamGen & EBA_CODING_GEN_LOW_SPEED)           > 0u) ? TRUE : FALSE;
    HEADCodingInfo.CodeGenCountryCodeAActive              = ((CParamGen & EBA_CODING_GEN_COUNTRY_A)           > 0u) ? TRUE : FALSE;
    HEADCodingInfo.CodeGenCountryCodeBActive              = ((CParamGen & EBA_CODING_GEN_COUNTRY_B)           > 0u) ? TRUE : FALSE;
    HEADCodingInfo.CodeGenIgnoreSelfCheckBitActive        = ((CParamGen & EBA_CODING_GEN_IGNR_SFTY_CHCKS)     > 0u) ? TRUE : FALSE;
    HEADCodingInfo.CodeGenDebugMessagesBitActive          = ((CParamGen & EBA_CODING_GEN_DEBUGMESSAGES)       > 0u) ? TRUE : FALSE;
    HEADCodingInfo.CodeGenDistanceLimitBitActive          = ((CParamGen & EBA_CODING_GEN_DISTANCELIMIT)       > 0u) ? TRUE : FALSE;
    HEADCodingInfo.CodeGenIgnoreActivationSwitch          = ((CParamGen & EBA_CODING_GEN_IGNORE_ACT_SWITCH)   > 0u) ? TRUE : FALSE;
    #if (MEDIC_CFG_USE_DEM)
    /*set DEM coding parameters valid*/
    MEDIC_v_SetDem(FCTVEH_DEM_STATIC, DEM_EVENT_STATUS_PASSED);
    #endif
  }
  else
  {
    if (CPAR_EBA_Parameters->EBACodingParamValid != FALSE)
    {
      #if (MEDIC_CFG_USE_DEM)
      /*set DEM coding parameters valid (but signal status is invalid)*/
      MEDIC_v_SetDem(FCTVEH_DEM_STATIC, DEM_EVENT_STATUS_PASSED);
      #endif
    }
    else
    {
      #if (MEDIC_CFG_USE_DEM)
      /*set DEM coding parameters invalid*/
      MEDIC_v_SetDem(FCTVEH_DEM_STATIC, DEM_EVENT_STATUS_FAILED);
      #endif
    }
    eError = GDB_ERROR_LOW_QUALITY;
  }
  return eError;
}

/*************************************************************************************************************************
  Functionname:         HEADCustomCoding                                                                            */ /*!

  @brief                applies custom coding 

  @description          CodingInfo

                        @startuml
                        Start
                            :Gets the Coding parameters from FCT module;
                            If(check for head module availability) then (Yes)
                            If (Checks coding parameters are other than no error type) then (yes)
                            : Assign default values to the invalid coding parameters;
                            Endif
                            If( Is the main switch  invalid?) than (Yes)
                            : update signal didn't have a sufficient quality to retswitch;
                            Endif
                            If(check for either retswitch or retcoding is no error type) then (No)
                            While(check for module is less than the max number of the module) is (Yes)
                            : set all modules to stop and error;
                            Endwhile (no)
                            : set HEAD to stop;
                            Else
                            If(check for either eba switch or eba coding is  false 
                            if coding index is long vehicle move and check for eba 
                            coding is false if coding index is long obstacle move) then (yes)
                            note right
                            Based on all module are checked
                            End note 
                            :degrade the late pre warn module;
                            Endif
                            endif
                            Else 
                            : update return type as null pointer error;
                            endif
                            :return the error type;
                        Stop
                        @enduml

  @return               eGDBError_t  :GDB error type is returned

  @param[in,out]        rgModules    : HEAD Module list array

  @glob_in              @ref MEDIC_p_GetHeadInGeneric()\n @ref HEADInputData
  @glob_out             @ref HEADCodingInfo

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADCustomCoding(struct HEADModule_t rgModules[])
{
  eGDBError_t eRet = GDB_ERROR_NONE;
  eGDBError_t eRetCoding = GDB_ERROR_NONE;
  eGDBError_t eRetSwitch = GDB_ERROR_NONE;
  const eMainSwitch_t     eMainSwitch     = MEDIC_p_GetHeadInGeneric()->eMainSwitch;
  if (rgModules != NULL)
  {
    HEADSPMCheck_t *pSPMRuleMinVel;

    /* In cases of invalid coding parameters assign default values*/
    eRetCoding = HEADCustomReadCodingParams();
    if (eRetCoding != GDB_ERROR_NONE)
    {
      HEADCodingInfo.CodeGenLowSpeedBitActive           = FALSE;
      HEADCodingInfo.CodeGenCountryCodeAActive          = FALSE;
      HEADCodingInfo.CodeGenCountryCodeBActive          = FALSE;
      HEADCodingInfo.CodeGenIgnoreSelfCheckBitActive    = FALSE;
      HEADCodingInfo.CodeGenDebugMessagesBitActive      = FALSE;
      HEADCodingInfo.CodeGenDistanceLimitBitActive      = FALSE;
      HEADCodingInfo.CodeGenIgnoreActivationSwitch      = FALSE;
    }

    if (eMainSwitch_Invalid == eMainSwitch)
    {
      eRetSwitch = GDB_ERROR_LOW_QUALITY;
    }

    if ((eRetSwitch != GDB_ERROR_NONE) || (eRetCoding != GDB_ERROR_NONE))
    {
      uint32 uModuleNr;
      eRet = GDB_ERROR_LOW_QUALITY;
      /*set all modules to stop and error*/
      for (uModuleNr = 0;uModuleNr < HEAD_AUTO_CFG_NO_MODULES ; ++uModuleNr)
      {
        rgModules[uModuleNr].eQoS           = HEADModuleQoS_DegradationStop;
        rgModules[uModuleNr].eReportedError = HEADModuleRepError_Critical;
      }
      /* set HEAD to stop */
      HEADSetOpMode(HEADOpMode_Stop);
    }
    else
    {
      /*  LatPreWarn  */
      if( (  (HEADGetEBASwitch(eEBASwitch_LongVehDW)  == FALSE) 
           ||(HEADGetEBACoding(EBA_CODING_BIT_DIST_WARN1, eEBACodingIdx_LongVehMov) == FALSE)
          )
        &&((HEADGetEBACoding(EBA_CODING_BIT_DIST_WARN1, eEBACodingIdx_LongObsMov) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_LatPreWarn);
      }

      /*  LatAcuteWarn  */
      if( (  (HEADGetEBASwitch(eEBASwitch_LongVehDW)  == FALSE) 
           ||(HEADGetEBACoding(EBA_CODING_BIT_DIST_WARN2, eEBACodingIdx_LongVehMov) == FALSE)
          )
        &&((HEADGetEBACoding(EBA_CODING_BIT_DIST_WARN2, eEBACodingIdx_LongObsMov) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_LatAcuteWarn);
      }

      /*  DynPreWarn  */
      if( (  (HEADGetEBASwitch(eEBASwitch_LongVehFCW1)  == FALSE) 
           ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_LongVehMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVehFCW1)  == FALSE) 
           ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_LongVehStat) == FALSE)
          )
        &&((HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_LongObsMov) == FALSE)
          )
        &&((HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_LongObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_DynPreWarn);
      }

      /*  DynAcuteWarn  */
      if( (  (HEADGetEBASwitch(eEBASwitch_LongVehFCW2)  == FALSE) 
           ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN2, eEBACodingIdx_LongVehMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVehFCW2)  == FALSE) 
           ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN2, eEBACodingIdx_LongVehStat) == FALSE)
          )
        &&((HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN2, eEBACodingIdx_LongObsMov) == FALSE)
          )
        &&((HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN2, eEBACodingIdx_LongObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_DynAcuteWarn);
      }

      /*  Prefill  */
      if( (  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_LongVehMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_LongVehStat) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_LongObsMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_LongObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_Prefill);
      }

      /*  Veh_AutoBrk1  */
      if(  (  (HEADGetEBASwitch(eEBASwitch_LongVehBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongVehMov) == FALSE)
            )
          &&(  (HEADGetEBASwitch(eEBASwitch_LongVehBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongVehStat) == FALSE)
            )
          &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongObsMov) == FALSE)
            )
          &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongObsStat) == FALSE)
            )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_Veh_AutoBrk1);
      }

      /*  Veh_AutoBrk2  */
      if(  (  (HEADGetEBASwitch(eEBASwitch_LongVehBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongVehMov) == FALSE)
            )
          &&(  (HEADGetEBASwitch(eEBASwitch_LongVehBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongVehStat) == FALSE)
            )
          &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongObsMov) == FALSE)
            )
          &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongObsStat) == FALSE)
            )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_Veh_AutoBrk2);
      }

      /*  Veh_AutoBrk3  */
      if(   (  (HEADGetEBASwitch(eEBASwitch_LongVehBRK)  == FALSE) 
              ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_LongVehMov) == FALSE)
            )
        &&  (  (HEADGetEBASwitch(eEBASwitch_LongVehBRK)  == FALSE) 
              ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_LongVehStat) == FALSE)
            )
        &&  (  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_LongObsMov) == FALSE)
            )
        &&  (  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_LongObsStat) == FALSE)
            )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_Veh_AutoBrk3);
      }

      /*  HBA_TA  */
      if( ( (HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx_LongVehMov) == FALSE)
          )
        &&((HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx_LongVehStat) == FALSE)
          )
        &&((HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx_LongObsMov) == FALSE)
          )
        &&((HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx_LongObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_HBA_TA);
      }

      /*  Ped_DynAcuteWarn  */
      if( (  (HEADGetEBASwitch(eEBASwitch_CrossVruFCW1)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_CrossPedMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_CrossVruFCW1)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_CrossPedStat) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_CrossVruFCW1)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_CrossCyclMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_CrossVruFCW1)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_CrossCyclStat) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_CrossObsMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_CrossObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn);
      }

      /*  CrossVru_Prefill  */
      if( (  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_CrossPedMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_CrossPedStat) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_CrossCyclMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_CrossCyclStat) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_CrossObsMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_CrossObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_CrossVru_Prefill);
      }

      /*  CrossVru_HBA  */
      if( (  (HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx_CrossPedMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx_CrossPedStat) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx_CrossCyclMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx_CrossCyclStat) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx_CrossObsMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_HBA1, eEBACodingIdx_CrossObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_CrossVru_HBA);
      }

      /*  CrossVru_PreBrk  */
      if( (  (HEADGetEBASwitch(eEBASwitch_CrossVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossPedMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_CrossVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossPedStat) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_CrossVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossCyclMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_CrossVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossCyclStat) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossObsMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_CrossVru_PreBrk);
      }

      /*  CrossVru_PreBrk2  */
      if( (  (HEADGetEBASwitch(eEBASwitch_CrossVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossPedMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_CrossVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossPedStat) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_CrossVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossCyclMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_CrossVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossCyclStat) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossObsMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_CrossVru_PreBrk2);
      }

      /*  LongVru_Prefill  */
      if( (  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_LongPedMov) == FALSE)
        )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_LongPedStat) == FALSE)
        )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_LongCyclMov) == FALSE)
        )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_PREFILL1, eEBACodingIdx_LongCyclStat) == FALSE)
        )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_LongVru_Prefill);
      }

      /*  LongVru_DynAcuteWarn  */
      if( (  (HEADGetEBASwitch(eEBASwitch_LongVruFCW1)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_LongPedMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVruFCW1)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_LongPedStat) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVruFCW1)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_LongCyclMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVruFCW1)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_DYN_WARN1, eEBACodingIdx_LongCyclStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn);
      }

      /*  LongVru_Brk1  */
      if( (  (HEADGetEBASwitch(eEBASwitch_LongVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongPedMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongPedStat) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongCyclMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongCyclStat) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongObsMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_LongVru_Brk1);
      }

      /*  LongVru_Brk2  */
      if( (  (HEADGetEBASwitch(eEBASwitch_LongVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongPedMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongPedStat) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongCyclMov) == FALSE)
          )
        &&(  (HEADGetEBASwitch(eEBASwitch_LongVruBRK)  == FALSE) 
            ||(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongCyclStat) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongObsMov) == FALSE)
          )
        &&(  (HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongObsStat) == FALSE)
          )
        )
      {
        HEADDegradateModule(HEAD_AUTOCODE_MOD_LongVru_Brk2);
      }

      /* remove low speed */
      pSPMRuleMinVel = HEADSPMGetRule(MEDIC_p_ModHEADInputData()->pSPMRules->rgSPMRules, HEAD_AUTOCODE_SPM_MinVelocity);
      if (HEADCodingInfo.CodeGenLowSpeedBitActive == FALSE)
      { 
        pSPMRuleMinVel->f16Value = HEADConvf32Tof16(HEAD_PAR_EGO_THRSHOLD_LOW_SPEED_CODING);
      }
    }
  }
  else
  {
    eRet = GDB_ERROR_POINTER_NULL;
  }

  return eRet;
} /* PRQA S 7004, 7012 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability */

/*************************************************************************************************************************
  Functionname:         HEADDegradateModule                                                                              */ /*!

  @brief                Degradate the current Module

  @description          shutdown module in case it is not already set to stop

                        @startuml
                        Start
                            :check for the status of Qos;
                            note left
                            Module is set to DegradationShutDown, if it has any
                            state greater than DegradationStop.
                            end note
                            :shutdown the module;
                            note left
                            Module will transit from active to wait
                            end note
                        Stop
                        @enduml

  @return               void

  @param[in]            moduleNr : number of the current module

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 

  @author               Ayman Almalih | ayman.almalih@continental-corporation.com
*************************************************************************************************************************/
static void HEADDegradateModule(const uint16 moduleNr)
{
  HEADModule_t *pModule = HEADGetModule(MEDIC_p_ModHEADInputData()->pModuleList, moduleNr);
  if (pModule->eQoS > HEADModuleQoS_DegradationStop)
  {
    /* shutdown module in case it is not already set to stop */
    pModule->eQoS = HEADModuleQoS_DegradationShutDown;
  }
}

/*************************************************************************************************************************
  Functionname:         HEADGetCustomCoding                                                                         */ /*!

  @brief                Get coding flags

  @description          Returns pointer of active coding info
                        @startuml
                        Start
                            : Gets active coding flags information;
                        Note left
                            Returns pointer of active HEADcoding information
                        End note
                        Stop
                        @enduml

  @return               HEADCustomCodingInfo_t : Pointer to HEAD custom coding info

  @param[in]            Void

  @glob_in              @ref HEADCodingInfo
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability         

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
const HEADCustomCodingInfo_t *HEADGetCustomCoding(void)
{
  return(&HEADCodingInfo);
}

#endif /* #if MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* !(MEDIC_CFG_HEAD20) */
/**@}*/ 
