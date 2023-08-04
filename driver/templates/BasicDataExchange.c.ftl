/**
<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
 * \file rnbd_example.c
 <#else>
  * \file rn487x_example.c
 </#if>
 * \brief This file contains the APIs required to communicate with the <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">RNBD <#else>RN487X</#if> driver library to 
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

<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
#include <stdbool.h>
#include <stdint.h>
#include "rnbd_example.h"
#include "../rnbd/rnbd_interface.h"
#include "../rnbd/rnbd.h"
<#else>
#include <stdbool.h>
#include <stdint.h>
#include "rn487x_example.h"
#include "../rn487x/rn487x_interface.h"
#include "../rn487x/rn487x.h"
</#if>

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
<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
 * \ingroup RNBD_Example
 <#else>
  * \ingroup RN487x_Example
 </#if>
 * \brief Example Implmentation for simple Data Exchange Demostration
 *
 * This demostration uses the Lightblue BLE application developed by 'Punch Through' 
 * \return Connected Status
 * \retval true - Connected.
 * \retval false - Not Connected
 */  
<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
static bool RNBD_Example_BasicDataExchange(void);
<#else>
static bool RN487x_Example_BasicDataExchange(void);
</#if>
/**
<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
 * \ingroup RNBD_Example
 <#else>
  * \ingroup RN487x_Example
 </#if>
 * \brief This 'Runs' the example applications While(1) loop
 *
 * For more details, refer <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">RNBD<#else>RN487x</#if> user guide.
 * \param none
 * \return void
 */
<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD"> 
static void RNBD_Example_Run(void);
<#else>
static void RN487x_Example_Run(void);
</#if>

volatile static uint8_t readData;

<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD"> 
bool RNBD_Example_Initialized(void)
<#else>
bool RN487x_Example_Initialized(void)
</#if>
{
    bool exampleIsInitialized = false;
    <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD"> 
    exampleIsInitialized = RNBD_SetAsyncMessageHandler(statusBuffer, (uint8_t)sizeof(statusBuffer));
    <#else>
    exampleIsInitialized = RN487x_SetAsyncMessageHandler(statusBuffer, (uint8_t)sizeof(statusBuffer));
    </#if>
    
    if (exampleIsInitialized == true)
    {
    <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
        RNBD_Example_Run();
    <#else>
        RN487x_Example_Run();
    </#if>
    }
    return (false);     // ^ Held if Successful; Return failure if reaching this.
}

<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
static void RNBD_Example_Run(void)
<#else>
static void RN487x_Example_Run(void)
</#if>
{
    while(true)
    {
    <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
        if (true == RNBD_Example_BasicDataExchange())
    <#else>
        if (true == RN487x_Example_BasicDataExchange())
    </#if>
        {
            // Connected
        }
        else
        {
            // Not Connected
        }
    }
}

<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
static bool RNBD_Example_BasicDataExchange(void)
<#else>
static bool RN487x_Example_BasicDataExchange(void)
</#if>
{
   static uint16_t periodicCounter = 0;
   bool isConnected,isOTAComplete;
   readData = 0;
   <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
   isConnected = RNBD_IsConnected();
   isOTAComplete = RNBD_IsOTAComplete();
   <#else>
   isConnected = RN487x_IsConnected();
   isOTAComplete = RN487x_IsOTAComplete();
   </#if>

   if (true == isConnected && false == isOTAComplete)
   {
   <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
       while (RNBD_DataReady())
    <#else>
       while (RN487x_DataReady())
    </#if>
       {
        <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
           readData = RNBD_Read();
        <#else>
           readData = RN487x_Read();
        </#if>   
           // Use the readData as desired
       }
       if (periodicCounter == DEMO_PERIODIC_TRANSMIT_COUNT)
       {
        <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
           RNBD.Write('1');
        <#else>
           RN487x.Write('1');
        </#if>
           periodicCounter = 0;
       }
       else
       {
           periodicCounter++;
           <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
              RNBD.DelayMs(1);
           <#else>
              RN487x.DelayMs(1);
           </#if>
       }
   }
   else
    {
    <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
        while(RNBD_DataReady())
    <#else>
        while(RN487x_DataReady())
    </#if>
        {
        <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
            // Clear data; Allow ASYNC processor decode
            readData = RNBD_Read();
        <#else>
            readData = RN487x_Read();
        </#if>
        }
    }

    return isConnected;
}
