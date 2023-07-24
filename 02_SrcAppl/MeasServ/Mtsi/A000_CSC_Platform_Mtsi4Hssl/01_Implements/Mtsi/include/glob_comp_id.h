// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.65 $
/// @file

/*****************************************************************************
  Last Author:    $Author: Pop-EXT, Andrei Gabriel (uia85031) (uia85031) $
  Last Change:    $Date: 2019/10/08 08:23:43CEST $


  File History:

  Changes:        $Log: glob_comp_id.h  $
  Changes:        Revision 1.65 2019/10/08 08:23:43CEST Pop-EXT, Andrei Gabriel (uia85031) (uia85031) 
  Changes:        add VA for HOMON
  Changes:        Revision 1.64 2019/10/01 10:30:40CEST Pop-EXT, Andrei Gabriel-ADD (uia85031) (uia85031) 
  Changes:        Change the virtual address of FCU
  Changes:        Revision 1.63 2019/10/01 08:15:10CEST Pop-EXT, Andrei Gabriel-ADD (uia85031) (uia85031) 
  Changes:        Change the virtual address of FCU
  Changes:        Revision 1.62 2019/09/30 08:25:41CEST Buz, Razvan (uid95356) 
  Changes:        Add VirtualAddresses for the CEM subcomponents
  Changes:        Revision 1.61 2019/09/17 09:37:07CEST Pop-EXT, Andrei Gabriel-ADD (uia85031) (uia85031) 
  Changes:        Suppress QAC 0380
  Changes:        Revision 1.60 2019/09/10 10:08:20CEST Pop-EXT, Andrei Gabriel-ADD (uia85031) (uia85031) 
  Changes:        Suppress qac warnings 0388 and 0810
  Changes:        Revision 1.59 2019/08/27 14:33:37CEST Paulig, Ralf (uidt3509) 
  Changes:        slight adaptions for making FS a top level comp
  Changes:        Revision 1.58 2019/08/20 10:00:40CEST Pop-EXT, Andrei Gabriel-ADD (uia85031) (uia85031) 
  Changes:        Change "TEST_Data" to Test_Data because "TEST_" is interpreted by doxy as a test funcion
  Changes:        Revision 1.57 2019/08/07 11:05:43CEST Mocan-Dragoescu, Andreea (uidq9296) 
  Changes:        Add Virtual addresses for LOPLN and LOCTR
  Changes:        Revision 1.56 2019/06/19 17:24:01CEST Tudoran, Catalin (uidv7833) 
  Changes:        Updated to newest design template. Fixed certain design issues.
  Changes:        Revision 1.55 2019/05/17 17:19:48CEST Andoniu, Lorena (uidl6191) 
  Changes:        - add IDs and Virtual addresses for Road CLasification components RC1 and RC2 ( needed in ARS441)
  Changes:        Revision 1.54 2019/05/15 17:34:53CEST Andoniu, Lorena (uidl6191) 
  Changes:        - set COMP ID for RPM1 and RPM2 to TBD
  Changes:        Revision 1.53 2019/05/14 17:08:17CEST Andoniu, Lorena (uidl6191) 
  Changes:        - add addresses for RPM1, RPM2, ACDC, MEDIC, TRJPLN and TRJCTR
  Changes:        - add RPP just to be in sync with ARS540 version from GIT
  Changes:        Revision 1.52 2019/03/22 07:18:25CET Kammerl, Matthias (uidr3468) 
  Changes:        Add comment
  Changes:        " DO NOT use the COMP_ID_xxx as RtaGlobalIDs anymore!!"
  Changes:        Revision 1.51 2019/03/18 09:46:16CET Tudoran, Catalin (uidv7833) 
  Changes:        Added SPT addresses.
  Changes:        Revision 1.50 2019/01/21 09:42:07CET Paulig, Ralf (uidt3509) 
  Changes:        VA range and cycle id for LMK added
  Changes:        Revision 1.49 2019/01/18 16:57:42CET Kammerl, Matthias (uidr3468) 
  Changes:        Rename COMP_ID_DPUCDR into COMP_ID_CDR
  Changes:        Revision 1.48 2018/12/14 10:10:58CET Paulig, Ralf (uidt3509) 
  Changes:        KFC added
  Changes:        Revision 1.47 2018/12/13 15:13:32CET Kammerl, Matthias (uidr3468) 
  Changes:        Renaming of a few componentIDs - required for autogeneration of RTA-xml-Files
  Changes:        Add COMP_ID_IPC_DPU_TX
  Changes:        Revision 1.46 2018/12/10 10:15:22CET Andoniu, Lorena (uidl6191) 
  Changes:        Allocate virtual address range for IOHWAB: 0x209A0000 - 0x209AFFFF
  Changes:        Revision 1.45 2018/12/03 12:46:23CET Andoniu, Lorena (uidl6191) 
  Changes:        Allocate virtual address range for RCG: 0x40A10000�to 0x40A10FFF
  Changes:        Revision 1.44 2018/11/14 12:34:50CET Salbageanu, Andrei (uidn9580) 
  Changes:        Updated HMI with VA/ Comp ID / Task id
  Changes:        Revision 1.43 2018/11/08 13:13:33CET Salbageanu, Andrei (uidn9580) 
  Changes:        Added VCS Measfreeze virtual address
  Changes:        Revision 1.42 2018/10/29 14:46:09CET Salbageanu, Andrei (uidn9580) 
  Changes:        Added new Comp IDs and VA 
  Changes:        SRP1,SRP2,RDT,SEP1,SEP2,RMP1,RMP2
  Changes:        Revision 1.41 2018/09/06 16:39:07CEST Kammerl, Matthias (uidr3468) 
  Changes:        Remove define COMP_ID_SW_GEN_ADAPT_ADAPAPTER which was needed for compatibility reason (eliminate typo)
  Changes:        Revision 1.40 2018/08/10 14:14:32CEST Kammerl, Matthias (uidr3468) 
  Changes:        Add virtualAddressRanges for several new components
  Changes:        (CC, MOS, OOC, RADI, RDT, RIC, RMP, RMHT, SEP).
  Changes:        Note: For these new components no COMP_IDs have been provided as we run out of 8 bit range. 
  Changes:        For now it's ok, hoping that we have a fnal solution as soon we need the the IDs for the new components.
  Changes:        Revision 1.39 2018/08/06 14:52:18CEST Paulig, Ralf (uidt3509) 
  Changes:        - RDBC added
  Changes:        - GEOS task id added
  Changes:        Revision 1.38 2018/07/17 10:15:54CEST Paulig, Ralf (uidt3509) 
  Changes:        GEOS id fixed
  Changes:        Revision 1.37 2018/07/13 12:20:58CEST Paulig, Ralf (uidt3509) 
  Changes:        - GEOS comp id added
  Changes:        - re-added algo VA ranges
  Changes:        Revision 1.36 2018/07/11 10:37:06CEST Timoce-EXT, Claudiu (uidq8761) 
  Changes:        Added Virtual Adreess for BSWM
  Changes:        Revision 1.35 2018/06/19 14:41:36CEST Schmid, Werner (uidv7869) 
  Changes:        glob_comp_id.h generated by means of GlobCompGenerator
  Changes:        Revision 1.34 2018/06/12 19:25:44CEST Tudoran, Catalin (uidv7833) 
  Changes:        Updated the virtual address of FROOP.
  Changes:        Revision 1.33 2018/05/18 15:39:29CEST Schmid, Werner (uidv7869) 
  Changes:        fixed mistake in writing
  Changes:        Revision 1.32 2018/05/18 14:53:24CEST Schmid, Werner (uidv7869) 
  Changes:        Added
  Changes:        a) missing COMP_ID_CUST_0 .... COMP_ID_CUST_2
  Changes:        b) ID for Algo DAPVEH
  Changes:        c) missing TASK_IDs for ARS441 Algos (for future use instead of TASK_ID_CUSTOM_xx
  Changes:        Revision 1.31 2018/05/18 09:51:19CEST Schmid, Werner (uidv7869) 
  Changes:        Removed ARS441 (VL28) Compiler flagging.
  Changes:        Revision 1.30 2018/05/14 15:52:25CEST Kammerl, Matthias (uidr3468) 
  Changes:        Correct typo (COMP_ID_SW_GEN_ADAPT_ADAPAPTER -> COMP_ID_SW_GEN_ADAPT_ADAPTER)
  Changes:        Revision 1.29 2018/04/20 15:58:22CEST Schmid, Werner (uidv7869) 
  Changes:        Temporary workaround for ARS441 DPU SW
  Changes:        Revision 1.28 2018/04/16 17:27:26CEST Paulig, Ralf (uidt3509) 
  Changes:        replaced legacy PED with GRAPPA
  Changes:        Revision 1.27 2018/03/09 09:57:33CET Kammerl, Matthias (uidr3468) 
  Changes:        include glob_type.h due to compile errors in vdy sim
  Changes:        Revision 1.26 2018/03/08 09:29:21CET Kammerl, Matthias (uidr3468) 
  Changes:        Provide all COMP_IDs as defines and as "static const" as well in order to avoid QAC violations.
  Changes:        Revision 1.25 2018/02/28 20:57:57CET Zaech, Patrick (uidj7155) 
  Changes:        Add COMP_ID_ISP 245 with address range of former SAC
  Changes:        Add TASK_ID_ISP 245
  Changes:        Revision 1.24 2018/02/19 09:58:07CET Kammerl, Matthias (uidr3468) 
  Changes:        Add "pseudo"-componentID COMP_ID_EVENTS_IUC as needed in MFC431
  Changes:        Revision 1.23 2018/02/16 09:56:22CET Kammerl, Matthias (uidr3468) 
  Changes:        Add COMP_ID_PED again as  needed by RUM SIM
  Changes:        Revision 1.22 2018/02/15 13:35:20CET Kammerl, Matthias (uidr3468) 
  Changes:        - Preparation for autoGeneration of rtaConfig-Files
  Changes:           ->cleanup and complete the glob_comp_ids (values and names of existing ids are unchanged) 
  Changes:        - Add startDefines for the virtuallAddresses for all the components and assing the current addresses as far
  Changes:          as possible (taken out of current sdl-files of all projects) 
  Changes:            -> This shall be a starting point for cleaning up the virtualAddressRanges of each component

*****************************************************************************/
// PRQA S 0380 EOF
// Msg(3:0380) [L] Number of macro definitions exceeds 4095 - program does not conform strictly to ISO:C99.
// Reason: These are the necessary defines.
// Reviewed by P. Andrei on 2019-09-17
#ifndef GLOB_COMP_ID_INCLUDED
#define GLOB_COMP_ID_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
// PRQA S 0388, 0810 5
// Msg(3:0388) [L] '#include glob_type.h' causes nesting to exceed 15 levels - program does not conform strictly to ISO:C99.
// Msg(3:0810) [L] '#include glob_type.h' causes nesting to exceed 8 levels - program does not conform strictly to ISO:C90.
// reason: solve preliminary, SW architecture problem
// Reviewed by P. Andrei on 2019-09-10
#include <Std_Types.h>
#include "MTSI_TaskId_Cfg.h"
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  GUIDLINE for new MeasFreezeDataMTS function
*****************************************************************************/
/*
  Guideline for the use of the new MeasFreezeDataMTS function.

  1) before each function cycle must call the function "void MEASStartFuncCycle(MEASFuncID_t FuncID)"
      - FuncID is equal to the glob_comp_id in the following table
     With this function the counter of the MTS is incremented.

  2) new MEASFreezeDataMTS function which is to call:
       MEASFreezeDataMTS(MEASInfo_t *Info,pui32_t MeasDataMTS, NULL);
  
  More Information for the MEASFreezeDataMTS function:

  1) MEASInfo_t *Info
 	      typedef struct
			  {
			    ui32_t VirtualAddress;               ==>  Location of data in virtual address space
			    ui32_t Length;                       ==>  Length of data in bytes
			    MEASFuncID_t         FuncID;         ==> Identifier of data source, see glob_comp_id
			    MEASFuncChannelID_t  FuncChannelID;  ==> Data classification (e.g. input, output), see 
                                                   Information for MTS and simulation in the glob_comp_id
			  }MEASInfo_t;
     
     ==> the struct mus be "const static", because the meas has an optimize access.
         For the meas means there are no unnecessary runing time and there are no deficit in the memory.

  2) FuncID
        FuncID = Glob_Comp_ID of the component, see in the following table

  3) FuncChannelID
        Special configuration for simulation, see at the end of this file.
        There are general configuration for simulation, all components can manage this by himself,
        if they need his own configuration.

        attention:
          --> last version of MTS doesn't supported this function
          --> for the meas component connoted this there are a workaround for the use the new MeasFreezeDataMTS
          --> no adaptation, if the MTS supported the function, all adaption is in the meas component

  4) virtual address define the structure of the data which will be send and set by a doxygen command.
          --> "@VADDR:0x05000900"      <==>  virtual address for MTS

  5) configuration of the cycle ID, by a doxygen command.
          --> "@cycleid cycleid_60"   <==>  "ARSMainCycle 60"
          --> no "@cycleid"           <==>  "ARSMainCycle 20" (DEFAULT)
*/

// The glob_comp_id.h is used in c-context and in cpp-context as well. In order to avoid QAC violations we have 
// all the componentIDs (COMP_ID_xxx) and the startAddresses of the virtualAddressRanges (VIRT_ADDR_START_xxx) twice 
// - in c-context as "defines" and in cpp-context as "static const".
// To avoid errors due to "double-implementation" and to make the life easier the COMP_ID_xxx and the 
// VIRT_ADDR_START_xxx are generated.
// Steps for changes:
// 1) Ensure that you have the latest (or the right) version of glob_comp_id.h on your hardDrive. 
//    Note: The glob_comp_id.h of the following location is used and will be updated by the generator:
//    http://ims-adas:7001/si/viewproject?projectName=/ADAS/SW/Components/MTSI%5fMTSInterface/04%5fEngineering/01%5fSource%5fCode/common/MTSI/project.pj
// 2) Edit the file CompIDsAndVirtAddresses.csv in 
//    http://ims-adas:7001/si/viewproject?projectName=/ADAS/SW/Components/MTSI%5fMTSInterface/04%5fEngineering/02%5fDevelopment%5fTools/MTSI/GlobCompGenerator/project.pj
// 3) Run the batch GenerateGlobCompId.bat
//    The glob_comp_id.h in the location mentioned above is updated according your changes in CompIDsAndVirtAddresses.csv
// 4) Review if anything is ok then check in both files the glob_comp_id.h and the CompIDsAndVirtAddresses.csv (!!) as well



// **************************************************************************************************************************************
// RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!!
// DO NOT use the COMP_ID_xxx as RtaGlobalIDs anymore!!
//
// Please use the RTA_GLOBALID_xxx provided in RTA_GlobalIDs.h instead.
// In case there is no adequate RTA_GLOBALID_xxx for your component or your your use case please contact Matthias Kammerl.
//
//The RtaGlobalID is the 2nd argument in the serviceFunction:
// void RTA_v_AddEvent(const RTA_t_Events EVENT, const uint8�u_GLOBALID, const uint8 u_LOCALID, const uint8 u_OPTDATA)
//
// DO NOT use the COMP_ID_xxx as RtaGlobalIDs anymore!!
// RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!! RTA !!!!
// **************************************************************************************************************************************

