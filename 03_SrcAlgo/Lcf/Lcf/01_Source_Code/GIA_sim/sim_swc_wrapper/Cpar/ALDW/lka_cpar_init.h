/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LKA

  MODULNAME:                 lka_cpar_init.h

  DESCRIPTION:               Initializer code for CodingParameters (CPar)

  AUTHOR:                    Claudiu Sav

  CREATION DATE:             2013-04-11

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: lka_cpar_init.h  $
  CHANGES:                   Revision 1.1 2021/12/13 17:23:45CET Wang, David (Wangd3) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Cpar/ALDW/project.pj
  CHANGES:                   Revision 1.0 2017/03/03 10:35:10CET Sorge, Sven (uidg3181) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Cpar/ALDW/project.pj
  CHANGES:                   Revision 1.7 2013/12/13 12:17:32CET Sav, Claudiu (uid95402) 
  CHANGES:                   Fixed RTE issues, for SRLCam4T0.
  CHANGES:                   - Added comments -  uid95402 [Dec 13, 2013 12:17:32 PM CET]
  CHANGES:                   Change Package : 201806:3 http://mks-psad:7002/im/viewissue?selection=201806
  CHANGES:                   Revision 1.6 2013/12/03 12:45:05CET Sav, Claudiu (uid95402) 
  CHANGES:                   Update of SRLCam4T0 to R2.0
  CHANGES:                   --- Added comments ---  uid95402 [Dec 3, 2013 12:45:05 PM CET]
  CHANGES:                   Change Package : 208592:1 http://mks-psad:7002/im/viewissue?selection=208592
  CHANGES:                   Revision 1.5 2013/10/02 11:36:11CEST Sav, Claudiu (uid95402) 
  CHANGES:                   Updated CPAR to new ALDW_Parameters type.
  CHANGES:                   --- Added comments ---  uid95402 [Oct 2, 2013 11:36:11 AM CEST]
  CHANGES:                   Change Package : 191863:2 http://mks-psad:7002/im/viewissue?selection=191863
  CHANGES:                   Revision 1.4 2013/09/23 11:27:20CEST Sav, Claudiu (uid95402) 
  CHANGES:                   Implementation of Toyota SRLCam req.
  CHANGES:                   --- Added comments ---  uid95402 [Sep 23, 2013 11:27:21 AM CEST]
  CHANGES:                   Change Package : 191863:5 http://mks-psad:7002/im/viewissue?selection=191863
  CHANGES:                   Revision 1.3 2013/09/20 17:48:39CEST Sav, Claudiu (uid95402) 
  CHANGES:                   LKA update for SRLCam Toyota.
  CHANGES:                   --- Added comments ---  uid95402 [Sep 20, 2013 5:48:40 PM CEST]
  CHANGES:                   Change Package : 191863:5 http://mks-psad:7002/im/viewissue?selection=191863
  CHANGES:                   Revision 1.2 2013/08/22 14:54:30CEST Sav, Claudiu (uid95402) 
  CHANGES:                   Changed init function name.
  CHANGES:                   --- Added comments ---  uid95402 [Aug 22, 2013 2:54:30 PM CEST]
  CHANGES:                   Change Package : 191863:2 http://mks-psad:7002/im/viewissue?selection=191863
  CHANGES:                   Revision 1.1 2013/08/05 12:18:12CEST Sav, Claudiu (uid95402) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/lka/project.pj


**************************************************************************** */

#ifndef lka_cpar_init_h
#define lka_cpar_init_h

