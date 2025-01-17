<a href="https://www.microchip.com" rel="nofollow"><img src="media/microchip.png" alt="MCHP" width="300"/></a>

# RNBD\_RN487x\_32Bit\_User\_Guide

-   [Introduction](#introduction)
-   [Getting Started with Software Development](#getting-started-with-software-development)
-   [Non Trust Zone Project Setup](#non-trust-zone-project-setup)
-   [Trust Zone Project Setup](#trust-zone-project-setup)
-   [Running RNBD Example Application](#running-rnbd-example-application)
-   [RNBD Example1: Running Basic Data Exchange Example Application](#rnbd-example1:-running-basic-data-exchange-example-application)
-   [RNBD Example2: Running Transparent UART Example Application](#rnbd-example2:-running-transparent-uart-example-application)
-   [Running RN487x Example Application](#running-rn487x-example-application)
-   [RN487x Example1: Running Basic Data Exchange Example Application](#rn487x-example1:-running-basic-data-exchange-example-application)
-   [RN487x Example2: Running Transparent UART Example Application](#rn487x-example2:-running-transparent-uart-example-application)
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
|MPLAB X IDE|v6.05|[MPLAB X IDE Website](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide#tabs)|
|XC32 Compiler|v4.10 or above|[Web](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers)|
|Microchip Code Configurator\(MCC\)|5.2.1 or above|[MPLAB X IDE \> Tools \>Plugins](https://internal.onlinedocs.microchip.com/pr/GUID-99E91F8E-E9F7-4C2C-B98A-E9662A2ABA50-en-US-1/GUID-A55E9342-CE44-4A91-86BB-FEC6706FCD1C.html)|
|Device Family Pack \(DFP\) Non-Trust Zone|SAML21\_DFP \(v3.6.105\)|Device: ATSAML21J18B|
|Device Family Pack \(DFP\) Trust Zone|PIC32CM-LS\_DFP \(v1.1.162\)|Device: PIC32CM5164LS00100|

<br />

**Harmony Components**:

<br />

|**Harmony components to be cloned with MCC Content Manager**|**Version**|
|------------------------------------------------------------|-----------|
|csp|v3.15.0|
|core|v3.10.0|
|dev\_packs|v3.15.0|
|bsp|v3.15.0|
|CMSIS-FreeRTOS|v10.3.1|
|devices|v1.1.0|

<br />

# Non Trust Zone Project Setup<a name="non-trust-zone-project-setup"></a>
<br />

1.  Create MPLAB Harmany Project with below device and DFP version

    <br />

    -   Device: ATSAML21J18B
    -   XC32 Compiler: v4.10
    -   DFP: SAML21\_DFP \(v3.6.105\)
    <br />

    <br />
	**1.1** Create new 32-bit MCC Harmony Project as shown below

    ![](media/GUID-1F5749EC-E7B4-4523-897D-672357706EC6-low.png)

    <br />

    **1.2** Select the **Framework Path** \(Framework path must match SDK setup<br /> document\)and select **Next**

    <br />

    ![](media/GUID-3D19DD6B-F7D5-4C0D-BEA5-77D8003FC859-low.png)

    <br />

    **1.3** Select Project Folder and select Next

    <br />

    ![](media/GUID-F1A8A999-FE9E-4D8F-9DE7-1152FB95BB02-low.png)

    <br />

    **1.4** Select the device "ATSAML21J18B" for standalone project using the SAML21<br /> device family in the "Target Device" and click Finish

    <br />

    ![](media/GUID-DD58810C-576C-4209-91DB-EB30366EBD70-low.png)

    <br />

    **1.5**MPLABx Code Configurator will be launched automatically. Then Select<br /> **"MPLAB Harmony"** and Click Next for the Harmony Framework<br /> Path.

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

    -   Expand the Drop down under Select Example Application option and choose any one as mentioned in the below
        -   Basic Data Exchange
        -   Transparent UART Application
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

        <br />

        ![](media/GUID-E0F435FE-B243-4B32-83CB-733D18E84AFB-low.png)

        <br />

        <br />

        ![](media/GUID-1278FF0D-6D3C-4B0F-AE4D-89F168518DAF-low.png)

        <br />

        **4.2. Transparent UART:**

        -   Transparent UART Application uses **TWO** SERCOM as a Dependency for the Data Transmission

            <br />

            ![](media/GUID-0B984F72-4BD1-4A0E-A500-8F5E47635AAE-low.png)

            <br />

            <br />

            ![](media/GUID-8DFAD094-DC6C-452C-8B76-A8959FA8751A-low.png)

            <br />

            SERCOM0 Pin Setting is same as mentioned under Basic<br /> Data Exchange above.

            <br />

            ![](media/GUID-65B59EB7-F897-4632-B540-900B80FA985B-low.png)

            <br />

            <br />

            ![](media/GUID-B7BC4E37-70AB-474A-BC7C-63F1BF807757-low.png)

            <br />

    <br />

5.  PIN Settings for Example Application:
    -   Basic Data Exchange Pin Settings

        <br />

        ![](media/GUID-7799CCD7-257F-4372-A8B4-38B82D8D2EC6-low.png)

        <br />

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

This is the End of Non-Trust Zone project kindly refer [RNBD](#running-rnbd-example-application) or [RN487x](#running-rn487x-example-application) Running<br /> Example Application

# Trust Zone Project Setup<a name="trust-zone-project-setup"></a>

<br />

1.  Create MPLAB Harmany Project with below device and DFP version
    -   Device: PIC32CM5164LS00100
    -   XC32 Compiler: v4.10
    -   DFP: PIC32CM-LS\_DFP \(v1.1.162\)

        **1.1**Create new 32-bit MCC Harmony Project as<br /> shown below

        <br />

        ![](media/GUID-1F5749EC-E7B4-4523-897D-672357706EC6-low.png)

        <br />

        **1.2** Select the **Framework Path** \(Framework path must<br /> match SDK setup document\)and select **Next**

        <br />

        ![](media/GUID-3D19DD6B-F7D5-4C0D-BEA5-77D8003FC859-low.png)

        <br />

        **1.3** Select Project Folder and select Next

        <br />

        ![](media/GUID-F1A8A999-FE9E-4D8F-9DE7-1152FB95BB02-low.png)

        <br />

        **1.4** Select the device "PIC32CM5164LS00100" for standalone<br /> project using the PIC32CM-LS device family in the "Target Device"<br /> and click Finish

        <br />

        ![](media/GUID-5F1FF3AB-ECC8-4737-A413-94BF029B8BA6-low.png)

        <br />

        **1.5** MPLABx Code Configurator will be launched<br /> automatically. Then Select **"MPLAB Harmony"** and Click Next for<br /> the Harmony Framework Path.

        <br />

        ![](media/GUID-294FFF44-97E6-44FA-B024-CF107A950910-low.png)

        <br />

        **1.6** Select **"Finish"**

        <br />

        ![](media/GUID-12B3E149-2BA4-49D7-8518-4E0AF4053503-low.png)

        <br />

        **1.7** Project Graph window of the Configurator may have<br /> predefined components

        <br />

        ![](media/GUID-B7BABF5E-8835-4450-AE8F-4756671D5621-low.png)

        <br />

        Right click on the project properties and verify the selected<br /> configuration

        <br />

        ![](media/GUID-854E224C-04F1-4BDA-85F6-9B80E67341E8-low.png)

        <br />

2.  After creating the project as shown in the above step go to device resource and verify RNBD was under Wireless component

    <br />

    ![](media/GUID-90230AC0-170B-49BE-8966-59DBCE84E4B8-low.png)

    <br />

    Click on Plus icon under RNBD to add it under the Project Resource

    <br />

    ![](media/GUID-897EAA48-0C5B-45F0-A3BA-E426618531C2-low.png)

    <br />

3.  Project Graph and RNBD/RN487x Module Configuration

    <br />

    ![](media/GUID-E98E66A5-023F-4A59-A415-188A9407B727-low.png)

    <br />

    User can Select **RNBD**or**RN487x** under the Select Module Type<br /> Drop Down either of the one as shown below

    <br />

    ![](media/GUID-2B7B2E95-2F31-4C72-BBFB-2ED03594AC60-low.png)

    <br />

4.  Selecting Example Application

    <br />

    -   Expand the Drop down under Select Example Application option and choose any one as mentioned in the below

        <br />

        -   Basic Data Exchange
        -   Transparent UART Application
        <br />

    <br />

    <br />

    ![](media/GUID-1183333D-3FE6-47A6-9A1C-DB89187FC07F-low.png)

    <br />

    **4.1 Basic Data Exchange:**

    <br />

    -   Basic Data Exchange uses only **ONE** SERCOM for the Data Transmission

        <br />

        ![](media/GUID-F906B088-0615-48F2-8E9B-2BBD390714F4-low.png)

        <br />

        <br />

        ![](media/GUID-237C2D6E-AB20-4D66-9BF5-B4967B189A89-low.png)

        <br />

        <br />

        ![](media/GUID-934D5E9F-070D-4C79-BBD8-E1FAB742B8AA-low.png)

        <br />

        **4.2 Transparent UART**

        -   Transparent UART Application uses **TWO** SERCOM as a Dependency for the Data Transmission

            <br />

            ![](media/GUID-C123B1D2-B140-478F-986F-05CBE5F5F778-low.png)

            <br />

            <br />

            ![](media/GUID-237C2D6E-AB20-4D66-9BF5-B4967B189A89-low.png)

            <br />

            ![](media/GUID-604E7160-985D-4B90-B0ED-2AEB3274EFC4-low.png)

            SERCOM2 Pin Setting is same as mentioned under Basic<br /> Data Exchange above.

            <br />

            ![](media/GUID-B7BC4E37-70AB-474A-BC7C-63F1BF807757-low.png)

            <br />

    <br />

5.  PIN Settings for Example Application:

    <br />

    -   Basic Data Exchange Pin Settings

        <br />

        ![](media/GUID-C9051DF7-2E47-4890-953A-FF5408FA7A47-low.png)

        <br />

    -   Transparent UART Pin Settings

        <br />

        ![](media/GUID-13237D2B-D9C8-4BCF-9495-8EB4AF31F439-low.png)

        <br />

    <br />

6.  Enabling RNBD/RN487x Secure and Non Secure for Trust Zone Devices

    Click the below check box to Enable and<br /> Disable RNBD secure

    <br />

    ![](media/GUID-55BAA7ED-4492-464B-9C33-38369A61A792-low.png)

    <br />

7.  Table for Secure and Non-Secure Configuration

    <br />

    |S.no|RNBD Secure \(Check Box in the UI\)|Dependency\(SERCOM\)|Pins|
    |----|-----------------------------------|--------------------|----|
    |1|Non Secure|Non Secure|Non Secure|
    |2|Non Secure|Secure|Non Secure|
    |3|Secure|Secure|Secure|

    <br />

    <br />

    **Note:** If RNBD Secure \(Check Box in the UI\) is marked to secure then BT\_RST pin settings should be Secured and if RNBD Secure \(Check Box in the UI\) is marked to Non-secure then BT\_RST pin settings should be Non-Secure

    <br />

    <br />

    -   **Case1:** \(RNBD: Non-Secure, Dependency: Non-Secure, BT\_RST Pin: Non-Secure\)
        -   **RNBD Secure \(Check Box in the UI\) –\> Unchecked \(Non-Secure\)** as shown below

            <br />

            ![](media/GUID-55BAA7ED-4492-464B-9C33-38369A61A792-low.png)

            <br />

        -   **Dependency –\> Non-Secure**

            <br />

            -   Goto –\> Project Graph –\> expand the plugins drop down –\> and select Arm TRUSTZONE for Armv8-M

                <br />

                ![](media/GUID-66D4E1DA-5032-4A14-8035-EE95C5F3C769-low.png)

                <br />

            -   Select **Peripheral Configuration** as shown<br /> below

                <br />

                ![](media/GUID-F21C855A-415F-4609-A5E0-843B0D21BF86-low.png)

                <br />

            -   **NOTE:** Set SERCOM2 from secure to Non-Secure as shown below \(Applicable for **Transparent UART** if **TWO** **SERCOM** was used\)

                <br />

                ![](media/GUID-1B755990-97B9-41F3-86B2-BBF85A0F050F-low.png)

                <br />

            <br />

        -   **Pin Settings –\> Non-Secure**

            <br />

            -   Goto –\> Project Graph –\> expand the plugins drop down –\> and select Pin Configuration as shown below

                <br />

                ![](media/GUID-F462E3AF-C296-496D-9B1A-A453C133EB86-low.png)

                <br />

            -   Set **BT\_RST** pin to **Non-Secure** under PIN Security Mode as shown below

                <br />

                ![](media/GUID-0B32338D-9798-4785-9004-93F9BDC7A0EE-low.png)

                <br />

            <br />

        -   **Project Structure:**

            Click Generate Button under Project<br /> Resource for Code Generation to the selected<br /> configuration

            <br />

            ![](media/GUID-C132E098-4CB8-4CE8-8E88-4B6DEBE1532F-low.png)

            <br />

            <br />

            ![](media/GUID-ACC3BAE3-899F-424B-B448-FF8EFA4E55D6-low.png)

            <br />

        -   **Adding example application to main.c**

            <br />

            -   Once after Generation is complete include the headers for **RNBD** or **RN487x** as shown below
                -   if **Select Module Type** is selected**n** is for **RNBD**: \#include "examples/rnbd\_example.h"
                -   if **Select Module Type** is selected for **RN487x**: \#include "examples/rn487x\_example.h"

                    <br />

                    ![](media/GUID-31D005A3-ADEE-47E8-8312-1BBCAF0AEE53-low.png)

                    <br />

                    Call the function<br /> **RNBD\_Example\_Initialized\(\); or RN487x\_Example\_Initialized\(\);** in **main\(\)**<br /> after **SYS\_Initialize \( NULL \);**

            <br />

        -   **Build the Generated Project:**

            <br />

            ![](media/GUID-69F2DB5D-6EEE-4922-935E-A0A0FB0E19F8-low.png)

            <br />

        -   **Program to the Development Board**

            <br />

            ![](media/GUID-86E3F2BD-3777-4E96-95C3-F1C8DED00136-low.png)

            <br />

            This is the End of **Case1** project kindly refer<br /> [RNBD](#running-rnbd-example-application) or [RN487x](#running-rn487x-example-application) Running Example<br /> Application

    -   **Case 2:** \(RNBD: **Non-Secur**e, Dependency**: Secure**, BT\_RST Pin: **Non-Secure**\)

        <br />

        -   **RNBD Secure \(Check Box in the UI\) –\>****Unchecked \(Non-Secure\)** as shown below

            <br />

            ![](media/GUID-55BAA7ED-4492-464B-9C33-38369A61A792-low.png)

            <br />

        -   **Dependency –\> Secure**

            <br />

            -   Goto –\> Project Graph –\> expand the plugins drop down –\> and select Arm TRUSTZONE for Armv8-M

                ![](media/GUID-66D4E1DA-5032-4A14-8035-EE95C5F3C769-low.png)

            -   Select **Peripheral Configuration** as shown below

                <br />

                ![](media/GUID-F21C855A-415F-4609-A5E0-843B0D21BF86-low.png)

                <br />

            -   **NOTE**: Set SERCOM2 from secure to Non-Secure as shown below \(Applicable for **Transparent UART** if **TWO** **SERCOM** was used\)
            <br />

        -   **Pin Settings –\> Non-Secure**

            <br />

            -   Goto –\> Project Graph –\> expand the plugins drop down –\> and select Pin Configuration as shown below

                <br />

                ![](media/GUID-F462E3AF-C296-496D-9B1A-A453C133EB86-low.png)

                <br />

            -   Set **BT\_RST** pin to **Non-Secure** under PIN Security Mode as shown below

                <br />

                ![](media/GUID-0B32338D-9798-4785-9004-93F9BDC7A0EE-low.png)

                <br />

            <br />

        -   **Project Folder Structure:**

            Click Generate<br /> Button under Project Resource for Code Generation to<br /> the selected configuration

            <br />

            ![](media/GUID-C132E098-4CB8-4CE8-8E88-4B6DEBE1532F-low.png)

            <br />

            <br />

            ![](media/GUID-ACC3BAE3-899F-424B-B448-FF8EFA4E55D6-low.png)

            <br />

        -   **Adding example application to main.c**

            <br />

            -   Once after Generation is complete include the headers for RNBD or RN487x as shown below
                -   if **Select Module Type** is selected for **RNBD**: \#include "examples/rnbd\_example.h"
                -   if **Select Module Type** is selected for**RN487x**: \#include "examples/rn487x\_example.h"

                    <br />

                    ![](media/GUID-31D005A3-ADEE-47E8-8312-1BBCAF0AEE53-low.png)

                    <br />

                    Call the function<br /> **RNBD\_Example\_Initialized\(\); or RN487x\_Example\_Initialized\(\);** in **main\(\)**<br /> after **SYS\_Initialize \( NULL \);**

            <br />

        -   **Build the Generated Project:**

            <br />

            ![](media/GUID-69F2DB5D-6EEE-4922-935E-A0A0FB0E19F8-low.png)

            <br />

        -   **Program to the Development Board**

            <br />

            ![](media/GUID-86E3F2BD-3777-4E96-95C3-F1C8DED00136-low.png)

            <br />

            This is the End of **Case2** project kindly<br /> refer [RNBD](#running-rnbd-example-application) or [RN487x](#running-rn487x-example-application) Running Example<br /> Application

        <br />

    -   **Case 3**: \(RNBD: **Secure**, Dependency: **Secure**, BT\_RST Pin: **Secure**\)

        <br />

        1.  **Scenario 1:**

            -   **RNBD Secure \(Check Box in the UI\) –\> Enable Check \(Secure\)**

                <br />

                **Note:** **Generate RNBD Non Secure Entry** check box Disabled \(Unchecked\) as shown below

                <br />

                <br />

                ![](media/GUID-9EE3A6D2-4F83-4524-8538-C79820877CB9-low.png)

                <br />

            -   **Dependency –\> Secure**

                <br />

                -   Goto –\> Project Graph –\> expand the<br /> plugins drop down –\> and select Arm TRUSTZONE<br /> for Armv8-M

                    ![](media/GUID-66D4E1DA-5032-4A14-8035-EE95C5F3C769-low.png)

                -   Select **Peripheral Configuration** as shown<br /> below

                    <br />

                    ![](media/GUID-F21C855A-415F-4609-A5E0-843B0D21BF86-low.png)

                    <br />

                    **NOTE**: Set SERCOM2 from secure to<br /> Non-Secure as shown below \(Applicable for<br /> **Transparent UART** if **TWO**<br /> **SERCOM** was used\)

                <br />

            -   **Pin Settings –\> Secure**

                <br />

                -   Goto –\> Project Graph –\> expand the plugins drop down –\> and select Pin Configuration as shown below

                    <br />

                    ![](media/GUID-F462E3AF-C296-496D-9B1A-A453C133EB86-low.png)

                    <br />

                -   Set **BT\_RST** pin to **Non-Secure** under PIN Security Mode as shown below

                    <br />

                    ![](media/GUID-32A08681-AD83-445E-8B52-970DA3BB4050-low.png)

                    <br />

                <br />

            -   **Project Folder Structure:**

                Click Generate<br /> Button under Project Resource for Code Generation<br /> to the selected configuration

                <br />

                ![](media/GUID-C132E098-4CB8-4CE8-8E88-4B6DEBE1532F-low.png)

                <br />

                <br />

                ![](media/GUID-7B3F7448-3312-4B7E-9A50-D0DB07FA33C6-low.png)

                <br />

            -   **Adding example application to main.c**

                <br />

                -   Once after Generation is complete include the headers for RNBD or RN487x as shown below
                    -   if **Select Module Type** is selected for **RNBD**: \#include "examples/rnbd\_example.h"
                    -   if **Select Module Type** is selected for **RN487x**: \#include "examples/rn487x\_example.h"

                        <br />

                        ![](media/GUID-31D005A3-ADEE-47E8-8312-1BBCAF0AEE53-low.png)

                        <br />

                        Call the function<br /> **RNBD\_Example\_Initialized\(\); or RN487x\_Example\_Initialized\(\);** in **main\(\)**<br /> after **SYS\_Initialize \( NULL \);**

                <br />

            -   **Build the Generated Project:**

                <br />

                ![](media/GUID-69F2DB5D-6EEE-4922-935E-A0A0FB0E19F8-low.png)

                <br />

            -   **Program to the Development Board**

                <br />

                ![](media/GUID-86E3F2BD-3777-4E96-95C3-F1C8DED00136-low.png)

                <br />

            This is the End of **Case3 –\> Scenario 1**<br /> project kindly refer [RNBD](#running-rnbd-example-application) or [RN487x](#running-rn487x-example-application) Running Example<br /> Application

        2.  **Scenario 2**:

            <br />

            -   **RNBD Secure \(Check Box in the UI\) –\> Enable Check \(Secure\)**

                <br />

                **Note:** **Generate RNBD Non Secure Entry** check box Enabled \(checked\) as shown below

                <br />

                <br />

                ![](media/GUID-07EBA86D-DDC1-413A-8905-A691BE598C97-low.png)

                <br />

            -   **Dependency –\> Secure**

                <br />

                -   Goto –\> Project Graph –\> expand the<br /> plugins drop down –\> and select Arm TRUSTZONE<br /> for Armv8-M

                    ![](media/GUID-66D4E1DA-5032-4A14-8035-EE95C5F3C769-low.png)

                -   Select **Peripheral Configuration** as shown<br /> below

                    <br />

                    ![](media/GUID-F21C855A-415F-4609-A5E0-843B0D21BF86-low.png)

                    <br />

                    **NOTE**: Set SERCOM2 from secure to<br /> Non-Secure as shown below \(Applicable for<br /> **Transparent UART** if **TWO**<br /> **SERCOM** was used\)

                <br />

            -   **Pin Settings –\> Secure**

                <br />

                -   Goto –\> Project Graph –\> expand the plugins drop down –\> and select Pin Configuration as shown below

                    <br />

                    ![](media/GUID-F462E3AF-C296-496D-9B1A-A453C133EB86-low.png)

                    <br />

                -   Set **BT\_RST** pin to **Non-Secure** under PIN Security Mode as shown below

                    <br />

                    ![](media/GUID-32A08681-AD83-445E-8B52-970DA3BB4050-low.png)

                    <br />

                <br />

            -   **Project Folder Structure:**

                Click Generate<br /> Button under Project Resource for Code Generation<br /> to the selected configuration

                <br />

                ![](media/GUID-C132E098-4CB8-4CE8-8E88-4B6DEBE1532F-low.png)

                <br />

                Verify the RNBD/RN487x Non-Secure Entry<br /> code Generation as shown below

                <br />

                ![](media/GUID-56BE2E74-91E0-474B-B011-28CBD4BBD0BE-low.png)

                <br />

            -   **Adding example application to main.c**

                <br />

                -   Once after Generation is complete include the headers for RNBD or RN487x as shown below
                    -   if **Select Module Type** is selected for **RNBD**: \#include "examples/rnbd\_example.h"
                    -   if **Select Module Type** is selected for **RN487x**: \#include "examples/rn487x\_example.h"

                        <br />

                        ![](media/GUID-31D005A3-ADEE-47E8-8312-1BBCAF0AEE53-low.png)

                        <br />

                        Call the function<br /> **RNBD\_Example\_Initialized\(\); or RN487x\_Example\_Initialized\(\);** in **main\(\)**<br /> after **SYS\_Initialize \( NULL \);**

                <br />

            -   **Build the Generated Project:**

                <br />

                ![](media/GUID-69F2DB5D-6EEE-4922-935E-A0A0FB0E19F8-low.png)

                <br />

            -   **Program to the Development Board**

                <br />

                ![](media/GUID-86E3F2BD-3777-4E96-95C3-F1C8DED00136-low.png)

                <br />

                This is the End of **Case3 –\> Scenario 2** project kindly refer [RNBD](#running-rnbd-example-application) or [RN487x](#running-rn487x-example-application) Running Example<br /> Application

            <br />

        <br />

    <br />


<br />

# Running RNBD Example Application<a name="running-rnbd-example-application"></a>

This Topic explains us briefly regarding Running RNBD451 for Basic Data Exchange and Transparent<br /> UART Application.

-   **[RNBD Example1: Running Basic Data Exchange Example Application](#rnbd-example1:-running-basic-data-exchange-example-application)**  

-   **[RNBD Example2: Running Transparent UART Example Application](#rnbd-example2:-running-transparent-uart-example-application)**

# RNBD Example1: Running Basic Data Exchange Example Application<a name="rnbd-example1:-running-basic-data-exchange-example-application"></a>

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

This is the END of the Basic Data Exchange Example

# RNBD Example2: Running Transparent UART Example Application<a name="rnbd-example2:-running-transparent-uart-example-application"></a>

<br />

![](media/GUID-7C8A6EC0-77B8-4206-B2F5-FA8FA50C2A35-low.png)

<br />

<br />

|Transparent Serial:|
|-------------------|
|<br /> This example will demostrat data transmitted from a PC serial<br /> terminal is written to a smart phone app and vice versa. The MCU<br /> device will act as a bridge, and pass data between RNBD Module â†?<br /> MCU â†’ Serial Terminal.<br /> This action will occur when STREAM\_OPEN is processed<br /> through the Message Handler. For this example, data typed into<br /> the Serial Terminal will appear on the BLE Phone Application,<br /> and Data sent from the Application will appear on the Serial<br /> Terminal.<br />|

<br />

1.  Download and Install Phone Application for demonstration:
    -   **Microchip Bluetooth Data** by **Microchip** from the [App Store](https://apps.apple.com/us/app/microchip-bluetooth-data/id1319166097) or from [Google Play](https://play.google.com/store/apps/details?id=com.microchip.bluetooth.data&hl=en_IN&gl=US).
2.  Launch the Phone Application

    ![](media/GUID-10887333-0442-467E-B79B-6A17DB835DB2-low.png)

    ![](media/GUID-7271A2D0-99A8-41F4-BB4C-269F2F83820C-low.png)

    <br />

    ![](media/GUID-8A9EE9CE-AA92-4648-8364-09987F2E0526-low.png)

    <br />

    After Installing open the MBD App and Click on **BLE UART** Sub Apps:

    <br />

    ![](media/GUID-D647FF96-CA12-4FA0-A3AA-29C6D6C3DF9D-low.png)

    <br />

3.  On Selecting **PIC32CXBZ** scan for available devices to connect. The Application scans the area for Bluetooth devices within a range. Look for "RNBD" devices under the scanned list.

    <br />

    ![](media/GUID-267AD085-1463-4495-8A62-0EBE87B8C667-low.png)

    <br />

4.  For Transparent Serial only: Open a "Serial Terminal" Program such as Tera Term, Realterm, PuTTY, Serial; or similar. Baud Rate will be configured as: 115200

    <br />

    ![](media/GUID-F03D2F6E-4C61-4076-8322-1CD1ACA81EA2-low.png)

    <br />

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

    - The data will be received at the RNBD45x side and will be displayed in<br /> serial terminal of RNBD45x

    <br />

    ![](media/GUID-2B7B8379-978D-4B3E-AE7F-F5FE12868EBF-low.png)

    <br />

7.  Type any data on the serial terminal of the RNBD45x to send to the Microchip Bluetooth Data App, which is received and printed on the receive view of the Microchip Bluetooth App.

    <br />

    ![](media/GUID-3D09C58E-D3A8-456B-A347-32BBC09DA06F-low.png)

    <br />

    <br />

    ![](media/GUID-34E4CFD6-6857-479E-93B0-4ACE34EDFD59-low.png)

    <br />


This is the END of the Transparent UART Example

# Running RN487x Example Application<a name="running-rn487x-example-application"></a>

This Topic explains us briefly regarding Running RN487x for Basic Data Exchange and<br /> Transparent UART Application.

-   **[RN487x Example1: Running Basic Data Exchange Example Application](#rn487x-example1:-running-basic-data-exchange-example-application)**  

-   **[RN487x Example2: Running Transparent UART Example Application](#rn487x-example2:-running-transparent-uart-example-application)**

# RN487x Example1: Running Basic Data Exchange Example Application<a name="rn487x-example1:-running-basic-data-exchange-example-application"></a>

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

This is the END of the Basic Data Exchange Example

# RN487x Example2: Running Transparent UART Example Application<a name="rn487x-example2:-running-transparent-uart-example-application"></a>

<br />

![](media/GUID-8E74C720-BCFD-47D5-A7CC-A02653A6DC80-low.png)

<br />

<br />

|Transparent Serial:|
|-------------------|
|<br /> This example will demostrat data transmitted from a PC serial<br /> terminal is written to a smart phone app and vice versa. The MCU<br /> device will act as a bridge, and pass data between RNBD Module â†?<br /> MCU â†’ Serial Terminal.<br /> This action will occur when STREAM\_OPEN is processed<br /> through the Message Handler. For this example, data typed into<br /> the Serial Terminal will appear on the BLE Phone Application,<br /> and Data sent from the Application will appear on the Serial<br /> Terminal.<br />|

<br />

1.  Download and Install Phone Application for demonstration:
    -   **Microchip Bluetooth Data** by **Microchip** from the [App Store](https://apps.apple.com/us/app/microchip-bluetooth-data/id1319166097) or from [Google Play](https://play.google.com/store/apps/details?id=com.microchip.bluetooth.data&hl=en_IN&gl=US).
2.  Launch the Phone Application

    ![](media/GUID-10887333-0442-467E-B79B-6A17DB835DB2-low.png)

    ![](media/GUID-7271A2D0-99A8-41F4-BB4C-269F2F83820C-low.png)

    <br />

    ![](media/GUID-8A9EE9CE-AA92-4648-8364-09987F2E0526-low.png)

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

    <br />

    ![](media/GUID-E985EFE1-6B23-4A76-86DE-E349AF41D0F1-low.png)

    <br />
This is the END of the Transparent UART Example

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
