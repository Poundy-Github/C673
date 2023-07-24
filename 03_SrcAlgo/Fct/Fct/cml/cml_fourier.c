/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_fourier.c

  DESCRIPTION:               functions related to the fourier transform

  AUTHOR:                    Michael Eisenacher

  CREATION DATE:             19.06.2012

  VERSION:                   $Revision: 1.20 $

  ---*/ /*---
  CHANGES:                   $Log: cml_fourier.c  $
  CHANGES:                   Revision 1.20 2019/06/21 15:15:10CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   QAF Level3 fixes for MFC431TA19
  CHANGES:                   Revision 1.19 2018/02/26 08:49:33CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.18 2017/11/09 11:36:17CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Replaced FALSE/TRUE by b_FALSE/b_TRUE
  CHANGES:                   Revision 1.17 2016/05/11 06:09:14CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.17 2016/05/11 06:09:14CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.17 2016/05/11 06:09:14CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.16 2015/08/25 06:06:28CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   - Added comments -  uidr5428 [Aug 25, 2015 6:06:29 AM CEST]
  CHANGES:                   Change Package : 360603:1 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.15 2015/06/26 10:26:31CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Added new line at the end of file to remove target
  CHANGES:                     build warning.
  CHANGES:                   --- Added comments ---  uidr5428 [Jun 26, 2015 10:26:32 AM CEST]
  CHANGES:                   Change Package : 351399:1 http://mks-psad:7002/im/viewissue?selection=351399
  CHANGES:                   Revision 1.14 2015/04/29 13:39:03CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to the coding guidelines
  CHANGES:                     of variables
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 1:39:05 PM CEST]
  CHANGES:                   Change Package : 324617:1 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.13 2015/04/28 19:19:20CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Edited the docu header of the function CML_v_InverseFFT16
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 28, 2015 7:19:21 PM CEST]
  CHANGES:                   Change Package : 316974:1 http://mks-psad:7002/im/viewissue?selection=316974
  CHANGES:                   Revision 1.12 2014/12/12 13:34:14CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added review ID to QA-C suppressions
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 12, 2014 1:34:14 PM CET]
  CHANGES:                   Change Package : 266613:12 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.11 2014/12/04 17:13:39CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - suppressed QA-C warning
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 4, 2014 5:13:40 PM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.10 2014/06/16 13:23:39CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - made counters in CML_vFFT() 32 bit to allow FFTs larger than 128 taps
  CHANGES:                   --- Added comments ---  uidg6516 [Jun 16, 2014 1:23:40 PM CEST]
  CHANGES:                   Change Package : 230040:7 http://mks-psad:7002/im/viewissue?selection=230040
  CHANGES:                   Revision 1.9 2014/03/25 11:30:54CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:30:54 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.8 2013/10/30 15:59:27CET Heidenreich, Philipp (uidv9899) 
  CHANGES:                   moved void CML_v_InverseBeamformingARS400Entry to cml_beam_processing
  CHANGES:                   --- Added comments ---  uidv9899 [Oct 30, 2013 3:59:28 PM CET]
  CHANGES:                   Change Package : 176454:1 http://mks-psad:7002/im/viewissue?selection=176454
  CHANGES:                   Revision 1.7 2013/09/12 10:10:05CEST Engels, Florian (engelsf) 
  CHANGES:                   MISRA
  CHANGES:                   --- Added comments ---  engelsf [Sep 12, 2013 10:10:05 AM CEST]
  CHANGES:                   Change Package : 195845:3 http://mks-psad:7002/im/viewissue?selection=195845
  CHANGES:                   Revision 1.6 2013/08/30 15:29:27CEST Engels, Florian (engelsf) 
  CHANGES:                   Corrected signs.
  CHANGES:                   --- Added comments ---  engelsf [Aug 30, 2013 3:29:27 PM CEST]
  CHANGES:                   Change Package : 192268:1 http://mks-psad:7002/im/viewissue?selection=192268
  CHANGES:                   Revision 1.5 2013/08/30 10:10:50CEST Engels, Florian (engelsf) 
  CHANGES:                   Corrected indices CML_v_InverseBeamformingARS400Entry.
  CHANGES:                   --- Added comments ---  engelsf [Aug 30, 2013 10:10:50 AM CEST]
  CHANGES:                   Change Package : 192268:1 http://mks-psad:7002/im/viewissue?selection=192268
  CHANGES:                   Revision 1.4 2013/08/28 18:04:43CEST Engels, Florian (engelsf) 
  CHANGES:                   Added CML_v_InverseBeamformingARS400Entry
  CHANGES:                   --- Added comments ---  engelsf [Aug 28, 2013 6:04:43 PM CEST]
  CHANGES:                   Change Package : 192268:1 http://mks-psad:7002/im/viewissue?selection=192268
  CHANGES:                   Revision 1.3 2013/03/11 16:07:57CET Westhofen, Daniel (uidt2642) 
  CHANGES:                   Replaced False with FALSE
  CHANGES:                   --- Added comments ---  uidt2642 [Mar 11, 2013 4:07:57 PM CET]
  CHANGES:                   Change Package : 162889:17 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                   Revision 1.2 2012/09/20 13:29:45CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:45 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:07CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

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
  Functionname:    CML_v_FFT                                            */ /*!

  @brief           This computes an in-place complex-to-complex FFT

  @description     http://paulbourke.net/miscellaneous/dft/index.html
                   The output equals the output of a direct Fourier transform.
                   The direct transform requires less memory but more 
                   computation time.
                   The output of this function is NOT normalized by 1/N to save
                   computation time.

  @param[in,out]   a_Elements :        list of input elements, replaced by transformed elements
                                       Optimal Range for a_Elements[].f_Real is [-F_MAX..F_MAX]
                                       Optimal Range for a_Elements[].f_Imag is [-F_MAX..F_MAX]
                                       where F_MAX is one-third of the max range of float.
  @param[in]       u_LogNofElements :  logarithm of length of af_ListOfElements
                                       Range of values [0..32]
  @param[in]       b_Inverse :         true if inverse FFT shall be computed
                                       This value can be either TRUE or FALSE

  @return          void

  @author          Michael Eisenacher

*****************************************************************************/
void CML_v_FFT(t_Complexf32 a_Elements[], const uint8 u_LogNofElements, boolean b_Inverse)
{

  /* number of elements */
  uint32 u_NofElements = 1U;

  float32 f_c1 = -1.f; 
  float32 f_c2 = 0.f;

  /* loop counters */
  uint32 u_ElementCounter1, u_ElementCounter2, u_ElementCounter3, u_ElementCounter4, u_ElementCounter5;

  {
    uint32 u_LogCounter;

    for(u_LogCounter = 0U; u_LogCounter < (uint32)u_LogNofElements; u_LogCounter++)
    {
      u_NofElements *= 2U;
    }
  }

  /* Do the bit reversal */
  u_ElementCounter2 = 0U;

  for ( u_ElementCounter1 = 0U; u_ElementCounter1 < (u_NofElements - 1U); u_ElementCounter1++)
  {
    if (u_ElementCounter1 < u_ElementCounter2)
    {
      /* temporary variable for copying */
      t_Complexf32 Copy;

      Copy                           = a_Elements[u_ElementCounter1];
      a_Elements[u_ElementCounter1]  = a_Elements[u_ElementCounter2];
      a_Elements[u_ElementCounter2]  = Copy;
    }

    {
      /* loop counters */
      u_ElementCounter3 = u_NofElements / 2U;

      while (u_ElementCounter3 <= u_ElementCounter2)
      {
        u_ElementCounter2 = u_ElementCounter2 - u_ElementCounter3;
        u_ElementCounter3 >>= 1U;
      }
      u_ElementCounter2 = u_ElementCounter2 + u_ElementCounter3;
    }
  }

  /* Compute the FFT */

  u_ElementCounter4 = 1U;
  for (u_ElementCounter1 = 0U; u_ElementCounter1 < (uint32)u_LogNofElements; u_ElementCounter1++)
  {

    float32 f_u1 = 1.f; 
    float32 f_u2 = 0.f;

    u_ElementCounter5 = u_ElementCounter4;

    u_ElementCounter4 = (uint32) (u_ElementCounter4<<1U);

    for (u_ElementCounter2 = 0U; u_ElementCounter2 < u_ElementCounter5; u_ElementCounter2++)
    {
      for (u_ElementCounter3 = u_ElementCounter2; u_ElementCounter3 < u_NofElements;
        u_ElementCounter3 = (u_ElementCounter3 + u_ElementCounter4) )
      {
        t_Complexf32 *const CurrentElement =
          &(a_Elements[u_ElementCounter3 + u_ElementCounter5]);

        float32 const Internal1 =
          (f_u1 * CurrentElement->f_Real) - (f_u2 * CurrentElement->f_Imag);

        float32 const Internal2 =
          (f_u1 * CurrentElement->f_Imag) + (f_u2 * CurrentElement->f_Real);

        CurrentElement->f_Real = a_Elements[u_ElementCounter3].f_Real - Internal1; 
        CurrentElement->f_Imag = a_Elements[u_ElementCounter3].f_Imag - Internal2;

        a_Elements[u_ElementCounter3].f_Real += Internal1;
        a_Elements[u_ElementCounter3].f_Imag += Internal2;
      }

      {
        /* temporary variable for copying */
        float32 const f_Copy = (f_u1 * f_c1) - (f_u2 * f_c2);
        f_u2 = (f_u1 * f_c2) + (f_u2 * f_c1);
        f_u1 = f_Copy;
      }
    }

    f_c2 = CML_f_Sqrt((1.f - f_c1) / 2.f);

    if (b_Inverse == b_FALSE)
    {
      f_c2 = -f_c2;
    }

    f_c1 = CML_f_Sqrt((1.f + f_c1) / 2.f);
  }
}