#ifndef COMP_ID_NULL
//TODO: What's the reason behind the compilerSwitch? 
#define COMP_ID_NULL      0   /* Reserved: Do not use */
//TODO: Why must "0" not be used as a COMP_ID?

// Generated code. No manually changes below this line, please!***************************************************
// GLOB_COMP_ID_GENERATION_START**********************************************************************************
// COMPONENT_XML_GENERATION_START ********************************************************************************
// ***************************************************************************************************************

// The component IDs**********************************************************************************************

#ifndef __cplusplus

#define COMP_ID_ACAL                                     ( 88U) //ACAL  AutoCalibration
#define COMP_ID_ACDC                                     ( 58U) //ACDC  CollisionDetectionAndClassification
#define COMP_ID_ADP                                      (  4U) //ADP AlgoSWAdapter
#define COMP_ID_ALN                                      ( 19U) //ALN Alignment
#define COMP_ID_APPLDIAG                                 (145U) //APPLDIAG  ApplicationDiagnostics                               - sub-component of Diag
#define COMP_ID_BAI                                      (156U) //BAI BootAppInt                                                 - sub-component of MEM_Memory
#define COMP_ID_BSWM                                     (  5U) //BSWM  BasicSwModeManager
#define COMP_ID_CAL                                      (  9U) //CAL CommonACCLibrary
#define COMP_ID_CALI                                     (  6U) //CALI  Calibration                                              - sub-component of EOL_Service
#define COMP_ID_CANIF                                    (136U) //CANIF CanInterface                                             - sub-component of ComStk
#define COMP_ID_CANNM                                    ( 14U) //CANNM CanNetworkManagement                                     - sub-component of ComStk
#define COMP_ID_CANSM                                    ( 15U) //CANSM CanStateManager                                          - sub-component of ComStk
#define COMP_ID_CANTP                                    ( 16U) //CANTP CanTransportProtocol                                     - sub-component of ComStk
#define COMP_ID_CANTSYNC                                 ( 17U) //ANTSYNC CanTimeSync                                            - sub-component of ComStk
#define COMP_ID_CB                                       ( 71U) //CB  CameraBlockage
// #define COMP_ID_CC                                      TBD //CC Classification Consolidation
#define COMP_ID_CCT                                      ( 10U) //CCT CommonCameraToolbox
#define COMP_ID_CHIPS                                    ( 73U) //CHIPS CommonHWAcceleratedImgProcSys
#define COMP_ID_CIPP                                     ( 70U) //CIPP  CommonImagePreProcessing
#define COMP_ID_CML                                      ( 11U) //CML CommonMathLibrary
#define COMP_ID_COF                                      ( 13U) //COF RadarCameraObjectFusion
#define COMP_ID_COM                                      ( 22U) //COM Communication                                              - sub-component of ComStk
#define COMP_ID_COMM                                     ( 20U) //COMM  CommunicationManager                                     - sub-component of ComStk
#define COMP_ID_COMXF                                    ( 21U) //COMXF ComTransformer                                           - sub-component of ComStk
#define COMP_ID_CROSS                                    ( 42U) //CROSS CustomerObjSelSide
#define COMP_ID_CRY                                      ( 46U) //CRY CryptographicLibrary                                       - sub-component of Crypto
#define COMP_ID_CRYIF                                    ( 43U) //CRYIF CryptoInterface                                          - sub-component of Crypto
#define COMP_ID_CRYPTO                                   ( 44U) //CRYPTO  CryptoDriver                                           - sub-component of Crypto
#define COMP_ID_CRYSHE                                   ( 45U) //CRYSHE  CryptographicSecureHwExtension                         - sub-component of Crypto
#define COMP_ID_CSI                                      (154U) //CSI CameraSerialInterface                                      - sub-component of Mcal
#define COMP_ID_CSM                                      ( 47U) //CSM CryptoServiceManager                                       - sub-component of Crypto
#define COMP_ID_CTA                                      ( 48U) //CTA CrossTrafficAssist
#define COMP_ID_CTB                                      ( 49U) //CTB CrossTrafficBraking
#define COMP_ID_DAP                                      (120U) //DAP RadarDataProcessing
#define COMP_ID_DAPVEH                                   (247U) //DAPVEH RadarDataProcessingVehicle
#define COMP_ID_DB                                       ( 50U) //DB  InterProcessorCommunicationDatabase
#define COMP_ID_DCM                                      ( 51U) //DCM DiagnosticCommunicationManager                             - sub-component of Diag
#define COMP_ID_DEM                                      (140U) //DEM DiagnosticEventManager                                     - sub-component of ErrMgt
#define COMP_ID_DET                                      (139U) //DET DefaultErrorTracer
#define COMP_ID_DGM                                      ( 84U) //DGM DegradationManager                                         - sub-component of ErrMgt
#define COMP_ID_DLT                                      ( 52U) //DLT DiagnosticLogAndTrace                                      - sub-component of Diag
#define COMP_ID_DoIP                                     ( 23U) //DoIP  DiagnosticOverIP                                         - sub-component of ComStk
#define COMP_ID_DPC                                      (220U) //DPC DataProcessingControl                                      - sub-component of RadarCdd
#define COMP_ID_CDR                                      (189U) //DPUCDR  CrashDataRecorder
#define COMP_ID_DPUCOM                                   ( 53U) //DPUCOM  Communication
#define COMP_ID_DPUEDP                                   ( 54U) //DPUEDP  EmbeddedDevelopmentPlatform
#define COMP_ID_DPUFF                                    ( 55U) //DPUFF FunctionsFramework
#define COMP_ID_DPUHWIF                                  ( 56U) //DPUHWIF HardwareInterface
#define COMP_ID_DPUIA                                    ( 57U) //DPUIA ImageAcquisition                                         - sub-component of DpuImaging
#define COMP_ID_DPUINFRA                                 (186U) //DPUINFRA  Infrastructure
#define COMP_ID_DPUOS                                    (193U) //DPUOS DPUOperatingSystem                                       - sub-component of Os
#define COMP_ID_DPUSBL                                   (181U) //DPUSBL  SecondaryBootloader
#define COMP_ID_DPUSERVICE                               (176U) //DPUSERVICE  Services
#define COMP_ID_DPUST                                    (177U) //DPUST SelfTest
#define COMP_ID_DRP                                      ( 59U) //DRP DigitalRadarSignalProcessing
#define COMP_ID_EA                                       (159U) //EA  EEPROMAbstraction                                          - sub-component of MEM_Memory
#define COMP_ID_EC                                       ( 62U) //EC  RadarEnvironmentClassification
#define COMP_ID_ECM                                      ( 72U) //ECM EOLCalibrationMono
#define COMP_ID_ECUM                                     ( 66U) //ECUM  EcuManager
#define COMP_ID_ECUOMC                                   ( 61U) //ECUOMC  EcuOperationModeControl
#define COMP_ID_EEP                                      (157U) //EEP EepromDriver                                               - sub-component of MEM_Memory
#define COMP_ID_EMLIB                                    ( 63U) //EMLIB RadarEMLibrary
#define COMP_ID_EM_CAM                                   ( 60U) //EM  CameraEnvironmentModel
#define COMP_ID_EM_RAD360                                ( 67U) //EM  Radar360EnvironmentModel
#define COMP_ID_EM_RAD_FRAME                             ( 77U) //EM  RadarEnvironmentModelFrame
#define COMP_ID_ETHIF                                    ( 24U) //ETHIF EthernetInterface                                        - sub-component of ComStk
#define COMP_ID_ETHSM                                    ( 25U) //ETHSM EthernetStateManager                                     - sub-component of ComStk
#define COMP_ID_ETHTSYN                                  ( 26U) //ETHTSYN TimeSyncOverEthernet                                   - sub-component of ComStk
#define COMP_ID_EVSADC                                   ( 89U) //EVSADC  EVSAnalogDigitalConversion
#define COMP_ID_EVSCAN                                   ( 96U) //EVSCAN  EcuValidationSoftwareCAN
#define COMP_ID_EVSFP                                    (244U) //EVSFP EcuValidationSoftwareFactoryProtocol
#define COMP_ID_EVSSPI                                   (103U) //EVSSPI  EVSSerialPeripheralInterface
#define COMP_ID_EVSTP                                    (243U) //EVSTP EcuValidationSoftwareTransportProtocol
#define COMP_ID_FAMO                                     ( 87U) //FAMO  FunctionalSafetyAlgoMonitor
#define COMP_ID_FCT                                      (  3U) //FCT Function
#define COMP_ID_FCTS                                     (107U) //FCTS  SideFunctions
#define COMP_ID_FCU                                      (101U) //FCU FunctionControlUnit
#define COMP_ID_FEE                                      (158U) //FEE FlashEEPROMEmulation                                       - sub-component of MEM_Memory
#define COMP_ID_FIM                                      (141U) //FIM FunctionInhibitionManager                                  - sub-component of ErrMgt
#define COMP_ID_FLSP                                     (161U) //FLSP  FlashParameters                                          - sub-component of MEM_Memory
#define COMP_ID_FPS                                      (241U) //FPS RadarFunctionPreSelection
#define COMP_ID_FROOP                                    (242U) //FROOP FrontRadOncomObjPreAssess
#define COMP_ID_FRS                                      ( 30U) //FRS FreeSpace
#define COMP_ID_FS                                       (112U) //FS  FreeSpace
#define COMP_ID_FSG                                      (171U) //FSG FeeSafeGuard                                               - sub-component of MEM_Memory
#define COMP_ID_GEOS                                     (248U) //GEOS GeometricSegmentation
#define COMP_ID_GEN                                      (105U) //GEN GeneralObjectDetection
#define COMP_ID_GFRS                                     (246U) //GFRS GridBasedFreespace
#define COMP_ID_GIN                                      (113U) //GIN GraphicalInference
#define COMP_ID_GP                                       (121U) //GP  RadarGridProcessing
#define COMP_ID_GRAPPA                                   (106U) //GRAPPA GenericRedvinePictureAnalysis
#define COMP_ID_GS                                       ( 74U) //GS  GlobalScheduler
#define COMP_ID_GSM                                      ( 97U) //GSM GroundSurfaceModel
#define COMP_ID_GSS                                      (114U) //GSS GenericSceneSegmentation
#define COMP_ID_HEAT                                     (134U) //HEAT  HeaterControl
#define COMP_ID_HLA                                      (  7U) //HLA HeadLightAssist
#define COMP_ID_HMI                                      (115U) //HMI HumanMachineInterface
#define COMP_ID_HOMON                                    (221U) //HOMON HomologationMonitor                         - sub-component of RadarCdd
#define COMP_ID_IC                                       ( 12U) //DPUIC ImagerControl                                            - sub-component of DpuImaging
#define COMP_ID_INFOBLOCK                                (179U) //INFOBLOCK InformationBlock                                     - sub-component of MEM_Memory
#define COMP_ID_IOB                                      ( 78U) //IOB ImageOverBus                                               - sub-component of EOL_Service
#define COMP_ID_IOHWAB                                   (116U) //IOHWAB  IoHwAbstractionLayer                                   - sub-component of IoHwAb
#define COMP_ID_IPC_IUC                                  (132U) //IPC InterProcessorCommunication
#define COMP_ID_ISC                                      (118U) //ISC InterfaceAndStateCoordinator
#define COMP_ID_ISP                                      (245U) //ISP ImageSignalProcessor
#define COMP_ID_ITC                                      (123U) //ITC InterTaskCommunication
#define COMP_ID_KFC                                      (251U) //KFC  KeyFrameCaddy
#define COMP_ID_LBS                                      (124U) //LBS LateralBlindSpot
#define COMP_ID_LCF_VEH                                  ( 90U) //LCF LateralControlFunctions
#define COMP_ID_LD                                       ( 75U) //LD  LaneDetection
#define COMP_ID_LMK                                      (125U) //LMK LandMarks
#define COMP_ID_LOCC                                     (126U) //LOCC  LongitudinalCruiseControl
#define COMP_ID_LODMC                                    (127U) //LODMC LongitudinalDynamicMotionControl
#define COMP_ID_LOHP                                     (135U) //LOHP  LongitudinalHeadwayPlanner
#define COMP_ID_LOPC                                     (131U) //LOPC  LongitudinalPlannerAndController
#define COMP_ID_LSD                                      ( 92U) //LSD LightSourceDetection
#define COMP_ID_MAP                                      (  8U) //MAP MapDataProvider
#define COMP_ID_MCAL                                     (148U) //MCAL  MicroControllerAbstractionLayer                          - sub-component of Mcal
#define COMP_ID_MCU                                      (144U) //MCU MicroControllerUnit                                        - sub-component of Mcal
#define COMP_ID_MEDIC                                    (155U) //MEDIC InterventionControl
#define COMP_ID_MEMIF                                    (180U) //MEMIF MemoryAbstractionInterface                               - sub-component of MEM_Memory
#define COMP_ID_MEMMAP                                   (182U) //MEMMAP  MemoryMap                                              - sub-component of MEM_Memory
#define COMP_ID_MEMO                                     ( 85U) //MEMO  MonoEgomotion
#define COMP_ID_MINOS                                    (194U) //MINOS MiniOperatingSystem                                      - sub-component of Os
// #define COMP_ID_MOS                                     TBD //MOS Model Output Selection
#define COMP_ID_MTSI                                     (133U) //MTSI  MTSInterface
#define COMP_ID_NM                                       ( 27U) //NM  NetworkManagementInterface                                 - sub-component of ComStk
#define COMP_ID_NVM                                      (130U) //NVM NonVolatileMemory                                          - sub-component of MEM_Memory
#define COMP_ID_NVMADAP                                  (187U) //NVMAD NonVolMemAdap                                            - sub-component of MEM_Memory
#define COMP_ID_NVMADMIN                                 (184U) //NVMAD NonVolatileMemoryAdministration                          - sub-component of MEM_Memory
#define COMP_ID_OD                                       (122U) //OD  RadarObjectDescription
#define COMP_ID_ODPP                                     (188U) //ODPP  RadarDetectionHistoryProcessingHP
#define COMP_ID_OG                                       (191U) //OG  OccupancyGrid
// #define COMP_ID_OOC                                     TBD //OOC Object and Obstruction Classification
#define COMP_ID_OS                                       (129U) //OS  OperatingSystem                                            - sub-component of Os
#define COMP_ID_PC                                       (108U) //PC  PatchCorrelator
#define COMP_ID_PCA                                      ( 95U) //PCA PointCloudAlgorithm
#define COMP_ID_PCC                                      (195U) //PCC RadarPedestrianCyclistClassification
#define COMP_ID_PD                                       (196U) //PD  RadarPerformanceDegradation
#define COMP_ID_PDM                                      ( 98U) //PDM PerformanceDegradationModule
#define COMP_ID_PDUR                                     ( 28U) //PDUR  PDURouter                                                - sub-component of ComStk
#define COMP_ID_PFC                                      ( 86U) //PFC PowerFlowComputation
#define COMP_ID_PMA                                      (153U) //PMA PostMortemAnalysis
#define COMP_ID_PMC                                      (197U) //PMC PowerModeControl
#define COMP_ID_POC                                      ( 99U) //POC POintcloudCorrespondences
#define COMP_ID_PROD                                     ( 79U) //PROD  ProductionXCPServices                                    - sub-component of EOL_Service
#define COMP_ID_PSB                                      (198U) //PSB PotholeAndSpeedBump
#define COMP_ID_PSC                                      (117U) //PSC PowerSupplyCircuit                                         - sub-component of IoHwAb
#define COMP_ID_PVS                                      (199U) //PVS       PavementSigns
#define COMP_ID_QSF                                      (149U) //QSF QuadSpiFlash                                               - sub-component of Mcal
// #define COMP_ID_RADI                                    TBD //RADI  Radar Detection Image
#define COMP_ID_RCG                                      (223U) //RCG RadarClusterGenerator
#define COMP_ID_RC1                                      (253U) //RC1  Road Classification 1
#define COMP_ID_RC2                                      (254U) //RC2  Road Classification 2
#define COMP_ID_RD                                       (224U) //RD  RadarRoadDescription
// #define COMP_ID_RDT                                     TBD //RDT Radar Detection Tracker
#define COMP_ID_RDPC                                     (222U) //RDPC  RawDataProcessingControl                                 - sub-component of RadarCdd
#define COMP_ID_RDBC                                     (249U) //RDBC  RoadDataBaseClient
#define COMP_ID_RFCOM                                    (146U) //RFCOM RadioFrequencyCommunication
#define COMP_ID_RHC                                      ( 65U) //RHC RadarHardwareControl
#define COMP_ID_RHCTI                                    (225U) //RHCTI RadarHardwareControlTi
// #define COMP_ID_RIC                                     TBD //RIC Road Infrastructure Classification
// #define COMP_ID_RMP1                                    TBD //RMP Radar Motion Properties
// #define COMP_ID_RMP2                                    TBD //RMP Radar Motion Properties
// #define COMP_ID_RMHT                                    TBD //RMHT Radar Multi Hypothesis Tracker
// #define COMP_ID_RPM1                                    TBD //RPM1 Radar Performance Monitoring 1
// #define COMP_ID_RPM2                                    TBD //RPM2 Radar Performance Monitoring 2
// #define COMP_ID_RPP                                     TBD //RPP
#define COMP_ID_RSP                                      ( 64U) //RSP RadarSignalProcessing
#define COMP_ID_RTA                                      (147U) //RTA RealTimeAnalysis
#define COMP_ID_RTE                                      (200U) //RTE RealTimeEnvironment
#define COMP_ID_RTL                                      (138U) //RTL RealTimeLogging
#define COMP_ID_RUM                                      ( 93U) //RUM RoadUserMeasurements
#define COMP_ID_SAP                                      (226U) //SAP SystemAnalysisAndProfiling
#define COMP_ID_SCTL                                     (143U) //SCTL  SensorControl
#define COMP_ID_SD                                       ( 29U) //SD  ServiceDiscovery                                           - sub-component of ComStk
#define COMP_ID_SECOC                                    (227U) //SECOC SecureOnboardCommunication
// #define COMP_ID_SEP1                                    TBD //SEP Static Environment Properties
// #define COMP_ID_SEP2                                    TBD //SEP Static Environment Properties
#define COMP_ID_SLATE                                    (230U) //SLATE SituationLaneAssociationTrajectoryEstimation
#define COMP_ID_SLATE1                                   (228U) //SLATE1  SituationLaneAssociationTrajectoryEstimation1
#define COMP_ID_SLATE2                                   (229U) //SLATE2  SituationLaneAssociationTrajectoryEstimation2
#define COMP_ID_SOAD                                     ( 31U) //SOAD  SocketAdapter                                            - sub-component of ComStk
#define COMP_ID_SOMEIPXF                                 ( 32U) //SOMEIPXF  SomeIpTransformer                                    - sub-component of ComStk
#define COMP_ID_SPM                                      (231U) //SPM SensorPerformanceMonitoring
#define COMP_ID_SPT_SIM                                  (232U) //SPT SignalProcessingToolbox Simulation Data
#define COMP_ID_SPT_RAWDATA                              (232U) //SPT SignalProcessingToolbox Raw (HW) Data
#define COMP_ID_SR                                       ( 80U) //SR  SignRecognition
// #define COMP_ID_SRP1                                    TBD //SRP Spatial and Relation Properties
// #define COMP_ID_SRP2                                    TBD //SRP Spatial and Relation Properties
#define COMP_ID_SSA                                      (233U) //SSA StandardSecurityArchitecture
#define COMP_ID_ST                                       (235U) //ST  SelfTest
#define COMP_ID_STARTUP                                  (234U) //STARTUP Startup
#define COMP_ID_STBM                                     (237U) //STBM  SynchronizedTimeBaseManager                              - sub-component of Sys
#define COMP_ID_SWHIL                                    (236U) //SWHIL HWInLoop
#define COMP_ID_SYS                                      (128U) //SYS SystemServices                                             - sub-component of Sys
#define COMP_ID_TCPIP                                    ( 40U) //TCPIP TcpIp                                                    - sub-component of ComStk
#define COMP_ID_TLR                                      (119U) //TLR TrafficLightRecognition
#define COMP_ID_TP                                       (  1U) //TP  TrafficParticipants
// #define COMP_ID_TRJPLN                                  TBD //TRJPLN
// #define COMP_ID_TRJCTR                                  TBD //TRJCTR
#define COMP_ID_TSA                                      ( 81U) //TSA TrafficSignAssist
#define COMP_ID_TST                                      (238U) //TST TestStimuli
#define COMP_ID_UDPNM                                    ( 41U) //UDPNM UDPNetworkManagement                                     - sub-component of ComStk
#define COMP_ID_UDW                                      ( 94U) //UDW UnsteadyDrivingWarning
#define COMP_ID_VC                                       (240U) //VC  RadarVehicleClassification
#define COMP_ID_VCS                                      (239U) //VCS VariantCodingServices
#define COMP_ID_VDY                                      (  2U) //VDY VehicleDynamics
#define COMP_ID_VODCA                                    (111U) //VODCA VisObjDetClaAlgo
#define COMP_ID_XCP                                      (137U) //XCP UniversalCalibrationProtocol                               - sub-component of ComStk
#define COMP_ID_ZIPWIRE                                  (150U) //ZIPWIRE ZipWire                                                - sub-component of Mcal
// The following componentIDs have to be checked if they are really needed.
// Either there is no mainstream component available, or they can be mapped to any mainstream component above.
// There are also IDs of PseudoComponents which can be avoided in near future maybe.                        
#define COMP_ID_MON                                      (142U) //Can it be assigned to COMP_ID_DGM or COMP_ID_DPUST ?
#define COMP_ID_EXTERNAL                                 (151U) //Used in imr_scheduler and imr_service -> part of DPUSERVICE?
#define COMP_ID_FCT60                                    ( 18U) //The same like FCT?
#define COMP_ID_EMO                                      (104U) //The same like MEMO ??
#define COMP_ID_ET                                       (152U) //Used in event_transceiver -> part of DUFF?
#define COMP_ID_LCF_SEN                                  ( 91U) //The same like LCF?
#define COMP_ID_IPC_DPU_RX                               (192U)
#define COMP_ID_IPC_DPU_TX                               (250U)
#define COMP_ID_RHC2                                     ( 69U) //The same like COMP_ID_RHC ?
#define COMP_ID_RSP2                                     ( 68U) //The same like COMP_ID_RSP ?
#define COMP_ID_SR_A                                     ( 82U) //COMP_ID_SR Shall be used as soon as dynamic taskMapping is implemented in rtaMo cct_ecu_monitor)
#define COMP_ID_SR_B                                     ( 83U) //COMP_ID_SR Shall be used as soon as dynamic taskMapping is implemented in rtaMo cct_ecu_monitor)
#define COMP_ID_CUST_1                                   ( 31U) //Alternative to COMP_ID_DAPVEH
#define COMP_ID_CUST_3                                   ( 33U) //Alternative to COMP_ID_RD
#define COMP_ID_CUST_4                                   ( 34U) //Alternative to COMP_ID_GFRS
#define COMP_ID_CUST_5                                   ( 35U) //Alternative to COMP_ID_PD
#define COMP_ID_CUST_6                                   ( 36U) //Alternative to COMP_ID_EC
#define COMP_ID_CUST_7                                   ( 37U) //Alternative to COMP_ID_VC
#define COMP_ID_CUST_8                                   ( 38U) //Alternative to COMP_ID_PCC
#define COMP_ID_CUST_9                                   ( 39U) //Alternative to COMP_ID_FPS
#define COMP_ID_SW_EVE                                   (173U) //-> part of DUFF?
#define COMP_ID_SW_EVE_ABORT                             ( 76U) //-> part of DUFF?
#define COMP_ID_SW_EVE_LOCKOUT                           (175U) //-> part of DUFF?
#define COMP_ID_SW_EVE_TRIGGER                           (174U) //-> part of DUFF?
#define COMP_ID_SW_FH                                    (185U) //-> can it be mapped to COMP_ID_DPUCDR  ?
#define COMP_ID_SW_GEN_ADAPT_ADAPTER                     (160U) //-> can it be mapped to COMP_ID_DPUFF or COMP_ID_DPUST?
#define COMP_ID_SW_GEN_ADAPT_ALGO_EXEC                   (165U) //-> can it be mapped to COMP_ID_DPUFF?
#define COMP_ID_SW_I2C                                   (163U) //-> can it be mapped to COMP_ID_DPUIC or COMP_ID_DPUIA?
#define COMP_ID_SW_ICC                                   (169U) //-> can it be mapped to COMP_ID_DPUCOM?
#define COMP_ID_SW_ICC_EVE                               (190U) //-> can it be mapped to COMP_ID_DPUFF or COMP_ID_DPUINFRA?
#define COMP_ID_SW_INIT                                  (178U) //-> can it be mapped to COMP_ID_DPUINFRA or COMP_ID_DPUSERVICE?
#define COMP_ID_SW_MDB                                   (183U) //-> can it be mapped to COMP_ID_DPUFF?
#define COMP_ID_SW_MEM_SERVICE                           (164U) //-> can it be mapped to COMP_ID_DPUSERVICE?
#define COMP_ID_SW_MONITORS                              (172U) //-> can it be mapped to COMP_ID_DPUST?
#define COMP_ID_SW_MTS                                   (170U) //-> can it be mapped to COMP_ID_MTSI?
#define COMP_ID_SW_SYSCLOCK                              (166U) //-> can it be mapped to COMP_ID_DPUSERVICE?
#define COMP_ID_SW_EVT_MARKER                            (162U) //-> PseudoComponentID
#define COMP_ID_EVENTS_IUC                               (100U) //-> PseudoComponentID
#define COMP_ID_SW_HWI                                   (167U) //-> PseudoComponentID
#define COMP_ID_SW_SWI                                   (168U) //-> PseudoComponentID
#define COMP_ID_LEMO                                     (109U) //mainstream component?
#define COMP_ID_LIQOR                                    (110U) //mainstream component?
//PseudoComponentIDs for free usage in RTE.                                                          
// They are needed for now, maybe it will be possible in future to map all of them to COMP_ID_RTE    
#define COMP_ID_RTE_1                                    (201U)
#define COMP_ID_RTE_2                                    (202U)
#define COMP_ID_RTE_3                                    (203U)
#define COMP_ID_RTE_4                                    (204U)
#define COMP_ID_RTE_5                                    (205U)
#define COMP_ID_RTE_6                                    (206U)
#define COMP_ID_RTE_7                                    (207U)
#define COMP_ID_RTE_8                                    (208U)
#define COMP_ID_RTE_9                                    (209U)
#define COMP_ID_RTE_10                                   (210U)
#define COMP_ID_RTE_11                                   (211U)
#define COMP_ID_RTE_12                                   (212U)
#define COMP_ID_RTE_13                                   (213U)
#define COMP_ID_RTE_14                                   (214U)
#define COMP_ID_RTE_15                                   (215U)
#define COMP_ID_RTE_16                                   (216U)
#define COMP_ID_RTE_17                                   (217U)
#define COMP_ID_RTE_18                                   (218U)
#define COMP_ID_RTE_19                                   (219U)

