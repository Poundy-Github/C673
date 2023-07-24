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
            08.01.2018      Q.Zhu       Add Jerk Check
            20.06.2018      Q.Zhu       Add Lane Cross Check
            16.07.2018      Q.Zhu       Include matrixInvertible in the optimal trajectory selection criteria
<NEW>
</NEW>
</HISTORY>

*********************************************************************/

/* -----------------------------------------------------------------------------
    M I S R A
 * -----------------------------------------------------------------------------
*/

/* -----------------------------------------------------------------------------

    I N C L U D E S

 * -----------------------------------------------------------------------------
*/

#include "calOptTrajektorie.h"

/* -----------------------------------------------------------------------------

    D E C L A R A T I O N   F U N C T I O N S

 * -----------------------------------------------------------------------------
*/

#define START_SEC_CODE

/* -----------------------------------------------------------------------------

    F U N C T I O N   D E F I N I T I O N S

 * -----------------------------------------------------------------------------
*/

void TrajCalc_InitializeOutputs(calOptOutTypeV4* Outputs) {
    Outputs->sfunc_TrajStatus_nu = false;
    {
        uint8 i;
        for( i=0; i<6; i++ )
        {
            Outputs->sfunc_TrajParam_nu[i] = 0.0F;
        }
    }
    Outputs->sfunc_MaxAclTraj_mps2         = 20.0F;
    Outputs->sfunc_TrajCalcTimeTrajEnd_sec   = 100.0F;
    Outputs->sfunc_ArcLengthTrajEnd_met      = 100.0F;
    Outputs->sfunc_OptimalTolerance_nu     = 0.f;
    Outputs->sfunc_OptimalCost_nu          = 99e+10F;
    Outputs->sfunc_FtireMinOK_nu           = true;
    Outputs->sfunc_FtireMaxOK_nu           = true;
    Outputs->sfunc_CollDetRightOK_nu       = true;
    Outputs->sfunc_CollDetLeftOK_nu        = true;
    Outputs->sfunc_CollDetObjOK_nu         = true;
    Outputs->sfunc_MatrixInverseOK_nu      = false;
    Outputs->sfunc_TrajLengthOK_nu         = true;
    Outputs->sfunc_MaxJerkTraj_mps3        = 10.0F;
    Outputs->sfunc_MaxJerkOK_nu            = true;
    Outputs->sfunc_LaneCrossOK_nu          = true;
}

void TrajCalc_CalcAxBx( float32 A[3][3], float32 B[3], const float32 Param[6], const float32 t, const float32 d, const float32 d_dot, const float32 d_ddot)
{
    float32 t_2,t_3,t_4,t_5;
    t_2 = t * t;
    t_3 = t_2 * t;
    t_4 = t_3 * t;
    t_5 = t_4 * t;
    A[0][0] = t_3;
    A[0][1] = t_4;
    A[0][2] = t_5;
    A[1][0] = 3 * t_2;
    A[1][1] = 4 * t_3;
    A[1][2] = 5 * t_4;
    A[2][0] = 6 * t;
    A[2][1] = 12 * t_2;
    A[2][2] = 20 * t_3;

    B[0] = d - Param[0] - (t * Param[1]) - ( t_2 * Param[2] );
    B[1] = d_dot - Param[1] - (( 2 * t ) * Param[2] );
    B[2] = d_ddot - ( 2 * Param[2] ); 
}

boolean_T TrajCalc_CalcParameters(float32 Param[6], float32 A[][3], const float32 B[3])
{
    boolean_T bIsMatrixInvertible;
    float32 determinant = ((A[0][0]*((A[1][1]*A[2][2])-(A[2][1]*A[1][2]))) - (A[0][1]*((A[1][0]*A[2][2])-(A[1][2]*A[2][0])))) + (A[0][2]*((A[1][0]*A[2][1])-(A[1][1]*A[2][0])));
    /* MISRA-AK: Math Functions */
    /* PRQA S 4604,3335 2 */
    if( (float32)FD_FABS(determinant) > 1.0e-10F )
    {
        {
            float32 A_inv[3][3];
            float32 invdet = 1.0f / determinant;
            A_inv[0][0] =  ((A[1][1]*A[2][2]) - (A[2][1]*A[1][2])) * invdet;
            A_inv[0][1] = -((A[0][1]*A[2][2]) - (A[0][2]*A[2][1])) * invdet;
            A_inv[0][2] =  ((A[0][1]*A[1][2]) - (A[0][2]*A[1][1])) * invdet;
            A_inv[1][0] = -((A[1][0]*A[2][2]) - (A[1][2]*A[2][0])) * invdet;
            A_inv[1][1] =  ((A[0][0]*A[2][2]) - (A[0][2]*A[2][0])) * invdet;
            A_inv[1][2] = -((A[0][0]*A[1][2]) - (A[1][0]*A[0][2])) * invdet;
            A_inv[2][0] =  ((A[1][0]*A[2][1]) - (A[2][0]*A[1][1])) * invdet;
            A_inv[2][1] = -((A[0][0]*A[2][1]) - (A[2][0]*A[0][1])) * invdet;
            A_inv[2][2] =  ((A[0][0]*A[1][1]) - (A[1][0]*A[0][1])) * invdet; 
            /* \DOORS 3388 At any time the parameters p3, p4, p5 shall be calculated by solving the following equations */
            Param[3] = (A_inv[0][0]*B[0]) + (A_inv[0][1]*B[1]) + (A_inv[0][2]*B[2]);      
            Param[4] = (A_inv[1][0]*B[0]) + (A_inv[1][1]*B[1]) + (A_inv[1][2]*B[2]);
            Param[5] = (A_inv[2][0]*B[0]) + (A_inv[2][1]*B[1]) + (A_inv[2][2]*B[2]);
            bIsMatrixInvertible = 1;
        }
    }
    else
    {
        bIsMatrixInvertible = 0;
        /* \DOORS 3388 At any time the parameters p3, p4, p5 shall be calculated by solving the following equations */
        Param[3] = 0.0f;      
        Param[4] = 0.0f;
        Param[5] = 0.0f;
    }
    A[0][0] = 0.0f;
    
    return bIsMatrixInvertible;   
}

