/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_naviscc.c

DESCRIPTION:               File containing NSCC custom functions for KMC in LOPC

AUTHOR:                    Thomas Mielke (uidq4510)

CREATION DATE:             05.12.2017

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 1.10

**************************************************************************** */

#if KMC_CFG_HI_NAVI_FEATURE// PRQA S 3332
/* date: 2018-10-31, reviewer: Radhakrishna Vemula, reason: Macro Defined Externally for simulation purpose*/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "Rte_type.h"
#include "fct_types.h"
#include "kmc_naviscc.h"
#include "cc_ext.h"
#include "fct_veh.h"
#include "cal_param_ext.h"
#include "cal_std_ext.h"

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

#define p_CamWarnInvalidDist (sint16)(-1)
#define p_CamWarnInvalidSpd (sint16)(-1)
#define p_OSC_SpdGain_Accel 0.05f
#define p_OSC_SpdGain_Decel 0.08f
#define p_NSCCReqAccelInit 10.0f
#define p_CamWarnCtrlChgDist (uint16)30
#define p_FOSC_FnInhibit FALSE
#define p_ACCMode_Engaged (uint8)1
#define p_MOSC_FnInhibit FALSE
#define p_OSC_TotalDistOfMosc (sint16)300
#define p_SOSC_FnInhibit FALSE
#define p_OSC_ReqAccelMax 3.0f
#define p_OSC_ReqAccelMin (-2.0f)
#define p_MOSC_CamWarnCtrlDist (uint16)200
#define p_FOSC_CamWarnCtrlDist (uint16)200
#define p_FMOSC_CamWarnCtrlDist (uint16)200
#define p_OSC_DesiredDecel (-0.2f)
#define p_OSC_CamWarnValidDistMaxL (sint16)600
#define p_OSC_CamWarnValidDistMaxH (sint16)1000
#define p_OSC_CamWarnValidSpdMax (uint8)140
#define p_OSC_CamWarnValidSpdMinFreeway (uint8)50
#define p_OSC_CamWarnValidSpdMinArterial (uint8)30
#define p_OSC_TargetSpdOffset (sint8)(-1)
#define p_SOSC_AvgSpdCtrlRatio (sint8)2
#define p_SOSC_AvgSpdCtrlOffset (sint8)3
#define p_SOSC_CtrlSpdMinRatio (percentage_t)75

/* NaviSCC-C */
#define p_NSCC_C_DistOfInterestMaxL 100 
#define p_NSCC_C_DistOfInterestMaxH 1000
#define p_NSCC_C_TimeForDoI 15u
#define p_NSCC_C_SafeSpdMax 250
#define p_NSCC_C_TargetType_Invalid 0u
#define p_NSCC_C_TargetType_Main 1u
#define p_NSCC_C_TargetDistInit 10000
#define p_NSCC_C_TargetRInit 10000
#define p_NSCC_C_DistOfInterestMin 50
#define p_NSCC_C_ReqAccelMax 3.0f
#define p_NSCC_C_ReqAccelMin (-1.0f)
#define p_SafeSpdMax 250
#define p_Retransmission_Offset 50
#define p_PROSHORT_ProfileType_Curvature 1u
#define p_Curvature_min 32
#define NSCC_C_CURVE_LOOKUP_TABLE_POINTS 13u

/*****************************************************************************
 APPLICATION PARAMETERS 
*****************************************************************************/

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

static union
  {
    nscc_measfreeze_data_t   NSCC_MEAS_DATA;  /*!< The real data */
    uint32 MTS_DUMMY;                         /*!< Needed to align the data to the MTS requirement */
  } gNSCC_MEAS_DATA;                          /*!< @VADDR:0x20022000 @CYCLEID:FCT_VEH */
  static const MEASInfo_t MEASINFO_NSCC_DATA = {0x20022000u, sizeof(gNSCC_MEAS_DATA), FCT_MEAS_FUNC_ID, FCT_MEAS_FUNC_CHAN_ID};

/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/

static boolean OSC_RoadClassCond = FALSE;
static boolean OSC_LinkClassCond = FALSE;
static boolean OSC_DataReady = FALSE;
static OSC_SpotCamInfoList_Type_t OSC_NearestSpotCam_Type = POI_TYPE_NONE;
static uint16 OSC_CamWarnCtrlDist = 0u;
static boolean OSC_SetSpdChg = FALSE;
static boolean SOSC_Valid = FALSE;
static boolean MOSC_IsInSection = FALSE;
static sint16 OSC_TargetDist = 0;
static sint16 OSC_TargetDistOld = 0;
static sint16 OSC_TargetSpd = 0;
static float32 SOSC_TargetSpd = 0.0f;
static boolean SOSC_TargetSpd_invalid = FALSE;

/* NaviSCC-C */
static boolean NSCC_C_RoadClassCond = FALSE;
static boolean NSCC_C_LinkClassCond = FALSE;
static sint16 NSCC_C_TargetDist = 0;
static sint16 NSCC_C_TargetR = 0;
static sint16 NSCC_C_TargetSpd = 0;
static uint8 NSCC_C_TargetType = 0u;
static boolean NSCC_C_SetSpdChg = FALSE;

static const sint16 p_NSCC_C_TargetSpdLane1[2u*NSCC_C_CURVE_LOOKUP_TABLE_POINTS] =
{
  15,27,
  30,35,
  60,48,
  90,52,
  140,63,
  200,72,
  280,79,
  380,87,
  460,94,
  600,103,
  710,110,
  1032,128,
  1500,250
};

static const sint16 p_NSCC_C_TargetSpdLane2[2u*NSCC_C_CURVE_LOOKUP_TABLE_POINTS] =
{
  15,27,
  30,35,
  60,48,
  90,54,
  140,66,
  200,75,
  280,82,
  380,91,
  460,98,
  600,107,
  710,115,
  1032,134,
  1500,250
};

static const sint16 p_NSCC_C_TargetSpdLane3[2u*NSCC_C_CURVE_LOOKUP_TABLE_POINTS] =
{
  15,27,
  30,35,
  60,48,
  90,57,
  140,69,
  200,79,
  280,86,
  380,95,
  460,103,
  600,112,
  710,120,
  1032,140,
  1500,250
};

static const sint16 p_NSCC_C_TargetSpdLane4[2u*NSCC_C_CURVE_LOOKUP_TABLE_POINTS] =
{
  15,27,
  30,35,
  60,48,
  90,59,
  140,71,
  200,82,
  280,89,
  380,98,
  460,107,
  600,116,
  710,124,
  1032,145,
  1500,250
};

static const sint16 p_NSCC_C_TargetSpdLane5[2u*NSCC_C_CURVE_LOOKUP_TABLE_POINTS] =
{
  15,27,
  30,35,
  60,48,
  90,61,
  140,74,
  200,85,
  280,92,
  380,102,
  460,111,
  600,120,
  710,129,
  1032,151,
  1500,250
};


/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/

static void NSCC_DECODE_SPEED_VALUES(nscc_inputs_t * NSCCIn);

static void NSCC_PROCESS_SIGNALS(nscc_inputs_t * NSCCIn, setspeed_t cc_setspeed, LongCtrlOutput_t * pLongCtrlCmd);

static void NSCC_MODE_MANAGER(nscc_inputs_t * NSCCIn, acc_mode_t ACCMode, boolean CCOnlyActive);

static void NSCC_CALC_ACCEL_REQ(const nscc_inputs_t * NSCCIn, acc_mode_t ACCMode, LongCtrlOutput_t * pLongCtrlCmd);

static void FCT_NSCC_MTS_CALLBACK(void);

static void NSCC_C_CURVE_MAP_RECONSTRUCTOR(nscc_inputs_t * NSCCIn);

