/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_radar.h

  DESCRIPTION:               Provide radar related mathematical functions 

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.3.1.2 $

  ---*/ /*---
  CHANGES:                   $Log: cml_radar.h  $
  CHANGES:                   Revision 1.3.1.2 2019/06/24 10:39:49CEST Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   QAF level 3 warnings have been fixed.
  CHANGES:                   Revision 1.3.1.1 2019/05/27 11:03:22CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   MFC431TA19: QAF L4 fixes added
  CHANGES:                   Revision 1.3 2018/02/26 08:52:11CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.2 2017/11/14 18:41:36CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated to the code from AL_CML_01.09.13_INT-1
  CHANGES:                   Revision 1.1 2017/08/04 23:42:20CEST Russell, Robert (russellr) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/CML_CommonMathLibrary/04_Engineering/radar/project.pj
  CHANGES:                   Revision 1.6 2017/06/06 07:38:58CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Removed unused externs
  CHANGES:                   Revision 1.5 2017/05/30 12:41:44CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Added $Log: cml_radar.h  $ to get version history
  CHANGES:                   Added Revision 1.3.1.2 2019/06/24 10:39:49CEST Kotre, Jeevan (uidk9586) (uidk9586)  to get version history
  CHANGES:                   Added QAF level 3 warnings have been fixed. to get version history
  CHANGES:                   Added Revision 1.3.1.1 2019/05/27 11:03:22CEST Thomas, Jyothy (uid22555)  to get version history
  CHANGES:                   Added MFC431TA19: QAF L4 fixes added to get version history
  CHANGES:                   Added Revision 1.3 2018/02/26 08:52:11CET Arulkumar-EXT, Nandu (uidr5428)  to get version history
  CHANGES:                   Added Updated the source code with respect to AL_CML_01.09.18_INT-1 to get version history
  CHANGES:                   Added Revision 1.2 2017/11/14 18:41:36CET Arulkumar-EXT, Nandu (uidr5428)  to get version history
  CHANGES:                   Added Updated to the code from AL_CML_01.09.13_INT-1 to get version history
  CHANGES:                   Added Revision 1.1 2017/08/04 23:42:20CEST Russell, Robert (russellr)  to get version history
  CHANGES:                   Added Initial revision to get version history
  CHANGES:                   Added Member added to project /ADAS/SW/Components/CML_CommonMathLibrary/04_Engineering/radar/project.pj to get version history
  CHANGES:                   Added Revision 1.6 2017/06/06 07:38:58CEST Thomas, Jyothy (uid22555)  to get version history
  CHANGES:                   Added Removed unused externs to get version history
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup radar RADAR (RADAR related mathematical functions)
@ingroup cml
@{ */

/*****************************************************************************
INCLUDE PROTECTION
*****************************************************************************/
#ifndef CML_RADAR_INCLUDED
#define CML_RADAR_INCLUDED      ///< To avoid multiple inclusion of the file

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef CML_EXT_INCLUDED
#pragma message(__FILE__": Inclusion of cml_radar.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef CML_EXT_INCLUDED */

/*****************************************************************************
QA-C
*****************************************************************************/
/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
/* Switch off QA-C warnings on side effects for functions, which don't have 
any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS CML_f_Sign
#endif /* #ifdef PRQA_SIZE_T */

/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
/* Switch off QA-C warnings on side effects for functions, which don't have 
any side effects and will sure never have some. */
#endif /* #ifdef PRQA_SIZE_T */

/* PRQA S 0388 6 */
/* Deactivate QAF warning 0388, Date: 2019-06-18; Reviewer: uid22555;  
   Reason: The warning says nesting level exceeds 15, but this can not be avoided here. 
   There is no risk in suppressing this warning as per our analysis. */
#include "cml_ext.h"

/*****************************************************************************
CONSTANTS
*****************************************************************************/
/* max angle for easy sine approximation */
#define CML_f_MaxAngleSinApprox_1 0.03f
#define CML_f_MaxAngleSinApprox_2 0.003f

