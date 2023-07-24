/*! \file **********************************************************************

  COMPANY:                   Continental(AG)

  PROJECT:                   ARS3xx()

  CPU:                       Intel(x86)

  COMPONENT:                 SIMULATION

  MODULNAME:                 sim_conv_vdy_input_data_veh_sig.cpp

  DESCRIPTION:               Conversion of VehSig

  AUTHOR:                    

  CREATION DATE:             11.04.2012

  VERSION:                   $Revision: 1.1 $

  CHANGES:
  ---*/ /*---
  CHANGE:                    $Log: sim_conv_vdy_input_data_veh_sig.cpp  $
  CHANGE:                    Revision 1.1 2021/12/13 17:21:53CET Wang, David (Wangd3) 
  CHANGE:                    Initial revision
  CHANGE:                    Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/vdy/project.pj
  CHANGE:                    Revision 1.1 2017/08/10 13:15:40CEST uid34177 
  CHANGE:                    Initial revision
  CHANGE:                    Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/vdy/project.pj
  CHANGE:                    Revision 1.21.1.5 2016/02/05 10:51:27CET Berndt, Thomas01 (berndtt1) 
  CHANGE:                    New Velocity monitoring based on new minimum and maximum velocity signals for ARS4D1 and ARS4D2
  CHANGE:                    Interface V11
  CHANGE:                    Copied from 418300:1
  CHANGE:                    Revision 1.21.1.4 2014/12/12 11:24:27CET Berndt, Thomas01 (berndtt1) 
  CHANGE:                    * moved to be affective in "sim_conv_vdy_input_data_veh_sig.h": #include "sim_adapter_cfg.h"
  CHANGE:                    - Added comments -  berndtt1 [Dec 12, 2014 11:35:56 AM CET]
  CHANGE:                    Change Package : 221167:44 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGE:                    Revision 1.21.1.3 2014/10/30 17:51:07CET Manea, Gabriela (ManeaG) 
  CHANGE:                    Updated with conversions for V10
  CHANGE:                    --- Added comments ---  ManeaG [Oct 30, 2014 5:51:08 PM CET]
  CHANGE:                    Change Package : 263320:1 http://mks-psad:7002/im/viewissue?selection=263320
  CHANGE:                    Revision 1.21.1.2 2014/06/27 10:17:18CEST Manea, Gabriela (ManeaG) 
  CHANGE:                    Updated with conversions for V9
  CHANGE:                    --- Added comments ---  ManeaG [Jun 27, 2014 10:17:18 AM CEST]
  CHANGE:                    Change Package : 212023:2 http://mks-psad:7002/im/viewissue?selection=212023
  CHANGE:                    Revision 1.24 2014/06/16 11:19:41CEST Wolter, Frank (wolterf) 
  CHANGE:                    Changed for MFC300 ReSim:
  CHANGE:                    - added conversion of VehSigAdd from V1 into V2
  CHANGE:                    - implementeded conversion of WiperStage based on WiperState signal
  CHANGE:                    - changed conversion of VehSigAdd signal in V5 into V6 and V6 into V5, using now signal values instead of default values
  CHANGE:                    --- Added comments ---  wolterf [Jun 16, 2014 11:19:41 AM CEST]
  CHANGE:                    Change Package : 242786:1 http://mks-psad:7002/im/viewissue?selection=242786
  CHANGE:                    Revision 1.23 2014/05/06 16:58:33CEST Wolter, Frank (wolterf) 
  CHANGE:                    - changed handling if ulPPortSize is 0
  CHANGE:                    - removed compiler warnings
  CHANGE:                    --- Added comments ---  wolterf [May 6, 2014 4:58:33 PM CEST]
  CHANGE:                    Change Package : 235009:1 http://mks-psad:7002/im/viewissue?selection=235009
  CHANGE:                    Revision 1.22 2014/03/18 13:07:47CET Sorge-EXT, Sven (uidg3181) 
  CHANGE:                    Added Conversion from MFC3xx to I390
  CHANGE:                    --- Added comments ---  uidg3181 [Mar 18, 2014 1:07:47 PM CET]
  CHANGE:                    Change Package : 217703:2 http://mks-psad:7002/im/viewissue?selection=217703
  CHANGE:                    Revision 1.21 2014/01/31 16:46:46CET Wolter, Frank (wolterf) 
  CHANGE:                    Corrected conversion of I/O states
  CHANGE:                    --- Added comments ---  wolterf [Jan 31, 2014 4:46:46 PM CET]
  CHANGE:                    Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGE:                    Revision 1.20 2014/01/28 15:40:31CET Wolter, Frank (wolterf) 
  CHANGE:                    Added support for VehSig V8
  CHANGE:                    --- Added comments ---  wolterf [Jan 28, 2014 3:40:31 PM CET]
  CHANGE:                    Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGE:                    Revision 1.19 2014/01/14 15:23:32CET Mueller, Reik (muellerr5) 
  CHANGE:                    - added support for PPorts with simREFERENCE_t port type
  CHANGE:                    --- Added comments ---  muellerr5 [Jan 14, 2014 3:23:32 PM CET]
  CHANGE:                    Change Package : 199840:1 http://mks-psad:7002/im/viewissue?selection=199840
  CHANGE:                    Revision 1.18 2013/07/25 09:40:41CEST Mueller, Reik (muellerr5) 
  CHANGE:                    - updated ConvertToVehSigV7
  CHANGE:                    - fixed conversion handling for VehSigV7 in ConvertData method
  CHANGE:                    --- Added comments ---  muellerr5 [Jul 25, 2013 9:40:42 AM CEST]
  CHANGE:                    Change Package : 184575:2 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGE:                    Revision 1.17 2013/07/24 14:35:42CEST Wolter, Frank (wolterf) 
  CHANGE:                    added VehSigV7:
  CHANGE:                    - ninth gear
  CHANGE:                    - powerfree gear
  CHANGE:                    - engine running
  CHANGE:                    --- Added comments ---  wolterf [Jul 24, 2013 2:35:42 PM CEST]
  CHANGE:                    Change Package : 189943:1 http://mks-psad:7002/im/viewissue?selection=189943
  CHANGE:                    Revision 1.16 2013/03/08 11:02:05CET Spruck, Jochen (spruckj) 
  CHANGE:                    Update veh par and veh sig adapter, add trail signal, ignition switch, wheel width and front axle to road data
  CHANGE:                    --- Added comments ---  spruckj [Mar 8, 2013 11:02:06 AM CET]
  CHANGE:                    Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGE:                    Revision 1.15 2013/02/06 12:59:39CET Spruck, Jochen (spruckj) 
  CHANGE:                    Add vdy offsets adapter to semo adapter, and use const vars instead of defines in interface namespaces
  CHANGE:                    --- Added comments ---  spruckj [Feb 6, 2013 12:59:41 PM CET]
  CHANGE:                    Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGE:                    Revision 1.14 2013/01/18 09:02:41CET Spruck, Jochen (spruckj) 
  CHANGE:                    move typedefs inside namespace
  CHANGE:                    --- Added comments ---  spruckj [Jan 18, 2013 9:02:41 AM CET]
  CHANGE:                    Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGE:                    Revision 1.13 2013/01/17 09:43:45CET Spruck, Jochen (spruckj) 
  CHANGE:                    Update adapter
  CHANGE:                    --- Added comments ---  spruckj [Jan 17, 2013 9:43:46 AM CET]
  CHANGE:                    Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGE:                    Revision 1.12 2013/01/16 13:06:09CET Spruck, Jochen (spruckj) 
  CHANGE:                    Rename namespaces, because of conflicts
  CHANGE:                    --- Added comments ---  spruckj [Jan 16, 2013 1:06:10 PM CET]
  CHANGE:                    Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGE:                    Revision 1.11 2013/01/16 11:36:35CET Spruck, Jochen (spruckj) 
  CHANGE:                    Update VehSig VehPar and VehDyn adapter modules regarding mfc400 changes
  CHANGE:                    --- Added comments ---  spruckj [Jan 16, 2013 11:36:36 AM CET]
  CHANGE:                    Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGE:                    Revision 1.10 2012/04/24 17:17:16CEST Mogos, Sorin (mogoss) 
  CHANGE:                    * update: added VehSigV4
  CHANGE:                    --- Added comments ---  mogoss [Apr 24, 2012 5:17:21 PM CEST]
  CHANGE:                    Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
  CHANGE:                    Revision 1.9 2012/04/17 11:16:55CEST Mogos, Sorin (mogoss) 
  CHANGE:                    * re-do changes to rev 1.7
  CHANGE:                    --- Added comments ---  mogoss [Apr 17, 2012 11:16:55 AM CEST]
  CHANGE:                    Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
  CHANGE:                    Revision 1.7 2012/04/11 10:21:10CEST Berndt, Thomas01 (berndtt1) 
  CHANGE:                    Added version 3 of BSW_VEH_SIG_INTFVER, which is identical to version 2
  CHANGE:                    --- Added comments ---  berndtt1 [Apr 11, 2012 10:24:57 AM CEST]
  CHANGE:                    Change Package : 105371:4 http://mks-psad:7002/im/viewissue?selection=105371

**************************************************************************** */
#include "stdafx.h"
#include "sim_adapter_cfg.h"
#include "sim_conv_vdy_input_data_veh_sig.h"
#include "sim_adapter_ext.h"

#define _MINI(x,y) (x<y?x:y)

/*
const char* CConvVdyInputDataVehSig::DEP_NAMES[CConvVdyInputDataVehSig::DEP_COUNT] = {
"Dep_1", //to be inserted here
};
*/

CVersionInfoImpl CConvVdyInputDataVehSig::BASE_VERSION(0, 0, 0);

CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V1_VERINFO(0, 0, 1);
CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V2_VERINFO(0, 0, 2);
CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V3_VERINFO(0, 0, 3);
CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V4_VERINFO(0, 0, 3);
CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V5_VERINFO(0, 0, 5);
CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V6_VERINFO(0, 0, 6);
CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V7_VERINFO(0, 0, 7);
CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V8_VERINFO(0, 0, 8);
CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V9_VERINFO(0, 0, 9);
CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V10_VERINFO(0, 0, 10);
CVersionInfoImpl CConvVdyInputDataVehSig::VEH_SIG_V11_VERINFO(0, 0, 11);

unsigned long CConvVdyInputDataVehSig::SUPPORTED_SIZE[CConvVdyInputDataVehSig::VDY_IN_VER_COUNT ] = { 
sizeof(VDY_SIG_300::VDYInputData_v1_t),
sizeof(VDY_SIG_300::VDYInputData_v2_t),
sizeof(VDY_SIG_300::VDYInputData_v3_t),
sizeof(VDY_SIG_300::VDYInputData_v4_t)
};

unsigned long CConvVdyInputDataVehSig::VEHSIG_SUPPORTED_SIZE[CConvVdyInputDataVehSig::VEHSIG_INPUT_VERSION_COUNT]=
{
  sizeof(VehSigV1::VehSig_t),
  sizeof(VehSigV2::VehSig_t),
  sizeof(VehSigV2::VehSig_t),
  sizeof(VehSigV4::VehSig_t),
  sizeof(VehSigV5::VehSig_t),
  sizeof(VehSigV6::VehSig_t),
  sizeof(VehSigV7::VehSig_t),
  sizeof(VehSigV8::VehSig_t),
  sizeof(VehSigV9::VehSig_t),
  sizeof(VehSigV10::VehSig_t),
  sizeof(VehSigV11::VehSig_t)
};

CVersionInfoImpl * const CConvVdyInputDataVehSig::VEHSIG_VERSION_NUMBERS[VEHSIG_INPUT_VERSION_COUNT]=
{
  &VEH_SIG_V1_VERINFO,
  &VEH_SIG_V2_VERINFO,
  &VEH_SIG_V3_VERINFO,
  &VEH_SIG_V4_VERINFO,
  &VEH_SIG_V5_VERINFO,
  &VEH_SIG_V6_VERINFO,
  &VEH_SIG_V7_VERINFO,
  &VEH_SIG_V8_VERINFO,
  &VEH_SIG_V9_VERINFO,
  &VEH_SIG_V10_VERINFO,
  &VEH_SIG_V11_VERINFO
};

const uint32 CConvVdyInputDataVehSig::DefaultStateWord = 0xAAAAAAAA;  // Set to 0xAAAAAAAA for VDY_IO_STATE_NOTAVAIL, 0x55555555 for VDY_IO_STATE_INVALID, 0 for VDY_IO_STATE_VALID

template<class T> T ValidateValueRange(T value, const T & minval, const T & maxval, const T & defvalue)
{
  if ((value >= minval) && (value <= maxval))
  {
    return value;
  }
  else
  {
#if SRR_SWITCH
      return value;
#else 
      return defvalue;
#endif 

  }
}


CConvVdyInputDataVehSig::CConvVdyInputDataVehSig(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT)
{
}


CConvVdyInputDataVehSig::~CConvVdyInputDataVehSig(void)
{
}


void CConvVdyInputDataVehSig::InitDefaultVehSigV1(VehSigV1::VehSig_t * const pDest)
{
  // Default values
  memset(pDest, 0, sizeof(VehSigV1::VehSig_t));
  pDest->uiVersionNumber              = 0;
  pDest->VehSigMain.State[0]          = DefaultStateWord;
  pDest->VehSigMain.State[1]          = DefaultStateWord;

}


void CConvVdyInputDataVehSig::InitDefaultVehSigV2(VehSigV2::VehSig_t * const pDest)
{
  // Default values
  memset(pDest, 0, sizeof(VehSigV2::VehSig_t));
  pDest->uiVersionNumber              = 0;
  pDest->VehSigMain.State[0]          = DefaultStateWord;
  pDest->VehSigMain.State[1]          = DefaultStateWord;
}

