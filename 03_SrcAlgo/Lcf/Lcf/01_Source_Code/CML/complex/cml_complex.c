/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_complex.c

  DESCRIPTION:               functions related to complex values and their transformation

  AUTHOR:                    Fabian Diewald

  CREATION DATE:             17.10.2012


  VERSION:                   $Revision: 1.14.2.1 $

  ---*/ /*---
  CHANGES:                   $Log: cml_complex.c  $
  CHANGES:                   Revision 1.14.2.1 2019/06/21 15:15:05CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   QAF Level3 fixes for MFC431TA19
  CHANGES:                   Revision 1.14 2018/02/26 08:49:11CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.13 2017/11/14 18:41:44CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated to the code from AL_CML_01.09.13_INT-1
  CHANGES:                   Revision 1.12 2016/05/11 06:08:20CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.12 2016/05/11 06:08:20CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.12 2016/05/11 06:08:20CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.11 2015/08/25 05:48:20CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   - Added comments -  uidr5428 [Aug 25, 2015 5:48:21 AM CEST]
  CHANGES:                   Change Package : 360603:1 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.10 2015/04/29 13:29:48CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to the coding guidelines
  CHANGES:                     of variables.
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 1:29:49 PM CEST]
  CHANGES:                   Change Package : 324617:1 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.9 2014/12/04 15:46:45CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - changed input data CML_v_PhaseUnwrapping() from pointer to array as they are accessed this way
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 4, 2014 3:46:45 PM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.8 2014/07/01 13:23:44CEST Diewald, Fabian (uidt8878) 
  CHANGES:                   made cpl multiplication safe
  CHANGES:                   --- Added comments ---  uidt8878 [Jul 1, 2014 1:23:45 PM CEST]
  CHANGES:                   Change Package : 229461:10 http://mks-psad:7002/im/viewissue?selection=229461
  CHANGES:                   Revision 1.7 2014/04/08 10:34:56CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added function description for complex division
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 8, 2014 10:34:57 AM CEST]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.6 2014/03/25 11:29:03CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:29:03 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.5 2014/02/04 15:10:15CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:10:16 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.4 2013/10/30 17:05:00CET Heidenreich, Philipp (uidv9899) 
  CHANGES:                   corrected compiler warnings
  CHANGES:                   --- Added comments ---  uidv9899 [Oct 30, 2013 5:05:00 PM CET]
  CHANGES:                   Change Package : 176454:1 http://mks-psad:7002/im/viewissue?selection=176454
  CHANGES:                   Revision 1.3 2013/10/30 14:32:16CET Heidenreich, Philipp (uidv9899) 
  CHANGES:                   added/moved three functions (MultiplyComplex, DivideComplex and QuadraticEquationComplex)
  CHANGES:                   --- Added comments ---  uidv9899 [Oct 30, 2013 2:32:17 PM CET]
  CHANGES:                   Change Package : 176454:1 http://mks-psad:7002/im/viewissue?selection=176454
  CHANGES:                   Revision 1.2 2013/04/12 13:25:14CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Fix file header
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 12, 2013 1:25:14 PM CEST]
  CHANGES:                   Change Package : 159154:23 http://mks-psad:7002/im/viewissue?selection=159154

**************************************************************************** */
/* PRQA S 0288 EOF */
/* Deactivate QAF warning 0288, Date: 2019-06-18; Reviewer: uid22555;  
   Reason: There is no risk here as the warning is in comments and not in the source code. */