int CParInitLka(CPAR_ALDW_Parameters_t * pCoding)
{
  pCoding->ALDW_Parameters.LKA_V_LKA_EXCEED_KMH = 270.0f;   /* [km/h] */
  pCoding->ALDW_Parameters.LKA_V_LKA_EXCEED_MPH = 160.0f;   /* [mph]  */
  pCoding->ALDW_Parameters.LKA_V_LKA_ACTIVE_KMH = 50.0f;    /* [km/h] */
  pCoding->ALDW_Parameters.LKA_V_LKA_ACTIVE_MPH = 31.0f;    /* [mph]  */
  pCoding->ALDW_Parameters.LKA_V_LKA_INACTIVE_KMH = 45.0f;  /* [km/h] */
  pCoding->ALDW_Parameters.LKA_V_LKA_INACTIVE_MPH = 28.0f;  /* [mph]  */
  pCoding->ALDW_Parameters.LKA_MIN_LANE_WIDTH = 2.5f;   /* [m] */
  pCoding->ALDW_Parameters.LKA_MAX_LANE_WIDTH = 6.0f;   /* [m] */
  pCoding->ALDW_Parameters.LKA_LANE_WIDTH_DEFAULT = 3.5f;  /* [m] */
  pCoding->ALDW_Parameters.LKA_PRED_QUAL_ACTIVE   = 70.0f;  /* [%] */
  pCoding->ALDW_Parameters.LKA_PRED_QUAL_INACTIVE = 60.0f;  /* [%] */

  pCoding->ALDW_Parameters.LKA_T_MIN_ALERT  = 0.9f; /* [s] */
  pCoding->ALDW_Parameters.LKA_T_MAX_ALERT  = 2.0f; /* [s] */
  pCoding->ALDW_Parameters.LKA_T_SUPP_ALERT = 2.0f; /* [s] */

  pCoding->ALDW_Parameters.LKA_ALERT_TIME_HYSTERESIS = 0.8f; /* [s] */

  pCoding->ALDW_Parameters.LKA_TIME_WARN_DASHED     = 0.150f; /* [s] */
  pCoding->ALDW_Parameters.LKA_TIME_WARN_CONTINUOUS = 0.500f; /* [s] */

  pCoding->ALDW_Parameters.LKA_TLC_CURVE_DASHED[0] = 1.0f;    /* x0 [m/s] */
  pCoding->ALDW_Parameters.LKA_TLC_CURVE_DASHED[1] = 0.0f;    /* y0 [s] */
  pCoding->ALDW_Parameters.LKA_TLC_CURVE_DASHED[2] = 1.25f;   /* x1 [m/s] */
  pCoding->ALDW_Parameters.LKA_TLC_CURVE_DASHED[3] = -0.2f;   /* y1 [m] */
  
  pCoding->ALDW_Parameters.LKA_TLC_CURVE_CONTINUOUS[0] = 0.53f;   /* x0 [m/s] */
  pCoding->ALDW_Parameters.LKA_TLC_CURVE_CONTINUOUS[1] = 0.3f;    /* y0 [m] */
  pCoding->ALDW_Parameters.LKA_TLC_CURVE_CONTINUOUS[2] = 1.0f;    /* x1 [m/s] */
  pCoding->ALDW_Parameters.LKA_TLC_CURVE_CONTINUOUS[3] = 0.0f;    /* y1 [m] */

  pCoding->ALDW_Parameters.LKA_DLM_THRES_CURVE_INSIDE[0] = 200.0f; /* x0 [m] radius */
  pCoding->ALDW_Parameters.LKA_DLM_THRES_CURVE_INSIDE[1] = 0.15f;  /* y0 [m]    */
  pCoding->ALDW_Parameters.LKA_DLM_THRES_CURVE_INSIDE[2] = 500.0f; /* x1 [m] radius */
  pCoding->ALDW_Parameters.LKA_DLM_THRES_CURVE_INSIDE[3] = 0.0f;   /* y1 [m]    */

  pCoding->ALDW_Parameters.LKA_DLM_THRES_CURVE_OUTSIDE[0] = 0.0f;   /* x0 [m] radius */
  pCoding->ALDW_Parameters.LKA_DLM_THRES_CURVE_OUTSIDE[1] = 0.0f;   /* y0 [m]    */
  pCoding->ALDW_Parameters.LKA_DLM_THRES_CURVE_OUTSIDE[2] = 0.0f;   /* x1 [m] radius */
  pCoding->ALDW_Parameters.LKA_DLM_THRES_CURVE_OUTSIDE[3] = 0.0f;  /* y1 [m]    */

  pCoding->ALDW_Parameters.LKA_T_CURVATURE_AHEAD = 0.0f; /* [s] */

  pCoding->ALDW_Parameters.LKA_LATERAL_DEVIATION[0] = 0.3f;   /* x0 [m] */
  pCoding->ALDW_Parameters.LKA_LATERAL_DEVIATION[1] = 0.0f;   /* y0 [m] */
  pCoding->ALDW_Parameters.LKA_LATERAL_DEVIATION[2] = 0.6f;   /* x1 [m] */
  pCoding->ALDW_Parameters.LKA_LATERAL_DEVIATION[3] = 0.3f;   /* y1 [m] */
  
  pCoding->ALDW_Parameters.LKA_LANE_WIDENING_CURVE[0] = 0.9f;   /* x0 [m] */
  pCoding->ALDW_Parameters.LKA_LANE_WIDENING_CURVE[1] = 0.3f;   /* y0 [m] */
  pCoding->ALDW_Parameters.LKA_LANE_WIDENING_CURVE[2] = 1.0f;   /* x1 [m] */
  pCoding->ALDW_Parameters.LKA_LANE_WIDENING_CURVE[3] = 0.0f;   /* y1 [m] */

  pCoding->ALDW_Parameters.LKA_ACTIVITY_THRESHOLD         = 70.0f;  /* [%] */
  pCoding->ALDW_Parameters.LKA_LANECHANGE_THRESHOLD       = 50.0f;  /* [%] */
  pCoding->ALDW_Parameters.LKA_LIGHT_ACTIVITY_THRESHOLD   = 90.0f;  /* [%] */
  pCoding->ALDW_Parameters.LKA_LIGHT_LANECHANGE_THRESHOLD = 70.0f;  /* [%] */

  pCoding->ALDW_Parameters.LKA_SUPRESS_ACTIVITY_TIME = 3.0f;   /* [s] */
  pCoding->ALDW_Parameters.LKA_SUPRESS_ACTIVITY_TIME_CURVE[0] = 70.0f;  /* x0 [%] */
  pCoding->ALDW_Parameters.LKA_SUPRESS_ACTIVITY_TIME_CURVE[1] = 2.0f;   /* y0 [s] */
  pCoding->ALDW_Parameters.LKA_SUPRESS_ACTIVITY_TIME_CURVE[2] = 100.0f; /* x1 [%] */
  pCoding->ALDW_Parameters.LKA_SUPRESS_ACTIVITY_TIME_CURVE[3] = 5.0f;   /* y1 [s] */
  
  pCoding->ALDW_Parameters.LKA_SUPRESS_LANE_CHANGE_TIME = 1.0f;   /* [s] */

  /* removed due to RTE interface problem */
  /* pCoding->ALDW_Parameters.LKA_CHASSIS_CONTROL_EVENT_TIME = 2.0f;  /* [s] */
  /* pCoding->ALDW_Parameters.LKA_MAX_TURNLIGHT_TIME = 60.0f;  /* [s] */
  /* pCoding->ALDW_Parameters.LKA_TURNLIGHT_EXTEND_TIME = 10.0f;  /* [s] */

  /* pCoding->ALDW_Parameters.LKA_RESET_DIST   = 0.0f; /* [m] */
  
  /* pCoding->ALDW_Parameters.LKA_CUSTOM_DISPLACEM_CURVE[0] = 3.5f;  /* x0 [m] */
  /* pCoding->ALDW_Parameters.LKA_CUSTOM_DISPLACEM_CURVE[1] = 0.0f;  /* y0 [m] */
  /* pCoding->ALDW_Parameters.LKA_CUSTOM_DISPLACEM_CURVE[2] = 3.8f;  /* x1 [m] */
  /* pCoding->ALDW_Parameters.LKA_CUSTOM_DISPLACEM_CURVE[3] = -0.1f; /* y1 [m] */

  return 0;
}

#endif