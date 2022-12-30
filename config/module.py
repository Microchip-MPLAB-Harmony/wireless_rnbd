# coding: utf-8
##############################################################################
# Copyright (C) 2019-2020 Microchip Technology Inc. and its subsidiaries.
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

def loadModule():
    print('Load Module: Harmony Wireless Service for SAMx Family')
    
    SAM_Device_family =  {'ATSAMD21J18A',
                          'ATSAME54',
                          'ATSAMR34J18B',
                          'ATSAML21J18B',
                          'PIC32CM5164LS00100',
						  'ATSAMD21E15A',
						  'ATSAMD21E15B',
						  'ATSAMD21E15BU',
						  'ATSAMD21E15CU',
						  'ATSAMD21E15L',
						  'ATSAMD21E16A',
						  'ATSAMD21E16B',
						  'ATSAMD21E16BU',
						  'ATSAMD21E16CU',
						  'ATSAMD21E16L',
						  'ATSAMD21E17A',
						  'ATSAMD21E17D',
						  'ATSAMD21E17DU',
						  'ATSAMD21E17L',
						  'ATSAMD21E18A',
						  'ATSAMD21G15A',
						  'ATSAMD21G15B',
						  'ATSAMD21G16A',
						  'ATSAMD21G16B',
						  'ATSAMD21G16L',
						  'ATSAMD21G17A',
						  'ATSAMD21G17AU',
						  'ATSAMD21G17D',
						  'ATSAMD21G17L',
						  'ATSAMD21G18A',
						  'ATSAMD21G18AU',
						  'ATSAMD21J15A',
						  'ATSAMD21J15B',
						  'ATSAMD21J16A',
						  'ATSAMD21J16B',
						  'ATSAMD21J17A',
						  'ATSAMD21J17D',
						  'ATSAMD21J17D',
						  'ATSAML21E15B',
						  'ATSAML21E16B',
						  'ATSAML21E17B',
						  'ATSAML21E18B',
						  'ATSAML21G16B',
						  'ATSAML21G17B',
						  'ATSAML21G18B',
						  'ATSAML21J16B',
						  'ATSAML21J17B',
						  'ATSAML21J18B',
						  'ATSAML21J18BU'
                          }
    
    processor = Variables.get('__PROCESSOR')
    print('processor={}'.format(processor))
    
    if(processor in SAM_Device_family):
        execfile(Module.getPath() + '/config/module_rn_host_library.py')
        #execfile(Module.getPath() + '/config/module_rn_TRP_UART_example.py')


