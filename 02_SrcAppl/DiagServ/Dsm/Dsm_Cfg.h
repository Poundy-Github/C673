#ifndef _DSM_CFG_H_
#define _DSM_CFG_H_

#include "Std_Types.h" /* AUTOSAR standard types */
#include "Dsm_System.h"

#define APPLICATION_A_VALIDFLAG_ADDRESS       ((void*)0x80100000u) 

#define APPLICATION_B_VALIDFLAG_ADDRESS       ((void*)0x80200000u) 

//Pointer to Boot version information in FBL
#define FBLVERSIONINFO_START_ADDRESS           ((void*)0x80064060u)  
//The length of Boot version information       
#define FBLVERSIONINFO_LEN                     (4u)
//Pointer to Boot requirements specification in FBL
#define FBLREQUIREMENTSPEC_START_ADDRESS       ((void*)0x80064040u)  
//The length of Boot Requirements specification 
#define FBLREQUIREMENTSPEC_LEN                 (4u)
//Pointer to A blank startup abnormal in DataFlash
#define A_BLANKSTARTUPABNORMAL_START_ADDRESS   ((void*)0xAF07E030u)
//Pointer to B blank startup abnormal in DataFlash
#define B_BLANKSTARTUPABNORMAL_START_ADDRESS   ((void*)0xAF07E028u)
//The flag of A or B blank startup abnormal
#define BKANKSTARTUPABNORMAL_FLAG              (0x5AA5A55A5AA5A55Au)
//Poniter to A blank fingerprint start in ROM
#define A_BLANK_FINGERPRINT_START_ADDRESS       ((void*)0x80100100u)
//Poniter to B blank fingerprint start in ROM
#define B_BLANK_FINGERPRINT_START_ADDRESS       ((void*)0x80200100u)
//The conversion factor of conversion voltage
#define DSM_SA_DELAYTIMER                      ((uint16)1000u)//10s = 10ms *1000
//
#define DSM_ECUTEMP_MIN_THLSD                  (-50.0f)
//
#define DSM_ECUTEMP_MAX_THLSD                  (605.35f)
//
#define DSM_ECUTEMP_FACTOR                     (0.01f)
//
#define DSM_ECUTEMP_OFFSET                     (-50.0f)

#define DSM_SOCTEMP_MIN_THLSD                  (-50.0f)

#define DSM_SOCTEMP_MAX_THLSD                  (605.35f)
 
#define DSM_IMAGERTEMP_MIN_THLSD               (-50.0f)

#define DSM_IMAGERTEMP_MAX_THLSD               (605.35f)

#define SPI_SOCTEMP_FACTOR                     (1000)

#define SPI_IMAGETEMP_FACTOR                   (1000)

#define DSM_RC_VEHSPEED_MIN_THSLD              (3u)

#define DSM_RC_VOLT_MIN_THSLD                  (8.5f)

#define DSM_RC_VOLT_MAX_THSLD                  (16.5f)

#define DSM_INTERNALTESTMODE_ON                (0x42u)

#define DSM_INTERNALTESTMODE_OFF               (0x00u)


//The data length of DID as below:

#define ECUSERIALNUMBERDATAID_LEN              (13u)

#define VINDATAID_LEN                          (17u)

#define ETHMAC_ADDRESS_LEN                     (8u)

#define ETH_READPHYLINKSTATE_LEN               (2u)

#define ETH_READPHYSIGQUALITYINDEX_LEN         (2u)

#define ETH_READNUMBEROFPORTS_LEN              (1u)

#define ETH_READPORTCONFIG_LEN                 (2u)

#define ETH_READCOMREADYSTATUS_LEN             (2u)

#define ETH_READMASTERSLAVECONFIG_LEN          (2u)

#define ETH_READMACLAYERSTATISTICS_LEN        (88u)

#define VEHICLETYPE_LEN                       (1u)

#define FABSWITCH_LEN                         (1u)

#define TSRSWITCH_LEN                         (1u)

#define TLASWITCH_LEN                         (1u)

#define EOLCALPARAMETER_LEN                   (8u)