float32 TrajCalc_CalcCostFunction(const float32 Param[6], const float32 t, const float32 Kd, const float32 Kt, const float32 d, const float32 d_k)
{
    /* \DOORS 3391 */
    float32 fCost, t_2, t_3, t_4, t_5, P3_2, P4_2, P5_2;
    t_2 = t * t;
    t_3 = t_2 * t;
    t_4 = t_3 * t;
    t_5 = t_4 * t;
    P3_2 = Param[3] * Param[3];
    P4_2 = Param[4] * Param[4];
    P5_2 = Param[5] * Param[5];
    /* MISRA-AK: Math Functions */
    /* PRQA S 4604,3335 2 */
    fCost = ((18 * P3_2) * t) + (((72 * Param[3]) * Param[4]) * t_2) + ((((120 * Param[3]) * Param[5]) + (96 * P4_2)) * t_3) + (((360 * Param[4]) * Param[5]) * t_4) + ((360 * P5_2) * t_5) + (Kd * ( (d - d_k) * (d - d_k) )) + (Kt * t);

    return fCost;
}

float32 TrajCalc_CalcMaxTrajAccel(const float32 p2, const float32 p3, const float32 p4, const float32 p5, const float32 t, const float32 Kr, const float32 Vx)
{
    float32 fAmax, t_2, t_3;
    t_2 = t * t;
    t_3 = t_2 * t;
    /* MISRA-AK: Math Functions */
    /* PRQA S 4604,3335 2 */
    fAmax = (float32)FD_FABS( ((((2*p2) + ((6*p3)*t)) + ((12*p4)*t_2)) + ((20*p5)*t_3)) + (Kr * (Vx * Vx)) );
    
    return fAmax;
}

boolean_T TrajCalc_CheckPotVector(const float32 curParam[6], float32* AMax, const float32 Kr, const float32 te, const float32 VehVelX, const float32 FTireAclMin ,const float32 FTireAclMax,  const boolean_T PlanArcLength, boolean_T* FTireAclMinOk, boolean_T* FTireAclMaxOk)
{
    boolean_T StatusPotVecCheck;
    
    float32 t_max1, t_max2, a_max[4], fTmpAMax, P4_2;
    t_max2 = 0;
    t_max1 = 0;
    P4_2 = curParam[4] * curParam[4];

        /* \DOORS 3404 Calculation of extreme value tm */
        /* MISRA-AK: Math Functions */
        /* PRQA S 4604,3335 2 */
        if( (float32)FD_FABS(curParam[5]) > 1.0e-10F ) {
            if( ( (2 * P4_2) - (5 * curParam[3] * curParam[5])) >= 0) {
                /* MISRA-AK: Math Functions */
                /* PRQA S 4604,3335 2 */
                t_max1 = ( (-2.0F * curParam[4]) + ((float32)FD_SQRT(2) * (float32)FD_SQRT( (2*P4_2) - (5*curParam[3]*curParam[5]) )) ) / (10 * curParam[5]);
                /* MISRA-AK: Math Functions */
                /* PRQA S 4604,3335 2 */
                t_max2 = ( (-2.0F * curParam[4]) - ((float32)FD_SQRT(2) * (float32)FD_SQRT( (2*P4_2) - (5*curParam[3]*curParam[5]) )) ) / (10 * curParam[5]);
                
                t_max1 = (te < t_max1)?te:t_max1; /* t_max1 = max(min(te[j],t_max1),0); */
                t_max1 = (t_max1 > 0)?t_max1:0;
                
                t_max2 = (te < t_max2)?te:t_max2; /* t_max2 = max(min(te[j],t_max2),0); */
                t_max2 = (t_max2 > 0)?t_max2:0;
            }
        }
        else {
            /* MISRA-AK: Math Functions */
            /* PRQA S 4604,3335 2 */
            if( (float32)FD_FABS(curParam[4]) > 1.0e-10F ) {
                t_max2 = - curParam[3] / (4 * curParam[4]);
                t_max2 = (te < t_max2)?te:t_max2;
                t_max2 = (t_max2 > 0)?t_max2:0;
            }
        }
        
        /* \DOORS 3405 Calculation of max. acceleration of all tm */
        a_max[0] = TrajCalc_CalcMaxTrajAccel( curParam[2], curParam[3], curParam[4], curParam[5], 0.0F, Kr, VehVelX);
        a_max[1] = TrajCalc_CalcMaxTrajAccel( curParam[2], curParam[3], curParam[4], curParam[5], t_max1, Kr, VehVelX);
        a_max[2] = TrajCalc_CalcMaxTrajAccel( curParam[2], curParam[3], curParam[4], curParam[5], t_max2, Kr, VehVelX);
        a_max[3] = TrajCalc_CalcMaxTrajAccel( curParam[2], curParam[3], curParam[4], curParam[5], te, Kr, VehVelX); 
        {
            uint8 iter;
            fTmpAMax =  a_max[0];
            for(iter = 1; iter < 4; iter++) 
            {
                fTmpAMax = (fTmpAMax > a_max[iter]) ? fTmpAMax : a_max[iter];
            }
        }
        *AMax = fTmpAMax;

        /* \DOORS 3407 Calculation of flag to check pot. vectors */
        if(PlanArcLength == true) 
        {
            StatusPotVecCheck = true;
            *FTireAclMinOk = true;
            *FTireAclMaxOk = true;
        }
        else
        {
            if(fTmpAMax >= FTireAclMin)
            {
                *FTireAclMinOk = true;
            }
            else
            {
                *FTireAclMinOk = false;
            }
            if(fTmpAMax <= FTireAclMax)
            {
                *FTireAclMaxOk = true;
            }
            else
            {
                *FTireAclMaxOk = false;
            }
            StatusPotVecCheck = (*FTireAclMaxOk) & (*FTireAclMinOk);
        }

        return StatusPotVecCheck;
}

