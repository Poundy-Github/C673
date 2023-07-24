/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_complex.h

  DESCRIPTION:               functions related to complex values and their transformation

  AUTHOR:                    Fabian Diewald

  CREATION DATE:             17.10.2012

  VERSION:                   $Revision: 1.10 $

  ---*/ /*---
  CHANGES:                   $Log: cml_complex.h  $
  CHANGES:                   Revision 1.10 2017/11/16 14:24:30CET Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   Updated cml_complex module with coding guidelines.
  CHANGES:                   Revision 1.9 2017/10/13 10:05:20CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the function header comment format
  CHANGES:                   Revision 1.8 2017/09/27 05:59:03CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.7 2015/04/29 13:30:27CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to the coding guidelines
  CHANGES:                     of variables.
  CHANGES:                   - Added comments -  uidr5428 [Apr 29, 2015 1:30:28 PM CEST]
  CHANGES:                   Change Package : 324617:1 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.6 2014/12/04 15:46:56CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - changed input data CML_v_PhaseUnwrapping() from pointer to array as they are accessed this way
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 4, 2014 3:46:57 PM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.5 2014/04/07 10:29:08CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:29:08 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.4 2014/02/04 15:10:16CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:10:16 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2013/10/30 14:32:18CET Heidenreich, Philipp (uidv9899) 
  CHANGES:                   added/moved three functions (MultiplyComplex, DivideComplex and QuadraticEquationComplex)
  CHANGES:                   --- Added comments ---  uidv9899 [Oct 30, 2013 2:32:18 PM CET]
  CHANGES:                   Change Package : 176454:1 http://mks-psad:7002/im/viewissue?selection=176454
  CHANGES:                   Revision 1.2 2013/04/12 13:25:23CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Fix file header
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 12, 2013 1:25:23 PM CEST]
  CHANGES:                   Change Package : 159154:23 http://mks-psad:7002/im/viewissue?selection=159154
  
**************************************************************************** */

/**
@defgroup complex COMPLEX (functions related to complex values and their transformations)
  @ingroup cml
@{ */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_complex.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_COMPLEX_INCLUDED
#define _CML_COMPLEX_INCLUDED


/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_v_cartesian2Polar                                *//*!

  \brief             Transforms a complex number from cartesian to polar representation.
                     
  \description       Transforms a complex number from cartesian to polar representation.
                     The real and imaginary parts are used to calculate the amplitude 
                     and phase.
  \InOutCorrelation   
                     Let the cartesian cordinates be (x,y) and polar cordinates be (r,ph)
                     then,        
                   \f[  r  = \sqrt{(x^2 + y^2)} \\
                        ph = atan(\frac {y}{x})
                   \f]
                     
  \param[in]         cartesian :  complex number cartesian
                                  Optimal Range for cartesian.f_Real is [-F_MAX..F_MAX]
                                  Optimal Range for cartesian.f_Imag is [-F_MAX..F_MAX]
                                  where F_MAX is cube root of max range of float.
  \param[out]        p_polar :  pointer to complex number polar
                     
  \return            void
                     
  \author            Fabian Diewald

  \testmethod
  \traceability   
*****************************************************************************/
void CML_v_cartesian2Polar(const t_Complexf32 cartesian, 
                           t_ComplexPolarf32 * const p_polar);

/*****************************************************************************
  Functionname:    CML_v_polar2Cartesian                                *//*!
  
  \brief             Transforms a complex number from polar to cartesian representation.
                     
  \description       Transforms a complex number from polar to cartesian representation.
                     The amplitude and phase are used to calculate the real and imaginary parts
  \InOutCorrelation     
                     Let the cartesian cordinates be (x,y) and polar cordinates be (r,ph)
                     then,        
                  \f[   x = r \times cos(ph) \\
                        y = r \times sin(ph)       \f]
                     
  \param[in]         polar :  complex number polar
                              Range for polar.f_Amplitude [Full range of float]
                              Range for polar.f_Phase [Full range of float]
  \param[out]        p_cartesian :  complex number cartesian
                     
  \return            void
                     
  \author            Fabian Diewald

  \testmethod
  \traceability   
*****************************************************************************/
void CML_v_polar2Cartesian(const t_ComplexPolarf32 polar, 
                           t_Complexf32 * const p_cartesian);

