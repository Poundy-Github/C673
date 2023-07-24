/*! \file **********************************************************************

COMPANY:              Continental

PROJECT:              Simulation

COMPONENT:            sim_swc_hla_adapter

MODULNAME:            sim_hlar_input_data.h

DESCRIPTION:          

AUTHOR:               Marcus Brunn

CREATION DATE:        03.08.2010

VERSION:              $Revision: 1.1 $

---*/ /*---
CHANGES:              $Log: sim_hlar_input_data.h  $
CHANGES:              Revision 1.1 2021/12/13 17:23:31CET Wang, David (Wangd3) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Converter/HLA/hlar_input/project.pj
CHANGES:              Revision 1.0 2017/03/03 10:35:02CET Sorge, Sven (uidg3181) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Converter/HLA/hlar_input/project.pj
CHANGES:              Revision 1.1.1.2 2014/04/08 13:15:57CEST Sorge, Sven (uidg3181) 
CHANGES:              Added RGBLuxTable Conversion
CHANGES:              - Added comments -  uidg3181 [Apr 8, 2014 1:15:57 PM CEST]
CHANGES:              Change Package : 199693:5 http://mks-psad:7002/im/viewissue?selection=199693
CHANGES:              Revision 1.1.1.1 2014/04/01 10:30:35CEST Sorge-EXT, Sven (uidg3181) 
CHANGES:              Modifications for MFC Wrapepr
CHANGES:              MFC Wrapper ONLY branch
CHANGES:              --- Added comments ---  uidg3181 [Apr 1, 2014 10:30:35 AM CEST]
CHANGES:              Change Package : 217703:2 http://mks-psad:7002/im/viewissue?selection=217703
CHANGES:              Revision 1.1 2014/04/01 09:37:05CEST Sorge-EXT, Sven (uidg3181) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Converter/HLA/hlar_input/project.pj
CHANGES:              Revision 1.1 2014/03/18 16:59:20CET Mutschler, Matthias (uidv7867) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/hla_adapter/hlar_input/project.pj
CHANGES:              Revision 1.27 2014/03/10 17:13:20CET Brunn, Marcus (brunnm) 
CHANGES:              support hlar_in interface  version 2.4.0
CHANGES:              --- Added comments ---  brunnm [Mar 10, 2014 5:13:21 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.26 2014/03/04 18:00:40CET Mutschler, Matthias (uidv7867) 
CHANGES:              Removed ppars and vehpar from RTE and internal interface
CHANGES:              --- Added comments ---  uidv7867 [Mar 4, 2014 6:00:40 PM CET]
CHANGES:              Change Package : 207432:38 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.25 2014/01/30 16:13:16CET Brunn, Marcus (brunnm) 
CHANGES:              adapter update for mfc4xx I320 rec-files
CHANGES:              --- Added comments ---  brunnm [Jan 30, 2014 4:13:16 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.24 2013/09/26 11:21:30CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced specific HLA opmodes by TestMode CPar
CHANGES:              --- Added comments ---  uidv7867 [Sep 26, 2013 11:21:31 AM CEST]
CHANGES:              Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
CHANGES:              Revision 1.23 2013/08/28 11:19:12CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Changed adapter according to new camera parameter struct
CHANGES:              --- Added comments ---  uidv7867 [Aug 28, 2013 11:19:12 AM CEST]
CHANGES:              Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
CHANGES:              Revision 1.22 2013/08/20 10:58:15CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Overwrite brightness of blacklevel if < 0
CHANGES:              --- Added comments ---  uidv7867 [Aug 20, 2013 10:58:15 AM CEST]
CHANGES:              Change Package : 167173:33 http://mks-psad:7002/im/viewissue?selection=167173
**************************************************************************** */
#pragma once
#include "sim_interface_hlar_input_data.h"
#include "sim_converter_base.h"
#include "sim_versioninfo_impl.h"
#include "hlar_ext.h"

class CHlarInputData
{
public:
  CHlarInputData(void);

  ~CHlarInputData(void);