// COMPONENT_XML_GENERATION_END *******************************************************************************

#else

static const uint8 COMP_ID_ACAL                                     =  88U; //ACAL  AutoCalibration
static const uint8 COMP_ID_ACDC                                     =  58U; //ACDC  CollisionDetectionAndClassification
static const uint8 COMP_ID_ADP                                      =   4U; //ADP AlgoSWAdapter
static const uint8 COMP_ID_ALN                                      =  19U; //ALN Alignment
static const uint8 COMP_ID_APPLDIAG                                 = 145U; //APPLDIAG  ApplicationDiagnostics                               - sub-component of Diag
static const uint8 COMP_ID_BAI                                      = 156U; //BAI BootAppInt                                                 - sub-component of MEM_Memory
static const uint8 COMP_ID_BSWM                                     =   5U; //BSWM  BasicSwModeManager
static const uint8 COMP_ID_CAL                                      =   9U; //CAL CommonACCLibrary
static const uint8 COMP_ID_CALI                                     =   6U; //CALI  Calibration                                              - sub-component of EOL_Service
static const uint8 COMP_ID_CANIF                                    = 136U; //CANIF CanInterface                                             - sub-component of ComStk
static const uint8 COMP_ID_CANNM                                    =  14U; //CANNM CanNetworkManagement                                     - sub-component of ComStk
static const uint8 COMP_ID_CANSM                                    =  15U; //CANSM CanStateManager                                          - sub-component of ComStk
static const uint8 COMP_ID_CANTP                                    =  16U; //CANTP CanTransportProtocol                                     - sub-component of ComStk
static const uint8 COMP_ID_CANTSYNC                                 =  17U; //ANTSYNC CanTimeSync                                            - sub-component of ComStk
static const uint8 COMP_ID_CB                                       =  71U; //CB  CameraBlockage
// static const uint8 COMP_ID_CC                                       = TBD //CC Classification Consolidation
static const uint8 COMP_ID_CCT                                      =  10U; //CCT CommonCameraToolbox
static const uint8 COMP_ID_CHIPS                                    =  73U; //CHIPS CommonHWAcceleratedImgProcSys
static const uint8 COMP_ID_CIPP                                     =  70U; //CIPP  CommonImagePreProcessing
static const uint8 COMP_ID_CML                                      =  11U; //CML CommonMathLibrary
static const uint8 COMP_ID_COF                                      =  13U; //COF RadarCameraObjectFusion
static const uint8 COMP_ID_COM                                      =  22U; //COM Communication                                              - sub-component of ComStk
static const uint8 COMP_ID_COMM                                     =  20U; //COMM  CommunicationManager                                     - sub-component of ComStk
static const uint8 COMP_ID_COMXF                                    =  21U; //COMXF ComTransformer                                           - sub-component of ComStk
static const uint8 COMP_ID_CROSS                                    =  42U; //CROSS CustomerObjSelSide
static const uint8 COMP_ID_CRY                                      =  46U; //CRY CryptographicLibrary                                       - sub-component of Crypto
static const uint8 COMP_ID_CRYIF                                    =  43U; //CRYIF CryptoInterface                                          - sub-component of Crypto
static const uint8 COMP_ID_CRYPTO                                   =  44U; //CRYPTO  CryptoDriver                                           - sub-component of Crypto
static const uint8 COMP_ID_CRYSHE                                   =  45U; //CRYSHE  CryptographicSecureHwExtension                         - sub-component of Crypto
static const uint8 COMP_ID_CSI                                      = 154U; //CSI CameraSerialInterface                                      - sub-component of Mcal
static const uint8 COMP_ID_CSM                                      =  47U; //CSM CryptoServiceManager                                       - sub-component of Crypto
static const uint8 COMP_ID_CTA                                      =  48U; //CTA CrossTrafficAssist
static const uint8 COMP_ID_CTB                                      =  49U; //CTB CrossTrafficBraking
static const uint8 COMP_ID_DAP                                      = 120U; //DAP RadarDataProcessing
static const uint8 COMP_ID_DAPVEH                                   = 247U; //DAPVEH RadarDataProcessingVehicle
static const uint8 COMP_ID_DB                                       =  50U; //DB  InterProcessorCommunicationDatabase
static const uint8 COMP_ID_DCM                                      =  51U; //DCM DiagnosticCommunicationManager                             - sub-component of Diag
static const uint8 COMP_ID_DEM                                      = 140U; //DEM DiagnosticEventManager                                     - sub-component of ErrMgt
static const uint8 COMP_ID_DET                                      = 139U; //DET DefaultErrorTracer
static const uint8 COMP_ID_DGM                                      =  84U; //DGM DegradationManager                                         - sub-component of ErrMgt
static const uint8 COMP_ID_DLT                                      =  52U; //DLT DiagnosticLogAndTrace                                      - sub-component of Diag
static const uint8 COMP_ID_DoIP                                     =  23U; //DoIP  DiagnosticOverIP                                         - sub-component of ComStk
static const uint8 COMP_ID_DPC                                      = 220U; //DPC DataProcessingControl                                      - sub-component of RadarCdd
static const uint8 COMP_ID_CDR                                      = 189U; //DPUCDR  CrashDataRecorder
static const uint8 COMP_ID_DPUCOM                                   =  53U; //DPUCOM  Communication
static const uint8 COMP_ID_DPUEDP                                   =  54U; //DPUEDP  EmbeddedDevelopmentPlatform
static const uint8 COMP_ID_DPUFF                                    =  55U; //DPUFF FunctionsFramework
static const uint8 COMP_ID_DPUHWIF                                  =  56U; //DPUHWIF HardwareInterface
static const uint8 COMP_ID_DPUIA                                    =  57U; //DPUIA ImageAcquisition                                         - sub-component of DpuImaging
static const uint8 COMP_ID_DPUINFRA                                 = 186U; //DPUINFRA  Infrastructure
static const uint8 COMP_ID_DPUOS                                    = 193U; //DPUOS DPUOperatingSystem                                       - sub-component of Os
static const uint8 COMP_ID_DPUSBL                                   = 181U; //DPUSBL  SecondaryBootloader
static const uint8 COMP_ID_DPUSERVICE                               = 176U; //DPUSERVICE  Services
static const uint8 COMP_ID_DPUST                                    = 177U; //DPUST SelfTest
static const uint8 COMP_ID_DRP                                      =  59U; //DRP DigitalRadarSignalProcessing
static const uint8 COMP_ID_EA                                       = 159U; //EA  EEPROMAbstraction                                          - sub-component of MEM_Memory
static const uint8 COMP_ID_EC                                       =  62U; //EC  RadarEnvironmentClassification
static const uint8 COMP_ID_ECM                                      =  72U; //ECM EOLCalibrationMono
static const uint8 COMP_ID_ECUM                                     =  66U; //ECUM  EcuManager
static const uint8 COMP_ID_ECUOMC                                   =  61U; //ECUOMC  EcuOperationModeControl
static const uint8 COMP_ID_EEP                                      = 157U; //EEP EepromDriver                                               - sub-component of MEM_Memory
static const uint8 COMP_ID_EMLIB                                    =  63U; //EMLIB RadarEMLibrary
static const uint8 COMP_ID_EM_CAM                                   =  60U; //EM  CameraEnvironmentModel
static const uint8 COMP_ID_EM_RAD360                                =  67U; //EM  Radar360EnvironmentModel
static const uint8 COMP_ID_EM_RAD_FRAME                             =  77U; //EM  RadarEnvironmentModelFrame
static const uint8 COMP_ID_ETHIF                                    =  24U; //ETHIF EthernetInterface                                        - sub-component of ComStk
static const uint8 COMP_ID_ETHSM                                    =  25U; //ETHSM EthernetStateManager                                     - sub-component of ComStk
static const uint8 COMP_ID_ETHTSYN                                  =  26U; //ETHTSYN TimeSyncOverEthernet                                   - sub-component of ComStk
static const uint8 COMP_ID_EVSADC                                   =  89U; //EVSADC  EVSAnalogDigitalConversion
static const uint8 COMP_ID_EVSCAN                                   =  96U; //EVSCAN  EcuValidationSoftwareCAN
static const uint8 COMP_ID_EVSFP                                    = 244U; //EVSFP EcuValidationSoftwareFactoryProtocol
static const uint8 COMP_ID_EVSSPI                                   = 103U; //EVSSPI  EVSSerialPeripheralInterface
static const uint8 COMP_ID_EVSTP                                    = 243U; //EVSTP EcuValidationSoftwareTransportProtocol
static const uint8 COMP_ID_FAMO                                     =  87U; //FAMO  FunctionalSafetyAlgoMonitor
static const uint8 COMP_ID_FCT                                      =   3U; //FCT Function
static const uint8 COMP_ID_FCTS                                     = 107U; //FCTS  SideFunctions
static const uint8 COMP_ID_FCU                                      = 101U; //FCU FunctionControlUnit
static const uint8 COMP_ID_FEE                                      = 158U; //FEE FlashEEPROMEmulation                                       - sub-component of MEM_Memory
static const uint8 COMP_ID_FIM                                      = 141U; //FIM FunctionInhibitionManager                                  - sub-component of ErrMgt
static const uint8 COMP_ID_FLSP                                     = 161U; //FLSP  FlashParameters                                          - sub-component of MEM_Memory
static const uint8 COMP_ID_FPS                                      = 241U; //FPS RadarFunctionPreSelection
static const uint8 COMP_ID_FROOP                                    = 242U; //FROOP FrontRadOncomObjPreAssess
static const uint8 COMP_ID_FRS                                      =  30U; //FRS FreeSpace
static const uint8 COMP_ID_FS                                       = 112U; //FS  FreeSpace
static const uint8 COMP_ID_FSG                                      = 171U; //FSG FeeSafeGuard                                               - sub-component of MEM_Memory
static const uint8 COMP_ID_GEOS                                     = 248U; //GEOS GeometricSegmentation
static const uint8 COMP_ID_GEN                                      = 105U; //GEN GeneralObjectDetection
static const uint8 COMP_ID_GFRS                                     = 246U; //GFRS GridBasedFreespace
static const uint8 COMP_ID_GIN                                      = 113U; //GIN GraphicalInference
static const uint8 COMP_ID_GP                                       = 121U; //GP  RadarGridProcessing
static const uint8 COMP_ID_GRAPPA                                   = 106U; //GRAPPA GenericRedvinePictureAnalysis
static const uint8 COMP_ID_GS                                       =  74U; //GS  GlobalScheduler
static const uint8 COMP_ID_GSM                                      =  97U; //GSM GroundSurfaceModel
static const uint8 COMP_ID_GSS                                      = 114U; //GSS GenericSceneSegmentation
static const uint8 COMP_ID_HEAT                                     = 134U; //HEAT  HeaterControl
static const uint8 COMP_ID_HLA                                      =   7U; //HLA HeadLightAssist
static const uint8 COMP_ID_HMI                                      = 115U; //HMI HumanMachineInterface
static const uint8 COMP_ID_HOMON                                    = 221U; //HOMON HomologationMonitor                         - sub-component of RadarCdd
static const uint8 COMP_ID_IC                                       =  12U; //DPUIC ImagerControl                                            - sub-component of DpuImaging
static const uint8 COMP_ID_INFOBLOCK                                = 179U; //INFOBLOCK InformationBlock                                     - sub-component of MEM_Memory
static const uint8 COMP_ID_IOB                                      =  78U; //IOB ImageOverBus                                               - sub-component of EOL_Service
static const uint8 COMP_ID_IOHWAB                                   = 116U; //IOHWAB  IoHwAbstractionLayer                                   - sub-component of IoHwAb
static const uint8 COMP_ID_IPC_IUC                                  = 132U; //IPC InterProcessorCommunication
static const uint8 COMP_ID_ISC                                      = 118U; //ISC InterfaceAndStateCoordinator
static const uint8 COMP_ID_ISP                                      = 245U; //ISP ImageSignalProcessor
static const uint8 COMP_ID_ITC                                      = 123U; //ITC InterTaskCommunication
static const uint8 COMP_ID_KFC                                      = 251U; //KFC  KeyFrameCaddy
static const uint8 COMP_ID_LBS                                      = 124U; //LBS LateralBlindSpot
static const uint8 COMP_ID_LCF_VEH                                  =  90U; //LCF LateralControlFunctions
static const uint8 COMP_ID_LD                                       =  75U; //LD  LaneDetection
static const uint8 COMP_ID_LMK                                      = 125U; //LMK LandMarks
static const uint8 COMP_ID_LOCC                                     = 126U; //LOCC  LongitudinalCruiseControl
static const uint8 COMP_ID_LODMC                                    = 127U; //LODMC LongitudinalDynamicMotionControl
static const uint8 COMP_ID_LOHP                                     = 135U; //LOHP  LongitudinalHeadwayPlanner
static const uint8 COMP_ID_LOPC                                     = 131U; //LOPC  LongitudinalPlannerAndController
static const uint8 COMP_ID_LSD                                      =  92U; //LSD LightSourceDetection
static const uint8 COMP_ID_MAP                                      =   8U; //MAP MapDataProvider
static const uint8 COMP_ID_MCAL                                     = 148U; //MCAL  MicroControllerAbstractionLayer                          - sub-component of Mcal
static const uint8 COMP_ID_MCU                                      = 144U; //MCU MicroControllerUnit                                        - sub-component of Mcal
static const uint8 COMP_ID_MEDIC                                    = 155U; //MEDIC InterventionControl
static const uint8 COMP_ID_MEMIF                                    = 180U; //MEMIF MemoryAbstractionInterface                               - sub-component of MEM_Memory
static const uint8 COMP_ID_MEMMAP                                   = 182U; //MEMMAP  MemoryMap                                              - sub-component of MEM_Memory
static const uint8 COMP_ID_MEMO                                     =  85U; //MEMO  MonoEgomotion
static const uint8 COMP_ID_MINOS                                    = 194U; //MINOS MiniOperatingSystem                                      - sub-component of Os
// static const uint8 COMP_ID_MOS                                      = TBD //MOS Model Output Selection
static const uint8 COMP_ID_MTSI                                     = 133U; //MTSI  MTSInterface
static const uint8 COMP_ID_NM                                       =  27U; //NM  NetworkManagementInterface                                 - sub-component of ComStk
static const uint8 COMP_ID_NVM                                      = 130U; //NVM NonVolatileMemory                                          - sub-component of MEM_Memory
static const uint8 COMP_ID_NVMADAP                                  = 187U; //NVMAD NonVolMemAdap                                            - sub-component of MEM_Memory
static const uint8 COMP_ID_NVMADMIN                                 = 184U; //NVMAD NonVolatileMemoryAdministration                          - sub-component of MEM_Memory
static const uint8 COMP_ID_OD                                       = 122U; //OD  RadarObjectDescription
static const uint8 COMP_ID_ODPP                                     = 188U; //ODPP  RadarDetectionHistoryProcessingHP
static const uint8 COMP_ID_OG                                       = 191U; //OG  OccupancyGrid
// static const uint8 COMP_ID_OOC                                      = TBD //OOC Object and Obstruction Classification
static const uint8 COMP_ID_OS                                       = 129U; //OS  OperatingSystem                                            - sub-component of Os
static const uint8 COMP_ID_PC                                       = 108U; //PC  PatchCorrelator
static const uint8 COMP_ID_PCA                                      =  95U; //PCA PointCloudAlgorithm
static const uint8 COMP_ID_PCC                                      = 195U; //PCC RadarPedestrianCyclistClassification
static const uint8 COMP_ID_PD                                       = 196U; //PD  RadarPerformanceDegradation
static const uint8 COMP_ID_PDM                                      =  98U; //PDM PerformanceDegradationModule
static const uint8 COMP_ID_PDUR                                     =  28U; //PDUR  PDURouter                                                - sub-component of ComStk
static const uint8 COMP_ID_PFC                                      =  86U; //PFC PowerFlowComputation
static const uint8 COMP_ID_PMA                                      = 153U; //PMA PostMortemAnalysis
static const uint8 COMP_ID_PMC                                      = 197U; //PMC PowerModeControl
static const uint8 COMP_ID_POC                                      =  99U; //POC POintcloudCorrespondences
static const uint8 COMP_ID_PROD                                     =  79U; //PROD  ProductionXCPServices                                    - sub-component of EOL_Service
static const uint8 COMP_ID_PSB                                      = 198U; //PSB PotholeAndSpeedBump
static const uint8 COMP_ID_PSC                                      = 117U; //PSC PowerSupplyCircuit                                         - sub-component of IoHwAb
static const uint8 COMP_ID_PVS                                      = 199U; //PVS       PavementSigns
static const uint8 COMP_ID_QSF                                      = 149U; //QSF QuadSpiFlash                                               - sub-component of Mcal
// static const uint8 COMP_ID_RADI                                     = TBD //RADI  Radar Detection Image
static const uint8 COMP_ID_RCG                                      = 223U; //RCG RadarClusterGenerator
static const uint8 COMP_ID_RC1                                      = 253U; //RC1  Road Classification 1
static const uint8 COMP_ID_RC2                                      = 254U; //RC2  Road Classification 2
static const uint8 COMP_ID_RD                                       = 224U; //RD  RadarRoadDescription
// static const uint8 COMP_ID_RDT                                      = TBD //RDT Radar Detection Tracker
static const uint8 COMP_ID_RDPC                                     = 222U; //RDPC  RawDataProcessingControl                                 - sub-component of RadarCdd
static const uint8 COMP_ID_RDBC                                     = 249U; //RDBC  RoadDataBaseClient
static const uint8 COMP_ID_RFCOM                                    = 146U; //RFCOM RadioFrequencyCommunication
static const uint8 COMP_ID_RHC                                      =  65U; //RHC RadarHardwareControl
static const uint8 COMP_ID_RHCTI                                    = 225U; //RHCTI RadarHardwareControlTi
// static const uint8 COMP_ID_RIC                                      = TBD //RIC Road Infrastructure Classification
// static const uint8 COMP_ID_RMP1                                     = TBD //RMP Radar Motion Properties
// static const uint8 COMP_ID_RMP2                                     = TBD //RMP Radar Motion Properties
// static const uint8 COMP_ID_RMHT                                     = TBD //RMHT Radar Multi Hypothesis Tracker
// static const uint8 COMP_ID_RPM1                                     = TBD //RPM1 Radar Performance Monitoring 1
// static const uint8 COMP_ID_RPM2                                     = TBD //RPM2 Radar Performance Monitoring 2
// static const uint8 COMP_ID_RPP                                      = TBD //RPP
static const uint8 COMP_ID_RSP                                      =  64U; //RSP RadarSignalProcessing
static const uint8 COMP_ID_RTA                                      = 147U; //RTA RealTimeAnalysis
static const uint8 COMP_ID_RTE                                      = 200U; //RTE RealTimeEnvironment
static const uint8 COMP_ID_RTL                                      = 138U; //RTL RealTimeLogging
static const uint8 COMP_ID_RUM                                      =  93U; //RUM RoadUserMeasurements
static const uint8 COMP_ID_SAP                                      = 226U; //SAP SystemAnalysisAndProfiling
static const uint8 COMP_ID_SCTL                                     = 143U; //SCTL  SensorControl
static const uint8 COMP_ID_SD                                       =  29U; //SD  ServiceDiscovery                                           - sub-component of ComStk
static const uint8 COMP_ID_SECOC                                    = 227U; //SECOC SecureOnboardCommunication
// static const uint8 COMP_ID_SEP1                                     = TBD //SEP Static Environment Properties
// static const uint8 COMP_ID_SEP2                                     = TBD //SEP Static Environment Properties
static const uint8 COMP_ID_SLATE                                    = 230U; //SLATE SituationLaneAssociationTrajectoryEstimation
static const uint8 COMP_ID_SLATE1                                   = 228U; //SLATE1  SituationLaneAssociationTrajectoryEstimation1
static const uint8 COMP_ID_SLATE2                                   = 229U; //SLATE2  SituationLaneAssociationTrajectoryEstimation2
static const uint8 COMP_ID_SOAD                                     =  31U; //SOAD  SocketAdapter                                            - sub-component of ComStk
static const uint8 COMP_ID_SOMEIPXF                                 =  32U; //SOMEIPXF  SomeIpTransformer                                    - sub-component of ComStk
static const uint8 COMP_ID_SPM                                      = 231U; //SPM SensorPerformanceMonitoring
static const uint8 COMP_ID_SPT_SIM                                  = 232U; //SPT SignalProcessingToolbox Simulation Data
static const uint8 COMP_ID_SPT_RAWDATA                              = 232U; //SPT SignalProcessingToolbox Raw (HW) Data
static const uint8 COMP_ID_SR                                       =  80U; //SR  SignRecognition
// static const uint8 COMP_ID_SRP1                                     = TBD //SRP Spatial and Relation Properties
// static const uint8 COMP_ID_SRP2                                     = TBD //SRP Spatial and Relation Properties
static const uint8 COMP_ID_SSA                                      = 233U; //SSA StandardSecurityArchitecture
static const uint8 COMP_ID_ST                                       = 235U; //ST  SelfTest
static const uint8 COMP_ID_STARTUP                                  = 234U; //STARTUP Startup
static const uint8 COMP_ID_STBM                                     = 237U; //STBM  SynchronizedTimeBaseManager                              - sub-component of Sys
static const uint8 COMP_ID_SWHIL                                    = 236U; //SWHIL HWInLoop
static const uint8 COMP_ID_SYS                                      = 128U; //SYS SystemServices                                             - sub-component of Sys
static const uint8 COMP_ID_TCPIP                                    =  40U; //TCPIP TcpIp                                                    - sub-component of ComStk
static const uint8 COMP_ID_TLR                                      = 119U; //TLR TrafficLightRecognition
static const uint8 COMP_ID_TP                                       =   1U; //TP  TrafficParticipants
// static const uint8 COMP_ID_TRJPLN                                   = TBD //TRJPLN
// static const uint8 COMP_ID_TRJCTR                                   = TBD //TRJCTR
static const uint8 COMP_ID_TSA                                      =  81U; //TSA TrafficSignAssist
static const uint8 COMP_ID_TST                                      = 238U; //TST TestStimuli
static const uint8 COMP_ID_UDPNM                                    =  41U; //UDPNM UDPNetworkManagement                                     - sub-component of ComStk
static const uint8 COMP_ID_UDW                                      =  94U; //UDW UnsteadyDrivingWarning
static const uint8 COMP_ID_VC                                       = 240U; //VC  RadarVehicleClassification
static const uint8 COMP_ID_VCS                                      = 239U; //VCS VariantCodingServices
static const uint8 COMP_ID_VDY                                      =   2U; //VDY VehicleDynamics
static const uint8 COMP_ID_VODCA                                    = 111U; //VODCA VisObjDetClaAlgo
static const uint8 COMP_ID_XCP                                      = 137U; //XCP UniversalCalibrationProtocol                               - sub-component of ComStk
static const uint8 COMP_ID_ZIPWIRE                                  = 150U; //ZIPWIRE ZipWire                                                - sub-component of Mcal
// The following componentIDs have to be checked if they are really needed.
// Either there is no mainstream component available, or they can be mapped to any mainstream component above.
// There are also IDs of PseudoComponents which can be avoided in near future maybe.                        
static const uint8 COMP_ID_MON                                      = 142U; //Can it be assigned to COMP_ID_DGM or COMP_ID_DPUST ?
static const uint8 COMP_ID_EXTERNAL                                 = 151U; //Used in imr_scheduler and imr_service -> part of DPUSERVICE?
static const uint8 COMP_ID_FCT60                                    =  18U; //The same like FCT?
static const uint8 COMP_ID_EMO                                      = 104U; //The same like MEMO ??
static const uint8 COMP_ID_ET                                       = 152U; //Used in event_transceiver -> part of DUFF?
static const uint8 COMP_ID_LCF_SEN                                  =  91U; //The same like LCF?
static const uint8 COMP_ID_IPC_DPU_RX                               = 192U;
static const uint8 COMP_ID_IPC_DPU_TX                               = 250U;
static const uint8 COMP_ID_RHC2                                     =  69U; //The same like COMP_ID_RHC ?
static const uint8 COMP_ID_RSP2                                     =  68U; //The same like COMP_ID_RSP ?
static const uint8 COMP_ID_SR_A                                     =  82U; //COMP_ID_SR Shall be used as soon as dynamic taskMapping is implemented in rtaMo cct_ecu_monitor)
static const uint8 COMP_ID_SR_B                                     =  83U; //COMP_ID_SR Shall be used as soon as dynamic taskMapping is implemented in rtaMo cct_ecu_monitor)
static const uint8 COMP_ID_CUST_1                                   =  31U; //Alternative to COMP_ID_DAPVEH
static const uint8 COMP_ID_CUST_3                                   =  33U; //Alternative to COMP_ID_RD
static const uint8 COMP_ID_CUST_4                                   =  34U; //Alternative to COMP_ID_GFRS
static const uint8 COMP_ID_CUST_5                                   =  35U; //Alternative to COMP_ID_PD
static const uint8 COMP_ID_CUST_6                                   =  36U; //Alternative to COMP_ID_EC
static const uint8 COMP_ID_CUST_7                                   =  37U; //Alternative to COMP_ID_VC
static const uint8 COMP_ID_CUST_8                                   =  38U; //Alternative to COMP_ID_PCC
static const uint8 COMP_ID_CUST_9                                   =  39U; //Alternative to COMP_ID_FPS
static const uint8 COMP_ID_SW_EVE                                   = 173U; //-> part of DUFF?
static const uint8 COMP_ID_SW_EVE_ABORT                             =  76U; //-> part of DUFF?
static const uint8 COMP_ID_SW_EVE_LOCKOUT                           = 175U; //-> part of DUFF?
static const uint8 COMP_ID_SW_EVE_TRIGGER                           = 174U; //-> part of DUFF?
static const uint8 COMP_ID_SW_FH                                    = 185U; //-> can it be mapped to COMP_ID_DPUCDR  ?
static const uint8 COMP_ID_SW_GEN_ADAPT_ADAPTER                     = 160U; //-> can it be mapped to COMP_ID_DPUFF or COMP_ID_DPUST?
static const uint8 COMP_ID_SW_GEN_ADAPT_ALGO_EXEC                   = 165U; //-> can it be mapped to COMP_ID_DPUFF?
static const uint8 COMP_ID_SW_I2C                                   = 163U; //-> can it be mapped to COMP_ID_DPUIC or COMP_ID_DPUIA?
static const uint8 COMP_ID_SW_ICC                                   = 169U; //-> can it be mapped to COMP_ID_DPUCOM?
static const uint8 COMP_ID_SW_ICC_EVE                               = 190U; //-> can it be mapped to COMP_ID_DPUFF or COMP_ID_DPUINFRA?
static const uint8 COMP_ID_SW_INIT                                  = 178U; //-> can it be mapped to COMP_ID_DPUINFRA or COMP_ID_DPUSERVICE?
static const uint8 COMP_ID_SW_MDB                                   = 183U; //-> can it be mapped to COMP_ID_DPUFF?
static const uint8 COMP_ID_SW_MEM_SERVICE                           = 164U; //-> can it be mapped to COMP_ID_DPUSERVICE?
static const uint8 COMP_ID_SW_MONITORS                              = 172U; //-> can it be mapped to COMP_ID_DPUST?
static const uint8 COMP_ID_SW_MTS                                   = 170U; //-> can it be mapped to COMP_ID_MTSI?
static const uint8 COMP_ID_SW_SYSCLOCK                              = 166U; //-> can it be mapped to COMP_ID_DPUSERVICE?
static const uint8 COMP_ID_SW_EVT_MARKER                            = 162U; //-> PseudoComponentID
static const uint8 COMP_ID_EVENTS_IUC                               = 100U; //-> PseudoComponentID
static const uint8 COMP_ID_SW_HWI                                   = 167U; //-> PseudoComponentID
static const uint8 COMP_ID_SW_SWI                                   = 168U; //-> PseudoComponentID
static const uint8 COMP_ID_LEMO                                     = 109U; //mainstream component?
static const uint8 COMP_ID_LIQOR                                    = 110U; //mainstream component?
//PseudoComponentIDs for free usage in RTE.                                                          
// They are needed for now, maybe it will be possible in future to map all of them to COMP_ID_RTE    
static const uint8 COMP_ID_RTE_1                                    = 201U;
static const uint8 COMP_ID_RTE_2                                    = 202U;
static const uint8 COMP_ID_RTE_3                                    = 203U;
static const uint8 COMP_ID_RTE_4                                    = 204U;
static const uint8 COMP_ID_RTE_5                                    = 205U;
static const uint8 COMP_ID_RTE_6                                    = 206U;
static const uint8 COMP_ID_RTE_7                                    = 207U;
static const uint8 COMP_ID_RTE_8                                    = 208U;
static const uint8 COMP_ID_RTE_9                                    = 209U;
static const uint8 COMP_ID_RTE_10                                   = 210U;
static const uint8 COMP_ID_RTE_11                                   = 211U;
static const uint8 COMP_ID_RTE_12                                   = 212U;
static const uint8 COMP_ID_RTE_13                                   = 213U;
static const uint8 COMP_ID_RTE_14                                   = 214U;
static const uint8 COMP_ID_RTE_15                                   = 215U;
static const uint8 COMP_ID_RTE_16                                   = 216U;
static const uint8 COMP_ID_RTE_17                                   = 217U;
static const uint8 COMP_ID_RTE_18                                   = 218U;
static const uint8 COMP_ID_RTE_19                                   = 219U;

