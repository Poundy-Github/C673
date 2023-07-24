/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_wrapper.h

DESCRIPTION:               header of the head wrapper

AUTHOR:                    $Author: uia92763 $

CREATION DATE:             $Date: 2020/05/29 11:28:23CEST $

VERSION:                   $Revision: 1.1.11.4 $

LEGACY VERSION:            1.58

**************************************************************************** */
/**
@ingroup head_wrapper
@{ **/

#ifndef _HEAD_WRAPPER_H_INCLUDED
#define _HEAD_WRAPPER_H_INCLUDED

/** @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/** @endcond */

/*** START OF SINGLE INCLUDE SECTION ****************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! @brief parameter ids for parameters that should be adaptable by country code 
    @typical 0xffff0003u */
#define HEAD_PARID_LATPRE_DIST_VELO        (0xffff0003u)

/*! @brief parameter ids for parameters that should be adaptable by country code 
    @typical 0xffff0004u */
#define HEAD_PARID_LATACUTE_DIST_VELO      (0xffff0004u)

/*! @brief  Parameter used to update safety distance derived from alignment, velocity etc. uncertainties 
    @typical 0xffff0010u */
#define HEAD_PARID_PREBRK_SAFETY_DIST      (0xffff0010u)

/*! @brief  Calibratable parameters dependent on encoded pre-brake function 
    @typical 0xffff0021u */
#define HEAD_PARID_DYNPRE_TTBPRE_EARLY_STAT (0xffff0021u)

/*! @brief  Calibratable parameters dependent on encoded pre-brake function 
    @typical 0xffff0022u */
#define HEAD_PARID_DYNPRE_TTBPRE_LATE_STAT  (0xffff0022u)

/*! @brief  Calibratable parameters dependent on encoded pre-brake function 
    @typical 0xffff0023u */
#define HEAD_PARID_DYNPRE_TTSPRE_EARLY      (0xffff0023u)

/*! @brief  Calibratable parameters dependent on encoded pre-brake function 
    @typical 0xffff0024u */
#define HEAD_PARID_DYNPRE_TTSPRE_LATE       (0xffff0024u)

/*! @brief  Calibratable parameters dependent on encoded pre-brake function
    @typical 0xffff0025u */
#define HEAD_PARID_DYNACUTE_TTBACUTE_STAT   (0xffff0025u)

/*! @brief  Calibratable parameters dependent on encoded pre-brake function 
    @typical 0xffff0026u */
#define HEAD_PARID_DYNACUTE_TTSACUTE        (0xffff0026u)

/*! @brief  Custom input parameter yaw rate used in HEAD configuration */
#define HEAD_CUST_ABS_YAWRATE               HEADParamOutType_CustomPar_00_HypIndependent
/*! @brief  Custom parameter: still stand external deactivation condition*/
#define HEAD_CUST_PAR_STILLSTAND_EXT_DEACT  HEADParamOutType_CustomPar_01_HypIndependent
/*! @brief  Custom parameter: break pressure condition*/
#define HEAD_CUST_PAR_AEB_Switch  HEADParamOutType_CustomPar_02_HypIndependent
/*! @brief  Custom parameter: DriverDoor and seatbelt condition*/
#define HEAD_CUST_PAR_Driver_Seatbelt  HEADParamOutType_CustomPar_03_HypIndependent
/*! @brief  Custom parameter: Brake chain state condition*/
#define HEAD_CUST_PAR_BrakeChainState  HEADParamOutType_CustomPar_04_HypIndependent
/*! @brief  Custom parameter: Warn chain state condition*/
#define HEAD_CUST_PAR_WarnChainState  HEADParamOutType_CustomPar_05_HypIndependent
/*! @brief  Custom parameter: Prefill qualifier condition*/
#define HEAD_CUST_PAR_Prefill_Qualifier  HEADParamOutType_CustomPar_06_HypIndependent
/*! @brief  Custom parameter: HBA qualifier condition*/
#define HEAD_CUST_PAR_HBA_Qualifier  HEADParamOutType_CustomPar_07_HypIndependent

#define HEAD_CUST_PAR_Diver_Braking  HEADParamOutType_CustomPar_08_HypIndependent // ego seepd blow 10kph && driver braking && ego accel blow -1m/s^2

#define HEAD_CUST_PAR_Diver_Braking_Delay  HEADParamOutType_CustomPar_09_HypIndependent
/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*These two variables are used to store the ego velocity when a braking module turns active
  or if the braking cascade starts (exact implementation when to write the ego velocity can be
  customized in HEADCustomOutput).
  The output function "head_out_ped_prebrake_function" uses HostSpeedLastPedBrakeStart, while 
  HostSpeedLastBrakeStart is used in "head_out_prebrake_function" and "head_out_fullbrake_function".
  Thereby the speed reduction can be calculated and if it exceeds the maximum allowed value,
  the output function forces the respective module to go to wait.*/
/*!  @cond Doxygen_Suppress */
extern fVelocity_t HostSpeedLastBrakeStart;
extern fVelocity_t HostSpeedLastPedBrakeStart;