/*****************************************************************************
TYPEDEFS
*****************************************************************************/
///< \brief       The Trajectory Reference Point Structure
///<   \description The Trajectory Reference Point Structur contains the X and Y cordinates 
///                 of the trajectory reference point, Distance to the trajectory and distance to the object
typedef struct {
    float32 f_X;           ///< Trajectory reference point X coordinate 
    float32 f_Y;           ///< Trajectory reference point Y coordinate 
    float32 f_DistToTraj;  ///< Distance to trajectory \unit m
    float32 f_DistOnTraj;  ///< Distance from vehicle center of gravity to object on trajectory \unit m
}CML_t_TrajRefPoint;

/*****************************************************************************
  FUNCTION DECLARATIONS                                             
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_v_calculateCOFEgomotionMatrices                   *//*!

  \brief           Calculate Trasformation Matrices for Egomotion Compensation 
                   of COF(Coordinate system Of vehicle Front)
                   
  \description     This function calculate Trasformation Matrices for Egomotion 
                   Compensation of COF (Coordinate system Of vehicle Front).
                   It determines the transformation type and entries of the 
                   transfromation matrices (forward and backward).\n
                   The matrices are of the format.
                   \f[ \begin{bmatrix}
                    cos(a)  &  -sin(a)  &  x \\
                    sin(a)  &   cos(a)  &  y \\
                    0    &   0    &  1   \\
                   \end{bmatrix} 
                   \f]
                   @startuml
                   (*) --> Calculate the Yaw angle, a = (Yaw Rate)/(Cycle Time)
                   --> Calculate the driven distance, D = (Corrected speed * Cycle Time) + ((Ego Acceleration * (Cycle Time)^2) /2)
                   If (a = 0)
                   note left: Check if yaw angle is zero or not
                   --> [Yes] Set the x distance values of forward and backward matrices to (-D) and D respectively 
                   note right : Transformation matrix is only translational. All values will be zero except x distance and cosine of yaw angle(= 1).
                   --> (*)
                   Else
                   --> [No] Compute the sine and cosine of yaw angle
                   --> Compute the x1 and y1 values, \n x1 = -1 * (D / a) * sin(a), y1 = -1 * (D / a) * (1-cos(a))
                   --> Compute the x ,y values of forward and backward matrices. \n xf= (x1 * cos(a)) + (y1 * sin(a)), yf = (y1 * cos(a)) - (x1 * sin(a)), \n xb = -x1, yb = -y1
                   --> Compute cos and sin values of forward and backward matrices. \n cos(af)= cos(a), sin(af) = -sin(a), \n xb = cos(a), yb = sin(a) 
                   -->(*)
                   EndIf
                   @enduml
     
  \attention      The pointers passed to this function needs to be valid.
                  Function will not verify this.

  \param[in]       f_SpeedCorrected :               The ego motion speed
                                                    Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_EgoAcceleration :              The ego acceleration
                                                    Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_YawRate_e :                    The ego yaw rate
                                                    Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_CycleTime :                    The time delta to use for calculation
                                                    Optimal values are [-F_MAX,..,F_MAX]
                                                    where F_MAX is the fourth root of max range of float32.
  \param[out]      p_TrafoMatrix2DCOFForwardRaw :   pointer to buffer for forward transformation matrix.
                                                    [Valid matrix structure pointer]
                                                    Supported values for p_TrafoMatrix2DCOFForwardRaw->TrafoType are 0,1,2.
                                                    Range for p_TrafoMatrix2DCOFForwardRaw->f00 is [0,..,1]
                                                    Range for p_TrafoMatrix2DCOFForwardRaw->f02 is [Full range of float32]
                                                    Range for p_TrafoMatrix2DCOFForwardRaw->f10 is [0,..,1]
                                                    Range for p_TrafoMatrix2DCOFForwardRaw->f12 is [Full range of float32]
  \param[out]      p_TrafoMatrix2DCOFBackwardRaw :  pointer to buffer for backward transformation matrix
                                                    [Valid matrix structure pointer]
                                                    Supported values for p_TrafoMatrix2DCOFBackwardRaw->TrafoType are 0,1,2.
                                                    Range for p_TrafoMatrix2DCOFBackwardRaw->f00 is [0,..,1]
                                                    Range for p_TrafoMatrix2DCOFBackwardRaw->f02 is [Full range of float32]
                                                    Range for p_TrafoMatrix2DCOFBackwardRaw->f10 is [0,..,1]
                                                    Range for p_TrafoMatrix2DCOFBackwardRaw->f12 is [Full range of float32]

                   
  \return          none
                   
  \author          Norman Apel
  
  \testmethod  
  \traceability    
*****************************************************************************/
extern void CML_v_calculateCOFEgomotionMatrices(CML_t_TrafoMatrix2D * p_TrafoMatrix2DCOFForwardRaw,
    CML_t_TrafoMatrix2D * p_TrafoMatrix2DCOFBackwardRaw,
    fVelocity_t   f_SpeedCorrected,
    fAccel_t      f_EgoAcceleration,
    fYawRate_t    f_YawRate_e,
    fTime_t       f_CycleTime);


