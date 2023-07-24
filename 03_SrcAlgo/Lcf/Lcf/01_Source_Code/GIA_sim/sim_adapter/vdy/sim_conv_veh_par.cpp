/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_vdy

  MODULNAME:            sim_conv_veh_par.cpp

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        23.03.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_veh_par.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:56CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/vdy/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:44CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/vdy/project.pj
  CHANGES:              Revision 1.31.1.13 2016/11/25 09:33:05CET Cretu, Teodora (CretuT) 
  CHANGES:              New version is added: V19 which is equal to V9 (as structure and size)
  CHANGES:              Conversion from V19 to V9 is needed because some parameters from PP are out of range.
  CHANGES:              Revision 1.31.1.12 2016/11/24 13:08:33CET Cretu, Teodora (CretuT) 
  CHANGES:              Adapted Sim parameter for the new SteeringWheelNumber parameter added in V9
  CHANGES:              Revision 1.31.1.11 2016/11/01 09:45:46CET Ketesdi, Csaba (KatesdiC) 
  CHANGES:              Added missing supported size for V9
  CHANGES:              Revision 1.31.1.10 2016/10/27 10:43:23CEST Cretu, Teodora (CretuT) 
  CHANGES:              Add new version (V9) equal to V8
  CHANGES:              Revision 1.31.1.9 2014/02/25 16:41:21CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              - Added conversion from V8 to V7
  CHANGES:              - Added comments -  berndtt1 [Mar 14, 2014 10:04:16 AM CET]
  CHANGES:              Change Package : 221167:1 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.31.1.8 2014/02/24 14:24:57CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              * changed lower limit of DrvAxle to 0
  CHANGES:              - removed copying of old states in ConvertToVehParV8()
  CHANGES:              --- Added comments ---  berndtt1 [Feb 24, 2014 2:25:51 PM CET]
  CHANGES:              Change Package : 221167:1 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.31.1.7 2014/02/03 11:11:56CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Corrected conversion of I/O states
  CHANGES:              --- Added comments ---  berndtt1 [Feb 3, 2014 11:17:54 AM CET]
  CHANGES:              Change Package : 208935:13 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:              Revision 1.31.1.6 2014/01/30 14:09:25CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added support for VehPar V8
  CHANGES:              --- Added comments ---  berndtt1 [Jan 30, 2014 2:27:35 PM CET]
  CHANGES:              Change Package : 208935:13 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:              Revision 1.31.1.5 2014/01/29 10:11:33CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:              Corrected merge
  CHANGES:              --- Added comments ---  uidt0551 [Jan 29, 2014 10:11:33 AM CET]
  CHANGES:              Change Package : 199714:3 http://mks-psad:7002/im/viewissue?selection=199714  CHANGES:              Revision 1.31.1.4 2014/01/29 10:05:46CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:              Merge from head
  CHANGES:              --- Added comments ---  uidt0551 [Jan 29, 2014 10:05:47 AM CET]
  CHANGES:              Change Package : 199714:3 http://mks-psad:7002/im/viewissue?selection=199714
  CHANGES:              Revision 1.35 2014/01/28 15:46:16CET Wolter, Frank (wolterf) 
  CHANGES:              Added support for VehPar V8
  CHANGES:              --- Added comments ---  wolterf [Jan 28, 2014 3:46:16 PM CET]
  CHANGES:              Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGES:              Revision 1.34 2013/12/17 13:27:53CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:              Correct handling of PPort of type reference
  CHANGES:              --- Added comments ---  uidt0551 [Dec 17, 2013 1:27:53 PM CET]
  CHANGES:              Change Package : 203467:1 http://mks-psad:7002/im/viewissue?selection=203467
  CHANGES:              Revision 1.34 2013/12/17 13:27:53CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:              Correct handling of PPort of type reference
  CHANGES:              --- Added comments ---  uidt0551 [Dec 17, 2013 1:27:53 PM CET]
  CHANGES:              Change Package : 203467:1 http://mks-psad:7002/im/viewissue?selection=203467
  CHANGES:              Revision 1.31.1.3 2013/12/12 15:41:28CET Schutsch-EXT, Julian (uidg2542) 
  CHANGES:              tchar issue
  CHANGES:              --- Added comments ---  uidg2542 [Dec 12, 2013 3:41:29 PM CET]
  CHANGES:              Change Package : 204135:1 http://mks-psad:7002/im/viewissue?selection=204135
  CHANGES:              Revision 1.31.1.2 2013/11/18 10:40:28CET Heidemann-EXT, Siegfried (uidg3348) 
  CHANGES:              Merge-in fixes changes from 1.33
  CHANGES:              --- Added comments ---  uidg3348 [Nov 18, 2013 10:40:28 AM CET]
  CHANGES:              Change Package : 206729:1 http://mks-psad:7002/im/viewissue?selection=206729
  CHANGES:              Revision 1.33 2013/11/18 10:27:38CET Heidemann-EXT, Siegfried (uidg3348) 
  CHANGES:              Merge-in fixes from temporary branch: fix steering ratio indexing copy-paste error, use SigHeader when available (do not always
  CHANGES:              assume OK with invalid content), fix version headers where appropriate
  CHANGES:              --- Added comments ---  uidg3348 [Nov 18, 2013 10:27:39 AM CET]
  CHANGES:              Change Package : 206729:1 http://mks-psad:7002/im/viewissue?selection=206729
  CHANGES:              Revision 1.32 2013/11/06 15:36:18CET Westhofen, Daniel (uidt2642) 
  CHANGES:              - Added VehParV6A to support SRLCAM4xx videos without VehicleLength in VehParAdd struct
  CHANGES:              --- Added comments ---  uidt2642 [Nov 6, 2013 3:36:19 PM CET]
  CHANGES:              Change Package : 198737:2 http://mks-psad:7002/im/viewissue?selection=198737
  CHANGES:              Revision 1.31.1.1 2013/08/07 10:39:07CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Simplified VehDyn/VehPar adapter version, where only factory function is exposed via header file (complete implementation
  CHANGES:              hidden in cpp file, making modification of single file necessary when support for new interface version becomes necessary)
  CHANGES:              Note: incompatible change to old versions as respective classes (CConvVehDyn, CConvVehPar) no longer declared by header
  CHANGES:              file. This is the price to pay for information hiding (if the class is exposed via header, then the header always needs to be modified
  CHANGES:              for new conversions)
  CHANGES:              --- Added comments ---  ungvaryg [Aug 7, 2013 10:39:07 AM CEST]
  CHANGES:              Change Package : 190143:3 http://mks-psad:7002/im/viewissue?selection=190143
  CHANGES:              Revision 1.31 2013/07/25 09:44:15CEST Mueller, Reik (muellerr5) 
  CHANGES:              - updated version numbers and supported size list for VehParV7
  CHANGES:              - updated ConvertToVehParV7
  CHANGES:              - fixed conversion handling of VehParV7 in ConvertData method
  CHANGES:              --- Added comments ---  muellerr5 [Jul 25, 2013 9:44:16 AM CEST]
  CHANGES:              Change Package : 184575:2 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGES:              Revision 1.30 2013/07/24 14:42:45CEST Wolter, Frank (wolterf) 
  CHANGES:              added VehParV7:
  CHANGES:              - PassableHeight
  CHANGES:              - DistCameraToHoodX
  CHANGES:              - DistCameraToHoodY
  CHANGES:              added VehicleLength to VehParV6
  CHANGES:              --- Added comments ---  wolterf [Jul 24, 2013 2:42:45 PM CEST]
  CHANGES:              Change Package : 190129:2 http://mks-psad:7002/im/viewissue?selection=190129
  CHANGES:              Revision 1.29 2013/06/27 12:58:22CEST Zechner, Stefan (uidt9253) 
  CHANGES:              - check input pointer pPPortData for NULL
  CHANGES:              --- Added comments ---  uidt9253 [Jun 27, 2013 12:58:22 PM CEST]
  CHANGES:              Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.28 2013/03/15 16:59:34CET Kubera, David (kuberad) 
  CHANGES:              fix
  CHANGES:              --- Added comments ---  kuberad [Mar 15, 2013 4:59:35 PM CET]
  CHANGES:              Change Package : 170509:6 http://mks-psad:7002/im/viewissue?selection=170509
  CHANGES:              Revision 1.27 2013/03/08 11:01:54CET Spruck, Jochen (spruckj) 
  CHANGES:              Update veh par and veh sig adapter, add trail signal, ignition switch, wheel width and front axle to road data
  CHANGES:              --- Added comments ---  spruckj [Mar 8, 2013 11:01:59 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.26 2013/02/06 12:59:42CET Spruck, Jochen (spruckj) 
  CHANGES:              Add vdy offsets adapter to semo adapter, and use const vars instead of defines in interface namespaces
  CHANGES:              --- Added comments ---  spruckj [Feb 6, 2013 12:59:42 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.25 2013/01/23 16:02:17CET Spruck, Jochen (spruckj) 
  CHANGES:              Update VehPar, if size fits but input version number is 0 convert the struct
  CHANGES:              --- Added comments ---  spruckj [Jan 23, 2013 4:02:19 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.24 2013/01/22 11:01:08CET Bachmann, Alexander (uidt5584) 
  CHANGES:              apadted veh par and veh dyn to new structure
  CHANGES:              --- Added comments ---  uidt5584 [Jan 22, 2013 11:01:09 AM CET]
  CHANGES:              Change Package : 162889:21 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.23 2013/01/16 13:06:07CET Spruck, Jochen (spruckj) 
  CHANGES:              Rename namespaces, because of conflicts
  CHANGES:              --- Added comments ---  spruckj [Jan 16, 2013 1:06:07 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.22 2013/01/16 11:36:33CET Spruck, Jochen (spruckj) 
  CHANGES:              Update VehSig VehPar and VehDyn adapter modules regarding mfc400 changes
  CHANGES:              --- Added comments ---  spruckj [Jan 16, 2013 11:36:34 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.21 2011/10/20 16:20:24CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Conversions for new Version of VehPar (Version 4, introduced by Joachim Tandler) which is actually identical to Version 3.
  CHANGES:              --- Added comments ---  berndtt1 [Oct 20, 2011 4:35:51 PM CEST]
  CHANGES:              Change Package : 77819:9 http://mks-psad:7002/im/viewissue?selection=77819
  CHANGES:              Revision 1.20 2011/07/14 13:01:56CEST Ovidiu Raicu (RaicuO) 
  CHANGES:              Fix for wrong Steering ratio sign.
  CHANGES:              --- Added comments ---  RaicuO [Jul 14, 2011 1:01:57 PM CEST]
  CHANGES:              Change Package : 71223:1 http://mks-psad:7002/im/viewissue?selection=71223
  CHANGES:              Revision 1.19 2011/07/05 14:52:58CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Fix compilation issues of ambigous template instantiation when using Orientation_t type (explicitly specify template type)
  CHANGES:              --- Added comments ---  ungvaryg [Jul 5, 2011 2:52:58 PM CEST]
  CHANGES:              Change Package : 71161:1 http://mks-psad:7002/im/viewissue?selection=71161
  CHANGES:              Revision 1.18 2011/06/30 10:19:34CEST Sachs Martin (sachsm) (sachsm) 
  CHANGES:              fix RSPInputVdata for measurements of April 2009, due to error in pdo
  CHANGES:              --- Added comments ---  sachsm [Jun 30, 2011 10:19:34 AM CEST]
  CHANGES:              Change Package : 71262:1 http://mks-psad:7002/im/viewissue?selection=71262
  CHANGES:              Revision 1.17 2011/05/02 11:48:45CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:              Do the get version via the dependency only if the interface version (first 4 bytes of interface) is zero (not set)
  CHANGES:              --- Added comments ---  spruckj [May 2, 2011 11:48:46 AM CEST]
  CHANGES:              Change Package : 65146:2 http://mks-psad:7002/im/viewissue?selection=65146
  CHANGES:              Revision 1.16 2011/04/14 10:49:04CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Add include of stdafx.h : the macro CONV_I32VERSION_TO_TUPPLE(x) has been moved there (since used by multiple
  CHANGES:              adapter classes). Note: to use this new revision you have to make sure that the given macro is directly or indirectly (through
  CHANGES:              sub-includes) available by including 'stdafx.h'.
  CHANGES:              --- Added comments ---  ungvaryg [Apr 14, 2011 10:49:04 AM CEST]
  CHANGES:              Change Package : 63692:1 http://mks-psad:7002/im/viewissue?selection=63692
  CHANGES:              Revision 1.15 2011/03/22 13:24:35CET Eisenacher Michael (eisenacherm) (eisenacherm) 
  CHANGES:              added ALN dependency information
  CHANGES:              --- Added comments ---  eisenacherm [Mar 22, 2011 1:24:36 PM CET]
  CHANGES:              Change Package : 58749:4 http://mks-psad:7002/im/viewissue?selection=58749
  CHANGES:              Revision 1.14 2011/03/03 08:38:52CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:              Fix null pointer exeption for all component versions
  CHANGES:              --- Added comments ---  spruckj [Mar 3, 2011 8:38:52 AM CET]
  CHANGES:              Change Package : 57478:1 http://mks-psad:7002/im/viewissue?selection=57478
  CHANGES:              Revision 1.13 2011/03/02 16:45:07CET Thomas Diepolder (diepoldert) 
  CHANGES:              Fix  null pointer exception in FCT dep version
  CHANGES:              --- Added comments ---  diepoldert [Mar 2, 2011 4:45:07 PM CET]
  CHANGES:              Change Package : 59660:2 http://mks-psad:7002/im/viewissue?selection=59660
  CHANGES:              Revision 1.12 2011/02/28 14:29:46CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Add FCT Version dependency information 01.17.00 and newer using version 0x2 of VehPar, 01.19.00 and newer using version 0x3 of VehPar
  CHANGES:              --- Added comments ---  ungvaryg [Feb 28, 2011 2:29:47 PM CET]
  CHANGES:              Change Package : 59406:1 http://mks-psad:7002/im/viewissue?selection=59406
  CHANGES:              Revision 1.11 2011/02/28 13:02:04CET Jochen Spruck (spruckj) 
  CHANGES:              Rename GetDevVersion to GetDepVersion
  CHANGES:              --- Added comments ---  spruckj [Feb 28, 2011 1:02:04 PM CET]
  CHANGES:              Change Package : 57478:1 http://mks-psad:7002/im/viewissue?selection=57478
  CHANGES:              Revision 1.10 2011/02/28 11:24:36CET Jochen Spruck (spruckj) 
  CHANGES:              - Update veh par adapter to VehPar interface version 3
  CHANGES:              - Add dependance handling for old recordings the component version could be used to select the right imput version of VehPar
  CHANGES:               -> the dep must be set in the sim plg e.g   SetRPortDependency("VehPar", "EMVersion",  simUI32_t, sizeof(em_version), NULL, "EMVersion", &em_version);
  CHANGES:              --- Added comments ---  spruckj [Feb 28, 2011 11:24:37 AM CET]
  CHANGES:              Change Package : 57478:1 http://mks-psad:7002/im/viewissue?selection=57478
  CHANGES:              Revision 1.9 2010/11/29 17:33:19CET Jochen Spruck (spruckj) 
  CHANGES:              Use general VehPar adater in the rsp adater, merge the RSPInputVDATA to the general VehPar adapter
  CHANGES:              --- Added comments ---  spruckj [Nov 29, 2010 5:33:19 PM CET]
  CHANGES:              Change Package : 51886:1 http://mks-psad:7002/im/viewissue?selection=51886
  CHANGES:              Revision 1.8 2010/11/24 09:47:43CET Jochen Spruck (spruckj) 
  CHANGES:              Simulation adapter
  CHANGES:              veh dyn, veh par, veh sig and vdy nvm data adapter bug fix for ARS300 data
  CHANGES:              --- Added comments ---  spruckj [Nov 24, 2010 9:47:44 AM CET]
  CHANGES:              Change Package : 51886:1 http://mks-psad:7002/im/viewissue?selection=51886
  CHANGES:              Revision 1.7 2010/11/23 10:50:29CET Jochen Spruck (spruckj) 
  CHANGES:              Update the vdy adapte
  CHANGES:              - use the general vehpar adapter, add the old vdy input adaption to this general adapter
  CHANGES:              - extend the vehsig adapter
  CHANGES:              Revision 1.6 2010/11/19 15:34:28CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Add signal state evaluation for TPW input signals
  CHANGES:              --- Added comments ---  ungvaryg [Nov 19, 2010 3:34:28 PM CET]
  CHANGES:              Change Package : 54752:1 http://mks-psad:7002/im/viewissue?selection=54752
  CHANGES:              Revision 1.5 2010/11/18 19:15:42CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Rewrite adapters for forward/backward compatibility
  CHANGES:              Clean up several unclean/problematic code parts (better transparancy of what adapter is doing, which
  CHANGES:              buffers it's using)
  CHANGES:              Remove overcomplicated CDataBuffer use (not needed anyway, hard to debug etc.)
  CHANGES:              --- Added comments ---  ungvaryg [Nov 18, 2010 7:15:42 PM CET]
  CHANGES:              Change Package : 54725:1 http://mks-psad:7002/im/viewissue?selection=54725
  CHANGES:              Revision 1.4 2010/07/22 13:12:14CEST Jochen Spruck (spruckj) 
  CHANGES:              Update veh dyn adapter, now adapat also the VehDyn stucts to VehDyn not only TPWInput
  CHANGES:              Update veh par adapter, now  adapt also the VehPyr sturcts to VehPar ont only form TPWInput
  CHANGES:              --- Added comments ---  spruckj [Jul 22, 2010 1:12:15 PM CEST]
  CHANGES:              Change Package : 46866:1 http://mks-psad:7002/im/viewissue?selection=46866
  CHANGES:              Revision 1.3 2010/04/21 16:20:26CEST oraicu 
  CHANGES:              Added ARS35x specific structures.
  CHANGES:              --- Added comments ---  oraicu [2010/04/21 14:20:26Z]
  CHANGES:              Change Package : 39644:2 http://LISS014:6001/im/viewissue?selection=39644
  CHANGES:              Revision 1.2 2010/04/20 14:58:50CEST ffoelster 
  CHANGES:              BugFix: Due to an error in the CDL compiler the size of TPWinput V10 might be given as 253 instead of 256 in CDL
  CHANGES:              --- Added comments ---  ffoelster [2010/04/20 12:58:51Z]
  CHANGES:              Change Package : 41450:1 http://LISS014:6001/im/viewissue?selection=41450
  CHANGES:              Revision 1.1 2010/04/07 10:08:25CEST Ovidiu Raicu (oraicu) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel/04_Engineering/03_Workspace/algo/em_sim/em_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_veh_par.h"
#include "sim_versioninfo_impl.h"
#include "interfacevehpar.h"

class CConvVehPar :
  public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  static const TCHAR* DEP_NAMES[];

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    VDY_VERSION,
    RSP_VERSION,
    ALN_VERSION,
    EM_VERSION,
    FCT_VERSION,
    DEP_COUNT
  };

  static CVersionInfoImpl VEH_PAR_V0_VERINFO;
  static CVersionInfoImpl VEH_PAR_V1_VERINFO;
  static CVersionInfoImpl VEH_PAR_V2_VERINFO;
  static CVersionInfoImpl VEH_PAR_V3_VERINFO;
  static CVersionInfoImpl VEH_PAR_V4_VERINFO;
  static CVersionInfoImpl VEH_PAR_V5_VERINFO;
  static CVersionInfoImpl VEH_PAR_V6_VERINFO;
  static CVersionInfoImpl VEH_PAR_V7_VERINFO;
  static CVersionInfoImpl VEH_PAR_V8_VERINFO;
  static CVersionInfoImpl VEH_PAR_V9_VERINFO;
  static CVersionInfoImpl VEH_PAR_V19_VERINFO;

  VehParV0::VehPar_t  m_VehParV0;
  VehParV1::VehPar_t  m_VehParV1;
  VehParV2::VehPar_t  m_VehParV2;
  VehParV3::VehPar_t  m_VehParV3;                          // This is also used for Version V4!
  VehParV5::VehPar_t  m_VehParV5;
  VehParV6::VehPar_t  m_VehParV6;
  VehParV6A::VehPar_t m_VehParV6A;
  VehParV7::VehPar_t  m_VehParV7;
  VehParV8::VehPar_t  m_VehParV8;
  VehParV9::VehPar_t  m_VehParV9;                         // V19 equal to V9

  void InitDefaultVehParV0(VehParV0::VehPar_t * const pDest);
  void InitDefaultVehParV1(VehParV1::VehPar_t * const pDest);
  void InitDefaultVehParV2(VehParV2::VehPar_t * const pDest);
  void InitDefaultVehParV3(VehParV3::VehPar_t * const pDest);
  void InitDefaultVehParV5(VehParV5::VehPar_t * const pDest);
  void InitDefaultVehParV6(VehParV6::VehPar_t * const pDest);
  void InitDefaultVehParV7(VehParV7::VehPar_t * const pDest);
  void InitDefaultVehParV8(VehParV8::VehPar_t * const pDest);
  void InitDefaultVehParV9(VehParV9::VehPar_t * const pDest);

  void ConvertToVehParV0(VehParV0::VehPar_t * const pDest, const VehParV1::VehPar_t * const pInput);
  void ConvertToVehParV0(VehParV0::VehPar_t * const pDest, const VehParV2::VehPar_t * const pInput);
  void ConvertToVehParV0(VehParV0::VehPar_t * const pDest, const VehParV3::VehPar_t * const pInput);

  void ConvertToVehParV1(VehParV1::VehPar_t * const pDest, const VehParV0::VehPar_t * const pInput);
  void ConvertToVehParV1(VehParV1::VehPar_t * const pDest, const VehParV2::VehPar_t * const pInput);
  void ConvertToVehParV1(VehParV1::VehPar_t * const pDest, const VehParV3::VehPar_t * const pInput);

  void ConvertToVehParV2(VehParV2::VehPar_t * const pDest, const VehParV0::VehPar_t * const pInput);
  void ConvertToVehParV2(VehParV2::VehPar_t * const pDest, const VehParV1::VehPar_t * const pInput);
  void ConvertToVehParV2(VehParV2::VehPar_t * const pDest, const VehParV3::VehPar_t * const pInput);

  void ConvertToVehParV3(VehParV3::VehPar_t * const pDest, const VehParV0::VehPar_t * const pInput);
  void ConvertToVehParV3(VehParV3::VehPar_t * const pDest, const VehParV1::VehPar_t * const pInput);
  void ConvertToVehParV3(VehParV3::VehPar_t * const pDest, const VehParV2::VehPar_t * const pInput);
  void ConvertToVehParV3(VehParV3::VehPar_t * const pDest, const VehParV5::VehPar_t * const pInput);

  void ConvertToVehParV5(VehParV5::VehPar_t * const pDest, const VehParV3::VehPar_t * const pInput);
  void ConvertToVehParV5(VehParV5::VehPar_t * const pDest, const VehParV6::VehPar_t * const pInput);

  void ConvertToVehParV6(VehParV6::VehPar_t * const pDest, const VehParV5::VehPar_t * const pInput);
  void ConvertToVehParV6(VehParV6::VehPar_t * const pDest, const VehParV3::VehPar_t * const pInput);

  void ConvertToVehParV7(VehParV7::VehPar_t * const pDest, const VehParV6::VehPar_t * const pInput);
  void ConvertToVehParV7(VehParV7::VehPar_t * const pDest, const VehParV6A::VehPar_t * const pInput);
  void ConvertToVehParV7(VehParV7::VehPar_t * const pDest, const VehParV8::VehPar_t * const pInput);

  void ConvertToVehParV8(VehParV8::VehPar_t * const pDest, const VehParV7::VehPar_t * const pInput);
  void ConvertToVehParV8(VehParV8::VehPar_t * const pDest, const VehParV9::VehPar_t * const pInput);

  void ConvertToVehParV9(VehParV9::VehPar_t * const pDest, const VehParV8::VehPar_t * const pInput);

  //ConvertToVehParV9(VehParV9::VehPar_t * const pDest, const VehParV19::VehPar_t * const pInput) (but V19 equals to V9)
  void ConvertToVehParV9(VehParV9::VehPar_t * const pDest, const VehParV9::VehPar_t * const pInput);

  uint8 ConvertIOState(unsigned int position, unsigned long* inputstate);

  bool DecodeTPWInput(VehParV3::VehPar_t * const pVehPar, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData);
  bool DecodeRSPInputVDATA(VehParV3::VehPar_t * const pVehPar, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData);
  bool DecodeVDYInput(VehParV3::VehPar_t * const pVehPar, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData);
  bool PortSupported(SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo * const pVersionInfo = NULL) const;

public:

  static const TCHAR* GetConverterTypeName()
  {
    return _T("VehPar");
  }

  CConvVehPar(void);
  virtual ~CConvVehPar(void);

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
  uint32 GetDepVersion(void);

  static CVersionInfoImpl BASE_VERSION;

  enum eTPWInputVersions
  {
    TPW_INPUT_V6          = 0,
    TPW_INPUT_V7_8        = 1,
    TPW_INPUT_V9          = 2,
    TPW_INPUT_V10         = 3,
    TPW_INPUT_V10_253byte = 4, // TPWInputVersion V10 with erroneous size in CDL 253bytes instead of 256bytes due to wrong byte alignment
    TPW_INPUT_V11         = 5,
    TPW_INPUT_V6_350      = 6,
    TPW_INPUT_V7_350      = 7,
    TPW_INPUT_VERSION_COUNT
  };
  static unsigned long SUPPORTED_SIZE[TPW_INPUT_VERSION_COUNT];

  enum RSP_INPUT_VDATA
  {
    RSP_INPUT_VDATA_IV2 = 0,
    RSP_INPUT_VDATA_IV3 = 1,
    RSP_INPUT_VDATA_IV4 = 2,
    RSP_INPUT_VDATA_IV5 = 3,
    RSP_INPUT_VDATA_IV6 = 4,
    RSP_INPUT_VDATA_IV7 = 5,
    RSP_INPUT_VDATA_IV7_2 = 6,
    RSP_INPUT_VDATA_IV8 = 7,
    RSP_INPUT_VDATA_IVL = 8,
    RSP_INPUT_VDATA_VER_COUNT = 9
  };
  static unsigned long SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_VER_COUNT];

  enum eVersions
  {
    VDY_IN_V1 = 0,
    VDY_IN_V2,
    VDY_IN_V3,
    VDY_IN_V4,
    VDY_IN_VER_COUNT
  };
  static unsigned long SUPPORTED_SIZE_VDY_INPUT[VDY_IN_VER_COUNT];

  enum eVehParInputVersions
  {
    VEHPAR_INPUT_V0         = 0,
    VEHPAR_INPUT_V1         = 1,
    VEHPAR_INPUT_V2         = 2,
    VEHPAR_INPUT_V3         = 3,
    VEHPAR_INPUT_V4         = 4,
    VEHPAR_INPUT_V5         = 5,
    VEHPAR_INPUT_V6         = 6,
    VEHPAR_INPUT_V7         = 7,
    VEHPAR_INPUT_V8         = 8,
    VEHPAR_INPUT_V9         = 9,
    VEHPAR_INPUT_V19         = 19,
    VEHPAR_INPUT_VERSION_COUNT
  };
  static unsigned long VEHPAR_SUPPORTED_SIZE[VEHPAR_INPUT_VERSION_COUNT];

  static CVersionInfoImpl * const VEHPAR_VERSION_NUMBERS[VEHPAR_INPUT_VERSION_COUNT];

  static const uint32 DefaultStateWord;
};

/*! External interface states version 7 and older */
#ifndef VDY_IO_STATE_VALID
#define VDY_IO_STATE_VALID             (0U)
#define VDY_IO_STATE_INVALID           (1U)
#define VDY_IO_STATE_NOTAVAIL          (2U)
#define VDY_IO_STATE_INIT              (3U)
#define VDY_IO_STATE_BITMASK           (unsigned long)(0x3UL)
#endif
#ifndef VDY_GET_IO_STATE
#define VDY_GET_IO_STATE(pos_,val_)    ( ((val_)[(pos_)/32UL] >> ((pos_) % 32UL)) & VDY_IO_STATE_BITMASK)
#endif


CVersionInfoImpl CConvVehPar::BASE_VERSION(0, 0, 0);

CVersionInfoImpl CConvVehPar::VEH_PAR_V0_VERINFO(0, 0, 0);
CVersionInfoImpl CConvVehPar::VEH_PAR_V1_VERINFO(0, 0, 1);
CVersionInfoImpl CConvVehPar::VEH_PAR_V2_VERINFO(0, 0, 2);
CVersionInfoImpl CConvVehPar::VEH_PAR_V3_VERINFO(0, 0, 3);
CVersionInfoImpl CConvVehPar::VEH_PAR_V4_VERINFO(0, 0, 4);
CVersionInfoImpl CConvVehPar::VEH_PAR_V5_VERINFO(0, 0, 5);
CVersionInfoImpl CConvVehPar::VEH_PAR_V6_VERINFO(0, 0, 6);
CVersionInfoImpl CConvVehPar::VEH_PAR_V7_VERINFO(0, 0, 7);
CVersionInfoImpl CConvVehPar::VEH_PAR_V8_VERINFO(0, 0, 8);
CVersionInfoImpl CConvVehPar::VEH_PAR_V9_VERINFO(0, 0, 9);
CVersionInfoImpl CConvVehPar::VEH_PAR_V19_VERINFO(0, 0, 19);

unsigned long CConvVehPar::SUPPORTED_SIZE[CConvVehPar::TPW_INPUT_VERSION_COUNT]=
{
  sizeof(TPW_PAR_300::TPWInput_V6_t),
  sizeof(TPW_PAR_300::TPWInput_8_7_t),
  sizeof(TPW_PAR_300::TPWInput_V9_t),
  sizeof(TPW_PAR_300::TPWInput_V10_t),
  sizeof(TPW_PAR_300::TPWInput_V10_t)-3,   // Due to an error in the CDL compiler the size of V10 might be set to 253
  sizeof(TPW_PAR_300::TPWInput_V11_t),
  sizeof(TPW_PAR_300::TPWInput_V6_ARS350_t),
  sizeof(TPW_PAR_300::TPWInput_V7_ARS350_t)
};

unsigned long CConvVehPar::SUPPORTED_SIZE_RSP_INPUT_VDATA[CConvVehPar::RSP_INPUT_VDATA_VER_COUNT] = {
  sizeof(RSP_PAR_300::RSPInputVData_t_IV2),
  sizeof(RSP_PAR_300::RSPInputVData_t_IV3),
  sizeof(RSP_PAR_300::RSPInputVData_t_IV4),
  sizeof(RSP_PAR_300::RSPInputVData_t_IV5),
  sizeof(RSP_PAR_300::RSPInputVData_t_IV6),
  sizeof(RSP_PAR_300::RSPInputVData_t_IV7),
  (sizeof(RSP_PAR_300::RSPInputVData_t_IV7)+2u),
  sizeof(RSP_PAR_300::RSPInputVData_t_IV8),
  sizeof(RSP_PAR_300::RSPInputVData_t_IVL)
};

unsigned long CConvVehPar::SUPPORTED_SIZE_VDY_INPUT[CConvVehPar::VDY_IN_VER_COUNT ] = { sizeof(VDY_PAR_300::VDYInputData_v1_t),
  sizeof(VDY_PAR_300::VDYInputData_v2_t),
  sizeof(VDY_PAR_300::VDYInputData_v3_t),
  sizeof(VDY_PAR_300::VDYInputData_v4_t)
};

unsigned long CConvVehPar::VEHPAR_SUPPORTED_SIZE[CConvVehPar::VEHPAR_INPUT_VERSION_COUNT]=
{
  sizeof(VehParV0::VehPar_t),
  sizeof(VehParV1::VehPar_t),
  sizeof(VehParV2::VehPar_t),
  sizeof(VehParV3::VehPar_t),
  sizeof(VehParV3::VehPar_t),
  sizeof(VehParV5::VehPar_t),
  sizeof(VehParV6::VehPar_t),
  sizeof(VehParV7::VehPar_t),
  sizeof(VehParV8::VehPar_t),
  sizeof(VehParV9::VehPar_t),
  sizeof(VehParV9::VehPar_t)
};

CVersionInfoImpl * const CConvVehPar::VEHPAR_VERSION_NUMBERS[VEHPAR_INPUT_VERSION_COUNT]=
{
  &VEH_PAR_V0_VERINFO,
  &VEH_PAR_V1_VERINFO,
  &VEH_PAR_V2_VERINFO,
  &VEH_PAR_V3_VERINFO,
  &VEH_PAR_V4_VERINFO,
  &VEH_PAR_V5_VERINFO,
  &VEH_PAR_V6_VERINFO,
  &VEH_PAR_V7_VERINFO,
  &VEH_PAR_V8_VERINFO,
  &VEH_PAR_V9_VERINFO,
  &VEH_PAR_V19_VERINFO
};

const TCHAR* CConvVehPar::DEP_NAMES[CConvVehPar::DEP_COUNT] = {_T("VDYVersion"),
                                                               _T("RSPVersion"),
                                                               _T("ALNVersion"),
                                                               _T("EMVersion"),
                                                               _T("FCTVersion")};

const uint32 CConvVehPar::DefaultStateWord = 0xAAAAAAAA;  // Set to 0xAAAAAAAA for VDY_IO_STATE_NOTAVAIL, 0x55555555 for VDY_IO_STATE_INVALID, 0 for VDY_IO_STATE_VALID
#define ALL_STATE_VALID                    0x0

template<class T> T ValidateValueRange(T value, const T & minval, const T & maxval, const T & defvalue)
{
  if ((value >= minval) && (value <= maxval))
  {
    return value;
  }
  else
  {
    return defvalue;
  }
}

CConvVehPar::CConvVehPar(void)
: CSimConverterBase(DEP_NAMES, DEP_COUNT),
m_VehParV0(), m_VehParV1(), m_VehParV2(), m_VehParV3()
{
}

CConvVehPar::~CConvVehPar(void)
{
}

void CConvVehPar::InitDefaultVehParV0(VehParV0::VehPar_t * const pDest)
{
  // Default values taken from Algo interface XLS
  pDest->uiVersionNumber              = 0;
  pDest->VehParMain.State[0]          = DefaultStateWord;
  pDest->VehParMain.State[1]          = DefaultStateWord;
  pDest->VehParMain.SelfSteerGrad     = 0.00488692f;
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = 1000.f;
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = 17.5f;
  pDest->VehParMain.WheelBase           = 2.854f;
  pDest->VehParMain.TrackWidthFront     = 1.559f;
  pDest->VehParMain.TrackWidthRear      = 1.552f;
  pDest->VehParMain.VehWeight           = 1725.f;
  pDest->VehParMain.CntrOfGravHeight    = 0.56f;
  pDest->VehParMain.AxisLoadDistr       = 0.52f;
  pDest->VehParMain.WhlLoadDepFrontAxle = 1.5f;
  pDest->VehParMain.WhlLoadDepRearAxle  = 1.0f;
  pDest->VehParMain.WhlCircumference    = 2.008f;
  pDest->VehParMain.DrvAxle             = 1u;
  pDest->VehParMain.WhlTcksPerRev       = 48u;
  pDest->VehParMain.FrCrnrStiff         = 0.f;
  pDest->VehParMain.ReCrnrStiff         = 0.f;
  pDest->VehParMain.Unc.SelfSteerGrad   = 1.f;
  pDest->VehParAdd.VehicleWidth         = 2.f;
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = 4.5f;
#endif
  pDest->VehParAdd.CurbWeight           = 1650.f; // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = 0.6f;   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = 0.0f;
  pDest->SensorMounting.LongPos         = 0.7f;
  pDest->SensorMounting.VertPos         = 0.35f;
  pDest->SensorMounting.PitchAngle      = 0.f;
  pDest->SensorMounting.Orientation     = SENSOR_OR_NORMAL;
  pDest->SensorMounting.YawAngle        = 0.f;
  pDest->Sensor.CoverDamping            = 5.f;
  pDest->Sensor.fCoverageAngle          = 20.f;
  pDest->Sensor.fLobeAngle              = 8.f;
  pDest->Sensor.fCycleTime              = 0.066f;
  pDest->Sensor.uNoOfScans              = 2u;
}


void CConvVehPar::InitDefaultVehParV1(VehParV1::VehPar_t * const pDest)
{
  // Default values taken from Algo interface XLS
  pDest->uiVersionNumber              = 1;
  pDest->VehParMain.State[0]          = DefaultStateWord;
  pDest->VehParMain.State[1]          = DefaultStateWord;
  pDest->VehParMain.SelfSteerGrad     = 0.00488692f;
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = 1000.f;
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = 17.5f;
  pDest->VehParMain.WheelBase           = 2.854f;
  pDest->VehParMain.TrackWidthFront     = 1.559f;
  pDest->VehParMain.TrackWidthRear      = 1.552f;
  pDest->VehParMain.VehWeight           = 1725.f;
  pDest->VehParMain.CntrOfGravHeight    = 0.56f;
  pDest->VehParMain.AxisLoadDistr       = 0.52f;
  pDest->VehParMain.WhlLoadDepFrontAxle = 1.5f;
  pDest->VehParMain.WhlLoadDepRearAxle  = 1.0f;
  pDest->VehParMain.WhlCircumference    = 2.008f;
  pDest->VehParMain.DrvAxle             = 1u;
  pDest->VehParMain.WhlTcksPerRev       = 48u;
  pDest->VehParMain.FrCrnrStiff         = 0.f;
  pDest->VehParMain.ReCrnrStiff         = 0.f;
  pDest->VehParMain.Unc.SelfSteerGrad   = 1.f;
  pDest->VehParAdd.VehicleWidth         = 2.f;
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = 4.5f;
#endif
  pDest->VehParAdd.CurbWeight           = 1650.f; // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = 0.6f;   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = 0.0f;
  pDest->SensorMounting.LongPos         = 0.7f;
  pDest->SensorMounting.VertPos         = 0.35f;
  pDest->SensorMounting.PitchAngle      = 0.f;
  pDest->SensorMounting.Orientation     = SENSOR_OR_NORMAL;
  pDest->SensorMounting.YawAngle        = 0.f;
  pDest->Sensor.CoverDamping            = 5.f;
  pDest->Sensor.fCoverageAngle          = 20.f;
  pDest->Sensor.fLobeAngle              = 8.f;
  pDest->Sensor.fCycleTime              = 0.066f;
  pDest->Sensor.uNoOfScans              = 2u;
}


void CConvVehPar::InitDefaultVehParV2(VehParV2::VehPar_t * const pDest)
{
  // Default values taken from Algo interface XLS
  pDest->uiVersionNumber              = 2;
  pDest->VehParMain.State[0]          = DefaultStateWord;
  pDest->VehParMain.State[1]          = DefaultStateWord;
  pDest->VehParMain.SelfSteerGrad     = 0.00488692f;
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = 1000.f;
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = 17.5f;
  pDest->VehParMain.WheelBase           = 2.854f;
  pDest->VehParMain.TrackWidthFront     = 1.559f;
  pDest->VehParMain.TrackWidthRear      = 1.552f;
  pDest->VehParMain.VehWeight           = 1725.f;
  pDest->VehParMain.CntrOfGravHeight    = 0.56f;
  pDest->VehParMain.AxisLoadDistr       = 0.52f;
  pDest->VehParMain.WhlLoadDepFrontAxle = 1.5f;
  pDest->VehParMain.WhlLoadDepRearAxle  = 1.0f;
  pDest->VehParMain.WhlCircumference    = 2.008f;
  pDest->VehParMain.DrvAxle             = 1u;
  pDest->VehParMain.WhlTcksPerRev       = 48u;
  pDest->VehParMain.FrCrnrStiff         = 0.f;
  pDest->VehParMain.ReCrnrStiff         = 0.f;
  pDest->VehParAdd.VehicleWidth         = 2.f;
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = 4.5f;
#endif
  pDest->VehParAdd.CurbWeight           = 1650.f; // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = 0.6f;   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = 0.0f;
  pDest->SensorMounting.LongPos         = 0.7f;
  pDest->SensorMounting.VertPos         = 0.35f;
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.PitchAngle      = 0.f;
  pDest->SensorMounting.Orientation     = SENSOR_OR_NORMAL;
  pDest->SensorMounting.YawAngle        = 0.f;
  pDest->Sensor.CoverDamping            = 5.f;
  pDest->Sensor.fCoverageAngle          = 20.f;
  pDest->Sensor.fLobeAngle              = 8.f;
  pDest->Sensor.fCycleTime              = 0.066f;
  pDest->Sensor.uNoOfScans              = 2u;
}


void CConvVehPar::InitDefaultVehParV3(VehParV3::VehPar_t * const pDest)
{
  // Default values taken from Algo interface XLS
  pDest->uiVersionNumber              = 3;
  pDest->VehParMain.State[0]          = DefaultStateWord;
  pDest->VehParMain.State[1]          = DefaultStateWord;
  pDest->VehParMain.SelfSteerGrad     = 0.00488692f;
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = 1000.f;
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = 17.5f;
  pDest->VehParMain.WheelBase           = 2.854f;
  pDest->VehParMain.TrackWidthFront     = 1.559f;
  pDest->VehParMain.TrackWidthRear      = 1.552f;
  pDest->VehParMain.VehWeight           = 1725.f;
  pDest->VehParMain.CntrOfGravHeight    = 0.56f;
  pDest->VehParMain.AxisLoadDistr       = 0.52f;
  pDest->VehParMain.WhlLoadDepFrontAxle = 1.5f;
  pDest->VehParMain.WhlLoadDepRearAxle  = 1.0f;
  pDest->VehParMain.WhlCircumference    = 2.008f;
  pDest->VehParMain.DrvAxle             = 1u;
  pDest->VehParMain.WhlTcksPerRev       = 48u;
  pDest->VehParMain.FrCrnrStiff         = 0.f;
  pDest->VehParMain.ReCrnrStiff         = 0.f;

  pDest->VehParAdd.State[0]          = DefaultStateWord;
  pDest->VehParAdd.State[1]          = DefaultStateWord;
  pDest->VehParAdd.VehicleWidth         = 2.f;
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = 4.5f;
#endif
  pDest->VehParAdd.CurbWeight           = 1650.f; // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = 0.6f;   // NOTE: No default in XLS

  pDest->SensorMounting.State[0]          = DefaultStateWord;
  pDest->SensorMounting.State[1]          = DefaultStateWord;
  pDest->SensorMounting.LatPos          = 0.0f;
  pDest->SensorMounting.LongPos         = 0.7f;
  pDest->SensorMounting.VertPos         = 0.35f;
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.PitchAngle      = 0.f;
  pDest->SensorMounting.Orientation     = SENSOR_OR_NORMAL;
  pDest->SensorMounting.YawAngle        = 0.f;

  pDest->Sensor.State[0]          = DefaultStateWord;
  pDest->Sensor.State[1]          = DefaultStateWord;
  pDest->Sensor.CoverDamping            = 5.f;
  pDest->Sensor.fCoverageAngle          = 20.f;
  pDest->Sensor.fLobeAngle              = 8.f;
  pDest->Sensor.fCycleTime              = 0.066f;
  pDest->Sensor.uNoOfScans              = 2u;
}


void CConvVehPar::InitDefaultVehParV5(VehParV5::VehPar_t * const pDest)
{
  // Default values taken from Algo interface XLS
  pDest->uiVersionNumber                    = 5;

  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehParV5::AL_SIG_STATE_OK;

  pDest->VehParMain.State[0]          = DefaultStateWord;
  pDest->VehParMain.State[1]          = DefaultStateWord;
  pDest->VehParMain.SelfSteerGrad     = 0.00488692f;
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = 1000.f;
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = 17.5f;
  pDest->VehParMain.WheelBase           = 2.854f;
  pDest->VehParMain.TrackWidthFront     = 1.559f;
  pDest->VehParMain.TrackWidthRear      = 1.552f;
  pDest->VehParMain.VehWeight           = 1725.f;
  pDest->VehParMain.CntrOfGravHeight    = 0.56f;
  pDest->VehParMain.AxisLoadDistr       = 0.52f;
  pDest->VehParMain.WhlLoadDepFrontAxle = 1.5f;
  pDest->VehParMain.WhlLoadDepRearAxle  = 1.0f;
  pDest->VehParMain.WhlCircumference    = 2.008f;
  pDest->VehParMain.DrvAxle             = 1u;
  pDest->VehParMain.WhlTcksPerRev       = 48u;
  pDest->VehParMain.FrCrnrStiff         = 0.f;
  pDest->VehParMain.ReCrnrStiff         = 0.f;

  pDest->VehParAdd.State[0]          = DefaultStateWord;
  pDest->VehParAdd.State[1]          = DefaultStateWord;
  pDest->VehParAdd.VehicleWidth         = 2.f;
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = 4.5f;
#endif
  pDest->VehParAdd.CurbWeight           = 1650.f; // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = 0.6f;   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = VehParV5::VEH_PAR_ADD_STEERING_VAR_UNKNOWN;

  pDest->SensorMounting.State[0]          = DefaultStateWord;
  pDest->SensorMounting.State[1]          = DefaultStateWord;
  pDest->SensorMounting.LatPos          = 0.0f;
  pDest->SensorMounting.LongPos         = 0.7f;
  pDest->SensorMounting.VertPos         = 0.35f;
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.PitchAngle      = 0.f;
  pDest->SensorMounting.Orientation     = SENSOR_OR_NORMAL;
  pDest->SensorMounting.RollAngle       = 0.f;
  pDest->SensorMounting.YawAngle        = 0.f;

  pDest->Sensor.State[0]                = DefaultStateWord;
  pDest->Sensor.State[1]                = DefaultStateWord;
  pDest->Sensor.CoverDamping            = 5.f;
  pDest->Sensor.fCoverageAngle          = 20.f;
  pDest->Sensor.fLobeAngle              = 8.f;
  pDest->Sensor.fCycleTime              = 0.066f;
  pDest->Sensor.uNoOfScans              = 2u;
}


void CConvVehPar::InitDefaultVehParV6(VehParV6::VehPar_t * const pDest)
{
  // Default values taken from Algo interface XLS
  pDest->uiVersionNumber                    = 6;

  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehParV6::AL_SIG_STATE_OK;

  pDest->VehParMain.State[0]          = DefaultStateWord;
  pDest->VehParMain.State[1]          = DefaultStateWord;
  pDest->VehParMain.SelfSteerGrad     = 0.00488692f;
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = 1000.f;
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = 17.5f;
  pDest->VehParMain.WheelBase           = 2.854f;
  pDest->VehParMain.TrackWidthFront     = 1.559f;
  pDest->VehParMain.TrackWidthRear      = 1.552f;
  pDest->VehParMain.VehWeight           = 1725.f;
  pDest->VehParMain.CntrOfGravHeight    = 0.56f;
  pDest->VehParMain.AxisLoadDistr       = 0.52f;
  pDest->VehParMain.WhlLoadDepFrontAxle = 1.5f;
  pDest->VehParMain.WhlLoadDepRearAxle  = 1.0f;
  pDest->VehParMain.WhlCircumference    = 2.008f;
  pDest->VehParMain.DrvAxle             = 1u;
  pDest->VehParMain.WhlTcksPerRev       = 48u;
  pDest->VehParMain.FrCrnrStiff         = 0.f;
  pDest->VehParMain.ReCrnrStiff         = 0.f;

  pDest->VehParAdd.State[0]          = DefaultStateWord;
  pDest->VehParAdd.State[1]          = DefaultStateWord;
  pDest->VehParAdd.VehicleWidth         = 2.f;
  pDest->VehParAdd.VehicleLength        = 4.5f;
  pDest->VehParAdd.CurbWeight           = 1650.f; // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = 0.6f;   // NOTE: No default in XLS
  pDest->VehParAdd.FrontAxleRoadDist    = 0.2F;   // NOTE: No default in XLS
  pDest->VehParAdd.WheelWidth           = 0.2F;   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = VehParV5::VEH_PAR_ADD_STEERING_VAR_UNKNOWN;

  pDest->SensorMounting.State[0]          = DefaultStateWord;
  pDest->SensorMounting.State[1]          = DefaultStateWord;
  pDest->SensorMounting.LatPos          = 0.0f;
  pDest->SensorMounting.LongPos         = 0.7f;
  pDest->SensorMounting.VertPos         = 0.35f;
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.PitchAngle      = 0.f;
  pDest->SensorMounting.Orientation     = SENSOR_OR_NORMAL;
  pDest->SensorMounting.RollAngle       = 0.f;
  pDest->SensorMounting.YawAngle        = 0.f;

  pDest->Sensor.State[0]                = DefaultStateWord;
  pDest->Sensor.State[1]                = DefaultStateWord;
  pDest->Sensor.CoverDamping            = 5.f;
  pDest->Sensor.fCoverageAngle          = 20.f;
  pDest->Sensor.fLobeAngle              = 8.f;
  pDest->Sensor.fCycleTime              = 0.066f;
  pDest->Sensor.uNoOfScans              = 2u;
}


void CConvVehPar::InitDefaultVehParV7(VehParV7::VehPar_t * const pDest)
{
  // Default values taken from Algo interface XLS
  pDest->uiVersionNumber                    = 7;

  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehParV6::AL_SIG_STATE_OK;

  pDest->VehParMain.State[0]          = DefaultStateWord;
  pDest->VehParMain.State[1]          = DefaultStateWord;
  pDest->VehParMain.SelfSteerGrad     = 0.00488692f;
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = 1000.f;
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = 17.5f;
  pDest->VehParMain.WheelBase           = 2.854f;
  pDest->VehParMain.TrackWidthFront     = 1.559f;
  pDest->VehParMain.TrackWidthRear      = 1.552f;
  pDest->VehParMain.VehWeight           = 1725.f;
  pDest->VehParMain.CntrOfGravHeight    = 0.56f;
  pDest->VehParMain.AxisLoadDistr       = 0.52f;
  pDest->VehParMain.WhlLoadDepFrontAxle = 1.5f;
  pDest->VehParMain.WhlLoadDepRearAxle  = 1.0f;
  pDest->VehParMain.WhlCircumference    = 2.008f;
  pDest->VehParMain.DrvAxle             = 1u;
  pDest->VehParMain.WhlTcksPerRev       = 48u;
  pDest->VehParMain.FrCrnrStiff         = 0.f;
  pDest->VehParMain.ReCrnrStiff         = 0.f;

  pDest->VehParAdd.State[0]             = DefaultStateWord;
  pDest->VehParAdd.State[1]             = DefaultStateWord;
  pDest->VehParAdd.VehicleWidth         = 2.f;
  pDest->VehParAdd.VehicleLength        = 4.5f;
  pDest->VehParAdd.CurbWeight           = 1650.f;
  pDest->VehParAdd.OverhangFront        = 0.6f;
  pDest->VehParAdd.FrontAxleRoadDist    = 0.2F;
  pDest->VehParAdd.WheelWidth           = 0.2F;
  pDest->VehParAdd.PassableHeight       = 1.2f;
  pDest->VehParAdd.DistCameraToHoodX    = 1.0f;
  pDest->VehParAdd.DistCameraToHoodY    = 0.0f;
  pDest->VehParAdd.SteeringVariant      = VehParV7::VEH_PAR_ADD_STEERING_VAR_UNKNOWN;

  pDest->SensorMounting.State[0]        = DefaultStateWord;
  pDest->SensorMounting.State[1]        = DefaultStateWord;
  pDest->SensorMounting.LatPos          = 0.0f;
  pDest->SensorMounting.LongPos         = 0.7f;
  pDest->SensorMounting.VertPos         = 0.35f;
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.PitchAngle      = 0.f;
  pDest->SensorMounting.Orientation     = SENSOR_OR_NORMAL;
  pDest->SensorMounting.RollAngle       = 0.f;
  pDest->SensorMounting.YawAngle        = 0.f;

  pDest->Sensor.State[0]                = DefaultStateWord;
  pDest->Sensor.State[1]                = DefaultStateWord;
  pDest->Sensor.CoverDamping            = 5.f;
  pDest->Sensor.fCoverageAngle          = 20.f;
  pDest->Sensor.fLobeAngle              = 8.f;
  pDest->Sensor.fCycleTime              = 0.066f;
  pDest->Sensor.uNoOfScans              = 2u;
}


void CConvVehPar::InitDefaultVehParV8(VehParV8::VehPar_t * const pDest)
{
  // Default values taken from Algo interface XLS
  pDest->uiVersionNumber                    = 7;

  pDest->sSigHeader.uiTimeStamp          = 0U;
  pDest->sSigHeader.uiMeasurementCounter = 0U;
  pDest->sSigHeader.uiCycleCounter       = 0U;
  pDest->sSigHeader.eSigStatus           = VehParV6::AL_SIG_STATE_OK;

  memset(pDest->VehParMain.State, VDY_IO_STATE_INIT, sizeof(pDest->VehParMain.State));
  pDest->VehParMain.SelfSteerGrad     = 0.00488692f;
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = 1000.f;
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = 17.5f;
  pDest->VehParMain.WheelBase           = 2.854f;
  pDest->VehParMain.TrackWidthFront     = 1.559f;
  pDest->VehParMain.TrackWidthRear      = 1.552f;
  pDest->VehParMain.VehWeight           = 1725.f;
  pDest->VehParMain.CntrOfGravHeight    = 0.56f;
  pDest->VehParMain.AxisLoadDistr       = 0.52f;
  pDest->VehParMain.WhlLoadDepFrontAxle = 1.5f;
  pDest->VehParMain.WhlLoadDepRearAxle  = 1.0f;
  pDest->VehParMain.WhlCircumference    = 2.008f;
  pDest->VehParMain.DrvAxle             = 1u;
  pDest->VehParMain.WhlTcksPerRev       = 48u;
  pDest->VehParMain.FrCrnrStiff         = 0.f;
  pDest->VehParMain.ReCrnrStiff         = 0.f;

  memset(pDest->VehParAdd.State, VDY_IO_STATE_INIT, sizeof(pDest->VehParMain.State));
  pDest->VehParAdd.VehicleWidth         = 2.f;
  pDest->VehParAdd.VehicleLength        = 4.5f;
  pDest->VehParAdd.CurbWeight           = 1650.f;
  pDest->VehParAdd.OverhangFront        = 0.6f;
  pDest->VehParAdd.FrontAxleRoadDist    = 0.2F;
  pDest->VehParAdd.WheelWidth           = 0.2F;
  pDest->VehParAdd.PassableHeight       = 1.2f;
  pDest->VehParAdd.DistCameraToHoodX    = 1.0f;
  pDest->VehParAdd.DistCameraToHoodY    = 0.0f;
  pDest->VehParAdd.SteeringVariant      = VehParV7::VEH_PAR_ADD_STEERING_VAR_UNKNOWN;

  memset(pDest->SensorMounting.State, VDY_IO_STATE_INIT, sizeof(pDest->VehParMain.State));
  pDest->SensorMounting.LatPos          = 0.0f;
  pDest->SensorMounting.LongPos         = 0.7f;
  pDest->SensorMounting.VertPos         = 0.35f;
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.PitchAngle      = 0.f;
  pDest->SensorMounting.Orientation     = SENSOR_OR_NORMAL;
  pDest->SensorMounting.RollAngle       = 0.f;
  pDest->SensorMounting.YawAngle        = 0.f;

  memset(pDest->Sensor.State, VDY_IO_STATE_INIT, sizeof(pDest->VehParMain.State));
  pDest->Sensor.CoverDamping            = 5.f;
  pDest->Sensor.fCoverageAngle          = 20.f;
  pDest->Sensor.fLobeAngle              = 8.f;
  pDest->Sensor.fCycleTime              = 0.066f;
  pDest->Sensor.uNoOfScans              = 2u;
}

void CConvVehPar::InitDefaultVehParV9(VehParV9::VehPar_t * const pDest)
{
  // Default values taken from Algo interface XLS
  pDest->uiVersionNumber                    = 9;

  pDest->sSigHeader.uiTimeStamp          = 0U;
  pDest->sSigHeader.uiMeasurementCounter = 0U;
  pDest->sSigHeader.uiCycleCounter       = 0U;
  pDest->sSigHeader.eSigStatus           = VehParV6::AL_SIG_STATE_OK;

  memset(pDest->VehParMain.State, VehParV9::VEH_PAR_IO_STATE_INIT, sizeof(pDest->VehParMain.State));
  pDest->VehParMain.SelfSteerGrad     = 0.00488692f;
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = 1000.f;
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = 0.f;
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = 17.5f;
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = 17.5f;
  pDest->VehParMain.WheelBase           = 2.854f;
  pDest->VehParMain.TrackWidthFront     = 1.559f;
  pDest->VehParMain.TrackWidthRear      = 1.552f;
  pDest->VehParMain.VehWeight           = 1725.f;
  pDest->VehParMain.CntrOfGravHeight    = 0.56f;
  pDest->VehParMain.AxisLoadDistr       = 0.52f;
  pDest->VehParMain.WhlLoadDepFrontAxle = 1.5f;
  pDest->VehParMain.WhlLoadDepRearAxle  = 1.0f;
  pDest->VehParMain.WhlCircumference    = 2.008f;
  pDest->VehParMain.DrvAxle             = 1u;
  pDest->VehParMain.WhlTcksPerRev       = 48u;
  pDest->VehParMain.FrCrnrStiff         = 0.f;
  pDest->VehParMain.ReCrnrStiff         = 0.f;

  memset(pDest->VehParAdd.State, VehParV9::VEH_PAR_IO_STATE_INIT, sizeof(pDest->VehParMain.State));
  pDest->VehParAdd.VehicleWidth         = 2.f;
  pDest->VehParAdd.VehicleLength        = 4.5f;
  pDest->VehParAdd.CurbWeight           = 1650.f;
  pDest->VehParAdd.OverhangFront        = 0.6f;
  pDest->VehParAdd.FrontAxleRoadDist    = 0.2F;
  pDest->VehParAdd.WheelWidth           = 0.2F;
  pDest->VehParAdd.PassableHeight       = 1.2f;
  pDest->VehParAdd.DistCameraToHoodX    = 1.0f;
  pDest->VehParAdd.DistCameraToHoodY    = 0.0f;
  pDest->VehParAdd.SteeringVariant      = VehParV7::VEH_PAR_ADD_STEERING_VAR_UNKNOWN;
  pDest->VehParAdd.SteeringWheelNumber  = VehParV9::VEH_PAR_ADD_STEERING_WHEEL_TWO;

  memset(pDest->SensorMounting.State, VehParV9::VEH_PAR_IO_STATE_INIT, sizeof(pDest->VehParMain.State));
  pDest->SensorMounting.LatPos          = 0.0f;
  pDest->SensorMounting.LongPos         = 0.7f;
  pDest->SensorMounting.VertPos         = 0.35f;
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.PitchAngle      = 0.f;
  pDest->SensorMounting.Orientation     = SENSOR_OR_NORMAL;
  pDest->SensorMounting.RollAngle       = 0.f;
  pDest->SensorMounting.YawAngle        = 0.f;

  memset(pDest->Sensor.State, VehParV9::VEH_PAR_IO_STATE_INIT, sizeof(pDest->VehParMain.State));
  pDest->Sensor.CoverDamping            = 5.f;
  pDest->Sensor.fCoverageAngle          = 20.f;
  pDest->Sensor.fLobeAngle              = 8.f;
  pDest->Sensor.fCycleTime              = 0.066f;
  pDest->Sensor.uNoOfScans              = 2u;
}

void CConvVehPar::ConvertToVehParV0(VehParV0::VehPar_t * const pDest, const VehParV1::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 0;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.Unc.SelfSteerGrad   = pInput->VehParMain.SelfSteerGrad;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV1::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV0(VehParV0::VehPar_t * const pDest, const VehParV2::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 0;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.Unc.SelfSteerGrad   = pInput->VehParMain.SelfSteerGrad;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV2::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV0(VehParV0::VehPar_t * const pDest, const VehParV3::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 0;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.Unc.SelfSteerGrad   = pInput->VehParMain.SelfSteerGrad;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV3::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV1(VehParV1::VehPar_t * const pDest, const VehParV0::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 1;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.Unc.SelfSteerGrad   = pInput->VehParMain.SelfSteerGrad;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV0::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV1(VehParV1::VehPar_t * const pDest, const VehParV2::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 1;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.Unc.SelfSteerGrad   = pInput->VehParMain.SelfSteerGrad;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV1::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV1(VehParV1::VehPar_t * const pDest, const VehParV3::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 1;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.Unc.SelfSteerGrad   = pInput->VehParMain.SelfSteerGrad;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV1::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV2(VehParV2::VehPar_t * const pDest, const VehParV0::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 2;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = - ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = - ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV2::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV2(VehParV2::VehPar_t * const pDest, const VehParV1::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 2;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV2::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV2(VehParV2::VehPar_t * const pDest, const VehParV3::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 2;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV2::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV3(VehParV3::VehPar_t * const pDest, const VehParV0::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 3;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParAdd.State[0]             = ALL_STATE_VALID;
  pDest->VehParAdd.State[1]             = ALL_STATE_VALID;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.State[0]        = ALL_STATE_VALID;
  pDest->SensorMounting.State[1]        = ALL_STATE_VALID;
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV3::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.State[0]                = ALL_STATE_VALID;
  pDest->Sensor.State[1]                = ALL_STATE_VALID;
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV3(VehParV3::VehPar_t * const pDest, const VehParV1::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 3;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParAdd.State[0]             = ALL_STATE_VALID;
  pDest->VehParAdd.State[1]             = ALL_STATE_VALID;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.State[0]        = ALL_STATE_VALID;
  pDest->SensorMounting.State[1]        = ALL_STATE_VALID;
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = 2.184f;
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV3::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.State[0]                = ALL_STATE_VALID;
  pDest->Sensor.State[1]                = ALL_STATE_VALID;
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV3(VehParV3::VehPar_t * const pDest, const VehParV2::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 3;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParAdd.State[0]             = ALL_STATE_VALID;
  pDest->VehParAdd.State[1]             = ALL_STATE_VALID;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.State[0]        = ALL_STATE_VALID;
  pDest->SensorMounting.State[1]        = ALL_STATE_VALID;
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV3::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.State[0]                = ALL_STATE_VALID;
  pDest->Sensor.State[1]                = ALL_STATE_VALID;
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV5(VehParV5::VehPar_t * const pDest, const VehParV3::VehPar_t * const pInput)
{
  // Initialize default values
  InitDefaultVehParV5(pDest);

  pDest->uiVersionNumber              = 5;

  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehParV5::AL_SIG_STATE_OK;

  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];

  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  pDest->VehParAdd.State[0]             = ALL_STATE_VALID;
  pDest->VehParAdd.State[1]             = ALL_STATE_VALID;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = VehParV5::VEH_PAR_ADD_STEERING_VAR_UNKNOWN;

  pDest->SensorMounting.State[0]        = ALL_STATE_VALID;
  pDest->SensorMounting.State[1]        = ALL_STATE_VALID;
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV5::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle       = 0.0F;
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  pDest->Sensor.State[0]                = ALL_STATE_VALID;
  pDest->Sensor.State[1]                = ALL_STATE_VALID;
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV6(VehParV6::VehPar_t * const pDest, const VehParV5::VehPar_t * const pInput)
{
  // Initialize default values
  InitDefaultVehParV6(pDest);

  pDest->uiVersionNumber              = 6;
// V5 has signal-header
  pDest->sSignalHeader.uiTimeStamp          = pInput->sSignalHeader.uiTimeStamp;
  pDest->sSignalHeader.uiMeasurementCounter = pInput->sSignalHeader.uiMeasurementCounter;
  pDest->sSignalHeader.uiCycleCounter       = pInput->sSignalHeader.uiCycleCounter;
  pDest->sSignalHeader.eSigStatus           = pInput->sSignalHeader.eSigStatus;

  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];

  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  pDest->VehParAdd.State[0]             = ALL_STATE_VALID;
  pDest->VehParAdd.State[1]             = ALL_STATE_VALID;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  // defaults are defined in the default function
  //pDest->VehParAdd.FrontAxleRoadDist    = 0.2F;   // NOTE: No default in XLS
  //pDest->VehParAdd.WheelWidth           = 0.2F;   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = VehParV6::VEH_PAR_ADD_STEERING_VAR_UNKNOWN;

  pDest->SensorMounting.State[0]        = ALL_STATE_VALID;
  pDest->SensorMounting.State[1]        = ALL_STATE_VALID;
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV6::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle       = 0.0F;
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  pDest->Sensor.State[0]                = ALL_STATE_VALID;
  pDest->Sensor.State[1]                = ALL_STATE_VALID;
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV6(VehParV6::VehPar_t * const pDest, const VehParV3::VehPar_t * const pInput)
{
  // Initialize default values
  InitDefaultVehParV6(pDest);

  pDest->uiVersionNumber              = 6;
// V3 has no signal-header
  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehParV6::AL_SIG_STATE_OK;

  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];

  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  pDest->VehParAdd.State[0]             = ALL_STATE_VALID;
  pDest->VehParAdd.State[1]             = ALL_STATE_VALID;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  // defaults are defined in the default function
  //pDest->VehParAdd.FrontAxleRoadDist    = 0.2F;   // NOTE: No default in XLS
  //pDest->VehParAdd.WheelWidth           = 0.2F;   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = VehParV6::VEH_PAR_ADD_STEERING_VAR_UNKNOWN;

  pDest->SensorMounting.State[0]        = ALL_STATE_VALID;
  pDest->SensorMounting.State[1]        = ALL_STATE_VALID;
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV6::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle       = 0.0F;
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  pDest->Sensor.State[0]                = ALL_STATE_VALID;
  pDest->Sensor.State[1]                = ALL_STATE_VALID;
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV7(VehParV7::VehPar_t * const pDest, const VehParV6::VehPar_t * const pInput)
{
  // Initialize default values
  InitDefaultVehParV7(pDest);

  pDest->uiVersionNumber              = 7;

  // V6 has signal-header
  pDest->sSignalHeader.uiTimeStamp          = pInput->sSignalHeader.uiTimeStamp;
  pDest->sSignalHeader.uiMeasurementCounter = pInput->sSignalHeader.uiMeasurementCounter;
  pDest->sSignalHeader.uiCycleCounter       = pInput->sSignalHeader.uiCycleCounter;
  pDest->sSignalHeader.eSigStatus           = pInput->sSignalHeader.eSigStatus;

  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];

  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  pDest->VehParAdd.State[0]             = pInput->VehParAdd.State[0];
  pDest->VehParAdd.State[1]             = pInput->VehParAdd.State[1];
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f);
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);
  pDest->VehParAdd.FrontAxleRoadDist    = ValidateValueRange(pInput->VehParAdd.FrontAxleRoadDist, 0.f, 5.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.WheelWidth           = ValidateValueRange(pInput->VehParAdd.WheelWidth, 0.f, 1.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = pInput->VehParAdd.SteeringVariant;

  pDest->SensorMounting.State[0]        = pInput->SensorMounting.State[0];
  pDest->SensorMounting.State[1]        = pInput->SensorMounting.State[1];
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV6::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle       = ValidateValueRange(pInput->SensorMounting.RollAngle, -25.f, 25.f, 0.f);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  pDest->Sensor.State[0]                = pInput->Sensor.State[0];
  pDest->Sensor.State[1]                = pInput->Sensor.State[1];
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV7(VehParV7::VehPar_t * const pDest, const VehParV6A::VehPar_t * const pInput)
{
  // Initialize default values
  InitDefaultVehParV7(pDest);

  pDest->uiVersionNumber              = 7;

  // V6 has signal-header
  pDest->sSignalHeader.uiTimeStamp          = pInput->sSignalHeader.uiTimeStamp;
  pDest->sSignalHeader.uiMeasurementCounter = pInput->sSignalHeader.uiMeasurementCounter;
  pDest->sSignalHeader.uiCycleCounter       = pInput->sSignalHeader.uiCycleCounter;
  pDest->sSignalHeader.eSigStatus           = pInput->sSignalHeader.eSigStatus;

  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];

  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  pDest->VehParAdd.State[0]             = pInput->VehParAdd.State[0];
  pDest->VehParAdd.State[1]             = pInput->VehParAdd.State[1];
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(4.5F, 1.f, 10.f, 4.5f);
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f);
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);
  pDest->VehParAdd.FrontAxleRoadDist    = ValidateValueRange(pInput->VehParAdd.FrontAxleRoadDist, 0.f, 5.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.WheelWidth           = ValidateValueRange(pInput->VehParAdd.WheelWidth, 0.f, 1.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = pInput->VehParAdd.SteeringVariant;

  pDest->SensorMounting.State[0]        = pInput->SensorMounting.State[0];
  pDest->SensorMounting.State[1]        = pInput->SensorMounting.State[1];
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV6A::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle       = ValidateValueRange(pInput->SensorMounting.RollAngle, -25.f, 25.f, 0.f);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  pDest->Sensor.State[0]                = pInput->Sensor.State[0];
  pDest->Sensor.State[1]                = pInput->Sensor.State[1];
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV7(VehParV7::VehPar_t * const pDest, const VehParV8::VehPar_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehParV7(pDest);

  // Version is already set in default values

  // V7 has a signal-header
  pDest->sSignalHeader.uiTimeStamp              = pInput->sSigHeader.uiTimeStamp;
  pDest->sSignalHeader.uiMeasurementCounter     = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSignalHeader.uiCycleCounter           = pInput->sSigHeader.uiCycleCounter;
  pDest->sSignalHeader.eSigStatus               = pInput->sSigHeader.eSigStatus;

  for (i=0; i<2; i++)
  {
    pDest->VehParMain.State[i]               = ConvertIOState(2*i, (unsigned long *)pInput->VehParMain.State);
  }

  pDest->VehParMain.SelfSteerGrad            = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0] = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1] = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0] = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1] = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0] = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1] = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0] = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1] = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0] = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1] = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase                = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront          = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear           = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight                = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight         = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr            = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle      = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle       = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference         = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle                  = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev            = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff              = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff              = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  for (i=0; i<2; i++)
  {
    pDest->VehParAdd.State[i]                = ConvertIOState(2*i, (unsigned long *)pInput->VehParAdd.State);
  }
  pDest->VehParAdd.VehicleWidth              = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
  pDest->VehParAdd.VehicleLength             = ValidateValueRange(4.5F, 1.f, 10.f, 4.5f);
  pDest->VehParAdd.CurbWeight                = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f);
  pDest->VehParAdd.OverhangFront             = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);
  pDest->VehParAdd.FrontAxleRoadDist         = ValidateValueRange(pInput->VehParAdd.FrontAxleRoadDist, 0.f, 5.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.WheelWidth                = ValidateValueRange(pInput->VehParAdd.WheelWidth, 0.f, 1.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant           = pInput->VehParAdd.SteeringVariant;

  for (i=0; i<2; i++)
  {
    pDest->SensorMounting.State[i]           = ConvertIOState(2*i, (unsigned long *)pInput->SensorMounting.State);
  }
  pDest->SensorMounting.LatPos               = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos              = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG         = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos              = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle           = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation          = ValidateValueRange<VehParV6A::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle            = ValidateValueRange(pInput->SensorMounting.RollAngle, -25.f, 25.f, 0.f);
  pDest->SensorMounting.YawAngle             = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  for (i=0; i<2; i++)
  {
    pDest->Sensor.State[i]                   = ConvertIOState(2*i, (unsigned long *)pInput->Sensor.State);
  }
  pDest->Sensor.CoverDamping                 = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle               = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle                   = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime                   = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans                   = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV8(VehParV8::VehPar_t * const pDest, const VehParV7::VehPar_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehParV8(pDest);

  // Version is already set in default values

  // V7 has a signal-header
  pDest->sSigHeader.uiTimeStamp              = pInput->sSignalHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter     = pInput->sSignalHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter           = pInput->sSignalHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus               = pInput->sSignalHeader.eSigStatus;

  for (i=0; i<VehParV8::VEH_PAR_POS_MAX; i++)
  {
    pDest->VehParMain.State[i]               = ConvertIOState(2*i, (unsigned long *)pInput->VehParMain.State);
  }

  pDest->VehParMain.SelfSteerGrad            = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0] = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1] = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0] = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1] = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0] = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1] = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0] = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1] = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0] = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1] = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase                = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront          = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear           = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight                = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight         = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr            = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle      = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle       = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference         = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev            = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff              = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff              = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  for (i=0; i<VehParV8::VEH_PAR_ADD_MAX; i++)
  {
    pDest->VehParAdd.State[i]                = ConvertIOState(2*i, (unsigned long *)pInput->VehParAdd.State);
  }
  pDest->VehParAdd.VehicleWidth              = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
  pDest->VehParAdd.VehicleLength             = ValidateValueRange(4.5F, 1.f, 10.f, 4.5f);
  pDest->VehParAdd.CurbWeight                = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f);
  pDest->VehParAdd.OverhangFront             = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);
  pDest->VehParAdd.FrontAxleRoadDist         = ValidateValueRange(pInput->VehParAdd.FrontAxleRoadDist, 0.f, 5.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.WheelWidth                = ValidateValueRange(pInput->VehParAdd.WheelWidth, 0.f, 1.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant           = pInput->VehParAdd.SteeringVariant;

  for (i=0; i<VehParV8::VEH_PAR_SEN_MOUNT_MAX; i++)
  {
    pDest->SensorMounting.State[i]           = ConvertIOState(2*i, (unsigned long *)pInput->SensorMounting.State);
  }
  pDest->SensorMounting.LatPos               = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos              = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG         = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos              = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle           = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation          = ValidateValueRange<VehParV6A::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle            = ValidateValueRange(pInput->SensorMounting.RollAngle, -25.f, 25.f, 0.f);
  pDest->SensorMounting.YawAngle             = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  for (i=0; i<VehParV8::VEH_PAR_SENSOR_MAX; i++)
  {
    pDest->Sensor.State[i]                   = ConvertIOState(2*i, (unsigned long *)pInput->Sensor.State);
  }
  pDest->Sensor.CoverDamping                 = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle               = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle                   = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime                   = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans                   = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}

// 8th version to 9th version
void CConvVehPar::ConvertToVehParV9(VehParV9::VehPar_t * const pDest, const VehParV8::VehPar_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehParV9(pDest);

  // Version is already set in default values

 
  pDest->sSigHeader.uiTimeStamp          = pInput->sSigHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter       = pInput->sSigHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus           = pInput->sSigHeader.eSigStatus;

  for (i=0; i<VehParV9::VEH_PAR_POS_MAX; i++)
  {
    pDest->VehParMain.State[i]           = ConvertIOState(2*i, (unsigned long *)pInput->VehParMain.State);
  }
  pDest->VehParMain.SelfSteerGrad        = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  for (i=0; i<VehParV9::VEH_PAR_ADD_MAX; i++)
  {
    pDest->VehParAdd.State[i]          = ConvertIOState(4*i, (unsigned long *)pInput->VehParAdd.State);
  }
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f);
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);
  pDest->VehParAdd.FrontAxleRoadDist    = ValidateValueRange(pInput->VehParAdd.FrontAxleRoadDist, 0.f, 5.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.WheelWidth           = ValidateValueRange(pInput->VehParAdd.WheelWidth, 0.f, 1.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = pInput->VehParAdd.SteeringVariant;
  pDest->VehParAdd.SteeringWheelNumber  = 1;  // in 8th version there is no steering wheel number , so filling with default 2 wheel steer

  for (i=0; i<VehParV9::VEH_PAR_SEN_MOUNT_MAX; i++)
  {
    pDest->SensorMounting.State[i]      = ConvertIOState(4*i, (unsigned long *)pInput->SensorMounting.State);
  }
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV6A::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle       = ValidateValueRange(pInput->SensorMounting.RollAngle, -25.f, 25.f, 0.f);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  for (i=0; i<VehParV9::VEH_PAR_SENSOR_MAX; i++)
  {
    pDest->Sensor.State[i]              = ConvertIOState(4*i, (unsigned long *)pInput->Sensor.State);
  }
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);

}

