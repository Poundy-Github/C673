/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_kalman.c

DESCRIPTION:               Kalman filtering for ACC Lane Association (LA) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             24.06.2016

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if (!LA_CFG_DIST2TRAJ_EM)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup la
@{ */

/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void LA_v_KalmanPredict(LA_t_TrajDistKalmanData *pTrajDist, const GDBSymMatrix2_t * pQ, float32 fCycleTime);
static void LA_v_KalmanUpdate(const LA_t_TrajDistKalmanMeas * pMeasurement, LA_t_TrajDistKalmanData *pTrajDist);


/*************************************************************************************************************************
  Functionname:    LA_v_KalmanInit                                                                                     */ /*!

  @brief           Kalman matrices initialization (cartesian distance direction)

  @description     Kalman matrices initialization (cartesian distance direction)
                                                                          

                                X
                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------

                   Distance is a the Y coordinate of the Object in the
                   reference coordinate system on a trajectory.
                   Kalman literature & notations: 
                   [WB04] @ http://www.cs.unc.edu/~welch/kalman/
                   G. Welch, G. Bishop, An Introduction to the Kalman Filter,
                   Department of Computer Science, University of North Carolina and Chapel Hill, 2004
                   @startuml 
                   partition LA_v_KalmanInit {
                   Start
                     -Initialize X Vector,The estimation at startup is given by the initial measurement 
                     -Initialize P Matrix ,The estimation accuracy at startup is given by the measurement accuracy of the initial measurement
                   end
                   }
                   @enduml

  @return             void

  @param[in]          pMeasurement : pointer to structure containing kalman measurement for distance
                        pMeasurement->Y.f0 : Lateral distance element of Kalman model [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pMeasurement->R.f00 : Element of 1X1 Symmetrical Matrix       [full range of datatype float32]

  @param[out]         pTrajDist : pointer to trajectory distance struct
                        pTrajDist->X.f0 : Logitudinal distance element of Kalman model      [-5 * RW_FCT_MAX to +5 * RW_FCT_MAX] m
                        pTrajDist->X.f1 : Velocity element of Kalman model                  [-330.f ... +330.f] m^-1
                        pTrajDist->P.f00 : Element of 2X2 symmetric matrix                  [full range of datatype float32]
                        pTrajDist->P.f01 : Element of 2X2 symmetric matrix                  [full range of datatype float32]
                        pTrajDist->P.f11 : Element of 2X2 symmetric matrix                  [full range of datatype float32]

  @glob_in            -
  @glob_out           -

  @c_switch_part      -
  @c_switch_full      FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component

  @pre                -
  @post               -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created            
  @changed            12/8/2015

  @author             Norman Apel,  Norman.Apel@adc-gmbh.de
*************************************************************************************************************************/
void LA_v_KalmanInit(const LA_t_TrajDistKalmanMeas * pMeasurement , LA_t_TrajDistKalmanData *pTrajDist )
{
  /* Initialize X Vector */
  /* The estimation at startup is given by the initial measurement */
  pTrajDist->X.f0 = pMeasurement->Y.f0;
  pTrajDist->X.f1 = 0.0F;
  
  /* Initialize P Matrix */
  /* The estimation accuracy at startup is given by the measurement accuracy of the 
     initial measurement */
  
  pTrajDist->P.f00 = pMeasurement->R.f00;
  pTrajDist->P.f01 = 0.0F;
  pTrajDist->P.f11 = SQR(LA_MAX_VREL);  /* max expected lateral speed */
}

/*************************************************************************************************************************
  Functionname:    LA_v_KalmanPredict                                                                                  */ /*!

  @brief           Kalman prediction (time update, cartesian distance)

  @description     Kalman prediction (time update, cartesian distance) including:

                                X
                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------


                   1. project the state ahead

                      x = A * x                with x = state (distance, relative speed),
                                                    A = process model

                   2. project the error covariance ahead
                   
                      P = Q + A * P * A'       with P = error covariance,
                                                    Q = process noise covariance

                   Kalman literature & notations:
                   [WB04] @ http://www.cs.unc.edu/~welch/kalman/
                   G. Welch, G. Bishop, An Introduction to the Kalman Filter,
                   Department of Computer Science, University of North Carolina and Chapel Hill, 2004
                   @startuml 
                   partition LA_v_KalmanPredict {
                   Start
                     -project the state ahead, Kalman prediction of fDistY, fRelSpeedY: x equal to  A multiply by x
                     -project the error system model covariance matrix Q
                     -project the error covariance ahead, Kalman prediction of the error covariance matrix:  P equal to sum of Q and product of A  P and  A
                     -get pointer to P matrix
                     end
                   }
                   @enduml

  @return           void

  @param[in,out]    pTrajDist : pointer to trajectory distance structure
                      pTrajDist->X.f0 : Logitudinal distance element of Kalman model      [-5 * RW_FCT_MAX to +5 * RW_FCT_MAX] m
                      pTrajDist->X.f1 : Velocity element of Kalman model                  [-330.f ... +330.f] m^-1
                      pTrajDist->P.f00 : Element of 2X2 symmetric matrix                  [full range of datatype float32]
                      pTrajDist->P.f01 : Element of 2X2 symmetric matrix                  [full range of datatype float32]
                      pTrajDist->P.f11 : Element of 2X2 symmetric matrix                  [full range of datatype float32]

  @param[in]        pQ : pointer to a structure representing 2x2 symmetric matrix
                      pQ->f00 : Element of 2X2 symmetric matrix      [full range of datatype float32]
                      pQ->f01 : Element of 2X2 symmetric matrix      [full range of datatype float32]
                      pQ->f11 : Element of 2X2 symmetric matrix      [full range of datatype float32]


  @param[in]        fCycleTime : Cycle time since last cycle         [0.f ... 1.f] s

  @glob_in          -
  @glob_out         -

  @c_switch_part    -
  @c_switch_full    FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component

  @pre              -
  @post             -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created          
  @changed          12/8/2015

  @author           Norman Apel, norman.apel@contiautomotive.com
*************************************************************************************************************************/
static void LA_v_KalmanPredict(LA_t_TrajDistKalmanData *pTrajDist, const GDBSymMatrix2_t * pQ, float32 fCycleTime)
{
  /*--- (SYMBOLIC) CONSTANTS ---*/
  
  /*--- VARIABLES ---*/
  
  float32 fTemp;  
  GDBSymMatrix2_t* pP;
  
  /*
  
    1. project the state ahead, Kalman prediction of fDistY, fRelSpeedY:  x = A * x
    
          | fDist     |        | 1  T |
      x = | fSpeed    |,   A = | 0  1 |,   T = fCycleTime
      
                    | fDistY  +  t*fRelSpeedY |
        x = A * x = |              fRelSpeedY |
        
  */
  pTrajDist->X.f0  += fCycleTime * pTrajDist->X.f1;
  
  /*
  2. project the error system model covariance matrix Q'
  
        | Q00  Q01 |
    Q = | Q01  Q11 |   !! This matrix is symmetric !!
  */
  
  
  /*
  3. project the error covariance ahead, Kalman prediction of the error covariance matrix:  P = Q + A * P * A'
  
        | P00  P01 |
    P = | P01  P11 | ! This matrix is symmetric !
    
      
                     | P00+t*P01+(P01+t*P11)*t   P01+t*P11 |
        A * P * A' = |               P01+t*P11         P11 |
  */
  
  /* get pointer to P matrix */
  pP = &(pTrajDist->P);
  
  /* P = Q + A * P * A' */
  /* temp variable for run time optimization */
  fTemp = CML_f_MultAdd(fCycleTime, pP->f11, pP->f01);

  pP->f00 += ( CML_f_MultAdd(fCycleTime, (pP->f01 + fTemp), pQ->f00) );
  pP->f01 =  pQ->f01 + fTemp;
  pP->f11 += pQ->f11;
  
  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/*************************************************************************************************************************
  Functionname:    LA_v_KalmanUpdate                                                                                   */ /*!

  @brief           Kalman filtering (measurement update / correction, distance direction)

  @description     Kalman filtering (measurement update / correction, distance direction) including:

                                  X
                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------

                   1. compute the Kalman gain
                   
                      K = P * H' / ( H * P * H' + R )   with K = Kalman gain,
                                                             P = error covariance,
                                                             H = state to measurement relation,
                                                             R = measurement noise covariance

                   2. update estimate with measurement
                      
                      x = x + K * ( z - H * x )         with x = state (distance, relative speed),
                                                             z = measurement (distance)

                   3. update the error covariance

                      P = ( I - K * H ) * P             with I = identity matrix

                   Kalman literature & notations: 
                   [WB04] @ http://www.cs.unc.edu/~welch/kalman/
                   G. Welch, G. Bishop, An Introduction to the Kalman Filter,
                   Department of Computer Science, University of North Carolina and Chapel Hill, 2004
                   @startuml 
                   partition LA_v_KalmanUpdate {
                   Start
                     -get pointer to P matrix
                     -Compute the measurement error matrix R,This error is computed assuming independent range and azimuth errors of the measurement
                     -compute the Kalman gain: K = P * H' / ( H * P * H' + R )
                     -update estimate with measurement, Kalman filtering of fDistY, fRelSpeedY: x = x + K * ( z - H * x )  
                     -compute innovation
                     -update the error covariance: P = ( I - K * H ) * P
                   end
                   }
                   @enduml

  @return          void

  @param[in]       pMeasurement : pointer to structure containing kalman measurement for distance
                     pMeasurement->Y.f0 : Lateral distance element of Kalman model [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     pMeasurement->R.f00 : Element of 2X2 Symmetric Matrix         [full range of datatype float32]

  @param[in,out]   *pTrajDist : pointer to trajectory distance calculated
                     pTrajDist->X.f0 : Logitudinal distance element of Kalman model[-5 * RW_FCT_MAX to +5 * RW_FCT_MAX] m
                     pTrajDist->X.f1 : Velocity element of Kalman model            [-330.f ... +330.f] m^-1
                     pTrajDist->P.f00 : Element of 2X2 symmetric matrix            [full range of datatype float32]
                     pTrajDist->P.f01 : Element of 2X2 symmetric matrix            [full range of datatype float32]
                     pTrajDist->P.f11 : Element of 2X2 symmetric matrix            [full range of datatype float32]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         
  @changed         12/10/2015

  @author          Norman Apel, norman.apel@contiautomotive.com
*************************************************************************************************************************/
static void LA_v_KalmanUpdate(const LA_t_TrajDistKalmanMeas * pMeasurement, LA_t_TrajDistKalmanData *pTrajDist)
{
  /*--- (SYMBOLIC) CONSTANTS ---*/

  /*--- VARIABLES ---*/
  float32 fTemp;
  float32 fK00, fK10;
  GDBSymMatrix2_t* pP;
  const GDBSymMatrix1_t* pR;

  /* get pointer to P matrix */
  pP = &(pTrajDist->P);

  /*
    1. Compute the measurement error matrix R
       This error is computed assuming independent range and azimuth errors of the measurement 
          R = | R00 |
  */  
  pR = &(pMeasurement->R);

  /*
    2. compute the Kalman gain: K = P * H' / ( H * P * H' + R )

            | P00  P01 |                      | K00 |
        P = | P01  P11 |, ! Symmetric !   K = | K10 |,   H = | 1  0 |,   R = | R00 |

                                      | 1/(P00+R00)*P00 |
        P * H' / ( H * P * H' + R ) = | 1/(P00+R00)*P01 |
  */

  fTemp = pP->f00 +  pR->f00;

  fK00 = pP->f00 / fTemp;
  fK10 = pP->f01 / fTemp;

  /* 
    3. update estimate with measurement, Kalman filtering of fDistY, fRelSpeedY: x = x + K * ( z - H * x )

                            | K00*(z1-x11) |
        K * ( z - H * x ) = | K10*(z1-x11) |
  */

  /* compute innovation */
  fTemp = pMeasurement->Y.f0 - pTrajDist->X.f0;

  /* estimation */
  pTrajDist->X.f0 += ( fK00 * fTemp );
  pTrajDist->X.f1 += ( fK10 * fTemp );

  /*
    4. update the error covariance: P = ( I - K * H ) * P

            | P00  P01 |       | 1  0 |        | K00 |
        P = | P01  P11 |, ! Symmetric !   I = | 0  1 |,   K = | K10 |,   H = | 1  0 |

                            |  (1-K00)*P00   (1-K00)*P01 |
        ( I - K * H ) * P = | -K10*P00+P01  -K10*P01+P11 |
  */

  fTemp = 1.0F - fK00;

  pP->f11 -= (fK10 * pP->f01);
  pP->f00 *= fTemp;
  pP->f01 *= fTemp;

  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}

/*************************************************************************************************************************
  Functionname:    LA_v_KalmanFiltering                                                                                */ /*!

  @brief           Kalman filtering (measurement update / correction)

  @description     Kalman filtering (measurement update / correction)

                                X

                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------

                   Kalman literature & notations: 
                   [WB04] @ http://www.cs.unc.edu/~welch/kalman/
                   G. Welch, G. Bishop, An Introduction to the Kalman Filter,
                   Department of Computer Science, University of North Carolina and Chapel Hill, 2004
                   @startuml 
                   partition LA_v_KalmanFiltering {
                   Start
                      if(object is new) then (yes)
                       -initialize filter in the first cycle after OT lifetime is 1 in first cycle
                      else
                       -calculate KALMAN prediction
                   	-compute system noise covariance for handling target maneuvers
                      endif	
                   end
                   }
                   @enduml

  @return          void

  @param[in]       iObj : Object ID Number                                                              [ObjNumber_t datatype as in Rte_Type.h]
  @param[in]       pMeasurement : pointer to structure containing kalman measurement for distance
  @param[in]       pQ : pointer to a structure representing 2x2 symmetric matrix
  @param[in]       fCycleTime : Time since last cycle                                                   [0.f ... 1.f] s
  @param[in,out]   *pTrajDist : pointer to trajectory distance calculated

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to enable/disable CP sub-component

  @pre             None 
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/10/2015

  @author          Norman Apel, norman.apel@contiautomotive.com
*************************************************************************************************************************/
void LA_v_KalmanFiltering(ObjNumber_t iObj, const LA_t_TrajDistKalmanMeas * pMeasurement, const GDBSymMatrix2_t * pQ ,float32 fCycleTime , LA_t_TrajDistKalmanData *pTrajDist)
{
  /*--- (SYMBOLIC) CONSTANTS ---*/

  /*--- VARIABLES ---*/
 
    /* initialization and filtering */
    if ( SLATE_b_GetObjIsNew(iObj) )
    {
      /* initialize filter in the first cycle (after OT lifetime is 1 in first cycle) */
      LA_v_KalmanInit  ( pMeasurement, pTrajDist );
    }
    else
    {
      /* calc KALMAN prediction */
      LA_v_KalmanPredict   ( pTrajDist , pQ , fCycleTime);

      /* compute system noise covariance for handling target maneuvers */
      /* SADistanceKalmanSysNoise(iObj); */
      /* distance  filtering */
      LA_v_KalmanUpdate( pMeasurement, pTrajDist );
    }
  /*--- UNDEF SYMBOLIC CONSTANTS ---*/
}
///@}
#endif /*LA_CFG_DIST2TRAJ_EM*/
#endif /*!< FCT_CFG_ACC_LANE_ASSOCIATION */
