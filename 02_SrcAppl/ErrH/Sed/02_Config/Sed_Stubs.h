/**
 * \file Sed_Stubs.h
 *
 * \brief
 *
 * \version refer the Sed_Core.h.
 *
 */

#ifndef SED_STUBS_H
#define SED_STUBS_H

/*==================[inclusions]============================================*/
#include "Sed_Type.h"
#include "Det.h"
#include <Std_Types.h>                            /* AUTOSAR standard types */
#include <TSAutosar.h>     /* EB specific standard types, TS_PARAM_UNUSED() */

/*==================[macros]=================================================*/
#define SED_EC_INACTIVE     0x00U
#define SED_EC_ACTIVE       0x01U

#define SED_GetBit(source, bitmask)   ( ((source) & (bitmask)) == (bitmask) )   // Get the corresponding Bit on the basis of the BITMASK

#define SED_GetBitMask(bitpos)        ((uint16)1u << (((uint16)bitpos) % 16u))  // Get the bit mask base on 16bit wide

/******************************************* SystemKernelErrMap software fault mask *************************************************************/
/*SystemKernelErrMap GroupID*/
#define SED_GROUPID_SystemKernelErrMap	  0U
/*bit 0-63*/
#define SED_BITPOS_kernel_i2c_ctrl0 				                              0u /*bit0*/
#define SED_BITPOS_kernel_i2c_ctrl1 				                              1u /*bit1*/
#define SED_BITPOS_kernel_i2c_ctrl2 				                              2u /*bit2*/
#define SED_BITPOS_kernel_i2c_ctrl3 				                              3u /*bit3*/
#define SED_BITPOS_kernel_i2c_ctrl4 				                              4u /*bit4*/
#define SED_BITPOS_kernel_i2c_ctrl5 				                              5u /*bit5*/
#define SED_BITPOS_kernel_mipi_host0 				                              6u /*bit6*/
#define SED_BITPOS_kernel_mipi_host1                                              7u /*bit7*/
#define SED_BITPOS_kernel_mipi_host2                                              8u /*bit8*/
#define SED_BITPOS_kernel_mipi_host3                                              9u /*bit9*/
#define SED_BITPOS_kernel_mipi_dev                                               10u /*bit10*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit11                             11u /*bit11*/
#define SED_BITPOS_kernel_ipu                                                    12u /*bit12*/
#define SED_BITPOS_kernel_isp_drop 		                                         13u /*bit13*/
#define SED_BITPOS_kernel_gdc0 			                                         14u /*bit14*/
#define SED_BITPOS_kernel_gdc1 	                                                 15u /*bit15*/
#define SED_BITPOS_kernel_ldc 		                                             16u /*bit16*/
#define SED_BITPOS_kernel_pym 	                                                 17u /*bit17*/
#define SED_BITPOS_kernel_sif0 			                                         18u /*bit18*/
#define SED_BITPOS_kernel_sif1 			                                         19u /*bit19*/
#define SED_BITPOS_kernel_sif2 				                                     20u /*bit20*/
#define SED_BITPOS_kernel_sif3 				                                     21u /*bit21*/
#define SED_BITPOS_kernel_sif4 				                                     22u /*bit22*/
#define SED_BITPOS_kernel_bpu0 				                                     23u /*bit23*/
#define SED_BITPOS_kernel_bpu1 					                                 24u /*bit24*/
#define SED_BITPOS_kernel_i2s0 					                                 25u /*bit25*/
#define SED_BITPOS_kernel_i2s1 						                             26u /*bit26*/
#define SED_BITPOS_kernel_bifspi 					                             27u /*bit27*/
#define SED_BITPOS_kernel_bifsd 					                             28u /*bit28*/
#define SED_BITPOS_kernel_bifspi_transfer 					                     29u /*bit29*/
#define SED_BITPOS_kernel_ethernet 					                             30u /*bit30*/
#define SED_BITPOS_kernel_spi0 					                                 31u /*bit31*/
#define SED_BITPOS_kernel_spi1 		                                             32u /*bit32*/
#define SED_BITPOS_kernel_spi2 	                                                 33u /*bit33*/
#define SED_BITPOS_kernel_emmc 			                                         34u /*bit34*/
#define SED_BITPOS_kernel_norflash 			                                     35u /*bit35*/
#define SED_BITPOS_kernel_cpu_cal_err 				                             36u /*bit36*/
#define SED_BITPOS_kernel_mpu_cnn0_fetch_err 				                     37u /*bit37*/
#define SED_BITPOS_kernel_mpu_cnn1_fetch_err 				                     38u /*bit38*/
#define SED_BITPOS_kernel_mpu_cnn0_other_err 				                     39u /*bit39*/
#define SED_BITPOS_kernel_mpu_cnn1_other_err 					                 40u /*bit40*/
#define SED_BITPOS_kernel_mpu_vio_m0_err 					                     41u /*bit41*/
#define SED_BITPOS_kernel_mpu_vpu_err 						                     42u /*bit42*/
#define SED_BITPOS_kernel_mpu_vio_m1_err 					                     43u /*bit43*/
#define SED_BITPOS_kernel_uart0 					                             44u /*bit44*/
#define SED_BITPOS_kernel_uart1 					                             45u /*bit45*/
#define SED_BITPOS_kernel_uart2 					                             46u /*bit46*/
#define SED_BITPOS_kernel_uart3 					                             47u /*bit47*/
#define SED_BITPOS_kernel_spi0_datalink_rc 		                                 48u /*bit48*/
#define SED_BITPOS_kernel_spi0_datalink_crc 	                                 49u /*bit49*/
#define SED_BITPOS_kernel_spi1_datalink_rc 			                             50u /*bit50*/
#define SED_BITPOS_kernel_spi1_datalink_crc 			                         51u /*bit51*/
#define SED_BITPOS_kernel_spi2_datalink_rc 				                         52u /*bit52*/
#define SED_BITPOS_kernel_spi2_datalink_crc 				                     53u /*bit53*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit54 				             54u /*bit54*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit55 				             55u /*bit55*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit56 					         56u /*bit56*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit57 					         57u /*bit57*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit58 						     58u /*bit58*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit59 					         59u /*bit59*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit60 					         60u /*bit60*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit61 					         61u /*bit61*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit62 					         62u /*bit62*/
#define SED_BITPOS_SystemKernelErrMap_Reserved_Bit63 					         63u /*bit63*/

