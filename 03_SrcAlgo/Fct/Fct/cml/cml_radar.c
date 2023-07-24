/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_radar.c

  DESCRIPTION:               Provide radar related mathematical functions 

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             05.25.2017

  VERSION:                   $Revision: 1.6 $

  ---*/ /*---
  CHANGES:                   $Log: cml_radar.c  $
  CHANGES:                   Revision 1.6 2019/06/24 10:39:50CEST Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   QAF level 3 warnings have been fixed.
  CHANGES:                   Revision 1.5 2019/04/25 12:46:08CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Changes for MFC431TA19 polyspace. Observed that CML_f_cos33Core is a better choice here. And this fix the RED warning
  CHANGES:                   Revision 1.4 2019/04/25 12:22:21CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   updated function CML_v_calculateCOFEgomotionMatrices to call CML_f_cos33Core
  CHANGES:                   Revision 1.3 2018/02/26 08:52:11CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.2 2017/11/14 18:41:37CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated to the code from AL_CML_01.09.13_INT-1
  CHANGES:                   Revision 1.1 2017/08/04 23:42:19CEST Russell, Robert (russellr) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/CML_CommonMathLibrary/04_Engineering/01_Source_Code/CML/radar/project.pj
  CHANGES:                   Revision 1.3 2017/06/06 07:39:37CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Initialized temporary variable
  CHANGES:                   Revision 1.2 2017/05/30 11:52:53CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Moved static declaration of CML_f_ApproximateRefpoint from cml_misc.c
  CHANGES:                   Corrected indentations
  CHANGES:                   Revision 1.1 2017/05/25 12:08:03CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/* PRQA S 0380 10*/
/* Deactivate QAF warning 0380, Date: 2019-06-17; Reviewer: uidk9586;  
   Reason: The warning is seen as number of macros exceeds 4095 which can not be avoided here. 
   Warning is analysed and no risk in suppressing this. */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cml_ext.h"

/*****************************************************************************
 (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*! Parameters for CML_calculateDistancePoint2Circle */
/* minimum curvature for which use circle equation instead of parabolic approximation */
#define CURVATURE_USE_CIRCLE_EQUATION   (1.F/1000.F)  /* in 1/m */
/* minimum curvature for which use circle equation instead of parabolic approximation */
#define RADIUS_INIT_VALUE               (999999.F)    /* in m */

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* Calculates X value of the normal crossing from object to clothoid tangent at last approximated X value */
static float32 CML_f_approximateRefPoint(float32 f_X, float32 f_Y, float32 f_C0, float32 f_C1, float32 f_RefX);

