![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

### Development kit and demo application support

Following table provides number of peripheral library examples available for different development kits.

| Development Kits  | MPLAB X applications |
|:-----------------:|:-------------------:|
| [PIC32CM LS00 Curiosity Pro Evaluation Kit](https://www.microchip.com/en-us/development-tool/ev12u44a)  | 1 |

# Microchip MPLAB® Harmony 3 Release Notes.

## RNBD/RN487x v2.0.3 Release
### NEW FEATURES SUPPORTED
 - Added PIC32CX device family support
 
### DEVELOPMENT TOOLS 
* [MPLAB® X IDE v6.20](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
* [MPLAB® XC32 C/C++ Compiler v4.45](https://www.microchip.com/mplab/compilers)
* MPLAB® XIDE plug-ins: 
    * MPLAB® Code Configurator (MCC)
      * MCC Plugin v5.7.1

## RNBD/RN487x v2.0.2 Release
### BUG FIXES
 - Updated the MPLAB-X IDE Discovery portal release and updated the existing project with latest environment tools.

## RNBD/RN487x v2.0.1 Release
### BUG FIXES
 - Fixed the dependency version in package.yml, corrected the wireless_rnbd release version.
 - Added support for SAM9x75

## RNBD/RN487x v2.0.0 Release
### NEW FEATURES SUPPORTED
 - Added the Wireless Capability Support for RNBD to support HOST MCU OTA
 - Added the features for HOST OTA DFU related functionalities
 - RNBD Folder Structure change

### BUG FIXES
 - Added the New function which is used for sending the commands and getting back response from RNBD
 - All other Api's has been updated with the newly added send command receive response function
 - Fixed the BT_RST Pin related issue

### KNOWN ISSUES

### DEVELOPMENT TOOLS 
* [MPLAB® X IDE v6.15](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
* [MPLAB® XC32 C/C++ Compiler v4.21](https://www.microchip.com/mplab/compilers)
* MPLAB® XIDE plug-ins: 
    * MPLAB® Code Configurator (MCC)
      * MCC Plugin v5.3.7
	  

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
