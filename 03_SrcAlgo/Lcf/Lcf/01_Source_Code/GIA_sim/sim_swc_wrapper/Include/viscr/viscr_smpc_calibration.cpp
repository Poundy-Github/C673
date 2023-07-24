/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SAC - Stereo Auto Calibration

  MODULNAME:      viscr_smpc_calibration.cpp  

  DESCRIPTION:    Auto calibration algorithms

  AUTHOR:         L. GARCIA

  CREATION DATE:  17.06.2011

  VERSION:        $Revision: 1.1 $
  CHANGES:        $Log: viscr_smpc_calibration.cpp  $
  CHANGES:        Revision 1.1 2021/12/13 17:28:35CET Wang, David (Wangd3) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.0 2017/03/03 10:40:28CET Sorge, Sven (uidg3181) 
  CHANGES:        Initial revision
  CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/viscr/project.pj
  CHANGES:        Revision 1.16.1.12 2014/03/03 18:23:20CET Sadran, Emal (uidw7976) 
  CHANGES:        integradted fixed point version for test purposes
  CHANGES:        added support for objective function types (float or fix point) in SDE
  CHANGES:        added more degradation tests
  CHANGES:        - Added comments -  uidw7976 [Mar 3, 2014 6:23:21 PM CET]
  CHANGES:        Change Package : 196075:4 http://mks-psad:7002/im/viewissue?selection=196075
  CHANGES:        Revision 1.16.1.11 2014/02/28 10:19:30CET Ruland, Thomas (uidw0251) 
  CHANGES:        - New optimization framework (still using floating point objective)
  CHANGES:        - Single correspondence OdoYAC test framework
  CHANGES:        --- Added comments ---  uidw0251 [Feb 28, 2014 10:19:30 AM CET]
  CHANGES:        Change Package : 210743:1 http://mks-psad:7002/im/viewissue?selection=210743
  CHANGES:        Revision 1.16.1.10 2014/02/20 13:46:15CET Sadran-EXT, Emal (uidw7976) 
  CHANGES:        reactived floating point version of the epipolar_objfun for test purposes
  CHANGES:        --- Added comments ---  uidw7976 [Feb 20, 2014 1:46:16 PM CET]
  CHANGES:        Change Package : 196075:4 http://mks-psad:7002/im/viewissue?selection=196075
  CHANGES:        Revision 1.16.1.9 2014/02/14 15:12:53CET Ruland, Thomas (uidw0251) 
  CHANGES:        Added more detailed Rta instrumentation to kernel
  CHANGES:        --- Added comments ---  uidw0251 [Feb 14, 2014 3:12:54 PM CET]
  CHANGES:        Change Package : 210743:1 http://mks-psad:7002/im/viewissue?selection=210743
  CHANGES:        Revision 1.16.1.8 2013/08/15 14:29:05CEST Daiber-EXT, Sebastian (uidw3458) 
  CHANGES:        reduce calls to dsp rte and number of divisions
  CHANGES:        --- Added comments ---  uidw3458 [Aug 15, 2013 2:29:06 PM CEST]
  CHANGES:        Change Package : 191881:1 http://mks-psad:7002/im/viewissue?selection=191881
  CHANGES:        Revision 1.16.1.7 2013/06/26 11:43:31CEST Mueller, Reik (muellerr5) 
  CHANGES:        - avoid C runtime check failure when casting 64 bit to 32 bit numbers
  CHANGES:        --- Added comments ---  muellerr5 [Jun 26, 2013 11:43:32 AM CEST]
  CHANGES:        Change Package : 184575:1 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGES:        Revision 1.16.1.6 2012/07/17 15:44:51CEST Garcia, Lucien (uid26778) 
  CHANGES:        pc lint
  CHANGES:        --- Added comments ---  uid26778 [Jul 17, 2012 3:44:52 PM CEST]
  CHANGES:        Change Package : 138467:2 http://mks-psad:7002/im/viewissue?selection=138467
  CHANGES:        Revision 1.16.1.5 2012/07/05 08:43:41CEST Behrens Alexander (uidv2823) (uidv2823) 
  CHANGES:        add code coverage tags (always false/true cases)
  CHANGES:        --- Added comments ---  uidv2823 [Jul 5, 2012 8:43:41 AM CEST]
  CHANGES:        Change Package : 134029:1 http://mks-psad:7002/im/viewissue?selection=134029
  CHANGES:        Revision 1.16.1.4 2012/06/25 09:41:04CEST Visscher-EXT, Eric (uidk7517) 
  CHANGES:        Added code review comments
  CHANGES:        --- Added comments ---  uidk7517 [Jun 25, 2012 9:41:05 AM CEST]
  CHANGES:        Change Package : 127722:1 http://mks-psad:7002/im/viewissue?selection=127722
  CHANGES:        Revision 1.16.1.3 2012/05/31 17:35:45CEST Garcia, Lucien (uid26778) 
  CHANGES:        Remove lint warnings
  CHANGES:        --- Added comments ---  uid26778 [May 31, 2012 5:35:46 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.16.1.2 2012/04/19 15:18:58CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning corrections
  CHANGES:        --- Added comments ---  uid26778 [Apr 19, 2012 3:18:58 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.16.1.1 2012/04/06 14:01:36CEST Garcia, Lucien (uid26778) 
  CHANGES:        Lint warning correction : Bitexactness test + MTS simulation done
  CHANGES:        --- Added comments ---  uid26778 [Apr 6, 2012 2:01:37 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.16 2011/11/21 17:02:47CET Garcia, Lucien (uid26778) 
  CHANGES:        Use only Runtime optimized LM with 20 iterations allowed for coarse calibration and 1 for fine
  CHANGES:        --- Added comments ---  uid26778 [Nov 21, 2011 5:02:47 PM CET]
  CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
  CHANGES:        Revision 1.15 2011/10/07 18:20:39CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove Lint warnings
  CHANGES:        --- Added comments ---  uid26778 [Oct 7, 2011 6:20:39 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.14 2011/10/04 15:44:07CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Remove warning lints
  CHANGES:        --- Added comments ---  uid26778 [Oct 4, 2011 3:44:07 PM CEST]
  CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
  CHANGES:        Revision 1.13 2011/10/04 08:52:03CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:        Remove misra issues
  CHANGES:        --- Added comments ---  spruckj [Oct 4, 2011 8:52:03 AM CEST]
  CHANGES:        Change Package : 79035:2 http://mks-psad:7002/im/viewissue?selection=79035
  CHANGES:        Revision 1.12 2011/08/03 17:00:44CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        started to work on ROI shift
  CHANGES:        --- Added comments ---  uidt6711 [Aug 3, 2011 5:00:44 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.11 2011/07/07 20:00:17CEST Stache Nicolaj (uidt6711) (uidt6711) 
  CHANGES:        3.1 Release Int1
  CHANGES:        --- Added comments ---  uidt6711 [Jul 7, 2011 8:00:18 PM CEST]
  CHANGES:        Change Package : 67326:1 http://mks-psad:7002/im/viewissue?selection=67326
  CHANGES:        Revision 1.10 2011/07/06 19:01:45CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Autocalibration quality measurementand improvement
  CHANGES:        --- Added comments ---  uid26778 [Jul 6, 2011 7:01:45 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  CHANGES:        Revision 1.9 2011/06/17 13:53:38CEST Garcia Lucien (uid26778) (uid26778) 
  CHANGES:        Add header for tracability
  CHANGES:        --- Added comments ---  uid26778 [Jun 17, 2011 1:53:38 PM CEST]
  CHANGES:        Change Package : 67298:1 http://mks-psad:7002/im/viewissue?selection=67298
  

**************************************************************************** */

#include <cmath>
#include <viscr_SMPC_calibration.hpp>
#include <viscr_rotation.hpp>
#include <viscr_levmar.hpp>
#include "sac_optim_objectiveEpipolarCalibration.h"
#include "sac_optim_iterativeOptimizerLevmar.h"

#include "sac_rta.h"



const i16_t ANGLE_LOG2 = 30;
const i16_t CORR_LOG2  = 30;

void
viscr_SMPC_ramp_mEstimator(
    const viscr_float e,
    viscr_float & wt,
    void *,
    void * const mEstData)
{
  /* <ln_offset:1 MISRA Rule 5-2-8, 5-2-9: reviewer name: Yannick Mescam date: 13.03.2012 reason: want to keep generic usage of this function*/
  viscr_SMPC_rampme_data * data=static_cast<viscr_SMPC_rampme_data*>(mEstData);

  viscr_float temp_float_for_misra = e*data->f;
  // ~CodeReview ~ID:5784a0a61d84c33a12dcaa45d1173afb ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error not commented
  viscr_float ad=fabsf(temp_float_for_misra);
  if( ad<data->rampMin)
    {wt= 1.0F;}
  else if( ad>data->rampMax)
    {wt= data->lowWeight;}
  else
    // ~CodeReview ~ID:afb204a8d891f428c061b1c282bde95a ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:2 ~Comment:Potential Divide y zero when rampMax == rampMin
    {wt= 1.0F-(((1.0F-data->lowWeight)*(ad-data->rampMin))/(data->rampMax-data->rampMin));}
}


/// Non-robust objective function for epipolar constraint
static void
epipolar_objfun(
    const viscr_vector & phi,
    viscr_vector & f,
    const viscr_float scale,
    const void * const sampleData,
    void * const ud)
{
  /* <ln_offset:2 MISRA Rule 5-2-8, 5-2-9: reviewer name: Yannick Mescam date: 13.03.2012 reason: want to keep generic usage of this function*/
  /* <ln_offset:2 MISRA Rule 5-2-8, 5-2-9: reviewer name: Yannick Mescam date: 13.03.2012 reason: want to keep generic usage of this function*/
  const viscr_SMPC_epipolar_corr * corr=static_cast<const viscr_SMPC_epipolar_corr *>(sampleData);
  viscr_SMPC_epipolar_calib_userdata * data=static_cast<viscr_SMPC_epipolar_calib_userdata*>(ud);

  viscr_mat33 R;
  viscr_mat33 Rt;
  viscr_mat33 E;
  viscr_vec3 nl;viscr_vec3 nr;
  viscr_vec3 pl;viscr_vec3 pr;


  viscr_float* pfloat_for_misra;
  viscr_int32  int32_for_misra;
  viscr_uint32 uint32_for_misra;
  viscr_uint64 uint64_for_misra;
  viscr_int64  int64_0_for_misra;
  viscr_int64  int64_1_for_misra;
  viscr_int64  int64_2_for_misra;
  viscr_uint64 uint64_sum_for_misra;
  
  pl.data[0]=corr->u0;
  pl.data[1]=corr->v0;
  pl.data[2]=1.0F;
  pr.data[0]=corr->u1;
  pr.data[1]=corr->v1;
  pr.data[2]=1.0F;

  assert(data->Tx.m.data[0] == 0);
  assert(data->Tx.m.data[4] == 0);
  assert(data->Tx.m.data[8] == 0);

  // ~CodeReview ~ID:25a31c8e8a2996d526142df5324c95f3 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:2 ~Comment:Remove or document reason for dead code
  //if (fine_flag == 1)           // fixpointed version
  {
    // ~CodeReview ~ID:b7f10cf056af7df6f67431eb4a9d3c87 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Multiple definitions on the next 7 lines are confusing. 
    viscr_int32 pl_0_i;viscr_int32 pl_1_i;viscr_int32 pl_2_i;viscr_int32 pr_0_i;viscr_int32 pr_1_i;viscr_int32 pr_2_i;
	  viscr_int32 phi_0_i;viscr_int32 phi_1_i;viscr_int32 phi_2_i; 
	  viscr_int32 Rt_I_00_i;viscr_int32 Rt_I_11_i;viscr_int32 Rt_I_22_i;
	  viscr_int64 Rt_01_i;viscr_int64 Rt_02_i;viscr_int64 Rt_10_i;viscr_int64 Rt_12_i;viscr_int64 Rt_20_i;viscr_int64 Rt_21_i;
	  viscr_int32 cos_0_i;viscr_int32 cos_1_i;viscr_int32 cos_2_i;viscr_int32 sin_0_i;viscr_int32 sin_1_i;viscr_int32 sin_2_i;
	  viscr_int32 Txmat_01_i;viscr_int32 Txmat_02_i;viscr_int32 Txmat_10_i;viscr_int32 Txmat_I_12_i;viscr_int32 Txmat_20_i;viscr_int32 Txmat_I_21_i;
	  viscr_int32 E_00_i;viscr_int32 E_01_i;viscr_int32 E_02_i;viscr_int32 E_10_i;viscr_int32 E_11_i;viscr_int32 E_12_i;viscr_int32 E_20_i;viscr_int32 E_21_i; viscr_int32 E_22_i;

	  viscr_float corr_scale_f = static_cast<viscr_float>(static_cast<ui32_t>(1U)<<CORR_LOG2);
	  viscr_float angle_scale_f = static_cast<viscr_float>(static_cast<ui32_t>(1U)<<ANGLE_LOG2);

	  viscr_float temp_float_for_misra;

      temp_float_for_misra = corr_scale_f * pl.data[0];
	  pl_0_i = static_cast<viscr_int32> (temp_float_for_misra); //(corr_scale_f * corr->u0);  //Q.CORR_LOG2
      temp_float_for_misra = corr_scale_f * pl.data[1];
	  pl_1_i = static_cast<viscr_int32> (temp_float_for_misra); //(corr_scale_f * corr->v0);  //Q.CORR_LOG2
      temp_float_for_misra = corr_scale_f * pl.data[2];
	  pl_2_i = static_cast<viscr_int32> (temp_float_for_misra); //(corr_scale_f);             //Q.CORR_LOG2
      temp_float_for_misra = corr_scale_f * pr.data[0];
	  pr_0_i = static_cast<viscr_int32> (temp_float_for_misra); //(corr_scale_f * corr->u1);  //Q.CORR_LOG2
      temp_float_for_misra = corr_scale_f * pr.data[1];
	  pr_1_i = static_cast<viscr_int32> (temp_float_for_misra); //(corr_scale_f * corr->v1);  //Q.CORR_LOG2
      temp_float_for_misra = corr_scale_f * pr.data[2];
	  pr_2_i = static_cast<viscr_int32> (temp_float_for_misra); //(corr_scale_f);             //Q.CORR_LOG2

      pfloat_for_misra = phi.data;

      temp_float_for_misra = *pfloat_for_misra * angle_scale_f;
	  phi_2_i = static_cast<viscr_int32> (temp_float_for_misra);   //Q.ANGLE_LOG2
      pfloat_for_misra++;
      temp_float_for_misra = *pfloat_for_misra * angle_scale_f;
	  phi_0_i = static_cast<viscr_int32> (temp_float_for_misra);   //Q.ANGLE_LOG2
      temp_float_for_misra = angle_scale_f * data->yaw;
	  phi_1_i = static_cast<viscr_int32> (temp_float_for_misra);//Q.ANGLE_LOG2

    int64_0_for_misra = static_cast<viscr_int64>(phi_0_i)*(static_cast<viscr_int64>(phi_0_i)/2);
    uint64_for_misra = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
    cos_0_i = 0 - static_cast<viscr_int32>(uint64_for_misra & 0xFFFFFFFF);
    int64_0_for_misra = static_cast<viscr_int64>(phi_1_i)*(static_cast<viscr_int64>(phi_1_i)/2);
    uint64_for_misra = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
    cos_1_i = 0 - static_cast<viscr_int32>(uint64_for_misra & 0xFFFFFFFF);
    int64_0_for_misra = static_cast<viscr_int64>(phi_2_i)*(static_cast<viscr_int64>(phi_2_i)/2);
    uint64_for_misra = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
    cos_2_i = 0 - static_cast<viscr_int32>(uint64_for_misra & 0xFFFFFFFF);

	  sin_0_i = phi_0_i;  //sa TODO eventually improving by x^3/6 term
	  sin_1_i = phi_1_i;  //sb
	  sin_2_i = phi_2_i;  //sg

	  int64_0_for_misra = static_cast<viscr_int64>(sin_0_i) * sin_1_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> (ANGLE_LOG2);
	  viscr_int32 sa_sb_i = static_cast<viscr_int32>(uint64_for_misra & 0xFFFFFFFF);

// ~CodeReview ~ID:29cbd7ea9e303211ad915e57b0ef7418 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  viscr_int32 sa_sb_i = static_cast<viscr_int32>(( static_cast<viscr_int64>(sin_0_i) * sin_1_i)>> ANGLE_LOG2);   //Q.ANGLE_LOG2

	  //R.m( 0, 0) = ca*cb;
	  int64_0_for_misra = static_cast<viscr_int64>(cos_0_i) * cos_1_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> (ANGLE_LOG2-3);
	  int64_0_for_misra = static_cast<viscr_int64>(uint64_for_misra);
      int32_for_misra   = cos_0_i+cos_1_i;
      uint32_for_misra  = static_cast<viscr_uint32>(int32_for_misra) << 3;
	  int64_0_for_misra = int64_0_for_misra - static_cast<viscr_int64>(uint32_for_misra);
      Rt_I_00_i = static_cast<viscr_int32>(int64_0_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:92604947874ad9929260d6e0d753d1f7 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  Rt_I_00_i = static_cast<viscr_int32>(((static_cast<viscr_int64>(cos_0_i) * cos_1_i)>> (ANGLE_LOG2-3))  - ((cos_0_i + cos_1_i)<<3)); // = 1-Rt(0,0) - 1, Q.ANGLE_LOG2+3
	  //R.m( 1, 1) = sa*sb*sg + ca*cg;
	  int64_0_for_misra = static_cast<viscr_int64>(sa_sb_i) * sin_2_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> (ANGLE_LOG2-3);
	  int64_0_for_misra = static_cast<viscr_int64>(uint64_for_misra);
	  int64_1_for_misra = static_cast<viscr_int64>(cos_0_i) * cos_2_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_1_for_misra) >> (ANGLE_LOG2-3);
	  int64_0_for_misra = int64_0_for_misra + static_cast<viscr_int64>(uint64_for_misra);
      int32_for_misra   = cos_0_i+cos_2_i;
      uint32_for_misra  = static_cast<viscr_uint32>(int32_for_misra) << 3;
	  int64_0_for_misra = int64_0_for_misra - static_cast<viscr_int64>(uint32_for_misra);
      Rt_I_11_i = static_cast<viscr_int32>(int64_0_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:107d733f59c3edecfcd5e431654daf92 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  Rt_I_11_i =   static_cast<viscr_int32>(((static_cast<viscr_int64>(sa_sb_i)*sin_2_i)>>(ANGLE_LOG2-3)) + ((static_cast<viscr_int64>(cos_0_i) * cos_2_i)>> (ANGLE_LOG2-3))  - ((cos_0_i+cos_2_i)<<3)); //=1-Rt(1,1,  Q.ANGLE_LOG2+3
	  //R.m( 2, 2) = cb*cg;
	  int64_0_for_misra = static_cast<viscr_int64>(cos_1_i) * cos_2_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> (ANGLE_LOG2-3);
      int32_for_misra   = cos_1_i + cos_2_i;
      uint32_for_misra  = static_cast<viscr_uint32>(int32_for_misra) << 3;
      int64_0_for_misra = static_cast<viscr_int64>(uint64_for_misra) - static_cast<viscr_int64>(uint32_for_misra);
      Rt_I_22_i = static_cast<viscr_int32>(int64_0_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:89bc1af954d80bc09938aeae757d16ea ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  Rt_I_22_i = static_cast<viscr_int32>(((static_cast<viscr_int64>(cos_1_i) * cos_2_i)>> (ANGLE_LOG2-3))  - (( cos_1_i + cos_2_i)<<3)); // = 1-Rt(2,2) - 1,  //Q.ANGLE_LOG2+3

	  cos_0_i = static_cast<viscr_int32>((static_cast<viscr_uint32>(1U)<<ANGLE_LOG2)) +  cos_0_i; // ca, Q.ANGLE_LOG2  
	  cos_1_i = static_cast<viscr_int32>((static_cast<viscr_uint32>(1U)<<ANGLE_LOG2)) +  cos_1_i; // cb, Q.ANGLE_LOG2
	  cos_2_i = static_cast<viscr_int32>(static_cast<viscr_uint32>(1U)<<ANGLE_LOG2) +  cos_2_i; // cg, Q.ANGLE_LOG2

	  int64_0_for_misra = static_cast<viscr_int64>(cos_0_i) * sin_1_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
	  viscr_int32 ca_sb_i = static_cast<viscr_int32>(uint64_for_misra & 0xFFFFFFFF);  //Q.ANGLE_LOG2
// ~CodeReview ~ID:c867967146a51702d1979aa37248162a ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  viscr_int32 ca_sb_i = static_cast<viscr_int32>(( (viscr_int64) cos_0_i * sin_1_i)>> ANGLE_LOG2);  //Q.ANGLE_LOG2

	  //R.m( 1, 0) = sa*cb;
	  int64_0_for_misra = static_cast<viscr_int64>(sin_0_i) * cos_1_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
	  Rt_01_i = static_cast<viscr_int64>(uint64_for_misra);
// ~CodeReview ~ID:beb8c3398fe857869ec5b7b583fb0c1a ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  Rt_01_i =  (static_cast<viscr_int64>(sin_0_i) * cos_1_i)>>ANGLE_LOG2;  //Q.ANGLE_LOG2
	  //R.m( 2, 0) = -sb;
	  Rt_02_i = -static_cast<viscr_int64>(sin_1_i);     //Q.ANGLE_LOG2
   // ~CodeReview ~ID:8bc13c5b40e34c03569bd1d4c2aa1a40 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
	  //R.m( 0, 1) = ca*sb*sg - sa*cg;

	  int64_0_for_misra = static_cast<viscr_int64>(ca_sb_i) * sin_2_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
      int64_0_for_misra = static_cast<viscr_int64>(uint64_for_misra);
	  int64_1_for_misra = static_cast<viscr_int64>(sin_0_i) * cos_2_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_1_for_misra) >> ANGLE_LOG2;
	  Rt_10_i = int64_0_for_misra - static_cast<viscr_int64>(uint64_for_misra);
// ~CodeReview ~ID:1d3d7135baca20b07eaeba7514e6d8cd ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  Rt_10_i = ((static_cast<viscr_int64>(ca_sb_i)*sin_2_i)>> ANGLE_LOG2) -  ((static_cast<viscr_int64>(sin_0_i) * cos_2_i) >> ANGLE_LOG2); //Q.ANGLE_LOG2
	  //R.m( 2, 1) = cb*sg;
	  int64_0_for_misra = static_cast<viscr_int64>(cos_1_i) * sin_2_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
	  Rt_12_i = static_cast<viscr_int64>(uint64_for_misra);
// ~CodeReview ~ID:c6831d3fa328563d3654654b2c028339 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  Rt_12_i = (static_cast<viscr_int64>(cos_1_i) * sin_2_i)>> ANGLE_LOG2; //Q.ANGLE_LOG2
	  //R.m( 0, 2) = ca*sb*cg + sa*sg;
	  int64_0_for_misra = static_cast<viscr_int64>(ca_sb_i) * cos_2_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
      int64_0_for_misra = static_cast<viscr_int64>(uint64_for_misra);
	  int64_1_for_misra = static_cast<viscr_int64>(sin_0_i) * sin_2_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_1_for_misra) >> ANGLE_LOG2;
	  Rt_20_i = int64_0_for_misra + static_cast<viscr_int64>(uint64_for_misra);
// ~CodeReview ~ID:34dbfdaa0c06e9381c4a89176f5ce9aa ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  Rt_20_i = ((static_cast<viscr_int64>(ca_sb_i) * cos_2_i)>> ANGLE_LOG2) + ((static_cast<viscr_int64>(sin_0_i) * sin_2_i)>>ANGLE_LOG2); //Q.ANGLE_LOG2
	  //R.m( 1, 2) = sa*sb*cg - ca*sg;
	  int64_0_for_misra = static_cast<viscr_int64>(sa_sb_i) * cos_2_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
      int64_0_for_misra = static_cast<viscr_int64>(uint64_for_misra);
	  int64_1_for_misra = static_cast<viscr_int64>(cos_0_i) * sin_2_i;
      uint64_for_misra  = static_cast<viscr_uint64>(int64_1_for_misra) >> ANGLE_LOG2;
	  Rt_21_i = int64_0_for_misra - static_cast<viscr_int64>(uint64_for_misra);
// ~CodeReview ~ID:473e62db91ab3dd3bcfcb1ee4aa94559 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  Rt_21_i = ((static_cast<viscr_int64>(sa_sb_i) * cos_2_i)>>ANGLE_LOG2) - ((static_cast<viscr_int64>(cos_0_i)*sin_2_i)>>ANGLE_LOG2); //Q.ANGLE_LOG2

	  //Txmat_00_i = (viscr_int32) (corr_scale_f * data->Tx.m.data[0]); //Q.CORR_LOG2
	  pfloat_for_misra = data->Tx.m.data;
	  pfloat_for_misra++;
	  Txmat_01_i = static_cast<viscr_int32>(*pfloat_for_misra); //Q.CORR_LOG2
	  pfloat_for_misra++;
	  Txmat_02_i = static_cast<viscr_int32>(*pfloat_for_misra); //Q.CORR_LOG2
	  pfloat_for_misra++;
	  Txmat_10_i = static_cast<viscr_int32>(*pfloat_for_misra); //Q.CORR_LOG2
	  pfloat_for_misra++;
	  //Txmat_11_i = (viscr_int32) (corr_scale_f * data->Tx.m.data[4]); //Q.CORR_LOG2
	  pfloat_for_misra++;
	  Txmat_I_12_i = static_cast<viscr_int32>(*pfloat_for_misra); //(1.0+data->Tx.m.data[5])); // -1+ Txmat(1,2), //Q.CORR_LOG2
	  pfloat_for_misra++;
	  Txmat_20_i = static_cast<viscr_int32>(*pfloat_for_misra);       //Q.CORR_LOG2
	  pfloat_for_misra++;
	  Txmat_I_21_i = static_cast<viscr_int32>(*pfloat_for_misra); //(1.0-data->Tx.m.data[7])); // 1-Txmat(2,1), //Q.CORR_LOG2
   // ~CodeReview ~ID:1d9df5dab80a2fbc416774128ee3d0a3 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
	  //Txmat_22_i = (viscr_int32) (corr_scale_f * data->Tx.m.data[8]);  //Q.CORR_LOG2

    int64_0_for_misra = (static_cast<viscr_int64>(Txmat_01_i) * Rt_10_i);
    int64_0_for_misra = int64_0_for_misra + (static_cast<viscr_int64>(Txmat_02_i) * Rt_20_i);
    uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
    E_00_i = static_cast<viscr_int32>(uint64_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:304cd4aa2b29ea43073ecef6925b0ffe ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  E_00_i = static_cast<viscr_int32>(( (static_cast<viscr_int64> (Txmat_01_i) * Rt_10_i) + (static_cast<viscr_int64> (Txmat_02_i) * Rt_20_i))>>ANGLE_LOG2); //Q.CORR_LOG2

    int64_0_for_misra = static_cast<viscr_int64>(Txmat_02_i) * Rt_21_i;
    uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
    int64_0_for_misra = static_cast<viscr_int64>(uint64_for_misra);
    int64_1_for_misra = static_cast<viscr_int64>(Txmat_01_i) * Rt_I_11_i;
    uint64_for_misra  = static_cast<viscr_uint64>(int64_1_for_misra) >> 3;
    int64_0_for_misra = int64_0_for_misra - static_cast<viscr_int64>(uint64_for_misra);
    E_01_i = Txmat_01_i + static_cast<viscr_int32>(int64_0_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:7b310fd4e74350971edf71d14feda768 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  E_01_i = static_cast<viscr_int32>(Txmat_01_i + ( - ((static_cast<viscr_int64> (Txmat_01_i) * Rt_I_11_i)>>3) + (static_cast<viscr_int64> (Txmat_02_i) * Rt_21_i)>>ANGLE_LOG2)); //Q.CORR_LOG2

    int64_0_for_misra = static_cast<viscr_int64>(Txmat_02_i) * Rt_I_22_i;
    uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> 3;
    uint64_for_misra  = uint64_for_misra >> ANGLE_LOG2;
    int64_0_for_misra = (static_cast<viscr_int64> (Txmat_01_i) * Rt_12_i) - static_cast<viscr_int64> (uint64_for_misra);
    E_02_i = Txmat_02_i + static_cast<viscr_int32>(int64_0_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:23eff2d16e48f93f6f5b28a86ed6169d ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  E_02_i = static_cast<viscr_int32>(Txmat_02_i + ( + (static_cast<viscr_int64> (Txmat_01_i) * Rt_12_i) - ((static_cast<viscr_int64> (Txmat_02_i) * Rt_I_22_i)>>3)>>ANGLE_LOG2)); //Q.CORR_LOG2

    int64_0_for_misra = static_cast<viscr_int64>(Txmat_10_i) * Rt_I_00_i;
    uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> 3;
    int64_0_for_misra = static_cast<viscr_int64>(uint64_for_misra);
    uint64_for_misra  = static_cast<viscr_uint64>(Rt_20_i) <<  CORR_LOG2;
    int64_0_for_misra = int64_0_for_misra + static_cast<viscr_int64>(uint64_for_misra);
    int64_0_for_misra = (static_cast<viscr_int64>(Txmat_I_12_i) * Rt_20_i) - int64_0_for_misra;
    uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
    E_10_i = Txmat_10_i + static_cast<viscr_int32>(uint64_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:aff8163f2693fa735a94bf8222412355 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  E_10_i = static_cast<viscr_int32>(Txmat_10_i + (( - ((static_cast<viscr_int64> (Txmat_10_i) * Rt_I_00_i)>>3) - (Rt_20_i<<CORR_LOG2) + (static_cast<viscr_int64>(Txmat_I_12_i) * Rt_20_i))>>ANGLE_LOG2)); //Q.CORR_LOG2

    // ~CodeReview ~ID:036c3f3c2afed70f127da4922b276ee1 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
    //YME: Suspicious cast: le résultat, qui est calculé dans un viscr_int64, est plus grand qu'un viscr_int32
    //     Le cast final tronque des bits
    /* <ln_offset:4 MISRA Rule 5-0-21: reviewer name: Yannick Mescam date: 06.04.2012 reason: signed/unsigned shift mismatch*/
    /* <ln_offset:3 MISRA Rule 5-0-21: reviewer name: Yannick Mescam date: 06.04.2012 reason: signed/unsigned shift mismatch*/
    /* <ln_offset:2 PCLINT Error 504: reviewer name: Yannick Mescam date: 18.04.2012 reason: Unusual shift */
    /* <ln_offset:1 MISRA Rule 5-0-2: reviewer name: Garcia Lucien date: 31.05.2012 reason: Unusual shift */
    E_11_i = static_cast<viscr_int32>(( (static_cast<viscr_int64> (Txmat_10_i) * Rt_01_i) - (Rt_21_i<<CORR_LOG2)+ (static_cast<viscr_int64>(Txmat_I_12_i) * Rt_21_i)>>ANGLE_LOG2)); //Q.CORR_LOG2

    // ~CodeReview ~ID:689ffc448204f0ed0f959138694d3121 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
    //YME: Suspicious shift: Rt_I_22_i est un int32, mais on le décale de 27 bits vers la gauche => on perd des bits
    /* <ln_offset:7 PCLINT Error 647: reviewer name: Yannick Mescam date: 18.04.2012 reason: Suspicious truncation */
    /* <ln_offset:6 MISRA Rule 5-0-10: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
    /* <ln_offset:5 MISRA Rule 5-19-1: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
    /* <ln_offset:4 MISRA Rule 5-0-2: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
    /* <ln_offset:3 MISRA Rule 5-0-21: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
    /* <ln_offset:2 MISRA Rule 5-0-3: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
    /* <ln_offset:1 MISRA Rule 5-0-4: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
    E_12_i = static_cast<viscr_int32>(((-1)*(1U<<CORR_LOG2) + Txmat_I_12_i + ((static_cast<viscr_int64> (Txmat_10_i) * Rt_02_i + (Rt_I_22_i<<(CORR_LOG2-3)) - ((static_cast<viscr_int64>(Txmat_I_12_i) * Rt_I_22_i)>>3))  >>ANGLE_LOG2))); //Q.CORR_LOG2

    int64_0_for_misra = static_cast<viscr_int64>(Txmat_20_i) * Rt_I_00_i;
    uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> 3;
    int64_0_for_misra = - static_cast<viscr_int64>(uint64_for_misra);
	  uint64_for_misra  = static_cast<viscr_uint64>(Rt_10_i)<<CORR_LOG2;
    // ~CodeReview ~ID:7a62b31076143716d7025f465706c53d ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
    int64_0_for_misra = (int64_0_for_misra + static_cast<viscr_int64>(uint64_for_misra)) - (static_cast<viscr_int64>(Txmat_I_21_i) * Rt_10_i);
  	uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >>ANGLE_LOG2;
    E_20_i = Txmat_20_i + static_cast<viscr_int32>(uint64_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:ec5f5d677d9d17c789907082c5fabed9 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  E_20_i = static_cast<viscr_int32>(Txmat_20_i + (((viscr_int64) - ((static_cast<viscr_int64>(Txmat_20_i) * Rt_I_00_i)>>3) + (Rt_10_i<<CORR_LOG2) - (static_cast<viscr_int64>(Txmat_I_21_i) * Rt_10_i) )   >>ANGLE_LOG2)); //Q.CORR_LOG2

   // ~CodeReview ~ID:5d30e9e987a5c97d95e742603183f88c ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split complicated calculation into multile steps for better code readability
    //YME: Suspicious shift: Rt_I_11_i est un int32, mais on le décale de 27 bits vers la gauche => on perd des bits
    /* <ln_offset:6 MISRA Rule 5-0-3: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
    /* <ln_offset:5 MISRA Rule 5-0-4: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
    /* <ln_offset:4 MISRA Rule 5-0-21: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
    /* <ln_offset:3 MISRA Rule 5-0-10: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
    /* <ln_offset:2 PCLINT Error 647: reviewer name: Yannick Mescam date: 18.04.2012 reason: Suspicious truncation */
    /* <ln_offset:1 MISRA Rule 5-0-2: reviewer name: Garcia Lucien date: 31.05.2012 reason: Suspicious truncation */
	  E_21_i = static_cast<viscr_int32>((1U<<CORR_LOG2) - Txmat_I_21_i + (( static_cast<viscr_int64>(Txmat_20_i) * Rt_01_i - (Rt_I_11_i<<(CORR_LOG2-3)) + (static_cast<viscr_int64>(Txmat_I_21_i) * Rt_I_11_i) )   >>ANGLE_LOG2)); //Q.CORR_LOG2
	  
    uint64_for_misra  = static_cast<viscr_uint64>(Rt_12_i) << CORR_LOG2;
   // ~CodeReview ~ID:5699be478a10cf2c977df40f457483c2 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
	  int64_0_for_misra = ((static_cast<viscr_int64> (Txmat_20_i) * Rt_02_i) + static_cast<viscr_int64>(uint64_for_misra)) - (static_cast<viscr_int64> (Txmat_I_21_i) * Rt_12_i);
    uint64_for_misra  = static_cast<viscr_uint64>(int64_0_for_misra) >> ANGLE_LOG2;
    E_22_i = static_cast<viscr_int32>(uint64_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:3de5dfe6dfe36bf43114eebd1c14d55f ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  E_22_i = static_cast<viscr_int32>((( (static_cast<viscr_int64> (Txmat_20_i) * Rt_02_i) + (Rt_12_i<<CORR_LOG2) - (static_cast<viscr_int64> (Txmat_I_21_i) * Rt_12_i) )    >>ANGLE_LOG2)); //Q.CORR_LOG2

	  int64_0_for_misra = static_cast<viscr_int64>(E_00_i) * pr_0_i;
	  int64_1_for_misra = static_cast<viscr_int64>(E_01_i) * pr_1_i;
	  int64_2_for_misra = static_cast<viscr_int64>(E_02_i) * pr_2_i;
   // ~CodeReview ~ID:77e470fc17be4d209795f8dc23d53c83 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
	  uint64_sum_for_misra = (static_cast<viscr_uint64>(int64_0_for_misra) >> CORR_LOG2) + ((static_cast<viscr_uint64>(int64_1_for_misra) >> CORR_LOG2) + (static_cast<viscr_uint64>(int64_2_for_misra) >> CORR_LOG2));
      viscr_int32 nl_0_i = static_cast<viscr_int32>(uint64_sum_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:069ac0ebc9ff8ea7065cbf92eab822d7 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  viscr_int32 nl_0_i = static_cast<viscr_int32>(((static_cast<viscr_int64> (E_00_i) * pr_0_i) >> CORR_LOG2) + ((static_cast<viscr_int64> (E_01_i) * pr_1_i )>> CORR_LOG2) + ((static_cast<viscr_int64> (E_02_i) * pr_2_i) >> CORR_LOG2));  //Q.CORR_LOG2

	  int64_0_for_misra = static_cast<viscr_int64>(E_10_i) * pr_0_i;
	  int64_1_for_misra = static_cast<viscr_int64>(E_11_i) * pr_1_i;
	  int64_2_for_misra = static_cast<viscr_int64>(E_12_i) * pr_2_i;
   // ~CodeReview ~ID:d46361df2541aba627a6f41a50568b31 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
	  uint64_sum_for_misra = (static_cast<viscr_uint64>(int64_0_for_misra) >> CORR_LOG2) + ((static_cast<viscr_uint64>(int64_1_for_misra) >> CORR_LOG2) + (static_cast<viscr_uint64>(int64_2_for_misra) >> CORR_LOG2));
      viscr_int32 nl_1_i = static_cast<viscr_int32>(uint64_sum_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:3651b8c44135e7984cda921f591da44c ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  viscr_int32 nl_1_i = static_cast<viscr_int32>(((static_cast<viscr_int64> (E_10_i) * pr_0_i) >> CORR_LOG2) + ((static_cast<viscr_int64> (E_11_i) * pr_1_i )>> CORR_LOG2) + ((static_cast<viscr_int64> (E_12_i) * pr_2_i) >> CORR_LOG2));  //Q.CORR_LOG2

	  int64_0_for_misra = static_cast<viscr_int64>(E_20_i) * pr_0_i;
	  int64_1_for_misra = static_cast<viscr_int64>(E_21_i) * pr_1_i;
	  int64_2_for_misra = static_cast<viscr_int64>(E_22_i) * pr_2_i;
   // ~CodeReview ~ID:60366148d9820bcbc6d991aca5def1bf ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
	  uint64_sum_for_misra = (static_cast<viscr_uint64>(int64_0_for_misra) >> CORR_LOG2) + ((static_cast<viscr_uint64>(int64_1_for_misra) >> CORR_LOG2) + (static_cast<viscr_uint64>(int64_2_for_misra) >> CORR_LOG2));
      viscr_int32 nl_2_i = static_cast<viscr_int32>(uint64_sum_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:c463aa4a9543db8c8c1c029f5666a86c ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  viscr_int32 nl_2_i = static_cast<viscr_int32>(((static_cast<viscr_int64> (E_20_i) * pr_0_i) >> CORR_LOG2) + ((static_cast<viscr_int64> (E_21_i) * pr_1_i )>> CORR_LOG2) + ((static_cast<viscr_int64> (E_22_i) * pr_2_i) >> CORR_LOG2));  //Q.CORR_LOG2

	  int64_0_for_misra = static_cast<viscr_int64>(E_00_i) * pl_0_i;
	  int64_1_for_misra = static_cast<viscr_int64>(E_10_i) * pl_1_i;
	  int64_2_for_misra = static_cast<viscr_int64>(E_20_i) * pl_2_i;
   // ~CodeReview ~ID:70a27a11617d965e6ca58e933b6a547e ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
	  uint64_sum_for_misra = (static_cast<viscr_uint64>(int64_0_for_misra) >> CORR_LOG2) + ((static_cast<viscr_uint64>(int64_1_for_misra) >> CORR_LOG2) + (static_cast<viscr_uint64>(int64_2_for_misra) >> CORR_LOG2));
      viscr_int32 nr_0_i = static_cast<viscr_int32>(uint64_sum_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:aec25429c5d0877e20db13a4bd43e9b9 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  viscr_int32 nr_0_i = static_cast<viscr_int32>(((static_cast<viscr_int64> (E_00_i) * pl_0_i) >> CORR_LOG2) + ((static_cast<viscr_int64> (E_10_i) * pl_1_i )>> CORR_LOG2) + ((static_cast<viscr_int64> (E_20_i) * pl_2_i) >> CORR_LOG2));  //Q.CORR_LOG2

	  int64_0_for_misra = static_cast<viscr_int64>(E_01_i) * pl_0_i;
	  int64_1_for_misra = static_cast<viscr_int64>(E_11_i) * pl_1_i;
	  int64_2_for_misra = static_cast<viscr_int64>(E_21_i) * pl_2_i;
   // ~CodeReview ~ID:3db3814e2733fdb5b6adb529aefb35ea ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
	  uint64_sum_for_misra = (static_cast<viscr_uint64>(int64_0_for_misra) >> CORR_LOG2) + ((static_cast<viscr_uint64>(int64_1_for_misra) >> CORR_LOG2) + (static_cast<viscr_uint64>(int64_2_for_misra) >> CORR_LOG2));
      viscr_int32 nr_1_i = static_cast<viscr_int32>(uint64_sum_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:650ace271c3b9e34349aa7e97b906f95 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  viscr_int32 nr_1_i = static_cast<viscr_int32>(((static_cast<viscr_int64> (E_01_i) * pl_0_i) >> CORR_LOG2) + ((static_cast<viscr_int64> (E_11_i) * pl_1_i )>> CORR_LOG2) + ((static_cast<viscr_int64> (E_21_i) * pl_2_i) >> CORR_LOG2));  //Q.CORR_LOG2

	  int64_0_for_misra = static_cast<viscr_int64>(E_02_i) * pl_0_i;
	  int64_1_for_misra = static_cast<viscr_int64>(E_12_i) * pl_1_i;
	  int64_2_for_misra = static_cast<viscr_int64>(E_22_i) * pl_2_i;
   // ~CodeReview ~ID:13df6acb20b7f6fddd99587df1738344 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
	  uint64_sum_for_misra = (static_cast<viscr_uint64>(int64_0_for_misra) >> CORR_LOG2) + ((static_cast<viscr_uint64>(int64_1_for_misra) >> CORR_LOG2) + (static_cast<viscr_uint64>(int64_2_for_misra) >> CORR_LOG2));
      viscr_int32 nr_2_i = static_cast<viscr_int32>(uint64_sum_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:1f7fb503fd6b8f46a6f9db02f249be59 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
// 	  viscr_int32 nr_2_i = static_cast<viscr_int32>(((static_cast<viscr_int64> (E_02_i) * pl_0_i) >> CORR_LOG2) + ((static_cast<viscr_int64> (E_12_i) * pl_1_i )>> CORR_LOG2) + ((static_cast<viscr_int64> (E_22_i) * pl_2_i) >> CORR_LOG2));  //Q.CORR_LOG2


	  //viscr_int32 ll_i = ((static_cast<viscr_int64>(nl_0_i) * nl_0_i) >> CORR_LOG2)  + ((static_cast<viscr_int64>(nl_1_i) * nl_1_i)>>CORR_LOG2) - (1U<<CORR_LOG2); 
	  //viscr_int32 lr_i = ((static_cast<viscr_int64>(nr_0_i) * nr_0_i) >> CORR_LOG2)  + ((static_cast<viscr_int64>(nr_1_i) * nr_1_i)>>CORR_LOG2) - (1U<<CORR_LOG2);

	  //viscr_int32 ll_1_i =  -(ll_i >> 1) + ((static_cast<viscr_int64>(ll_i) *ll_i)>>(CORR_LOG2+3));  // 1-sqrt(x) ~= (1/2)*x-(1/8)*x^2, Q.CORR_LOG2
	  //viscr_int32 lr_1_i =  -(lr_i >> 1) + ((static_cast<viscr_int64>(lr_i) *lr_i)>>(CORR_LOG2+3));  // 1-sqrt(x) ~= (1/2)*x-(1/8)*x^2, Q.CORR_LOG2


	  int64_0_for_misra = static_cast<viscr_int64>(pl_0_i) * nl_0_i;
	  int64_1_for_misra = static_cast<viscr_int64>(pl_1_i) * nl_1_i;
	  int64_2_for_misra = static_cast<viscr_int64>(pl_2_i) * nl_2_i;
   // ~CodeReview ~ID:bb05e17cac5bc756b9c026bd62b7ddee ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
	  uint64_sum_for_misra = (static_cast<viscr_uint64>(int64_0_for_misra) >> CORR_LOG2) + ((static_cast<viscr_uint64>(int64_1_for_misra) >> CORR_LOG2) + (static_cast<viscr_uint64>(int64_2_for_misra) >> CORR_LOG2));
      viscr_int32 pl_dot_nl_i = static_cast<viscr_int32>(uint64_sum_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:ef6109f42b4dd2632837cbc84c1be2e2 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  viscr_int32 pl_dot_nl_i = static_cast<viscr_int32>((static_cast<viscr_int32>((static_cast<viscr_int64>(pl_0_i) * nl_0_i) >> CORR_LOG2) + ((static_cast<viscr_int64>(pl_1_i) * nl_1_i) >> CORR_LOG2) + ((static_cast<viscr_int64>(pl_2_i) * nl_2_i) >> CORR_LOG2)));// /(ll_i>>den_shift); //Q.CORR_LOG2

	  int64_0_for_misra = static_cast<viscr_int64>(pr_0_i) * nr_0_i;
	  int64_1_for_misra = static_cast<viscr_int64>(pr_1_i) * nr_1_i;
	  int64_2_for_misra = static_cast<viscr_int64>(pr_2_i) * nr_2_i;
   // ~CodeReview ~ID:14c27a56a8fe9fae83a36ee02da7ae31 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Split up ambiguous and complicated statement into multiple more comprehensible ones
	  uint64_sum_for_misra = (static_cast<viscr_uint64>(int64_0_for_misra) >> CORR_LOG2) + ((static_cast<viscr_uint64>(int64_1_for_misra) >> CORR_LOG2) + (static_cast<viscr_uint64>(int64_2_for_misra) >> CORR_LOG2));
      viscr_int32 pr_dot_nr_i = static_cast<viscr_int32>(uint64_sum_for_misra & 0xFFFFFFFF);
// ~CodeReview ~ID:fee4e73dab1cda699403ab1cea6bc988 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  viscr_int32 pr_dot_nr_i = static_cast<viscr_int32>((static_cast<viscr_int32>((static_cast<viscr_int64>(pr_0_i) * nr_0_i) >> CORR_LOG2) + ((static_cast<viscr_int64>(pr_1_i) * nr_1_i) >> CORR_LOG2) + ((static_cast<viscr_int64>(pr_2_i) * nr_2_i) >> CORR_LOG2)));// /(lr_i>>den_shift); //Q.CORR_LOG2

	  //viscr_int32 pl_dot_nl_q_i = pl_dot_nl_i + ((pl_dot_nl_i * ll_1_i) >> CORR_LOG2) + ((pl_dot_nl_i * (  (ll_1_i * ll_1_i) >> CORR_LOG2)) >> CORR_LOG2); // ~=pl_dot_nl_i/ll_1_i (Geometric Series)
	  //viscr_int32 pr_dot_nr_q_i = pr_dot_nr_i + ((pr_dot_nr_i * lr_1_i) >> CORR_LOG2) + ((pr_dot_nr_i * (  (lr_1_i * lr_1_i) >> CORR_LOG2)) >> CORR_LOG2); // ~=pl_dot_nl_i/ll_1_i (Geometric Series)

	  viscr_float scale_fp = scale/ (static_cast<viscr_float>(static_cast<ui32_t>(static_cast<ui32_t>(1U) << CORR_LOG2)));

	  viscr_float df_0 = scale_fp * (static_cast<viscr_float>(pl_dot_nl_i));
	  viscr_float df_1 = scale_fp * (static_cast<viscr_float>(pr_dot_nr_i));

	  // Epipolar distances
	  pfloat_for_misra = f.data;
	  *pfloat_for_misra += df_0;
	  pfloat_for_misra++;
	  *pfloat_for_misra += df_1;
	}
 // ~CodeReview ~ID:0ad323dbd5fbc49a842fd633852d861c ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
 // else // original floating point version
	//{
	//	// Compute rotation matrix
	//	viscr_XYZFixedAngles2RotationMatrix( R, phi.data[0], data->yaw, phi.data[1]);

	//	// which has to be transposed due to Hartley and Zissermans notation
	//	viscr_mat_transpose_copy( Rt.m, R.m);

	//	// Essential matrix
	//	viscr_mat_mult_mat( E.m, data->Tx.m, Rt.m);

	//	// Left and right epipolar distance
	//	// Normals of epipolar line in other image
	//	viscr_mat_mult_vec( nl.v, E.m, pr.v);
	//	viscr_mat_mult_vec_left( nr.v, pl.v, E.m);

	//	viscr_float ll=sqrt((nl.data[0]*nl.data[0])+(nl.data[1]*nl.data[1]));
	//	viscr_float lr=sqrt((nr.data[0]*nr.data[0])+(nr.data[1]*nr.data[1]));

	//	//DEBUG DEBUG DEBUG
	//	//viscr_float df_00 = scale*viscr_vec_dot(pl.v,nl.v)/ll;   //DEBUG
	//	//viscr_float df_11 = scale*viscr_vec_dot(nr.v,pr.v)/lr;   //DEBUG

	//	// Epipolar distances
	//	f.data[0]+=(scale*viscr_vec_dot(pl.v,nl.v))/ll;
	//	f.data[1]+=(scale*viscr_vec_dot(nr.v,pr.v))/lr;

	//}  // end of original floating point version ( else  of the condition if (fine_flag == 1) 
 

  // ~CodeReview ~ID:56a0d985c76e1ab8f95f50fd12cff3b7 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Various Lint errors for this function not commented (see LINT report)
  }

  /// reactived floating point version of the epipolar_objfun for test purposes
  /// Non-robust objective function for epipolar constraint
  void
    epipolar_objfun_floatingpoint(
    const viscr_vector & phi,
    viscr_vector & f,
    const viscr_float scale,
    const void * const sampleData,
    void * const ud)
  {
    const viscr_SMPC_epipolar_corr * corr=static_cast<const viscr_SMPC_epipolar_corr *>(sampleData);
    viscr_SMPC_epipolar_calib_userdata * data=static_cast<viscr_SMPC_epipolar_calib_userdata*>(ud);

    viscr_mat33 R;
    viscr_mat33 Rt;
    viscr_mat33 E;
    viscr_vec3 nl;viscr_vec3 nr;
    viscr_vec3 pl;viscr_vec3 pr;

    pl.data[0]=corr->u0;
    pl.data[1]=corr->v0;
    pl.data[2]=1.0F;
    pr.data[0]=corr->u1;
    pr.data[1]=corr->v1;
    pr.data[2]=1.0F;

    assert(data->Tx.m.data[0] == 0);
    assert(data->Tx.m.data[4] == 0);
    assert(data->Tx.m.data[8] == 0);


    // Compute rotation matrix
    viscr_XYZFixedAngles2RotationMatrix( R, phi.data[0], data->yaw, phi.data[1]);

    // which has to be transposed due to Hartley and Zissermans notation
    viscr_mat_transpose_copy( Rt.m, R.m);

    // Essential matrix
    viscr_mat_mult_mat( E.m, data->Tx.m, Rt.m);

    // Left and right epipolar distance
    // Normals of epipolar line in other image
    viscr_mat_mult_vec( nl.v, E.m, pr.v);
    viscr_mat_mult_vec_left( nr.v, pl.v, E.m);

    viscr_float ll=sqrt((nl.data[0]*nl.data[0])+(nl.data[1]*nl.data[1]));
    viscr_float lr=sqrt((nr.data[0]*nr.data[0])+(nr.data[1]*nr.data[1]));

    //DEBUG DEBUG DEBUG
    //viscr_float df_00 = scale*viscr_vec_dot(pl.v,nl.v)/ll;   //DEBUG
    //viscr_float df_11 = scale*viscr_vec_dot(nr.v,pr.v)/lr;   //DEBUG

    // Epipolar distances
    f.data[0]+=(scale*viscr_vec_dot(pl.v,nl.v))/ll;
    f.data[1]+=(scale*viscr_vec_dot(nr.v,pr.v))/lr;
  }


/** Objective function interface that calls computes the derivatives point by
 * point.
 */
void
epipolar_derivatives(
    viscr_vector & phi,
    viscr_matrix & JtJ, 
    viscr_vector & Jte, 
    viscr_float & Fx,
    void * const ud)
{
  // cast the global, generic user data to our data structures
  /* <ln_offset:1 MISRA Rule 5-2-8, 5-2-9: reviewer name: Yannick Mescam date: 14.03.2012 reason: want to keep generic usage of this function*/
  viscr_SMPC_epipolar_calib_userdata * data=static_cast<viscr_SMPC_epipolar_calib_userdata*>(ud);
  viscr_uint nPt=data->param->points_per_epipolar_bin * data->param->bins_u * data->param->bins_v;
  for( viscr_uint iPt=0U; iPt<nPt; ++iPt)
  {
    // for each point compute the numerical derivatives, the errors, and the
    // weights from the m-estimator. Update the accumulators (JtJ, Jte) from
    // the weighted derivatives.
    viscr_levmar_num_der_mEst( 

          &epipolar_objfun_floatingpoint, 

          &viscr_SMPC_ramp_mEstimator, 
          1e-3F, 
          phi, 
          JtJ, 
          Jte, 
          Fx, 
          data->delta.v,
          data->smallJ.m,
          data->row.v, 
          /* <ln_offset:6 MISRA Rule 5-2-5: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
          /* <ln_offset:5 MISRA Rule 5-2-4: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
          /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
          /* <ln_offset:3 MISRA Rule 5-2-5: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
          /* <ln_offset:2 MISRA Rule 5-2-9: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
          /* <ln_offset:1 MISRA Rule 5-2-8: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
          (void*)(&data->corr[iPt]), 
          ud, 
          &data->mEstData);
  }
}


/// Prepare and perform the optimisation 
void
viscr_SMPC_epipolar_calibration( 
    viscr_SMPC_data & data, 
    viscr_float & a,
    viscr_float & c,
    viscr_float & rmse_epipolar,
    viscr_float & rmse_improvement,
    const SACCallBackHdlr_t & callBackHandler)
{
  //Rta instrumentation
  if(callBackHandler.pfct_AlgoServiceAddEvent) {
    callBackHandler.pfct_AlgoServiceAddEvent(e_RTA_EVT_AlgoStart, COMP_ID_SAC, 
      RTA_ID_SAC_EPIPOLAR_CALIBRATION, 0xFE);
  }


  viscr_mat22 JtJ;
  viscr_mat22 L;
  viscr_vec2 Jte;
  viscr_vec2 phi;
  viscr_vec2 phi_old;
  viscr_vec2 Jte_old;
  viscr_vec2 delta;
  viscr_float temp_float1_for_misra;
  viscr_float temp_float2_for_misra;
  viscr_float temp_float3_for_misra;
  viscr_float temp_float4_for_misra;

  phi.data[0]=0.0F;
  phi.data[1]=0.0F;

  viscr_SMPC_epipolar_calib_userdata est_rmat_data;

  est_rmat_data.param=&data.param;
  
  est_rmat_data.mEstData.rampMin=data.param.rampme_epipolar.rampMin;
  est_rmat_data.mEstData.rampMax=data.param.rampme_epipolar.rampMax;
  est_rmat_data.mEstData.lowWeight=data.param.rampme_epipolar.lowWeight;

  // Compute the cross-product matrix
  viscr_vec3 T;
  
  

#if (VISCR_EPIPOLAR_CALIBRATION_MODE == 0) 
    est_rmat_data.f=data.calib_k0.f;
    est_rmat_data.mEstData.f=data.calib_k0.f;
    est_rmat_data.yaw=data.current_angles[1];
    viscr_vec_copy( T.v, data.calib_k1.m2c_t.v);
#endif

#if (VISCR_EPIPOLAR_CALIBRATION_MODE == 1) 
    est_rmat_data.f=data.stereo_camera.f;
    est_rmat_data.mEstData.f=data.stereo_camera.f;
    est_rmat_data.yaw=0.0F;
    T.data[0] = data.stereo_camera.b;
    T.data[1] = 0.0F;
    T.data[2] = 0.0F;
#endif




  viscr_vec_normalize( T.v);

  est_rmat_data.Tx.m(0U,0U)=0.0F;
  est_rmat_data.Tx.m(0U,1U)=-T.data[2];
  est_rmat_data.Tx.m(0U,2U)=T.data[1];

  est_rmat_data.Tx.m(1U,0U)=T.data[2];
  est_rmat_data.Tx.m(1U,1U)=0.0F;
  est_rmat_data.Tx.m(1U,2U)=-T.data[0];

  est_rmat_data.Tx.m(2U,0U)=-T.data[1];
  est_rmat_data.Tx.m(2U,1U)=T.data[0];
  est_rmat_data.Tx.m(2U,2U)=0.0F;

  est_rmat_data.corr=&data.binned_epipolar_points[0];

  // setup the parameters for the levenberg-marquardt
  viscr_levmar_param opt_param;

  extern i8_t fine_flag;
  
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Parameter control check. */
  if (fine_flag == 1)
  {
     opt_param.max_iter=1U;
    }
  else
    {
    opt_param.max_iter=20U;
    }

#if (VISCR_EPIPOLAR_CALIBRATION_MODE == 0) 
    phi.data[0] = data.current_angles[0];
    phi.data[1] = data.current_angles[2];
#endif

  viscr_float corr_scale_f = static_cast<viscr_float> (static_cast<ui32_t>(1U)<<CORR_LOG2);

  // ~CodeReview ~ID:d44ddfc1b7e46cac189a335b4cd40bb4 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
	 //Txmat_I_12_i = (viscr_int32) (corr_scale_f * (1.0+data->Tx.m.data[5])); // -1+ Txmat(1,2), //Q.CORR_LOG2
	 //Txmat_20_i = (viscr_int32) (corr_scale_f * data->Tx.m.data[6]);       //Q.CORR_LOG2
	 //Txmat_I_21_i = (viscr_int32) (corr_scale_f * (1.0-data->Tx.m.data[7])); // 1-Txmat(2,1), //Q.CORR_LOG2


  //1-T[x] was added for fixpointing - when using floating point objective function this is to be removed
  //because the complete matrix is zero. This is why the assignment of Tx above is used and not overwritten here
// 	 est_rmat_data.Tx.m(0U,0U)=0.0F;
// 	 est_rmat_data.Tx.m(0U,1U)=-T.data[2]*corr_scale_f;
// 	 est_rmat_data.Tx.m(0U,2U)=T.data[1]*corr_scale_f;
// 
// 	 est_rmat_data.Tx.m(1U,0U)=T.data[2]*corr_scale_f;
// 	 est_rmat_data.Tx.m(1U,1U)=0.0F;
// 	 est_rmat_data.Tx.m(1U,2U)=(1.0F-T.data[0])*corr_scale_f;
// 
// 	 est_rmat_data.Tx.m(2U,0U)=-T.data[1]*corr_scale_f;
// 	 est_rmat_data.Tx.m(2U,1U)=(1.0F-T.data[0])*corr_scale_f;
// 	 est_rmat_data.Tx.m(2U,2U)=0.0F;


 // ~CodeReview ~ID:92844484398ee9cb01c79ad1f6143d98 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
 // }
  /*else
  {
	  est_rmat_data.Tx.m(0U,0U)=0.0F;
	  est_rmat_data.Tx.m(0U,1U)=-T.data[2];
	  est_rmat_data.Tx.m(0U,2U)=T.data[1];

	  est_rmat_data.Tx.m(1U,0U)=T.data[2];
	  est_rmat_data.Tx.m(1U,1U)=0.0F;
	  est_rmat_data.Tx.m(1U,2U)=-T.data[0];

	  est_rmat_data.Tx.m(2U,0U)=-T.data[1];
	  est_rmat_data.Tx.m(2U,1U)=T.data[0];
	  est_rmat_data.Tx.m(2U,2U)=0.0F;

    opt_param.max_iter=20U;
	  phi.data[0]=0.0F;
	  phi.data[1]=0.0F;
  }*/

  SAC::OPTIM::ObjectiveEpipolarCalibration objective(T, est_rmat_data);
  SAC::OPTIM::IterativeOptimizerLevmar<2,2> optimizer(&objective, opt_param);
  optimizer.reset();

  //viscr_levmar( phi.v, 
  //              opt_param, 

  //              &epipolar_derivatives, 
  //              &est_rmat_data, 
  //              JtJ.m, 
  //              Jte.v, 
  //              L.m,
  //              phi_old.v,
  //              Jte_old.v,
  //              delta.v);
  optimizer.iterate();
  optimizer.getCurrentParameters(phi.v);

#if (VISCR_SMPC_QUALITY_MEASUREMENT == 1)
  viscr_uint nPt= data.param.points_per_epipolar_bin * data.param.bins_u * data.param.bins_v;
  f32_t Fx=0.0F;
  ui32_t outlier_cnt = 0U;
  ui32_t inlier_cnt = 0U;
  f32_t mean_abs_u = C_F32_DELTA;


  viscr_vec2 phi_start;
  phi_start.data[0]=0.0F;
  phi_start.data[1]=0.0F;

  f32_t Fx_start=0.0F;
  // ~CodeReview ~ID:a181cf6dcc2770a1559a704ae349dc72 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
  //i32_t outlier_cnt_start = 0;
  f32_t mean_abs_u_start = 0.0F;
  // ~CodeReview ~ID:8f93534220568c4c5a338aebe3d5605b ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
  //f32_t rmse_epipolar_start = 0.0F;
  viscr_vec2 delta_start;

  const viscr_SMPC_epipolar_corr* pcorr_for_misra = est_rmat_data.corr;

  for( viscr_uint iPt=0U; iPt<nPt; ++iPt)
  {
    // original solution
    viscr_vec_zero( delta_start.v);
    /* <ln_offset:6 MISRA Rule 5-2-5: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    /* <ln_offset:5 MISRA Rule 5-2-4: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    /* <ln_offset:3 MISRA Rule 5-2-5: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    /* <ln_offset:2 MISRA Rule 5-2-9: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    /* <ln_offset:1 MISRA Rule 5-2-8: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
	  //epipolar_objfun_floatingpoint(phi_start.v, delta_start.v, 1.0F,  (void*)(&est_rmat_data.corr[iPt])  ,&est_rmat_data);
    objective.objectiveFunction(phi_start.v, delta_start.v, 1.0F,  (void*)(&est_rmat_data.corr[iPt]));

    // final solution
    viscr_vec_zero( delta.v);

    /* <ln_offset:6 MISRA Rule 5-2-5: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    /* <ln_offset:5 MISRA Rule 5-2-4: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    /* <ln_offset:4 MISRA Rule 5-0-15: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    /* <ln_offset:3 MISRA Rule 5-2-5: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    /* <ln_offset:2 MISRA Rule 5-2-9: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    /* <ln_offset:1 MISRA Rule 5-2-8: reviewer name: Yannick Mescam date: 12.03.2012 reason: want to keep generic usage of this function*/
    //epipolar_objfun_floatingpoint(phi.v, delta.v, 1.0F,  (void*)(&est_rmat_data.corr[iPt])  ,&est_rmat_data);
    objective.objectiveFunction(phi_start.v, delta_start.v, 1.0F,  (void*)(&est_rmat_data.corr[iPt]));

    // check if the final solution is inside the measurement noise
    // ~CodeReview ~ID:89e449ee0650fad93c7ab02c6d49e524 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:3 ~Comment:Use defines instead of magic numbers + complex calculation in IF statement
    if (((std::fabsf(delta.data[0])+std::fabsf(delta.data[1])) * (data.stereo_camera.f/2.0F)) > 2.0F) // measurement noise + model error
      {
        outlier_cnt++;
      }
    else 
      {
        // count inliers and calculate RMSE
        inlier_cnt++;
        Fx += (delta.data[0]*delta.data[0]) + (delta.data[1]*delta.data[1]);
        mean_abs_u += std::fabsf(pcorr_for_misra->u0 * data.stereo_camera.f);

        Fx_start += (delta_start.data[0]*delta_start.data[0]) + (delta_start.data[1]*delta_start.data[1]);
        mean_abs_u_start += std::fabsf(pcorr_for_misra->u0 * data.stereo_camera.f);
      }
	pcorr_for_misra++;
  }
  
  // mean of the distribution of the inliers in order to have an idea of the goodness of the data set
  /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Parameter control check for mean calculation. */
  if ((inlier_cnt !=0U) && (fabsf(mean_abs_u) > C_F32_DELTA) && (phi.v.length!=0U) && (fabsf(mean_abs_u_start)>C_F32_DELTA))
    {
      viscr_float temp_float_inverse=1.0F/(static_cast<viscr_float>(phi.v.length) * static_cast<viscr_float>(inlier_cnt)); //helper variable to reduce the number of divisions

      //mean_abs_u = mean_abs_u/static_cast<f32_t>(inlier_cnt);
      mean_abs_u = mean_abs_u*temp_float_inverse*static_cast<viscr_float>(phi.v.length);        //more multiplications, but no division anymore

      /* <ln_offset:+1 COVERAGE reviewer name: Alexander Behrens date: 05.07.2012 reason: Parameter control check for valid mean calculation. */
      if (fabsf(mean_abs_u) > C_F32_DELTA) {
        //temp_float1_for_misra = Fx/(static_cast<f32_t>(phi.v.length) * static_cast<f32_t>(inlier_cnt));
        temp_float1_for_misra = Fx*temp_float_inverse;

        // ~CodeReview ~ID:d0bdc8ef3adad01d91a2da4da14259e0 ~Reviewer:CW01\uidk7517 ~Date:24.06.2012 ~Priority:2 ~Comment:Lint error not commented
        temp_float1_for_misra = sqrtf(temp_float1_for_misra);
        temp_float1_for_misra = temp_float1_for_misra * data.stereo_camera.f;
        temp_float1_for_misra = temp_float1_for_misra * (static_cast<viscr_float>(est_rmat_data.param->size.u)/2.0F);
        temp_float1_for_misra = temp_float1_for_misra / mean_abs_u;
        rmse_epipolar = (static_cast<f32_t>(outlier_cnt)*10.0F) + temp_float1_for_misra;
      }
      else {
        rmse_epipolar = 0.0F;
      }
// ~CodeReview ~ID:1512dae104cd79bea4694c6de8a6155b ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//    rmse_epipolar = outlier_cnt*10.0F + sqrt(Fx  /(phi.v.length * inlier_cnt)) * data.stereo_camera.f * (static_cast<viscr_float>(est_rmat_data.param->size.u)/2.0F) / mean_abs_u;

      // debug information
      //mean_abs_u_start = mean_abs_u_start/inlier_cnt;
      //rmse_epipolar_start = outlier_cnt*10.0F + sqrt(Fx_start  /(phi.v.length * inlier_cnt)) * data.stereo_camera.f * (static_cast<viscr_float>(est_rmat_data.param->size.u)/2.0F) / mean_abs_u_start;
  
      // improvement of the finals solution compared to the original one using only inliers

      //temp_float1_for_misra =  static_cast<viscr_float>(Fx_start)/(static_cast<viscr_float>(phi.v.length) * static_cast<viscr_float>(inlier_cnt));
      temp_float1_for_misra =  static_cast<viscr_float>(Fx_start)*temp_float_inverse;
      temp_float2_for_misra =  sqrtf(temp_float1_for_misra) * data.stereo_camera.f;
      //temp_float3_for_misra =  static_cast<viscr_float>(Fx)/(static_cast<viscr_float>(phi.v.length) * static_cast<viscr_float>(inlier_cnt));
      temp_float3_for_misra =  static_cast<viscr_float>(Fx)*temp_float_inverse;
      temp_float4_for_misra =  sqrtf(temp_float3_for_misra) * data.stereo_camera.f;
      rmse_improvement = temp_float2_for_misra - temp_float4_for_misra;
// ~CodeReview ~ID:47b01a24de1a4c205727d72a66aef91c ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
//	  rmse_improvement = (sqrt(Fx_start  /(phi.v.length * inlier_cnt)) * data.stereo_camera.f) - (sqrt(Fx  /(phi.v.length * inlier_cnt)) * data.stereo_camera.f) ;
    }
  else
    {
      rmse_epipolar = 0.0F;
      rmse_improvement = 0.0F;
    }

#else
  rmse_epipolar = 0.0F;
  rmse_improvement = 0.0F;
#endif


  // return the optimisation values
#if (VISCR_EPIPOLAR_CALIBRATION_MODE == 0) 
  a=phi.data[0];
  c=phi.data[1];
#endif
#if (VISCR_EPIPOLAR_CALIBRATION_MODE == 1)
  viscr_mat33 tmp_mat;
  viscr_mat33 tmp2_mat;
  viscr_mat33 tmp3_mat;
  // ~CodeReview ~ID:c1d23cdb1c1807f1ada80c0710b02a90 ~Reviewer:CW01\uidk7517 ~Date:23.06.2012 ~Priority:3 ~Comment:Remove or document reason for dead code
  // R_raw = transpose(R1)*R_rectified*R0
  viscr_XYZFixedAngles2RotationMatrix(tmp_mat,phi.data[0],0.0F,phi.data[1]);
  viscr_mat_transpose_copy(tmp3_mat.m,data.stereo_camera.R_k1.m);
  viscr_mat_mult_mat(tmp2_mat.m,tmp3_mat.m,tmp_mat.m);
  viscr_mat_mult_mat(tmp_mat.m,tmp2_mat.m,data.stereo_camera.R_k0.m);
  viscr_float b;
  viscr_RotationMatrix2XYZFixedAngles(a,b,c,tmp_mat);
#endif

  //Rta instrumentation
  if(callBackHandler.pfct_AlgoServiceAddEvent) {
    callBackHandler.pfct_AlgoServiceAddEvent(e_RTA_EVT_AlgoEnd, COMP_ID_SAC, 
      RTA_ID_SAC_EPIPOLAR_CALIBRATION, 0xFE);
  }
}


