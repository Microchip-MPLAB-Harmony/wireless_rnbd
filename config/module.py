# coding: utf-8
##############################################################################
# Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
#
# Subject to your compliance with these terms, you may use Microchip software
# and any derivatives exclusively with Microchip products. It is your
# responsibility to comply with third party license terms applicable to your
# use of third party software (including open source software) that may
# accompany Microchip software.
#
# THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
# EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
# WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
# PARTICULAR PURPOSE.
#
# IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
# INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
# WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
# BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
# FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
# ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
# THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
##############################################################################
supportedDevicefamily = ["PIC32MZ","SAMD","SAML","PIC32CM","PIC32CMMC","PIC32MK","PIC32MX","PIC32MM1324","PIC32MZDA","PIC32MZEF","PIC32MZW","SAME","SAMC","SAM9","PIC32CX","PIC32CK","PIC32CXMT", "PIC32C"]

def loadModule():
    print('Load Module: Harmony Wireless Service for SAMx Family')
    
    deviceNode = ATDF.getNode("/avr-tools-device-file/devices")
    deviceChild = deviceNode.getChildren()
    deviceName = deviceChild[0].getAttribute("family")
    for x in supportedDevicefamily:
        if (deviceName in supportedDevicefamily):
            execfile(Module.getPath() + '/config/module_rn_host_library.py')


