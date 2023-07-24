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

/*!
 * @file pmic_pf5024_map.h
 * @brief PF5024 register map.
 *
 * This header file contains addresses, masks, shifts and shifted discreet values
 * for runtime registers of the PF5024.
 * See datasheet for details.
 *
 * @author nxa23158
 * @version 1.0
 * @date 18-December-2020
 * @copyright Copyright (c) 2021 NXP
 */

#ifndef PMIC_PF5024_MAP_H__
#define PMIC_PF5024_MAP_H__

/******************************************************************************/
/* DEVICE_ID - Type: R                                                        */
/******************************************************************************/

#define PF502X_DEVICE_ID_ADDR            0x00U
#define PF502X_DEVICE_ID_DEFAULT         0x50U

/**
 * Device ID
 */
#define PF502X_F_DEVICE_ID_MASK          0x0FU
/**
 * Device Family
 */
#define PF502X_F_DEVICE_FAM_MASK         0xF0U

/**
 * Device ID
 */
#define PF502X_F_DEVICE_ID_SHIFT         0x00U
/**
 * Device Family
 */
#define PF502X_F_DEVICE_FAM_SHIFT        0x04U

/**
 * PF5024 QM
 */
#define PF502X_F_DEVICE_ID_PF5024_QM     (0x00U << PF502X_F_DEVICE_ID_SHIFT)
/**
 * PF5024 ASILB
 */
#define PF502X_F_DEVICE_ID_PF5024_ASILB  (0x08U << PF502X_F_DEVICE_ID_SHIFT)

/**
 * PF502x Family
 */
#define PF502X_F_DEVICE_FAM_PF502X_FAMILY (0x05U << PF502X_F_DEVICE_FAM_SHIFT)

/******************************************************************************/
/* REV_ID - Type: R                                                           */
/******************************************************************************/

#define PF502X_REV_ID_ADDR               0x01U
#define PF502X_REV_ID_DEFAULT            0x00U

/**
 * Reserved for Internal use
 */
#define PF502X_F_METAL_LAYER_REV_MASK    0x0FU
/**
 * Reserved for Internal use
 */
#define PF502X_F_FULL_LAYER_REV_MASK     0xF0U

/**
 * Reserved for Internal use
 */
#define PF502X_F_METAL_LAYER_REV_SHIFT   0x00U
/**
 * Reserved for Internal use
 */
#define PF502X_F_FULL_LAYER_REV_SHIFT    0x04U

/******************************************************************************/
/* EMREV - Type: R                                                            */
/******************************************************************************/

#define PF502X_EMREV_ADDR                0x02U
#define PF502X_EMREV_DEFAULT             0x00U

/**
 * Reserved for Internal use
 */
#define PF502X_F_EMREV_MASK              0x07U
/**
 * OTP ID
 */
#define PF502X_F_PROG_IDH_MASK           0xF0U

/**
 * Reserved for Internal use
 */
#define PF502X_F_EMREV_SHIFT             0x00U
/**
 * OTP ID
 */
#define PF502X_F_PROG_IDH_SHIFT          0x04U

/******************************************************************************/
/* PROG_ID - Type: R                                                          */
/******************************************************************************/

#define PF502X_PROG_ID_ADDR              0x03U
#define PF502X_PROG_ID_DEFAULT           0x00U

/**
 * OTP ID
 */
#define PF502X_F_PROG_IDL_MASK           0xFFU

/**
 * OTP ID
 */
#define PF502X_F_PROG_IDL_SHIFT          0x00U

/******************************************************************************/
/* INT_STATUS1 - Type: RW                                                     */
/******************************************************************************/

#define PF502X_INT_STATUS1_ADDR          0x04U
#define PF502X_INT_STATUS1_DEFAULT       0x00U

/**
 * If bit is cleared when the VIN_OVLO condition is still pressent, the interrupt bit will set again.
 */
#define PF502X_F_VIN_OVLO_I_MASK         0x01U
/**
 * If bit is cleared when the VIN_OVLO condition is still pressent, the interrupt bit will set again.
 */
#define PF502X_F_PGOOD_I_MASK            0x02U
/**
 * (Run to Standby mode)
 */
#define PF502X_F_PWRDN_I_MASK            0x08U
/**
 * (Off to Run mode, Standby to Run mode or WD_Reset to Run Mode)
 */
#define PF502X_F_PWRUP_I_MASK            0x10U
/**
 * Bit is latched when a bad CRC is detected during an I2C transaction
 */
#define PF502X_F_CRC_I_MASK              0x20U
/**
 * bit is latched when the device has reached the new frequency programed in manual clock tuning
 */
#define PF502X_F_FREQ_RDY_I_MASK         0x40U
/**
 * Clearing this flag shall stop the shutdown request.
 */
#define PF502X_F_SDWN_I_MASK             0x80U

/**
 * If bit is cleared when the VIN_OVLO condition is still pressent, the interrupt bit will set again.
 */
#define PF502X_F_VIN_OVLO_I_SHIFT        0x00U
/**
 * If bit is cleared when the VIN_OVLO condition is still pressent, the interrupt bit will set again.
 */
#define PF502X_F_PGOOD_I_SHIFT           0x01U
/**
 * (Run to Standby mode)
 */
#define PF502X_F_PWRDN_I_SHIFT           0x03U
/**
 * (Off to Run mode, Standby to Run mode or WD_Reset to Run Mode)
 */
#define PF502X_F_PWRUP_I_SHIFT           0x04U
/**
 * Bit is latched when a bad CRC is detected during an I2C transaction
 */
#define PF502X_F_CRC_I_SHIFT             0x05U
/**
 * bit is latched when the device has reached the new frequency programed in manual clock tuning
 */
#define PF502X_F_FREQ_RDY_I_SHIFT        0x06U
/**
 * Clearing this flag shall stop the shutdown request.
 */
#define PF502X_F_SDWN_I_SHIFT            0x07U

/**
 * Interrupt Cleared
 */
#define PF502X_F_VIN_OVLO_I_CLEARED      (0x00U << PF502X_F_VIN_OVLO_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_VIN_OVLO_I_SET          (0x01U << PF502X_F_VIN_OVLO_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_PGOOD_I_CLEARED         (0x00U << PF502X_F_PGOOD_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PGOOD_I_SET             (0x01U << PF502X_F_PGOOD_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_PWRDN_I_CLEARED         (0x00U << PF502X_F_PWRDN_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PWRDN_I_SET             (0x01U << PF502X_F_PWRDN_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_PWRUP_I_CLEARED         (0x00U << PF502X_F_PWRUP_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PWRUP_I_SET             (0x01U << PF502X_F_PWRUP_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_CRC_I_CLEARED           (0x00U << PF502X_F_CRC_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_CRC_I_SET               (0x01U << PF502X_F_CRC_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_FREQ_RDY_I_CLEARED      (0x00U << PF502X_F_FREQ_RDY_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_FREQ_RDY_I_SET          (0x01U << PF502X_F_FREQ_RDY_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SDWN_I_CLEARED          (0x00U << PF502X_F_SDWN_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SDWN_I_SET              (0x01U << PF502X_F_SDWN_I_SHIFT)

/******************************************************************************/
/* INT_MASK1 - Type: RW                                                       */
/******************************************************************************/

#define PF502X_INT_MASK1_ADDR            0x05U
#define PF502X_INT_MASK1_DEFAULT         0xFBU

/**
 * Mask the VIN_OVLO_I interrupt
 */
#define PF502X_F_VIN_OVLO_M_MASK         0x01U
/**
 * Mask the PGOOD_I interrupt
 */
#define PF502X_F_PGOOD_M_MASK            0x02U
/**
 * Mask the PWRDN_I interrupt
 */
#define PF502X_F_PWRDN_M_MASK            0x08U
/**
 * Mask the PWRUP_I interrupt
 */
#define PF502X_F_PWRUP_M_MASK            0x10U
/**
 * Mask the CRC_I interrupt
 */
#define PF502X_F_CRC_M_MASK              0x20U
/**
 * Mask the FREQ_RDY_I interrupt
 */
#define PF502X_F_FREQ_RDY_M_MASK         0x40U
/**
 * Mask the SDWN_I interrupt
 */
#define PF502X_F_SDWN_M_MASK             0x80U

/**
 * Mask the VIN_OVLO_I interrupt
 */
#define PF502X_F_VIN_OVLO_M_SHIFT        0x00U
/**
 * Mask the PGOOD_I interrupt
 */
#define PF502X_F_PGOOD_M_SHIFT           0x01U
/**
 * Mask the PWRDN_I interrupt
 */
#define PF502X_F_PWRDN_M_SHIFT           0x03U
/**
 * Mask the PWRUP_I interrupt
 */
#define PF502X_F_PWRUP_M_SHIFT           0x04U
/**
 * Mask the CRC_I interrupt
 */
#define PF502X_F_CRC_M_SHIFT             0x05U
/**
 * Mask the FREQ_RDY_I interrupt
 */
#define PF502X_F_FREQ_RDY_M_SHIFT        0x06U
/**
 * Mask the SDWN_I interrupt
 */
#define PF502X_F_SDWN_M_SHIFT            0x07U

/**
 * Interrupt Unmasked
 */
#define PF502X_F_VIN_OVLO_M_UNMASKED     (0x00U << PF502X_F_VIN_OVLO_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_VIN_OVLO_M_MASKED       (0x01U << PF502X_F_VIN_OVLO_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_PGOOD_M_UNMASKED        (0x00U << PF502X_F_PGOOD_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_PGOOD_M_MASKED          (0x01U << PF502X_F_PGOOD_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_PWRDN_M_UNMASKED        (0x00U << PF502X_F_PWRDN_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_PWRDN_M_MASKED          (0x01U << PF502X_F_PWRDN_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_PWRUP_M_UNMASKED        (0x00U << PF502X_F_PWRUP_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_PWRUP_M_MASKED          (0x01U << PF502X_F_PWRUP_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_CRC_M_UNMASKED          (0x00U << PF502X_F_CRC_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_CRC_M_MASKED            (0x01U << PF502X_F_CRC_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_FREQ_RDY_M_UNMASKED     (0x00U << PF502X_F_FREQ_RDY_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_FREQ_RDY_M_MASKED       (0x01U << PF502X_F_FREQ_RDY_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SDWN_M_UNMASKED         (0x00U << PF502X_F_SDWN_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SDWN_M_MASKED           (0x01U << PF502X_F_SDWN_M_SHIFT)

/******************************************************************************/
/* INT_SENSE1 - Type: R                                                       */
/******************************************************************************/

#define PF502X_INT_SENSE1_ADDR           0x06U
#define PF502X_INT_SENSE1_DEFAULT        0x00U

/**
 * Sense pin is 1 as long as the VIN_OVLO condition is still present
 */
#define PF502X_F_VIN_OVLO_S_MASK         0x01U
#define PF502X_F_PGOOD_S_MASK            0x02U

/**
 * Sense pin is 1 as long as the VIN_OVLO condition is still present
 */
#define PF502X_F_VIN_OVLO_S_SHIFT        0x00U
#define PF502X_F_PGOOD_S_SHIFT           0x01U

/**
 * VIN OVLO Ok
 */
#define PF502X_F_VIN_OVLO_S_VIN_OVLO_OK  (0x00U << PF502X_F_VIN_OVLO_S_SHIFT)
/**
 * VIN OVLO Event
 */
#define PF502X_F_VIN_OVLO_S_VIN_OVLO_EVENT (0x01U << PF502X_F_VIN_OVLO_S_SHIFT)

/**
 * PGOOD pin is low
 */
#define PF502X_F_PGOOD_S_LOW             (0x00U << PF502X_F_PGOOD_S_SHIFT)
/**
 * PGOOD pin is high
 */
#define PF502X_F_PGOOD_S_HIGH            (0x01U << PF502X_F_PGOOD_S_SHIFT)

/******************************************************************************/
/* INT_STATUS2 - Type: RW                                                     */
/******************************************************************************/

#define PF502X_INT_STATUS2_ADDR          0x07U
#define PF502X_INT_STATUS2_DEFAULT       0x00U

/**
 * Bit is latched when Central Temp Sensor crosses the 80_ Threshold rising
 */
#define PF502X_F_THERM_80_I_MASK         0x01U
/**
 * Bit is latched when Central Temp Sensor crosses the 95_ Threshold rising
 */
#define PF502X_F_THERM_95_I_MASK         0x02U
/**
 * Bit is latched when Central Temp Sensor crosses the 110_ Threshold rising
 */
#define PF502X_F_THERM_110_I_MASK        0x04U
/**
 * Bit is latched when Central Temp Sensor crosses the 125_ Threshold rising
 */
#define PF502X_F_THERM_125_I_MASK        0x08U
/**
 * Bit is latched when Central Temp Sensor crosses the 140_ Threshold rising
 */
#define PF502X_F_THERM_140_I_MASK        0x10U
/**
 * Bit is latched when Central Temp Sensor crosses the 155_ Threshold rising
 */
#define PF502X_F_THERM_155_I_MASK        0x20U
/**
 * Bit is latched when  the internal Frequency Watchdog detects an input frequency out of range or missing on the 
 * SYNCIN pin. If the faulty clock condition persist and the FSYN _FLT_I bit is cleared, the bit will be re-set back.
 */
#define PF502X_F_FSYNC_FLT_I_MASK        0x40U
/**
 * Bit is latched when  the soft WD reset is finished after a WDI event.
 */
#define PF502X_F_WDI_I_MASK              0x80U

/**
 * Bit is latched when Central Temp Sensor crosses the 80_ Threshold rising
 */
#define PF502X_F_THERM_80_I_SHIFT        0x00U
/**
 * Bit is latched when Central Temp Sensor crosses the 95_ Threshold rising
 */
#define PF502X_F_THERM_95_I_SHIFT        0x01U
/**
 * Bit is latched when Central Temp Sensor crosses the 110_ Threshold rising
 */
#define PF502X_F_THERM_110_I_SHIFT       0x02U
/**
 * Bit is latched when Central Temp Sensor crosses the 125_ Threshold rising
 */
#define PF502X_F_THERM_125_I_SHIFT       0x03U
/**
 * Bit is latched when Central Temp Sensor crosses the 140_ Threshold rising
 */
#define PF502X_F_THERM_140_I_SHIFT       0x04U
/**
 * Bit is latched when Central Temp Sensor crosses the 155_ Threshold rising
 */
#define PF502X_F_THERM_155_I_SHIFT       0x05U
/**
 * Bit is latched when  the internal Frequency Watchdog detects an input frequency out of range or missing on the 
 * SYNCIN pin. If the faulty clock condition persist and the FSYN _FLT_I bit is cleared, the bit will be re-set back.
 */
#define PF502X_F_FSYNC_FLT_I_SHIFT       0x06U
/**
 * Bit is latched when  the soft WD reset is finished after a WDI event.
 */
#define PF502X_F_WDI_I_SHIFT             0x07U

/**
 * Interrupt Cleared
 */
#define PF502X_F_THERM_80_I_CLEARED      (0x00U << PF502X_F_THERM_80_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_THERM_80_I_SET          (0x01U << PF502X_F_THERM_80_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_THERM_95_I_CLEARED      (0x00U << PF502X_F_THERM_95_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_THERM_95_I_SET          (0x01U << PF502X_F_THERM_95_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_THERM_110_I_CLEARED     (0x00U << PF502X_F_THERM_110_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_THERM_110_I_SET         (0x01U << PF502X_F_THERM_110_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_THERM_125_I_CLEARED     (0x00U << PF502X_F_THERM_125_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_THERM_125_I_SET         (0x01U << PF502X_F_THERM_125_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_THERM_140_I_CLEARED     (0x00U << PF502X_F_THERM_140_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_THERM_140_I_SET         (0x01U << PF502X_F_THERM_140_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_THERM_155_I_CLEARED     (0x00U << PF502X_F_THERM_155_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_THERM_155_I_SET         (0x01U << PF502X_F_THERM_155_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_FSYNC_FLT_I_CLEARED     (0x00U << PF502X_F_FSYNC_FLT_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_FSYNC_FLT_I_SET         (0x01U << PF502X_F_FSYNC_FLT_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_WDI_I_CLEARED           (0x00U << PF502X_F_WDI_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_WDI_I_SET               (0x01U << PF502X_F_WDI_I_SHIFT)

/******************************************************************************/
/* INT_MASK2 - Type: RW                                                       */
/******************************************************************************/

#define PF502X_INT_MASK2_ADDR            0x08U
#define PF502X_INT_MASK2_DEFAULT         0xFFU

/**
 * Mask the THERM_80_I interrupt
 */
#define PF502X_F_THERM_80_M_MASK         0x01U
/**
 * Mask the THERM_95_I interrupt
 */
#define PF502X_F_THERM_95_M_MASK         0x02U
/**
 * Mask the THERM_110_I interrupt
 */
#define PF502X_F_THERM_110_M_MASK        0x04U
/**
 * Mask the THERM_125_I interrupt
 */
#define PF502X_F_THERM_125_M_MASK        0x08U
/**
 * Mask the THERM_140_I interrupt
 */
#define PF502X_F_THERM_140_M_MASK        0x10U
/**
 * Mask the THERM_155_I interrupt
 */
#define PF502X_F_THERM_155_M_MASK        0x20U
/**
 * Mask the FSYNC_FLT_I interrupt
 */
#define PF502X_F_FSYNC_FLT_M_MASK        0x40U
/**
 * Mask the WDI_I interrupt
 */
#define PF502X_F_WDI_M_MASK              0x80U

/**
 * Mask the THERM_80_I interrupt
 */
#define PF502X_F_THERM_80_M_SHIFT        0x00U
/**
 * Mask the THERM_95_I interrupt
 */
#define PF502X_F_THERM_95_M_SHIFT        0x01U
/**
 * Mask the THERM_110_I interrupt
 */
#define PF502X_F_THERM_110_M_SHIFT       0x02U
/**
 * Mask the THERM_125_I interrupt
 */
#define PF502X_F_THERM_125_M_SHIFT       0x03U
/**
 * Mask the THERM_140_I interrupt
 */
#define PF502X_F_THERM_140_M_SHIFT       0x04U
/**
 * Mask the THERM_155_I interrupt
 */
#define PF502X_F_THERM_155_M_SHIFT       0x05U
/**
 * Mask the FSYNC_FLT_I interrupt
 */
#define PF502X_F_FSYNC_FLT_M_SHIFT       0x06U
/**
 * Mask the WDI_I interrupt
 */
#define PF502X_F_WDI_M_SHIFT             0x07U

/**
 * Interrupt Unmasked
 */
#define PF502X_F_THERM_80_M_UNMASKED     (0x00U << PF502X_F_THERM_80_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_THERM_80_M_MASKED       (0x01U << PF502X_F_THERM_80_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_THERM_95_M_UNMASKED     (0x00U << PF502X_F_THERM_95_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_THERM_95_M_MASKED       (0x01U << PF502X_F_THERM_95_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_THERM_110_M_UNMASKED    (0x00U << PF502X_F_THERM_110_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_THERM_110_M_MASKED      (0x01U << PF502X_F_THERM_110_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_THERM_125_M_UNMASKED    (0x00U << PF502X_F_THERM_125_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_THERM_125_M_MASKED      (0x01U << PF502X_F_THERM_125_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_THERM_140_M_UNMASKED    (0x00U << PF502X_F_THERM_140_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_THERM_140_M_MASKED      (0x01U << PF502X_F_THERM_140_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_THERM_155_M_UNMASKED    (0x00U << PF502X_F_THERM_155_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_THERM_155_M_MASKED      (0x01U << PF502X_F_THERM_155_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_FSYNC_FLT_M_UNMASKED    (0x00U << PF502X_F_FSYNC_FLT_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_FSYNC_FLT_M_MASKED      (0x01U << PF502X_F_FSYNC_FLT_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_WDI_M_UNMASKED          (0x00U << PF502X_F_WDI_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_WDI_M_MASKED            (0x01U << PF502X_F_WDI_M_SHIFT)

/******************************************************************************/
/* INT_SENSE2 - Type: R                                                       */
/******************************************************************************/

#define PF502X_INT_SENSE2_ADDR           0x09U
#define PF502X_INT_SENSE2_DEFAULT        0x00U

/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_80_S_MASK         0x01U
/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_95_S_MASK         0x02U
/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_110_S_MASK        0x04U
/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_125_S_MASK        0x08U
/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_140_S_MASK        0x10U
/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_155_S_MASK        0x20U
/**
 * Sense pin is 1 as long as the internal watchdog is detecting a frequency out of range.
 */
#define PF502X_F_FSYNC_FLT_S_MASK        0x40U
/**
 * Sense pin is 1 as long as the WDI pin is high.
 */
#define PF502X_F_WDI_S_MASK              0x80U

/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_80_S_SHIFT        0x00U
/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_95_S_SHIFT        0x01U
/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_110_S_SHIFT       0x02U
/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_125_S_SHIFT       0x03U
/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_140_S_SHIFT       0x04U
/**
 * Sesne bit is released if the temperature is 5 degrees below the nominal threshold.
 */
#define PF502X_F_THERM_155_S_SHIFT       0x05U
/**
 * Sense pin is 1 as long as the internal watchdog is detecting a frequency out of range.
 */
#define PF502X_F_FSYNC_FLT_S_SHIFT       0x06U
/**
 * Sense pin is 1 as long as the WDI pin is high.
 */
#define PF502X_F_WDI_S_SHIFT             0x07U

/**
 * 80 _C threshold not reached
 */
#define PF502X_F_THERM_80_S_80_C_THRESHOLD_NOT_REACHED (0x00U << PF502X_F_THERM_80_S_SHIFT)
/**
 * 80 _C threshold reached
 */
#define PF502X_F_THERM_80_S_80_C_THRESHOLD_REACHED (0x01U << PF502X_F_THERM_80_S_SHIFT)

/**
 * 80 _C threshold not reached
 */
#define PF502X_F_THERM_95_S_95_C_THRESHOLD_NOT_REACHED (0x00U << PF502X_F_THERM_95_S_SHIFT)
/**
 * 80 _C threshold reached
 */
#define PF502X_F_THERM_95_S_95_C_THRESHOLD_REACHED (0x01U << PF502X_F_THERM_95_S_SHIFT)

/**
 * 80 _C threshold not reached
 */
#define PF502X_F_THERM_110_S_110_C_THRESHOLD_NOT_REACHED (0x00U << PF502X_F_THERM_110_S_SHIFT)
/**
 * 80 _C threshold reached
 */
#define PF502X_F_THERM_110_S_110_C_THRESHOLD_REACHED (0x01U << PF502X_F_THERM_110_S_SHIFT)

/**
 * 80 _C threshold not reached
 */
#define PF502X_F_THERM_125_S_125_C_THRESHOLD_NOT_REACHED (0x00U << PF502X_F_THERM_125_S_SHIFT)
/**
 * 80 _C threshold reached
 */
#define PF502X_F_THERM_125_S_125_C_THRESHOLD_REACHED (0x01U << PF502X_F_THERM_125_S_SHIFT)

/**
 * 80 _C threshold not reached
 */
#define PF502X_F_THERM_140_S_140_C_THRESHOLD_NOT_REACHED (0x00U << PF502X_F_THERM_140_S_SHIFT)
/**
 * 80 _C threshold reached
 */
#define PF502X_F_THERM_140_S_140_C_THRESHOLD_REACHED (0x01U << PF502X_F_THERM_140_S_SHIFT)

/**
 * 80 _C threshold not reached
 */
#define PF502X_F_THERM_155_S_155_C_THRESHOLD_NOT_REACHED (0x00U << PF502X_F_THERM_155_S_SHIFT)
/**
 * 80 _C threshold reached
 */
#define PF502X_F_THERM_155_S_155_C_THRESHOLD_REACHED (0x01U << PF502X_F_THERM_155_S_SHIFT)

/**
 * Frequency out of range
 */
#define PF502X_F_FSYNC_FLT_S_FREQUENCY_OUT_OF_RANGE (0x00U << PF502X_F_FSYNC_FLT_S_SHIFT)
/**
 * Frequency OK
 */
#define PF502X_F_FSYNC_FLT_S_FREQUENCY_OK (0x01U << PF502X_F_FSYNC_FLT_S_SHIFT)

/**
 * WD pin Low
 */
#define PF502X_F_WDI_S_LOW               (0x00U << PF502X_F_WDI_S_SHIFT)
/**
 * WD pin High
 */
#define PF502X_F_WDI_S_HIGH              (0x01U << PF502X_F_WDI_S_SHIFT)

/******************************************************************************/
/* SW_MODE_INT - Type: RW                                                     */
/******************************************************************************/

#define PF502X_SW_MODE_INT_ADDR          0x0AU
#define PF502X_SW_MODE_INT_DEFAULT       0x00U

/**
 * (PWM, PFM,  Auto Skip)
 */
#define PF502X_F_SW1_MODE_I_MASK         0x01U
/**
 * (PWM, PFM,  Auto Skip)
 */
#define PF502X_F_SW2_MODE_I_MASK         0x02U
/**
 * (PWM, PFM,  Auto Skip)
 */
#define PF502X_F_SW3_MODE_I_MASK         0x04U
/**
 * (PWM, PFM,  Auto Skip)
 */
#define PF502X_F_SW4_MODE_I_MASK         0x08U

/**
 * (PWM, PFM,  Auto Skip)
 */
#define PF502X_F_SW1_MODE_I_SHIFT        0x00U
/**
 * (PWM, PFM,  Auto Skip)
 */
#define PF502X_F_SW2_MODE_I_SHIFT        0x01U
/**
 * (PWM, PFM,  Auto Skip)
 */
#define PF502X_F_SW3_MODE_I_SHIFT        0x02U
/**
 * (PWM, PFM,  Auto Skip)
 */
#define PF502X_F_SW4_MODE_I_SHIFT        0x03U

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW1_MODE_I_CLEARED      (0x00U << PF502X_F_SW1_MODE_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW1_MODE_I_SET          (0x01U << PF502X_F_SW1_MODE_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW2_MODE_I_CLEARED      (0x00U << PF502X_F_SW2_MODE_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW2_MODE_I_SET          (0x01U << PF502X_F_SW2_MODE_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW3_MODE_I_CLEARED      (0x00U << PF502X_F_SW3_MODE_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW3_MODE_I_SET          (0x01U << PF502X_F_SW3_MODE_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW4_MODE_I_CLEARED      (0x00U << PF502X_F_SW4_MODE_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW4_MODE_I_SET          (0x01U << PF502X_F_SW4_MODE_I_SHIFT)

/******************************************************************************/
/* SW_MODE_MASK - Type: RW                                                    */
/******************************************************************************/

#define PF502X_SW_MODE_MASK_ADDR         0x0BU
#define PF502X_SW_MODE_MASK_DEFAULT      0x0FU

/**
 * Mask the SW1_MODE_I interrupt
 */
#define PF502X_F_SW1_MODE_M_MASK         0x01U
/**
 * Mask the SW2_MODE_I interrupt
 */
#define PF502X_F_SW2_MODE_M_MASK         0x02U
/**
 * Mask the SW3_MODE_I interrupt
 */
#define PF502X_F_SW3_MODE_M_MASK         0x04U
/**
 * Mask the SW4_MODE_I interrupt
 */
#define PF502X_F_SW4_MODE_M_MASK         0x08U

/**
 * Mask the SW1_MODE_I interrupt
 */
#define PF502X_F_SW1_MODE_M_SHIFT        0x00U
/**
 * Mask the SW2_MODE_I interrupt
 */
#define PF502X_F_SW2_MODE_M_SHIFT        0x01U
/**
 * Mask the SW3_MODE_I interrupt
 */
#define PF502X_F_SW3_MODE_M_SHIFT        0x02U
/**
 * Mask the SW4_MODE_I interrupt
 */
#define PF502X_F_SW4_MODE_M_SHIFT        0x03U

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW1_MODE_M_UNMASKED     (0x00U << PF502X_F_SW1_MODE_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW1_MODE_M_MASKED       (0x01U << PF502X_F_SW1_MODE_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW2_MODE_M_UNMASKED     (0x00U << PF502X_F_SW2_MODE_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW2_MODE_M_MASKED       (0x01U << PF502X_F_SW2_MODE_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW3_MODE_M_UNMASKED     (0x00U << PF502X_F_SW3_MODE_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW3_MODE_M_MASKED       (0x01U << PF502X_F_SW3_MODE_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW4_MODE_M_UNMASKED     (0x00U << PF502X_F_SW4_MODE_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW4_MODE_M_MASKED       (0x01U << PF502X_F_SW4_MODE_M_SHIFT)

/******************************************************************************/
/* SW_ILIM_INT - Type: RW                                                     */
/******************************************************************************/

#define PF502X_SW_ILIM_INT_ADDR          0x0CU
#define PF502X_SW_ILIM_INT_DEFAULT       0x00U

/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW1_ILIM_I_MASK         0x01U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW2_ILIM_I_MASK         0x02U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW3_ILIM_I_MASK         0x04U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW4_ILIM_I_MASK         0x08U

/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW1_ILIM_I_SHIFT        0x00U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW2_ILIM_I_SHIFT        0x01U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW3_ILIM_I_SHIFT        0x02U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW4_ILIM_I_SHIFT        0x03U

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW1_ILIM_I_CLEARED      (0x00U << PF502X_F_SW1_ILIM_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW1_ILIM_I_SET          (0x01U << PF502X_F_SW1_ILIM_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW2_ILIM_I_CLEARED      (0x00U << PF502X_F_SW2_ILIM_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW2_ILIM_I_SET          (0x01U << PF502X_F_SW2_ILIM_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW3_ILIM_I_CLEARED      (0x00U << PF502X_F_SW3_ILIM_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW3_ILIM_I_SET          (0x01U << PF502X_F_SW3_ILIM_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW4_ILIM_I_CLEARED      (0x00U << PF502X_F_SW4_ILIM_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW4_ILIM_I_SET          (0x01U << PF502X_F_SW4_ILIM_I_SHIFT)

/******************************************************************************/
/* SW_ILIM_MASK - Type: RW                                                    */
/******************************************************************************/

#define PF502X_SW_ILIM_MASK_ADDR         0x0DU
#define PF502X_SW_ILIM_MASK_DEFAULT      0x0FU

/**
 * Mask the SW1_ILIM_I interrupt
 */
#define PF502X_F_SW1_ILIM_M_MASK         0x01U
/**
 * Mask the SW2_ILIM_I interrupt
 */
#define PF502X_F_SW2_ILIM_M_MASK         0x02U
/**
 * Mask the SW3_ILIM_I interrupt
 */
#define PF502X_F_SW3_ILIM_M_MASK         0x04U
/**
 * Mask the SW4_ILIM_I interrupt
 */
#define PF502X_F_SW4_ILIM_M_MASK         0x08U

/**
 * Mask the SW1_ILIM_I interrupt
 */
#define PF502X_F_SW1_ILIM_M_SHIFT        0x00U
/**
 * Mask the SW2_ILIM_I interrupt
 */
#define PF502X_F_SW2_ILIM_M_SHIFT        0x01U
/**
 * Mask the SW3_ILIM_I interrupt
 */
#define PF502X_F_SW3_ILIM_M_SHIFT        0x02U
/**
 * Mask the SW4_ILIM_I interrupt
 */
#define PF502X_F_SW4_ILIM_M_SHIFT        0x03U

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW1_ILIM_M_UNMASKED     (0x00U << PF502X_F_SW1_ILIM_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW1_ILIM_M_MASKED       (0x01U << PF502X_F_SW1_ILIM_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW2_ILIM_M_UNMASKED     (0x00U << PF502X_F_SW2_ILIM_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW2_ILIM_M_MASKED       (0x01U << PF502X_F_SW2_ILIM_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW3_ILIM_M_UNMASKED     (0x00U << PF502X_F_SW3_ILIM_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW3_ILIM_M_MASKED       (0x01U << PF502X_F_SW3_ILIM_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW4_ILIM_M_UNMASKED     (0x00U << PF502X_F_SW4_ILIM_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW4_ILIM_M_MASKED       (0x01U << PF502X_F_SW4_ILIM_M_SHIFT)

/******************************************************************************/
/* SW_ILIM_SENSE - Type: R                                                    */
/******************************************************************************/

#define PF502X_SW_ILIM_SENSE_ADDR        0x0EU
#define PF502X_SW_ILIM_SENSE_DEFAULT     0x00U

/**
 * Sense pin is 1 as long as the ILIM condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW1_ILIM_S_MASK         0x01U
/**
 * Sense pin is 1 as long as the ILIM condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW2_ILIM_S_MASK         0x02U
/**
 * Sense pin is 1 as long as the ILIM condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW3_ILIM_S_MASK         0x04U
/**
 * Sense pin is 1 as long as the ILIM condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW4_ILIM_S_MASK         0x08U

/**
 * Sense pin is 1 as long as the ILIM condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW1_ILIM_S_SHIFT        0x00U
/**
 * Sense pin is 1 as long as the ILIM condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW2_ILIM_S_SHIFT        0x01U
/**
 * Sense pin is 1 as long as the ILIM condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW3_ILIM_S_SHIFT        0x02U
/**
 * Sense pin is 1 as long as the ILIM condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW4_ILIM_S_SHIFT        0x03U

/**
 * SW1 Current Limit OK
 */
#define PF502X_F_SW1_ILIM_S_SW1_CURRENT_LIMIT_OK (0x00U << PF502X_F_SW1_ILIM_S_SHIFT)
/**
 * SW1 Current Limit Event
 */
#define PF502X_F_SW1_ILIM_S_SW1_CURRENT_LIMIT_EVENT (0x01U << PF502X_F_SW1_ILIM_S_SHIFT)

/**
 * SW2 Current Limit OK
 */
#define PF502X_F_SW2_ILIM_S_SW2_CURRENT_LIMIT_OK (0x00U << PF502X_F_SW2_ILIM_S_SHIFT)
/**
 * SW2 Current Limit Event
 */
#define PF502X_F_SW2_ILIM_S_SW2_CURRENT_LIMIT_EVENT (0x01U << PF502X_F_SW2_ILIM_S_SHIFT)

/**
 * SW3 Current Limit OK
 */
#define PF502X_F_SW3_ILIM_S_SW3_CURRENT_LIMIT_OK (0x00U << PF502X_F_SW3_ILIM_S_SHIFT)
/**
 * SW3 Current Limit Event
 */
#define PF502X_F_SW3_ILIM_S_SW3_CURRENT_LIMIT_EVENT (0x01U << PF502X_F_SW3_ILIM_S_SHIFT)

/**
 * SW4 Current Limit OK
 */
#define PF502X_F_SW4_ILIM_S_SW4_CURRENT_LIMIT_OK (0x00U << PF502X_F_SW4_ILIM_S_SHIFT)
/**
 * SW4 Current Limit Event
 */
#define PF502X_F_SW4_ILIM_S_SW4_CURRENT_LIMIT_EVENT (0x01U << PF502X_F_SW4_ILIM_S_SHIFT)

/******************************************************************************/
/* SW_UV_INT - Type: RW                                                       */
/******************************************************************************/

#define PF502X_SW_UV_INT_ADDR            0x12U
#define PF502X_SW_UV_INT_DEFAULT         0x00U

/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW1_UV_I_MASK           0x01U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW2_UV_I_MASK           0x02U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW3_UV_I_MASK           0x04U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW4_UV_I_MASK           0x08U

/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW1_UV_I_SHIFT          0x00U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW2_UV_I_SHIFT          0x01U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW3_UV_I_SHIFT          0x02U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW4_UV_I_SHIFT          0x03U

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW1_UV_I_CLEARED        (0x00U << PF502X_F_SW1_UV_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW1_UV_I_SET            (0x01U << PF502X_F_SW1_UV_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW2_UV_I_CLEARED        (0x00U << PF502X_F_SW2_UV_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW2_UV_I_SET            (0x01U << PF502X_F_SW2_UV_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW3_UV_I_CLEARED        (0x00U << PF502X_F_SW3_UV_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW3_UV_I_SET            (0x01U << PF502X_F_SW3_UV_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW4_UV_I_CLEARED        (0x00U << PF502X_F_SW4_UV_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW4_UV_I_SET            (0x01U << PF502X_F_SW4_UV_I_SHIFT)

/******************************************************************************/
/* SW_UV_MASK - Type: RW                                                      */
/******************************************************************************/

#define PF502X_SW_UV_MASK_ADDR           0x13U
#define PF502X_SW_UV_MASK_DEFAULT        0x0FU

/**
 * Mask the SW1_UV_I interrupt
 */
#define PF502X_F_SW1_UV_M_MASK           0x01U
/**
 * Mask the SW2_UV_I interrupt
 */
#define PF502X_F_SW2_UV_M_MASK           0x02U
/**
 * Mask the SW3_UV_I interrupt
 */
#define PF502X_F_SW3_UV_M_MASK           0x04U
/**
 * Mask the SW4_UV_I interrupt
 */
#define PF502X_F_SW4_UV_M_MASK           0x08U

/**
 * Mask the SW1_UV_I interrupt
 */
#define PF502X_F_SW1_UV_M_SHIFT          0x00U
/**
 * Mask the SW2_UV_I interrupt
 */
#define PF502X_F_SW2_UV_M_SHIFT          0x01U
/**
 * Mask the SW3_UV_I interrupt
 */
#define PF502X_F_SW3_UV_M_SHIFT          0x02U
/**
 * Mask the SW4_UV_I interrupt
 */
#define PF502X_F_SW4_UV_M_SHIFT          0x03U

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW1_UV_M_UNMASKED       (0x00U << PF502X_F_SW1_UV_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW1_UV_M_MASKED         (0x01U << PF502X_F_SW1_UV_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW2_UV_M_UNMASKED       (0x00U << PF502X_F_SW2_UV_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW2_UV_M_MASKED         (0x01U << PF502X_F_SW2_UV_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW3_UV_M_UNMASKED       (0x00U << PF502X_F_SW3_UV_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW3_UV_M_MASKED         (0x01U << PF502X_F_SW3_UV_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW4_UV_M_UNMASKED       (0x00U << PF502X_F_SW4_UV_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW4_UV_M_MASKED         (0x01U << PF502X_F_SW4_UV_M_SHIFT)

/******************************************************************************/
/* SW_UV_SENSE - Type: R                                                      */
/******************************************************************************/

#define PF502X_SW_UV_SENSE_ADDR          0x14U
#define PF502X_SW_UV_SENSE_DEFAULT       0x00U

/**
 * Sense pin is 1 as long as the UV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW1_UV_S_MASK           0x01U
/**
 * Sense pin is 1 as long as the UV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW2_UV_S_MASK           0x02U
/**
 * Sense pin is 1 as long as the UV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW3_UV_S_MASK           0x04U
/**
 * Sense pin is 1 as long as the UV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW4_UV_S_MASK           0x08U

/**
 * Sense pin is 1 as long as the UV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW1_UV_S_SHIFT          0x00U
/**
 * Sense pin is 1 as long as the UV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW2_UV_S_SHIFT          0x01U
/**
 * Sense pin is 1 as long as the UV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW3_UV_S_SHIFT          0x02U
/**
 * Sense pin is 1 as long as the UV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW4_UV_S_SHIFT          0x03U

/**
 * SW1 Undervoltage OK
 */
#define PF502X_F_SW1_UV_S_SW1_UNDERVOLTAGE_OK (0x00U << PF502X_F_SW1_UV_S_SHIFT)
/**
 * SW1 Undervoltage Event
 */
#define PF502X_F_SW1_UV_S_SW1_UNDERVOLTAGE_EVENT (0x01U << PF502X_F_SW1_UV_S_SHIFT)

/**
 * SW2 Undervoltage OK
 */
#define PF502X_F_SW2_UV_S_SW2_UNDERVOLTAGE_OK (0x00U << PF502X_F_SW2_UV_S_SHIFT)
/**
 * SW2 Undervoltage Event
 */
#define PF502X_F_SW2_UV_S_SW2_UNDERVOLTAGE_EVENT (0x01U << PF502X_F_SW2_UV_S_SHIFT)

/**
 * SW3 Undervoltage OK
 */
#define PF502X_F_SW3_UV_S_SW3_UNDERVOLTAGE_OK (0x00U << PF502X_F_SW3_UV_S_SHIFT)
/**
 * SW3 Undervoltage Event
 */
#define PF502X_F_SW3_UV_S_SW3_UNDERVOLTAGE_EVENT (0x01U << PF502X_F_SW3_UV_S_SHIFT)

/**
 * SW4 Undervoltage OK
 */
#define PF502X_F_SW4_UV_S_SW4_UNDERVOLTAGE_OK (0x00U << PF502X_F_SW4_UV_S_SHIFT)
/**
 * SW4 Undervoltage Event
 */
#define PF502X_F_SW4_UV_S_SW4_UNDERVOLTAGE_EVENT (0x01U << PF502X_F_SW4_UV_S_SHIFT)

/******************************************************************************/
/* SW_OV_INT - Type: RW                                                       */
/******************************************************************************/

#define PF502X_SW_OV_INT_ADDR            0x15U
#define PF502X_SW_OV_INT_DEFAULT         0x00U

/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW1_OV_I_MASK           0x01U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW2_OV_I_MASK           0x02U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW3_OV_I_MASK           0x04U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW4_OV_I_MASK           0x08U

/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW1_OV_I_SHIFT          0x00U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW2_OV_I_SHIFT          0x01U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW3_OV_I_SHIFT          0x02U
/**
 * Interrupt bit can be cleared even if the fault condition is still present.
 */
#define PF502X_F_SW4_OV_I_SHIFT          0x03U

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW1_OV_I_CLEARED        (0x00U << PF502X_F_SW1_OV_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW1_OV_I_SET            (0x01U << PF502X_F_SW1_OV_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW2_OV_I_CLEARED        (0x00U << PF502X_F_SW2_OV_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW2_OV_I_SET            (0x01U << PF502X_F_SW2_OV_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW3_OV_I_CLEARED        (0x00U << PF502X_F_SW3_OV_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW3_OV_I_SET            (0x01U << PF502X_F_SW3_OV_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_SW4_OV_I_CLEARED        (0x00U << PF502X_F_SW4_OV_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_SW4_OV_I_SET            (0x01U << PF502X_F_SW4_OV_I_SHIFT)

/******************************************************************************/
/* SW_OV_MASK - Type: RW                                                      */
/******************************************************************************/

#define PF502X_SW_OV_MASK_ADDR           0x16U
#define PF502X_SW_OV_MASK_DEFAULT        0x0FU

/**
 * Mask the SW1_OV_I interrupt
 */
#define PF502X_F_SW1_OV_M_MASK           0x01U
/**
 * Mask the SW2_OV_I interrupt
 */
#define PF502X_F_SW2_OV_M_MASK           0x02U
/**
 * Mask the SW3_OV_I interrupt
 */
#define PF502X_F_SW3_OV_M_MASK           0x04U
/**
 * Mask the SW4_OV_I interrupt
 */
#define PF502X_F_SW4_OV_M_MASK           0x08U

/**
 * Mask the SW1_OV_I interrupt
 */
#define PF502X_F_SW1_OV_M_SHIFT          0x00U
/**
 * Mask the SW2_OV_I interrupt
 */
#define PF502X_F_SW2_OV_M_SHIFT          0x01U
/**
 * Mask the SW3_OV_I interrupt
 */
#define PF502X_F_SW3_OV_M_SHIFT          0x02U
/**
 * Mask the SW4_OV_I interrupt
 */
#define PF502X_F_SW4_OV_M_SHIFT          0x03U

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW1_OV_M_UNMASKED       (0x00U << PF502X_F_SW1_OV_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW1_OV_M_MASKED         (0x01U << PF502X_F_SW1_OV_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW2_OV_M_UNMASKED       (0x00U << PF502X_F_SW2_OV_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW2_OV_M_MASKED         (0x01U << PF502X_F_SW2_OV_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW3_OV_M_UNMASKED       (0x00U << PF502X_F_SW3_OV_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW3_OV_M_MASKED         (0x01U << PF502X_F_SW3_OV_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_SW4_OV_M_UNMASKED       (0x00U << PF502X_F_SW4_OV_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_SW4_OV_M_MASKED         (0x01U << PF502X_F_SW4_OV_M_SHIFT)

/******************************************************************************/
/* SW_OV_SENSE - Type: R                                                      */
/******************************************************************************/

#define PF502X_SW_OV_SENSE_ADDR          0x17U
#define PF502X_SW_OV_SENSE_DEFAULT       0x00U

/**
 * Sense pin is 1 as long as the OV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW1_OV_S_MASK           0x01U
/**
 * Sense pin is 1 as long as the OV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW2_OV_S_MASK           0x02U
/**
 * Sense pin is 1 as long as the OV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW3_OV_S_MASK           0x04U
/**
 * Sense pin is 1 as long as the OV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW4_OV_S_MASK           0x08U

/**
 * Sense pin is 1 as long as the OV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW1_OV_S_SHIFT          0x00U
/**
 * Sense pin is 1 as long as the OV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW2_OV_S_SHIFT          0x01U
/**
 * Sense pin is 1 as long as the OV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW3_OV_S_SHIFT          0x02U
/**
 * Sense pin is 1 as long as the OV condition is still present in the corresponding Regulator.
 */
#define PF502X_F_SW4_OV_S_SHIFT          0x03U

/**
 * SW1 Overvoltage OK
 */
#define PF502X_F_SW1_OV_S_SW1_OVERVOLTAGE_OK (0x00U << PF502X_F_SW1_OV_S_SHIFT)
/**
 * SW1 Overvoltage Event
 */
#define PF502X_F_SW1_OV_S_SW1_OVERVOLTAGE_EVENT (0x01U << PF502X_F_SW1_OV_S_SHIFT)

/**
 * SW2 Overvoltage OK
 */
#define PF502X_F_SW2_OV_S_SW2_OVERVOLTAGE_OK (0x00U << PF502X_F_SW2_OV_S_SHIFT)
/**
 * SW2 Overvoltage Event
 */
#define PF502X_F_SW2_OV_S_SW2_OVERVOLTAGE_EVENT (0x01U << PF502X_F_SW2_OV_S_SHIFT)

/**
 * SW3 Overvoltage OK
 */
#define PF502X_F_SW3_OV_S_SW3_OVERVOLTAGE_OK (0x00U << PF502X_F_SW3_OV_S_SHIFT)
/**
 * SW3 Overvoltage Event
 */
#define PF502X_F_SW3_OV_S_SW3_OVERVOLTAGE_EVENT (0x01U << PF502X_F_SW3_OV_S_SHIFT)

/**
 * SW4 Overvoltage OK
 */
#define PF502X_F_SW4_OV_S_SW4_OVERVOLTAGE_OK (0x00U << PF502X_F_SW4_OV_S_SHIFT)
/**
 * SW4 Overvoltage Event
 */
#define PF502X_F_SW4_OV_S_SW4_OVERVOLTAGE_EVENT (0x01U << PF502X_F_SW4_OV_S_SHIFT)

/******************************************************************************/
/* PWRON_INT - Type: RW                                                       */
/******************************************************************************/

#define PF502X_PWRON_INT_ADDR            0x1EU
#define PF502X_PWRON_INT_DEFAULT         0x00U

/**
 * bit is latched when PWRON is pushed in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_PUSH_I_MASK       0x01U
/**
 * bit is latched when PWRON is Released (After a push transition ) in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_REL_I_MASK        0x02U
/**
 * bit is latched when PWRON is pushed for 1s in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_1S_I_MASK         0x04U
/**
 * bit is latched when PWRON is pushed for 2s in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_2S_I_MASK         0x08U
/**
 * bit is latched when PWRON is pushed for 3s in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_3S_I_MASK         0x10U
/**
 * bit is latched when PWRON is pushed for 4s in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_4S_I_MASK         0x20U
/**
 * bit is latched when PWRON is pushed for 8s in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_8S_I_MASK         0x40U
/**
 * bit is latched when BGMON fault is detected
 */
#define PF502X_F_BGMON_I_MASK            0x80U

/**
 * bit is latched when PWRON is pushed in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_PUSH_I_SHIFT      0x00U
/**
 * bit is latched when PWRON is Released (After a push transition ) in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_REL_I_SHIFT       0x01U
/**
 * bit is latched when PWRON is pushed for 1s in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_1S_I_SHIFT        0x02U
/**
 * bit is latched when PWRON is pushed for 2s in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_2S_I_SHIFT        0x03U
/**
 * bit is latched when PWRON is pushed for 3s in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_3S_I_SHIFT        0x04U
/**
 * bit is latched when PWRON is pushed for 4s in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_4S_I_SHIFT        0x05U
/**
 * bit is latched when PWRON is pushed for 8s in Edge sensitive Mode only
 */
#define PF502X_F_PWRON_8S_I_SHIFT        0x06U
/**
 * bit is latched when BGMON fault is detected
 */
#define PF502X_F_BGMON_I_SHIFT           0x07U

/**
 * Interrupt Cleared
 */
#define PF502X_F_PWRON_PUSH_I_CLEARED    (0x00U << PF502X_F_PWRON_PUSH_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PWRON_PUSH_I_SET        (0x01U << PF502X_F_PWRON_PUSH_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_PWRON_REL_I_CLEARED     (0x00U << PF502X_F_PWRON_REL_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PWRON_REL_I_SET         (0x01U << PF502X_F_PWRON_REL_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_PWRON_1S_I_CLEARED      (0x00U << PF502X_F_PWRON_1S_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PWRON_1S_I_SET          (0x01U << PF502X_F_PWRON_1S_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_PWRON_2S_I_CLEARED      (0x00U << PF502X_F_PWRON_2S_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PWRON_2S_I_SET          (0x01U << PF502X_F_PWRON_2S_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_PWRON_3S_I_CLEARED      (0x00U << PF502X_F_PWRON_3S_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PWRON_3S_I_SET          (0x01U << PF502X_F_PWRON_3S_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_PWRON_4S_I_CLEARED      (0x00U << PF502X_F_PWRON_4S_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PWRON_4S_I_SET          (0x01U << PF502X_F_PWRON_4S_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_PWRON_8S_I_CLEARED      (0x00U << PF502X_F_PWRON_8S_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PWRON_8S_I_SET          (0x01U << PF502X_F_PWRON_8S_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_BGMON_I_CLEARED         (0x00U << PF502X_F_BGMON_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_BGMON_I_SET             (0x01U << PF502X_F_BGMON_I_SHIFT)

/******************************************************************************/
/* PWRON_MASK - Type: RW                                                      */
/******************************************************************************/

#define PF502X_PWRON_MASK_ADDR           0x1FU
#define PF502X_PWRON_MASK_DEFAULT        0xFFU

/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_PUSH_M_MASK       0x01U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_REL_M_MASK        0x02U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_1S_M_MASK         0x04U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_2S_M_MASK         0x08U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_3S_M_MASK         0x10U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_4S_M_MASK         0x20U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_8S_M_MASK         0x40U
/**
 * Mask the BGMON interrupt
 */
#define PF502X_F_BGMON_M_MASK            0x80U

/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_PUSH_M_SHIFT      0x00U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_REL_M_SHIFT       0x01U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_1S_M_SHIFT        0x02U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_2S_M_SHIFT        0x03U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_3S_M_SHIFT        0x04U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_4S_M_SHIFT        0x05U
/**
 * Mask the corresponding Push button I interrupt
 */
#define PF502X_F_PWRON_8S_M_SHIFT        0x06U
/**
 * Mask the BGMON interrupt
 */
#define PF502X_F_BGMON_M_SHIFT           0x07U

/**
 * Interrupt Unmasked
 */
#define PF502X_F_PWRON_PUSH_M_UNMASKED   (0x00U << PF502X_F_PWRON_PUSH_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_PWRON_PUSH_M_MASKED     (0x01U << PF502X_F_PWRON_PUSH_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_PWRON_REL_M_UNMASKED    (0x00U << PF502X_F_PWRON_REL_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_PWRON_REL_M_MASKED      (0x01U << PF502X_F_PWRON_REL_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_PWRON_1S_M_UNMASKED     (0x00U << PF502X_F_PWRON_1S_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_PWRON_1S_M_MASKED       (0x01U << PF502X_F_PWRON_1S_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_PWRON_2S_M_UNMASKED     (0x00U << PF502X_F_PWRON_2S_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_PWRON_2S_M_MASKED       (0x01U << PF502X_F_PWRON_2S_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_PWRON_3S_M_UNMASKED     (0x00U << PF502X_F_PWRON_3S_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_PWRON_3S_M_MASKED       (0x01U << PF502X_F_PWRON_3S_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_PWRON_4S_M_UNMASKED     (0x00U << PF502X_F_PWRON_4S_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_PWRON_4S_M_MASKED       (0x01U << PF502X_F_PWRON_4S_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_PWRON_8S_M_UNMASKED     (0x00U << PF502X_F_PWRON_8S_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_PWRON_8S_M_MASKED       (0x01U << PF502X_F_PWRON_8S_M_SHIFT)

/**
 * Interrupt Unmasked
 */
#define PF502X_F_BGMON_M_UNMASKED        (0x00U << PF502X_F_BGMON_M_SHIFT)
/**
 * Interrupt Masked
 */
#define PF502X_F_BGMON_M_MASKED          (0x01U << PF502X_F_BGMON_M_SHIFT)

/******************************************************************************/
/* PWRON_SENSE - Type: R                                                      */
/******************************************************************************/

#define PF502X_PWRON_SENSE_ADDR          0x20U
#define PF502X_PWRON_SENSE_DEFAULT       0x00U

/**
 * Current Status of PWRON pin
 */
#define PF502X_F_PWRON_S_MASK            0x01U
/**
 * Sense bit is 1 as long as BGMON fault is still present
 */
#define PF502X_F_BGMON_S_MASK            0x80U

/**
 * Current Status of PWRON pin
 */
#define PF502X_F_PWRON_S_SHIFT           0x00U
/**
 * Sense bit is 1 as long as BGMON fault is still present
 */
#define PF502X_F_BGMON_S_SHIFT           0x07U

/**
 * PWRON pin low (push button pressed)
 */
#define PF502X_F_PWRON_S_PWRON_LOW       (0x00U << PF502X_F_PWRON_S_SHIFT)
/**
 * PWRON pin high (push button released)
 */
#define PF502X_F_PWRON_S_PWRON_HIGH      (0x01U << PF502X_F_PWRON_S_SHIFT)

/**
 * Bandgap OK
 */
#define PF502X_F_BGMON_S_BANDGAP_OK      (0x00U << PF502X_F_BGMON_S_SHIFT)
/**
 * Bandgap Fault
 */
#define PF502X_F_BGMON_S_BANDGAP_FAULT   (0x01U << PF502X_F_BGMON_S_SHIFT)

/******************************************************************************/
/* EN_SENSE - Type: R                                                         */
/******************************************************************************/

#define PF502X_EN_SENSE_ADDR             0x21U
#define PF502X_EN_SENSE_DEFAULT          0x00U

/**
 * Current Status of EN1 pin
 */
#define PF502X_F_EN1_S_MASK              0x01U
/**
 * Current Status of EN2 pin
 */
#define PF502X_F_EN2_S_MASK              0x02U
/**
 * Current Status of EN3 pin
 */
#define PF502X_F_EN3_S_MASK              0x04U
/**
 * Current Status of EN4 pin
 */
#define PF502X_F_EN4_S_MASK              0x08U

/**
 * Current Status of EN1 pin
 */
#define PF502X_F_EN1_S_SHIFT             0x00U
/**
 * Current Status of EN2 pin
 */
#define PF502X_F_EN2_S_SHIFT             0x01U
/**
 * Current Status of EN3 pin
 */
#define PF502X_F_EN3_S_SHIFT             0x02U
/**
 * Current Status of EN4 pin
 */
#define PF502X_F_EN4_S_SHIFT             0x03U

/**
 * EN1 pin low (push button pressed)
 */
#define PF502X_F_EN1_S_LOW               (0x00U << PF502X_F_EN1_S_SHIFT)
/**
 * EN1 pin high (push button released)
 */
#define PF502X_F_EN1_S_HIGH              (0x01U << PF502X_F_EN1_S_SHIFT)

/**
 * EN2 pin low (push button pressed)
 */
#define PF502X_F_EN2_S_LOW               (0x00U << PF502X_F_EN2_S_SHIFT)
/**
 * EN2 pin high (push button released)
 */
#define PF502X_F_EN2_S_HIGH              (0x01U << PF502X_F_EN2_S_SHIFT)

/**
 * EN3 pin low (push button pressed)
 */
#define PF502X_F_EN3_S_LOW               (0x00U << PF502X_F_EN3_S_SHIFT)
/**
 * EN3 pin high (push button released)
 */
#define PF502X_F_EN3_S_HIGH              (0x01U << PF502X_F_EN3_S_SHIFT)

/**
 * EN4 pin low (push button pressed)
 */
#define PF502X_F_EN4_S_LOW               (0x00U << PF502X_F_EN4_S_SHIFT)
/**
 * EN4 pin high (push button released)
 */
#define PF502X_F_EN4_S_HIGH              (0x01U << PF502X_F_EN4_S_SHIFT)

/******************************************************************************/
/* SYS_INT - Type: R                                                          */
/******************************************************************************/

#define PF502X_SYS_INT_ADDR              0x22U
#define PF502X_SYS_INT_DEFAULT           0x00U

/**
 * Bit is latched when one of bit in STATUS1_I register is set to 1.
 */
#define PF502X_F_STATUS1_I_MASK          0x01U
/**
 * Bit is latched when one of bit in STATUS2_I register is set to 1.
 */
#define PF502X_F_STATUS2_I_MASK          0x02U
/**
 * Bit is latched when one of bit in MODE_I register is set to 1.
 */
#define PF502X_F_MODE_I_MASK             0x04U
/**
 * Bit is latched when one of bit in ILIM_I register is set to 1.
 */
#define PF502X_F_ILIM_I_MASK             0x08U
/**
 * Bit is latched when one of bit in UV_I register is set to 1.
 */
#define PF502X_F_UV_I_MASK               0x10U
/**
 * Bit is latched when one of bit in OV_I register is set to 1.
 */
#define PF502X_F_OV_I_MASK               0x20U
/**
 * Bit is latched when one of bit in PWRON_I register is set to 1.
 */
#define PF502X_F_PWRON_I_MASK            0x40U
#define PF502X_F_EWARN_I_MASK            0x80U

/**
 * Bit is latched when one of bit in STATUS1_I register is set to 1.
 */
#define PF502X_F_STATUS1_I_SHIFT         0x00U
/**
 * Bit is latched when one of bit in STATUS2_I register is set to 1.
 */
#define PF502X_F_STATUS2_I_SHIFT         0x01U
/**
 * Bit is latched when one of bit in MODE_I register is set to 1.
 */
#define PF502X_F_MODE_I_SHIFT            0x02U
/**
 * Bit is latched when one of bit in ILIM_I register is set to 1.
 */
#define PF502X_F_ILIM_I_SHIFT            0x03U
/**
 * Bit is latched when one of bit in UV_I register is set to 1.
 */
#define PF502X_F_UV_I_SHIFT              0x04U
/**
 * Bit is latched when one of bit in OV_I register is set to 1.
 */
#define PF502X_F_OV_I_SHIFT              0x05U
/**
 * Bit is latched when one of bit in PWRON_I register is set to 1.
 */
#define PF502X_F_PWRON_I_SHIFT           0x06U
#define PF502X_F_EWARN_I_SHIFT           0x07U

/**
 * Interrupt Cleared
 */
#define PF502X_F_STATUS1_I_CLEARED       (0x00U << PF502X_F_STATUS1_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_STATUS1_I_SET           (0x01U << PF502X_F_STATUS1_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_STATUS2_I_CLEARED       (0x00U << PF502X_F_STATUS2_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_STATUS2_I_SET           (0x01U << PF502X_F_STATUS2_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_MODE_I_CLEARED          (0x00U << PF502X_F_MODE_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_MODE_I_SET              (0x01U << PF502X_F_MODE_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_ILIM_I_CLEARED          (0x00U << PF502X_F_ILIM_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_ILIM_I_SET              (0x01U << PF502X_F_ILIM_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_UV_I_CLEARED            (0x00U << PF502X_F_UV_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_UV_I_SET                (0x01U << PF502X_F_UV_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_OV_I_CLEARED            (0x00U << PF502X_F_OV_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_OV_I_SET                (0x01U << PF502X_F_OV_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_PWRON_I_CLEARED         (0x00U << PF502X_F_PWRON_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_PWRON_I_SET             (0x01U << PF502X_F_PWRON_I_SHIFT)

/**
 * Interrupt Cleared
 */
#define PF502X_F_EWARN_I_CLEARED         (0x00U << PF502X_F_EWARN_I_SHIFT)
/**
 * Interrupt Set
 */
#define PF502X_F_EWARN_I_SET             (0x01U << PF502X_F_EWARN_I_SHIFT)

/******************************************************************************/
/* HARDFAULT_FLAGS - Type: RW                                                 */
/******************************************************************************/

#define PF502X_HARDFAULT_FLAGS_ADDR      0x23U
#define PF502X_HARDFAULT_FLAGS_DEFAULT   0x00U

/**
 * Bit is set if the turn off event is caused by a Thermal shudown .
 */
#define PF502X_F_TSD_FAIL_MASK           0x01U
/**
 * Bit is set if the turn off event is caused by a Regulator Failure
 */
#define PF502X_F_REG_FAIL_MASK           0x02U
/**
 * Bit is set if the turn off event is caused by a Watchdog expiration
 */
#define PF502X_F_WD_FAIL_MASK            0x04U
/**
 * Bit is set if the turn off event is caused by a Power up failure.
 */
#define PF502X_F_PU_FAIL_MASK            0x08U

/**
 * Bit is set if the turn off event is caused by a Thermal shudown .
 */
#define PF502X_F_TSD_FAIL_SHIFT          0x00U
/**
 * Bit is set if the turn off event is caused by a Regulator Failure
 */
#define PF502X_F_REG_FAIL_SHIFT          0x01U
/**
 * Bit is set if the turn off event is caused by a Watchdog expiration
 */
#define PF502X_F_WD_FAIL_SHIFT           0x02U
/**
 * Bit is set if the turn off event is caused by a Power up failure.
 */
#define PF502X_F_PU_FAIL_SHIFT           0x03U

/**
 * Event not detected
 */
#define PF502X_F_TSD_FAIL_EVENT_NOT_DETECTED (0x00U << PF502X_F_TSD_FAIL_SHIFT)
/**
 * Event detected
 */
#define PF502X_F_TSD_FAIL_EVENT_DETECTED (0x01U << PF502X_F_TSD_FAIL_SHIFT)

/**
 * Event not detected
 */
#define PF502X_F_REG_FAIL_EVENT_NOT_DETECTED (0x00U << PF502X_F_REG_FAIL_SHIFT)
/**
 * Event detected
 */
#define PF502X_F_REG_FAIL_EVENT_DETECTED (0x01U << PF502X_F_REG_FAIL_SHIFT)

/**
 * Event not detected
 */
#define PF502X_F_WD_FAIL_EVENT_NOT_DETECTED (0x00U << PF502X_F_WD_FAIL_SHIFT)
/**
 * Event detected
 */
#define PF502X_F_WD_FAIL_EVENT_DETECTED  (0x01U << PF502X_F_WD_FAIL_SHIFT)

/**
 * Event not detected
 */
#define PF502X_F_PU_FAIL_EVENT_NOT_DETECTED (0x00U << PF502X_F_PU_FAIL_SHIFT)
/**
 * Event detected
 */
#define PF502X_F_PU_FAIL_EVENT_DETECTED  (0x01U << PF502X_F_PU_FAIL_SHIFT)

/******************************************************************************/
/* ABIST_PGOOD_MON - Type: RW                                                 */
/******************************************************************************/

#define PF502X_ABIST_PGOOD_MON_ADDR      0x25U
#define PF502X_ABIST_PGOOD_MON_DEFAULT   0x00U

/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_PGOOD_MON_MASK       0x01U

/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_PGOOD_MON_SHIFT      0x00U

/**
 * 0
 */
#define PF502X_F_AB_PGOOD_MON_0          (0x00U << PF502X_F_AB_PGOOD_MON_SHIFT)
/**
 * 1
 */
#define PF502X_F_AB_PGOOD_MON_1          (0x01U << PF502X_F_AB_PGOOD_MON_SHIFT)

/******************************************************************************/
/* ABIST_OV1 - Type: RW                                                       */
/******************************************************************************/

#define PF502X_ABIST_OV1_ADDR            0x26U
#define PF502X_ABIST_OV1_DEFAULT         0x00U

/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW1_OV_MASK          0x01U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW2_OV_MASK          0x02U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW3_OV_MASK          0x04U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW4_OV_MASK          0x08U

/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW1_OV_SHIFT         0x00U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW2_OV_SHIFT         0x01U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW3_OV_SHIFT         0x02U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW4_OV_SHIFT         0x03U

/**
 * 0
 */
#define PF502X_F_AB_SW1_OV_0             (0x00U << PF502X_F_AB_SW1_OV_SHIFT)
/**
 * 1
 */
#define PF502X_F_AB_SW1_OV_1             (0x01U << PF502X_F_AB_SW1_OV_SHIFT)

/**
 * 0
 */
#define PF502X_F_AB_SW2_OV_0             (0x00U << PF502X_F_AB_SW2_OV_SHIFT)
/**
 * 1
 */
#define PF502X_F_AB_SW2_OV_1             (0x01U << PF502X_F_AB_SW2_OV_SHIFT)

/**
 * 0
 */
#define PF502X_F_AB_SW3_OV_0             (0x00U << PF502X_F_AB_SW3_OV_SHIFT)
/**
 * 1
 */
#define PF502X_F_AB_SW3_OV_1             (0x01U << PF502X_F_AB_SW3_OV_SHIFT)

/**
 * 0
 */
#define PF502X_F_AB_SW4_OV_0             (0x00U << PF502X_F_AB_SW4_OV_SHIFT)
/**
 * 1
 */
#define PF502X_F_AB_SW4_OV_1             (0x01U << PF502X_F_AB_SW4_OV_SHIFT)

/******************************************************************************/
/* ABIST_UV1 - Type: RW                                                       */
/******************************************************************************/

#define PF502X_ABIST_UV1_ADDR            0x28U
#define PF502X_ABIST_UV1_DEFAULT         0x00U

/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW1_UV_MASK          0x01U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW2_UV_MASK          0x02U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW3_UV_MASK          0x04U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW4_UV_MASK          0x08U

/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW1_UV_SHIFT         0x00U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW2_UV_SHIFT         0x01U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW3_UV_SHIFT         0x02U
/**
 * Set high when a failure is detected during ABIST test.
 */
#define PF502X_F_AB_SW4_UV_SHIFT         0x03U

/**
 * 0
 */
#define PF502X_F_AB_SW1_UV_0             (0x00U << PF502X_F_AB_SW1_UV_SHIFT)
/**
 * 1
 */
#define PF502X_F_AB_SW1_UV_1             (0x01U << PF502X_F_AB_SW1_UV_SHIFT)

/**
 * 0
 */
#define PF502X_F_AB_SW2_UV_0             (0x00U << PF502X_F_AB_SW2_UV_SHIFT)
/**
 * 1
 */
#define PF502X_F_AB_SW2_UV_1             (0x01U << PF502X_F_AB_SW2_UV_SHIFT)

/**
 * 0
 */
#define PF502X_F_AB_SW3_UV_0             (0x00U << PF502X_F_AB_SW3_UV_SHIFT)
/**
 * 1
 */
#define PF502X_F_AB_SW3_UV_1             (0x01U << PF502X_F_AB_SW3_UV_SHIFT)

/**
 * 0
 */
#define PF502X_F_AB_SW4_UV_0             (0x00U << PF502X_F_AB_SW4_UV_SHIFT)
/**
 * 1
 */
#define PF502X_F_AB_SW4_UV_1             (0x01U << PF502X_F_AB_SW4_UV_SHIFT)

/******************************************************************************/
/* TEST_FLAGS - Type: RW                                                      */
/******************************************************************************/

#define PF502X_TEST_FLAGS_ADDR           0x2AU
#define PF502X_TEST_FLAGS_DEFAULT        0x00U

/**
 * Flag is set if there is an OTP Fuse loading failure.
 */
#define PF502X_F_OTP_NOK_MASK            0x01U
/**
 * Flag set if there is a Trim fuse loading failure.
 */
#define PF502X_F_TRIM_NOK_MASK           0x02U
/**
 * Flag set if the Self test fails in the TBB Mode.
 */
#define PF502X_F_STEST_NOK_MASK          0x04U

/**
 * Flag is set if there is an OTP Fuse loading failure.
 */
#define PF502X_F_OTP_NOK_SHIFT           0x00U
/**
 * Flag set if there is a Trim fuse loading failure.
 */
#define PF502X_F_TRIM_NOK_SHIFT          0x01U
/**
 * Flag set if the Self test fails in the TBB Mode.
 */
#define PF502X_F_STEST_NOK_SHIFT         0x02U

/**
 * 0
 */
#define PF502X_F_OTP_NOK_0               (0x00U << PF502X_F_OTP_NOK_SHIFT)
/**
 * 1
 */
#define PF502X_F_OTP_NOK_1               (0x01U << PF502X_F_OTP_NOK_SHIFT)

/**
 * 0
 */
#define PF502X_F_TRIM_NOK_0              (0x00U << PF502X_F_TRIM_NOK_SHIFT)
/**
 * 1
 */
#define PF502X_F_TRIM_NOK_1              (0x01U << PF502X_F_TRIM_NOK_SHIFT)

/**
 * 0
 */
#define PF502X_F_STEST_NOK_0             (0x00U << PF502X_F_STEST_NOK_SHIFT)
/**
 * 1
 */
#define PF502X_F_STEST_NOK_1             (0x01U << PF502X_F_STEST_NOK_SHIFT)

/******************************************************************************/
/* ABIST_RUN - Type: RW                                                       */
/******************************************************************************/

#define PF502X_ABIST_RUN_ADDR            0x2BU
#define PF502X_ABIST_RUN_DEFAULT         0x00U

/**
 * Write 1 to run on-demand ABIST
 */
#define PF502X_F_AB_RUN_MASK             0x01U

/**
 * Write 1 to run on-demand ABIST
 */
#define PF502X_F_AB_RUN_SHIFT            0x00U

/**
 * 0
 */
#define PF502X_F_AB_RUN_0                (0x00U << PF502X_F_AB_RUN_SHIFT)
/**
 * 1
 */
#define PF502X_F_AB_RUN_1                (0x01U << PF502X_F_AB_RUN_SHIFT)

/******************************************************************************/
/* RANDOM_GEN - Type: R                                                       */
/******************************************************************************/

#define PF502X_RANDOM_GEN_ADDR           0x2DU
#define PF502X_RANDOM_GEN_DEFAULT        0x00U

/**
 * Random Code generation for Secure write operation. MCU must read the code generated after a Secure Write command 
 * and write it on the RANDOM_CHK register.
 */
#define PF502X_F_RANDOM_GEN_MASK         0xFFU

/**
 * Random Code generation for Secure write operation. MCU must read the code generated after a Secure Write command 
 * and write it on the RANDOM_CHK register.
 */
#define PF502X_F_RANDOM_GEN_SHIFT        0x00U

/******************************************************************************/
/* RANDOM_CHK - Type: RW                                                      */
/******************************************************************************/

#define PF502X_RANDOM_CHK_ADDR           0x2EU
#define PF502X_RANDOM_CHK_DEFAULT        0x00U

/**
 * Random Code Validation register for secure write operation
 */
#define PF502X_F_RANDOM_CHK_MASK         0xFFU

/**
 * Random Code Validation register for secure write operation
 */
#define PF502X_F_RANDOM_CHK_SHIFT        0x00U

/******************************************************************************/
/* VMONEN1 - Type: RW                                                         */
/******************************************************************************/

#define PF502X_VMONEN1_ADDR              0x2FU
#define PF502X_VMONEN1_DEFAULT           0x0FU

/**
 * Enable SW1 Regulator Voltage Monitor (Secure Write)
 */
#define PF502X_F_SW1VMON_EN_MASK         0x01U
/**
 * Enable SW2 Regulator Voltage Monitor (Secure Write)
 */
#define PF502X_F_SW2VMON_EN_MASK         0x02U
/**
 * Enable SW3 Regulator Voltage Monitor (Secure Write)
 */
#define PF502X_F_SW3VMON_EN_MASK         0x04U
/**
 * Enable SW4 Regulator Voltage Monitor (Secure Write)
 */
#define PF502X_F_SW4VMON_EN_MASK         0x08U

/**
 * Enable SW1 Regulator Voltage Monitor (Secure Write)
 */
#define PF502X_F_SW1VMON_EN_SHIFT        0x00U
/**
 * Enable SW2 Regulator Voltage Monitor (Secure Write)
 */
#define PF502X_F_SW2VMON_EN_SHIFT        0x01U
/**
 * Enable SW3 Regulator Voltage Monitor (Secure Write)
 */
#define PF502X_F_SW3VMON_EN_SHIFT        0x02U
/**
 * Enable SW4 Regulator Voltage Monitor (Secure Write)
 */
#define PF502X_F_SW4VMON_EN_SHIFT        0x03U

/**
 * Voltage monitor is Disabled
 */
#define PF502X_F_SW1VMON_EN_DISABLED     (0x00U << PF502X_F_SW1VMON_EN_SHIFT)
/**
 * Voltage monitor enables along with output voltage. (Default)
 */
#define PF502X_F_SW1VMON_EN_ENABLED      (0x01U << PF502X_F_SW1VMON_EN_SHIFT)

/**
 * Voltage monitor is Disabled
 */
#define PF502X_F_SW2VMON_EN_DISABLED     (0x00U << PF502X_F_SW2VMON_EN_SHIFT)
/**
 * Voltage monitor enables along with output voltage. (Default)
 */
#define PF502X_F_SW2VMON_EN_ENABLED      (0x01U << PF502X_F_SW2VMON_EN_SHIFT)

/**
 * Voltage monitor is Disabled
 */
#define PF502X_F_SW3VMON_EN_DISABLED     (0x00U << PF502X_F_SW3VMON_EN_SHIFT)
/**
 * Voltage monitor enables along with output voltage. (Default)
 */
#define PF502X_F_SW3VMON_EN_ENABLED      (0x01U << PF502X_F_SW3VMON_EN_SHIFT)

/**
 * Voltage monitor is Disabled
 */
#define PF502X_F_SW4VMON_EN_DISABLED     (0x00U << PF502X_F_SW4VMON_EN_SHIFT)
/**
 * Voltage monitor enables along with output voltage. (Default)
 */
#define PF502X_F_SW4VMON_EN_ENABLED      (0x01U << PF502X_F_SW4VMON_EN_SHIFT)

/******************************************************************************/
/* CTRL1 - Type: RW                                                           */
/******************************************************************************/

#define PF502X_CTRL1_ADDR                0x31U
#define PF502X_CTRL1_DEFAULT             0x10U

/**
 * Enables the Secure I2C mode to dissable critical safety functions (Secure Write)
 */
#define PF502X_F_I2C_SECURE_EN_MASK      0x01U
/**
 * Selects whether PMIC reacts to WDI in Standby mode (Secure Write)
 */
#define PF502X_F_WDI_STBY_ACTIVE_MASK    0x02U
/**
 * Enables the watchdog timer during STBY mode (Secure Write)
 */
#define PF502X_F_WD_STBY_EN_MASK         0x04U
/**
 * Enables watchdog timer (Secure Write)
 */
#define PF502X_F_WD_EN_MASK              0x08U
/**
 * Enable the Temperature Monitoring circiut. (Secure Write)
 */
#define PF502X_F_TMP_MON_EN_MASK         0x10U
/**
 * Select the type of reset to be perform upon WDI event.
 */
#define PF502X_F_WDI_MODE_MASK           0x20U
/**
 * VIN OVLO Monitor Shutdown the device upon a VIN_OVLO event (Secure Write)
 */
#define PF502X_F_VIN_OVLO_SDWN_MASK      0x40U
/**
 * Enables or disable the OVLO monitor and protection (Secure Write)
 */
#define PF502X_F_VIN_OVLO_EN_MASK        0x80U

/**
 * Enables the Secure I2C mode to dissable critical safety functions (Secure Write)
 */
#define PF502X_F_I2C_SECURE_EN_SHIFT     0x00U
/**
 * Selects whether PMIC reacts to WDI in Standby mode (Secure Write)
 */
#define PF502X_F_WDI_STBY_ACTIVE_SHIFT   0x01U
/**
 * Enables the watchdog timer during STBY mode (Secure Write)
 */
#define PF502X_F_WD_STBY_EN_SHIFT        0x02U
/**
 * Enables watchdog timer (Secure Write)
 */
#define PF502X_F_WD_EN_SHIFT             0x03U
/**
 * Enable the Temperature Monitoring circiut. (Secure Write)
 */
#define PF502X_F_TMP_MON_EN_SHIFT        0x04U
/**
 * Select the type of reset to be perform upon WDI event.
 */
#define PF502X_F_WDI_MODE_SHIFT          0x05U
/**
 * VIN OVLO Monitor Shutdown the device upon a VIN_OVLO event (Secure Write)
 */
#define PF502X_F_VIN_OVLO_SDWN_SHIFT     0x06U
/**
 * Enables or disable the OVLO monitor and protection (Secure Write)
 */
#define PF502X_F_VIN_OVLO_EN_SHIFT       0x07U

/**
 * Secure write disabled
 */
#define PF502X_F_I2C_SECURE_EN_SECURE_WRITE_DISABLED (0x00U << PF502X_F_I2C_SECURE_EN_SHIFT)
/**
 * Secure write enabled
 */
#define PF502X_F_I2C_SECURE_EN_SECURE_WRITE_ENABLED (0x01U << PF502X_F_I2C_SECURE_EN_SHIFT)

/**
 * WDI event is disabled in Stadby
 */
#define PF502X_F_WDI_STBY_ACTIVE_DISABLED (0x00U << PF502X_F_WDI_STBY_ACTIVE_SHIFT)
/**
 * WDI event enabled in Standby
 */
#define PF502X_F_WDI_STBY_ACTIVE_ENABLED (0x01U << PF502X_F_WDI_STBY_ACTIVE_SHIFT)

/**
 * Disabled
 */
#define PF502X_F_WD_STBY_EN_DISABLED     (0x00U << PF502X_F_WD_STBY_EN_SHIFT)
/**
 * Enabled
 */
#define PF502X_F_WD_STBY_EN_ENABLED      (0x01U << PF502X_F_WD_STBY_EN_SHIFT)

/**
 * WD timer Disabled
 */
#define PF502X_F_WD_EN_DISABLED          (0x00U << PF502X_F_WD_EN_SHIFT)
/**
 * WD timer Enabled
 */
#define PF502X_F_WD_EN_ENABLED           (0x01U << PF502X_F_WD_EN_SHIFT)

/**
 * Temp Monitor Disabled
 */
#define PF502X_F_TMP_MON_EN_DISABLED     (0x00U << PF502X_F_TMP_MON_EN_SHIFT)
/**
 * Temp Monitor Enabled (default)
 */
#define PF502X_F_TMP_MON_EN_ENABLED      (0x01U << PF502X_F_TMP_MON_EN_SHIFT)

/**
 * Soft WD Reset
 */
#define PF502X_F_WDI_MODE_SOFT_WD_RESET  (0x00U << PF502X_F_WDI_MODE_SHIFT)
/**
 * Hard WD Reset
 */
#define PF502X_F_WDI_MODE_HARD_WD_RESET  (0x01U << PF502X_F_WDI_MODE_SHIFT)

/**
 * No shutdown on VIN_OVLO (only Interrupt sent)
 */
#define PF502X_F_VIN_OVLO_SDWN_NO_SHUTDOWN (0x00U << PF502X_F_VIN_OVLO_SDWN_SHIFT)
/**
 * Device Shutsdown upon a VIN_OVLO
 */
#define PF502X_F_VIN_OVLO_SDWN_DEVICE_SHUTSDOWN (0x01U << PF502X_F_VIN_OVLO_SDWN_SHIFT)

/**
 * the VIN_OVLO monitor is Disabled
 */
#define PF502X_F_VIN_OVLO_EN_DISABLED    (0x00U << PF502X_F_VIN_OVLO_EN_SHIFT)
/**
 * The VIN_OVLO monitor is Enabled
 */
#define PF502X_F_VIN_OVLO_EN_ENABLED     (0x01U << PF502X_F_VIN_OVLO_EN_SHIFT)

/******************************************************************************/
/* CTRL2 - Type: RW                                                           */
/******************************************************************************/

#define PF502X_CTRL2_ADDR                0x32U
#define PF502X_CTRL2_DEFAULT             0x10U

/**
 * Control the Status of PGOOD by I2C in GPO mode during the Standby state
 */
#define PF502X_F_STBY_PG_GPO_MASK        0x01U
/**
 * Control the Status of PGOOD by I2C in GPO mode during the Run state
 */
#define PF502X_F_RUN_PG_GPO_MASK         0x02U
/**
 * Invert the polarity of the STANDBY pin
 */
#define PF502X_F_STANDBYINV_MASK         0x04U
/**
 * When device is in the OFF mode enable LPM or QPU
 */
#define PF502X_F_LPM_OFF_MASK            0x08U
/**
 * Enable the Thermal monitor to be Alwasys on or Pulsed during the Run Mode
 */
#define PF502X_F_TMP_MON_AON_MASK        0x10U
/**
 * Sets the Vin overvoltage lockout debounce timer to 10, 100 or 1000 us.
 */
#define PF502X_F_VIN_OVLO_DBNC_MASK      0xC0U

/**
 * Control the Status of PGOOD by I2C in GPO mode during the Standby state
 */
#define PF502X_F_STBY_PG_GPO_SHIFT       0x00U
/**
 * Control the Status of PGOOD by I2C in GPO mode during the Run state
 */
#define PF502X_F_RUN_PG_GPO_SHIFT        0x01U
/**
 * Invert the polarity of the STANDBY pin
 */
#define PF502X_F_STANDBYINV_SHIFT        0x02U
/**
 * When device is in the OFF mode enable LPM or QPU
 */
#define PF502X_F_LPM_OFF_SHIFT           0x03U
/**
 * Enable the Thermal monitor to be Alwasys on or Pulsed during the Run Mode
 */
#define PF502X_F_TMP_MON_AON_SHIFT       0x04U
/**
 * Sets the Vin overvoltage lockout debounce timer to 10, 100 or 1000 us.
 */
#define PF502X_F_VIN_OVLO_DBNC_SHIFT     0x06U

/**
 * PGOOD low
 */
#define PF502X_F_STBY_PG_GPO_LOW         (0x00U << PF502X_F_STBY_PG_GPO_SHIFT)
/**
 * PGOOD high
 */
#define PF502X_F_STBY_PG_GPO_HIGH        (0x01U << PF502X_F_STBY_PG_GPO_SHIFT)

/**
 * PGOOD low
 */
#define PF502X_F_RUN_PG_GPO_LOW          (0x00U << PF502X_F_RUN_PG_GPO_SHIFT)
/**
 * PGOOD high
 */
#define PF502X_F_RUN_PG_GPO_HIGH         (0x01U << PF502X_F_RUN_PG_GPO_SHIFT)

/**
 * STANDBY pin Active High
 */
#define PF502X_F_STANDBYINV_ACTIVE_HIGH  (0x00U << PF502X_F_STANDBYINV_SHIFT)
/**
 * STANDBY pin Active Low
 */
#define PF502X_F_STANDBYINV_ACTIVE_LOW   (0x01U << PF502X_F_STANDBYINV_SHIFT)

/**
 * LPM (Low power mode) (default)
 */
#define PF502X_F_LPM_OFF_LPM             (0x00U << PF502X_F_LPM_OFF_SHIFT)
/**
 * QPU (Quick power up)
 */
#define PF502X_F_LPM_OFF_QPU             (0x01U << PF502X_F_LPM_OFF_SHIFT)

/**
 * Thermal monitor is turend on every 1ms
 */
#define PF502X_F_TMP_MON_AON_ON_EVERY_1MS (0x00U << PF502X_F_TMP_MON_AON_SHIFT)
/**
 * Thermal monitor is Always on
 */
#define PF502X_F_TMP_MON_AON_ALWAYS_ON   (0x01U << PF502X_F_TMP_MON_AON_SHIFT)

/**
 * 10 us
 */
#define PF502X_F_VIN_OVLO_DBNC_10_US     (0x00U << PF502X_F_VIN_OVLO_DBNC_SHIFT)
/**
 * 100 us
 */
#define PF502X_F_VIN_OVLO_DBNC_100_US    (0x01U << PF502X_F_VIN_OVLO_DBNC_SHIFT)
/**
 * 1000 us
 */
#define PF502X_F_VIN_OVLO_DBNC_1000_US   (0x02U << PF502X_F_VIN_OVLO_DBNC_SHIFT)

/******************************************************************************/
/* CTRL3 - Type: RW                                                           */
/******************************************************************************/

#define PF502X_CTRL3_ADDR                0x33U
#define PF502X_CTRL3_DEFAULT             0x20U

/**
 * Bit self-clears to 0 after test pulse is performed.
 */
#define PF502X_F_INTB_TEST_MASK          0x01U
/**
 * If Pin is nor cleared within that time, device will initiate a shut down sequence.
 */
#define PF502X_F_PMIC_OFF_MASK           0x02U
/**
 * Under voltage debounce time selection
 */
#define PF502X_F_UV_DB_MASK              0x30U
/**
 * Over voltage debounce time selection
 */
#define PF502X_F_OV_DB_MASK              0xC0U

/**
 * Bit self-clears to 0 after test pulse is performed.
 */
#define PF502X_F_INTB_TEST_SHIFT         0x00U
/**
 * If Pin is nor cleared within that time, device will initiate a shut down sequence.
 */
#define PF502X_F_PMIC_OFF_SHIFT          0x01U
/**
 * Under voltage debounce time selection
 */
#define PF502X_F_UV_DB_SHIFT             0x04U
/**
 * Over voltage debounce time selection
 */
#define PF502X_F_OV_DB_SHIFT             0x06U

/**
 * 0
 */
#define PF502X_F_INTB_TEST_0               (0x00U << PF502X_F_INTB_TEST_SHIFT)
/**
 * 1
 */
#define PF502X_F_INTB_TEST_1               (0x01U << PF502X_F_INTB_TEST_SHIFT)

/**
 * 0
 */
#define PF502X_F_PMIC_OFF_0                (0x00U << PF502X_F_PMIC_OFF_SHIFT)
/**
 * 1
 */
#define PF502X_F_PMIC_OFF_1                (0x01U << PF502X_F_PMIC_OFF_SHIFT)

/**
 * 5 us
 */
#define PF502X_F_UV_DB_5_US              (0x00U << PF502X_F_UV_DB_SHIFT)
/**
 * 15 us
 */
#define PF502X_F_UV_DB_15_US             (0x01U << PF502X_F_UV_DB_SHIFT)
/**
 * 30 us ( Default)
 */
#define PF502X_F_UV_DB_30_US             (0x02U << PF502X_F_UV_DB_SHIFT)
/**
 * 40 us
 */
#define PF502X_F_UV_DB_40_US             (0x03U << PF502X_F_UV_DB_SHIFT)

/**
 * 30 us (Default)
 */
#define PF502X_F_OV_DB_30_US             (0x00U << PF502X_F_OV_DB_SHIFT)
/**
 * 50 us
 */
#define PF502X_F_OV_DB_50_US             (0x01U << PF502X_F_OV_DB_SHIFT)
/**
 * 80 us
 */
#define PF502X_F_OV_DB_80_US             (0x02U << PF502X_F_OV_DB_SHIFT)
/**
 * 125 us
 */
#define PF502X_F_OV_DB_125_US            (0x03U << PF502X_F_OV_DB_SHIFT)

/******************************************************************************/
/* PWRUP_CTRL - Type: RW                                                      */
/******************************************************************************/

#define PF502X_PWRUP_CTRL_ADDR           0x34U
#define PF502X_PWRUP_CTRL_DEFAULT        0x00U

/**
 * *Power Off Reset values to default OTP value.
 */
#define PF502X_F_SEQ_TBASE_MASK          0x03U
/**
 * Power-down group for RESETBMCU
 */
#define PF502X_F_RESETBMCU_PDGRP_MASK    0x0CU
/**
 * Power-down group for PGOOD
 */
#define PF502X_F_PGOOD_PDGRP_MASK        0x30U
/**
 * Enable the Power down sequence by groups
 */
#define PF502X_F_PWRDWN_MODE_MASK        0x40U

/**
 * *Power Off Reset values to default OTP value.
 */
#define PF502X_F_SEQ_TBASE_SHIFT         0x00U
/**
 * Power-down group for RESETBMCU
 */
#define PF502X_F_RESETBMCU_PDGRP_SHIFT   0x02U
/**
 * Power-down group for PGOOD
 */
#define PF502X_F_PGOOD_PDGRP_SHIFT       0x04U
/**
 * Enable the Power down sequence by groups
 */
#define PF502X_F_PWRDWN_MODE_SHIFT       0x06U

/**
 * 30 us
 */
#define PF502X_F_SEQ_TBASE_30_US         (0x00U << PF502X_F_SEQ_TBASE_SHIFT)
/**
 * 120 us
 */
#define PF502X_F_SEQ_TBASE_120_US        (0x01U << PF502X_F_SEQ_TBASE_SHIFT)
/**
 * 250 us
 */
#define PF502X_F_SEQ_TBASE_250_US        (0x02U << PF502X_F_SEQ_TBASE_SHIFT)
/**
 * 500 us
 */
#define PF502X_F_SEQ_TBASE_500_US        (0x03U << PF502X_F_SEQ_TBASE_SHIFT)

/**
 * RESETBMCU is in Group 4
 */
#define PF502X_F_RESETBMCU_PDGRP_GROUP_4 (0x00U << PF502X_F_RESETBMCU_PDGRP_SHIFT)
/**
 * RESETBMCU is in Group 3
 */
#define PF502X_F_RESETBMCU_PDGRP_GROUP_3 (0x01U << PF502X_F_RESETBMCU_PDGRP_SHIFT)
/**
 * RESETBMCU is in Group 2
 */
#define PF502X_F_RESETBMCU_PDGRP_GROUP_2 (0x02U << PF502X_F_RESETBMCU_PDGRP_SHIFT)
/**
 * RESETBMCU is in Group 1
 */
#define PF502X_F_RESETBMCU_PDGRP_GROUP_1 (0x03U << PF502X_F_RESETBMCU_PDGRP_SHIFT)

/**
 * PGOOD is in Group 4
 */
#define PF502X_F_PGOOD_PDGRP_GROUP_4     (0x00U << PF502X_F_PGOOD_PDGRP_SHIFT)
/**
 * PGOOD is in Group 3
 */
#define PF502X_F_PGOOD_PDGRP_GROUP_3     (0x01U << PF502X_F_PGOOD_PDGRP_SHIFT)
/**
 * PGOOD is in Group 2
 */
#define PF502X_F_PGOOD_PDGRP_GROUP_2     (0x02U << PF502X_F_PGOOD_PDGRP_SHIFT)
/**
 * PGOOD is in Group 1
 */
#define PF502X_F_PGOOD_PDGRP_GROUP_1     (0x03U << PF502X_F_PGOOD_PDGRP_SHIFT)

/**
 * Power Down sequence is a mirror of the power up sequence (one by one)
 */
#define PF502X_F_PWRDWN_MODE_INDIVIDUAL_POWER_DOWN (0x00U << PF502X_F_PWRDWN_MODE_SHIFT)
/**
 * Power down sequence use the group sequencing mode
 */
#define PF502X_F_PWRDWN_MODE_GROUP_POWER_DOWN (0x01U << PF502X_F_PWRDWN_MODE_SHIFT)

/******************************************************************************/
/* RESETBMCU_PWRUP - Type: RW                                                 */
/******************************************************************************/

#define PF502X_RESETBMCU_PWRUP_ADDR      0x36U
#define PF502X_RESETBMCU_PWRUP_DEFAULT   0x00U

/**
 * Functional bits can be changed to set the power down sequence.
 */
#define PF502X_F_RESETBMCU_SEQ_MASK      0xFFU

/**
 * Functional bits can be changed to set the power down sequence.
 */
#define PF502X_F_RESETBMCU_SEQ_SHIFT     0x00U

/******************************************************************************/
/* PGOOD_PWRUP - Type: RW                                                     */
/******************************************************************************/

#define PF502X_PGOOD_PWRUP_ADDR          0x37U
#define PF502X_PGOOD_PWRUP_DEFAULT       0x00U

/**
 * Functional bits can be changed to set the power down sequence.
 */
#define PF502X_F_PGOOD_SEQ_MASK          0xFFU

/**
 * Functional bits can be changed to set the power down sequence.
 */
#define PF502X_F_PGOOD_SEQ_SHIFT         0x00U

/******************************************************************************/
/* PWRDN_DLY1 - Type: RW                                                      */
/******************************************************************************/

#define PF502X_PWRDN_DLY1_ADDR           0x38U
#define PF502X_PWRDN_DLY1_DEFAULT        0x00U

/**
 * Sets the time base for Group1 power down sequencing.
 */
#define PF502X_F_GRP1_DLY_MASK           0x03U
/**
 * Sets the time base for Group 2 power down sequencing.
 */
#define PF502X_F_GRP2_DLY_MASK           0x0CU
/**
 * Sets the time base for Group 3 power down sequencing.
 */
#define PF502X_F_GRP3_DLY_MASK           0x30U
/**
 * Sets the time base for Group 4 power down sequencing.
 */
#define PF502X_F_GRP4_DLY_MASK           0xC0U

/**
 * Sets the time base for Group1 power down sequencing.
 */
#define PF502X_F_GRP1_DLY_SHIFT          0x00U
/**
 * Sets the time base for Group 2 power down sequencing.
 */
#define PF502X_F_GRP2_DLY_SHIFT          0x02U
/**
 * Sets the time base for Group 3 power down sequencing.
 */
#define PF502X_F_GRP3_DLY_SHIFT          0x04U
/**
 * Sets the time base for Group 4 power down sequencing.
 */
#define PF502X_F_GRP4_DLY_SHIFT          0x06U

/**
 * 120 us
 */
#define PF502X_F_GRP1_DLY_120_US         (0x00U << PF502X_F_GRP1_DLY_SHIFT)
/**
 * 250 us
 */
#define PF502X_F_GRP1_DLY_250_US         (0x01U << PF502X_F_GRP1_DLY_SHIFT)
/**
 * 500 us
 */
#define PF502X_F_GRP1_DLY_500_US         (0x02U << PF502X_F_GRP1_DLY_SHIFT)
/**
 * 1000 us
 */
#define PF502X_F_GRP1_DLY_1000_US        (0x03U << PF502X_F_GRP1_DLY_SHIFT)

/**
 * 120 us
 */
#define PF502X_F_GRP2_DLY_120_US         (0x00U << PF502X_F_GRP2_DLY_SHIFT)
/**
 * 250 us
 */
#define PF502X_F_GRP2_DLY_250_US         (0x01U << PF502X_F_GRP2_DLY_SHIFT)
/**
 * 500 us
 */
#define PF502X_F_GRP2_DLY_500_US         (0x02U << PF502X_F_GRP2_DLY_SHIFT)
/**
 * 1000 us
 */
#define PF502X_F_GRP2_DLY_1000_US        (0x03U << PF502X_F_GRP2_DLY_SHIFT)

/**
 * 120 us
 */
#define PF502X_F_GRP3_DLY_120_US         (0x00U << PF502X_F_GRP3_DLY_SHIFT)
/**
 * 250 us
 */
#define PF502X_F_GRP3_DLY_250_US         (0x01U << PF502X_F_GRP3_DLY_SHIFT)
/**
 * 500 us
 */
#define PF502X_F_GRP3_DLY_500_US         (0x02U << PF502X_F_GRP3_DLY_SHIFT)
/**
 * 1000 us
 */
#define PF502X_F_GRP3_DLY_1000_US        (0x03U << PF502X_F_GRP3_DLY_SHIFT)

/**
 * 120 us
 */
#define PF502X_F_GRP4_DLY_120_US         (0x00U << PF502X_F_GRP4_DLY_SHIFT)
/**
 * 250 us
 */
#define PF502X_F_GRP4_DLY_250_US         (0x01U << PF502X_F_GRP4_DLY_SHIFT)
/**
 * 500 us
 */
#define PF502X_F_GRP4_DLY_500_US         (0x02U << PF502X_F_GRP4_DLY_SHIFT)
/**
 * 1000 us
 */
#define PF502X_F_GRP4_DLY_1000_US        (0x03U << PF502X_F_GRP4_DLY_SHIFT)

/******************************************************************************/
/* PWRDN_DLY2 - Type: RW                                                      */
/******************************************************************************/

#define PF502X_PWRDN_DLY2_ADDR           0x39U
#define PF502X_PWRDN_DLY2_DEFAULT        0x00U

/**
 * Set the delay between the RESETBMCU asserting and the first regulator in the selected power down group.
 */
#define PF502X_F_RESETBMCU_DLY_MASK      0x03U

/**
 * Set the delay between the RESETBMCU asserting and the first regulator in the selected power down group.
 */
#define PF502X_F_RESETBMCU_DLY_SHIFT     0x00U

/**
 * No delay
 */
#define PF502X_F_RESETBMCU_DLY_NO_DELAY  (0x00U << PF502X_F_RESETBMCU_DLY_SHIFT)
/**
 * 10 us
 */
#define PF502X_F_RESETBMCU_DLY_10_US     (0x01U << PF502X_F_RESETBMCU_DLY_SHIFT)
/**
 * 100 us
 */
#define PF502X_F_RESETBMCU_DLY_100_US    (0x02U << PF502X_F_RESETBMCU_DLY_SHIFT)
/**
 * 500 us
 */
#define PF502X_F_RESETBMCU_DLY_500_US    (0x03U << PF502X_F_RESETBMCU_DLY_SHIFT)

/******************************************************************************/
/* FREQ_CTRL - Type: RW                                                       */
/******************************************************************************/

#define PF502X_FREQ_CTRL_ADDR            0x3AU
#define PF502X_FREQ_CTRL_DEFAULT         0x00U

/**
 * Manual frequency tuning control (allow frequency range from 2MHz to 3MHz)
 */
#define PF502X_F_CLK_FREQ_MASK           0x0FU
/**
 * Set the Frequency Spread Spectrum Range
 */
#define PF502X_F_FSS_RANGE_MASK          0x10U
/**
 * Enable Frequency Spread Spectrum feature
 */
#define PF502X_F_FSS_EN_MASK             0x20U
/**
 * Selects the Input Clock frequency range
 */
#define PF502X_F_FSYNC_RANGE_MASK        0x40U
/**
 * Enables/disables CLKOUT
 */
#define PF502X_F_SYNCOUT_EN_MASK         0x80U

/**
 * Manual frequency tuning control (allow frequency range from 2MHz to 3MHz)
 */
#define PF502X_F_CLK_FREQ_SHIFT          0x00U
/**
 * Set the Frequency Spread Spectrum Range
 */
#define PF502X_F_FSS_RANGE_SHIFT         0x04U
/**
 * Enable Frequency Spread Spectrum feature
 */
#define PF502X_F_FSS_EN_SHIFT            0x05U
/**
 * Selects the Input Clock frequency range
 */
#define PF502X_F_FSYNC_RANGE_SHIFT       0x06U
/**
 * Enables/disables CLKOUT
 */
#define PF502X_F_SYNCOUT_EN_SHIFT        0x07U

/**
 * 2.500 MHz
 */
#define PF502X_F_CLK_FREQ_2_500_MHZ      (0x00U << PF502X_F_CLK_FREQ_SHIFT)
/**
 * 2.625 MHz
 */
#define PF502X_F_CLK_FREQ_2_625_MHZ      (0x01U << PF502X_F_CLK_FREQ_SHIFT)
/**
 * 2.750 MHz
 */
#define PF502X_F_CLK_FREQ_2_750_MHZ      (0x02U << PF502X_F_CLK_FREQ_SHIFT)
/**
 * 2.875 MHz
 */
#define PF502X_F_CLK_FREQ_2_875_MHZ      (0x03U << PF502X_F_CLK_FREQ_SHIFT)
/**
 * 3.000 MHz
 */
#define PF502X_F_CLK_FREQ_3_000_MHZ      (0x04U << PF502X_F_CLK_FREQ_SHIFT)
/**
 * 2.000 MHz
 */
#define PF502X_F_CLK_FREQ_2_000_MHZ      (0x09U << PF502X_F_CLK_FREQ_SHIFT)
/**
 * 2.125 MHz
 */
#define PF502X_F_CLK_FREQ_2_125_MHZ      (0x0AU << PF502X_F_CLK_FREQ_SHIFT)
/**
 * 2.250 MHz
 */
#define PF502X_F_CLK_FREQ_2_250_MHZ      (0x0BU << PF502X_F_CLK_FREQ_SHIFT)
/**
 * 2.375 MHz
 */
#define PF502X_F_CLK_FREQ_2_375_MHZ      (0x0CU << PF502X_F_CLK_FREQ_SHIFT)

/**
 * +/- 5%
 */
#define PF502X_F_FSS_RANGE_5             (0x00U << PF502X_F_FSS_RANGE_SHIFT)
/**
 * +/- 10%
 */
#define PF502X_F_FSS_RANGE_10            (0x01U << PF502X_F_FSS_RANGE_SHIFT)

/**
 * Disabled
 */
#define PF502X_F_FSS_EN_DISABLED         (0x00U << PF502X_F_FSS_EN_SHIFT)
/**
 * Enabled
 */
#define PF502X_F_FSS_EN_ENABLED          (0x01U << PF502X_F_FSS_EN_SHIFT)

/**
 * 2000KHz to 3000KHz
 */
#define PF502X_F_FSYNC_RANGE_2000_KHZ_3000_KHZ (0x00U << PF502X_F_FSYNC_RANGE_SHIFT)
/**
 * 333KHZ to 500KHz
 */
#define PF502X_F_FSYNC_RANGE_333_KHZ_500_KHZ (0x01U << PF502X_F_FSYNC_RANGE_SHIFT)

/**
 * Disabled
 */
#define PF502X_F_SYNCOUT_EN_DISABLED     (0x00U << PF502X_F_SYNCOUT_EN_SHIFT)
/**
 * Enabled
 */
#define PF502X_F_SYNCOUT_EN_ENABLED      (0x01U << PF502X_F_SYNCOUT_EN_SHIFT)

/******************************************************************************/
/* PWRON - Type: RW                                                           */
/******************************************************************************/

#define PF502X_PWRON_ADDR                0x3CU
#define PF502X_PWRON_DEFAULT             0x00U

/**
 * Sets PWRON push duration for hard reset in Edge sensitive mode
 */
#define PF502X_F_TRESET_MASK             0x03U
/**
 * Pressing the PWRON button for longer that TRESET generate an PMIC Reset.
 */
#define PF502X_F_PWRON_RST_EN_MASK       0x04U
/**
 * Sets the PWRON  debounce timer (32, 32, 125, 750 ms)
 */
#define PF502X_F_PWRON_DBNC_MASK         0x18U

/**
 * Sets PWRON push duration for hard reset in Edge sensitive mode
 */
#define PF502X_F_TRESET_SHIFT            0x00U
/**
 * Pressing the PWRON button for longer that TRESET generate an PMIC Reset.
 */
#define PF502X_F_PWRON_RST_EN_SHIFT      0x02U
/**
 * Sets the PWRON  debounce timer (32, 32, 125, 750 ms)
 */
#define PF502X_F_PWRON_DBNC_SHIFT        0x03U

/**
 * 2 sec
 */
#define PF502X_F_TRESET_2_SEC            (0x00U << PF502X_F_TRESET_SHIFT)
/**
 * 4 sec
 */
#define PF502X_F_TRESET_4_SEC            (0x01U << PF502X_F_TRESET_SHIFT)
/**
 * 8 sec
 */
#define PF502X_F_TRESET_8_SEC            (0x02U << PF502X_F_TRESET_SHIFT)
/**
 * 16 sec
 */
#define PF502X_F_TRESET_16_SEC           (0x03U << PF502X_F_TRESET_SHIFT)

/**
 * PMIC shuts down after push button pressed for longer than TRESET
 */
#define PF502X_F_PWRON_RST_EN_SHUT_DOWN  (0x00U << PF502X_F_PWRON_RST_EN_SHIFT)
/**
 * PMIC reset after push button pressed for longer than TRESET.
 */
#define PF502X_F_PWRON_RST_EN_RESET      (0x01U << PF502X_F_PWRON_RST_EN_SHIFT)

/**
 * 32ms
 */
#define PF502X_F_PWRON_DBNC_32_MS        (0x00U << PF502X_F_PWRON_DBNC_SHIFT)
/**
 * 125ms
 */
#define PF502X_F_PWRON_DBNC_125_MS       (0x02U << PF502X_F_PWRON_DBNC_SHIFT)
/**
 * 750ms
 */
#define PF502X_F_PWRON_DBNC_750_MS       (0x03U << PF502X_F_PWRON_DBNC_SHIFT)

/******************************************************************************/
/* WD_CONFIG - Type: RW                                                       */
/******************************************************************************/

#define PF502X_WD_CONFIG_ADDR            0x3DU
#define PF502X_WD_CONFIG_DEFAULT         0x00U

/**
 * Selects the Watchdog Window duration between 1ms and 32.768 s
 */
#define PF502X_F_WD_DURATION_MASK        0x0FU

/**
 * Selects the Watchdog Window duration between 1ms and 32.768 s
 */
#define PF502X_F_WD_DURATION_SHIFT       0x00U

/**
 * 1 ms
 */
#define PF502X_F_WD_DURATION_1_MS        (0x00U << PF502X_F_WD_DURATION_SHIFT)
/**
 * 2 ms
 */
#define PF502X_F_WD_DURATION_2_MS        (0x01U << PF502X_F_WD_DURATION_SHIFT)
/**
 * 4 ms
 */
#define PF502X_F_WD_DURATION_4_MS        (0x02U << PF502X_F_WD_DURATION_SHIFT)
/**
 * 8 ms
 */
#define PF502X_F_WD_DURATION_8_MS        (0x03U << PF502X_F_WD_DURATION_SHIFT)
/**
 * 16 ms
 */
#define PF502X_F_WD_DURATION_16_MS       (0x04U << PF502X_F_WD_DURATION_SHIFT)
/**
 * 32 ms
 */
#define PF502X_F_WD_DURATION_32_MS       (0x05U << PF502X_F_WD_DURATION_SHIFT)
/**
 * 64 ms
 */
#define PF502X_F_WD_DURATION_64_MS       (0x06U << PF502X_F_WD_DURATION_SHIFT)
/**
 * 128 ms
 */
#define PF502X_F_WD_DURATION_128_MS      (0x07U << PF502X_F_WD_DURATION_SHIFT)
/**
 * 256 ms
 */
#define PF502X_F_WD_DURATION_256_MS      (0x08U << PF502X_F_WD_DURATION_SHIFT)
/**
 * 512 ms
 */
#define PF502X_F_WD_DURATION_512_MS      (0x09U << PF502X_F_WD_DURATION_SHIFT)
/**
 * 1024 ms
 */
#define PF502X_F_WD_DURATION_1024_MS     (0x0AU << PF502X_F_WD_DURATION_SHIFT)
/**
 * 2048 ms
 */
#define PF502X_F_WD_DURATION_2048_MS     (0x0BU << PF502X_F_WD_DURATION_SHIFT)
/**
 * 4096 ms
 */
#define PF502X_F_WD_DURATION_4096_MS     (0x0CU << PF502X_F_WD_DURATION_SHIFT)
/**
 * 8192 ms
 */
#define PF502X_F_WD_DURATION_8192_MS     (0x0DU << PF502X_F_WD_DURATION_SHIFT)
/**
 * 16384 ms
 */
#define PF502X_F_WD_DURATION_16384_MS    (0x0EU << PF502X_F_WD_DURATION_SHIFT)
/**
 * 32768 ms
 */
#define PF502X_F_WD_DURATION_32768_MS    (0x0FU << PF502X_F_WD_DURATION_SHIFT)

/******************************************************************************/
/* WD_CLEAR - Type: RW                                                        */
/******************************************************************************/

#define PF502X_WD_CLEAR_ADDR             0x3EU
#define PF502X_WD_CLEAR_DEFAULT          0x00U

/**
 * Write a 1 to this flag to clear.
 */
#define PF502X_F_WD_CLEAR_MASK           0x01U

/**
 * Write a 1 to this flag to clear.
 */
#define PF502X_F_WD_CLEAR_SHIFT          0x00U

/**
 * Cleared
 */
#define PF502X_F_WD_CLEAR_0              (0x00U << PF502X_F_WD_CLEAR_SHIFT)
/**
 * Set
 */
#define PF502X_F_WD_CLEAR_1              (0x01U << PF502X_F_WD_CLEAR_SHIFT)

/******************************************************************************/
/* WD_EXPIRE - Type: RW                                                       */
/******************************************************************************/

#define PF502X_WD_EXPIRE_ADDR            0x3FU
#define PF502X_WD_EXPIRE_DEFAULT         0x00U

/**
 * When Timer is cleared successfully, it is decreased by 1.
 */
#define PF502X_F_WD_EXPIRE_CNT_MASK      0x07U
/**
 * Sets the Maximum number of times the WD timer is allowed to expire before starting a WD reset.
 */
#define PF502X_F_WD_MAX_EXPIRE_MASK      0x70U

/**
 * When Timer is cleared successfully, it is decreased by 1.
 */
#define PF502X_F_WD_EXPIRE_CNT_SHIFT     0x00U
/**
 * Sets the Maximum number of times the WD timer is allowed to expire before starting a WD reset.
 */
#define PF502X_F_WD_MAX_EXPIRE_SHIFT     0x04U

/**
 * 0
 */
#define PF502X_F_WD_EXPIRE_CNT_0         (0x00U << PF502X_F_WD_EXPIRE_CNT_SHIFT)
/**
 * 1
 */
#define PF502X_F_WD_EXPIRE_CNT_1         (0x01U << PF502X_F_WD_EXPIRE_CNT_SHIFT)
/**
 * 2
 */
#define PF502X_F_WD_EXPIRE_CNT_2         (0x02U << PF502X_F_WD_EXPIRE_CNT_SHIFT)
/**
 * 3
 */
#define PF502X_F_WD_EXPIRE_CNT_3         (0x03U << PF502X_F_WD_EXPIRE_CNT_SHIFT)
/**
 * 4
 */
#define PF502X_F_WD_EXPIRE_CNT_4         (0x04U << PF502X_F_WD_EXPIRE_CNT_SHIFT)
/**
 * 5
 */
#define PF502X_F_WD_EXPIRE_CNT_5         (0x05U << PF502X_F_WD_EXPIRE_CNT_SHIFT)
/**
 * 6
 */
#define PF502X_F_WD_EXPIRE_CNT_6         (0x06U << PF502X_F_WD_EXPIRE_CNT_SHIFT)
/**
 * 7
 */
#define PF502X_F_WD_EXPIRE_CNT_7         (0x07U << PF502X_F_WD_EXPIRE_CNT_SHIFT)

/**
 * 0
 */
#define PF502X_F_WD_MAX_EXPIRE_0         (0x00U << PF502X_F_WD_MAX_EXPIRE_SHIFT)
/**
 * 1
 */
#define PF502X_F_WD_MAX_EXPIRE_1         (0x01U << PF502X_F_WD_MAX_EXPIRE_SHIFT)
/**
 * 2
 */
#define PF502X_F_WD_MAX_EXPIRE_2         (0x02U << PF502X_F_WD_MAX_EXPIRE_SHIFT)
/**
 * 3
 */
#define PF502X_F_WD_MAX_EXPIRE_3         (0x03U << PF502X_F_WD_MAX_EXPIRE_SHIFT)
/**
 * 4
 */
#define PF502X_F_WD_MAX_EXPIRE_4         (0x04U << PF502X_F_WD_MAX_EXPIRE_SHIFT)
/**
 * 5
 */
#define PF502X_F_WD_MAX_EXPIRE_5         (0x05U << PF502X_F_WD_MAX_EXPIRE_SHIFT)
/**
 * 6
 */
#define PF502X_F_WD_MAX_EXPIRE_6         (0x06U << PF502X_F_WD_MAX_EXPIRE_SHIFT)
/**
 * 7
 */
#define PF502X_F_WD_MAX_EXPIRE_7         (0x07U << PF502X_F_WD_MAX_EXPIRE_SHIFT)

/******************************************************************************/
/* WD_COUNTER - Type: RW                                                      */
/******************************************************************************/

#define PF502X_WD_COUNTER_ADDR           0x40U
#define PF502X_WD_COUNTER_DEFAULT        0x00U

/**
 * After a successful recovery from a WD fault, MCU is expected to reset these bits.
 */
#define PF502X_F_WD_EVENT_CNT_MASK       0x0FU
/**
 * Sets the Max number of WATCHDOG failures before proceeding to Fail safe transition.
 */
#define PF502X_F_WD_MAX_CNT_MASK         0xF0U

/**
 * After a successful recovery from a WD fault, MCU is expected to reset these bits.
 */
#define PF502X_F_WD_EVENT_CNT_SHIFT      0x00U
/**
 * Sets the Max number of WATCHDOG failures before proceeding to Fail safe transition.
 */
#define PF502X_F_WD_MAX_CNT_SHIFT        0x04U

/**
 * 0
 */
#define PF502X_F_WD_EVENT_CNT_0          (0x00U << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 1
 */
#define PF502X_F_WD_EVENT_CNT_1          (0x01U << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 2
 */
#define PF502X_F_WD_EVENT_CNT_2          (0x02U << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 3
 */
#define PF502X_F_WD_EVENT_CNT_3          (0x03U << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 4
 */
#define PF502X_F_WD_EVENT_CNT_4          (0x04U << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 5
 */
#define PF502X_F_WD_EVENT_CNT_5          (0x05U << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 6
 */
#define PF502X_F_WD_EVENT_CNT_6          (0x06U << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 7
 */
#define PF502X_F_WD_EVENT_CNT_7          (0x07U << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 8
 */
#define PF502X_F_WD_EVENT_CNT_8            (0x08U << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 9
 */
#define PF502X_F_WD_EVENT_CNT_9            (0x09U << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 10
 */
#define PF502X_F_WD_EVENT_CNT_10           (0x0AU << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 11
 */
#define PF502X_F_WD_EVENT_CNT_11           (0x0BU << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 12
 */
#define PF502X_F_WD_EVENT_CNT_12           (0x0CU << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 13
 */
#define PF502X_F_WD_EVENT_CNT_13           (0x0DU << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 14
 */
#define PF502X_F_WD_EVENT_CNT_14           (0x0EU << PF502X_F_WD_EVENT_CNT_SHIFT)
/**
 * 15
 */
#define PF502X_F_WD_EVENT_CNT_15           (0x0FU << PF502X_F_WD_EVENT_CNT_SHIFT)

/**
 * 0
 */
#define PF502X_F_WD_MAX_CNT_0            (0x00U << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 1
 */
#define PF502X_F_WD_MAX_CNT_1            (0x01U << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 2
 */
#define PF502X_F_WD_MAX_CNT_2            (0x02U << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 3
 */
#define PF502X_F_WD_MAX_CNT_3            (0x03U << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 4
 */
#define PF502X_F_WD_MAX_CNT_4            (0x04U << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 5
 */
#define PF502X_F_WD_MAX_CNT_5            (0x05U << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 6
 */
#define PF502X_F_WD_MAX_CNT_6            (0x06U << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 7
 */
#define PF502X_F_WD_MAX_CNT_7            (0x07U << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 8
 */
#define PF502X_F_WD_MAX_CNT_8              (0x08U << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 9
 */
#define PF502X_F_WD_MAX_CNT_9              (0x09U << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 10
 */
#define PF502X_F_WD_MAX_CNT_10             (0x0AU << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 11
 */
#define PF502X_F_WD_MAX_CNT_11             (0x0BU << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 12
 */
#define PF502X_F_WD_MAX_CNT_12             (0x0CU << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 13
 */
#define PF502X_F_WD_MAX_CNT_13             (0x0DU << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 14
 */
#define PF502X_F_WD_MAX_CNT_14             (0x0EU << PF502X_F_WD_MAX_CNT_SHIFT)
/**
 * 15
 */
#define PF502X_F_WD_MAX_CNT_15             (0x0FU << PF502X_F_WD_MAX_CNT_SHIFT)

/******************************************************************************/
/* FAULT_COUNTER - Type: RW                                                   */
/******************************************************************************/

#define PF502X_FAULT_COUNTER_ADDR        0x41U
#define PF502X_FAULT_COUNTER_DEFAULT     0x00U

/**
 * After a Fault condition is cleared the MCU is expected to reset this counter
 */
#define PF502X_F_FAULT_CNT_MASK          0x0FU
/**
 * Set the maximum number of times the device can go into a regulator Fault condition prior to move to start a power 
 * down sequence and move to the fail-safe transition.
 */
#define PF502X_F_FAULT_MAX_CNT_MASK      0xF0U

/**
 * After a Fault condition is cleared the MCU is expected to reset this counter
 */
#define PF502X_F_FAULT_CNT_SHIFT         0x00U
/**
 * Set the maximum number of times the device can go into a regulator Fault condition prior to move to start a power 
 * down sequence and move to the fail-safe transition.
 */
#define PF502X_F_FAULT_MAX_CNT_SHIFT     0x04U

/**
 * 0
 */
#define PF502X_F_FAULT_CNT_0             (0x00U << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 1
 */
#define PF502X_F_FAULT_CNT_1             (0x01U << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 2
 */
#define PF502X_F_FAULT_CNT_2             (0x02U << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 3
 */
#define PF502X_F_FAULT_CNT_3             (0x03U << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 4
 */
#define PF502X_F_FAULT_CNT_4             (0x04U << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 5
 */
#define PF502X_F_FAULT_CNT_5             (0x05U << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 6
 */
#define PF502X_F_FAULT_CNT_6             (0x06U << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 7
 */
#define PF502X_F_FAULT_CNT_7             (0x07U << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 8
 */
#define PF502X_F_FAULT_CNT_8             (0x08U << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 9
 */
#define PF502X_F_FAULT_CNT_9             (0x09U << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 10
 */
#define PF502X_F_FAULT_CNT_10            (0x0AU << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 11
 */
#define PF502X_F_FAULT_CNT_11            (0x0BU << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 12
 */
#define PF502X_F_FAULT_CNT_12            (0x0CU << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 13
 */
#define PF502X_F_FAULT_CNT_13            (0x0DU << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 14
 */
#define PF502X_F_FAULT_CNT_14            (0x0EU << PF502X_F_FAULT_CNT_SHIFT)
/**
 * 15
 */
#define PF502X_F_FAULT_CNT_15            (0x0FU << PF502X_F_FAULT_CNT_SHIFT)

/**
 * 0
 */
#define PF502X_F_FAULT_MAX_CNT_0         (0x00U << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 1
 */
#define PF502X_F_FAULT_MAX_CNT_1         (0x01U << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 2
 */
#define PF502X_F_FAULT_MAX_CNT_2         (0x02U << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 3
 */
#define PF502X_F_FAULT_MAX_CNT_3         (0x03U << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 4
 */
#define PF502X_F_FAULT_MAX_CNT_4         (0x04U << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 5
 */
#define PF502X_F_FAULT_MAX_CNT_5         (0x05U << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 6
 */
#define PF502X_F_FAULT_MAX_CNT_6         (0x06U << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 7
 */
#define PF502X_F_FAULT_MAX_CNT_7         (0x07U << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 8
 */
#define PF502X_F_FAULT_MAX_CNT_8         (0x08U << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 9
 */
#define PF502X_F_FAULT_MAX_CNT_9         (0x09U << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 10
 */
#define PF502X_F_FAULT_MAX_CNT_10        (0x0AU << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 11
 */
#define PF502X_F_FAULT_MAX_CNT_11        (0x0BU << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 12
 */
#define PF502X_F_FAULT_MAX_CNT_12        (0x0CU << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 13
 */
#define PF502X_F_FAULT_MAX_CNT_13        (0x0DU << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 14
 */
#define PF502X_F_FAULT_MAX_CNT_14        (0x0EU << PF502X_F_FAULT_MAX_CNT_SHIFT)
/**
 * 15
 */
#define PF502X_F_FAULT_MAX_CNT_15        (0x0FU << PF502X_F_FAULT_MAX_CNT_SHIFT)

/******************************************************************************/
/* FSAFE_COUNTER - Type: RW                                                   */
/******************************************************************************/

#define PF502X_FSAFE_COUNTER_ADDR        0x42U
#define PF502X_FSAFE_COUNTER_DEFAULT     0x00U

/**
 * *FS_CNT is decreased everytime time the Fail-safe OK timer is reached the programmed time
 */
#define PF502X_F_FS_CNT_MASK             0x0FU

/**
 * *FS_CNT is decreased everytime time the Fail-safe OK timer is reached the programmed time
 */
#define PF502X_F_FS_CNT_SHIFT            0x00U

/**
 * 1 min
 */
#define PF502X_F_FS_CNT_1_MIN            (0x00U << PF502X_F_FS_CNT_SHIFT)
/**
 * 5 min
 */
#define PF502X_F_FS_CNT_5_MIN            (0x01U << PF502X_F_FS_CNT_SHIFT)
/**
 * 10 min
 */
#define PF502X_F_FS_CNT_10_MIN           (0x02U << PF502X_F_FS_CNT_SHIFT)
/**
 * 15 min
 */
#define PF502X_F_FS_CNT_15_MIN           (0x03U << PF502X_F_FS_CNT_SHIFT)
/**
 * 20 min
 */
#define PF502X_F_FS_CNT_20_MIN           (0x04U << PF502X_F_FS_CNT_SHIFT)
/**
 * 30 min
 */
#define PF502X_F_FS_CNT_30_MIN           (0x05U << PF502X_F_FS_CNT_SHIFT)
/**
 * 45 min
 */
#define PF502X_F_FS_CNT_45_MIN           (0x06U << PF502X_F_FS_CNT_SHIFT)
/**
 * 60 min
 */
#define PF502X_F_FS_CNT_60_MIN           (0x07U << PF502X_F_FS_CNT_SHIFT)

/******************************************************************************/
/* FAULT_TIMERS - Type: RW                                                    */
/******************************************************************************/

#define PF502X_FAULT_TIMERS_ADDR         0x43U
#define PF502X_FAULT_TIMERS_DEFAULT      0x00U

/**
 * Set the duration of the Fault Timer. From 1 to 2056 ms
 */
#define PF502X_F_TIMER_FAULT_MASK        0x0FU

/**
 * Set the duration of the Fault Timer. From 1 to 2056 ms
 */
#define PF502X_F_TIMER_FAULT_SHIFT       0x00U

/**
 * 1 ms
 */
#define PF502X_F_TIMER_FAULT_1_MS        (0x00U << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 2 ms
 */
#define PF502X_F_TIMER_FAULT_2_MS        (0x01U << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 4 ms
 */
#define PF502X_F_TIMER_FAULT_4_MS        (0x02U << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 8 ms
 */
#define PF502X_F_TIMER_FAULT_8_MS        (0x03U << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 16 ms
 */
#define PF502X_F_TIMER_FAULT_16_MS       (0x04U << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 32 ms
 */
#define PF502X_F_TIMER_FAULT_32_MS       (0x05U << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 64 ms
 */
#define PF502X_F_TIMER_FAULT_64_MS       (0x06U << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 128 ms
 */
#define PF502X_F_TIMER_FAULT_128_MS      (0x07U << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 256 ms
 */
#define PF502X_F_TIMER_FAULT_256_MS      (0x08U << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 512 ms
 */
#define PF502X_F_TIMER_FAULT_512_MS      (0x09U << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 1024 ms
 */
#define PF502X_F_TIMER_FAULT_1024_MS     (0x0AU << PF502X_F_TIMER_FAULT_SHIFT)
/**
 * 2056 ms
 */
#define PF502X_F_TIMER_FAULT_2056_MS     (0x0BU << PF502X_F_TIMER_FAULT_SHIFT)

/******************************************************************************/
/* AMUX - Type: RW                                                            */
/******************************************************************************/

#define PF502X_AMUX_ADDR                 0x44U
#define PF502X_AMUX_DEFAULT              0x00U

/**
 * Select AMUX output resource.
 */
#define PF502X_F_AMUX_SEL_MASK           0x1FU
/**
 * Enable AMUX mode.
 */
#define PF502X_F_AMUX_EN_MASK            0x20U

/**
 * Select AMUX output resource.
 */
#define PF502X_F_AMUX_SEL_SHIFT          0x00U
/**
 * Enable AMUX mode.
 */
#define PF502X_F_AMUX_EN_SHIFT           0x05U

/**
 * AMUX disabled - PGOOD mode.
 */
#define PF502X_F_AMUX_EN_DISABLE         (0x00U << PF502X_F_AMUX_EN_SHIFT)
/**
 * AMUX enabled
 */
#define PF502X_F_AMUX_EN_ENABLE          (0x01U << PF502X_F_AMUX_EN_SHIFT)

/******************************************************************************/
/* SW_RAMP - Type: RW                                                         */
/******************************************************************************/

#define PF502X_SW_RAMP_ADDR              0x46U
#define PF502X_SW_RAMP_DEFAULT           0x00U

/**
 * Set the DVS ramp speed for SW regulator.
 */
#define PF502X_F_SW1DVS_RAMP_MASK        0x03U
/**
 * Set the DVS ramp speed for SW regulator.
 */
#define PF502X_F_SW2DVS_RAMP_MASK        0x0CU
/**
 * Set the DVS ramp speed for SW regulator.
 */
#define PF502X_F_SW3DVS_RAMP_MASK        0x30U
/**
 * Set the DVS ramp speed for SW regulator.
 */
#define PF502X_F_SW4DVS_RAMP_MASK        0xC0U

/**
 * Set the DVS ramp speed for SW regulator.
 */
#define PF502X_F_SW1DVS_RAMP_SHIFT       0x00U
/**
 * Set the DVS ramp speed for SW regulator.
 */
#define PF502X_F_SW2DVS_RAMP_SHIFT       0x02U
/**
 * Set the DVS ramp speed for SW regulator.
 */
#define PF502X_F_SW3DVS_RAMP_SHIFT       0x04U
/**
 * Set the DVS ramp speed for SW regulator.
 */
#define PF502X_F_SW4DVS_RAMP_SHIFT       0x06U

/**
 * 6.25 mV/us
 */
#define PF502X_F_SW1DVS_RAMP_6_25_MV_US  (0x00U << PF502X_F_SW1DVS_RAMP_SHIFT)
/**
 * 12.5 mV/us
 */
#define PF502X_F_SW1DVS_RAMP_12_5_MV_US  (0x01U << PF502X_F_SW1DVS_RAMP_SHIFT)
/**
 * 3.12 mV/us
 */
#define PF502X_F_SW1DVS_RAMP_3_12_MV_US  (0x02U << PF502X_F_SW1DVS_RAMP_SHIFT)
/**
 * 1.56 mV/us
 */
#define PF502X_F_SW1DVS_RAMP_1_56_MV_US  (0x03U << PF502X_F_SW1DVS_RAMP_SHIFT)

/**
 * 6.25 mV/us
 */
#define PF502X_F_SW2DVS_RAMP_6_25_MV_US  (0x00U << PF502X_F_SW2DVS_RAMP_SHIFT)
/**
 * 12.5 mV/us
 */
#define PF502X_F_SW2DVS_RAMP_12_5_MV_US  (0x01U << PF502X_F_SW2DVS_RAMP_SHIFT)
/**
 * 3.12 mV/us
 */
#define PF502X_F_SW2DVS_RAMP_3_12_MV_US  (0x02U << PF502X_F_SW2DVS_RAMP_SHIFT)
/**
 * 1.56 mV/us
 */
#define PF502X_F_SW2DVS_RAMP_1_56_MV_US  (0x03U << PF502X_F_SW2DVS_RAMP_SHIFT)

/**
 * 6.25 mV/us
 */
#define PF502X_F_SW3DVS_RAMP_6_25_MV_US  (0x00U << PF502X_F_SW3DVS_RAMP_SHIFT)
/**
 * 12.5 mV/us
 */
#define PF502X_F_SW3DVS_RAMP_12_5_MV_US  (0x01U << PF502X_F_SW3DVS_RAMP_SHIFT)
/**
 * 3.12 mV/us
 */
#define PF502X_F_SW3DVS_RAMP_3_12_MV_US  (0x02U << PF502X_F_SW3DVS_RAMP_SHIFT)
/**
 * 1.56 mV/us
 */
#define PF502X_F_SW3DVS_RAMP_1_56_MV_US  (0x03U << PF502X_F_SW3DVS_RAMP_SHIFT)

/**
 * 6.25 mV/us
 */
#define PF502X_F_SW4DVS_RAMP_6_25_MV_US  (0x00U << PF502X_F_SW4DVS_RAMP_SHIFT)
/**
 * 12.5 mV/us
 */
#define PF502X_F_SW4DVS_RAMP_12_5_MV_US  (0x01U << PF502X_F_SW4DVS_RAMP_SHIFT)
/**
 * 3.12 mV/us
 */
#define PF502X_F_SW4DVS_RAMP_3_12_MV_US  (0x02U << PF502X_F_SW4DVS_RAMP_SHIFT)
/**
 * 1.56 mV/us
 */
#define PF502X_F_SW4DVS_RAMP_1_56_MV_US  (0x03U << PF502X_F_SW4DVS_RAMP_SHIFT)

/******************************************************************************/
/* SW1_CONFIG1 - Type: RW                                                     */
/******************************************************************************/

#define PF502X_SW1_CONFIG1_ADDR          0x47U
#define PF502X_SW1_CONFIG1_DEFAULT       0x1CU

/**
 * Allows SW1 regulator to control the PGOOD pin.
 */
#define PF502X_F_SW1_PG_EN_MASK          0x01U
/**
 * Enable Watchdog bypass for SW1 Regulator
 */
#define PF502X_F_SW1_WDBYPASS_MASK       0x02U
/**
 * Decides wherther SW1 Regulator remains enable or is disabled upon an ILIM Fault event
 */
#define PF502X_F_SW1_ILIM_STATE_MASK     0x04U
/**
 * Decides wherther SW1 Regulator remains enable or is disabled upon an OV Fault event
 */
#define PF502X_F_SW1_OV_STATE_MASK       0x08U
/**
 * Decides wherther SW1 Regulator remains enable or is disabled upon an UV Fault event
 */
#define PF502X_F_SW1_UV_STATE_MASK       0x10U
/**
 * Bypass the ILIM Fault event on SW1 Regulator
 */
#define PF502X_F_SW1_ILIM_BYPASS_MASK    0x20U
/**
 * Bypass the OV Fault event on SW1 Regulator
 */
#define PF502X_F_SW1_OV_BYPASS_MASK      0x40U
/**
 * Bypass the UV Fault event on SW1 Regulator
 */
#define PF502X_F_SW1_UV_BYPASS_MASK      0x80U

/**
 * Allows SW1 regulator to control the PGOOD pin.
 */
#define PF502X_F_SW1_PG_EN_SHIFT         0x00U
/**
 * Enable Watchdog bypass for SW1 Regulator
 */
#define PF502X_F_SW1_WDBYPASS_SHIFT      0x01U
/**
 * Decides wherther SW1 Regulator remains enable or is disabled upon an ILIM Fault event
 */
#define PF502X_F_SW1_ILIM_STATE_SHIFT    0x02U
/**
 * Decides wherther SW1 Regulator remains enable or is disabled upon an OV Fault event
 */
#define PF502X_F_SW1_OV_STATE_SHIFT      0x03U
/**
 * Decides wherther SW1 Regulator remains enable or is disabled upon an UV Fault event
 */
#define PF502X_F_SW1_UV_STATE_SHIFT      0x04U
/**
 * Bypass the ILIM Fault event on SW1 Regulator
 */
#define PF502X_F_SW1_ILIM_BYPASS_SHIFT   0x05U
/**
 * Bypass the OV Fault event on SW1 Regulator
 */
#define PF502X_F_SW1_OV_BYPASS_SHIFT     0x06U
/**
 * Bypass the UV Fault event on SW1 Regulator
 */
#define PF502X_F_SW1_UV_BYPASS_SHIFT     0x07U

/**
 * regulator is not able to set or clear the PGOOD pin
 */
#define PF502X_F_SW1_PG_EN_DISABLED      (0x00U << PF502X_F_SW1_PG_EN_SHIFT)
/**
 * Regulator's PG bit is part of the AND function to control PGOOD pin
 */
#define PF502X_F_SW1_PG_EN_ENABLED       (0x01U << PF502X_F_SW1_PG_EN_SHIFT)

/**
 * Regulator reacts upon a Watchdog
 */
#define PF502X_F_SW1_WDBYPASS_ENABLED    (0x00U << PF502X_F_SW1_WDBYPASS_SHIFT)
/**
 * Regulator bypass Watchdog event and keeps current configuration
 */
#define PF502X_F_SW1_WDBYPASS_BYPASS     (0x01U << PF502X_F_SW1_WDBYPASS_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW1_ILIM_STATE_DISABLED (0x00U << PF502X_F_SW1_ILIM_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW1_ILIM_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW1_ILIM_STATE_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW1_OV_STATE_DISABLED   (0x00U << PF502X_F_SW1_OV_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW1_OV_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW1_OV_STATE_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW1_UV_STATE_DISABLED   (0x00U << PF502X_F_SW1_UV_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW1_UV_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW1_UV_STATE_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW1_ILIM_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW1_ILIM_BYPASS_SHIFT)
/**
 * The Fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW1_ILIM_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW1_ILIM_BYPASS_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW1_OV_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW1_OV_BYPASS_SHIFT)
/**
 * The fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW1_OV_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW1_OV_BYPASS_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW1_UV_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW1_UV_BYPASS_SHIFT)
/**
 * The fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW1_UV_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW1_UV_BYPASS_SHIFT)

/******************************************************************************/
/* SW1_CONFIG2 - Type: RW                                                     */
/******************************************************************************/

#define PF502X_SW1_CONFIG2_ADDR          0x48U
#define PF502X_SW1_CONFIG2_DEFAULT       0x80U

/**
 * Set the Phase shift for SW1 Regulator
 */
#define PF502X_F_SW1PHASE_MASK           0x07U
/**
 * Set the current limit for SW1 Regulator
 */
#define PF502X_F_SW1ILIM_MASK            0x18U
/**
 * If SW1  is disabled upon a fault, this bit allow the regulator to re-enable when the fault condition is cleared.
 */
#define PF502X_F_SW1_FLT_REN_MASK        0x80U

/**
 * Set the Phase shift for SW1 Regulator
 */
#define PF502X_F_SW1PHASE_SHIFT          0x00U
/**
 * Set the current limit for SW1 Regulator
 */
#define PF502X_F_SW1ILIM_SHIFT           0x03U
/**
 * If SW1  is disabled upon a fault, this bit allow the regulator to re-enable when the fault condition is cleared.
 */
#define PF502X_F_SW1_FLT_REN_SHIFT       0x07U

/**
 * 45_
 */
#define PF502X_F_SW1PHASE_45_            (0x00U << PF502X_F_SW1PHASE_SHIFT)
/**
 * 90_
 */
#define PF502X_F_SW1PHASE_90_            (0x01U << PF502X_F_SW1PHASE_SHIFT)
/**
 * 135_
 */
#define PF502X_F_SW1PHASE_135_           (0x02U << PF502X_F_SW1PHASE_SHIFT)
/**
 * 180_
 */
#define PF502X_F_SW1PHASE_180_           (0x03U << PF502X_F_SW1PHASE_SHIFT)
/**
 * 225_
 */
#define PF502X_F_SW1PHASE_225_           (0x04U << PF502X_F_SW1PHASE_SHIFT)
/**
 * 270_
 */
#define PF502X_F_SW1PHASE_270_           (0x05U << PF502X_F_SW1PHASE_SHIFT)
/**
 * 315_
 */
#define PF502X_F_SW1PHASE_315_           (0x06U << PF502X_F_SW1PHASE_SHIFT)
/**
 * 0_
 */
#define PF502X_F_SW1PHASE_0_             (0x07U << PF502X_F_SW1PHASE_SHIFT)

/**
 * 2.1A
 */
#define PF502X_F_SW1ILIM_2_1_A           (0x00U << PF502X_F_SW1ILIM_SHIFT)
/**
 * 2.6A
 */
#define PF502X_F_SW1ILIM_2_6_A           (0x01U << PF502X_F_SW1ILIM_SHIFT)
/**
 * 3.0A
 */
#define PF502X_F_SW1ILIM_3_0_A           (0x02U << PF502X_F_SW1ILIM_SHIFT)
/**
 * 4.5A
 */
#define PF502X_F_SW1ILIM_4_5_A           (0x03U << PF502X_F_SW1ILIM_SHIFT)

/**
 * Regulator remains disabled upon clrearing the fault
 */
#define PF502X_F_SW1_FLT_REN_DISABLED    (0x00U << PF502X_F_SW1_FLT_REN_SHIFT)
/**
 * Regulator returns to its previous configuration.
 */
#define PF502X_F_SW1_FLT_REN_PREVIOUS_CONFIG_ (0x01U << PF502X_F_SW1_FLT_REN_SHIFT)

/******************************************************************************/
/* SW1_PWRUP - Type: RW                                                       */
/******************************************************************************/

#define PF502X_SW1_PWRUP_ADDR            0x49U
#define PF502X_SW1_PWRUP_DEFAULT         0x00U

/**
 * *Power Off Reset values to default OTP value.
 */
#define PF502X_F_SW1_SEQ_MASK            0xFFU

/**
 * *Power Off Reset values to default OTP value.
 */
#define PF502X_F_SW1_SEQ_SHIFT           0x00U

/******************************************************************************/
/* SW1_MODE1 - Type: RW                                                       */
/******************************************************************************/

#define PF502X_SW1_MODE1_ADDR            0x4AU
#define PF502X_SW1_MODE1_DEFAULT         0x00U

/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW1_RUN_MODE_MASK       0x03U
/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW1_STBY_MODE_MASK      0x0CU
/**
 * Assign a Power Down group to SW1 Register.
 */
#define PF502X_F_SW1_PDGRP_MASK          0x30U

/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW1_RUN_MODE_SHIFT      0x00U
/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW1_STBY_MODE_SHIFT     0x02U
/**
 * Assign a Power Down group to SW1 Register.
 */
#define PF502X_F_SW1_PDGRP_SHIFT         0x04U

/**
 * OFF
 */
#define PF502X_F_SW1_RUN_MODE_OFF        (0x00U << PF502X_F_SW1_RUN_MODE_SHIFT)
/**
 * PWM
 */
#define PF502X_F_SW1_RUN_MODE_PWM        (0x01U << PF502X_F_SW1_RUN_MODE_SHIFT)
/**
 * PFM
 */
#define PF502X_F_SW1_RUN_MODE_PFM        (0x02U << PF502X_F_SW1_RUN_MODE_SHIFT)
/**
 * Auto Skip mode
 */
#define PF502X_F_SW1_RUN_MODE_AUTO_SKIP_MODE (0x03U << PF502X_F_SW1_RUN_MODE_SHIFT)

/**
 * OFF
 */
#define PF502X_F_SW1_STBY_MODE_OFF       (0x00U << PF502X_F_SW1_STBY_MODE_SHIFT)
/**
 * PWM
 */
#define PF502X_F_SW1_STBY_MODE_PWM       (0x01U << PF502X_F_SW1_STBY_MODE_SHIFT)
/**
 * PFM
 */
#define PF502X_F_SW1_STBY_MODE_PFM       (0x02U << PF502X_F_SW1_STBY_MODE_SHIFT)
/**
 * Auto Skip mode
 */
#define PF502X_F_SW1_STBY_MODE_AUTO_SKIP_MODE (0x03U << PF502X_F_SW1_STBY_MODE_SHIFT)

/**
 * Regulator is in Group 4 (turn of first)
 */
#define PF502X_F_SW1_PDGRP_GROUP_4       (0x00U << PF502X_F_SW1_PDGRP_SHIFT)
/**
 * Regulator is in Group 3
 */
#define PF502X_F_SW1_PDGRP_GROUP_3       (0x01U << PF502X_F_SW1_PDGRP_SHIFT)
/**
 * Regulator is in Group 2
 */
#define PF502X_F_SW1_PDGRP_GROUP_2       (0x02U << PF502X_F_SW1_PDGRP_SHIFT)
/**
 * Regulator is in Group 1 (turn off Last)
 */
#define PF502X_F_SW1_PDGRP_GROUP_1       (0x03U << PF502X_F_SW1_PDGRP_SHIFT)

/******************************************************************************/
/* SW1_RUN_VOLT - Type: RW                                                    */
/******************************************************************************/

#define PF502X_SW1_RUN_VOLT_ADDR         0x4BU
#define PF502X_SW1_RUN_VOLT_DEFAULT      0x00U

/**
 * It uses the OTP_VSW1  to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW1_RUN_MASK           0xFFU

/**
 * It uses the OTP_VSW1  to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW1_RUN_SHIFT          0x00U

/**
 * 0.400000 V
 */
#define PF502X_F_VSW1_RUN_0_400000_V     (0x00U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.406250 V
 */
#define PF502X_F_VSW1_RUN_0_406250_V     (0x01U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.412500 V
 */
#define PF502X_F_VSW1_RUN_0_412500_V     (0x02U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.418750 V
 */
#define PF502X_F_VSW1_RUN_0_418750_V     (0x03U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.425000 V
 */
#define PF502X_F_VSW1_RUN_0_425000_V     (0x04U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.431250 V
 */
#define PF502X_F_VSW1_RUN_0_431250_V     (0x05U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.437500 V
 */
#define PF502X_F_VSW1_RUN_0_437500_V     (0x06U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.443750 V
 */
#define PF502X_F_VSW1_RUN_0_443750_V     (0x07U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.450000 V
 */
#define PF502X_F_VSW1_RUN_0_450000_V     (0x08U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.456250 V
 */
#define PF502X_F_VSW1_RUN_0_456250_V     (0x09U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.462500 V
 */
#define PF502X_F_VSW1_RUN_0_462500_V     (0x0AU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.468750 V
 */
#define PF502X_F_VSW1_RUN_0_468750_V     (0x0BU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.475000 V
 */
#define PF502X_F_VSW1_RUN_0_475000_V     (0x0CU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.481250 V
 */
#define PF502X_F_VSW1_RUN_0_481250_V     (0x0DU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.487500 V
 */
#define PF502X_F_VSW1_RUN_0_487500_V     (0x0EU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.493750 V
 */
#define PF502X_F_VSW1_RUN_0_493750_V     (0x0FU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.500000 V
 */
#define PF502X_F_VSW1_RUN_0_500000_V     (0x10U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.506250 V
 */
#define PF502X_F_VSW1_RUN_0_506250_V     (0x11U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.512500 V
 */
#define PF502X_F_VSW1_RUN_0_512500_V     (0x12U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.518750 V
 */
#define PF502X_F_VSW1_RUN_0_518750_V     (0x13U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.525000 V
 */
#define PF502X_F_VSW1_RUN_0_525000_V     (0x14U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.531250 V
 */
#define PF502X_F_VSW1_RUN_0_531250_V     (0x15U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.537500 V
 */
#define PF502X_F_VSW1_RUN_0_537500_V     (0x16U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.543750 V
 */
#define PF502X_F_VSW1_RUN_0_543750_V     (0x17U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.550000 V
 */
#define PF502X_F_VSW1_RUN_0_550000_V     (0x18U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.556250 V
 */
#define PF502X_F_VSW1_RUN_0_556250_V     (0x19U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.562500 V
 */
#define PF502X_F_VSW1_RUN_0_562500_V     (0x1AU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.568750 V
 */
#define PF502X_F_VSW1_RUN_0_568750_V     (0x1BU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.575000 V
 */
#define PF502X_F_VSW1_RUN_0_575000_V     (0x1CU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.581250 V
 */
#define PF502X_F_VSW1_RUN_0_581250_V     (0x1DU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.587500 V
 */
#define PF502X_F_VSW1_RUN_0_587500_V     (0x1EU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.593750 V
 */
#define PF502X_F_VSW1_RUN_0_593750_V     (0x1FU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.600000 V
 */
#define PF502X_F_VSW1_RUN_0_600000_V     (0x20U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.606250 V
 */
#define PF502X_F_VSW1_RUN_0_606250_V     (0x21U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.612500 V
 */
#define PF502X_F_VSW1_RUN_0_612500_V     (0x22U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.618750 V
 */
#define PF502X_F_VSW1_RUN_0_618750_V     (0x23U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.625000 V
 */
#define PF502X_F_VSW1_RUN_0_625000_V     (0x24U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.631250 V
 */
#define PF502X_F_VSW1_RUN_0_631250_V     (0x25U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.637500 V
 */
#define PF502X_F_VSW1_RUN_0_637500_V     (0x26U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.643750 V
 */
#define PF502X_F_VSW1_RUN_0_643750_V     (0x27U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.650000 V
 */
#define PF502X_F_VSW1_RUN_0_650000_V     (0x28U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.656250 V
 */
#define PF502X_F_VSW1_RUN_0_656250_V     (0x29U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.662500 V
 */
#define PF502X_F_VSW1_RUN_0_662500_V     (0x2AU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.668750 V
 */
#define PF502X_F_VSW1_RUN_0_668750_V     (0x2BU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.675000 V
 */
#define PF502X_F_VSW1_RUN_0_675000_V     (0x2CU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.681250 V
 */
#define PF502X_F_VSW1_RUN_0_681250_V     (0x2DU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.687500 V
 */
#define PF502X_F_VSW1_RUN_0_687500_V     (0x2EU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.693750 V
 */
#define PF502X_F_VSW1_RUN_0_693750_V     (0x2FU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.700000 V
 */
#define PF502X_F_VSW1_RUN_0_700000_V     (0x30U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.706250 V
 */
#define PF502X_F_VSW1_RUN_0_706250_V     (0x31U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.712500 V
 */
#define PF502X_F_VSW1_RUN_0_712500_V     (0x32U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.718750 V
 */
#define PF502X_F_VSW1_RUN_0_718750_V     (0x33U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.725000 V
 */
#define PF502X_F_VSW1_RUN_0_725000_V     (0x34U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.731250 V
 */
#define PF502X_F_VSW1_RUN_0_731250_V     (0x35U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.737500 V
 */
#define PF502X_F_VSW1_RUN_0_737500_V     (0x36U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.743750 V
 */
#define PF502X_F_VSW1_RUN_0_743750_V     (0x37U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.750000 V
 */
#define PF502X_F_VSW1_RUN_0_750000_V     (0x38U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.756250 V
 */
#define PF502X_F_VSW1_RUN_0_756250_V     (0x39U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.762500 V
 */
#define PF502X_F_VSW1_RUN_0_762500_V     (0x3AU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.768750 V
 */
#define PF502X_F_VSW1_RUN_0_768750_V     (0x3BU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.775000 V
 */
#define PF502X_F_VSW1_RUN_0_775000_V     (0x3CU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.781250 V
 */
#define PF502X_F_VSW1_RUN_0_781250_V     (0x3DU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.787500 V
 */
#define PF502X_F_VSW1_RUN_0_787500_V     (0x3EU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.793750 V
 */
#define PF502X_F_VSW1_RUN_0_793750_V     (0x3FU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.800000 V
 */
#define PF502X_F_VSW1_RUN_0_800000_V     (0x40U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.806250 V
 */
#define PF502X_F_VSW1_RUN_0_806250_V     (0x41U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.812500 V
 */
#define PF502X_F_VSW1_RUN_0_812500_V     (0x42U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.818750 V
 */
#define PF502X_F_VSW1_RUN_0_818750_V     (0x43U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.825000 V
 */
#define PF502X_F_VSW1_RUN_0_825000_V     (0x44U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.831250 V
 */
#define PF502X_F_VSW1_RUN_0_831250_V     (0x45U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.837500 V
 */
#define PF502X_F_VSW1_RUN_0_837500_V     (0x46U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.843750 V
 */
#define PF502X_F_VSW1_RUN_0_843750_V     (0x47U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.850000 V
 */
#define PF502X_F_VSW1_RUN_0_850000_V     (0x48U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.856250 V
 */
#define PF502X_F_VSW1_RUN_0_856250_V     (0x49U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.862500 V
 */
#define PF502X_F_VSW1_RUN_0_862500_V     (0x4AU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.868750 V
 */
#define PF502X_F_VSW1_RUN_0_868750_V     (0x4BU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.875000 V
 */
#define PF502X_F_VSW1_RUN_0_875000_V     (0x4CU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.881250 V
 */
#define PF502X_F_VSW1_RUN_0_881250_V     (0x4DU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.887500 V
 */
#define PF502X_F_VSW1_RUN_0_887500_V     (0x4EU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.893750 V
 */
#define PF502X_F_VSW1_RUN_0_893750_V     (0x4FU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.900000 V
 */
#define PF502X_F_VSW1_RUN_0_900000_V     (0x50U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.906250 V
 */
#define PF502X_F_VSW1_RUN_0_906250_V     (0x51U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.912500 V
 */
#define PF502X_F_VSW1_RUN_0_912500_V     (0x52U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.918750 V
 */
#define PF502X_F_VSW1_RUN_0_918750_V     (0x53U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.925000 V
 */
#define PF502X_F_VSW1_RUN_0_925000_V     (0x54U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.931250 V
 */
#define PF502X_F_VSW1_RUN_0_931250_V     (0x55U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.937500 V
 */
#define PF502X_F_VSW1_RUN_0_937500_V     (0x56U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.943750 V
 */
#define PF502X_F_VSW1_RUN_0_943750_V     (0x57U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.950000 V
 */
#define PF502X_F_VSW1_RUN_0_950000_V     (0x58U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.956250 V
 */
#define PF502X_F_VSW1_RUN_0_956250_V     (0x59U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.962500 V
 */
#define PF502X_F_VSW1_RUN_0_962500_V     (0x5AU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.968750 V
 */
#define PF502X_F_VSW1_RUN_0_968750_V     (0x5BU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.975000 V
 */
#define PF502X_F_VSW1_RUN_0_975000_V     (0x5CU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.981250 V
 */
#define PF502X_F_VSW1_RUN_0_981250_V     (0x5DU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.987500 V
 */
#define PF502X_F_VSW1_RUN_0_987500_V     (0x5EU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 0.993750 V
 */
#define PF502X_F_VSW1_RUN_0_993750_V     (0x5FU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.000000 V
 */
#define PF502X_F_VSW1_RUN_1_000000_V     (0x60U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.006250 V
 */
#define PF502X_F_VSW1_RUN_1_006250_V     (0x61U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.012500 V
 */
#define PF502X_F_VSW1_RUN_1_012500_V     (0x62U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.018750 V
 */
#define PF502X_F_VSW1_RUN_1_018750_V     (0x63U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.025000 V
 */
#define PF502X_F_VSW1_RUN_1_025000_V     (0x64U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.031250 V
 */
#define PF502X_F_VSW1_RUN_1_031250_V     (0x65U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.037500 V
 */
#define PF502X_F_VSW1_RUN_1_037500_V     (0x66U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.043750 V
 */
#define PF502X_F_VSW1_RUN_1_043750_V     (0x67U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.050000 V
 */
#define PF502X_F_VSW1_RUN_1_050000_V     (0x68U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.056250 V
 */
#define PF502X_F_VSW1_RUN_1_056250_V     (0x69U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.062500 V
 */
#define PF502X_F_VSW1_RUN_1_062500_V     (0x6AU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.068750 V
 */
#define PF502X_F_VSW1_RUN_1_068750_V     (0x6BU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.075000 V
 */
#define PF502X_F_VSW1_RUN_1_075000_V     (0x6CU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.081250 V
 */
#define PF502X_F_VSW1_RUN_1_081250_V     (0x6DU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.087500 V
 */
#define PF502X_F_VSW1_RUN_1_087500_V     (0x6EU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.093750 V
 */
#define PF502X_F_VSW1_RUN_1_093750_V     (0x6FU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.100000 V
 */
#define PF502X_F_VSW1_RUN_1_100000_V     (0x70U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.106250 V
 */
#define PF502X_F_VSW1_RUN_1_106250_V     (0x71U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.112500 V
 */
#define PF502X_F_VSW1_RUN_1_112500_V     (0x72U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.118750 V
 */
#define PF502X_F_VSW1_RUN_1_118750_V     (0x73U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.125000 V
 */
#define PF502X_F_VSW1_RUN_1_125000_V     (0x74U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.131250 V
 */
#define PF502X_F_VSW1_RUN_1_131250_V     (0x75U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.137500 V
 */
#define PF502X_F_VSW1_RUN_1_137500_V     (0x76U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.143750 V
 */
#define PF502X_F_VSW1_RUN_1_143750_V     (0x77U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.150000 V
 */
#define PF502X_F_VSW1_RUN_1_150000_V     (0x78U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.156250 V
 */
#define PF502X_F_VSW1_RUN_1_156250_V     (0x79U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.162500 V
 */
#define PF502X_F_VSW1_RUN_1_162500_V     (0x7AU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.168750 V
 */
#define PF502X_F_VSW1_RUN_1_168750_V     (0x7BU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.175000 V
 */
#define PF502X_F_VSW1_RUN_1_175000_V     (0x7CU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.181250 V
 */
#define PF502X_F_VSW1_RUN_1_181250_V     (0x7DU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.187500 V
 */
#define PF502X_F_VSW1_RUN_1_187500_V     (0x7EU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.193750 V
 */
#define PF502X_F_VSW1_RUN_1_193750_V     (0x7FU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.200000 V
 */
#define PF502X_F_VSW1_RUN_1_200000_V     (0x80U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.206250 V
 */
#define PF502X_F_VSW1_RUN_1_206250_V     (0x81U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.212500 V
 */
#define PF502X_F_VSW1_RUN_1_212500_V     (0x82U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.218750 V
 */
#define PF502X_F_VSW1_RUN_1_218750_V     (0x83U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.225000 V
 */
#define PF502X_F_VSW1_RUN_1_225000_V     (0x84U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.231250 V
 */
#define PF502X_F_VSW1_RUN_1_231250_V     (0x85U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.237500 V
 */
#define PF502X_F_VSW1_RUN_1_237500_V     (0x86U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.243750 V
 */
#define PF502X_F_VSW1_RUN_1_243750_V     (0x87U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.250000 V
 */
#define PF502X_F_VSW1_RUN_1_250000_V     (0x88U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.256250 V
 */
#define PF502X_F_VSW1_RUN_1_256250_V     (0x89U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.262500 V
 */
#define PF502X_F_VSW1_RUN_1_262500_V     (0x8AU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.268750 V
 */
#define PF502X_F_VSW1_RUN_1_268750_V     (0x8BU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.275000 V
 */
#define PF502X_F_VSW1_RUN_1_275000_V     (0x8CU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.281250 V
 */
#define PF502X_F_VSW1_RUN_1_281250_V     (0x8DU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.287500 V
 */
#define PF502X_F_VSW1_RUN_1_287500_V     (0x8EU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.293750 V
 */
#define PF502X_F_VSW1_RUN_1_293750_V     (0x8FU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.300000 V
 */
#define PF502X_F_VSW1_RUN_1_300000_V     (0x90U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.306250 V
 */
#define PF502X_F_VSW1_RUN_1_306250_V     (0x91U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.312500 V
 */
#define PF502X_F_VSW1_RUN_1_312500_V     (0x92U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.318750 V
 */
#define PF502X_F_VSW1_RUN_1_318750_V     (0x93U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.325000 V
 */
#define PF502X_F_VSW1_RUN_1_325000_V     (0x94U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.331250 V
 */
#define PF502X_F_VSW1_RUN_1_331250_V     (0x95U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.337500 V
 */
#define PF502X_F_VSW1_RUN_1_337500_V     (0x96U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.343750 V
 */
#define PF502X_F_VSW1_RUN_1_343750_V     (0x97U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.350000 V
 */
#define PF502X_F_VSW1_RUN_1_350000_V     (0x98U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.356250 V
 */
#define PF502X_F_VSW1_RUN_1_356250_V     (0x99U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.362500 V
 */
#define PF502X_F_VSW1_RUN_1_362500_V     (0x9AU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.368750 V
 */
#define PF502X_F_VSW1_RUN_1_368750_V     (0x9BU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.375000 V
 */
#define PF502X_F_VSW1_RUN_1_375000_V     (0x9CU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.381250 V
 */
#define PF502X_F_VSW1_RUN_1_381250_V     (0x9DU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.387500 V
 */
#define PF502X_F_VSW1_RUN_1_387500_V     (0x9EU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.393750 V
 */
#define PF502X_F_VSW1_RUN_1_393750_V     (0x9FU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.400000 V
 */
#define PF502X_F_VSW1_RUN_1_400000_V     (0xA0U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.406250 V
 */
#define PF502X_F_VSW1_RUN_1_406250_V     (0xA1U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.412500 V
 */
#define PF502X_F_VSW1_RUN_1_412500_V     (0xA2U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.418750 V
 */
#define PF502X_F_VSW1_RUN_1_418750_V     (0xA3U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.425000 V
 */
#define PF502X_F_VSW1_RUN_1_425000_V     (0xA4U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.431250 V
 */
#define PF502X_F_VSW1_RUN_1_431250_V     (0xA5U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.437500 V
 */
#define PF502X_F_VSW1_RUN_1_437500_V     (0xA6U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.443750 V
 */
#define PF502X_F_VSW1_RUN_1_443750_V     (0xA7U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.450000 V
 */
#define PF502X_F_VSW1_RUN_1_450000_V     (0xA8U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.456250 V
 */
#define PF502X_F_VSW1_RUN_1_456250_V     (0xA9U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.462500 V
 */
#define PF502X_F_VSW1_RUN_1_462500_V     (0xAAU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.468750 V
 */
#define PF502X_F_VSW1_RUN_1_468750_V     (0xABU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.475000 V
 */
#define PF502X_F_VSW1_RUN_1_475000_V     (0xACU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.481250 V
 */
#define PF502X_F_VSW1_RUN_1_481250_V     (0xADU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.487500 V
 */
#define PF502X_F_VSW1_RUN_1_487500_V     (0xAEU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.493750 V
 */
#define PF502X_F_VSW1_RUN_1_493750_V     (0xAFU << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.500000 V
 */
#define PF502X_F_VSW1_RUN_1_500000_V     (0xB0U << PF502X_F_VSW1_RUN_SHIFT)
/**
 * 1.80000 V
 */
#define PF502X_F_VSW1_RUN_1_80000_V      (0xB1U << PF502X_F_VSW1_RUN_SHIFT)

/******************************************************************************/
/* SW1_STBY_VOLT - Type: RW                                                   */
/******************************************************************************/

#define PF502X_SW1_STBY_VOLT_ADDR        0x4CU
#define PF502X_SW1_STBY_VOLT_DEFAULT     0x00U

/**
 * It uses the OTP_VSW1 to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW1_STBY_MASK          0xFFU

/**
 * It uses the OTP_VSW1 to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW1_STBY_SHIFT         0x00U

/**
 * 0.400000 V
 */
#define PF502X_F_VSW1_STBY_0_400000_V    (0x00U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.406250 V
 */
#define PF502X_F_VSW1_STBY_0_406250_V    (0x01U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.412500 V
 */
#define PF502X_F_VSW1_STBY_0_412500_V    (0x02U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.418750 V
 */
#define PF502X_F_VSW1_STBY_0_418750_V    (0x03U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.425000 V
 */
#define PF502X_F_VSW1_STBY_0_425000_V    (0x04U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.431250 V
 */
#define PF502X_F_VSW1_STBY_0_431250_V    (0x05U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.437500 V
 */
#define PF502X_F_VSW1_STBY_0_437500_V    (0x06U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.443750 V
 */
#define PF502X_F_VSW1_STBY_0_443750_V    (0x07U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.450000 V
 */
#define PF502X_F_VSW1_STBY_0_450000_V    (0x08U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.456250 V
 */
#define PF502X_F_VSW1_STBY_0_456250_V    (0x09U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.462500 V
 */
#define PF502X_F_VSW1_STBY_0_462500_V    (0x0AU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.468750 V
 */
#define PF502X_F_VSW1_STBY_0_468750_V    (0x0BU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.475000 V
 */
#define PF502X_F_VSW1_STBY_0_475000_V    (0x0CU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.481250 V
 */
#define PF502X_F_VSW1_STBY_0_481250_V    (0x0DU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.487500 V
 */
#define PF502X_F_VSW1_STBY_0_487500_V    (0x0EU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.493750 V
 */
#define PF502X_F_VSW1_STBY_0_493750_V    (0x0FU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.500000 V
 */
#define PF502X_F_VSW1_STBY_0_500000_V    (0x10U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.506250 V
 */
#define PF502X_F_VSW1_STBY_0_506250_V    (0x11U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.512500 V
 */
#define PF502X_F_VSW1_STBY_0_512500_V    (0x12U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.518750 V
 */
#define PF502X_F_VSW1_STBY_0_518750_V    (0x13U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.525000 V
 */
#define PF502X_F_VSW1_STBY_0_525000_V    (0x14U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.531250 V
 */
#define PF502X_F_VSW1_STBY_0_531250_V    (0x15U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.537500 V
 */
#define PF502X_F_VSW1_STBY_0_537500_V    (0x16U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.543750 V
 */
#define PF502X_F_VSW1_STBY_0_543750_V    (0x17U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.550000 V
 */
#define PF502X_F_VSW1_STBY_0_550000_V    (0x18U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.556250 V
 */
#define PF502X_F_VSW1_STBY_0_556250_V    (0x19U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.562500 V
 */
#define PF502X_F_VSW1_STBY_0_562500_V    (0x1AU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.568750 V
 */
#define PF502X_F_VSW1_STBY_0_568750_V    (0x1BU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.575000 V
 */
#define PF502X_F_VSW1_STBY_0_575000_V    (0x1CU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.581250 V
 */
#define PF502X_F_VSW1_STBY_0_581250_V    (0x1DU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.587500 V
 */
#define PF502X_F_VSW1_STBY_0_587500_V    (0x1EU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.593750 V
 */
#define PF502X_F_VSW1_STBY_0_593750_V    (0x1FU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.600000 V
 */
#define PF502X_F_VSW1_STBY_0_600000_V    (0x20U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.606250 V
 */
#define PF502X_F_VSW1_STBY_0_606250_V    (0x21U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.612500 V
 */
#define PF502X_F_VSW1_STBY_0_612500_V    (0x22U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.618750 V
 */
#define PF502X_F_VSW1_STBY_0_618750_V    (0x23U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.625000 V
 */
#define PF502X_F_VSW1_STBY_0_625000_V    (0x24U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.631250 V
 */
#define PF502X_F_VSW1_STBY_0_631250_V    (0x25U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.637500 V
 */
#define PF502X_F_VSW1_STBY_0_637500_V    (0x26U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.643750 V
 */
#define PF502X_F_VSW1_STBY_0_643750_V    (0x27U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.650000 V
 */
#define PF502X_F_VSW1_STBY_0_650000_V    (0x28U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.656250 V
 */
#define PF502X_F_VSW1_STBY_0_656250_V    (0x29U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.662500 V
 */
#define PF502X_F_VSW1_STBY_0_662500_V    (0x2AU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.668750 V
 */
#define PF502X_F_VSW1_STBY_0_668750_V    (0x2BU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.675000 V
 */
#define PF502X_F_VSW1_STBY_0_675000_V    (0x2CU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.681250 V
 */
#define PF502X_F_VSW1_STBY_0_681250_V    (0x2DU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.687500 V
 */
#define PF502X_F_VSW1_STBY_0_687500_V    (0x2EU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.693750 V
 */
#define PF502X_F_VSW1_STBY_0_693750_V    (0x2FU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.700000 V
 */
#define PF502X_F_VSW1_STBY_0_700000_V    (0x30U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.706250 V
 */
#define PF502X_F_VSW1_STBY_0_706250_V    (0x31U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.712500 V
 */
#define PF502X_F_VSW1_STBY_0_712500_V    (0x32U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.718750 V
 */
#define PF502X_F_VSW1_STBY_0_718750_V    (0x33U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.725000 V
 */
#define PF502X_F_VSW1_STBY_0_725000_V    (0x34U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.731250 V
 */
#define PF502X_F_VSW1_STBY_0_731250_V    (0x35U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.737500 V
 */
#define PF502X_F_VSW1_STBY_0_737500_V    (0x36U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.743750 V
 */
#define PF502X_F_VSW1_STBY_0_743750_V    (0x37U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.750000 V
 */
#define PF502X_F_VSW1_STBY_0_750000_V    (0x38U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.756250 V
 */
#define PF502X_F_VSW1_STBY_0_756250_V    (0x39U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.762500 V
 */
#define PF502X_F_VSW1_STBY_0_762500_V    (0x3AU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.768750 V
 */
#define PF502X_F_VSW1_STBY_0_768750_V    (0x3BU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.775000 V
 */
#define PF502X_F_VSW1_STBY_0_775000_V    (0x3CU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.781250 V
 */
#define PF502X_F_VSW1_STBY_0_781250_V    (0x3DU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.787500 V
 */
#define PF502X_F_VSW1_STBY_0_787500_V    (0x3EU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.793750 V
 */
#define PF502X_F_VSW1_STBY_0_793750_V    (0x3FU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.800000 V
 */
#define PF502X_F_VSW1_STBY_0_800000_V    (0x40U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.806250 V
 */
#define PF502X_F_VSW1_STBY_0_806250_V    (0x41U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.812500 V
 */
#define PF502X_F_VSW1_STBY_0_812500_V    (0x42U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.818750 V
 */
#define PF502X_F_VSW1_STBY_0_818750_V    (0x43U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.825000 V
 */
#define PF502X_F_VSW1_STBY_0_825000_V    (0x44U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.831250 V
 */
#define PF502X_F_VSW1_STBY_0_831250_V    (0x45U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.837500 V
 */
#define PF502X_F_VSW1_STBY_0_837500_V    (0x46U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.843750 V
 */
#define PF502X_F_VSW1_STBY_0_843750_V    (0x47U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.850000 V
 */
#define PF502X_F_VSW1_STBY_0_850000_V    (0x48U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.856250 V
 */
#define PF502X_F_VSW1_STBY_0_856250_V    (0x49U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.862500 V
 */
#define PF502X_F_VSW1_STBY_0_862500_V    (0x4AU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.868750 V
 */
#define PF502X_F_VSW1_STBY_0_868750_V    (0x4BU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.875000 V
 */
#define PF502X_F_VSW1_STBY_0_875000_V    (0x4CU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.881250 V
 */
#define PF502X_F_VSW1_STBY_0_881250_V    (0x4DU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.887500 V
 */
#define PF502X_F_VSW1_STBY_0_887500_V    (0x4EU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.893750 V
 */
#define PF502X_F_VSW1_STBY_0_893750_V    (0x4FU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.900000 V
 */
#define PF502X_F_VSW1_STBY_0_900000_V    (0x50U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.906250 V
 */
#define PF502X_F_VSW1_STBY_0_906250_V    (0x51U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.912500 V
 */
#define PF502X_F_VSW1_STBY_0_912500_V    (0x52U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.918750 V
 */
#define PF502X_F_VSW1_STBY_0_918750_V    (0x53U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.925000 V
 */
#define PF502X_F_VSW1_STBY_0_925000_V    (0x54U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.931250 V
 */
#define PF502X_F_VSW1_STBY_0_931250_V    (0x55U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.937500 V
 */
#define PF502X_F_VSW1_STBY_0_937500_V    (0x56U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.943750 V
 */
#define PF502X_F_VSW1_STBY_0_943750_V    (0x57U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.950000 V
 */
#define PF502X_F_VSW1_STBY_0_950000_V    (0x58U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.956250 V
 */
#define PF502X_F_VSW1_STBY_0_956250_V    (0x59U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.962500 V
 */
#define PF502X_F_VSW1_STBY_0_962500_V    (0x5AU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.968750 V
 */
#define PF502X_F_VSW1_STBY_0_968750_V    (0x5BU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.975000 V
 */
#define PF502X_F_VSW1_STBY_0_975000_V    (0x5CU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.981250 V
 */
#define PF502X_F_VSW1_STBY_0_981250_V    (0x5DU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.987500 V
 */
#define PF502X_F_VSW1_STBY_0_987500_V    (0x5EU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 0.993750 V
 */
#define PF502X_F_VSW1_STBY_0_993750_V    (0x5FU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.000000 V
 */
#define PF502X_F_VSW1_STBY_1_000000_V    (0x60U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.006250 V
 */
#define PF502X_F_VSW1_STBY_1_006250_V    (0x61U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.012500 V
 */
#define PF502X_F_VSW1_STBY_1_012500_V    (0x62U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.018750 V
 */
#define PF502X_F_VSW1_STBY_1_018750_V    (0x63U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.025000 V
 */
#define PF502X_F_VSW1_STBY_1_025000_V    (0x64U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.031250 V
 */
#define PF502X_F_VSW1_STBY_1_031250_V    (0x65U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.037500 V
 */
#define PF502X_F_VSW1_STBY_1_037500_V    (0x66U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.043750 V
 */
#define PF502X_F_VSW1_STBY_1_043750_V    (0x67U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.050000 V
 */
#define PF502X_F_VSW1_STBY_1_050000_V    (0x68U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.056250 V
 */
#define PF502X_F_VSW1_STBY_1_056250_V    (0x69U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.062500 V
 */
#define PF502X_F_VSW1_STBY_1_062500_V    (0x6AU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.068750 V
 */
#define PF502X_F_VSW1_STBY_1_068750_V    (0x6BU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.075000 V
 */
#define PF502X_F_VSW1_STBY_1_075000_V    (0x6CU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.081250 V
 */
#define PF502X_F_VSW1_STBY_1_081250_V    (0x6DU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.087500 V
 */
#define PF502X_F_VSW1_STBY_1_087500_V    (0x6EU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.093750 V
 */
#define PF502X_F_VSW1_STBY_1_093750_V    (0x6FU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.100000 V
 */
#define PF502X_F_VSW1_STBY_1_100000_V    (0x70U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.106250 V
 */
#define PF502X_F_VSW1_STBY_1_106250_V    (0x71U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.112500 V
 */
#define PF502X_F_VSW1_STBY_1_112500_V    (0x72U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.118750 V
 */
#define PF502X_F_VSW1_STBY_1_118750_V    (0x73U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.125000 V
 */
#define PF502X_F_VSW1_STBY_1_125000_V    (0x74U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.131250 V
 */
#define PF502X_F_VSW1_STBY_1_131250_V    (0x75U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.137500 V
 */
#define PF502X_F_VSW1_STBY_1_137500_V    (0x76U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.143750 V
 */
#define PF502X_F_VSW1_STBY_1_143750_V    (0x77U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.150000 V
 */
#define PF502X_F_VSW1_STBY_1_150000_V    (0x78U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.156250 V
 */
#define PF502X_F_VSW1_STBY_1_156250_V    (0x79U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.162500 V
 */
#define PF502X_F_VSW1_STBY_1_162500_V    (0x7AU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.168750 V
 */
#define PF502X_F_VSW1_STBY_1_168750_V    (0x7BU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.175000 V
 */
#define PF502X_F_VSW1_STBY_1_175000_V    (0x7CU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.181250 V
 */
#define PF502X_F_VSW1_STBY_1_181250_V    (0x7DU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.187500 V
 */
#define PF502X_F_VSW1_STBY_1_187500_V    (0x7EU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.193750 V
 */
#define PF502X_F_VSW1_STBY_1_193750_V    (0x7FU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.200000 V
 */
#define PF502X_F_VSW1_STBY_1_200000_V    (0x80U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.206250 V
 */
#define PF502X_F_VSW1_STBY_1_206250_V    (0x81U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.212500 V
 */
#define PF502X_F_VSW1_STBY_1_212500_V    (0x82U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.218750 V
 */
#define PF502X_F_VSW1_STBY_1_218750_V    (0x83U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.225000 V
 */
#define PF502X_F_VSW1_STBY_1_225000_V    (0x84U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.231250 V
 */
#define PF502X_F_VSW1_STBY_1_231250_V    (0x85U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.237500 V
 */
#define PF502X_F_VSW1_STBY_1_237500_V    (0x86U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.243750 V
 */
#define PF502X_F_VSW1_STBY_1_243750_V    (0x87U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.250000 V
 */
#define PF502X_F_VSW1_STBY_1_250000_V    (0x88U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.256250 V
 */
#define PF502X_F_VSW1_STBY_1_256250_V    (0x89U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.262500 V
 */
#define PF502X_F_VSW1_STBY_1_262500_V    (0x8AU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.268750 V
 */
#define PF502X_F_VSW1_STBY_1_268750_V    (0x8BU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.275000 V
 */
#define PF502X_F_VSW1_STBY_1_275000_V    (0x8CU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.281250 V
 */
#define PF502X_F_VSW1_STBY_1_281250_V    (0x8DU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.287500 V
 */
#define PF502X_F_VSW1_STBY_1_287500_V    (0x8EU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.293750 V
 */
#define PF502X_F_VSW1_STBY_1_293750_V    (0x8FU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.300000 V
 */
#define PF502X_F_VSW1_STBY_1_300000_V    (0x90U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.306250 V
 */
#define PF502X_F_VSW1_STBY_1_306250_V    (0x91U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.312500 V
 */
#define PF502X_F_VSW1_STBY_1_312500_V    (0x92U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.318750 V
 */
#define PF502X_F_VSW1_STBY_1_318750_V    (0x93U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.325000 V
 */
#define PF502X_F_VSW1_STBY_1_325000_V    (0x94U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.331250 V
 */
#define PF502X_F_VSW1_STBY_1_331250_V    (0x95U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.337500 V
 */
#define PF502X_F_VSW1_STBY_1_337500_V    (0x96U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.343750 V
 */
#define PF502X_F_VSW1_STBY_1_343750_V    (0x97U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.350000 V
 */
#define PF502X_F_VSW1_STBY_1_350000_V    (0x98U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.356250 V
 */
#define PF502X_F_VSW1_STBY_1_356250_V    (0x99U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.362500 V
 */
#define PF502X_F_VSW1_STBY_1_362500_V    (0x9AU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.368750 V
 */
#define PF502X_F_VSW1_STBY_1_368750_V    (0x9BU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.375000 V
 */
#define PF502X_F_VSW1_STBY_1_375000_V    (0x9CU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.381250 V
 */
#define PF502X_F_VSW1_STBY_1_381250_V    (0x9DU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.387500 V
 */
#define PF502X_F_VSW1_STBY_1_387500_V    (0x9EU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.393750 V
 */
#define PF502X_F_VSW1_STBY_1_393750_V    (0x9FU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.400000 V
 */
#define PF502X_F_VSW1_STBY_1_400000_V    (0xA0U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.406250 V
 */
#define PF502X_F_VSW1_STBY_1_406250_V    (0xA1U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.412500 V
 */
#define PF502X_F_VSW1_STBY_1_412500_V    (0xA2U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.418750 V
 */
#define PF502X_F_VSW1_STBY_1_418750_V    (0xA3U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.425000 V
 */
#define PF502X_F_VSW1_STBY_1_425000_V    (0xA4U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.431250 V
 */
#define PF502X_F_VSW1_STBY_1_431250_V    (0xA5U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.437500 V
 */
#define PF502X_F_VSW1_STBY_1_437500_V    (0xA6U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.443750 V
 */
#define PF502X_F_VSW1_STBY_1_443750_V    (0xA7U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.450000 V
 */
#define PF502X_F_VSW1_STBY_1_450000_V    (0xA8U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.456250 V
 */
#define PF502X_F_VSW1_STBY_1_456250_V    (0xA9U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.462500 V
 */
#define PF502X_F_VSW1_STBY_1_462500_V    (0xAAU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.468750 V
 */
#define PF502X_F_VSW1_STBY_1_468750_V    (0xABU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.475000 V
 */
#define PF502X_F_VSW1_STBY_1_475000_V    (0xACU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.481250 V
 */
#define PF502X_F_VSW1_STBY_1_481250_V    (0xADU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.487500 V
 */
#define PF502X_F_VSW1_STBY_1_487500_V    (0xAEU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.493750 V
 */
#define PF502X_F_VSW1_STBY_1_493750_V    (0xAFU << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.500000 V
 */
#define PF502X_F_VSW1_STBY_1_500000_V    (0xB0U << PF502X_F_VSW1_STBY_SHIFT)
/**
 * 1.80000 V
 */
#define PF502X_F_VSW1_STBY_1_80000_V     (0xB1U << PF502X_F_VSW1_STBY_SHIFT)

/******************************************************************************/
/* SW2_CONFIG1 - Type: RW                                                     */
/******************************************************************************/

#define PF502X_SW2_CONFIG1_ADDR          0x4FU
#define PF502X_SW2_CONFIG1_DEFAULT       0x1CU

/**
 * Allows SW2 regulator to control the PGOOD pin.
 */
#define PF502X_F_SW2_PG_EN_MASK          0x01U
/**
 * Enable Watchdog bypass for SW2 Regulator
 */
#define PF502X_F_SW2_WDBYPASS_MASK       0x02U
/**
 * Decides wherther SW2 Regulator remains enable or is disabled upon an ILIM Fault event
 */
#define PF502X_F_SW2_ILIM_STATE_MASK     0x04U
/**
 * Decides wherther SW2 Regulator remains enable or is disabled upon an OV Fault event
 */
#define PF502X_F_SW2_OV_STATE_MASK       0x08U
/**
 * Decides wherther SW2 Regulator remains enable or is disabled upon an UV Fault event
 */
#define PF502X_F_SW2_UV_STATE_MASK       0x10U
/**
 * Bypass the ILIM Fault event on SW2 Regulator
 */
#define PF502X_F_SW2_ILIM_BYPASS_MASK    0x20U
/**
 * Bypass the OV Fault event on SW2 Regulator
 */
#define PF502X_F_SW2_OV_BYPASS_MASK      0x40U
/**
 * Bypass the UV Fault event on SW2 Regulator
 */
#define PF502X_F_SW2_UV_BYPASS_MASK      0x80U

/**
 * Allows SW2 regulator to control the PGOOD pin.
 */
#define PF502X_F_SW2_PG_EN_SHIFT         0x00U
/**
 * Enable Watchdog bypass for SW2 Regulator
 */
#define PF502X_F_SW2_WDBYPASS_SHIFT      0x01U
/**
 * Decides wherther SW2 Regulator remains enable or is disabled upon an ILIM Fault event
 */
#define PF502X_F_SW2_ILIM_STATE_SHIFT    0x02U
/**
 * Decides wherther SW2 Regulator remains enable or is disabled upon an OV Fault event
 */
#define PF502X_F_SW2_OV_STATE_SHIFT      0x03U
/**
 * Decides wherther SW2 Regulator remains enable or is disabled upon an UV Fault event
 */
#define PF502X_F_SW2_UV_STATE_SHIFT      0x04U
/**
 * Bypass the ILIM Fault event on SW2 Regulator
 */
#define PF502X_F_SW2_ILIM_BYPASS_SHIFT   0x05U
/**
 * Bypass the OV Fault event on SW2 Regulator
 */
#define PF502X_F_SW2_OV_BYPASS_SHIFT     0x06U
/**
 * Bypass the UV Fault event on SW2 Regulator
 */
#define PF502X_F_SW2_UV_BYPASS_SHIFT     0x07U

/**
 * regulator is not able to set or clear the PGOOD pin
 */
#define PF502X_F_SW2_PG_EN_DISABLED      (0x00U << PF502X_F_SW2_PG_EN_SHIFT)
/**
 * Regulator's PG bit is part of the AND function to control PGOOD pin
 */
#define PF502X_F_SW2_PG_EN_ENABLED       (0x01U << PF502X_F_SW2_PG_EN_SHIFT)

/**
 * Regulator reacts upon a Watchdog
 */
#define PF502X_F_SW2_WDBYPASS_ENABLED    (0x00U << PF502X_F_SW2_WDBYPASS_SHIFT)
/**
 * Regulator bypass Watchdog event and keeps current configuration
 */
#define PF502X_F_SW2_WDBYPASS_BYPASS     (0x01U << PF502X_F_SW2_WDBYPASS_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW2_ILIM_STATE_DISABLED (0x00U << PF502X_F_SW2_ILIM_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW2_ILIM_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW2_ILIM_STATE_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW2_OV_STATE_DISABLED   (0x00U << PF502X_F_SW2_OV_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW2_OV_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW2_OV_STATE_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW2_UV_STATE_DISABLED   (0x00U << PF502X_F_SW2_UV_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW2_UV_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW2_UV_STATE_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW2_ILIM_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW2_ILIM_BYPASS_SHIFT)
/**
 * The Fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW2_ILIM_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW2_ILIM_BYPASS_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW2_OV_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW2_OV_BYPASS_SHIFT)
/**
 * The fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW2_OV_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW2_OV_BYPASS_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW2_UV_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW2_UV_BYPASS_SHIFT)
/**
 * The fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW2_UV_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW2_UV_BYPASS_SHIFT)

/******************************************************************************/
/* SW2_CONFIG2 - Type: RW                                                     */
/******************************************************************************/

#define PF502X_SW2_CONFIG2_ADDR          0x50U
#define PF502X_SW2_CONFIG2_DEFAULT       0x80U

/**
 * Set the Phase shift for SW2 Regulator
 */
#define PF502X_F_SW2PHASE_MASK           0x07U
/**
 * Set the current limit for SW2 Regulator
 */
#define PF502X_F_SW2ILIM_MASK            0x18U
/**
 * Set VTT mode
 */
#define PF502X_F_SW2_VTTEN_MASK          0x40U
/**
 * If SW2  is disabled upon a fault, this bit allow the regulator to re-enable when the fault condition is cleared.
 */
#define PF502X_F_SW2_FLT_REN_MASK        0x80U

/**
 * Set the Phase shift for SW2 Regulator
 */
#define PF502X_F_SW2PHASE_SHIFT          0x00U
/**
 * Set the current limit for SW2 Regulator
 */
#define PF502X_F_SW2ILIM_SHIFT           0x03U
/**
 * Set VTT mode
 */
#define PF502X_F_SW2_VTTEN_SHIFT         0x06U
/**
 * If SW2  is disabled upon a fault, this bit allow the regulator to re-enable when the fault condition is cleared.
 */
#define PF502X_F_SW2_FLT_REN_SHIFT       0x07U

/**
 * 45_
 */
#define PF502X_F_SW2PHASE_45_            (0x00U << PF502X_F_SW2PHASE_SHIFT)
/**
 * 90_
 */
#define PF502X_F_SW2PHASE_90_            (0x01U << PF502X_F_SW2PHASE_SHIFT)
/**
 * 135_
 */
#define PF502X_F_SW2PHASE_135_           (0x02U << PF502X_F_SW2PHASE_SHIFT)
/**
 * 180_
 */
#define PF502X_F_SW2PHASE_180_           (0x03U << PF502X_F_SW2PHASE_SHIFT)
/**
 * 225_
 */
#define PF502X_F_SW2PHASE_225_           (0x04U << PF502X_F_SW2PHASE_SHIFT)
/**
 * 270_
 */
#define PF502X_F_SW2PHASE_270_           (0x05U << PF502X_F_SW2PHASE_SHIFT)
/**
 * 315_
 */
#define PF502X_F_SW2PHASE_315_           (0x06U << PF502X_F_SW2PHASE_SHIFT)
/**
 * 0_
 */
#define PF502X_F_SW2PHASE_0_             (0x07U << PF502X_F_SW2PHASE_SHIFT)

/**
 * 2.1A
 */
#define PF502X_F_SW2ILIM_2_1A            (0x00U << PF502X_F_SW2ILIM_SHIFT)
/**
 * 2.6A
 */
#define PF502X_F_SW2ILIM_2_6A            (0x01U << PF502X_F_SW2ILIM_SHIFT)
/**
 * 3.0A
 */
#define PF502X_F_SW2ILIM_3_0A            (0x02U << PF502X_F_SW2ILIM_SHIFT)
/**
 * 4.5A
 */
#define PF502X_F_SW2ILIM_4_5A            (0x03U << PF502X_F_SW2ILIM_SHIFT)

/**
 * Disabled
 */
#define PF502X_F_SW2_VTTEN_DISABLED      (0x00U << PF502X_F_SW2_VTTEN_SHIFT)
/**
 * Enabled
 */
#define PF502X_F_SW2_VTTEN_ENABLED       (0x01U << PF502X_F_SW2_VTTEN_SHIFT)

/**
 * Regulator remains disabled upon clrearing the fault
 */
#define PF502X_F_SW2_FLT_REN_DISABLED    (0x00U << PF502X_F_SW2_FLT_REN_SHIFT)
/**
 * Regulator returns to its previous configuration.
 */
#define PF502X_F_SW2_FLT_REN_PREVIOUS_CONFIG_ (0x01U << PF502X_F_SW2_FLT_REN_SHIFT)

/******************************************************************************/
/* SW2_PWRUP - Type: RW                                                       */
/******************************************************************************/

#define PF502X_SW2_PWRUP_ADDR            0x51U
#define PF502X_SW2_PWRUP_DEFAULT         0x00U

/**
 * *Power Off Reset values to default OTP value.
 */
#define PF502X_F_SW2_SEQ_MASK            0xFFU

/**
 * *Power Off Reset values to default OTP value.
 */
#define PF502X_F_SW2_SEQ_SHIFT           0x00U

/******************************************************************************/
/* SW2_MODE1 - Type: RW                                                       */
/******************************************************************************/

#define PF502X_SW2_MODE1_ADDR            0x52U
#define PF502X_SW2_MODE1_DEFAULT         0x00U

/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW2_RUN_MODE_MASK       0x03U
/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW2_STBY_MODE_MASK      0x0CU
/**
 * Assign a Power Down group to SW2 Register.
 */
#define PF502X_F_SW2_PDGRP_MASK          0x30U

/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW2_RUN_MODE_SHIFT      0x00U
/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW2_STBY_MODE_SHIFT     0x02U
/**
 * Assign a Power Down group to SW2 Register.
 */
#define PF502X_F_SW2_PDGRP_SHIFT         0x04U

/**
 * OFF
 */
#define PF502X_F_SW2_RUN_MODE_OFF        (0x00U << PF502X_F_SW2_RUN_MODE_SHIFT)
/**
 * PWM
 */
#define PF502X_F_SW2_RUN_MODE_PWM        (0x01U << PF502X_F_SW2_RUN_MODE_SHIFT)
/**
 * PFM
 */
#define PF502X_F_SW2_RUN_MODE_PFM        (0x02U << PF502X_F_SW2_RUN_MODE_SHIFT)
/**
 * Auto Skip mode
 */
#define PF502X_F_SW2_RUN_MODE_AUTO_SKIP_MODE (0x03U << PF502X_F_SW2_RUN_MODE_SHIFT)

/**
 * OFF
 */
#define PF502X_F_SW2_STBY_MODE_OFF       (0x00U << PF502X_F_SW2_STBY_MODE_SHIFT)
/**
 * PWM
 */
#define PF502X_F_SW2_STBY_MODE_PWM       (0x01U << PF502X_F_SW2_STBY_MODE_SHIFT)
/**
 * PFM
 */
#define PF502X_F_SW2_STBY_MODE_PFM       (0x02U << PF502X_F_SW2_STBY_MODE_SHIFT)
/**
 * Auto Skip mode
 */
#define PF502X_F_SW2_STBY_MODE_AUTO_SKIP_MODE (0x03U << PF502X_F_SW2_STBY_MODE_SHIFT)

/**
 * Regulator is in Group 4 (turn of first)
 */
#define PF502X_F_SW2_PDGRP_GROUP_4       (0x00U << PF502X_F_SW2_PDGRP_SHIFT)
/**
 * Regulator is in Group 3
 */
#define PF502X_F_SW2_PDGRP_GROUP_3       (0x01U << PF502X_F_SW2_PDGRP_SHIFT)
/**
 * Regulator is in Group 2
 */
#define PF502X_F_SW2_PDGRP_GROUP_2       (0x02U << PF502X_F_SW2_PDGRP_SHIFT)
/**
 * Regulator is in Group 1 (turn off Last)
 */
#define PF502X_F_SW2_PDGRP_GROUP_1       (0x03U << PF502X_F_SW2_PDGRP_SHIFT)

/******************************************************************************/
/* SW2_RUN_VOLT - Type: RW                                                    */
/******************************************************************************/

#define PF502X_SW2_RUN_VOLT_ADDR         0x53U
#define PF502X_SW2_RUN_VOLT_DEFAULT      0x00U

/**
 * It uses the OTP_VSW2  to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW2_RUN_MASK           0xFFU

/**
 * It uses the OTP_VSW2  to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW2_RUN_SHIFT          0x00U

/**
 * 0.400000 V
 */
#define PF502X_F_VSW2_RUN_0_400000_V     (0x00U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.406250 V
 */
#define PF502X_F_VSW2_RUN_0_406250_V     (0x01U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.412500 V
 */
#define PF502X_F_VSW2_RUN_0_412500_V     (0x02U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.418750 V
 */
#define PF502X_F_VSW2_RUN_0_418750_V     (0x03U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.425000 V
 */
#define PF502X_F_VSW2_RUN_0_425000_V     (0x04U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.431250 V
 */
#define PF502X_F_VSW2_RUN_0_431250_V     (0x05U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.437500 V
 */
#define PF502X_F_VSW2_RUN_0_437500_V     (0x06U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.443750 V
 */
#define PF502X_F_VSW2_RUN_0_443750_V     (0x07U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.450000 V
 */
#define PF502X_F_VSW2_RUN_0_450000_V     (0x08U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.456250 V
 */
#define PF502X_F_VSW2_RUN_0_456250_V     (0x09U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.462500 V
 */
#define PF502X_F_VSW2_RUN_0_462500_V     (0x0AU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.468750 V
 */
#define PF502X_F_VSW2_RUN_0_468750_V     (0x0BU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.475000 V
 */
#define PF502X_F_VSW2_RUN_0_475000_V     (0x0CU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.481250 V
 */
#define PF502X_F_VSW2_RUN_0_481250_V     (0x0DU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.487500 V
 */
#define PF502X_F_VSW2_RUN_0_487500_V     (0x0EU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.493750 V
 */
#define PF502X_F_VSW2_RUN_0_493750_V     (0x0FU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.500000 V
 */
#define PF502X_F_VSW2_RUN_0_500000_V     (0x10U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.506250 V
 */
#define PF502X_F_VSW2_RUN_0_506250_V     (0x11U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.512500 V
 */
#define PF502X_F_VSW2_RUN_0_512500_V     (0x12U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.518750 V
 */
#define PF502X_F_VSW2_RUN_0_518750_V     (0x13U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.525000 V
 */
#define PF502X_F_VSW2_RUN_0_525000_V     (0x14U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.531250 V
 */
#define PF502X_F_VSW2_RUN_0_531250_V     (0x15U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.537500 V
 */
#define PF502X_F_VSW2_RUN_0_537500_V     (0x16U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.543750 V
 */
#define PF502X_F_VSW2_RUN_0_543750_V     (0x17U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.550000 V
 */
#define PF502X_F_VSW2_RUN_0_550000_V     (0x18U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.556250 V
 */
#define PF502X_F_VSW2_RUN_0_556250_V     (0x19U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.562500 V
 */
#define PF502X_F_VSW2_RUN_0_562500_V     (0x1AU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.568750 V
 */
#define PF502X_F_VSW2_RUN_0_568750_V     (0x1BU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.575000 V
 */
#define PF502X_F_VSW2_RUN_0_575000_V     (0x1CU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.581250 V
 */
#define PF502X_F_VSW2_RUN_0_581250_V     (0x1DU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.587500 V
 */
#define PF502X_F_VSW2_RUN_0_587500_V     (0x1EU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.593750 V
 */
#define PF502X_F_VSW2_RUN_0_593750_V     (0x1FU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.600000 V
 */
#define PF502X_F_VSW2_RUN_0_600000_V     (0x20U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.606250 V
 */
#define PF502X_F_VSW2_RUN_0_606250_V     (0x21U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.612500 V
 */
#define PF502X_F_VSW2_RUN_0_612500_V     (0x22U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.618750 V
 */
#define PF502X_F_VSW2_RUN_0_618750_V     (0x23U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.625000 V
 */
#define PF502X_F_VSW2_RUN_0_625000_V     (0x24U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.631250 V
 */
#define PF502X_F_VSW2_RUN_0_631250_V     (0x25U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.637500 V
 */
#define PF502X_F_VSW2_RUN_0_637500_V     (0x26U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.643750 V
 */
#define PF502X_F_VSW2_RUN_0_643750_V     (0x27U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.650000 V
 */
#define PF502X_F_VSW2_RUN_0_650000_V     (0x28U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.656250 V
 */
#define PF502X_F_VSW2_RUN_0_656250_V     (0x29U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.662500 V
 */
#define PF502X_F_VSW2_RUN_0_662500_V     (0x2AU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.668750 V
 */
#define PF502X_F_VSW2_RUN_0_668750_V     (0x2BU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.675000 V
 */
#define PF502X_F_VSW2_RUN_0_675000_V     (0x2CU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.681250 V
 */
#define PF502X_F_VSW2_RUN_0_681250_V     (0x2DU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.687500 V
 */
#define PF502X_F_VSW2_RUN_0_687500_V     (0x2EU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.693750 V
 */
#define PF502X_F_VSW2_RUN_0_693750_V     (0x2FU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.700000 V
 */
#define PF502X_F_VSW2_RUN_0_700000_V     (0x30U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.706250 V
 */
#define PF502X_F_VSW2_RUN_0_706250_V     (0x31U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.712500 V
 */
#define PF502X_F_VSW2_RUN_0_712500_V     (0x32U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.718750 V
 */
#define PF502X_F_VSW2_RUN_0_718750_V     (0x33U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.725000 V
 */
#define PF502X_F_VSW2_RUN_0_725000_V     (0x34U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.731250 V
 */
#define PF502X_F_VSW2_RUN_0_731250_V     (0x35U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.737500 V
 */
#define PF502X_F_VSW2_RUN_0_737500_V     (0x36U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.743750 V
 */
#define PF502X_F_VSW2_RUN_0_743750_V     (0x37U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.750000 V
 */
#define PF502X_F_VSW2_RUN_0_750000_V     (0x38U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.756250 V
 */
#define PF502X_F_VSW2_RUN_0_756250_V     (0x39U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.762500 V
 */
#define PF502X_F_VSW2_RUN_0_762500_V     (0x3AU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.768750 V
 */
#define PF502X_F_VSW2_RUN_0_768750_V     (0x3BU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.775000 V
 */
#define PF502X_F_VSW2_RUN_0_775000_V     (0x3CU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.781250 V
 */
#define PF502X_F_VSW2_RUN_0_781250_V     (0x3DU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.787500 V
 */
#define PF502X_F_VSW2_RUN_0_787500_V     (0x3EU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.793750 V
 */
#define PF502X_F_VSW2_RUN_0_793750_V     (0x3FU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.800000 V
 */
#define PF502X_F_VSW2_RUN_0_800000_V     (0x40U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.806250 V
 */
#define PF502X_F_VSW2_RUN_0_806250_V     (0x41U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.812500 V
 */
#define PF502X_F_VSW2_RUN_0_812500_V     (0x42U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.818750 V
 */
#define PF502X_F_VSW2_RUN_0_818750_V     (0x43U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.825000 V
 */
#define PF502X_F_VSW2_RUN_0_825000_V     (0x44U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.831250 V
 */
#define PF502X_F_VSW2_RUN_0_831250_V     (0x45U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.837500 V
 */
#define PF502X_F_VSW2_RUN_0_837500_V     (0x46U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.843750 V
 */
#define PF502X_F_VSW2_RUN_0_843750_V     (0x47U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.850000 V
 */
#define PF502X_F_VSW2_RUN_0_850000_V     (0x48U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.856250 V
 */
#define PF502X_F_VSW2_RUN_0_856250_V     (0x49U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.862500 V
 */
#define PF502X_F_VSW2_RUN_0_862500_V     (0x4AU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.868750 V
 */
#define PF502X_F_VSW2_RUN_0_868750_V     (0x4BU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.875000 V
 */
#define PF502X_F_VSW2_RUN_0_875000_V     (0x4CU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.881250 V
 */
#define PF502X_F_VSW2_RUN_0_881250_V     (0x4DU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.887500 V
 */
#define PF502X_F_VSW2_RUN_0_887500_V     (0x4EU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.893750 V
 */
#define PF502X_F_VSW2_RUN_0_893750_V     (0x4FU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.900000 V
 */
#define PF502X_F_VSW2_RUN_0_900000_V     (0x50U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.906250 V
 */
#define PF502X_F_VSW2_RUN_0_906250_V     (0x51U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.912500 V
 */
#define PF502X_F_VSW2_RUN_0_912500_V     (0x52U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.918750 V
 */
#define PF502X_F_VSW2_RUN_0_918750_V     (0x53U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.925000 V
 */
#define PF502X_F_VSW2_RUN_0_925000_V     (0x54U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.931250 V
 */
#define PF502X_F_VSW2_RUN_0_931250_V     (0x55U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.937500 V
 */
#define PF502X_F_VSW2_RUN_0_937500_V     (0x56U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.943750 V
 */
#define PF502X_F_VSW2_RUN_0_943750_V     (0x57U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.950000 V
 */
#define PF502X_F_VSW2_RUN_0_950000_V     (0x58U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.956250 V
 */
#define PF502X_F_VSW2_RUN_0_956250_V     (0x59U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.962500 V
 */
#define PF502X_F_VSW2_RUN_0_962500_V     (0x5AU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.968750 V
 */
#define PF502X_F_VSW2_RUN_0_968750_V     (0x5BU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.975000 V
 */
#define PF502X_F_VSW2_RUN_0_975000_V     (0x5CU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.981250 V
 */
#define PF502X_F_VSW2_RUN_0_981250_V     (0x5DU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.987500 V
 */
#define PF502X_F_VSW2_RUN_0_987500_V     (0x5EU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 0.993750 V
 */
#define PF502X_F_VSW2_RUN_0_993750_V     (0x5FU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.000000 V
 */
#define PF502X_F_VSW2_RUN_1_000000_V     (0x60U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.006250 V
 */
#define PF502X_F_VSW2_RUN_1_006250_V     (0x61U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.012500 V
 */
#define PF502X_F_VSW2_RUN_1_012500_V     (0x62U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.018750 V
 */
#define PF502X_F_VSW2_RUN_1_018750_V     (0x63U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.025000 V
 */
#define PF502X_F_VSW2_RUN_1_025000_V     (0x64U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.031250 V
 */
#define PF502X_F_VSW2_RUN_1_031250_V     (0x65U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.037500 V
 */
#define PF502X_F_VSW2_RUN_1_037500_V     (0x66U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.043750 V
 */
#define PF502X_F_VSW2_RUN_1_043750_V     (0x67U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.050000 V
 */
#define PF502X_F_VSW2_RUN_1_050000_V     (0x68U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.056250 V
 */
#define PF502X_F_VSW2_RUN_1_056250_V     (0x69U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.062500 V
 */
#define PF502X_F_VSW2_RUN_1_062500_V     (0x6AU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.068750 V
 */
#define PF502X_F_VSW2_RUN_1_068750_V     (0x6BU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.075000 V
 */
#define PF502X_F_VSW2_RUN_1_075000_V     (0x6CU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.081250 V
 */
#define PF502X_F_VSW2_RUN_1_081250_V     (0x6DU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.087500 V
 */
#define PF502X_F_VSW2_RUN_1_087500_V     (0x6EU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.093750 V
 */
#define PF502X_F_VSW2_RUN_1_093750_V     (0x6FU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.100000 V
 */
#define PF502X_F_VSW2_RUN_1_100000_V     (0x70U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.106250 V
 */
#define PF502X_F_VSW2_RUN_1_106250_V     (0x71U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.112500 V
 */
#define PF502X_F_VSW2_RUN_1_112500_V     (0x72U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.118750 V
 */
#define PF502X_F_VSW2_RUN_1_118750_V     (0x73U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.125000 V
 */
#define PF502X_F_VSW2_RUN_1_125000_V     (0x74U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.131250 V
 */
#define PF502X_F_VSW2_RUN_1_131250_V     (0x75U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.137500 V
 */
#define PF502X_F_VSW2_RUN_1_137500_V     (0x76U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.143750 V
 */
#define PF502X_F_VSW2_RUN_1_143750_V     (0x77U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.150000 V
 */
#define PF502X_F_VSW2_RUN_1_150000_V     (0x78U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.156250 V
 */
#define PF502X_F_VSW2_RUN_1_156250_V     (0x79U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.162500 V
 */
#define PF502X_F_VSW2_RUN_1_162500_V     (0x7AU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.168750 V
 */
#define PF502X_F_VSW2_RUN_1_168750_V     (0x7BU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.175000 V
 */
#define PF502X_F_VSW2_RUN_1_175000_V     (0x7CU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.181250 V
 */
#define PF502X_F_VSW2_RUN_1_181250_V     (0x7DU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.187500 V
 */
#define PF502X_F_VSW2_RUN_1_187500_V     (0x7EU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.193750 V
 */
#define PF502X_F_VSW2_RUN_1_193750_V     (0x7FU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.200000 V
 */
#define PF502X_F_VSW2_RUN_1_200000_V     (0x80U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.206250 V
 */
#define PF502X_F_VSW2_RUN_1_206250_V     (0x81U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.212500 V
 */
#define PF502X_F_VSW2_RUN_1_212500_V     (0x82U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.218750 V
 */
#define PF502X_F_VSW2_RUN_1_218750_V     (0x83U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.225000 V
 */
#define PF502X_F_VSW2_RUN_1_225000_V     (0x84U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.231250 V
 */
#define PF502X_F_VSW2_RUN_1_231250_V     (0x85U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.237500 V
 */
#define PF502X_F_VSW2_RUN_1_237500_V     (0x86U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.243750 V
 */
#define PF502X_F_VSW2_RUN_1_243750_V     (0x87U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.250000 V
 */
#define PF502X_F_VSW2_RUN_1_250000_V     (0x88U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.256250 V
 */
#define PF502X_F_VSW2_RUN_1_256250_V     (0x89U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.262500 V
 */
#define PF502X_F_VSW2_RUN_1_262500_V     (0x8AU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.268750 V
 */
#define PF502X_F_VSW2_RUN_1_268750_V     (0x8BU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.275000 V
 */
#define PF502X_F_VSW2_RUN_1_275000_V     (0x8CU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.281250 V
 */
#define PF502X_F_VSW2_RUN_1_281250_V     (0x8DU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.287500 V
 */
#define PF502X_F_VSW2_RUN_1_287500_V     (0x8EU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.293750 V
 */
#define PF502X_F_VSW2_RUN_1_293750_V     (0x8FU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.300000 V
 */
#define PF502X_F_VSW2_RUN_1_300000_V     (0x90U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.306250 V
 */
#define PF502X_F_VSW2_RUN_1_306250_V     (0x91U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.312500 V
 */
#define PF502X_F_VSW2_RUN_1_312500_V     (0x92U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.318750 V
 */
#define PF502X_F_VSW2_RUN_1_318750_V     (0x93U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.325000 V
 */
#define PF502X_F_VSW2_RUN_1_325000_V     (0x94U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.331250 V
 */
#define PF502X_F_VSW2_RUN_1_331250_V     (0x95U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.337500 V
 */
#define PF502X_F_VSW2_RUN_1_337500_V     (0x96U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.343750 V
 */
#define PF502X_F_VSW2_RUN_1_343750_V     (0x97U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.350000 V
 */
#define PF502X_F_VSW2_RUN_1_350000_V     (0x98U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.356250 V
 */
#define PF502X_F_VSW2_RUN_1_356250_V     (0x99U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.362500 V
 */
#define PF502X_F_VSW2_RUN_1_362500_V     (0x9AU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.368750 V
 */
#define PF502X_F_VSW2_RUN_1_368750_V     (0x9BU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.375000 V
 */
#define PF502X_F_VSW2_RUN_1_375000_V     (0x9CU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.381250 V
 */
#define PF502X_F_VSW2_RUN_1_381250_V     (0x9DU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.387500 V
 */
#define PF502X_F_VSW2_RUN_1_387500_V     (0x9EU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.393750 V
 */
#define PF502X_F_VSW2_RUN_1_393750_V     (0x9FU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.400000 V
 */
#define PF502X_F_VSW2_RUN_1_400000_V     (0xA0U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.406250 V
 */
#define PF502X_F_VSW2_RUN_1_406250_V     (0xA1U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.412500 V
 */
#define PF502X_F_VSW2_RUN_1_412500_V     (0xA2U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.418750 V
 */
#define PF502X_F_VSW2_RUN_1_418750_V     (0xA3U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.425000 V
 */
#define PF502X_F_VSW2_RUN_1_425000_V     (0xA4U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.431250 V
 */
#define PF502X_F_VSW2_RUN_1_431250_V     (0xA5U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.437500 V
 */
#define PF502X_F_VSW2_RUN_1_437500_V     (0xA6U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.443750 V
 */
#define PF502X_F_VSW2_RUN_1_443750_V     (0xA7U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.450000 V
 */
#define PF502X_F_VSW2_RUN_1_450000_V     (0xA8U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.456250 V
 */
#define PF502X_F_VSW2_RUN_1_456250_V     (0xA9U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.462500 V
 */
#define PF502X_F_VSW2_RUN_1_462500_V     (0xAAU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.468750 V
 */
#define PF502X_F_VSW2_RUN_1_468750_V     (0xABU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.475000 V
 */
#define PF502X_F_VSW2_RUN_1_475000_V     (0xACU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.481250 V
 */
#define PF502X_F_VSW2_RUN_1_481250_V     (0xADU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.487500 V
 */
#define PF502X_F_VSW2_RUN_1_487500_V     (0xAEU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.493750 V
 */
#define PF502X_F_VSW2_RUN_1_493750_V     (0xAFU << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.500000 V
 */
#define PF502X_F_VSW2_RUN_1_500000_V     (0xB0U << PF502X_F_VSW2_RUN_SHIFT)
/**
 * 1.80000 V
 */
#define PF502X_F_VSW2_RUN_1_80000_V      (0xB1U << PF502X_F_VSW2_RUN_SHIFT)

/******************************************************************************/
/* SW2_STBY_VOLT - Type: RW                                                   */
/******************************************************************************/

#define PF502X_SW2_STBY_VOLT_ADDR        0x54U
#define PF502X_SW2_STBY_VOLT_DEFAULT     0x00U

/**
 * It uses the OTP_VSW2 to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW2_STBY_MASK          0xFFU

/**
 * It uses the OTP_VSW2 to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW2_STBY_SHIFT         0x00U

/**
 * 0.400000 V
 */
#define PF502X_F_VSW2_STBY_0_400000_V    (0x00U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.406250 V
 */
#define PF502X_F_VSW2_STBY_0_406250_V    (0x01U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.412500 V
 */
#define PF502X_F_VSW2_STBY_0_412500_V    (0x02U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.418750 V
 */
#define PF502X_F_VSW2_STBY_0_418750_V    (0x03U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.425000 V
 */
#define PF502X_F_VSW2_STBY_0_425000_V    (0x04U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.431250 V
 */
#define PF502X_F_VSW2_STBY_0_431250_V    (0x05U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.437500 V
 */
#define PF502X_F_VSW2_STBY_0_437500_V    (0x06U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.443750 V
 */
#define PF502X_F_VSW2_STBY_0_443750_V    (0x07U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.450000 V
 */
#define PF502X_F_VSW2_STBY_0_450000_V    (0x08U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.456250 V
 */
#define PF502X_F_VSW2_STBY_0_456250_V    (0x09U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.462500 V
 */
#define PF502X_F_VSW2_STBY_0_462500_V    (0x0AU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.468750 V
 */
#define PF502X_F_VSW2_STBY_0_468750_V    (0x0BU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.475000 V
 */
#define PF502X_F_VSW2_STBY_0_475000_V    (0x0CU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.481250 V
 */
#define PF502X_F_VSW2_STBY_0_481250_V    (0x0DU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.487500 V
 */
#define PF502X_F_VSW2_STBY_0_487500_V    (0x0EU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.493750 V
 */
#define PF502X_F_VSW2_STBY_0_493750_V    (0x0FU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.500000 V
 */
#define PF502X_F_VSW2_STBY_0_500000_V    (0x10U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.506250 V
 */
#define PF502X_F_VSW2_STBY_0_506250_V    (0x11U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.512500 V
 */
#define PF502X_F_VSW2_STBY_0_512500_V    (0x12U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.518750 V
 */
#define PF502X_F_VSW2_STBY_0_518750_V    (0x13U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.525000 V
 */
#define PF502X_F_VSW2_STBY_0_525000_V    (0x14U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.531250 V
 */
#define PF502X_F_VSW2_STBY_0_531250_V    (0x15U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.537500 V
 */
#define PF502X_F_VSW2_STBY_0_537500_V    (0x16U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.543750 V
 */
#define PF502X_F_VSW2_STBY_0_543750_V    (0x17U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.550000 V
 */
#define PF502X_F_VSW2_STBY_0_550000_V    (0x18U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.556250 V
 */
#define PF502X_F_VSW2_STBY_0_556250_V    (0x19U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.562500 V
 */
#define PF502X_F_VSW2_STBY_0_562500_V    (0x1AU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.568750 V
 */
#define PF502X_F_VSW2_STBY_0_568750_V    (0x1BU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.575000 V
 */
#define PF502X_F_VSW2_STBY_0_575000_V    (0x1CU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.581250 V
 */
#define PF502X_F_VSW2_STBY_0_581250_V    (0x1DU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.587500 V
 */
#define PF502X_F_VSW2_STBY_0_587500_V    (0x1EU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.593750 V
 */
#define PF502X_F_VSW2_STBY_0_593750_V    (0x1FU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.600000 V
 */
#define PF502X_F_VSW2_STBY_0_600000_V    (0x20U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.606250 V
 */
#define PF502X_F_VSW2_STBY_0_606250_V    (0x21U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.612500 V
 */
#define PF502X_F_VSW2_STBY_0_612500_V    (0x22U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.618750 V
 */
#define PF502X_F_VSW2_STBY_0_618750_V    (0x23U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.625000 V
 */
#define PF502X_F_VSW2_STBY_0_625000_V    (0x24U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.631250 V
 */
#define PF502X_F_VSW2_STBY_0_631250_V    (0x25U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.637500 V
 */
#define PF502X_F_VSW2_STBY_0_637500_V    (0x26U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.643750 V
 */
#define PF502X_F_VSW2_STBY_0_643750_V    (0x27U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.650000 V
 */
#define PF502X_F_VSW2_STBY_0_650000_V    (0x28U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.656250 V
 */
#define PF502X_F_VSW2_STBY_0_656250_V    (0x29U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.662500 V
 */
#define PF502X_F_VSW2_STBY_0_662500_V    (0x2AU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.668750 V
 */
#define PF502X_F_VSW2_STBY_0_668750_V    (0x2BU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.675000 V
 */
#define PF502X_F_VSW2_STBY_0_675000_V    (0x2CU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.681250 V
 */
#define PF502X_F_VSW2_STBY_0_681250_V    (0x2DU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.687500 V
 */
#define PF502X_F_VSW2_STBY_0_687500_V    (0x2EU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.693750 V
 */
#define PF502X_F_VSW2_STBY_0_693750_V    (0x2FU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.700000 V
 */
#define PF502X_F_VSW2_STBY_0_700000_V    (0x30U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.706250 V
 */
#define PF502X_F_VSW2_STBY_0_706250_V    (0x31U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.712500 V
 */
#define PF502X_F_VSW2_STBY_0_712500_V    (0x32U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.718750 V
 */
#define PF502X_F_VSW2_STBY_0_718750_V    (0x33U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.725000 V
 */
#define PF502X_F_VSW2_STBY_0_725000_V    (0x34U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.731250 V
 */
#define PF502X_F_VSW2_STBY_0_731250_V    (0x35U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.737500 V
 */
#define PF502X_F_VSW2_STBY_0_737500_V    (0x36U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.743750 V
 */
#define PF502X_F_VSW2_STBY_0_743750_V    (0x37U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.750000 V
 */
#define PF502X_F_VSW2_STBY_0_750000_V    (0x38U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.756250 V
 */
#define PF502X_F_VSW2_STBY_0_756250_V    (0x39U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.762500 V
 */
#define PF502X_F_VSW2_STBY_0_762500_V    (0x3AU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.768750 V
 */
#define PF502X_F_VSW2_STBY_0_768750_V    (0x3BU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.775000 V
 */
#define PF502X_F_VSW2_STBY_0_775000_V    (0x3CU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.781250 V
 */
#define PF502X_F_VSW2_STBY_0_781250_V    (0x3DU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.787500 V
 */
#define PF502X_F_VSW2_STBY_0_787500_V    (0x3EU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.793750 V
 */
#define PF502X_F_VSW2_STBY_0_793750_V    (0x3FU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.800000 V
 */
#define PF502X_F_VSW2_STBY_0_800000_V    (0x40U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.806250 V
 */
#define PF502X_F_VSW2_STBY_0_806250_V    (0x41U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.812500 V
 */
#define PF502X_F_VSW2_STBY_0_812500_V    (0x42U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.818750 V
 */
#define PF502X_F_VSW2_STBY_0_818750_V    (0x43U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.825000 V
 */
#define PF502X_F_VSW2_STBY_0_825000_V    (0x44U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.831250 V
 */
#define PF502X_F_VSW2_STBY_0_831250_V    (0x45U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.837500 V
 */
#define PF502X_F_VSW2_STBY_0_837500_V    (0x46U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.843750 V
 */
#define PF502X_F_VSW2_STBY_0_843750_V    (0x47U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.850000 V
 */
#define PF502X_F_VSW2_STBY_0_850000_V    (0x48U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.856250 V
 */
#define PF502X_F_VSW2_STBY_0_856250_V    (0x49U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.862500 V
 */
#define PF502X_F_VSW2_STBY_0_862500_V    (0x4AU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.868750 V
 */
#define PF502X_F_VSW2_STBY_0_868750_V    (0x4BU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.875000 V
 */
#define PF502X_F_VSW2_STBY_0_875000_V    (0x4CU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.881250 V
 */
#define PF502X_F_VSW2_STBY_0_881250_V    (0x4DU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.887500 V
 */
#define PF502X_F_VSW2_STBY_0_887500_V    (0x4EU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.893750 V
 */
#define PF502X_F_VSW2_STBY_0_893750_V    (0x4FU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.900000 V
 */
#define PF502X_F_VSW2_STBY_0_900000_V    (0x50U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.906250 V
 */
#define PF502X_F_VSW2_STBY_0_906250_V    (0x51U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.912500 V
 */
#define PF502X_F_VSW2_STBY_0_912500_V    (0x52U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.918750 V
 */
#define PF502X_F_VSW2_STBY_0_918750_V    (0x53U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.925000 V
 */
#define PF502X_F_VSW2_STBY_0_925000_V    (0x54U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.931250 V
 */
#define PF502X_F_VSW2_STBY_0_931250_V    (0x55U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.937500 V
 */
#define PF502X_F_VSW2_STBY_0_937500_V    (0x56U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.943750 V
 */
#define PF502X_F_VSW2_STBY_0_943750_V    (0x57U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.950000 V
 */
#define PF502X_F_VSW2_STBY_0_950000_V    (0x58U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.956250 V
 */
#define PF502X_F_VSW2_STBY_0_956250_V    (0x59U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.962500 V
 */
#define PF502X_F_VSW2_STBY_0_962500_V    (0x5AU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.968750 V
 */
#define PF502X_F_VSW2_STBY_0_968750_V    (0x5BU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.975000 V
 */
#define PF502X_F_VSW2_STBY_0_975000_V    (0x5CU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.981250 V
 */
#define PF502X_F_VSW2_STBY_0_981250_V    (0x5DU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.987500 V
 */
#define PF502X_F_VSW2_STBY_0_987500_V    (0x5EU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 0.993750 V
 */
#define PF502X_F_VSW2_STBY_0_993750_V    (0x5FU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.000000 V
 */
#define PF502X_F_VSW2_STBY_1_000000_V    (0x60U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.006250 V
 */
#define PF502X_F_VSW2_STBY_1_006250_V    (0x61U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.012500 V
 */
#define PF502X_F_VSW2_STBY_1_012500_V    (0x62U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.018750 V
 */
#define PF502X_F_VSW2_STBY_1_018750_V    (0x63U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.025000 V
 */
#define PF502X_F_VSW2_STBY_1_025000_V    (0x64U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.031250 V
 */
#define PF502X_F_VSW2_STBY_1_031250_V    (0x65U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.037500 V
 */
#define PF502X_F_VSW2_STBY_1_037500_V    (0x66U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.043750 V
 */
#define PF502X_F_VSW2_STBY_1_043750_V    (0x67U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.050000 V
 */
#define PF502X_F_VSW2_STBY_1_050000_V    (0x68U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.056250 V
 */
#define PF502X_F_VSW2_STBY_1_056250_V    (0x69U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.062500 V
 */
#define PF502X_F_VSW2_STBY_1_062500_V    (0x6AU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.068750 V
 */
#define PF502X_F_VSW2_STBY_1_068750_V    (0x6BU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.075000 V
 */
#define PF502X_F_VSW2_STBY_1_075000_V    (0x6CU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.081250 V
 */
#define PF502X_F_VSW2_STBY_1_081250_V    (0x6DU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.087500 V
 */
#define PF502X_F_VSW2_STBY_1_087500_V    (0x6EU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.093750 V
 */
#define PF502X_F_VSW2_STBY_1_093750_V    (0x6FU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.100000 V
 */
#define PF502X_F_VSW2_STBY_1_100000_V    (0x70U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.106250 V
 */
#define PF502X_F_VSW2_STBY_1_106250_V    (0x71U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.112500 V
 */
#define PF502X_F_VSW2_STBY_1_112500_V    (0x72U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.118750 V
 */
#define PF502X_F_VSW2_STBY_1_118750_V    (0x73U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.125000 V
 */
#define PF502X_F_VSW2_STBY_1_125000_V    (0x74U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.131250 V
 */
#define PF502X_F_VSW2_STBY_1_131250_V    (0x75U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.137500 V
 */
#define PF502X_F_VSW2_STBY_1_137500_V    (0x76U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.143750 V
 */
#define PF502X_F_VSW2_STBY_1_143750_V    (0x77U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.150000 V
 */
#define PF502X_F_VSW2_STBY_1_150000_V    (0x78U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.156250 V
 */
#define PF502X_F_VSW2_STBY_1_156250_V    (0x79U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.162500 V
 */
#define PF502X_F_VSW2_STBY_1_162500_V    (0x7AU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.168750 V
 */
#define PF502X_F_VSW2_STBY_1_168750_V    (0x7BU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.175000 V
 */
#define PF502X_F_VSW2_STBY_1_175000_V    (0x7CU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.181250 V
 */
#define PF502X_F_VSW2_STBY_1_181250_V    (0x7DU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.187500 V
 */
#define PF502X_F_VSW2_STBY_1_187500_V    (0x7EU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.193750 V
 */
#define PF502X_F_VSW2_STBY_1_193750_V    (0x7FU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.200000 V
 */
#define PF502X_F_VSW2_STBY_1_200000_V    (0x80U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.206250 V
 */
#define PF502X_F_VSW2_STBY_1_206250_V    (0x81U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.212500 V
 */
#define PF502X_F_VSW2_STBY_1_212500_V    (0x82U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.218750 V
 */
#define PF502X_F_VSW2_STBY_1_218750_V    (0x83U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.225000 V
 */
#define PF502X_F_VSW2_STBY_1_225000_V    (0x84U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.231250 V
 */
#define PF502X_F_VSW2_STBY_1_231250_V    (0x85U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.237500 V
 */
#define PF502X_F_VSW2_STBY_1_237500_V    (0x86U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.243750 V
 */
#define PF502X_F_VSW2_STBY_1_243750_V    (0x87U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.250000 V
 */
#define PF502X_F_VSW2_STBY_1_250000_V    (0x88U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.256250 V
 */
#define PF502X_F_VSW2_STBY_1_256250_V    (0x89U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.262500 V
 */
#define PF502X_F_VSW2_STBY_1_262500_V    (0x8AU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.268750 V
 */
#define PF502X_F_VSW2_STBY_1_268750_V    (0x8BU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.275000 V
 */
#define PF502X_F_VSW2_STBY_1_275000_V    (0x8CU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.281250 V
 */
#define PF502X_F_VSW2_STBY_1_281250_V    (0x8DU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.287500 V
 */
#define PF502X_F_VSW2_STBY_1_287500_V    (0x8EU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.293750 V
 */
#define PF502X_F_VSW2_STBY_1_293750_V    (0x8FU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.300000 V
 */
#define PF502X_F_VSW2_STBY_1_300000_V    (0x90U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.306250 V
 */
#define PF502X_F_VSW2_STBY_1_306250_V    (0x91U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.312500 V
 */
#define PF502X_F_VSW2_STBY_1_312500_V    (0x92U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.318750 V
 */
#define PF502X_F_VSW2_STBY_1_318750_V    (0x93U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.325000 V
 */
#define PF502X_F_VSW2_STBY_1_325000_V    (0x94U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.331250 V
 */
#define PF502X_F_VSW2_STBY_1_331250_V    (0x95U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.337500 V
 */
#define PF502X_F_VSW2_STBY_1_337500_V    (0x96U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.343750 V
 */
#define PF502X_F_VSW2_STBY_1_343750_V    (0x97U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.350000 V
 */
#define PF502X_F_VSW2_STBY_1_350000_V    (0x98U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.356250 V
 */
#define PF502X_F_VSW2_STBY_1_356250_V    (0x99U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.362500 V
 */
#define PF502X_F_VSW2_STBY_1_362500_V    (0x9AU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.368750 V
 */
#define PF502X_F_VSW2_STBY_1_368750_V    (0x9BU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.375000 V
 */
#define PF502X_F_VSW2_STBY_1_375000_V    (0x9CU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.381250 V
 */
#define PF502X_F_VSW2_STBY_1_381250_V    (0x9DU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.387500 V
 */
#define PF502X_F_VSW2_STBY_1_387500_V    (0x9EU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.393750 V
 */
#define PF502X_F_VSW2_STBY_1_393750_V    (0x9FU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.400000 V
 */
#define PF502X_F_VSW2_STBY_1_400000_V    (0xA0U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.406250 V
 */
#define PF502X_F_VSW2_STBY_1_406250_V    (0xA1U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.412500 V
 */
#define PF502X_F_VSW2_STBY_1_412500_V    (0xA2U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.418750 V
 */
#define PF502X_F_VSW2_STBY_1_418750_V    (0xA3U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.425000 V
 */
#define PF502X_F_VSW2_STBY_1_425000_V    (0xA4U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.431250 V
 */
#define PF502X_F_VSW2_STBY_1_431250_V    (0xA5U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.437500 V
 */
#define PF502X_F_VSW2_STBY_1_437500_V    (0xA6U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.443750 V
 */
#define PF502X_F_VSW2_STBY_1_443750_V    (0xA7U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.450000 V
 */
#define PF502X_F_VSW2_STBY_1_450000_V    (0xA8U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.456250 V
 */
#define PF502X_F_VSW2_STBY_1_456250_V    (0xA9U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.462500 V
 */
#define PF502X_F_VSW2_STBY_1_462500_V    (0xAAU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.468750 V
 */
#define PF502X_F_VSW2_STBY_1_468750_V    (0xABU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.475000 V
 */
#define PF502X_F_VSW2_STBY_1_475000_V    (0xACU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.481250 V
 */
#define PF502X_F_VSW2_STBY_1_481250_V    (0xADU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.487500 V
 */
#define PF502X_F_VSW2_STBY_1_487500_V    (0xAEU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.493750 V
 */
#define PF502X_F_VSW2_STBY_1_493750_V    (0xAFU << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.500000 V
 */
#define PF502X_F_VSW2_STBY_1_500000_V    (0xB0U << PF502X_F_VSW2_STBY_SHIFT)
/**
 * 1.80000 V
 */
#define PF502X_F_VSW2_STBY_1_80000_V     (0xB1U << PF502X_F_VSW2_STBY_SHIFT)

/******************************************************************************/
/* SW3_CONFIG1 - Type: RW                                                     */
/******************************************************************************/

#define PF502X_SW3_CONFIG1_ADDR          0x57U
#define PF502X_SW3_CONFIG1_DEFAULT       0x1CU

/**
 * Allows SW3 regulator to control the PGOOD pin.
 */
#define PF502X_F_SW3_PG_EN_MASK          0x01U
/**
 * Enable Watchdog bypass for SW3 Regulator
 */
#define PF502X_F_SW3_WDBYPASS_MASK       0x02U
/**
 * Decides wherther SW3 Regulator remains enable or is disabled upon an ILIM Fault event
 */
#define PF502X_F_SW3_ILIM_STATE_MASK     0x04U
/**
 * Decides wherther SW3 Regulator remains enable or is disabled upon an OV Fault event
 */
#define PF502X_F_SW3_OV_STATE_MASK       0x08U
/**
 * Decides wherther SW3 Regulator remains enable or is disabled upon an UV Fault event
 */
#define PF502X_F_SW3_UV_STATE_MASK       0x10U
/**
 * Bypass the ILIM Fault event on SW3 Regulator
 */
#define PF502X_F_SW3_ILIM_BYPASS_MASK    0x20U
/**
 * Bypass the OV Fault event on SW3 Regulator
 */
#define PF502X_F_SW3_OV_BYPASS_MASK      0x40U
/**
 * Bypass the UV Fault event on SW3 Regulator
 */
#define PF502X_F_SW3_UV_BYPASS_MASK      0x80U

/**
 * Allows SW3 regulator to control the PGOOD pin.
 */
#define PF502X_F_SW3_PG_EN_SHIFT         0x00U
/**
 * Enable Watchdog bypass for SW3 Regulator
 */
#define PF502X_F_SW3_WDBYPASS_SHIFT      0x01U
/**
 * Decides wherther SW3 Regulator remains enable or is disabled upon an ILIM Fault event
 */
#define PF502X_F_SW3_ILIM_STATE_SHIFT    0x02U
/**
 * Decides wherther SW3 Regulator remains enable or is disabled upon an OV Fault event
 */
#define PF502X_F_SW3_OV_STATE_SHIFT      0x03U
/**
 * Decides wherther SW3 Regulator remains enable or is disabled upon an UV Fault event
 */
#define PF502X_F_SW3_UV_STATE_SHIFT      0x04U
/**
 * Bypass the ILIM Fault event on SW3 Regulator
 */
#define PF502X_F_SW3_ILIM_BYPASS_SHIFT   0x05U
/**
 * Bypass the OV Fault event on SW3 Regulator
 */
#define PF502X_F_SW3_OV_BYPASS_SHIFT     0x06U
/**
 * Bypass the UV Fault event on SW3 Regulator
 */
#define PF502X_F_SW3_UV_BYPASS_SHIFT     0x07U

/**
 * regulator is not able to set or clear the PGOOD pin
 */
#define PF502X_F_SW3_PG_EN_DISABLED      (0x00U << PF502X_F_SW3_PG_EN_SHIFT)
/**
 * Regulator's PG bit is part of the AND function to control PGOOD pin
 */
#define PF502X_F_SW3_PG_EN_ENABLED       (0x01U << PF502X_F_SW3_PG_EN_SHIFT)

/**
 * Regulator reacts upon a Watchdog
 */
#define PF502X_F_SW3_WDBYPASS_ENABLED    (0x00U << PF502X_F_SW3_WDBYPASS_SHIFT)
/**
 * Regulator bypass Watchdog event and keeps current configuration
 */
#define PF502X_F_SW3_WDBYPASS_BYPASS     (0x01U << PF502X_F_SW3_WDBYPASS_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW3_ILIM_STATE_DISABLED (0x00U << PF502X_F_SW3_ILIM_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW3_ILIM_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW3_ILIM_STATE_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW3_OV_STATE_DISABLED   (0x00U << PF502X_F_SW3_OV_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW3_OV_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW3_OV_STATE_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW3_UV_STATE_DISABLED   (0x00U << PF502X_F_SW3_UV_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW3_UV_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW3_UV_STATE_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW3_ILIM_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW3_ILIM_BYPASS_SHIFT)
/**
 * The Fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW3_ILIM_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW3_ILIM_BYPASS_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW3_OV_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW3_OV_BYPASS_SHIFT)
/**
 * The fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW3_OV_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW3_OV_BYPASS_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW3_UV_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW3_UV_BYPASS_SHIFT)
/**
 * The fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW3_UV_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW3_UV_BYPASS_SHIFT)

/******************************************************************************/
/* SW3_CONFIG2 - Type: RW                                                     */
/******************************************************************************/

#define PF502X_SW3_CONFIG2_ADDR          0x58U
#define PF502X_SW3_CONFIG2_DEFAULT       0x80U

/**
 * Set the Phase shift for SW3 Regulator
 */
#define PF502X_F_SW3PHASE_MASK           0x07U
/**
 * Set the current limit for SW3 Regulator
 */
#define PF502X_F_SW3ILIM_MASK            0x18U
/**
 * If SW3  is disabled upon a fault, this bit allow the regulator to re-enable when the fault condition is cleared.
 */
#define PF502X_F_SW3_FLT_REN_MASK        0x80U

/**
 * Set the Phase shift for SW3 Regulator
 */
#define PF502X_F_SW3PHASE_SHIFT          0x00U
/**
 * Set the current limit for SW3 Regulator
 */
#define PF502X_F_SW3ILIM_SHIFT           0x03U
/**
 * If SW3  is disabled upon a fault, this bit allow the regulator to re-enable when the fault condition is cleared.
 */
#define PF502X_F_SW3_FLT_REN_SHIFT       0x07U

/**
 * 45_
 */
#define PF502X_F_SW3PHASE_45_            (0x00U << PF502X_F_SW3PHASE_SHIFT)
/**
 * 90_
 */
#define PF502X_F_SW3PHASE_90_            (0x01U << PF502X_F_SW3PHASE_SHIFT)
/**
 * 135_
 */
#define PF502X_F_SW3PHASE_135_           (0x02U << PF502X_F_SW3PHASE_SHIFT)
/**
 * 180_
 */
#define PF502X_F_SW3PHASE_180_           (0x03U << PF502X_F_SW3PHASE_SHIFT)
/**
 * 225_
 */
#define PF502X_F_SW3PHASE_225_           (0x04U << PF502X_F_SW3PHASE_SHIFT)
/**
 * 270_
 */
#define PF502X_F_SW3PHASE_270_           (0x05U << PF502X_F_SW3PHASE_SHIFT)
/**
 * 315_
 */
#define PF502X_F_SW3PHASE_315_           (0x06U << PF502X_F_SW3PHASE_SHIFT)
/**
 * 0_
 */
#define PF502X_F_SW3PHASE_0_             (0x07U << PF502X_F_SW3PHASE_SHIFT)

/**
 * 2.1A
 */
#define PF502X_F_SW3ILIM_2_1_A           (0x00U << PF502X_F_SW3ILIM_SHIFT)
/**
 * 2.6A
 */
#define PF502X_F_SW3ILIM_2_6_A           (0x01U << PF502X_F_SW3ILIM_SHIFT)
/**
 * 3.0A
 */
#define PF502X_F_SW3ILIM_3_0_A           (0x02U << PF502X_F_SW3ILIM_SHIFT)
/**
 * 4.5A
 */
#define PF502X_F_SW3ILIM_4_5_A           (0x03U << PF502X_F_SW3ILIM_SHIFT)

/**
 * Regulator remains disabled upon clrearing the fault
 */
#define PF502X_F_SW3_FLT_REN_DISABLED    (0x00U << PF502X_F_SW3_FLT_REN_SHIFT)
/**
 * Regulator returns to its previous configuration.
 */
#define PF502X_F_SW3_FLT_REN_PREVIOUS_CONFIG_ (0x01U << PF502X_F_SW3_FLT_REN_SHIFT)

/******************************************************************************/
/* SW3_PWRUP - Type: RW                                                       */
/******************************************************************************/

#define PF502X_SW3_PWRUP_ADDR            0x59U
#define PF502X_SW3_PWRUP_DEFAULT         0x00U

/**
 * *Power Off Reset values to default OTP value.
 */
#define PF502X_F_SW3_SEQ_MASK            0xFFU

/**
 * *Power Off Reset values to default OTP value.
 */
#define PF502X_F_SW3_SEQ_SHIFT           0x00U

/******************************************************************************/
/* SW3_MODE1 - Type: RW                                                       */
/******************************************************************************/

#define PF502X_SW3_MODE1_ADDR            0x5AU
#define PF502X_SW3_MODE1_DEFAULT         0x00U

/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW3_RUN_MODE_MASK       0x03U
/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW3_STBY_MODE_MASK      0x0CU
/**
 * Assign a Power Down group to SW3 Register.
 */
#define PF502X_F_SW3_PDGRP_MASK          0x30U

/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW3_RUN_MODE_SHIFT      0x00U
/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW3_STBY_MODE_SHIFT     0x02U
/**
 * Assign a Power Down group to SW3 Register.
 */
#define PF502X_F_SW3_PDGRP_SHIFT         0x04U

/**
 * OFF
 */
#define PF502X_F_SW3_RUN_MODE_OFF        (0x00U << PF502X_F_SW3_RUN_MODE_SHIFT)
/**
 * PWM
 */
#define PF502X_F_SW3_RUN_MODE_PWM        (0x01U << PF502X_F_SW3_RUN_MODE_SHIFT)
/**
 * PFM
 */
#define PF502X_F_SW3_RUN_MODE_PFM        (0x02U << PF502X_F_SW3_RUN_MODE_SHIFT)
/**
 * Auto Skip mode
 */
#define PF502X_F_SW3_RUN_MODE_AUTO_SKIP_MODE (0x03U << PF502X_F_SW3_RUN_MODE_SHIFT)

/**
 * OFF
 */
#define PF502X_F_SW3_STBY_MODE_OFF       (0x00U << PF502X_F_SW3_STBY_MODE_SHIFT)
/**
 * PWM
 */
#define PF502X_F_SW3_STBY_MODE_PWM       (0x01U << PF502X_F_SW3_STBY_MODE_SHIFT)
/**
 * PFM
 */
#define PF502X_F_SW3_STBY_MODE_PFM       (0x02U << PF502X_F_SW3_STBY_MODE_SHIFT)
/**
 * Auto Skip mode
 */
#define PF502X_F_SW3_STBY_MODE_AUTO_SKIP_MODE (0x03U << PF502X_F_SW3_STBY_MODE_SHIFT)

/**
 * Regulator is in Group 4 (turn of first)
 */
#define PF502X_F_SW3_PDGRP_GROUP_4       (0x00U << PF502X_F_SW3_PDGRP_SHIFT)
/**
 * Regulator is in Group 3
 */
#define PF502X_F_SW3_PDGRP_GROUP_3       (0x01U << PF502X_F_SW3_PDGRP_SHIFT)
/**
 * Regulator is in Group 2
 */
#define PF502X_F_SW3_PDGRP_GROUP_2       (0x02U << PF502X_F_SW3_PDGRP_SHIFT)
/**
 * Regulator is in Group 1 (turn off Last)
 */
#define PF502X_F_SW3_PDGRP_GROUP_1       (0x03U << PF502X_F_SW3_PDGRP_SHIFT)

/******************************************************************************/
/* SW3_RUN_VOLT - Type: RW                                                    */
/******************************************************************************/

#define PF502X_SW3_RUN_VOLT_ADDR         0x5BU
#define PF502X_SW3_RUN_VOLT_DEFAULT      0x00U

/**
 * It uses the OTP_VSW3  to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW3_RUN_MASK           0xFFU

/**
 * It uses the OTP_VSW3  to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW3_RUN_SHIFT          0x00U

/**
 * 0.400000 V
 */
#define PF502X_F_VSW3_RUN_0_400000_V     (0x00U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.406250 V
 */
#define PF502X_F_VSW3_RUN_0_406250_V     (0x01U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.412500 V
 */
#define PF502X_F_VSW3_RUN_0_412500_V     (0x02U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.418750 V
 */
#define PF502X_F_VSW3_RUN_0_418750_V     (0x03U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.425000 V
 */
#define PF502X_F_VSW3_RUN_0_425000_V     (0x04U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.431250 V
 */
#define PF502X_F_VSW3_RUN_0_431250_V     (0x05U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.437500 V
 */
#define PF502X_F_VSW3_RUN_0_437500_V     (0x06U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.443750 V
 */
#define PF502X_F_VSW3_RUN_0_443750_V     (0x07U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.450000 V
 */
#define PF502X_F_VSW3_RUN_0_450000_V     (0x08U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.456250 V
 */
#define PF502X_F_VSW3_RUN_0_456250_V     (0x09U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.462500 V
 */
#define PF502X_F_VSW3_RUN_0_462500_V     (0x0AU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.468750 V
 */
#define PF502X_F_VSW3_RUN_0_468750_V     (0x0BU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.475000 V
 */
#define PF502X_F_VSW3_RUN_0_475000_V     (0x0CU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.481250 V
 */
#define PF502X_F_VSW3_RUN_0_481250_V     (0x0DU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.487500 V
 */
#define PF502X_F_VSW3_RUN_0_487500_V     (0x0EU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.493750 V
 */
#define PF502X_F_VSW3_RUN_0_493750_V     (0x0FU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.500000 V
 */
#define PF502X_F_VSW3_RUN_0_500000_V     (0x10U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.506250 V
 */
#define PF502X_F_VSW3_RUN_0_506250_V     (0x11U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.512500 V
 */
#define PF502X_F_VSW3_RUN_0_512500_V     (0x12U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.518750 V
 */
#define PF502X_F_VSW3_RUN_0_518750_V     (0x13U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.525000 V
 */
#define PF502X_F_VSW3_RUN_0_525000_V     (0x14U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.531250 V
 */
#define PF502X_F_VSW3_RUN_0_531250_V     (0x15U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.537500 V
 */
#define PF502X_F_VSW3_RUN_0_537500_V     (0x16U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.543750 V
 */
#define PF502X_F_VSW3_RUN_0_543750_V     (0x17U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.550000 V
 */
#define PF502X_F_VSW3_RUN_0_550000_V     (0x18U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.556250 V
 */
#define PF502X_F_VSW3_RUN_0_556250_V     (0x19U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.562500 V
 */
#define PF502X_F_VSW3_RUN_0_562500_V     (0x1AU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.568750 V
 */
#define PF502X_F_VSW3_RUN_0_568750_V     (0x1BU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.575000 V
 */
#define PF502X_F_VSW3_RUN_0_575000_V     (0x1CU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.581250 V
 */
#define PF502X_F_VSW3_RUN_0_581250_V     (0x1DU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.587500 V
 */
#define PF502X_F_VSW3_RUN_0_587500_V     (0x1EU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.593750 V
 */
#define PF502X_F_VSW3_RUN_0_593750_V     (0x1FU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.600000 V
 */
#define PF502X_F_VSW3_RUN_0_600000_V     (0x20U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.606250 V
 */
#define PF502X_F_VSW3_RUN_0_606250_V     (0x21U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.612500 V
 */
#define PF502X_F_VSW3_RUN_0_612500_V     (0x22U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.618750 V
 */
#define PF502X_F_VSW3_RUN_0_618750_V     (0x23U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.625000 V
 */
#define PF502X_F_VSW3_RUN_0_625000_V     (0x24U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.631250 V
 */
#define PF502X_F_VSW3_RUN_0_631250_V     (0x25U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.637500 V
 */
#define PF502X_F_VSW3_RUN_0_637500_V     (0x26U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.643750 V
 */
#define PF502X_F_VSW3_RUN_0_643750_V     (0x27U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.650000 V
 */
#define PF502X_F_VSW3_RUN_0_650000_V     (0x28U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.656250 V
 */
#define PF502X_F_VSW3_RUN_0_656250_V     (0x29U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.662500 V
 */
#define PF502X_F_VSW3_RUN_0_662500_V     (0x2AU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.668750 V
 */
#define PF502X_F_VSW3_RUN_0_668750_V     (0x2BU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.675000 V
 */
#define PF502X_F_VSW3_RUN_0_675000_V     (0x2CU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.681250 V
 */
#define PF502X_F_VSW3_RUN_0_681250_V     (0x2DU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.687500 V
 */
#define PF502X_F_VSW3_RUN_0_687500_V     (0x2EU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.693750 V
 */
#define PF502X_F_VSW3_RUN_0_693750_V     (0x2FU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.700000 V
 */
#define PF502X_F_VSW3_RUN_0_700000_V     (0x30U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.706250 V
 */
#define PF502X_F_VSW3_RUN_0_706250_V     (0x31U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.712500 V
 */
#define PF502X_F_VSW3_RUN_0_712500_V     (0x32U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.718750 V
 */
#define PF502X_F_VSW3_RUN_0_718750_V     (0x33U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.725000 V
 */
#define PF502X_F_VSW3_RUN_0_725000_V     (0x34U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.731250 V
 */
#define PF502X_F_VSW3_RUN_0_731250_V     (0x35U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.737500 V
 */
#define PF502X_F_VSW3_RUN_0_737500_V     (0x36U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.743750 V
 */
#define PF502X_F_VSW3_RUN_0_743750_V     (0x37U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.750000 V
 */
#define PF502X_F_VSW3_RUN_0_750000_V     (0x38U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.756250 V
 */
#define PF502X_F_VSW3_RUN_0_756250_V     (0x39U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.762500 V
 */
#define PF502X_F_VSW3_RUN_0_762500_V     (0x3AU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.768750 V
 */
#define PF502X_F_VSW3_RUN_0_768750_V     (0x3BU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.775000 V
 */
#define PF502X_F_VSW3_RUN_0_775000_V     (0x3CU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.781250 V
 */
#define PF502X_F_VSW3_RUN_0_781250_V     (0x3DU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.787500 V
 */
#define PF502X_F_VSW3_RUN_0_787500_V     (0x3EU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.793750 V
 */
#define PF502X_F_VSW3_RUN_0_793750_V     (0x3FU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.800000 V
 */
#define PF502X_F_VSW3_RUN_0_800000_V     (0x40U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.806250 V
 */
#define PF502X_F_VSW3_RUN_0_806250_V     (0x41U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.812500 V
 */
#define PF502X_F_VSW3_RUN_0_812500_V     (0x42U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.818750 V
 */
#define PF502X_F_VSW3_RUN_0_818750_V     (0x43U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.825000 V
 */
#define PF502X_F_VSW3_RUN_0_825000_V     (0x44U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.831250 V
 */
#define PF502X_F_VSW3_RUN_0_831250_V     (0x45U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.837500 V
 */
#define PF502X_F_VSW3_RUN_0_837500_V     (0x46U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.843750 V
 */
#define PF502X_F_VSW3_RUN_0_843750_V     (0x47U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.850000 V
 */
#define PF502X_F_VSW3_RUN_0_850000_V     (0x48U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.856250 V
 */
#define PF502X_F_VSW3_RUN_0_856250_V     (0x49U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.862500 V
 */
#define PF502X_F_VSW3_RUN_0_862500_V     (0x4AU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.868750 V
 */
#define PF502X_F_VSW3_RUN_0_868750_V     (0x4BU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.875000 V
 */
#define PF502X_F_VSW3_RUN_0_875000_V     (0x4CU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.881250 V
 */
#define PF502X_F_VSW3_RUN_0_881250_V     (0x4DU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.887500 V
 */
#define PF502X_F_VSW3_RUN_0_887500_V     (0x4EU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.893750 V
 */
#define PF502X_F_VSW3_RUN_0_893750_V     (0x4FU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.900000 V
 */
#define PF502X_F_VSW3_RUN_0_900000_V     (0x50U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.906250 V
 */
#define PF502X_F_VSW3_RUN_0_906250_V     (0x51U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.912500 V
 */
#define PF502X_F_VSW3_RUN_0_912500_V     (0x52U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.918750 V
 */
#define PF502X_F_VSW3_RUN_0_918750_V     (0x53U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.925000 V
 */
#define PF502X_F_VSW3_RUN_0_925000_V     (0x54U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.931250 V
 */
#define PF502X_F_VSW3_RUN_0_931250_V     (0x55U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.937500 V
 */
#define PF502X_F_VSW3_RUN_0_937500_V     (0x56U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.943750 V
 */
#define PF502X_F_VSW3_RUN_0_943750_V     (0x57U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.950000 V
 */
#define PF502X_F_VSW3_RUN_0_950000_V     (0x58U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.956250 V
 */
#define PF502X_F_VSW3_RUN_0_956250_V     (0x59U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.962500 V
 */
#define PF502X_F_VSW3_RUN_0_962500_V     (0x5AU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.968750 V
 */
#define PF502X_F_VSW3_RUN_0_968750_V     (0x5BU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.975000 V
 */
#define PF502X_F_VSW3_RUN_0_975000_V     (0x5CU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.981250 V
 */
#define PF502X_F_VSW3_RUN_0_981250_V     (0x5DU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.987500 V
 */
#define PF502X_F_VSW3_RUN_0_987500_V     (0x5EU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 0.993750 V
 */
#define PF502X_F_VSW3_RUN_0_993750_V     (0x5FU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.000000 V
 */
#define PF502X_F_VSW3_RUN_1_000000_V     (0x60U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.006250 V
 */
#define PF502X_F_VSW3_RUN_1_006250_V     (0x61U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.012500 V
 */
#define PF502X_F_VSW3_RUN_1_012500_V     (0x62U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.018750 V
 */
#define PF502X_F_VSW3_RUN_1_018750_V     (0x63U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.025000 V
 */
#define PF502X_F_VSW3_RUN_1_025000_V     (0x64U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.031250 V
 */
#define PF502X_F_VSW3_RUN_1_031250_V     (0x65U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.037500 V
 */
#define PF502X_F_VSW3_RUN_1_037500_V     (0x66U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.043750 V
 */
#define PF502X_F_VSW3_RUN_1_043750_V     (0x67U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.050000 V
 */
#define PF502X_F_VSW3_RUN_1_050000_V     (0x68U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.056250 V
 */
#define PF502X_F_VSW3_RUN_1_056250_V     (0x69U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.062500 V
 */
#define PF502X_F_VSW3_RUN_1_062500_V     (0x6AU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.068750 V
 */
#define PF502X_F_VSW3_RUN_1_068750_V     (0x6BU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.075000 V
 */
#define PF502X_F_VSW3_RUN_1_075000_V     (0x6CU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.081250 V
 */
#define PF502X_F_VSW3_RUN_1_081250_V     (0x6DU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.087500 V
 */
#define PF502X_F_VSW3_RUN_1_087500_V     (0x6EU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.093750 V
 */
#define PF502X_F_VSW3_RUN_1_093750_V     (0x6FU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.100000 V
 */
#define PF502X_F_VSW3_RUN_1_100000_V     (0x70U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.106250 V
 */
#define PF502X_F_VSW3_RUN_1_106250_V     (0x71U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.112500 V
 */
#define PF502X_F_VSW3_RUN_1_112500_V     (0x72U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.118750 V
 */
#define PF502X_F_VSW3_RUN_1_118750_V     (0x73U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.125000 V
 */
#define PF502X_F_VSW3_RUN_1_125000_V     (0x74U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.131250 V
 */
#define PF502X_F_VSW3_RUN_1_131250_V     (0x75U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.137500 V
 */
#define PF502X_F_VSW3_RUN_1_137500_V     (0x76U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.143750 V
 */
#define PF502X_F_VSW3_RUN_1_143750_V     (0x77U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.150000 V
 */
#define PF502X_F_VSW3_RUN_1_150000_V     (0x78U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.156250 V
 */
#define PF502X_F_VSW3_RUN_1_156250_V     (0x79U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.162500 V
 */
#define PF502X_F_VSW3_RUN_1_162500_V     (0x7AU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.168750 V
 */
#define PF502X_F_VSW3_RUN_1_168750_V     (0x7BU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.175000 V
 */
#define PF502X_F_VSW3_RUN_1_175000_V     (0x7CU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.181250 V
 */
#define PF502X_F_VSW3_RUN_1_181250_V     (0x7DU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.187500 V
 */
#define PF502X_F_VSW3_RUN_1_187500_V     (0x7EU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.193750 V
 */
#define PF502X_F_VSW3_RUN_1_193750_V     (0x7FU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.200000 V
 */
#define PF502X_F_VSW3_RUN_1_200000_V     (0x80U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.206250 V
 */
#define PF502X_F_VSW3_RUN_1_206250_V     (0x81U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.212500 V
 */
#define PF502X_F_VSW3_RUN_1_212500_V     (0x82U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.218750 V
 */
#define PF502X_F_VSW3_RUN_1_218750_V     (0x83U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.225000 V
 */
#define PF502X_F_VSW3_RUN_1_225000_V     (0x84U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.231250 V
 */
#define PF502X_F_VSW3_RUN_1_231250_V     (0x85U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.237500 V
 */
#define PF502X_F_VSW3_RUN_1_237500_V     (0x86U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.243750 V
 */
#define PF502X_F_VSW3_RUN_1_243750_V     (0x87U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.250000 V
 */
#define PF502X_F_VSW3_RUN_1_250000_V     (0x88U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.256250 V
 */
#define PF502X_F_VSW3_RUN_1_256250_V     (0x89U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.262500 V
 */
#define PF502X_F_VSW3_RUN_1_262500_V     (0x8AU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.268750 V
 */
#define PF502X_F_VSW3_RUN_1_268750_V     (0x8BU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.275000 V
 */
#define PF502X_F_VSW3_RUN_1_275000_V     (0x8CU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.281250 V
 */
#define PF502X_F_VSW3_RUN_1_281250_V     (0x8DU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.287500 V
 */
#define PF502X_F_VSW3_RUN_1_287500_V     (0x8EU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.293750 V
 */
#define PF502X_F_VSW3_RUN_1_293750_V     (0x8FU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.300000 V
 */
#define PF502X_F_VSW3_RUN_1_300000_V     (0x90U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.306250 V
 */
#define PF502X_F_VSW3_RUN_1_306250_V     (0x91U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.312500 V
 */
#define PF502X_F_VSW3_RUN_1_312500_V     (0x92U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.318750 V
 */
#define PF502X_F_VSW3_RUN_1_318750_V     (0x93U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.325000 V
 */
#define PF502X_F_VSW3_RUN_1_325000_V     (0x94U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.331250 V
 */
#define PF502X_F_VSW3_RUN_1_331250_V     (0x95U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.337500 V
 */
#define PF502X_F_VSW3_RUN_1_337500_V     (0x96U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.343750 V
 */
#define PF502X_F_VSW3_RUN_1_343750_V     (0x97U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.350000 V
 */
#define PF502X_F_VSW3_RUN_1_350000_V     (0x98U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.356250 V
 */
#define PF502X_F_VSW3_RUN_1_356250_V     (0x99U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.362500 V
 */
#define PF502X_F_VSW3_RUN_1_362500_V     (0x9AU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.368750 V
 */
#define PF502X_F_VSW3_RUN_1_368750_V     (0x9BU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.375000 V
 */
#define PF502X_F_VSW3_RUN_1_375000_V     (0x9CU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.381250 V
 */
#define PF502X_F_VSW3_RUN_1_381250_V     (0x9DU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.387500 V
 */
#define PF502X_F_VSW3_RUN_1_387500_V     (0x9EU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.393750 V
 */
#define PF502X_F_VSW3_RUN_1_393750_V     (0x9FU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.400000 V
 */
#define PF502X_F_VSW3_RUN_1_400000_V     (0xA0U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.406250 V
 */
#define PF502X_F_VSW3_RUN_1_406250_V     (0xA1U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.412500 V
 */
#define PF502X_F_VSW3_RUN_1_412500_V     (0xA2U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.418750 V
 */
#define PF502X_F_VSW3_RUN_1_418750_V     (0xA3U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.425000 V
 */
#define PF502X_F_VSW3_RUN_1_425000_V     (0xA4U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.431250 V
 */
#define PF502X_F_VSW3_RUN_1_431250_V     (0xA5U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.437500 V
 */
#define PF502X_F_VSW3_RUN_1_437500_V     (0xA6U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.443750 V
 */
#define PF502X_F_VSW3_RUN_1_443750_V     (0xA7U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.450000 V
 */
#define PF502X_F_VSW3_RUN_1_450000_V     (0xA8U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.456250 V
 */
#define PF502X_F_VSW3_RUN_1_456250_V     (0xA9U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.462500 V
 */
#define PF502X_F_VSW3_RUN_1_462500_V     (0xAAU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.468750 V
 */
#define PF502X_F_VSW3_RUN_1_468750_V     (0xABU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.475000 V
 */
#define PF502X_F_VSW3_RUN_1_475000_V     (0xACU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.481250 V
 */
#define PF502X_F_VSW3_RUN_1_481250_V     (0xADU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.487500 V
 */
#define PF502X_F_VSW3_RUN_1_487500_V     (0xAEU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.493750 V
 */
#define PF502X_F_VSW3_RUN_1_493750_V     (0xAFU << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.500000 V
 */
#define PF502X_F_VSW3_RUN_1_500000_V     (0xB0U << PF502X_F_VSW3_RUN_SHIFT)
/**
 * 1.80000 V
 */
#define PF502X_F_VSW3_RUN_1_80000_V      (0xB1U << PF502X_F_VSW3_RUN_SHIFT)

/******************************************************************************/
/* SW3_STBY_VOLT - Type: RW                                                   */
/******************************************************************************/

#define PF502X_SW3_STBY_VOLT_ADDR        0x5CU
#define PF502X_SW3_STBY_VOLT_DEFAULT     0x00U

/**
 * It uses the OTP_VSW3 to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW3_STBY_MASK          0xFFU

/**
 * It uses the OTP_VSW3 to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW3_STBY_SHIFT         0x00U

/**
 * 0.400000 V
 */
#define PF502X_F_VSW3_STBY_0_400000_V    (0x00U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.406250 V
 */
#define PF502X_F_VSW3_STBY_0_406250_V    (0x01U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.412500 V
 */
#define PF502X_F_VSW3_STBY_0_412500_V    (0x02U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.418750 V
 */
#define PF502X_F_VSW3_STBY_0_418750_V    (0x03U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.425000 V
 */
#define PF502X_F_VSW3_STBY_0_425000_V    (0x04U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.431250 V
 */
#define PF502X_F_VSW3_STBY_0_431250_V    (0x05U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.437500 V
 */
#define PF502X_F_VSW3_STBY_0_437500_V    (0x06U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.443750 V
 */
#define PF502X_F_VSW3_STBY_0_443750_V    (0x07U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.450000 V
 */
#define PF502X_F_VSW3_STBY_0_450000_V    (0x08U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.456250 V
 */
#define PF502X_F_VSW3_STBY_0_456250_V    (0x09U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.462500 V
 */
#define PF502X_F_VSW3_STBY_0_462500_V    (0x0AU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.468750 V
 */
#define PF502X_F_VSW3_STBY_0_468750_V    (0x0BU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.475000 V
 */
#define PF502X_F_VSW3_STBY_0_475000_V    (0x0CU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.481250 V
 */
#define PF502X_F_VSW3_STBY_0_481250_V    (0x0DU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.487500 V
 */
#define PF502X_F_VSW3_STBY_0_487500_V    (0x0EU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.493750 V
 */
#define PF502X_F_VSW3_STBY_0_493750_V    (0x0FU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.500000 V
 */
#define PF502X_F_VSW3_STBY_0_500000_V    (0x10U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.506250 V
 */
#define PF502X_F_VSW3_STBY_0_506250_V    (0x11U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.512500 V
 */
#define PF502X_F_VSW3_STBY_0_512500_V    (0x12U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.518750 V
 */
#define PF502X_F_VSW3_STBY_0_518750_V    (0x13U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.525000 V
 */
#define PF502X_F_VSW3_STBY_0_525000_V    (0x14U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.531250 V
 */
#define PF502X_F_VSW3_STBY_0_531250_V    (0x15U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.537500 V
 */
#define PF502X_F_VSW3_STBY_0_537500_V    (0x16U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.543750 V
 */
#define PF502X_F_VSW3_STBY_0_543750_V    (0x17U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.550000 V
 */
#define PF502X_F_VSW3_STBY_0_550000_V    (0x18U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.556250 V
 */
#define PF502X_F_VSW3_STBY_0_556250_V    (0x19U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.562500 V
 */
#define PF502X_F_VSW3_STBY_0_562500_V    (0x1AU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.568750 V
 */
#define PF502X_F_VSW3_STBY_0_568750_V    (0x1BU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.575000 V
 */
#define PF502X_F_VSW3_STBY_0_575000_V    (0x1CU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.581250 V
 */
#define PF502X_F_VSW3_STBY_0_581250_V    (0x1DU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.587500 V
 */
#define PF502X_F_VSW3_STBY_0_587500_V    (0x1EU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.593750 V
 */
#define PF502X_F_VSW3_STBY_0_593750_V    (0x1FU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.600000 V
 */
#define PF502X_F_VSW3_STBY_0_600000_V    (0x20U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.606250 V
 */
#define PF502X_F_VSW3_STBY_0_606250_V    (0x21U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.612500 V
 */
#define PF502X_F_VSW3_STBY_0_612500_V    (0x22U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.618750 V
 */
#define PF502X_F_VSW3_STBY_0_618750_V    (0x23U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.625000 V
 */
#define PF502X_F_VSW3_STBY_0_625000_V    (0x24U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.631250 V
 */
#define PF502X_F_VSW3_STBY_0_631250_V    (0x25U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.637500 V
 */
#define PF502X_F_VSW3_STBY_0_637500_V    (0x26U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.643750 V
 */
#define PF502X_F_VSW3_STBY_0_643750_V    (0x27U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.650000 V
 */
#define PF502X_F_VSW3_STBY_0_650000_V    (0x28U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.656250 V
 */
#define PF502X_F_VSW3_STBY_0_656250_V    (0x29U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.662500 V
 */
#define PF502X_F_VSW3_STBY_0_662500_V    (0x2AU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.668750 V
 */
#define PF502X_F_VSW3_STBY_0_668750_V    (0x2BU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.675000 V
 */
#define PF502X_F_VSW3_STBY_0_675000_V    (0x2CU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.681250 V
 */
#define PF502X_F_VSW3_STBY_0_681250_V    (0x2DU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.687500 V
 */
#define PF502X_F_VSW3_STBY_0_687500_V    (0x2EU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.693750 V
 */
#define PF502X_F_VSW3_STBY_0_693750_V    (0x2FU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.700000 V
 */
#define PF502X_F_VSW3_STBY_0_700000_V    (0x30U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.706250 V
 */
#define PF502X_F_VSW3_STBY_0_706250_V    (0x31U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.712500 V
 */
#define PF502X_F_VSW3_STBY_0_712500_V    (0x32U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.718750 V
 */
#define PF502X_F_VSW3_STBY_0_718750_V    (0x33U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.725000 V
 */
#define PF502X_F_VSW3_STBY_0_725000_V    (0x34U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.731250 V
 */
#define PF502X_F_VSW3_STBY_0_731250_V    (0x35U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.737500 V
 */
#define PF502X_F_VSW3_STBY_0_737500_V    (0x36U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.743750 V
 */
#define PF502X_F_VSW3_STBY_0_743750_V    (0x37U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.750000 V
 */
#define PF502X_F_VSW3_STBY_0_750000_V    (0x38U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.756250 V
 */
#define PF502X_F_VSW3_STBY_0_756250_V    (0x39U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.762500 V
 */
#define PF502X_F_VSW3_STBY_0_762500_V    (0x3AU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.768750 V
 */
#define PF502X_F_VSW3_STBY_0_768750_V    (0x3BU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.775000 V
 */
#define PF502X_F_VSW3_STBY_0_775000_V    (0x3CU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.781250 V
 */
#define PF502X_F_VSW3_STBY_0_781250_V    (0x3DU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.787500 V
 */
#define PF502X_F_VSW3_STBY_0_787500_V    (0x3EU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.793750 V
 */
#define PF502X_F_VSW3_STBY_0_793750_V    (0x3FU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.800000 V
 */
#define PF502X_F_VSW3_STBY_0_800000_V    (0x40U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.806250 V
 */
#define PF502X_F_VSW3_STBY_0_806250_V    (0x41U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.812500 V
 */
#define PF502X_F_VSW3_STBY_0_812500_V    (0x42U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.818750 V
 */
#define PF502X_F_VSW3_STBY_0_818750_V    (0x43U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.825000 V
 */
#define PF502X_F_VSW3_STBY_0_825000_V    (0x44U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.831250 V
 */
#define PF502X_F_VSW3_STBY_0_831250_V    (0x45U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.837500 V
 */
#define PF502X_F_VSW3_STBY_0_837500_V    (0x46U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.843750 V
 */
#define PF502X_F_VSW3_STBY_0_843750_V    (0x47U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.850000 V
 */
#define PF502X_F_VSW3_STBY_0_850000_V    (0x48U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.856250 V
 */
#define PF502X_F_VSW3_STBY_0_856250_V    (0x49U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.862500 V
 */
#define PF502X_F_VSW3_STBY_0_862500_V    (0x4AU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.868750 V
 */
#define PF502X_F_VSW3_STBY_0_868750_V    (0x4BU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.875000 V
 */
#define PF502X_F_VSW3_STBY_0_875000_V    (0x4CU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.881250 V
 */
#define PF502X_F_VSW3_STBY_0_881250_V    (0x4DU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.887500 V
 */
#define PF502X_F_VSW3_STBY_0_887500_V    (0x4EU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.893750 V
 */
#define PF502X_F_VSW3_STBY_0_893750_V    (0x4FU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.900000 V
 */
#define PF502X_F_VSW3_STBY_0_900000_V    (0x50U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.906250 V
 */
#define PF502X_F_VSW3_STBY_0_906250_V    (0x51U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.912500 V
 */
#define PF502X_F_VSW3_STBY_0_912500_V    (0x52U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.918750 V
 */
#define PF502X_F_VSW3_STBY_0_918750_V    (0x53U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.925000 V
 */
#define PF502X_F_VSW3_STBY_0_925000_V    (0x54U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.931250 V
 */
#define PF502X_F_VSW3_STBY_0_931250_V    (0x55U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.937500 V
 */
#define PF502X_F_VSW3_STBY_0_937500_V    (0x56U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.943750 V
 */
#define PF502X_F_VSW3_STBY_0_943750_V    (0x57U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.950000 V
 */
#define PF502X_F_VSW3_STBY_0_950000_V    (0x58U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.956250 V
 */
#define PF502X_F_VSW3_STBY_0_956250_V    (0x59U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.962500 V
 */
#define PF502X_F_VSW3_STBY_0_962500_V    (0x5AU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.968750 V
 */
#define PF502X_F_VSW3_STBY_0_968750_V    (0x5BU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.975000 V
 */
#define PF502X_F_VSW3_STBY_0_975000_V    (0x5CU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.981250 V
 */
#define PF502X_F_VSW3_STBY_0_981250_V    (0x5DU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.987500 V
 */
#define PF502X_F_VSW3_STBY_0_987500_V    (0x5EU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 0.993750 V
 */
#define PF502X_F_VSW3_STBY_0_993750_V    (0x5FU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.000000 V
 */
#define PF502X_F_VSW3_STBY_1_000000_V    (0x60U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.006250 V
 */
#define PF502X_F_VSW3_STBY_1_006250_V    (0x61U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.012500 V
 */
#define PF502X_F_VSW3_STBY_1_012500_V    (0x62U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.018750 V
 */
#define PF502X_F_VSW3_STBY_1_018750_V    (0x63U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.025000 V
 */
#define PF502X_F_VSW3_STBY_1_025000_V    (0x64U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.031250 V
 */
#define PF502X_F_VSW3_STBY_1_031250_V    (0x65U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.037500 V
 */
#define PF502X_F_VSW3_STBY_1_037500_V    (0x66U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.043750 V
 */
#define PF502X_F_VSW3_STBY_1_043750_V    (0x67U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.050000 V
 */
#define PF502X_F_VSW3_STBY_1_050000_V    (0x68U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.056250 V
 */
#define PF502X_F_VSW3_STBY_1_056250_V    (0x69U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.062500 V
 */
#define PF502X_F_VSW3_STBY_1_062500_V    (0x6AU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.068750 V
 */
#define PF502X_F_VSW3_STBY_1_068750_V    (0x6BU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.075000 V
 */
#define PF502X_F_VSW3_STBY_1_075000_V    (0x6CU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.081250 V
 */
#define PF502X_F_VSW3_STBY_1_081250_V    (0x6DU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.087500 V
 */
#define PF502X_F_VSW3_STBY_1_087500_V    (0x6EU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.093750 V
 */
#define PF502X_F_VSW3_STBY_1_093750_V    (0x6FU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.100000 V
 */
#define PF502X_F_VSW3_STBY_1_100000_V    (0x70U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.106250 V
 */
#define PF502X_F_VSW3_STBY_1_106250_V    (0x71U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.112500 V
 */
#define PF502X_F_VSW3_STBY_1_112500_V    (0x72U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.118750 V
 */
#define PF502X_F_VSW3_STBY_1_118750_V    (0x73U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.125000 V
 */
#define PF502X_F_VSW3_STBY_1_125000_V    (0x74U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.131250 V
 */
#define PF502X_F_VSW3_STBY_1_131250_V    (0x75U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.137500 V
 */
#define PF502X_F_VSW3_STBY_1_137500_V    (0x76U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.143750 V
 */
#define PF502X_F_VSW3_STBY_1_143750_V    (0x77U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.150000 V
 */
#define PF502X_F_VSW3_STBY_1_150000_V    (0x78U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.156250 V
 */
#define PF502X_F_VSW3_STBY_1_156250_V    (0x79U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.162500 V
 */
#define PF502X_F_VSW3_STBY_1_162500_V    (0x7AU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.168750 V
 */
#define PF502X_F_VSW3_STBY_1_168750_V    (0x7BU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.175000 V
 */
#define PF502X_F_VSW3_STBY_1_175000_V    (0x7CU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.181250 V
 */
#define PF502X_F_VSW3_STBY_1_181250_V    (0x7DU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.187500 V
 */
#define PF502X_F_VSW3_STBY_1_187500_V    (0x7EU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.193750 V
 */
#define PF502X_F_VSW3_STBY_1_193750_V    (0x7FU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.200000 V
 */
#define PF502X_F_VSW3_STBY_1_200000_V    (0x80U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.206250 V
 */
#define PF502X_F_VSW3_STBY_1_206250_V    (0x81U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.212500 V
 */
#define PF502X_F_VSW3_STBY_1_212500_V    (0x82U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.218750 V
 */
#define PF502X_F_VSW3_STBY_1_218750_V    (0x83U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.225000 V
 */
#define PF502X_F_VSW3_STBY_1_225000_V    (0x84U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.231250 V
 */
#define PF502X_F_VSW3_STBY_1_231250_V    (0x85U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.237500 V
 */
#define PF502X_F_VSW3_STBY_1_237500_V    (0x86U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.243750 V
 */
#define PF502X_F_VSW3_STBY_1_243750_V    (0x87U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.250000 V
 */
#define PF502X_F_VSW3_STBY_1_250000_V    (0x88U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.256250 V
 */
#define PF502X_F_VSW3_STBY_1_256250_V    (0x89U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.262500 V
 */
#define PF502X_F_VSW3_STBY_1_262500_V    (0x8AU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.268750 V
 */
#define PF502X_F_VSW3_STBY_1_268750_V    (0x8BU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.275000 V
 */
#define PF502X_F_VSW3_STBY_1_275000_V    (0x8CU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.281250 V
 */
#define PF502X_F_VSW3_STBY_1_281250_V    (0x8DU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.287500 V
 */
#define PF502X_F_VSW3_STBY_1_287500_V    (0x8EU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.293750 V
 */
#define PF502X_F_VSW3_STBY_1_293750_V    (0x8FU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.300000 V
 */
#define PF502X_F_VSW3_STBY_1_300000_V    (0x90U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.306250 V
 */
#define PF502X_F_VSW3_STBY_1_306250_V    (0x91U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.312500 V
 */
#define PF502X_F_VSW3_STBY_1_312500_V    (0x92U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.318750 V
 */
#define PF502X_F_VSW3_STBY_1_318750_V    (0x93U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.325000 V
 */
#define PF502X_F_VSW3_STBY_1_325000_V    (0x94U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.331250 V
 */
#define PF502X_F_VSW3_STBY_1_331250_V    (0x95U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.337500 V
 */
#define PF502X_F_VSW3_STBY_1_337500_V    (0x96U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.343750 V
 */
#define PF502X_F_VSW3_STBY_1_343750_V    (0x97U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.350000 V
 */
#define PF502X_F_VSW3_STBY_1_350000_V    (0x98U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.356250 V
 */
#define PF502X_F_VSW3_STBY_1_356250_V    (0x99U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.362500 V
 */
#define PF502X_F_VSW3_STBY_1_362500_V    (0x9AU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.368750 V
 */
#define PF502X_F_VSW3_STBY_1_368750_V    (0x9BU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.375000 V
 */
#define PF502X_F_VSW3_STBY_1_375000_V    (0x9CU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.381250 V
 */
#define PF502X_F_VSW3_STBY_1_381250_V    (0x9DU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.387500 V
 */
#define PF502X_F_VSW3_STBY_1_387500_V    (0x9EU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.393750 V
 */
#define PF502X_F_VSW3_STBY_1_393750_V    (0x9FU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.400000 V
 */
#define PF502X_F_VSW3_STBY_1_400000_V    (0xA0U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.406250 V
 */
#define PF502X_F_VSW3_STBY_1_406250_V    (0xA1U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.412500 V
 */
#define PF502X_F_VSW3_STBY_1_412500_V    (0xA2U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.418750 V
 */
#define PF502X_F_VSW3_STBY_1_418750_V    (0xA3U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.425000 V
 */
#define PF502X_F_VSW3_STBY_1_425000_V    (0xA4U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.431250 V
 */
#define PF502X_F_VSW3_STBY_1_431250_V    (0xA5U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.437500 V
 */
#define PF502X_F_VSW3_STBY_1_437500_V    (0xA6U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.443750 V
 */
#define PF502X_F_VSW3_STBY_1_443750_V    (0xA7U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.450000 V
 */
#define PF502X_F_VSW3_STBY_1_450000_V    (0xA8U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.456250 V
 */
#define PF502X_F_VSW3_STBY_1_456250_V    (0xA9U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.462500 V
 */
#define PF502X_F_VSW3_STBY_1_462500_V    (0xAAU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.468750 V
 */
#define PF502X_F_VSW3_STBY_1_468750_V    (0xABU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.475000 V
 */
#define PF502X_F_VSW3_STBY_1_475000_V    (0xACU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.481250 V
 */
#define PF502X_F_VSW3_STBY_1_481250_V    (0xADU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.487500 V
 */
#define PF502X_F_VSW3_STBY_1_487500_V    (0xAEU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.493750 V
 */
#define PF502X_F_VSW3_STBY_1_493750_V    (0xAFU << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.500000 V
 */
#define PF502X_F_VSW3_STBY_1_500000_V    (0xB0U << PF502X_F_VSW3_STBY_SHIFT)
/**
 * 1.80000 V
 */
#define PF502X_F_VSW3_STBY_1_80000_V     (0xB1U << PF502X_F_VSW3_STBY_SHIFT)

/******************************************************************************/
/* SW4_CONFIG1 - Type: RW                                                     */
/******************************************************************************/

#define PF502X_SW4_CONFIG1_ADDR          0x5FU
#define PF502X_SW4_CONFIG1_DEFAULT       0x1CU

/**
 * Allows SW4 regulator to control the PGOOD pin.
 */
#define PF502X_F_SW4_PG_EN_MASK          0x01U
/**
 * Enable Watchdog bypass for SW4 Regulator
 */
#define PF502X_F_SW4_WDBYPASS_MASK       0x02U
/**
 * Decides wherther SW4 Regulator remains enable or is disabled upon an ILIM Fault event
 */
#define PF502X_F_SW4_ILIM_STATE_MASK     0x04U
/**
 * Decides wherther SW4 Regulator remains enable or is disabled upon an OV Fault event
 */
#define PF502X_F_SW4_OV_STATE_MASK       0x08U
/**
 * Decides wherther SW4 Regulator remains enable or is disabled upon an UV Fault event
 */
#define PF502X_F_SW4_UV_STATE_MASK       0x10U
/**
 * Bypass the ILIM Fault event on SW4 Regulator
 */
#define PF502X_F_SW4_ILIM_BYPASS_MASK    0x20U
/**
 * Bypass the OV Fault event on SW4 Regulator
 */
#define PF502X_F_SW4_OV_BYPASS_MASK      0x40U
/**
 * Bypass the UV Fault event on SW4 Regulator
 */
#define PF502X_F_SW4_UV_BYPASS_MASK      0x80U

/**
 * Allows SW4 regulator to control the PGOOD pin.
 */
#define PF502X_F_SW4_PG_EN_SHIFT         0x00U
/**
 * Enable Watchdog bypass for SW4 Regulator
 */
#define PF502X_F_SW4_WDBYPASS_SHIFT      0x01U
/**
 * Decides wherther SW4 Regulator remains enable or is disabled upon an ILIM Fault event
 */
#define PF502X_F_SW4_ILIM_STATE_SHIFT    0x02U
/**
 * Decides wherther SW4 Regulator remains enable or is disabled upon an OV Fault event
 */
#define PF502X_F_SW4_OV_STATE_SHIFT      0x03U
/**
 * Decides wherther SW4 Regulator remains enable or is disabled upon an UV Fault event
 */
#define PF502X_F_SW4_UV_STATE_SHIFT      0x04U
/**
 * Bypass the ILIM Fault event on SW4 Regulator
 */
#define PF502X_F_SW4_ILIM_BYPASS_SHIFT   0x05U
/**
 * Bypass the OV Fault event on SW4 Regulator
 */
#define PF502X_F_SW4_OV_BYPASS_SHIFT     0x06U
/**
 * Bypass the UV Fault event on SW4 Regulator
 */
#define PF502X_F_SW4_UV_BYPASS_SHIFT     0x07U

/**
 * regulator is not able to set or clear the PGOOD pin
 */
#define PF502X_F_SW4_PG_EN_DISABLED      (0x00U << PF502X_F_SW4_PG_EN_SHIFT)
/**
 * Regulator's PG bit is part of the AND function to control PGOOD pin
 */
#define PF502X_F_SW4_PG_EN_ENABLED       (0x01U << PF502X_F_SW4_PG_EN_SHIFT)

/**
 * Regulator reacts upon a Watchdog
 */
#define PF502X_F_SW4_WDBYPASS_ENABLED    (0x00U << PF502X_F_SW4_WDBYPASS_SHIFT)
/**
 * Regulator bypass Watchdog event and keeps current configuration
 */
#define PF502X_F_SW4_WDBYPASS_BYPASS     (0x01U << PF502X_F_SW4_WDBYPASS_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW4_ILIM_STATE_DISABLED (0x00U << PF502X_F_SW4_ILIM_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW4_ILIM_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW4_ILIM_STATE_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW4_OV_STATE_DISABLED   (0x00U << PF502X_F_SW4_OV_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW4_OV_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW4_OV_STATE_SHIFT)

/**
 * Regulator is disabled
 */
#define PF502X_F_SW4_UV_STATE_DISABLED   (0x00U << PF502X_F_SW4_UV_STATE_SHIFT)
/**
 * Regulator remains in previous state.
 */
#define PF502X_F_SW4_UV_STATE_PREVIOUS_STATE (0x01U << PF502X_F_SW4_UV_STATE_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW4_ILIM_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW4_ILIM_BYPASS_SHIFT)
/**
 * The Fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW4_ILIM_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW4_ILIM_BYPASS_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW4_OV_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW4_OV_BYPASS_SHIFT)
/**
 * The fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW4_OV_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW4_OV_BYPASS_SHIFT)

/**
 * A fault event will trigger a protective behavior ( start the Fault timer, Fault counter and disable the regulator 
 * if programmed to do so)
 */
#define PF502X_F_SW4_UV_BYPASS_TRIGGER_ENABLED (0x00U << PF502X_F_SW4_UV_BYPASS_SHIFT)
/**
 * The fault is bypassed, The regulator does not follow any corrective behavior (interrupt is still set if not masked)
 */
#define PF502X_F_SW4_UV_BYPASS_TRIGGER_BYPASSED (0x01U << PF502X_F_SW4_UV_BYPASS_SHIFT)

/******************************************************************************/
/* SW4_CONFIG2 - Type: RW                                                     */
/******************************************************************************/

#define PF502X_SW4_CONFIG2_ADDR          0x60U
#define PF502X_SW4_CONFIG2_DEFAULT       0x80U

/**
 * Set the Phase shift for SW4 Regulator
 */
#define PF502X_F_SW4PHASE_MASK           0x07U
/**
 * Set the current limit for SW4 Regulator
 */
#define PF502X_F_SW4ILIM_MASK            0x18U
/**
 * If SW4  is disabled upon a fault, this bit allow the regulator to re-enable when the fault condition is cleared.
 */
#define PF502X_F_SW4_FLT_REN_MASK        0x80U

/**
 * Set the Phase shift for SW4 Regulator
 */
#define PF502X_F_SW4PHASE_SHIFT          0x00U
/**
 * Set the current limit for SW4 Regulator
 */
#define PF502X_F_SW4ILIM_SHIFT           0x03U
/**
 * If SW4  is disabled upon a fault, this bit allow the regulator to re-enable when the fault condition is cleared.
 */
#define PF502X_F_SW4_FLT_REN_SHIFT       0x07U

/**
 * 45_
 */
#define PF502X_F_SW4PHASE_45_            (0x00U << PF502X_F_SW4PHASE_SHIFT)
/**
 * 90_
 */
#define PF502X_F_SW4PHASE_90_            (0x01U << PF502X_F_SW4PHASE_SHIFT)
/**
 * 135_
 */
#define PF502X_F_SW4PHASE_135_           (0x02U << PF502X_F_SW4PHASE_SHIFT)
/**
 * 180_
 */
#define PF502X_F_SW4PHASE_180_           (0x03U << PF502X_F_SW4PHASE_SHIFT)
/**
 * 225_
 */
#define PF502X_F_SW4PHASE_225_           (0x04U << PF502X_F_SW4PHASE_SHIFT)
/**
 * 270_
 */
#define PF502X_F_SW4PHASE_270_           (0x05U << PF502X_F_SW4PHASE_SHIFT)
/**
 * 315_
 */
#define PF502X_F_SW4PHASE_315_           (0x06U << PF502X_F_SW4PHASE_SHIFT)
/**
 * 0_
 */
#define PF502X_F_SW4PHASE_0_             (0x07U << PF502X_F_SW4PHASE_SHIFT)

/**
 * 2.1A
 */
#define PF502X_F_SW4ILIM_2_1_A           (0x00U << PF502X_F_SW4ILIM_SHIFT)
/**
 * 2.6A
 */
#define PF502X_F_SW4ILIM_2_6_A           (0x01U << PF502X_F_SW4ILIM_SHIFT)
/**
 * 3.0A
 */
#define PF502X_F_SW4ILIM_3_0_A           (0x02U << PF502X_F_SW4ILIM_SHIFT)
/**
 * 4.5A
 */
#define PF502X_F_SW4ILIM_4_5_A           (0x03U << PF502X_F_SW4ILIM_SHIFT)

/**
 * Regulator remains disabled upon clrearing the fault
 */
#define PF502X_F_SW4_FLT_REN_DISABLED    (0x00U << PF502X_F_SW4_FLT_REN_SHIFT)
/**
 * Regulator returns to its previous configuration.
 */
#define PF502X_F_SW4_FLT_REN_PREVIOUS_CONFIG_ (0x01U << PF502X_F_SW4_FLT_REN_SHIFT)

/******************************************************************************/
/* SW4_PWRUP - Type: RW                                                       */
/******************************************************************************/

#define PF502X_SW4_PWRUP_ADDR            0x61U
#define PF502X_SW4_PWRUP_DEFAULT         0x00U

/**
 * *Power Off Reset values to default OTP value.
 */
#define PF502X_F_SW4_SEQ_MASK            0xFFU

/**
 * *Power Off Reset values to default OTP value.
 */
#define PF502X_F_SW4_SEQ_SHIFT           0x00U

/******************************************************************************/
/* SW4_MODE1 - Type: RW                                                       */
/******************************************************************************/

#define PF502X_SW4_MODE1_ADDR            0x62U
#define PF502X_SW4_MODE1_DEFAULT         0x00U

/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW4_RUN_MODE_MASK       0x03U
/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW4_STBY_MODE_MASK      0x0CU
/**
 * Assign a Power Down group to SW4 Register.
 */
#define PF502X_F_SW4_PDGRP_MASK          0x30U

/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW4_RUN_MODE_SHIFT      0x00U
/**
 * when regulator is part of the Power up sequence, default value uses OTP_SW_MODE configuration, otherwise, default 
 * value is OFF.
 */
#define PF502X_F_SW4_STBY_MODE_SHIFT     0x02U
/**
 * Assign a Power Down group to SW4 Register.
 */
#define PF502X_F_SW4_PDGRP_SHIFT         0x04U

/**
 * OFF
 */
#define PF502X_F_SW4_RUN_MODE_OFF        (0x00U << PF502X_F_SW4_RUN_MODE_SHIFT)
/**
 * PWM
 */
#define PF502X_F_SW4_RUN_MODE_PWM        (0x01U << PF502X_F_SW4_RUN_MODE_SHIFT)
/**
 * PFM
 */
#define PF502X_F_SW4_RUN_MODE_PFM        (0x02U << PF502X_F_SW4_RUN_MODE_SHIFT)
/**
 * Auto Skip mode
 */
#define PF502X_F_SW4_RUN_MODE_AUTO_SKIP_MODE (0x03U << PF502X_F_SW4_RUN_MODE_SHIFT)

/**
 * OFF
 */
#define PF502X_F_SW4_STBY_MODE_OFF       (0x00U << PF502X_F_SW4_STBY_MODE_SHIFT)
/**
 * PWM
 */
#define PF502X_F_SW4_STBY_MODE_PWM       (0x01U << PF502X_F_SW4_STBY_MODE_SHIFT)
/**
 * PFM
 */
#define PF502X_F_SW4_STBY_MODE_PFM       (0x02U << PF502X_F_SW4_STBY_MODE_SHIFT)
/**
 * Auto Skip mode
 */
#define PF502X_F_SW4_STBY_MODE_AUTO_SKIP_MODE (0x03U << PF502X_F_SW4_STBY_MODE_SHIFT)

/**
 * Regulator is in Group 4 (turn of first)
 */
#define PF502X_F_SW4_PDGRP_GROUP_4       (0x00U << PF502X_F_SW4_PDGRP_SHIFT)
/**
 * Regulator is in Group 3
 */
#define PF502X_F_SW4_PDGRP_GROUP_3       (0x01U << PF502X_F_SW4_PDGRP_SHIFT)
/**
 * Regulator is in Group 2
 */
#define PF502X_F_SW4_PDGRP_GROUP_2       (0x02U << PF502X_F_SW4_PDGRP_SHIFT)
/**
 * Regulator is in Group 1 (turn off Last)
 */
#define PF502X_F_SW4_PDGRP_GROUP_1       (0x03U << PF502X_F_SW4_PDGRP_SHIFT)

/******************************************************************************/
/* SW4_RUN_VOLT - Type: RW                                                    */
/******************************************************************************/

#define PF502X_SW4_RUN_VOLT_ADDR         0x63U
#define PF502X_SW4_RUN_VOLT_DEFAULT      0x00U

/**
 * It uses the OTP_VSW4  to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW4_RUN_MASK           0xFFU

/**
 * It uses the OTP_VSW4  to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW4_RUN_SHIFT          0x00U

/**
 * 0.400000 V
 */
#define PF502X_F_VSW4_RUN_0_400000_V     (0x00U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.406250 V
 */
#define PF502X_F_VSW4_RUN_0_406250_V     (0x01U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.412500 V
 */
#define PF502X_F_VSW4_RUN_0_412500_V     (0x02U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.418750 V
 */
#define PF502X_F_VSW4_RUN_0_418750_V     (0x03U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.425000 V
 */
#define PF502X_F_VSW4_RUN_0_425000_V     (0x04U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.431250 V
 */
#define PF502X_F_VSW4_RUN_0_431250_V     (0x05U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.437500 V
 */
#define PF502X_F_VSW4_RUN_0_437500_V     (0x06U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.443750 V
 */
#define PF502X_F_VSW4_RUN_0_443750_V     (0x07U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.450000 V
 */
#define PF502X_F_VSW4_RUN_0_450000_V     (0x08U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.456250 V
 */
#define PF502X_F_VSW4_RUN_0_456250_V     (0x09U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.462500 V
 */
#define PF502X_F_VSW4_RUN_0_462500_V     (0x0AU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.468750 V
 */
#define PF502X_F_VSW4_RUN_0_468750_V     (0x0BU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.475000 V
 */
#define PF502X_F_VSW4_RUN_0_475000_V     (0x0CU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.481250 V
 */
#define PF502X_F_VSW4_RUN_0_481250_V     (0x0DU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.487500 V
 */
#define PF502X_F_VSW4_RUN_0_487500_V     (0x0EU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.493750 V
 */
#define PF502X_F_VSW4_RUN_0_493750_V     (0x0FU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.500000 V
 */
#define PF502X_F_VSW4_RUN_0_500000_V     (0x10U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.506250 V
 */
#define PF502X_F_VSW4_RUN_0_506250_V     (0x11U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.512500 V
 */
#define PF502X_F_VSW4_RUN_0_512500_V     (0x12U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.518750 V
 */
#define PF502X_F_VSW4_RUN_0_518750_V     (0x13U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.525000 V
 */
#define PF502X_F_VSW4_RUN_0_525000_V     (0x14U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.531250 V
 */
#define PF502X_F_VSW4_RUN_0_531250_V     (0x15U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.537500 V
 */
#define PF502X_F_VSW4_RUN_0_537500_V     (0x16U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.543750 V
 */
#define PF502X_F_VSW4_RUN_0_543750_V     (0x17U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.550000 V
 */
#define PF502X_F_VSW4_RUN_0_550000_V     (0x18U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.556250 V
 */
#define PF502X_F_VSW4_RUN_0_556250_V     (0x19U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.562500 V
 */
#define PF502X_F_VSW4_RUN_0_562500_V     (0x1AU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.568750 V
 */
#define PF502X_F_VSW4_RUN_0_568750_V     (0x1BU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.575000 V
 */
#define PF502X_F_VSW4_RUN_0_575000_V     (0x1CU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.581250 V
 */
#define PF502X_F_VSW4_RUN_0_581250_V     (0x1DU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.587500 V
 */
#define PF502X_F_VSW4_RUN_0_587500_V     (0x1EU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.593750 V
 */
#define PF502X_F_VSW4_RUN_0_593750_V     (0x1FU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.600000 V
 */
#define PF502X_F_VSW4_RUN_0_600000_V     (0x20U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.606250 V
 */
#define PF502X_F_VSW4_RUN_0_606250_V     (0x21U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.612500 V
 */
#define PF502X_F_VSW4_RUN_0_612500_V     (0x22U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.618750 V
 */
#define PF502X_F_VSW4_RUN_0_618750_V     (0x23U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.625000 V
 */
#define PF502X_F_VSW4_RUN_0_625000_V     (0x24U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.631250 V
 */
#define PF502X_F_VSW4_RUN_0_631250_V     (0x25U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.637500 V
 */
#define PF502X_F_VSW4_RUN_0_637500_V     (0x26U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.643750 V
 */
#define PF502X_F_VSW4_RUN_0_643750_V     (0x27U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.650000 V
 */
#define PF502X_F_VSW4_RUN_0_650000_V     (0x28U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.656250 V
 */
#define PF502X_F_VSW4_RUN_0_656250_V     (0x29U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.662500 V
 */
#define PF502X_F_VSW4_RUN_0_662500_V     (0x2AU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.668750 V
 */
#define PF502X_F_VSW4_RUN_0_668750_V     (0x2BU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.675000 V
 */
#define PF502X_F_VSW4_RUN_0_675000_V     (0x2CU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.681250 V
 */
#define PF502X_F_VSW4_RUN_0_681250_V     (0x2DU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.687500 V
 */
#define PF502X_F_VSW4_RUN_0_687500_V     (0x2EU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.693750 V
 */
#define PF502X_F_VSW4_RUN_0_693750_V     (0x2FU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.700000 V
 */
#define PF502X_F_VSW4_RUN_0_700000_V     (0x30U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.706250 V
 */
#define PF502X_F_VSW4_RUN_0_706250_V     (0x31U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.712500 V
 */
#define PF502X_F_VSW4_RUN_0_712500_V     (0x32U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.718750 V
 */
#define PF502X_F_VSW4_RUN_0_718750_V     (0x33U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.725000 V
 */
#define PF502X_F_VSW4_RUN_0_725000_V     (0x34U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.731250 V
 */
#define PF502X_F_VSW4_RUN_0_731250_V     (0x35U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.737500 V
 */
#define PF502X_F_VSW4_RUN_0_737500_V     (0x36U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.743750 V
 */
#define PF502X_F_VSW4_RUN_0_743750_V     (0x37U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.750000 V
 */
#define PF502X_F_VSW4_RUN_0_750000_V     (0x38U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.756250 V
 */
#define PF502X_F_VSW4_RUN_0_756250_V     (0x39U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.762500 V
 */
#define PF502X_F_VSW4_RUN_0_762500_V     (0x3AU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.768750 V
 */
#define PF502X_F_VSW4_RUN_0_768750_V     (0x3BU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.775000 V
 */
#define PF502X_F_VSW4_RUN_0_775000_V     (0x3CU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.781250 V
 */
#define PF502X_F_VSW4_RUN_0_781250_V     (0x3DU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.787500 V
 */
#define PF502X_F_VSW4_RUN_0_787500_V     (0x3EU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.793750 V
 */
#define PF502X_F_VSW4_RUN_0_793750_V     (0x3FU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.800000 V
 */
#define PF502X_F_VSW4_RUN_0_800000_V     (0x40U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.806250 V
 */
#define PF502X_F_VSW4_RUN_0_806250_V     (0x41U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.812500 V
 */
#define PF502X_F_VSW4_RUN_0_812500_V     (0x42U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.818750 V
 */
#define PF502X_F_VSW4_RUN_0_818750_V     (0x43U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.825000 V
 */
#define PF502X_F_VSW4_RUN_0_825000_V     (0x44U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.831250 V
 */
#define PF502X_F_VSW4_RUN_0_831250_V     (0x45U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.837500 V
 */
#define PF502X_F_VSW4_RUN_0_837500_V     (0x46U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.843750 V
 */
#define PF502X_F_VSW4_RUN_0_843750_V     (0x47U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.850000 V
 */
#define PF502X_F_VSW4_RUN_0_850000_V     (0x48U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.856250 V
 */
#define PF502X_F_VSW4_RUN_0_856250_V     (0x49U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.862500 V
 */
#define PF502X_F_VSW4_RUN_0_862500_V     (0x4AU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.868750 V
 */
#define PF502X_F_VSW4_RUN_0_868750_V     (0x4BU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.875000 V
 */
#define PF502X_F_VSW4_RUN_0_875000_V     (0x4CU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.881250 V
 */
#define PF502X_F_VSW4_RUN_0_881250_V     (0x4DU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.887500 V
 */
#define PF502X_F_VSW4_RUN_0_887500_V     (0x4EU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.893750 V
 */
#define PF502X_F_VSW4_RUN_0_893750_V     (0x4FU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.900000 V
 */
#define PF502X_F_VSW4_RUN_0_900000_V     (0x50U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.906250 V
 */
#define PF502X_F_VSW4_RUN_0_906250_V     (0x51U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.912500 V
 */
#define PF502X_F_VSW4_RUN_0_912500_V     (0x52U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.918750 V
 */
#define PF502X_F_VSW4_RUN_0_918750_V     (0x53U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.925000 V
 */
#define PF502X_F_VSW4_RUN_0_925000_V     (0x54U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.931250 V
 */
#define PF502X_F_VSW4_RUN_0_931250_V     (0x55U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.937500 V
 */
#define PF502X_F_VSW4_RUN_0_937500_V     (0x56U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.943750 V
 */
#define PF502X_F_VSW4_RUN_0_943750_V     (0x57U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.950000 V
 */
#define PF502X_F_VSW4_RUN_0_950000_V     (0x58U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.956250 V
 */
#define PF502X_F_VSW4_RUN_0_956250_V     (0x59U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.962500 V
 */
#define PF502X_F_VSW4_RUN_0_962500_V     (0x5AU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.968750 V
 */
#define PF502X_F_VSW4_RUN_0_968750_V     (0x5BU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.975000 V
 */
#define PF502X_F_VSW4_RUN_0_975000_V     (0x5CU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.981250 V
 */
#define PF502X_F_VSW4_RUN_0_981250_V     (0x5DU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.987500 V
 */
#define PF502X_F_VSW4_RUN_0_987500_V     (0x5EU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 0.993750 V
 */
#define PF502X_F_VSW4_RUN_0_993750_V     (0x5FU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.000000 V
 */
#define PF502X_F_VSW4_RUN_1_000000_V     (0x60U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.006250 V
 */
#define PF502X_F_VSW4_RUN_1_006250_V     (0x61U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.012500 V
 */
#define PF502X_F_VSW4_RUN_1_012500_V     (0x62U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.018750 V
 */
#define PF502X_F_VSW4_RUN_1_018750_V     (0x63U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.025000 V
 */
#define PF502X_F_VSW4_RUN_1_025000_V     (0x64U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.031250 V
 */
#define PF502X_F_VSW4_RUN_1_031250_V     (0x65U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.037500 V
 */
#define PF502X_F_VSW4_RUN_1_037500_V     (0x66U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.043750 V
 */
#define PF502X_F_VSW4_RUN_1_043750_V     (0x67U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.050000 V
 */
#define PF502X_F_VSW4_RUN_1_050000_V     (0x68U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.056250 V
 */
#define PF502X_F_VSW4_RUN_1_056250_V     (0x69U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.062500 V
 */
#define PF502X_F_VSW4_RUN_1_062500_V     (0x6AU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.068750 V
 */
#define PF502X_F_VSW4_RUN_1_068750_V     (0x6BU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.075000 V
 */
#define PF502X_F_VSW4_RUN_1_075000_V     (0x6CU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.081250 V
 */
#define PF502X_F_VSW4_RUN_1_081250_V     (0x6DU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.087500 V
 */
#define PF502X_F_VSW4_RUN_1_087500_V     (0x6EU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.093750 V
 */
#define PF502X_F_VSW4_RUN_1_093750_V     (0x6FU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.100000 V
 */
#define PF502X_F_VSW4_RUN_1_100000_V     (0x70U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.106250 V
 */
#define PF502X_F_VSW4_RUN_1_106250_V     (0x71U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.112500 V
 */
#define PF502X_F_VSW4_RUN_1_112500_V     (0x72U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.118750 V
 */
#define PF502X_F_VSW4_RUN_1_118750_V     (0x73U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.125000 V
 */
#define PF502X_F_VSW4_RUN_1_125000_V     (0x74U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.131250 V
 */
#define PF502X_F_VSW4_RUN_1_131250_V     (0x75U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.137500 V
 */
#define PF502X_F_VSW4_RUN_1_137500_V     (0x76U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.143750 V
 */
#define PF502X_F_VSW4_RUN_1_143750_V     (0x77U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.150000 V
 */
#define PF502X_F_VSW4_RUN_1_150000_V     (0x78U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.156250 V
 */
#define PF502X_F_VSW4_RUN_1_156250_V     (0x79U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.162500 V
 */
#define PF502X_F_VSW4_RUN_1_162500_V     (0x7AU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.168750 V
 */
#define PF502X_F_VSW4_RUN_1_168750_V     (0x7BU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.175000 V
 */
#define PF502X_F_VSW4_RUN_1_175000_V     (0x7CU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.181250 V
 */
#define PF502X_F_VSW4_RUN_1_181250_V     (0x7DU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.187500 V
 */
#define PF502X_F_VSW4_RUN_1_187500_V     (0x7EU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.193750 V
 */
#define PF502X_F_VSW4_RUN_1_193750_V     (0x7FU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.200000 V
 */
#define PF502X_F_VSW4_RUN_1_200000_V     (0x80U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.206250 V
 */
#define PF502X_F_VSW4_RUN_1_206250_V     (0x81U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.212500 V
 */
#define PF502X_F_VSW4_RUN_1_212500_V     (0x82U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.218750 V
 */
#define PF502X_F_VSW4_RUN_1_218750_V     (0x83U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.225000 V
 */
#define PF502X_F_VSW4_RUN_1_225000_V     (0x84U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.231250 V
 */
#define PF502X_F_VSW4_RUN_1_231250_V     (0x85U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.237500 V
 */
#define PF502X_F_VSW4_RUN_1_237500_V     (0x86U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.243750 V
 */
#define PF502X_F_VSW4_RUN_1_243750_V     (0x87U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.250000 V
 */
#define PF502X_F_VSW4_RUN_1_250000_V     (0x88U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.256250 V
 */
#define PF502X_F_VSW4_RUN_1_256250_V     (0x89U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.262500 V
 */
#define PF502X_F_VSW4_RUN_1_262500_V     (0x8AU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.268750 V
 */
#define PF502X_F_VSW4_RUN_1_268750_V     (0x8BU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.275000 V
 */
#define PF502X_F_VSW4_RUN_1_275000_V     (0x8CU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.281250 V
 */
#define PF502X_F_VSW4_RUN_1_281250_V     (0x8DU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.287500 V
 */
#define PF502X_F_VSW4_RUN_1_287500_V     (0x8EU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.293750 V
 */
#define PF502X_F_VSW4_RUN_1_293750_V     (0x8FU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.300000 V
 */
#define PF502X_F_VSW4_RUN_1_300000_V     (0x90U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.306250 V
 */
#define PF502X_F_VSW4_RUN_1_306250_V     (0x91U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.312500 V
 */
#define PF502X_F_VSW4_RUN_1_312500_V     (0x92U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.318750 V
 */
#define PF502X_F_VSW4_RUN_1_318750_V     (0x93U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.325000 V
 */
#define PF502X_F_VSW4_RUN_1_325000_V     (0x94U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.331250 V
 */
#define PF502X_F_VSW4_RUN_1_331250_V     (0x95U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.337500 V
 */
#define PF502X_F_VSW4_RUN_1_337500_V     (0x96U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.343750 V
 */
#define PF502X_F_VSW4_RUN_1_343750_V     (0x97U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.350000 V
 */
#define PF502X_F_VSW4_RUN_1_350000_V     (0x98U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.356250 V
 */
#define PF502X_F_VSW4_RUN_1_356250_V     (0x99U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.362500 V
 */
#define PF502X_F_VSW4_RUN_1_362500_V     (0x9AU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.368750 V
 */
#define PF502X_F_VSW4_RUN_1_368750_V     (0x9BU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.375000 V
 */
#define PF502X_F_VSW4_RUN_1_375000_V     (0x9CU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.381250 V
 */
#define PF502X_F_VSW4_RUN_1_381250_V     (0x9DU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.387500 V
 */
#define PF502X_F_VSW4_RUN_1_387500_V     (0x9EU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.393750 V
 */
#define PF502X_F_VSW4_RUN_1_393750_V     (0x9FU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.400000 V
 */
#define PF502X_F_VSW4_RUN_1_400000_V     (0xA0U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.406250 V
 */
#define PF502X_F_VSW4_RUN_1_406250_V     (0xA1U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.412500 V
 */
#define PF502X_F_VSW4_RUN_1_412500_V     (0xA2U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.418750 V
 */
#define PF502X_F_VSW4_RUN_1_418750_V     (0xA3U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.425000 V
 */
#define PF502X_F_VSW4_RUN_1_425000_V     (0xA4U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.431250 V
 */
#define PF502X_F_VSW4_RUN_1_431250_V     (0xA5U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.437500 V
 */
#define PF502X_F_VSW4_RUN_1_437500_V     (0xA6U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.443750 V
 */
#define PF502X_F_VSW4_RUN_1_443750_V     (0xA7U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.450000 V
 */
#define PF502X_F_VSW4_RUN_1_450000_V     (0xA8U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.456250 V
 */
#define PF502X_F_VSW4_RUN_1_456250_V     (0xA9U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.462500 V
 */
#define PF502X_F_VSW4_RUN_1_462500_V     (0xAAU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.468750 V
 */
#define PF502X_F_VSW4_RUN_1_468750_V     (0xABU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.475000 V
 */
#define PF502X_F_VSW4_RUN_1_475000_V     (0xACU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.481250 V
 */
#define PF502X_F_VSW4_RUN_1_481250_V     (0xADU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.487500 V
 */
#define PF502X_F_VSW4_RUN_1_487500_V     (0xAEU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.493750 V
 */
#define PF502X_F_VSW4_RUN_1_493750_V     (0xAFU << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.500000 V
 */
#define PF502X_F_VSW4_RUN_1_500000_V     (0xB0U << PF502X_F_VSW4_RUN_SHIFT)
/**
 * 1.80000 V
 */
#define PF502X_F_VSW4_RUN_1_80000_V      (0xB1U << PF502X_F_VSW4_RUN_SHIFT)

/******************************************************************************/
/* SW4_STBY_VOLT - Type: RW                                                   */
/******************************************************************************/

#define PF502X_SW4_STBY_VOLT_ADDR        0x64U
#define PF502X_SW4_STBY_VOLT_DEFAULT     0x00U

/**
 * It uses the OTP_VSW4 to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW4_STBY_MASK          0xFFU

/**
 * It uses the OTP_VSW4 to load the Default Voltage upon Power up
 */
#define PF502X_F_VSW4_STBY_SHIFT         0x00U

/**
 * 0.400000 V
 */
#define PF502X_F_VSW4_STBY_0_400000_V    (0x00U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.406250 V
 */
#define PF502X_F_VSW4_STBY_0_406250_V    (0x01U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.412500 V
 */
#define PF502X_F_VSW4_STBY_0_412500_V    (0x02U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.418750 V
 */
#define PF502X_F_VSW4_STBY_0_418750_V    (0x03U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.425000 V
 */
#define PF502X_F_VSW4_STBY_0_425000_V    (0x04U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.431250 V
 */
#define PF502X_F_VSW4_STBY_0_431250_V    (0x05U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.437500 V
 */
#define PF502X_F_VSW4_STBY_0_437500_V    (0x06U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.443750 V
 */
#define PF502X_F_VSW4_STBY_0_443750_V    (0x07U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.450000 V
 */
#define PF502X_F_VSW4_STBY_0_450000_V    (0x08U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.456250 V
 */
#define PF502X_F_VSW4_STBY_0_456250_V    (0x09U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.462500 V
 */
#define PF502X_F_VSW4_STBY_0_462500_V    (0x0AU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.468750 V
 */
#define PF502X_F_VSW4_STBY_0_468750_V    (0x0BU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.475000 V
 */
#define PF502X_F_VSW4_STBY_0_475000_V    (0x0CU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.481250 V
 */
#define PF502X_F_VSW4_STBY_0_481250_V    (0x0DU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.487500 V
 */
#define PF502X_F_VSW4_STBY_0_487500_V    (0x0EU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.493750 V
 */
#define PF502X_F_VSW4_STBY_0_493750_V    (0x0FU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.500000 V
 */
#define PF502X_F_VSW4_STBY_0_500000_V    (0x10U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.506250 V
 */
#define PF502X_F_VSW4_STBY_0_506250_V    (0x11U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.512500 V
 */
#define PF502X_F_VSW4_STBY_0_512500_V    (0x12U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.518750 V
 */
#define PF502X_F_VSW4_STBY_0_518750_V    (0x13U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.525000 V
 */
#define PF502X_F_VSW4_STBY_0_525000_V    (0x14U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.531250 V
 */
#define PF502X_F_VSW4_STBY_0_531250_V    (0x15U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.537500 V
 */
#define PF502X_F_VSW4_STBY_0_537500_V    (0x16U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.543750 V
 */
#define PF502X_F_VSW4_STBY_0_543750_V    (0x17U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.550000 V
 */
#define PF502X_F_VSW4_STBY_0_550000_V    (0x18U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.556250 V
 */
#define PF502X_F_VSW4_STBY_0_556250_V    (0x19U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.562500 V
 */
#define PF502X_F_VSW4_STBY_0_562500_V    (0x1AU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.568750 V
 */
#define PF502X_F_VSW4_STBY_0_568750_V    (0x1BU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.575000 V
 */
#define PF502X_F_VSW4_STBY_0_575000_V    (0x1CU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.581250 V
 */
#define PF502X_F_VSW4_STBY_0_581250_V    (0x1DU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.587500 V
 */
#define PF502X_F_VSW4_STBY_0_587500_V    (0x1EU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.593750 V
 */
#define PF502X_F_VSW4_STBY_0_593750_V    (0x1FU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.600000 V
 */
#define PF502X_F_VSW4_STBY_0_600000_V    (0x20U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.606250 V
 */
#define PF502X_F_VSW4_STBY_0_606250_V    (0x21U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.612500 V
 */
#define PF502X_F_VSW4_STBY_0_612500_V    (0x22U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.618750 V
 */
#define PF502X_F_VSW4_STBY_0_618750_V    (0x23U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.625000 V
 */
#define PF502X_F_VSW4_STBY_0_625000_V    (0x24U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.631250 V
 */
#define PF502X_F_VSW4_STBY_0_631250_V    (0x25U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.637500 V
 */
#define PF502X_F_VSW4_STBY_0_637500_V    (0x26U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.643750 V
 */
#define PF502X_F_VSW4_STBY_0_643750_V    (0x27U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.650000 V
 */
#define PF502X_F_VSW4_STBY_0_650000_V    (0x28U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.656250 V
 */
#define PF502X_F_VSW4_STBY_0_656250_V    (0x29U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.662500 V
 */
#define PF502X_F_VSW4_STBY_0_662500_V    (0x2AU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.668750 V
 */
#define PF502X_F_VSW4_STBY_0_668750_V    (0x2BU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.675000 V
 */
#define PF502X_F_VSW4_STBY_0_675000_V    (0x2CU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.681250 V
 */
#define PF502X_F_VSW4_STBY_0_681250_V    (0x2DU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.687500 V
 */
#define PF502X_F_VSW4_STBY_0_687500_V    (0x2EU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.693750 V
 */
#define PF502X_F_VSW4_STBY_0_693750_V    (0x2FU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.700000 V
 */
#define PF502X_F_VSW4_STBY_0_700000_V    (0x30U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.706250 V
 */
#define PF502X_F_VSW4_STBY_0_706250_V    (0x31U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.712500 V
 */
#define PF502X_F_VSW4_STBY_0_712500_V    (0x32U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.718750 V
 */
#define PF502X_F_VSW4_STBY_0_718750_V    (0x33U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.725000 V
 */
#define PF502X_F_VSW4_STBY_0_725000_V    (0x34U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.731250 V
 */
#define PF502X_F_VSW4_STBY_0_731250_V    (0x35U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.737500 V
 */
#define PF502X_F_VSW4_STBY_0_737500_V    (0x36U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.743750 V
 */
#define PF502X_F_VSW4_STBY_0_743750_V    (0x37U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.750000 V
 */
#define PF502X_F_VSW4_STBY_0_750000_V    (0x38U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.756250 V
 */
#define PF502X_F_VSW4_STBY_0_756250_V    (0x39U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.762500 V
 */
#define PF502X_F_VSW4_STBY_0_762500_V    (0x3AU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.768750 V
 */
#define PF502X_F_VSW4_STBY_0_768750_V    (0x3BU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.775000 V
 */
#define PF502X_F_VSW4_STBY_0_775000_V    (0x3CU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.781250 V
 */
#define PF502X_F_VSW4_STBY_0_781250_V    (0x3DU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.787500 V
 */
#define PF502X_F_VSW4_STBY_0_787500_V    (0x3EU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.793750 V
 */
#define PF502X_F_VSW4_STBY_0_793750_V    (0x3FU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.800000 V
 */
#define PF502X_F_VSW4_STBY_0_800000_V    (0x40U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.806250 V
 */
#define PF502X_F_VSW4_STBY_0_806250_V    (0x41U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.812500 V
 */
#define PF502X_F_VSW4_STBY_0_812500_V    (0x42U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.818750 V
 */
#define PF502X_F_VSW4_STBY_0_818750_V    (0x43U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.825000 V
 */
#define PF502X_F_VSW4_STBY_0_825000_V    (0x44U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.831250 V
 */
#define PF502X_F_VSW4_STBY_0_831250_V    (0x45U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.837500 V
 */
#define PF502X_F_VSW4_STBY_0_837500_V    (0x46U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.843750 V
 */
#define PF502X_F_VSW4_STBY_0_843750_V    (0x47U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.850000 V
 */
#define PF502X_F_VSW4_STBY_0_850000_V    (0x48U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.856250 V
 */
#define PF502X_F_VSW4_STBY_0_856250_V    (0x49U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.862500 V
 */
#define PF502X_F_VSW4_STBY_0_862500_V    (0x4AU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.868750 V
 */
#define PF502X_F_VSW4_STBY_0_868750_V    (0x4BU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.875000 V
 */
#define PF502X_F_VSW4_STBY_0_875000_V    (0x4CU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.881250 V
 */
#define PF502X_F_VSW4_STBY_0_881250_V    (0x4DU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.887500 V
 */
#define PF502X_F_VSW4_STBY_0_887500_V    (0x4EU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.893750 V
 */
#define PF502X_F_VSW4_STBY_0_893750_V    (0x4FU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.900000 V
 */
#define PF502X_F_VSW4_STBY_0_900000_V    (0x50U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.906250 V
 */
#define PF502X_F_VSW4_STBY_0_906250_V    (0x51U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.912500 V
 */
#define PF502X_F_VSW4_STBY_0_912500_V    (0x52U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.918750 V
 */
#define PF502X_F_VSW4_STBY_0_918750_V    (0x53U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.925000 V
 */
#define PF502X_F_VSW4_STBY_0_925000_V    (0x54U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.931250 V
 */
#define PF502X_F_VSW4_STBY_0_931250_V    (0x55U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.937500 V
 */
#define PF502X_F_VSW4_STBY_0_937500_V    (0x56U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.943750 V
 */
#define PF502X_F_VSW4_STBY_0_943750_V    (0x57U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.950000 V
 */
#define PF502X_F_VSW4_STBY_0_950000_V    (0x58U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.956250 V
 */
#define PF502X_F_VSW4_STBY_0_956250_V    (0x59U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.962500 V
 */
#define PF502X_F_VSW4_STBY_0_962500_V    (0x5AU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.968750 V
 */
#define PF502X_F_VSW4_STBY_0_968750_V    (0x5BU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.975000 V
 */
#define PF502X_F_VSW4_STBY_0_975000_V    (0x5CU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.981250 V
 */
#define PF502X_F_VSW4_STBY_0_981250_V    (0x5DU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.987500 V
 */
#define PF502X_F_VSW4_STBY_0_987500_V    (0x5EU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 0.993750 V
 */
#define PF502X_F_VSW4_STBY_0_993750_V    (0x5FU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.000000 V
 */
#define PF502X_F_VSW4_STBY_1_000000_V    (0x60U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.006250 V
 */
#define PF502X_F_VSW4_STBY_1_006250_V    (0x61U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.012500 V
 */
#define PF502X_F_VSW4_STBY_1_012500_V    (0x62U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.018750 V
 */
#define PF502X_F_VSW4_STBY_1_018750_V    (0x63U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.025000 V
 */
#define PF502X_F_VSW4_STBY_1_025000_V    (0x64U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.031250 V
 */
#define PF502X_F_VSW4_STBY_1_031250_V    (0x65U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.037500 V
 */
#define PF502X_F_VSW4_STBY_1_037500_V    (0x66U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.043750 V
 */
#define PF502X_F_VSW4_STBY_1_043750_V    (0x67U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.050000 V
 */
#define PF502X_F_VSW4_STBY_1_050000_V    (0x68U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.056250 V
 */
#define PF502X_F_VSW4_STBY_1_056250_V    (0x69U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.062500 V
 */
#define PF502X_F_VSW4_STBY_1_062500_V    (0x6AU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.068750 V
 */
#define PF502X_F_VSW4_STBY_1_068750_V    (0x6BU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.075000 V
 */
#define PF502X_F_VSW4_STBY_1_075000_V    (0x6CU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.081250 V
 */
#define PF502X_F_VSW4_STBY_1_081250_V    (0x6DU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.087500 V
 */
#define PF502X_F_VSW4_STBY_1_087500_V    (0x6EU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.093750 V
 */
#define PF502X_F_VSW4_STBY_1_093750_V    (0x6FU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.100000 V
 */
#define PF502X_F_VSW4_STBY_1_100000_V    (0x70U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.106250 V
 */
#define PF502X_F_VSW4_STBY_1_106250_V    (0x71U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.112500 V
 */
#define PF502X_F_VSW4_STBY_1_112500_V    (0x72U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.118750 V
 */
#define PF502X_F_VSW4_STBY_1_118750_V    (0x73U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.125000 V
 */
#define PF502X_F_VSW4_STBY_1_125000_V    (0x74U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.131250 V
 */
#define PF502X_F_VSW4_STBY_1_131250_V    (0x75U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.137500 V
 */
#define PF502X_F_VSW4_STBY_1_137500_V    (0x76U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.143750 V
 */
#define PF502X_F_VSW4_STBY_1_143750_V    (0x77U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.150000 V
 */
#define PF502X_F_VSW4_STBY_1_150000_V    (0x78U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.156250 V
 */
#define PF502X_F_VSW4_STBY_1_156250_V    (0x79U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.162500 V
 */
#define PF502X_F_VSW4_STBY_1_162500_V    (0x7AU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.168750 V
 */
#define PF502X_F_VSW4_STBY_1_168750_V    (0x7BU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.175000 V
 */
#define PF502X_F_VSW4_STBY_1_175000_V    (0x7CU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.181250 V
 */
#define PF502X_F_VSW4_STBY_1_181250_V    (0x7DU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.187500 V
 */
#define PF502X_F_VSW4_STBY_1_187500_V    (0x7EU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.193750 V
 */
#define PF502X_F_VSW4_STBY_1_193750_V    (0x7FU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.200000 V
 */
#define PF502X_F_VSW4_STBY_1_200000_V    (0x80U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.206250 V
 */
#define PF502X_F_VSW4_STBY_1_206250_V    (0x81U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.212500 V
 */
#define PF502X_F_VSW4_STBY_1_212500_V    (0x82U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.218750 V
 */
#define PF502X_F_VSW4_STBY_1_218750_V    (0x83U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.225000 V
 */
#define PF502X_F_VSW4_STBY_1_225000_V    (0x84U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.231250 V
 */
#define PF502X_F_VSW4_STBY_1_231250_V    (0x85U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.237500 V
 */
#define PF502X_F_VSW4_STBY_1_237500_V    (0x86U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.243750 V
 */
#define PF502X_F_VSW4_STBY_1_243750_V    (0x87U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.250000 V
 */
#define PF502X_F_VSW4_STBY_1_250000_V    (0x88U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.256250 V
 */
#define PF502X_F_VSW4_STBY_1_256250_V    (0x89U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.262500 V
 */
#define PF502X_F_VSW4_STBY_1_262500_V    (0x8AU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.268750 V
 */
#define PF502X_F_VSW4_STBY_1_268750_V    (0x8BU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.275000 V
 */
#define PF502X_F_VSW4_STBY_1_275000_V    (0x8CU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.281250 V
 */
#define PF502X_F_VSW4_STBY_1_281250_V    (0x8DU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.287500 V
 */
#define PF502X_F_VSW4_STBY_1_287500_V    (0x8EU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.293750 V
 */
#define PF502X_F_VSW4_STBY_1_293750_V    (0x8FU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.300000 V
 */
#define PF502X_F_VSW4_STBY_1_300000_V    (0x90U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.306250 V
 */
#define PF502X_F_VSW4_STBY_1_306250_V    (0x91U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.312500 V
 */
#define PF502X_F_VSW4_STBY_1_312500_V    (0x92U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.318750 V
 */
#define PF502X_F_VSW4_STBY_1_318750_V    (0x93U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.325000 V
 */
#define PF502X_F_VSW4_STBY_1_325000_V    (0x94U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.331250 V
 */
#define PF502X_F_VSW4_STBY_1_331250_V    (0x95U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.337500 V
 */
#define PF502X_F_VSW4_STBY_1_337500_V    (0x96U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.343750 V
 */
#define PF502X_F_VSW4_STBY_1_343750_V    (0x97U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.350000 V
 */
#define PF502X_F_VSW4_STBY_1_350000_V    (0x98U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.356250 V
 */
#define PF502X_F_VSW4_STBY_1_356250_V    (0x99U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.362500 V
 */
#define PF502X_F_VSW4_STBY_1_362500_V    (0x9AU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.368750 V
 */
#define PF502X_F_VSW4_STBY_1_368750_V    (0x9BU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.375000 V
 */
#define PF502X_F_VSW4_STBY_1_375000_V    (0x9CU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.381250 V
 */
#define PF502X_F_VSW4_STBY_1_381250_V    (0x9DU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.387500 V
 */
#define PF502X_F_VSW4_STBY_1_387500_V    (0x9EU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.393750 V
 */
#define PF502X_F_VSW4_STBY_1_393750_V    (0x9FU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.400000 V
 */
#define PF502X_F_VSW4_STBY_1_400000_V    (0xA0U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.406250 V
 */
#define PF502X_F_VSW4_STBY_1_406250_V    (0xA1U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.412500 V
 */
#define PF502X_F_VSW4_STBY_1_412500_V    (0xA2U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.418750 V
 */
#define PF502X_F_VSW4_STBY_1_418750_V    (0xA3U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.425000 V
 */
#define PF502X_F_VSW4_STBY_1_425000_V    (0xA4U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.431250 V
 */
#define PF502X_F_VSW4_STBY_1_431250_V    (0xA5U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.437500 V
 */
#define PF502X_F_VSW4_STBY_1_437500_V    (0xA6U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.443750 V
 */
#define PF502X_F_VSW4_STBY_1_443750_V    (0xA7U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.450000 V
 */
#define PF502X_F_VSW4_STBY_1_450000_V    (0xA8U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.456250 V
 */
#define PF502X_F_VSW4_STBY_1_456250_V    (0xA9U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.462500 V
 */
#define PF502X_F_VSW4_STBY_1_462500_V    (0xAAU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.468750 V
 */
#define PF502X_F_VSW4_STBY_1_468750_V    (0xABU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.475000 V
 */
#define PF502X_F_VSW4_STBY_1_475000_V    (0xACU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.481250 V
 */
#define PF502X_F_VSW4_STBY_1_481250_V    (0xADU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.487500 V
 */
#define PF502X_F_VSW4_STBY_1_487500_V    (0xAEU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.493750 V
 */
#define PF502X_F_VSW4_STBY_1_493750_V    (0xAFU << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.500000 V
 */
#define PF502X_F_VSW4_STBY_1_500000_V    (0xB0U << PF502X_F_VSW4_STBY_SHIFT)
/**
 * 1.80000 V
 */
#define PF502X_F_VSW4_STBY_1_80000_V     (0xB1U << PF502X_F_VSW4_STBY_SHIFT)

/******************************************************************************/
/* VSNVS_CONFIG1 - Type: RW                                                   */
/******************************************************************************/

#define PF502X_VSNVS_CONFIG1_ADDR        0x75U
#define PF502X_VSNVS_CONFIG1_DEFAULT     0x00U

/**
 * Selects VSNVS output voltage
 */
#define PF502X_F_VSNVSVOLT_MASK          0x03U

/**
 * Selects VSNVS output voltage
 */
#define PF502X_F_VSNVSVOLT_SHIFT         0x00U

/**
 * OFF
 */
#define PF502X_F_VSNVSVOLT_OFF           (0x00U << PF502X_F_VSNVSVOLT_SHIFT)
/**
 * 1.8V
 */
#define PF502X_F_VSNVSVOLT_1_8_V         (0x01U << PF502X_F_VSNVSVOLT_SHIFT)
/**
 * 3.0V
 */
#define PF502X_F_VSNVSVOLT_3_0_V         (0x02U << PF502X_F_VSNVSVOLT_SHIFT)
/**
 * 3.3V
 */
#define PF502X_F_VSNVSVOLT_3_3_V         (0x03U << PF502X_F_VSNVSVOLT_SHIFT)

/******************************************************************************/
/* PAGE_SELECT - Type: RW                                                     */
/******************************************************************************/

#define PF502X_PAGE_SELECT_ADDR          0x77U
#define PF502X_PAGE_SELECT_DEFAULT       0x00U

/**
 * Select the I2C register page for TBB/OTP configuration and Test features.
 */
#define PF502X_F_PAGE_MASK               0x07U

/**
 * Select the I2C register page for TBB/OTP configuration and Test features.
 */
#define PF502X_F_PAGE_SHIFT              0x00U

/**
 * Functional Page selected (no extended page active)
 */
#define PF502X_F_PAGE_FUNCTIONAL_PAGE    (0x00U << PF502X_F_PAGE_SHIFT)
/**
 * OTP Mirror Registers
 */
#define PF502X_F_PAGE_OTP_MIRROR_REGISTERS (0x01U << PF502X_F_PAGE_SHIFT)
/**
 * OTP Misc Control
 */
#define PF502X_F_PAGE_OTP_MISC_CONTROL   (0x02U << PF502X_F_PAGE_SHIFT)



#endif /* PMIC_PF5024_MAP_H__ */