void CConvVehPar::ConvertToVehParV9(VehParV9::VehPar_t * const pDest, const VehParV9::VehPar_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehParV9(pDest);

  // Version is already set in default values

 
  pDest->sSigHeader.uiTimeStamp          = pInput->sSigHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter       = pInput->sSigHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus           = pInput->sSigHeader.eSigStatus;

  for (i=0; i<VehParV9::VEH_PAR_POS_MAX; i++)
  {
    pDest->VehParMain.State[i]           = ConvertIOState(2*i, (unsigned long *)pInput->VehParMain.State);
  }
  pDest->VehParMain.SelfSteerGrad        = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  for (i=0; i<VehParV9::VEH_PAR_ADD_MAX; i++)
  {
    pDest->VehParAdd.State[i]          = ConvertIOState(4*i, (unsigned long *)pInput->VehParAdd.State);
  }
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f);
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);
  pDest->VehParAdd.FrontAxleRoadDist    = ValidateValueRange(pInput->VehParAdd.FrontAxleRoadDist, 0.f, 5.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.WheelWidth           = ValidateValueRange(pInput->VehParAdd.WheelWidth, 0.f, 1.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = pInput->VehParAdd.SteeringVariant;
  pDest->VehParAdd.SteeringWheelNumber  = 1;  // in 8th version there is no steering wheel number , so filling with default 2 wheel steer

  for (i=0; i<VehParV9::VEH_PAR_SEN_MOUNT_MAX; i++)
  {
    pDest->SensorMounting.State[i]      = ConvertIOState(4*i, (unsigned long *)pInput->SensorMounting.State);
  }
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV6A::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle       = ValidateValueRange(pInput->SensorMounting.RollAngle, -25.f, 25.f, 0.f);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  for (i=0; i<VehParV9::VEH_PAR_SENSOR_MAX; i++)
  {
    pDest->Sensor.State[i]              = ConvertIOState(4*i, (unsigned long *)pInput->Sensor.State);
  }
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);

}