/*************************************************************************************************************************
  Functionname:    NSCC_C_CURVE_MAP_RECONSTRUCTOR                                                                   */ /*!

  @brief           Calculation of curve information

  @description     Calculation of curve information based on CAN inputs from Navi

  @return          static void

  @param[in,out]   NSCCIn : NaviSCC input data
  @param[out]      pLongCtrlCmd : LongCtrlOutput data

  @glob_in         p_NSCC_C_TargetSpdLane1 : lookup-table for conversion from curve radius to allowed speed (1 lane road)
                   p_NSCC_C_TargetSpdLane2 : lookup-table for conversion from curve radius to allowed speed (2 lane road)
                   p_NSCC_C_TargetSpdLane3 : lookup-table for conversion from curve radius to allowed speed (3 lane road)
                   p_NSCC_C_TargetSpdLane4 : lookup-table for conversion from curve radius to allowed speed (4 lane road)
                   p_NSCC_C_TargetSpdLane5 : lookup-table for conversion from curve radius to allowed speed (else)

  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         11.08.2017
  @changed         11.08.2017

  @author          Thomas Mielke | thomas.mielke-ext@conti-engineering.com | +49 (69) 67869-6417
*************************************************************************************************************************/
static void NSCC_C_CURVE_MAP_RECONSTRUCTOR(nscc_inputs_t * NSCCIn)
{
  uint8 i = 0u;
  uint8 j = 0u;
  uint8 k = 0u;
  uint8 l = 0u;
  uint8 m = 0u;
  uint8 n = 0u;
  boolean J_COND = FALSE;
  boolean L_COND = FALSE;
  boolean M_COND = FALSE;
  sint16 CurveRadius = 0;
  uint8 CurSafeSpd = 0u;
  static float32 CurDesiredAy = 0.0f;
  nscc_linkclass_t PROSHORT_link_class = LC_UNKNOWN;
  nscc_roadclass_t PROSHORT_road_class = RC_UNKNOWN;
  boolean MainLinkCurve_flag = FALSE;
  static uint8 PROSHORT_CyclicCounter_Old = p_CyclicCounter_Invalid;
  static sint16 CurRadius = 0; 
  
  /* NaviSCC-C CurveRadiusCalculation */

  if (NSCCIn->PROSHORT_Value0 <= 510u)
  {
    CurveRadius = (sint16)MAT_ABS((2*(sint32)NSCCIn->PROSHORT_Value0) - 1032);
  }
  else if (NSCCIn->PROSHORT_Value0 == 511u)
  {
    CurveRadius = 0;
  }
  else if (NSCCIn->PROSHORT_Value0 <= 1022u)
  {
    CurveRadius = (sint16)MAT_ABS((2*(sint32)NSCCIn->PROSHORT_Value0) - 1012);
  }
  else if (NSCCIn->PROSHORT_Value0 == 1023u)
  {
    CurveRadius = 32767; // todo: N/A case, what value should be set?
  }
  else
  {
    CurveRadius = 32767; // same as N/A case?
  }

  /* NaviSCC-C 3.8 MainLinkCurve_flag */

  PROSHORT_road_class = NSCCIn->NSCC_CurRoadClass;
  PROSHORT_link_class = NSCCIn->NSCC_CurLinkClass;

  for (i=0u;i<NSCCIn->NSCC_SegInfoValidSize;i++)
  {
    if (NSCCIn->NSCC_SegInfoList_Dist[i] < NSCCIn->PROSHORT_Offset)
    {
      PROSHORT_road_class = NSCCIn->NSCC_SegInfoList_RoadClass[i];
      PROSHORT_link_class = NSCCIn->NSCC_SegInfoList_LinkClass[i];
    }
    else
    {
      // do nothing
    }
  }

  if (
      (
       (PROSHORT_road_class == FREEWAY)
       ||
       (PROSHORT_road_class == ARTERIAL)
      )
      &&
      (
       (PROSHORT_link_class == MAINROAD_NONDIS)
       ||
       (PROSHORT_link_class == MAINROAD_DIS)
      )
     )
  {
    MainLinkCurve_flag = TRUE;
  }
  else
  {
    MainLinkCurve_flag = FALSE;
  }



  /* NaviSCC-C 3.8 NDP_ProshortMsgProcessing4Curvature */

  if (NSCCIn->NDP_BufferResetNSCC_C == TRUE)
  {
    NSCCIn->NDP_CurveInfoValidSize = 0u;
    PROSHORT_CyclicCounter_Old = p_CyclicCounter_Invalid;
  }
  else
  {
    // do nothing
  }

  if (
      (NSCCIn->NDP_CurveInfoValidSizeEndReal > 0u)
      &&
      (NSCCIn->NSCC_PosMsgUpdate == TRUE)
     )
  {
    for (i=0u;i<NSCCIn->NDP_CurveInfoValidSizeEndReal;i++)
    {
      NSCCIn->NDP_CurveInfoListDistReal[i] = NSCCIn->NDP_CurveInfoListDistReal[i] - (sint16)ROUND_TO_INT(NSCCIn->DrivingDistForPosMsgUpdate);
      NSCCIn->NDP_CurveInfoListDistEndReal[i] = NSCCIn->NDP_CurveInfoListDistEndReal[i] - (sint16)ROUND_TO_INT(NSCCIn->DrivingDistForPosMsgUpdate);
    }
    
    l = 0u;
    while(L_COND == FALSE)
    {
      if (l < NSCCIn->NDP_CurveInfoValidSizeReal)
      {
        if (NSCCIn->NDP_CurveInfoListDistReal[l] > 0)
        {
          l++;
          // continue
        }
        else
        {
          NSCCIn->NDP_CurveInfoValidSizeReal -= 1u;
          CurRadius = NSCCIn->NDP_CurveInfoListRred[l];
          if (NSCCIn->NDP_CurLanes == 1u)
          {
            CurSafeSpd = (uint8)MAT_CALCULATE_PARAM_VALUE1D(p_NSCC_C_TargetSpdLane1, NSCC_C_CURVE_LOOKUP_TABLE_POINTS, CurRadius);
          }
          else if (NSCCIn->NDP_CurLanes == 2u)
          {
            CurSafeSpd = (uint8)MAT_CALCULATE_PARAM_VALUE1D(p_NSCC_C_TargetSpdLane2, NSCC_C_CURVE_LOOKUP_TABLE_POINTS, CurRadius);
          }
          else if (NSCCIn->NDP_CurLanes == 3u)
          {
            CurSafeSpd = (uint8)MAT_CALCULATE_PARAM_VALUE1D(p_NSCC_C_TargetSpdLane3, NSCC_C_CURVE_LOOKUP_TABLE_POINTS, CurRadius);
          }
          else if (NSCCIn->NDP_CurLanes == 4u)
          {
            CurSafeSpd = (uint8)MAT_CALCULATE_PARAM_VALUE1D(p_NSCC_C_TargetSpdLane4, NSCC_C_CURVE_LOOKUP_TABLE_POINTS, CurRadius);
          }
          else
          {
            CurSafeSpd = (uint8)MAT_CALCULATE_PARAM_VALUE1D(p_NSCC_C_TargetSpdLane5, NSCC_C_CURVE_LOOKUP_TABLE_POINTS, CurRadius);
          }
          CurDesiredAy = (((float32)CurSafeSpd/C_KMH_MS)*((float32)CurSafeSpd/C_KMH_MS)) / (float32)CurRadius;


          if (NSCCIn->NDP_CurveInfoValidSizeReal > 0u)
          {
            k = 0u;
            for(k=l;k<NSCCIn->NDP_CurveInfoValidSizeReal;k++)
            {
              NSCCIn->NDP_CurveInfoListDistReal[k] = NSCCIn->NDP_CurveInfoListDistReal[k+1u];
              NSCCIn->NDP_CurveInfoListRred[k] = NSCCIn->NDP_CurveInfoListRred[k+1u]; 
            }
            l = 0u;
            // continue
          }
          else
          {
            L_COND = TRUE;
            // break
          }
        }
      }
      else
      {
        L_COND = TRUE;
        // break
      }
    }

    m = 0u;
    while(M_COND == FALSE)
    {
      if (m < NSCCIn->NDP_CurveInfoValidSizeEndReal)
      {
        if (NSCCIn->NDP_CurveInfoListDistEndReal[m] > 0)
        {
          m++;
          // continue
        }
        else
        {
          NSCCIn->NDP_CurveInfoValidSizeEndReal -= 1u;



          if (NSCCIn->NDP_CurveInfoValidSizeEndReal > 0u)
          {
            k = 0u;
            for(k=m;k<NSCCIn->NDP_CurveInfoValidSizeEndReal;k++)
            {
              NSCCIn->NDP_CurveInfoListDistEndReal[k] = NSCCIn->NDP_CurveInfoListDistEndReal[k+1u];
            }
            m = 0u;
            // continue
          }
          else
          {
            M_COND = TRUE;
            // break
          }
        }
      }
      else
      {
        M_COND = TRUE;
        // break
      }
    }

    if (NSCCIn->NDP_CurveInfoValidSizeReal == NSCCIn->NDP_CurveInfoValidSizeEndReal)
    {
      CurRadius = 0;
      CurDesiredAy = 0.0f;
    }
    else
    {
      //nothing
    }
  }
  else
  {
  }



  if (
      (NSCCIn->NDP_CurveInfoValidSize > 0u)
      &&
      (NSCCIn->NSCC_PosMsgUpdate == TRUE)
     )
  {
    for (i=0u;i<NSCCIn->NDP_CurveInfoValidSize;i++)
    {
      NSCCIn->NDP_CurveInfoListDist[i] = NSCCIn->NDP_CurveInfoListDist[i] - (sint16)ROUND_TO_INT(NSCCIn->DrivingDistForPosMsgUpdate);
    }

    j = 0u;
    while(J_COND == FALSE)
    {
      if (j < NSCCIn->NDP_CurveInfoValidSize)
      {
        if (NSCCIn->NDP_CurveInfoListDist[j] > 0)
        {
          j++;
          // continue
        }
        else
        {
          NSCCIn->NDP_CurveInfoValidSize -= 1u;
          if (NSCCIn->NDP_CurveInfoValidSize > 0u)
          {
            k = 0u;
            for(k=j;k<NSCCIn->NDP_CurveInfoValidSize;k++)
            {
              NSCCIn->NDP_CurveInfoListDist[k] = NSCCIn->NDP_CurveInfoListDist[k+1u];
              NSCCIn->NDP_CurveInfoListR[k] = NSCCIn->NDP_CurveInfoListR[k+1u]; 
            }
            j = 0u;
            // continue
          }
          else
          {
            J_COND = TRUE;
            // break
          }
        }
      }
      else
      {
        J_COND = TRUE;
        // break
      }
    }
  }
  else
  {
    // do nothing (J)
  }

  // J
  if (
      (NSCCIn->PROSHORT_Offset != p_Offset_Invalid)
      &&
      (NSCCIn->PROSHORT_Distance != p_PROSHORT_Distance_Invalid)
      &&
      (NSCCIn->PROSHORT_CyclicCounter != p_CyclicCounter_Invalid)
      &&
      (NSCCIn->PROSHORT_ProfileType != p_PROSHORT_ProfileType_Invalid)
      &&
      (NSCCIn->PROSHORT_ProfileType == p_PROSHORT_ProfileType_Curvature)
      &&
      (NSCCIn->PROSHORT_CyclicCounter != PROSHORT_CyclicCounter_Old)
      &&
      (NSCCIn->PROSHORT_Value0 != p_PROSHORT_Value_Invalid)
     )
  {
    if (
        (((NSCCIn->PROSHORT_Offset - (uint16)ROUND_TO_UINT(NSCCIn->DistBySysDelay)) + (NSCCIn->PROSHORT_Distance*2u)) > 0u)
        &&
        (MainLinkCurve_flag == TRUE)
        &&
        (CurveRadius > p_Curvature_min)
       )
    {
      NSCCIn->NDP_CurveInfoListDist[NSCCIn->NDP_CurveInfoValidSize] = ( (sint16)NSCCIn->PROSHORT_Offset + (sint16)ROUND_TO_INT((float32)NSCCIn->PROSHORT_Distance * 0.5f) ) 
                                                                      - (sint16)ROUND_TO_INT(NSCCIn->DistBySysDelay);
      NSCCIn->NDP_CurveInfoListDist[NSCCIn->NDP_CurveInfoValidSize+1u] = ( (sint16)NSCCIn->PROSHORT_Offset + (sint16)ROUND_TO_INT((float32)NSCCIn->PROSHORT_Distance * 1.5f) )
                                                                        - (sint16)ROUND_TO_INT(NSCCIn->DistBySysDelay);
	    NSCCIn->NDP_CurveInfoListDistReal[NSCCIn->NDP_CurveInfoValidSizeReal] = (sint16)NSCCIn->PROSHORT_Offset - (sint16)NSCCIn->DistBySysDelay;
      NSCCIn->NDP_CurveInfoListDistEndReal[NSCCIn->NDP_CurveInfoValidSizeReal] = ( (sint16)NSCCIn->PROSHORT_Offset + (sint16)ROUND_TO_INT((float32)NSCCIn->PROSHORT_Distance * 2.0f) ) 
                                                                                 - (sint16)NSCCIn->DistBySysDelay;
      NSCCIn->NDP_CurveInfoListR[NSCCIn->NDP_CurveInfoValidSize] = CurveRadius;
      NSCCIn->NDP_CurveInfoListR[NSCCIn->NDP_CurveInfoValidSize+1u] = CurveRadius;
      NSCCIn->NDP_CurveInfoListRred[NSCCIn->NDP_CurveInfoValidSizeReal] = CurveRadius;
      NSCCIn->NDP_CurveInfoValidSize = NSCCIn->NDP_CurveInfoValidSize + 2u;
      NSCCIn->NDP_CurveInfoValidSizeReal = NSCCIn->NDP_CurveInfoValidSizeReal + 1u;
      NSCCIn->NDP_CurveInfoValidSizeEndReal = NSCCIn->NDP_CurveInfoValidSizeEndReal + 1u;
      PROSHORT_CyclicCounter_Old = NSCCIn->PROSHORT_CyclicCounter;
    }
    else
    {
      PROSHORT_CyclicCounter_Old = NSCCIn->PROSHORT_CyclicCounter;
    }
  }
  else
  {
    // do nothing (don't update PROSHORT_CyclicCounter_Old)
  }



  /* NSCC-C MeasFreezes */
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.MainLinkCurve_flag_MEAS = MainLinkCurve_flag;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.CurDesiredAy_MEAS = CurDesiredAy;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.CurRadius_MEAS = CurRadius;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.CurSafeSpd_MEAS = CurSafeSpd;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NDP_CurveInfoValidSize_MEAS = NSCCIn->NDP_CurveInfoValidSize;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NDP_CurveInfoValidSizeReal_MEAS = NSCCIn->NDP_CurveInfoValidSizeReal;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NDP_CurveInfoValidSizeEndReal_MEAS = NSCCIn->NDP_CurveInfoValidSizeEndReal;

  for (n=0u;n<NSCC_C_CURVE_ARRAY_SIZE_MEAS;n++)
  {
    gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NDP_CurveInfoListDist_MEAS[n] = NSCCIn->NDP_CurveInfoListDist[n];
    gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NDP_CurveInfoListR_MEAS[n] = NSCCIn->NDP_CurveInfoListR[n];

    if (n<NSCC_C_CURVE_ARRAY_SIZE_MEAS_REDUCED)
    {
      gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NDP_CurveInfoListDistReal_MEAS[n] = NSCCIn->NDP_CurveInfoListDistReal[n];
      gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NDP_CurveInfoListDistEndReal_MEAS[n] = NSCCIn->NDP_CurveInfoListDistEndReal[n];
      gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NDP_CurveInfoListRred_MEAS[n] = NSCCIn->NDP_CurveInfoListRred[n];
    }
    else
    {
      // do nothing
    }
  }
}


