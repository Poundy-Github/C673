/***********************************************************************************

COMPANY:                       Continental AG, A.D.C. GmbH

PROJECT:                       MFC4B0

COMPONENT:                     Diagnostic Event Management (DEM)

MODULENAME:                    Dem_IntErrIdSlv.h

DESCRIPTION:                   Diagnostic EventId Information Lists for all events

GENERATED WITH:                RCC_TM v 1.1.0

CREATION DATE:                 Thu Jan 23 18:06:57 EET 2014

GENERATED BY:                  uidl7600

VERSION:                       $Revision: 1.1 $

CHANGE HISTORY
                               $Log: Dem_IntErrIdSlv.h  $
                               Revision 1.1 2021/12/13 17:22:59CET Wang, David (Wangd3) 
                               Initial revision
                               Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/common_wrapper/project.pj
                               Revision 1.0 2017/03/03 10:34:38CET Sorge, Sven (uidg3181) 
                               Initial revision
                               Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/common_wrapper/project.pj
                               Revision 1.21 2014/01/28 12:48:08CET Gilch-EXT, Andreas (uidt0904) 
                               Renamed five VDY-DEMs (VDY_xyz -> VDY_E_xyz) due to name overlapping with VDY internal struct-elements.
                               - Added comments -  uidt0904 [Jan 28, 2014 12:48:09 PM CET]
                               Change Package : 188806:1 http://mks-psad:7002/im/viewissue?selection=188806
                               Revision 1.20 2014/01/24 12:41:24CET Tepeliga, Adrian (uidl7600) 
                               Slave file after generation with the new dem 18.8 integration
                               --- Added comments ---  uidl7600 [Jan 24, 2014 12:41:24 PM CET]
                               Change Package : 213879:1 http://mks-psad:7002/im/viewissue?selection=213879

                               Revision 1.2 2013/02/22 13:03:37CET Curea, Aurel (uidl7200) 

                               Implemented remaining review findings id: 3504650

                               --- Added comments ---  uidl7200 [Feb 22, 2013 1:03:37 PM CET]

                               Change Package : 173669:2 http://mks-psad:7002/im/viewissue?selection=173669

***********************************************************************************/
#ifndef __DEM_INTERRIDSLV_H
#define __DEM_INTERRIDSLV_H

/***********************************************************************************
  INCLUDES
***********************************************************************************/

/***********************************************************************************
  DEFINES
***********************************************************************************/

/* Check file versions */
#ifdef THE_MAGIC_NUMBER
#if (THE_MAGIC_NUMBER != 1829858024)
#error "error: Magic number of generated EIL headers does not match. Please check time and date of generated files!"
#endif
#else
#define THE_MAGIC_NUMBER 1829858024
#endif

/* Project setting of the generated Event Information List configuration */
#define DEM_PRJ_SETTING_OF_EIL_CONFIG     "MFC4B0"

/* Event Information List Master-/Slave-Version */
#define DEM_EIL_MASTER_VERSION_NUMBER (603u)
#define DEM_EIL_SLAVE_VERSION_NUMBER (3u)
#define DEM_EIL_SLAVE2_VERSION_NUMBER (0u)
#define DEM_EIL_SLAVE3_VERSION_NUMBER (1u)


/* DEM_SLAVE_COMPONENT_OFFSET: Defines the Offset of the Slave Components from the Master Components */
#define DEM_SLAVE_COMPONENT_OFFSET   0x4000u

/* Defines the number of DTC's which are used from the Project */
#define DEM_NUM_OF_DTCS                               168u
/* In LinkTime Configuration (ARS327) DEM_NUM_OF_DTCS describes the max number of DTCs, */
/* therefore a 2nd define DEM_NUM_OF_USED_DTCS is implemented for reducing runtime      */
#define DEM_NUM_OF_USED_DTCS                          168u
/* Defines the maximum number of Events which are assigned to a DTC-FTB combination */
#define DEM_MAX_NUM_OF_EVENTS_PER_DTC_FTB             153u
#define DEM_NUM_OF_FF_IDS                             (16u)
/* Defines the summarized number of events and Hw errors used Dem_EvInCSFlags[] */
#define DEM_MAX_EV_HW_ERROR_EVENT_FLAG_INDEX          899u
/* Configured inhibitions, events or Hw errors in the slave configuration */
#define DEM_MAX_INHIB_EVENT_HW_EVENT_FLAG_INDEX_SLAVE 453u

#define DEM_NUM_OF_PID_IDS 32u

#define DEM_NUMBER_OF_BYTES_PER_PID_HEADER 2u

#define DEM_NUM_OF_MAX_PIDS_PER_FF                    (5u)

/*****************************************************************************
(SYMBOLIC) CONSTANTS
*****************************************************************************/

