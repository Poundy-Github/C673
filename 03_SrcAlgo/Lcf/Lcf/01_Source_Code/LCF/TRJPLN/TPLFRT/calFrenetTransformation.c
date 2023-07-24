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
            12.07.2018      QiZh        Adaption of v_Traj and a_Traj
<NEW>
</NEW>
</HISTORY>

*********************************************************************/

/* -----------------------------------------------------------------------------

    I N C L U D E S

 * -----------------------------------------------------------------------------
*/
#include "calFrenetTransformation.h"

/* -----------------------------------------------------------------------------

    D E C L A R A T I O N   F U N C T I O N S

 * -----------------------------------------------------------------------------
*/

#define START_SEC_CODE

/* -----------------------------------------------------------------------------
    M I S R A
 *__________________________________________
*/

/* -----------------------------------------------------------------------------

    F U N C T I O N S

 * -----------------------------------------------------------------------------
*/


void TrajCalc_FT_InitializeOutputs(calFTOutType* Outputs) {
    uint8 i, j;
    for(i=0; i<15; i++) {
        Outputs->sf_TgtDistY_met[i] = 99.0F;
        Outputs->sf_TgtDistY1stDeriv_nu[i] = 99.0F;
        Outputs->sf_TgtDistY2ndDeriv_nu[i] = 99.0F;
        Outputs->sf_TgtPoints_nu[i] = 99.0F;
        Outputs->sf_CridrRight_Crv_1pm[i] = 0.0F;
    }
    
    for(j=0; j<100; j++) {
        Outputs->sf_DistYLeft_met[j] = 99.0F;
    }
    Outputs->sf_DistYCurValue_met = 0.0F;
    Outputs->sf_DistY1stDerivCurValue_nu = 0.0F;
    Outputs->sf_DistY2ndDerivCurValue_nu = 0.0F;
    Outputs->sf_TrajVel_mps = 0.0F;
    Outputs->sf_TrajAcl_mps2 = 0.0F;
    Outputs->sf_TrajDistYPrevious_met = 0.0F;                   
    Outputs->sf_TrajDistYPrev1stDeriv_nu = 0.0F;         
    Outputs->sf_TrajDistYPrev2ndDeriv_nu = 0.0F;         
    Outputs->sf_NumTgtPoints_nu = 0;
    Outputs->sf_TrajPlanningHorizon_sec = 0.0F;
    Outputs->sf_PlanHorizonVisRange_sec = 0.0F;
    Outputs->sf_2ndDerivDevHeading_nu = 0.0F;
    Outputs->sf_1stDerivDevHeading_nu = 0.0F;
    Outputs->sf_DstYCurValuePreview_met = 0.0f;
    Outputs->sf_DstY1stDrvCurValPrvw_mps = 0.0f;
    Outputs->sf_FrenTrafHeadingPrvw_sec = 0.0f;
    Outputs->sf_NumPointsCridrLeft_nu = 0;
    Outputs->sf_NumPointsCridrRight_nu = 0;
}

void TrajCalc_FT_InitializeIntVectors(float32 A[61], float32 B[61], float32 C[61], float32 D[61]){
    uint8 indx;
    for(indx = 0; indx < 61; indx++) {
        A[indx] = 0.0f;
        B[indx] = 0.0f;
        C[indx] = 0.0f;
        D[indx] = 0.0f;
    }
}

void TrajCalc_FT_TransformCurValues(const boolean_T PlanArcLength, const float32 DevDistY, const float32 DevHeading, const float32 Vx, const float32 Ax, const float32 Kr, const float32 Kr_prime, const float32 Kist, float32* dist, float32* dist1stDeriv, float32* dist2ndDeriv, float32* v_traj, float32* a_traj, float32 CurHdngAndDelta, float32* DeltaHdng1stDeriv, float32* DeltaHdng2ndDeriv, float32 Kstart, float32 Ksoll){
    
    float32 OneminusKrd, CosDeltathetaCur, SinDeltathetaCur, TanDeltathetaCur, dist_prime, temp_1, v_traj_2, CosDeltathetaCur_2; 
    float32 CosHeadingCurAndDeltaHdg, SinHeadingCurAndDeltaHdg, TanHeadingCurAndDeltaHdg, dist_primeHeadingCurAndDeltaHdg, CosHeadingCurAndDeltaHdg_2;
    
    /* \DOORS 2852 */
    *dist = DevDistY;
    
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 3 */
    CosDeltathetaCur = TrajCalc_FT_AvoidZero((float32)FD_COS(DevHeading));
    SinDeltathetaCur = (float32)FD_SIN(DevHeading);
    TanDeltathetaCur = (float32)FD_TAN(DevHeading);
    CosDeltathetaCur_2 = CosDeltathetaCur*CosDeltathetaCur;

    /* Control error Heading */
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 3 */
    CosHeadingCurAndDeltaHdg = TrajCalc_FT_AvoidZero((float32)FD_COS(CurHdngAndDelta));
    SinHeadingCurAndDeltaHdg = (float32)FD_SIN(CurHdngAndDelta);
    TanHeadingCurAndDeltaHdg = (float32)FD_TAN(CurHdngAndDelta);
    CosHeadingCurAndDeltaHdg_2 = CosHeadingCurAndDeltaHdg * CosHeadingCurAndDeltaHdg;

    /* Temporary values: (1-Kr*d) */
    OneminusKrd = 1.0F - ( Kr*(*dist) );
    
    OneminusKrd = TrajCalc_FT_AvoidZero(OneminusKrd);
    
    /* \DOORS 2858 */
    *v_traj = (Vx * CosDeltathetaCur) / OneminusKrd;        
    temp_1 = CosDeltathetaCur / OneminusKrd;

    /* \DOORS 9616 */
    dist_prime = OneminusKrd * TanDeltathetaCur;

    /* Control error Heading */
    dist_primeHeadingCurAndDeltaHdg = OneminusKrd * TanHeadingCurAndDeltaHdg;
    v_traj_2 = (*v_traj) * (*v_traj); 

    /* \DOORS 3534 */
    *a_traj =   temp_1 * (Ax - ( (v_traj_2 / CosDeltathetaCur) * ( (dist_prime * ((Kist / temp_1) - Kr)) - ( (Kr_prime*(*dist)) + (Kr * dist_prime)) ) ));
    
    /*
     * Arc length based planning
     */
    if( PlanArcLength == true){
        /* \DOORS 9616 */
        *dist1stDeriv = dist_prime;

        /* \DOORS 9617 */
        *dist2ndDeriv = ((-((Kr_prime * (*dist)) + (Kr * (*dist1stDeriv)))) * TanDeltathetaCur) + ((OneminusKrd / CosDeltathetaCur_2) * (((OneminusKrd / CosDeltathetaCur) * Kstart) - Kr));

        /* Control error Heading */
        *DeltaHdng1stDeriv = dist_primeHeadingCurAndDeltaHdg;
        *DeltaHdng2ndDeriv = ((-((Kr_prime * (*dist)) + (Kr * (*DeltaHdng1stDeriv)))) * TanHeadingCurAndDeltaHdg) + ((OneminusKrd / CosHeadingCurAndDeltaHdg_2) * (((OneminusKrd / CosHeadingCurAndDeltaHdg) * Ksoll) - Kr));
    }
    /*
     * Time based planning
     */
    else
    {
        /* \DOORS 9616 */
        *dist1stDeriv = Vx*SinDeltathetaCur;

        /* \DOORS 9617 */
        *dist2ndDeriv = (Ax * SinDeltathetaCur) + ((Vx * CosDeltathetaCur) * ((Kstart * Vx) - (Kr * (*v_traj))));

        /* Control error Heading */
        *DeltaHdng1stDeriv = Vx * SinHeadingCurAndDeltaHdg;
        *DeltaHdng2ndDeriv = (Ax * SinHeadingCurAndDeltaHdg) + ((Vx * CosHeadingCurAndDeltaHdg) * ((Ksoll * Vx) - (Kr * (*v_traj))));
    }  
}