void CConvVdyInputDataVehSig::InitDefaultVehSigV4(VehSigV4::VehSig_t * const pDest)
{
  // Default values
  memset(pDest, 0, sizeof(VehSigV4::VehSig_t));
  pDest->uiVersionNumber              = 0;
  pDest->VehSigMain.State[0]          = DefaultStateWord;
  pDest->VehSigMain.State[1]          = DefaultStateWord;
}


void CConvVdyInputDataVehSig::InitDefaultVehSigV5(VehSigV5::VehSig_t * const pDest)
{
  // Default values
  memset(pDest, 0, sizeof(VehSigV5::VehSig_t));
  pDest->uiVersionNumber                    = 5;

  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehSigV5::AL_SIG_STATE_OK;

  pDest->VehSigMain.State[0]          = DefaultStateWord;
  pDest->VehSigMain.State[1]          = DefaultStateWord;
}


void CConvVdyInputDataVehSig::InitDefaultVehSigV6(VehSigV6::VehSig_t * const pDest)
{
  // Default values
  memset(pDest, 0, sizeof(VehSigV6::VehSig_t));
  pDest->uiVersionNumber                    = 6;

  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehSigV5::AL_SIG_STATE_OK;

  pDest->VehSigMain.State[0]          = DefaultStateWord;
  pDest->VehSigMain.State[1]          = DefaultStateWord;
}


void CConvVdyInputDataVehSig::InitDefaultVehSigV7(VehSigV7::VehSig_t * const pDest)
{
  // Default values
  memset(pDest, 0, sizeof(VehSigV7::VehSig_t));
  pDest->uiVersionNumber                    = 7;

  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehSigV5::AL_SIG_STATE_OK;

  pDest->VehSigMain.State[0]          = DefaultStateWord;
  pDest->VehSigMain.State[1]          = DefaultStateWord;
}


void CConvVdyInputDataVehSig::InitDefaultVehSigV8(VehSigV8::VehSig_t * const pDest)
{
  // Default values
  memset(pDest, 0, sizeof(VehSigV8::VehSig_t));
  pDest->uiVersionNumber                 = 8;

  pDest->sSigHeader.uiTimeStamp          = 0U;
  pDest->sSigHeader.uiMeasurementCounter = 0U;
  pDest->sSigHeader.uiCycleCounter       = 0U;
  pDest->sSigHeader.eSigStatus           = VehSigV5::AL_SIG_STATE_OK;

  memset(pDest->VehSigMain.State, VehSigV8::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->VehSigMain.State));
  memset(pDest->VehSigAdd.State, VehSigV8::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->VehSigAdd.State));
  memset(pDest->PowerTrain.State, VehSigV8::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->PowerTrain.State));
  memset(pDest->Brake.State, VehSigV8::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->Brake.State));
}

void CConvVdyInputDataVehSig::InitDefaultVehSigV9(VehSigV9::VehSig_t * const pDest)
{
  // Default values
  memset(pDest, 0, sizeof(VehSigV9::VehSig_t));
  pDest->uiVersionNumber                 = 9;

  pDest->sSigHeader.uiTimeStamp          = 0U;
  pDest->sSigHeader.uiMeasurementCounter = 0U;
  pDest->sSigHeader.uiCycleCounter       = 0U;
  pDest->sSigHeader.eSigStatus           = VehSigV5::AL_SIG_STATE_OK;

  memset(pDest->VehSigMain.State, VehSigV9::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->VehSigMain.State));
  memset(pDest->VehSigAdd.State, VehSigV9::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->VehSigAdd.State));
  memset(pDest->PowerTrain.State, VehSigV9::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->PowerTrain.State));
  memset(pDest->Brake.State, VehSigV9::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->Brake.State));
}

void CConvVdyInputDataVehSig::InitDefaultVehSigV10(VehSigV10::VehSig_t * const pDest)
{
  // Default values
  memset(pDest, 0, sizeof(VehSigV10::VehSig_t));
  pDest->uiVersionNumber                 = 10;

  pDest->sSigHeader.uiTimeStamp          = 0U;
  pDest->sSigHeader.uiMeasurementCounter = 0U;
  pDest->sSigHeader.uiCycleCounter       = 0U;
  pDest->sSigHeader.eSigStatus           = VehSigV5::AL_SIG_STATE_OK;

  memset(pDest->VehSigMain.State, VehSigV10::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->VehSigMain.State));
  memset(pDest->VehSigAdd.State, VehSigV10::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->VehSigAdd.State));
  memset(pDest->PowerTrain.State, VehSigV10::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->PowerTrain.State));
  memset(pDest->Brake.State, VehSigV10::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->Brake.State));
}

/* Initializing the 11th version of veh_sig */
void CConvVdyInputDataVehSig::InitDefaultVehSigV11(VehSigV11::VehSig_t * const pDest)
{
  // Default values
  memset(pDest, 0, sizeof(VehSigV11::VehSig_t));
  pDest->uiVersionNumber                 = 11;

  pDest->sSigHeader.uiTimeStamp          = 0U;
  pDest->sSigHeader.uiMeasurementCounter = 0U;
  pDest->sSigHeader.uiCycleCounter       = 0U;
  pDest->sSigHeader.eSigStatus           = VehSigV5::AL_SIG_STATE_OK;

  memset(pDest->VehSigMain.State, VehSigV11::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->VehSigMain.State));
  memset(pDest->VehSigAdd.State, VehSigV11::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->VehSigAdd.State));
  memset(pDest->PowerTrain.State, VehSigV11::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->PowerTrain.State));
  memset(pDest->Brake.State, VehSigV11::VEH_SIG_IO_STATE_NOTAVAIL, sizeof(pDest->Brake.State));
}


void CConvVdyInputDataVehSig::ConvertToVehSigV1(VehSigV1::VehSig_t * const pDest, const VehSigV2::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV1(pDest);
  
  pDest->uiVersionNumber              = 0;
  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV2::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV2::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV2::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

}


void CConvVdyInputDataVehSig::ConvertToVehSigV1(VehSigV1::VehSig_t * const pDest, const VehSigV4::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV1(pDest); 

  pDest->uiVersionNumber              = 0;
  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

		  

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV4::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV4::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV4::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);
		 
  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;   
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl; 
  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
  pDest->VehSigAdd.EnvTemp = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.TurnSignal  = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.RoadWhlAngFr = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe	= pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer	= pInput->VehSigAdd.Odometer;
}


void CConvVdyInputDataVehSig::ConvertToVehSigV2(VehSigV2::VehSig_t * const pDest, const VehSigV1::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV2(pDest);

  pDest->uiVersionNumber              = 0;
  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV1::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV1::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV1::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV1::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV1::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV1::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV1::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV1::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  pDest->VehSigAdd.EnvTemp         = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.Odometer        = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.RoadWhlAngFr    = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe    = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.TurnSignal      = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.WiperState      = pInput->VehSigAdd.WiperState;
}


void CConvVdyInputDataVehSig::ConvertToVehSigV2(VehSigV2::VehSig_t * const pDest, const VehSigV4::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV2(pDest);

  pDest->uiVersionNumber              = 0;
  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV4::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV4::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV4::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);


  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;   
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl; 
  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
  pDest->VehSigAdd.EnvTemp = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.TurnSignal  = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.RoadWhlAngFr = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe	= pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer	= pInput->VehSigAdd.Odometer;
}


void CConvVdyInputDataVehSig::ConvertToVehSigV4(VehSigV4::VehSig_t * const pDest, const VehSigV1::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV4(pDest);

  pDest->uiVersionNumber              = 0;
  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV1::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV1::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV1::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV1::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV1::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV1::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV1::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV1::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);
		 
  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;   
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl; 
  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
  pDest->VehSigAdd.EnvTemp = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.TurnSignal  = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.RoadWhlAngFr = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe	= pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer	= pInput->VehSigAdd.Odometer;
}


void CConvVdyInputDataVehSig::ConvertToVehSigV4(VehSigV4::VehSig_t * const pDest, const VehSigV2::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV4(pDest);

  pDest->uiVersionNumber              = 0;
  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV2::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV2::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV2::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;   
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl; 
  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
  pDest->VehSigAdd.EnvTemp = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.TurnSignal  = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.RoadWhlAngFr = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe	= pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer	= pInput->VehSigAdd.Odometer;
}


void CConvVdyInputDataVehSig::ConvertToVehSigV5(VehSigV5::VehSig_t * const pDest, const VehSigV4::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV5(pDest);

  pDest->uiVersionNumber              = 5;

  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehSigV5::AL_SIG_STATE_OK;

  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV4::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV4::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV4::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV4::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  pDest->VehSigAdd.State[0] = DefaultStateWord;
  pDest->VehSigAdd.State[1] = DefaultStateWord;

  pDest->VehSigAdd.EnvTemp               = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState            = pInput->VehSigAdd.WiperState; 
  if(pInput->VehSigAdd.WiperState == VehSigV5::VEH_SIG_ADD_WIPER_STATE_INACTIVE )
  {
    pDest->VehSigAdd.WiperStage            = VehSigV5::VEH_SIG_ADD_WIPER_OFF;
  }
  else
  {
    pDest->VehSigAdd.WiperStage            = VehSigV5::VEH_SIG_ADD_WIPER_STAGE2;
  }
  pDest->VehSigAdd.WiperOutParkPos       = VehSigV5::VEH_SIG_ADD_WIPER_OFF;
  pDest->VehSigAdd.WiperWasherFrontState = VehSigV5::VEH_SIG_ADD_WWS_IDLE;
  pDest->VehSigAdd.RainSensor            = FALSE;
  pDest->VehSigAdd.TurnSignal            = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront          = FALSE;
  pDest->VehSigAdd.FogLampRear           = FALSE;
  pDest->VehSigAdd.RoadWhlAngFr          = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe          = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer              = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos           = 0.0F;
  pDest->VehSigAdd.KickDown              = FALSE;
  pDest->VehSigAdd.BrakePedalPressed     = FALSE;
  pDest->VehSigAdd.DriverTired           = FALSE;
  pDest->VehSigAdd.SpeedUnit             = VehSigV5::VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN;
  pDest->VehSigAdd.SpeedoSpeed           = 0.0F;

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;
  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
}


void CConvVdyInputDataVehSig::ConvertToVehSigV5(VehSigV5::VehSig_t * const pDest, const VehSigV6::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV5(pDest);

  pDest->uiVersionNumber              = 5;

  pDest->sSignalHeader.uiTimeStamp          = pInput->sSignalHeader.uiTimeStamp;
  pDest->sSignalHeader.uiMeasurementCounter = pInput->sSignalHeader.uiMeasurementCounter;
  pDest->sSignalHeader.uiCycleCounter       = pInput->sSignalHeader.uiCycleCounter;
  pDest->sSignalHeader.eSigStatus           = pInput->sSignalHeader.eSigStatus;

  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV6::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV6::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV6::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV6::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV6::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV6::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV6::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV6::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  pDest->VehSigAdd.State[0] = pInput->VehSigAdd.State[0];
  pDest->VehSigAdd.State[1] = pInput->VehSigAdd.State[1];

  pDest->VehSigAdd.EnvTemp               = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState            = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage            = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos       = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor            = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal            = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront          = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear           = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr          = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe          = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer              = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos           = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown              = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed     = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired           = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit             = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed           = pInput->VehSigAdd.SpeedoSpeed;

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;
  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
}


void CConvVdyInputDataVehSig::ConvertToVehSigV4(VehSigV4::VehSig_t * const pDest, const VehSigV5::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV4(pDest);

  pDest->uiVersionNumber              = 0;
  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV5::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV5::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV5::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV5::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV5::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV5::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV5::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV5::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;
  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
  pDest->VehSigAdd.EnvTemp = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.TurnSignal  = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.RoadWhlAngFr = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe	= pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer	= pInput->VehSigAdd.Odometer;
}


void CConvVdyInputDataVehSig::ConvertToVehSigV6(VehSigV6::VehSig_t * const pDest, const VehSigV5::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV6(pDest);

  pDest->uiVersionNumber              = 6;

  pDest->sSignalHeader.uiTimeStamp          = pInput->sSignalHeader.uiTimeStamp;
  pDest->sSignalHeader.uiMeasurementCounter = pInput->sSignalHeader.uiMeasurementCounter;
  pDest->sSignalHeader.uiCycleCounter       = pInput->sSignalHeader.uiCycleCounter;
  pDest->sSignalHeader.eSigStatus           = pInput->sSignalHeader.eSigStatus;

  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV5::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV5::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV5::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV5::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV5::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV5::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV5::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV5::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  pDest->VehSigAdd.State[0]             = pInput->VehSigAdd.State[0];
  pDest->VehSigAdd.State[1]             = pInput->VehSigAdd.State[0];

  pDest->VehSigAdd.EnvTemp               = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState            = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage            = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos       = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor            = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal            = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront          = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear           = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr          = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe          = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer              = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos           = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown              = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed     = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired           = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit             = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed           = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection     = VehSigV6::VEH_SIG_ADD_TRLR_SNA;
  pDest->VehSigAdd.IgnitionSwitch        = VehSigV6::VEH_SIG_ADD_IGN_ON;

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;
  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
}

void CConvVdyInputDataVehSig::ConvertToVehSigV6(VehSigV6::VehSig_t * const pDest, const VehSigV7::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV6(pDest);

  pDest->uiVersionNumber              = 6;

  pDest->sSignalHeader.uiTimeStamp          = pInput->sSignalHeader.uiTimeStamp;
  pDest->sSignalHeader.uiMeasurementCounter = pInput->sSignalHeader.uiMeasurementCounter;
  pDest->sSignalHeader.uiCycleCounter       = pInput->sSignalHeader.uiCycleCounter;
  pDest->sSignalHeader.eSigStatus           = pInput->sSignalHeader.eSigStatus;

  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV7::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV7::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV7::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV7::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV7::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV7::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV7::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV7::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  pDest->VehSigAdd.State[0] = pInput->VehSigAdd.State[0];
  pDest->VehSigAdd.State[1] = pInput->VehSigAdd.State[1];

  pDest->VehSigAdd.EnvTemp               = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState            = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage            = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos       = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor            = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal            = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront          = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear           = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr          = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe          = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer              = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos           = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown              = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed     = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired           = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit             = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed           = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection     = pInput->VehSigAdd.TrailerConnection;
  pDest->VehSigAdd.IgnitionSwitch        = pInput->VehSigAdd.IgnitionSwitch;

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;
  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
}

