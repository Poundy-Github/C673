/*! \file **********************************************************************

  COMPANY:                   Continental(AG)

  PROJECT:                   ARS3xx()

  CPU:                       Intel(x86)

  COMPONENT:                 SIMULATION

  MODULNAME:                 sim_conv_vdy_input_data_veh_sig.h

  DESCRIPTION:               Conversion of VehSig

  AUTHOR:                    

  CREATION DATE:             11.04.2012

  VERSION:                   $Revision: 1.1 $

  CHANGES:
  ---*/ /*---
  CHANGE:                    $Log: sim_conv_vdy_input_data_veh_sig.h  $
  CHANGE:                    Revision 1.1 2017/08/10 13:15:41CEST uid34177 
  CHANGE:                    Initial revision
  CHANGE:                    Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/vdy/project.pj
  CHANGE:                    Revision 1.14.1.4 2016/02/05 10:51:29CET Berndt, Thomas01 (berndtt1) 
  CHANGE:                    New Velocity monitoring based on new minimum and maximum velocity signals for ARS4D1 and ARS4D2
  CHANGE:                    Interface V11
  CHANGE:                    Copied from 418300:1
  CHANGE:                    Revision 1.14.1.3 2014/10/30 17:51:31CET Manea, Gabriela (ManeaG) 
  CHANGE:                    Updated with conversions for V10
  CHANGE:                    - Added comments -  ManeaG [Oct 30, 2014 5:51:31 PM CET]
  CHANGE:                    Change Package : 263320:1 http://mks-psad:7002/im/viewissue?selection=263320
  CHANGE:                    Revision 1.14.1.2 2014/06/27 10:18:08CEST Manea, Gabriela (ManeaG) 
  CHANGE:                    Updated : Added conversions for V9
  CHANGE:                    --- Added comments ---  ManeaG [Jun 27, 2014 10:18:08 AM CEST]
  CHANGE:                    Change Package : 212023:2 http://mks-psad:7002/im/viewissue?selection=212023
  CHANGE:                    Revision 1.14.1.1 2014/03/07 15:02:07CET Manea, Gabriela (ManeaG) 
  CHANGE:                    Updated with factory function. This function is exposed via header file (complete implementation hidden in cpp file, making modification of single file necessary when support for new interface version becomes necessary) Note: incompatible change to old versions as respective class) no longer declared by header file.
  CHANGE:                    --- Added comments ---  ManeaG [Mar 7, 2014 3:02:08 PM CET]
  CHANGE:                    Change Package : 212023:1 http://mks-psad:7002/im/viewissue?selection=212023
  CHANGE:                    Revision 1.14 2014/03/06 12:12:33CET Sorge-EXT, Sven (uidg3181) 
  CHANGE:                    Changed char to TCHAR
  CHANGE:                    --- Added comments ---  uidg3181 [Mar 6, 2014 12:12:33 PM CET]
  CHANGE:                    Change Package : 217703:2 http://mks-psad:7002/im/viewissue?selection=217703
  CHANGE:                    Revision 1.13 2014/01/28 15:40:46CET Wolter, Frank (wolterf) 
  CHANGE:                    Added support for VehSig V8
  CHANGE:                    --- Added comments ---  wolterf [Jan 28, 2014 3:40:46 PM CET]
  CHANGE:                    Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGE:                    Revision 1.12 2013/11/08 15:18:09CET Mueller, Reik (muellerr5) 
  CHANGE:                    - updated GetConverterTypeName():
  CHANGE:                        - use the corresponding RTE type name instead of the port name
  CHANGE:                    --- Added comments ---  muellerr5 [Nov 8, 2013 3:18:09 PM CET]
  CHANGE:                    Change Package : 198409:1 http://mks-psad:7002/im/viewissue?selection=198409
  CHANGE:                    Revision 1.11 2013/07/24 14:35:52CEST Wolter, Frank (wolterf) 
  CHANGE:                    added VehSigV7:
  CHANGE:                    - ninth gear
  CHANGE:                    - powerfree gear
  CHANGE:                    - engine running
  CHANGE:                    --- Added comments ---  wolterf [Jul 24, 2013 2:35:53 PM CEST]
  CHANGE:                    Change Package : 189943:1 http://mks-psad:7002/im/viewissue?selection=189943
  CHANGE:                    Revision 1.10 2013/03/08 11:02:04CET Spruck, Jochen (spruckj) 
  CHANGE:                    Update veh par and veh sig adapter, add trail signal, ignition switch, wheel width and front axle to road data
  CHANGE:                    --- Added comments ---  spruckj [Mar 8, 2013 11:02:04 AM CET]
  CHANGE:                    Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGE:                    Revision 1.9 2013/01/16 11:36:35CET Spruck, Jochen (spruckj) 
  CHANGE:                    Update VehSig VehPar and VehDyn adapter modules regarding mfc400 changes
  CHANGE:                    --- Added comments ---  spruckj [Jan 16, 2013 11:36:35 AM CET]
  CHANGE:                    Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGE:                    Revision 1.8 2012/04/24 17:25:28CEST Mogos, Sorin (mogoss) 
  CHANGE:                    * update: added VehSigV4
  CHANGE:                    --- Added comments ---  mogoss [Apr 24, 2012 5:25:28 PM CEST]
  CHANGE:                    Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
  CHANGE:                    Revision 1.7 2012/04/17 11:14:35CEST Mogos, Sorin (mogoss) 
  CHANGE:                    * re-do changes to rev 1.5
  CHANGE:                    --- Added comments ---  mogoss [Apr 17, 2012 11:14:41 AM CEST]
  CHANGE:                    Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
  CHANGE:                    Revision 1.5 2012/04/11 09:56:26CEST Berndt, Thomas01 (berndtt1) 
  CHANGE:                    Added version 3 of BSW_VEH_SIG_INTFVER, which is identical to version 2
  CHANGE:                    --- Added comments ---  berndtt1 [Apr 11, 2012 10:24:58 AM CEST]
  CHANGE:                    Change Package : 105371:4 http://mks-psad:7002/im/viewissue?selection=105371

**************************************************************************** */
#pragma once