#define EOL_LASTRESULT_LEN                    (1u)

#define EOL_PRERESULT_LEN                     (1u)

#define EOL_SDALASTRESULT_LEN                 (1u)

#define LANEFUNCCONFIG_LEN                    (2u)

#define EOLMODEGATE_LEN                       (2u)

#define FCW_LASTBUTONEAPPEARED_LEN            (49u)

#define AWB_LASTBUTONEAPPEARED_LEN            (49u)

#define AEB_LASTBUTONEAPPEARED_LEN            (49u)

#define FCW_LASTAPPEARED_LEN                  (49u)

#define AWB_LASTAPPEARED_LEN                  (49u)

#define AEB_LASTAPPEARED_LEN                  (49u)

#define PCBASNDATAIDENT_LEN                   (5u)

#define SOCSSNUMBER_LEN                       (8u)

#define SOCSOFTVER_LEN                        (8u)

#define OMSN_LEN                              (4u)

#define BOOTSENSOR_LEN                        (1u)

#define CALBOARDDIS_LEN                       (2u)

#define PARTNUMBER_LEN                        (21u)

#define ECUHWVERSNUMBER_LEN                   (8u)

#define SYSSUPPLIER_LEN                       (7u)

#define ECUOPERATIONMODE_LEN                  (1u)

#define CUSTOMERVAR_LEN                       (1u)

#define FSDEBUG_LEN                           (164u)

//System type selection
#define DSM_SYSTEM_TYPE     DSM_SYSTEM_MFC5J3_C673

#define DSM_FEAT_MEMMAP_EB_IS_USED         STD_ON

/* *** Read Data by identifier Feature($22) *** */
#define DSM_FEAT_RDBI_NetworkInformationDataIdentifier         STD_ON

#define DSM_FEAT_RDBI_FunctionSpecificationDataIdentifier      STD_ON 

#define DSM_FEAT_RDBI_DiagnosticDefinitionDataIdentifier       STD_ON

#define DSM_FEAT_RDBI_ECUPartNumber                            STD_ON

#define DSM_FEAT_RDBI_ECUSoftwareVersionNumberDataIdentifier   STD_ON

#define DSM_FEAT_RDBI_FBLVersionInformation                    STD_ON

#define DSM_FEAT_RDBI_FBLRequirementSpecification              STD_ON

#define DSM_FEAT_RDBI_SoftwareNumber                           STD_ON

#define DSM_FEAT_RDBI_ECUHardwareVersionNumber                 STD_ON

#define DSM_FEAT_RDBI_ProjectID                                STD_ON

#define DSM_FEAT_RDBI_ECUInternalSoftwareVersionNumber         STD_ON

#define DSM_FEAT_RDBI_CalibrationDataIdentifier                STD_ON

#define DSM_FEAT_RDBI_APPDownloadArea_ConditionCheck           STD_ON

#define DSM_FEAT_RDBI_APPDownloadArea_Read                     STD_ON

#define DSM_FEAT_RDBI_MCU_AbankError                           STD_ON

#define DSM_FEAT_RDBI_MCU_BbankError                           STD_ON

#define DSM_FEAT_RDBI_ActiveDiagnosticSessionDataIdentifier    STD_ON

#define DSM_FEAT_RDBI_ECUSupplierVoltage                       STD_ON

#define DSM_FEAT_RDBI_ECUTemperature                           STD_ON

#define DSM_FEAT_RDBI_ECUHardwareVersionNumberDataIdentifier   STD_ON

#define DSM_FEAT_RDBI_SystemSupplierIdentifier                 STD_ON

#define DSM_FEAT_RDBI_ECUSerialNumberDataIdentifier            STD_ON

#define DSM_FEAT_RDBI_VINDataIdentifier                        STD_ON

#define DSM_FEAT_RDBI_applicationSoftwareFingerprintDataIdentifier STD_ON

#define DSM_FEAT_RDBI_ETH_MAC_Address                          STD_ON

#define DSM_FEAT_RDBI_ETH_ReadPHYLink_State                    STD_ON

#define DSM_FEAT_RDBI_ETH_ReadPHYSignal_QualityIndex          STD_ON