/*****************************************************************************
  Functionname:    CML_v_calculateCOFEgomotionMatrices                  */ /*!

  @brief           Calculate Trasformation Matrices for Egomotion Compensation 
                   of COF(Coordinate system Of vehicle Front)
                   
  @description     This function calculate Trasformation Matrices for Egomotion 
                   Compensation of COF (Coordinate system Of vehicle Front).
                   It determines the transformation type and entries of the 
                   transfromation matrices (forward and backward).
                   
  @param[in]       f_SpeedCorrected :               The ego motion speed
                                                    Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_EgoAcceleration :              The ego acceleration
                                                    Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_YawRate_e :                    The ego yaw rate
                                                    Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_CycleTime :                    The time delta to use for calculation
                                                    Optimal values are [-F_MAX,..,F_MAX]
                                                    where F_MAX is the fourth root of max range of float32.
  @param[out]      p_TrafoMatrix2DCOFForwardRaw :   pointer to buffer for forward transformation matrix.
                                                    [Valid matrix structure pointer]
                                                    Supported values for p_TrafoMatrix2DCOFForwardRaw->TrafoType are 0,1,2.
                                                    Range for p_TrafoMatrix2DCOFForwardRaw->f00 is [0,..,1]
                                                    Range for p_TrafoMatrix2DCOFForwardRaw->f02 is [Full range of float32]
                                                    Range for p_TrafoMatrix2DCOFForwardRaw->f10 is [0,..,1]
                                                    Range for p_TrafoMatrix2DCOFForwardRaw->f12 is [Full range of float32]
  @param[out]      p_TrafoMatrix2DCOFBackwardRaw :  pointer to buffer for backward transformation matrix
                                                    [Valid matrix structure pointer]
                                                    Supported values for p_TrafoMatrix2DCOFBackwardRaw->TrafoType are 0,1,2.
                                                    Range for p_TrafoMatrix2DCOFBackwardRaw->f00 is [0,..,1]
                                                    Range for p_TrafoMatrix2DCOFBackwardRaw->f02 is [Full range of float32]
                                                    Range for p_TrafoMatrix2DCOFBackwardRaw->f10 is [0,..,1]
                                                    Range for p_TrafoMatrix2DCOFBackwardRaw->f12 is [Full range of float32]

                   
  @return          none
                   
  @author          Norman Apel
  
*****************************************************************************/
void CML_v_calculateCOFEgomotionMatrices(CML_t_TrafoMatrix2D * p_TrafoMatrix2DCOFForwardRaw,
    CML_t_TrafoMatrix2D * p_TrafoMatrix2DCOFBackwardRaw,
    fVelocity_t   f_SpeedCorrected,
    fAccel_t      f_EgoAcceleration,
    fYawRate_t    f_YawRate_e,
    fTime_t       f_CycleTime)
{

    fAngle_t f_YawAngle;
    float32  f_DrivenDistance;
    float32  f_cosYawAngle;
    float32  f_sinYawAngle;
    float32  f_Translation_X; 
    float32  f_Translation_Y; 
    float32 f_temp1,f_temp2,f_temp3,f_temp4;

    /* this section is only of equal test */
    float32 f_YawRateCurve; 
    float32 f_YawRate;
    if (f_SpeedCorrected > CML_f_Delta)
    {
        f_YawRateCurve = f_YawRate_e / f_SpeedCorrected;
    }
    else
    {
        f_YawRateCurve = 0.f;
    }
    f_YawRate = f_SpeedCorrected * f_YawRateCurve;

    f_YawAngle = f_YawRate * f_CycleTime;

    /* Below lines of code implement : f_DrivenDistance = (f_SpeedCorrected * f_CycleTime) + (((0.5f * f_EgoAcceleration) * f_CycleTime) * f_CycleTime);
    Code modified to maintain consistency between MSVC & C66x */
    f_temp1 = f_SpeedCorrected * f_CycleTime;
    f_temp2 = 0.5f * f_EgoAcceleration;
    f_temp3 = f_temp2 * f_CycleTime;
    f_temp4 = f_temp3 * f_CycleTime;
    f_DrivenDistance = f_temp1 + f_temp4;

    /* to avoid division by zero */
    if( CML_f_Abs(f_YawAngle) <= CML_f_Delta  ) 
    {
        p_TrafoMatrix2DCOFForwardRaw->TrafoType = TRANSLATION_;
        p_TrafoMatrix2DCOFForwardRaw->f00 = 1.0f;
        p_TrafoMatrix2DCOFForwardRaw->f02 = -1.0f * f_DrivenDistance;
        p_TrafoMatrix2DCOFForwardRaw->f10 = 0.0f;
        p_TrafoMatrix2DCOFForwardRaw->f12 = 0.0f;

        p_TrafoMatrix2DCOFBackwardRaw->TrafoType = TRANSLATION_;
        p_TrafoMatrix2DCOFBackwardRaw->f00 = 1.0f;
        p_TrafoMatrix2DCOFBackwardRaw->f02 = f_DrivenDistance;
        p_TrafoMatrix2DCOFBackwardRaw->f10 = 0.0f;
        p_TrafoMatrix2DCOFBackwardRaw->f12 = 0.0f;
    }
    else
    {
        /* fuer kleine Winkel ist die SIN/COS-Approximation schlecht!!!  */
        /* absoluter fehler sin/cos_52: <= 6.70669e-6 */
        /* absoluter fehler sin/cos_32: <= 5.98681e-4 */
        /* nutze deshalb die Approximation  */
        /* sin(x) = x, mit abs. Fehler e-6 fuer x > 0.03rad */
        /* cos(x) = 1-0.5*x*x, mit abs. Fehler e-6 fuer x > 0.003rad */
        if(CML_f_Abs(f_YawAngle) < CML_f_MaxAngleSinApprox_1)
        {
            f_sinYawAngle = f_YawAngle;
            if(CML_f_Abs(f_YawAngle) < CML_f_MaxAngleSinApprox_2)
            {
                /* Below lines of code implement: f_cosYawAngle = 1.0f - ((0.5f * f_YawAngle) * f_YawAngle);
                Code modified to maintain consistency between MSVC & C66x */
                f_temp1 = 0.5f * f_YawAngle;
                f_temp2 = f_temp1 * f_YawAngle;
                f_cosYawAngle = 1.0f - f_temp2;
            }
            else
            {   /* Changes for MFC431TA19 polyspace. Observed that CML_f_cos33Core is a better choice here */
                f_cosYawAngle = CML_f_cos33Core(f_YawAngle);
            }
        }
        else
        {
            f_sinYawAngle = SIN_HD_(f_YawAngle);
            f_cosYawAngle = COS_HD_(f_YawAngle);
        }

        /* calculate Translation-Vector */
        /* <ln_offset:1to2 MISRA Rule 1.2: reviewer name: Daniel Meschenmoser date: 2012-09-12 reason: fYawAngle is checked for zero in the if statement */
        /* Below lines of code implement :f_Translation_X = -1.0f * (f_DrivenDistance / f_YawAngle) * f_sinYawAngle;
        f_Translation_Y = -1.0f * (f_DrivenDistance / f_YawAngle) * (1.0f - f_cosYawAngle);
        Code modified to maintain consistency between MSVC & C66x */
        f_temp1 = f_DrivenDistance / f_YawAngle;
        f_temp2 = f_temp1 * f_sinYawAngle;
        f_Translation_X = -1.0f * f_temp2;

        f_temp2 = 1.0f - f_cosYawAngle;
        f_temp3 = f_temp1 * f_temp2;
        f_Translation_Y = -1.0f * f_temp3;

        p_TrafoMatrix2DCOFForwardRaw->TrafoType = DEFAULT_;
        p_TrafoMatrix2DCOFForwardRaw->f00 = f_cosYawAngle;
        /* p_TrafoMatrix2DCOFForwardRaw->f02 = (f_Translation_X * f_cosYawAngle) + (f_Translation_Y * f_sinYawAngle);
        Code modified to maintain consistency between MSVC & C66x */
        f_temp1 = f_Translation_X * f_cosYawAngle;
        f_temp2 = f_Translation_Y * f_sinYawAngle;
        p_TrafoMatrix2DCOFForwardRaw->f02 = f_temp1 + f_temp2;	
        p_TrafoMatrix2DCOFForwardRaw->f10 = -1.0f * f_sinYawAngle;
        /* p_TrafoMatrix2DCOFForwardRaw->f12 = (f_Translation_Y * f_cosYawAngle) - (f_Translation_X * f_sinYawAngle);
        Code modified to maintain consistency between MSVC & C66x */
        f_temp1 = f_Translation_Y * f_cosYawAngle;
        f_temp2 = f_Translation_X * f_sinYawAngle;
        p_TrafoMatrix2DCOFForwardRaw->f12 = f_temp1 - f_temp2;

        p_TrafoMatrix2DCOFBackwardRaw->TrafoType = DEFAULT_;
        p_TrafoMatrix2DCOFBackwardRaw->f00 = f_cosYawAngle;
        p_TrafoMatrix2DCOFBackwardRaw->f02 = -1.0f * f_Translation_X;
        p_TrafoMatrix2DCOFBackwardRaw->f10 = f_sinYawAngle;
        p_TrafoMatrix2DCOFBackwardRaw->f12 = -1.0f * f_Translation_Y;
    }
}

