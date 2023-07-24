/*! \file **********************************************************************

// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.22 $

---*/ /*---
CHANGES:                   $Log: spm_interference.c  $
CHANGES:                   Revision 1.22 2021/02/01 16:20:18CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC boolean issue
CHANGES:                   Revision 1.21 2020/10/23 15:41:50CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Adaptation for situation when SLATE and ACC are both turned OFF simultaniously
CHANGES:                   Revision 1.20 2020/10/21 07:07:26CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Delete pragma from comment
CHANGES:                   Revision 1.19 2020/10/20 16:00:54CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Remove compiler warning
CHANGES:                   Revision 1.18 2020/06/30 16:28:46CEST Pallo, Istvan (palloi) 
CHANGES:                   Revert SRR SPM split changes on trunk
CHANGES:                   Revision 1.17 2020/06/26 09:49:18CEST Pallo, Istvan (palloi) 
CHANGES:                   Fix compile errors on devgate
CHANGES:                   Revision 1.16 2020/06/25 07:04:03CEST Pallo, Istvan (palloi) 
CHANGES:                   Update interference according to SPM split changes - SRR
CHANGES:                   Revision 1.15 2020/06/10 13:15:45CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Reverse changes based in 1.13 revision
CHANGES:                   Revision 1.14 2020/05/11 11:54:06CEST Motocu, Alexandru Marian02 (MotocuA02) 
CHANGES:                   USE ONLY FOR SRR520GM20 Project
CHANGES:                   L3 QAC Warning: fix indentation
CHANGES:                   Revision 1.12 2019/09/16 15:57:38CEST Motocu, Alexandru Marian02 (MotocuA02) 
CHANGES:                   Added Interference Detection Logic for SRR
CHANGES:                   Revision 1.11 2019/05/29 10:46:19CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Add suppress message
CHANGES:                   Revision 1.10 2019/05/28 06:52:13CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAF warnings
CHANGES:                   Revision 1.9 2018/09/24 15:09:54CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for SRR
CHANGES:                   Revision 1.8 2017/11/22 08:55:09CET Pallo, Istvan (palloi) 
CHANGES:                   Add extra brackets
CHANGES:                   Revision 1.7 2017/11/22 08:05:48CET Pallo, Istvan (palloi) 
CHANGES:                   Replace uint8 with ObjNumber_t for relevant object index.
CHANGES:                   Use defines instead magic numbers when checking for index range
CHANGES:                   Revision 1.6 2017/11/08 15:38:27CET Pallo, Istvan (palloi) 
CHANGES:                   Add guard for access violation
CHANGES:                   Revision 1.5 2017/11/07 09:51:12CET Pallo, Istvan (palloi) 
CHANGES:                   Check for null pointer in interference loss reason
CHANGES:                   Revision 1.4 2017/07/31 14:43:08CEST Pallo, Istvan (palloi) 
CHANGES:                   Conversion to sint32 to solve QA-C
CHANGES:                   Revision 1.3 2017/07/28 06:59:19CEST Pallo, Istvan (palloi) 
CHANGES:                   Add functionality from AL_FCT_ARS400_02.86.00. Code refactoring & QAC cleaning.
CHANGES:                   Revision 1.2 2017/06/21 09:09:10CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove function header.
CHANGES:                   Revision 1.1 2017/03/17 13:17:02CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/interference/project.pj

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_par.h" /* PRQA S 0380 */ /* 2019-05-29, reviewer:Opreai01, Popam05 reason: multiple header files inherited according to include strategy */
#include "spm.h"
#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
  #if (FCT_CFG_SIGNAL_PERF_MONITORING)
  /*****************************************************************************
    MACROS
  *****************************************************************************/
  #if(EM_PERF_DEGR_INTFVER >= EM_PERF_INTERFERENCE_INT_VER_THLD)      /* Check RTE version */
    #define RSP_GET_DATA_RANGE    SPM_GET_PERF_DEG_DATA_PTR->fNoiseRange
  #else
    /*! Temporary work-around for missing range estimation from RSP in ARS400.
    Needs to be clarified where this information for interference range shall come
    from! */
    #define RSP_GET_DATA_RANGE    (200.f)
  #endif
  
  /*****************************************************************************
    TYPEDEFS
  *****************************************************************************/
  
  /*****************************************************************************
    (SYMBOLIC) CONSTANTS
  *****************************************************************************/
  /* Interference bitmask */
  #define CYCLES_MASK_15 (0x7FFFu)
  
  /* mapping parameters */
  #define SPM_INTERF_EVENTCOUNT_WITH_OBJECTLOSS   (3U)
  #define SPM_INTERF_EVENTCOUNT                   (7U)
  #define SPM_INTERF_LAST_DIST_MULTIPLY_FACTOR    (2.0F)
  #define SPM_INTERF_HOLD_COUNTER_THLD            (0U)
  #define SPM_INTERF_BITE_FACTOR               (1U)
  
  /*****************************************************************************
    TYPEDEFS
  *****************************************************************************/
  
  /*****************************************************************************
    MODULEGLOBAL VARIABLES
  *****************************************************************************/
  
  /*****************************************************************************
    MODULELOKAL VARIABLES
  *****************************************************************************/
  
  /*****************************************************************************
    FUNCTION PROTOTYPES
  *****************************************************************************/
  
  /*****************************************************************************
    FUNCTION
  *****************************************************************************/
  void SPMInterferenceRange (void)
  {
    /*--- (SYMBOLIC) CONSTANTS ---*/
    /*--- VARIABLES ---*/
  
    float32 RangeThld;
    float32 f_XDistOOI0;
#if((FCT_CFG_SLATE_COMPONENT == SWITCH_ON) && (FCT_CFG_OBJECT_LIST_PROC) && (FCT_CFG_ASSESSED_OBJ_OUT_INTF))
    ObjNumber_t uRelObjIdx;
#endif
    //const SIRelObject_t * pRelObject;      /* Relevante Objekte aus Tracking-Komponente */
    eRelObjLossReason_t LossReason;
    sint32 BitCnt15 = 0;
  
    f_XDistOOI0 = 0.0F;
#if((FCT_CFG_SLATE_COMPONENT == SWITCH_ON) && (FCT_CFG_OBJECT_LIST_PROC == SWITCH_ON) && (FCT_CFG_ASSESSED_OBJ_OUT_INTF == SWITCH_ON))
    uRelObjIdx = (ObjNumber_t)SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI);
    if((uRelObjIdx > OBJ_INDEX_NO_OBJECT) && (uRelObjIdx < EM_N_OBJECTS))
    {
      f_XDistOOI0 = SPM_OBJ_LONG_DISPLACEMENT(uRelObjIdx);
    }