/*bit 0-15*/
#define SED_BITMASK_kernel_i2c_ctrl0 				                              0X0001U /*bit0*/
#define SED_BITMASK_kernel_i2c_ctrl1 				                              0X0002U /*bit1*/
#define SED_BITMASK_kernel_i2c_ctrl2 				                              0X0004U /*bit2*/
#define SED_BITMASK_kernel_i2c_ctrl3 				                              0X0008U /*bit3*/
#define SED_BITMASK_kernel_i2c_ctrl4 				                              0X0010U /*bit4*/
#define SED_BITMASK_kernel_i2c_ctrl5 				                              0X0020U /*bit5*/
#define SED_BITMASK_kernel_mipi_host0 				                              0X0040U /*bit6*/
#define SED_BITMASK_kernel_mipi_host1                                             0X0080U /*bit7*/
#define SED_BITMASK_kernel_mipi_host2                                             0X0100U /*bit8*/
#define SED_BITMASK_kernel_mipi_host3                                             0x0200U /*bit9*/
#define SED_BITMASK_kernel_mipi_dev                                               0x0400U /*bit10*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit11                             0x0800U /*bit11*/
#define SED_BITMASK_kernel_ipu                                                    0x1000U /*bit12*/
#define SED_BITMASK_kernel_isp_drop 		                                      0X2000U /*bit13*/
#define SED_BITMASK_kernel_gdc0 			                                      0X4000U /*bit14*/
#define SED_BITMASK_kernel_gdc1 	                                              0X8000U /*bit15*/
/*bit 16-31*/
#define SED_BITMASK_kernel_ldc 		                                              0X0001U /*bit16*/
#define SED_BITMASK_kernel_pym 	                                                  0X0002U /*bit17*/
#define SED_BITMASK_kernel_sif0 			                                      0X0004U /*bit18*/
#define SED_BITMASK_kernel_sif1 			                                      0X0008U /*bit19*/
#define SED_BITMASK_kernel_sif2 				                                  0X0010U /*bit20*/
#define SED_BITMASK_kernel_sif3 				                                  0X0020U /*bit21*/
#define SED_BITMASK_kernel_sif4 				                                  0X0040U /*bit22*/
#define SED_BITMASK_kernel_bpu0 				                                  0X0080U /*bit23*/
#define SED_BITMASK_kernel_bpu1 					                              0X0100U /*bit24*/
#define SED_BITMASK_kernel_i2s0 					                              0X0200U /*bit25*/
#define SED_BITMASK_kernel_i2s1 						                          0X0400U /*bit26*/
#define SED_BITMASK_kernel_bifspi 					                              0X0800U /*bit27*/
#define SED_BITMASK_kernel_bifsd 					                              0X1000U /*bit28*/
#define SED_BITMASK_kernel_bifspi_transfer 					                      0X2000U /*bit29*/
#define SED_BITMASK_kernel_ethernet 					                          0X4000U /*bit30*/
#define SED_BITMASK_kernel_spi0 					                              0X8000U /*bit31*/
/*bit 32-47*/
#define SED_BITMASK_kernel_spi1 		                                          0X0001U /*bit32*/
#define SED_BITMASK_kernel_spi2 	                                              0X0002U /*bit33*/
#define SED_BITMASK_kernel_emmc 			                                      0X0004U /*bit34*/
#define SED_BITMASK_kernel_norflash 			                                  0X0008U /*bit35*/
#define SED_BITMASK_kernel_cpu_cal_err 				                              0X0010U /*bit36*/
#define SED_BITMASK_kernel_mpu_cnn0_fetch_err 				                      0X0020U /*bit37*/
#define SED_BITMASK_kernel_mpu_cnn1_fetch_err 				                      0X0040U /*bit38*/
#define SED_BITMASK_kernel_mpu_cnn0_other_err 				                      0X0080U /*bit39*/
#define SED_BITMASK_kernel_mpu_cnn1_other_err 					                  0X0100U /*bit40*/
#define SED_BITMASK_kernel_mpu_vio_m0_err 					                      0X0200U /*bit41*/
#define SED_BITMASK_kernel_mpu_vpu_err 						                      0X0400U /*bit42*/
#define SED_BITMASK_kernel_mpu_vio_m1_err 					                      0X0800U /*bit43*/
#define SED_BITMASK_kernel_uart0 					                              0X1000U /*bit44*/
#define SED_BITMASK_kernel_uart1 					                              0X2000U /*bit45*/
#define SED_BITMASK_kernel_uart2 					                              0X4000U /*bit46*/
#define SED_BITMASK_kernel_uart3 					                              0X8000U /*bit47*/
/*bit 48-63*/
#define SED_BITMASK_kernel_spi0_datalink_rc 		                              0X0001U /*bit48*/
#define SED_BITMASK_kernel_spi0_datalink_crc 	                                  0X0002U /*bit49*/
#define SED_BITMASK_kernel_spi1_datalink_rc 			                          0X0004U /*bit50*/
#define SED_BITMASK_kernel_spi1_datalink_crc 			                          0X0008U /*bit51*/
#define SED_BITMASK_kernel_spi2_datalink_rc 				                      0X0010U /*bit52*/
#define SED_BITMASK_kernel_spi2_datalink_crc 				                      0X0020U /*bit53*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit54 				              0X0040U /*bit54*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit55 				              0X0080U /*bit55*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit56 					          0X0100U /*bit56*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit57 					          0X0200U /*bit57*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit58 						      0X0400U /*bit58*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit59 					          0X0800U /*bit59*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit60 					          0X1000U /*bit60*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit61 					          0X2000U /*bit61*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit62 					          0X4000U /*bit62*/
#define SED_BITMASK_SystemKernelErrMap_Reserved_Bit63 					          0X8000U /*bit63*/

/*bit 0 12 13(0X3001)*/
#ifndef SED_BITMASK_KERNEL_GROUPCUT0
#define SED_BITMASK_KERNEL_GROUPCUT0	         (SED_BITMASK_kernel_i2c_ctrl0 | SED_BITPOS_kernel_i2c_ctrl2 | SED_BITMASK_kernel_ipu | SED_BITMASK_kernel_isp_drop)         
#endif

/*bit 17 18 23 24(0X0186)*/
#ifndef SED_BITMASK_KERNEL_GROUPCUT1
#define SED_BITMASK_KERNEL_GROUPCUT1	         (SED_BITMASK_kernel_pym | SED_BITMASK_kernel_sif0 | SED_BITMASK_kernel_bpu0 | SED_BITMASK_kernel_bpu1)         
#endif

/*bit 33 34 36 39 40 41 42 43 44(0X1F96)*/
#ifndef SED_BITMASK_KERNEL_GROUPCUT2
#define SED_BITMASK_KERNEL_GROUPCUT2	          (SED_BITMASK_kernel_spi2 | SED_BITMASK_kernel_emmc | SED_BITMASK_kernel_cpu_cal_err \
                                                   | SED_BITMASK_kernel_mpu_cnn0_other_err | SED_BITMASK_kernel_mpu_cnn1_other_err \
                                                   | SED_BITMASK_kernel_mpu_vio_m0_err | SED_BITMASK_kernel_mpu_vpu_err | SED_BITMASK_kernel_mpu_vio_m1_err \
                                                   | SED_BITMASK_kernel_uart0)		 
#endif

/*bit 52 53(0X0030)*/
#ifndef SED_BITMASK_KERNEL_GROUPCUT3
#define SED_BITMASK_KERNEL_GROUPCUT3		      (SED_BITMASK_kernel_spi2_datalink_rc | SED_BITMASK_kernel_spi2_datalink_crc)	 
#endif