/*************************************************************************
  Functionname:    CML_v_phaseUnwrapping                            *//*!
  \brief           Does a phase unwrapping for the phases of an array, 
                   can be adapted to array with elevation/monopulse feature 
                   by parameter.

  \description     This function does a phase unwrapping for the phases of 
                   an array, can be adapted to array with elevation/monopulse 
                   feature by parameter. Here it considers the fact that phase
                   is 2pi periodic. It finds the phase which has the mininmum
                   difference to previous relevent phase.
                   @startuml
                   (*)--> Check the channel counter
                   If channel counter < no. of channels
                   --> [Yes] If channel counter < no. of arrays
                   --> [Yes]   Previous_phase = p, phase of array at (channel counter - 1)
                   --> Compare revious and current phases
                   Else
                   --> [No]   Previous_phase = p, phase of array at (channel counter - no. of Subarrays)
                   EndIf
                   --> Compare revious and current phases
                   If p < phase of array at current channel 
                   --> [Yes] Low_Phase = phase of array at current channel
                   --> Compare Low phase and previous phase
                   If (Low_Phase > p)
                   --> [Yes] High_Phase = Low_Phase, Low_Phase = Low_Phase-2pi
                   --> Compare Low phase and previous phase
                   Else
                   --> [No] Compare Difference with phases
                   EndIf
                   Else
                   --> [No] High_Phase = phase of array at current channel
                   --> Compare High phase and previous phase
                   If (High_Phase < p)
                   --> [Yes] Low_Phase = High_Phase, High_Phase = High_Phase+2pi
                   --> Compare High phase and previous phase
                   Else
                   --> [No] Compare Difference with phases
                   EndIf
                   EndIf
                   if ( (High_Phase-p) < (p-Low_Phase) )
                   -->[Yes]phase of array at current channel = High_Phase
                   --> Check the channel counter
                   Else
                   -->[No] phase of array at current channel = Low_Phase
                   --> Check the channel counter
                   EndIf
                   Else
                   -->(*)
                   EndIf
                   @enduml
  
  \param[in, out]  a_values :  complex polar values with phases to be unwrapped 
                            -> complex polar values with unwrapped phases
                               Range for a_values[].f_Amplitude [Full range of float]
                               Range for a_values[].f_Phase [Full range of float]
  \param[in]       u_NofChannels  :  number of the channels
                                     Range can be [Full range of uint32]
  \param[in]       u_NofSubarrays :  number of subarrays, 1u if no elevation 
                                     feature should be considered, so 1u
                                     is the value for default purposes
                                     Range can be [Full range of uint32]

  \return          void
  
  \author          Michael Eisenacher/Fabian Diewald

  \testmethod
  \traceability   
***************************************************************************/
void CML_v_phaseUnwrapping(t_ComplexPolarf32 a_values[],  
                           const uint32 u_NofChannels, 
                           const uint32 u_NofSubarrays);

/*****************************************************************************
  Functionname :    CML_v_multiplyComplex                               *//*! 
  
  \brief            Multiplies two complex numbers
  
  \description      Multiplies two complex numbers under the condition which 
                    checks if the first number has to be multiplied by the 
                    second number as it is or by the conjugate of the second 
                    number.
  \InOutCorrelation     
                  \f[ Let \\  
                      Factor1   = (R_1, I_1)  , 
                      Factor2   = (R_2, I_2)  and \\ 
                      Product   = (R_p, I_p), \f] 
                  
                     If complex conjugate flag is set to TRUE, then
                     real and imaginary parts of the product is calculated as  
                  \f[ R_p =  (R_1 \times R_2) + (I_1 \times I_2) \\
                      I_p =  (I_1 \times R_2) - (R_1 \times I_2)  \f]
                  
                     If complex conjugate flag is set to FALSE, then
                     real and imaginary parts of the product is calculated as         
                  \f[ R_p =  (R_1 \times R_2) - (I_1 \times I_2) \\
                      I_p =  (I_1 \times R_2) + (R_1 \times I_2)    \f]
  
  \param[in]        p_Fac1 :  Factor1 
                              Optimal Range for p_Fac1.f_Real is [-F_MAX..F_MAX]
                              Optimal Range for p_Fac1.f_Imag is [-F_MAX..F_MAX]
                              where F_MAX is square root of half the max range of float.
  \param[in]        p_Fac2 :  Factor2
                              Optimal Range for p_Fac2.f_Real is [-F_MAX..F_MAX]
                              Optimal Range for p_Fac2.f_Imag is [-F_MAX..F_MAX]
                              where F_MAX is square root of half the max range of float.
  \param[in]        b_Conj :  Factor2 complex conjugate
                              This value can be either TRUE or FALSE
  \param[out]       p_Prod :  Resulting product
  
  \return           void
  
  \author           Fabian Diewald

  \testmethod
  \traceability   
*****************************************************************************/
void CML_v_multiplyComplex(const t_Complexf32 *p_Fac1,  
                           const t_Complexf32 *p_Fac2, 
                           const boolean b_Conj, 
                           t_Complexf32 *p_Prod);

