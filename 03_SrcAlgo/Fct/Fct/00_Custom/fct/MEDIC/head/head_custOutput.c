/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_custOutput.c 

DESCRIPTION:               Implementation of the head output arbitration

AUTHOR:                    $Author: uia92763 $

CREATION DATE:             $Date: 2020/12/09 08:40:37CET $

VERSION:                   $Revision: 1.4.10.9 $

**************************************************************************** */
/**
@defgroup head_custOutput HEAD_CUSTOUTPUT
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
static void HEADOutArbitrateLatPreWarn(void);
static void HEADOutArbitrateLatAcuteWarn(void);
static void HEADOutArbitrateBrake(void);
static void HEADOutArbitratePreWarning(void);
static void HEADOutArbitrateAcuteWarning(void);
static void HEADOutArbitratePrefill(void);
static void HEADSet_Qualifiers(HEADModule_t const * const pModules[]);
static boolean HEADSetEmergency(void);
#if(HEAD_DO_NOT_SET_CHANNEL_UNCLASSIFIED == SWITCH_ON)
static eEBAFctChan_t HEADCheckForUnclassfied(const Hypothesis_t* pHyp, eEBAFctChan_t eEBAFctChan_current);
#endif
static void HEADSetReachedBrkLevel(void);
static eWarnSens_t HEADGetHaptSensState(void); 

/*****************************************************************************
  DEFINES
*****************************************************************************/
/*! @brief       FPSEBACFCT_MAX_OBJ_QUAL_NO_CAM
    @description FPS max. quality of an object without camera confirmation
    @typical     CDObjEbaQual_NoCamConf   */
#define FPSEBACFCT_MAX_OBJ_QUAL_NO_CAM CDObjEbaQual_NoCamConf

/*! @brief       HEAD_BRK_LVL_STNDST
    @general     HEAD Break Level for Standstill
    @typical     9u     */
#define HEAD_BRK_LVL_STNDST         (9u)

#if defined (HEAD_USE_CROSSING_BRK) && (HEAD_USE_CROSSING_BRK == SWITCH_ON)
/*! @brief       HEAD_BRK_LVL_CROS
    @general     HEAD Break Level for Crossing
    @typical     8u     */
#define HEAD_BRK_LVL_CROSS      (8u)
#endif

/*! @brief       HEAD_BRK_LVL_LONGVRU2
    @general     HEAD Break Level for Pedestrian2
    @typical     7u         */
#define HEAD_BRK_LVL_LONGVRU2       (7u)

/*! @brief       HEAD_BRK_LVL_LONGVRU1
    @general     HEAD Break Level for Pedestrian1
    @typical     6u     */
#define HEAD_BRK_LVL_LONGVRU1       (6u)

/*! @brief       HEAD_BRK_LVL_PED2
    @general     HEAD Break Level for Pedestrian2
    @typical     5u     */
#define HEAD_BRK_LVL_PED2       (5u)

/*! @brief       HEAD_BRK_LVL_PED1
    @general     HEAD Break Level for Pedestrian1
    @typical     4u    */
#define HEAD_BRK_LVL_PED1       (4u)

/*! @brief       HEAD_BRK_LVL_VEH3
    @general     HEAD Break Level for Vehicle3
    @typical     3u     */
#define HEAD_BRK_LVL_VEH3       (3u)

/*! @brief       HEAD_BRK_LVL_VEH2
    @general     HEAD Break Level for Vehicle2
    @typical     2u     */
#define HEAD_BRK_LVL_VEH2       (2u)

/*! @brief       HEAD_BRK_LVL_VEH1
    @general     HEAD Break Level for Vehicle1
    @typical     1u   */
#define HEAD_BRK_LVL_VEH1       (1u)

/*! @brief       HEAD_BRK_PASSIVE
    @general     HEAD Break Passive
    @typical     0   */
#define HEAD_BRK_PASSIVE        (0u)

/*! @brief HBA level : Default state
    @general     HEAD Default level
    @typical     0   */
#define FCT_HEAD_HBA_LEVEL_NONE (0u)

/*Add for Changan_C385*/
#define MEDIC_CYCLE_TIME_CHANGAN     (20u)
#define HEAD_EMERGENCY_LIGHT_TIME (100u)
#ifndef FCW_SPEED_THRESHOLD_MINI
#define FCW_SPEED_THRESHOLD_MINI (12.76875/3.6f) //Use IP VehSpeed
#endif
/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
#pragma PRQA_NO_SIDE_EFFECTS HEADGetEBASwitch
#pragma PRQA_NO_SIDE_EFFECTS HEADGetEBACoding

/*************************************************************************************************************************
  Functionname:         HEADCustomOutputInit                                                                        */ /*!

  @brief                Reset HEAD custom output data

  @description          The function Reset the HEAD custom output data to Default value
                        @startuml
                        Start
                            :Reset HEAD Custom output data
                            to default value.;
                        Stop
                        @enduml 

  @return               void

  @param[in]            void
  
  @glob_in              None
  @glob_out             @ref MEDIC_p_ModHeadOutCustom()

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined 
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
*************************************************************************************************************************/
void HEADCustomOutputInit(void)
{
  /* reset cust out data */
  MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.eFctChan        = eEBAFctChan_Unknown;
  MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.eSignal         = eEBAOn_Inactive;
  MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.uActiveHyp      = HEADNoHypothesis;
    
  MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.eFctChan      = eEBAFctChan_Unknown;
  MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.eSignal       = eEBAOn_Inactive;
  MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.uActiveHyp    = HEADNoHypothesis;
    
  MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.eFctChan       = eEBAFctChan_Unknown;
  MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.eSignal        = eEBAOn_Inactive;
  MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.uActiveHyp     = HEADNoHypothesis;
  
  MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eFctChan     = eEBAFctChan_Unknown;
  MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eSignal      = eEBAOn_Inactive;
  MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.uActiveHyp   = HEADNoHypothesis;
    
  MEDIC_p_ModHeadOutCustom()->sPrefill.eFctChan                           = eEBAFctChan_Unknown;
  MEDIC_p_ModHeadOutCustom()->sPrefill.bPrefillActive                     = FALSE;
  MEDIC_p_ModHeadOutCustom()->sPrefill.bPreRunActive                      = FALSE;
  MEDIC_p_ModHeadOutCustom()->sPrefill.eGeneratorControl                  = eEBAGenerator_No;
  MEDIC_p_ModHeadOutCustom()->sPrefill.uActiveHyp                         = HEADNoHypothesis;

  MEDIC_p_ModHeadOutCustom()->sHBA.fHBADecel                              = 0;
  MEDIC_p_ModHeadOutCustom()->sHBA.uActiveHyp                             = HEADNoHypothesis;
  MEDIC_p_ModHeadOutCustom()->sHBA.eFctChan                               = eEBAFctChan_Unknown;
  MEDIC_p_ModHeadOutCustom()->sHBA.uiHBALevel                             = FCT_HEAD_HBA_LEVEL_NONE;

  MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeDecelEnabled             = FALSE;
  MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeStdstillRequest          = FALSE;
  MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeEmergency                = FALSE;
  MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan                          = eEBAFctChan_Unknown;
  MEDIC_p_ModHeadOutCustom()->sPreBrake.fPreBrakeDecel                    = 0;
  MEDIC_p_ModHeadOutCustom()->sPreBrake.uActiveHyp                        = HEADNoHypothesis;
  MEDIC_p_ModHeadOutCustom()->sPreBrake.uPreBrakeLevel                    = HEAD_BRK_PASSIVE;
  MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeCamConfirmed             = FALSE; // add for Changan_C385

  MEDIC_p_ModHeadOutCustom()->sPreCrash.bEMAActive                        = FALSE;
  MEDIC_p_ModHeadOutCustom()->sPreCrash.eEBAFctChan                       = eEBAFctChan_Unknown;
  MEDIC_p_ModHeadOutCustom()->sPreCrash.fPreCrashCV                       = 0;
  MEDIC_p_ModHeadOutCustom()->sPreCrash.fPreCrashTTC                      = HEAD_TTX_MAX;
  MEDIC_p_ModHeadOutCustom()->sPreCrash.uActiveHyp                        = HEADNoHypothesis;

  MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.eFctChan       = eEBAFctChan_Unknown;
  MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.eSignal        = eEBAOn_Inactive;
  MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.uActiveHyp     = HEADNoHypothesis;

  MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier          = 0;
  MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier         = 0;
  MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier = 0;
  MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier          = 0;
}