float32 TrajCalc_CalcTrajJerk(const float32 p3, const float32 p4, const float32 p5, const float32 t, const float32 CrvChng, const float32 Vx)
{
    float32 fJerk, t_2;
    t_2 = t * t;
    /* MISRA-AK: Math Functions */
    /* PRQA S 4604,3335 2 */
    fJerk = (float32)FD_FABS( (6*p3 + (24*p4)*t + (60*p5)*t_2) + CrvChng * (Vx * Vx * Vx) );
    
    return fJerk;
}

boolean_T TrajCalc_CheckJerk(const float32 curParam[6], float32* JerkMax, const float32 CrvChng, const float32 te, const float32 VehVelX, const float32 AllwdJerkMax, const boolean_T PlanArcLength)
{
    boolean_T StatusJerkCheck;
    float32 t_m[3]; 
    float32 t_Jerkmax, TempJerkMax, TempJerk[3], t, SumJerk, t_offset;
    
    t_m[0] = 0.0F;
    /* Calculation of extreme value tm */
    if( (float32)FD_FABS(curParam[5]) > 1.0e-10F ) {
        t_m[1] = -24*curParam[4]/(120*curParam[5]);
    }
    else {
        t_m[1] = 0.0F;
    }
    t_m[2] = te;
    /* Calculation of max. Jerk */
    TempJerk[0] = TrajCalc_CalcTrajJerk(curParam[3], curParam[4], curParam[5], t_m[0], CrvChng, VehVelX);
    TempJerk[1] = TrajCalc_CalcTrajJerk(curParam[3], curParam[4], curParam[5], t_m[1], CrvChng, VehVelX);
    TempJerk[2] = TrajCalc_CalcTrajJerk(curParam[3], curParam[4], curParam[5], t_m[2], CrvChng, VehVelX);
    {
        uint8 iter;
        TempJerkMax =  TempJerk[0];
        t_Jerkmax = t_m[0];
        for(iter = 1; iter < 3; iter++) 
        {
            if(TempJerk[iter] > TempJerkMax)
            {
                TempJerkMax = TempJerk[iter];
                t_Jerkmax = t_m[iter];
            }
        }
    }
    /* Check max. ave. Jerk */
    if((TempJerkMax > AllwdJerkMax) & (PlanArcLength == false)){
        if(t_Jerkmax < 0.25F)
        {
            t_offset = 0.0F;
        }
        else if(t_Jerkmax >= (te - 0.25F))
        {
            t_offset = te - 0.5F;
        }
        else
        {
            t_offset = t_Jerkmax - 0.25F;
        }
        SumJerk = 0.0F;
        t = t_offset;
        SumJerk = SumJerk + TrajCalc_CalcTrajJerk(curParam[3], curParam[4], curParam[5], t, CrvChng, VehVelX);
        {
            uint8 jter;
            for(jter = 1; jter < 26; jter++) 
            {
                t = t + 0.02F;
                SumJerk = SumJerk + TrajCalc_CalcTrajJerk(curParam[3], curParam[4], curParam[5], t, CrvChng, VehVelX);
            }
        }
        *JerkMax = SumJerk / 26.0;
        if(*JerkMax > AllwdJerkMax)
        {
            StatusJerkCheck = false;
        }
        else
        {
            StatusJerkCheck = true;
        }
    }
    else {
        StatusJerkCheck = true;
    }
        
    return StatusJerkCheck;
}


boolean_T TrajCalc_CheckCollisionCorridor( const boolean_T PlanArcLength, const float32 PH_Traj, const float32 PH_VisLength, const float32 CurTgtPoint, const uint8 EndIndexLeftCridr, float32 CircleRadius, const float32 Param[6], const float32 LeftDistY[100], boolean_T* CollCheckRightOk, boolean_T* CollCheckLeftOk)
{
    uint8   MaxNumPoints;
    float32 TestPoints, VisLength;
    uint8 i;
    float32 TestPoints_2, TestPoints_3, TestPoints_4, TestPoints_5;
    boolean_T EndOfCheck, CollRightCridr, CollLeftCridr;
    float32 delta_s, delta_t, Y_Traj;
    boolean_T NoCollision;

    /* Init */
    MaxNumPoints = 100;
    EndOfCheck = false;
    CollRightCridr = false;
    CollLeftCridr = false;

    /* \DOORS 10507 Definition of delta_s and delta_t */
    delta_s = 0.7f;
    delta_t = 0.05f;
    i = 0;

    while ( (EndOfCheck != true) && ( CollRightCridr != true) && (CollLeftCridr != true) )
    {
        /* \DOORS 10507 Calculate sample points for each trajectory. The sample points must be within visible length */
        if( PlanArcLength == true )
        {
            VisLength = PH_Traj;
            TestPoints = (float32)(i+1) * delta_s;      // in Meter
        }
        else
        {
            VisLength = PH_VisLength;
            TestPoints = (float32)(i+1) * delta_t;      // in Seconds
        }

        /* \DOORS 13508, 13511 */
        if( (TestPoints <= VisLength) && (TestPoints <= CurTgtPoint) && (i < EndIndexLeftCridr) && (i < MaxNumPoints))
        {
            /* \DOORS 10511 Calculate lateral distance for each test point */
            TestPoints_2 = TestPoints * TestPoints;
            TestPoints_3 = TestPoints_2 * TestPoints;
            TestPoints_4 = TestPoints_3 * TestPoints;
            TestPoints_5 = TestPoints_4 * TestPoints;
            Y_Traj = (((((Param[0]) + ( (Param[1]) * TestPoints)) + ((Param[2]) * TestPoints_2)) + ((Param[3]) * TestPoints_3)) + ((Param[4]) * TestPoints_4)) + ((Param[5]) * TestPoints_5);

            /*
             * Check if lateral distance of test point collides with right corridor boundary
             * \DOORS 13394
             */
            if( Y_Traj < CircleRadius )
            {
                CollRightCridr = true;
            }
            /*
             * Check if lateral distance of test point collides with left corridor boundary
             *  \DOORS 13474
             */
            if( Y_Traj > (LeftDistY[i] - CircleRadius) )
            {
                CollLeftCridr = true;
            }

            /*
             *  Next point
             */
            i = i + 1;
        }
        else
        {
            EndOfCheck = true;
        }
    }

    /* \DOORS 13473 Bit 2 of signal FasQcBplBtb_QualifierStatusBPL */
    if(CollRightCridr != true)
    {
        *CollCheckRightOk = true;
    }
    else
    {
        *CollCheckRightOk = false;
    }

    /* \DOORS 13475 Bit 3 of signal FasQcBplBtb_QualifierStatusBPL */
    if(CollLeftCridr != true)
    {
        *CollCheckLeftOk = true;
    }
    else
    {
        *CollCheckLeftOk = false;
    }

    /* \DOORS 6242 */
    NoCollision = (*CollCheckRightOk) & (*CollCheckLeftOk);

    return NoCollision;
}

