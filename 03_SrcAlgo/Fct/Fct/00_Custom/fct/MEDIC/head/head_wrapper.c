/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_wrapper.c

DESCRIPTION:               External Header of the HEAD component

AUTHOR:                    $Author: uia92763 $

CREATION DATE:             $Date: 2020/09/02 05:36:45CEST $

VERSION:                   $Revision: 1.4.4.19 $

LEGACY VERSION:            1.157
 
**************************************************************************** */

/**
@defgroup head_wrapper HEAD_WRAPPER
@ingroup Medic_head
@{ **/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_HEAD20)
/*string.h for memset*/
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */
#include "head/head_int.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
/*! @brief       ACCEL_ARRAY_SIZE
    @general     Accleration Array Size
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     4u
    @unit        SI-unit
    
       */
#define ACCEL_ARRAY_SIZE 4u

/* Static checks to avoid allocation errors*/
#if HEAD_AUTO_CFG_NO_MODULES > HEAD_MTS_MAX_MODULES
#error Number of configured head modules exceeds mts buffer capacities
#endif

#if HEAD_AUTO_CFG_NO_SPM_RULES > HEADMTSSPMRulesMax
#error Number of configured spm rules exceeds mts buffer capacities
#endif

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

/*These two variables are used to store the ego velocity when a braking module turns active
  or if the braking cascade starts (exact implementation when to write the ego velocity can be
  customized in HEADCustomOutput).
  The output function "head_out_ped_prebrake_function" uses HostSpeedLastPedBrakeStart, while 
  HostSpeedLastBrakeStart is used in "head_out_prebrake_function" and "head_out_fullbrake_function".
  Thereby the speed reduction can be calculated and if it exceeds the maximum allowed value,
  the output function forces the respective module to go to wait.*/
/*!  @cond Doxygen_Suppress */
fVelocity_t HostSpeedLastBrakeStart=0;     /*Store the ego velocity when a braking module turns active*/
fVelocity_t HostSpeedLastPedBrakeStart=0;  /*Store the ego velocity when a braking module turns active because of pedestrian cross*/


boolean          bHEADInitInputOutputDone = FALSE; /*PRQA S 3408*/ /* date: 2020-8-26, reviewer:Luoxi Zou reason:variable decl is in a .c file and cant be moved to .h file*/    /* static variable to store information if initialization has been done in the last cycle */
static HEADModuleList_t        HEADModuleList;     /* Define the module list of the HEAD*/
static HEADMTSStaticData_t     HEADMTSStaticData;  /* Write and update the head parameter data to MTS*/

float32        fStandstillActiveTime;        /*Define the stand still active time */
float32        fSteeringWheelBrakeStart;     /*Store the steering wheel angle at the start of braking event*/ 
float32        fGasPedalPosBrakeStart;       /*Store the gas pedal position at the start of braking event*/
boolean        bBrakeStatValuesValid;        /*Define the Brake event status */
boolean        bHEADDeactivationStandStill;  /*Define deactivation stand still status*/
/*! @endcond */

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
/*!  @cond Doxygen_Suppress */
static eGDBError_t HEADCustomOutput( eGDBError_t error );
/*! @endcond */
static void HEADInitGlobals(void);
static void HEADCustomModuleDeactivation( void );
static void HEADCustomInhibitionCheck(HEADHypothesis_t const *pHyp, HEADBitField_t *pInhibitionMask, eGDBError_t* pError);

