/** \file rn487x.c
 *  \brief This file contains APIs to access features support by RN487X series devices.
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

#include "rn487x.h"
#include "../config/default/rn487x/rn487x_interface.h"
#include "definitions.h" 
#include <string.h>
#include <stddef.h>
#include <stdlib.h> 

/* This value depends upon the System Clock Frequency, Baudrate value and Error percentage of Baudrate*/
#define RESPONSE_TIMEOUT 65 
/**
 * \def STATUS_MESSAGE_DELIMITER
 * This Variable provide a definition of the RN487X devices PRE/POST status message delimiter.
 */
char STATUS_MESSAGE_DELIMITER = '%';

bool skip_Delimter = false;
static uint8_t cmdBuf[64];                                 /**< Command TX Buffer */
static uint8_t dummyread;

static char *asyncBuffer;                           /**< Async Message Buffer */
static uint8_t asyncBufferSize;                     /**< Size of the Async Message Buffer */
static char *pHead;                                 /**< Pointer to the Head of the Async Message Buffer */
static uint8_t peek = 0;                            /**< Recieved Non-Status Message Data */
static bool dataReady = false;                      /**< Flag which indicates whether Non-Status Message Data is ready */
uint8_t resp[100];

/**
 * \brief This function filters status messages from RN487x data.
 * \param void This function takes no params.
 * \return a boolean value
 * \retval dataReady Returns true if data is ready; false otherwise.
 */
static bool RN487x_FilterData(void);

bool RN487x_Init(void)
{
    //Enter reset
    RN487x.ResetModule(true);
    //Wait for Reset
    RN487x.DelayMs(RN487x_RESET_DELAY_TIME);
    //Exit reset
    RN487x.ResetModule(false);

    //Wait while RN Device is booting up
    RN487x.DelayMs(RN487x_STARTUP_DELAY);

    //Remove unread data sent by RN487x, if any
    while (RN487x.DataReady())
    {
        dummyread=RN487x.Read();
    }
    
    return true;
}

void RN487x_SendCmd(const uint8_t *cmd, uint8_t cmdLen)
{
    uint8_t index = 0;

	do{
        if (RN487x.TransmitDone())
        {
            RN487x.Write(cmd[index]);
            index++;
        }
    }
    while(index < cmdLen);
    while(!RN487x.TransmitDone());
}

uint8_t RN487x_GetCmd(const uint8_t *getCmd, uint8_t getCmdLen)
{
	uint8_t index = 0, ResponseTime=0;

    RN487x_SendCmd(getCmd, getCmdLen);

	//Wait for the response time
    while(!RN487x.DataReady() && ResponseTime<=RESPONSE_TIMEOUT)
    {
        RN487x.DelayMs(1);
        ResponseTime++;
    }
    do
    {
        //Read Ready data 
        if(RN487x.DataReady())
        {
            resp[index++]=RN487x.Read();
        }
    }
    while (resp[index - 1U] != '>');

    return index;
}

bool RN487x_ReadMsg(const uint8_t *expectedMsg, uint8_t msgLen)
{
    unsigned int ResponseRead=0,ResponseTime=0,ResponseCheck=0;
	//Wait for the response time
    while(!RN487x.DataReady() && ResponseTime<=RESPONSE_TIMEOUT)
    {
        RN487x.DelayMs(1);
        ResponseTime++;
    }
    
    //Read Ready data 
    while(RN487x.DataReady())
    {
        resp[ResponseRead]=RN487x.Read();
        <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
		UART_CDC_write(resp[ResponseRead]);
        </#if>
        ResponseRead++;
    }
	//Comparing length of response expected
    if (ResponseRead != msgLen)
    {
        return false;
    }
    //Comparing the Response with expected result
    for(ResponseCheck=0;ResponseCheck<ResponseRead;ResponseCheck++)
    {
        if (resp[ResponseCheck] != expectedMsg[ResponseCheck])
        {
            return false;
        }
    }

    return true;
}