#endif

// **************************************************************************************************************
// The starting point of the virtualAddressRanges for each component*********************************************
// **************************************************************************************************************

#ifndef __cplusplus

#define VIRT_ADDR_START_ACAL                                    (0x31900000uL) //EndAddress: 0x319FFFFF;
#define VIRT_ADDR_START_ACDC                                    (0x20360000uL) //EndAddress: 0x2036FFFF;
#define VIRT_ADDR_START_ADP                                     (0x20400000uL) //EndAddress: 0x20400FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_ALN                                     (0x20500000uL) //EndAddress: 0x20537FFF           Second range: 0x20803000 - 20804FFF                                                                                                                                             ;
#define VIRT_ADDR_START_APPLDIAG                                //Currently no measFreezes??.....;
#define VIRT_ADDR_START_BAI                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_BSWM                                    (0x20390000uL) //EndAddress: 0x2039FFFF                                                                                                                                                                                                                 ;
#define VIRT_ADDR_START_CAL                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CALI                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CANIF                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CANNM                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CANSM                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CANTP                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CANTSYNC                                //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CB                                      (0x20090000uL) //EndAddress: 0x2009FFFF;
#define VIRT_ADDR_START_CC                                      (0x41300000uL) //EndAddress: 0x413FFFFF;
#define VIRT_ADDR_START_CCT                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CHIPS                                   (0x30000000uL) //EndAddress: 0x300FFFFF;
#define VIRT_ADDR_START_CIPP                                    (0x30500000uL) //EndAddress: 0x305FFFFF;
#define VIRT_ADDR_START_CML                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_COF                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_COM                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_COMM                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_COMXF                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CROSS                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CRY                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CRYIF                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CRYPTO                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CRYSHE                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CSI                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CSM                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CTA                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CTB                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DAP                                     (0x40000000uL) //EndAddress: 0x40010FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_DAPVEH                                  (0x40A00000uL) //EndAddress: 0x40A001FF (same address is used for FROOP as well);
#define VIRT_ADDR_START_DB                                      //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DCM                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DEM                                     (0x80090000uL) //EndAddress: 0x80095FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_DET                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DGM                                     (0x80096000uL) //EndAddress: 0x80098FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_DLT                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DoIP                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DPC                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_CDR                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DPUCOM                                  (0x820e6000uL) //"EndAddress: 0x820ec0FF        Other ranges: 0x820fd800 - 0x820fd8FF; 0x8211f000 - 0x8211f0ff                                                                                                                     ";
#define VIRT_ADDR_START_DPUEDP                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DPUFF                                   (0x8208f000uL) //"EndAddress: 0x82093FFF        Other ranges: 0x820c0000 - 0x820c00FF; 0x0x820c4000 - 0x820c40FF; 0x820c0800 - 0x820c080FF; 0x820c0a00 - 0x820c0a0FF; 0x820e2000 - 0x820e20FF; 0x820e4000 - 0x820e40FF             ";
#define VIRT_ADDR_START_DPUHWIF                                 //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DPUIA                                   (0x82156000uL) //EndAddress: 0x821568FF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_DPUINFRA                                (0x82016000uL) //"EndAddress: 0x82019FFF        Other ranges: 0x82094000 - 0x820940FF; 0x82117000 - 0x82117FFF; 0x82154000 - 0x82154FFF; 0x83002000 - 0x830020FF                                                                   ";
#define VIRT_ADDR_START_DPUOS                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DPUSBL                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_DPUSERVICE                              (0x82000000uL) //"EndAddress: 0x82002FFF        Other ranges: 0x82051000 - 0x820510FF; 0x82065000 - 0x820650FF; 0x8211d000 - 0x8211ecff                                                                                            ";
#define VIRT_ADDR_START_DPUST                                   (0x8201e800uL) //EndAddress: 0x8201e8FF        Other ranges: 0x82130000 - 0x82142FFF                                                                                                                                              ;
#define VIRT_ADDR_START_DRP                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EA                                      //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EC                                      (0x40300000uL) //EndAddress: 0x40302FFF                                                                                                                                                                                         ;
#define VIRT_ADDR_START_ECM                                     (0x30F00000uL) //EndAddress: 0x30FFFFFF                                                                                                                                                                                         ;
#define VIRT_ADDR_START_ECUM                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_ECUOMC                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EEP                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EMLIB                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EM_CAM                                  (0x20100000uL) //EndAddress: 0x201FFFFF;
#define VIRT_ADDR_START_EM_RAD360                               //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EM_RAD_FRAME                            (0x20001000uL) //"  EndAddress: 0x2000FFFF    Other ranges: 0x20112100 - 0x201FFFFF; 0x70010000 - 0x7001019F; 0x700a6000 -  0x700AAAAA; 0x700C8FA0 - 0x700C9400;                                                                   ";
#define VIRT_ADDR_START_ETHIF                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_ETHSM                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_ETHTSYN                                 //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EVSADC                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EVSCAN                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EVSFP                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EVSSPI                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EVSTP                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_FAMO                                    (0x31800000uL) //EndAddress: 0x318FFFFF;
#define VIRT_ADDR_START_FCT                                     (0x20200000uL) //"EndAddress: 0x202FFFFF       other ranges: 0x20200000 - 0x202FFFFF; 0x205400d8 - 0x205400FF; 0x20900000 - 0x209001FF; 0x82150a00 - 0x82150aff; 0x83000000 - 830000FF                                             ";
#define VIRT_ADDR_START_FCTS                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_FCU                                     (0x3351000uL) //EndAddress: 0x3355FFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_FEE                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_FIM                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_FLSP                                    (0x80720000uL) //EndAddress: 0x80730FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_FPS                                     (0x40900000uL) //EndAddress: 0x40909FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_FROOP                                   (0x40A00000uL) //EndAddress: 0x40A0FFFF                                                                                                                                                                                ;
#define VIRT_ADDR_START_FRS                                     (0x40800000uL) //EndAddress: 0x40801FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_FS                                      (0x41A00000uL) //EndAddress: 0x41AFFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_FSG                                     (0x80070000uL) //EndAddress:                                                                                                                                                                                                      ;
#define VIRT_ADDR_START_GEOS                                    (0x31500000uL) //EndAddress: 0x315FFFFF;
#define VIRT_ADDR_START_GEN                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_GFRS                                    (0x40800000uL) //EndAddress: 0x40802FFF (same address is used for FRS as well);
#define VIRT_ADDR_START_GIN                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_GP                                      (0x40100000uL) //EndAddress: 0x401FFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_GRAPPA                                  (0x31300000uL) //EndAddress: 0x313FFFFF;
#define VIRT_ADDR_START_GS                                      (0x31180000uL) //EndAddress: 0x31190FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_GSM                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_GSS                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_HEAT                                    (0x80060000uL) //EndAddress: 0x80060FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_HLA                                     (0x31200000uL) //EndAddress: 0x312FFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_HMI                                     (0x20970000uL) //EndAddress: 0x2097FFFF                                                                                                                                                                                                            ;
#define VIRT_ADDR_START_HOMON                                   (0x31500000uL) //EndAddress: 0x3151FFFF                                                                                                                                                                                                               ;
#define VIRT_ADDR_START_IC                                      (0x200b0000uL) //"EndAddress: 0x200b4FFF       Other ranges: 0x82150000 - 0x821500FF; 0x30010000 - 0x300103FF                                                                                                                      ";
#define VIRT_ADDR_START_INFOBLOCK                               (0x80080000uL) //EndAddress: 0x800800FF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_IOB                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_IOHWAB                                  (0x209A0000uL) //End Address: 0x209AFFFF                  ;
#define VIRT_ADDR_START_IPC_IUC                                 (0x820f5000uL) //"EndAddress: 0x820fc0FF       Other ranges: 0x8211a000 - 8211a0FF; 0x82150800 - 821509FF; 0x82156900 - 0x82157FFF; 0x83001000 - 0x830010FF; 0x83003000 - 0x830030FF                                               ";
#define VIRT_ADDR_START_ISC                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_ISP                                     (0x30900000uL) //EndAddress: 0x309FFFFF       Former range of SAC;
#define VIRT_ADDR_START_ITC                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_KFC                                     (0x32800000uL) //EndAddress: 0x328FFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_LBS                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_LCF_VEH                                 (0x32100000uL) //EndAddress: 0x32202FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_LD                                      (0x30E00000uL) //EndAddress: 0x30EFFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_LMK                                     (0x31000000uL) //EndAddress: 0x310FFFFF                                                                                                                                                                                              ;
#define VIRT_ADDR_START_LOCC                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_LOCTR                                   (0x20D20000uL) //EndAddress: 0x20D2FFFF ;
#define VIRT_ADDR_START_LODMC                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_LOHP                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_LOPC                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_LOPLN                                   (0x20D10000uL) //EndAddress: 0x20D1FFFF ;
#define VIRT_ADDR_START_LSD                                     (0x32300000uL) //EndAddress: 0x323FFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_MAP                                     (0x32000000uL) //EndAddress: 0x32001FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_MCAL                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_MCU                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_MEDIC                                   (0x20A50000uL) //EndAddress: 0x20A5FFFF                                                                                                                                                                                             ;
#define VIRT_ADDR_START_MEMIF                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_MEMMAP                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_MEMO                                    (0x30B00000uL) //EndAddress: 0x30BFFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_MINOS                                   (0x800d0000uL) //EndAddress: 0x800D02D3  !!!!!Conflict with FS!!! Only in ARS441!!!!!!!!!                                                                                                                                         ;
#define VIRT_ADDR_START_MOS                                     (0x41400000uL) //EndAddress: 0x414FFFFF;
#define VIRT_ADDR_START_MTSI                                    (0x80050500uL) //"EndAddress: 0x80053FFF       other ranges: 0x82005000 - 0x8200BFFF; 0x820e1000 - 0x820e10FF; 0x82143800 - 82143dff; 0x82143f00 - 0x82143fff                                                                      ";
#define VIRT_ADDR_START_NM                                      //Currently no measFreezes??.....;
#define VIRT_ADDR_START_NVM                                     (0x700a0000uL) //EndAddress: 0x702F0FFF       range partly occupied by EM but currently no overlapping                                                                                                                            ;
#define VIRT_ADDR_START_NVMADAP                                 //Currently no measFreezes??.....;
#define VIRT_ADDR_START_NVMADMIN                                (0x80030000uL) //EndAddress: 0x80030FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_OD                                      (0x40200000uL) //EndAddress: 0x40212FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_ODPP                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_OG                                      //Currently no measFreezes??.....;
#define VIRT_ADDR_START_OOC                                     (0x41100000uL) //EndAddress: 0x411FFFFF;
#define VIRT_ADDR_START_OS                                      //Currently no measFreezes??.....;
#define VIRT_ADDR_START_PC                                      (0x30300000uL) //EndAddress: 0x303FFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_PCA                                     (0x32609000uL) //EndAddress: 0x32624FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_PCC                                     (0x200f0000uL) //EndAddress: 0x200FFFFF         Second range 0x40500000 - 0x40509FFF                                                                                                                                              ;
#define VIRT_ADDR_START_PD                                      (0x40600000uL) //EndAddress: 0x40600FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_PDM                                     (0x32900000uL) //EndAddress: 0x329fffff                                                                                                                                                                                           ;
#define VIRT_ADDR_START_PDUR                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_PFC                                     (0x31400000uL) //EndAddress: 0x314FFFFF;
#define VIRT_ADDR_START_PMA                                     (0x800b0000uL) //EndAddress: 0x800B4FFF        Other ranges: 0x82146000 - 0x0x82149FFF                                                                                                                                            ;
#define VIRT_ADDR_START_PMC                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_POC                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_PROD                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_PSB                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_PSC                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_PVS                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_QSF                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_RADI                                    (0x40C00000uL) //EndAddress: 40CFFFFF;
#define VIRT_ADDR_START_RCG                                     (0x40A10000uL) //EndAddress: 0x40A10FFF                                                                                                                                                                                                                ;
#define VIRT_ADDR_START_RC1                                     (0x47F00000uL) //EndAddress: 0x47F0FFFF
#define VIRT_ADDR_START_RC2                                     (0x47F10000uL) //EndAddress: 0x47F1FFFF
#define VIRT_ADDR_START_RD                                      (0x40700000uL) //EndAddress: 0x40701FFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_RDT                                     (0x41500000uL) //EndAddress: 0x416FFFFF;
#define VIRT_ADDR_START_RDPC                                    (0x80054000uL) //EndAddress: 0x800540FF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_RDBC                                    (0x32700000uL) //EndAddress: 0x327FFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_RFCOM                                   (0x80054100uL) //EndAddress: 0x80054FFF           Second range: 0x800f4000 - 0x800f44FF                                                                                                                                           ;
#define VIRT_ADDR_START_RHC                                     (0x20600000uL) //EndAddress: 0x2078FFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_RHCTI                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_RIC                                     (0x41200000uL) //EndAddress: 0x412FFFFF;
#define VIRT_ADDR_START_RMP1                                    (0x40B00000uL) //EndAddress: 0x40BFFFFF;
#define VIRT_ADDR_START_RMP2                                    (0x40D00000uL) //EndAddress: 0x40DFFFFF;
#define VIRT_ADDR_START_RMHT                                    (0x40F00000uL) //EndAddress: 0x40FFFFFF;
#define VIRT_ADDR_START_RPM1                                    (0x47D00000uL) //EndAddress: 0x47DFFFFF;
#define VIRT_ADDR_START_RPM2                                    (0x47E00000uL) //EndAddress: 0x47EFFFFF;
#define VIRT_ADDR_START_RPP                                     (0x41900000uL) //;EndAddress: ;
#define VIRT_ADDR_START_RSP                                     (0x06000000uL) //EndAddress: 0x06b6FFFF           Second range: 0x20805000 - 20805FFF                                                                                                                                             ;
#define VIRT_ADDR_START_RTA                                     (0x80010000uL) //EndAddress: 0x8002FFFF           more ranges in use for old dp                                                                                                                                                   ;
#define VIRT_ADDR_START_RTE                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_RTL                                     (0x80040000uL) //EndAddress: 0x8004FFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_RUM                                     (0x32400000uL) //EndAddress: 0x324FFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_SAP                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SCTL                                    (0x800d1000uL) //EndAddress: 0x800d1FFF    Second range: 0x80000400 - 0x80000428 Infoblock)                                                                                                                                       ;
#define VIRT_ADDR_START_SD                                      //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SECOC                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SEP1                                    (0x40E00000uL) //EndAddress: 0x40EFFFFF;
#define VIRT_ADDR_START_SEP2                                    (0x41700000uL) //EndAddress: 0x417FFFFF;
#define VIRT_ADDR_START_SLATE                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SLATE1                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SLATE2                                  //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SOAD                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SOMEIPXF                                //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SPM                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SPT_SIM                                 (0xD0000000uL) //EndAddress: 0xD7FFFFFF;
#define VIRT_ADDR_START_SPT_RAWDATA                             (0xA0000000uL) //EndAddress: 0xA0FFFFFF;
#define VIRT_ADDR_START_SR                                      (0x30D00000uL) //EndAddress: 0x30DFFFFF;
#define VIRT_ADDR_START_SRP1                                    (0x41000000uL) //EndAddress: 0x410FFFFF;
#define VIRT_ADDR_START_SRP2                                    (0x41800000uL) //EndAddress: 0x418FFFFF;
#define VIRT_ADDR_START_SSA                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_ST                                      //Currently no measFreezes??.....;
#define VIRT_ADDR_START_STARTUP                                 //Currently no measFreezes??.....;
#define VIRT_ADDR_START_STBM                                    //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SWHIL                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_SYS                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_TCPIP                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_TLR                                     (0x31600000uL) //EndAddress: 0x316FFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_TP                                      //Currently no measFreezes??.....;
#define VIRT_ADDR_START_TRJPLN                                  (0x20D10000uL) //EndAddress: 0x20D1FFFF;
#define VIRT_ADDR_START_TRJCTR                                  (0x20D20000uL) //EndAddress: 0x20D2FFFF;
#define VIRT_ADDR_START_TSA                                     (0x31700000uL) //EndAddress: 0x317FFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_TST                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_UDPNM                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_UDW                                     (0x32500000uL) //EndAddress: 0x325FFFFF                                                                                                                                                                                           ;
#define VIRT_ADDR_START_VC                                      (0x40400300uL) //EndAddress: 0x40406FFF            Second range:  0x700101A0 - 0x70010FFF                                                                                                                                         ;
#define VIRT_ADDR_START_VCS                                     (0x20CD0000uL) //EndAddress: 0x20CDFFFF                                                                                                                                                                                                   ;
#define VIRT_ADDR_START_VDY                                     (0x20300000uL) //EndAddress: 0x203FFFFF            Second range:  0x20300000 - 0x20351FFF                                                                                                                                         ;
#define VIRT_ADDR_START_VODCA                                   //Currently no measFreezes??.....;
#define VIRT_ADDR_START_XCP                                     //Currently no measFreezes??.....;
#define VIRT_ADDR_START_ZIPWIRE                                 //Currently no measFreezes??.....;
#define VIRT_ADDR_START_EMF                                     (0x50100000uL) //EndAddress: 0x5010FFFF
#define VIRT_ADDR_START_SEF                                     (0x50110000uL) //EndAddress: 0x5014FFFF
#define VIRT_ADDR_START_EML                                     (0x50150000uL) //EndAddress: 0x5015FFFF
#define VIRT_ADDR_START_TPF                                     (0x50160000uL) //EndAddress: 0x5017FFFF
#define VIRT_ADDR_START_RMF                                     (0x50180000uL) //EndAddress: 0x5019FFFF
#define VIRT_ADDR_START_FSF                                     (0x501A0000uL) //EndAddress: 0x5021FFFF
#define VIRT_ADDR_START_PCL                                     (0x50220000uL) //EndAddress: 0x5022FFFF
#define VIRT_ADDR_START_TCI                                     (0x50230000uL) //EndAddress: 0x5023FFFF
#define VIRT_ADDR_START_COH                                     (0x50240000uL) //EndAddress: 0x5029FFFF
#define VIRT_ADDR_START_VAL                                     (0x503A0000uL) //EndAddress: 0x503DFFFF
#define VIRT_ADDR_START_SIP_ARS540                              (0x503E0000uL) //EndAddress: 0x5043FFFF
#define VIRT_ADDR_START_SIP_MFC_APTIV                           (0x50440000uL) //EndAddress: 0x5049FFFF
#define VIRT_ADDR_START_SIP_SRR_APTIV                           (0x504A0000uL) //EndAddress: 0x504FFFFF
#define VIRT_ADDR_START_SIP_EHORIZON                            (0x50500000uL) //EndAddress: 0x5050FFFF
#define VIRT_ADDR_START_SIP_OTHERS                              (0x50510000uL) //EndAddress: 0x5051FFFF
#define VIRT_ADDR_START_FDP_BASE                                (0x50520000uL) //EndAddress: 0x505BFFFF

