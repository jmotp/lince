/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       EK_TM4C129EXL.h
 *
 *  @brief      EK_TM4C129EXL Board Specific APIs
 *
 *  The EK_TM4C129EXL header file should be included in an application as
 *  follows:
 *  @code
 *  #include <EK_TM4C129EXL.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef __EK_TM4C129EXL_H
#define __EK_TM4C129EXL_H

#ifdef __cplusplus
extern "C" {
#endif

/* LEDs on EK_TM4C129EXL are active high. */
#define LINCE_LED_OFF (0)
#define LINCE_LED_ON  (1)

/*!
 *  @def    EK_TM4C129EXL_EMACName
 *  @brief  Enum of EMAC names on the EK_TM4C129EXL dev board
 */

#define LINCE_EMAC 0


/*!
 *  @def    EK_TM4C129EXL_GPIOName
 *  @brief  Enum of LED names on the EK_TM4C129EXL dev board
 */
typedef enum EK_TM4C129EXL_GPIOName {
    DBG_LED_1 = 0,
    DBG_LED_2,
    DIGITAL_OUT_1_1,
    DIGITAL_OUT_1_2,
    DIGITAL_OUT_1_3,
    DIGITAL_OUT_1_4,
    DIGITAL_OUT_2_1,
    DIGITAL_OUT_2_2,
    DIGITAL_OUT_2_3,
    DIGITAL_OUT_2_4,
    DIGITAL_IN_1,
    DIGITAL_IN_2,
    DIGITAL_IN_3,
    DIGITAL_IN_4,
    DIGITAL_IN_5,
    DIGITAL_IN_6,
    DIGITAL_IN_7,
    DIGITAL_IN_8,
    LINCE_GPIOCOUNT
} EK_TM4C129EXL_GPIOName;

/*!
 *  @def    EK_TM4C129EXL_I2CName
 *  @brief  Enum of I2C names on the EK_TM4C129EXL dev board
 */
typedef enum EK_TM4C129EXL_I2CName {
    EK_TM4C129EXL_I2C7 = 0,
    EK_TM4C129EXL_I2C8,

    EK_TM4C129EXL_I2CCOUNT
} EK_TM4C129EXL_I2CName;

/*!
 *  @def    EK_TM4C129EXL_PWMName
 *  @brief  Enum of PWM names on the EK_TM4C129EXL dev board
 */
typedef enum EK_TM4C129EXL_PWMName {
    EK_TM4C129EXL_PWM0 = 0,

    EK_TM4C129EXL_PWMCOUNT
} EK_TM4C129EXL_PWMName;

/*!
 *  @def    EK_TM4C129EXL_SDSPIName
 *  @brief  Enum of SDSPI names on the EK_TM4C129EXL dev board
 */
typedef enum EK_TM4C129EXL_SDSPIName {
    EK_TM4C129EXL_SDSPI0 = 0,
    EK_TM4C129EXL_SDSPI1,

    EK_TM4C129EXL_SDSPICOUNT
} EK_TM4C129EXL_SDSPIName;

/*!
 *  @def    EK_TM4C129EXL_SPIName
 *  @brief  Enum of SPI names on the EK_TM4C129EXL dev board
 */
typedef enum EK_TM4C129EXL_SPIName {
    EK_TM4C129EXL_SPI2 = 0,
    EK_TM4C129EXL_SPI3,

    EK_TM4C129EXL_SPICOUNT
} EK_TM4C129EXL_SPIName;

/*!
 *  @def    EK_TM4C129EXL_UARTName
 *  @brief  Enum of UARTs on the EK_TM4C129EXL dev board
 */
typedef enum EK_TM4C129EXL_UARTName {
    EK_TM4C129EXL_UART0 = 0,

    EK_TM4C129EXL_UARTCOUNT
} EK_TM4C129EXL_UARTName;

/*!
 *  @def    EK_TM4C129EXL_USBMode
 *  @brief  Enum of USB setup function on the EK_TM4C129EXL dev board
 */
typedef enum EK_TM4C129EXL_USBMode {
    EK_TM4C129EXL_USBDEVICE,
    EK_TM4C129EXL_USBHOST
} EK_TM4C129EXL_USBMode;

/*!
 *  @def    EK_TM4C129EXL_USBMSCHFatFsName
 *  @brief  Enum of USBMSCHFatFs names on the EK_TM4C129EXL dev board
 */
typedef enum EK_TM4C129EXL_USBMSCHFatFsName {
    EK_TM4C129EXL_USBMSCHFatFs0 = 0,

    EK_TM4C129EXL_USBMSCHFatFsCOUNT
} EK_TM4C129EXL_USBMSCHFatFsName;

/*
 *  @def    EK_TM4C129EXL_WatchdogName
 *  @brief  Enum of Watchdogs on the EK_TM4C129EXL dev board
 */
typedef enum EK_TM4C129EXL_WatchdogName {
    EK_TM4C129EXL_WATCHDOG0 = 0,

    EK_TM4C129EXL_WATCHDOGCOUNT
} EK_TM4C129EXL_WatchdogName;

/*!
 *  @def    EK_TM4C129EXL_WiFiName
 *  @brief  Enum of WiFi names on the EK_TM4C129EXL dev board
 */
typedef enum EK_TM4C129EXL_WiFiName {
    EK_TM4C129EXL_WIFI = 0,

    EK_TM4C129EXL_WIFICOUNT
} EK_TM4C129EXL_WiFiName;

/*!
 *  @brief  Initialize the general board specific settings
 *
 *  This function initializes the general board specific settings.
 *  This includes:
 *     - Enable clock sources for peripherals
 */
extern void EK_TM4C129EXL_initGeneral(void);

/*!
 *  @brief Initialize board specific EMAC settings
 *
 *  This function initializes the board specific EMAC settings and
 *  then calls the EMAC_init API to initialize the EMAC module.
 *
 *  The EMAC address is programmed as part of this call.
 *
 */
extern void EK_TM4C129EXL_initEMAC(void);

/*!
 *  @brief  Initialize board specific GPIO settings
 *
 *  This function initializes the board specific GPIO settings and
 *  then calls the GPIO_init API to initialize the GPIO module.
 *
 *  The GPIOs controlled by the GPIO module are determined by the GPIO_PinConfig
 *  variable.
 */
extern void EK_TM4C129EXL_initGPIO(void);

/*!
 *  @brief  Initialize board specific I2C settings
 *
 *  This function initializes the board specific I2C settings and then calls
 *  the I2C_init API to initialize the I2C module.
 *
 *  The I2C peripherals controlled by the I2C module are determined by the
 *  I2C_config variable.
 */
extern void EK_TM4C129EXL_initI2C(void);

/*!
 *  @brief  Initialize board specific PWM settings
 *
 *  This function initializes the board specific PWM settings and then calls
 *  the PWM_init API to initialize the PWM module.
 *
 *  The PWM peripherals controlled by the PWM module are determined by the
 *  PWM_config variable.
 */
extern void EK_TM4C129EXL_initPWM(void);

/*!
 *  @brief  Initialize board specific SDSPI settings
 *
 *  This function initializes the board specific SDSPI settings and then calls
 *  the SDSPI_init API to initialize the SDSPI module.
 *
 *  The SDSPI peripherals controlled by the SDSPI module are determined by the
 *  SDSPI_config variable.
 */
extern void EK_TM4C129EXL_initSDSPI(void);

/*!
 *  @brief  Initialize board specific SPI settings
 *
 *  This function initializes the board specific SPI settings and then calls
 *  the SPI_init API to initialize the SPI module.
 *
 *  The SPI peripherals controlled by the SPI module are determined by the
 *  SPI_config variable.
 */
extern void EK_TM4C129EXL_initSPI(void);

/*!
 *  @brief  Initialize board specific UART settings
 *
 *  This function initializes the board specific UART settings and then calls
 *  the UART_init API to initialize the UART module.
 *
 *  The UART peripherals controlled by the UART module are determined by the
 *  UART_config variable.
 */
extern void EK_TM4C129EXL_initUART(void);

/*!
 *  @brief  Initialize board specific USB settings
 *
 *  This function initializes the board specific USB settings and pins based on
 *  the USB mode of operation.
 *
 *  @param      usbMode    USB mode of operation
 */
extern void EK_TM4C129EXL_initUSB(EK_TM4C129EXL_USBMode usbMode);

/*!
 *  @brief  Initialize board specific USBMSCHFatFs settings
 *
 *  This function initializes the board specific USBMSCHFatFs settings and then
 *  calls the USBMSCHFatFs_init API to initialize the USBMSCHFatFs module.
 *
 *  The USBMSCHFatFs peripherals controlled by the USBMSCHFatFs module are
 *  determined by the USBMSCHFatFs_config variable.
 */
extern void EK_TM4C129EXL_initUSBMSCHFatFs(void);

/*!
 *  @brief  Initialize board specific Watchdog settings
 *
 *  This function initializes the board specific Watchdog settings and then
 *  calls the Watchdog_init API to initialize the Watchdog module.
 *
 *  The Watchdog peripherals controlled by the Watchdog module are determined
 *  by the Watchdog_config variable.
 */
extern void EK_TM4C129EXL_initWatchdog(void);


#ifdef __cplusplus
}
#endif

#endif /* __EK_TM4C129EXL_H */