#endif
    
    SPMData.SPMInterferenceRange = RSP_GET_DATA_RANGE;
  
    /* Objekte von Objekterkennung holen */  
    //pRelObject = SIReSiDaGetRelevantObject();
    LossReason = OBJ_LOSS_NO_INFO;
#if(FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
    if(FCTSEN_pSLATE_SPM_Data != NULL)
    {
      LossReason = FCTSEN_pSLATE_SPM_Data->t_ObjLossReasonACCRelObj;//SIObOOIGetOOILossReason(OBJ_NEXT_OOI);
    }
#endif  
  
    /* range threshold = vehicle speed * 3.6sec */
    RangeThld = fEgoSpeed * SPM_INTERFERENC_RANGE_TIME_DIST;
  
    /* range thld is maximum the distance of the relevant object,  */
    if(CML_f_IsNonZero(f_XDistOOI0))//(pRelObject->DistX > 0.F)
    {
      //RangeThld = CML_f_Min(RangeThld, pRelObject->DistX);
      RangeThld = CML_f_Min(RangeThld, f_XDistOOI0);
    }
  
    /* limit the threshold from 15 to 140 meter  */
    RangeThld = CML_f_MinMax(SPM_INTERFERENCE_RANGE_DIST_MIN, SPM_INTERFERENCE_RANGE_DIST_MAX, RangeThld);
  
    #if 1
      // Verify that using SW cycle detection instead of target list validity check is OK
      /* date: 2015-05-18, reviewer: Lonard jaison Manohar, reason: Non QAC related but required.*/
      if (SPM_GDB_CYCLE_MODE == EM_FCT_CYCLE_DEFAULT)
    #else
      if(
          (RSP_IS_TGT_LIST_FAR_VALID == TRUE)
        ||(RSP_IS_TGT_LIST_NEAR_VALID == TRUE)
        )
    #endif
      {
        /* Interference-Feld einen Zyklus altern */
        SPMData.SPMInterference <<= 1;
  
        /* Interference-Feld */
        if(
            (SPMData.SPMInterferenceRange < RangeThld) 
         #if(EM_PERF_DEGR_INTFVER >= EM_PERF_INTERFERENCE_INT_VER_THLD)/* Check RTE version */
          &&(SPM_GET_PERF_DEG_DATA_PTR->bNoiseRangeValid == b_TRUE)
         #endif
          )
        {
          SPMData.SPMInterference |= SPM_INTERF_BITE_FACTOR;
        }
        else{/* keine Interference wurde detektiert */}
  
        /* counting interference cycles of the last 15 cycles */
        #if (FCT_CFG_USE_ALGO_MATH)
          BitCnt15 = iGDBmathBitEinsAnzahl_32(SPMData.SPMInterference & CYCLES_MASK_15);
        #elif (FCT_CFG_USE_CML)
          BitCnt15 = CML_s_CountNrOfBitsSet(SPMData.SPMInterference & CYCLES_MASK_15);
        #else
          #error Do not know which math library to use!
        #endif
  
        if(
            (BitCnt15 >= (sint32)SPM_INTERF_EVENTCOUNT)
        ||(
            (LossReason == OBJ_LOSS_DISAPPEARED)
          &&((SPMData.SPMInterferenceRange < (SPM_INTERF_LAST_DIST_MULTIPLY_FACTOR * fLastRelevantObjectDistance)) 
        #if(EM_PERF_DEGR_INTFVER >= EM_PERF_INTERFERENCE_INT_VER_THLD)/* Check RTE version */
          &&(SPM_GET_PERF_DEG_DATA_PTR->bNoiseRangeValid == b_TRUE)
  #endif
        )
        &&(BitCnt15 >= (sint32)SPM_INTERF_EVENTCOUNT_WITH_OBJECTLOSS)   /*!< Additional check to make sure that 'base' range requirement not met for at least 3 cycles in last 15 cycles */
        )
        )
        {
          /* set interference event */
          SPMSetErrorState( SPM_ERREV_INTERFERENCE_RANGE, AL_ERR_STATE_ACTIVE);
          SPMData.SPMInterferenceHoldCnt = SPM_INTERFERENCE_RANGE_HOLD;
          SPMData.SPMInterferenceState = b_TRUE;
        }
        else if(SPMData.SPMInterferenceHoldCnt > SPM_INTERF_HOLD_COUNTER_THLD)
        {
          /* hold interference event */
          SPMSetErrorState( SPM_ERREV_INTERFERENCE_RANGE, AL_ERR_STATE_ACTIVE);
          SPMData.SPMInterferenceHoldCnt--;
          SPMData.SPMInterferenceState = b_TRUE;
        }
        else
        {
          /* no interference */
          SPMSetErrorState( SPM_ERREV_INTERFERENCE_RANGE, AL_ERR_STATE_INACTIVE);
          SPMData.SPMInterferenceState = b_FALSE;
        }
      }
  
    fLastRelevantObjectDistance = f_XDistOOI0;//pRelObject->DistX;
    /*--- UNDEF SYMBOLIC CONSTANTS ---*/
  }
  #endif