/*************************************************************************************************************************
  Functionname:         HEADInitOutput                                                                              */ /*!

  @brief                Initializes the HEAD output data

  @description          The function initializes the HEAD output data for the first time

                        @startuml
                        Start
                            if(Is the FCT HEAD generic output information available?) then (Yes)
                            : Initialize head cycle conter;
                            Else
                            : Update the null pointer error;
                            endif
                            If(IS the FCT HEAD custom output information available?) then (Yes)
                            #orange: Initialise the HEAD output signals
                            <b> HEADCustomOutputInit <b> >
                            Else
                            :update the null pointer error;
                            Endif
                            : Return the updated error type;
                        Stop
                        @enduml

  @return               eGDBError_t      :GDB error type is returned

  @param[in]            void
  
  @glob_in              None            
  @glob_out             @ref MEDIC_p_ModHeadOutGeneric() \n @ref MEDIC_p_ModHeadOutCustom()

  @c_switch_part        @ref MEDIC_CFG_USE_EM_GENERIC_OBJECT_LIST \n @ref MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION \n @ref HEAD_USE_TIME_HIGH_OBJ_QUALITY \n
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
*************************************************************************************************************************/
eGDBError_t HEADInitOutput(void)
{
  eGDBError_t retValue = GDB_ERROR_NONE;

  if (MEDIC_p_ModHeadOutGeneric() != NULL)
  {
    #if (MEDIC_CFG_USE_EM_GENERIC_OBJECT_LIST)
    #else
    MEDIC_p_ModHeadOutGeneric()->uiHEADCycleCounter = 0uL;
    #endif /* MEDIC_CFG_USE_EM_GENERIC_OBJECT_LIST */
  }
  else
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }

  if (MEDIC_p_ModHeadOutCustom() != NULL)
  {
    /* Initialise the HEAD output signals */
    HEADCustomOutputInit();

    /* Initialise the additions output signals */
    #if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
    MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeCamConfirmed           = FALSE;
    #endif /* MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION */
    
    MEDIC_p_ModHeadOutCustom()->sFCTData.iObjRef                          = -1;
    MEDIC_p_ModHeadOutCustom()->sFCTData.fVelocityFactor                  = 0;
    MEDIC_p_ModHeadOutCustom()->sFCTData.fSafeObjDistance                 = HEAD_DEFAULT_SafeObjDistance;
    MEDIC_p_ModHeadOutCustom()->sFCTData.fObjTTC                          = HEAD_TTX_MAX;
    #if (HEAD_USE_TIME_HIGH_OBJ_QUALITY)
    MEDIC_p_ModHeadOutCustom()->sFCTData.fObjLifeTimeHiQual               = 0;
    #endif
    MEDIC_p_ModHeadOutCustom()->sFCTData.eObjRelQualifier                 = eEBAObjRelNo;
    MEDIC_p_ModHeadOutCustom()->sFCTData.fObjDistX                        = 255.0F;
    MEDIC_p_ModHeadOutCustom()->sFCTData.fCollisionAvoidAccel             = 0;
  }
  else
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  MEDIC_p_GetEBASignalState()->HEADLatPreWarnSigState         = eEBAOn_Inactive; 
  MEDIC_p_GetEBAFctChan()->HEADLatPreWarnFctChannel           = eEBAFctChan_Unknown;
  MEDIC_p_GetEBASignalState()->HEADLatAcuteWarnSigState       = eEBAOn_Inactive;
  MEDIC_p_GetEBAFctChan()->HEADLatAcuteWarnFctChannel         = eEBAFctChan_Unknown;
  MEDIC_p_GetEBASignalState()->HEADPreWarnSignal              = eEBAOn_Inactive;
  MEDIC_p_GetEBAFctChan()->HEADPreWarnFctChannel              = eEBAFctChan_Unknown;
  MEDIC_p_GetEBASignalState()->HEADAcuteWarnSignal            = eEBAOn_Inactive;
  MEDIC_p_GetHEADCustOutputLocVar()->HEADAcuteWarnActiveHyp   = HEADNoHypothesis;
  MEDIC_p_GetEBAFctChan()->HEADAcuteWarnFctChannel            = eEBAFctChan_Unknown;
  MEDIC_p_GetEBAFctChan()->HEADBrakeFctChannel                = eEBAFctChan_Unknown;
  MEDIC_p_GetEBAFctChan()->HEADPrefillFctChannel              = eEBAFctChan_Unknown;
  MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel          = 0u;
  #if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
  MEDIC_p_GetHEADCustOutputLocVar()->HEADPreBrakeCamConfirm   = FALSE;
  #endif

  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADCustomOutputSet                                                                        */ /*!

  @brief                Writes out HEAD custom Output Data

  @description          Writes out HEAD Custom output data
  
                        @startuml
                        start
                            :Set Custom Output Data From \nModule Output Data;
                            Note left
                            Set HEAD Custom output Data from HEAD Module Output Data for
                            latent pre warning, latent acute warning, dynamic pre warning,
                            dynamic acute warning, pre fill, HBA and VehAutoBrake.
                            End note
                            #Orange: Set emergency bit
                            <b> HEADSetEmergency <b> > 
                            #orange: Get maximum brake level
                            <b> HEADSetReachedBrkLevel <b> >
                            If( Is max brake level passive?) then (yes)
                            :Save steering wheel angle
                            and gas pedal position;
                            else if(Is max brake level buffer passive?) then (Yes)
                            :Save only at the start of New braking event;
                            else
                            :nothing is to be done;
                            endif
                            if(check for HoldBreakStandstill function is active
                            and Vehicle Auto Brake1 is not Active) then (True)
                            if(check for  max brake level buffer and stand 
                            still active time greater than the HEAD 
                            Break Passive and Hold time for standstill) then (Yes)
                            :Hold Brake in Stand still;
                            endif
                            If(check for  stand still active time greater than  Hold time for standstill) then (Yes)
                            :Update Stand still active time;
                            Endif
                            Else
                            : reset the standstill timer;
                            Endif
                            :Deactivate Brake;
                            Note left
                            Deactivate Brake incase if the Function is Switched off
                            Or it is not Coded.
                            End note
                            While( Is Hypothesis number valid?) is (Yes)
                            : delete all hypotheses reactions;
                            Endwhile(No)
                            While( Is Hypothesis number valid?) is (Yes)
                            :Update Hypotheses reactions;
                            Endwhile(No)
                            Note right
                            Update Hypotheses reactions based on Module Output
                            (Note:This is Additional output used for development)
                            End note
                            #orange:Set Custom Output Qualifiers
                            <b> HEADSet_Qualifiers <b> >
                            Note right
                            Set HEAD Custom Output Qualifiers based on
                            corresponding coding,Switches, Reported Error
                            and Quality of State;
                            End note
                        Stop
                        @enduml

  @return               eGDBError_t      :GDB error type is returned

  @param[in]            Void

  @glob_in              @ref MEDIC_p_GetDIMInGeneric()\n @ref fStandstillActiveTime\n @ref HEADInputData\n @ref HEADMaxBrkLevel\n @ref HEADModuleOutputData
  @glob_out             @ref MEDIC_p_ModHeadOutGeneric()\n @ref MEDIC_p_ModHeadOutCustom()\n @ref bBrakeStatValuesValid\n @ref fSteeringWheelBrakeStart\n @ref fGasPedalPosBrakeStart\n
						@ref fStandstillActiveTime

  @c_switch_part        @ref MEDIC_CFG_USE_SIG_HEADER
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADCustomOutputSet(void)
{
    eGDBError_t   retValue = GDB_ERROR_NONE;
    float32       fPreBrkActVel;
    uint32        uiModul;
    uint32        critical = 0u;
    HEADModule_t const *pModules[HEAD_AUTO_CFG_NO_MODULES];
	/*Changan_C385 Mcylinder_Pressure condition*/
    static HEADModuleOutputToggleFunction_t HaptDynWarnTemp;




    /*ARS410BD10 keep last FCW activation status for output*/
    static Boolean LastFCWStatus = FALSE;
	static Boolean bLowSpdFCWActive = FALSE;
    /* save buffer Value of HEADMaxBrkLevel for Standstill */
    uint8         uHEADMaxBrkLevelBuffer = MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel;
    (void)HEADGetInputValue_float32(MEDIC_p_ModHEADInputData()->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &fPreBrkActVel);

#if (MEDIC_CFG_USE_SIG_HEADER)
    MEDIC_p_ModHeadOutGeneric()->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
    MEDIC_p_ModHeadOutCustom()->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
#else
    /* Write head cycle counter to output interface to indicate liveliness */
    MEDIC_p_ModHeadOutGeneric()->uiHEADCycleCounter = MEDIC_p_ModHEADInputData()->uiCurrentCycle;
#endif /*MEDIC_CFG_USE_EM_GENERIC_OBJECT_LIST */

    /****** Set warnings according to function object class and coding ******/
    /* remark: "else" don't care cause warning are already initialized with "no warning" */
    /* latent pre warning  Distance Warning*/
    MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.eSignal = HEADModuleOutputData.LatPreWarn.eEBASignalState;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.uActiveHyp = HEADModuleOutputData.LatPreWarn.ActHypNr;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.eFctChan = HEADModuleOutputData.LatPreWarn.eEBAFctChannel;

    /* latent acute warning */
    MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.eSignal = HEADModuleOutputData.LatAcuteWarn.eEBASignalState;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.uActiveHyp = HEADModuleOutputData.LatAcuteWarn.ActHypNr;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.eFctChan = HEADModuleOutputData.LatAcuteWarn.eEBAFctChannel;

    /* dynamic pre warning */
    MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.eSignal = HEADModuleOutputData.DynPreWarn.eEBASignalState;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.uActiveHyp = HEADModuleOutputData.DynPreWarn.ActHypNr;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.eFctChan = HEADModuleOutputData.DynPreWarn.eEBAFctChannel;
	
	
	/*ChanganC385_AWB BASE_JERK Warning*/
	if ((MEDIC_p_GetDIMInGeneric()->eDriverSetting != eDriverSetting_Invalid))
	{    
    if(HEADModuleOutputData.CrossVru_HaptDynWarn.bOutFunctionActive != 0)
    {
      HaptDynWarnTemp = HEADModuleOutputData.CrossVru_HaptDynWarn;
    }
    else if(HEADModuleOutputData.LongVru_HaptDynWarn.bOutFunctionActive != 0)
    {
      HaptDynWarnTemp = HEADModuleOutputData.LongVru_HaptDynWarn;
    }
    else
    {
      HaptDynWarnTemp = HEADModuleOutputData.HaptDynWarn;
    }

    HEADModuleOutputData.HaptDynWarn = HaptDynWarnTemp;

		MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicHaptWarning.eSignal = HEADModuleOutputData.HaptDynWarn.eEBASignalState;
		MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicHaptWarning.uActiveHyp = HEADModuleOutputData.HaptDynWarn.ActHypNr;
		MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicHaptWarning.eFctChan = HEADModuleOutputData.HaptDynWarn.eEBAFctChannel;
		MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicHaptWarning.eWarnSens = HEADGetHaptSensState();
    //Function2(); // Reset 
    if(HEADModuleOutputData.CrossVru_HaptDynWarn.bOutFunctionActive != 0)
    {
      HEADModuleOutputData.CrossVru_HaptDynWarn           = HaptDynWarnTemp;
      HEADModuleOutputData.HaptDynWarn.bOutFunctionActive = b_FALSE;
      HEADModuleOutputData.HaptDynWarn.ActHypNr            = HEADNoHypothesis;
      HEADModuleOutputData.HaptDynWarn.eEBAFctChannel      = eEBAFctChan_Unknown;
      HEADModuleOutputData.HaptDynWarn.eEBASignalState     = eEBAOn_Inactive;
    }
    else if(HEADModuleOutputData.LongVru_HaptDynWarn.bOutFunctionActive != 0)
    {
      HEADModuleOutputData.LongVru_HaptDynWarn            = HaptDynWarnTemp;
      HEADModuleOutputData.HaptDynWarn.bOutFunctionActive = b_FALSE;
      HEADModuleOutputData.HaptDynWarn.ActHypNr            = HEADNoHypothesis;
      HEADModuleOutputData.HaptDynWarn.eEBAFctChannel      = eEBAFctChan_Unknown;
      HEADModuleOutputData.HaptDynWarn.eEBASignalState     = eEBAOn_Inactive;
    }
    else
    {}

	}
	else
	{
		MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicHaptWarning.eSignal = eEBAOn_Inactive;
		MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicHaptWarning.uActiveHyp = HEADNoHypothesis;
		MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicHaptWarning.eFctChan = eEBAFctChan_Unknown;
		MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicHaptWarning.eWarnSens = 0;
	}
    
#if HEAD_CFG_TURN_ASSIST
    if (HEADModuleOutputData.OncomingDriveOffPrevention.bOutFunctionActive == TRUE)
    {
    MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.eSignal = eEBAOn_Oncoming;
        MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.uActiveHyp = HEADModuleOutputData.OncomingWarn.ActHypNr;
        MEDIC_p_ModHeadOutCustom()->sWarnings.sPreDynamicWarning.eFctChan = eEBAFctChan_DrvIntoOncoming;
    }
#endif  /* HEAD_CFG_TURN_ASSIST */
    /* dynamic acute warning */

