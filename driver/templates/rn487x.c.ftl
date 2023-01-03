/** \file rn487x.c
 *  \brief This file contains APIs to access features support by RN487X series devices.
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

#include "rn487x.h"
#include "rn487x_interface.h"
#include "definitions.h" 

/**
 * \def STATUS_MESSAGE_DELIMITER
 * This macro provide a definition of the RN487X devices PRE/POST status message delimiter.
 */
#define STATUS_MESSAGE_DELIMITER        ('%')

uint8_t cmdBuf[64];                                 /**< Command TX Buffer */

const char * const rnHost_driver_version = "1.0.0"; /**<  Current RN HOST Driver Version */

static char *asyncBuffer;                           /**< Async Message Buffer */
static uint8_t asyncBufferSize;                     /**< Size of the Async Message Buffer */
static char *pHead;                                 /**< Pointer to the Head of the Async Message Buffer */
static uint8_t peek = 0;                            /**< Recieved Non-Status Message Data */
static bool dataReady = false;                      /**< Flag which indicates whether Non-Status Message Data is ready */

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
        RN487x.Read();
    }
    
    return true;
}

void RN487x_SendCmd(const uint8_t *cmd, uint8_t cmdLen)
{
    uint8_t index = 0;

    while (index < cmdLen)
    {
        if (RN487x.TransmitDone())
        {
            RN487x.Write(cmd[index]);
            index++;
        }
    }
}

uint8_t RN487x_GetCmd(const char *getCmd, uint8_t getCmdLen, char *getCmdResp)
{
    uint8_t index = 0;

    RN487x_SendCmd((uint8_t *) getCmd, getCmdLen);

    do
    {
        getCmdResp[index++] = RN487x.Read();
    }
    while (getCmdResp[index - 1] != '\n');

    return index;
}

bool RN487x_ReadMsg(const uint8_t *expectedMsg, uint8_t msgLen)
{
    uint8_t index;
    uint8_t resp;

    for (index = 0; index < msgLen; index++)
    {
        resp = RN487x.Read();
        <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
        UART_CDC_write(resp);
        </#if>
        if (resp != expectedMsg[index])
        {
            return false;
        }
    }

    return true;
}

bool RN487x_ReadDefaultResponse(void)
{
    uint8_t resp[3];
    bool status = false;

    resp[0] = RN487x.Read();
    resp[1] = RN487x.Read();
    resp[2] = RN487x.Read();
    <#if RN_HOST_EXAMPLE_APPLICATION_CHOICE == "TRANSPARENT UART">
    UART_CDC_write(resp[0]);
    UART_CDC_write(resp[1]);
    UART_CDC_write(resp[2]);
    </#if>
    switch (resp[0])
    {
        case 'A':
        {
            if ((resp[1] == 'O') && (resp[2] == 'K'))
                status = true;

            break;
        }
        case 'E':
        {
            if ((resp[1] == 'r') && (resp[2] == 'r'))
                status = false;

            break;
        }
        default:
        {
            return status;
        }
    }

    /* Read carriage return and line feed comes with response */
    RN487x.Read();
    RN487x.Read();

    //Read CMD>
    RN487x.Read();
    RN487x.Read();
    RN487x.Read();
    RN487x.Read();
    RN487x.Read();
  
    return status;
}

void RN487x_WaitForMsg(const char *expectedMsg, uint8_t msgLen)
{
    uint8_t index = 0;
    uint8_t resp;

    do
    {
        resp = RN487x.Read();

        if (resp == expectedMsg[index])
        {
            index++;
        }
        else
        {
            index = 0;
            if (resp == expectedMsg[index])
            {
                index++;
            }
        }
    }
    while (index < msgLen);
}

bool RN487x_EnterCmdMode(void)
{
    const uint8_t cmdPrompt[] = {'C', 'M', 'D', '>', ' '};

    cmdBuf[0] = '$';
    cmdBuf[1] = '$';
    cmdBuf[2] = '$';

    RN487x_SendCmd(cmdBuf, 3);

    return RN487x_ReadMsg(cmdPrompt, sizeof (cmdPrompt));
}

bool RN487x_EnterDataMode(void)
{
    const uint8_t cmdPrompt[] = {'E', 'N', 'D', '\r', '\n'};

    cmdBuf[0] = '-';
    cmdBuf[1] = '-';
    cmdBuf[2] = '-';
    cmdBuf[3] = '\r';
    cmdBuf[4] = '\n';

    RN487x_SendCmd(cmdBuf, 5);

    return RN487x_ReadMsg(cmdPrompt, sizeof (cmdPrompt));
}

bool RN487x_SetName(const char *name, uint8_t nameLen)
{
    uint8_t index;

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

    RN487x_SendCmd(cmdBuf, nameLen + 5);

    return RN487x_ReadDefaultResponse();
}

bool RN487x_SetBaudRate(uint8_t baudRate)
{
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'B';
    cmdBuf[2] = ',';
    cmdBuf[3] = ((uint8_t)(baudRate >> 4)) & 0x0F;
    cmdBuf[4] = (baudRate & 0x0F);
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';

    RN487x_SendCmd(cmdBuf, 7);

    return RN487x_ReadDefaultResponse();
}

bool RN487x_SetServiceBitmap(uint8_t serviceBitmap)
{
    uint8_t temp = (serviceBitmap >> 4);

    cmdBuf[0] = 'S';
    cmdBuf[1] = 'S';
    cmdBuf[2] = ',';
    cmdBuf[3] = NIBBLE2ASCII(temp);
    temp = (serviceBitmap & 0x0F);
    cmdBuf[4] = NIBBLE2ASCII(temp);
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';

    RN487x_SendCmd(cmdBuf, 7);

    return RN487x_ReadDefaultResponse();
}