/******************************************* SystemServiceErrMap software fault mask *************************************************************/
/*SystemServiceErrMap GroupID*/
#define SED_GROUPID_SystemServiceErrMap	    1U
/*bit 0-67*/
#define SED_BITPOS_higt_cpu_load 				                              0u /*bit0*/
#define SED_BITPOS_higt_cpu_temp 				                              1u /*bit1*/
#define SED_BITPOS_higt_memory 				                                  2u /*bit2*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_Bit3 				          3u /*bit3*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_Bit4 				          4u /*bit4*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_Bit5 				          5u /*bit5*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_Bit6 				          6u /*bit6*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_Bit7                          7u /*bit7*/
#define SED_BITPOS_ERROR_LOCATION_DIAG_COM                                    8u /*bit8*/
#define SED_BITPOS_ETH_link_down                                              9u /*bit9*/
#define SED_BITPOS_ETH_heartbeat_lost                                         10u /*bit10*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_Bit11                         11u /*bit11*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_Bit12                         12u /*bit12*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_Bit13 		                  13u /*bit13*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_Bit14 			              14u /*bit14*/
#define SED_BITPOS_cpu_high_temp_Level_2 	                                  15u /*bit15*/
#define SED_BITPOS_ADAS_high_cpu_load 		                                  16u /*bit16*/
#define SED_BITPOS_ADAS_high_memory 	                                      17u /*bit17*/
#define SED_BITPOS_Location_high_cpu_load 			                          18u /*bit18*/
#define SED_BITPOS_Location_high_memory 			                          19u /*bit19*/
#define SED_BITPOS_SystemSoftware_high_cpu_load 				              20u /*bit20*/
#define SED_BITPOS_SystemSoftware_high_memory 				                  21u /*bit21*/
#define SED_BITPOS_ADAS_miss 				                                  22u /*bit22*/
#define SED_BITPOS_Location_miss 				                              23u /*bit23*/
#define SED_BITPOS_SystemSoftware_miss 					                      24u /*bit24*/
#define SED_BITPOS_timesync_init_error 					                      25u /*bit25*/
#define SED_BITPOS_timesync_comm_error 						                  26u /*bit26*/
#define SED_BITPOS_timesync_delay 					                          27u /*bit27*/
#define SED_BITPOS_requset_OTA_fail 					                      28u /*bit28*/
#define SED_BITPOS_reveice_agent_package_fail 					              29u /*bit29*/
#define SED_BITPOS_manager_with_service_connect_fail 					      30u /*bit30*/
#define SED_BITPOS_Verify_signature_fail 					                  31u /*bit31*/
#define SED_BITPOS_send_package_J3A_fail 		                              32u /*bit32*/
#define SED_BITPOS_send_package_J3B_fail 	                                  33u /*bit33*/
#define SED_BITPOS_request_upgrade_J3A_fail 			                      34u /*bit34*/
#define SED_BITPOS_request_upgrade_J3B_fail 			                      35u /*bit35*/
#define SED_BITPOS_request_upgrade_J3C_fail 				                  36u /*bit36*/
#define SED_BITPOS_request_upgrade_MCU_fail 				                  37u /*bit37*/
#define SED_BITPOS_upgrade_time_out 				                          38u /*bit38*/
#define SED_BITPOS_init_manager_fail 				                          39u /*bit39*/
#define SED_BITPOS_check_ota_package_fail 					                  40u /*bit40*/
#define SED_BITPOS_ota_log_upload_fail 					                      41u /*bit41*/
#define SED_BITPOS_j3_upgrade_resutl_fail 						              42u /*bit42*/
#define SED_BITPOS_mcu_upgrade_resutl_fail 					                  43u /*bit43*/
#define SED_BITPOS_mcu_read_partition_fail 					                  44u /*bit44*/
#define SED_BITPOS_j3_set_partition_fail 					                  45u /*bit45*/
#define SED_BITPOS_mcu_set_partition_fail 					                  46u /*bit46*/
#define SED_BITPOS_j3_read_partition_fail 					                  47u /*bit47*/
#define SED_BITPOS_j3_rolback_set_partition_fail 		                      48u /*bit48*/
#define SED_BITPOS_mcu_rolback_set_partition_fail 	                          49u /*bit49*/
#define SED_BITPOS_j3_check_version_fail 			                          50u /*bit50*/
#define SED_BITPOS_mcu_check_version_fail 			                          51u /*bit51*/
#define SED_BITPOS_j3_check_partition_fail 				                      52u /*bit52*/
#define SED_BITPOS_mcu_check_partition_fail 				                  53u /*bit53*/
#define SED_BITPOS_j3_clear_userdata_fail 				                      54u /*bit54*/
#define SED_BITPOS_j3_do_not_find_upgrade_package 				              55u /*bit55*/
#define SED_BITPOS_j3_unzip_fail 					                          56u /*bit56*/
#define SED_BITPOS_j3_md5_check_fail 					                      57u /*bit57*/
#define SED_BITPOS_version_check_fail 						                  58u /*bit58*/
#define SED_BITPOS_gpt_is_not_compatible 					                  59u /*bit59*/
#define SED_BITPOS_app_upgrade_timeout 					                      60u /*bit60*/
#define SED_BITPOS_get_zip_size_fail 					                      61u /*bit61*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_bit62 					      62u /*bit62*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_bit63 					      63u /*bit63*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_bit64 		                  64u /*bit64*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_bit65 	                      65u /*bit65*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_bit66 			              66u /*bit66*/
#define SED_BITPOS_SystemServiceErrMap_Reserved_bit67 			              67u /*bit67*/

