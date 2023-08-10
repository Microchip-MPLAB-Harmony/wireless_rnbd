/**
 * \file rnbd_example.c
 * \brief This file contains the APIs required to communicate with the RNBD  driver library to 
 *        create, and open a basic Transparent EUSART demonstration.
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

#include <stdbool.h>
#include <stdint.h>
#include "rnbd_example.h"
#include "../rnbd/rnbd_interface.h"
#include "../rnbd/rnbd.h"

/** MACRO used to configure the application used buffer sizes.
 *  This is used by the application for communication buffers.
 */
#define MAX_BUFFER_SIZE                 (80)

/**< Status Buffer instance passed to RN487X drive used for Asynchronous Message Handling (see *asyncBuffer in rn487x.c) */
static char statusBuffer[MAX_BUFFER_SIZE];    

/**
 * \def DEMO_PERIODIC_TRANSMIT_COUNT
 * This macro provide a definition for a periodic data transmission demostration
 */
#define DEMO_PERIODIC_TRANSMIT_COUNT           (uint8_t)(100)

/**
 * \ingroup RNBD_Example
 * \brief Example Implmentation for simple Data Exchange Demostration
 *
 * This demostration uses the Lightblue BLE application developed by 'Punch Through' 
 * \return Connected Status
 * \retval true - Connected.
 * \retval false - Not Connected
 */  
static bool RNBD_Example_BasicDataExchange(void);
/**
 * \ingroup RNBD_Example
 * \brief This 'Runs' the example applications While(1) loop
 *
 * For more details, refer RNBD user guide.
 * \param none
 * \return void
 */
static void RNBD_Example_Run(void);

volatile static uint8_t readData;

bool RNBD_Example_Initialized(void)
{
    bool exampleIsInitialized = false;
    exampleIsInitialized = RNBD_SetAsyncMessageHandler(statusBuffer, (uint8_t)sizeof(statusBuffer));
    
    if (exampleIsInitialized == true)
    {
        RNBD_Example_Run();
    }
    return (false);     // ^ Held if Successful; Return failure if reaching this.
}

static void RNBD_Example_Run(void)
{
    while(true)
    {
        if (true == RNBD_Example_BasicDataExchange())
        {
            // Connected
        }
        else
        {
            // Not Connected
        }
    }
}

static bool RNBD_Example_BasicDataExchange(void)
{
   static uint16_t periodicCounter = 0;
   bool isConnected,isOTAComplete;
   readData = 0;
   isConnected = RNBD_IsConnected();
   isOTAComplete = RNBD_IsOTAComplete();

   if (true == isConnected && false == isOTAComplete)
   {
       while (RNBD_DataReady())
       {
           readData = RNBD_Read();
           // Use the readData as desired
       }
       if (periodicCounter == DEMO_PERIODIC_TRANSMIT_COUNT)
       {
           RNBD.Write('1');
           periodicCounter = 0;
       }
       else
       {
           periodicCounter++;
              RNBD.DelayMs(1);
       }
   }
   else
    {
        while(RNBD_DataReady())
        {
            // Clear data; Allow ASYNC processor decode
            readData = RNBD_Read();
        }
    }

    return isConnected;
}