/*****************************************************************************
  Functionname:    CML_v_calcCOFEgomotionMatrices                        *//*!

  \brief           Calculate Transformation Matrices for Egomotion Compensation 
                   of COF (Coordinate system Of vehicle Front)
                   
  \description     This function calculate forward and jitter transformation 
                   Matrices for Egomotion Compensation of COF 
                   (Coordinate system Of vehicle Front)
                   The matrices are of the format.
                   \f[ \begin{bmatrix}
                    cos(a)  &  -sin(a)  &  x \\
                    sin(a)  &   cos(a)  &  y \\
                    0    &   0    &  1   \\
                   \end{bmatrix} 
                   \f]
                   @startuml
                   (*) --> Calculate the Yaw angle, a = (Yaw Rate)/(Cycle Time)
                   --> Calculate the driven distance, D = (Ego speed * Cycle Time) + ((Ego Acceleration * (Cycle Time)^2) /2)
                   --> Calculate transformation matrices C1, C2 such that \n C1 = matrix with angle = 0, (x,y) = (X,0) \n C2 = matrix with angle = 0, (x,y) = (-X,0)
                   note left : (X,Y) is the Sensor mounting position.
                   --> Calculate transformation matrix R such that \n R = matrix with angle = a, (x,y) = (0,0)
                   If (a = 0)
                   --> [Yes] Define transformation matrix T with angle = 0, (x,y) = (-D,0)
                   --> Compute Forward matrix, \n F = (C2 x (R x (T x (C1 x M)))), where M is matrix with angle = 0, (x,y) = (0,0)
                   Else
                   --> [No] Define transformation matrix T with angle = 0, (x,y) = ((D/a)*sin(a),(D/a)*(1-cos(a)))
                   EndIf
                   --> Compute Forward matrix, \n F = (C2 x (R x (T x (C1 x M)))), where M is matrix with angle = 0, (x,y) = (0,0)
                   note right : Transformation matrix multiplication is applied.
                   --> Compute terms for Jitter angle calculation. \n A = (Yaw Rate + Yaw Rate for Max Jitter) and B = sqrt(Ego yaw rate variance)
                   --> Compute the jitter yaw angle. \n a1 = (A + B)*(Cycle Time) if max jitter of yaw rate is positive \n a1 = (A - B)*(Cycle Time) if otherwise
                   --> Calculate transformation matrix R1 such that \n R = matrix with angle = a1, (x,y) = (0,0)
                   If (a1 = 0)
                   --> [Yes] Define transformation matrix T1 with angle = 0, (x,y) = (-D,0)
                   --> Compute Jitter matrix, \n J = (C2 x (R1 x (T1 x (C1 x M)))), where M is matrix with angle = 0, (x,y) = (0,0)
                   Else
                   --> [No] Define transformation matrix T with angle = 0, (x,y) = ((D/a1)*sin(a1),(D/a1)*(1-cos(a1)))
                   EndIf
                   --> Compute Jitter matrix, \n J = (C2 x (R1 x (T1 x (C1 x M)))), where M is matrix with angle = 0, (x,y) = (0,0)
                   note right : Transformation matrix multiplication is applied.
                   --> (*)
                   @enduml

  \attention      The pointers passed to this function needs to be valid.
                  Function will not verify this.

  \param[in]       f_EgoSpeedXTgtSync :                The ego motion speed
                                                       Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_EgoAccelXTgtSync :                The ego acceleration
                                                       Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_YawRateTgtSync :                  The ego yaw rate
                                                       Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_YawRateVarTgtSync :               variance of the ego yaw rate
                                                       Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_YawRateMaxJitterTgtSync :         max jitter of ego yaw rate
                                                       Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_SensorXPosition :                 sensor x position
                                                       Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_CycleTime :                       sensor cycle time
                                                       Optimal values are [-F_MAX,..,F_MAX]
                                                       where F_MAX is the fourth root of max range of float32.
  \param[out]      p_TrafoMatrix2DCOFForwardTgtSync :  pointer to buffer for forward transformation matrix
                                                       [Valid matrix structure pointer]
                                                       Supported values for p_TrafoMatrix2DCOFForwardTgtSync->TrafoType are 0,1,2.
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f00 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f02 is [Full range of float32]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f10 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f12 is [Full range of float32]
  \param[out]      p_TrafoMatrix2DCOFForJitTgtSync :   pointer to buffer for jitter transformation matrix
                                                       [Valid matrix structure pointer]
                                                       Supported values for p_TrafoMatrix2DCOFForJitTgtSync->TrafoType are 0,1,2.
                                                       Range for p_TrafoMatrix2DCOFForJitTgtSync->f00 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForJitTgtSync->f02 is [Full range of float32]
                                                       Range for p_TrafoMatrix2DCOFForJitTgtSync->f10 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForJitTgtSync->f12 is [Full range of float32]
  \param[in]       f_SensorYPosition                   Not in use
                                                       Supported values are [Full range of float32]
  \param[in]       f_SlipAngleTgtSync                  Not in use
                                                       Supported values are [Full range of float32]
  \param[in]       f_SlipAngleVarTgtSync               Not in use
                                                       Supported values are [Full range of float32]

  \return          none
                   
  \author          Norman Apel

  \testmethod  
  \traceability    
*****************************************************************************/
extern void CML_v_calcCOFEgomotionMatrices(CML_t_TrafoMatrix2D * p_TrafoMatrix2DCOFForwardTgtSync,
    CML_t_TrafoMatrix2D * p_TrafoMatrix2DCOFForJitTgtSync,
    fVelocity_t f_EgoSpeedXTgtSync,
    fVelocity_t f_EgoAccelXTgtSync,
    fYawRate_t  f_YawRateTgtSync,
    fVariance_t f_YawRateVarTgtSync,
    fYawRate_t  f_YawRateMaxJitterTgtSync,
    fDistance_t f_SensorXPosition,
    fDistance_t f_SensorYPosition,
    fAngle_t    f_SlipAngleTgtSync,
    fVariance_t f_SlipAngleVarTgtSync,
    fTime_t     f_CycleTime);