/*bit 0-15*/
#define SED_BITMASK_higt_cpu_load 				                              0X0001U /*bit0*/
#define SED_BITMASK_higt_cpu_temp 				                              0X0002U /*bit1*/
#define SED_BITMASK_higt_memory 				                              0X0004U /*bit2*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_Bit3 				          0X0008U /*bit3*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_Bit4 				          0X0010U /*bit4*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_Bit5 				          0X0020U /*bit5*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_Bit6 				          0X0040U /*bit6*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_Bit7                         0X0080U /*bit7*/
#define SED_BITMASK_ERROR_LOCATION_DIAG_COM                                   0X0100U /*bit8*/
#define SED_BITMASK_ETH_link_down                                             0x0200U /*bit9*/
#define SED_BITMASK_ETH_heartbeat_lost                                        0x0400U /*bit10*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_Bit11                        0x0800U /*bit11*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_Bit12                        0x1000U /*bit12*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_Bit13 		                  0X2000U /*bit13*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_Bit14 			              0X4000U /*bit14*/
#define SED_BITMASK_cpu_high_temp_Level_2 	                                  0X8000U /*bit15*/
/*bit 16-31*/
#define SED_BITMASK_ADAS_high_cpu_load 		                                  0X0001U /*bit16*/
#define SED_BITMASK_ADAS_high_memory 	                                      0X0002U /*bit17*/
#define SED_BITMASK_Location_high_cpu_load 			                          0X0004U /*bit18*/
#define SED_BITMASK_Location_high_memory 			                          0X0008U /*bit19*/
#define SED_BITMASK_SystemSoftware_high_cpu_load 				              0X0010U /*bit20*/
#define SED_BITMASK_SystemSoftware_high_memory 				                  0X0020U /*bit21*/
#define SED_BITMASK_ADAS_miss 				                                  0X0040U /*bit22*/
#define SED_BITMASK_Location_miss 				                              0X0080U /*bit23*/
#define SED_BITMASK_SystemSoftware_miss 					                  0X0100U /*bit24*/
#define SED_BITMASK_timesync_init_error 					                  0X0200U /*bit25*/
#define SED_BITMASK_timesync_comm_error 						              0X0400U /*bit26*/
#define SED_BITMASK_timesync_delay 					                          0X0800U /*bit27*/
#define SED_BITMASK_requset_OTA_fail 					                      0X1000U /*bit28*/
#define SED_BITMASK_reveice_agent_package_fail 					              0X2000U /*bit29*/
#define SED_BITMASK_manager_with_service_connect_fail 					      0X4000U /*bit30*/
#define SED_BITMASK_Verify_signature_fail 					                  0X8000U /*bit31*/
/*bit 32-47*/
#define SED_BITMASK_send_package_J3A_fail 		                              0X0001U /*bit32*/
#define SED_BITMASK_send_package_J3B_fail 	                                  0X0002U /*bit33*/
#define SED_BITMASK_request_upgrade_J3A_fail 			                      0X0004U /*bit34*/
#define SED_BITMASK_request_upgrade_J3B_fail 			                      0X0008U /*bit35*/
#define SED_BITMASK_request_upgrade_J3C_fail 				                  0X0010U /*bit36*/
#define SED_BITMASK_request_upgrade_MCU_fail 				                  0X0020U /*bit37*/
#define SED_BITMASK_upgrade_time_out 				                          0X0040U /*bit38*/
#define SED_BITMASK_init_manager_fail 				                          0X0080U /*bit39*/
#define SED_BITMASK_check_ota_package_fail 					                  0X0100U /*bit40*/
#define SED_BITMASK_ota_log_upload_fail 					                  0X0200U /*bit41*/
#define SED_BITMASK_j3_upgrade_resutl_fail 						              0X0400U /*bit42*/
#define SED_BITMASK_mcu_upgrade_resutl_fail 					              0X0800U /*bit43*/
#define SED_BITMASK_mcu_read_partition_fail 					              0X1000U /*bit44*/
#define SED_BITMASK_j3_set_partition_fail 					                  0X2000U /*bit45*/
#define SED_BITMASK_mcu_set_partition_fail 					                  0X4000U /*bit46*/
#define SED_BITMASK_j3_read_partition_fail 					                  0X8000U /*bit47*/
/*bit 48-63*/
#define SED_BITMASK_j3_rolback_set_partition_fail 		                      0X0001U /*bit48*/
#define SED_BITMASK_mcu_rolback_set_partition_fail 	                          0X0002U /*bit49*/
#define SED_BITMASK_j3_check_version_fail 			                          0X0004U /*bit50*/
#define SED_BITMASK_mcu_check_version_fail 			                          0X0008U /*bit51*/
#define SED_BITMASK_j3_check_partition_fail 				                  0X0010U /*bit52*/
#define SED_BITMASK_mcu_check_partition_fail 				                  0X0020U /*bit53*/
#define SED_BITMASK_j3_clear_userdata_fail 				                      0X0040U /*bit54*/
#define SED_BITMASK_j3_do_not_find_upgrade_package 				              0X0080U /*bit55*/
#define SED_BITMASK_j3_unzip_fail 					                          0X0100U /*bit56*/
#define SED_BITMASK_j3_md5_check_fail 					                      0X0200U /*bit57*/
#define SED_BITMASK_version_check_fail 						                  0X0400U /*bit58*/
#define SED_BITMASK_gpt_is_not_compatible 					                  0X0800U /*bit59*/
#define SED_BITMASK_app_upgrade_timeout 					                  0X1000U /*bit60*/
#define SED_BITMASK_get_zip_size_fail 					                      0X2000U /*bit61*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_bit62 					      0X4000U /*bit62*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_bit63 					      0X8000U /*bit63*/
/*bit 64-79*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_bit64 		                  0X0001U /*bit64*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_bit65 	                      0X0002U /*bit65*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_bit66 			              0X0004U /*bit66*/
#define SED_BITMASK_SystemServiceErrMap_Reserved_bit67 			              0X0008U /*bit67*/


/*bit 0 1 2 3 15(0X800F)*/
#ifndef SED_BITMASK_SYSSERVICE_GROUPCUT0
#define SED_BITMASK_SYSSERVICE_GROUPCUT0 	        (SED_BITMASK_higt_cpu_load | SED_BITMASK_higt_cpu_temp | SED_BITMASK_higt_memory \
                                                     | SED_BITMASK_SystemServiceErrMap_Reserved_Bit3 | SED_BITMASK_cpu_high_temp_Level_2) 	
#endif

/*bit 22(0X0040)*/
#ifndef SED_BITMASK_SYSSERVICE_GROUPCUT1
#define SED_BITMASK_SYSSERVICE_GROUPCUT1	        (SED_BITMASK_ADAS_miss)      
#endif	

/*bit 65(0X0002)*/
#ifndef SED_BITMASK_SYSSERVICE_GROUPCUT4
#define SED_BITMASK_SYSSERVICE_GROUPCUT4	        (SED_BITMASK_SystemServiceErrMap_Reserved_bit65) 	
#endif

/******************************************* ADASErrMap software fault mask *************************************************************/
/*ADASErrMap  GroupID*/
#define SED_GROUPID_ADASErrMap	2U
/*bit 0-63*/
#define SED_BITPOS_adas_0_diagnose_image_input 				                  0u /*bit0*/
#define SED_BITPOS_adas_0_diagnose_image_order 				                  1u /*bit1*/
#define SED_BITPOS_adas_0_diagnose_image_freezed 				              2u /*bit2*/
#define SED_BITPOS_adas_0_diagnose_image_covered 				              3u /*bit3*/
#define SED_BITPOS_adas_0_diagnose_image_blurred 				              4u /*bit4*/
#define SED_BITPOS_adas_0_diagnose_image_glare 				                  5u /*bit5*/
#define SED_BITPOS_adas_0_diagnose_dynamic_calibration_pitc 				  6u /*bit6*/
#define SED_BITPOS_adas_0_diagnose_dynamic_calibration_yaw                    7u /*bit7*/
#define SED_BITPOS_adas_0_diagnose_dynamic_calibration_roll                   8u /*bit8*/
#define SED_BITPOS_adas_0_diagnose_app_performance_fps_low                    9u /*bit9*/
#define SED_BITPOS_adas_0_diagnose_network_block                             10u /*bit10*/
#define SED_BITPOS_adas_0_diagnose_mono_extrinsic_calibration_find_corners   11u /*bit11*/
#define SED_BITPOS_adas_0_diagnose_mono_extrinsic_calibration_reproject      12u /*bit12*/
#define SED_BITPOS_adas_0_diagnose_odometry_outofrange 		                 13u /*bit13*/
#define SED_BITPOS_adas_0_diagnose_odometry_timeout 			             14u /*bit14*/
#define SED_BITPOS_adas_0_diagnose_online_calibration_pitch 	             15u /*bit15*/
#define SED_BITPOS_adas_0_diagnose_online_calibration_yaw 		             16u /*bit16*/
#define SED_BITPOS_adas_0_diagnose_online_calibration_roll 	                 17u /*bit17*/
#define SED_BITPOS_adas_0_diagnose_can_signal_speed 			             18u /*bit18*/
#define SED_BITPOS_adas_0_diagnose_can_signal_yawrate 			             19u /*bit19*/
#define SED_BITPOS_adas_0_diagnose_can_signal_speed_timeout 				 20u /*bit20*/
#define SED_BITPOS_adas_0_diagnose_can_signal_yawrate_timeout 				 21u /*bit21*/
#define SED_BITPOS_adas_0_diagnose_can_signal_speed_stable 				     22u /*bit22*/
#define SED_BITPOS_adas_0_diagnose_can_signal_yawrate_stable 				 23u /*bit23*/
#define SED_BITPOS_adas_0_diagnose_foggy 					                 24u /*bit24*/
#define SED_BITPOS_adas_0_diagnose_heavy_rain 					             25u /*bit25*/
#define SED_BITPOS_adas_0_diagnose_snow 						             26u /*bit26*/
#define SED_BITPOS_adas_0_diagnose_low_sun 					                 27u /*bit27*/
#define SED_BITPOS_adas_0_diagnose_forward_timeout 					         28u /*bit28*/
#define SED_BITPOS_adas_0_diagnose_forward_block 					         29u /*bit29*/
#define SED_BITPOS_adas_0_diagnose_config 					                 30u /*bit30*/
#define SED_BITPOS_adas_0_diagnose_bpu_task_timeout 					     31u /*bit31*/
#define SED_BITPOS_adas_0_diagnose_bpu_task_abondon 		                 32u /*bit32*/
#define SED_BITPOS_adas_0_diagnose_bpu_task_start_fail 	                     33u /*bit33*/
#define SED_BITPOS_adas_0_diagnose_forward_order_error 			             34u /*bit34*/
#define SED_BITPOS_adas_0_diagnose_abnormal_detection_result 			     35u /*bit35*/
#define SED_BITPOS_adas_0_diagnose_abnormal_parsing_result 				     36u /*bit36*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit37 				             37u /*bit37*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit38 				             38u /*bit38*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit39 				             39u /*bit39*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit40 					         40u /*bit40*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit41 					         41u /*bit41*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit42 						     42u /*bit42*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit43 					         43u /*bit43*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit44 					         44u /*bit44*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit45 					         45u /*bit45*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit46 					         46u /*bit46*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit47 					         47u /*bit47*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit48 		                     48u /*bit48*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit49 	                         49u /*bit49*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit50 			                 50u /*bit50*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit51 			                 51u /*bit51*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit52 				             52u /*bit52*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit53 				             53u /*bit53*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit54 				             54u /*bit54*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit55 				             55u /*bit55*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit56 					         56u /*bit56*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit57 					         57u /*bit57*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit58 						     58u /*bit58*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit59 					         59u /*bit59*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit60 					         60u /*bit60*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit61 					         61u /*bit61*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit62 					         62u /*bit62*/
#define SED_BITPOS_adas_0_diagnose_Reserved_bit63 					         63u /*bit63*/