/*************************************************************************************************************************
  Functionname:         HEADInitGlobals                                                                             */ /*!

  @brief                Initializes all global variables that are created in head_wrapper

  @description          The function initializes all global variables that are created in head_wrapper 

  @return               void

  @param[in]            void

  @glob_in              None
  @glob_out             @ref HostSpeedLastBrakeStart \n         @ref HostSpeedLastPedBrakeStart

  @c_switch_part        None
  @c_switch_full        None

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static void HEADInitGlobals(void)
{
  HostSpeedLastBrakeStart = 0;
  HostSpeedLastPedBrakeStart = 0;
}

/*************************************************************************************************************************
  Functionname:         HEADInit                                                                                     */ /*!

  @brief                Initializes all HEAD variables at the beginning of the program run

  @description          The function initializes all values from the HEAD component
                        @startuml
                        Start
                            :Initialize HEAD Internal Data;
                        Note right:Initialize MTS date Structure \nand Head module list.
                            :Initialize HEAD Input Data;
                        Note left:Initialize HEAD input data structure
                            :Initialize HEAD Output Data;
                        Note right:Initialize all HEAD Custom Data output \nto default value.
                            :Initialize HEAD MTS Output Data;
                        Note left:Initialize HEAD MTS Custom Data output.
                            :Initialize Variables related \nto speed reduction;
                            :Setup Input Hypothesis;
                        Note right
                            ->Update Input Hypothesis List.
                            ->Update HEAD Input Date related to CD Hypothesis 
                              and total number of HEAD Hypothesis.
                        End note
                            :Initialize custom System fuction;
                        Note left:Initialize if the custom System fuction \nSwitched is ON.
                            :Initialize variables related \nto standstill function;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error.

  @param[in]            void

  @glob_in              bHEADInitialized : Bool variable to indicate whether the HEAD is Initialized or not.
  @glob_out             None

  @c_switch_part        @ref HEAD_USE_CUSTOM_SYSTEMFUNCTION
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None 
  @post                 None  

  @InOutCorrelation     Not defined 
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
/*PRQA S 1505 1*//*HEADInit is also called by simulation functions*/
eGDBError_t HEADInit( void )
{
  eGDBError_t retValue = GDB_ERROR_NONE;

  bHEADInitialized            = FALSE;

  /* Initialise HEAD internal data */
  retValue = HEADInitialize(&HEADMTSStaticData, &HEADModuleList);

  /* Initialise HEAD input data */
  retValue = HEADInitInput(&HEADModuleList, MEDIC_CYCLE_TIME);

  /* Initailise HEAD output data */
  retValue = HEADInitOutput(); 
 
  /* Initialise HEADMTSCustHypData */
  HEADMTSCustomInit(); 

  /* Initializes all global variables that are created in head_wrapper.c */
  HEADInitGlobals();

  /* --- hypothesis --- */
  retValue = HEADSetupInputHypRef();

  #if defined (HEAD_USE_CUSTOM_SYSTEMFUNCTION) &&(HEAD_USE_CUSTOM_SYSTEMFUNCTION == MEDIC_ON)
  HEADInit_CustSysFunction();
  #endif

  /* initialize standstill relevant variables */
  bHEADDeactivationStandStill     = FALSE;
  bBrakeStatValuesValid           = FALSE;
  fSteeringWheelBrakeStart        = 0;
  fGasPedalPosBrakeStart          = 0;
  fStandstillActiveTime           = HEAD_PAR_MAX_OBS_TIME;

  return (retValue);
}

/*************************************************************************************************************************
  Functionname:         HEADUseReInit                                                                        */ /*!

  @brief                The function handles reinitialization of the head component

  @description          The function handles reinitialization of the head component
                        @startuml
                        Start
                            :Initialize Modules;
                        Note right:Initialize: \nstate machine function and \nCustom output functions
                            :Initialize Output values;
                        Note left:Initialize all HEAD Variables
                        Stop
                        @enduml  

  @return               void

  @param[in]            void

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
void HEADUseReInit(void)
{
  (void) HEADReInit(MEDIC_p_ModHEADInputData(), &HEADModuleList); /* Initialize modules */
  (void) HEADInit(); /* Initialize all output values */
}