/* PRQA S 0380 10 */
/* Deactivate QAF warning 0380, Date: 2019-06-17; Reviewer: uid22555;  
   Reason: The warning is seen as number of macros exceeds 4095 which can not be avoided here. 
   Warning is analysed and no risk in suppressing this. */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cml_ext.h"

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_v_cartesian2Polar                                */ /*!
  
  @brief           Transforms a complex number from cartesian to polar representation.
  
  @description     Transforms a complex number from cartesian to polar representation.
                   The real and imaginary parts are used to calculate the amplitude 
                   and phase as follows:
                   Let the cartesian cordinates be (x,y) and polar cordinates be (r,ph)
                   then,        
                   r  = sqrt(x*x + y*y)
                   ph = atan(y/x)
  
  @param[in]       cartesian :  complex number cartesian
                                Optimal Range for cartesian.f_Real is [-F_MAX..F_MAX]
                                Optimal Range for cartesian.f_Imag is [-F_MAX..F_MAX]
                                where F_MAX is cube root of max range of float.
  @param[out]      p_polar :  pointer to complex number polar

  @return          void
  
  @author          Fabian Diewald

*****************************************************************************/
void CML_v_cartesian2Polar(const t_Complexf32 cartesian, t_ComplexPolarf32 * const p_polar)
{
  const float32 f_RootArg = CML_Sqr(cartesian.f_Real) + CML_Sqr(cartesian.f_Imag);
  
  if (CML_f_IsNonZero(cartesian.f_Real))
  {
    if (CML_f_IsNonZero(cartesian.f_Imag))
    {
      /* regular calculation, special cases in the case of real or imaginary part = 0 see below */
      p_polar->f_Phase      = ATAN2_(cartesian.f_Imag, cartesian.f_Real);
      p_polar->f_Amplitude  = CML_f_Sqrt(f_RootArg);
    }
    else if (cartesian.f_Real > 0.f)
    {
      /* imag = 0 and real > 0 -> angle = 0 degree */
      p_polar->f_Phase      = 0.0f;
      p_polar->f_Amplitude  = cartesian.f_Real;
    }
    else
    {
      /* imag = 0 and real < 0 -> angle = 180 degree */
      p_polar->f_Phase      = CML_f_Pi;
      p_polar->f_Amplitude  = -cartesian.f_Real;
    }
  }
  else if (CML_f_IsZero(cartesian.f_Imag))
  {
    /* real = 0 and imag = 0 -> angle = 0 (convention) */
    p_polar->f_Phase      = 0.0f;
    p_polar->f_Amplitude  = 0.0f;
  }
  else if (cartesian.f_Imag > 0.f)
  {
    /* real = 0 and imag > 0 -> angle = 90� */
    p_polar->f_Phase      = 0.5f*CML_f_Pi;
    p_polar->f_Amplitude  = cartesian.f_Imag;
  }
  else
  {
    /* real = 0 and imag < 0 -> angle = -90� */
    p_polar->f_Phase      = (-0.5f)*CML_f_Pi;
    p_polar->f_Amplitude  = -cartesian.f_Imag;
  }
}

/*****************************************************************************
  Functionname:    CML_v_polar2Cartesian                                */ /*!
  
  @brief           Transforms a complex number from polar to cartesian representation.
  
  @description     Transforms a complex number from polar to cartesian representation.
                   The amplitude and phase are used to calculate the real and imaginary parts
                   as follows:
                   Let the cartesian cordinates be (x,y) and polar cordinates be (r,ph)
                   then,        
                   x = r * cos(ph)
                   y = r * sin(ph)
  
  @param[in]       polar :  complex number polar
                            Range for polar.f_Amplitude [Full range of float]
                            Range for polar.f_Phase [Full range of float]
  @param[out]      p_cartesian :  complex number cartesian
  
  @return          void
  
  @author          Fabian Diewald

*****************************************************************************/
void CML_v_polar2Cartesian(const t_ComplexPolarf32 polar, 
                           t_Complexf32 * const p_cartesian)
{
  float32 f_Phase = polar.f_Phase,
          f_CosVal,
          f_SinVal;

/* PRQA S 3350 , 3339 6 */
/* Deactivate QAC warning 3350 , 3339, Date: 2019-06-18; Reviewer: uid22555;
   Reason: Comparison with Pi is needed here as per algorithm used. */
  /* otherwise COS_ can produce wrong values... */
  while (f_Phase < (-CML_f_Pi))
  {
    f_Phase += (2.f*CML_f_Pi);
  }
/* PRQA S 3350 , 3339 5 */
/* Deactivate QAC warning 3350,3339,  Date: 2019-06-18; Reviewer: uid22555;
     Reason: Comparison with Pi is needed here as per algorithm used. */
  while (f_Phase > CML_f_Pi)
  {
    f_Phase -= (2.f*CML_f_Pi);
  }

  f_CosVal = COS_(f_Phase);
  f_SinVal = SIN_(f_Phase);

  p_cartesian->f_Real = polar.f_Amplitude * f_CosVal;
  p_cartesian->f_Imag = polar.f_Amplitude * f_SinVal;
}

