![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Microchip MPLAB® Harmony 3 Release Notes.

## RNBD/RN487x v1.0.0 Release
### NEW FEATURES SUPPORTED
 - Supports both RNBD and RN487x BLE Library
 - This Library uses (1) UART, (1) GPIO, and DELAY support at minimal
 - The library module uses a Graphic User Interface (GUI) presented by MCC within MPLABX which allows for selection of desired configuration, and custom configurations of the protocol

### BUG FIXES

### KNOWN ISSUES

### DEVELOPMENT TOOLS 
* [MPLAB® X IDE v6.05](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
* [MPLAB® XC32 C/C++ Compiler v4.20](https://www.microchip.com/mplab/compilers)
* MPLAB® XIDE plug-ins: 
    * MPLAB® Code Configurator (MCC)
      * MCC Plugin v5.2.2

## RNBD/RN487x v2.0.0 Release
### NEW FEATURES SUPPORTED
 - Added the Wireless Capability Support for RNBD to support HOST MCU OTA

### BUG FIXES
 - Added the New function which is used for sending the commands and getting back response from RNBD
 - All other Api's has been updated with the newly added send command receive response function
 - Fixed the BT_RST Pin related issue
 - Added the RNBD Set Capability Support for HOST OTA DFU
 - Added the features for HOST OTA DFU related functionalities

### KNOWN ISSUES

### DEVELOPMENT TOOLS 
* [MPLAB® X IDE v6.15](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
* [MPLAB® XC32 C/C++ Compiler v4.21](https://www.microchip.com/mplab/compilers)
* MPLAB® XIDE plug-ins: 
    * MPLAB® Code Configurator (MCC)
      * MCC Plugin v5.3.7