// 9th version to 8th version 
void CConvVehPar::ConvertToVehParV8(VehParV8::VehPar_t * const pDest, const VehParV9::VehPar_t * const pInput)
{
  uint16 i;

  // Initialize default values
  InitDefaultVehParV8(pDest);

  // Version is already set in default values

  pDest->sSigHeader.uiTimeStamp          = pInput->sSigHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pInput->sSigHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter       = pInput->sSigHeader.uiCycleCounter;
  pDest->sSigHeader.eSigStatus           = pInput->sSigHeader.eSigStatus;

  for (i=0; i<VehParV8::VEH_PAR_POS_MAX; i++)
  {
    pDest->VehParMain.State[i]           = ConvertIOState(2*i, (unsigned long *)pInput->VehParMain.State);
  }
  pDest->VehParMain.SelfSteerGrad        = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  for (i=0; i<VehParV8::VEH_PAR_ADD_MAX; i++)
  {
    pDest->VehParAdd.State[i]          = ConvertIOState(4*i, (unsigned long *)pInput->VehParAdd.State);
  }
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f);
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);
  pDest->VehParAdd.FrontAxleRoadDist    = ValidateValueRange(pInput->VehParAdd.FrontAxleRoadDist, 0.f, 5.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.WheelWidth           = ValidateValueRange(pInput->VehParAdd.WheelWidth, 0.f, 1.f, 0.2F);   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = pInput->VehParAdd.SteeringVariant;

  for (i=0; i<VehParV8::VEH_PAR_SEN_MOUNT_MAX; i++)
  {
    pDest->SensorMounting.State[i]      = ConvertIOState(4*i, (unsigned long *)pInput->SensorMounting.State);
  }
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV6A::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle       = ValidateValueRange(pInput->SensorMounting.RollAngle, -25.f, 25.f, 0.f);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  for (i=0; i<VehParV8::VEH_PAR_SENSOR_MAX; i++)
  {
    pDest->Sensor.State[i]              = ConvertIOState(4*i, (unsigned long *)pInput->Sensor.State);
  }
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}