/*****************************************************************************
  Functionname:    CML_v_calcCOFEgomotionMatrices                       */ /*!

  @brief           Calculate Transformation Matrices for Egomotion Compensation 
                   of COF (Coordinate system Of vehicle Front)
                   
  @description     This function calculate forward and jitter transformation 
                   Matrices for Egomotion Compensation of COF 
                   (Coordinate system Of vehicle Front)

  @param[in]       f_EgoSpeedXTgtSync :                The ego motion speed
                                                       Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_EgoAccelXTgtSync :                The ego acceleration
                                                       Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_YawRateTgtSync :                  The ego yaw rate
                                                       Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_YawRateVarTgtSync :               variance of the ego yaw rate
                                                       Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_YawRateMaxJitterTgtSync :         max jitter of ego yaw rate
                                                       Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_SensorXPosition :                 sensor x position
                                                       Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_CycleTime :                       sensor cycle time
                                                       Optimal values are [-F_MAX,..,F_MAX]
                                                       where F_MAX is the fourth root of max range of float32.
  @param[out]      p_TrafoMatrix2DCOFForwardTgtSync :  pointer to buffer for forward transformation matrix
                                                       [Valid matrix structure pointer]
                                                       Supported values for p_TrafoMatrix2DCOFForwardTgtSync->TrafoType are 0,1,2.
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f00 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f02 is [Full range of float32]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f10 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f12 is [Full range of float32]
  @param[out]      p_TrafoMatrix2DCOFForJitTgtSync :   pointer to buffer for jitter transformation matrix
                                                       [Valid matrix structure pointer]
                                                       Supported values for p_TrafoMatrix2DCOFForJitTgtSync->TrafoType are 0,1,2.
                                                       Range for p_TrafoMatrix2DCOFForJitTgtSync->f00 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForJitTgtSync->f02 is [Full range of float32]
                                                       Range for p_TrafoMatrix2DCOFForJitTgtSync->f10 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForJitTgtSync->f12 is [Full range of float32]
  @param[in]       f_SensorYPosition                   Not in use
                                                       Supported values are [Full range of float32]
  @param[in]       f_SlipAngleTgtSync                  Not in use
                                                       Supported values are [Full range of float32]
  @param[in]       f_SlipAngleVarTgtSync               Not in use
                                                       Supported values are [Full range of float32]

  @return          none
                   
  @author          Norman Apel

*****************************************************************************/
void CML_v_calcCOFEgomotionMatrices(CML_t_TrafoMatrix2D * p_TrafoMatrix2DCOFForwardTgtSync,
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
    fTime_t     f_CycleTime)
{
    float32 f_YawAngle,
        f_YawAngleJitter;
    float32 f_DrivenDistance;
    float32 f_sinTmp = 0.0f,  /* temporary variable for sinus result */
        f_cosTmp = 0.0f;  /* temporary variable for cosinus result */
    float32 f_temp1, f_temp2, f_temp3, f_temp4; 

    GDBTrafoMatrix2D_t COF2COG,TMOT,RMOT,TJMOT,RJMOT,COG2COF,M_tmp;

    f_YawAngle        = f_YawRateTgtSync * f_CycleTime;  

    /* f_DrivenDistance  = (f_EgoSpeedXTgtSync * f_CycleTime) + (((0.5f * f_EgoAccelXTgtSync) * f_CycleTime) * f_CycleTime);
    Code modified to maintain consistency between MSVC & C66x*/
    f_temp1 = f_EgoSpeedXTgtSync * f_CycleTime;
    f_temp2 = 0.5f * f_EgoAccelXTgtSync;
    f_temp3 = f_temp2 * f_CycleTime;
    f_temp4 = f_temp3 * f_CycleTime;
    f_DrivenDistance = f_temp1 + f_temp4;

    /*Calculate Matrices*/
    M_tmp.TrafoType = TRANSLATION_;
    M_tmp.f00 = 1.0f;
    M_tmp.f10 = 0.0f; 
    M_tmp.f02 = 0.0f;
    M_tmp.f12 = 0.0f;

    COF2COG.TrafoType = TRANSLATION_;
    COF2COG.f00 = 1.0f;
    COF2COG.f10 = 0.0f; 
    COF2COG.f02 = f_SensorXPosition;
    COF2COG.f12 = 0.0f;

    COG2COF.TrafoType = TRANSLATION_;
    COG2COF.f00 = 1.0f;
    COG2COF.f10 = 0.0f; 
    COG2COF.f02 = -1.0f * f_SensorXPosition;
    COG2COF.f12 = 0.0f;

    RMOT.TrafoType = ROTATION_;
    CML_f_sincos(-1.0f * f_YawAngle, &f_sinTmp, &f_cosTmp);
    RMOT.f00 = f_cosTmp;
    RMOT.f10 = f_sinTmp;
    RMOT.f02 = 0.0f;   
    RMOT.f12 = 0.0f;  

    TMOT.TrafoType = TRANSLATION_;
    TMOT.f00 = 1.0f;
    TMOT.f10 = 0.0f; 
    /* to avoid division by zero */
    if( CML_f_Abs(f_YawAngle) <= CML_f_Delta  ) 
    {     
        TMOT.f02 = -1.0f * f_DrivenDistance;
        TMOT.f12 = 0.0f;
    }
    else
    { 
        /*Code modified to maintain consistency between MSVC & C66x*/
        //TMOT.f02 = (f_DrivenDistance / f_YawAngle) * RMOT.f10;
        f_temp1 = f_DrivenDistance / f_YawAngle;
        TMOT.f02 = f_temp1 * RMOT.f10;

        //TMOT.f12 = (f_DrivenDistance / f_YawAngle) * (1.0f - RMOT.f00);
        f_temp2 = 1.0f - RMOT.f00;
        TMOT.f12 = f_temp1 * f_temp2;
    }  

    /*! @todo write as one line to avoid runtime because of memcopying*/
    M_tmp = CML_TrafoMatrix2DMult(COF2COG,M_tmp);/*center front to center of gravity*/
    M_tmp = CML_TrafoMatrix2DMult(TMOT,M_tmp);/*translation trough motion*/
    M_tmp = CML_TrafoMatrix2DMult(RMOT,M_tmp);/*rotation trough motion*/
    M_tmp = CML_TrafoMatrix2DMult(COG2COF,M_tmp);/*center of gravity to front*/
    *p_TrafoMatrix2DCOFForwardTgtSync = M_tmp;

    if(f_YawRateMaxJitterTgtSync > 0.0f)
    {
        /*Code modified to maintain consistency between MSVC & C66x*/
        //f_YawAngleJitter  = (f_YawRateTgtSync + f_YawRateMaxJitterTgtSync + CML_f_Sqrt(f_YawRateVarTgtSync)) * f_CycleTime;
        f_temp1 = f_YawRateTgtSync + f_YawRateMaxJitterTgtSync;
        f_temp2 = CML_f_Sqrt(f_YawRateVarTgtSync);
        f_temp3 = f_temp1 + f_temp2;
        f_YawAngleJitter = f_temp3 * f_CycleTime;
    }
    else
    {
        /*Code modified to maintain consistency between MSVC & C66x*/
        //f_YawAngleJitter  = ((f_YawRateTgtSync + f_YawRateMaxJitterTgtSync) - CML_f_Sqrt(f_YawRateVarTgtSync)) * f_CycleTime;
        f_temp1 = f_YawRateTgtSync + f_YawRateMaxJitterTgtSync;
        f_temp2 = CML_f_Sqrt(f_YawRateVarTgtSync);
        f_temp3 = f_temp1 - f_temp2;
        f_YawAngleJitter = f_temp3 * f_CycleTime;
    }
    RJMOT.TrafoType = ROTATION_;
    CML_f_sincos(-1.0f * f_YawAngleJitter, &f_sinTmp, &f_cosTmp);
    RJMOT.f00 = f_cosTmp;
    RJMOT.f10 = f_sinTmp;
    RJMOT.f02 = 0.0f;
    RJMOT.f12 = 0.0f;
    TJMOT.TrafoType = TRANSLATION_;
    TJMOT.f00 = 1.0f;
    TJMOT.f10 = 0.0f;
    /* to avoid division by zero */
    if( CML_f_Abs(f_YawAngleJitter) <= CML_f_Delta  )
    {
        TJMOT.f02 = -1.0f * f_DrivenDistance;
        TJMOT.f12 = 0.0f;
    }
    else
    {
        /* The following lines of code implement */ 
        //TJMOT.f02 = (f_DrivenDistance / f_YawAngleJitter) * RJMOT.f10;
        //TJMOT.f12 = (f_DrivenDistance / f_YawAngleJitter) * (1.0f - RJMOT.f00);
        f_temp1 = f_DrivenDistance / f_YawAngleJitter;
        f_temp2 = 1.0f - RJMOT.f00;
        TJMOT.f02 = f_temp1 * RJMOT.f10;
        TJMOT.f12 = f_temp1 * f_temp2; 
    }

    /*Calculate Matrices*/
    M_tmp.TrafoType = TRANSLATION_;
    M_tmp.f00 = 1.0f;
    M_tmp.f10 = 0.0f; 
    M_tmp.f02 = 0.0f;
    M_tmp.f12 = 0.0f;
    /*! @todo write as one line to avoid runtime because of memcopying*/
    M_tmp = CML_TrafoMatrix2DMult(COF2COG,M_tmp);/*center front to center of gravity*/
    M_tmp = CML_TrafoMatrix2DMult(TJMOT,M_tmp);/*translation trough motion*/
    M_tmp = CML_TrafoMatrix2DMult(RJMOT,M_tmp);/*rotation trough motion*/
    M_tmp = CML_TrafoMatrix2DMult(COG2COF,M_tmp);/*center of gravity to front*/
    *p_TrafoMatrix2DCOFForJitTgtSync = M_tmp;

 /* PRQA S 3119 10 */
/* Deactivate QAC warning 3119, Date: 2019-06-17; Reviewer: uidk9586;
   Reason: The function is reviewed. Ignore these variables for the moment. */
   /* Deactivate QA-C warning 3112; Reviewer: S. Schwarzkopf; 
    Date: 04.12.2014; Reason: Translate MISRA/PCLINT suppression below.
    Review-ID: 3942463 */
    /* PRQA S 3112 4 */
    /* <ln_offset:1to3 MISRA Rule 14.2: reviewer name: Daniel Meschenmoser date: 2012-09-07 reason: ignore fSensorYPosition, fSlipAngleTgtSync, and fSlipAngleVarTgtSync for the moment  */
    CML_UNREFERENCED_FORMAL_PARAMETER(f_SensorYPosition);
    CML_UNREFERENCED_FORMAL_PARAMETER(f_SlipAngleTgtSync);
    CML_UNREFERENCED_FORMAL_PARAMETER(f_SlipAngleVarTgtSync);
    /* <ln_offset:+1 PCLINT Error 550: reviewer name: Daniel Meschenmoser date: 2012-09-07 reason: ignore fSensorYPosition, fSlipAngleTgtSync, and fSlipAngleVarTgtSync for the moment  */
}