#else

static const uint32 VIRT_ADDR_START_ACAL                                    = 0x31900000uL; //EndAddress: 0x319FFFFF;
static const uint32 VIRT_ADDR_START_ACDC                                    = 0x20360000uL; //EndAddress: 0x2036FFFF;
static const uint32 VIRT_ADDR_START_ADP                                     = 0x20400000uL; //EndAddress: 0x20400FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_ALN                                     = 0x20500000uL; //EndAddress: 0x20537FFF           Second range: 0x20803000 - 20804FFF                                                                                                                                             ;
//static const uint32 VIRT_ADDR_START_APPLDIAG                                Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_BAI                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_BSWM                                    = 0x20390000uL; //EndAddress: 0x2039FFFF                                                                                                                                                                                                                 ;
//static const uint32 VIRT_ADDR_START_CAL                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CALI                                    Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CANIF                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CANNM                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CANSM                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CANTP                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CANTSYNC                                Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_CB                                      = 0x20090000uL; //EndAddress: 0x2009FFFF;
static const uint32 VIRT_ADDR_START_CC                                      = 0x41300000uL; //EndAddress: 0x413FFFFF;
//static const uint32 VIRT_ADDR_START_CCT                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_CHIPS                                   = 0x30000000uL; //EndAddress: 0x300FFFFF;
static const uint32 VIRT_ADDR_START_CIPP                                    = 0x30500000uL; //EndAddress: 0x305FFFFF;
//static const uint32 VIRT_ADDR_START_CML                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_COF                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_COM                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_COMM                                    Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_COMXF                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CROSS                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CRY                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CRYIF                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CRYPTO                                  Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CRYSHE                                  Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CSI                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CSM                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CTA                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CTB                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_DAP                                     = 0x40000000uL; //EndAddress: 0x40010FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_DAPVEH                                  = 0x40A00000uL; //EndAddress: 0x40A001FF (same address is used for FROOP as well);
//static const uint32 VIRT_ADDR_START_DB                                      Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_DCM                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_DEM                                     = 0x80090000uL; //EndAddress: 0x80095FFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_DET                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_DGM                                     = 0x80096000uL; //EndAddress: 0x80098FFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_DLT                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_DoIP                                    Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_DPC                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_CDR                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_DPUCOM                                  = 0x820e6000uL; //"EndAddress: 0x820ec0FF        Other ranges: 0x820fd800 - 0x820fd8FF; 0x8211f000 - 0x8211f0ff                                                                                                                     ";
//static const uint32 VIRT_ADDR_START_DPUEDP                                  Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_DPUFF                                   = 0x8208f000uL; //"EndAddress: 0x82093FFF        Other ranges: 0x820c0000 - 0x820c00FF; 0x0x820c4000 - 0x820c40FF; 0x820c0800 - 0x820c080FF; 0x820c0a00 - 0x820c0a0FF; 0x820e2000 - 0x820e20FF; 0x820e4000 - 0x820e40FF             ";
//static const uint32 VIRT_ADDR_START_DPUHWIF                                 Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_DPUIA                                   = 0x82156000uL; //EndAddress: 0x821568FF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_DPUINFRA                                = 0x82016000uL; //"EndAddress: 0x82019FFF        Other ranges: 0x82094000 - 0x820940FF; 0x82117000 - 0x82117FFF; 0x82154000 - 0x82154FFF; 0x83002000 - 0x830020FF                                                                   ";
//static const uint32 VIRT_ADDR_START_DPUOS                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_DPUSBL                                  Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_DPUSERVICE                              = 0x82000000uL; //"EndAddress: 0x82002FFF        Other ranges: 0x82051000 - 0x820510FF; 0x82065000 - 0x820650FF; 0x8211d000 - 0x8211ecff                                                                                            ";
static const uint32 VIRT_ADDR_START_DPUST                                   = 0x8201e800uL; //EndAddress: 0x8201e8FF        Other ranges: 0x82130000 - 0x82142FFF                                                                                                                                              ;
//static const uint32 VIRT_ADDR_START_DRP                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_EA                                      Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_EC                                      = 0x40300000uL; //EndAddress: 0x40302FFF                                                                                                                                                                                         ;
static const uint32 VIRT_ADDR_START_ECM                                     = 0x30F00000uL; //EndAddress: 0x30FFFFFF                                                                                                                                                                                         ;
//static const uint32 VIRT_ADDR_START_ECUM                                    Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_ECUOMC                                  Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_EEP                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_EMLIB                                   Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_EM_CAM                                  = 0x20100000uL; //EndAddress: 0x201FFFFF;
//static const uint32 VIRT_ADDR_START_EM_RAD360                               Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_EM_RAD_FRAME                            = 0x20001000uL; //"  EndAddress: 0x2000FFFF    Other ranges: 0x20112100 - 0x201FFFFF; 0x70010000 - 0x7001019F; 0x700a6000 -  0x700AAAAA; 0x700C8FA0 - 0x700C9400;                                                                   ";
//static const uint32 VIRT_ADDR_START_ETHIF                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_ETHSM                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_ETHTSYN                                 Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_EVSADC                                  Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_EVSCAN                                  Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_EVSFP                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_EVSSPI                                  Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_EVSTP                                   Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_FAMO                                    = 0x31800000uL; //EndAddress: 0x318FFFFF;
static const uint32 VIRT_ADDR_START_FCT                                     = 0x20200000uL; //"EndAddress: 0x202FFFFF       other ranges: 0x20200000 - 0x202FFFFF; 0x205400d8 - 0x205400FF; 0x20900000 - 0x209001FF; 0x82150a00 - 0x82150aff; 0x83000000 - 830000FF                                             ";
//static const uint32 VIRT_ADDR_START_FCTS                                    Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_FCU                                     = 0x3351000uL; //EndAddress: 0x3355FFFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_FEE                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_FIM                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_FLSP                                    = 0x80720000uL; //EndAddress: 0x80730FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_FPS                                     = 0x40900000uL; //EndAddress: 0x40909FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_FROOP                                   = 0x40A00000uL; //EndAddress: 0x40A0FFFF                                                                                                                                                                                ;
static const uint32 VIRT_ADDR_START_FRS                                     = 0x40800000uL; //EndAddress: 0x40801FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_FS                                      = 0x41A00000uL; //EndAddress: 0x41AFFFFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_FSG                                     = 0x80070000uL; //EndAddress:                                                                                                                                                                                                      ;
static const uint32 VIRT_ADDR_START_GEOS                                    = 0x31500000uL; //EndAddress: 0x315FFFFF;
//static const uint32 VIRT_ADDR_START_GEN                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_GFRS                                    = 0x40800000uL; //EndAddress: 0x40802FFF (same address is used for FRS as well);
//static const uint32 VIRT_ADDR_START_GIN                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_GP                                      = 0x40100000uL; //EndAddress: 0x401FFFFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_GRAPPA                                  = 0x31300000uL; //EndAddress: 0x313FFFFF;
static const uint32 VIRT_ADDR_START_GS                                      = 0x31180000uL; //EndAddress: 0x31190FFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_GSM                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_GSS                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_HEAT                                    = 0x80060000uL; //EndAddress: 0x80060FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_HLA                                     = 0x31200000uL; //EndAddress: 0x312FFFFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_HMI                                     = 0x20970000uL; //EndAddress: 0x2097FFFF                                                                                                                                                                                                            ;
static const uint32 VIRT_ADDR_START_HOMON                                   = 0x31500000uL; //EndAddress: 0x3151FFFF                                                                                                                                                                                                               ;
static const uint32 VIRT_ADDR_START_IC                                      = 0x200b0000uL; //"EndAddress: 0x200b4FFF       Other ranges: 0x82150000 - 0x821500FF; 0x30010000 - 0x300103FF                                                                                                                      ";
static const uint32 VIRT_ADDR_START_INFOBLOCK                               = 0x80080000uL; //EndAddress: 0x800800FF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_IOB                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_IOHWAB                                  = 0x209A0000uL; //End Address: 0x209AFFFF                  ;
static const uint32 VIRT_ADDR_START_IPC_IUC                                 = 0x820f5000uL; //"EndAddress: 0x820fc0FF       Other ranges: 0x8211a000 - 8211a0FF; 0x82150800 - 821509FF; 0x82156900 - 0x82157FFF; 0x83001000 - 0x830010FF; 0x83003000 - 0x830030FF                                               ";
//static const uint32 VIRT_ADDR_START_ISC                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_ISP                                     = 0x30900000uL; //EndAddress: 0x309FFFFF       Former range of SAC;
//static const uint32 VIRT_ADDR_START_ITC                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_KFC                                     = 0x32800000uL; //EndAddress: 0x328FFFFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_LBS                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_LCF_VEH                                 = 0x32100000uL; //EndAddress: 0x32202FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_LD                                      = 0x30E00000uL; //EndAddress: 0x30EFFFFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_LMK                                     = 0x31000000uL; //EndAddress: 0x310FFFFF                                                                                                                                                                                              ;
//static const uint32 VIRT_ADDR_START_LOCC                                    Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_LOCTR                                   = 0x20D20000uL; //EndAddress: 0x20D2FFFF ;
//static const uint32 VIRT_ADDR_START_LODMC                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_LOHP                                    Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_LOPC                                    Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_LOPLN                                   = 0x20D10000uL; //EndAddress: 0x20D1FFFF ;
static const uint32 VIRT_ADDR_START_LSD                                     = 0x32300000uL; //EndAddress: 0x323FFFFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_MAP                                     = 0x32000000uL; //EndAddress: 0x32001FFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_MCAL                                    Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_MCU                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_MEDIC                                   = 0x20A50000uL; //EndAddress: 0x20A5FFFF                                                                                                                                                                                             ;
//static const uint32 VIRT_ADDR_START_MEMIF                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_MEMMAP                                  Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_MEMO                                    = 0x30B00000uL; //EndAddress: 0x30BFFFFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_MINOS                                   = 0x800d0000uL; //EndAddress: 0x800D02D3  !!!!!Conflict with FS!!! Only in ARS441!!!!!!!!!                                                                                                                                         ;
static const uint32 VIRT_ADDR_START_MOS                                     = 0x41400000uL; //EndAddress: 0x414FFFFF;
static const uint32 VIRT_ADDR_START_MTSI                                    = 0x80050500uL; //"EndAddress: 0x80053FFF       other ranges: 0x82005000 - 0x8200BFFF; 0x820e1000 - 0x820e10FF; 0x82143800 - 82143dff; 0x82143f00 - 0x82143fff                                                                      ";
//static const uint32 VIRT_ADDR_START_NM                                      Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_NVM                                     = 0x700a0000uL; //EndAddress: 0x702F0FFF       range partly occupied by EM but currently no overlapping                                                                                                                            ;
//static const uint32 VIRT_ADDR_START_NVMADAP                                 Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_NVMADMIN                                = 0x80030000uL; //EndAddress: 0x80030FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_OD                                      = 0x40200000uL; //EndAddress: 0x40212FFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_ODPP                                    Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_OG                                      Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_OOC                                     = 0x41100000uL; //EndAddress: 0x411FFFFF;
//static const uint32 VIRT_ADDR_START_OS                                      Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_PC                                      = 0x30300000uL; //EndAddress: 0x303FFFFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_PCA                                     = 0x32609000uL; //EndAddress: 0x32624FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_PCC                                     = 0x200f0000uL; //EndAddress: 0x200FFFFF         Second range 0x40500000 - 0x40509FFF                                                                                                                                              ;
static const uint32 VIRT_ADDR_START_PD                                      = 0x40600000uL; //EndAddress: 0x40600FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_PDM                                     = 0x32900000uL; //EndAddress: 0x329fffff                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_PDUR                                    Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_PFC                                     = 0x31400000uL; //EndAddress: 0x314FFFFF;
static const uint32 VIRT_ADDR_START_PMA                                     = 0x800b0000uL; //EndAddress: 0x800B4FFF        Other ranges: 0x82146000 - 0x0x82149FFF                                                                                                                                            ;
//static const uint32 VIRT_ADDR_START_PMC                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_POC                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_PROD                                    Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_PSB                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_PSC                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_PVS                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_QSF                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_RADI                                    = 0x40C00000uL; //EndAddress: 40CFFFFF;
static const uint32 VIRT_ADDR_START_RCG                                     = 0x40A10000uL; //EndAddress: 0x40A10FFF                                                                                                                                                                                                                ;
static const uint32 VIRT_ADDR_START_RC1                                     = 0x47F00000uL; //EndAddress: 0x47F0FFFF
static const uint32 VIRT_ADDR_START_RC2                                     = 0x47F10000uL; //EndAddress: 0x47F1FFFF
static const uint32 VIRT_ADDR_START_RD                                      = 0x40700000uL; //EndAddress: 0x40701FFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_RDT                                     = 0x41500000uL; //EndAddress: 0x416FFFFF;
static const uint32 VIRT_ADDR_START_RDPC                                    = 0x80054000uL; //EndAddress: 0x800540FF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_RDBC                                    = 0x32700000uL; //EndAddress: 0x327FFFFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_RFCOM                                   = 0x80054100uL; //EndAddress: 0x80054FFF           Second range: 0x800f4000 - 0x800f44FF                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_RHC                                     = 0x20600000uL; //EndAddress: 0x2078FFFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_RHCTI                                   Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_RIC                                     = 0x41200000uL; //EndAddress: 0x412FFFFF;
static const uint32 VIRT_ADDR_START_RMP1                                    = 0x40B00000uL; //EndAddress: 0x40BFFFFF;
static const uint32 VIRT_ADDR_START_RMP2                                    = 0x40D00000uL; //EndAddress: 0x40DFFFFF;
static const uint32 VIRT_ADDR_START_RMHT                                    = 0x40F00000uL; //EndAddress: 0x40FFFFFF;
static const uint32 VIRT_ADDR_START_RPM1                                    = 0x47D00000uL; //EndAddress: 0x47DFFFFF;
static const uint32 VIRT_ADDR_START_RPM2                                    = 0x47E00000uL; //EndAddress: 0x47EFFFFF;
static const uint32 VIRT_ADDR_START_RPP                                     = 0x41900000uL; //;EndAddress: ;
static const uint32 VIRT_ADDR_START_RSP                                     = 0x06000000uL; //EndAddress: 0x06b6FFFF           Second range: 0x20805000 - 20805FFF                                                                                                                                             ;
static const uint32 VIRT_ADDR_START_RTA                                     = 0x80010000uL; //EndAddress: 0x8002FFFF           more ranges in use for old dp                                                                                                                                                   ;
//static const uint32 VIRT_ADDR_START_RTE                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_RTL                                     = 0x80040000uL; //EndAddress: 0x8004FFFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_RUM                                     = 0x32400000uL; //EndAddress: 0x324FFFFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_SAP                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_SCTL                                    = 0x800d1000uL; //EndAddress: 0x800d1FFF    Second range: 0x80000400 - 0x80000428 Infoblock)                                                                                                                                       ;
//static const uint32 VIRT_ADDR_START_SD                                      Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_SECOC                                   Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_SEP1                                    = 0x40E00000uL; //EndAddress: 0x40EFFFFF;
static const uint32 VIRT_ADDR_START_SEP2                                    = 0x41700000uL; //EndAddress: 0x417FFFFF;
//static const uint32 VIRT_ADDR_START_SLATE                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_SLATE1                                  Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_SLATE2                                  Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_SOAD                                    Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_SOMEIPXF                                Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_SPM                                     Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_SPT_SIM                                 = 0xD0000000uL; //EndAddress: 0xD7FFFFFF;
static const uint32 VIRT_ADDR_START_SPT_RAWDATA                             = 0xA0000000uL; //EndAddress: 0xA0FFFFFF;
static const uint32 VIRT_ADDR_START_SR                                      = 0x30D00000uL; //EndAddress: 0x30DFFFFF;
static const uint32 VIRT_ADDR_START_SRP1                                    = 0x41000000uL; //EndAddress: 0x410FFFFF;
static const uint32 VIRT_ADDR_START_SRP2                                    = 0x41800000uL; //EndAddress: 0x418FFFFF;
//static const uint32 VIRT_ADDR_START_SSA                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_ST                                      Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_STARTUP                                 Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_STBM                                    Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_SWHIL                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_SYS                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_TCPIP                                   Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_TLR                                     = 0x31600000uL; //EndAddress: 0x316FFFFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_TP                                      Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_TRJPLN                                  = 0x20D10000uL; //EndAddress: 0x20D1FFFF;
static const uint32 VIRT_ADDR_START_TRJCTR                                  = 0x20D20000uL; //EndAddress: 0x20D2FFFF;
static const uint32 VIRT_ADDR_START_TSA                                     = 0x31700000uL; //EndAddress: 0x317FFFFF                                                                                                                                                                                           ;
//static const uint32 VIRT_ADDR_START_TST                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_UDPNM                                   Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_UDW                                     = 0x32500000uL; //EndAddress: 0x325FFFFF                                                                                                                                                                                           ;
static const uint32 VIRT_ADDR_START_VC                                      = 0x40400300uL; //EndAddress: 0x40406FFF            Second range:  0x700101A0 - 0x70010FFF                                                                                                                                         ;
static const uint32 VIRT_ADDR_START_VCS                                     = 0x20CD0000uL; //EndAddress: 0x20CDFFFF                                                                                                                                                                                                   ;
static const uint32 VIRT_ADDR_START_VDY                                     = 0x20300000uL; //EndAddress: 0x203FFFFF            Second range:  0x20300000 - 0x20351FFF                                                                                                                                         ;
//static const uint32 VIRT_ADDR_START_VODCA                                   Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_XCP                                     Currently no measFreezes??.....;
//static const uint32 VIRT_ADDR_START_ZIPWIRE                                 Currently no measFreezes??.....;
static const uint32 VIRT_ADDR_START_EMF                                     = 0x50100000uL; //EndAddress: 0x5010FFFF
static const uint32 VIRT_ADDR_START_SEF                                     = 0x50110000uL; //EndAddress: 0x5014FFFF
static const uint32 VIRT_ADDR_START_EML                                     = 0x50150000uL; //EndAddress: 0x5015FFFF
static const uint32 VIRT_ADDR_START_TPF                                     = 0x50160000uL; //EndAddress: 0x5017FFFF
static const uint32 VIRT_ADDR_START_RMF                                     = 0x50180000uL; //EndAddress: 0x5019FFFF
static const uint32 VIRT_ADDR_START_FSF                                     = 0x501A0000uL; //EndAddress: 0x5021FFFF
static const uint32 VIRT_ADDR_START_PCL                                     = 0x50220000uL; //EndAddress: 0x5022FFFF
static const uint32 VIRT_ADDR_START_TCI                                     = 0x50230000uL; //EndAddress: 0x5023FFFF
static const uint32 VIRT_ADDR_START_COH                                     = 0x50240000uL; //EndAddress: 0x5029FFFF
static const uint32 VIRT_ADDR_START_VAL                                     = 0x503A0000uL; //EndAddress: 0x503DFFFF
static const uint32 VIRT_ADDR_START_SIP_ARS540                              = 0x503E0000uL; //EndAddress: 0x5043FFFF
static const uint32 VIRT_ADDR_START_SIP_MFC_APTIV                           = 0x50440000uL; //EndAddress: 0x5049FFFF
static const uint32 VIRT_ADDR_START_SIP_SRR_APTIV                           = 0x504A0000uL; //EndAddress: 0x504FFFFF
static const uint32 VIRT_ADDR_START_SIP_EHORIZON                            = 0x50500000uL; //EndAddress: 0x5050FFFF
static const uint32 VIRT_ADDR_START_SIP_OTHERS                              = 0x50510000uL; //EndAddress: 0x5051FFFF
static const uint32 VIRT_ADDR_START_FDP_BASE                                = 0x50520000uL; //EndAddress: 0x505BFFFF