boolean_T TrajCalc_CheckCollisionObject(const float32 t_DeadTime, const float32 v_Traj, const float32 a_Traj, const float32 v_Obj, const float32 a_Obj, const float32 ObstDistX, const float32 ObstDistY, const float32 HindernisWidth, const float32 CircleRadius, const float32 VisLength, const float32 TgtPoint, const float32 P[6])
{
    boolean_T NoCollision, EndOfCheck;
    float32 delta_t, TestPoints, TestPoints_2, TestPoints_3, TestPoints_4, TestPoints_5, t_DeadTime_2, min_t;
    uint8 i;
    float32 X0_Traj, X0_Obj;
    float32 X_Traj, Y_Traj, X_Obj, Y_Obj, X_TrajObj, Y_TrajObj;

    delta_t = 0.05f;    /* in Seconds */
    i = 0;
    NoCollision = true;
    EndOfCheck = false;

    /* Calculate start point of trajectory and object according to dead time */
    t_DeadTime_2 = t_DeadTime * t_DeadTime;
    X0_Traj = (v_Traj * t_DeadTime) + ((0.5f * a_Traj) * t_DeadTime_2);
    X0_Obj = (v_Obj * t_DeadTime) + ((0.5f * a_Obj) * t_DeadTime_2);

    while ( (EndOfCheck != true) && ( NoCollision == true) )    //
    {
        /* Calculate sample points for time based optimization (collision check only if time based planning) */
        TestPoints = (float32)(i+1) * delta_t;      /* in Seconds */
        TestPoints_2 = TestPoints * TestPoints;
        TestPoints_3 = TestPoints_2 * TestPoints;
        TestPoints_4 = TestPoints_3 * TestPoints;
        TestPoints_5 = TestPoints_4 * TestPoints;

        /* Calculate x-distance and y-distance of trajectory */
        min_t = TrajCalc_MinFloat( (1.f - t_DeadTime), TestPoints);
        X_Traj = (X0_Traj + (v_Traj * TestPoints)) + ((0.5f * a_Traj) * (min_t * min_t));
        Y_Traj = ((((P[0] + (P[1]*TestPoints)) + (P[2]*TestPoints_2)) + (P[3]*TestPoints_3)) + (P[4]*TestPoints_4)) + (P[5]*TestPoints_5);

        /* Calculate x-distance of object */
        X_Obj = (X0_Obj + (v_Obj * TestPoints)) + ((0.5f * a_Obj) * (min_t * min_t));
        Y_Obj = 0.f;

        /* Calculate relative motion */
        X_TrajObj = X_Traj - X_Obj;
        Y_TrajObj = Y_Traj - Y_Obj;

        if( X_TrajObj >= ( ObstDistX - CircleRadius) )
        {
            if( (Y_TrajObj <= ( (ObstDistY + (0.5f*HindernisWidth)) + CircleRadius) ) && ( Y_TrajObj >= ((ObstDistY - (0.5*HindernisWidth)) - CircleRadius) ) )
            {
                NoCollision = false;
            }
        }
        /* Next point */
        if( (TestPoints >= VisLength) || (TestPoints >= TgtPoint))
        {
            EndOfCheck = true;
        }
        else
        {
            i++;
        }
    }
    return NoCollision;
}

boolean_T TrajCalc_CheckLaneCross(const float32 PH_VisLength, const float32 CurTgtPoint, const float32 VehicleWidth, const float32 Param[6], const float32 AllowedTimetoCross, const float32 LaneWidth)
{
    float32 TestPoints, VisLength;
    float32 TestPoints_2, TestPoints_3, TestPoints_4, TestPoints_5;
    boolean_T CrossRightCridr, CrossLeftCridr;
    float32 Y_Traj;
    boolean_T NoCross;

    CrossRightCridr = false;
    CrossLeftCridr = false;
    NoCross = true;
    VisLength = PH_VisLength;
    TestPoints = AllowedTimetoCross;

    if(TestPoints >= 0.01)
    {
        /* Calculate lateral distance for test point */
        TestPoints_2 = TestPoints * TestPoints;
        TestPoints_3 = TestPoints_2 * TestPoints;
        TestPoints_4 = TestPoints_3 * TestPoints;
        TestPoints_5 = TestPoints_4 * TestPoints;
        Y_Traj = (((((Param[0]) + ((Param[1]) * TestPoints)) + ((Param[2]) * TestPoints_2)) + ((Param[3]) * TestPoints_3)) + ((Param[4]) * TestPoints_4)) + ((Param[5]) * TestPoints_5);

        if ((Param[0]) < 0)
        {
            /* Check if lateral distance of test point cross the right corridor boundary */
            if(Y_Traj > (-0.5F * VehicleWidth))
            {
                CrossRightCridr = true;
            }
        }
        else
        {
            /* Check if lateral distance of test point cross the left corridor boundary */
            if(Y_Traj < (LaneWidth + 0.5F * VehicleWidth))
            {
                CrossLeftCridr = true;
            }
        }
    }

    /*  */
    if((CrossRightCridr != true) && (CrossLeftCridr != true))
    {
        NoCross = true;
    }
    else
    {
        NoCross = false;
    }

    return NoCross;
}

