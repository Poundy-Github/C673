/*********************************************************************

PROJECT:        TJA Base Development

MODULE:         Frenet Transformation

Type:           C-Header

CPU:            All

DESCRIPTION:    S-Function calFrenetTransformation

AUTHOR:         JiYa, JaAl

********************************************************************************

<HISTORY>
#<version>  <modify-date>   <owner>     <comment>
            28.03.2013      JiYa        Neuerstellung
            28.10.2014      JiYa        Misra-Fehler beheben/Argumentieren, DOORS-ID einfuegen
            24.11.2015      DoFr        Translation German -> English
<NEW>
</NEW>
</HISTORY>

*********************************************************************/


#ifndef CALFRENETTRANSFORMATION_H
#define CALFRENETTRANSFORMATION_H

#include "calFrenetTransformation_TypeDef.h"

/* -----------------------------------------------------------------------------
    \brief Frenet Transformation
    
    \param 
    
    \return 
 * -----------------------------------------------------------------------------
*/
calFTOutType calFrenetTransformation(const calFTInTypeV3* Inputs);

/* -----------------------------------------------------------------------------
    \brief Calculation of Heading
    
    \param 
    
    \return 
    
    \DOORS 10308
 * -----------------------------------------------------------------------------
*/
float32 TrajCalc_FT_Theta(const float32 theta0, const float32 K0, const float32 K_prime, const float32 x, const float32 x0);

/* -----------------------------------------------------------------------------
    \brief Calculation of lateral distance 
    
    \param 
    
    \return 
    
    \DOORS 10308
 * -----------------------------------------------------------------------------
*/
float32 TrajCalc_FT_Y(const float32 Y0, const float32 theta0, const float32 K0, const float32 K_prime, const float32 x, const float32 x0);

/* -----------------------------------------------------------------------------
    \brief Calculation of curvature K 
    
    \param 
    
    \return 
    
    \DOORS 10308
 * -----------------------------------------------------------------------------
*/
float32 TrajCalc_FT_K(const float32 K0, const float32 K_prime, const float32 x, const float32 x0);

/* -----------------------------------------------------------------------------
    \brief Simplified calculation of heading angle for right corridor
    
    \param 
    
    \return 
    
    Initial heading angle of the right corridor is always zero. Thus a simplified
    calculation is used to reduce CPU load.
    
    \DOORS 9568
 * -----------------------------------------------------------------------------
*/
float32 TrajCalc_FT_Thetar(const float32 theta0, const float32 K0, const float32 K_prime, const float32 x, const float32 x0, const boolean_T UseCridrRiX0);

/* -----------------------------------------------------------------------------
    \brief Simplified calculation of lateral distance for right corridor
    
    \param 
    
    \return 
    
    Initial heading angle of the right corridor is always zero. Thus a simplified
    calculation is used to reduce CPU load.
    
    \DOORS 9568
 * -----------------------------------------------------------------------------
*/
float32 TrajCalc_FT_Yr(const float32 Y0, const float32 theta0, const float32 K0, const float32 K_prime, const float32 x, const float32 x0, const boolean_T UseCridrRiX0);

