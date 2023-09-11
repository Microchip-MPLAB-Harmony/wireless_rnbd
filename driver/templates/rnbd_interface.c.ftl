/**
 * \file rnbd_interface.c
 * \brief This file provides and interface between the RNBD and the hardware.
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
#include <string.h>
#include<stdio.h>
#include "rnbd_interface.h"
#include "definitions.h"
<#if TRUST_ZONE_ENABLED = true>
<#if (SERCOM_INTERFACE_NON_SECURE?? && SERCOM_CONSOLE_NON_SECURE??)>
<#if (SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = true) && (SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = true)>
#include "../../../trustZone/rnbd/non_secure_entry.h"
</#if>
</#if>
</#if>

static bool connected = false,OTABegin = false; //**< RNBD connection state */
static uint32_t delay_ms_cycles = CPU_CLOCK_FREQUENCY/1000; 
static uint8_t readbuffer[1];
static size_t dummyread=0;
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE =="TRANSPARENT UART">
static uint8_t cdcreadbuffer[1];
</#if>

/**
 * \ingroup RNBD_INTERFACE
 * \brief Initiate Hardware Reset of RNBD
 * 
 * This API is used to issue a hardware Reset to the RNBD.
 *
 * 
 * \param value true - Reset State false - Normal State
 * \return Nothing
 */
static void RNBD_Reset(bool value);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Notify RNBD to expect incoming data
 * 
 * This API notifies the RNBD Device to expect incoming Data.
 * 
 * \param value true - RX Incoming false - No Data Incoming
 * \return Nothing
 * 
 */
static void RNBD_IndicateRx(bool value);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Set the RNBD System Configuration Mode
 * 
 * This API sets the System Configuration Mode to Either Normal application Mode 
 * or Test Mode/Flash Update/EEPROM configuration
 * 
 * \param mode APPLICATION_MODE - Normal Application Mode TEST_MODE - Test Mode/Flash Update/EEPROM Configuration
 * \return Nothing
 */
static void RNBD_SetSystemMode(RNBD_SYSTEM_MODES_t mode);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Handle RNBD Status Message
 * 
 * This API is used to handle incoming status messages.
 * It prints all status messages, If DISCONNECT or STREAM_OPEN is received it manages
 * the state of bool connected.
 * 
 * \param message Passed status message
 * \return Nothing
 */
static void RNBD_MessageHandler(char* message);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Write API transmitting to RNBD module
 * 
 * This API is used to send data bytes to the RNBD module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param txData - data byte to send
 * \return Nothing
 */
static inline void RNBD_Write(uint8_t txData);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Read API to capture data bytes from RNBD module
 * 
 * This API is used to receive data bytes to the RNBD module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return uint8_t readDataByte - Byte captured from RNBD module
 */
static inline uint8_t RNBD_read(void);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Returns if Write to RNBD module was completed
 * 
 * This API is used to receive status of communication with RNBD module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return bool status - RNBD is ready for another data byte
 */
static inline bool RNBD_is_tx_done(void);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Returns if Read from RNBD module is ready
 * 
 * This API is used to receive status of communication with RNBD module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return bool status - RNBD is ready to provide another byte
 */
static inline bool RNBD_is_rx_ready(void);

/**
 * \ingroup RNBD_INTERFACE
 * \brief Returns if Read from RNBD module is ready
 * 
 * This API is used to receive status of communication with RNBD module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return bool status - RNBD is ready to provide another byte
 */
static inline void RNBD_Delay(uint32_t delayCount);
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
/*****************************************************
*   *OPTIONAL* APPLICATION MESSAGE FORMATTING API(s)
******************************************************/  
/**
 * \ingroup RNBD_MESSAGE_TYPE
 * Enum of the MESSAGE TYPES supported in Driver Example(s)
 */
typedef enum 
{
    DISCONNECT_MSG  = 0,
    STREAM_OPEN_MSG = 1,
    GENERAL_MSG     = 2,
}RNBD_MESSAGE_TYPE;
/**
 * \def GENERAL_PRINT_SIZE_LIMIT
 * This macro provide a definition used to process 
 */
