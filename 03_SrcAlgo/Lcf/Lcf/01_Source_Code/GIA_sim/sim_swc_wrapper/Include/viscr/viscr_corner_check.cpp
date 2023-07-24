/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_corner_check.cpp 

  DESCRIPTION:    Check if it is a corner or not

  AUTHOR:         L. GARCIA

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_corner_check.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:24CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:04CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.15 2014/02/13 20:47:30CET Ruland, Thomas (uidw0251) 
  CHANGES:        Adapted thresholds to trigger optimization
  CHANGES:        - Added comments -  uidw0251 [Feb 13, 2014 8:47:31 PM CET]
  CHANGES:        Change Package : 210743:1 http://mks-psad:7002/im/viewissue?selection=210743
  CHANGES:        Revision 1.14 2012/07/13 11:02:57CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add coverage tag for the whole pixel checks
  CHANGES:        --- Added comments ---  uidv2823 [Jul 13, 2012 11:02:57 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.13 2012/07/05 13:40:42CEST Behrens, Alexander (uidv2823) 
  CHANGES:        add code coverage tags
  CHANGES:        --- Added comments ---  uidv2823 [Jul 5, 2012 1:40:42 PM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.12 2012/06/25 09:35:52CEST Visscher-EXT, Eric (uidk7517) 
  CHANGES:        Added code review comments
  CHANGES:        --- Added comments ---  uidk7517 [Jun 25, 2012 9:35:53 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.11 2012/03/09 15:15:19CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Mar 9, 2012 3:15:19 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.10 2012/02/28 15:47:41CET Garcia, Lucien (uid26778) 
  CHANGES:        Remove Lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Feb 28, 2012 3:47:41 PM CET]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.9 2011/10/04 09:03:10CEST Spruck, Jochen (spruckj) 
  CHANGES:        Remove misra issues
  CHANGES:        --- Added comments ---  spruckj [Oct 4, 2011 9:03:11 AM CEST]
  CHANGES:        Change Package : 79035:2 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.8 2011/06/17 13:30:17CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Improve fast corner checker (no more loop but static threshold instead)
  CHANGES:        --- Added comments ---  uid26778 [Jun 17, 2011 1:30:18 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298


**************************************************************************** */


#include <viscr_corner_check.hpp>
#include "sac_profile.h"
#include <viscr_defs.h>




#if (VISCR_CORNER_CHECK == 0)
/// Offset from central pixel to the outer pixels
#define CLAW_STEP 3
  /// Return true if the pixel at the given position has a high enough contrast
  static viscr_bool
  get_and_check(
      viscr_pixel gv_ctr,
      const viscr_image & img,
      viscr_coord u,
      viscr_coord v,
      viscr_pixel min_contrast)
  {
    viscr_pixel gv=viscr_image_getPixel( img, u, v);

    if (std::abs(gv-gv_ctr)>min_contrast)
      return viscr_true;
    return viscr_false;
  }


  static viscr_bool
  viscr_mincorner_check(
      const viscr_image & img,
      viscr_coord u,
      viscr_coord v,
      viscr_pixel min_contrast)
  {
    if( u>=CLAW_STEP && u+CLAW_STEP<img.size.u &&
        v>=CLAW_STEP && v+CLAW_STEP<img.size.v)
    {
      // Get the central pixel
      viscr_pixel gv_00 = viscr_image_getPixel( img, u, v);

      // If any pixel has a good contrast, the window is OK
      for( viscr_int vv=-1; vv<=1; ++vv)
      {
        for( viscr_int uu=-1; uu<=1; ++uu)
        {
          if( uu!=0 || vv!=0)
          {
            if( get_and_check( gv_00, img, u+uu*CLAW_STEP, v+vv*CLAW_STEP, min_contrast))
              return viscr_true;
          }
        }
      }
    }
    return viscr_false;
  }
#endif

#if (VISCR_CORNER_CHECK == 1)

  static void make_offsets(viscr_int pixel[], const viscr_int row_stride)
  {
          // ~CodeReview ~ID:49785a164e6d678977eb4d9226591adc ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Substitute magic numbers by meaningful defines
          pixel[0] = (row_stride * 3);
          pixel[1] = 1 + (row_stride * 3);
          pixel[2] = 2 + (row_stride * 2);
          pixel[3] = 3 + (row_stride * 1);
          pixel[4] = 3;
          pixel[5] = 3 + (row_stride * -1);
          pixel[6] = 2 + (row_stride * -2);
          pixel[7] = 1 + (row_stride * -3);
          pixel[8] = (row_stride * -3);
          pixel[9] = -1 + (row_stride * -3);
          pixel[10] = -2 + (row_stride * -2);
          pixel[11] = -3 + (row_stride * -1);
          pixel[12] = -3;
          pixel[13] = -3 + (row_stride * 1);
          pixel[14] = -2 + (row_stride * 2);
          pixel[15] = -1 + (row_stride * 3);
  }


  /* <ln_offset:+1to+2056 COVERAGE reviewer name: Alexander Behrens date: 13.07.2012 reason: Perform corner finding. Check each of the 16 pixel. */
  static viscr_pixel fast12_corner_score(const viscr_pixel p[] , const viscr_int pixel[], const viscr_pixel bstart)
  {    
	  viscr_pixel result = 0U;
      viscr_pixel b = bstart;
      // ~CodeReview ~ID:662b999a5ec636567fd9046d6a2854e9 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:substitute magic numbers by meaningful defines
      for (viscr_int i =0; i<16; i++)
      {

          // ~CodeReview ~ID:2f88d453ab452799c4002c695fb697a3 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:substitute magic numbers by meaningful defines
          if ((p[pixel[i]] == 0U) || (p[pixel[i]] == 4095U)) 
            {{goto is_not_a_corner;}}
      }

      /*Compute the score using binary search*/
      {
        viscr_pixel cb = *p + b;
        viscr_pixel c_b= *p - b;


          if( p[pixel[0]] > cb){
           if( p[pixel[1]] > cb){
            if( p[pixel[2]] > cb){
             if( p[pixel[3]] > cb){
              if( p[pixel[4]] > cb){
               if( p[pixel[5]] > cb){
                if( p[pixel[6]] > cb){
                 if( p[pixel[7]] > cb){
                  if( p[pixel[8]] > cb){
                   if( p[pixel[9]] > cb){
                    if( p[pixel[10]] > cb){
                     if( p[pixel[11]] > cb){
                      // ~CodeReview ~ID:cb08aee06e1551e953c69ba3d43cb9cb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_a_corner;}
                     }else
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:5f67fcf406766b8d71d0224bff4020fb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:559a7b2e1a83a3bf3fe5363afe1118d3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                    }else
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:8dba5e2e206865eb2cd35e4c2671cc62 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:e8f7fb21bef941ca48c08d1dc2499b96 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:677181490ab8102a6ad20e37b69a1647 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                   }else
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:c028ced37cf2c92e75c99041c8191c04 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:6c6fd061a4b213d91b4d1e76c3cd9837 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:194aaa58a3dcb5a5734149ab10352ff9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:eeb668af6095be3bb58acc6d241ccfb1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                  }else
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:0f3bec3e0e55709a6788a35da654b35f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:6d5fc9d0fe46737cb8a7b94541e8f53d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:87474b6f47aa3a446ce1f1c9124ec2a4 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:8e37ad67837c97412143cbc490f453b3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:45f6a9b4d10aeca16108a1cbab338d6a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                 }else
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:0b26579f7086d1cd1117c980f8ac710e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:02851a8820747caf5315e57b06361461 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:50ffd2ee6d44d547a69e3db28fed7812 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:8195f716ef13dcfb9263296a1978bd7a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:5b2766111029cc89e30d5a6f101a5bf1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:83beba880c32c113a299c6c64cf39807 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                }else
                 if( p[pixel[10]] > cb){
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:a9625e6320778ebc2f468d7195feb5a9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:7cd5f7dd7ad61a12f8422b29f9e8da71 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:0cb765b8190e6f93426b73bb9fea9f72 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:ff970c3016f3f21b2849363bf5510962 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:1bf349624f8b70898a35e0a56c6dbd59 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:a902b8cab1205477fea522c8d70e95e5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:0aa2b6960cd418aaf51416002d7ad330 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
               }else
                if( p[pixel[9]] > cb){
                 if( p[pixel[10]] > cb){
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:0694baebf0b04c0790148a4d38f53abb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:8bc0bef21bfb7d3eb613c8a7f5c70e88 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:f83b4f3a60f13f7d9a1276a9a1683c0b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:2b2a1bd812b85620ce95a46339c2d2dd ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:133b29700292dde75d08f945bad4c41f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:6f5764fd2847a3384b5d72c8009348e4 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:bf403a3479b55ddf861330aa178db17b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:019644e7201487657868964848bf6935 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
              }else if( p[pixel[4]] < c_b){
               if( p[pixel[8]] > cb){
                if( p[pixel[9]] > cb){
                 if( p[pixel[10]] > cb){
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:17e1318724883affa89e7ade7761e48d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:0a96a53d5a7d375dc6b6290359ba5d5c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:fc693fb83a4f44654b44b0b0e5dafb65 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:24dc9c7dc66b1a5ec60bbd1930d10884 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:5b3458b885bd4eabc8977c8c2383748f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:f902146e88beafeb3474866ff9f16ab2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:c9fc9635ef60b2f74e8a9739dba4a8fb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:48e980ea18519c0cd6156e926284c404 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else if( p[pixel[8]] < c_b){
                if( p[pixel[5]] < c_b){
                 if( p[pixel[6]] < c_b){
                  if( p[pixel[7]] < c_b){
                   if( p[pixel[9]] < c_b){
                    if( p[pixel[10]] < c_b){
                     if( p[pixel[11]] < c_b){
                      if( p[pixel[12]] < c_b){
                       if( p[pixel[13]] < c_b){
                        if( p[pixel[14]] < c_b){
                         if( p[pixel[15]] < c_b){
                          // ~CodeReview ~ID:84f7ac817f4bcaaa8cb12fca18e7cf20 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:eefab854db1c71c19af1deb1f9e9c946 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:3be5c95ea869913a5c04ca2526eaf5a3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:54c689c44efb5cd56c7e949dac6b31e4 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:4f6373583c938d367686c4bd908251b2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:df485f569e9579df9c3e7bfdab25bf97 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:5c60776a88bc11c3291f7dc7fb4b2c3d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:0cb5366b2ebb65ab49ed8139d7e55d93 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:7d73df3529dab5924728c7ff2df24aa5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:296faa0502ebec7567a28850819a5701 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:a421758f30549d85483843a6ad771ef7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:b3947dd1f30d918bed283bed77a9f7be ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               if( p[pixel[8]] > cb){
                if( p[pixel[9]] > cb){
                 if( p[pixel[10]] > cb){
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:3ca5fa9e89d47d49f82a32380f3acffe ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:1aedd3a6df43ee2972f61cf66b7fa1bc ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:13a20a0a509b58689a496a04a94a9dc1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:11d6a3972f688b17a617b68d869cd837 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:0a396479277e4e4a45b1a17f1870aa57 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:053e340a7e5a45f0b4fb7454dadf913a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:958da52bc7b51419249c68048c63bac6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:7f030599fb640428df014ebb1435b5c8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:851d4d2fba4a7861f86a6824172d9815 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
             }else if( p[pixel[3]] < c_b){
              if( p[pixel[15]] > cb){
               if( p[pixel[7]] > cb){
                if( p[pixel[8]] > cb){
                 if( p[pixel[9]] > cb){
                  if( p[pixel[10]] > cb){
                   if( p[pixel[11]] > cb){
                    if( p[pixel[12]] > cb){
                     if( p[pixel[13]] > cb){
                      if( p[pixel[14]] > cb){
                       // ~CodeReview ~ID:bde78b5e64fda3a25a016290f9886d93 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:b3043bf06a30352d5787bff7f1ed4dcf ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:982a395447e741a80359c076929eae0c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:d069d18655fdcce432b08f784361ad9a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:55853c725569fe6777c59d538d8d5144 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:aee21e7c5a97d268657c81d78fb10237 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:d6c0c0332ec4500d7dd99293df2e4808 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:57b1bb306c79b2611780df1e5c6bfe7f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else if( p[pixel[7]] < c_b){
                if( p[pixel[4]] < c_b){
                 if( p[pixel[5]] < c_b){
                  if( p[pixel[6]] < c_b){
                   if( p[pixel[8]] < c_b){
                    if( p[pixel[9]] < c_b){
                     if( p[pixel[10]] < c_b){
                      if( p[pixel[11]] < c_b){
                       if( p[pixel[12]] < c_b){
                        if( p[pixel[13]] < c_b){
                         if( p[pixel[14]] < c_b){
                          // ~CodeReview ~ID:e1f228f51cc5ab746cc97a422142b869 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:dbe1f8f095d8d873d33f9f8793ba1a73 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:7a7e2146e23964613331d03040f890d3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:c77390067a87c54c3aba12ddeb3bcca4 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:177431012f402cf6245653f177ad190f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:8027ba4cd5bb44973bc1c77d835f5562 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:37fc0c6682f845d3dcedcd05ab9ab743 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:e740c7b47493b3452aa919904cdee79e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:64686d015b0db7ce5b222274d6621ae5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:e414c8b21e1a37696a9780fa3bd684f6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:19ac5d895f19660d530d3171f8b0ffcb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:0e8b42c6499627b6fce0f7df77c95405 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               if( p[pixel[4]] < c_b){
                if( p[pixel[5]] < c_b){
                 if( p[pixel[6]] < c_b){
                  if( p[pixel[7]] < c_b){
                   if( p[pixel[8]] < c_b){
                    if( p[pixel[9]] < c_b){
                     if( p[pixel[10]] < c_b){
                      if( p[pixel[11]] < c_b){
                       if( p[pixel[12]] < c_b){
                        if( p[pixel[13]] < c_b){
                         if( p[pixel[14]] < c_b){
                          // ~CodeReview ~ID:67cda477cc2263e37fbce391527f1fc0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:c83077666f5b76147f92354de12d1331 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:1d41dffa882c81c91de7cd525e10570c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:7ea5e3192fc0ef5363fc57cf340d5450 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:cc36aca15830aea62cd0c659b0c16bfd ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:1092d9555d4b65f29fb366a7e52b7c43 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:e2edd7ac5291e998d0f5d761168ba1f3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:f3af420e69a88ee225c2e77ba06638e1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:f748639345fe0f9fa441b091222da52a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:7add8ca0bb4011b8ff91c22d92a9c5ac ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:567335e4b61368ff69354e518ddbb3ff ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:5fdf109417a67c852f675fe7a2448f65 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
             }else
              if( p[pixel[7]] > cb){
               if( p[pixel[8]] > cb){
                if( p[pixel[9]] > cb){
                 if( p[pixel[10]] > cb){
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:ed767ae7404e37f31fdae5e1f052c32f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:3c9d3c50c50c3f87264d956f9be3b4e3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:dfd14de52e05462f1733fa48bd1b5802 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:52684c4925b5d1fa114fc9aadedf3e86 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:4407ce8f68d2fae6d9a245e79c896d74 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:28c2ff4461dac006f59f84af6cf2928c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:6f051493da21e21f0d7c075d6eda78c1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:bba35044e26441348bd448787c188a79 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:d14d68a0b9cf076a5fdd6bc33f590185 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else if( p[pixel[7]] < c_b){
               if( p[pixel[4]] < c_b){
                if( p[pixel[5]] < c_b){
                 if( p[pixel[6]] < c_b){
                  if( p[pixel[8]] < c_b){
                   if( p[pixel[9]] < c_b){
                    if( p[pixel[10]] < c_b){
                     if( p[pixel[11]] < c_b){
                      if( p[pixel[12]] < c_b){
                       if( p[pixel[13]] < c_b){
                        if( p[pixel[14]] < c_b){
                         if( p[pixel[15]] < c_b){
                          // ~CodeReview ~ID:a9e84acd01f127d1e49cd88feaba8823 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:2b1313c492606d214bc4f57c53291d9a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:13db859e611be648ce5cd6b2aa313874 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:3a8d6bd2f40cbfea9fbd9e607586daa6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:c70ee1c62fe8563cf5c9e53c0be9e370 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:789d7fd4dfb0fdcb4cc57d9accbcf0e4 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:a17c28e2d7a371a696d1ea78e712ab55 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:1b3f0deac6770a1088357f1f56815b7b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:f7193edbaae3af834297acdd92b70ecb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:3220a27d48a8922043d09f66ec102cd4 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:ad669e33b89ff718da2b8fac2db72be2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:e26257c6ddaedd8ad80933f993cf05c6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:34779f9cee38012acb461b1430b8df61 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
            }else if( p[pixel[2]] < c_b){
             if( p[pixel[6]] > cb){
              if( p[pixel[7]] > cb){
               if( p[pixel[8]] > cb){
                if( p[pixel[9]] > cb){
                 if( p[pixel[10]] > cb){
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:ea25020b674aa14512341b3228340758 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[3]] > cb){
                        if( p[pixel[4]] > cb){
                         if( p[pixel[5]] > cb){
                          // ~CodeReview ~ID:f21a3ae4b5f1235fdc826e5e67576018 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:ccc4c32750d096871d4ae8a2cce41a92 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:cb223de67261292ee8f653f96cc4494f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:a6aeca07749e474898390bf411afdf91 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:1daa6d76844e19ba3e3c2adc0deb73b9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:9319400c7aa4678ecab1972381fd13f9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:ff82c8c55c85db1f12e2ab6e6d6c16a9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:24ed2bdb2a0f2b81b6d82532292c6cad ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:3a7de6c3d3267103d00006e32671e644 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:3a2283e1a50c909c2a4456c7b8a9656e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:e9bf2823ac114db4d09b006d746de2a8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:9318bbaf75cc8cea97acbad6e39ba4ef ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else if( p[pixel[6]] < c_b){
              if( p[pixel[4]] < c_b){
               if( p[pixel[5]] < c_b){
                if( p[pixel[7]] < c_b){
                 if( p[pixel[8]] < c_b){
                  if( p[pixel[9]] < c_b){
                   if( p[pixel[10]] < c_b){
                    if( p[pixel[11]] < c_b){
                     if( p[pixel[12]] < c_b){
                      if( p[pixel[13]] < c_b){
                       if( p[pixel[3]] < c_b){
                        // ~CodeReview ~ID:a4837de5556a5e2c4a01af2f339ffcd9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_a_corner;}
                       }else
                        if( p[pixel[14]] < c_b){
                         if( p[pixel[15]] < c_b){
                          // ~CodeReview ~ID:531425d00df7eb2c39a706447b4b3e84 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:8ffb94e5729d7685279178ff0b261f7c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:cff319ffa70678bfd74026cfacad5e0b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:a9108ee7b14d06a6b2d16859ac9fc4dc ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:4bc6a055cb9d76d31b76dd58adfbee21 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:061efc9699844d10a88caa0d7c1a10c7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:f288585d7ceade979904274facce235c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:4f7612412e63cd6fd721778f26ea62ff ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:5140b8237fe92c35ede9d4fea8df8c9e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:f23aeb1af06d82cf41fa81ff443294c7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:c5c091a5e9d4fb61ca8760513ad8fd94 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:91b0b3e8e1b58ad600654fc954e962d9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:7d6947bf6bd2403b778f0ae1a5a852f8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else
             if( p[pixel[6]] > cb){
              if( p[pixel[7]] > cb){
               if( p[pixel[8]] > cb){
                if( p[pixel[9]] > cb){
                 if( p[pixel[10]] > cb){
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:5d8c16ccaf3303e9c33d26af377086aa ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[3]] > cb){
                        if( p[pixel[4]] > cb){
                         if( p[pixel[5]] > cb){
                          // ~CodeReview ~ID:8baa8ec228c1e2dda7dde3a6e262ac16 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:974fd32ec3827a7792e7c6d9dfca50d0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:b89eb15e9c1117bd2e8b4cfbd3ca3e85 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:1766cf9f801455be68386071d5313d87 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:4ca7290e618853769681296cf2e40ffd ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:a3c9d0b9248ed83fde95942e45121862 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:bc867027c82cc2fcedc4d1b896e460c9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:83d3ecc237f53e95c878696e655ed768 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:9fdd5ac10f185dc32f3ec445a4da97b6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:32a413e8bfdb966250b62fdbd32d7968 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:8988deae9a4d093047771174633743ce ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:7a1e73e50168b5c2c57594e4d847ee81 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else if( p[pixel[6]] < c_b){
              if( p[pixel[4]] < c_b){
               if( p[pixel[5]] < c_b){
                if( p[pixel[7]] < c_b){
                 if( p[pixel[8]] < c_b){
                  if( p[pixel[9]] < c_b){
                   if( p[pixel[10]] < c_b){
                    if( p[pixel[11]] < c_b){
                     if( p[pixel[12]] < c_b){
                      if( p[pixel[13]] < c_b){
                       if( p[pixel[14]] < c_b){
                        if( p[pixel[3]] < c_b){
                         // ~CodeReview ~ID:82aea9b0c472cb4d96bc977b23eaff7a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         if( p[pixel[15]] < c_b){
                          // ~CodeReview ~ID:6d0f7a381b186fb3e431c77e4e161078 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:a6520fa85f8feb14f97c26c8cf942888 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:ee399049da0b08688fadd5674cfb6042 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:559d51981c98f9b14033a33cd04c443e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:2580fdf182ad0f66deff0d846bf04e3a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:63842c3e9bf5f2db2cfa43da1e99e1d5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:08c2518e92a79fb27a4b562e37eac9f0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:320367563a655f399c17980d565c75f0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:0465a268d285117272a516f3e11b5e18 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:34c212b89c8d656a5a6d236b54b4110f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:434aec9d5a1dd94202a2e0f270d55b82 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:0d4e866e11498b6b0e7bf6c9913bf369 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:d00c336c0cc79be2f9e1d6299527cec1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
           }else if( p[pixel[1]] < c_b){
            if( p[pixel[5]] > cb){
             if( p[pixel[6]] > cb){
              if( p[pixel[7]] > cb){
               if( p[pixel[8]] > cb){
                if( p[pixel[9]] > cb){
                 if( p[pixel[10]] > cb){
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:071dc06a026361779f4503e8475d8486 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[3]] > cb){
                        if( p[pixel[4]] > cb){
                         // ~CodeReview ~ID:25277ef82fbaf55e1424e89d3ac5822f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:6e86862843054239f579c2b30884f6ad ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:02806d33a484a3abbc7362bfa58fa94c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      if( p[pixel[2]] > cb){
                       if( p[pixel[3]] > cb){
                        if( p[pixel[4]] > cb){
                         // ~CodeReview ~ID:f2b11d9e8aca25397dd9c3a4773478f5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:13561097abc16d65286382e68003c13a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:ab64274291faa370d881f6b96c65be65 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:08574858867218df4d6f6eb40288d9b7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:552720d8dc04f4e6eb7a3559bedf6683 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:e71e29165e9eacc6257592ad44b1df83 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:fa8efacd24dfacd84470866fbae4b3f0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:692562efa2da6ecb7ada195981587b6d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:d5e531055af92d811cabdc7ba536962a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:23faa604c5615e6dc482490fd7b460c0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:0d62f1e72c0da40d26d20bb16978297d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:fdb092a06ff5f12750c34a4033b15bc9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else if( p[pixel[5]] < c_b){
             if( p[pixel[4]] < c_b){
              if( p[pixel[6]] < c_b){
               if( p[pixel[7]] < c_b){
                if( p[pixel[8]] < c_b){
                 if( p[pixel[9]] < c_b){
                  if( p[pixel[10]] < c_b){
                   if( p[pixel[11]] < c_b){
                    if( p[pixel[12]] < c_b){
                     if( p[pixel[3]] < c_b){
                      if( p[pixel[2]] < c_b){
                       // ~CodeReview ~ID:9af9fc05ec2ab848c45d0c96d67e0eb2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[13]] < c_b){
                        if( p[pixel[14]] < c_b){
                         // ~CodeReview ~ID:7e19656afb62e2a73700f36c3d54b563 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:842158033d142d98b230ecaf8a09c014 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:3bc9c0371ae0902708b05fe4237982e2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      if( p[pixel[13]] < c_b){
                       if( p[pixel[14]] < c_b){
                        if( p[pixel[15]] < c_b){
                         // ~CodeReview ~ID:0f74ee082c58739474bf084ed1a7020e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:d4850aae1bb00809f1a102dcb42892b5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:3fb33544cf99286cc53a0d8502f15cb7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:612217908ae69987287f8708a57d5347 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:0dd941e5b67a12c1c517ec831f2e36b9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:d31ce1cb78c6a4a77467aa5bd1030470 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:becd3fa2dce73cedb107b5d23ccdb8f2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:afdf734880106d180c5deb6f4fc21eed ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:7f399df972224204f5a13b7ff7393c3f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:ecd35bba603cb3e068948a26fd75acad ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:f0663a739664d19824fd81d1a0b08965 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:4bf50103ae597a9617425554394f1488 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else
             // ~CodeReview ~ID:cd94f6053c97c23e2a5a6e60c1624fd1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
             {goto is_not_a_corner;}
           }else
            if( p[pixel[5]] > cb){
             if( p[pixel[6]] > cb){
              if( p[pixel[7]] > cb){
               if( p[pixel[8]] > cb){
                if( p[pixel[9]] > cb){
                 if( p[pixel[10]] > cb){
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[13]] > cb){
                     if( p[pixel[14]] > cb){
                      if( p[pixel[15]] > cb){
                       // ~CodeReview ~ID:423c8f919e38794f31bcdd543e346ebf ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[3]] > cb){
                        if( p[pixel[4]] > cb){
                         // ~CodeReview ~ID:07906a77711cb7dec4716b5c1161a8d5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:93d5416c60e9e9b7775f92d6b05ffb97 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:6aead641d28a5ff19bd142268251f7f7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      if( p[pixel[2]] > cb){
                       if( p[pixel[3]] > cb){
                        if( p[pixel[4]] > cb){
                         // ~CodeReview ~ID:1f71ef922ba44367f5b5bae2965c3100 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:bca4b29adc6773c004560a39f242e8cc ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:365ca1dfafb000f19df24ffad9619242 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:c2328820e3ea8cb04e8de3a3cf3c97ee ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:c4f62d456f2beed3755b9f511f50de6f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:284ff68b30915e6504b94d9df35e9673 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:2e72a8f9587edbf2201539db78cadbda ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:4b4905fd0c1f040cbd7154e98ebfe528 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:1790689b2f5353718b0dfa29bc9e5c07 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:65e48c9087340df10b1b7bb2493b8ec3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:2a5c6ecb43e4db8a141f8ab503103675 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:6f3fffdd8891676054a5f708f6309c30 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else if( p[pixel[5]] < c_b){
             if( p[pixel[4]] < c_b){
              if( p[pixel[6]] < c_b){
               if( p[pixel[7]] < c_b){
                if( p[pixel[8]] < c_b){
                 if( p[pixel[9]] < c_b){
                  if( p[pixel[10]] < c_b){
                   if( p[pixel[11]] < c_b){
                    if( p[pixel[12]] < c_b){
                     if( p[pixel[13]] < c_b){
                      if( p[pixel[3]] < c_b){
                       if( p[pixel[2]] < c_b){
                        // ~CodeReview ~ID:437a2397c4b53b7550571899e6312193 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_a_corner;}
                       }else
                        if( p[pixel[14]] < c_b){
                         // ~CodeReview ~ID:ebb899463944dd9dd50360f8a670386b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:b0bfddad30bddd80defe41c1c4642749 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                      }else
                       if( p[pixel[14]] < c_b){
                        if( p[pixel[15]] < c_b){
                         // ~CodeReview ~ID:1470d7707c4a454ec2bbc03ede7490cb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:ad3f38c580143aada7e77114d6610c9c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:bd41cc1cdd7bfa866114bb4efd99d415 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:4d2f052fb2e1f1c3776c937af5ccdc73 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:6ea90f210e854c7358cfe07691d27eff ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:767466cac5f6639882e84d870d6cd5b6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:72ade57e697d497b297f686cf743f9b9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:104609a8e2c1d4e5efd8683e672b6859 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:23cd979f1347c01005cfd037390caa18 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:850d3fcebf935a4d9c3ab94d956c13a0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:1e3120f51a1be6b01876c9cd815650fa ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else
             // ~CodeReview ~ID:05683d5a0a009b0d39d6c46b016318bb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
             {goto is_not_a_corner;}
          }else if( p[pixel[0]] < c_b){
           if( p[pixel[1]] > cb){
            if( p[pixel[5]] > cb){
             if( p[pixel[4]] > cb){
              if( p[pixel[6]] > cb){
               if( p[pixel[7]] > cb){
                if( p[pixel[8]] > cb){
                 if( p[pixel[9]] > cb){
                  if( p[pixel[10]] > cb){
                   if( p[pixel[11]] > cb){
                    if( p[pixel[12]] > cb){
                     if( p[pixel[3]] > cb){
                      if( p[pixel[2]] > cb){
                       // ~CodeReview ~ID:b80e52d1689c71f1c40993e866d8ca97 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[13]] > cb){
                        if( p[pixel[14]] > cb){
                         // ~CodeReview ~ID:98d20e42cdd701a6cae757be614ca6ea ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:101c6cc77199c4bb10272bcbf92c106c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:b4ef6755bc1e43f0e2bce28bebfc9e5c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      if( p[pixel[13]] > cb){
                       if( p[pixel[14]] > cb){
                        if( p[pixel[15]] > cb){
                         // ~CodeReview ~ID:3d6d847bee7f941259417e8fd0c33736 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:8e8f82cc1f4a2f78b3b00c336f4977fc ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:93d852bd9f002968b8b8e439aa5b7707 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:f89b22c6a8eb602d8155dc0cf8661412 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:283bb2a518472a22c4a92efb08bfc7f5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:69af9904e3baa59c70141437056346de ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:ab7303de502e979e8e207738a227de3c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:b2153cf297797f99ea4224ace98fcc77 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:21bd029dc5d60570adc7859644cbe627 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:49471b2aa3f33ab52c9c5d7e1f59b7f6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:0f510f066c6829551488329fd746eae5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:9d73dee8b04aa969d0952c5ef4e9fe0f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else if( p[pixel[5]] < c_b){
             if( p[pixel[6]] < c_b){
              if( p[pixel[7]] < c_b){
               if( p[pixel[8]] < c_b){
                if( p[pixel[9]] < c_b){
                 if( p[pixel[10]] < c_b){
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:5cf332f911f626aa7aa66c5df620f31a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[3]] < c_b){
                        if( p[pixel[4]] < c_b){
                         // ~CodeReview ~ID:5bfa35a706d0583238a74a9c20e8b70e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:5aad0d4bf613bf889a408d2fb52eac81 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:02db5c62833ce38bc09c802853953c12 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      if( p[pixel[2]] < c_b){
                       if( p[pixel[3]] < c_b){
                        if( p[pixel[4]] < c_b){
                         // ~CodeReview ~ID:ecc275d82e6ea4a7b28475376e55da4f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:c4ea1245255e083261bd5898d37892a7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:672bd2cb79560c30b168973c7576f921 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:08f2fcc9ba6c5d9f16be6021e50fb7db ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:1c50e03693a96a271acfac46332fe9b0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:34932cb38c6166d90550bdcf6942de3e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:174dc1ab345bb43891cfa6c522caa41e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:73d27f3bf06e2428e5a230a211d623fb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:b1010f495ce29e5f654b2f085c63ad5c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:c5ba4021cc098c590e20a5dec044e8d1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:41beb2427afac657e590818a8337357f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:b7c5fb9dab8b7bd89d6e71279fdbd167 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else
             // ~CodeReview ~ID:049871c3bd344e94feef8b2b8b8afe4d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
             {goto is_not_a_corner;}
           }else if( p[pixel[1]] < c_b){
            if( p[pixel[2]] > cb){
             if( p[pixel[6]] > cb){
              if( p[pixel[4]] > cb){
               if( p[pixel[5]] > cb){
                if( p[pixel[7]] > cb){
                 if( p[pixel[8]] > cb){
                  if( p[pixel[9]] > cb){
                   if( p[pixel[10]] > cb){
                    if( p[pixel[11]] > cb){
                     if( p[pixel[12]] > cb){
                      if( p[pixel[13]] > cb){
                       if( p[pixel[3]] > cb){
                        // ~CodeReview ~ID:a89f3052189229949302762b7028e3d8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_a_corner;}
                       }else
                        if( p[pixel[14]] > cb){
                         if( p[pixel[15]] > cb){
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:9e369e97e159f1b4173df2e2048bd7f2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:83ab1d518cbc6a362995e335c952ad68 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:dedc6c0c5fb5832540f80ad1f3ab8b05 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:a30220d1752fe5794eb4bb8f49119b6e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:c3c930ec111bc03da93e765f303ccc05 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:7606e7fd4968d862f221da66318a591a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:467790f9500a5b6ae9dcf7f97a49e70f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:c89b7a39c298c75a02e91e5efc6e256b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:14eb59b9078eda9f9afdd52a59b5056c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:838a2b4519653add75631ec56418c56a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:70df01902616a816102bb97e9a4cff4f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else if( p[pixel[6]] < c_b){
              if( p[pixel[7]] < c_b){
               if( p[pixel[8]] < c_b){
                if( p[pixel[9]] < c_b){
                 if( p[pixel[10]] < c_b){
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:fbc53a2a837f9c7868945bbb5a25d294 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[3]] < c_b){
                        if( p[pixel[4]] < c_b){
                         if( p[pixel[5]] < c_b){
                          // ~CodeReview ~ID:c1d59e9403cc58756e492d0aae03bf41 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:f86fd0758610f3f232108333682081f6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:781745825f4b37b60ee59db5db0c5d95 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:3f94f738d65583b57b53bc927f2977e9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:72477bcd85dce4aa24b4f008ce89e09a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:fccd3bb54f9e2d95ffc9646ae5dd811e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:b15f599c8f98f7af99aaf4bccbb835a4 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:3f68d5e8c29ac136c0694944377bf6b0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:0b92cf7b568c36a6c894d4fbe5adf64a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:ea0dd1249383109e8d3bd84a1e90c096 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:ca87085001e76be99d474b997af361c2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:ead1efbd441089b10886e14b37a15782 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:3824239ff95895ccda36c40a34ff7eaa ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else if( p[pixel[2]] < c_b){
             if( p[pixel[3]] > cb){
              if( p[pixel[15]] < c_b){
               if( p[pixel[7]] > cb){
                if( p[pixel[4]] > cb){
                 if( p[pixel[5]] > cb){
                  if( p[pixel[6]] > cb){
                   if( p[pixel[8]] > cb){
                    if( p[pixel[9]] > cb){
                     if( p[pixel[10]] > cb){
                      if( p[pixel[11]] > cb){
                       if( p[pixel[12]] > cb){
                        if( p[pixel[13]] > cb){
                         if( p[pixel[14]] > cb){
                          // ~CodeReview ~ID:abdd983f4bed82fa0b34e2027f9ee9cc ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:1a9b6958be8005eaeb378afbd059ad3d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:92a8d3ed8e035c4a90b4d922a871207f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:bc1d584d7cba0236c2b62515c0832bb8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:dea83144591aba2df2a82d458c11e81e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:d7bff1d88d788456bcac3860b9fd4beb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:d5f196b7beb84ba8944316a067bc2bc4 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:969a96f8f660c6c19a2bfeebe7a9c62e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:d936ea8c0705b3759b4d5fe2d90d7608 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:2ae1fc61aa4f76de08ab58219b38fac7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:aefaed2765fa2c749ae5038bfc493d33 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else if( p[pixel[7]] < c_b){
                if( p[pixel[8]] < c_b){
                 if( p[pixel[9]] < c_b){
                  if( p[pixel[10]] < c_b){
                   if( p[pixel[11]] < c_b){
                    if( p[pixel[12]] < c_b){
                     if( p[pixel[13]] < c_b){
                      if( p[pixel[14]] < c_b){
                       // ~CodeReview ~ID:4a8d6e27ba367c4a3f12ff48421697d8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:75d84dcf3b74093bf96129a2de7cca30 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:67196380e688845cb18df579ca0d71c3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:1f071d1fccd4d94819c42c325c000229 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:3ffbde85ef98324425c272a712f9be92 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:7dfa70c82559287a6adb8aa4cec04775 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:b7dbea28301a6ded81f39b2f035a4c41 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:e023bd79b9a68715bd676dcdd5873e7b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:cede367e73e105b8730873de410623af ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               if( p[pixel[4]] > cb){
                if( p[pixel[5]] > cb){
                 if( p[pixel[6]] > cb){
                  if( p[pixel[7]] > cb){
                   if( p[pixel[8]] > cb){
                    if( p[pixel[9]] > cb){
                     if( p[pixel[10]] > cb){
                      if( p[pixel[11]] > cb){
                       if( p[pixel[12]] > cb){
                        if( p[pixel[13]] > cb){
                         if( p[pixel[14]] > cb){
                          // ~CodeReview ~ID:e8fd4e092abf0e4cc670f4db16e27574 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:b2f6e934878f667abaf1a0156986a6b8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:6c1cc3ef83e9d36e357972fe9861dcaa ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:0065c4e73e577d6935434faaba728316 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:f700bd87f2a4f9dfc3d161ffe15f4752 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:2ccb4b14858c6179b29077609ce44d20 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:324bad97dd723603cc0c0cf848217be7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:120c9d0f9961543f5cb4121b66bef80d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:cd691d6bab2577bf0bd70fa4649e080a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:ec6687459d0fdd65b866d07ea21e3a25 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:68dad08550bdf15524e909a797ad2165 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:fd8c27acaa41a6167eab39b650bb3152 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
             }else if( p[pixel[3]] < c_b){
              if( p[pixel[4]] > cb){
               if( p[pixel[8]] > cb){
                if( p[pixel[5]] > cb){
                 if( p[pixel[6]] > cb){
                  if( p[pixel[7]] > cb){
                   if( p[pixel[9]] > cb){
                    if( p[pixel[10]] > cb){
                     if( p[pixel[11]] > cb){
                      if( p[pixel[12]] > cb){
                       if( p[pixel[13]] > cb){
                        if( p[pixel[14]] > cb){
                         if( p[pixel[15]] > cb){
                          // ~CodeReview ~ID:fb2698ebfda2fb9193e5fac8a4ccf29a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:7a6ff4ddebe4d097bced4787522728c1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:75bf7b7c25010890ad0b2b636723bcce ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:b54f3de48c0765f67fd0b145c613269c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:978134a64c8c7f026f421c337d7f9f23 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:fdafe3515679b3d2e4b29e4ad045a4c1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:3e0ea776cf2ff7bafb204ca319ae4fc3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:eea7b1d9b9807f9c3ed89a994e067bc0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:42a6cae1f6799f4c6eae4191efb07a82 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:031e36dfaa53c3f651333b6ea741edd7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:b1ee214d14356efa85fb1cfe81d69cca ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else if( p[pixel[8]] < c_b){
                if( p[pixel[9]] < c_b){
                 if( p[pixel[10]] < c_b){
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:09f6c4d2ac7e7230e6e07f65419269b4 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:9bf1ebdf14d9272ddff8c774b32f0d0e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:fa97cd61523b14c5e1748c39cf37f88f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:15467b0f9b91371057227b1af414fd4c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:32c05c5e81b2d2123c7c1f12a90032f0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:9337292ffd95919c59e1928497545e81 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:f9335935c81c4719d032ed212a828df5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:7f2afed7a0d1b517048777cc1230389e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:279de1e3c0954beb858ca7c4a1e29220 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else if( p[pixel[4]] < c_b){
               if( p[pixel[5]] < c_b){
                if( p[pixel[6]] < c_b){
                 if( p[pixel[7]] < c_b){
                  if( p[pixel[8]] < c_b){
                   if( p[pixel[9]] < c_b){
                    if( p[pixel[10]] < c_b){
                     if( p[pixel[11]] < c_b){
                      // ~CodeReview ~ID:f2dfdc173cb71a52dfacc535e4c1eed5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_a_corner;}
                     }else
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:090340777bb5a4d4893f7452104bfa16 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:2afb48529f610f9207858f9e8f71b9d8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                    }else
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:fc310b46544b2136ec33291e0d68396b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:fd988caa39b4ad662153f4c4ebb08bec ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:dff24fae8d536a27ad60926c14a43ce3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                   }else
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:7e9a24ba2fa5521890fd1365ceb84d81 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:afdaaffbb9b91ca855048c3ab785975e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:cbb7e4e0656e78cdab365c016ed7fc10 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:9943765f66b472b28839f862dcf591b9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                  }else
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:f1d1b5dafcd6b78276deb713c1ebac99 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:1ef65827ff0483ff3eb8c78ece722416 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:18daf7247ddd4c3b604b7c9d1488e0af ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:7353f72d876c777093953ee997ead53c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:a44369bd0e8df23384829e102fa5626f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                 }else
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:89e45649bfef6c630509da47ecf716f6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:25747a60fd1a3bbf288e99546c45eb3a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:d100af2e25b4db70863059e8ea9e5d91 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:26f532feb40f35c67753ba7ae008974d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:cff2971cddf9212f997fd636c1927365 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:f7df4f0843ffe77242310c255ab11ecd ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                }else
                 if( p[pixel[10]] < c_b){
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:bdb6c028d78dd4b588402568fb626b45 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:d34bc4e480f944566e66d61b4d546178 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:122246248292dfddd3fac9d055e8a5a5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:1f00b95f19e2c0209ffbcf66ecb2f2ea ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:1299c8b7d92a85b4a05339b55dd4cf50 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:129bbb97f3ec33038baa63605ab29b6c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:0d25291b327d4f1ef756e11f98b3d41e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
               }else
                if( p[pixel[9]] < c_b){
                 if( p[pixel[10]] < c_b){
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:c77930f5493fd18ccf1073961150a6de ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:5d838863878a810cfb15c5198c7611bf ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:6a3ebfc7a80d5766167fab732111dbb0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:ba5699669a4c2c576e33f49381cfa2a7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:e439d7d16ab81281cd02e3c545be52ed ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:bab2cd795424be5334aa94b76fec89f1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:8ee746aa0f22972e5a7f85a98e074106 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
              }else
               if( p[pixel[8]] < c_b){
                if( p[pixel[9]] < c_b){
                 if( p[pixel[10]] < c_b){
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:9afa66e69fe6071b1d08d70db6cb6c18 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:ef10e447f9b417e96bdd718686011855 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:6ee337b785a16110f63bd66e89d5697f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:8bed7ed648df7bd7a38fecbf95cb7ac8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:2091b95f1880aaa233d695ce592014cd ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:d3035c2abb338c40c87efaf0a958e92c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:9533ecb7e06ea42030cc1561c69f49f5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:b513541b1bc9c7878d63778171c36319 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:7d77e67a2837135d78029395421a2f0d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
             }else
              if( p[pixel[7]] > cb){
               if( p[pixel[4]] > cb){
                if( p[pixel[5]] > cb){
                 if( p[pixel[6]] > cb){
                  if( p[pixel[8]] > cb){
                   if( p[pixel[9]] > cb){
                    if( p[pixel[10]] > cb){
                     if( p[pixel[11]] > cb){
                      if( p[pixel[12]] > cb){
                       if( p[pixel[13]] > cb){
                        if( p[pixel[14]] > cb){
                         if( p[pixel[15]] > cb){
                          // ~CodeReview ~ID:081eef990bfa6f1562b9c03719887dd0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:d5826db27bbdafbe009a787354933b98 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:5c84e336b74a5574ec5c0a6aec57f2d9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:95cb9eafba6045b8270bdab505e7b6ad ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:5ab268011ab1a0bfcd51e7d9f22cf6ee ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:69b0f7483972074c609ba978d100d0bb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:9232b2b1845e9d2e4d254df92f51b8a3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:d8af146b2d60242bd97bcaa8ec817200 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:c057e2c6eec1902e91732b5b6352f19b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:6165b357b993dd473086bf849c9924cc ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:34ff68a121e55bb58b98b23688103560 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:ef8bb98fd2a45064ee9803559f772f1c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else if( p[pixel[7]] < c_b){
               if( p[pixel[8]] < c_b){
                if( p[pixel[9]] < c_b){
                 if( p[pixel[10]] < c_b){
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:41a00350724c9a82554c336cd6cb21f0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       // ~CodeReview ~ID:c8ce46b5f7b60f7584c686c677a83efb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:667d0e6306b22825d131c6ea88f91e91 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:0343196a22cb41b6d290c86530380a71 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:6f13442bb61444cc8eedae3598a4a32f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:dde081d41c47718334410348433b5099 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:ff368c7c06479ec036b18c001ee11831 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:fee17943291bff7296bc0b57bdccd8e8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:4c057f8c7d24e8ab1c00fabd2c07675b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:eff900b089c2ddf2a4f8214df86ac577 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
            }else
             if( p[pixel[6]] > cb){
              if( p[pixel[4]] > cb){
               if( p[pixel[5]] > cb){
                if( p[pixel[7]] > cb){
                 if( p[pixel[8]] > cb){
                  if( p[pixel[9]] > cb){
                   if( p[pixel[10]] > cb){
                    if( p[pixel[11]] > cb){
                     if( p[pixel[12]] > cb){
                      if( p[pixel[13]] > cb){
                       if( p[pixel[14]] > cb){
                        if( p[pixel[3]] > cb){
                         // ~CodeReview ~ID:9a089e4c296ed8b3774d9d2ea6bac3b6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         if( p[pixel[15]] > cb){
                          // ~CodeReview ~ID:dcb8e5f0363fe32ec4321f11121da92e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:f5bbf245964f8c02f9de4caea982c718 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:55931f666b647bfa86e464cf813ec3ef ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:ffcee80b3575cdde73bfa9cfd49808f2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:b5f3fed0c90a68cb50f36dcf5ffc0190 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:dcd540a17ac603b76e1a63cb771cbf04 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:9ad5c80d74419d56bca077beafcbedc0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:7b13a8b46e6a76f3f21c726cafe28eef ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:db3586171a88a308489f7e245cdcb9aa ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:e87a5f78069ed298fdc1a72b2afe91b6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:36a18e6f4613d4b2a871c727e6aaafcf ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:7899684a5f088d159ebf03906a2a646a ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else if( p[pixel[6]] < c_b){
              if( p[pixel[7]] < c_b){
               if( p[pixel[8]] < c_b){
                if( p[pixel[9]] < c_b){
                 if( p[pixel[10]] < c_b){
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:ee78e9a256f2d740dfbad507566a9c62 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[3]] < c_b){
                        if( p[pixel[4]] < c_b){
                         if( p[pixel[5]] < c_b){
                          // ~CodeReview ~ID:213e7a5e4a50ced8711161f3cc10363c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_a_corner;}
                         }else
                          // ~CodeReview ~ID:6fc0653372dcab95185b1b8c903a01e6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                          {goto is_not_a_corner;}
                        }else
                         // ~CodeReview ~ID:bbef05780ae65f339574a207ae14491e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:1fee4183edaf3a23ec722549952ee5b5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:aa575dd971a0feed9c0e09318d005bba ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:a3e49a6f697288b185292541237e87a3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:f03b371cb240532ec5845ff68cea24d9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:95aacab03423e46cea4450510b389cb3 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:f7ea7d305c08e9feea37cf70a3fb1772 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:194b063227cbf148c3b651d9307ce322 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:ca56e7e83420af892bf7541fa0cf3071 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:da92e9c0bf973ccd7d12199acac19815 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:f2e427b044c8d6097f9de816fdd9ea38 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
           }else
            if( p[pixel[5]] > cb){
             if( p[pixel[4]] > cb){
              if( p[pixel[6]] > cb){
               if( p[pixel[7]] > cb){
                if( p[pixel[8]] > cb){
                 if( p[pixel[9]] > cb){
                  if( p[pixel[10]] > cb){
                   if( p[pixel[11]] > cb){
                    if( p[pixel[12]] > cb){
                     if( p[pixel[13]] > cb){
                      if( p[pixel[3]] > cb){
                       if( p[pixel[2]] > cb){
                        // ~CodeReview ~ID:de593388ca4c897372e7e919023e1af6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_a_corner;}
                       }else
                        if( p[pixel[14]] > cb){
                         // ~CodeReview ~ID:ed2276294bb450a0f50c408c2ab582d6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:5a64c7657421076020a381b1073727c5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                      }else
                       if( p[pixel[14]] > cb){
                        if( p[pixel[15]] > cb){
                         // ~CodeReview ~ID:e7a55eec831f014eb75577875eeb220c ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:2f2de300c0c9fe6520c161edacc63f17 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:0dd4abac97f51818f7135297aa253104 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:84b9dba768305a20efb3dad445262483 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:802586add33eccb4c4625f8bc79366f1 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:7cf17aceb56a0fdeb03ac8126a2e3618 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:0c004f45faffa11697edb1692a7a01bc ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:98b00b3a79cf93b3a67e4602d66c230f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:f43152168fddd245ac84d7b77ffa1243 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:d28ac43616d54fc00d1b2bc21aa0c1f5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:9e2fd4432fe95c1fbdf778525729b400 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:ec5ef3208f4e869b978bca39d816b1fe ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else if( p[pixel[5]] < c_b){
             if( p[pixel[6]] < c_b){
              if( p[pixel[7]] < c_b){
               if( p[pixel[8]] < c_b){
                if( p[pixel[9]] < c_b){
                 if( p[pixel[10]] < c_b){
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[13]] < c_b){
                     if( p[pixel[14]] < c_b){
                      if( p[pixel[15]] < c_b){
                       // ~CodeReview ~ID:73aa932597cc6abce7d969ca09218336 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[3]] < c_b){
                        if( p[pixel[4]] < c_b){
                         // ~CodeReview ~ID:0f4f54c3022f9e0872b9ce05e16dec47 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:9628dad185bb8c26f822fa57f97230fb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:10e87f245dfddd2d3d442f3965ef1a98 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      if( p[pixel[2]] < c_b){
                       if( p[pixel[3]] < c_b){
                        if( p[pixel[4]] < c_b){
                         // ~CodeReview ~ID:d0f4964655459b96f5b5e3e65bd61921 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_a_corner;}
                        }else
                         // ~CodeReview ~ID:6107c4a5fb1d5b41a533b3daaac00774 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                         {goto is_not_a_corner;}
                       }else
                        // ~CodeReview ~ID:3c91179442a84cead8f82a43b37b472d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:c58312be4a8c5f9fa4b80786b5eaef7e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                    }else
                     // ~CodeReview ~ID:df1b8f4ef81112026560e24c245179cd ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                     {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:333796ab088a0737032cefd959194b1d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:18c875b35c814160a129c1f01971c1ec ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:cb2b25e18265dc507a8a180cff792c81 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:3f5a392ba73b5e8fe046e3d06a1e67c8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:bde1852ee2e5aba05afb10b0106f83f5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:9f05df89333dfe71e21a3c8f99c765bb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:aa5d576cafa852e71854007d49fd22fc ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else
             // ~CodeReview ~ID:9e8c62ddc794f51e107def2f0584bcc5 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
             {goto is_not_a_corner;}
          }else
           if( p[pixel[4]] > cb){
            if( p[pixel[5]] > cb){
             if( p[pixel[6]] > cb){
              if( p[pixel[7]] > cb){
               if( p[pixel[8]] > cb){
                if( p[pixel[9]] > cb){
                 if( p[pixel[10]] > cb){
                  if( p[pixel[11]] > cb){
                   if( p[pixel[12]] > cb){
                    if( p[pixel[3]] > cb){
                     if( p[pixel[2]] > cb){
                      if( p[pixel[1]] > cb){
                       // ~CodeReview ~ID:286f02d875e077da4fedd2604a7db6b2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[13]] > cb){
                        // ~CodeReview ~ID:6048d257931604a56fb872eee38333b7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_a_corner;}
                       }else
                        // ~CodeReview ~ID:1765c66e7c28427c78b8a617cbb222f6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      if( p[pixel[13]] > cb){
                       if( p[pixel[14]] > cb){
                        // ~CodeReview ~ID:b03000423665439a1903e04c3692199e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_a_corner;}
                       }else
                        // ~CodeReview ~ID:ddf8c95f7e02ec2cb52eef44cbe6ca88 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:57f5834418f533cf78f384dc31dd71c7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                    }else
                     if( p[pixel[13]] > cb){
                      if( p[pixel[14]] > cb){
                       if( p[pixel[15]] > cb){
                        // ~CodeReview ~ID:5185aa61944e1405e372d88c767ee415 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_a_corner;}
                       }else
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:72c0162d902bfc033685677a510f1517 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:c2d7e179994d1b7b89a01604d12d2190 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:a8665e044166193845f36c103b6c6e6f ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:012c73b721896fb9b568f9f79c906c54 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:d6a5c562799fb663a14ce7c304858eb0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:885b2eac77f1eac9aa5ee433cd7ba76d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:44f23741ecff7285cd17b6a8cde4b03d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:7c28bcdf67b888aab7985d714b189e99 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:aa0559c0313ee0964130a28945b79944 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else
             // ~CodeReview ~ID:46ad96813fc36bcf213c1f85516e3704 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
             {goto is_not_a_corner;}
           }else if( p[pixel[4]] < c_b){
            if( p[pixel[5]] < c_b){
             if( p[pixel[6]] < c_b){
              if( p[pixel[7]] < c_b){
               if( p[pixel[8]] < c_b){
                if( p[pixel[9]] < c_b){
                 if( p[pixel[10]] < c_b){
                  if( p[pixel[11]] < c_b){
                   if( p[pixel[12]] < c_b){
                    if( p[pixel[3]] < c_b){
                     if( p[pixel[2]] < c_b){
                      if( p[pixel[1]] < c_b){
                       // ~CodeReview ~ID:d34009fb0c5950b432cd0619445215ff ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_a_corner;}
                      }else
                       if( p[pixel[13]] < c_b){
                        // ~CodeReview ~ID:f277c7b6c86277aa62301f04a04486d6 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_a_corner;}
                       }else
                        // ~CodeReview ~ID:043eb34e953d7efb5039e718f0eb46d9 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                     }else
                      if( p[pixel[13]] < c_b){
                       if( p[pixel[14]] < c_b){
                        // ~CodeReview ~ID:daf4ebe9b81617a25432d507beb49f12 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_a_corner;}
                       }else
                        // ~CodeReview ~ID:9105ea1151e04e5610115dfd2411bb31 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:a16c718d40ce575374ae033f2ed35a11 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                    }else
                     if( p[pixel[13]] < c_b){
                      if( p[pixel[14]] < c_b){
                       if( p[pixel[15]] < c_b){
                        {goto is_a_corner;}
                       }else
                        // ~CodeReview ~ID:2e69a290139ee145e581ceeb36091698 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                        {goto is_not_a_corner;}
                      }else
                       // ~CodeReview ~ID:d2b24389c79a5a715caad311f39318b2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                       {goto is_not_a_corner;}
                     }else
                      // ~CodeReview ~ID:c00688a903e400a546fe39acea7fea5b ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                      {goto is_not_a_corner;}
                   }else
                    // ~CodeReview ~ID:0f12f77d16754c93027650b0b49d8aa8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                    {goto is_not_a_corner;}
                  }else
                   // ~CodeReview ~ID:5cb241a78177d7e7ad9870bfefe17aa8 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                   {goto is_not_a_corner;}
                 }else
                  // ~CodeReview ~ID:37fb99621d0e37e260a2728bc2d0ba6e ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                  {goto is_not_a_corner;}
                }else
                 // ~CodeReview ~ID:b94085b1479a5f7e5e5663e58d47a46d ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                 {goto is_not_a_corner;}
               }else
                // ~CodeReview ~ID:f9960b5b0217c41fb2cb5f0058b54126 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
                {goto is_not_a_corner;}
              }else
               // ~CodeReview ~ID:24aee3db440859483a9b121012290913 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
               {goto is_not_a_corner;}
             }else
              // ~CodeReview ~ID:364ca1432e25df9924f2b3897a7f9fea ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
              {goto is_not_a_corner;}
            }else
             // ~CodeReview ~ID:5575b4f1e691e9d6a635a4431b7eeaa2 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
             {goto is_not_a_corner;}
           }else
            // ~CodeReview ~ID:48bd80f7902b9c2030ab84cbdf4b2dcf ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
            {goto is_not_a_corner;}

          is_a_corner:
		    result = bstart;
   // ~CodeReview ~ID:357b58719c9a6461e6bba24185fa3f66 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
			goto end_of_function;

        is_not_a_corner:
	    result = 0U;
  // ~CodeReview ~ID:3d7eadebbb054350b5cfd3f1fcda9a91 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error 801 (use of goto is deprecated) not commented
		goto end_of_function;


      }
	end_of_function:
	return result;
  }

  viscr_bool viscr_fastcorner_check(const viscr_image & img, const viscr_coord u, const viscr_coord v,const viscr_pixel min_contrast)
  {
    viscr_int pixel[16];
    viscr_pixel score;
    viscr_pixel b;
    viscr_bool is_corner;
    b = min_contrast;
    make_offsets(&pixel[0], img.size.u);
    // ~CodeReview ~ID:a6b093b992994d5b469cead25947853e ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:substitute magic numbers by meaningful defines
    /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Parameter control check. */
    if ( (u < (img.size.u - 5)) && (u >= 5) && (v < (img.size.v - 5)) && (v >= 5))
    {
      /* <ln_offset:1 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 06.03.2012 reason: indexing by pointer faster */
      viscr_pixel* p = img.data + u + (v*img.size.u);
	  score = fast12_corner_score(p, &pixel[0], b);
    }
    else
    {
      score = 0U;
    }
    if (score >= b)
      {is_corner = viscr_true;}
    else 
      {is_corner = viscr_false;}

    return is_corner;
  }
#endif

viscr_bool viscr_corner_check(const viscr_image & img, const viscr_coord u, const viscr_coord v)
{
  viscr_bool is_corner;
  M_SAC_PROFILE_START(sSACRun_ACFine_ProcFineEpi_CornerCheck)
#if (VISCR_CORNER_CHECK == 0)
  is_corner = viscr_mincorner_check(img,u,v,28*16);
#endif
#if (VISCR_CORNER_CHECK == 1)
  // ~CodeReview ~ID:0c4feb53b1b19235db56e336ac379f86 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:substitute magic numbers with meaningful defines
  is_corner = viscr_fastcorner_check(img,u,v,5U*16U);
#endif
  M_SAC_PROFILE_END(sSACRun_ACFine_ProcFineEpi_CornerCheck)
  return is_corner;
}