/*****************************************************************************
  Functionname:    CML_v_divideComplex                                  *//*!
  
  \brief           complex division
  
  \description     This function divides a complex numerator by a complex 
                   denominator.
  \attention       A division by 0 has to be avoided by user!

  \InOutCorrelation 
                     The real and imaginary parts of the quotient is calculated as         
                  \f[   
                      Numerator   = (R_n, I_n)  , 
                      Denominator = (R_d, I_d)  and \\ 
                      Quotient    = (R_q, I_q), \\ then, \\
                      R_q =  \frac {(R_n \times R_d) + (I_n \times I_d)}{R_d^2 + I_d^2 } \\
                      I_q =  \frac {(I_n \times R_d) - (R_n \times I_d)}{R_d^2 + I_d^2 } \\  
                  \f]
  
  \param[in]       p_Num :  Numerator
                            Optimal Range for p_Num.f_Real is [-F_MAX..F_MAX]
                            Optimal Range for p_Num.f_Imag is [-F_MAX..F_MAX]
                            where F_MAX is square root of half the max range of float.
  \param[in]       p_Denom :  Denominator
                              Optimal Range for p_Denom.f_Real is [-F_MAX..F_MAX]
                              Optimal Range for p_Denom.f_Imag is [-F_MAX..F_MAX]
                              where F_MAX is square root of half the max range of float.
  \param[out]      p_Quot :  Resulting quotient
  
  \return          void
  
  \author          Florian Engels

  \testmethod
  \traceability   
*****************************************************************************/
void CML_v_divideComplex(const t_Complexf32 *p_Num,  
	                     const t_Complexf32 *p_Denom,
                         t_Complexf32 *p_Quot);

/*****************************************************************************
  Functionname:    CML_v_quadraticEquationComplex                       *//*! 
  
  \brief           calculate the two solutions of z*z + p*z + q = 0
                   according to z1 = 0.5*(-p + sqrt(p*p - 4*q))
                            z2 = 0.5*(-p - sqrt(p*p - 4*q))
               
  \description     The function calculates the solution for the quadratic equation
                   z*z + p*z + q = 0. 
                   The two solutions to the quadratic equation is given by,
                   z1 = 0.5*(-p + sqrt(p*p - 4*q))
                   z2 = 0.5*(-p - sqrt(p*p - 4*q))
  \InOutCorrelation
                   Let the solutions of the quadratic equation given by
                   \f[ z^2 + p \times z + q = 0 \f]  are z1 and z2, then,
                   \f[ z_1 = \frac{-p + \sqrt{p^2 - (4 \times q)}}{2} \f] and 
                   \f[ z_2 = \frac{-p + \sqrt{p^2 + (4 \times q)}}{2} \f]
  
  \param[in]   p_p :  Complex polynomial coefficient
                          Optimal Range for p_p.f_Real is [-F_MAX..F_MAX]
                          Optimal Range for p_p.f_Imag is [-F_MAX..F_MAX]
                          where F_MAX is square root of half the max range of float.
  \param[in]   p_q :  Complex polynomial coefficient
                          Optimal Range for p_q.f_Real is [-F_MAX..F_MAX]
                          Optimal Range for p_q.f_Imag is [-F_MAX..F_MAX]
                          where F_MAX is one-eighth the max range of float.
                          Note: The value of (p*p - 4*q) for both real and imaginary part 
                          should be greater than or equal to 0
  \param[out]   p_z1 :  Complex solution 1
  \param[out]   p_z2 :  Complex solution 2
  
  \return          void
  
  \author          Philipp Heidenreich

  \testmethod
  \traceability   
*****************************************************************************/
void CML_v_quadraticEquationComplex(const t_Complexf32 *p_p,  
                                    const t_Complexf32 *p_q,
                                    t_Complexf32 *p_z1,
                                    t_Complexf32 *p_z2);

#endif  /* #ifndef _CML_COMPLEX_INCLUDED */


/** @} end defgroup */
