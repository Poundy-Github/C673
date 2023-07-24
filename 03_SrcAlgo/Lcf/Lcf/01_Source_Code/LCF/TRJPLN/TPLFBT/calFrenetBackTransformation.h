/*********************************************************************

PROJECT:        TJA Base Development

MODULE:         Trajectory Planning

Type:           C-Header

CPU:            All

DESCRIPTION:    S-Funktion calFrenetBackTransformation

AUTHOR:         JiYa, JaAl

********************************************************************************

<HISTORY>
#<version>  <modify-date>   <owner>     <comment>
            14.05.2013      JiYa        Neuerstellung
            13.11.2015      JaAl        Removed Dependency on BMW tmwtypes.h
            25.11.2015      DoFr        Translation German -> English
<NEW>
</NEW>
</HISTORY>

*********************************************************************/

#ifndef CALFRENETRUECKTRANSFORMATION_H_
#define CALFRENETRUECKTRANSFORMATION_H_

/* -----------------------------------------------------------------------------

    I N C L U D E S

 * -----------------------------------------------------------------------------
*/

#include "calFrenetBackTransformation_TypeDef.h"

/* -----------------------------------------------------------------------------

    D E C L A R A T I O N   F U N C T I O N S

 * -----------------------------------------------------------------------------
*/

/* -----------------------------------------------------------------------------
    \brief Calculate Frenet back transformation (Frenet -> Vehicle).
    
    \param Inputs Frenet back transformation inputs
    
    \return 
 * -----------------------------------------------------------------------------
*/
calFBTOutType calFrenetBackTransformation(const calFBTInType* Inputs);

/* -----------------------------------------------------------------------------
    \brief Calculate the change of curvature of the trajectory
    
    \param 
    
    \return 
 * -----------------------------------------------------------------------------
*/
float32 TrajCalc_FBT_CalcTrajChgOfCurvature(float32 deltaTheta, float32 Kr, float32 Kr_p, float32 d, float32 d_p, float32 d_pp, float32 d_ppp, float32 Kt, float32 v_Bahn);

/* -----------------------------------------------------------------------------

    H E L P E R   F U N C T I O N S

 * -----------------------------------------------------------------------------
*/

/* -----------------------------------------------------------------------------
    \brief Avoid zero values 
    
    \param input
    
    \return 
    
    \DOORS 13687
 * -----------------------------------------------------------------------------
*/
float32	TrajCalc_FBT_AvoidZero(const float32 input);

#endif	/* _CALFRENETRUECKTRANSFORMATION_H */