void TrajCalc_FT_CalcStartPoint_ArcLength(float32* x_Start, float32* t_Start, float32* s_Start, float32* PlanAreaTgt, const float32 TgtSg1X, const float32 TgtSg1Length, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0){

     float32 Xi, Xi_pre, Si, Si_pre, deltaS, deltaSSmall, thetar_x_pre;
     uint8 i;
     boolean_T TgtSg1XFound;

     /* Initial Start points and intermediate values*/
     *x_Start = 0;
     *s_Start = 0;
     *PlanAreaTgt = 0;
     Si = 0;
     Xi = 0;
     i = 0;
     deltaS = 0.6f;
     deltaSSmall = 0.2f;
     TgtSg1XFound = false;
     Xi_pre = 0;
     Si_pre = 0;

     /* \DOORS 9280, 9281*/
     while( TgtSg1XFound==false ){
         Xi_pre = Xi;
         Si_pre = Si;
         Si = (float32)i * deltaS;
         thetar_x_pre =  TrajCalc_FT_Thetar(CridrRiSg1Heading, Kr, Kr_prime, Xi_pre, CridrRiSg1X, UseCridrRiX0);
         /* MISRA-AK: Math functions */
         /* PRQA S 4604,3335 1 */
         Xi = Xi_pre + ((Si - Si_pre)* (float32)FD_COS(thetar_x_pre));

         /* To avoid endless go at most up to 70m */
         if( (Xi >= TgtSg1X) || (Xi >= 70.0f) ){
             TgtSg1XFound = 1;
         }
         else
         {
             i++;
         }
     } // ----> End while(!TgtSg1XFound)

     /* MISRA-AK: Math functions */
     /* PRQA S 4604,3335 1 */
     if( (float32)FD_FABS(Xi - TgtSg1X)<= 0.0001f )
     {
         *s_Start = Si;
         *x_Start = TgtSg1X;
         *PlanAreaTgt = (*x_Start) + TgtSg1Length;
     }
     else if( Xi > TgtSg1X)    
     {
         /* \DOORS 9378 Go back one step and search with smaller step size */
         TgtSg1XFound = false;
         Xi = Xi_pre;
         Si = Si_pre;
         while( TgtSg1XFound == false ){
             Xi_pre = Xi;
             Si_pre = Si;
             Si = Si + deltaSSmall;
             thetar_x_pre =  TrajCalc_FT_Thetar(CridrRiSg1Heading, Kr, Kr_prime, Xi_pre, CridrRiSg1X, UseCridrRiX0);
             /* MISRA-AK: Math functions */
             /* PRQA S 4604,3335 1 */
             Xi = Xi_pre + ((Si - Si_pre)* (float32)FD_COS(thetar_x_pre));

             /* To avoid endless go at most up to 70m */
             if( (Xi >= TgtSg1X) || (Xi >= 70.0f) ){
                 TgtSg1XFound = 1;
             }
         }
         *s_Start = Si;
         *x_Start = Xi ;
         *PlanAreaTgt = (*x_Start) + TgtSg1Length;
     }
     else           //
     {
         *s_Start = Si;
         *x_Start = Xi;
         *PlanAreaTgt = (*x_Start) + TgtSg1Length;
     }
     /* No time for arc-length based planning */
     *t_Start = 0.0f;
}

void TrajCalc_FT_CalcStartPoint_Time(float32* x_Start, float32* t_Start, float32* s_Start, float32* PlanAreaTgt, const float32 v_traj, const float32 a_traj, const float32 TgtSg1X, const float32 TgtSg1Length, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0){

    float32 Xi, Xi_pre, Si, Si_pre, thetar_x_pre, deltaT,deltaTSmall, ti, temp, temp_2;
    uint8 i;
    boolean_T TgtSg1XFound;

    /* Initial start points and intermediate values */
    *x_Start = 0;
    *s_Start = 0;
    *t_Start = 0;
    *PlanAreaTgt = 0;
    Xi_pre = 0;
    Si_pre = 0;
    deltaT = 0.2f;
    deltaTSmall = 0.02f;
    Si = 0.0f;
    Xi = 0.0f;
    i = 1;
    TgtSg1XFound = false;
    ti = 0;

    /* \DOORS 9280, 9281*/
    while( TgtSg1XFound==false )
    {
        Xi_pre = Xi;
        Si_pre = Si;
        ti = deltaT * (float32)i;
        temp = TrajCalc_FT_MinFloat(1.0f,ti);
        temp_2 = temp* temp;
        Si = (v_traj*ti) + ((0.5f*a_traj)*temp_2);
        thetar_x_pre =  TrajCalc_FT_Thetar(CridrRiSg1Heading, Kr, Kr_prime, Xi_pre, CridrRiSg1X, UseCridrRiX0);
        /* MISRA-AK: Math functions */
        /* PRQA S 4604,3335 1 */
        Xi = Xi_pre + ((Si - Si_pre)* (float32)FD_COS(thetar_x_pre));

        /* To avoid endless go at most up to 70m */
        if( (Xi >= TgtSg1X) || (Xi >= 70.0f) ){
         TgtSg1XFound = 1;
        }
        else
        {
            i++;
        }
    }
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    if( (float32)FD_FABS(Xi - TgtSg1X)<= 0.0001f )
    {
        *s_Start = Si;
        *x_Start = TgtSg1X;
        *t_Start = deltaT * (float32)i;
        *PlanAreaTgt = (*x_Start) + TgtSg1Length;
    }
    else if( Xi > TgtSg1X )    
    {
        /* \DOORS 9378 Go back one step and search with smaller step size */
        TgtSg1XFound = false;
        Si = Si_pre;
        Xi = Xi_pre;
        ti = deltaT*(float32)(i-1);

        while( TgtSg1XFound == false){
            ti = ti + deltaTSmall;
            temp = TrajCalc_FT_MinFloat(1.0f,ti);
            temp_2 = temp* temp;
            Si = (v_traj*ti) + ((0.5f*a_traj)*temp_2);
            thetar_x_pre =  TrajCalc_FT_Thetar(CridrRiSg1Heading, Kr, Kr_prime, Xi_pre, CridrRiSg1X, UseCridrRiX0);
            /* MISRA-AK: Math functions */
            /* PRQA S 4604,3335 1 */
            Xi = Xi_pre + ((Si - Si_pre)*(float32)FD_COS(thetar_x_pre));

            /* To avoid endless go at most up to 70m */
            if( (Xi >= TgtSg1X) || (Xi >= 70.0f) ){
             TgtSg1XFound = 1;
            }
        }
        *s_Start = Si;
        *x_Start = Xi;
        *PlanAreaTgt = (*x_Start) + TgtSg1Length;
        *t_Start = ti;
    }
    else            //
    {
     *s_Start = Si;
     *x_Start = Xi;
     *PlanAreaTgt = (*x_Start) + TgtSg1Length;
     *t_Start = ti;
    }
}