/*****************************************************************************
  Functionname:    CML_v_calcForwardTrafoEgomotionMatrix                */ /*!

  @brief           Calculate Transformation Matrices for Egomotion Compensation 
                   of COF (Coordinate system Of vehicle Front) for EM_V6
                   
  @description     This function calculate forward transformation 
                   Matrix for Egomotion Compensation of COF 
                   (Coordinate system Of vehicle Front)

  @param[in]       f_EgoSpeedXTgtSync :                The ego motion speed
                                                       Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_EgoAccelXTgtSync :                The ego acceleration
                                                       Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_YawRateTgtSync :                  The ego yaw rate
                                                       Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_SensorXPosition :                 sensor x position
                                                       Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_CycleTime :                       sensor cycle time
                                                       Optimal values are [-F_MAX,..,F_MAX]
                                                       where F_MAX is the fourth root of max range of float32.
  @param[out]      p_TrafoMatrix2DCOFForwardTgtSync :  pointer to buffer for forward transformation matrix
                                                       [Valid matrix structure pointer]
                                                       Supported values for p_TrafoMatrix2DCOFForwardTgtSync->TrafoType are 0,1,2.
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f00 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f02 is [Full range of float32]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f10 is [0,..,1]
                                                       Range for p_TrafoMatrix2DCOFForwardTgtSync->f12 is [Full range of float32]
  @param[in]       f_SensorYPosition                   Not in use
                                                       Supported values are [Full range of float32]

  @return          none
                   
  @author          uidq1491

*****************************************************************************/
void CML_v_calcForwardTrafoEgomotionMatrix(CML_t_TrafoMatrix2D * p_TrafoMatrix2DCOFForwardTgtSync,
    fVelocity_t f_EgoSpeedXTgtSync,
    fVelocity_t f_EgoAccelXTgtSync,
    fYawRate_t  f_YawRateTgtSync,
    fDistance_t f_SensorXPosition,
    fDistance_t f_SensorYPosition,
    fTime_t     f_CycleTime)
{
    float32 f_YawAngle;
    float32 f_DrivenDistance;
    float32 f_sinTmp = 0.0f,  /* temporary variable for sinus result */
        f_cosTmp = 0.0f;  /* temporary variable for cosinus result */

    GDBTrafoMatrix2D_t COF2COG,TMOT,RMOT,COG2COF,M_tmp;

    f_YawAngle        = f_YawRateTgtSync * f_CycleTime;  
    f_DrivenDistance  = (f_EgoSpeedXTgtSync * f_CycleTime) + (((0.5f * f_EgoAccelXTgtSync) * f_CycleTime) * f_CycleTime);

    /*Calculate Matrices*/
    COF2COG.TrafoType = TRANSLATION_;
    COF2COG.f00 = 1.0f;
    COF2COG.f10 = 0.0f; 
    COF2COG.f02 = f_SensorXPosition;
    COF2COG.f12 = 0.0f;

    COG2COF.TrafoType = TRANSLATION_;
    COG2COF.f00 = 1.0f;
    COG2COF.f10 = 0.0f; 
    COG2COF.f02 = -1.0f * f_SensorXPosition;
    COG2COF.f12 = 0.0f;

    RMOT.TrafoType = ROTATION_;
    CML_f_sincos(-1.0f * f_YawAngle, &f_sinTmp, &f_cosTmp);
    RMOT.f00 = f_cosTmp;
    RMOT.f10 = f_sinTmp;
    RMOT.f02 = 0.0f;   
    RMOT.f12 = 0.0f;  

    TMOT.TrafoType = TRANSLATION_;
    TMOT.f00 = 1.0f;
    TMOT.f10 = 0.0f; 
    /* to avoid division by zero */
    if( CML_f_Abs(f_YawAngle) <= CML_f_Delta  ) 
    {     
        TMOT.f02 = -1.0f * f_DrivenDistance;
        TMOT.f12 = 0.0f;
    }
    else
    { 
        TMOT.f02 = (f_DrivenDistance / f_YawAngle) * RMOT.f10;
        TMOT.f12 = (f_DrivenDistance / f_YawAngle) * (1.0f - RMOT.f00);
    }  

    /*! @todo write as one line to avoid runtime because of memcopying*/
    M_tmp = COF2COG;                              /*center front to center of gravity*/
    M_tmp = CML_TrafoMatrix2DMult(TMOT,M_tmp);    /*translation trough motion*/
    M_tmp = CML_TrafoMatrix2DMult(RMOT,M_tmp);    /*rotation trough motion*/
    M_tmp = CML_TrafoMatrix2DMult(COG2COF,M_tmp); /*center of gravity to front*/
    *p_TrafoMatrix2DCOFForwardTgtSync = M_tmp;


/* PRQA S 3119 12 */
/* Deactivate QAC warning 3119, Date: 2019-06-17; Reviewer: uidk9586;
   Reason: The function is reviewed. Ignore these variables for the moment. */
    /* Deactivate QA-C warning 3112; Reviewer: S. Schwarzkopf; 
    Date: 04.12.2014; Reason: Translate MISRA/PCLINT suppression below.
    Review-ID: 3942463 */
    /* PRQA S 3112 4 */
    /* <ln_offset:1to3 MISRA Rule 14.2: reviewer name: Daniel Meschenmoser date: 2012-09-07 reason: ignore fSensorYPosition, fSlipAngleTgtSync, and fSlipAngleVarTgtSync for the moment  */
    CML_UNREFERENCED_FORMAL_PARAMETER(f_SensorYPosition);
    /* <ln_offset:+1 PCLINT Error 550: reviewer name: Daniel Meschenmoser date: 2012-09-07 reason: ignore fSensorYPosition, fSlipAngleTgtSync, and fSlipAngleVarTgtSync for the moment  */
}

