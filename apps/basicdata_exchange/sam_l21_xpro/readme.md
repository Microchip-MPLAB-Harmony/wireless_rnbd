<a href="https://www.microchip.com" rel="nofollow"><img src="media/microchip.png" alt="MCHP" width="300"/></a>

# RNBD\_RN487x\_32Bit\_User\_Guide

-   [Introduction](#introduction)
-   [Getting Started with Software Development](#getting-started-with-software-development)
-   [Project Setup](#project-setup)
-   [RNBD Example: Running Basic Data Exchange Example Application](#rnbd-example:-running-basic-data-exchange-example-application)
-   [RN487x Example: Running Basic Data Exchange Example Application](#rn487x-example:-running-basic-data-exchange-example-application)
-   [Summary](#summary)


**List of supported MCU/MPU Device Family**

"SAMC",
"SAMD",
"SAME",
"SAML",
"SAM9x",
"PIC32MK",
"PIC32MX",
"PIC32CM",
"PIC32CMMC",
"PIC32MM1324",
"PIC32MZDA",
"PIC32MZEF",
"PIC32MZW",
"PIC32CX"



# Introduction<a name="introduction"></a>

The MPLAB® Code Configurator [RNBD](http://mchpweb:4576/SpecIndex_FileAttach/TPT_20227216811993/70005514A.pdf)/[RN487x](https://www.microchip.com/en-us/product/RN4870) BLE Modules Library allows quick and easy configuration of the C<br /> code generated software driver based upon the user’s selected API features available<br /> from the MCC Library. Generated Driver code supports use of either BLE Module with use<br /> of a 32 Bit PIC Devices

The library module uses a Graphic User Interface \(GUI\) presented by MCC within MPLABX<br /> which allows for selection of desired configuration, and custom configurations of the<br /> protocol. Customized C code is generated within the MPLABX project, in a folder named<br /> "MCC Generated Files".

This Library uses \(1\) UART, \(1\) GPIO, and DELAY support at minimal.

Refer to the /media folder for source files & max resolution.


# Getting Started with Software Development<a name="getting-started-with-software-development"></a>

Steps to install IDE, compiler, tool chain and application examples on your PC

This guide will walk you through setting up your development environment with all<br /> required dependencies versions.If you are already familiar Microchip Tools, then you can<br /> find a table summarizing the dependencies below

**Tools and Harmony Component Versions**

<br />

|IDE, Compiler and MCC plugin|Version|Location|
|----------------------------|-------|--------|
|MPLAB X IDE|v6.20|[MPLAB X IDE Website](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide#tabs)|
|XC32 Compiler|v4.45 or above|[Web](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)|
|Microchip Code Configurator\(MCC\)|5.5.1 or above|[MPLAB X IDE \> Tools \>Plugins](https://internal.onlinedocs.microchip.com/pr/GUID-99E91F8E-E9F7-4C2C-B98A-E9662A2ABA50-en-US-1/GUID-A55E9342-CE44-4A91-86BB-FEC6706FCD1C.html)|
|Device Family Pack \(DFP\) |SAML21\_DFP \(v3.7.217\)|Device: ATSAML21J18B|

<br />

**Harmony Components**:

<br />



|**Harmony components to be cloned with MCC Content Manager**|**Version**|
|------------------------------------------------------------|-----------|
|csp|v3.20.0|
|core|v3.13.5|
|bsp|v3.21.1|
|CMSIS-FreeRTOS|v10.5.1|
|wireless_rnbd|v2.0.4 or above|
<br />

# Project Setup<a name="project-setup"></a>
<br />

1.  Create MPLAB Harmany Project with below device and DFP version

    <br />

    -   Device: ATSAML21J18B
    -   XC32 Compiler: v4.45
    -   DFP: SAML21\_DFP \(v3.7.217\)
    <br />

    <br />

	**1.1** Create new 32-bit MCC Harmony Project as shown below

    ![](media/GUID-1F5749EC-E7B4-4523-897D-672357706EC6-low.png)

    <br />

    **1.2** Select the device "ATSAML21J18B" for application project using the SAML21<br /> device family

    <br />

    ![](media/GUID-3D19DD6B-F7D5-4C0D-BEA5-77D8003FC859-low.png)

    <br />

    **1.3** Select the compiler

    <br />

    ![](media/GUID-F1A8A999-FE9E-4D8F-9DE7-1152FB95BB02-low.png)

    <br />

    **1.4** Select the project name and  **Framework Path** \(Framework path must match SDK setup<br /> document\) and click Finish

    <br />

    ![](media/GUID-DD58810C-576C-4209-91DB-EB30366EBD70-low.png)

    <br />

    **1.5** MPLABx Code Configurator will be launched automatically. Then Select<br /> **"MPLAB Harmony"** and Click Next for the Harmony Framework<br /> Path.

    <br />

    ![](media/GUID-294FFF44-97E6-44FA-B024-CF107A950910-low.png)

    <br />

    **1.6** Select **"Finish"**

    <br />

    ![](media/GUID-12B3E149-2BA4-49D7-8518-4E0AF4053503-low.png)

    <br />

    **1.7** Project Graph window of the Configurator may have predefined<br /> components

    <br />

    ![](media/GUID-B7BABF5E-8835-4450-AE8F-4756671D5621-low.png)

    <br />

    Right click on the project properties and verify the selected<br /> configuration

    <br />

    ![](media/GUID-AFFFE743-53B2-4936-955F-91C9AD625657-low.png)

    <br />

2.  After creating the project as shown in the above step go to device resource and verify RNBD was under Wireless component

    <br />

    ![](media/GUID-8D6AAFC9-672F-4CEF-8A42-B848019EE289-low.png)

    <br />

    Click on Plus icon under RNBD to add it under the Project Resource

    <br />

    ![](media/GUID-C082E138-AB16-4561-B37C-8167A1EB3862-low.png)

    <br />

3.  Project Graph and RNBD/RN487x Module Configuration

    <br />

    ![](media/GUID-F82D5FA9-3ECA-4676-9866-B7236D123102-low.png)

    <br />

    User can Select **RNBD or RN487x** under the Select Module Type Drop<br /> Down either of the one as shown below

    <br />

    ![](media/GUID-20676429-4B4E-45F0-AFB6-2F9F24A05C90-low.png)

    <br />

4.  Selecting Example Application

    <br />

    -   Expand the Drop down under Select Example Application option and choose Basic Data Exchange as shown below
    <br />

    <br />

    ![](media/GUID-C4728BF0-3624-47F6-BB59-D0D48ABE4304-low.png)

    <br />

    **4.1. Basic Data Exchange:**

    <br />

    -   Basic Data Exchange uses only **ONE** SERCOM for the Data Transmission

        <br />

        ![](media/GUID-7362913E-214A-4A5B-8025-EB5978FD83AA-low.png)

        <br />

        <br />

        ![](media/GUID-6D4F728F-800C-44DA-8DBA-D38FE09C05E2-low.png)

        <br />

        ![](media/GUID-E0F435FE-B243-4B32-83CB-733D18E84AFB-low.png)
        <br />

        ![](media/GUID-1278FF0D-6D3C-4B0F-AE4D-89F168518DAF-low.png)

        <br />

    <br />

5.  PIN Settings for Example Application:
    -   Basic Data Exchange Pin Settings

        <br />

        ![](media/GUID-7799CCD7-257F-4372-A8B4-38B82D8D2EC6-low.png)

        <br />

6.  Code Generation and adding the example application to main.c

    <br />

    -   After making the all the above settings click on Generate in which code will be generated for RNBD or RN487x as per the selection

        <br />

        ![](media/GUID-1C36EEDF-61DE-4BCF-B7C8-E249E7AF5651-low.png)

        <br />

    -   Once after Generation is complete include the headers for **RNBD** or **RN487x** as shown below
        -   if **Select Module Type** is selected for **RNBD**: \#include "examples/rnbd\_example.h"
        -   if **Select Module Type** is selected for **RN487x**: \#include "examples/rn487x\_example.h"

            <br />

            ![](media/GUID-31D005A3-ADEE-47E8-8312-1BBCAF0AEE53-low.png)

            <br />

            Call the function **RNBD\_Example\_Initialized\(\); or RN487x\_Example\_Initialized\(\);** in **main\(\)**<br /> after **SYS\_Initialize \( NULL \);**

    <br />

7.  Build the Generated Project:

    <br />

    ![](media/GUID-69F2DB5D-6EEE-4922-935E-A0A0FB0E19F8-low.png)

    <br />

8.  Program to the Development Board

    <br />

    ![](media/GUID-86E3F2BD-3777-4E96-95C3-F1C8DED00136-low.png)

    <br />


<br />

# RNBD Example: Running Basic Data Exchange Example Application<a name="rnbd-example:-running-basic-data-exchange-example-application"></a>

**Basic Data Exchange:**

|This example shows how an MCU can be programmed to transmit data<br /> to a smart phone over BLE. Here the MCU device will send Periodic<br /> Transmission of a single character when **STREAM\_OPEN** is<br /> processed through the Message Handler. This indicates to the MCU<br /> & RNBD Module that the application is in a DATA STREAMING mode<br /> of operation; and can expect to hear data over the BLE<br /> connection.\#define DEMO\_PERIODIC\_TRANSMIT\_COUNT<br /> \(10000\)\#define DEMO\_PERIODIC\_CHARACTER \(‘1’\)Are<br /> used in the example can be found \#defined at the top of<br /> rnbd\_example.c.|

<br />

![](GUID-74E91F2D-EED5-4586-8AE1-3ED592753615-low.png)

<br />

<br />

1.  Download and Install Phone Application for demonstration:
    1.  **Microchip Bluetooth Data**by **Microchip** from the [App Store](https://apps.apple.com/us/app/microchip-bluetooth-data/id1319166097) or from [Google Play Store](https://play.google.com/store/apps/details?id=com.microchip.bluetooth.data&hl=en_IN&gl=US).
2.  Launch the Phone Application

    ![](media/GUID-10887333-0442-467E-B79B-6A17DB835DB2-low.png)![](media/GUID-7271A2D0-99A8-41F4-BB4C-269F2F83820C-low.png)

    <br />

    ![](media/GUID-8A9EE9CE-AA92-4648-8364-09987F2E0526-low.png)

    <br />

    Click on the 'BLE Smart' Sub Apps as shown below:

    ![](media/GUID-E19A7964-8190-4C53-8BBA-6370A19C9829-low.png)

3.  The Application scans the area for Bluetooth devices within a range. Look for "RNBD" devices under the scanned list.

    <br />

    ![](media/GUID-E5C513CE-6227-42C1-9DA8-3FA2075112DF-low.png)

    <br />

4.  On selecting the "RNBD" device from the list will be ready to connect with RNBD Module once you click on CONNECT Button

    <br />

    ![](media/GUID-5962533D-A1D4-40DA-8933-A7224139EBA7-low.png)

    <br />

5.  Once connected, the Microchip Bluetooth App discovers all the services and characteristics supported by the RNBD451 device as shown in the following figure.

    ![](media/GUID-AC320004-8543-404F-806A-4C5E70E09E3B-low.png)

6.  Click the **Microchip Data Service** Option and Select the **Microchip Data Characteristic** and Write Notify Indication to receive the data in Mobile App.

    ![](media/GUID-65CA4B07-2C54-4799-A9AE-826FD83B676D-low.png)

7.  Select **Listen for notifications** on the application.
    -   It may be required to "enable notification" access to the app on the<br /> phone.

        Data will begin to Send at a Periodic Rate to the device.

        Data will become visible beneath the **Notify/Listen Toggle**<br /> Option.

        -   **Before Enabling** the **Notify/Indicate Toggle** Button:

            ![](media/GUID-C5223277-D33D-4366-8CA4-124D340F0554-low.png)

            **After Enabling** the<br /> **Notify/Indicate Toggle** Button Mobile App can read<br /> the data **31\(Hex Value\)** which was sent from RNBD<br /> Module.

            ![](media/GUID-83D3CD62-CA8C-4C6C-88AF-CA15728E6392-low.png)


<br />

# RN487x Example: Running Basic Data Exchange Example Application<a name="rn487x-example:-running-basic-data-exchange-example-application"></a>

**Basic Data Exchange:**

|This example shows how an MCU can be programmed to transmit data<br /> to a smart phone over BLE. Here the MCU device will send Periodic<br /> Transmission of a single character when **STREAM\_OPEN** is<br /> processed through the Message Handler. This indicates to the MCU<br /> & RN487x Module that the application is in a DATA STREAMING mode<br /> of operation; and can expect to hear data over the BLE<br /> connection.\#define DEMO\_PERIODIC\_TRANSMIT\_COUNT<br /> \(10000\)\#define DEMO\_PERIODIC\_CHARACTER \(‘1’\)Are<br /> used in the example can be found \#defined at the top of<br /> rnbd\_example.c.|

<br />

![](media/GUID-8BF59E53-A177-4963-826B-5CC4BB72F35B-low.png)

<br />

<br />

1.  Download and Install Phone Application for demonstration:
    1.  **Microchip Bluetooth Data**by **Microchip** from the [App Store](https://apps.apple.com/us/app/microchip-bluetooth-data/id1319166097) or from [Google Play Store](https://play.google.com/store/apps/details?id=com.microchip.bluetooth.data&hl=en_IN&gl=US).
2.  Launch the Phone Application

    ![](media/GUID-10887333-0442-467E-B79B-6A17DB835DB2-low.png)![](media/GUID-7271A2D0-99A8-41F4-BB4C-269F2F83820C-low.png)

    <br />

    ![](media/GUID-8A9EE9CE-AA92-4648-8364-09987F2E0526-low.png)

    <br />

    Click on the 'BLE Smart' Sub Apps as shown below:

    ![](media/GUID-E19A7964-8190-4C53-8BBA-6370A19C9829-low.png)

3.  The Application scans the area for Bluetooth devices within a range. Look for "RN487x" devices under the scanned list.

    <br />

    ![](media/GUID-F9008121-7D40-4680-89B2-F595E314CB17-low.png)

    <br />

4.  On selecting the "RN487x" device from the list will be ready to connect with RNBD Module once you click on CONNECT Button

    <br />

    ![](media/GUID-EC0D19FF-B0F3-4D44-BD3F-D99B9FEFC62D-low.png)

    <br />

5.  Once connected, the Microchip Bluetooth App discovers all the services and characteristics supported by the RN487x device as shown in the following figure.

    <br />

    ![](media/GUID-9ED50565-2513-482E-BE6A-D118C539C56D-low.png)

    <br />

6.  Click the **Microchip Data Service** Option and Select the **Microchip Data Characteristic** and Write Notify Indication to receive the data in Mobile App.

    <br />

    ![](media/GUID-57D1EBD2-972B-4152-AAC3-D5C98DE6E4C6-low.png)

    <br />

7.  Select **Listen for notifications** on the application.
    -   It may be required to "enable notification" access to the app on the<br /> phone.

        Data will begin to Send at a Periodic Rate to the device.

        Data will become visible beneath the **Notify/Listen Toggle**<br /> Option.

        -   **Before Enabling** the**Notify/Indicate Toggle** Button:

            <br />

            ![](media/GUID-3780F6BB-6198-4179-A5C0-58042FC83EAE-low.png)

            <br />

            **After Enabling** the **Notify/Indicate Toggle Button** Mobile App can read the data **31\(Hex Value\)** which was sent from RN487x<br /> Module.

            ![](media/GUID-9A94A4DF-BEB9-48A5-B958-CDDC2C296ED7-low.png)


<br />


# Summary<a name="summary"></a>

**Command, Data Communication with Asynchronized Message Processing:**

This driver contains, at its' core, the inherent code capability of distinguishing<br /> between **Message** exchange and **Data** exchange between the connected MCU and<br /> Module devices.

The library supplies all required Application Programming Interfaces \(APIs\) required to<br /> create functional

implementation of operation a BLE connected end-device.

Through the MCC configuration the physical connection of the \(3\) required pins can be<br /> selected through the GUI.

These are the \(2\) UART pins used for communication, and control of the **RST\_N**<br /> connected to the RNBD Module.

Additionally; this Library allows for extension of Module pin behaviors through the<br /> simple RNBD Module object

interface; where any device/project specific instantiations exist.<br /> **rnbd\_interface.c/h**/**rn487x\_interface.c/h**

A brief description of the Interface, and object extension is described below:

iRNBD\_FunctionPtrs\_t is a typedef struct which can be found in<br /> **rnbd\_interface.h**/**rn487x\_interface.h** and consist of \(9\) function<br /> pointers. In the **rnbd\_interface.c**/**rn487x\_interface.c**, the concrete<br /> creation of RNBD as an object is instantiated. Within<br /> **rnbd\_interface.c**/**rn487x\_interface.c** are the **private static**<br /> implementations of desired behavior. In some cases, such as DELAY or UART, the<br /> supporting behavior is supplied through another supporting library module. When<br /> applicable ‘inline’ has been used to reduce stack depth overhead.

<br />

![](media/GUID-2B41A010-DEC4-4198-9245-049150500274-low.png)

<br />

<br />

![](media/GUID-08351B32-7A45-4F07-91BF-66534BFE5482-low.png)

<br />

The driver library itself should not require any modifications or injections by the user;<br /> unless to expand upon the supported command implementations **rnbd.c/h**

**Configurable Module Hardware Requirement\(s\):**

A single UART instance used for communication between MCU and Module:

|Library Name: Output\(s\)|Module: Input\(s\)|Description|Module Physical Defaults|
|-------------------------|------------------|-----------|------------------------|
|BT\_MODE|P2\_0|<br /> 1 : Application Mode<br /> 0 : Test Mode/Flash Update/EEPROM Configuration<br />|Active-Low, Internal Pull-High|
|BT\_RST|RST\_N|Module Reset|Active-Low, Internal Pull-High|
|BT\_RX\_IND|P3\_3|Configured as UART RX Indication pin|Active-Low|

<br />
