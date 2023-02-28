/** \file rnbd.c
 *  \brief This file contains APIs to access features support by RNBD series devices.
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

#include "rnbd.h"
#include "rnbd_interface.h"
#include "definitions.h" 

/**
 * \def STATUS_MESSAGE_DELIMITER
 * This macro provide a definition of the RNBD devices PRE/POST status message delimiter.
 */
#define STATUS_MESSAGE_DELIMITER        ('%')

static char cmdBuf[64];                                 /**< Command TX Buffer */
static uint8_t dummyread;

static char *asyncBuffer;                           /**< Async Message Buffer */
static uint8_t asyncBufferSize;                     /**< Size of the Async Message Buffer */
static char *pHead;                                 /**< Pointer to the Head of the Async Message Buffer */
static uint8_t peek = 0;                            /**< Recieved Non-Status Message Data */
static bool dataReady = false;                      /**< Flag which indicates whether Non-Status Message Data is ready */

/**
 * \brief This function filters status messages from RNBD data.
 * \param void This function takes no params.
 * \return a boolean value
 * \retval dataReady Returns true if data is ready; false otherwise.
 */
static bool RNBD_FilterData(void);

bool RNBD_Init(void)
{
    //Enter reset
    RNBD.ResetModule(true);
    //Wait for Reset
    RNBD.DelayMs(RNBD_RESET_DELAY_TIME);
    //Exit reset
    RNBD.ResetModule(false);

    //Wait while RN Device is booting up
    RNBD.DelayMs(RNBD_STARTUP_DELAY);

    //Remove unread data sent by RNBD, if any
    while (RNBD.DataReady())
    {
        dummyread=RNBD.Read();
    }
    
    return true;
}

void RNBD_SendCmd(const char *cmd, uint8_t cmdLen)
{
    uint8_t index = 0;

    while (index < cmdLen)
    {
        if (RNBD.TransmitDone())
        {
            RNBD.Write(cmd[index]);
            index++;
        }
    }
}

uint8_t RNBD_GetCmd(const char *getCmd, uint8_t getCmdLen, char *getCmdResp)
{
    uint8_t index = 0;

    RNBD_SendCmd(getCmd, getCmdLen);

    do
    {
        getCmdResp[index++] = (char)RNBD.Read();
    }
    while (getCmdResp[index - 1U] != '\n');

    return index;
}

bool RNBD_ReadMsg(const char *expectedMsg, uint8_t msgLen)
{
    uint8_t index;
    uint8_t resp;

    for (index = 0; index < msgLen; index++)
    {
        resp = RNBD.Read();
                if (resp != (uint8_t)expectedMsg[index])
        {
            return false;
        }
    }

    return true;
}