void CConvVehPar::ConvertToVehParV5(VehParV5::VehPar_t * const pDest, const VehParV6::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 5;

  pDest->sSignalHeader.uiTimeStamp          = 0U;
  pDest->sSignalHeader.uiMeasurementCounter = 0U;
  pDest->sSignalHeader.uiCycleCounter       = 0U;
  pDest->sSignalHeader.eSigStatus           = VehParV5::AL_SIG_STATE_OK;

  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];

  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);

  pDest->VehParAdd.State[0]             = ALL_STATE_VALID;
  pDest->VehParAdd.State[1]             = ALL_STATE_VALID;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->VehParAdd.SteeringVariant      = VehParV5::VEH_PAR_ADD_STEERING_VAR_UNKNOWN;

  pDest->SensorMounting.State[0]        = ALL_STATE_VALID;
  pDest->SensorMounting.State[1]        = ALL_STATE_VALID;
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV5::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.RollAngle       = 0.0F;
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);

  pDest->Sensor.State[0]                = ALL_STATE_VALID;
  pDest->Sensor.State[1]                = ALL_STATE_VALID;
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


void CConvVehPar::ConvertToVehParV3(VehParV3::VehPar_t * const pDest, const VehParV5::VehPar_t * const pInput)
{
  pDest->uiVersionNumber              = 0;
  pDest->VehParMain.State[0]          = pInput->VehParMain.State[0];
  pDest->VehParMain.State[1]          = pInput->VehParMain.State[1];
  pDest->VehParMain.SelfSteerGrad     = ValidateValueRange(pInput->VehParMain.SelfSteerGrad, -128.f, 128.f, 0.00488692f);
  pDest->VehParMain.SteeringRatio.swa.ang[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.swa.ang[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.ang[1], 0.f, 1200.f, 1000.f);
#if (SRR_SWITCH)
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = -ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#else
  pDest->VehParMain.SteeringRatio.swa.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.swa.rat[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.swa.rat[1], 0.5f, 50.f, 17.5f);
#endif
  pDest->VehParMain.SteeringRatio.vel.vel[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[0], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.vel[1]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.vel[1], 0.f, 1200.f, 0.f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[0], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.SteeringRatio.vel.rat[0]  = ValidateValueRange(pInput->VehParMain.SteeringRatio.vel.rat[1], 0.5f, 50.f, 17.5f);
  pDest->VehParMain.WheelBase           = ValidateValueRange(pInput->VehParMain.WheelBase, 1.f, 5.f, 2.854f);
  pDest->VehParMain.TrackWidthFront     = ValidateValueRange(pInput->VehParMain.TrackWidthFront, 1.f, 3.f, 1.559f);
  pDest->VehParMain.TrackWidthRear      = ValidateValueRange(pInput->VehParMain.TrackWidthRear, 1.f, 3.f, 1.552f);
  pDest->VehParMain.VehWeight           = ValidateValueRange(pInput->VehParMain.VehWeight, 500.f, 5000.f, 1725.f);
  pDest->VehParMain.CntrOfGravHeight    = ValidateValueRange(pInput->VehParMain.CntrOfGravHeight, 0.1f, 1.5f, 0.56f);
  pDest->VehParMain.AxisLoadDistr       = ValidateValueRange(pInput->VehParMain.AxisLoadDistr, 0.1f, 0.9f, 0.52f);
  pDest->VehParMain.WhlLoadDepFrontAxle = ValidateValueRange(pInput->VehParMain.WhlLoadDepFrontAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlLoadDepRearAxle  = ValidateValueRange(pInput->VehParMain.WhlLoadDepRearAxle, 0.f, 3.f, 0.5f);
  pDest->VehParMain.WhlCircumference    = ValidateValueRange(pInput->VehParMain.WhlCircumference, 1.f, 5.f, 2.008f);
  pDest->VehParMain.DrvAxle             = ValidateValueRange<uint8>(pInput->VehParMain.DrvAxle, 0, 5, 1);
  pDest->VehParMain.WhlTcksPerRev       = ValidateValueRange<uint8>(pInput->VehParMain.WhlTcksPerRev, 10, 255, 48);
  pDest->VehParMain.FrCrnrStiff         = ValidateValueRange(pInput->VehParMain.FrCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParMain.ReCrnrStiff         = ValidateValueRange(pInput->VehParMain.ReCrnrStiff, -25.f, 25.f, 0.f);
  pDest->VehParAdd.State[0]             = ALL_STATE_VALID;
  pDest->VehParAdd.State[1]             = ALL_STATE_VALID;
  pDest->VehParAdd.VehicleWidth         = ValidateValueRange(pInput->VehParAdd.VehicleWidth, 1.f, 3.f, 2.f);
#if (SRR_SWITCH)
  pDest->VehParAdd.VehicleLength        = ValidateValueRange(pInput->VehParAdd.VehicleLength, 1.f, 10.f, 4.5f);
#endif
  pDest->VehParAdd.CurbWeight           = ValidateValueRange(pInput->VehParAdd.CurbWeight, 100.f, 65000.f, 1650.f); // NOTE: No default in XLS
  pDest->VehParAdd.OverhangFront        = ValidateValueRange(pInput->VehParAdd.OverhangFront, 0.f, 5.f, 0.6f);   // NOTE: No default in XLS
  pDest->SensorMounting.State[0]        = ALL_STATE_VALID;
  pDest->SensorMounting.State[1]        = ALL_STATE_VALID;
  pDest->SensorMounting.LatPos          = ValidateValueRange(pInput->SensorMounting.LatPos, -25.f, 25.f, 0.0f);
  pDest->SensorMounting.LongPos         = ValidateValueRange(pInput->SensorMounting.LongPos, -25.f, 25.f, 0.7f);
  pDest->SensorMounting.LongPosToCoG    = ValidateValueRange(pInput->SensorMounting.LongPosToCoG, -25.f, 25.f, 2.184f);
  pDest->SensorMounting.VertPos         = ValidateValueRange(pInput->SensorMounting.VertPos, -25.f, 25.f, 0.35f);
  pDest->SensorMounting.PitchAngle      = ValidateValueRange(pInput->SensorMounting.PitchAngle, 0.f, 40.f, 0.f);
  pDest->SensorMounting.Orientation     = ValidateValueRange<VehParV3::Orientation_t>(pInput->SensorMounting.Orientation, SENSOR_OR_NORMAL, SENSOR_OR_ROTATED, SENSOR_OR_NORMAL);
  pDest->SensorMounting.YawAngle        = ValidateValueRange(pInput->SensorMounting.YawAngle, 0.f, 40.f, 0.f);
  pDest->Sensor.State[0]                = ALL_STATE_VALID;
  pDest->Sensor.State[1]                = ALL_STATE_VALID;
  pDest->Sensor.CoverDamping            = ValidateValueRange(pInput->Sensor.CoverDamping, -25.f, 25.f, 5.f);
  pDest->Sensor.fCoverageAngle          = ValidateValueRange(pInput->Sensor.fCoverageAngle, 1.f, 90.f, 20.f);
  pDest->Sensor.fLobeAngle              = ValidateValueRange(pInput->Sensor.fLobeAngle, 0.f, 40.f, 8.f);
  pDest->Sensor.fCycleTime              = ValidateValueRange(pInput->Sensor.fCycleTime, 0.001f, 10.f, 0.066f);
  pDest->Sensor.uNoOfScans              = ValidateValueRange<uint8>(pInput->Sensor.uNoOfScans, 1u, 4u, 2u);
}


bool CConvVehPar::DecodeTPWInput(VehParV3::VehPar_t * const pVehPar, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData)
{
  bool bRet = false;
  const float DEFAULT_LONG_POS  = 0.0f;

#define SIGNAL_STATE_OK(x)    ((x) == 1u)

  // TPWinput can be decoded if the type is opaque and at least the 4 byte
  // version number is decodable
  if ((ePPortType == simOPAQUE_t) && (ulPPortSize > 4))
  {
    const uint32 tpw_version = *reinterpret_cast<const uint32*>(pPPortData);
    // Initialize default values
    InitDefaultVehParV3(pVehPar);
    // Check TPW version
    switch (tpw_version)
    {
    case 6:
      if (ulPPortSize == SUPPORTED_SIZE[CConvVehPar::TPW_INPUT_V6])
      {
        const TPW_PAR_300::TPWInput_V6_t * const pTyped = reinterpret_cast<const TPW_PAR_300::TPWInput_V6_t*>(pPPortData);
        if (SIGNAL_STATE_OK(pTyped->SignalStateTrackWidthFront))
        {
          pVehPar->VehParMain.TrackWidthFront = pTyped->TrackWidthFront;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateWheelBase))
        {
          pVehPar->VehParMain.WheelBase       = pTyped->WheelBase;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateAxleLoadDistribution))
        {
          pVehPar->VehParMain.AxisLoadDistr   = (pTyped->AxleLoadDistribution > 1)?(pTyped->AxleLoadDistribution*0.01f):(pTyped->AxleLoadDistribution);
        }
        pVehPar->SensorMounting.LongPos     = DEFAULT_LONG_POS;
        if (SIGNAL_STATE_OK(pTyped->SignalStateStatSensHorizOffset))
        {
          pVehPar->SensorMounting.LatPos      = pTyped->TPWMeasSensorPosition;
        }
        bRet = true;
      }
      else if (ulPPortSize == SUPPORTED_SIZE[CConvVehPar::TPW_INPUT_V6_350])
      {
        const TPW_PAR_300::TPWInput_V6_ARS350_t * const pTyped = reinterpret_cast<const TPW_PAR_300::TPWInput_V6_ARS350_t*>(pPPortData);
        if (SIGNAL_STATE_OK(pTyped->SignalStateTrackWidthFront))
        {
          pVehPar->VehParMain.TrackWidthFront = pTyped->TrackWidthFront;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateWheelBase))
        {
          pVehPar->VehParMain.WheelBase       = pTyped->WheelBase;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateAxleLoadDistribution))
        {
          pVehPar->VehParMain.AxisLoadDistr   = (pTyped->AxleLoadDistribution > 1)?(pTyped->AxleLoadDistribution*0.01f):(pTyped->AxleLoadDistribution);
        }
        pVehPar->SensorMounting.LongPos     = DEFAULT_LONG_POS;
        if (SIGNAL_STATE_OK(pTyped->SignalStateStatSensHorizOffset))
        {
          pVehPar->SensorMounting.LatPos      = pTyped->TPWMeasSensorPosition;
        }
        bRet = true;
      }
      else
      {
        bRet = false;
      }
      break;
    case 7:
    case 8:
      if (ulPPortSize == SUPPORTED_SIZE[CConvVehPar::TPW_INPUT_V7_8])
      {
        const TPW_PAR_300::TPWInput_8_7_t * const pTyped = reinterpret_cast<const TPW_PAR_300::TPWInput_8_7_t*>(pPPortData);
        if (SIGNAL_STATE_OK(pTyped->SignalStateTrackWidthFront))
        {
          pVehPar->VehParMain.TrackWidthFront = pTyped->TrackWidthFront;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateWheelBase))
        {
          pVehPar->VehParMain.WheelBase       = pTyped->WheelBase;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateAxleLoadDistribution))
        {
          pVehPar->VehParMain.AxisLoadDistr   = (pTyped->AxleLoadDistribution > 1)?(pTyped->AxleLoadDistribution*0.01f):(pTyped->AxleLoadDistribution);
        }
        pVehPar->SensorMounting.LongPos     = DEFAULT_LONG_POS;
        if (SIGNAL_STATE_OK(pTyped->SignalState.StatSensHorizOffset))
        {
          pVehPar->SensorMounting.LatPos      = pTyped->TPWMeasSensorPosition;
        }
        bRet = true;
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[CConvVehPar::TPW_INPUT_V7_350]) && (tpw_version == 7))
      {
        const TPW_PAR_300::TPWInput_V7_ARS350_t * const pTyped = reinterpret_cast<const TPW_PAR_300::TPWInput_V7_ARS350_t*>(pPPortData);
        if (SIGNAL_STATE_OK(pTyped->SignalStateTrackWidthFront))
        {
          pVehPar->VehParMain.TrackWidthFront = pTyped->TrackWidthFront;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateWheelBase))
        {
          pVehPar->VehParMain.WheelBase       = pTyped->WheelBase;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateAxleLoadDistribution))
        {
          pVehPar->VehParMain.AxisLoadDistr   = (pTyped->AxleLoadDistribution > 1)?(pTyped->AxleLoadDistribution*0.01f):(pTyped->AxleLoadDistribution);
        }
        pVehPar->SensorMounting.LongPos     = DEFAULT_LONG_POS;
        if (SIGNAL_STATE_OK(pTyped->SignalStateStatSensHorizOffset))
        {
          pVehPar->SensorMounting.LatPos      = pTyped->TPWMeasSensorPosition;
        }
        bRet = true;
      }
      else
      {
        bRet = false;
      }
      break;
    case 9:
      if (ulPPortSize == SUPPORTED_SIZE[CConvVehPar::TPW_INPUT_V9])
      {
        const TPW_PAR_300::TPWInput_V9_t * pTyped = reinterpret_cast<const TPW_PAR_300::TPWInput_V9_t *>(pPPortData);
        if (SIGNAL_STATE_OK(pTyped->SignalStateTrackWidthFront))
        {
          pVehPar->VehParMain.TrackWidthFront = pTyped->TrackWidthFront;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateWheelBase))
        {
          pVehPar->VehParMain.WheelBase       = pTyped->WheelBase;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateAxleLoadDistribution))
        {
          pVehPar->VehParMain.AxisLoadDistr   = (pTyped->AxleLoadDistribution > 1)?(pTyped->AxleLoadDistribution*0.01f):(pTyped->AxleLoadDistribution);
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateSensorMountOffsetLong))
        {
          pVehPar->SensorMounting.LongPos     = pTyped->SensorMountOffsetLong;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalState.StatSensHorizOffset))
        {
          pVehPar->SensorMounting.LatPos      = pTyped->TPWMeasSensorPosition;
        }
        bRet = true;
      }
      else
      {
        bRet = false;
      }
      break;
    case 10:
      if ((ulPPortSize == SUPPORTED_SIZE[CConvVehPar::TPW_INPUT_V10]) || (ulPPortSize == SUPPORTED_SIZE[CConvVehPar::TPW_INPUT_V10_253byte]))
      {
        const TPW_PAR_300::TPWInput_V10_t * pTyped = reinterpret_cast<const TPW_PAR_300::TPWInput_V10_t *>(pPPortData);
        if (SIGNAL_STATE_OK(pTyped->SignalStateTrackWidthFront))
        {
          pVehPar->VehParMain.TrackWidthFront = pTyped->TrackWidthFront;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateWheelBase))
        {
          pVehPar->VehParMain.WheelBase       = pTyped->WheelBase;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateAxleLoadDistribution))
        {
          pVehPar->VehParMain.AxisLoadDistr   = (pTyped->AxleLoadDistribution > 1)?(pTyped->AxleLoadDistribution*0.01f):(pTyped->AxleLoadDistribution);
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateSensorMountOffsetLong))
        {
          pVehPar->SensorMounting.LongPos     = pTyped->SensorMountOffsetLong;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalState.StatSensHorizOffset))
        {
          pVehPar->SensorMounting.LatPos      = pTyped->TPWMeasSensorPosition;
        }
        bRet = true;
      }
      else
      {
        bRet = false;
      }
      break;
    case 11:
      if (ulPPortSize == SUPPORTED_SIZE[CConvVehPar::TPW_INPUT_V11])
      {
        const TPW_PAR_300::TPWInput_V11_t * pTyped = reinterpret_cast<const TPW_PAR_300::TPWInput_V11_t *>(pPPortData);
        if (SIGNAL_STATE_OK(pTyped->SignalStateTrackWidthFront))
        {
          pVehPar->VehParMain.TrackWidthFront = pTyped->TrackWidthFront;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateWheelBase))
        {
          pVehPar->VehParMain.WheelBase       = pTyped->WheelBase;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateAxleLoadDistribution))
        {
          pVehPar->VehParMain.AxisLoadDistr   = (pTyped->AxleLoadDistribution > 1)?(pTyped->AxleLoadDistribution*0.01f):(pTyped->AxleLoadDistribution);
        }
        if (SIGNAL_STATE_OK(pTyped->SignalStateSensorMountOffsetLong))
        {
          pVehPar->SensorMounting.LongPos     = pTyped->SensorMountOffsetLong;
        }
        if (SIGNAL_STATE_OK(pTyped->SignalState.StatSensHorizOffset))
        {
          pVehPar->SensorMounting.LatPos      = pTyped->TPWMeasSensorPosition;
        }
        bRet = true;
      }
      else
      {
        bRet = false;
      }
      break;
    default:
      bRet = false;
      break;
    }
  }
  else
  {
    bRet = false;
  }
  return bRet;
}