void CConvVdyInputDataVehSig::ConvertToVehSigV7(VehSigV7::VehSig_t * const pDest, const VehSigV2::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV7(pDest);

  pDest->uiVersionNumber              = 7;

  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehSigV5::AL_SIG_STATE_OK;

  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV2::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV2::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV2::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV2::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  pDest->VehSigAdd.State[0] = DefaultStateWord;
  pDest->VehSigAdd.State[1] = DefaultStateWord;

  pDest->VehSigAdd.EnvTemp               = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState            = pInput->VehSigAdd.WiperState; 
  if(pInput->VehSigAdd.WiperState == VehSigV6::VEH_SIG_ADD_WIPER_STATE_INACTIVE)
  {
    pDest->VehSigAdd.WiperStage        = VehSigV6::VEH_SIG_ADD_WIPER_OFF;
  }
  else
  {
    pDest->VehSigAdd.WiperStage        = VehSigV6::VEH_SIG_ADD_WIPER_STAGE2;
  }
  pDest->VehSigAdd.WiperOutParkPos       = VehSigV6::VEH_SIG_ADD_WIPER_OFF;
  pDest->VehSigAdd.WiperWasherFrontState = VehSigV6::VEH_SIG_ADD_WWS_IDLE;
  pDest->VehSigAdd.RainSensor            = FALSE;
  pDest->VehSigAdd.TurnSignal            = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront          = FALSE;
  pDest->VehSigAdd.FogLampRear           = FALSE;
  pDest->VehSigAdd.RoadWhlAngFr          = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe          = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer              = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos           = 0.0F;
  pDest->VehSigAdd.KickDown              = FALSE;
  pDest->VehSigAdd.BrakePedalPressed     = FALSE;
  pDest->VehSigAdd.DriverTired           = FALSE;
  pDest->VehSigAdd.SpeedUnit             = VehSigV6::VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN;
  pDest->VehSigAdd.SpeedoSpeed           = 0.0F;
  pDest->VehSigAdd.TrailerConnection     = VehSigV6::VEH_SIG_ADD_TRLR_SNA;
  pDest->VehSigAdd.IgnitionSwitch        = VehSigV6::VEH_SIG_ADD_IGN_ON;

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;

  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
  pDest->PowerTrain.EngineRunning = FALSE;
}


void CConvVdyInputDataVehSig::ConvertToVehSigV7(VehSigV7::VehSig_t * const pDest, const VehSigV6::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV7(pDest);

  pDest->uiVersionNumber              = 7;

  pDest->sSignalHeader.uiTimeStamp          = pInput->sSignalHeader.uiTimeStamp;
  pDest->sSignalHeader.uiMeasurementCounter = pInput->sSignalHeader.uiMeasurementCounter;
  pDest->sSignalHeader.uiCycleCounter       = pInput->sSignalHeader.uiCycleCounter;
  pDest->sSignalHeader.eSigStatus           = pInput->sSignalHeader.eSigStatus;

  pDest->VehSigMain.State[0]          = pInput->VehSigMain.State[0];
  pDest->VehSigMain.State[1]          = pInput->VehSigMain.State[1];

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV6::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV6::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV6::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV6::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV6::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV6::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV6::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV6::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  pDest->VehSigAdd.State[0]              = pInput->VehSigAdd.State[0];
  pDest->VehSigAdd.State[1]              = pInput->VehSigAdd.State[1];

  pDest->VehSigAdd.EnvTemp               = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState            = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage            = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos       = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor            = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal            = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront          = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear           = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr          = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe          = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer              = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos           = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown              = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed     = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired           = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit             = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed           = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection     = pInput->VehSigAdd.TrailerConnection;
  pDest->VehSigAdd.IgnitionSwitch        = pInput->VehSigAdd.IgnitionSwitch;

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;

  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
  pDest->PowerTrain.EngineRunning = FALSE;
}

void CConvVdyInputDataVehSig::ConvertToVehSigV7(VehSigV7::VehSig_t * const pDest, const VehSigV8::VehSig_t * const pInput)
{
  // Initialize default values
  InitDefaultVehSigV7(pDest);

  pDest->uiVersionNumber              = 7;

  pDest->sSignalHeader.uiTimeStamp          = pInput->sSigHeader.uiTimeStamp;
  pDest->sSignalHeader.uiMeasurementCounter = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSignalHeader.uiCycleCounter       = pInput->sSigHeader.uiCycleCounter;
  pDest->sSignalHeader.eSigStatus           = pInput->sSigHeader.eSigStatus;

  pDest->VehSigMain.State[0]             = 0xFFFFL;
  for (unsigned int i=0; i<VehSigV8::VDY_SIN_POS_MAX; i++)
  {
    ConvertIOState(2*i, pInput->VehSigMain.State[i], (unsigned long *)pDest->VehSigMain.State);
  }
  pDest->VehSigMain.State[1]             = 0xFFFFL;
  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV8::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV8::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV8::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV8::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV8::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV8::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV8::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV8::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  for (unsigned int i=0; i<VehSigV8::VEH_SIG_ADD_MAX; i++)
  {
    ConvertIOState(4*i, pInput->VehSigAdd.State[i], (unsigned long *)pDest->VehSigAdd.State);
  }
  pDest->VehSigAdd.EnvTemp               = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState            = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage            = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos       = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor            = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal            = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront          = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear           = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr          = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe          = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer              = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos           = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown              = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed     = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired           = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit             = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed           = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection     = pInput->VehSigAdd.TrailerConnection;
  pDest->VehSigAdd.IgnitionSwitch        = pInput->VehSigAdd.IgnitionSwitch;

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;

  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
  pDest->PowerTrain.EngineRunning = pInput->PowerTrain.EngineRunning;
}


void CConvVdyInputDataVehSig::ConvertToVehSigV8(VehSigV8::VehSig_t * const pDest, const VehSigV7::VehSig_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehSigV8(pDest);

  pDest->sSigHeader.uiTimeStamp          = pInput->sSignalHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pInput->sSignalHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter       = pInput->sSignalHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus           = pInput->sSignalHeader.eSigStatus;
  
  for (i=0; i<VehSigV8::VDY_SIN_POS_MAX; i++)
  {
    pDest->VehSigMain.State[i]          = ConvertIOState(2*i, (unsigned long *)pInput->VehSigMain.State);
  }
  //  single signal conversion would look like:
  //  pDest->VehSigMain.State[VehSigV8::VDY_SIN_POS_YWR] = ConvertIOState(VehSigV6::VDY_SIN_POS_YWR, (unsigned long *)pInput->VehSigMain.State);
    
  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV7::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV7::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV7::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV7::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV7::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV7::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV7::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV7::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  for (i=0; i<VehSigV8::VEH_SIG_ADD_MAX; i++)
  {
    pDest->VehSigAdd.State[i]          = ConvertIOState(4*i, (unsigned long *)pInput->VehSigAdd.State);
  }
  pDest->VehSigAdd.EnvTemp               = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState            = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage            = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos       = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor            = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal            = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront          = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear           = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr          = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe          = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer              = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos           = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown              = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed     = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired           = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit             = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed           = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection     = pInput->VehSigAdd.TrailerConnection;
  pDest->VehSigAdd.IgnitionSwitch        = pInput->VehSigAdd.IgnitionSwitch;

  // Brake signals had no validity state before, assume they were valid
  for (i=0; i<VehSigV8::VEH_SIG_BRAKE_MAX; i++)
  {
    pDest->Brake.State[i]          = VehSigV8::VEH_SIG_IO_STATE_VALID;
  }

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;

  // Powertrain signals had no validity state before, assume they were valid
  for (i=0; i<VehSigV8::VEH_SIG_POWERTRAIN_MAX; i++)
  {
    pDest->PowerTrain.State[i]     = VehSigV8::VEH_SIG_IO_STATE_VALID;
  }

  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
  pDest->PowerTrain.EngineRunning = pInput->PowerTrain.EngineRunning;
}

void CConvVdyInputDataVehSig::ConvertToVehSigV8(VehSigV8::VehSig_t * const pDest, const VehSigV9::VehSig_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehSigV8(pDest);

  pDest->sSigHeader.uiTimeStamp          = pInput->sSigHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter       = pInput->sSigHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus           = pInput->sSigHeader.eSigStatus;

  for (i=0; i<VehSigV8::VDY_SIN_POS_MAX; i++)
  {
    pDest->VehSigMain.State[i]          = pInput->VehSigMain.State[i];
  }
  //  single signal conversion would look like:
  //  pDest->VehSigMain.State[VehSigV8::VDY_SIN_POS_YWR] = ConvertIOState(VehSigV6::VDY_SIN_POS_YWR, (unsigned long *)pInput->VehSigMain.State);
    
  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.LatAccel        = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.LongAccel       = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.RearWhlAngle    = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ActGearPos      = ValidateValueRange<VehSigV9::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel   = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);

  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV9::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV9::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);

  for (i=0; i<VehSigV8::VEH_SIG_ADD_MAX; i++)
  {
    pDest->VehSigAdd.State[i]          = pInput->VehSigAdd.State[i];
  }
  pDest->VehSigAdd.EnvTemp               = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState            = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage            = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos       = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor            = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal            = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront          = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear           = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr          = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe          = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer              = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos           = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown              = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed     = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired           = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit             = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed           = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection     = pInput->VehSigAdd.TrailerConnection;
  pDest->VehSigAdd.IgnitionSwitch        = pInput->VehSigAdd.IgnitionSwitch;

  // Brake signals had no validity state before, assume they were valid
  for (i=0; i<VehSigV8::VEH_SIG_BRAKE_MAX; i++)
  {
    pDest->Brake.State[i]          = pInput->Brake.State[i];
  }

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;

  // Powertrain signals had no validity state before, assume they were valid
  for (i=0; i<VehSigV8::VEH_SIG_POWERTRAIN_MAX; i++)
  {
    pDest->PowerTrain.State[i]     = pInput->PowerTrain.State[i];
  }

  pDest->PowerTrain.ActualGear = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear = pInput->PowerTrain.TargetGear;
  pDest->PowerTrain.EngineRunning = pInput->PowerTrain.EngineRunning;
}

void CConvVdyInputDataVehSig::ConvertToVehSigV9(VehSigV9::VehSig_t * const pDest, const VehSigV8::VehSig_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehSigV9(pDest);

  //sSigHeader
  pDest->sSigHeader.uiTimeStamp          = pInput->sSigHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter       = pInput->sSigHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus           = pInput->sSigHeader.eSigStatus;

  //VehSigMain
  for (i=0; i<VehSigV9::VDY_SIN_POS_MAX; i++)
  {
    pDest->VehSigMain.State[i]          = pInput->VehSigMain.State[i];
  }
  //  single signal conversion would look like:
  //  pDest->VehSigMain.State[VehSigV8::VDY_SIN_POS_YWR] = ConvertIOState(VehSigV6::VDY_SIN_POS_YWR, (unsigned long *)pInput->VehSigMain.State);
  pDest->VehSigMain.ActGearPos          = ValidateValueRange<VehSigV8::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel       = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.LatAccel            = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.LongAccel           = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV8::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.RearWhlAngle        = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV8::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV8::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV8::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV8::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV8::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV8::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);

  for (i=0; i<VehSigV9::VEH_SIG_ADD_MAX; i++)
  {

    pDest->VehSigAdd.State[i]          = pInput->VehSigAdd.State[i];
  }
  pDest->VehSigAdd.EnvTemp                       = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState                    = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage                    = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos               = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState         = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor                    = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal                    = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront                  = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear                   = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr                  = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe                  = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer                      = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos                   = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown                      = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed             = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired                   = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit                     = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed                   = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection             = pInput->VehSigAdd.TrailerConnection;
  pDest->VehSigAdd.TrailerConnBeforeShutDown     = 0;
  pDest->VehSigAdd.TrailerLengthInput            = 0;
  pDest->VehSigAdd.ParkAidDet_L                  = 0;
  pDest->VehSigAdd.ParkAidDet_CL                 = 0;
  pDest->VehSigAdd.ParkAidDet_CR                 = 0;
  pDest->VehSigAdd.ParkAidDet_R                  = 0;
  pDest->VehSigAdd.IgnitionSwitch        = pInput->VehSigAdd.IgnitionSwitch;

  for (i=0; i<VehSigV9::VEH_SIG_BRAKE_MAX; i++)
  {
    pDest->Brake.State[i]          = pInput->Brake.State[i];
  }

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;

  // Powertrain signals had no validity state before, assume they were valid
  for (i=0; i<VehSigV9::VEH_SIG_POWERTRAIN_MAX; i++)
  {
    pDest->PowerTrain.State[i]     = pInput->PowerTrain.State[i];
  }

  pDest->PowerTrain.ActualGear    = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear    = pInput->PowerTrain.TargetGear;
  pDest->PowerTrain.EngineRunning = pInput->PowerTrain.EngineRunning;
  pDest->PowerTrain.FillByte      = 0;
}