void TrajCalc_FT_CalcTargetCurvePoints(const boolean_T PlanArcLength, const float32 TgtSg1X, const float32 TgtSg1Length, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 PlanHorizon, const float32 CridrRiSg1Length, const float32 TgtTrajSg1Y, const float32 TgtTrajSg1Hdng, const float32 TgtTrajSg1Crv, const float32 TgtTrajSg1ChngOfCrv, const float32 v_traj, const float32 a_traj, calFTOutType* Outputs, const boolean_T UseTgtTrajX0, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Y){

     float32 x_Start, t_Start, s_Start, PlanAreaTgt;
     float32 TrajPlanHorizon, PlanHorizonVisRange;
     float32 TgtDistYPoint[61], TgtDistY1stDerivPoint[61], TgtDistY2ndDerivPoint[61], TgtPoints[61];
     uint8 i, NumTgtPoints, VectorLength;
     float32 ZieltrajSg1YNew, ZieltrajSg1HeadingNew, ZieltrajSg1KruemmungNew;
     TrajCalc_FT_InitializeIntVectors(TgtDistYPoint, TgtDistY1stDerivPoint, TgtDistY2ndDerivPoint, TgtPoints);

     /* Initial start points and intermediate values */
     x_Start = 0;
     t_Start = 0;
     s_Start = 0;
     PlanAreaTgt = 0;
     NumTgtPoints = 0;
     VectorLength = 15;

     /* \DOORS 9280 if long distance less than zero no need to continue search */
     if( TgtSg1X <= 0){
         x_Start = 0;
         t_Start = 0;
         s_Start = 0;
         PlanAreaTgt = TgtSg1Length;
     }
     else
     {

        if ( PlanArcLength == true ){
            /* \DOORS 12950 arc length based: Calculate start point for trajectory */
            TrajCalc_FT_CalcStartPoint_ArcLength(&x_Start, &t_Start, &s_Start, &PlanAreaTgt, TgtSg1X, TgtSg1Length, CridrRiSg1Heading, Kr, Kr_prime, CridrRiSg1X, UseCridrRiX0);
        }
        else {
            /* \DOORS 12950 time based: Calculate start point for trajectory */
            TrajCalc_FT_CalcStartPoint_Time(&x_Start, &t_Start, &s_Start, &PlanAreaTgt, v_traj, a_traj, TgtSg1X, TgtSg1Length, CridrRiSg1Heading, Kr, Kr_prime, CridrRiSg1X, UseCridrRiX0);
        }
     }
     /* Correction of target trajectory X0 */
    if(UseTgtTrajX0 == true)
    {
        ZieltrajSg1YNew = TrajCalc_FT_Y(TgtTrajSg1Y, TgtTrajSg1Hdng, TgtTrajSg1Crv, TgtTrajSg1ChngOfCrv, x_Start, TgtSg1X);
        ZieltrajSg1HeadingNew = TrajCalc_FT_Theta(TgtTrajSg1Hdng, TgtTrajSg1Crv, TgtTrajSg1ChngOfCrv, x_Start, TgtSg1X);
        ZieltrajSg1KruemmungNew = TrajCalc_FT_K(TgtTrajSg1Crv, TgtTrajSg1ChngOfCrv, x_Start, TgtSg1X);
    }
    else
    {
        ZieltrajSg1YNew = TgtTrajSg1Y;
        ZieltrajSg1HeadingNew = TgtTrajSg1Hdng;
        ZieltrajSg1KruemmungNew = TgtTrajSg1Crv;
    }

    if ( PlanArcLength == true ) {
        /* \DOORS 12951 arc length based: Calculate target lateral distances and derivatives */
        TrajCalc_FT_CalcTargetCurve_ArcLength(&NumTgtPoints, TgtPoints, TgtDistYPoint, TgtDistY1stDerivPoint, TgtDistY2ndDerivPoint, &TrajPlanHorizon, &PlanHorizonVisRange, x_Start, s_Start, CridrRiSg1Heading, Kr, Kr_prime, CridrRiSg1Length, PlanAreaTgt, ZieltrajSg1YNew, ZieltrajSg1HeadingNew, ZieltrajSg1KruemmungNew, TgtTrajSg1ChngOfCrv, v_traj, CridrRiSg1X, UseCridrRiX0, CridrRiSg1Y);
    }
    else {
        /* \DOORS 12951 time based: Calculate target lateral distances and derivatives */
        TrajCalc_FT_CalcTargetCurve_Time(&NumTgtPoints, TgtPoints, TgtDistYPoint, TgtDistY1stDerivPoint, TgtDistY2ndDerivPoint, &TrajPlanHorizon, &PlanHorizonVisRange, x_Start, s_Start, t_Start, CridrRiSg1Heading, Kr, Kr_prime, CridrRiSg1Length, PlanAreaTgt, ZieltrajSg1YNew, ZieltrajSg1HeadingNew, ZieltrajSg1KruemmungNew, TgtTrajSg1ChngOfCrv, v_traj, a_traj, PlanHorizon, CridrRiSg1X, UseCridrRiX0, CridrRiSg1Y);
    }

    /* \DOORS 9224 */
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    Outputs->sf_NumTgtPoints_nu = (uint8)FD_CEIL( (float32)NumTgtPoints / 2.0  );
    /* \DOORS 9572 */
    Outputs->sf_TrajPlanningHorizon_sec = TrajPlanHorizon;
    /* \DOORS 9572 */
    Outputs->sf_PlanHorizonVisRange_sec = PlanHorizonVisRange;

    /* Always send last 15 points. */
    /* \DOORS 9573 */
    /* \DOORS 9582 */

    /* If NumTgtPoints <= VectorLength : */
    if(Outputs->sf_NumTgtPoints_nu <= VectorLength)
    {
        for( i = 0; i < Outputs->sf_NumTgtPoints_nu; i++)
        {
            Outputs->sf_TgtDistY_met[i] = TgtDistYPoint[2*i];
            Outputs->sf_TgtDistY1stDeriv_nu[i] = TgtDistY1stDerivPoint[2*i];
            Outputs->sf_TgtDistY2ndDeriv_nu[i] = TgtDistY2ndDerivPoint[2*i];
            Outputs->sf_TgtPoints_nu[i] = TgtPoints[2*i];
        }
    }
    /* If NumTgtPoints > VectorLength : */
    else
    {
        uint8 rest, index;
        rest = Outputs->sf_NumTgtPoints_nu - VectorLength;
        for( i = 0; i < VectorLength; i++)
        {
            index = rest + i;
            Outputs->sf_TgtDistY_met[i] = TgtDistYPoint[2*index];
            Outputs->sf_TgtDistY1stDeriv_nu[i] = TgtDistY1stDerivPoint[2*index];
            Outputs->sf_TgtDistY2ndDeriv_nu[i] = TgtDistY2ndDerivPoint[2*index];
            Outputs->sf_TgtPoints_nu[i] = TgtPoints[2*index];
        }
        Outputs->sf_NumTgtPoints_nu = VectorLength;
    }
}

