/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * @file pmic_pf502x.c
 * @brief Implementation of I2C communication logic for NXP PMIC PF502x.
 *
 * @author nxa22158, nxa23158
 * @version 1.0
 * @date 18-December-2020
 * @copyright Copyright (c) 2021 NXP
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <pmic_pf502x.h>
#include <pmic_pf502x_assert.h>
#include <stddef.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* I2C frame. */
#define PF502X_ADDRESS_BASE 0x08U      /* I2C device base address */
#define PF502X_COMM_FRAME_SIZE 0x03U   /* Length of the communication frame */
#define PF502X_FRAME_SIZE 0x04U        /* Length of the complete I2C frame */
#define PF502X_READ_FRAME_LENGTH 0x01U /* Length of the data frame for I2C read command. */
#define PF502X_RX_SIZE 0x02U           /* Length of the received I2C data frame */

/* CRC polynomial. */
#define PF502X_CRC_TBL_SIZE 256U       /* Size of CRC table. */
#define PF502X_CRC_POLYNOM 0x1DU       /* CRC polynom. */
#define PF502X_CRC_INIT 0xFFU          /* CRC initial value. */

/*******************************************************************************
 * Constants
 ******************************************************************************/

/** @brief CRC lookup table. */
static const uint8_t PF502X_CRC_TABLE[PF502X_CRC_TBL_SIZE] = { 0x00U, 0x1DU,
		0x3AU, 0x27U, 0x74U, 0x69U, 0x4EU, 0x53U, 0xE8U, 0xF5U, 0xD2U, 0xCFU,
		0x9CU, 0x81U, 0xA6U, 0xBBU, 0xCDU, 0xD0U, 0xF7U, 0xEAU, 0xB9U, 0xA4U,
		0x83U, 0x9EU, 0x25U, 0x38U, 0x1FU, 0x02U, 0x51U, 0x4CU, 0x6BU, 0x76U,
		0x87U, 0x9AU, 0xBDU, 0xA0U, 0xF3U, 0xEEU, 0xC9U, 0xD4U, 0x6FU, 0x72U,
		0x55U, 0x48U, 0x1BU, 0x06U, 0x21U, 0x3CU, 0x4AU, 0x57U, 0x70U, 0x6DU,
		0x3EU, 0x23U, 0x04U, 0x19U, 0xA2U, 0xBFU, 0x98U, 0x85U, 0xD6U, 0xCBU,
		0xECU, 0xF1U, 0x13U, 0x0EU, 0x29U, 0x34U, 0x67U, 0x7AU, 0x5DU, 0x40U,
		0xFBU, 0xE6U, 0xC1U, 0xDCU, 0x8FU, 0x92U, 0xB5U, 0xA8U, 0xDEU, 0xC3U,
		0xE4U, 0xF9U, 0xAAU, 0xB7U, 0x90U, 0x8DU, 0x36U, 0x2BU, 0x0CU, 0x11U,
		0x42U, 0x5FU, 0x78U, 0x65U, 0x94U, 0x89U, 0xAEU, 0xB3U, 0xE0U, 0xFDU,
		0xDAU, 0xC7U, 0x7CU, 0x61U, 0x46U, 0x5BU, 0x08U, 0x15U, 0x32U, 0x2FU,
		0x59U, 0x44U, 0x63U, 0x7EU, 0x2DU, 0x30U, 0x17U, 0x0AU, 0xB1U, 0xACU,
		0x8BU, 0x96U, 0xC5U, 0xD8U, 0xFFU, 0xE2U, 0x26U, 0x3BU, 0x1CU, 0x01U,
		0x52U, 0x4FU, 0x68U, 0x75U, 0xCEU, 0xD3U, 0xF4U, 0xE9U, 0xBAU, 0xA7U,
		0x80U, 0x9DU, 0xEBU, 0xF6U, 0xD1U, 0xCCU, 0x9FU, 0x82U, 0xA5U, 0xB8U,
		0x03U, 0x1EU, 0x39U, 0x24U, 0x77U, 0x6AU, 0x4DU, 0x50U, 0xA1U, 0xBCU,
		0x9BU, 0x86U, 0xD5U, 0xC8U, 0xEFU, 0xF2U, 0x49U, 0x54U, 0x73U, 0x6EU,
		0x3DU, 0x20U, 0x07U, 0x1AU, 0x6CU, 0x71U, 0x56U, 0x4BU, 0x18U, 0x05U,
		0x22U, 0x3FU, 0x84U, 0x99U, 0xBEU, 0xA3U, 0xF0U, 0xEDU, 0xCAU, 0xD7U,
		0x35U, 0x28U, 0x0FU, 0x12U, 0x41U, 0x5CU, 0x7BU, 0x66U, 0xDDU, 0xC0U,
		0xE7U, 0xFAU, 0xA9U, 0xB4U, 0x93U, 0x8EU, 0xF8U, 0xE5U, 0xC2U, 0xDFU,
		0x8CU, 0x91U, 0xB6U, 0xABU, 0x10U, 0x0DU, 0x2AU, 0x37U, 0x64U, 0x79U,
		0x5EU, 0x43U, 0xB2U, 0xAFU, 0x88U, 0x95U, 0xC6U, 0xDBU, 0xFCU, 0xE1U,
		0x5AU, 0x47U, 0x60U, 0x7DU, 0x2EU, 0x33U, 0x14U, 0x09U, 0x7FU, 0x62U,
		0x45U, 0x58U, 0x0BU, 0x16U, 0x31U, 0x2CU, 0x97U, 0x8AU, 0xADU, 0xB0U,
		0xE3U, 0xFEU, 0xD9U, 0xC4U };