void CConvVdyInputDataVehSig::ConvertToVehSigV9(VehSigV9::VehSig_t * const pDest, const VehSigV10::VehSig_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehSigV9(pDest);

  //sSigHeader
  pDest->sSigHeader.uiTimeStamp          = pInput->sSigHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter       = pInput->sSigHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus           = pInput->sSigHeader.eSigStatus;

  //VehSigMain
  for (i=0; i<VehSigV9::VDY_SIN_POS_MAX; i++)
  {
    pDest->VehSigMain.State[i]          = pInput->VehSigMain.State[i];
  }
  //  single signal conversion would look like:
  //  pDest->VehSigMain.State[VehSigV8::VDY_SIN_POS_YWR] = ConvertIOState(VehSigV6::VDY_SIN_POS_YWR, (unsigned long *)pInput->VehSigMain.State);
  pDest->VehSigMain.ActGearPos          = ValidateValueRange<VehSigV10::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel       = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.LatAccel            = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.LongAccel           = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV10::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.RearWhlAngle        = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);
  pDest->VehSigMain.StWheelAngle        = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt     = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV10::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV10::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.VehVelocityExt      = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV10::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV10::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV10::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV10::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);

  for (i=0; i<VehSigV9::VEH_SIG_ADD_MAX; i++)
  {

    pDest->VehSigAdd.State[i]          = pInput->VehSigAdd.State[i];
  }
  pDest->VehSigAdd.EnvTemp                       = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState                    = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage                    = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos               = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState         = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor                    = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal                    = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront                  = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear                   = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr                  = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe                  = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer                      = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos                   = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown                      = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed             = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired                   = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit                     = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed                   = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection             = pInput->VehSigAdd.TrailerConnection;
  pDest->VehSigAdd.TrailerConnBeforeShutDown     = pInput->VehSigAdd.TrailerConnBeforeShutDown;
  pDest->VehSigAdd.TrailerLengthInput            = pInput->VehSigAdd.TrailerLengthInput;
  pDest->VehSigAdd.ParkAidDet_L                  = pInput->VehSigAdd.ParkAidDet_L;
  pDest->VehSigAdd.ParkAidDet_CL                 = pInput->VehSigAdd.ParkAidDet_CL;
  pDest->VehSigAdd.ParkAidDet_CR                 = pInput->VehSigAdd.ParkAidDet_CR;
  pDest->VehSigAdd.ParkAidDet_R                  = pInput->VehSigAdd.ParkAidDet_R;
  pDest->VehSigAdd.IgnitionSwitch                = pInput->VehSigAdd.IgnitionSwitch;

  for (i=0; i<VehSigV9::VEH_SIG_BRAKE_MAX; i++)
  {
    pDest->Brake.State[i]          = pInput->Brake.State[i];
  }

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;

  // Powertrain signals had no validity state before, assume they were valid
  for (i=0; i<VehSigV9::VEH_SIG_POWERTRAIN_MAX; i++)
  {
    pDest->PowerTrain.State[i]     = pInput->PowerTrain.State[i];
  }

  pDest->PowerTrain.ActualGear    = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear    = pInput->PowerTrain.TargetGear;
  pDest->PowerTrain.EngineRunning = pInput->PowerTrain.EngineRunning;
  pDest->PowerTrain.FillByte      = pInput->PowerTrain.FillByte;
}

void CConvVdyInputDataVehSig::ConvertToVehSigV10(VehSigV10::VehSig_t * const pDest, const VehSigV9::VehSig_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehSigV10(pDest);

  //sSigHeader
  pDest->sSigHeader.uiTimeStamp          = pInput->sSigHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter       = pInput->sSigHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus           = pInput->sSigHeader.eSigStatus;

  //VehSigMain
  for (i=0; i<VehSigV10::VDY_SIN_POS_MAX; i++)
  {
    pDest->VehSigMain.State[i]          = pInput->VehSigMain.State[i];
  }
  //  single signal conversion would look like:
  //  pDest->VehSigMain.State[VehSigV8::VDY_SIN_POS_YWR] = ConvertIOState(VehSigV6::VDY_SIN_POS_YWR, (unsigned long *)pInput->VehSigMain.State);
  pDest->VehSigMain.ActGearPos          = ValidateValueRange<VehSigV9::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel       = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.LatAccel            = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.LongAccel           = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV9::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.RearWhlAngle        = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV9::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);

  for (i=0; i<VehSigV10::VEH_SIG_ADD_MAX; i++)
  {
    if(pInput->VehSigAdd.State[i] != VehSigV9::VEH_SIG_ADD_IGN_SWITCH)
    {
      pDest->VehSigAdd.State[i]          = pInput->VehSigAdd.State[i];
    }
    else
    {
      pDest->VehSigAdd.State[i]          = VehSigV10::VEH_SIG_ADD_IGN_SWITCH;
    }
  }
  pDest->VehSigAdd.EnvTemp                       = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState                    = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage                    = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos               = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState         = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor                    = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal                    = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront                  = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear                   = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr                  = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe                  = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer                      = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos                   = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown                      = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed             = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired                   = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit                     = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed                   = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection             = pInput->VehSigAdd.TrailerConnection;
  pDest->VehSigAdd.TrailerConnBeforeShutDown     = pInput->VehSigAdd.TrailerConnBeforeShutDown;
  pDest->VehSigAdd.TrailerLengthInput            = pInput->VehSigAdd.TrailerLengthInput;
  pDest->VehSigAdd.ParkAidDet_L                  = pInput->VehSigAdd.ParkAidDet_L;
  pDest->VehSigAdd.ParkAidDet_CL                 = pInput->VehSigAdd.ParkAidDet_CL;
  pDest->VehSigAdd.ParkAidDet_CR                 = pInput->VehSigAdd.ParkAidDet_CR;
  pDest->VehSigAdd.ParkAidDet_R                  = pInput->VehSigAdd.ParkAidDet_R;
  pDest->VehSigAdd.IgnitionSwitch                = pInput->VehSigAdd.IgnitionSwitch;
  pDest->VehSigAdd.eSuspensionSystem             = 0;
  pDest->VehSigAdd.eHeightLevel                  = 0;
  pDest->VehSigAdd.WheelHeightLevel.FrontLeft    = 0;
  pDest->VehSigAdd.WheelHeightLevel.FrontRight   = 0;
  pDest->VehSigAdd.WheelHeightLevel.RearLeft     = 0;
  pDest->VehSigAdd.WheelHeightLevel.RearRight    = 0;
  pDest->VehSigAdd.AlignmentByte1                = 0;
  pDest->VehSigAdd.AlignmentByte2                = 0;

  for (i=0; i<VehSigV10::VEH_SIG_BRAKE_MAX; i++)
  {
    pDest->Brake.State[i]          = pInput->Brake.State[i];
  }

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;

  for (i=0; i<VehSigV10::VEH_SIG_POWERTRAIN_MAX; i++)
  {
    pDest->PowerTrain.State[i]     = pInput->PowerTrain.State[i];
  }

  pDest->PowerTrain.ActualGear    = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear    = pInput->PowerTrain.TargetGear;
  pDest->PowerTrain.EngineRunning = pInput->PowerTrain.EngineRunning;
  pDest->PowerTrain.FillByte      = pInput->PowerTrain.FillByte;
}

// Covert the 11th version to 10th version 
void CConvVdyInputDataVehSig::ConvertToVehSigV10(VehSigV10::VehSig_t * const pDest, const VehSigV11::VehSig_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehSigV10(pDest);

  //sSigHeader
  pDest->sSigHeader.uiTimeStamp          = pInput->sSigHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter       = pInput->sSigHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus           = pInput->sSigHeader.eSigStatus;

  //VehSigMain
  for (i=0; i<VehSigV10::VDY_SIN_POS_MAX; i++)
  {
    pDest->VehSigMain.State[i]          = pInput->VehSigMain.State[i];
  }
  //  single signal conversion would look like:
  //  pDest->VehSigMain.State[VehSigV8::VDY_SIN_POS_YWR] = ConvertIOState(VehSigV6::VDY_SIN_POS_YWR, (unsigned long *)pInput->VehSigMain.State);
  pDest->VehSigMain.ActGearPos          = ValidateValueRange<VehSigV9::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel       = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.LatAccel            = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.LongAccel           = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV9::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.RearWhlAngle        = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV9::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);

  for (i=0; i<VehSigV10::VEH_SIG_ADD_MAX; i++)
  {
    if(pInput->VehSigAdd.State[i] != VehSigV9::VEH_SIG_ADD_IGN_SWITCH)
    {
      pDest->VehSigAdd.State[i]          = pInput->VehSigAdd.State[i];
    }
    else
    {
      pDest->VehSigAdd.State[i]          = VehSigV10::VEH_SIG_ADD_IGN_SWITCH;
    }
  }
  pDest->VehSigAdd.EnvTemp                       = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState                    = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage                    = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos               = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState         = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor                    = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal                    = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront                  = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear                   = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr                  = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe                  = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer                      = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos                   = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown                      = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed             = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired                   = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit                     = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed                   = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection             = pInput->VehSigAdd.TrailerConnection;
  pDest->VehSigAdd.TrailerConnBeforeShutDown     = pInput->VehSigAdd.TrailerConnBeforeShutDown;
  pDest->VehSigAdd.TrailerLengthInput            = pInput->VehSigAdd.TrailerLengthInput;
  pDest->VehSigAdd.ParkAidDet_L                  = pInput->VehSigAdd.ParkAidDet_L;
  pDest->VehSigAdd.ParkAidDet_CL                 = pInput->VehSigAdd.ParkAidDet_CL;
  pDest->VehSigAdd.ParkAidDet_CR                 = pInput->VehSigAdd.ParkAidDet_CR;
  pDest->VehSigAdd.ParkAidDet_R                  = pInput->VehSigAdd.ParkAidDet_R;
  pDest->VehSigAdd.IgnitionSwitch                = pInput->VehSigAdd.IgnitionSwitch;
  pDest->VehSigAdd.eSuspensionSystem             = pInput->VehSigAdd.eSuspensionSystem ;
  pDest->VehSigAdd.eHeightLevel                  = pInput->VehSigAdd.eHeightLevel  ;
  pDest->VehSigAdd.WheelHeightLevel.FrontLeft    = pInput->VehSigAdd.WheelHeightLevel.FrontLeft;
  pDest->VehSigAdd.WheelHeightLevel.FrontRight   = pInput->VehSigAdd.WheelHeightLevel.FrontRight ;
  pDest->VehSigAdd.WheelHeightLevel.RearLeft     = pInput->VehSigAdd.WheelHeightLevel.RearLeft ;
  pDest->VehSigAdd.WheelHeightLevel.RearRight    = pInput->VehSigAdd.WheelHeightLevel.RearRight;
  pDest->VehSigAdd.AlignmentByte1                = pInput->VehSigAdd.AlignmentByte1;
  pDest->VehSigAdd.AlignmentByte2                = pInput->VehSigAdd.AlignmentByte2;

  for (i=0; i<VehSigV10::VEH_SIG_BRAKE_MAX; i++)
  {
    pDest->Brake.State[i]          = pInput->Brake.State[i];
  }

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;

  for (i=0; i<VehSigV10::VEH_SIG_POWERTRAIN_MAX; i++)
  {
    pDest->PowerTrain.State[i]     = pInput->PowerTrain.State[i];
  }

  pDest->PowerTrain.ActualGear    = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear    = pInput->PowerTrain.TargetGear;
  pDest->PowerTrain.EngineRunning = pInput->PowerTrain.EngineRunning;
  pDest->PowerTrain.FillByte      = pInput->PowerTrain.FillByte;
}