void TrajCalc_FT_CalcTargetCurve_Time(uint8* NumTgtPoints, float32 TgtPoints[61], float32 TgtDistYPoint[61], float32 TgtDistY1stDerivPoint[61], float32 TgtDistY2ndDerivPoint[61], float32* PlanHorizonFT, float32* PlanHorizonVisRange, const float32 x_Start, const float32 s_Start, const float32 t_Start, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 CridrRiSg1Length, const float32 PlanAreaTgt, const float32 TgtTrajSg1Y, const float32 TgtTrajSg1Hdng, const float32 TgtTrajSg1Crv, const float32 TgtTrajSg1ChngOfCrv, const float32 v_traj, const float32 a_traj, const float32 PlanHorizon, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Y)
{
    float32 Xi, Xi_pre, Si, Si_pre, thetar_x_pre, DeltaT, Sti_dot, ti, tmax, tmpPlanHorizon, temp1, temp2;
    uint8 i;
    boolean_T PlanningEnd;
    boolean_T LengthEnd;
    float32 TgtDistY,TgtDistY_prime, TgtDistY_primeprime;
    float32 temp;
    float32 minFT_t1;

    /* Initial start points and intermediate values */
    temp = 0;
    *NumTgtPoints = 0;
    *PlanHorizonVisRange = 0;
    *PlanHorizonFT = 0;
    PlanningEnd = false;
    LengthEnd = false;
    DeltaT = 0.1f;
    i = 0;
    Xi = x_Start;
    Si = s_Start;

    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    temp2 = (float32)FD_FABS(TrajCalc_FT_MinFloat(PlanAreaTgt, CridrRiSg1Length));

    /* \DOORS 10646 tmax */
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    tmpPlanHorizon = (float32)FD_FLOOR( (float32)(PlanHorizon / ( 2.0f * DeltaT ) ) ) * ( 2.0f * DeltaT );
    tmax = tmpPlanHorizon + t_Start;

    /* \DOORS 10646 */
    while( PlanningEnd == false)
    {
        Xi_pre = Xi;
        Si_pre = Si;
        thetar_x_pre = TrajCalc_FT_Thetar(CridrRiSg1Heading, Kr, Kr_prime, Xi_pre, CridrRiSg1X, UseCridrRiX0);
        ti = t_Start + (DeltaT*(float32)i);

        TgtPoints[i] = ti;

        minFT_t1 = TrajCalc_FT_MinFloat(1,ti);
        Sti_dot = v_traj + (a_traj*minFT_t1);
        Si = (v_traj*ti) + ((0.5f*a_traj)*(minFT_t1 * minFT_t1));
        /* MISRA-AK: Math functions */
        // PRQA S 4604,3335 2
        Xi = Xi_pre + ((Si - Si_pre)*(float32)FD_COS(thetar_x_pre));
        temp1 = (float32)FD_FABS(x_Start);
        if( (( temp1 < 0.000001f) && ( temp2 < 0.000001f)) || (i > 59)  )   // i > 59
        {
            LengthEnd = true;
        }

        if( LengthEnd != true )
        {
            /* \DOORS 5286  d_Tgt */
            /* \DOORS 5287  d_Tgtprime */
            /* \DOORS 5287  d_Tgtprimeprime */
            TrajCalc_FT_CalcLatDistDerivs(&TgtDistY_prime, &TgtDistY_primeprime, &TgtDistY, Xi, CridrRiSg1Heading, Kr, Kr_prime, TgtTrajSg1Y, TgtTrajSg1Hdng,TgtTrajSg1Crv, TgtTrajSg1ChngOfCrv,x_Start, CridrRiSg1X, UseCridrRiX0, CridrRiSg1Y);

            /* \DOORS 5286  d_Tgt */
            TgtDistYPoint[i] = TgtDistY;
            /* \DOORS 5287  d_Tgtpunkt */
            TgtDistY1stDerivPoint[i] = TgtDistY_prime * Sti_dot;
            /* \DOORS 5344  d_Tgtpunktpunkt */
            TgtDistY2ndDerivPoint[i] = (a_traj * TgtDistY_prime) + (Sti_dot * Sti_dot * TgtDistY_primeprime);
            *NumTgtPoints = i+1;
            *PlanHorizonVisRange = ti;
            temp = ti;
        }

        /* \DOORS 10646 End condition */
        if( Xi >= TrajCalc_FT_MinFloat(PlanAreaTgt, CridrRiSg1Length))
        {
            LengthEnd = true;
        }

        /* \DOORS 9610 */
        if( LengthEnd == true )
        {
            if(i > 0)
            {
                TgtDistYPoint[i] = TgtDistYPoint[i-1];
                TgtDistY1stDerivPoint[i] = 0;
                TgtDistY2ndDerivPoint[i] = 0;
                *NumTgtPoints = i+1;
                *PlanHorizonVisRange = temp - DeltaT;
            }
        }

        /* \DOORS 10646 End condition */
        if( ((tmax - ti) >= 0.000001) && (i < 60) )                   
        {
            i = i + 1 ;
        }
        else
        {
            PlanningEnd = true;
        }

        /* \DOORS 9572 */
        *PlanHorizonFT = tmpPlanHorizon + t_Start;
    }
}

void TrajCalc_FT_CalcTargetCurve_ArcLength(uint8*  NumTgtPoints, float32 TgtPoints[61], float32 TgtDistYPoint[61], float32 TgtDistY1stDerivPoint[61], float32 TgtDistY2ndDerivPoint[61], float32* PlanHorizonFT, float32* PlanHorizonVisRange, const float32 x_Start, const float32 s_Start, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 CridrRiSg1Length, const float32 PlanAreaTgt, const float32 TgtTrajSg1Y, const float32 TgtTrajSg1Hdng, const float32 TgtTrajSg1Crv, const float32 TgtTrajSg1ChngOfCrv, float32 v_traj, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Y)
{
    float32 Xi, Xi_pre, Si, Si_pre, thetar_x_pre, DeltaS, temp1, temp2;
    uint8 i;
    boolean_T PlanningEnd;
    float32 TgtDistY_prime, TgtDistY_primeprime, TgtDistY;

    /* Initial start points and intermediate values */
    *NumTgtPoints = 0;
    *PlanHorizonVisRange = 0;
    *PlanHorizonFT = 0;
    PlanningEnd = false;

    /* \DOORS 10646 Dynamic step for arc length based planning */
    DeltaS = v_traj * 0.1f;         // delta_S = Bahngeschwindigkeit * delta_t
    DeltaS = TrajCalc_FT_MaxFloat(DeltaS, 0.2f);

    i = 0;
    Xi = x_Start;
    Si = s_Start;
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    temp2 = (float32)FD_FABS(TrajCalc_FT_MinFloat(PlanAreaTgt, CridrRiSg1Length));
    while( PlanningEnd == false )
    {
        Xi_pre = Xi;
        Si_pre = Si;
        thetar_x_pre = TrajCalc_FT_Thetar(CridrRiSg1Heading, Kr, Kr_prime, Xi_pre, CridrRiSg1X, UseCridrRiX0);
        Si = s_Start + ((float32)i*DeltaS);

        TgtPoints[i] = Si;
        /* MISRA-AK: Math functions */
        /* PRQA S 4604,3335 1 */
        Xi = Xi_pre + ((Si - Si_pre)*(float32)FD_COS(thetar_x_pre));

        /* \DOORS 9572 PlanHorizonFT, PlanHorizonVisRange*/
        *PlanHorizonFT = Si;
        *PlanHorizonVisRange = Xi;
        temp1 = (float32)fabs(x_Start);
        if( ( ( temp1 < 0.000001f )&&( temp2 < 0.000001f ) ))
        {
            PlanningEnd = true;
        }
        else
        {
            /* \DOORS 5286  TgtDistY */
            /* \DOORS 5287  TgtDistY_prime */
            /* \DOORS 5287  TgtDistY_primeprime */
            TrajCalc_FT_CalcLatDistDerivs(&TgtDistY_prime, &TgtDistY_primeprime, &TgtDistY, Xi, CridrRiSg1Heading, Kr, Kr_prime, TgtTrajSg1Y, TgtTrajSg1Hdng,TgtTrajSg1Crv, TgtTrajSg1ChngOfCrv, x_Start, CridrRiSg1X, UseCridrRiX0, CridrRiSg1Y);
            /* \DOORS 5286  TgtDistY */
            TgtDistYPoint[i] = TgtDistY;
            /* \DOORS 5287  TgtDistY Dot */
            TgtDistY1stDerivPoint[i] = TgtDistY_prime;
            /* \DOORS 5287  TgtDistY Dot Dot */
            TgtDistY2ndDerivPoint[i] = TgtDistY_primeprime;
            *NumTgtPoints = i+1;
        }
        /* \DOORS 10646 End condition */
        if( (Xi >= TrajCalc_FT_MinFloat(PlanAreaTgt, CridrRiSg1Length)) || (i>=60))        // JIRA:FASSIEBEN-9367: Korrektur Berechnung letzter Zielpunkt
        {
            PlanningEnd = true;
        }
        i++;
    }
}

