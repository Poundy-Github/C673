/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_dim_input_custom.cpp

  DESCRIPTION:          

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_dim_input_custom.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:57CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:13CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.29 2016/11/17 14:12:37CET Dagli, Goekhan (uidj7850) 
  CHANGES:              + Conversion from V8 (=V6_2) to V9 (=V6_2) (Mitsubishi)
  CHANGES:              Revision 1.28 2016/11/10 14:19:18CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              ARS410HI17 V11 with Toyota Data V7
  CHANGES:              Revision 1.27 2016/11/10 13:01:20CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              ARS410GY18 V8 with Toyota Data V6
  CHANGES:              Revision 1.26 2016/10/27 08:20:24CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              + Conversion from V8 to V11
  CHANGES:              V8 and V11 have the same structure of V6 (EuNCAP18)
  CHANGES:              Revision 1.25 2016/10/06 15:58:42CEST Cretu, Teodora (CretuT) 
  CHANGES:              Adapt RequestPort(V11_2) to ProvidePort (V6)
  CHANGES:              Revision 1.24 2016/09/21 14:36:13CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Version V11_2 for ARS430BW18
  CHANGES:              Revision 1.23 2016/09/14 13:46:13CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              +V11 (Hyundayi)
  CHANGES:              Revision 1.22 2016/08/08 15:35:37CEST Cretu, Teodora (CretuT) 
  CHANGES:              Update for conversion V9 to V9
  CHANGES:              Revision 1.21 2016/07/21 17:12:06CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V9 (same as V6_2) for ARS510
  CHANGES:              Revision 1.20 2016/06/29 12:18:22CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              +V9 (same as V6)
  CHANGES:              Revision 1.19 2016/02/29 14:45:26CET Cretu, Teodora (CretuT) 
  CHANGES:              A new version is added: V7
  CHANGES:              Revision 1.18 2016/02/03 14:34:55CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + V8
  CHANGES:              Revision 1.17 2015/07/15 16:20:19CEST Heintz, Sebastian (uidu6467) 
  CHANGES:              Add Simulation converter for ARS410GY18 project
  CHANGES:              - Added comments -  uidu6467 [Jul 15, 2015 4:20:19 PM CEST]
  CHANGES:              Change Package : 353230:2 http://mks-psad:7002/im/viewissue?selection=353230
  CHANGES:              Revision 1.16 2015/06/19 07:37:10CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Bugfix
  CHANGES:              --- Added comments ---  berndtt1 [Jun 19, 2015 7:41:48 AM CEST]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.15 2015/05/29 13:47:31CEST Diepolder, Thomas (diepoldert) 
  CHANGES:              Updated adapter to enable x-simulation D1/B0 D2/T0
  CHANGES:              --- Added comments ---  diepoldert [May 29, 2015 1:47:32 PM CEST]
  CHANGES:              Change Package : 343338:1 http://mks-psad:7002/im/viewissue?selection=343338
  CHANGES:              Revision 1.14 2015/02/10 14:42:24CET Kaelberer, Stephan (uidu2442) 
  CHANGES:              Fix for init eSigStatus of dim input custom
  CHANGES:              --- Added comments ---  uidu2442 [Feb 10, 2015 2:42:25 PM CET]
  CHANGES:              Change Package : 304664:1 http://mks-psad:7002/im/viewissue?selection=304664
  CHANGES:              Revision 1.13 2014/10/09 16:16:40CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Update for AL_ARS400EN_01.15.01
  CHANGES:              LongCtrlInputV10
  CHANGES:              DimInputCustomV6_2
  CHANGES:              update FCTVehCustomInput
  CHANGES:              --- Added comments ---  berndtt1 [Oct 10, 2014 7:43:23 AM CEST]
  CHANGES:              Change Package : 270187:1 http://mks-psad:7002/im/viewissue?selection=270187
  CHANGES:              Revision 1.12 2014/02/14 14:48:19CET Obst, Christian02 (uidv8774) 
  CHANGES:              fix for same version of request and provide port
  CHANGES:              --- Added comments ---  uidv8774 [Feb 14, 2014 2:48:20 PM CET]
  CHANGES:              Change Package : 205519:1 http://mks-psad:7002/im/viewissue?selection=205519
  CHANGES:              Revision 1.11 2014/01/24 15:35:52CET Obst, Christian02 (uidv8774) 
  CHANGES:              updated Adapter TypeNaming and
  CHANGES:              using "big Adapter" version of HeadInputCustom
  CHANGES:              --- Added comments ---  uidv8774 [Jan 24, 2014 3:35:52 PM CET]
  CHANGES:              Change Package : 215077:1 http://mks-psad:7002/im/viewissue?selection=215077
  CHANGES:              Revision 1.10 2013/10/10 14:16:23CEST Obst, Christian02 (uidv8774) 
  CHANGES:              fix convert data
  CHANGES:              --- Added comments ---  uidv8774 [Oct 10, 2013 2:16:23 PM CEST]
  CHANGES:              Change Package : 194538:5 http://mks-psad:7002/im/viewissue?selection=194538
  CHANGES:              Revision 1.9 2013/09/30 11:14:28CEST Obst, Christian02 (uidv8774) 
  CHANGES:              modified Input Version5
  CHANGES:              --- Added comments ---  uidv8774 [Sep 30, 2013 11:14:29 AM CEST]
  CHANGES:              Change Package : 194538:5 http://mks-psad:7002/im/viewissue?selection=194538
  CHANGES:              Revision 1.8 2013/09/26 09:52:07CEST Obst, Christian02 (uidv8774) 
  CHANGES:              minor fixes
  CHANGES:              --- Added comments ---  uidv8774 [Sep 26, 2013 9:52:08 AM CEST]
  CHANGES:              Change Package : 194538:5 http://mks-psad:7002/im/viewissue?selection=194538
  CHANGES:              Revision 1.7 2013/09/25 09:50:32CEST Obst, Christian02 (uidv8774) 
  CHANGES:              added further adapter support
  CHANGES:              --- Added comments ---  uidv8774 [Sep 25, 2013 9:50:33 AM CEST]
  CHANGES:              Change Package : 194538:5 http://mks-psad:7002/im/viewissue?selection=194538
  CHANGES:              Revision 1.6 2013/09/20 14:01:29CEST Obst, Christian02 (uidv8774) 
  CHANGES:              Added Dim input custom v6 support and cleanup
  CHANGES:              --- Added comments ---  uidv8774 [Sep 20, 2013 2:01:29 PM CEST]
  CHANGES:              Change Package : 194538:5 http://mks-psad:7002/im/viewissue?selection=194538
  CHANGES:              Revision 1.5 2013/05/21 18:04:24CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              --- Added comments ---  ungvaryg [May 21, 2013 6:04:24 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.4 2013/02/15 10:40:14CET Diepolder, Thomas (diepoldert) 
  CHANGES:              Use effective front axle steer angle as addtional custom input for dim (degradation due to multiturn loss)
  CHANGES:              --- Added comments ---  diepoldert [Feb 15, 2013 10:40:14 AM CET]
  CHANGES:              Change Package : 175279:1 http://mks-psad:7002/im/viewissue?selection=175279
  CHANGES:              Revision 1.3 2011/10/17 18:27:25CEST Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Update simulation adapters to handle new rte interfaces
  CHANGES:              Revision 1.2 2011/05/10 14:31:15CEST Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Conversions for newest version of port
  CHANGES:              --- Added comments ---  diepoldert [May 10, 2011 2:31:15 PM CEST]
  CHANGES:              Change Package : 65322:1 http://mks-psad:7002/im/viewissue?selection=65322
  CHANGES:              Revision 1.1 2011/03/02 17:11:18CET Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj
  CHANGES:              Revision 1.1 2011/03/02 13:47:53CET Thomas Diepolder (diepoldert) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_adapter_cfg.h"
#include "sim_conv_dim_input_custom.h"
#include "sim_versioninfo_impl.h"
#include "interfacedriverinput.h"

//
// Main conversion class
//

class CConvDimInputCustom : public CSimConverterBase
//  public CHeadInputCustom
{

  // the list of dependency names used inside by the converter
  /*
  static const char* DEP_NAMES[];
  */
  // Buffer for holding converted data
  DimInputCustomV0::DIMInputCustom_t  m_DimInputCustomV0;
  DimInputCustomV1::DIMInputCustom_t  m_DimInputCustomV1;
  DimInputCustomV2::DIMInputCustom_t  m_DimInputCustomV2;
  DimInputCustomV3::DIMInputCustom_t  m_DimInputCustomV3;
  DimInputCustomV4::DIMInputCustom_t  m_DimInputCustomV4;
  DimInputCustomV5::DIMInputCustom_t  m_DimInputCustomV5;
  DimInputCustomV6::DIMInputCustom_t  m_DimInputCustomV6;
  DimInputCustomV6_2::DIMInputCustom_t  m_DimInputCustomV6_2;
  DimInputCustomV7_GY::DIMInputCustom_t m_DimInputCustomV7_GY;
  DimInputCustomV6::DIMInputCustom_t m_DimInputCustomV9;
  DimInputCustomV11::DIMInputCustom_t m_DimInputCustomV11;
  DimInputCustomV6::DIMInputCustom_t m_DimInputCustomV11_2;

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  void InitDimInputV0(DimInputCustomV0::DIMInputCustom_t &DestDim);
  void InitDimInputV1(DimInputCustomV1::DIMInputCustom_t &DestDim);
  void InitDimInputV2(DimInputCustomV2::DIMInputCustom_t &DestDim);
  void InitDimInputV3(DimInputCustomV3::DIMInputCustom_t &DestDim);
  void InitDimInputV4(DimInputCustomV4::DIMInputCustom_t &DestDim);
  void InitDimInputV5(DimInputCustomV5::DIMInputCustom_t & DestDim);
  void InitDimInputV6(DimInputCustomV6::DIMInputCustom_t & DestDim);
  void InitDimInputV6_2(DimInputCustomV6_2::DIMInputCustom_t & DestDim);
  void InitDimInputV7_GY(DimInputCustomV7_GY::DIMInputCustom_t & DestDim);
  void InitDimInputV8(DimInputCustomV6::DIMInputCustom_t & DestDim);
  void InitDimInputV9(DimInputCustomV6::DIMInputCustom_t & DestDim);
  void InitDimInputV11(DimInputCustomV11::DIMInputCustom_t & DestDim);
  void InitDimInputV11_2(DimInputCustomV6::DIMInputCustom_t & DestDim);

  void ConvertToV0(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV0::DIMInputCustom_t &DestDim);
  void ConvertToV2(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t &DestDim);
  void ConvertToV2(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t &DestDim);
  void ConvertToV2(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t &DestDim);
  void ConvertToV2(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t &DestDim);
  void ConvertToV2(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t &DestDim);
  void ConvertToV2(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t &DestDim);
  void ConvertToV2(const DimInputCustomV7_GY::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t &DestDim);

  void ConvertToV3(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim);
  void ConvertToV3(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim);
  void ConvertToV3(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim);
  void ConvertToV3(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim);
  void ConvertToV3(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim);
  void ConvertToV3(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim);
  void ConvertToV3(const DimInputCustomV7_GY::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim);

  void ConvertToV4(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim);
  void ConvertToV4(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim);
  void ConvertToV4(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim);
  void ConvertToV4(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim);
  void ConvertToV4(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim);
  void ConvertToV4(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim);
  void ConvertToV4(const DimInputCustomV7_GY::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim);

  void ConvertToV5(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim);
  void ConvertToV5(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim);
  void ConvertToV5(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim);
  void ConvertToV5(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim);
  void ConvertToV5(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim);
  void ConvertToV5(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim);
  void ConvertToV5(const DimInputCustomV7_GY::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim);

  void ConvertToV6(const DimInputCustomV7_GY::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV6(const DimInputCustomV6_2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV6(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV6(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV6(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV6(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV6(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV6(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);

  void ConvertToV6_2(const DimInputCustomV7_GY::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim);
  void ConvertToV6_2(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim);
  void ConvertToV6_2(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim);
  void ConvertToV6_2(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim);
  void ConvertToV6_2(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim);
  void ConvertToV6_2(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim);
  void ConvertToV6_2(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim);
  void ConvertToV6_2(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim);

  void ConvertToV7_GY(const DimInputCustomV6_2::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim);
  void ConvertToV7_GY(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim);
  void ConvertToV7_GY(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim);
  void ConvertToV7_GY(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim);
  void ConvertToV7_GY(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim);
  void ConvertToV7_GY(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim);
  void ConvertToV7_GY(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim);
  void ConvertToV7_GY(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim);

  void ConvertToV9(const DimInputCustomV7_GY::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV9(const DimInputCustomV6_2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV9(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV9(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV9(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV9(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV9(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV9(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV9(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);

  void ConvertToV11(const DimInputCustomV7_GY::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim);
  void ConvertToV11(const DimInputCustomV6_2::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim);
  void ConvertToV11(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim);
  void ConvertToV11(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim);
  void ConvertToV11(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim);
  void ConvertToV11(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim);
  void ConvertToV11(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim);
  void ConvertToV11(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim);
  void ConvertToV11(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim);

  void ConvertToV11_2(const DimInputCustomV11::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV11_2(const DimInputCustomV7_GY::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV11_2(const DimInputCustomV6_2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV11_2(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV11_2(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV11_2(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV11_2(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV11_2(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV11_2(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);
  void ConvertToV11_2(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim);

public:

  static const char* GetConverterTypeName()
  {
    return "DIMInputCustom_t";
  }

  CConvDimInputCustom(void);
  virtual ~CConvDimInputCustom(void);

  const char* GetTypeName()
  {
    return GetConverterTypeName();
  }

  void Destroy()
  {
    delete this;
  }

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo,
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void** pDefaultData, unsigned long& ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo);
private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl DIM_INPUT_VERSION_V0;
  static CVersionInfoImpl DIM_INPUT_VERSION_V1;
  static CVersionInfoImpl DIM_INPUT_VERSION_V2;
  static CVersionInfoImpl DIM_INPUT_VERSION_V3;
  static CVersionInfoImpl DIM_INPUT_VERSION_V4;
  static CVersionInfoImpl DIM_INPUT_VERSION_V5;
  static CVersionInfoImpl DIM_INPUT_VERSION_V6;
  static CVersionInfoImpl DIM_INPUT_VERSION_V6_2;
  static CVersionInfoImpl DIM_INPUT_VERSION_V7;
  static CVersionInfoImpl DIM_INPUT_VERSION_V7_GY;
  static CVersionInfoImpl DIM_INPUT_VERSION_V8;
  static CVersionInfoImpl DIM_INPUT_VERSION_V9;
  static CVersionInfoImpl DIM_INPUT_VERSION_V11;
  static CVersionInfoImpl DIM_INPUT_VERSION_V11_2;

  enum eDIMInputVersions
  {
    DIM_INPUT_STRUCT_V0     = 0,
    DIM_INPUT_STRUCT_V1     = 1,
    DIM_INPUT_STRUCT_V2     = 2,
    DIM_INPUT_STRUCT_V3     = 3,
    DIM_INPUT_STRUCT_V4     = 4,
    DIM_INPUT_STRUCT_V5     = 5,
    DIM_INPUT_STRUCT_V6     = 6,
    DIM_INPUT_STRUCT_V6_2   = 7,
    DIM_INPUT_STRUCT_V7     = 8,
    DIM_INPUT_STRUCT_V7_GY  = 9,
    DIM_INPUT_STRUCT_V8     = 10,
    DIM_INPUT_STRUCT_V9     = 11,
    DIM_INPUT_STRUCT_V9_2   = 12,
    DIM_INPUT_STRUCT_V11    = 13,
    DIM_INPUT_STRUCT_V11_2  = 14,
    DIM_INPUT_VERSION_COUNT
  };
  static unsigned long SUPPORTED_SIZE[DIM_INPUT_VERSION_COUNT];

  static const CVersionInfoImpl * const DIM_INPUT_VERSIONS[DIM_INPUT_VERSION_COUNT];
};

CVersionInfoImpl CConvDimInputCustom::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V0(0, 0, 0);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V1(0, 0, 1);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V2(0, 0, 2);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V3(0, 0, 3);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V4(0, 0, 4);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V5(0, 0, 5);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V6(0, 0, 6);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V6_2(0, 0, 6);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V7(0, 0, 7);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V7_GY(0, 0, 7);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V8(0, 0, 8);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V9(0, 0, 9);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V11(0, 0, 11);
CVersionInfoImpl CConvDimInputCustom::DIM_INPUT_VERSION_V11_2(0, 0, 11);

unsigned long CConvDimInputCustom::SUPPORTED_SIZE[CConvDimInputCustom::DIM_INPUT_VERSION_COUNT]= {
  sizeof(DimInputCustomV0::DIMInputCustom_t),
  sizeof(DimInputCustomV1::DIMInputCustom_t),
  sizeof(DimInputCustomV2::DIMInputCustom_t),
  sizeof(DimInputCustomV3::DIMInputCustom_t),
  sizeof(DimInputCustomV4::DIMInputCustom_t),
  sizeof(DimInputCustomV5::DIMInputCustom_t),
  sizeof(DimInputCustomV6::DIMInputCustom_t),
  sizeof(DimInputCustomV6_2::DIMInputCustom_t),
  sizeof(DimInputCustomV6::DIMInputCustom_t),
  sizeof(DimInputCustomV7_GY::DIMInputCustom_t),
  sizeof(DimInputCustomV6::DIMInputCustom_t),
  sizeof(DimInputCustomV6::DIMInputCustom_t),
  sizeof(DimInputCustomV6_2::DIMInputCustom_t),
  sizeof(DimInputCustomV11::DIMInputCustom_t),
  sizeof(DimInputCustomV6::DIMInputCustom_t)
};

const CVersionInfoImpl * const CConvDimInputCustom::DIM_INPUT_VERSIONS[CConvDimInputCustom::DIM_INPUT_VERSION_COUNT] =
{
  &DIM_INPUT_VERSION_V0,
  &DIM_INPUT_VERSION_V1,
  &DIM_INPUT_VERSION_V2,
  &DIM_INPUT_VERSION_V3,
  &DIM_INPUT_VERSION_V4,
  &DIM_INPUT_VERSION_V5,
  &DIM_INPUT_VERSION_V6,
  &DIM_INPUT_VERSION_V6_2,
  &DIM_INPUT_VERSION_V7,
  &DIM_INPUT_VERSION_V7_GY,
  &DIM_INPUT_VERSION_V8,
  &DIM_INPUT_VERSION_V9,
  &DIM_INPUT_VERSION_V9,
  &DIM_INPUT_VERSION_V11,
  &DIM_INPUT_VERSION_V11_2
};

CConvDimInputCustom::CConvDimInputCustom(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_DimInputCustomV0(), m_DimInputCustomV2(), m_DimInputCustomV3(), m_DimInputCustomV4(), m_DimInputCustomV6(), m_DimInputCustomV11(), m_DimInputCustomV11_2()
{
  InitDimInputV0(m_DimInputCustomV0);
  InitDimInputV2(m_DimInputCustomV2);
  InitDimInputV3(m_DimInputCustomV3);
  InitDimInputV4(m_DimInputCustomV4);
  InitDimInputV5(m_DimInputCustomV5);
  InitDimInputV6(m_DimInputCustomV6);
  InitDimInputV6_2(m_DimInputCustomV6_2);
  InitDimInputV7_GY(m_DimInputCustomV7_GY);
  InitDimInputV8(m_DimInputCustomV6);
  InitDimInputV9(m_DimInputCustomV9);
  InitDimInputV11(m_DimInputCustomV11);
  InitDimInputV11_2(m_DimInputCustomV11_2);
}

CConvDimInputCustom::~CConvDimInputCustom(void)
{
}


void CConvDimInputCustom::InitDimInputV0(DimInputCustomV0::DIMInputCustom_t & DestDim)
{
  DestDim.eDriverRecognition = 3;
}

void CConvDimInputCustom::InitDimInputV1(DimInputCustomV1::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 1uL;
  DestDim.eDriverRecognition = 3;

  DestDim.fRequestedBrakeTorque    = 0.F;
  DestDim.fSteeringWheelCurvature  = 0.F;
  DestDim.fSteeringWheelCurvStdDev = 0.F;
  DestDim.fOverallCurvature = 0.F;
  DestDim.fCameraCurvature = 0.F;
  DestDim.fPsi = 0.F;
  DestDim.fLateralVelocity = 0.F;
  DestDim.fLateralDistance = 0.F;
  DestDim.eLateralDistanceStat = 0;
  DestDim.eDriverRecognition = 0;
  DestDim.bLongCtrlSysActive = FALSE;
  DestDim.bLRActive = FALSE;
  DestDim.bLaneChangeActive = FALSE;
  DestDim.bKickdown = FALSE;
  DestDim.bGearShiftActive = FALSE;
  DestDim.bSteeringWheelOffsetLearned = FALSE;
  DestDim.bTurnLightLeft = FALSE;
  DestDim.bTurnLightRight = FALSE;
  DestDim.bLaneChangeLeft = FALSE;
  DestDim.bLaneChangeRight = FALSE;
  DestDim.RadioButtons = FALSE;
  DestDim.SeatButtons = FALSE;
  DestDim.WindowButtons = FALSE;
  DestDim.MirrorButtons = FALSE;
  DestDim.InteriorLightsButtons = FALSE;
  DestDim.ExteriorLightsButtons = FALSE;
  DestDim.SunRoofButtons = FALSE;
  DestDim.SteeringWheelButtons = FALSE;
  DestDim.TiredButtons = FALSE;
  DestDim.StrColumnButtons;
  DestDim.MidConsoleButtons = FALSE;
  DestDim.OtherButtons = FALSE;
}

void CConvDimInputCustom::InitDimInputV2(DimInputCustomV2::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 2uL;
  DestDim.eDriverRecognition = 3;
}


void CConvDimInputCustom::InitDimInputV3(DimInputCustomV3::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 3uL;
  DestDim.eDriverRecognition = 3;
  DestDim.bSpeedLimitActive = FALSE;
}

void CConvDimInputCustom::InitDimInputV4(DimInputCustomV4::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 4uL;
  DestDim.eDriverRecognition = 3;
  DestDim.eSpeedLimitActive = eFCT_STATE_SIG_INACTIVE;
}

void CConvDimInputCustom::InitDimInputV5(DimInputCustomV5::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 5uL;
  //DestDim.fSteerAngleFrontEffv = 0.0F;
  //DestDim.eSteerAngleFrontEffvStat = DIMInputSignalState_OK;
  DestDim.eSpeedLimitActive = eFCT_STATE_SIG_INACTIVE;
}

void CConvDimInputCustom::InitDimInputV6(DimInputCustomV6::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 6uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  DestDim.eSpeedLimitActive = eFCT_STATE_SIG_INACTIVE;
}

void CConvDimInputCustom::InitDimInputV6_2(DimInputCustomV6_2::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 6uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  DestDim.eSpeedLimitActive = eFCT_STATE_SIG_INACTIVE;
  DestDim.sDriverInput.fBrakeTorque = 0.F;
}

void CConvDimInputCustom::InitDimInputV7_GY(DimInputCustomV7_GY::DIMInputCustom_t & DestDim)
{
  memset(&DestDim, 0,sizeof(DestDim));
  DestDim.uiVersionNumber = 7uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  DestDim.eSpeedLimitActive = eFCT_STATE_SIG_INACTIVE;
  DestDim.sDriverInput.bDriverOverride = FALSE;
}

void CConvDimInputCustom::InitDimInputV8(DimInputCustomV6::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 8uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  DestDim.eSpeedLimitActive = eFCT_STATE_SIG_INACTIVE;
}

void CConvDimInputCustom::InitDimInputV9(DimInputCustomV6::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 9uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  DestDim.eSpeedLimitActive = eFCT_STATE_SIG_INACTIVE;
}

void CConvDimInputCustom::InitDimInputV11(DimInputCustomV11::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 11uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  DestDim.eSpeedLimitActive = eFCT_STATE_SIG_INACTIVE;
  DestDim.sDriverInput.fBrakeTorque = 0.F;
  DestDim.sDriverInput.eDriverOverride = 3;
}

void CConvDimInputCustom::InitDimInputV11_2(DimInputCustomV6::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 11uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_INIT;
  DestDim.eSpeedLimitActive = eFCT_STATE_SIG_INACTIVE;
}

void CConvDimInputCustom::ConvertToV0(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV0::DIMInputCustom_t & DestDim)
{
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
}

void CConvDimInputCustom::ConvertToV2(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 2uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
}

void CConvDimInputCustom::ConvertToV2(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 2uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
}

void CConvDimInputCustom::ConvertToV2(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 2uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
}

void CConvDimInputCustom::ConvertToV2(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 2uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
}

void CConvDimInputCustom::ConvertToV2(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 2uL;
  DestDim.eDriverRecognition = eDriverRecognition_Invalid;
}

void CConvDimInputCustom::ConvertToV2(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV2::DIMInputCustom_t & DestDim)
{
  DestDim.uiVersionNumber = 2uL;
  DestDim.eDriverRecognition = eDriverRecognition_Invalid;
}


void CConvDimInputCustom::ConvertToV3(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber = 3uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
  DestDim.bSpeedLimitActive = FALSE;
}

void CConvDimInputCustom::ConvertToV3(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 3uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
  DestDim.bSpeedLimitActive = FALSE;
}

void CConvDimInputCustom::ConvertToV3(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber = 3uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
  DestDim.bSpeedLimitActive = FALSE;
}

void CConvDimInputCustom::ConvertToV3(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber = 3uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
  DestDim.bSpeedLimitActive = (SrcDim.eSpeedLimitActive == eFCT_STATE_SIG_ACTIVE) ? TRUE : FALSE;
}

void CConvDimInputCustom::ConvertToV3(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 3uL;
  DestDim.eDriverRecognition = eDriverRecognition_Invalid;
  DestDim.bSpeedLimitActive = (SrcDim.eSpeedLimitActive == eFCT_STATE_SIG_ACTIVE) ? TRUE : FALSE;
}

void CConvDimInputCustom::ConvertToV3(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV3::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 3uL;
  DestDim.eDriverRecognition = eDriverRecognition_Invalid;
  DestDim.bSpeedLimitActive = (SrcDim.eSpeedLimitActive == eFCT_STATE_SIG_ACTIVE) ? TRUE : FALSE;
}

void CConvDimInputCustom::ConvertToV4(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 4uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
}

void CConvDimInputCustom::ConvertToV4(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 4uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
}

void CConvDimInputCustom::ConvertToV4(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 4uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
}

void CConvDimInputCustom::ConvertToV4(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 4uL;
  DestDim.eDriverRecognition = SrcDim.eDriverRecognition;
  DestDim.eSpeedLimitActive  = (SrcDim.bSpeedLimitActive != FALSE) ? eFCT_STATE_SIG_ACTIVE: eFCT_STATE_SIG_INACTIVE;
}

void CConvDimInputCustom::ConvertToV4(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 4uL;
  DestDim.eDriverRecognition = eDriverRecognition_Invalid;
  DestDim.eSpeedLimitActive  = SrcDim.eSpeedLimitActive;
}

void CConvDimInputCustom::ConvertToV4(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV4::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 4uL;
  DestDim.eDriverRecognition = eDriverRecognition_Invalid;
  DestDim.eSpeedLimitActive  = SrcDim.eSpeedLimitActive;
}

void CConvDimInputCustom::ConvertToV5(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 5uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  //DestDim.fSteerAngleFrontEffv = 0.0F;
  //DestDim.eSteerAngleFrontEffvStat = DIMInputSignalState_OK;
}

void CConvDimInputCustom::ConvertToV5(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 5uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  //DestDim.fSteerAngleFrontEffv = 0.0F;
  //DestDim.eSteerAngleFrontEffvStat = DIMInputSignalState_OK;
}

void CConvDimInputCustom::ConvertToV5(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 5uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  //DestDim.fSteerAngleFrontEffv = 0.0F;
  //DestDim.eSteerAngleFrontEffvStat = DIMInputSignalState_OK;
}

void CConvDimInputCustom::ConvertToV5(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 5uL;
  DestDim.eSpeedLimitActive  = (SrcDim.bSpeedLimitActive != FALSE) ? eFCT_STATE_SIG_ACTIVE: eFCT_STATE_SIG_INACTIVE;
  //DestDim.fSteerAngleFrontEffv = 0.0F;
  //DestDim.eSteerAngleFrontEffvStat = DIMInputSignalState_OK;
}

void CConvDimInputCustom::ConvertToV5(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 5uL;
  DestDim.eSpeedLimitActive  = SrcDim.eSpeedLimitActive;
  //DestDim.fSteerAngleFrontEffv = 0.0F;
  //DestDim.eSteerAngleFrontEffvStat = DIMInputSignalState_OK;
}

void CConvDimInputCustom::ConvertToV5(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV5::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 5uL;
  DestDim.eSpeedLimitActive  = SrcDim.eSpeedLimitActive;
}


void CConvDimInputCustom::ConvertToV6(const DimInputCustomV6_2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber       = 6uL;
  DestDim.eSpeedLimitActive     = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader            = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV6(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber       = 6uL;
  DestDim.sSigHeader            = SrcDim.sSigHeader;
  DestDim.eSpeedLimitActive     = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV6(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 6uL;
  DestDim.eSpeedLimitActive  = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV6(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 6uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  if (SrcDim.bSpeedLimitActive)
  {
    DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_ACTIVE;
  }
  else
  {
    DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  }
}
void CConvDimInputCustom::ConvertToV6(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 6uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV6(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 6uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV6(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 6uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}

void CConvDimInputCustom::ConvertToV6_2(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber           = 6uL;
  DestDim.eSpeedLimitActive         = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader                = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus     = AL_SIG_STATE_OK;
  DestDim.sDriverInput.fBrakeTorque = 0.F;
}
void CConvDimInputCustom::ConvertToV6_2(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber       = 6uL;
  DestDim.eSpeedLimitActive     = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader            = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV6_2(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 6uL;
  DestDim.eSpeedLimitActive  = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  DestDim.sDriverInput.fBrakeTorque = 0.F;
}
void CConvDimInputCustom::ConvertToV6_2(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 6uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  if (SrcDim.bSpeedLimitActive)
  {
    DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_ACTIVE;
  }
  else
  {
    DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  }
  DestDim.sDriverInput.fBrakeTorque = 0.F;
}
void CConvDimInputCustom::ConvertToV6_2(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 6uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  DestDim.sDriverInput.fBrakeTorque = 0.F;
}
void CConvDimInputCustom::ConvertToV6_2(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 6uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  DestDim.sDriverInput.fBrakeTorque = 0.F;
}
void CConvDimInputCustom::ConvertToV6_2(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV6_2::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 6uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  DestDim.sDriverInput.fBrakeTorque = 0.F;
}

void CConvDimInputCustom::ConvertToV7_GY(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 7uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  DestDim.sDriverInput.bDriverOverride = FALSE;
}
void CConvDimInputCustom::ConvertToV7_GY(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 7uL;
  DestDim.eSpeedLimitActive  = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  DestDim.sDriverInput.bDriverOverride = FALSE;
}
void CConvDimInputCustom::ConvertToV7_GY(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 7uL;
  DestDim.eSpeedLimitActive  = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  DestDim.sDriverInput.bDriverOverride = FALSE;
}
void CConvDimInputCustom::ConvertToV7_GY(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 7uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  if (SrcDim.bSpeedLimitActive)
  {
    DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_ACTIVE;
  }
  else
  {
    DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  }
  DestDim.sDriverInput.bDriverOverride = FALSE;
}
void CConvDimInputCustom::ConvertToV7_GY(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 7uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  DestDim.sDriverInput.bDriverOverride = FALSE;
}
void CConvDimInputCustom::ConvertToV7_GY(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 7uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  DestDim.sDriverInput.bDriverOverride = FALSE;
}
void CConvDimInputCustom::ConvertToV7_GY(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV7_GY::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 7uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  DestDim.sDriverInput.bDriverOverride = FALSE;
}

void CConvDimInputCustom::ConvertToV9(const DimInputCustomV6_2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber       = 9uL;
  DestDim.eSpeedLimitActive     = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader            = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV9(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 9uL;
  DestDim.eSpeedLimitActive  = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV9(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 9uL;
  DestDim.eSpeedLimitActive  = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV9(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 9uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  if (SrcDim.bSpeedLimitActive)
  {
    DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_ACTIVE;
  }
  else
  {
    DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  }
}
void CConvDimInputCustom::ConvertToV9(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 9uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV9(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 9uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV9(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 9uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}

void CConvDimInputCustom::ConvertToV11(const DimInputCustomV6_2::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber              = 11uL;
  DestDim.eSpeedLimitActive            = SrcDim.eSpeedLimitActive;
  DestDim.sDriverInput.fBrakeTorque    = SrcDim.sDriverInput.fBrakeTorque;
  DestDim.sDriverInput.eDriverOverride = 3;
  DestDim.sSigHeader                   = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus        = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber              = 11uL;
  DestDim.eSpeedLimitActive            = SrcDim.eSpeedLimitActive;
  DestDim.sDriverInput.fBrakeTorque    = 0.F;
  DestDim.sDriverInput.eDriverOverride = 3;
  DestDim.sSigHeader                   = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus        = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber              = 11uL;
  DestDim.eSpeedLimitActive            = SrcDim.eSpeedLimitActive;
  DestDim.sDriverInput.fBrakeTorque    = 0.F;
  DestDim.sDriverInput.eDriverOverride = 3;
  DestDim.sSigHeader                   = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus        = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber              = 11uL;
  DestDim.eSpeedLimitActive            = SrcDim.eSpeedLimitActive;
  DestDim.sDriverInput.fBrakeTorque    = 0.F;
  DestDim.sDriverInput.eDriverOverride = 3;
  DestDim.sSigHeader.eSigStatus        = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber       = 11uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  if (SrcDim.bSpeedLimitActive)
  {
    DestDim.eSpeedLimitActive = eFCT_STATE_SIG_ACTIVE;
  }
  else
  {
    DestDim.eSpeedLimitActive = eFCT_STATE_SIG_INACTIVE;
  }
  DestDim.sDriverInput.fBrakeTorque    = 0.F;
  DestDim.sDriverInput.eDriverOverride = 3;
}
void CConvDimInputCustom::ConvertToV11(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber              = 11uL;
  DestDim.eSpeedLimitActive            = eFCT_STATE_SIG_INACTIVE;
  DestDim.sDriverInput.fBrakeTorque    = 0.F;
  DestDim.sDriverInput.eDriverOverride = 3;
  DestDim.sSigHeader.eSigStatus        = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber              = 11uL;
  DestDim.eSpeedLimitActive            = eFCT_STATE_SIG_INACTIVE;
  DestDim.sDriverInput.fBrakeTorque    = 0.F;
  DestDim.sDriverInput.eDriverOverride = 3;
  DestDim.sSigHeader.eSigStatus        = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV11::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber              = 11uL;
  DestDim.eSpeedLimitActive            = eFCT_STATE_SIG_INACTIVE;
  DestDim.sDriverInput.fBrakeTorque    = 0.F;
  DestDim.sDriverInput.eDriverOverride = 3;
  DestDim.sSigHeader.eSigStatus        = AL_SIG_STATE_OK;
}


void CConvDimInputCustom::ConvertToV11_2(const DimInputCustomV11::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber       = 11uL;
  DestDim.eSpeedLimitActive     = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader            = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11_2(const DimInputCustomV6_2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber       = 11uL;
  DestDim.eSpeedLimitActive     = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader            = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11_2(const DimInputCustomV6::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber       = 11uL;
  DestDim.eSpeedLimitActive     = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader            = SrcDim.sSigHeader;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11_2(const DimInputCustomV5::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber       = 11uL;
  DestDim.sSigHeader            = SrcDim.sSigHeader;
  DestDim.eSpeedLimitActive     = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11_2(const DimInputCustomV4::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber       = 11uL;
  DestDim.eSpeedLimitActive     = SrcDim.eSpeedLimitActive;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11_2(const DimInputCustomV3::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 11uL;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
  if (SrcDim.bSpeedLimitActive)
  {
    DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_ACTIVE;
  }
  else
  {
    DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  }
}
void CConvDimInputCustom::ConvertToV11_2(const DimInputCustomV2::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 11uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11_2(const DimInputCustomV1::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 11uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}
void CConvDimInputCustom::ConvertToV11_2(const DimInputCustomV0::DIMInputCustom_t &SrcDim, DimInputCustomV6::DIMInputCustom_t &DestDim)
{
  DestDim.uiVersionNumber    = 11uL;
  DestDim.eSpeedLimitActive  = eFCT_STATE_SIG_INACTIVE;
  DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK;
}

long CConvDimInputCustom::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo,
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  if (eRPortType == ePPortType)
  {
    const uint32 raw_data_version = *reinterpret_cast<const uint32 *>(pPPortData);
    CVersionInfoImpl RawVersion((raw_data_version >> 16) & 0xFF, (raw_data_version >> 8) & 0xFF, (raw_data_version & 0xFF));

    if ( (ulRPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V11_2) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V11_2 */
      DimInputCustomV6::DIMInputCustom_t &DestDim = m_DimInputCustomV11_2;
      if ( (ulPPortSize == sizeof(DimInputCustomV11::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V11)) )
      {
        /* Provide port V11 */
        const DimInputCustomV11::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV11::DIMInputCustom_t *>(pPPortData);
        ConvertToV11_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV6_2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6_2)) )
      {
        /* Provide port V6_2 */
        const DimInputCustomV6_2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6_2::DIMInputCustom_t *>(pPPortData);
        ConvertToV11_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && ((RawVersion.Equals(&DIM_INPUT_VERSION_V6)) || (RawVersion.Equals(&DIM_INPUT_VERSION_V7)) || (RawVersion.Equals(&DIM_INPUT_VERSION_V8)) || (RawVersion.Equals(&DIM_INPUT_VERSION_V9)) || (RawVersion.Equals(&DIM_INPUT_VERSION_V11_2))))
      {
        /* Provide port V6 */
        const DimInputCustomV6::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6::DIMInputCustom_t *>(pPPortData);
        ConvertToV11_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V5)) )
      {
        /* Provide port V5 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData);
        ConvertToV11_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V4)) )
      {
        /* Provide port V4 */
        const DimInputCustomV4::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV4::DIMInputCustom_t *>(pPPortData);
        ConvertToV11_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V3)) )
      {
        /* Provide port V3 */
        const DimInputCustomV3::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV3::DIMInputCustom_t *>(pPPortData);
        ConvertToV11_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        const DimInputCustomV2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV2::DIMInputCustom_t *>(pPPortData);
        ConvertToV11_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        const DimInputCustomV1::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV1::DIMInputCustom_t *>(pPPortData);
        ConvertToV11_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        const DimInputCustomV0::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV0::DIMInputCustom_t *>(pPPortData);
        ConvertToV11_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV11::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V11) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V11 */
      DimInputCustomV11::DIMInputCustom_t &DestDim = m_DimInputCustomV11;
      if ( (ulPPortSize == sizeof(DimInputCustomV6_2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6_2)) )
      {
        /* Provide port V6_2 */
        const DimInputCustomV6_2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6_2::DIMInputCustom_t *>(pPPortData);
        ConvertToV11(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && ((RawVersion.Equals(&DIM_INPUT_VERSION_V6)) || (RawVersion.Equals(&DIM_INPUT_VERSION_V7)) || (RawVersion.Equals(&DIM_INPUT_VERSION_V9))))
      {
        /* Provide port V6 */
        const DimInputCustomV6::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6::DIMInputCustom_t *>(pPPortData);
        ConvertToV11(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V5)) )
      {
        /* Provide port V5 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData);
        ConvertToV11(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V4)) )
      {
        /* Provide port V4 */
        const DimInputCustomV4::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV4::DIMInputCustom_t *>(pPPortData);
        ConvertToV11(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V3)) )
      {
        /* Provide port V3 */
        const DimInputCustomV3::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV3::DIMInputCustom_t *>(pPPortData);
        ConvertToV11(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        const DimInputCustomV2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV2::DIMInputCustom_t *>(pPPortData);
        ConvertToV11(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        const DimInputCustomV1::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV1::DIMInputCustom_t *>(pPPortData);
        ConvertToV11(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        const DimInputCustomV0::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV0::DIMInputCustom_t *>(pPPortData);
        ConvertToV11(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V9) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V9 */
      DimInputCustomV6::DIMInputCustom_t &DestDim = m_DimInputCustomV9;
      if ( (ulPPortSize == sizeof(DimInputCustomV6_2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6_2)) )
      {
        /* Provide port V6_2 */
        const DimInputCustomV6_2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6_2::DIMInputCustom_t *>(pPPortData);
        ConvertToV9(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && ((RawVersion.Equals(&DIM_INPUT_VERSION_V6)) || (RawVersion.Equals(&DIM_INPUT_VERSION_V9))))
      {
        /* Provide port V6 */
        const DimInputCustomV6::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6::DIMInputCustom_t *>(pPPortData);
        DestDim = SrcDim;
        DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK; // Thank you frame SW... 
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V5)) )
      {
        /* Provide port V5 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData);
        ConvertToV9(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V4)) )
      {
        /* Provide port V4 */
        const DimInputCustomV4::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV4::DIMInputCustom_t *>(pPPortData);
        ConvertToV9(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V3)) )
      {
        /* Provide port V3 */
        const DimInputCustomV3::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV3::DIMInputCustom_t *>(pPPortData);
        ConvertToV9(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        const DimInputCustomV2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV2::DIMInputCustom_t *>(pPPortData);
        ConvertToV9(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        const DimInputCustomV1::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV1::DIMInputCustom_t *>(pPPortData);
        ConvertToV9(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        const DimInputCustomV0::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV0::DIMInputCustom_t *>(pPPortData);
        ConvertToV9(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V8) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V8 */
      DimInputCustomV6::DIMInputCustom_t &DestDim = m_DimInputCustomV6;
      if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V8) || RawVersion.Equals(&DIM_INPUT_VERSION_V7)) )
      {
        /* Provide port V8 or V7 */
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6)) )
      {
        /* Request port V8 (ARS410GY18) which is actually DimInputCustomV7_GY ! */
        DimInputCustomV7_GY::DIMInputCustom_t &DestDim = m_DimInputCustomV7_GY;
        /* Provide port V6 implemented for ARS410GY18 ! */
        const DimInputCustomV6::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6::DIMInputCustom_t *>(pPPortData);
        ConvertToV7_GY(SrcDim, DestDim);
        DestDim.uiVersionNumber = 8u;
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV7_GY::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V7_GY) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V7_GY */
      DimInputCustomV7_GY::DIMInputCustom_t &DestDim = m_DimInputCustomV7_GY;
      if ( (ulPPortSize == sizeof(DimInputCustomV7_GY::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V7_GY)) )
      {
        /* Provide port V7_GY */
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      /* Request port V6_2 */
      else if ( (ulPPortSize == sizeof(DimInputCustomV6_2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6_2)) ) // correct ??
      {
        /* Provide port V6_2 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData); // could stay from V5 ???
        ConvertToV7_GY(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      /* Request port V6 */
      else if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6)) ) // needed after 6_2 ??
      {
        /* Provide port V6 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData);
        ConvertToV7_GY(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V5)) )
      {
        /* Provide port V5 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData);
        ConvertToV7_GY(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V4)) )
      {
        /* Provide port V4 */
        const DimInputCustomV4::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV4::DIMInputCustom_t *>(pPPortData);
        ConvertToV7_GY(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V3)) )
      {
        /* Provide port V3 */
        const DimInputCustomV3::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV3::DIMInputCustom_t *>(pPPortData);
        ConvertToV7_GY(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        const DimInputCustomV2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV2::DIMInputCustom_t *>(pPPortData);
        ConvertToV7_GY(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        const DimInputCustomV1::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV1::DIMInputCustom_t *>(pPPortData);
        ConvertToV7_GY(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        const DimInputCustomV0::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV0::DIMInputCustom_t *>(pPPortData);
        ConvertToV7_GY(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV6_2::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V6_2) || requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V9) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V6_2, V9 (Mitsubishi) and V9_2 (ARS510) */
      DimInputCustomV6_2::DIMInputCustom_t &DestDim = m_DimInputCustomV6_2;
      if ( (ulPPortSize == sizeof(DimInputCustomV6_2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6_2) || RawVersion.Equals(&DIM_INPUT_VERSION_V9) || RawVersion.Equals(&DIM_INPUT_VERSION_V8)))
      {
        /* Provide port V6_2, V8 (Mitsubishi) and V9_2 (ARS510) */
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6)) )
      {
        /* Provide port V6 */
        const DimInputCustomV6::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6::DIMInputCustom_t *>(pPPortData);
        ConvertToV6_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V5)) )
      {
        /* Provide port V5 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData);
        ConvertToV6_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V4)) )
      {
        /* Provide port V4 */
        const DimInputCustomV4::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV4::DIMInputCustom_t *>(pPPortData);
        ConvertToV6_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V3)) )
      {
        /* Provide port V3 */
        const DimInputCustomV3::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV3::DIMInputCustom_t *>(pPPortData);
        ConvertToV6_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        const DimInputCustomV2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV2::DIMInputCustom_t *>(pPPortData);
        ConvertToV6_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        const DimInputCustomV1::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV1::DIMInputCustom_t *>(pPPortData);
        ConvertToV6_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        const DimInputCustomV0::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV0::DIMInputCustom_t *>(pPPortData);
        ConvertToV6_2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V6) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V6 */
      DimInputCustomV6::DIMInputCustom_t &DestDim = m_DimInputCustomV6;
      if ( (ulPPortSize == sizeof(DimInputCustomV6_2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6_2)) )
      {
        /* Provide port V6_2 */
        const DimInputCustomV6_2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6_2::DIMInputCustom_t *>(pPPortData);
        ConvertToV6(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6)) )
      {
        /* Provide port V6 */
        const DimInputCustomV6::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6::DIMInputCustom_t *>(pPPortData);
        DestDim = SrcDim;
        DestDim.sSigHeader.eSigStatus = AL_SIG_STATE_OK; // Thank you frame SW... 
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V5)) )
      {
        /* Provide port V5 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData);
        ConvertToV6(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V4)) )
      {
        /* Provide port V4 */
        const DimInputCustomV4::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV4::DIMInputCustom_t *>(pPPortData);
        ConvertToV6(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V3)) )
      {
        /* Provide port V3 */
        const DimInputCustomV3::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV3::DIMInputCustom_t *>(pPPortData);
        ConvertToV6(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        const DimInputCustomV2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV2::DIMInputCustom_t *>(pPPortData);
        ConvertToV6(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        const DimInputCustomV1::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV1::DIMInputCustom_t *>(pPPortData);
        ConvertToV6(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        const DimInputCustomV0::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV0::DIMInputCustom_t *>(pPPortData);
        ConvertToV6(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V5) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V5 */
      DimInputCustomV5::DIMInputCustom_t &DestDim = m_DimInputCustomV5;
      if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6)) )
      {
        /* Provide port V6 */
        const DimInputCustomV6::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6::DIMInputCustom_t *>(pPPortData);
        ConvertToV5(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V5)) )
      {
        /* Provide port V5 */
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V4)) )
      {
        /* Provide port V4 */
        const DimInputCustomV4::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV4::DIMInputCustom_t *>(pPPortData);
        ConvertToV5(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V3)) )
      {
        /* Provide port V3 */
        const DimInputCustomV3::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV3::DIMInputCustom_t *>(pPPortData);
        ConvertToV5(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        const DimInputCustomV2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV2::DIMInputCustom_t *>(pPPortData);
        ConvertToV5(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        const DimInputCustomV1::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV1::DIMInputCustom_t *>(pPPortData);
        ConvertToV5(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        const DimInputCustomV0::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV0::DIMInputCustom_t *>(pPPortData);
        ConvertToV5(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V4) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V4 */
      DimInputCustomV4::DIMInputCustom_t &DestDim = m_DimInputCustomV4;
      if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6)) )
      {
        /* Provide port V6 */
        const DimInputCustomV6::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6::DIMInputCustom_t *>(pPPortData);
        ConvertToV4(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V5)) )
      {
        /* Provide port V5 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData);
        ConvertToV4(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V4)) )
      {
        /* Provide port V4 */
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V3)) )
      {
        /* Provide port V3 */
        const DimInputCustomV3::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV3::DIMInputCustom_t *>(pPPortData);
        ConvertToV4(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        const DimInputCustomV2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV2::DIMInputCustom_t *>(pPPortData);
        ConvertToV4(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        const DimInputCustomV1::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV1::DIMInputCustom_t *>(pPPortData);
        ConvertToV4(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        const DimInputCustomV0::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV0::DIMInputCustom_t *>(pPPortData);
        ConvertToV4(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V3) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V3 */
      DimInputCustomV3::DIMInputCustom_t &DestDim = m_DimInputCustomV3;
      if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6)) )
      {
        /* Provide port V6 */
        const DimInputCustomV6::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6::DIMInputCustom_t *>(pPPortData);
        ConvertToV3(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V5)) )
      {
        /* Provide port V5 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData);
        ConvertToV3(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V4)) )
      {
        /* Provide port V4 */
        const DimInputCustomV4::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV4::DIMInputCustom_t *>(pPPortData);
        ConvertToV3(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V3)) )
      {
        /* Provide port V3 */
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        const DimInputCustomV2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV2::DIMInputCustom_t *>(pPPortData);
        ConvertToV3(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        const DimInputCustomV1::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV1::DIMInputCustom_t *>(pPPortData);
        ConvertToV3(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        const DimInputCustomV0::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV0::DIMInputCustom_t *>(pPPortData);
        ConvertToV3(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V2) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V2 */
      DimInputCustomV2::DIMInputCustom_t &DestDim = m_DimInputCustomV2;
      if ( (ulPPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V6)) )
      {
        /* Provide port V6 */
        const DimInputCustomV6::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV6::DIMInputCustom_t *>(pPPortData);
        ConvertToV2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V5)) )
      {
        /* Provide port V5 */
        const DimInputCustomV5::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV5::DIMInputCustom_t *>(pPPortData);
        ConvertToV2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V4)) )
      {
        /* Provide port V4 */
        const DimInputCustomV4::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV4::DIMInputCustom_t *>(pPPortData);
        ConvertToV2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V3)) )
      {
        /* Provide port V3 */
        const DimInputCustomV3::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV3::DIMInputCustom_t *>(pPPortData);
        ConvertToV2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        const DimInputCustomV1::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV1::DIMInputCustom_t *>(pPPortData);
        ConvertToV2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        const DimInputCustomV0::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV0::DIMInputCustom_t *>(pPPortData);
        ConvertToV2(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V1) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V1 */
      DimInputCustomV1::DIMInputCustom_t &DestDim = m_DimInputCustomV1;
      if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        /* Provide port V1 */
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V4) || (requestPortVersionInfo.Equals(&BASE_VERSION)))))
    {
      /* Request port V0 */
      DimInputCustomV0::DIMInputCustom_t &DestDim = m_DimInputCustomV0;
      if ( (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V2)) )
      {
        /* Provide port V2 */
        const DimInputCustomV2::DIMInputCustom_t &SrcDim = *reinterpret_cast<DimInputCustomV2::DIMInputCustom_t *>(pPPortData);
        ConvertToV0(SrcDim, DestDim);
        *pOutData = &DestDim;
        ulOutSize = sizeof(DestDim);
        lRet = SIM_ERR_OK;
      }
      else if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (RawVersion.Equals(&DIM_INPUT_VERSION_V0)) )
      {
        /* Provide port V0 */
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      else
      {
        long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
  }
  return lRet;
}


/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvDimInputCustom::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    // Find proper version to use for default value
    if ((ulRPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V11_2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* port version v11_2 */
      DimInputCustomV6::DIMInputCustom_t &DestDim = m_DimInputCustomV11_2;
      InitDimInputV11_2(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV11::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V11)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* port version v11 */
      DimInputCustomV11::DIMInputCustom_t &DestDim = m_DimInputCustomV11;
      InitDimInputV11(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V9)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* port version v9 */
      DimInputCustomV6::DIMInputCustom_t &DestDim = m_DimInputCustomV9;
      InitDimInputV9(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV7_GY::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V7_GY)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* port version v7 */
      DimInputCustomV7_GY::DIMInputCustom_t &DestDim = m_DimInputCustomV7_GY;
      InitDimInputV7_GY(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV6_2::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V6_2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* port version v6 */
      DimInputCustomV6_2::DIMInputCustom_t &DestDim = m_DimInputCustomV6_2;
      InitDimInputV6_2(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV6::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V6)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* port version v6 */
      DimInputCustomV6::DIMInputCustom_t &DestDim = m_DimInputCustomV6;
      InitDimInputV6(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV5::DIMInputCustom_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V5)))
      /* port version v5 */
    {
      DimInputCustomV5::DIMInputCustom_t &DestDim = m_DimInputCustomV5;
      InitDimInputV5(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV4::DIMInputCustom_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V4)))
      /* port version v4 */
    {
      DimInputCustomV4::DIMInputCustom_t &DestDim = m_DimInputCustomV4;
      InitDimInputV4(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV3::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V3)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* port version v3 */
      DimInputCustomV3::DIMInputCustom_t &DestDim = m_DimInputCustomV3;
      InitDimInputV3(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* port version v2 */
      DimInputCustomV2::DIMInputCustom_t &DestDim = m_DimInputCustomV2;
      InitDimInputV2(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V1)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* port version v1 */
      DimInputCustomV1::DIMInputCustom_t &DestDim = m_DimInputCustomV1;
      InitDimInputV1(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V0)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      /* port version v0 */
      DimInputCustomV0::DIMInputCustom_t &DestDim = m_DimInputCustomV0;
      InitDimInputV0(DestDim);
      *pDefaultData = &DestDim;
      ulDefaultSize = sizeof(DestDim);
      lRet = SIM_ERR_OK;
    }
    else
    {
      lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvDimInputCustom::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  if (eRPortType == ePPortType)
  {
    if ((ulRPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V0)))
    {
      /* Port is version 0 */
      if ( (ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t))
        || (ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) )
      {
        bResult = true;
      }
    }
    else if ((ulRPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V1)))
      /* Port is version 1 */
    {
      if (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t))
        /* no converter available */
      {
        bResult = true;
      }
    }
    else
    {
      /* RPort is version 2 to 8 and 11 to 11_2 (all converters implemented) */
      for (int nI=2; nI<DIM_INPUT_VERSION_COUNT; nI++)
      {
        if ((ulRPortSize == SUPPORTED_SIZE[nI]) && requestPortVersionInfo.Equals(DIM_INPUT_VERSIONS[nI]))
        {
          /* PPort version 0 to 9 */
          for (int nJ=0; nJ<DIM_INPUT_VERSION_COUNT; nJ++)
          {
            if (ulPPortSize == SUPPORTED_SIZE[nJ])
            {
              bResult = true;
              break;
            }
          }
        }
      }
    }
  }
  else
  {
    bResult = false;
  }
  return bResult;
}


// used to check if ports are compatible between different versions
bool CConvDimInputCustom::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult;
  if (eRPortType == ePPortType)
  {
    if ( (ulRPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V0)) || (requestPortVersionInfo.Equals(&BASE_VERSION))) )
    {
      /* request port version 0 */
      if ( ((ulPPortSize == sizeof(DimInputCustomV0::DIMInputCustom_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V0)))
        || ((ulPPortSize == sizeof(DimInputCustomV2::DIMInputCustom_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V2))) )
      {
        bResult = true;
      }
    }
    else if ( (ulRPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && ((requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V1)) || (requestPortVersionInfo.Equals(&BASE_VERSION))) )
    {
      /* request port version 1 */
      if ( (ulPPortSize == sizeof(DimInputCustomV1::DIMInputCustom_t)) && (requestPortVersionInfo.Equals(&DIM_INPUT_VERSION_V1)) )
      {
        bResult = true;
      }
    }
    else
    {
      /* RPort is version 2 to 9 and 11 to 11_2 (all converters implemented) */
      for (int nI=2; nI<DIM_INPUT_VERSION_COUNT; nI++)
      {
        if ((ulRPortSize == SUPPORTED_SIZE[nI]) && requestPortVersionInfo.Equals(DIM_INPUT_VERSIONS[nI]))
        {
          /* PPort version 0 to 9 */
          for (int nJ=0; nJ<DIM_INPUT_VERSION_COUNT; nJ++)
          {
            if ((ulPPortSize == SUPPORTED_SIZE[nJ]) && providePortVersionInfo.Equals(DIM_INPUT_VERSIONS[nJ]))
            {
              bResult = true;
              break;
            }
          }
        }
      }
    }
  }
  else
  {
    bResult = false;
  }
  return bResult;
}

//
// Externally visible factory function for conversion instance
//

IConverter * CreateDimInputCustomConvInstance(void)
{
  return new CConvDimInputCustom();
}