#endif

// ***************************************************************************************************************
// GLOB_COMP_ID_GENERATION_END************************************************************************************
// Generated code. No manually changes above this line, please!***************************************************
// ***************************************************************************************************************

/* Virtual addresses found in sdl-files which could not be assigned to any component ****************************************
 *
 * PerfDegrExtInput       0x20100000; size   20 bytes
 * SysPerfMonStates       0x20100100; size   20 bytes
 * BSW_EMCtrlData         0x20100200; size   32 bytes
 * EM_RCSDecayNearSeq     0x20100300; size  108 bytes
 * EM_RCSDecayFarSeq      0x20100400; size  108 bytes
 * EMCameraData           0x20104000; size   16 bytes
 * OLC_ObjectStatus       0x80071100; size    1 bytes
 * Test_Data              0x800d05e0; size    4 bytes
 * CroiShortRight         0x8211b000; size   52 bytes
 * CroiLongRight          0x8211b800; size   52 bytes
 * RawImageRight          0x8211c000; size   52 bytes
 * EmbeddedDataPreRight   0x8211c800; size   52 bytes
 * CroiLongLeft           0x82144000; size   52 bytes
 * RawImageLeft           0x82144800; size   52 bytes
 * Xdc_Ids                0x82150b00; size 1212 bytes
 * TIMESTAMP_MCU          0x83004000; size   12 bytes
 * HIL_TIMESYNC           0x83006000; size   28 bytes
 *
 ********************************************************************************************************************************/