// Covert the 10th version to 11th version 
void CConvVdyInputDataVehSig::ConvertToVehSigV11(VehSigV11::VehSig_t * const pDest, const VehSigV10::VehSig_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehSigV11(pDest);

  //sSigHeader
  pDest->sSigHeader.uiTimeStamp          = pInput->sSigHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter       = pInput->sSigHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus           = pInput->sSigHeader.eSigStatus;

  //VehSigMain
  for (i=0; i<VehSigV11::VDY_SIN_POS_MAX; i++)
  {
    pDest->VehSigMain.State[i]          = pInput->VehSigMain.State[i];
  }
  //  single signal conversion would look like:
  //  pDest->VehSigMain.State[VehSigV8::VDY_SIN_POS_YWR] = ConvertIOState(VehSigV6::VDY_SIN_POS_YWR, (unsigned long *)pInput->VehSigMain.State);
  pDest->VehSigMain.ActGearPos          = ValidateValueRange<VehSigV9::ActGearPos_t>(pInput->VehSigMain.ActGearPos, 0, 20, 0);
  pDest->VehSigMain.BrakeActLevel       = ValidateValueRange<uint16>(pInput->VehSigMain.BrakeActLevel, 0, 20000, 0);
  pDest->VehSigMain.CurveC0Ext          = ValidateValueRange(pInput->VehSigMain.CurveC0Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.CurveC1Ext          = ValidateValueRange(pInput->VehSigMain.CurveC1Ext, -10000.f, 10000.f, 0.f);
  pDest->VehSigMain.LatAccel            = ValidateValueRange(pInput->VehSigMain.LatAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.LongAccel           = ValidateValueRange(pInput->VehSigMain.LongAccel, -20.f, 20.f, 0.f);
  pDest->VehSigMain.ParkBrakeState      = ValidateValueRange<VehSigV9::ParkBrakeState_t>(pInput->VehSigMain.ParkBrakeState, 0, 1, 0);
  pDest->VehSigMain.RearWhlAngle        = ValidateValueRange(pInput->VehSigMain.RearWhlAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.SideSlipAngleExt    = ValidateValueRange(pInput->VehSigMain.SideSlipAngleExt, -128.f, 128.f, 0.f);
  pDest->VehSigMain.StWheelAngle    = ValidateValueRange(pInput->VehSigMain.StWheelAngle, -128.f, 128.f, 0.f);
  pDest->VehSigMain.VehLongAccelExt = ValidateValueRange(pInput->VehSigMain.VehLongAccelExt, -20.f, 20.f, 0.f);
  pDest->VehSigMain.VehLongDirExt       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.VehLongDirExt, 0, 2, 0);
  pDest->VehSigMain.VehLongMotStateExt  = ValidateValueRange<VehSigV9::VehLongMotStateExt_t>(pInput->VehSigMain.VehLongMotStateExt, 0, 2, 0);
  pDest->VehSigMain.VehVelocityExt  = ValidateValueRange(pInput->VehSigMain.VehVelocityExt, -128.f, 150.f, 0.f);

  pDest->VehSigMain.WhlDirFrLeft       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirFrLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirFrRight      = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirFrRight, 0, 2, 0);
  pDest->VehSigMain.WhlDirReLeft       = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirReLeft, 0, 2, 0);
  pDest->VehSigMain.WhlDirReRight      = ValidateValueRange<VehSigV9::LongDirState_t>(pInput->VehSigMain.WhlDirReRight, 0, 2, 0);
  pDest->VehSigMain.WhlTicksDevFrLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevFrRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevFrRight, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReLeft  = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReLeft, 0, 255, 0);
  pDest->VehSigMain.WhlTicksDevReRight = ValidateValueRange<uint8>(pInput->VehSigMain.WhlTicksDevReRight, 0, 255, 0);

  pDest->VehSigMain.WhlVelFrLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelFrLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelFrRight   = ValidateValueRange(pInput->VehSigMain.WhlVelFrRight, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReLeft    = ValidateValueRange(pInput->VehSigMain.WhlVelReLeft, -128.f, 128.f, 0.f);
  pDest->VehSigMain.WhlVelReRight   = ValidateValueRange(pInput->VehSigMain.WhlVelReRight, -128.f, 128.f, 0.f);

  pDest->VehSigMain.YawRate         = ValidateValueRange(pInput->VehSigMain.YawRate, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateInt      = ValidateValueRange(pInput->VehSigMain.YawRateInt, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateIntTemp  = ValidateValueRange(pInput->VehSigMain.YawRateIntTemp, -150.f, 150.f, 0.f);
  pDest->VehSigMain.YawRateTemp     = ValidateValueRange(pInput->VehSigMain.YawRateTemp, -150.f, 150.f, 0.f);

  pDest->VehSigMain.VehVelocityExtMax = 0;
  pDest->VehSigMain.VehVelocityExtMin = 0;

  for (i=0; i<VehSigV11::VEH_SIG_ADD_MAX; i++)
  {
    if(pInput->VehSigAdd.State[i] != VehSigV9::VEH_SIG_ADD_IGN_SWITCH)
    {
      pDest->VehSigAdd.State[i]          = pInput->VehSigAdd.State[i];
    }
    else
    {
      pDest->VehSigAdd.State[i]          = VehSigV11::VEH_SIG_ADD_IGN_SWITCH;
    }
  }
  pDest->VehSigAdd.EnvTemp                       = pInput->VehSigAdd.EnvTemp;
  pDest->VehSigAdd.WiperState                    = pInput->VehSigAdd.WiperState; 
  pDest->VehSigAdd.WiperStage                    = pInput->VehSigAdd.WiperStage;
  pDest->VehSigAdd.WiperOutParkPos               = pInput->VehSigAdd.WiperOutParkPos;
  pDest->VehSigAdd.WiperWasherFrontState         = pInput->VehSigAdd.WiperWasherFrontState;
  pDest->VehSigAdd.RainSensor                    = pInput->VehSigAdd.RainSensor;
  pDest->VehSigAdd.TurnSignal                    = pInput->VehSigAdd.TurnSignal;
  pDest->VehSigAdd.FogLampFront                  = pInput->VehSigAdd.FogLampFront;
  pDest->VehSigAdd.FogLampRear                   = pInput->VehSigAdd.FogLampRear;
  pDest->VehSigAdd.RoadWhlAngFr                  = pInput->VehSigAdd.RoadWhlAngFr;
  pDest->VehSigAdd.RoadWhlAngRe                  = pInput->VehSigAdd.RoadWhlAngRe;
  pDest->VehSigAdd.Odometer                      = pInput->VehSigAdd.Odometer;
  pDest->VehSigAdd.GasPedalPos                   = pInput->VehSigAdd.GasPedalPos;
  pDest->VehSigAdd.KickDown                      = pInput->VehSigAdd.KickDown;
  pDest->VehSigAdd.BrakePedalPressed             = pInput->VehSigAdd.BrakePedalPressed;
  pDest->VehSigAdd.DriverTired                   = pInput->VehSigAdd.DriverTired;
  pDest->VehSigAdd.SpeedUnit                     = pInput->VehSigAdd.SpeedUnit;
  pDest->VehSigAdd.SpeedoSpeed                   = pInput->VehSigAdd.SpeedoSpeed;
  pDest->VehSigAdd.TrailerConnection             = pInput->VehSigAdd.TrailerConnection;
  pDest->VehSigAdd.TrailerConnBeforeShutDown     = pInput->VehSigAdd.TrailerConnBeforeShutDown;
  pDest->VehSigAdd.TrailerLengthInput            = pInput->VehSigAdd.TrailerLengthInput;
  pDest->VehSigAdd.ParkAidDet_L                  = pInput->VehSigAdd.ParkAidDet_L;
  pDest->VehSigAdd.ParkAidDet_CL                 = pInput->VehSigAdd.ParkAidDet_CL;
  pDest->VehSigAdd.ParkAidDet_CR                 = pInput->VehSigAdd.ParkAidDet_CR;
  pDest->VehSigAdd.ParkAidDet_R                  = pInput->VehSigAdd.ParkAidDet_R;
  pDest->VehSigAdd.IgnitionSwitch                = pInput->VehSigAdd.IgnitionSwitch;
  pDest->VehSigAdd.eSuspensionSystem             = pInput->VehSigAdd.eSuspensionSystem ;
  pDest->VehSigAdd.eHeightLevel                  = pInput->VehSigAdd.eHeightLevel  ;
  pDest->VehSigAdd.WheelHeightLevel.FrontLeft    = pInput->VehSigAdd.WheelHeightLevel.FrontLeft;
  pDest->VehSigAdd.WheelHeightLevel.FrontRight   = pInput->VehSigAdd.WheelHeightLevel.FrontRight ;
  pDest->VehSigAdd.WheelHeightLevel.RearLeft     = pInput->VehSigAdd.WheelHeightLevel.RearLeft ;
  pDest->VehSigAdd.WheelHeightLevel.RearRight    = pInput->VehSigAdd.WheelHeightLevel.RearRight;
  pDest->VehSigAdd.AlignmentByte1                = pInput->VehSigAdd.AlignmentByte1;
  pDest->VehSigAdd.AlignmentByte2                = pInput->VehSigAdd.AlignmentByte2;

  for (i=0; i<VehSigV11::VEH_SIG_BRAKE_MAX; i++)
  {
    pDest->Brake.State[i]          = pInput->Brake.State[i];
  }

  pDest->Brake.ABSCtrl = pInput->Brake.ABSCtrl;
  pDest->Brake.TCSCtrl = pInput->Brake.TCSCtrl;

  for (i=0; i<VehSigV11::VEH_SIG_POWERTRAIN_MAX; i++)
  {
    pDest->PowerTrain.State[i]     = pInput->PowerTrain.State[i];
  }

  pDest->PowerTrain.ActualGear    = pInput->PowerTrain.ActualGear;
  pDest->PowerTrain.TargetGear    = pInput->PowerTrain.TargetGear;
  pDest->PowerTrain.EngineRunning = pInput->PowerTrain.EngineRunning;
  pDest->PowerTrain.FillByte      = pInput->PowerTrain.FillByte;
}


bool CConvVdyInputDataVehSig::DecodeVDYInput(VehSigV2::VehSig_t * const pVehSig, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData)
{
  bool bRet = false;

  // VDYinput can be decoded if the type is opaque and at least the 4 byte
  // version number is decodable
  if ((ePPortType == simOPAQUE_t) && (ulPPortSize > 4))
  {
    // Initialize default values
    InitDefaultVehSigV2(pVehSig);

    if (ulPPortSize == SUPPORTED_SIZE[CConvVdyInputDataVehSig::VDY_IN_V1])
    {
      const VDY_SIG_300::VDYInputData_v1_t * const pTyped = reinterpret_cast<const VDY_SIG_300::VDYInputData_v1_t *>(pPPortData);
      pVehSig->VehSigMain.WhlDirFrLeft       = pTyped->Signals.WhlDirFrLeft;
      pVehSig->VehSigMain.WhlDirFrRight      = pTyped->Signals.WhlDirFrRight;
      pVehSig->VehSigMain.WhlDirFrRight      = pTyped->Signals.WhlDirFrRight;
      pVehSig->VehSigMain.WhlDirReRight      = pTyped->Signals.WhlDirReRight;
      pVehSig->VehSigMain.WhlTicksDevFrLeft  = pTyped->Signals.WhlTicksDevFrLeft;
      pVehSig->VehSigMain.WhlTicksDevFrRight = pTyped->Signals.WhlTicksDevFrRight;
      pVehSig->VehSigMain.WhlTicksDevReLeft  = pTyped->Signals.WhlTicksDevReLeft;
      pVehSig->VehSigMain.WhlTicksDevReRight = pTyped->Signals.WhlTicksDevReRight;

      pVehSig->VehSigMain.WhlVelFrLeft  = pTyped->Signals.WhlVelFrLeft;
      pVehSig->VehSigMain.WhlVelFrRight = pTyped->Signals.WhlVelFrRight;
      pVehSig->VehSigMain.WhlVelReLeft  = pTyped->Signals.WhlVelReLeft;
      pVehSig->VehSigMain.WhlVelReRight = pTyped->Signals.WhlVelReRight;

      pVehSig->VehSigMain.YawRate       = pTyped->Signals.YawRate;
      pVehSig->VehSigMain.YawRateTemp   = pTyped->Signals.YawRateTemp;
      pVehSig->VehSigMain.StWheelAngle  = pTyped->Signals.StWheelAngle;
      pVehSig->VehSigMain.LatAccel      = pTyped->Signals.LatAccel;
      pVehSig->VehSigMain.YawRateInt    = pTyped->Signals.YawRateInt;
      pVehSig->VehSigMain.YawRateIntTemp =pTyped->Signals.YawRateIntTemp;
      pVehSig->VehSigMain.LongAccel     = pTyped->Signals.LongAccel;
      pVehSig->VehSigMain.RearWhlAngle  = pTyped->Signals.RearWhlAngle;
      pVehSig->VehSigMain.VehVelocityExt  = pTyped->Signals.VehVelocityExt;
      pVehSig->VehSigMain.VehLongAccelExt = pTyped->Signals.VehLongAccelExt;
      pVehSig->VehSigMain.ActGearPos      = pTyped->Signals.ActGearPos;
      pVehSig->VehSigMain.BrakeActLevel   = pTyped->Signals.BrakeActLevel;
      pVehSig->VehSigMain.ParkBrakeState  = pTyped->Signals.ParkBrakeState;
      pVehSig->VehSigMain.VehLongDirExt   = pTyped->Signals.VehLongDirExt;
      pVehSig->VehSigMain.VehLongMotStateExt = pTyped->Signals.VehLongMotStateExt;
      pVehSig->VehSigMain.CurveC0Ext      = pTyped->Signals.CurveC0Ext;
      pVehSig->VehSigMain.CurveC1Ext      = pTyped->Signals.CurveC1Ext;
      pVehSig->VehSigMain.SideSlipAngleExt  =pTyped->Signals.SideSlipAngleExt;

      memcpy_s(pVehSig->VehSigMain.State, sizeof(pVehSig->VehSigMain.State), pTyped->Signals.State ,sizeof(pTyped->Signals.State));

      bRet = true;
    }
    else if (ulPPortSize == SUPPORTED_SIZE[CConvVdyInputDataVehSig::VDY_IN_V2])
    {
      const VDY_SIG_300::VDYInputData_v2_t * const pTyped = reinterpret_cast<const VDY_SIG_300::VDYInputData_v2_t *>(pPPortData);
      pVehSig->VehSigMain.WhlDirFrLeft       = pTyped->Signals.WhlDirFrLeft;
      pVehSig->VehSigMain.WhlDirFrRight      = pTyped->Signals.WhlDirFrRight;
      pVehSig->VehSigMain.WhlDirFrRight      = pTyped->Signals.WhlDirFrRight;
      pVehSig->VehSigMain.WhlDirReRight      = pTyped->Signals.WhlDirReRight;
      pVehSig->VehSigMain.WhlTicksDevFrLeft  = pTyped->Signals.WhlTicksDevFrLeft;
      pVehSig->VehSigMain.WhlTicksDevFrRight = pTyped->Signals.WhlTicksDevFrRight;
      pVehSig->VehSigMain.WhlTicksDevReLeft  = pTyped->Signals.WhlTicksDevReLeft;
      pVehSig->VehSigMain.WhlTicksDevReRight = pTyped->Signals.WhlTicksDevReRight;

      pVehSig->VehSigMain.WhlVelFrLeft  = pTyped->Signals.WhlVelFrLeft;
      pVehSig->VehSigMain.WhlVelFrRight = pTyped->Signals.WhlVelFrRight;
      pVehSig->VehSigMain.WhlVelReLeft  = pTyped->Signals.WhlVelReLeft;
      pVehSig->VehSigMain.WhlVelReRight = pTyped->Signals.WhlVelReRight;

      pVehSig->VehSigMain.YawRate       = pTyped->Signals.YawRate;
      pVehSig->VehSigMain.YawRateTemp   = pTyped->Signals.YawRateTemp;
      pVehSig->VehSigMain.StWheelAngle  = pTyped->Signals.StWheelAngle;
      pVehSig->VehSigMain.LatAccel      = pTyped->Signals.LatAccel;
      pVehSig->VehSigMain.YawRateInt    = pTyped->Signals.YawRateInt;
      pVehSig->VehSigMain.YawRateIntTemp =pTyped->Signals.YawRateIntTemp;
      pVehSig->VehSigMain.LongAccel     = pTyped->Signals.LongAccel;
      pVehSig->VehSigMain.RearWhlAngle  = pTyped->Signals.RearWhlAngle;
      pVehSig->VehSigMain.VehVelocityExt  = pTyped->Signals.VehVelocityExt;
      pVehSig->VehSigMain.VehLongAccelExt = pTyped->Signals.VehLongAccelExt;
      pVehSig->VehSigMain.ActGearPos      = pTyped->Signals.ActGearPos;
      pVehSig->VehSigMain.BrakeActLevel   = pTyped->Signals.BrakeActLevel;
      pVehSig->VehSigMain.ParkBrakeState  = pTyped->Signals.ParkBrakeState;
      pVehSig->VehSigMain.VehLongDirExt   = pTyped->Signals.VehLongDirExt;
      pVehSig->VehSigMain.VehLongMotStateExt = pTyped->Signals.VehLongMotStateExt;
      pVehSig->VehSigMain.CurveC0Ext      = pTyped->Signals.CurveC0Ext;
      pVehSig->VehSigMain.CurveC1Ext      = pTyped->Signals.CurveC1Ext;
      pVehSig->VehSigMain.SideSlipAngleExt  =pTyped->Signals.SideSlipAngleExt;

      memcpy_s(pVehSig->VehSigMain.State, sizeof(pVehSig->VehSigMain.State), pTyped->Signals.State ,sizeof(pTyped->Signals.State));

      bRet = true;
    }
    else if (ulPPortSize == SUPPORTED_SIZE[CConvVdyInputDataVehSig::VDY_IN_V3])
    {
      const VDY_SIG_300::VDYInputData_v3_t * const pTyped = reinterpret_cast<const VDY_SIG_300::VDYInputData_v3_t *>(pPPortData);
      pVehSig->VehSigMain.WhlDirFrLeft       = pTyped->Signals.WhlDirFrLeft;
      pVehSig->VehSigMain.WhlDirFrRight      = pTyped->Signals.WhlDirFrRight;
      pVehSig->VehSigMain.WhlDirFrRight      = pTyped->Signals.WhlDirFrRight;
      pVehSig->VehSigMain.WhlDirReRight      = pTyped->Signals.WhlDirReRight;
      pVehSig->VehSigMain.WhlTicksDevFrLeft  = pTyped->Signals.WhlTicksDevFrLeft;
      pVehSig->VehSigMain.WhlTicksDevFrRight = pTyped->Signals.WhlTicksDevFrRight;
      pVehSig->VehSigMain.WhlTicksDevReLeft  = pTyped->Signals.WhlTicksDevReLeft;
      pVehSig->VehSigMain.WhlTicksDevReRight = pTyped->Signals.WhlTicksDevReRight;

      pVehSig->VehSigMain.WhlVelFrLeft  = pTyped->Signals.WhlVelFrLeft;
      pVehSig->VehSigMain.WhlVelFrRight = pTyped->Signals.WhlVelFrRight;
      pVehSig->VehSigMain.WhlVelReLeft  = pTyped->Signals.WhlVelReLeft;
      pVehSig->VehSigMain.WhlVelReRight = pTyped->Signals.WhlVelReRight;

      pVehSig->VehSigMain.YawRate       = pTyped->Signals.YawRate;
      pVehSig->VehSigMain.YawRateTemp   = pTyped->Signals.YawRateTemp;
      pVehSig->VehSigMain.StWheelAngle  = pTyped->Signals.StWheelAngle;
      pVehSig->VehSigMain.LatAccel      = pTyped->Signals.LatAccel;
      pVehSig->VehSigMain.YawRateInt    = pTyped->Signals.YawRateInt;
      pVehSig->VehSigMain.YawRateIntTemp =pTyped->Signals.YawRateIntTemp;
      pVehSig->VehSigMain.LongAccel     = pTyped->Signals.LongAccel;
      pVehSig->VehSigMain.RearWhlAngle  = pTyped->Signals.RearWhlAngle;
      pVehSig->VehSigMain.VehVelocityExt  = pTyped->Signals.VehVelocityExt;
      pVehSig->VehSigMain.VehLongAccelExt = pTyped->Signals.VehLongAccelExt;
      pVehSig->VehSigMain.ActGearPos      = pTyped->Signals.ActGearPos;
      pVehSig->VehSigMain.BrakeActLevel   = pTyped->Signals.BrakeActLevel;
      pVehSig->VehSigMain.ParkBrakeState  = pTyped->Signals.ParkBrakeState;
      pVehSig->VehSigMain.VehLongDirExt   = pTyped->Signals.VehLongDirExt;
      pVehSig->VehSigMain.VehLongMotStateExt = pTyped->Signals.VehLongMotStateExt;
      pVehSig->VehSigMain.CurveC0Ext      = pTyped->Signals.CurveC0Ext;
      pVehSig->VehSigMain.CurveC1Ext      = pTyped->Signals.CurveC1Ext;
      pVehSig->VehSigMain.SideSlipAngleExt  =pTyped->Signals.SideSlipAngleExt;

      memcpy_s(pVehSig->VehSigMain.State, sizeof(pVehSig->VehSigMain.State), pTyped->Signals.State ,sizeof(pTyped->Signals.State));

      bRet = true;
    }
    else if (ulPPortSize == SUPPORTED_SIZE[CConvVdyInputDataVehSig::VDY_IN_V4])
    {
      const VDY_SIG_300::VDYInputData_v4_t * const pTyped = reinterpret_cast<const VDY_SIG_300::VDYInputData_v4_t *>(pPPortData);
      pVehSig->VehSigMain.WhlDirFrLeft       = pTyped->Signals.WhlDirFrLeft;
      pVehSig->VehSigMain.WhlDirFrRight      = pTyped->Signals.WhlDirFrRight;
      pVehSig->VehSigMain.WhlDirFrRight      = pTyped->Signals.WhlDirFrRight;
      pVehSig->VehSigMain.WhlDirReRight      = pTyped->Signals.WhlDirReRight;
      pVehSig->VehSigMain.WhlTicksDevFrLeft  = pTyped->Signals.WhlTicksDevFrLeft;
      pVehSig->VehSigMain.WhlTicksDevFrRight = pTyped->Signals.WhlTicksDevFrRight;
      pVehSig->VehSigMain.WhlTicksDevReLeft  = pTyped->Signals.WhlTicksDevReLeft;
      pVehSig->VehSigMain.WhlTicksDevReRight = pTyped->Signals.WhlTicksDevReRight;

      pVehSig->VehSigMain.WhlVelFrLeft  = pTyped->Signals.WhlVelFrLeft;
      pVehSig->VehSigMain.WhlVelFrRight = pTyped->Signals.WhlVelFrRight;
      pVehSig->VehSigMain.WhlVelReLeft  = pTyped->Signals.WhlVelReLeft;
      pVehSig->VehSigMain.WhlVelReRight = pTyped->Signals.WhlVelReRight;

      pVehSig->VehSigMain.YawRate       = pTyped->Signals.YawRate;
      pVehSig->VehSigMain.YawRateTemp   = pTyped->Signals.YawRateTemp;
      pVehSig->VehSigMain.StWheelAngle  = pTyped->Signals.StWheelAngle;
      pVehSig->VehSigMain.LatAccel      = pTyped->Signals.LatAccel;
      pVehSig->VehSigMain.YawRateInt    = pTyped->Signals.YawRateInt;
      pVehSig->VehSigMain.YawRateIntTemp =pTyped->Signals.YawRateIntTemp;
      pVehSig->VehSigMain.LongAccel     = pTyped->Signals.LongAccel;
      pVehSig->VehSigMain.RearWhlAngle  = pTyped->Signals.RearWhlAngle;
      pVehSig->VehSigMain.VehVelocityExt  = pTyped->Signals.VehVelocityExt;
      pVehSig->VehSigMain.VehLongAccelExt = pTyped->Signals.VehLongAccelExt;
      pVehSig->VehSigMain.ActGearPos      = pTyped->Signals.ActGearPos;
      pVehSig->VehSigMain.BrakeActLevel   = pTyped->Signals.BrakeActLevel;
      pVehSig->VehSigMain.ParkBrakeState  = pTyped->Signals.ParkBrakeState;
      pVehSig->VehSigMain.VehLongDirExt   = pTyped->Signals.VehLongDirExt;
      pVehSig->VehSigMain.VehLongMotStateExt = pTyped->Signals.VehLongMotStateExt;
      pVehSig->VehSigMain.CurveC0Ext      = pTyped->Signals.CurveC0Ext;
      pVehSig->VehSigMain.CurveC1Ext      = pTyped->Signals.CurveC1Ext;
      pVehSig->VehSigMain.SideSlipAngleExt  =pTyped->Signals.SideSlipAngleExt;

      memcpy_s(pVehSig->VehSigMain.State, sizeof(pVehSig->VehSigMain.State), pTyped->Signals.State ,sizeof(pTyped->Signals.State));

      bRet = true;
    }
    else
    {
      bRet = false;
    }
  }
  else
  {
    bRet = false;
  }
  return bRet;
}


long CConvVdyInputDataVehSig::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
  void* pPPortData,
  void** pOutData, unsigned long& ulOutSize)
{
  long lRet;

  const uint32 version = GetRteInterfaceVersion(ePPortType,ulPPortSize, pPPortData);
  CVersionInfoImpl ProvidePortVersionInfo(CONV_I32VERSION_TO_TUPPLE(version));

  // If sizes and versions match, then just take data
  if ((ePPortType == eRPortType) && (ulPPortSize == ulRPortSize) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))))
  {
    // Port types sizes and versions match, we can directly use the input data
    *pOutData = pPPortData;
    ulOutSize = ulPPortSize;
    lRet = SIM_ERR_OK;
  }
  else
  {
    // Some conversion is needed, first level branching based on request port size/version
    // Check if destination is V11 version and the size of the request port equals the V11 size
    if (    (ulRPortSize == sizeof(m_VehSigV11))
         && (requestPortVersionInfo.Equals(&VEH_SIG_V11_VERINFO)))
    {
      // Check if source is V10 version (if provided) and the size of the provided port equals the V10 size
      if ((ulPPortSize == sizeof(m_VehSigV10)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V10_VERINFO))))
      {
        ConvertToVehSigV11(&m_VehSigV11, reinterpret_cast<const VehSigV10::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV11;
        ulOutSize = sizeof(m_VehSigV11);
        lRet = SIM_ERR_OK;
      }

      // Check if source is V9 version (if provided) and the size of the provided port equals the V9 size
      else if ((ulPPortSize == sizeof(m_VehSigV9)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V9_VERINFO))))
      {
        ConvertToVehSigV10(&m_VehSigV10, reinterpret_cast<const VehSigV9::VehSig_t*>(pPPortData));
        ConvertToVehSigV11(&m_VehSigV11, &m_VehSigV10);
        *pOutData = &m_VehSigV11;
        ulOutSize = sizeof(m_VehSigV11);
        lRet = SIM_ERR_OK;
      }
      // Check if source is V8 version (if provided) and the size of the provided port equals the V8 size
      else if ((ulPPortSize == sizeof(m_VehSigV8)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO))))
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV8::VehSig_t*>(pPPortData));
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        ConvertToVehSigV11(&m_VehSigV11, &m_VehSigV10);
        *pOutData = &m_VehSigV11;
        ulOutSize = sizeof(m_VehSigV11);
        lRet = SIM_ERR_OK;
      }
      // Check if source is V7 version (if provided) and the size of the provided port equals the V7 size
      else if ((ulPPortSize == sizeof(m_VehSigV7)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO))))
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV7::VehSig_t*>(pPPortData));
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        ConvertToVehSigV11(&m_VehSigV11, &m_VehSigV10);
        *pOutData = &m_VehSigV11;
        ulOutSize = sizeof(m_VehSigV11);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV1)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO))))
      {
        ConvertToVehSigV2(&m_VehSigV2, reinterpret_cast<const VehSigV1::VehSig_t*>(pPPortData));
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV2);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        ConvertToVehSigV11(&m_VehSigV11, &m_VehSigV10);
        *pOutData = &m_VehSigV11;
        ulOutSize = sizeof(m_VehSigV11);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV2)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V3_VERINFO)))))
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV2::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        ConvertToVehSigV11(&m_VehSigV11, &m_VehSigV10);
        *pOutData = &m_VehSigV11;
        ulOutSize = sizeof(m_VehSigV11);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV4)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO))))
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV4::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        ConvertToVehSigV11(&m_VehSigV11, &m_VehSigV10);
        *pOutData = &m_VehSigV11;
        ulOutSize = sizeof(m_VehSigV11);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV5)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V5_VERINFO))))
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV5::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        ConvertToVehSigV11(&m_VehSigV11, &m_VehSigV10);
        *pOutData = &m_VehSigV11;
        ulOutSize = sizeof(m_VehSigV11);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV6)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO))))
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV6::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        ConvertToVehSigV11(&m_VehSigV11, &m_VehSigV10);
        *pOutData = &m_VehSigV11;
        ulOutSize = sizeof(m_VehSigV11);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_NO_CONVERSION;
      }
    }
    // Check if destination is V10 version and the size of the request port equals the V10 size
    else if (    (ulRPortSize == sizeof(m_VehSigV10))
         && (requestPortVersionInfo.Equals(&VEH_SIG_V10_VERINFO)))
    {
      // Check if source is V11 version (if provided) and the size of the provided port equals the V11 size
      if ((ulPPortSize == sizeof(m_VehSigV11)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V11_VERINFO))))
      {
        ConvertToVehSigV10(&m_VehSigV10, reinterpret_cast<const VehSigV11::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV10;
        ulOutSize = sizeof(m_VehSigV10);
        lRet = SIM_ERR_OK;
      }
      // Check if source is V9 version (if provided) and the size of the provided port equals the V9 size
      else if ((ulPPortSize == sizeof(m_VehSigV9)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V9_VERINFO))))
      {
        ConvertToVehSigV10(&m_VehSigV10, reinterpret_cast<const VehSigV9::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV10;
        ulOutSize = sizeof(m_VehSigV10);
        lRet = SIM_ERR_OK;
      }
      // Check if source is V8 version (if provided) and the size of the provided port equals the V8 size
      else if ((ulPPortSize == sizeof(m_VehSigV8)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO))))
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV8::VehSig_t*>(pPPortData));
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        *pOutData = &m_VehSigV10;
        ulOutSize = sizeof(m_VehSigV10);
        lRet = SIM_ERR_OK;
      }
      // Check if source is V7 version (if provided) and the size of the provided port equals the V7 size
      else if ((ulPPortSize == sizeof(m_VehSigV7)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO))))
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV7::VehSig_t*>(pPPortData));
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        *pOutData = &m_VehSigV10;
        ulOutSize = sizeof(m_VehSigV10);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV1)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO))))
      {
        ConvertToVehSigV2(&m_VehSigV2, reinterpret_cast<const VehSigV1::VehSig_t*>(pPPortData));
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV2);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        *pOutData = &m_VehSigV10;
        ulOutSize = sizeof(m_VehSigV10);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV2)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V3_VERINFO)))))
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV2::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        *pOutData = &m_VehSigV10;
        ulOutSize = sizeof(m_VehSigV10);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV4)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO))))
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV4::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        *pOutData = &m_VehSigV10;
        ulOutSize = sizeof(m_VehSigV10);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV5)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V5_VERINFO))))
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV5::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        *pOutData = &m_VehSigV10;
        ulOutSize = sizeof(m_VehSigV10);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV6)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO))))
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV6::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        ConvertToVehSigV10(&m_VehSigV10, &m_VehSigV9);
        *pOutData = &m_VehSigV10;
        ulOutSize = sizeof(m_VehSigV10);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    // Check if destination is V9 version and the size of the request port equals the V9 size
    else if (    (ulRPortSize == sizeof(m_VehSigV9))
         && (requestPortVersionInfo.Equals(&VEH_SIG_V9_VERINFO))  )
    {
      // Check if source is V11 version (if provided) and the size of the provided port equals the V11 size
      if ((ulPPortSize == sizeof(m_VehSigV11)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V11_VERINFO))))
      {
        ConvertToVehSigV10(&m_VehSigV10, reinterpret_cast<const VehSigV11::VehSig_t*>(pPPortData));
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV10);
        *pOutData = &m_VehSigV9;
        ulOutSize = sizeof(m_VehSigV9);
        lRet = SIM_ERR_OK;
      }
      // Check if source is V10 version (if provided) and the size of the provided port equals the V10 size
      else if ((ulPPortSize == sizeof(m_VehSigV10)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V10_VERINFO))))
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV10::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV9;
        ulOutSize = sizeof(m_VehSigV9);
        lRet = SIM_ERR_OK;
      }
      // Check if source is V8 version (if provided) and the size of the provided port equals the V8 size
      else if ((ulPPortSize == sizeof(m_VehSigV8)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO))))
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV8::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV9;
        ulOutSize = sizeof(m_VehSigV9);
        lRet = SIM_ERR_OK;
      }
      // Check if source is V7 version (if provided) and the size of the provided port equals the V7 size
      else if ((ulPPortSize == sizeof(m_VehSigV7)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO))))
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV7::VehSig_t*>(pPPortData));
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        *pOutData = &m_VehSigV9;
        ulOutSize = sizeof(m_VehSigV9);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV1)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO))))
      {
        ConvertToVehSigV2(&m_VehSigV2, reinterpret_cast<const VehSigV1::VehSig_t*>(pPPortData));
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV2);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        *pOutData = &m_VehSigV9;
        ulOutSize = sizeof(m_VehSigV9);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV2)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V3_VERINFO)))))
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV2::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        *pOutData = &m_VehSigV9;
        ulOutSize = sizeof(m_VehSigV9);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV4)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO))))
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV4::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        *pOutData = &m_VehSigV9;
        ulOutSize = sizeof(m_VehSigV9);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV5)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V5_VERINFO))))
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV5::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        *pOutData = &m_VehSigV9;
        ulOutSize = sizeof(m_VehSigV9);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV6)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO))))
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV6::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV8);
        *pOutData = &m_VehSigV9;
        ulOutSize = sizeof(m_VehSigV9);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }	 
    }
    // Check if destination is V8 version and the size of the request port equals the V8 size
    else if (    (ulRPortSize == sizeof(m_VehSigV8))
         && (requestPortVersionInfo.Equals(&VEH_SIG_V8_VERINFO))  )
    {
      // Check if source is V11 version (if provided) and the size of the provided port equals the V11 size
      if ((ulPPortSize == sizeof(m_VehSigV11)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V11_VERINFO))))
      {
        ConvertToVehSigV10(&m_VehSigV10, reinterpret_cast<const VehSigV11::VehSig_t*>(pPPortData));
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV10);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);

        *pOutData = &m_VehSigV8;
        ulOutSize = sizeof(m_VehSigV8);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV8)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO))))
      {
        // Provide port sizes match and versions are VEH_PAR_V8_VERINFO
        // Forward the data directly:
        *pOutData = pPPortData;
        ulOutSize = ulPPortSize;
        lRet = SIM_ERR_OK;
      }
      // Check if source is V10 version (if provided) and the size of the provided port equals the V10 size
      else if ((ulPPortSize == sizeof(m_VehSigV10)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V10_VERINFO))))
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV10::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);
        *pOutData = &m_VehSigV8;
        ulOutSize = sizeof(m_VehSigV8);
        lRet = SIM_ERR_OK;
      }
      // Check if source is V9 version (if provided) and the size of the provided port equals the V9 size
      else if ((ulPPortSize == sizeof(m_VehSigV9)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V9_VERINFO))))
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV9::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV8;
        ulOutSize = sizeof(m_VehSigV8);
        lRet = SIM_ERR_OK;
      }
      // Check if source is V7 version (if provided) and the size of the provided port equals the V7 size
      else if ((ulPPortSize == sizeof(m_VehSigV7)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO))))
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV7::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV8;
        ulOutSize = sizeof(m_VehSigV8);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV1)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO))))
      {
        ConvertToVehSigV2(&m_VehSigV2, reinterpret_cast<const VehSigV1::VehSig_t*>(pPPortData));
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV2);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        *pOutData = &m_VehSigV8;
        ulOutSize = sizeof(m_VehSigV8);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV2)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V3_VERINFO)))))
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV2::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        *pOutData = &m_VehSigV8;
        ulOutSize = sizeof(m_VehSigV8);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV4)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO))))
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV4::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        *pOutData = &m_VehSigV8;
        ulOutSize = sizeof(m_VehSigV8);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV5)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V5_VERINFO))))
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV5::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        *pOutData = &m_VehSigV8;
        ulOutSize = sizeof(m_VehSigV8);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV6)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO))))
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV6::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV7);
        *pOutData = &m_VehSigV8;
        ulOutSize = sizeof(m_VehSigV8);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }	 
    }
    // Check if destination is V2 version. It is so if the size of the request port equals the V2
    // size & the the request port version is V2 (also handle special case when no version information
    // is provided for the request port, ie.: version number is zero)
    else if ((ulRPortSize == sizeof(m_VehSigV2)) && 
      ((requestPortVersionInfo.Equals(&VEH_SIG_V2_VERINFO) || (requestPortVersionInfo.Equals(&VEH_SIG_V3_VERINFO)))))
    {
      if ((ulPPortSize == sizeof(m_VehSigV2)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO))))
      {
        // Provide port sizes match and versions are VEH_PAR_V8_VERINFO
        // Forward the data directly:
        *pOutData = pPPortData;
        ulOutSize = ulPPortSize;
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV1)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO))))
      {
        ConvertToVehSigV2(&m_VehSigV2, reinterpret_cast<const VehSigV1::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV2;
        ulOutSize = sizeof(m_VehSigV2);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV4)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO)))) 
      {
        ConvertToVehSigV2(&m_VehSigV2, reinterpret_cast<const VehSigV4::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV2;
        ulOutSize = sizeof(m_VehSigV2);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV5)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V5_VERINFO)))) 
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV5::VehSig_t*>(pPPortData));
        ConvertToVehSigV2(&m_VehSigV2, &m_VehSigV4);
        *pOutData = &m_VehSigV2;
        ulOutSize = sizeof(m_VehSigV2);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV6)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO)))) 
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV6::VehSig_t*>(pPPortData));
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        ConvertToVehSigV2(&m_VehSigV2, &m_VehSigV4);
        *pOutData = &m_VehSigV2;
        ulOutSize = sizeof(m_VehSigV2);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV7)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO)))) 
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV7::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        ConvertToVehSigV2(&m_VehSigV2, &m_VehSigV4);
        *pOutData = &m_VehSigV2;
        ulOutSize = sizeof(m_VehSigV2);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV8)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO)))) 
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV8::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        ConvertToVehSigV2(&m_VehSigV2, &m_VehSigV4);
        *pOutData = &m_VehSigV2;
        ulOutSize = sizeof(m_VehSigV2);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV9)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V9_VERINFO)))) 
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV9::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        ConvertToVehSigV2(&m_VehSigV2, &m_VehSigV4);
        *pOutData = &m_VehSigV2;
        ulOutSize = sizeof(m_VehSigV2);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV10)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V10_VERINFO)))) 
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV10::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        ConvertToVehSigV2(&m_VehSigV2, &m_VehSigV4);
        *pOutData = &m_VehSigV2;
        ulOutSize = sizeof(m_VehSigV2);
        lRet = SIM_ERR_OK;
      }
      else
      {
        if (DecodeVDYInput(&m_VehSigV2, ePPortType, ulPPortSize, pPPortData))
        {
          *pOutData = &m_VehSigV2;
          ulOutSize = sizeof(m_VehSigV2);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }	 
    }

    else if ((ulRPortSize == sizeof(m_VehSigV1)) && (requestPortVersionInfo.Equals(&VEH_SIG_V1_VERINFO)))
    {
      if ((ulPPortSize == sizeof(m_VehSigV1)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO))))
      {
        // Provide port sizes match and versions are VEH_PAR_V8_VERINFO
        // Forward the data directly:
        *pOutData = pPPortData;
        ulOutSize = ulPPortSize;
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV2)) && 
        ((pProvidePortVersionInfo == NULL) || 
        (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V3_VERINFO)) ))
      {
        ConvertToVehSigV1(&m_VehSigV1, reinterpret_cast<const VehSigV2::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV1;
        ulOutSize = sizeof(m_VehSigV1);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV4)) && 
        ((pProvidePortVersionInfo == NULL) || 
        (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO))))
      {	   
        ConvertToVehSigV1(&m_VehSigV1, reinterpret_cast<const VehSigV4::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV1;
        ulOutSize = sizeof(m_VehSigV1);
        lRet = SIM_ERR_OK;    
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV5)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V5_VERINFO)))) 
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV5::VehSig_t*>(pPPortData));
        ConvertToVehSigV1(&m_VehSigV1, &m_VehSigV4);
        *pOutData = &m_VehSigV1;
        ulOutSize = sizeof(m_VehSigV1);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV6)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO)))) 
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV6::VehSig_t*>(pPPortData));
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        ConvertToVehSigV1(&m_VehSigV1, &m_VehSigV4);
        *pOutData = &m_VehSigV1;
        ulOutSize = sizeof(m_VehSigV1);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV7)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO)))) 
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV7::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        ConvertToVehSigV1(&m_VehSigV1, &m_VehSigV4);
        *pOutData = &m_VehSigV1;
        ulOutSize = sizeof(m_VehSigV1);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV8)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO)))) 
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV8::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        ConvertToVehSigV1(&m_VehSigV1, &m_VehSigV4);
        *pOutData = &m_VehSigV1;
        ulOutSize = sizeof(m_VehSigV1);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV9)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V9_VERINFO)))) 
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV9::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        ConvertToVehSigV1(&m_VehSigV1, &m_VehSigV4);
        *pOutData = &m_VehSigV1;
        ulOutSize = sizeof(m_VehSigV1);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV10)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V10_VERINFO)))) 
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV10::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        ConvertToVehSigV1(&m_VehSigV1, &m_VehSigV4);
        *pOutData = &m_VehSigV1;
        ulOutSize = sizeof(m_VehSigV1);
        lRet = SIM_ERR_OK;
      }
      else
      {
        if (DecodeVDYInput(&m_VehSigV2, ePPortType, ulPPortSize, pPPortData))
        {
          ConvertToVehSigV1(&m_VehSigV1, &m_VehSigV2);
          *pOutData = &m_VehSigV1;
          ulOutSize = sizeof(m_VehSigV1);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
    }
    else if ((ulRPortSize == sizeof(m_VehSigV4)) && (requestPortVersionInfo.Equals(&VEH_SIG_V4_VERINFO)))
    {
      if ((ulPPortSize == sizeof(m_VehSigV4)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO))))
      {
        // Provide port sizes match and versions are VEH_PAR_V8_VERINFO
        // Forward the data directly:
        *pOutData = pPPortData;
        ulOutSize = ulPPortSize;
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV1)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO))))
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV1::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV4;
        ulOutSize = sizeof(m_VehSigV4);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV2)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V3_VERINFO)))))
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV2::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV4;
        ulOutSize = sizeof(m_VehSigV4);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV5)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V5_VERINFO))))
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV5::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV4;
        ulOutSize = sizeof(m_VehSigV4);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV6)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO)))) 
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV6::VehSig_t*>(pPPortData));
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        *pOutData = &m_VehSigV4;
        ulOutSize = sizeof(m_VehSigV4);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV7)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO)))) 
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV7::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        *pOutData = &m_VehSigV4;
        ulOutSize = sizeof(m_VehSigV4);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV8)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO)))) 
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV8::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        *pOutData = &m_VehSigV4;
        ulOutSize = sizeof(m_VehSigV4);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV9)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V9_VERINFO)))) 
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV9::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        *pOutData = &m_VehSigV4;
        ulOutSize = sizeof(m_VehSigV4);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV10)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V10_VERINFO)))) 
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV10::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV5);
        *pOutData = &m_VehSigV4;
        ulOutSize = sizeof(m_VehSigV4);
        lRet = SIM_ERR_OK;
      }
      else
      {
        if (DecodeVDYInput(&m_VehSigV2, ePPortType, ulPPortSize, pPPortData))
        {
          ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV2);
          *pOutData = &m_VehSigV4;
          ulOutSize = sizeof(m_VehSigV4);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
    }
    else if ((ulRPortSize == sizeof(m_VehSigV5)) && (requestPortVersionInfo.Equals(&VEH_SIG_V5_VERINFO)))
    {
      if ((ulPPortSize == sizeof(m_VehSigV5)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V5_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V5_VERINFO))))
      {
        // Provide port sizes match and versions are VEH_PAR_V8_VERINFO
        // Forward the data directly:
        *pOutData = pPPortData;
        ulOutSize = ulPPortSize;
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV1)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO))))
      {
        ConvertToVehSigV2(&m_VehSigV2, reinterpret_cast<const VehSigV1::VehSig_t*>(pPPortData));
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV2);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        *pOutData = &m_VehSigV5;
        ulOutSize = sizeof(m_VehSigV5);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV2)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V3_VERINFO)))))
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV2::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        *pOutData = &m_VehSigV5;
        ulOutSize = sizeof(m_VehSigV5);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV4)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO))))
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV4::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV5;
        ulOutSize = sizeof(m_VehSigV5);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV6)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO)))) 
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV6::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV5;
        ulOutSize = sizeof(m_VehSigV5);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV7)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO)))) 
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV7::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        *pOutData = &m_VehSigV5;
        ulOutSize = sizeof(m_VehSigV5);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV8)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO)))) 
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV8::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        *pOutData = &m_VehSigV5;
        ulOutSize = sizeof(m_VehSigV5);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV9)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V9_VERINFO)))) 
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV9::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        *pOutData = &m_VehSigV5;
        ulOutSize = sizeof(m_VehSigV5);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV10)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V10_VERINFO)))) 
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV10::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        *pOutData = &m_VehSigV5;
        ulOutSize = sizeof(m_VehSigV5);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV11)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V11_VERINFO)))) 
      {
        ConvertToVehSigV10(&m_VehSigV10, reinterpret_cast<const VehSigV11::VehSig_t*>(pPPortData));
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV10);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV6);
        *pOutData = &m_VehSigV5;
        ulOutSize = sizeof(m_VehSigV5);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(m_VehSigV6)) && (requestPortVersionInfo.Equals(&VEH_SIG_V6_VERINFO)))
    {
      if ((ulPPortSize == sizeof(m_VehSigV6)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO))))
      {
        // Provide port sizes match and versions are VEH_PAR_V8_VERINFO
        // Forward the data directly:
        *pOutData = pPPortData;
        ulOutSize = ulPPortSize;
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV1)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO))))
      {
        ConvertToVehSigV2(&m_VehSigV2, reinterpret_cast<const VehSigV1::VehSig_t*>(pPPortData));
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV2);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        *pOutData = &m_VehSigV6;
        ulOutSize = sizeof(m_VehSigV6);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV2)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V3_VERINFO)))))
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV2::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        *pOutData = &m_VehSigV6;
        ulOutSize = sizeof(m_VehSigV6);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV4)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO))))
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV4::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        *pOutData = &m_VehSigV6;
        ulOutSize = sizeof(m_VehSigV6);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV5)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO))))
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV5::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV6;
        ulOutSize = sizeof(m_VehSigV6);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV7)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO)))) 
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV7::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV6;
        ulOutSize = sizeof(m_VehSigV6);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV8)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO)))) 
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV8::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        *pOutData = &m_VehSigV6;
        ulOutSize = sizeof(m_VehSigV6);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV9)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V9_VERINFO)))) 
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV9::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        *pOutData = &m_VehSigV6;
        ulOutSize = sizeof(m_VehSigV6);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV10)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V10_VERINFO)))) 
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV10::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);
        *pOutData = &m_VehSigV6;
        ulOutSize = sizeof(m_VehSigV6);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV11)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V11_VERINFO)))) 
      {
        ConvertToVehSigV10(&m_VehSigV10, reinterpret_cast<const VehSigV9::VehSig_t*>(pPPortData));
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV10);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV7);

        *pOutData = &m_VehSigV6;
        ulOutSize = sizeof(m_VehSigV6);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(m_VehSigV7))  && (requestPortVersionInfo.Equals(&VEH_SIG_V7_VERINFO)))  // !!! number 7 is not defined in RTE
    {
      if ((ulPPortSize == sizeof(m_VehSigV7)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V7_VERINFO))))
      {
        // Provide port sizes match and versions are VEH_PAR_V8_VERINFO
        // Forward the data directly:
        *pOutData = pPPortData;
        ulOutSize = ulPPortSize;
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV1)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V1_VERINFO))))
      {
        ConvertToVehSigV2(&m_VehSigV2, reinterpret_cast<const VehSigV1::VehSig_t*>(pPPortData));
        ConvertToVehSigV4(&m_VehSigV4, &m_VehSigV2);
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        *pOutData = &m_VehSigV7;
        ulOutSize = sizeof(m_VehSigV7);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV2)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V2_VERINFO) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V3_VERINFO)))))
      {
        ConvertToVehSigV4(&m_VehSigV4, reinterpret_cast<const VehSigV2::VehSig_t*>(pPPortData));
        ConvertToVehSigV5(&m_VehSigV5, &m_VehSigV4);
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        *pOutData = &m_VehSigV7;
        ulOutSize = sizeof(m_VehSigV7);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV4)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V4_VERINFO))))
      {
        ConvertToVehSigV5(&m_VehSigV5, reinterpret_cast<const VehSigV4::VehSig_t*>(pPPortData));
        ConvertToVehSigV6(&m_VehSigV6, &m_VehSigV5);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        *pOutData = &m_VehSigV7;
        ulOutSize = sizeof(m_VehSigV7);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV5)) &&
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V5_VERINFO))))
      {
        ConvertToVehSigV6(&m_VehSigV6, reinterpret_cast<const VehSigV5::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV6);
        *pOutData = &m_VehSigV7;
        ulOutSize = sizeof(m_VehSigV7);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(m_VehSigV6)) && 
        ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V6_VERINFO))))
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV6::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV7;
        ulOutSize = sizeof(m_VehSigV7);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV8)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V8_VERINFO)))) 
      {
        ConvertToVehSigV7(&m_VehSigV7, reinterpret_cast<const VehSigV8::VehSig_t*>(pPPortData));
        *pOutData = &m_VehSigV7;
        ulOutSize = sizeof(m_VehSigV7);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV9)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V9_VERINFO)))) 
      {
        ConvertToVehSigV8(&m_VehSigV8, reinterpret_cast<const VehSigV9::VehSig_t*>(pPPortData));
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        *pOutData = &m_VehSigV7;
        ulOutSize = sizeof(m_VehSigV7);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV10)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V10_VERINFO)))) 
      {
        ConvertToVehSigV9(&m_VehSigV9, reinterpret_cast<const VehSigV10::VehSig_t*>(pPPortData));
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        *pOutData = &m_VehSigV7;
        ulOutSize = sizeof(m_VehSigV7);
        lRet = SIM_ERR_OK;
      }
      else if  ((ulPPortSize == sizeof(m_VehSigV11)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_SIG_V11_VERINFO)))) 
      {
        ConvertToVehSigV10(&m_VehSigV10, reinterpret_cast<const VehSigV11::VehSig_t*>(pPPortData));
        ConvertToVehSigV9(&m_VehSigV9, &m_VehSigV10);
        ConvertToVehSigV8(&m_VehSigV8, &m_VehSigV9);
        ConvertToVehSigV7(&m_VehSigV7, &m_VehSigV8);
        *pOutData = &m_VehSigV7;
        ulOutSize = sizeof(m_VehSigV7);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else
    {
      lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
    }
  }

  return lRet;
}