  void SetHlarInputData_v1(HLAR_t_RequiredInputs_v1* pIn, HLAR_t_RequiredInputs* pIn_Out);
  void SetHlarInputData_v2(HLAR_t_RequiredInputs_v2* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v3(HLAR_t_RequiredInputs_v3* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v4(HLAR_t_RequiredInputs_v3* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v5(HLAR_t_RequiredInputs_v4* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v6(HLAR_t_RequiredInputs_v5* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v7(HLAR_t_RequiredInputs_v6* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v8(HLAR_t_RequiredInputs_v7* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v9(HLAR_t_RequiredInputs_v8* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v10(HLAR_t_RequiredInputs_v9* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v11(HLAR_t_RequiredInputs_v10* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v12(HLAR_t_RequiredInputs_v11* pIn, HLAR_t_RequiredInputs* pIn_Out);
  uint32 SetHlarInputData_v13(HLAR_t_RequiredInputs_v12* pIn, HLAR_t_RequiredInputs* pIn_Out);

  static CVersionInfoImpl BASE_VERSION;
  enum eVersions
  {
    HLAR_IN_V1_1 = 0,
    HLAR_IN_V1_2 = 1,
    HLAR_IN_V2   = 2,
    HLAR_IN_V3   = 3,
    HLAR_IN_V4   = 4,
    HLAR_IN_V5   = 5,
    HLAR_IN_V6   = 6,
    HLAR_IN_V7   = 7,
    HLAR_IN_V8   = 8,
    HLAR_IN_V9   = 9,
    HLAR_IN_V10  = 10,
    HLAR_IN_V11  = 11,
    HLAR_IN_V12  = 12,
    HLAR_IN_V13  = 13,
    HLAR_IN_ORIG = 14,
    HLAR_IN_VER_COUNT
  };
  static unsigned long SUPPORTED_SIZE[HLAR_IN_VER_COUNT];
  static unsigned long SUPPORTED_VERSION[HLAR_IN_VER_COUNT];

private:

  void Set_HLA_CameraParameter_PreCheck_v1(float32 *f32_RatioRedGreen,
                                           float32 *f32_RatioBlueGreen,
                                           float32 *f32_RatioGreenRef,
                                           float32 *f32_T1_us,
                                           float32 *f32_T2_us,
                                           float32 *f32_T3_us,
                                           uint32  *ui32_R1,
                                           uint32  *ui32_R2,
                                           HLA_t_CalibratedRGBLuxTable_v3 *s_RGBLuxTable,
                                           HLA_t_ImagerResponseCurve_v1 &s_ResponseCurve
                                          );

  void SetRgbLuxTable(HLA_t_CalibratedRGBLuxTable *destRGBLuxTable,
                    uint32                      ui32_R1,
                    uint32                      ui32_R2,
                    float32                     f32_T1_us,
                    float32                     f32_T2_us,
                    float32                     f32_T3_us,
                    float32                     f32_Gain,
                    float32                     f32_RatioRedGreen,
                    float32                     f32_RatioBlueGreen,
                    float32                     f32_RatioGreenRef,
                    uint32                      ui32_tableLength,
                    HLA_t_RGBLuxElement_v1      *pRGBLuxTable);

  RTE_HLA_LightStyle Convert_HLA_eLightStyle_v1(HLA_t_enum8 e_LightStyle);
  RTE_HLA_LightStyle Convert_HLA_eLightStyle_v2(HLA_t_enum8 e_LightStyle);
  RTE_HLA_HeadlightType Convert_HLA_eHeadLightType_v1(HLA_t_enum8 e_HeadLightType);
  RTE_HLA_HeadLightMechanics Convert_HLA_eHeadLightMechanics_v1(HLA_t_enum8 e_HeadLightMechanics);
  RTE_HLA_SpotLight Convert_HLA_eSpotLight_v1(HLA_t_enum8 eSpotLight);
  RTE_HLA_WindshieldType Convert_HLA_eWindshieldType_v1(HLA_t_enum8 eWindshieldType);
  RTE_HLAR_DefectPixelType Convert_HLA_eDefectPixelType_v1(HLA_t_enum8 eDefectPixelType);
  RTE_HLA_LightModuleState Convert_HLA_eLightModuleState_v1(HLA_t_enum8 eLightModuleState);
  RTE_HLA_LightModuleState Convert_HLA_eLightModuleState_v2(HLA_t_enum8 eLightModuleState);
  RTE_HLA_GlareReductionState Convert_HLA_eGlareReductionState_v1(HLA_t_enum8 eGlareReductionState);
  RTE_HLA_GlareReductionState Convert_HLA_eGlareReductionState_v2(HLA_t_enum8 eGlareReductionState);
  HLA_t_eWiperWasherState Convert_HLA_eWiperWasherState_v1(HLA_t_enum8 eWiperWasherState);
  HLA_t_eWiperStage CHlarInputData::Convert_HLA_eWiperStage_v1(HLA_t_enum8 eWiperStage);
  HLA_t_eMovementState CHlarInputData::Convert_HLA_eMovementState_v1(HLA_t_enum8 eMovementState);
  HLA_t_eActiveChar CHlarInputData::Convert_HLA_eActiveChar_v1(HLA_t_enum8 eActiveChar);
  HLA_t_eBayerPatternType CHlarInputData::Convert_HLA_eBayerPatternType_v1(HLA_t_enum8 eBayerPatternType);
  HLA_t_eBayerPatternType CHlarInputData::Convert_HLA_eBayerPatternType_v2(HLA_t_enum8 eBayerPatternType);

};