if(*(HEADModuleOutputData.DynAcuteWarn.peSignal) > 0
&& (MEDIC_p_GetVDYDynRaw()->Longitudinal.VeloCorr.corrVelo < FCW_SPEED_THRESHOLD_MINI))
{
  bLowSpdFCWActive = TRUE;
}
if(*(HEADModuleOutputData.DynAcuteWarn.peSignal) == 0)
{
  bLowSpdFCWActive = FALSE;
}

    //if (MEDIC_p_GetVDYDynRaw()->Longitudinal.VeloCorr.corrVelo > 8.33)
    if ((MEDIC_p_GetDIMInGeneric()->eDriverSetting != eDriverSetting_Invalid)
		&& (MEDIC_p_GetVDYDynRaw()->Longitudinal.VeloCorr.corrVelo > FCW_SPEED_THRESHOLD_MINI)
    && (bLowSpdFCWActive != TRUE))
    {
        MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eSignal = *(HEADModuleOutputData.DynAcuteWarn.peSignal);
        MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.uActiveHyp = *(HEADModuleOutputData.DynAcuteWarn.puActiveHyp);
        MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eFctChan = *(HEADModuleOutputData.DynAcuteWarn.peFctChan);
    }
    else
    {
         if ((LastFCWStatus == TRUE) && (MEDIC_p_GetDIMInGeneric()->eDriverSetting != eDriverSetting_Invalid))
         {
             MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eSignal = *(HEADModuleOutputData.DynAcuteWarn.peSignal);
             MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.uActiveHyp = *(HEADModuleOutputData.DynAcuteWarn.puActiveHyp);
             MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eFctChan = *(HEADModuleOutputData.DynAcuteWarn.peFctChan);
         }
        else
        {
            MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eSignal = eEBAOn_Inactive;
            MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.uActiveHyp = HEADNoHypothesis;
            MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eFctChan = eEBAFctChan_Unknown;
        }
    }

    LastFCWStatus = (Boolean)((MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eSignal > 0) ? 1 : 0);


  #if HEAD_CFG_TURN_ASSIST
  if ((HEADModuleOutputData.OncomingWarn.bOutFunctionActive == TRUE) || (HEADModuleOutputData.OncomingLatentWarn.bOutFunctionActive == TRUE))
  {
    MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eSignal    = eEBAOn_Oncoming;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.uActiveHyp = HEADModuleOutputData.OncomingWarn.ActHypNr;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteDynamicWarning.eFctChan   = eEBAFctChan_DrvIntoOncoming;
  }

  if (HEADModuleOutputData.OncomingLatentWarn.bOutFunctionActive == TRUE)
  {
    MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.eSignal    = eEBAOn_Oncoming;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.uActiveHyp = HEADModuleOutputData.OncomingWarn.ActHypNr;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sPreStaticWarning.eFctChan   = eEBAFctChan_DrvIntoOncoming;

    MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.eSignal    = eEBAOn_Oncoming;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.uActiveHyp = HEADModuleOutputData.OncomingWarn.ActHypNr;
    MEDIC_p_ModHeadOutCustom()->sWarnings.sAcuteStaticWarning.eFctChan   = eEBAFctChan_DrvIntoOncoming;
  }
  #endif  /* HEAD_CFG_TURN_ASSIST */

  /* pre fill */

    MEDIC_p_ModHeadOutCustom()->sPrefill.bPrefillActive = HEADModuleOutputData.Prefill.bOutFunctionActive;
    MEDIC_p_ModHeadOutCustom()->sPrefill.uActiveHyp     = HEADModuleOutputData.Prefill.ActHypNr;
    MEDIC_p_ModHeadOutCustom()->sPrefill.eFctChan       = HEADModuleOutputData.Prefill.eEBAFctChannel;

 
 

  /* HBA TA ChanganC385_ABA */

    MEDIC_p_ModHeadOutCustom()->sHBA.fHBADecel  = *(HEADModuleOutputData.HBA_TA.pfHBADeceleration);
    MEDIC_p_ModHeadOutCustom()->sHBA.uiHBALevel = *(HEADModuleOutputData.HBA_TA.puiHBALevel);
    MEDIC_p_ModHeadOutCustom()->sHBA.uActiveHyp = *(HEADModuleOutputData.HBA_TA.pHypoNr);
    MEDIC_p_ModHeadOutCustom()->sHBA.eFctChan   = *(HEADModuleOutputData.HBA_TA.pFctChannel);

  
  
  
  /* VehAutoBrake */

    MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeDecelEnabled = *(HEADModuleOutputData.Veh_AutoBrk1.pbPreBrakeActive);
    MEDIC_p_ModHeadOutCustom()->sPreBrake.fPreBrakeDecel        = *(HEADModuleOutputData.Veh_AutoBrk1.pfPreBrakeDeceleration);
    MEDIC_p_ModHeadOutCustom()->sPreBrake.uActiveHyp            = *(HEADModuleOutputData.Veh_AutoBrk1.pActHypNr);
    MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan              = *(HEADModuleOutputData.Veh_AutoBrk1.peFctChan);
    MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeEmergency    = HEADSetEmergency();
    HEADSetReachedBrkLevel();
    MEDIC_p_ModHeadOutCustom()->sPreBrake.uPreBrakeLevel        = MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel;

  #if HEAD_CFG_TURN_ASSIST 
  if (HEADModuleOutputData.OncomingBrake.bOutFunctionActive == TRUE)
  {
    MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeDecelEnabled = TRUE;
    MEDIC_p_ModHeadOutCustom()->sPreBrake.fPreBrakeDecel        = HEAD_PAR_PRE_BRAKE_DECELERATION_FOR_TURN_ASSIST;
    MEDIC_p_ModHeadOutCustom()->sPreBrake.uActiveHyp            = HEADModuleOutputData.OncomingBrake.ActHypNr;
    MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan              = eEBAFctChan_DrvIntoOncoming;
    MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeEmergency    = TRUE;
    MEDIC_p_ModHeadOutCustom()->sPreBrake.uPreBrakeLevel        = MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel;
  }
  #endif /* HEAD_CFG_TURN_ASSIST */



  /* EDR output */
  if(*(HEADModuleOutputData.Veh_AutoBrk1.pActHypNr)== HEADNoHypothesis)
  {
      /* keep hyp[0] as critical before braking point */
  }
  else
  {
      critical = *(HEADModuleOutputData.Veh_AutoBrk1.pActHypNr);
  }

  MEDIC_p_ModHeadOutCustom()->EDROutput.fX_Dist = MEDIC_p_GetHypothesisIntf()->Hypothesis[critical].fDistX;
  MEDIC_p_ModHeadOutCustom()->EDROutput.fX_Vrel = MEDIC_p_GetHypothesisIntf()->Hypothesis[critical].fVrelX;
  MEDIC_p_ModHeadOutCustom()->EDROutput.fX_Arel = MEDIC_p_GetHypothesisIntf()->Hypothesis[critical].fArelX;
  MEDIC_p_ModHeadOutCustom()->EDROutput.fY_Dist = MEDIC_p_GetHypothesisIntf()->Hypothesis[critical].fDistY;
  MEDIC_p_ModHeadOutCustom()->EDROutput.fY_Vrel = MEDIC_p_GetHypothesisIntf()->Hypothesis[critical].fVrelY;
  MEDIC_p_ModHeadOutCustom()->EDROutput.fY_Arel = MEDIC_p_GetHypothesisIntf()->Hypothesis[critical].fArelY;
  MEDIC_p_ModHeadOutCustom()->EDROutput.ObjID   = MEDIC_p_GetHypothesisIntf()->Hypothesis[critical].uiObjectRef;
  {
      const Hypothesis_t* Critical_hyp = (&(MEDIC_p_GetHypothesisIntf()->Hypothesis[critical]));
      MEDIC_p_ModHeadOutCustom()->EDROutput.ObjStatus = HEADGetEBASignalState(Critical_hyp);
  }
  /* Save steering wheel angle and gas pedal position at the start of braking event */
  if (MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel == HEAD_BRK_PASSIVE)
  {
    bBrakeStatValuesValid    = FALSE;
    fSteeringWheelBrakeStart = 0;
    fGasPedalPosBrakeStart   = 0;
  }
  else if (uHEADMaxBrkLevelBuffer == HEAD_BRK_PASSIVE)
  {
    /* New Brake Event -> Save data */
    bBrakeStatValuesValid    = TRUE;
    fSteeringWheelBrakeStart = MEDIC_p_GetDIMInGeneric()->fSteeringWheelAngle;
    fGasPedalPosBrakeStart   = MEDIC_p_GetDIMInGeneric()->fAccelPedalPos;
  }
  else
  {
    /* nothing is to be done */
  }

  /* Standstill */
  if (  (HEADModuleOutputData.HoldBrakeInStandstill.bOutFunctionActive == TRUE)
     && (*(HEADModuleOutputData.Veh_AutoBrk1.pbPreBrakeActive) == FALSE))
  {
    /* start the timer */
    if ((uHEADMaxBrkLevelBuffer > HEAD_BRK_PASSIVE)
      &&(fStandstillActiveTime > HEAD_PAR_STANDSTILL_HOLD_TIME_STAT_MAX))
    {
      fStandstillActiveTime = HEAD_PAR_STANDSTILL_HOLD_TIME_STAT_MAX;
    }
    /* update the timer value */
    if (fStandstillActiveTime <= HEAD_PAR_STANDSTILL_HOLD_TIME_STAT_MAX)
    {
      fStandstillActiveTime = fStandstillActiveTime-MEDIC_CYCLE_TIME;
      fStandstillActiveTime = CML_f_Max(0,fStandstillActiveTime);
      /* update the output interface */
      MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel               = HEAD_BRK_LVL_STNDST;
      MEDIC_p_ModHeadOutCustom()->sPreBrake.fPreBrakeDecel             = HEAD_PAR_STANDSTILL_REQ_DECEL_VAL;   
      MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeEmergency         = FALSE;
      MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeDecelEnabled      = TRUE;
      MEDIC_p_ModHeadOutCustom()->sPreBrake.uActiveHyp                 = HEADNoHypothesis;
      MEDIC_p_ModHeadOutCustom()->sPreBrake.uPreBrakeLevel             = MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel;
      MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeStdstillRequest   = TRUE;
      MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan                   = eEBAFctChan_Unknown;
    }
  }
  else
  {
    /* reset the standstill timer */
    fStandstillActiveTime = HEAD_PAR_MAX_OBS_TIME;
  }

  /* Deactivate Brake if not switched or not coded */
  /*************************************************/
  if ( ( ( (MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan == eEBAFctChan_Pedestrian)
         ||(MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan == eEBAFctChan_Cyclist)
         )
       &&(HEADGetEBASwitch(eEBASwitch_LongVruBRK) == FALSE)
       &&(HEADGetEBASwitch(eEBASwitch_CrossVruBRK) == FALSE)
       &&(HEADGetEBASwitch(eEBASwitch_OncVruBRK) == FALSE)
      )
    ||( ( (MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan == eEBAFctChan_Vehicle)
        ||(MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan == eEBAFctChan_Unclassified)
        )
      &&(HEADGetEBASwitch(eEBASwitch_LongVehBRK) == FALSE)
      &&(HEADGetEBASwitch(eEBASwitch_CrossVehBRK) == FALSE)
      &&(HEADGetEBASwitch(eEBASwitch_OncVehBRK) == FALSE)
      )
    ||((MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan == eEBAFctChan_Unknown)
      && (HEADModuleOutputData.HoldBrakeInStandstill.bOutFunctionActive != TRUE))

    ||( (MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan == eEBAFctChan_Pedestrian)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongPedMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossPedMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_OncPedMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongPedStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossPedStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_OncPedStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongPedMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossPedMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_OncPedMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongPedStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossPedStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_OncPedStat) == FALSE)
      )
    ||( (MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan == eEBAFctChan_Cyclist)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongCyclMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossCyclMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_OncCyclMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongCyclStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossCyclStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_OncCyclStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongCyclMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossCyclMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_OncCyclMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongCyclStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossCyclStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_OncCyclStat) == FALSE)
      )
    ||( (MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan == eEBAFctChan_Vehicle)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongVehMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossVehMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_OncVehMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongVehStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossVehStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_OncVehStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongVehMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossVehMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_OncVehMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongVehStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossVehStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_OncVehStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_LongVehMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_CrossVehMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_OncVehMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_LongVehStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_CrossVehStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_OncVehStat) == FALSE)
      )
    ||( (MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan == eEBAFctChan_Unclassified)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongObsMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossObsMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_OncObsMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_LongObsStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_CrossObsStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK1, eEBACodingIdx_OncObsStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongObsMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossObsMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_OncObsMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_LongObsStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_CrossObsStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK2, eEBACodingIdx_OncObsStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_LongObsMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_CrossObsMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_OncObsMov) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_LongObsStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_CrossObsStat) == FALSE)
      &&(HEADGetEBACoding(EBA_CODING_BIT_AUTOBRK3, eEBACodingIdx_OncObsStat) == FALSE)
      )
    )
  {
    MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeDecelEnabled             = FALSE;
    MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeEmergency                = FALSE;
    MEDIC_p_ModHeadOutCustom()->sPreBrake.eFctChan                          = eEBAFctChan_Unknown;
    MEDIC_p_ModHeadOutCustom()->sPreBrake.fPreBrakeDecel                    = 0;
    MEDIC_p_ModHeadOutCustom()->sPreBrake.uActiveHyp                        = HEADNoHypothesis;
    MEDIC_p_ModHeadOutCustom()->sPreBrake.uPreBrakeLevel                    = 0u;
  }

  /*------------- Hypotheses reactions (additional output used for development) -------------*/
  { /* Create a matrix between hypotheses and output functions */
    uint8 uiNr;
    HEADHypothesisNr_t hypNr;
    /* delete all hypotheses reactions*/
    for(uiNr = 0u; uiNr < HEAD_MAX_NUMBER_OF_CD_HYPS; uiNr++)
    {
      MEDIC_p_ModHeadOutCustom()->rgHypReactions[uiNr].bDynamicAcuteWarningActive = FALSE;
      MEDIC_p_ModHeadOutCustom()->rgHypReactions[uiNr].bDynamicPreWarningActive   = FALSE;
      MEDIC_p_ModHeadOutCustom()->rgHypReactions[uiNr].bHBAActive                 = FALSE;
      MEDIC_p_ModHeadOutCustom()->rgHypReactions[uiNr].bLatentAcuteWarningActive  = FALSE;
      MEDIC_p_ModHeadOutCustom()->rgHypReactions[uiNr].bLatentPreWarningActive    = FALSE;
      MEDIC_p_ModHeadOutCustom()->rgHypReactions[uiNr].bPreBrakeActive            = FALSE;
      MEDIC_p_ModHeadOutCustom()->rgHypReactions[uiNr].bPreFillActive             = FALSE;
    }
    
    for (uiModul = 0u; uiModul < HEAD_AUTO_CFG_NO_MODULES; uiModul++)
    {
      pModules[uiModul] = HEADGetModule(MEDIC_p_ModHEADInputData()->pModuleList, uiModul);
    }
    
    for(hypNr = 0u; hypNr < HEAD_MAX_NUMBER_OF_CD_HYPS; hypNr++)
    {
      /* Map dynamic acute warning to hypothesis */
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_DynAcuteWarn], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bDynamicAcuteWarningActive = TRUE;
      }
      /* Map dynamic pre-warning to hypothesis */
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_DynPreWarn], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bDynamicPreWarningActive = TRUE;
      }
      /* Map hba to hypothesis */
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_HBA_TA], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bHBAActive = TRUE;
      }
      /* Map latent pre warning to hypothesis */
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_LatPreWarn], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bLatentPreWarningActive = TRUE;
      }
      /* Map latent acute warning to hypothesis */
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_LatAcuteWarn], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bLatentAcuteWarningActive = TRUE;
      }
      /* Map prefill to hypothesis */
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_Prefill], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bPreFillActive = TRUE;
      }
        /* Map Brake to hypothesis */
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk1], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bPreBrakeActive = TRUE;
      }
      /* Map Ped_DynAcuteWarn to hypothesis */ 
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bDynamicAcuteWarningActive = TRUE;
      }
      /* Map Ped_Prefill to hypothesis */ 
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_CrossVru_Prefill], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bPreFillActive = TRUE;
      }
      /* Map Ped_HBA to hypothesis */ 
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_CrossVru_HBA], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bHBAActive = TRUE;
      }
      /* Map Ped_PreBrk to hypothesis */  
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bPreBrakeActive = TRUE;
      }
      /* Map Cross_Warn to hypothesis */  
       if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk2], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bPreBrakeActive = TRUE;
      }
      /* Map dynamic acute warning to hypothesis */
       if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bDynamicAcuteWarningActive = TRUE;
      }
      /* Map Brake to hypothesis */
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_LongVru_Brk1], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bPreBrakeActive = TRUE;
      }
      /* Map Ped_Prefill to hypothesis */ 
      if (HEADIsHypoActiveForModule(pModules[HEAD_AUTOCODE_MOD_LongVru_Prefill], hypNr) == TRUE)
      {
        MEDIC_p_ModHeadOutCustom()->rgHypReactions[hypNr].bPreFillActive = TRUE;
      }
    }
  }

  HEADSet_Qualifiers(pModules);
   /* return */
  return retValue;
} /* PRQA S 7004, 7012 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability*/