void TrajCalc_FT_CalcLatDistDerivs(float32* dTgt_prime, float32* dTgt_primeprime, float32* TgtDistYPoint, const float32 Xi, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 TgtTrajSg1Y, const float32 TgtTrajSg1Hdng, const float32 TgtTrajSg1Crv, const float32 TgtTrajSg1ChngOfCrv, const float32 X0, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Y)
{
    float32 Thetar_Xi, Yr_Xi, Kr_Xi;
    float32 Yziel_Xi, ThetaZiel_Xi, Kziel_Xi;

    float32 deltaTheta_RefTgt, CosdeltaTheta_RefTgt, deltaY_RefTgt, temp_3;

    /* \DOORS 9568 */
    Thetar_Xi = TrajCalc_FT_Thetar(CridrRiSg1Heading, Kr, Kr_prime, Xi, CridrRiSg1X, UseCridrRiX0);
    Yr_Xi = TrajCalc_FT_Yr(CridrRiSg1Y, CridrRiSg1Heading, Kr, Kr_prime, Xi, CridrRiSg1X, UseCridrRiX0);
    Kr_Xi = TrajCalc_FT_K(Kr, Kr_prime, Xi, CridrRiSg1X);

    /* \DOORS 5270 */
    Yziel_Xi = TrajCalc_FT_Y(TgtTrajSg1Y, TgtTrajSg1Hdng, TgtTrajSg1Crv, TgtTrajSg1ChngOfCrv, Xi, X0);
    ThetaZiel_Xi = TrajCalc_FT_Theta(TgtTrajSg1Hdng, TgtTrajSg1Crv, TgtTrajSg1ChngOfCrv, Xi, X0);
    Kziel_Xi = TrajCalc_FT_K(TgtTrajSg1Crv, TgtTrajSg1ChngOfCrv, Xi, X0);

    /* \DOORS 5271 */
    deltaTheta_RefTgt = ThetaZiel_Xi - Thetar_Xi;
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    CosdeltaTheta_RefTgt = TrajCalc_FT_AvoidZero( (float32)FD_COS(deltaTheta_RefTgt) );                                       // Änderung 17.02.2014 Vermeidung Division durch NULL
    deltaY_RefTgt = Yziel_Xi - Yr_Xi;

    /* \DOORS 5286 d_Ziel */
    if( (Thetar_Xi * ThetaZiel_Xi) > 0 )
    {
         /* MISRA-AK: Math functions */
         /* PRQA S 4604,3335 1 */
        *TgtDistYPoint = (deltaY_RefTgt * (float32)FD_COS(ThetaZiel_Xi)) / CosdeltaTheta_RefTgt;          // Änderung 17.02.2014 Vermeidung Division durch NULL
    }
    else
    {
         /* MISRA-AK: Math functions */
         /* PRQA S 4604,3335 1 */
        *TgtDistYPoint = (deltaY_RefTgt * (float32)FD_COS(ThetaZiel_Xi)) / TrajCalc_FT_AvoidZero( (float32)FD_COS( (float32)FD_FABS(ThetaZiel_Xi) + (float32)FD_FABS(Thetar_Xi) ) );
    }

    /* \DOORS 5286 d_Zielprime */
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    *dTgt_prime = (1- (Kr_Xi * (*TgtDistYPoint))) * (float32)FD_TAN(deltaTheta_RefTgt);
    temp_3 = (1.0F - (Kr_Xi * (*TgtDistYPoint))) / CosdeltaTheta_RefTgt;
    /* \DOORS 5287 d_Zielprimeprime */
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    *dTgt_primeprime = ((-((Kr_prime * (*TgtDistYPoint)) + (Kr_Xi * (*dTgt_prime)))) * (float32)FD_TAN(deltaTheta_RefTgt)) + ((temp_3 / CosdeltaTheta_RefTgt) * ((temp_3 * Kziel_Xi) - Kr_Xi));
}

void TrajCalc_FT_CalcTrajLastCycle(float32* FT_DistYTrajPrev, float32* FT_DistYTrajPrev_dot, float32* FT_DistYTrajPrev_ddot, const float32 DistYTrajPrev, const float32 HdngTrajPrev, const boolean_T PlanArcLength, const float32 Kr, const float32 Kr_prime, const float32 Ktraj, const float32 vx, const float32 ax, float32* v_traj_Tgt, float32* a_traj_Tgt)
{
    float32 CosDeltathetaPrev, SinDeltathetaPrev, TanDeltathetaPrev;
    float32 OneminusKrd, dist_prime, temp_1, v_traj_Tgt_2; 
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 3 */
    CosDeltathetaPrev =  TrajCalc_FT_AvoidZero((float32)FD_COS((HdngTrajPrev)));
    SinDeltathetaPrev = (float32)FD_SIN((HdngTrajPrev));
    TanDeltathetaPrev = (float32)FD_TAN((HdngTrajPrev));

    /* \DOORS 9695 */
    *FT_DistYTrajPrev = DistYTrajPrev;
    
    /* Temporary values: (1-Kr*d) */
    OneminusKrd = 1.0F - (Kr * DistYTrajPrev);
    
    OneminusKrd = TrajCalc_FT_AvoidZero(OneminusKrd);
    
    /* velocity of the reference line based on target value*/
    *v_traj_Tgt = (vx * CosDeltathetaPrev) / OneminusKrd;        
    temp_1 = CosDeltathetaPrev / OneminusKrd;

    dist_prime = OneminusKrd * TanDeltathetaPrev;

    v_traj_Tgt_2 = (*v_traj_Tgt) * (*v_traj_Tgt); 
    /* acceleration of the reference line based on target value*/
    *a_traj_Tgt =   temp_1 * (ax - ( (v_traj_Tgt_2 / CosDeltathetaPrev) * ( (dist_prime * ((Ktraj / TrajCalc_FT_AvoidZero(temp_1)) - Kr)) - ( (Kr_prime * DistYTrajPrev) + (Kr * dist_prime)) ) ));
    
    if(PlanArcLength == true)
    {
        *FT_DistYTrajPrev_dot = (1 - (Kr * DistYTrajPrev)) * TanDeltathetaPrev;
        *FT_DistYTrajPrev_ddot = ((-((Kr_prime * DistYTrajPrev) + (Kr * (*FT_DistYTrajPrev_dot)))) * TanDeltathetaPrev) + (((1 - (Kr * DistYTrajPrev)) / (CosDeltathetaPrev * CosDeltathetaPrev)) * ((((1 - (Kr * DistYTrajPrev)) / CosDeltathetaPrev) * Ktraj) - Kr));
    }
    else
    {
        *FT_DistYTrajPrev_dot = vx*SinDeltathetaPrev;
        *FT_DistYTrajPrev_ddot = (ax * SinDeltathetaPrev) + ((vx * ((Ktraj * vx) - (Kr * (*v_traj_Tgt)))) * CosDeltathetaPrev);
    }
}