/*Remapped IDs (in order to be compilable**************************************************************************/
#define COMP_ID_EM                      COMP_ID_EM_RAD360
#define COMP_ID_RSP1                    COMP_ID_RSP
#define COMP_ID_RHC1                    COMP_ID_RHC
#define COMP_ID_MEAS_MF                 COMP_ID_MTSI
#define COMP_ID_CAN                     COMP_ID_CANIF
#define COMP_ID_ACTL                    COMP_ID_SCTL
#define COMP_ID_SW_ALGO_EDMA_SERVICE    COMP_ID_DPUSERVICE
#define COMP_ID_SW_CDR                  COMP_ID_CDR
#define COMP_ID_SW_FFI                  COMP_ID_DPUST
#define COMP_ID_SW_SYSTEM               COMP_ID_DPUINFRA
#define COMP_ID_LCF                     COMP_ID_LCF_VEH
#define COMP_ID_IPC                     COMP_ID_IPC_IUC
#define COMP_ID_IPC_RX                  COMP_ID_IPC_DPU_RX
/*Remapped IDs to be compilable - END****************************************************************************/



/* Information for MTS and simulation */
/* Definition of function channel IDs for MEASInfo_t */
#define CHAN_ID_OUTPUT    0
#define CHAN_ID_INPUT     1
#define CHAN_ID_ADJUST    2
#define CHAN_ID_INTERNAL  3

