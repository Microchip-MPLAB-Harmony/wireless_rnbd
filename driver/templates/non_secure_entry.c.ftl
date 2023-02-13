/*******************************************************************************
 Non-secure entry source file for secure project

  Company:
    Microchip Technology Inc.

  File Name:
    nonsecure_entry.c

  Summary:
    Implements hooks for Non-secure application

  Description:
    This file is used to call specific API's in the secure world from the Non-Secure world.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END
#include "stdint.h"
#include "definitions.h"


<#if SERCOM_INTERFACE_NON_SECURE == "False" && RNBD_NON_SECURE == "True">

uint16_t __attribute__((cmse_nonsecure_entry)) BLE_SERCOM_Read(uint8_t* pRdBuffer, const uint16_t size)
{
     return ${SERCOM_INST}_USART_Read(pRdBuffer,size);
}

uint16_t __attribute__((cmse_nonsecure_entry)) BLE_SERCOM_ReadCountGet(void)
{
    return ${SERCOM_INST}_USART_ReadCountGet();
}

bool __attribute__((cmse_nonsecure_entry)) BLE_SERCOM_TransmitComplete( void )
{
    return ${SERCOM_INST}_USART_TransmitComplete();
}

uint16_t __attribute__((cmse_nonsecure_entry)) BLE_SERCOM_Write(uint8_t pWrBuffer, const uint16_t size )
{
   return ${SERCOM_INST}_USART_Write(&pWrBuffer, size);
}
</#if>

<#if SERCOM_INTERFACE_NON_SECURE == "True" && RNBD_NON_SECURE == "false">
#error "RNBD Interface dependency cannot be Non secure while RNBD is secure"
</#if>
<#if TC_INTERFACE_NON_SECURE == true && RNBD_NON_SECURE == false>
#error "RNBD Delay Service dependency cannot be Non secure while RNBD is secure"
</#if>