bool RN487x_SetFeaturesBitmap(uint16_t featuresBitmap)
{
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

    RN487x_SendCmd(cmdBuf, 9);

    return RN487x_ReadDefaultResponse();
}

bool RN487x_SetIOCapability(uint8_t ioCapability)
{
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'A';
    cmdBuf[2] = ',';
    cmdBuf[3] = NIBBLE2ASCII(ioCapability);
    cmdBuf[4] = '\r';
    cmdBuf[5] = '\n';

    RN487x_SendCmd(cmdBuf, 6);

    return RN487x_ReadDefaultResponse();
}

bool RN487x_SetPinCode(const char *pinCode, uint8_t pinCodeLen)
{
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

    RN487x_SendCmd(cmdBuf, index);

    return RN487x_ReadDefaultResponse();
}

bool RN487x_SetStatusMsgDelimiter(char preDelimiter, char postDelimiter)
{
    cmdBuf[0] = 'S';
    cmdBuf[1] = '%';
    cmdBuf[2] = ',';
    cmdBuf[3] = preDelimiter;
    cmdBuf[4] = ',';
    cmdBuf[5] = postDelimiter;
    cmdBuf[6] = '\r';
    cmdBuf[7] = '\n';

    RN487x_SendCmd(cmdBuf, 8);

    if (RN487x_ReadDefaultResponse())
    {
        return true;
    }

    return false;
}

bool RN487x_SetOutputs(RN487x_gpio_bitmap_t bitMap)
{
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

    RN487x_SendCmd(cmdBuf, 10);
    return RN487x_ReadDefaultResponse();
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

    RN487x_SendCmd(cmdBuf, 7);
    RN487x_ReadMsg(ioValue, sizeof (ioValue));    
    ioBitMapValue.gpioStateBitMap = ( (((ioValue[0] - '0') & 0x0F) << 4) | ((ioValue[1] - '0') & 0x0F) );
    return ioBitMapValue;
}

uint8_t * RN487x_GetRSSIValue(void)
{
    static uint8_t resp[3];

    cmdBuf[0] = 'M';
    cmdBuf[1] = '\r';
    cmdBuf[2] = '\n';

    RN487x_SendCmd(cmdBuf, 3);

    resp[0] = RN487x.Read();
    resp[1] = RN487x.Read();
    resp[2] = RN487x.Read();

    // Read carriage return and line feed
    RN487x.Read();
    RN487x.Read();

    // Read CMD>
    RN487x.Read();
    RN487x.Read();
    RN487x.Read();
    RN487x.Read();
    RN487x.Read();

    return resp;
}

bool RN487x_RebootCmd(void)
{
    const uint8_t reboot[] = {'R', 'e', 'b', 'o', 'o', 't', 'i', 'n', 'g', '\r', '\n'};

    cmdBuf[0] = 'R';
    cmdBuf[1] = ',';
    cmdBuf[2] = '1';
    cmdBuf[4] = '\r';
    cmdBuf[5] = '\n';

    RN487x_SendCmd(cmdBuf, 5);

    return RN487x_ReadMsg(reboot, sizeof (reboot));
}

bool RN487x_FactoryReset(RN487x_FACTORY_RESET_MODE_t resetMode)
{
    const uint8_t reboot[] = {'R', 'e', 'b', 'o', 'o', 't', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'F', 'a', 'c', 't', 'o', 'r', 'y', ' ', 'R', 'e', 's', 'e', 't', '\r', '\n'};
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'F';
    cmdBuf[2] = ',';
    cmdBuf[4] = resetMode;
    cmdBuf[5] = '\r';
    cmdBuf[5] = '\n';

    RN487x_SendCmd(cmdBuf, 6);

    return RN487x_ReadMsg(reboot, sizeof (reboot));
}

bool RN487x_Disconnect(void)
{
    cmdBuf[0] = 'K';
    cmdBuf[1] = ',';
    cmdBuf[2] = '1';
    cmdBuf[3] = '\r';
    cmdBuf[4] = '\n';

    RN487x_SendCmd(cmdBuf, 5);

    return RN487x_ReadDefaultResponse();
}

bool RN487x_SetAsyncMessageHandler(char* pBuffer, uint8_t len)
{
    if ((pBuffer != NULL) && (len > 1))
    {
      asyncBuffer = pBuffer;
      asyncBufferSize = len - 1;
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
    while(RN487x_DataReady() == false); // Wait
    dataReady = false;
    return peek;
}

static bool RN487x_FilterData(void)
{
    static bool asyncBuffering = false;
    
    uint8_t readChar = RN487x.Read();
    
    if(asyncBuffering == true)
    {
        if(readChar == STATUS_MESSAGE_DELIMITER)
        {
            asyncBuffering = false;
            *pHead = '\0';
            RN487x.AsyncHandler(asyncBuffer);
        }
        else if (pHead < asyncBuffer + asyncBufferSize)
        {
            *pHead++ = readChar;
        }
    }
    else
    {
        if (readChar == STATUS_MESSAGE_DELIMITER)
        {
            asyncBuffering = true;
            pHead = asyncBuffer;
        }
        else 
        {
            dataReady = true;
            peek = readChar;
        }
    }
    return dataReady;
}