bool CConvVehPar::DecodeRSPInputVDATA(VehParV3::VehPar_t * const pVehPar, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData)
{
  bool bRet = false;

  // RSPInputVDATA can be decoded if the type is opaque and at least the 4 byte
  // version number is decodable
  if ((ePPortType == simOPAQUE_t) && (ulPPortSize > 4))
  {
    const uint32 intf_version = *reinterpret_cast<const uint32*>(pPPortData);
    // Initialize default values
    InitDefaultVehParV3(pVehPar);

    if (intf_version == 2u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV2] )
    {
      RSP_PAR_300::RSPInputVData_t_IV2* pTyped = (RSP_PAR_300::RSPInputVData_t_IV2*) pPPortData;
      pVehPar->uiVersionNumber            = pTyped->InterfaceVersion;
      pVehPar->Sensor.CoverDamping        = pTyped->CovDamping;
      pVehPar->SensorMounting.Orientation = (unsigned char) pTyped->SensorGeometry.Rotated;
      pVehPar->SensorMounting.LatPos      = pTyped->SensorGeometry.Offset;
      pVehPar->SensorMounting.VertPos     = pTyped->SensorGeometry.Height;
      bRet = true;
    }
    else if (intf_version == 3u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV3] )
    {
      RSP_PAR_300::RSPInputVData_t_IV3* pTyped = (RSP_PAR_300::RSPInputVData_t_IV3*) pPPortData;
      pVehPar->uiVersionNumber            = pTyped->InterfaceVersion;
      pVehPar->Sensor.CoverDamping        = pTyped->CovDamping;
      pVehPar->SensorMounting.Orientation = (unsigned char) pTyped->SensorGeometry.Rotated;
      pVehPar->SensorMounting.LatPos      = pTyped->SensorGeometry.Offset;
      pVehPar->SensorMounting.VertPos     = pTyped->SensorGeometry.Height;
      bRet = true;
    }
    else if (intf_version == 4u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV4] )
    {
      RSP_PAR_300::RSPInputVData_t_IV4* pTyped = (RSP_PAR_300::RSPInputVData_t_IV4*) pPPortData;
      pVehPar->uiVersionNumber            = pTyped->InterfaceVersion;
      pVehPar->Sensor.CoverDamping        = pTyped->CovDamping;
      pVehPar->SensorMounting.Orientation = (unsigned char) pTyped->SensorGeometry.Rotated;
      pVehPar->SensorMounting.LatPos      = pTyped->SensorGeometry.Offset;
      pVehPar->SensorMounting.VertPos     = pTyped->SensorGeometry.Height;
      bRet = true;
    }
    else if (intf_version == 5u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV5] )
    {
      RSP_PAR_300::RSPInputVData_t_IV5* pTyped = (RSP_PAR_300::RSPInputVData_t_IV5*) pPPortData;
      pVehPar->uiVersionNumber            = pTyped->InterfaceVersion;
      pVehPar->Sensor.CoverDamping        = pTyped->CovDamping;
      pVehPar->SensorMounting.Orientation = (unsigned char) pTyped->SensorGeometry.Rotated;
      pVehPar->SensorMounting.LatPos      = pTyped->SensorGeometry.Offset;
      pVehPar->SensorMounting.VertPos     = pTyped->SensorGeometry.Height;
      bRet = true;
    }
    else if (intf_version == 6u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV6] )
    {
      RSP_PAR_300::RSPInputVData_t_IV6* pTyped = (RSP_PAR_300::RSPInputVData_t_IV6*) pPPortData;
      pVehPar->uiVersionNumber            = pTyped->InterfaceVersion;
      pVehPar->Sensor.CoverDamping        = pTyped->CovDamping;
      pVehPar->SensorMounting.Orientation = (unsigned char) pTyped->SensorGeometry.Rotated;
      pVehPar->SensorMounting.LatPos      = pTyped->SensorGeometry.Offset;
      pVehPar->SensorMounting.VertPos     = pTyped->SensorGeometry.Height;
      bRet = true;
    }
    else if (intf_version == 7u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV7] )
    {
      RSP_PAR_300::RSPInputVData_t_IV7* pTyped = (RSP_PAR_300::RSPInputVData_t_IV7*) pPPortData;
      pVehPar->uiVersionNumber            = pTyped->InterfaceVersion;
      pVehPar->Sensor.CoverDamping        = pTyped->CovDamping;
      pVehPar->SensorMounting.Orientation = (unsigned char) pTyped->SensorGeometry.Rotated;
      pVehPar->SensorMounting.LatPos      = pTyped->SensorGeometry.Offset;
      pVehPar->SensorMounting.VertPos     = pTyped->SensorGeometry.Height;
      bRet = true;
    }
    else if (intf_version == 8u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV8] )
    {
      RSP_PAR_300::RSPInputVData_t_IV8* pTyped = (RSP_PAR_300::RSPInputVData_t_IV8*) pPPortData;
      pVehPar->uiVersionNumber            = pTyped->InterfaceVersion;
      pVehPar->Sensor.CoverDamping        = pTyped->CovDamping;
      pVehPar->SensorMounting.Orientation = (unsigned char) pTyped->SensorGeometry.Rotated;
      pVehPar->SensorMounting.LatPos      = pTyped->SensorGeometry.Offset;
      pVehPar->SensorMounting.VertPos     = pTyped->SensorGeometry.Height;
      bRet = true;
    }
    else if ( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IVL] )
    {
      RSP_PAR_300::RSPInputVData_t_IVL* pTyped = (RSP_PAR_300::RSPInputVData_t_IVL*) pPPortData;
      pVehPar->uiVersionNumber            = pTyped->InterfaceVersion;
      pVehPar->Sensor.CoverDamping        = pTyped->VData.CovDamping;
      pVehPar->SensorMounting.Orientation = (unsigned char) pTyped->VData.SensorGeometry.Rotated;
      pVehPar->SensorMounting.LatPos      = pTyped->VData.SensorGeometry.Offset;
      pVehPar->SensorMounting.VertPos     = pTyped->VData.SensorGeometry.Height;
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


bool CConvVehPar::DecodeVDYInput(VehParV3::VehPar_t * const pVehPar, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData)
{
  bool bRet = false;

  // VDYinput can be decoded if the type is opaque and at least the 4 byte
  // version number is decodable
  if ((ePPortType == simOPAQUE_t) && (ulPPortSize > 4))
  {
//    const uint32 vdy_version = *reinterpret_cast<const uint32*>(pPPortData);
    // Initialize default values
    InitDefaultVehParV3(pVehPar);

    if (ulPPortSize == SUPPORTED_SIZE_VDY_INPUT[CConvVehPar::VDY_IN_V1])
    {
      const VDY_PAR_300::VDYInputData_v1_t * const pType = reinterpret_cast<const VDY_PAR_300::VDYInputData_v1_t *>(pPPortData);
      const VDY_PAR_300::VDYInputPara_t * const pPVehPar = &pType->Parameter;

      pVehPar->VehParMain.SelfSteerGrad         = pPVehPar->SelfSteerGrad;
      memcpy_s(pVehPar->VehParMain.SteeringRatio.swa.ang, sizeof(pVehPar->VehParMain.SteeringRatio.swa.ang), pPVehPar->SteeringRatio.swa.ang, sizeof(pVehPar->VehParMain.SteeringRatio.swa.ang));
      memcpy_s(pVehPar->VehParMain.SteeringRatio.swa.rat, sizeof(pVehPar->VehParMain.SteeringRatio.swa.rat), pPVehPar->SteeringRatio.swa.rat, sizeof(pVehPar->VehParMain.SteeringRatio.swa.rat));
      pVehPar->VehParMain.WheelBase            = pPVehPar->WheelBase;
      pVehPar->VehParMain.TrackWidthFront      = pPVehPar->TrackWidthFront;
      pVehPar->VehParMain.TrackWidthRear       = pPVehPar->TrackWidthRear;
      pVehPar->VehParMain.VehWeight            = pPVehPar->VehWeight;
      pVehPar->VehParMain.CntrOfGravHeight     = pPVehPar->CntrOfGravHeight;
      pVehPar->VehParMain.AxisLoadDistr        = pPVehPar->AxisLoadDistr;
      pVehPar->VehParMain.WhlLoadDepFrontAxle  = pPVehPar->WhlLoadDepFrontAxle;
      pVehPar->VehParMain.WhlLoadDepRearAxle   = pPVehPar->WhlLoadDepRearAxle;
      pVehPar->VehParMain.WhlCircumference     = pPVehPar->WhlCircumference;
      pVehPar->VehParMain.DrvAxle              = pPVehPar->DrvAxle;
      pVehPar->VehParMain.WhlTcksPerRev        = pPVehPar->WhlTcksPerRev;
      pVehPar->VehParMain.FrCrnrStiff          = pPVehPar->FrCrnrStiff;
      pVehPar->VehParMain.ReCrnrStiff          = pPVehPar->ReCrnrStiff;

      memcpy_s(pVehPar->VehParMain.State, sizeof(pVehPar->VehParMain.State), &pPVehPar->State, sizeof(pVehPar->VehParMain.State));

      bRet = true;
    }
    else if (ulPPortSize == SUPPORTED_SIZE_VDY_INPUT[CConvVehPar::VDY_IN_V2])
    {
      const VDY_PAR_300::VDYInputData_v2_t * const pType = reinterpret_cast<const VDY_PAR_300::VDYInputData_v2_t *>(pPPortData);
      const VDY_PAR_300::VDYInputPara_t * const pPVehPar = &pType->Parameter;

      pVehPar->VehParMain.SelfSteerGrad         = pPVehPar->SelfSteerGrad;
      memcpy_s(pVehPar->VehParMain.SteeringRatio.swa.ang, sizeof(pVehPar->VehParMain.SteeringRatio.swa.ang), pPVehPar->SteeringRatio.swa.ang, sizeof(pVehPar->VehParMain.SteeringRatio.swa.ang));
      memcpy_s(pVehPar->VehParMain.SteeringRatio.swa.rat, sizeof(pVehPar->VehParMain.SteeringRatio.swa.rat), pPVehPar->SteeringRatio.swa.rat, sizeof(pVehPar->VehParMain.SteeringRatio.swa.rat));
      pVehPar->VehParMain.WheelBase            = pPVehPar->WheelBase;
      pVehPar->VehParMain.TrackWidthFront      = pPVehPar->TrackWidthFront;
      pVehPar->VehParMain.TrackWidthRear       = pPVehPar->TrackWidthRear;
      pVehPar->VehParMain.VehWeight            = pPVehPar->VehWeight;
      pVehPar->VehParMain.CntrOfGravHeight     = pPVehPar->CntrOfGravHeight;
      pVehPar->VehParMain.AxisLoadDistr        = pPVehPar->AxisLoadDistr;
      pVehPar->VehParMain.WhlLoadDepFrontAxle  = pPVehPar->WhlLoadDepFrontAxle;
      pVehPar->VehParMain.WhlLoadDepRearAxle   = pPVehPar->WhlLoadDepRearAxle;
      pVehPar->VehParMain.WhlCircumference     = pPVehPar->WhlCircumference;
      pVehPar->VehParMain.DrvAxle              = pPVehPar->DrvAxle;
      pVehPar->VehParMain.WhlTcksPerRev        = pPVehPar->WhlTcksPerRev;
      pVehPar->VehParMain.FrCrnrStiff          = pPVehPar->FrCrnrStiff;
      pVehPar->VehParMain.ReCrnrStiff          = pPVehPar->ReCrnrStiff;

      memcpy_s(pVehPar->VehParMain.State, sizeof(pVehPar->VehParMain.State), &pPVehPar->State, sizeof(pVehPar->VehParMain.State));

      bRet = true;
    }
    else if (ulPPortSize == SUPPORTED_SIZE_VDY_INPUT[CConvVehPar::VDY_IN_V3])
    {
      const VDY_PAR_300::VDYInputData_v3_t * const pType = reinterpret_cast<const VDY_PAR_300::VDYInputData_v3_t *>(pPPortData);
      const VDY_PAR_300::VDYInputPara_t * const pPVehPar = &pType->Parameter;

      pVehPar->VehParMain.SelfSteerGrad         = pPVehPar->SelfSteerGrad;
      memcpy_s(pVehPar->VehParMain.SteeringRatio.swa.ang, sizeof(pVehPar->VehParMain.SteeringRatio.swa.ang), pPVehPar->SteeringRatio.swa.ang, sizeof(pVehPar->VehParMain.SteeringRatio.swa.ang));
      memcpy_s(pVehPar->VehParMain.SteeringRatio.swa.rat, sizeof(pVehPar->VehParMain.SteeringRatio.swa.rat), pPVehPar->SteeringRatio.swa.rat, sizeof(pVehPar->VehParMain.SteeringRatio.swa.rat));
      pVehPar->VehParMain.WheelBase            = pPVehPar->WheelBase;
      pVehPar->VehParMain.TrackWidthFront      = pPVehPar->TrackWidthFront;
      pVehPar->VehParMain.TrackWidthRear       = pPVehPar->TrackWidthRear;
      pVehPar->VehParMain.VehWeight            = pPVehPar->VehWeight;
      pVehPar->VehParMain.CntrOfGravHeight     = pPVehPar->CntrOfGravHeight;
      pVehPar->VehParMain.AxisLoadDistr        = pPVehPar->AxisLoadDistr;
      pVehPar->VehParMain.WhlLoadDepFrontAxle  = pPVehPar->WhlLoadDepFrontAxle;
      pVehPar->VehParMain.WhlLoadDepRearAxle   = pPVehPar->WhlLoadDepRearAxle;
      pVehPar->VehParMain.WhlCircumference     = pPVehPar->WhlCircumference;
      pVehPar->VehParMain.DrvAxle              = pPVehPar->DrvAxle;
      pVehPar->VehParMain.WhlTcksPerRev        = pPVehPar->WhlTcksPerRev;
      pVehPar->VehParMain.FrCrnrStiff          = pPVehPar->FrCrnrStiff;
      pVehPar->VehParMain.ReCrnrStiff          = pPVehPar->ReCrnrStiff;

      memcpy_s(pVehPar->VehParMain.State, sizeof(pVehPar->VehParMain.State), &pPVehPar->State, sizeof(pVehPar->VehParMain.State));

      bRet = true;
    }
    else if (ulPPortSize == SUPPORTED_SIZE_VDY_INPUT[CConvVehPar::VDY_IN_V4])
    {
      const VDY_PAR_300::VDYInputData_v4_t * const pType = reinterpret_cast<const VDY_PAR_300::VDYInputData_v4_t *>(pPPortData);
      const VDY_PAR_300::VDYInputPara_v2_t * const pPVehPar = &pType->Parameter;

      pVehPar->VehParMain.SelfSteerGrad         = pPVehPar->SelfSteerGrad;
      memcpy_s(pVehPar->VehParMain.SteeringRatio.swa.ang, sizeof(pVehPar->VehParMain.SteeringRatio.swa.ang), pPVehPar->SteeringRatio.swa.ang, sizeof(pVehPar->VehParMain.SteeringRatio.swa.ang));
      memcpy_s(pVehPar->VehParMain.SteeringRatio.swa.rat, sizeof(pVehPar->VehParMain.SteeringRatio.swa.rat), pPVehPar->SteeringRatio.swa.rat, sizeof(pVehPar->VehParMain.SteeringRatio.swa.rat));
      pVehPar->VehParMain.WheelBase            = pPVehPar->WheelBase;
      pVehPar->VehParMain.TrackWidthFront      = pPVehPar->TrackWidthFront;
      pVehPar->VehParMain.TrackWidthRear       = pPVehPar->TrackWidthRear;
      pVehPar->VehParMain.VehWeight            = pPVehPar->VehWeight;
      pVehPar->VehParMain.CntrOfGravHeight     = pPVehPar->CntrOfGravHeight;
      pVehPar->VehParMain.AxisLoadDistr        = pPVehPar->AxisLoadDistr;
      pVehPar->VehParMain.WhlLoadDepFrontAxle  = pPVehPar->WhlLoadDepFrontAxle;
      pVehPar->VehParMain.WhlLoadDepRearAxle   = pPVehPar->WhlLoadDepRearAxle;
      pVehPar->VehParMain.WhlCircumference     = pPVehPar->WhlCircumference;
      pVehPar->VehParMain.DrvAxle              = pPVehPar->DrvAxle;
      pVehPar->VehParMain.WhlTcksPerRev        = pPVehPar->WhlTcksPerRev;
      pVehPar->VehParMain.FrCrnrStiff          = pPVehPar->FrCrnrStiff;
      pVehPar->VehParMain.ReCrnrStiff          = pPVehPar->ReCrnrStiff;

      memcpy_s(pVehPar->VehParMain.State, sizeof(pVehPar->VehParMain.State), &pPVehPar->State, sizeof(pVehPar->VehParMain.State));

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


bool CConvVehPar::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * const pPortVersionInfo) const
{
  bool bRet = false;
  unsigned int i;
  // VehPar_t to VehPar_t conversion
  for (i=0;(i<CConvVehPar::VEHPAR_INPUT_VERSION_COUNT) && (!bRet);i++)
  {
    if ((ePortType == simOPAQUE_t) && (ulPortSize == VEHPAR_SUPPORTED_SIZE[i]))
    {
      // Check if version information is compatible - with extra care for simulators that
      // do not set the version number at all...
      if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(VEHPAR_VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
      {
        bRet = true;
      }
    }
  }
  /* get ehPar from the tpw input */
  for (unsigned int i =0; (i<CConvVehPar::TPW_INPUT_VERSION_COUNT) && (!bRet);i++)
  {
    bRet |= (ulPortSize == SUPPORTED_SIZE[i]);
  }
  /* get VehPar from RSPInputVDATA */
  for (unsigned int i =0; (i<CConvVehPar::RSP_INPUT_VDATA_VER_COUNT) && (!bRet);i++)
  {
    bRet |= (ulPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[i]);
  }
  /* get VehPar from the VdyInput */
  for (unsigned int i =0; (i<CConvVehPar::VDY_IN_VER_COUNT) && (!bRet);i++)
  {
    bRet |= (ulPortSize == SUPPORTED_SIZE_VDY_INPUT[i]);
  }
  return bRet;
}


uint32 CConvVehPar::GetDepVersion(void)
{
  /* Get the version via the dependency */
  uint32 DepVersion = 0xFFFFFFFF;
  DepInfo* pVersion = NULL;
  for (int i = VDY_VERSION; i < DEP_COUNT; i++)
  {
    pVersion = GetDependencyInfo(i);
    if ((pVersion != NULL) && (pVersion->m_pDepData != NULL))
    {
      break;
    }
  }

  if ((pVersion == NULL) || (pVersion->m_pDepData == NULL))
  {
    return DepVersion;
  }
  else
  {
    if (pVersion->m_ssDepName == _T("VDYVersion"))
    {
      unsigned int * VDYVersion = reinterpret_cast<unsigned int *>(pVersion->m_pDepData);
      if ((*VDYVersion >= 0x00030000) && (*VDYVersion < 0x00030100))
      {
        DepVersion = 0x1;
      }
      else if ((*VDYVersion >= 0x00030100) && (*VDYVersion < 0x00030105))
      {
        DepVersion = 0x2;
      }
    }
    if (pVersion->m_ssDepName == _T("RSPVersion"))
    {
      unsigned int * RSPVersion = reinterpret_cast<unsigned int *>(pVersion->m_pDepData);
      if ((*RSPVersion >= 0x00020000) && (*RSPVersion < 0x00040000))
      {
        DepVersion = 0x1;
      }
      else if ((*RSPVersion >= 0x00040000) && (*RSPVersion < 0x00030105))
      {
        DepVersion = 0x2;
      }
    }
    if (pVersion->m_ssDepName == _T("ALNVersion"))
    {
      unsigned int * ALNVersion = reinterpret_cast<unsigned int *>(pVersion->m_pDepData);

      if (*ALNVersion < 80000)
      {
        DepVersion = 0x2;
      }
    }
    if (pVersion->m_ssDepName == _T("EMVersion"))
    {
      unsigned int * EMVersion = reinterpret_cast<unsigned int *>(pVersion->m_pDepData);
      if ((*EMVersion >= 0x04000000) && (*EMVersion < 0x04010300))
      {
        DepVersion = 0x1;
      }
      else if ((*EMVersion >= 0x04010300) && (*EMVersion < 0x04010800))
      {
        DepVersion = 0x2;
      }
    }
    if (pVersion->m_ssDepName == _T("FCTVersion"))
    {
      unsigned int FCTVersion = 0;

      if (pVersion->m_pDepData != NULL)
      {
        FCTVersion = *reinterpret_cast<unsigned int *>(pVersion->m_pDepData);
        // Corresponds to 01.19.00
        if (FCTVersion >= 0x011300)
        {
          DepVersion = 3;
        }
        // Corresponds to 01.17.00
        else if (FCTVersion >= 0x011100)
        {
          DepVersion = 2;
        }
        else
        {
          DepVersion = 1;
        }
      }
      else
      {
        // No depversion set by simulator - assume newest
        DepVersion = 3;
      }
    }
  }

  return DepVersion;
}


long CConvVehPar::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo,
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
{
  long lRet;
  /* Get the version via the dependency */
  uint32 DepVersion = GetDepVersion();

  if ( ( ((ePPortType == simOPAQUE_t) && (ulPPortSize > 4)) || (ePPortType == simREFERENCE_t) ) && (pPPortData != NULL))
  {
    const uint32 version = *reinterpret_cast<const uint32*>(pPPortData);
    CVersionInfoImpl ProvidePortVersionInfo(CONV_I32VERSION_TO_TUPPLE(version));
    CVersionInfoImpl ProvidePortVersionInfoDep(CONV_I32VERSION_TO_TUPPLE(DepVersion));

    if ( (DepVersion != 0xFFFFFFFF) && (version == 0U) )
    {
      ProvidePortVersionInfo = ProvidePortVersionInfoDep;
    }

    // If sizes and versions match, then just take data
    if (   (ePPortType == eRPortType)
        && (ulPPortSize == ulRPortSize)
        && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo)))
        && (ProvidePortVersionInfo.Equals(&requestPortVersionInfo))
       )
    {
      // Port types sizes and versions match, we can directly use the input data
      *pOutData = pPPortData;
      ulOutSize = ulPPortSize;
      lRet = SIM_ERR_OK;
    }
    else
    {
      // Some conversion is needed, first level branching based on request port size/version
      // check if destination is V9 version.
      if (    (ulRPortSize == sizeof(m_VehParV9))
           && (requestPortVersionInfo.Equals(&VEH_PAR_V9_VERINFO))   )
      {
        if ((ulPPortSize == sizeof(m_VehParV9)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V9_VERINFO))))
        {
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        //V19 equal to V9
        else if ((ulPPortSize == sizeof(m_VehParV9)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V19_VERINFO))))
        {
          ConvertToVehParV9(&m_VehParV9, reinterpret_cast<const VehParV9::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV9;
          ulOutSize = sizeof(m_VehParV9);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV8)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V8_VERINFO))))
        {
          ConvertToVehParV9(&m_VehParV9, reinterpret_cast<const VehParV8::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV9;
          ulOutSize = sizeof(m_VehParV9);
          lRet = SIM_ERR_OK;
        }

        else if ((ulPPortSize == sizeof(m_VehParV7)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V7_VERINFO))))
        {
          ConvertToVehParV8(&m_VehParV8, reinterpret_cast<const VehParV7::VehPar_t*>(pPPortData));
          ConvertToVehParV9(&m_VehParV9, &m_VehParV8);
          *pOutData = &m_VehParV9;
          ulOutSize = sizeof(m_VehParV9);
          lRet = SIM_ERR_OK;
        }

        else if ((ulPPortSize == sizeof(m_VehParV6)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V6_VERINFO))))
        {
          ConvertToVehParV7(&m_VehParV7, reinterpret_cast<const VehParV6::VehPar_t*>(pPPortData));
          ConvertToVehParV8(&m_VehParV8, &m_VehParV7);
          ConvertToVehParV9(&m_VehParV9, &m_VehParV8);
          *pOutData = &m_VehParV9;
          ulOutSize = sizeof(m_VehParV9);
          lRet = SIM_ERR_OK;
        }

        else if ((ulPPortSize == sizeof(m_VehParV6A)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V6_VERINFO))))
        {
          ConvertToVehParV7(&m_VehParV7, reinterpret_cast<const VehParV6A::VehPar_t*>(pPPortData));
          ConvertToVehParV8(&m_VehParV8, &m_VehParV7);
          ConvertToVehParV9(&m_VehParV9, &m_VehParV8);
          *pOutData = &m_VehParV9;
          ulOutSize = sizeof(m_VehParV9);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV5)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V5_VERINFO))))
        {
          ConvertToVehParV6(&m_VehParV6, reinterpret_cast<const VehParV5::VehPar_t*>(pPPortData));
          ConvertToVehParV7(&m_VehParV7, &m_VehParV6);
          ConvertToVehParV8(&m_VehParV8, &m_VehParV7);
          ConvertToVehParV9(&m_VehParV9, &m_VehParV8);
          *pOutData = &m_VehParV9;
          ulOutSize = sizeof(m_VehParV9);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV3)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V3_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V4_VERINFO))) &&
          ((ProvidePortVersionInfo.Equals(&VEH_PAR_V3_VERINFO)) || (ProvidePortVersionInfo.Equals(&VEH_PAR_V4_VERINFO)) || (ProvidePortVersionInfo.Equals(&BASE_VERSION))))
        {
          ConvertToVehParV5(&m_VehParV5, reinterpret_cast<const VehParV3::VehPar_t*>(pPPortData));
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          ConvertToVehParV7(&m_VehParV7, &m_VehParV6);
          ConvertToVehParV8(&m_VehParV8, &m_VehParV7);
          ConvertToVehParV9(&m_VehParV9, &m_VehParV8);
          *pOutData = &m_VehParV9;
          ulOutSize = sizeof(m_VehParV9);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV2)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V2_VERINFO))) && (ProvidePortVersionInfo.Equals(&VEH_PAR_V2_VERINFO)))
        {
          ConvertToVehParV3(&m_VehParV3, reinterpret_cast<const VehParV2::VehPar_t*>(pPPortData));
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          ConvertToVehParV7(&m_VehParV7, &m_VehParV6);
          ConvertToVehParV8(&m_VehParV8, &m_VehParV7);
          ConvertToVehParV9(&m_VehParV9, &m_VehParV8);
          *pOutData = &m_VehParV9;
          ulOutSize = sizeof(m_VehParV9);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV1)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V1_VERINFO))) && (ProvidePortVersionInfo.Equals(&VEH_PAR_V1_VERINFO)))
        {
          ConvertToVehParV3(&m_VehParV3, reinterpret_cast<const VehParV1::VehPar_t*>(pPPortData));
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          ConvertToVehParV7(&m_VehParV7, &m_VehParV6);
          ConvertToVehParV8(&m_VehParV8, &m_VehParV7);
          ConvertToVehParV9(&m_VehParV9, &m_VehParV8);
          *pOutData = &m_VehParV9;
          ulOutSize = sizeof(m_VehParV9);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV0)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V0_VERINFO))) && (ProvidePortVersionInfo.Equals(&VEH_PAR_V0_VERINFO)))
        {
          ConvertToVehParV3(&m_VehParV3, reinterpret_cast<const VehParV0::VehPar_t*>(pPPortData));
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          ConvertToVehParV7(&m_VehParV7, &m_VehParV6);
          ConvertToVehParV8(&m_VehParV8, &m_VehParV7);
          ConvertToVehParV9(&m_VehParV9, &m_VehParV8);
          *pOutData = &m_VehParV9;
          ulOutSize = sizeof(m_VehParV9);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_NO_CONVERSION;
        }
      }

      // Check if destination is V8 version. 
      else if (    (ulRPortSize == sizeof(m_VehParV8))
           && (requestPortVersionInfo.Equals(&VEH_PAR_V8_VERINFO))   )
      {
        if ((ulPPortSize == sizeof(m_VehParV8)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V8_VERINFO))))
        {
          // Provide port sizes match and versions are either VEH_PAR_V8_VERINFO or VEH_PAR_V9_VERINFO, which are identical
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV9)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V9_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V9_VERINFO))))
        {
          ConvertToVehParV8(&m_VehParV8, reinterpret_cast<const VehParV9::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV8;
          ulOutSize = sizeof(m_VehParV8);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV7)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V7_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V7_VERINFO))))
        {
          ConvertToVehParV8(&m_VehParV8, reinterpret_cast<const VehParV7::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV8;
          ulOutSize = sizeof(m_VehParV8);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      // Check if destination is V7 version. 
      else if ((ulRPortSize == sizeof(m_VehParV7)) &&
        (requestPortVersionInfo.Equals(&VEH_PAR_V7_VERINFO)))
      {
        if ((ulPPortSize == sizeof(m_VehParV8)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V8_VERINFO))))
        {
          // Provide port sizes match and versions are VEH_PAR_V8_VERINFO
          // Forward the data directly:
          ConvertToVehParV7(&m_VehParV7, reinterpret_cast<const VehParV8::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV7;
          ulOutSize = sizeof(m_VehParV7);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV7)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V7_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V7_VERINFO))))
        {
          // Provide port sizes match and versions are VEH_PAR_V7_VERINFO
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV6)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V6_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V6_VERINFO))))
        {
          ConvertToVehParV7(&m_VehParV7, reinterpret_cast<const VehParV6::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV7;
          ulOutSize = sizeof(m_VehParV7);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV6A)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V6_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V6_VERINFO))))
        {
          ConvertToVehParV7(&m_VehParV7, reinterpret_cast<const VehParV6A::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV7;
          ulOutSize = sizeof(m_VehParV7);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV5)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V5_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V5_VERINFO))))
        {
          ConvertToVehParV6(&m_VehParV6, reinterpret_cast<const VehParV5::VehPar_t*>(pPPortData));
          ConvertToVehParV7(&m_VehParV7, &m_VehParV6);
          *pOutData = &m_VehParV7;
          ulOutSize = sizeof(m_VehParV7);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV3)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V3_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V4_VERINFO))) &&
          ((ProvidePortVersionInfo.Equals(&VEH_PAR_V3_VERINFO)) || (ProvidePortVersionInfo.Equals(&VEH_PAR_V4_VERINFO)) || (ProvidePortVersionInfo.Equals(&BASE_VERSION))))
        {
          ConvertToVehParV5(&m_VehParV5, reinterpret_cast<const VehParV3::VehPar_t*>(pPPortData));
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          ConvertToVehParV7(&m_VehParV7, &m_VehParV6);
          *pOutData = &m_VehParV7;
          ulOutSize = sizeof(m_VehParV7);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV2)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V2_VERINFO))) && (ProvidePortVersionInfo.Equals(&VEH_PAR_V2_VERINFO)))
        {
          ConvertToVehParV3(&m_VehParV3, reinterpret_cast<const VehParV2::VehPar_t*>(pPPortData));
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          ConvertToVehParV7(&m_VehParV7, &m_VehParV6);
          *pOutData = &m_VehParV7;
          ulOutSize = sizeof(m_VehParV7);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV1)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V1_VERINFO))) && (ProvidePortVersionInfo.Equals(&VEH_PAR_V1_VERINFO)))
        {
          ConvertToVehParV2(&m_VehParV2, reinterpret_cast<const VehParV1::VehPar_t*>(pPPortData));
          ConvertToVehParV3(&m_VehParV3, &m_VehParV2);
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          ConvertToVehParV7(&m_VehParV7, &m_VehParV6);
          *pOutData = &m_VehParV7;
          ulOutSize = sizeof(m_VehParV7);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV0)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V0_VERINFO))) && (ProvidePortVersionInfo.Equals(&VEH_PAR_V0_VERINFO)))
        {
          ConvertToVehParV1(&m_VehParV1, reinterpret_cast<const VehParV0::VehPar_t*>(pPPortData));
          ConvertToVehParV2(&m_VehParV2, &m_VehParV1);
          ConvertToVehParV3(&m_VehParV3, &m_VehParV2);
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          ConvertToVehParV7(&m_VehParV7, &m_VehParV6);
          *pOutData = &m_VehParV7;
          ulOutSize = sizeof(m_VehParV7);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      // Some conversion is needed, first level branching based on request port size/version
      // Check if destination is V6 version. 
      else if (    (ulRPortSize == sizeof(m_VehParV6))
           && ((requestPortVersionInfo.Equals(&VEH_PAR_V6_VERINFO)) || (requestPortVersionInfo.Equals(&VEH_PAR_V7_VERINFO)))  ) 
      {
        if (   (ulPPortSize == sizeof(m_VehParV6))
            && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V6_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V6_VERINFO)))  )
        {
          // Provide port sizes match and versions are VEH_PAR_V6_VERINFO
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV5))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V5_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V5_VERINFO)))  )
        {
          ConvertToVehParV6(&m_VehParV6, reinterpret_cast<const VehParV5::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV6;
          ulOutSize = sizeof(m_VehParV6);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV3))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V3_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V4_VERINFO)))
                  && ((ProvidePortVersionInfo.Equals(&VEH_PAR_V3_VERINFO)) || (ProvidePortVersionInfo.Equals(&VEH_PAR_V4_VERINFO)) || (ProvidePortVersionInfo.Equals(&BASE_VERSION)))  )
        {
          ConvertToVehParV5(&m_VehParV5, reinterpret_cast<const VehParV3::VehPar_t*>(pPPortData));
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          *pOutData = &m_VehParV6;
          ulOutSize = sizeof(m_VehParV6);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV2))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V2_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V2_VERINFO))  )
        {
          ConvertToVehParV3(&m_VehParV3, reinterpret_cast<const VehParV2::VehPar_t*>(pPPortData));
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          *pOutData = &m_VehParV6;
          ulOutSize = sizeof(m_VehParV6);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV1))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V1_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V1_VERINFO))  )
        {
          ConvertToVehParV2(&m_VehParV2, reinterpret_cast<const VehParV1::VehPar_t*>(pPPortData));
          ConvertToVehParV3(&m_VehParV3, &m_VehParV2);
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          *pOutData = &m_VehParV6;
          ulOutSize = sizeof(m_VehParV6);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV0))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V0_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V0_VERINFO))  )
        {
          ConvertToVehParV1(&m_VehParV1, reinterpret_cast<const VehParV0::VehPar_t*>(pPPortData));
          ConvertToVehParV2(&m_VehParV2, &m_VehParV1);
          ConvertToVehParV3(&m_VehParV3, &m_VehParV2);
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          ConvertToVehParV6(&m_VehParV6, &m_VehParV5);
          *pOutData = &m_VehParV6;
          ulOutSize = sizeof(m_VehParV6);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      // Some conversion is needed, first level branching based on request port size/version
      // Check if destination is V5 version. 
      else if ( (ulRPortSize == sizeof(m_VehParV5)) && (requestPortVersionInfo.Equals(&VEH_PAR_V5_VERINFO)) )
      {
        if (    (ulPPortSize == sizeof(m_VehParV5))
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V5_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V5_VERINFO)))  )
        {
          // Provide port sizes match and versions are VEH_PAR_V5_VERINFO
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV3))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V3_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V4_VERINFO)))
                  && ((ProvidePortVersionInfo.Equals(&VEH_PAR_V3_VERINFO)) || (ProvidePortVersionInfo.Equals(&VEH_PAR_V4_VERINFO)) || (ProvidePortVersionInfo.Equals(&BASE_VERSION)))  )
        {
          ConvertToVehParV5(&m_VehParV5, reinterpret_cast<const VehParV3::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV5;
          ulOutSize = sizeof(m_VehParV5);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV2))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V2_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V2_VERINFO))  )
        {
          ConvertToVehParV3(&m_VehParV3, reinterpret_cast<const VehParV2::VehPar_t*>(pPPortData));
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          *pOutData = &m_VehParV5;
          ulOutSize = sizeof(m_VehParV5);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV1))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V1_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V1_VERINFO))   )
        {
          ConvertToVehParV2(&m_VehParV2, reinterpret_cast<const VehParV1::VehPar_t*>(pPPortData));
          ConvertToVehParV3(&m_VehParV3, &m_VehParV2);
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          *pOutData = &m_VehParV5;
          ulOutSize = sizeof(m_VehParV5);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV0))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V0_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V0_VERINFO)))
        {
          ConvertToVehParV1(&m_VehParV1, reinterpret_cast<const VehParV0::VehPar_t*>(pPPortData));
          ConvertToVehParV2(&m_VehParV2, &m_VehParV1);
          ConvertToVehParV3(&m_VehParV3, &m_VehParV2);
          ConvertToVehParV5(&m_VehParV5, &m_VehParV3);
          *pOutData = &m_VehParV5;
          ulOutSize = sizeof(m_VehParV5);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      // It is so if the size of the request port equals the V3
      // size & the the request port version is V3 (also handle special case when no version information
      // is provided for the request port, ie.: version number is zero)
      // In addition the request port version V4 is handled like the V3 version!
      else if ((ulRPortSize == sizeof(m_VehParV3)) &&
        ((requestPortVersionInfo.Equals(&VEH_PAR_V3_VERINFO)) || (requestPortVersionInfo.Equals(&VEH_PAR_V4_VERINFO))))
      {
        if ((ulPPortSize == sizeof(m_VehParV3)) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V3_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V4_VERINFO))) &&
          ((ProvidePortVersionInfo.Equals(&VEH_PAR_V3_VERINFO)) || (ProvidePortVersionInfo.Equals(&VEH_PAR_V4_VERINFO))))
        {
          // Provide port sizes match and versions are either VEH_PAR_V3_VERINFO or VEH_PAR_V4_VERINFO, which are identical
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV5)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V5_VERINFO))) && (ProvidePortVersionInfo.Equals(&VEH_PAR_V5_VERINFO)))
        {
          ConvertToVehParV3(&m_VehParV3, reinterpret_cast<const VehParV5::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV3;
          ulOutSize = sizeof(m_VehParV3);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV2)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V2_VERINFO))) && (ProvidePortVersionInfo.Equals(&VEH_PAR_V2_VERINFO)))
        {
          ConvertToVehParV3(&m_VehParV3, reinterpret_cast<const VehParV2::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV3;
          ulOutSize = sizeof(m_VehParV3);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV1)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V1_VERINFO))) && (ProvidePortVersionInfo.Equals(&VEH_PAR_V1_VERINFO)))
        {
          ConvertToVehParV3(&m_VehParV3, reinterpret_cast<const VehParV1::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV3;
          ulOutSize = sizeof(m_VehParV3);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == sizeof(m_VehParV0)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V0_VERINFO))) && (ProvidePortVersionInfo.Equals(&VEH_PAR_V0_VERINFO)))
        {
          ConvertToVehParV3(&m_VehParV3, reinterpret_cast<const VehParV0::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV3;
          ulOutSize = sizeof(m_VehParV3);
          lRet = SIM_ERR_OK;
        }
        else
        {
          if (DecodeTPWInput(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            *pOutData = &m_VehParV3;
            ulOutSize = sizeof(m_VehParV3);
            lRet = SIM_ERR_OK;
          }
          else if (DecodeRSPInputVDATA(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            *pOutData = &m_VehParV3;
            ulOutSize = sizeof(m_VehParV3);
            lRet = SIM_ERR_OK;
          }
          else if (DecodeVDYInput(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            *pOutData = &m_VehParV3;
            ulOutSize = sizeof(m_VehParV3);
            lRet = SIM_ERR_OK;
          }
          else
          {
            lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
          }
        }
      }
      else if (    (ulRPortSize == sizeof(m_VehParV2))
                && (requestPortVersionInfo.Equals(&VEH_PAR_V2_VERINFO))  )
      {
        if (    (ulPPortSize == sizeof(m_VehParV3))
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V3_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V4_VERINFO)))
             && ((ProvidePortVersionInfo.Equals(&VEH_PAR_V3_VERINFO)) || (ProvidePortVersionInfo.Equals(&VEH_PAR_V4_VERINFO)))  )
        {
          ConvertToVehParV2(&m_VehParV2, reinterpret_cast<const VehParV3::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV2;
          ulOutSize = sizeof(m_VehParV2);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV1))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V1_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V1_VERINFO))  )
        {
          ConvertToVehParV2(&m_VehParV2, reinterpret_cast<const VehParV1::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV2;
          ulOutSize = sizeof(m_VehParV2);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV0))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V0_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V0_VERINFO))  )
        {
          ConvertToVehParV2(&m_VehParV2, reinterpret_cast<const VehParV0::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV2;
          ulOutSize = sizeof(m_VehParV2);
          lRet = SIM_ERR_OK;
        }
        else
        {
          if (DecodeTPWInput(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            *pOutData = &m_VehParV3;
            ulOutSize = sizeof(m_VehParV3);
            lRet = SIM_ERR_OK;
          }
          else if (DecodeRSPInputVDATA(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            *pOutData = &m_VehParV3;
            ulOutSize = sizeof(m_VehParV3);
            lRet = SIM_ERR_OK;
          }
          else if (DecodeVDYInput(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            *pOutData = &m_VehParV3;
            ulOutSize = sizeof(m_VehParV3);
            lRet = SIM_ERR_OK;
          }
          else
          {
            lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
          }
        }
      }
      else if ((ulRPortSize == sizeof(m_VehParV1)) && (requestPortVersionInfo.Equals(&VEH_PAR_V1_VERINFO)))
      {
        if (    (ulPPortSize == sizeof(m_VehParV3))
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V3_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V4_VERINFO)))
             && ((ProvidePortVersionInfo.Equals(&VEH_PAR_V3_VERINFO)) || (ProvidePortVersionInfo.Equals(&VEH_PAR_V4_VERINFO)))  )
        {
          ConvertToVehParV1(&m_VehParV1, reinterpret_cast<const VehParV3::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV1;
          ulOutSize = sizeof(m_VehParV1);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV2))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V2_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V2_VERINFO))  )
        {
          ConvertToVehParV1(&m_VehParV1, reinterpret_cast<const VehParV2::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV1;
          ulOutSize = sizeof(m_VehParV1);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV0))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V0_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V0_VERINFO))  )
        {
          ConvertToVehParV1(&m_VehParV1, reinterpret_cast<const VehParV0::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV1;
          ulOutSize = sizeof(m_VehParV1);
          lRet = SIM_ERR_OK;
        }
        else
        {
          if (DecodeTPWInput(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehParV1(&m_VehParV1, &m_VehParV3);
            *pOutData = &m_VehParV1;
            ulOutSize = sizeof(m_VehParV1);
            lRet = SIM_ERR_OK;
          }
          else if (DecodeRSPInputVDATA(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehParV1(&m_VehParV1, &m_VehParV3);
            *pOutData = &m_VehParV1;
            ulOutSize = sizeof(m_VehParV1);
            lRet = SIM_ERR_OK;
          }
          else if (DecodeVDYInput(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehParV1(&m_VehParV1, &m_VehParV3);
            *pOutData = &m_VehParV1;
            ulOutSize = sizeof(m_VehParV1);
            lRet = SIM_ERR_OK;
          }
          else
          {
            lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
          }
        }
      }
      else if ((ulRPortSize == sizeof(m_VehParV0)) && (requestPortVersionInfo.Equals(&VEH_PAR_V0_VERINFO)))
      {
        if (    (ulPPortSize == sizeof(m_VehParV3))
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V3_VERINFO)) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V4_VERINFO)))
             && ((ProvidePortVersionInfo.Equals(&VEH_PAR_V3_VERINFO)) || (ProvidePortVersionInfo.Equals(&VEH_PAR_V4_VERINFO)))  )
        {
          ConvertToVehParV0(&m_VehParV0, reinterpret_cast<const VehParV3::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV0;
          ulOutSize = sizeof(m_VehParV0);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV2))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V2_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V2_VERINFO))  )
        {
          ConvertToVehParV0(&m_VehParV0, reinterpret_cast<const VehParV2::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV0;
          ulOutSize = sizeof(m_VehParV0);
          lRet = SIM_ERR_OK;
        }
        else if (    (ulPPortSize == sizeof(m_VehParV1))
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VEH_PAR_V1_VERINFO)))
                  && (ProvidePortVersionInfo.Equals(&VEH_PAR_V1_VERINFO))  )
        {
          ConvertToVehParV0(&m_VehParV0, reinterpret_cast<const VehParV1::VehPar_t*>(pPPortData));
          *pOutData = &m_VehParV0;
          ulOutSize = sizeof(m_VehParV0);
          lRet = SIM_ERR_OK;
        }
        else
        {
          if (DecodeTPWInput(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehParV0(&m_VehParV0, &m_VehParV3);
            *pOutData = &m_VehParV0;
            ulOutSize = sizeof(m_VehParV0);
            lRet = SIM_ERR_OK;
          }
          else if (DecodeRSPInputVDATA(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehParV0(&m_VehParV0, &m_VehParV3);
            *pOutData = &m_VehParV0;
            ulOutSize = sizeof(m_VehParV0);
            lRet = SIM_ERR_OK;
          }
          else if (DecodeVDYInput(&m_VehParV3, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehParV0(&m_VehParV0, &m_VehParV3);
            *pOutData = &m_VehParV0;
            ulOutSize = sizeof(m_VehParV0);
            lRet = SIM_ERR_OK;
          }
          else
          {
            lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
          }
        }
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
  }
  else
  {
    lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  }

  return lRet;
}


/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvVehPar::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet;

  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(m_VehParV8)) && (requestPortVersionInfo.Equals(&VEH_PAR_V8_VERINFO)))
    {
      InitDefaultVehParV8(&m_VehParV8);
      *pDefaultData = &m_VehParV8;
      ulDefaultSize = sizeof(m_VehParV8);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehParV7)) && (requestPortVersionInfo.Equals(&VEH_PAR_V7_VERINFO)))
    {
      InitDefaultVehParV7(&m_VehParV7);
      *pDefaultData = &m_VehParV7;
      ulDefaultSize = sizeof(m_VehParV7);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehParV3)) && ((requestPortVersionInfo.Equals(&VEH_PAR_V3_VERINFO)) || (requestPortVersionInfo.Equals(&VEH_PAR_V4_VERINFO))))
    {
      InitDefaultVehParV3(&m_VehParV3);
      *pDefaultData = &m_VehParV3;
      ulDefaultSize = sizeof(m_VehParV3);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehParV2)) && (requestPortVersionInfo.Equals(&VEH_PAR_V2_VERINFO)))
    {
      InitDefaultVehParV2(&m_VehParV2);
      *pDefaultData = &m_VehParV2;
      ulDefaultSize = sizeof(m_VehParV2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehParV1)) && (requestPortVersionInfo.Equals(&VEH_PAR_V1_VERINFO)))
    {
      InitDefaultVehParV1(&m_VehParV1);
      *pDefaultData = &m_VehParV1;
      ulDefaultSize = sizeof(m_VehParV1);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehParV0)) && (requestPortVersionInfo.Equals(&VEH_PAR_V0_VERINFO)))
    {
      InitDefaultVehParV0(&m_VehParV0);
      *pDefaultData = &m_VehParV0;
      ulDefaultSize = sizeof(m_VehParV0);
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


uint8 CConvVehPar::ConvertIOState(unsigned int position, unsigned long* pInputstate)
{
  uint8 outputstate;
  uint8 inputstate;

  inputstate = VDY_GET_IO_STATE(position, pInputstate);

  if (inputstate == VDY_IO_STATE_VALID)
  {
    outputstate = VehParV8::VEH_PAR_IO_STATE_VALID;
  }
  else if (inputstate == VDY_IO_STATE_NOTAVAIL)
  {
    outputstate = VehParV8::VEH_PAR_IO_STATE_NOTAVAIL;
  }
  else if (inputstate == VDY_IO_STATE_INIT)
  {
    outputstate = VehParV8::VEH_PAR_IO_STATE_INIT;
  }
  else 
  {
    outputstate = VehParV8::VEH_PAR_IO_STATE_INVALID;
  }

  return outputstate;
}


// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvVehPar::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // If sizes and versions match, then just take data
  if ((ePPortType == eRPortType) && (ulPPortSize == ulRPortSize))
  {
    bResult = true;
  }
  else if (ePPortType == simREFERENCE_t)
  {
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo);
  }
  else
  {
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize);
  }
  return bResult;
}


// used to check if ports are compatible between different versions
bool CConvVehPar::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // If sizes and versions match, then just take data
  if ((ePPortType == eRPortType) && (ulPPortSize == ulRPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }
  else if (ePPortType == simREFERENCE_t)
  {
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo);
  }
  else
  {
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize, &providePortVersionInfo);
  }
  return bResult;
}

//
// Factory function (only visible symbol from outside of this module)
//
IConverter * CreateVehParConvClass(void)
{
  return new CConvVehPar();
}
