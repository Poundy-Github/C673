/*
 * Copyright (c) 2019 NXP
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
 * o Neither the name of the copyright holder nor the names of its
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
 * @file pmic_pf8x.h
 * @brief Definitions of I2C communication logic for NXP PMIC PF8x.
 *
 * @author nxa22158
 * @version 1.0
 * @date 21-August-2019
 * @copyright Copyright (c) 2019 NXP
 */

#ifndef PMIC_PF8X_H_
#define PMIC_PF8X_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <pmic_pf8x_common.h>
#include "pmi_driver.h"
#if PF8X_DEVICE == PF8X_DEVICE_PF81
#include <pmic_pf81_map.h>
#else
#include <pmic_pf82_map.h>
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/** @defgroup EnumsDefs Enums definition
 * @{ */
/** @brief Buck regulator. */
typedef enum
{
    pf8xRegBuckSW1 = 0U,     /**< SW1 buck. */
    pf8xRegBuckSW2 = 1U,     /**< SW2 buck. */
    pf8xRegBuckSW3 = 2U,     /**< SW3 buck. */
    pf8xRegBuckSW4 = 3U,     /**< SW4 buck. */
    pf8xRegBuckSW5 = 4U,     /**< SW5 buck. */
    pf8xRegBuckSW6 = 5U,     /**< SW6 buck. */
    pf8xRegBuckSW7 = 6U      /**< SW7 buck. */
} pf8x_reg_buck_t;

/** @brief LDO regulator. */
typedef enum
{
    pf8xRegLdo1 = 0U,        /**< LDO1. */
    pf8xRegLdo2 = 1U,        /**< LDO2. */
    pf8xRegLdo3 = 2U,        /**< LDO3. */
    pf8xRegLdo4 = 3U         /**< LDO4. */
} pf8x_reg_ldo_t;

/** @brief Regulator state. */
typedef enum
{
    pf8xRegStateRun     = 0U, /**< Run state. */
    pf8xRegStateStandby = 1U  /**< Standby state. */
} pf8x_reg_state_t;

/** @brief Regulator mode. */
typedef enum
{
    pf8xRegModeOff = 0U,     /**< OFF mode. */
    pf8xRegModePwm = 1U,     /**< PWM mode. */
    pf8xRegModePfm = 2U,     /**< PFM mode. */
    pf8xRegModeAutoskip = 3U /**< Autoskip mode. */
} pf8x_reg_mode_t;

/** @brief Regulator power down group. */
typedef enum
{
    pf8xRegPdGroup4 = 0U,    /**< Power down group 4. */
    pf8xRegPdGroup3 = 1U,    /**< Power down group 3. */
    pf8xRegPdGroup2 = 2U,    /**< Power down group 2. */
    pf8xRegPdGroup1 = 3U     /**< Power down group 1. */
} pf8x_reg_powerdown_t;

/** @brief Pin/regulator power sequence. */
typedef enum
{
    pf8xPinRegResetbMcu = PF8X_RESETBMCU_PWRUP_ADDR, /**< INT_STATUS1 interrupts. */
    pf8xPinRegPgood = PF8X_PGOOD_PWRUP_ADDR,         /**< INT_STATUS2 interrupts. */
    pf8xPinRegSw1 = PF8X_SW1_PWRUP_ADDR,             /**< SW_MODE interrupts. */
    pf8xPinRegSw2 = PF8X_SW2_PWRUP_ADDR,             /**< SW_ILIM interrupts. */
    pf8xPinRegSw3 = PF8X_SW3_PWRUP_ADDR,             /**< LDO_ILIM interrupts. */
    pf8xPinRegSw4 = PF8X_SW4_PWRUP_ADDR,             /**< SW_UV interrupts. */
    pf8xPinRegSw5 = PF8X_SW5_PWRUP_ADDR,             /**< SW_OV interrupts. */
    pf8xPinRegSw6 = PF8X_SW6_PWRUP_ADDR,             /**< LDO_UV interrupts. */
    pf8xPinRegSw7 = PF8X_SW7_PWRUP_ADDR,             /**< LDO_OV interrupts. */
    pf8xPinRegLdo1 = PF8X_LDO1_PWRUP_ADDR,           /**< LDO_UV interrupts. */
    pf8xPinRegLdo2 = PF8X_LDO2_PWRUP_ADDR,           /**< LDO_OV interrupts. */
    pf8xPinRegLdo3 = PF8X_LDO3_PWRUP_ADDR,           /**< PWRON interrupts. */
    pf8xPinRegLdo4 = PF8X_LDO4_PWRUP_ADDR            /**< SYS_INT interrupts. */
} px8x_pin_reg_t;

