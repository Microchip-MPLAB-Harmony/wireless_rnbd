/**
 * \file rn487x_interface.h
 * \brief This file provides and interface between the RN487x and the hardware.
 */
/*
    (c) 2023 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#ifndef RN487X_INTERFACE_H
#define	RN487X_INTERFACE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * \ingroup RN487X_INTERFACE
 * Enum of the RN487x System Configuration Modes
 */
typedef enum
{
    TEST_MODE           = 0x00,
    APPLICATION_MODE    = 0x01 
}RN487x_SYSTEM_MODES_t;

/**
 * \ingroup RN487X_INTERFACE
 * Struct of RN487X Interface Function Pointer Prototypes
 */
typedef struct
{
    // RN487x UART interface control
    void (*Write)(uint8_t txData);
    uint8_t (*Read)(void);
    bool (*TransmitDone)(void);
    bool (*DataReady)(void);
    // RN487x RX_IND pin control
    void (*IndicateRx)(bool value);
    // RN487x Reset pin control
    void (*ResetModule)(bool value);
    // RN487x Mode pin set
    void (*SetSystemMode)(RN487x_SYSTEM_MODES_t mode);
    // Delay API
    void (*DelayMs)(uint32_t delayCount);
    // Status Message Handler
    void (*AsyncHandler)(char* message);
}iRN487x_FunctionPtrs_t;

extern const iRN487x_FunctionPtrs_t RN487x;

/**
 * \ingroup RN_INTERFACE
 * \brief Checks Connected State of RN487x
 * \return Connected Status
 * \retval true - Connected.
 * \retval false - Not Connected
 */
bool RN487x_IsConnected(void);
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
uint8_t UART_CDC_Read(void);
void UART_CDC_write(uint8_t buffer);
size_t UART_CDC_DataReady(void);
</#if>
uint8_t UART_BLE_Read(void);
void UART_BLE_write(uint8_t buffer);
size_t UART_BLE_DataReady(void);
bool UART_BLE_TransmitDone(void);
bool RN487x_IsOTAComplete(void);

#endif	/* RN487X_INTERFACE_H */