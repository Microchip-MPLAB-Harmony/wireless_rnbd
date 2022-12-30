/**
 * \file rn487x_interface.c
 * \brief This file provides and interface between the RN487X and the hardware.
 */
/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. 
    
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
#ifndef RN487X_INTERFACE_C
#define RN487X_INTERFACE_C

#include <string.h>
#include<stdio.h>
#include "rn487x_interface.h"
#include "definitions.h"
<#if TRUST_ZONE_ENABLED = true>
<#if (SERCOM_INTERFACE_NON_SECURE?? && SERCOM_CONSOLE_NON_SECURE??)>
<#if (SERCOM_INTERFACE_NON_SECURE?? && SERCOM_CONSOLE_NON_SECURE??) && (SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = true) || (SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = true)>
#include "../trustZone/rnbd/non_secure_entry.h"
</#if>
</#if>
</#if>

static bool connected = false,OTAComplete = false; //**< RN487x connection state */
static uint32_t delay_ms_cycles = CPU_CLOCK_FREQUENCY/1000;
uint8_t readbuffer[1];
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
uint8_t cdcreadbuffer[1];
</#if> 

/**
 * \ingroup RN487X_INTERFACE
 * \brief Initiate Hardware Reset of RN487x
 * 
 * This API is used to issue a hardware Reset to the RN487x.
 *
 * 
 * \param value true - Reset State false - Normal State
 * \return Nothing
 */
static void RN487x_Reset(bool value);

/**
 * \ingroup RN487X_INTERFACE
 * \brief Notify RN487x to expect incoming data
 * 
 * This API notifies the RN Device to expect incoming Data.
 * 
 * \param value true - RX Incoming false - No Data Incoming
 * \return Nothing
 * 
 */
static void RN487x_IndicateRx(bool value);

/**
 * \ingroup RN487X_INTERFACE
 * \brief Set the RN487x System Configuration Mode
 * 
 * This API sets the System Configuration Mode to Either Normal application Mode 
 * or Test Mode/Flash Update/EEPROM configuration
 * 
 * \param mode APPLICATION_MODE - Normal Application Mode TEST_MODE - Test Mode/Flash Update/EEPROM Configuration
 * \return Nothing
 */
static void RN487x_SetSystemMode(RN487x_SYSTEM_MODES_t mode);

/**
 * \ingroup RN487X_INTERFACE
 * \brief Handle RN487x Status Message
 * 
 * This API is used to handle incoming status messages.
 * It prints all status messages, If DISCONNECT or STREAM_OPEN is received it manages
 * the state of bool connected.
 * 
 * \param message Passed status message
 * \return Nothing
 */
static void RN487x_MessageHandler(char* message);

/**
 * \ingroup RN487X_INTERFACE
 * \brief Write API transmitting to RN module
 * 
 * This API is used to send data bytes to the RN module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param txData - data byte to send
 * \return Nothing
 */
static inline void RN487x_Write(uint8_t txData);

/**
 * \ingroup RN487X_INTERFACE
 * \brief Read API to capture data bytes from RN module
 * 
 * This API is used to receive data bytes to the RN module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return uint8_t readDataByte - Byte captured from RN487X module
 */
static inline uint8_t RN487x_read(void);

/**
 * \ingroup RN487X_INTERFACE
 * \brief Returns if Write to RN module was completed
 * 
 * This API is used to receive status of communication with RN module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return bool status - RN487x is ready for another data byte
 */
static inline bool RN487x_is_tx_done(void);

/**
 * \ingroup RN487X_INTERFACE
 * \brief Returns if Read from RN module is ready
 * 
 * This API is used to receive status of communication with RN module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return bool status - RN487x is ready to provide another byte
 */
static inline bool RN487x_is_rx_ready(void);

/**
 * \ingroup RN487X_INTERFACE
 * \brief Returns if Read from RN module is ready
 * 
 * This API is used to receive status of communication with RN module
 *
 * HINT: This API is in place to give compile time memory allocation.
 *       Functionality exist locally within file.
 *       Use of IN LINE to prevent additional stack depth requirement. 
 *       APIs can be injected in place if suitable to save (1) stack depth level
 * 
 * \param N/A
 * \return bool status - RN487x is ready to provide another byte
 */
static inline void RN487x_Delay(uint32_t delayCount);
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
/*****************************************************
*   *OPTIONAL* APPLICATION MESSAGE FORMATTING API(s)
******************************************************/  
/**
 * \ingroup RN487x_MESSAGE_TYPE
 * Enum of the MESSAGE TYPES supported in Driver Example(s)
 */
typedef enum 
{
    DISCONNECT_MSG  = 0,
    STREAM_OPEN_MSG = 1,
    GENERAL_MSG     = 2,
}RN487x_MESSAGE_TYPE;
/**
 * \def GENERAL_PRINT_SIZE_LIMIT
 * This macro provide a definition used to process 
 */