/*************************************************************************

  Functionname:    CML_v_phaseUnwrapping                            */ /*!
  
  @brief           Does a phase unwrapping for the phases of an array, 
                   can be adapted to array with elevation/monopulse feature 
                   by parameter.

  @description     This function Does a phase unwrapping for the phases of 
                   an array, can be adapted to array with elevation/monopulse 
                   feature by parameter. Here it considers the fact that phase
                   is 2pi periodic. It finds the phase which has the mininmum
                   difference to previous relevent phase.
  
  @param[in, out]  a_values :  complex polar values with phases to be unwrapped 
                            -> complex polar values with unwrapped phases
                               Range for a_values[].f_Amplitude [Full range of float]
                               Range for a_values[].f_Phase [Full range of float]
  @param[in]       u_NofChannels  :  number of the channels
                                     Range can be [Full range of uint32]
  @param[in]       u_NofSubarrays :  number of subarrays, 1u if no elevation 
                                     feature should be considered, so 1u
                                     is the value for default purposes
                                     Range can be [Full range of uint32]

  @return          void
  
  @author          Michael Eisenacher/Fabian Diewald
*/

/***************************************************************************/
void CML_v_phaseUnwrapping(t_ComplexPolarf32 a_values[], 
                           const uint32 u_NofChannels,
                           const uint32 u_NofSubarrays)
{
  /* loop counter */
  uint8 u_ChannelCounter;
  
  /* phase of previous channel during the loop over all channels */
  float32 f_PhasePrev;
  
  for (u_ChannelCounter = 1u; u_ChannelCounter < u_NofChannels; u_ChannelCounter++)
  {
    /* phase candidates which are higher and lower than previous relevant phase,
       initialized here to suppress compiler warning, although it is not needed */
    float32 f_PhaseHigh = 0.f;
    float32 f_PhaseLow  = 0.f;
  
    /* phase is 2pi periodic
       => find the phase which has minimum difference to previous relevant phase  */
    if (u_ChannelCounter < u_NofSubarrays)
    {
      /* between this and previous antenna minimize phase difference */
      f_PhasePrev = a_values[u_ChannelCounter-1u].f_Phase;
    }
    else
    {
      /*  for u_NofSubarrays-th antenna to the end, minimize phase 
          difference to antenna u_NofSubarrays before;
          this should provide a more robust phase unwrapping in the case 
          of an elevation feature, where there is a shift at every second phase */
      f_PhasePrev = a_values[u_ChannelCounter-u_NofSubarrays].f_Phase;
    }
  
    if ( f_PhasePrev < a_values[u_ChannelCounter].f_Phase )
    {
      f_PhaseLow = a_values[u_ChannelCounter].f_Phase;
/* PRQA S 3350 6 */
/* Deactivate QAC warning 3350, Date: 2019-06-18; Reviewer: uid22555;
   Reason: Comparison of two floating point variables are needed here as per algorithm used. */
      while (f_PhaseLow > f_PhasePrev)
      {
        f_PhaseHigh = f_PhaseLow;
        f_PhaseLow -= (2.f*CML_f_Pi);
      }
    }
    else
    {
      f_PhaseHigh = a_values[u_ChannelCounter].f_Phase;
/* PRQA S 3350 10 */
/* Deactivate QAC warning 3350, Date: 2019-06-18; Reviewer: uid22555;
     Reason: Comparison with a float number is needed here as per algorithm used. */
      while (f_PhaseHigh < f_PhasePrev)
      {
        f_PhaseLow = f_PhaseHigh;
        f_PhaseHigh += (2.f*CML_f_Pi);
      }
    }
  
    if ( (f_PhaseHigh-f_PhasePrev) < (f_PhasePrev-f_PhaseLow) )
    {
      a_values[u_ChannelCounter].f_Phase = f_PhaseHigh;
    }
    else
    {
      a_values[u_ChannelCounter].f_Phase = f_PhaseLow;
    }
  }
}