/** @brief Sync frequency range. */
typedef enum
{
    /**< 2000 kHz to 3000 kHz. */
    pf8xFsyncRangeHigh = PF8X_F_FSYNC_RANGE_2000_KHZ_3000_KHZ,
    /**< 333 kHz to 500 kHz. */
    pf8xFsyncRangeLow = PF8X_F_FSYNC_RANGE_333_KHZ_500_KHZ
} pf8x_fsync_range_t;

/** @brief FSS range. */
typedef enum
{
    pf8xFssRangeNarrow = PF8X_F_FSS_RANGE_5, /**< +/- 5% range. */
    pf8xFssRangeWide = PF8X_F_FSS_RANGE_10   /**< +/- 10% range. */
} pf8x_fss_range_t;

/** @brief VIN_OVLO debounce. */
typedef enum
{
    pf8xOvloDbnc10us = PF8X_F_VIN_OVLO_DBNC_10_US,    /**< Debounce 10 us. */
    pf8xOvloDbnc100us = PF8X_F_VIN_OVLO_DBNC_100_US,  /**< Debounce 100 us. */
    pf8xOvloDbnc1000us = PF8X_F_VIN_OVLO_DBNC_1000_US /**< Debounce 1000 us. */
} pf8x_ovlo_dbnc_t;

/** @brief Interrupt group. */
typedef enum
{
    pf8xIntGroupStatus1 = PF8X_INT_STATUS1_ADDR,  /**< INT_STATUS1 interrupts. */
    pf8xIntGroupStatus2 = PF8X_INT_STATUS2_ADDR,  /**< INT_STATUS2 interrupts. */
    pf8xIntGroupSwMode = PF8X_SW_MODE_INT_ADDR,   /**< SW_MODE interrupts. */
    pf8xIntGroupSwIlim = PF8X_SW_ILIM_INT_ADDR,   /**< SW_ILIM interrupts. */
    pf8xIntGroupLdoIlim = PF8X_LDO_ILIM_INT_ADDR, /**< LDO_ILIM interrupts. */
    pf8xIntGroupSwUv = PF8X_SW_UV_INT_ADDR,       /**< SW_UV interrupts. */
    pf8xIntGroupSwOv = PF8X_SW_OV_INT_ADDR,       /**< SW_OV interrupts. */
    pf8xIntGroupLdoUv = PF8X_LDO_UV_INT_ADDR,     /**< LDO_UV interrupts. */
    pf8xIntGroupLdoOv = PF8X_LDO_OV_INT_ADDR,     /**< LDO_OV interrupts. */
    pf8xIntGroupPwron = PF8X_PWRON_INT_ADDR,      /**< PWRON interrupts. */
    pf8xIntGroupSysInt = PF8X_SYS_INT_ADDR        /**< SYS_INT interrupts. */
} pf8x_int_group_t;
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
 * @param [in] i2cAddress       7-bit I2C address of the PF8x device.
 *
 * @return pf8x_status_t "Status return code."
 */
extern pf8x_status_t PF8x_MCU_I2C_SendData(uint8_t* txFrame, uint8_t frameLengthBytes, uint8_t i2cAddress);

/** @brief This function receives single frame from I2C bus.
 *         MCU specific.
 *
 * This function must be implemented when I2C communication is used. The PF8x driver expects
 * incoming data in reversed order, e.g. rxFrame[0] = CRC, rxFrame[1] = data ...
 *
 * @warning This function must be implemented as blocking as there is not synchronization
 * mechanism implemented in the driver.
 *
 * @param [in]  frameLengthBytes Frame size in bytes.
 * @param [in]  i2cAddress       7-bit I2C address of the PF8x device.
 * @param [out] rxFrame          Received frame.
 *
 * @return pf8x_status_t "Status return code."
 */
extern pf8x_status_t PF8x_MCU_I2C_ReceiveData(uint8_t frameLengthBytes, uint8_t i2cAddress, uint8_t* rxFrame);
/** @} */
/*******************************************************************************
 * API
 ******************************************************************************/
/** @addtogroup API
 * @{ */
