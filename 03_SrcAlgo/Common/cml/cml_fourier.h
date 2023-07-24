/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_fourier.h

  DESCRIPTION:               functions related to the fourier transform

  AUTHOR:                    Michael Eisenacher

  CREATION DATE:             19.06.2012

  VERSION:                   $Revision: 1.7 $

  ---*/ /*---
  CHANGES:                   $Log: cml_fourier.h  $
  CHANGES:                   Revision 1.7 2017/11/13 06:21:52CET Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   Updated cml_fourier module functions with coding standard naming convention.
  CHANGES:                   Revision 1.6 2017/09/27 05:59:01CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.5 2014/04/07 10:30:17CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   - Added comments -  uidg6516 [Apr 7, 2014 10:30:18 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.4 2014/02/04 15:11:23CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:11:24 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2013/10/30 15:59:29CET Heidenreich, Philipp (uidv9899) 
  CHANGES:                   moved void CML_v_InverseBeamformingARS400Entry to cml_beam_processing
  CHANGES:                   --- Added comments ---  uidv9899 [Oct 30, 2013 3:59:30 PM CET]
  CHANGES:                   Change Package : 176454:1 http://mks-psad:7002/im/viewissue?selection=176454
  CHANGES:                   Revision 1.2 2013/08/28 18:04:43CEST Engels, Florian (engelsf) 
  CHANGES:                   Added CML_v_InverseBeamformingARS400Entry
  CHANGES:                   --- Added comments ---  engelsf [Aug 28, 2013 6:04:44 PM CEST]
  CHANGES:                   Change Package : 192268:1 http://mks-psad:7002/im/viewissue?selection=192268
  CHANGES:                   Revision 1.1 2012/09/14 14:31:08CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup fourier FOURIER (functions related to the fourier transform)
  @ingroup cml
@{ */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_fourier.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_FOURIER_INCLUDED
#define _CML_FOURIER_INCLUDED


/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_v_FFT                                            */ 

///  \brief           This computes an in-place complex-to-complex FFT
///
///  \description     http://paulbourke.net/miscellaneous/dft/index.html
///                   The output equals the output of a direct Fourier transform.
///                   The direct transform requires less memory but more 
///                   computation time.
///                   The FFT calculation happens in three steps. 
///                   (1) The N-point signal in time domain is split into N signals 
///                   each containing a single point. (2) find the spectrum of each 
///                   signal and (3) processing the frequency data to one spectrum.
///                   As the first step the signals are rearranged for an easier processing
///                   using a bit reversal sorting algorithm, where order of the time domain 
///                   samples are rearranged by counting in the sample number binary with the bits
///                   flipped left-for-right. Then the FFT is calculated using the butterfly 
///                   algorithm in the innermost loop wrapped by the loop for each sub-DFT and 
///                   a loop for Log2(N) stages respectively going outwards.
///                   @startuml
///                   (*)--> Bit Reversal Data Sorting 
///                   note left: Rearranging the signals 
///                   --> Loop for Log2(N) stages
///                   If Stage processing done
///                   --> [All stages are done] End of processing 
///                   Else
///                   --> Loop for each sub DFT
///                   If sub DFT processing done
///                   --> [next stage] Loop for Log2(N) stages 
///                   Else
///                   --> Loop for Butterfly algorithm
///                   If Butterfly calculation ends
///                   --> [next sub DFT] Loop for each sub DFT 
///                   Else
///                   --> [next sample] Loop for Butterfly algorithm 
///                   EndIf
///                   EndIf
///                   EndIf
///                   --> End of processing
///                   -->(*)
///                   @enduml
///                   
///  \attention       The output of this function is NOT normalized by 1/N to save
///                   computation time.
///
///  \param[in,out]   a_Elements :        list of input elements, replaced by transformed elements
///                                       Optimal Range for a_Elements[].f_Real is [-F_MAX..F_MAX]
///                                       Optimal Range for a_Elements[].f_Imag is [-F_MAX..F_MAX]
///                                       where F_MAX is one-third of the max range of float.
///  \param[in]       u_LogNofElements :  logarithm of length of af_ListOfElements
///                                       Range of values [0..32]
///  \param[in]       b_Inverse :         true if inverse FFT shall be computed
///                                       This value can be either TRUE or FALSE
///
///  \return          void
///
///  \author          Michael Eisenacher
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
void CML_v_FFT(t_Complexf32 a_Elements[], const uint8 u_LogNofElements, boolean b_Inverse);

/*****************************************************************************
  Functionname:    CML_v_inverseFFT16                                   */ 

///  \brief           Computes the inverse 16 point DFT
///
///  \description     Special time optimized version of CML_v_FFT:
///                   - u_LogNofElements hard coded to 4
///                   - b_Inverse hard coded to 1
///                   - all loops are rolled out
///                   - sqrt function computed offline.
///                    The function swaps the elements based on the same 
///                    index bit reversal logic as in CML_v_FFT. After this 
///                    the butterfly stages are implemented with loop unrolled
///                    for 16 point DFT. The butterfly algorithm for each pair 
///                    of elements will be as follows
///                    \image html CML_v_InverseFFT16.png
///                    
///  \attention       This function does NOT perform the scaling operation upon the
///                   result. The user has to take care of the scaling as is
///                   required.
///
///  \param[in,out]   a_Elements :  list of input elements, replaced by transformed elements
///                                 Optimal Range for a_Elements[].f_Real is [-F_MAX..F_MAX]
///                                 Optimal Range for a_Elements[].f_Imag is [-F_MAX..F_MAX]
///                                 where F_MAX is one-sixth of the max range of float.
///
///  \return          void
///
///  \author          Michael Eisenacher
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
void CML_v_inverseFFT16(t_Complexf32 a_Elements[]);

#endif  /* #ifndef _CML_FOURIER_INCLUDED */


/** @} end defgroup */
