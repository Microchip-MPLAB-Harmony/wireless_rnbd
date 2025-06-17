<a href="https://www.microchip.com" rel="nofollow"><img src="media/microchip.png" alt="MCHP" width="300"/></a>

# RNBD\_RN487x\_32Bit\_User\_Guide

-   [Introduction](#introduction)
-   [Getting Started with Software Development](#getting-started-with-software-development)
-   [Project Setup](#project-setup)
-   [RNBD Example: Running Transparent UART Example Application](#rnbd-example:-running-transparent-uart-example-application)
-   [RN487x Example: Running Transparent UART Example Application](#rn487x-example:-running-transparent-uart-example-application)
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
"PIC32CX",
"PIC32CK",
"PIC32CXMT",
"PIC32C".

# Introduction<a name="introduction"></a>

The MPLAB® Code Configurator [RNBD](http://mchpweb:4576/SpecIndex_FileAttach/TPT_20227216811993/70005514A.pdf)/[RN487x](https://www.microchip.com/en-us/product/RN4870) BLE Modules Library allows quick and easy configuration of the C code generated software driver based upon the user’s selected API features available from the MCC Library. Generated Driver code supports use of either BLE Module with use of a 32 Bit PIC Devices

The library module uses a Graphic User Interface \(GUI\) presented by MCC within MPLABX which allows for selection of desired configuration, and custom configurations of the protocol. Customized C code is generated within the MPLABX project, in a folder named "MCC Generated Files".

This Library uses \(1\) UART, \(1\) GPIO, and DELAY support at minimal.

Refer to the /media folder for source files & max resolution.


# Getting Started with Software Development<a name="getting-started-with-software-development"></a>

Steps to install IDE, compiler, tool chain and application examples on your PC

This guide will walk you through setting up your development environment with all required dependencies versions. If you are already familiar Microchip Tools, then you can find a table summarizing the dependencies below

**Tools and Harmony Component Versions**

|IDE, Compiler and MCC plugin|Version|Location|
|----------------------------|-------|--------|
|MPLAB X IDE|v6.20|[MPLAB X IDE Website](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide#tabs)|
|XC32 Compiler|v4.45 or above|[Web](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)|
|Microchip Code Configurator\(MCC\)|5.5.1 or above|[MPLAB X IDE \> Tools \>Plugins](https://internal.onlinedocs.microchip.com/pr/GUID-99E91F8E-E9F7-4C2C-B98A-E9662A2ABA50-en-US-1/GUID-A55E9342-CE44-4A91-86BB-FEC6706FCD1C.html)|
|Device Family Pack \(DFP\)|PIC32CM-MC\_DFP \(v1.4.67\)|Device: PIC32CM1216MC00048|

<br />

**Harmony Components**:

|**Harmony components to be cloned with MCC Content Manager**|**Version**|
|------------------------------------------------------------|-----------|
|csp|v3.20.0|
|core|v3.13.5|
|bsp|v3.21.1|
|CMSIS-FreeRTOS|v10.5.1|
|wireless_rnbd|v2.0.4 or above|

# Project Setup<a name="project-setup"></a>
<br />

1.  Create MPLAB Harmony Project with below device and DFP version

    -   Device: PIC32CM1216MC00048
    -   XC32 Compiler: v4.45
    -   DFP: PIC32CM-MC\_DFP \(v1.4.67\)
    <br />

    **1.1** Create new 32-bit MCC Harmony Project as shown below

      ![](media/GUID-1F5749EC-E7B4-4523-897D-672357706EC6-low.png)

      <br />

      **1.2** Select the device "PIC32CM1216MC00048" for application project using the PIC32CM device family

      <br />

      ![](media/GUID-3D19DD6B-F7D5-4C0D-BEA5-77D8003FC859-low.png)

      <br />

      **1.3** Select the compiler

      <br />

      ![](media/GUID-F1A8A999-FE9E-4D8F-9DE7-1152FB95BB02-low.png)

      <br />

      **1.4** Select the project name and  **Framework Path** \(Framework path must match SDK setup document\) and click Finish

      <br />

      ![](media/GUID-DD58810C-576C-4209-91DB-EB30366EBD70-low.png)

      <br />

    **1.5** MPLABx Code Configurator will be launched automatically. Then Select **"MPLAB Harmony"** and Click Next for the Harmony Framework Path.

    <br />

    ![](media/GUID-294FFF44-97E6-44FA-B024-CF107A950910-low.png)

    <br />

    **1.6** Select **"Finish"**

    <br />

    ![](media/GUID-12B3E149-2BA4-49D7-8518-4E0AF4053503-low.png)

    <br />

    **1.7** Project Graph window of the Configurator may have predefined components

    <br />

    ![](media/GUID-B7BABF5E-8835-4450-AE8F-4756671D5621-low.png)

    <br />

    Right click on the project properties and verify the selected configuration

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

    ![](media/GUID-E98E66A5-023F-4A59-A415-188A9407B727-low.png)

    <br />

    User can Select **RNBD** or **RN487x** under the Select Module Type Drop Down either of the one as shown below

    <br />

    ![](media/GUID-2B7B2E95-2F31-4C72-BBFB-2ED03594AC60-low.png)

    <br />

4.  Selecting Example Application

    <br />

    -   Expand the Drop down under Select Example Application option and choose Transparent UART as shown below
    <br />

      ![](media/GUID-C4728BF0-3624-47F6-BB59-D0D48ABE4304-low.png)

      <br />

      ![](media/GUID-0B984F72-4BD1-4A0E-A500-8F5E47635AAE-low.png)

    -   Transparent UART Application uses **TWO** SERCOM as a Dependency for the Data Transmission

      ![](media/GUID-8DFAD094-DC6C-452C-8B76-A8959FA8751A-low.png)

      ![](media/GUID-65B59EB7-F897-4632-B540-900B80FA985B-low.png)

      RNBD/RN487x Depenedency0 **SERCOM3** Tx/Rx Pad settings

      ![](media/Sercom_Dependency0_rx_tx_pad_settings.png)

      RNBD/RN487x Depenedency1 **SERCOM0** Tx/Rx Pad settings

      ![](media/GUID-B7BC4E37-70AB-474A-BC7C-63F1BF807757-low.png)

5.  PIN Settings for Example Application:

    -   Transparent UART Pin Settings

        <br />

        ![](media/GUID-1B561392-5A32-454E-BA0F-68DBF4D5201F-low.png)

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

            Call the function **RNBD\_Example\_Initialized\(\); or RN487x\_Example\_Initialized\(\);** in **main\(\)** after **SYS\_Initialize \( NULL \);**

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

# RNBD Example: Running Transparent UART Example Application<a name="rnbd-example:-running-transparent-uart-example-application"></a>

<br />

![](media/GUID-7C8A6EC0-77B8-4206-B2F5-FA8FA50C2A35-low.png)

<br />

<br />

|Transparent Serial:|
|-------------------|
|This example will demonstrate data transmitted from a PC serial terminal is written to a smart phone app and vice versa. The MCU device will act as a bridge, and pass data between RNBD Module to MCU via Serial Terminal. This action will occur when STREAM\_OPEN is processed through the Message Handler. For this example, data typed into the Serial Terminal will appear on the BLE Phone Application, and Data sent from the Application will appear on the Serial Terminal.|

<br />

1.  Download and Install Phone Application for demonstration:
    -   Search **Microchip Bluetooth Data** by **Microchip Technology Inc** from the [App Store](https://apps.apple.com/us/app/microchip-bluetooth-data/id1319166097) or from [Google Play](https://play.google.com/store/apps/details?id=com.microchip.bluetooth.data&hl=en_IN&gl=US).

    <br />

    ![](media/GUID-8A9EE9CE-AA92-4648-8364-09987F2E0526-low.png)

    <br />

2.  Launch the Phone Application

    <br />

    ![](media/GUID-7271A2D0-99A8-41F4-BB4C-269F2F83820C-low.png)

    <br />

    After Installing open the MBD App and Click on **BLE UART** Sub Apps:

    <br />

    ![](media/GUID-D647FF96-CA12-4FA0-A3AA-29C6D6C3DF9D-low.png)

    <br />

3.  On Selecting **PIC32CXBZ** scan for available devices to connect. The Application scans the area for Bluetooth devices within a range. Look for "RNBD" devices under the scanned list.

    <br />

    ![](media/GUID-267AD085-1463-4495-8A62-0EBE87B8C667-low.png)

    <br />

4.  For Transparent Serial only: Open a "Serial Terminal" Program such as Tera Term, Real term, PuTTY, Serial; or similar. Baud Rate will be configured as: 115200

    <br />

    ![](media/GUID-F03D2F6E-4C61-4076-8322-1CD1ACA81EA2-low.png)

    <br />

    ![](media/GUID-136BD52C-2CDC-4522-AE36-B7E75249C656-low.png)

    <br />

5.  Once Connected with RNBD451\_0EC4 click on **Text Mode** at bottom of the settings as shown below to initiate the data transfer.

    <br />

    ![](media/GUID-4A2C616C-FB94-465C-BA58-997E542DBF9C-low.png)

    <br />

    - Check Serial Terminal for the status of the connection.

    <br />

    ![](media/GUID-928146A5-0740-4390-AB9D-31AE1A0A9164-low.png)

    <br />

6.  Enter the text to be transferred from mobile to RNB45x device and click send button

    <br />

    ![](media/GUID-9C7FDD8B-9541-4543-8746-9C1B98D0E5D0-low.png)

    <br />

    - The data will be received at the RNBD45x side and will be displayed in serial terminal of RNBD45x

    <br />

    ![](media/GUID-2B7B8379-978D-4B3E-AE7F-F5FE12868EBF-low.png)

    <br />

7.  Type any data on the serial terminal of the RNBD45x to send to the Microchip Bluetooth Data App, which is received and printed on the receive view of the Microchip Bluetooth App.

    <br />

    ![](media/GUID-3D09C58E-D3A8-456B-A347-32BBC09DA06F-low.png)

    <br />

    ![](media/GUID-34E4CFD6-6857-479E-93B0-4ACE34EDFD59-low.png)

    <br />

# RN487x Example: Running Transparent UART Example Application<a name="rn487x-example:-running-transparent-uart-example-application"></a>

<br />

![](media/GUID-8E74C720-BCFD-47D5-A7CC-A02653A6DC80-low.png)

<br />

<br />

|Transparent Serial:|
|-------------------|
|This example will demonstrate data transmitted from a PC serial terminal is written to a smart phone app and vice versa. The MCU device will act as a bridge, and pass data between RN487x Module to MCU via Serial Terminal. This action will occur when STREAM\_OPEN is processed through the Message Handler. For this example, data typed into the Serial Terminal will appear on the BLE Phone Application, and Data sent from the Application will appear on the Serial Terminal.|

<br />

1.  Download and Install Phone Application for demonstration:
    -   Search **Microchip Bluetooth Data** by **Microchip Technology Inc** from the [App Store](https://apps.apple.com/us/app/microchip-bluetooth-data/id1319166097) or from [Google Play](https://play.google.com/store/apps/details?id=com.microchip.bluetooth.data&hl=en_IN&gl=US).

    <br />

    ![](media/GUID-8A9EE9CE-AA92-4648-8364-09987F2E0526-low.png)

    <br />

2.  Launch the Phone Application

    <br />

    ![](media/GUID-7271A2D0-99A8-41F4-BB4C-269F2F83820C-low.png)

    <br />

    After Installing open the MBD App and Click on **BLE UART** Sub Apps:

    <br />

    ![](media/GUID-D647FF96-CA12-4FA0-A3AA-29C6D6C3DF9D-low.png)

    <br />

3.  On Selecting **BM70** scan for available devices to connect.

    <br />

    ![](media/GUID-6B7B0F61-A3A7-478C-A253-06E561E1313F-low.png)

    <br />

    Click on the below Scan image to scan the Nearby "RN487x-xxxx"

    <br />

    ![](media/GUID-C7AB4C05-260C-4C69-AF6D-298B9E02F302-low.png)

    <br />

    The Application scans the area for Bluetooth devices within a range. Look for<br /> "RN487x-xxxx" devices under the scanned list.

    <br />

    ![](media/GUID-C36CEB36-58F8-4DAD-8800-358F70E56B66-low.png)

    <br />

4.  For Transparent Serial only: Open a "Serial Terminal" Program such as Tera Term, Realterm, PuTTY, Serial; or similar. Baud Rate will be configured as: 115200

    <br />

    ![](media/GUID-B18B65D8-9AA3-478A-A674-DEB871E086CA-low.png)

    <br />

    <br />

    ![](media/GUID-BC559EA4-E40C-4332-9EF3-4BA8F919AFE6-low.png)

    <br />

5.  Once Connected with RN487x-xxxx click on **Transfer data to device** as shown below to initiate the data transfer.

    <br />

    ![](media/GUID-B3297905-2011-452F-8141-887853ECF6AD-low.png)

    <br />

    - Check Serial Terminal for the status of the connection.

    <br />

    ![](media/GUID-DF2150F8-89DC-4876-B351-D59A58E34272-low.png)

    <br />

6.  Enter the text to be transferred from mobile to RN487x-xxxx device and click send button

    <br />

    ![](media/GUID-B8693063-53D6-4080-AD8C-3906E2698F6C-low.png)

    <br />

    - The data will be received at the RN487x-xxxx side and will be displayed in<br /> serial terminal of RNBD45x

    <br />

    ![](media/GUID-E0106617-7CA8-4508-AE5A-278D8E8B737B-low.png)

    <br />

7.  Type any data on the serial terminal of the RN487x-xxxx to send to the Microchip Bluetooth Data App, which is received and printed on the receive view of the Microchip Bluetooth App.

    <br />

    ![](media/GUID-CEC4E31B-D080-4A65-8350-81D62D130FC9-low.png)

    <br />

    ![](media/GUID-E985EFE1-6B23-4A76-86DE-E349AF41D0F1-low.png)

    <br />

# Summary<a name="summary"></a>

**Command, Data Communication with Asynchronized Message Processing:**

This driver contains, at its' core, the inherent code capability of distinguishing between **Message** exchange and **Data** exchange between the connected MCU and Module devices.

The library supplies all required Application Programming Interfaces \(APIs\) required to create functional implementation of operation a BLE connected end-device. Through the MCC configuration the physical connection of the \(3\) required pins can be selected through the GUI. These are the \(2\) UART pins used for communication, and control of the **RST\_N** connected to the RNBD Module.

Additionally this Library allows for extension of Module pin behaviors through the simple RNBD Module object interface; where any device/project specific instantiations exist **rnbd\_interface.c/h**/**rn487x\_interface.c/h**


A brief description of the Interface, and object extension is described below:

iRNBD\_FunctionPtrs\_t is a typedef struct which can be found in **rnbd\_interface.h**/**rn487x\_interface.h** and consist of \(9\) function pointers. In the **rnbd\_interface.c**/**rn487x\_interface.c**, the concrete creation of RNBD as an object is instantiated. Within **rnbd\_interface.c**/**rn487x\_interface.c** are the **private static** implementations of desired behavior. In some cases, such as DELAY or UART, the supporting behavior is supplied through another supporting library module. When applicable ‘inline’ has been used to reduce stack depth overhead.

<br />

![](media/GUID-2B41A010-DEC4-4198-9245-049150500274-low.png)

<br />

![](media/GUID-08351B32-7A45-4F07-91BF-66534BFE5482-low.png)

<br />

The driver library itself should not require any modifications or injections by the user unless to expand upon the supported command implementations **rnbd.c/h**

**Configurable Module Hardware Requirement\(s\):**

A single UART instance used for communication between MCU and Module:

|Library Name: Output\(s\)|Module: Input\(s\)|Description|Module Physical Defaults|
|-------------------------|------------------|-----------|------------------------|
|BT\_MODE|P2\_0|<br /> 1 : Application Mode<br /> 0 : Test Mode/Flash Update/EEPROM Configuration<br />|Active-Low, Internal Pull-High|
|BT\_RST|RST\_N|Module Reset|Active-Low, Internal Pull-High|
|BT\_RX\_IND|P3\_3|Configured as UART RX Indication pin|Active-Low|

<br />