#define GENERAL_PRINT_SIZE_LIMIT        (100)
/**
 * \ingroup RNBD_MESSAGE
 * \brief Prints the START Message "<<< " for UART_CDC
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RNBD_PrintMessageStart(void);
/**
 * \ingroup RNBD_MESSAGE
 * \brief Prints the END Message ">>>\r\n" for UART_CDC
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RNBD_PrintMessageEnd(void);
/**
 * \ingroup RNBD_MESSAGE
 * \brief Prints the Indicator [ or ] to UART_CDC
 *        [ - Disconnected | ] - Connected
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RNBD_PrintIndicatorCharacters(RNBD_MESSAGE_TYPE msgType);
/**
 * \ingroup RNBD_MESSAGE
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RNBD_PrintMessage(char* passedMessage);
</#if>
/*****************************************************
*   Driver Instance Declaration(s) API(s)
******************************************************/  

const iRNBD_FunctionPtrs_t RNBD = {
    .Write = RNBD_Write,
    .Read = RNBD_read,
    .TransmitDone = RNBD_is_tx_done,
    .DataReady = RNBD_is_rx_ready,
    .IndicateRx = RNBD_IndicateRx,
    .ResetModule = RNBD_Reset,
    .SetSystemMode = RNBD_SetSystemMode,
    .DelayMs = RNBD_Delay,
    .AsyncHandler = RNBD_MessageHandler
};


/*****************************************************
*   Driver Public API
******************************************************/  

bool RNBD_IsConnected(void)
{
    return connected;
}

bool RNBD_IsOTABegin(void)
{
    return OTABegin;
}

/*****************************************************
*   Driver Implementation Private API(s)
******************************************************/  

static inline void RNBD_Write(uint8_t txData)
{
    UART_BLE_write(txData);
}

static inline uint8_t RNBD_read(void)
{
    return UART_BLE_Read();
     
}

static inline bool RNBD_is_tx_done(void)
{
    return (UART_BLE_TransmitDone());
}

static inline bool RNBD_is_rx_ready(void)
{
    return UART_BLE_DataReady();
}