/** returns: 
*   SIM_ERR_OK - when this value can be used
*   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
*                                            and the default value from Request Port must be used
*/
long CConvVdyInputDataVehSig::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
  void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet;

  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(m_VehSigV2)) && 
		((requestPortVersionInfo.Equals(&VEH_SIG_V2_VERINFO) || (requestPortVersionInfo.Equals(&VEH_SIG_V3_VERINFO)))))
    {
      InitDefaultVehSigV2(&m_VehSigV2);
      *pDefaultData = &m_VehSigV2;
      ulDefaultSize = sizeof(m_VehSigV2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehSigV1)) && (requestPortVersionInfo.Equals(&VEH_SIG_V1_VERINFO)))
    {
      InitDefaultVehSigV1(&m_VehSigV1);
      *pDefaultData = &m_VehSigV1;
      ulDefaultSize = sizeof(m_VehSigV1);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehSigV4)) && (requestPortVersionInfo.Equals(&VEH_SIG_V4_VERINFO)))
    {
      InitDefaultVehSigV4(&m_VehSigV4);
      *pDefaultData = &m_VehSigV4;
      ulDefaultSize = sizeof(m_VehSigV4);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehSigV7)) && (requestPortVersionInfo.Equals(&VEH_SIG_V7_VERINFO)))
    {
      InitDefaultVehSigV7(&m_VehSigV7);
      *pDefaultData = &m_VehSigV7;
      ulDefaultSize = sizeof(m_VehSigV7);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehSigV8)) && (requestPortVersionInfo.Equals(&VEH_SIG_V8_VERINFO)))
    {
      InitDefaultVehSigV8(&m_VehSigV8);
      *pDefaultData = &m_VehSigV8;
      ulDefaultSize = sizeof(m_VehSigV8);
      lRet = SIM_ERR_OK;
    }
    else
    {
      lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
    }
  }
  else
  {
    lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  }
  return lRet;
}