/* Active time of Standstill function */
extern float32 fStandstillActiveTime;
extern float32 fSteeringWheelBrakeStart;
extern float32 fGasPedalPosBrakeStart;
extern boolean bBrakeStatValuesValid;
extern boolean bHEADDeactivationStandStill;
/*! @endcond */
/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
#if defined(HEAD_USE_DEBUG_INTERFACE)
extern const HEADModuleList_t *HEADDbgGetModuleList(void);
extern const struct HEADInputData_t *HEADDbgGetInputData(void);
#endif
extern eGDBError_t CalibrationFunction(HEADParameterEmpty_t *pParameter, uint32 uiParID);
extern eGDBError_t CalibSensorFusion(HEADParameterEmpty_t * pParameter, uint32 uiParID);
extern eGDBError_t HEADMTSSendExtraInputSignals(const void *pExtraValueList, HEADMTSInputSignalList_t *pMTSInputSignalList, uint8 uiStartNr);
extern void HEADUseReInit(void);

/* Deactivate QA-C warning 3406; Reviewer: Veerashettappa.Nagaraja; Date: 06.07.2018; 
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406 ALGO_INLINES */
ALGO_INLINE eEBASignalState_t HEADGetEBASignalState(const Hypothesis_t* pHyp);
ALGO_INLINE eEBAFctChan_t HEADGetFctChannel(const Hypothesis_t* pHyp);

/* This Function is only here for compatibility with old HEAD implementation. Use Get-function in HEAD.h instead */
#if (defined(_MSC_VER))
#endif


/*****************************************************************************
  INLINE FUNCTION
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:    HEADGetEBASignalState                                                                              */ /*!

  @brief           HEAD Get EBA Signal State

  @description     Returns EBA Signal State "only Mapping".

  @return          ALGO_INLINE eEBASignalState_t

  @param[in]       pHyp : Pointer to current Hypothesis

  @pre             [None]
  @post            [None]
*************************************************************************************************************************/
ALGO_INLINE eEBASignalState_t HEADGetEBASignalState(const Hypothesis_t* pHyp)
{
  eEBASignalState_t eSignal;
  /* Set Dynamics */
  if(pHyp != NULL)
  {
    switch (pHyp->eEBADynProp)
    {
    case (eEBADynProp_t)EBADynProp_Stat:
      eSignal = eEBAOn_Standing;
      if ((pHyp->eType == CDHypothesisType_RunUp) || (pHyp->eType == CDHypothesisType_RunUpBraking))
      {
        eSignal = eEBAOn_Halted;
      }
      break;
    case (eEBADynProp_t)EBADynProp_Mov:
      eSignal = eEBAOn_Moving;
      if (pHyp->eType == CDHypothesisType_Crossing)
      {
        if (pHyp->fVrelY > 0)
        {
         eSignal = eEBAOn_CrossFrRight;
        }
        else
        {
          eSignal = eEBAOn_CrossFrLeft;
        }
      }
      break;
    case (eEBADynProp_t)EBADynProp_NotAvail:
    default:
      eSignal = eEBAOn_Inactive;
      break;
    }
  }
  else
  {
    eSignal = eEBAOn_Inactive;
  }
  return eSignal;
}
/*************************************************************************************************************************
  Functionname:    HEADGetFctChannel                                                                              */ /*!

  @brief           HEAD Get FCT Channel

  @description     Returns EBA FCT Channel "only Mapping".

  @return          ALGO_INLINE eEBAFctChan_t

  @param[in]       pHyp : Pointer to current Hypothesis

  @pre             [None]
  @post            [None]
*************************************************************************************************************************/
ALGO_INLINE eEBAFctChan_t HEADGetFctChannel(const Hypothesis_t* pHyp)
{
  eEBAFctChan_t eFctChan;
  /* Set Function Channel */
  if(pHyp != NULL)
  {
    switch (pHyp->eEBAObjectClass)
    {
    case (eEBAObjectClass_t)EBAObjectClass_Pedestrian:
        eFctChan = eEBAFctChan_Pedestrian;
        break;
    case (eEBAObjectClass_t)EBAObjectClass_Cyclist:
        eFctChan = eEBAFctChan_Cyclist;
        break;
    case (eEBAObjectClass_t)EBAObjectClass_Vehicle:
        eFctChan = eEBAFctChan_Vehicle;
        if (pHyp->eType == CDHypothesisType_Crossing)
        {
          eFctChan = eEBAFctChan_Crossing;
        }
        #if HEAD_CFG_TURN_ASSIST
        else if (pHyp->eType == CDHypothesisType_DriveIntoOncoming)
        {
          eFctChan = eEBAFctChan_DrvIntoOncoming;
        }
        #endif // HEAD_CFG_TURN_ASSIST
        break;
    case (eEBAObjectClass_t)EBAObjectClass_Obstacle:
        eFctChan = eEBAFctChan_Unclassified;
        if (pHyp->eType == CDHypothesisType_Crossing)
        {
          eFctChan = eEBAFctChan_Crossing;
        }
        break;
    case (eEBAObjectClass_t)EBAObjectClass_NotAvail:
    default:
        eFctChan = eEBAFctChan_Unknown;
        break;
    }
  }
  else
  {
    eFctChan = eEBAFctChan_Unknown;
  }
  return eFctChan;
}

/*** END OF SINLGE INCLUDE SECTION ******************************************/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
/* PRQA L:ALGO_INLINES */
#endif /* _HEAD_WRAPPER_H_INCLUDED */
/**@}*/ 