#define DSM_FEAT_RDBI_ETH_Read_NumberOfPorts        STD_ON

#define DSM_FEAT_RDBI_ETH_ReadPort_Configuration    STD_ON

#define DSM_FEAT_RDBI_ETH_ReadCommunication_ReadyStatus   STD_ON

#define DSM_FEAT_RDBI_ETH_ReadMasterSlave_Configures     STD_ON

#define DSM_FEAT_RDBI_ETH_ReadMACLayer_Statistics     STD_ON

#define DSM_FEAT_RDBI_VehicleType   STD_ON

#define DSM_FEAT_RDBI_FABSwitch   STD_ON

#define DSM_FEAT_RDBI_TSRSwitch   STD_ON

#define DSM_FEAT_RDBI_TLASwitch   STD_ON

#define DSM_FEAT_RDBI_InvalidAttemptCounter  STD_ON

#define DSM_FEAT_RDBI_EOL_CalibrationParameters  STD_ON

#define DSM_FEAT_RDBI_EOL_LastResult  STD_ON

#define DSM_FEAT_RDBI_EOL_Previous_EOLResult  STD_ON

#define DSM_FEAT_RDBI_SDA_LastResults    STD_ON

#define DSM_FEAT_RDBI_LaneFunctionConfiguration STD_ON

#define DSM_FEAT_RDBI_EOL_ModeGate  STD_ON

#define DSM_FEAT_RDBI_FCW_Lastbutoneappeared  STD_ON

#define DSM_FEAT_RDBI_AWB_Lastbutoneappeared  STD_ON

#define DSM_FEAT_RDBI_AEB_Lastbutoneappeared  STD_ON

#define DSM_FEAT_RDBI_FCW_Lastappeared   STD_ON

#define DSM_FEAT_RDBI_AWB_Lastappeared   STD_ON

#define DSM_FEAT_RDBI_AEB_Lastappeared   STD_ON

#define DSM_FEAT_RDBI_InternalSocTemperature  STD_ON

#define DSM_FEAT_RDBI_PCBASerialNumberDataIdentifier  STD_ON

#define DSM_FEAT_RDBI_ImagerTemperature    STD_ON

#define DSM_FEAT_RDBI_SecureUpdateLog  STD_ON

#define DSM_FEAT_RDBI_InternalTestMode  STD_ON

#define DSM_FEAT_RDBI_SocSupplierSoftwareNumber  STD_ON

#define DSM_FEAT_RDBI_SocSoftwareVersion  STD_ON

#define DSM_FEAT_RDBI_OMSN   STD_ON

#define DSM_FEAT_RDBI_SocSoftwareNumberDataIdentifier  STD_ON

#define DSM_FEAT_RDBI_SocBootSensor  STD_ON

#define DSM_FEAT_RDBI_OMCalibrationStatus  STD_ON

#define DSM_FEAT_RDBI_CalibrationStatus  STD_ON

#define DSM_FEAT_RDBI_CurrentStaticCalibrationDetails   STD_ON

#define DSM_FEAT_RDBI_CalibrationBoardDistance     STD_ON

#define DSM_FEAT_RDBI_BodyHeightWheelHouseEdge  STD_ON

#define DSM_FEAT_RDBI_ECUOperationMode  STD_ON

#define DSM_FEAT_RDBI_SocResetControl  STD_ON

#define DSM_FEAT_RDBI_Fusa_Debug_Status STD_ON

/* *** Write Data by identifier Feature($2E) *** */
#define DSM_FEAT_WDBI_ECUHardwareVersionNumberDataIdentifier  STD_ON

#define DSM_FEAT_WDBI_SystemSupplierIdentifier  STD_ON

#define DSM_FEAT_WDBI_ECUSerialNumberDataIdentifier STD_ON

#define DSM_FEAT_WDBI_VINDataIdentifier STD_ON

#define DSM_FEAT_WDBI_VehicleType   STD_ON

#define DSM_FEAT_WDBI_FABSwitch   STD_ON

#define DSM_FEAT_WDBI_TSRSwitch  STD_ON