#include "sim_converter_base.h"
#include "sim_versioninfo_impl.h"
#include "interfacevehsig.h"
//#include "Interface_Version_Control.h"


/*! External interface states version 7 and older */
typedef ui32_t VDYIoState_t;
#ifndef VDY_IO_STATE_VALID
#define VDY_IO_STATE_VALID             (0U)
#define VDY_IO_STATE_INVALID           (1U)
#define VDY_IO_STATE_NOTAVAIL          (2U)
#define VDY_IO_STATE_INIT              (3U)
#endif
#ifndef VDY_GET_IO_STATE
#define VDY_IO_STATE_BITMASK           (unsigned long)(0x3UL)
#define VDY_GET_IO_STATE(pos_,val_)    ( ((val_)[(pos_)/32UL] >> ((pos_) % 32UL)) & VDY_IO_STATE_BITMASK)
#endif
#ifndef VDY_SET_IO_STATE
#define VDY_SET_IO_STATE(pos_, state_, val_)   ( (val_)[(pos_)/32UL] = (~((VDYIoState_t) (VDY_IO_STATE_BITMASK<<((pos_)%32UL))) & ((val_)[(pos_)/32UL])) | ((VDY_IO_STATE_BITMASK & (state_))<<((pos_)%32UL)))
#endif