/**
 * \addtogroup calOptTrajektorie_Ext External
 * \ingroup TrajCalc_CalcOptTrajectory
 * \{
 */
calOptOutTypeV4 TrajCalc_CalcOptTrajectory(const calOptInTypeV3* Inputs)
{
    calOptOutTypeV4 Outputs;
    uint8 VecLength;
    boolean_T NewBestPoint;
    float32 dz_toleranz, temp;
    VecLength = 15;

    /* Initialize all variables */
    TrajCalc_InitializeOutputs(&Outputs);
    NewBestPoint = false;
    temp = Inputs->sfunc_TrajCalcPlanHorizonTraj_sec;
    
    if( (Inputs->sfunc_TrajCalcNumTgtPoints_nu == 0) || 
      ( (Inputs->sfunc_TrajCalcNumTgtPoints_nu == 1) && ( temp < 0.000001f ) ) )       // --> No valid sample points
    {
        Outputs.sfunc_TrajStatus_nu = false;
        Outputs.sfunc_MatrixInverseOK_nu = true;
        Outputs.sfunc_TrajLengthOK_nu = false;

    }
    else
    {
        /* Calculate trajectory parameters */
        uint8 ind_dTgtk, k_max, ind_opt;
        float32 te;
        float32 dTgt_k, dz_dot, dz_ddot;
        float32 K_d, K_t;

        if(Inputs->sfunc_ReplanModeArcLength_nu == true ) {
            K_d = Inputs->sfunc_Kd;
            K_t = Inputs->sfunc_Kt * Inputs->sfunc_WeightArcLengthPlan_nu;
        }
        else {
            K_d = Inputs->sfunc_Kd;
            K_t = Inputs->sfunc_Kt;
        }
        
        k_max = Inputs->sfunc_TrajCalcNumTgtPoints_nu;
        if(k_max > VecLength)
        {
            k_max = VecLength;      /* maximum VecLength is 15. */
        }

        ind_opt = 255;      /* --> Initialize index with optimum point to 255 */
        for(ind_dTgtk = 0; ind_dTgtk < k_max; ind_dTgtk++)
        {
            te = Inputs->sfunc_teTrajCalcTgt_nu[ind_dTgtk];
            dTgt_k = Inputs->sfunc_TrajCalcTgtDistY_met[ind_dTgtk];
            dz_dot = Inputs->sfunc_TrajCalcTgtDistY1stDeriv_nu[ind_dTgtk];
            dz_ddot = Inputs->sfunc_TrajCalcTgtDistY2ndDeriv_nu[ind_dTgtk];
            dz_toleranz = dTgt_k + 0.f;
            TrajCalc_CalcOptTrajectoryInt(dz_toleranz, dz_dot, dz_ddot, te, &NewBestPoint, Inputs->sfunc_DistYInit_nu, Inputs->sfunc_DistY1stDerivInit_nu, Inputs->sfunc_DistY2ndDerivInit_nu, K_d, K_t, dTgt_k, Inputs->sfunc_CheckFtire_nu, Inputs->sfunc_LatCtrlCoordCridrRightSeg1_Crv_1pm, Inputs->sfunc_TrajCalcEgoVelX_mps, Inputs->sfunc_AclPotVecMin_mps2, Inputs->sfunc_AclPotVecMax_mps2, Inputs->sfunc_ReplanModeArcLength_nu, &Outputs, Inputs->sfunc_TrajCalcPlanHorizonVisibility_sec, Inputs->sfunc_TrajCalcPlanHorizonTraj_sec, Inputs->sfunc_CheckCridrBoundaries_nu, Inputs->sfunc_CheckObjects_nu, Inputs, Inputs->sfunc_CrvChng_1pm2, Inputs->sfunc_AllwdJerkMax_mps3, Inputs->sfunc_CheckJerk_nu, Inputs->sfunc_CheckLaneCross_nu);
            if(NewBestPoint == true)
            {
                ind_opt = ind_dTgtk;
            }
        }   /* Until here all target points have been calculate an an "optimum" trajectory has been found (if it exists) */


        /* 
         *  Extension of lateral tolerance area 
         */
        if( ind_opt != 255 )    /* at least one optimum point was found */
        {   
            uint8 maxLoop, curLoop;
            float32 dz_alt_opt, dz_new, dz_new_opt;
            dz_dot = Inputs->sfunc_TrajCalcTgtDistY1stDeriv_nu[ind_opt];
            dz_ddot = Inputs->sfunc_TrajCalcTgtDistY2ndDeriv_nu[ind_opt];
            te = Inputs->sfunc_teTrajCalcTgt_nu[ind_opt];
            /* false means old optimum point: no new point was found */
            NewBestPoint = false; 
            maxLoop = 8;

            /* MISRA-AK: Mathfunktionen */
            /* PRQA S 4604,3335 2 */
            if( (float32)FD_FABS(Inputs->sfunc_TolDistYLeft_met) >= 0.00000f ) {      /* Tolerance left */
                dz_alt_opt = Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt];
                dz_new = Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt] + Inputs->sfunc_TolDistYLeft_met;
                TrajCalc_CalcOptTrajectoryInt(dz_new, dz_dot, dz_ddot, te, &NewBestPoint, Inputs->sfunc_DistYInit_nu, Inputs->sfunc_DistY1stDerivInit_nu, Inputs->sfunc_DistY2ndDerivInit_nu, K_d, K_t, Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt], Inputs->sfunc_CheckFtire_nu, Inputs->sfunc_LatCtrlCoordCridrRightSeg1_Crv_1pm, Inputs->sfunc_TrajCalcEgoVelX_mps, Inputs->sfunc_AclPotVecMin_mps2, Inputs->sfunc_AclPotVecMax_mps2, Inputs->sfunc_ReplanModeArcLength_nu, &Outputs, Inputs->sfunc_TrajCalcPlanHorizonVisibility_sec, Inputs->sfunc_TrajCalcPlanHorizonTraj_sec, Inputs->sfunc_CheckCridrBoundaries_nu, Inputs->sfunc_CheckObjects_nu, Inputs, Inputs->sfunc_CrvChng_1pm2, Inputs->sfunc_AllwdJerkMax_mps3, Inputs->sfunc_CheckJerk_nu, Inputs->sfunc_CheckLaneCross_nu);
                dz_new = (dz_alt_opt + dz_new) / 2.0f;
                if( NewBestPoint == true ) {
                    dz_alt_opt = Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt] + Inputs->sfunc_TolDistYLeft_met;
                }
                else {
                    dz_alt_opt = Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt];
                }
                TrajCalc_CalcOptTrajectoryInt(dz_new, dz_dot, dz_ddot, te, &NewBestPoint, Inputs->sfunc_DistYInit_nu, Inputs->sfunc_DistY1stDerivInit_nu, Inputs->sfunc_DistY2ndDerivInit_nu, K_d, K_t, Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt], Inputs->sfunc_CheckFtire_nu, Inputs->sfunc_LatCtrlCoordCridrRightSeg1_Crv_1pm, Inputs->sfunc_TrajCalcEgoVelX_mps, Inputs->sfunc_AclPotVecMin_mps2, Inputs->sfunc_AclPotVecMax_mps2, Inputs->sfunc_ReplanModeArcLength_nu, &Outputs, Inputs->sfunc_TrajCalcPlanHorizonVisibility_sec, Inputs->sfunc_TrajCalcPlanHorizonTraj_sec, Inputs->sfunc_CheckCridrBoundaries_nu, Inputs->sfunc_CheckObjects_nu, Inputs, Inputs->sfunc_CrvChng_1pm2, Inputs->sfunc_AllwdJerkMax_mps3, Inputs->sfunc_CheckJerk_nu, Inputs->sfunc_CheckLaneCross_nu);
                dz_new_opt = dz_new;
                
                for( curLoop= 1; curLoop < maxLoop; curLoop++ ) {
                    
                    dz_new = (dz_alt_opt + dz_new_opt) / 2.0f;
                    
                    TrajCalc_CalcOptTrajectoryInt(dz_new, dz_dot, dz_ddot, te, &NewBestPoint, Inputs->sfunc_DistYInit_nu, Inputs->sfunc_DistY1stDerivInit_nu, Inputs->sfunc_DistY2ndDerivInit_nu, K_d, K_t, Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt], Inputs->sfunc_CheckFtire_nu, Inputs->sfunc_LatCtrlCoordCridrRightSeg1_Crv_1pm, Inputs->sfunc_TrajCalcEgoVelX_mps, Inputs->sfunc_AclPotVecMin_mps2, Inputs->sfunc_AclPotVecMax_mps2, Inputs->sfunc_ReplanModeArcLength_nu, &Outputs, Inputs->sfunc_TrajCalcPlanHorizonVisibility_sec, Inputs->sfunc_TrajCalcPlanHorizonTraj_sec, Inputs->sfunc_CheckCridrBoundaries_nu, Inputs->sfunc_CheckObjects_nu, Inputs, Inputs->sfunc_CrvChng_1pm2, Inputs->sfunc_AllwdJerkMax_mps3, Inputs->sfunc_CheckJerk_nu, Inputs->sfunc_CheckLaneCross_nu);

                    if( NewBestPoint == true ) {
                        dz_alt_opt = dz_new_opt;
                        dz_new_opt = dz_new;
                    }
                    else {
                        dz_alt_opt = dz_new;
                        dz_new_opt = dz_new_opt;
                    }
                    
                }
            }

            /* MISRA-AK: Mathfunktionen */
            /* PRQA S 4604,3335 2 */
            if( (float32)FD_FABS(Inputs->sfunc_TolDistYRight_met)>= 0.00000f ) {
                
                dz_alt_opt = Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt];
                dz_new = Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt] - Inputs->sfunc_TolDistYRight_met;
                TrajCalc_CalcOptTrajectoryInt(dz_new, dz_dot, dz_ddot, te, &NewBestPoint, Inputs->sfunc_DistYInit_nu, Inputs->sfunc_DistY1stDerivInit_nu, Inputs->sfunc_DistY2ndDerivInit_nu, K_d, K_t, Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt], Inputs->sfunc_CheckFtire_nu, Inputs->sfunc_LatCtrlCoordCridrRightSeg1_Crv_1pm, Inputs->sfunc_TrajCalcEgoVelX_mps, Inputs->sfunc_AclPotVecMin_mps2, Inputs->sfunc_AclPotVecMax_mps2, Inputs->sfunc_ReplanModeArcLength_nu, &Outputs, Inputs->sfunc_TrajCalcPlanHorizonVisibility_sec, Inputs->sfunc_TrajCalcPlanHorizonTraj_sec, Inputs->sfunc_CheckCridrBoundaries_nu, Inputs->sfunc_CheckObjects_nu, Inputs, Inputs->sfunc_CrvChng_1pm2, Inputs->sfunc_AllwdJerkMax_mps3, Inputs->sfunc_CheckJerk_nu, Inputs->sfunc_CheckLaneCross_nu);

                dz_new = (dz_alt_opt + dz_new) / 2.0f;

                if( NewBestPoint == true )
                {
                    dz_alt_opt = Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt] - Inputs->sfunc_TolDistYRight_met;
                }
                else
                {
                    dz_alt_opt = Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt];
                }

                TrajCalc_CalcOptTrajectoryInt(dz_new, dz_dot, dz_ddot, te, &NewBestPoint, Inputs->sfunc_DistYInit_nu, Inputs->sfunc_DistY1stDerivInit_nu, Inputs->sfunc_DistY2ndDerivInit_nu, K_d, K_t, Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt], Inputs->sfunc_CheckFtire_nu, Inputs->sfunc_LatCtrlCoordCridrRightSeg1_Crv_1pm, Inputs->sfunc_TrajCalcEgoVelX_mps, Inputs->sfunc_AclPotVecMin_mps2, Inputs->sfunc_AclPotVecMax_mps2, Inputs->sfunc_ReplanModeArcLength_nu, &Outputs, Inputs->sfunc_TrajCalcPlanHorizonVisibility_sec, Inputs->sfunc_TrajCalcPlanHorizonTraj_sec, Inputs->sfunc_CheckCridrBoundaries_nu, Inputs->sfunc_CheckObjects_nu, Inputs, Inputs->sfunc_CrvChng_1pm2, Inputs->sfunc_AllwdJerkMax_mps3, Inputs->sfunc_CheckJerk_nu, Inputs->sfunc_CheckLaneCross_nu);
                dz_new_opt = dz_new;

                for( curLoop= 1; curLoop < maxLoop; curLoop++ ) {
                    
                    dz_new = (dz_alt_opt + dz_new_opt) / 2.0f;
                    
                    TrajCalc_CalcOptTrajectoryInt(dz_new, dz_dot, dz_ddot, te, &NewBestPoint, Inputs->sfunc_DistYInit_nu, Inputs->sfunc_DistY1stDerivInit_nu, Inputs->sfunc_DistY2ndDerivInit_nu, K_d, K_t, Inputs->sfunc_TrajCalcTgtDistY_met[ind_opt], Inputs->sfunc_CheckFtire_nu, Inputs->sfunc_LatCtrlCoordCridrRightSeg1_Crv_1pm, Inputs->sfunc_TrajCalcEgoVelX_mps, Inputs->sfunc_AclPotVecMin_mps2, Inputs->sfunc_AclPotVecMax_mps2, Inputs->sfunc_ReplanModeArcLength_nu, &Outputs, Inputs->sfunc_TrajCalcPlanHorizonVisibility_sec, Inputs->sfunc_TrajCalcPlanHorizonTraj_sec, Inputs->sfunc_CheckCridrBoundaries_nu, Inputs->sfunc_CheckObjects_nu, Inputs, Inputs->sfunc_CrvChng_1pm2, Inputs->sfunc_AllwdJerkMax_mps3, Inputs->sfunc_CheckJerk_nu, Inputs->sfunc_CheckLaneCross_nu);

                    if( NewBestPoint == true ) {
                        dz_alt_opt = dz_new_opt;
                        dz_new_opt = dz_new;
                    }
                    else {
                        dz_alt_opt = dz_new;
                        dz_new_opt = dz_new_opt;
                    }
                }
            }
        }
        
    }   /* --> End of calculation of parameters of new trajectory */
    return Outputs;
}