/*************************************************************************************************************************
  Functionname:      HEADSet_Qualifiers                                                                               */ /*!

  @brief             set the Qualifiers

  @description      It is setting  the Qualifiers (ePedFunctionQualifier, eVehFunctionQualifier, eCyclFunctionQualifier, 
                    eUnclassifiedFunctionQualifier) based on the state of corresponding coding, switches, eReportedError and 
                    eQoS.For each type of object  FCW,autobrk,brakeassist,BrakePreCond  modules are set.Each of the above module
                    is analyzed and set with ( If the module is coded, switched, module for errors  or silent errors, Qos state).
                     
                    @startuml
                    Start
                        :Qualifier for Pedestrian function;
                        Note Left 
                        Same procedures are following in the Vehicle, Cyclist and Unclassified function.
                        In each function have FCW, AutoBrk, BrakeAssist and BrakePreCond Qualifier  
                        End note
                        Note right 
                        The Vehicle and Unclassified have DistWarn Qualifier 
                        End note
                        If(Check for HEADGetEBACoding return type true) then (True) 
                        #orange:Assign Qualifier coded details
                        <b> HEADGetEBACoding <b> >
                        If(Check for HEADGetEBASwitch return type is true) then (True)
                        #orange:Assign Qualifier switched details 
                        <b> HEADGetEBASwitch <b> >
                        Note Left
                        Same procedures are following in the Pedestrian, Vehicle and Cyclist function.
                        In each Qualifier have switched details except BrakeAssist and BrakePreCond Qualifier  
                        End note 
                        Note Left
                        Unclassified function switched details are only present in the FCW, AutoBrk Qualifier
                        End note
                        If(check for SPM reported error is normal mode ?) then (yes)
                        :Set the mode error detail to the function qualifier;
                        If(Is module Qos normal running?) then(Yes)
                        : Set the degraded details the function qualifier;;
                        Endif
                        Endif
                        Endif
                        endif
                    Stop
                    @enduml

  @return           void

  @param[in,out]     pModules : Pointer to head Module

  @glob_in           None
  @glob_out          None

  @c_switch_part     None
  @c_switch_full     @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre               None
  @post              None
  
  @InOutCorrelation  Not defined

  @testmethod        Test of output data (dynamic module test)

  @traceability 

  @author            Ayman Almalih | ayman.almalih@continental-corporation.com
*************************************************************************************************************************/