/* -----------------------------------------------------------------------------
    \brief Frenet 
    
    \param 
    
    \return 
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_InitializeOutputs(calFTOutType* Outputs);

/* -----------------------------------------------------------------------------
    \brief Frenet 
    
    \param 
    
    \return 
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_InitializeIntVectors(float32 A[61], float32 B[61], float32 C[61], float32 D[61]);

/* -----------------------------------------------------------------------------
    \brief Frenet Transformation of current values
    
    \param 
    
    \return 
    
    \DOORS 5205
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_TransformCurValues(const boolean_T PlanArcLength, const float32 DevDistY, const float32 DevHeading, const float32 Vx, const float32 Ax, const float32 Kr, const float32 Kr_prime, const float32 Kist, float32* dist, float32* dist1stDeriv, float32* dist2ndDeriv, float32* v_traj, float32* a_traj, float32 CurHdngAndDelta, float32* DeltaHdng1stDeriv, float32* DeltaHdng2ndDeriv, float32 Kstart, float32 Ksoll);

/* -----------------------------------------------------------------------------
    \brief Calculation of target lateral distances and derivatives 
    
    \param 
    
    \return 
    
    \DOORS 12951
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_CalcTargetCurvePoints(const boolean_T PlanArcLength, const float32 TgtSg1X, const float32 TgtSg1Length, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 PlanHorizon, const float32 CridrRiSg1Length, const float32 TgtTrajSg1Y, const float32 TgtTrajSg1Hdng, const float32 TgtTrajSg1Crv, const float32 TgtTrajSg1ChngOfCrv, const float32 v_traj, const float32 a_traj, calFTOutType* Outputs, const boolean_T UseTgtTrajX0, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Y);

/* -----------------------------------------------------------------------------
    \brief Calculation of start point of trajectory (arc length based planning)
    
    \param 
    
    \return 
    
    \DOORS 12950
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_CalcStartPoint_ArcLength(float32* x_Start, float32* t_Start, float32* s_Start, float32* PlanAreaTgt, const float32 TgtSg1X, const float32 TgtSg1Length, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0);

/* -----------------------------------------------------------------------------
    \brief Calculation of start point of trajectory (time based planning)
    
    \param 
    
    \return 
    
    \DOORS 12950
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_CalcStartPoint_Time(float32* x_Start, float32* t_Start, float32* s_Start, float32* PlanAreaTgt, const float32 v_traj, const float32 a_traj, const float32 TgtSg1X, const float32 TgtSg1Length, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0);

/* -----------------------------------------------------------------------------
    \brief Calculation of target lateral distances and derivatives (arc length based) 
    
    \param 
    
    \return 
    
    \DOORS 12951
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_CalcTargetCurve_ArcLength(uint8*  NumTgtPoints, float32 TgtPoints[61], float32 TgtDistYPoint[61], float32 TgtDistY1stDerivPoint[61], float32 TgtDistY2ndDerivPoint[61], float32* PlanHorizonFT, float32* PlanHorizonVisRange, const float32 x_Start, const float32 s_Start, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 CridrRiSg1Length, const float32 PlanAreaTgt, const float32 TgtTrajSg1Y, const float32 TgtTrajSg1Hdng, const float32 TgtTrajSg1Crv, const float32 TgtTrajSg1ChngOfCrv, float32 v_traj, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Y);

/* -----------------------------------------------------------------------------
    \brief Calculation of target lateral distances and derivatives (time based) 
    
    \param 
    
    \return 
    
    \DOORS 12951
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_CalcTargetCurve_Time(uint8*  NumTgtPoints, float32 TgtPoints[61], float32 TgtDistYPoint[61], float32 TgtDistY1stDerivPoint[61], float32 TgtDistY2ndDerivPoint[61], float32* PlanHorizonFT, float32* PlanHorizonVisRange, const float32 x_Start, const float32 s_Start, const float32 t_Start, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 CridrRiSg1Length, const float32 PlanAreaTgt, const float32 TgtTrajSg1Y, const float32 TgtTrajSg1Hdng, const float32 TgtTrajSg1Crv, const float32 TgtTrajSg1ChngOfCrv, const float32 v_traj, const float32 a_traj, const float32 PlanHorizon, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Y);

/* -----------------------------------------------------------------------------
    \brief Calculation of target lateral distances and derivatives 
    
    \param 
    
    \return 
    
    \DOORS 5286 
    \DOORS 5287
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_CalcLatDistDerivs(float32* dTgt_prime, float32* dTgt_primeprime, float32* TgtDistYPoint, const float32 Xi, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 TgtTrajSg1Y, const float32 TgtTrajSg1Hdng, const float32 TgtTrajSg1Crv, const float32 TgtTrajSg1ChngOfCrv, const float32 X0, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Y);

/* -----------------------------------------------------------------------------
    \brief Transformation of trajectory values from last cycle to Frenet coords 
    
    \param 
    
    \return 
    
    \DOORS 8050
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_CalcTrajLastCycle(float32* FT_DistYTrajPrev, float32* FT_DistYTrajPrev_dot, float32* FT_DistYTrajPrev_ddot, const float32 DistYTrajPrev, const float32 HdngTrajPrev, const boolean_T PlanArcLength, const float32 Kr, const float32 Kr_prime, const float32 Ktraj, const float32 vx, const float32 ax, float32* v_traj_Tgt, float32* a_traj_Tgt);

/* -----------------------------------------------------------------------------
    \brief Calculate preview of current values in Frenet coords
    
    \param 
    
    \return 
    
    \DOORS 12952
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_CalcPreviewCurValues(const float32 PreviewTimeKF, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 IstY, const float32 IstHeading, const float32 CurCrv, const float32 v_traj, const float32 a_traj, calFTOutType* Outputs, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Y);

/* -----------------------------------------------------------------------------
    \brief Frenet Transformation of left corridor boundary
    
    \param 
    
    \return 
    
    Calculate the lateral distances from the left corridor boundary at different points
    
    \DOORS 5663
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_CalcLeftCorridor(calFTOutType* Outputs, const float32 CridrRiSg1Crv, const float32 CridrRiSg1ChgOfCrv, const float32 CridrLeSg1Length, const float32 CridrRiSg1Length, const float32 CridrLeSg1Y,const float32 CridrLeSg1Hdng, const float32 CridrLeSg1Crv, const float32 CridrLeSg1ChgOfCrv, const float32 v_Traj, const float32 a_Traj, const boolean_T PlanArcLength, const float32 DeadTime, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Heading, const float32 CridrRiSg1Y, const float32 CridrLeSg1X);

/* -----------------------------------------------------------------------------
    \brief Frenet 
    
    \param 
    
    \return 
 * -----------------------------------------------------------------------------
*/
void TrajCalc_FT_CalcRightCorridor(const boolean_T PlanArcLength, const float32 v_Traj, const float32 a_Traj, const float32 CridrRiSg1Crv, const float32 CridrRiSg1ChgOfCrv, const float32 CridrRiSg1Length, calFTOutType* Outputs, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Heading);

/* -----------------------------------------------------------------------------

    H E L P E R   F U N C T I O N S

 * -----------------------------------------------------------------------------
*/

float32 TrajCalc_FT_AvoidZero(const float32 input);

float32 TrajCalc_FT_MinFloat(const float32 A, const float32 B);

float32 TrajCalc_FT_MaxFloat(const float32 A, const float32 B);

#endif	/* CALFRENETTRANSFORMATION_H */


