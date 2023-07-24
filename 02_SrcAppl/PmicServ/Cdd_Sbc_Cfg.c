/**
 * \file   Cdd_Sbc_Cfg.c
 *
 * \brief  Configuration data and stubs function of PMIC.
 *
 * \version refer the Cdd_Sbc_Cfg.h.
 *
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include "Cdd_Sbc_Cfg.h"



/*==================[internal data]=========================================*/
/*==================[.rodata]==============================*/
const fs8x_drv_data_t fs8400drvData = {.watchdogSeed = FS8x_WD_SEED_DEFAULT,.communicationMode=fs8xI2C,.i2cAddressOtp=FS8400_I2C_ADDRESS_OTP};
const pf8x_drv_data_t pf8200drvData = { .i2cAddressOtp = PF8200_I2C_ADDRESS_OTP, .secureEnabled = false, .crcEnabled = true };
const pf502x_drv_data_t pf5024drvData = { .i2cAddressOtp = PF5024_I2C_ADDRESS_OTP, .secureEnabled = false, .crcEnabled = false };

/*==================[external data]=========================================*/


/*==================[internal function declarations]========================*/
static void reverseByteArray(uint8_t* start, uint32_t size);

/*==================[external function definitions]=========================*/
/**
 * \functions FS8x_MCU_I2C_SendData
 *
 * \brief Send the reuqest data to IIC.
 *
 ** \param[in] *start,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
fs8x_status_t FS8x_MCU_I2C_SendData(uint8_t* txFrame, uint8_t frameSizeBytes, uint8_t i2cAddress)
{
	I2c_ErrorType status;
    uint16_t slaveAddress;
    uint16_t dataSize;
    slaveAddress = (uint16_t)i2cAddress;
	//FS8x_DebugVar = slaveAddress;
    reverseByteArray(txFrame, frameSizeBytes);
    dataSize = (uint16_t)frameSizeBytes;
    status = I2c_SyncWrite(0, txFrame, dataSize, slaveAddress);
    if (status != I2C_NO_ERR)
    {
        return fs8xStatusError;
    }
    return fs8xStatusOk;
}

/**
 * \functions FS8x_MCU_I2C_ReceiveData
 *
 * \brief Get the receive data from IIC.  
 *
 ** \param[in] frameSizeBytes,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
fs8x_status_t FS8x_MCU_I2C_ReceiveData(uint8_t frameSizeBytes, uint8_t i2cAddress, uint8_t* rxFrame)
{
	I2c_ErrorType status;
    uint16_t slaveAddress;
    uint16_t dataSize;
    slaveAddress = (uint16_t)i2cAddress;
    dataSize = (uint16_t)frameSizeBytes;
    status = I2c_SyncRead(0,rxFrame, dataSize, slaveAddress);
    reverseByteArray(rxFrame, frameSizeBytes);
    if (status != I2C_NO_ERR)
    {
        return fs8xStatusError;
    }
    return fs8xStatusOk;
}

/**
 * \functions PF8x_MCU_I2C_SendData
 *
 * \brief   
 *
 ** \param[in] *txFrame,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
pf8x_status_t PF8x_MCU_I2C_SendData(uint8_t* txFrame, uint8_t frameSizeBytes, uint8_t i2cAddress)
{
	I2c_ErrorType status;
    uint16_t slaveAddress;
    uint16_t dataSize;
    slaveAddress = (uint16_t)i2cAddress;
    reverseByteArray(txFrame, frameSizeBytes);
    dataSize = (uint16_t)frameSizeBytes;
    status = I2c_SyncWrite(0, txFrame, dataSize, slaveAddress);
    if (status != I2C_NO_ERR)
    {
        return pf8xStatusError;
    }
    return pf8xStatusOk;
}

/**
 * \functions PF8x_MCU_I2C_ReceiveData
 *
 * \brief   
 *
 ** \param[in] frameSizeBytes,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
pf8x_status_t PF8x_MCU_I2C_ReceiveData(uint8_t frameSizeBytes, uint8_t i2cAddress, uint8_t* rxFrame)
{
	I2c_ErrorType status;
    uint16_t slaveAddress;
    uint16_t dataSize;
    slaveAddress = (uint16_t)i2cAddress;
    dataSize = (uint16_t)frameSizeBytes;
    status = I2c_SyncRead(0,rxFrame, dataSize, slaveAddress);
    reverseByteArray(rxFrame, frameSizeBytes);
    if (status != I2C_NO_ERR)
    {
        return pf8xStatusError;
    }
    return pf8xStatusOk;
}

/**
 * \functions PF5x_MCU_I2C_SendData
 *
 * \brief   
 *
 ** \param[in] *start,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
pf502x_status_t PF5x_MCU_I2C_SendData(uint8_t* txFrame, uint8_t frameSizeBytes, uint8_t i2cAddress)
{
	I2c_ErrorType status;
    uint16_t slaveAddress;
    uint16_t dataSize;
    slaveAddress = (uint16_t)i2cAddress;
    reverseByteArray(txFrame, frameSizeBytes);
    dataSize = (uint16_t)frameSizeBytes;
    status = I2c_SyncWrite(0, txFrame, dataSize, slaveAddress);
    if (status != I2C_NO_ERR)
    {
        return pf502xStatusError;
    }
    return pf502xStatusOk;
}

/**
 * \functions PF5x_MCU_I2C_ReceiveData
 *
 * \brief   
 *
 ** \param[in] *start,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
pf502x_status_t PF5x_MCU_I2C_ReceiveData(uint8_t frameSizeBytes, uint8_t i2cAddress, uint8_t* rxFrame)
{
	I2c_ErrorType status;
    uint16_t slaveAddress;
    uint16_t dataSize;
    slaveAddress = (uint16_t)i2cAddress;
    dataSize = (uint16_t)frameSizeBytes;
    status = I2c_SyncRead(0,rxFrame, dataSize, slaveAddress);
    reverseByteArray(rxFrame, frameSizeBytes);
    if (status != I2C_NO_ERR)
    {
        return pf502xStatusError;
    }
    return pf502xStatusOk;
}

/**
 * \functions MCU_SPI_TransferData
 *
 * \brief   
 *
 ** \param[in] *txData,
 *              frameLengthBytes
 ** \param[out] rxData,
 *
 ** \return none,
 * \comments
 *
 */
fs8x_status_t MCU_SPI_TransferData(uint8_t* txData, uint16_t frameLengthBytes, uint8_t* rxData)
{
	return 0;
}

/*==================[internal function definitions]=========================*/
/**
 * \functions reverseByteArray
 *
 * \brief   
 *
 ** \param[in] *start,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
static void reverseByteArray(uint8_t* start, uint32_t size)
{
    uint8_t* lo = start;
    uint8_t* hi = start + size - 1;
    uint8_t swap;
    while (lo < hi)
    {
        swap = *lo;
        *lo++ = *hi;
        *hi-- = swap;
    }
}