uint8 CConvVdyInputDataVehSig::ConvertIOState(unsigned int position, unsigned long* pInputstate)
{
  uint8 outputstate;
  uint8 inputstate;

  inputstate = (uint8)VDY_GET_IO_STATE(position, pInputstate);

  if (inputstate == VDY_IO_STATE_VALID)
  {
    outputstate = VehSigV8::VEH_SIG_IO_STATE_VALID;
  }
  else if (inputstate == VDY_IO_STATE_NOTAVAIL)
  {
    outputstate = VehSigV8::VEH_SIG_IO_STATE_NOTAVAIL;
  }
  else if (inputstate == VDY_IO_STATE_INIT)
  {
    outputstate = VehSigV8::VEH_SIG_IO_STATE_INIT;
  }
  else 
  {
    outputstate = VehSigV8::VEH_SIG_IO_STATE_INVALID;
  }

  return outputstate;
}

unsigned long CConvVdyInputDataVehSig::ConvertIOState(unsigned int position, uint8 ui8Inputstate, unsigned long* pOutputstate)
{
  uint8 inputstate;
  unsigned long outputstate = 0;

  if (ui8Inputstate == VehSigV8::VEH_SIG_IO_STATE_VALID)
  {
    inputstate = VDY_IO_STATE_VALID;
  }
  else if (ui8Inputstate == VehSigV8::VEH_SIG_IO_STATE_NOTAVAIL)
  {
    inputstate = VDY_IO_STATE_NOTAVAIL;
  }
  else if (ui8Inputstate == VehSigV8::VEH_SIG_IO_STATE_INIT)
  {
    inputstate = VDY_IO_STATE_INIT;
  }
  else
  {
    inputstate = VDY_IO_STATE_INVALID;
  }

  outputstate = VDY_SET_IO_STATE(position, inputstate, pOutputstate);

  return outputstate;
}

