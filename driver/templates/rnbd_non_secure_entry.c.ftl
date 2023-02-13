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
#include "stdint.h"
#include "definitions.h"
<#if RNBD_EXAMPLE_SELECTION??>
<#if (RNBD_EXAMPLE_SELECTION == "TRANSPARENT UART" || RNBD_EXAMPLE_SELECTION == "BASIC DATA EXCHANGE") && RNBD_NON_SECURE = false>
<#if RNBD_MODULE_SELECTION == "RNBD">
#include "examples/rnbd_example.h"
<#else>
#include "examples/rn487x_example.h"
</#if>
</#if>
</#if>

<#if RNBD_NON_SECURE_ENTRY = true && RNBD_NON_SECURE = false>
<#if RNBD_MODULE_SELECTION == "RNBD">
#include "rnHostLib/rnbd.h"
<#else>
#include "examples/rn487x.h"
</#if>
</#if>


<#if SERCOM_INTERFACE_NON_SECURE = true && RNBD_NON_SECURE = false>
#error "RNBD Sercom dependency 0 cannot be Non secure while RNBD is secure"
</#if>

<#if SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = true && SERCOM_INST??>
/*Non Secure Entry for RNBD BLE Interface Sercom(Dependency0)  API's*/

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
    return ${SERCOM_INST}_USART_WriteCountGet()? false:true;
}

uint16_t __attribute__((cmse_nonsecure_entry)) BLE_SERCOM_Write(uint8_t pWrBuffer, const uint16_t size )
{
   return ${SERCOM_INST}_USART_Write(&pWrBuffer, size);
}
</#if>

<#if SERCOM_CONSOLE_NON_SECURE = true && RNBD_NON_SECURE = false>
#error "RNBD Sercom dependency 1 cannot be Non secure while RNBD is secure"
</#if>

<#if SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = true && CONSOLE_SERCOM_INST?? && RNBD_EXAMPLE_SELECTION == "TRANSPARENT UART">
/*Non Secure Entry for RNBD Console Sercom(Dependency1) API's for Trasnparent UART Example*/

uint16_t __attribute__((cmse_nonsecure_entry)) CDC_SERCOM_Read(uint8_t* pRdBuffer, const uint16_t size)
{
     return ${CONSOLE_SERCOM_INST}_USART_Read(pRdBuffer,size);
}

uint16_t __attribute__((cmse_nonsecure_entry)) CDC_SERCOM_ReadCountGet(void)
{
    return ${CONSOLE_SERCOM_INST}_USART_ReadCountGet();
}

bool __attribute__((cmse_nonsecure_entry)) CDC_SERCOM_TransmitComplete( void )
{
    return ${CONSOLE_SERCOM_INST}_USART_WriteCountGet()? false:true;
}

uint16_t __attribute__((cmse_nonsecure_entry)) CDC_SERCOM_Write(uint8_t pWrBuffer, const uint16_t size )
{
   return ${CONSOLE_SERCOM_INST}_USART_Write(&pWrBuffer, size);
}
</#if>


<#if RNBD_NON_SECURE_ENTRY = true && RNBD_NON_SECURE = false>
/* Non-secure callable (entry) RNBD functions*/
bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_Init(void)
{
    return ${RNBD_MODULE_SELECTION}_Init();
}

void __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_SendCmd(const char *cmd, uint8_t cmdLen)
{
    ${RNBD_MODULE_SELECTION}_SendCmd(cmd,cmdLen);
}

uint8_t __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_GetCmd(const char *getCmd, uint8_t getCmdLen, char *getCmdResp)
{
    return ${RNBD_MODULE_SELECTION}_GetCmd(getCmd,getCmdLen, getCmdResp);

}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_ReadMsg(const char *expectedMsg, uint8_t msgLen)
{
    return ${RNBD_MODULE_SELECTION}_ReadMsg(expectedMsg, msgLen);
}

