/*********************************************************************

PROJECT:        TJA Base Development

MODULE:         Trajectory Planning

Type:           C-Source

CPU:            All

DESCRIPTION:    S-Function TrajCalc_CalcOptTrajectory

AUTHOR:         JiYa, JaAl

********************************************************************************

<HISTORY>
#<version>  <modify-date>   <owner>     <comment>
            30.04.2013      JiYa        Neuerstellung
            30.10.2014      JiYa        Misra-Fehler beheben/Argumentieren, DOORS-ID einfuegen
            13.11.2015      JaAl        Removed Dependency on BMW tmwtypes.h
            23.11.2015      DoFr        Translation German->English
<NEW>
</NEW>
</HISTORY>

*********************************************************************/

#ifndef CALOPTTRAJEKTORIE_H
#define CALOPTTRAJEKTORIE_H

/* -----------------------------------------------------------------------------

    I N C L U D E S

 * -----------------------------------------------------------------------------
*/

#include "calOptTrajektorie_TypeDef.h"

/* -----------------------------------------------------------------------------

    D E C L A R A T I O N   F U N C T I O N S

 * -----------------------------------------------------------------------------
*/

/* -----------------------------------------------------------------------------
    \brief Calculate optimal trajectory.
    
    \param Inputs Trajectory planning inputs
    
    \return Calculated trajectory
 * -----------------------------------------------------------------------------
*/
calOptOutTypeV4 TrajCalc_CalcOptTrajectory(const calOptInTypeV3* Inputs);

/* -----------------------------------------------------------------------------
    \brief Calculate max. acceleration along trajectory.
    
    \param p2 Trajectory parameter
    \param p3 Trajectory parameter
    \param p4 Trajectory parameter
    \param p5 Trajectory parameter
    \param Kr 
    \param Vx Vehicle long. velocity
    
    \return Max. acceleration (Ax
    
    \DOORS 3405
 * -----------------------------------------------------------------------------
*/
float32 TrajCalc_CalcMaxTrajAccel(const float32 p2, const float32 p3, const float32 p4, const float32 p5, const float32 t, const float32 Kr, const float32 Vx);

/* -----------------------------------------------------------------------------
    \brief Initialize output structure.
    
    \param Outputs Output structure
    
    \return -
 * -----------------------------------------------------------------------------
*/
void TrajCalc_InitializeOutputs(calOptOutTypeV4* Outputs);

/* -----------------------------------------------------------------------------
    \brief Calculation of matrix Ax and vector Bx
    
    \param 
    
    \return -
    
    \DOORS 3390
 * -----------------------------------------------------------------------------
*/
void TrajCalc_CalcAxBx( float32 A[3][3], float32 B[3], const float32 Param[6], const float32 t, float32 const d, float32 const d_dot, float32 const d_ddot);

/* -----------------------------------------------------------------------------
    \brief Calculate parameters p3, p4, p5
    
    \param 
    
    \return 
    
    \DOORS 3390
    \DOORS 3388
 * -----------------------------------------------------------------------------
*/
boolean_T TrajCalc_CalcParameters(float32 Param[6], float32 A[][3], const float32 B[3]);

/* -----------------------------------------------------------------------------
    \brief Calculate cost function
    
    \param Param
    \param t
    \param Kd
    \param Kt
    \param d
    \param d_k
    
    \return Calculated cost
    
    \DOORS 2920
    \DOORS 3391
 * -----------------------------------------------------------------------------
*/
float32 TrajCalc_CalcCostFunction(const float32 Param[6], const float32 t, const float32 Kd, const float32 Kt, const float32 d, const float32 d_k);

/* -----------------------------------------------------------------------------
    \brief Check tire potential vector.
    
    \param 
    
    \return 
    
    \DOORS 5931
 * -----------------------------------------------------------------------------
*/
boolean_T TrajCalc_CheckPotVector(const float32 Param_akt[6], float32* AMax, const float32 Kr, const float32 te, const float32 VehVelX, const float32 FTireAclMin ,const float32 FTireAclMax,  const boolean_T PlanArcLength, boolean_T* FTireAclMinOk, boolean_T* FTireAclMaxOk);

/* Jerk Calculation*/
float32 TrajCalc_CalcTrajJerk(const float32 p3, const float32 p4, const float32 p5, const float32 t, const float32 CrvChng, const float32 Vx);

/* Jerk Check*/
boolean_T TrajCalc_CheckJerk(const float32 curParam[6], float32* JerkMax, const float32 CrvChng, const float32 te, const float32 VehVelX, const float32 AllwdJerkMax, const boolean_T PlanArcLength);

/* -----------------------------------------------------------------------------
    \brief Calculate optimal trajectory (internal)
    
    \param 
    
    \return 
    
    \DOORS 2918
    \DOORS 5932
 * -----------------------------------------------------------------------------
*/
void TrajCalc_CalcOptTrajectoryInt(const float32 dz_new, const float32 dz_dot, const float32 dz_ddot, const float32 te, boolean_T* NewBestPoint, const float32 d_AW, const float32 d_AWdot, const float32 d_AWddot, const float32 Kd, const float32 Kt, const float32 dz_original, const boolean_T CheckFTire, const float32 Kr, const float32 VehVelX, const float32 FTireAclMin, const float32 FTireAclMax, const boolean_T PlanArcLength, calOptOutTypeV4* Outputs, const float32 PH_VisLength, const float32 PH_Traj, const boolean_T CheckCollCridr, const boolean_T CheckCollObj, const calOptInTypeV3* Inputs, const float32 CrvChng, const float32 AllwdJerkMax, const boolean_T CheckJerk, const boolean_T CheckLaneCross);

/* -----------------------------------------------------------------------------
    \brief Check for collision of trajectory with available corridor
    
    \param 
    
    \return 
    
    \DOORS 5945
    \DOORS 10496
 * -----------------------------------------------------------------------------
*/
boolean_T TrajCalc_CheckCollisionCorridor( const boolean_T PlanArcLength, const float32 PH_Traj, const float32 PH_VisLength, const float32 CurTgtPoint, const uint8 EndIndexLeftCridr, float32 CircleRadius, const float32 Param[6], const float32 LeftDistY[100], boolean_T* CollCheckRightOk, boolean_T* CollCheckLeftOk);

/* -----------------------------------------------------------------------------
    \brief Check for collision of trajectory with obstacle
    
    \param 
    
    \return 
    
    \DOORS 5945
    \DOORS 10497
 * -----------------------------------------------------------------------------
*/
boolean_T TrajCalc_CheckCollisionObject(const float32 t_DeadTime, const float32 v_Traj, const float32 a_Traj, const float32 v_Obj, const float32 a_Obj, const float32 ObstDistX, const float32 ObstDistY, const float32 HindernisWidth, const float32 CircleRadius, const float32 VisLength, const float32 TgtPoint, const float32 P[6]);

boolean_T TrajCalc_CheckLaneCross(const float32 PH_VisLength, const float32 CurTgtPoint, const float32 VehicleWidth, const float32 Param[6], const float32 AllowedTimetoCross, const float32 LaneWidth);

/* -----------------------------------------------------------------------------

    H E L P E R   F U N C T I O N S

 * -----------------------------------------------------------------------------
*/

float32 TrajCalc_MinFloat(const float32 A, const float32 B);

#endif	/* CALOPTTRAJEKTORIE_H */