/*****************************************************************************
  Functionname:    CML_v_inverseFFT16                                   */ /*!

  @brief           Computes the inverse 16 point DFT

  @description     Special time optimized version of CML_v_FFT:
                   - u_LogNofElements hard coded to 4
                   - b_Inverse hard coded to 1
                   - all loops are rolled out
                   - sqrt function computed offline
                   This function does NOT perform the scaling operation upon the
                   result. The user has to take care of the scaling as is
                   required.

  @param[in,out]   a_Elements :  list of input elements, replaced by transformed elements
                                 Optimal Range for a_Elements[].f_Real is [-F_MAX..F_MAX]
                                 Optimal Range for a_Elements[].f_Imag is [-F_MAX..F_MAX]
                                 where F_MAX is one-sixth of the max range of float.

  @return          void

  @author          Michael Eisenacher

*****************************************************************************/
/* PRQA S 7012 INVERSEFFT16 */
/* Deactivate QAC warning 7012, Reviewer: S.Schwarzkopf; Date: 04.12.2014; 
   Reason: loops had to be unrolled for performance issues.
   Review-ID: 3942463 */
void CML_v_inverseFFT16(t_Complexf32 a_Elements[]) {

  static float32 const f_k2 = 0.382683432365090f;
  static float32 const f_k1 = 0.707106781186548f;
  static float32 const f_k3 = 0.923879532511287f;

  float32 f_Internal1;
  float32 f_Internal2;
  t_Complexf32 Copy;

  Copy           = a_Elements[1];
  a_Elements[1]  = a_Elements[8];
  a_Elements[8]  = Copy;

  Copy           = a_Elements[2];
  a_Elements[2]  = a_Elements[4];
  a_Elements[4]  = Copy;

  Copy           = a_Elements[3];
  a_Elements[3]  = a_Elements[12];
  a_Elements[12] = Copy;

  Copy           = a_Elements[5];
  a_Elements[5]  = a_Elements[10];
  a_Elements[10] = Copy;

  Copy           = a_Elements[7];
  a_Elements[7]  = a_Elements[14];
  a_Elements[14] = Copy;

  Copy            = a_Elements[11];
  a_Elements[11]  = a_Elements[13];
  a_Elements[13]  = Copy;

  f_Internal1 = a_Elements[1].f_Real;
  f_Internal2 = a_Elements[1].f_Imag;

  a_Elements[1].f_Real = a_Elements[0].f_Real - f_Internal1; 
  a_Elements[1].f_Imag = a_Elements[0].f_Imag - f_Internal2;

  a_Elements[0].f_Real += f_Internal1;
  a_Elements[0].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[3].f_Real;
  f_Internal2 = a_Elements[3].f_Imag;

  a_Elements[3].f_Real = a_Elements[2].f_Real - f_Internal1; 
  a_Elements[3].f_Imag = a_Elements[2].f_Imag - f_Internal2;

  a_Elements[2].f_Real += f_Internal1;
  a_Elements[2].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[5].f_Real;
  f_Internal2 = a_Elements[5].f_Imag;

  a_Elements[5].f_Real = a_Elements[4].f_Real - f_Internal1; 
  a_Elements[5].f_Imag = a_Elements[4].f_Imag - f_Internal2;

  a_Elements[4].f_Real += f_Internal1;
  a_Elements[4].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[7].f_Real;
  f_Internal2 = a_Elements[7].f_Imag;

  a_Elements[7].f_Real = a_Elements[6].f_Real - f_Internal1; 
  a_Elements[7].f_Imag = a_Elements[6].f_Imag - f_Internal2;

  a_Elements[6].f_Real += f_Internal1;
  a_Elements[6].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[9].f_Real;
  f_Internal2 = a_Elements[9].f_Imag;

  a_Elements[9].f_Real = a_Elements[8].f_Real - f_Internal1; 
  a_Elements[9].f_Imag = a_Elements[8].f_Imag - f_Internal2;

  a_Elements[8].f_Real += f_Internal1;
  a_Elements[8].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[11].f_Real;
  f_Internal2 = a_Elements[11].f_Imag;

  a_Elements[11].f_Real = a_Elements[10].f_Real - f_Internal1; 
  a_Elements[11].f_Imag = a_Elements[10].f_Imag - f_Internal2;

  a_Elements[10].f_Real += f_Internal1;
  a_Elements[10].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[13].f_Real;
  f_Internal2 = a_Elements[13].f_Imag;

  a_Elements[13].f_Real = a_Elements[12].f_Real - f_Internal1; 
  a_Elements[13].f_Imag = a_Elements[12].f_Imag - f_Internal2;

  a_Elements[12].f_Real += f_Internal1;
  a_Elements[12].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[15].f_Real;
  f_Internal2 = a_Elements[15].f_Imag;

  a_Elements[15].f_Real = a_Elements[14].f_Real - f_Internal1; 
  a_Elements[15].f_Imag = a_Elements[14].f_Imag - f_Internal2;

  a_Elements[14].f_Real += f_Internal1;
  a_Elements[14].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[2].f_Real;
  f_Internal2 = a_Elements[2].f_Imag;

  a_Elements[2].f_Real = a_Elements[0].f_Real - f_Internal1; 
  a_Elements[2].f_Imag = a_Elements[0].f_Imag - f_Internal2;

  a_Elements[0].f_Real += f_Internal1;
  a_Elements[0].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[6].f_Real;
  f_Internal2 = a_Elements[6].f_Imag;

  a_Elements[6].f_Real = a_Elements[4].f_Real - f_Internal1; 
  a_Elements[6].f_Imag = a_Elements[4].f_Imag - f_Internal2;

  a_Elements[4].f_Real += f_Internal1;
  a_Elements[4].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[10].f_Real;
  f_Internal2 = a_Elements[10].f_Imag;

  a_Elements[10].f_Real = a_Elements[8].f_Real - f_Internal1; 
  a_Elements[10].f_Imag = a_Elements[8].f_Imag - f_Internal2;

  a_Elements[8].f_Real += f_Internal1;
  a_Elements[8].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[14].f_Real;
  f_Internal2 = a_Elements[14].f_Imag;

  a_Elements[14].f_Real = a_Elements[12].f_Real - f_Internal1; 
  a_Elements[14].f_Imag = a_Elements[12].f_Imag - f_Internal2;

  a_Elements[12].f_Real += f_Internal1;
  a_Elements[12].f_Imag += f_Internal2;

  f_Internal1 = -a_Elements[3].f_Imag;
  f_Internal2 = a_Elements[3].f_Real;

  a_Elements[3].f_Real = a_Elements[1].f_Real - f_Internal1; 
  a_Elements[3].f_Imag = a_Elements[1].f_Imag - f_Internal2;

  a_Elements[1].f_Real += f_Internal1;
  a_Elements[1].f_Imag += f_Internal2;

  f_Internal1 = -a_Elements[7].f_Imag;
  f_Internal2 = a_Elements[7].f_Real;

  a_Elements[7].f_Real = a_Elements[5].f_Real - f_Internal1; 
  a_Elements[7].f_Imag = a_Elements[5].f_Imag - f_Internal2;

  a_Elements[5].f_Real += f_Internal1;
  a_Elements[5].f_Imag += f_Internal2;

  f_Internal1 = -a_Elements[11].f_Imag;
  f_Internal2 = a_Elements[11].f_Real;

  a_Elements[11].f_Real = a_Elements[9].f_Real - f_Internal1; 
  a_Elements[11].f_Imag = a_Elements[9].f_Imag - f_Internal2;

  a_Elements[9].f_Real += f_Internal1;
  a_Elements[9].f_Imag += f_Internal2;

  f_Internal1 = -a_Elements[15].f_Imag;
  f_Internal2 = a_Elements[15].f_Real;

  a_Elements[15].f_Real = a_Elements[13].f_Real - f_Internal1; 
  a_Elements[15].f_Imag = a_Elements[13].f_Imag - f_Internal2;

  a_Elements[13].f_Real += f_Internal1;
  a_Elements[13].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[4].f_Real;
  f_Internal2 = a_Elements[4].f_Imag;

  a_Elements[4].f_Real = a_Elements[0].f_Real - f_Internal1; 
  a_Elements[4].f_Imag = a_Elements[0].f_Imag - f_Internal2;

  a_Elements[0].f_Real += f_Internal1;
  a_Elements[0].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[12].f_Real;
  f_Internal2 = a_Elements[12].f_Imag;

  a_Elements[12].f_Real = a_Elements[8].f_Real - f_Internal1; 
  a_Elements[12].f_Imag = a_Elements[8].f_Imag - f_Internal2;

  a_Elements[8].f_Real += f_Internal1;
  a_Elements[8].f_Imag += f_Internal2;

  f_Internal1 = f_k1 * (a_Elements[5].f_Real - a_Elements[5].f_Imag);
  f_Internal2 = f_k1 * (a_Elements[5].f_Imag + a_Elements[5].f_Real);

  a_Elements[5].f_Real = a_Elements[1].f_Real - f_Internal1; 
  a_Elements[5].f_Imag = a_Elements[1].f_Imag - f_Internal2;

  a_Elements[1].f_Real += f_Internal1;
  a_Elements[1].f_Imag += f_Internal2;

  f_Internal1 = f_k1 * (a_Elements[13].f_Real - a_Elements[13].f_Imag);
  f_Internal2 = f_k1 * (a_Elements[13].f_Imag + a_Elements[13].f_Real);

  a_Elements[13].f_Real = a_Elements[9].f_Real - f_Internal1; 
  a_Elements[13].f_Imag = a_Elements[9].f_Imag - f_Internal2;

  a_Elements[9].f_Real += f_Internal1;
  a_Elements[9].f_Imag += f_Internal2;

  f_Internal1 = -a_Elements[6].f_Imag;
  f_Internal2 = a_Elements[6].f_Real;

  a_Elements[6].f_Real = a_Elements[2].f_Real - f_Internal1; 
  a_Elements[6].f_Imag = a_Elements[2].f_Imag - f_Internal2;

  a_Elements[2].f_Real += f_Internal1;
  a_Elements[2].f_Imag += f_Internal2;

  f_Internal1 =-a_Elements[14].f_Imag;
  f_Internal2 =a_Elements[14].f_Real;

  a_Elements[14].f_Real = a_Elements[10].f_Real - f_Internal1; 
  a_Elements[14].f_Imag = a_Elements[10].f_Imag - f_Internal2;

  a_Elements[10].f_Real += f_Internal1;
  a_Elements[10].f_Imag += f_Internal2;

  f_Internal1 = -f_k1 * (a_Elements[7].f_Real + a_Elements[7].f_Imag);
  f_Internal2 = f_k1 * ( a_Elements[7].f_Real - a_Elements[7].f_Imag);

  a_Elements[7].f_Real = a_Elements[3].f_Real - f_Internal1; 
  a_Elements[7].f_Imag = a_Elements[3].f_Imag - f_Internal2;

  a_Elements[3].f_Real += f_Internal1;
  a_Elements[3].f_Imag += f_Internal2;

  f_Internal1 = -f_k1 * (a_Elements[15].f_Real + a_Elements[15].f_Imag);
  f_Internal2 = f_k1 * ( a_Elements[15].f_Real - a_Elements[15].f_Imag);

  a_Elements[15].f_Real = a_Elements[11].f_Real - f_Internal1; 
  a_Elements[15].f_Imag = a_Elements[11].f_Imag - f_Internal2;

  a_Elements[11].f_Real += f_Internal1;
  a_Elements[11].f_Imag += f_Internal2;

  f_Internal1 = a_Elements[8].f_Real;
  f_Internal2 = a_Elements[8].f_Imag;

  a_Elements[8].f_Real = a_Elements[0].f_Real - f_Internal1; 
  a_Elements[8].f_Imag = a_Elements[0].f_Imag - f_Internal2;

  a_Elements[0].f_Real += f_Internal1;
  a_Elements[0].f_Imag += f_Internal2;

  f_Internal1 = (f_k3 * a_Elements[9].f_Real) - (f_k2 * a_Elements[9].f_Imag);
  f_Internal2 = (f_k3 * a_Elements[9].f_Imag) + (f_k2 * a_Elements[9].f_Real);

  a_Elements[9].f_Real = a_Elements[1].f_Real - f_Internal1; 
  a_Elements[9].f_Imag = a_Elements[1].f_Imag - f_Internal2;

  a_Elements[1].f_Real += f_Internal1;
  a_Elements[1].f_Imag += f_Internal2;

  f_Internal1 = f_k1 * (a_Elements[10].f_Real - a_Elements[10].f_Imag);
  f_Internal2 = f_k1 * (a_Elements[10].f_Imag + a_Elements[10].f_Real);

  a_Elements[10].f_Real = a_Elements[2].f_Real - f_Internal1; 
  a_Elements[10].f_Imag = a_Elements[2].f_Imag - f_Internal2;

  a_Elements[2].f_Real += f_Internal1;
  a_Elements[2].f_Imag += f_Internal2;

  f_Internal1 = (f_k2 * a_Elements[11].f_Real) - (f_k3 * a_Elements[11].f_Imag);
  f_Internal2 = (f_k2 * a_Elements[11].f_Imag) + (f_k3 * a_Elements[11].f_Real);

  a_Elements[11].f_Real = a_Elements[3].f_Real - f_Internal1; 
  a_Elements[11].f_Imag = a_Elements[3].f_Imag - f_Internal2;

  a_Elements[3].f_Real += f_Internal1;
  a_Elements[3].f_Imag += f_Internal2;

  f_Internal1 = -a_Elements[12].f_Imag;
  f_Internal2 = a_Elements[12].f_Real;

  a_Elements[12].f_Real = a_Elements[4].f_Real - f_Internal1; 
  a_Elements[12].f_Imag = a_Elements[4].f_Imag - f_Internal2;

  a_Elements[4].f_Real += f_Internal1;
  a_Elements[4].f_Imag += f_Internal2;

  f_Internal1 = (-f_k2 * a_Elements[13].f_Real) - (f_k3 * a_Elements[13].f_Imag);
  f_Internal2 = (-f_k2 * a_Elements[13].f_Imag) + (f_k3 * a_Elements[13].f_Real);

  a_Elements[13].f_Real = a_Elements[5].f_Real - f_Internal1; 
  a_Elements[13].f_Imag = a_Elements[5].f_Imag - f_Internal2;

  a_Elements[5].f_Real += f_Internal1;
  a_Elements[5].f_Imag += f_Internal2;

  f_Internal1 = -f_k1 * (a_Elements[14].f_Real + a_Elements[14].f_Imag);
  f_Internal2 =  f_k1 * (a_Elements[14].f_Real - a_Elements[14].f_Imag);

  a_Elements[14].f_Real = a_Elements[6].f_Real - f_Internal1; 
  a_Elements[14].f_Imag = a_Elements[6].f_Imag - f_Internal2;

  a_Elements[6].f_Real += f_Internal1;
  a_Elements[6].f_Imag += f_Internal2;

  f_Internal1 = (-f_k3 * a_Elements[15].f_Real) - (f_k2 * a_Elements[15].f_Imag);
  f_Internal2 = (-f_k3 * a_Elements[15].f_Imag) + (f_k2 * a_Elements[15].f_Real);

  a_Elements[15].f_Real = a_Elements[7].f_Real - f_Internal1; 
  a_Elements[15].f_Imag = a_Elements[7].f_Imag - f_Internal2;

  a_Elements[7].f_Real += f_Internal1;
  a_Elements[7].f_Imag += f_Internal2;
}
/* PRQA L:INVERSEFFT16 */