bool CConvVdyInputDataVehSig::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * const pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;

  // in case of reference input port the input port should be supported
  if (ePortType == simREFERENCE_t)
  {
    bResult = true;
  }

  // VehSig_t to VehSig_t conversion
  for (i=0;(i<CConvVdyInputDataVehSig::VEHSIG_INPUT_VERSION_COUNT) && (!bResult);i++)
  {
    if ((ePortType == simOPAQUE_t) && (ulPortSize == VEHSIG_SUPPORTED_SIZE[i]))
    {
      // Check if version information is compatible - with extra care for simulators that
      // do not set the version number at all...
      if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(VEHSIG_VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
      {
        bResult = true;
      }
    }
  }
  for (i =0; (i<CConvVdyInputDataVehSig::VDY_IN_VER_COUNT) && (!bResult);i++)
  {
    bResult |= (ulPortSize == SUPPORTED_SIZE[i]);
  }

  return bResult;
}


// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvVdyInputDataVehSig::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // If sizes and versions match, then just take data
  if ((ePPortType == eRPortType) && (ulPPortSize == ulRPortSize))
  {
    bResult = true;
  }
  else
  {
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo);
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvVdyInputDataVehSig::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // If sizes and versions match, then just take data
  if ((ePPortType == eRPortType) && (ulPPortSize == ulRPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize, &providePortVersionInfo);
  }
  return bResult;

}
// Factory function

IConverter * CreateVehSigConvClass(void)
{
  return new CConvVdyInputDataVehSig();
}
