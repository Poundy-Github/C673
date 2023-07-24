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
 * @file pmic_pf502x_common.h
 * @brief Driver common structures, enums, macros and configuration values.
 *
 * @author nxa22158, nxa23158
 * @version 1.0
 * @date 18-December-2020
 * @copyright Copyright (c) 2021 NXP
 */

#ifndef PMIC_PF502X_COMMON_H_
#define PMIC_PF502X_COMMON_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdint.h>
#include <stdbool.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define PF502X_DEVICE_PF5020 0U
#define PF502X_DEVICE_PF5023 1U
#define PF502X_DEVICE_PF5024 2U

/* Select device used in your application. */
#define PF502X_DEVICE PF502X_DEVICE_PF5024

#if PF502X_DEVICE == PF502X_DEVICE_PF5020
#define PF502X_LDO_FEATURE
#define PF502x_VSNVS_FEATURE
#endif

/** @defgroup EnumsDefs Enums definition
 * @{ */
/** @brief Status return codes. */
typedef enum
{
    pf502xStatusOk    = 0U,   /**< No error. */
    pf502xStatusError = 1U    /**< Error. */
} pf502x_status_t;
/** @} */

/** @brief This data structure is used by the PF502X driver (this is the first
* parameter of most the PF502X functions). It contains a configuration of the
* PF502X device. */
typedef struct
{
    /** @brief PMIC I2C address.
     *
     * This is not the full I2C address but just a value of the OTP register
     * OTP_I2C - OTP_I2C_ADD[2:0]. */
    uint8_t i2cAddressOtp;

    /** @brief Secure write enabled for I2C transfer. */
    bool secureEnabled;

    /** @brief CRC enabled for I2C transfer. */
    bool crcEnabled;
} pf502x_drv_data_t;
/** @} */

/** @name Bitwise operations used by this driver. */
/** @{ */
/** @brief This macro updates value of bits specified by the mask. It is assumed that
 *  value is already shifted. */
#define PF502X_BO_SETVAL(data, val, mask)   (((data) & ~(mask)) | (val))

/** @brief This macro updates value of bits specified by the mask. Additionally range
 *  check on the value is performed. It is assumed that value is not shifted. */
#define PF502X_BO_SETVAL_EXT(data, value, mask, shift) \
    (((data) & ~(mask << shift)) | (((value) & (mask)) << (shift)))

/** @brief This macro returns value specified by the mask. */
#define PF502X_BO_GETVAL(data, mask, shift) ((data) & (mask) << (shift))

/** @brief Macro for getting value from register.
 *
 * @param value Value read from register.
 * @param mask Bit selection.
 * @param shift Bit shift.
 * @returns Masked and r-shifted value. */
#define PF502X_BO_GET_REG_VALUE(value, mask, shift) (((value) & (mask)) >> (shift))
/** @} */

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/

#endif /* PMIC_PF502X_COMMON_H_ */