static void HEADSet_Qualifiers(HEADModule_t const * const pModules[])
{
  uint16 uEBA_CODING_FCW_Bitfield        = (EBA_CODING_BIT_DYN_WARN1  | EBA_CODING_BIT_DYN_WARN2  | EBA_CODING_BIT_DYN_WARN3);
  uint16 uEBA_CODING_AutoBrk_Bitfield    = (EBA_CODING_BIT_AUTOBRK1   | EBA_CODING_BIT_AUTOBRK2   | EBA_CODING_BIT_AUTOBRK3 );
  uint16 uEBA_CODING_DistWarn_Bitfield   = (EBA_CODING_BIT_DIST_WARN1 | EBA_CODING_BIT_DIST_WARN2                           );
  uint16 uEBA_CODING_HBA_Bitfield        = (EBA_CODING_BIT_HBA1       | EBA_CODING_BIT_HBA2                                 );
  uint16 uEBA_CODING_PreFill_Bitfield    = (EBA_CODING_BIT_PREFILL1   | EBA_CODING_BIT_PREFILL2                             );

  /*-------------------------------------*/
  /* Qualifier for Pedestrian function   */
  /*-------------------------------------*/
  /* Qualifier for FCW   */
  if(  (HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_LongPedMov    ) != FALSE)                        /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_LongPedStat   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_CrossPedMov   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_CrossPedStat  ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_FCW_Coded;
    if(  (HEADGetEBASwitch(eEBASwitch_LongVruFCW1 ) != FALSE)                                                   /* if switched on */
       ||(HEADGetEBASwitch(eEBASwitch_LongVruFCW2 ) != FALSE)
       ||(HEADGetEBASwitch(eEBASwitch_LongVruFCW3 ) != FALSE)
       ||(HEADGetEBASwitch(eEBASwitch_CrossVruFCW1) != FALSE)
       ||(HEADGetEBASwitch(eEBASwitch_CrossVruFCW2) != FALSE)
       ||(HEADGetEBASwitch(eEBASwitch_CrossVruFCW3) != FALSE)
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_FCW_Switched;
      if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn  ]->eReportedError == HEADModuleRepError_NoError)    /* module eReportedError = NoError */
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn ]->eReportedError == HEADModuleRepError_NoError)
        )   
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_FCW_NoError;
        if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn   ]->eQoS == HEADModuleQoS_NormalRunning)          /* module eQoS = NormalRunning */
           ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn  ]->eQoS == HEADModuleQoS_NormalRunning)
          )   
        {
          MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_FCW_NoDegraded;
        }
      }
    }
  }

  /* Qualifier for AutoBrk   */
  if(  (HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_LongPedMov   ) != FALSE)                          /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_LongPedStat  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_CrossPedMov  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_CrossPedStat ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_AutoBrk_Coded;
    if(  (HEADGetEBASwitch(eEBASwitch_LongVruBRK   ) != FALSE)                                                    /* if switched on */
       ||(HEADGetEBASwitch(eEBASwitch_CrossVruBRK  ) != FALSE)
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_AutoBrk_Switched;
      if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_Brk1     ]->eReportedError == HEADModuleRepError_NoError)        /* module eReportedError = NoError */
         ||(pModules[HEAD_AUTOCODE_MOD_LongVru_Brk2     ]->eReportedError == HEADModuleRepError_NoError)
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk  ]->eReportedError == HEADModuleRepError_NoError)
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk2 ]->eReportedError == HEADModuleRepError_NoError)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_AutoBrk_NoError;
        if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_Brk1     ]->eQoS == HEADModuleQoS_NormalRunning)               /* module eQoS = NormalRunning */
           ||(pModules[HEAD_AUTOCODE_MOD_LongVru_Brk2     ]->eQoS == HEADModuleQoS_NormalRunning)
           ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk  ]->eQoS == HEADModuleQoS_NormalRunning)
           ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk2 ]->eQoS == HEADModuleQoS_NormalRunning)
          )
        {
          MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_AutoBrk_NoDegraded;
        }
      }
    }
  }

  /* Qualifier for BrakeAssist   */
  if(  (HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_LongPedMov   ) != FALSE)                             /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_LongPedStat  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_CrossPedMov  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_CrossPedStat ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_BrakeAssist_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_BrakeAssist_Switched;
    if(pModules[HEAD_AUTOCODE_MOD_CrossVru_HBA]->eReportedError == HEADModuleRepError_NoError)                /* module eReportedError = NoError */
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_BrakeAssist_NoError;
      if(pModules[HEAD_AUTOCODE_MOD_CrossVru_HBA]->eQoS == HEADModuleQoS_NormalRunning)                       /* module eQoS = NormalRunning */
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_BrakeAssist_NoDegraded;
      }
    }
  }

  /* Qualifier for BrakePreCond   */
  if(  (HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_LongPedMov   ) != FALSE)                         /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_LongPedStat  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_CrossPedMov  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_CrossPedStat ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_BrakePreCond_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_BrakePreCond_Switched;
    if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_Prefill  ]->eReportedError == HEADModuleRepError_NoError)            /* module eReportedError = NoError */
       ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_Prefill ]->eReportedError == HEADModuleRepError_NoError)
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_BrakePreCond_NoError;
      if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_Prefill  ]->eQoS == HEADModuleQoS_NormalRunning)                   /* module eQoS = NormalRunning */
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_Prefill ]->eQoS == HEADModuleQoS_NormalRunning)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.ePedFunctionQualifier |= eStatus_BrakePreCond_NoDegraded;
      }
    }
  }

  /*-------------------------------------*/
  /* Qualifier for Vehicle function   */
  /*-------------------------------------*/
  /* Qualifier for FCW   */
  if(  (HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_LongVehMov   ) != FALSE)                           /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_LongVehStat  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_CrossVehMov  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_CrossVehStat ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_FCW_Coded;
    if  (  (HEADGetEBASwitch(eEBASwitch_LongVehFCW1   ) != FALSE)                                                   /* if switched on */
         ||(HEADGetEBASwitch(eEBASwitch_LongVehFCW2   ) != FALSE)
         ||(HEADGetEBASwitch(eEBASwitch_LongVehFCW3   ) != FALSE)
         ||(HEADGetEBASwitch(eEBASwitch_CrossVehFCW1  ) != FALSE)
         ||(HEADGetEBASwitch(eEBASwitch_CrossVehFCW2  ) != FALSE)
         ||(HEADGetEBASwitch(eEBASwitch_CrossVehFCW3  ) != FALSE)
        )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_FCW_Switched;
      if(  (pModules[HEAD_AUTOCODE_MOD_DynPreWarn   ]->eReportedError == HEADModuleRepError_NoError)                /* module eReportedError = NoError */
         ||(pModules[HEAD_AUTOCODE_MOD_DynAcuteWarn ]->eReportedError == HEADModuleRepError_NoError)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_FCW_NoError;
        if(  (pModules[HEAD_AUTOCODE_MOD_DynPreWarn   ]->eQoS == HEADModuleQoS_NormalRunning)                    /* module eQoS = NormalRunning */
           ||(pModules[HEAD_AUTOCODE_MOD_DynAcuteWarn ]->eQoS == HEADModuleQoS_NormalRunning)
          )
        {
          MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_FCW_NoDegraded;
        }
      }
    }
  }

  /* Qualifier for AutoBrk   */
  if (  (HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_LongVehMov   ) != FALSE)                           /* if coded */
      ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_LongVehStat  ) != FALSE)
      ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_CrossVehMov  ) != FALSE)
      ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_CrossVehStat ) != FALSE)
     )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_AutoBrk_Coded;
    if(  (HEADGetEBASwitch(eEBASwitch_LongVehBRK )   != FALSE)                                                    /* if switched on */
       ||(HEADGetEBASwitch(eEBASwitch_CrossVehBRK)   != FALSE)
      )
    {
     MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_AutoBrk_Switched;
      if(  (pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk1 ]->eReportedError == HEADModuleRepError_NoError)              /* module eReportedError = NoError */
         ||(pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk2 ]->eReportedError == HEADModuleRepError_NoError)
         ||(pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk3 ]->eReportedError == HEADModuleRepError_NoError)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_AutoBrk_NoError;
        if (  (pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk1 ]->eQoS == HEADModuleQoS_NormalRunning)                     /* module eQoS = NormalRunning */
            ||(pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk2 ]->eQoS == HEADModuleQoS_NormalRunning)
            ||(pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk3 ]->eQoS == HEADModuleQoS_NormalRunning)
           )
        {
          MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_AutoBrk_NoDegraded;
        }
      }
    }
  }

  /* Qualifier for DistWarn   */
  if(  (HEADGetEBACoding(uEBA_CODING_DistWarn_Bitfield, eEBACodingIdx_LongVehMov )  != FALSE)                           /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_DistWarn_Bitfield, eEBACodingIdx_CrossVehMov)  != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_DistWarn_Coded;
    if(  (HEADGetEBASwitch(eEBASwitch_LongVehDW )   != FALSE)                                                      /* if switched on */
       ||(HEADGetEBASwitch(eEBASwitch_CrossVehDW)   != FALSE)
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_DistWarn_Switched;
      if(  (pModules[HEAD_AUTOCODE_MOD_LatPreWarn    ]->eReportedError == HEADModuleRepError_NoError)            /* module eReportedError = NoError */
         ||(pModules[HEAD_AUTOCODE_MOD_LatAcuteWarn  ]->eReportedError == HEADModuleRepError_NoError)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_DistWarn_NoError;
        if(  (pModules[HEAD_AUTOCODE_MOD_LatPreWarn    ]->eQoS == HEADModuleQoS_NormalRunning)                   /* module eQoS = NormalRunning */
           ||(pModules[HEAD_AUTOCODE_MOD_LatAcuteWarn  ]->eQoS == HEADModuleQoS_NormalRunning)
          )
        {
          MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_DistWarn_NoDegraded;
        }
      }
    }
  }

  /* Qualifier for BrakeAssist   */
  if(  (HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_LongVehMov    ) != FALSE)                             /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_LongVehStat   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_CrossVehMov   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_CrossVehStat  ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_BrakeAssist_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_BrakeAssist_Switched;
    if(  (pModules[HEAD_AUTOCODE_MOD_HBA_TA   ]->eReportedError == HEADModuleRepError_NoError)                    /* module eReportedError = NoError */
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_BrakeAssist_NoError;
      if(  (pModules[HEAD_AUTOCODE_MOD_HBA_TA  ]->eQoS == HEADModuleQoS_NormalRunning)                          /* module eQoS = NormalRunning */

        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_BrakeAssist_NoDegraded;
      }
    }
  }

  /* Qualifier for BrakePreCond   */
  if(  (HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_LongVehMov    ) != FALSE)                        /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_LongVehStat   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_CrossVehMov   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_CrossVehStat  ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_BrakePreCond_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_BrakePreCond_Switched;
    if(  pModules[HEAD_AUTOCODE_MOD_Prefill]->eReportedError == HEADModuleRepError_NoError                    /* module eReportedError = NoError */
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_BrakePreCond_NoError;
      if(pModules[HEAD_AUTOCODE_MOD_Prefill]->eQoS == HEADModuleQoS_NormalRunning                             /* module eQoS = NormalRunning */
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eVehFunctionQualifier |= eStatus_BrakePreCond_NoDegraded;
      }
    }
  }

  /*-------------------------------------*/
  /* Qualifier for Cyclist function   */
  /*-------------------------------------*/
  /* Qualifier for FCW   */
  if(  (HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_LongCyclMov   ) != FALSE)                      /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_LongCyclStat  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_CrossCyclMov  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_CrossCyclStat ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_FCW_Coded;
    if(  (HEADGetEBASwitch(eEBASwitch_LongVruFCW1  ) != FALSE)                                                  /* if switched on */
       ||(HEADGetEBASwitch(eEBASwitch_LongVruFCW2  ) != FALSE)
       ||(HEADGetEBASwitch(eEBASwitch_LongVruFCW3  ) != FALSE)
       ||(HEADGetEBASwitch(eEBASwitch_CrossVruFCW1 ) != FALSE)
       ||(HEADGetEBASwitch(eEBASwitch_CrossVruFCW2 ) != FALSE)
       ||(HEADGetEBASwitch(eEBASwitch_CrossVruFCW3 ) != FALSE)
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_FCW_Switched;
      if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn  ]->eReportedError == HEADModuleRepError_NoError)   /* module eReportedError = NoError */
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn ]->eReportedError == HEADModuleRepError_NoError) 
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_FCW_NoError;
        if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn  ]->eQoS == HEADModuleQoS_NormalRunning)          /* module eQoS = NormalRunning */
           ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn ]->eQoS == HEADModuleQoS_NormalRunning)
          )
        {
          MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_FCW_NoDegraded;
        }
      }
    }
  }

  /* Qualifier for AutoBrk   */
  if(  (HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_LongCyclMov    ) != FALSE)                      /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_LongCyclStat   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_CrossCyclMov   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_CrossCyclStat  ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_AutoBrk_Coded;
    if(  (HEADGetEBASwitch(eEBASwitch_LongVruBRK   ) != FALSE)                                                  /* if switched on */
       ||(HEADGetEBASwitch(eEBASwitch_CrossVruBRK  ) != FALSE)
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_AutoBrk_Switched;
      if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_Brk1      ]->eReportedError == HEADModuleRepError_NoError)       /* module eReportedError = NoError */
         ||(pModules[HEAD_AUTOCODE_MOD_LongVru_Brk2      ]->eReportedError == HEADModuleRepError_NoError)
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk   ]->eReportedError == HEADModuleRepError_NoError)
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk2  ]->eReportedError == HEADModuleRepError_NoError)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_AutoBrk_NoError;
        if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_Brk1      ]->eQoS == HEADModuleQoS_NormalRunning)              /* module eQoS = NormalRunning */
           ||(pModules[HEAD_AUTOCODE_MOD_LongVru_Brk2      ]->eQoS == HEADModuleQoS_NormalRunning)
           ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk   ]->eQoS == HEADModuleQoS_NormalRunning)
           ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk2  ]->eQoS == HEADModuleQoS_NormalRunning)
          )
        {
          MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_AutoBrk_NoDegraded;
        }
      }
    }
  }

  /* Qualifier for BrakeAssist   */
  if(  (HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_LongCyclMov   ) != FALSE)                            /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_LongCyclStat  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_CrossCyclMov  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_CrossCyclStat ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_BrakeAssist_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_BrakeAssist_Switched;
    if(pModules[HEAD_AUTOCODE_MOD_CrossVru_HBA]->eReportedError == HEADModuleRepError_NoError)                /* module eReportedError = NoError */
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_BrakeAssist_NoError;
      if(pModules[HEAD_AUTOCODE_MOD_CrossVru_HBA]->eQoS == HEADModuleQoS_NormalRunning)                       /* module eQoS = NormalRunning */
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_BrakeAssist_NoDegraded;
      }
    }
  }

  /* Qualifier for BrakePreCond   */
  if(  (HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_LongCyclMov    ) != FALSE)                      /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_LongCyclStat   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_CrossCyclMov   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_CrossCyclStat  ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_BrakePreCond_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_BrakePreCond_Switched;
    if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_Prefill   ]->eReportedError == HEADModuleRepError_NoError)         /* module eReportedError = NoError */
       ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_Prefill  ]->eReportedError == HEADModuleRepError_NoError)         
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_BrakePreCond_NoError;
      if(  (pModules[HEAD_AUTOCODE_MOD_LongVru_Prefill   ]->eQoS == HEADModuleQoS_NormalRunning)                /* module eQoS = NormalRunning */
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_Prefill  ]->eQoS == HEADModuleQoS_NormalRunning)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eCyclFunctionQualifier |= eStatus_BrakePreCond_NoDegraded;
      }
    }
  }

  /*-------------------------------------*/
  /* Qualifier for Unclassified function   */
  /*-------------------------------------*/
  /* Qualifier for FCW   */
  if(  (HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_LongObsMov   ) != FALSE)                        /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_LongObsStat  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_CrossObsMov  ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_FCW_Bitfield, eEBACodingIdx_CrossObsStat ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_FCW_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_FCW_Switched;
    if(  (pModules[HEAD_AUTOCODE_MOD_DynPreWarn            ]->eReportedError == HEADModuleRepError_NoError)     /* module eReportedError = NoError */
       ||(pModules[HEAD_AUTOCODE_MOD_DynAcuteWarn          ]->eReportedError == HEADModuleRepError_NoError)
       ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn ]->eReportedError == HEADModuleRepError_NoError)
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_FCW_NoError;
      if(  (pModules[HEAD_AUTOCODE_MOD_DynPreWarn            ]->eQoS == HEADModuleQoS_NormalRunning)            /* module eQoS = NormalRunning */
         ||(pModules[HEAD_AUTOCODE_MOD_DynAcuteWarn          ]->eQoS == HEADModuleQoS_NormalRunning)
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn ]->eQoS == HEADModuleQoS_NormalRunning)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_FCW_NoDegraded;
      }
    }
  }

  /* Qualifier for AutoBrk   */
  if(  (HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_LongObsMov    ) != FALSE)                        /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_LongObsStat   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_CrossObsMov   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_AutoBrk_Bitfield, eEBACodingIdx_CrossObsStat  ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_AutoBrk_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_AutoBrk_Switched;
    if(  (pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk1      ]->eReportedError == HEADModuleRepError_NoError)         /* module eReportedError = NoError */
       ||(pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk2      ]->eReportedError == HEADModuleRepError_NoError)
       ||(pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk3      ]->eReportedError == HEADModuleRepError_NoError)
       ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk   ]->eReportedError == HEADModuleRepError_NoError)
       ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk2  ]->eReportedError == HEADModuleRepError_NoError)
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_AutoBrk_NoError;
      if(  (pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk1      ]->eQoS == HEADModuleQoS_NormalRunning)                /* module eQoS = NormalRunning */
         ||(pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk2      ]->eQoS == HEADModuleQoS_NormalRunning)
         ||(pModules[HEAD_AUTOCODE_MOD_Veh_AutoBrk3      ]->eQoS == HEADModuleQoS_NormalRunning)
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk   ]->eQoS == HEADModuleQoS_NormalRunning)
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_PreBrk2  ]->eQoS == HEADModuleQoS_NormalRunning)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_AutoBrk_NoDegraded;
      }
    }
  }

  /* Qualifier for DistWarn   */
  if(  (HEADGetEBACoding(uEBA_CODING_DistWarn_Bitfield, eEBACodingIdx_LongObsMov ) != FALSE)                        /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_DistWarn_Bitfield, eEBACodingIdx_CrossObsMov) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_DistWarn_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_DistWarn_Switched;
    if(  (pModules[HEAD_AUTOCODE_MOD_LatPreWarn    ]->eReportedError == HEADModuleRepError_NoError)            /* module eReportedError = NoError */
       ||(pModules[HEAD_AUTOCODE_MOD_LatAcuteWarn  ]->eReportedError == HEADModuleRepError_NoError)
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_DistWarn_NoError;
      if(  (pModules[HEAD_AUTOCODE_MOD_LatPreWarn    ]->eQoS == HEADModuleQoS_NormalRunning)                   /* module eQoS = NormalRunning */
         ||(pModules[HEAD_AUTOCODE_MOD_LatAcuteWarn  ]->eQoS == HEADModuleQoS_NormalRunning)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_DistWarn_NoDegraded;
      }
    }
  }

  /* Qualifier for BrakeAssist   */
  if(  (HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_LongObsMov    ) != FALSE)                           /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_LongObsStat   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_CrossObsMov   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_HBA_Bitfield, eEBACodingIdx_CrossObsStat  ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_BrakeAssist_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_BrakeAssist_Switched;
    if(  (pModules[HEAD_AUTOCODE_MOD_HBA_TA        ]->eReportedError == HEADModuleRepError_NoError)            /* module eReportedError = NoError */
       ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_HBA  ]->eReportedError == HEADModuleRepError_NoError)
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_BrakeAssist_NoError;
      if(  (pModules[HEAD_AUTOCODE_MOD_HBA_TA        ]->eQoS == HEADModuleQoS_NormalRunning)                   /* module eQoS = NormalRunning */
         ||(pModules[HEAD_AUTOCODE_MOD_CrossVru_HBA  ]->eQoS == HEADModuleQoS_NormalRunning)
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_BrakeAssist_NoDegraded;
      }
    }
  }

  /* Qualifier for BrakePreCond   */
  if(  (HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_LongObsMov    ) != FALSE)                       /* if coded */
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_LongObsStat   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_CrossObsMov   ) != FALSE)
     ||(HEADGetEBACoding(uEBA_CODING_PreFill_Bitfield, eEBACodingIdx_CrossObsStat  ) != FALSE)
    )
  {
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_BrakePreCond_Coded;
    MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_BrakePreCond_Switched;
    if(pModules[HEAD_AUTOCODE_MOD_Prefill]->eReportedError == HEADModuleRepError_NoError                     /* module eReportedError = NoError */
      )
    {
      MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_BrakePreCond_NoError;
      if(pModules[HEAD_AUTOCODE_MOD_Prefill]->eQoS == HEADModuleQoS_NormalRunning                            /* module eQoS = NormalRunning */
        )
      {
        MEDIC_p_ModHeadOutCustom()->sFCTQualifiers.eUnclassifiedFunctionQualifier |= eStatus_BrakePreCond_NoDegraded;
      }
    }
  }
} /* PRQA S 7004, 7012 *//* date: 2018-10-26, reviewer:Krupa H R, reason:suppressing cyclomatic complexity for better code maintainability */