/*****************************************************************************
  Functionname:    CML_v_calcForwardTrafoEgomotionMatrix                 *//*!

  \brief           Calculate Transformation Matrices for Egomotion Compensation 
                   of COF (Coordinate system Of vehicle Front) for EM_V6
                   
  \description     This function calculate forward transformation 
                   Matrix for Egomotion Compensation of COF 
                   (Coordinate system Of vehicle Front)
                   The matrix is of the format.
                   \f[ \begin{bmatrix}
                    cos(a)  &  -sin(a)  &  x \\
                    sin(a)  &   cos(a)  &  y \\
                    0    &   0    &  1   \\
                   \end{bmatrix} 
                   \f]

                   @startuml
                   (*)--> Calculate the Yaw angle, a = (Yaw Rate)/(Cycle Time)
                   --> Calculate the driven distance, D = (Ego speed * Cycle Time) + ((Ego Acceleration * (Cycle Time)^2) /2)
                   --> Calculate transformation matrices C1, C2 such that \n C1 = matrix with angle = 0, (x,y) = (X,0) \n C2 = matrix with angle = 0, (x,y) = (-X,0)
                   note left : (X,Y) is the Sensor mounting position.
                   --> Calculate transformation matrix R such that \n R = matrix with angle = a, (x,y) = (0,0)
                   If (a = 0)
                   --> [Yes] Define transformation matrix T with angle = 0, (x,y) = (-D,0)
                   --> Compute Forward matrix, \n F = (C2 x (R x (T x (C1 x M)))), where M is matrix with angle = 0, (x,y) = (0,0)
                   Else
                   --> [No] Define transformation matrix T with angle = 0, (x,y) = ((D/a)*sin(a),(D/a)*(1-cos(a)))
                   EndIf
                   --> Compute Forward matrix, \n F = (C2 x (R x (T x (C1 x M)))), where M is matrix with angle = 0, (x,y) = (0,0)
                   note right : Transformation matrix multiplication is applied.
                   -->(*)
                   @enduml

  \attention      The pointers passed to this function needs to be valid.
                  Function will not verify this.

  \param[in]       f_EgoSpeedXTgtSync :                The ego motion speed
                                                       Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_EgoAccelXTgtSync :                The ego acceleration
                                                       Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_YawRateTgtSync :                  The ego yaw rate
                                                       Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_SensorXPosition :                 sensor x position
                                                       Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_CycleTime :                       sensor cycle time
                                                       Optimal values are [-F_MAX,..,F_MAX]
                                                       where F_MAX is the fourth root of max range of float32.
  \param[out]      p_TrafoMatrix2DCOFForwardTgtSync :  pointer to buffer for forward transformation matrix
                                                       [Valid matrix structure pointer]
                                                       Supported values for p_TrafoMatrix2DCOFForwardTgtSync->TrafoType are 0,1,2.
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f00 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f02 is [Full range of float32]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f10 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f12 is [Full range of float32]
  \param[in]       f_SensorYPosition                   Not in use
                                                       Supported values are [Full range of float32]

  \return          none
                   
  \author          uidq1491

  \testmethod  
  \traceability    
*****************************************************************************/
extern void CML_v_calcForwardTrafoEgomotionMatrix(CML_t_TrafoMatrix2D * p_TrafoMatrix2DCOFForwardTgtSync,
    fVelocity_t f_EgoSpeedXTgtSync,
    fVelocity_t f_EgoAccelXTgtSync,
    fYawRate_t  f_YawRateTgtSync,
    fDistance_t f_SensorXPosition,
    fDistance_t f_SensorYPosition,
    fTime_t     f_CycleTime);