/*************************************************************************************************************************
  Functionname:         HEADSetOpMode                                                                        */ /*!

  @brief                The function Set the HEAD operation mode

  @description          The function set the HEAD external operation mode
                        @startuml
                        Start
                            :Set Operation Mode;
                        Note right:Set HEAD external operation mode
                        Stop
                        @enduml
          
  @return               void

  @param[in]            OpMode : Enum variable holds external operation mode

  @glob_in              None
  @glob_out             @ref HEADInputData : HEAD input Data

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
void HEADSetOpMode(eHEADOpMode_t OpMode)
{
  MEDIC_p_ModHEADInputData()->eOpMode = OpMode;
}

/*************************************************************************************************************************
  Functionname:         HEADProcess                                                                                 */ /*!

  @brief                The function handles the HEAD wrapper

  @description          The function handles the HEAD wrapper
                        The criticality of the states is:
                        |           State                 | Criticality|
                        |:--------------------------------|:-----------|
                        | COMP_STATE_PERMANENT_ERROR:     |     6      |
                        | COMP_STATE_TEMPORARY_ERROR:     |     5      |
                        | COMP_STATE_NOT_RUNNING:         |     4      |
                        | COMP_STATE_NOT_INITIALIZED:     |     3      |
                        | COMP_STATE_REDUCED_AVAILABILITY:|     2      |
                        | COMP_STATE_RUNNING:             |     1      |
                        | COMP_STATE_SUCCESS:             |     0      |

                        @startuml
                        Start
                            :Get the medic subcomponent; 
                            :Clear MTS Date;
                        Note right:Clear MTS related Data
                        if (Is HEAD Initialized?) then (No)
                            :Set HEAD state as not initialized;
                        endif
                        if (Is HEAD state normal running?) then (yes)
                                :Get Input Date;
                            Note left:collect input data from other modules
                                :Run SPM Rules check;
                            Note left:Run SPM Rules check and \nset modules to desired state.
                                :Run Custom Coding;
                            Note left:Reads custom coding information and based on that \nit will overwrite some information from SPM.
                                :Update Auto Code parameters;
                            Note left:update Auto code Parameters \nduring runtime.
                                :Evaluate Custom Module Deactivation;
                            Note left:External deactivation conditions for HEAD-modules are evaluated.
                                :Run HEAD;
                            Note left
                                ->Use external opmode to override the module opmodes.
                                ->For each module call the main handler function and the output function.
                            End note
                                :Send HEAD Config to MTS;
                            Note left:Write HEAD configuration to MTS
                                :Initialize HEAD custom output;
                                :HEAD Out Arbitration;
                            Note left: Run Arbitration for custom output
                                :Set Custom Data output;
                            Note left: writes out custom Data
                                :Freeze MTS Data;
                            Note left:writes out data to MTS
                        else (no)
                                :Initialize HEAD;
                            Note right: Initialize all HEAD Variables
                        Endif
                            :Set HEAD Version \n Sets the desired subcomponents to the 
                            desired state;
                        Stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error.

  @param[in]            fCycleTime : The function cycle time

  @glob_in              None
  @glob_out             @ref HEADState : Enum variable to indicate HEAD State

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com

*************************************************************************************************************************/
eGDBError_t HEADProcess( const float32 fCycleTime )
{
  eGDBError_t error    = GDB_ERROR_NONE;

  *MEDIC_p_ModHEADState() = MEDIC_e_GetSubCompState(MEDIC_SUB_COMP_HEAD);

  (void)memset(MEDIC_p_ModHEADMTSData()             , 0u, (uint32)sizeof(HEADMTSData_t));
  (void)memset(MEDIC_p_ModHEADMTSExtData()          , 0u, (uint32)sizeof(HEADMTSSpecificData_t));
  (void)memset(MEDIC_p_ModHEADMTSCodedInhibition()  , 0u, (uint32)sizeof(HEADMTSCodedInhibition_t));
  (void)memset(MEDIC_p_ModHEADMTSConditionsOKTimer(), 0u, (uint32)sizeof(HEADMTSConditionsOKTimer_t));
  (void)memset(MEDIC_p_ModHEADMTSModuleCommonOut()  , 0u, (uint32)sizeof(HEADMTSModuleCommonOut_t));

  if(bHEADInitialized == FALSE)
  {
    *MEDIC_p_ModHEADState() = COMP_STATE_NOT_INITIALIZED;
  }

  switch (*MEDIC_p_ModHEADState())
  {
  case COMP_STATE_RUNNING:
    /*collect input data*/
    HEADGetInputData(fCycleTime);

    /* ------ run SPM ----- */
    error = HEADSPMRunCheck(MEDIC_p_ModHEADInputData()->pSPMRules, &HEADModuleList, MEDIC_p_GetHEADInputData()->fCycleTime);

    /* set custom coding information (after SPM, because it'll overwrite some information from SPM)*/
    error = HEADCustomCoding(HEADModuleList.rgModules);


    /* ------ update parameters ------ */
    error = HEADAutoCodeUpdateParams();

    /* Calculate Custom Module Deactivation Conditions */
    HEADCustomModuleDeactivation();

    /* ------ run HEAD ----- */
    /* leave as an example how to use extra input values*/
    error = HEADRun(MEDIC_p_GetHEADInputData(), 
                    (void *)(&HEADExtraInputValueList), 
                    &HEADMTSSendExtraInputSignals,
                    MEDIC_p_ModHEADMTSData(),
                    &HEADMTSStaticData,
                    MEDIC_p_ModHEADMTSModuleCommonOut(),
                    &(MEDIC_p_ModHEADInputData()->uiCurrentCycle));
    
    /*write head config to MTS*/
    (void) HEADSendCfgToMTS(&HEADMTSStaticData, &(MEDIC_p_ModHEADMTSData()->sMTSCfgData));
    /*Init custom output every cycle*/
    HEADCustomOutputInit();
    /* arbitrate outputfunctions */
    error = HEADOutArbitration();
    /* write date to output interface (VDATA, RTE etc.) */
    error = HEADCustomOutputSet();

    /* MTS data freeze */
    (void)HEADCustomMTSFreezeData(MEDIC_p_ModHEADMTSExtData(), 
                            MEDIC_p_ModHEADMTSCodedInhibition(), 
                            MEDIC_p_ModHEADMTSConditionsOKTimer(), 
                            MEDIC_p_ModHEADMTSModuleCommonOut(), 
                            MEDIC_p_ModHEADMTSData(), 
                            MEDIC_p_GetHEADInputData()); 
    break;
  case COMP_STATE_NOT_INITIALIZED:
  default:
    error = HEADInit();
    #if defined (HEAD_USE_CUSTOM_SYSTEMFUNCTION) &&(HEAD_USE_CUSTOM_SYSTEMFUNCTION == MEDIC_ON)
    HEADInit_CustSysFunction();
    #endif
    break;
  }

  MEDIC_p_ModHeadOutCustom()->uiVersionNumber = FCT_HEAD_OUTPUT_CUSTOM_INTFVER;
  MEDIC_v_SetSubComponentStates(MEDIC_SUB_COMP_HEAD, *MEDIC_p_ModHEADState());
  return error;
}