#endif


#ifndef TASK_ID_NULL
/* TaskID, former CycleID, TaskID and Cycle ID are equivalent */
#define TASK_ID_NULL      0   /* Reserved: Do not use */

/* SRL Task ID's range 10U - 19U */
#define TASK_ID_SRL       10U


#define TASK_ID_VDY       20U
#define TASK_ID_FCT       21U
#define TASK_ID_ALDW      22U
#define TASK_ID_LCF_VEH   23U

#define TASK_ID_CUST_0    30U
#define TASK_ID_CUST_1    31U
#define TASK_ID_CUST_2    32U
#define TASK_ID_CUST_3    33U
#define TASK_ID_CUST_4    34U
#define TASK_ID_CUST_5    35U
#define TASK_ID_CUST_6    36U
#define TASK_ID_CUST_7    37U
#define TASK_ID_CUST_8    38U
#define TASK_ID_CUST_9    39U

#define TASK_ID_VEHICLE      40U
#define TASK_ID_EVEN_MAIN    41U
#define TASK_ID_ODD_MAIN     42U
#define TASK_ID_ODD_CLASSIC  43U
#define TASK_ID_ODD_MOD      44U
#define TASK_ID_STEREO_MAIN  45U
#define TASK_ID_STEREO_PV    46U
#define TASK_ID_STEREO_RECT  47U
#define TASK_ID_CLASSIFIERS  48U

#define TASK_ID_LD        49U
#define TASK_ID_SR        50U
#define TASK_ID_LMK       51U
#define TASK_ID_MAP       54U

#define TASK_ID_RHC       60U
#define TASK_ID_RSP       60U
#define TASK_ID_ALN       60U
#define TASK_ID_EM        60U


#define TASK_ID_IMAGE     60U

#define TASK_ID_RSP1      61U

/* mono camera components */
#define TASK_ID_CIPP      61U
#define TASK_ID_CB        62U
#define TASK_ID_ECM       63U
#define TASK_ID_IC        64U
#define TASK_ID_HLA       65U
#define TASK_ID_TSA       66U
#define TASK_ID_SAC       68U
#define TASK_ID_FPGA      69U
#define TASK_ID_CEM       70U
#define TASK_ID_PV        71U
#define TASK_ID_FCT60     72U
#define TASK_ID_CHIPS     73U //TASK_ID_SCB in ARS441
#define TASK_ID_GS        74U
#define TASK_ID_GS_STEREO 75U

#define TASK_ID_SR_A      82U
#define TASK_ID_SR_B      83U

#define TASK_ID_MEMO      85U
#define TASK_ID_PFC       86U
#define TASK_ID_FAMO      87U

#define TASK_ID_ACAL      88U
#define TASK_ID_LCF_SEN   90U
#define TASK_ID_LSD       91U
#define TASK_ID_RUM       92U
#define TASK_ID_UDW       93U
#define TASK_ID_PCA       94U
#define TASK_ID_RDBC      95U
#define TASK_ID_GSM       96U
#define TASK_ID_PDM       97U
#define TASK_ID_POC       98U
#define TASK_ID_GEOS      99U


/* stereo camera components */
#define TASK_ID_FEX       100U
#define TASK_ID_SIB       101U
#define TASK_ID_FS        102U
#define TASK_ID_FTRC      103U
#define TASK_ID_EMO       104U
#define TASK_ID_GEN       105U
#define TASK_ID_GRAPPA    106U
#define TASK_ID_VCL       107U
#define TASK_ID_PC        108U
#define TASK_ID_LEMO      109U
#define TASK_ID_LIQOR     110U
#define TASK_ID_VODCA     111U
#define TASK_ID_FEXCONTROL	112U
#define TASK_ID_HMI       115U

#define TASK_ID_CRLS      118U

#define TASK_ID_TLR       119U

#define TASK_ID_DAP       120U
#define TASK_ID_GP        121U
#define TASK_ID_OD        122U


/* Framesoftware task id */
#define TASK_ID_M11       130U
#define TASK_ID_M12       131U
#define TASK_ID_IPC       132U

#define TASK_ID_S16       135U
#define TASK_ID_S17       136U
#define TASK_ID_S27       137U

#define TASK_ID_S11       140U
#define TASK_ID_S12       141U
#define TASK_ID_S13       142U
#define TASK_ID_S14       143U
#define TASK_ID_S15       144U

#define TASK_ID_S21       145U
#define TASK_ID_S22       146U
#define TASK_ID_S23       147U
#define TASK_ID_S24       148U
#define TASK_ID_S25       149U

#define TASK_ID_IPC_RX    192U

#define TASK_ID_EC	       62U //EC RadarEnvironmentClassification
#define TASK_ID_PCC		  195U //PCC RadarPedestrianCyclistClassification
#define TASK_ID_PD		  196U //PD RadarPerformanceDegradation
#define TASK_ID_RD        224U //RD RadarRoadDescription
#define TASK_ID_VC		  240U //VC RadarVehicleClassification
#define TASK_ID_FPS		  241U //FPS RadarFunctionPreSelection
#define TASK_ID_GFRS      246U //GFRS GridBasedFreespace
#define TASK_ID_DAPVEH    247U //DAPVEH RadarDataProcessingVehicle

/* NOT NOT USE            160 and higher */
/* The TASK_ID starting with 160 are assigned to the frame SW */
/* There are defined in rta_conf.h file */

/* ARS510/SRR520 Tasks */
#define TASK_ID_NOT_USED_200                200U //TASK_ID_SW_RCC
#define TASK_ID_NOT_USED_201                201U //TASK_ID_SW_COM 
#define TASK_ID_NOT_USED_202                202U //TASK_ID_SW_BSW 
#define TASK_ID_NOT_USED_203                203U // #define TASK_ID_SW_MTS                      TASK_ID_SW_MEAS /* renamed */ /* Do not use this one for ARS400 platform */

#define TASK_ID_ALGO_RAW_DATA_CYCLE         204U    /* cycle */
#define TASK_ID_ALGO_DATA_PROC_CYCLE        205U    /* cycle (poss. ext. cycle) */
#define TASK_ID_ALGO_RHC_CYCLE              206U    /* cycle */
#define TASK_ID_ALGO_VEH_CYCLE              MTSI_TASK_ID_FCT_VEH    /* 20 ms */
#define TASK_ID_ALGO_SEN_CYCLE              MTSI_TASK_ID_FCT_SEN    /* cycle (poss. ext. cycle) */
#define TASK_ID_SW_EVERY_10MS               209U    /* 10 ms */
#define TASK_ID_SW_EVERY_20MS               210U    /* 20 ms */
#define TASK_ID_SW_RADAR_CYCLE              211U    /* cycle */
#define TASK_ID_ALGO_PEAK_LIST              212U    /* cycle */

#define TASK_ID_NOT_USED_213                213U  // TASK_ID_DSP
#define TASK_ID_SW_MTA_LANE_0               214U    /* MTA cycle of lane 0 */ // TASK_ID_SW_EVERY_100MS
#define TASK_ID_SW_MTA_LANE_1               215U    /* MTA cycle of lane 1 */ // TASK_ID_SW_EVERY_10S
#define TASK_ID_ALGO_HIL_CYCLE              216U    /* SPT/ADC sigma delta freezes */  //TASK_ID_SW_06

#define TASK_ID_ISP                         245U

#define TASK_ID_UNKNOWN                     255U    /* Error: If this ID is seen in RTA then there are missing ID's */
/* Do not exceed the 8-bit data space of 255!! */

/* Remapped TaskIDs for ARS441 IUC*/
#define TASK_ID_SW_06 TASK_ID_ALGO_HIL_CYCLE


#endif

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/

#endif /* #define GLOB_COMP_ID_INCLUDED */