bool RNBD_ReadDefaultResponse(void)
{
    char resp[3];
    bool status = false;

    resp[0] = (char)RNBD.Read();
    resp[1] = (char)RNBD.Read();
    resp[2] = (char)RNBD.Read();
    switch (resp[0])
    {
        case 'A':
        {
            if ((resp[1] == 'O') && (resp[2] == 'K'))
            {
                status = true;
            }

            break;
        }
        case 'E':
        {
            if ((resp[1] == 'r') && (resp[2] == 'r'))
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

    /* Read carriage return and line feed comes with response */
    dummyread=RNBD.Read();
    dummyread=RNBD.Read();

    //Read CMD>
    dummyread=RNBD.Read();
    dummyread=RNBD.Read();
    dummyread=RNBD.Read();
    dummyread=RNBD.Read();
    dummyread=RNBD.Read();
  
    return status;
}
/*
void RNBD_WaitForMsg(const char *expectedMsg, uint8_t msgLen)
{
    uint8_t index = 0;
    uint8_t resp;

    do
    {
        resp = RNBD.Read();

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
*/

bool RNBD_EnterCmdMode(void)
{
    const char cmdPrompt[] = {'C', 'M', 'D', '>', ' '};

    cmdBuf[0] = '$';
    cmdBuf[1] = '$';
    cmdBuf[2] = '$';

    RNBD_SendCmd(cmdBuf, 3U);

    return RNBD_ReadMsg(cmdPrompt, (uint8_t)sizeof (cmdPrompt));
}

bool RNBD_EnterDataMode(void)
{
    const char cmdPrompt[] = {'E', 'N', 'D', '\r', '\n'};

    cmdBuf[0] = '-';
    cmdBuf[1] = '-';
    cmdBuf[2] = '-';
    cmdBuf[3] = '\r';
    cmdBuf[4] = '\n';

    RNBD_SendCmd(cmdBuf, 5U);

    return RNBD_ReadMsg(cmdPrompt, (uint8_t)sizeof (cmdPrompt));
}

/*
bool RNBD_SetName(const char *name, uint8_t nameLen)
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

    RNBD_SendCmd(cmdBuf, nameLen + 5);

    return RNBD_ReadDefaultResponse();
}

bool RNBD_SetBaudRate(uint8_t baudRate)
{
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'B';
    cmdBuf[2] = ',';
    cmdBuf[3] = ((uint8_t)(baudRate >> 4)) & 0x0F;
    cmdBuf[4] = (baudRate & 0x0F);
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';

    RNBD_SendCmd(cmdBuf, 7);

    return RNBD_ReadDefaultResponse();
}

bool RNBD_SetServiceBitmap(uint8_t serviceBitmap)
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

    RNBD_SendCmd(cmdBuf, 7);

    return RNBD_ReadDefaultResponse();
}

bool RNBD_SetFeaturesBitmap(uint16_t featuresBitmap)
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

    RNBD_SendCmd(cmdBuf, 9);

    return RNBD_ReadDefaultResponse();
}

bool RNBD_SetIOCapability(uint8_t ioCapability)
{
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'A';
    cmdBuf[2] = ',';
    cmdBuf[3] = NIBBLE2ASCII(ioCapability);
    cmdBuf[4] = '\r';
    cmdBuf[5] = '\n';

    RNBD_SendCmd(cmdBuf, 6);

    return RNBD_ReadDefaultResponse();
}

bool RNBD_SetPinCode(const char *pinCode, uint8_t pinCodeLen)
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

    RNBD_SendCmd(cmdBuf, index);

    return RNBD_ReadDefaultResponse();
}

bool RNBD_SetStatusMsgDelimiter(char preDelimiter, char postDelimiter)
{
    cmdBuf[0] = 'S';
    cmdBuf[1] = '%';
    cmdBuf[2] = ',';
    cmdBuf[3] = preDelimiter;
    cmdBuf[4] = ',';
    cmdBuf[5] = postDelimiter;
    cmdBuf[6] = '\r';
    cmdBuf[7] = '\n';

    RNBD_SendCmd(cmdBuf, 8);

    if (RNBD_ReadDefaultResponse())
    {
        return true;
    }

    return false;
}

bool RNBD_SetOutputs(RNBD_gpio_bitmap_t bitMap)
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

    RNBD_SendCmd(cmdBuf, 10);
    return RNBD_ReadDefaultResponse();
}

RNBD_gpio_stateBitMap_t RNBD_GetInputsValues(RNBD_gpio_ioBitMap_t getGPIOs)
{
    char ioHighNibble = '0';
    char ioLowNibble = '0';
    uint8_t ioValue[] = {'0', '0'};
    RNBD_gpio_stateBitMap_t ioBitMapValue;
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

    RNBD_SendCmd(cmdBuf, 7);
    RNBD_ReadMsg(ioValue, sizeof (ioValue));    
    ioBitMapValue.gpioStateBitMap = ( (((ioValue[0] - '0') & 0x0F) << 4) | ((ioValue[1] - '0') & 0x0F) );
    return ioBitMapValue;
}

uint8_t * RNBD_GetRSSIValue(void)
{
    static uint8_t resp[3];

    cmdBuf[0] = 'M';
    cmdBuf[1] = '\r';
    cmdBuf[2] = '\n';

    RNBD_SendCmd(cmdBuf, 3);

    resp[0] = RNBD.Read();
    resp[1] = RNBD.Read();
    resp[2] = RNBD.Read();

    // Read carriage return and line feed
    RNBD.Read();
    RNBD.Read();

    // Read CMD>
    RNBD.Read();
    RNBD.Read();
    RNBD.Read();
    RNBD.Read();
    RNBD.Read();

    return resp;
}
*/

bool RNBD_RebootCmd(void)
{
    const char reboot[] = {'R', 'e', 'b', 'o', 'o', 't', 'i', 'n', 'g', '\r', '\n'};

    cmdBuf[0] = 'R';
    cmdBuf[1] = ',';
    cmdBuf[2] = '1';
    cmdBuf[4] = '\r';
    cmdBuf[5] = '\n';

    RNBD_SendCmd(cmdBuf, 5U);

    return RNBD_ReadMsg(reboot, (uint8_t)sizeof (reboot));
}

bool RNBD_FactoryReset(RNBD_FACTORY_RESET_MODE_t resetMode)
{
    const char reboot[] = {'R', 'e', 'b', 'o', 'o', 't', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'F', 'a', 'c', 't', 'o', 'r', 'y', ' ', 'R', 'e', 's', 'e', 't', '\r', '\n'};
    cmdBuf[0] = 'S';
    cmdBuf[1] = 'F';
    cmdBuf[2] = ',';
    cmdBuf[4] = (char)resetMode;
    cmdBuf[5] = '\r';
    cmdBuf[6] = '\n';

    RNBD_SendCmd(cmdBuf, 6U);

    return RNBD_ReadMsg(reboot, (uint8_t)sizeof (reboot));
}

bool RNBD_Disconnect(void)
{
    cmdBuf[0] = 'K';
    cmdBuf[1] = ',';
    cmdBuf[2] = '1';
    cmdBuf[3] = '\r';
    cmdBuf[4] = '\n';

    RNBD_SendCmd(cmdBuf, 5U);

    return RNBD_ReadDefaultResponse();
}

bool RNBD_SetAsyncMessageHandler(char* pBuffer, uint8_t len)
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

bool RNBD_DataReady(void)
{
    if (dataReady)
    {
        return true;
    }
    
    if (RNBD.DataReady())
    {
        return RNBD_FilterData();
    }
    return false;
}

uint8_t RNBD_Read(void)
{
    while(RNBD_DataReady() == false){}; // Wait
    dataReady = false;
    return peek;
}

static bool RNBD_FilterData(void)
{
    static bool asyncBuffering = false;
    
    uint8_t readChar = RNBD.Read();
    
    if(asyncBuffering == true)
    {
        if(readChar == (uint8_t)STATUS_MESSAGE_DELIMITER)
        {
            asyncBuffering = false;
            *pHead = '\0';
            RNBD.AsyncHandler(asyncBuffer);
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
        if (readChar == (uint8_t)STATUS_MESSAGE_DELIMITER)
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