#define GENERAL_PRINT_SIZE_LIMIT        (100)
/**
 * \ingroup RN487x_MESSAGE
 * \brief Prints the START Message "<<< " for UART_CDC
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RN487x_PrintMessageStart(void);
/**
 * \ingroup RN487x_MESSAGE
 * \brief Prints the END Message ">>>\r\n" for UART_CDC
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RN487x_PrintMessageEnd(void);
/**
 * \ingroup RN487x_MESSAGE
 * \brief Prints the Indicator [ or ] to UART_CDC
 *        [ - Disconnected | ] - Connected
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RN487x_PrintIndicatorCharacters(RN487x_MESSAGE_TYPE msgType);
/**
 * \ingroup RN487x_MESSAGE
 * 
 * This API prints *Optional Application* Messages
 *
 * \param N/A
 * \return N/A
 */
static inline void RN487x_PrintMessage(char* passedMessage);
</#if>
/*****************************************************
*   Driver Instance Declaration(s) API(s)
******************************************************/  

const iRN487x_FunctionPtrs_t RN487x = {
    .Write = RN487x_Write,
    .Read = RN487x_read,
    .TransmitDone = RN487x_is_tx_done,
    .DataReady = RN487x_is_rx_ready,
    .IndicateRx = RN487x_IndicateRx,
    .ResetModule = RN487x_Reset,
    .SetSystemMode = RN487x_SetSystemMode,
    .DelayMs = RN487x_Delay,
    .AsyncHandler = RN487x_MessageHandler
};

/*****************************************************
*   Driver Public API
******************************************************/  

bool RN487x_IsConnected(void)
{
    return connected;
}

bool RN487x_IsOTAComplete(void)
{
    return OTAComplete;
}

/*****************************************************
*   Driver Implementation Private API(s)
******************************************************/  

static inline void RN487x_Write(uint8_t txData)
{
    UART_BLE_write(txData);
}

static inline uint8_t RN487x_read(void)
{
    return UART_BLE_Read();
     
}

static inline bool RN487x_is_tx_done(void)
{
    return (UART_BLE_TransmitDone());
}

static inline bool RN487x_is_rx_ready(void)
{
    return UART_BLE_DataReady();
}

<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE =="TRANSPARENT UART">
uint8_t UART_CDC_Read(void)
{
<#if TRUST_ZONE_ENABLED = true>
    <#if SERCOM_CONSOLE_NON_SECURE?? && SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = true>
	CDC_SERCOM_Read(cdcreadbuffer,1);
	</#if>
	<#if  (SERCOM_CONSOLE_NON_SECURE?? && CONSOLE_SERCOM_INST??)>
	<#if (SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_CONSOLE_NON_SECURE = true && RNBD_NON_SECURE = true)>
	${CONSOLE_SERCOM_INST}_USART_Read(cdcreadbuffer,1);
	</#if>
	</#if>
<#else>
	<#if CONSOLE_SERCOM_INST??>
	${CONSOLE_SERCOM_INST}_USART_Read(cdcreadbuffer,1);
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
	CDC_SERCOM_Write(buffer,1);
	</#if>
	<#if (SERCOM_CONSOLE_NON_SECURE?? && CONSOLE_SERCOM_INST??)>
	<#if (SERCOM_CONSOLE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_CONSOLE_NON_SECURE = true && RNBD_NON_SECURE = true)>
	${CONSOLE_SERCOM_INST}_USART_Write(&buffer, 1);
	</#if>
	</#if>
	<#else>
	<#if CONSOLE_SERCOM_INST??>
	${CONSOLE_SERCOM_INST}_USART_Write(&buffer, 1);
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
	return ${CONSOLE_SERCOM_INST}_USART_ReadCountGet();
	</#if>
	</#if>
	<#else>
	<#if CONSOLE_SERCOM_INST??>
	return ${CONSOLE_SERCOM_INST}_USART_ReadCountGet();
	</#if>
	</#if>
    
}
</#if>
uint8_t UART_BLE_Read(void)
{
<#if TRUST_ZONE_ENABLED = true>
    <#if SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = true>
	BLE_SERCOM_Read(readbuffer,1);
	</#if>
	<#if (SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INST??)>
	<#if (SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_INTERFACE_NON_SECURE = true && RNBD_NON_SECURE = true)>
	${SERCOM_INST}_USART_Read(readbuffer,1);
	</#if>
	</#if>
<#else>
	<#if SERCOM_INST??>
	${SERCOM_INST}_USART_Read(readbuffer,1);
	</#if>
</#if>
    return *(uint8_t*)readbuffer;
}