/*************************************************************************************************************************
  Functionname:         HEADOutArbitration                                                                          */ /*!

  @brief                calls HEAD output arbitrations

  @description          calls HEAD output arbitrations

                        @startuml
                        Start
                            :HEAD Module output arbitration;
                        Note right
                            Run Arbitration for HEAD Module output Data
                        End note
                        Stop
                        @enduml    

  @return               eGDBError_t      :GDB error type is returned

  @param[in]            Void
  
  @glob_in              @ref HEADModuleOutputData
  @glob_out             @ref HEADModuleOutputData

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADOutArbitration(void)
{
  eGDBError_t eError = GDB_ERROR_NONE;
  HEADOutArbitrateLatPreWarn();
  HEADOutArbitrateLatAcuteWarn();
  HEADOutArbitratePrefill();
  HEADOutArbitrateBrake();
  HEADOutArbitratePreWarning();
  HEADOutArbitrateAcuteWarning();
  return eError;
}

/*************************************************************************************************************************
  Functionname:         HEADOutArbitrateLatPreWarn                                                                  */ /*!

  @brief                custom output arbitration for LatPreWarn function

  @description          Following function is for setting the Fct channel for latent pre warn module.
                        If the  latent pre warn  function is active and hypothesis is present for this module 
                        then signal state and FCt channel are set for the  latent pre warn  module from the output of toggle function
                        else  signal state and channel are set as Inactive and unknown respectively.     
                                   
                        @startuml
                        Start
                            If(check latent pre warn function is actve or not) then (Active)
                            If(Is active hypothesis available?)then (Yes)
                            : Update EBA signal state and EBA FCT Channel;
                             Else (No)
                            :Update output values from stored values;
                            Endif 
                            Else (Inactive)
                            :reset latent pre Warn signal state and function channel;
                            Endif
                            : Update pre warn signal state and function channel ;
                        Stop
                        @enduml
  
  @return               void

  @param[in]            None

  @glob_in              None
  @glob_out             @ref HEADLatPreWarnSigState \n @ref HEADLatPreWarnFctChannel

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 

  @author               Andreas Jakob | andreas.jakob-ext@conti-engineering.com
*************************************************************************************************************************/

static void HEADOutArbitrateLatPreWarn(void)
{
  if(HEADModuleOutputData.LatPreWarn.bOutFunctionActive == TRUE)
  {
    if(HEADModuleOutputData.LatPreWarn.ActHypNr != HEADNoHypothesis)
    {
      /*store values from toggle function, as long as hyp is available*/
      MEDIC_p_GetEBASignalState()->HEADLatPreWarnSigState  = HEADModuleOutputData.LatPreWarn.eEBASignalState;
      MEDIC_p_GetEBAFctChan()->HEADLatPreWarnFctChannel    = HEADModuleOutputData.LatPreWarn.eEBAFctChannel;
    }
    else
    {
      /*write stored values to Output when hyp is not available but function is active*/
    }
  }
  else
  {
    MEDIC_p_GetEBASignalState()->HEADLatPreWarnSigState    = eEBAOn_Inactive;
    MEDIC_p_GetEBAFctChan()->HEADLatPreWarnFctChannel      = eEBAFctChan_Unknown;
  }
  
  HEADModuleOutputData.LatPreWarn.eEBASignalState          = MEDIC_p_GetEBASignalState()->HEADLatPreWarnSigState;
  HEADModuleOutputData.LatPreWarn.eEBAFctChannel           = MEDIC_p_GetEBAFctChan()->HEADLatPreWarnFctChannel;
}

/************************************************************************************************************************
  Functionname:         HEADOutArbitrateLatAcuteWarn                                                               */ /*!

  @brief                custom output arbitration for LatAcuteWarn function

  @description          Following function is for setting the Fct channel for latent acute warn module.
                        If the latent acute warn  function is active and hypothesis is presence for this module then 
                        signal state and FCt channel are set for the  latent acute warn  module from the output of toggle function
                        Else signal state and channel are set as Inactive and unknown respectively.

                        @startuml
                        Start
                            If(Is Latent Acute Warning active?) then (Yes)
                            If(Is active hypothesis available ?)then (Yes)
                            :Update EBA signal state and EBA FCT Channel;
                            Else (Yes)
                            :If hypothesis is not available then update output values from stored values;
                            Endif 
                            Else (Inactive)
                            :reset Acute Warn signal state and function channel;
                            Endif
                            :Update acute warn signal state and function channel ;
                        Stop
                        @enduml
  
  @return               void

  @param[in]            None 

  @glob_in              None
  @glob_out             @ref HEADLatAcuteWarnSigState \n @ref HEADLatAcuteWarnFctChannel

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 

  @author               Andreas Jakob | andreas.jakob-ext@conti-engineering.com
*************************************************************************************************************************/
static void HEADOutArbitrateLatAcuteWarn(void)
{
  if(HEADModuleOutputData.LatAcuteWarn.bOutFunctionActive == TRUE)
  {
    if(HEADModuleOutputData.LatAcuteWarn.ActHypNr != HEADNoHypothesis)
    {
      /*store values from toggle function, as long as hyp is available*/
      MEDIC_p_GetEBASignalState()->HEADLatAcuteWarnSigState   = HEADModuleOutputData.LatAcuteWarn.eEBASignalState;
      MEDIC_p_GetEBAFctChan()->HEADLatAcuteWarnFctChannel     = HEADModuleOutputData.LatAcuteWarn.eEBAFctChannel;
    }
    else
    {
      /*write stored values to Output when hyp is not available but function is active*/
    }
  }
  else
  {
    MEDIC_p_GetEBASignalState()->HEADLatAcuteWarnSigState    = eEBAOn_Inactive;
    MEDIC_p_GetEBAFctChan()->HEADLatAcuteWarnFctChannel      = eEBAFctChan_Unknown;
  }

  HEADModuleOutputData.LatAcuteWarn.eEBASignalState          = MEDIC_p_GetEBASignalState()->HEADLatAcuteWarnSigState;
  HEADModuleOutputData.LatAcuteWarn.eEBAFctChannel           = MEDIC_p_GetEBAFctChan()->HEADLatAcuteWarnFctChannel;
}


/* *************************************************************************************************************************
  Functionname:         HEADOutArbitratePrefill                                                                       */ /*!

  @brief                custom output arbitration for Prefill function

  @description          Here we are arbitrating the Prefill channel and filling the channel with most critical channel.
                        Most critical can be either normal Prefill or Prefill for Vulnerable road user.

                        If the out function for Normal prefill is active and hypothesis is available for prefill module.
                        Prefill channel, active hypnumber(VALID),prefill active signal (TRUE) and signal status (VALID) are set appropriately
                        else there are set to Unclassified and invalid.

                        If the out function for Vulnerable road user prefill is active and hypothesis is available for prefill module.
                        Prefill channel, active hypnumber(VALID),prefill active signal (TRUE) and signal status (VALID) are set appropriately
                        else there are set to Unclassified and invalid.

                        @startuml
                        Start
                            :initialize fucnction channel and signal state; 
                            If(check all Prefill activations) then (True)
                            If(check  Prefill Hypothesis availabilities) then (available)
                            : HEAD Module Output Toggle Function will be updated;
                            Endif
                            endif
                            If(check vulnerable road user Prefill activations) then (active)
                            :Fetch head hypothesis information;
                            If(Is Prefill Hypothesis available?) then (available)
                            If(Is necessary acceleration  stronger?) then (yes)
                            : HEAD Module Output Toggle Function will be updated;
                            Endif
                            Endif
                            Endif
                            If(check Longitude vulnerable road user Prefill activations status) then (active)
                            :Fetch head hypothesis information;
                            If(check  Prefill Hypothesis availabilities) then (available)
                            If(Is necessary acceleration  strong?) then (yes)
                            : HEAD Module Output Toggle Function will be updated;
                            Endif
                            Endif
                            Endif
                            :Local scope variable information is written back to global variable;
                        Stop
                        @enduml
  
  @return               void

  @param[in]            None

  @glob_in              None
  @glob_out             @ref HEADPrefillFctChannel

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 

  @author               Andreas Jakob | andreas.jakob-ext@conti-engineering.com
*************************************************************************************************************************/
static void HEADOutArbitratePrefill(void)
{
  boolean bPrefillActive = FALSE;
  eEBASignalState_t eSignalState = eEBAOn_Inactive;
  float32 fANec = 0;
  HEADHypothesisNr_t uiHeadNr = HEADNoHypothesis;
  const HEADHypothesis_t* pPrefillHyp = NULL;
  eEBAFctChan_t tempEBAFctChan = eEBAFctChan_Unknown;

  /*check all Prefill-activations and arbitrate by aNec*/
  if(HEADModuleOutputData.Prefill.bOutFunctionActive == TRUE)
  {
    /* set to PrefillFctChannel of the last cycle*/
    tempEBAFctChan = MEDIC_p_GetEBAFctChan()->HEADPrefillFctChannel;
    bPrefillActive = TRUE;
    pPrefillHyp = HEADGetHypothesis(MEDIC_p_ModHEADInputData()->rgHypothesisList, HEADModuleOutputData.Prefill.ActHypNr);
    if(pPrefillHyp != NULL)
    {
      fANec         = pPrefillHyp->pHypothesis->fLongNecAccel;
      uiHeadNr      = HEADModuleOutputData.Prefill.ActHypNr;
      tempEBAFctChan = HEADModuleOutputData.Prefill.eEBAFctChannel;
      #if(HEAD_DO_NOT_SET_CHANNEL_UNCLASSIFIED == SWITCH_ON)
      {
        tempEBAFctChan = HEADCheckForUnclassfied((pPrefillHyp->pHypothesis), MEDIC_p_GetEBAFctChan()->HEADPrefillFctChannel);
      }
      #endif
      eSignalState  = HEADModuleOutputData.Prefill.eEBASignalState;
    }

  }
  if(HEADModuleOutputData.CrossVru_Prefill.bOutFunctionActive == TRUE)
  {
    tempEBAFctChan = MEDIC_p_GetEBAFctChan()->HEADPrefillFctChannel;
    bPrefillActive = TRUE;
    pPrefillHyp = HEADGetHypothesis(MEDIC_p_ModHEADInputData()->rgHypothesisList, HEADModuleOutputData.CrossVru_Prefill.ActHypNr);
    if(pPrefillHyp != NULL)
    {
      if( (pPrefillHyp->pHypothesis->fLongNecAccel) < fANec )
      {
        uiHeadNr      = HEADModuleOutputData.CrossVru_Prefill.ActHypNr;
        tempEBAFctChan = HEADModuleOutputData.CrossVru_Prefill.eEBAFctChannel;
        #if(HEAD_DO_NOT_SET_CHANNEL_UNCLASSIFIED == SWITCH_ON)
        {
          tempEBAFctChan = HEADCheckForUnclassfied((pPrefillHyp->pHypothesis), MEDIC_p_GetEBAFctChan()->HEADPrefillFctChannel);
        }
        #endif
        eSignalState  = HEADModuleOutputData.CrossVru_Prefill.eEBASignalState;
      }
    }
  }

  if(HEADModuleOutputData.LongVru_Prefill.bOutFunctionActive == TRUE)
  {
    tempEBAFctChan = MEDIC_p_GetEBAFctChan()->HEADPrefillFctChannel;
    bPrefillActive = TRUE;
    pPrefillHyp = HEADGetHypothesis(MEDIC_p_ModHEADInputData()->rgHypothesisList, HEADModuleOutputData.LongVru_Prefill.ActHypNr);
    if(pPrefillHyp != NULL)
    {
      if( (pPrefillHyp->pHypothesis->fLongNecAccel) < fANec )
      {
        uiHeadNr       = HEADModuleOutputData.LongVru_Prefill.ActHypNr;
        #if(HEAD_DO_NOT_SET_CHANNEL_UNCLASSIFIED == SWITCH_ON)
        tempEBAFctChan = HEADCheckForUnclassfied((pPrefillHyp->pHypothesis), MEDIC_p_GetEBAFctChan()->HEADPrefillFctChannel);
        #else
        tempEBAFctChan = HEADModuleOutputData.LongVru_Prefill.eEBAFctChannel;
        #endif
        eSignalState = HEADModuleOutputData.LongVru_Prefill.eEBASignalState;
      }
    }
  }
  /* temporary function channel is written back to global variable*/
  MEDIC_p_GetEBAFctChan()->HEADPrefillFctChannel  = tempEBAFctChan;
  HEADModuleOutputData.Prefill.bOutFunctionActive = bPrefillActive;
  HEADModuleOutputData.Prefill.eEBASignalState    = eSignalState;
  HEADModuleOutputData.Prefill.ActHypNr           = uiHeadNr;
  HEADModuleOutputData.Prefill.eEBAFctChannel     = MEDIC_p_GetEBAFctChan()->HEADPrefillFctChannel;
}