/* *************************************** custom functions ******************************************** */

/*************************************************************************************************************************
  Functionname:         CalibrationFunction                                                                        */ /*!

  @brief                The function makes it possible to change parameters while running

  @description          The function makes it possible to change parameters while running
                        @startuml
                        Start
                        If(Is the Parameter ID?) then (Latent Pre-warning)
                            : Set parameter Float type as float32;
                            : Set the default value Correspond to Latent Pre-warning;
                            : Set Number of Rows as Number of Table entries for
                            Distance over velocity in Module latent pre-warning;
                            If (Is Country Code A Active) then (No)
                                :Update the table parameter with country0/Early 
                                object distance over velocity Table;
                            Else
                                :Update the table parameter with country1/Early 
                                object distance over velocity Table;
                            endif
                        elseif (Is the Parameter ID?) then (Latent Acute-warning)
                            : Set parameter Float type as float32;
                            : Set the default value Correspond to Latent Acute-warning;
                            : Set Number of Rows as Number of Table entries for
                            Distance over velocity in Module latent Acute-warning;
                            If (Is Country Code A Active) then (No)
                                :Update the table parameter with country0/late 
                                object distance over velocity Table;
                            Else
                                :Update the table parameter with country1/late 
                                object distance over velocity Table;
                            endif
                        Elseif (Is the Parameter ID?) then (Pre Brake Safety Distance)
                            If () 
                                partition Configuration_Switch_to_enable_ignoring_distance_safety_check {
                                if (Ignore Self Check == True) then (yes)
                                :Update the Scalar Parameter with Maximum allowed longitudinal object distance;
                                else
                                :Update the Scalar Parameter with Safety Distance value;
                                Note 
                                Safety Distance should be within the Maximum
                                allowed longitudinal object distance range.
                                End note
                                endif
                                }
                            Else
                                :Update the Scalar Parameter with Safety Distance value;
                                Note 
                                Safety Distance should be within the Maximum
                                allowed longitudinal object distance range.
                                End note
                            endif
                        Else
                            :Return Error;
                        endif
                        stop
                        @enduml

  @return               void

  @param[in]            pParameter : pointer to a parameter
  @param[in]            uiParID : ID of the external parameter -> to be able to set the parameter to a new value

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
eGDBError_t CalibrationFunction(HEADParameterEmpty_t *pParameter, uint32 uiParID)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  void *pPara = pParameter;

  /* change parameters for latent warning factors depending on country code */
  switch(uiParID)
  {
    case HEAD_PARID_LATPRE_DIST_VELO:
      /* Modify PreLatent early object distance over velocity curve */
      ((HEADParameterTable_t *)pPara)->eTableFloatType = HEADParameterTableFloatType_f32;
      ((HEADParameterTable_t *)pPara)->f16DefaultValue = HEADConvf32Tof16(LAT_PRE_DIST_OVER_VELOCITY_DEF_VELO);
      ((HEADParameterTable_t *)pPara)->uiNrOfTableRows = LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS;

      if (HEADCodingInfo.CodeGenCountryCodeAActive == 0u)
      {
        ((HEADParameterTable_t *)pPara)->pTable = (const void *) LatPreDistVel_Cntr0;
      }
      else
      {
        ((HEADParameterTable_t *)pPara)->pTable = (const void *) LatPreDistVel_Cntr1;
      }
      break;
     
    case HEAD_PARID_LATACUTE_DIST_VELO:
      /* Modify PreLatent late object distance over velocity curve */
      ((HEADParameterTable_t *)pPara)->eTableFloatType = HEADParameterTableFloatType_f32;
      ((HEADParameterTable_t *)pPara)->f16DefaultValue = HEADConvf32Tof16(LAT_ACUTE_DIST_OVER_VELOCITY_DEF_VELO);
      ((HEADParameterTable_t *)pPara)->uiNrOfTableRows = LAT_ACUTE_DIST_OVER_VELOCITY_TAB_POINTS;

      if(HEADCodingInfo.CodeGenCountryCodeAActive == 0u)
      {
        ((HEADParameterTable_t *)pPara)->pTable = (const void *) LatAcuteDistVel_Cntr0;
      }
      else
      {
        ((HEADParameterTable_t *)pPara)->pTable = (const void *) LatAcuteDistVel_Cntr1;
      }
      break;

    case HEAD_PARID_PREBRK_SAFETY_DIST:
      #if (MEDIC_CFG_EBA_HEAD_IGNR_SFTY_CHECK)
      if(HEADCodingInfo.CodeGenIgnoreSelfCheckBitActive != FALSE)
      {
        ((HEADParameterScalar_t *)pPara)->f16RawValue = HEADConvf32Tof16(HEAD_PAR_MAX_BRAKE_DISTANCE);
      }
      else
      {
        ((HEADParameterScalar_t *)pPara)->f16RawValue = HEADConvf32Tof16(MIN_FLOAT(MEDIC_p_ModHEADInputData()->pInputValueList->SafeObjDistSfty.uValue.fValue,HEAD_PAR_MAX_BRAKE_DISTANCE));
      }
      #else
      ((HEADParameterScalar_t *)pPara)->f16RawValue = HEADConvf32Tof16(MIN_FLOAT(MEDIC_p_ModHEADInputData()->pInputValueList->SafeObjDistSfty.uValue.fValue,HEAD_PAR_MAX_BRAKE_DISTANCE));
      #endif
      break;
   
   default:
     eRetValue = GDB_ERROR_FILTER_DOESNT_MATCH;
     break;
  }
  return eRetValue;
}

