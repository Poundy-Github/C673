/*********************************************************************
MODULE:         Trajectory Planning

Type:           C

CPU:            All

DESCRIPTION:    S-Funktion calFrenetBackTransformation

AUTHOR:         JiYa, JaAl, QiZh

********************************************************************************

<HISTORY>
#<version>  <modify-date>   <owner>     <comment>
            14.05.2013      JiYa        Neuerstellung
            13.11.2015      JaAl        Removed Dependency on BMW tmwtypes.h
            25.11.2015      DoFr        Translation German -> English
            29.07.2019      QiZh        Clean up, DOORS ID update
<NEW>
</NEW>
</HISTORY>

*********************************************************************/

/* -----------------------------------------------------------------------------
    M I S R A
/* -----------------------------------------------------------------------------
*/

/* -----------------------------------------------------------------------------

    I N C L U D E S

 * -----------------------------------------------------------------------------
*/

#include "calFrenetBackTransformation.h"

/* -----------------------------------------------------------------------------

    D E C L A R A T I O N   F U N C T I O N S

 * -----------------------------------------------------------------------------
*/

#define START_SEC_CODE

/* -----------------------------------------------------------------------------

    F U N C T I O N   D E F I N I T I O N S

 * -----------------------------------------------------------------------------
*/
calFBTOutType calFrenetBackTransformation(const calFBTInType* Inputs)
{
    calFBTOutType Outputs;
    float32 v_traj, a_traj;
    float32 one_minus_kappa_d;
    float32 d_prime, d_prime_TrajPrevHdg;
    float32 d_primeprime, d_primeprime_TrajPrevKappaAndDeadTime, d_primeprime_TrajPrevKappa;
    float32	d_primeprimeprime, d_primeprimeprime_TrajPrevKappaAndDeadTime;
    /* DOORS ID FCT_CMP_TRJPLN_271, FCT_CMP_TRJPLN_323, FCT_CMP_TRJPLN_324, FCT_CMP_TRJPLN_341, FCT_CMP_TRJPLN_314, FCT_CMP_TRJPLN_342, FCT_CMP_TRJPLN_329*/
    v_traj = TrajCalc_FBT_AvoidZero( Inputs->sfunc_TPLFBT_TrajVelRefCurve_mps );
    /* DOORS ID FCT_CMP_TRJPLN_341, FCT_CMP_TRJPLN_314, FCT_CMP_TRJPLN_342, FCT_CMP_TRJPLN_329 */
    a_traj = Inputs->sfunc_TPLFBT_TrajAclRefCurve_mps2;

    if( (Inputs->sfunc_TPLFBT_TrajGuiEnable_nu == true) && (Inputs->sfunc_NoTrajFound_nu == false) )
    {
        /* DOORS ID FCT_CMP_TRJPLN_325 */
        Outputs.sfunc_TrajDistY_met = Inputs->sfunc_TPLFBT_TrajDistY_met;
        
        /* DOORS ID FCT_CMP_TRJPLN_271, FCT_CMP_TRJPLN_323, FCT_CMP_TRJPLN_324, FCT_CMP_TRJPLN_341, FCT_CMP_TRJPLN_314, FCT_CMP_TRJPLN_342, FCT_CMP_TRJPLN_329*/
        one_minus_kappa_d = 1.0F - ( Inputs->sfunc_TPLFBT_CridrRightSeg1_Crv_1pm * Inputs->sfunc_TPLFBT_TrajDistY_met );
        one_minus_kappa_d = TrajCalc_FBT_AvoidZero(one_minus_kappa_d);

        /* */
        if(Inputs->sfunc_ReplanModeArcLength_nu == true)
        {
            /* DOORS ID FCT_CMP_TRJPLN_323, FCT_CMP_TRJPLN_341, FCT_CMP_TRJPLN_314, FCT_CMP_TRJPLN_342, FCT_CMP_TRJPLN_329 */
            d_prime = Inputs->sfunc_TPLFBT_TrajDistY1stDeriv_nu;
            /* DOORS ID FCT_CMP_TRJPLN_324 */
            d_prime_TrajPrevHdg = Inputs->sfunc_YDotTrajFromHeadingPreview_nu;
            /* DOORS ID FCT_CMP_TRJPLN_341, FCT_CMP_TRJPLN_342, FCT_CMP_TRJPLN_329 */
            d_primeprime = Inputs->sfunc_TPLFBT_TrajDistY2ndDeriv_nu;
            /* DOORS ID FCT_CMP_TRJPLN_314 */
            d_primeprime_TrajPrevKappaAndDeadTime = Inputs->sfunc_YDot2TrajFromKappaPrevAndDT_nu;
            
            d_primeprime_TrajPrevKappa = Inputs->sfunc_YDotDotTrajFromKappaPreview_nu;
            /* DOORS ID FCT_CMP_TRJPLN_271 */
            Outputs.sfunc_HeadingCurValuePreview_rad = Inputs->sfunc_DevHeading_rad;
            /* DOORS ID FCT_CMP_TRJPLN_329 */
            d_primeprimeprime_TrajPrevKappaAndDeadTime = Inputs->sfunc_YDot3TrajFromKappaPrevAndDT_nu;
            /* DOORS ID FCT_CMP_TRJPLN_342 */
            d_primeprimeprime = Inputs->sfunc_TPLFBT_TrajDistY3rdDeriv_nu;
        }
        else
        {
        	float32 d_prime_CurValPreview;
        	float32 v_traj_3;
        	v_traj_3 = v_traj * v_traj * v_traj;
            /* DOORS ID FCT_CMP_TRJPLN_323, FCT_CMP_TRJPLN_341, FCT_CMP_TRJPLN_314, FCT_CMP_TRJPLN_342, FCT_CMP_TRJPLN_329 */
        	d_prime = Inputs->sfunc_TPLFBT_TrajDistY1stDeriv_nu / v_traj;
            /* DOORS ID FCT_CMP_TRJPLN_271 */
            d_prime_CurValPreview = Inputs->sfunc_DistY1stDerivCurValuePreview_mps / v_traj;
            /* DOORS ID FCT_CMP_TRJPLN_324 */
        	d_prime_TrajPrevHdg = Inputs->sfunc_YDotTrajFromHeadingPreview_nu / v_traj;
            /* DOORS ID FCT_CMP_TRJPLN_341, FCT_CMP_TRJPLN_342, FCT_CMP_TRJPLN_329 */
            d_primeprime = ( Inputs->sfunc_TPLFBT_TrajDistY2ndDeriv_nu - ( a_traj * d_prime ) ) / (v_traj * v_traj);
            /* DOORS ID FCT_CMP_TRJPLN_314 */
            d_primeprime_TrajPrevKappaAndDeadTime = ( Inputs->sfunc_YDot2TrajFromKappaPrevAndDT_nu - ( a_traj * d_prime ) ) / (v_traj * v_traj);
            
            d_primeprime_TrajPrevKappa = ( Inputs->sfunc_YDotDotTrajFromKappaPreview_nu - ( a_traj * d_prime ) ) / (v_traj * v_traj);
            /* DOORS ID FCT_CMP_TRJPLN_329 */
            d_primeprimeprime_TrajPrevKappaAndDeadTime = (Inputs->sfunc_YDot3TrajFromKappaPrevAndDT_nu - (((3*a_traj)*v_traj)*d_primeprime_TrajPrevKappaAndDeadTime)) / v_traj_3;
            /* DOORS ID FCT_CMP_TRJPLN_342 */
            d_primeprimeprime = (Inputs->sfunc_TPLFBT_TrajDistY3rdDeriv_nu - (((3*a_traj)*v_traj)*d_primeprime)) / v_traj_3;
            /* DOORS ID FCT_CMP_TRJPLN_271 */
            Outputs.sfunc_HeadingCurValuePreview_rad = (float32)FD_ATAN(d_prime_CurValPreview / one_minus_kappa_d );
        }
        /* DOORS ID FCT_CMP_TRJPLN_323 */
        Outputs.sfunc_TrajHeading_rad = (float32)FD_ATAN(d_prime / one_minus_kappa_d);
        /* DOORS ID FCT_CMP_TRJPLN_324 */
        Outputs.sfunc_TrajHeadingInclPreview_rad = (float32)FD_ATAN(d_prime_TrajPrevHdg / one_minus_kappa_d);
        /* DOORS ID FCT_CMP_TRJPLN_341 */
        Outputs.sfunc_TrajTgtCrv_1pm = (((d_primeprime + ( ((Inputs->sfunc_TPLFBT_CridrRightSeg1_Crv_1pm * d_prime) + (Inputs->sfunc_TPLFBT_CridrRightSeg1_ChngOfCrv_1pm2 * Inputs->sfunc_TPLFBT_TrajDistY_met)) * (float32)FD_TAN(Outputs.sfunc_TrajHeading_rad))) * (float32)FD_POW(FD_COS(Outputs.sfunc_TrajHeading_rad),3)) / (one_minus_kappa_d*one_minus_kappa_d)) + (((float32)FD_COS(Outputs.sfunc_TrajHeading_rad) / one_minus_kappa_d) * Inputs->sfunc_TPLFBT_CridrRightSeg1_Crv_1pm);
        
        Outputs.sfunc_DistYCurValuePreview_met = Inputs->sfunc_DevDistY_met;
        /* DOORS ID FCT_CMP_TRJPLN_314 */
        Outputs.sfunc_TgtCrvInclPreviewAndDeadTime_1pm = (((d_primeprime_TrajPrevKappaAndDeadTime + ( ((Inputs->sfunc_TPLFBT_CridrRightSeg1_Crv_1pm * d_prime) + (Inputs->sfunc_TPLFBT_CridrRightSeg1_ChngOfCrv_1pm2 * Inputs->sfunc_TPLFBT_TrajDistY_met)) * (float32)FD_TAN(Outputs.sfunc_TrajHeading_rad))) * (float32)FD_POW(FD_COS(Outputs.sfunc_TrajHeading_rad),3)) / (one_minus_kappa_d*one_minus_kappa_d)) + (((float32)FD_COS(Outputs.sfunc_TrajHeading_rad) / one_minus_kappa_d) * Inputs->sfunc_TPLFBT_CridrRightSeg1_Crv_1pm);
		
        Outputs.sfunc_TgtCrvTrajInclPreview_1pm = (((d_primeprime_TrajPrevKappa + ( ((Inputs->sfunc_TPLFBT_CridrRightSeg1_Crv_1pm * d_prime) + (Inputs->sfunc_TPLFBT_CridrRightSeg1_ChngOfCrv_1pm2 * Inputs->sfunc_TPLFBT_TrajDistY_met)) * (float32)FD_TAN(Outputs.sfunc_TrajHeading_rad))) * (float32)FD_POW(FD_COS(Outputs.sfunc_TrajHeading_rad),3)) / (one_minus_kappa_d*one_minus_kappa_d)) + (((float32)FD_COS(Outputs.sfunc_TrajHeading_rad) / one_minus_kappa_d) * Inputs->sfunc_TPLFBT_CridrRightSeg1_Crv_1pm);
		/* DOORS ID FCT_CMP_TRJPLN_329 */
        Outputs.sfunc_TgtCrvGrdTrajInclPrevAndDT_1pms = TrajCalc_FBT_CalcTrajChgOfCurvature(Outputs.sfunc_TrajHeading_rad, Inputs->sfunc_TPLFBT_CridrRightSeg1_Crv_1pm, Inputs->sfunc_TPLFBT_CridrRightSeg1_ChngOfCrv_1pm2, Inputs->sfunc_TPLFBT_TrajDistY_met, d_prime, d_primeprime, d_primeprimeprime_TrajPrevKappaAndDeadTime,  Outputs.sfunc_TrajTgtCrv_1pm, v_traj);
        /* DOORS ID FCT_CMP_TRJPLN_342 */
        Outputs.sfunc_TrajTgtCrvGrd_1pms = TrajCalc_FBT_CalcTrajChgOfCurvature(Outputs.sfunc_TrajHeading_rad, Inputs->sfunc_TPLFBT_CridrRightSeg1_Crv_1pm, Inputs->sfunc_TPLFBT_CridrRightSeg1_ChngOfCrv_1pm2, Inputs->sfunc_TPLFBT_TrajDistY_met, d_prime, d_primeprime, d_primeprimeprime,  Outputs.sfunc_TrajTgtCrv_1pm, v_traj);
            }

    else        
    {
        /* DOORS ID FCT_CMP_TRJPLN_325 */
        Outputs.sfunc_TrajDistY_met = 0.0f;
        /* DOORS ID FCT_CMP_TRJPLN_323 */
        Outputs.sfunc_TrajHeading_rad = 0.0f;
        /* DOORS ID FCT_CMP_TRJPLN_324 */
        Outputs.sfunc_TrajHeadingInclPreview_rad = 0.0f;
        /* DOORS ID FCT_CMP_TRJPLN_341 */
        Outputs.sfunc_TrajTgtCrv_1pm = 0.0f;
        /* DOORS ID FCT_CMP_TRJPLN_314 */
        Outputs.sfunc_TgtCrvInclPreviewAndDeadTime_1pm = 0.0f;
        /* DOORS ID FCT_CMP_TRJPLN_342 */
        Outputs.sfunc_TrajTgtCrvGrd_1pms = 0.0f;
        /* DOORS ID FCT_CMP_TRJPLN_329 */
        Outputs.sfunc_TgtCrvGrdTrajInclPrevAndDT_1pms = 0.0f;
        
        Outputs.sfunc_TgtCrvTrajInclPreview_1pm = 0.0f;
        /* DOORS ID FCT_CMP_TRJPLN_271 */
        Outputs.sfunc_HeadingCurValuePreview_rad = Inputs->sfunc_DevHeading_rad;

        Outputs.sfunc_DistYCurValuePreview_met = Inputs->sfunc_DevDistY_met;
    }
    
	return Outputs;
}