/*************************************************************************************************************************
  Functionname:    NSCC_DECODE_SPEED_VALUES                                                                         */ /*!

  @brief           Decoding of speed information codes to km/h

  @description     -

  @return          static nscc_inputs_t : input signals with speed signals in km/h

  @param[in]       NSCCIn : NaviSCC input signals coming from SW

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         12.09.2016
  @changed         12.09.2016

  @author          Thomas Mielke | thomas.mielke-ext@conti-engineering.com | +49 (69) 67869-6417
*************************************************************************************************************************/
static void NSCC_DECODE_SPEED_VALUES(nscc_inputs_t * NSCCIn)
{
  uint8 i;

  // PROLONG decoding
  for(i=0u;i<(uint8)FCT_NAVISCC_MAX_NUM_OF_POI;i++)
  {
    switch(NSCCIn->OSC_SpotCamInfoList_Spd[i])
    {
    case 0u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 0u;
      break;
    case 1u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 5u;
      break;
    case 2u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 7u;
      break;
    case 3u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 10u;
      break;
    case 4u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 15u;
      break;
    case 5u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 20u;
      break;
    case 6u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 25u;
      break;
    case 7u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 30u;
      break;
    case 8u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 35u;
      break;
    case 9u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 40u;
      break;
    case 10u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 45u;
      break;
    case 11u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 50u;
      break;
    case 12u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 55u;
      break;
    case 13u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 60u;
      break;
    case 14u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 65u;
      break;
    case 15u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 70u;
      break;
    case 16u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 75u;
      break;
    case 17u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 80u;
      break;
    case 18u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 85u;
      break;
    case 19u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 90u;
      break;
    case 20u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 95u;
      break;
    case 21u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 100u;
      break;
    case 22u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 105u;
      break;
    case 23u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 110u;
      break;
    case 24u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 115u;
      break;
    case 25u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 120u;
      break;
    case 26u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 130u;
      break;
    case 27u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 140u;
      break;
    case 28u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 150u;
      break;
    case 29u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 160u;
      break;
    case 30u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 255u;
      break;
    case 31u:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 0u;
      break;
    default:
      NSCCIn->OSC_SpotCamInfoList_Spd[i] = 0u;
      break;
    }
  }

  // PROSHORT decoding
  switch(NSCCIn->OSC_SectCam_Spd)
  {
  case 0u:
    NSCCIn->OSC_SectCam_Spd = 0u;
    break;
  case 1u:
    NSCCIn->OSC_SectCam_Spd = 5u;
    break;
  case 2u:
    NSCCIn->OSC_SectCam_Spd = 7u;
    break;
  case 3u:
    NSCCIn->OSC_SectCam_Spd = 10u;
    break;
  case 4u:
    NSCCIn->OSC_SectCam_Spd = 15u;
    break;
  case 5u:
    NSCCIn->OSC_SectCam_Spd = 20u;
    break;
  case 6u:
    NSCCIn->OSC_SectCam_Spd = 25u;
    break;
  case 7u:
    NSCCIn->OSC_SectCam_Spd = 30u;
    break;
  case 8u:
    NSCCIn->OSC_SectCam_Spd = 35u;
    break;
  case 9u:
    NSCCIn->OSC_SectCam_Spd = 40u;
    break;
  case 10u:
    NSCCIn->OSC_SectCam_Spd = 45u;
    break;
  case 11u:
    NSCCIn->OSC_SectCam_Spd = 50u;
    break;
  case 12u:
    NSCCIn->OSC_SectCam_Spd = 55u;
    break;
  case 13u:
    NSCCIn->OSC_SectCam_Spd = 60u;
    break;
  case 14u:
    NSCCIn->OSC_SectCam_Spd = 65u;
    break;
  case 15u:
    NSCCIn->OSC_SectCam_Spd = 70u;
    break;
  case 16u:
    NSCCIn->OSC_SectCam_Spd = 75u;
    break;
  case 17u:
    NSCCIn->OSC_SectCam_Spd = 80u;
    break;
  case 18u:
    NSCCIn->OSC_SectCam_Spd = 85u;
    break;
  case 19u:
    NSCCIn->OSC_SectCam_Spd = 90u;
    break;
  case 20u:
    NSCCIn->OSC_SectCam_Spd = 95u;
    break;
  case 21u:
    NSCCIn->OSC_SectCam_Spd = 100u;
    break;
  case 22u:
    NSCCIn->OSC_SectCam_Spd = 105u;
    break;
  case 23u:
    NSCCIn->OSC_SectCam_Spd = 110u;
    break;
  case 24u:
    NSCCIn->OSC_SectCam_Spd = 115u;
    break;
  case 25u:
    NSCCIn->OSC_SectCam_Spd = 120u;
    break;
  case 26u:
    NSCCIn->OSC_SectCam_Spd = 130u;
    break;
  case 27u:
    NSCCIn->OSC_SectCam_Spd = 140u;
    break;
  case 28u:
    NSCCIn->OSC_SectCam_Spd = 150u;
    break;
  case 29u:
    NSCCIn->OSC_SectCam_Spd = 160u;
    break;
  case 30u:
    NSCCIn->OSC_SectCam_Spd = 255u;
    break;
  case 31u:
    NSCCIn->OSC_SectCam_Spd = 0u;
    break;
  default:
    NSCCIn->OSC_SectCam_Spd = 0u;
    break;
  }
}