/*************************************************************************************************************************
  Functionname:         CalibSensorFusion                                                                           */ /*!

  @brief                The function makes it possible to change parameters while running

  @description          The function makes it possible to change parameters while running
                        @startuml
                        Start
                        :Set Error as None;
                        Partition 2ND_Sensor_Enabled{
                        :Get parameter;
                        If ((CodingInfo_SwitchBrakeLvl2 == FALSE) &&  
                         (CodingInfo_SwitchBrakeLvl1 != FALSE)) then (yes)
                            : Use lowered parameter values for ttx;
                        Endif
                        If(Is ParamID Valid?) then (valid)
                            :change parameter value for warning factors 
                            Depending on ParameterID;
                        Else (not Valid)
                            :Set Error as filter function doesn't match any resul;
                        endif
                        }
                        :Return Error;
                        stop
                        @enduml
          
  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns filter function mismatch error.

  @param[in]            pParameter : pointer to a parameter
  @param[in]            uiParID : ID of the external parameter -> to be able to set the parameter to a new value

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t CalibSensorFusion(HEADParameterEmpty_t * pParameter, uint32 uiParID)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;
  #if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
  HEADParameterScalar_t *pPara = (HEADParameterScalar_t *)((void *)pParameter);
  uint32 idxParVar = 0uL;

  if ( (HEADCodingInfo.SwitchVclBrakeL2 == FALSE)  /* iBrake conding active */
     &&(HEADCodingInfo.SwitchVclBrakeL1 != FALSE)
     )
  {
    /* Use lowered parameter values for ttx */
    idxParVar = 1uL;
  }

  /* change parameters for latent warning factors depending on country code */
  switch(uiParID)
  {
    case HEAD_PARID_DYNPRE_TTBPRE_EARLY_STAT:
      pPara->f16RawValue = HEADConvf32Tof16(HEAD_PAR_DYNPRE_TTBPRE_EARLY_STAT[idxParVar]);
      break;
    case HEAD_PARID_DYNPRE_TTBPRE_LATE_STAT:
      pPara->f16RawValue = HEADConvf32Tof16(HEAD_PAR_DYNPRE_TTBPRE_LATE_STAT[idxParVar]);
      break;
    case HEAD_PARID_DYNPRE_TTSPRE_EARLY:
      pPara->f16RawValue = HEADConvf32Tof16(HEAD_PAR_DYNPRE_TTSPRE_EARLY[idxParVar]);
      break;
    case HEAD_PARID_DYNPRE_TTSPRE_LATE:
      pPara->f16RawValue = HEADConvf32Tof16(HEAD_PAR_DYNPRE_TTSPRE_LATE[idxParVar]);
      break;
    case HEAD_PARID_DYNACUTE_TTBACUTE_STAT:
      pPara->f16RawValue = HEADConvf32Tof16(HEAD_PAR_DYNACUTE_TTBACUTE_STAT[idxParVar]);
      break;
    case HEAD_PARID_DYNACUTE_TTSACUTE:
      pPara->f16RawValue = HEADConvf32Tof16(HEAD_PAR_DYNACUTE_TTSACUTE[idxParVar]);
      break;
    default:
      eRetValue = GDB_ERROR_FILTER_DOESNT_MATCH;
      break;
  }
  #else
  _PARAM_UNUSED(pParameter);
  _PARAM_UNUSED(uiParID);
  #endif
  return eRetValue;
}