/*****************************************************************************
  Functionname:    CML_f_getPickupDist                                   *//*!

  \brief           Calculate pickup distance for distance control
  
  \description     Calculate the pickup distance for distance control with given
                   ego speed and deceleration, target speed, desired gap time and 
                   latency time. The pick up distance is calculated only when Ego 
                   deceleration is greater than the minimum acceptable value (~ >0).
                   Otherwise a value of 0 is returned.
  \InOutCorrelation
                   If PD = Pickup distance,
                      OS = Object Rel speed,
                      ES = Ego speed,
                      ED = Ego deceleration,
                      GT = Gap time
                      LT = Latency time,
                   then,
                   \f[   PD = (((ES+OS) \times ((GT-LT)-(OS/ED)))+(ES \times (LT+(\frac{OS}{ED}))))-(\frac{(OS^2)}{(2 \times ED)}) \f]


  \param[in]       f_ObjRelSpeed :      actual object rel speed
                                        Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_EgoSpeed :         actual ego speed
                                        Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_EgoDeceleration :  assuemd deceleration while distance control (larger than 0)
                                        Optimal values are [-F_MAX,..,F_MAX]
  \param[in]       f_GapTime :          desired time gap after distance control
                                        Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_LatencyTime :      assumed latency of distance control
                                        Optimal values are [-F_MAX,..,F_MAX]
                                        where F_MAX is the fourth root of max range of float32.

  @return          the pickup distance in the given situation (returns 0.f if fEgoDeceleration < CML_f_Delta)
                   
  @author          Normal Apel

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_getPickupDist(float32 f_ObjRelSpeed, float32 f_EgoSpeed, float32 f_EgoDeceleration, float32 f_GapTime, float32 f_LatencyTime); // GDBGetPickupDist

/*****************************************************************************
  Functionname:    CML_f_computeClothoidLateralDistance                  *//*!

  \brief           Compute the y-distance of a clothoid for a given x-distance
  
  \description     Compute the y-distance of a clothoid for a given x-distance.
                   The lateral distance of clothoid is calculated as follows:
  \InOutCorrelation
                   Let, A  = the heading direction or angle,
                        X  = the length,
                        Y  = lateral displacement,
                        C0 = the initial curvature,
                        C1 = curvature change,
                   then,
                     \f[  Y  = (A \times X)+(\frac{(C0 \times X^2)}{2})+(\frac{(C1 \times X^3)}{6}) \f]
                   
                     Limitation : Since the inputs and output datatypes are same, 
                     the function fails to store the results for higher values when 
                     the result exceeds the float range.

  \param[in]       f_Xpos :  distance (x-direction)
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.
  \param[in]       f_C0 :    Curvature
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.
  \param[in]       f_C1 :    Curvature change
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.
  \param[in]       f_Angle : Yaw Angle between car and road axis
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.

  \return          y-distance of a clothoid for a given x-distance
                   
  \author          Philippe Dintzer

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_computeClothoidLateralDistance (float32 f_Xpos, float32 f_C0, float32 f_C1, float32 f_Angle); // GDBRoadClothoid


/*****************************************************************************
  Functionname:    CML_v_lowPassFilter2                                  *//*!

  \brief           simple first order lowpass filter
                 
  \description     This function is an implementation of simple first order
                   lowpass filter. This determines the output sample in terms of
                   the input sample and preceding output.
  \InOutCorrelation
                   So if x = input, y = output and z = previous output, and 
                   a = filter coefficient, then,
                  \f[ y = (a \times x) + ((1-a) \times z)   \f]   
  \attention      The pointers passed to this function needs to be valid.
                  Function will not verify this.
  
  \param[in,out]   f_Old :   old value (in), filtered value (out)
                             Valid float pointer.
                             Supported value for data [Full range of float32]
  \param[in]       f_New :   new value
                             Supported value [Full range of float32]
  \param[in]       f_Alpha : filter coefficient
                             Optimal Values [0,..,1]

  \return          none
                   
  \author          Peter Seydel
  
  \testmethod  
  \traceability    
*****************************************************************************/
extern void  CML_v_lowPassFilter2(float32 * f_Old, float32 f_New, float32 f_Alpha); // GDB_Math_LowPassFilter