void TrajCalc_FT_CalcLeftCorridor(calFTOutType* Outputs, const float32 CridrRiSg1Crv, const float32 CridrRiSg1ChgOfCrv, const float32 CridrLeSg1Length, const float32 CridrRiSg1Length, const float32 CridrLeSg1Y,const float32 CridrLeSg1Hdng, const float32 CridrLeSg1Crv, const float32 CridrLeSg1ChgOfCrv, const float32 v_Traj, const float32 a_Traj, const boolean_T PlanArcLength, const float32 DeadTime, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Heading, const float32 CridrRiSg1Y, const float32 CridrLeSg1X)
{
    uint8 ind_Left;
    boolean_T CalcEnd;
    float32 SiLeft, XiLeft, SiLeft_pre, XiLeft_pre, Thetar_XiLeft_pre, Yr_XiLeft,Thetar_XiLeft,Yl_XiLeft,Thetal_XiLeft;
    float32 deltaTheta_Refl, CosdeltaTheta_Refl, deltaY_Refl;
    boolean_T StartPointFound;
    float32 t_LeftDeadTime, s_LeftDeadTime, x_LeftDeadTime, Thetar_x_LeftDeadTime, s_LeftDeadTime_pre, x_LeftDeadTime_pre, Thetar_x_LeftDeadTime_pre;
    float32 delta_t, delta_sec, StepsLeft;
    float32 minRunLength;

    /* Initialize intermediate values */
    CalcEnd = false;
    StartPointFound = false;
    delta_t = 0.05f;        /* in Seconds */
    minRunLength = TrajCalc_FT_MinFloat(CridrLeSg1Length,CridrRiSg1Length);

    /*
     * Calculation start point due to dead time
     * \DOORS 13055
     */
    s_LeftDeadTime = 0.0f;
    x_LeftDeadTime = 0.0f;
    t_LeftDeadTime  = 0.0f;
    Thetar_x_LeftDeadTime = TrajCalc_FT_Thetar(CridrRiSg1Heading, CridrRiSg1Crv, CridrRiSg1ChgOfCrv, 0.0f, CridrRiSg1X, UseCridrRiX0);
    while ( StartPointFound != true )
    {
        s_LeftDeadTime_pre = s_LeftDeadTime;
        s_LeftDeadTime = (t_LeftDeadTime * v_Traj) + ((0.5f * a_Traj) * (t_LeftDeadTime * t_LeftDeadTime));
        x_LeftDeadTime_pre = x_LeftDeadTime;
        Thetar_x_LeftDeadTime_pre = Thetar_x_LeftDeadTime;
        /* MISRA-AK: Math functions */
        /* PRQA S 4604,3335 1 */
        x_LeftDeadTime = x_LeftDeadTime_pre + ((s_LeftDeadTime - s_LeftDeadTime_pre) * (float32)FD_COS(Thetar_x_LeftDeadTime_pre));
        Thetar_x_LeftDeadTime = TrajCalc_FT_Thetar(CridrRiSg1Heading, CridrRiSg1Crv, CridrRiSg1ChgOfCrv, x_LeftDeadTime, CridrRiSg1X, UseCridrRiX0);
        if( t_LeftDeadTime >= DeadTime )
        {
            StartPointFound = true;
        }
        else
        {
            t_LeftDeadTime = t_LeftDeadTime + delta_t;
        }
    }

    /*
     *  Calculate left corridor
     *  \DOORS 12948
     */
    ind_Left = 1;
    delta_sec = 0.7f;         /* in Meters */
    SiLeft = s_LeftDeadTime;
    XiLeft = x_LeftDeadTime;
    Thetar_XiLeft = Thetar_x_LeftDeadTime;
    /*  \DOORS 12948 */
    while(CalcEnd != true) {

        SiLeft_pre = SiLeft;
        if(PlanArcLength == true)
        {
            SiLeft = SiLeft + delta_sec;
        }
        else
        {
            float32 min_t;
            StepsLeft = (float32)ind_Left * delta_t;
            min_t = TrajCalc_FT_MinFloat(StepsLeft, 1.0f - t_LeftDeadTime);         /* accelerate within 1s */
            SiLeft = s_LeftDeadTime + (StepsLeft * v_Traj) + ((0.5f * a_Traj) * (min_t * min_t));
        }
        XiLeft_pre = XiLeft;
        Thetar_XiLeft_pre = Thetar_XiLeft;
        /* MISRA-AK: Math functions */
        /* PRQA S 4604,3335 1 */
        XiLeft = XiLeft_pre + ((SiLeft - SiLeft_pre) * (float32)FD_COS(Thetar_XiLeft_pre));
        /*  \DOORS 12949 Yr, Thetar*/
        Yr_XiLeft = TrajCalc_FT_Yr(CridrRiSg1Y, CridrRiSg1Heading, CridrRiSg1Crv, CridrRiSg1ChgOfCrv, XiLeft, CridrRiSg1X, UseCridrRiX0);
        Thetar_XiLeft = TrajCalc_FT_Thetar(CridrRiSg1Heading, CridrRiSg1Crv, CridrRiSg1ChgOfCrv, XiLeft, CridrRiSg1X, UseCridrRiX0);

        if( XiLeft  >= minRunLength ) {
            CalcEnd = 1;        /* End loop */
            /* \DOORS 13111 */
            Outputs->sf_NumPointsCridrLeft_nu = ind_Left;
        }
        /*  \DOORS 10313 Yl, Thetal*/
        Yl_XiLeft  = TrajCalc_FT_Y(CridrLeSg1Y, CridrLeSg1Hdng, CridrLeSg1Crv, CridrLeSg1ChgOfCrv, XiLeft, CridrLeSg1X);
        Thetal_XiLeft = TrajCalc_FT_Theta(CridrLeSg1Hdng, CridrLeSg1Crv, CridrLeSg1ChgOfCrv, XiLeft, CridrLeSg1X);

        /*  \DOORS 5718 deltaTheta_Refl, deltaY_Refl */
        deltaTheta_Refl = Thetal_XiLeft - Thetar_XiLeft;
        /* MISRA-AK: Math functions */
        // PRQA S 4604,3335 2
        CosdeltaTheta_Refl = TrajCalc_FT_AvoidZero( (float32)FD_COS(deltaTheta_Refl) );
        deltaY_Refl = Yl_XiLeft - Yr_XiLeft;
        /*  \DOORS 5719 */
        if( (Thetar_XiLeft * Thetal_XiLeft) > 0 ) {
            /* MISRA-AK: Math functions */
            /* PRQA S 4604,3335 1 */
            Outputs->sf_DistYLeft_met[ind_Left - 1] = (deltaY_Refl * (float32)FD_COS(Thetal_XiLeft)) / CosdeltaTheta_Refl;
        }
        else {
            /* MISRA-AK: Math functions */
            /* PRQA S 4604,3335 1 */
            Outputs->sf_DistYLeft_met[ind_Left - 1] = (deltaY_Refl * (float32)FD_COS(Thetal_XiLeft)) / TrajCalc_FT_AvoidZero( (float32)FD_COS( (float32)FD_FABS(Thetal_XiLeft) + (float32)FD_FABS(Thetar_XiLeft) ) );
        }
        /*  \DOORS 12948 */
        if( ind_Left < 100) {
            ind_Left = ind_Left + 1;
        }
        else {
            CalcEnd = true;     /* End loop. Max. 100 points */
            /* \DOORS 13111 */
            Outputs->sf_NumPointsCridrLeft_nu = ind_Left;
        }
    }
}