#define DSM_FEAT_WDBI_TLASwitch  STD_ON

#define DSM_FEAT_WDBI_LaneFunctionConfiguration STD_ON

#define DSM_FEAT_WDBI_EOL_ModeGate  STD_ON

#define DSM_FEAT_WDBI_PCBASerialNumberDataIdentifier  STD_ON

#define DSM_FEAT_WDBI_InternalTestMode  STD_ON

#define DSM_FEAT_WDBI_PartNumberDataIdentifier  STD_ON

#define DSM_FEAT_WDBI_CalibrationDataIdentifier STD_OFF

#define DSM_FEAT_WDBI_CustomerCodeConfig STD_OFF

#define DSM_FEAT_WDBI_ECUOperationMode STD_ON

#define DSM_FEAT_WDBI_CustomerVariant  STD_OFF

#define DSM_FEAT_WDBI_SocResetControl  STD_ON

#define DSM_FEAT_WDBI_Fusa_Debug_Status STD_ON

/* *** Routine Control Feature($31) *** */
#define DSM_FEAT_RC_ProgrammingPreconditionCheck_StartRoutine   STD_ON

#define DSM_FEAT_RC_ExchangeApplicationRunningArea_StartRoutine  STD_ON

#define DSM_FEAT_RC_ApplicationRollback_StartRoutine   STD_ON

#define DSM_FEAT_RC_LockJTAG_StartRoutine  STD_ON

#define DSM_FEAT_RC_LockJTAG_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_EOLCalibration_StartRoutine  STD_ON

#define DSM_FEAT_RC_EOLCalibration_RequestRoutineResults STD_ON

#define DSM_FEAT_RC_SDACalibration_StartRoutine  STD_ON

#define DSM_FEAT_RC_SDACalibration_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_OTPEnable_StartRoutine  STD_ON

#define DSM_FEAT_RC_OTPEnable_RequestRoutineResults   STD_ON

#define DSM_FEAT_RC_ETHSetPortConfiguration_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_ETHSetPortConfiguration_StartRoutine  STD_ON

#define DSM_FEAT_RC_ETHResetPortConfiguration_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_ETHResetPortConfiguration_StartRoutine  STD_ON

#define DSM_FEAT_RC_ETHReadPhyRegister_StartRoutine  STD_ON

#define DSM_FEAT_RC_ETHReadPhyRegister_RequestRoutineResults   STD_ON

#define DSM_FEAT_RC_ETHCableDiagnostic_StartRoutine  STD_ON

#define DSM_FEAT_RC_ETHCableDiagnostic_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_ETHEnableTestMode_StartRoutine  STD_ON

#define DSM_FEAT_RC_ETHEnableTestMode_StopRoutine  STD_ON

#define DSM_FEAT_RC_ETHEnableTestMode_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_ETHPhyLoopBackTest_StartRoutine   STD_ON

#define DSM_FEAT_RC_ETHPhyLoopBackTest_StopRoutine    STD_ON

#define DSM_FEAT_RC_ETHPhyLoopBackTest_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_ETHResetMACAddress_StartRoutine  STD_ON

#define DSM_FEAT_RC_ETHResetMACAddress_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_ETHResetMACLayerStatistic_StartRoutine  STD_ON

#define DSM_FEAT_RC_ETHResetMACLayerStatistic_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_ETHCableLengthDiagnostic_StartRoutine  STD_ON

#define DSM_FEAT_RC_ETHCableLengthDiagnostic_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_ClearNvM_StartRoutine   STD_ON

#define DSM_FEAT_RC_ClearNvM_RequestRoutineResults  STD_ON

#define DSM_FEAT_RC_SaveNvM_StartRoutine  STD_ON

#define DSM_FEAT_RC_SaveNvM_RequestRoutineResults  STD_ON

/* *** ECU Reset Feature($11) *** */
// Programming session [EcuReset]
#define DSM_FEAT_SU_PROGRAMMING_SESSION    STD_ON


/* *** Security Access Feature($27) *** */
#define DSM_FEAT_SECURITY_ACCESS_TEST      STD_OFF

#endif