float32	TrajCalc_FBT_AvoidZero(const float32 input)
{
    float32 result;
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

float32 TrajCalc_FBT_CalcTrajChgOfCurvature(float32 deltaTheta, float32 Kr, float32 Kr_p, float32 d, float32 d_p, float32 d_pp, float32 d_ppp, float32 Kt, float32 v_Bahn)
{
	float32 Kt_p;
	float32 Costheta, Sintheta, Tantheta;
	float32 one_minus_krd, Krpd_plus_Krdp, one_minus_krd_2, one_minus_krd_3, deltatheta_p;
	float32 A, A_p, B, B_p, C, C_p;

		Costheta = TrajCalc_FBT_AvoidZero((float32)FD_COS(deltaTheta));
	Sintheta = (float32)FD_SIN(deltaTheta);
	Tantheta = (float32)FD_TAN(deltaTheta);
	one_minus_krd = TrajCalc_FBT_AvoidZero((1 - (Kr * d)));
	one_minus_krd_2 = one_minus_krd * one_minus_krd;
	one_minus_krd_3 = one_minus_krd_2 * one_minus_krd;
	Krpd_plus_Krdp = (Kr_p * d) + (Kr * d_p);

	A = d_pp + (Krpd_plus_Krdp * Tantheta);
	C = Costheta / one_minus_krd;
	B = (C * C) * Costheta;
	deltatheta_p = (Kt / TrajCalc_FBT_AvoidZero(C)) - Kr;
	A_p = (d_ppp + (( ((2 * d_p) * Kr_p) + (d_pp * Kr) ) * Tantheta)) + ((Krpd_plus_Krdp * ( (1 / Costheta) / Costheta)) * deltatheta_p);
	B_p = ((((2 * Costheta) * Costheta) * ( (Costheta * Krpd_plus_Krdp) - ((Sintheta * deltatheta_p) * one_minus_krd) )) / one_minus_krd_3) - (((Sintheta * deltatheta_p) * C) * C);
	C_p = ( (Costheta * Krpd_plus_Krdp) - ((Sintheta * deltatheta_p) * one_minus_krd) ) / one_minus_krd_2;
	Kt_p = v_Bahn * ( (((A_p * B) + (B_p * A)) + (C_p * Kr)) + (Kr_p * C) );

	return Kt_p;
}

#define STOP_SEC_CODE


/*-------------------------------------------------------------------------------------------*
  END OF FILE
 *-------------------------------------------------------------------------------------------*/