/*bit 0-15*/
#define SED_BITMASK_adas_0_diagnose_image_input 				              0X0001U /*bit0*/
#define SED_BITMASK_adas_0_diagnose_image_order 				              0X0002U /*bit1*/
#define SED_BITMASK_adas_0_diagnose_image_freezed 				              0X0004U /*bit2*/
#define SED_BITMASK_adas_0_diagnose_image_covered 				              0X0008U /*bit3*/
#define SED_BITMASK_adas_0_diagnose_image_blurred 				              0X0010U /*bit4*/
#define SED_BITMASK_adas_0_diagnose_image_glare 				              0X0020U /*bit5*/
#define SED_BITMASK_adas_0_diagnose_dynamic_calibration_pitc 				  0X0040U /*bit6*/
#define SED_BITMASK_adas_0_diagnose_dynamic_calibration_yaw                   0X0080U /*bit7*/
#define SED_BITMASK_adas_0_diagnose_dynamic_calibration_roll                  0X0100U /*bit8*/
#define SED_BITMASK_adas_0_diagnose_app_performance_fps_low                   0x0200U /*bit9*/
#define SED_BITMASK_adas_0_diagnose_network_block                             0x0400U /*bit10*/
#define SED_BITMASK_adas_0_diagnose_mono_extrinsic_calibration_find_corners   0x0800U /*bit11*/
#define SED_BITMASK_adas_0_diagnose_mono_extrinsic_calibration_reproject      0x1000U /*bit12*/
#define SED_BITMASK_adas_0_diagnose_odometry_outofrange 		              0X2000U /*bit13*/
#define SED_BITMASK_adas_0_diagnose_odometry_timeout 			              0X4000U /*bit14*/
#define SED_BITMASK_adas_0_diagnose_online_calibration_pitch 	              0X8000U /*bit15*/
/*bit 16-31*/
#define SED_BITMASK_adas_0_diagnose_online_calibration_yaw 		              0X0001U /*bit16*/
#define SED_BITMASK_adas_0_diagnose_online_calibration_roll 	              0X0002U /*bit17*/
#define SED_BITMASK_adas_0_diagnose_can_signal_speed 			              0X0004U /*bit18*/
#define SED_BITMASK_adas_0_diagnose_can_signal_yawrate 			              0X0008U /*bit19*/
#define SED_BITMASK_adas_0_diagnose_can_signal_speed_timeout 				  0X0010U /*bit20*/
#define SED_BITMASK_adas_0_diagnose_can_signal_yawrate_timeout 				  0X0020U /*bit21*/
#define SED_BITMASK_adas_0_diagnose_can_signal_speed_stable 				  0X0040U /*bit22*/
#define SED_BITMASK_adas_0_diagnose_can_signal_yawrate_stable 				  0X0080U /*bit23*/
#define SED_BITMASK_adas_0_diagnose_foggy 					                  0X0100U /*bit24*/
#define SED_BITMASK_adas_0_diagnose_heavy_rain 					              0X0200U /*bit25*/
#define SED_BITMASK_adas_0_diagnose_snow 						              0X0400U /*bit26*/
#define SED_BITMASK_adas_0_diagnose_low_sun 					              0X0800U /*bit27*/
#define SED_BITMASK_adas_0_diagnose_forward_timeout 					      0X1000U /*bit28*/
#define SED_BITMASK_adas_0_diagnose_forward_block 					          0X2000U /*bit29*/
#define SED_BITMASK_adas_0_diagnose_config 					                  0X4000U /*bit30*/
#define SED_BITMASK_adas_0_diagnose_bpu_task_timeout 					      0X8000U /*bit31*/
/*bit 32-47*/
#define SED_BITMASK_adas_0_diagnose_bpu_task_abondon 		                  0X0001U /*bit32*/
#define SED_BITMASK_adas_0_diagnose_bpu_task_start_fail 	                  0X0002U /*bit33*/
#define SED_BITMASK_adas_0_diagnose_forward_order_error 			          0X0004U /*bit34*/
#define SED_BITMASK_adas_0_diagnose_abnormal_detection_result 			      0X0008U /*bit35*/
#define SED_BITMASK_adas_0_diagnose_abnormal_parsing_result 				  0X0010U /*bit36*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit37 				              0X0020U /*bit37*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit38 				              0X0040U /*bit38*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit39 				              0X0080U /*bit39*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit40 					          0X0100U /*bit40*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit41 					          0X0200U /*bit41*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit42 						      0X0400U /*bit42*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit43 					          0X0800U /*bit43*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit44 					          0X1000U /*bit44*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit45 					          0X2000U /*bit45*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit46 					          0X4000U /*bit46*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit47 					          0X8000U /*bit47*/
/*bit 48-63*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit48 		                      0X0001U /*bit48*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit49 	                          0X0002U /*bit49*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit50 			                  0X0004U /*bit50*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit51 			                  0X0008U /*bit51*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit52 				              0X0010U /*bit52*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit53 				              0X0020U /*bit53*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit54 				              0X0040U /*bit54*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit55 				              0X0080U /*bit55*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit56 					          0X0100U /*bit56*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit57 					          0X0200U /*bit57*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit58 						      0X0400U /*bit58*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit59 					          0X0800U /*bit59*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit60 					          0X1000U /*bit60*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit61 					          0X2000U /*bit61*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit62 					          0X4000U /*bit62*/
#define SED_BITMASK_adas_0_diagnose_Reserved_bit63 					          0X8000U /*bit63*/

