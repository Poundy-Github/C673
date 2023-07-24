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
 * @file pmic_pf502x.h
 * @brief Definitions of I2C communication logic for NXP PMIC PF502x.
 *
 * @author nxa22158, nxa23158
 * @version 1.0
 * @date 18-December-2020
 * @copyright Copyright (c) 2021 NXP
 */

#ifndef PMIC_PF502X_H_
#define PMIC_PF502X_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <pmic_pf502x_common.h>
#include <stdint.h>
#include <stdbool.h>

#if PF502X_DEVICE == PF502X_DEVICE_PF5020
#include <pmic_pf5020_map.h>
#elif PF502X_DEVICE == PF502X_DEVICE_PF5023
#include <pmic_pf5023_map.h>
#elif PF502X_DEVICE == PF502X_DEVICE_PF5024
#include <pmic_pf5024_map.h>
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup EnumsDefs Enums definition
 * @{ */
/** @brief Buck regulator. */
typedef enum
{
    pf502xRegBuckSW1 = 0U,     /**< SW1 buck. Applicable for PF5020, PF5023, PF5024. */
    pf502xRegBuckSW2 = 1U,     /**< SW2 buck. Applicable for PF5020, PF5023, PF5024. */
    pf502xRegBuckSW3 = 2U,     /**< SW3 buck. Applicable for PF5023, PF5024.*/
    pf502xRegBuckSW4 = 3U,     /**< SW4 buck. Applicable for PF5024.*/
	pf502xRegBuckSWND = 4U     /**< SWND buck. Applicable for PF5020. */
} pf502x_reg_buck_t;

#ifdef PF502X_LDO_FEATURE
/** @brief LDO regulator. */
typedef enum
{
    pf502xRegLdo1 = 0U         /**< LDO1. */
} pf502x_reg_ldo_t;
#endif

/** @brief Regulator state. */
typedef enum
{
    pf502xRegStateRun     = 0U, /**< Run state. */
    pf502xRegStateStandby = 1U  /**< Standby state. */
} pf502x_reg_state_t;

/** @brief Regulator mode. */
typedef enum
{
    pf502xRegModeOff = 0U,     /**< OFF mode. */
    pf502xRegModePwm = 1U,     /**< PWM mode. */
    pf502xRegModePfm = 2U,     /**< PFM mode. */
    pf502xRegModeAutoskip = 3U /**< Autoskip mode. */
} pf502x_reg_mode_t;

/** @brief Regulator power down group. */
typedef enum
{
    pf502xRegPdGroup4 = 0U,    /**< Power down group 4. */
    pf502xRegPdGroup3 = 1U,    /**< Power down group 3. */
    pf502xRegPdGroup2 = 2U,    /**< Power down group 2. */
    pf502xRegPdGroup1 = 3U     /**< Power down group 1. */
} pf502x_reg_powerdown_t;

/** @brief Pin/regulator power sequence. */
typedef enum
{
    pf502xPinRegResetbMcu = PF502X_RESETBMCU_PWRUP_ADDR, /**< RESETBMCU. */
    pf502xPinRegPgood = PF502X_PGOOD_PWRUP_ADDR,         /**< PGOOD. */
    pf502xPinRegSw1 = PF502X_SW1_PWRUP_ADDR,             /**< BUCK SW1. */
    pf502xPinRegSw2 = PF502X_SW2_PWRUP_ADDR,             /**< BUCK SW2. */
#if (PF502X_DEVICE == PF502X_DEVICE_PF5023) || (PF502X_DEVICE == PF502X_DEVICE_PF5024)
    pf502xPinRegSw3 = PF502X_SW3_PWRUP_ADDR,             /**< BUCK SW3. */
#endif
#if PF502X_DEVICE == PF502X_DEVICE_PF5024
    pf502xPinRegSw4 = PF502X_SW4_PWRUP_ADDR,             /**< BUCK SW4. */
#endif
#if PF502X_DEVICE == PF502X_DEVICE_PF5020
	pf502xPinRegSwnd = PF502X_SWND1_CONFIG1_ADDR,	     /**< BUCK SWND. */
    pf502xPinRegLdo1 = PF502X_LDO1_PWRUP_ADDR            /**< LDO1. */
#endif
} px5x_pin_reg_t;

/** @brief Sync frequency range. */
typedef enum
{
    /**< 2000 kHz to 3000 kHz. */
    pf502xFsyncRangeHigh = PF502X_F_FSYNC_RANGE_2000_KHZ_3000_KHZ,
    /**< 333 kHz to 500 kHz. */
    pf502xFsyncRangeLow = PF502X_F_FSYNC_RANGE_333_KHZ_500_KHZ
} pf502x_fsync_range_t;

/** @brief FSS range. */
typedef enum
{
    pf502xFssRangeNarrow = PF502X_F_FSS_RANGE_5, /**< +/- 5% range. */
    pf502xFssRangeWide = PF502X_F_FSS_RANGE_10   /**< +/- 10% range. */
} pf502x_fss_range_t;

/** @brief VIN_OVLO debounce. */
typedef enum
{
    pf502xOvloDbnc10us = PF502X_F_VIN_OVLO_DBNC_10_US,    /**< Debounce 10 us. */
    pf502xOvloDbnc100us = PF502X_F_VIN_OVLO_DBNC_100_US,  /**< Debounce 100 us. */
    pf502xOvloDbnc1000us = PF502X_F_VIN_OVLO_DBNC_1000_US /**< Debounce 1000 us. */
} pf502x_ovlo_dbnc_t;

/** @brief Interrupt group. */
typedef enum
{
    pf502xIntGroupStatus1 = PF502X_INT_STATUS1_ADDR,  /**< INT_STATUS1 interrupts. */
    pf502xIntGroupStatus2 = PF502X_INT_STATUS2_ADDR,  /**< INT_STATUS2 interrupts. */
    pf502xIntGroupSwMode = PF502X_SW_MODE_INT_ADDR,   /**< SW_MODE interrupts. */
    pf502xIntGroupSwIlim = PF502X_SW_ILIM_INT_ADDR,   /**< SW_ILIM interrupts. */
#ifdef PF502X_LDO_FEATURE
    pf502xIntGroupLdoIlim = PF502X_LDO_ILIM_INT_ADDR, /**< LDO_ILIM interrupts. */
#endif
    pf502xIntGroupSwUv = PF502X_SW_UV_INT_ADDR,       /**< SW_UV interrupts. */
    pf502xIntGroupSwOv = PF502X_SW_OV_INT_ADDR,       /**< SW_OV interrupts. */
#ifdef PF502X_LDO_FEATURE
    pf502xIntGroupLdoUv = PF502X_LDO_UV_INT_ADDR,     /**< LDO_UV interrupts. */
    pf502xIntGroupLdoOv = PF502X_LDO_OV_INT_ADDR,     /**< LDO_OV interrupts. */
#endif
    pf502xIntGroupPwron = PF502X_PWRON_INT_ADDR,      /**< PWRON interrupts. */
    pf502xIntGroupSysInt = PF502X_SYS_INT_ADDR        /**< SYS_INT interrupts. */
} pf502x_int_group_t;
/** @} */

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes of extern functions
 ******************************************************************************/
/** @defgroup Extern MCU specific functions
 * @brief Functions in this group must be implemented by the user.
 * @{ */
/** @brief This function sends single frame to I2C bus.
 *         MCU specific.
 *
 * This function must be implemented when I2C communication is used. The txFrame must be
 * sent to the I2C bus from the last byte to the first (e.g. txFrame[0] will be sent last).
 *
 * @warning This function must be implemented as blocking as there is not synchronization
 * mechanism implemented in the driver.
 *
 * @param [in] txFrame          Frame to be send.
 * @param [in] frameLengthBytes Frame size in bytes.
 * @param [in] i2cAddress       7-bit I2C address of the PF502x device.
 *
 * @return pf502x_status_t "Status return code."
 */
extern pf502x_status_t MCU_I2C_SendData(uint8_t* txFrame, uint8_t frameLengthBytes, uint8_t i2cAddress);

/** @brief This function receives single frame from I2C bus.
 *         MCU specific.
 *
 * This function must be implemented when I2C communication is used. The PF502x driver expects
 * incoming data in reversed order, e.g. rxFrame[0] = CRC, rxFrame[1] = data ...
 *
 * @warning This function must be implemented as blocking as there is not synchronization
 * mechanism implemented in the driver.
 *
 * @param [in]  frameLengthBytes Frame size in bytes.
 * @param [in]  i2cAddress       7-bit I2C address of the PF502x device.
 * @param [out] rxFrame          Received frame.
 *
 * @return pf502x_status_t "Status return code."
 */
extern pf502x_status_t MCU_I2C_ReceiveData(uint8_t frameLengthBytes, uint8_t i2cAddress, uint8_t* rxFrame);
/** @} */
/*******************************************************************************
 * API
 ******************************************************************************/
/** @addtogroup API
 * @{ */
/** @brief Performs a read from a single PF502x register.
 *
 * Reads a single register based on provided address.
 *
 * @param [in]  drvData Driver run-time data.
 * @param [in]  address Register address.
 * @param [out] rxData  Response from PMIC.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_ReadRegister(const pf502x_drv_data_t* drvData, uint8_t address,
        uint8_t* rxData);

/** @brief Sends write command to the PF502x.
 *
 * Writes a single register based on provided address and data to write.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] address   Register address.
 * @param [in] writeData Register write value.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_WriteRegister(const pf502x_drv_data_t* drvData, uint8_t address,
        uint8_t writeData);

/** @brief Performs a write to a single PF82 secured register.
 *
 * Writes a single secured register based on provided address and data to write.
 * Reads generated random code from RANDOM_GEN register and writes it back to
 * RANDOM_CHK register to complete the secure write transfer.
 *
 * Note: Only available on PF82xx devices.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] address   Register address.
 * @param [in] writeData Register write value.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_WriteRegisterSecured(const pf502x_drv_data_t* drvData,
		    uint8_t address, uint8_t writeData);

/** @brief Reads device identification information.
 *
 * The function gets the following IDs:
 * - device family and device IDs from DEVICE_ID register
 * - full layer and metal layer revision IDs from REV_ID register
 * - EMREV and program ID from EMREV and PROG_ID registers
 *
 * If one of the pointers is NULL, none of the IDs within the same register are read
 * (for example if deviceId is NULL, both device ID and device family ID are ignored).
 *
 * @param [in]  drvData      Driver run-time data.
 * @param [out] deviceFamily Device family ID.
 * @param [out] deviceId     Device ID.
 * @param [out] fullRev      Full layer revision.
 * @param [out] metalRev     Metal layer revision.
 * @param [out] emRev        EMREV.
 * @param [out] progId       Program ID.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_GetId(const pf502x_drv_data_t* drvData, uint8_t* deviceFamily, uint8_t* deviceId,
        uint8_t* fullRev, uint8_t* metalRev, uint8_t* emRev, uint16_t* progId);

/** @brief Sets power up/down configuration.
 *
 * @param [in] drvData Driver run-time data.
 * @param [in] pinReg  Pin or regulator power sequence.
 * @param [in] seqSlot Sequence slot (0 = off, 1 = SLOT0, 255 = SLOT254).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetPowerSequence(const pf502x_drv_data_t* drvData,
        px5x_pin_reg_t pinReg, uint8_t seqSlot);

/** @brief Sets buck regulator configuration.
 *
 * @param [in] drvData     Driver run-time data.
 * @param [in] buckSwNum   Buck regulator number.
 * @param [in] uvBypass    true = regulator bypasses undervoltage event.
 * @param [in] ovBypass    true = regulator bypasses overvoltage event.
 * @param [in] ilimBypass  true = regulator bypasses ILIM event.
 * @param [in] uvState     true = regulator remains in previous state.
 * @param [in] ovState     true = regulator remains in previous state.
 * @param [in] ilimState   true = regulator remains in previous state.
 * @param [in] wdBypass    true = regulator bypasses watchdog event.
 * @param [in] pgoodEnable true = regulator affects PGOOD pin.
 * @param [in] fltRen      true = return to previous state after fault is cleared.
 * @param [in] vttEnable   true = VTT mode enabled (only applicable for SW2).
 * @param [in] dvsRamp     DVD ramp speed (use PF502X_F_SW1DVS_RAMP_ macros corresponding
 *                         to actual regulator number) (only applicable for SW1-SW4).
 * @param [in] ilim        Current limit (use PF502X_F_SW1ILIM_ macros corresponding
 *                         to actual regulator number).
 * @param [in] phase       Phase shift (use PF502X_F_SW1PHASE_ macros corresponding
 *                         to actual regulator number).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetBuckConfig(const pf502x_drv_data_t* drvData, pf502x_reg_buck_t buckSwNum,
        bool uvBypass, bool ovBypass, bool ilimBypass, bool uvState, bool ovState,
        bool ilimState, bool wdBypass, bool pgoodEnable, bool fltRen, bool vttEnable,
        uint8_t dvsRamp, uint8_t ilim, uint8_t phase);

/** @brief Sets buck regulator mode and power down group.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] buckSwNum Buck regulator number.
 * @param [in] pdGroup   Power down group.
 * @param [in] runMode   Mode in run state.
 * @param [in] stbyMode  Mode in standby state.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetBuckModeConfig(const pf502x_drv_data_t* drvData, pf502x_reg_buck_t buckSwNum,
        pf502x_reg_powerdown_t pdGroup, pf502x_reg_mode_t runMode, pf502x_reg_mode_t stbyMode);

/** @brief Sets buck regulator voltage.
 *
 * The function sets buck regulator voltages separately for run and standby state.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] buckSwNum Buck regulator number.
 * @param [in] regState  Regulator state.
 * @param [in] voltage   Voltage (use PF502X_F_VSW1_RUN_ or PF502X_F_VSW1_STANDBY_ macros
 *                       corresponding to actual regulator number and regulator state).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetBuckVoltage(const pf502x_drv_data_t* drvData, pf502x_reg_buck_t buckSwNum,
        pf502x_reg_state_t regState, uint8_t voltage);

#ifdef PF502X_LDO_FEATURE
/** @brief Sets LDO regulator configuration.
 *
 * @param [in] drvData     Driver run-time data.
 * @param [in] ldoNum      LDO regulator number.
 * @param [in] uvBypass    true = regulator bypasses undervoltage event.
 * @param [in] ovBypass    true = regulator bypasses overvoltage event.
 * @param [in] ilimBypass  true = regulator bypasses ILIM event.
 * @param [in] uvState     true = regulator remains in previous state.
 * @param [in] ovState     true = regulator remains in previous state.
 * @param [in] ilimState   true = regulator remains in previous state.
 * @param [in] wdBypass    true = regulator bypasses watchdog event.
 * @param [in] pgoodEnable true = regulator affects PGOOD pin.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetLdoConfig(const pf502x_drv_data_t* drvData, pf502x_reg_ldo_t ldoNum,
        bool uvBypass, bool ovBypass, bool ilimBypass, bool uvState, bool ovState,
        bool ilimState, bool wdBypass, bool pgoodEnable);

/** @brief Sets LDO regulator mode and power down group.
 *
 * @param [in] drvData     Driver run-time data.
 * @param [in] ldoNum      LDO regulator number.
 * @param [in] fltRen      true = return to previous state after fault is cleared.
 * @param [in] pdGroup     Power down group.
 * @param [in] runEnabled  true = enabled in run state.
 * @param [in] stbyEnabled true = enabled in standby state.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetLdoModeConfig(const pf502x_drv_data_t* drvData, pf502x_reg_ldo_t ldoNum,
        bool fltRen, pf502x_reg_powerdown_t pdGroup, bool runEnabled, bool stbyEnabled);

/** @brief Sets LDO regulator voltage.
 *
 * The function sets LDO regulator voltages separately for run and standby state.
 *
 * @param [in] drvData  Driver run-time data.
 * @param [in] ldoNum   LDO regulator number.
 * @param [in] regState Regulator state.
 * @param [in] voltage  Voltage (use PF502X_F_VLDO1_RUN or PF502X_F_VLDO1_STANDBY_ macros
 *                      corresponding to actual regulator number and regulator state).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetLdoVoltage(const pf502x_drv_data_t* drvData, pf502x_reg_ldo_t ldoNum,
        pf502x_reg_state_t regState, uint8_t voltage);
#endif

#ifdef PF502x_VSNVS_FEATURE
/** @brief Sets VSNVS regulator voltage.
 *
 * The function sets VSNVS regulator voltage..
 *
 * @param [in] drvData  Driver run-time data.
 * @param [in] voltage  Voltage (use PF502X_F_VSNVSVOLT_ macros).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetVsnvsVoltage(const pf502x_drv_data_t* drvData, uint8_t voltage);
#endif

/** @brief Set frequency configuration of the PMIC.
 *
 * @param [in] drvData       Driver run-time data.
 * @param [in] syncoutEnable true = SYNCOUT enabled.
 * @param [in] fsyncRange    Input frequency range of SYNCIN pin.
 * @param [in] fssEnable     true = frequency spread-spectrum enabled.
 * @param [in] fssRange      Clock frequency range.
 * @param [in] clkFreq       Switching regulators frequency (use PF502X_F_CLK_FREQ_ macros).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetFreqConfig(const pf502x_drv_data_t* drvData, bool syncoutEnable,
        pf502x_fsync_range_t fsyncRange, bool fssEnable, pf502x_fss_range_t fssRange, uint8_t clkFreq);

/** @brief Sets input voltage monitor configuration.
 *
 * @param [in] drvData      Driver run-time data.
 * @param [in] ovloEnable   true = OVLO enabled.
 * @param [in] ovloShutdown true = OVLO initiates power down.
 * @param [in] ovloDebounce OVLO debounce time.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetVinOvloConfig(const pf502x_drv_data_t* drvData, bool ovloEnable,
        bool ovloShutdown, pf502x_ovlo_dbnc_t ovloDebounce);

/** @brief Sets voltage monitor configuration.
 *
 * @param [in] drvData    Driver run-time data.
 * @param [in] swMonMask  Voltage monitors for SW regulators.
 * @param [in] ldoMonMask Voltage monitors for LDO regulators.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetVoltMonitorConfig(const pf502x_drv_data_t* drvData,
        uint8_t swMonMask, uint8_t ldoMonMask);

/** @brief Sets temperature monitor configuration.
 *
 * @param [in] drvData       Driver run-time data.
 * @param [in] tempMonEnable true = enable temperature monitor circuit.
 * @param [in] tempMonAon    false = sampling mode, true = always on mode.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetTempMonitorConfig(const pf502x_drv_data_t* drvData,
        bool tempMonEnable, bool tempMonAon);

/** @brief Reads interrupt flags from selected interrupt group.
 *
 * @param [in]  drvData   Driver run-time data.
 * @param [in]  intGroup  Interrupt group.
 * @param [out] intStatus Interrupt flags.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_GetInterrupts(const pf502x_drv_data_t* drvData, pf502x_int_group_t intGroup, uint8_t* intStatus);

/** @brief Clears selected interrupt flags from selected interrupt group.
 *
 * @param [in] drvData  Driver run-time data.
 * @param [in] intGroup Interrupt group.
 * @param [in] intMask  Interrupts to clear.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_ClearInterrupts(const pf502x_drv_data_t* drvData, pf502x_int_group_t intGroup, uint8_t intMask);

/** @brief Sets which interrupts pull the INTB pin.
 *
 * @param [in] drvData  Driver run-time data.
 * @param [in] intGroup Interrupt group.
 * @param [in] intMask  Interrupt mask.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_MaskInterrupts(const pf502x_drv_data_t* drvData, pf502x_int_group_t intGroup, uint8_t intMask);

/** @brief Reads the actual status of the signal triggering interrupt.
 *
 * @param [in]  drvData  Driver run-time data.
 * @param [in]  intGroup Interrupt group.
 * @param [out] intSense Status of interrupt signals.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SenseInterrupts(const pf502x_drv_data_t* drvData, pf502x_int_group_t intGroup, uint8_t* intSense);

/** @brief Reads hardfault status.
 *
 * @param [in]  drvData Driver run-time data.
 * @param [out] hfFlags Hardfault flags.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_GetHardfaultFlags(const pf502x_drv_data_t* drvData, uint8_t* hfFlags);

/** @brief Clears hardfault status flags.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] flagsMask Flags to clear.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_ClearHardfaultFlags(const pf502x_drv_data_t* drvData, uint8_t flagsMask);

/** @brief Sets watchdog configuration.
 *
 * @param [in] drvData      Driver run-time data.
 * @param [in] wdEnable     true = watchdog timer enabled.
 * @param [in] wdStbyEnable true = watchdog timer enabled during standby.
 * @param [in] wdDuration   Watchdog timer duration (use PF502X_F_WD_DURATION_ macros).
 * @param [in] wdMaxExpire  Number of times WD can expire before WD reset
 *                          (use PF502X_F_WD_MAX_EXPIRE_ macros).
 * @param [in] wdMaxCnt     Number of WD events before the state machine goes to fail-safe
 *                          (use PF502X_F_WD_MAX_CNT_ macros).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetWatchdogConfig(const pf502x_drv_data_t* drvData, bool wdEnable,
        bool wdStbyEnable, uint8_t wdDuration, uint8_t wdMaxExpire, uint8_t wdMaxCnt);

/** @brief Reads watchdog status.
 *
 * @param [in]  drvData     Driver run-time data.
 * @param [out] wdExpireCnt Number of times WD expired.
 * @param [out] wdEventCnt  Number of WD events.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_GetWatchdogStatus(const pf502x_drv_data_t* drvData, uint8_t* wdExpireCnt, uint8_t* wdEventCnt);

/** @brief Clears watchdog.
 *
 * Watchdog clearing timing needs to be handled in the application.
 *
 * @param [in] drvData     Driver run-time data.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_ClearWatchdog(const pf502x_drv_data_t* drvData);

/** @brief Sets fault configuration.
 *
 * @param [in] drvData     Driver run-time data.
 * @param [in] faultMaxCnt Number of faults to initiate power down (use PF502X_F_FAULT_MAX_CNT_ macros).
 * @param [in] faultTimer  Fault timer duration (use PF502X_F_TIMER_FAULT_ macros).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetFaultConfig(const pf502x_drv_data_t* drvData, uint8_t faultMaxCnt, uint8_t faultTimer);

/** @brief Reads fault counter value.
 *
 * @param [in]  drvData  Driver run-time data.
 * @param [out] faultCnt Fault counter value.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_GetFaultCounter(const pf502x_drv_data_t* drvData, uint8_t* faultCnt);

/** @brief Runs ABIST on demand.
 *
 * @param [in] drvData Driver run-time data.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_RunAbist(const pf502x_drv_data_t* drvData);

/** @brief Reads ABIST OV and UV flags.
 *
 * @param [in]  drvData    Driver run-time data.
 * @param [in]  ovUvFlags  false = OV flags, true = UV flags.
 * @param [out] abistFlags ABIST flags (high byte = LDO flags, low byte = SW flags).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_GetAbistFlags(const pf502x_drv_data_t* drvData, bool ovUvFlags, uint16_t* abistFlags);

/** @brief Clears ABIST status flags.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] ovUvFlags false = OV flags, true = UV flags.
 * @param [in] flagsMask Flags to clear (high byte = LDO flags, low byte = SW flags).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_ClearAbistFlags(const pf502x_drv_data_t* drvData, bool ovUvFlags, uint16_t flagsMask);

/** @brief Reads test flags.
 *
 * @param [in]  drvData   Driver run-time data.
 * @param [out] testFlags Test flags.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_GetTestFlags(const pf502x_drv_data_t* drvData, uint8_t* testFlags);

/** @brief Clears test flags.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] flagsMask Flags to clear.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_ClearTestFlags(const pf502x_drv_data_t* drvData, uint8_t flagsMask);

/** @brief Sets analog multiplexer (AMUX).
 *
 * @param [in] drvData    Driver run-time data.
 * @param [in] amuxEnable true = AMUX enabled.
 * @param [in] amuxSel    AMUX selection (use PF502X_F_AMUX_SEL_ macros).
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF502X_SetAmux(const pf502x_drv_data_t* drvData, bool amuxEnable, uint8_t amuxSel);

/** @brief Turns PMIC off (after 500us shutdown timer expires).
 *
 * @param [in] drvData Driver run-time data.
 *
 * @return pf502x_status_t "Status return code."
 */
pf502x_status_t PF5024_TurnOff(const pf502x_drv_data_t *drvData);

/** @} */
#endif /* PMIC_PF502X_H_ */