/*************************************************************************************************************************
  Functionname:         HEADMTSSendExtraInputSignals                                                                */ /*!

  @brief                Freeze additional input signals
  
  @description          Writing HEAD input signal to MTS
                        @startuml
                        Start
                            :Send HEADMTS Input Signal;
                        Note right:Writing HEAD input signal to MTS 
                        stop
                        @enduml

  @return               eGDBError_t : GDB_ERROR_NONE is returned if no error, else returns forwarded Error.

  @param[in,out]        pExtraValueList : Pointer to Extra Value List
  @param[in,out]        pMTSInputSignalList : Pointer to MTS Input signal List
  @param[in,out]        uiStartNr : Start of MTS Signal Number

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None 
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (Dynamic module test)

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
*************************************************************************************************************************/
/*PRQA S 1505 1*//*HEADMTSSendExtraInputSignals is also called by external functions*/
eGDBError_t HEADMTSSendExtraInputSignals(const void *pExtraValueList, HEADMTSInputSignalList_t *pMTSInputSignalList, uint8 uiStartNr)
{

  eGDBError_t retValue = GDB_ERROR_NONE;

  HEADMTSSendInputSignal(&((const HEADExtraInputValueList_t *)pExtraValueList)->ExtPreBrakeSetting, 
                                                      pMTSInputSignalList, uiStartNr, eHEADMTSInSigIdent_ExtPreBrakeSetting, &retValue );
  uiStartNr++;
  HEADMTSSendInputSignal(&((const HEADExtraInputValueList_t *)pExtraValueList)->DIMInputsValid,
                          pMTSInputSignalList, uiStartNr , eHEADMTSInSigIdent_DIMInputsValid, &retValue );

  return retValue;
}


#if defined (HEAD_USE_DEBUG_INTERFACE)
/*************************************************************************************************************************
  Functionname:         HEADDbgGetModuleList                                                                         */ /*!

  @brief                Head module list 
  
  @description          Get Head module list 
                        @startuml
                        Start
                            :Send HEAD Module list;
                        Note right:Returns  pointer to the array of head modules 
                        stop
                        @enduml
    
  @return               HEADModuleList_t : Address of modulelist  

  @param[in]            void 
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None 
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n @ref HEAD_USE_DEBUG_INTERFACE

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (Dynamic module test)

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
*************************************************************************************************************************/
const HEADModuleList_t *HEADDbgGetModuleList(void)
{
  return(&HEADModuleList);
}

/*************************************************************************************************************************
  Functionname:         HEADDbgGetInputData                                                                         */ /*!

  @brief                HBA module output function
  
  @description          Get Head Input data 
                        @startuml
                        Start
                            :Returns main HeadInput Data structure;
                        stop
                        @enduml

  @return               HEADInputData_t : Address of HEAD Input data

  @param[in]            void

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION \n @ref HEAD_USE_DEBUG_INTERFACE

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (Dynamic module test)

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
*************************************************************************************************************************/
const struct HEADInputData_t *HEADDbgGetInputData(void)
{
  return(MEDIC_p_GetHEADInputData());
}
#endif // HEAD_USE_DEBUG_INTERFACE