/***********************************************************************************************************************
  Functionname          HEADOutArbitrateBrake                                                                    */ /*! 
  
  @brief                custom output arbitration for brake function
  
  @description          Following function is for setting the Fct channel for brake module.
                        If the hypothesis for vehautobrk1 module is present then a valid channel is assigned based on the object class.
                 
                        If the object class is Pedestrian then Pedestrian fct channel is assigned.
                        If the object class is crossing then crossing fct channel is assigned.
                        If the object class is cyclist then cyclist fct channel is assigned.
                        If the object class is vehicle then vehicle fct channel is assigned.
                        If the object class is Pedestrian then Pedestrian fct channel is assigned.
                        If the object class is unclassified then unknown (0)fct channel is assigned.  Etc.

                        If MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION is enabled then depending on Veh_AutoBrk1.
                        Pre Brake state camera confirmation is done for brake activation.
                        If the Veh_AutoBrk1.pePreBrakeStat is not in RAMP or PASSIVE state camera conformation is derived from object probability.

                        @startuml
                        Start
                            If(Status of vehicle pre break   ) then (active)
                            :fetch head Hypothesis value;
                            If(check Availability of Vehicle Auto Break Hypothesis) then (available)
                            If(Is function channel switched on? ) then (yes)
                            : set function channel from current hyp;
                            Else If(check function channel is unknown channel ) then (yes)
                            : set function channel once again from current hypothesis;
                            Endif
                            If(Is unclassified function channel switched on?) then (Yes)
                            : unclassified function Channel object to be updated;
                            Endif
                            else
                            :brake is active without hyp;
                            Endif
                            Else (Inactive)
                            :reset function channel;
                            Endif
                            :update break function channel;
                            : set camera confirmation;
                            Note left 
                            Camara confirmation updated After getting confirmation from 
                            the second sensor 
                            End note 
                        Stop
                        @enduml
  
  @return               void

  @param[in]            None

  @glob_in              None
  @glob_out             @ref HEADBrakeFctChannel \n @ref HEADPreBrakeCamConfirm

  @c_switch_part        @ref MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 

  @author               Andreas Jakob | andreas.jakob-ext@conti-engineering.com
*************************************************************************************************************************/
static void HEADOutArbitrateBrake(void)
{
  eEBAFctChan_t tempFctChan = MEDIC_p_GetEBAFctChan()->HEADBrakeFctChannel;

  /*arbitrate*/
  if( *(HEADModuleOutputData.Veh_AutoBrk1.pbPreBrakeActive) == TRUE )
  { 
     const HEADHypothesis_t* pVehAutoBrk1Hyp = HEADGetHypothesis(MEDIC_p_ModHEADInputData()->rgHypothesisList, *(HEADModuleOutputData.Veh_AutoBrk1.pActHypNr));
    if(pVehAutoBrk1Hyp != NULL)
    {
      const Hypothesis_t* pHyp  = pVehAutoBrk1Hyp->pHypothesis;
      #if(HEAD_USE_CHANGE_FUNCTIONCHANNEL == SWITCH_ON)
      /*set function channel from current hyp*/
      tempFctChan = HEADGetFctChannel(pHyp);
      #else
      if(MEDIC_p_GetEBAFctChan()->HEADBrakeFctChannel == eEBAFctChan_Unknown)
      {
        /*brake is active and function channel not set -> set fctChannel once*/
        tempFctChan = HEADGetFctChannel(pHyp);
      }
      #endif
      #if(HEAD_DO_NOT_SET_CHANNEL_UNCLASSIFIED == SWITCH_ON)
      tempFctChan = HEADCheckForUnclassfied(pHyp, MEDIC_p_GetEBAFctChan()->HEADBrakeFctChannel);
      #endif
      MEDIC_p_GetEBAFctChan()->HEADBrakeFctChannel = tempFctChan;
    }
    else
    {
      /*brake is active without hyp - keep stored values*/
    }
  }
  else
  {
    /*reset function channel*/
    MEDIC_p_GetEBAFctChan()->HEADBrakeFctChannel = eEBAFctChan_Unknown;
  }
  HEADModuleOutputData.Veh_AutoBrk1.peFctChan = &MEDIC_p_GetEBAFctChan()->HEADBrakeFctChannel;

  /*set cam confirmation*/
  #if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
  if (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_RAMP)
  {
    /* During ramp-out phase latch last camera confirmation state present during active output states 
    In this state no hypothesis is attached to module anymore and thus no camera confirmation can be 
    derived. In order to prevent a hard degradation on the brake controller preserve last state during 
    ramp-out */
  }
  else if (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_PASSIVE)
  {
    MEDIC_p_GetHEADCustOutputLocVar()->HEADPreBrakeCamConfirm   = FALSE;
  }
  else
  {
    /* Update camera confirmation state */
    uint16 uiModBitF = 0;
    const Hypothesis_t* pKinHyp = NULL;
    HEADModule_t *pModuleVehAutoBrk1 = HEADGetModule(MEDIC_p_ModHEADInputData()->pModuleList, HEAD_AUTOCODE_MOD_Veh_AutoBrk1);

    MEDIC_p_GetHEADCustOutputLocVar()->HEADPreBrakeCamConfirm  = FALSE;
    /* Search for relevant hypothesis and derive camera confirmation from object probability */
    uiModBitF = HEADGetActiveHypothesisForModule(pModuleVehAutoBrk1);
    (void) HEADGetMostCritHypOfBitfieldForModule(MEDIC_p_ModHEADInputData(), uiModBitF, &pKinHyp, TRUE);
    if(pKinHyp != NULL)
    {
      if( (pKinHyp->uiObjectProbability > FPSEBACFCT_MAX_OBJ_QUAL_NO_CAM)
           || ( *(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_VEH_LEVEL_3)
           || ( *(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_VEH_LEVEL_2)
           || ((*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_VEH_LEVEL_1) && (pKinHyp->eType == CDHypothesisType_RunUpStationary))
        )
      {
        MEDIC_p_GetHEADCustOutputLocVar()->HEADPreBrakeCamConfirm  = TRUE;
      }
      else
      {
        MEDIC_p_GetHEADCustOutputLocVar()->HEADPreBrakeCamConfirm  = FALSE;
      }
    }
  }
  MEDIC_p_ModHeadOutCustom()->sPreBrake.bPreBrakeCamConfirmed = MEDIC_p_GetHEADCustOutputLocVar()->HEADPreBrakeCamConfirm ;
  #endif /* MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION */
}

/*************************************************************************************************************************
  Functionname          HEADOutArbitratePreWarning                                                                  */ /*! 
  
  @brief                custom output arbitration for pre warning
   
  @description          Following function is for setting the Fct channel for prewarning. 
                        If the pre warn module is active , pre brake is TRUE and if the pre warn module has valid 
                        hypothesis pre warn module Signal state and channel are set appropriately else they are set with Inactive and Unknown state.
  
                        @startuml
                        Start
                             :Fetch head hypothesis and head module information;

                             If(Is module information avaliable?) then (Yes)
                             If (check either module state or vehicle auto prebrake is active or not) then (Active)

                             If(Is dynamic pre warning Active Hypothesis existing?) then (Yes)
                             If(unclassified function channlel status) then (Switch ON)
                             If(is dynamic per warning hypothesis  available? ) then (yes)
                             :fetch pre warn hypothesis information;
                             Endif
                             Endif
                             :update EBA signal state;
                             Endif
                             :update pre warn function channel;
                             Else (inactive)
                             :reset function channel and signal;
                             Endif
                             Else (No)
                             :reset function channel and signal;
                             Endif
                             : update pre warn function channel and signal state
                             To coresponding EBA signal state and function channel;
                        Stop
                        @enduml
  
  @return               void

  @param[in]            None

  @glob_in              None
  @glob_out             @ref HEADPreWarnFctChannel 
  @glob_out             @ref HEADPreWarnSignal
   
  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 

  @author               Andreas Jakob | andreas.jakob-ext@conti-engineering.com
**************************************************************************************************************************/
static void HEADOutArbitratePreWarning(void)
{
  HEADModule_t* pModule = HEADGetModule(MEDIC_p_ModHEADInputData()->pModuleList, HEAD_AUTOCODE_MOD_DynPreWarn);
  eEBAFctChan_t tempFctChan = MEDIC_p_GetEBAFctChan()->HEADPreWarnFctChannel ;
  const HEADHypothesis_t* pDynPreWarnHyp = HEADGetHypothesis(MEDIC_p_ModHEADInputData()->rgHypothesisList, HEADModuleOutputData.DynPreWarn.ActHypNr);
  if ( pModule != NULL )
  {
    if( ( pModule->eSMState == HEADSMState_ACTIVE )
      ||( *(HEADModuleOutputData.Veh_AutoBrk1.pbPreBrakeActive) == TRUE)
      )
    {
      if( HEADModuleOutputData.DynPreWarn.ActHypNr != HEADNoHypothesis)
      {
        tempFctChan = HEADModuleOutputData.DynPreWarn.eEBAFctChannel;
        #if(HEAD_DO_NOT_SET_CHANNEL_UNCLASSIFIED == SWITCH_ON)
        if(pDynPreWarnHyp != NULL)
        {
          const Hypothesis_t* pHyp  = pDynPreWarnHyp->pHypothesis;
          tempFctChan = HEADCheckForUnclassfied(pHyp, MEDIC_p_GetEBAFctChan()->HEADPreWarnFctChannel );
        }
        #else
        _PARAM_UNUSED(pDynPreWarnHyp);
        #endif
        MEDIC_p_GetEBASignalState()->HEADPreWarnSignal     = HEADModuleOutputData.DynPreWarn.eEBASignalState;
      }
      MEDIC_p_GetEBAFctChan()->HEADPreWarnFctChannel       = tempFctChan;
    }
    else
    {
      MEDIC_p_GetEBAFctChan()->HEADPreWarnFctChannel       = eEBAFctChan_Unknown;
      MEDIC_p_GetEBASignalState()->HEADPreWarnSignal       = eEBAOn_Inactive;
    }
  }
  else
  {
    MEDIC_p_GetEBAFctChan()->HEADPreWarnFctChannel         = eEBAFctChan_Unknown;
    MEDIC_p_GetEBASignalState()->HEADPreWarnSignal         = eEBAOn_Inactive;
  }

  HEADModuleOutputData.DynPreWarn.eEBAFctChannel           = MEDIC_p_GetEBAFctChan()->HEADPreWarnFctChannel ;
  HEADModuleOutputData.DynPreWarn.eEBASignalState          = MEDIC_p_GetEBASignalState()->HEADPreWarnSignal;
}

/***********************************************************************************************************************
  Functionname          HEADOutArbitrateAcuteWarning                                                              */ /*! 
  
  @brief                custom output arbitration for actute warning
   
  @description          Arbitrate (interpose) the Acute warning module if vehicle auto brake1 pre brake is active.
                        If Pre Brake Active is TRUE then only we arbitrate the Acute warn channel.
                     
                        If HEAD_USE_CHANGE_FUNCTIONCHANNEL is Switch on and if Vehicle Auto brk1 
                        hypothesis is active brake values are directed to acute warning out channel.
                        Else warn hypothesis channel is set to No hypothesis.
                    
                        If HEAD_USE_CHANGE_FUNCTIONCHANNEL is Switch off and if Acute warn hypothesis is active
                        Warning values are only directed to acute warning channel. Else warn hypothesis channel is set to No hypothesis.
  
                        @startuml
                        Start                
                             If (check Vehicle Auto Break Hypothesis status) then (True)
                             If(check function channel status during activation) then (True)
                             :fetch hypothesis information;
                             If(Is Active break Hypothesis existing?) then (Yes)
                             :set brake values to warning output;
                             Else
                             :reset hypothesis but break is active;
                             Endif
                             Endif
                             If(Is Dynamic Acute Warning active Hypothesis existing?) then (No)
                             : update values from warn function;
                             Else (Yes)
                             :reset hypothesis but break is active;
                             Endif
                             :store values to warn function;
                             Else (False)
                             :reset stored values;
                             Endif
                        Stop
                        @enduml
  
  @return               void

  @param[in]            None 

  @glob_in              None
  @glob_out             @ref HEADAcuteWarnFctChannel
  @glob_out             @ref HEADAcuteWarnSignal
  @glob_out             @ref HEADAcuteWarnActiveHyp

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 

  @author               Andreas Jakob | andreas.jakob-ext@conti-engineering.com
*************************************************************************************************************************/
static void HEADOutArbitrateAcuteWarning(void)
{
  if( *(HEADModuleOutputData.Veh_AutoBrk1.pbPreBrakeActive) == TRUE)
  {
    #if (HEAD_USE_CHANGE_FUNCTIONCHANNEL == SWITCH_ON)
    const HEADHypothesis_t* pVehAutoBrk1Hyp = HEADGetHypothesis(MEDIC_p_ModHEADInputData()->rgHypothesisList, *(HEADModuleOutputData.Veh_AutoBrk1.pActHypNr));
    if(pVehAutoBrk1Hyp != NULL)
    {
      const Hypothesis_t* pHyp  = pVehAutoBrk1Hyp->pHypothesis;
      /* set brake values to warning output*/
      MEDIC_p_GetEBAFctChan()->HEADAcuteWarnFctChannel           = HEADGetFctChannel(pHyp);
      MEDIC_p_GetEBASignalState()->HEADAcuteWarnSignal           = HEADGetEBASignalState(pHyp);
      MEDIC_p_GetHEADCustOutputLocVar()->HEADAcuteWarnActiveHyp  = *(HEADModuleOutputData.Veh_AutoBrk1.pActHypNr);
    }
    else
    {
      /*brake is active without hyp - keep stored values - reset hyp*/
      MEDIC_p_GetHEADCustOutputLocVar()->HEADAcuteWarnActiveHyp  = HEADNoHypothesis;
    }
    #else
    if( *(HEADModuleOutputData.DynAcuteWarn.puActiveHyp) != HEADNoHypothesis)
    {
      /*brake and warnfunction are active - store values from warnfunction*/
      MEDIC_p_GetEBAFctChan()->HEADAcuteWarnFctChannel           = *(HEADModuleOutputData.DynAcuteWarn.peFctChan);
      MEDIC_p_GetEBASignalState()->HEADAcuteWarnSignal           = *(HEADModuleOutputData.DynAcuteWarn.peSignal);
      MEDIC_p_GetHEADCustOutputLocVar()->HEADAcuteWarnActiveHyp  = *(HEADModuleOutputData.DynAcuteWarn.puActiveHyp);
    }
    else
    {
      MEDIC_p_GetHEADCustOutputLocVar()->HEADAcuteWarnActiveHyp = HEADNoHypothesis;
    }
    #endif

    *(HEADModuleOutputData.DynAcuteWarn.peFctChan)             = MEDIC_p_GetEBAFctChan()->HEADAcuteWarnFctChannel;
    *(HEADModuleOutputData.DynAcuteWarn.peSignal)              = MEDIC_p_GetEBASignalState()->HEADAcuteWarnSignal;
    *(HEADModuleOutputData.DynAcuteWarn.puActiveHyp)           = MEDIC_p_GetHEADCustOutputLocVar()->HEADAcuteWarnActiveHyp;
  }
  else
  {
    /*no Brake activation - reset stored values*/
    MEDIC_p_GetEBAFctChan()->HEADAcuteWarnFctChannel           = eEBAFctChan_Unknown;
    MEDIC_p_GetEBASignalState()->HEADAcuteWarnSignal           = eEBAOn_Inactive;
    MEDIC_p_GetHEADCustOutputLocVar()->HEADAcuteWarnActiveHyp  = HEADNoHypothesis;
  }
}

/************************************************************************************************************************
  Functionname          HEADSetEmergency                                                                          */ /*! 
  
  @brief                HEADSetEmergency
  
  @description          Third level vehicle pre break request signal is activated. 
                        Its Depends on the criticality.
                     
                        @startuml
                        Start
                            If(check for pre brake vehicle active level is equal to third level ) then (Yes)
                            :Set emergency bit;
                            Else 
                            :return the updated signal;
                            Endif
                        Stop
                        @enduml

  @return               static boolean
  
  @param[in]            None 

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability   
 
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
**************************************************************************** */
static boolean HEADSetEmergency(void)
{
  boolean EmergencyBit = FALSE;
  /* SET EMERGENCY BIT */
  if(*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_VEH_LEVEL_3)
  {
    EmergencyBit = TRUE;
  }
  else
  {
    EmergencyBit = FALSE;
  }
  return EmergencyBit;
}
/************************************************************************************************************************
  Functionname          HEADGetHaptSensState                                                                       */ /*! 

  @brief                HEADGetHaptSensState

  @description          HEAD Set sensitivity state for dynamic haptic warn 

                       @startuml
                       start
                            :Fetch head module information;
                            If (check if module state is active or channel is known?) then (True)
                            :fetch hypothesis information;
                            If(Hypothesis existing?) then (Yes)
                            :set required deceleration to hypothesis negative acceleration;
                            Endif
                            If( required deceleration is less than lowest threshold to 
                            enable haptic warning sensitivity state to high?) then (Yes)
                            : update sensor state to high;
                            Else If( required deceleration is less than lowest threshold to
                            enable haptic warning sensitivity state to mid?) then (Yes)
                            : update sensor state to mid;
                            Else If( required deceleration is less than lowest threshold to  
                            enable haptic warning sensitivity state to low?) then (Yes)
                            : update sensor state to low;
                            Endif
                            :return updated sensor state;
                            Endif
                       Stop
                       @enduml


  @return        static eEBAWarnSens_t                

  @param[in]            None 

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability   
 
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
**************************************************************************** */

static eWarnSens_t HEADGetHaptSensState(void)
{
  eWarnSens_t actSensState = eEBAHaptSensNone;
  HEADModule_t* pModule = HEADGetModule(MEDIC_p_ModHEADInputData()->pModuleList, HEAD_AUTOCODE_MOD_HaptDynWarn);
  if( ( pModule->eSMState == HEADSMState_ACTIVE )
    ||( HEADModuleOutputData.HaptDynWarn.eEBAFctChannel != eEBAFctChan_Unknown)
    )
  {
    const Hypothesis_t* pKinHyp = NULL;
    float32 actANecLong = 0.f;
    uint16 uiModBitF = 0;
    uiModBitF = HEADGetActiveHypothesisForModule(pModule);
    (void) HEADGetMostCritHypOfBitfieldForModule(MEDIC_p_ModHEADInputData(), uiModBitF, &pKinHyp, TRUE);
    if(pKinHyp != NULL)
    {
      actANecLong = pKinHyp->fLongNecAccel;
    }
    if (actANecLong < HEAD_PAR_HAPTACUWARN_SENS_HIGH_THRS)
    {
      actSensState = eEBAHaptSensHigh;
    }
    else if (actANecLong < HEAD_PAR_HAPTACUWARN_SENS_MID_THRS)
    {
      actSensState = eEBAHaptSensMid;
    }
    else
    {
      actSensState = eEBAHaptSensLow;
    }
  }
  return actSensState;
}
#if(HEAD_DO_NOT_SET_CHANNEL_UNCLASSIFIED == SWITCH_ON)
/************************************************************************************************************************
  Functionname          HEADCheckForUnclassfied                                                                   */ /*! 
  
  @brief                HEADCheckForUnclassfied
  
  @description          FCT Channel object would be updated. If FCT channel is unclassified     
                        object then update the Previous FCT channel object.

                        @startuml
                        Start
                             :Set Function Channel;
                             :Return the Function channel;
                             Note right
                             Change FCT Channel to previous FCT channel in case of an unclassified object
                             End note
                        Stop
                        @enduml

  @return               eEBAFctChan_t 
  
  @param[in]            pHyp                : Pointer to hypothesis  
  @param[in]            eEBAFctChan_current : Current function channel

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
**************************************************************************************************************************/
static eEBAFctChan_t HEADCheckForUnclassfied(const Hypothesis_t* pHyp, eEBAFctChan_t eEBAFctChan_current)
{
  eEBAFctChan_t tempFctChan = eEBAFctChan_Unknown; 
  /* Set Function Channel */
  if(pHyp != NULL)
  {
    tempFctChan = HEADGetFctChannel(pHyp);
    if (tempFctChan == eEBAFctChan_Unclassified)
    {
      /*change FCT Channel to previous channel case of an unclassified object*/
      tempFctChan = eEBAFctChan_current;
    }
    else
    {
      /*do nothing*/
    }
  }

  return tempFctChan;
}

#endif

/***********************************************************************************************************************
  Functionname          HEADSetReachedBrkLevel                                                                   */ /*! 
  
  @brief                HEADSetReachedBrkLevel
  
  @description          Maximum reached brake level is updated  by reading the status of veh-autobrk1 status. 
                        If Veh_AutoBrk1.pePreBrakeState has valid value and its state is greater than PASSIVE state.
                        Maximum reached brake level is updated by readiing every prebrake state.    
                     
                        @startuml
                        Start
                            if(check for Pre Brake State availability)then (Available) 
                            if(Is pre brake state passive?) then (No)
                            : Update maximum reached Brake Level;
                            Note right
                            vehicle, pedestrian and vulnerable road user
                             any one of these level will be updated
                            End note
                            elseif (Is pre brake state cross brake?) then (Yes)
                            Partition #LightBlue **((HEAD_USE_CROSSING_BRK))** {
                            : Update maximum reached Brake Level;
                            }
                            Else 
                            : Reset break level;
                            endif
                            Else (No information)
                            : keep previous break Level;
                            Endif
                        Stop
                        @enduml    
                     
  @param[in]            None
  
  @return               None
  
  @glob_in              None
  @glob_out             @ref HEADMaxBrkLevel

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
**************************************************************************************************************************/
static void HEADSetReachedBrkLevel (void)
{
  if((HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) != NULL)
  {
   
    /*set max reached Brake Level*/
    if (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) > eBrakeState_PASSIVE)
    {
      if (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_VEH_LEVEL_3)
      {
        MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel = HEAD_BRK_LVL_VEH3;
      }
      else if ( (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_VEH_LEVEL_2) 
              &&(  MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel < HEAD_BRK_LVL_VEH3)
              )
      {
        MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel = HEAD_BRK_LVL_VEH2;
      }
      else if ( (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_VEH_LEVEL_1 )
              &&(  MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel < HEAD_BRK_LVL_VEH2)
              )
      {
        MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel = HEAD_BRK_LVL_VEH1;
      }
      else if (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_PED_LEVEL_2 )
      {
        MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel = HEAD_BRK_LVL_PED2;
      }
      else if ( (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_PED_LEVEL_1 )
              &&(  MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel < HEAD_BRK_LVL_PED2)
              )
      {
        MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel = HEAD_BRK_LVL_PED1;
      }
      else if (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_LongVru_LEVEL_2 )
      {
        MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel = HEAD_BRK_LVL_LONGVRU2;
      }
      else if ( (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_LongVru_LEVEL_1 )
        &&(  MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel < HEAD_BRK_LVL_LONGVRU2)
        )
      {
        MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel = HEAD_BRK_LVL_LONGVRU1;
      }
      #if defined (HEAD_USE_CROSSING_BRK) && (HEAD_USE_CROSSING_BRK == SWITCH_ON)
      else if (*(HEADModuleOutputData.Veh_AutoBrk1.pePreBrakeState) == eBrakeState_CROSSBRK )
      {
        MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel = HEAD_BRK_LVL_CROSS;
      }
      #endif
      else
      {
        /*shouldn't happen*/
      }
    }
    else
    {
      /* If no brake request is active, reset brk level */
      MEDIC_p_GetHEADCustOutputLocVar()->HEADMaxBrkLevel = HEAD_BRK_PASSIVE;
    }
  }
  else
  {
    /* keep previous Level */
  }
}

#endif
#endif  /* !(MEDIC_CFG_HEAD20) */

/**@}*/ 

/* PRQA S 7013 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability*/
