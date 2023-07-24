/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_head_input_generic.cpp

  DESCRIPTION:          

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_head_input_custom.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:01CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:18CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.16 2016/11/16 14:04:35CET Dagli, Goekhan (uidj7850) 
  CHANGES:              + V7_D1
  CHANGES:              + V9_MI
  CHANGES:              Revision 1.15 2016/09/21 13:21:10CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Handling of V9 and V10_2
  CHANGES:              Revision 1.14 2016/09/14 13:47:05CEST Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              +V10 (Hyundayi)
  CHANGES:              Revision 1.13 2016/03/03 17:30:19CET Roedelsperger-EXT, Sabine (uidp2902) 
  CHANGES:              Added conversion for V9_GY (Geely)
  CHANGES:              Revision 1.12 2015/12/14 13:33:29CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Update with V9 (actually V9a because only for ARS4D1 and ARS4D2)
  CHANGES:              Revision 1.11 2015/07/02 15:48:02CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Conversion V7 to V8a to enable x-simulation D1/B0 D2/T0 for older measurements
  CHANGES:              - Added comments -  berndtt1 [Jul 2, 2015 3:52:52 PM CEST]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.10 2015/05/29 13:49:35CEST Diepolder, Thomas (diepoldert) 
  CHANGES:              Updated adapter to enable x-simulation D1/B0 D2/T0
  CHANGES:              --- Added comments ---  diepoldert [May 29, 2015 1:49:35 PM CEST]
  CHANGES:              Change Package : 343338:1 http://mks-psad:7002/im/viewissue?selection=343338
  CHANGES:              Revision 1.9 2014/07/25 08:35:11CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Revisions V7 and V8
  CHANGES:              --- Added comments ---  berndtt1 [Jul 25, 2014 8:38:44 AM CEST]
  CHANGES:              Change Package : 221167:21 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.8 2014/01/24 15:35:50CET Obst, Christian02 (uidv8774) 
  CHANGES:              updated Adapter TypeNaming and
  CHANGES:              using "big Adapter" version of HeadInputCustom
  CHANGES:              --- Added comments ---  uidv8774 [Jan 24, 2014 3:35:51 PM CET]
  CHANGES:              Change Package : 215077:1 http://mks-psad:7002/im/viewissue?selection=215077
  CHANGES:              Revision 1.7 2013/05/21 18:04:27CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              --- Added comments ---  ungvaryg [May 21, 2013 6:04:27 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.6 2012/04/18 14:10:33CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add head input custom v4b (long live the exponential complexity explosion of interfaces!)
  CHANGES:              --- Added comments ---  ungvaryg [Apr 18, 2012 2:10:37 PM CEST]
  CHANGES:              Change Package : 111577:1 http://mks-psad:7002/im/viewissue?selection=111577
  CHANGES:              Revision 1.5 2012/03/15 09:01:45CET Froehlich, Dominik01 (froehlichd1) 
  CHANGES:              * change: updated adapter to RTE change for FCM inhibit
  CHANGES:              --- Added comments ---  froehlichd1 [Mar 15, 2012 9:01:45 AM CET]
  CHANGES:              Change Package : 102796:3 http://mks-psad:7002/im/viewissue?selection=102796
  CHANGES:              Revision 1.4 2012/02/21 17:46:17CET Diepolder, Thomas (diepoldert) 
  CHANGES:              New adaptations for ars353 version 3 headinputcustom
  CHANGES:              --- Added comments ---  diepoldert [Feb 21, 2012 5:46:17 PM CET]
  CHANGES:              Change Package : 97173:1 http://mks-psad:7002/im/viewissue?selection=97173
  CHANGES:              Revision 1.3 2012/01/19 10:08:26CET Froehlich, Dominik01 (froehlichd1) 
  CHANGES:              * change: support of HEADInputCustom interface changes
  CHANGES:              --- Added comments ---  froehlichd1 [Jan 19, 2012 10:08:27 AM CET]
  CHANGES:              Change Package : 30337:8 http://mks-psad:7002/im/viewissue?selection=30337
  CHANGES:              Revision 1.2 2011/03/21 12:56:49CET Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Fix bug: Camera status was not copied
  CHANGES:              Set default "iBrake5" active in case of old version coding parameters
  CHANGES:              --- Added comments ---  diepoldert [Mar 21, 2011 12:56:50 PM CET]
  CHANGES:              Change Package : 59660:2 http://mks-psad:7002/im/viewissue?selection=59660
  CHANGES:              Revision 1.1 2011/03/02 13:49:00CET Thomas Diepolder (diepoldert) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_head_input_custom.h"
#include "sim_versioninfo_impl.h"
#include "interfaceheadinput.h"

class CConvHeadInputCustom :
  public CSimConverterBase
//  public CHeadInputCustom
{

  // the list of dependency names used inside by the converter
  /*
  static const char* DEP_NAMES[];
  */
  // Buffer for holding converted data
  HEADInputCustomV1::HEADInputCustom_t  m_HeadInputCustomV1;
  HEADInputCustomV2a::HEADInputCustom_t m_HeadInputCustomV2a;
  HEADInputCustomV2b::HEADInputCustom_t m_HeadInputCustomV2b;
  HEADInputCustomV3a::HEADInputCustom_t  m_HeadInputCustomV3a;
  HEADInputCustomV3b::HEADInputCustom_t  m_HeadInputCustomV3b;
  HEADInputCustomV4a::HEADInputCustom_t  m_HeadInputCustomV4a;
  HEADInputCustomV4b::HEADInputCustom_t  m_HeadInputCustomV4b;
  HEADInputCustomV7::HEADInputCustom_t  m_HeadInputCustomV7;
  HEADInputCustomV7_D1::HEADInputCustom_t  m_HeadInputCustomV7_D1;
  HEADInputCustomV8::HEADInputCustom_t  m_HeadInputCustomV8;
  HEADInputCustomV8a::HEADInputCustom_t  m_HeadInputCustomV8a;
  HEADInputCustomV9::HEADInputCustom_t  m_HeadInputCustomV9;
  HEADInputCustomV9a::HEADInputCustom_t  m_HeadInputCustomV9a;
  HEADInputCustomV9_GY::HEADInputCustom_t  m_HeadInputCustomV9_GY;
  HEADInputCustomV9_MI::HEADInputCustom_t  m_HeadInputCustomV9_MI;
  HEADInputCustomV10::HEADInputCustom_t  m_HeadInputCustomV10;
  HEADInputCustomV10_2::HEADInputCustom_t  m_HeadInputCustomV10_2;

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  void InitHeadInputV1(HEADInputCustomV1::HEADInputCustom_t & DestHead);
  void InitHeadInputV2a(HEADInputCustomV2a::HEADInputCustom_t & DestHead);
  void InitHeadInputV2b(HEADInputCustomV2b::HEADInputCustom_t & DestHead);
  void InitHeadInputV3a(HEADInputCustomV3a::HEADInputCustom_t & DestHead);
  void InitHeadInputV3b(HEADInputCustomV3b::HEADInputCustom_t & DestHead);
  void InitHeadInputV4a(HEADInputCustomV4a::HEADInputCustom_t & DestHead);
  void InitHeadInputV4b(HEADInputCustomV4b::HEADInputCustom_t & DestHead);
  void InitHeadInputV7(HEADInputCustomV7::HEADInputCustom_t & DestHead);
  void InitHeadInputV7_D1(HEADInputCustomV7_D1::HEADInputCustom_t & DestHead);
  void InitHeadInputV8(HEADInputCustomV8::HEADInputCustom_t & DestHead);
  void InitHeadInputV8a(HEADInputCustomV8a::HEADInputCustom_t & DestHead);
  void InitHeadInputV9(HEADInputCustomV9::HEADInputCustom_t & DestHead);
  void InitHeadInputV9a(HEADInputCustomV9a::HEADInputCustom_t & DestHead);
  void InitHeadInputV9_GY(HEADInputCustomV9_GY::HEADInputCustom_t & DestHead);
  void InitHeadInputV9_MI(HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void InitHeadInputV10(HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void InitHeadInputV10_2(HEADInputCustomV10_2::HEADInputCustom_t & DestHead);

  void ConvertToV1(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead);
  void ConvertToV1(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead);
  void ConvertToV1(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead);
  void ConvertToV1(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead);
  void ConvertToV1(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead);
  void ConvertToV1(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead);

  void ConvertToV2a(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead);
  void ConvertToV2a(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead);
  void ConvertToV2a(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead);
  void ConvertToV2a(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead);
  void ConvertToV2a(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead);
  void ConvertToV2a(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead);

  void ConvertToV2b(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead);
  void ConvertToV2b(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead);
  void ConvertToV2b(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead);
  void ConvertToV2b(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead);
  void ConvertToV2b(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead);
  void ConvertToV2b(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead);

  void ConvertToV3a(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead);
  void ConvertToV3a(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead);
  void ConvertToV3a(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead);
  void ConvertToV3a(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead);
  void ConvertToV3a(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead);
  void ConvertToV3a(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead);

  void ConvertToV3b(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead);
  void ConvertToV3b(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead);
  void ConvertToV3b(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead);
  void ConvertToV3b(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead);
  void ConvertToV3b(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead);
  void ConvertToV3b(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead);

  void ConvertToV4a(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead);
  void ConvertToV4a(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead);
  void ConvertToV4a(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead);
  void ConvertToV4a(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead);
  void ConvertToV4a(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead);
  void ConvertToV4a(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead);

  void ConvertToV4b(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead);
  void ConvertToV4b(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead);
  void ConvertToV4b(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead);
  void ConvertToV4b(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead);
  void ConvertToV4b(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead);
  void ConvertToV4b(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead);

  void ConvertToV8(const HEADInputCustomV9_GY::HEADInputCustom_t &SrcHead, HEADInputCustomV8::HEADInputCustom_t & DestHead);
  void ConvertToV8(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV8::HEADInputCustom_t & DestHead);

  void ConvertToV8a(const HEADInputCustomV9a::HEADInputCustom_t &SrcHead, HEADInputCustomV8a::HEADInputCustom_t & DestHead);
  void ConvertToV8a(const HEADInputCustomV8::HEADInputCustom_t &SrcHead, HEADInputCustomV8a::HEADInputCustom_t & DestHead);
  void ConvertToV8a(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV8a::HEADInputCustom_t & DestHead);

  void ConvertToV9a(const HEADInputCustomV8a::HEADInputCustom_t &SrcHead, HEADInputCustomV9a::HEADInputCustom_t & DestHead);
  void ConvertToV9a(const HEADInputCustomV8::HEADInputCustom_t &SrcHead, HEADInputCustomV9a::HEADInputCustom_t & DestHead);
  void ConvertToV9a(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV9a::HEADInputCustom_t & DestHead);

  void ConvertToV9_GY(const HEADInputCustomV8::HEADInputCustom_t &SrcHead, HEADInputCustomV9_GY::HEADInputCustom_t & DestHead);
  void ConvertToV9_GY(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV9_GY::HEADInputCustom_t & DestHead);

  void ConvertToV9_MI(const HEADInputCustomV1::HEADInputCustom_t &SrcHead,    HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV7::HEADInputCustom_t &SrcHead,    HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV7_D1::HEADInputCustom_t &SrcHead, HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV8::HEADInputCustom_t &SrcHead,    HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV8a::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV9::HEADInputCustom_t &SrcHead,    HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV9a::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV9_GY::HEADInputCustom_t &SrcHead, HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV10::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);
  void ConvertToV9_MI(const HEADInputCustomV10_2::HEADInputCustom_t &SrcHead, HEADInputCustomV9_MI::HEADInputCustom_t & DestHead);

  void ConvertToV10(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void ConvertToV10(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void ConvertToV10(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void ConvertToV10(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void ConvertToV10(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void ConvertToV10(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void ConvertToV10(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void ConvertToV10(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void ConvertToV10(const HEADInputCustomV8::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void ConvertToV10(const HEADInputCustomV8a::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);
  void ConvertToV10(const HEADInputCustomV9_GY::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead);

  void ConvertToV10_2(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV8::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV8a::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV9::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV9_GY::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);
  void ConvertToV10_2(const HEADInputCustomV10::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead);

public:

  static const char* GetConverterTypeName()
  {
    return "HEADInputCustom";
  }

  CConvHeadInputCustom(void);
  virtual ~CConvHeadInputCustom(void);

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
  static CVersionInfoImpl HEAD_INPUT_VERSION_V1;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V2a;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V2b;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V3a;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V3b;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V4a;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V4b;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V7;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V7_D1;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V8;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V8a;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V9;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V9a;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V9_GY;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V9_MI;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V10;
  static CVersionInfoImpl HEAD_INPUT_VERSION_V10_2;

  enum eHeadInputVersions
  {
    HEAD_INPUT_STRUCT_V1     = 0,
    HEAD_INPUT_STRUCT_V2a    = 1,
    HEAD_INPUT_STRUCT_V2b    = 2,
    HEAD_INPUT_STRUCT_V3a    = 3,
    HEAD_INPUT_STRUCT_V3b    = 4,
    HEAD_INPUT_STRUCT_V4a    = 5,
    HEAD_INPUT_STRUCT_V4b    = 6,
    HEAD_INPUT_STRUCT_V7     = 7,
    HEAD_INPUT_STRUCT_V7_D1  = 8,
    HEAD_INPUT_STRUCT_V8     = 9,
    HEAD_INPUT_STRUCT_V8a    = 10,
    HEAD_INPUT_STRUCT_V9     = 11,
    HEAD_INPUT_STRUCT_V9a    = 12,
    HEAD_INPUT_STRUCT_V9_GY  = 13,
    HEAD_INPUT_STRUCT_V9_MI  = 14,
    HEAD_INPUT_STRUCT_V10    = 15,
    HEAD_INPUT_STRUCT_V10_2  = 16,
    HEAD_INPUT_VERSION_COUNT
  };
  static unsigned long SUPPORTED_SIZE[HEAD_INPUT_VERSION_COUNT];

  static const CVersionInfoImpl * const HEAD_INPUT_VERSIONS[HEAD_INPUT_VERSION_COUNT];
};

CVersionInfoImpl CConvHeadInputCustom::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V1(0, 0, 1);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V2a(0, 0, 2);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V2b(0, 0, 2);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V3a(0, 0, 3);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V3b(0, 0, 3);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V4a(0, 0, 4);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V4b(0, 0, 4);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V7(0, 0, 7);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V7_D1(0, 0, 7);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V8(0, 0, 8);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V8a(0, 0, 8);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V9(0, 0, 9);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V9a(0, 0, 9);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V9_GY(0, 0, 9);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V9_MI(0, 0, 9);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V10(0, 0, 10);
CVersionInfoImpl CConvHeadInputCustom::HEAD_INPUT_VERSION_V10_2(0, 0, 10);

unsigned long CConvHeadInputCustom::SUPPORTED_SIZE[CConvHeadInputCustom::HEAD_INPUT_VERSION_COUNT]= {
  sizeof(HEADInputCustomV1::HEADInputCustom_t),
  sizeof(HEADInputCustomV2a::HEADInputCustom_t),
  sizeof(HEADInputCustomV2b::HEADInputCustom_t),
  sizeof(HEADInputCustomV3a::HEADInputCustom_t),
  sizeof(HEADInputCustomV3b::HEADInputCustom_t),
  sizeof(HEADInputCustomV4a::HEADInputCustom_t),
  sizeof(HEADInputCustomV4b::HEADInputCustom_t),
  sizeof(HEADInputCustomV7::HEADInputCustom_t),
  sizeof(HEADInputCustomV7_D1::HEADInputCustom_t),
  sizeof(HEADInputCustomV8::HEADInputCustom_t),
  sizeof(HEADInputCustomV8a::HEADInputCustom_t),
  sizeof(HEADInputCustomV9::HEADInputCustom_t),
  sizeof(HEADInputCustomV9a::HEADInputCustom_t),
  sizeof(HEADInputCustomV9_GY::HEADInputCustom_t),
  sizeof(HEADInputCustomV9_MI::HEADInputCustom_t),
  sizeof(HEADInputCustomV10::HEADInputCustom_t),
  sizeof(HEADInputCustomV10_2::HEADInputCustom_t)
};

const CVersionInfoImpl * const CConvHeadInputCustom::HEAD_INPUT_VERSIONS[CConvHeadInputCustom::HEAD_INPUT_VERSION_COUNT] =
{
  &HEAD_INPUT_VERSION_V1,
  &HEAD_INPUT_VERSION_V2a,
  &HEAD_INPUT_VERSION_V2b,
  &HEAD_INPUT_VERSION_V3a,
  &HEAD_INPUT_VERSION_V3b,
  &HEAD_INPUT_VERSION_V4a,
  &HEAD_INPUT_VERSION_V4b,
  &HEAD_INPUT_VERSION_V7,
  &HEAD_INPUT_VERSION_V7_D1,
  &HEAD_INPUT_VERSION_V8,
  &HEAD_INPUT_VERSION_V8a,
  &HEAD_INPUT_VERSION_V9,
  &HEAD_INPUT_VERSION_V9a,
  &HEAD_INPUT_VERSION_V9_GY,
  &HEAD_INPUT_VERSION_V9_MI,
  &HEAD_INPUT_VERSION_V10,
  &HEAD_INPUT_VERSION_V10_2
};

CConvHeadInputCustom::CConvHeadInputCustom(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT),
  m_HeadInputCustomV1(),
  m_HeadInputCustomV2a(),
  m_HeadInputCustomV2b(),
  m_HeadInputCustomV3a(),
  m_HeadInputCustomV3b(),
  m_HeadInputCustomV4a(),
  m_HeadInputCustomV4b(),
  m_HeadInputCustomV7(),
  m_HeadInputCustomV7_D1(),
  m_HeadInputCustomV8(),
  m_HeadInputCustomV8a(),
  m_HeadInputCustomV9(),
  m_HeadInputCustomV9a(),
  m_HeadInputCustomV9_GY(),
  m_HeadInputCustomV9_MI(),
  m_HeadInputCustomV10(),
  m_HeadInputCustomV10_2()
{
  InitHeadInputV1(m_HeadInputCustomV1);
  InitHeadInputV2a(m_HeadInputCustomV2a);
  InitHeadInputV2b(m_HeadInputCustomV2b);
  InitHeadInputV3a(m_HeadInputCustomV3a);
  InitHeadInputV3b(m_HeadInputCustomV3b);
  InitHeadInputV4a(m_HeadInputCustomV4a);
  InitHeadInputV4b(m_HeadInputCustomV4b);
  InitHeadInputV7(m_HeadInputCustomV7);
  InitHeadInputV7_D1(m_HeadInputCustomV7_D1);
  InitHeadInputV8(m_HeadInputCustomV8);
  InitHeadInputV8a(m_HeadInputCustomV8a);
  InitHeadInputV9(m_HeadInputCustomV9);
  InitHeadInputV9a(m_HeadInputCustomV9a);
  InitHeadInputV9_GY(m_HeadInputCustomV9_GY);
  InitHeadInputV9_MI(m_HeadInputCustomV9_MI);
  InitHeadInputV10(m_HeadInputCustomV10);
  InitHeadInputV10_2(m_HeadInputCustomV10_2);
}

CConvHeadInputCustom::~CConvHeadInputCustom(void)
{
}


void CConvHeadInputCustom::InitHeadInputV1(HEADInputCustomV1::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 1;

  DestHead.CodingByte           = 0x00;
  DestHead.CodingByteValid      = FALSE;
  DestHead.ucCameraObjectStatus = 0x00;
  DestHead.ucCameraStatus       = 0x00;
}

void CConvHeadInputCustom::InitHeadInputV2a(HEADInputCustomV2a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2;

  DestHead.CodingParam           = 0x00;
  DestHead.CodingParamValid      = FALSE;
  DestHead.ucCameraObjectStatus  = 0x00;
  DestHead.ucCameraStatus        = 0x00;
}

void CConvHeadInputCustom::InitHeadInputV2b(HEADInputCustomV2b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2;

  DestHead.CodingParam           = 0x00;
  DestHead.CodingParamValid      = FALSE;
  DestHead.ucCameraObjectStatus  = 0x00;
  DestHead.ucCameraStatus        = 0x00;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
}

void CConvHeadInputCustom::InitHeadInputV3a(HEADInputCustomV3a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2;

  DestHead.CodingParam           = 0x00;
  DestHead.CodingParamValid      = FALSE;
  DestHead.ucCameraObjectStatus  = 0x00;
  DestHead.ucCameraStatus        = 0x00;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
}


void CConvHeadInputCustom::InitHeadInputV3b(HEADInputCustomV3b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3;

  DestHead.CodingParam           = 0x00;
  DestHead.CodingParamValid      = FALSE;
  DestHead.ucCameraObjectStatus  = 0x00;
  DestHead.ucCameraStatus        = 0x00;
}

void CConvHeadInputCustom::InitHeadInputV4a(HEADInputCustomV4a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4;

  DestHead.CodingParam           = 0x00;
  DestHead.CodingParamValid      = FALSE;
  DestHead.ucCameraObjectStatus  = 0x00;
  DestHead.ucCameraStatus        = 0x00;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;
}

void CConvHeadInputCustom::InitHeadInputV4b(HEADInputCustomV4b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4;

  DestHead.CodingParam           = 0x00;
  DestHead.CodingParamValid      = FALSE;
  DestHead.ucCameraObjectStatus  = 0x00;
  DestHead.ucCameraStatus        = 0x00;
}


void CConvHeadInputCustom::InitHeadInputV7(HEADInputCustomV7::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 7;

  DestHead.CodingParam           = 0x00;
  DestHead.CodingParamValid      = FALSE;
  DestHead.ucCameraObjectStatus  = 0x00;
  DestHead.ucCameraStatus        = 0x00;

  DestHead.sSigHeader.uiTimeStamp           = 0;
  DestHead.sSigHeader.uiMeasurementCounter  = 0;
  DestHead.sSigHeader.uiCycleCounter        = 0;
  DestHead.sSigHeader.eSigStatus            = 0;
}


void CConvHeadInputCustom::InitHeadInputV7_D1(HEADInputCustomV7_D1::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 7;

  DestHead.sSigHeader.uiTimeStamp          = 0;
  DestHead.sSigHeader.uiMeasurementCounter = 0;
  DestHead.sSigHeader.uiCycleCounter       = 0;
  DestHead.sSigHeader.eSigStatus           = 0;

  DestHead.CodingParam      = 0x00;
  DestHead.CodingParamValid = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;
}


void CConvHeadInputCustom::InitHeadInputV8(HEADInputCustomV8::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 8;

  DestHead.ucCameraObjectStatus  = 0x00;
  DestHead.ucCameraStatus        = 0x00;

  DestHead.sSigHeader.uiTimeStamp           = 0;
  DestHead.sSigHeader.uiMeasurementCounter  = 0;
  DestHead.sSigHeader.uiCycleCounter        = 0;
  DestHead.sSigHeader.eSigStatus            = 0;
}

void CConvHeadInputCustom::InitHeadInputV8a(HEADInputCustomV8a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 8;

  DestHead.sSigHeader.uiTimeStamp           = 0;
  DestHead.sSigHeader.uiMeasurementCounter  = 0;
  DestHead.sSigHeader.uiCycleCounter        = 0;
  DestHead.sSigHeader.eSigStatus            = 0;

  DestHead.sSpeedometerInput.eSpeedometerUnit =   HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;
}

void CConvHeadInputCustom::InitHeadInputV9(HEADInputCustomV9::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9;
  
  DestHead.ucCameraStatus        = 0x00;
  DestHead.ucCameraObjectStatus  = 0x00;
}

void CConvHeadInputCustom::InitHeadInputV9a(HEADInputCustomV9a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9;

  DestHead.sSigHeader.uiTimeStamp           = 0;
  DestHead.sSigHeader.uiMeasurementCounter  = 0;
  DestHead.sSigHeader.uiCycleCounter        = 0;
  DestHead.sSigHeader.eSigStatus            = 0;

  DestHead.sSpeedometerInput.eSpeedometerUnit =   HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;
  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::InitHeadInputV9_GY(HEADInputCustomV9_GY::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9;

  DestHead.ucCameraObjectStatus  = 0x00;
  DestHead.ucCameraStatus        = 0x00;
  DestHead.eBuzzerState          = 0x00;

  DestHead.sSigHeader.uiTimeStamp           = 0;
  DestHead.sSigHeader.uiMeasurementCounter  = 0;
  DestHead.sSigHeader.uiCycleCounter        = 0;
  DestHead.sSigHeader.eSigStatus            = 0;
}

void CConvHeadInputCustom::InitHeadInputV9_MI(HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9;

  DestHead.sSigHeader.uiTimeStamp          = 0;
  DestHead.sSigHeader.uiMeasurementCounter = 0;
  DestHead.sSigHeader.uiCycleCounter       = 0;
  DestHead.sSigHeader.eSigStatus           = 0;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;
  
  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::InitHeadInputV10(HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10;
  
  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x00;

  DestHead.sSpeedometerInput.eSpeedometerUnit =   HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;

  DestHead.sSigHeader.uiTimeStamp           = 0;
  DestHead.sSigHeader.uiMeasurementCounter  = 0;
  DestHead.sSigHeader.uiCycleCounter        = 0;
  DestHead.sSigHeader.eSigStatus            = 0;
}

void CConvHeadInputCustom::InitHeadInputV10_2(HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10;
  
  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.sSigHeader.uiTimeStamp           = 0;
  DestHead.sSigHeader.uiMeasurementCounter  = 0;
  DestHead.sSigHeader.uiCycleCounter        = 0;
  DestHead.sSigHeader.eSigStatus            = 0;
}

void CConvHeadInputCustom::ConvertToV1(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 1uL;

  DestHead.CodingByteValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus       = SrcHead.ucCameraStatus;
  DestHead.CodingByte           = (uint8) (SrcHead.CodingParam & 0x000000FF);
}

void CConvHeadInputCustom::ConvertToV1(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 1uL;

  DestHead.CodingByteValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus       = SrcHead.ucCameraStatus;
  DestHead.CodingByte           = (uint8) (SrcHead.CodingParam & 0x000000FF);
}

void CConvHeadInputCustom::ConvertToV1(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 1uL;

  DestHead.CodingByteValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus       = SrcHead.ucCameraStatus;
  DestHead.CodingByte           = (uint8) (SrcHead.CodingParam & 0x000000FF);
}

void CConvHeadInputCustom::ConvertToV1(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 1uL;

  DestHead.CodingByteValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus       = SrcHead.ucCameraStatus;
  DestHead.CodingByte           = (uint8) (SrcHead.CodingParam & 0x000000FF);
}

void CConvHeadInputCustom::ConvertToV1(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 1uL;

  DestHead.CodingByteValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus       = SrcHead.ucCameraStatus;
  DestHead.CodingByte           = (uint8) (SrcHead.CodingParam & 0x000000FF);
}

void CConvHeadInputCustom::ConvertToV1(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV1::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 1uL;

  DestHead.CodingByteValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus       = SrcHead.ucCameraStatus;
  DestHead.CodingByte           = (uint8) (SrcHead.CodingParam & 0x000000FF);
}

void CConvHeadInputCustom::ConvertToV2a(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingByteValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = (uint32) SrcHead.CodingByte | 0x80u;
}

void CConvHeadInputCustom::ConvertToV2a(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV2a(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV2a(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV2a(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV2a(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV2a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV2b(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingByteValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = (uint32) SrcHead.CodingByte | 0x80u;
}

void CConvHeadInputCustom::ConvertToV2b(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV2b(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = SrcHead.sCMBInput.bFCMMainSwitch;
  DestHead.sCMBInput.bFCMHistValid  = SrcHead.sCMBInput.bFCMHistValid;
  DestHead.sCMBInput.eFCMStateHist  = SrcHead.sCMBInput.eFCMStateHist;
  DestHead.sCMBInput.eFCMTimingHist = SrcHead.sCMBInput.eFCMTimingHist;
}

void CConvHeadInputCustom::ConvertToV2b(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
}

void CConvHeadInputCustom::ConvertToV2b(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = SrcHead.sCMBInput.bFCMMainSwitch;
  DestHead.sCMBInput.bFCMHistValid  = SrcHead.sCMBInput.bFCMHistValid;
  DestHead.sCMBInput.eFCMStateHist  = SrcHead.sCMBInput.eFCMStateHist;
  DestHead.sCMBInput.eFCMTimingHist = SrcHead.sCMBInput.eFCMTimingHist;
}

void CConvHeadInputCustom::ConvertToV2b(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV2b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 2uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
}

void CConvHeadInputCustom::ConvertToV3a(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingByteValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = (uint32) SrcHead.CodingByte | 0x80u;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
}

void CConvHeadInputCustom::ConvertToV3a(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
}

void CConvHeadInputCustom::ConvertToV3a(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = SrcHead.sCMBInput.bFCMMainSwitch;
  DestHead.sCMBInput.bFCMHistValid  = SrcHead.sCMBInput.bFCMHistValid;
  DestHead.sCMBInput.eFCMStateHist  = SrcHead.sCMBInput.eFCMStateHist;
  DestHead.sCMBInput.eFCMTimingHist = SrcHead.sCMBInput.eFCMTimingHist;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
}

void CConvHeadInputCustom::ConvertToV3a(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
}

void CConvHeadInputCustom::ConvertToV3a(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = SrcHead.sCMBInput.bFCMMainSwitch;
  DestHead.sCMBInput.bFCMHistValid  = SrcHead.sCMBInput.bFCMHistValid;
  DestHead.sCMBInput.eFCMStateHist  = SrcHead.sCMBInput.eFCMStateHist;
  DestHead.sCMBInput.eFCMTimingHist = SrcHead.sCMBInput.eFCMTimingHist;
  DestHead.sCMBInput.bFCMShiftPos   = SrcHead.sCMBInput.bFCMShiftPos;
}

void CConvHeadInputCustom::ConvertToV3a(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV3a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
}

void CConvHeadInputCustom::ConvertToV3b(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingByteValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = (uint32) SrcHead.CodingByte | 0x80u;
}

void CConvHeadInputCustom::ConvertToV3b(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV3b(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV3b(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV3b(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV3b(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV3b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 3uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV4a(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingByteValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = (uint32) SrcHead.CodingByte | 0x80u;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;
}

void CConvHeadInputCustom::ConvertToV4a(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;
}

void CConvHeadInputCustom::ConvertToV4a(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = SrcHead.sCMBInput.bFCMMainSwitch;
  DestHead.sCMBInput.bFCMHistValid  = SrcHead.sCMBInput.bFCMHistValid;
  DestHead.sCMBInput.eFCMStateHist  = SrcHead.sCMBInput.eFCMStateHist;
  DestHead.sCMBInput.eFCMTimingHist = SrcHead.sCMBInput.eFCMTimingHist;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;
}

void CConvHeadInputCustom::ConvertToV4a(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = SrcHead.sCMBInput.bFCMMainSwitch;
  DestHead.sCMBInput.bFCMHistValid  = SrcHead.sCMBInput.bFCMHistValid;
  DestHead.sCMBInput.eFCMStateHist  = SrcHead.sCMBInput.eFCMStateHist;
  DestHead.sCMBInput.eFCMTimingHist = SrcHead.sCMBInput.eFCMTimingHist;
  DestHead.sCMBInput.bFCMShiftPos   = SrcHead.sCMBInput.bFCMShiftPos;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;
}

void CConvHeadInputCustom::ConvertToV4a(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;
}

void CConvHeadInputCustom::ConvertToV4a(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV4a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;

  DestHead.sCMBInput.bFCMMainSwitch = FALSE;
  DestHead.sCMBInput.bFCMHistValid  = TRUE;
  DestHead.sCMBInput.eFCMStateHist  = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMShiftPos   = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;
}

void CConvHeadInputCustom::ConvertToV4b(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingByteValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = (uint32) SrcHead.CodingByte | 0x80u;
}

void CConvHeadInputCustom::ConvertToV4b(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV4b(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV4b(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV4b(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV4b(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV4b::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 4uL;

  DestHead.CodingParamValid      = SrcHead.CodingParamValid;
  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.CodingParam           = SrcHead.CodingParam;
}

void CConvHeadInputCustom::ConvertToV8(const HEADInputCustomV9_GY::HEADInputCustom_t &SrcHead, HEADInputCustomV8::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 8uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
}

void CConvHeadInputCustom::ConvertToV8(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV8::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 8uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
}


void CConvHeadInputCustom::ConvertToV8a(const HEADInputCustomV9a::HEADInputCustom_t &SrcHead, HEADInputCustomV8a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 8uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sSpeedometerInput.eSpeedometerUnit = SrcHead.sSpeedometerInput.eSpeedometerUnit;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = SrcHead.sSpeedometerInput.fSpeedometerSpeed; // to do use vdy velocity
}

void CConvHeadInputCustom::ConvertToV8a(const HEADInputCustomV8::HEADInputCustom_t &SrcHead, HEADInputCustomV8a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 8uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sSpeedometerInput.eSpeedometerUnit =   HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity
}


void CConvHeadInputCustom::ConvertToV8a(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV8a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 8uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sSpeedometerInput.eSpeedometerUnit =   HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity
}


void CConvHeadInputCustom::ConvertToV9a(const HEADInputCustomV8a::HEADInputCustom_t &SrcHead, HEADInputCustomV9a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sSpeedometerInput.eSpeedometerUnit = SrcHead.sSpeedometerInput.eSpeedometerUnit;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = SrcHead.sSpeedometerInput.fSpeedometerSpeed; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV9a(const HEADInputCustomV8::HEADInputCustom_t &SrcHead, HEADInputCustomV9a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sSpeedometerInput.eSpeedometerUnit = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV9a(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV9a::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sSpeedometerInput.eSpeedometerUnit = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}


void CConvHeadInputCustom::ConvertToV9_GY(const HEADInputCustomV8::HEADInputCustom_t &SrcHead, HEADInputCustomV9_GY::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.eBuzzerState          = 0x0;
}

void CConvHeadInputCustom::ConvertToV9_GY(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV9_GY::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.ucCameraObjectStatus  = SrcHead.ucCameraObjectStatus;
  DestHead.ucCameraStatus        = SrcHead.ucCameraStatus;
  DestHead.eBuzzerState          = 0x0;
}

void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV1::HEADInputCustom_t &SrcHead,    HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sCMBInput.bFCMMainSwitch       = SrcHead.sCMBInput.bFCMMainSwitch;
  DestHead.sCMBInput.eFCMStateHist        = SrcHead.sCMBInput.eFCMStateHist;
  DestHead.sCMBInput.eFCMTimingHist       = SrcHead.sCMBInput.eFCMTimingHist;
  DestHead.sCMBInput.bFCMHistValid        = SrcHead.sCMBInput.bFCMHistValid;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sCMBInput.bFCMMainSwitch       = SrcHead.sCMBInput.bFCMMainSwitch;
  DestHead.sCMBInput.eFCMStateHist        = SrcHead.sCMBInput.eFCMStateHist;
  DestHead.sCMBInput.eFCMTimingHist       = SrcHead.sCMBInput.eFCMTimingHist;
  DestHead.sCMBInput.bFCMHistValid        = SrcHead.sCMBInput.bFCMHistValid;
  DestHead.sCMBInput.bFCMShiftPos         = SrcHead.sCMBInput.bFCMShiftPos;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sCMBInput.bFCMMainSwitch       = SrcHead.sCMBInput.bFCMMainSwitch;
  DestHead.sCMBInput.eFCMStateHist        = SrcHead.sCMBInput.eFCMStateHist;
  DestHead.sCMBInput.eFCMTimingHist       = SrcHead.sCMBInput.eFCMTimingHist;
  DestHead.sCMBInput.bFCMHistValid        = SrcHead.sCMBInput.bFCMHistValid;
  DestHead.sCMBInput.bFCMShiftPos         = SrcHead.sCMBInput.bFCMShiftPos;
  DestHead.sCMBInput.bFCMSysSilentInhibit = SrcHead.sCMBInput.bFCMSysSilentInhibit;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV7::HEADInputCustom_t &SrcHead,    HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV7_D1::HEADInputCustom_t &SrcHead,    HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = SrcHead.sSpeedometerInput.eSpeedometerUnit;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = SrcHead.sSpeedometerInput.fSpeedometerSpeed;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV8::HEADInputCustom_t &SrcHead,    HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV8a::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = SrcHead.sSpeedometerInput.eSpeedometerUnit;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = SrcHead.sSpeedometerInput.fSpeedometerSpeed;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV9::HEADInputCustom_t &SrcHead,    HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV9a::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = SrcHead.sSpeedometerInput.eSpeedometerUnit;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = SrcHead.sSpeedometerInput.fSpeedometerSpeed;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = SrcHead.sExtVehicleSystems.bVehStopCoordActive;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV9_GY::HEADInputCustom_t &SrcHead, HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV10::HEADInputCustom_t &SrcHead,   HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = SrcHead.sSpeedometerInput.eSpeedometerUnit;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = SrcHead.sSpeedometerInput.fSpeedometerSpeed;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = SrcHead.sExtVehicleSystems.bVehStopCoordActive;
}
void CConvHeadInputCustom::ConvertToV9_MI(const HEADInputCustomV10_2::HEADInputCustom_t &SrcHead, HEADInputCustomV9_MI::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 9uL;

  DestHead.sSigHeader = SrcHead.sSigHeader;

  DestHead.sCMBInput.bFCMMainSwitch       = FALSE;
  DestHead.sCMBInput.eFCMStateHist        = eFCMStateHist_Standby;
  DestHead.sCMBInput.eFCMTimingHist       = eFCMTimingHist_Far;
  DestHead.sCMBInput.bFCMHistValid        = TRUE;
  DestHead.sCMBInput.bFCMShiftPos         = TRUE;
  DestHead.sCMBInput.bFCMSysSilentInhibit = FALSE;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}


void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x0;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x0;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x0;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x0;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x0;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x0;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x0;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.sSigHeader            = SrcHead.sSigHeader;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x0;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV8::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.sSigHeader            = SrcHead.sSigHeader;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x0;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV8a::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.sSigHeader            = SrcHead.sSigHeader;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = 0x0;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = SrcHead.sSpeedometerInput.eSpeedometerUnit;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = SrcHead.sSpeedometerInput.fSpeedometerSpeed;

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}

void CConvHeadInputCustom::ConvertToV10(const HEADInputCustomV9_GY::HEADInputCustom_t &SrcHead, HEADInputCustomV10::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.sSigHeader            = SrcHead.sSigHeader;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;

  DestHead.eBuzzerState          = SrcHead.eBuzzerState;

  DestHead.sSpeedometerInput.eSpeedometerUnit  = HEADInputCustomV8a::SPD_UNIT_KMH;
  DestHead.sSpeedometerInput.fSpeedometerSpeed = 0; // to do use vdy velocity

  DestHead.sExtVehicleSystems.bVehStopCoordActive = FALSE;
}


void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV1::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV2a::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV2b::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV3a::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV3b::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV4a::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV4b::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV7::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.sSigHeader            = SrcHead.sSigHeader;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV8::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.sSigHeader            = SrcHead.sSigHeader;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV8a::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.sSigHeader            = SrcHead.sSigHeader;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV9::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.sSigHeader            = SrcHead.sSigHeader;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV9_GY::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.sSigHeader            = SrcHead.sSigHeader;

  DestHead.eQualifierBrakeChain = 0;
  DestHead.eQualifierWarnChain  = 0;
  DestHead.eQualifierPrefill    = 0;
  DestHead.eQualifierHBA        = 0;
}

void CConvHeadInputCustom::ConvertToV10_2(const HEADInputCustomV10::HEADInputCustom_t &SrcHead, HEADInputCustomV10_2::HEADInputCustom_t & DestHead)
{
  DestHead.uiVersionNumber = 10uL;

  DestHead.sSigHeader            = SrcHead.sSigHeader;

  DestHead.eQualifierBrakeChain = SrcHead.eQualifierBrakeChain;
  DestHead.eQualifierWarnChain  = SrcHead.eQualifierWarnChain;
  DestHead.eQualifierPrefill    = SrcHead.eQualifierPrefill;
  DestHead.eQualifierHBA        = SrcHead.eQualifierHBA;
}


long CConvHeadInputCustom::ConvertData(
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
    if ((ulRPortSize == ulPPortSize) && (((pProvidePortVersionInfo == NULL) && (requestPortVersionInfo.Equals(&RawVersion))) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))))
    {
      // Ports are equal, use provide port directly
      *pOutData = pPPortData;
      ulOutSize = ulPPortSize;
      lRet = SIM_ERR_OK;
    }
    else
    {
      // Ports are not equal - conversion necessary, first find destination (request port) version
      if ((ulRPortSize == sizeof(HEADInputCustomV10_2::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V10_2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        HEADInputCustomV10_2::HEADInputCustom_t &DestHead = m_HeadInputCustomV10_2;
        
        if ((ulPPortSize == sizeof(HEADInputCustomV9::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V9.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V8.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV9::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV9::HEADInputCustom_t *>(pPPortData);
          ConvertToV10_2(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        if ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V8.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V8.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV8::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV8::HEADInputCustom_t *>(pPPortData);
          ConvertToV10_2(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        if ((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V7.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V7.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV7::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV7::HEADInputCustom_t *>(pPPortData);
          ConvertToV10_2(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV10::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V10)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        HEADInputCustomV10::HEADInputCustom_t &DestHead = m_HeadInputCustomV10;

        if ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V8.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V8.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV8::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV8::HEADInputCustom_t *>(pPPortData);
          ConvertToV10(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        if ((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V7.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V7.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV7::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV7::HEADInputCustom_t *>(pPPortData);
          ConvertToV10(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV9_MI::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9_MI)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        HEADInputCustomV9_MI::HEADInputCustom_t &DestHead = m_HeadInputCustomV9_MI;

        if ((ulPPortSize == sizeof(HEADInputCustomV10_2::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V10_2.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V10_2.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV10_2::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV10_2::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV10::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V10.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V10.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV10::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV10::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V9a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V9a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV9a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV9a::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV9::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V9.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V9.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV9::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV9::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V8a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V8a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV8a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV8a::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V8.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V8.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV8::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV8::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV7_D1::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V7_D1.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V7_D1.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV7_D1::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV7_D1::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }                
        else if ((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V7.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V7.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV7::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV7::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV4b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4b::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4a::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3b::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3a::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2b::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2a::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }        
        else if ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V1.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V1.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV1::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV1::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_MI(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV9_GY::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9_GY)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        HEADInputCustomV9_GY::HEADInputCustom_t &DestHead = m_HeadInputCustomV9_GY;

        if ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V8.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V8.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV8::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV8::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_GY(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        if ((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V7.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V7.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV7::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV7::HEADInputCustom_t *>(pPPortData);
          ConvertToV9_GY(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        HEADInputCustomV9a::HEADInputCustom_t &DestHead = m_HeadInputCustomV9a;

        if ((ulPPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V8a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V8a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV8a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV8a::HEADInputCustom_t *>(pPPortData);
          ConvertToV9a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        if ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V8.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V8.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV8::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV8::HEADInputCustom_t *>(pPPortData);
          ConvertToV9a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        if ((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V7.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V7.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV7::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV7::HEADInputCustom_t *>(pPPortData);
          ConvertToV9a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V8)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        HEADInputCustomV8::HEADInputCustom_t &DestHead = m_HeadInputCustomV8;

        if ((ulPPortSize == sizeof(HEADInputCustomV9_GY::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V9_GY.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V9_GY.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV9_GY::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV9_GY::HEADInputCustom_t *>(pPPortData);
          ConvertToV8(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        if ((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V7.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V7.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV7::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV7::HEADInputCustom_t *>(pPPortData);
          ConvertToV8(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V8a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V4a of head input custom
        HEADInputCustomV8a::HEADInputCustom_t &DestHead = m_HeadInputCustomV8a;
        if ((ulPPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V9a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V9a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV9a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV9a::HEADInputCustom_t *>(pPPortData);
          ConvertToV8a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V8.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V1.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV8::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV8::HEADInputCustom_t *>(pPPortData);
          ConvertToV8a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V7.Equals(&RawVersion)))
        {
          const HEADInputCustomV7::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV7::HEADInputCustom_t *>(pPPortData);
          ConvertToV8a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }

      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V4a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V4a of head input custom
        HEADInputCustomV4a::HEADInputCustom_t &DestHead = m_HeadInputCustomV4a;
        if ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V1.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V1.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV1::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV1::HEADInputCustom_t *>(pPPortData);
          ConvertToV4a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2a::HEADInputCustom_t *>(pPPortData);
          ConvertToV4a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2b::HEADInputCustom_t *>(pPPortData);
          ConvertToV4a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3a::HEADInputCustom_t *>(pPPortData);
          ConvertToV4a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3b::HEADInputCustom_t *>(pPPortData);
          ConvertToV4a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV4b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4b::HEADInputCustom_t *>(pPPortData);
          ConvertToV4a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV4b::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V4b)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V4b of head input custom
        HEADInputCustomV4b::HEADInputCustom_t &DestHead = m_HeadInputCustomV4b;
        if ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V1.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V1.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV1::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV1::HEADInputCustom_t *>(pPPortData);
          ConvertToV4b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2a::HEADInputCustom_t *>(pPPortData);
          ConvertToV4b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2b::HEADInputCustom_t *>(pPPortData);
          ConvertToV4b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3a::HEADInputCustom_t *>(pPPortData);
          ConvertToV4b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3b::HEADInputCustom_t *>(pPPortData);
          ConvertToV4b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4a::HEADInputCustom_t *>(pPPortData);
          ConvertToV4b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V3b)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V3b of head input custom
        HEADInputCustomV3b::HEADInputCustom_t &DestHead = m_HeadInputCustomV3b;
        if ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V1.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V1.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV1::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV1::HEADInputCustom_t *>(pPPortData);
          ConvertToV3b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2a::HEADInputCustom_t *>(pPPortData);
          ConvertToV3b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2b::HEADInputCustom_t *>(pPPortData);
          ConvertToV3b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3a::HEADInputCustom_t *>(pPPortData);
          ConvertToV3b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4a::HEADInputCustom_t *>(pPPortData);
          ConvertToV3b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV4b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4b::HEADInputCustom_t *>(pPPortData);
          ConvertToV3b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V3a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V3a of head input custom
        HEADInputCustomV3a::HEADInputCustom_t &DestHead = m_HeadInputCustomV3a;
        if ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V1.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V1.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV1::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV1::HEADInputCustom_t *>(pPPortData);
          ConvertToV3a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2a::HEADInputCustom_t *>(pPPortData);
          ConvertToV3a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2b::HEADInputCustom_t *>(pPPortData);
          ConvertToV3a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3b::HEADInputCustom_t *>(pPPortData);
          ConvertToV3a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4a::HEADInputCustom_t *>(pPPortData);
          ConvertToV3a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV4b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4b::HEADInputCustom_t *>(pPPortData);
          ConvertToV3a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V2b)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V2b of head input custom
        HEADInputCustomV2b::HEADInputCustom_t &DestHead = m_HeadInputCustomV2b;
        if ((ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4a::HEADInputCustom_t *>(pPPortData);
          ConvertToV2b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV4b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4b::HEADInputCustom_t *>(pPPortData);
          ConvertToV2b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3b::HEADInputCustom_t *>(pPPortData);
          ConvertToV2b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3a::HEADInputCustom_t *>(pPPortData);
          ConvertToV2b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2a::HEADInputCustom_t *>(pPPortData);
          ConvertToV2b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V1.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V1.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV1::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV1::HEADInputCustom_t *>(pPPortData);
          ConvertToV2b(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V2a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V2a of head input custom
        HEADInputCustomV2a::HEADInputCustom_t &DestHead = m_HeadInputCustomV2a;
        if ((ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4a::HEADInputCustom_t *>(pPPortData);
          ConvertToV2a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV4b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV4b::HEADInputCustom_t *>(pPPortData);
          ConvertToV2a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3b::HEADInputCustom_t *>(pPPortData);
          ConvertToV2a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3a::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV3a::HEADInputCustom_t *>(pPPortData);
          ConvertToV2a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2b::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV2b::HEADInputCustom_t *>(pPPortData);
          ConvertToV2a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V1.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V1.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV1::HEADInputCustom_t &SrcHead = *reinterpret_cast<HEADInputCustomV1::HEADInputCustom_t *>(pPPortData);
          ConvertToV2a(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V1)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V1 of head input
        HEADInputCustomV1::HEADInputCustom_t &DestHead = m_HeadInputCustomV1;
        if ((ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4a::HEADInputCustom_t & SrcHead = *reinterpret_cast<HEADInputCustomV4a::HEADInputCustom_t *>(pPPortData);
          ConvertToV1(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV4b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V4b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V4b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV4b::HEADInputCustom_t & SrcHead = *reinterpret_cast<HEADInputCustomV4b::HEADInputCustom_t *>(pPPortData);
          ConvertToV1(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3b::HEADInputCustom_t & SrcHead = *reinterpret_cast<HEADInputCustomV3b::HEADInputCustom_t *>(pPPortData);
          ConvertToV1(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V3a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V3a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV3a::HEADInputCustom_t & SrcHead = *reinterpret_cast<HEADInputCustomV3a::HEADInputCustom_t *>(pPPortData);
          ConvertToV1(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2a.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2a.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2a::HEADInputCustom_t & SrcHead = *reinterpret_cast<HEADInputCustomV2a::HEADInputCustom_t *>(pPPortData);
          ConvertToV1(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && ((HEAD_INPUT_VERSION_V2b.Equals(&RawVersion)) || (HEAD_INPUT_VERSION_V2b.Equals(pProvidePortVersionInfo))))
        {
          const HEADInputCustomV2b::HEADInputCustom_t & SrcHead = *reinterpret_cast<HEADInputCustomV2b::HEADInputCustom_t *>(pPPortData);
          ConvertToV1(SrcHead, DestHead);
          *pOutData = &DestHead;
          ulOutSize = sizeof(DestHead);
          lRet = SIM_ERR_OK;
        }
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
long CConvHeadInputCustom::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    // Find proper version to use for default value
    if ((ulRPortSize == sizeof(HEADInputCustomV10_2::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V10_2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Initialization of V10_2
      HEADInputCustomV10_2::HEADInputCustom_t &DestHead = m_HeadInputCustomV10_2;
      InitHeadInputV10_2(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV10::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V10)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Initialization of V10
      HEADInputCustomV10::HEADInputCustom_t &DestHead = m_HeadInputCustomV10;
      InitHeadInputV10(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV9_MI::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9_MI)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Initialization of V9_MI
      HEADInputCustomV9_MI::HEADInputCustom_t &DestHead = m_HeadInputCustomV9_MI;
      InitHeadInputV9_MI(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV9_GY::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9_GY)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Initialization of V9_GY
      HEADInputCustomV9_GY::HEADInputCustom_t &DestHead = m_HeadInputCustomV9_GY;
      InitHeadInputV9_GY(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Initialization of V9a
      HEADInputCustomV9a::HEADInputCustom_t &DestHead = m_HeadInputCustomV9a;
      InitHeadInputV9a(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V8a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Initialization of V8a
      HEADInputCustomV8a::HEADInputCustom_t &DestHead = m_HeadInputCustomV8a;
      InitHeadInputV8a(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V8)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Initialization of V8
      HEADInputCustomV8::HEADInputCustom_t &DestHead = m_HeadInputCustomV8;
      InitHeadInputV8(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V7)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Initialization of V7
      HEADInputCustomV7::HEADInputCustom_t &DestHead = m_HeadInputCustomV7;
      InitHeadInputV7(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V4a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Conversion to V4
      HEADInputCustomV4a::HEADInputCustom_t &DestHead = m_HeadInputCustomV4a;
      InitHeadInputV4a(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V3b)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Conversion to V3b
      HEADInputCustomV3b::HEADInputCustom_t &DestHead = m_HeadInputCustomV3b;
      InitHeadInputV3b(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V3a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Conversion to V3a
      HEADInputCustomV3a::HEADInputCustom_t &DestHead = m_HeadInputCustomV3a;
      InitHeadInputV3a(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V2a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Conversion to V2a
      HEADInputCustomV2a::HEADInputCustom_t &DestHead = m_HeadInputCustomV2a;
      InitHeadInputV2a(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V2b)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Conversion to V2b
      HEADInputCustomV2b::HEADInputCustom_t &DestHead = m_HeadInputCustomV2b;
      InitHeadInputV2b(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V1)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      HEADInputCustomV1::HEADInputCustom_t & DestHead = m_HeadInputCustomV1;
      InitHeadInputV1(DestHead);
      *pDefaultData = &DestHead;
      ulDefaultSize = sizeof(DestHead);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvHeadInputCustom::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;

  if (eRPortType == ePPortType)
  {
    if (ulRPortSize == ulPPortSize)
    {
      bResult = true;
    }
    else
    {
      if ((ulRPortSize == sizeof(HEADInputCustomV10_2::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V10_2)))
      {
        if ((ulPPortSize == sizeof(HEADInputCustomV9::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)))
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV10::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V10)))
      {
        if ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)))
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV9_MI::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9_MI)))
      {
        if ((ulPPortSize == sizeof(HEADInputCustomV10_2::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV10::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV9::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV7_D1::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV4b::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)))
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV9_GY::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9_GY)))
      {
        if ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)))
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9a)))
      {
        if ((ulPPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)))
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V8a)))
      {
        if ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)))
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V8)))
      {
        if ( (ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) ||
          (ulPPortSize == sizeof(HEADInputCustomV9_GY::HEADInputCustom_t)))
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V8)))
      {
        if ( (ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)))
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V4a)))
      {
        if( (ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t))
          ||
          (ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t))
          ||
          (ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t))
          ||
          (ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t))
          ||
          (ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t))
          )
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V3b)))
      {
        if( (ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t))
          ||
          (ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t))
          ||
          (ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t))
          ||
          (ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t))
          ||
          (ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t))
          )
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V3a)))
      {
        if( (ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t))
            )
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V2a)))
      {
        if( (ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t))
            )
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V2b)))
      {
        if( (ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t))
            )
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && (requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V1)))
      {
        if( (ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t))
            ||
            (ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t))
            )
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}


// used to check if ports are compatible between different versions
bool CConvHeadInputCustom::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  if (eRPortType == ePPortType)
  {
    if ((ulRPortSize == ulPPortSize) && ((requestPortVersionInfo.Equals(&providePortVersionInfo))) || (providePortVersionInfo.Equals(&BASE_VERSION)) || (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Ports are equal, use provide port directly
      bResult = true;
    }
    else
    {
      // Ports are not equal - conversion necessary, first find destination (request port) version
      if ((ulRPortSize == sizeof(HEADInputCustomV10_2::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V10_2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V10_2
        if(((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V7.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V8.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV9::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V9.Equals(&providePortVersionInfo))) )
        {
          bResult = true;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV10::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V10)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V10
        if(((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V7.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V8.Equals(&providePortVersionInfo))) )
        {
          bResult = true;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV9_MI::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9_MI)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V9_MI
        if(((ulPPortSize == sizeof(HEADInputCustomV10_2::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V10_2.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV10::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V10.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V9a.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV9::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V9.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V8a.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V8.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV7_D1::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V7_D1.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V7.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV4b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V4b.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV4a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V4a.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V3b.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V3a.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V2b.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V2a.Equals(&providePortVersionInfo)))  ||
          ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V1.Equals(&providePortVersionInfo))) )
        {
          bResult = true;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV9_GY::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9_GY)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V9_GY
        if(((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V7.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V8.Equals(&providePortVersionInfo))) )
        {
          bResult = true;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V9a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V9a
        if(((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V7.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V8.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V8a.Equals(&providePortVersionInfo))) )
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V8a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V8a
        if(((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V7.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V8.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V9a.Equals(&providePortVersionInfo))) )
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV8::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V8)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V8
        if(((ulPPortSize == sizeof(HEADInputCustomV7::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V7.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV8a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V8a.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV9a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V9a.Equals(&providePortVersionInfo))) ||
          ((ulPPortSize == sizeof(HEADInputCustomV9_GY::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V9_GY.Equals(&providePortVersionInfo))) )
        {
          bResult = true;
        }
      }

      // Ports are not equal - conversion necessary, first find destination (request port) version
      if ((ulRPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V3b)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V3
        if( ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V1.Equals(&providePortVersionInfo)))
          ||
          ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V2a.Equals(&providePortVersionInfo)))
          ||
          ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V2b.Equals(&providePortVersionInfo)))
          ||
          ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V3a.Equals(&providePortVersionInfo)))
          )
        {
          bResult = true;
        }
      }
      // Ports are not equal - conversion necessary, first find destination (request port) version
      else if ((ulRPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V3a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V3
        if( ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V1.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V2a.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V2b.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V3b.Equals(&providePortVersionInfo)))
          )
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V2a)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V2a
        if( ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V1.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V2b.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V3a.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V3b.Equals(&providePortVersionInfo)))
          )
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V2b)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V2b
        if( ((ulPPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V1.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V2a.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V3a.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V3b.Equals(&providePortVersionInfo)))
          )
        {
          bResult = true;
        }
      }
      else if ((ulRPortSize == sizeof(HEADInputCustomV1::HEADInputCustom_t)) && ((requestPortVersionInfo.Equals(&HEAD_INPUT_VERSION_V1)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
      {
        // Conversion to V1
        if( ((ulPPortSize == sizeof(HEADInputCustomV2a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V2a.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV2b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V2b.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV3a::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V3a.Equals(&providePortVersionInfo)))
            ||
            ((ulPPortSize == sizeof(HEADInputCustomV3b::HEADInputCustom_t)) && (HEAD_INPUT_VERSION_V3b.Equals(&providePortVersionInfo)))
          )
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}

//
// Factory function
//
IConverter * CreateHeadInputCustomConvInstance(void)
{
  return new CConvHeadInputCustom();
}