/*bit 0 1 9 10 13 14(0X6603)*/
#ifndef SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT0
#define SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT0 			(SED_BITMASK_adas_0_diagnose_image_input | SED_BITMASK_adas_0_diagnose_image_order | SED_BITMASK_adas_0_diagnose_app_performance_fps_low \
                                                         | SED_BITMASK_adas_0_diagnose_network_block | SED_BITMASK_adas_0_diagnose_odometry_outofrange| SED_BITMASK_adas_0_diagnose_odometry_timeout)	
#endif

 /*bit 18 19 20 21 28 29 30 31(0XF03C)*/
#ifndef SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT1
#define SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT1 		    (SED_BITMASK_adas_0_diagnose_can_signal_speed | SED_BITMASK_adas_0_diagnose_can_signal_yawrate | SED_BITMASK_adas_0_diagnose_can_signal_speed_timeout \
                                                         | SED_BITMASK_adas_0_diagnose_can_signal_yawrate_timeout | SED_BITMASK_adas_0_diagnose_forward_timeout | SED_BITMASK_adas_0_diagnose_forward_block \
                                                         | SED_BITMASK_adas_0_diagnose_config | SED_BITMASK_adas_0_diagnose_bpu_task_timeout)			
#endif

/*bit 32 33 34 35 36 40 46 47(0XC11F)*/
#ifndef SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT2
#define SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT2 	        (SED_BITMASK_adas_0_diagnose_bpu_task_abondon| SED_BITMASK_adas_0_diagnose_bpu_task_start_fail | SED_BITMASK_adas_0_diagnose_forward_order_error \
                                                          | SED_BITMASK_adas_0_diagnose_abnormal_detection_result | SED_BITMASK_adas_0_diagnose_abnormal_parsing_result | SED_BITMASK_adas_0_diagnose_Reserved_bit40 \
                                                          | SED_BITMASK_adas_0_diagnose_Reserved_bit46 | SED_BITMASK_adas_0_diagnose_Reserved_bit47)	
#endif

/*bit 48 (0X0001)*/
#ifndef SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT3
#define SED_BITMASK_ADAS_0_DIAGNOSE_GROUPCUT3 		    (SED_BITMASK_adas_0_diagnose_Reserved_bit48)	
#endif
		 
/******************************************* CameraErrMap software fault mask *************************************************************/
/*CameraErrMap*/
#define SED_GROUPID_CAMERAERR	3U
/*bit 0-63*/
#define SED_BITPOS_camera_init_0 				                              0u /*bit0*/
#define SED_BITPOS_camera_init_1 				                              1u /*bit1*/
#define SED_BITPOS_camera_init_2 				                              2u /*bit2*/
#define SED_BITPOS_camera_init_3 				                              3u /*bit3*/
#define SED_BITPOS_camera_init_4 				                              4u /*bit4*/
#define SED_BITPOS_sensor_temperature_0 				                      5u /*bit5*/
#define SED_BITPOS_sensor_temperature_1 				                      6u /*bit6*/
#define SED_BITPOS_sensor_temperature_2                                       7u /*bit7*/
#define SED_BITPOS_sensor_temperature_3                                       8u /*bit8*/
#define SED_BITPOS_sensor_temperature_4                                       9u /*bit9*/
#define SED_BITPOS_sensor_test_pattern_0                                     10u /*bit10*/
#define SED_BITPOS_sensor_test_pattern_1                                     11u /*bit11*/
#define SED_BITPOS_sensor_test_pattern_2                                     12u /*bit12*/
#define SED_BITPOS_sensor_test_pattern_3 		                             13u /*bit13*/
#define SED_BITPOS_sensor_test_pattern_4 			                         14u /*bit14*/
#define SED_BITPOS_sensor_system_check_0 	                                 15u /*bit15*/
#define SED_BITPOS_sensor_system_check_1 		                             16u /*bit16*/
#define SED_BITPOS_sensor_system_check_2 	                                 17u /*bit17*/
#define SED_BITPOS_sensor_system_check_3 			                         18u /*bit18*/
#define SED_BITPOS_sensor_system_check_4 			                         19u /*bit19*/
#define SED_BITPOS_serdser_lock_0 				                             20u /*bit20*/
#define SED_BITPOS_serdser_lock_1 				                             21u /*bit21*/
#define SED_BITPOS_serdser_lock_2 				                             22u /*bit22*/
#define SED_BITPOS_serdser_lock_3 				                             23u /*bit23*/
#define SED_BITPOS_serdser_lock_4 					                         24u /*bit24*/
#define SED_BITPOS_sensor_fcnt_test_0 					                     25u /*bit25*/
#define SED_BITPOS_sensor_fcnt_test_1 						                 26u /*bit26*/
#define SED_BITPOS_sensor_fcnt_test_2 					                     27u /*bit27*/
#define SED_BITPOS_sensor_fcnt_test_3 					                     28u /*bit28*/
#define SED_BITPOS_sensor_fcnt_test_4 					                     29u /*bit29*/
#define SED_BITPOS_sensor_i2c_crc_0 					                     30u /*bit30*/
#define SED_BITPOS_sensor_i2c_crc_1 					                     31u /*bit31*/
#define SED_BITPOS_sensor_i2c_crc_2 		                                 32u /*bit32*/
#define SED_BITPOS_sensor_i2c_crc_3 	                                     33u /*bit33*/
#define SED_BITPOS_sensor_i2c_crc_4 			                             34u /*bit34*/
#define SED_BITPOS_sensor_poc_check_0 			                             35u /*bit35*/
#define SED_BITPOS_sensor_poc_check_1 				                         36u /*bit36*/
#define SED_BITPOS_sensor_poc_check_2 				                         37u /*bit37*/
#define SED_BITPOS_sensor_poc_check_3 				                         38u /*bit38*/
#define SED_BITPOS_sensor_poc_check_4 				                         39u /*bit39*/
#define SED_BITPOS_CameraErrMap_Reserved_bit40 					             40u /*bit40*/
#define SED_BITPOS_CameraErrMap_Reserved_bit41 					             41u /*bit41*/
#define SED_BITPOS_CameraErrMap_Reserved_bit42 						         42u /*bit42*/
#define SED_BITPOS_CameraErrMap_Reserved_bit43 					             43u /*bit43*/
#define SED_BITPOS_CameraErrMap_Reserved_bit44 					             44u /*bit44*/
#define SED_BITPOS_CameraErrMap_Reserved_bit45 					             45u /*bit45*/
#define SED_BITPOS_CameraErrMap_Reserved_bit46 					             46u /*bit46*/
#define SED_BITPOS_CameraErrMap_Reserved_bit47 					             47u /*bit47*/
#define SED_BITPOS_CameraErrMap_Reserved_bit48 		                         48u /*bit48*/
#define SED_BITPOS_CameraErrMap_Reserved_bit49 	                             49u /*bit49*/
#define SED_BITPOS_CameraErrMap_Reserved_bit50 			                     50u /*bit50*/
#define SED_BITPOS_CameraErrMap_Reserved_bit51 			                     51u /*bit51*/
#define SED_BITPOS_CameraErrMap_Reserved_bit52 				                 52u /*bit52*/
#define SED_BITPOS_CameraErrMap_Reserved_bit53 				                 53u /*bit53*/
#define SED_BITPOS_CameraErrMap_Reserved_bit54 				                 54u /*bit54*/
#define SED_BITPOS_CameraErrMap_Reserved_bit55 				                 55u /*bit55*/
#define SED_BITPOS_CameraErrMap_Reserved_bit56 					             56u /*bit56*/
#define SED_BITPOS_CameraErrMap_Reserved_bit57 					             57u /*bit57*/
#define SED_BITPOS_CameraErrMap_Reserved_bit58 						         58u /*bit58*/
#define SED_BITPOS_CameraErrMap_Reserved_bit59 					             59u /*bit59*/
#define SED_BITPOS_CameraErrMap_Reserved_bit60 					             60u /*bit60*/
#define SED_BITPOS_CameraErrMap_Reserved_bit61 					             61u /*bit61*/
#define SED_BITPOS_CameraErrMap_Reserved_bit62 					             62u /*bit62*/
#define SED_BITPOS_CameraErrMap_Reserved_bit63 					             63u /*bit63*/

