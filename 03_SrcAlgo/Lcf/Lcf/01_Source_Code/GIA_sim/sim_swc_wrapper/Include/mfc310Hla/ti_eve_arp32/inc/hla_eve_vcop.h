/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve_vcop.h

  DESCRIPTION:            Common vcop definitions

  AUTHOR:                 Matthias Mutschler


  CREATION DATE:          2013-07-12
  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve_vcop.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:47CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:37CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:04CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.2 2014/03/12 18:07:45CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:45 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.1 2013/10/29 17:07:09CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/inc/project.pj
  CHANGES:                Revision 1.2 2013/08/15 14:16:57CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Improved EDMA handling on EVE side
  CHANGES:                --- Added comments ---  uidv7867 [Aug 15, 2013 2:16:57 PM CEST]
  CHANGES:                Change Package : 192116:1 http://mks-psad:7002/im/viewissue?selection=192116
  CHANGES:                Revision 1.1 2013/07/26 17:12:47CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/inc/project.pj
  CHANGES:
**************************************************************************** */

#ifndef HLA_EVE_VCOP_H
#define HLA_EVE_VCOP_H

/* Generic */
#define ELEMSIZE(elem)   (sizeof(*elem))
#define VECTORSIZE(elem) (VCOP_SIMD_WIDTH * ELEMSIZE(elem))

/* LRF */
/* Number of parallel look-up tables, i.e. replicates of LUTs in RAM */
#define VCOP_NUM_PARALLEL_TABLES  (8)
/* Number of index/points which can be looked-up at once.
 * Note that VCOP_NUM_POINTS_PER_TABLE * VCOP_NUM_PARALLEL_TABLES must be 8 (or 4, 2, 1)
 */
#define VCOP_NUM_POINTS_PER_TABLE (1)
/* number of bits that result of feature calculation has to be shifted/truncated.
 * Note! It's less than HLA_ICON_LRF_FIXPOINT_SCALE_LOG2 (23) defined in hla_analysisicon.h
 */
#define VCOP_RF_FIXPOINT_EXPONENT (20)
/* number of positive elements defined in look-up table (note that in LUT are negatvie values as well).
 * Size of this table must be 32-byte aligned: 80 * 4 Bytes = 10 * 32 Bytes -> 320 Bytes
 * (half of it should also be possible because it was not designed for negative values).
 * As we have it interleaved, i.e. 8 times, size of total LUT is 320 * 8 =  2560 Bytes
 */
#define VCOP_NUM_INDEX_TANH_LUT   (40)

#endif /* HLA_EVE_VCOP_H */