/*************************************************************************************************************************
  Functionname:         HEADCustomModuleDeactivation                                                                */ /*!

  @brief                External deactivation conditions for HEAD-modules are evaluated

  @description          External deactivation conditions for HEAD-modules are evaluated
  
                        @startuml
                        Start
                            : Initialize deactivation Boolean;
                            If (check for stand still active time less than zero) then (Yes)
                            : deactivation Boolean enabled;
                            Endif
                            If (check for Driver braking status is active) then (Yes)

                            : Deactivate autonomous braking ;
                            Endif
                            If(check for status of the steering wheel angle is position) then (active)
                            : Deactivate autonomous braking ;
                            endif
                            : Deactivate autonomous braking depends on Gas Pedal move;
                            : Max Acceleration Pedal Position;
                            : Detection of kick down;
                        stop
                        @enduml

  @return               void

  @param[in]            void

  @glob_in              @ref fGasPedalPosBrakeStart\n @ref fSteeringWheelBrakeStart\n @ref fStandstillActiveTime 
  @glob_out             @ref bHEADDeactivationStandStill\n @ref bBrakeStatValuesValid

  @c_switch_part        @ref HEAD_STANDSTILL_DEACT_USE_BRAKE\n @ref HEAD_STANDSTILL_DEACT_USE_STEER_ANGLE_MOVE
                        @ref HEAD_STANDSTILL_DEACT_USE_GAS_PEDAL_MOVE @ref HEAD_STANDSTILL_DEACT_USE_GAS_PEDAL_POS
                        @ref HEAD_STANDSTILL_DEACT_USE_KICK_DOWN @ref MEDIC_CFG_VEH_SIG_INPUT
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None    
  @post                 None
  
  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision

  @author               Mohamed Abdelkarim | mohamed.abdelkarim@continental-corporation.com 
*************************************************************************************************************************/
static void HEADCustomModuleDeactivation( void )
{
  float32 fSteeringWheelMove = 0;
  float32 fGasPedalMove = 0;

  /* Initialize deactivation boolean */
  bHEADDeactivationStandStill = FALSE;

  /* Condition 1: Max Time for stillstand activation */
  if (fStandstillActiveTime <= 0)
  {
    bHEADDeactivationStandStill = TRUE;
  }

  /* Condition 2: Deactivate autonomous braking if driver stops pressing the brake pedal */
  #if (HEAD_STANDSTILL_DEACT_USE_BRAKE)
  if ((MEDIC_p_GetDIMInGeneric()->eDriverBraking == eFCT_STATE_SIG_ACTIVE))
  {
    bHEADDeactivationStandStill = TRUE;
  }
  #endif

  /* Condition 3: Deactivate autonomous braking on steering wheel angle */
  #if (HEAD_STANDSTILL_DEACT_USE_STEER_ANGLE_MOVE)
  if (  (MEDIC_p_GetDIMInGeneric()->eSteeringWheelAngleStat == DIMInputSignalState_OK)
     && (bBrakeStatValuesValid == TRUE) )
  {
    fSteeringWheelMove = (MEDIC_p_GetDIMInGeneric()->fSteeringWheelAngle - fSteeringWheelBrakeStart);
    if ( fABS(fSteeringWheelMove) > HEAD_PAR_STANDSTILL_MAX_STEER_WHEEL_MOVE )
    {
      bHEADDeactivationStandStill = TRUE;
    }
  }
  #endif

  /* Condition 4: Deactivate autonomous braking on Gas Pedal move */
  #if (HEAD_STANDSTILL_DEACT_USE_GAS_PEDAL_MOVE)
  if ( (MEDIC_p_GetDIMInGeneric()->eAccelPadelStat == DIMInputSignalState_OK)
    && (bBrakeStatValuesValid == TRUE) )
  {
    fGasPedalMove = (MEDIC_p_GetDIMInGeneric()->fAccelPedalPos - fGasPedalPosBrakeStart);
    if ( fGasPedalMove > HEAD_PAR_STANDSTILL_MAX_GAS_PEDAL_MOVE )
    {
      bHEADDeactivationStandStill = TRUE;
    }
  }
  #endif

  /* Condition 5: Max Acc Pedal Position */
  #if (HEAD_STANDSTILL_DEACT_USE_GAS_PEDAL_POS)
  if (MEDIC_p_GetDIMInGeneric()->eAccelPadelStat == DIMInputSignalState_OK)
  {
    if (MEDIC_p_GetDIMInGeneric()->fAccelPedalPos >= HEAD_PAR_STANDSTILL_MAX_ACC_PEDAL_POS) 
    {
      bHEADDeactivationStandStill = TRUE;
    }
  }
  #endif

  /* Condition 6: KickDown */
  #if (HEAD_STANDSTILL_DEACT_USE_KICK_DOWN) && (MEDIC_CFG_VEH_SIG_INPUT)
  if (MEDIC_p_GetVehSig()->VehSigAdd.KickDown == TRUE)
  {
    bHEADDeactivationStandStill = TRUE;
  }
  #endif
}

/*************************************************************************************************************************
  Functionname:         HEADInhibitionCheck                                                                         */ /*!

  @brief                Returns the InhibitionMask based on the Coding as well as special custom requirements

  @description          The following steps are executed in order to determine the inhibition mask:
                            1- Checks object class and dynamic property and determine the Inhibition-mask according to the Coding
                            2- The determined Inhibition mask is manipulated based on custom logic by calling the function HEADCustomInhibitionCheck

                        @startuml
                        Start
                            #orange:Get the InhibitionMask based on the coding
                            <b>HEADCodingInhibitionCheck</b> >
                            #orange:Modify the InhibitionMask based on cutom logic
                            <b>HEADCustomInhibitionCheck</b> >
                        stop
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

  @traceability         Design Decision

  @author               Mohamed Abdelkarim
*************************************************************************************************************************/
eGDBError_t HEADInhibitionCheck(HEADHypothesis_t const *pHyp, HEADBitField_t *pInhibitionMask)
{
  eGDBError_t                 eError = GDB_ERROR_NONE;

  /* Get the InhibitionMask based on the coding */
  eError = HEADCodingInhibitionCheck(pHyp, pInhibitionMask);
  
  /* Modify the InhibitionMask based on cutom logic */
  HEADCustomInhibitionCheck(pHyp, pInhibitionMask, &eError);

  return eError;
}

