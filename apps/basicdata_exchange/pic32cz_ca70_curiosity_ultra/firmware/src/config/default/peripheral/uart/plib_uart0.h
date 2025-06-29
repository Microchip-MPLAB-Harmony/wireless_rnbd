/*******************************************************************************
  UART0 PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_uart0.h

  Summary:
    UART0 PLIB Header File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef PLIB_UART0_H
#define PLIB_UART0_H

#include "plib_uart_common.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Interface
// *****************************************************************************
// *****************************************************************************

#define UART0_FrequencyGet()    (uint32_t)(150000000UL)

/****************************** UART0 API *********************************/

void UART0_Initialize( void );

bool UART0_SerialSetup( UART_SERIAL_SETUP *setup, uint32_t srcClkFreq );

UART_ERROR UART0_ErrorGet( void );

size_t UART0_Write(uint8_t* pWrBuffer, const size_t size );

size_t UART0_WriteCountGet(void);

size_t UART0_WriteFreeBufferCountGet(void);

size_t UART0_WriteBufferSizeGet(void);

bool UART0_TransmitComplete(void);

bool UART0_WriteNotificationEnable(bool isEnabled, bool isPersistent);

void UART0_WriteThresholdSet(uint32_t nBytesThreshold);

void UART0_WriteCallbackRegister( UART_RING_BUFFER_CALLBACK callback, uintptr_t context);

size_t UART0_Read(uint8_t* pRdBuffer, const size_t size);

size_t UART0_ReadCountGet(void);

size_t UART0_ReadFreeBufferCountGet(void);

size_t UART0_ReadBufferSizeGet(void);

bool UART0_ReadNotificationEnable(bool isEnabled, bool isPersistent);

void UART0_ReadThresholdSet(uint32_t nBytesThreshold);

void UART0_ReadCallbackRegister( UART_RING_BUFFER_CALLBACK callback, uintptr_t context);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

// DOM-IGNORE-END
#endif // PLIB_UART0_H
