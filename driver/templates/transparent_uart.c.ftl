/**
<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
 * \file rnbd_example.c
 <#else>
 * \file rn487x_example.c
 </#if>
 <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
 * \brief This file contains the APIs required to communicate with the RNBD driver library to 
 <#else>
 * \brief This file contains the APIs required to communicate with the RN487X driver library to 
 </#if>
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
<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RN487x">
#include "rn487x_example.h"
#include "../rnHostLib/rn487x_interface.h"
#include "../rnHostLib/rn487x.h"
<#else>
#include "rnbd_example.h"
#include "../rnHostLib/rnbd_interface.h"
#include "../rnHostLib/rnbd.h"
</#if>
#include "definitions.h"                // SYS function prototypes

/** MACRO used to configure the application used buffer sizes.
 *  This is used by the application for communication buffers.
 */
#define MAX_BUFFER_SIZE                 (80)

<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RN487x">
/**< Status Buffer instance passed to RN487X drive used for Asynchronous Message Handling (see *asyncBuffer in rn487x.c) */
<#else>
/**< Status Buffer instance passed to RNBD drive used for Asynchronous Message Handling (see *asyncBuffer in rnbd.c) */
</#if>
static char statusBuffer[MAX_BUFFER_SIZE];    

/**
 * \ingroup RN_Example
 * \brief Example Implementation of Transparent UART
 *        This can be connected to a Smart BLE 'Terminal' 
 *        application for simple data exchange demonstration.
 *<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RN487x">
 * For more details, refer RN487X user guide.
 <#else>
 * For more details, refer RNBD user guide.
 </#if>
 * \return Connected Status
 * \retval true - Connected.
 * \retval false - Not Connected
 */ 
<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD"> 
static bool RNBD_Example_TransparentUart(void);
<#else>
static bool RN487x_Example_TransparentUart(void);
</#if>
/**
<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD"> 
 * \ingroup RNBD_Example_Run
 <#else>
  * \ingroup RN487x_Example_Run
 </#if>
 * \brief This 'Runs' the example applications While(1) loop
 *
 *<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RN487x">
 * For more details, refer RN487X user guide.
 <#else>
 * For more details, refer RNBD user guide.
 </#if>
 * \param none
 * \return void
 */  
<#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
static void RNBD_Example_Run(void);
<#else>
static void RN487x_Example_Run(void);
</#if>

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
        if (true == RNBD_Example_TransparentUart())
        <#else>
        if (true == RN487x_Example_TransparentUart())
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
static bool RNBD_Example_TransparentUart(void)
<#else>
static bool RN487x_Example_TransparentUart(void)
</#if>
{
    bool isConnected,isOTAComplete;
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
           UART_CDC_write(RNBD_Read());
       <#else>
           UART_CDC_write(RN487x_Read());
       </#if>
       }
       
       while (UART_CDC_DataReady())
       {
           <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
           RNBD.Write(UART_CDC_Read());
           <#else>
           RN487x.Write(UART_CDC_Read());
           </#if>
       }
       
   }
   else
    {
        
        <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
        while (RNBD_DataReady())
        <#else>
        while (RN487x_DataReady())
        </#if>
       {
           <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
           UART_CDC_write(RNBD_Read());
           <#else>
           UART_CDC_write(RN487x_Read());
           </#if>
       }
        
       
        while (UART_CDC_DataReady())
        {
            <#if RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE == "RNBD">
            RNBD.Write(UART_CDC_Read());
            <#else>
            RN487x.Write(UART_CDC_Read());
            </#if>
        }
       
 
    }

    return isConnected;
}