/*****************************************************************************
  Functionname:    CML_f_getPickupDist                                  */ /*!

  @brief           Calculate pickup distance for distance control
  
  @description     Calculate the pickup distance for distance control with given
                   ego speed and deceleration, target speed, desired gap time and 
                   latency time. The pick up distance is calculated only when Ego 
                   deceleration is greater than the minimum acceptable value (~ >0).
                   Otherwise a value of 0 is returned.
                   If PD = Pickup distance,
                      OS = Object Rel speed,
                      ES = Ego speed,
                      ED = Ego deceleration,
                      GT = Gap time
                      LT = Latency time,
                   then,
                      PD = (((ES+OS)*((GT-LT)-(OS/ED)))+(ES*(LT+(OS/ED))))-((OS*OS)/(2*ED))


  @param[in]       f_ObjRelSpeed :      actual object rel speed
                                        Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_EgoSpeed :         actual ego speed
                                        Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_EgoDeceleration :  assuemd deceleration while distance control (larger than 0)
                                        Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_GapTime :          desired time gap after distance control
                                        Optimal values are [-F_MAX,..,F_MAX]
  @param[in]       f_LatencyTime :      assumed latency of distance control
                                        Optimal values are [-F_MAX,..,F_MAX]
                                        where F_MAX is the fourth root of max range of float32.

  @return          the pickup distance in the given situation (returns 0.f if fEgoDeceleration < CML_f_Delta)
                   
  @author          Normal Apel

*****************************************************************************/
/* PRQA S 1298 10 */
/* Deactivate QAC warning 1298, Date: 2019-06-17; Reviewer: uidk9586;
   Reason: There is no risk in violating this rule  as this is an initialization*/
