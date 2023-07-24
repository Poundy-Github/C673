/**
 * \file Cdd_Sbc_Cfg.h
 *
 * \brief  Configuration data and stubs function of PMIC.
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2023.01.22			  xxx			        Init version
 *
 *
 */

#ifndef __CDD_SBC_CFG_H_
#define __CDD_SBC_CFG_H_

#include "Std_Types.h"
#include "pmic_pf8x.h"
#include "pmic_pf8x_assert.h"
#include "pmic_pf8x_common.h"
#include "pmic_pf82_map.h"
#include "pmic_pf502x.h"
#include "pmic_pf502x_assert.h"
#include "pmic_pf502x_common.h"
#include "pmic_pf5024_map.h"
#include "sbc_fs8x.h"
#include "sbc_fs8x_assert.h"
#include "sbc_fs8x_common.h"
#include "sbc_fs8x_communication.h"
#include "sbc_fs8x_map.h"
#include "I2c.h"


#define FS8400_I2C_ADDRESS_OTP (0x00U)
#define PF5024_I2C_ADDRESS_OTP (0x00U)
#define PF8200_I2C_ADDRESS_OTP (0x01U)

extern const fs8x_drv_data_t fs8400drvData;
extern const pf8x_drv_data_t pf8200drvData;
extern const pf502x_drv_data_t pf5024drvData;
#endif