/*bit 0-15*/
#define SED_BITMASK_camera_init_0 				                              0X0001U /*bit0*/
#define SED_BITMASK_camera_init_1 				                              0X0002U /*bit1*/
#define SED_BITMASK_camera_init_2 				                              0X0004U /*bit2*/
#define SED_BITMASK_camera_init_3 				                              0X0008U /*bit3*/
#define SED_BITMASK_camera_init_4 				                              0X0010U /*bit4*/
#define SED_BITMASK_sensor_temperature_0 				                      0X0020U /*bit5*/
#define SED_BITMASK_sensor_temperature_1 				                      0X0040U /*bit6*/
#define SED_BITMASK_sensor_temperature_2                                      0X0080U /*bit7*/
#define SED_BITMASK_sensor_temperature_3                                      0X0100U /*bit8*/
#define SED_BITMASK_sensor_temperature_4                                      0x0200U /*bit9*/
#define SED_BITMASK_sensor_test_pattern_0                                     0x0400U /*bit10*/
#define SED_BITMASK_sensor_test_pattern_1                                     0x0800U /*bit11*/
#define SED_BITMASK_sensor_test_pattern_2                                     0x1000U /*bit12*/
#define SED_BITMASK_sensor_test_pattern_3 		                              0X2000U /*bit13*/
#define SED_BITMASK_sensor_test_pattern_4 			                          0X4000U /*bit14*/
#define SED_BITMASK_sensor_system_check_0 	                                  0X8000U /*bit15*/
/*bit 16-31*/
#define SED_BITMASK_sensor_system_check_1 		                              0X0001U /*bit16*/
#define SED_BITMASK_sensor_system_check_2 	                                  0X0002U /*bit17*/
#define SED_BITMASK_sensor_system_check_3 			                          0X0004U /*bit18*/
#define SED_BITMASK_sensor_system_check_4 			                          0X0008U /*bit19*/
#define SED_BITMASK_serdser_lock_0 				                              0X0010U /*bit20*/
#define SED_BITMASK_serdser_lock_1 				                              0X0020U /*bit21*/
#define SED_BITMASK_serdser_lock_2 				                              0X0040U /*bit22*/
#define SED_BITMASK_serdser_lock_3 				                              0X0080U /*bit23*/
#define SED_BITMASK_serdser_lock_4 					                          0X0100U /*bit24*/
#define SED_BITMASK_sensor_fcnt_test_0 					                      0X0200U /*bit25*/
#define SED_BITMASK_sensor_fcnt_test_1 						                  0X0400U /*bit26*/
#define SED_BITMASK_sensor_fcnt_test_2 					                      0X0800U /*bit27*/
#define SED_BITMASK_sensor_fcnt_test_3 					                      0X1000U /*bit28*/
#define SED_BITMASK_sensor_fcnt_test_4 					                      0X2000U /*bit29*/
#define SED_BITMASK_sensor_i2c_crc_0 					                      0X4000U /*bit30*/
#define SED_BITMASK_sensor_i2c_crc_1 					                      0X8000U /*bit31*/
/*bit 32-47*/
#define SED_BITMASK_sensor_i2c_crc_2 		                                  0X0001U /*bit32*/
#define SED_BITMASK_sensor_i2c_crc_3 	                                      0X0002U /*bit33*/
#define SED_BITMASK_sensor_i2c_crc_4 			                              0X0004U /*bit34*/
#define SED_BITMASK_sensor_poc_check_0 			                              0X0008U /*bit35*/
#define SED_BITMASK_sensor_poc_check_1 				                          0X0010U /*bit36*/
#define SED_BITMASK_sensor_poc_check_2 				                          0X0020U /*bit37*/
#define SED_BITMASK_sensor_poc_check_3 				                          0X0040U /*bit38*/
#define SED_BITMASK_sensor_poc_check_4 				                          0X0080U /*bit39*/
#define SED_BITMASK_CameraErrMap_Reserved_bit40 					          0X0100U /*bit40*/
#define SED_BITMASK_CameraErrMap_Reserved_bit41 					          0X0200U /*bit41*/
#define SED_BITMASK_CameraErrMap_Reserved_bit42 						      0X0400U /*bit42*/
#define SED_BITMASK_CameraErrMap_Reserved_bit43 					          0X0800U /*bit43*/
#define SED_BITMASK_CameraErrMap_Reserved_bit44 					          0X1000U /*bit44*/
#define SED_BITMASK_CameraErrMap_Reserved_bit45 					          0X2000U /*bit45*/
#define SED_BITMASK_CameraErrMap_Reserved_bit46 					          0X4000U /*bit46*/
#define SED_BITMASK_CameraErrMap_Reserved_bit47 					          0X8000U /*bit47*/
/*bit 48-63*/
#define SED_BITMASK_CameraErrMap_Reserved_bit48 		                      0X0001U /*bit48*/
#define SED_BITMASK_CameraErrMap_Reserved_bit49 	                          0X0002U /*bit49*/
#define SED_BITMASK_CameraErrMap_Reserved_bit50 			                  0X0004U /*bit50*/
#define SED_BITMASK_CameraErrMap_Reserved_bit51 			                  0X0008U /*bit51*/
#define SED_BITMASK_CameraErrMap_Reserved_bit52 				              0X0010U /*bit52*/
#define SED_BITMASK_CameraErrMap_Reserved_bit53 				              0X0020U /*bit53*/
#define SED_BITMASK_CameraErrMap_Reserved_bit54 				              0X0040U /*bit54*/
#define SED_BITMASK_CameraErrMap_Reserved_bit55 				              0X0080U /*bit55*/
#define SED_BITMASK_CameraErrMap_Reserved_bit56 					          0X0100U /*bit56*/
#define SED_BITMASK_CameraErrMap_Reserved_bit57 					          0X0200U /*bit57*/
#define SED_BITMASK_CameraErrMap_Reserved_bit58 						      0X0400U /*bit58*/
#define SED_BITMASK_CameraErrMap_Reserved_bit59 					          0X0800U /*bit59*/
#define SED_BITMASK_CameraErrMap_Reserved_bit60 					          0X1000U /*bit60*/
#define SED_BITMASK_CameraErrMap_Reserved_bit61 					          0X2000U /*bit61*/
#define SED_BITMASK_CameraErrMap_Reserved_bit62 					          0X4000U /*bit62*/
#define SED_BITMASK_CameraErrMap_Reserved_bit63 					          0X8000U /*bit63*/