/*******************************************************************************
 * Local Functions Prototypes
 ******************************************************************************/

/** @brief This function calculates CRC value of passed data array.
 *         Takes bytes in inverted order due to frame format.
 *
 * @param [in] data     Data array.
 * @param [in] dataLen  Length of the data array.
 *
 * @return CRC8
 */
static uint8_t PF502X_CalcCRC(const uint8_t *data, uint8_t dataLen);

/** @brief Performs CRC check of the data array.
 *
 * CRC is expected in the first array item (index 0).
 *
 * @param [in] data     Data array.
 * @param [in] dataLen  Length of the data array.
 *
 * @return Returns pf502xStatusOk if CRC is correct.
 */
static pf502x_status_t PF502X_CheckCRC(const uint8_t *data, uint8_t dataLen);

/** @brief Returns 7-bit I2C address.
 *
 * @param [in] drvData  Driver run-time data.
 *
 * @return PF502x I2C address.
 */
static uint8_t PF502X_GetI2CAddress(const pf502x_drv_data_t *drvData);

/*******************************************************************************
 * Local Variables
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * Local Functions - Implementation
 ******************************************************************************/

/* This function calculates CRC value of passed data array.
 * Takes bytes in inverted order due to frame format. */
static uint8_t PF502X_CalcCRC(const uint8_t *data, uint8_t dataLen) {
	uint8_t crc; /* Result. */
	uint8_t tableIdx; /* Index to the CRC table. */
	uint8_t dataIdx; /* Index to the data array (memory). */

	/* Set CRC seed value. */
	crc = PF502X_CRC_INIT;

	for (dataIdx = dataLen - 1; dataIdx > 0; dataIdx--) {
		tableIdx = crc ^ data[dataIdx];
		crc = PF502X_CRC_TABLE[tableIdx];
	}
	return crc;
}

/* Performs CRC check of the data array. */
static pf502x_status_t PF502X_CheckCRC(const uint8_t *data, uint8_t dataLen) {
	uint8_t frameCrc; /* CRC value from resp. */
	uint8_t compCrc; /* Computed CRC value. */

	/* Check CRC. */
	frameCrc = data[0];
	compCrc = PF502X_CalcCRC(data, dataLen);
	return (compCrc != frameCrc) ? pf502xStatusError : pf502xStatusOk;
}

/* Returns 7-bit I2C address. */
static uint8_t PF502X_GetI2CAddress(const pf502x_drv_data_t *drvData) {
	uint8_t i2cAddress = PF502X_ADDRESS_BASE;

	i2cAddress = PF502X_BO_SETVAL(i2cAddress, drvData->i2cAddressOtp, 0x07U);

	return i2cAddress;
}

/*******************************************************************************
 * API - Implementation
 ******************************************************************************/

/* Performs a single read register based on provided address. */
pf502x_status_t PF502X_ReadRegister(const pf502x_drv_data_t *drvData,
		uint8_t address, uint8_t *rxData) {
	pf502x_status_t status;
	uint8_t i2cAddress;
	uint8_t txFrame[PF502X_READ_FRAME_LENGTH] = { 0 };
	uint8_t rxFrameCrc[PF502X_FRAME_SIZE] = { 0 };
	uint8_t rxFrame[PF502X_FRAME_SIZE - 3U] = { 0 };

	FS_ASSERT(drvData != NULL);
	FS_ASSERT(rxData != NULL);

	i2cAddress = PF502X_GetI2CAddress(drvData);
	txFrame[0] = address;

	/* Send I2C command with register address only. */
	status = PF5x_MCU_I2C_SendData(txFrame, PF502X_READ_FRAME_LENGTH, i2cAddress);
	if (status != pf502xStatusOk) {
		return status;
	}

	if (drvData->crcEnabled) {
		/* Read 2 bytes - 1 data byte, 1 CRC byte. */
		status = PF5x_MCU_I2C_ReceiveData(PF502X_RX_SIZE, i2cAddress, rxFrameCrc);
		if (status != pf502xStatusOk) {
			return status;
		}

		/* I2C response frame contains just data and CRC.
		 * The Device address and Register address is added
		 * for proper CRC check. */
		rxFrameCrc[2] = address;
		rxFrameCrc[3] = (uint8_t) ((i2cAddress << 1U) | 0x01U); /* R/W bit is 1 for I2C read */

		/* Check CRC. */
		status = PF502X_CheckCRC(rxFrameCrc, PF502X_FRAME_SIZE);
		if (status != pf502xStatusOk) {
			return status;
		}

		*rxData = rxFrameCrc[1];
	} else {
		/* Read 1 byte - data byte only, no CRC. */
		status = PF5x_MCU_I2C_ReceiveData(PF502X_RX_SIZE - 1U, i2cAddress, rxFrame);
		if (status != pf502xStatusOk) {
			return status;
		}

		*rxData = rxFrame[0];
	}

	return pf502xStatusOk;
}