float32 CML_f_getPickupDist(float32 f_ObjRelSpeed, float32 f_EgoSpeed, float32 f_EgoDeceleration, float32 f_GapTime, float32 f_LatencyTime)
{
    float32 f_Dist;
    float32 f_ObjSpeed = f_EgoSpeed + f_ObjRelSpeed;
    float32 f_Temp = 0, f_temp0,f_temp1, f_temp2, f_temp3, f_temp4, f_temp5;

    if (f_EgoDeceleration >= CML_f_Delta)
    {
        f_Temp = f_ObjRelSpeed / f_EgoDeceleration;
    }
    if (f_EgoDeceleration < CML_f_Delta)
    {
        f_Dist = 0.f;
    }
    else
    {
        /* The below code implement 
        "f_Dist = ((f_ObjSpeed * ((f_GapTime - f_LatencyTime) - (f_ObjRelSpeed/f_EgoDeceleration))) + 
        (f_EgoSpeed * (f_LatencyTime + (f_ObjRelSpeed / f_EgoDeceleration))))
        - (0.5F * (CML_Sqr(f_ObjRelSpeed) / f_EgoDeceleration));"   
        Code modified to maintain consistency between MSVC & C66x */

        //(0.5F * (CML_Sqr(f_ObjRelSpeed) / f_EgoDeceleration))
        f_temp1 = f_Temp * f_ObjRelSpeed;
        f_temp2 = 0.5F * f_temp1;

        //(f_EgoSpeed * (f_LatencyTime + (f_ObjRelSpeed / f_EgoDeceleration)))
        f_temp3 = f_LatencyTime + f_Temp;
        f_temp4 = f_EgoSpeed * f_temp3;

        //(f_ObjSpeed * ((f_GapTime - f_LatencyTime) - (f_ObjRelSpeed/f_EgoDeceleration)))
        f_temp3 = f_GapTime - f_LatencyTime;
        f_temp5 = f_temp3 - f_Temp;
        f_temp0 = f_ObjSpeed * f_temp5;

        f_temp3 = f_temp0 + f_temp4;
        f_Dist = f_temp3 - f_temp2;
    }
    return f_Dist;
}

/*****************************************************************************
  Functionname:    CML_f_computeClothoidLateralDistance                 */ /*!

  @brief           Compute the y-distance of a clothoid for a given x-distance
  
  @description     Compute the y-distance of a clothoid for a given x-distance.
                   The lateral distance of clothoid is calculated as follows:
                   Let, A  = the heading direction or angle,
                        X  = the length,
                        Y  = lateral displacement,
                        C0 = the initial curvature,
                        C1 = curvature change,
                   then,
                        Y  = (A*X)+((C0*X*X)/2)+((C1*X*X*X)/6)
                   
                     Limitation : Since the inputs and output datatypes are same, 
                     the function fails to store the results for higher values when 
                     the result exceeds the float range.

  @param[in]       f_Xpos :  distance (x-direction)
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_C0 :    Curvature
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_C1 :    Curvature change
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_Angle : Yaw Angle between car and road axis
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.

  @return          y-distance of a clothoid for a given x-distance
                   
  @author          Philippe Dintzer

*****************************************************************************/
float32 CML_f_computeClothoidLateralDistance (float32 f_Xpos, float32 f_C0, float32 f_C1, float32 f_Angle)
{
    /* The below code lines splitted & implemented to get consistency between CCS & MSVC
    float32 f_Tmp  = f_Xpos*f_Xpos*0.5f;
    return ( (f_Angle*f_Xpos) + (f_C0*f_Tmp) + (f_C1*f_Xpos*f_Tmp*(1.0f/3.0f)) ); */
    float32 f_Tmp;
    float32 f_Tmp0;
    float32 f_Tmp1;
    float32 f_Tmp2;
    float32 f_Tmp3;
    float32 f_Tmp4;
    float32 f_Tmp5;
    float32 f_Tmp6;

    f_Tmp0 = f_Xpos*f_Xpos;
    f_Tmp = f_Tmp0*0.5f;		//f_Xpos*f_Xpos*0.5f;
    f_Tmp1 = f_Angle*f_Xpos;	//(f_Angle*f_Xpos)
    f_Tmp2 = f_C0*f_Tmp;		//(f_C0*f_Tmp)
    f_Tmp3 = f_C1*f_Xpos;
    f_Tmp4 = 1.0f/3.0f;
    f_Tmp5 = f_Tmp*f_Tmp3;
    f_Tmp6 = f_Tmp5 * f_Tmp4;	//(f_C1*f_Xpos*f_Tmp*(1.0f/3.0f))
    f_Tmp4 = f_Tmp1 + f_Tmp2;
    f_Tmp1 = f_Tmp4 + f_Tmp6;
    return f_Tmp1;
}