calFTOutType calFrenetTransformation(const calFTInTypeV3* Inputs)
{
    calFTOutType Outputs;

    /* Initialize all output parameters */
    TrajCalc_FT_InitializeOutputs(&Outputs);
    
    /* DOORS 5424 */
    if(Inputs->sf_TrajPlanEnbl_nu == true)
    {
        boolean_T PlanArcLength;
        float32 DevY, DevTheta,Vx, Ax, Kr, Kr_prime, Kist, Kstart, Ksoll;

        float32 dist, dist1stDeriv, dist2ndDeriv, v_traj, a_traj;
        float32 DistYTrajPrev, DistYTrajPrev_dot, DistYTrajPrev_ddot;
        float32 FirstDerivDeltaHeading,SecondDerivDeltaHeading;
        float32 v_traj_Tgt, a_traj_Tgt;
        
        /* Initialize and intermediate values */
        a_traj = 0;
        v_traj = 0;
        dist = 0;
        dist1stDeriv = 0;
        dist2ndDeriv = 0;
        DistYTrajPrev = 0;
        DistYTrajPrev_dot = 0;
        DistYTrajPrev_ddot = 0;
        FirstDerivDeltaHeading = 0;
        SecondDerivDeltaHeading = 0;
        v_traj_Tgt = 0;
        a_traj_Tgt = 0;

        PlanArcLength = Inputs->sf_ReplanModeArcLength_nu;
        DevY = Inputs->sf_DevDistY_met;
        DevTheta = Inputs->sf_DevHeading_rad;
        Vx = Inputs->sf_EgoVelX_mps;
        Ax = Inputs->sf_EgoAclX_mps2;
        Kr = Inputs->sf_CridrRightSg1_Crv_1pm;
        Kr_prime = Inputs->sf_CridrRightSg1_ChOfCrv_1pm2;
        Kist = Inputs->sf_CurCrvVehMotion_1pm;
        Kstart = Inputs->sf_StartCrv_1pm;
        Ksoll = Inputs->sf_TgtCrvTrajPrev_1pm;

        /* \DOORS 5205 Transformation of current values to Frenet */
        TrajCalc_FT_TransformCurValues(PlanArcLength, DevY, DevTheta, Vx, Ax, Kr, Kr_prime, Kist, &dist, &dist1stDeriv, &dist2ndDeriv, &v_traj, &a_traj, Inputs->sf_CurHdngAndDeltaHdng_rad, &FirstDerivDeltaHeading, &SecondDerivDeltaHeading, Kstart, Ksoll);

        /* \DOORS 12952 Transformation of current value preview to Frenet */
        TrajCalc_FT_CalcPreviewCurValues(Inputs->sf_PreviewTimeHeading_sec, 0.0, Kr, Kr_prime, DevY, DevTheta, Kist, v_traj, a_traj, &Outputs, Inputs->sf_CridrRightSg1_DistX_met, Inputs->sf_UseCridrRightX0_nu, Inputs->sf_CridrRightSg1_DistY_met);

        /* \DOORS 8050 Transformation of trajectory values of last cycle to Frenet */
        TrajCalc_FT_CalcTrajLastCycle(&DistYTrajPrev, &DistYTrajPrev_dot,&DistYTrajPrev_ddot, Inputs->sf_DistYTrajPrev_met, Inputs->sf_HeadingTrajPrev_rad, PlanArcLength, Kr, Kr_prime, Inputs->sf_TgtCrvTrajPrev_1pm, Vx, Ax, &v_traj_Tgt, &a_traj_Tgt);

        /* Set outputs of S-Function */
        Outputs.sf_DistYCurValue_met = dist;
        Outputs.sf_DistY1stDerivCurValue_nu = dist1stDeriv;
        Outputs.sf_DistY2ndDerivCurValue_nu = dist2ndDeriv;
        
        /* Select the velocity and acceleration of the reference line*/
        if (Inputs->sf_ReplanCurValues_nu != true)
        {
            v_traj = v_traj_Tgt;
            a_traj = a_traj_Tgt;
        }
        
        Outputs.sf_TrajVel_mps = v_traj;
        Outputs.sf_TrajAcl_mps2 = a_traj;
        
        Outputs.sf_TrajDistYPrevious_met = DistYTrajPrev;
        Outputs.sf_TrajDistYPrev1stDeriv_nu = DistYTrajPrev_dot;
        Outputs.sf_TrajDistYPrev2ndDeriv_nu = DistYTrajPrev_ddot;

        Outputs.sf_1stDerivDevHeading_nu = FirstDerivDeltaHeading;
        Outputs.sf_2ndDerivDevHeading_nu = SecondDerivDeltaHeading;
        
        if ( (Inputs->sf_TrigRecalc_nu == true) || (Inputs->sf_TrigTgtTrajCalc_nu == true) )
        {

            float32 TgtSg1X, TgtSg1Length, CridrRiSg1Heading, PlanHorizon, CridrRiSg1Length, TgtTrajSg1Y, TgtTrajSg1Hdng, TgtTrajSg1Crv, TgtTrajSg1ChngOfCrv,CridrRiSg1X, CridrLeSg1X, CridrRiSg1Y;
            float32 CridrLeSg1Length,CridrLeSg1Y,CridrLeSg1Hdng,CridrLeSg1Crv, CridrLeSg1ChgOfCrv;
            TgtSg1X = Inputs->sf_TgtTrajSg1_DistX_met;
            TgtSg1Length = Inputs->sf_TgtTrajSg1_Length_met;
            TgtTrajSg1ChngOfCrv = Inputs->sf_TgtTrajSg1_ChngOfCrv_1pm2;
            TgtTrajSg1Y = Inputs->sf_TgtTrajSg1_DistY_met;
            TgtTrajSg1Hdng = Inputs->sf_TgtTrajSg1_Heading_rad;
            TgtTrajSg1Crv = Inputs->sf_TgtTrajSg1_Crv_1pm;
            CridrRiSg1X = Inputs->sf_CridrRightSg1_DistX_met;
            CridrRiSg1Y = Inputs->sf_CridrRightSg1_DistY_met;
            CridrRiSg1Heading = Inputs->sf_CridrRightSg1_Heading_rad;
            CridrRiSg1Length = Inputs->sf_CridrRightSg1_Length_met;
            PlanHorizon = Inputs->sf_PlanningHorizon_sec;
            CridrLeSg1Length = Inputs->sf_CridrLeftSg1_Length_met;
            CridrLeSg1X = Inputs->sf_CridrLeftSg1_DistX_met;
            CridrLeSg1Y = Inputs->sf_CridrLeftSg1_DistY_met;
            CridrLeSg1Hdng = Inputs->sf_CridrLeftSg1_Heading_rad;
            CridrLeSg1Crv = Inputs->sf_CridrLeftSg1_Crv_1pm;
            CridrLeSg1ChgOfCrv = Inputs->sf_CridrLeftSg1_ChOfCrv_1pm2;
            /* \DOORS 13759 */
            if( (Inputs->sf_TrigTgtTrajCalc_nu == true) && (Inputs->sf_TgtTrajSg1_Length_met >= 0) && (Inputs->sf_CridrRightSg1_Length_met > 0) ) // JIRA: FASSIEBEN-7347 Feher bei der Ausgabe der Zielwerte, wenn die Lauflänge negativ ist
            {
                /* \DOORS 5206  Transformation of target curve to Frenet */
                TrajCalc_FT_CalcTargetCurvePoints(PlanArcLength, TgtSg1X, TgtSg1Length, CridrRiSg1Heading, Kr, Kr_prime, PlanHorizon, CridrRiSg1Length, TgtTrajSg1Y, TgtTrajSg1Hdng, TgtTrajSg1Crv, TgtTrajSg1ChngOfCrv, v_traj, a_traj, &Outputs, Inputs->sf_UseTgtTrajX0_nu, CridrRiSg1X, Inputs->sf_UseCridrRightX0_nu, CridrRiSg1Y);
            }

            /* \DOORS xxxxxx Calculation of curvature of right corridor */
            if( Inputs->sf_TrigRecalc_nu == true )
            {
                TrajCalc_FT_CalcRightCorridor(PlanArcLength, v_traj, a_traj, Kr, Kr_prime, CridrRiSg1Length, &Outputs, CridrRiSg1X, Inputs->sf_UseCridrRightX0_nu, CridrRiSg1Heading);
            }

            /* \DOORS 10353 */
            if( (Inputs->sf_TrigRecalc_nu == true) && (Inputs->sf_LeftCridrActive_nu == true) )
            {
                /* \DOORS 5663 Transformation of left corridor boundary */
                TrajCalc_FT_CalcLeftCorridor(&Outputs, Kr,Kr_prime, CridrLeSg1Length,CridrRiSg1Length, CridrLeSg1Y,CridrLeSg1Hdng, CridrLeSg1Crv,CridrLeSg1ChgOfCrv, v_traj, a_traj, PlanArcLength, Inputs->sf_DeadTime_sec, CridrRiSg1X, Inputs->sf_UseCridrRightX0_nu, CridrRiSg1Heading, CridrRiSg1Y, CridrLeSg1X);
            }
        } /* --> End of If */
    }  
                
    return Outputs;
}

float32 TrajCalc_FT_Theta(const float32 theta0, const float32 K0, const float32 K_prime, const float32 x, const float32 x0)
{
    float32 result;
    float32 deltaX;

    deltaX = (x-x0);
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    result = (float32)(FD_ATAN( ((float32)FD_TAN(theta0) + (K0 * deltaX)) + ((0.5F * K_prime) * (deltaX * deltaX))));
    return result;
}

float32 TrajCalc_FT_Y(const float32 Y0, const float32 theta0, const float32 K0, const float32 K_prime, const float32 x, const float32 x0)
{
    float32 result;
    float32 deltaX;
    float32 deltaXpow2;

    deltaX = (x-x0);
    deltaXpow2 = deltaX * deltaX;
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    result = (( Y0 + ((float32)FD_TAN(theta0) * (deltaX))) + ((0.5F * K0) * deltaXpow2)) + (((float32)(1.0F / 6.0F) * K_prime) * (deltaXpow2 * deltaX));
    return result;
}

float32 TrajCalc_FT_K(const float32 K0, const float32 K_prime, const float32 x, const float32 x0)
{
    float32 result;
    result = K0 + (K_prime * (x-x0));
    return result;
}

float32 TrajCalc_FT_AvoidZero(const float32 input)
{
    float32 result;
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    if( (float32)FD_FABS(input) < 0.000001F )
    {
        if( input >= 0)
        {
            result = 0.000001F;
        }
        else
        {
            result = -0.000001F;
        }
    }
    else
    {
        result = input;
    }
    return result;
}