/******************* Defines of EventID's ***********************************/
#define   DEM_EVENT_ID_INVALID_SL		(0x4001u)
#define   DEM_NOT_INITIALIZED_SL		(0x4002u)
#define   DEM_EV_FLAG_INDEX_INVALID_SL		(0x4003u)
#define   DEM_WRONG_DATABASE_CLUSTER_SIZE_SL		(0x4004u)
#define   DEM_PRE_EXT_DATA_BUFFER_OVERFLOW_SL		(0x4005u)
#define   DEM_PASSIV_VALUE_SL		(0x4006u)
#define   DEM_POINTER_ADDR_INVALID_SL		(0x4007u)
#define   DEM_PRE_EXT_DATA_BUFFER_OVERFLOW		(0x4008u)
#define   HLA_FATAL_ERROR		(0x4009u)
#define   HLA_STATIC_INPUT_DATA_ERROR		(0x400Au)
#define   HLA_BLOCKAGE		(0x400Bu)
#define   HLA_TEMP_BLOCKAGE		(0x400Cu)
#define   HLA_DYNAMIC_INPUT_DATA_ERROR		(0x400Du)
#define   HLA_IMAGE_INPUT_DATA_ERROR		(0x400Eu)
#define   HLA_CALIBRATION_INPUT_DATA_ERROR		(0x400Fu)
#define   HLA_SW_ERROR		(0x4010u)
#define   HLA_SENSITIVITY_MISALIGNED		(0x4011u)
#define   HLA_FIRST_ERROR		(0x4012u)
#define   SR_FATAL_ERROR		(0x4013u)
#define   SR_STATIC_INPUT_DATA_ERROR		(0x4014u)
#define   SR_DEVELOPMENT_ERROR		(0x4015u)
#define   SR_BLOCKAGE		(0x4016u)
#define   SR_DYNAMIC_INPUT_DATA_ERROR		(0x4017u)
#define   SR_IMAGE_INPUT_DATA_ERROR		(0x4018u)
#define   SR_CALIBRATION_INPUT_DATA_ERROR		(0x4019u)
#define   SR_SW_ERROR		(0x401Au)
#define   SR_FIRST_ERROR		(0x401Bu)
#define   SR_GENERAL_INPUT_DATA_ERROR		(0x401Cu)
#define   TSA_FATAL_ERROR		(0x401Du)
#define   TSA_STATIC_INPUT_DATA_ERROR		(0x401Eu)
#define   TSA_BLOCKAGE		(0x401Fu)
#define   TSA_TEMP_BLOCKAGE		(0x4020u)
#define   TSA_DYNAMIC_INPUT_DATA_ERROR		(0x4021u)
#define   TSA_IMAGE_INPUT_DATA_ERROR		(0x4022u)
#define   TSA_CALIBRATION_INPUT_DATA_ERROR		(0x4023u)
#define   TSA_SW_ERROR		(0x4024u)
#define   TSA_FIRST_ERROR		(0x4025u)
#define   TSA_DEVELOPMENT_ERROR		(0x4026u)
#define   TSA_INPUT_COUNTRY_CODE_ERROR		(0x4027u)
#define   TSA_GENERAL_INPUT_DATA_ERROR		(0x4028u)
#define   LD_FATAL_ERROR		(0x4029u)
#define   LD_STATIC_INPUT_DATA_ERROR		(0x402Au)
#define   LD_BLOCKAGE		(0x402Bu)
#define   LD_TEMP_BLOCKAGE		(0x402Cu)
#define   LD_DYNAMIC_INPUT_DATA_ERROR		(0x402Du)
#define   LD_IMAGE_INPUT_DATA_ERROR		(0x402Eu)
#define   LD_CALIBRATION_INPUT_DATA_ERROR		(0x402Fu)
#define   LD_SW_ERROR		(0x4030u)
#define   LD_FIRST_ERROR		(0x4031u)
#define   LD_ONLINE_CALIBRATION_ERROR		(0x4032u)
#define   ALDW_FATAL_ERROR		(0x4033u)
#define   ALDW_STATIC_INPUT_DATA_ERROR		(0x4034u)
#define   ALDW_BLOCKAGE		(0x4035u)
#define   ALDW_TEMP_BLOCKAGE		(0x4036u)
#define   ALDW_DYNAMIC_INPUT_DATA_ERROR		(0x4037u)
#define   ALDW_IMAGE_INPUT_DATA_ERROR		(0x4038u)
#define   ALDW_CALIBRATION_INPUT_DATA_ERROR		(0x4039u)
#define   ALDW_SW_ERROR		(0x403Au)
#define   ALDW_FIRST_ERROR		(0x403Bu)
#define   CB_FATAL_ERROR		(0x403Cu)
#define   CB_STATIC_INPUT_DATA_ERROR		(0x403Du)
#define   CB_BLOCKAGE		(0x403Eu)
#define   CB_DYNAMIC_INPUT_DATA_ERROR		(0x403Fu)
#define   CB_IMAGE_INPUT_DATA_ERROR		(0x4040u)
#define   CB_CALIBRATION_INPUT_DATA_ERROR		(0x4041u)
#define   CB_SW_ERROR		(0x4042u)
#define   CB_FIRST_ERROR		(0x4043u)
#define   ECM_FATAL_ERROR		(0x4044u)
#define   ECM_STATIC_INPUT_DATA_ERROR		(0x4045u)
#define   ECM_BLOCKAGE		(0x4046u)
#define   ECM_DYNAMIC_INPUT_DATA_ERROR		(0x4047u)
#define   ECM_IMAGE_INPUT_DATA_ERROR		(0x4048u)
#define   ECM_CALIBRATION_INPUT_DATA_ERROR		(0x4049u)
#define   ECM_SW_ERROR		(0x404Au)
#define   ECM_FIRST_ERROR		(0x404Bu)
#define   ECM_CALIBRATION_ERROR		(0x404Cu)
#define   CIPP_FATAL_ERROR		(0x404Du)
#define   CIPP_STATIC_INPUT_DATA_ERROR		(0x404Eu)
#define   CIPP_BLOCKAGE		(0x404Fu)
#define   CIPP_DYNAMIC_INPUT_DATA_ERROR		(0x4050u)
#define   CIPP_IMAGE_INPUT_DATA_ERROR		(0x4051u)
#define   CIPP_CALIBRATION_INPUT_DATA_ERROR		(0x4052u)
#define   CIPP_SW_ERROR		(0x4053u)
#define   CIPP_FIRST_ERROR		(0x4054u)
#define   MEMO_FATAL_ERROR		(0x4055u)
#define   MEMO_STATIC_INPUT_DATA_ERROR		(0x4056u)
#define   MEMO_BLOCKAGE		(0x4057u)
#define   MEMO_DYNAMIC_INPUT_DATA_ERROR		(0x4058u)
#define   MEMO_IMAGE_INPUT_DATA_ERROR		(0x4059u)
#define   MEMO_CALIBRATION_INPUT_DATA_ERROR		(0x405Au)
#define   MEMO_SW_ERROR		(0x405Bu)
#define   MEMO_FIRST_ERROR		(0x405Cu)
#define   MEMO_ONLINE_CALIBRATION_ERROR		(0x405Du)
#define   VDY_FATAL_ERROR		(0x405Eu)
#define   VDY_STATIC_INPUT_DATA_ERROR		(0x405Fu)
#define   VDY_BLOCKAGE		(0x4060u)
#define   VDY_DYNAMIC_INPUT_DATA_ERROR		(0x4061u)
#define   VDY_IMAGE_INPUT_DATA_ERROR		(0x4062u)
#define   VDY_CALIBRATION_INPUT_DATA_ERROR		(0x4063u)
#define   VDY_SW_ERROR		(0x4064u)
#define   VDY_FIRST_ERROR		(0x4065u)
#define   EBA_VHCL_FATAL_ERROR		(0x4066u)
#define   EBA_VHCL_STATIC_INPUT_DATA_ERROR		(0x4067u)
#define   EBA_VHCL_BLOCKAGE		(0x4068u)
#define   EBA_VHCL_DYNAMIC_INPUT_DATA_ERROR		(0x4069u)
#define   EBA_VHCL_IMAGE_INPUT_DATA_ERROR		(0x406Au)
#define   EBA_VHCL_CALIBRATION_INPUT_DATA_ERROR		(0x406Bu)
#define   EBA_VHCL_SW_ERROR		(0x406Cu)
#define   EBA_VHCL_FIRST_ERROR		(0x406Du)
#define   EBA_SENS_FATAL_ERROR		(0x406Eu)
#define   EBA_SENS_STATIC_INPUT_DATA_ERROR		(0x406Fu)
#define   EBA_SENS_BLOCKAGE		(0x4070u)
#define   EBA_SENS_DYNAMIC_INPUT_DATA_ERROR		(0x4071u)
#define   EBA_SENS_IMAGE_INPUT_DATA_ERROR		(0x4072u)
#define   EBA_SENS_CALIBRATION_INPUT_DATA_ERROR		(0x4073u)
#define   EBA_SENS_SW_ERROR		(0x4074u)
#define   EBA_SENS_FIRST_ERROR		(0x4075u)
#define   EM_FATAL_ERROR		(0x4076u)
#define   EM_STATIC_INPUT_DATA_ERROR		(0x4077u)
#define   EM_BLOCKAGE		(0x4078u)
#define   EM_DYNAMIC_INPUT_DATA_ERROR		(0x4079u)
#define   EM_IMAGE_INPUT_DATA_ERROR		(0x407Au)
#define   EM_CALIBRATION_INPUT_DATA_ERROR		(0x407Bu)
#define   EM_SW_ERROR		(0x407Cu)
#define   EM_FIRST_ERROR		(0x407Du)
#define   GEN_SOBJ_FATAL_ERROR		(0x407Eu)
#define   GEN_SOBJ_STATIC_INPUT_DATA_ERROR		(0x407Fu)
#define   GEN_SOBJ_BLOCKAGE		(0x4080u)
#define   GEN_SOBJ_DYNAMIC_INPUT_DATA_ERROR		(0x4081u)
#define   GEN_SOBJ_IMAGE_INPUT_DATA_ERROR		(0x4082u)
#define   GEN_SOBJ_CALIBRATION_INPUT_DATA_ERROR		(0x4083u)
#define   GEN_SOBJ_SW_ERROR		(0x4084u)
#define   GEN_SOBJ_FIRST_ERROR		(0x4085u)
#define   PED_FATAL_ERROR		(0x4086u)
#define   PED_STATIC_INPUT_DATA_ERROR		(0x4087u)
#define   PED_BLOCKAGE		(0x4088u)
#define   PED_DYNAMIC_INPUT_DATA_ERROR		(0x4089u)
#define   PED_IMAGE_INPUT_DATA_ERROR		(0x408Au)
#define   PED_CALIBRATION_INPUT_DATA_ERROR		(0x408Bu)
#define   PED_SW_ERROR		(0x408Cu)
#define   PED_FIRST_ERROR		(0x408Du)
#define   VCL_FATAL_ERROR		(0x408Eu)
#define   VCL_STATIC_INPUT_DATA_ERROR		(0x408Fu)
#define   VCL_BLOCKAGE		(0x4090u)
#define   VCL_DYNAMIC_INPUT_DATA_ERROR		(0x4091u)
#define   VCL_IMAGE_INPUT_DATA_ERROR		(0x4092u)
#define   VCL_CALIBRATION_INPUT_DATA_ERROR		(0x4093u)
#define   VCL_SW_ERROR		(0x4094u)
#define   VCL_FIRST_ERROR		(0x4095u)
#define   PC_FATAL_ERROR		(0x4096u)
#define   PC_STATIC_INPUT_DATA_ERROR		(0x4097u)
#define   PC_BLOCKAGE		(0x4098u)
#define   PC_DYNAMIC_INPUT_DATA_ERROR		(0x4099u)
#define   PC_IMAGE_INPUT_DATA_ERROR		(0x409Au)
#define   PC_CALIBRATION_INPUT_DATA_ERROR		(0x409Bu)
#define   PC_SW_ERROR		(0x409Cu)
#define   PC_FIRST_ERROR		(0x409Du)
#define   SIB_FATAL_ERROR		(0x409Eu)
#define   SIB_STATIC_INPUT_DATA_ERROR		(0x409Fu)
#define   SIB_BLOCKAGE		(0x40A0u)
#define   SIB_DYNAMIC_INPUT_DATA_ERROR		(0x40A1u)
#define   SIB_IMAGE_INPUT_DATA_ERROR		(0x40A2u)
#define   SIB_CALIBRATION_INPUT_DATA_ERROR		(0x40A3u)
#define   SIB_SW_ERROR		(0x40A4u)
#define   SIB_FIRST_ERROR		(0x40A5u)
#define   SEMO_FATAL_ERROR		(0x40A6u)
#define   SEMO_STATIC_INPUT_DATA_ERROR		(0x40A7u)
#define   SEMO_BLOCKAGE		(0x40A8u)
#define   SEMO_DYNAMIC_INPUT_DATA_ERROR		(0x40A9u)
#define   SEMO_IMAGE_INPUT_DATA_ERROR		(0x40AAu)
#define   SEMO_CALIBRATION_INPUT_DATA_ERROR		(0x40ABu)
#define   SEMO_SW_ERROR		(0x40ACu)
#define   SEMO_FIRST_ERROR		(0x40ADu)
#define   SEMO_ONLINE_CALIBRATION_ERROR		(0x40AEu)
#define   FSD_DEVELOPMENT_ERROR		(0x40AFu)
#define   FSD_STATIC_INPUT_DATA_ERROR		(0x40B0u)
#define   FSD_BLOCKAGE		(0x40B1u)
#define   FSD_DYNAMIC_INPUT_DATA_ERROR		(0x40B2u)
#define   FSD_IMAGE_INPUT_DATA_ERROR		(0x40B3u)
#define   FSD_CALIBRATION_INPUT_DATA_ERROR		(0x40B4u)
#define   FSD_SW_ERROR		(0x40B5u)
#define   FSD_FIRST_ERROR		(0x40B6u)
#define   FTRC_FATAL_ERROR		(0x40B7u)
#define   FTRC_STATIC_INPUT_DATA_ERROR		(0x40B8u)
#define   FTRC_BLOCKAGE		(0x40B9u)
#define   FTRC_DYNAMIC_INPUT_DATA_ERROR		(0x40BAu)
#define   FTRC_IMAGE_INPUT_DATA_ERROR		(0x40BBu)
#define   FTRC_CALIBRATION_INPUT_DATA_ERROR		(0x40BCu)
#define   FTRC_SW_ERROR		(0x40BDu)
#define   FTRC_FIRST_ERROR		(0x40BEu)
#define   FEX_FATAL_ERROR		(0x40BFu)
#define   FEX_STATIC_INPUT_DATA_ERROR		(0x40C0u)
#define   FEX_BLOCKAGE		(0x40C1u)
#define   FEX_DYNAMIC_INPUT_DATA_ERROR		(0x40C2u)
#define   FEX_IMAGE_INPUT_DATA_ERROR		(0x40C3u)
#define   FEX_CALIBRATION_INPUT_DATA_ERROR		(0x40C4u)
#define   FEX_SW_ERROR		(0x40C5u)
#define   FEX_FIRST_ERROR		(0x40C6u)
#define   FEX_IMAGE_DATA_ERROR		(0x40C7u)
#define   PV_FATAL_ERROR		(0x40C8u)
#define   PV_STATIC_INPUT_DATA_ERROR		(0x40C9u)
#define   PV_BLOCKAGE		(0x40CAu)
#define   PV_DYNAMIC_INPUT_DATA_ERROR		(0x40CBu)
#define   PV_IMAGE_INPUT_DATA_ERROR		(0x40CCu)
#define   PV_CALIBRATION_INPUT_DATA_ERROR		(0x40CDu)
#define   PV_SW_ERROR		(0x40CEu)
#define   PV_TEMP_BLOCKAGE		(0x40CFu)
#define   PV_FIRST_ERROR		(0x40D0u)
#define   SCB_FATAL_ERROR		(0x40D1u)
#define   SCB_STATIC_INPUT_DATA_ERROR		(0x40D2u)
#define   SCB_BLOCKAGE		(0x40D3u)
#define   SCB_DYNAMIC_INPUT_DATA_ERROR		(0x40D4u)
#define   SCB_IMAGE_INPUT_DATA_ERROR		(0x40D5u)
#define   SCB_CALIBRATION_INPUT_DATA_ERROR		(0x40D6u)
#define   SCB_SW_ERROR		(0x40D7u)
#define   SCB_FIRST_ERROR		(0x40D8u)
#define   SAC_CALIBRATION_WORLD_ERROR		(0x40D9u)
#define   SAC_STATIC_INPUT_DATA_ERROR		(0x40DAu)
#define   SAC_BLOCKAGE		(0x40DBu)
#define   SAC_DYNAMIC_INPUT_DATA_ERROR		(0x40DCu)
#define   SAC_IMAGE_INPUT_DATA_ERROR		(0x40DDu)
#define   SAC_CALIBRATION_INPUT_DATA_ERROR		(0x40DEu)
#define   SAC_SW_ERROR		(0x40DFu)
#define   SAC_FIRST_ERROR		(0x40E0u)
#define   SAC_CALIBRATION_ERROR		(0x40E1u)
#define   IC_ERR_PARAMETER		(0x40E2u)
#define   IC_ERR_IMAGER_BIST_R		(0x40E3u)
#define   IC_ERR_IMAGER_BIST_L		(0x40E4u)
#define   IC_ERR_IMAGER_DATABUS_MCU_STARTUP		(0x40E5u)
#define   IC_ERR_IMAGER_ATEST_R		(0x40E6u)
#define   IC_ERR_REGTX_SYNC_VERIFY_FAILED_R		(0x40E7u)
#define   IC_ERR_REGTX_SYNC_VERIFY_FAILED_L		(0x40E8u)
#define   IC_ERR_FRAMECOUNTER		(0x40E9u)
#define   IC_ERR_FRAMECOUNTER_INCONSISTENT		(0x40EAu)
#define   IC_ERR_UNEXPECTED_EMBD_REG_STAT		(0x40EBu)
#define   IC_ERR_GENERAL		(0x40ECu)
#define   IC_ERR_PART1_NOTCALLED		(0x40EDu)
#define   IC_ERR_PART2_NOTCALLED		(0x40EEu)
#define   IC_ERR_IMAGER_COMM_R		(0x40EFu)
#define   IC_ERR_IMAGER_COMM_L		(0x40F0u)
#define   IC_ERR_IMAGER_COMM		(0x40F1u)
#define   IC_ERR_IMAGER_COMM_TIMING		(0x40F2u)
#define   IC_ERR_EMBEDDED_REGS_CORRUPTED		(0x40F3u)
#define   IC_ERR_EMBEDDED_STAT_CORRUPTED		(0x40F4u)
#define   IC_ERR_REGCHECK_FAILED_R		(0x40F5u)
#define   IC_ERR_REGCHECK_FAILED_L		(0x40F6u)
#define   IC_ERR_INPUTS_DSP2		(0x40F7u)
#define   IC_ERR_INPUTS		(0x40F8u)
#define   IC_ERR_GENERAL_FATAL		(0x40F9u)
#define   IC_ERR_HARDWARE_TIMING		(0x40FAu)
#define   IC_ERR_IMAGER_DATABUS_CYCLIC_R		(0x40FBu)
#define   IC_ERR_SOFTWARE_TIMING		(0x40FCu)
#define   IC_ERR_CALIBRATION		(0x40FDu)
#define   IC_MISC_ERR_VDY_OUT		(0x40FEu)
#define   IC_MISC_ERR_LD_OUT		(0x40FFu)
#define   IC_MISC_ERR_CAMPOS_CALI_OUT		(0x4100u)
#define   IC_MISC_ERR_SAC_OUT		(0x4101u)
#define   IC_ERR_RESERVED_1		(0x4102u)
#define   IC_COMMON_HW_DEF_ERR		(0x4103u)
#define   IC_ADAPTER_SIGNAL_ERROR		(0x4104u)
#define   SOCMONO_LD_ADP_INPUT_ERROR		(0x4105u)
#define   SOCMONO_LD_ADP_OUTPUT_ERROR		(0x4106u)
#define   SOCMONO_LD_ADP_CHECKSUM_ERROR		(0x4107u)
#define   SOCMONO_LD_ADP_IMGCHECK_ERROR		(0x4108u)
#define   SOCMONO_LD_ADP_RESET_ERROR		(0x4109u)
#define   SOCMONO_HLA_ADP_INPUT_ERROR		(0x410Au)
#define   SOCMONO_HLA_ADP_OUTPUT_ERROR		(0x410Bu)
#define   SOCMONO_HLA_ADP_IMGCHECK_ERROR		(0x410Cu)
#define   SOCMONO_HLA_ADP_RESET_ERROR		(0x410Du)
#define   SOCMONO_CIPP_ADP_INPUT_ERROR		(0x410Eu)
#define   SOCMONO_CIPP_ADP_OUTPUT_ERROR		(0x410Fu)
#define   SOCMONO_CIPP_ADP_IMGCHECK_ERROR		(0x4110u)
#define   SOCMONO_CIPP_ADP_RESET_ERROR		(0x4111u)
#define   SOCMONO_ALDW_ADP_INPUT_ERROR		(0x4112u)
#define   SOCMONO_ALDW_ADP_OUTPUT_ERROR		(0x4113u)
#define   SOCMONO_ALDW_ADP_CHECKSUM_ERROR		(0x4114u)
#define   SOCMONO_ALDW_ADP_RESET_ERROR		(0x4115u)
#define   SOCMONO_ECM_ADP_INPUT_ERROR		(0x4116u)
#define   SOCMONO_ECM_ADP_OUTPUT_ERROR		(0x4117u)
#define   SOCMONO_ECM_ADP_IMGCHECK_ERROR		(0x4118u)
#define   SOCMONO_ECM_ADP_RESET_ERROR		(0x4119u)
#define   SOCMONO_CB_ADP_INPUT_ERROR		(0x411Au)
#define   SOCMONO_CB_ADP_OUTPUT_ERROR		(0x411Bu)
#define   SOCMONO_CB_ADP_IMGCHECK_ERROR		(0x411Cu)
#define   SOCMONO_CB_ADP_RESET_ERROR		(0x411Du)
#define   SOCMONO_MEMO_ADP_INPUT_ERROR		(0x411Eu)
#define   SOCMONO_MEMO_ADP_OUTPUT_ERROR		(0x411Fu)
#define   SOCMONO_MEMO_ADP_RESET_ERROR		(0x4120u)
#define   SOCMONO_VCL_ADP_INPUT_ERROR		(0x4121u)
#define   SOCMONO_VCL_ADP_OUTPUT_ERROR		(0x4122u)
#define   SOCMONO_VCL_ADP_CHECKSUM_ERROR		(0x4123u)
#define   SOCMONO_VCL_ADP_IMGCHECK_ERROR		(0x4124u)
#define   SOCMONO_VCL_ADP_RESET_ERROR		(0x4125u)
#define   SOCMONO_SR_ADP_INPUT_ERROR		(0x4126u)
#define   SOCMONO_SR_ADP_OUTPUT_ERROR		(0x4127u)
#define   SOCMONO_SR_ADP_IMGCHECK_ERROR		(0x4128u)
#define   SOCMONO_SR_ADP_RESET_ERROR		(0x4129u)
#define   SOCMONO_TSA_ADP_INPUT_ERROR		(0x412Au)
#define   SOCMONO_TSA_ADP_OUTPUT_ERROR		(0x412Bu)
#define   SOCMONO_TSA_ADP_IMGCHECK_ERROR		(0x412Cu)
#define   SOCMONO_TSA_ADP_RESET_ERROR		(0x412Du)
#define   SOCMONO_MS_ADP_INPUT_ERROR		(0x412Eu)
#define   SOCMONO_MS_ADP_OUTPUT_ERROR		(0x412Fu)
#define   SOCMONO_MS_ADP_CHECKSUM_ERROR		(0x4130u)
#define   SOCMONO_MS_ADP_RESET_ERROR		(0x4131u)
#define   SOCMONO_MON_ONCHIPMEM_ERROR		(0x4132u)
#define   SOCMONO_MON_EXTMEM_ERROR		(0x4133u)
#define   SOCMONO_MON_ADDRBUS_ERROR		(0x4134u)
#define   SOCMONO_COREM3_MON_TSKSTACK_ERROR		(0x4135u)
#define   SOCMONO_COREDSP_MON_TSKSTACK_ERROR		(0x4136u)
#define   SOCMONO_COREA8_MON_TSKSTACK_ERROR		(0x4137u)
#define   SOCMONO_MON_STATMEM_ERROR		(0x4138u)
#define   SOCMONO_COREM3_MON_STARTUP_CHECKPOINT_ERROR		(0x4139u)
#define   SOCMONO_COREDSP_MON_STARTUP_CHECKPOINT_ERROR		(0x413Au)
#define   SOCMONO_COREA8_MON_STARTUP_CHECKPOINT_ERROR		(0x413Bu)
#define   SOCMONO_COREM3_MON_FRAMEDROP_OCCUR_ERROR		(0x413Cu)
#define   SOCMONO_COREDSP_MON_FRAMEDROP_OCCUR_ERROR		(0x413Du)
#define   SOCMONO_COREA8_MON_FRAMEDROP_OCCUR_ERROR		(0x413Eu)
#define   SOCMONO_COREM3_INTDEM_BUFOVER_ERROR		(0x413Fu)
#define   SOCMONO_COREDSP_INTDEM_BUFOVER_ERROR		(0x4140u)
#define   SOCMONO_COREA8_INTDEM_BUFOVER_ERROR		(0x4141u)
#define   SOCMONO_COREM3_SERVICE_MEAS_ERROR		(0x4142u)
#define   SOCMONO_COREDSP_SERVICE_MEAS_ERROR		(0x4143u)
#define   SOCMONO_COREA8_SERVICE_MEAS_ERROR		(0x4144u)
#define   SOCMONO_COREM3_SERVICE_EDMA_ERROR		(0x4145u)
#define   SOCMONO_COREDSP_SERVICE_EDMA_ERROR		(0x4146u)
#define   SOCMONO_COREA8_SERVICE_EDMA_ERROR		(0x4147u)
#define   SOCMONO_SERVICE_ONCHIPMEM_ERROR		(0x4148u)
#define   SOCMONO_SERVICE_EVE_ERROR		(0x4149u)
#define   SOCMONO_COREM3_SERVICE_ICC_ERROR		(0x414Au)
#define   SOCMONO_COREDSP_SERVICE_ICC_ERROR		(0x414Bu)
#define   SOCMONO_COREA8_SERVICE_ICC_ERROR		(0x414Cu)
#define   SOCMONO_PCIE_DRIVER_SELFDIAG_ERROR		(0x414Du)
#define   SOCSTEREO_GEN_ADP_INPUT_ERROR		(0x414Eu)
#define   SOCSTEREO_GEN_ADP_OUTPUT_ERROR		(0x414Fu)
#define   SOCSTEREO_GEN_ADP_IMGCHECK_ERROR		(0x4150u)
#define   SOCSTEREO_GEN_ADP_RESET_ERROR		(0x4151u)
#define   SOCSTEREO_SIB_ADP_INPUT_ERROR		(0x4152u)
#define   SOCSTEREO_SIB_ADP_OUTPUT_ERROR		(0x4153u)
#define   SOCSTEREO_SIB_ADP_IMGCHECK_ERROR		(0x4154u)
#define   SOCSTEREO_SIB_ADP_RESET_ERROR		(0x4155u)
#define   SOCSTEREO_FTRC_ADP_INPUT_ERROR		(0x4156u)
#define   SOCSTEREO_FTRC_ADP_OUTPUT_ERROR		(0x4157u)
#define   SOCSTEREO_FTRC_ADP_IMGCHECK_ERROR		(0x4158u)
#define   SOCSTEREO_FTRC_ADP_RESET_ERROR		(0x4159u)
#define   SOCSTEREO_SAC_ADP_INPUT_ERROR		(0x415Au)
#define   SOCSTEREO_SAC_ADP_OUTPUT_ERROR		(0x415Bu)
#define   SOCSTEREO_SAC_ADP_IMGCHECK_ERROR		(0x415Cu)
#define   SOCSTEREO_SAC_ADP_CHECKSUM_ERROR		(0x415Du)
#define   SOCSTEREO_SAC_ADP_RESET_ERROR		(0x415Eu)
#define   SOCSTEREO_ECS_ADP_INPUT_ERROR		(0x415Fu)
#define   SOCSTEREO_ECS_ADP_OUTPUT_ERROR		(0x4160u)
#define   SOCSTEREO_ECS_ADP_IMGCHECK_ERROR		(0x4161u)
#define   SOCSTEREO_ECS_ADP_RESET_ERROR		(0x4162u)
#define   SOCSTEREO_SCB_ADP_INPUT_ERROR		(0x4163u)
#define   SOCSTEREO_SCB_ADP_OUTPUT_ERROR		(0x4164u)
#define   SOCSTEREO_SCB_ADP_IMGCHECK_ERROR		(0x4165u)
#define   SOCSTEREO_SCB_ADP_RESET_ERROR		(0x4166u)
#define   SOCSTEREO_SEMO_ADP_INPUT_ERROR		(0x4167u)
#define   SOCSTEREO_SEMO_ADP_OUTPUT_ERROR		(0x4168u)
#define   SOCSTEREO_SEMO_ADP_RESET_ERROR		(0x4169u)
#define   SOCSTEREO_FSD_ADP_INPUT_ERROR		(0x416Au)
#define   SOCSTEREO_FSD_ADP_OUTPUT_ERROR		(0x416Bu)
#define   SOCSTEREO_FSD_ADP_CHECKSUM_ERROR		(0x416Cu)
#define   SOCSTEREO_FSD_ADP_IMGCHECK_ERROR		(0x416Du)
#define   SOCSTEREO_FSD_ADP_RESET_ERROR		(0x416Eu)
#define   SOCSTEREO_PED_ADP_INPUT_ERROR		(0x416Fu)
#define   SOCSTEREO_PED_ADP_OUTPUT_ERROR		(0x4170u)
#define   SOCSTEREO_PED_ADP_IMGCHECK_ERROR		(0x4171u)
#define   SOCSTEREO_PED_ADP_RESET_ERROR		(0x4172u)
#define   SOCSTEREO_PV_ADP_INPUT_ERROR		(0x4173u)
#define   SOCSTEREO_PV_ADP_OUTPUT_ERROR		(0x4174u)
#define   SOCSTEREO_PV_ADP_CHECKSUM_ERROR		(0x4175u)
#define   SOCSTEREO_PV_ADP_IMGCHECK_ERROR		(0x4176u)
#define   SOCSTEREO_PV_ADP_RESET_ERROR		(0x4177u)
#define   SOCSTEREO_SS_ADP_INPUT_ERROR		(0x4178u)
#define   SOCSTEREO_SS_ADP_OUTPUT_ERROR		(0x4179u)
#define   SOCSTEREO_SS_ADP_CHECKSUM_ERROR		(0x417Au)
#define   SOCSTEREO_SS_ADP_RESET_ERROR		(0x417Bu)
#define   SOCSTEREO_MON_ONCHIPMEM_ERROR		(0x417Cu)
#define   SOCSTEREO_MON_EXTMEM_ERROR		(0x417Du)
#define   SOCSTEREO_MON_ADDRBUS_ERROR		(0x417Eu)
#define   SOCSTEREO_COREM3_MON_TSKSTACK_ERROR		(0x417Fu)
#define   SOCSTEREO_COREDSP_MON_TSKSTACK_ERROR		(0x4180u)
#define   SOCSTEREO_MON_STATMEM_ERROR		(0x4181u)
#define   SOCSTEREO_COREM3_MON_STARTUP_CHECKPOINT_ERROR		(0x4182u)
#define   SOCSTEREO_COREDSP_MON_STARTUP_CHECKPOINT_ERROR		(0x4183u)
#define   SOCSTEREO_COREM3_MON_FRAMEDROP_OCCUR_ERROR		(0x4184u)
#define   SOCSTEREO_COREDSP_MON_FRAMEDROP_OCCUR_ERROR		(0x4185u)
#define   SOCSTEREO_COREM3_INTDEM_BUFOVER_ERROR		(0x4186u)
#define   SOCSTEREO_COREDSP_INTDEM_BUFOVER_ERROR		(0x4187u)
#define   SOCSTEREO_COREM3_SERVICE_MEAS_ERROR		(0x4188u)
#define   SOCSTEREO_COREDSP_SERVICE_MEAS_ERROR		(0x4189u)
#define   SOCSTEREO_COREM3_SERVICE_EDMA_ERROR		(0x418Au)
#define   SOCSTEREO_COREDSP_SERVICE_EDMA_ERROR		(0x418Bu)
#define   SOCSTEREO_SERVICE_ONCHIPMEM_ERROR		(0x418Cu)
#define   SOCSTEREO_SERVICE_EVE_ERROR		(0x418Du)
#define   SOCSTEREO_COREM3_SERVICE_ICC_ERROR		(0x418Eu)
#define   SOCSTEREO_COREDSP_SERVICE_ICC_ERROR		(0x418Fu)
#define   SOCSTEREO_PCIE_DRIVER_SELFDIAG_ERROR		(0x4190u)
#define   SOCSTEREO_MCASP_DRIVER_SELFDIAG_ERROR		(0x4191u)
#define   SOCSTEREO_GPMC_DRIVER_SELFDIAG_ERROR		(0x4192u)
#define   SOCSTEREO_FPGA_ERROR_DL		(0x4193u)
#define   SOCSTEREO_FPGA_ERROR_DR		(0x4194u)
#define   SOCSTEREO_FPGA_ERROR_RL		(0x4195u)
#define   SOCSTEREO_FPGA_ERROR_RR		(0x4196u)
#define   SOCSTEREO_FPGA_ERROR_PF		(0x4197u)
#define   SOCSTEREO_FPGA_ERROR_SG		(0x4198u)
#define   SOCSTEREO_FPGA_ERROR_PD		(0x4199u)
#define   SOCSTEREO_FPGA_ERROR_SR		(0x419Au)
#define   SOCSTEREO_FPGA_ERROR_PERSISTANT		(0x419Bu)
#define   SOCSTEREO_FPGA_ERROR_STARTUP		(0x419Cu)
#define   SOCSTEREO_FPGA_ERROR_DEBAYER		(0x419Du)
#define   SOCSTEREO_FPGA_ERROR_VERSION		(0x419Eu)
#define   IPC_TX_TIMEOUT_SOC_MONO		(0x419Fu)
#define   IPC_CRC_FAILURE_CLUSTER_SOC_MONO		(0x41A0u)
#define   IPC_CLUSTER_UPDATE_ERR_SOC_MONO		(0x41A1u)
#define   SOCMONO_CPU_EXCEPTION		(0x41A2u)
#define   SOCMONO_TASK_MONITORING		(0x41A3u)
#define   SOCSTEREO_CPU_EXCEPTION		(0x41A4u)
#define   SOCSTEREO_TASK_MONITORING		(0x41A5u)
#define   SOCSTEREO_MON_FATAL_ERROR		(0x41A6u)
#define   VDY_E_YWR_OFFSET_RANGE		(0x41A7u)
#define   VDY_E_SWA_OFFSET_RANGE		(0x41A8u)
#define   VDY_E_AY_OFFSET_RANGE		(0x41A9u)
#define   VDY_E_VEL_CORR_RANGE		(0x41AAu)
#define   VDY_E_FS_YR_VS_WSP		(0x41ABu)
#define   VDY_E_FS_YR_VS_AY		(0x41ACu)
#define   VDY_E_FS_YR_VS_SWA		(0x41ADu)
#define   VDY_E_VEH_VEL_NOT_AVAILABLE		(0x41AEu)
#define   VDY_E_VEH_YWR_NOT_AVAILABLE		(0x41AFu)
#define   VDY_E_INPUTCHECK_YAW_RATE		(0x41B0u)
#define   VDY_E_INPUTCHECK_VHCL_VELOCITY		(0x41B1u)
#define   VDY_E_INPUTCHECK_WHL_VELOCITY_FR		(0x41B2u)
#define   VDY_E_INPUTCHECK_WHL_VELOCITY_FL		(0x41B3u)
#define   VDY_E_INPUTCHECK_WHL_VELOCITY_RR		(0x41B4u)
#define   VDY_E_INPUTCHECK_WHL_VELOCITY_RL		(0x41B5u)
#define   VDY_E_INPUTCHECK_STEERING_ANGLE		(0x41B6u)
#define   VDY_E_INPUTCHECK_LATERAL_ACCEL		(0x41B7u)
#define   VDY_E_INPUTCHECK_LONGITUDINAL_ACCEL		(0x41B8u)
#define   VDY_E_INPUTCHECK_DRIVING_CONDITION		(0x41B9u)
#define   MON_ADC_BIST_RUNTIME_TO_HIGH		(0x41BAu)
#define   SR_TEMP_BLOCKAGE		(0x41BBu)
#define   ECM_TEMP_BLOCKAGE		(0x41BCu)
#define   MEMO_TEMP_BLOCKAGE		(0x41BDu)
#define   SEMO_TEMP_BLOCKAGE		(0x41BEu)
#define   SAC_TEMP_BLOCKAGE		(0x41BFu)
#define   EBA_VHCL_TEMP_BLOCKAGE		(0x41C0u)
#define   EM_TEMP_BLOCKAGE		(0x41C1u)
#define   GEN_SOBJ_TEMP_BLOCKAGE		(0x41C2u)
#define   PED_TEMP_BLOCKAGE		(0x41C3u)
#define   VCL_TEMP_BLOCKAGE		(0x41C4u)
#define   FSD_TEMP_BLOCKAGE		(0x41C5u)

#endif
/* Total generated bytes: 25587 */
