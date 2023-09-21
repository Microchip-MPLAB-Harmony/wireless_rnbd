/*******************************************************************************
 Non-secure entry header File for non-secure project

  Company:
    Microchip Technology Inc.

  File Name:
    non_secure_entry.h

  Summary:
    Function prototype declarations for Non-secure callable functions

  Description:
    This file is used to declare non-secure callable functions in non-secure project.

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#ifndef NON_SECURE_ENTRY_H_
#define NON_SECURE_ENTRY_H_

<#if SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = true>
extern uint16_t BLE_SERCOM_Read(uint8_t* pRdBuffer, const uint16_t size);

extern uint16_t BLE_SERCOM_ReadCountGet(void);

extern bool BLE_SERCOM_TransmitComplete( void );

extern uint16_t BLE_SERCOM_Write(uint8_t pWrBuffer, const uint16_t size );
</#if>

<#if SERCOM_INTERFACE_NON_SECURE = true && RNBD_NON_SECURE = false>
#error "RNBD Sercom dependency 0 cannot be Non secure while RNBD is secure"
</#if>

<#if SERCOM_CONSOLE_NON_SECURE = true && RNBD_NON_SECURE = false>
#error "RNBD Sercom dependency 1 cannot be Non secure while RNBD is secure"
</#if>

<#if SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = true>
extern uint16_t CDC_SERCOM_Read(uint8_t* pRdBuffer, const uint16_t size);

extern uint16_t CDC_SERCOM_ReadCountGet(void);

extern bool CDC_SERCOM_TransmitComplete( void );

extern uint16_t CDC_SERCOM_Write(uint8_t pWrBuffer, const uint16_t size );
</#if>

<#if RNBD_EXAMPLE_SELECTION??>
<#if (RNBD_EXAMPLE_SELECTION == "TRANSPARENT UART" || RNBD_EXAMPLE_SELECTION == "BASIC DATA EXCHANGE") && RNBD_NON_SECURE = false>
extern bool ${RNBD_MODULE_SELECTION}_ExampleInit(void);
</#if>
</#if>

<#if RNBD_NON_SECURE_ENTRY = true && RNBD_NON_SECURE = false>
/**
 * \ingroup RNBD
 * Union of RNBD gpio BEHAVIOR state (Input/Output)
 * Bits (pins) set as (1) are considered OUTPUTS
 */
typedef union
{
    uint8_t gpioBitMap;
    struct
    {
        unsigned p2_2 : 1;          // 01
        unsigned p2_4 : 1;          // 02
        unsigned p3_5 : 1;          // 04
        unsigned p1_2 : 1;          // 08
        unsigned p1_3 : 1;          // 10
        unsigned reserved : 3;
    };
}RNBD_gpio_ioBitMap_t;


typedef enum
{
    SF_1 = 1,   //Reset to factory default
    //SF_2 = 2,   //Reset to factory default including private services and script
}RNBD_FACTORY_RESET_MODE_t;


/**
 * \ingroup RNBD
 * Union of RNBD gpio OUTPUT state (High/Low)
 * Bits (states) set as (1) are considered HIGH
 */
typedef union
{
    uint8_t gpioStateBitMap;
    struct
    {
        unsigned p2_2_state : 1;
        unsigned p2_4_state : 1;
        unsigned p3_5_state : 1;
        unsigned p1_2_state : 1;
        unsigned p1_3_state : 1;
        unsigned reserved : 3;
    };
}RNBD_gpio_stateBitMap_t;


/**
 * \ingroup RNBD
 * Union of RNBD gpio state & configuration
 * Used for I/O (|) related commands
 */
typedef union 
{
    uint16_t gpioMap;
    struct
    {
        RNBD_gpio_ioBitMap_t ioBitMap;
        RNBD_gpio_stateBitMap_t ioStateBitMap;
    };
}RNBD_gpio_bitmap_t;


/* Non-secure RNBD callable functions */
extern bool  ${RNBD_MODULE_SELECTION}_Module_Init(void);

extern void  ${RNBD_MODULE_SELECTION}_Module_SendCmd(const char *cmd, uint8_t cmdLen);

extern uint8_t  ${RNBD_MODULE_SELECTION}_Module_GetCmd(const char *getCmd, uint8_t getCmdLen);

extern bool  ${RNBD_MODULE_SELECTION}_Module_ReadMsg(const char *expectedMsg, uint8_t msgLen);
 
extern bool ${RNBD_MODULE_SELECTION}_Module_ReadDefaultResponse(void);

extern bool  ${RNBD_MODULE_SELECTION}_Module_SendCommand_ReceiveResponse(const char *cmdMsg, uint8_t cmdLen, const char *responsemsg, uint8_t responseLen);

extern bool  ${RNBD_MODULE_SELECTION}_Module_EnterCmdMode(void);

extern bool  ${RNBD_MODULE_SELECTION}_Module_EnterDataMode(void);

extern bool  ${RNBD_MODULE_SELECTION}_Module_SetName(const char *name, uint8_t nameLen);

extern bool  ${RNBD_MODULE_SELECTION}_Module_SetBaudRate(uint8_t baudRate);

extern bool  ${RNBD_MODULE_SELECTION}_Module_SetServiceBitmap(uint8_t serviceBitmap);
 
extern bool  ${RNBD_MODULE_SELECTION}_Module_SetFeaturesBitmap(uint16_t featuresBitmap);

extern bool  ${RNBD_MODULE_SELECTION}_Module_SetIOCapability(uint8_t ioCapability);

extern bool  ${RNBD_MODULE_SELECTION}_Module_SetPinCode(const char *pinCode, uint8_t pinCodeLen);

extern bool  ${RNBD_MODULE_SELECTION}_Module_SetStatusMsgDelimiter(char preDelimiter, char postDelimiter);

extern bool  ${RNBD_MODULE_SELECTION}_Module_SetOutputs(${RNBD_MODULE_SELECTION}_gpio_bitmap_t bitMap);

extern ${RNBD_MODULE_SELECTION}_gpio_stateBitMap_t  ${RNBD_MODULE_SELECTION}_Module_GetInputsValues(${RNBD_MODULE_SELECTION}_gpio_ioBitMap_t getGPIOs);
 
extern uint8_t *  ${RNBD_MODULE_SELECTION}_Module_GetRSSIValue(void);

extern bool  ${RNBD_MODULE_SELECTION}_Module_RebootCmd(void);

extern bool  ${RNBD_MODULE_SELECTION}_Module_FactoryReset(${RNBD_MODULE_SELECTION}_FACTORY_RESET_MODE_t resetMode);

extern bool  ${RNBD_MODULE_SELECTION}_Module_Disconnect(void);

extern bool  ${RNBD_MODULE_SELECTION}_Module_SetAsyncMessageHandler(char* pBuffer, uint8_t len);
 
extern bool  ${RNBD_MODULE_SELECTION}_Module_DataReady(void);

extern uint8_t  ${RNBD_MODULE_SELECTION}_Module_Read(void);

extern void  ${RNBD_MODULE_SELECTION}_Module_set_StatusDelimter(char Delimter_Character);

extern char  ${RNBD_MODULE_SELECTION}_Module_get_StatusDelimter(void);

extern void  ${RNBD_MODULE_SELECTION}_Module_set_NoDelimter(bool value);

extern bool  ${RNBD_MODULE_SELECTION}_Module_get_NoDelimter(void);
</#if>

#endif /* NON_SECURE_ENTRY_H_ */