/*************************************************************************************************************************
  Functionname:    NSCC_PROCESS_SIGNALS                                                                             */ /*!

  @brief           Processing of NaviSCC input signals

  @description     In this function, the NaviSCC inputs coming from SW are processed to obtain all information
                   required for NaviSCC speed control.
                   
  @return          static void

  @param[in]       NSCCIn : NaviSCC input signals coming from SW
  @param[in]       cc_setspeed : ACC setspeed
  @param[in,out]   pLongCtrlCmd : output of the longitudinal controller

  @glob_in         OSC_RoadClassCond : road class condition for activating NaviSCC (FREEWAY or ARTERIAL) is fulfilled                           [TRUE, FALSE]
  @glob_in         OSC_LinkClassCond : link class condition for activating NaviSCC (MAINROAD_DIS or MAINROAD_NONDIS) is fulfilled               [TRUE, FALSE]
  @glob_in         OSC_DataReady : information about the nearest speed camera  is available                                                     [TRUE, FALSE]
  @glob_in         OSC_NearestSpotCam_Type : type of the nearest speed camera (None, Fixed, Moving, FixedMoving)                                [0...3]
  @glob_in         OSC_CamWarnCtrlDist : distance to the speed camera, where the vehicle velocity should reach the speed limit                  [full range of unsigned short]
  @glob_in         OSC_SwCond : switch input condition for activating NaviSCC is fulfilled                                                      [TRUE, FALSE]
  @glob_in         OSC_TargetDist : distance to nearest speed camera updated every second                                                       [full range of signed short]
  @glob_in         SOSC_TargetSpd : current target speed limit for camera enforcement section                                                   [full range of float32]
  @glob_in         NSCC_C_TargetDist : distance to target curve                                                                                 [full range of signed short]
  @glob_in         NSCC_C_TargetR : radius of target curve                                                                                      [full range of signed short]
  @glob_in         NSCC_C_TargetSpd : allowed speed at target curve                                                                             [full range of signed short]
  @glob_out        OSC_RoadClassCond : road class condition for activating NaviSCC (FREEWAY or ARTERIAL) is fulfilled                           [TRUE, FALSE]
  @glob_out        OSC_LinkClassCond : link class condition for activating NaviSCC (MAINROAD_DIS or MAINROAD_NONDIS) is fulfilled               [TRUE, FALSE]
  @glob_out        OSC_DataReady : information about the nearest speed camera  is available                                                     [TRUE, FALSE]
  @glob_out        OSC_NearestSpotCam_Type : type of the nearest speed camera (None, Fixed, Moving, FixedMoving)                                [0...3]
  @glob_out        OSC_CamWarnCtrlDist : distance to the speed camera, where the vehicle velocity should reach the speed limit                  [full range of unsigned short]
  @glob_out        OSC_SetSpdChg :  ACC setspeed is bigger than the current relevant speed limit                                                [TRUE, FALSE]
  @glob_out        SOSC_Valid : information about the camera enforcement section is available and the vehicle is currently inside that section  [TRUE, FALSE]
  @glob_out        OSC_TargetDist : distance to nearest speed camera updated every second                                                       [full range of signed short]
  @glob_out        OSC_TargetDistOld : distance to nearest speed camera of former cycle                                                         [full range of signed short]
  @glob_out        OSC_TargetSpd : current target speed limit                                                                                   [full range of signed short]
  @glob_out        SOSC_TargetSpd : current target speed limit for camera enforcement section                                                   [full range of float32]
  @glob_out        SOSC_TargetSpd_invalid : calculation of SOSC_TargetSpd wasn't successfull                                                    [TRUE, FALSE]
  @glob_out        NSCC_C_RoadClassCond : road class condition for activating NaviSCC-C (FREEWAY or ARTERIAL) is fulfilled                      [TRUE, FALSE]
  @glob_out        NSCC_C_LinkClassCond : link class condition for activating NaviSCC-C (MAINROAD_DIS or MAINROAD_NONDIS) is fulfilled          [TRUE, FALSE]
  @glob_out        NSCC_C_TargetDist : distance to target curve                                                                                 [full range of signed short]
  @glob_out        NSCC_C_TargetR : radius of target curve                                                                                      [full range of signed short]
  @glob_out        NSCC_C_TargetSpd : allowed speed at target curve                                                                             [full range of signed short]
  @glob_out        NSCC_C_TargetType : target curve type                                                                                        [full range of unsigned char]
  @glob_out        NSCC_C_SetSpdChg : setspeed condition (NSCC-C target speed < ACC setspeed)                                                   [TRUE, FALSE]


  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         12.09.2016
  @changed         12.09.2016

  @author          Thomas Mielke | thomas.mielke-ext@conti-engineering.com | +49 (69) 67869-6417
*************************************************************************************************************************/
static void NSCC_PROCESS_SIGNALS(nscc_inputs_t * NSCCIn, setspeed_t cc_setspeed, LongCtrlOutput_t * pLongCtrlCmd)
{
  static sint16 OSC_NearestSpotCam_Spd = 0;
  static boolean OSC_CamValidDistMaxChgEn = FALSE;
  static sint16 OSC_NearestSpotCam_Dist = 0;
  static float32 OSC_CamWarnValidDistMax = 0.0f;
  static sint16 OSC_CurLmtSpd = 0;
  static boolean OSC_CurLmtSpdChgByCam = FALSE;
  float32 OSC_CamWarnValidDistMax_Old = 0.0f;
  float32 helpvar1 = 0.0f;
  float32 helpvar2 = 0.0f;
  float32 SOSC_AvgSpd = 0.0f;
  float32 SOSC_TargetSpdAvg = 0.0f;
  float32 SOSC_CtrlMinSpd = 0.0f;
  uint8 i;
  uint8 k;
  boolean kLoopCond = TRUE;
  boolean iLoopCond = TRUE;
  boolean OSC_Data_set_invalid = FALSE;

  /* NaviSCC-C */
  uint8 NSCC_C_TimeForDoI = 0u;
  sint16 NSCC_C_DistOfInterestMax = 0;
  static sint16 NSCC_C_DistOfInterestMaxOld = 0;
  sint16 NSCC_C_DistOfInterestMin = 0;


  /*************/

  /* 3.2.1 */
  if(NSCCIn->OSC_USM_Status == TRUE)
	{
    NSCCIn->NSCC_Z_SwCond = TRUE;
	}
	else
	{
		NSCCIn->NSCC_Z_SwCond = FALSE;
	}

  /* 3.2.2 */
  if(
     (NSCCIn->NSCC_CurRoadClass == FREEWAY)
	   ||
	   (NSCCIn->NSCC_CurRoadClass == ARTERIAL)
    )
	{
		OSC_RoadClassCond = TRUE;
	}
	else
	{
		OSC_RoadClassCond = FALSE;
	}

  /* 3.2.3 */
  if(
     (NSCCIn->NSCC_CurLinkClass == MAINROAD_NONDIS)
		 ||
		 (NSCCIn->NSCC_CurLinkClass == MAINROAD_DIS)
    )
	{
		OSC_LinkClassCond = TRUE;
	}
	else
	{
		OSC_LinkClassCond = FALSE;
	}

  /* 3.3.1 */

  if(NSCCIn->NSCC_DataReady == TRUE)
  {
    i = 0u;
    k = 0u;
    while(kLoopCond == TRUE)
    {
      iLoopCond = TRUE;
      if(NSCCIn->OSC_SpotCamInfoValidSize > k)
      {
        if(NSCCIn->NSCC_SegInfoValidSize == 0u) // <= changed to == because of SegInfoValidSize being unsigned!
        {
          if(
             (OSC_RoadClassCond == TRUE)
             &&
             (OSC_LinkClassCond == TRUE)
            )
          {
            kLoopCond = FALSE;
            iLoopCond = FALSE;
          }
          else
          {
            k++;
          }
        }
        else
        {
          if(i>0u)
          {
            while(iLoopCond == TRUE)
            {
              if(NSCCIn->NSCC_SegInfoList_Dist[i] >= NSCCIn->OSC_SpotCamInfoList_Dist[k])
              {
                if(
                   (
                    (NSCCIn->NSCC_SegInfoList_RoadClass[i-1u] == FREEWAY)
                    ||
                    (NSCCIn->NSCC_SegInfoList_RoadClass[i-1u] == ARTERIAL)
                   )
                   &&
                   (
                    (NSCCIn->NSCC_SegInfoList_LinkClass[i-1u] == MAINROAD_DIS)
                    ||
                    (NSCCIn->NSCC_SegInfoList_LinkClass[i-1u] == MAINROAD_NONDIS)
                   )
                  )
                {
                  kLoopCond = FALSE;
                  iLoopCond = FALSE;
                }
                else
                {
                  k++;
                  iLoopCond = FALSE;
                }
              }
              else
              {
                i++;
                if(NSCCIn->NSCC_SegInfoValidSize <= i)
                {
                  if(
                      (
                      (NSCCIn->NSCC_SegInfoList_RoadClass[i-1u] == FREEWAY)
                      ||
                      (NSCCIn->NSCC_SegInfoList_RoadClass[i-1u] == ARTERIAL)
                      )
                      &&
                      (
                      (NSCCIn->NSCC_SegInfoList_LinkClass[i-1u] == MAINROAD_DIS)
                      ||
                      (NSCCIn->NSCC_SegInfoList_LinkClass[i-1u] == MAINROAD_NONDIS)
                      )
                    )
                  {
                    kLoopCond = FALSE;
                    iLoopCond = FALSE;
                  }
                  else
                  {
                    k++;
                    iLoopCond = FALSE;
                  }
                }
                else
                {
                  // do nothing
                }
              }
            }
          }
          else
          {
            if(NSCCIn->NSCC_SegInfoList_Dist[i] >= NSCCIn->OSC_SpotCamInfoList_Dist[k])
            {
              if(
                 (OSC_RoadClassCond == TRUE)
                 &&
                 (OSC_LinkClassCond == TRUE)
                )
              {
                kLoopCond = FALSE;
                iLoopCond = FALSE;
              }
              else
              {
                k++;
                iLoopCond = FALSE;
              }
            }
            else
            {
              while(iLoopCond == TRUE)
              {
                i++;
                if(NSCCIn->NSCC_SegInfoValidSize <= i)
                {
                  if(
                     (
                      (NSCCIn->NSCC_SegInfoList_RoadClass[i-1u] == FREEWAY)
                      ||
                      (NSCCIn->NSCC_SegInfoList_RoadClass[i-1u] == ARTERIAL)
                     )
                     &&
                     (
                      (NSCCIn->NSCC_SegInfoList_LinkClass[i-1u] == MAINROAD_DIS)
                      ||
                      (NSCCIn->NSCC_SegInfoList_LinkClass[i-1u] == MAINROAD_NONDIS)
                     )
                    )
                  {
                    kLoopCond = FALSE;
                    iLoopCond = FALSE;
                  }
                  else
                  {
                    k++;
                    iLoopCond = FALSE;
                  }
                }
                else
                {
                  if(NSCCIn->NSCC_SegInfoList_Dist[i] >= NSCCIn->OSC_SpotCamInfoList_Dist[k])
                  {
                    if(
                       (
                        (NSCCIn->NSCC_SegInfoList_RoadClass[i-1u] == FREEWAY)
                        ||
                        (NSCCIn->NSCC_SegInfoList_RoadClass[i-1u] == ARTERIAL)
                       )
                       &&
                       (
                        (NSCCIn->NSCC_SegInfoList_LinkClass[i-1u] == MAINROAD_DIS)
                        ||
                        (NSCCIn->NSCC_SegInfoList_LinkClass[i-1u] == MAINROAD_NONDIS)
                       )
                      )
                    {
                      kLoopCond = FALSE;
                      iLoopCond = FALSE;
                    }
                    else
                    {
                      k++;
                      iLoopCond = FALSE;
                    }
                  }
                  else
                  {
                    // do nothing
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        kLoopCond = FALSE;
        iLoopCond = FALSE;
        OSC_NearestSpotCam_Type = POI_TYPE_NONE;
        OSC_NearestSpotCam_Spd = p_CamWarnInvalidSpd;
        OSC_NearestSpotCam_Dist = p_CamWarnInvalidDist;
        OSC_DataReady = FALSE;
        OSC_Data_set_invalid = TRUE;
      }
    }
    if(OSC_Data_set_invalid == FALSE)
    {
      OSC_NearestSpotCam_Type = NSCCIn->OSC_SpotCamInfoList_Type[k];
      OSC_NearestSpotCam_Spd = (sint16)NSCCIn->OSC_SpotCamInfoList_Spd[k]; 
      OSC_NearestSpotCam_Dist = NSCCIn->OSC_SpotCamInfoList_Dist[k]; 
      OSC_DataReady = TRUE;
    }
    else
    {
      // do nothing
    }
  }
  else
  {
    OSC_NearestSpotCam_Type = POI_TYPE_NONE;
    OSC_NearestSpotCam_Spd = p_CamWarnInvalidSpd;
    OSC_NearestSpotCam_Dist = p_CamWarnInvalidDist;
    OSC_DataReady = FALSE;
  }

  pLongCtrlCmd->Custom.LongCtrlOutputCustomHIOut.OSC_NearestSpotCam_Dist = (float32)OSC_NearestSpotCam_Dist; // Feedback to SW!

  /* 3.3.2 */
  if(OSC_DataReady == TRUE)
  {
		if(OSC_NearestSpotCam_Type == POI_TYPE_MOVING)
		{
			OSC_CamWarnCtrlDist = p_MOSC_CamWarnCtrlDist + p_FMOSC_CamWarnCtrlDist;
		}
		else if(OSC_NearestSpotCam_Type == POI_TYPE_FIXED_MOVING)
		{
			OSC_CamWarnCtrlDist = p_FMOSC_CamWarnCtrlDist;
		}
		else if(OSC_NearestSpotCam_Type == POI_TYPE_FIXED)
		{
			OSC_CamWarnCtrlDist = p_FOSC_CamWarnCtrlDist;
		}
    else
		{
			OSC_CamWarnCtrlDist = 0u;
		}
	}
	else
	{
		OSC_CamWarnCtrlDist = 0u;
	}

  /* 3.3.3 */
  OSC_CamWarnValidDistMax_Old = OSC_CamWarnValidDistMax;

	if(
     (OSC_CamValidDistMaxChgEn == TRUE) 
		 && 
		 (OSC_NearestSpotCam_Type != POI_TYPE_NONE)
    )
	{
    helpvar1 = (float32)OSC_NearestSpotCam_Spd/C_KMH_MS;
    helpvar1 = helpvar1 * helpvar1;
    helpvar2 = NSCCIn->VehSpdCluCal/C_KMH_MS;
    helpvar2 = helpvar2 * helpvar2;
    helpvar1 = helpvar1 - helpvar2;
    helpvar1 = helpvar1 / (2.0f*p_OSC_DesiredDecel);
    OSC_CamWarnValidDistMax = helpvar1 + (float32)OSC_CamWarnCtrlDist; 

		if(OSC_CamWarnValidDistMax <= (float32)p_OSC_CamWarnValidDistMaxL)
		{
			OSC_CamWarnValidDistMax = (float32)p_OSC_CamWarnValidDistMaxL;
		}
		else if(OSC_CamWarnValidDistMax <= (float32)p_OSC_CamWarnValidDistMaxH)
		{
			OSC_CamWarnValidDistMax = OSC_CamWarnValidDistMax;
		}
		else
		{
			OSC_CamWarnValidDistMax = (float32)p_OSC_CamWarnValidDistMaxH;
		}
	}
	else
	{
	  OSC_CamWarnValidDistMax = OSC_CamWarnValidDistMax_Old;
	}

  /* 3.3.4 */
  if(
     (OSC_DataReady == TRUE)
     &&
     (OSC_NearestSpotCam_Type != POI_TYPE_NONE)
     &&
     (
      (OSC_NearestSpotCam_Dist >= 0)
      &&
      ((float32)OSC_NearestSpotCam_Dist < OSC_CamWarnValidDistMax)
     )
    )
  {
    if (
        (NSCCIn->NSCC_CurRoadClass == FREEWAY)
        &&
        (OSC_NearestSpotCam_Spd >= (sint16)p_OSC_CamWarnValidSpdMinFreeway)
        &&
        (OSC_NearestSpotCam_Spd <= (sint16)p_OSC_CamWarnValidSpdMax)
       )
    {
      OSC_CurLmtSpd = OSC_NearestSpotCam_Spd;
      OSC_CurLmtSpdChgByCam = TRUE;
      OSC_CamValidDistMaxChgEn = FALSE;
    }
    else if (
             (NSCCIn->NSCC_CurRoadClass == ARTERIAL)
             &&
             (OSC_NearestSpotCam_Spd >= (sint16)p_OSC_CamWarnValidSpdMinArterial)
             &&
             (OSC_NearestSpotCam_Spd <= (sint16)p_OSC_CamWarnValidSpdMax)
            )
    {
      OSC_CurLmtSpd = OSC_NearestSpotCam_Spd;
      OSC_CurLmtSpdChgByCam = TRUE;
      OSC_CamValidDistMaxChgEn = FALSE;
    }
    else
    {
      OSC_CurLmtSpd = p_CamWarnInvalidSpd;
      OSC_CurLmtSpdChgByCam = FALSE;
      OSC_CamValidDistMaxChgEn = TRUE;
    }
  }
  else
  {
    OSC_CurLmtSpd = p_CamWarnInvalidSpd;
      OSC_CurLmtSpdChgByCam = FALSE;
      OSC_CamValidDistMaxChgEn = TRUE;
  }

  _PARAM_UNUSED(OSC_CurLmtSpdChgByCam);

  /* 3.3.5 */
  if(
     (OSC_CurLmtSpd != p_CamWarnInvalidSpd)
     &&
     ((sint16)cc_setspeed > OSC_CurLmtSpd)
    )
  {
    OSC_TargetSpd = OSC_CurLmtSpd + (sint16)p_OSC_TargetSpdOffset;
    OSC_SetSpdChg = TRUE;
  }
  else
  {
    OSC_TargetSpd = p_CamWarnInvalidSpd;
    OSC_SetSpdChg = FALSE;
  }

  OSC_TargetDistOld = OSC_TargetDist;
  OSC_TargetDist = OSC_NearestSpotCam_Dist;

  /* 3.3.6 */
  if(
     (NSCCIn->SOSC_DataReady == TRUE)
     &&
     (NSCCIn->OSC_SectCam_Valid == TRUE)
    )
  {
    SOSC_Valid = TRUE;
    SOSC_TargetSpd = (float32)NSCCIn->OSC_SectCam_Spd + (float32)p_OSC_TargetSpdOffset;
    SOSC_TargetSpd_invalid = FALSE;
    
    if(
       (NSCCIn->VehSpdCluCal > 0.0f) // > instead of != due to float type
       &&
       (NSCCIn->OSC_SectCam_AvgSpd < 0.01f) // "< 0.01f" instead of "!= 0.0f" due to float type
      )
    {
      SOSC_AvgSpd = NSCCIn->VehSpdCluCal;
    }
    else
    {
      SOSC_AvgSpd = NSCCIn->OSC_SectCam_AvgSpd;
    }

    if(
       (SOSC_TargetSpd < (SOSC_AvgSpd + CML_f_AlmostZero))  //
       &&                                                   // two small thresholds instead of "==SOSC_AvgSpd" due to float type
       (SOSC_TargetSpd > (SOSC_AvgSpd - CML_f_AlmostZero))  //
      )
    {
      SOSC_TargetSpdAvg = SOSC_TargetSpd;
    }
    else
    {
      SOSC_TargetSpdAvg = ( (SOSC_TargetSpd - SOSC_AvgSpd) * (float32)p_SOSC_AvgSpdCtrlRatio ) + (SOSC_TargetSpd - (float32)p_SOSC_AvgSpdCtrlOffset);
    }

    SOSC_CtrlMinSpd = SOSC_TargetSpd * ( (float32)p_SOSC_CtrlSpdMinRatio / 100.0f );

    if(SOSC_TargetSpdAvg < SOSC_CtrlMinSpd)
    {
      SOSC_TargetSpd = SOSC_CtrlMinSpd;
      SOSC_TargetSpd_invalid = FALSE;
    }
    else if(SOSC_TargetSpdAvg <= SOSC_TargetSpd)
    {
      SOSC_TargetSpd = SOSC_TargetSpdAvg;
      SOSC_TargetSpd_invalid = FALSE;
    }
    else
    {
      // do nothing
    }
  }
  else
  {
    SOSC_Valid = FALSE;
    SOSC_TargetSpd = (float32)p_CamWarnInvalidSpd;
    SOSC_TargetSpd_invalid = TRUE;
    SOSC_AvgSpd = (float32)p_CamWarnInvalidSpd;
  }

  /*  NaviSCC-C  */

  /* NSCC-C 5.1.1 NSCC-C_SwCondDecision */
  if (NSCCIn->NSCC_Curve_USM_In == TRUE)
  {
    NSCCIn->NSCC_C_SwCond = TRUE;
  }
  else
  {
    NSCCIn->NSCC_C_SwCond = FALSE;
  }

  /* NSCC-C 5.1.1 NSCC-C_RoadClassDecision */
  if (
      (NSCCIn->NSCC_CurRoadClass == FREEWAY)
      ||
      (NSCCIn->NSCC_CurRoadClass == ARTERIAL)
     )
  {
    NSCC_C_RoadClassCond = TRUE;
  }
  else
  {
    NSCC_C_RoadClassCond = FALSE;
  }

  /* NSCC-C 5.1.3 NSCC-C_LinkClassDecision */
  if (
      (NSCCIn->NSCC_CurLinkClass == MAINROAD_NONDIS)
      ||
      (NSCCIn->NSCC_CurLinkClass == MAINROAD_DIS)
     )
  {
    NSCC_C_LinkClassCond = TRUE;
  }
  else
  {
    NSCC_C_LinkClassCond = FALSE;
  }


  /* NSCC-C 5.2.1 CalcDistOfInterest */

  NSCC_C_TimeForDoI = p_NSCC_C_TimeForDoI;
  NSCC_C_DistOfInterestMax = (sint16)(ROUND_TO_INT(NSCCIn->VehSpdCluCal / C_KMH_MS) * (sint16)NSCC_C_TimeForDoI);

  if (NSCC_C_DistOfInterestMax < p_NSCC_C_DistOfInterestMaxL)
  {
    NSCC_C_DistOfInterestMax = p_NSCC_C_DistOfInterestMaxL;
  }
  else
  {
    // do nothing
  }
  if (NSCC_C_DistOfInterestMax > p_NSCC_C_DistOfInterestMaxH)
  {
    NSCC_C_DistOfInterestMax = p_NSCC_C_DistOfInterestMaxH;
  }
  else
  {
    // do nothing
  }

  if (NSCCIn->NSCC_PosMsgUpdate == FALSE)
  {
    NSCC_C_DistOfInterestMax = NSCC_C_DistOfInterestMaxOld;
  }
  else
  {
    NSCC_C_DistOfInterestMaxOld = NSCC_C_DistOfInterestMax;
  }

  /* NSCC-C 5.2.2 CalcTargetPntInfo */

  NSCC_C_TargetDist = p_NSCC_C_TargetDistInit;
  NSCC_C_DistOfInterestMin = p_NSCC_C_DistOfInterestMin;
  NSCC_C_TargetR = p_NSCC_C_TargetRInit;

  i = 0u;
  for (i=0u; i<NSCCIn->NDP_CurveInfoValidSize; i++)
  {
    if (
        (NSCCIn->NDP_CurveInfoListDist[i] > 0)
        &&
        (NSCCIn->NDP_CurveInfoListDist[i] <= NSCC_C_DistOfInterestMax)
        &&
        (NSCCIn->NDP_CurveInfoListDist[i] >= NSCC_C_DistOfInterestMin)
       )
    {
      if (NSCCIn->NDP_CurveInfoListR[i] < NSCC_C_TargetR)
      {
        NSCC_C_TargetR = NSCCIn->NDP_CurveInfoListR[i];
        NSCC_C_TargetDist = NSCCIn->NDP_CurveInfoListDist[i];
      }
      else if (
               (NSCCIn->NDP_CurveInfoListR[i] == NSCC_C_TargetR)
               &&
               (NSCCIn->NDP_CurveInfoListDist[i] < NSCC_C_TargetDist)
              )
      {
        NSCC_C_TargetR = NSCCIn->NDP_CurveInfoListR[i];
        NSCC_C_TargetDist = NSCCIn->NDP_CurveInfoListDist[i];
      }
      else
      {
        // do nothing (keep init values)
      }
    }
    else
    {
      // do nothing (continue loop)
    }
  }

  if (NSCC_C_TargetDist < p_NSCC_C_TargetDistInit)
  {
    NSCC_C_TargetType = p_NSCC_C_TargetType_Main;
  }
  else
  {
    NSCC_C_TargetType = p_NSCC_C_TargetType_Invalid;
  }

  /* NSCC-C 5.2.3 Calculation of Target Speed */

  if (NSCC_C_TargetR == p_NSCC_C_TargetRInit)
  {
    NSCC_C_TargetSpd = p_NSCC_C_SafeSpdMax;
  }
  else
  {
    if (NSCCIn->NDP_CurLanes == 1u)
    {
      NSCC_C_TargetSpd = MAT_CALCULATE_PARAM_VALUE1D(p_NSCC_C_TargetSpdLane1, NSCC_C_CURVE_LOOKUP_TABLE_POINTS, NSCC_C_TargetR);
    }
    else if (NSCCIn->NDP_CurLanes == 2u)
    {
      NSCC_C_TargetSpd = MAT_CALCULATE_PARAM_VALUE1D(p_NSCC_C_TargetSpdLane2, NSCC_C_CURVE_LOOKUP_TABLE_POINTS, NSCC_C_TargetR);
    }
    else if (NSCCIn->NDP_CurLanes == 3u)
    {
      NSCC_C_TargetSpd = MAT_CALCULATE_PARAM_VALUE1D(p_NSCC_C_TargetSpdLane3, NSCC_C_CURVE_LOOKUP_TABLE_POINTS, NSCC_C_TargetR);
    }
    else if (NSCCIn->NDP_CurLanes == 4u)
    {
      NSCC_C_TargetSpd = MAT_CALCULATE_PARAM_VALUE1D(p_NSCC_C_TargetSpdLane4, NSCC_C_CURVE_LOOKUP_TABLE_POINTS, NSCC_C_TargetR);
    }
    else
    {
      NSCC_C_TargetSpd = MAT_CALCULATE_PARAM_VALUE1D(p_NSCC_C_TargetSpdLane5, NSCC_C_CURVE_LOOKUP_TABLE_POINTS, NSCC_C_TargetR);
    }

    if (NSCC_C_TargetSpd < (sint16)pLongCtrlCmd->KinFctInfo.desired_speed)
    {
      NSCC_C_SetSpdChg = TRUE;
    }
    else
    {
      NSCC_C_SetSpdChg = FALSE;
    }
  }


  /***************/

  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_NearestSpotCam_Dist_MEAS = OSC_NearestSpotCam_Dist;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_NearestSpotCam_Spd_MEAS = OSC_NearestSpotCam_Spd;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.SOSC_AvgSpd_MEAS = SOSC_AvgSpd;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.SOSC_TargetSpdAvg_MEAS = SOSC_TargetSpdAvg;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_TargetDist_MEAS = OSC_TargetDist;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_TargetSpd_MEAS = OSC_TargetSpd;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.SOSC_TargetSpd_MEAS = SOSC_TargetSpd;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_CurLmtSpd_MEAS = OSC_CurLmtSpd;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.SOSC_Valid_MEAS = SOSC_Valid;
  /* NaviSCC-C */
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_SetSpdChg_MEAS = NSCC_C_SetSpdChg;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_DistOfInterestMax_MEAS = NSCC_C_DistOfInterestMax;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_DistOfInterestMaxOld_MEAS = NSCC_C_DistOfInterestMaxOld;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_TargetDist_MEAS = NSCC_C_TargetDist;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_TargetSpd_MEAS = NSCC_C_TargetSpd;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_TargetR_MEAS = NSCC_C_TargetR;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_TargetType_MEAS = NSCC_C_TargetType;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_SwCond_MEAS = NSCCIn->NSCC_C_SwCond;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_RoadClassCond_MEAS = NSCC_C_RoadClassCond;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_LinkClassCond_MEAS = NSCC_C_LinkClassCond;

}


/*************************************************************************************************************************
  Functionname:    NSCC_MODE_MANAGER                                                                                */ /*!

  @brief           NaviSCC statemachine

  @description     -

  @return          static void

  @param[in]       NSCCIn : NaviSCC input signals coming from SW
  @param[in]       ACCMode : contains information about ACC system state (off, engaged, override, shutoff) 
  @param[in]       CCOnlyActive : boolean flag indicating if SCC is in "CC only" mode

  @glob_in         OSC_RoadClassCond : road class condition for activating NaviSCC (FREEWAY or ARTERIAL) is fulfilled                           [TRUE, FALSE]
  @glob_in         OSC_LinkClassCond : link class condition for activating NaviSCC (MAINROAD_DIS or MAINROAD_NONDIS) is fulfilled               [TRUE, FALSE]
  @glob_in         OSC_DataReady : information about the nearest speed camera  is available                                                     [TRUE, FALSE]
  @glob_in         OSC_SwCond : switch input condition for activating NaviSCC is fulfilled                                                      [TRUE, FALSE]
  @glob_in         OSC_SetSpdChg :  ACC setspeed is bigger than the current relevant speed limit                                                [TRUE, FALSE]
  @glob_in         SOSC_Valid : information about the camera enforcement section is available and the vehicle is currently inside that section  [TRUE, FALSE]
  @glob_in         MOSC_IsInSection : activation flag for MOVING type speed camera                                                              [TRUE, FALSE]
  @glob_in         NSCC_C_RoadClassCond : road class condition for activating NaviSCC-C (FREEWAY or ARTERIAL) is fulfilled                      [TRUE, FALSE]
  @glob_in         NSCC_C_LinkClassCond : link class condition for activating NaviSCC-C (MAINROAD_DIS or MAINROAD_NONDIS) is fulfilled          [TRUE, FALSE]
  @glob_in         NSCC_C_TargetType : target curve type                                                                                        [full range of unsigned char]
  @glob_in         NSCC_C_SetSpdChg : setspeed condition (NSCC-C target speed < ACC setspeed)                                                   [TRUE, FALSE]  
  @glob_out        gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_Mode_MEAS : state of NaviSCC-Z state machine                                              [0...3]

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         12.09.2016
  @changed         12.09.2016

  @author          Thomas Mielke | thomas.mielke-ext@conti-engineering.com | +49 (69) 67869-6417
*************************************************************************************************************************/
static void NSCC_MODE_MANAGER(nscc_inputs_t * NSCCIn, acc_mode_t ACCMode, boolean CCOnlyActive)
{
  switch(NSCCIn->NSCC_Z_Mode)
  {
    case osc_off:
      
      if(NSCCIn->NSCC_Z_SwCond == TRUE)  
      {
        NSCCIn->NSCC_Z_Mode = osc_on;  // T1
      }
      else
      {
        // do nothing
      }

      break;

    case osc_on:

      if(NSCCIn->NSCC_Z_SwCond == FALSE) 
      {
        NSCCIn->NSCC_Z_Mode = osc_off; // T2
      }
      else if( 
              (NSCCIn->NSCC_Inhibit == FALSE)
              &&
              (NSCCIn->NSCC_RouteInvalid == FALSE)
              &&
              (OSC_RoadClassCond == TRUE)
              &&
              (OSC_LinkClassCond == TRUE)
              &&
              (NSCCIn->NSCC_DataReady == TRUE)
              &&
              (
               (ACCMode == acc_mode_engaged) 
               ||
               (ACCMode == acc_mode_override) // override case added in new NSCC-C Design Doc 
              )
              &&
              (CCOnlyActive == FALSE) // not in CC only mode
             )
      {
        NSCCIn->NSCC_Z_Mode = osc_standby; // T4
      }
      else
      {
        // do nothing
      }

      break;

    case osc_standby:

      if(NSCCIn->NSCC_Z_SwCond == FALSE)
      {
        NSCCIn->NSCC_Z_Mode = osc_off; // T3
      }
      else if(
              (NSCCIn->NSCC_Inhibit == TRUE)
              ||
              (NSCCIn->NSCC_Buffer_Reset == TRUE)
              ||
              (OSC_RoadClassCond == FALSE)
              ||
              (OSC_LinkClassCond == FALSE)
              ||
              (NSCCIn->NSCC_DataReady == FALSE)
              ||
              (
               (ACCMode != acc_mode_engaged)
               &&
               (ACCMode != acc_mode_override) // override case added in new NSCC-C Design Doc 
              )
              ||
              (CCOnlyActive == TRUE) // in CC only mode
             )
      {
        NSCCIn->NSCC_Z_Mode = osc_on;  // T5
      }
      else if(
              (
               (OSC_DataReady == TRUE)
               &&
               (OSC_SetSpdChg == TRUE)
              )
              ||
              (MOSC_IsInSection == TRUE)
              ||
              (
               (NSCCIn->SOSC_DataReady == TRUE)
               &&
               (SOSC_Valid == TRUE)
              )     
             )
      {
        NSCCIn->NSCC_Z_Mode = osc_control; // T6
      }
      else
      {
        // do nothing
      }

      break;

    case osc_control:

      if(NSCCIn->NSCC_Z_SwCond == FALSE)
      {
        NSCCIn->NSCC_Z_Mode = osc_off; // T3
      }
      else if(
              (NSCCIn->NSCC_Inhibit == TRUE)
              ||
              (NSCCIn->NSCC_Buffer_Reset == TRUE)
              ||
              (OSC_RoadClassCond == FALSE)
              ||
              (OSC_LinkClassCond == FALSE)
              ||
              (NSCCIn->NSCC_DataReady == FALSE)
              ||
              (
               (ACCMode != acc_mode_engaged)
               &&
               (ACCMode != acc_mode_override) // override case added in new NSCC-C Design Doc 
              )
              ||
              (CCOnlyActive == TRUE) // in CC only mode
             )
      {
        NSCCIn->NSCC_Z_Mode = osc_on;  // T5
      }
      else if(
              (
               (OSC_DataReady == FALSE)
               ||
               (OSC_SetSpdChg == FALSE)
              )
              &&
              (MOSC_IsInSection == FALSE)
              &&
              (
               (NSCCIn->SOSC_DataReady == FALSE)
               ||
               (SOSC_Valid == FALSE)
              )     
             )
      {
        NSCCIn->NSCC_Z_Mode = osc_standby; // T7
      }
      else
      {
        // do nothing
      }

      break;

    default:
      break;
  }



  /* NaviSCC-C */

  switch(NSCCIn->NSCC_C_Mode)
  {
    case osc_off:
      
      if(NSCCIn->NSCC_C_SwCond == TRUE)  
      {
        NSCCIn->NSCC_C_Mode = osc_on;  // T1
      }
      else
      {
        // do nothing
      }

      break;

    case osc_on:

      if(NSCCIn->NSCC_C_SwCond == FALSE) 
      {
        NSCCIn->NSCC_C_Mode = osc_off; // T2
      }
      else if( 
              (NSCCIn->NSCC_Inhibit == FALSE) 
              &&
              (NSCCIn->NSCC_RouteInvalid == FALSE) 
              &&
              (NSCC_C_RoadClassCond == TRUE) 
              &&
              (NSCC_C_LinkClassCond == TRUE) 
              &&
              (NSCCIn->NSCC_DataReady == TRUE) 
              &&
              (
               (ACCMode == acc_mode_engaged) 
               ||
               (ACCMode == acc_mode_override) // override case added in new NSCC-C Design Doc 
              )
              &&
              (CCOnlyActive == FALSE) // not in CC only mode
             )
      {
        NSCCIn->NSCC_C_Mode = osc_standby; // T4
      }
      else
      {
        // do nothing
      }

      break;

    case osc_standby:

      if(NSCCIn->NSCC_C_SwCond == FALSE)
      {
        NSCCIn->NSCC_C_Mode = osc_off; // T3
      }
      else if(
              (NSCCIn->NSCC_Inhibit == TRUE)
              ||
              (NSCCIn->NSCC_Buffer_Reset == TRUE)
              ||
              (OSC_RoadClassCond == FALSE)
              ||
              (OSC_LinkClassCond == FALSE)
              ||
              (NSCCIn->NSCC_DataReady == FALSE)
              ||
              (
               (ACCMode != acc_mode_engaged)
               &&
               (ACCMode != acc_mode_override) // override case added in new NSCC-C Design Doc 
              )
              ||
              (CCOnlyActive == TRUE) // in CC only mode
             )
      {
        NSCCIn->NSCC_C_Mode = osc_on;  // T5
      }
      else if(
              (NSCC_C_TargetType == p_NSCC_C_TargetType_Main)
              &&
              (NSCC_C_SetSpdChg == TRUE)
             )
      {
        NSCCIn->NSCC_C_Mode = osc_control; // T6
      }
      else
      {
        // do nothing
      }

      break;

    case osc_control:

      if(NSCCIn->NSCC_Z_SwCond == FALSE)
      {
        NSCCIn->NSCC_C_Mode = osc_off; // T3
      }
      else if(
              (NSCCIn->NSCC_Inhibit == TRUE)
              ||
              (NSCCIn->NSCC_Buffer_Reset == TRUE)
              ||
              (OSC_RoadClassCond == FALSE)
              ||
              (OSC_LinkClassCond == FALSE)
              ||
              (NSCCIn->NSCC_DataReady == FALSE)
              ||
              (
               (ACCMode != acc_mode_engaged)
               &&
               (ACCMode != acc_mode_override) // override case added in new NSCC-C Design Doc 
              )
              ||
              (CCOnlyActive == TRUE) // in CC only mode
             )
      {
        NSCCIn->NSCC_C_Mode = osc_on;  // T5
      }
      else if(
              (
               (NSCC_C_TargetType != p_NSCC_C_TargetType_Main)
               ||
               (NSCC_C_SetSpdChg == FALSE)
              )  
             )
      {
        NSCCIn->NSCC_C_Mode = osc_standby; // T7
      }
      else
      {
        // do nothing
      }

      break;

    default:
      break;
  }



  /*************/

  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_Mode_MEAS = NSCCIn->NSCC_Z_Mode;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_Mode_MEAS = NSCCIn->NSCC_C_Mode;
}



/*************************************************************************************************************************
  Functionname:    NSCC_CALC_ACCEL_REQ                                                                              */ /*!

  @brief           Calculation of NaviSCC acceleration request

  @description     -

  @return          static void

  @param[in]       NSCCIn : NaviSCC input signals coming from SW
  @param[in]       ACCMode : contains information about ACC system state (off, engaged, override, shutoff)
  @param[in,out]   pLongCtrlCmd : output of the longitudinal controller

  @glob_in         OSC_NearestSpotCam_Type : type of the nearest speed camera (None, Fixed, Moving, FixedMoving)                                [0...3]
  @glob_in         OSC_CamWarnCtrlDist : distance to the speed camera, where the vehicle velocity should reach the speed limit                  [full range of unsigned short]
  @glob_in         SOSC_Valid : information about the camera enforcement section is available and the vehicle is currently inside that section  [TRUE, FALSE]
  @glob_in         MOSC_IsInSection : activation flag for MOVING type speed camera                                                              [TRUE, FALSE]
  @glob_in         OSC_TargetDist : distance to nearest speed camera updated every second                                                       [full range of signed short]
  @glob_in         OSC_TargetDistOld : distance to nearest speed camera of former cycle                                                         [full range of signed short]
  @glob_in         OSC_TargetSpd : current target speed limit                                                                                   [full range of signed short]
  @glob_in         NSCCIn->NSCC_Z_Mode : state of the NaviSCC statemachine                                                                                 [0...3]
  @glob_in         SOSC_TargetSpd : current target speed limit for camera enforcement section                                                   [full range of float32]
  @glob_in         SOSC_TargetSpd_invalid : calculation of SOSC_TargetSpd wasn't successfull                                                    [TRUE, FALSE]
  @glob_in         NSCC_C_TargetDist : distance to target curve                                                                                 [full range of signed short]
  @glob_in         NSCC_C_TargetR : radius of target curve                                                                                      [full range of signed short]
  @glob_in         NSCC_C_TargetSpd : allowed speed at target curve                                                                             [full range of signed short]
  @glob_out        MOSC_IsInSection : activation flag for MOVING type speed camera                                                              [TRUE, FALSE]
  @glob_out        gNSCC_MEAS_DATA.NSCC_MEAS_DATA : struct containing NaviSCC measfreezes

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         12.09.2016
  @changed         12.09.2016

  @author          Thomas Mielke | thomas.mielke-ext@conti-engineering.com | +49 (69) 67869-6417
*************************************************************************************************************************/
static void NSCC_CALC_ACCEL_REQ(const nscc_inputs_t * NSCCIn, acc_mode_t ACCMode, LongCtrlOutput_t * pLongCtrlCmd)
{
  static float32 OSC_TargetDistComp = 0.0f;
  static float32 OSC_ReqAccel_PCtrl = 0.0f;
  static float32 OSC_ReqAccel_SCtrl = 0.0f;
  static boolean OSC_CtrlStrategyChgToPFlag = FALSE;
  static float32 FOSC_ReqAccel = 0.0f;
  static float32 MOSC_ReqAccel = 0.0f;
  static float32 SOSC_ReqAccel = 0.0f;
  static boolean FOSC_ReqAccelCond = FALSE;
  static boolean MOSC_ReqAccelCond = FALSE;
  static boolean SOSC_ReqAccelCond = FALSE;
  static float32 OSC_ReqAccel = 0.0f;
  static osc_req_accel_mode_t OSC_ReqAccelMode = osc_no_req_accel;
  static float32 OSC_ReqAccelLmt = 0.0f;
  static sint16 MOSC_TargetSpdHold = 0;
  static float32 NSCC_ReqAccel = 0.0f;
  static nscc_req_accel_mode_t NSCC_ReqAccelMode = nscc_req_accel_mode_no_act;
  static sint32 NSCC_ReqAccelOut = 0;
  boolean OSC_TargetDistComp_invalid = FALSE;
  float32 OSC_SpdEr = 0.0f;
  float32 OSC_SpdGain = 0.0f;
  float32 helpvar1 = 0.0f;
  float32 helpvar2 = 0.0f;
  static float32 MOSC_SumOfDrivingDist = 0.0f;
  float32 MOSC_SpdEr = 0.0f;
  float32 MOSC_SpdGain = 0.0f;
  float32 SOSC_SpdEr = 0.0f;
  float32 SOSC_SpdGain = 0.0f;

  /* NaviSCC-C */
  static sint16 NSCC_C_TargetDistOld = 0;
  static sint16 NSCC_C_TargetROld = 0;
  static float32 NSCC_C_TargetDistComp = 0.0f;
  float32 NSCC_C_ReqAccel = 0.0f;
  float32 NSCC_C_ReqAccelMax = 0.0f;
  float32 NSCC_C_ReqAccelMin = 0.0f;
  float32 NSCC_C_ReqAccelLmt = 0.0f; 
  /*************/

  /* 5.1.1 */
  if(OSC_TargetDist >= 0)
  {
    if(
       (NSCCIn->NSCC_PosMsgUpdate == TRUE)
       &&
       (OSC_TargetDistOld > OSC_TargetDist)
      )
    {
      OSC_TargetDistComp = (float32)OSC_TargetDist;
    }
    else
    {
      OSC_TargetDistComp = OSC_TargetDistComp - NSCCIn->DrivingDistFor1Cycle;
    }

    if(OSC_TargetDistComp >= 0.0f)
    {
      // do nothing
    }
    else
    {
      OSC_TargetDistComp = 0.0f;
    }
  }
  else
  {
    OSC_TargetDistComp = (float32)p_CamWarnInvalidDist;
    OSC_TargetDistComp_invalid = TRUE;
  }


  /* 5.1.2 */
  if(
     (OSC_TargetDistComp_invalid == FALSE)
     &&
     (OSC_TargetSpd != p_CamWarnInvalidSpd)
    )
  {
    OSC_SpdEr = (float32)OSC_TargetSpd - NSCCIn->VehSpdCluCal;

    if(OSC_SpdEr >= 0.0f)
    {
      OSC_SpdGain = p_OSC_SpdGain_Accel;
    }
    else
    {
      OSC_SpdGain = p_OSC_SpdGain_Decel;
    }


    OSC_ReqAccel_PCtrl = OSC_SpdEr * OSC_SpdGain;

    if(OSC_TargetDistComp > (float32)OSC_CamWarnCtrlDist)
    {
      helpvar1 = (float32)OSC_TargetSpd / C_KMH_MS;
      helpvar1 = helpvar1 * helpvar1;
      helpvar2 = NSCCIn->VehSpdCluCal / C_KMH_MS; 
      helpvar2 = helpvar2 * helpvar2;
      helpvar1 = helpvar1 - helpvar2;
      helpvar2 = 2.0f * (OSC_TargetDistComp - (float32)OSC_CamWarnCtrlDist);
      OSC_ReqAccel_SCtrl = helpvar1 / helpvar2;
    }
    else
    {
      OSC_ReqAccel_SCtrl = OSC_ReqAccel_PCtrl;
    }

    if(
       (OSC_TargetDistComp <= ((float32)p_CamWarnCtrlChgDist + (float32)OSC_CamWarnCtrlDist))
       ||
       (OSC_ReqAccel_PCtrl >= OSC_ReqAccel_SCtrl)
      )
    {
      OSC_CtrlStrategyChgToPFlag = TRUE;
    }
    else
    {
      OSC_CtrlStrategyChgToPFlag = FALSE;
    }
  }
  else
  {
    OSC_ReqAccel_SCtrl = p_NSCCReqAccelInit;
    OSC_ReqAccel_PCtrl = p_NSCCReqAccelInit;
    OSC_CtrlStrategyChgToPFlag = FALSE;
  }

  /* 5.1.3 */
  if(
     (p_FOSC_FnInhibit == FALSE)
     &&
     (NSCCIn->NSCC_Z_Mode == osc_control)
     &&
     (
      (OSC_TargetDistComp_invalid == FALSE)
      &&
      (OSC_TargetSpd != p_CamWarnInvalidSpd)
     )
     &&
     (
      (OSC_NearestSpotCam_Type == POI_TYPE_FIXED_MOVING)
      ||
      (OSC_NearestSpotCam_Type == POI_TYPE_FIXED)
     )
    )
  {
    FOSC_ReqAccelCond = TRUE;

    if(OSC_CtrlStrategyChgToPFlag == TRUE)
    {
      FOSC_ReqAccel = OSC_ReqAccel_PCtrl;
    }
    else
    {
      FOSC_ReqAccel = OSC_ReqAccel_SCtrl;
    }
  }
  else
  {
    FOSC_ReqAccelCond = FALSE;
    FOSC_ReqAccel = p_NSCCReqAccelInit;
  }

  /* 5.1.4 */
  if(
     (p_MOSC_FnInhibit == FALSE)
     &&
     (NSCCIn->NSCC_Z_Mode == osc_control)
    )
  {
    if(MOSC_IsInSection == TRUE)
    {
      if(
         (OSC_NearestSpotCam_Type != POI_TYPE_MOVING)
         ||
         (OSC_TargetDistComp_invalid == TRUE)
         ||
         (OSC_TargetSpd == p_CamWarnInvalidSpd)
        )
      {
        MOSC_SumOfDrivingDist = MOSC_SumOfDrivingDist + NSCCIn->DrivingDistForPosMsgUpdate;

        if(MOSC_SumOfDrivingDist <= (float32)p_OSC_TotalDistOfMosc)
        {
          MOSC_SpdEr = (float32)MOSC_TargetSpdHold - NSCCIn->VehSpdCluCal;

          if(MOSC_SpdEr >= 0.0f)
          {
            MOSC_SpdGain = p_OSC_SpdGain_Accel;
          }
          else
          {
            MOSC_SpdGain = p_OSC_SpdGain_Decel;
          }

          MOSC_ReqAccel = MOSC_SpdEr * MOSC_SpdGain;
          MOSC_ReqAccelCond = TRUE;
        }
        else
        {
          MOSC_IsInSection = FALSE;
          MOSC_SumOfDrivingDist = 0.0f;
          MOSC_ReqAccel = p_NSCCReqAccelInit;
          MOSC_ReqAccelCond = FALSE;
        }
      }
      else
      {
        if(
           (OSC_NearestSpotCam_Type == POI_TYPE_MOVING)
           &&
           (OSC_TargetDistComp_invalid == FALSE)
           &&
           (OSC_TargetSpd != p_CamWarnInvalidSpd)
          )
        {
          MOSC_IsInSection = TRUE;
          MOSC_TargetSpdHold = OSC_TargetSpd;

          if(OSC_CtrlStrategyChgToPFlag == TRUE)
          {
            MOSC_ReqAccel = OSC_ReqAccel_PCtrl;
          }
          else
          {
            MOSC_ReqAccel = OSC_ReqAccel_SCtrl;
          }

          MOSC_ReqAccelCond = TRUE;
        }
        else
        {
          MOSC_IsInSection = FALSE;
          MOSC_SumOfDrivingDist = 0.0f;
          MOSC_ReqAccel = p_NSCCReqAccelInit;
          MOSC_ReqAccelCond = FALSE;
        }
      }
    }
    else
    {
      if(
         (OSC_NearestSpotCam_Type == POI_TYPE_MOVING)
         &&
         (OSC_TargetDistComp_invalid == FALSE)
         &&
         (OSC_TargetSpd != p_CamWarnInvalidSpd)
        )
      {
        MOSC_IsInSection = TRUE;
        MOSC_TargetSpdHold = OSC_TargetSpd;

        if(OSC_CtrlStrategyChgToPFlag == TRUE)
        {
          MOSC_ReqAccel = OSC_ReqAccel_PCtrl;
        }
        else
        {
          MOSC_ReqAccel = OSC_ReqAccel_SCtrl;
        }

        MOSC_ReqAccelCond = TRUE;
      }
      else
      {
        MOSC_IsInSection = FALSE;
        MOSC_SumOfDrivingDist = 0.0f;
        MOSC_ReqAccel = p_NSCCReqAccelInit;
        MOSC_ReqAccelCond = FALSE;
      }
    }
  }
  else
  {
    MOSC_IsInSection = FALSE;
    MOSC_SumOfDrivingDist = 0.0f;
    MOSC_ReqAccel = p_NSCCReqAccelInit;
    MOSC_ReqAccelCond = FALSE;
  }

  /* 5.1.5 */
  if(
     (p_SOSC_FnInhibit == FALSE)
     &&
     (NSCCIn->NSCC_Z_Mode == osc_control)
     &&
     (SOSC_Valid == TRUE)
     &&
     (SOSC_TargetSpd_invalid == FALSE)
    )
  {
    SOSC_ReqAccelCond = TRUE;
    SOSC_SpdEr = SOSC_TargetSpd - NSCCIn->VehSpdCluCal;

    if(SOSC_SpdEr >= 0.0f)
    {
      SOSC_SpdGain = p_OSC_SpdGain_Accel;
    }
    else
    {
      SOSC_SpdGain = p_OSC_SpdGain_Decel;
    }

    SOSC_ReqAccel = SOSC_SpdEr * SOSC_SpdGain;
  }
  else
  {
    SOSC_ReqAccelCond = FALSE;
    SOSC_ReqAccel = p_NSCCReqAccelInit;
  }

  /* 5.1.6 */
  if(FOSC_ReqAccel <= SOSC_ReqAccel)
  {
    if(MOSC_ReqAccel <= FOSC_ReqAccel)
    {
      if(MOSC_ReqAccelCond == TRUE)
      {
        OSC_ReqAccel = MOSC_ReqAccel;
        OSC_ReqAccelMode = osc_mosc_req_accel;
      }
      else
      {
        OSC_ReqAccel = p_NSCCReqAccelInit;
        OSC_ReqAccelMode = osc_no_req_accel;
      }
    }
    else
    {
      if(FOSC_ReqAccelCond == TRUE)
      {
        OSC_ReqAccel = FOSC_ReqAccel;
        OSC_ReqAccelMode = osc_fosc_req_accel;
      }
      else
      {
        OSC_ReqAccel = p_NSCCReqAccelInit;
        OSC_ReqAccelMode = osc_no_req_accel;
      }
    }
  }
  else
  {
    if(MOSC_ReqAccel <= SOSC_ReqAccel)
    {
      if(MOSC_ReqAccelCond == TRUE)
      {
        OSC_ReqAccel = MOSC_ReqAccel;
        OSC_ReqAccelMode = osc_mosc_req_accel;
      }
      else
      {
        OSC_ReqAccel = p_NSCCReqAccelInit;
        OSC_ReqAccelMode = osc_no_req_accel;
      }
    }
    else
    {
      if(SOSC_ReqAccelCond == TRUE)
      {
        OSC_ReqAccel = SOSC_ReqAccel;
        OSC_ReqAccelMode = osc_sosc_req_accel;
      }
      else
      {
        OSC_ReqAccel = p_NSCCReqAccelInit;
        OSC_ReqAccelMode = osc_no_req_accel;
      }
    }
  }

  /* 5.1.7 */
  if(OSC_ReqAccelMode != osc_no_req_accel)
  {
    if(OSC_ReqAccel >= p_OSC_ReqAccelMax)
    {
      OSC_ReqAccelLmt = p_OSC_ReqAccelMax;
    }
    else
    {
      OSC_ReqAccelLmt = OSC_ReqAccel;
    }

    if(OSC_ReqAccelLmt <= p_OSC_ReqAccelMin)
    {
      OSC_ReqAccelLmt = p_OSC_ReqAccelMin;
    }
    else
    {
      // do nothing
    }
  }
  else
  {
    OSC_ReqAccelLmt = p_NSCCReqAccelInit;
  }

  /* NaviSCC-C */

  /* NaviSCC-C 5.4.1 CompNSCC-CTargetDist */

  if (
      (NSCC_C_TargetDist >= 0)
      &&
      (NSCC_C_TargetDist != p_NSCC_C_TargetDistInit)
     )
  {
    if (
        (NSCC_C_TargetDistOld != NSCC_C_TargetDist)
        ||
        (NSCC_C_TargetROld != NSCC_C_TargetR)
       )
    {
      NSCC_C_TargetDistComp = (float32)NSCC_C_TargetDist;
    }
    else
    {
      NSCC_C_TargetDistComp = NSCC_C_TargetDistComp - NSCCIn->DrivingDistFor1Cycle;
    }

    if (NSCC_C_TargetDistComp >= 0.0f)
    {
      // do nothing
    }
    else
    {
      NSCC_C_TargetDistComp = 0.0f;
    }
  }
  else
  {
    NSCC_C_TargetDistComp = (float32)p_CamWarnInvalidDist;
  }

  NSCC_C_TargetDistOld = NSCC_C_TargetDist;
  NSCC_C_TargetROld = NSCC_C_TargetR;

  /* NaviSCC-C 5.4.2 CalcNSCC-CReqAccel */

  if (NSCCIn->NSCC_C_Mode == osc_control)
  {

    NSCC_C_ReqAccel = ((((float32)NSCC_C_TargetSpd / C_KMH_MS)*((float32)NSCC_C_TargetSpd / C_KMH_MS)) - (( NSCCIn->VehSpdCluCal/C_KMH_MS ) * ( NSCCIn->VehSpdCluCal/C_KMH_MS ) )) / (2.0f*NSCC_C_TargetDistComp); 
  }
  else
  {
    NSCC_C_ReqAccel = p_NSCCReqAccelInit;
  }

  /* NaviSCC-C 5.4.3 CalcNSCC_CReqAccelLmt */

  if (NSCCIn->NSCC_C_Mode == osc_control)
  {
    NSCC_C_ReqAccelMax = p_NSCC_C_ReqAccelMax;
    NSCC_C_ReqAccelMin = p_NSCC_C_ReqAccelMin;

    if (NSCC_C_ReqAccel >= NSCC_C_ReqAccelMax)
    {
      NSCC_C_ReqAccelLmt = NSCC_C_ReqAccelMax;
    }
    else
    {
      NSCC_C_ReqAccelLmt = NSCC_C_ReqAccel;
    }

    if (NSCC_C_ReqAccelLmt <= NSCC_C_ReqAccelMin)
    {
      NSCC_C_ReqAccelLmt = NSCC_C_ReqAccelMin;
    }
    else
    {
      // do nothing (keep value)
    }
  }
  else
  {
    NSCC_C_ReqAccelLmt = NSCC_C_ReqAccel;
  }

  /* NaviSCC-C 6.1 NAP_CalcNaviReqAccel*/

  if (NSCC_C_ReqAccelLmt <= OSC_ReqAccelLmt)
  {
    NSCC_ReqAccel = NSCC_C_ReqAccelLmt;
    NSCC_ReqAccelMode = nscc_req_accel_mode_nscc_c;
  }
  else
  {
    NSCC_ReqAccel = OSC_ReqAccelLmt;
    NSCC_ReqAccelMode = nscc_req_accel_mode_nscc_z;
  }

  if (NSCC_ReqAccel >= (p_NSCCReqAccelInit - CML_f_AlmostZero)) // instead of NSCC_ReqAccel == p_NSCCReqAccelInit
  {
    NSCC_ReqAccelMode = nscc_req_accel_mode_no_act;
  }
  else
  {
    // do nothing
  }

  if (ACCMode == acc_mode_override)
  {
    NSCC_ReqAccel = 0.0f;
    NSCC_ReqAccelMode = nscc_req_accel_mode_drvovr;
  }
  else
  {
    // do nothing
  }


  /*************/

  NSCC_ReqAccelOut = ROUND_TO_INT(NSCC_ReqAccel * (float32)Scale_1000); // Caution: float2int
  pLongCtrlCmd->Custom.LongCtrlOutputCustomHIOut.NSCC_ReqAccel = NSCC_ReqAccelOut;
  pLongCtrlCmd->Custom.LongCtrlOutputCustomHIOut.NSCC_Inhibit = NSCCIn->NSCC_Inhibit;
  pLongCtrlCmd->Custom.LongCtrlOutputCustomHIOut.NSCC_ReqAccelMode = (uint8)NSCC_ReqAccelMode;

  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_TargetDistComp_MEAS = OSC_TargetDistComp;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_ReqAccel_PCtrl_MEAS = OSC_ReqAccel_PCtrl;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_ReqAccel_SCtrl_MEAS = OSC_ReqAccel_SCtrl;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_CtrlStrategyChgToPFlag_MEAS = OSC_CtrlStrategyChgToPFlag;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_SpdEr_MEAS = OSC_SpdEr;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_SpdGain_MEAS = OSC_SpdGain;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.MOSC_SpdEr_MEAS = MOSC_SpdEr;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.MOSC_SpdGain_MEAS = MOSC_SpdGain;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.SOSC_SpdEr_MEAS = SOSC_SpdEr;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.SOSC_SpdGain_MEAS = SOSC_SpdGain;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_ReqAccelMode_MEAS = OSC_ReqAccelMode;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.OSC_ReqAccel_MEAS = OSC_ReqAccel;
  /* NaviSCC-C */
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_ReqAccel_MEAS = NSCC_C_ReqAccel;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_ReqAccelLmt_MEAS = NSCC_C_ReqAccelLmt;
  gNSCC_MEAS_DATA.NSCC_MEAS_DATA.NSCC_C_TargetDistComp_MEAS = NSCC_C_TargetDistComp;

}


/*************************************************************************************************************************
  Functionname:    FCT_NSCC_MTS_CALLBACK                                                                                 */ /*!

  @brief           Callback for MEAS-freezes of static buffers

  @description     -

  @return          static void

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         26.10.2016
  @changed         26.10.2016

  @author          Thomas Mielke | thomas.mielke-ext@conti-engineering.com | +49 (69) 67869-6417
*************************************************************************************************************************/
static void FCT_NSCC_MTS_CALLBACK(void)
{
}

/*************************************************************************************************************************
  Functionname:    NSCC_EXEC                                                                                        */ /*!

  @brief           NaviSCC execution

  @description     -

  @return          void

  @param[in]       NSCCIn : NaviSCC input signals coming from SW
  @param[in]       ACCMode : contains information about ACC system state (off, engaged, override, shutoff)
  @param[in]       cc_setspeed : ACC setspeed
  @param[in]       CCOnlyActive : boolean flag indicating if SCC is in "CC only" mode
  @param[in,out]   pLongCtrlCmd : output of the longitudinal controller

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         12.09.2016
  @changed         12.09.2016

  @author          Thomas Mielke | thomas.mielke-ext@conti-engineering.com | +49 (69) 67869-6417
*************************************************************************************************************************/
void NSCC_EXEC(nscc_inputs_t * NSCCIn, acc_mode_t ACCMode, setspeed_t cc_setspeed, boolean CCOnlyActive, LongCtrlOutput_t * pLongCtrlCmd)
{
  NSCC_C_CURVE_MAP_RECONSTRUCTOR(NSCCIn);

  NSCC_DECODE_SPEED_VALUES(NSCCIn);

  NSCC_PROCESS_SIGNALS(NSCCIn, cc_setspeed, pLongCtrlCmd);

  NSCC_MODE_MANAGER(NSCCIn, ACCMode, CCOnlyActive);

  NSCC_CALC_ACCEL_REQ(NSCCIn, ACCMode, pLongCtrlCmd);

  (void)FCT_FREEZE_DATA(&MEASINFO_NSCC_DATA, &gNSCC_MEAS_DATA.MTS_DUMMY, &FCT_NSCC_MTS_CALLBACK);
}

#endif /* KMC_CFG_HI_NAVI_FEATURE */