/* Sends write command to the PF502x. */
pf502x_status_t PF502X_WriteRegister(const pf502x_drv_data_t *drvData,
		uint8_t address, uint8_t writeData) {
	uint8_t i2cAddress;
	uint8_t txFrameCrc[PF502X_FRAME_SIZE] = { 0 };
	uint8_t txFrame[PF502X_FRAME_SIZE - 1U] = { 0 };

	FS_ASSERT(drvData != NULL);

	i2cAddress = PF502X_GetI2CAddress(drvData);

	if (drvData->crcEnabled) {
		txFrameCrc[3] = (uint8_t) (i2cAddress << 1U); /* R/W bit is 0 for write */

		/* Sets address of the register (first two bits are ignored). */
		txFrameCrc[2] = address;

		/* Sets data. */
		txFrameCrc[1] = writeData;

		/* Add CRC. */
		txFrameCrc[0] = PF502X_CalcCRC(txFrameCrc, PF502X_FRAME_SIZE);

		/* Write 3 bytes - register address byte, data byte, CRC byte. */
		return PF5x_MCU_I2C_SendData(txFrameCrc, PF502X_COMM_FRAME_SIZE, i2cAddress);
	} else {
		txFrame[2] = (uint8_t) (i2cAddress << 1U); /* R/W bit is 0 for write */

		/* Sets address of the register (first two bits are ignored). */
		txFrame[1] = address;

		/* Sets data. */
		txFrame[0] = writeData;

		/* Write 2 bytes - register address byte, data byte, no CRC. */
		return PF5x_MCU_I2C_SendData(txFrame, PF502X_COMM_FRAME_SIZE - 1U,
				i2cAddress);
	}
}