/*************************************************************************************************************************
  Functionname:         HEADCustomInhibitionCheck                                                                         */ /*!

  @brief                The inhibition mask is modified based on custom logic

  @description          If an object is once classified and got hypothesis, the hypothesis wouldn't be removed in the case
                        of object reclassification. However, the new activations of the prefill, dynamic warning and first brake level
                        is to be inhibited for unclassified objects. On the other hand, the already started activations shall not be interrupted
                        only for reclassification of the object. Thus,The inhibition mask, which is only an enable condition in HEAD-Cfg, is to be
                        modified by inhibiting pre-fill, warning and first brake level for unclassified objects.
                        @startuml
                        Start
                            If(NULL check for HEAD Hypothesis) then (No)
                            If(NULL check for Hypothesis) then (No)
                            : Assign type of the hypothesis and object class;
                            If(Is object class is obstacle?) then (Yes)
                            If(check for hypothesis are any or all of the following \n hypothesis Runup, RunUpBraking, RunUpStationary and CutIn) then (Yes)
                            : Inhibition of new prefill, warning and Brake activation\n for unclassified objects that have crossing hypothesis;
                            Endif
                            If(Is hypothesis type is either Pedestrian Collision or Cycle Collision?) then (Yes)
                            : Inhibition of new prefill, warning and Brake activation \n for unclassified objects that have crossing hypothesis;
                            Endif
                            If(Is Inhibition obstacle longitude and obstacle crossing defined?) then (No)
                            : Inhibition mask is not to be modified;
                            Endif
                            Endif
                            Else
                            : update null pointer error;
                            Endif
                            Else
                            : update null pointer error;
                            Endif
                        stop
                        @enduml

  @return               void

  @param[in]            pHyp : Pointer to current Hypothesis
  @param[in,out]        pInhibitionMask : Pointer to Inhibition Mask
  @param[in,out]        pError : Pointer to the output error

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision

  @author               Mohamed Abdelkarim
*************************************************************************************************************************/
static void HEADCustomInhibitionCheck(HEADHypothesis_t const *pHyp, HEADBitField_t *pInhibitionMask, eGDBError_t* pError)
{
  eEBAObjectClass_t             eObjClass;
  eCDHypothesisType_t           eHypType;
  Hypothesis_t          const * plocalHyp;

  if(pHyp != NULL)
  {
    plocalHyp = pHyp->pHypothesis;

    if(plocalHyp != NULL)
    {
      eObjClass  = plocalHyp->eEBAObjectClass;
      eHypType   = plocalHyp->eType;

      /* The inhibition mask is only modified for unclassified objects */
      if ( eObjClass == EBAObjectClass_Obstacle )
      {
        /* Inhibition of new prefill-, warning- and Brake activation for unclassified objects that have longitudinal hypothesis */
        #ifdef HEAD_CFG_INHIBIT_OBSTACLE_LONG
        #if (HEAD_CFG_INHIBIT_OBSTACLE_LONG == MEDIC_ON)
        if ( (eHypType==CDHypothesisType_RunUp) || (eHypType== CDHypothesisType_RunUpBraking) || (eHypType==CDHypothesisType_RunUpStationary)|| (eHypType==CDHypothesisType_CutIn) )
        {
          *pInhibitionMask = (*pInhibitionMask)|FPS_EBA_INH_PRE_FILL|FPS_EBA_INH_PRE_WARN|FPS_EBA_INH_ACU_WARN|FPS_EBA_INH_BRAKE_L1;
        }
        #endif
        #endif // HEAD_CFG_INHIBIT_OBSTACLE_LONG

        /* Inhibition of new prefill-, warning- and Brake activation for unclassified objects that have crossing hypothesis */
        #ifdef HEAD_CFG_INHIBIT_OBSTACLE_CROSSING
        #if (HEAD_CFG_INHIBIT_OBSTACLE_CROSSING == MEDIC_ON)
        if ( (eHypType==CDHypothesisType_PedCollision) || (eHypType== CDHypothesisType_CyclColl) )
        {
          *pInhibitionMask = (*pInhibitionMask)|FPS_EBA_INH_PRE_FILL|FPS_EBA_INH_PRE_WARN|FPS_EBA_INH_ACU_WARN|FPS_EBA_INH_BRAKE_L1;
        }
        #endif
        #endif // HEAD_CFG_INHIBIT_OBSTACLE_CROSSING
      }

      /* if nothing of the corresponding switches is switched on the inhibition mask is not to be modified */
      #if (!defined(HEAD_CFG_INHIBIT_OBSTACLE_LONG)||(HEAD_CFG_INHIBIT_OBSTACLE_LONG==MEDIC_OFF)) &&  (!defined(HEAD_CFG_INHIBIT_OBSTACLE_CROSSING)||(HEAD_CFG_INHIBIT_OBSTACLE_CROSSING==MEDIC_OFF))
      (*pInhibitionMask) = (*pInhibitionMask);
      _PARAM_UNUSED(eHypType);
      #endif
    }
    else if(*pError == GDB_ERROR_NONE)
    {
      *pError = GDB_ERROR_POINTER_NULL;
    }
    else
    {
      /* The passed error is not to be modified in the function */
    }
  }
  else if(*pError == GDB_ERROR_NONE)
  {
    *pError = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    /* The passed error is not to be modified in the function */
  }
}

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* !(MEDIC_CFG_HEAD20) */

/**@}*/ 