bool RN487x_ReadDefaultResponse(void)
{
    char DefaultResponse[30];
    bool status = false;
    unsigned int ResponseWait=0,DataReadcount=0;
    while(!RN487x.DataReady() && ResponseWait<=RESPONSE_TIMEOUT)
    {
        RN487x.DelayMs(1);
        ResponseWait++;
    }
    while(RN487x.DataReady())
    {
        DefaultResponse[DataReadcount]=RN487x.Read();
    <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
		UART_CDC_write((uint8_t)DefaultResponse[DataReadcount]);
    </#if>
        DataReadcount++;
    }
    switch (DefaultResponse[0])
    {
        case 'A':
        {
            if ((DefaultResponse[1] == 'O') && (DefaultResponse[2] == 'K'))
            {
                status = true;
            }

            break;
        }
        case 'E':
        {
            if ((DefaultResponse[1] == 'r') && (DefaultResponse[2] == 'r'))
            {
                status = false;
            }

            break;
        }
        default:
        {
            return status;
        }
    }


  
    return status;
}

bool RN487x_SendCommand_ReceiveResponse(const uint8_t *cmdMsg, uint8_t cmdLen, const uint8_t *responsemsg, uint8_t responseLen)
{
    unsigned int ResponseRead=0,ResponseTime=0,ResponseCheck=0;

    //Flush out any unread data
    while (RN487x.DataReady())
    {
        RN487x.Read();
    }
    
    //Sending Command to UART
    RN487x_SendCmd(cmdMsg, cmdLen);
    //Wait for the response time
    while(!RN487x.DataReady() && ResponseTime<=RESPONSE_TIMEOUT)
        {
        RN487x.DelayMs(1);
        ResponseTime++;
        }
    
    //Read Ready data 
    while(RN487x.DataReady())
        {
        resp[ResponseRead]=RN487x.Read();
		<#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
		UART_CDC_write((uint8_t)resp[ResponseRead]);
		</#if>
        ResponseRead++;
    }
	//Comparing length of response expected
    if (ResponseRead != responseLen)
            {
        return false;
            }
    //Comparing the Response with expected result
    for(ResponseCheck=0;ResponseCheck<ResponseRead;ResponseCheck++)
    {
        if (resp[ResponseCheck] != responsemsg[ResponseCheck])
        {
            return false;
        }
    }
    return true;
}


bool RN487x_EnterCmdMode(void)
{
    const uint8_t cmdModeResponse[] = {'C', 'M', 'D', '>', ' '};

    cmdBuf[0] = '$';
    cmdBuf[1] = '$';
    cmdBuf[2] = '$';


    return RN487x_SendCommand_ReceiveResponse(cmdBuf, 3U, cmdModeResponse,5U);
}

bool RN487x_EnterDataMode(void)
{
    const uint8_t dataModeResponse[] = {'E', 'N', 'D', '\r', '\n'};

    cmdBuf[0] = '-';
    cmdBuf[1] = '-';
    cmdBuf[2] = '-';
    cmdBuf[3] = '\r';
    cmdBuf[4] = '\n';


    return RN487x_SendCommand_ReceiveResponse(cmdBuf, 5U, dataModeResponse,5U);
}


bool RN487x_SetName(const uint8_t *name, uint8_t nameLen)
{
    uint8_t index;
	const uint8_t cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};

    cmdBuf[0] = 'S';
    cmdBuf[1] = 'N';
    cmdBuf[2] = ',';

    for (index = 0; index < nameLen; index++)
    {
        cmdBuf[3 + index] = name[index];
    }
    index = index + 3;

    cmdBuf[index++] = '\r';
    cmdBuf[index++] = '\n';

    return RN487x_SendCommand_ReceiveResponse(cmdBuf, nameLen + 5U, cmdPrompt, 10);

}