void TrajCalc_CalcOptTrajectoryInt(const float32 dz_new, const float32 dz_dot, const float32 dz_ddot, const float32 te, boolean_T* NewBestPoint, const float32 d_AW, const float32 d_AWdot, const float32 d_AWddot, const float32 Kd, const float32 Kt, const float32 dz_original, const boolean_T CheckFTire, const float32 Kr, const float32 VehVelX, const float32 FTireAclMin, const float32 FTireAclMax, const boolean_T PlanArcLength, calOptOutTypeV4* Outputs, const float32 PH_VisLength, const float32 PH_Traj, const boolean_T CheckCollCridr, const boolean_T CheckCollObj, const calOptInTypeV3* Inputs, const float32 CrvChng, const float32 AllwdJerkMax, const boolean_T CheckJerk, const boolean_T CheckLaneCross)
{
    boolean_T matrixInvertible;
    boolean_T StatusPotVecCheck, FTireAclMinOk, FTireAclMaxOk;
    boolean_T StatusCollCheckCridr, CollCheckRightOk, CollCheckLeftOk, StatusCollCheckObj;
    boolean_T StatusLaneCrossCheck;
    boolean_T StatusTrajPlan;
    float32 curTolerance;
    float32 curParams[6];
    float32 Ax[3][3];
    float32 Bx[3];
    float32 curCost, tmpAmax;
    uint8 i,j;
    boolean_T StatusJerkCheck;
    float32 JerkMax;

    /* Initialisierung der Variablen */
    tmpAmax = 0.0f;
    JerkMax = 0.0f;
    StatusPotVecCheck       = true;
    StatusCollCheckCridr    = true;
    StatusCollCheckObj      = true;
    FTireAclMinOk           = true;
    FTireAclMaxOk           = true;
    CollCheckRightOk        = true;
    CollCheckLeftOk         = true;
    StatusJerkCheck         = true;
    StatusLaneCrossCheck    = true;

    curTolerance = dz_new - dz_original;
    for( i=0; i<3; i++ )
    {
        Bx[i] = 0.0F;
        for( j=0; j<3; j++)
        {
            Ax[i][j] = 0.0F;
        }
    }

    /* Calculation of parameters p0, p1, p2 */
    curParams[0] = d_AW;
    curParams[1] = d_AWdot;
    curParams[2] = d_AWddot / 2;

    /* Calculation of parameters p3, p4, p5 */
    TrajCalc_CalcAxBx(Ax, Bx, curParams, te, dz_new, dz_dot, dz_ddot);
    matrixInvertible = TrajCalc_CalcParameters(curParams, Ax, Bx);

    /* Calculation of cost function */

    if( matrixInvertible != false) {
        curCost = TrajCalc_CalcCostFunction(curParams, te, Kd, Kt, dz_new, dz_original);
    }
    else {
        curCost = 99e+10F;
    }

    /* Check of limitations */
    if( (CheckFTire == true) && (matrixInvertible != false) ) {
        /* Check potential vector (friction value) */
        StatusPotVecCheck = TrajCalc_CheckPotVector(curParams, &tmpAmax, Kr, te, VehVelX, FTireAclMin, FTireAclMax, PlanArcLength, &FTireAclMinOk, &FTireAclMaxOk);
    }

    /* Jerk Check */
    if( (CheckJerk == true) && (matrixInvertible != false) ) {
        StatusJerkCheck = TrajCalc_CheckJerk(curParams, &JerkMax, CrvChng, te, VehVelX, AllwdJerkMax, PlanArcLength);
    }
    
    /* Check collision with corridor boundaries */
    if( (CheckCollCridr == true) && (matrixInvertible != false) ) {
        StatusCollCheckCridr = TrajCalc_CheckCollisionCorridor( PlanArcLength, PH_Traj, PH_VisLength, te, Inputs->sfunc_TrajCalcNumCridrPointsLeft_nu, Inputs->sfunc_TrajCalcCircleRadius_met, curParams, Inputs->sfunc_TrajCalcDistYLeft_met, &CollCheckRightOk, &CollCheckLeftOk);
    }

    /* Check collision with object */
    if( (CheckCollObj == true) && (matrixInvertible != false) && (PlanArcLength == false) ) {
        StatusCollCheckObj = TrajCalc_CheckCollisionObject(Inputs->sfunc_TrajCalcDeadTime_sec, Inputs->sfunc_TrajCalcTrajVel_mps, Inputs->sfunc_TrajCalcTrajAcl_mps2, Inputs->sfunc_TrajCalcObjVelX_mps, Inputs->sfunc_TrajCalcObjAclX_mps2, Inputs->sfunc_Obstacle_DistX_met, Inputs->sfunc_Obstacle_DistY_met, Inputs->sfunc_Obstacle_Width_met, Inputs->sfunc_TrajCalcCircleRadius_met, PH_VisLength, te, curParams);
    }
    
    /* Lane crossing check */
    if( (CheckLaneCross == true) && (matrixInvertible != false) && (PlanArcLength == false) ) {
        StatusLaneCrossCheck = TrajCalc_CheckLaneCross(PH_VisLength, te, Inputs->sfunc_VehicleWidth_met, curParams, Inputs->sfunc_AllowedTimetoCross_sec, Inputs->sfunc_LaneWidth_met);
    }    

    /* Select optimum trajectory */
    if( (StatusPotVecCheck == true) && (StatusCollCheckCridr == true) && (StatusCollCheckObj == true) && (StatusJerkCheck == true) && (StatusLaneCrossCheck == true) && (matrixInvertible != false) )
    {
        StatusTrajPlan = true;
    }
    else
    {
        StatusTrajPlan = false;
    }

    if( Outputs->sfunc_TrajStatus_nu == true )
    {
        if(StatusTrajPlan == true)
        {
            if( curCost < Outputs->sfunc_OptimalCost_nu) {
                *NewBestPoint = true;
            }
            else
            {
                *NewBestPoint = false;
            }
        }
        else
        {
            *NewBestPoint = false;
        }
    }
    else
    {
        if( StatusTrajPlan == true )
        {
            *NewBestPoint = true;
        }
        else
        {
            if( curCost < Outputs->sfunc_OptimalCost_nu) {
                *NewBestPoint = true;
            }
            else
            {
                *NewBestPoint = false;
            }
        }
    }

    if(*NewBestPoint == true)
    {
        uint8 iter;
        for(iter = 0; iter < 6; iter++ ) {
            Outputs->sfunc_TrajParam_nu[iter] = curParams[iter];
        }
        if(PlanArcLength == true) {
            Outputs->sfunc_ArcLengthTrajEnd_met = te;
        }
        else {
            Outputs->sfunc_TrajCalcTimeTrajEnd_sec = te;
        }
        Outputs->sfunc_MaxAclTraj_mps2 = tmpAmax;
        Outputs->sfunc_OptimalCost_nu = curCost;
        Outputs->sfunc_OptimalTolerance_nu = curTolerance;
        Outputs->sfunc_TrajStatus_nu = StatusTrajPlan;
        Outputs->sfunc_FtireMinOK_nu = FTireAclMinOk;
        Outputs->sfunc_FtireMaxOK_nu = FTireAclMaxOk;
        Outputs->sfunc_CollDetRightOK_nu = CollCheckRightOk;
        Outputs->sfunc_CollDetLeftOK_nu = CollCheckLeftOk;
        Outputs->sfunc_CollDetObjOK_nu = StatusCollCheckObj;
        Outputs->sfunc_MaxJerkTraj_mps3 = JerkMax;
        Outputs->sfunc_MaxJerkOK_nu = StatusJerkCheck;
        Outputs->sfunc_LaneCrossOK_nu = StatusLaneCrossCheck;
    }

    if( Outputs->sfunc_MatrixInverseOK_nu == false)
    {
        Outputs->sfunc_MatrixInverseOK_nu = matrixInvertible;
    }
}

float32 TrajCalc_MinFloat(const float32 A, const float32 B)
{
    float32 C;
    if(A>=B)
    {
        C = B;
    }
    else
    {
        C = A;
    }
    return C;
}

#define STOP_SEC_CODE


/*-------------------------------------------------------------------------------------------*
  END OF FILE
 *-------------------------------------------------------------------------------------------*/
/* PRQA S 0862 EOF */