/*****************************************************************************
  Functionname:    CML_v_lowPassFilter2                                 */ /*!

  @brief           simple first order lowpass filter
                 
  @description     This function is an implementation of simple first order
                   lowpass filter. This determines the output sample in terms of
                   the input sample and preceding output.
                   So if x = input, y = output and z = previous output, and 
                   a = filter coefficient, then,
                   y = (a*x) + ((1-a)*z)        
  
  @param[in,out]   f_Old :   old value (in), filtered value (out)
                             Valid float pointer.
                             Supported value for data [Full range of float32]
  @param[in]       f_New :   new value
                             Supported value [Full range of float32]
  @param[in]       f_Alpha : filter coefficient
                             Optimal Values [0,..,1]

  @return          none
                   
  @author          Peter Seydel
  
*****************************************************************************/
void CML_v_lowPassFilter2(float32 * f_Old, float32 f_New, float32 f_Alpha)
{
    /* Code lines are splitted to maintain consistency between CCS & MSVC
    float32 f_Dummy;
    f_Dummy = (f_Alpha * f_New) + ((1.f - f_Alpha) * (*f_Old));
    *f_Old = f_Dummy; */
     float32 f_dummy;
     f_dummy = (float32)CML_f_MultAdd(-f_Alpha, *f_Old, *f_Old);
     *f_Old = (float32)CML_f_MultAdd(f_Alpha, f_New, f_dummy);
}

/************************************************************************
  Functionname:    CML_calculateDistancePoint2Circle               */ /*!

  @brief           Calculates the distance from point to circle
                   (trajectory)

  @description     This function calculates various trajectory reference 
                   point parameters including the x and y cordinates,
                   distance to trajectory and distance from vehicle center 
                   of gravity to object on trajectory.                                                                         

                                X

                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------

                   


  @param[in]       f_X :  X cordinate of the point
                          Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                          MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_Y :  Y cordinate of the point
                          Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                          MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_C0 : Curvature
                          Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                          MAX_VAL is fourth root of maximum value of float32.

  @return          Trajectory reference point structure

  @post            -

  @todo            initial version

  @author          Norman Apel, Grant Davtjan
**************************************************************************** */
CML_t_TrajRefPoint CML_calculateDistancePoint2Circle(float32 f_X, float32 f_Y, float32 f_C0)
{
    float32 f_Radius         = RADIUS_INIT_VALUE;
    float32 f_R              = 0.f;
    float32 f_DistToCourse   = 0.f;
    float32 f_DistOnCourse   = 0.f;
    float32 f_NormVecX       = 0.f;
    float32 f_NormVecY       = 0.f;
    float32 f_RefCourseDistX = 0.f;
    float32 f_RefCourseDistY = 0.f;
    float32 f_temp1,f_temp2,f_temp3;
    CML_t_TrajRefPoint ReferencePoint;

    if (fABS( f_C0 ) > CURVATURE_USE_CIRCLE_EQUATION)
    {
        f_Radius = 1.0f/(f_C0);
        /* Object Transform to Moment Pole Coordinates */    
        f_Y-=f_Radius;

        /*The below code implement "f_R = SQRT_(SQR(f_X) + SQR(f_Y));"
        The code is modified to maintain consistency between MSVC & C66x */
        f_temp1 = SQR(f_X);
        f_temp2 = SQR(f_Y);
        f_temp3 = f_temp1 + f_temp2; 
        f_R = SQRT_(f_temp3);

        /* Check for divison by zero */
        /* Check for divison by zero */
        if (CML_f_IsZero(f_R))
        {
            /* Distances are zero */
        }
        else
        {
            /* NormVec to Course always pointing to the left side of course */
            if(f_C0 > 0.0f)
            {
                f_NormVecX = -f_X/f_R;
                f_NormVecY = -f_Y/f_R;
                f_DistToCourse = (fABS(f_Radius)-f_R);	

                /* The below code implement "f_DistOnCourse = f_Radius * (C_HALFPI + ATAN2_(f_Y, f_X));
                The code is modified to maintain consistency between MSVC & C66x */
                f_temp1 = ATAN2_(f_Y, f_X);
                f_temp2 = C_HALFPI + f_temp1;
                f_DistOnCourse = f_Radius * f_temp2;
            }
            else
            {
                f_NormVecX = f_X/f_R;
                f_NormVecY = f_Y/f_R;

                /* The below code implement 
                "f_DistToCourse = -(fABS(f_Radius)-f_R);		
                f_DistOnCourse = f_Radius * (ATAN2_(f_Y, f_X) - C_HALFPI);"
                The code is modified to maintain consistency between MSVC & C66x*/
                f_temp1 = fABS(f_Radius);
                f_DistToCourse = -(f_temp1-f_R);	
                f_temp1 = ATAN2_(f_Y, f_X);
                f_temp2 = f_temp1 - C_HALFPI; 
                f_DistOnCourse = f_Radius * f_temp2;
            }
            /* DistCourse (fRadius-fR) positive when object left of course; negative when object right of course*/
            /* |RefCourseDistXRef| + DistCourse * |dNormVec[0]| = |fX| */
            /* |RefCourseDistYRef|                |dNormVec[1]|   |fY| */

            //f_RefCourseDistX =  f_X - (f_NormVecX * f_DistToCourse);
            f_temp1 = f_NormVecX * f_DistToCourse;
            f_RefCourseDistX = f_X - f_temp1;

            //f_RefCourseDistY = (f_Y - (f_NormVecY * f_DistToCourse) ) + f_Radius;
            f_temp2 = f_NormVecY * f_DistToCourse;
            f_temp3 = f_Y - f_temp2;
            f_RefCourseDistY = f_temp3 + f_Radius;
        }
    }
    else
    {
        /* use old parabolic approximation for wide curves and distance in Y- Direction*/
        f_RefCourseDistX    = f_X;    
        //f_RefCourseDistY    = SQR( f_X ) * (f_C0) * (0.5f);
        f_temp1 = SQR( f_X );
        f_temp2 = f_temp1 * f_C0;
        f_RefCourseDistY = f_temp2 * 0.5f;

        f_DistToCourse = (f_Y - f_RefCourseDistY);
        /*instead of integral 0 to fX of function SQRT(1+(fC0*x)^2) dx*/
        f_DistOnCourse = f_X;
    }
    ReferencePoint.f_X              = f_RefCourseDistX;
    ReferencePoint.f_Y              = f_RefCourseDistY;
    ReferencePoint.f_DistToTraj     = f_DistToCourse;
    ReferencePoint.f_DistOnTraj     = f_DistOnCourse;

    return ReferencePoint;
}