bool RN487x_SetBaudRate(uint8_t baudRate)
{
    uint8_t temp = (baudRate >> 4);
	const uint8_t cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'B';
    cmdBuf[2] = ',';
    cmdBuf[3] = NIBBLE2ASCII(temp);
	temp = (baudRate & 0x0F);
    cmdBuf[4] = NIBBLE2ASCII(temp);
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';


	return RN487x_SendCommand_ReceiveResponse(cmdBuf, 7U, cmdPrompt, 10);
}

bool RN487x_SetServiceBitmap(uint8_t serviceBitmap)
{
    const uint8_t cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    uint8_t temp = (serviceBitmap >> 4);

    cmdBuf[0] = 'S';
    cmdBuf[1] = 'S';
    cmdBuf[2] = ',';
    cmdBuf[3] = NIBBLE2ASCII(temp);
    temp = (serviceBitmap & 0x0F);
    cmdBuf[4] = NIBBLE2ASCII(temp);
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';


	return RN487x_SendCommand_ReceiveResponse(cmdBuf, 7U, cmdPrompt, 10);
}

bool RN487x_SetFeaturesBitmap(uint16_t featuresBitmap)
{
    const uint8_t cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    uint8_t temp = (uint8_t) (featuresBitmap >> 12);

    cmdBuf[0] = 'S';
    cmdBuf[1] = 'R';
    cmdBuf[2] = ',';
    temp = temp & 0x0F;
    cmdBuf[3] = NIBBLE2ASCII(temp);
    temp = (uint8_t) (featuresBitmap >> 8);
    temp = temp & 0x0F;
    cmdBuf[4] = NIBBLE2ASCII(temp);
    temp = (uint8_t) (featuresBitmap >> 4);
    temp = temp & 0x0F;
    cmdBuf[5] = NIBBLE2ASCII(temp);
    temp = (uint8_t) featuresBitmap;
    temp = temp & 0x0F;
    cmdBuf[6] = NIBBLE2ASCII(temp);
    cmdBuf[7] = '\r';
    cmdBuf[8] = '\n';


	return RN487x_SendCommand_ReceiveResponse(cmdBuf, 9U, cmdPrompt, 10);
}

bool RN487x_SetIOCapability(uint8_t ioCapability)
{
    const uint8_t cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'A';
    cmdBuf[2] = ',';
    cmdBuf[3] = NIBBLE2ASCII(ioCapability);
    cmdBuf[4] = '\r';
    cmdBuf[5] = '\n';


	return RN487x_SendCommand_ReceiveResponse(cmdBuf, 6U, cmdPrompt, 10);
}

bool RN487x_SetPinCode(const char *pinCode, uint8_t pinCodeLen)
{
    const uint8_t cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    uint8_t index;

    cmdBuf[0] = 'S';
    cmdBuf[1] = 'P';
    cmdBuf[2] = ',';

    for (index = 0; index < pinCodeLen; index++)
    {
        cmdBuf[3 + index] = pinCode[index];
    }
    index = index + 3;
    cmdBuf[index++] = '\r';
    cmdBuf[index++] = '\n';


	return RN487x_SendCommand_ReceiveResponse(cmdBuf, index, cmdPrompt, 10);
}

bool RN487x_SetStatusMsgDelimiter(char preDelimiter, char postDelimiter)
{
    const uint8_t cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    cmdBuf[0] = 'S';
    cmdBuf[1] = '%';
    cmdBuf[2] = ',';
    cmdBuf[3] = preDelimiter;
    cmdBuf[4] = ',';
    cmdBuf[5] = postDelimiter;
    cmdBuf[6] = '\r';
    cmdBuf[7] = '\n';

	return RN487x_SendCommand_ReceiveResponse(cmdBuf, 8, cmdPrompt, 10);

    }