/*bit 0 5(0X0021)*/
#ifndef SED_BITMASK_CAMERA_ERROR_GROUPCUT0
#define SED_BITMASK_CAMERA_ERROR_GROUPCUT0 				    	 (SED_BITMASK_camera_init_0 | SED_BITMASK_sensor_temperature_0)
#endif

/*bit 25 30(0X4200)*/
#ifndef SED_BITMASK_CAMERA_ERROR_GROUPCUT1
#define SED_BITMASK_CAMERA_ERROR_GROUPCUT1 		                 (SED_BITMASK_sensor_fcnt_test_0 | SED_BITMASK_sensor_i2c_crc_0)		    	 
#endif

/*bit 35(0X0008)*/
#ifndef SED_BITMASK_CAMERA_ERROR_GROUPCUT2
#define SED_BITMASK_CAMERA_ERROR_GROUPCUT2			    	     (SED_BITMASK_sensor_poc_check_0) 
#endif

/*bit 50(0X0004)*/
#ifndef SED_BITMASK_CAMERA_ERROR_GROUPCUT3
#define SED_BITMASK_CAMERA_ERROR_GROUPCUT3  			         (SED_BITMASK_CameraErrMap_Reserved_bit50)    
#endif


/******************************************* SafetylibErrMap software fault mask *************************************************************/
/*safety testlib fault*/
#define SED_GROUPID_SAFETYLIB		4U
/*bitposition 0-15*/
#define SED_BITPOS_ddr_ecc_check 				                              0u /*bit0*/
#define SED_BITPOS_ddr_ecc_check_tiemout 				                      1u /*bit1*/
#define SED_BITPOS_bpu_check 				                                  2u /*bit2*/
#define SED_BITPOS_RCore_alu_check 				                              3u /*bit3*/
#define SED_BITPOS_bpu_check_timeout 				                          4u /*bit4*/
#define SED_BITPOS_ddr_dataline_check 				                          5u /*bit5*/
#define SED_BITPOS_ddr_dataline_check_timeout 				                  6u /*bit6*/
#define SED_BITPOS_safe_reg_check                                             7u /*bit7*/
#define SED_BITPOS_safe_reg_check_timeout                                     8u /*bit8*/
#define SED_BITPOS_soc_temperature_check                                      9u /*bit9*/
#define SED_BITPOS_soc_temperature_check_timeout                             10u /*bit10*/
#define SED_BITPOS_nvm_crc_check                                             11u /*bit11*/
#define SED_BITPOS_qa_btwn_acore_check                                       12u /*bit12*/
#define SED_BITPOS_qa_btwn_acore_check_timeout 		                         13u /*bit13*/
#define SED_BITPOS_ddr_ecc_func_check 			                             14u /*bit14*/
#define SED_BITPOS_SafetyLibErrMap_Reserved_Bit15 	                         15u /*bit15*/

/*bitmask 0-15*/
#define SED_BITMASK_ddr_ecc_check 				                              0X0001U /*bit0*/
#define SED_BITMASK_ddr_ecc_check_tiemout 				                      0X0002U /*bit1*/
#define SED_BITMASK_bpu_check 				                                  0X0004U /*bit2*/
#define SED_BITMASK_RCore_alu_check 				                          0X0008U /*bit3*/
#define SED_BITMASK_bpu_check_timeout 				                          0X0010U /*bit4*/
#define SED_BITMASK_ddr_dataline_check 				                          0X0020U /*bit5*/
#define SED_BITMASK_ddr_dataline_check_timeout 				                  0X0040U /*bit6*/
#define SED_BITMASK_safe_reg_check                                            0X0080U /*bit7*/
#define SED_BITMASK_safe_reg_check_timeout                                    0X0100U /*bit8*/
#define SED_BITMASK_soc_temperature_check                                     0x0200U /*bit9*/
#define SED_BITMASK_soc_temperature_check_timeout                             0x0400U /*bit10*/
#define SED_BITMASK_nvm_crc_check                                             0x0800U /*bit11*/
#define SED_BITMASK_qa_btwn_acore_check                                       0x1000U /*bit12*/
#define SED_BITMASK_qa_btwn_acore_check_timeout 		                      0X2000U /*bit13*/
#define SED_BITMASK_ddr_ecc_func_check 			                              0X4000U /*bit14*/
#define SED_BITMASK_SafetyLibErrMap_Reserved_Bit15 	                          0X8000U /*bit15*/
/*bitmask 16-31 (RESERVED)*/

/*bit 2 3 4 5 6 7 8 9 10 11 12 13(0X3FFC)*/
#ifndef SED_BITMASK_SAFETYLIB_GROUPCUT0
#define SED_BITMASK_SAFETYLIB_GROUPCUT0 		                (SED_BITMASK_bpu_check | SED_BITMASK_RCore_alu_check | SED_BITMASK_bpu_check_timeout | SED_BITMASK_ddr_dataline_check \
                                                                 | SED_BITMASK_ddr_dataline_check_timeout | SED_BITMASK_safe_reg_check | SED_BITMASK_safe_reg_check_timeout \
                                                                 | SED_BITMASK_soc_temperature_check_timeout | SED_BITMASK_nvm_crc_check \
                                                                 | SED_BITMASK_qa_btwn_acore_check | SED_BITMASK_qa_btwn_acore_check_timeout) 
#endif


#define SED_GROUPID_MAX          SED_GROUPID_SAFETYLIB


/*==================[type definitions]=======================================*/



/*==================[external function declarations]========================*/
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocTimeSyncError(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocSystemKernelError(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocSystemServiceError(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocCameraError(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocSafetylibError(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocPerceptionError(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_SocTempExtTooHigh(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_CPUErrorPWMMissing(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_CameraBlockage(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_CameraCalibrationFailure(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_CameraAutoCalibrationFailure(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthUnexpectedLinkDown(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthDriverAbnormal(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthCrcError(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthLinkSignalWake(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthCableFault(void);
extern FUNC(boolean, RTE_CODE) Sed_EnableCondition_EthIcmpError(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_EthUnexpectedLinkDown(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_EthDriverAbnormal(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_EthCrcError(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_EthLinkSignalWake(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_EthCableFault(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_EthIcmpError(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_SocTimeSyncError(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_SocSafetylibError(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_SocPerceptionError(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_SocCameraError(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_SocSystemServiceError(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_SocSystemKernelError(void); 
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_SocTempExtTooHigh(void); 
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_CameraAutoCalibrationFailure(void); 
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_CameraCalibrationFailure(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_CameraBlockage(void);
extern FUNC(boolean, RTE_CODE) Sed_TestFailed_CPUErrorPWMMissing(void);


#endif /* SED_STUBS_H */