class CConvVdyInputDataVehSig :
  public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  /*
  static const char* DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here 
    DEP_COUNT
  };

  static CVersionInfoImpl VEH_SIG_V1_VERINFO;
  static CVersionInfoImpl VEH_SIG_V2_VERINFO;
  static CVersionInfoImpl VEH_SIG_V3_VERINFO;
  static CVersionInfoImpl VEH_SIG_V4_VERINFO;
  static CVersionInfoImpl VEH_SIG_V5_VERINFO;
  static CVersionInfoImpl VEH_SIG_V6_VERINFO;
  static CVersionInfoImpl VEH_SIG_V7_VERINFO;
  static CVersionInfoImpl VEH_SIG_V8_VERINFO;
  static CVersionInfoImpl VEH_SIG_V9_VERINFO;
  static CVersionInfoImpl VEH_SIG_V10_VERINFO;
  static CVersionInfoImpl VEH_SIG_V11_VERINFO;

  VehSigV1::VehSig_t  m_VehSigV1;
  VehSigV2::VehSig_t  m_VehSigV2;
  VehSigV4::VehSig_t  m_VehSigV4;
  VehSigV5::VehSig_t  m_VehSigV5;
  VehSigV6::VehSig_t  m_VehSigV6;
  VehSigV7::VehSig_t  m_VehSigV7;
  VehSigV8::VehSig_t  m_VehSigV8;
  VehSigV9::VehSig_t  m_VehSigV9;
  VehSigV10::VehSig_t  m_VehSigV10;
  VehSigV11::VehSig_t  m_VehSigV11;

  void InitDefaultVehSigV1(VehSigV1::VehSig_t * const pDest);
  void InitDefaultVehSigV2(VehSigV2::VehSig_t * const pDest);
  void InitDefaultVehSigV4(VehSigV4::VehSig_t * const pDest);
  void InitDefaultVehSigV5(VehSigV5::VehSig_t * const pDest);
  void InitDefaultVehSigV6(VehSigV6::VehSig_t * const pDest);
  void InitDefaultVehSigV7(VehSigV7::VehSig_t * const pDest);
  void InitDefaultVehSigV8(VehSigV8::VehSig_t * const pDest);
  void InitDefaultVehSigV9(VehSigV9::VehSig_t * const pDest);
  void InitDefaultVehSigV10(VehSigV10::VehSig_t * const pDest);
  void InitDefaultVehSigV11(VehSigV11::VehSig_t * const pDest);

  void ConvertToVehSigV1(VehSigV1::VehSig_t * const pDest, const VehSigV2::VehSig_t * const pInput);
  void ConvertToVehSigV1(VehSigV1::VehSig_t * const pDest, const VehSigV4::VehSig_t * const pInput);
  void ConvertToVehSigV2(VehSigV2::VehSig_t * const pDest, const VehSigV1::VehSig_t * const pInput);
  void ConvertToVehSigV2(VehSigV2::VehSig_t * const pDest, const VehSigV4::VehSig_t * const pInput);
  //the VehSigV3 is covered by VehSigV2 because are identical 
  void ConvertToVehSigV4(VehSigV4::VehSig_t * const pDest, const VehSigV1::VehSig_t * const pInput);
  void ConvertToVehSigV4(VehSigV4::VehSig_t * const pDest, const VehSigV2::VehSig_t * const pInput);
  void ConvertToVehSigV4(VehSigV4::VehSig_t * const pDest, const VehSigV5::VehSig_t * const pInput);
  void ConvertToVehSigV5(VehSigV5::VehSig_t * const pDest, const VehSigV4::VehSig_t * const pInput);
  void ConvertToVehSigV5(VehSigV5::VehSig_t * const pDest, const VehSigV6::VehSig_t * const pInput);
  void ConvertToVehSigV6(VehSigV6::VehSig_t * const pDest, const VehSigV5::VehSig_t * const pInput);
  void ConvertToVehSigV6(VehSigV6::VehSig_t * const pDest, const VehSigV7::VehSig_t * const pInput);
  void ConvertToVehSigV7(VehSigV7::VehSig_t * const pDest, const VehSigV2::VehSig_t * const pInput);
  void ConvertToVehSigV7(VehSigV7::VehSig_t * const pDest, const VehSigV6::VehSig_t * const pInput);
  void ConvertToVehSigV7(VehSigV7::VehSig_t * const pDest, const VehSigV8::VehSig_t * const pInput);
  void ConvertToVehSigV8(VehSigV8::VehSig_t * const pDest, const VehSigV7::VehSig_t * const pInput);
  void ConvertToVehSigV8(VehSigV8::VehSig_t * const pDest, const VehSigV9::VehSig_t * const pInput);
  void ConvertToVehSigV9(VehSigV9::VehSig_t * const pDest, const VehSigV8::VehSig_t * const pInput);
  void ConvertToVehSigV9(VehSigV9::VehSig_t * const pDest, const VehSigV10::VehSig_t * const pInput);
  void ConvertToVehSigV10(VehSigV10::VehSig_t * const pDest, const VehSigV9::VehSig_t * const pInput);
  void ConvertToVehSigV10(VehSigV10::VehSig_t * const pDest, const VehSigV11::VehSig_t * const pInput);
  void ConvertToVehSigV11(VehSigV11::VehSig_t * const pDest, const VehSigV10::VehSig_t * const pInput);
  
  uint8 ConvertIOState(unsigned int position, unsigned long* inputstate);
  unsigned long ConvertIOState(unsigned int position, uint8 ui8Inputstate, unsigned long* pOutputstate);

  bool DecodeVDYInput(VehSigV2::VehSig_t * const pVehSig, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData);
  bool PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * const pPortVersionInfo = NULL) const;

public:

  static const TCHAR* GetConverterTypeName()
  {
    return _T("VehSig_t");
  }

  CConvVdyInputDataVehSig(void);
  virtual ~CConvVdyInputDataVehSig(void);

  const TCHAR* GetTypeName()
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
  enum eVersions
  {
    VDY_IN_V1 = 0,
    VDY_IN_V2,
    VDY_IN_V3,
    VDY_IN_V4,
    VDY_IN_VER_COUNT
  };
  static unsigned long SUPPORTED_SIZE[VDY_IN_VER_COUNT];

  enum eVehSigInputVersions
  {
    VEHSIG_INPUT_V1         = 0,
    VEHSIG_INPUT_V2 ,
    VEHSIG_INPUT_V3 ,
    VEHSIG_INPUT_V4 ,
    VEHSIG_INPUT_V5 ,
    VEHSIG_INPUT_V6 ,
    VEHSIG_INPUT_V7 ,
    VEHSIG_INPUT_V8 ,
    VEHSIG_INPUT_V9 ,
    VEHSIG_INPUT_V10 ,
    VEHSIG_INPUT_V11 ,
    VEHSIG_INPUT_VERSION_COUNT
  };

  // AdaptationList_t ReportedAdaptationErrors;

  static unsigned long VEHSIG_SUPPORTED_SIZE[VEHSIG_INPUT_VERSION_COUNT];

  static CVersionInfoImpl * const VEHSIG_VERSION_NUMBERS[VEHSIG_INPUT_VERSION_COUNT];

  static const uint32 DefaultStateWord;
};

extern IConverter * CreateVehSigConvClass(void);