#endif

#if(SPM_SRR_TECHNOLOGY == SWITCH_ON)
    /*****************************************************************************
    MACROS
  *****************************************************************************/
  #if((EM_PERF_DEGR_INTFVER >= EM_PERF_INTERFERENCE_INT_VER_THLD) && (FCT_SEN_ERROR_OUT_INTFVER >= 20U))      /* Check RTE version */
  //#define RSP_GET_DATA_RANGE    SPM_GET_PERF_DEG_DATA_PTR->fNoiseRange 
  //#else
  //  /*! Temporary work-around for missing range estimation from RSP in ARS400.
  //  Needs to be clarified where this information for interference range shall come
  //  from! */
  //  #define RSP_GET_DATA_RANGE    (200.f)
  //#endif
  
  /*****************************************************************************
    TYPEDEFS
  *****************************************************************************/
  
  /*****************************************************************************
    (SYMBOLIC) CONSTANTS
  *****************************************************************************/
  /* Interference bitmask */
  #define CYCLES_MASK_15 (0x7FFFu)
  
  /* mapping parameters */
  #define SPM_INTERF_EVENTCOUNT                   (7U)
  #define SPM_INTERF_HOLD_COUNTER_THLD            (0U)
  #define SPM_INTERF_BITE_FACTOR               (1U)
  
  /*****************************************************************************
    TYPEDEFS
  *****************************************************************************/
  
  /*****************************************************************************
    MODULEGLOBAL VARIABLES
  *****************************************************************************/

  /*****************************************************************************
    MODULELOKAL VARIABLES
  *****************************************************************************/
  
  /*****************************************************************************
    FUNCTION PROTOTYPES
  *****************************************************************************/
  
  /*****************************************************************************
    FUNCTION
  *****************************************************************************/
  
  void SPMInterferenceRange(float32 fNoiseRange, boolean bNoiseRangeValid, FCTSenErrorOut_t *puiBlockageEvent)
  {
    /*--- (SYMBOLIC) CONSTANTS ---*/
    /*--- VARIABLES ---*/
  
    float32 RangeThld;
    sint32 BitCnt15 = 0;
    
    SPMData.SPMInterferenceRange = fNoiseRange;
   
    /* range threshold = vehicle speed * 3.6sec */
    RangeThld = FCT_f_GetEgoSpeedX() * SPM_INTERFERENC_RANGE_TIME_DIST;
  
    /* limit the threshold from 15 to 60 meter  */
    RangeThld = CML_f_MinMax(SPM_INTERFERENCE_RANGE_DIST_MIN, SPM_INTERFERENCE_RANGE_DIST_MAX, RangeThld);
    SPMData.InterferenceRangeThld = RangeThld;

    if (StateSPM == SPM_OK)
      {
        /* Interference-Feld einen Zyklus altern */
        SPMData.SPMInterference <<= 1;
  
        /* Interference-Feld */
        if(
            (SPMData.SPMInterferenceRange < RangeThld) 
          &&(bNoiseRangeValid == TRUE)
          )
        {
          SPMData.SPMInterference |= SPM_INTERF_BITE_FACTOR;
        }
        else{/* keine Interference wurde detektiert */}
  
          BitCnt15 = CML_s_CountNrOfBitsSet(SPMData.SPMInterference & CYCLES_MASK_15);
  
        if(BitCnt15 >= (sint32)SPM_INTERF_EVENTCOUNT)
        {
          /* set interference event */
          puiBlockageEvent->InterferenceRange = AL_ERR_STATE_ACTIVE;
          SPMData.SPMInterferenceHoldCnt = SPM_INTERFERENCE_RANGE_HOLD;
          SPMData.SPMInterferenceState = TRUE;
        }
        else if(SPMData.SPMInterferenceHoldCnt > SPM_INTERF_HOLD_COUNTER_THLD)
        {
          /* hold interference event */
          puiBlockageEvent->InterferenceRange = AL_ERR_STATE_ACTIVE;
          SPMData.SPMInterferenceHoldCnt--;
          SPMData.SPMInterferenceState = TRUE;
        }
        else
        {
          /* no interference */
          puiBlockageEvent->InterferenceRange = AL_ERR_STATE_INACTIVE;
          SPMData.SPMInterferenceState = FALSE;
        }
      }
  
    /*--- UNDEF SYMBOLIC CONSTANTS ---*/
  }
  #endif
#endif