/*****************************************************************************
  Functionname :    CML_v_multiplyComplex                               */ /*!
  
  @brief            Multiplies two complex numbers
  
  @description      Multiplies two complex numbers under the condition which 
                    checks if the first number has to be multiplied by the 
                    second number as it is or by the conjugate of the second 
                    number.
  
  @param[in]        p_Fac1 :  Factor1 
                              Optimal Range for p_Fac1.f_Real is [-F_MAX..F_MAX]
                              Optimal Range for p_Fac1.f_Imag is [-F_MAX..F_MAX]
                              where F_MAX is square root of half the max range of float.
  @param[in]        p_Fac2 :  Factor2
                              Optimal Range for p_Fac2.f_Real is [-F_MAX..F_MAX]
                              Optimal Range for p_Fac2.f_Imag is [-F_MAX..F_MAX]
                              where F_MAX is square root of half the max range of float.
  @param[in]        b_Conj :  Factor2 complex conjugate
                              This value can be either TRUE or FALSE
  @param[out]       p_Prod :  Resulting product
  
  @return           void
  
  @author           Fabian Diewald

*****************************************************************************/

void CML_v_multiplyComplex(const t_Complexf32 *p_Fac1,
                           const t_Complexf32 *p_Fac2,
                           const boolean b_Conj,
                           t_Complexf32 *p_Prod)
{
  if (b_Conj == b_TRUE)
  {
	  p_Prod->f_Real = p_Fac1->f_Real * p_Fac2->f_Real;
	  p_Prod->f_Real = CML_f_MultAdd( p_Fac1->f_Imag, p_Fac2->f_Imag, p_Prod->f_Real);
	  p_Prod->f_Imag = p_Fac1->f_Real * (-p_Fac2->f_Imag);
	  p_Prod->f_Imag = CML_f_MultAdd( p_Fac1->f_Imag, p_Fac2->f_Real, p_Prod->f_Imag);
  }
  else
  {
	  p_Prod->f_Real = p_Fac1->f_Real * p_Fac2->f_Real;
	  p_Prod->f_Real = CML_f_MultAdd( (-p_Fac1->f_Imag), p_Fac2->f_Imag, p_Prod->f_Real);
	  p_Prod->f_Imag = p_Fac1->f_Real * p_Fac2->f_Imag;
	  p_Prod->f_Imag = CML_f_MultAdd( p_Fac1->f_Imag, p_Fac2->f_Real, p_Prod->f_Imag);
  }
}


/*****************************************************************************
  Functionname:    CML_v_divideComplex                                  */ /*!
  
  @brief           complex division
  
  @description     This function divides a complex numerator by a complex 
                   denominator.
  @attention       A division by 0 has to be avoided by user!
  
  @param[in]       p_Num :  Numerator
                            Optimal Range for p_Num.f_Real is [-F_MAX..F_MAX]
                            Optimal Range for p_Num.f_Imag is [-F_MAX..F_MAX]
                            where F_MAX is square root of half the max range of float.
  @param[in]       p_Denom :  Denominator
                              Optimal Range for p_Denom.f_Real is [-F_MAX..F_MAX]
                              Optimal Range for p_Denom.f_Imag is [-F_MAX..F_MAX]
                              where F_MAX is square root of half the max range of float.
  @param[out]      p_Quot :  Resulting quotient
  
  @return          void
  
  @author          Florian Engels

*****************************************************************************/