<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE =="TRANSPARENT UART">
uint8_t UART_CDC_Read(void)
{    
   <#if TRUST_ZONE_ENABLED = true>
    <#if SERCOM_CONSOLE_NON_SECURE?? && SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = true>
    dummyread=CDC_SERCOM_Read(cdcreadbuffer,1);
    </#if>
    <#if  (SERCOM_CONSOLE_NON_SECURE?? && CONSOLE_SERCOM_INST??)>
    <#if (SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_CONSOLE_NON_SECURE = true && RNBD_NON_SECURE = true)>
    dummyread=${.vars["${CONSOLE_SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_Read(cdcreadbuffer,1);
    </#if>
    </#if>
<#else>
    <#if CONSOLE_SERCOM_INST??>
    dummyread=${.vars["${CONSOLE_SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_Read(cdcreadbuffer,1);
    </#if>
</#if>
    return *(uint8_t*)cdcreadbuffer;
}
</#if>
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
void UART_CDC_write(uint8_t buffer)
{
    <#if TRUST_ZONE_ENABLED = true>
    <#if SERCOM_CONSOLE_NON_SECURE?? && SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = true>
    dummyread=CDC_SERCOM_Write(buffer,1);
    </#if>
    <#if (SERCOM_CONSOLE_NON_SECURE?? && CONSOLE_SERCOM_INST??)>
    <#if (SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_CONSOLE_NON_SECURE = true && RNBD_NON_SECURE = true)>
    dummyread=${.vars["${CONSOLE_SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_Write(&buffer, 1);
    </#if>
    </#if>
    <#else>
    <#if CONSOLE_SERCOM_INST??>
    dummyread=${.vars["${CONSOLE_SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_Write(&buffer, 1);
    </#if>
    </#if>
}
</#if>
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
size_t UART_CDC_DataReady(void)
{
<#if TRUST_ZONE_ENABLED = true>
    <#if SERCOM_CONSOLE_NON_SECURE?? && SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = true>
    return CDC_SERCOM_ReadCountGet();
    </#if>
    <#if  (SERCOM_CONSOLE_NON_SECURE?? && CONSOLE_SERCOM_INST??)>
    <#if (SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_CONSOLE_NON_SECURE = true && RNBD_NON_SECURE = true)>
    return ${.vars["${CONSOLE_SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_ReadCountGet();
    </#if>
    </#if>
    <#else>
    <#if CONSOLE_SERCOM_INST??>
    return ${.vars["${CONSOLE_SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_ReadCountGet();
    </#if>
    </#if>
}
</#if>
uint8_t UART_BLE_Read(void)
{
<#if TRUST_ZONE_ENABLED = true>
    <#if SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = true>
    dummyread=BLE_SERCOM_Read(readbuffer,1);
    </#if>
    <#if (SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INST??)>
    <#if (SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_INTERFACE_NON_SECURE = true && RNBD_NON_SECURE = true)>
    dummyread=${.vars["${SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_Read(readbuffer,1);
    </#if>
    </#if>
<#else>
    <#if SERCOM_INST??>
    dummyread=${.vars["${SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_Read(readbuffer,1);
    </#if>
</#if>
    return *(uint8_t*)readbuffer;
}

void UART_BLE_write(uint8_t buffer)
{
<#if TRUST_ZONE_ENABLED = true>
   <#if SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = true>
     dummyread=BLE_SERCOM_Write(buffer,1);
    </#if>
    <#if (SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INST??)>
    <#if (SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_INTERFACE_NON_SECURE = true && RNBD_NON_SECURE = true)>
    dummyread=${.vars["${SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_Write(&buffer, 1);
    </#if>
    </#if>
<#else>
    <#if SERCOM_INST??>
    dummyread=${.vars["${SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_Write(&buffer, 1);
    </#if>
</#if>
}

size_t UART_BLE_DataReady(void)
{
<#if TRUST_ZONE_ENABLED = true>
    <#if SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = true>
    return BLE_SERCOM_ReadCountGet();
    </#if>
    <#if (SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INST??)>
    <#if (SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_INTERFACE_NON_SECURE = true && RNBD_NON_SECURE = true)>
    return ${.vars["${SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_ReadCountGet();
    </#if>
    </#if>
<#else>
    <#if SERCOM_INST??>
    return ${.vars["${SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_ReadCountGet();
    </#if>
</#if>
}

bool UART_BLE_TransmitDone(void)
{
<#if TRUST_ZONE_ENABLED = true>
    <#if SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = true>
     return BLE_SERCOM_TransmitComplete();
    </#if>
    <#if (SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INST??)>
    <#if (SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_INTERFACE_NON_SECURE = true && RNBD_NON_SECURE = true)>
    return ${.vars["${SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_WriteCountGet()? false:true;
    </#if>
    </#if>
    <#else>
    <#if SERCOM_INST??>
    return ${.vars["${SERCOM_INST?lower_case}"].USART_PLIB_API_PREFIX}_WriteCountGet()? false:true;
    </#if>
    </#if>
}

static inline void RNBD_Delay(uint32_t delayCount)
{
    if(delayCount > 0U)
    {
        delayCount *= delay_ms_cycles;
        while(delayCount--)
        {
			<#if core.CoreArchitecture == "CORTEX-M0PLUS">
            __NOP();
			</#if>
			<#if core.CoreArchitecture == "CORTEX-M4">
            __NOP();
			</#if>
			<#if core.CoreArchitecture == "CORTEX-M23">
            __NOP();
			</#if>
			<#if core.CoreArchitecture == "CORTEX-M7">
            __NOP();
			</#if>
			<#if core.CoreArchitecture == "MIPS">
            asm("NOP");
			</#if>
        }
    }
}

static void RNBD_Reset(bool value)
{
<#if BLE_RST_PIN_SELECTED == true>
    if (true == value)
    {
        BT_RST_Clear();
    }
    else
    {
        BT_RST_Set();
    }
</#if>
}

static void RNBD_IndicateRx(bool value)
{
<#if BT_RX_IND_PIN_CHECK_ENABLE>
    if (true == value)
    {
        BT_RX_IND_Clear();
    }
    else
    {
        BT_RX_IND_Set();
    }
<#else>
    // Implement desired support code for RX Indicator
</#if>
}

static void RNBD_SetSystemMode(RNBD_SYSTEM_MODES_t mode)
{
<#if BT_SYS_MODE_PIN_CHECK_ENABLE>
    if (APPLICATION_MODE == mode)
    {
        BT_MODE_Set();
    }
    else
    {
        BT_MODE_Clear();
    }
<#else>
    // Implement desired support code for system Mode
</#if>
}

/*****************************************************
*   *Optional* Message Formatting Private API(s)
******************************************************/  
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
static inline void RNBD_PrintMessageStart(void)
{
    UART_CDC_write((uint8_t)'<');
    UART_CDC_write((uint8_t)'<');
    UART_CDC_write((uint8_t)'<');
    UART_CDC_write((uint8_t)' ');
}
</#if>
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
static inline void RNBD_PrintMessageEnd(void)
{
    UART_CDC_write((uint8_t)' ');
    UART_CDC_write((uint8_t)'>');
    UART_CDC_write((uint8_t)'>');
    UART_CDC_write((uint8_t)'>');
    UART_CDC_write((uint8_t)' ');
    UART_CDC_write((uint8_t)'\r');
    UART_CDC_write((uint8_t)'\n');
}
</#if>
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
static inline void RNBD_PrintIndicatorCharacters(RNBD_MESSAGE_TYPE msgType)
{
    if (DISCONNECT_MSG == msgType)
    {
        UART_CDC_write((uint8_t)'[');
    }
    else if (STREAM_OPEN_MSG == msgType)
    {
        UART_CDC_write((uint8_t)']');
    }
    else
    {

    }
}
</#if>
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
static inline void RNBD_PrintMessage(char* passedMessage)
{
    char printCharacter [GENERAL_PRINT_SIZE_LIMIT];
    strcpy(printCharacter, passedMessage);
    for (uint8_t messageIndex = 0; messageIndex < strlen(passedMessage); messageIndex++)
    {
       UART_CDC_write((uint8_t)printCharacter[messageIndex]);  
    }
}
</#if>

static void RNBD_MessageHandler(char* message)
{
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
    RNBD_MESSAGE_TYPE messageType = GENERAL_MSG;
    RNBD_PrintMessageStart();
</#if>

<#if BT_STATUS_PIN_CHECK_ENABLE>

    int BT_Status_Ind1 = BT_STATUS1_Get();
    int BT_Status_Ind2 = BT_STATUS2_Get(); 

    if (!BT_Status_Ind1 && !BT_Status_Ind2)
    {
    <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
        messageType = DISCONNECT_MSG;
    </#if>
        connected = false;
        OTABegin = false;
    }
    else if (BT_Status_Ind1 && BT_Status_Ind2)
    {
    <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
        messageType = STREAM_OPEN_MSG;
    </#if>
        connected = true;
    }
    else if (strstr(message, "OTA_REQ"))
    {
        OTABegin = true;        

        RNBD.Write('O');
        RNBD.Write('T');
        RNBD.Write('A');
        RNBD.Write('A');
        RNBD.Write(',');
        RNBD.Write('0');
        RNBD.Write('1');
        RNBD.Write(',');
        RNBD.Write('0');
        RNBD.Write('2');
        RNBD.Write('1');
        RNBD.Write('3');
        RNBD.Write('\r');
        RNBD.Write('\n');  
    }
	else if (strstr(message, "OTA_START")!= NULL)
    {
        OTABegin = true;
    }
    else
    {
    <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
        messageType = GENERAL_MSG;
    <#else>
     // Left Intentionally Blank: For General Messages
    </#if>
    }
    <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
    RNBD_PrintMessage(message);
    RNBD_PrintMessageEnd();
    RNBD_PrintIndicatorCharacters(messageType);
    </#if>
    

</#if>


<#if !BT_STATUS_PIN_CHECK_ENABLE>
    if (strstr(message, "DISCONNECT")!= NULL)
    {
    <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
        messageType = DISCONNECT_MSG;
    </#if>
        connected = false;
        OTABegin = false;
    }
    else if (strstr(message, "STREAM_OPEN")!= NULL)
    {
    <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
        messageType = STREAM_OPEN_MSG;
    </#if>
        connected = true;
    }
    else if (strstr(message, "OTA_REQ")!= NULL)
    {
		OTABegin = true;
		
        RNBD.Write('O');
        RNBD.Write('T');
        RNBD.Write('A');
        RNBD.Write('A');
        RNBD.Write(',');
        RNBD.Write('0');
        RNBD.Write('1');
        RNBD.Write(',');
        RNBD.Write('0');
        RNBD.Write('2');
        RNBD.Write('1');
        RNBD.Write('3');
        RNBD.Write('\r');
        RNBD.Write('\n');    
    }
	else if (strstr(message, "OTA_START")!= NULL)
    {
        OTABegin = true;
    }
    else
    {
    <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
        messageType = GENERAL_MSG;
    <#else>
     // Left Intentionally Blank: For General Messages
    </#if>
    }
    <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
    RNBD_PrintMessage(message);
    RNBD_PrintMessageEnd();
    RNBD_PrintIndicatorCharacters(messageType);
    </#if>
</#if>
}