/** @brief Performs a read from a single PF8x register.
 *
 * Reads a single register based on provided address.
 *
 * @param [in]  drvData Driver run-time data.
 * @param [in]  address Register address.
 * @param [out] rxData  Response from PMIC.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_ReadRegister(pf8x_drv_data_t* drvData, uint8_t address,
        uint8_t* rxData);

/** @brief Sends write command to the PF8x.
 *
 * Writes a single register based on provided address and data to write.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] address   Register address.
 * @param [in] writeData Register write value.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_WriteRegister(pf8x_drv_data_t* drvData, uint8_t address,
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
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_WriteRegisterSecured(pf8x_drv_data_t* drvData,
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
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_GetId(pf8x_drv_data_t* drvData, uint8_t* deviceFamily, uint8_t* deviceId,
        uint8_t* fullRev, uint8_t* metalRev, uint8_t* emRev, uint16_t* progId);

/** @brief Sets power up/down configuration.
 *
 * @param [in] drvData Driver run-time data.
 * @param [in] pinReg  Pin or regulator power sequence.
 * @param [in] seqSlot Sequence slot (0 = off, 1 = SLOT0, 255 = SLOT254).
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetPowerSequence(pf8x_drv_data_t* drvData,
        px8x_pin_reg_t pinReg, uint8_t seqSlot);

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
 * @param [in] vttEnable   true = VTT mode enabled (only applicable for SW6).
 * @param [in] dvsRamp     true = 12.5 mV/us, false = 6.25 mV/us (not applicable for SW7).
 * @param [in] ilim        Current limit (use PF8X_F_SW1ILIM_ macros corresponding
 *                         to actual regulator number).
 * @param [in] phase       Phase shift (use PF8X_F_SW1PHASE_ macros corresponding
 *                         to actual regulator number).
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetBuckConfig(pf8x_drv_data_t* drvData, pf8x_reg_buck_t buckSwNum,
        bool uvBypass, bool ovBypass, bool ilimBypass, bool uvState, bool ovState,
        bool ilimState, bool wdBypass, bool pgoodEnable, bool fltRen, bool vttEnable,
        bool dvsRamp, uint8_t ilim, uint8_t phase);

/** @brief Sets buck regulator mode and power down group.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] buckSwNum Buck regulator number.
 * @param [in] pdGroup   Power down group.
 * @param [in] runMode   Mode in run state.
 * @param [in] stbyMode  Mode in standby state.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetBuckModeConfig(pf8x_drv_data_t* drvData, pf8x_reg_buck_t buckSwNum,
        pf8x_reg_powerdown_t pdGroup, pf8x_reg_mode_t runMode, pf8x_reg_mode_t stbyMode);

/** @brief Sets buck regulator voltage.
 *
 * The function sets buck regulator voltages separately for run and standby state.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] buckSwNum Buck regulator number.
 * @param [in] regState  Regulator state.
 * @param [in] voltage   Voltage (use PF8X_F_VSW1_RUN_ or PF8X_F_VSW1_STANDBY_ macros
 *                       corresponding to actual regulator number and regulator state).
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetBuckVoltage(pf8x_drv_data_t* drvData, pf8x_reg_buck_t buckSwNum,
        pf8x_reg_state_t regState, uint8_t voltage);

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
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetLdoConfig(pf8x_drv_data_t* drvData, pf8x_reg_ldo_t ldoNum,
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
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetLdoModeConfig(pf8x_drv_data_t* drvData, pf8x_reg_ldo_t ldoNum,
        bool fltRen, pf8x_reg_powerdown_t pdGroup, bool runEnabled, bool stbyEnabled);

/** @brief Sets LDO regulator voltage.
 *
 * The function sets LDO regulator voltages separately for run and standby state.
 *
 * @param [in] drvData  Driver run-time data.
 * @param [in] ldoNum   LDO regulator number.
 * @param [in] regState Regulator state.
 * @param [in] voltage  Voltage (use PF8X_F_VLDO1_RUN or PF8X_F_VLDO1_STANDBY_ macros
 *                      corresponding to actual regulator number and regulator state).
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetLdoVoltage(pf8x_drv_data_t* drvData, pf8x_reg_ldo_t ldoNum,
        pf8x_reg_state_t regState, uint8_t voltage);

/** @brief Set frequency configuration of the PMIC.
 *
 * @param [in] drvData       Driver run-time data.
 * @param [in] syncoutEnable true = SYNCOUT enabled.
 * @param [in] fsyncRange    Input frequency range of SYNCIN pin.
 * @param [in] fssEnable     true = frequency spread-spectrum enabled.
 * @param [in] fssRange      Clock frequency range.
 * @param [in] clkFreq       Switching regulators frequency (use PF8X_F_CLK_FREQ_ macros).
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetFreqConfig(pf8x_drv_data_t* drvData, bool syncoutEnable,
        pf8x_fsync_range_t fsyncRange, bool fssEnable, pf8x_fss_range_t fssRange, uint8_t clkFreq);

/** @brief Sets input voltage monitor configuration.
 *
 * @param [in] drvData      Driver run-time data.
 * @param [in] ovloEnable   true = OVLO enabled.
 * @param [in] ovloShutdown true = OVLO initiates power down.
 * @param [in] ovloDebounce OVLO debounce time.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetVinOvloConfig(pf8x_drv_data_t* drvData, bool ovloEnable,
        bool ovloShutdown, pf8x_ovlo_dbnc_t ovloDebounce);

/** @brief Sets voltage monitor configuration.
 *
 * @param [in] drvData    Driver run-time data.
 * @param [in] swMonMask  Voltage monitors for SW regulators.
 * @param [in] ldoMonMask Voltage monitors for LDO regulators.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetVoltMonitorConfig(pf8x_drv_data_t* drvData,
        uint8_t swMonMask, uint8_t ldoMonMask);

/** @brief Sets temperature monitor configuration.
 *
 * @param [in] drvData       Driver run-time data.
 * @param [in] tempMonEnable true = enable temperature monitor circuit.
 * @param [in] tempMonAon    false = sampling mode, true = always on mode.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetTempMonitorConfig(pf8x_drv_data_t* drvData,
        bool tempMonEnable, bool tempMonAon);

/** @brief Reads interrupt flags from selected interrupt group.
 *
 * @param [in]  drvData   Driver run-time data.
 * @param [in]  intGroup  Interrupt group.
 * @param [out] intStatus Interrupt flags.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_GetInterrupts(pf8x_drv_data_t* drvData, pf8x_int_group_t intGroup, uint8_t* intStatus);

/** @brief Clears selected interrupt flags from selected interrupt group.
 *
 * @param [in] drvData  Driver run-time data.
 * @param [in] intGroup Interrupt group.
 * @param [in] intMask  Interrupts to clear.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_ClearInterrupts(pf8x_drv_data_t* drvData, pf8x_int_group_t intGroup, uint8_t intMask);

/** @brief Sets which interrupts pull the INTB pin.
 *
 * @param [in] drvData  Driver run-time data.
 * @param [in] intGroup Interrupt group.
 * @param [in] intMask  Interrupt mask.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_MaskInterrupts(pf8x_drv_data_t* drvData, pf8x_int_group_t intGroup, uint8_t intMask);

/** @brief Reads the actual status of the signal triggering interrupt.
 *
 * @param [in]  drvData  Driver run-time data.
 * @param [in]  intGroup Interrupt group.
 * @param [out] intSense Status of interrupt signals.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SenseInterrupts(pf8x_drv_data_t* drvData, pf8x_int_group_t intGroup, uint8_t* intSense);

/** @brief Reads hardfault status.
 *
 * @param [in]  drvData Driver run-time data.
 * @param [out] hfFlags Hardfault flags.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_GetHardfaultFlags(pf8x_drv_data_t* drvData, uint8_t* hfFlags);

/** @brief Clears hardfault status flags.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] flagsMask Flags to clear.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_ClearHardfaultFlags(pf8x_drv_data_t* drvData, uint8_t flagsMask);

/** @brief Sets FSOB configuration.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] softfault true = FSOB asserted when regulator fault is present.
 * @param [in] wdi       true = FSOB asserted when watchdog reset occurs due to WDI event.
 * @param [in] wdc       true = FSOB asserted when watchdog reset occurs due to WD counter fault.
 * @param [in] hardfault true = FSOB asserted when hardfault shutdown occurs.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetFSOBConfig(pf8x_drv_data_t* drvData,
        bool softfault, bool wdi, bool wdc, bool hardfault);

/** @brief Reads FSOB status.
 *
 * @param [in]  drvData Driver run-time data.
 * @param [out] fsFlags FSOB flags.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_GetFSOBFlags(pf8x_drv_data_t* drvData, uint8_t* fsFlags);

/** @brief Clears FSOB status flags.
 *
 * @param [in] drvData     Driver run-time data.
 * @param [in] flagsMask   Flags to clear.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_ClearFSOBFlags(pf8x_drv_data_t* drvData, uint8_t flagsMask);

/** @brief Sets watchdog configuration.
 *
 * @param [in] drvData      Driver run-time data.
 * @param [in] wdEnable     true = watchdog timer enabled.
 * @param [in] wdStbyEnable true = watchdog timer enabled during standby.
 * @param [in] wdDuration   Watchdog timer duration (use PF8X_F_WD_DURATION_ macros).
 * @param [in] wdMaxExpire  Number of times WD can expire before WD reset
 *                          (use PF8X_F_WD_MAX_EXPIRE_ macros).
 * @param [in] wdMaxCnt     Number of WD events before the state machine goes to fail-safe
 *                          (use PF8X_F_WD_MAX_CNT_ macros).
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetWatchdogConfig(pf8x_drv_data_t* drvData, bool wdEnable,
        bool wdStbyEnable, uint8_t wdDuration, uint8_t wdMaxExpire, uint8_t wdMaxCnt);

/** @brief Reads watchdog status.
 *
 * @param [in]  drvData     Driver run-time data.
 * @param [out] wdExpireCnt Number of times WD expired.
 * @param [out] wdEventCnt  Number of WD events.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_GetWatchdogStatus(pf8x_drv_data_t* drvData, uint8_t* wdExpireCnt, uint8_t* wdEventCnt);

/** @brief Clears watchdog.
 *
 * Watchdog clearing timing needs to be handled in the application.
 *
 * @param [in] drvData     Driver run-time data.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_ClearWatchdog(pf8x_drv_data_t* drvData);

/** @brief Sets fault configuration.
 *
 * @param [in] drvData     Driver run-time data.
 * @param [in] faultMaxCnt Number of faults to initiate power down (use PF8X_F_FAULT_MAX_CNT_ macros).
 * @param [in] faultTimer  Fault timer duration (use PF8X_F_TIMER_FAULT_ macros).
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetFaultConfig(pf8x_drv_data_t* drvData, uint8_t faultMaxCnt, uint8_t faultTimer);

/** @brief Reads fault counter value.
 *
 * @param [in]  drvData  Driver run-time data.
 * @param [out] faultCnt Fault counter value.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_GetFaultCounter(pf8x_drv_data_t* drvData, uint8_t* faultCnt);

#if PF8X_DEVICE == PF8X_DEVICE_PF82
/** @brief Runs ABIST on demand.
 *
 * @param [in] drvData Driver run-time data.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_RunAbist(pf8x_drv_data_t* drvData);

/** @brief Reads ABIST OV and UV flags.
 *
 * @param [in]  drvData    Driver run-time data.
 * @param [in]  ovUvFlags  false = OV flags, true = UV flags.
 * @param [out] abistFlags ABIST flags (high byte = LDO flags, low byte = SW flags).
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_GetAbistFlags(pf8x_drv_data_t* drvData, bool ovUvFlags, uint16_t* abistFlags);

/** @brief Clears ABIST status flags.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] ovUvFlags false = OV flags, true = UV flags.
 * @param [in] flagsMask Flags to clear (high byte = LDO flags, low byte = SW flags).
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_ClearAbistFlags(pf8x_drv_data_t* drvData, bool ovUvFlags, uint16_t flagsMask);
#endif

/** @brief Reads test flags.
 *
 * @param [in]  drvData   Driver run-time data.
 * @param [out] testFlags Test flags.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_GetTestFlags(pf8x_drv_data_t* drvData, uint8_t* testFlags);

/** @brief Clears test flags.
 *
 * @param [in] drvData   Driver run-time data.
 * @param [in] flagsMask Flags to clear.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_ClearTestFlags(pf8x_drv_data_t* drvData, uint8_t flagsMask);

/** @brief Sets analog multiplexer (AMUX).
 *
 * @param [in] drvData    Driver run-time data.
 * @param [in] amuxEnable true = AMUX enabled.
 * @param [in] amuxSel    AMUX selection (use PF8X_F_AMUX_SEL_ macros).
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_SetAmux(pf8x_drv_data_t* drvData, bool amuxEnable, uint8_t amuxSel);

/** @brief Turns PMIC off (after 500us shutdown timer expires).
 *
 * @param [in] drvData Driver run-time data.
 *
 * @return pf8x_status_t "Status return code."
 */
pf8x_status_t PF8X_TurnOff(pf8x_drv_data_t* drvData);
uint8_t PF8200_PowerOn_Flag(pf8x_drv_data_t* drvData);
uint8_t PF8X_CTRL3Flags(pf8x_drv_data_t* drvData);
/** @} */
#endif /* PMIC_PF8X_H_ */