/* Performs a write to a single PF82 secured register. */
pf502x_status_t PF502X_WriteRegisterSecured(const pf502x_drv_data_t *drvData,
		uint8_t address, uint8_t writeData) {
	pf502x_status_t status;
	uint8_t rxData = 0;

	FS_ASSERT(drvData != NULL);

	/* Write data to secured register. */
	status = PF502X_WriteRegister(drvData, address, writeData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Read generated random code from RANDOM_GEN register. */
	status = PF502X_ReadRegister(drvData, PF502X_RANDOM_GEN_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Write generated random code to RANDOM_CHK register. */
	return PF502X_WriteRegister(drvData, PF502X_RANDOM_CHK_ADDR, rxData);
}

/* Reads device identification information. */
pf502x_status_t PF502X_GetId(const pf502x_drv_data_t *drvData,
		uint8_t *deviceFamily, uint8_t *deviceId, uint8_t *fullRev,
		uint8_t *metalRev, uint8_t *emRev, uint16_t *progId) {
	pf502x_status_t status;
	uint8_t rxData = 0;

	FS_ASSERT(drvData != NULL);

	/* Skip reading DEVICE_ID register, if deviceFamily or deviceID is NULL. */
	if ((deviceFamily != NULL) && (deviceId != NULL)) {
		/* Read DEVICE_ID register. */
		status = PF502X_ReadRegister(drvData, PF502X_DEVICE_ID_ADDR, &rxData);
		if (status != pf502xStatusOk) {
			return status;
		}

		/* Store device family and device ID. */
		*deviceFamily = (rxData & PF502X_F_DEVICE_FAM_MASK)
				>> PF502X_F_DEVICE_FAM_SHIFT;
		*deviceId = (rxData & PF502X_F_DEVICE_ID_MASK)
				>> PF502X_F_DEVICE_ID_SHIFT;
	}

	/* Skip reading REV_ID register, if fullRev or metalRev is NULL. */
	if ((fullRev != NULL) && (metalRev != NULL)) {
		/* Read REV_ID register. */
		status = PF502X_ReadRegister(drvData, PF502X_REV_ID_ADDR, &rxData);
		if (status != pf502xStatusOk) {
			return status;
		}

		/* Store full layer revision and metal layer revision. */
		*fullRev = (rxData & PF502X_F_FULL_LAYER_REV_MASK)
				>> PF502X_F_FULL_LAYER_REV_SHIFT;
		*metalRev = (rxData & PF502X_F_METAL_LAYER_REV_MASK)
				>> PF502X_F_METAL_LAYER_REV_SHIFT;
	}

	/* Skip reading EMREV and PROG_ID register, if emRev or progId is NULL. */
	if ((emRev != NULL) && (progId != NULL)) {
		/* Read EMREV register. */
		status = PF502X_ReadRegister(drvData, PF502X_EMREV_ADDR, &rxData);
		if (status != pf502xStatusOk) {
			return status;
		}

		/* Store program ID high byte and EMREV. */
		*progId = ((rxData & PF502X_F_PROG_IDH_MASK) >> PF502X_F_PROG_IDH_SHIFT)
				<< 8U;
		*emRev = (rxData & PF502X_F_EMREV_MASK) >> PF502X_F_EMREV_SHIFT;

		/* Read PROG_ID register. */
		status = PF502X_ReadRegister(drvData, PF502X_PROG_ID_ADDR, &rxData);
		if (status != pf502xStatusOk) {
			return status;
		}

		/* Store program ID low byte. */
		*progId |=
				((rxData & PF502X_F_PROG_IDL_MASK) >> PF502X_F_PROG_IDL_SHIFT);
	}

	return pf502xStatusOk;
}

/* Sets power up/down configuration. */
pf502x_status_t PF502X_SetPowerSequence(const pf502x_drv_data_t *drvData,
		px5x_pin_reg_t pinReg, uint8_t seqSlot) {
	FS_ASSERT(drvData != NULL);

	/* Write settings to PWRUP register. */
	return PF502X_WriteRegister(drvData, (uint8_t) pinReg, seqSlot);
}

/* Sets buck regulator configuration. */
pf502x_status_t PF502X_SetBuckConfig(const pf502x_drv_data_t *drvData,
		pf502x_reg_buck_t buckSwNum,
		bool uvBypass, bool ovBypass, bool ilimBypass, bool uvState,
		bool ovState,
		bool ilimState, bool wdBypass, bool pgoodEnable, bool fltRen,
		bool vttEnable, uint8_t dvsRamp, uint8_t ilim, uint8_t phase) {
	pf502x_status_t status;
	uint8_t rxData = 0x00;

	FS_ASSERT(drvData != NULL);

	/* Write mode settings to selected regulator CONFIG1 register. */
	status = PF502X_WriteRegister(drvData,
			PF502X_SW1_CONFIG1_ADDR + (8 * (uint8_t) buckSwNum),
			(((uint8_t) uvBypass << PF502X_F_SW1_UV_BYPASS_SHIFT)
					| ((uint8_t) ovBypass << PF502X_F_SW1_OV_BYPASS_SHIFT)
					| ((uint8_t) ilimBypass << PF502X_F_SW1_ILIM_BYPASS_SHIFT)
					| ((uint8_t) uvState << PF502X_F_SW1_UV_STATE_SHIFT)
					| ((uint8_t) ovState << PF502X_F_SW1_OV_STATE_SHIFT)
					| ((uint8_t) ilimState << PF502X_F_SW1_ILIM_STATE_SHIFT)
					| ((uint8_t) wdBypass << PF502X_F_SW1_WDBYPASS_SHIFT)
					| ((uint8_t) pgoodEnable << PF502X_F_SW1_PG_EN_SHIFT)));
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Write settings to selected regulator CONFIG2 register. */
	status = PF502X_WriteRegister(drvData,
			PF502X_SW1_CONFIG2_ADDR + (8 * (uint8_t) buckSwNum),
			(((uint8_t) fltRen << PF502X_F_SW1_FLT_REN_SHIFT)
					| ((uint8_t) vttEnable << PF502X_F_SW2_VTTEN_SHIFT) | ilim
					| phase));

	if (status != pf502xStatusOk) {
		return status;
	}

	if (buckSwNum <= pf502xRegBuckSW4) {
		/* Read out SW_RAMP register to get settings for other regulators. */
		status = PF502X_ReadRegister(drvData, PF502X_SW_RAMP_ADDR, &rxData);

		if (status != pf502xStatusOk) {
			return status;
		}

		rxData = PF502X_BO_SETVAL(rxData, dvsRamp,
				(PF502X_F_SW1DVS_RAMP_MASK << ((uint8_t)buckSwNum * 2)));

		/* Write to SW_RAMP register updated settings for SW1-4 regulators. */
		status = PF502X_WriteRegister(drvData, PF502X_SW_RAMP_ADDR, rxData);
	}

	return status;
}

/* Sets buck regulator mode and power down group. */
pf502x_status_t PF502X_SetBuckModeConfig(const pf502x_drv_data_t *drvData,
		pf502x_reg_buck_t buckSwNum, pf502x_reg_powerdown_t pdGroup,
		pf502x_reg_mode_t runMode, pf502x_reg_mode_t stbyMode) {
	FS_ASSERT(drvData != NULL);

	/* Write mode settings to selected regulator MODE register. */
	return PF502X_WriteRegister(drvData,
			PF502X_SW1_MODE1_ADDR + (8 * (uint8_t) buckSwNum),
			(((uint8_t)pdGroup << PF502X_F_SW1_PDGRP_SHIFT)
					| ((uint8_t)stbyMode << PF502X_F_SW1_STBY_MODE_SHIFT)
					| ((uint8_t)runMode << PF502X_F_SW1_RUN_MODE_SHIFT)));
}

/* Sets buck regulator voltage. */
pf502x_status_t PF502X_SetBuckVoltage(const pf502x_drv_data_t *drvData,
		pf502x_reg_buck_t buckSwNum, pf502x_reg_state_t regState,
		uint8_t voltage) {
	pf502x_status_t status = pf502xStatusOk;

	FS_ASSERT(drvData != NULL);

	/* Write voltage to selected regulator VOLT register. */
	if (buckSwNum <= pf502xRegBuckSW4) {
		status = PF502X_WriteRegister(drvData,
				PF502X_SW1_RUN_VOLT_ADDR + (uint8_t)regState + (8 * (uint8_t)buckSwNum),
				voltage);
	}

#if PF502X_DEVICE == PF502X_DEVICE_PF5020
	if (buckSwNum == pf502xRegBuckSWND) {
		status = PF502X_WriteRegister(drvData, PF502X_SWND1_RUN_VOLT_ADDR,
				voltage);
	}
#endif

	return status;
}

#ifdef PF502X_LDO_FEATURE
/* Sets LDO regulator configuration. */
pf502x_status_t PF502X_SetLdoConfig(const pf502x_drv_data_t *drvData,
		pf502x_reg_ldo_t ldoNum,
		bool uvBypass, bool ovBypass, bool ilimBypass, bool uvState,
		bool ovState,
		bool ilimState, bool wdBypass, bool pgoodEnable) {
	FS_ASSERT(drvData != NULL);

	/* Write settings to selected regulator CONFIG1 register. */
	return PF502X_WriteRegister(drvData,
			PF502X_LDO1_CONFIG1_ADDR + (6 * (uint8_t) ldoNum),
			(((uint8_t) uvBypass << PF502X_F_LDO1_UV_BYPASS_SHIFT)
					| ((uint8_t) ovBypass << PF502X_F_LDO1_OV_BYPASS_SHIFT)
					| ((uint8_t) ilimBypass << PF502X_F_LDO1_ILIM_BYPASS_SHIFT)
					| ((uint8_t) uvState << PF502X_F_LDO1_UV_STATE_SHIFT)
					| ((uint8_t) ovState << PF502X_F_LDO1_OV_STATE_SHIFT)
					| ((uint8_t) ilimState << PF502X_F_LDO1_ILIM_STATE_SHIFT)
					| ((uint8_t) wdBypass << PF502X_F_LDO1_WDBYPASS_SHIFT)
					| ((uint8_t) pgoodEnable << PF502X_F_LDO1_PG_EN_SHIFT)));
}

/* Sets LDO regulator mode and power down group. */
pf502x_status_t PF502X_SetLdoModeConfig(const pf502x_drv_data_t *drvData,
		pf502x_reg_ldo_t ldoNum,
		bool fltRen, pf502x_reg_powerdown_t pdGroup, bool runEnable,
		bool stbyEnable) {
	FS_ASSERT(drvData != NULL);

	/* Write mode settings to selected regulator CONFIG2 register. */
	return PF502X_WriteRegister(drvData,
			PF502X_LDO1_CONFIG2_ADDR + (6 * (uint8_t)ldoNum),
			(((uint8_t)fltRen << PF502X_F_LDO1_FLT_REN_SHIFT)
					| ((uint8_t)pdGroup << PF502X_F_LDO1_PDGRP_SHIFT)
					| ((uint8_t)runEnable << PF502X_F_LDO1_RUN_EN_SHIFT)
					| ((uint8_t)stbyEnable << PF502X_F_LDO1_STBY_EN_SHIFT)));
}

/* Sets LDO regulator voltage. */
pf502x_status_t PF502X_SetLdoVoltage(const pf502x_drv_data_t *drvData,
		pf502x_reg_ldo_t ldoNum, pf502x_reg_state_t regState, uint8_t voltage) {
	FS_ASSERT(drvData != NULL);

	/* Write voltage to selected regulator VOLT register. */
	return PF502X_WriteRegister(drvData,
			PF502X_LDO1_RUN_VOLT_ADDR + (uint8_t)regState + (6 * (uint8_t)ldoNum),
			voltage);
}
#endif

#ifdef PF502x_VSNVS_FEATURE
/* Sets VSNVS regulator voltage. */
pf502x_status_t PF502X_SetVsnvsVoltage(const pf502x_drv_data_t *drvData,
		uint8_t voltage) {
	FS_ASSERT(drvData != NULL);

	/* Write voltage to selected regulator VOLT register. */
	return PF502X_WriteRegister(drvData, PF502X_VSNVS_CONFIG1_ADDR, voltage);
}
#endif

/* Set frequency configuration of the PMIC. */
pf502x_status_t PF502X_SetFreqConfig(const pf502x_drv_data_t *drvData,
		bool syncoutEnable, pf502x_fsync_range_t fsyncRange, bool fssEnable,
		pf502x_fss_range_t fssRange, uint8_t clkFreq) {
	FS_ASSERT(drvData != NULL);

	/* Write settings to FREQ_CTRL register. */
	return PF502X_WriteRegister(drvData, PF502X_FREQ_CTRL_ADDR,
			((syncoutEnable << PF502X_F_SYNCOUT_EN_SHIFT) | (uint8_t)fsyncRange
					| (fssEnable << PF502X_F_FSS_EN_SHIFT) | (uint8_t)fssRange | clkFreq));
}

/* Sets input voltage monitor configuration. */
pf502x_status_t PF502X_SetVinOvloConfig(const pf502x_drv_data_t *drvData,
		bool ovloEnable,
		bool ovloShutdown, pf502x_ovlo_dbnc_t ovloDebounce) {
	pf502x_status_t status;
	uint8_t rxData = 0;

	FS_ASSERT(drvData != NULL);

	/* Read CTRL1 register. */
	status = PF502X_ReadRegister(drvData, PF502X_CTRL1_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Clear bits before changing them. */
	rxData &= ~(PF502X_F_VIN_OVLO_EN_MASK | PF502X_F_VIN_OVLO_SDWN_MASK);
	/* Modify register content. */
	rxData |= ((uint8_t) ovloEnable << PF502X_F_VIN_OVLO_EN_SHIFT)
			| ((uint8_t) ovloShutdown << PF502X_F_VIN_OVLO_SDWN_SHIFT);

	/* Write settings to CTRL1 register. */
	if (drvData->secureEnabled) {
		status = PF502X_WriteRegisterSecured(drvData, PF502X_CTRL1_ADDR,
				rxData);
	} else {
		status = PF502X_WriteRegister(drvData, PF502X_CTRL1_ADDR, rxData);
	}
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Read CTRL2 register. */
	status = PF502X_ReadRegister(drvData, PF502X_CTRL2_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Clear bits before changing them. */
	rxData &= ~(PF502X_F_VIN_OVLO_DBNC_MASK);
	/* Modify register content. */
	rxData |= (uint8_t)ovloDebounce;

	/* Write settings to CTRL2 register. */
	return PF502X_WriteRegister(drvData, PF502X_CTRL2_ADDR, rxData);
}

/* Sets voltage monitor configuration. */
pf502x_status_t PF502X_SetVoltMonitorConfig(const pf502x_drv_data_t *drvData,
		uint8_t swMonMask, uint8_t ldoMonMask) {
	pf502x_status_t status;

	FS_ASSERT(drvData != NULL);

	/* Write settings to VMONEN1 register. */
	if (drvData->secureEnabled) {
		status = PF502X_WriteRegisterSecured(drvData, PF502X_VMONEN1_ADDR,
				swMonMask);
	} else {
		status = PF502X_WriteRegister(drvData, PF502X_VMONEN1_ADDR, swMonMask);
	}
	if (status != pf502xStatusOk) {
		return status;
	}

#ifdef PF502X_LDO_FEATURE
	/* Write settings to VMONEN2 register. */
	if (drvData->secureEnabled) {
		status = PF502X_WriteRegisterSecured(drvData, PF502X_VMONEN2_ADDR,
				ldoMonMask);
	} else {
		status = PF502X_WriteRegister(drvData, PF502X_VMONEN2_ADDR, ldoMonMask);
	}
#endif

	return status;
}

/* Sets temperature monitor configuration. */
pf502x_status_t PF502X_SetTempMonitorConfig(const pf502x_drv_data_t *drvData,
bool tempMonEnable, bool tempMonAon) {
	pf502x_status_t status;
	uint8_t rxData = 0;

	FS_ASSERT(drvData != NULL);

	/* Read CTRL1 register. */
	status = PF502X_ReadRegister(drvData, PF502X_CTRL1_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Clear bits before changing them. */
	rxData &= ~(PF502X_F_TMP_MON_EN_MASK);
	/* Modify register content. */
	rxData |= (uint8_t) tempMonEnable << PF502X_F_TMP_MON_EN_SHIFT;

	/* Write settings to CTRL1 register. */
	if (drvData->secureEnabled) {
		status = PF502X_WriteRegisterSecured(drvData, PF502X_CTRL1_ADDR,
				rxData);
	} else {
		status = PF502X_WriteRegister(drvData, PF502X_CTRL1_ADDR, rxData);
	}
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Read CTRL2 register. */
	status = PF502X_ReadRegister(drvData, PF502X_CTRL2_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Clear bits before changing them. */
	rxData &= ~(PF502X_F_TMP_MON_AON_MASK);
	/* Modify register content. */
	rxData |= (uint8_t) tempMonAon << PF502X_F_TMP_MON_AON_SHIFT;

	/* Write settings to CTRL2 register. */
	return PF502X_WriteRegister(drvData, PF502X_CTRL2_ADDR, rxData);
}

/* Reads interrupt flags from selected interrupt group. */
pf502x_status_t PF502X_GetInterrupts(const pf502x_drv_data_t *drvData,
		pf502x_int_group_t intGroup, uint8_t *intStatus) {
	FS_ASSERT(drvData != NULL);
	FS_ASSERT(intStatus != NULL);

	/* Read interrupt register. */
	return PF502X_ReadRegister(drvData, (uint8_t)intGroup, intStatus);
}

/* Clears selected interrupt flags from selected interrupt group. */
pf502x_status_t PF502X_ClearInterrupts(const pf502x_drv_data_t *drvData,
		pf502x_int_group_t intGroup, uint8_t intMask) {
	FS_ASSERT(drvData != NULL);
	FS_ASSERT(intGroup < pf502xIntGroupSysInt); /* SYS_INT register is cleared automatically. */

	/* Clear flags in interrupt register. */
	return PF502X_WriteRegister(drvData, (uint8_t)intGroup, intMask);
}

/* Sets which interrupts pull the INTB pin. */
pf502x_status_t PF502X_MaskInterrupts(const pf502x_drv_data_t *drvData,
		pf502x_int_group_t intGroup, uint8_t intMask) {
	FS_ASSERT(drvData != NULL);
	FS_ASSERT(intGroup < pf502xIntGroupSysInt); /* SYS_INT register cannot be masked. */

	/* Write to interrupt MASK register. */
	return PF502X_WriteRegister(drvData, (uint8_t)intGroup + 1U, intMask);
}

/* Reads the actual status of the signal triggering interrupt. */
pf502x_status_t PF502X_SenseInterrupts(const pf502x_drv_data_t *drvData,
		pf502x_int_group_t intGroup, uint8_t *intSense) {
	FS_ASSERT(drvData != NULL);
	FS_ASSERT(intSense != NULL);
	/* There is no SENSE register for SW_MODE and SYS_INT. */
	FS_ASSERT(
			(intGroup < pf502xIntGroupSysInt) && (intGroup != pf502xIntGroupSwMode));

	/* Read interrupt SENSE register. */
	return PF502X_ReadRegister(drvData, (uint8_t)intGroup + 2U, intSense);
}

/* Reads hardfault status. */
pf502x_status_t PF502X_GetHardfaultFlags(const pf502x_drv_data_t *drvData,
		uint8_t *hfFlags) {
	FS_ASSERT(drvData != NULL);
	FS_ASSERT(hfFlags != NULL);

	/* Read HARDFAULT_FLAGS register. */
	return PF502X_ReadRegister(drvData, PF502X_HARDFAULT_FLAGS_ADDR, hfFlags);
}

/* Clears hardfault status flags. */
pf502x_status_t PF502X_ClearHardfaultFlags(const pf502x_drv_data_t *drvData,
		uint8_t flagsMask) {
	FS_ASSERT(drvData != NULL);

	/* Clear hardfault flags. */
	return PF502X_WriteRegister(drvData, PF502X_HARDFAULT_FLAGS_ADDR, flagsMask);
}

/* Sets watchdog configuration. */
pf502x_status_t PF502X_SetWatchdogConfig(const pf502x_drv_data_t *drvData,
		bool wdEnable,
		bool wdStbyEnable, uint8_t wdDuration, uint8_t wdMaxExpire,
		uint8_t wdMaxCnt) {
	pf502x_status_t status;
	uint8_t rxData = 0;

	FS_ASSERT(drvData != NULL);

	/* Read CTRL1 register. */
	status = PF502X_ReadRegister(drvData, PF502X_CTRL1_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Clear bits before changing them. */
	rxData &= ~(PF502X_F_WD_EN_MASK | PF502X_F_WD_STBY_EN_MASK);
	/* Modify register content. */
	rxData |= ((uint8_t) wdEnable << PF502X_F_WD_EN_SHIFT)
			| ((uint8_t) wdStbyEnable << PF502X_F_WD_STBY_EN_SHIFT);

	/* Write settings to CTRL1 register. */
	if (drvData->secureEnabled) {
		status = PF502X_WriteRegisterSecured(drvData, PF502X_CTRL1_ADDR,
				rxData);
	} else {
		status = PF502X_WriteRegister(drvData, PF502X_CTRL1_ADDR, rxData);
	}
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Write settings to WD_CONFIG register. */
	status = PF502X_WriteRegister(drvData, PF502X_WD_CONFIG_ADDR, wdDuration);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Read WD_EXPIRE register. */
	status = PF502X_ReadRegister(drvData, PF502X_WD_EXPIRE_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Clear bits before changing them. */
	rxData &= ~(PF502X_F_WD_MAX_EXPIRE_MASK);
	/* Modify register content. */
	rxData |= wdMaxExpire;

	/* Write settings to WD_EXPIRE register. */
	status = PF502X_WriteRegister(drvData, PF502X_WD_EXPIRE_ADDR, rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Read WD_COUNTER register. */
	status = PF502X_ReadRegister(drvData, PF502X_WD_COUNTER_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Clear bits before changing them. */
	rxData &= ~(PF502X_F_WD_MAX_CNT_MASK);
	/* Modify register content. */
	rxData |= wdMaxCnt;

	/* Write settings to WD_COUNTER register. */
	return PF502X_WriteRegister(drvData, PF502X_WD_COUNTER_ADDR, rxData);
}

/* Reads watchdog status. */
pf502x_status_t PF502X_GetWatchdogStatus(const pf502x_drv_data_t *drvData,
		uint8_t *wdExpireCnt, uint8_t *wdEventCnt) {
	pf502x_status_t status;
	uint8_t rxData = 0;

	FS_ASSERT(drvData != NULL);
	FS_ASSERT(wdExpireCnt != NULL);
	FS_ASSERT(wdEventCnt != NULL);

	/* Read WD_EXPIRE register. */
	status = PF502X_ReadRegister(drvData, PF502X_WD_EXPIRE_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	*wdExpireCnt = (rxData & PF502X_F_WD_EXPIRE_CNT_MASK)
			>> PF502X_F_WD_EXPIRE_CNT_SHIFT;

	/* Read WD_COUNTER register. */
	status = PF502X_ReadRegister(drvData, PF502X_WD_COUNTER_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	*wdEventCnt = (rxData & PF502X_F_WD_EVENT_CNT_MASK)
			>> PF502X_F_WD_EVENT_CNT_SHIFT;

	return status;
}

/* Clears watchdog. */
pf502x_status_t PF502X_ClearWatchdog(const pf502x_drv_data_t *drvData) {
	pf502x_status_t status;

	FS_ASSERT(drvData != NULL);

	/* Write to WD_CLEAR register. */
	if (drvData->secureEnabled) {
		status = PF502X_WriteRegisterSecured(drvData, PF502X_WD_CLEAR_ADDR,
				PF502X_F_WD_CLEAR_1);
	} else {
		status = PF502X_WriteRegister(drvData, PF502X_WD_CLEAR_ADDR,
				PF502X_F_WD_CLEAR_1);
	}

	return status;
}

/* Sets fault configuration. */
pf502x_status_t PF502X_SetFaultConfig(const pf502x_drv_data_t *drvData,
		uint8_t faultMaxCnt, uint8_t faultTimer) {
	pf502x_status_t status;
	uint8_t rxData = 0;

	FS_ASSERT(drvData != NULL);

	/* Read FAULT_COUNTER register. */
	status = PF502X_ReadRegister(drvData, PF502X_FAULT_COUNTER_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Clear bits before changing them. */
	rxData &= ~(PF502X_F_FAULT_MAX_CNT_MASK);
	/* Modify register content. */
	rxData |= faultMaxCnt;

	/* Write settings to FAULT_COUNTER register. */
	status = PF502X_WriteRegister(drvData, PF502X_FAULT_COUNTER_ADDR, rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Write settings to FAULT_TIMERS register. */
	return PF502X_WriteRegister(drvData, PF502X_FAULT_TIMERS_ADDR, faultTimer);
}

/* Reads fault counter value. */
pf502x_status_t PF502X_GetFaultCounter(const pf502x_drv_data_t *drvData,
		uint8_t *faultCnt) {
	pf502x_status_t status;
	uint8_t rxData = 0;

	FS_ASSERT(drvData != NULL);
	FS_ASSERT(faultCnt != NULL);

	/* Read FAULT_COUNTER register. */
	status = PF502X_ReadRegister(drvData, PF502X_FAULT_COUNTER_ADDR, &rxData);

	*faultCnt = (rxData & PF502X_F_FAULT_CNT_MASK) >> PF502X_F_FAULT_CNT_SHIFT;

	return status;
}

/* Runs ABIST on demand. */
pf502x_status_t PF502X_RunAbist(const pf502x_drv_data_t *drvData) {
	FS_ASSERT(drvData != NULL);

	/* Write to ABIST_RUN register. */
	if (drvData->secureEnabled) {
		return PF502X_WriteRegisterSecured(drvData, PF502X_ABIST_RUN_ADDR,
				PF502X_F_AB_RUN_1);
	} else {
		return PF502X_WriteRegister(drvData, PF502X_ABIST_RUN_ADDR,
				PF502X_F_AB_RUN_1);
	}
}

/* Reads ABIST OV and UV flags. */
pf502x_status_t PF502X_GetAbistFlags(const pf502x_drv_data_t *drvData,
		bool ovUvFlags, uint16_t *abistFlags) {
	pf502x_status_t status;
	uint8_t rxData = 0;

	FS_ASSERT(drvData != NULL);
	FS_ASSERT(abistFlags != NULL);

	/* Read ABIST_OV1/UV1 register (SW flags). */
	status = PF502X_ReadRegister(drvData,
			PF502X_ABIST_OV1_ADDR + (2 * (uint8_t) ovUvFlags), &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	*abistFlags = rxData;

#ifdef PF502X_LDO_FEATURE
	/* Read ABIST_OV2/UV2 register (LDO flags). */
	status = PF502X_ReadRegister(drvData,
			PF502X_ABIST_OV2_ADDR + (2 * (uint8_t) ovUvFlags), &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	*abistFlags |= (rxData & 0x0FU) << 8U;
#endif

	return status;
}

/* Clears ABIST status flags. */
pf502x_status_t PF502X_ClearAbistFlags(const pf502x_drv_data_t *drvData,
		bool ovUvFlags, uint16_t flagsMask) {
	pf502x_status_t status;

	FS_ASSERT(drvData != NULL);

	/* Clear ABIST_OV1/UV1 register (SW flags). */
	if (drvData->secureEnabled) {
		status = PF502X_WriteRegisterSecured(drvData,
				PF502X_ABIST_OV1_ADDR + (2 * (uint8_t) ovUvFlags),
				(uint8_t) (flagsMask & 0x00FFU));
	} else {
		status = PF502X_WriteRegister(drvData,
				PF502X_ABIST_OV1_ADDR + (2 * (uint8_t) ovUvFlags),
				(uint8_t) (flagsMask & 0x00FFU));
	}
	if (status != pf502xStatusOk) {
		return status;
	}

#ifdef PF502X_LDO_FEATURE
	/* Clear ABIST_OV2/UV2 register (LDO flags). */
	if (drvData->secureEnabled) {
		return PF502X_WriteRegisterSecured(drvData,
				PF502X_ABIST_OV2_ADDR + (2 * (uint8_t) ovUvFlags),
				(uint8_t) ((flagsMask & 0xFF00U) >> 8U));
	} else {
		return PF502X_WriteRegister(drvData,
				PF502X_ABIST_OV2_ADDR + (2 * (uint8_t) ovUvFlags),
				(uint8_t) ((flagsMask & 0xFF00U) >> 8U));
	}
#else
    return status;
#endif
}

/* Reads test flags. */
pf502x_status_t PF502X_GetTestFlags(const pf502x_drv_data_t *drvData,
		uint8_t *testFlags) {
	FS_ASSERT(drvData != NULL);
	FS_ASSERT(testFlags != NULL);

	/* Read TEST_FLAGS register. */
	return PF502X_ReadRegister(drvData, PF502X_TEST_FLAGS_ADDR, testFlags);
}

/* Clears test flags. */
pf502x_status_t PF502X_ClearTestFlags(const pf502x_drv_data_t *drvData,
		uint8_t flagsMask) {
	FS_ASSERT(drvData != NULL);

	/* Clear TEST_FLAGS register. */
	return PF502X_WriteRegister(drvData, PF502X_TEST_FLAGS_ADDR, flagsMask);
}

/* Sets analog multiplexer (AMUX). */
pf502x_status_t PF502X_SetAmux(const pf502x_drv_data_t *drvData,
		bool amuxEnable, uint8_t amuxSel) {
	FS_ASSERT(drvData != NULL);

	/* Write settings to AMUX register. */
	return PF502X_WriteRegister(drvData, PF502X_AMUX_ADDR,
			(((uint8_t) amuxEnable << PF502X_F_AMUX_EN_SHIFT) | amuxSel));
}

/* Turns PMIC off (after 500us shutdown timer expires). */
pf502x_status_t PF502X_TurnOff(const pf502x_drv_data_t *drvData) {
	pf502x_status_t status;
	uint8_t rxData = 0;

	FS_ASSERT(drvData != NULL);

	/* Read CTRL3 register. */
	status = PF502X_ReadRegister(drvData, PF502X_CTRL3_ADDR, &rxData);
	if (status != pf502xStatusOk) {
		return status;
	}

	/* Set PMIC_OFF bit. */
	rxData |= PF502X_F_PMIC_OFF_1;

	/* Write to CTRL3 register. */
	return PF502X_WriteRegister(drvData, PF502X_CTRL3_ADDR, rxData);
}

/*Turn off PMIC PF5024 */
pf502x_status_t PF5024_TurnOff(const pf502x_drv_data_t *drvData)
{
	pf502x_status_t status;

	status = PF502X_TurnOff(drvData);
	if (status != pf502xStatusOk)
	{
		return status;
	}
}