bool __attribute__((cmse_nonsecure_entry))${RNBD_MODULE_SELECTION}_Module_ReadDefaultResponse(void)
{
    return ${RNBD_MODULE_SELECTION}_ReadDefaultResponse();
}
/*
void __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_WaitForMsg(const char *expectedMsg, uint8_t msgLen)
{
    ${RNBD_MODULE_SELECTION}_WaitForMsg(expectedMsg,msgLen);
}
*/

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_EnterCmdMode(void)
{
    return ${RNBD_MODULE_SELECTION}_EnterCmdMode();
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_EnterDataMode(void)
{
    return ${RNBD_MODULE_SELECTION}_EnterDataMode();
}
/*
bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_SetName(const char *name, uint8_t nameLen)
{
    return ${RNBD_MODULE_SELECTION}_SetName(name, nameLen);
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_SetBaudRate(uint8_t baudRate)
{
    return ${RNBD_MODULE_SELECTION}_SetBaudRate(baudRate);
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_SetServiceBitmap(uint8_t serviceBitmap)
{
    return ${RNBD_MODULE_SELECTION}_SetServiceBitmap(serviceBitmap);
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_SetFeaturesBitmap(uint16_t featuresBitmap)
{
    return ${RNBD_MODULE_SELECTION}_SetFeaturesBitmap(featuresBitmap);
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_SetIOCapability(uint8_t ioCapability)
{
    return ${RNBD_MODULE_SELECTION}_SetIOCapability(ioCapability);
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_SetPinCode(const char *pinCode, uint8_t pinCodeLen)
{
    return ${RNBD_MODULE_SELECTION}_SetPinCode(pinCode,pinCodeLen);
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_SetStatusMsgDelimiter(char preDelimiter, char postDelimiter)
{
	return ${RNBD_MODULE_SELECTION}_SetStatusMsgDelimiter(preDelimiter,postDelimiter);
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_SetOutputs(${RNBD_MODULE_SELECTION}_gpio_bitmap_t bitMap)
{
    return ${RNBD_MODULE_SELECTION}_SetOutputs(bitMap);
}

${RNBD_MODULE_SELECTION}_gpio_stateBitMap_t __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_GetInputsValues(${RNBD_MODULE_SELECTION}_gpio_ioBitMap_t getGPIOs)
{
    return ${RNBD_MODULE_SELECTION}_GetInputsValues(getGPIOs);
}

uint8_t * __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_GetRSSIValue(void)
{
    return ${RNBD_MODULE_SELECTION}_GetRSSIValue();
}
*/

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_RebootCmd(void)
{
    return ${RNBD_MODULE_SELECTION}_RebootCmd();
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_FactoryReset(${RNBD_MODULE_SELECTION}_FACTORY_RESET_MODE_t resetMode)
{
    return ${RNBD_MODULE_SELECTION}_FactoryReset(resetMode);
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_Disconnect(void)
{
    return ${RNBD_MODULE_SELECTION}_Disconnect();
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_SetAsyncMessageHandler(char* pBuffer, uint8_t len)
{
    return  ${RNBD_MODULE_SELECTION}_SetAsyncMessageHandler(pBuffer,len);
}

bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_DataReady(void)
{
    return ${RNBD_MODULE_SELECTION}_DataReady();
}

uint8_t __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_Module_Read(void)
{
    return ${RNBD_MODULE_SELECTION}_Read();
}
</#if>

<#if RNBD_EXAMPLE_SELECTION??>
<#if (RNBD_EXAMPLE_SELECTION == "TRANSPARENT UART" || RNBD_EXAMPLE_SELECTION == "BASIC DATA EXCHANGE") && RNBD_NON_SECURE = false>
bool __attribute__((cmse_nonsecure_entry)) ${RNBD_MODULE_SELECTION}_ExampleInit(void)
{
     return ${RNBD_MODULE_SELECTION}_Example_Initialized();
}
</#if>
</#if>