float32 TrajCalc_FT_MinFloat(const float32 A, const float32 B)
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

float32 TrajCalc_FT_MaxFloat(const float32 A, const float32 B)
{
    float32 C;
    if(A>=B)
    {
        C = A;
    }
    else
    {
        C = B;
    }
    return C;
}

float32 TrajCalc_FT_Thetar(const float32 theta0, const float32 K0, const float32 K_prime, const float32 x, const float32 x0, const boolean_T UseCridrRiX0)
{
    float32 result, deltaX;

    if(UseCridrRiX0 == true)
    {
        deltaX = x - x0;
        /* MISRA-AK: Math functions */
        /* PRQA S 4604,3335 1 */
        result = ( (float32)FD_TAN(theta0) + (K0 * deltaX)) + ((0.5F * K_prime) * (deltaX * deltaX) );
    }
    else
    {
        deltaX = x;
        result = (K0 * deltaX) + ( (0.5F * K_prime) * (deltaX * deltaX) );
    }
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    result = (float32)FD_ATAN(result);
    return result;
}

float32 TrajCalc_FT_Yr(const float32 Y0, const float32 theta0, const float32 K0, const float32 K_prime, const float32 x, const float32 x0, const boolean_T UseCridrRiX0)
{
    float32 result;
    float32 deltaX;
    float32 deltaXpow2;

    if(UseCridrRiX0 == true)
    {
        deltaX = x - x0;
        deltaXpow2 = deltaX * deltaX;
        /* MISRA-AK: Math functions */
        /* PRQA S 4604,3335 1 */
        result = (( Y0 + ((float32)FD_TAN(theta0) * (deltaX))) + ((0.5F * K0) * deltaXpow2)) + (((float32)(1.0F / 6.0F) * K_prime) * (deltaXpow2 * deltaX));
    }
    else
    {
        deltaX = x;
        deltaXpow2 = deltaX * deltaX;
        result = ((0.5F * K0) * deltaXpow2) + ( ((float32)(1.0F / 6.0F) * K_prime) * (deltaXpow2 * deltaX));
    }
    return result;
}

void TrajCalc_FT_CalcPreviewCurValues(const float32 PreviewTimeKF, const float32 CridrRiSg1Heading, const float32 Kr, const float32 Kr_prime, const float32 CurY, const float32 CurHeading, const float32 CurCrv, const float32 v_traj, const float32 a_traj, calFTOutType* Outputs, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Y )
{
    float32 Xi, Xi_pre, Si, Si_pre, thetar_x_pre, DeltaT, Sti_dot, ti, tmax, PreviewTime, x_Start;
    uint8 i;
    boolean_T PreviewEnd;
    float32 CurYPreview, CurYPreview_prime, CurYPreview_primeprime, MaxPreviewTime, CurCrvChg;
    float32 minBft_t1;

    PreviewEnd = false;

    DeltaT = 0.1f;
    i = 0;
    Xi = 0.0f;
    Si = 0.0f;
    MaxPreviewTime = 2.0f;
    CurCrvChg = 0.0f;
    x_Start = 0.0f;
    Sti_dot = 0.0f;
    /* MISRA-AK: Math functions */
    /* PRQA S 4604,3335 1 */
    PreviewTime = (float32)FD_CEIL( (float32)(PreviewTimeKF/(DeltaT)) ) * (DeltaT);
    tmax = TrajCalc_FT_MinFloat(PreviewTime, MaxPreviewTime);

    while( PreviewEnd == false )
    {
        Xi_pre = Xi;
        Si_pre = Si;
        thetar_x_pre = TrajCalc_FT_Thetar(CridrRiSg1Heading, Kr, Kr_prime, Xi_pre, CridrRiSg1X, UseCridrRiX0);
        ti = DeltaT*(float32)i;

        minBft_t1 = TrajCalc_FT_MinFloat(1,ti);
        Sti_dot = v_traj + (a_traj*minBft_t1);
        Si = (v_traj*ti) + ((0.5f*a_traj)*(minBft_t1 * minBft_t1));
        /* MISRA-AK: Math functions */
        /* PRQA S 4604,3335 1 */
        Xi = Xi_pre + ((Si - Si_pre)*(float32)FD_COS(thetar_x_pre));

        if( (tmax - ti) >= 0.000001 )
        {
            i = i + 1 ;
        }
        else
        {
            PreviewEnd = true;
        }
    }
    TrajCalc_FT_CalcLatDistDerivs(&CurYPreview_prime, &CurYPreview_primeprime, &CurYPreview, Xi, CridrRiSg1Heading, Kr, Kr_prime, CurY, CurHeading, CurCrv, CurCrvChg, x_Start, CridrRiSg1X, UseCridrRiX0, CridrRiSg1Y);

    /* Set outputs */
    Outputs->sf_DstYCurValuePreview_met = CurYPreview;
    Outputs->sf_DstY1stDrvCurValPrvw_mps = CurYPreview_prime * Sti_dot;
    Outputs->sf_FrenTrafHeadingPrvw_sec = tmax;
}

void TrajCalc_FT_CalcRightCorridor(const boolean_T PlanArcLength, const float32 v_Traj, const float32 a_Traj, const float32 CridrRiSg1Crv, const float32 CridrRiSg1ChgOfCrv, const float32 CridrRiSg1Length, calFTOutType* Outputs, const float32 CridrRiSg1X, const boolean_T UseCridrRiX0, const float32 CridrRiSg1Heading)
{
    float32 delta_sec, delta_t;
    float32 SiRight, XiRight, ThetaRight, SiRight_pre, XiRight_pre, ThetaRight_pre;
    boolean_T CalcEnd;
    float32 Time, KRight;
    uint8 Index, Index_Output, MaxIter;

    /* Initialize Variables */
    MaxIter = 75;
    delta_sec = 0.7f;  /* in Meters */
    delta_t = 0.05f; /* in Seconds */
    CalcEnd = false;
    SiRight = 0.0f;
    XiRight = 0.0f;
    ThetaRight = 0.0f;
    Index = 0;
    Index_Output = 0;
    while(CalcEnd != true) {
        SiRight_pre = SiRight;

        if( PlanArcLength == true ) /* arc length based */
        {
            SiRight = (float32)(Index + 1) * delta_sec;
        }
        else                        /* time based */
        {
            float32 min_t;
            Time = (float32)(Index + 1) * delta_t;
            min_t = TrajCalc_FT_MinFloat(Time, 1.0f);
            SiRight = (v_Traj * Time) + ((0.5f * a_Traj) * (min_t * min_t));
        }
        XiRight_pre = XiRight;
        ThetaRight_pre = ThetaRight;
        /* MISRA-AK: Math functions */
        /* PRQA S 4604,3335 1 */
        XiRight = XiRight_pre + ((SiRight - SiRight_pre) * (float32)FD_COS(ThetaRight_pre));
        ThetaRight = TrajCalc_FT_Thetar(CridrRiSg1Heading, CridrRiSg1Crv, CridrRiSg1ChgOfCrv, XiRight, CridrRiSg1X, UseCridrRiX0);
        KRight = TrajCalc_FT_K(CridrRiSg1Crv, CridrRiSg1ChgOfCrv, XiRight, CridrRiSg1X);

        if( ( ((Index + 1)%5) == 0) && (Index_Output < 15)  )
        {
            Outputs->sf_CridrRight_Crv_1pm[Index_Output] = KRight;
            Index_Output = Index_Output + 1;
            Outputs->sf_NumPointsCridrRight_nu = Index_Output;
        }

        if( (XiRight >= CridrRiSg1Length) || (Index >= (MaxIter-1) ) )
        {
            CalcEnd = true;
        }
        else
        {
            Index = Index + 1;
        }
    }
}

#define STOP_SEC_CODE
/*-------------------------------------------------------------------------------------------*
  END OF FILE
 *-------------------------------------------------------------------------------------------*/
/* PRQA S 0862 EOF */