void CML_v_divideComplex(const t_Complexf32 *p_Num, 
                         const t_Complexf32 *p_Denom,
                         t_Complexf32 *p_Quot)
{
  const float32 f_MagRec = 1.f / (CML_Sqr(p_Denom->f_Real) + CML_Sqr(p_Denom->f_Imag));
  
p_Quot->f_Real = p_Num->f_Real * p_Denom->f_Real;
p_Quot->f_Real = CML_f_MultAdd(p_Num->f_Imag, p_Denom->f_Imag, p_Quot->f_Real);
p_Quot->f_Real *= f_MagRec;

p_Quot->f_Imag = p_Num->f_Real *(-p_Denom->f_Imag);
p_Quot->f_Imag = CML_f_MultAdd(p_Num->f_Imag, p_Denom->f_Real,p_Quot->f_Imag);
p_Quot->f_Imag *= f_MagRec;
}


/*****************************************************************************
  Functionname:    CML_v_quadraticEquationComplex                       */ /*!
  
  @brief           calculate the two solutions of z*z + p*z + q = 0
                   according to z1 = 0.5*(-p + sqrt(p*p - 4*q))
                            z2 = 0.5*(-p - sqrt(p*p - 4*q))
               
  @description     The function calculates the solution for the quadratic equation
                   z*z + p*z + q = 0. 
                   The two solutions to the quadratic equation is given by,
                   z1 = 0.5*(-p + sqrt(p*p - 4*q))
                   z2 = 0.5*(-p - sqrt(p*p - 4*q))
  
  @param[in]   p_p :  Complex polynomial coefficient
                          Optimal Range for p_p.f_Real is [-F_MAX..F_MAX]
                          Optimal Range for p_p.f_Imag is [-F_MAX..F_MAX]
                          where F_MAX is square root of half the max range of float.
  @param[in]   p_q :  Complex polynomial coefficient
                          Optimal Range for p_q.f_Real is [-F_MAX..F_MAX]
                          Optimal Range for p_q.f_Imag is [-F_MAX..F_MAX]
                          where F_MAX is one-eighth the max range of float.
                          Note: The value of (p*p - 4*q) for both real and imaginary part 
                          should be greater than or equal to 0
  @param[out]   p_z1 :  Complex solution 1
  @param[out]   p_z2 :  Complex solution 2
  
  @return          void
  
  @author          Philipp Heidenreich

*****************************************************************************/

void CML_v_quadraticEquationComplex(const t_Complexf32 *p_p, 
                                    const t_Complexf32 *p_q,
                                    t_Complexf32 *p_z1,
                                    t_Complexf32 *p_z2)
{
  t_Complexf32 t_Tmp;
  t_ComplexPolarf32 t_Root;

/* PRQA S 1295 10 */
/* Deactivate QAC warning 1295, Date: 2019-06-18; Reviewer: uid22555;
   Reason: There is no risk as there is no loss of data or change of data in this conversion */
  CML_v_multiplyComplex(p_p, p_p, 0u, &t_Tmp);

  t_Tmp.f_Real -= 4.0f*(p_q->f_Real); /* real(p*p - 4*q) */
  t_Tmp.f_Imag -= 4.0f*(p_q->f_Imag); /* imag(p*p - 4*q) */

  /* complex root calculation */
  CML_v_cartesian2Polar(t_Tmp, &t_Root);

  t_Root.f_Amplitude = CML_f_Sqrt(t_Root.f_Amplitude);
  t_Root.f_Phase *= 0.5f;

  CML_v_polar2Cartesian(t_Root, &t_Tmp);
  
  p_z1->f_Real = 0.5f*(-p_p->f_Real + t_Tmp.f_Real);
  p_z1->f_Imag = 0.5f*(-p_p->f_Imag + t_Tmp.f_Imag);
  p_z2->f_Real = 0.5f*(-p_p->f_Real - t_Tmp.f_Real);
  p_z2->f_Imag = 0.5f*(-p_p->f_Imag - t_Tmp.f_Imag);
}