/************************************************************************
  Functionname:    CML_calculateDistancePoint2Circle                *//*!

  \brief           Calculates the distance from point to circle
                   (trajectory)

  \description     This function calculates various trajectory reference 
                   point parameters including the x and y cordinates,
                   distance to trajectory and distance from vehicle center 
                   of gravity to object on trajectory.                                                                         
                   @startuml
                   (*)--> Check if absolute curvature is greater than the threshold value(1/1000)
                   If (|c| > threshold)
                   -->[Yes] Compute the distance R as per equation (1)
                   If (R == 0)
                   --> [Yes] All distances are set to zero
                   -->(*)
                   Else
                   --> [No] Check the curvature sign 
                   If (c > 0)
                   --> [Yes] Compute values Nx, Ny, DTC and DOC. \n Nx = -(x/R), Ny = -(y/R) \n DTC = |(1/c)| - R , DOC = f_Radius * (atan2(y/x) + (pi/2))
                   --> Compute course distances dx and dy. \n dx= x - (Nx * DTC), dy = (y - (Ny * DTC)) + (1/c)
                   Else
                   --> [No] Compute values Nx, Ny, DTC and DOC. \n Nx = (x/R), Ny = (y/R) \n DTC = -(|(1/c)| - R) , DOC = f_Radius * (atan2(y/x) - (pi/2))
                   EndIf
                   --> Compute course distances dx and dy. \n dx= x - (Nx * DTC), dy = (y - (Ny * DTC)) + (1/c)
                   --> Final values for reference point (dx,dy,DTC,DOC)
                   Else
                   --> [No] Compute course distances, \n dx = x, dy = (x^2 * c)/2, \n DTC = y - dy, DOC = x
                   EndIf
                   --> Final values for reference point (dx,dy,DTC,DOC)
                   --> (*)
                   @enduml(
                   
                   \f[ R = \sqrt{x^2 + (y-\frac{1}{c})^2} ---------  Equation (1) \f]

  \param[in]       f_X :  X cordinate of the point
                          Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                          MAX_VAL is fourth root of maximum value of float32.
  \param[in]       f_Y :  Y cordinate of the point
                          Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                          MAX_VAL is fourth root of maximum value of float32.
  \param[in]       f_C0 : Curvature
                          Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                          MAX_VAL is fourth root of maximum value of float32.

  \return          Trajectory reference point structure

  \author          Norman Apel, Grant Davtjan

  \testmethod  
  \traceability    
**************************************************************************** */
extern CML_t_TrajRefPoint CML_calculateDistancePoint2Circle(float32 f_X, float32 f_Y, float32 f_C0);