bool RN487x_SetOutputs(RN487x_gpio_bitmap_t bitMap)
{
    const uint8_t cmdPrompt[] = {'A', 'O', 'K', '\r', '\n', 'C', 'M', 'D', '>', ' '};
    char ioHighNibble = '0';
    char ioLowNibble = '0';
    char stateHighNibble = '0';
    char stateLowNibble = '0';
    
    // Output pins configurations
    if (bitMap.ioBitMap.p1_3)
    {
        ioHighNibble = '1';
    }
    else
    {
        ioHighNibble = '0';
    }
    ioLowNibble = ( (0x0F & bitMap.ioBitMap.gpioBitMap) + '0');
    
    // High/Low Output settings
    if (bitMap.ioStateBitMap.p1_3_state)
    {
        stateHighNibble = '1';
    }
    else
    {
        stateHighNibble = '0';
    }
    stateLowNibble = ( (0x0F & bitMap.ioStateBitMap.gpioStateBitMap) + '0');

    cmdBuf[0] = '|';    // I/O
    cmdBuf[1] = 'O';    // Output
    cmdBuf[2] = ',';
    cmdBuf[3] = ioHighNibble;       // - | - | - | P1_3
    cmdBuf[4] = ioLowNibble;        // P1_2 | P3_5 | P2_4 | P2_2
    cmdBuf[5] = ',';
    cmdBuf[6] = stateHighNibble;    // - | - | - | P1_3
    cmdBuf[7] = stateLowNibble;     // P1_2 | P3_5 | P2_4 | P2_2
    cmdBuf[8] = '\r';
    cmdBuf[9] = '\n';

	return RN487x_SendCommand_ReceiveResponse(cmdBuf, 10U, cmdPrompt, 10U);
}

RN487x_gpio_stateBitMap_t RN487x_GetInputsValues(RN487x_gpio_ioBitMap_t getGPIOs)
{
    char ioHighNibble = '0';
    char ioLowNibble = '0';
    uint8_t ioValue[] = {'0', '0'};
    RN487x_gpio_stateBitMap_t ioBitMapValue;
    ioBitMapValue.gpioStateBitMap = 0x00;
    
    // Output pins configurations
    if (getGPIOs.p1_3)
    {
        ioHighNibble = '1';
    }
    else
    {
        ioHighNibble = '0';
    }
    ioLowNibble = ( (0x0F & getGPIOs.gpioBitMap) + '0');

    cmdBuf[0] = '|';    // I/O
    cmdBuf[1] = 'I';    // Output
    cmdBuf[2] = ',';
    cmdBuf[3] = ioHighNibble;       // - | - | - | P1_3
    cmdBuf[4] = ioLowNibble;        // P1_2 | P3_5 | P2_4 | P2_2
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';

	RN487x_SendCommand_ReceiveResponse(cmdBuf, 7, ioValue, sizeof (ioValue));
    ioBitMapValue.gpioStateBitMap = ( (((ioValue[0] - '0') & 0x0F) << 4) | ((ioValue[1] - '0') & 0x0F) );
    return ioBitMapValue;
}

uint8_t * RN487x_GetRSSIValue(void)
{
    static uint8_t rssiResp[20];
    unsigned int ResponseRead=0,ResponseTime=0;

    cmdBuf[0] = 'M';
    cmdBuf[1] = '\r';
    cmdBuf[2] = '\n';

    RN487x_SendCmd(cmdBuf, 3);

	//Wait for the response time
    while(!RN487x.DataReady() && ResponseTime<=RESPONSE_TIMEOUT)
    {
        RN487x.DelayMs(1);
        ResponseTime++;
    }
    //Read Ready data 
    while(RN487x.DataReady())
    {
        resp[ResponseRead]=RN487x.Read();
        ResponseRead++;
    }
    rssiResp[0]=resp[0];
    rssiResp[1]=resp[1];
    rssiResp[2]=resp[2];
    return rssiResp;
}