void UART_BLE_write(uint8_t buffer)
{
<#if TRUST_ZONE_ENABLED = true>
   <#if SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = true>
	 BLE_SERCOM_Write(buffer,1);
	</#if>
	<#if (SERCOM_INTERFACE_NON_SECURE?? && SERCOM_INST??)>
	<#if (SERCOM_INTERFACE_NON_SECURE = false && RNBD_NON_SECURE = false)|| (SERCOM_INTERFACE_NON_SECURE = true && RNBD_NON_SECURE = true)>
	${SERCOM_INST}_USART_Write(&buffer, 1);
	</#if>
	</#if>
<#else>
	<#if SERCOM_INST??>	
	${SERCOM_INST}_USART_Write(&buffer, 1);
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
	return ${SERCOM_INST}_USART_ReadCountGet();
	</#if>
	</#if>
<#else>
	<#if SERCOM_INST??>
	return ${SERCOM_INST}_USART_ReadCountGet();
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
	return ${SERCOM_INST}_USART_WriteCountGet()? false:true;
	</#if>
	</#if>
	<#else>
	<#if SERCOM_INST??>
	return ${SERCOM_INST}_USART_WriteCountGet()? false:true;
	</#if>
	</#if>
}

static inline void RN487x_Delay(uint32_t delayCount)
{
    if(delayCount > 0)
    {
        delayCount *= delay_ms_cycles;
        while(delayCount--)
        {
            __NOP();
        }
    }
}

static void RN487x_Reset(bool value)
{
<#if BT_RST_Pin_Selected>
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

static void RN487x_IndicateRx(bool value)
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

static void RN487x_SetSystemMode(RN487x_SYSTEM_MODES_t mode)
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
static inline void RN487x_PrintMessageStart(void)
{
    UART_CDC_write('<');
    UART_CDC_write('<');
    UART_CDC_write('<');
    UART_CDC_write(' ');
}
</#if>
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
static inline void RN487x_PrintMessageEnd(void)
{
    UART_CDC_write(' ');
    UART_CDC_write('>');
    UART_CDC_write('>');
    UART_CDC_write('>');
    UART_CDC_write(' ');
    UART_CDC_write('\r');
    UART_CDC_write('\n');
}
</#if>
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
static inline void RN487x_PrintIndicatorCharacters(RN487x_MESSAGE_TYPE msgType)
{
    if (DISCONNECT_MSG == msgType)
    {
        UART_CDC_write('[');
    }
    else if (STREAM_OPEN_MSG == msgType)
    {
        UART_CDC_write(']');
    }
    else
    {

    }
}
</#if>
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
static inline void RN487x_PrintMessage(char* passedMessage)
{
    char printCharacter [GENERAL_PRINT_SIZE_LIMIT];
    strcpy(printCharacter, passedMessage);
    for (uint8_t messageIndex = 0; messageIndex < strlen(passedMessage); messageIndex++)
    {
       UART_CDC_write(printCharacter[messageIndex]);  
    }
}
</#if>

static void RN487x_MessageHandler(char* message)
{
<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
    RN487x_MESSAGE_TYPE messageType = GENERAL_MSG;
    RN487x_PrintMessageStart();
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
		OTAComplete = false;
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
        OTAComplete = true;
        RN487x.Write('\r');
        RN487x.Write('\n');        

        RN487x.Write('O');
        RN487x.Write('T');
        RN487x.Write('A');
        RN487x.Write('A');
        RN487x.Write(',');
        RN487x.Write('0');
        RN487x.Write('1');
        RN487x.Write('\r');
        RN487x.Write('\n');
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
    RN487x_PrintMessage(message);
    RN487x_PrintMessageEnd();
    RN487x_PrintIndicatorCharacters(messageType);
	</#if>
</#if>	

<#if !BT_STATUS_PIN_CHECK_ENABLE>	
    if (strstr(message, "DISCONNECT"))
    {
	<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
        messageType = DISCONNECT_MSG;
	</#if>
        connected = false;
		OTAComplete = false;
    }
    else if (strstr(message, "STREAM_OPEN"))
    {
	<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
        messageType = STREAM_OPEN_MSG;
	</#if>
        connected = true;
    }
	else if (strstr(message, "OTA_REQ"))
    {
        OTAComplete = true;
        RN487x.Write('\r');
        RN487x.Write('\n');        

        RN487x.Write('O');
        RN487x.Write('T');
        RN487x.Write('A');
        RN487x.Write('A');
        RN487x.Write(',');
        RN487x.Write('0');
        RN487x.Write('1');
        RN487x.Write('\r');
        RN487x.Write('\n');
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
    RN487x_PrintMessage(message);
    RN487x_PrintMessageEnd();
    RN487x_PrintIndicatorCharacters(messageType);
	</#if>	
	
</#if>	
}


#endif