/************************************************************************
  Functionname:    CML_f_approximateRefPoint                         */ /*!

  @brief           calculates X value of the normal crossing from object
                   to clothoid tangent at last approximated X value  

  @description     This function calculates X value of the normal crossing 
                   from object to clothoid tangent at last approximated X 
                   value  
                   

                                X

                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------

                   


  @param[in]       f_X :     Obj X
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_Y :     Obj Y
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_C0 :    C0 of 3 degree clothoid polynom
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_C1 :    C1 of 3 degree clothoid polynom 
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_RefX :  last approximated X value of Reference point 
                             Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                             MAX_VAL is fourth root of maximum value of float32.

  @return          Approximated X value of Reference point 

  @post            -

  @todo            initial version

  @author          Norman Apel, Grant Davtjan
**************************************************************************** */
static float32 CML_f_approximateRefPoint(float32 f_X, float32 f_Y, float32 f_C0, float32 f_C1, float32 f_RefX)
{
    float32 f_Xc = f_RefX;
    float32 f_XXc = SQR(f_Xc);
    float32 f_C1XXc = f_C1*f_XXc;
    float32 f_C0Xc = f_C0*f_Xc;
    float32 f_Yc;
    float32 f_m;
    float32 f_m_inv;
    float32 f_temp1,f_temp2,f_temp3,f_temp4;

    /* The below lines of code implement : f_Yc = (C_SIXTH*f_C1XXc*f_Xc) + (0.5f*f_C0Xc*f_Xc);
    The code is modified to maintain consistency between MSVC & C66x */ 
    f_temp1 = C_SIXTH*f_C1XXc;
    f_temp2 = f_temp1*f_Xc;
    f_temp3 = 0.5f*f_C0Xc;
    f_temp4 = f_temp3*f_Xc;
    f_Yc = f_temp2 + f_temp4;

    /* The below lines of code implement :f_m = ((0.5f*f_C1XXc)+f_C0Xc); 
    The code is modified to maintain consistency between MSVC & C66x */ 
    f_temp1 = 0.5f*f_C1XXc;
    f_m = f_temp1 + f_C0Xc;

    if(fABS(f_m) < CML_f_Delta)
    {
        f_RefX = f_X;
    }
    else
    {
        /*The below lines of code implement:f_RefX = ( ((f_Y - f_Yc) + (f_m*f_Xc)) + (f_m_inv*f_X) ) / ( f_m + f_m_inv );
        The code is modified to maintain consistency between MSVC & C66x */
        f_m_inv  = 1.0f/f_m; 
        f_temp1 = f_Y - f_Yc;
        f_temp2 = f_m*f_Xc;
        f_temp3 = f_temp1 + f_temp2;

        f_temp1 = f_m_inv*f_X;
        f_temp4 = f_temp3 + f_temp1;

        f_temp3 = f_m + f_m_inv;
        f_RefX = f_temp4 / f_temp3;
    }

    return f_RefX;
}

/************************************************************************
  Functionname:    CML_calculateDistancePoint2Clothoid             */ /*!

  @brief           Calculates distance from point to clothoid

  @description     This function computes and returns the parameters of 
                   the trajectory reference point structure including the 
                   x and y cordinates, distance to trajectory and distance 
                   from vehicle center of gravity to object on trajectory. 
                                                                          

                                X

                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------

                   


  @param[in]       f_X : X coordinate of point
                         Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                         MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_Y : Y coordinate of point
                         Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                         MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_C0 : Coefficient 0
                         Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                         MAX_VAL is fourth root of maximum value of float32.
  @param[in]       f_C1 : Coefficient 1
                         Optimal range is [-MAX_VAL,..,MAX_VAL], where 
                         MAX_VAL is fourth root of maximum value of float32.

  @return          Trajectory reference point structure

  @post            -

  @todo            initial version

  @author          Norman Apel, Grant Davtjan
**************************************************************************** */
CML_t_TrajRefPoint CML_calculateDistancePoint2Clothoid(float32 f_X, float32 f_Y, float32 f_C0, float32 f_C1)
{
    float32 f_Temp;
    float32 f_YDiff;  
    float32 f_temp1,f_temp2,f_temp3,f_temp4;
    CML_t_TrajRefPoint ReferencePoint;

    ReferencePoint.f_X          = f_X;
    ReferencePoint.f_X          = CML_f_approximateRefPoint(f_X, f_Y, f_C0, f_C1, ReferencePoint.f_X);
    f_Temp                      = SQR(ReferencePoint.f_X);

    /*The below lines of code implement: ReferencePoint.f_Y = (0.5f*f_C0*f_Temp) + ((f_C1*f_Temp*ReferencePoint.f_X) * C_SIXTH);
    The code is modified to maintain consistency between MSVC & C66x */
    f_temp1 = 0.5f * f_C0;
    f_temp2 = f_temp1 * f_Temp;

    f_temp3 = f_C1 * f_Temp;
    f_temp4 = f_temp3 * ReferencePoint.f_X;
    f_temp1 = f_temp4 * C_SIXTH;
    ReferencePoint.f_Y  = f_temp2 + f_temp1;

    f_YDiff = f_Y - ReferencePoint.f_Y;

    /*The below lines of code implement: ReferencePoint.f_DistToTraj = SQRT_(SQR(f_X - ReferencePoint.f_X)+SQR(f_YDiff));
    The code is modified to maintain consistency between MSVC & C66x */
    f_temp1 = f_X - ReferencePoint.f_X;
    f_temp2 = SQR(f_temp1);
    f_temp3 = SQR(f_YDiff);
    f_temp4 = f_temp2 + f_temp3;
    ReferencePoint.f_DistToTraj = SQRT_(f_temp4);

    if (f_YDiff < 0.0f)
    {
        ReferencePoint.f_DistToTraj *= -1.0f;
    }

    /*@todo implement arclength on clothoid approximation*/
    /*@hack use difference in x instead*/
    ReferencePoint.f_DistOnTraj = ReferencePoint.f_X;

    return ReferencePoint;
}