/************************************************************************
  Functionname:    CML_calculateDistancePoint2Clothoid              *//*!

  \brief           Calculates distance from point to clothoid

  \description     This function computes and returns the parameters of 
                   the trajectory reference point structure including the 
                   x and y cordinates, distance to trajectory and distance 
                   from vehicle center of gravity to object on trajectory. 
                                                                          
  \InOutCorrelation
                   @startuml
                   (*) -->[x,y,curvatures] Compute x1 with the approximate reference point equations (1), (2) and (3)
                   note right : For approximate reference point calculations, x' = x #aqua
                   --> Compute y1 value using equation (4)
                   --> Compute the Distance to trajectory using equation (5)
                   note left: The sign of the distance is negative if y<y1
                   --> Distance on trajectory is set same as the x value
                   --> (*)
                   @enduml

                   \f[ y'  = ((C_1 * (x')^3)/6) + ((C_0 * (x')^2)/2) ----------- Equation (1) \f]
                   \f[ m   = ((C_1 * (x')^2 )/2) + (C_0 * x') ----------- Equation (2) \f]
                   If m is not qual to zero, following calculation is used , otherwise, x_1 = x
                   \f[ x_1 = ( ((y - y') + (m*x')) + (x/m) ) / ( m + (1/m) ) ----------- Equation (3) \f]
                   \f[ y_1 = \frac{C_0 \times x_1^2}{2} + (\frac{(C_1 \times x_1^3)}{6})  ----------- Equation (4) \f]
                   \f[ DTT = \sqrt{((x - x_1)^2+(y - y_1)^2)}  ----------- Equation (5) \f]

  \param[in]       f_X : X coordinate of point
                         Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                         MAX_VAL is fourth root of maximum value of float32.
  \param[in]       f_Y : Y coordinate of point
                         Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                         MAX_VAL is fourth root of maximum value of float32.
  \param[in]       f_C0 : Curvature 0
                         Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                         MAX_VAL is fourth root of maximum value of float32.
  \param[in]       f_C1 : Curvature 1
                         Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                         MAX_VAL is fourth root of maximum value of float32.

  \return          Trajectory reference point structure

  \author          Norman Apel, Grant Davtjan

  \testmethod  
  \traceability    
**************************************************************************** */
extern CML_t_TrajRefPoint CML_calculateDistancePoint2Clothoid(float32 f_X, float32 f_Y, float32 f_C0, float32 f_C1);

#endif /* #ifndef CML_RADAR_INCLUDED */

/** @} end defgroup */