bool RN487x_RebootCmd(void)
{
    bool RebootStatus = false;
    const uint8_t rebootResponse[] = {'R', 'e', 'b', 'o', 'o', 't', 'i', 'n', 'g', '\r', '\n'};

    cmdBuf[0] = 'R';
    cmdBuf[1] = ',';
    cmdBuf[2] = '1';
    cmdBuf[4] = '\r';
    cmdBuf[5] = '\n';
    RebootStatus = RN487x_SendCommand_ReceiveResponse(cmdBuf, 5U, rebootResponse, 11U);

	RN487x.DelayMs(250);

	return RebootStatus;
}

bool RN487x_FactoryReset(RN487x_FACTORY_RESET_MODE_t resetMode)
{
    bool FactoryResetStatus = false;
    const uint8_t reboot[] = {'R', 'e', 'b', 'o', 'o', 't', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'F', 'a', 'c', 't', 'o', 'r', 'y', ' ', 'R', 'e', 's', 'e', 't', '\r', '\n'};
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'F';
    cmdBuf[2] = ',';
    cmdBuf[4] = (char)resetMode;
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';
    FactoryResetStatus = RN487x_SendCommand_ReceiveResponse(cmdBuf, 6U, reboot, 28U);

	RN487x.DelayMs(250);

	return FactoryResetStatus;
}

bool RN487x_Disconnect(void)
{
    cmdBuf[0] = 'K';
    cmdBuf[1] = ',';
    cmdBuf[2] = '1';
    cmdBuf[3] = '\r';
    cmdBuf[4] = '\n';

    RN487x_SendCmd(cmdBuf, 5U);

    return RN487x_ReadDefaultResponse();
}
void RN487x_set_StatusDelimter(char Delimter_Character)
{
	STATUS_MESSAGE_DELIMITER = Delimter_Character;
}
char RN487x_get_StatusDelimter()
{
	return STATUS_MESSAGE_DELIMITER;
}
void RN487x_set_NoDelimter(bool value)
{
    skip_Delimter=value;
}
bool RN487x_get_NoDelimter()
{
    return skip_Delimter;
}

bool RN487x_SetAsyncMessageHandler(char* pBuffer, uint8_t len)
{
    if ((pBuffer != NULL) && (len > 1U))
    {
      asyncBuffer = pBuffer;
      asyncBufferSize = len - 1U;
      return true;
    }
    else
    {
        return false;
    }
}

bool RN487x_DataReady(void)
{
    if (dataReady)
    {
        return true;
    }
    
    if (RN487x.DataReady())
    {
        return RN487x_FilterData();
    }
    return false;
}

uint8_t RN487x_Read(void)
{
    while(RN487x_DataReady() == false){}; // Wait
    dataReady = false;
    return peek;
}

static bool RN487x_FilterData(void)
{
    static bool asyncBuffering = false;
    
    uint8_t readChar = RN487x.Read();
    
    if(asyncBuffering == true)
    {
        if(readChar == (uint8_t)STATUS_MESSAGE_DELIMITER)
        {
            asyncBuffering = false;
            *pHead = '\0';
            RN487x.AsyncHandler(asyncBuffer);
        }
        else if (pHead < asyncBuffer + asyncBufferSize)
        {
            *pHead++ = (char)readChar;
        }
        else
        {
            //do nothing
        }
    }
    else
    {
		if((readChar != (uint8_t)STATUS_MESSAGE_DELIMITER ) && ((RN487x_IsOTABegin() == false)))
        {        
            asyncBuffering = true;
            pHead = asyncBuffer;
            *pHead++ = (char)readChar;
        }
        else if ((readChar == (uint8_t)STATUS_MESSAGE_DELIMITER && (skip_Delimter == false)) && (RNBD_IsOTABegin() == false))
        {
            asyncBuffering = true;
            pHead = asyncBuffer;
        }
        else 
        {
			skip_Delimter = true;
            dataReady = true;
            peek = readChar;
        }
    }
    return dataReady;
}
